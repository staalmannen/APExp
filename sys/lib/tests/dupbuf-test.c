/*
 * dupbuf-test -- can a BUFFERED descriptor be duplicated?
 *
 *	pcc -o dupbuf-test dupbuf-test.c && ./dupbuf-test
 *
 * On the host, where there is no libap to mark:
 *
 *	gcc -Wall -o /tmp/dupbuf-test dupbuf-test.c \
 *	    -xc <(echo 'int _dupmark(void){return 1;}')
 *	/tmp/dupbuf-test
 *
 * (0 failures on glibc, where nothing is ever "buffered" in libap's
 * sense and every section reduces to an ordinary dup -- which is what
 * makes the host run a control rather than a formality.)
 *
 * ------------------------------------------------------------------
 * THE BUG.
 *
 * `fcntl/fcntl.c''s F_DUPFD arm opened with
 *
 *	if(fi->flags&(FD_BUFFERED|FD_BUFFEREDX)){
 *		err = EGREG;	// dup of buffered fd not implemented
 *		break;
 *	}
 *
 * and `dup()' and `dup2()' are each one line of `fcntl(.., F_DUPFD,..)',
 * so all three refused. A descriptor becomes buffered the first time
 * anything `select()'s it -- libap's select forks a copy process rather
 * than polling -- so **any program with an event loop lost the ability
 * to dup the descriptors it was watching**.
 *
 * Found in bash's own suite, `read7.sub' line 60:
 *
 *	read -e -t .001 a <<<abcde
 *
 * `-e' is readline, which select()s fd 0; the here-string is a
 * redirection of fd 0, so bash saves the original with a dup first. It
 * printed `cannot duplicate fd: Unknown error' -- `Unknown error' being
 * `strerror''s text for EGREG, and also its text for an errno out of
 * range, so the message could not even be traced back to a call.
 *
 * ------------------------------------------------------------------
 * WHAT SEPARATES THE FIX FROM A HALF-FIX, which is section 5.
 *
 * `Muxbuf' is keyed on the descriptor NUMBER, and `Fdinfo' holds a
 * `buf' pointer beside the FD_BUFFERED flag. Deleting the arm and
 * nothing else copies the flag onto a number that has no Muxbuf, and
 * `_readbuf' then answers **EBADF on every read of the new
 * descriptor** -- a dup that succeeds and hands back something broken,
 * which is worse than the refusal it replaced. So section 5 asks what
 * a read of the dup reports, and the one answer it treats as a
 * failure is EBADF. Everything else -- bytes, EOF, EAGAIN -- is
 * information, printed and not asserted, because on Plan 9 the copy
 * process is a second reader of the same open file and which of the
 * two gets a given byte is a race by construction. *A probe where the
 * answer is racy and an assertion where it is not.*
 *
 * Section 6 is the other half of that: the ORIGINAL descriptor must
 * still read its data after the dup. That one is not racy -- the bytes
 * were written before the select, so the copy process has them in the
 * Muxbuf -- and it is what would fail if the dup had torn down or
 * re-keyed the buffer it was supposed to leave alone.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>

static int failures;

static void
ck(int ok, const char *what)
{
	printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
	if(!ok)
		failures++;
}

extern int _dupmark(void);

/*
 * Make fd buffered the way every real caller does: ask select() about
 * it. On glibc this is just a select and changes nothing, which is why
 * the whole file is meaningful there as a control rather than a
 * no-op -- every section still exercises dup, dup2 and F_DUPFD.
 */
static void
makebuffered(int fd)
{
	fd_set r;
	struct timeval tv;

	FD_ZERO(&r);
	FD_SET(fd, &r);
	tv.tv_sec = 0;
	tv.tv_usec = 1000;
	select(fd+1, &r, 0, 0, &tv);
}

int
main(void)
{
	int p[2], d, d2, d3, n;
	char buf[32];

	/*
	 * Unbuffered, so that if a section ever does block the output
	 * already printed says WHICH one -- the first version of this
	 * file hung and its buffered stdout was lost with the kill,
	 * leaving nothing at all to read.
	 */
	setvbuf(stdout, 0, _IONBF, 0);

	/* 1. the library marker */
	printf("1. _dupmark = %d  (libap that can dup a buffered fd)\n\n",
		_dupmark());

	/*
	 * 2. CONTROL: dup of a PLAIN descriptor. This passed before the
	 *    fix and must still pass; a change that broke it would make
	 *    every later section unreadable.
	 */
	if(pipe(p) < 0){
		perror("pipe");
		return 1;
	}
	/*
	 * EVERY READ BELOW IS NON-BLOCKING, AND THAT IS NOT TIDINESS --
	 * the first version of this file HUNG on the host. Section 5
	 * drains the pipe through the dup, section 6 then reads the
	 * original, and with a blocking descriptor there is nothing left
	 * to return. The two readers racing is the very thing this file
	 * exists around, so a blocking read anywhere in it is a hang
	 * waiting for a scheduling accident. O_NONBLOCK once, here, makes
	 * every section bounded by construction rather than by argument.
	 * (It is set on the read end before anything is buffered, so it
	 * is also the state a real event-loop caller would have.)
	 */
	fcntl(p[0], F_SETFL, O_NONBLOCK);

	d = dup(p[0]);
	ck(d >= 0, "2. dup() of a plain descriptor");
	if(d >= 0)
		close(d);

	/*
	 * 3. dup() of a BUFFERED descriptor. This is the bug: it
	 *    answered -1 with errno EGREG before the fix.
	 */
	write(p[1], "abcdefgh", 8);
	makebuffered(p[0]);
	errno = 0;
	d = dup(p[0]);
	if(d < 0)
		printf("   dup errno %d (%s)\n", errno, strerror(errno));
	ck(d >= 0, "3. dup() of a select()ed (buffered) descriptor");

	/*
	 * 4. The same through dup2() and through F_DUPFD with a minimum,
	 *    because all three are the same arm and a fix to one is a fix
	 *    to all three -- but only if they really do share it, which
	 *    is what asking separately is for. The minimum is checked as
	 *    well: POSIX wants the lowest free descriptor >= arg.
	 */
	errno = 0;
	d2 = dup2(p[0], 20);
	if(d2 < 0)
		printf("   dup2 errno %d (%s)\n", errno, strerror(errno));
	ck(d2 == 20, "4a. dup2(buffered, 20) returns 20");

	errno = 0;
	d3 = fcntl(p[0], F_DUPFD, 25);
	if(d3 < 0)
		printf("   F_DUPFD errno %d (%s)\n", errno, strerror(errno));
	ck(d3 >= 25, "4b. fcntl(buffered, F_DUPFD, 25) returns >= 25");

	/*
	 * 5. THE HALF-FIX CONTROL. A read of the new descriptor must not
	 *    answer EBADF -- that is the stale-Muxbuf failure, and it is
	 *    the only outcome here that is a bug. See the header.
	 */
	if(d >= 0){
		errno = 0;
		n = read(d, buf, sizeof buf);
		printf("   read(dup) -> %d", n);
		if(n < 0)
			printf(", errno %d (%s)", errno, strerror(errno));
		else if(n > 0)
			printf(", %.*s", n, buf);
		printf("\n");
		ck(!(n < 0 && errno == EBADF),
			"5. read of the dup does not answer EBADF");
	} else
		ck(0, "5. read of the dup does not answer EBADF (no dup)");

	/*
	 * 6. The ORIGINAL must be undisturbed. Fresh bytes are written
	 *    first, because section 5 may legitimately have taken the
	 *    earlier eight -- the two readers partition the input and
	 *    which gets what is a race, so sizing this on what is left
	 *    would be sizing it on luck. What is NOT racy is whether the
	 *    descriptor still works at all, and that is the assertion:
	 *    EBADF or EIO here would mean the dup had torn down or
	 *    re-keyed the Muxbuf it was supposed to leave alone.
	 */
	write(p[1], "ijklmnop", 8);
	errno = 0;
	n = read(p[0], buf, sizeof buf);
	printf("   read(original) -> %d", n);
	if(n < 0)
		printf(", errno %d (%s)", errno, strerror(errno));
	else if(n > 0)
		printf(", %.*s", n, buf);
	printf("\n");
	ck(n >= 0 || (errno != EBADF && errno != EIO),
		"6. the original buffered descriptor still reads");

	/*
	 * 7. Closing a dup must not tear down the original's buffer --
	 *    `_closebuf' is keyed on the fd number, so the dup's close
	 *    must find nothing and leave the original's Muxbuf alone.
	 */
	if(d2 >= 0)
		close(d2);
	if(d3 >= 0)
		close(d3);
	errno = 0;
	d2 = dup(p[0]);
	ck(d2 >= 0, "7. the original is still duplicable after a dup closed");
	if(d2 >= 0)
		close(d2);

	if(d >= 0)
		close(d);
	close(p[0]);
	close(p[1]);

	printf("\n%d failures\n", failures);
	return failures;
}
