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
 * It calls a name of our own rather than abort() directly, and does not
 * declare abort here. gnulib's copy declares abort itself, and copying
 * that cost a build:
 *
 *   /sys/include/ape/stdlib.h:36 external redeclaration of: abort
 *       EXTERN FUNC(VOID) VOID       stdlib.h:36
 *       EXTERN FUNC(VOID) NORET VOID stddef.h:75
 *
 * The two spellings are identical in the source, so this is the
 * compiler declining to see a _Noreturn function declared twice: it
 * keeps NORET from the first and compares the second without it. A
 * distinct name cannot collide with anything, whichever order the
 * headers are read in, and __ape_unreachable() in libap does the
 * abort(). Better than __builtin_unreachable(), which pcc swallows into
 * a constant -- a no-op that neither traps nor tells the optimiser
 * anything.
 *
 * C++ has std::unreachable and no _Noreturn, so the block sits outside
 * it.
 */
#ifndef __cplusplus
#ifndef unreachable
extern _Noreturn void __ape_unreachable(void);
#define unreachable() __ape_unreachable()
#endif
#endif

#endif /* __STDDEF_H */
