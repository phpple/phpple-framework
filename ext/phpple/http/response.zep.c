
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Phpple_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Http, Response, phpple, http_response, phpple_http_response_method_entry, 0);

	zend_declare_property_null(phpple_http_response_ce, SL("app"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_response_ce, SL("logger"), ZEND_ACC_PROTECTED);

	/**
	 * Output variables
	 *
	 * @var array
	 */
	zend_declare_property_null(phpple_http_response_ce, SL("outputs"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_response_ce, SL("headers"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phpple_http_response_ce, SL("rawData"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var Exception
	 */
	zend_declare_property_null(phpple_http_response_ce, SL("exception"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_response_ce, SL("error"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(phpple_http_response_ce, SL("needSetContentType"), 1, ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_response_ce, SL("callback"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_response_ce, SL("results"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_response_ce, SL("cookies"), ZEND_ACC_PRIVATE);

	/**
	 * background task.
	 * @var array
	 */
	zend_declare_property_null(phpple_http_response_ce, SL("tasks"), ZEND_ACC_PRIVATE);

	phpple_http_response_ce->create_object = zephir_init_properties_Phpple_Http_Response;
	zephir_declare_class_constant_string(phpple_http_response_ce, SL("STATUS_OK"), "ok");

	zephir_declare_class_constant_string(phpple_http_response_ce, SL("STATUS_FATAL"), "fatal");

	zephir_declare_class_constant_string(phpple_http_response_ce, SL("STATUS_INPUT"), "u_input");

	zend_class_implements(phpple_http_response_ce, 1, phpple_responseinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Http_Response, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

/**
 * Response constructor.
 *
 * @param Application app
 */
PHP_METHOD(Phpple_Http_Response, __construct) {

	zval *app = NULL, app_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(0, 1, &app);

	if (!app) {
		app = &app_sub;
		app = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), app);

}

/**
 * Reset
 */
PHP_METHOD(Phpple_Http_Response, reset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, __$true, __$false, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("exception"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &__$null);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("rawData"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), &__$null);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("outputs"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("results"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set exception
 *
 * @param ex Exception
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setException) {

	zval *ex, ex_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ex_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &ex);



	zephir_update_property_zval(this_ptr, ZEND_STRL("exception"), ex);
	RETURN_THISW();

}

/**
 * Set a variable
 *
 * @param string key The key of output variable
 * @param mixed value The value of output variable
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("outputs"), &key, value);
	RETURN_THIS();

}

/**
 * Set multi variables
 *
 * @param array vars variables
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, sets) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL, k, v, *_0, _1;
	zval vars;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	zephir_get_arrval(&vars, vars_param);


	zephir_is_iterable(&vars, 0, "phpple/Http/Response.zep", 111);
	if (Z_TYPE_P(&vars) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&vars), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&k, _3);
			} else {
				ZVAL_LONG(&k, _2);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _0);
			zephir_update_property_array(this_ptr, SL("outputs"), &k, &v);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &vars, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &vars, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &vars, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &vars, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("outputs"), &k, &v);
			ZEPHIR_CALL_METHOD(NULL, &vars, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_THIS();

}

/**
 * remove key from outputs
 *
 * @param string keys the keys need removed
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, rmset) {

	zend_string *_5;
	zend_ulong _4;
	zval keys, k, _1, *_2, _3, _0$$3, _6$$4, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&keys);
	zephir_get_args(&keys);
	if (zephir_fast_count_int(&keys) == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("outputs"), &_0$$3);
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&keys, 0, "phpple/Http/Response.zep", 131);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keys), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&k, _5);
			} else {
				ZVAL_LONG(&k, _4);
			}
			ZEPHIR_INIT_NVAR(&_1);
			ZVAL_COPY(&_1, _2);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("outputs"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_6$$4, &k, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &keys, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1, &keys, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("outputs"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_7$$5, &k, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_THIS();

}

/**
 * Set the callback function's name of jsonp
 *
 * @param string funcName
 *
 * @return Response
 * @throws Exception phpple.illegalCallback illegal function name
 */
PHP_METHOD(Phpple_Http_Response, setCallback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *funcName_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval funcName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&funcName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &funcName_param);

	zephir_get_strval(&funcName, funcName_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^[a-zA-Z_][a-zA-Z_0-9.]{0,128}/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/^[a-zA-Z_][a-zA-Z_0-9.]{0,128}/");
	zephir_preg_match(&_2, &_3, &funcName, &_0, 0, 0 , 0 );
	if (!zephir_is_true(&_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_http_exception_ce, "phpple.illegalCallback", "phpple/Http/Response.zep", 145);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), &funcName);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "json");
	ZEPHIR_CALL_METHOD(NULL, &_5, "setoutputformat", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set output header
 *
 * @param string|array key key
 * @param null value value
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setHeader) {

	zend_bool _1$$3, _5$$3, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value = NULL, value_sub, __$true, __$false, __$null, _0, _2$$3, _3$$3, _4$$3, _7$$3, _8$$5;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("needSetContentType"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		_1$$3 = Z_TYPE_P(value) == IS_NULL;
		if (_1$$3) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_fast_strtolower(&_2$$3, &key);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "content-type:");
			ZEPHIR_INIT_VAR(&_4$$3);
			zephir_fast_strpos(&_4$$3, &_2$$3, &_3$$3, 0 );
			_1$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_4$$3, 0);
		}
		_5$$3 = _1$$3;
		if (!(_5$$3)) {
			_6$$3 = Z_TYPE_P(value) != IS_NULL;
			if (_6$$3) {
				ZEPHIR_INIT_VAR(&_7$$3);
				zephir_fast_strtolower(&_7$$3, &key);
				_6$$3 = ZEPHIR_IS_STRING(&_7$$3, "content-type");
			}
			_5$$3 = _6$$3;
		}
		if (_5$$3) {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$false);
			}
		}
	}
	if (Z_TYPE_P(value) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_CONCAT_VSV(&_8$$5, &key, ": ", value);
		zephir_update_property_array_append(this_ptr, SL("headers"), &_8$$5);
	} else {
		zephir_update_property_array_append(this_ptr, SL("headers"), &key);
	}
	RETURN_THIS();

}

/**
 * Defines a cookie to be sent along with the rest of the HTTP headers
 *
 * @param string name The name of the cookie
 * @param string value The value of the cookie
 * @param int expires The time the cookie expires
 * @param string path The path on the server in which the cookie will be available on
 * @param string domain The (sub)domain that the cookie is available to
 * @param bool secure Indicates that the cookie should only be transmitted over a secure HTTPS connection from
 *                         the client
 * @param bool httponly When TRUE the cookie will be made accessible only through the HTTP protocol
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setCookie) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool httponly, secure;
	zend_long expires;
	zval *name_param = NULL, *value_param = NULL, *expires_param = NULL, *path_param = NULL, *domain_param = NULL, *httponly_param = NULL, *secure_param = NULL, _0;
	zval name, value, path, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value_param, &expires_param, &path_param, &domain_param, &httponly_param, &secure_param);

	zephir_get_strval(&name, name_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}
	if (!expires_param) {
		expires = 0;
	} else {
		expires = zephir_get_intval(expires_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "/");
	} else {
		zephir_get_strval(&path, path_param);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
		zephir_get_strval(&domain, domain_param);
	}
	if (!httponly_param) {
		httponly = 0;
	} else {
		httponly = zephir_get_boolval(httponly_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_update_property_array_append(this_ptr, SL("cookies"), &_0);
	RETURN_THIS();

}

/**
 * 设置原始输出内容
 *
 * @param string rawData
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setRaw) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *rawData_param = NULL;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_strval(&rawData, rawData_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("rawData"), &rawData);
	RETURN_THIS();

}

/**
 * Redirect
 *
 * @param string url
 * @param bool permanent
 */
PHP_METHOD(Phpple_Http_Response, redirect) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool permanent;
	zval *url_param = NULL, *permanent_param = NULL, _0$$3, _2, _3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &permanent_param);

	zephir_get_strval(&url, url_param);
	if (!permanent_param) {
		permanent = 0;
	} else {
		permanent = zephir_get_boolval(permanent_param);
	}


	if (permanent) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "HTTP/1.1 301 Moved Permanently");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_1, 0, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Location");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_1, 0, &_2, &url);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ok");
	ZEPHIR_CALL_METHOD(NULL, &_3, "setendstatus", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "end", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the header of framework
 *
 * @param string errCode
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setFrHeader) {

	zend_bool _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *errCode_param = NULL, header, _0, _1, _2, method$$3, urls$$3, _3$$3, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, retry$$3, _12$$3, _13$$5;
	zval errCode, _14$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errCode);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&method$$3);
	ZVAL_UNDEF(&urls$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&retry$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &errCode_param);

	if (!errCode_param) {
		ZEPHIR_INIT_VAR(&errCode);
		ZVAL_STRING(&errCode, "suc");
	} else {
		zephir_get_strval(&errCode, errCode_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, ZEND_STRL("appId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "phpple: id=%d");
	ZEPHIR_CALL_FUNCTION(&header, "sprintf", NULL, 14, &_2, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&errCode, "suc")) {
		ZEPHIR_INIT_VAR(&method$$3);
		ZVAL_STRING(&method$$3, "r");
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "getrequest", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "geturl", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&urls$$3);
		zephir_fast_explode_str(&urls$$3, SL("/"), &_5$$3, LONG_MAX);
		_6$$3 = zephir_is_true(&urls$$3);
		if (_6$$3) {
			zephir_array_fetch_long(&_7$$3, &urls$$3, (zephir_fast_count_int(&urls$$3) - 1), PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 251);
			ZEPHIR_INIT_VAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "_");
			ZVAL_LONG(&_9$$3, 1);
			ZEPHIR_CALL_FUNCTION(&_10$$3, "strncmp", NULL, 22, &_7$$3, &_8$$3, &_9$$3);
			zephir_check_call_status();
			_6$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_10$$3, 0);
		}
		if (_6$$3) {
			ZEPHIR_INIT_NVAR(&method$$3);
			ZVAL_STRING(&method$$3, "w");
		}
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, ",e=%s,m=%s");
		ZEPHIR_CALL_FUNCTION(&_11$$3, "sprintf", NULL, 14, &_8$$3, &errCode, &method$$3);
		zephir_check_call_status();
		zephir_concat_self(&header, &_11$$3);
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$3, &_9$$3, "getrequest", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "retry");
		ZEPHIR_CALL_METHOD(&retry$$3, &_12$$3, "get", NULL, 0, &_8$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&retry$$3, 0)) {
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_LONG(&_13$$5, zephir_get_intval(&retry$$3));
			ZEPHIR_INIT_VAR(&_14$$5);
			ZEPHIR_CONCAT_SV(&_14$$5, ",r=", &_13$$5);
			zephir_concat_self(&header, &_14$$5);
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &header);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Tell brower or delagate not cache this page
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setNoCache) {

	zval _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Expires");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Mon, 26 Jul 1997 05:00:00 GMT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "D, d M Y H:i:s");
	ZEPHIR_CALL_FUNCTION(&_3, "gmdate", NULL, 45, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, " GMT");
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Last-Modified");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Cache-Control");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "no-store, no-cache, must-revalidate, post-check=0, pre-check=0");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Pragma");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "no-cache");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set the variable of framework
 *
 * @param string key Key of the variable
 * @param mixed value Value of the variable
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, setFrVar) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("results"), &key, value);
	RETURN_THIS();

}

/**
 * Send the http headers
 *
 * @return Response
 */
PHP_METHOD(Phpple_Http_Response, sendHeaders) {

	zval cookie, header, _0, *_1, _2, _7, _3$$3, _4$$3, _5$$4, _6$$4, _8$$5, *_9$$5, _10$$5, _11$$6, _12$$6, _13$$7, _14$$7, _15$$8, *_16$$8, _17$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phpple/Http/Response.zep", 306);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&cookie);
			ZVAL_COPY(&cookie, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "setcookie");
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_3$$3, &_4$$3, &cookie);
			zephir_check_call_status();
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
			ZEPHIR_CALL_METHOD(&cookie, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_STRING(&_6$$4, "setcookie");
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$4, &_6$$4, &cookie);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cookie);
	ZEPHIR_CALL_FUNCTION(&_7, "php_sapi_name", NULL, 46);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_7, "cli")) {
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_8$$5, 0, "phpple/Http/Response.zep", 310);
		if (Z_TYPE_P(&_8$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8$$5), _9$$5)
			{
				ZEPHIR_INIT_NVAR(&header);
				ZVAL_COPY(&header, _9$$5);
				zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZEPHIR_CONCAT_SV(&_12$$6, "header:", &header);
				ZEPHIR_CALL_METHOD(NULL, &_11$$6, "debug", NULL, 0, &_12$$6);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$5, &_8$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&header, &_8$$5, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_14$$7);
					ZEPHIR_CONCAT_SV(&_14$$7, "header:", &header);
					ZEPHIR_CALL_METHOD(NULL, &_13$$7, "debug", NULL, 0, &_14$$7);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&header);
	} else {
		zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_15$$8, 0, "phpple/Http/Response.zep", 314);
		if (Z_TYPE_P(&_15$$8) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_15$$8), _16$$8)
			{
				ZEPHIR_INIT_NVAR(&header);
				ZVAL_COPY(&header, _16$$8);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_18, 47, &header);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_15$$8, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$8, &_15$$8, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&header, &_15$$8, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_18, 47, &header);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_15$$8, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&header);
	}
	RETURN_THIS();

}

/**
 * End the output
 */
PHP_METHOD(Phpple_Http_Response, end) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "output");
	ZEPHIR_CALL_METHOD(NULL, &_0, "filter", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ok");
	ZEPHIR_CALL_METHOD(NULL, &_2, "setendstatus", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

/**
 * Run tasks
 */
PHP_METHOD(Phpple_Http_Response, runTasks) {

	zval _0, _1$$3, _3$$3, _4$$3, task$$3, *_5$$3, _6$$3, _8$$4, _9$$4, _10$$4, output$$4, _12$$5, _13$$5, _14$$6, _15$$6, _16$$6, output$$6, _17$$7, _18$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&task$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&output$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&output$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tasks"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_CALL_FUNCTION(NULL, "fastcgi_finish_request", NULL, 48);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "phpple.fastcgi_finish_timeout");
		ZVAL_LONG(&_4$$3, 3600);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phpple_util_conf_ce, "get", &_2, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "max_execution_time");
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_1$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 6, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("tasks"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_4$$3, 0, "phpple/Http/Response.zep", 351);
		if (Z_TYPE_P(&_4$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4$$3), _5$$3)
			{
				ZEPHIR_INIT_NVAR(&task$$3);
				ZVAL_COPY(&task$$3, _5$$3);
				ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_7, 49);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_array_fetch_long(&_9$$4, &task$$3, 0, PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 345);
				zephir_array_fetch_long(&_10$$4, &task$$3, 1, PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 345);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_8$$4, &_9$$4, &_10$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&output$$4, "ob_get_clean", &_11, 50);
				zephir_check_call_status();
				if (zephir_is_true(&output$$4)) {
					zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_13$$5);
					ZEPHIR_CONCAT_SV(&_13$$5, "task output:", &output$$4);
					ZEPHIR_CALL_METHOD(NULL, &_12$$5, "trace", NULL, 0, &_13$$5);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_4$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$3, &_4$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&task$$3, &_4$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_7, 49);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_array_fetch_long(&_15$$6, &task$$3, 0, PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 345);
					zephir_array_fetch_long(&_16$$6, &task$$3, 1, PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 345);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$6, &_15$$6, &_16$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&output$$6, "ob_get_clean", &_11, 50);
					zephir_check_call_status();
					if (zephir_is_true(&output$$6)) {
						zephir_read_property(&_17$$7, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_18$$7);
						ZEPHIR_CONCAT_SV(&_18$$7, "task output:", &output$$6);
						ZEPHIR_CALL_METHOD(NULL, &_17$$7, "trace", NULL, 0, &_18$$7);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &_4$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&task$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Build the header named "Content-Type"
 *
 * @param of
 * @param encoding
 */
PHP_METHOD(Phpple_Http_Response, buildContentType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *of_param = NULL, *encoding_param = NULL, __$true, __$false, _0;
	zval of, encoding, _1$$4, _2$$5, _3$$6, _4$$7, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&of);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &of_param, &encoding_param);

	zephir_get_strval(&of, of_param);
	zephir_get_strval(&encoding, encoding_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("needSetContentType"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	do {
		if (ZEPHIR_IS_STRING(&of, "json")) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZEPHIR_CONCAT_SV(&_1$$4, "Content-type: application/json; charset=", &encoding);
			zephir_update_property_array_append(this_ptr, SL("headers"), &_1$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&of, "html")) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SV(&_2$$5, "Content-Type: text/html; charset=", &encoding);
			zephir_update_property_array_append(this_ptr, SL("headers"), &_2$$5);
			break;
		}
		if (ZEPHIR_IS_STRING(&of, "xml")) {
			ZEPHIR_INIT_VAR(&_3$$6);
			ZEPHIR_CONCAT_SV(&_3$$6, "Content-Type: text/xml; charset=", &encoding);
			zephir_update_property_array_append(this_ptr, SL("headers"), &_3$$6);
			break;
		}
		if (ZEPHIR_IS_STRING(&of, "jpg") || ZEPHIR_IS_STRING(&of, "png") || ZEPHIR_IS_STRING(&of, "gif")) {
			ZEPHIR_INIT_VAR(&_4$$7);
			ZEPHIR_CONCAT_SV(&_4$$7, "Content-Type: image/", &of);
			zephir_update_property_array_append(this_ptr, SL("headers"), &_4$$7);
			break;
		}
		ZEPHIR_INIT_VAR(&_5$$8);
		ZEPHIR_CONCAT_SV(&_5$$8, "Content-Type: text/plain; charset=", &encoding);
		zephir_update_property_array_append(this_ptr, SL("headers"), &_5$$8);
	} while(0);

	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("needSetContentType"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the result of output
 *
 * @return array
 */
PHP_METHOD(Phpple_Http_Response, getResult) {

	zend_string *_20;
	zend_ulong _19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, result, _0, key, value, *_17, _18, errcode$$3, _1$$3, pos$$3, _2$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _3$$4, _4$$4, _10$$6, _11$$6, _12$$6, _13$$6, _14$$6, _15$$7, _16$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&errcode$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&pos$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&result);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&errcode$$3, &_1$$3, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, " ");
		ZEPHIR_INIT_VAR(&pos$$3);
		zephir_fast_strpos(&pos$$3, &errcode$$3, &_2$$3, 0 );
		if (zephir_is_true(&pos$$3)) {
			ZVAL_LONG(&_3$$4, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_substr(&_4$$4, &errcode$$3, 0 , zephir_get_intval(&pos$$3), 0);
			ZEPHIR_CPY_WRT(&errcode$$3, &_4$$4);
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "/^[a-zA-Z0-9\\.\\-_]{1,50}/");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "/^[a-zA-Z0-9\\.\\-_]{1,50}/");
		zephir_preg_match(&_7$$3, &_8$$3, &errcode$$3, &_5$$3, 0, 0 , 0 );
		if (!(zephir_is_true(&_7$$3))) {
			ZEPHIR_INIT_NVAR(&errcode$$3);
			ZVAL_STRING(&errcode$$3, "fatal");
		}
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 1, 0);
		zephir_array_update_string(&_9$$3, SL("err"), &errcode$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&result, &_9$$3);
		if (ZEPHIR_IS_STRING(&errcode$$3, "u_input")) {
			zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("outputs"), PH_NOISY_CC | PH_READONLY);
			zephir_array_update_string(&result, SL("data"), &_10$$6, PH_COPY | PH_SEPARATE);
			zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_12$$6, &result, SL("data"), PH_NOISY | PH_READONLY, "phpple/Http/Response.zep", 409);
			ZEPHIR_CALL_FUNCTION(&_13$$6, "print_r", NULL, 27, &_12$$6, &__$true);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_14$$6);
			ZVAL_STRING(&_14$$6, "input data error:%s");
			ZEPHIR_CALL_METHOD(NULL, &_11$$6, "debug", NULL, 0, &_14$$6, &_13$$6);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_VAR(&_15$$7);
		zephir_create_array(&_15$$7, 2, 0);
		add_assoc_stringl_ex(&_15$$7, SL("err"), SL("ok"));
		ZEPHIR_OBS_VAR(&_16$$7);
		zephir_read_property(&_16$$7, this_ptr, ZEND_STRL("outputs"), PH_NOISY_CC);
		zephir_array_update_string(&_15$$7, SL("data"), &_16$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&result, &_15$$7);
	}
	zephir_is_iterable(&result, 1, "phpple/Http/Response.zep", 423);
	if (Z_TYPE_P(&result) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&result), _19, _20, _17)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_20 != NULL) { 
				ZVAL_STR_COPY(&key, _20);
			} else {
				ZVAL_LONG(&key, _19);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _17);
			if (!(zephir_array_isset(&result, &key))) {
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &result, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_18, &result, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &result, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &result, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&result, &key))) {
					zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &result, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);

}

/**
 * Format output
 *
 * @return mixed|string
 */
PHP_METHOD(Phpple_Http_Response, formatResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, result, of, _0, _1, _2, _3, _4, _5$$4, _9$$4, _10$$4, _11$$4, _12$$4, _6$$5, _7$$5, _8$$5, _14$$7, _15$$7;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, options$$4;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&of);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&result, this_ptr, "getresult", NULL, 51);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&of, &_1, "getoutputformat", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getencoding", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "buildcontenttype", NULL, 52, &of, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("rawData"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		RETURN_MM_MEMBER(getThis(), "rawData");
	}
	if (ZEPHIR_IS_STRING(&of, "json")) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_5$$4)) {
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_LONG(&_8$$5, 256);
			zephir_json_encode(&_7$$5, &result, zephir_get_intval(&_8$$5) );
			ZEPHIR_CONCAT_VSVS(return_value, &_6$$5, "(", &_7$$5, ")");
			RETURN_MM();
		}
		options$$4 = (256 | 64);
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$4, &_9$$4, "getrequest", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$4, &_10$$4, "getpretty", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$4)) {
			options$$4 = (options$$4 | 128);
		}
		ZVAL_LONG(&_12$$4, options$$4);
		zephir_json_encode(return_value, &result, zephir_get_intval(&_12$$4) );
		RETURN_MM();
	} else if (ZEPHIR_IS_STRING(&of, "xml")) {
		zephir_read_property(&_14$$7, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_15$$7, &_14$$7, "getencoding", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_CE_STATIC(phpple_util_xml_ce, "array2xml", &_13, 0, &result, &_15$$7);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("print_r", NULL, 27, &result, &__$true);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Send output
 */
PHP_METHOD(Phpple_Http_Response, send) {

	zend_bool _1, _7$$4;
	zval data, ob, _0, str$$3, _2$$3, _3$$3, outputHandlers$$4, _5$$4, _6$$4, _8$$5, handler$$6, *_9$$6, _10$$6, _11$$8, _13$$9, _14$$9, _15$$9, _16$$11, _17$$12, _18$$12, _19$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&ob);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&str$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&outputHandlers$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&handler$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfrheader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, this_ptr, "formatresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "output_buffering");
	ZEPHIR_CALL_FUNCTION(&ob, "ini_get", NULL, 53, &_0);
	zephir_check_call_status();
	_1 = zephir_is_true(&ob);
	if (_1) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_strtolower(&_0, &ob);
		_1 = !ZEPHIR_IS_STRING_IDENTICAL(&_0, "off");
	}
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&str$$3, "ob_get_clean", NULL, 50);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fast_trim(&_2$$3, &str$$3, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VV(&_3$$3, &_2$$3, &data);
		ZEPHIR_CPY_WRT(&data, &_3$$3);
	}
	if (zephir_is_true(&data)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		array_init(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "phpple.output.handler");
		ZEPHIR_CALL_CE_STATIC(&outputHandlers$$4, phpple_util_conf_ce, "get", &_4, 0, &_6$$4, &_5$$4);
		zephir_check_call_status();
		_7$$4 = zephir_is_true(&outputHandlers$$4);
		if (_7$$4) {
			_7$$4 = !(Z_TYPE_P(&outputHandlers$$4) == IS_ARRAY);
		}
		if (_7$$4) {
			ZEPHIR_INIT_VAR(&_8$$5);
			zephir_create_array(&_8$$5, 1, 0);
			zephir_array_fast_append(&_8$$5, &outputHandlers$$4);
			ZEPHIR_CPY_WRT(&outputHandlers$$4, &_8$$5);
		}
		if (zephir_is_true(&outputHandlers$$4)) {
			zephir_is_iterable(&outputHandlers$$4, 0, "phpple/Http/Response.zep", 491);
			if (Z_TYPE_P(&outputHandlers$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&outputHandlers$$4), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&handler$$6);
					ZVAL_COPY(&handler$$6, _9$$6);
					if (zephir_is_callable(&handler$$6)) {
						ZEPHIR_CALL_FUNCTION(&_11$$8, "call_user_func", &_12, 16, &handler$$6, &data);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&data, &_11$$8);
					} else {
						zephir_read_property(&_13$$9, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_14$$9);
						if (Z_TYPE_P(&handler$$6) == IS_ARRAY) {
							ZEPHIR_OBS_NVAR(&_14$$9);
							zephir_array_fetch_long(&_14$$9, &handler$$6, 1, PH_NOISY, "phpple/Http/Response.zep", 487);
						} else {
							ZEPHIR_CPY_WRT(&_14$$9, &handler$$6);
						}
						ZEPHIR_INIT_NVAR(&_15$$9);
						ZVAL_STRING(&_15$$9, "outouthandler:%s can't call");
						ZEPHIR_CALL_METHOD(NULL, &_13$$9, "warn", NULL, 0, &_15$$9, &_14$$9);
						zephir_check_call_status();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &outputHandlers$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$6, &outputHandlers$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&handler$$6, &outputHandlers$$4, "current", NULL, 0);
					zephir_check_call_status();
						if (zephir_is_callable(&handler$$6)) {
							ZEPHIR_CALL_FUNCTION(&_16$$11, "call_user_func", &_12, 16, &handler$$6, &data);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&data, &_16$$11);
						} else {
							zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&_18$$12);
							if (Z_TYPE_P(&handler$$6) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&_18$$12);
								zephir_array_fetch_long(&_18$$12, &handler$$6, 1, PH_NOISY, "phpple/Http/Response.zep", 487);
							} else {
								ZEPHIR_CPY_WRT(&_18$$12, &handler$$6);
							}
							ZEPHIR_INIT_NVAR(&_19$$12);
							ZVAL_STRING(&_19$$12, "outouthandler:%s can't call");
							ZEPHIR_CALL_METHOD(NULL, &_17$$12, "warn", NULL, 0, &_19$$12, &_18$$12);
							zephir_check_call_status();
						}
					ZEPHIR_CALL_METHOD(NULL, &outputHandlers$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&handler$$6);
		}
		zend_print_zval(&data, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "runtasks", NULL, 54);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add background task
 * @param callable task
 * @param array args
 * @return this
 */
PHP_METHOD(Phpple_Http_Response, addTask) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval args, _0;
	zval *task, task_sub, *args_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&task_sub);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &task, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, task);
	zephir_array_fast_append(&_0, &args);
	zephir_update_property_array_append(this_ptr, SL("tasks"), &_0);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phpple_Http_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("tasks"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("tasks"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("cookies"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("results"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("results"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("headers"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("outputs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("outputs"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

