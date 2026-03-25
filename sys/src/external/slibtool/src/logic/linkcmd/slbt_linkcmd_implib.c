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
#include "slibtool_snprintf_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_exec_link_create_import_library(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char *				impfilename,
	char *				deffilename,
	char *				soname)
{
	int	fmdso;
	char ** argv;
	char ** parg;
	char ** aarg;
	char	program[PATH_MAX];
	char    as[PATH_MAX];

	/* dlltool or mdso? */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_IMPLIB_DSODEPS)
		fmdso = 1;

	else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_IMPLIB_IDATA)
		fmdso = 0;

	else if (!(strcmp(dctx->x_cctx->x_host.ha_flavor,"midipix")))
		fmdso = 1;

	else
		fmdso = 0;

	/* alternate argument vector */
	ectx->x_argv    = ectx->x_altv;
	ectx->x_program = program;

	/* tool-specific argument vector */
	argv = (fmdso)
		? (slbt_get_driver_ictx(dctx))->host.mdso_argv
		: (slbt_get_driver_ictx(dctx))->host.dlltool_argv;

	/* tool-specific argv */
	aarg = ectx->x_altv;

	if ((parg = argv)) {
		ectx->x_program = argv[0];

		for (; *parg; )
			*aarg++ = *parg++;
	} else {
		*aarg++ = program;
	}

	/* altv */
	if (fmdso) {
		if (!argv)
			if (slbt_snprintf(program,sizeof(program),
					"%s",dctx->x_cctx->x_host.ha_mdso) < 0)
				return SLBT_BUFFER_ERROR(dctx);

		*aarg++ = "-i";
		*aarg++ = impfilename;
		*aarg++ = "-n";
		*aarg++ = soname;
		*aarg++ = deffilename;
		*aarg   = 0;
	} else {
		if (!argv)
			if (slbt_snprintf(program,sizeof(program),
					"%s",dctx->x_cctx->x_host.ha_dlltool) < 0)
				return SLBT_BUFFER_ERROR(dctx);

		*aarg++ = "-l";
		*aarg++ = impfilename;
		*aarg++ = "-d";
		*aarg++ = deffilename;
		*aarg++ = "-D";
		*aarg++ = soname;
		*aarg = 0;

		if (dctx->x_cctx->x_host.ha_as) {
			if ((argv = (slbt_get_driver_ictx(dctx))->host.as_argv)) {
				*aarg++ = "-S";
				*aarg++ = argv[0];

				for (parg=&argv[1]; *parg; parg++) {
					*aarg++ = "-f";
					*aarg++ = *parg;
				}
			} else {
				if (slbt_snprintf(as,sizeof(as),
						"%s",dctx->x_cctx->x_host.ha_as) < 0)
					return SLBT_BUFFER_ERROR(dctx);

				*aarg++ = "-S";
				*aarg++ = as;
			}

			const char * host = dctx->x_cctx->x_host.ha_host;

			if (host && (host[0] == 'i')
					&& (host[1] >= '3')
					&& (host[1] <= '6')
					&& (host[2] == '8')
					&& (host[3] == '6')
					&& (host[4] == '-')) {
				*aarg++  = "-f";
				*aarg++ = "--32";
				*aarg++ = "-m";
				*aarg++ = "i386";
				*aarg++ = 0;
			} else {
				*aarg++ = "-f";
				*aarg++ = "--64";
				*aarg++ = "-m";
				*aarg++ = "i386:x86-64";
				*aarg   = 0;
			}
		}
	}

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
		if (slbt_output_link(ectx))
			return SLBT_NESTED_ERROR(dctx);

	/* dlltool/mdso spawn */
	if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
		return SLBT_SPAWN_ERROR(dctx);

	} else if (ectx->x_exitcode) {
		return SLBT_CUSTOM_ERROR(
			dctx,
			fmdso ? SLBT_ERR_MDSO_ERROR : SLBT_ERR_DLLTOOL_ERROR);
	}

	return 0;
}
