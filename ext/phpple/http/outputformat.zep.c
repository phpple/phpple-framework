
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


ZEPHIR_INIT_CLASS(Phpple_Http_OutputFormat) {

	ZEPHIR_REGISTER_CLASS(Phpple\\Http, OutputFormat, phpple, http_outputformat, NULL, 0);

	zephir_declare_class_constant_string(phpple_http_outputformat_ce, SL("FORMAT_JSON"), "json");

	zephir_declare_class_constant_string(phpple_http_outputformat_ce, SL("FORMAT_XML"), "xml");

	zephir_declare_class_constant_string(phpple_http_outputformat_ce, SL("FORMAT_HTML"), "html");

	zephir_declare_class_constant_string(phpple_http_outputformat_ce, SL("FORMAT_TEXT"), "txt");

	zephir_declare_class_constant_string(phpple_http_outputformat_ce, SL("FORMAT_DEFAULT"), "default");

	return SUCCESS;

}

