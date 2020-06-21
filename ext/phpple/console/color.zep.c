
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phpple_Console_Color) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Console, Color, phpple, console_color, phpple_console_color_method_entry, 0);

	zend_declare_property_null(phpple_console_color_ce, SL("colors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phpple_console_color_ce, SL("bgColors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * Get colored string
 * @param string original string
 * @param string color the color of the $str
 * @param string backColor the background color or the $str
 * @return string
 */
PHP_METHOD(Phpple_Console_Color, getColoredString) {

	zend_bool _0, _5, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *str_param = NULL, *color_param = NULL, *backColor_param = NULL, _1, _6, _2$$3, _3$$3, _4$$3, _7$$4, _8$$4, _9$$4;
	zval str, color, backColor, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&backColor);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &color_param, &backColor_param);

	zephir_get_strval(&str, str_param);
	if (!color_param) {
		ZEPHIR_INIT_VAR(&color);
		ZVAL_STRING(&color, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(color_param) != IS_STRING && Z_TYPE_P(color_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'color' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(color_param) == IS_STRING)) {
		zephir_get_strval(&color, color_param);
	} else {
		ZEPHIR_INIT_VAR(&color);
		ZVAL_EMPTY_STRING(&color);
	}
	}
	if (!backColor_param) {
		ZEPHIR_INIT_VAR(&backColor);
		ZVAL_STRING(&backColor, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(backColor_param) != IS_STRING && Z_TYPE_P(backColor_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'backColor' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(backColor_param) == IS_STRING)) {
		zephir_get_strval(&backColor, backColor_param);
	} else {
		ZEPHIR_INIT_VAR(&backColor);
		ZVAL_EMPTY_STRING(&backColor);
	}
	}


	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	_0 = !ZEPHIR_IS_STRING(&color, "");
	if (_0) {
		zephir_read_static_property_ce(&_1, phpple_console_color_ce, SL("colors"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &color);
	}
	if (_0) {
		zephir_read_static_property_ce(&_2$$3, phpple_console_color_ce, SL("colors"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &color, PH_NOISY | PH_READONLY, "phpple/Console/Color.zep", 47);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "\033[", &_3$$3, "m");
		zephir_concat_self(&result, &_4$$3);
	}
	_5 = !ZEPHIR_IS_STRING(&backColor, "");
	if (_5) {
		zephir_read_static_property_ce(&_6, phpple_console_color_ce, SL("bgColors"), PH_NOISY_CC | PH_READONLY);
		_5 = zephir_array_isset(&_6, &backColor);
	}
	if (_5) {
		zephir_read_static_property_ce(&_7$$4, phpple_console_color_ce, SL("bgColors"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$4, &_7$$4, &backColor, PH_NOISY | PH_READONLY, "phpple/Console/Color.zep", 51);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SVS(&_9$$4, "\033[", &_8$$4, "m");
		zephir_concat_self(&result, &_9$$4);
	}
	zephir_concat_self(&result, &str);
	_10 = !ZEPHIR_IS_STRING(&color, "");
	if (!(_10)) {
		_10 = !ZEPHIR_IS_STRING(&backColor, "");
	}
	if (_10) {
		zephir_concat_self_str(&result, "\033[0m", sizeof("\033[0m") - 1);
	}
	RETURN_CTOR(&result);

}

/**
 * Output normal information
 * @param string content content of information
 * @return string
 */
PHP_METHOD(Phpple_Console_Color, info) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "STDOUT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "light_gray");
	ZEPHIR_CALL_SELF(&_1, "getcoloredstring", NULL, 0, &content, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_1, &_2);
	zephir_fwrite(NULL, &_0, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Output warning information
 * @param string content content of information
 * @return string
 */
PHP_METHOD(Phpple_Console_Color, warn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "STDOUT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "yellow");
	ZEPHIR_CALL_SELF(&_1, "getcoloredstring", NULL, 0, &content, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_1, &_2);
	zephir_fwrite(NULL, &_0, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Output success information
 * @param string content content of information
 * @return string
 */
PHP_METHOD(Phpple_Console_Color, success) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "STDOUT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "green");
	ZEPHIR_CALL_SELF(&_1, "getcoloredstring", NULL, 0, &content, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_1, &_2);
	zephir_fwrite(NULL, &_0, &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Output error information
 * @param string content content of information
 * @return string
 */
PHP_METHOD(Phpple_Console_Color, error) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "STDERR");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "red");
	ZEPHIR_CALL_SELF(&_1, "getcoloredstring", NULL, 0, &content, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_1, &_2);
	zephir_fwrite(NULL, &_0, &_3);
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Phpple_Console_Color(TSRMLS_D) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 8, 0);
	add_assoc_stringl_ex(&_0, SL("black"), SL("40"));
	add_assoc_stringl_ex(&_0, SL("red"), SL("41"));
	add_assoc_stringl_ex(&_0, SL("green"), SL("42"));
	add_assoc_stringl_ex(&_0, SL("yellow"), SL("43"));
	add_assoc_stringl_ex(&_0, SL("blue"), SL("44"));
	add_assoc_stringl_ex(&_0, SL("magenta"), SL("45"));
	add_assoc_stringl_ex(&_0, SL("cyan"), SL("46"));
	add_assoc_stringl_ex(&_0, SL("light_gray"), SL("47"));
	zephir_update_static_property_ce(phpple_console_color_ce, ZEND_STRL("bgColors"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 16, 0);
	add_assoc_stringl_ex(&_1, SL("black"), SL("0;30"));
	add_assoc_stringl_ex(&_1, SL("dark_gray"), SL("1;30"));
	add_assoc_stringl_ex(&_1, SL("blue"), SL("0;34"));
	add_assoc_stringl_ex(&_1, SL("light_blue"), SL("1;34"));
	add_assoc_stringl_ex(&_1, SL("green"), SL("0;32"));
	add_assoc_stringl_ex(&_1, SL("light_green"), SL("1;32"));
	add_assoc_stringl_ex(&_1, SL("cyan"), SL("0;36"));
	add_assoc_stringl_ex(&_1, SL("light_cyan"), SL("1;36"));
	add_assoc_stringl_ex(&_1, SL("red"), SL("0;31"));
	add_assoc_stringl_ex(&_1, SL("light_red"), SL("1;31"));
	add_assoc_stringl_ex(&_1, SL("purple"), SL("0;35"));
	add_assoc_stringl_ex(&_1, SL("light_purple"), SL("1;35"));
	add_assoc_stringl_ex(&_1, SL("brown"), SL("0;33"));
	add_assoc_stringl_ex(&_1, SL("yellow"), SL("1;33"));
	add_assoc_stringl_ex(&_1, SL("light_gray"), SL("0;37"));
	add_assoc_stringl_ex(&_1, SL("white"), SL("1;37"));
	zephir_update_static_property_ce(phpple_console_color_ce, ZEND_STRL("colors"), &_1);
	ZEPHIR_MM_RESTORE();

}

