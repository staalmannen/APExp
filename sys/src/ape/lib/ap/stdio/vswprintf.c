/*
 * pANS stdio -- vswprintf, swprintf
 *
 * These write into a wchar_t buffer, so unlike vfwprintf they cannot
 * simply delegate: snprintf would deposit bytes where wide characters
 * are expected. Format into a narrow buffer first, then convert that
 * into the caller's buffer.
 *
 * C99 7.24.2.7: at most n wide characters are written including the
 * terminator, and the return is the count excluding it, or negative if
 * n or more would have been needed.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int vswprintf(wchar_t *s, size_t n, const wchar_t *fmt, va_list ap)
{
	char *nf, *out = 0;
	const char *p;
	mbstate_t st;
	size_t w;
	int len;

	if (!(nf = __wfmt_narrow(fmt)))
		return -1;
	/*
	 * vasprintf rather than a two-pass vsnprintf: the argument list
	 * can only be walked once, and sizing first would consume it.
	 */
	len = vasprintf(&out, nf, ap);
	free(nf);
	if (len < 0)
		return -1;

	p = out;
	memset(&st, 0, sizeof st);
	w = mbsrtowcs(s, &p, n, &st);
	free(out);

	if (w == (size_t)-1) {
		errno = EILSEQ;
		return -1;
	}
	if (p) {			/* stopped early: did not all fit */
		if (n)
			s[n - 1] = 0;
		return -1;
	}
	return (int)w;
}

int swprintf(wchar_t *s, size_t n, const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vswprintf(s, n, fmt, ap);
	va_end(ap);
	return r;
}
