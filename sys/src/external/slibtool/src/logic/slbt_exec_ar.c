/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include <slibtool/slibtool_output.h>
#include "slibtool_driver_impl.h"
#include "slibtool_ar_impl.h"
#include "slibtool_errinfo_impl.h"
#include "argv/argv.h"

#define SLBT_DRIVER_MODE_AR_ACTIONS     (SLBT_DRIVER_MODE_AR_CHECK \
	                                 | SLBT_DRIVER_MODE_AR_MERGE)

#define SLBT_DRIVER_MODE_AR_OUTPUTS     (SLBT_OUTPUT_ARCHIVE_MEMBERS  \
	                                 | SLBT_OUTPUT_ARCHIVE_HEADERS \
	                                 | SLBT_OUTPUT_ARCHIVE_SYMBOLS  \
	                                 | SLBT_OUTPUT_ARCHIVE_ARMAPS)

#define SLBT_PRETTY_FLAGS               (SLBT_PRETTY_YAML      \
	                                 | SLBT_PRETTY_POSIX    \
	                                 | SLBT_PRETTY_HEXDATA)

static int slbt_ar_usage(
	int				fdout,
	const char *			program,
	const char *			arg,
	const struct argv_option **	optv,
	struct argv_meta *		meta,
	struct slbt_exec_ctx *		ectx,
	int				noclr)
{
	char		header[512];
	bool		armode;
	const char *	dash;

	armode = (dash = strrchr(program,'-'))
		&& !strcmp(++dash,"ar");

	snprintf(header,sizeof(header),
		"Usage: %s%s [options] [ARCHIVE-FILE] [ARCHIVE_FILE] ...\n"
		"Options:\n",
		program,
		armode ? "" : " --mode=ar");

	switch (noclr) {
		case 0:
			slbt_argv_usage(fdout,header,optv,arg);
			break;

		default:
			slbt_argv_usage_plain(fdout,header,optv,arg);
			break;
	}

	if (ectx)
		slbt_ectx_free_exec_ctx(ectx);

	slbt_argv_free(meta);

	return SLBT_USAGE;
}

static int slbt_exec_ar_fail(
	struct slbt_exec_ctx *	ectx,
	struct argv_meta *	meta,
	int			ret)
{
	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);
	return ret;
}

static int slbt_exec_ar_perform_archive_actions(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_ctx **      arctxv)
{
	struct slbt_archive_ctx **      arctxp;
	struct slbt_archive_ctx *       arctx;
	bool                            farname;

	switch (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_FLAGS) {
		case SLBT_PRETTY_POSIX:
			farname = (arctxv[0] && arctxv[1]);
			break;

		default:
			farname = true;
			break;
	}

	for (arctxp=arctxv; *arctxp; arctxp++) {
		if (dctx->x_cctx->x_fmtflags & SLBT_DRIVER_MODE_AR_OUTPUTS)
			if (farname && (slbt_au_output_arname(*arctxp) < 0))
				return SLBT_NESTED_ERROR(dctx);

		if (dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_MEMBERS)
			if (slbt_au_output_members((*arctxp)->x_meta) < 0)
				return SLBT_NESTED_ERROR(dctx);

		if (dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_SYMBOLS)
			if (slbt_au_output_symbols((*arctxp)->x_meta) < 0)
				return SLBT_NESTED_ERROR(dctx);

		if (dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_MAPFILE)
			if (slbt_au_output_mapfile((*arctxp)->x_meta) < 0)
				return SLBT_NESTED_ERROR(dctx);
	}

	if (dctx->x_cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_DLSYMS)
		if (slbt_au_output_dlsyms(arctxv,dctx->x_cctx->x_dlunit) < 0)
			return SLBT_NESTED_ERROR(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_MODE_AR_MERGE) {
		if (slbt_ar_merge_archives(arctxv,&arctx) < 0)
			return SLBT_NESTED_ERROR(dctx);

		/* (defer mode to umask) */
		if (slbt_ar_store_archive(arctx,dctx->x_cctx->x_output,0666) < 0)
			return SLBT_NESTED_ERROR(dctx);
	}

	return 0;
}

int slbt_exec_ar(const struct slbt_driver_ctx * dctx)
{
	int				ret;
	int				fdout;
	int				fderr;
	char **				argv;
	char **				iargv;
	struct slbt_exec_ctx *		ectx;
	struct slbt_driver_ctx_impl *	ictx;
	const struct slbt_common_ctx *	cctx;
	struct slbt_archive_ctx **	arctxv;
	struct slbt_archive_ctx **	arctxp;
	const char **			unitv;
	const char **			unitp;
	size_t				nunits;
	struct argv_meta *		meta;
	struct argv_entry *		entry;
	const struct argv_option *	optv[SLBT_OPTV_ELEMENTS];

	/* context */
	if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* initial state, ar mode skin */
	slbt_ectx_reset_arguments(ectx);
	slbt_disable_placeholders(ectx);

	ictx  = slbt_get_driver_ictx(dctx);
	cctx  = dctx->x_cctx;
	iargv = ectx->x_cargv;

	fdout = slbt_driver_fdout(dctx);
	fderr = slbt_driver_fderr(dctx);

	/* missing arguments? */
	slbt_optv_init(slbt_ar_options,optv);

	if (!iargv[1] && (dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_USAGE))
		return slbt_ar_usage(
			fdout,
			dctx->x_program,
			0,optv,0,ectx,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER);

	/* <ar> argv meta */
	if (!(meta = slbt_argv_get(
			iargv,optv,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS
				? ARGV_VERBOSITY_ERRORS
				: ARGV_VERBOSITY_NONE,
			fdout)))
		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_AR_FAIL));

	/* dest, alternate argument vector options */
	argv    = ectx->x_altv;
	*argv++ = iargv[0];
	nunits  = 0;

	for (entry=meta->entries; entry->fopt || entry->arg; entry++) {
		if (entry->fopt) {
			switch (entry->tag) {
				case TAG_AR_HELP:
					slbt_ar_usage(
						fdout,
						dctx->x_program,
						0,optv,0,ectx,
						dctx->x_cctx->x_drvflags
							& SLBT_DRIVER_ANNOTATE_NEVER);

					ictx->cctx.x_drvflags |= SLBT_DRIVER_VERSION;
					ictx->cctx.x_drvflags ^= SLBT_DRIVER_VERSION;

					slbt_argv_free(meta);

					return SLBT_OK;

				case TAG_AR_VERSION:
					ictx->cctx.x_drvflags |= SLBT_DRIVER_VERSION;
					break;

				case TAG_AR_CHECK:
					ictx->cctx.x_drvflags |= SLBT_DRIVER_MODE_AR_CHECK;
					break;

				case TAG_AR_MERGE:
					ictx->cctx.x_drvflags |= SLBT_DRIVER_MODE_AR_MERGE;
					break;

				case TAG_AR_OUTPUT:
					ictx->cctx.x_output = entry->arg;
					break;

				case TAG_AR_PRINT:
					if (!entry->arg)
						ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_MEMBERS;

					else if (!strcmp(entry->arg,"members"))
						ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_MEMBERS;

					else if (!strcmp(entry->arg,"headers"))
						ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_HEADERS;

					else if (!strcmp(entry->arg,"symbols"))
						ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_SYMBOLS;

					else if (!strcmp(entry->arg,"armaps"))
						ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_ARMAPS;

					break;

				case TAG_AR_MAPFILE:
					ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_MAPFILE;
					break;

				case TAG_AR_DLSYMS:
					ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_DLSYMS;
					break;

				case TAG_AR_DLUNIT:
					ictx->cctx.x_dlunit = entry->arg;
					break;

				case TAG_AR_NOSORT:
					ictx->cctx.x_fmtflags |= SLBT_OUTPUT_ARCHIVE_NOSORT;
					break;

				case TAG_AR_REGEX:
					ictx->cctx.x_regex = entry->arg;
					break;

				case TAG_AR_PRETTY:
					if (!strcmp(entry->arg,"yaml")) {
						ictx->cctx.x_fmtflags &= ~(uint64_t)SLBT_PRETTY_FLAGS;
						ictx->cctx.x_fmtflags |= SLBT_PRETTY_YAML;

					} else if (!strcmp(entry->arg,"posix")) {
						ictx->cctx.x_fmtflags &= ~(uint64_t)SLBT_PRETTY_FLAGS;
						ictx->cctx.x_fmtflags |= SLBT_PRETTY_POSIX;
					}

					break;

				case TAG_AR_POSIX:
					ictx->cctx.x_fmtflags &= ~(uint64_t)SLBT_PRETTY_FLAGS;
					ictx->cctx.x_fmtflags |= SLBT_PRETTY_POSIX;
					break;

				case TAG_AR_YAML:
					ictx->cctx.x_fmtflags &= ~(uint64_t)SLBT_PRETTY_FLAGS;
					ictx->cctx.x_fmtflags |= SLBT_PRETTY_YAML;
					break;

				case TAG_AR_VERBOSE:
					ictx->cctx.x_fmtflags |= SLBT_PRETTY_VERBOSE;
					break;
			}

			if (entry->fval) {
				*argv++ = (char *)entry->arg;
			}
		} else {
			nunits++;
		};
	}

	/* defer --version printing to slbt_main() as needed */
	if (cctx->x_drvflags & SLBT_DRIVER_VERSION) {
		slbt_argv_free(meta);
		slbt_ectx_free_exec_ctx(ectx);
		return SLBT_OK;
	}

	/* at least one action must be specified */
	if (cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_DLSYMS) {
		if (!cctx->x_dlunit) {
			slbt_dprintf(fderr,
				"%s: missing -Wdlunit: generation of a dlsyms vtable "
				"requires the name of the dynamic library, executable "
				"program, or dynamic module for which the vtable would "
				"be generated.\n",
				dctx->x_program);

			return slbt_exec_ar_fail(
				ectx,meta,
				SLBT_CUSTOM_ERROR(
					dctx,
					SLBT_ERR_AR_DLUNIT_NOT_SPECIFIED));
		}
	} else if (cctx->x_fmtflags & SLBT_DRIVER_MODE_AR_OUTPUTS) {
		(void)0;

	} else if (cctx->x_fmtflags & SLBT_OUTPUT_ARCHIVE_MAPFILE) {
		(void)0;

	} else if (!(cctx->x_drvflags & SLBT_DRIVER_MODE_AR_ACTIONS)) {
		if (cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_dprintf(fderr,
				"%s: at least one action must be specified\n",
				dctx->x_program);

		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_NO_ACTION_SPECIFIED));
	}

	/* -Wmerge without -Woutput? */
	if ((cctx->x_drvflags & SLBT_DRIVER_MODE_AR_MERGE) && !cctx->x_output) {
		if (cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_dprintf(fderr,
				"%s: archive merging: output must be specified.\n",
				dctx->x_program);

		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_OUTPUT_NOT_SPECIFIED));
	}


	/* -Woutput without -Wmerge? */
	if (cctx->x_output && !(cctx->x_drvflags & SLBT_DRIVER_MODE_AR_MERGE)) {
		if (cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_dprintf(fderr,
				"%s: output may only be specified "
				"when merging one or more archives.\n",
				dctx->x_program);

		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_OUTPUT_NOT_APPLICABLE));
	}


	/* at least one unit must be specified */
	if (!nunits) {
		if (cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_dprintf(fderr,
				"%s: all actions require at least one input unit\n",
				dctx->x_program);

		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_NO_INPUT_SPECIFIED));
	}

	/* archive vector allocation */
	if (!(arctxv = calloc(nunits+1,sizeof(struct slbt_archive_ctx *))))
		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_SYSTEM_ERROR(dctx));

	/* unit vector allocation */
	if (!(unitv = calloc(nunits+1,sizeof(const char *)))) {
		free (arctxv);

		return slbt_exec_ar_fail(
			ectx,meta,
			SLBT_SYSTEM_ERROR(dctx));
	}

	/* unit vector initialization */
	for (entry=meta->entries,unitp=unitv; entry->fopt || entry->arg; entry++)
		if (!entry->fopt)
			*unitp++ = entry->arg;

	/* archive context vector initialization */
	for (unitp=unitv,arctxp=arctxv; *unitp; unitp++,arctxp++) {
		if (slbt_ar_get_archive_ctx(dctx,*unitp,arctxp) < 0) {
			for (arctxp=arctxv; *arctxp; arctxp++)
				slbt_ar_free_archive_ctx(*arctxp);

			free(unitv);
			free(arctxv);

			return slbt_exec_ar_fail(
				ectx,meta,
				SLBT_NESTED_ERROR(dctx));
		}
	}

	/* archive operations */
	ret = slbt_exec_ar_perform_archive_actions(dctx,arctxv);

	/* all done */
	for (arctxp=arctxv; *arctxp; arctxp++)
		slbt_ar_free_archive_ctx(*arctxp);

	free(unitv);
	free(arctxv);

	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);

	return ret;
}
