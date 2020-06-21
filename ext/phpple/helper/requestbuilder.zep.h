
extern zend_class_entry *phpple_helper_requestbuilder_ce;

ZEPHIR_INIT_CLASS(Phpple_Helper_RequestBuilder);

PHP_METHOD(Phpple_Helper_RequestBuilder, buildGetRequest);
PHP_METHOD(Phpple_Helper_RequestBuilder, buildPostRequest);
PHP_METHOD(Phpple_Helper_RequestBuilder, buildHeaders);
void zephir_init_static_properties_Phpple_Helper_RequestBuilder(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_helper_requestbuilder_buildgetrequest, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_helper_requestbuilder_buildpostrequest, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_helper_requestbuilder_buildheaders, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_helper_requestbuilder_buildheaders, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_helper_requestbuilder_method_entry) {
	PHP_ME(Phpple_Helper_RequestBuilder, buildGetRequest, arginfo_phpple_helper_requestbuilder_buildgetrequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Helper_RequestBuilder, buildPostRequest, arginfo_phpple_helper_requestbuilder_buildpostrequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Helper_RequestBuilder, buildHeaders, arginfo_phpple_helper_requestbuilder_buildheaders, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
