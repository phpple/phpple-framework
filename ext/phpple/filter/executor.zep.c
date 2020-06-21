
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phpple_Filter_Executor) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Filter, Executor, phpple, filter_executor, phpple_filter_executor_method_entry, 0);

	/**
	 * @var FilterInterface[]
	 */
	zend_declare_property_null(phpple_filter_executor_ce, SL("impFilters"), ZEND_ACC_PRIVATE);

	/**
	 * @var Application
	 */
	zend_declare_property_null(phpple_filter_executor_ce, SL("app"), ZEND_ACC_PRIVATE);

	/**
	 * @var <LoggerInterface>
	 */
	zend_declare_property_null(phpple_filter_executor_ce, SL("logger"), ZEND_ACC_PRIVATE);

	phpple_filter_executor_ce->create_object = zephir_init_properties_Phpple_Filter_Executor;
	return SUCCESS;

}

/**
 * Executor constructor.
 *
 * @param Application $app
 */
PHP_METHOD(Phpple_Filter_Executor, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), app);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getlogger", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Load filters
 *
 * @param filters
 *
 * @throws Exception
 */
PHP_METHOD(Phpple_Filter_Executor, loadFilters) {

	zend_class_entry *_10$$4, *_13$$6, *_21$$9, *_24$$11;
	zend_string *_3, *_8$$3, *_19$$8;
	zend_ulong _2, _7$$3, _18$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_14 = NULL, *_22 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters_param = NULL, key, classes, *_0, _1, classname$$3, cls$$3, _4$$3, *_5$$3, _6$$3, _9$$4, _12$$6, classname$$8, cls$$8, _15$$8, *_16$$8, _17$$8, _20$$9, _23$$11;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&classname$$3);
	ZVAL_UNDEF(&cls$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&classname$$8);
	ZVAL_UNDEF(&cls$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_23$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	zephir_get_arrval(&filters, filters_param);


	zephir_is_iterable(&filters, 0, "phpple/Filter/Executor.zep", 54);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&filters), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&classes);
			ZVAL_COPY(&classes, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_is_iterable(&classes, 0, "phpple/Filter/Executor.zep", 53);
			if (Z_TYPE_P(&classes) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&classes), _7$$3, _8$$3, _5$$3)
				{
					ZEPHIR_INIT_NVAR(&_4$$3);
					if (_8$$3 != NULL) { 
						ZVAL_STR_COPY(&_4$$3, _8$$3);
					} else {
						ZVAL_LONG(&_4$$3, _7$$3);
					}
					ZEPHIR_INIT_NVAR(&classname$$3);
					ZVAL_COPY(&classname$$3, _5$$3);
					ZEPHIR_INIT_NVAR(&cls$$3);
					zephir_fetch_safe_class(&_9$$4, &classname$$3);
					_10$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_9$$4), Z_STRLEN_P(&_9$$4), ZEND_FETCH_CLASS_AUTO);
					if(!_10$$4) {
						RETURN_MM_NULL();
					}
					object_init_ex(&cls$$3, _10$$4);
					if (zephir_has_constructor(&cls$$3)) {
						ZEPHIR_CALL_METHOD(NULL, &cls$$3, "__construct", &_11, 0);
						zephir_check_call_status();
					}
					if (!(zephir_instance_of_ev(&cls$$3, phpple_filter_filterinterface_ce))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_filter_exception_ce, "phpple.errFilterInstance", "phpple/Filter/Executor.zep", 49);
						return;
					}
					zephir_update_property_array_multi(this_ptr, SL("impFilters"), &cls$$3, SL("za"), 2, &key);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_6$$3, &classes, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&_4$$3, &classes, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&classname$$3, &classes, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&cls$$3);
						zephir_fetch_safe_class(&_12$$6, &classname$$3);
						_13$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_12$$6), Z_STRLEN_P(&_12$$6), ZEND_FETCH_CLASS_AUTO);
						if(!_13$$6) {
							RETURN_MM_NULL();
						}
						object_init_ex(&cls$$3, _13$$6);
						if (zephir_has_constructor(&cls$$3)) {
							ZEPHIR_CALL_METHOD(NULL, &cls$$3, "__construct", &_14, 0);
							zephir_check_call_status();
						}
						if (!(zephir_instance_of_ev(&cls$$3, phpple_filter_filterinterface_ce))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_filter_exception_ce, "phpple.errFilterInstance", "phpple/Filter/Executor.zep", 49);
							return;
						}
						zephir_update_property_array_multi(this_ptr, SL("impFilters"), &cls$$3, SL("za"), 2, &key);
					ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&classname$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &filters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &filters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&classes, &filters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$8);
				zephir_is_iterable(&classes, 0, "phpple/Filter/Executor.zep", 53);
				if (Z_TYPE_P(&classes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&classes), _18$$8, _19$$8, _16$$8)
					{
						ZEPHIR_INIT_NVAR(&_15$$8);
						if (_19$$8 != NULL) { 
							ZVAL_STR_COPY(&_15$$8, _19$$8);
						} else {
							ZVAL_LONG(&_15$$8, _18$$8);
						}
						ZEPHIR_INIT_NVAR(&classname$$8);
						ZVAL_COPY(&classname$$8, _16$$8);
						ZEPHIR_INIT_NVAR(&cls$$8);
						zephir_fetch_safe_class(&_20$$9, &classname$$8);
						_21$$9 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_20$$9), Z_STRLEN_P(&_20$$9), ZEND_FETCH_CLASS_AUTO);
						if(!_21$$9) {
							RETURN_MM_NULL();
						}
						object_init_ex(&cls$$8, _21$$9);
						if (zephir_has_constructor(&cls$$8)) {
							ZEPHIR_CALL_METHOD(NULL, &cls$$8, "__construct", &_22, 0);
							zephir_check_call_status();
						}
						if (!(zephir_instance_of_ev(&cls$$8, phpple_filter_filterinterface_ce))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_filter_exception_ce, "phpple.errFilterInstance", "phpple/Filter/Executor.zep", 49);
							return;
						}
						zephir_update_property_array_multi(this_ptr, SL("impFilters"), &cls$$8, SL("za"), 2, &key);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_17$$8, &classes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_17$$8)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&_15$$8, &classes, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&classname$$8, &classes, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&cls$$8);
							zephir_fetch_safe_class(&_23$$11, &classname$$8);
							_24$$11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_23$$11), Z_STRLEN_P(&_23$$11), ZEND_FETCH_CLASS_AUTO);
							if(!_24$$11) {
								RETURN_MM_NULL();
							}
							object_init_ex(&cls$$8, _24$$11);
							if (zephir_has_constructor(&cls$$8)) {
								ZEPHIR_CALL_METHOD(NULL, &cls$$8, "__construct", &_25, 0);
								zephir_check_call_status();
							}
							if (!(zephir_instance_of_ev(&cls$$8, phpple_filter_filterinterface_ce))) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_filter_exception_ce, "phpple.errFilterInstance", "phpple/Filter/Executor.zep", 49);
								return;
							}
							zephir_update_property_array_multi(this_ptr, SL("impFilters"), &cls$$8, SL("za"), 2, &key);
						ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&classname$$8);
				ZEPHIR_INIT_NVAR(&_15$$8);
			ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&classes);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute filter
 *
 * @param filtername
 *
 * @return bool
 */
PHP_METHOD(Phpple_Filter_Executor, execute) {

	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filterName_param = NULL, _0, _1, _2, filters, _3, filter, _4, *_5, _6, _28, _29, _9$$4, _10$$4, _11$$5, _12$$5, _13$$5, _14$$5, _16$$5, _17$$5, _19$$6, _20$$6, _21$$7, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7;
	zval filterName, key, _18$$5, _27$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filterName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filterName_param);

	zephir_get_strval(&filterName, filterName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("impFilters"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &filterName))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_SV(&key, "f_", &filterName);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "gettimer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "begin", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("impFilters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&filters);
	zephir_array_fetch(&filters, &_3, &filterName, PH_NOISY, "phpple/Filter/Executor.zep", 70);
	ZEPHIR_INIT_VAR(&_4);
	zephir_is_iterable(&filters, 0, "phpple/Filter/Executor.zep", 78);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&filters), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&_4);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&_4, _8);
			} else {
				ZVAL_LONG(&_4, _7);
			}
			ZEPHIR_INIT_NVAR(&filter);
			ZVAL_COPY(&filter, _5);
			zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_9$$4, &filter, "execute", NULL, 0, &_10$$4);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$4)) {
				zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_get_class(&_12$$5, &filter, 0);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "call filter %s.%s=false");
				ZEPHIR_CALL_FUNCTION(&_14$$5, "sprintf", &_15, 14, &_13$$5, &filterName, &_12$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_11$$5, "info", NULL, 0, &_14$$5);
				zephir_check_call_status();
				zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_17$$5, &_16$$5, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_CONCAT_SV(&_18$$5, "f_", &filterName);
				ZEPHIR_CALL_METHOD(NULL, &_17$$5, "end", NULL, 0, &_18$$5);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &filters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_4, &filters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_20$$6, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_19$$6, &filter, "execute", NULL, 0, &_20$$6);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$6)) {
					zephir_read_property(&_21$$7, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_22$$7);
					zephir_get_class(&_22$$7, &filter, 0);
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_STRING(&_23$$7, "call filter %s.%s=false");
					ZEPHIR_CALL_FUNCTION(&_24$$7, "sprintf", &_15, 14, &_23$$7, &filterName, &_22$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_21$$7, "info", NULL, 0, &_24$$7);
					zephir_check_call_status();
					zephir_read_property(&_25$$7, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_26$$7, &_25$$7, ZEND_STRL("timer"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZEPHIR_CONCAT_SV(&_27$$7, "f_", &filterName);
					ZEPHIR_CALL_METHOD(NULL, &_26$$7, "end", NULL, 0, &_27$$7);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&filter);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_read_property(&_28, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_29, &_28, "gettimer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_29, "end", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

zend_object *zephir_init_properties_Phpple_Filter_Executor(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("impFilters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("impFilters"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

