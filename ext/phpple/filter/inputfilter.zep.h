
extern zend_class_entry *phpple_filter_inputfilter_ce;

ZEPHIR_INIT_CLASS(Phpple_Filter_InputFilter);

PHP_METHOD(Phpple_Filter_InputFilter, setLogger);
PHP_METHOD(Phpple_Filter_InputFilter, getLogger);
PHP_METHOD(Phpple_Filter_InputFilter, execute);
PHP_METHOD(Phpple_Filter_InputFilter, parseCommon);
PHP_METHOD(Phpple_Filter_InputFilter, parseInternalVar);
PHP_METHOD(Phpple_Filter_InputFilter, parseParams);
PHP_METHOD(Phpple_Filter_InputFilter, logRequest);
void zephir_init_static_properties_Phpple_Filter_InputFilter(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_inputfilter_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_inputfilter_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_inputfilter_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_inputfilter_parsecommon, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_inputfilter_parseinternalvar, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_inputfilter_parseparams, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_inputfilter_logrequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, requestFile, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, requestFile)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_filter_inputfilter_method_entry) {
	PHP_ME(Phpple_Filter_InputFilter, setLogger, arginfo_phpple_filter_inputfilter_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_InputFilter, getLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_InputFilter, execute, arginfo_phpple_filter_inputfilter_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_InputFilter, parseCommon, arginfo_phpple_filter_inputfilter_parsecommon, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Filter_InputFilter, parseInternalVar, arginfo_phpple_filter_inputfilter_parseinternalvar, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Filter_InputFilter, parseParams, arginfo_phpple_filter_inputfilter_parseparams, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Filter_InputFilter, logRequest, arginfo_phpple_filter_inputfilter_logrequest, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
