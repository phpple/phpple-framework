
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Filter interface
 */
ZEPHIR_INIT_CLASS(Phpple_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phpple\\Filter, FilterInterface, phpple, filter_filterinterface, phpple_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Execute filter
 *
 * @param Application app
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phpple_Filter_FilterInterface, execute);

