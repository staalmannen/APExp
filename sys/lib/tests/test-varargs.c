/*
 * test-varargs.c - Verify that va_arg reads the correct values for all types.
 *
 * On Plan9 amd64, all arguments are in 8-byte stack slots.
 * va_arg uses pointer arithmetic (stdarg_arch.h).  If any slot is read at
 * the wrong offset the value will be wrong.
 *
 * Compile: pcc -o test-varargs test-varargs.c
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int fails = 0;

#define EXPECT(label, got, want) do { \
    if ((got) != (want)) { \
        fprintf(stderr, "FAIL %s: got %lld want %lld\n", \
                (label), (long long)(got), (long long)(want)); \
        fails++; \
    } else { \
        printf("PASS %s\n", (label)); \
    } \
} while(0)

/* ---- int ---- */
static void
chk_int(int want, ...)
{
    va_list ap;
    int v;
    va_start(ap, want);
    v = va_arg(ap, int);
    va_end(ap);
    EXPECT("int first-arg", v, want);
}

/* ---- multiple ints ---- */
static void
chk_3int(int a, int b, int c, ...)
{
    va_list ap;
    int x, y, z;
    va_start(ap, c);
    x = va_arg(ap, int);
    y = va_arg(ap, int);
    z = va_arg(ap, int);
    va_end(ap);
    EXPECT("3int [0]", x, a);
    EXPECT("3int [1]", y, b);
    EXPECT("3int [2]", z, c);
}

/* ---- long ---- */
static void
chk_long(long want, ...)
{
    va_list ap;
    long v;
    va_start(ap, want);
    v = va_arg(ap, long);
    va_end(ap);
    EXPECT("long first-arg", v, want);
}

/* ---- long long ---- */
static void
chk_ll(long long want, ...)
{
    va_list ap;
    long long v;
    va_start(ap, want);
    v = va_arg(ap, long long);
    va_end(ap);
    EXPECT("longlong first-arg", v, want);
}

/* ---- pointer ---- */
static void
chk_ptr(void *want, ...)
{
    va_list ap;
    void *v;
    va_start(ap, want);
    v = va_arg(ap, void *);
    va_end(ap);
    if (v != want) {
        fprintf(stderr, "FAIL ptr: got %p want %p\n", v, want);
        fails++;
    } else {
        printf("PASS ptr\n");
    }
}

/* ---- mixed: int, long long, int ---- */
static void
chk_mixed(int dummy, ...)
{
    va_list ap;
    int a, c;
    long long b;
    va_start(ap, dummy);
    a = va_arg(ap, int);
    b = va_arg(ap, long long);
    c = va_arg(ap, int);
    va_end(ap);
    EXPECT("mixed int[0]",     a, 11);
    EXPECT("mixed longlong",   b, 0x123456789abcLL);
    EXPECT("mixed int[1]",     c, 99);
}

/* ---- width+precision pattern used by sbase printf ---- */
static void
chk_width_prec_ll(int dummy, ...)
{
    va_list ap;
    int width, prec;
    long long val;
    va_start(ap, dummy);
    width = va_arg(ap, int);
    prec  = va_arg(ap, int);
    val   = va_arg(ap, long long);
    va_end(ap);
    EXPECT("w/p/ll width", width, 8);
    EXPECT("w/p/ll prec",  prec,  3);
    EXPECT("w/p/ll val",   val,   -42LL);
}

int
main(void)
{
    int sentinel = 0xdeadbeef;

    chk_int(42, 42, sentinel);
    chk_3int(10, 20, 30, 10, 20, 30);
    chk_long(0x7fffffffL, 0x7fffffffL, sentinel);
    chk_ll(0x7fffffffffffffffLL, 0x7fffffffffffffffLL, sentinel);
    chk_ptr((void *)0x1234, (void *)0x1234, sentinel);
    chk_mixed(0, 11, 0x123456789abcLL, 99);
    chk_width_prec_ll(0, 8, 3, -42LL);

    if (fails)
        fprintf(stderr, "%d test(s) FAILED\n", fails);
    else
        printf("all varargs tests passed\n");

    return fails ? 1 : 0;
}
