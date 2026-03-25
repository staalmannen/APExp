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
#include "slibtool_tmpfile_impl.h"
#include "slibtool_ar_impl.h"

#define SLBT_PRETTY_FLAGS       (SLBT_PRETTY_YAML      \
	                         | SLBT_PRETTY_POSIX    \
	                         | SLBT_PRETTY_HEXDATA)

static int slbt_au_output_symbols_posix(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * mctx,
	int                             fdout)
{
	bool            fsort;
	bool            fcoff;
	const char *    dot;
	const char *    mark;
	const char *    regex;
	const char **   symv;
	const char **   symstrv;
	regex_t         regctx;
	regmatch_t      pmatch[2] = {{0,0},{0,0}};
	char            strbuf[4096];

	fsort = !(dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_NOSORT);
	fcoff = (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

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
				if (slbt_dprintf(fdout,"%s\n",*symv) < 0)
					return SLBT_SYSTEM_ERROR(dctx);
			}

		/* coff weak symbols: expsym = .weak.alias.strong */
		} else if (fcoff && !strncmp(*symv,".weak.",6)) {
			mark = &(*symv)[6];
			dot  = strchr(mark,'.');

			strncpy(strbuf,mark,dot-mark);
			strbuf[dot-mark] = '\0';

			if (!regex || !regexec(&regctx,strbuf,1,pmatch,0))
				if (slbt_dprintf(fdout,"%s\n",strbuf) < 0)
					return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if (regex)
		regfree(&regctx);

	return 0;
}

static int slbt_au_output_one_symbol_yaml(
	int                             fdout,
	struct slbt_archive_meta_impl * mctx,
	const char *                    symname)
{
	struct ar_meta_symbol_info **   syminfv;

	for (syminfv=mctx->syminfv; *syminfv; syminfv++)
		if (!strcmp(syminfv[0]->ar_symbol_name,symname))
			return slbt_dprintf(
				fdout,
				"    - Symbol:\n"
				"      - [ object_name: " "%s"    " ]\n"
				"      - [ symbol_name: " "%s"    " ]\n"
				"      - [ symbol_type: " "%s"    " ]\n\n",
				syminfv[0]->ar_object_name,
				symname,
				syminfv[0]->ar_symbol_type);

	return 0;
}

static int slbt_au_output_symbols_yaml(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * mctx,
	int                             fdout)
{
	int                             fdtmp;
	bool                            fsort;
	bool                            fcoff;
	const char *                    dot;
	const char *                    mark;
	const char *                    regex;
	const char **                   symv;
	const char **                   symstrv;
	regex_t                         regctx;
	regmatch_t                      pmatch[2] = {{0,0},{0,0}};
	char                            strbuf[4096];

	fsort = !(dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_NOSORT);
	fcoff = (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	if ((fdtmp = slbt_tmpfile()) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (fsort && !mctx->mapstrv)
		if (slbt_update_mapstrv(dctx,mctx) < 0)
			return SLBT_NESTED_ERROR(dctx);

	if (slbt_ar_update_syminfo_ex(mctx->actx,fdtmp) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if ((regex = dctx->x_cctx->x_regex))
		if (regcomp(&regctx,regex,REG_EXTENDED|REG_NEWLINE))
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_FLOW_ERROR);

	symstrv = fsort ? mctx->mapstrv : mctx->symstrv;

	if (slbt_dprintf(fdout,"  - Symbols:\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	for (symv=symstrv; *symv; symv++) {
		if (!fcoff || slbt_is_strong_coff_symbol(*symv)) {
			if (!regex || !regexec(&regctx,*symv,1,pmatch,0)) {
				if (slbt_au_output_one_symbol_yaml(
						fdout,mctx,*symv) < 0)
					return SLBT_SYSTEM_ERROR(dctx);
			}

		/* coff weak symbols: expsym = .weak.alias.strong */
		} else if (fcoff && !strncmp(*symv,".weak.",6)) {
			mark = &(*symv)[6];
			dot  = strchr(mark,'.');

			strncpy(strbuf,mark,dot-mark);
			strbuf[dot-mark] = '\0';

			if (!regex || !regexec(&regctx,strbuf,1,pmatch,0))
				if (slbt_au_output_one_symbol_yaml(
						fdout,mctx,strbuf) < 0)
					return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if (regex)
		regfree(&regctx);

	return 0;
}

int slbt_au_output_symbols(const struct slbt_archive_meta * meta)
{
	struct slbt_archive_meta_impl * mctx;
	const struct slbt_driver_ctx *  dctx;
	int                             fdout;

	mctx = slbt_archive_meta_ictx(meta);
	dctx = (slbt_archive_meta_ictx(meta))->dctx;

	fdout = slbt_driver_fdout(dctx);

	if (!meta->a_memberv)
		return 0;

	switch (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_FLAGS) {
		case SLBT_PRETTY_YAML:
			return slbt_au_output_symbols_yaml(
				dctx,mctx,fdout);

		case SLBT_PRETTY_POSIX:
			return slbt_au_output_symbols_posix(
				dctx,mctx,fdout);

		default:
			return slbt_au_output_symbols_yaml(
				dctx,mctx,fdout);
	}
}
