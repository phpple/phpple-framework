
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/concat.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phpple_Application) {

	ZEPHIR_REGISTER_CLASS(Phpple, Application, phpple, application, phpple_application_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phpple_application_ce, SL("errorTypeMap"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	/**
	 * site's root dir, default is the parent directory
	 * @var string
	 */
	zend_declare_property_null(phpple_application_ce, SL("rootDir"), ZEND_ACC_PRIVATE);

	/**
	 * site's root namespace,default is App
	 * @var string
	 */
	zend_declare_property_null(phpple_application_ce, SL("rootNs"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_application_ce, SL("logger"), ZEND_ACC_PROTECTED);

	/**
	 * Unique ID of the application
	 *
	 * @var int
	 */
	zend_declare_property_null(phpple_application_ce, SL("appId"), ZEND_ACC_PRIVATE);

	/**
	 * Application's timer
	 *
	 * @var Phpple\Util\Timer
	 */
	zend_declare_property_null(phpple_application_ce, SL("timer"), ZEND_ACC_PRIVATE);

	/**
	 * encoding
	 *
	 * @var string
	 */
	zend_declare_property_null(phpple_application_ce, SL("encoding"), ZEND_ACC_PRIVATE);

	/**
	 * end status
	 *
	 * @var string
	 */
	zend_declare_property_null(phpple_application_ce, SL("endStatus"), ZEND_ACC_PRIVATE);

	/**
	 * Debug mode，optional values: true/false/munual
	 * false: debug diable
	 * true： debug enable
	 * munual： debug manualable, enable by the param _d through the url
	 *
	 * @var boolean|string
	 */
	zend_declare_property_null(phpple_application_ce, SL("debug"), ZEND_ACC_PROTECTED);

	/**
	 * @var ResponseInterface
	 */
	zend_declare_property_null(phpple_application_ce, SL("response"), ZEND_ACC_PROTECTED);

	/**
	 * @var RequestInterface
	 */
	zend_declare_property_null(phpple_application_ce, SL("request"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_application_ce, SL("baseUrl"), ZEND_ACC_PRIVATE);

	zephir_declare_class_constant_string(phpple_application_ce, SL("FILTER_INIT"), "init");

	zephir_declare_class_constant_string(phpple_application_ce, SL("FILTER_INPUT"), "input");

	zephir_declare_class_constant_string(phpple_application_ce, SL("FILTER_ROUTE"), "route");

	zephir_declare_class_constant_string(phpple_application_ce, SL("FILTER_OUTPUT"), "output");

	zephir_declare_class_constant_string(phpple_application_ce, SL("FILTER_CLEAN"), "clean");

	zephir_declare_class_constant_bool(phpple_application_ce, SL("APP_DEBUG_ENABLE"), 1);

	zephir_declare_class_constant_bool(phpple_application_ce, SL("APP_DEBUG_DISABLE"), 0);

	zephir_declare_class_constant_string(phpple_application_ce, SL("APP_DEBUG_MANUAL"), "manual");

	zephir_declare_class_constant_string(phpple_application_ce, SL("ENDSTATUS_OK"), "ok");

	zephir_declare_class_constant_string(phpple_application_ce, SL("ENDSTATUS_INIT"), "init");

	zephir_declare_class_constant_string(phpple_application_ce, SL("ENDSTATUS_ERROR"), "error");

	zephir_declare_class_constant_string(phpple_application_ce, SL("DEFAULT_ENCODING"), "UTF-8");

	return SUCCESS;

}

PHP_METHOD(Phpple_Application, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Application, getLogger) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logger");

}

/**
 * Unique ID of the application
 */
PHP_METHOD(Phpple_Application, getAppId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "appId");

}

/**
 * Application's timer
 */
PHP_METHOD(Phpple_Application, getTimer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "timer");

}

/**
 * encoding
 */
PHP_METHOD(Phpple_Application, getEncoding) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encoding");

}

/**
 * end status
 */
PHP_METHOD(Phpple_Application, getEndStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "endStatus");

}

/**
 * Debug mode，optional values: true/false/munual
 *
 *
 * false: debug diable
 * true： debug enable
 * munual： debug manualable, enable by the param _d through the url
 *
 */
PHP_METHOD(Phpple_Application, getDebug) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "debug");

}

/**
 */
PHP_METHOD(Phpple_Application, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

/**
 */
PHP_METHOD(Phpple_Application, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

PHP_METHOD(Phpple_Application, getBaseUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "baseUrl");

}

PHP_METHOD(Phpple_Application, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, *ns_param = NULL, _0, _1, _2, _4, _5, _7, _8;
	zval dir, ns, _3, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dir_param, &ns_param);

	zephir_get_strval(&dir, dir_param);
	if (!ns_param) {
		ZEPHIR_INIT_VAR(&ns);
		ZVAL_STRING(&ns, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(ns_param) != IS_STRING && Z_TYPE_P(ns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_param) == IS_STRING)) {
		zephir_get_strval(&ns, ns_param);
	} else {
		ZEPHIR_INIT_VAR(&ns);
		ZVAL_EMPTY_STRING(&ns);
	}
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_readable", NULL, 3, &dir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_exception_ce, "phpple.dirNotReadable", "phpple/Application.zep", 101);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&ns, "")) {
		ZEPHIR_INIT_NVAR(&ns);
		ZVAL_STRING(&ns, "\\App");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, &dir, &_2, ZEPHIR_TRIM_RIGHT);
	zephir_get_strval(&_3, &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rootDir"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\");
	zephir_fast_trim(&_4, &ns, &_5, ZEPHIR_TRIM_RIGHT);
	zephir_get_strval(&_6, &_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rootNs"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "init");
	zephir_update_property_zval(this_ptr, ZEND_STRL("endStatus"), &_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "UTF-8");
	zephir_update_property_zval(this_ptr, ZEND_STRL("encoding"), &_7);
	ZEPHIR_INIT_NVAR(&_7);
	object_init_ex(&_7, phpple_util_timer_ce);
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("timer"), &_7);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "genappid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("appId"), &_8);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phpple_Application, setRequest) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &request);



	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);

}

/**
 * Run application.The entrence of application
 */
PHP_METHOD(Phpple_Application, run) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "total");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "init");
	ZEPHIR_CALL_METHOD(NULL, &_0, "begin", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "init");
	ZEPHIR_CALL_METHOD(NULL, &_3, "end", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "process");
	ZEPHIR_CALL_METHOD(NULL, &_4, "begin", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "process");
	ZEPHIR_CALL_METHOD(NULL, &_5, "end", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ok");
	zephir_update_property_zval(this_ptr, ZEND_STRL("endStatus"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Init
 */
PHP_METHOD(Phpple_Application, init) {

}

/**
 * Process
 */
PHP_METHOD(Phpple_Application, process) {

}

/**
 * Initialize log
 */
PHP_METHOD(Phpple_Application, initLogger) {

	zval _11;
	zval loggerName, _1, _2, logLevel, debug, notice, _4, logMode, _5, _7, _8, _12, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_9 = NULL, *_10 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&loggerName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&logLevel);
	ZVAL_UNDEF(&debug);
	ZVAL_UNDEF(&notice);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&logMode);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phpple.log.name");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "logger");
	ZEPHIR_CALL_CE_STATIC(&loggerName, phpple_util_conf_ce, "get", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "phpple.log.level");
	ZEPHIR_CALL_CE_STATIC(&logLevel, phpple_util_conf_ce, "get", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&debug);
	ZVAL_STRING(&debug, "debug");
	ZEPHIR_INIT_VAR(&notice);
	ZVAL_STRING(&notice, "notice");
	if (!(zephir_is_true(&logLevel))) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CPY_WRT(&logLevel, &debug);
		} else {
			ZEPHIR_CPY_WRT(&logLevel, &notice);
		}
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_4)) {
		ZEPHIR_CPY_WRT(&logLevel, &debug);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "phpple.log.mode");
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_CE_STATIC(&logMode, phpple_util_conf_ce, "get", &_0, 0, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "log");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getdir", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, phpple_log_logger_ce, "init", &_6, 0, &_7, &logLevel, &logMode);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_8, phpple_log_logger_ce, "getlogger", &_9, 0, &loggerName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlogger", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0);
	ZEPHIR_OBS_VAR(&_12);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("appId"), PH_NOISY_CC);
	zephir_array_update_string(&_11, SL("appid"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(NULL, phpple_log_logger_ce, "addbasic", &_10, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Initialize environment
 */
PHP_METHOD(Phpple_Application, initEnv) {

	zval _5, _6, _7;
	zval _0, _1, _2, _4, _8$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("encoding"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "mb_internal_encoding", NULL, 5, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("encoding"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "default_charset");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_3, 6, &_2, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_4, ((32767 | 2048) | 8));
	ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 7, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_fast_append(&_5, this_ptr);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "errorHandler");
	zephir_array_fast_append(&_5, &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 8, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_fast_append(&_6, this_ptr);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "exceptionHandler");
	zephir_array_fast_append(&_6, &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 9, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_fast_append(&_7, this_ptr);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "shutdownHandler");
	zephir_array_fast_append(&_7, &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 10, &_7);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "display_errors");
		ZVAL_LONG(&_9$$3, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_3, 6, &_8$$3, &_9$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate unique appId
 *
 * @return int
 */
PHP_METHOD(Phpple_Application, genAppId) {

	zval time, rand, id, _0, _1, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&rand);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&time, "gettimeofday", NULL, 11);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &time, SL("sec"), PH_NOISY | PH_READONLY, "phpple/Application.zep", 215);
	zephir_array_fetch_string(&_1, &time, SL("usec"), PH_NOISY | PH_READONLY, "phpple/Application.zep", 215);
	_2 = ((zephir_get_numberval(&_0) * 100) + zephir_get_numberval(&_1));
	ZEPHIR_INIT_NVAR(&time);
	ZVAL_LONG(&time, _2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_add_function(&_3, &time, &time);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_INIT_VAR(&rand);
	ZVAL_LONG(&rand, zephir_mt_rand(zephir_get_intval(&_4), zephir_get_intval(&_3)));
	ZEPHIR_INIT_VAR(&_5);
	zephir_bitwise_xor_function(&_5, &time, &rand);
	ZEPHIR_INIT_VAR(&id);
	ZVAL_LONG(&id, ((int) (zephir_get_numberval(&_5)) & 0xFFFFFFFF));
	ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(&id, 100));
	RETURN_MM_DOUBLE((zephir_floor(&_6) * (double) (100)));

}

/**
 * Shutdown handler
 */
PHP_METHOD(Phpple_Application, shutdownHandler) {

	zend_string *_7;
	zend_ulong _6;
	zval str;
	zval _0, _1, result, _2, key, time, *_4, _5, _10, _8$$3, _9$$4, _11$$5, _12$$5, _13$$5, _14$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "shutdownHandler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "notice", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "getresult", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&str);
	array_init(&str);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "[time:");
	ZEPHIR_MAKE_REF(&str);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_3, 12, &str, &_1);
	ZEPHIR_UNREF(&str);
	zephir_check_call_status();
	zephir_is_iterable(&result, 0, "phpple/Application.zep", 233);
	if (Z_TYPE_P(&result) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&result), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&time);
			ZVAL_COPY(&time, _4);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_SVSV(&_8$$3, " ", &key, "=", &time);
			ZEPHIR_MAKE_REF(&str);
			ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_3, 12, &str, &_8$$3);
			ZEPHIR_UNREF(&str);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &result, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &result, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &result, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&time, &result, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVSV(&_9$$4, " ", &key, "=", &time);
				ZEPHIR_MAKE_REF(&str);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_3, 12, &str, &_9$$4);
				ZEPHIR_UNREF(&str);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &result, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&time);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "]");
	ZEPHIR_MAKE_REF(&str);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_3, 12, &str, &_1);
	ZEPHIR_UNREF(&str);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_10)) {
		zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_fast_join_str(&_12$$5, SL(""), &str);
		zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("endStatus"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZEPHIR_CONCAT_VSV(&_14$$5, &_12$$5, " status=", &_13$$5);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "notice", NULL, 0, &_14$$5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *  Inner Exception handler
 *
 * @param Exception ex
 */
PHP_METHOD(Phpple_Application, exceptionHandler) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ex, ex_sub, _0, _1, errcode, errmsg, _2, pos, _5, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ex_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&errcode);
	ZVAL_UNDEF(&errmsg);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ex);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "exceptionHandler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "notice", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_exception_handler", NULL, 13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&errcode, ex, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, ex, "__tostring", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "caught exception, errcode:%s, trace: %s");
	ZEPHIR_CALL_FUNCTION(&errmsg, "sprintf", NULL, 14, &_1, &errcode, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, " ");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &errcode, &_1, 0 );
	if (ZEPHIR_GT_LONG(&pos, 0)) {
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &errcode, 0 , zephir_get_intval(&pos), 0);
		ZEPHIR_CPY_WRT(&errcode, &_4$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("endStatus"), &errcode);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_5, "error", NULL, 0, &errmsg);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Error handler
 *
 * @return boolean if return false, standard error handler will be invoked continually
 */
PHP_METHOD(Phpple_Application, errorHandler) {

	zval _12$$3, _18$$4, _26$$4;
	zval _0, _1, error, _2, _3, _14, _15, errmsg, _28, _29, _30, _31, _32, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, logLevel$$4, _16$$4, _17$$4, _19$$4, _20$$4, _21$$4, _22$$4, _23$$4, _24$$4, _25$$4, _27$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&errmsg);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&logLevel$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_26$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "errorHandler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "notice", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&error);
	zephir_get_args(&error);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 15);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &error, SL("0"), PH_NOISY | PH_READONLY, "phpple/Application.zep", 281);
	ZEPHIR_CALL_FUNCTION(&_3, "error_reporting", NULL, 7);
	zephir_check_call_status();
	if (!((zephir_get_intval(&_2) & zephir_get_intval(&_3)))) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_5$$3, &error, 0, PH_NOISY | PH_READONLY, "phpple/Application.zep", 284);
		zephir_array_fetch_long(&_6$$3, &error, 1, PH_NOISY | PH_READONLY, "phpple/Application.zep", 285);
		zephir_array_fetch_long(&_7$$3, &error, 2, PH_NOISY | PH_READONLY, "phpple/Application.zep", 286);
		zephir_array_fetch_long(&_8$$3, &error, 3, PH_NOISY | PH_READONLY, "phpple/Application.zep", 288);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "caught info, errno:%d,errmsg:%s,file:%s,line:%d");
		ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", &_11, 14, &_9$$3, &_5$$3, &_6$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "debug", NULL, 0, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$3);
		zephir_create_array(&_12$$3, 2, 0);
		zephir_array_fast_append(&_12$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "errorHandler");
		zephir_array_fast_append(&_12$$3, &_9$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", &_13, 8, &_12$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_static_property_ce(&_14, phpple_application_ce, SL("errorTypeMap"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_15, &error, 0, PH_READONLY, "phpple/Application.zep", 293);
	if (zephir_array_isset(&_14, &_15)) {
		zephir_read_static_property_ce(&_16$$4, phpple_application_ce, SL("errorTypeMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&logLevel$$4);
		ZEPHIR_OBS_VAR(&_17$$4);
		zephir_array_fetch_long(&_17$$4, &error, 0, PH_NOISY, "phpple/Application.zep", 294);
		zephir_array_fetch(&logLevel$$4, &_16$$4, &_17$$4, PH_NOISY, "phpple/Application.zep", 294);
		ZEPHIR_INIT_VAR(&_18$$4);
		zephir_create_array(&_18$$4, 2, 0);
		ZEPHIR_OBS_VAR(&_19$$4);
		zephir_read_property(&_19$$4, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC);
		zephir_array_fast_append(&_18$$4, &_19$$4);
		zephir_array_fast_append(&_18$$4, &logLevel$$4);
		ZEPHIR_INIT_VAR(&_20$$4);
		ZEPHIR_CONCAT_SVS(&_20$$4, "caught ", &logLevel$$4, ", errno:%d,errmsg:%s,file:%s,line:%d");
		zephir_array_fetch_long(&_21$$4, &error, 0, PH_NOISY | PH_READONLY, "phpple/Application.zep", 299);
		zephir_array_fetch_long(&_22$$4, &error, 1, PH_NOISY | PH_READONLY, "phpple/Application.zep", 300);
		zephir_array_fetch_long(&_23$$4, &error, 2, PH_NOISY | PH_READONLY, "phpple/Application.zep", 301);
		zephir_array_fetch_long(&_24$$4, &error, 3, PH_NOISY | PH_READONLY, "phpple/Application.zep", 303);
		ZEPHIR_CALL_FUNCTION(&_25$$4, "sprintf", &_11, 14, &_20$$4, &_21$$4, &_22$$4, &_23$$4, &_24$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 16, &_18$$4, &_25$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_26$$4);
		zephir_create_array(&_26$$4, 2, 0);
		zephir_array_fast_append(&_26$$4, this_ptr);
		ZEPHIR_INIT_VAR(&_27$$4);
		ZVAL_STRING(&_27$$4, "errorHandler");
		zephir_array_fast_append(&_26$$4, &_27$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", &_13, 8, &_26$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_28, &error, 0, PH_NOISY | PH_READONLY, "phpple/Application.zep", 311);
	zephir_array_fetch_long(&_29, &error, 1, PH_NOISY | PH_READONLY, "phpple/Application.zep", 312);
	zephir_array_fetch_long(&_30, &error, 2, PH_NOISY | PH_READONLY, "phpple/Application.zep", 313);
	zephir_array_fetch_long(&_31, &error, 3, PH_NOISY | PH_READONLY, "phpple/Application.zep", 315);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "caught error, errno:%d,errmsg:%s,file:%s,line:%d");
	ZEPHIR_CALL_FUNCTION(&errmsg, "sprintf", &_11, 14, &_1, &_28, &_29, &_30, &_31);
	zephir_check_call_status();
	zephir_read_property(&_32, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_32, "error", NULL, 0, &errmsg);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "error");
	zephir_update_property_zval(this_ptr, ZEND_STRL("endStatus"), &_1);
	RETURN_MM_BOOL(1);

}

/**
 * Get the dir by the name
 * @param name
 * @return string
 */
PHP_METHOD(Phpple_Application, getDir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &name, &_1, ZEPHIR_TRIM_BOTH);
	zephir_get_strval(&name, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	ZEPHIR_CALL_FUNCTION(&_3, "ucwords", NULL, 17, &name, &_2);
	zephir_check_call_status();
	zephir_get_strval(&name, &_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("rootDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSVS(return_value, &_4, "/", &name, "/");
	RETURN_MM();

}

/**
 * Get the namespace by the name
 * @return string
 */
PHP_METHOD(Phpple_Application, getNamespace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("rootNs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &name);
	ZEPHIR_CONCAT_VSV(return_value, &_0, "\\", &_1);
	RETURN_MM();

}

void zephir_init_static_properties_Phpple_Application(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	add_assoc_stringl_ex(&_0, SL("1024"), SL("notice"));
	add_assoc_stringl_ex(&_0, SL("512"), SL("warning"));
	add_assoc_stringl_ex(&_0, SL("256"), SL("error"));
	zephir_update_static_property_ce(phpple_application_ce, ZEND_STRL("errorTypeMap"), &_0);
	ZEPHIR_MM_RESTORE();

}

