#include <sys/statvfs.h>
#include <sys/stat.h>	/* fstat, struct stat */
#include <unistd.h>	/* access */
#include <limits.h>	/* NAME_MAX */
#include <string.h>
#include <stdlib.h>	/* getenv */
#include <errno.h>

/*
 * statvfs / fstatvfs.
 *
 * ***PLAN 9 CANNOT ANSWER THIS QUESTION, AND THAT IS ESTABLISHED
 * RATHER THAN ASSUMED.***  Two independent reasons, and the second is
 * the one that closes it:
 *
 *   1. **9P2000 has no `Tstatfs'.**  The whole message set is
 *      Tversion, Tauth, Tattach, Tflush, Twalk, Topen, Tcreate,
 *      Tread, Twrite, Tclunk, Tremove, Tstat, Twstat -- and `Tstat'
 *      returns a per-file `Dir' with no filesystem-level counts
 *      anywhere.  (Linux's v9fs gets one only from the `9P2000.L'
 *      dialect, which Plan 9 servers do not speak.)
 *
 *   2. **The file servers DO know, and it is still out of reach.**
 *      hjfs has a `df' console command reporting free/used/total --
 *      `echo df >>/srv/hjfs.cmd' -- so the information exists.  It
 *      cannot back this call: *the output goes to the system
 *      CONSOLE*, not to the caller, so there is nothing to read; it
 *      is a WRITE to a ctl file, a side effect needing permission,
 *      from a function callers expect to be read-only; the spelling
 *      is per-server (hjfs's is not cwfs's) and **9P gives no way to
 *      ask which server backs a path**; and hjfs's own manual says it
 *      scans the block table and is slow on a large disk, from a call
 *      programs make casually.
 *
 * *The protocol answer alone would have been a weaker reason*, since
 * a library can do things a protocol cannot; it is the mechanism that
 * rules it out.
 *
 * ---------------------------------------------------------------
 * SO WHAT SHOULD IT RETURN?  There are only two honest answers and
 * each breaks something, which is why this is a switch and not a
 * decision baked in.
 *
 * **FAILING IS CORRECT AND COSTS PORTS.**  POSIX has no way to say
 * "unknown", so ENOSYS is the truthful reply -- and a caller that
 * does not check turns it into ZERO.  php's `disk_free_space()'
 * returns `false'; the Phoronix Test Suite then evaluates
 * `false < 1024', which is true, and reports
 * `Lock creation failed due to lack of disk space' on a disk with
 * plenty.  *Every program that gates on free space before writing
 * stops working*, and the message it prints is about the disk rather
 * than about us.
 *
 * **SUCCEEDING WITH A LARGE VALUE IS A LIE AND UNBLOCKS THEM.**  It
 * is not an unprecedented one: filesystems that genuinely cannot
 * report -- several network and FUSE mounts -- answer this way for
 * exactly this reason, because failing breaks more callers than it
 * helps.  What it costs is a program that checks before writing
 * something huge: it now proceeds and discovers the truth from the
 * failing `write' instead.  **That program was going to fail either
 * way**; the difference is where.
 *
 * ***THE DEFAULT IS THE OPTIMISTIC ANSWER AND `$APEXP_STATVFS=strict'
 * IS THE WAY BACK***, which is this tree's own idiom for a question
 * the platform has not promised an answer to -- `$APEXP_DEBUG',
 * `$APEXP_LISTENDEBUG', `$APEXP_STRTOD_DEBUG' are the precedents.
 * The default serves the porting goal, which is what APExp is for;
 * `strict' serves anyone who would rather be told nothing than told
 * a number, and it is one word.
 *
 * **THE NUMBERS ARE DELIBERATELY RECOGNISABLE.**  `1<<31' blocks of
 * 4096 is 8 TiB -- plausible enough that no program balks, and a
 * round power of two repeated across five fields, so a human reading
 * a debugger or a `stat -f' sees at once that it is synthetic rather
 * than measured.  *A plausible-looking 7.3 TiB would have hidden
 * exactly what this most needs to advertise.*
 *
 * The product is checked rather than hoped: `f_bavail * f_frsize' is
 * 2**31 * 2**12 = 2**43, which fits a 64-bit `fsblkcnt_t` with 20
 * bits to spare and is exact in a double, so the usual
 * `(double)f_bavail * (double)f_frsize' in callers cannot round.
 *
 * `f_namemax' is the one field that is REAL.  `f_type' stays 0, which
 * `<sys/statvfs.h>' documents as "unknown"; inventing a value there
 * would make gnulib believe it had identified the filesystem.
 */

#define UNKNOWN_BLOCKS	(1ULL << 31)	/* x 4096 = 8 TiB */
#define UNKNOWN_FILES	(1ULL << 31)
#define BLOCKSIZE	4096UL

static int strictmode = -1;

/*
 * Read once.  `getenv' walks `/env' on Plan 9, and this is called from
 * a function a program may run in a loop over a directory tree.
 */
static int
statvfs_strict(void)
{
	char *s;

	if(strictmode < 0){
		s = getenv("APEXP_STATVFS");
		strictmode = s != 0 && strcmp(s, "strict") == 0;
	}
	return strictmode;
}

static int
fillunknown(struct statvfs *buf)
{
	if(buf == 0){
		errno = EFAULT;
		return -1;
	}
	if(statvfs_strict()){
		errno = ENOSYS;
		return -1;
	}

	memset(buf, 0, sizeof *buf);
	buf->f_bsize = BLOCKSIZE;
	buf->f_frsize = BLOCKSIZE;
	buf->f_blocks = UNKNOWN_BLOCKS;
	buf->f_bfree = UNKNOWN_BLOCKS;
	buf->f_bavail = UNKNOWN_BLOCKS;
	buf->f_files = UNKNOWN_FILES;
	buf->f_ffree = UNKNOWN_FILES;
	buf->f_favail = UNKNOWN_FILES;
	buf->f_fsid = 0;
	buf->f_flag = 0;
	buf->f_namemax = NAME_MAX;
	buf->f_type = 0;		/* "unknown", per the header */
	return 0;
}

int
statvfs(const char *path, struct statvfs *buf)
{
	if(path == 0){
		errno = EFAULT;
		return -1;
	}
	/*
	 * The path is not consulted beyond existing, and that is
	 * deliberate: reporting success for a path that is not there
	 * would be a second lie on top of the first, and a caller
	 * distinguishing ENOENT from ENOSYS is asking a question we can
	 * answer truthfully.
	 */
	if(access(path, 0) < 0)
		return -1;		/* access set errno */
	return fillunknown(buf);
}

int
fstatvfs(int fd, struct statvfs *buf)
{
	struct stat st;

	if(fstat(fd, &st) < 0)
		return -1;		/* fstat set errno: EBADF etc. */
	return fillunknown(buf);
}

/*
 * Version marker for `statvfs-test.c'.  `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code and report on it.  A test that calls this will
 * not LINK against a libap predating this file.  Fourteenth use of the
 * idiom.
 */
int
_statvfsmark(void)
{
	return 1;
}
