/*
 * io.c --- routines for dealing with input and output and records
 */

/* 
 * Copyright (C) 1986, 1988, 1989, 1991-2011 the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 * 
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
/* find sockaddr_storage */

#if defined PLAN9
#define sockaddr_storage sockaddr
#endif

/* For OSF/1 to get struct sockaddr_storage */
#if defined(__osf__) && !defined(_OSF_SOURCE)
#define _OSF_SOURCE
#endif

#include "awk.h"

#ifdef HAVE_SYS_PARAM_H
#undef RE_DUP_MAX	/* avoid spurious conflict w/regex.h */
#include <sys/param.h>
#endif /* HAVE_SYS_PARAM_H */

#ifndef O_ACCMODE
#define O_ACCMODE	(O_RDONLY|O_WRONLY|O_RDWR)
#endif

#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif
#ifdef HAVE_STROPTS_H
#include <stropts.h>
#endif

#ifdef HAVE_SOCKETS

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#else
#include <socket.h>
#endif /* HAVE_SYS_SOCKET_H */

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#else /* ! HAVE_NETINET_IN_H */
#include <in.h>
#endif /* HAVE_NETINET_IN_H */

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif /* HAVE_NETDB_H */

#ifndef HAVE_GETADDRINFO
#include "missing_d/getaddrinfo.h"
#endif

#ifndef AI_ADDRCONFIG	/* This is a recent symbol, not everyone has it */
#define AI_ADDRCONFIG 0
#endif /* AI_ADDRCONFIG */

#ifndef HAVE_SOCKADDR_STORAGE
#define sockaddr_storage sockaddr	/* for older systems */
#endif /* HAVE_SOCKADDR_STORAGE */

#endif /* HAVE_SOCKETS */

#ifndef AF_UNSPEC
#define AF_UNSPEC 0
#endif
#ifndef AF_INET
#define AF_INET 2
#endif
#ifndef AF_INET6
#define AF_INET6 10
#endif

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifdef __EMX__
#include <process.h>
#endif

#ifndef ENFILE
#define ENFILE EMFILE
#endif

#ifdef HAVE_SOCKETS

#ifndef SHUT_RD
#define SHUT_RD		0
#endif

#ifndef SHUT_WR
#define SHUT_WR		1
#endif

#ifndef SHUT_RDWR
#define SHUT_RDWR	2
#endif

#endif /* HAVE_SOCKETS */

#if defined(GAWK_AIX)
#undef TANDEM	/* AIX defines this in one of its header files */
#endif

#if defined(__DJGPP__) || defined(__MINGW32__)
#define PIPES_SIMULATED
#endif

typedef enum { CLOSE_ALL, CLOSE_TO, CLOSE_FROM } two_way_close_type;

/* Several macros make the code a bit clearer:                              */
/*                                                                          */
/*                                                                          */
/* <defines and enums>=                                                     */
#define at_eof(iop)     (((iop)->flag & IOP_AT_EOF) != 0)
#define has_no_data(iop)        ((iop)->dataend == NULL)
#define no_data_left(iop)	((iop)->off >= (iop)->dataend)
/* The key point to the design is to split out the code that searches through */
/* a buffer looking for the record and the terminator into separate routines, */
/* with a higher-level routine doing the reading of data and buffer management. */
/* This makes the code easier to manage; the buffering code is the same independent */
/* of how we find a record.  Communication is via the return value:         */
/*                                                                          */
/*                                                                          */
/* <defines and enums>=                                                     */
typedef enum recvalues {
        REC_OK,         /* record and terminator found, recmatch struct filled in */
        NOTERM,         /* no terminator found, give me more input data */
        TERMATEND,      /* found terminator at end of buffer */
        TERMNEAREND     /* found terminator close to end of buffer, for RE might be bigger */
} RECVALUE;
/* Between calls to a scanning routine, the state is stored in              */
/* an [[enum scanstate]] variable.  Not all states apply to all             */
/* variants, but the higher code doesn't really care.                       */
/*                                                                          */
/*                                                                          */
/* <defines and enums>=                                                     */
typedef enum scanstate {
        NOSTATE,        /* scanning not started yet (all) */
        INLEADER,       /* skipping leading data (RS = "") */
        INDATA,         /* in body of record (all) */
        INTERM          /* scanning terminator (RS = "", RS = regexp) */
} SCANSTATE;
/* When a record is seen ([[REC_OK]] or [[TERMATEND]]), the following       */
/* structure is filled in.                                                  */
/*                                                                          */
/*                                                                          */
/* <recmatch>=                                                              */
struct recmatch {
        char *start;    /* record start */
        size_t len;     /* length of record */
        char *rt_start; /* start of terminator */
        size_t rt_len;  /* length of terminator */
};


static int iop_close(IOBUF *iop);
struct redirect *redirect(NODE *redir_exp, int redirtype, int *errflg);
static void close_one(void);
static int close_redir(struct redirect *rp, int exitwarn, two_way_close_type how);
#ifndef PIPES_SIMULATED
static int wait_any(int interesting);
#endif
static IOBUF *gawk_popen(const char *cmd, struct redirect *rp);
static IOBUF *iop_alloc(int fd, const char *name, IOBUF *buf, int do_openhooks);
static int gawk_pclose(struct redirect *rp);
static int str2mode(const char *mode);
static int two_way_open(const char *str, struct redirect *rp);
static int pty_vs_pipe(const char *command);
static void find_open_hook(IOBUF *iop);

static RECVALUE rs1scan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state);
static RECVALUE rsnullscan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state);
static RECVALUE rsrescan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state);

static RECVALUE (*matchrec)(IOBUF *iop, struct recmatch *recm, SCANSTATE *state) = rs1scan;

static int get_a_record(char **out, IOBUF *iop, int *errcode);

static void free_rp(struct redirect *rp);
static int inetfile(const char *str, int *length, int *family);

#if defined(HAVE_POPEN_H)
#include "popen.h"
#endif

static struct redirect *red_head = NULL;
static NODE *RS;
static Regexp *RS_re_yes_case;
static Regexp *RS_re_no_case;
static Regexp *RS_regexp;

int RS_is_null;
int has_endfile = FALSE;

extern int output_is_tty;
extern NODE *ARGC_node;
extern NODE *ARGV_node;
extern NODE *ARGIND_node;
extern NODE *ERRNO_node;
extern NODE **fields_arr;

#if defined(__DJGPP__) || defined(__MINGW32__) || defined(__EMX__) || defined(__CYGWIN__)
/* binmode --- convert BINMODE to string for fopen */

static const char *
binmode(const char *mode)
{
	switch (mode[0]) {
	case 'r':
		if ((BINMODE & 1) != 0)
			mode = "rb";
		break;
	case 'w':
	case 'a':
		if ((BINMODE & 2) != 0)
			mode = (mode[0] == 'w' ? "wb" : "ab");
		break;
	}
	return mode;
}
#else
#define binmode(mode)	(mode)
#endif

#ifdef VMS
/* File pointers have an extra level of indirection, and there are cases where
   `stdin' can be null.  That can crash gawk if fileno() is used as-is.  */
static int vmsrtl_fileno(FILE *);
static int vmsrtl_fileno(fp) FILE *fp; { return fileno(fp); }
#undef fileno
#define fileno(FP) (((FP) && *(FP)) ? vmsrtl_fileno(FP) : -1)
#endif	/* VMS */

void
after_beginfile(IOBUF **curfile)
{
	IOBUF *iop;

	iop = *curfile;
	assert(iop != NULL);
#if 0
	if (iop == NULL)
		return;
#endif

	if (iop->fd == INVALID_HANDLE) {
		const char *fname;
		int errcode;

		fname = iop->name;
		errcode = iop->errcode; 
		iop->errcode = 0;
		errno = 0;
		update_ERRNO();
		iop_close(iop);
		*curfile = NULL;
		if (errcode == EISDIR && ! do_traditional) {
			warning(_("command line argument `%s' is a directory: skipped"), fname);
			return;		/* read next file */
		}
		fatal(_("cannot open file `%s' for reading (%s)"),
				fname, strerror(errcode));
	}

	/*
	 * Open hooks could have been changed by BEGINFILE,
	 * so delay check until now.
	 */

	find_open_hook(iop);
}

/* nextfile --- move to the next input data file */

int
nextfile(IOBUF **curfile, int skipping)
{
	static long i = 1;
	static int files = FALSE;
	NODE *arg, *tmp;
	static IOBUF mybuf;
	const char *fname;
	int fd = INVALID_HANDLE;
	int errcode;
	IOBUF *iop = *curfile;

	if (skipping) {			/* for 'nextfile' call */
		if (iop != NULL)
			(void) iop_close(iop);
		*curfile = NULL;
		return 0;	/* return value not used */
	}

	if (iop != NULL) {
		if (at_eof(iop)) {
			assert(iop->fd != INVALID_HANDLE);
			(void) iop_close(iop);
			*curfile = NULL;
			return 1;	/* run endfile block */
		} else				
			return 0;
	}

	for (; i < (long) (ARGC_node->lnode->numbr); i++) {
		tmp = make_number((AWKNUM) i);
		(void) force_string(tmp);
		arg = in_array(ARGV_node, tmp);
		unref(tmp);
		if (arg == NULL || arg->stlen == 0)
			continue;
		arg = force_string(arg);
		arg->stptr[arg->stlen] = '\0';
		if (! do_traditional) {
			unref(ARGIND_node->var_value);
			ARGIND_node->var_value = make_number((AWKNUM) i);
		}

		if (! arg_assign(arg->stptr, FALSE)) {
			files = TRUE;
			fname = arg->stptr;
			errno = 0;
			fd = devopen(fname, binmode("r"));
			errcode = errno;
			if (! do_traditional)
				update_ERRNO();

			/* This is a kludge.  */
			unref(FILENAME_node->var_value);
			FILENAME_node->var_value = dupnode(arg);
			FNR = 0;
			iop = *curfile = iop_alloc(fd, fname, &mybuf, FALSE);
			if (fd == INVALID_HANDLE)
				iop->errcode = errcode;
			else
				iop->errcode = 0;
			iop->flag |= IOP_NOFREE_OBJ;
			return ++i;	/* run beginfile block */
		}
	}

	if (files == FALSE) {
		files = TRUE;
		/* no args. -- use stdin */
		/* FNR is init'ed to 0 */
		errno = 0;
		if (! do_traditional)
			update_ERRNO();
		unref(FILENAME_node->var_value);
		FILENAME_node->var_value = make_string("-", 1);
		FILENAME_node->var_value->flags |= MAYBE_NUM; /* be pedantic */
		fname = "-";
		iop = *curfile = iop_alloc(fileno(stdin), fname, &mybuf, FALSE);
		iop->flag |= IOP_NOFREE_OBJ;
		if (iop->fd == INVALID_HANDLE) {
			errcode = errno;
			errno = 0;
			update_ERRNO();
			(void) iop_close(iop);
			*curfile = NULL;
			fatal(_("cannot open file `%s' for reading (%s)"),
					fname, strerror(errcode));
		}
		return ++i;	/* run beginfile block */
	}

	return -1;	/* end of input, run end block or Op_atexit */
}

/* set_FNR --- update internal FNR from awk variable */

void
set_FNR()
{
	FNR = (long) FNR_node->var_value->numbr;
}

/* set_NR --- update internal NR from awk variable */

void
set_NR()
{
	NR = (long) NR_node->var_value->numbr;
}

/* inrec --- This reads in a record from the input file */

int
inrec(IOBUF *iop)
{
	char *begin;
	int cnt;
	int retval = 0;
	int errcode = 0;

	if (at_eof(iop) && no_data_left(iop))
		cnt = EOF;
	else if ((iop->flag & IOP_CLOSED) != 0)
		cnt = EOF;
	else 
		cnt = get_a_record(&begin, iop, & errcode);

	if (cnt == EOF) {
		retval = 1;
		if (errcode > 0) {
			update_ERRNO_saved(errcode);
			if (do_traditional || ! has_endfile)
				fatal(_("error reading input file `%s': %s"),
						iop->name, strerror(errcode));
		}
	} else {
		NR += 1;
		FNR += 1;
		set_record(begin, cnt);
	}

	return retval;
}

/* remap_std_file --- reopen a standard descriptor on /dev/null */

static int
remap_std_file(int oldfd)
{
	int newfd;
	int ret = -1;

	close(oldfd);
	newfd = open("/dev/null", O_RDWR);
	if (newfd >= 0 && newfd != oldfd) {
		/* dup2() will close oldfd for us first. */
		ret = dup2(newfd, oldfd);
		if (ret == 0)
			close(newfd);
	} else
		ret = 0;

	return ret;
}

/* iop_close --- close an open IOP */

static int
iop_close(IOBUF *iop)
{
	int ret;

	if (iop == NULL)
		return 0;
	if (iop->fd == INVALID_HANDLE) {	/* from nextfile(...) above */
		assert(iop->buf == NULL);
		assert((iop->flag & IOP_NOFREE_OBJ) != 0);
		return 0;
	}	

	errno = 0;

	iop->flag &= ~IOP_AT_EOF;
	iop->flag |= IOP_CLOSED;	/* there may be dangling pointers */
	iop->dataend = NULL;
	/*
	 * Closing standard files can cause crufty code elsewhere to lose.
	 * So we remap the standard file to /dev/null.
	 * Thanks to Jim Meyering for the suggestion.
	 */
	if (iop->fd == fileno(stdin)
	    || iop->fd == fileno(stdout)
	    || iop->fd == fileno(stderr))
		ret = remap_std_file(iop->fd);
	else
		ret = close(iop->fd);

	if (iop->close_func != NULL)
		(*iop->close_func)(iop);

	if (ret == -1)
		warning(_("close of fd %d (`%s') failed (%s)"), iop->fd,
				iop->name, strerror(errno));
	/*
	 * Be careful -- $0 may still reference the buffer even though
	 * an explicit close is being done; in the future, maybe we
	 * can do this a bit better.
	 */
	if (iop->buf) {
		if ((fields_arr[0]->stptr >= iop->buf)
		    && (fields_arr[0]->stptr < (iop->buf + iop->size))) {
			NODE *t;

			t = make_string(fields_arr[0]->stptr,
					fields_arr[0]->stlen);
			unref(fields_arr[0]);
			fields_arr[0] = t;
			/*
			 * 1/27/2003: This used to be here:
			 *
			 * reset_record();
			 *
			 * Don't do that; reset_record() throws away all fields,
			 * saves FS etc.  We just need to make sure memory isn't
			 * corrupted and that references to $0 and fields work.
			 */
		}
		efree(iop->buf);
		iop->buf = NULL;
	}
	if ((iop->flag & IOP_NOFREE_OBJ) == 0)
		efree(iop);
	return ret == -1 ? 1 : 0;
}

/* redflags2str --- turn redirection flags into a string, for debugging */

const char *
redflags2str(int flags)
{
	static const struct flagtab redtab[] = {
		{ RED_FILE,	"RED_FILE" },
		{ RED_PIPE,	"RED_PIPE" },
		{ RED_READ,	"RED_READ" },
		{ RED_WRITE,	"RED_WRITE" },
		{ RED_APPEND,	"RED_APPEND" },
		{ RED_NOBUF,	"RED_NOBUF" },
		{ RED_EOF,	"RED_EOF" },
		{ RED_TWOWAY,	"RED_TWOWAY" },
		{ RED_PTY,	"RED_PTY" },
		{ RED_SOCKET,	"RED_SOCKET" },
		{ RED_TCP,	"RED_TCP" },
		{ 0, NULL }
	};

	return genflags2str(flags, redtab);
}

/* redirect --- Redirection for printf and print commands */

struct redirect *
redirect(NODE *redir_exp, int redirtype, int *errflg)
{
	struct redirect *rp;
	char *str;
	int tflag = 0;
	int outflag = 0;
	const char *direction = "to";
	const char *mode;
	int fd;
	const char *what = NULL;
	int new_rp = FALSE;
	int len;	/* used with /inet */
	static struct redirect *save_rp = NULL;	/* hold onto rp that should
	                                         * be freed for reuse
	                                         */

	if (do_sandbox)
		fatal(_("redirection not allowed in sandbox mode"));

	switch (redirtype) {
	case redirect_append:
		tflag = RED_APPEND;
		/* FALL THROUGH */
	case redirect_output:
		outflag = (RED_FILE|RED_WRITE);
		tflag |= outflag;
		if (redirtype == redirect_output)
			what = ">";
		else
			what = ">>";
		break;
	case redirect_pipe:
		tflag = (RED_PIPE|RED_WRITE);
		what = "|";
		break;
	case redirect_pipein:
		tflag = (RED_PIPE|RED_READ);
		what = "|";
		break;
	case redirect_input:
		tflag = (RED_FILE|RED_READ);
		what = "<";
		break;
	case redirect_twoway:
		tflag = (RED_READ|RED_WRITE|RED_TWOWAY);
		what = "|&";
		break;
	default:
		cant_happen();
	}
	if (do_lint && (redir_exp->flags & STRCUR) == 0)
		lintwarn(_("expression in `%s' redirection only has numeric value"),
			what);
	redir_exp = force_string(redir_exp);
	str = redir_exp->stptr;

	if (str == NULL || *str == '\0')
		fatal(_("expression for `%s' redirection has null string value"),
			what);

	if (do_lint && (STREQN(str, "0", redir_exp->stlen)
						|| STREQN(str, "1", redir_exp->stlen))
	)
		lintwarn(_("filename `%s' for `%s' redirection may be result of logical expression"),
				str, what);

	/*
	 * XXX: Use /inet4 and /inet6 with plain /inet being whatever
	 * we get back from the system.
	 */
#ifdef HAVE_SOCKETS
	if (inetfile(str, & len, NULL)) {
		tflag |= RED_SOCKET;
		if (STREQN(str + len, "tcp/", 4))
			tflag |= RED_TCP;	/* use shutdown when closing */
	}
#endif /* HAVE_SOCKETS */

	for (rp = red_head; rp != NULL; rp = rp->next) {
#ifndef PIPES_SIMULATED
		/*
		 * This is an efficiency hack.  We want to
		 * recover the process slot for dead children,
		 * if at all possible.  Messing with signal() for
		 * SIGCLD leads to lots of headaches.  However, if
		 * we've gotten EOF from a child input pipeline, it's
		 * good bet that the child has died. So recover it.
		 */
		if ((rp->flag & RED_EOF) && redirtype == redirect_pipein) {
			if (rp->pid != -1)
				wait_any(0);
		}
#endif /* PIPES_SIMULATED */

		/* now check for a match */
		if (strlen(rp->value) == redir_exp->stlen
		    && memcmp(rp->value, str, redir_exp->stlen) == 0
		    && ((rp->flag & ~(RED_NOBUF|RED_EOF|RED_PTY)) == tflag
			|| (outflag != 0
			    && (rp->flag & (RED_FILE|RED_WRITE)) == outflag))) {

			int rpflag = (rp->flag & ~(RED_NOBUF|RED_EOF|RED_PTY));
			int newflag = (tflag & ~(RED_NOBUF|RED_EOF|RED_PTY));

			if (do_lint && rpflag != newflag)
				lintwarn(
		_("unnecessary mixing of `>' and `>>' for file `%.*s'"),
					(int) redir_exp->stlen, rp->value);

			break;
		}
	}

	if (rp == NULL) {
		new_rp = TRUE;
		if (save_rp != NULL) {
			rp = save_rp;
			efree(rp->value);
		} else
			emalloc(rp, struct redirect *, sizeof(struct redirect), "redirect");
		emalloc(str, char *, redir_exp->stlen + 1, "redirect");
		memcpy(str, redir_exp->stptr, redir_exp->stlen);
		str[redir_exp->stlen] = '\0';
		rp->value = str;
		rp->flag = tflag;
		rp->fp = NULL;
		rp->iop = NULL;
		rp->pid = -1;
		rp->status = 0;
	} else
		str = rp->value;	/* get \0 terminated string */
	save_rp = rp;

	while (rp->fp == NULL && rp->iop == NULL) {
		if (! new_rp && rp->flag & RED_EOF) {
			/*
			 * encountered EOF on file or pipe -- must be cleared
			 * by explicit close() before reading more
			 */
			save_rp = NULL;
			return rp;
		}
		mode = NULL;
		errno = 0;
		switch (redirtype) {
		case redirect_output:
			mode = binmode("w");
			if ((rp->flag & RED_USED) != 0)
				mode = (rp->mode[1] == 'b') ? "ab" : "a";
			break;
		case redirect_append:
			mode = binmode("a");
			break;
		case redirect_pipe:
			/* synchronize output before new pipe */
			(void) flush_io();

			os_restore_mode(fileno(stdin));
			if ((rp->fp = popen(str, binmode("w"))) == NULL)
				fatal(_("can't open pipe `%s' for output (%s)"),
						str, strerror(errno));

			/* set close-on-exec */
			os_close_on_exec(fileno(rp->fp), str, "pipe", "to");
			rp->flag |= RED_NOBUF;
			break;
		case redirect_pipein:
			direction = "from";
			if (gawk_popen(str, rp) == NULL)
				fatal(_("can't open pipe `%s' for input (%s)"),
					str, strerror(errno));
			break;
		case redirect_input:
			direction = "from";
			fd = devopen(str, binmode("r"));
			if (fd == INVALID_HANDLE && errno == EISDIR) {
				*errflg = EISDIR;
				/* do not free rp, saving it for reuse (save_rp = rp) */
				return NULL;
			}
			rp->iop = iop_alloc(fd, str, NULL, TRUE);
			break;
		case redirect_twoway:
			direction = "to/from";
			if (! two_way_open(str, rp)) {
#ifdef HAVE_SOCKETS
				if (inetfile(str, NULL, NULL)) {
					*errflg = errno;
					/* do not free rp, saving it for reuse (save_rp = rp) */
					return NULL;
				} else
#endif
					fatal(_("can't open two way pipe `%s' for input/output (%s)"),
							str, strerror(errno));
			}
			break;
		default:
			cant_happen();
		}

		if (mode != NULL) {
			errno = 0;
			fd = devopen(str, mode);

			if (fd > INVALID_HANDLE) {
				if (fd == fileno(stdin))
					rp->fp = stdin;
				else if (fd == fileno(stdout))
					rp->fp = stdout;
				else if (fd == fileno(stderr))
					rp->fp = stderr;
				else {
					const char *omode = mode;
#if defined(F_GETFL) && defined(O_APPEND)
					int fd_flags;

					fd_flags = fcntl(fd, F_GETFL);
					if (fd_flags != -1 && (fd_flags & O_APPEND) == O_APPEND)
						omode = binmode("a");
#endif
					os_close_on_exec(fd, str, "file", "");
					rp->fp = fdopen(fd, (const char *) omode);
					rp->mode = (const char *) mode;
					/* don't leak file descriptors */
					if (rp->fp == NULL)
						close(fd);
				}
				if (rp->fp != NULL && os_isatty(fd))
					rp->flag |= RED_NOBUF;

				/* Move rp to the head of the list. */
				if (! new_rp && red_head != rp) {
					if ((rp->prev->next = rp->next) != NULL)
						rp->next->prev = rp->prev;
					red_head->prev = rp;
					rp->prev = NULL;
					rp->next = red_head;
					red_head = rp;
				}
			}
		}

		if (rp->fp == NULL && rp->iop == NULL) {
			/* too many files open -- close one and try again */
			if (errno == EMFILE || errno == ENFILE)
				close_one();
#if defined __MINGW32__ || defined __sun
			else if (errno == 0)    /* HACK! */
				close_one();
#endif
#ifdef VMS
			/* Alpha/VMS V7.1's C RTL is returning this instead
			   of EMFILE (haven't tried other post-V6.2 systems) */
#define SS$_EXQUOTA 0x001C
			else if (errno == EIO && vaxc$errno == SS$_EXQUOTA)
				close_one();
#endif
			else {
				/*
				 * Some other reason for failure.
				 *
				 * On redirection of input from a file,
				 * just return an error, so e.g. getline
				 * can return -1.  For output to file,
				 * complain. The shell will complain on
				 * a bad command to a pipe.
				 */
				if (errflg != NULL)
					*errflg = errno;
				if (redirtype == redirect_output
						|| redirtype == redirect_append
				) {
					/* multiple messages make life easier for translators */
					if (*direction == 'f')
						fatal(_("can't redirect from `%s' (%s)"),
					    		str, strerror(errno));
					else
						fatal(_("can't redirect to `%s' (%s)"),
							str, strerror(errno));
				} else {
					/* do not free rp, saving it for reuse (save_rp = rp) */
					return NULL;
				}
			}
		}
	}

	if (new_rp) {
		/*
		 * It opened successfully, hook it into the list.
		 * Maintain the list in most-recently-used first order.
		 */
		if (red_head != NULL)
			red_head->prev = rp;
		rp->prev = NULL;
		rp->next = red_head;
		red_head = rp;
	}
	save_rp = NULL;
	return rp;
}

/* getredirect --- find the struct redirect for this file or pipe */

struct redirect *
getredirect(const char *str, int len)
{
	struct redirect *rp;

	for (rp = red_head; rp != NULL; rp = rp->next)
		if (strlen(rp->value) == len && memcmp(rp->value, str, len) == 0)
			return rp;

	return NULL;
}

/* close_one --- temporarily close an open file to re-use the fd */

static void
close_one()
{
	struct redirect *rp;
	struct redirect *rplast = NULL;

	static short warned = FALSE;

	if (do_lint && ! warned) {
		warned = TRUE;
		lintwarn(_("reached system limit for open files: starting to multiplex file descriptors"));
	}

	/* go to end of list first, to pick up least recently used entry */
	for (rp = red_head; rp != NULL; rp = rp->next)
		rplast = rp;
	/* now work back up through the list */
	for (rp = rplast; rp != NULL; rp = rp->prev) {
		/* don't close standard files! */
		if (rp->fp == NULL || rp->fp == stderr || rp->fp == stdout)
			continue;

		if ((rp->flag & (RED_FILE|RED_WRITE)) == (RED_FILE|RED_WRITE)) {
			rp->flag |= RED_USED;
			errno = 0;
			if (/* do_lint && */ fclose(rp->fp) != 0)
				warning(_("close of `%s' failed (%s)."),
					rp->value, strerror(errno));
			rp->fp = NULL;
			break;
		}
	}
	if (rp == NULL)
		/* surely this is the only reason ??? */
		fatal(_("too many pipes or input files open")); 
}

/* do_close --- completely close an open file or pipe */

NODE *
do_close(int nargs)
{
	NODE *tmp, *tmp2;
	struct redirect *rp;
	two_way_close_type how = CLOSE_ALL;	/* default */

	if (nargs == 2) {
		/* 2nd arg if present: "to" or "from" for two-way pipe */
		/* DO NOT use _() on the strings here! */
		tmp2 = POP_STRING();
		if (strcasecmp(tmp2->stptr, "to") == 0)
			how = CLOSE_TO;
		else if (strcasecmp(tmp2->stptr, "from") == 0)
			how = CLOSE_FROM;
		else {
			DEREF(tmp2);
			fatal(_("close: second argument must be `to' or `from'"));
		}
		DEREF(tmp2);
	}

	tmp = POP_STRING(); 	/* 1st arg: redir to close */

	for (rp = red_head; rp != NULL; rp = rp->next) {
		if (strlen(rp->value) == tmp->stlen
		    && memcmp(rp->value, tmp->stptr, tmp->stlen) == 0)
			break;
	}

	if (rp == NULL) {	/* no match, return -1 */
		char *cp;

		if (do_lint)
			lintwarn(_("close: `%.*s' is not an open file, pipe or co-process"),
				(int) tmp->stlen, tmp->stptr);

		if (! do_traditional) {
			/* update ERRNO manually, using errno = ENOENT is a stretch. */
			cp = _("close of redirection that was never opened");
			unref(ERRNO_node->var_value);
			ERRNO_node->var_value = make_string(cp, strlen(cp));
		}

		DEREF(tmp);
		return make_number((AWKNUM) -1.0);
	}
	DEREF(tmp);
	fflush(stdout);	/* synchronize regular output */
	tmp = make_number((AWKNUM) close_redir(rp, FALSE, how));
	rp = NULL;
	/*
	 * POSIX says close() returns 0 on success, non-zero otherwise.
	 * For POSIX, at this point we just return 0.  Otherwise we
	 * return the exit status of the process or of pclose(), depending.
	 * This whole business is a mess.
	 */
	if (do_posix) {
		unref(tmp);
		return make_number((AWKNUM) 0);
	}
	return tmp;
}

/* close_rp --- separate function to just do closing */

static int
close_rp(struct redirect *rp, two_way_close_type how)
{
	int status = 0;

	errno = 0;
	if ((rp->flag & RED_TWOWAY) != 0) {	/* two-way pipe */
		/* write end: */
		if ((how == CLOSE_ALL || how == CLOSE_TO) && rp->fp != NULL) {
#ifdef HAVE_SOCKETS
			if ((rp->flag & RED_TCP) != 0)
				(void) shutdown(fileno(rp->fp), SHUT_WR);
#endif /* HAVE_SOCKETS */

			if ((rp->flag & RED_PTY) != 0) {
				fwrite("\004\n", sizeof("\004\n") - 1, 1, rp->fp);
				fflush(rp->fp);
			}
			status = fclose(rp->fp);
			rp->fp = NULL;
		}

		/* read end: */
		if (how == CLOSE_ALL || how == CLOSE_FROM) {
			if ((rp->flag & RED_SOCKET) != 0 && rp->iop != NULL) {
#ifdef HAVE_SOCKETS
				if ((rp->flag & RED_TCP) != 0)
					(void) shutdown(rp->iop->fd, SHUT_RD);
#endif /* HAVE_SOCKETS */
				(void) iop_close(rp->iop);
			} else
				status = gawk_pclose(rp);

			rp->iop = NULL;
		}
	} else if ((rp->flag & (RED_PIPE|RED_WRITE)) == (RED_PIPE|RED_WRITE)) { /* write to pipe */
		status = pclose(rp->fp);
		if ((BINMODE & 1) != 0)
			os_setbinmode(fileno(stdin), O_BINARY);

		rp->fp = NULL;
	} else if (rp->fp != NULL) {	/* write to file */
		status = fclose(rp->fp);
		rp->fp = NULL;
	} else if (rp->iop != NULL) {	/* read from pipe/file */
		if ((rp->flag & RED_PIPE) != 0)		/* read from pipe */
			status = gawk_pclose(rp);
			/* gawk_pclose sets rp->iop to null */
		else {					/* read from file */
			status = iop_close(rp->iop);
			rp->iop = NULL;
		}
	}

	return status;
}

/* close_redir --- close an open file or pipe */

static int
close_redir(struct redirect *rp, int exitwarn, two_way_close_type how)
{
	int status = 0;

	if (rp == NULL)
		return 0;
	if (rp->fp == stdout || rp->fp == stderr)
		goto checkwarn;		/* bypass closing, remove from list */

	if (do_lint && (rp->flag & RED_TWOWAY) == 0 && how != CLOSE_ALL)
		lintwarn(_("close: redirection `%s' not opened with `|&', second argument ignored"),
				rp->value);

	status = close_rp(rp, how);

	/* SVR4 awk checks and warns about status of close */
	if (status != 0) {
		int save_errno = errno;
		char *s = strerror(save_errno);

		/*
		 * Too many people have complained about this.
		 * As of 2.15.6, it is now under lint control.
		 */
		if (do_lint) {
			if ((rp->flag & RED_PIPE) != 0)
				lintwarn(_("failure status (%d) on pipe close of `%s' (%s)"),
					 status, rp->value, s);
			else
				lintwarn(_("failure status (%d) on file close of `%s' (%s)"),
					 status, rp->value, s);
		}

		if (! do_traditional) {
			/* set ERRNO too so that program can get at it */
			update_ERRNO_saved(save_errno);
		}
	}

checkwarn:
	if (exitwarn) {
		/*
		 * Don't use lintwarn() here.  If lint warnings are fatal,
		 * doing so prevents us from closing other open redirections.
		 *
		 * Using multiple full messages instead of string parameters
		 * for the types makes message translation easier.
		 */
		if ((rp->flag & RED_SOCKET) != 0)
			warning(_("no explicit close of socket `%s' provided"),
				rp->value);
		else if ((rp->flag & RED_TWOWAY) != 0)
			warning(_("no explicit close of co-process `%s' provided"),
				rp->value);
		else if ((rp->flag & RED_PIPE) != 0)
			warning(_("no explicit close of pipe `%s' provided"),
				rp->value);
		else
			warning(_("no explicit close of file `%s' provided"),
				rp->value);
	}

	/* remove it from the list if closing both or both ends have been closed */
	if (how == CLOSE_ALL || (rp->iop == NULL && rp->fp == NULL)) {
		if (rp->next != NULL)
			rp->next->prev = rp->prev;
		if (rp->prev != NULL)
			rp->prev->next = rp->next;
		else
			red_head = rp->next;
		free_rp(rp);
	}

	return status;
}

/* flush_io --- flush all open output files */

int
flush_io()
{
	struct redirect *rp;
	int status = 0;

	errno = 0;
	if (fflush(stdout)) {
		warning(_("error writing standard output (%s)"), strerror(errno));
		status++;
	}
	if (fflush(stderr)) {
		warning(_("error writing standard error (%s)"), strerror(errno));
		status++;
	}
	for (rp = red_head; rp != NULL; rp = rp->next)
		/* flush both files and pipes, what the heck */
		if ((rp->flag & RED_WRITE) && rp->fp != NULL) {
			if (fflush(rp->fp)) {
				if (rp->flag  & RED_PIPE)
					warning(_("pipe flush of `%s' failed (%s)."),
						rp->value, strerror(errno));
				else if (rp->flag & RED_TWOWAY)
					warning(_("co-process flush of pipe to `%s' failed (%s)."),
						rp->value, strerror(errno));
				else
					warning(_("file flush of `%s' failed (%s)."),
						rp->value, strerror(errno));
				status++;
			}
		}
	if (status != 0)
		status = -1;	/* canonicalize it */
	return status;
}

/* close_io --- close all open files, called when exiting */

int
close_io(int *stdio_problem)
{
	struct redirect *rp;
	struct redirect *next;
	int status = 0;

	errno = 0;
	for (rp = red_head; rp != NULL; rp = next) {
		next = rp->next;
		/*
		 * close_redir() will print a message if needed
		 * if do_lint, warn about lack of explicit close
		 */
		if (close_redir(rp, do_lint, CLOSE_ALL))
			status++;
		rp = NULL;
	}
	/*
	 * Some of the non-Unix os's have problems doing an fclose
	 * on stdout and stderr.  Since we don't really need to close
	 * them, we just flush them, and do that across the board.
	 */
	*stdio_problem = FALSE;
	if (fflush(stdout)) {
		warning(_("error writing standard output (%s)"), strerror(errno));
		status++;
		*stdio_problem = TRUE;
	}
	if (fflush(stderr)) {
		warning(_("error writing standard error (%s)"), strerror(errno));
		status++;
		*stdio_problem = TRUE;
	}
	return status;
}

/* str2mode --- convert a string mode to an integer mode */

static int
str2mode(const char *mode)
{
	int ret;
	const char *second = & mode[1];

	if (*second == 'b')
		second++;

	switch(mode[0]) {
	case 'r':
		ret = O_RDONLY;
		if (*second == '+' || *second == 'w')
			ret = O_RDWR;
		break;

	case 'w':
		ret = O_WRONLY|O_CREAT|O_TRUNC;
		if (*second == '+' || *second == 'r')
			ret = O_RDWR|O_CREAT|O_TRUNC;
		break;

	case 'a':
		ret = O_WRONLY|O_APPEND|O_CREAT;
		if (*second == '+')
			ret = O_RDWR|O_APPEND|O_CREAT;
		break;

	default:
		ret = 0;		/* lint */
		cant_happen();
	}
	if (strchr(mode, 'b') != NULL)
		ret |= O_BINARY;
	return ret;
}

#ifdef HAVE_SOCKETS

/* socketopen --- open a socket and set it into connected state */

static int
socketopen(int family, int type, const char *localpname,
	const char *remotepname, const char *remotehostname)
{
	struct addrinfo *lres, *lres0;
	struct addrinfo lhints;
	struct addrinfo *rres, *rres0;
	struct addrinfo rhints;

	int lerror;
	int rerror;

	int socket_fd = INVALID_HANDLE;
	int any_remote_host = (strcmp(remotehostname, "0") == 0);

	memset (&lhints, '\0', sizeof (lhints));
	lhints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
	lhints.ai_socktype = type;
	lhints.ai_family = family;

	lerror = getaddrinfo (NULL, localpname, &lhints, &lres);
	if (lerror) {
		if (strcmp(localpname, "0") != 0)
			fatal(_("local port %s invalid in `/inet'"), localpname);
		lres0 = NULL;
		lres = &lhints;
	} else
		lres0 = lres;

	while (lres != NULL) {
		memset (&rhints, '\0', sizeof (rhints));
		rhints.ai_flags = lhints.ai_flags;
		rhints.ai_socktype = lhints.ai_socktype;
		rhints.ai_family = lhints.ai_family;
		rhints.ai_protocol = lhints.ai_protocol;

		rerror = getaddrinfo (any_remote_host ? NULL : remotehostname, remotepname, &rhints, &rres);
		if (rerror) {
			if (lres0 != NULL)
				freeaddrinfo(lres0);
			fatal(_("remote host and port information (%s, %s) invalid"), remotehostname, remotepname);
		}
		rres0 = rres;
		socket_fd = INVALID_HANDLE;
		while (rres != NULL) {
			socket_fd = socket(rres->ai_family,
				rres->ai_socktype, rres->ai_protocol);
			if (socket_fd < 0 || socket_fd == INVALID_HANDLE)
				goto nextrres;

			if (type == SOCK_STREAM) {
				int on = 1;
#ifdef SO_LINGER
				struct linger linger;
				memset(& linger, '\0', sizeof(linger));
#endif
				setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR,
					(char *) & on, sizeof(on));
#ifdef SO_LINGER
				linger.l_onoff = 1;
				linger.l_linger = 30;    /* linger for 30/100 second */
				setsockopt(socket_fd, SOL_SOCKET, SO_LINGER,
					(char *) & linger, sizeof(linger));
#endif
			}
			if (bind(socket_fd, lres->ai_addr, lres->ai_addrlen) != 0)
				goto nextrres;

			if (! any_remote_host) { /* not ANY => create a client */
				if (connect(socket_fd, rres->ai_addr, rres->ai_addrlen) == 0)
					break;
			} else { /* remote host is ANY => create a server */
				if (type == SOCK_STREAM) {
					int clientsocket_fd = INVALID_HANDLE;

					struct sockaddr_storage remote_addr;
					socklen_t namelen = sizeof (remote_addr);

					if (listen(socket_fd, 1) >= 0
					    && (clientsocket_fd = accept(socket_fd,
						(struct sockaddr *) &remote_addr,
						&namelen)) >= 0) {
						close(socket_fd);
						socket_fd = clientsocket_fd;
						break;
					}
				} else if (type == SOCK_DGRAM) {
#ifdef MSG_PEEK
					char buf[10];
					struct sockaddr_storage remote_addr;
					socklen_t readle;

					if (recvfrom(socket_fd, buf, 1, MSG_PEEK,
						(struct sockaddr *) & remote_addr,
							& readle) >= 0
							&& readle
							&& connect(socket_fd,
						(struct sockaddr *)& remote_addr,
								readle) == 0)
							break;
#endif
				}
			}

nextrres:
			if (socket_fd != INVALID_HANDLE)
				close(socket_fd);
			socket_fd = INVALID_HANDLE;
			rres = rres->ai_next;
		}
		freeaddrinfo(rres0);
		if (socket_fd != INVALID_HANDLE)
			break;
		lres = lres->ai_next;
	}
	if (lres0)
		freeaddrinfo(lres0);

	return socket_fd;
}
#endif /* HAVE_SOCKETS */

/* devopen --- handle /dev/std{in,out,err}, /dev/fd/N, regular files */

/*
 * Strictly speaking, "name" is not a "const char *" because we temporarily
 * change the string.
 */

int
devopen(const char *name, const char *mode)
{
	int openfd;
	char *cp;
	char *ptr;
	int flag = 0;
	int len;
	int family;

	flag = str2mode(mode);

	if (STREQ(name, "-"))
		return fileno(stdin);

	openfd = INVALID_HANDLE;

	if (do_traditional)
		goto strictopen;

	if ((openfd = os_devopen(name, flag)) != INVALID_HANDLE) {
		os_close_on_exec(openfd, name, "file", "");
		return openfd;
	}

	if (STREQN(name, "/dev/", 5)) {
		cp = (char *) name + 5;

		if (STREQ(cp, "stdin") && (flag & O_ACCMODE) == O_RDONLY)
			openfd = fileno(stdin);
		else if (STREQ(cp, "stdout") && (flag & O_ACCMODE) == O_WRONLY)
			openfd = fileno(stdout);
		else if (STREQ(cp, "stderr") && (flag & O_ACCMODE) == O_WRONLY)
			openfd = fileno(stderr);
		else if (STREQN(cp, "fd/", 3)) {
			struct stat sbuf;

			cp += 3;
			openfd = (int) strtoul(cp, &ptr, 10);
			if (openfd <= INVALID_HANDLE || ptr == cp
			    || fstat(openfd, &sbuf) < 0)
				openfd = INVALID_HANDLE;
		}
		/* do not set close-on-exec for inherited fd's */
		if (openfd != INVALID_HANDLE)
			return openfd;
	} else if (inetfile(name, & len, & family)) {
#ifdef HAVE_SOCKETS
		/* /inet/protocol/localport/hostname/remoteport */
		int protocol;
		char *hostname;
		char *hostnameslastcharp;
		char *localpname;
		char *localpnamelastcharp;

		cp = (char *) name + len;
		/* which protocol? */
		if (STREQN(cp, "tcp/", 4))
			protocol = SOCK_STREAM;
		else if (STREQN(cp, "udp/", 4))
			protocol = SOCK_DGRAM;
		else {
			protocol = SOCK_STREAM;	/* shut up the compiler */
			fatal(_("no (known) protocol supplied in special filename `%s'"),
						name);
		}
		cp += 4;

		/* which localport? */
		localpname = cp;
		while (*cp != '/' && *cp != '\0')
			cp++;
		/*                    
		 * Require a port, let them explicitly put 0 if
		 * they don't care.  
		 */
		if (*cp != '/' || cp == localpname)
			fatal(_("special file name `%s' is incomplete"), name);

		/*
		 * We change the special file name temporarily because we
		 * need a 0-terminated string here for conversion with atoi().
		 * By using atoi() the use of decimal numbers is enforced.
		 */
		*cp = '\0';
		localpnamelastcharp = cp;

		/* which hostname? */
		cp++;
		hostname = cp;
		while (*cp != '/' && *cp != '\0')
			cp++; 
		if (*cp != '/' || cp == hostname) {
			*localpnamelastcharp = '/';
			fatal(_("must supply a remote hostname to `/inet'"));
		}
		*cp = '\0';
		hostnameslastcharp = cp;

		/* which remoteport? */
		cp++;
		/*
		 * The remote port ends the special file name.
		 * This means there already is a 0 at the end of the string.
		 * Therefore no need to patch any string ending.
		 *
		 * Here too, require a port, let them explicitly put 0 if
		 * they don't care.
		 */
		if (*cp == '\0') {
			*localpnamelastcharp = '/';
			*hostnameslastcharp = '/';
			fatal(_("must supply a remote port to `/inet'"));
		}

		{
#define DEFAULT_RETRIES 20
			static unsigned long def_retries = DEFAULT_RETRIES;
			static int first_time = TRUE;
			unsigned long retries = 0;
			static long msleep = 1000;

			if (first_time) {
				char *cp, *end;
				unsigned long count = 0;
				char *ms2;
				
				first_time = FALSE;
				if ((cp = getenv("GAWK_SOCK_RETRIES")) != NULL) {
					count = strtoul(cp, &end, 10);
					if (end != cp && count > 0)
						def_retries = count;
				}

				/*
				 * Env var is in milliseconds, paramter to usleep()
				 * is microseconds, make the conversion. Default is
				 * 1 millisecond.
				 */
				if ((ms2 = getenv("GAWK_MSEC_SLEEP")) != NULL) {
					msleep = strtol(ms2, &end, 10);
					if (end == ms2 || msleep < 0)
						msleep = 1000;
					else
						msleep *= 1000;
				}
			}
			retries = def_retries;

			do {
				openfd = socketopen(family, protocol, localpname, cp, hostname);
				retries--;
			} while (openfd == INVALID_HANDLE && retries > 0 && usleep(msleep) == 0);
		}

		*localpnamelastcharp = '/';
		*hostnameslastcharp = '/';
#else /* ! HAVE_SOCKETS */
		fatal(_("TCP/IP communications are not supported"));
#endif /* HAVE_SOCKETS */
	}

strictopen:
	if (openfd == INVALID_HANDLE)
		openfd = open(name, flag, 0666);
#ifdef __EMX__
	if (openfd == INVALID_HANDLE && errno == EACCES) {
		/* on OS/2 directory access via open() is not permitted */
		struct stat buf;

		if (stat(name, &buf) == 0 && S_ISDIR(buf.st_mode))
		errno = EISDIR;
	}
#endif
	if (openfd != INVALID_HANDLE) {
		if (os_isdir(openfd)) {
			(void) close(openfd);	/* don't leak fds */
			/* Set useful error number.  */
			errno = EISDIR;
			return INVALID_HANDLE;
		}

		if (openfd > fileno(stderr))
			os_close_on_exec(openfd, name, "file", "");
	}
	/*
	 * XXX: FIXME: if fd is INVALID_HANDLE, see if an open hook
	 * can do something.
	 */
	return openfd;
}

/* two_way_open --- open a two way communications channel */

static int
two_way_open(const char *str, struct redirect *rp)
{
	static int no_ptys = FALSE;

#ifdef HAVE_SOCKETS
	/* case 1: socket */
	if (inetfile(str, NULL, NULL)) {
		int fd, newfd;

		fd = devopen(str, "rw");
		if (fd == INVALID_HANDLE)
			return FALSE;
		rp->fp = fdopen(fd, "w");
		if (rp->fp == NULL) {
			close(fd);
			return FALSE;
		}
		newfd = dup(fd);
		if (newfd < 0) {
			fclose(rp->fp);
			return FALSE;
		}
		os_close_on_exec(newfd, str, "socket", "to/from");
		rp->iop = iop_alloc(newfd, str, NULL, TRUE);
		if (rp->iop == NULL) {
			fclose(rp->fp);
			return FALSE;
		}
		rp->flag |= RED_SOCKET;
		return TRUE;
	}
#endif /* HAVE_SOCKETS */

#ifdef HAVE_TERMIOS_H
	/* case 2: use ptys for two-way communications to child */
	if (! no_ptys && pty_vs_pipe(str)) {
		static int initialized = FALSE;
		static char first_pty_letter;
#ifdef HAVE_GRANTPT
		static int have_dev_ptmx;
#endif
		char slavenam[32];
		char c;
		int master, dup_master;
		int slave;
		int save_errno; 
		pid_t pid;
		struct stat statb;
		struct termios st;
		/* Use array of chars to avoid ascii / ebcdic issues */
		static char pty_chars[] = "pqrstuvwxyzabcdefghijklmno";
		int i;

		if (! initialized) {
			initialized = TRUE;
#ifdef HAVE_GRANTPT
			have_dev_ptmx = (stat("/dev/ptmx", &statb) >= 0);
#endif
			i = 0;
			do {
				c = pty_chars[i++];
				sprintf(slavenam, "/dev/pty%c0", c);
				if (stat(slavenam, &statb) >= 0) {
					first_pty_letter = c;
					break;
				}
			} while (pty_chars[i] != '\0');
		}

#ifdef HAVE_GRANTPT
		if (have_dev_ptmx) {
			master = open("/dev/ptmx", O_RDWR);
			if (master >= 0) {
				char *tem;

				grantpt(master);
				unlockpt(master);
				tem = ptsname(master);
				if (tem != NULL) {
					strcpy(slavenam, tem);
					goto got_the_pty;
				}
				(void) close(master);
			}
		}
#endif

		if (first_pty_letter) {
			/*
			 * Assume /dev/ptyXNN and /dev/ttyXN naming system.
			 * The FIRST_PTY_LETTER gives the first X to try. We try in the 
			 * sequence FIRST_PTY_LETTER, .., 'z', 'a', .., FIRST_PTY_LETTER.
			 * Is this worthwhile, or just over-zealous?
			 */
			c = first_pty_letter;
			do {
				int i;
				char *cp;

				for (i = 0; i < 16; i++) {
					sprintf(slavenam, "/dev/pty%c%x", c, i);
					if (stat(slavenam, &statb) < 0) {
						no_ptys = TRUE;	/* bypass all this next time */
						goto use_pipes;
					}

					if ((master = open(slavenam, O_RDWR)) >= 0) {
						slavenam[sizeof("/dev/") - 1] = 't';
						if (access(slavenam, R_OK | W_OK) == 0)
							goto got_the_pty;
						close(master);
					}
				}
				/* move to next character */
				cp = strchr(pty_chars, c);
				if (cp[1] != '\0')
					cp++;
				else
					cp = pty_chars;
				c = *cp;
			} while (c != first_pty_letter);
		} else
			no_ptys = TRUE;

		/* Couldn't find a pty. Fall back to using pipes. */
		goto use_pipes;

	got_the_pty:
		if ((slave = open(slavenam, O_RDWR)) < 0) {
			close(master);
			fatal(_("could not open `%s', mode `%s'"),
				slavenam, "r+");
		}

#ifdef I_PUSH
		/*
		 * Push the necessary modules onto the slave to
		 * get terminal semantics.
		 */
		ioctl(slave, I_PUSH, "ptem");
		ioctl(slave, I_PUSH, "ldterm");
#endif

#ifdef TIOCSCTTY
		ioctl(slave, TIOCSCTTY, 0);
#endif
		tcgetattr(slave, &st);
		st.c_iflag &= ~(ISTRIP | IGNCR | INLCR | IXOFF);
		st.c_iflag |= (ICRNL | IGNPAR | BRKINT | IXON);
		st.c_oflag &= ~OPOST;
		st.c_cflag &= ~CSIZE;
		st.c_cflag |= CREAD | CS8 | CLOCAL;
		st.c_lflag &= ~(ECHO | ECHOE | ECHOK | NOFLSH | TOSTOP);
		st.c_lflag |= ISIG;
#if 0
		st.c_cc[VMIN] = 1;
		st.c_cc[VTIME] = 0;
#endif

		/* Set some control codes to default values */
#ifdef VINTR
		st.c_cc[VINTR] = '\003';        /* ^c */
#endif
#ifdef VQUIT
		st.c_cc[VQUIT] = '\034';        /* ^| */
#endif
#ifdef VERASE
		st.c_cc[VERASE] = '\177';       /* ^? */
#endif
#ifdef VKILL
		st.c_cc[VKILL] = '\025';        /* ^u */
#endif
#ifdef VEOF
		st.c_cc[VEOF] = '\004'; /* ^d */
#endif
		tcsetattr(slave, TCSANOW, &st);

		switch (pid = fork ()) {
		case 0:
			/* Child process */
			if (close(master) == -1)
				fatal(_("close of master pty failed (%s)"), strerror(errno));
			if (close(1) == -1)
				fatal(_("close of stdout in child failed (%s)"),
					strerror(errno));
			if (dup(slave) != 1)
				fatal(_("moving slave pty to stdout in child failed (dup: %s)"), strerror(errno));
			if (close(0) == -1)
				fatal(_("close of stdin in child failed (%s)"),
					strerror(errno));
			if (dup(slave) != 0)
				fatal(_("moving slave pty to stdin in child failed (dup: %s)"), strerror(errno));
			if (close(slave))
				fatal(_("close of slave pty failed (%s)"), strerror(errno));

			/* stderr does NOT get dup'ed onto child's stdout */

			signal(SIGPIPE, SIG_DFL);

			execl("/bin/sh", "sh", "-c", str, NULL);
			_exit(errno == ENOENT ? 127 : 126);

		case -1:
			save_errno = errno;
			close(master);
			errno = save_errno;
			return FALSE;

		}

		/* parent */
		if (close(slave)) {
			close(master);
			(void) kill(pid, SIGKILL);      /* overkill? (pardon pun) */
			fatal(_("close of slave pty failed (%s)"), strerror(errno));
		}

		rp->pid = pid;
		rp->iop = iop_alloc(master, str, NULL, TRUE);
		if (rp->iop == NULL) {
			(void) close(master);
			(void) kill(pid, SIGKILL);      /* overkill? (pardon pun) */
			return FALSE;
		}

		/*
		 * Force read and write ends of two-way connection to
		 * be different fd's so they can be closed independently.
		 */
		if ((dup_master = dup(master)) < 0
		    || (rp->fp = fdopen(dup_master, "w")) == NULL) {
			iop_close(rp->iop);
			rp->iop = NULL;
			(void) close(master);
			(void) kill(pid, SIGKILL);      /* overkill? (pardon pun) */
			if (dup_master > 0)
				(void) close(dup_master);
			return FALSE;
		}
		rp->flag |= RED_PTY;
		os_close_on_exec(master, str, "pipe", "from");
		os_close_on_exec(dup_master, str, "pipe", "to");
		first_pty_letter = '\0';	/* reset for next command */
		return TRUE;
	}
#endif /* HAVE_TERMIOS_H */

use_pipes:
#ifndef PIPES_SIMULATED		/* real pipes */
	/* case 3: two way pipe to a child process */
    {
	int ptoc[2], ctop[2];
	int pid;
	int save_errno;
#ifdef __EMX__
	int save_stdout, save_stdin;
#endif

	if (pipe(ptoc) < 0)
		return FALSE;	/* errno set, diagnostic from caller */

	if (pipe(ctop) < 0) {
		save_errno = errno;
		close(ptoc[0]);
		close(ptoc[1]);
		errno = save_errno;
		return FALSE;
	}

#ifdef __EMX__
	save_stdin = dup(0);	/* duplicate stdin */
	save_stdout = dup(1);	/* duplicate stdout */
	
	if (save_stdout == -1 || save_stdin == -1) {
		/* if an error occurrs close all open file handles */
		save_errno = errno;
		if (save_stdin != -1)
			close(save_stdin);
		if (save_stdout != -1)
			close(save_stdout);
		close(ptoc[0]); close(ptoc[1]);
		close(ctop[0]); close(ctop[1]);
		errno = save_errno;
		return FALSE;
	}
	
	/* connect pipes to stdin and stdout */
	close(1);	/* close stdout */
	if (dup(ctop[1]) != 1) {	/* connect pipe input to stdout */
		close(save_stdin); close(save_stdout);
		close(ptoc[0]); close(ptoc[1]);
		close(ctop[0]); close(ctop[1]);
		fatal(_("moving pipe to stdout in child failed (dup: %s)"), strerror(errno));
	}
	close(0);	/* close stdin */
	if (dup(ptoc[0]) != 0) {	/* connect pipe output to stdin */
		close(save_stdin); close(save_stdout);
		close(ptoc[0]); close(ptoc[1]);
		close(ctop[0]); close(ctop[1]);
		fatal(_("moving pipe to stdin in child failed (dup: %s)"), strerror(errno));
	}

	/* none of these handles must be inherited by the child process */
	(void) close(ptoc[0]);	/* close pipe output, child will use stdin instead */
	(void) close(ctop[1]);	/* close pipe input, child will use stdout instead */
	
	os_close_on_exec(ptoc[1], str, "pipe", "from"); /* pipe input: output of the parent process */
	os_close_on_exec(ctop[0], str, "pipe", "from"); /* pipe output: input of the parent process */
	os_close_on_exec(save_stdin, str, "pipe", "from"); /* saved stdin of the parent process */
	os_close_on_exec(save_stdout, str, "pipe", "from"); /* saved stdout of the parent process */

	/* stderr does NOT get dup'ed onto child's stdout */
	pid = spawnl(P_NOWAIT, "/bin/sh", "sh", "-c", str, NULL);
	
	/* restore stdin and stdout */
	close(1);
	if (dup(save_stdout) != 1) {
		close(save_stdin); close(save_stdout);
		close(ptoc[1]); close(ctop[0]);
		fatal(_("restoring stdout in parent process failed\n"));
	}
	close(save_stdout);
	
	close(0);
	if (dup(save_stdin) != 0) {
		close(save_stdin);
		close(ptoc[1]);	close(ctop[0]);
		fatal(_("restoring stdin in parent process failed\n"));
	}
	close(save_stdin);

	if (pid < 0) { /* spawnl() failed */
		save_errno = errno;
		close(ptoc[1]);
		close(ctop[0]);

		errno = save_errno;
		return FALSE;
	}

#else /* NOT __EMX__ */
	if ((pid = fork()) < 0) {
		save_errno = errno;
		close(ptoc[0]); close(ptoc[1]);
		close(ctop[0]); close(ctop[1]);
		errno = save_errno;
		return FALSE;
	}
	
	if (pid == 0) {	/* child */
		if (close(1) == -1)
			fatal(_("close of stdout in child failed (%s)"),
				strerror(errno));
		if (dup(ctop[1]) != 1)
			fatal(_("moving pipe to stdout in child failed (dup: %s)"), strerror(errno));
		if (close(0) == -1)
			fatal(_("close of stdin in child failed (%s)"),
				strerror(errno));
		if (dup(ptoc[0]) != 0)
			fatal(_("moving pipe to stdin in child failed (dup: %s)"), strerror(errno));
		if (   close(ptoc[0]) == -1 || close(ptoc[1]) == -1
		    || close(ctop[0]) == -1 || close(ctop[1]) == -1)
			fatal(_("close of pipe failed (%s)"), strerror(errno));
		/* stderr does NOT get dup'ed onto child's stdout */
		execl("/bin/sh", "sh", "-c", str, NULL);
		_exit(errno == ENOENT ? 127 : 126);
	}
#endif /* NOT __EMX__ */

	/* parent */
	rp->pid = pid;
	rp->iop = iop_alloc(ctop[0], str, NULL, TRUE);
	if (rp->iop == NULL) {
		(void) close(ctop[0]);
		(void) close(ctop[1]);
		(void) close(ptoc[0]);
		(void) close(ptoc[1]);
		(void) kill(pid, SIGKILL);	/* overkill? (pardon pun) */

		return FALSE;
	}
	rp->fp = fdopen(ptoc[1], "w");
	if (rp->fp == NULL) {
		iop_close(rp->iop);
		rp->iop = NULL;
		(void) close(ctop[0]);
		(void) close(ctop[1]);
		(void) close(ptoc[0]);
		(void) close(ptoc[1]);
		(void) kill(pid, SIGKILL);	/* overkill? (pardon pun) */

		return FALSE;
	}

#ifndef __EMX__
	os_close_on_exec(ctop[0], str, "pipe", "from");
	os_close_on_exec(ptoc[1], str, "pipe", "from");

	(void) close(ptoc[0]);
	(void) close(ctop[1]);
#endif

	return TRUE;
    }

#else	/*PIPES_SIMULATED*/

	fatal(_("`|&' not supported"));
	/*NOTREACHED*/
	return FALSE;

#endif
}

#ifndef PIPES_SIMULATED		/* real pipes */

/* wait_any --- wait for a child process, close associated pipe */

static int
wait_any(int interesting)	/* pid of interest, if any */
{
	RETSIGTYPE (*hstat)(int), (*istat)(int), (*qstat)(int);
	int pid;
	int status = 0;
	struct redirect *redp;

	hstat = signal(SIGHUP, SIG_IGN);
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	for (;;) {
#ifdef HAVE_SYS_WAIT_H	/* POSIX compatible sys/wait.h */
		pid = wait(&status);
#else
		pid = wait((union wait *)&status);
#endif
		if (interesting && pid == interesting) {
			break;
		} else if (pid != -1) {
			for (redp = red_head; redp != NULL; redp = redp->next)
				if (pid == redp->pid) {
					redp->pid = -1;
					redp->status = status;
					break;
				}
		}
		if (pid == -1 && errno == ECHILD)
			break;
	}
	signal(SIGHUP, hstat);
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	return status;
}

/* gawk_popen --- open an IOBUF on a child process */

static IOBUF *
gawk_popen(const char *cmd, struct redirect *rp)
{
	int p[2];
	int pid;
#ifdef __EMX__
	int save_stdout;
#endif

	/*
	 * used to wait for any children to synchronize input and output,
	 * but this could cause gawk to hang when it is started in a pipeline
	 * and thus has a child process feeding it input (shell dependant)
	 */
	/*(void) wait_any(0);*/	/* wait for outstanding processes */

	if (pipe(p) < 0)
		fatal(_("cannot open pipe `%s' (%s)"), cmd, strerror(errno));

#ifdef __EMX__
	save_stdout = dup(1); /* save stdout */
	rp->iop = NULL;
	if (save_stdout == -1) {
		close(p[0]); close(p[1]);
		return rp->iop; /* failed */
	}

	close(1); /* close stdout */
	if (dup(p[1]) != 1) {
		close(p[0]); close(p[1]);
		fatal(_("moving pipe to stdout in child failed (dup: %s)"), strerror(errno));
	}
	
	/* none of these handles must be inherited by the child process */
	close(p[1]); /* close pipe input */
	
	os_close_on_exec(p[0], cmd, "pipe", "from"); /* pipe output: input of the parent process */
	os_close_on_exec(save_stdout, cmd, "pipe", "from"); /* saved stdout of the parent process */
	
	pid = spawnl(P_NOWAIT, "/bin/sh", "sh", "-c", cmd, NULL);
	
	/* restore stdout */
	close(1);
	if (dup(save_stdout) != 1) {
		close(p[0]);
		fatal(_("restoring stdout in parent process failed\n"));
	}
	close(save_stdout);

#else /* NOT __EMX__ */
	if ((pid = fork()) == 0) {
		if (close(1) == -1)
			fatal(_("close of stdout in child failed (%s)"),
				strerror(errno));
		if (dup(p[1]) != 1)
			fatal(_("moving pipe to stdout in child failed (dup: %s)"), strerror(errno));
		if (close(p[0]) == -1 || close(p[1]) == -1)
			fatal(_("close of pipe failed (%s)"), strerror(errno));
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		_exit(errno == ENOENT ? 127 : 126);
	}
#endif /* NOT __EMX__ */

	if (pid == -1) {
		close(p[0]); close(p[1]);
		fatal(_("cannot create child process for `%s' (fork: %s)"), cmd, strerror(errno));
	}
	rp->pid = pid;
#ifndef __EMX__
	if (close(p[1]) == -1) {
		close(p[0]);
		fatal(_("close of pipe failed (%s)"), strerror(errno));
	}
#endif
	os_close_on_exec(p[0], cmd, "pipe", "from");
	rp->iop = iop_alloc(p[0], cmd, NULL, TRUE);
	if (rp->iop == NULL)
		(void) close(p[0]);

	return rp->iop;
}

/* gawk_pclose --- close an open child pipe */

static int
gawk_pclose(struct redirect *rp)
{
	if (rp->iop != NULL)
		(void) iop_close(rp->iop);
	rp->iop = NULL;

	/* process previously found, return stored status */
	if (rp->pid == -1)
		return rp->status;
	rp->status = wait_any(rp->pid);
	rp->pid = -1;
	return rp->status;
}

#else	/* PIPES_SIMULATED */

/*
 * use temporary file rather than pipe
 * except if popen() provides real pipes too
 */

/* gawk_popen --- open an IOBUF on a child process */

static IOBUF *
gawk_popen(const char *cmd, struct redirect *rp)
{
	FILE *current;

	os_restore_mode(fileno(stdin));
	current = popen(cmd, binmode("r"));
	if ((BINMODE & 1) != 0)
		os_setbinmode(fileno(stdin), O_BINARY);
	if (current == NULL)
		return NULL;
	os_close_on_exec(fileno(current), cmd, "pipe", "from");
	rp->iop = iop_alloc(fileno(current), cmd, NULL, TRUE);
	if (rp->iop == NULL) {
		(void) pclose(current);
		current = NULL;
	}
	rp->ifp = current;
	return rp->iop;
}

/* gawk_pclose --- close an open child pipe */

static int
gawk_pclose(struct redirect *rp)
{
	int rval, aval, fd = rp->iop->fd;

	if (rp->iop != NULL) {
		rp->iop->fd = dup(fd);	  /* kludge to allow close() + pclose() */
		rval = iop_close(rp->iop);
	}
	rp->iop = NULL;
	aval = pclose(rp->ifp);
	rp->ifp = NULL;
	return (rval < 0 ? rval : aval);
}

#endif	/* PIPES_SIMULATED */

/* do_getline --- read in a line, into var and with redirection */

NODE *
do_getline_redir(int intovar, int redirtype)
{
	struct redirect *rp = NULL;
	IOBUF *iop;
	int cnt = EOF;
	char *s = NULL;
	int errcode;
	NODE *redir_exp = NULL;
	NODE **lhs = NULL;
	int redir_error = 0;

	if (intovar)
		lhs = POP_ADDRESS();

	assert(redirtype != 0);
	redir_exp = TOP();
	rp = redirect(redir_exp, redirtype, &redir_error);
	DEREF(redir_exp);
	decr_sp();
	if (rp == NULL) {
		if (redir_error) { /* failed redirect */
			if (! do_traditional)
				update_ERRNO_saved(redir_error);
		}
		return make_number((AWKNUM) -1.0);
	}
	iop = rp->iop;
	if (iop == NULL)		/* end of input */
		return make_number((AWKNUM) 0.0);

	errcode = 0;
	cnt = get_a_record(&s, iop, &errcode);
	if (errcode != 0) {
		if (! do_traditional && (errcode != -1))
			update_ERRNO_saved(errcode);
		return make_number((AWKNUM) -1.0);
	}

	if (cnt == EOF) {
		/*
		 * Don't do iop_close() here if we are
		 * reading from a pipe; otherwise
		 * gawk_pclose will not be called.
		 */
		if ((rp->flag & (RED_PIPE|RED_TWOWAY)) == 0) {
			(void) iop_close(iop);
			rp->iop = NULL;
		}
		rp->flag |= RED_EOF;	/* sticky EOF */
		return make_number((AWKNUM) 0.0);
	}

	if (lhs == NULL)	/* no optional var. */
		set_record(s, cnt);
	else {			/* assignment to variable */
		unref(*lhs);
		*lhs = make_string(s, cnt);
		(*lhs)->flags |= MAYBE_NUM;
	}

	return make_number((AWKNUM) 1.0);
}

/* do_getline --- read in a line, into var and without redirection */

NODE *
do_getline(int intovar, IOBUF *iop)
{
	int cnt = EOF;
	char *s = NULL;
	int errcode;

	if (iop == NULL) {	/* end of input */
		if (intovar)
			(void) POP_ADDRESS();
		return make_number((AWKNUM) 0.0);
	}

	errcode = 0;
	cnt = get_a_record(&s, iop, &errcode);
	if (errcode != 0) {
		if (! do_traditional && (errcode != -1))
			update_ERRNO_saved(errcode);
		if (intovar)
			(void) POP_ADDRESS();
		return make_number((AWKNUM) -1.0); 
	}

	if (cnt == EOF)
		return NULL;	/* try next file */
	NR++;
	FNR++;

	if (! intovar)	/* no optional var. */
		set_record(s, cnt);
	else {			/* assignment to variable */
		NODE **lhs;
		lhs = POP_ADDRESS();
		unref(*lhs);
		*lhs = make_string(s, cnt);
		(*lhs)->flags |= MAYBE_NUM;
	}
	return make_number((AWKNUM) 1.0);
}


static char **awkpath = NULL;	/* array containing library search paths */ 
static int max_pathlen;		/* length of the longest item in awkpath */ 

/* init_awkpath --- split path(=$AWKPATH) into components */

static void
init_awkpath(char *path)
{
	char *start, *end, *p;
	int len, i;
	static int max_path = 0;

#define INC_PATH 5

	max_pathlen = 0;
	if (path == NULL || *path == '\0')
		path = defpath;

	for (i = 0; i < max_path && awkpath[i]; i++) {
		efree(awkpath[i]);
		awkpath[i] = NULL;
	}

	if (max_path == 0) {
		max_path = INC_PATH;
		emalloc(awkpath, char **, (max_path + 1) * sizeof(char *), "init_awkpath");
		memset(awkpath, 0, (max_path + 1) * sizeof(char *));
	}

	end = start = path;
	i = 0;
	while (*start) {
		while (*end && *end != envsep)
			end++;
		len = end - start;
		if (len > 0) {
			emalloc(p, char *, len + 2, "init_awkpath");
			memcpy(p, start, len);

			/* add directory punctuation if necessary */
			if (! isdirpunct(*(end - 1)))
				p[len++] = '/';
			p[len] = '\0';

			if (i == max_path) {
				max_path += INC_PATH;
				erealloc(awkpath, char **, (max_path + 1) * sizeof(char *), "init_awkpath");
				memset(awkpath + i, 0, (INC_PATH + 1) * sizeof(char *));
			}
			awkpath[i++] = p;
			if (len > max_pathlen)
				max_pathlen = len;
		}

		/* skip one or more envsep char */
		while (*end && *end == envsep)
			end++;
		start = end;
	}
	awkpath[i] = NULL;

#undef INC_PATH
}

/* do_find_source --- search $AWKPATH for file, return NULL if not found */ 

static char *
do_find_source(const char *src, struct stat *stb, int *errcode)
{
	char *path;
	int i;

	assert(errcode != NULL);

	/* some kind of path name, no search */
	if (ispath(src)) {
		emalloc(path, char *, strlen(src) + 1, "do_find_source");
		strcpy(path, src);
		if (stat(path, stb) == 0)
			return path;
		*errcode = errno;
		efree(path);
		return NULL;
	}

	/* try current directory before path search */
	if (stat(src, stb) == 0) {
		emalloc(path, char *, strlen(src) + 1, "do_find_source");
		strcpy(path, src);
		return path;
	}

	if (awkpath == NULL)
		init_awkpath(getenv("AWKPATH"));

	emalloc(path, char *, max_pathlen + strlen(src) + 1, "do_find_source"); 
	for (i = 0; awkpath[i] != NULL; i++) {
		if (STREQ(awkpath[i], "./") || STREQ(awkpath[i], ".")) {
			*path = '\0';
		} else
			strcpy(path, awkpath[i]);
		strcat(path, src);
		if (stat(path, stb) == 0)
			return path;
	}

	/* not found, give up */
	*errcode = errno;
	efree(path);
	return NULL;
}

/* find_source --- find source file with default file extension handling */ 

char *
find_source(const char *src, struct stat *stb, int *errcode)
{
	char *path;

	*errcode = 0;
	if (src == NULL || *src == '\0')
		return NULL;
	path = do_find_source(src, stb, errcode);

#ifdef DEFAULT_FILETYPE
	if (! do_traditional && path == NULL) {
		char *file_awk;
		int save = errno;
#ifdef VMS
		int vms_save = vaxc$errno;
#endif

		/* append ".awk" and try again */
		emalloc(file_awk, char *, strlen(src) +
			sizeof(DEFAULT_FILETYPE) + 1, "find_source");
		sprintf(file_awk, "%s%s", src, DEFAULT_FILETYPE);
		path = do_find_source(file_awk, stb, errcode);
		efree(file_awk);
		if (path == NULL) {
			errno = save;
#ifdef VMS
			vaxc$errno = vms_save;
#endif
		}
	}
#endif	/*DEFAULT_FILETYPE*/

	return path;
}

/* srcopen --- open source file */

int
srcopen(SRCFILE *s)
{
	if (s->stype == SRC_STDIN)
		return (0);
	if (s->stype == SRC_FILE || s->stype == SRC_INC)
		return devopen(s->fullpath, "r");
	return INVALID_HANDLE;
}

#ifdef TEST
int bufsize = 8192;

void
fatal(const char *s)
{
	printf("%s\n", s);
	exit(EXIT_FAILURE);
}
#endif

/* open hooks, mainly for use by extension functions */

static struct open_hook {
	struct open_hook *next;
	void *(*open_func)(IOBUF *);
} *open_hooks;

/* register_open_hook --- add an open hook to the list */

void
register_open_hook(void *(*open_func)(IOBUF *))
{
	struct open_hook *oh;

	emalloc(oh, struct open_hook *, sizeof(*oh), "register_open_hook");
	oh->open_func = open_func;
	oh->next = open_hooks;
	open_hooks = oh;
}

/* find_open_hook --- search the list of open hooks */

static void
find_open_hook(IOBUF *iop)
{
	struct open_hook *oh;

	/* walk through open hooks, stop at first one that responds */
	for (oh = open_hooks; oh != NULL; oh = oh->next) {
		if ((iop->opaque = (*oh->open_func)(iop)) != NULL)
			break;
	}
}

/* iop_alloc --- allocate an IOBUF structure for an open fd */

static IOBUF *
iop_alloc(int fd, const char *name, IOBUF *iop, int do_openhooks)
{
	struct stat sbuf;
	int iop_malloced = FALSE;

	if (iop == NULL) {
		emalloc(iop, IOBUF *, sizeof(IOBUF), "iop_alloc");
		iop_malloced = TRUE;
	}
	memset(iop, '\0', sizeof(IOBUF));
	iop->flag = 0;
	iop->fd = fd;
	iop->name = name;

	if (do_openhooks)
		find_open_hook(iop);
	else if (iop->fd == INVALID_HANDLE)
		return iop;

	/* test reached if tried to find open hook and could not */
	if (iop->fd == INVALID_HANDLE) {
		if (iop_malloced)
			efree(iop);
		return NULL;
	}

	if (os_isatty(iop->fd))
		iop->flag |= IOP_IS_TTY;
	iop->readsize = iop->size = optimal_bufsize(iop->fd, & sbuf);
	iop->sbuf = sbuf;
	if (do_lint && S_ISREG(sbuf.st_mode) && sbuf.st_size == 0)
		lintwarn(_("data file `%s' is empty"), name);
	errno = 0;
	iop->count = iop->scanoff = 0;
	emalloc(iop->buf, char *, iop->size += 2, "iop_alloc");
	iop->off = iop->buf;
	iop->dataend = NULL;
	iop->end = iop->buf + iop->size;
	iop->flag |= IOP_AT_START;
	return iop;
}

#define set_RT_to_null() \
	(void)(! do_traditional && (unref(RT_node->var_value), \
			   RT_node->var_value = Nnull_string))

#define set_RT(str, len) \
	(void)(! do_traditional && (unref(RT_node->var_value), \
			   RT_node->var_value = make_string(str, len)))

/* grow must increase size of buffer, set end, make sure off and dataend point at */
/* right spot.                                                              */
/*                                                                          */
/*                                                                          */
/* <growbuffer>=                                                            */
/* grow_iop_buffer --- grow the buffer */

static void
grow_iop_buffer(IOBUF *iop)
{
	size_t valid = iop->dataend - iop->off;
	size_t off = iop->off - iop->buf;
	size_t newsize;

	/*
	 * Lop off original extra two bytes, double the size,
	 * add them back.
	 */
	newsize = ((iop->size - 2) * 2) + 2;

	/* Check for overflow */
	if (newsize <= iop->size)
		fatal(_("could not allocate more input memory"));

	/* Make sure there's room for a disk block */
	if (newsize - valid < iop->readsize)
		newsize += iop->readsize + 2;

	/* Check for overflow, again */
	if (newsize <= iop->size)
		fatal(_("could not allocate more input memory"));

	iop->size = newsize;
	erealloc(iop->buf, char *, iop->size, "grow_iop_buffer");
	iop->off = iop->buf + off;
	iop->dataend = iop->off + valid;
	iop->end = iop->buf + iop->size;
}

/* Here are the routines.                                                   */
/*                                                                          */
/*                                                                          */
/* <rs1scan>=                                                               */
/* rs1scan --- scan for a single character record terminator */

static RECVALUE
rs1scan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state)
{
	char *bp;
	char rs;
#ifdef MBS_SUPPORT
	size_t mbclen = 0;
	mbstate_t mbs;
#endif

	memset(recm, '\0', sizeof(struct recmatch));
	rs = RS->stptr[0];
	*(iop->dataend) = rs;   /* set sentinel */
	recm->start = iop->off; /* beginning of record */

	bp = iop->off;
	if (*state == INDATA)   /* skip over data we've already seen */
		bp += iop->scanoff;

#ifdef MBS_SUPPORT
	/*
	 * From: Bruno Haible <bruno@clisp.org>
	 * To: Aharon Robbins <arnold@skeeve.com>, gnits@gnits.org
	 * Subject: Re: multibyte locales: any way to find if a character isn't multibyte?
	 * Date: Mon, 23 Jun 2003 12:20:16 +0200
	 * Cc: isamu@yamato.ibm.com
	 * 
	 * Hi,
	 * 
	 * > Is there any way to make the following query to the current locale?
	 * >
	 * > 	Given an 8-bit value, can this value ever appear as part of
	 * > 	a multibyte character?
	 * 
	 * There is no simple answer here. The easiest solution I see is to
	 * get the current locale's codeset (via locale_charset() which is a
	 * wrapper around nl_langinfo(CODESET)), and then perform a case-by-case
	 * treatment of the known multibyte encodings, from GB2312 to EUC-JISX0213;
	 * for the unibyte encodings, a single btowc() call will tell you.
	 * 
	 * > This is particularly critical for me for ASCII newline ('\n').  If I
	 * > can be guaranteed that it never shows up as part of a multibyte character,
	 * > I can speed up gawk considerably in mulitbyte locales.
	 * 
	 * This is much simpler to answer!
	 * In all ASCII based multibyte encodings used for locales today (this
	 * excludes EBCDIC based doublebyte encodings from IBM, and also excludes
	 * ISO-2022-JP which is used for email exchange but not as a locale encoding)
	 * ALL bytes in the range 0x00..0x2F occur only as a single character, not
	 * as part of a multibyte character.
	 * 
	 * So it's safe to assume, but deserves a comment in the source.
	 * 
	 * Bruno
	 ***************************************************************
	 * From: Bruno Haible <bruno@clisp.org>
	 * To: Aharon Robbins <arnold@skeeve.com>
	 * Subject: Re: multibyte locales: any way to find if a character isn't multibyte?
	 * Date: Mon, 23 Jun 2003 14:27:49 +0200
	 * 
	 * On Monday 23 June 2003 14:11, you wrote:
	 * 
	 * >       if (rs != '\n' && MB_CUR_MAX > 1) {
	 * 
	 * If you assume ASCII, you can even write
	 * 
	 *         if (rs >= 0x30 && MB_CUR_MAX > 1) {
	 * 
	 * (this catches also the space character) but if portability to EBCDIC
	 * systems is desired, your code is fine as is.
	 * 
	 * Bruno
	 */
	/* Thus, the check for \n here; big speedup ! */
	if (rs != '\n' && gawk_mb_cur_max > 1) {
		int len = iop->dataend - bp;
		int found = 0;

		memset(&mbs, 0, sizeof(mbstate_t));
		do {
			if (*bp == rs)
				found = 1;
			if (is_valid_character(*bp))
				mbclen = 1;
			else
				mbclen = mbrlen(bp, len, &mbs);
			if (   (mbclen == 1)
			    || (mbclen == (size_t) -1)
			    || (mbclen == (size_t) -2)
			    || (mbclen == 0)) {
				/* We treat it as a singlebyte character.  */
				mbclen = 1;
			}
			len -= mbclen;
			bp += mbclen;
		} while (len > 0 && ! found);

		/* Check that newline found isn't the sentinel. */
		if (found && (bp - mbclen) < iop->dataend) {
			/*
			 * set len to what we have so far, in case this is
			 * all there is
			 */
			recm->len = bp - recm->start - mbclen;
			recm->rt_start = bp - mbclen;
			recm->rt_len = mbclen;
			*state = NOSTATE;
			return REC_OK;
		} else {
			/* also set len */
			recm->len = bp - recm->start;
			*state = INDATA;
			iop->scanoff = bp - iop->off;
			return NOTERM;
		}
	}
#endif
	while (*bp != rs)
		bp++;

	/* set len to what we have so far, in case this is all there is */
	recm->len = bp - recm->start;

	if (bp < iop->dataend) {        /* found it in the buffer */
		recm->rt_start = bp;
		recm->rt_len = 1;
		*state = NOSTATE;
		return REC_OK;
	} else {
		*state = INDATA;
		iop->scanoff = bp - iop->off;
		return NOTERM;
	}
}

/* <rsrescan>=                                                              */
/* rsrescan --- search for a regex match in the buffer */

static RECVALUE
rsrescan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state)
{
	char *bp;
	size_t restart = 0, reend = 0;
	Regexp *RSre = RS_regexp;
	int regex_flags = RE_NEED_START;

	memset(recm, '\0', sizeof(struct recmatch));
	recm->start = iop->off;

	bp = iop->off;
	if (*state == INDATA)
		bp += iop->scanoff;

	if ((iop->flag & IOP_AT_START) == 0)
		regex_flags |= RE_NO_BOL;
again:
	/* case 1, no match */
	if (research(RSre, bp, 0, iop->dataend - bp, regex_flags) == -1) {
		/* set len, in case this all there is. */
		recm->len = iop->dataend - iop->off;
		return NOTERM;
	}

	/* ok, we matched within the buffer, set start and end */
	restart = RESTART(RSre, iop->off);
	reend = REEND(RSre, iop->off);

	/* case 2, null regex match, grow buffer, try again */
	if (restart == reend) {
		*state = INDATA;
		iop->scanoff = reend + 1;
		/*
		 * If still room in buffer, skip over null match
		 * and restart search. Otherwise, return.
		 */
		if (bp + iop->scanoff < iop->dataend) {
			bp += iop->scanoff;
			goto again;
		}
		recm->len = (bp - iop->off) + restart;
		return NOTERM;
	}

	/*
	 * At this point, we have a non-empty match.
	 *
	 * First, fill in rest of data. The rest of the cases return
	 * a record and terminator.
	 */
	recm->len = restart;
	recm->rt_start = bp + restart;
	recm->rt_len = reend - restart;
	*state = NOSTATE;

	/*
	 * 3. Match exactly at end:
	 *      if re is a simple string match
	 *              found a simple string match at end, return REC_OK
	 *      else
	 *              grow buffer, add more data, try again
	 *      fi
	 */
	if (iop->off + reend >= iop->dataend) {
		if (reisstring(RS->stptr, RS->stlen, RSre, iop->off))
			return REC_OK;
		else
			return TERMATEND;
	}

	/*
	 * 4. Match within xxx bytes of end & maybe islong re:
	 *      return TERMNEAREND
	 */

        /*
         * case 4, match succeeded, but there may be more in
         * the next input buffer.
         *
         * Consider an RS of   xyz(abc)?   where the
         * exact end of the buffer is   xyza  and the
         * next two, unread, characters are bc.
         *
         * This matches the "xyz" and ends up putting the
         * "abc" into the front of the next record. Ooops.
         *
         * The remaybelong() function looks to see if the
         * regex contains one of: + * ? |.  This is a very
         * simple heuristic, but in combination with the
         * "end of match within a few bytes of end of buffer"
         * check, should keep things reasonable.
         */

        /*
         * XXX: The reisstring and remaybelong tests should
         * really be done once when RS is assigned to and
         * then tested as flags here.  Maybe one day.
         */

	/* succession of tests is easier to trace in GDB. */
	if (remaybelong(RS->stptr, RS->stlen)) {
		char *matchend = iop->off + reend;

		if (iop->dataend - matchend < RS->stlen)
			return TERMNEAREND;
	}

	return REC_OK;
}

/* <rsnullscan>=                                                            */
/* rsnullscan --- handle RS = "" */

static RECVALUE
rsnullscan(IOBUF *iop, struct recmatch *recm, SCANSTATE *state)
{
	char *bp;

	if (*state == NOSTATE || *state == INLEADER)
		memset(recm, '\0', sizeof(struct recmatch));

	recm->start = iop->off;

	bp = iop->off;
	if (*state != NOSTATE)
		bp += iop->scanoff;

	/* set sentinel */
	*(iop->dataend) = '\n';

	if (*state == INTERM)
		goto find_longest_terminator;
	else if (*state == INDATA)
		goto scan_data;
	/* else
		fall into things from beginning,
		either NOSTATE or INLEADER */

/* skip_leading: */
	/* leading newlines are ignored */
	while (*bp == '\n' && bp < iop->dataend)
		bp++;

	if (bp >= iop->dataend) {       /* LOTS of leading newlines, sheesh. */
		*state = INLEADER;
		iop->scanoff = bp - iop->off;
		return NOTERM;
	}

	iop->off = recm->start = bp;    /* real start of record */
scan_data:
	while (*bp++ != '\n')
		continue;

	if (bp >= iop->dataend) {       /* no terminator */
		iop->scanoff = recm->len = bp - iop->off - 1;
		*state = INDATA;
		return NOTERM;
	}

	/* found one newline before end of buffer, check next char */
	if (*bp != '\n')
		goto scan_data;

	/* we've now seen at least two newlines */
	*state = INTERM;
	recm->len = bp - iop->off - 1;
	recm->rt_start = bp - 1;

find_longest_terminator:
	/* find as many newlines as we can, to set RT */
	while (*bp == '\n' && bp < iop->dataend)
		bp++;

	recm->rt_len = bp - recm->rt_start;
	iop->scanoff = bp - iop->off;

	if (bp >= iop->dataend)
		return TERMATEND;

	return REC_OK;
}

/* <getarecord>=                                                            */
/* get_a_record --- read a record from IOP into out, return length of EOF, set RT */

static int
get_a_record(char **out,        /* pointer to pointer to data */
        IOBUF *iop,             /* input IOP */
        int *errcode)           /* pointer to error variable */
{
	struct recmatch recm;
	SCANSTATE state;
	RECVALUE ret;
	int retval;
	NODE *rtval = NULL;
	static RECVALUE (*lastmatchrec)(IOBUF *iop, struct recmatch *recm, SCANSTATE *state) = NULL;

	if (at_eof(iop) && no_data_left(iop))
		return EOF;

	if (iop->get_record != NULL)
		return (*iop->get_record)(out, iop, errcode);

        /* <fill initial buffer>= */
	if (has_no_data(iop) || no_data_left(iop)) {
		iop->count = read(iop->fd, iop->buf, iop->readsize);
		if (iop->count == 0) {
			iop->flag |= IOP_AT_EOF;
			return EOF;
		} else if (iop->count == -1) {
			iop->flag |= IOP_AT_EOF; 
			if (errcode != NULL)
				*errcode = errno;
			return EOF;
		} else {
			iop->dataend = iop->buf + iop->count;
			iop->off = iop->buf;
		}
	}

	/* <loop through file to find a record>= */
	state = NOSTATE;
	for (;;) {
		size_t dataend_off;

		ret = (*matchrec)(iop, & recm, & state);
		iop->flag &= ~IOP_AT_START;
		if (ret == REC_OK)
			break;

		/* need to add more data to buffer */
		/* <shift data down in buffer>=    */
		dataend_off = iop->dataend - iop->off;
		memmove(iop->buf, iop->off, dataend_off);
		iop->off = iop->buf;
		iop->dataend = iop->buf + dataend_off;

		/* <adjust recm contents>= */
		recm.start = iop->off;
		if (recm.rt_start != NULL)
			recm.rt_start = iop->off + recm.len;

		/* <read more data, break if EOF>= */
		{
#define min(x, y) (x < y ? x : y)
			/* subtract one in read count to leave room for sentinel */
			size_t room_left = iop->end - iop->dataend - 1;
			size_t amt_to_read = min(iop->readsize, room_left);

			if (amt_to_read < iop->readsize) {
				grow_iop_buffer(iop);
				/* <adjust recm contents>= */
				recm.start = iop->off;
				if (recm.rt_start != NULL)
					recm.rt_start = iop->off + recm.len;

				/* recalculate amt_to_read */
				room_left = iop->end - iop->dataend - 1;
				amt_to_read = min(iop->readsize, room_left);
			}
			while (amt_to_read + iop->readsize < room_left)
				amt_to_read += iop->readsize;

#ifdef SSIZE_MAX
			/*
			 * POSIX limits read to SSIZE_MAX. There are (bizarre)
			 * systems where this amount is small.
			 */
			amt_to_read = min(amt_to_read, SSIZE_MAX);
#endif

			iop->count = read(iop->fd, iop->dataend, amt_to_read);
			if (iop->count == -1) {
				*errcode = errno;
				iop->flag |= IOP_AT_EOF;
				break;
			} else if (iop->count == 0) {
				/*
				 * hit EOF before matching RS, so end
				 * the record and set RT to ""
				 */
				iop->flag |= IOP_AT_EOF;
				break;
			} else
				iop->dataend += iop->count;
		}
	}

	/* <set record, RT, return right value>= */

	/*
	 * rtval is not a static pointer to avoid dangling pointer problems
	 * in case awk code assigns to RT.  A remote possibility, to be sure,
	 * but Bitter Experience teaches us not to make ``that'll never
	 * happen'' kinds of assumptions.
	 */
	rtval = RT_node->var_value;

	if (recm.rt_len == 0) {
		set_RT_to_null();
		lastmatchrec = NULL;
	} else {
		assert(recm.rt_start != NULL);
		/*
		 * Optimization. For rs1 case, don't set RT if
		 * character is same as last time.  This knocks a
		 * chunk of time off something simple like
		 *
		 *      gawk '{ print }' /some/big/file
		 *
		 * Similarly, for rsnull case, if length of new RT is
		 * shorter than current RT, just bump length down in RT.
		 *
		 * Make sure that matchrec didn't change since the last
		 * check.  (Ugh, details, details, details.)
		 */
		if (lastmatchrec == NULL || lastmatchrec != matchrec) {
			lastmatchrec = matchrec;
			set_RT(recm.rt_start, recm.rt_len);
		} else if (matchrec == rs1scan) {
			if (rtval->stlen != 1 || rtval->stptr[0] != recm.rt_start[0])
				set_RT(recm.rt_start, recm.rt_len);
			/* else
				leave it alone */
		} else if (matchrec == rsnullscan) {
			if (rtval->stlen <= recm.rt_len)
				rtval->stlen = recm.rt_len;
			else
				set_RT(recm.rt_start, recm.rt_len);
		} else
			set_RT(recm.rt_start, recm.rt_len);
	}

	if (recm.len == 0) {
		*out = NULL;
		retval = 0;
	} else {
		assert(recm.start != NULL);
		*out = recm.start;
		retval = recm.len;
	}

	iop->off += recm.len + recm.rt_len;

	if (recm.len == 0 && recm.rt_len == 0 && at_eof(iop))
		return EOF;
	else
		return retval;
}

/* set_RS --- update things as appropriate when RS is set */

void
set_RS()
{
	static NODE *save_rs = NULL;

	/*
	 * Don't use cmp_nodes(), which pays attention to IGNORECASE.
	 */
	if (save_rs
		&& RS_node->var_value->stlen == save_rs->stlen
		&& memcmp(RS_node->var_value->stptr, save_rs->stptr, save_rs->stlen) == 0) {
		/*
		 * It could be that just IGNORECASE changed.  If so,
		 * update the regex and then do the same for FS.
		 * set_IGNORECASE() relies on this routine to call
		 * set_FS().
		 */
		RS_regexp = (IGNORECASE ? RS_re_no_case : RS_re_yes_case);
		goto set_FS;
	}
	unref(save_rs);
	save_rs = dupnode(RS_node->var_value);
	RS_is_null = FALSE;
	RS = force_string(RS_node->var_value);
	/*
	 * used to be if (RS_regexp != NULL) { refree(..); refree(..); ...; }.
	 * Please do not remerge the if condition; hinders memory deallocation
	 * in case of fatal error in make_regexp.
	 */
	refree(RS_re_yes_case);	/* NULL argument is ok */
	refree(RS_re_no_case); 
	RS_re_yes_case = RS_re_no_case = RS_regexp = NULL;

	if (RS->stlen == 0) {
		RS_is_null = TRUE;
		matchrec = rsnullscan;
	} else if (RS->stlen > 1) {
		static short warned = FALSE;

		RS_re_yes_case = make_regexp(RS->stptr, RS->stlen, FALSE, TRUE, TRUE);
		RS_re_no_case = make_regexp(RS->stptr, RS->stlen, TRUE, TRUE, TRUE);
		RS_regexp = (IGNORECASE ? RS_re_no_case : RS_re_yes_case);

		matchrec = rsrescan;

		if (do_lint && ! warned) {
			lintwarn(_("multicharacter value of `RS' is a gawk extension"));
			warned = TRUE;
		}
	} else
		matchrec = rs1scan;
set_FS:
	if (current_field_sep() == Using_FS)
		set_FS();
}

/* pty_vs_pipe --- return true if should use pty instead of pipes for `|&' */

/*
 * This works by checking if PROCINFO["command", "pty"] exists and is true.
 */

static int
pty_vs_pipe(const char *command)
{
#ifdef HAVE_TERMIOS_H
	char *full_index;
	size_t full_len;
	NODE *val;
	NODE *sub;

	if (PROCINFO_node == NULL)
		return FALSE;

	full_len = strlen(command)
			+ SUBSEP_node->var_value->stlen
			+ 3	/* strlen("pty") */
			+ 1;	/* string terminator */
	emalloc(full_index, char *, full_len, "pty_vs_pipe");
	sprintf(full_index, "%s%.*spty", command,
		(int) SUBSEP_node->var_value->stlen, SUBSEP_node->var_value->stptr);

	sub = make_string(full_index, strlen(full_index));
	val = in_array(PROCINFO_node, sub);
	unref(sub);
	efree(full_index);

	if (val) {
		if (val->flags & MAYBE_NUM)
			(void) force_number(val);
		if (val->flags & NUMBER)
			return (val->numbr != 0.0);
		else
			return (val->stlen != 0);
	}
#endif /* HAVE_TERMIOS_H */
	return FALSE;
}

/* iopflags2str --- make IOP flags printable */

const char *
iopflags2str(int flag)
{
	static const struct flagtab values[] = {
		{ IOP_IS_TTY, "IOP_IS_TTY" },
		{ IOP_NOFREE_OBJ, "IOP_NOFREE_OBJ" },
		{ IOP_AT_EOF,  "IOP_AT_EOF" },
		{ IOP_CLOSED, "IOP_CLOSED" },
		{ IOP_AT_START,  "IOP_AT_START" },
		{ 0, NULL }
	};

	return genflags2str(flag, values);
}

/* free_rp --- release the memory used by rp */

static void
free_rp(struct redirect *rp)
{
	efree(rp->value);
	efree(rp);
}

/* inetfile --- return true for a /inet special file, set other values */

static int
inetfile(const char *str, int *length, int *family)
{
	int ret = FALSE;

	if (STREQN(str, "/inet/", 6)) {
		ret = TRUE;
		if (length != NULL)
			*length = 6;
		if (family != NULL)
			*family = AF_UNSPEC;
	} else if (STREQN(str, "/inet4/", 7)) {
		ret = TRUE;
		if (length != NULL)
			*length = 7;
		if (family != NULL)
			*family = AF_INET;
	} else if (STREQN(str, "/inet6/", 7)) {
		ret = TRUE;
		if (length != NULL)
			*length = 7;
		if (family != NULL)
			*family = AF_INET6;
#ifndef HAVE_GETADDRINFO
		fatal(_("IPv6 communication is not supported"));
#endif
	}

	return ret;
}
