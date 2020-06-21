namespace Phpple\Http;

use Phpple\RequestInterface;
use Phpple\Log\LoggerInterface;
use Phpple\Application;

class Request implements RequestInterface
{
    private url { get, set };
    private uri { get, set };
    private rawUri { set, get };
    private prefix {get, set };
    private method {get, set };

    private serverEnvs = [] { set, get };
    private inputs = [] { set, get };
    private datas = [] { set, get };

    private app;
    protected logger { set };
    private now { set, get };
    private schema { set, get };
    private host { set, get };
    private userIp { set, get };
    private clientIp { set, get };
    private cookies { set, get };

    private isAjax = false { set, get };
    private pretty = false { set, get };

    private inputFormat { set, get };
    private outputFormat { set, get };

    public function __construct(<Application> app = null)
    {
        let this->app = app;
    }

    /**
     * Whether have the attribute named key
     */
    public function has(string key) -> boolean
    {
        return array_key_exists(key, this->inputs);
    }
    
    /**
     * Reset
     */
    public function reset()
    {
        let this->app = null;
        let this->inputs = [];
        let this->datas = [];
        let this->cookies = [];
        let this->pretty = false;
    }

    /**
     * Fetch the request data by key
     *
     * @param  string key Name of the param
     * @param null default
     *
     * @return mixed|null
     */
    public function get(string key, defval = null)
    {
        if array_key_exists(key, this->inputs) {
            return this->inputs[key];
        }
        return defval;
    }

    /**
     * Fetch a lot of _GET data
     *
     * @param \string[] ...keys
     *
     * @return array
     */
    public function gets() -> array
    {
        var keys = func_get_args();
        var ret = [], key;
        for key in keys {
            if array_key_exists(key, this->inputs) {
                let ret[key] = this->inputs[key];
            } else {
                let ret[key] = null;
            }
        }
        return ret;
    }

    /**
     * Set user data by key
     *
     * @param string key
     * @param        value
     * @return this
     */
    public function setData(string key, val) -> <Request>
    {
        let this->datas[key] = val;
        return this;
    }

    /**
     * Fetch user data by key
     *
     * @param string key
     * @param null default
     *
     * @return mixed|null
     */
    public function getData(string key, defval = null) -> var
    {
        if array_key_exists(key, this->datas) {
            return this->datas[key];
        }
        return defval;
    }

    /**
     * Fetch the cookie by key
     *
     * @param string key key of cookie
     * @param string default default value
     *
     * @return string
     */
    public function getCookie(string key, defval = null) -> var
    {
        if array_key_exists(key, this->cookies) {
            return this->cookies[key];
        }
        return defval;
    }

    /**
     * Get the header value,it will become uppercase, and add the prefix "HTTP_'
     *
     * @param string key key of the header
     * @param string default default value
     *
     * @return string
     */
    public function getHeader(string key, defval = null) -> var
    {
        if strpos(key, "-") !== false {
            let key = str_replace("-", "_", key);
        }
        var name;
        let name = "HTTP_" . strtoupper(key);
        if array_key_exists(name, this->serverEnvs) {
            return this->serverEnvs[name];
        }
        return defval;
    }

    /**
     * Fetch the upload file
     *
     * @param string key 名称
     *
     * @return array | null
     */
    public function getFile(key)
    {
        if isset(_FILES[key]) {
            return _FILES[key];
        }
        return null;
    }
}
