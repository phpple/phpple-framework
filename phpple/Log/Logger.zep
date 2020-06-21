namespace Phpple\Log;
//
//use Phpple\Exception;
//
class Logger implements LoggerInterface
{
    const BUFFER_SIZE = 50;

    const DEFAULT_LOGGER_NAME = "logger";
    const MODE_DEFAULT = 0;
    const MODE_HOURLY = 1;
    const MODE_DAILY = 2;
    const MODE_MONTHLY = 4;
    const MODE_YEARLY = 8;

    const MIN_ERROR_LEVEL = LogLevel::ERROR;

    const LOG_TYPE_NORMAL = "normal";
    const LOG_TYPE_ERROR = "error";

    static private loggers = [];
    static private basic = [];
    static private dir;
    static private minLevel = 0;
    static private mode = self::MODE_DEFAULT;
    // log levels
    static private logLevels = [
        "emergency":    0x08,
        "alert":        0x07,
        "critical":     0x06,
        "error":        0x05,
        "warning":      0x04,
        "notice":       0x03,
        "info":         0x02,
        "debug":        0x01
    ];

    private name = "";
    private paths = [];
    private fhs = [];
    private buffers = [];

    private function __construct(string name)
    {
        let this->name = name;
        let this->fhs[self::LOG_TYPE_NORMAL] = null;
        let this->fhs[self::LOG_TYPE_ERROR] = null;

        let this->buffers[self::LOG_TYPE_NORMAL] = [];
        let this->buffers[self::LOG_TYPE_ERROR] = [];

        let this->paths[self::LOG_TYPE_NORMAL] = self::getPathByMode(name, self::mode, self::LOG_TYPE_NORMAL);
        let this->paths[self::LOG_TYPE_ERROR] = self::getPathByMode(name, self::mode, self::LOG_TYPE_ERROR);
    }

    /**
     * Initlize the logger
     * @param string dir the log's directory
     */
    public static function init(string dir, string level, int mode)
    {
        // Check directory
        if !is_writable(dir) {
            throw new Exception("logger.dirNotWritable");
        }
        let self::dir = dir;
        let self::minLevel = self::logLevels[level];
        let self::mode = mode;
    }

    /**
     * Get the logger instance
     * @param string name
     * @return mixed|Logger
     */
    public static function getLogger(string name = self::DEFAULT_LOGGER_NAME) -> <LoggerInterface> | null
    {
        if isset self::loggers[name] {
            return self::loggers[name];
        }
        let self::loggers[name] = new self(name);
        return self::loggers[name];
    }

    /**
     * Set the basic options
     * @param array options
     */
    public static function addBasic(array basic)
    {
        var key, val;
        for key, val in basic {
            let self::basic[key] = val;
        }
    }

    /**
     * Get the log path by the mode
     */
    private static function getPathByMode(string name, int mode, string type = self::LOG_TYPE_NORMAL) -> string
    {
        var tag = "";
        switch (mode) {
            case self::MODE_HOURLY:
                let tag = date("Y-m-d-H");
                break;
            case self::MODE_DAILY:
                let tag = date("Y-m-d");
                break;
            case self::MODE_MONTHLY:
                let tag = date("Y-m");
                break;
            case self::MODE_YEARLY:
                let tag = date("Y");
                break;
        }
        if tag {
            let tag = "-" . tag;
        }
        string extension = ".log";
        if type == self::LOG_TYPE_ERROR {
            let extension = ".wf.log";
        }
        return sprintf(
            "%s%s%s%s%s",
            self::dir,
            DIRECTORY_SEPARATOR,
            name,
            tag,
            extension
        );
    }

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed  level
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function log(level, string message, array context = [])
    {
        if self::logLevels[level] < self::minLevel {
            return;
        }

        var secs = explode(" ", microtime());
        var usec = secs[0];
        var sec = secs[1];
        var msg = sprintf(
            "[%s.%06d] %s [name=%s] [%s] %s %s\n",
            date("Y-m-d H:i:s", sec),
            usec * 1000000,
            strtoupper(level),
            this->name,
            self::basic ? http_build_query(self::basic) : "",
            message,
            json_encode(context, JSON_UNESCAPED_UNICODE)
        );
        var type = self::getLogType(level);
        this->outputLog(type, msg);
    }

    /**
     * Get the writer
     * @return resource
     */
    private function getWriter(string type) -> var
    {
        if this->fhs[type] !== null {
            return this->fhs[type];
        }
        let this->fhs[type] = fopen(this->paths[type], "a+");
        return this->fhs[type];
    }

    /**
     * Output log
     */
    private function outputLog(string type, msg)
    {
        array_push(this->buffers[type], msg);
        if count(this->buffers[type]) == self::BUFFER_SIZE {
            this->flushLogs(type);
        }
    }

    /**
     * Get log type
     */
    private static function getLogType(string level)
    {
        if intval(self::logLevels[level]) < intval(Logger::MIN_ERROR_LEVEL) {
            return self::LOG_TYPE_ERROR;
        }
        return self::LOG_TYPE_NORMAL;
    }

    /**
     * Refresh log to file
     */
    private function flushLogs(string type)
    {
        var writer = this->getWriter(type);
        if writer {
            fwrite(writer, implode("", this->buffers[type]));
        }
        let this->buffers[type] = [];
    }

    /**
     * Destruct of Logger
     */
    public function __destruct()
    {
        var type;
        for type, _ in this->buffers {
            this->flushLogs(type);
        }
        for type, _ in this->fhs {
            if !this->fhs[type] {
                continue;
            }
            fclose(this->fhs[type]);
            let this->fhs[type] = null;
        }
    }


    /**
     * System is unusable.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function emergency(string message, array context = [])
    {
        this->log(LogLevel::EMERGENCY, message, context);
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function alert(string message, array context = [])
    {
        this->log(LogLevel::ALERT, message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function critical(string message, array context = [])
    {
        this->log(LogLevel::CRITICAL, message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function error(string message, array context = [])
    {
        this->log(LogLevel::ERROR, message, context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function warning(string message, array context = [])
    {
        this->log(LogLevel::WARNING, message, context);
    }

    /**
     * Normal but significant events.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function notice(string message, array context = [])
    {
        this->log(LogLevel::NOTICE, message, context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function info(string message, array context = [])
    {
        this->log(LogLevel::INFO, message, context);
    }

    /**
     * Detailed debug information.
     *
     * @param string message
     * @param array  context
     *
     * @return void
     */
    public function debug(string message, array context = [])
    {
        this->log(LogLevel::DEBUG, message, context);
    }
}
