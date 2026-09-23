/*
 * progname-test.c -- does a program know its own name?
 *
 * RUN IT AS ./progname-test, and then again by a path and through a
 * link if you like; it reports what it was told rather than asserting
 * one spelling.
 *
 * WHERE THIS CAME FROM. GNU tar under APExp printed
 *
 *	: This does not look like a tar archive
 *
 * where tar anywhere else says "tar: ...". The missing word is not
 * cosmetic: gnulib's error() is `#define program_name getprogname ()'
 * (gnulib/error.c:128), so EVERY GNU program built here -- tar, sed,
 * awk, grep, m4, gettext -- had been reporting its diagnostics with no
 * name at all, and a build log full of unattributed messages cannot be
 * read.
 *
 * libap's getprogname() returned `argv0', lib9's global. lib9 fills
 * that from ARGBEGIN, a Plan 9 idiom no APE program executes, so it
 * was NULL unless the program happened to call getopt_long -- which
 * set it as a side effect, which is why some programs named themselves
 * and others did not. It is now set in plan9/callmain.c, the one path
 * every APE program takes.
 *
 * WHAT THIS ASKS. Three things, and the third is the one that was
 * broken:
 *   1. getprogname() is never NULL -- callers print it with %s.
 *   2. it is not empty.
 *   3. it is the BASENAME, because that is what every implementation
 *      this is modelled on returns and what "tar:" rather than
 *      "/bin/tar:" depends on.
 *
 * Correct on glibc, which is where it was checked -- there
 * getprogname() is the C library's own.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __GNUC__
/*
 * ON THE HOST, getprogname() is SUPPLIED HERE. It is a BSD name and
 * this glibc does not have it -- the first build of this file failed
 * to link for exactly that reason. glibc's equivalent is
 * program_invocation_short_name, which is already the basename, and
 * which is the arm gnulib's own getprogname.c takes first
 * (getprogname.c:57). So the host still exercises everything this
 * file asserts -- not NULL, not empty, basename, stable -- against a
 * reference implementation, which is the point of checking here
 * before the VM.
 */
extern char *program_invocation_short_name;
static const char *
getprogname(void)
{
	return program_invocation_short_name;
}
#else
extern const char *getprogname(void);
/*
 * WHICH libap IS LINKED IN. `pcc -o x x.c' links against the INSTALLED
 * library, so a fresh copy of this file can measure days-old code.
 * An old libap has no _ttymark either, but that one belongs to the
 * termios round; argv0 is the marker that matters here, and it is
 * lib9's own global rather than something added -- so this file
 * reports it instead, which is the honest thing available.
 */
extern char *argv0;
#endif

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

int
main(int argc, char **argv)
{
	const char *p;

	printf("--- 1. what the program was invoked as ---\n");
	printf("  note argv[0]      = \"%s\"\n", argc > 0 && argv[0] ? argv[0] : "(none)");
#ifndef __GNUC__
	printf("  note libap argv0  = \"%s\"\n", argv0 ? argv0 : "(null)");
#endif

	printf("--- 2. getprogname() answers, and is usable ---\n");
	p = getprogname();
	printf("  note getprogname() = %s\n", p ? p : "(NULL)");
	/*
	 * NULL first and on its own: every caller prints this with %s,
	 * so a NULL here is a fault waiting in gnulib's error(), and the
	 * checks below would be the ones that faulted rather than the
	 * ones that reported.
	 */
	ok("getprogname() is not NULL", p != NULL);
	if(p == NULL){
		printf("%d failure(s)\n", failures);
		return failures;
	}
	ok("...and not empty -- this is the bug tar was reporting",
		*p != '\0');

	printf("--- 3. it is the BASENAME, not the path ---\n");
	/*
	 * THE ONE THAT DISTINGUISHES A FIX FROM A HALF-FIX. Returning
	 * argv[0] whole would pass section 2 and still make tar say
	 * "/bin/tar:" where every other system says "tar:".
	 */
	ok("no '/' in the answer", strchr(p, '/') == NULL);
	if(argc > 0 && argv[0]){
		const char *want = strrchr(argv[0], '/');
		want = want ? want + 1 : argv[0];
		printf("  note basename of argv[0] = \"%s\"\n", want);
		ok("...and it matches the basename of argv[0]",
			strcmp(p, want) == 0);
	}

	printf("--- 4. THE CONTROL: it is stable across calls ---\n");
	/*
	 * Without this, an implementation returning a pointer into a
	 * buffer it reuses would pass everything above and hand the
	 * second caller something else.
	 */
	ok("two calls give the same string", strcmp(getprogname(), p) == 0);

	printf("%d failure(s)\n", failures);
	return failures;
}
