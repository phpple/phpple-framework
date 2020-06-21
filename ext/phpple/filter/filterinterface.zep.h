
extern zend_class_entry *phpple_filter_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phpple_Filter_FilterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_filterinterface_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_filterinterface_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_filter_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phpple_Filter_FilterInterface, execute, arginfo_phpple_filter_filterinterface_execute)
	PHP_FE_END
};
