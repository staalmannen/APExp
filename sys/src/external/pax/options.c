/*	$OpenBSD: options.c,v 1.102 2018/09/13 12:33:43 millert Exp $	*/
/*	$NetBSD: options.c,v 1.6 1996/03/26 23:54:18 mrg Exp $	*/

/*-
 * Copyright (c) 2005, 2006, 2007, 2009, 2011, 2012, 2014, 2016,
 *		 2019, 2020
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
#if HAVE_SYS_MTIO_H
#include <sys/mtio.h>
#endif
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#if HAVE_PATHS_H
#include <paths.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif
#include <unistd.h>

#define EXTERN
#include "pax.h"
#include "ar.h"
#include "cpio.h"
#include "tar.h"
#include "extern.h"

__RCSID("$MirOS: src/bin/pax/options.c,v 1.75 2020/09/04 22:27:49 tg Exp $");

#ifndef _PATH_DEFTAPE
#define _PATH_DEFTAPE "/dev/rmt0"
#endif

#define NELEM(a) (sizeof(a) / sizeof((a)[0]))
#define SELEM(a) (sizeof((a)[0]))

/*
 * argv[0] names. Used for tar and cpio emulation
 */

#define NM_TAR  "tar"
#define NM_CPIO "cpio"
#define NM_PAX  "pax"

/*
 * Constants used to specify the legal sets of flags in pax. For each major
 * operation mode of pax, a set of illegal flags is defined. If any one of
 * those illegal flags are found set, we scream and exit
 */

/*
 * flags (one for each option).
 */
#define	AF	0x00000001
#define	BF	0x00000002
#define	CF	0x00000004
#define	DF	0x00000008
#define	FF	0x00000010
#define	IF	0x00000020
#define	KF	0x00000040
#define	LF	0x00000080
#define	NF	0x00000100
#define	OF	0x00000200
#define	PF	0x00000400
#define	RF	0x00000800
#define	SF	0x00001000
#define	TF	0x00002000
#define	UF	0x00004000
#define	VF	0x00008000
#define	WF	0x00010000
#define	XF	0x00020000
#define	CBF	0x00040000	/* nonstandard extension */
#define	CDF	0x00080000	/* nonstandard extension */
#define	CEF	0x00100000	/* nonstandard extension */
#define	CGF	0x00200000	/* nonstandard extension */
#define	CHF	0x00400000	/* nonstandard extension */
#define	CLF	0x00800000	/* nonstandard extension */
#define	CPF	0x01000000	/* nonstandard extension */
#define	CTF	0x02000000	/* nonstandard extension */
#define	CUF	0x04000000	/* nonstandard extension */
#define	CXF	0x08000000
#define	CYF	0x10000000	/* nonstandard extension */
#define	CZF	0x20000000	/* nonstandard extension */
#define	C0F	0x40000000	/* nonstandard extension */

/*
 * ascii string indexed by bit position above (alter the above and you must
 * alter this string) used to tell the user what flags caused us to complain
 */
#define FLGCH	"abcdfiklnoprstuvwxBDEGHLPTUXYZ0"

/*
 * legal pax operation bit patterns
 */

#define ISLIST(x)	(((x) & (RF|WF)) == 0)
#define	ISEXTRACT(x)	(((x) & (RF|WF)) == RF)
#define ISARCHIVE(x)	(((x) & (AF|RF|WF)) == WF)
#define ISAPPND(x)	(((x) & (AF|RF|WF)) == (AF|WF))
#define	ISCOPY(x)	(((x) & (RF|WF)) == (RF|WF))
#define	ISWRITE(x)	(((x) & (RF|WF)) == WF)

/*
 * Illegal option flag subsets based on pax operation
 */

#define	BDEXTR	(AF|BF|LF|TF|WF|XF|CBF|CHF|CLF|CPF|CXF)
#define	BDARCH	(CF|KF|LF|NF|PF|RF|CDF|CEF|CYF|CZF)
#define	BDCOPY	(AF|BF|FF|OF|XF|CBF|CEF)
#define	BDLIST	(AF|BF|IF|KF|LF|OF|PF|RF|TF|UF|WF|XF|CBF|CDF|CHF|CLF|CPF|CXF|CYF|CZF)

/*
 * Routines which handle command line options
 */

static char flgch[] = FLGCH;	/* list of all possible flags */
static OPLIST *ophead = NULL;	/* head for format specific options -x */
static OPLIST *optail = NULL;	/* option tail */

#ifndef SMALL
static int no_op(void);
static int no_op_i(int);
#endif
static int mkpath(char *);
static void process_M(const char *, void (*)(void));
static void printflg(unsigned int);
static int c_frmt(const void *, const void *);
static off_t str_offt(char *);
static void pax_options(int, char **);
static void pax_usage(void) MKSH_A_NORETURN;
static void tar_set_action(int);
static void tar_options(int, char **);
static void tar_usage(void) MKSH_A_NORETURN;
static void cpio_set_action(int);
static void cpio_options(int, char **);
static void cpio_usage(void) MKSH_A_NORETURN;

#ifndef SMALL
static int compress_id(char *_blk, int _size);
static int gzip_id(char *_blk, int _size);
static int bzip2_id(char *_blk, int _size);
static int xz_id(char *_blk, int _size);
#endif

/* command to run as gzip */
static const char GZIP_CMD[] = "gzip";
#ifndef SMALL
/* command to run as compress */
static const char COMPRESS_CMD[] = "compress";
/* command to run as bzip2 */
static const char BZIP2_CMD[] = "bzip2";
/* command to run as lzma and xz */
static const char XZ_CMD[] = "xz";
/* command used for creating lzma archives */
static const char LZMA_WRCMD[] = "lzma";
/* command to run as lzop */
static const char LZOP_CMD[] = "lzop";
#endif
/* used as flag value */
#define COMPRESS_GUESS_CMD ((const void *)&compress_program)

/*
 *	Format specific routine table, MUST be in sorted order
 *	and MUST match enum fsub_order in pax.h
 *	(see pax.h for description of each function)
 *
 *	name, blksz, hdsz, udev, hlk, blkagn, id, st_read,
 *	read, end_read, st_write, write, end_write, trail,
 *	rd_data, wr_data, options, inhead, is_uar
 */

const FSUB fsub[] = {
#ifndef SMALL
/* FSUB_AR: UNIX ARCHIVER */
	{"ar", 512, sizeof(HD_AR), 0, 0, 0, uar_id, no_op,
	uar_rd, uar_endrd, uar_stwr, uar_wr, no_op, uar_trail,
	rd_wrfile, uar_wr_data, bad_opt, 0, 1},

/* FSUB_BCPIO: OLD BINARY CPIO */
	{"bcpio", 5120, sizeof(HD_BCPIO), 1, 0, 0, bcpio_id, cpio_strd,
	bcpio_rd, bcpio_endrd, cpio_stwr, bcpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},
#endif

/* FSUB_CPIO: OLD OCTAL CHARACTER CPIO */
	{"cpio", 5120, sizeof(HD_CPIO), 1, 0, 0, cpio_id, cpio_strd,
	cpio_rd, cpio_endrd, cpio_stwr, cpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},

#ifndef SMALL
/* FSUB_DIST: OLD OCTAL CHARACTER CPIO, UID/GID CLEARED (ANONYMISED) */
	{"dist", 512, sizeof(HD_CPIO), 1, 0, 0, cpio_id, cpio_strd,
	cpio_rd, cpio_endrd, dist_stwr, cpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},
#endif

/* FSUB_SV4CPIO: SVR4 HEX CPIO */
	{"sv4cpio", 5120, sizeof(HD_VCPIO), 1, 0, 0, vcpio_id, cpio_strd,
	vcpio_rd, vcpio_endrd, cpio_stwr, vcpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},

/* FSUB_SV4CRC: SVR4 HEX CPIO WITH CRC */
	{"sv4crc", 5120, sizeof(HD_VCPIO), 1, 0, 0, crc_id, crc_strd,
	vcpio_rd, vcpio_endrd, crc_stwr, vcpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},

#ifndef SMALL
/* FSUB_TAR: OLD TAR */
	{"tar", 10240, BLKMULT, 0, 1, BLKMULT, tar_id, no_op,
	tar_rd, tar_endrd, no_op_i, tar_wr, tar_endwr, tar_trail,
	rd_wrfile, wr_rdfile, tar_opt, 0, 0},
#endif

/* FSUB_USTAR: POSIX USTAR */
	{"ustar", 10240, BLKMULT, 0, 1, BLKMULT, ustar_id, ustar_strd,
	ustar_rd, tar_endrd, ustar_stwr, ustar_wr, tar_endwr, tar_trail,
	rd_wrfile, wr_rdfile, tar_opt, 0, 0},

#ifndef SMALL
/* FSUB_V4NORM: SVR4 HEX CPIO WITH CRC, UID/GID/MTIME CLEARED (NORMALISED) */
	{"v4norm", 512, sizeof(HD_VCPIO), 1, 0, 0, crc_id, crc_strd,
	vcpio_rd, vcpio_endrd, v4norm_stwr, vcpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},

/* FSUB_V4ROOT: SVR4 HEX CPIO WITH CRC, UID/GID CLEARED (ANONYMISED) */
	{"v4root", 512, sizeof(HD_VCPIO), 1, 0, 0, crc_id, crc_strd,
	vcpio_rd, vcpio_endrd, v4root_stwr, vcpio_wr, cpio_endwr, cpio_trail,
	rd_wrfile, wr_rdfile, bad_opt, 1, 0},

/* FSUBFAIL_Z: compress, to detect failure to use -Z */
	{NULL, 0, 4, 0, 0, 0, compress_id, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, 0, 0},
/* FSUBFAIL_XZ: xz, to detect failure to decompress it */
	{NULL, 0, 6, 0, 0, 0, xz_id, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, 0, 0},
/* FSUBFAIL_BZ2: bzip2, to detect failure to use -j */
	{NULL, 0, 4, 0, 0, 0, bzip2_id, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, 0, 0},
/* FSUBFAIL_GZ: gzip, to detect failure to use -z */
	{NULL, 0, 4, 0, 0, 0, gzip_id, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, 0, 0},
#endif
};

/*
 * ford is the archive search order used by get_arc() to determine what kind
 * of archive we are dealing with. This helps to properly id archive formats
 * some formats may be subsets of others....
 */
const unsigned char ford[] = {
	FSUB_USTAR,
#ifndef SMALL
	FSUB_TAR,
	FSUBFAIL_GZ,
	FSUBFAIL_BZ2,
	FSUBFAIL_XZ,
	FSUBFAIL_Z,
#endif
	FSUB_SV4CRC,
	FSUB_SV4CPIO,
	FSUB_CPIO,
#ifndef SMALL
	FSUB_BCPIO,
#endif
	FSUB_MAX
};

/* normalise archives */
int anonarch = 0;

/* extract to standard output */
char to_stdout = 0;

/*
 * Do we have -C anywhere and what is it?
 */
char havechd = 0;
char *chdname = NULL;

/*
 * options()
 *	figure out if we are pax, tar or cpio. Call the appropriate options
 *	parser
 */

void
options(int argc, char **argv)
{
	size_t n;

	/*
	 * Are we acting like pax, tar or cpio (based on argv[0])
	 */
	n = strlen(argv[0]);

	if (n >= 3 && !strcmp(argv[0] + (n - 3), NM_TAR)) {
		argv0 = NM_TAR;
		op_mode = OP_TAR;
		tar_options(argc, argv);
	} else if (n >= 4 && !strcmp(argv[0] + (n - 4), NM_CPIO)) {
		argv0 = NM_CPIO;
		op_mode = OP_CPIO;
		cpio_options(argc, argv);
	} else {
		/* assume pax as the default */
		argv0 = NM_PAX;
		op_mode = OP_PAX;
		pax_options(argc, argv);
	}
}

static int
gather_format(FSUB *fp, const char *name, int flag)
{
	size_t i;

	if ((frmt = (const FSUB *)bsearch((const void *)fp, (const void *)fsub,
	    NELEM(fsub), SELEM(fsub), c_frmt)) != NULL)
		return (0);
	paxwarn(1, "Unknown -%c format: %s", flag, optarg);
	fprintf(stderr, "%s: Known -%c formats are:", name, flag);
	for (i = 0; i < NELEM(fsub); ++i)
		if (fsub[i].name != NULL)
			fprintf(stderr, " %s", fsub[i].name);
	fputs("\n\n", stderr);
	return (1);
}

/*
 * pax_options()
 *	look at the user specified flags. set globals as required and check if
 *	the user specified a legal set of flags. If not, complain and exit
 */

static void
pax_options(int argc, char **argv)
{
	int c;
	unsigned int flg = 0;
	unsigned int bflg = 0;
	const char *errstr;
	char *pt;
	FSUB tmp;

	/*
	 * process option flags
	 */
	while ((c = getopt(argc, argv,
	    "0aB:b:cDdE:f:G:HiJjkLlM:nOo:Pp:rs:T:tU:uvwXx:YZz")) != -1) {
		switch (c) {
		case '0':
			/*
			 * Use \0 as pathname terminator.
			 * (For use with the -print0 option of find(1).)
			 */
			zeroflag = 1;
			flg |= C0F;
			break;
		case 'a':
			/*
			 * append
			 */
			flg |= AF;
			break;
		case 'B':
			/*
			 * non-standard option on number of bytes written on a
			 * single archive volume.
			 */
			if ((wrlimit = str_offt(optarg)) <= 0) {
				paxwarn(1, "Invalid write limit %s", optarg);
				pax_usage();
			}
			if (wrlimit % BLKMULT) {
				paxwarn(1, "Write limit is not a %d byte multiple",
				    BLKMULT);
				pax_usage();
			}
			flg |= CBF;
			break;
		case 'b':
			/*
			 * specify blocksize
			 */
			flg |= BF;
			if ((wrblksz = (int)str_offt(optarg)) <= 0) {
				paxwarn(1, "Invalid block size %s", optarg);
				pax_usage();
			}
			break;
		case 'c':
			/*
			 * inverse match on patterns
			 */
			cflag = 1;
			flg |= CF;
			break;
		case 'D':
			/*
			 * On extraction check file inode change time before the
			 * modification of the file name. Non standard option.
			 */
			Dflag = 1;
			flg |= CDF;
			break;
		case 'd':
			/*
			 * match only dir on extract, not the subtree at dir
			 */
			dflag = 1;
			flg |= DF;
			break;
		case 'E':
			/*
			 * non-standard limit on read faults
			 * 0 indicates stop after first error, values
			 * indicate a limit
			 */
			flg |= CEF;
			maxflt = strtonum(optarg, 0, INT_MAX, &errstr);
			if (errstr) {
				paxwarn(1, "Error count value: %s", errstr);
				pax_usage();
			}
			break;
		case 'f':
			/*
			 * filename where the archive is stored
			 */
			arcname = optarg;
			flg |= FF;
			break;
		case 'G':
			/*
			 * non-standard option for selecting files within an
			 * archive by group (gid or name)
			 */
			if (grp_add(optarg) < 0) {
				pax_usage();
				break;
			}
			flg |= CGF;
			break;
		case 'H':
			/*
			 * follow command line symlinks only
			 */
			Hflag = 1;
			flg |= CHF;
			break;
		case 'i':
			/*
			 * interactive file rename
			 */
			iflag = 1;
			flg |= IF;
			break;
#ifndef SMALL
		case 'J':
			/*
			 * use xz (non-standard option)
			 */
			compress_program = XZ_CMD;
			break;
		case 'j':
			/*
			 * use bzip2 (non-standard option)
			 */
			compress_program = BZIP2_CMD;
			break;
#endif
		case 'k':
			/*
			 * do not clobber files that exist
			 */
			kflag = 1;
			flg |= KF;
			break;
		case 'L':
			/*
			 * follow symlinks
			 */
			Lflag = 1;
			flg |= CLF;
			break;
		case 'l':
			/*
			 * try to link src to dest with copy (-rw)
			 */
			lflag = 1;
			flg |= LF;
			break;
		case 'M':
			/*
			 * MirOS extension: archive normaliser
			 */
			process_M(optarg, pax_usage);
			break;
		case 'n':
			/*
			 * select first match for a pattern only
			 */
			nflag = 1;
			flg |= NF;
			break;
		case 'O':
			/*
			 * Force one volume.  Non standard option.
			 */
			force_one_volume = 1;
			break;
		case 'o':
			/*
			 * pass format specific options
			 */
			flg |= OF;
			if (opt_add(optarg) < 0)
				pax_usage();
			break;
		case 'P':
			/*
			 * do NOT follow symlinks (default)
			 */
			Lflag = 0;
			flg |= CPF;
			break;
		case 'p':
			/*
			 * specify file characteristic options
			 */
			for (pt = optarg; *pt != '\0'; ++pt) {
				switch (*pt) {
				case 'a':
					/*
					 * do not preserve access time
					 */
					patime = 0;
					break;
				case 'e':
					/*
					 * preserve user id, group id, file
					 * mode, access/modification times
					 */
					pids = 1;
					pmode = 1;
					patime = 1;
					pmtime = 1;
					break;
				case 'm':
					/*
					 * do not preserve modification time
					 */
					pmtime = 0;
					break;
				case 'o':
					/*
					 * preserve uid/gid
					 */
					pids = 1;
					break;
				case 'p':
					/*
					 * preserve file mode bits
					 */
					pmode = 1;
					break;
				default:
					paxwarn(1, "Invalid -p string: %c", *pt);
					pax_usage();
					break;
				}
			}
			flg |= PF;
			break;
		case 'r':
			/*
			 * read the archive
			 */
			flg |= RF;
			break;
		case 's':
			/*
			 * file name substitution name pattern
			 */
			if (rep_add(optarg) < 0) {
				pax_usage();
				break;
			}
			flg |= SF;
			break;
		case 'T':
			/*
			 * non-standard option for selecting files within an
			 * archive by modification time range (lower,upper)
			 */
			if (trng_add(optarg) < 0) {
				pax_usage();
				break;
			}
			flg |= CTF;
			break;
		case 't':
			/*
			 * preserve access time on filesystem nodes we read
			 */
			tflag = 1;
			flg |= TF;
			break;
		case 'U':
			/*
			 * non-standard option for selecting files within an
			 * archive by user (uid or name)
			 */
			if (usr_add(optarg) < 0) {
				pax_usage();
				break;
			}
			flg |= CUF;
			break;
		case 'u':
			/*
			 * ignore those older files
			 */
			uflag = 1;
			flg |= UF;
			break;
		case 'v':
			/*
			 * verbose operation mode
			 */
			++vflag;
			flg |= VF;
			break;
		case 'w':
			/*
			 * write an archive
			 */
			flg |= WF;
			break;
		case 'X':
			/*
			 * do not pass over mount points in the filesystem
			 */
			Xflag = 1;
			flg |= CXF;
			break;
		case 'x':
			/*
			 * specify an archive format on write
			 */
			tmp.name = optarg;
			if (gather_format(&tmp, "pax", 'x'))
				pax_usage();
			flg |= XF;
			break;
		case 'Y':
			/*
			 * On extraction check file inode change time after the
			 * modification of the file name. Non standard option.
			 */
			Yflag = 1;
			flg |= CYF;
			break;
		case 'Z':
			/*
			 * On extraction check modification time after the
			 * modification of the file name. Non standard option.
			 */
			Zflag = 1;
			flg |= CZF;
			break;
		case 'z':
			/*
			 * use gzip (non-standard option)
			 */
			compress_program = GZIP_CMD;
			break;
		default:
			pax_usage();
			break;
		}
	}

	/*
	 * figure out the operation mode of pax read,write,extract,copy,append
	 * or list. check that we have not been given a bogus set of flags
	 * for the operation mode.
	 */
	if (ISLIST(flg)) {
		act = LIST;
		listf = stdout;
		bflg = flg & BDLIST;
	} else if (ISEXTRACT(flg)) {
		act = EXTRACT;
		bflg = flg & BDEXTR;
	} else if (ISARCHIVE(flg)) {
		act = ARCHIVE;
		bflg = flg & BDARCH;
	} else if (ISAPPND(flg)) {
		act = APPND;
		bflg = flg & BDARCH;
	} else if (ISCOPY(flg)) {
		act = COPY;
		bflg = flg & BDCOPY;
	} else
		pax_usage();
	if (bflg) {
		printflg(flg);
		pax_usage();
	}

	/*
	 * if we are writing (ARCHIVE) we use the default format if the user
	 * did not specify a format. when we write during an APPEND, we will
	 * adopt the format of the existing archive if none was supplied.
	 */
	if (!(flg & XF) && (act == ARCHIVE))
		frmt = &(fsub[FSUB_USTAR]);

	/*
	 * process the args as they are interpreted by the operation mode
	 */
	switch (act) {
	case LIST:
	case EXTRACT:
		for (; optind < argc; optind++)
			if (pat_add(argv[optind], NULL) < 0)
				pax_usage();
		break;
	case COPY:
		if (optind >= argc) {
			paxwarn(0, "Destination directory was not supplied");
			pax_usage();
		}
		--argc;
		dirptr = argv[argc];
		/* FALLTHROUGH */
	case ARCHIVE:
	case APPND:
		for (; optind < argc; optind++)
			if (ftree_add(argv[optind], 0) < 0)
				pax_usage();
		/*
		 * no read errors allowed on updates/append operation!
		 */
		maxflt = 0;
		break;
	}
}

/*
 * tar_options()
 *	look at the user specified flags. set globals as required and check if
 *	the user specified a legal set of flags. If not, complain and exit
 */

static void
tar_set_action(int op)
{
	if (act != ERROR && act != op)
		tar_usage();
	act = op;
}

static void
tar_options(int argc, char **argv)
{
	int c;
	int Oflag = FSUB_USTAR;
	int nincfiles = 0;
	int incfiles_max = 0;
	struct incfile {
		char *file;
		char *dir;
	};
	struct incfile *incfiles = NULL;
	FSUB tmp;
	char *bp, *cp;

	/*
	 * Set default values.
	 */
	rmleadslash = 1;

	/*
	 * process option flags
	 */
	while ((c = getoldopt(argc, argv,
	    "014578AaBb:C:cD:ef:HhI:JjLM:mNOoPpqRrSs:tuvwXxZz")) != -1) {
		switch (c) {
		case '0':
			arcname = DEV_0;
			break;
		case '1':
			arcname = DEV_1;
			break;
		case '4':
			arcname = DEV_4;
			break;
		case '5':
			arcname = DEV_5;
			break;
		case '7':
			arcname = DEV_7;
			break;
		case '8':
			arcname = DEV_8;
			break;
#ifndef SMALL
		case 'A':
			Oflag = FSUB_AR;
			mircpio_deprecated("-A flag", "-D ar");
			break;
#endif
		case 'a':
			/*
			 * use compression dependent on arcname
			 * (non-standard option, gtar extension)
			 */
			compress_program = COMPRESS_GUESS_CMD;
			break;
		case 'B':
			/*
			 * Nothing to do here, this is pax default
			 */
			break;
		case 'b':
			/*
			 * specify blocksize in 512-byte blocks
			 */
			if ((wrblksz = (int)str_offt(optarg)) <= 0) {
				paxwarn(1, "Invalid block size %s", optarg);
				tar_usage();
			}
			/* XXX - check for integer overflow */
			wrblksz *= 512;
			break;
		case 'C':
			havechd++;
			chdname = optarg;
			break;
		case 'c':
			/*
			 * create an archive
			 */
			tar_set_action(ARCHIVE);
			break;
		case 'D':
			/*
			 * specify archive format and options
			 */
			if (!(bp = strdup(optarg))) {
				paxwarn(0, "out of memory");
				exit(1);
			}
			if ((cp = strchr(bp, ',')))
				*cp++ = '\0';
			tmp.name = bp;
			if (gather_format(&tmp, "tar", 'D'))
				tar_usage();
			if (cp && opt_add(cp) < 0)
				tar_usage();
			free(bp);
			Oflag = -666; /* "frmt already set" */
			break;
		case 'e':
			/*
			 * stop after first error
			 */
			maxflt = 0;
			break;
		case 'f':
			/*
			 * filename where the archive is stored
			 */
			arcname = optarg;
			break;
		case 'H':
			/*
			 * follow command line symlinks only
			 */
			Hflag = 1;
			break;
		case 'h':
			/*
			 * follow symlinks
			 */
			Lflag = 1;
			break;
		case 'I':
			if (++nincfiles > incfiles_max) {
				size_t n = nincfiles + 3;
				struct incfile *p;

				p = reallocarray(incfiles, n,
				    sizeof(*incfiles));
				if (p == NULL) {
					paxwarn(0, "Unable to allocate space "
					    "for option list");
					exit(1);
				}
				incfiles = p;
				incfiles_max = n;
			}
			incfiles[nincfiles - 1].file = optarg;
			incfiles[nincfiles - 1].dir = chdname;
			break;
#ifndef SMALL
		case 'J':
			/*
			 * use xz (non-standard option)
			 */
			compress_program = XZ_CMD;
			break;
		case 'j':
			/*
			 * use bzip2 (non-standard option)
			 */
			compress_program = BZIP2_CMD;
			break;
#endif
		case 'L':
			/*
			 * follow symlinks
			 */
			Lflag = 1;
			break;
		case 'M':
			/*
			 * MirOS extension: archive normaliser
			 */
			process_M(optarg, tar_usage);
			break;
		case 'm':
			/*
			 * do not preserve modification time
			 */
			pmtime = 0;
			break;
#ifndef SMALL
		case 'N':
			/* numeric uid and gid only */
			anonarch |= ANON_NUMID;
			mircpio_deprecated("-N flag", "-M numid");
			break;
#endif
		case 'O':
#ifndef SMALL
			Oflag = FSUB_TAR;
#else
			Oflag = FSUB_MAX;
#endif
			to_stdout = 2;
			break;
#ifndef SMALL
		case 'o':
			Oflag = FSUB_TAR;
			tar_nodir = 1;
			break;
#endif
		case 'P':
			/*
			 * do not remove leading '/' from pathnames
			 */
			rmleadslash = 0;
			break;
		case 'p':
			/*
			 * preserve uid/gid and file mode, regardless of umask
			 */
			pmode = 1;
			pids = 1;
			break;
		case 'q':
			/*
			 * select first match for a pattern only
			 */
			nflag = 1;
			break;
#ifndef SMALL
		case 'R':
			Oflag = FSUB_SV4CPIO;
			anonarch |= ANON_INODES | ANON_HARDLINKS;
			mircpio_deprecated("-R flag", "-D sv4cpio -M set");
			break;
#endif
		case 'r':
		case 'u':
			/*
			 * append to the archive
			 */
			tar_set_action(APPND);
			break;
#ifndef SMALL
		case 'S':
			Oflag = FSUB_SV4CRC;
			anonarch |= ANON_INODES | ANON_HARDLINKS;
			mircpio_deprecated("-S flag", "-D sv4crc -M set");
			break;
#endif
		case 's':
			/*
			 * file name substitution name pattern
			 */
			if (rep_add(optarg) < 0) {
				tar_usage();
				break;
			}
			break;
		case 't':
			/*
			 * list contents of the tape
			 */
			tar_set_action(LIST);
			break;
		/* u: see r */
		case 'v':
			/*
			 * verbose operation mode
			 */
			vflag++;
			break;
		case 'w':
			/*
			 * interactive file rename
			 */
			iflag = 1;
			break;
		case 'X':
			/*
			 * do not pass over mount points in the filesystem
			 */
			Xflag = 1;
			break;
		case 'x':
			/*
			 * extract an archive, preserving mode,
			 * and mtime if possible.
			 */
			tar_set_action(EXTRACT);
			pmtime = 1;
			break;
#ifndef SMALL
		case 'Z':
			/*
			 * use compress
			 */
			compress_program = COMPRESS_CMD;
			break;
#endif
		case 'z':
			/*
			 * use gzip (non-standard option)
			 */
			compress_program = GZIP_CMD;
			break;
		default:
			tar_usage();
			break;
		}
	}
	argc -= optind;
	argv += optind;

	/* tar requires an action. */
	if (act == ERROR)
		tar_usage();

	if ((arcname == NULL) || (*arcname == '\0')) {
		arcname = getenv("TAPE");
		if ((arcname == NULL) || (*arcname == '\0'))
			arcname = _PATH_DEFTAPE;
	}
	if ((arcname[0] == '-') && (arcname[1] == '\0'))
		arcname = NULL;

	/*
	 * Traditional tar behaviour: list-like output goes to stdout unless
	 * writing the archive there.  (pax uses stderr unless in list mode)
	 */
        if (act == LIST || act == EXTRACT || arcname != NULL)
		listf = stdout;

	/* Traditional tar behaviour (pax wants to read file list from stdin) */
	if ((act == ARCHIVE || act == APPND) && argc == 0 && nincfiles == 0)
		exit(0);

	/*
	 * process the args as they are interpreted by the operation mode
	 */
	switch (act) {
	case EXTRACT:
		if (to_stdout == 2)
			to_stdout = 1;
		/* FALLTHROUGH */
	case LIST:
	default:
		{
			int sawpat = 0;
			char *file, *dir = NULL;

			while (nincfiles || *argv != NULL) {
				/*
				 * If we queued up any include files,
				 * pull them in now.  Otherwise, check
				 * for -I and -C positional flags.
				 * Anything else must be a file to
				 * extract.
				 */
				if (nincfiles) {
					file = incfiles->file;
					dir = incfiles->dir;
					incfiles++;
					nincfiles--;
				} else if (strcmp(*argv, "-I") == 0) {
					if (*++argv == NULL)
						break;
					file = *argv++;
					dir = chdname;
				} else
					file = NULL;
				if (file != NULL) {
					int fd;
					char *str;

					if (strcmp(file, "-") == 0)
						fd = STDIN_FILENO;
					else if ((fd = binopen2(0, file, O_RDONLY)) == -1) {
						syswarn(1, errno,
						    "Unable to open %s", file);
						tar_usage();
					}
					while ((str = fdgetline(fd)) != NULL) {
						if (pat_add(str, dir) < 0)
							tar_usage();
						sawpat = 1;
					}
					if (fd != STDIN_FILENO)
						close(fd);
					if (fdgetline_err) {
						paxwarn(1,
						    "Unable to read from %s",
						    strcmp(file, "-") ? file :
						    "stdin");
						tar_usage();
					}
				} else if (strcmp(*argv, "-C") == 0) {
					if (*++argv == NULL)
						break;
					chdname = *argv++;
					havechd++;
				} else if (pat_add(*argv++, chdname) < 0)
					tar_usage();
				else
					sawpat = 1;
			}
			/*
			 * if patterns were added, we are doing	chdir()
			 * on a file-by-file basis, else, just one
			 * global chdir (if any) after opening input.
			 */
			if (sawpat > 0)
				chdname = NULL;
		}
		break;
	case ARCHIVE:
	case APPND:
		if (Oflag == FSUB_MAX)
			tar_usage();
		else if (Oflag != -666)
			frmt = &(fsub[Oflag]);

		if (chdname != NULL) {
			/* initial chdir() */
			if (ftree_add(chdname, 1) < 0)
				tar_usage();
		}

		while (nincfiles || *argv != NULL) {
			char *file, *dir = NULL;

			/*
			 * If we queued up any include files, pull them in
			 * now.  Otherwise, check for -I and -C positional
			 * flags.  Anything else must be a file to include
			 * in the archive.
			 */
			if (nincfiles) {
				file = incfiles->file;
				dir = incfiles->dir;
				incfiles++;
				nincfiles--;
			} else if (strcmp(*argv, "-I") == 0) {
				if (*++argv == NULL)
					break;
				file = *argv++;
				dir = NULL;
			} else
				file = NULL;
			if (file != NULL) {
				int fd;
				char *str;

				/* Set directory if needed */
				if (dir) {
					if (ftree_add(dir, 1) < 0)
						tar_usage();
				}

				if (strcmp(file, "-") == 0)
					fd = STDIN_FILENO;
				else if ((fd = binopen2(0, file, O_RDONLY)) == -1) {
					syswarn(1, errno, "Unable to open %s",
					    file);
					tar_usage();
				}
				while ((str = fdgetline(fd)) != NULL) {
					if (ftree_add(str, 0) < 0)
						tar_usage();
				}
				if (fd != STDIN_FILENO)
					close(fd);
				if (fdgetline_err) {
					paxwarn(1,
					    "Unable to read from %s",
					    strcmp(file, "-") ? file : "stdin");
					tar_usage();
				}
			} else if (strcmp(*argv, "-C") == 0) {
				if (*++argv == NULL)
					break;
				if (ftree_add(*argv++, 1) < 0)
					tar_usage();
				havechd++;
			} else if (ftree_add(*argv++, 0) < 0)
				tar_usage();
		}
		/*
		 * no read errors allowed on updates/append operation!
		 */
		maxflt = 0;
		break;
	}
	if (to_stdout != 1)
		to_stdout = 0;
}

static int
mkpath(char *path)
{
	struct stat sb;
	char *slash;
	int done = 0;

	slash = path;

	while (!done) {
		slash += strspn(slash, "/");
		slash += strcspn(slash, "/");

		done = (*slash == '\0');
		*slash = '\0';

		if (stat(path, &sb)) {
			if (errno != ENOENT || mkdir(path, 0777)) {
				paxwarn(1, "%s", path);
				return (-1);
			}
		} else if (!S_ISDIR(sb.st_mode)) {
			syswarn(1, ENOTDIR, "%s", path);
			return (-1);
		}

		if (!done)
			*slash = '/';
	}

	return (0);
}

/*
 * cpio_options()
 *	look at the user specified flags. set globals as required and check if
 *	the user specified a legal set of flags. If not, complain and exit
 */

static void
cpio_set_action(int op)
{
	if ((act == APPND && op == ARCHIVE) || (act == ARCHIVE && op == APPND))
		act = APPND;
	else if ((act == LIST && op == EXTRACT) || (act == EXTRACT && op == LIST))
		act = LIST;
	else if (act != ERROR && act != op)
		cpio_usage();
	else
		act = op;
}

static void
cpio_options(int argc, char **argv)
{
	const char *errstr;
	int c, list_only = 0;
	char *str;
	int fd;
	const char *optstr;
	FSUB tmp;

	kflag = 1;
	pids = 1;
	pmode = 1;
	pmtime = 0;
	arcname = NULL;
	dflag = 1;
	nodirs = 1;
	optstr = "iop";
	opterr = 0;
	while ((c = getopt(argc, argv, optstr)) != -1) {
		switch (c) {
		case '0':
			/*
			 * Use \0 as pathname terminator.
			 * (For use with the -print0 option of find(1).)
			 */
			zeroflag = 1;
			break;
#ifndef SMALL
		case '6':
			/*
			 * process Version 6 cpio format
			 */
			frmt = &(fsub[FSUB_BCPIO]);
			break;
#endif
		case 'A':
			/*
			 * append mode
			 */
			cpio_set_action(APPND);
			break;
		case 'a':
			/*
			 * preserve access time on files read
			 */
			tflag = 1;
			break;
		case 'B':
			/*
			 * Use 5120 byte block size
			 */
			wrblksz = 5120;
			break;
		case 'b':
			/*
			 * swap bytes and half-words when reading data
			 */
			break;
		case 'C':
			/*
			 * set block size in bytes
			 */
			wrblksz = strtonum(optarg, 0, INT_MAX, &errstr);
			if (errstr) {
				paxwarn(1, "Invalid block size %s: %s",
				    optarg, errstr);
				pax_usage();
			}
			break;
		case 'c':
			/*
			 * ASCII cpio header
			 */
			frmt = &(fsub[FSUB_CPIO]);
			break;
		case 'd':
			/*
			 * create directories as needed
			 */
			nodirs = 0;
			break;
		case 'E':
			/*
			 * file with patterns to extract or list
			 */
			if ((fd = binopen2(0, optarg, O_RDONLY)) == -1) {
				syswarn(1, errno, "Unable to open %s",
				    optarg);
				cpio_usage();
			}
			while ((str = fdgetline(fd)) != NULL) {
				pat_add(str, NULL);
			}
			close(fd);
			if (fdgetline_err) {
				paxwarn(1,
				    "Unable to read from %s", optarg);
				cpio_usage();
			}
			break;
		case 'F':
		case 'I':
		case 'O':
			/*
			 * filename where the archive is stored
			 */
			if ((optarg[0] == '-') && (optarg[1]== '\0')) {
				/*
				 * treat a - as stdin
				 */
				arcname = NULL;
				break;
			}
			arcname = optarg;
			break;
		case 'f':
			/*
			 * invert meaning of pattern list
			 */
			cflag = 1;
			break;
		case 'H':
			/*
			 * specify an archive format on write
			 */
			if (!strcmp(optarg, "bin")) {
				tmp.name = "bcpio";
			} else if (!strcmp(optarg, "crc")) {
				tmp.name = "sv4crc";
			} else if (!strcmp(optarg, "newc")) {
				tmp.name = "sv4cpio";
			} else if (!strcmp(optarg, "odc")) {
				tmp.name = "cpio";
			} else {
				tmp.name = optarg;
			}
			if (gather_format(&tmp, "cpio", 'H'))
				cpio_usage();
			break;
		/* I: see F */
		case 'i':
			/*
			 * restore an archive
			 */
			cpio_set_action(EXTRACT);
			break;
#ifndef SMALL
		case 'J':
			/*
			 * use xz (non-standard option)
			 */
			compress_program = XZ_CMD;
			break;
		case 'j':
			/*
			 * use bzip2 (non-standard option)
			 */
			compress_program = BZIP2_CMD;
			break;
#endif
		case 'k':
			break;
		case 'L':
			/*
			 * follow symbolic links
			 */
			Lflag = 1;
			break;
		case 'l':
			/*
			 * use links instead of copies when possible
			 */
			lflag = 1;
			break;
		case 'M':
			/*
			 * MirOS extension: archive normaliser
			 */
			process_M(optarg, cpio_usage);
			break;
		case 'm':
			/*
			 * preserve modification time
			 */
			pmtime = 1;
			break;
		/* O: see F */
		case 'o':
			/*
			 * create an archive
			 */
			cpio_set_action(ARCHIVE);
			frmt = &(fsub[FSUB_SV4CRC]);
			break;
		case 'p':
			/*
			 * copy-pass mode
			 */
			cpio_set_action(COPY);
			break;
		case 'r':
			/*
			 * interactively rename files
			 */
			iflag = 1;
			break;
		case 'S':
			/*
			 * swap halfwords after reading data
			 */
			break;
		case 's':
			/*
			 * swap bytes after reading data
			 */
			break;
		case 't':
			/*
			 * list contents of archive
			 */
			list_only = 1;
			break;
		case 'u':
			/*
			 * replace newer files
			 */
			kflag = 0;
			break;
		case 'V':
			/*
			 * print a dot for each file processed
			 */
			Vflag++;
			break;
		case 'v':
			/*
			 * verbose operation mode
			 */
			++vflag;
			break;
#ifndef SMALL
		case 'Z':
			/*
			 * use compress (non-standard option)
			 */
			compress_program = COMPRESS_CMD;
			break;
#endif
		case 'z':
			/*
			 * use gzip (non-standard option)
			 */
			compress_program = GZIP_CMD;
			break;
		case '?':
		default:
			if (opterr == 0) {
				paxwarn(1, "need -i or -o or -p option first");
			}
			cpio_usage();
			break;
		}
		if (opterr == 0) {
			optstr = "06AaBbC:cdE:F:fH:I:iJjkLlM:mO:oprSstuVvZz";
			opterr = 1;
		}
	}
	argc -= optind;
	argv += optind;

	/*
	 * process the args as they are interpreted by the operation mode
	 */
	switch (act) {
	case EXTRACT:
		if (list_only) {
			act = LIST;

			/*
			 * cpio is like pax: list to stderr
			 * unless in list mode
			 */
			listf = stdout;
		}
		while (*argv != NULL)
			if (pat_add(*argv++, NULL) < 0)
				cpio_usage();
		break;
	case COPY:
		if (*argv == NULL) {
			paxwarn(0, "Destination directory was not supplied");
			cpio_usage();
		}
		dirptr = *argv;
		if (mkpath(dirptr) < 0)
			cpio_usage();
		--argc;
		++argv;
		/* FALLTHROUGH */
	case ARCHIVE:
	case APPND:
		if (*argv != NULL)
			cpio_usage();
		/*
		 * no read errors allowed on updates/append operation!
		 */
		maxflt = 0;
		while ((str = fdgetline(STDIN_FILENO)) != NULL) {
			ftree_add(str, 0);
		}
		if (fdgetline_err) {
			paxwarn(1, "Unable to read from %s",
			    "stdin");
			cpio_usage();
		}
		break;
	default:
		cpio_usage();
		break;
	}
}

/*
 * printflg()
 *	print out those invalid flag sets found to the user
 */

static void
printflg(unsigned int flg)
{
	int nxt;
	int pos = 0;

	(void)fprintf(stderr,"%s: Invalid combination of options:", argv0);
	while ((nxt = ffs(flg)) != 0) {
		flg >>= nxt;
		pos += nxt;
		(void)fprintf(stderr, " -%c", flgch[pos-1]);
	}
	(void)putc('\n', stderr);
}

/*
 * c_frmt()
 *	comparison routine used by bsearch to find the format specified
 *	by the user
 */

static int
c_frmt(const void *a, const void *b)
{
	if (!((const FSUB *)b)->name)
		return (-1);
	return(strcmp(((const FSUB *)a)->name, ((const FSUB *)b)->name));
}

/*
 * opt_next()
 *	called by format specific options routines to get each format specific
 *	flag and value specified with -o
 * Return:
 *	pointer to next OPLIST entry or NULL (end of list).
 */

OPLIST *
opt_next(void)
{
	OPLIST *opt;

	if ((opt = ophead) != NULL)
		ophead = ophead->fow;
	return(opt);
}

/*
 * bad_opt()
 *	generic routine used to complain about a format specific options
 *	when the format does not support options.
 */

int
bad_opt(void)
{
	OPLIST *opt;

	if (ophead == NULL)
		return(0);
	/*
	 * print all we were given
	 */
	paxwarn(1,"These format options are not supported");
	while ((opt = opt_next()) != NULL)
		(void)fprintf(stderr, "\t%s = %s\n", opt->name, opt->value);
	pax_usage();
	return(0);
}

/*
 * opt_add()
 *	breaks the value supplied to -o into a option name and value.
 *	options are given to -o in the form -o name=value,name=value
 *	or to -D in the form format,name=value[,name=value ...]
 *	multiple -o may be specified.
 * Return:
 *	0 if format in name=value format, -1 if -o is passed junk
 */

int
opt_add(const char *str)
{
	OPLIST *opt;
	char *frpt;
	char *pt;
	char *endpt;
	char *dstr;

	if ((str == NULL) || (*str == '\0')) {
		paxwarn(0, "Invalid option name");
		return(-1);
	}
	if ((dstr = strdup(str)) == NULL) {
		paxwarn(0, "Unable to allocate space for option list");
		return(-1);
	}
	frpt = endpt = dstr;

	/*
	 * break into name and values pieces and stuff each one into a
	 * OPLIST structure. When we know the format, the format specific
	 * option function will go through this list
	 */
	while ((frpt != NULL) && (*frpt != '\0')) {
		if ((endpt = strchr(frpt, ',')) != NULL)
			*endpt = '\0';
		if ((pt = strchr(frpt, '=')) == NULL) {
			paxwarn(0, "Invalid options format");
			free(dstr);
			return(-1);
		}
		if ((opt = malloc(sizeof(OPLIST))) == NULL) {
			paxwarn(0, "Unable to allocate space for option list");
			free(dstr);
			return(-1);
		}
		/* parts of string going onto the OPLIST */
		dstr = NULL;
		*pt++ = '\0';
		opt->name = frpt;
		opt->value = pt;
		opt->fow = NULL;
		if (endpt != NULL)
			frpt = endpt + 1;
		else
			frpt = NULL;
		if (ophead == NULL) {
			optail = ophead = opt;
			continue;
		}
		optail->fow = opt;
		optail = opt;
	}
	free(dstr);
	return(0);
}

/*
 * str_offt()
 *	Convert an expression of the following forms to an off_t > 0.
 *	1) A positive decimal number.
 *	2) A positive decimal number followed by a b (mult by 512).
 *	3) A positive decimal number followed by a k (mult by 1024).
 *	4) A positive decimal number followed by a m (mult by 512).
 *	5) A positive decimal number followed by a w (mult by sizeof int)
 *	6) Two or more positive decimal numbers (with/without k,b or w).
 *	   separated by x (also * for backwards compatibility), specifying
 *	   the product of the indicated values.
 * Return:
 *	0 for an error, a positive value o.w.
 */

#if HAVE_OFFT_LONG
#define OT_MAX	LONG_MAX
#define strtoot	strtol
#else
#define OT_MAX	LLONG_MAX
#define strtoot	strtoll
#endif

static off_t
str_offt(char *val)
{
	char *expr;
	off_t num, t;

	num = strtoot(val, &expr, 0);
	if ((num == OT_MAX) || (num <= 0) || (expr == val))
		return (0);

	switch (*expr) {
	case 'b':
		t = num;
		num *= 512;
		if (t > num)
			return (0);
		++expr;
		break;
	case 'k':
		t = num;
		num *= 1024;
		if (t > num)
			return (0);
		++expr;
		break;
	case 'm':
		t = num;
		num *= 1048576;
		if (t > num)
			return (0);
		++expr;
		break;
	case 'w':
		t = num;
		num *= sizeof(int);
		if (t > num)
			return (0);
		++expr;
		break;
	}

	switch (*expr) {
	case '\0':
		break;
	case '*':
	case 'x':
		t = num;
		num *= str_offt(expr + 1);
		if (t > num)
			return(0);
		break;
	default:
		return(0);
	}
	return (num);
}

#ifndef SMALL
/*
 * no_op()
 *	for those option functions where the archive format has nothing to do.
 * Return:
 *	0
 */

static int
no_op(void)
{
	return (0);
}

static int
no_op_i(int is_app MKSH_A_UNUSED)
{
	return (0);
}
#endif

/*
 * pax_usage()
 *	print the usage summary to the user
 */

void
pax_usage(void)
{
	(void)fputs(
	    "usage: pax [-0cdJjnOvz] [-E limit] [-f archive] [-G group] [-s replstr]\n"
	    "           [-T range] [-U user] [pattern ...]\n"
	    "       pax -r [-0cDdiJjknOuvYZz] [-E limit] [-f archive] [-G group] [-M flag]\n"
	    "           [-o options] [-p string] [-s replstr] [-T range] [-U user]\n"
	    "           [pattern ...]\n"
	    "       pax -w [-0adHiJjLOPtuvXz] [-B bytes] [-b blocksize] [-f archive]\n"
	    "           [-G group] [-M flag] [-o options] [-s replstr] [-T range]\n"
	    "           [-U user] [-x format] [file ...]\n"
	    "       pax -rw [-0DdHikLlnOPtuvXYZ] [-G group] [-p string] [-s replstr]\n"
	    "           [-T range] [-U user] [file ...] directory\n",
	    stderr);
	exit(1);
}

/*
 * tar_usage()
 *	print the usage summary to the user
 */

void
tar_usage(void)
{
	(void)fputs(
	    "usage: tar {crtux}[014578AabefHhJjLmNOoPpqRSsvwXZz]\n"
	    "           [blocking-factor | archive | replstr] [-C directory] [-I file]\n"
	    "           [file ...]\n"
	    "       tar {-crtux} [-014578AaeHhJjLmNOoPpqRSvwXZz] [-b blocking-factor]\n"
	    "           [-C directory] [-D format-options] [-f archive] [-I file]\n"
	    "           [-M flag] [-s replstr] [file ...]\n",
	    stderr);
	exit(1);
}

/*
 * cpio_usage()
 *	print the usage summary to the user
 */

void
cpio_usage(void)
{
	(void)fputs(
	    "usage: cpio -o [-0AaBcJjLVvZz] [-C bytes] [-F archive] [-H format]\n"
	    "               [-M flag] [-O archive] <name-list [>archive]\n"
	    "       cpio -i [-06BbcdfJjmrSstuVvZz] [-C bytes] [-E file] [-F archive]\n"
	    "               [-H format] [-I archive] [-M flag] [pattern ...] [<archive]\n"
	    "       cpio -p [-0adLlmuVv] destination-directory <name-list\n",
	    stderr);
	exit(1);
}

void
anonarch_init(void)
{
	if (anonarch & ANON_VERBOSE) {
		anonarch &= ~ANON_VERBOSE;
		paxwarn(0, "debug: -M 0x%08X -x %s", anonarch, frmt->name);
	}
}

static void
process_M(const char *arg, void (*call_usage)(void))
{
	int j, k = 0;

	if ((arg[0] >= '0') && (arg[0] <= '9')) {
#if HAVE_STRTONUM
		const char *s;
		int64_t i = strtonum(arg, 0,
		    ANON_MAXVAL, &s);
		if (s)
			errx(1, "%s M value: %s", s,
			    arg);
#else
		char *ep;
		long long i = strtoll(arg, &ep, 0);
		if ((ep == arg) || (*ep != '\0') ||
		    (i < 0) || (i > ANON_MAXVAL))
			errx(1, "impossible M value:"
			    " %s", arg);
#endif
		anonarch = i;
		return;
	}

	if (!strncmp(arg, "no-", 3)) {
		j = 0;
		arg += 3;
	} else
		j = 1;
	if (!strncmp(arg, "uid", 3) ||
	    !strncmp(arg, "gid", 3)) {
		k = ANON_UIDGID;
	} else if (!strncmp(arg, "ino", 3)) {
		k = ANON_INODES;
	} else if (!strncmp(arg, "mtim", 4)) {
		k = ANON_MTIME;
	} else if (!strncmp(arg, "link", 4)) {
		k = ANON_HARDLINKS;
	} else if (!strncmp(arg, "norm", 4)) {
		k = ANON_UIDGID | ANON_INODES | ANON_NUMID |
		    ANON_MTIME | ANON_HARDLINKS;
	} else if (!strncmp(arg, "root", 4)) {
		k = ANON_UIDGID | ANON_INODES | ANON_NUMID;
	} else if (!strncmp(arg, "dist", 4)) {
		k = ANON_UIDGID | ANON_INODES | ANON_NUMID |
		    ANON_HARDLINKS;
	} else if (!strncmp(arg, "set", 3)) {
		k = ANON_INODES | ANON_HARDLINKS;
	} else if (!strncmp(arg, "v", 1)) {
		k = ANON_VERBOSE;
	} else if (!strncmp(arg, "debug", 5)) {
		k = ANON_DEBUG;
	} else if (!strncmp(arg, "lncp", 4)) {
		k = ANON_LNCP;
	} else if (!strncmp(arg, "numid", 5)) {
		k = ANON_NUMID;
	} else if (!strncmp(arg, "gslash", 6)) {
		k = ANON_DIRSLASH;
	} else
		call_usage();
	if (j)
		anonarch |= k;
	else
		anonarch &= ~k;
}

void
guess_compress_program(int wr __attribute__((__unused__)))
{
	const char *ccp;

	if (compress_program != COMPRESS_GUESS_CMD)
		return;

	if (arcname == NULL || (ccp = strrchr(arcname, '.')) == NULL) {
		compress_program = NULL;
		return;
	}
	++ccp;

	/* guess standard format gzip */
	if (!strcmp(ccp, "gz") ||
	    !strcmp(ccp, "tgz") ||
	    !strcmp(ccp, "cgz") ||
	    !strcmp(ccp, "ngz") ||
	    !strcmp(ccp, "taz")) {
		compress_program = GZIP_CMD;
		return;
	}

#ifndef SMALL
	/* guess extended format xz */
	if (!strcmp(ccp, "xz") ||
	    !strcmp(ccp, "txz") ||
	    !strcmp(ccp, "cxz") ||
	    !strcmp(ccp, "nxz")) {
		compress_program = XZ_CMD;
		return;
	}

	/* guess extended format bzip2 (not bzip) */
	if (!strcmp(ccp, "bz2") ||
	    !strcmp(ccp, "tbz") ||
	    !strcmp(ccp, "tz2") ||
	    !strcmp(ccp, "tbz2") ||
	    !strcmp(ccp, "cbz") ||
	    !strcmp(ccp, "nbz")) {
		compress_program = BZIP2_CMD;
		return;
	}

	/* guess standard format Unix compress */
	if (!strcmp(ccp, "Z") ||
	    !strcmp(ccp, "mcz") ||
	    !strcmp(ccp, "taZ")) {
		compress_program = COMPRESS_CMD;
		return;
	}

	/* guess extended format lzma (using xz for decompression) */
	if (!strcmp(ccp, "lzma")) {
		compress_program = wr ? LZMA_WRCMD : XZ_CMD;
		return;
	}

	/* guess extended format lzop */
	if (!strcmp(ccp, "lzo")) {
		compress_program = LZOP_CMD;
		return;
	}
#endif

	/* no sugar */
	compress_program = NULL;
}

#ifndef SMALL
static int
compress_id(char *blk, int size)
{
	if (size >= 2 && blk[0] == '\037' && blk[1] == '\235') {
		paxwarn(0, "input compressed with %s; use the -%c option"
		    " to decompress it", "compress", 'Z');
		exit(1);
	}
	return (-1);
}

static int
gzip_id(char *blk, int size)
{
	if (size >= 2 && blk[0] == '\037' && blk[1] == '\213') {
		paxwarn(0, "input compressed with %s; use the -%c option"
		    " to decompress it", "gzip", 'z');
		exit(1);
	}
	return (-1);
}

static int
bzip2_id(char *blk, int size)
{
	if (size >= 3 && blk[0] == 'B' && blk[1] == 'Z' && blk[2] == 'h') {
		paxwarn(0, "input compressed with %s; use the -%c option"
		    " to decompress it", "bzip2", 'j');
		exit(1);
	}
	return (-1);
}

static int
xz_id(char *blk, int size)
{
	if (size >= 6 && memcmp(blk, "\xFD\x37\x7A\x58\x5A", 6) == 0) {
		paxwarn(0, "input compressed with %s; use the -%c option"
		    " to decompress it", "xz", 'J');
		exit(1);
	}
	return (-1);
}

void
mircpio_deprecated(const char *what, const char *with)
{
	paxwarn(0, "the old MirCPIO %s is deprecated and will be removed soon; use %s instead",
	    what, with);
}
#endif /* !SMALL */
