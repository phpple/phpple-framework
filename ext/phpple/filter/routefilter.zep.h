
extern zend_class_entry *phpple_filter_routefilter_ce;

ZEPHIR_INIT_CLASS(Phpple_Filter_RouteFilter);

PHP_METHOD(Phpple_Filter_RouteFilter, setLogger);
PHP_METHOD(Phpple_Filter_RouteFilter, getLogger);
PHP_METHOD(Phpple_Filter_RouteFilter, __construct);
PHP_METHOD(Phpple_Filter_RouteFilter, execute);
PHP_METHOD(Phpple_Filter_RouteFilter, getCtlAndFunc);
PHP_METHOD(Phpple_Filter_RouteFilter, buildMethod);
zend_object *zephir_init_properties_Phpple_Filter_RouteFilter(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_routefilter_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_routefilter_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_routefilter_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_routefilter_getctlandfunc, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_filter_routefilter_getctlandfunc, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_filter_routefilter_buildmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, controller, Phpple\\Filter\\Controller, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_OBJ_INFO(0, app, Phpple\\Application, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_filter_routefilter_method_entry) {
	PHP_ME(Phpple_Filter_RouteFilter, setLogger, arginfo_phpple_filter_routefilter_setlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_RouteFilter, getLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_RouteFilter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phpple_Filter_RouteFilter, execute, arginfo_phpple_filter_routefilter_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phpple_Filter_RouteFilter, getCtlAndFunc, arginfo_phpple_filter_routefilter_getctlandfunc, ZEND_ACC_PRIVATE)
	PHP_ME(Phpple_Filter_RouteFilter, buildMethod, arginfo_phpple_filter_routefilter_buildmethod, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
