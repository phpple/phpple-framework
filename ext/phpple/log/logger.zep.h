
extern zend_class_entry *phpple_log_logger_ce;

ZEPHIR_INIT_CLASS(Phpple_Log_Logger);

PHP_METHOD(Phpple_Log_Logger, __construct);
PHP_METHOD(Phpple_Log_Logger, init);
PHP_METHOD(Phpple_Log_Logger, getLogger);
PHP_METHOD(Phpple_Log_Logger, addBasic);
PHP_METHOD(Phpple_Log_Logger, getPathByMode);
PHP_METHOD(Phpple_Log_Logger, log);
PHP_METHOD(Phpple_Log_Logger, getWriter);
PHP_METHOD(Phpple_Log_Logger, outputLog);
PHP_METHOD(Phpple_Log_Logger, getLogType);
PHP_METHOD(Phpple_Log_Logger, flushLogs);
PHP_METHOD(Phpple_Log_Logger, __destruct);
PHP_METHOD(Phpple_Log_Logger, emergency);
PHP_METHOD(Phpple_Log_Logger, alert);
PHP_METHOD(Phpple_Log_Logger, critical);
PHP_METHOD(Phpple_Log_Logger, error);
PHP_METHOD(Phpple_Log_Logger, warning);
PHP_METHOD(Phpple_Log_Logger, notice);
PHP_METHOD(Phpple_Log_Logger, info);
PHP_METHOD(Phpple_Log_Logger, debug);
void zephir_init_static_properties_Phpple_Log_Logger(TSRMLS_D);
zend_object *zephir_init_properties_Phpple_Log_Logger(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_init, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dir)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_log_logger_getlogger, 0, 0, Phpple\\Log\\LoggerInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_log_logger_getlogger, 0, 0, IS_OBJECT, "Phpple\\Log\\LoggerInterface", 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_addbasic, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, basic, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_log_logger_getpathbymode, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_log_logger_getpathbymode, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_getwriter, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_outputlog, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_getlogtype, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_flushlogs, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_emergency, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_alert, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_critical, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_error, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_warning, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_notice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_info, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_log_logger_debug, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_log_logger_method_entry) {
	PHP_ME(Phpple_Log_Logger, __construct, arginfo_phpple_log_logger___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Log_Logger, init, arginfo_phpple_log_logger_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Log_Logger, getLogger, arginfo_phpple_log_logger_getlogger, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Log_Logger, addBasic, arginfo_phpple_log_logger_addbasic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Log_Logger, getPathByMode, arginfo_phpple_log_logger_getpathbymode, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Log_Logger, log, arginfo_phpple_log_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, getWriter, arginfo_phpple_log_logger_getwriter, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Log_Logger, outputLog, arginfo_phpple_log_logger_outputlog, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Log_Logger, getLogType, arginfo_phpple_log_logger_getlogtype, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Log_Logger, flushLogs, arginfo_phpple_log_logger_flushlogs, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Log_Logger, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phpple_Log_Logger, emergency, arginfo_phpple_log_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, alert, arginfo_phpple_log_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, critical, arginfo_phpple_log_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, error, arginfo_phpple_log_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, warning, arginfo_phpple_log_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, notice, arginfo_phpple_log_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, info, arginfo_phpple_log_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Log_Logger, debug, arginfo_phpple_log_logger_debug, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
