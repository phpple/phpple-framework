
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


ZEPHIR_INIT_CLASS(Phpple_Http_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phpple\\Http, Exception, phpple, http_exception, phpple_exception_ce, NULL, 0);

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_NOT_FOUND"), "phpple.u_notfound");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_NO_POWER"), "phpple.u_power");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_NOT_LOGIN"), "phpple.u_login");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_FATAL"), "phpple.fatal");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_INPUT"), "phpple.u_input");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_COMMON"), "phpple.error");

	zephir_declare_class_constant_string(phpple_http_exception_ce, SL("EXCEPTION_ARGS"), "phpple.u_args");

	return SUCCESS;

}

