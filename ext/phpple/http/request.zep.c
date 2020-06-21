
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
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phpple_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Http, Request, phpple, http_request, phpple_http_request_method_entry, 0);

	zend_declare_property_null(phpple_http_request_ce, SL("url"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("uri"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("rawUri"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("prefix"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("method"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("serverEnvs"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("inputs"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("datas"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("app"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("logger"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_http_request_ce, SL("now"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("schema"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("host"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("userIp"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("clientIp"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("cookies"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(phpple_http_request_ce, SL("isAjax"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_bool(phpple_http_request_ce, SL("pretty"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("inputFormat"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phpple_http_request_ce, SL("outputFormat"), ZEND_ACC_PRIVATE);

	phpple_http_request_ce->create_object = zephir_init_properties_Phpple_Http_Request;

	zend_class_implements(phpple_http_request_ce, 1, phpple_requestinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Http_Request, getUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "url");

}

PHP_METHOD(Phpple_Http_Request, setUrl) {

	zval *url, url_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &url);



	zephir_update_property_zval(this_ptr, ZEND_STRL("url"), url);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uri");

}

PHP_METHOD(Phpple_Http_Request, setUri) {

	zval *uri, uri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &uri);



	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), uri);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, setRawUri) {

	zval *rawUri, rawUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawUri_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &rawUri);



	zephir_update_property_zval(this_ptr, ZEND_STRL("rawUri"), rawUri);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getRawUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "rawUri");

}

PHP_METHOD(Phpple_Http_Request, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

PHP_METHOD(Phpple_Http_Request, setPrefix) {

	zval *prefix, prefix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &prefix);



	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), prefix);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Phpple_Http_Request, setMethod) {

	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &method);



	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), method);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, setServerEnvs) {

	zval *serverEnvs, serverEnvs_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverEnvs_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &serverEnvs);



	zephir_update_property_zval(this_ptr, ZEND_STRL("serverEnvs"), serverEnvs);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getServerEnvs) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serverEnvs");

}

PHP_METHOD(Phpple_Http_Request, setInputs) {

	zval *inputs, inputs_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputs_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &inputs);



	zephir_update_property_zval(this_ptr, ZEND_STRL("inputs"), inputs);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getInputs) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "inputs");

}

PHP_METHOD(Phpple_Http_Request, setDatas) {

	zval *datas, datas_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datas_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &datas);



	zephir_update_property_zval(this_ptr, ZEND_STRL("datas"), datas);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getDatas) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "datas");

}

PHP_METHOD(Phpple_Http_Request, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, setNow) {

	zval *now, now_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&now_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &now);



	zephir_update_property_zval(this_ptr, ZEND_STRL("now"), now);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getNow) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "now");

}

PHP_METHOD(Phpple_Http_Request, setSchema) {

	zval *schema, schema_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schema_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &schema);



	zephir_update_property_zval(this_ptr, ZEND_STRL("schema"), schema);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getSchema) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "schema");

}

PHP_METHOD(Phpple_Http_Request, setHost) {

	zval *host, host_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &host);



	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), host);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getHost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "host");

}

PHP_METHOD(Phpple_Http_Request, setUserIp) {

	zval *userIp, userIp_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userIp_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &userIp);



	zephir_update_property_zval(this_ptr, ZEND_STRL("userIp"), userIp);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getUserIp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "userIp");

}

PHP_METHOD(Phpple_Http_Request, setClientIp) {

	zval *clientIp, clientIp_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&clientIp_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &clientIp);



	zephir_update_property_zval(this_ptr, ZEND_STRL("clientIp"), clientIp);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getClientIp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientIp");

}

PHP_METHOD(Phpple_Http_Request, setCookies) {

	zval *cookies, cookies_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &cookies);



	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), cookies);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

PHP_METHOD(Phpple_Http_Request, setIsAjax) {

	zval *isAjax, isAjax_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&isAjax_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &isAjax);



	zephir_update_property_zval(this_ptr, ZEND_STRL("isAjax"), isAjax);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getIsAjax) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isAjax");

}

PHP_METHOD(Phpple_Http_Request, setPretty) {

	zval *pretty, pretty_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pretty_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pretty);



	zephir_update_property_zval(this_ptr, ZEND_STRL("pretty"), pretty);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getPretty) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pretty");

}

PHP_METHOD(Phpple_Http_Request, setInputFormat) {

	zval *inputFormat, inputFormat_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputFormat_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &inputFormat);



	zephir_update_property_zval(this_ptr, ZEND_STRL("inputFormat"), inputFormat);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getInputFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "inputFormat");

}

PHP_METHOD(Phpple_Http_Request, setOutputFormat) {

	zval *outputFormat, outputFormat_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&outputFormat_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &outputFormat);



	zephir_update_property_zval(this_ptr, ZEND_STRL("outputFormat"), outputFormat);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Http_Request, getOutputFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "outputFormat");

}

PHP_METHOD(Phpple_Http_Request, __construct) {

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
 * Whether have the attribute named key
 */
PHP_METHOD(Phpple_Http_Request, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_0, &key));

}

/**
 * Reset
 */
PHP_METHOD(Phpple_Http_Request, reset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, __$true, __$false, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), &__$null);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("inputs"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("datas"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), &_2);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("pretty"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("pretty"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch the request data by key
 *
 * @param  string key Name of the param
 * @param null default
 *
 * @return mixed|null
 */
PHP_METHOD(Phpple_Http_Request, get) {

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 70);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defval, 1, 0);
	RETURN_MM();

}

/**
 * Fetch a lot of _GET data
 *
 * @param \string[] ...keys
 *
 * @return array
 */
PHP_METHOD(Phpple_Http_Request, gets) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, keys, ret, key, *_0, _1, _2$$3, _3$$4, _4$$4, _5$$6, _6$$7, _7$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&keys);
	zephir_get_args(&keys);
	ZEPHIR_INIT_VAR(&ret);
	array_init(&ret);
	zephir_is_iterable(&keys, 0, "phpple/Http/Request.zep", 93);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_key_exists(&_2$$3, &key)) {
				zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_4$$4, &_3$$4, &key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 88);
				zephir_array_update_zval(&ret, &key, &_4$$4, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&ret, &key, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_key_exists(&_5$$6, &key)) {
					zephir_read_property(&_6$$7, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_7$$7, &_6$$7, &key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 88);
					zephir_array_update_zval(&ret, &key, &_7$$7, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&ret, &key, &__$null, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&ret);

}

/**
 * Set user data by key
 *
 * @param string key
 * @param        value
 * @return this
 */
PHP_METHOD(Phpple_Http_Request, setData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *val, val_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &val);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("datas"), &key, val);
	RETURN_THIS();

}

/**
 * Fetch user data by key
 *
 * @param string key
 * @param null default
 *
 * @return mixed|null
 */
PHP_METHOD(Phpple_Http_Request, getData) {

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("datas"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("datas"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 120);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defval, 1, 0);
	RETURN_MM();

}

/**
 * Fetch the cookie by key
 *
 * @param string key key of cookie
 * @param string default default value
 *
 * @return string
 */
PHP_METHOD(Phpple_Http_Request, getCookie) {

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 136);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defval, 1, 0);
	RETURN_MM();

}

/**
 * Get the header value,it will become uppercase, and add the prefix "HTTP_'
 *
 * @param string key key of the header
 * @param string default default value
 *
 * @return string
 */
PHP_METHOD(Phpple_Http_Request, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defval = NULL, defval_sub, __$null, _0, _1, name, _5, _6, _2$$3, _3$$3, _4$$3, _7$$4, _8$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defval_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defval);

	zephir_get_strval(&key, key_param);
	if (!defval) {
		defval = &defval_sub;
		defval = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &key, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "_");
		zephir_fast_str_replace(&_2$$3, &_3$$3, &_4$$3, &key);
		zephir_get_strval(&key, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strtoupper(&_5, &key);
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_SV(&name, "HTTP_", &_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("serverEnvs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_6, &name)) {
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("serverEnvs"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$4, &_7$$4, &name, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 157);
		RETURN_CTOR(&_8$$4);
	}
	RETVAL_ZVAL(defval, 1, 0);
	RETURN_MM();

}

/**
 * Fetch the upload file
 *
 * @param string key 名称
 *
 * @return array | null
 */
PHP_METHOD(Phpple_Http_Request, getFile) {

	zval *key, key_sub, _FILES, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&_0$$3);

	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params_without_memory_grow(1, 0, &key);



	if (zephir_array_isset(&_FILES, key)) {
		zephir_array_fetch(&_0$$3, &_FILES, key, PH_NOISY | PH_READONLY, "phpple/Http/Request.zep", 172);
		RETURN_CTORW(&_0$$3);
	}
	RETURN_NULL();

}

zend_object *zephir_init_properties_Phpple_Http_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("datas"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("datas"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("inputs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("inputs"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("serverEnvs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("serverEnvs"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

