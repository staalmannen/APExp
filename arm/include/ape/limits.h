#ifndef _APEXP_LIMITS_H_
#define _APEXP_LIMITS_H_

/*
 * <limits.h> -- a wrapper, and it has to exist in EVERY architecture
 * directory.
 *
 * pcc passes
 *
 *	-I/$objtype/include/ape	 before	 -I/sys/include/ape
 *
 * (pcc.c:234-235), and stock 9front APE keeps a limits.h in the
 * architecture directory. So this tree's sys/include/ape/limits.h was
 * never read by anything: `deeppath-test` printed PATH_MAX 1023 and
 * NAME_MAX 27, which are stock's values and match neither the 255/14
 * this tree used to define nor the 4096/255 it defines now.
 *
 * It is the same trap as float.h, stdarg.h and stdint.h before it, and
 * the guard makes it worse in the same way: this tree's file opened
 * with `#ifndef __LIMITS`, which is stock's guard too, so whichever was
 * read second compiled to nothing.
 *
 * The content lives in limits_generic.h because none of these copies
 * could reach "the other limits.h" by that name -- the search would
 * find itself. `__LIMITS` is defined here as well, so a stock header
 * reached by some other route is neutralised rather than fighting this
 * one.
 */
#define __LIMITS
#include <limits_generic.h>

#endif /* _APEXP_LIMITS_H_ */
