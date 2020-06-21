
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
* Mock the http request
*/
ZEPHIR_INIT_CLASS(Phpple_Helper_RequestBuilder) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Helper, RequestBuilder, phpple, helper_requestbuilder, phpple_helper_requestbuilder_method_entry, 0);

	zend_declare_property_null(phpple_helper_requestbuilder_ce, SL("defaultOptions"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Build HTTP get request
 * @param string url
 * @param array headers
 */
PHP_METHOD(Phpple_Helper_RequestBuilder, buildGetRequest) {

	zend_string *_5, *_9;
	zend_ulong _4, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *url_param = NULL, headers, *headers_param = NULL, _SERVER, _GET, _0, key, val, *_2, _3, query, args, *_6, _7;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 1, &url_param, &headers_param);

	zephir_get_strval(&url, url_param);
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_CALL_SELF(&_0, "buildheaders", &_1, 37, &url, &headers);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_is_iterable(&headers, 0, "phpple/Helper/RequestBuilder.zep", 42);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _2);
			zephir_array_update_zval(&_SERVER, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &headers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_SERVER, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_OBS_VAR(&query);
	zephir_array_fetch_string(&query, &headers, SL("QUERY_STRING"), PH_NOISY, "phpple/Helper/RequestBuilder.zep", 42);
	ZEPHIR_MAKE_REF(&args);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 38, &query, &args);
	ZEPHIR_UNREF(&args);
	zephir_check_call_status();
	zephir_is_iterable(&args, 0, "phpple/Helper/RequestBuilder.zep", 47);
	if (Z_TYPE_P(&args) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _6);
			zephir_array_update_zval(&_GET, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &args, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &args, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &args, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &args, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_GET, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &args, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Build HTTP post request
 * @param url
 * @param data
 * @param array headers
 */
PHP_METHOD(Phpple_Helper_RequestBuilder, buildPostRequest) {

	zend_string *_5, *_10, *_14;
	zend_ulong _4, _9, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval data;
	zval *url_param = NULL, *data_param = NULL, headers, *headers_param = NULL, _SERVER, _GET, _POST, _0, key, val, *_2, _3, _6, query, args, *_7, _8, *_11, _12;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 1, &url_param, &data_param, &headers_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&data, data_param);
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_CALL_SELF(&_0, "buildheaders", &_1, 37, &url, &headers);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&headers, &_0);
	zephir_is_iterable(&headers, 0, "phpple/Helper/RequestBuilder.zep", 62);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _2);
			zephir_array_update_zval(&_SERVER, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &headers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_SERVER, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "POST");
	zephir_array_update_string(&_SERVER, SL("REQUEST_METHOD"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&query);
	zephir_array_fetch_string(&query, &headers, SL("QUERY_STRING"), PH_NOISY, "phpple/Helper/RequestBuilder.zep", 65);
	ZEPHIR_MAKE_REF(&args);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 38, &query, &args);
	ZEPHIR_UNREF(&args);
	zephir_check_call_status();
	zephir_is_iterable(&args, 0, "phpple/Helper/RequestBuilder.zep", 72);
	if (Z_TYPE_P(&args) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _9, _10, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&key, _10);
			} else {
				ZVAL_LONG(&key, _9);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _7);
			zephir_array_update_zval(&_GET, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &args, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &args, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &args, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &args, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_GET, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &args, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	zephir_is_iterable(&data, 0, "phpple/Helper/RequestBuilder.zep", 75);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _13, _14, _11)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_14 != NULL) { 
				ZVAL_STR_COPY(&key, _14);
			} else {
				ZVAL_LONG(&key, _13);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _11);
			zephir_array_update_zval(&_POST, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_12, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &data, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_POST, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Build the headers
 * @param string uri
 * @param array headers
 */
PHP_METHOD(Phpple_Helper_RequestBuilder, buildHeaders) {

	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval headers;
	zval *uri_param = NULL, *headers_param = NULL, defaultOptions, _0, info, _1, _2, _3, key, val, *_5, _6, _4$$3;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&defaultOptions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &headers_param);

	zephir_get_strval(&uri, uri_param);
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phpple_helper_requestbuilder_ce, SL("defaultOptions"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&defaultOptions, &_0);
	ZEPHIR_CALL_FUNCTION(&info, "parse_url", NULL, 39, &uri);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &info, SL("path"), PH_NOISY | PH_READONLY, "phpple/Helper/RequestBuilder.zep", 88);
	zephir_array_update_string(&defaultOptions, SL("REQUEST_URI"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_update_string(&defaultOptions, SL("QUERY_STRING"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, &info, SL("query"), PH_NOISY | PH_READONLY, "phpple/Helper/RequestBuilder.zep", 90);
	if (zephir_is_true(&_3)) {
		zephir_array_fetch_string(&_4$$3, &info, SL("query"), PH_NOISY | PH_READONLY, "phpple/Helper/RequestBuilder.zep", 91);
		zephir_array_update_string(&defaultOptions, SL("QUERY_STRING"), &_4$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_is_iterable(&headers, 0, "phpple/Helper/RequestBuilder.zep", 97);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _5);
			zephir_array_update_zval(&defaultOptions, &key, &val, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &headers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&defaultOptions, &key, &val, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&defaultOptions);

}

void zephir_init_static_properties_Phpple_Helper_RequestBuilder(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 18, 0);
	add_assoc_stringl_ex(&_0, SL("DOCUMENT_ROOT"), SL("/Users/ronnie/test/web"));
	add_assoc_stringl_ex(&_0, SL("REMOTE_ADDR"), SL("::1"));
	add_assoc_stringl_ex(&_0, SL("REMOTE_PORT"), SL("54210"));
	add_assoc_stringl_ex(&_0, SL("SERVER_SOFTWARE"), SL("Phpple Framework"));
	add_assoc_stringl_ex(&_0, SL("SERVER_PROTOCOL"), SL("HTTP/1.1"));
	add_assoc_stringl_ex(&_0, SL("SERVER_NAME"), SL("localhost"));
	add_assoc_stringl_ex(&_0, SL("SERVER_PORT"), SL("80"));
	add_assoc_stringl_ex(&_0, SL("REQUEST_URI"), SL("/"));
	add_assoc_stringl_ex(&_0, SL("REQUEST_METHOD"), SL("GET"));
	add_assoc_stringl_ex(&_0, SL("SCRIPT_NAME"), SL("/index.php"));
	add_assoc_stringl_ex(&_0, SL("SCRIPT_FILENAME"), SL("/Users/ronnie/test/web/index.php"));
	add_assoc_stringl_ex(&_0, SL("PHP_SELF"), SL("/index.php"));
	add_assoc_stringl_ex(&_0, SL("QUERY_STRING"), SL(""));
	add_assoc_stringl_ex(&_0, SL("HTTP_HOST"), SL("localhost:80"));
	add_assoc_stringl_ex(&_0, SL("HTTP_USER_AGENT"), SL("Phpple Php Framework Request"));
	add_assoc_stringl_ex(&_0, SL("HTTP_ACCEPT"), SL("*/*"));
	add_assoc_long_ex(&_0, SL("REQUEST_TIME_FLOAT"), 0);
	add_assoc_long_ex(&_0, SL("REQUEST_TIME"), 0);
	zephir_update_static_property_ce(phpple_helper_requestbuilder_ce, ZEND_STRL("defaultOptions"), &_0);
	ZEPHIR_MM_RESTORE();

}

