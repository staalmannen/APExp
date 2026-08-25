/*
 * pANS stdio -- fgetws
 *
 * C99 7.24.3.2: read at most n-1 wide characters, stopping after a
 * newline, and NUL-terminate. Return s, or a null pointer if a read
 * error occurred or end-of-file was reached before any character.
 */
#include "stdio_impl.h"
#include <wchar.h>

wchar_t *fgetws(wchar_t *s, int n, FILE *f)
{
	wchar_t *p = s;
	wint_t c;

	if (n <= 0)
		return 0;
	if (n == 1) {			/* room for the terminator only */
		*s = 0;
		return s;
	}

	while (p - s < n - 1) {
		c = fgetwc(f);
		if (c == WEOF)
			break;
		*p++ = (wchar_t)c;
		if (c == L'\n')
			break;
	}
	*p = 0;

	if (ferror(f))
		return 0;
	return p == s ? 0 : s;		/* nothing read means EOF */
}
