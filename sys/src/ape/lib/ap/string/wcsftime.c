/*
 * wcsftime
 *
 * Convert the format to the narrow encoding, run strftime, and convert
 * the result back. Self-contained rather than reaching for the helpers
 * in stdio/__wfmt.c, so a time function does not have to pull in
 * stdio_impl.h.
 *
 * C99 7.24.5.1: if the result including the terminator needs more than
 * maxsize wide characters, return 0 and leave the contents
 * indeterminate.
 */
#include <wchar.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

size_t
wcsftime(wchar_t *s, size_t n, const wchar_t *fmt, const struct tm *tm)
{
	const wchar_t *wp;
	const char *np;
	mbstate_t st;
	char *nf = 0, *out = 0;
	size_t need, cap, r, w;

	if (n == 0)
		return 0;

	/* format: wide to narrow */
	wp = fmt;
	memset(&st, 0, sizeof st);
	need = wcsrtombs(0, &wp, 0, &st);
	if (need == (size_t)-1)
		return 0;
	if (!(nf = malloc(need + 1)))
		return 0;
	wp = fmt;
	memset(&st, 0, sizeof st);
	if (wcsrtombs(nf, &wp, need + 1, &st) == (size_t)-1)
		goto fail;

	/*
	 * n wide characters can need up to MB_LEN_MAX bytes each. Guard
	 * the multiplication rather than trusting it not to wrap.
	 */
	if (n > (size_t)-2 / MB_LEN_MAX)
		goto fail;
	cap = n * MB_LEN_MAX + 1;
	if (!(out = malloc(cap)))
		goto fail;

	r = strftime(out, cap, nf, tm);
	if (r == 0)			/* did not fit, or empty result */
		goto fail;

	/* result: narrow back to wide, into the caller's buffer */
	np = out;
	memset(&st, 0, sizeof st);
	w = mbsrtowcs(s, &np, n, &st);
	if (w == (size_t)-1 || np)	/* error, or would not all fit */
		goto fail;

	free(nf);
	free(out);
	return w;

fail:
	free(nf);
	free(out);
	return 0;
}
