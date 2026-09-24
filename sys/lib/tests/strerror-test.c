/*
 * strerror-test -- does strerror() RETURN?
 *
 * WHERE THIS CAME FROM. `tar cf /tmp/t.tar /tmp/h' died with
 *
 *	tar 2459: suicide: sys: trap: fault write addr=0x7ffffeffefc8 pc=0x247ba3
 *
 * and acid's lstk() on the Broken process printed one frame over and
 * over:
 *
 *	strerror(n=0x14)+0x19  .../external/gnulib/strerror.c:52
 *	strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56
 *	strerror(n=0x14)+0x1e  .../external/gnulib/strerror.c:56
 *	...
 *
 * gnulib's strerror.c is written to REPLACE the system strerror while
 * still calling it, and the whole mechanism is one macro in gnulib's
 * GENERATED string.h -- `#define strerror rpl_strerror'. With it, the
 * definition defines rpl_strerror and the `#undef strerror' between the
 * declarator and the body makes the inner call reach the real one.
 * Nothing generates that header in this tree (there is a string.in.h
 * and no string.h), so <string.h> was APE's, the function defined the
 * plain name, and line 52's call was a call to itself.
 *
 * n=0x14 is 20, ENOENT. errno 20 was reached, error(0, errno, ...) was
 * called, and tar exhausted its stack instead of printing a message.
 *
 * IT WAS NEVER TAR'S. strerror.$O was in libgnu.a, which is on the link
 * line of every GNU program here -- tar, sed, awk, grep, m4, gettext,
 * diff, patch, bison. gnulib's error(0, errno, ...) is the standard way
 * all of them report a failed system call, so all of them died on their
 * first one. Fixed by dropping strerror.$O from
 * sys/src/ape/cmd/gnulib/mkfile: libap's strerror is complete, and the
 * archive's own README already said not to add a module libap provides.
 *
 * ------------------------------------------------------------------
 * HOW TO BUILD IT, AND WHY IT IS NOT THE USUAL COMMAND.
 *
 * The bug is in libgnu.a, and a test built the ordinary way
 * (`pcc -o strerror-test strerror-test.c') links libap.a alone -- it
 * would have PASSED against the broken tree and proved nothing. The
 * failing call is strerror() made from a program that links libgnu.a,
 * so that is the call this reproduces:
 *
 *	cd sys/lib/tests
 *	pcc -o strerror-test strerror-test.c \
 *		$home/APExp/$objtype/lib/ape/libgnu.a
 *	./strerror-test
 *
 * Section 1 is the one that matters and it either returns or it kills
 * the process; there is no failing answer it can print. So every
 * section flushes a line BEFORE the call it is about to make, and the
 * last line on the screen names the call that did not come back.
 *
 * On glibc this links and passes with or without the extra archive,
 * which is the point of checking it there: it says the test is right,
 * not that the tree is.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

static int failures = 0;

static void
ok(int cond, char *what)
{
	if(cond)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s\n", what);
		failures++;
	}
}

/*
 * Every errno this asks about, by name rather than by number: the
 * numbers are APE's own and differ from glibc's, and the test has to
 * mean the same thing on both.
 */
static struct {
	int	e;
	char	*name;
} known[] = {
	{ENOENT,	"ENOENT"},
	{EINVAL,	"EINVAL"},
	{EACCES,	"EACCES"},
	{ENOMEM,	"ENOMEM"},
	{EEXIST,	"EEXIST"},
	{EPIPE,		"EPIPE"},
	{ERANGE,	"ERANGE"},
	{EDOM,		"EDOM"},
};
#define NKNOWN ((int)(sizeof known / sizeof known[0]))

int
main(void)
{
	int i;
	char *s;

	/*
	 * 1. The bug itself. strerror(ENOENT) is the exact call the
	 * recursion was found on -- lstk() printed n=0x14 all the way
	 * down. Reaching the line after it IS the pass.
	 */
	printf("section 1: calling strerror(ENOENT)...\n");
	fflush(stdout);
	s = strerror(ENOENT);
	ok(1, "strerror(ENOENT) returned at all");
	ok(s != 0, "strerror(ENOENT) is not NULL");
	ok(s != 0 && *s != '\0', "strerror(ENOENT) is not empty");
	printf("note  strerror(ENOENT) = \"%s\"\n", s ? s : "(null)");

	/*
	 * 2. The rest of the common errnos, each behind its own marker
	 * for the same reason: a recursion that only fires for some
	 * values would otherwise stop the run with no way to tell which
	 * one did it.
	 */
	for(i = 0; i < NKNOWN; i++){
		printf("section 2: calling strerror(%s)...\n", known[i].name);
		fflush(stdout);
		s = strerror(known[i].e);
		ok(s != 0 && *s != '\0', known[i].name);
	}

	/*
	 * 3. An errno nothing defines. gnulib's version answered
	 * "Unknown error %d" here and libap's answers "Unknown error";
	 * the test asserts only that something comes back, because
	 * which of the two is right is not what this file is about and
	 * an assertion on the text would just pin the current library.
	 */
	printf("section 3: calling strerror(4242)...\n");
	fflush(stdout);
	s = strerror(4242);
	ok(s != 0 && *s != '\0', "strerror of an unknown errno answers something");
	printf("note  strerror(4242) = \"%s\"\n", s ? s : "(null)");

	/*
	 * 4. perror() and gnulib's error() both reach strerror through
	 * one more layer, and that layer is what tar was actually in.
	 * perror is the one available without libgnu, so it is the
	 * stand-in.
	 */
	printf("section 4: calling perror()...\n");
	fflush(stdout);
	errno = ENOENT;
	perror("note  perror");
	ok(1, "perror returned at all");

	printf("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
	return failures;
}
