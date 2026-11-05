/* ucontext-test.c -- getcontext/makecontext/swapcontext/setcontext
 *
 *	pcc -o ucontext-test ucontext-test.c && ./ucontext-test
 *	gcc -o ucontext-test ucontext-test.c && ./ucontext-test   # the control
 *
 * ***THIS ONE HAS A REAL REFERENCE IMPLEMENTATION, WHICH IS RARE HERE.***
 * glibc has ucontext, so every assertion below can be checked against a
 * working implementation before the VM ever sees it -- the tree's own
 * rule about checking a new test on gcc first, for once with the unit
 * under test present on both sides rather than only the harness.  **A
 * failure on Plan 9 that also fails on glibc is this file's bug.**
 *
 * WHERE IT CAME FROM.  php's `Zend/zend_fibers.c' is unconditional --
 * `Fiber' is a language class -- and needs either boost.context's GAS
 * assembly or `<ucontext.h>'.  APExp had neither, so the second was
 * written: `lib/ap/arch/amd64/mcontext.s' (three register-only
 * primitives) and `ucontext.c' (everything structural).
 * `docs/notes/php.md' has the survey it came out of.
 *
 * WHAT EACH SECTION IS FOR, because several of them look alike and are
 * not:
 *
 *   0  a context resumed by `setcontext' RETURNS 0 from its
 *      `getcontext'.  The assembly zeroes AX before jumping for this
 *      reason alone, exactly as longjmp does -- *without it a resumed
 *      getcontext returns whatever was in AX and its caller believes
 *      the number*.
 *   1  a function runs on the new stack AND the stack is really the one
 *      that was handed over -- checked by taking the address of a local
 *      and asking whether it lies inside the allocation.  A context
 *      switch that quietly ran on the caller's stack would pass every
 *      other section here.
 *   2  `uc_link' is honoured when the function RETURNS.
 *   3  ***THE ARGUMENTS, AND THIS IS THE ONE THAT CHECKS THE FRAME
 *      LAYOUT.***  It passes the maximum this port accepts, because the
 *      cell holding the ucontext sits immediately above the argument
 *      slots: an off-by-one puts the last argument on top of it, and
 *      then `_ctxfinish' reads a bad pointer.  **The dangerous outcome
 *      is silence** -- a null-ish `uc_link' means `exit(0)', which from
 *      the shell is indistinguishable from a clean finish -- so the
 *      section prints a marker before the call and the count after it.
 *   4  ping-pong, which is what a fiber actually does: many switches
 *      through one pair of contexts, each resuming where it left off.
 *   5  a context's own locals survive being switched away from and back.
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

#ifndef __linux__
extern int _ucmark(void);
#endif

#define STKSZ (256*1024)

static int fails;

static void
eq(const char *what, long got, long want)
{
	if(got == want)
		printf("  PASS %-46s %ld\n", what, got);
	else {
		printf("  FAIL %-46s got %ld want %ld\n", what, got, want);
		fails++;
	}
}

/* ---- section 0 ---- */
static int s0_count;

/* ---- section 1 ---- */
static ucontext_t s1_main, s1_ctx;
static char *s1_lo, *s1_hi;
static int s1_ran, s1_onstack;

static void
s1_fn(void)
{
	char probe;

	s1_ran++;
	s1_onstack = (&probe >= s1_lo && &probe < s1_hi);
	swapcontext(&s1_ctx, &s1_main);
}

/* ---- section 2 ---- */
static ucontext_t s2_main, s2_ctx;
static int s2_ran;

static void
s2_fn(void)
{
	s2_ran++;
	/* returns: uc_link must take us back */
}

/* ---- section 3 ---- */
static ucontext_t s3_main, s3_ctx;
static int s3_got[8], s3_ran;

static void
s3_fn(int a, int b, int c, int d, int e, int f, int g, int h)
{
	s3_got[0] = a; s3_got[1] = b; s3_got[2] = c; s3_got[3] = d;
	s3_got[4] = e; s3_got[5] = f; s3_got[6] = g; s3_got[7] = h;
	s3_ran++;
}

/* ---- section 4 ---- */
static ucontext_t s4_main, s4_ctx;
static int s4_ticks;

static void
s4_fn(void)
{
	int i;

	for(i = 0; i < 5; i++){
		s4_ticks++;
		swapcontext(&s4_ctx, &s4_main);
	}
}

/* ---- section 5 ---- */
static ucontext_t s5_main, s5_ctx;
static int s5_seen;

/*
 * ***`long long', NOT `long', AND THAT IS WHAT THE FIRST VM RUN
 * FOUND.***  This said `volatile long a = 0x1111111111111111L;', which
 * passes on glibc and cannot on this machine: **kencc's `long` is four
 * bytes**, so `a' held `0x11111111' and the comparison against the full
 * 64-bit constant was false.  Section 5 reported `got 0 want 1' for a
 * context switch that was working perfectly.
 *
 * *The gcc check could not have caught it* -- this is the one class of
 * test bug that the reference implementation is blind to, because the
 * difference IS the reference's width.  The tree's own first invariant,
 * arriving in the file written to check something else.
 */
static void
s5_fn(void)
{
	volatile long long a = 0x1111111111111111LL;
	volatile long long b = 0x2222222222222222LL;

	swapcontext(&s5_ctx, &s5_main);
	if(a == 0x1111111111111111LL && b == 0x2222222222222222LL)
		s5_seen = 1;
	swapcontext(&s5_ctx, &s5_main);
}

static char *
newstack(ucontext_t *uc, ucontext_t *link, char **lo, char **hi)
{
	char *s = malloc(STKSZ);

	if(s == 0){
		printf("  FAIL could not allocate a stack\n");
		fails++;
		exit(fails);
	}
	memset(s, 0, STKSZ);
	getcontext(uc);
	uc->uc_stack.ss_sp = s;
	uc->uc_stack.ss_size = STKSZ;
	uc->uc_stack.ss_flags = 0;
	uc->uc_link = link;
	if(lo) *lo = s;
	if(hi) *hi = s + STKSZ;
	return s;
}

int
main(void)
{
	ucontext_t c0;
	int i;

	/* a fault, a kill and a clean finish all give the prompt back */
	setvbuf(stdout, (char*)0, _IONBF, 0);
	printf("ucontext-test: starting\n");
#ifndef __linux__
	printf("ucontext-test: _ucmark = %d\n", _ucmark());
#endif

	/* ---- 0: getcontext/setcontext round trip ---- */
	printf("\nSection 0: a resumed getcontext returns 0\n");
	/*
	 * The PASS line below prints TWICE and that is the point: the
	 * second is the resumed path re-entering at getcontext's return.
	 */
	s0_count = 0;
	i = getcontext(&c0);
	eq("getcontext returned 0", i, 0);
	s0_count++;
	if(s0_count == 1)
		setcontext(&c0);	/* re-enters getcontext's return */
	eq("setcontext came back round", s0_count, 2);

	/* ---- 1: a function on its own stack ---- */
	printf("\nSection 1: the function runs, on the stack it was given\n");
	newstack(&s1_ctx, &s1_main, &s1_lo, &s1_hi);
	makecontext(&s1_ctx, s1_fn, 0);
	swapcontext(&s1_main, &s1_ctx);
	eq("the function ran", s1_ran, 1);
	eq("its locals are inside the given stack", s1_onstack, 1);

	/* ---- 2: uc_link ---- */
	printf("\nSection 2: returning follows uc_link\n");
	newstack(&s2_ctx, &s2_main, (char**)0, (char**)0);
	makecontext(&s2_ctx, s2_fn, 0);
	swapcontext(&s2_main, &s2_ctx);
	eq("the function ran", s2_ran, 1);
	/*
	 * There is deliberately no `eq("uc_link honoured", 1, 1)' here.
	 * *A check that cannot fail is not a check*: if uc_link were
	 * ignored, `_ctxfinish' would call `exit(0)' and this line would
	 * never run, so REACHING section 3 is the result -- the same
	 * shape as the marker printed there, and the reason both are
	 * written as prose rather than as a passing assertion.
	 */

	/* ---- 3: arguments, at the cap ---- */
	printf("\nSection 3: eight arguments, the most this port passes\n");
	printf("  (if nothing follows this line, the ucontext cell above\n");
	printf("   the argument slots was overwritten and _ctxfinish\n");
	printf("   exited: see ucontext.c's frame picture)\n");
	newstack(&s3_ctx, &s3_main, (char**)0, (char**)0);
	makecontext(&s3_ctx, (void(*)(void))s3_fn, 8,
	            11, 22, 33, 44, 55, 66, 77, 88);
	swapcontext(&s3_main, &s3_ctx);
	eq("the function ran", s3_ran, 1);
	for(i = 0; i < 8; i++){
		char nm[48];
		sprintf(nm, "argument %d", i);
		eq(nm, s3_got[i], 11*(i+1));
	}

	/* ---- 4: ping-pong ---- */
	printf("\nSection 4: five switches through one pair\n");
	newstack(&s4_ctx, &s4_main, (char**)0, (char**)0);
	makecontext(&s4_ctx, s4_fn, 0);
	for(i = 0; i < 5; i++)
		swapcontext(&s4_main, &s4_ctx);
	eq("ticks", s4_ticks, 5);

	/* ---- 5: locals survive a switch away and back ---- */
	printf("\nSection 5: a context's locals survive being left\n");
	newstack(&s5_ctx, &s5_main, (char**)0, (char**)0);
	makecontext(&s5_ctx, s5_fn, 0);
	swapcontext(&s5_main, &s5_ctx);
	swapcontext(&s5_main, &s5_ctx);
	eq("both locals intact after the round trip", s5_seen, 1);

	printf("\nucontext-test: %d failures\n", fails);
	return fails;
}
