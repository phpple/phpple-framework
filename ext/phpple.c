
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phpple.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phpple_filter_filterinterface_ce;
zend_class_entry *phpple_log_loggerinterface_ce;
zend_class_entry *phpple_requestinterface_ce;
zend_class_entry *phpple_responseinterface_ce;
zend_class_entry *phpple_exception_ce;
zend_class_entry *phpple_application_ce;
zend_class_entry *phpple_console_color_ce;
zend_class_entry *phpple_filter_cleanfilter_ce;
zend_class_entry *phpple_filter_exception_ce;
zend_class_entry *phpple_filter_executor_ce;
zend_class_entry *phpple_filter_inputfilter_ce;
zend_class_entry *phpple_filter_outputfilter_ce;
zend_class_entry *phpple_filter_routefilter_ce;
zend_class_entry *phpple_helper_requestbuilder_ce;
zend_class_entry *phpple_http_application_ce;
zend_class_entry *phpple_http_controller_ce;
zend_class_entry *phpple_http_exception_ce;
zend_class_entry *phpple_http_outputformat_ce;
zend_class_entry *phpple_http_request_ce;
zend_class_entry *phpple_http_response_ce;
zend_class_entry *phpple_log_exception_ce;
zend_class_entry *phpple_log_logger_ce;
zend_class_entry *phpple_log_loglevel_ce;
zend_class_entry *phpple_util_conf_ce;
zend_class_entry *phpple_util_timer_ce;
zend_class_entry *phpple_util_xml_ce;

ZEND_DECLARE_MODULE_GLOBALS(phpple)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phpple)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Phpple_Filter_FilterInterface);
	ZEPHIR_INIT(Phpple_Log_LoggerInterface);
	ZEPHIR_INIT(Phpple_RequestInterface);
	ZEPHIR_INIT(Phpple_ResponseInterface);
	ZEPHIR_INIT(Phpple_Exception);
	ZEPHIR_INIT(Phpple_Application);
	ZEPHIR_INIT(Phpple_Console_Color);
	ZEPHIR_INIT(Phpple_Filter_CleanFilter);
	ZEPHIR_INIT(Phpple_Filter_Exception);
	ZEPHIR_INIT(Phpple_Filter_Executor);
	ZEPHIR_INIT(Phpple_Filter_InputFilter);
	ZEPHIR_INIT(Phpple_Filter_OutputFilter);
	ZEPHIR_INIT(Phpple_Filter_RouteFilter);
	ZEPHIR_INIT(Phpple_Helper_RequestBuilder);
	ZEPHIR_INIT(Phpple_Http_Application);
	ZEPHIR_INIT(Phpple_Http_Controller);
	ZEPHIR_INIT(Phpple_Http_Exception);
	ZEPHIR_INIT(Phpple_Http_OutputFormat);
	ZEPHIR_INIT(Phpple_Http_Request);
	ZEPHIR_INIT(Phpple_Http_Response);
	ZEPHIR_INIT(Phpple_Log_Exception);
	ZEPHIR_INIT(Phpple_Log_LogLevel);
	ZEPHIR_INIT(Phpple_Log_Logger);
	ZEPHIR_INIT(Phpple_Util_Conf);
	ZEPHIR_INIT(Phpple_Util_Timer);
	ZEPHIR_INIT(Phpple_Util_Xml);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phpple)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phpple_globals *phpple_globals TSRMLS_DC)
{
	phpple_globals->initialized = 0;

	/* Cache Enabled */
	phpple_globals->cache_enabled = 1;

	/* Recursive Lock */
	phpple_globals->recursive_lock = 0;

	/* Static cache */
	memset(phpple_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phpple_globals *phpple_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(phpple)
{
	zend_phpple_globals *phpple_globals_ptr;
	phpple_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phpple_globals_ptr);
	zephir_initialize_memory(phpple_globals_ptr);

		zephir_init_static_properties_Phpple_Application(TSRMLS_C);
		zephir_init_static_properties_Phpple_Console_Color(TSRMLS_C);
		zephir_init_static_properties_Phpple_Filter_InputFilter(TSRMLS_C);
		zephir_init_static_properties_Phpple_Helper_RequestBuilder(TSRMLS_C);
		zephir_init_static_properties_Phpple_Log_Logger(TSRMLS_C);
		zephir_init_static_properties_Phpple_Util_Conf(TSRMLS_C);
		zephir_init_static_properties_Phpple_Util_Xml(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phpple)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phpple)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHPPLE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHPPLE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHPPLE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHPPLE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHPPLE_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phpple)
{
#if defined(COMPILE_DL_PHPPLE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(phpple_globals);
	php_zephir_init_module_globals(phpple_globals);
}

static PHP_GSHUTDOWN_FUNCTION(phpple)
{
	
}


zend_function_entry php_phpple_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_phpple_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry phpple_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_phpple_deps,
	PHP_PHPPLE_EXTNAME,
	php_phpple_functions,
	PHP_MINIT(phpple),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phpple),
#else
	NULL,
#endif
	PHP_RINIT(phpple),
	PHP_RSHUTDOWN(phpple),
	PHP_MINFO(phpple),
	PHP_PHPPLE_VERSION,
	ZEND_MODULE_GLOBALS(phpple),
	PHP_GINIT(phpple),
	PHP_GSHUTDOWN(phpple),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phpple),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PHPPLE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phpple)
#endif
