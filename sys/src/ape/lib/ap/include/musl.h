/* musl_compat.h – minimal libc glue for musl stdio on APExp */

#ifndef MUSL_COMPAT_H
#define MUSL_COMPAT_H

/* -------------------------------------------------------------
 * Basic standard C types that musl stdio expects
 * ------------------------------------------------------------- */

#include <u.h>
#include <libc.h>      /* APExp / APE libc */
#include <stddef.h>
#include <stdint.h>

/*
 * musl expects ssize_t. <sys/types.h> is reached through <libc.h>
 * above and uses this same guard, so this fallback normally does not
 * fire; it must still agree with it, because "long" is 32 bits on
 * amd64 and a 32-bit ssize_t against a 64-bit caller reads four bytes
 * of stack garbage in the top half.
 */
#ifndef _SSIZE_T
#define _SSIZE_T
#ifdef _BITS64
typedef long long ssize_t;
#else
typedef long ssize_t;
#endif
#endif

/* -------------------------------------------------------------
 * errno handling
 *
 * APE has no "int errno" to declare: <errno.h> defines
 *
 *	extern int *_errnoloc;
 *	#define errno (*_errnoloc)
 *
 * so &errno below is _errnoloc, which is what __errno_location has to
 * return.  This used to be
 *
 *	#ifndef errno
 *	extern int errno;
 *	#endif
 *
 * which is a reference to a symbol that does not exist anywhere in
 * libap.  It never fired only because <libc.h> above includes <utf.h>,
 * which includes <stdio.h>, which used to include stdio_impl.h, which
 * includes <errno.h> -- so the macro happened to be defined by the
 * time this file was read.  When <stdio.h> stopped dragging errno in,
 * every object that reaches this header without naming <errno.h> first
 * -- locale_stubs.o among them, so anything that calls setlocale --
 * came out referencing it, and the link failed:
 *
 *	errno: not defined
 *
 * seen first from dash, whose main() calls setlocale(LC_ALL, "").
 * Including <errno.h> here is unconditional and order-independent.
 * ------------------------------------------------------------- */

#include <errno.h>

/* musl stdio expects a macro to retrieve errno */
static inline int *__errno_location(void) {
    return &errno;
}

/* -------------------------------------------------------------
 * System call wrappers musl stdio needs:
 *   read / write / seek / close
 * ------------------------------------------------------------- */

static inline ssize_t sys_read(int fd, void *buf, size_t n) {
    return read(fd, buf, n);
}

static inline ssize_t sys_write(int fd, const void *buf, size_t n) {
    return write(fd, buf, n);
}

static inline off_t sys_lseek(int fd, off_t off, int whence) {
    return seek(fd, off, whence);
}

static inline int sys_close(int fd) {
    return close(fd);
}

/* -------------------------------------------------------------
 * Memory helpers musl uses internally
 * ------------------------------------------------------------- */

static inline void *musl_malloc(size_t n) { return malloc(n); }
static inline void musl_free(void *p) { free(p); }

/* APExp APE provides realloc, calloc, strdup via libc.h */

#endif /* MUSL_COMPAT_H */
