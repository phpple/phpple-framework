namespace Phpple\Log;

/**
 * Describes log levels.
 * @see https://github.com/php-fig/log/blob/master/Psr/Log/LogLevel.php
 */
class LogLevel
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";
}
