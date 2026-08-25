/*
 * pANS stdio -- vfwscanf, fwscanf, vwscanf, wscanf
 *
 * Convert the wide format to the narrow encoding and hand it to
 * vfscanf, which now understands %ls and %lc. The stream itself is
 * byte-oriented underneath, so no conversion of the input is needed;
 * only the format string's encoding differs.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>

int vfwscanf(FILE *f, const wchar_t *fmt, va_list ap)
{
	char *nf;
	int r;

	if (!(nf = __wfmt_narrow(fmt)))
		return EOF;
	r = vfscanf(f, nf, ap);
	free(nf);
	return r;
}

int fwscanf(FILE *f, const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vfwscanf(f, fmt, ap);
	va_end(ap);
	return r;
}

int vwscanf(const wchar_t *fmt, va_list ap)
{
	return vfwscanf(stdin, fmt, ap);
}

int wscanf(const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vfwscanf(stdin, fmt, ap);
	va_end(ap);
	return r;
}
