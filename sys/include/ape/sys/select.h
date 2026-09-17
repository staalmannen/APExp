#ifndef __SELECT_H
#define __SELECT_H

#pragma lib "/$M/lib/ape/libap.a"

/* POSIX lists suseconds_t here too; same guard as <sys/time.h>. */
#ifndef __suseconds_t_defined
#define __suseconds_t_defined
typedef long suseconds_t;
#endif

#include <fdset_generic.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int select(int, fd_set*, fd_set*, fd_set*, struct timeval *);

#ifdef __cplusplus
}
#endif

#endif
