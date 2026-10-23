#ifndef __STDDEF_ARCH_H
#define __STDDEF_ARCH_H

/*
 * 386 is ILP32: `long' and a pointer are both 32 bits, so `ptrdiff_t'
 * is a plain `long' and `size_t' is a plain `unsigned long'.
 *
 * NOTHING IS DEFINED HERE BUT `_ptrdiff_t', AND THE FILE STILL HAS TO
 * EXIST.  <stddef.h> includes <stddef_arch.h> UNCONDITIONALLY, and so
 * do <sys/types.h>, <limits_generic.h> and <stdint_generic.h> -- so a
 * missing copy is not a fallback, it is a failure at the first
 * `#include <stddef.h>' in the first file compiled.  **Before this
 * file, `objtype=386 mk install' could not get past that point.**
 *
 * The header exists at all because the 64-bit targets need it:
 * amd64, arm64 and power64 are LLP64 under kencc -- pointers are 64
 * bits and `unsigned long' is 32 -- so each of those defines `size_t'
 * and `ssize_t' here, ahead of <stddef.h>'s own `#ifndef _SIZE_T' arm,
 * which would otherwise hand back a 32-bit `unsigned long'.  *On 386
 * that arm is already right*, and the surest way to keep it right is to
 * leave it alone: `_BITS64' is not defined by `386/include/ape/
 * _apetypes.h', so <stddef.h> takes the `unsigned long' branch by
 * itself.
 *
 * THE TRAILING INCLUDE IS THE SAME SHAPE THE 64-BIT COPIES USE, and it
 * is not circular.  Reached from <stddef.h>, `__STDDEF_H' is already
 * set, so the include below is a no-op and control returns.  Reached
 * first -- which is what <sys/types.h> does -- this file defines its
 * types and then pulls <stddef.h>, whose own include of this file is
 * now guarded.  Either order ends with both headers complete.
 *
 * SEVEN ARCHITECTURES STILL HAVE NO COPY: 68020, arm, mips, power,
 * sparc, sparc64 and spim.  The first five and spim are ILP32 and want
 * exactly this file; **sparc64 is 64-bit and wants amd64's**, which is a
 * different file and not a copy of this one.  They are left out
 * deliberately rather than written blind: a cross build stops at the
 * first thing missing and there will be more than this, so the next one
 * should be found by a build rather than guessed by a reader.
 */
typedef long _ptrdiff_t;

#include "/sys/include/ape/stddef.h"

#endif /* __STDDEF_ARCH_H */
