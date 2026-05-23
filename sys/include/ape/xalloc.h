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
extern void *xreallocarray(void *, size_t, size_t);
extern void *xnmalloc(size_t, size_t);
extern void *xnrealloc(void *, size_t, size_t);  /* fixed resize to n*s */
extern void *xmemdup(const void *, size_t);
extern char *xcharalloc(size_t);
extern void *xzalloc(size_t);
extern char *xstrdup(const char *);
extern char *xstrndup(const char *, size_t);
extern void *x2nrealloc(void *, size_t *, size_t);  /* growing: ~1.5x */
extern void *x2realloc(void *, size_t *);
extern void *xpalloc(void *, ptrdiff_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t);

/* Convenience: typed versions */
#define XMALLOC(t, n)        ((t *)xmalloc((n) * sizeof(t)))
#define XCALLOC(t, n)        ((t *)xcalloc((n), sizeof(t)))
#define XREALLOC(t, p, n)    ((t *)xrealloc((p), (n) * sizeof(t)))
#define XNMALLOC(n, t)       ((t *)xnmalloc((n), sizeof(t)))
#define XNREALLOC(p, n, t)   ((t *)xnrealloc((p), (n), sizeof(t)))

#ifdef __cplusplus
}
#endif

#endif /* _XALLOC_H */
