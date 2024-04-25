#include <stdint.h>
#include "../wchar.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "internal.h"
#define EILSEQ ERANGE

size_t mbsrtowcs(wchar_t * ws, const char ** src, size_t wn, mbstate_t * st)
{
	const unsigned char *s = (const void *)*src;
	size_t wn0 = wn;
	unsigned c = 0;

	if (st && (c = *(unsigned *)st)) {
		if (ws) {
			*(unsigned *)st = 0;
			goto resume;
		} else {
			goto resume0;
		}
	}

	if (MB_CUR_MAX==1) {
		if (!ws) return strlen((const char *)s);
		for (;;) {
			if (!wn) {
				*src = (const void *)s;
				return wn0;
			}
			if (!*s) break;
			c = *s++;
			*ws++ = CODEUNIT(c);
			wn--;
		}
		*ws = 0;
		*src = 0;
		return wn0-wn;
	}

	if (!ws) for (;;) {
		if (*s-1u < 0x7f) {
			s++;
			wn--;
			continue;
		}
		if (*s-SA > SB-SA) break;
		c = bittab[*s++-SA];
resume0:
		if (OOB(c,*s)) { s--; break; }
		s++;
		if (c&(1U<<25)) {
			if (*s-0x80u >= 0x40) { s-=2; break; }
			s++;
			if (c&(1U<<19)) {
				if (*s-0x80u >= 0x40) { s-=3; break; }
				s++;
			}
		}
		wn--;
		c = 0;
	} else for (;;) {
		if (!wn) {
			*src = (const void *)s;
			return wn0;
		}
		if (*s-1u < 0x7f) {
			*ws++ = *s++;
			wn--;
			continue;
		}
		if (*s-SA > SB-SA) break;
		c = bittab[*s++-SA];
resume:
		if (OOB(c,*s)) { s--; break; }
		c = (c<<6) | *s++-0x80;
		if (c&(1U<<31)) {
			if (*s-0x80u >= 0x40) { s-=2; break; }
			c = (c<<6) | *s++-0x80;
			if (c&(1U<<31)) {
				if (*s-0x80u >= 0x40) { s-=3; break; }
				c = (c<<6) | *s++-0x80;
			}
		}
		*ws++ = c;
		wn--;
		c = 0;
	}

	if (!c && !*s) {
		if (ws) {
			*ws = 0;
			*src = 0;
		}
		return wn0-wn;
	}
	errno = EILSEQ;
	if (ws) *src = (const void *)s;
	return -1;
}
