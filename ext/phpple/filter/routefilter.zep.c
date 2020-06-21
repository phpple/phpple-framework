
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
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phpple_Filter_RouteFilter) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Filter, RouteFilter, phpple, filter_routefilter, phpple_filter_routefilter_method_entry, 0);

	zend_declare_property_null(phpple_filter_routefilter_ce, SL("protectedMethods"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phpple_filter_routefilter_ce, SL("methodExt"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phpple_filter_routefilter_ce, SL("logger"), ZEND_ACC_PROTECTED);

	phpple_filter_routefilter_ce->create_object = zephir_init_properties_Phpple_Filter_RouteFilter;
	zephir_declare_class_constant_string(phpple_filter_routefilter_ce, SL("METHOD_BEFORE"), "_before");

	zephir_declare_class_constant_string(phpple_filter_routefilter_ce, SL("METHOD_AFTER"), "_after");

	zephir_declare_class_constant_string(phpple_filter_routefilter_ce, SL("DEFAULT_ACTION"), "index");

	zephir_declare_class_constant_string(phpple_filter_routefilter_ce, SL("CONTROLLER_FILE"), "Controller.php");

	zend_class_implements(phpple_filter_routefilter_ce, 1, phpple_filter_filterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phpple_Filter_RouteFilter, setLogger) {

	zval *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	RETURN_THISW();

}

PHP_METHOD(Phpple_Filter_RouteFilter, getLogger) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "logger");

}

PHP_METHOD(Phpple_Filter_RouteFilter, __construct) {

	zval _0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "phpple.methodExt");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_CE_STATIC(&_0, phpple_util_conf_ce, "get", &_1, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodExt"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @inheritDoc
 */
PHP_METHOD(Phpple_Filter_RouteFilter, execute) {

	zval _11, _16, _9$$3, _14$$4, _18$$5;
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, request, url, info, clsName, path, func, ctl, _0, _2, _3, _4, _5, _6, methodInfo, mainMethod, args, _12, _7$$3, _10$$3, _13$$4, _15$$4, _17$$5, _19$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&clsName);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&ctl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&methodInfo);
	ZVAL_UNDEF(&mainMethod);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_18$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&url, &request, "geturl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&info, this_ptr, "getctlandfunc", NULL, 29, &url, app);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&clsName);
	zephir_array_fetch_long(&clsName, &info, 0, PH_NOISY, "phpple/Filter/RouteFilter.zep", 35);
	ZEPHIR_OBS_VAR(&path);
	zephir_array_fetch_long(&path, &info, 1, PH_NOISY, "phpple/Filter/RouteFilter.zep", 36);
	ZEPHIR_OBS_VAR(&func);
	zephir_array_fetch_long(&func, &info, 2, PH_NOISY, "phpple/Filter/RouteFilter.zep", 37);
	if (zephir_require_zval(&path) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&ctl);
	zephir_fetch_safe_class(&_0, &clsName);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&ctl, _1);
	if (zephir_has_constructor(&ctl)) {
		ZEPHIR_CALL_METHOD(NULL, &ctl, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, app, "getlogger", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setlogger", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, app, "getdebug", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setdebug", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, app, "getappid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setappid", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setrequest", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, app, "getresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setresponse", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&methodInfo, this_ptr, "buildmethod", NULL, 30, &ctl, &func, app);
	zephir_check_call_status();
	if (!(zephir_is_true(&methodInfo))) {
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 2, 0);
		add_assoc_stringl_ex(&_9$$3, SL("detail"), SL("func not found"));
		zephir_array_update_string(&_9$$3, SL("func"), &func, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "phpple.u_notfound");
		ZEPHIR_CALL_CE_STATIC(&_7$$3, phpple_http_exception_ce, "withparams", &_8, 0, &_10$$3, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phpple/Filter/RouteFilter.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&mainMethod);
	zephir_array_fetch_long(&mainMethod, &methodInfo, 0, PH_NOISY, "phpple/Filter/RouteFilter.zep", 56);
	ZEPHIR_OBS_VAR(&args);
	zephir_array_fetch_long(&args, &methodInfo, 1, PH_NOISY, "phpple/Filter/RouteFilter.zep", 57);
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setmethod", NULL, 0, &func);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setpath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &ctl, "setargs", NULL, 0, &args);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0);
	zephir_array_fast_append(&_11, &ctl);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "_before");
	zephir_array_fast_append(&_11, &_12);
	if (zephir_is_callable(&_11)) {
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_INIT_VAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0);
		zephir_array_fast_append(&_14$$4, &ctl);
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "_before");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_CALL_USER_FUNC(&_13$$4, &_14$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &mainMethod, "invokeargs", NULL, 0, &ctl, &args);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 2, 0);
	zephir_array_fast_append(&_16, &ctl);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRING(&_12, "_after");
	zephir_array_fast_append(&_16, &_12);
	if (zephir_is_callable(&_16)) {
		ZEPHIR_INIT_VAR(&_17$$5);
		ZEPHIR_INIT_VAR(&_18$$5);
		zephir_create_array(&_18$$5, 2, 0);
		zephir_array_fast_append(&_18$$5, &ctl);
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_STRING(&_19$$5, "_after");
		zephir_array_fast_append(&_18$$5, &_19$$5);
		ZEPHIR_CALL_USER_FUNC(&_17$$5, &_18$$5);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Get controller and method
 * @return [clsName, path, func]
 */
PHP_METHOD(Phpple_Filter_RouteFilter, getCtlAndFunc) {

	zend_bool _11, _9$$3, _10$$5;
	zend_string *_8;
	zend_ulong _7;
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, segNum;
	zval *url_param = NULL, *app, app_sub, _0, _1, segs, _2, _4, seg, *_5, _6, _12, _13, ctlRoot, _16, _17, _18, path, func, _20, _36, _39, _40, _41, _42, _43, _44, _14$$7, _15$$7, _24$$9, _26$$10, rootSeg$$12, _27$$12, _28$$12, _29$$12, _30$$12, _31$$12, _32$$12, _33$$12, _34$$13, _35$$13, _37$$14, _38$$14;
	zval url, fullpath, _19, clsName, _22$$8, _23$$9, _25$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&fullpath);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&clsName);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&segs);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&seg);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&ctlRoot);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&rootSeg$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &app);

	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &url, &_1, ZEPHIR_TRIM_BOTH);
	zephir_get_strval(&url, &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_explode_str(&_2, SL("/"), &url, LONG_MAX);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_FUNCTION(&segs, "array_diff", NULL, 31, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	zephir_is_iterable(&segs, 0, "phpple/Filter/RouteFilter.zep", 93);
	if (Z_TYPE_P(&segs) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&segs), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&_4);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&_4, _8);
			} else {
				ZVAL_LONG(&_4, _7);
			}
			ZEPHIR_INIT_NVAR(&seg);
			ZVAL_COPY(&seg, _5);
			_9$$3 = ZEPHIR_IS_STRING(&seg, "..");
			if (!(_9$$3)) {
				_9$$3 = ZEPHIR_IS_STRING(&seg, ".");
			}
			if (_9$$3) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_http_exception_ce, "router.u_illegalRouter", "phpple/Filter/RouteFilter.zep", 90);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &segs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &segs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_4, &segs, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&seg, &segs, "current", NULL, 0);
			zephir_check_call_status();
				_10$$5 = ZEPHIR_IS_STRING(&seg, "..");
				if (!(_10$$5)) {
					_10$$5 = ZEPHIR_IS_STRING(&seg, ".");
				}
				if (_10$$5) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_http_exception_ce, "router.u_illegalRouter", "phpple/Filter/RouteFilter.zep", 90);
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &segs, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&seg);
	ZEPHIR_INIT_NVAR(&_4);
	segNum = zephir_fast_count_int(&segs);
	_11 = segNum > 0;
	if (_11) {
		zephir_array_fetch_long(&_12, &segs, (segNum - 1), PH_NOISY | PH_READONLY, "phpple/Filter/RouteFilter.zep", 95);
		zephir_read_property(&_13, this_ptr, ZEND_STRL("protectedMethods"), PH_NOISY_CC | PH_READONLY);
		_11 = zephir_fast_in_array(&_12, &_13);
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_14$$7);
		object_init_ex(&_14$$7, phpple_http_exception_ce);
		ZEPHIR_INIT_VAR(&_15$$7);
		ZVAL_STRING(&_15$$7, "phpple.u_notfound");
		ZEPHIR_CALL_METHOD(NULL, &_14$$7, "__construct", NULL, 1, &_15$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$7, "phpple/Filter/RouteFilter.zep", 96);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "app/controller");
	ZEPHIR_CALL_METHOD(&ctlRoot, app, "getdir", NULL, 0, &_16);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_16);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "/");
	zephir_fast_join(&_16, &_17, &segs);
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VV(&_18, &ctlRoot, &_16);
	zephir_get_strval(&fullpath, &_18);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_VSS(&_19, &fullpath, "/", "Controller.php");
	ZEPHIR_CALL_FUNCTION(&_20, "is_readable", &_21, 3, &_19);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_INIT_VAR(&_22$$8);
		ZEPHIR_CONCAT_VSS(&_22$$8, &fullpath, "/", "Controller.php");
		ZEPHIR_CPY_WRT(&path, &_22$$8);
		ZEPHIR_INIT_VAR(&func);
		ZVAL_STRING(&func, "index");
	} else {
		ZEPHIR_INIT_VAR(&_23$$9);
		ZEPHIR_CONCAT_VSSSS(&_23$$9, &fullpath, "/", "index", "/", "Controller.php");
		ZEPHIR_CALL_FUNCTION(&_24$$9, "is_readable", &_21, 3, &_23$$9);
		zephir_check_call_status();
		if (zephir_is_true(&_24$$9)) {
			ZEPHIR_INIT_VAR(&_25$$10);
			ZEPHIR_CONCAT_VSSSS(&_25$$10, &fullpath, "/", "index", "/", "Controller.php");
			ZEPHIR_CPY_WRT(&path, &_25$$10);
			ZEPHIR_INIT_NVAR(&func);
			ZVAL_STRING(&func, "index");
			ZEPHIR_INIT_VAR(&_26$$10);
			ZVAL_STRING(&_26$$10, "index");
			ZEPHIR_MAKE_REF(&segs);
			ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 12, &segs, &_26$$10);
			ZEPHIR_UNREF(&segs);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&path);
			if (segNum > 0) {
				ZVAL_LONG(&_27$$12, 0);
				ZVAL_LONG(&_28$$12, (segNum - 1));
				ZEPHIR_CALL_FUNCTION(&rootSeg$$12, "array_slice", NULL, 32, &segs, &_27$$12, &_28$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_29$$12);
				ZEPHIR_INIT_VAR(&_30$$12);
				ZEPHIR_INIT_VAR(&_31$$12);
				ZVAL_STRING(&_31$$12, "/");
				zephir_fast_join(&_30$$12, &_31$$12, &rootSeg$$12);
				ZEPHIR_INIT_VAR(&_32$$12);
				ZEPHIR_CONCAT_VV(&_32$$12, &ctlRoot, &_30$$12);
				ZEPHIR_INIT_VAR(&_33$$12);
				ZVAL_STRING(&_33$$12, "/");
				zephir_fast_trim(&_29$$12, &_32$$12, &_33$$12, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_CONCAT_VSS(&path, &_29$$12, "/", "Controller.php");
				ZEPHIR_OBS_NVAR(&func);
				zephir_array_fetch_long(&func, &segs, (segNum - 1), PH_NOISY, "phpple/Filter/RouteFilter.zep", 115);
				ZEPHIR_MAKE_REF(&segs);
				ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 33, &segs);
				ZEPHIR_UNREF(&segs);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_34$$13);
				ZEPHIR_INIT_VAR(&_35$$13);
				ZVAL_STRING(&_35$$13, "/");
				zephir_fast_trim(&_34$$13, &ctlRoot, &_35$$13, ZEPHIR_TRIM_RIGHT);
				ZEPHIR_CONCAT_VSS(&path, &_34$$13, "/", "Controller.php");
				ZEPHIR_INIT_NVAR(&func);
				ZVAL_STRING(&func, "index");
			}
		}
	}
	ZEPHIR_CALL_FUNCTION(&_36, "is_readable", &_21, 3, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_36)) {
		ZEPHIR_INIT_VAR(&_37$$14);
		object_init_ex(&_37$$14, phpple_http_exception_ce);
		ZEPHIR_INIT_VAR(&_38$$14);
		ZEPHIR_CONCAT_SSV(&_38$$14, "phpple.u_notfound", " path not readable:", &path);
		ZEPHIR_CALL_METHOD(NULL, &_37$$14, "__construct", NULL, 1, &_38$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_37$$14, "phpple/Filter/RouteFilter.zep", 126);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_39);
	ZVAL_STRING(&_39, "/");
	ZEPHIR_CALL_FUNCTION(&_40, "ucwords", NULL, 17, &path, &_39);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&path, &_40);
	ZEPHIR_INIT_NVAR(&_39);
	ZVAL_STRING(&_39, "ucfirst");
	ZEPHIR_CALL_FUNCTION(&_40, "array_map", NULL, 34, &_39, &segs);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&segs, &_40);
	ZEPHIR_INIT_NVAR(&_39);
	ZEPHIR_INIT_VAR(&_41);
	ZVAL_STRING(&_41, "controller");
	ZEPHIR_CALL_METHOD(&_40, app, "getnamespace", NULL, 0, &_41);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_41);
	zephir_fast_join_str(&_41, SL("\\"), &segs);
	ZEPHIR_INIT_VAR(&_42);
	ZEPHIR_CONCAT_VSV(&_42, &_40, "\\", &_41);
	ZEPHIR_INIT_VAR(&_43);
	ZVAL_STRING(&_43, "\\");
	zephir_fast_trim(&_39, &_42, &_43, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_44);
	ZEPHIR_CONCAT_VS(&_44, &_39, "\\Controller");
	zephir_get_strval(&clsName, &_44);
	zephir_create_array(return_value, 3, 0);
	zephir_array_fast_append(return_value, &clsName);
	zephir_array_fast_append(return_value, &path);
	zephir_array_fast_append(return_value, &func);
	RETURN_MM();

}

/**
 * Build args
 *
 * @param mixed controller
 * @param string method
 * @param array args
 *
 * @return \ReflectionMethod|false
 * @throws Exception
 */
PHP_METHOD(Phpple_Filter_RouteFilter, buildMethod) {

	zend_bool _7$$5, _10$$5, _21$$13, _24$$13;
	zval _2, args;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_13 = NULL, *_23 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method, name$$4, name$$12;
	zval *controller, controller_sub, *method_param = NULL, *app, app_sub, _0, _1, reflection, request, response, param, _3, *_4, _5, _6$$4, cls$$4, _14$$4, _15$$4, _16$$4, _8$$5, _11$$5, _17$$8, _18$$9, _19$$10, _20$$12, cls$$12, _27$$12, _28$$12, _29$$12, _22$$13, _25$$13, _30$$16, _31$$17, _32$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&cls$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&cls$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&name$$4);
	ZVAL_UNDEF(&name$$12);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &controller, &method_param, &app);

	zephir_get_strval(&method, method_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodExt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &method, &_0);
	zephir_get_strval(&method, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, controller);
	zephir_array_fast_append(&_2, &method);
	if (!(zephir_is_callable(&_2))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 35, controller, &method);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_CALL_METHOD(&request, app, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, app, "getresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &reflection, "getparameters", NULL, 36);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phpple/Filter/RouteFilter.zep", 179);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&param);
			ZVAL_COPY(&param, _4);
			zephir_read_property(&_6$$4, &param, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			zephir_get_strval(&name$$4, &_6$$4);
			ZEPHIR_CALL_METHOD(&cls$$4, &param, "getclass", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&cls$$4) != IS_NULL) {
				_7$$5 = zephir_is_true(&request);
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_8$$5, &cls$$4, "isinstance", &_9, 0, &request);
					zephir_check_call_status();
					_7$$5 = zephir_is_true(&_8$$5);
				}
				_10$$5 = zephir_is_true(&response);
				if (_10$$5) {
					ZEPHIR_CALL_METHOD(&_11$$5, &cls$$4, "isinstance", &_12, 0, &response);
					zephir_check_call_status();
					_10$$5 = zephir_is_true(&_11$$5);
				}
				if (_7$$5) {
					ZEPHIR_MAKE_REF(&args);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &request);
					ZEPHIR_UNREF(&args);
					zephir_check_call_status();
				} else if (_10$$5) {
					ZEPHIR_MAKE_REF(&args);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &response);
					ZEPHIR_UNREF(&args);
					zephir_check_call_status();
				}
				continue;
			}
			ZEPHIR_CALL_METHOD(&_14$$4, &request, "has", NULL, 0, &name$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$4, &param, "isdefaultvalueavailable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$4, &param, "allowsnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$4)) {
				ZEPHIR_CALL_METHOD(&_17$$8, &request, "get", NULL, 0, &name$$4);
				zephir_check_call_status();
				ZEPHIR_MAKE_REF(&args);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_17$$8);
				ZEPHIR_UNREF(&args);
				zephir_check_call_status();
			} else if (zephir_is_true(&_15$$4)) {
				ZEPHIR_CALL_METHOD(&_18$$9, &param, "getdefaultvalue", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_MAKE_REF(&args);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_18$$9);
				ZEPHIR_UNREF(&args);
				zephir_check_call_status();
			} else if (zephir_is_true(&_16$$4)) {
				ZVAL_NULL(&_19$$10);
				ZEPHIR_MAKE_REF(&args);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_19$$10);
				ZEPHIR_UNREF(&args);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_http_exception_ce, "urlfilter.argIllegal", "phpple/Filter/RouteFilter.zep", 176);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&param, &_3, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_20$$12, &param, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				zephir_get_strval(&name$$12, &_20$$12);
				ZEPHIR_CALL_METHOD(&cls$$12, &param, "getclass", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&cls$$12) != IS_NULL) {
					_21$$13 = zephir_is_true(&request);
					if (_21$$13) {
						ZEPHIR_CALL_METHOD(&_22$$13, &cls$$12, "isinstance", &_23, 0, &request);
						zephir_check_call_status();
						_21$$13 = zephir_is_true(&_22$$13);
					}
					_24$$13 = zephir_is_true(&response);
					if (_24$$13) {
						ZEPHIR_CALL_METHOD(&_25$$13, &cls$$12, "isinstance", &_26, 0, &response);
						zephir_check_call_status();
						_24$$13 = zephir_is_true(&_25$$13);
					}
					if (_21$$13) {
						ZEPHIR_MAKE_REF(&args);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &request);
						ZEPHIR_UNREF(&args);
						zephir_check_call_status();
					} else if (_24$$13) {
						ZEPHIR_MAKE_REF(&args);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &response);
						ZEPHIR_UNREF(&args);
						zephir_check_call_status();
					}
					continue;
				}
				ZEPHIR_CALL_METHOD(&_27$$12, &request, "has", NULL, 0, &name$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_28$$12, &param, "isdefaultvalueavailable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_29$$12, &param, "allowsnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_27$$12)) {
					ZEPHIR_CALL_METHOD(&_30$$16, &request, "get", NULL, 0, &name$$12);
					zephir_check_call_status();
					ZEPHIR_MAKE_REF(&args);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_30$$16);
					ZEPHIR_UNREF(&args);
					zephir_check_call_status();
				} else if (zephir_is_true(&_28$$12)) {
					ZEPHIR_CALL_METHOD(&_31$$17, &param, "getdefaultvalue", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_MAKE_REF(&args);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_31$$17);
					ZEPHIR_UNREF(&args);
					zephir_check_call_status();
				} else if (zephir_is_true(&_29$$12)) {
					ZVAL_NULL(&_32$$18);
					ZEPHIR_MAKE_REF(&args);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 12, &args, &_32$$18);
					ZEPHIR_UNREF(&args);
					zephir_check_call_status();
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phpple_http_exception_ce, "urlfilter.argIllegal", "phpple/Filter/RouteFilter.zep", 176);
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&param);
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &reflection);
	zephir_array_fast_append(return_value, &args);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phpple_Filter_RouteFilter(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("protectedMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "_before");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "_after");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("protectedMethods"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

