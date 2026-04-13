/*
 * test-stdio-buf.c - Test stdout write-buffer management edge cases.
 *
 * Exercises: buffer fill without newline, flush on newline, explicit fflush,
 * writes larger than BUFSIZ, and fprintf after a flush.
 *
 * If stdout's wpos/wend/wbase are corrupted after any of these operations
 * subsequent writes will fault.  The crash address would be in the BSS area
 * near the static buf[] in stdout.c.
 *
 * Compile: pcc -o test-stdio-buf test-stdio-buf.c
 * Run:     ./test-stdio-buf && echo "exit ok"
 */
#include <stdio.h>
#include <string.h>

#define BUFSZ 1024   /* matches APExp BUFSIZ */

int
main(void)
{
    int i;
    char big[BUFSZ * 3];

    /* Test 1: fill nearly all of stdout buffer without a newline, then flush */
    printf("=== test 1: near-full buffer + fflush\n");
    fflush(stdout);
    for (i = 0; i < BUFSZ - 10; i++)
        putchar('A');
    fflush(stdout);
    putchar('\n');
    printf("PASS test 1\n");
    fflush(stdout);

    /* Test 2: fill past BUFSIZ without a newline */
    printf("=== test 2: overfull buffer (no newline mid-write)\n");
    fflush(stdout);
    for (i = 0; i < BUFSZ + 50; i++)
        putchar('B');
    fflush(stdout);
    putchar('\n');
    printf("PASS test 2\n");
    fflush(stdout);

    /* Test 3: newline triggers line-buffer flush */
    printf("=== test 3: newline flush\n");
    fflush(stdout);
    fputs("line-a\n", stdout);
    fputs("line-b\n", stdout);
    printf("PASS test 3\n");
    fflush(stdout);

    /* Test 4: fwrite of block larger than BUFSIZ */
    printf("=== test 4: fwrite > BUFSIZ\n");
    fflush(stdout);
    memset(big, 'C', sizeof big);
    big[sizeof big - 1] = '\n';
    fwrite(big, 1, sizeof big, stdout);
    fflush(stdout);
    printf("PASS test 4\n");
    fflush(stdout);

    /* Test 5: fprintf with %d after buffer ops */
    printf("=== test 5: fprintf after buffer ops\n");
    fflush(stdout);
    fprintf(stdout, "value=%d\n", 12345);
    fprintf(stdout, "lld=%lld\n", -9876543210LL);
    printf("PASS test 5\n");
    fflush(stdout);

    /* Test 6: rapid alternation between short writes and flushes */
    printf("=== test 6: rapid write+flush\n");
    fflush(stdout);
    for (i = 0; i < 20; i++) {
        fprintf(stdout, "%d", i);
        fflush(stdout);
    }
    putchar('\n');
    printf("PASS test 6\n");
    fflush(stdout);

    /* Test 7: fprintf with * width/prec (exact sbase printf call pattern) */
    printf("=== test 7: printf %%*.*lld pattern\n");
    fflush(stdout);
    printf("%*.*lld\n", 10, 4, 42LL);
    printf("%*.*lld\n", 0, -1, -99LL);
    printf("%*.*s\n",   8,  3, "hello");
    printf("PASS test 7\n");
    fflush(stdout);

    printf("all stdio-buf tests passed\n");
    return 0;
}
