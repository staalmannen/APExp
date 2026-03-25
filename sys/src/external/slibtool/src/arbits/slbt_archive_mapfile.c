/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <time.h>
#include <locale.h>
#include <regex.h>
#include <inttypes.h>
#include <slibtool/slibtool.h>
#include <slibtool/slibtool_output.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_pecoff_impl.h"
#include "slibtool_ar_impl.h"

/********************************************************/
/* Generate a symbol mapfile (aka version script) that  */
/* could be passed to the host linker.                  */
/*                                                      */
/* Since the symbol list is directly derived from the   */
/* archive's armap member, prepending symbol names with */
/* an underscore (where relevant) is not necessary.     */
/********************************************************/

static int slbt_ar_output_mapfile_impl(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * mctx,
	int                             fdout)
{
	bool            fsort;
	bool            fcoff;
	bool            fmach;
	const char *    dot;
	const char *    mark;
	const char *    regex;
	const char **   symv;
	const char **   symstrv;
	regex_t         regctx;
	regmatch_t      pmatch[2] = {{0,0},{0,0}};
	char            strbuf[4096];

	fsort = !(dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_NOSORT);

	fmach  = slbt_host_objfmt_is_macho(dctx);
	fmach |= (mctx->ofmtattr & AR_OBJECT_ATTR_MACHO);

	fcoff  = slbt_host_objfmt_is_coff(dctx);
	fcoff |= (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	if (fcoff) {
		if (slbt_dprintf(fdout,"EXPORTS\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else if (fmach) {
		if (slbt_dprintf(fdout,"# export_list, armap underscores\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		if (slbt_dprintf(fdout,"{\n" "\t" "global:\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	}

	if (fsort && !mctx->mapstrv)
		if (slbt_update_mapstrv(dctx,mctx) < 0)
			return SLBT_NESTED_ERROR(dctx);

	if ((regex = dctx->x_cctx->x_regex))
		if (regcomp(&regctx,regex,REG_EXTENDED|REG_NEWLINE))
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_FLOW_ERROR);

	symstrv = fsort ? mctx->mapstrv : mctx->symstrv;

	for (symv=symstrv; *symv; symv++) {
		if (!fcoff || slbt_is_strong_coff_symbol(*symv)) {
			if (!regex || !regexec(&regctx,*symv,1,pmatch,0)) {
				if (fcoff) {
					if (slbt_dprintf(fdout,"    %s\n",*symv) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				} else if (fmach) {
					if (slbt_dprintf(fdout,"%s\n",*symv) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				} else {
					if (slbt_dprintf(fdout,"\t\t%s;\n",*symv) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				}
			}
		/* coff weak symbols: expsym = .weak.alias.strong */
		} else if (fcoff && !strncmp(*symv,".weak.",6)) {
			mark = &(*symv)[6];
			dot  = strchr(mark,'.');

			strncpy(strbuf,mark,dot-mark);
			strbuf[dot-mark] = '\0';

			if (!regex || !regexec(&regctx,strbuf,1,pmatch,0))
				if (slbt_dprintf(fdout,"    %s = %s\n",strbuf,++dot) < 0)
					return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if (regex)
		regfree(&regctx);

	if (!fcoff && !fmach)
		if (slbt_dprintf(fdout,"\n\t" "local:\n" "\t\t*;\n" "};\n") < 0)
			return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}


static int slbt_ar_create_mapfile_impl(
	const struct slbt_archive_meta *  meta,
	const char *                      path,
	mode_t                            mode)
{
	int                             ret;
	struct slbt_archive_meta_impl * mctx;
	const struct slbt_driver_ctx *  dctx;
	struct slbt_fd_ctx              fdctx;
	int                             fdout;

	mctx = slbt_archive_meta_ictx(meta);
	dctx = (slbt_archive_meta_ictx(meta))->dctx;

	if (slbt_lib_get_driver_fdctx(dctx,&fdctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (!meta->a_memberv)
		return 0;

	if (path) {
		slbt_driver_set_ectx(
			dctx,0,path);

		if ((fdout = openat(
				fdctx.fdcwd,path,
				O_WRONLY|O_CREAT|O_TRUNC,
				mode)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		fdout = fdctx.fdout;
	}

	ret = slbt_ar_output_mapfile_impl(
		dctx,mctx,fdout);

	if (path) {
		close(fdout);
	}

	return ret;
}


int slbt_ar_create_mapfile(
	const struct slbt_archive_meta *  meta,
	const char *                      path,
	mode_t                            mode)
{
	return slbt_ar_create_mapfile_impl(meta,path,mode);
}
