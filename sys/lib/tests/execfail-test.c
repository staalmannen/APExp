/*
 * execfail-test.c -- is the process image unchanged when exec fails?
 *
 * RUN IT AS ./execfail-test -- it re-execs itself in section 5, so it
 * has to be reachable by the name it was started with.
 *
 * WHERE THIS CAME FROM. Tcl's exec-10.20.1 and exec-10.21.1:
 *
 *	exec ~non_existent_user/foo/bar
 *	  wanted: couldn't execute "~non_existent_user/foo/bar":
 *		  no such file or directory
 *	  got:    TclpCreateProcess: unable to write to errPipeOut
 *
 * Tcl's child forks, execs, and if the exec fails writes the reason
 * down an error pipe for the parent to read. That pipe is marked
 * close-on-exec, because its closing is exactly how the parent tells a
 * successful exec from a failed one. libap's execve closed every
 * FD_CLOEXEC descriptor on its way to _EXEC, so when the exec failed
 * and execvp returned, the pipe Tcl was about to explain itself down
 * had already been closed underneath it. The write got EBADF and Tcl
 * panicked -- losing the actual error, which is the part the test is
 * asking about.
 *
 * WHAT POSIX SAYS, and it is unusually blunt: "If the exec function
 * returns to the calling process image, an error has occurred; ... the
 * process image is unchanged."
 *
 * WHAT THIS MEASURES. Not the panic, and not Tcl: the three things
 * libap's execve changes before it tries the exec -- close-on-exec
 * descriptors, the environment, and the signal table's shadow in /env
 * -- asked one at a time after an exec that was always going to fail.
 * Reproducing the CALL the failing code makes rather than the outcome
 * it wants is the point; a test driven through Tcl would have to get
 * Tcl right first.
 *
 * SECTION 5 IS THE CONTROL AND IT IS NOT OPTIONAL. "Never close
 * close-on-exec descriptors" would pass sections 1 to 4 and break
 * every program that relies on FD_CLOEXEC, Tcl included -- the parent
 * would wait for an EOF that never came. So the file also checks that
 * a SUCCESSFUL exec still closes them, using the same pipe-EOF
 * mechanism Tcl itself uses.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/*
 * WHICH libap IS ACTUALLY LINKED IN. `pcc -o x x.c' links against the
 * INSTALLED library, so a copy of this file fresh from a pull can run
 * days-old library code and report on that instead -- a measurement of
 * a build that does not contain the change measures nothing. Declared
 * extern here rather than included, so an old libap fails to LINK with
 * an undefined `_execmark' instead of passing quietly.
 *
 * THE DISCRIMINATOR IS __GNUC__, because pcc predefines only __STDC__
 * and _POSIX_SOURCE -- a guard on __plan9__ would be false everywhere
 * and the marker would never be asked for. socket-server-test.c has
 * the same note and the same reason.
 */
#ifndef __GNUC__
extern int _execmark(void);
#define EXECMARK _execmark()
#else
#define EXECMARK (-1)
#endif

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

/*
 * A path that cannot exist, in the shape the failing tests use: a
 * leading component that is not a directory, so the failure comes from
 * the walk rather than from the last element. Tcl passes the tilde
 * through unexpanded, which is why its own message quotes it verbatim.
 */
static const char *badpath = "~non_existent_user/foo/bar";

int
main(int argc, char **argv)
{
	int fds[2], fd, n, st;
	char c;
	const char *av[3];
	char *v;
	pid_t pid, w;

	/*
	 * The re-exec target for section 5. It must do nothing and say
	 * nothing: the parent is reading a pipe for EOF, and anything
	 * written here would be indistinguishable from a descriptor that
	 * failed to close.
	 */
	if(argc > 1 && strcmp(argv[1], "exitchild") == 0)
		return 0;

	printf("  note libap _execmark = %d  (-1 means built on the host,"
		" where there is no marker to ask)\n", EXECMARK);

	printf("--- 1. a failed execve reports the right errno ---\n");
	errno = 0;
	av[0] = (char *)badpath;
	av[1] = 0;
	n = execve(badpath, (void *)av, (void *)environ);
	printf("  note execve(\"%s\") -> %d, errno %d (%s)\n",
		badpath, n, errno, strerror(errno));
	ok("execve of a path that cannot exist returns -1", n == -1);
	ok("...with ENOENT, which is what the caller prints",
		errno == ENOENT);

	printf("--- 2. ...and a close-on-exec descriptor SURVIVES it ---\n");
	/*
	 * THE ONE THAT MATTERS. This is Tcl's error pipe: created, marked
	 * close-on-exec, then used AFTER the exec has failed. If execve
	 * closed it on the way out, the write below is the EBADF that
	 * became "unable to write to errPipeOut".
	 */
	if(pipe(fds) < 0){
		printf("  note pipe failed: %s\n", strerror(errno));
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	if(fcntl(fds[1], F_SETFD, FD_CLOEXEC) != 0)
		printf("  note fcntl(F_SETFD, FD_CLOEXEC) failed: %s\n",
			strerror(errno));
	execve(badpath, (void *)av, (void *)environ);
	errno = 0;
	n = write(fds[1], "x", 1);
	printf("  note write to the close-on-exec pipe -> %d, errno %d (%s)\n",
		n, errno, n < 0 ? strerror(errno) : "-");
	ok("the error pipe is still writable after a failed exec", n == 1);
	if(n == 1){
		c = 0;
		ok("...and the byte arrives at the other end",
			read(fds[0], &c, 1) == 1 && c == 'x');
	} else
		ok("...and the byte arrives at the other end", 0);
	close(fds[0]);
	close(fds[1]);

	printf("--- 3. ...and an ORDINARY descriptor survives it too ---\n");
	/*
	 * The control for section 2 rather than a second copy of it: if
	 * plain descriptors were being closed as well, the fault would be
	 * somewhere other than the FD_CLOEXEC handling and section 2's
	 * name would be wrong.
	 */
	fd = open("/dev/null", O_RDONLY);
	if(fd < 0)
		fd = open(argv[0], O_RDONLY);
	if(fd < 0)
		printf("  note could not open anything to test with\n");
	execve(badpath, (void *)av, (void *)environ);
	ok("a descriptor with no FD_CLOEXEC is still open",
		fd >= 0 && fcntl(fd, F_GETFD) >= 0);
	if(fd >= 0)
		close(fd);

	printf("--- 4. ...and the ENVIRONMENT survives it ---\n");
	/*
	 * libap's execve starts with _RFORK(RFCENVG), which creates an
	 * EMPTY environment group -- the `C' is clear, not copy. So a
	 * failed exec used to leave the caller with no environment at all,
	 * which is recorded in the notes as a bounded problem because
	 * `environ' in memory is untouched. getenv reads `environ', so it
	 * cannot see that; /env can, and only on Plan 9. Both are asked.
	 */
	putenv((char *)"APEXP_EXECFAIL_TEST=alive");
	execve(badpath, (void *)av, (void *)environ);
	v = getenv("APEXP_EXECFAIL_TEST");
	printf("  note getenv after the failed exec = %s\n", v ? v : "(null)");
	ok("getenv still answers after a failed exec",
		v != NULL && strcmp(v, "alive") == 0);
	fd = open("/env/APEXP_EXECFAIL_TEST", O_RDONLY);
	if(fd < 0)
		printf("  note no /env here (not Plan 9), so the kernel-side"
			" half is not asked\n");
	else {
		char b[32];

		n = read(fd, b, sizeof b - 1);
		if(n < 0)
			n = 0;
		b[n] = 0;
		printf("  note /env/APEXP_EXECFAIL_TEST = \"%s\"\n", b);
		ok("/env still holds the variable after a failed exec",
			strncmp(b, "alive", 5) == 0);
		close(fd);
	}

	printf("--- 5. THE CONTROL: a SUCCESSFUL exec still closes them ---\n");
	/*
	 * Without this, "stop closing close-on-exec descriptors" passes
	 * everything above and breaks FD_CLOEXEC for every program in the
	 * tree -- Tcl included, whose parent waits for the EOF that the
	 * closing produces.
	 *
	 * Asked the way Tcl asks it: the child holds the write end, the
	 * parent closes its own copy and reads. EOF means every write end
	 * is gone, so the exec closed the child's.
	 */
	if(pipe(fds) < 0){
		printf("  note pipe failed: %s\n", strerror(errno));
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	pid = fork();
	if(pid < 0){
		printf("  note fork failed: %s\n", strerror(errno));
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	if(pid == 0){
		close(fds[0]);
		if(fcntl(fds[1], F_SETFD, FD_CLOEXEC) != 0)
			_exit(3);
		av[0] = argv[0];
		av[1] = "exitchild";
		av[2] = 0;
		execve(argv[0], (void *)av, (void *)environ);
		/*
		 * Only here if the re-exec failed. Say so down the pipe, so
		 * the parent reports "could not re-exec" rather than reading
		 * the byte as a broken FD_CLOEXEC.
		 */
		if(write(fds[1], "E", 1) != 1)
			_exit(4);
		_exit(5);
	}
	close(fds[1]);
	errno = 0;
	n = read(fds[0], &c, 1);
	while((w = wait(&st)) != pid && w >= 0)
		;
	close(fds[0]);
	if(n == 1 && c == 'E'){
		printf("  note the child could not re-exec %s -- run this as"
			" ./execfail-test\n", argv[0]);
		printf("  note section 5 says nothing about FD_CLOEXEC\n");
	} else {
		printf("  note read on the pipe after the exec -> %d (0 is EOF,"
			" which is what is wanted)\n", n);
		ok("a successful exec DOES close the close-on-exec descriptor",
			n == 0);
	}

	printf("%d failure(s)\n", failures);
	return failures;
}
