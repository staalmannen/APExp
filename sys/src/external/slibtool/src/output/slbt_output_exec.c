/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <slibtool/slibtool.h>

#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"

static const char aclr_null[]    = "";
static const char aclr_reset[]   = "\x1b[0m";
static const char aclr_bold[]    = "\x1b[1m";

static const char aclr_green[]   = "\x1b[32m";
static const char aclr_magenta[] = "\x1b[35m";
static const char aclr_white[]   = "\x1b[37m";

static int slbt_output_exec_annotated(
	const struct slbt_driver_ctx *	dctx,
	const struct slbt_exec_ctx *	ectx,
	const char *			step)
{
	int          fdout;
	char **      parg;
	const char * aclr_set;
	const char * aclr_color;
	const char * aclr_unset;

	fdout = (strcmp(step,"execute"))
		? slbt_driver_fdout(dctx)
		: slbt_driver_fderr(dctx);

	if (slbt_dprintf(
			fdout,"%s%s%s: %s%s%s%s:%s",
			aclr_bold,aclr_magenta,
			dctx->x_program,aclr_reset,
			aclr_bold,aclr_green,step,aclr_reset) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	for (parg=ectx->x_argv; *parg; parg++) {
		if ((parg == ectx->x_lout[0]) || (parg == ectx->x_mout[0])) {
			aclr_set      = aclr_bold;
			aclr_color    = aclr_white;
			aclr_unset    = aclr_null;
		} else {
			aclr_set      = aclr_null;
			aclr_color    = aclr_null;
			aclr_unset    = aclr_reset;
		}

		if (slbt_dprintf(
				fdout," %s%s%s%s",
				aclr_set,aclr_color,
				*parg,
				aclr_unset) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

	}

	if (slbt_dprintf(fdout,"\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}

static int slbt_output_exec_plain(
	const struct slbt_driver_ctx *	dctx,
	const struct slbt_exec_ctx *	ectx,
	const char *		step)
{
	int	fdout;
	char ** parg;

	fdout = (strcmp(step,"execute"))
		? slbt_driver_fdout(dctx)
		: slbt_driver_fderr(dctx);

	if (slbt_dprintf(fdout,"%s: %s:",dctx->x_program,step) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	for (parg=ectx->x_argv; *parg; parg++)
		if (slbt_dprintf(fdout," %s",*parg) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_dprintf(fdout,"\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}

int slbt_output_exec(
	const struct slbt_exec_ctx *	ectx,
	const char *			step)
{
	const struct slbt_driver_ctx *  dctx;
	int                             fdout;

	dctx  = (slbt_get_exec_ictx(ectx))->dctx;

	fdout = (strcmp(step,"execute"))
		? slbt_driver_fdout(dctx)
		: slbt_driver_fderr(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER)
		return slbt_output_exec_plain(dctx,ectx,step);

	else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_ALWAYS)
		return slbt_output_exec_annotated(dctx,ectx,step);

	else if (isatty(fdout))
		return slbt_output_exec_annotated(dctx,ectx,step);

	else
		return slbt_output_exec_plain(dctx,ectx,step);
}

int slbt_output_compile(const struct slbt_exec_ctx * ectx)
{
	return slbt_output_exec(ectx,"compile");
}

int slbt_output_execute(const struct slbt_exec_ctx * ectx)
{
	return slbt_output_exec(ectx,"execute");
}

int slbt_output_install(const struct slbt_exec_ctx * ectx)
{
	return slbt_output_exec(ectx,"install");
}

int slbt_output_link(const struct slbt_exec_ctx * ectx)
{
	return slbt_output_exec(ectx,"link");
}

int slbt_output_uninstall(const struct slbt_exec_ctx * ectx)
{
	return slbt_output_exec(ectx,"uninstall");
}
