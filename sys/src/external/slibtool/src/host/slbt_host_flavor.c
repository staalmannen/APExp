/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"

/* elf rpath */
static const char * ldrpath_elf[] = {
	"/lib",
	"/lib/64",
	"/usr/lib",
	"/usr/lib64",
	"/usr/local/lib",
	"/usr/local/lib64",
	0};

/* flavor settings */
#define SLBT_FLAVOR_SETTINGS(flavor,          \
		bfmt,pic,                     \
		arp,ars,dsop,dsos,osds,osdf,  \
		exep,exes,impp,imps,maps,     \
		ldenv)                        \
	static const struct slbt_flavor_settings flavor = {  \
		bfmt,arp,ars,dsop,dsos,osds,osdf,           \
		exep,exes,impp,imps,maps,                  \
		ldenv,pic}

SLBT_FLAVOR_SETTINGS(host_flavor_default,       \
	"elf","-fPIC",                          \
	"lib",".a","lib",".so",".so","",        \
	"","","","",".expsyms.ver",             \
	"LD_LIBRARY_PATH");

SLBT_FLAVOR_SETTINGS(host_flavor_midipix,       \
	"pe","-fPIC",                           \
	"lib",".a","lib",".so",".so","",        \
	"","","lib",".lib.a",".expsyms.def",    \
	"LD_LIBRARY_PATH");

SLBT_FLAVOR_SETTINGS(host_flavor_mingw,         \
	"pe",0,                                 \
	"lib",".a","lib",".dll","",".dll",      \
	"",".exe","lib",".dll.a",".expsyms.def",\
	"PATH");

SLBT_FLAVOR_SETTINGS(host_flavor_cygwin,        \
	"pe",0,                                 \
	"lib",".a","lib",".dll","",".dll",      \
	"",".exe","lib",".dll.a",".expsyms.def",\
	"PATH");

SLBT_FLAVOR_SETTINGS(host_flavor_msys,          \
	"pe",0,                                 \
	"lib",".a","lib",".dll","",".dll",      \
	"",".exe","lib",".dll.a",".expsyms.def",\
	"PATH");

SLBT_FLAVOR_SETTINGS(host_flavor_darwin,        \
	"macho","-fPIC",                        \
	"lib",".a","lib",".dylib","",".dylib",  \
	"","","","",".expsyms.exp",             \
	"DYLD_LIBRARY_PATH");


slbt_hidden int slbt_init_ldrpath(
	struct slbt_common_ctx *  cctx,
	struct slbt_host_params * host)
{
	char *         buf;
	const char **  ldrpath;

	if (!cctx->x_rpath || !(cctx->x_drvflags & SLBT_DRIVER_IMAGE_ELF)) {
		host->ha_ldrpath = 0;
		return 0;
	}

	/* common? */
	for (ldrpath=ldrpath_elf; *ldrpath; ldrpath ++)
		if (!(strcmp(cctx->x_rpath,*ldrpath))) {
			host->ha_ldrpath = 0;
			return 0;
		}

	/* buf */
	if (!(buf = malloc(12 + strlen(cctx->x_host.ha_host))))
		return -1;

	/* /usr/{host}/lib */
	sprintf(buf,"/usr/%s/lib",cctx->x_host.ha_host);

	if (!(strcmp(cctx->x_rpath,buf))) {
		host->ha_ldrpath = 0;
		free(buf);
		return 0;
	}

	/* /usr/{host}/lib64 */
	sprintf(buf,"/usr/%s/lib64",cctx->x_host.ha_host);

	if (!(strcmp(cctx->x_rpath,buf))) {
		host->ha_ldrpath = 0;
		free(buf);
		return 0;
	}

	host->ha_ldrpath = cctx->x_rpath;

	free(buf);
	return 0;
}


slbt_hidden void slbt_init_flavor_settings(
	struct slbt_common_ctx *	cctx,
	const struct slbt_host_params * ahost,
	struct slbt_flavor_settings *	psettings)
{
	const struct slbt_host_params *     host;
	const struct slbt_flavor_settings * settings;

	host = ahost ? ahost : &cctx->x_host;

	if (!strcmp(host->ha_flavor,"midipix"))
		settings = &host_flavor_midipix;
	else if (!strcmp(host->ha_flavor,"mingw"))
		settings = &host_flavor_mingw;
	else if (!strcmp(host->ha_flavor,"cygwin"))
		settings = &host_flavor_cygwin;
	else if (!strcmp(host->ha_flavor,"msys"))
		settings = &host_flavor_msys;
	else if (!strcmp(host->ha_flavor,"darwin"))
		settings = &host_flavor_darwin;
	else
		settings = &host_flavor_default;

	if (!ahost) {
		if (!strcmp(settings->fa_imagefmt,"elf"))
			cctx->x_drvflags |= SLBT_DRIVER_IMAGE_ELF;
		else if (!strcmp(settings->fa_imagefmt,"pe"))
			cctx->x_drvflags |= SLBT_DRIVER_IMAGE_PE;
		else if (!strcmp(settings->fa_imagefmt,"macho"))
			cctx->x_drvflags |= SLBT_DRIVER_IMAGE_MACHO;
	}

	memcpy(psettings,settings,sizeof(*settings));
}


int slbt_host_flavor_settings(
	const char *                            flavor,
	const struct slbt_flavor_settings **    settings)
{
	if (!strcmp(flavor,"midipix"))
		*settings = &host_flavor_midipix;
	else if (!strcmp(flavor,"mingw"))
		*settings = &host_flavor_mingw;
	else if (!strcmp(flavor,"cygwin"))
		*settings = &host_flavor_cygwin;
	else if (!strcmp(flavor,"msys"))
		*settings = &host_flavor_msys;
	else if (!strcmp(flavor,"darwin"))
		*settings = &host_flavor_darwin;
	else if (!strcmp(flavor,"default"))
		*settings = &host_flavor_default;
	else
		*settings = 0;

	return *settings ? 0 : -1;
}


int slbt_host_objfmt_is_coff(const struct slbt_driver_ctx * dctx)
{
	const char * flavor = dctx->x_cctx->x_host.ha_flavor;

	return !strcmp(flavor,"midipix")
		|| !strcmp(flavor,"mingw")
		|| !strcmp(flavor,"cygwin")
		|| !strcmp(flavor,"msys");
}


int slbt_host_objfmt_is_macho(const struct slbt_driver_ctx * dctx)
{
	const char * flavor = dctx->x_cctx->x_host.ha_flavor;

	return !strcmp(flavor,"darwin");
}


int slbt_host_group_is_winnt(const struct slbt_driver_ctx * dctx)
{
	return slbt_host_objfmt_is_coff(dctx);
}


int slbt_host_group_is_darwin(const struct slbt_driver_ctx * dctx)
{
	return slbt_host_objfmt_is_macho(dctx);
}
