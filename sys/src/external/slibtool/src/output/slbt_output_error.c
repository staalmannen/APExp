/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <slibtool/slibtool.h>

#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"

static const char aclr_reset[]   = "\x1b[0m";
static const char aclr_bold[]    = "\x1b[1m";

static const char aclr_red[]     = "\x1b[31m";
static const char aclr_green[]   = "\x1b[32m";
static const char aclr_blue[]    = "\x1b[34m";
static const char aclr_magenta[] = "\x1b[35m";

static const char * slbt_output_error_header(const struct slbt_error_info * erri)
{
	if (erri->eflags & SLBT_ERROR_CHILD)
		return "exec error upon";

	else if (erri->eflags & SLBT_ERROR_TOP_LEVEL)
		return "error logged in";

	else if (erri->eflags & SLBT_ERROR_NESTED)
		return "< returned to >";

	else
		return "distorted state";
}

static const char * slbt_output_unit_header(const struct slbt_error_info * erri)
{
	if (!(erri->eflags & SLBT_ERROR_CUSTOM))
		return "while opening";

	else
		return "while parsing";
}

static const char * slbt_output_strerror(
	const struct slbt_error_info * erri,
	char (*errbuf)[256])
{
	if (erri->eflags & SLBT_ERROR_CUSTOM)
		return "flow error: unexpected condition or other";

	else if (erri->eflags & SLBT_ERROR_NESTED)
		return "";

	else if (erri->eflags & SLBT_ERROR_CHILD)
		return "(see child process error messages)";

	else if (erri->esyscode == ENOBUFS)
		return "input error: string length exceeds buffer size";

	else
		return strerror_r(erri->esyscode,*errbuf,sizeof(*errbuf))
			? "internal error: strerror_r(3) call failed"
			: *errbuf;
}

static int slbt_output_error_record_plain(
	const struct slbt_driver_ctx *	dctx,
	const struct slbt_error_info *	erri)
{
	const char * epath;
	char         errbuf[256];

	int          fderr   = slbt_driver_fderr(dctx);
	const char * errdesc = slbt_output_strerror(erri,&errbuf);

	epath = erri->euctx
		? *erri->euctx->x_path
		: erri->eunit;

	if (epath && !(erri->eflags & SLBT_ERROR_NESTED))
		if (slbt_dprintf(
				fderr,
				"%s: [%s] '%s':\n",
				dctx->x_program,
				slbt_output_unit_header(erri),
				epath) < 0)
			return -1;

	if (slbt_dprintf(
			fderr,
			"%s: %s %s(), line %d%s%s.\n",
			dctx->x_program,
			slbt_output_error_header(erri),
			erri->efunction,
			erri->eline,
			strlen(errdesc) ? ": " : "",
			errdesc) < 0)
		return -1;

	return 0;
}

static int slbt_output_error_record_annotated(
	const struct slbt_driver_ctx *	dctx,
	const struct slbt_error_info *	erri)
{
	const char * epath;
	char         errbuf[256];

	int          fderr   = slbt_driver_fderr(dctx);
	const char * errdesc = slbt_output_strerror(erri,&errbuf);

	epath = erri->euctx
		? *erri->euctx->x_path
		: erri->eunit;

	if (epath && !(erri->eflags & SLBT_ERROR_NESTED))
		if (slbt_dprintf(
				fderr,
				"%s%s%s:%s %s[%s]%s %s%s'%s'%s:\n",

				aclr_bold,aclr_magenta,
				dctx->x_program,
				aclr_reset,

				aclr_bold,
				slbt_output_unit_header(erri),
				aclr_reset,

				aclr_bold,aclr_red,
				epath,
				aclr_reset) < 0)
			return -1;

	if (slbt_dprintf(
			fderr,
			"%s%s%s:%s %s%s%s %s%s%s()%s, %s%sline %d%s%s%s%s%s.\n",

			aclr_bold,aclr_magenta,
			dctx->x_program,
			aclr_reset,

			aclr_bold,
			slbt_output_error_header(erri),
			aclr_reset,

			aclr_bold,aclr_blue,
			erri->efunction,
			aclr_reset,

			aclr_bold,aclr_green,
			erri->eline,
			aclr_reset,
			strlen(errdesc) ? ": " : "",

			aclr_bold,
			errdesc,
			aclr_reset) < 0)
		return -1;

	return 0;
}

int slbt_output_error_record(
	const struct slbt_error_info *	erri)
{
	const struct slbt_driver_ctx *	dctx;
	int                             fderr;

	dctx  = erri->edctx;
	fderr = slbt_driver_fderr(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER)
		return slbt_output_error_record_plain(dctx,erri);

	else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_ALWAYS)
		return slbt_output_error_record_annotated(dctx,erri);

	else if (isatty(fderr))
		return slbt_output_error_record_annotated(dctx,erri);

	else
		return slbt_output_error_record_plain(dctx,erri);
}

static int slbt_output_error_vector_plain(const struct slbt_driver_ctx * dctx)
{
	const struct slbt_error_info ** perr;

	for (perr=dctx->x_errv; *perr; perr++)
		if (slbt_output_error_record_plain(dctx,*perr))
			return -1;

	return 0;
}

static int slbt_output_error_vector_annotated(const struct slbt_driver_ctx * dctx)
{
	const struct slbt_error_info ** perr;

	for (perr=dctx->x_errv; *perr; perr++)
		if (slbt_output_error_record_annotated(dctx,*perr))
			return -1;

	return 0;
}

int slbt_output_error_vector(const struct slbt_driver_ctx * dctx)
{
	int fderr = slbt_driver_fderr(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER)
		return slbt_output_error_vector_plain(dctx);

	else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_ALWAYS)
		return slbt_output_error_vector_annotated(dctx);

	else if (isatty(fderr))
		return slbt_output_error_vector_annotated(dctx);

	else
		return slbt_output_error_vector_plain(dctx);
}
