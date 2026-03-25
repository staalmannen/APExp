/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <spawn.h>
#include <sys/wait.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"
#include "slibtool_ar_impl.h"

/* preferred native tools, specified at the time of configuration for the host */
static const char * slbt_native_ar_variant     = SLBT_PREFERRED_HOST_AR;
static const char * slbt_native_as_variant     = SLBT_PREFERRED_HOST_AS;
static const char * slbt_native_nm_variant     = SLBT_PREFERRED_HOST_NM;
static const char * slbt_native_ranlib_variant = SLBT_PREFERRED_HOST_RANLIB;

/* annotation strings */
static const char cfgexplicit[] = "command-line argument";
static const char cfghost[]     = "derived from <host>";
static const char cfgar[]       = "derived from <ar>";
static const char cfgranlib[]   = "derived from <ranlib>";
static const char cfgtarget[]   = "derived from <target>";
static const char cfgcompiler[] = "derived from <compiler>";
static const char cfgnmachine[] = "native (cached in ccenv/host.mk)";
static const char cfgxmachine[] = "foreign (derived from -dumpmachine)";
static const char cfguseropt[]  = "native (preferred alternative)";
static const char cfgnative[]   = "native (system default)";

static void slbt_get_host_quad(
	char *	hostbuf,
	char ** hostquad)
{
	char *	mark;
	char *	ch;
	int	i;

	for (i=0, ch=hostbuf, mark=hostbuf; *ch && i<4; ch++) {
		if (*ch == '-') {
			*ch = 0;
			hostquad[i++] = mark;
			mark = &ch[1];
		}
	}

	if (i<4)
		hostquad[i] = mark;

	if (i==3) {
		hostquad[1] = hostquad[2];
		hostquad[2] = hostquad[3];
		hostquad[3] = 0;
	}
}


static void slbt_spawn_ar(char ** argv, int * ecode)
{
	int	estatus;
	pid_t	pid;

	*ecode = 127;

	if ((pid = slbt_fork()) < 0) {
		return;

	} else if (pid == 0) {
		execvp(argv[0],argv);
		_exit(errno);

	} else {
		waitpid(pid,&estatus,0);

		if (WIFEXITED(estatus))
			*ecode = WEXITSTATUS(estatus);
	}
}


slbt_hidden int slbt_init_host_params(
	const struct slbt_driver_ctx *	dctx,
	const struct slbt_common_ctx *	cctx,
	struct slbt_host_strs *		drvhost,
	struct slbt_host_params *	host,
	struct slbt_host_params *	cfgmeta,
	const char *                    cfgmeta_host,
	const char *                    cfgmeta_ar,
	const char *                    cfgmeta_as,
	const char *                    cfgmeta_nm,
	const char *                    cfgmeta_ranlib,
	const char *                    cfgmeta_dlltool,
	const char *                    mkvars)
{
	int		fdcwd;
	int		arprobe;
	int		arfd;
	int		ecode;
	int             cint;
	size_t		toollen;
	size_t          altlen;
	char *		dash;
	char *		base;
	char *		mark;
	const char *	machine;
	bool		ftarget       = false;
	bool		fhost         = false;
	bool		fcompiler     = false;
	bool		fnative       = false;
	bool		fnativear     = false;
	bool		fdumpmachine  = false;
	char		buf        [256];
	char		hostbuf    [256];
	char		machinebuf [256];
	char *		hostquad   [4];
	char *		machinequad[4];
	char *		arprobeargv[4];
	char		archivename[] = "/tmp/slibtool.ar.probe.XXXXXXXXXXXXXXXX";

	/* base */
	if ((base = strrchr(cctx->x_cargv[0],'/')))
		base++;
	else
		base = cctx->x_cargv[0];

	fdumpmachine  = (cctx->x_mode == SLBT_MODE_COMPILE)
			|| (cctx->x_mode == SLBT_MODE_LINK)
			|| (cctx->x_mode == SLBT_MODE_INFO);

	fdumpmachine &= (!strcmp(base,"xgcc")
			|| !strcmp(base,"xg++"));

	/* support the portbld <--> unknown synonym */
	if (!(drvhost->machine = strdup(SLBT_MACHINE)))
		return -1;

	if ((mark = strstr(drvhost->machine,"-portbld-")))
		memcpy(mark,"-unknown",8);

	/* host */
	if (host->ha_host) {
		cfgmeta->ha_host = cfgmeta_host ? cfgmeta_host : cfgexplicit;
		fhost            = true;

	} else if (cctx->x_target) {
		host->ha_host    = cctx->x_target;
		cfgmeta->ha_host = cfgtarget;
		ftarget          = true;

	} else if (!strcmp(base,"slibtool-ar")) {
		host->ha_host    = drvhost->machine;
		cfgmeta->ha_host = cfgnmachine;
		fnative          = true;

	} else if (strrchr(base,'-')) {
		if (!(drvhost->host = strdup(cctx->x_cargv[0])))
			return -1;

		dash             = strrchr(drvhost->host,'-');
		*dash            = 0;
		host->ha_host    = drvhost->host;
		cfgmeta->ha_host = cfgcompiler;
		fcompiler        = true;

	} else if (!fdumpmachine) {
		host->ha_host    = drvhost->machine;
		cfgmeta->ha_host = cfgnmachine;

	} else if (slbt_util_dump_machine(cctx->x_cargv[0],buf,sizeof(buf)) < 0) {
		if (dctx)
			slbt_dprintf(
				slbt_driver_fderr(dctx),
				"%s: could not determine host "
				"via -dumpmachine\n",
				dctx->x_program);
		return -1;

	} else {
		if (!(drvhost->host = strdup(buf)))
			return -1;

		host->ha_host    = drvhost->host;
		fcompiler        = true;
		fnative          = !strcmp(host->ha_host,drvhost->machine);
		cfgmeta->ha_host = fnative ? cfgnmachine : cfgxmachine;

		if (!fnative) {
			strcpy(hostbuf,host->ha_host);
			strcpy(machinebuf,drvhost->machine);

			slbt_get_host_quad(hostbuf,hostquad);
			slbt_get_host_quad(machinebuf,machinequad);

			if (hostquad[2] && machinequad[2])
				fnative = !strcmp(hostquad[0],machinequad[0])
					&& !strcmp(hostquad[1],machinequad[1])
					&& !strcmp(hostquad[2],machinequad[2]);
		}
	}

	/* flavor */
	if (host->ha_flavor) {
		cfgmeta->ha_flavor = cfgexplicit;
	} else {
		if (fhost) {
			machine            = host->ha_host;
			cfgmeta->ha_flavor = cfghost;
		} else if (ftarget) {
			machine            = cctx->x_target;
			cfgmeta->ha_flavor = cfgtarget;
		} else if (fcompiler) {
			machine            = drvhost->host;
			cfgmeta->ha_flavor = cfgcompiler;
		} else {
			machine            = drvhost->machine;
			cfgmeta->ha_flavor = cfgnmachine;
		}

		dash = strrchr(machine,'-');
		cfgmeta->ha_flavor = cfghost;

		if ((dash && !strcmp(dash,"-bsd")) || strstr(machine,"-bsd-"))
			host->ha_flavor = "bsd";
		else if ((dash && !strcmp(dash,"-cygwin")) || strstr(machine,"-cygwin-"))
			host->ha_flavor = "cygwin";
		else if ((dash && !strcmp(dash,"-msys")) || strstr(machine,"-msys-"))
			host->ha_flavor = "msys";
		else if ((dash && !strcmp(dash,"-darwin")) || strstr(machine,"-darwin"))
			host->ha_flavor = "darwin";
		else if ((dash && !strcmp(dash,"-linux")) || strstr(machine,"-linux-"))
			host->ha_flavor = "linux";
		else if ((dash && !strcmp(dash,"-midipix")) || strstr(machine,"-midipix-"))
			host->ha_flavor = "midipix";
		else if ((dash && !strcmp(dash,"-mingw")) || strstr(machine,"-mingw-"))
			host->ha_flavor = "mingw";
		else if ((dash && !strcmp(dash,"-mingw32")) || strstr(machine,"-mingw32-"))
			host->ha_flavor = "mingw";
		else if ((dash && !strcmp(dash,"-mingw64")) || strstr(machine,"-mingw64-"))
			host->ha_flavor = "mingw";
		else if ((dash && !strcmp(dash,"-windows")) || strstr(machine,"-windows-"))
			host->ha_flavor = "mingw";
		else {
			host->ha_flavor   = "default";
			cfgmeta->ha_flavor = "fallback, unverified";
		}

		if (fcompiler && !fnative)
			if ((mark = strstr(drvhost->machine,host->ha_flavor)))
				if (mark > drvhost->machine)
					fnative = (*--mark == '-');
	}

	/* toollen */
	toollen =  fnative ? 0 : strlen(host->ha_host);
	toollen += strlen("-utility-name");
	toollen += host->ha_ranlib ? strlen(host->ha_ranlib) : 0;

	if (fnative && slbt_native_ar_variant)
		if ((altlen = strlen(slbt_native_ar_variant)) > toollen)
			toollen = altlen;

	if (fnative && slbt_native_as_variant)
		if ((altlen = strlen(slbt_native_as_variant)) > toollen)
			toollen = altlen;

	if (fnative && slbt_native_nm_variant)
		if ((altlen = strlen(slbt_native_nm_variant)) > toollen)
			toollen = altlen;

	if (fnative && slbt_native_ranlib_variant)
		if ((altlen = strlen(slbt_native_ranlib_variant)) > toollen)
			toollen = altlen;

	/* ar */
	if (host->ha_ar)
		cfgmeta->ha_ar = cfgmeta_ar ? cfgmeta_ar : cfgexplicit;
	else {
		if (!(drvhost->ar = calloc(1,toollen)))
			return -1;

		if (fnative && slbt_native_ar_variant) {
			strcpy(drvhost->ar,slbt_native_ar_variant);
			cfgmeta->ha_ar = cfguseropt;
			arprobe = 0;
		} else if (fnative) {
			strcpy(drvhost->ar,"ar");
			cfgmeta->ha_ar = cfgnative;
			arprobe = 0;
		} else if (cctx->x_mode == SLBT_MODE_LINK) {
			arprobe = true;
		} else if (cctx->x_mode == SLBT_MODE_INFO) {
			arprobe = true;
		} else if (mkvars) {
			arprobe = true;
		} else {
			arprobe = false;
		}

		/* arprobe */
		if (arprobe) {
			sprintf(drvhost->ar,"%s-ar",host->ha_host);
			cfgmeta->ha_ar = cfghost;
			ecode          = 127;

			/* empty archive */
			if ((arfd = mkstemp(archivename)) >= 0) {
				slbt_dprintf(arfd,"!<arch>\n");

				arprobeargv[0] = drvhost->ar;
				arprobeargv[1] = "-t";
				arprobeargv[2] = archivename;
				arprobeargv[3] = 0;

				/* <target>-ar */
				slbt_spawn_ar(
					arprobeargv,
					&ecode);
			}

			/* <target>-<compiler>-ar */
			if (ecode && !strchr(base,'-')) {
				sprintf(drvhost->ar,"%s-%s-ar",host->ha_host,base);

				slbt_spawn_ar(
					arprobeargv,
					&ecode);
			}

			/* <compiler>-ar */
			if (ecode && !strchr(base,'-')) {
				sprintf(drvhost->ar,"%s-ar",base);

				slbt_spawn_ar(
					arprobeargv,
					&ecode);
			}

			/* if target is the native target, fallback to native ar */
			if ((fnative = (ecode && !strcmp(host->ha_host,SLBT_MACHINE)))) {
				if (slbt_native_ar_variant) {
					strcpy(drvhost->ar,slbt_native_ar_variant);
					cfgmeta->ha_ar = cfguseropt;
				} else {
					strcpy(drvhost->ar,"ar");
					cfgmeta->ha_ar = cfgnative;
				}
			}

			/* fdcwd */
			fdcwd = slbt_driver_fdcwd(dctx);

			/* clean up */
			if (arfd >= 0) {
				unlinkat(fdcwd,archivename,0);
				close(arfd);
			}
		}

		host->ha_ar = drvhost->ar;
	}

	if (!fnative && slbt_native_ar_variant) {
		if (!strcmp(host->ha_ar,slbt_native_ar_variant)) {
			fnative   = true;
			fnativear = true;
		}
	}

	if (!fnative && !strncmp(host->ha_ar,"ar",2)) {
		if (!host->ha_ar[2] || isspace((cint = host->ha_ar[2]))) {
			fnative   = true;
			fnativear = true;
		}
	}

	/* as */
	if (host->ha_as)
		cfgmeta->ha_as = cfgmeta_as ? cfgmeta_as : cfgexplicit;
	else {
		if (!(drvhost->as = calloc(1,toollen)))
			return -1;

		if (fnative && slbt_native_as_variant) {
			strcpy(drvhost->as,slbt_native_as_variant);
			cfgmeta->ha_as = cfguseropt;
		} else if (fnative) {
			strcpy(drvhost->as,"as");
			cfgmeta->ha_as = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->as,"%s-as",host->ha_host);
			cfgmeta->ha_as = cfghost;
		}

		if (host->ha_ranlib && (mark = strrchr(host->ha_ranlib,'/'))) {
			if (strcmp(++mark,"ranlib"))
				if ((mark = strrchr(mark,'-')))
					if (strcmp(++mark,"ranlib"))
						mark = 0;

			if (mark) {
				strcpy(drvhost->as,host->ha_ranlib);
				strcpy(&drvhost->as[mark-host->ha_ranlib],"as");
				cfgmeta->ha_as = cfgranlib;
			}
		}

		host->ha_as = drvhost->as;
	}

	/* nm */
	if (host->ha_nm)
		cfgmeta->ha_nm = cfgmeta_nm ? cfgmeta_nm : cfgexplicit;
	else {
		if (!(drvhost->nm = calloc(1,toollen)))
			return -1;

		if (fnative && slbt_native_nm_variant) {
			strcpy(drvhost->nm,slbt_native_nm_variant);
			cfgmeta->ha_nm = cfguseropt;
		} else if (fnative) {
			strcpy(drvhost->nm,"nm");
			cfgmeta->ha_nm = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->nm,"%s-nm",host->ha_host);
			cfgmeta->ha_nm = cfghost;
		}

		host->ha_nm = drvhost->nm;
	}

	/* ranlib */
	if (host->ha_ranlib)
		cfgmeta->ha_ranlib = cfgmeta_ranlib ? cfgmeta_ranlib : cfgexplicit;
	else {
		if (!(drvhost->ranlib = calloc(1,toollen)))
			return -1;

		if (fnative && slbt_native_ranlib_variant) {
			strcpy(drvhost->ranlib,slbt_native_ranlib_variant);
			cfgmeta->ha_ranlib = cfguseropt;
		} else if (fnative) {
			strcpy(drvhost->ranlib,"ranlib");
			cfgmeta->ha_ranlib = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->ranlib,"%s-ranlib",host->ha_host);
			cfgmeta->ha_ranlib = cfghost;
		}

		host->ha_ranlib = drvhost->ranlib;
	}

	/* windres */
	if (host->ha_windres)
		cfgmeta->ha_windres = cfgexplicit;

	else if (strcmp(host->ha_flavor,"cygwin")
			&& strcmp(host->ha_flavor,"msys")
			&& strcmp(host->ha_flavor,"midipix")
			&& strcmp(host->ha_flavor,"mingw")) {
		host->ha_windres    = "";
		cfgmeta->ha_windres = "not applicable";

	} else {
		if (!(drvhost->windres = calloc(1,toollen)))
			return -1;

		if (fnative) {
			strcpy(drvhost->windres,"windres");
			cfgmeta->ha_windres = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->windres,"%s-windres",host->ha_host);
			cfgmeta->ha_windres = cfghost;
		}

		if ((mark = strrchr(host->ha_ranlib,'/'))) {
			if (strcmp(++mark,"ranlib"))
				if ((mark = strrchr(mark,'-')))
					if (strcmp(++mark,"ranlib"))
						mark = 0;

			if (mark) {
				strcpy(drvhost->windres,host->ha_ranlib);
				strcpy(&drvhost->windres[mark-host->ha_ranlib],"windres");
				cfgmeta->ha_windres = cfgranlib;
			}
		}

		host->ha_windres = drvhost->windres;
	}

	/* dlltool */
	if (host->ha_dlltool)
		cfgmeta->ha_dlltool = cfgmeta_dlltool ? cfgmeta_dlltool : cfgexplicit;

	else if (strcmp(host->ha_flavor,"cygwin")
			&& strcmp(host->ha_flavor,"msys")
			&& strcmp(host->ha_flavor,"midipix")
			&& strcmp(host->ha_flavor,"mingw")) {
		host->ha_dlltool = "";
		cfgmeta->ha_dlltool = "not applicable";

	} else {
		if (!(drvhost->dlltool = calloc(1,toollen)))
			return -1;

		if (fnative) {
			strcpy(drvhost->dlltool,"dlltool");
			cfgmeta->ha_dlltool = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->dlltool,"%s-dlltool",host->ha_host);
			cfgmeta->ha_dlltool = cfghost;
		}

		if ((mark = strrchr(host->ha_ranlib,'/'))) {
			if (strcmp(++mark,"ranlib"))
				if ((mark = strrchr(mark,'-')))
					if (strcmp(++mark,"ranlib"))
						mark = 0;

			if (mark) {
				strcpy(drvhost->dlltool,host->ha_ranlib);
				strcpy(&drvhost->dlltool[mark-host->ha_ranlib],"dlltool");
				cfgmeta->ha_dlltool = cfgranlib;
			}
		}

		host->ha_dlltool = drvhost->dlltool;
	}

	/* mdso */
	if (host->ha_mdso)
		cfgmeta->ha_mdso = cfgexplicit;

	else if (strcmp(host->ha_flavor,"cygwin")
			&& strcmp(host->ha_flavor,"msys")
			&& strcmp(host->ha_flavor,"midipix")
			&& strcmp(host->ha_flavor,"mingw")) {
		host->ha_mdso = "";
		cfgmeta->ha_mdso = "not applicable";

	} else {
		if (!(drvhost->mdso = calloc(1,toollen)))
			return -1;

		if (fnative) {
			strcpy(drvhost->mdso,"mdso");
			cfgmeta->ha_mdso = fnativear ? cfgar : cfgnative;
		} else {
			sprintf(drvhost->mdso,"%s-mdso",host->ha_host);
			cfgmeta->ha_mdso = cfghost;
		}

		host->ha_mdso = drvhost->mdso;
	}

	return 0;
}

static void slbt_free_host_tool_argv(char ** argv)
{
	char ** parg;

	if (!argv)
		return;

	for (parg=argv; *parg; parg++)
		free(*parg);

	free(argv);
}

slbt_hidden void slbt_free_host_params(struct slbt_host_strs * host)
{
	if (host->machine)
		free(host->machine);

	if (host->host)
		free(host->host);

	if (host->flavor)
		free(host->flavor);

	if (host->ar)
		free(host->ar);

	if (host->as)
		free(host->as);

	if (host->nm)
		free(host->nm);

	if (host->ranlib)
		free(host->ranlib);

	if (host->windres)
		free(host->windres);

	if (host->dlltool)
		free(host->dlltool);

	if (host->mdso)
		free(host->mdso);

	slbt_free_host_tool_argv(host->ar_argv);
	slbt_free_host_tool_argv(host->as_argv);
	slbt_free_host_tool_argv(host->nm_argv);
	slbt_free_host_tool_argv(host->ranlib_argv);
	slbt_free_host_tool_argv(host->windres_argv);
	slbt_free_host_tool_argv(host->dlltool_argv);
	slbt_free_host_tool_argv(host->mdso_argv);

	memset(host,0,sizeof(*host));
}


void slbt_host_reset_althost(const struct slbt_driver_ctx * ctx)
{
	struct slbt_driver_ctx_alloc *	ictx;
	uintptr_t			addr;

	addr = (uintptr_t)ctx - offsetof(struct slbt_driver_ctx_alloc,ctx);
	addr = addr - offsetof(struct slbt_driver_ctx_impl,ctx);
	ictx = (struct slbt_driver_ctx_alloc *)addr;

	slbt_free_host_params(&ictx->ctx.ahost);
}

int  slbt_host_set_althost(
	const struct slbt_driver_ctx *	ctx,
	const char *			host,
	const char *			flavor)
{
	struct slbt_driver_ctx_alloc *	ictx;
	uintptr_t			addr;

	addr = (uintptr_t)ctx - offsetof(struct slbt_driver_ctx_alloc,ctx);
	addr = addr - offsetof(struct slbt_driver_ctx_impl,ctx);
	ictx = (struct slbt_driver_ctx_alloc *)addr;
	slbt_free_host_params(&ictx->ctx.ahost);

	if (!(ictx->ctx.ahost.host = strdup(host)))
		return SLBT_SYSTEM_ERROR(ctx);

	if (!(ictx->ctx.ahost.flavor = strdup(flavor))) {
		slbt_free_host_params(&ictx->ctx.ahost);
		return SLBT_SYSTEM_ERROR(ctx);
	}

	ictx->ctx.cctx.x_ahost.ha_host   = ictx->ctx.ahost.host;
	ictx->ctx.cctx.x_ahost.ha_flavor = ictx->ctx.ahost.flavor;

	if (slbt_init_host_params(
			0,
			ctx->x_cctx,
			&ictx->ctx.ahost,
			&ictx->ctx.cctx.x_ahost,
			&ictx->ctx.cctx.x_acfgmeta,
			0,0,0,0,0,0,0)) {
		slbt_free_host_params(&ictx->ctx.ahost);
		return SLBT_CUSTOM_ERROR(ctx,SLBT_ERR_HOST_INIT);
	}

	slbt_init_flavor_settings(
		&ictx->ctx.cctx,
		&ictx->ctx.cctx.x_ahost,
		&ictx->ctx.cctx.x_asettings);

	if (slbt_init_ldrpath(
			&ictx->ctx.cctx,
			&ictx->ctx.cctx.x_ahost)) {
		slbt_free_host_params(&ictx->ctx.ahost);
		return SLBT_CUSTOM_ERROR(ctx,SLBT_ERR_LDRPATH_INIT);
	}

	return 0;
}
