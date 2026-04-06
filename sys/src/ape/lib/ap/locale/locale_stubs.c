/*
 * locale_stubs.c - Plan9 APExp locale stubs
 *
 * Plan9 supports exactly one locale: UTF-8.
 * These stubs satisfy the POSIX locale API for software that calls
 * setlocale/newlocale/uselocale as a configure or compile dependency,
 * without implementing real locale switching.
 *
 * setlocale()  - always succeeds, always returns "C.UTF-8"
 * newlocale()  - returns the one global UTF-8 locale
 * uselocale()  - returns the one global UTF-8 locale
 * duplocale()  - returns the one global UTF-8 locale
 * freelocale() - no-op (nothing to free)
 * __get_locale() - always returns the UTF-8 locale map or NULL for C
 */

#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "locale_impl.h"

/* ------------------------------------------------------------------ */
/* The single built-in UTF-8 locale map (defined in c_locale.c)       */
/* ------------------------------------------------------------------ */

/* __c_dot_utf8, __c_locale, __c_dot_utf8_locale are in c_locale.c    */

/* ------------------------------------------------------------------ */
/* __get_locale: always return the UTF-8 locale map                    */
/* ------------------------------------------------------------------ */

const struct __locale_map *
__get_locale(int cat, const char *val)
{
	/*
	 * We accept any locale name.  Since Plan9 is always UTF-8,
	 * LC_CTYPE gets the C.UTF-8 map; all other categories get NULL
	 * (which means "C" / no special handling).
	 */
	if (cat == LC_CTYPE)
		return &__c_dot_utf8;
	return 0;
}

/* ------------------------------------------------------------------ */
/* setlocale: accept any request, always report C.UTF-8               */
/* ------------------------------------------------------------------ */

char *
setlocale(int cat, const char *name)
{
	if ((unsigned)cat > LC_ALL)
		return 0;
	/* We accept the set request but do nothing - always UTF-8.      */
	/* For LC_ALL, return a semicolon-separated string of C.UTF-8.   */
	if (cat == LC_ALL) {
		static char buf[] =
			"C.UTF-8;C.UTF-8;C.UTF-8;C.UTF-8;C.UTF-8;C.UTF-8";
		return buf;
	}
	return "C.UTF-8";
}

/* ------------------------------------------------------------------ */
/* newlocale: always return the UTF-8 locale object                    */
/* ------------------------------------------------------------------ */

locale_t
__newlocale(int mask, const char *name, locale_t base)
{
	(void)mask; (void)name; (void)base;
	return UTF8_LOCALE;
}

weak_alias(__newlocale, newlocale);

/* ------------------------------------------------------------------ */
/* uselocale: ignore the request, always return UTF-8 locale           */
/* ------------------------------------------------------------------ */

locale_t
__uselocale(locale_t new)
{
	(void)new;
	return UTF8_LOCALE;
}

weak_alias(__uselocale, uselocale);

/* ------------------------------------------------------------------ */
/* duplocale: nothing to duplicate                                      */
/* ------------------------------------------------------------------ */

locale_t
duplocale(locale_t loc)
{
	(void)loc;
	return UTF8_LOCALE;
}

/* ------------------------------------------------------------------ */
/* freelocale: nothing to free                                          */
/* ------------------------------------------------------------------ */

void
freelocale(locale_t loc)
{
	(void)loc;
}

/* ------------------------------------------------------------------ */
/* __loc_is_allocated: nothing is ever dynamically allocated           */
/* ------------------------------------------------------------------ */

int
__loc_is_allocated(locale_t loc)
{
	(void)loc;
	return 0;
}

/* ------------------------------------------------------------------ */
/* __lctrans_impl: message translation (no .mo files on Plan9)         */
/* ------------------------------------------------------------------ */

const char *
__lctrans_impl(const char *msg, const struct __locale_map *lm)
{
	(void)lm;
	return msg;
}




