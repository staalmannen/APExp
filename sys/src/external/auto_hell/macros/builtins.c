#include "builtins.h"
#include "macro.h"

void macro_builtins_register(struct MacroSet *m)
{
	if (!m)
		return;

	/* minimal builtin macros needed for tinyx. */
	macroset_add(m, "AC_USE_SYSTEM_EXTENSIONS",
		"AC_DEFINE([_GNU_SOURCE],[1],[enable G*U extensions])\n");
	macroset_add(m, "XTRANS_CONNECTION_FLAGS",
		"AC_DEFINE([UNIXCONN],[1],[support UNIX socket connections])\n"
		"AC_DEFINE([TCPCONN],[1],[support TCP socket connections])\n"
		"AC_CHECK_FUNCS([strcasecmp strlcpy])\n");
}
