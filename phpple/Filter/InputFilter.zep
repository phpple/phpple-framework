namespace Phpple\Filter;

use Phpple\Application;
use Phpple\Log\LoggerInterface;
use Phpple\Util\Conf;
use Phpple\Http\Exception as HttpException;
use Phpple\Http\OutputFormat;

class InputFilter implements FilterInterface
{
    private logger { set, get };

    /**
     * Request magic variables
     *
     * @var array
     */
    public static reqVars = [
        "_if",
        "_ie",
        "_d",
        "_of",
        "_oe",
        "route",
        "_e",
        "_try",
        "_ep",
        "_pretty"
    ];

    /**
     * @inheritDoc
     */
    public function execute(<Application> app) -> boolean
    {
        this->parseCommon(app);
        this->parseInternalVar(app);
        this->parseParams(app);

        var requestFile = Conf::get("phpple.log.request");
        if requestFile {
            this->logRequest(app, requestFile);
        }

        return true;
    }

    /**
     * Parse common
     *
     * @param Application app
     *
     * @throws Exception
     */
    private function parseCommon(<Application> app)
    {
        var request = app->getRequest();
        request->setNow(_SERVER["REQUEST_TIME"]);

        // Get request schema
        // Check https setting, which is required to be supplied by the web server
        var schema;
        if isset _SERVER["HTTP_X_FORWARDED_PROTO"] {
            let schema = _SERVER["HTTP_X_FORWARDED_PROTO"];
        } elseif isset _SERVER["HTTP_X_HTTPS"] && (_SERVER["HTTP_X_HTTPS"] == "1" || _SERVER["HTTP_X_HTTPS"] == "on") {
            let schema = "https";
        } elseif isset _SERVER["HTTPS"] && (_SERVER["HTTPS"] == "1" || _SERVER["HTTPS"] == "on") {
            let schema = "https";
        }
        request->setSchema(schema);

        // 获取host
        var host;
        if isset _SERVER["HTTP_X_FORWARDED_HOST"] {
            let host = _SERVER["HTTP_X_FORWARDED_HOST"];

            if isset _SERVER["HTTP_X_FORWARDED_PORT"] {
                if schema == "https" && _SERVER["HTTP_X_FORWARDED_PORT"] != 443 {
                    let host = host . ":" . _SERVER["HTTP_X_FORWARDED_PORT"];
                } elseif schema == "http" && _SERVER["HTTP_X_FORWARDED_PORT"] != 80 {
                    let host = host . ":" . _SERVER["HTTP_X_FORWARDED_PORT"];
                }
            }
        } elseif isset _SERVER["HTTP_HOST"] {
            let host = _SERVER["HTTP_HOST"];
        } else {
            let host = Conf::get("phpple.host", "");
        }
        request->setHost(host);
        var rawUri = _SERVER["REQUEST_URI"];
        request->setRawUri(rawUri);

        request->setCookies(_COOKIE);
        request->setMethod(_SERVER["REQUEST_METHOD"]);

        // userip
        if isset _SERVER["HTTP_X_FORWARDED_FOR"] {
            var userip = _SERVER["HTTP_X_FORWARDED_FOR"];
            var userips = explode(",", userip);
            request->setUserIp(strtolower(userips[0]));
        } elseif isset _SERVER["HTTP_X_REAL_IP"] {
            request->setUserIp(_SERVER["HTTP_X_REAL_IP"]);
        } elseif isset _SERVER["REMOTE_ADDR"] {
            request->setUserIp(_SERVER["REMOTE_ADDR"]);
        }
        // clientip
        request->setClientIp(_SERVER["REMOTE_ADDR"]);

        string url;
        if isset _GET["route"] {
            request->setUrl(_GET["route"]);
            unset _GET["route"];
        } elseif isset _SERVER["REQUEST_URI"] {
            var pos = strpos(rawUri, "?");
            if pos !== false {
                let url = substr(rawUri, 0, pos);
            } else {
                let url = rawUri;
            }
        } else {
            throw new HttpException(HttpException::EXCEPTION_NOT_FOUND);
        }
        let url = "/" . ltrim(url, "/");

        var baseUrl = app->getBaseUrl();
        if baseUrl && strncmp(url, baseUrl, strlen(baseUrl)) === 0 {
            let url = substr(url, strlen(baseUrl) - 1);
            request->setPrefix(baseUrl);
        }
        request->setUrl(url);

        var query = http_build_query(_GET);
        request->setUri(url . (query ? "?" . query : ""));

        request->setServerEnvs(_SERVER);

        if isset _SERVER["HTTP_X_REQUESTED_WITH"] && _SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest" {
            request->setIsAjax(true);
        }
    }

    /**
     * Parse internal variables
     *
     * @param Application app
     */
    private function parseInternalVar(<Application> app)
    {
        var request = app->getRequest();
        var arr = array_merge(_REQUEST, _GET, _POST);

        if isset arr["_pretty"] {
            request->setPretty(true);
        }
        if isset arr["_if"] {
            request->setInputFormat(arr["_if"]);
        }

        if isset arr["_of"] {
            request->setOutputFormat(arr["_of"]);
        } elseif request->getOutputFormat() == OutputFormat::FORMAT_DEFAULT {
            var method = request->getMethod();
            if in_array(method,[ "POST", "PUT", "DELETE"]) {
                // Ruturn with the json format while not a GET request
                request->setOutputFormat(OutputFormat::FORMAT_JSON);
            } else {
                request->setOutputFormat(OutputFormat::FORMAT_DEFAULT);
            }
        }
    }

    /**
     * Parse params
     *
     * @param app
     */
    private function parseParams(<Application> app)
    {
        var request = app->getRequest();
        var arr = array_merge(_GET, _POST);
        if count(arr) != count(_GET) + count(_POST) {
            // Some variables are overrited
            var keys = array_intersect(array_keys(_GET), array_keys(_POST));
            this->logger->warn("_GET & _POST have same variables overided:%s", implode(",", keys));
        }
        var key;
        for key in self::reqVars {
            // remove all system params
            unset(arr[key]);
        }

        if OutputFormat::FORMAT_JSON === request->getInputFormat() {
            var puts = file_get_contents("php://input");
            if puts {
                var json = json_decode(puts, true);
                if is_array(json) {
                    let arr = arr ? array_merge(arr, json) : json;
                }
            }
        }
        request->setInputs(arr);
    }

    /**
     * Record request data
     *
     * @param Application app
     * @param  string requestFile
     */
    private function logRequest(<Application> app, string requestFile)
    {
        var request = app->getRequest();
        var headers = [];
        var key, value;
        for key, value in request->getServerEnvs() {
            if strncmp("HTTP_", key, 5) === 0 {
                let headers[key] = value;
            }
        }
        var file;
        let file = app->getDir("log") . requestFile;
        var data = request->getAttributes();
        var keyarr = Conf::get("phpple.log.requestFilter", []);
        for key in keyarr {
            if isset data[key] {
                let data[key] = "[removed]";
            }
        }
        var out = [
            "info": app->getAppId() . ":" . request->getUrl() . ":" . date("Y-m-d H:i:s", request->getNow()),
            "cookie": request->getCookies(),
            "header": headers,
            "data": data
        ];
        file_put_contents(file, print_r(out, true), FILE_APPEND);
    }
}
