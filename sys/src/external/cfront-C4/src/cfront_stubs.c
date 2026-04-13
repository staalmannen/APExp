/* cfront runtime stubs for pure C build */
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
#include <stdio.h>

extern void *out_file;
extern void *in_file;

static void crash_handler(int sig) {
    char buf[16];
    int n = snprintf(buf, sizeof(buf), "SIG%d\n", sig);
    write(2, buf, n);
    void *bt[32];
    int nb = backtrace(bt, 32);
    backtrace_symbols_fd(bt, nb, 2);
    _exit(1);
}

__attribute__((constructor(101)))
static void early_init(void) {
    signal(SIGSEGV, crash_handler);
    signal(SIGBUS,  crash_handler);
    out_file = stdout;
    in_file  = stdin;
}

void _main(void) { /* no C++ global constructors needed */ }

/* __vec_new: allocate array and call constructor for each element */
void *__vec_new(void *p, int n, int sz, void *ctor) {
    if (!p) p = calloc((size_t)n, (size_t)sz);
    if (!p) return 0;
    if (ctor) {
        /* ctor signature: T* (*)(T*) - takes pointer, returns pointer */
        char *q = (char *)p;
        typedef void *(*CtorFn)(void *);
        CtorFn fn = (CtorFn)ctor;
        int i;
        for (i = 0; i < n; i++, q += sz)
            fn(q);
    }
    return p;
}

/* __vec_delete: call destructor for each element then free */
void __vec_delete(void *p, int n, int sz, void *dtor, int del, int d) {
    if (!p) return;
    if (dtor && n > 0) {
        /* dtor signature: void (*)(T*, int) - the int is a "free" flag */
        char *q = n > 0 ? (char *)p + (n-1) * sz : (char *)p;
        typedef void (*DtorFn)(void *, int);
        DtorFn fn = (DtorFn)dtor;
        int i;
        for (i = n-1; i >= 0; i--, q -= sz)
            fn(q, 0);  /* 0 = don't free the element itself */
    }
    if (del) free(p);
}
