/*
 * dcngettext.c - Plan9 APExp gettext stubs
 *
 * Plan9 has no message catalogue (.mo) files and no MUSL_LOCPATH,
 * so every gettext lookup falls through to "no translation found".
 * These stubs satisfy the link-time API without any of the musl
 * machinery (mmap, atomic ops, locale maps, VLAs) that the kencc
 * compiler cannot handle.
 *
 * The functions are correct for Plan9:
 *   - dcngettext/dngettext: return msgid2 when n!=1, else msgid1
 *   - dcgettext/dgettext:   return msgid
 *   - bindtextdomain:       accepted but silently ignored
 *   - textdomain:           accepted but silently ignored
 */

#include <libintl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/* ------------------------------------------------------------------ */
/* bindtextdomain / bind_textdomain_codeset                            */
/* ------------------------------------------------------------------ */

/* Keep a single binding so bindtextdomain() can return dirname.       */
static char bound_dir[1024];
static char bound_domain[256];

char *
bindtextdomain(const char *domainname, const char *dirname)
{
	if (!domainname)
		return 0;
	if (!dirname) {
		/* query */
		return bound_dir[0] ? bound_dir : 0;
	}
	strncpy(bound_domain, domainname, sizeof bound_domain - 1);
	strncpy(bound_dir,    dirname,    sizeof bound_dir - 1);
	return bound_dir;
}

/* ------------------------------------------------------------------ */
/* Core translation: always untranslated on Plan9                      */
/* ------------------------------------------------------------------ */

char *
dcngettext(const char *domainname, const char *msgid1,
           const char *msgid2, unsigned long int n, int category)
{
	(void)domainname;
	(void)category;
	if (!msgid1)
		return (char *)msgid2;
	return (char *)(n == 1 ? msgid1 : msgid2 ? msgid2 : msgid1);
}

char *
dcgettext(const char *domainname, const char *msgid, int category)
{
	return dcngettext(domainname, msgid, 0, 1, category);
}

char *
dngettext(const char *domainname, const char *msgid1,
          const char *msgid2, unsigned long int n)
{
	return dcngettext(domainname, msgid1, msgid2, n, 6 /* LC_MESSAGES */);
}

char *
dgettext(const char *domainname, const char *msgid)
{
	return dcngettext(domainname, msgid, 0, 1, 6 /* LC_MESSAGES */);
}
