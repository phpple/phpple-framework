
extern zend_class_entry *phpple_console_color_ce;

ZEPHIR_INIT_CLASS(Phpple_Console_Color);

PHP_METHOD(Phpple_Console_Color, getColoredString);
PHP_METHOD(Phpple_Console_Color, info);
PHP_METHOD(Phpple_Console_Color, warn);
PHP_METHOD(Phpple_Console_Color, success);
PHP_METHOD(Phpple_Console_Color, error);
void zephir_init_static_properties_Phpple_Console_Color(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_console_color_getcoloredstring, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phpple_console_color_getcoloredstring, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, str)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, color)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, backColor, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, backColor)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_console_color_info, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_console_color_warn, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_console_color_success, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phpple_console_color_error, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phpple_console_color_method_entry) {
	PHP_ME(Phpple_Console_Color, getColoredString, arginfo_phpple_console_color_getcoloredstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Console_Color, info, arginfo_phpple_console_color_info, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Console_Color, warn, arginfo_phpple_console_color_warn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Console_Color, success, arginfo_phpple_console_color_success, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phpple_Console_Color, error, arginfo_phpple_console_color_error, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
