/*
 * test-local-static.c - Test function-local static variables (CLOCAL class).
 *
 * The Plan9 C compiler assigns class CLOCAL (not CSTATIC) to static variables
 * declared inside a function.  All three locations in each arch's txt.c must
 * handle CLOCAL alongside CSTATIC:
 *   1. global emit loop
 *   2. naddr ONAME case
 *   3. gpseudo D_STATIC selection
 *
 * If any location is missing, the compiler generates a wrong address for the
 * variable.  The crash manifests as a write fault to a BSS-adjacent address
 * in larger programs (readline, etc.) but not in small tests.
 *
 * Compile: pcc -o test-local-static test-local-static.c
 * Run:     ./test-local-static
 */
#include <stdio.h>
#include <stdlib.h>

static int fails = 0;

#define EXPECT(label, got, want) do { \
    if ((got) != (want)) { \
        fprintf(stderr, "FAIL %s: got %d want %d\n", (label), (int)(got), (int)(want)); \
        fails++; \
    } else { \
        printf("PASS %s\n", (label)); \
    } \
} while(0)

/* Plain counter: static int initialised to 0 */
static int
counter(void)
{
    static int n = 0;
    return ++n;
}

/* Counter initialised to non-zero */
static int
counter_from(void)
{
    static int n = 100;
    return n--;
}

/* Static pointer */
static const char *
rotating_word(void)
{
    static int idx = 0;
    static const char *words[] = { "alpha", "beta", "gamma" };
    const char *w = words[idx % 3];
    idx++;
    return w;
}

/* Static flag: set once */
static int
set_once(void)
{
    static int done = 0;
    if (done) return 0;
    done = 1;
    return 1;
}

/* Nested: local static in inner scope */
static int
inner_scope(int x)
{
    if (x > 0) {
        static int saved = -1;
        saved = x;
        return saved;
    }
    return -1;
}

/* Two independent local statics in same function */
static void
two_statics(int *a_out, int *b_out)
{
    static int a = 10;
    static int b = 20;
    *a_out = a++;
    *b_out = b++;
}

/* Local static array */
static int
sum_via_static_array(int idx)
{
    static int acc[8] = {0};
    if (idx < 0 || idx >= 8) return -1;
    acc[idx] += idx + 1;
    return acc[idx];
}

/* Recursive function with local static */
static int
fib_memo(int n)
{
    static int cache[20] = {0};
    if (n <= 1) return n;
    if (n < 20 && cache[n]) return cache[n];
    int r = fib_memo(n-1) + fib_memo(n-2);
    if (n < 20) cache[n] = r;
    return r;
}

int
main(void)
{
    int a, b;

    /* counter */
    printf("=== counter\n");
    EXPECT("counter 1st", counter(), 1);
    EXPECT("counter 2nd", counter(), 2);
    EXPECT("counter 3rd", counter(), 3);

    /* counter_from */
    printf("=== counter_from\n");
    EXPECT("counter_from 1st", counter_from(), 100);
    EXPECT("counter_from 2nd", counter_from(),  99);

    /* rotating_word */
    printf("=== rotating_word\n");
    {
        const char *w0 = rotating_word();
        const char *w1 = rotating_word();
        const char *w2 = rotating_word();
        const char *w3 = rotating_word();
        if (w0[0]!='a' || w1[0]!='b' || w2[0]!='g' || w3[0]!='a') {
            fprintf(stderr, "FAIL rotating_word: got %s %s %s %s\n", w0,w1,w2,w3);
            fails++;
        } else {
            printf("PASS rotating_word\n");
        }
    }

    /* set_once */
    printf("=== set_once\n");
    EXPECT("set_once 1st", set_once(), 1);
    EXPECT("set_once 2nd", set_once(), 0);
    EXPECT("set_once 3rd", set_once(), 0);

    /* inner_scope */
    printf("=== inner_scope\n");
    EXPECT("inner_scope(5)",  inner_scope(5),  5);
    EXPECT("inner_scope(0)",  inner_scope(0), -1);
    EXPECT("inner_scope(7)",  inner_scope(7),  7);

    /* two_statics */
    printf("=== two_statics\n");
    two_statics(&a, &b);
    EXPECT("two_statics a[0]", a, 10);
    EXPECT("two_statics b[0]", b, 20);
    two_statics(&a, &b);
    EXPECT("two_statics a[1]", a, 11);
    EXPECT("two_statics b[1]", b, 21);

    /* static array */
    printf("=== static array\n");
    EXPECT("acc[0] first",  sum_via_static_array(0), 1);
    EXPECT("acc[0] second", sum_via_static_array(0), 2);
    EXPECT("acc[3] first",  sum_via_static_array(3), 4);
    EXPECT("acc[3] second", sum_via_static_array(3), 8);

    /* memoised fibonacci */
    printf("=== fib_memo\n");
    EXPECT("fib(0)",  fib_memo(0),  0);
    EXPECT("fib(1)",  fib_memo(1),  1);
    EXPECT("fib(5)",  fib_memo(5),  5);
    EXPECT("fib(10)", fib_memo(10), 55);

    if (fails)
        fprintf(stderr, "%d test(s) FAILED\n", fails);
    else
        printf("all local-static tests passed\n");

    return fails ? 1 : 0;
}
