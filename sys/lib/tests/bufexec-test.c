/*
 * bufexec-test -- a descriptor must not arrive POISONED from an exec.
 *
 *	pcc -o bufexec-test bufexec-test.c && ./bufexec-test
 *
 * Correct on gcc too, where it passes trivially -- Linux has no such
 * concept, which is exactly what makes it worth running there first:
 * it says the test is asserting something true of POSIX rather than
 * something true of this tree.
 *
 *	gcc -o /tmp/bufexec-test bufexec-test.c && /tmp/bufexec-test
 *
 * ------------------------------------------------------------------
 * THE BUG, WHICH WAS NOT WHERE ANY OF US WERE LOOKING.
 *
 * bash under vts printed its prompt and exited 0, and the server's 9P
 * trace showed NOT ONE read of the shell's descriptor -- while reads on
 * fds 3 and 5 in the same process worked perfectly. Three rounds went
 * on vts and on bash. It was neither.
 *
 * readline's rl_getc() (input.c) is:
 *
 *	result = 0;
 *	result = _rl_timeout_select (fd + 1, &readfds, 0, 0, 0, ...);
 *	if (result >= 0)
 *		result = read (fd, &c, 1);
 *	...
 *	if (errno != EINTR)
 *		return (RL_ISSTATE (RL_STATE_READCMD) ? READERR : EOF);
 *
 * so a select() that answers NEGATIVE means the read never happens at
 * all, and readline calls it end of file. libap's select() answered -1
 * with EIO, out of _startbuf, because fd 0 carried FD_BUFFEREDX.
 *
 * FD_BUFFERED and FD_BUFFEREDX are not facts about a descriptor. They
 * say that THIS process image has a copy process reading it into a
 * shared segment. fork()'s child runs _detachbuf(), which turns every
 * FD_BUFFERED into FD_BUFFEREDX -- "poisoned", read() and select() both
 * answer EIO and never touch the fd -- and execve() then wrote the
 * flags word verbatim into $_fdinfo, where the new image's _fdinit()
 * applied it verbatim.
 *
 * So EVERY program started by an APE parent that had ever select()ed on
 * a descriptor inherited that descriptor unreadable. It reaches far
 * past bash: it is any APE program run from an interactive APE shell.
 *
 * It only became reachable when READLINE was turned on in bash's
 * config.h, because nothing before that ever asked select() about a
 * terminal. *A fix that makes a process reach code it never reached
 * before can expose anything on that path.*
 *
 * ------------------------------------------------------------------
 * WHAT THIS ASSERTS, AND WHAT IT DELIBERATELY DOES NOT.
 *
 * It asserts that after an exec the descriptor is USABLE: select() and
 * read() reach it rather than refusing with EIO.
 *
 * It does NOT assert that the bytes are all there. They may not be, and
 * that is a real and separate problem: the parent's copy process is
 * still alive and still reading the same open file, so on a shared
 * descriptor the two compete. Asserting delivery here would be
 * asserting something this design does not provide -- and a test that
 * demands the wrong thing gets "fixed" by inventing semantics, which is
 * the failure mode this tree has a rule about. The competition is
 * recorded in docs/notes/libap.md instead.
 *
 * _fdinfomark() is why the test cannot be run against a stale libap by
 * accident: a library that predates the fix does not define it, so the
 * link fails rather than the test passing. The same idiom as
 * _sock_listenmark, _execmark and _ttymark.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

static int failures = 0;

static void
ok(const char *what, int good, const char *detail)
{
	printf("%s: %s%s%s\n", good ? "PASS" : "FAIL", what,
		detail && *detail ? " -- " : "", detail ? detail : "");
	fflush(stdout);
	if(!good)
		failures++;
}

/*
 * The child half. fd 0 is the read end of a pipe the parent has
 * already select()ed on, so in the broken tree it arrives carrying
 * FD_BUFFEREDX and both calls below refuse with EIO without going near
 * the descriptor.
 */
static int
child(void)
{
	fd_set rfds;
	struct timeval tv;
	char buf[16];
	int r, e, flags;

	printf("--- child, fd 0 inherited across exec ---\n");
	fflush(stdout);

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	errno = 0;
	r = select(1, &rfds, NULL, NULL, &tv);
	e = errno;
	{
		char d[128];
		sprintf(d, "select returned %d, errno %d", r, r < 0 ? e : 0);
		/*
		 * 0 or 1 are both fine -- whether anything is queued
		 * depends on the parent's copy process, which is exactly
		 * what this does not assert. -1 with EIO is the bug.
		 */
		ok("select() on an exec-inherited fd does not fail",
			r >= 0 || e != EIO, d);
	}

	/*
	 * And read(), which refuses for the same reason and by a
	 * different line -- pread() tests FD_BUFFEREDX before it tests
	 * anything else. O_NONBLOCK so that an empty pipe answers
	 * instead of hanging; a hang here would be a different failure
	 * and would say so by never finishing.
	 */
	flags = fcntl(0, F_GETFL, 0);
	if(flags != -1)
		fcntl(0, F_SETFL, flags | O_NONBLOCK);
	errno = 0;
	r = read(0, buf, sizeof buf);
	e = errno;
	{
		char d[128];
		sprintf(d, "read returned %d, errno %d", r, r < 0 ? e : 0);
		ok("read() on an exec-inherited fd does not fail with EIO",
			r >= 0 || e != EIO, d);
	}

	printf("child failures: %d\n", failures);
	fflush(stdout);
	return failures;
}

int
main(int argc, char **argv)
{
	int p[2], pid, st;
	fd_set rfds;
	struct timeval tv;

	if(argc > 1 && strcmp(argv[1], "child") == 0)
		return child();

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("bufexec-test\n");
#ifndef __linux__
	printf("_fdinfomark = %d  (libap with the exec scrub)\n",
		_fdinfomark());
#endif

	/*
	 * 1. Put a pipe on fd 0 and make libap buffer it, which is what
	 *    every select() on a descriptor does here: _startbuf forks a
	 *    copy process and sets FD_BUFFERED.
	 */
	if(pipe(p) < 0){
		perror("pipe");
		return 2;
	}
	if(dup2(p[0], 0) < 0){
		perror("dup2");
		return 2;
	}
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	errno = 0;
	if(select(1, &rfds, NULL, NULL, &tv) < 0 && errno == EIO){
		/*
		 * Section 1 failing means fd 0 was ALREADY poisoned when
		 * this program started -- which is the same bug, one
		 * generation earlier, and worth naming rather than
		 * reporting as a setup error.
		 */
		ok("fd 0 was usable when this test started", 0,
			"select gave EIO before any exec: the shell that "
			"started this test handed over a poisoned fd 0");
	}else
		ok("fd 0 was usable when this test started", 1, "");

	/*
	 * 2. Write something, so that a child which CAN read has
	 *    something to find. Not asserted on -- see the header.
	 */
	if(write(p[1], "hello\n", 6) != 6)
		printf("note: could not seed the pipe\n");

	/*
	 * 3. fork and exec ourselves. The fork is the half that poisons
	 *    (the child's _detachbuf) and the exec is the half that used
	 *    to carry the poison into the new image.
	 */
	pid = fork();
	if(pid < 0){
		perror("fork");
		return 2;
	}
	if(pid == 0){
		execl(argv[0], argv[0], "child", (char *)0);
		perror("execl");
		_exit(2);
	}
	if(waitpid(pid, &st, 0) < 0){
		perror("waitpid");
		return 2;
	}
	if(!WIFEXITED(st)){
		ok("the child exited normally", 0, "it did not");
	}else{
		char d[64];
		sprintf(d, "child reported %d failure(s)", WEXITSTATUS(st));
		ok("the child found nothing wrong", WEXITSTATUS(st) == 0, d);
	}

	printf("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
	return failures;
}
