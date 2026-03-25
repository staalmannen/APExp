/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "slibtool_lconf_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_visibility_impl.h"

enum slbt_lconf_opt {
	SLBT_LCONF_OPT_UNKNOWN,
	SLBT_LCONF_OPT_NO,
	SLBT_LCONF_OPT_YES,
};

static const char aclr_reset[]   = "\x1b[0m";
static const char aclr_bold[]    = "\x1b[1m";

static const char aclr_red[]     = "\x1b[31m";
static const char aclr_green[]   = "\x1b[32m";
static const char aclr_yellow[]  = "\x1b[33m";
static const char aclr_blue[]    = "\x1b[34m";
static const char aclr_magenta[] = "\x1b[35m";

static void slbt_lconf_close(int fdcwd, int fdlconfdir)
{
	if (fdlconfdir != fdcwd)
		close(fdlconfdir);
}

static int slbt_lconf_trace_lconf_plain(
	struct slbt_driver_ctx *	dctx,
	const char *			lconf)
{
	int fderr = slbt_driver_fderr(dctx);

	if (slbt_dprintf(
			fderr,
			"%s: %s: {.name=%c%s%c}.\n",
			dctx->x_program,
			"lconf",
			'"',lconf,'"') < 0)
		return -1;

	return 0;
}

static int slbt_lconf_trace_lconf_annotated(
	struct slbt_driver_ctx *	dctx,
	const char *			lconf)
{
	int fderr = slbt_driver_fderr(dctx);

	if (slbt_dprintf(
			fderr,
			"%s%s%s%s: %s%s%s: {.name=%s%s%c%s%c%s}.\n",

			aclr_bold,aclr_magenta,
			dctx->x_program,
			aclr_reset,

			aclr_bold,
			"lconf",
			aclr_reset,

			aclr_bold,aclr_green,
			'"',lconf,'"',
			aclr_reset) < 0)
		return -1;

	return 0;
}

static int slbt_lconf_trace_openat_silent(
	struct slbt_driver_ctx *	dctx,
	int				fdat,
	const char *			path,
	int				oflag,
	int				mode)
{
	(void)dctx;
	return openat(fdat,path,oflag,mode);
}

static int slbt_lconf_trace_openat_plain(
	struct slbt_driver_ctx *	dctx,
	int				fdat,
	const char *			path,
	int				oflag,
	int				mode)
{
	char scwd[20];
	char serr[512];

	int  ret   = openat(fdat,path,oflag,mode);
	int  fderr = slbt_driver_fderr(dctx);

	if (fdat == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fdat);
	}

	if ((ret < 0) && (errno == ENOENT)) {
		strcpy(serr," [ENOENT]");
	} else if (ret < 0) {
		memset(serr,0,sizeof(serr));
		strerror_r(errno,&serr[2],sizeof(serr)-4);
		serr[0] = ' ';
		serr[1] = '(';
		serr[strlen(serr)] = ')';
	} else {
		serr[0] = 0;
	}

	slbt_dprintf(
		fderr,
		"%s: %s: openat(%s,%c%s%c,%s,%d) = %d%s.\n",
		dctx->x_program,
		"lconf",
		scwd,
		'"',path,'"',
		(oflag == O_DIRECTORY) ? "O_DIRECTORY" : "O_RDONLY",
		mode,ret,serr);

	return ret;
}

static int slbt_lconf_trace_openat_annotated(
	struct slbt_driver_ctx *	dctx,
	int				fdat,
	const char *			path,
	int				oflag,
	int				mode)
{
	char scwd[20];
	char serr[512];

	int  ret   = openat(fdat,path,oflag,mode);
	int  fderr = slbt_driver_fderr(dctx);

	if (fdat == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fdat);
	}

	if ((ret < 0) && (errno == ENOENT)) {
		strcpy(serr," [ENOENT]");
	} else if (ret < 0) {
		memset(serr,0,sizeof(serr));
		strerror_r(errno,&serr[2],sizeof(serr)-4);
		serr[0] = ' ';
		serr[1] = '(';
		serr[strlen(serr)] = ')';
	} else {
		serr[0] = 0;
	}

	slbt_dprintf(
		fderr,
		"%s%s%s%s: %s%s%s: openat(%s%s%s%s,%s%s%c%s%c%s,%s%s%s%s,%d) = %s%d%s%s%s%s%s.\n",

		aclr_bold,aclr_magenta,
		dctx->x_program,
		aclr_reset,

		aclr_bold,
		"lconf",
		aclr_reset,

		aclr_bold,aclr_blue,
		scwd,
		aclr_reset,

		aclr_bold,aclr_green,
		'"',path,'"',
		aclr_reset,

		aclr_bold,aclr_blue,
		(oflag == O_DIRECTORY) ? "O_DIRECTORY" : "O_RDONLY",
		aclr_reset,

		mode,

		aclr_bold,
		ret,
		aclr_reset,

		aclr_bold,aclr_red,
		serr,
		aclr_reset);

	return ret;
}

static int slbt_lconf_trace_fstat_silent(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	const char *			path,
	struct stat *			st)
{
	(void)dctx;

	return path ? fstatat(fd,path,st,0) : fstat(fd,st);
}

static int slbt_lconf_trace_fstat_plain(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	const char *			path,
	struct stat *			st)
{
	char scwd[20];
	char serr[512];
	char quot[2] = {'"',0};

	int  ret   = path ? fstatat(fd,path,st,0) : fstat(fd,st);
	int  fderr = slbt_driver_fderr(dctx);

	if (fd == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fd);
	}

	if ((ret < 0) && (errno == ENOENT)) {
		strcpy(serr," [ENOENT]");
	} else if (ret < 0) {
		memset(serr,0,sizeof(serr));
		strerror_r(errno,&serr[2],sizeof(serr)-4);
		serr[0] = ' ';
		serr[1] = '(';
		serr[strlen(serr)] = ')';
	} else {
		serr[0] = 0;
	}

	slbt_dprintf(
		fderr,
		"%s: %s: %s(%s%s%s%s%s,...) = %d%s%s",
		dctx->x_program,
		"lconf",
		path ? "fstatat" : "fstat",
		scwd,
		path ? "," : "",
		path ? quot : "",
		path ? path : "",
		path ? quot : "",
		ret,
		serr,
		ret ? ".\n" : "");

	if (ret == 0)
		slbt_dprintf(
			fderr,
			" {.st_dev = %ld, .st_ino = %ld}.\n",
			st->st_dev,
			st->st_ino);

	return ret;
}

static int slbt_lconf_trace_fstat_annotated(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	const char *			path,
	struct stat *			st)
{
	char scwd[20];
	char serr[512];
	char quot[2] = {'"',0};

	int  ret   = path ? fstatat(fd,path,st,0) : fstat(fd,st);
	int  fderr = slbt_driver_fderr(dctx);

	if (fd == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fd);
	}

	if ((ret < 0) && (errno == ENOENT)) {
		strcpy(serr," [ENOENT]");
	} else if (ret < 0) {
		memset(serr,0,sizeof(serr));
		strerror_r(errno,&serr[2],sizeof(serr)-4);
		serr[0] = ' ';
		serr[1] = '(';
		serr[strlen(serr)] = ')';
	} else {
		serr[0] = 0;
	}

	slbt_dprintf(
		fderr,
		"%s%s%s%s: %s%s%s: %s(%s%s%s%s%s%s%s%s%s%s%s,...) = %s%d%s%s%s%s%s%s",

		aclr_bold,aclr_magenta,
		dctx->x_program,
		aclr_reset,

		aclr_bold,
		"lconf",
		aclr_reset,

		path ? "fstatat" : "fstat",

		aclr_bold,aclr_blue,
		scwd,
		aclr_reset,

		aclr_bold,aclr_green,
		path ? "," : "",
		path ? quot : "",
		path ? path : "",
		path ? quot : "",
		aclr_reset,

		aclr_bold,
		ret,
		aclr_reset,

		aclr_bold,aclr_red,
		serr,
		aclr_reset,

		ret ? ".\n" : "");

	if (ret == 0)
		slbt_dprintf(
			fderr,
			" {%s%s.st_dev%s = %s%ld%s, %s%s.st_ino%s = %s%ld%s}.\n",

			aclr_bold,aclr_yellow,aclr_reset,

			aclr_bold,
			st->st_dev,
			aclr_reset,

			aclr_bold,aclr_yellow,aclr_reset,

			aclr_bold,
			st->st_ino,
			aclr_reset);

	return ret;
}

static int slbt_lconf_trace_result_silent(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	int				fdat,
	const char *			lconf,
	int				err,
	char				(*pathbuf)[PATH_MAX])
{
	(void)dctx;
	(void)fd;
	(void)fdat;
	(void)lconf;

	if (err)
		return -1;

	if (slbt_realpath(fdat,lconf,0,*pathbuf,sizeof(*pathbuf)) <0)
		return -1;

	return fd;
}

static int slbt_lconf_trace_result_plain(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	int				fdat,
	const char *			lconf,
	int				err,
	char				(*pathbuf)[PATH_MAX])
{
	int             fderr;
	const char *    cpath;

	fderr = slbt_driver_fderr(dctx);

	cpath = !(slbt_realpath(fdat,lconf,0,*pathbuf,sizeof(*pathbuf)))
		? *pathbuf : lconf;

	switch (err) {
		case 0:
			slbt_dprintf(
				fderr,
				"%s: %s: found %c%s%c.\n",
				dctx->x_program,
				"lconf",
				'"',cpath,'"');
			return fd;

		case EXDEV:
			slbt_dprintf(
				fderr,
				"%s: %s: stopped in %c%s%c "
				"(config file not found on current device).\n",
				dctx->x_program,
				"lconf",
				'"',cpath,'"');
			return -1;

		default:
			slbt_dprintf(
				fderr,
				"%s: %s: stopped in %c%s%c "
				"(top-level directory reached).\n",
				dctx->x_program,
				"lconf",
				'"',cpath,'"');
			return -1;
	}
}

static int slbt_lconf_trace_result_annotated(
	struct slbt_driver_ctx *	dctx,
	int				fd,
	int				fdat,
	const char *			lconf,
	int				err,
	char				(*pathbuf)[PATH_MAX])
{
	int             fderr;
	const char *    cpath;

	fderr = slbt_driver_fderr(dctx);

	cpath = !(slbt_realpath(fdat,lconf,0,*pathbuf,sizeof(*pathbuf)))
		? *pathbuf : lconf;

	switch (err) {
		case 0:
			slbt_dprintf(
				fderr,
				"%s%s%s%s: %s%s%s: found %s%s%c%s%c%s.\n",

				aclr_bold,aclr_magenta,
				dctx->x_program,
				aclr_reset,

				aclr_bold,
				"lconf",
				aclr_reset,

				aclr_bold,aclr_green,
				'"',cpath,'"',
				aclr_reset);
			return fd;

		case EXDEV:
			slbt_dprintf(
				fderr,
				"%s%s%s%s: %s%s%s: stopped in %s%s%c%s%c%s "
				"%s%s(config file not found on current device)%s.\n",

				aclr_bold,aclr_magenta,
				dctx->x_program,
				aclr_reset,

				aclr_bold,
				"lconf",
				aclr_reset,

				aclr_bold,aclr_green,
				'"',cpath,'"',
				aclr_reset,

				aclr_bold,aclr_red,
				aclr_reset);
			return -1;

		default:
			slbt_dprintf(
				fderr,
				"%s%s%s%s: %s%s%s: stopped in %s%s%c%s%c%s "
				"%s%s(top-level directory reached)%s.\n",

				aclr_bold,aclr_magenta,
				dctx->x_program,
				aclr_reset,

				aclr_bold,
				"lconf",
				aclr_reset,

				aclr_bold,aclr_green,
				'"',cpath,'"',
				aclr_reset,

				aclr_bold,aclr_red,
				aclr_reset);
			return -1;
	}
}

static int slbt_lconf_open(
	struct slbt_driver_ctx *	dctx,
	const char *			lconf,
	bool                            fsilent,
	char				(*lconfpath)[PATH_MAX])
{
	int		fderr;
	int		fdcwd;
	int		fdlconf;
	int		fdlconfdir;
	int		fdparent;
	struct stat	stcwd;
	struct stat	stparent;
	ino_t		stinode;
	const char *    mconf;

	int             (*trace_lconf)(struct slbt_driver_ctx *,
	                                const char *);

	int             (*trace_fstat)(struct slbt_driver_ctx *,
	                                int,const char *, struct stat *);

	int             (*trace_openat)(struct slbt_driver_ctx *,
	                                int,const char *,int,int);

	int             (*trace_result)(struct slbt_driver_ctx *,
	                                int,int,const char *,int,
	                                char (*)[PATH_MAX]);

	fderr      = slbt_driver_fderr(dctx);
	fdcwd      = slbt_driver_fdcwd(dctx);
	fdlconfdir = fdcwd;
	fsilent   |= (dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT);
	fsilent   |= (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_MASK);

	if (lconf) {
		mconf = 0;
	} else {
		mconf = "slibtool.cfg";
		lconf = "libtool";
	}

	if (fsilent) {
		trace_lconf  = 0;
		trace_fstat  = slbt_lconf_trace_fstat_silent;
		trace_openat = slbt_lconf_trace_openat_silent;
		trace_result = slbt_lconf_trace_result_silent;

	} else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER) {
		trace_lconf  = slbt_lconf_trace_lconf_plain;
		trace_fstat  = slbt_lconf_trace_fstat_plain;
		trace_openat = slbt_lconf_trace_openat_plain;
		trace_result = slbt_lconf_trace_result_plain;

	} else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_ALWAYS) {
		trace_lconf  = slbt_lconf_trace_lconf_annotated;
		trace_fstat  = slbt_lconf_trace_fstat_annotated;
		trace_openat = slbt_lconf_trace_openat_annotated;
		trace_result = slbt_lconf_trace_result_annotated;

	} else if (isatty(fderr)) {
		trace_lconf  = slbt_lconf_trace_lconf_annotated;
		trace_fstat  = slbt_lconf_trace_fstat_annotated;
		trace_openat = slbt_lconf_trace_openat_annotated;
		trace_result = slbt_lconf_trace_result_annotated;

	} else {
		trace_lconf  = slbt_lconf_trace_lconf_plain;
		trace_fstat  = slbt_lconf_trace_fstat_plain;
		trace_openat = slbt_lconf_trace_openat_plain;
		trace_result = slbt_lconf_trace_result_plain;
	}

	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_DEBUG)) {
		trace_fstat  = slbt_lconf_trace_fstat_silent;
		trace_openat = slbt_lconf_trace_openat_silent;
	}

	if (!fsilent) {
		if (!mconf)
			trace_lconf(dctx,lconf);

		slbt_output_fdcwd(dctx);
	}

	if (lconf && strchr(lconf,'/'))
		return ((fdlconf = trace_openat(dctx,fdcwd,lconf,O_RDONLY,0)) < 0)
			? SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_LCONF_OPEN)
			: trace_result(dctx,fdlconf,fdcwd,lconf,0,lconfpath);

	if (trace_fstat(dctx,fdlconfdir,".",&stcwd) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	stinode = stcwd.st_ino;
	fdlconf = -1;

	if (mconf)
		if ((fdlconf = trace_openat(dctx,fdlconfdir,mconf,O_RDONLY,0)) >= 0)
			lconf = mconf;

	if (fdlconf < 0)
		fdlconf = trace_openat(dctx,fdlconfdir,lconf,O_RDONLY,0);

	while (fdlconf < 0) {
		fdparent = trace_openat(dctx,fdlconfdir,"../",O_DIRECTORY,0);
		slbt_lconf_close(fdcwd,fdlconfdir);

		if (fdparent < 0)
			return SLBT_SYSTEM_ERROR(dctx);

		if (trace_fstat(dctx,fdparent,0,&stparent) < 0) {
			close(fdparent);
			return SLBT_SYSTEM_ERROR(dctx);
		}

		if (stparent.st_dev != stcwd.st_dev) {
			trace_result(dctx,fdparent,fdparent,".",EXDEV,lconfpath);
			close(fdparent);

			return (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_MASK)
				? (-1)
				: SLBT_CUSTOM_ERROR(
					dctx,SLBT_ERR_LCONF_OPEN);
		}

		if (stparent.st_ino == stinode) {
			trace_result(dctx,fdparent,fdparent,".",ELOOP,lconfpath);
			close(fdparent);

			return (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_MASK)
				? (-1)
				: SLBT_CUSTOM_ERROR(
					dctx,SLBT_ERR_LCONF_OPEN);
		}

		fdlconfdir = fdparent;
		stinode    = stparent.st_ino;

		if (mconf)
			if ((fdlconf = trace_openat(dctx,fdlconfdir,mconf,O_RDONLY,0)) >= 0)
				lconf = mconf;

		if (fdlconf < 0)
			fdlconf = trace_openat(dctx,fdlconfdir,lconf,O_RDONLY,0);
	}

	trace_result(dctx,fdlconf,fdlconfdir,lconf,0,lconfpath);

	slbt_lconf_close(fdcwd,fdlconfdir);

	return fdlconf;
}

static int slbt_get_lconf_var(
	const struct slbt_txtfile_ctx * tctx,
	const char *                    var,
	const char                      space,
	char                            (*val)[PATH_MAX])
{
	const char **   pline;
	const char *    mark;
	const char *    match;
	const char *    cap;
	ssize_t         len;
	int             cint;

	/* init */
	match = 0;
	pline = tctx->x_txtlinev;
	len   = strlen(var);

	/* search for ^var= */
	for (; *pline && !match; ) {
		if (!strncmp(*pline,var,len)) {
			match = *pline;
		} else {
			pline++;
		}
	}

	/* not found? */
	if (!match) {
		(*val)[0] = '\0';
		return 0;
	}

	/* support a single pair of double quotes */
	match = &match[len];
	mark  = match;

	if (match[0] == '"') {
		match++;
		mark++;

		for (; *mark && (*mark != '"'); )
			mark++;

		/* unpaired quote? */
		if (*mark != '"')
			return -1;
	} else {
		for (; *mark && !isspace((cint=*mark)); )
			mark++;
	}

	cap = mark;

	/* validate */
	for (mark=match; mark<cap; mark++) {
		if ((*mark >= 'a') && (*mark <= 'z'))
			(void)0;

		else if ((*mark >= 'A') && (*mark <= 'Z'))
			(void)0;

		else if ((*mark >= '0') && (*mark <= '9'))
			(void)0;

		else if ((*mark == '+') || (*mark == '-'))
			(void)0;

		else if ((*mark == '/') || (*mark == '@'))
			(void)0;

		else if ((*mark == '.') || (*mark == '_'))
			(void)0;

		else if ((*mark == ':') || (*mark == space))
			(void)0;

		else
			return -1;
	}

	/* all done */
	memcpy(*val,match,cap-match);
	(*val)[cap-match] = '\0';

	return 0;
}

slbt_hidden int slbt_get_lconf_flags(
	struct slbt_driver_ctx *	dctx,
	const char *			lconf,
	uint64_t *			flags,
	bool                            fsilent)
{
	struct slbt_driver_ctx_impl *   ctx;
	struct slbt_txtfile_ctx *       confctx;
	int				fdlconf;
	struct stat			st;
	void *				addr;
	uint64_t			optshared;
	uint64_t			optstatic;
	uint64_t			optsltdl;
	char                            val[PATH_MAX];

	/* driver context (ar, ranlib, cc) */
	ctx = slbt_get_driver_ictx(dctx);

	/* open relative libtool script */
	if ((fdlconf = slbt_lconf_open(dctx,lconf,fsilent,&val)) < 0)
		return (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_MASK)
			? (-1) : SLBT_NESTED_ERROR(dctx);

	/* cache the configuration in library friendly form) */
	if (slbt_lib_get_txtfile_ctx(dctx,val,&ctx->lconfctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	confctx = ctx->lconfctx;

	/* map relative libtool script */
	if (fstat(fdlconf,&st) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	addr = mmap(
		0,st.st_size,
		PROT_READ,MAP_SHARED,
		fdlconf,0);

	close(fdlconf);

	if (addr == MAP_FAILED)
		return SLBT_CUSTOM_ERROR(
			dctx,SLBT_ERR_LCONF_MAP);

	/* scan */
	optshared = 0;
	optstatic = 0;

	/* shared libraries option */
	if (slbt_get_lconf_var(confctx,"build_libtool_libs=",0,&val) < 0)
		return SLBT_CUSTOM_ERROR(
			dctx,SLBT_ERR_LCONF_PARSE);

	if (!strcmp(val,"yes")) {
		optshared = SLBT_DRIVER_SHARED;

	} else if (!strcmp(val,"no")) {
		optshared = SLBT_DRIVER_DISABLE_SHARED;
	}


	/* static libraries option */
	if (slbt_get_lconf_var(confctx,"build_old_libs=",0,&val) < 0)
		return SLBT_CUSTOM_ERROR(
			dctx,SLBT_ERR_LCONF_PARSE);

	if (!strcmp(val,"yes")) {
		optstatic = SLBT_DRIVER_STATIC;

	} else if (!strcmp(val,"no")) {
		optstatic = SLBT_DRIVER_DISABLE_STATIC;
	}

	if (!optshared || !optstatic)
		return SLBT_CUSTOM_ERROR(
			dctx,SLBT_ERR_LCONF_PARSE);

	/* sltdl option */
	if (slbt_get_lconf_var(confctx,"prefer_sltdl=",0,&val) < 0) {
		return SLBT_CUSTOM_ERROR(
			dctx,SLBT_ERR_LCONF_PARSE);

	} else if (!strcmp(val,"yes")) {
		optsltdl = SLBT_DRIVER_PREFER_SLTDL;

	} else {
		optsltdl = 0;
	}

	/* return flags */
	*flags = optshared | optstatic | optsltdl;

	/* host */
	if (!ctx->cctx.x_host.ha_host) {
		if (slbt_get_lconf_var(confctx,"host=",0,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.host = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_host = ctx->host.host;
	}


	/* ar tool */
	if (!ctx->cctx.x_host.ha_ar) {
		if (slbt_get_lconf_var(confctx,"AR=",0x20,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.ar = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_ar = ctx->host.ar;
	}


	/* nm tool */
	if (!ctx->cctx.x_host.ha_nm) {
		if (slbt_get_lconf_var(confctx,"NM=",0x20,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.nm = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_nm = ctx->host.nm;
	}


	/* ranlib tool */
	if (!ctx->cctx.x_host.ha_ranlib) {
		if (slbt_get_lconf_var(confctx,"RANLIB=",0x20,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.ranlib = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_ranlib = ctx->host.ranlib;
	}


	/* as tool (optional) */
	if (!ctx->cctx.x_host.ha_as) {
		if (slbt_get_lconf_var(confctx,"AS=",0x20,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.as = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);


		ctx->cctx.x_host.ha_as = ctx->host.as;
	}


	/* dlltool tool (optional) */
	if (!ctx->cctx.x_host.ha_dlltool) {
		if (slbt_get_lconf_var(confctx,"DLLTOOL=",0x20,&val) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,SLBT_ERR_LCONF_PARSE);

		if (val[0] && !(ctx->host.dlltool = strdup(val)))
			return SLBT_SYSTEM_ERROR(dctx);

		ctx->cctx.x_host.ha_dlltool = ctx->host.dlltool;
	}


	/* all done */
	ctx->lconf.addr = addr;
	ctx->lconf.size = st.st_size;

	return 0;
}
