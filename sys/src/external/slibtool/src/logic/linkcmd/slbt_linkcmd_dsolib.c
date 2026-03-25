/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_linkcmd_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_metafile_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_visibility_impl.h"

static int slbt_linkcmd_exit(
	struct slbt_deps_meta *	depsmeta,
	int			ret)
{
	if (depsmeta->altv)
		free(depsmeta->altv);

	if (depsmeta->args)
		free(depsmeta->args);

	return ret;
}

static int slbt_exec_link_remove_file(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target)
{
	int fdcwd;

	(void)ectx;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove target (if any) */
	if (!unlinkat(fdcwd,target,0) || (errno == ENOENT))
		return 0;

	return SLBT_SYSTEM_ERROR(dctx);
}

static int slbt_exec_link_remove_dso_files(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			target)
{
	int fdcwd;
	char * mark;
	char * sbuf;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove target (if any) */
	if (unlinkat(fdcwd,target,0) && (errno != ENOENT))
		return SLBT_SYSTEM_ERROR(dctx);

	/* remove a previous .disabled placeholder */
	sbuf  = (slbt_get_exec_ictx(ectx))->sbuf;
	mark  = sbuf;
	mark += sprintf(mark,"%s",target);
	strcpy(mark,".disabled");

	if (unlinkat(fdcwd,sbuf,0) && (errno != ENOENT))
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}

slbt_hidden int slbt_exec_link_create_library(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	const char *			dsobasename,
	const char *			dsofilename,
	const char *			relfilename,
	bool                            fardlopen,
	bool                            fpic)
{
	int                     fdcwd;
	char **                 parg;
	char **                 xarg;
	char *	                ccwrap;
	const char *            laout;
	const char *            dot;
	char                    cwd    [PATH_MAX];
	char                    output [PATH_MAX];
	char                    soname [PATH_MAX];
	char                    symfile[PATH_MAX];
	char                    mapfile[PATH_MAX];
	struct slbt_deps_meta   depsmeta = {0,0,0,0};

	/* initial state */
	slbt_ectx_reset_arguments(ectx);

	/* placeholders */
	slbt_reset_placeholders(ectx);

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* remove previous libfoo.so, libfoo.so.disabled */
	if (slbt_exec_link_remove_dso_files(dctx,ectx,ectx->x_dsofilename) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* input argument adjustment */
	for (parg=ectx->x_cargv; *parg; parg++)
		slbt_adjust_object_argument(*parg,fpic,false,fdcwd);

	/* .deps */
	if (slbt_exec_link_create_dep_file(
			dctx,ectx,ectx->x_cargv,
			dsofilename,false))
		return slbt_linkcmd_exit(
			&depsmeta,
			SLBT_NESTED_ERROR(dctx));

	/* linker argument adjustment */
	for (parg=ectx->x_cargv, xarg=ectx->x_xargv; *parg; parg++, xarg++)
		if (slbt_adjust_linker_argument(
				dctx,
				*parg,xarg,true,
				dctx->x_cctx->x_settings.fa_dsosuffix,
				dctx->x_cctx->x_settings.fa_arsuffix,
				&depsmeta) < 0)
			return SLBT_NESTED_ERROR(dctx);

	/* --no-undefined */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_NO_UNDEFINED)
		*ectx->x_noundef = slbt_host_group_is_darwin(dctx)
			? "-Wl,-undefined,error"
			: "-Wl,--no-undefined";

	/* -soname */
	dot   = strrchr(dctx->x_cctx->x_output,'.');
	laout = (dot && !strcmp(dot,".la"))
			? dctx->x_cctx->x_output
			: 0;

	char wl_soname[24];

	if (slbt_host_group_is_darwin(dctx)) {
		strcpy(wl_soname,"-Wl,-install_name");
	} else {
		strcpy(wl_soname,"-Wl,-soname");
	}

	if ((dctx->x_cctx->x_drvflags & SLBT_DRIVER_IMAGE_MACHO)) {
		(void)0;

	} else if (!laout && (dctx->x_cctx->x_drvflags & SLBT_DRIVER_MODULE)) {
		if (slbt_snprintf(soname,sizeof(soname),
				"-Wl,%s",dctx->x_cctx->x_output) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_soname  = wl_soname;
		*ectx->x_lsoname = soname;

	} else if (relfilename && dctx->x_cctx->x_verinfo.vi_verinfo) {
		if (slbt_snprintf(soname,sizeof(soname),
					"-Wl,%s%s%s%s%s.%d%s",
					ectx->x_sonameprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_release ? "-" : "",
					dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
					dctx->x_cctx->x_settings.fa_osdsuffix,
					dctx->x_cctx->x_verinfo.vi_major,
					dctx->x_cctx->x_settings.fa_osdfussix) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_soname  = wl_soname;
		*ectx->x_lsoname = soname;

	} else if (relfilename) {
		if (slbt_snprintf(soname,sizeof(soname),
					"-Wl,%s%s%s%s%s",
					ectx->x_sonameprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_release ? "-" : "",
					dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
					dctx->x_cctx->x_settings.fa_dsosuffix) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_soname  = wl_soname;
		*ectx->x_lsoname = soname;

	} else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_AVOID_VERSION) {
		if (slbt_snprintf(soname,sizeof(soname),
					"-Wl,%s%s%s",
					ectx->x_sonameprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_settings.fa_dsosuffix) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_soname  = wl_soname;
		*ectx->x_lsoname = soname;

	} else {
		if (slbt_snprintf(soname,sizeof(soname),
					"-Wl,%s%s%s.%d%s",
					ectx->x_sonameprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_settings.fa_osdsuffix,
					dctx->x_cctx->x_verinfo.vi_major,
					dctx->x_cctx->x_settings.fa_osdfussix) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_soname  = wl_soname;
		*ectx->x_lsoname = soname;
	}

	/* PE: --output-def */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_IMAGE_PE) {
		if (slbt_snprintf(symfile,sizeof(symfile),
					"-Wl,%s",
					ectx->x_deffilename) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		*ectx->x_symdefs = "-Wl,--output-def";
		*ectx->x_symfile = symfile;
	}

	/* -export-symbols */
	if (dctx->x_cctx->x_expsyms) {
		struct slbt_symlist_ctx * sctx;
		sctx = (slbt_get_exec_ictx(ectx))->sctx;

		if (slbt_util_create_mapfile(sctx,ectx->x_mapfilename,0644) < 0)
			return SLBT_NESTED_ERROR(dctx);

		if (slbt_snprintf(mapfile,sizeof(mapfile),
					"-Wl,%s",
					ectx->x_mapfilename) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		if (slbt_host_group_is_darwin(dctx)) {
			*ectx->x_explarg = "-Wl,-exported_symbols_list";
			*ectx->x_expsyms = mapfile;

		} else if (slbt_host_group_is_winnt(dctx)) {
			*ectx->x_expsyms = mapfile;
		} else {
			*ectx->x_explarg = "-Wl,--version-script";
			*ectx->x_expsyms = mapfile;
		}
	}

	/* -export-symbols-regex; and see also:     */
	/* slbt_exec_link_create_expsyms_archive() */
	if (dctx->x_cctx->x_regex) {
		if (slbt_snprintf(mapfile,sizeof(mapfile),
					"-Wl,%s",
					ectx->x_mapfilename) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		if (slbt_host_group_is_darwin(dctx)) {
			*ectx->x_explarg = "-Wl,-exported_symbols_list";
			*ectx->x_expsyms = mapfile;

		} else if (slbt_host_group_is_winnt(dctx)) {
			*ectx->x_expsyms = mapfile;
		} else {
			*ectx->x_explarg = "-Wl,--version-script";
			*ectx->x_expsyms = mapfile;
		}
	}

	/* shared/static */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ALL_STATIC) {
		*ectx->x_dpic = "-static";
	} else if (dctx->x_cctx->x_settings.fa_picswitch) {
		*ectx->x_dpic = "-shared";
		*ectx->x_fpic = dctx->x_cctx->x_settings.fa_picswitch;
	} else {
		*ectx->x_dpic = "-shared";
	}

	/* output */
	if (!laout && dctx->x_cctx->x_drvflags & SLBT_DRIVER_MODULE) {
		strcpy(output,dctx->x_cctx->x_output);
	} else if (relfilename) {
		strcpy(output,relfilename);
	} else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_AVOID_VERSION) {
		strcpy(output,dsofilename);
	} else {
		if (slbt_snprintf(output,sizeof(output),
					"%s%s.%d.%d.%d%s",
					dsobasename,
					dctx->x_cctx->x_settings.fa_osdsuffix,
					dctx->x_cctx->x_verinfo.vi_major,
					dctx->x_cctx->x_verinfo.vi_minor,
					dctx->x_cctx->x_verinfo.vi_revision,
					dctx->x_cctx->x_settings.fa_osdfussix) < 0)
			return SLBT_BUFFER_ERROR(dctx);
	}

	/* output marks */
	*ectx->x_lout[0] = "-o";
	*ectx->x_lout[1] = output;

	/* ldrpath */
	if (dctx->x_cctx->x_host.ha_ldrpath) {
		if (slbt_exec_link_remove_file(dctx,ectx,ectx->x_rpathfilename))
			return SLBT_NESTED_ERROR(dctx);

		if (slbt_create_symlink(
				dctx,ectx,
				dctx->x_cctx->x_host.ha_ldrpath,
				ectx->x_rpathfilename,
				SLBT_SYMLINK_LITERAL))
			return SLBT_NESTED_ERROR(dctx);
	}

	/* cwd */
	if (slbt_realpath(fdcwd,".",O_DIRECTORY,cwd,sizeof(cwd)))
		return SLBT_SYSTEM_ERROR(dctx);

	/* .libs/libfoo.so --> -L.libs -lfoo */
	if (slbt_exec_link_adjust_argument_vector(
			dctx,ectx,&depsmeta,cwd,true))
		return SLBT_NESTED_ERROR(dctx);

	/* using alternate argument vector */
	ccwrap        = (char *)dctx->x_cctx->x_ccwrap;
	ectx->x_argv    = depsmeta.altv;
	ectx->x_program = ccwrap ? ccwrap : depsmeta.altv[0];

	/* sigh */
	if (slbt_exec_link_finalize_argument_vector(dctx,ectx))
		return SLBT_NESTED_ERROR(dctx);

	/* all done? */
	if (fardlopen)
		return 0;

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
		if (slbt_output_link(ectx))
			return slbt_linkcmd_exit(
				&depsmeta,
				SLBT_NESTED_ERROR(dctx));

	/* spawn */
	if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
		return slbt_linkcmd_exit(
			&depsmeta,
			SLBT_SPAWN_ERROR(dctx));

	} else if (ectx->x_exitcode) {
		return slbt_linkcmd_exit(
			&depsmeta,
			SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_LINK_ERROR));
	}

	return slbt_linkcmd_exit(&depsmeta,0);
}
