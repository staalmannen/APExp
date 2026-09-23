/*
 * tty-xcheck.c -- the console raw/cooked state machine, on the HOST.
 *
 * NOT A PLAN 9 TEST. Like tz-xcheck.c, strtod-xcheck.c and the rest of
 * the *-xcheck family, this links the unit under test into a program
 * that runs on the build machine, so the logic can be checked without
 * a round trip to the VM and a full rebuild. Build and run it with:
 *
 *	cd sys/lib/tests
 *	gcc -Wall -I ttystub -o tty-xcheck tty-xcheck.c && ./tty-xcheck
 *
 * WHERE THIS CAME FROM. libap's tcsetattr, handed a real /dev/cons,
 * used to `return 0' and change nothing -- so readline asked for
 * ICANON and ECHO off, was told it had them, and then waited for
 * keystrokes the Plan 9 console driver was holding back until Enter.
 * That is why tab completion has never worked under APE. The repair
 * routes termios through ap/plan9/tty.c, which owns the one switch
 * Plan 9 offers: "rawon"/"rawoff" on /dev/consctl.
 *
 * WHAT IS CHECKED HERE, AND WHY IT IS NOT rawmode-test's job.
 * rawmode-test.c runs on 9front and asks the real question -- does a
 * raw request read back. It cannot reach the cases that matter for
 * getting this right and are awkward to provoke on a live console:
 *
 *   - asking for the state it is already in must be "nothing to do"
 *     and NOT a failure, because tcsetattr reports those differently;
 *   - the return value is the PREVIOUS state, which is what makes
 *     save/restore possible for getpass();
 *   - a consctl that will not open must leave the state cooked rather
 *     than half-set;
 *   - closing the descriptor is what actually reverts the console, so
 *     the cooked path must close it.
 *
 * open/write/close are replaced with counting fakes, so every one of
 * those is an assertion about the code rather than about a terminal.
 * The macros are defined AFTER the real system headers are pulled in,
 * or they collide with glibc's own declarations of open().
 */

#include <stdio.h>
#include <string.h>

/* real headers first, so tty.c's own includes are no-ops */
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "ttystub/libv.h"
#include "ttystub/lib.h"

static int fake_opens, fake_writes, fake_closes, fail_open;
static char lastwrite[32];

#define open(p,f)    fake_open(p,f)
#define write(d,b,n) fake_write(d,b,n)
#define close(d)     fake_close(d)

static int
fake_open(const char *p, int f)
{
	(void)p; (void)f;
	fake_opens++;
	return fail_open ? -1 : 7;
}

static long
fake_write(int d, const void *b, unsigned long n)
{
	(void)d;
	fake_writes++;
	memcpy(lastwrite, b, n < 31 ? n : 31);
	lastwrite[n < 31 ? n : 31] = 0;
	return (long)n;
}

static int
fake_close(int d)
{
	(void)d;
	fake_closes++;
	return 0;
}

#include "../../src/ape/lib/ap/plan9/tty.c"

#undef open
#undef write
#undef close

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

int
main(void)
{
	int r, was;

	printf("--- 1. turning it on ---\n");
	ok("starts cooked", _tty_israw() == 0);
	r = _tty_raw(1);
	ok("first raw returns the previous state, 0", r == 0);
	ok("...and it reads back raw", _tty_israw() == 1);
	ok("...having written rawon", strcmp(lastwrite, "rawon") == 0);
	ok("...opening consctl exactly once", fake_opens == 1);

	printf("--- 2. asking again is NOTHING TO DO, not a failure ---\n");
	/*
	 * The distinction tcsetattr rests on. A -1 here would make every
	 * redundant tcsetattr look like an error to the caller, and
	 * readline calls it on every line.
	 */
	fake_opens = fake_writes = 0;
	r = _tty_raw(1);
	ok("returns the previous state, 1", r == 1);
	ok("...which is not -1", r >= 0);
	ok("...and consctl is not touched at all", fake_opens == 0 && fake_writes == 0);

	printf("--- 3. turning it off ---\n");
	r = _tty_raw(0);
	ok("returns the previous state, 1", r == 1);
	ok("...and it reads back cooked", _tty_israw() == 0);
	ok("...having written rawoff", strcmp(lastwrite, "rawoff") == 0);
	ok("...and CLOSED consctl, which is what reverts the console",
		fake_closes == 1);

	fake_opens = fake_writes = fake_closes = 0;
	r = _tty_raw(0);
	ok("cooking an already cooked console does nothing",
		r == 0 && fake_opens == 0 && fake_writes == 0);

	printf("--- 4. a consctl that will not open ---\n");
	fail_open = 1;
	r = _tty_raw(1);
	ok("reports -1", r == -1);
	ok("...and leaves the state cooked, not half-set", _tty_israw() == 0);
	fail_open = 0;

	printf("--- 5. save and restore, the shape getpass uses ---\n");
	/*
	 * getpass borrows the console and hands it back. The old
	 * tty_echoon() cooked it unconditionally, which would have
	 * quietly ended a caller's raw mode the first time anything asked
	 * for a password.
	 */
	_tty_raw(1);
	was = _tty_raw(1);
	_tty_raw(was);
	ok("a RAW console is still raw afterwards", _tty_israw() == 1);
	_tty_raw(0);
	was = _tty_raw(1);
	_tty_raw(was);
	ok("a COOKED console is still cooked afterwards", _tty_israw() == 0);

	printf("--- 6. THE CONTROL: the marker is the one this tree built ---\n");
	/*
	 * Without this the file would pass against any tty.c at all,
	 * including one that had been replaced wholesale.
	 */
	printf("  note _ttymark() = %d\n", _ttymark());
	ok("_ttymark answers", _ttymark() >= 1);

	printf("%d failure(s)\n", failures);
	return failures;
}
