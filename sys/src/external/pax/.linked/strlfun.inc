#if 0 /* comment in gmake; next line ignored by gcc */
ifeq (0,gmake ignores from here)
#endif
/*-
 * Copyright (c) 2006, 2008, 2011
 *	mirabilos <m@mirbsd.org>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un-
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person's immediate fault when using the work as intended.
 *-
 * The original implementations of strlcpy(3) and strlcat(3) are from
 * Todd C. Miller; its licence is reproduced in the L_strlcpy part as
 * it applies to only that now; mirabilos rewrote strlcat from specs,
 * optimised both from suggestions by Bodo Eggert, aliased strlcpy as
 * just-copying strxfrm(3) and introduced wcslcat(3), wcslcpy(3) and,
 * symmetrically, wcsxfrm(3) as wide character variants.
 */

#include <sys/types.h>
#if defined(MBSDPORT_H)
#include MBSDPORT_H
#elif !defined(OUTSIDE_OF_LIBKERN)
#include <libckern.h>
#endif

#ifndef __RCSID
#define __RCSID(x)		/* fallback */ static const char __rcsid[] = x
#endif

__RCSID("$MirOS: src/bin/pax/.linked/strlfun.inc,v 1.9 2020/09/06 02:24:02 tg Exp $");

#ifdef WIDEC
#if defined(MBSDPORT_H) || defined(OUTSIDE_OF_LIBKERN)
#ifdef __WCHAR_TYPE__
typedef __WCHAR_TYPE__ wchar_t;
#else
#include <wchar.h>
#endif
#endif
/* wide character string functions */
#define NUL			L'\0'
#define char_t			wchar_t
#define fn_len			wcslen
#define	fn_cat			wcslcat
#define fn_cpy			wcslcpy
#else
/* (multibyte) string functions */
#define NUL			'\0'
#define char_t			char
#define fn_len			strlen
#define	fn_cat			strlcat
#define fn_cpy			strlcpy
#endif

#ifdef L_strxfrm
#define strlcpy			strxfrm
#define wcslcpy			wcsxfrm
#define L_strlcpy
#endif

#if defined(MBSDPORT_H) || defined(OUTSIDE_OF_LIBKERN)
extern size_t fn_len(const char_t *);
#ifdef NEED_STRLFUN_PROTOS
size_t fn_cat(char_t *, const char_t *, size_t);
size_t fn_cpy(char_t *, const char_t *, size_t);
#endif
#endif

#ifndef __predict_true
#define __predict_true(exp)	(exp)
#define __predict_false(exp)	(exp)
#endif

#ifdef L_strlcat
/*
 * Appends src to string dst of size dlen (unlike strncat, dlen is the
 * full size of dst, not space left).  At most dlen-1 characters
 * will be copied.  Always NUL terminates (unless dlen <= strlen(dst)).
 * Returns strlen(src) + MIN(dlen, strlen(initial dst)), without the
 * trailing NUL byte counted.  If retval >= dlen, truncation occurred.
 */
size_t
fn_cat(char_t *dst, const char_t *src, size_t dlen)
{
	size_t n = 0, slen;

	slen = fn_len(src);
	while (__predict_true(n + 1 < dlen && dst[n] != NUL))
		++n;
	if (__predict_false(dlen == 0 || dst[n] != NUL))
		return (dlen + slen);
	while (__predict_true((slen > 0) && (n < (dlen - 1)))) {
		dst[n++] = *src++;
		--slen;
	}
	dst[n] = NUL;
	return (n + slen);
}
#endif

#ifdef L_strlcpy
/* $OpenBSD: strlcpy.c,v 1.11 2006/05/05 15:27:38 millert Exp $ */

/*-
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t
fn_cpy(char_t *dst, const char_t *src, size_t siz)
{
	const char_t *s = src;

	if (__predict_false(siz == 0))
		goto traverse_src;

	/* copy as many chars as will fit */
	while (--siz && (*dst++ = *s++))
		;

	/* not enough room in dst */
	if (__predict_false(siz == 0)) {
		/* safe to NUL-terminate dst since we copied <= siz-1 chars */
		*dst = NUL;
 traverse_src:
		/* traverse rest of src */
		while (*s++)
			;
	}

	/* count does not include NUL */
	return (s - src - 1);
}
#endif

#if 0 /* gcc ignored from here; gmake stops ignoring */
endif

USE_WIDEC?=	1

LIB=		libstrlfun.a
OBJS=		strlcpy.o strlcat.o
ifeq (1,$(strip $(USE_WIDEC)))
OBJS+=		wcslcpy.o wcslcat.o
endif
DEFS=		-DOUTSIDE_OF_LIBKERN
DEFS_strlcpy.o=	-DL_strlcpy
DEFS_strlcat.o=	-DL_strlcat
DEFS_wcslcpy.o=	-DL_strlcpy -DWIDEC
DEFS_wcslcat.o=	-DL_strlcat -DWIDEC

all: $(LIB)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	-ranlib $(LIB)

$(OBJS): strlfun.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEFS) $(DEFS_$@) -c -o $@ strlfun.c

#endif /* EOF for gmake and gcc */
