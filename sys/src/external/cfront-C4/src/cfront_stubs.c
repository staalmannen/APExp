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

void *__vec_new(void *p, int n, int sz, void *ctor) {
    (void)ctor;
    if (!p) p = malloc((size_t)n * (size_t)sz);
    return p;
}

void __vec_delete(void *p, int n, int sz, void *dtor, int del, int d) {
    (void)sz; (void)dtor; (void)d;
    if (del && p) free(p);
}
