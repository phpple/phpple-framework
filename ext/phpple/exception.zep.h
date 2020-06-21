
extern zend_class_entry *phpple_exception_ce;

ZEPHIR_INIT_CLASS(Phpple_Exception);

PHP_METHOD(Phpple_Exception, setParams);
PHP_METHOD(Phpple_Exception, withParams);
PHP_METHOD(Phpple_Exception, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_exception_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phpple_exception_withparams, 0, 2, Phpple\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_exception_withparams, 0, 2, IS_OBJECT, "Phpple\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, msg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, msg)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_exception_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_exception_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_exception_method_entry) {
	PHP_ME(Phpple_Exception, setParams, arginfo_phpple_exception_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Exception, withParams, arginfo_phpple_exception_withparams, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Exception, getParams, arginfo_phpple_exception_getparams, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
