
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phpple_Http_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phpple\\Http, Application, phpple, http_application, phpple_application_ce, phpple_http_application_method_entry, 0);

	/**
	 * @var Executor
	 */
	zend_declare_property_null(phpple_http_application_ce, SL("filterExecutor"), ZEND_ACC_PRIVATE);

	/**
	 * baseUrl
	 * @var string
	 */
	zend_declare_property_null(phpple_http_application_ce, SL("baseUrl"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Phpple_Http_Application, init) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phpple_http_request_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 40, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phpple_http_response_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 41, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initenv", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initlogger", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setlogger", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setlogger", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phpple_filter_executor_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 42, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("filterExecutor"), &_6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initfilters", NULL, 43);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritDoc
 */
PHP_METHOD(Phpple_Http_Application, process) {

	zval _0;
	zval filter, _1, *_2, _3, _4$$3, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "init");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "input");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "route");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "output");
	zephir_array_fast_append(&_0, &_1);
	zephir_is_iterable(&_0, 0, "phpple/Http/Application.zep", 51);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
		{
			ZEPHIR_INIT_NVAR(&filter);
			ZVAL_COPY(&filter, _2);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "execfilter", &_5, 0, &filter);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&filter, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "execfilter", &_5, 0, &filter);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$5)) {
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&filter);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initialize filters
 */
PHP_METHOD(Phpple_Http_Application, initFilters) {

	zval _6, _10, _14;
	zval _1, _5, _9, _13, _16;
	zval filters, _0, _2, _4, _7, _8, _11, _12, _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&filters);
	array_init(&filters);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SS(&_1, "phpple.filter.", "init");
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getfilter", &_3, 44, &_1, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&filters, SL("init"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SS(&_5, "phpple.filter.", "input");
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "\\Phpple\\Filter\\InputFilter");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getfilter", &_3, 44, &_5, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&filters, SL("input"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SS(&_9, "phpple.filter.", "route");
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 1, 0);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "\\Phpple\\Filter\\RouteFilter");
	zephir_array_fast_append(&_10, &_7);
	ZVAL_BOOL(&_11, 1);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getfilter", &_3, 44, &_9, &_10, &_11);
	zephir_check_call_status();
	zephir_array_update_string(&filters, SL("route"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SS(&_13, "phpple.filter.", "output");
	ZEPHIR_INIT_VAR(&_14);
	zephir_create_array(&_14, 1, 0);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "\\Phpple\\Filter\\OutputFilter");
	zephir_array_fast_append(&_14, &_7);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getfilter", &_3, 44, &_13, &_14);
	zephir_check_call_status();
	zephir_array_update_string(&filters, SL("output"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_SS(&_16, "phpple.filter.", "clean");
	ZEPHIR_INIT_NVAR(&_7);
	array_init(&_7);
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getfilter", &_3, 44, &_16, &_7);
	zephir_check_call_status();
	zephir_array_update_string(&filters, SL("clean"), &_15, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("filterExecutor"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_11, "loadfilters", NULL, 0, &filters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch filter
 *
 * @param string name
 * @param array defaults
 * @param boolean cover
 *
 * @return array
 */
PHP_METHOD(Phpple_Http_Application, getFilter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool cover;
	zval defaults;
	zval *name_param = NULL, *defaults_param = NULL, *cover_param = NULL, filters, _1, _2$$3, _3$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&defaults);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &defaults_param, &cover_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&defaults, defaults_param);
	if (!cover_param) {
		cover = 0;
	} else {
		cover = zephir_get_boolval(cover_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_CE_STATIC(&filters, phpple_util_conf_ce, "get", &_0, 0, &name, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&filters) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		zephir_array_fast_append(&_2$$3, &filters);
		ZEPHIR_CPY_WRT(&filters, &_2$$3);
	}
	if (!(cover)) {
		ZEPHIR_CALL_FUNCTION(&_3$$4, "array_diff", NULL, 31, &defaults, &filters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&defaults, &_3$$4);
		zephir_fast_array_merge(return_value, &defaults, &filters);
		RETURN_MM();
	}
	if (zephir_is_true(&filters)) {
		RETURN_CCTOR(&filters);
	}
	RETURN_CTOR(&defaults);

}

/**
 * Execute filter
 */
PHP_METHOD(Phpple_Http_Application, execFilter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filterName_param = NULL, _0;
	zval filterName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filterName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filterName_param);

	zephir_get_strval(&filterName, filterName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("filterExecutor"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "execute", NULL, 0, &filterName);
	zephir_check_call_status();
	RETURN_MM();

}

