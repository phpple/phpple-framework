
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Phpple_Filter_InputFilter) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Filter, InputFilter, phpple, filter_inputfilter, phpple_filter_inputfilter_method_entry, 0);

	zend_declare_property_null(phpple_filter_inputfilter_ce, SL("logger"), ZEND_ACC_PRIVATE);

	/**
	 * Request magic variables
	 *
	 * @var array
	 */
	zend_declare_property_null(phpple_filter_inputfilter_ce, SL("reqVars"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_class_implements(phpple_filter_inputfilter_ce, 1, phpple_filter_filterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Filter_InputFilter, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Filter_InputFilter, getLogger) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logger");

}

/**
 * @inheritDoc
 */
PHP_METHOD(Phpple_Filter_InputFilter, execute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, requestFile, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&requestFile);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parsecommon", NULL, 18, app);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseinternalvar", NULL, 19, app);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseparams", NULL, 20, app);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phpple.log.request");
	ZEPHIR_CALL_CE_STATIC(&requestFile, phpple_util_conf_ce, "get", &_0, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&requestFile)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "logrequest", NULL, 21, app, &requestFile);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Parse common
 *
 * @param Application app
 *
 * @throws Exception
 */
PHP_METHOD(Phpple_Filter_InputFilter, parseCommon) {

	zval url;
	zend_bool _1, _3, _5, _7, _34, _41, _9$$7, _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _SERVER, _COOKIE, _GET, request, _0, schema, _2, _4, _6, _8, host, rawUri, _20, _25, _31, _32, _33, baseUrl, _35, _36, query, _39, _40, _42, _10$$7, _12$$7, _13$$8, _14$$8, _15$$9, _16$$9, _18$$11, _19$$11, userip$$12, userips$$12, _21$$12, _22$$12, _23$$13, _24$$14, _26$$15, pos$$16, _27$$16, _28$$17, _29$$19, _30$$19, _37$$20, _38$$20, _43$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&rawUri);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&baseUrl);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&userip$$12);
	ZVAL_UNDEF(&userips$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&pos$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&url);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &_SERVER, SL("REQUEST_TIME"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 58);
	ZEPHIR_CALL_METHOD(NULL, &request, "setnow", NULL, 0, &_0);
	zephir_check_call_status();
	_1 = zephir_array_isset_string(&_SERVER, SL("HTTP_X_HTTPS"));
	if (_1) {
		zephir_array_fetch_string(&_2, &_SERVER, SL("HTTP_X_HTTPS"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 65);
		_3 = ZEPHIR_IS_STRING(&_2, "1");
		if (!(_3)) {
			zephir_array_fetch_string(&_4, &_SERVER, SL("HTTP_X_HTTPS"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 65);
			_3 = ZEPHIR_IS_STRING(&_4, "on");
		}
		_1 = _3;
	}
	_5 = zephir_array_isset_string(&_SERVER, SL("HTTPS"));
	if (_5) {
		zephir_array_fetch_string(&_6, &_SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 67);
		_7 = ZEPHIR_IS_STRING(&_6, "1");
		if (!(_7)) {
			zephir_array_fetch_string(&_8, &_SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 67);
			_7 = ZEPHIR_IS_STRING(&_8, "on");
		}
		_5 = _7;
	}
	if (zephir_array_isset_string(&_SERVER, SL("HTTP_X_FORWARDED_PROTO"))) {
		ZEPHIR_OBS_VAR(&schema);
		zephir_array_fetch_string(&schema, &_SERVER, SL("HTTP_X_FORWARDED_PROTO"), PH_NOISY, "phpple/Filter/InputFilter.zep", 64);
	} else if (_1) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "https");
	} else if (_5) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "https");
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "setschema", NULL, 0, &schema);
	zephir_check_call_status();
	if (zephir_array_isset_string(&_SERVER, SL("HTTP_X_FORWARDED_HOST"))) {
		ZEPHIR_OBS_VAR(&host);
		zephir_array_fetch_string(&host, &_SERVER, SL("HTTP_X_FORWARDED_HOST"), PH_NOISY, "phpple/Filter/InputFilter.zep", 75);
		if (zephir_array_isset_string(&_SERVER, SL("HTTP_X_FORWARDED_PORT"))) {
			_9$$7 = ZEPHIR_IS_STRING(&schema, "https");
			if (_9$$7) {
				zephir_array_fetch_string(&_10$$7, &_SERVER, SL("HTTP_X_FORWARDED_PORT"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 78);
				_9$$7 = !ZEPHIR_IS_LONG(&_10$$7, 443);
			}
			_11$$7 = ZEPHIR_IS_STRING(&schema, "http");
			if (_11$$7) {
				zephir_array_fetch_string(&_12$$7, &_SERVER, SL("HTTP_X_FORWARDED_PORT"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 80);
				_11$$7 = !ZEPHIR_IS_LONG(&_12$$7, 80);
			}
			if (_9$$7) {
				zephir_array_fetch_string(&_13$$8, &_SERVER, SL("HTTP_X_FORWARDED_PORT"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 79);
				ZEPHIR_INIT_VAR(&_14$$8);
				ZEPHIR_CONCAT_VSV(&_14$$8, &host, ":", &_13$$8);
				ZEPHIR_CPY_WRT(&host, &_14$$8);
			} else if (_11$$7) {
				zephir_array_fetch_string(&_15$$9, &_SERVER, SL("HTTP_X_FORWARDED_PORT"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 81);
				ZEPHIR_INIT_VAR(&_16$$9);
				ZEPHIR_CONCAT_VSV(&_16$$9, &host, ":", &_15$$9);
				ZEPHIR_CPY_WRT(&host, &_16$$9);
			}
		}
	} else if (zephir_array_isset_string(&_SERVER, SL("HTTP_HOST"))) {
		ZEPHIR_OBS_NVAR(&host);
		zephir_array_fetch_string(&host, &_SERVER, SL("HTTP_HOST"), PH_NOISY, "phpple/Filter/InputFilter.zep", 85);
	} else {
		ZEPHIR_INIT_VAR(&_18$$11);
		ZVAL_STRING(&_18$$11, "phpple.host");
		ZEPHIR_INIT_VAR(&_19$$11);
		ZVAL_STRING(&_19$$11, "");
		ZEPHIR_CALL_CE_STATIC(&host, phpple_util_conf_ce, "get", &_17, 0, &_18$$11, &_19$$11);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "sethost", NULL, 0, &host);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&rawUri);
	zephir_array_fetch_string(&rawUri, &_SERVER, SL("REQUEST_URI"), PH_NOISY, "phpple/Filter/InputFilter.zep", 90);
	ZEPHIR_CALL_METHOD(NULL, &request, "setrawuri", NULL, 0, &rawUri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &request, "setcookies", NULL, 0, &_COOKIE);
	zephir_check_call_status();
	zephir_array_fetch_string(&_20, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 94);
	ZEPHIR_CALL_METHOD(NULL, &request, "setmethod", NULL, 0, &_20);
	zephir_check_call_status();
	if (zephir_array_isset_string(&_SERVER, SL("HTTP_X_FORWARDED_FOR"))) {
		ZEPHIR_OBS_VAR(&userip$$12);
		zephir_array_fetch_string(&userip$$12, &_SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY, "phpple/Filter/InputFilter.zep", 98);
		ZEPHIR_INIT_VAR(&userips$$12);
		zephir_fast_explode_str(&userips$$12, SL(","), &userip$$12, LONG_MAX);
		ZEPHIR_INIT_VAR(&_21$$12);
		zephir_array_fetch_long(&_22$$12, &userips$$12, 0, PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 100);
		zephir_fast_strtolower(&_21$$12, &_22$$12);
		ZEPHIR_CALL_METHOD(NULL, &request, "setuserip", NULL, 0, &_21$$12);
		zephir_check_call_status();
	} else if (zephir_array_isset_string(&_SERVER, SL("HTTP_X_REAL_IP"))) {
		zephir_array_fetch_string(&_23$$13, &_SERVER, SL("HTTP_X_REAL_IP"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 102);
		ZEPHIR_CALL_METHOD(NULL, &request, "setuserip", NULL, 0, &_23$$13);
		zephir_check_call_status();
	} else if (zephir_array_isset_string(&_SERVER, SL("REMOTE_ADDR"))) {
		zephir_array_fetch_string(&_24$$14, &_SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 104);
		ZEPHIR_CALL_METHOD(NULL, &request, "setuserip", NULL, 0, &_24$$14);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_25, &_SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 107);
	ZEPHIR_CALL_METHOD(NULL, &request, "setclientip", NULL, 0, &_25);
	zephir_check_call_status();
	if (zephir_array_isset_string(&_GET, SL("route"))) {
		zephir_array_fetch_string(&_26$$15, &_GET, SL("route"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 111);
		ZEPHIR_CALL_METHOD(NULL, &request, "seturl", NULL, 0, &_26$$15);
		zephir_check_call_status();
		zephir_array_unset_string(&_GET, SL("route"), PH_SEPARATE);
	} else if (zephir_array_isset_string(&_SERVER, SL("REQUEST_URI"))) {
		ZEPHIR_INIT_VAR(&_27$$16);
		ZVAL_STRING(&_27$$16, "?");
		ZEPHIR_INIT_VAR(&pos$$16);
		zephir_fast_strpos(&pos$$16, &rawUri, &_27$$16, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos$$16)) {
			ZVAL_LONG(&_28$$17, 0);
			ZEPHIR_INIT_VAR(&url);
			zephir_substr(&url, &rawUri, 0 , zephir_get_intval(&pos$$16), 0);
		} else {
			zephir_get_strval(&url, &rawUri);
		}
	} else {
		ZEPHIR_INIT_VAR(&_29$$19);
		object_init_ex(&_29$$19, phpple_http_exception_ce);
		ZEPHIR_INIT_VAR(&_30$$19);
		ZVAL_STRING(&_30$$19, "phpple.u_notfound");
		ZEPHIR_CALL_METHOD(NULL, &_29$$19, "__construct", NULL, 1, &_30$$19);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_29$$19, "phpple/Filter/InputFilter.zep", 121);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_INIT_VAR(&_32);
	ZVAL_STRING(&_32, "/");
	zephir_fast_trim(&_31, &url, &_32, ZEPHIR_TRIM_LEFT);
	ZEPHIR_INIT_VAR(&_33);
	ZEPHIR_CONCAT_SV(&_33, "/", &_31);
	zephir_get_strval(&url, &_33);
	ZEPHIR_CALL_METHOD(&baseUrl, app, "getbaseurl", NULL, 0);
	zephir_check_call_status();
	_34 = zephir_is_true(&baseUrl);
	if (_34) {
		ZVAL_LONG(&_35, zephir_fast_strlen_ev(&baseUrl));
		ZEPHIR_CALL_FUNCTION(&_36, "strncmp", NULL, 22, &url, &baseUrl, &_35);
		zephir_check_call_status();
		_34 = ZEPHIR_IS_LONG_IDENTICAL(&_36, 0);
	}
	if (_34) {
		ZVAL_LONG(&_37$$20, (zephir_fast_strlen_ev(&baseUrl) - 1));
		ZEPHIR_INIT_VAR(&_38$$20);
		zephir_substr(&_38$$20, &url, zephir_get_intval(&_37$$20), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&url, &_38$$20);
		ZEPHIR_CALL_METHOD(NULL, &request, "setprefix", NULL, 0, &baseUrl);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "seturl", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&query, "http_build_query", NULL, 23, &_GET);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_39);
	if (zephir_is_true(&query)) {
		ZEPHIR_INIT_NVAR(&_39);
		ZEPHIR_CONCAT_SV(&_39, "?", &query);
	} else {
		ZEPHIR_INIT_NVAR(&_39);
		ZVAL_STRING(&_39, "");
	}
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_CONCAT_VV(&_40, &url, &_39);
	ZEPHIR_CALL_METHOD(NULL, &request, "seturi", NULL, 0, &_40);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &request, "setserverenvs", NULL, 0, &_SERVER);
	zephir_check_call_status();
	_41 = zephir_array_isset_string(&_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_41) {
		zephir_array_fetch_string(&_42, &_SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 137);
		_41 = ZEPHIR_IS_STRING_IDENTICAL(&_42, "XMLHttpRequest");
	}
	if (_41) {
		ZVAL_BOOL(&_43$$21, 1);
		ZEPHIR_CALL_METHOD(NULL, &request, "setisajax", NULL, 0, &_43$$21);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse internal variables
 *
 * @param Application app
 */
PHP_METHOD(Phpple_Filter_InputFilter, parseInternalVar) {

	zval _4$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _REQUEST, _GET, _POST, request, arr, _2, _0$$3, _1$$4, _3$$5, method$$6, _5$$6, _6$$7, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&method$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&arr, "array_merge", NULL, 24, &_REQUEST, &_GET, &_POST);
	zephir_check_call_status();
	if (zephir_array_isset_string(&arr, SL("_pretty"))) {
		ZVAL_BOOL(&_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &request, "setpretty", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&arr, SL("_if"))) {
		zephir_array_fetch_string(&_1$$4, &arr, SL("_if"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 156);
		ZEPHIR_CALL_METHOD(NULL, &request, "setinputformat", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, &request, "getoutputformat", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_string(&arr, SL("_of"))) {
		zephir_array_fetch_string(&_3$$5, &arr, SL("_of"), PH_NOISY | PH_READONLY, "phpple/Filter/InputFilter.zep", 160);
		ZEPHIR_CALL_METHOD(NULL, &request, "setoutputformat", NULL, 0, &_3$$5);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_STRING(&_2, "default")) {
		ZEPHIR_CALL_METHOD(&method$$6, &request, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_create_array(&_4$$6, 3, 0);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "POST");
		zephir_array_fast_append(&_4$$6, &_5$$6);
		ZEPHIR_INIT_NVAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "PUT");
		zephir_array_fast_append(&_4$$6, &_5$$6);
		ZEPHIR_INIT_NVAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "DELETE");
		zephir_array_fast_append(&_4$$6, &_5$$6);
		if (zephir_fast_in_array(&method$$6, &_4$$6)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "json");
			ZEPHIR_CALL_METHOD(NULL, &request, "setoutputformat", NULL, 0, &_6$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_7$$8);
			ZVAL_STRING(&_7$$8, "default");
			ZEPHIR_CALL_METHOD(NULL, &request, "setoutputformat", NULL, 0, &_7$$8);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse params
 *
 * @param app
 */
PHP_METHOD(Phpple_Filter_InputFilter, parseParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _GET, _POST, __$true, request, arr, key, _5, *_6, _7, _8, _9, keys$$3, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, puts$$6, _10$$6, json$$7, _11$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&keys$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&puts$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&json$$7);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arr);
	zephir_fast_array_merge(&arr, &_GET, &_POST);
	if (zephir_fast_count_int(&arr) != (zephir_fast_count_int(&_GET) + zephir_fast_count_int(&_POST))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_array_keys(&_0$$3, &_GET);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_array_keys(&_1$$3, &_POST);
		ZEPHIR_CALL_FUNCTION(&keys$$3, "array_intersect", NULL, 25, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_join_str(&_3$$3, SL(","), &keys$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "_GET & _POST have same variables overided:%s");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "warn", NULL, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_5, phpple_filter_inputfilter_ce, SL("reqVars"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phpple/Filter/InputFilter.zep", 192);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _6);
			zephir_array_unset(&arr, &key, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_5, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_unset(&arr, &key, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&_8, &request, "getinputformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "json");
	if (ZEPHIR_IS_IDENTICAL(&_9, &_8)) {
		ZEPHIR_INIT_VAR(&_10$$6);
		ZVAL_STRING(&_10$$6, "php://input");
		ZEPHIR_INIT_VAR(&puts$$6);
		zephir_file_get_contents(&puts$$6, &_10$$6);
		if (zephir_is_true(&puts$$6)) {
			ZEPHIR_INIT_VAR(&json$$7);
			zephir_json_decode(&json$$7, &puts$$6, zephir_get_intval(&__$true) );
			if (Z_TYPE_P(&json$$7) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&_11$$8);
				if (zephir_is_true(&arr)) {
					ZEPHIR_INIT_NVAR(&_11$$8);
					zephir_fast_array_merge(&_11$$8, &arr, &json$$7);
				} else {
					ZEPHIR_CPY_WRT(&_11$$8, &json$$7);
				}
				ZEPHIR_CPY_WRT(&arr, &_11$$8);
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "setinputs", NULL, 0, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Record request data
 *
 * @param Application app
 * @param  string requestFile
 */
PHP_METHOD(Phpple_Filter_InputFilter, logRequest) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval requestFile;
	zval *app, app_sub, *requestFile_param = NULL, __$true, request, headers, key, value, _0, *_1, _2, file, _12, _13, data, keyarr, _15, *_16, _17, out, _20, _21, _22, _23, _24, _25, _26, _5$$3, _6$$3, _7$$3, _9$$5, _10$$5, _11$$5, _18$$8, _19$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keyarr);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&requestFile);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &app, &requestFile_param);

	zephir_get_strval(&requestFile, requestFile_param);


	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_CALL_METHOD(&_0, &request, "getserverenvs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phpple/Filter/InputFilter.zep", 220);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "HTTP_");
			ZVAL_LONG(&_6$$3, 5);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "strncmp", &_8, 22, &_5$$3, &key, &_6$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$3, 0)) {
				zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "HTTP_");
				ZVAL_LONG(&_10$$5, 5);
				ZEPHIR_CALL_FUNCTION(&_11$$5, "strncmp", &_8, 22, &_9$$5, &key, &_10$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$5, 0)) {
					zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "log");
	ZEPHIR_CALL_METHOD(&_12, app, "getdir", NULL, 0, &_13);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VV(&file, &_12, &requestFile);
	ZEPHIR_CALL_METHOD(&data, &request, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	array_init(&_13);
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, "phpple.log.requestFilter");
	ZEPHIR_CALL_CE_STATIC(&keyarr, phpple_util_conf_ce, "get", &_14, 0, &_15, &_13);
	zephir_check_call_status();
	zephir_is_iterable(&keyarr, 0, "phpple/Filter/InputFilter.zep", 229);
	if (Z_TYPE_P(&keyarr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keyarr), _16)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _16);
			if (zephir_array_isset(&data, &key)) {
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "[removed]");
				zephir_array_update_zval(&data, &key, &_18$$8, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keyarr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_17, &keyarr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &keyarr, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&data, &key)) {
					ZEPHIR_INIT_NVAR(&_19$$10);
					ZVAL_STRING(&_19$$10, "[removed]");
					zephir_array_update_zval(&data, &key, &_19$$10, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keyarr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&out);
	zephir_create_array(&out, 4, 0);
	ZEPHIR_CALL_METHOD(&_20, app, "getappid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_21, &request, "geturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, &request, "getnow", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_23, "date", NULL, 26, &_15, &_22);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_CONCAT_VSVSV(&_24, &_20, ":", &_21, ":", &_23);
	zephir_array_update_string(&out, SL("info"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_25, &request, "getcookies", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&out, SL("cookie"), &_25, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&out, SL("header"), &headers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&out, SL("data"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_25, "print_r", NULL, 27, &out, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_26, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 28, &file, &_25, &_26);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Phpple_Filter_InputFilter(TSRMLS_D) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 10, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_if");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_ie");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_d");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_of");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_oe");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "route");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_e");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_try");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_ep");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_pretty");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(phpple_filter_inputfilter_ce, ZEND_STRL("reqVars"), &_0);
	ZEPHIR_MM_RESTORE();

}

