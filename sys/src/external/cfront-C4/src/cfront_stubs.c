/* cfront runtime stubs for pure C build */
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <signal.h>
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

static void early_init(void) {
    signal(SIGSEGV, crash_handler);
    signal(SIGBUS, crash_handler);
    out_file = stdout;
    in_file = stdin;
}

void _main(void) { /* no C++ global constructors needed */ }

/* ------------------------------------------------------------------ */
/* EH runtime: setjmp/longjmp exception handling for cfront            */
/* ------------------------------------------------------------------ */

#include <setjmp.h>
#include <string.h>

/* NOTE: layout must match the struct emitted in generated C by print.c case 100.
 * __env[64]: jmp_buf storage (512 B on 64-bit, always >= any real jmp_buf).
 * exc_buf[256]: separate storage for the thrown value (not overlapping jmp_buf).
 */
struct __cfront_eh_frame {
    long __env[64]; /* jmp_buf -- must be first */
    struct __cfront_eh_frame *prev;
    void *exception; /* points into exc_buf after throw */
    const char *exception_type;
    unsigned char exc_buf[256]; /* copy of thrown value */
};

struct __cfront_eh_frame *__cfront_eh_top = 0;

int __cfront_setjmp(struct __cfront_eh_frame *f) { return setjmp(*(jmp_buf *)f->__env); }

void __cfront_throw(unsigned long sz, const char *tname, void *val) {
    struct __cfront_eh_frame *f = __cfront_eh_top;
    if (!f) {
        fprintf(stderr, "cfront: unhandled exception: %s\n", tname ? tname : "?");
        abort();
    }
    if (sz > sizeof(f->exc_buf))
        sz = sizeof(f->exc_buf);
    if (val && sz)
        memcpy(f->exc_buf, val, sz);
    f->exception = f->exc_buf;
    f->exception_type = tname;
    longjmp(*(jmp_buf *)f->__env, 1); /* jmp_buf not corrupted -- exc_buf is separate */
}

void __cfront_rethrow(void) {
    struct __cfront_eh_frame *f = __cfront_eh_top;
    if (!f) {
        fprintf(stderr, "cfront: rethrow with no active exception\n");
        abort();
    }
    longjmp(*(jmp_buf *)f->__env, 1);
}

int __cfront_eh_match(struct __cfront_eh_frame *f, const char *tname) {
    if (!f || !f->exception_type || !tname)
        return 0;
    return strcmp(f->exception_type, tname) == 0;
}

/* __vec_new: allocate array and call constructor for each element */
void *__vec_new(void *p, int n, int sz, void *ctor) {
    if (!p)
        p = calloc((size_t)n, (size_t)sz);
    if (!p)
        return 0;
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
    if (!p)
        return;
    if (dtor && n > 0) {
        /* dtor signature: void (*)(T*, int) - the int is a "free" flag */
        char *q = n > 0 ? (char *)p + (n - 1) * sz : (char *)p;
        typedef void (*DtorFn)(void *, int);
        DtorFn fn = (DtorFn)dtor;
        int i;
        for (i = n - 1; i >= 0; i--, q -= sz)
            fn(q, 0); /* 0 = don't free the element itself */
    }
    if (del)
        free(p);
}
