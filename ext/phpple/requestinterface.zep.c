
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phpple_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phpple, RequestInterface, phpple, requestinterface, NULL);

	return SUCCESS;

}

