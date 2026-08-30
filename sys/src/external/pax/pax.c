/*	$OpenBSD: pax.c,v 1.52 2018/09/13 12:33:43 millert Exp $	*/
/*	$NetBSD: pax.c,v 1.5 1996/03/26 23:54:20 mrg Exp $	*/

/*-
 * Copyright (c) 2012, 2015, 2016, 2017
 *	mirabilos <m@mirbsd.org>
 * Copyright (c) 1992 Keith Muller.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>
#if HAVE_BOTH_TIME_H
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#elif HAVE_TIME_H
#include <time.h>
#endif
#if HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#if HAVE_GRP_H
#include <grp.h>
#endif
#if HAVE_PATHS_H
#include <paths.h>
#endif
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif
#include <unistd.h>

#include "pax.h"
#include "extern.h"

__RCSID("$MirOS: src/bin/pax/pax.c,v 1.29 2018/12/13 07:09:11 tg Exp $");

static int gen_init(void);

/*
 * PAX main routines, general globals and some simple start up routines
 */

/*
 * Variables that can be accessed by any routine within pax
 */
signed char act = ERROR;	/* read/write/append/copy */
const FSUB *frmt = NULL;	/* archive format type */
signed char cflag;		/* match all EXCEPT pattern/file */
signed char cwdfd;		/* starting cwd */
signed char dflag;		/* directory member match only  */
signed char iflag;		/* interactive file/archive rename */
signed char kflag;		/* do not overwrite existing files */
signed char lflag;		/* use hard links when possible */
signed char nflag;		/* select first archive member match */
signed char tflag;		/* restore access time after read */
signed char uflag;		/* ignore older modification time files */
signed char Vflag = 0;		/* print a dot for each file processed */
signed char vflag;		/* produce verbose output */
signed char Dflag;		/* same as uflag except inode change time */
signed char Hflag;		/* follow command line symlinks (write only) */
signed char Lflag;		/* follow symlinks when writing */
signed char Xflag;		/* archive files with same device id only */
signed char Yflag;		/* same as Dflag except after name mode */
signed char Zflag;		/* same as uflag except after name mode */
signed char zeroflag;		/* use \0 as pathname terminator */
signed char vfpart = 0;		/* is partial verbose output in progress */
signed char patime = 1;		/* preserve file access time */
signed char pmtime = 1;		/* preserve file modification times */
signed char nodirs;		/* do not create directories as needed */
signed char pmode;		/* preserve file mode bits */
signed char pids;		/* preserve file uid/gid */
signed char rmleadslash = 0;	/* remove leading '/' from pathnames */
signed char exit_val;		/* exit value */
signed char docrc;		/* check/create file crc */
char	*dirptr;		/* destination dir in a copy */
const char *argv0;		/* root of argv[0] */
enum op_mode op_mode;		/* what program are we acting as? */
sigset_t s_mask;		/* signal mask for cleanup critical sect */
FILE	*listf;			/* fp to print file list to (default stderr) */
int	listfd = STDERR_FILENO;	/* fd matching listf, for sighandler output */
char	*tempfile;		/* tempfile to use for mkstemp(3) */
char	*tempbase;		/* basename of tempfile to use for mkstemp(3) */
time_t	 now;			/* time of program start */

/*
 *	PAX - Portable Archive Interchange
 *
 *	A utility to read, write, and write lists of the members of archive
 *	files and copy directory hierarchies. A variety of archive formats
 *	are supported (some are described in POSIX 1003.1 10.1):
 *
 *		ustar - 10.1.1 extended tar interchange format
 *		cpio  - 10.1.2 extended cpio interchange format
 *		tar - old BSD 4.3 tar format
 *		binary cpio - old cpio with binary header format
 *		sysVR4 cpio -  with and without CRC
 *
 * This version is a superset of IEEE Std 1003.2b-d3
 *
 * Summary of Extensions to the IEEE Standard:
 *
 * 1	READ ENHANCEMENTS
 * 1.1	Operations which read archives will continue to operate even when
 *	processing archives which may be damaged, truncated, or fail to meet
 *	format specs in several different ways. Damaged sections of archives
 *	are detected and avoided if possible. Attempts will be made to resync
 *	archive read operations even with badly damaged media.
 * 1.2	Blocksize requirements are not strictly enforced on archive read.
 *	Tapes which have variable sized records can be read without errors.
 * 1.3	The user can specify via the non-standard option flag -E if error
 *	resync operation should stop on a media error, try a specified number
 *	of times to correct, or try to correct forever.
 * 1.4	Sparse files (lseek holes) stored on the archive (but stored with blocks
 *	of all zeros will be restored with holes appropriate for the target
 *	filesystem
 * 1.5	The user is notified whenever something is found during archive
 *	read operations which violates spec (but the read will continue).
 * 1.6	Multiple archive volumes can be read and may span over different
 *	archive devices
 * 1.7	Rigidly restores all file attributes exactly as they are stored on the
 *	archive.
 * 1.8	Modification change time ranges can be specified via multiple -T
 *	options. These allow a user to select files whose modification time
 *	lies within a specific time range.
 * 1.9	Files can be selected based on owner (user name or uid) via one or more
 *	-U options.
 * 1.10	Files can be selected based on group (group name or gid) via one o
 *	more -G options.
 * 1.11	File modification time can be checked against existing file after
 *	name modification (-Z)
 *
 * 2	WRITE ENHANCEMENTS
 * 2.1	Write operation will stop instead of allowing a user to create a flawed
 *	flawed archive (due to any problem).
 * 2.2	Archives written by pax are forced to strictly conform to both the
 *	archive and pax the specific format specifications.
 * 2.3	Blocking size and format is rigidly enforced on writes.
 * 2.4	Formats which may exhibit header overflow problems (they have fields
 *	too small for large filesystems, such as inode number storage), use
 *	routines designed to repair this problem. These techniques still
 *	conform to both pax and format specifications, but no longer truncate
 *	these fields. This removes any restrictions on using these archive
 *	formats on large filesystems.
 * 2.5	Multiple archive volumes can be written and may span over different
 *	archive devices
 * 2.6	A archive volume record limit allows the user to specify the number
 *	of bytes stored on an archive volume. When reached the user is
 *	prompted for the next archive volume. This is specified with the
 *	non-standard -B flag. The limit is rounded up to the next blocksize.
 * 2.7	All archive padding during write use zero filled sections. This makes
 *	it much easier to pull data out of flawed archive during read
 *	operations.
 * 2.8	Access time reset with the -t applies to all file nodes (including
 *	directories).
 * 2.9	Symbolic links can be followed with -L (optional in the spec).
 * 2.10	Modification or inode change time ranges can be specified via
 *	multiple -T options. These allow a user to select files whose
 *	modification or inode change time lies within a specific time range.
 * 2.11	Files can be selected based on owner (user name or uid) via one or more
 *	-U options.
 * 2.12	Files can be selected based on group (group name or gid) via one o
 *	more -G options.
 * 2.13	Symlinks which appear on the command line can be followed (without
 *	following other symlinks; -H flag)
 *
 * 3	COPY ENHANCEMENTS
 * 3.1	Sparse files (lseek holes) can be copied without expanding the holes
 *	into zero filled blocks. The file copy is created with holes which are
 *	appropriate for the target filesystem
 * 3.2	Access time as well as modification time on copied file trees can be
 *	preserved with the appropriate -p options.
 * 3.3	Access time reset with the -t applies to all file nodes (including
 *	directories).
 * 3.4	Symbolic links can be followed with -L (optional in the spec).
 * 3.5	Modification or inode change time ranges can be specified via
 *	multiple -T options. These allow a user to select files whose
 *	modification or inode change time lies within a specific time range.
 * 3.6	Files can be selected based on owner (user name or uid) via one or more
 *	-U options.
 * 3.7	Files can be selected based on group (group name or gid) via one o
 *	more -G options.
 * 3.8	Symlinks which appear on the command line can be followed (without
 *	following other symlinks; -H flag)
 * 3.9  File inode change time can be checked against existing file before
 *	name modification (-D)
 * 3.10 File inode change time can be checked against existing file after
 *	name modification (-Y)
 * 3.11	File modification time can be checked against existing file after
 *	name modification (-Z)
 *
 * 4	GENERAL ENHANCEMENTS
 * 4.1	Internal structure is designed to isolate format dependent and
 *	independent functions. Formats are selected via a format driver table.
 *	This encourages the addition of new archive formats by only having to
 *	write those routines which id, read and write the archive header.
 */

/*
 * main()
 *	parse options, set up and operate as specified by the user.
 *	any operational flaw will set exit_val to non-zero
 * Return: 0 if ok, 1 otherwise
 */

int
main(int argc, char **argv)
{
	const char *tmpdir;
	size_t tdlen;

	/* may not be a constant, thus initialising early */
	listf = stderr;

	now = time(NULL);

	/*
	 * Keep a reference to cwd, so we can always come back home.
	 */
	cwdfd = binopen2(BO_CLEXEC, ".", O_RDONLY);
	if (cwdfd < 0) {
		syswarn(1, errno, "Cannot open current working directory.");
		return(exit_val);
	}

	/*
	 * Where should we put temporary files?
	 */
	if ((tmpdir = getenv("TMPDIR")) == NULL || *tmpdir == '\0')
		tmpdir = _PATH_TMP;
	tdlen = strlen(tmpdir);
	while (tdlen > 0 && tmpdir[tdlen - 1] == '/')
		tdlen--;
	tempfile = malloc(tdlen + 1 + sizeof(_TFILE_BASE));
	if (tempfile == NULL) {
		paxwarn(1, "%s for %s", "Out of memory",
		    "temp file name");
		return (exit_val);
	}
	if (tdlen)
		memcpy(tempfile, tmpdir, tdlen);
	tempbase = tempfile + tdlen;
	*tempbase++ = '/';

#if HAVE_SETPGENT
	/*
	 * keep passwd and group files open for faster lookups.
	 */
	setpassent(1);
	setgroupent(1);
#endif

	/*
	 * parse options, determine operational mode, general init
	 */
	options(argc, argv);
	if ((gen_init() < 0) || (tty_init() < 0))
		return(exit_val);

#if HAVE_PLEDGE
	/*
	 * pmode needs to restore setugid bits when extracting or copying,
	 * so can't pledge at all then.
	 */
	if (pmode == 0 || (act != EXTRACT && act != COPY)) {
		if (pledge("stdio rpath wpath cpath fattr dpath getpw proc exec tape",
		    NULL) == -1)
			err(1, "pledge");

		/* Copy mode, or no gzip -- don't need to fork/exec. */
		if (compress_program == NULL || act == COPY) {
			if (pledge("stdio rpath wpath cpath fattr dpath getpw tape",
			    NULL) == -1)
				err(1, "pledge");
		}
	}
#endif

	/* make list fd independent and line-buffered */
	if ((listfd = dup(fileno(listf))) < 0 ||
	    !(listf = fdopen(listfd, "wb"))) {
		syswarn(1, errno, "Cannot open list file descriptor");
		return (exit_val);
	}
	if (fcntl(listfd, F_SETFD, FD_CLOEXEC) == -1)
		syswarn(0, errno, "%s on list file descriptor",
		    "Failed to set the close-on-exec flag");
	setlinebuf(listf);

	/*
	 * select a primary operation mode
	 */
	switch (act) {
	case EXTRACT:
		extract();
		break;
	case ARCHIVE:
		archive();
		break;
	case APPND:
		if (compress_program != NULL)
			errx(1, "cannot compress while appending");
		append();
		break;
	case COPY:
		copy();
		break;
	default:
		/* for ar_io.c etc. */
		act = LIST;
		/* FALLTHROUGH */
	case LIST:
		list();
		break;
	}
	return(exit_val);
}

/*
 * sig_cleanup()
 *	when interrupted we try to do whatever delayed processing we can.
 *	This is not critical, but we really ought to limit our damage when we
 *	are aborted by the user.
 * Return:
 *	never....
 */

void
sig_cleanup(int which_sig)
{
	/*
	 * Restore modes and times for any dirs we may have created
	 * or any dirs we may have read. Set vflag and vfpart so the
	 * user will clearly see the message on a line by itself.
	 */
	vflag = vfpart = 1;

	/* paxwarn() uses stdio; fake it as well as we can */
	if (which_sig == SIGXCPU)
		dprintf(STDERR_FILENO, "\nCPU time limit reached, cleaning up.\n");
	else if (!which_sig)
		dprintf(STDERR_FILENO, "\nCowardly giving up, trying to clean up.\n");
	else
		dprintf(STDERR_FILENO, "\nSignal caught, cleaning up.\n");

	ar_close(1);
	sltab_process(1);
	proc_dir(1);
	if (tflag)
		atdir_end();
	_exit(1);
}

/*
 * setup_sig()
 *	set a signal to be caught, but only if it isn't being ignored already
 */

static int
setup_sig(int sig, const struct sigaction *n_hand)
{
	struct sigaction o_hand;

	if (sigaction(sig, NULL, &o_hand) < 0)
		return (-1);

	if (o_hand.sa_handler == SIG_IGN)
		return (0);

	return (sigaction(sig, n_hand, NULL));
}

/*
 * gen_init()
 *	general setup routines. Not all are required, but they really help
 *	when dealing with a medium to large sized archives.
 */

static int
gen_init(void)
{
	struct rlimit reslimit;
	struct sigaction n_hand;

	/*
	 * Really needed to handle large archives. We can run out of memory for
	 * internal tables really fast when we have a whole lot of files...
	 */
	if (getrlimit(RLIMIT_DATA , &reslimit) == 0){
		reslimit.rlim_cur = reslimit.rlim_max;
		(void)setrlimit(RLIMIT_DATA , &reslimit);
	}

	/*
	 * should file size limits be waived? if the os limits us, this is
	 * needed if we want to write a large archive
	 */
	if (getrlimit(RLIMIT_FSIZE , &reslimit) == 0){
		reslimit.rlim_cur = reslimit.rlim_max;
		(void)setrlimit(RLIMIT_FSIZE , &reslimit);
	}

	/*
	 * increase the size the stack can grow to
	 */
	if (getrlimit(RLIMIT_STACK , &reslimit) == 0){
		reslimit.rlim_cur = reslimit.rlim_max;
		(void)setrlimit(RLIMIT_STACK , &reslimit);
	}

	/*
	 * not really needed, but doesn't hurt
	 */
#ifdef RLIMIT_RSS
	if (getrlimit(RLIMIT_RSS , &reslimit) == 0){
		reslimit.rlim_cur = reslimit.rlim_max;
		(void)setrlimit(RLIMIT_RSS , &reslimit);
	}
#endif

	/*
	 * signal handling to reset stored directory times and modes. Since
	 * we deal with broken pipes via failed writes we ignore it. We also
	 * deal with any file size limit through failed writes. CPU time
	 * limits are caught and a cleanup is forced.
	 */
	if ((sigemptyset(&s_mask) < 0) || (sigaddset(&s_mask, SIGTERM) < 0) ||
	    (sigaddset(&s_mask,SIGINT) < 0)||(sigaddset(&s_mask,SIGHUP) < 0) ||
	    (sigaddset(&s_mask,SIGPIPE) < 0)||(sigaddset(&s_mask,SIGQUIT)<0) ||
	    (sigaddset(&s_mask,SIGXCPU) < 0)||(sigaddset(&s_mask,SIGXFSZ)<0)) {
		paxwarn(1, "Unable to set up signal mask");
		return(-1);
	}

	/* snag the fd to be used from the signal handler */
	listfd = fileno(listf);

	memset(&n_hand, 0, sizeof n_hand);
	n_hand.sa_mask = s_mask;
	n_hand.sa_flags = 0;
	n_hand.sa_handler = sig_cleanup;

	if (setup_sig(SIGHUP,  &n_hand) ||
	    setup_sig(SIGTERM, &n_hand) ||
	    setup_sig(SIGINT,  &n_hand) ||
	    setup_sig(SIGQUIT, &n_hand) ||
	    setup_sig(SIGXCPU, &n_hand))
		goto out;

	n_hand.sa_handler = SIG_IGN;
	if ((sigaction(SIGPIPE, &n_hand, NULL) < 0) ||
	    (sigaction(SIGXFSZ, &n_hand, NULL) < 0))
		goto out;
	return (0);

 out:
	syswarn(1, errno, "Unable to set up signal handler");
	return (-1);
}
