/*
 * pANS stdio -- fputws
 *
 * C99 7.24.3.4: write the wide string, not including its terminator.
 * Return a non-negative value, or EOF on a write error.
 */
#include "stdio_impl.h"
#include <wchar.h>

int fputws(const wchar_t *ws, FILE *f)
{
	for (; *ws; ws++)
		if (fputwc(*ws, f) == WEOF)
			return EOF;
	return 0;
}
