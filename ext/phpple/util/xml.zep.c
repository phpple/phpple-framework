
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phpple_Util_Xml) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Util, Xml, phpple, util_xml, phpple_util_xml_method_entry, 0);

	zend_declare_property_null(phpple_util_xml_ce, SL("search"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phpple_util_xml_ce, SL("replace"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phpple_util_xml_ce, SL("buffers"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * Change Array to xml
 * @param array arr
 * @param int level
 */
PHP_METHOD(Phpple_Util_Xml, innerArray2Xml) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *arr_param = NULL, *level_param = NULL, key, value, *_0, _1, _4$$5, _5$$5, _6$$5, _9$$6, _10$$6, _11$$6, _12$$6, _13$$6, _14$$9, _15$$9, _16$$9, _17$$10, _18$$10, _19$$10, _20$$10, _21$$10;
	zval arr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr_param, &level_param);

	zephir_get_arrval(&arr, arr_param);
	level = zephir_get_intval(level_param);


	zephir_is_iterable(&arr, 0, "phpple/Util/Xml.zep", 33);
	if (Z_TYPE_P(&arr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arr), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_STRING(&key, "item");
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "\t");
				ZVAL_LONG(&_5$$5, (level - 1));
				ZEPHIR_CALL_FUNCTION(&_6$$5, "str_repeat", &_7, 63, &_4$$5, &_5$$5);
				zephir_check_call_status();
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_6$$5, SL("a"), 1);
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "<key>\r\n");
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_4$$5, SL("a"), 1);
				ZVAL_LONG(&_5$$5, (level + 1));
				ZEPHIR_CALL_SELF(NULL, "innerarray2xml", &_8, 64, &value, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "\t");
				ZVAL_LONG(&_5$$5, (level - 1));
				ZEPHIR_CALL_FUNCTION(&_6$$5, "str_repeat", &_7, 63, &_4$$5, &_5$$5);
				zephir_check_call_status();
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_6$$5, SL("a"), 1);
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "</key>\r\n");
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_4$$5, SL("a"), 1);
			} else {
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_read_static_property_ce(&_10$$6, phpple_util_xml_ce, SL("search"), PH_NOISY_CC | PH_READONLY);
				zephir_read_static_property_ce(&_11$$6, phpple_util_xml_ce, SL("replace"), PH_NOISY_CC | PH_READONLY);
				zephir_fast_str_replace(&_9$$6, &_10$$6, &_11$$6, &value);
				ZEPHIR_CPY_WRT(&value, &_9$$6);
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "\t");
				ZVAL_LONG(&_12$$6, (level - 1));
				ZEPHIR_CALL_FUNCTION(&_13$$6, "str_repeat", &_7, 63, &_9$$6, &_12$$6);
				zephir_check_call_status();
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_13$$6, SL("a"), 1);
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "<key>value</key>\r\n");
				zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_9$$6, SL("a"), 1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &arr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &arr, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &arr, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					ZEPHIR_INIT_NVAR(&key);
					ZVAL_STRING(&key, "item");
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZVAL_STRING(&_14$$9, "\t");
					ZVAL_LONG(&_15$$9, (level - 1));
					ZEPHIR_CALL_FUNCTION(&_16$$9, "str_repeat", &_7, 63, &_14$$9, &_15$$9);
					zephir_check_call_status();
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_16$$9, SL("a"), 1);
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZVAL_STRING(&_14$$9, "<key>\r\n");
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_14$$9, SL("a"), 1);
					ZVAL_LONG(&_15$$9, (level + 1));
					ZEPHIR_CALL_SELF(NULL, "innerarray2xml", &_8, 64, &value, &_15$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZVAL_STRING(&_14$$9, "\t");
					ZVAL_LONG(&_15$$9, (level - 1));
					ZEPHIR_CALL_FUNCTION(&_16$$9, "str_repeat", &_7, 63, &_14$$9, &_15$$9);
					zephir_check_call_status();
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_16$$9, SL("a"), 1);
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZVAL_STRING(&_14$$9, "</key>\r\n");
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_14$$9, SL("a"), 1);
				} else {
					ZEPHIR_INIT_NVAR(&_17$$10);
					zephir_read_static_property_ce(&_18$$10, phpple_util_xml_ce, SL("search"), PH_NOISY_CC | PH_READONLY);
					zephir_read_static_property_ce(&_19$$10, phpple_util_xml_ce, SL("replace"), PH_NOISY_CC | PH_READONLY);
					zephir_fast_str_replace(&_17$$10, &_18$$10, &_19$$10, &value);
					ZEPHIR_CPY_WRT(&value, &_17$$10);
					ZEPHIR_INIT_NVAR(&_17$$10);
					ZVAL_STRING(&_17$$10, "\t");
					ZVAL_LONG(&_20$$10, (level - 1));
					ZEPHIR_CALL_FUNCTION(&_21$$10, "str_repeat", &_7, 63, &_17$$10, &_20$$10);
					zephir_check_call_status();
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_21$$10, SL("a"), 1);
					ZEPHIR_INIT_NVAR(&_17$$10);
					ZVAL_STRING(&_17$$10, "<key>value</key>\r\n");
					zephir_update_static_property_array_multi_ce(phpple_util_xml_ce, SL("buffers"), &_17$$10, SL("a"), 1);
				}
			ZEPHIR_CALL_METHOD(NULL, &arr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 将数组转化为xml
 *
 * @param array  arr
 * @param string encoding
 *
 * @return string
 */
PHP_METHOD(Phpple_Util_Xml, array2Xml) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval encoding;
	zval *arr_param = NULL, *encoding_param = NULL, __$null, _1, ret, _4, data$$3, _3$$3;
	zval arr, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&data$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr_param, &encoding_param);

	zephir_get_arrval(&arr, arr_param);
	zephir_get_strval(&encoding, encoding_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<?xml version=\"1.0\" encoding=\"encoding\" ?>\r\n");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(phpple_util_xml_ce, ZEND_STRL("buffers"), &_0);
	if (zephir_fast_count_int(&arr) > 0) {
		ZEPHIR_INIT_VAR(&data$$3);
		zephir_create_array(&data$$3, 1, 0);
		zephir_array_update_string(&data$$3, SL("Phpple"), &arr, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_CALL_SELF(NULL, "innerarray2xml", &_2, 64, &data$$3, &_3$$3);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_4, phpple_util_xml_ce, SL("buffers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&ret);
	zephir_fast_join_str(&ret, SL(""), &_4);
	zephir_update_static_property_ce(phpple_util_xml_ce, ZEND_STRL("buffers"), &__$null);
	RETURN_CCTOR(&ret);

}

void zephir_init_static_properties_Phpple_Util_Xml(TSRMLS_D) {

	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "&amp;");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "&gt;");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "&lt;");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "&quot;");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "&apos;");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(phpple_util_xml_ce, ZEND_STRL("replace"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 5, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "&");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ">");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "'");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\"");
	zephir_array_fast_append(&_2, &_1);
	zephir_update_static_property_ce(phpple_util_xml_ce, ZEND_STRL("search"), &_2);
	ZEPHIR_MM_RESTORE();

}

