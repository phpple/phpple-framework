
extern zend_class_entry *phpple_filter_cleanfilter_ce;

ZEPHIR_INIT_CLASS(Phpple_Filter_CleanFilter);

PHP_METHOD(Phpple_Filter_CleanFilter, setLogger);
PHP_METHOD(Phpple_Filter_CleanFilter, getLogger);
PHP_METHOD(Phpple_Filter_CleanFilter, __construct);
PHP_METHOD(Phpple_Filter_CleanFilter, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_cleanfilter_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_cleanfilter_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_cleanfilter_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_filter_cleanfilter_method_entry) {
	PHP_ME(Phpple_Filter_CleanFilter, setLogger, arginfo_phpple_filter_cleanfilter_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_CleanFilter, getLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_CleanFilter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Filter_CleanFilter, execute, arginfo_phpple_filter_cleanfilter_execute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
