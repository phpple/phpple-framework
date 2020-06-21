
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/require.h"


/**
 * Configure
 */
ZEPHIR_INIT_CLASS(Phpple_Util_Conf) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Util, Conf, phpple, util_conf, phpple_util_conf_method_entry, 0);

	zend_declare_property_null(phpple_util_conf_ce, SL("loadedFiles"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phpple_util_conf_ce, SL("confData"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * Load the configure files
 *
 * @param string|array paths
 */
PHP_METHOD(Phpple_Util_Conf, load) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *paths = NULL, paths_sub, __$true, _0$$3, path, _1, *_2, _3, _6$$4, _7$$4, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths);

	ZEPHIR_SEPARATE_PARAM(paths);


	if (!(Z_TYPE_P(paths) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, paths);
		ZEPHIR_CPY_WRT(paths, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(paths, 0, "phpple/Util/Conf.zep", 31);
	if (Z_TYPE_P(paths) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(paths), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_1);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_1, _5);
			} else {
				ZVAL_LONG(&_1, _4);
			}
			ZEPHIR_INIT_NVAR(&path);
			ZVAL_COPY(&path, _2);
			zephir_read_static_property_ce(&_6$$4, phpple_util_conf_ce, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_6$$4, &path)) {
				continue;
			}
			ZEPHIR_CALL_FUNCTION(&_7$$4, "is_readable", &_8, 3, &path);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$4)) {
				if (zephir_require_zval(&path) == FAILURE) {
					RETURN_MM_NULL();
				}
				zephir_update_static_property_array_multi_ce(phpple_util_conf_ce, SL("loadedFiles"), &__$true, SL("z"), 1, &path);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, paths, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, paths, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_1, paths, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&path, paths, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_static_property_ce(&_9$$7, phpple_util_conf_ce, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_9$$7, &path)) {
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_10$$7, "is_readable", &_8, 3, &path);
				zephir_check_call_status();
				if (zephir_is_true(&_10$$7)) {
					if (zephir_require_zval(&path) == FAILURE) {
						RETURN_MM_NULL();
					}
					zephir_update_static_property_array_multi_ce(phpple_util_conf_ce, SL("loadedFiles"), &__$true, SL("z"), 1, &path);
				}
			ZEPHIR_CALL_METHOD(NULL, paths, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&path);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the configure data by key
 *
 * @param string key
 * @param mixed  default
 *
 * @return mixed|null
 */
PHP_METHOD(Phpple_Util_Conf, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defval = NULL, defval_sub, __$null, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defval_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defval);

	zephir_get_strval(&key, key_param);
	if (!defval) {
		defval = &defval_sub;
		defval = &__$null;
	}


	zephir_read_static_property_ce(&_0, phpple_util_conf_ce, SL("confData"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &key)) {
		zephir_read_static_property_ce(&_1$$3, phpple_util_conf_ce, SL("confData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phpple/Util/Conf.zep", 44);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defval, 1, 0);
	RETURN_MM();

}

/**
 * Set the configure data by key
 *
 * @param string key key of the configure
 * @param mixed  value
 */
PHP_METHOD(Phpple_Util_Conf, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_static_property_array_multi_ce(phpple_util_conf_ce, SL("confData"), value, SL("z"), 1, &key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the key is defined
 *
 * @param string key
 *
 * @return bool
 */
PHP_METHOD(Phpple_Util_Conf, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_static_property_ce(&_0, phpple_util_conf_ce, SL("confData"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_0, &key));

}

/**
 * Clear the configure data
 */
PHP_METHOD(Phpple_Util_Conf, clear) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phpple_util_conf_ce, ZEND_STRL("loadedFiles"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_static_property_ce(phpple_util_conf_ce, ZEND_STRL("confData"), &_1);
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Phpple_Util_Conf(TSRMLS_D) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phpple_util_conf_ce, ZEND_STRL("confData"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_static_property_ce(phpple_util_conf_ce, ZEND_STRL("loadedFiles"), &_1);
	ZEPHIR_MM_RESTORE();

}

