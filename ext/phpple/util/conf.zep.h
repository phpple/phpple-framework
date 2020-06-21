
extern zend_class_entry *phpple_util_conf_ce;

ZEPHIR_INIT_CLASS(Phpple_Util_Conf);

PHP_METHOD(Phpple_Util_Conf, load);
PHP_METHOD(Phpple_Util_Conf, get);
PHP_METHOD(Phpple_Util_Conf, set);
PHP_METHOD(Phpple_Util_Conf, has);
PHP_METHOD(Phpple_Util_Conf, clear);
void zephir_init_static_properties_Phpple_Util_Conf(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_util_conf_load, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_util_conf_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_util_conf_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_conf_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_conf_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_util_conf_method_entry) {
	PHP_ME(Phpple_Util_Conf, load, arginfo_phpple_util_conf_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Util_Conf, get, arginfo_phpple_util_conf_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Util_Conf, set, arginfo_phpple_util_conf_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Util_Conf, has, arginfo_phpple_util_conf_has, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Util_Conf, clear, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
