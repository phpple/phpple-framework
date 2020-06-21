
extern zend_class_entry *phpple_filter_executor_ce;

ZEPHIR_INIT_CLASS(Phpple_Filter_Executor);

PHP_METHOD(Phpple_Filter_Executor, __construct);
PHP_METHOD(Phpple_Filter_Executor, loadFilters);
PHP_METHOD(Phpple_Filter_Executor, execute);
zend_object *zephir_init_properties_Phpple_Filter_Executor(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_executor___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_executor_loadfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_executor_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_executor_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filterName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filterName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_filter_executor_method_entry) {
	PHP_ME(Phpple_Filter_Executor, __construct, arginfo_phpple_filter_executor___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Filter_Executor, loadFilters, arginfo_phpple_filter_executor_loadfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_Executor, execute, arginfo_phpple_filter_executor_execute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
