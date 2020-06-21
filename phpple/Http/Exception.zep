namespace Phpple\Http;

class Exception extends \Phpple\Exception
{
    const EXCEPTION_NOT_FOUND = "phpple.u_notfound";
    const EXCEPTION_NO_POWER = "phpple.u_power";
    const EXCEPTION_NOT_LOGIN = "phpple.u_login";
    const EXCEPTION_FATAL = "phpple.fatal";
    const EXCEPTION_INPUT = "phpple.u_input";
    const EXCEPTION_COMMON = "phpple.error";
    const EXCEPTION_ARGS = "phpple.u_args";
}
