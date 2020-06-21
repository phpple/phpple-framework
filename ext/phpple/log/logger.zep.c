
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Phpple_Log_Logger) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Log, Logger, phpple, log_logger, phpple_log_logger_method_entry, 0);

	zend_declare_property_null(phpple_log_logger_ce, SL("loggers"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("basic"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("dir"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_long(phpple_log_logger_ce, SL("minLevel"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_long(phpple_log_logger_ce, SL("mode"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("logLevels"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	zend_declare_property_string(phpple_log_logger_ce, SL("name"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("paths"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("fhs"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_log_logger_ce, SL("buffers"), ZEND_ACC_PRIVATE);

	phpple_log_logger_ce->create_object = zephir_init_properties_Phpple_Log_Logger;
	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("BUFFER_SIZE"), 50);

	zephir_declare_class_constant_string(phpple_log_logger_ce, SL("DEFAULT_LOGGER_NAME"), "logger");

	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("MODE_DEFAULT"), 0);

	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("MODE_HOURLY"), 1);

	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("MODE_DAILY"), 2);

	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("MODE_MONTHLY"), 4);

	zephir_declare_class_constant_long(phpple_log_logger_ce, SL("MODE_YEARLY"), 8);

	zephir_declare_class_constant_string(phpple_log_logger_ce, SL("MIN_ERROR_LEVEL"), "error");

	zephir_declare_class_constant_string(phpple_log_logger_ce, SL("LOG_TYPE_NORMAL"), "normal");

	zephir_declare_class_constant_string(phpple_log_logger_ce, SL("LOG_TYPE_ERROR"), "error");

	zend_class_implements(phpple_log_logger_ce, 1, phpple_log_loggerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Log_Logger, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL;
	zval *name_param = NULL, __$null, _0, _1, _2, _3, _4, _5, _6, _8, _9, _10, _11;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "normal");
	zephir_update_property_array(this_ptr, SL("fhs"), &_0, &__$null);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "error");
	zephir_update_property_array(this_ptr, SL("fhs"), &_1, &__$null);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "normal");
	zephir_update_property_array(this_ptr, SL("buffers"), &_3, &_2);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "error");
	zephir_update_property_array(this_ptr, SL("buffers"), &_5, &_4);
	zephir_read_static_property_ce(&_8, phpple_log_logger_ce, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "normal");
	ZEPHIR_CALL_SELF(&_6, "getpathbymode", &_7, 55, &name, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "normal");
	zephir_update_property_array(this_ptr, SL("paths"), &_9, &_6);
	zephir_read_static_property_ce(&_10, phpple_log_logger_ce, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "error");
	ZEPHIR_CALL_SELF(&_6, "getpathbymode", &_7, 55, &name, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_STRING(&_11, "error");
	zephir_update_property_array(this_ptr, SL("paths"), &_11, &_6);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initlize the logger
 * @param string dir the log's directory
 */
PHP_METHOD(Phpple_Log_Logger, init) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, *level_param = NULL, *mode_param = NULL, _0, _1, _2, _3;
	zval dir, level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dir_param, &level_param, &mode_param);

	zephir_get_strval(&dir, dir_param);
	zephir_get_strval(&level, level_param);
	mode = zephir_get_intval(mode_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_writable", NULL, 56, &dir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_log_exception_ce, "logger.dirNotWritable", "phpple/Log/Logger.zep", 64);
		return;
	}
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("dir"), &dir);
	zephir_read_static_property_ce(&_1, phpple_log_logger_ce, SL("logLevels"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &level, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 67);
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("minLevel"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, mode);
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("mode"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the logger instance
 * @param string name
 * @return mixed|Logger
 */
PHP_METHOD(Phpple_Log_Logger, getLogger) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _5, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "logger");
	} else {
		zephir_get_strval(&name, name_param);
	}


	zephir_read_static_property_ce(&_0, phpple_log_logger_ce, SL("loggers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_static_property_ce(&_1$$3, phpple_log_logger_ce, SL("loggers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 79);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phpple_log_logger_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 57, &name);
	zephir_check_call_status();
	zephir_update_static_property_array_multi_ce(phpple_log_logger_ce, SL("loggers"), &_3, SL("z"), 1, &name);
	zephir_read_static_property_ce(&_4, phpple_log_logger_ce, SL("loggers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 82);
	RETURN_CTOR(&_5);

}

/**
 * Set the basic options
 * @param array options
 */
PHP_METHOD(Phpple_Log_Logger, addBasic) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basic_param = NULL, key, val, *_0, _1;
	zval basic;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basic);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basic_param);

	zephir_get_arrval(&basic, basic_param);


	zephir_is_iterable(&basic, 0, "phpple/Log/Logger.zep", 95);
	if (Z_TYPE_P(&basic) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&basic), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			zephir_update_static_property_array_multi_ce(phpple_log_logger_ce, SL("basic"), &val, SL("z"), 1, &key);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &basic, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &basic, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &basic, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &basic, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_static_property_array_multi_ce(phpple_log_logger_ce, SL("basic"), &val, SL("z"), 1, &key);
			ZEPHIR_CALL_METHOD(NULL, &basic, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the log path by the mode
 */
PHP_METHOD(Phpple_Log_Logger, getPathByMode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *mode_param = NULL, *type_param = NULL, tag, _6, _7, _8, _0$$3, _2$$4, _3$$5, _4$$6, _5$$7;
	zval name, type, extension;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &mode_param, &type_param);

	zephir_get_strval(&name, name_param);
	mode = zephir_get_intval(mode_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "normal");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&tag);
	ZVAL_STRING(&tag, "");
	do {
		if (mode == 1) {
			ZEPHIR_INIT_VAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Y-m-d-H");
			ZEPHIR_CALL_FUNCTION(&tag, "date", &_1, 26, &_0$$3);
			zephir_check_call_status();
			break;
		}
		if (mode == 2) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "Y-m-d");
			ZEPHIR_CALL_FUNCTION(&tag, "date", &_1, 26, &_2$$4);
			zephir_check_call_status();
			break;
		}
		if (mode == 4) {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "Y-m");
			ZEPHIR_CALL_FUNCTION(&tag, "date", &_1, 26, &_3$$5);
			zephir_check_call_status();
			break;
		}
		if (mode == 8) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "Y");
			ZEPHIR_CALL_FUNCTION(&tag, "date", &_1, 26, &_4$$6);
			zephir_check_call_status();
			break;
		}
	} while(0);

	if (zephir_is_true(&tag)) {
		ZEPHIR_INIT_VAR(&_5$$7);
		ZEPHIR_CONCAT_SV(&_5$$7, "-", &tag);
		ZEPHIR_CPY_WRT(&tag, &_5$$7);
	}
	ZEPHIR_INIT_VAR(&extension);
	ZVAL_STRING(&extension, ".log");
	if (ZEPHIR_IS_STRING(&type, "error")) {
		ZEPHIR_INIT_NVAR(&extension);
		ZVAL_STRING(&extension, ".wf.log");
	}
	zephir_read_static_property_ce(&_6, phpple_log_logger_ce, SL("dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "%s%s%s%s%s");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "/");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 14, &_7, &_6, &_8, &name, &tag, &extension);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phpple_Log_Logger, log) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval message;
	zval *level, level_sub, *message_param = NULL, *context_param = NULL, _0, _1, _2, secs, _3, usec, sec, msg, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&secs);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&usec);
	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_read_static_property_ce(&_0, phpple_log_logger_ce, SL("logLevels"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, level, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 145);
	zephir_read_static_property_ce(&_2, phpple_log_logger_ce, SL("minLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LT(&_1, &_2)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_microtime(&_3, NULL);
	ZEPHIR_INIT_VAR(&secs);
	zephir_fast_explode_str(&secs, SL(" "), &_3, LONG_MAX);
	ZEPHIR_OBS_VAR(&usec);
	zephir_array_fetch_long(&usec, &secs, 0, PH_NOISY, "phpple/Log/Logger.zep", 150);
	ZEPHIR_OBS_VAR(&sec);
	zephir_array_fetch_long(&sec, &secs, 1, PH_NOISY, "phpple/Log/Logger.zep", 151);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_5, "date", NULL, 26, &_4, &sec);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	zephir_fast_strtoupper(&_4, level);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	zephir_read_static_property_ce(&_8, phpple_log_logger_ce, SL("basic"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_8)) {
		zephir_read_static_property_ce(&_9, phpple_log_logger_ce, SL("basic"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_7, "http_build_query", NULL, 23, &_9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_LONG(&_11, 256);
	zephir_json_encode(&_10, &context, zephir_get_intval(&_11) );
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "[%s.%06d] %s [name=%s] [%s] %s %s\n");
	ZVAL_LONG(&_13, (zephir_get_numberval(&usec) * 1000000));
	ZEPHIR_CALL_FUNCTION(&msg, "sprintf", NULL, 14, &_12, &_5, &_13, &_4, &_6, &_7, &message, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&type, "getlogtype", &_14, 58, level);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputlog", NULL, 59, &type, &msg);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the writer
 * @return resource
 */
PHP_METHOD(Phpple_Log_Logger, getWriter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, _0, _1, _4, _5, _6, _7, _8, _9, _2$$3, _3$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 172);
	if (Z_TYPE_P(&_1) != IS_NULL) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 173);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 175);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "a+");
	ZEPHIR_CALL_FUNCTION(&_7, "fopen", NULL, 60, &_5, &_6);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("fhs"), &type, &_7);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_9, &_8, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 176);
	RETURN_CTOR(&_9);

}

/**
 * Output log
 */
PHP_METHOD(Phpple_Log_Logger, outputLog) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *msg, msg_sub, _0, _1, _2, _3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&msg_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &msg);

	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("buffers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 184);
	ZEPHIR_MAKE_REF(&_1);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 12, &_1, msg);
	ZEPHIR_UNREF(&_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("buffers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 185);
	if (zephir_fast_count_int(&_3) == 50) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flushlogs", NULL, 61, &type);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get log type
 */
PHP_METHOD(Phpple_Log_Logger, getLogType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *level_param = NULL, _0, _1, _2;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_static_property_ce(&_0, phpple_log_logger_ce, SL("logLevels"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &level, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 195);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "error");
	if (zephir_get_intval(&_1) < zephir_get_intval(&_2)) {
		RETURN_MM_STRING("error");
	}
	RETURN_MM_STRING("normal");

}

/**
 * Refresh log to file
 */
PHP_METHOD(Phpple_Log_Logger, flushLogs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, writer, _3, _0$$3, _1$$3, _2$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&writer);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	ZEPHIR_CALL_METHOD(&writer, this_ptr, "getwriter", NULL, 62, &type);
	zephir_check_call_status();
	if (zephir_is_true(&writer)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("buffers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 208);
		zephir_fast_join_str(&_0$$3, SL(""), &_2$$3);
		zephir_fwrite(NULL, &writer, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_array(this_ptr, SL("buffers"), &type, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Destruct of Logger
 */
PHP_METHOD(Phpple_Log_Logger, __destruct) {

	zend_string *_5, *_12;
	zend_ulong _4, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, type, _0, _1, *_2, _3, _7, _8, *_9, _10, _13$$5, _14$$5, _15$$5, _16$$5, _17$$7, _18$$7, _19$$7, _20$$7;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("buffers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&_0, 0, "phpple/Log/Logger.zep", 222);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&type, _5);
			} else {
				ZVAL_LONG(&type, _4);
			}
			ZEPHIR_INIT_NVAR(&_1);
			ZVAL_COPY(&_1, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "flushlogs", &_6, 61, &type);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&type, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "flushlogs", &_6, 61, &type);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&type);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	zephir_is_iterable(&_7, 0, "phpple/Log/Logger.zep", 229);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_7), _11, _12, _9)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&type, _12);
			} else {
				ZVAL_LONG(&type, _11);
			}
			ZEPHIR_INIT_NVAR(&_8);
			ZVAL_COPY(&_8, _9);
			zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_14$$5, &_13$$5, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 223);
			if (!(zephir_is_true(&_14$$5))) {
				continue;
			}
			zephir_read_property(&_15$$5, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_16$$5, &_15$$5, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 226);
			zephir_fclose(&_16$$5);
			zephir_update_property_array(this_ptr, SL("fhs"), &type, &__$null);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_7, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &_7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&type, &_7, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8, &_7, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_17$$7, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_18$$7, &_17$$7, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 223);
				if (!(zephir_is_true(&_18$$7))) {
					continue;
				}
				zephir_read_property(&_19$$7, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_20$$7, &_19$$7, &type, PH_NOISY | PH_READONLY, "phpple/Log/Logger.zep", 226);
				zephir_fclose(&_20$$7);
				zephir_update_property_array(this_ptr, SL("fhs"), &type, &__$null);
			ZEPHIR_CALL_METHOD(NULL, &_7, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_MM_RESTORE();

}

/**
 * System is unusable.
 *
 * @param string message
 * @param array  context
 *
 * @return void
 */
PHP_METHOD(Phpple_Log_Logger, emergency) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "emergency");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phpple_Log_Logger, alert) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alert");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phpple_Log_Logger, critical) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "critical");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phpple_Log_Logger, error) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phpple_Log_Logger, warning) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Normal but significant events.
 *
 * @param string message
 * @param array  context
 *
 * @return void
 */
PHP_METHOD(Phpple_Log_Logger, notice) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phpple_Log_Logger, info) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Detailed debug information.
 *
 * @param string message
 * @param array  context
 *
 * @return void
 */
PHP_METHOD(Phpple_Log_Logger, debug) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "debug");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Phpple_Log_Logger(TSRMLS_D) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 8, 0);
	add_assoc_long_ex(&_0, SL("emergency"), 0x08);
	add_assoc_long_ex(&_0, SL("alert"), 0x07);
	add_assoc_long_ex(&_0, SL("critical"), 0x06);
	add_assoc_long_ex(&_0, SL("error"), 0x05);
	add_assoc_long_ex(&_0, SL("warning"), 0x04);
	add_assoc_long_ex(&_0, SL("notice"), 0x03);
	add_assoc_long_ex(&_0, SL("info"), 0x02);
	add_assoc_long_ex(&_0, SL("debug"), 0x01);
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("logLevels"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("basic"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_static_property_ce(phpple_log_logger_ce, ZEND_STRL("loggers"), &_2);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phpple_Log_Logger(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("buffers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("buffers"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("fhs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("fhs"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("paths"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

