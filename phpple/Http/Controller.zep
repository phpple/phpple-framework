namespace Phpple\Http;

class Controller
{
    protected logger { set };

    protected appId { set };
    protected debug { set };
    protected method { set };
    protected args { set};
    protected path { set };

    protected request { set };
    protected response { set };

    public function _before()
    {

    }

    public function _after()
    {

    }

    /**
     * Fetch request datas
     *
     * @param \string[] keys
     *
     * @return array
     * @see Request::gets
     */
    public function gets() -> array
    {
        return call_user_func_array([this->request, "gets"], func_get_args());
    }
    
    /**
     * Fetch request data
     *
     * @param string key
     * @param null default
     *
     * @return mixed|null
     * @see Request::get
     */
    public function get(string key, defval = null) -> var
    {
        return this->request->get(key, defval);
    }

    /**
     * Set response data
     *
     * @param string key
     * @param mixed  value
     *
     * @return this
     * @see Response::set
     */
    public function set(string key, value = null) -> <Controller>
    {
        if (is_array(key)) {
            this->response->sets(key);
            return this;
        }
        this->response->set(key, value);
        return this;
    }

    /**
     * Set response datas
     *
     * @param \string[] vars
     *
     * @see Response::sets
     * @return this
     */
    public function sets(array vars) -> <Controller>
    {
        this->response->sets(vars);
        return this;
    }

    /**
     * Fetch user data by key
     *
     * @param string key
     * @param null defval
     * @return mixed
     *
     * @see Request::getData
     */
    public function getData(string key, defval = null) -> var
    {
        return this->request->getData(key, defval);
    }

    /**
     * Set user data by key
     *
     * @param string key
     * @param        value
     * @return this
     */
    public function setData(string key, value) -> <Controller>
    {
        this->request->setData(key, value);
        return this;
    }

    /**
     * Set user data by key
     *
     * @param string key
     * @param        value
     * @return this
     */
    public function setDatas(array vars) -> <Controller>
    {
        this->request->setDatas(vars);
        return this;
    }
}

