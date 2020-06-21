
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phpple_Filter_CleanFilter) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Filter, CleanFilter, phpple, filter_cleanfilter, phpple_filter_cleanfilter_method_entry, 0);

	zend_declare_property_null(phpple_filter_cleanfilter_ce, SL("logger"), ZEND_ACC_PRIVATE);

	zend_class_implements(phpple_filter_cleanfilter_ce, 1, phpple_filter_filterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Filter_CleanFilter, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Filter_CleanFilter, getLogger) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logger");

}

PHP_METHOD(Phpple_Filter_CleanFilter, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @inheritDoc
 */
PHP_METHOD(Phpple_Filter_CleanFilter, execute) {

	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &app);



	RETURN_BOOL(1);

}

