
extern zend_class_entry *phpple_util_xml_ce;

ZEPHIR_INIT_CLASS(Phpple_Util_Xml);

PHP_METHOD(Phpple_Util_Xml, innerArray2Xml);
PHP_METHOD(Phpple_Util_Xml, array2Xml);
void zephir_init_static_properties_Phpple_Util_Xml(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_util_xml_innerarray2xml, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_util_xml_array2xml, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_util_xml_method_entry) {
	PHP_ME(Phpple_Util_Xml, innerArray2Xml, arginfo_phpple_util_xml_innerarray2xml, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Util_Xml, array2Xml, arginfo_phpple_util_xml_array2xml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
