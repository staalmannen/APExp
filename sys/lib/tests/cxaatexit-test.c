/*
 * cxaatexit-test.c -- the Itanium C++ ABI finalization pair.
 *
 * FROM: the first link of `cmd/edg', which answered
 * `_Z12__call_dtorsv: undefined: __cxa_finalize' -- EDG declares the
 * pair in `include_c++/cxxabi.h' and defines neither, leaving them to
 * the platform's C++ runtime, of which there is none here.
 * `sys/src/ape/lib/edg/cxa_atexit.c' is the answer and this measures
 * it.
 *
 * IT IS A HOST PROGRAM AND A PLAN 9 ONE BOTH, and the same file
 * serves because the unit is a pure function of its own calls --
 * no syscalls, no libap behaviour, nothing platform-shaped.  *That
 * is the `tz-xcheck' pattern at its cheapest*: link the unit under
 * test into a program beside a reference and ask it questions.
 *
 *   gcc -o cxaatexit-test cxaatexit-test.c \
 *       ../../src/ape/lib/edg/cxa_atexit.c      # host
 *   pcc -o cxaatexit-test cxaatexit-test.c \
 *       ../../src/ape/lib/edg/cxa_atexit.c      # 9front
 *   ./cxaatexit-test
 *
 * SECTIONS 3 AND 4 ARE THE REASON THIS FILE EXISTS.  A plain
 * descending `for' loop over the list passes sections 1 and 2 and
 * fails both of those, and they are the two halves of the ABI that
 * are easy to approximate and observable when you do not:
 *
 *   3  a destructor that REGISTERS ANOTHER must have the new one run
 *      (the list is re-scanned, not walked once);
 *   4  a destructor that calls `__cxa_finalize' AGAIN must not see
 *      itself (the entry is removed BEFORE it is called).
 *
 * Section 4 is the one that would otherwise recurse for ever rather
 * than print a wrong number, so it is bounded: it refuses to call
 * through more than a fixed depth and reports the depth it reached.
 *
 * SECTION 5 IS A CONTROL OF THE INSTRUMENT rather than of the unit:
 * it asks whether the order check in section 2 can report anything at
 * all, by comparing the recorded sequence against a deliberately
 * wrong one.  *An order test whose expected string is what any order
 * produces is not a test*, which is the trap `random-xcheck`'s
 * section 0 was written for.
 */

#include <stdio.h>
#include <string.h>

extern int __cxa_atexit(void (*)(void *), void *, void *);
extern void __cxa_finalize(void *);
extern void *__dso_handle;

static char log[256];
static int logn;

static void
note(const char *s)
{
	if(logn + (int)strlen(s) + 1 < (int)sizeof log) {
		strcpy(log + logn, s);
		logn += strlen(s);
	}
}

static void a(void *p) { note((char *)p); }

/* section 3: registers another destructor while being called */
static void late(void *p) { note((char *)p); }
static void
spawner(void *p)
{
	note((char *)p);
	__cxa_atexit(late, (void *)"L", __dso_handle);
}

/* section 4: calls finalize again from inside a destructor */
static int depth, maxdepth;
static void
reenter(void *p)
{
	note((char *)p);
	if(++depth < 10)
		__cxa_finalize(0);
	if(depth > maxdepth)
		maxdepth = depth;
	depth--;
}

static int
check(const char *nm, const char *got, const char *want)
{
	if(strcmp(got, want) == 0) {
		printf("PASS %s -> \"%s\"\n", nm, got);
		return 0;
	}
	printf("FAIL %s -> \"%s\", want \"%s\"\n", nm, got, want);
	return 1;
}

int
main(void)
{
	int fail = 0;
	void *other;

	printf("cxaatexit-test\n");

	/* Section 0: a PROBE.  The handle must be usable and unique. */
	printf("  __dso_handle   %s\n", __dso_handle ? "non-null" : "NULL");
	if(__dso_handle == 0) {
		printf("FAIL 0a __dso_handle is null\n");
		fail++;
	} else
		printf("PASS 0a __dso_handle is non-null\n");

	/* Section 1: registration succeeds and a null function is refused. */
	if(__cxa_atexit(a, (void *)"x", __dso_handle) != 0) {
		printf("FAIL 1a registration failed\n");
		fail++;
	} else
		printf("PASS 1a registration returns 0\n");
	logn = 0; log[0] = 0;
	__cxa_finalize(0);
	fail += check("1b it runs", log, "x");

	if(__cxa_atexit(0, 0, __dso_handle) == 0) {
		printf("FAIL 1c a null function was accepted\n");
		fail++;
	} else
		printf("PASS 1c a null function is refused\n");

	/* Section 2: REVERSE registration order. */
	logn = 0; log[0] = 0;
	__cxa_atexit(a, (void *)"1", __dso_handle);
	__cxa_atexit(a, (void *)"2", __dso_handle);
	__cxa_atexit(a, (void *)"3", __dso_handle);
	__cxa_finalize(0);
	fail += check("2a reverse order", log, "321");

	/* Section 3: a destructor that registers another. */
	logn = 0; log[0] = 0;
	__cxa_atexit(a, (void *)"A", __dso_handle);
	__cxa_atexit(spawner, (void *)"S", __dso_handle);
	__cxa_finalize(0);
	/* S runs first (reverse order) and registers L; L is now the
	 * newest, so it runs next; then A. */
	fail += check("3a a destructor's own registration runs", log, "SLA");

	/* Section 4: re-entry must not run an entry twice. */
	logn = 0; log[0] = 0;
	depth = maxdepth = 0;
	__cxa_atexit(reenter, (void *)"R", __dso_handle);
	__cxa_atexit(a, (void *)"b", __dso_handle);
	__cxa_finalize(0);
	fail += check("4a no entry runs twice", log, "bR");
	if(maxdepth > 1) {
		printf("FAIL 4b re-entered %d deep; the entry was not"
		    " removed before the call\n", maxdepth);
		fail++;
	} else
		printf("PASS 4b re-entry saw an empty list\n");

	/* Section 5: the HANDLE is compared, not ignored. */
	other = (void *)&fail;
	logn = 0; log[0] = 0;
	__cxa_atexit(a, (void *)"m", __dso_handle);
	__cxa_atexit(a, (void *)"o", other);
	__cxa_finalize(other);
	fail += check("5a only the matching handle ran", log, "o");
	__cxa_finalize(0);
	fail += check("5b the other survived until d==0", log, "om");

	/*
	 * Section 6: CONTROL OF THE INSTRUMENT.  Section 2's whole
	 * content is that "321" is not "123", so ask whether the
	 * comparison can tell them apart at all.  It is done with a
	 * SILENT compare rather than by calling `check' -- a control
	 * that prints the word FAIL on a healthy run is a control
	 * nobody can grep past.
	 */
	if(strcmp("321", "123") == 0) {
		printf("FAIL 6a the order check cannot report a"
		    " difference\n");
		fail++;
	} else
		printf("PASS 6a the order check can report a difference\n");

	printf("%d failures\n", fail);
	return fail;
}
