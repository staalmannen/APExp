/*
 * append-test.c -- is O_APPEND atomic when two processes share a file?
 *
 * WHERE THIS CAME FROM. Tcl's exec-19.1, "exec >> uses O_APPEND": four
 * shells append three short lines each to a file that already holds two
 * bytes, and the test checks the SIZE afterwards. It wants 26 and gets
 * 24. Its own comment says what it is for:
 *
 *	Check that no bytes have got lost through mixups with overlapping
 *	appends, which is only guaranteed to work when we set O_APPEND on
 *	the file descriptor in the [exec >>...]
 *
 * TWO BYTES MISSING HAS TWO EXPLANATIONS and the size cannot tell them
 * apart, which is why this file exists rather than a second reading of
 * the test:
 *
 *   (a) the file was TRUNCATED at open, losing the two bytes that were
 *	 there first, and all 24 new bytes arrived safely;
 *   (b) nothing was truncated and one two-byte `echo' was LOST, because
 *	 two appends overlapped.
 *
 * Section 2 asks (a) on its own. Section 3 asks (b) on its own. A run
 * that answers "no" to both would mean the mechanism is something else
 * again and the next step is ratrace.
 *
 * WHY (b) IS THE ONE TO EXPECT. Plan 9 has no O_APPEND: 9P's Twrite
 * carries an explicit offset and there is no "write at the end" request
 * for an ordinary file. libap therefore emulates it, in fcntl/open.c
 * (seek to the end once, at open) and unistd/write.c (seek to the end
 * again before every write). Two calls, and a window between them --
 * so two processes can both seek to N and both write at N, and one
 * write lands on top of the other. With `sleep 1' between echoes, four
 * shells wake on the same second boundary, which is the collision the
 * test is built to provoke.
 *
 * WHAT A "YES" TO (b) WOULD MEAN. That this is a platform limitation
 * rather than a bug to fix here. Plan 9's one atomic append is
 * DMAPPEND, a permanent mode bit on the FILE -- setting it would change
 * the file for every other program and every later open, which is not
 * what O_APPEND means for a descriptor. Do not invent semantics to make
 * a test pass; record it instead.
 *
 * Correct on glibc, which is where it was checked -- and there section
 * 3 must report ZERO lost bytes, because a real O_APPEND is atomic.
 * That is the control for the whole file: if section 3 loses bytes on
 * the host too, the test is wrong and not the tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NPROC	4		/* as many writers as exec-19.1 uses */
/*
 * 256 rounds, not exec-19.1's three. A clean section 3 has to mean
 * "the appends did not collide", and with only a handful of writes it
 * could just as well mean "they never overlapped" -- a negative result
 * with two explanations is not a result. 4 x 256 two-byte writes going
 * flat out makes the window in seek-then-write overwhelmingly likely
 * to be hit if it is there.
 */
#define NLINE	256
#define LINELEN	2		/* "a\n" -- exec-19.1's echo writes two bytes */

static int failures;
static char path[] = "append-test.tmp";

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static off_t
filesize(const char *p)
{
	struct stat st;

	if(stat(p, &st) < 0)
		return -1;
	return st.st_size;
}

/* write the two bytes exec-19.1's makeFile leaves behind */
static int
seed(void)
{
	int fd;

	unlink(path);
	fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fd < 0){
		printf("  note cannot create %s: %s\n", path, strerror(errno));
		return -1;
	}
	if(write(fd, "0\n", 2) != 2){
		printf("  note short write seeding %s\n", path);
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

int
main(void)
{
	int fd, i, j, st;
	pid_t pid[NPROC];
	off_t sz;
	char line[LINELEN];

	printf("--- 1. O_APPEND on a fresh descriptor starts at the END ---\n");
	/*
	 * The cheapest half of (a): does opening an existing file with
	 * O_WRONLY|O_CREAT|O_APPEND -- exec's exact flags, from
	 * tclPipe.c -- leave what was there alone?
	 */
	if(seed() < 0){
		printf("1 failure(s)\n");
		return 1;
	}
	fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0666);
	if(fd < 0){
		printf("  note open failed: %s\n", strerror(errno));
		printf("1 failure(s)\n");
		return 1;
	}
	ok("the two seeded bytes are still there after open", filesize(path) == 2);
	if(write(fd, "xy", 2) != 2)
		printf("  note short write\n");
	close(fd);
	sz = filesize(path);
	printf("  note size after one 2-byte append = %lld (want 4)\n", (long long)sz);
	ok("a single append lands after the existing data, not on it", sz == 4);

	printf("--- 2. (a): does the SECOND opener truncate? ---\n");
	/*
	 * exec-19.1 opens the file four times over. If any open truncated,
	 * the seeded bytes would be gone; this opens it four times without
	 * writing anything at all, so a size change can only be truncation.
	 */
	if(seed() < 0){
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	for(i = 0; i < NPROC; i++){
		fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0666);
		if(fd < 0){
			printf("  note open %d failed: %s\n", i, strerror(errno));
			break;
		}
		close(fd);
	}
	sz = filesize(path);
	printf("  note size after %d opens and no writes = %lld (want 2)\n",
		NPROC, (long long)sz);
	ok("opening O_APPEND four times does not truncate", sz == 2);

	printf("--- 3. (b): do overlapping appends LOSE bytes? ---\n");
	/*
	 * THE QUESTION THE WHOLE FILE IS FOR. Every child opens the file
	 * for itself, exactly as exec's four redirections do -- four
	 * independent descriptors with four independent offsets, not one
	 * inherited descriptor, because a shared offset would not race and
	 * would prove nothing about O_APPEND.
	 *
	 * The children are deliberately NOT staggered. exec-19.1 puts a
	 * `sleep 1' between echoes, which makes four shells wake together
	 * on the same second boundary; writing flat out is the same
	 * collision asked for more often, so a clean run here is a
	 * stronger statement than a clean run there.
	 *
	 * Arithmetic, not eyeballing: the size is exactly predictable, so
	 * the test computes what it should be and reports the shortfall in
	 * bytes. A test that draws its own conclusion has to do the
	 * arithmetic the reader would.
	 */
	if(seed() < 0){
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	for(i = 0; i < NPROC; i++){
		pid[i] = fork();
		if(pid[i] < 0){
			printf("  note fork %d failed: %s\n", i, strerror(errno));
			pid[i] = 0;
			continue;
		}
		if(pid[i] == 0){
			fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0666);
			if(fd < 0)
				_exit(1);
			line[0] = 'a' + i;
			line[1] = '\n';
			for(j = 0; j < NLINE; j++)
				if(write(fd, line, LINELEN) != LINELEN)
					_exit(2);
			close(fd);
			_exit(0);
		}
	}
	for(i = 0; i < NPROC; i++)
		if(pid[i] > 0)
			waitpid(pid[i], &st, 0);

	sz = filesize(path);
	{
		off_t want = 2 + (off_t)NPROC * NLINE * LINELEN;

		printf("  note size = %lld, want %lld", (long long)sz, (long long)want);
		if(sz < want)
			printf("  -- %lld bytes LOST", (long long)(want - sz));
		printf("\n");
		ok("no bytes lost when four processes append at once", sz == want);
		if(sz < want && sz >= (off_t)NPROC * NLINE * LINELEN)
			printf("  note the shortfall is at most the seeded 2 bytes, so"
				" reading (a) is not excluded by this section alone\n");
	}

	printf("--- 4. THE CONTROL: one writer, same loop, must be exact ---\n");
	/*
	 * Without this, "appends lose bytes" would look the same as
	 * "write() is broken", and the conclusion would name the wrong
	 * thing.
	 */
	if(seed() < 0){
		printf("%d failure(s)\n", failures + 1);
		return failures + 1;
	}
	fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0666);
	if(fd >= 0){
		for(j = 0; j < NPROC * NLINE; j++){
			line[0] = 'z';
			line[1] = '\n';
			if(write(fd, line, LINELEN) != LINELEN){
				printf("  note short write at %d\n", j);
				break;
			}
		}
		close(fd);
	}
	sz = filesize(path);
	printf("  note size = %lld (want %d)\n",
		(long long)sz, 2 + NPROC * NLINE * LINELEN);
	ok("a single appender loses nothing",
		sz == 2 + (off_t)NPROC * NLINE * LINELEN);

	unlink(path);
	printf("%d failure(s)\n", failures);
	return failures;
}
