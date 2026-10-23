/*
 * fsync-test.c -- does fsync() answer "nothing to do" or "I failed"?
 *
 * WHERE THIS CAME FROM.  With the pthread fixes in, `xz -c <sample.txt
 * >/tmp/t.xz' stopped hanging and produced 72 bytes.  `unxz /tmp/t.xz'
 * then decompressed it correctly and printed
 *
 *	unxz: /tmp/t: Synchronizing the file failed: Invalid argument
 *
 * and **deleted the output**.  libap's fsync was, in full,
 * `errno = EINVAL; return -1;'.
 *
 * xz's `io_sync_dest' (`src/xz/file_io.c:484') turns a nonzero fsync
 * into `success = false' (`:1207'), and `io_close_dest(pair, false)'
 * REMOVES the destination file.  `opt_synchronous' defaults to `true'
 * (`src/xz/args.c:24'), so this was every `xz' and `unxz' on a named
 * file, every time.  ***The bytes were correct, written, and thrown
 * away on the way out.***
 *
 * THE RULE THIS BREAKS is the one CLAUDE.md calls the commonest bug in
 * the tree: *a stub that answers "failure" is not the same as one that
 * answers "nothing to do"*.  Plan 9 has no fsync because a write to a
 * file server is already acknowledged when `write' returns -- so there
 * is nothing to flush, and 0 is the truthful answer.  **libap said so
 * in a second place that disagreed with the first**:
 * `plan9/__p9_syscall.c:594' is `case SYS_fsync: / * Plan9 writes are
 * synchronous; no-op is correct * / return 0;'.
 *
 * SECTION 0 IS THE CONTROL and it is also the whole bug: fsync of an
 * ordinary open file must return 0.  Section 2 is the other half --
 * **a function that cannot fail is its own kind of lie**, so a closed
 * descriptor must still be EBADF.
 *
 * Build:
 *   gcc -o fsync-test fsync-test.c && ./fsync-test      # host, 0
 *   pcc -o fsync-test fsync-test.c && ./fsync-test      # 9front
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#ifndef __linux__
extern int _syncmark(void);
#endif

static int fails;

static void
eq(const char *what, long got, long want)
{
	if (got == want)
		printf("PASS %-46s %ld\n", what, got);
	else {
		printf("FAIL %-46s %ld   want %ld\n", what, got, want);
		fails++;
	}
}

int
main(void)
{
	char nm[] = "/tmp/fsynctestXXXXXX";
	char buf[16];
	int fd, bad, r;

	printf("fsync-test: does fsync() answer `nothing to do' or\n");
	printf("`I failed'?  The second deleted every file xz wrote.\n\n");

#ifndef __linux__
	printf("_syncmark = %d\n\n", _syncmark());
#endif

	/* ---- section 0: CONTROL, and the whole bug ---- */
	printf("Section 0: CONTROL -- fsync of an ordinary open file\n");
	fd = mkstemp(nm);
	if (fd < 0) {
		printf("FAIL could not make a temporary file\n");
		return 1;
	}
	if (write(fd, "hello", 5) != 5) {
		printf("FAIL could not write to it\n");
		close(fd);
		unlink(nm);
		return 1;
	}
	errno = 0;
	r = fsync(fd);
	if (r != 0)
		printf("     errno was %d (%s)\n", errno, strerror(errno));
	eq("fsync of an open regular file returns 0", r, 0);

	/*
	 * And the bytes have to still be there afterwards. This cannot
	 * fail on either system, which is the point: it says the call is
	 * a no-op rather than something that quietly did harm.
	 */
	printf("\nSection 1: the data survives the call\n");
	lseek(fd, 0, SEEK_SET);
	memset(buf, 0, sizeof buf);
	r = (int)read(fd, buf, 5);
	eq("5 bytes read back", r, 5);
	eq("and they are the ones written", strncmp(buf, "hello", 5) == 0, 1);

	/* ---- section 2: it must still be able to fail ---- */
	printf("\nSection 2: a CLOSED descriptor is still EBADF\n");
	printf("     (a function that cannot fail is its own kind of lie.\n");
	printf("      POSIX requires EBADF here, and answering 0 to\n");
	printf("      everything would pass section 0 for the wrong\n");
	printf("      reason.)\n");
	bad = dup(fd);
	close(bad);
	errno = 0;
	r = fsync(bad);
	eq("fsync of a closed descriptor returns -1", r, -1);
	eq("and errno is EBADF", errno, EBADF);

	errno = 0;
	r = fsync(-1);
	eq("fsync(-1) returns -1", r, -1);
	eq("and errno is EBADF", errno, EBADF);

	close(fd);
	unlink(nm);

	printf("\n%d failures\n", fails);
	return fails;
}
