namespace Phpple\Helper;

/**
* Mock the http request
*/
class RequestBuilder
{
    static private defaultOptions = [
        "DOCUMENT_ROOT": "/Users/ronnie/test/web",
        "REMOTE_ADDR": "::1",
        "REMOTE_PORT": "54210",
        "SERVER_SOFTWARE": "Phpple Framework",
        "SERVER_PROTOCOL": "HTTP/1.1",
        "SERVER_NAME": "localhost",
        "SERVER_PORT": "80",
        "REQUEST_URI": "/",
        "REQUEST_METHOD": "GET",
        "SCRIPT_NAME": "/index.php",
        "SCRIPT_FILENAME": "/Users/ronnie/test/web/index.php",
        "PHP_SELF": "/index.php",
        "QUERY_STRING": "",
        "HTTP_HOST": "localhost:80",
        "HTTP_USER_AGENT": "Phpple Php Framework Request",
        "HTTP_ACCEPT": "*/*",
        "REQUEST_TIME_FLOAT": 0,
        "REQUEST_TIME": 0
    ];

    /**
     * Build HTTP get request
     * @param string url
     * @param array headers
     */
    public static function buildGetRequest(string url, array headers = [])
    {
        var headers = self::buildHeaders(url, headers);
        var key, val;
        for key, val in headers {
            let _SERVER[key] = val;
        }

        var query = headers["QUERY_STRING"], args;
        parse_str(query, args);
        for key, val in args {
            let _GET[key] = val;
        }
    }

    /**
     * Build HTTP post request
     * @param url
     * @param data
     * @param array headers
     */
    public static function buildPostRequest(string url, array data, array headers = [])
    {
        var headers = self::buildHeaders(url, headers);
        var key, val;
        for key,val in headers {
            let _SERVER[key] = val;
        }
        let _SERVER["REQUEST_METHOD"] = "POST";

        // build the query data
        var query = headers["QUERY_STRING"], args;
        parse_str(query, args);
        for key, val in args {
            let _GET[key] = val;
        }

        // build the post data
        for key, val in data {
            let _POST[key] = val;
        }
    }

    /**
     * Build the headers
     * @param string uri
     * @param array headers
     */
    private static function buildHeaders(string uri, array headers = []) -> array
    {
        var defaultOptions;
        let defaultOptions = self::defaultOptions;

        var info = parse_url(uri);
        let defaultOptions["REQUEST_URI"] = info["path"];
        let defaultOptions["QUERY_STRING"] = "";
        if info["query"] {
            let defaultOptions["QUERY_STRING"] = info["query"];
        };
        var key, val;
        for key, val in headers {
            let defaultOptions[key] = val;
        }
        return defaultOptions;
    }
}
