
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Describes a logger instance.
 * @see https://github.com/php-fig/log/blob/master/Psr/Log/LoggerInterface.php
 */
ZEPHIR_INIT_CLASS(Phpple_Log_LoggerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phpple\\Log, LoggerInterface, phpple, log_loggerinterface, phpple_log_loggerinterface_method_entry);

	return SUCCESS;

}

/**
 * System is unusable.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, emergency);

/**
 * Action must be taken immediately.
 *
 * Example: Entire website down, database unavailable, etc. This should
 * trigger the SMS alerts and wake you up.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, alert);

/**
 * Critical conditions.
 *
 * Example: Application component unavailable, unexpected exception.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, critical);

/**
 * Runtime errors that do not require immediate action but should typically
 * be logged and monitored.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, error);

/**
 * Exceptional occurrences that are not errors.
 *
 * Example: Use of deprecated APIs, poor use of an API, undesirable things
 * that are not necessarily wrong.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, warning);

/**
 * Normal but significant events.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, notice);

/**
 * Interesting events.
 *
 * Example: User logs in, SQL logs.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, info);

/**
 * Detailed debug information.
 *
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, debug);

/**
 * Logs with an arbitrary level.
 *
 * @param mixed   level
 * @param string  message
 * @param mixed[] context
 *
 * @return void
 *
 * @throws \Psr\Log\InvalidArgumentException
 */
ZEPHIR_DOC_METHOD(Phpple_Log_LoggerInterface, log);

