/*
 * test-readline-init.c - Simulate readline's initialisation sequence.
 *
 * readline does more than just termcap + tcsetattr.  This test drives the
 * additional pieces that test-termcap.c did NOT exercise:
 *
 *   1. malloc/realloc/free with the sizes readline uses for its state
 *   2. signal() for SIGINT, SIGTERM, SIGWINCH, SIGALRM
 *   3. sigsetjmp / siglongjmp (readline's interrupt recovery)
 *   4. setenv / getenv (readline reads HOME, INPUTRC, TERM, COLUMNS, LINES)
 *   5. poll() on stdin fd
 *   6. strtol for numeric env var parsing
 *   7. ioctl FIONREAD on a tty fd
 *
 * Compile: pcc -o test-readline-init test-readline-init.c
 * Run:     ./test-readline-init
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <errno.h>

static int fails = 0;
static int sigwinch_count = 0;
static int sigint_count = 0;

#define PASS(label) printf("PASS %s\n", (label))
#define FAIL(label, ...) do { \
    fprintf(stderr, "FAIL " label ": " __VA_ARGS__); \
    fprintf(stderr, "\n"); \
    fails++; \
} while(0)

/* --- 1. malloc/realloc patterns ----------------------------------------- */

static void
test_malloc(void)
{
    /* readline allocates its main state block up-front */
    char *p;
    char *p2;
    int i;

    printf("=== malloc / realloc / free\n");

    /* small alloc */
    p = malloc(64);
    if(p == NULL){ FAIL("malloc 64", "returned NULL"); return; }
    memset(p, 0xaa, 64);
    free(p);
    PASS("malloc+free 64");

    /* readline's rl_line_buffer: starts 256, grows to 512 via realloc */
    p = malloc(256);
    if(p == NULL){ FAIL("malloc 256", "returned NULL"); return; }
    memset(p, 0, 256);
    strcpy(p, "hello world");
    p2 = realloc(p, 512);
    if(p2 == NULL){ FAIL("realloc 256->512", "returned NULL"); free(p); return; }
    p = p2;
    if(strcmp(p, "hello world") != 0){ FAIL("realloc content", "content lost"); free(p); return; }
    PASS("realloc 256->512 content preserved");
    free(p);

    /* many small allocations (history list) */
    char *ptrs[200];
    for(i = 0; i < 200; i++){
        ptrs[i] = malloc(32 + i);
        if(ptrs[i] == NULL){ FAIL("malloc loop", "NULL at %d", i); break; }
        memset(ptrs[i], i & 0xff, 32 + i);
    }
    for(i = 0; i < 200; i++)
        if(ptrs[i]) free(ptrs[i]);
    PASS("200x malloc+free");

    /* realloc(NULL, n) must behave like malloc(n) */
    p = realloc(NULL, 128);
    if(p == NULL){ FAIL("realloc(NULL,128)", "returned NULL"); return; }
    memset(p, 0x55, 128);
    free(p);
    PASS("realloc(NULL,128)");
}

/* --- 2. signal handlers -------------------------------------------------- */

static void
handle_sigwinch(int sig)
{
    (void)sig;
    sigwinch_count++;
}

static void
handle_sigint(int sig)
{
    (void)sig;
    sigint_count++;
}

static void
test_signals(void)
{
    printf("=== signal handlers\n");

    if(signal(SIGWINCH, handle_sigwinch) == SIG_ERR)
        FAIL("signal SIGWINCH", "SIG_ERR errno=%d", errno);
    else
        PASS("signal SIGWINCH");

    if(signal(SIGINT, handle_sigint) == SIG_ERR)
        FAIL("signal SIGINT", "SIG_ERR errno=%d", errno);
    else
        PASS("signal SIGINT");

    if(signal(SIGTERM, SIG_DFL) == SIG_ERR)
        FAIL("signal SIGTERM SIG_DFL", "SIG_ERR");
    else
        PASS("signal SIGTERM SIG_DFL");

    if(signal(SIGALRM, SIG_IGN) == SIG_ERR)
        FAIL("signal SIGALRM SIG_IGN", "SIG_ERR");
    else
        PASS("signal SIGALRM SIG_IGN");

    /* restore */
    signal(SIGWINCH, SIG_DFL);
    signal(SIGINT,   SIG_DFL);
    signal(SIGALRM,  SIG_DFL);
}

/* --- 3. sigsetjmp / siglongjmp ------------------------------------------ */

static sigjmp_buf jmpbuf;
static int jumped = 0;

static void
longjmp_handler(int sig)
{
    (void)sig;
    siglongjmp(jmpbuf, 1);
}

static void
test_sigsetjmp(void)
{
    printf("=== sigsetjmp / siglongjmp\n");

    jumped = 0;
    signal(SIGUSR1, longjmp_handler);

    if(sigsetjmp(jmpbuf, 1) == 0){
        /* first call */
        raise(SIGUSR1);
        /* should not reach here */
        FAIL("sigsetjmp raise", "raise returned without longjmp");
    } else {
        jumped = 1;
    }

    signal(SIGUSR1, SIG_DFL);

    if(jumped)
        PASS("sigsetjmp+siglongjmp via raise");
    else
        FAIL("sigsetjmp", "never jumped");

    /* basic setjmp/longjmp without signals */
    jmp_buf jb;
    int r = setjmp(jb);
    if(r == 0){
        longjmp(jb, 42);
        FAIL("setjmp", "longjmp didn't work");
    } else if(r == 42){
        PASS("setjmp/longjmp");
    } else {
        FAIL("setjmp/longjmp", "got %d want 42", r);
    }
}

/* --- 4. setenv / getenv -------------------------------------------------- */

static void
test_env(void)
{
    char *v;

    printf("=== setenv / getenv\n");

    if(setenv("_RLTEST_KEY", "hello", 1) != 0)
        FAIL("setenv", "returned non-zero errno=%d", errno);
    else {
        v = getenv("_RLTEST_KEY");
        if(v == NULL || strcmp(v, "hello") != 0)
            FAIL("getenv after setenv", "got '%s'", v ? v : "(null)");
        else
            PASS("setenv+getenv");
    }

    /* overwrite */
    setenv("_RLTEST_KEY", "world", 1);
    v = getenv("_RLTEST_KEY");
    if(v && strcmp(v, "world") == 0)
        PASS("setenv overwrite");
    else
        FAIL("setenv overwrite", "got '%s'", v ? v : "(null)");

    /* COLUMNS / LINES as integers */
    setenv("COLUMNS", "132", 1);
    v = getenv("COLUMNS");
    if(v){
        long n = strtol(v, NULL, 10);
        if(n == 132) PASS("COLUMNS strtol"); else FAIL("COLUMNS strtol", "got %ld", n);
    }

    unsetenv("_RLTEST_KEY");
    if(getenv("_RLTEST_KEY") != NULL)
        FAIL("unsetenv", "variable still present");
    else
        PASS("unsetenv");
}

/* --- 5. poll() on stdin -------------------------------------------------- */

static void
test_poll(void)
{
    struct pollfd pfd;

    printf("=== poll(stdin, 0 timeout)\n");

    pfd.fd = 0;  /* stdin */
    pfd.events = POLLIN;
    pfd.revents = 0;

    int r = poll(&pfd, 1, 0);  /* immediate return */
    /* r >= 0 is success; r < 0 is failure */
    if(r < 0)
        FAIL("poll stdin", "returned %d errno=%d", r, errno);
    else
        PASS("poll(stdin, 0 timeout)");
}

/* --- 6. FIONREAD --------------------------------------------------------- */

static void
test_fionread(void)
{
    long n = -1;

    printf("=== FIONREAD on stdin\n");

    if(ioctl(0, FIONREAD, &n) < 0){
        printf("SKIP FIONREAD (ioctl failed errno=%d)\n", errno);
    } else {
        printf("PASS FIONREAD: %ld bytes available\n", n);
    }
}

/* --- main --------------------------------------------------------------- */

int
main(void)
{
    test_malloc();
    test_signals();
    test_sigsetjmp();
    test_env();
    test_poll();
    test_fionread();

    if(fails)
        fprintf(stderr, "%d test(s) FAILED\n", fails);
    else
        printf("all readline-init tests passed\n");

    return fails ? 1 : 0;
}
