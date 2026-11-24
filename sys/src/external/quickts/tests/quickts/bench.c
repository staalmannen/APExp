/* quickts benchmark: parse cost and peak heap for compiling one module.
 *
 *   cc -O2 -I<quickjs> bench.c <quickjs>/libquickjs.a -lm -lpthread -ldl -o bench
 *   ./bench <file> <iterations> [--ts]
 *
 * Reports wall time per compile and the high-water mark of the QuickJS heap,
 * measured through a wrapping allocator. The point of comparison is the Nim
 * transpiler, whose token array is a separate ~430 KB - 1.4 MB allocation
 * *outside* this heap for a 36 KB app.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "quickjs.h"

#ifndef JS_EVAL_FLAG_TYPESCRIPT
#define JS_EVAL_FLAG_TYPESCRIPT 0
#endif

static size_t live_bytes, peak_bytes;

static void *b_malloc(JSMallocState *opaque, size_t n)
{
    size_t *p = malloc(n + 16);
    if (!p)
        return NULL;
    *p = n;
    live_bytes += n;
    if (live_bytes > peak_bytes)
        peak_bytes = live_bytes;
    return (char *)p + 16;
}

static void b_free(JSMallocState *opaque, void *ptr)
{
    size_t *p;
    if (!ptr)
        return;
    p = (size_t *)((char *)ptr - 16);
    live_bytes -= *p;
    free(p);
}

static void *b_realloc(JSMallocState *opaque, void *ptr, size_t n)
{
    size_t *p, old = 0;
    if (ptr) {
        p = (size_t *)((char *)ptr - 16);
        old = *p;
    } else {
        p = NULL;
    }
    if (n == 0) {
        b_free(opaque, ptr);
        return NULL;
    }
    p = realloc(p, n + 16);
    if (!p)
        return NULL;
    *p = n;
    live_bytes += n - old;
    if (live_bytes > peak_bytes)
        peak_bytes = live_bytes;
    return (char *)p + 16;
}

static const JSMallocFunctions mf = {
    .js_malloc = b_malloc,
    .js_free = b_free,
    .js_realloc = b_realloc,
    .js_malloc_usable_size = NULL,
};

static double now_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

int main(int argc, char **argv)
{
    const char *path;
    int iters, ts = 0, i;
    FILE *f;
    long len;
    char *buf;
    JSRuntime *rt;
    JSContext *ctx;
    double t0, t1;
    size_t base_peak;

    if (argc < 3) {
        fprintf(stderr, "usage: bench <file> <iterations> [--ts]\n");
        return 1;
    }
    path = argv[1];
    iters = atoi(argv[2]);
    for (i = 3; i < argc; i++)
        if (!strcmp(argv[i], "--ts"))
            ts = 1;

    f = fopen(path, "rb");
    if (!f) {
        perror(path);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = malloc(len + 1);
    if (fread(buf, 1, len, f) != (size_t)len) {
        perror("read");
        return 1;
    }
    buf[len] = 0;
    fclose(f);

    rt = JS_NewRuntime2(&mf, NULL);
    ctx = JS_NewContext(rt);

    /* warm up and record the heap the runtime itself holds */
    JS_FreeValue(ctx, JS_Eval(ctx, buf, len, path,
                              JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY |
                              (ts ? JS_EVAL_FLAG_TYPESCRIPT : 0)));
    base_peak = 0;
    peak_bytes = live_bytes;

    t0 = now_ms();
    for (i = 0; i < iters; i++) {
        size_t start = live_bytes, delta;
        JSValue v;
        peak_bytes = live_bytes;
        v = JS_Eval(ctx, buf, len, path,
                    JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY |
                    (ts ? JS_EVAL_FLAG_TYPESCRIPT : 0));
        if (JS_IsException(v)) {
            JSValue e = JS_GetException(ctx);
            const char *msg = JS_ToCString(ctx, e);
            fprintf(stderr, "compile failed: %s\n", msg ? msg : "?");
            return 1;
        }
        delta = peak_bytes - start;
        if (delta > base_peak)
            base_peak = delta;      /* reused as the per-compile high water */
        JS_FreeValue(ctx, v);
    }
    t1 = now_ms();

    printf("%-3s %6ld bytes source  %7.3f ms/compile  peak heap for one "
           "compile %7zu bytes\n",
           ts ? "ts" : "js", len, (t1 - t0) / iters, base_peak);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
    free(buf);
    return 0;
}
