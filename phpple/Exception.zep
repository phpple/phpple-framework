namespace Phpple;

class Exception extends \Exception
{
    private params;

    /**
     * Set Params
     * @param array $params
     */
    public function setParams(array params)
    {
        var key, val;
        for key, val in params {
            let this->params[key] = val;
        }
    }

    /**
     * Get Exception with Params
     * @param msg
     * @param array params
     * @param int code
     * @throws Exception
     */
    public static function withParams(string msg, array params, int code = 0) -> <self>
    {
        var ex;
        let ex = new self(msg, code);
        ex->setParams(params);
        return ex;
    }

    /**
     * Get params
     * @return array
     */
    public function getParams() -> array
    {
        return this->params;
    }
}
