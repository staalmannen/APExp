/*
 * umask-test -- does umask() STORE the mask and RETURN the previous one,
 * and does it actually remove bits at creation?
 *
 *	pcc -o umask-test umask-test.c && ./umask-test
 *
 * On the host, where there is no libap to mark:
 *
 *	gcc -Wall -o /tmp/umask-test umask-test.c \
 *	    -xc <(echo 'int _umaskmark(void){return 1;}')
 *	/tmp/umask-test
 *
 * (0 failures on glibc.)
 *
 * ------------------------------------------------------------------
 * THE BUG IT CAME FROM, and it was found by a test suite rather than by
 * anything crashing.
 *
 * `ap/stat/umask.c' was, in its entirety:
 *
 *	mode_t umask(mode_t) { return 0; }
 *
 * with the comment "No such concept in plan9, but supposed to be always
 * successful". So the argument was discarded, nothing was stored, and
 * every read answered 0.
 *
 * **bash's `run-builtins' spends 42 of its 225 differing lines on it**,
 * all the same shape: `umask 022` then `umask -S` answering
 * `u=rwx,g=rwx,o=rwx` where `u=rwx,g=rx,o=rx` was wanted. Twenty
 * assertions, one missing variable.
 *
 * *This is the most common bug shape in this tree* -- a stub that
 * answers the wrong thing rather than answering "nothing to do" -- and
 * the rule it breaks is already written down: **a platform having
 * nothing to DISPLAY is no reason for a value not to read back.**
 *
 * ------------------------------------------------------------------
 * HOW THE SECTIONS ARE ARRANGED, AND WHY SECTION 3 IS THE REAL TEST.
 *
 * 1 and 2 ask the bookkeeping: that the mask is stored, and that the
 * call returns the PREVIOUS value rather than the new one. A stub that
 * stored the mask but returned the new value would pass section 1 and
 * fail section 2, which is why they are separate.
 *
 * **Section 3 is what separates a real umask from a remembered number.**
 * It creates a file and a directory under a mask and checks the bits
 * that came back. An implementation that stored the value and never
 * applied it -- "a value that reads back and does nothing" -- passes 1
 * and 2 and fails only here.
 *
 * Section 3 asks only that the masked bits are ABSENT, never that the
 * unmasked ones are present: Plan 9's file server applies
 * `perm & (dirperm | ~0666)' of its own, so a conforming umask can only
 * ever remove more. *Asserting the bits that must be gone is a test;
 * asserting the bits that must remain would be a test of the file
 * server.*
 *
 * **Section 4 is a PROBE and asserts nothing** -- it reports whether
 * the mask survives `exec`, which POSIX requires and this libap does
 * not do: the static lives in the process image, and carrying it over
 * would mean another `/env/' variable beside `_fdinfo' and `_sighdlr'.
 * It prints a number so the next reader measures the gap instead of
 * taking a comment's word for it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int _umaskmark(void);

static int failures;

static void
ok(int cond, const char *what)
{
	printf("%s: %s\n", cond ? "PASS" : "FAIL", what);
	if(!cond)
		failures++;
}

int
main(int argc, char **argv)
{
	mode_t prev;
	struct stat st;
	char fname[64], dname[64];
	int fd;

	/*
	 * The exec'd half of section 4. The parent sets a mask, then
	 * re-execs this program with one argument; POSIX says the mask
	 * is inherited, so a conforming system prints 022 here.
	 */
	if(argc > 1){
		prev = umask(0);
		printf("   child after exec: mask = 0%03o\n", (unsigned)prev);
		printf("   %s\n", prev == 0022 ?
			"INHERITED (POSIX)" :
			"NOT inherited -- known gap, see stat/umask.c");
		return 0;
	}

	printf("umask-test\n");
	printf("_umaskmark = %d  (libap that stores the mask)\n\n",
		_umaskmark());

	/* 1. the mask is stored at all */
	printf("1. umask() stores the value\n");
	umask(0022);
	prev = umask(0022);		/* read it back by setting the same */
	ok(prev == 0022, "a mask set to 022 reads back as 022");
	printf("   read back 0%03o\n\n", (unsigned)prev);

	/*
	 * 2. it returns the PREVIOUS mask, not the new one. An
	 *    implementation that stored but answered the new value
	 *    passes section 1 and fails here.
	 */
	printf("2. umask() returns the PREVIOUS mask\n");
	umask(0022);
	prev = umask(0077);
	ok(prev == 0022, "setting 077 over 022 returns 022");
	prev = umask(0);
	ok(prev == 0077, "setting 0 over 077 returns 077");
	printf("   (a stub returning the NEW value fails exactly here)\n\n");

	/*
	 * 3. THE ONE THAT MATTERS: the mask removes bits at creation.
	 *    Only the masked bits are asserted absent -- see the header.
	 */
	printf("3. the mask REMOVES bits at creation (the real test)\n");
	sprintf(fname, "/tmp/umask-test-f.%d", (int)getpid());
	sprintf(dname, "/tmp/umask-test-d.%d", (int)getpid());
	unlink(fname);
	rmdir(dname);

	umask(0027);
	fd = open(fname, O_CREAT|O_WRONLY, 0777);
	if(fd < 0){
		printf("FAIL: cannot create %s: %s\n", fname, strerror(errno));
		failures++;
	}else{
		close(fd);
		if(stat(fname, &st) < 0){
			printf("FAIL: cannot stat %s\n", fname);
			failures++;
		}else{
			printf("   open(0777) under mask 027 -> 0%03o\n",
				(unsigned)(st.st_mode & 0777));
			ok((st.st_mode & 0027) == 0,
				"group-w and all of other are masked off");
		}
		unlink(fname);
	}

	if(mkdir(dname, 0777) < 0){
		printf("FAIL: cannot mkdir %s: %s\n", dname, strerror(errno));
		failures++;
	}else{
		if(stat(dname, &st) < 0){
			printf("FAIL: cannot stat %s\n", dname);
			failures++;
		}else{
			printf("   mkdir(0777) under mask 027 -> 0%03o\n",
				(unsigned)(st.st_mode & 0777));
			ok((st.st_mode & 0027) == 0,
				"mkdir honours the mask too");
		}
		rmdir(dname);
	}
	umask(0);
	printf("\n");

	/*
	 * 4. PROBE, asserting nothing: does the mask survive exec?
	 *    POSIX says yes; this libap keeps it in a static, so it
	 *    does not. Measured rather than claimed.
	 */
	printf("4. PROBE (no assertion): does the mask survive exec?\n");
	umask(0022);
	fflush(stdout);
	execl(argv[0], argv[0], "child", (char *)0);
	printf("   (could not re-exec %s: %s -- probe skipped)\n",
		argv[0], strerror(errno));
	umask(0);

	printf("\n%d failures\n", failures);
	return failures;
}
