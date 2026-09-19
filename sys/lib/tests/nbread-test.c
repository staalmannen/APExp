/*
 * nbread-test.c -- O_NONBLOCK on a regular file, which POSIX says means
 * nothing at all.
 *
 * WHERE THIS CAME FROM. Twelve failures in Tcl's io.test and
 * chanio.test -- the same six tests through two APIs, which is why the
 * two clusters looked bigger than the one bug:
 *
 *	io-39.9   empty file, non-blocking: got fblocked 1, eof 0
 *	                                    wanted fblocked 0, eof 1
 *	io-35.4   the same thing asked through eof alone
 *	io-32.7   `read $f 20' on a long file returned fewer than 20
 *	io-32.8, io-36.5, io-36.6, and the chan-io twin of every one
 *
 * libap's read() sent ANY descriptor with O_NONBLOCK into the buffered
 * copy-process path, whatever kind of file it was. For a pipe or a
 * socket that is the whole design -- Plan 9 has no non-blocking read,
 * so another process does the reading -- but for a regular file it
 * forks a process for something that can never block, and then reports
 * "would block" whenever that process has not caught up. A file at end
 * of file said "try again later" for ever.
 *
 * POSIX: O_NONBLOCK affects pipes, FIFOs, terminals and sockets. A read
 * from a regular file transfers what is there and returns 0 at end of
 * file; it never fails with EAGAIN.
 *
 * SECTION 3 IS THE POINT OF THE FILE. Sections 1 and 2 would both pass
 * if O_NONBLOCK were ignored EVERYWHERE, which would break every event
 * loop on the system -- so the last section reads an empty pipe and
 * requires EAGAIN. Without it this test cannot tell a fix from a
 * catastrophe.
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

#define EMPTY	"nbr-empty.txt"
#define LONG	"nbr-long.txt"
#define LONGN	8192

static int
openrd(const char *path)
{
	int fd;

	if((fd = open(path, O_RDONLY)) < 0){
		why("open for reading");
		return -1;
	}
	if(fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
		why("fcntl O_NONBLOCK");
	return fd;
}

int
main(void)
{
	char buf[LONGN];
	int fd, p[2], i, n;

	unlink(EMPTY);
	unlink(LONG);

	if((fd = open(EMPTY, O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0){
		why("create " EMPTY);
		printf("1 failure(s)\n");
		return 1;
	}
	close(fd);
	if((fd = open(LONG, O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0){
		why("create " LONG);
		printf("1 failure(s)\n");
		return 1;
	}
	for(i = 0; i < LONGN; i++)
		buf[i] = 'a' + (i % 26);
	if(write(fd, buf, LONGN) != LONGN)
		why("write " LONG);
	close(fd);

	printf("--- 1. an EMPTY file read non-blocking is at end of file ---\n");
	/*
	 * io-39.9 and io-35.4 reduced. The wrong answer is -1/EAGAIN,
	 * which Tcl renders as `fblocked 1, eof 0' -- a file that will
	 * never have more to give, asking to be tried again later.
	 */
	if((fd = openrd(EMPTY)) >= 0){
		errno = 0;
		n = read(fd, buf, sizeof buf);
		if(n < 0)
			why("read of an empty file");
		printf("  note read returned %d\n", n);
		ok("it is 0 (end of file), not -1 with EAGAIN", n == 0);
		close(fd);
	} else
		ok("section 1 could not open the file", 0);

	printf("--- 2. a full read of a long file is FULL ---\n");
	/*
	 * io-32.7: `read $f 20' must give 20. A short read here is the
	 * copy process not having caught up, reported as though the file
	 * had run out.
	 */
	if((fd = openrd(LONG)) >= 0){
		errno = 0;
		n = read(fd, buf, LONGN);
		if(n < 0)
			why("read of a long file");
		printf("  note asked for %d bytes, got %d\n", LONGN, n);
		ok("a non-blocking read of a regular file is not short",
			n == LONGN);
		close(fd);
	} else
		ok("section 2 could not open the file", 0);

	printf("--- 3. THE CONTROL: a pipe still blocks, and says so ---\n");
	/*
	 * Everything above would also pass if O_NONBLOCK were ignored on
	 * every kind of descriptor, which would wedge every event loop on
	 * the system. This is what tells those two apart.
	 */
	if(pipe(p) < 0){
		why("pipe");
		ok("section 3 could not make a pipe", 0);
	} else {
		if(fcntl(p[0], F_SETFL, O_NONBLOCK) < 0)
			why("fcntl O_NONBLOCK on the pipe");
		errno = 0;
		n = read(p[0], buf, sizeof buf);
		if(n < 0)
			why("read of an empty pipe");
		else
			printf("  note read returned %d\n", n);
		ok("an empty non-blocking pipe reports EAGAIN, not 0",
			n < 0 && (errno == EAGAIN || errno == EWOULDBLOCK));
		close(p[0]);
		close(p[1]);
	}

	unlink(EMPTY);
	unlink(LONG);
	printf("%d failure(s)\n", failures);
	return failures;
}
