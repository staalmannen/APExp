/*
 * rmdir-test.c -- removing a directory, and what Plan 9 says when it
 * will not.
 *
 * WHERE THIS CAME FROM. Tcl's fCmd-20.1 makes `tfa`, makes `tfa/a`,
 * sets tfa/a to permissions 00000, and deletes the lot. Its cleanup
 * reported
 *
 *	error deleting "tfa": invalid operation
 *	errorCode: POSIX {unknown error} {invalid operation}
 *
 * -- "unknown error" being Tcl's rendering of an errno libap had no
 * name for, i.e. EPLAN9, and "invalid operation" being a Plan 9 errstr
 * that is in no table here. So `file delete -force` on a directory
 * fails, and fCmd-20.1 leaves `tfa` behind.
 *
 * WHAT IT COST: THE WHOLE SUITE, AND THE LOOP IS UPSTREAM'S. The very
 * next test ends with
 *
 *	-cleanup { while {[catch {file delete -force tfa}]} {} }
 *
 * an unbounded retry with no limit and no delay, so a delete that can
 * never succeed spins at full CPU for ever, writing nothing. That is
 * the first SPIN in this project's Tcl work -- every earlier hang was a
 * block -- and no amount of care in libap will stop it: the fix has to
 * be that the delete succeeds.
 *
 * So this probe asks the machine which call fails and what it says,
 * rather than reasoning about it, which is the method that settled the
 * announce spelling and the missing loopback.
 *
 * Sections 1 and 2 are POSIX and are correct on glibc, which is where
 * they were checked. Section 3 prints Plan 9's own errstr and compiles
 * only under pcc -- see the __GNUC__ note in socket-server-test.c,
 * which explains why that is the only guard that works here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef __GNUC__
#define HAVE_ERRSTR 1
#endif

#ifdef HAVE_ERRSTR
extern int errstr(char*, unsigned int);
static const char *
p9err(void)
{
	static char buf[256];

	buf[0] = 0;
	errstr(buf, sizeof buf);
	return buf;
}
#else
static const char *
p9err(void)
{
	return "";
}
#endif

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

/* report a call that is allowed to fail, naming what the system said */
static void
tell(const char *what, int r)
{
	const char *pe;

	if(r == 0){
		printf("  YES  %s\n", what);
		return;
	}
	pe = p9err();
	printf("  no   %s -> errno %d (%s)%s%s\n", what, errno,
		strerror(errno), pe[0] ? "; plan 9 says: " : "", pe);
}

static void
cleanup(void)
{
	chmod("tfa/a", 0777);
	chmod("tfa", 0777);
	rmdir("tfa/a");
	unlink("tfa/f");
	rmdir("tfa");
}

int
main(void)
{
	int fd;

	cleanup();

	printf("--- 1. an empty directory can be removed ---\n");
	ok("mkdir tfa", mkdir("tfa", 0777) == 0);
	ok("rmdir tfa", rmdir("tfa") == 0);

	printf("--- 2. a directory with something in it cannot ---\n");
	mkdir("tfa", 0777);
	if((fd = open("tfa/f", O_WRONLY|O_CREAT, 0666)) >= 0)
		close(fd);
	errno = 0;
	tell("rmdir of a non-empty directory (must fail)", rmdir("tfa"));
	ok("...and it reported ENOTEMPTY or EEXIST",
		errno == ENOTEMPTY || errno == EEXIST);
	errno = 0;
	tell("unlink of a directory (POSIX allows EPERM or EISDIR)",
		unlink("tfa"));
	ok("unlink of tfa/f", unlink("tfa/f") == 0);
	ok("rmdir tfa once emptied", rmdir("tfa") == 0);

	/*
	 * 3. fCmd-20.1, step by step. Each line is allowed to fail; what
	 * is wanted is WHICH one does and what the system calls it.
	 */
	printf("--- 3. fCmd-20.1: a subdirectory with no permissions ---\n");
	errno = 0; tell("mkdir tfa", mkdir("tfa", 0777));
	errno = 0; tell("mkdir tfa/a", mkdir("tfa/a", 0777));
	errno = 0; tell("chmod tfa/a 00000", chmod("tfa/a", 0));
	errno = 0; tell("rmdir tfa/a while it is 00000", rmdir("tfa/a"));
	errno = 0; tell("chmod tfa/a back to 0777", chmod("tfa/a", 0777));
	errno = 0; tell("rmdir tfa/a", rmdir("tfa/a"));
	errno = 0; tell("rmdir tfa", rmdir("tfa"));

	printf("  note anything still present after this is what Tcl's\n");
	printf("  note `while {[catch {file delete -force tfa}]} {}` spins on\n");

	cleanup();
	printf("%d failure(s)\n", failures);
	return failures;
}
