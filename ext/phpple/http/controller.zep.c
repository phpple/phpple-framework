
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
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phpple_Http_Controller) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Http, Controller, phpple, http_controller, phpple_http_controller_method_entry, 0);

	zend_declare_property_null(phpple_http_controller_ce, SL("logger"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("appId"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("debug"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("method"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("args"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("path"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("request"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_controller_ce, SL("response"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Phpple_Http_Controller, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setAppId) {

	zval *appId, appId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appId_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &appId);



	zephir_update_property_zval(this_ptr, ZEND_STRL("appId"), appId);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setDebug) {

	zval *debug, debug_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&debug_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &debug);



	zephir_update_property_zval(this_ptr, ZEND_STRL("debug"), debug);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setMethod) {

	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &method);



	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), method);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setArgs) {

	zval *args, args_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &args);



	zephir_update_property_zval(this_ptr, ZEND_STRL("args"), args);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setPath) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &path);



	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), path);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setRequest) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &request);



	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, setResponse) {

	zval *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &response);



	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), response);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Controller, _before) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Phpple_Http_Controller, _after) {

	zval *this_ptr = getThis();



}

/**
 * Fetch request datas
 *
 * @param \string[] keys
 *
 * @return array
 * @see Request::gets
 */
PHP_METHOD(Phpple_Http_Controller, gets) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("request"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "gets");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetch request data
 *
 * @param string key
 * @param null default
 *
 * @return mixed|null
 * @see Request::get
 */
PHP_METHOD(Phpple_Http_Controller, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defval = NULL, defval_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defval_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defval);

	zephir_get_strval(&key, key_param);
	if (!defval) {
		defval = &defval_sub;
		defval = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &key, defval);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set response data
 *
 * @param string key
 * @param mixed  value
 *
 * @return this
 * @see Response::set
 */
PHP_METHOD(Phpple_Http_Controller, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL, value_sub, __$null, _0$$3, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(&key) == IS_ARRAY) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "sets", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_THIS();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &key, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set response datas
 *
 * @param \string[] vars
 *
 * @see Response::sets
 * @return this
 */
PHP_METHOD(Phpple_Http_Controller, sets) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL, _0;
	zval vars;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	zephir_get_arrval(&vars, vars_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "sets", NULL, 0, &vars);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Fetch user data by key
 *
 * @param string key
 * @param null defval
 * @return mixed
 *
 * @see Request::getData
 */
PHP_METHOD(Phpple_Http_Controller, getData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defval = NULL, defval_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defval_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defval);

	zephir_get_strval(&key, key_param);
	if (!defval) {
		defval = &defval_sub;
		defval = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdata", NULL, 0, &key, defval);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set user data by key
 *
 * @param string key
 * @param        value
 * @return this
 */
PHP_METHOD(Phpple_Http_Controller, setData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setdata", NULL, 0, &key, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set user data by key
 *
 * @param string key
 * @param        value
 * @return this
 */
PHP_METHOD(Phpple_Http_Controller, setDatas) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL, _0;
	zval vars;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	zephir_get_arrval(&vars, vars_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setdatas", NULL, 0, &vars);
	zephir_check_call_status();
	RETURN_THIS();

}

