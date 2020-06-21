
extern zend_class_entry *phpple_http_application_ce;

ZEPHIR_INIT_CLASS(Phpple_Http_Application);

PHP_METHOD(Phpple_Http_Application, init);
PHP_METHOD(Phpple_Http_Application, process);
PHP_METHOD(Phpple_Http_Application, initFilters);
PHP_METHOD(Phpple_Http_Application, getFilter);
PHP_METHOD(Phpple_Http_Application, execFilter);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_application_getfilter, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_application_getfilter, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cover, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, cover)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_application_execfilter, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_http_application_execfilter, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filterName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filterName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_http_application_method_entry) {
	PHP_ME(Phpple_Http_Application, init, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Http_Application, process, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phpple_Http_Application, initFilters, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Http_Application, getFilter, arginfo_phpple_http_application_getfilter, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Http_Application, execFilter, arginfo_phpple_http_application_execfilter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
