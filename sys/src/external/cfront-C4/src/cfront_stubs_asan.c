/* cfront runtime stubs - ASan version */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

extern void *out_file;
extern void *in_file;

static void early_init(void) {
    out_file = stdout;
    in_file  = stdin;
}

void _main(void) {}

void *__vec_new(void *p, int n, int sz, void *ctor) {
    if (!p) p = calloc((size_t)n, (size_t)sz);
    if (!p) return 0;
    if (ctor) {
        char *q = (char *)p;
        typedef void *(*CtorFn)(void *);
        CtorFn fn = (CtorFn)ctor;
        int i;
        for (i = 0; i < n; i++, q += sz)
            fn(q);
    }
    return p;
}

void __vec_delete(void *p, int n, int sz, void *dtor, int del, int d) {
    if (!p) return;
    if (dtor && n > 0) {
        char *q = (char *)p + (n-1) * sz;
        typedef void (*DtorFn)(void *, int);
        DtorFn fn = (DtorFn)dtor;
        int i;
        for (i = n-1; i >= 0; i--, q -= sz)
            fn(q, 0);
    }
    if (del) free(p);
}
