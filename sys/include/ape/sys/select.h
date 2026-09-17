#ifndef __SELECT_H
#define __SELECT_H

#pragma lib "/$M/lib/ape/libap.a"

/* POSIX lists suseconds_t here too; same guard as <sys/time.h>. */
#ifndef __suseconds_t_defined
#define __suseconds_t_defined
typedef long suseconds_t;
#endif

#ifndef _FD_SET_T
#define _FD_SET_T
/* BSD select, and adjunct types and macros */

/* assume 96 fds is sufficient for fdset size */

/*
 * A MARKER SO A TEST CAN SAY WHICH fd_set IT GOT. The host's stock APE
 * keeps its own <sys/types.h> and <sys/select.h> in the architecture
 * directory, which pcc searches FIRST (pcc.c:234-235), and this tree
 * has no sys/ there -- mount-include unions the directory rather than
 * replacing it, so stock's copies are still what a compile sees.
 * select-test.c section 11 prints whether this name is defined, which
 * is the same technique limits-test.c uses for float/stdarg/stdint.
 */
#ifndef _APEXP_FD_SET_T
#define _APEXP_FD_SET_T
#endif

typedef struct fd_set {
	long fds_bits[3];
} fd_set;

#define FD_SET(n,p)	((p)->fds_bits[(n)>>5] |= (1 << ((n) &0x1f)))
#define FD_CLR(n,p)	((p)->fds_bits[(n)>>5] &= ~(1 << ((n) &0x1f)))
#define FD_ISSET(n,p)	((p)->fds_bits[(n)>>5] & (1 << ((n) &0x1f)))
#define FD_ZERO(p)	((p)->fds_bits[0] =0, (p)->fds_bits[1] =0, (p)->fds_bits[2] =0)

#ifndef FD_SETSIZE
#define FD_SETSIZE	96
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int select(int, fd_set*, fd_set*, fd_set*, struct timeval *);

#ifdef __cplusplus
}
#endif

#endif
