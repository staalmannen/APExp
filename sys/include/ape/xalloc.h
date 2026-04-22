#ifndef _XALLOC_H
#define _XALLOC_H

#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Called on allocation failure; default prints "memory exhausted" and exits.
 * Programs may replace this with their own handler. */
extern void xalloc_die(void);

extern void *xmalloc(size_t);
extern void *xcalloc(size_t, size_t);
extern void *xrealloc(void *, size_t);
extern void *xmemdup(const void *, size_t);
extern char *xstrdup(const char *);
extern char *xstrndup(const char *, size_t);
extern void *xnrealloc(void *, size_t *, size_t);

/* Convenience: typed versions */
#define XMALLOC(t, n)       ((t *)xmalloc((n) * sizeof(t)))
#define XCALLOC(t, n)       ((t *)xcalloc((n), sizeof(t)))
#define XREALLOC(t, p, n)   ((t *)xrealloc((p), (n) * sizeof(t)))

#ifdef __cplusplus
}
#endif

#endif /* _XALLOC_H */
