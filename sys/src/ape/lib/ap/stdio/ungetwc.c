/*
 * pANS stdio -- ungetwc
 *
 * Convert back to multibyte and push the bytes back in reverse, so the
 * next read returns them in the original order. MB_LEN_MAX is 4 and
 * ungetc has an UNGET area of 8 bytes, so one wide character always
 * fits; a second consecutive ungetwc may not, which C99 permits since
 * only one pushback is guaranteed.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

wint_t ungetwc(wint_t c, FILE *f)
{
	mbstate_t st;
	char b[MB_LEN_MAX];
	size_t n;
	int i;

	if (c == WEOF)
		return WEOF;

	memset(&st, 0, sizeof st);
	n = wcrtomb(b, (wchar_t)c, &st);
	if (n == (size_t)-1) {
		errno = EILSEQ;
		return WEOF;
	}
	for (i = (int)n - 1; i >= 0; i--)
		if (ungetc((unsigned char)b[i], f) == EOF)
			return WEOF;
	return c;
}
