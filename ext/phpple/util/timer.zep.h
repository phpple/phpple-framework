
extern zend_class_entry *phpple_util_timer_ce;

ZEPHIR_INIT_CLASS(Phpple_Util_Timer);

PHP_METHOD(Phpple_Util_Timer, __construct);
PHP_METHOD(Phpple_Util_Timer, begin);
PHP_METHOD(Phpple_Util_Timer, end);
PHP_METHOD(Phpple_Util_Timer, endAll);
PHP_METHOD(Phpple_Util_Timer, getResult);
zend_object *zephir_init_properties_Phpple_Util_Timer(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_begin, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_begin, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_end, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_end, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_endall, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_endall, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_getresult, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_util_timer_getresult, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, end, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, end)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_util_timer_method_entry) {
	PHP_ME(Phpple_Util_Timer, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Util_Timer, begin, arginfo_phpple_util_timer_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Util_Timer, end, arginfo_phpple_util_timer_end, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Util_Timer, endAll, arginfo_phpple_util_timer_endall, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Util_Timer, getResult, arginfo_phpple_util_timer_getresult, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
