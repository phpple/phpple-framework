
extern zend_class_entry *phpple_http_response_ce;

ZEPHIR_INIT_CLASS(Phpple_Http_Response);

PHP_METHOD(Phpple_Http_Response, setLogger);
PHP_METHOD(Phpple_Http_Response, __construct);
PHP_METHOD(Phpple_Http_Response, reset);
PHP_METHOD(Phpple_Http_Response, setException);
PHP_METHOD(Phpple_Http_Response, set);
PHP_METHOD(Phpple_Http_Response, sets);
PHP_METHOD(Phpple_Http_Response, rmset);
PHP_METHOD(Phpple_Http_Response, setCallback);
PHP_METHOD(Phpple_Http_Response, setHeader);
PHP_METHOD(Phpple_Http_Response, setCookie);
PHP_METHOD(Phpple_Http_Response, setRaw);
PHP_METHOD(Phpple_Http_Response, redirect);
PHP_METHOD(Phpple_Http_Response, setFrHeader);
PHP_METHOD(Phpple_Http_Response, setNoCache);
PHP_METHOD(Phpple_Http_Response, setFrVar);
PHP_METHOD(Phpple_Http_Response, sendHeaders);
PHP_METHOD(Phpple_Http_Response, end);
PHP_METHOD(Phpple_Http_Response, runTasks);
PHP_METHOD(Phpple_Http_Response, buildContentType);
PHP_METHOD(Phpple_Http_Response, getResult);
PHP_METHOD(Phpple_Http_Response, formatResponse);
PHP_METHOD(Phpple_Http_Response, send);
PHP_METHOD(Phpple_Http_Response, addTask);
zend_object *zephir_init_properties_Phpple_Http_Response(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_response_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_response___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setexception, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setexception, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, ex, Throwable, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_set, 0, 2, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_set, 0, 2, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_sets, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_sets, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_rmset, 0, 0, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_rmset, 0, 0, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setcallback, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setcallback, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, funcName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, funcName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setheader, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setheader, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setcookie, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setcookie, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expires, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, expires)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, domain)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httponly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, httponly)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, secure)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setraw, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setraw, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rawData, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, rawData)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_response_redirect, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, permanent, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, permanent)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setfrheader, 0, 0, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setfrheader, 0, 0, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, errCode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, errCode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setnocache, 0, 0, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setnocache, 0, 0, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_setfrvar, 0, 2, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_setfrvar, 0, 2, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_sendheaders, 0, 0, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_sendheaders, 0, 0, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_response_buildcontenttype, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, of, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, of)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_getresult, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_getresult, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_response_addtask, 0, 1, Phpple\\Http\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_response_addtask, 0, 1, IS_OBJECT, "Phpple\\Http\\Response", 0)
#endif
	ZEND_ARG_INFO(0, task)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_http_response_method_entry) {
	PHP_ME(Phpple_Http_Response, setLogger, arginfo_phpple_http_response_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, __construct, arginfo_phpple_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Http_Response, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setException, arginfo_phpple_http_response_setexception, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, set, arginfo_phpple_http_response_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, sets, arginfo_phpple_http_response_sets, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, rmset, arginfo_phpple_http_response_rmset, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setCallback, arginfo_phpple_http_response_setcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setHeader, arginfo_phpple_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setCookie, arginfo_phpple_http_response_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setRaw, arginfo_phpple_http_response_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, redirect, arginfo_phpple_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setFrHeader, arginfo_phpple_http_response_setfrheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setNoCache, arginfo_phpple_http_response_setnocache, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, setFrVar, arginfo_phpple_http_response_setfrvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, sendHeaders, arginfo_phpple_http_response_sendheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, end, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, runTasks, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Http_Response, buildContentType, arginfo_phpple_http_response_buildcontenttype, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Http_Response, getResult, arginfo_phpple_http_response_getresult, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Http_Response, formatResponse, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Response, addTask, arginfo_phpple_http_response_addtask, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
