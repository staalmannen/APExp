#ifndef __SYS_UIO_H__
#define __SYS_UIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#pragma lib "/$M/lib/ape/libap.a"

/*
 * size_t for iov_len and ssize_t for the two return values. This header
 * used both and included nothing, so it compiled only when something
 * else had defined them first. LibreSSL's include/compat/sys/uio.h
 * reaches this one through #include_next before anything else has:
 *
 *   /sys/include/ape/sys/uio.h:20 syntax error, last name: size_t
 */
#include <stddef.h>
#include <sys/types.h>

/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)uio.h	7.1 (Berkeley) 6/4/86
 */

struct iovec {
      void  *iov_base;   /* was char * */
      size_t iov_len;    /* was int */
  };

/*
 * POSIX gives both an ssize_t return, and they said int. On amd64 that
 * is the readlinkat bug again (see ap/unistd/at_functions.c): the
 * callee writes four bytes where an ssize_t caller reads eight, so the
 * top half is whatever was in the register. ap/unistd/writev.c and
 * readv.c return ssize_t to match.
 *
 * Not const-qualified, unlike POSIX's "const struct iovec *", because
 * the definitions are not either and a declaration that disagrees with
 * its definition is worse than one that is merely lax. A caller passing
 * a non-const array is unaffected.
 */
extern ssize_t writev(int, struct iovec*, int);
extern ssize_t readv(int, struct iovec*, int);

#ifdef __cplusplus
}
#endif

#endif /* !__SYS_UIO_H__ */
