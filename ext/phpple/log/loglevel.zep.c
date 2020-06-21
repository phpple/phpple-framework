
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Describes log levels.
 * @see https://github.com/php-fig/log/blob/master/Psr/Log/LogLevel.php
 */
ZEPHIR_INIT_CLASS(Phpple_Log_LogLevel) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Log, LogLevel, phpple, log_loglevel, NULL, 0);

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("EMERGENCY"), "emergency");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("ALERT"), "alert");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("CRITICAL"), "critical");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("ERROR"), "error");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("WARNING"), "warning");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("NOTICE"), "notice");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("INFO"), "info");

	zephir_declare_class_constant_string(phpple_log_loglevel_ce, SL("DEBUG"), "debug");

	return SUCCESS;

}

