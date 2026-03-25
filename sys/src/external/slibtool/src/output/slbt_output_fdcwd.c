/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <slibtool/slibtool.h>

#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_realpath_impl.h"

static const char aclr_reset[]   = "\x1b[0m";
static const char aclr_bold[]    = "\x1b[1m";

static const char aclr_green[]   = "\x1b[32m";
static const char aclr_blue[]    = "\x1b[34m";
static const char aclr_magenta[] = "\x1b[35m";

static int slbt_output_fdcwd_plain(const struct slbt_driver_ctx * dctx)
{
	char         path[PATH_MAX];
	char         scwd[20];

	int          fdcwd   = slbt_driver_fdcwd(dctx);
	int          fderr   = slbt_driver_fderr(dctx);
	int          ferror  = 0;

	if (fdcwd == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fdcwd);
	}

	if (slbt_realpath(fdcwd,".",0,path,sizeof(path)) < 0) {
		ferror = 1;
		memset(path,0,sizeof(path));
		strerror_r(errno,path,sizeof(path));
	}

	if (slbt_dprintf(
			fderr,
			"%s: %s: {.fdcwd=%s, .realpath%s=%c%s%c}.\n",
			dctx->x_program,
			"fdcwd",
			scwd,
			ferror ? ".error" : "",
			ferror ? '[' : '"',
			path,
			ferror ? ']' : '"') < 0)
		return -1;

	return 0;
}

static int slbt_output_fdcwd_annotated(const struct slbt_driver_ctx * dctx)
{
	char         path[PATH_MAX];
	char         scwd[20];

	int          fdcwd   = slbt_driver_fdcwd(dctx);
	int          fderr   = slbt_driver_fderr(dctx);
	int          ferror  = 0;

	if (fdcwd == AT_FDCWD) {
		strcpy(scwd,"AT_FDCWD");
	} else {
		sprintf(scwd,"%d",fdcwd);
	}

	if (slbt_realpath(fdcwd,".",0,path,sizeof(path)) < 0) {
		ferror = 1;
		memset(path,0,sizeof(path));
		strerror_r(errno,path,sizeof(path));
	}

	if (slbt_dprintf(
			fderr,
			"%s%s%s%s: %s%s%s: {.fdcwd=%s%s%s%s, .realpath%s=%s%s%c%s%c%s}.\n",

			aclr_bold,aclr_magenta,
			dctx->x_program,
			aclr_reset,

			aclr_bold,
			"fdcwd",
			aclr_reset,

			aclr_bold,aclr_blue,
			scwd,
			aclr_reset,

			ferror ? ".error" : "",
			aclr_bold,aclr_green,
			ferror ? '[' : '"',
			path,
			ferror ? ']' : '"',
			aclr_reset) < 0)
		return -1;

	return 0;
}

int slbt_output_fdcwd(const struct slbt_driver_ctx * dctx)
{
	int fderr = slbt_driver_fderr(dctx);

	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER)
		return slbt_output_fdcwd_plain(dctx);

	else if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_ALWAYS)
		return slbt_output_fdcwd_annotated(dctx);

	else if (isatty(fderr))
		return slbt_output_fdcwd_annotated(dctx);

	else
		return slbt_output_fdcwd_plain(dctx);
}
