/*
 * rename-test.c -- rename(), and especially rename() of a DIRECTORY.
 *
 * WHERE THIS CAME FROM. Of fCmd.test's thirty-five failures, fifteen
 * need symbolic links and eight need a password database; nearly all of
 * the rest were one bug, and Tcl reported it as
 *
 *	error renaming "td1" to "td3/td3": invalid operation: 'td3/td3'
 *	errorCode: POSIX {unknown error} {invalid operation: 'td3/td3'}
 *
 * -- for `file rename td1 td3/td3', which fCmd-9.11 expects to simply
 * SUCCEED. A wstat can change a name but cannot move a file to another
 * directory, so libap's rename() copies across directories; and the copy
 * path ran for directories too, where it did
 *
 *	_CREATE(to, OWRITE, s->mode)
 *
 * A directory cannot be opened for writing. So EVERY rename of a
 * directory into a different directory failed, and failed with an errno
 * that has no POSIX name. That also explains two tests that look
 * unrelated: fCmd-9.1 and unixFCmd-1.7 wanted "permission denied" and
 * got "invalid operation", because the create failed for its own reason
 * before the permission on the real target was ever reached.
 *
 * SECTION 4 IS A REAL DIVERGENCE AND IS WRITTEN TO ALLOW IT. POSIX says
 * renaming a NON-EMPTY directory within one file system succeeds, and on
 * glibc it does. Plan 9 cannot move a directory at all, so libap answers
 * EXDEV and leaves the recursive copy to the caller -- which is what
 * POSIX's EXDEV is for, and what Tcl's CopyRenameOneFile already branches
 * on. The check is therefore "succeeded, or said exactly EXDEV", which
 * is not a check that cannot fail: it fails for EPLAN9, which is what
 * this bug produced, and for any other errno.
 *
 * SECTION 5 IS THE OTHER HALF. POSIX requires EINVAL when the old
 * pathname is an ancestor of the new one. `file rename td1 td1' becomes
 * rename("td1", "td1/td1"), and fCmd-9.14.3 does it through `..', which
 * is why the implementation compares qids up the tree rather than
 * comparing strings -- a textual prefix test passes 5a and fails 5b.
 *
 * Correct on glibc, which is where it was checked.
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

static void
why(const char *what)
{
	const char *pe;

	pe = p9err();
	printf("  note %s -> errno %d (%s)%s%s\n", what, errno,
		strerror(errno), pe[0] ? "; plan 9 says: " : "", pe);
}

static void
mkfile(const char *path, const char *what)
{
	int fd;

	if((fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0666)) >= 0){
		write(fd, what, strlen(what));
		close(fd);
	}
}

static int
exists(const char *path)
{
	struct stat st;

	return stat(path, &st) == 0;
}

static void
nuke(void)
{
	unlink("rt/a/f");
	unlink("rt/b/f");
	unlink("rt/f");
	unlink("rt/g");
	unlink("rt/a/deep/f");
	rmdir("rt/a/deep");
	rmdir("rt/b/moved");
	rmdir("rt/a/moved");
	rmdir("rt/b/empty");
	rmdir("rt/a/empty");
	rmdir("rt/a/full");
	rmdir("rt/self/self");
	rmdir("rt/self");
	chmod("rt/shut", 0777);
	rmdir("rt/shut");
	rmdir("rt/a");
	rmdir("rt/b");
	rmdir("rt");
}

int
main(void)
{
	nuke();

	if(mkdir("rt", 0777) < 0 || mkdir("rt/a", 0777) < 0
	|| mkdir("rt/b", 0777) < 0){
		why("mkdir the scratch tree");
		return 1;
	}

	printf("--- 1. a plain file, renamed within one directory ---\n");
	mkfile("rt/f", "hi\n");
	errno = 0;
	if(rename("rt/f", "rt/g") < 0)
		why("rename rt/f rt/g");
	ok("rt/f became rt/g", exists("rt/g") && !exists("rt/f"));

	printf("--- 2. a plain file, renamed ACROSS directories ---\n");
	errno = 0;
	if(rename("rt/g", "rt/a/f") < 0)
		why("rename rt/g rt/a/f");
	ok("rt/g became rt/a/f", exists("rt/a/f") && !exists("rt/g"));

	printf("--- 3. an EMPTY directory, across directories ---\n");
	/*
	 * This is fCmd-9.11 reduced: it must succeed, and it is what the
	 * OWRITE create made impossible.
	 */
	mkdir("rt/a/empty", 0777);
	errno = 0;
	if(rename("rt/a/empty", "rt/b/empty") < 0)
		why("rename rt/a/empty rt/b/empty");
	ok("an empty directory can be moved to another directory",
		exists("rt/b/empty") && !exists("rt/a/empty"));

	printf("--- 4. a NON-EMPTY directory, across directories ---\n");
	mkdir("rt/a/full", 0777);
	mkfile("rt/a/full/f", "x\n");
	errno = 0;
	if(rename("rt/a/full", "rt/b/full") == 0){
		printf("  note it succeeded, as POSIX asks and glibc does\n");
		ok("a non-empty directory moved, or reported exactly EXDEV", 1);
		rename("rt/b/full", "rt/a/full");	/* put it back */
	} else {
		int e = errno;

		why("rename rt/a/full rt/b/full");
		/*
		 * EXDEV is the answer that TELLS THE CALLER WHAT TO DO, and
		 * Tcl acts on it. EPLAN9 -- an errno with no name -- is the
		 * bug this file came from, so this must not accept it.
		 */
		printf("  note Plan 9 cannot move a directory; EXDEV asks the\n");
		printf("  note caller to copy the tree, which Tcl then does\n");
		ok("a non-empty directory moved, or reported exactly EXDEV",
			e == EXDEV);
	}
	unlink("rt/a/full/f");
	unlink("rt/b/full/f");
	rmdir("rt/a/full");
	rmdir("rt/b/full");

	printf("--- 5a. a directory into itself ---\n");
	mkdir("rt/self", 0777);
	errno = 0;
	if(rename("rt/self", "rt/self/self") == 0){
		ok("rename of a directory into itself failed", 0);
		printf("  note and it left rt/self/self behind\n");
	} else {
		why("rename rt/self rt/self/self");
		ok("...and reported EINVAL, which POSIX requires",
			errno == EINVAL);
	}

	printf("--- 5b. ...reached through `..', which defeats a string test ---\n");
	if(chdir("rt/self") == 0){
		errno = 0;
		if(rename("../self", "../self/foo") == 0){
			ok("rename of ../self into ../self/foo failed", 0);
		} else {
			why("rename ../self ../self/foo");
			ok("...and reported EINVAL too", errno == EINVAL);
		}
		if(chdir("../..") < 0)
			printf("  note could not chdir back\n");
	} else
		printf("  note could not chdir into rt/self; 5b skipped\n");

	printf("--- 6. a rename of something onto itself is a no-op ---\n");
	errno = 0;
	if(rename("rt/a/f", "rt/a/f") < 0)
		why("rename rt/a/f onto itself");
	ok("the file is still there afterwards", exists("rt/a/f"));

	printf("--- 7. a directory whose permissions say no ---\n");
	/*
	 * fCmd-6.6 reduced. POSIX distinguishes EACCES ("the permission
	 * bits say no") from EPERM ("you are not the owner"); Plan 9 says
	 * "permission denied" for the first and libap's errno table
	 * mapped it to the second, so Tcl printed "operation not
	 * permitted" where it wanted "permission denied".
	 *
	 * ROOT SKIPS THIS, and saying so matters: a superuser bypasses the
	 * permission check entirely, the rename SUCCEEDS, and a test that
	 * asserted EACCES would report a failure that is nothing to do
	 * with the library.
	 */
	if(geteuid() == 0){
		printf("  note running as root, which bypasses the check;\n");
		printf("  note this section proves nothing here and is skipped\n");
	} else {
		mkfile("rt/a/f", "hi\n");
		if(mkdir("rt/shut", 0) < 0 && !exists("rt/shut"))
			printf("  note could not make rt/shut; section 7 skipped\n");
		else {
			errno = 0;
			if(rename("rt/a/f", "rt/shut/f") == 0){
				ok("rename into a mode-0 directory failed", 0);
				unlink("rt/shut/f");
			} else {
				why("rename rt/a/f rt/shut/f");
				ok("...and reported EACCES, not EPERM",
					errno == EACCES);
			}
			errno = 0;
			if(mkdir("rt/shut/d", 0777) == 0){
				ok("mkdir inside a mode-0 directory failed", 0);
				rmdir("rt/shut/d");
			} else {
				why("mkdir rt/shut/d");
				ok("...and reported EACCES too", errno == EACCES);
			}
			chmod("rt/shut", 0777);
			rmdir("rt/shut");
		}
	}

	nuke();
	printf("%d failure(s)\n", failures);
	return failures;
}
