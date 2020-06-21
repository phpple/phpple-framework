
extern zend_class_entry *phpple_http_request_ce;

ZEPHIR_INIT_CLASS(Phpple_Http_Request);

PHP_METHOD(Phpple_Http_Request, getUrl);
PHP_METHOD(Phpple_Http_Request, setUrl);
PHP_METHOD(Phpple_Http_Request, getUri);
PHP_METHOD(Phpple_Http_Request, setUri);
PHP_METHOD(Phpple_Http_Request, setRawUri);
PHP_METHOD(Phpple_Http_Request, getRawUri);
PHP_METHOD(Phpple_Http_Request, getPrefix);
PHP_METHOD(Phpple_Http_Request, setPrefix);
PHP_METHOD(Phpple_Http_Request, getMethod);
PHP_METHOD(Phpple_Http_Request, setMethod);
PHP_METHOD(Phpple_Http_Request, setServerEnvs);
PHP_METHOD(Phpple_Http_Request, getServerEnvs);
PHP_METHOD(Phpple_Http_Request, setInputs);
PHP_METHOD(Phpple_Http_Request, getInputs);
PHP_METHOD(Phpple_Http_Request, setDatas);
PHP_METHOD(Phpple_Http_Request, getDatas);
PHP_METHOD(Phpple_Http_Request, setLogger);
PHP_METHOD(Phpple_Http_Request, setNow);
PHP_METHOD(Phpple_Http_Request, getNow);
PHP_METHOD(Phpple_Http_Request, setSchema);
PHP_METHOD(Phpple_Http_Request, getSchema);
PHP_METHOD(Phpple_Http_Request, setHost);
PHP_METHOD(Phpple_Http_Request, getHost);
PHP_METHOD(Phpple_Http_Request, setUserIp);
PHP_METHOD(Phpple_Http_Request, getUserIp);
PHP_METHOD(Phpple_Http_Request, setClientIp);
PHP_METHOD(Phpple_Http_Request, getClientIp);
PHP_METHOD(Phpple_Http_Request, setCookies);
PHP_METHOD(Phpple_Http_Request, getCookies);
PHP_METHOD(Phpple_Http_Request, setIsAjax);
PHP_METHOD(Phpple_Http_Request, getIsAjax);
PHP_METHOD(Phpple_Http_Request, setPretty);
PHP_METHOD(Phpple_Http_Request, getPretty);
PHP_METHOD(Phpple_Http_Request, setInputFormat);
PHP_METHOD(Phpple_Http_Request, getInputFormat);
PHP_METHOD(Phpple_Http_Request, setOutputFormat);
PHP_METHOD(Phpple_Http_Request, getOutputFormat);
PHP_METHOD(Phpple_Http_Request, __construct);
PHP_METHOD(Phpple_Http_Request, has);
PHP_METHOD(Phpple_Http_Request, reset);
PHP_METHOD(Phpple_Http_Request, get);
PHP_METHOD(Phpple_Http_Request, gets);
PHP_METHOD(Phpple_Http_Request, setData);
PHP_METHOD(Phpple_Http_Request, getData);
PHP_METHOD(Phpple_Http_Request, getCookie);
PHP_METHOD(Phpple_Http_Request, getHeader);
PHP_METHOD(Phpple_Http_Request, getFile);
zend_object *zephir_init_properties_Phpple_Http_Request(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setrawuri, 0, 0, 1)
	ZEND_ARG_INFO(0, rawUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setserverenvs, 0, 0, 1)
	ZEND_ARG_INFO(0, serverEnvs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setinputs, 0, 0, 1)
	ZEND_ARG_INFO(0, inputs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setdatas, 0, 0, 1)
	ZEND_ARG_INFO(0, datas)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setnow, 0, 0, 1)
	ZEND_ARG_INFO(0, now)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setschema, 0, 0, 1)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setuserip, 0, 0, 1)
	ZEND_ARG_INFO(0, userIp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setclientip, 0, 0, 1)
	ZEND_ARG_INFO(0, clientIp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setcookies, 0, 0, 1)
	ZEND_ARG_INFO(0, cookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setisajax, 0, 0, 1)
	ZEND_ARG_INFO(0, isAjax)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setpretty, 0, 0, 1)
	ZEND_ARG_INFO(0, pretty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setinputformat, 0, 0, 1)
	ZEND_ARG_INFO(0, inputFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_setoutputformat, 0, 0, 1)
	ZEND_ARG_INFO(0, outputFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_request_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_request_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_request_gets, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_request_gets, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_http_request_setdata, 0, 2, Phpple\\Http\\Request, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_request_setdata, 0, 2, IS_OBJECT, "Phpple\\Http\\Request", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_getdata, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_getcookie, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_getheader, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_http_request_getfile, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_http_request_method_entry) {
	PHP_ME(Phpple_Http_Request, getUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setUrl, arginfo_phpple_http_request_seturl, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setUri, arginfo_phpple_http_request_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setRawUri, arginfo_phpple_http_request_setrawuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getRawUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setPrefix, arginfo_phpple_http_request_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setMethod, arginfo_phpple_http_request_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setServerEnvs, arginfo_phpple_http_request_setserverenvs, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getServerEnvs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setInputs, arginfo_phpple_http_request_setinputs, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getInputs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setDatas, arginfo_phpple_http_request_setdatas, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getDatas, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setLogger, arginfo_phpple_http_request_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setNow, arginfo_phpple_http_request_setnow, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getNow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setSchema, arginfo_phpple_http_request_setschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setHost, arginfo_phpple_http_request_sethost, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setUserIp, arginfo_phpple_http_request_setuserip, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getUserIp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setClientIp, arginfo_phpple_http_request_setclientip, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getClientIp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setCookies, arginfo_phpple_http_request_setcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setIsAjax, arginfo_phpple_http_request_setisajax, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getIsAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setPretty, arginfo_phpple_http_request_setpretty, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getPretty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setInputFormat, arginfo_phpple_http_request_setinputformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getInputFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setOutputFormat, arginfo_phpple_http_request_setoutputformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getOutputFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, __construct, arginfo_phpple_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Http_Request, has, arginfo_phpple_http_request_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, get, arginfo_phpple_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, gets, arginfo_phpple_http_request_gets, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, setData, arginfo_phpple_http_request_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getData, arginfo_phpple_http_request_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getCookie, arginfo_phpple_http_request_getcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getHeader, arginfo_phpple_http_request_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Http_Request, getFile, arginfo_phpple_http_request_getfile, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
