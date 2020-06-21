
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
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phpple_Util_Timer) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Util, Timer, phpple, util_timer, phpple_util_timer_method_entry, 0);

	zend_declare_property_long(phpple_util_timer_ce, SL("start"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_util_timer_ce, SL("stats"), ZEND_ACC_PRIVATE);

	phpple_util_timer_ce->create_object = zephir_init_properties_Phpple_Util_Timer;
	return SUCCESS;

}

/**
 * Timer constructor
 */
PHP_METHOD(Phpple_Util_Timer, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true);
	zephir_update_property_zval(this_ptr, ZEND_STRL("start"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Begin a timer segment.The last timer will be terminated
 *
 * @param string[] $phases the name of the timers
 *
 * @return float current timestamp(unit:10^-3ms)
 */
PHP_METHOD(Phpple_Util_Timer, begin) {

	zval _7$$4, _10$$6;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, now, phase, _0, _1, *_2, _3, _6$$3, _8$$4, _9$$5, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&phase);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&now);
	zephir_microtime(&now, &__$true);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&_0, 0, "phpple/Util/Timer.zep", 31);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_1);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_1, _5);
			} else {
				ZVAL_LONG(&_1, _4);
			}
			ZEPHIR_INIT_NVAR(&phase);
			ZVAL_COPY(&phase, _2);
			zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_6$$3, &phase))) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_create_array(&_7$$4, 2, 0);
				zephir_array_fast_append(&_7$$4, &now);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_LONG(&_8$$4, 0);
				zephir_array_fast_append(&_7$$4, &_8$$4);
				zephir_update_property_array(this_ptr, SL("stats"), &phase, &_7$$4);
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
			ZEPHIR_CALL_METHOD(&_1, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&phase, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_9$$5, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_9$$5, &phase))) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_create_array(&_10$$6, 2, 0);
					zephir_array_fast_append(&_10$$6, &now);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_LONG(&_11$$6, 0);
					zephir_array_fast_append(&_10$$6, &_11$$6);
					zephir_update_property_array(this_ptr, SL("stats"), &phase, &_10$$6);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&phase);
	ZEPHIR_INIT_NVAR(&_1);
	RETURN_CCTOR(&now);

}

/**
 * Terminate the timers
 *
 * @param string[] $phases the names of timer that will be terminated
 *
 * @return float current timestamp
 */
PHP_METHOD(Phpple_Util_Timer, end) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, now, phase, _0, _1, *_2, _3, _6$$3, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&phase);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&now);
	zephir_microtime(&now, &__$true);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&_0, 0, "phpple/Util/Timer.zep", 49);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_1);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_1, _5);
			} else {
				ZVAL_LONG(&_1, _4);
			}
			ZEPHIR_INIT_NVAR(&phase);
			ZVAL_COPY(&phase, _2);
			zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_6$$3, &phase)) {
				zephir_update_property_array_multi(this_ptr, SL("stats"), &now, SL("zl"), 2, &phase, 1);
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
			ZEPHIR_CALL_METHOD(&_1, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&phase, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_7$$5, &phase)) {
					zephir_update_property_array_multi(this_ptr, SL("stats"), &now, SL("zl"), 2, &phase, 1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&phase);
	ZEPHIR_INIT_NVAR(&_1);
	RETURN_CCTOR(&now);

}

/**
 * Terminate all timers
 *
 * @return float current timestamp
 */
PHP_METHOD(Phpple_Util_Timer, endAll) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, now, phase, stat, _0, *_1, _2, _5$$3, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&phase);
	ZVAL_UNDEF(&stat);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&now);
	zephir_microtime(&now, &__$true);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phpple/Util/Timer.zep", 65);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&phase);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&phase, _4);
			} else {
				ZVAL_LONG(&phase, _3);
			}
			ZEPHIR_INIT_NVAR(&stat);
			ZVAL_COPY(&stat, _1);
			zephir_array_fetch_long(&_5$$3, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 61);
			if (ZEPHIR_IS_LONG_IDENTICAL(&_5$$3, 0)) {
				zephir_update_property_array_multi(this_ptr, SL("stats"), &now, SL("zl"), 2, &phase, 1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&phase, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&stat, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_6$$5, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 61);
				if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$5, 0)) {
					zephir_update_property_array_multi(this_ptr, SL("stats"), &now, SL("zl"), 2, &phase, 1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&stat);
	ZEPHIR_INIT_NVAR(&phase);
	RETURN_CCTOR(&now);

}

/**
 * Get the result of all timers
 *
 * @param bool $end if stop all timers
 *
 * @return array array(
 *  $phase => $cost
 * )
 */
PHP_METHOD(Phpple_Util_Timer, getResult) {

	zend_string *_4;
	zend_ulong _3;
	zval result;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *end_param = NULL, phase, stat, _0, *_1, _2, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$6, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7;
	zend_bool end;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phase);
	ZVAL_UNDEF(&stat);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &end_param);

	if (!end_param) {
		end = 1;
	} else {
		end = zephir_get_boolval(end_param);
	}


	if (end) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "endall", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phpple/Util/Timer.zep", 89);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&phase);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&phase, _4);
			} else {
				ZVAL_LONG(&phase, _3);
			}
			ZEPHIR_INIT_NVAR(&stat);
			ZVAL_COPY(&stat, _1);
			zephir_array_fetch_long(&_5$$4, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 85);
			if (zephir_is_true(&_5$$4)) {
				zephir_array_fetch_long(&_6$$5, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 86);
				zephir_array_fetch_long(&_7$$5, &stat, 0, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 86);
				ZEPHIR_INIT_NVAR(&_8$$5);
				zephir_sub_function(&_8$$5, &_6$$5, &_7$$5);
				ZVAL_LONG(&_9$$5, (zephir_get_numberval(&_8$$5) * 1000000));
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_LONG(&_10$$5, zephir_get_intval(&_9$$5));
				zephir_array_update_zval(&result, &phase, &_10$$5, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&phase, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&stat, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_11$$6, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 85);
				if (zephir_is_true(&_11$$6)) {
					zephir_array_fetch_long(&_12$$7, &stat, 1, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 86);
					zephir_array_fetch_long(&_13$$7, &stat, 0, PH_NOISY | PH_READONLY, "phpple/Util/Timer.zep", 86);
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_sub_function(&_14$$7, &_12$$7, &_13$$7);
					ZVAL_LONG(&_15$$7, (zephir_get_numberval(&_14$$7) * 1000000));
					ZEPHIR_INIT_NVAR(&_16$$7);
					ZVAL_LONG(&_16$$7, zephir_get_intval(&_15$$7));
					zephir_array_update_zval(&result, &phase, &_16$$7, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&stat);
	ZEPHIR_INIT_NVAR(&phase);
	RETURN_CTOR(&result);

}

zend_object *zephir_init_properties_Phpple_Util_Timer(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("stats"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("stats"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

