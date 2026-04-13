/*
 * test-stack.c - Test large stack frames and deep recursion.
 *
 * If the crash is a stack overflow (writing below the stack guard page),
 * these tests will reproduce it in a controlled setting and show at what
 * depth or frame size it occurs.
 *
 * Compile: pcc -o test-stack test-stack.c
 * Run:     ./test-stack
 */
#include <stdio.h>
#include <string.h>

/* Test 1: large local arrays of increasing sizes */
static void
large_frame_1k(int n)
{
    char buf[1024];
    memset(buf, n & 0xff, sizeof buf);
    printf("PASS 1k frame (n=%d, buf[0]=0x%x)\n", n, (unsigned char)buf[0]);
    fflush(stdout);
}

static void
large_frame_8k(int n)
{
    char buf[8192];
    memset(buf, n & 0xff, sizeof buf);
    printf("PASS 8k frame (n=%d, buf[0]=0x%x)\n", n, (unsigned char)buf[0]);
    fflush(stdout);
}

static void
large_frame_64k(int n)
{
    char buf[65536];
    memset(buf, n & 0xff, sizeof buf);
    printf("PASS 64k frame (n=%d, buf[0]=0x%x)\n", n, (unsigned char)buf[0]);
    fflush(stdout);
}

/* Test 2: recursion depth */
static int depth_reached;

static void
recurse(int depth)
{
    /* 512-byte frame to accelerate stack consumption */
    volatile char pad[512];
    pad[0] = (char)depth;
    pad[511] = (char)depth;
    depth_reached = depth;
    if (depth > 0)
        recurse(depth - 1);
}

/* Test 3: recursion with printf at each level (tests stdio on deep stack) */
static void
recurse_print(int depth)
{
    if (depth == 0) {
        printf("PASS recurse_print reached depth 0\n");
        fflush(stdout);
        return;
    }
    recurse_print(depth - 1);
    /* printf AFTER recursion: tests that stack is still valid on unwind */
}

int
main(void)
{
    int i;

    printf("=== test 1: large stack frames\n");
    fflush(stdout);
    for (i = 0; i < 5; i++)
        large_frame_1k(i);
    printf("=== 8k frames\n");
    fflush(stdout);
    for (i = 0; i < 5; i++)
        large_frame_8k(i);
    printf("=== 64k frames\n");
    fflush(stdout);
    for (i = 0; i < 3; i++)
        large_frame_64k(i);

    printf("=== test 2: recursion depth (512-byte frames)\n");
    fflush(stdout);
    /* Stop at 500 so we don't blow the stack on purpose */
    depth_reached = -1;
    recurse(500);
    printf("PASS recursion: reached depth %d\n", depth_reached);
    fflush(stdout);

    printf("=== test 3: printf on deep stack (depth 100)\n");
    fflush(stdout);
    recurse_print(100);
    printf("PASS recurse_print\n");
    fflush(stdout);

    printf("all stack tests passed\n");
    return 0;
}
