/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <slibtool/slibtool.h>
#include "slibtool_ar_impl.h"
#include "slibtool_coff_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"

static const char ar_symbol_type_A[] = "A";
static const char ar_symbol_type_B[] = "B";
static const char ar_symbol_type_C[] = "C";
static const char ar_symbol_type_D[] = "D";
static const char ar_symbol_type_G[] = "G";
static const char ar_symbol_type_I[] = "I";
static const char ar_symbol_type_R[] = "R";
static const char ar_symbol_type_S[] = "S";
static const char ar_symbol_type_T[] = "T";
static const char ar_symbol_type_W[] = "W";

static const char * const ar_symbol_type['Z'-'A'] = {
	['A'-'A'] = ar_symbol_type_A,
	['B'-'A'] = ar_symbol_type_B,
	['C'-'A'] = ar_symbol_type_C,
	['D'-'A'] = ar_symbol_type_D,
	['G'-'A'] = ar_symbol_type_G,
	['I'-'A'] = ar_symbol_type_I,
	['R'-'A'] = ar_symbol_type_R,
	['S'-'A'] = ar_symbol_type_S,
	['T'-'A'] = ar_symbol_type_T,
	['W'-'A'] = ar_symbol_type_W,
};

static void slbt_ar_update_syminfo_child(
	char *	program,
	char *  arname,
	int	fdout)
{
	char *	argv[6];

	argv[0] = program;
	argv[1] = "-P";
	argv[2] = "-A";
	argv[3] = "-g";
	argv[4] = arname;
	argv[5] = 0;

	if (dup2(fdout,1) == 1)
		execvp(program,argv);

	_exit(EXIT_FAILURE);
}

static int slbt_obtain_nminfo(
	struct slbt_archive_ctx_impl *  ictx,
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * mctx,
	int                             fdout)
{
	int     ret;
	int     pos;
	int	fdcwd;
	int     fdarg;
	pid_t   pid;
	pid_t   rpid;
	int     ecode;
	char ** argv;
	char    arname [PATH_MAX];
	char    output [PATH_MAX];
	char	program[PATH_MAX];

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* tool-specific argument vector */
	argv = (slbt_get_driver_ictx(dctx))->host.nm_argv;

	/* ar alternate argument vector */
	if (argv) {
		if (slbt_snprintf(program,sizeof(program),
				"%s",argv[0]) < 0)
			return SLBT_BUFFER_ERROR(dctx);
	} else {
		if (slbt_snprintf(program,sizeof(program),
				"%s",dctx->x_cctx->x_host.ha_nm) < 0)
			return SLBT_BUFFER_ERROR(dctx);
	}

	/* arname (.nm suffix, buf treat as .syminfo) */
	pos = slbt_snprintf(
		arname,sizeof(arname)-8,"%s",
		ictx->path);

	/* output */
	if ((fdarg = fdout) < 0) {
		strcpy(output,arname);
		strcpy(&output[pos],".nm");

		slbt_driver_set_ectx(
			dctx,0,
			output);

		if ((fdout = openat(fdcwd,output,O_CREAT|O_TRUNC|O_RDWR,0644)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		strcpy(output,"@nminfo@");
	}

	/* fork */
	if ((pid = slbt_fork()) < 0) {
		close(fdout);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* child */
	if (pid == 0)
		slbt_ar_update_syminfo_child(
			program,arname,fdout);

	/* parent */
	rpid = waitpid(
		pid,
		&ecode,
		0);

	/* nm output */
	if ((rpid > 0)  && (ecode == 0))
		ret = slbt_impl_get_txtfile_ctx(
			dctx,output,fdout,
			&mctx->nminfo);

	if (fdarg < 0)
		close(fdout);

	if (rpid < 0) {
		return SLBT_SYSTEM_ERROR(dctx);

	} else if (ecode) {
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);
	}

	return (ret < 0) ? SLBT_NESTED_ERROR(dctx) : 0;
}

static int slbt_get_symbol_nm_info(
	struct slbt_archive_ctx *       actx,
	struct slbt_archive_meta_impl * mctx,
	uint64_t                        idx)
{
	int                             cint;
	const char **                   pline;
	const char *                    mark;
	const char *                    cap;
	const char *                    objname;
	const char *                    symname;
	struct ar_meta_symbol_info *    syminfo;
	struct ar_meta_member_info **   pmember;

	symname = mctx->symstrv[idx];
	syminfo = &mctx->syminfo[idx];

	for (pline=mctx->nminfo->x_txtlinev; *pline; pline++) {
		mark = *pline;

		if (!(mark = strchr(mark,']')))
			return -1;

		if ((*++mark != ':') || (*++mark != ' '))
			return -1;

		cap = ++mark;

		for (; *cap && !isspace((cint = *cap)); )
			cap++;

		if (*cap != ' ')
			return -1;

		if (!(strncmp(symname,mark,cap-mark))) {
			mark = ++cap;

			/* space only according to posix, but ... */
			if (mark[1] && (mark[1] != ' '))
				return -1;

			switch (mark[0]) {
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'G':
				case 'I':
				case 'R':
				case 'S':
				case 'T':
				case 'W':
					syminfo->ar_symbol_type = ar_symbol_type[mark[0]-'A'];
					break;

				default:
					break;
			}

			if (syminfo->ar_symbol_type) {
				syminfo->ar_archive_name = *actx->x_path;
				syminfo->ar_symbol_name  = symname;

				if (!(mark = strchr(*pline,'[')))
					return -1;

				if (!(cap = strchr(++mark,']')))
					return -1;
			}

			pmember = mctx->memberv;

			for (; *pmember && !syminfo->ar_object_name; ) {
				objname = (*pmember)->ar_file_header.ar_member_name;

				if (!(strncmp(objname,mark,cap-mark)))
					syminfo->ar_object_name = objname;

				pmember++;
			}

			mctx->syminfv[idx] = syminfo;
		}
	}

	return (mctx->syminfv[idx] ? 0 : (-1));
}

static int slbt_qsort_syminfo_cmp(const void * a, const void * b)
{
	struct ar_meta_symbol_info ** syminfoa;
	struct ar_meta_symbol_info ** syminfob;

	syminfoa = (struct ar_meta_symbol_info **)a;
	syminfob = (struct ar_meta_symbol_info **)b;

	return strcmp(
		(*syminfoa)->ar_symbol_name,
		(*syminfob)->ar_symbol_name);
}

static int slbt_coff_qsort_syminfo_cmp(const void * a, const void * b)
{
	struct ar_meta_symbol_info ** syminfoa;
	struct ar_meta_symbol_info ** syminfob;

	syminfoa = (struct ar_meta_symbol_info **)a;
	syminfob = (struct ar_meta_symbol_info **)b;

	return slbt_coff_qsort_strcmp(
		&(*syminfoa)->ar_symbol_name,
		&(*syminfob)->ar_symbol_name);
}

static int slbt_ar_update_syminfo_impl(
	struct slbt_archive_ctx *       actx,
	int                             fdout)
{
	const struct slbt_driver_ctx *  dctx;
	struct slbt_archive_ctx_impl *  ictx;
	struct slbt_archive_meta_impl * mctx;
	uint64_t                        idx;
	bool                            fcoff;

	/* driver context, etc. */
	ictx = slbt_get_archive_ictx(actx);
	mctx = slbt_archive_meta_ictx(ictx->meta);
	dctx = ictx->dctx;

	/* nm -P -A -g */
	if (mctx->armaps.armap_nsyms) {
		if (slbt_obtain_nminfo(ictx,dctx,mctx,fdout) < 0)
			return SLBT_NESTED_ERROR(dctx);
	} else {
		if (slbt_lib_get_txtfile_ctx(
				dctx,"/dev/null",
				&mctx->nminfo) < 0)
			return SLBT_NESTED_ERROR(dctx);
	}

	/* free old syminfo vector */
	if (mctx->syminfv)
		free(mctx->syminfv);

	/* syminfo vector: armap symbols only */
	if (!(mctx->syminfo = calloc(
			mctx->armaps.armap_nsyms + 1,
			sizeof(*mctx->syminfo))))
		return SLBT_SYSTEM_ERROR(dctx);

	if (!(mctx->syminfv = calloc(
			mctx->armaps.armap_nsyms + 1,
			sizeof(*mctx->syminfv))))
		return SLBT_SYSTEM_ERROR(dctx);

	/* do the thing */
	for (idx=0; idx<mctx->armaps.armap_nsyms; idx++)
		if (slbt_get_symbol_nm_info(actx,mctx,idx) < 0)
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_FLOW_ERROR);

	/* coff-aware sorting */
	fcoff  = slbt_host_objfmt_is_coff(dctx);
	fcoff |= (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	qsort(mctx->syminfv,mctx->armaps.armap_nsyms,sizeof(*mctx->syminfv),
		fcoff ? slbt_coff_qsort_syminfo_cmp : slbt_qsort_syminfo_cmp);

	/* yay */
	return 0;
}

slbt_hidden int slbt_ar_update_syminfo(
	struct slbt_archive_ctx * actx)
{
	return slbt_ar_update_syminfo_impl(actx,(-1));
}

slbt_hidden int slbt_ar_update_syminfo_ex(
	struct slbt_archive_ctx * actx,
	int                       fdout)
{
	return slbt_ar_update_syminfo_impl(actx,fdout);
}
