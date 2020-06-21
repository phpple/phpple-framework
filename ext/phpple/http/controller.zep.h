
extern zend_class_entry *phpple_http_controller_ce;

ZEPHIR_INIT_CLASS(Phpple_Http_Controller);

PHP_METHOD(Phpple_Http_Controller, setLogger);
PHP_METHOD(Phpple_Http_Controller, setAppId);
PHP_METHOD(Phpple_Http_Controller, setDebug);
PHP_METHOD(Phpple_Http_Controller, setMethod);
PHP_METHOD(Phpple_Http_Controller, setArgs);
PHP_METHOD(Phpple_Http_Controller, setPath);
PHP_METHOD(Phpple_Http_Controller, setRequest);
PHP_METHOD(Phpple_Http_Controller, setResponse);
PHP_METHOD(Phpple_Http_Controller, _before);
PHP_METHOD(Phpple_Http_Controller, _after);
PHP_METHOD(Phpple_Http_Controller, gets);
PHP_METHOD(Phpple_Http_Controller, get);
PHP_METHOD(Phpple_Http_Controller, set);
PHP_METHOD(Phpple_Http_Controller, sets);
PHP_METHOD(Phpple_Http_Controller, getData);
PHP_METHOD(Phpple_Http_Controller, setData);
PHP_METHOD(Phpple_Http_Controller, setDatas);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setappid, 0, 0, 1)
	ZEND_ARG_INFO(0, appId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setdebug, 0, 0, 1)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setargs, 0, 0, 1)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_setresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_gets, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_gets, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_controller_set, 0, 1, Phpple\\Http\\Controller, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_set, 0, 1, IS_OBJECT, "Phpple\\Http\\Controller", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_controller_sets, 0, 1, Phpple\\Http\\Controller, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_sets, 0, 1, IS_OBJECT, "Phpple\\Http\\Controller", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_controller_getdata, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_controller_setdata, 0, 2, Phpple\\Http\\Controller, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_setdata, 0, 2, IS_OBJECT, "Phpple\\Http\\Controller", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_controller_setdatas, 0, 1, Phpple\\Http\\Controller, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_controller_setdatas, 0, 1, IS_OBJECT, "Phpple\\Http\\Controller", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_http_controller_method_entry) {
	PHP_ME(Phpple_Http_Controller, setLogger, arginfo_phpple_http_controller_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setAppId, arginfo_phpple_http_controller_setappid, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setDebug, arginfo_phpple_http_controller_setdebug, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setMethod, arginfo_phpple_http_controller_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setArgs, arginfo_phpple_http_controller_setargs, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setPath, arginfo_phpple_http_controller_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setRequest, arginfo_phpple_http_controller_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setResponse, arginfo_phpple_http_controller_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, _before, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, _after, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, gets, arginfo_phpple_http_controller_gets, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, get, arginfo_phpple_http_controller_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, set, arginfo_phpple_http_controller_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, sets, arginfo_phpple_http_controller_sets, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, getData, arginfo_phpple_http_controller_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setData, arginfo_phpple_http_controller_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Controller, setDatas, arginfo_phpple_http_controller_setdatas, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
