#ifndef __SELECT_H
#define __SELECT_H
#ifndef _BSD_EXTENSION
    This header file is an extension to ANSI/POSIX
#endif
#pragma lib "/$M/lib/ape/libap.a"

#include <fdset_generic.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int select(int, fd_set*, fd_set*, fd_set*, struct timeval *);

#ifdef __cplusplus
}
#endif

#endif
