
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phpple_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phpple, Exception, phpple, exception, zend_exception_get_default(TSRMLS_C), phpple_exception_method_entry, 0);

	zend_declare_property_null(phpple_exception_ce, SL("params"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Set Params
 * @param array $params
 */
PHP_METHOD(Phpple_Exception, setParams) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, key, val, *_0, _1;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	zephir_is_iterable(&params, 0, "phpple/Exception.zep", 17);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			zephir_update_property_array(this_ptr, SL("params"), &key, &val);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &params, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &params, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &params, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &params, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("params"), &key, &val);
			ZEPHIR_CALL_METHOD(NULL, &params, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get Exception with Params
 * @param msg
 * @param array params
 * @param int code
 * @throws Exception
 */
PHP_METHOD(Phpple_Exception, withParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *msg_param = NULL, *params_param = NULL, *code_param = NULL, ex, _0;
	zval msg;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &msg_param, &params_param, &code_param);

	zephir_get_strval(&msg, msg_param);
	zephir_get_arrval(&params, params_param);
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	ZEPHIR_INIT_VAR(&ex);
	object_init_ex(&ex, phpple_exception_ce);
	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_METHOD(NULL, &ex, "__construct", NULL, 1, &msg, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ex, "setparams", NULL, 2, &params);
	zephir_check_call_status();
	RETURN_CCTOR(&ex);

}

/**
 * Get params
 * @return array
 */
PHP_METHOD(Phpple_Exception, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

