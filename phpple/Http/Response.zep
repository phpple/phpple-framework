namespace Phpple\Http;

use Phpple\ResponseInterface;
use Phpple\Log\LoggerInterface;
use Phpple\Application;
use Phpple\Util\Conf;
use Phpple\Util\Xml;

class Response implements ResponseInterface
{
    const STATUS_OK = "ok";
    const STATUS_FATAL = "fatal";
    const STATUS_INPUT = "u_input";

    private app;
    protected logger { set };
    
    /**
     * Output variables
     *
     * @var array
     */
    protected outputs = [];

    protected headers = [];
    
    protected rawData = "";

    /**
     * @var Exception
     */
    private exception;
    private error;
    private needSetContentType = true;
    private callback;
    private results = [];
    private cookies = [];

    /**
     * background task.
     * @var array
     */
    private tasks = [];

    /**
     * Response constructor.
     *
     * @param Application app
     */
    public function __construct(<Application> app = null)
    {
        let this->app = app;
    }

    /**
     * Reset
     */
    public function reset()
    {
        let this->headers = [];
        let this->cookies = [];
        let this->exception = null;
        let this->error = null;
        let this->needSetContentType = true;
        let this->rawData = null;
        let this->callback = null;
        let this->outputs = [];
        let this->results = [];
    }

    /**
     * Set exception
     *
     * @param ex Exception
     *
     * @return Response
     */
    public function setException(<\Throwable> ex) -> <Response>
    {
        let this->exception = ex;
        return this;
    }

    /**
     * Set a variable
     *
     * @param string key The key of output variable
     * @param mixed value The value of output variable
     *
     * @return Response
     */
    public function set(string key, value) -> <Response>
    {
        let this->outputs[key] = value;
        return this;
    }

    /**
     * Set multi variables
     *
     * @param array vars variables
     *
     * @return Response
     */
    public function sets(array vars) -> <Response>
    {
        var k, v;
        for k, v in vars {
            let this->outputs[k] = v;
        }
        return this;
    }

    /**
     * remove key from outputs
     *
     * @param string keys the keys need removed
     * @return Response
     */
    public function rmset() -> <Response>
    {
        var keys = func_get_args();
        if count(keys) == 0 {
            let this->outputs = [];
            return this;
        }
        var k;
        for k, _ in keys {
            unset this->outputs[k];
        }
        return this;
    }

    /**
     * Set the callback function's name of jsonp
     *
     * @param string funcName
     *
     * @return Response
     * @throws Exception phpple.illegalCallback illegal function name
     */
    public function setCallback(string funcName) -> <Response>
    {
        if (!preg_match("/^[a-zA-Z_][a-zA-Z_0-9.]{0,128}/", funcName)) {
            throw new Exception("phpple.illegalCallback");
        }
        let this->callback = funcName;

        // Change the encoding and format
        this->app->getRequest()->setOutputFormat(\Phpple\Http\OutputFormat::FORMAT_JSON);
        return this;
    }

    /**
     * Set output header
     *
     * @param string|array key key
     * @param null value value
     *
     * @return Response
     */
    public function setHeader(string key, value = null) -> <Response>
    {
        if this->needSetContentType {
            if (value === null && strpos(strtolower(key), "content-type:") === 0)
                || (value !== null && strtolower(key) == "content-type") {
                let this->needSetContentType = false;
            }
        }
        if value !== null {
            let this->headers[] = key . ": " . value;
        } else {
            let this->headers[] = key;
        }
        return this;
    }

    /**
     * Defines a cookie to be sent along with the rest of the HTTP headers
     *
     * @param string name The name of the cookie
     * @param string value The value of the cookie
     * @param int expires The time the cookie expires
     * @param string path The path on the server in which the cookie will be available on
     * @param string domain The (sub)domain that the cookie is available to
     * @param bool secure Indicates that the cookie should only be transmitted over a secure HTTPS connection from
     *                         the client
     * @param bool httponly When TRUE the cookie will be made accessible only through the HTTP protocol
     *
     * @return Response
     */
    public function setCookie(
        string name,
        string value = "",
        int expires = null,
        string path = "/",
        string domain = "",
        bool httponly = false,
        bool secure = false
    ) -> <Response>
    {
        let this->cookies[] = func_get_args();
        return this;
    }

    /**
     * 设置原始输出内容
     *
     * @param string rawData
     *
     * @return Response
     */
    public function setRaw(string rawData) -> <Response>
    {
        let this->rawData = rawData;
        return this;
    }

    /**
     * Redirect
     *
     * @param string url
     * @param bool permanent
     */
    public function redirect(string url, boolean permanent = false)
    {
        if (permanent) {
            this->setHeader("HTTP/1.1 301 Moved Permanently");
        }
        this->setHeader("Location", url);
        this->app->setEndStatus(Application::ENDSTATUS_OK);
        this->sendHeaders();
        this->end();
        exit();
    }

    /**
     * Set the header of framework
     *
     * @param string errCode
     *
     * @return Response
     */
    public function setFrHeader(string errCode = "suc") -> <Response>
    {
        var header = sprintf("phpple: id=%d", this->app->appId);

        if errCode != "suc" {
            var method = "r";
            var urls = explode("/", this->app->getRequest()->getUrl());
            if urls && strncmp(urls[count(urls) - 1], "_", 1) === 0 {
                // whether the last segment begin with "_"
                let method = "w";
            }
            let header .= sprintf(",e=%s,m=%s", errCode, method);
            var retry = this->app->getRequest()->get("retry");
            if retry > 0 {
                let header .= ",r=" . intval(retry);
            }
        }

        this->setHeader(header);
        return this;
    }

    /**
     * Tell brower or delagate not cache this page
     *
     * @return Response
     */
    public function setNoCache() -> <Response>
    {
        this->setHeader("Expires", "Mon, 26 Jul 1997 05:00:00 GMT");
        this->setHeader("Last-Modified", gmdate("D, d M Y H:i:s") . " GMT");
        this->setHeader("Cache-Control", "no-store, no-cache, must-revalidate, post-check=0, pre-check=0");
        this->setHeader("Pragma", "no-cache");

        return this;
    }

    /**
     * Set the variable of framework
     *
     * @param string key Key of the variable
     * @param mixed value Value of the variable
     *
     * @return Response
     */
    public function setFrVar(string key, value) -> <Response>
    {
        let this->results[key] = value;
        return this;
    }

    /**
     * Send the http headers
     *
     * @return Response
     */
    public function sendHeaders() -> <Response>
    {
        var cookie, header;
        for cookie in this->cookies {
            call_user_func_array("setcookie", cookie);
        }
        if php_sapi_name() == "cli" {
            for header in this->headers {
                this->logger->debug("header:". header);
            }
        } else {
            for header in this->headers {
                header(header);
            }
        }
        return this;
    }

    /**
     * End the output
     */
    public function end()
    {
        this->app->filter(Application::FILTER_OUTPUT);
        //Set the endstatus
        this->app->setEndStatus(Application::ENDSTATUS_OK);
        exit();
    }

    /**
     * Run tasks
     */
    private function runTasks()
    {
         // Check task
        if (!empty(this->tasks)) {
            fastcgi_finish_request();

            // allow to run one hour
            ini_set("max_execution_time", intval(Conf::get("phpple.fastcgi_finish_timeout", 3600)));

            var task;
            for task in this->tasks {
                // buffer output
                ob_start();
                call_user_func_array(task[0], task[1]);
                var output = ob_get_clean();
                if (output) {
                    this->logger->trace("task output:" . output);
                }
            }
        }
    }

    /**
     * Build the header named "Content-Type"
     *
     * @param of
     * @param encoding
     */
    private function buildContentType(string of, string encoding)
    {
        if !this->needSetContentType {
            return;
        }
        switch (of) {
            case "json":
                let this->headers[] = "Content-type: application/json; charset=" . encoding;
                break;
            case "html":
                let this->headers[] = "Content-Type: text/html; charset=" . encoding;
                break;
            case "xml":
                let this->headers[] = "Content-Type: text/xml; charset=" . encoding;
                break;
            case "jpg":
            case "png":
            case "gif":
                let this->headers[] = "Content-Type: image/" . of;
                break;
            default:
                let this->headers[] = "Content-Type: text/plain; charset=" . encoding;
        }

        let this->needSetContentType = false;
    }

    /**
     * Get the result of output
     *
     * @return array
     */
    private function getResult() -> array
    {
        var result;
        if this->exception {
            var errcode = this->exception->getMessage();
            var pos = strpos(errcode, " ");
            if pos {
                let errcode = substr(errcode, 0, pos);
            }
            if !preg_match("/^[a-zA-Z0-9\.\-_]{1,50}/", errcode) {
                //普通的错误信息不能传到前端
                let errcode = self::STATUS_FATAL;
            }
            let result = ["err": errcode];
            if errcode == self::STATUS_INPUT {
                // Take some data while check error
                let result["data"] = this->outputs;
                this->logger->debug("input data error:%s", print_r(result["data"], true));
            }
        } else {
            let result = [
                "err": self::STATUS_OK,
                "data": this->outputs
            ];
        }
        var key, value;
        for key, value in result {
            if !isset result[key] {
                let result[key] = value;
            }
        }
        return result;
    }

    /**
     * Format output
     *
     * @return mixed|string
     */
    protected function formatResponse()
    {
        var result = this->getResult();
        var of = this->app->getRequest()->getOutputFormat();
        this->buildContentType(of, this->app->getEncoding());
        if this->rawData {
            return this->rawData;
        }
        //formatter
        if (of == OutputFormat::FORMAT_JSON) {
            if (this->callback) {
                return this->callback . "(" . json_encode(result, JSON_UNESCAPED_UNICODE) . ")";
            }
            int options = JSON_UNESCAPED_UNICODE | JSON_UNESCAPED_SLASHES;
            if this->app->getRequest()->getPretty() {
                let options = options | JSON_PRETTY_PRINT;
            }
            return json_encode(result, options);
        } elseif (of == OutputFormat::FORMAT_XML) {
            return Xml::array2Xml(result, this->app->getEncoding());
        }
        return print_r(result, true);
    }

    /**
     * Send output
     */
    public function send()
    {
        this->setFrHeader();
        var data = this->formatResponse();
        this->sendHeaders();

        // fetch the output data
        var ob = ini_get("output_buffering");
        if ob && strtolower(ob) !== "off" {
            var str = ob_get_clean();
            //trim data
            let data = trim(str) . data;
        }

        if data {
            var outputHandlers = Conf::get("phpple.output.handler", []);
            if outputHandlers && !is_array(outputHandlers) {
                // support string
                let outputHandlers = [outputHandlers];
            }
            if outputHandlers {
                // call the global output handlers
                var handler;
                for handler in outputHandlers {
                    if is_callable(handler) {
                        let data = call_user_func(handler, data);
                    } else {
                        this->logger->warn(
                            "outouthandler:%s can't call",
                            is_array(handler) ? handler[1] : handler
                        );
                    }
                }
            }
            echo data;
        }

        this->runTasks();
    }

    /**
     * Add background task
     * @param callable task
     * @param array args
     * @return this
     */
    public function addTask(callable task, array args = []) -> <Response>
    {
        let this->tasks[] = [task, args];
        return this;
    }
}
