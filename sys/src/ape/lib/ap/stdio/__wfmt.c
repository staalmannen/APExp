/*
 * APExp internal -- conversion between wide and narrow format strings.
 *
 * The wide printf and scanf families are implemented by converting the
 * format (and, for the sw* variants, the buffer) to the narrow encoding
 * and delegating to vfprintf/vfscanf. That works because the conversion
 * specifiers mean the same thing in both: C99 gives %s a char * and %ls
 * a wchar_t * whether the format itself is wide or narrow. Only the
 * format string's own encoding differs.
 *
 * Both return a malloc'd buffer the caller frees, or 0 with errno set.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *__wfmt_narrow(const wchar_t *ws)
{
	const wchar_t *p = ws;
	mbstate_t st;
	size_t n;
	char *b;

	memset(&st, 0, sizeof st);
	n = wcsrtombs(0, &p, 0, &st);
	if (n == (size_t)-1) {
		errno = EILSEQ;
		return 0;
	}
	if (!(b = malloc(n + 1)))
		return 0;
	p = ws;
	memset(&st, 0, sizeof st);
	if (wcsrtombs(b, &p, n + 1, &st) == (size_t)-1) {
		free(b);
		errno = EILSEQ;
		return 0;
	}
	return b;
}

wchar_t *__wfmt_wide(const char *s)
{
	const char *p = s;
	mbstate_t st;
	size_t n;
	wchar_t *b;

	memset(&st, 0, sizeof st);
	n = mbsrtowcs(0, &p, 0, &st);
	if (n == (size_t)-1) {
		errno = EILSEQ;
		return 0;
	}
	if (!(b = malloc((n + 1) * sizeof(wchar_t))))
		return 0;
	p = s;
	memset(&st, 0, sizeof st);
	if (mbsrtowcs(b, &p, n + 1, &st) == (size_t)-1) {
		free(b);
		errno = EILSEQ;
		return 0;
	}
	return b;
}
