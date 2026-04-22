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

/* musl expects ssize_t */
#ifndef _SSIZE_T
#define _SSIZE_T
typedef long ssize_t;
#endif

/* -------------------------------------------------------------
 * errno handling – APExp already provides global 'errno'
 * ------------------------------------------------------------- */

#ifndef errno
extern int errno;
#endif

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
