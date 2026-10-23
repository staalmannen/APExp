/*
 * devreg-probe.c -- which files does APE call REGULAR, and does select()
 * then claim they are readable when nothing has been written?
 *
 * THIS IS A PROBE AND NOT A TEST.  Every question in it is about one
 * operating system's own arrangements -- what rio serves, over which
 * protocol, with what length -- and nobody has promised an answer.
 * Report what it prints; do not assert it.  It exits 0 unless it could
 * not run at all.
 *
 * ***IT HAS NO HOST FORM.***  The subject is /dev/mouse under rio, so a
 * gcc build would measure a machine that has neither.  Build it with
 *
 *	pcc -o devreg-probe devreg-probe.c && ./devreg-probe
 *
 * and run it INSIDE a rio window, under apexp-sh, with no wish running.
 *
 * WHERE IT CAME FROM.  select() was changed so that a regular file reads
 * as ready at once, because POSIX says one always is and libap's select
 * answered from a copy process that had not run yet.  The predicate was
 * `_isregular', which is `S_ISREG' -- and on Plan 9 that is a FALLBACK
 * rather than a fact.  `_dirtostat' has no device-type bit to read, so
 * it takes `Dir.type': directory, then `|' and `s' for pipes and
 * sockets, then everything that is not `M' is a character special --
 * and **everything left, which is every file reached through a 9P
 * MOUNT, is called regular.**  rio serves /dev/cons, /dev/mouse,
 * /dev/winname and /dev/snarf from its own file server.
 *
 * If that reasoning is right, /dev/mouse answers S_ISREG, select()
 * marks it readable with the mouse untouched, and Tk's `PollP9Events'
 * -- a zero-timeout select on exactly these two descriptors, followed
 * by a plain blocking `tkp9_readmouse' on whichever is marked -- blocks
 * on its first call.  That is the white window and the suite frozen on
 * its first file.
 *
 * ***AND IF IT IS WRONG, SECTION 1 SAYS SO IN ONE LINE*** -- /dev/mouse
 * reported `chr', select silent, and the freeze is something else.  The
 * reasoning above is a mechanism argued from source, which this tree's
 * own tally puts at about one in eight.
 *
 * SECTION 0 IS THE CONTROL and it is the one to read first: an ordinary
 * file with bytes in it must be regular and must select readable.  If
 * that fails the probe is broken and nothing below it means anything.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>

/*
 * Version marker.  `pcc -o x x.c' relinks against the INSTALLED libap,
 * so a probe built from a fresh pull can measure days-old library code.
 * This will not LINK against a libap predating the _selregular
 * narrowing, which is precisely the state it is meant to distinguish.
 */
extern int _selregmark(void);

static int
selready(int fd)
{
	struct timeval tv;
	fd_set rs;
	int n;

	FD_ZERO(&rs);
	FD_SET(fd, &rs);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	n = select(fd + 1, &rs, 0, 0, &tv);
	if (n < 0)
		return -1;
	return FD_ISSET(fd, &rs) != 0;
}

static const char *
kindof(mode_t m)
{
	if (S_ISDIR(m))  return "dir";
	if (S_ISCHR(m))  return "chr";
	if (S_ISBLK(m))  return "blk";
	if (S_ISFIFO(m)) return "fifo";
	if (S_ISREG(m))  return "REG";
	return "?";
}

/*
 * Open a name read-only and say what APE thinks it is.  `want' is what
 * this file predicts, printed beside the answer so that a run reads as
 * a comparison rather than as a list of numbers.
 */
static void
look(const char *name, const char *want)
{
	struct stat st;
	int fd, r;

	fd = open(name, O_RDONLY);
	if (fd < 0) {
		printf("     %-16s could not open: %s\n", name, strerror(errno));
		return;
	}
	if (fstat(fd, &st) < 0) {
		printf("     %-16s could not fstat: %s\n", name, strerror(errno));
		close(fd);
		return;
	}
	r = selready(fd);
	printf("     %-16s %-4s size %-8ld  select %-12s (predicted %s)\n",
	    name, kindof(st.st_mode), (long)st.st_size,
	    r < 0 ? "ERROR" : (r ? "READABLE" : "not ready"), want);
	close(fd);
}

int
main(void)
{
	char nm[] = "/tmp/devregXXXXXX";
	char em[] = "/tmp/devregeXXXXXX";
	struct stat st;
	int fd, r;

	printf("devreg-probe: which files does APE call regular, and does\n");
	printf("select() then report them readable?  PROBE -- report what it\n");
	printf("prints, do not assert it.  Run inside a rio window, under\n");
	printf("apexp-sh, with no wish running.\n\n");
	printf("_selregmark = %d\n\n", _selregmark());

	/* ---- section 0: CONTROL ---- */
	printf("Section 0: CONTROL -- an ordinary file with bytes in it\n");
	fd = mkstemp(nm);
	if (fd < 0) {
		printf("     could not make a temporary file -- the probe\n");
		printf("     cannot run, and nothing below would mean anything\n");
		return 1;
	}
	write(fd, "hello", 5);
	lseek(fd, 0, SEEK_SET);
	fstat(fd, &st);
	r = selready(fd);
	printf("     %-16s %-4s size %-8ld  select %-12s (predicted REG, READABLE)\n",
	    nm, kindof(st.st_mode), (long)st.st_size,
	    r < 0 ? "ERROR" : (r ? "READABLE" : "not ready"));
	if (!(S_ISREG(st.st_mode) && r == 1))
		printf("     *** CONTROL FAILED -- read nothing below ***\n");
	close(fd);
	unlink(nm);

	/*
	 * An EMPTY regular file is the case the length discriminator gives
	 * up on, deliberately: it falls back to the buffered path, whose
	 * copy process reaches end of file at once.  So `not ready' here
	 * is the slow arm working, not a fault -- it is printed because a
	 * reader who does not know that would call it one.
	 */
	printf("\nSection 1: an EMPTY regular file -- the deliberate fallback\n");
	fd = mkstemp(em);
	if (fd < 0)
		printf("     could not make a temporary file -- SKIPPED\n");
	else {
		fstat(fd, &st);
		r = selready(fd);
		printf("     %-16s %-4s size %-8ld  select %-12s\n",
		    em, kindof(st.st_mode), (long)st.st_size,
		    r < 0 ? "ERROR" : (r ? "READABLE" : "not ready"));
		printf("     (either answer is correct: the fast arm wants a\n");
		printf("      positive length, so this one takes the copy\n");
		printf("      process, which hits EOF immediately.)\n");
		close(fd);
		unlink(em);
	}

	/* ---- section 2: THE QUESTION ---- */
	printf("\nSection 2: rio's own files -- THE QUESTION\n");
	printf("     If /dev/mouse says REG and select says READABLE, the\n");
	printf("     white-window freeze is explained: Tk polls it with a\n");
	printf("     zero timeout and then reads it, and the read blocks\n");
	printf("     until the mouse moves.  If it says `chr', or says REG\n");
	printf("     and `not ready', the freeze is something else and the\n");
	printf("     reasoning in this file's header is wrong.\n");
	look("/dev/mouse",   "REG under rio");
	look("/dev/cons",    "chr if isatty ran, else REG");
	look("/dev/winname", "REG under rio");
	look("/dev/snarf",   "REG under rio");

	/* ---- section 3: kernel devices, for contrast ---- */
	printf("\nSection 3: kernel devices, for contrast (type != 'M')\n");
	printf("     These are not served over a mount, so `_dirtostat'\n");
	printf("     reaches its character-special arm and the question\n");
	printf("     above never arises for them.\n");
	look("/dev/null", "chr");
	look("/dev/zero", "chr");
	look("/dev/time", "chr");

	printf("\ndevreg-probe: done (a probe asserts nothing; exit 0)\n");
	return 0;
}
