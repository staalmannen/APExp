/*
 * rawmode-test.c -- does tcsetattr actually change anything?
 *
 * RUN IT ON A CONSOLE: ./rawmode-test, from a window, with stdin a
 * terminal. Redirected, sections 3 and 4 cannot run and say so.
 *
 * WHERE THIS CAME FROM. bash's tab completion has never worked under
 * APE, and the reason was in libap rather than in bash. termios's
 * tcsetattr, given a real /dev/cons, did this:
 *
 *	if(!isatty(fd)) { errno = ENOTTY; return -1; }
 *	else return 0;                  <- and nothing else
 *
 * It reported success and changed nothing. tcgetattr was the matching
 * half: it returned a hardcoded c_lflag of ISIG|ICANON|ECHO|ECHOE|ECHOK
 * whatever the console was actually doing. So readline cleared ICANON
 * and ECHO, was told it had them, and then waited for keystrokes that
 * the Plan 9 console driver was holding back until Enter. Tab arrived
 * as part of a finished line, which is far too late to complete
 * anything.
 *
 * That is this tree's single most common bug shape, recorded in
 * CLAUDE.md: *a stub that answers "failure" is not the same as one
 * that answers "nothing to do"*, and neither is the same as one that
 * answers "done". Plan 9 has the switch -- /dev/consctl takes "rawon"
 * -- and libap was already using it in plan9/tty.c for getpass().
 *
 * WHAT SECTION 3 ASKS, AND WHY IT IS THE WHOLE POINT. Not "did
 * tcsetattr return 0" -- the broken version returned 0 too, which is
 * exactly how this survived. It sets raw, then reads the state BACK
 * and checks the bits it asked to clear are clear. A platform having
 * only one switch where POSIX has a flag set is no reason for a value
 * not to read back.
 *
 * Section 5 is the end-to-end proof and needs a human, so it only runs
 * when $APEXP_RAWTEST_KEYS is set. Without it the file is still a real
 * test: sections 3 and 4 fail on the old library and pass on the new
 * one, with no keystrokes at all.
 *
 * Correct on glibc, which is where it was checked -- under a pty, so
 * that sections 3 and 4 genuinely ran rather than skipping.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>

/*
 * WHICH libap IS LINKED IN. `pcc -o x x.c' links against the INSTALLED
 * library, so a copy of this file fresh from a pull can measure
 * days-old library code. Declared extern here, so an old libap fails
 * to LINK with an undefined `_ttymark' instead of passing quietly.
 *
 * THE DISCRIMINATOR IS __GNUC__: pcc predefines only __STDC__ and
 * _POSIX_SOURCE, so a guard on __plan9__ would be false everywhere and
 * the marker would never be asked for. socket-server-test.c and
 * execfail-test.c carry the same note.
 */
#ifndef __GNUC__
extern int _ttymark(void);
#define TTYMARK _ttymark()
#else
#define TTYMARK (-1)
#endif

static int failures;
static int haveorig;
static struct termios orig;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static void
lflags(const char *label, const struct termios *t)
{
	printf("  note %s: ICANON=%d ECHO=%d ISIG=%d  (c_lflag=0x%lx)\n",
		label,
		(t->c_lflag & ICANON) != 0,
		(t->c_lflag & ECHO) != 0,
		(t->c_lflag & ISIG) != 0,
		(unsigned long) t->c_lflag);
}

/*
 * Put the console back however this file found it. Called on every
 * exit path: leaving a terminal raw makes the shell that ran the test
 * unusable, and a test that wrecks the machine it measures will not be
 * run twice.
 */
static void
restore(void)
{
	if(haveorig)
		tcsetattr(0, TCSANOW, &orig);
}

static int
done(void)
{
	restore();
	printf("%d failure(s)\n", failures);
	return failures;
}

int
main(void)
{
	struct termios t, back;
	int fds[2], n;
	char c;

	printf("  note libap _ttymark = %d  (-1 means built on the host,"
		" where there is no marker to ask)\n", TTYMARK);

	printf("--- 1. PROBE: what is stdin, and what does it claim ---\n");
	printf("  note isatty(0) = %d\n", isatty(0));
	if(!isatty(0)){
		printf("  note stdin is NOT a terminal, so sections 3 and 4\n");
		printf("  note cannot run. Run this from a window without\n");
		printf("  note redirecting stdin. Section 2 still applies.\n");
	} else {
		if(tcgetattr(0, &orig) < 0){
			printf("  note tcgetattr(0) failed: %s\n", strerror(errno));
		} else {
			haveorig = 1;
			lflags("as found", &orig);
		}
	}

	printf("--- 2. THE CONTROL: a pipe is not a terminal ---\n");
	/*
	 * Without this, "tcsetattr always returns 0" and "tcsetattr works"
	 * look identical from section 3 alone -- and the bug being fixed
	 * here was precisely a function that returned 0 for everything.
	 * A pipe must be refused.
	 */
	if(pipe(fds) < 0){
		printf("  note pipe failed: %s\n", strerror(errno));
		return done() + 1;
	}
	errno = 0;
	n = tcgetattr(fds[0], &t);
	printf("  note tcgetattr(pipe) -> %d, errno %d (%s)\n",
		n, errno, n < 0 ? strerror(errno) : "-");
	ok("tcgetattr on a pipe fails", n < 0);
	ok("...with ENOTTY", n < 0 && errno == ENOTTY);
	memset(&t, 0, sizeof t);
	errno = 0;
	n = tcsetattr(fds[0], TCSANOW, &t);
	printf("  note tcsetattr(pipe) -> %d, errno %d (%s)\n",
		n, errno, n < 0 ? strerror(errno) : "-");
	ok("tcsetattr on a pipe fails", n < 0);
	ok("...with ENOTTY", n < 0 && errno == ENOTTY);
	close(fds[0]);
	close(fds[1]);

	if(!haveorig){
		printf("--- 3,4. SKIPPED: stdin is not a terminal ---\n");
		printf("  note this is a SKIP and not a pass; the question the\n");
		printf("  note file exists to ask was not asked.\n");
		return done();
	}

	printf("--- 3. raw mode has to READ BACK ---\n");
	/*
	 * The request readline makes. Checking the return value alone
	 * would have passed on the broken library, so the return value is
	 * reported and the STATE is what is asserted.
	 */
	t = orig;
	t.c_lflag &= ~(ICANON | ECHO);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	errno = 0;
	n = tcsetattr(0, TCSANOW, &t);
	printf("  note tcsetattr(raw) -> %d, errno %d (%s)\n",
		n, errno, n < 0 ? strerror(errno) : "-");
	ok("tcsetattr accepts the raw request", n == 0);

	if(tcgetattr(0, &back) < 0){
		printf("  note tcgetattr after the change failed: %s\n",
			strerror(errno));
		ok("ICANON reads back clear", 0);
		ok("ECHO reads back clear", 0);
	} else {
		lflags("after asking for raw", &back);
		ok("ICANON reads back clear", (back.c_lflag & ICANON) == 0);
		ok("ECHO reads back clear", (back.c_lflag & ECHO) == 0);
	}

	printf("--- 4. ...and so does putting it back ---\n");
	/*
	 * The other half, and not a formality: a library that answered
	 * "raw" unconditionally would pass section 3 and fail here.
	 */
	errno = 0;
	n = tcsetattr(0, TCSANOW, &orig);
	printf("  note tcsetattr(restore) -> %d, errno %d (%s)\n",
		n, errno, n < 0 ? strerror(errno) : "-");
	ok("tcsetattr accepts the restore", n == 0);
	if(tcgetattr(0, &back) < 0){
		ok("ICANON reads back set", 0);
		ok("ECHO reads back set", 0);
	} else {
		lflags("after restoring", &back);
		ok("ICANON reads back set", (back.c_lflag & ICANON) != 0);
		ok("ECHO reads back set", (back.c_lflag & ECHO) != 0);
	}

	if(getenv("APEXP_RAWTEST_KEYS") == NULL){
		printf("--- 5. SKIPPED: set $APEXP_RAWTEST_KEYS to run it ---\n");
		printf("  note section 5 needs a human to press a key. It is the\n");
		printf("  note end-to-end proof -- a byte arriving BEFORE Enter is\n");
		printf("  note what tab completion needs -- but sections 3 and 4\n");
		printf("  note already separate the fixed library from the old one.\n");
		return done();
	}

	printf("--- 5. a single keystroke, with no Enter ---\n");
	t = orig;
	t.c_lflag &= ~(ICANON | ECHO);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	if(tcsetattr(0, TCSANOW, &t) < 0){
		printf("  note could not set raw: %s\n", strerror(errno));
		ok("a keystroke arrives without Enter", 0);
		return done();
	}
	printf("  Press a single key (NOT Enter): ");
	fflush(stdout);
	n = read(0, &c, 1);
	restore();
	printf("\n  note read(0) -> %d, byte 0x%02x\n", n, n == 1 ? c & 0xff : 0);
	ok("a keystroke arrives without Enter", n == 1 && c != '\n' && c != '\r');
	printf("  note if that byte is 0x0a or 0x0d, the console was still\n");
	printf("  note cooking and it waited for the whole line.\n");

	return done();
}
