
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
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phpple_Filter_OutputFilter) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Filter, OutputFilter, phpple, filter_outputfilter, phpple_filter_outputfilter_method_entry, 0);

	zend_declare_property_null(phpple_filter_outputfilter_ce, SL("logger"), ZEND_ACC_PRIVATE);

	zend_class_implements(phpple_filter_outputfilter_ce, 1, phpple_filter_filterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Filter_OutputFilter, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Filter_OutputFilter, getLogger) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logger");

}

/**
 * @inheritDoc
 */
PHP_METHOD(Phpple_Filter_OutputFilter, execute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(&_0, app, "getresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

