namespace Phpple;

use Phpple\Util\Timer;
use Phpple\Util\Conf;
use Phpple\Log\Logger;
use Phpple\Log\LogLevel;
use Phpple\Log\LoggerInterface;
use Phpple\RequestInterface;

abstract class Application
{
    const FILTER_INIT = "init";
    const FILTER_INPUT = "input";
    const FILTER_ROUTE = "route";
    const FILTER_OUTPUT = "output";
    const FILTER_CLEAN = "clean";

    const APP_DEBUG_ENABLE = true;
    const APP_DEBUG_DISABLE = false;
    const APP_DEBUG_MANUAL = "manual";

    const ENDSTATUS_OK = "ok";
    const ENDSTATUS_INIT = "init";
    const ENDSTATUS_ERROR = "error";

    const DEFAULT_ENCODING = "UTF-8";

    private static errorTypeMap = [
        "1024": LogLevel::NOTICE,
        "512": LogLevel::WARNING,
        "256": LogLevel::ERROR
    ];

    /**
     * site's root dir, default is the parent directory
     * @var string
     */
    private rootDir;

    /**
     * site's root namespace,default is App
     * @var string
     */
    private rootNs;

    protected logger = null { set, get };

    /**
     * Unique ID of the application
     *
     * @var int
     */
    private appId { get };

    /**
     * Application's timer
     *
     * @var Phpple\Util\Timer
     */
    private timer { get };

    /**
     * encoding
     *
     * @var string
     */
    private encoding { get };

    /**
     * end status
     *
     * @var string
     */
    private endStatus { get };

    /**
     * Debug mode，optional values: true/false/munual
     * false: debug diable
     * true： debug enable
     * munual： debug manualable, enable by the param _d through the url
     *
     * @var boolean|string
     */
    protected debug { get };

    /**
     * @var ResponseInterface
     */
    protected response { get };

    /**
     * @var RequestInterface
     */
    protected request { get };

    private baseUrl { get };

    public function __construct(string dir, string! ns = null)
    {
        if !is_readable(dir) {
            throw new Exception("phpple.dirNotReadable");
        }
        if ns === null {
            let ns = "\\App";
        }
        let this->rootDir = (string)rtrim(dir, DIRECTORY_SEPARATOR);
        let this->rootNs = (string)rtrim(ns, "\\");

        let this->endStatus = self::ENDSTATUS_INIT;
        let this->encoding = self::DEFAULT_ENCODING;
        let this->timer = new Timer();
        let this->appId = this->genAppId();
    }

    public function setRequest(<RequestInterface> request)
    {
        let this->request = request;
    }

    /**
     * Run application.The entrence of application
     */
    public function run()
    {
//        var ex;

        this->timer->begin("total", "init");
//        try {
            this->init();
//        } catch \Throwable,ex {
//            this->exceptionHandler(ex);
//        }
        this->timer->end("init");

        this->timer->begin("process");
//        try {
            this->process();
//        } catch \Throwable,ex {
//            this->exceptionHandler(ex);
//        }
        this->timer->end("process");

        let this->endStatus = self::ENDSTATUS_OK;
    }

    /**
     * Init
     */
    abstract protected function init();

    /**
     * Process
     */
    abstract protected function process();

    /**
     * Initialize log
     */
    public function initLogger()
    {
        var loggerName = Conf::get("phpple.log.name", Logger::DEFAULT_LOGGER_NAME);
        var logLevel = Conf::get("phpple.log.level");
        var debug, notice;
        let debug = LogLevel::DEBUG;
        let notice = LogLevel::NOTICE;
        if !logLevel {
            if this->debug {
                let logLevel =debug;
            } else {
                let logLevel = notice;
            }
        }
        // set log level as debug if in debug mode
        if this->debug === true {
            let logLevel = debug;
        }

        var logMode = Conf::get("phpple.log.mode", Logger::MODE_DAILY);
        Logger::init(this->getDir("log"), logLevel, logMode);

        this->setLogger(Logger::getLogger(loggerName));
        Logger::addBasic([
            "appid": this->appId
        ]);
    }

    /**
     * Initialize environment
     */
    protected function initEnv()
    {
        mb_internal_encoding(this->encoding);
        ini_set("default_charset", this->encoding);
        error_reporting(E_ALL | E_STRICT | E_NOTICE);

        set_error_handler([this, "errorHandler"]);
        set_exception_handler([this, "exceptionHandler"]);
        register_shutdown_function([this, "shutdownHandler"]);

        if this->debug {
            ini_set("display_errors", 1);
        }
    }


    /**
     * Generate unique appId
     *
     * @return int
     */
    protected function genAppId()
    {
        var time, rand, id;
        let time = gettimeofday();
        let time = time["sec"] * 100 + time["usec"];
        let rand = mt_rand(1, time + time);
        let id = (time ^ rand) & 0xFFFFFFFF;
        return floor(id / 100) * 100;
    }

    /**
     * Shutdown handler
     */
    public function shutdownHandler()
    {
        this->logger->notice("shutdownHandler");
        var result = this->timer->getResult(), key, time;
        array str = [];
        array_push(str, "[time:");
        for key, time in result {
            array_push(str, " " . key . "=" . time);
        }
        array_push(str, "]");
        if this->logger {
            this->logger->notice(implode("", str). " status=". this->endStatus);
        }

//        if (true !== Conf::get('phpple.disable_db')) {
//            //做一些清理
//            TxScope::rollbackAll();
//        }
    }
    
    /**
     *  Inner Exception handler
     *
     * @param Exception ex
     */
    public function exceptionHandler(ex)
    {
        this->logger->notice("exceptionHandler");
        restore_exception_handler();
        var errcode = ex->getMessage();
        var errmsg = sprintf("caught exception, errcode:%s, trace: %s", errcode, ex->__toString());
        var pos = strpos(errcode, " ");
        if pos > 0 {
            let errcode = substr(errcode, 0, pos);
        }
        let this->endStatus = errcode;
//        if (this->isUserErr(errcode)) {
//            Logger::trace(errmsg);
//        } else {
        this->logger->error(errmsg);
//        }
    }

    /**
     * Error handler
     *
     * @return boolean if return false, standard error handler will be invoked continually
     */
    public function errorHandler()
    {
        this->logger->notice("errorHandler");
        var error;
        let error = func_get_args();
        restore_error_handler();

//        int errorLevel = intval(error["0"]);
//        int reporting = intval(error_reporting());
        if !(intval(error["0"]) & intval(error_reporting())) {
            this->logger->debug(sprintf(
                "caught info, errno:%d,errmsg:%s,file:%s,line:%d",
                error[0],
                error[1],
                error[2],
                error[3]
            ));
            set_error_handler([this, "errorHandler"]);
            return false;
        }

        if isset self::errorTypeMap[error[0]] {
            var logLevel = self::errorTypeMap[error[0]];
            call_user_func(
                [this->logger, logLevel],
                sprintf(
                    "caught " . logLevel . ", errno:%d,errmsg:%s,file:%s,line:%d",
                    error[0],
                    error[1],
                    error[2],
                    error[3]
                )
            );
            set_error_handler([this, "errorHandler"]);
            return false;
        }

        var errmsg = sprintf(
            "caught error, errno:%d,errmsg:%s,file:%s,line:%d",
            error[0],
            error[1],
            error[2],
            error[3]
        );
        this->logger->error(errmsg);
        let this->endStatus = self::ENDSTATUS_ERROR;
        return true;
    }

    /**
     * Get the dir by the name
     * @param name
     * @return string
     */
    public function getDir(string name) -> string
    {
        let name = trim(name, DIRECTORY_SEPARATOR);
        let name = ucwords(name, DIRECTORY_SEPARATOR);
        return this->rootDir. DIRECTORY_SEPARATOR . name . DIRECTORY_SEPARATOR;
    }

    /**
     * Get the namespace by the name
     * @return string
     */
    public function getNamespace(string name) -> string
    {
        return this->rootNs . "\\" . ucfirst(name);
    }
}
