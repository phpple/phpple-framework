PHP_ARG_ENABLE(phpple, whether to enable phpple, [ --enable-phpple   Enable Phpple])

if test "$PHP_PHPPLE" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHPPLE_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHPPLE, 1, [Whether you have Phpple])
	phpple_sources="phpple.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phpple/filter/filterinterface.zep.c
	phpple/exception.zep.c
	phpple/application.zep.c
	phpple/log/loggerinterface.zep.c
	phpple/requestinterface.zep.c
	phpple/responseinterface.zep.c
	phpple/console/color.zep.c
	phpple/filter/cleanfilter.zep.c
	phpple/filter/exception.zep.c
	phpple/filter/executor.zep.c
	phpple/filter/inputfilter.zep.c
	phpple/filter/outputfilter.zep.c
	phpple/filter/routefilter.zep.c
	phpple/helper/requestbuilder.zep.c
	phpple/http/application.zep.c
	phpple/http/controller.zep.c
	phpple/http/exception.zep.c
	phpple/http/outputformat.zep.c
	phpple/http/request.zep.c
	phpple/http/response.zep.c
	phpple/log/exception.zep.c
	phpple/log/loglevel.zep.c
	phpple/log/logger.zep.c
	phpple/util/conf.zep.c
	phpple/util/timer.zep.c
	phpple/util/xml.zep.c "
	PHP_NEW_EXTENSION(phpple, $phpple_sources, $ext_shared,, )
	PHP_SUBST(PHPPLE_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phpple], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phpple], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phpple], [php_PHPPLE.h])

fi
