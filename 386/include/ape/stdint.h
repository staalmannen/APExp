#ifndef _APEXP_STDINT_H_
#define _APEXP_STDINT_H_

/*
 * <stdint.h> for 386
 *
 * Two lines, because the content cannot live under this name. pcc passes
 *
 *	-I/$objtype/include/ape	 before	 -I/sys/include/ape
 *
 * (pcc.c:234-235), and stock 9front APE keeps a stdint.h in the
 * architecture directory. So a copy has to exist in each architecture
 * directory to shadow the host's, and none of those copies can reach
 * "the other stdint.h" by that name -- the search would find itself.
 * Hence stdint_generic.h.
 *
 * The stock header was not merely being preferred, it was disabling
 * APExp's: it defines _STDINT_ARCH_H_, which is the guard on APExp's own
 * stdint_arch.h, so that file compiled to nothing and INTPTR_WIDTH was
 * never set. SIZE_MAX is chosen by "#if INTPTR_WIDTH == 64", so it came
 * out 0xffffffff on amd64 while size_t stayed 8 bytes -- and gnulib's
 *
 *	argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize
 *
 * then never looked for the NUL, which is how GNU ls came to read its
 * way off the end of the heap.
 */
#include <stdint_arch.h>
#include <stdint_generic.h>

#endif /* _APEXP_STDINT_H_ */
