/*
 * pANS stdio -- fputwc, putwc, putwchar
 *
 * Convert the wide character to its multibyte form and write those
 * bytes. fputc does the locking and buffering, so there is none here;
 * see the note in fgetwc.c.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

wint_t fputwc(wchar_t wc, FILE *f)
{
	mbstate_t st;
	char b[MB_LEN_MAX];
	size_t n, i;

	memset(&st, 0, sizeof st);
	n = wcrtomb(b, wc, &st);
	if (n == (size_t)-1) {		/* not representable in this encoding */
		f->flags |= F_ERR;
		errno = EILSEQ;
		return WEOF;
	}
	for (i = 0; i < n; i++)
		if (fputc((unsigned char)b[i], f) == EOF)
			return WEOF;
	return (wint_t)wc;
}

wint_t putwc(wchar_t wc, FILE *f)
{
	return fputwc(wc, f);
}

wint_t putwchar(wchar_t wc)
{
	return fputwc(wc, stdout);
}
