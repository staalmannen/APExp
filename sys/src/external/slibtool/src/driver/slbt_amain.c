/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"

#ifndef SLBT_DRIVER_FLAGS
#define SLBT_DRIVER_FLAGS	SLBT_DRIVER_VERBOSITY_ERRORS \
				| SLBT_DRIVER_VERBOSITY_USAGE
#endif

static const char vermsg[] = "%s%s%s (https://git.foss21.org/slibtool): "
			     "version %s%d.%d.%d%s.\n"
			     "%s%s%s%s%s\n";

static const char * const slbt_ver_color[6] = {
		"\x1b[1m\x1b[35m","\x1b[0m",
		"\x1b[1m\x1b[32m","\x1b[0m",
		"\x1b[1m\x1b[34m","\x1b[0m"
};

static const char * const slbt_ver_plain[6] = {
		"","",
		"","",
		"",""
};

static ssize_t slbt_version(struct slbt_driver_ctx * dctx, int fdout)
{
	const struct slbt_source_version * verinfo;
	const char * const * verclr;
	bool gitver;

	verinfo = slbt_api_source_version();
	verclr  = isatty(fdout) ? slbt_ver_color : slbt_ver_plain;
	gitver  = strcmp(verinfo->v_commit,"unknown");

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER)
		verclr = slbt_ver_plain;

	return slbt_dprintf(fdout,vermsg,
			verclr[0],dctx->x_program,verclr[1],
			verclr[2],verinfo->v_major,verinfo->v_minor,
			verinfo->v_revision,verclr[3],
			gitver ? "[commit reference: " : "",
			verclr[4],gitver ? verinfo->v_commit : "",
			verclr[5],gitver ? "]" : "");
}

static ssize_t slbt_print_aux_dir(int fdout)
{
	return slbt_dprintf(fdout,"%s\n",SLBT_PACKAGE_DATADIR);
}

static ssize_t slbt_print_m4_dir(int fdout)
{
	return slbt_dprintf(fdout,"%s\n",SLBT_PACKAGE_M4DIR);
}

static ssize_t slbt_print_shared_ext(int fdout, struct slbt_driver_ctx * dctx)
{
	return slbt_dprintf(fdout,"%s\n",dctx->x_cctx->x_settings.fa_dsosuffix);
}

static ssize_t slbt_print_static_ext(int fdout, struct slbt_driver_ctx * dctx)
{
	return slbt_dprintf(fdout,"%s\n",dctx->x_cctx->x_settings.fa_arsuffix);
}

static void slbt_perform_driver_actions(struct slbt_driver_ctx * dctx)
{
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_INFO)
		slbt_output_info(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_FEATURES)
		slbt_output_features(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_CONFIG)
		slbt_output_config(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_COMPILE)
		slbt_exec_compile(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_EXECUTE)
		slbt_exec_execute(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_INSTALL)
		slbt_exec_install(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_LINK)
		slbt_exec_link(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_UNINSTALL)
		slbt_exec_uninstall(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_AR)
		slbt_exec_ar(dctx);

	if (dctx->x_cctx->x_mode == SLBT_MODE_STOOLIE)
		slbt_exec_stoolie(dctx);
}

static int slbt_exit(struct slbt_driver_ctx * dctx, int ret)
{
	slbt_output_error_vector(dctx);
	slbt_lib_free_driver_ctx(dctx);
	return ret;
}

int slbt_main(char ** argv, char ** envp, const struct slbt_fd_ctx * fdctx)
{
	int				ret;
	int				fdout;
	uint64_t			flags;
	uint64_t			noclr;
	struct slbt_driver_ctx *	dctx;
	char *				program;
	char *				dash;

	flags = SLBT_DRIVER_FLAGS;
	fdout = fdctx ? fdctx->fdout : STDOUT_FILENO;
	noclr = getenv("NO_COLOR") ? SLBT_DRIVER_ANNOTATE_NEVER : 0;

	/* program */
	if ((program = strrchr(argv[0],'/')))
		program++;
	else
		program = argv[0];

	/* dash */
	if ((dash = strrchr(program,'-')))
		dash++;

	/* flags */
	if (dash == 0)
		flags = SLBT_DRIVER_FLAGS;

	else if (!(strcmp(dash,"shared")))
		flags = SLBT_DRIVER_FLAGS | SLBT_DRIVER_DISABLE_STATIC;

	else if (!(strcmp(dash,"static")))
		flags = SLBT_DRIVER_FLAGS | SLBT_DRIVER_DISABLE_SHARED;

	/* internal ar mode */
	else if (!(strcmp(dash,"ar")))
		flags |= SLBT_DRIVER_MODE_AR;

	/* slibtoolize (stoolie) mode */
	if (!(strcmp(program,"stoolie")))
		flags |= SLBT_DRIVER_MODE_STOOLIE | SLBT_DRIVER_PREFER_SLTDL;

	else if (!(strcmp(program,"slibtoolize")))
		flags |= SLBT_DRIVER_MODE_STOOLIE | SLBT_DRIVER_PREFER_SLTDL;

	else if (!(strcmp(program,"libtoolize")))
		flags |= SLBT_DRIVER_MODE_STOOLIE | SLBT_DRIVER_PREFER_SLTDL;

	/* debug */
	if (!(strcmp(program,"dlibtool")))
		flags |= SLBT_DRIVER_DEBUG;

	else if (!(strncmp(program,"dlibtool",8)))
		if ((program[8] == '-') || (program[8] == '.'))
			flags |= SLBT_DRIVER_DEBUG;

	/* legabits */
	if (!(strcmp(program,"clibtool")))
		flags |= SLBT_DRIVER_LEGABITS;

	else if (!(strncmp(program,"clibtool",8)))
		if ((program[8] == '-') || (program[8] == '.'))
			flags |= SLBT_DRIVER_LEGABITS;

	/* heuristics */
	if (!(strcmp(program,"rlibtool")))
		flags |= SLBT_DRIVER_HEURISTICS;

	/* heuristics + legabits */
	if (!(strcmp(program,"rclibtool")))
		flags |= (SLBT_DRIVER_HEURISTICS
                          | SLBT_DRIVER_LEGABITS);

	/* heuristics + debug */
	if (!(strcmp(program,"rdlibtool")))
		flags |= (SLBT_DRIVER_HEURISTICS
                          | SLBT_DRIVER_DEBUG);

	/* heuristics + debug + legabits */
	if (!(strcmp(program,"rdclibtool")))
		flags |= (SLBT_DRIVER_HEURISTICS
                          | SLBT_DRIVER_DEBUG
                          | SLBT_DRIVER_LEGABITS);

	/* driver context */
	if ((ret = slbt_lib_get_driver_ctx(argv,envp,flags|noclr,fdctx,&dctx)))
		return (ret == SLBT_USAGE)
			? !argv || !argv[0] || !argv[1] || !argv[2]
			: SLBT_ERROR;

	/* --dumpmachine disables all other actions */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_MACHINE)
		return slbt_output_machine(dctx)
			? SLBT_ERROR : SLBT_OK;

	/* --version must be the first (and only) action */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERSION)
		if (dctx->x_cctx->x_mode != SLBT_MODE_AR)
			if (dctx->x_cctx->x_mode != SLBT_MODE_STOOLIE)
				return (slbt_version(dctx,fdout) < 0)
					? slbt_exit(dctx,SLBT_ERROR)
					: slbt_exit(dctx,SLBT_OK);

	/* -print-aux-dir must be the first (and only) action */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_AUX_DIR)
		return (slbt_print_aux_dir(fdout) < 0)
			? slbt_exit(dctx,SLBT_ERROR)
			: slbt_exit(dctx,SLBT_OK);

	/* -print-m4-dir must be the first (and only) action */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_M4_DIR)
		return (slbt_print_m4_dir(fdout) < 0)
			? slbt_exit(dctx,SLBT_ERROR)
			: slbt_exit(dctx,SLBT_OK);

	/* -print-shared-ext must be the first (and only) action */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_SHARED_EXT)
		return (slbt_print_shared_ext(fdout,dctx) < 0)
			? slbt_exit(dctx,SLBT_ERROR)
			: slbt_exit(dctx,SLBT_OK);

	/* -print-static-ext must be the first (and only) action */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_OUTPUT_STATIC_EXT)
		return (slbt_print_static_ext(fdout,dctx) < 0)
			? slbt_exit(dctx,SLBT_ERROR)
			: slbt_exit(dctx,SLBT_OK);

	/* perform all other actions */
	slbt_perform_driver_actions(dctx);

	/* print --version on behalf of a secondary tool as needed */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERSION)
		return (slbt_version(dctx,fdout) < 0)
			? slbt_exit(dctx,SLBT_ERROR)
			: slbt_exit(dctx,SLBT_OK);

	return slbt_exit(dctx,dctx->x_errv[0] ? SLBT_ERROR : SLBT_OK);
}
