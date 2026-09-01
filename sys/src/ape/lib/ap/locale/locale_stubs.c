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
/* setlocale: accept any request, and report back what was asked for   */
/* ------------------------------------------------------------------ */

/*
 * Plan 9 has one locale and no locale database, so nothing here changes
 * any behaviour: every name is accepted and every category behaves as
 * C.UTF-8 whatever it is called. What this does do is keep the *names*
 * straight, which is a separate contract and the one callers actually
 * test:
 *
 *   C99 7.11.1.1p8 -- setlocale returns a string associated with the
 *   specified locale for the category, and a later call with that
 *   string and the same category restores that part of the program's
 *   locale.
 *
 * The old version ignored `name' and answered "C.UTF-8" to everything,
 * which fails that on its face: ask for "C" and you are told you got
 * something else. perl checks, and says so --
 *
 *	locale.c: 3441: panic: Can't change locale for LC_NUMERIC (4)
 *	  from 'C.UTF-8' to 'C'
 *
 * from Perl_set_numeric_standard, which sets LC_NUMERIC to "C" so that
 * the radix character is a dot no matter what LC_CTYPE is doing. That
 * is exactly the case this arrangement exists for, and it is a category
 * whose name has to differ from the others.
 *
 * So each category remembers the name it was last set to, a query
 * returns that name, and a set returns the name that was just stored.
 * "" means "from the environment", where an unset environment gives
 * C.UTF-8 -- Plan 9's native encoding is UTF-8, and that is the
 * implementation-defined native locale C99 7.11.1.1p3 leaves to us.
 *
 * The initial value is "C", because C99 7.11.1.1p4 requires the
 * equivalent of setlocale(LC_ALL, "C") at program start.
 */

#define LOCALE_NAME_MAX	64	/* longest name kept, plus the NUL */
#define NLOCALECAT	6

/*
 * Index order is glibc's for the LC_ALL composite string, so the string
 * this produces is the one portable code knows how to parse back.
 */
static const struct {
	int cat;
	const char *name;
} lcorder[NLOCALECAT] = {
	{ LC_CTYPE,	"LC_CTYPE" },
	{ LC_NUMERIC,	"LC_NUMERIC" },
	{ LC_TIME,	"LC_TIME" },
	{ LC_COLLATE,	"LC_COLLATE" },
	{ LC_MONETARY,	"LC_MONETARY" },
	{ LC_MESSAGES,	"LC_MESSAGES" },
};

static char curlocale[NLOCALECAT][LOCALE_NAME_MAX] = {
	"C", "C", "C", "C", "C", "C"
};

static int
lcindex(int cat)
{
	int i;

	for (i = 0; i < NLOCALECAT; i++)
		if (lcorder[i].cat == cat)
			return i;
	return -1;
}

/*
 * What "" means for one category: LC_ALL wins over the category's own
 * variable, which wins over LANG (POSIX XBD 8.2). An empty or unset
 * value falls through to the next, and C.UTF-8 is the default.
 */
static const char *
lcfromenv(int i)
{
	const char *s;

	if ((s = getenv("LC_ALL")) != 0 && *s)
		return s;
	if ((s = getenv(lcorder[i].name)) != 0 && *s)
		return s;
	if ((s = getenv("LANG")) != 0 && *s)
		return s;
	return "C.UTF-8";
}

static int
lcset(int i, const char *name)
{
	if (*name == '\0')
		name = lcfromenv(i);
	if (strlen(name) >= LOCALE_NAME_MAX)
		return -1;
	strcpy(curlocale[i], name);
	return 0;
}

/*
 * The LC_ALL string. When every category agrees, that is the bare name
 * -- which is what glibc returns, and what any caller can hand straight
 * back to setlocale. Only a mixture needs the composite form, and perl
 * reaches that as soon as it pins LC_NUMERIC to "C".
 */
static char *
lcall(void)
{
	static char buf[NLOCALECAT * (16 + LOCALE_NAME_MAX + 2)];
	char *p;
	int i;

	for (i = 1; i < NLOCALECAT; i++)
		if (strcmp(curlocale[i], curlocale[0]) != 0)
			break;
	if (i == NLOCALECAT)
		return curlocale[0];

	p = buf;
	for (i = 0; i < NLOCALECAT; i++) {
		if (i > 0)
			*p++ = ';';
		strcpy(p, lcorder[i].name);
		p += strlen(p);
		*p++ = '=';
		strcpy(p, curlocale[i]);
		p += strlen(p);
	}
	*p = '\0';
	return buf;
}

/*
 * Setting LC_ALL. The name is either one locale for every category, or
 * a composite of the kind lcall() produces -- which it has to accept,
 * because C99 7.11.1.1p8 promises that whatever a query returned can be
 * handed back. Both spellings seen in the wild are taken: glibc's
 * "LC_CTYPE=x;LC_NUMERIC=y;..." and musl's bare "x;y;..." in category
 * order. A named category we do not have is skipped rather than
 * refused, so a string from some other system still restores the
 * categories we share with it.
 */
static int
lcsetall(const char *name)
{
	const char *p, *semi, *eq;
	char key[32], val[LOCALE_NAME_MAX];
	size_t flen, klen, vlen;
	int i, n;

	if (strchr(name, ';') == 0 && strchr(name, '=') == 0) {
		for (i = 0; i < NLOCALECAT; i++)
			if (lcset(i, name) < 0)
				return -1;
		return 0;
	}

	n = 0;
	for (p = name; ; p = semi + 1) {
		semi = strchr(p, ';');
		flen = semi ? (size_t)(semi - p) : strlen(p);
		eq = memchr(p, '=', flen);
		if (eq != 0) {
			klen = eq - p;
			vlen = flen - klen - 1;
			if (klen >= sizeof key || vlen >= LOCALE_NAME_MAX)
				return -1;
			memcpy(key, p, klen);
			key[klen] = '\0';
			memcpy(val, eq + 1, vlen);
			val[vlen] = '\0';
			for (i = 0; i < NLOCALECAT; i++)
				if (strcmp(lcorder[i].name, key) == 0) {
					if (lcset(i, val) < 0)
						return -1;
					break;
				}
		} else {
			if (n >= NLOCALECAT || flen >= LOCALE_NAME_MAX)
				return -1;
			memcpy(val, p, flen);
			val[flen] = '\0';
			if (lcset(n, val) < 0)
				return -1;
		}
		n++;
		if (semi == 0)
			break;
	}
	return 0;
}

char *
setlocale(int cat, const char *name)
{
	char saved[NLOCALECAT][LOCALE_NAME_MAX];
	int i;

	if (cat == LC_ALL) {
		if (name == 0)
			return lcall();
		/*
		 * All or nothing: if any part of the name will not take,
		 * the whole call fails and no category has moved.
		 */
		memcpy(saved, curlocale, sizeof saved);
		if (lcsetall(name) < 0) {
			memcpy(curlocale, saved, sizeof saved);
			return 0;
		}
		return lcall();
	}

	/*
	 * Anything that is not one of our categories. LC_ALL is 0 here,
	 * so the older '> LC_ALL' test rejected every real category.
	 */
	if ((i = lcindex(cat)) < 0)
		return 0;

	if (name == 0)
		return curlocale[i];
	if (lcset(i, name) < 0)
		return 0;
	return curlocale[i];
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

locale_t
newlocale(int mask, const char *name, locale_t base)
{
	(void)mask; (void)name; (void)base;
	return UTF8_LOCALE;
}


/* ------------------------------------------------------------------ */
/* uselocale: ignore the request, always return UTF-8 locale           */
/* ------------------------------------------------------------------ */

locale_t
__uselocale(locale_t new)
{
	(void)new;
	return UTF8_LOCALE;
}

locale_t
uselocale(locale_t new)
{
	(void)new;
	return UTF8_LOCALE;
}

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

const char *__lctrans_cur(const char *msg)
{
	return __lctrans_impl(msg, (const struct __locale_map *) "UTF-8");
}






