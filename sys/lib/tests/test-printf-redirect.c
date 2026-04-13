/*
 * test-printf-redirect.c - Test printf with stdout redirected to a file
 *                          (fully buffered, not line-buffered).
 *
 * Configure scripts redirect stdout to config.log.  This changes stdout
 * from line-buffered to fully-buffered (_IOFBF), which exercises a
 * different code path in __stdio_write / __overflow.
 *
 * Run:
 *   pcc -o test-printf-redirect test-printf-redirect.c
 *   ./test-printf-redirect > /tmp/pr-out.txt && echo OK && cat /tmp/pr-out.txt
 *
 * If it crashes when stdout is redirected but not when writing to a
 * terminal, the bug is in the fully-buffered write path.
 */
#include <stdio.h>
#include <string.h>

int
main(void)
{
    int i;

    /* printf with no format args */
    printf("no-args\n");

    /* printf with %s */
    printf("%s\n", "string-arg");

    /* printf with %d */
    printf("%d\n", 42);

    /* printf with %lld */
    printf("%lld\n", 9000000000LL);

    /* the exact pattern sbase printf uses for integers */
    printf("%*.*lld\n", 0, -1, 99LL);
    printf("%*.*lld\n", 8,  3, 42LL);

    /* the pattern for strings */
    printf("%*.*s\n", 8, 3, "hello");

    /* fill buffer past BUFSIZ with no newlines, then flush */
    for (i = 0; i < 1100; i++)
        putchar('x');
    putchar('\n');

    /* multiple conversions in one call */
    printf("%d %s %lld %f\n", 1, "two", 3LL, 4.0);

    /* fprintf to stderr (should always be unbuffered) */
    fprintf(stderr, "stderr ok\n");

    fflush(stdout);
    return 0;
}
