/*
 * mkstemp-test -- can one process create MANY temporary files?
 *
 *	pcc -o mkstemp-test mkstemp-test.c && ./mkstemp-test
 *
 * Correct on gcc too, where it passes, which is what says the test
 * asserts something about POSIX rather than about this tree:
 *
 *	gcc -o /tmp/mkstemp-test mkstemp-test.c && /tmp/mkstemp-test
 *
 * ------------------------------------------------------------------
 * THE BUG.
 *
 * libap's mktemp wrote the pid modulo 100000 into five of the six
 * X's and tried one trailing letter 'a'..'z' -- **26 names per
 * process, ever**. The 27th temporary failed, and mktemp reported it
 * by setting template[0] = 0, so the caller then opened "" and Plan
 * 9 answered `empty file name'. mkstemp's twenty retries re-derived
 * the same twenty-six candidates, because nothing in them varied but
 * the pid; *a retry is only a retry if something varies between the
 * tries.*
 *
 * It surfaced as coreutils sort on a 272 MB file:
 *
 *	sort: cannot create temporary file in '/tmp': empty file name
 *
 * -- a message naming /tmp, for a bug that has nothing to do with
 * /tmp, whose tail is a Plan 9 errstr rather than a POSIX strerror.
 *
 * **Why it survived: the 27th.** A program making a handful of
 * temporaries is fine for ever; one making dozens dies. So the
 * number in section 1 is the whole point -- anything at or below 26
 * would have passed on the broken library too.
 *
 * ------------------------------------------------------------------
 * WHAT EACH SECTION IS FOR.
 *
 *  1. Sixty-four at once, all held open. **Sixty-four is chosen to be
 *     comfortably past 26** and small enough not to trouble a
 *     descriptor limit. This is the regression test proper.
 *  2. Every name distinct. A generator could answer without failing
 *     and still hand out the same name twice, which O_EXCL would
 *     turn into a spurious error rather than a duplicate -- but a
 *     collision rate worth knowing about would show here first.
 *  3. The template contract: XXXXXX replaced in place, same length,
 *     same prefix.
 *  4. A template WITHOUT the six X's must fail with EINVAL rather
 *     than be creative. The old code emptied the string and left
 *     errno alone, which is how a naming failure came out wearing
 *     someone else's error.
 *  5. Sequentially, with each file closed and REMOVED before the
 *     next. This is the one the old code could almost pass -- it
 *     frees the name each time, so a 26-name generator survives if
 *     it reuses freed names. It is here so that a future generator
 *     that only works when nothing is held open is still caught by
 *     section 1 rather than flattered by this one.
 *
 * _tempmark() is why this cannot be run against a stale libap by
 * accident: a library predating the fix does not define it, so the
 * LINK fails rather than the test passing. Same idiom as
 * _sock_listenmark, _execmark, _ttymark and _fdinfomark.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#ifndef __linux__
extern int _tempmark(void);
#endif

#define NFILE 64

static int failures;

static void
ok(const char *what, int good, const char *detail)
{
	printf("%s  %s%s%s\n", good ? "PASS" : "FAIL", what,
		detail && *detail ? " -- " : "", detail ? detail : "");
	if(!good)
		failures++;
}

int
main(void)
{
	char name[NFILE][64];
	int fd[NFILE];
	int i, j, n, dup, bad;
	char detail[256];

	printf("mkstemp-test\n");
#ifndef __linux__
	printf("_tempmark = %d  (libap with the 26-names fix)\n\n",
		_tempmark());
#else
	printf("(glibc reference run)\n\n");
#endif

	for(i = 0; i < NFILE; i++)
		fd[i] = -1;

	/*
	 * 1. MANY AT ONCE. The old library failed at the 27th, so the
	 *    count matters more than anything else here: a test that
	 *    asked for twenty would have passed against the bug.
	 */
	n = 0;
	for(i = 0; i < NFILE; i++){
		strcpy(name[i], "/tmp/mkstempXXXXXX");
		errno = 0;
		fd[i] = mkstemp(name[i]);
		if(fd[i] < 0){
			sprintf(detail, "failed at file %d of %d, errno %d (%s)",
				i + 1, NFILE, errno, strerror(errno));
			break;
		}
		n++;
	}
	if(n == NFILE)
		sprintf(detail, "%d files open at once", n);
	ok("64 temporary files in one process", n == NFILE, detail);

	/*
	 * 2. ALL DISTINCT. Only over the ones actually created, so a
	 *    partial section 1 does not make this report a second,
	 *    unrelated failure.
	 */
	dup = 0;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(strcmp(name[i], name[j]) == 0)
				dup++;
	sprintf(detail, "%d duplicate name(s) among %d", dup, n);
	ok("every name distinct", dup == 0, detail);

	/*
	 * 3. THE TEMPLATE CONTRACT: same length, same prefix, and the
	 *    X's gone. A generator that returned a shorter name would
	 *    still "work" for the caller above and break anyone who
	 *    sized a buffer from the template.
	 */
	bad = 0;
	for(i = 0; i < n; i++){
		if(strlen(name[i]) != strlen("/tmp/mkstempXXXXXX"))
			bad++;
		else if(strncmp(name[i], "/tmp/mkstemp", 12) != 0)
			bad++;
		else if(strstr(name[i], "XXXXXX") != NULL)
			bad++;
	}
	sprintf(detail, "%d malformed of %d; first is %s", bad, n,
		n > 0 ? name[0] : "(none)");
	ok("template filled in place, prefix and length kept", bad == 0, detail);

	for(i = 0; i < n; i++){
		if(fd[i] >= 0)
			close(fd[i]);
		unlink(name[i]);
	}

	/*
	 * 4. A BAD TEMPLATE MUST SAY EINVAL. The old code emptied the
	 *    string and left errno holding whatever was there before,
	 *    so the caller printed an unrelated message -- which is
	 *    most of why this bug was hard to read.
	 */
	{
		char bad2[64];

		strcpy(bad2, "/tmp/mkstempNOX");
		errno = 0;
		i = mkstemp(bad2);
		sprintf(detail, "returned %d, errno %d (%s)", i, errno,
			strerror(errno));
		ok("a template without XXXXXX fails with EINVAL",
			i < 0 && errno == EINVAL, detail);
		if(i >= 0){
			close(i);
			unlink(bad2);
		}
	}

	/*
	 * 5. SEQUENTIALLY, each removed before the next. Deliberately
	 *    AFTER section 1 and deliberately not the only test: the
	 *    old 26-name generator could pass this one, because every
	 *    name is freed again before the next is asked for. *A
	 *    check that the broken code passes is not a check* -- it
	 *    is here to catch a different future regression, not this
	 *    one.
	 */
	bad = 0;
	for(i = 0; i < 100; i++){
		char one[64];
		int f;

		strcpy(one, "/tmp/mkstemp2XXXXXX");
		f = mkstemp(one);
		if(f < 0){
			bad = i + 1;
			break;
		}
		close(f);
		unlink(one);
	}
	sprintf(detail, bad ? "failed at %d" : "100 in sequence", bad);
	ok("100 sequential create/close/unlink", bad == 0, detail);

	printf("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
	return failures;
}
