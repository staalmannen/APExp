#ifndef __STDIO_EXT_H__
#define __STDIO_EXT_H__

#pragma lib "/$M/lib/ape/libap.a"

/*
 * <stdio_ext.h>: accessors for stdio state that the standard API does
 * not expose. Originally Solaris; glibc and musl both provide a subset.
 *
 * These matter because gnulib's freadahead, fseterr and fwriting
 * modules each begin with a "#if HAVE___FREADAHEAD / musl libc" branch
 * that simply forwards to the function here. Without them gnulib falls
 * through to a long #elif chain that reads FILE internals directly, one
 * platform at a time, and picks its Plan 9 branch on the strength of
 * EPLAN9 being defined -- which then reads fp->state, fp->rp and fp->wp
 * from the old APE FILE that APExp no longer uses.
 *
 * The set implemented follows musl.
 */

#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Bytes buffered for reading, including anything pushed back by ungetc. */
extern size_t __freadahead(FILE *);

/* Bytes buffered for writing but not yet flushed. */
extern size_t __fpending(FILE *);

/* Set the stream's error indicator. */
extern void __fseterr(FILE *);

/* Stream orientation. */
extern int __freading(FILE *);
extern int __fwriting(FILE *);

#ifdef __cplusplus
}
#endif

#endif /* __STDIO_EXT_H__ */
