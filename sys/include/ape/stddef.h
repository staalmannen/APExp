#ifndef __STDDEF_H
#define __STDDEF_H

#include <_apetypes.h>
#include <stddef_arch.h>

#ifndef __STDDEF_ARCH_H
typedef long _ptrdiff_t;
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#define offsetof(ty,mem) ((size_t) &(((ty *)0)->mem))

typedef _ptrdiff_t ptrdiff_t;
typedef long max_align_t;
#ifndef _SIZE_T
#define _SIZE_T
#ifdef _BITS64
typedef unsigned long long size_t;
#else
typedef unsigned long size_t;
#endif
#endif
#ifndef _WCHAR_T
#define _WCHAR_T
/*
 * wchar_t must be 32 bits, matching Rune in <utf.h>.
 *
 * It was "unsigned short", which contradicted the rest of the system in
 * three ways:
 *
 *  - pcc emits L"..." as an array of Rune. See cc.y, where a wide string
 *    literal is built with "$$->type->width = $1.l + sizeof(Rune)" and
 *    "$$->rstring = (Rune*)$1.s". So "wchar_t *p = L\"abc\";" handed a
 *    16-bit pointer to a 32-bit array and walked it at the wrong stride.
 *  - <wchar.h> defines WCHAR_MAX as Runemax, 0x10FFFF, which does not
 *    fit in 16 bits.
 *  - 16 bits cannot hold anything above the BMP, while Plan 9 is UTF-8
 *    throughout and libap's own wide functions operate on wchar_t.
 *
 * Nothing assumed the old width: every user in libap and the APE headers
 * goes through sizeof(wchar_t).
 */
typedef unsigned int wchar_t;
#endif

/*
 * C23 7.21.1: unreachable() expands to a void expression whose
 * execution is undefined behaviour. It belongs in this header, and
 * gnulib's generated <stddef.h> supplied it -- that wrapper is pruned
 * here for shadowing this one, so without it a caller gets an implicit
 * function and the link fails:
 *
 *   diff_2_files: undefined: unreachable in diff_2_files
 *
 * abort() is gnulib's own fallback for a compiler with no
 * __builtin_unreachable, and is what pcc needs: it swallows unknown
 * __builtin_* calls and yields a constant, so __builtin_unreachable()
 * would compile to a no-op that neither traps nor informs the
 * optimiser. Reaching abort() is at least honest about the bug.
 *
 * abort is declared here rather than pulling in <stdlib.h>, as gnulib
 * also does; the declaration matches the one in <stdlib.h> exactly, so
 * the two can be seen in either order. C++ has its own std::unreachable
 * and no _Noreturn, so the whole block sits outside it.
 */
#ifndef __cplusplus
#ifndef unreachable
extern _Noreturn void abort(void);
#define unreachable() abort()
#endif
#endif

#endif /* __STDDEF_H */
