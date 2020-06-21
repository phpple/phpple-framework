
extern zend_class_entry *phpple_application_ce;

ZEPHIR_INIT_CLASS(Phpple_Application);

PHP_METHOD(Phpple_Application, setLogger);
PHP_METHOD(Phpple_Application, getLogger);
PHP_METHOD(Phpple_Application, getAppId);
PHP_METHOD(Phpple_Application, getTimer);
PHP_METHOD(Phpple_Application, getEncoding);
PHP_METHOD(Phpple_Application, getEndStatus);
PHP_METHOD(Phpple_Application, getDebug);
PHP_METHOD(Phpple_Application, getResponse);
PHP_METHOD(Phpple_Application, getRequest);
PHP_METHOD(Phpple_Application, getBaseUrl);
PHP_METHOD(Phpple_Application, __construct);
PHP_METHOD(Phpple_Application, setRequest);
PHP_METHOD(Phpple_Application, run);
PHP_METHOD(Phpple_Application, init);
PHP_METHOD(Phpple_Application, process);
PHP_METHOD(Phpple_Application, initLogger);
PHP_METHOD(Phpple_Application, initEnv);
PHP_METHOD(Phpple_Application, genAppId);
PHP_METHOD(Phpple_Application, shutdownHandler);
PHP_METHOD(Phpple_Application, exceptionHandler);
PHP_METHOD(Phpple_Application, errorHandler);
PHP_METHOD(Phpple_Application, getDir);
PHP_METHOD(Phpple_Application, getNamespace);
void zephir_init_static_properties_Phpple_Application(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_application_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getappid, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getappid, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getencoding, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getencoding, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getendstatus, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getendstatus, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_application___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dir)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ns, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, ns)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_application_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phpple\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_application_exceptionhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, ex)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getdir, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getdir, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getnamespace, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_application_getnamespace, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_application_method_entry) {
	PHP_ME(Phpple_Application, setLogger, arginfo_phpple_application_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getAppId, arginfo_phpple_application_getappid, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getTimer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getEncoding, arginfo_phpple_application_getencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getEndStatus, arginfo_phpple_application_getendstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getBaseUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, __construct, arginfo_phpple_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Application, setRequest, arginfo_phpple_application_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, init, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Application, process, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Application, initLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, initEnv, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Application, genAppId, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Application, shutdownHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, exceptionHandler, arginfo_phpple_application_exceptionhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, errorHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getDir, arginfo_phpple_application_getdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Application, getNamespace, arginfo_phpple_application_getnamespace, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
