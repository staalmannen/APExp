/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <slibtool/slibtool.h>
#include "slibtool_version.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"


slbt_hidden int slbt_init_version_info(
	struct slbt_driver_ctx_impl *	ictx,
	struct slbt_version_info *	verinfo)
{
	int	current;
	int	revision;
	int	age;
	int	colons;
	int	fmtcnt;
	const char * ch;

	if (!verinfo->vi_verinfo && !verinfo->vi_vernumber)
		return 0;

	if (verinfo->vi_vernumber) {
		sscanf(verinfo->vi_vernumber,"%d:%d:%d",
			&verinfo->vi_major,
			&verinfo->vi_minor,
			&verinfo->vi_revision);
		return 0;
	}

	current = revision = age = 0;

	for (colons=0, ch=verinfo->vi_verinfo; *ch; ch++)
		if (*ch == ':')
			colons++;

	fmtcnt = sscanf(verinfo->vi_verinfo,"%d:%d:%d",
		&current,&revision,&age);

	if (!fmtcnt || (fmtcnt > 3) || (fmtcnt != colons + 1)) {
		slbt_dprintf(ictx->fdctx.fderr,
			"%s: error: invalid version info: "
			"supported argument format is %%d[:%%d[:%%d]].\n",
			slbt_program_name(ictx->cctx.x_targv[0]));
		return -1;
	}

	if (current < age) {
		if (ictx->cctx.x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_dprintf(ictx->fdctx.fderr,
				"%s: error: invalid version info: "
				"<current> may not be smaller than <age>.\n",
				slbt_program_name(ictx->cctx.x_targv[0]));
		return -1;
	}

	verinfo->vi_major    = current - age;
	verinfo->vi_minor    = age;
	verinfo->vi_revision = revision;

	return 0;
}
