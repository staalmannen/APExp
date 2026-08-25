/*
 * pANS stdio -- vfwprintf, fwprintf, vwprintf, wprintf
 *
 * Convert the wide format to the narrow encoding and hand it to
 * vfprintf, which understands %ls and %lc. The argument list needs no
 * adjustment: the specifiers carry the same meaning in a wide format as
 * in a narrow one.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>

int vfwprintf(FILE *f, const wchar_t *fmt, va_list ap)
{
	char *nf;
	int r;

	if (!(nf = __wfmt_narrow(fmt)))
		return -1;
	r = vfprintf(f, nf, ap);
	free(nf);
	return r;
}

int fwprintf(FILE *f, const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vfwprintf(f, fmt, ap);
	va_end(ap);
	return r;
}

int vwprintf(const wchar_t *fmt, va_list ap)
{
	return vfwprintf(stdout, fmt, ap);
}

int wprintf(const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vfwprintf(stdout, fmt, ap);
	va_end(ap);
	return r;
}
