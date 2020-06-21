namespace Phpple\Filter;

use Phpple\Application;
use Phpple\Util\Conf;
use Phpple\Http\Exception;
use Phpple\Log\LoggerInterface;

class RouteFilter implements FilterInterface
{
    const METHOD_BEFORE = "_before";
    const METHOD_AFTER = "_after";
    const DEFAULT_ACTION = "index";
    const CONTROLLER_FILE = "Controller.php";

    protected protectedMethods = [self::METHOD_BEFORE, self::METHOD_AFTER];
    protected methodExt = "";

    protected logger = null { set, get };

    public function __construct()
    {
        let this->methodExt = Conf::get("phpple.methodExt", "");
    }

    /**
     * @inheritDoc
     */
    public function execute(<Application> app) -> boolean
    {
        var request = app->getRequest();
        var url = request->getUrl();

        var info = this->getCtlAndFunc(url, app);

        var clsName = info[0];
        var path = info[1];
        var func = info[2];

        require path;
        var ctl;
        let ctl = new {clsName}();
        ctl->setLogger(app->getLogger());
        ctl->setDebug(app->getDebug());
        ctl->setAppId(app->getAppId());
        ctl->setRequest(app->getRequest());
        ctl->setResponse(app->getResponse());

        var methodInfo = this->buildMethod(ctl, func, app);

        if !methodInfo {
            throw Exception::withParams(Exception::EXCEPTION_NOT_FOUND, [
                "detail": "func not found",
                "func": func
            ]);
        }
        var mainMethod = methodInfo[0];
        var args = methodInfo[1];

        ctl->setMethod(func);
        ctl->setPath(path);
        ctl->setArgs(args);

        // call method _before
        if is_callable([ctl, self::METHOD_BEFORE]) {
            call_user_func([ctl, self::METHOD_BEFORE]);
        }

        // call main action method
        mainMethod->invokeArgs(ctl, args);

        // call method _after
        if (is_callable([ctl, self::METHOD_AFTER])) {
            call_user_func([ctl, self::METHOD_AFTER]);
        }

        return true;
    }

    /**
     * Get controller and method
     * @return [clsName, path, func]
     */
    private function getCtlAndFunc(string url, <Application> app) -> array
    {
        let url = trim(url, "/");
        var segs = array_diff(explode("/", url), [""]);
        var seg;
        for _, seg in segs {
            if seg == ".." || seg == "." {
                throw new Exception("router.u_illegalRouter");
            }
        }
        int segNum = count(segs);

        if segNum > 0 && in_array(segs[segNum - 1], this->protectedMethods) {
            throw new Exception(Exception::EXCEPTION_NOT_FOUND);
        }

        var ctlRoot = app->getDir("app/controller");
        string fullpath = ctlRoot . implode(DIRECTORY_SEPARATOR, segs);
        var path, func;
        if is_readable(fullpath . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE) {
            let path = fullpath . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE;
            let func = self::DEFAULT_ACTION;
        } else {
            if is_readable(fullpath . DIRECTORY_SEPARATOR . self::DEFAULT_ACTION . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE) {
                let path = fullpath . DIRECTORY_SEPARATOR . self::DEFAULT_ACTION . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE;
                let func = self::DEFAULT_ACTION;
                array_push(segs, self::DEFAULT_ACTION);
            } else {
                if segNum > 0 {
                    // one level at least
                    var rootSeg = array_slice(segs, 0, segNum - 1);
                    let path = rtrim(ctlRoot . implode(DIRECTORY_SEPARATOR, rootSeg), DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE;
                    let func = segs[segNum - 1];

                    array_pop(segs);
                } else {
                    let path = rtrim(ctlRoot, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR . self::CONTROLLER_FILE;
                    let func = self::DEFAULT_ACTION;
                }
            }
        }

        if (!is_readable(path)) {
            throw new Exception(Exception::EXCEPTION_NOT_FOUND . " path not readable:" . path);
        }
        let path = ucwords(path, DIRECTORY_SEPARATOR);
        //TODO StaticTypeInference=fcall undefined
        let segs = array_map("ucfirst", segs);
        string clsName = rtrim(app->getNamespace("controller") . "\\" . implode("\\", segs), "\\") . "\\Controller";
        return [clsName, path, func];
    }

    /**
     * Build args
     *
     * @param mixed controller
     * @param string method
     * @param array args
     *
     * @return \ReflectionMethod|false
     * @throws Exception
     */
    private function buildMethod(<Controller> controller, string method, <Application> app)
    {
        let method = method . this->methodExt;
        if !is_callable([controller, method]) {
            return null;
        }
        var reflection;
        let reflection = new \ReflectionMethod(controller, method);
        array args = [];
        var request = app->getRequest(), response = app->getResponse();
        var param;
        for param in reflection->getParameters() {
            string name = param->name;
            var cls = param->getClass();

            if cls != null {
                if request && cls->isInstance(request) {
                    array_push(args, request);
                } elseif response && cls->isInstance(response) {
                    array_push(args, response);
                }
                continue;
            }

            if request->has(name) {
                array_push(args, request->get(name));
            } elseif param->isDefaultValueAvailable() {
                array_push(args, param->getDefaultValue());
            } elseif param->allowsNull() {
                array_push(args, null);
            } else {
                throw new Exception("urlfilter.argIllegal");
            }
        }
        return [reflection, args];
    }
}
