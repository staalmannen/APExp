/*
 * posix-spawn-test.c -- posix_spawn file actions and attributes.
 *
 * libap's posix_spawn used to ignore file actions and attributes
 * altogether: posix_spawn_file_actions_adddup2 and friends returned 0
 * and did nothing, so the child simply inherited the parent's file
 * descriptors. That is not a stub a caller can detect. gnulib's
 * spawn-pipe.c, for one, wires its pipe to the child purely through
 * adddup2, so it would have got a child talking to the wrong fds with
 * no error anywhere.
 *
 * ap/process/posix_spawn.c now forks, replays the actions in the child
 * and execs, reporting any setup failure back through a close-on-exec
 * pipe. These are the cases that distinguishes the two.
 *
 * The child is /bin/cat, /bin/pwd and a deliberately absent name; the
 * test is about plumbing, not about what the child does.
 *
 * Build and run:  pcc -o posix-spawn-test posix-spawn-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <spawn.h>
#include <sys/wait.h>
#include <sys/stat.h>

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s: %s\n", what, detail ? detail : "");
		failures++;
	}
}

/* Wait for pid, return its exit status or -1. */
static int
reap(pid_t pid)
{
	int st;

	while (waitpid(pid, &st, 0) < 0)
		if (errno != EINTR)
			return -1;
	if (WIFEXITED(st))
		return WEXITSTATUS(st);
	return -1;
}

/*
 * cat with its stdout dup2'd onto the write end of a pipe. If adddup2 is
 * ignored, cat writes to the test's own stdout and the read below sees
 * EOF with nothing in it.
 */
static void
test_dup2(void)
{
	posix_spawn_file_actions_t fa;
	pid_t pid;
	int p[2], q[2], err, n;
	char buf[64];
	char *argv[2];

	if (pipe(p) < 0 || pipe(q) < 0) {
		check("adddup2 redirects stdout", 0, "pipe failed");
		return;
	}

	if (posix_spawn_file_actions_init(&fa) != 0) {
		check("adddup2 redirects stdout", 0, "actions_init failed");
		return;
	}
	/* child: stdin = q read end, stdout = p write end */
	posix_spawn_file_actions_adddup2(&fa, q[0], 0);
	posix_spawn_file_actions_adddup2(&fa, p[1], 1);
	posix_spawn_file_actions_addclose(&fa, q[1]);
	posix_spawn_file_actions_addclose(&fa, p[0]);

	argv[0] = "cat";
	argv[1] = NULL;
	err = posix_spawnp(&pid, "cat", &fa, NULL, argv, NULL);
	posix_spawn_file_actions_destroy(&fa);
	if (err != 0) {
		check("adddup2 redirects stdout", 0, strerror(err));
		close(p[0]); close(p[1]); close(q[0]); close(q[1]);
		return;
	}

	close(p[1]);
	close(q[0]);
	write(q[1], "hello\n", 6);
	close(q[1]);

	n = read(p[0], buf, sizeof buf - 1);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	close(p[0]);
	reap(pid);

	check("adddup2 redirects child stdout to a pipe",
	      strcmp(buf, "hello\n") == 0, buf[0] ? buf : "read nothing");
}

/*
 * cat with stdout opened onto a file by addopen. If addopen is ignored
 * the file stays empty (or absent) and the output goes to the test's
 * stdout.
 */
static void
test_addopen(void)
{
	posix_spawn_file_actions_t fa;
	pid_t pid;
	int q[2], err, n, fd;
	char buf[64];
	char *argv[2];
	const char *out = "spawn-test.out";

	remove(out);
	if (pipe(q) < 0) {
		check("addopen redirects stdout to a file", 0, "pipe failed");
		return;
	}
	posix_spawn_file_actions_init(&fa);
	posix_spawn_file_actions_adddup2(&fa, q[0], 0);
	posix_spawn_file_actions_addclose(&fa, q[1]);
	posix_spawn_file_actions_addopen(&fa, 1, out,
	    O_WRONLY|O_CREAT|O_TRUNC, 0666);

	argv[0] = "cat";
	argv[1] = NULL;
	err = posix_spawnp(&pid, "cat", &fa, NULL, argv, NULL);
	posix_spawn_file_actions_destroy(&fa);
	if (err != 0) {
		check("addopen redirects stdout to a file", 0, strerror(err));
		close(q[0]); close(q[1]);
		return;
	}
	close(q[0]);
	write(q[1], "written\n", 8);
	close(q[1]);
	reap(pid);

	n = 0;
	fd = open(out, O_RDONLY);
	if (fd >= 0) {
		n = read(fd, buf, sizeof buf - 1);
		if (n < 0)
			n = 0;
		close(fd);
	}
	buf[n] = '\0';
	remove(out);

	check("addopen redirects child stdout to a file",
	      strcmp(buf, "written\n") == 0, n ? buf : "file empty or absent");
}

/*
 * A child that cannot be exec'd. The error belongs in posix_spawn's
 * return value, not in a 127 exit status the caller has to guess at --
 * that is what the report pipe is for.
 */
static void
test_enoent(void)
{
	pid_t pid;
	int err;
	char *argv[2];
	char detail[64];

	argv[0] = "no-such-program-9f3a";
	argv[1] = NULL;
	pid = -1;
	err = posix_spawnp(&pid, "no-such-program-9f3a", NULL, NULL, argv, NULL);
	sprintf(detail, "returned %d", err);
	check("failed exec is reported through the return value",
	      err != 0, detail);
	if (err == 0)
		reap(pid);
}

/*
 * addopen of a path that does not exist: the failure happens in the
 * child, after fork, and still has to come back as a return value.
 */
static void
test_open_failure(void)
{
	posix_spawn_file_actions_t fa;
	pid_t pid;
	int err;
	char *argv[2];
	char detail[64];

	posix_spawn_file_actions_init(&fa);
	posix_spawn_file_actions_addopen(&fa, 1,
	    "no-such-dir-9f3a/out", O_WRONLY|O_CREAT, 0666);

	argv[0] = "true";
	argv[1] = NULL;
	pid = -1;
	err = posix_spawnp(&pid, "true", &fa, NULL, argv, NULL);
	posix_spawn_file_actions_destroy(&fa);
	sprintf(detail, "returned %d", err);
	check("failed file action is reported through the return value",
	      err != 0, detail);
	if (err == 0)
		reap(pid);
}

/* The attribute setters have to store what they are given. */
static void
test_attr_roundtrip(void)
{
	posix_spawnattr_t at;
	sigset_t set, got;
	short flags;
	pid_t pgrp;

	if (posix_spawnattr_init(&at) != 0) {
		check("attributes round-trip", 0, "attr_init failed");
		return;
	}

	check("attr_setflags/getflags",
	      posix_spawnattr_setflags(&at, POSIX_SPAWN_SETSIGMASK) == 0
	      && posix_spawnattr_getflags(&at, &flags) == 0
	      && flags == POSIX_SPAWN_SETSIGMASK, "flags did not survive");

	check("attr_setpgroup/getpgroup",
	      posix_spawnattr_setpgroup(&at, 12345) == 0
	      && posix_spawnattr_getpgroup(&at, &pgrp) == 0
	      && pgrp == 12345, "pgroup did not survive");

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	check("attr_setsigmask/getsigmask",
	      posix_spawnattr_setsigmask(&at, &set) == 0
	      && posix_spawnattr_getsigmask(&at, &got) == 0
	      && sigismember(&got, SIGINT) == 1, "sigmask did not survive");

	sigemptyset(&set);
	sigaddset(&set, SIGTERM);
	check("attr_setsigdefault/getsigdefault",
	      posix_spawnattr_setsigdefault(&at, &set) == 0
	      && posix_spawnattr_getsigdefault(&at, &got) == 0
	      && sigismember(&got, SIGTERM) == 1, "sigdefault did not survive");

	posix_spawnattr_destroy(&at);
}

/*
 * More actions than the initial eight-entry array, to exercise the
 * growth path. Only the last dup2 matters to the output.
 */
static void
test_many_actions(void)
{
	posix_spawn_file_actions_t fa;
	pid_t pid;
	int p[2], q[2], err, n, i;
	char buf[64];
	char *argv[2];

	if (pipe(p) < 0 || pipe(q) < 0) {
		check("many file actions", 0, "pipe failed");
		return;
	}
	posix_spawn_file_actions_init(&fa);
	/* Closing already-closed descriptors is not an error. */
	for (i = 0; i < 20; i++)
		posix_spawn_file_actions_addclose(&fa, 900 + i);
	posix_spawn_file_actions_adddup2(&fa, q[0], 0);
	posix_spawn_file_actions_adddup2(&fa, p[1], 1);
	/* The child must not keep a write end of q, or it never sees
	   EOF on its stdin once the parent closes its own. */
	posix_spawn_file_actions_addclose(&fa, q[1]);
	posix_spawn_file_actions_addclose(&fa, p[0]);

	argv[0] = "cat";
	argv[1] = NULL;
	err = posix_spawnp(&pid, "cat", &fa, NULL, argv, NULL);
	posix_spawn_file_actions_destroy(&fa);
	if (err != 0) {
		check("many file actions", 0, strerror(err));
		close(p[0]); close(p[1]); close(q[0]); close(q[1]);
		return;
	}
	close(p[1]);
	close(q[0]);
	write(q[1], "grown\n", 6);
	close(q[1]);
	n = read(p[0], buf, sizeof buf - 1);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	close(p[0]);
	reap(pid);

	check("action list grows past its initial size",
	      strcmp(buf, "grown\n") == 0, buf[0] ? buf : "read nothing");
}

int
main(void)
{
	test_attr_roundtrip();
	test_dup2();
	test_addopen();
	test_many_actions();
	test_enoent();
	test_open_failure();

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
