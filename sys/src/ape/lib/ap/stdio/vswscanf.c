/*
 * pANS stdio -- vswscanf, swscanf
 *
 * Unlike vfwscanf both the format and the INPUT are wide, so the input
 * is converted to the narrow encoding first and read through a memory
 * stream, the same way sscanf works.
 *
 * One deviation to be aware of: %n reports a count in the narrow
 * string, which is a byte offset rather than a count of wide
 * characters. They agree for ASCII input and diverge above it. Fixing
 * that needs a wide-aware vfscanf rather than this delegation.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int vswscanf(const wchar_t *ws, const wchar_t *fmt, va_list ap)
{
	char *ns, *nf;
	FILE *f;
	int r;

	if (!(ns = __wfmt_narrow(ws)))
		return EOF;
	if (!(nf = __wfmt_narrow(fmt))) {
		free(ns);
		return EOF;
	}
	if (!(f = fmemopen(ns, strlen(ns), "r"))) {
		free(ns);
		free(nf);
		return EOF;
	}
	r = vfscanf(f, nf, ap);
	fclose(f);
	free(ns);
	free(nf);
	return r;
}

int swscanf(const wchar_t *ws, const wchar_t *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vswscanf(ws, fmt, ap);
	va_end(ap);
	return r;
}
