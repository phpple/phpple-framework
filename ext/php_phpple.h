
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHPPLE_H
#define PHP_PHPPLE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHPPLE_NAME        "phpple"
#define PHP_PHPPLE_VERSION     "0.0.1"
#define PHP_PHPPLE_EXTNAME     "phpple"
#define PHP_PHPPLE_AUTHOR      "Phalcon Team"
#define PHP_PHPPLE_ZEPVERSION  "0.12.19-$Id$"
#define PHP_PHPPLE_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(phpple)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(phpple)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phpple)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(phpple, v)
#else
	#define ZEPHIR_GLOBAL(v) (phpple_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_phpple_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(phpple_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phpple_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phpple_globals
#define zend_zephir_globals_def zend_phpple_globals

extern zend_module_entry phpple_module_entry;
#define phpext_phpple_ptr &phpple_module_entry

#endif
