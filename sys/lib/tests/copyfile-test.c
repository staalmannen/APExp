/*
 * copyfile-test.c -- Tcl's `file copy`, call for call.
 *
 * WHERE THIS CAME FROM. Four lines in tclsh:
 *
 *	cd /tmp
 *	set f [open a.txt w]; puts $f hi; close $f
 *	file copy -force a.txt b.txt
 *	error copying "a.txt" to "b.txt": no such file or directory
 *
 * A file written one line earlier cannot be copied. That aborts
 * encoding.test, http.test and fCmd.test outright -- tcltest counts
 * nothing at all for a file that exits with an error, so fCmd's eighty
 * failures are invisible in the suite total.
 *
 * WHY A PROBE RATHER THAN MORE READING. Five separate candidates were
 * argued from the source and none of them held up: the S_IFMT dispatch
 * in DoCopyFile, open()'s access() precheck, the mode argument carrying
 * S_IFREG, utime()'s wstat, and the destination lstat. The message
 * cannot distinguish them either -- Tcl prints `Tcl_PosixError` at a
 * common `done:` label, so it reports whatever errno holds by then and
 * names both paths. So this asks the machine, which is what has settled
 * every question of this shape here.
 *
 * WHAT IT REPLICATES, in order, from tclFCmd.c CopyRenameOneFile,
 * tclUnixFCmd.c DoCopyFile, TclUnixCopyFile and CopyFileAtts:
 *
 *	lstat(src)
 *	lstat(dst)			<- must fail with ENOENT exactly
 *	open(src, O_RDONLY)
 *	open(dst, O_CREAT|O_TRUNC|O_WRONLY, srcStat.st_mode)
 *	read/write
 *	chmod(dst, mode & 07777-ish)
 *	utime(dst, &tval)
 *
 * THE ONE ASSERTION TCL'S CONTROL FLOW DEPENDS ON is the second line:
 *
 *	if (Tcl_FSLstat(target, &targetStatBuf) != 0) {
 *	    if (errno != ENOENT) { errfile = target; goto done; }
 *
 * A destination that does not exist yet is the normal case, and the
 * whole copy is refused unless lstat reports exactly ENOENT -- which in
 * APE is 20, not the 2 a reader expects.
 *
 * Note the mode passed to open() is the FULL st_mode, S_IFREG and all
 * (0100644, not 0644). That is upstream's, and POSIX says the file-type
 * bits are ignored; it is here because a faithful probe has to make the
 * same call, not a tidier one.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <utime.h>
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

/* a step that must succeed; reports what the system said when it does not */
static int
step(const char *what, int r)
{
	const char *pe;

	if(r >= 0){
		printf("  YES  %s\n", what);
		return r;
	}
	pe = p9err();
	printf("  no   %s -> errno %d (%s)%s%s\n", what, errno,
		strerror(errno), pe[0] ? "; plan 9 says: " : "", pe);
	failures++;
	return r;
}

#define SRC "cft-src.txt"
#define DST "cft-dst.txt"

int
main(void)
{
	struct stat ss, ds;
	struct utimbuf tval;
	int sfd, dfd, n, e;
	char buf[4096];

	unlink(SRC);
	unlink(DST);

	printf("--- 1. write the source, as `open a.txt w` does ---\n");
	sfd = step("open " SRC " for writing",
		open(SRC, O_WRONLY|O_CREAT|O_TRUNC, 0666));
	if(sfd < 0)
		return failures;
	step("write to it", (int)write(sfd, "hi\n", 3));
	close(sfd);

	printf("--- 2. the two stats Tcl does first ---\n");
	step("lstat " SRC, lstat(SRC, &ss));
	printf("  note source st_mode 0%o, size %ld\n",
		(unsigned)ss.st_mode, (long)ss.st_size);

	errno = 0;
	if(lstat(DST, &ds) == 0)
		ok("lstat of a missing destination failed (it exists?)", 0);
	else {
		e = errno;
		printf("  note lstat of a missing file: errno %d (%s)%s%s\n",
			e, strerror(e), p9err()[0] ? "; plan 9 says: " : "",
			p9err());
		/*
		 * This is the branch Tcl takes. Anything but ENOENT and the
		 * copy is abandoned before it starts.
		 */
		ok("...and it is exactly ENOENT, which Tcl requires",
			e == ENOENT);
	}

	printf("--- 3. the copy itself ---\n");
	sfd = step("open " SRC " O_RDONLY", open(SRC, O_RDONLY));
	/*
	 * The full st_mode, S_IFREG included, exactly as TclUnixCopyFile
	 * passes it.
	 */
	printf("  note the mode handed to open() is the full st_mode, 0%o,\n",
		(unsigned)ss.st_mode);
	printf("  note S_IFREG and all, exactly as TclUnixCopyFile passes it\n");
	dfd = step("open " DST " O_CREAT|O_TRUNC|O_WRONLY with that mode",
		open(DST, O_CREAT|O_TRUNC|O_WRONLY, ss.st_mode));
	if(sfd >= 0 && dfd >= 0){
		while((n = (int)read(sfd, buf, sizeof buf)) > 0)
			if(write(dfd, buf, n) != n){
				step("write to the destination", -1);
				break;
			}
	}
	if(sfd >= 0)
		close(sfd);
	if(dfd >= 0)
		close(dfd);

	printf("--- 4. CopyFileAtts: chmod then utime ---\n");
	step("chmod " DST, chmod(DST, ss.st_mode & 07777));
	tval.actime = ss.st_atime;
	tval.modtime = ss.st_mtime;
	step("utime " DST, utime(DST, &tval));

	printf("--- 5. the result ---\n");
	if(lstat(DST, &ds) == 0)
		ok("the copy is the same size as the source",
			ds.st_size == ss.st_size);
	else
		ok("the copy exists", 0);

	unlink(SRC);
	unlink(DST);
	printf("%d failure(s)\n", failures);
	return failures;
}
