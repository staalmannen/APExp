#ifndef __LOCK_H
#define __LOCK_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * ***THERE IS NO `#include <u.h>' HERE ANY MORE, AND NOTHING IN THIS
 * FILE EVER USED IT.***  `Lock' is `{ int val; }' and the four
 * declarations below take `int' and `Lock*': `ulong', `uchar',
 * `ushort', `uint', `schar', `vlong' and `uvlong' were never
 * referenced.  *The include was pure cost.*
 *
 * And the cost is not small, because of where this header sits:
 *
 *	locale.h -> alltypes.h -> pthread.h -> lock.h -> u.h
 *
 * `<locale.h>' is included by almost everything, so every such
 * translation unit was getting Plan 9's type names in its namespace.
 * **CLISP is where it surfaced**: `lispbibl.d:13910' defines
 * `static inline chart schar (object string, uintL index)', and
 * `u.h:18' is `typedef signed char schar;' --
 *
 *	lispbibl.d:13910 external redeclaration of: schar
 *	  STATIC FUNC(IND VOID, ULONG) ULONG
 *	  TYPEDEF CHAR  /sys/include/ape/u.h:18
 *
 * ***THIS IS THE THIRD TIME THE SAME CHAIN HAS COST SOMETHING.***
 * `<string.h>' carries the note about `string.h -> wchar.h -> time.h
 * -> signal.h -> pthread.h -> lock.h -> u.h', which redefined the
 * Objective-C runtime's `nil'; `<signal.h>' carries its own about
 * reaching `<pthread.h>' for a pointer.  Both cut their link.  *The
 * link out of `pthread.h' could not be cut the same way* -- that
 * header embeds `Lock', `QLock' and `Rendez' BY VALUE, so it needs
 * the complete types -- which is why the cut belongs here, at the
 * end of the chain where the include buys nothing at all.
 *
 * **The two files that take `u.h' types THROUGH this header both
 * include `<lib9.h>' on the next line**, and `lib9.h' includes
 * `<u.h>' itself: `lib/ap/include/libc.h:12-14' and
 * `external/PDCursesMod/plan9/pdcutil.c:6-8'.  They were the whole
 * blast radius and they are unaffected.  The other `u.h' includers --
 * `auth.h', `bio.h', `draw.h', `fmt.h', `lib9.h', `libsec.h', `mp.h'
 * -- keep theirs, because those are Plan 9 API headers whose
 * declarations really do use the types.
 */

typedef struct
{
	int	val;
} Lock;

#ifdef __cplusplus
extern "C" {
#endif

extern	void	lock(Lock*);
extern	void	unlock(Lock*);
extern	int	canlock(Lock*);
extern	int	tas(int*);


#ifdef __cplusplus
}
#endif

#endif
