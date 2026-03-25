/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_install_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_readlink_impl.h"
#include "slibtool_spawn_impl.h"
#include "slibtool_symlink_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_snprintf_impl.h"
#include "argv/argv.h"

static int slbt_install_usage(
	int				fdout,
	const char *			program,
	const char *			arg,
	const struct argv_option **	optv,
	struct argv_meta *		meta,
	int				noclr)
{
	char header[512];

	snprintf(header,sizeof(header),
		"Usage: %s --mode=install <install> [options] [SOURCE]... DEST\n"
		"Options:\n",
		program);

	switch (noclr) {
		case 0:
			slbt_argv_usage(fdout,header,optv,arg);
			break;

		default:
			slbt_argv_usage_plain(fdout,header,optv,arg);
			break;
	}

	slbt_argv_free(meta);

	return SLBT_USAGE;
}

static int slbt_exec_install_fail(
	struct slbt_exec_ctx *	ectx,
	struct argv_meta *	meta,
	int			ret)
{
	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);
	return ret;
}

static int slbt_exec_install_init_dstdir(
	const struct slbt_driver_ctx *	dctx,
	struct argv_entry *	dest,
	struct argv_entry *	last,
	char *			dstdir)
{
	int		fdcwd;
	struct stat	st;
	char *		slash;
	size_t		len;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* last */
	if (dest)
		last = dest;

	/* dstdir: initial string */
	if (slbt_snprintf(dstdir,PATH_MAX,
			"%s",last->arg) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* dstdir might end with a slash */
	len = strlen(dstdir);

	if (dstdir[--len] == '/')
		dstdir[len] = 0;

	/* -t DSTDIR? */
	if (dest)
		return 0;

	/* is DEST a directory? */
	if (!fstatat(fdcwd,dstdir,&st,0))
		if (S_ISDIR(st.st_mode))
			return 0;

	/* remove last path component */
	if ((slash = strrchr(dstdir,'/')))
		*slash = 0;

	return 0;
}

static int slbt_exec_install_import_libraries(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char *				srcdso,
	char *				dstdir)
{
	char *	slash;
	char *	dot;
	char *	mark;
	char	srcbuf [PATH_MAX];
	char	implib [PATH_MAX];
	char	hostlnk[PATH_MAX];
	char	major  [128];
	char	minor  [128];
	char	rev    [128];

	/* .libs/libfoo.so.x.y.z */
	if (slbt_snprintf(srcbuf,sizeof(srcbuf),
			"%s",srcdso) <0)
		return SLBT_BUFFER_ERROR(dctx);

	/* (dso is under .libs) */
	if (!(slash = strrchr(srcbuf,'/')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

	/* libfoo.so.x.y.z */
	const char * impsuffix = dctx->x_cctx->x_settings.fa_impsuffix;

	if (slbt_snprintf(implib,
			sizeof(implib) - strlen(impsuffix),
			"%s",++slash) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* guard against an infinitely long version */
	mark = srcbuf + strlen(srcbuf);

	if (dctx->x_cctx->x_asettings.fa_osdfussix[0]) {
		if (!(dot = strrchr(srcbuf,'.')))
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

		*dot = 0;
	}

	/* rev */
	if (!(dot = strrchr(srcbuf,'.')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);
	else if ((size_t)(mark - dot) > sizeof(rev))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_REV);
	else {
		strcpy(rev,dot);
		*dot = 0;
	}

	/* minor */
	if (!(dot = strrchr(srcbuf,'.')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);
	else if ((size_t)(mark - dot) > sizeof(minor))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_REV);
	else {
		strcpy(minor,dot);
		*dot = 0;
	}

	/* major */
	if (!(dot = strrchr(srcbuf,'.')))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);
	else if ((size_t)(mark - dot) > sizeof(major))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_REV);
	else {
		strcpy(major,dot);
		*dot = 0;
	}

	if (!dctx->x_cctx->x_asettings.fa_osdfussix[0])
		if (!(dot = strrchr(srcbuf,'.')))
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

	/* .libs/libfoo.x.y.z.lib.a */
	sprintf(dot,"%s%s%s%s",
		major,minor,rev,
		dctx->x_cctx->x_asettings.fa_impsuffix);

	/* copy: .libs/libfoo.x.y.z.lib.a --> dstdir */
	if (slbt_util_copy_file(ectx,srcbuf,dstdir))
		return SLBT_NESTED_ERROR(dctx);

	/* .libs/libfoo.x.lib.a */
	sprintf(dot,"%s%s",
		major,
		dctx->x_cctx->x_asettings.fa_impsuffix);

	/* copy: .libs/libfoo.x.lib.a --> dstdir */
	if (slbt_util_copy_file(ectx,srcbuf,dstdir))
		return SLBT_NESTED_ERROR(dctx);

	/* /dstdir/libfoo.lib.a */
	strcpy(implib,slash);
	strcpy(dot,dctx->x_cctx->x_asettings.fa_impsuffix);

	if (slbt_snprintf(hostlnk,sizeof(hostlnk),
			"%s/%s",dstdir,slash) <0)
		return SLBT_BUFFER_ERROR(dctx);

	if (slbt_create_symlink(
			dctx,ectx,
			implib,
			hostlnk,
			SLBT_SYMLINK_DEFAULT))
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}

static int slbt_exec_install_library_wrapper(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	struct argv_entry *		entry,
	char *				dstdir)
{
	int			fdcwd;
	int			fddst;
	size_t			buflen;
	const char *		base;
	char *			srcline;
	char *			dstline;
	char			clainame[PATH_MAX];
	char			instname[PATH_MAX];
	char			cfgbuf  [PATH_MAX];
	struct slbt_map_info *	mapinfo;

	/* base libfoo.la */
	if ((base = strrchr(entry->arg,'/')))
		base++;
	else
		base = entry->arg;

	/* /dstdir/libfoo.la */
	if (slbt_snprintf(instname,sizeof(instname),
			"%s/%s",dstdir,base) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* libfoo.la.slibtool.install */
	if (slbt_snprintf(clainame,sizeof(clainame),
			"%s.slibtool.install",
			entry->arg) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* fddst (libfoo.la.slibtool.install, build directory) */
	slbt_driver_set_ectx(
		dctx,0,
		clainame);

	if ((fddst = openat(fdcwd,clainame,O_RDWR|O_CREAT|O_TRUNC,0644)) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	/* mapinfo (libfoo.la, build directory) */
	slbt_driver_set_ectx(
		dctx,0,
		entry->arg);

	if (!(mapinfo = slbt_map_file(fdcwd,entry->arg,SLBT_MAP_INPUT))) {
		close(fddst);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* srcline */
	if (mapinfo->size < sizeof(cfgbuf)) {
		buflen  = sizeof(cfgbuf);
		srcline = cfgbuf;
	} else {
		buflen  = mapinfo->size;
		srcline = malloc(++buflen);
	}

	if (!srcline) {
		close(fddst);
		slbt_unmap_file(mapinfo);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* copy config, installed=no --> installed=yes */
	while (mapinfo->mark < mapinfo->cap) {
		if (slbt_mapped_readline(dctx,mapinfo,srcline,buflen) < 0) {
			close(fddst);
			slbt_unmap_file(mapinfo);
			return SLBT_NESTED_ERROR(dctx);
		}

		dstline = strcmp(srcline,"installed=no\n")
			? srcline
			: "installed=yes\n";

		if (slbt_dprintf(fddst,"%s",dstline) < 0) {
			close(fddst);
			slbt_unmap_file(mapinfo);
			return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if (srcline != cfgbuf)
		free(srcline);

	/* close, unmap */
	close(fddst);
	slbt_unmap_file(mapinfo);

	/* cp libfoo.la.slibtool.install /dstdir/libfoo.la */
	if (slbt_util_copy_file(ectx,clainame,instname))
		return SLBT_NESTED_ERROR(dctx);

	return 0;
}

static int slbt_exec_install_entry(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	struct argv_entry *		entry,
	struct argv_entry *		last,
	struct argv_entry *		dest,
	char *				dstdir,
	char **				src,
	char **				dst)
{
	int		fdcwd;
	const char *	base;
	char *		dot;
	char *		host;
	char *		mark;
	char *		slash;
	char *		suffix;
	char *		dsosuffix;
	char		sobuf   [64];
	char		target  [PATH_MAX];
	char		srcfile [PATH_MAX];
	char		dstfile [PATH_MAX];
	char		slnkname[PATH_MAX];
	char		dlnkname[PATH_MAX];
	char		hosttag [PATH_MAX];
	char		lasource[PATH_MAX - 8];
	bool		fexe = false;
	bool		fpe;
	bool		frelease;
	bool		fdualver;
	size_t		slen;
	size_t		dlen;
	struct stat	st;

	/* executable wrapper? */
	base = (slash = strrchr(entry->arg,'/'))
		? ++slash : entry->arg;

	strcpy(slnkname,entry->arg);
	mark = &slnkname[base - entry->arg];
	slen = sizeof(slnkname) - (mark - slnkname);

	if (slbt_snprintf(mark,slen,
			".libs/%s.exe.wrapper",
			base) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* fexe */
	fexe = !fstatat(fdcwd,slnkname,&st,0);

	/* argument suffix */
	dot  = strrchr(entry->arg,'.');

	/* .lai --> .la */
	if (!fexe && dot && !strcmp(dot,".lai"))
		dot[3] = 0;

	/* srcfile */
	if (strlen(entry->arg) + strlen(".libs/") >= (PATH_MAX-1))
		return SLBT_BUFFER_ERROR(dctx);

	strcpy(lasource,entry->arg);

	if ((slash = strrchr(lasource,'/'))) {
		*slash++ = 0;
		sprintf(srcfile,"%s/.libs/%s",lasource,slash);
	} else {
		sprintf(srcfile,".libs/%s",lasource);
	}

	/* executable? ordinary file? */
	if (fexe || !dot || strcmp(dot,".la")) {
		*src = fexe ? srcfile : (char *)entry->arg;
		*dst = dest ? 0 : (char *)last->arg;

		if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
			if (slbt_output_install(ectx))
				return SLBT_NESTED_ERROR(dctx);

		if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
			return SLBT_SPAWN_ERROR(dctx);

		} else if (ectx->x_exitcode) {
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_INSTALL_ERROR);
		}

		return 0;
	}

	/* -shrext, dsosuffix */
	strcpy(sobuf,dctx->x_cctx->x_settings.fa_dsosuffix);
	dsosuffix = sobuf;

	if (slbt_snprintf(slnkname,sizeof(slnkname),
			"%s.shrext",srcfile) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	if (!fstatat(fdcwd,slnkname,&st,0)) {
		slbt_driver_set_ectx(
			dctx,0,
			slnkname);

		if (slbt_readlinkat(fdcwd,slnkname,target,sizeof(target)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

		if (strncmp(lasource,target,(slen = strlen(lasource))))
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

		if (strncmp(&target[slen],".shrext",7))
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

		strcpy(sobuf,&target[slen+7]);
	}

	/* legabits? */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_LEGABITS)
		if (slbt_exec_install_library_wrapper(dctx,ectx,entry,dstdir))
			return SLBT_NESTED_ERROR(dctx);

	/* *dst: consider: cp libfoo.la /dest/dir/libfoo.la */
	if ((*dst = dest ? 0 : (char *)last->arg))
		if ((dot = strrchr(last->arg,'.')))
			if (!(strcmp(dot,".la")))
				*dst = dstdir;

	/* libfoo.a */
	dot = strrchr(srcfile,'.');
	strcpy(dot,dctx->x_cctx->x_settings.fa_arsuffix);

	/* libfoo.a installation */
	if (!slbt_symlink_is_a_placeholder(fdcwd,srcfile))
		if (slbt_util_copy_file(
				ectx,
				srcfile,
				dest ? (char *)dest->arg : *dst))
			return SLBT_NESTED_ERROR(dctx);

	/* dot/suffix */
	strcpy(slnkname,srcfile);
	dot = strrchr(slnkname,'.');

	/* .libs/libfoo.so.def.host */
	slen  = sizeof(slnkname);
	slen -= (dot - slnkname);

	/* static library only? */
	sprintf(dot,"%s",dsosuffix);

	if (slbt_symlink_is_a_placeholder(fdcwd,slnkname))
		return 0;

	/* detect -release, exclusively or alongside -version-info */
	frelease = false;
	fdualver = false;
	fpe      = false;

	/* libfoo.a --> libfoo.so.release */
	sprintf(dot,"%s.release",dsosuffix);
	frelease = !fstatat(fdcwd,slnkname,&st,0);

	/* libfoo.a --> libfoo.so.dualver */
	if (!frelease) {
		sprintf(dot,"%s.dualver",dsosuffix);
		fdualver = !fstatat(fdcwd,slnkname,&st,0);
	}

	/* libfoo.so.def.{flavor} */
	if (frelease || fdualver) {
		strcpy(dlnkname,slnkname);
		slash = strrchr(dlnkname,'/');

		dlen  = sizeof(dlnkname);
		dlen -= (++slash - dlnkname);
		dlen -= 9;

		slbt_driver_set_ectx(
			dctx,0,
			slnkname);

		if (slbt_readlinkat(fdcwd,slnkname,slash,dlen))
			return SLBT_SYSTEM_ERROR(dctx);

		if (fdualver) {
			/* remove .patch */
			if (!(mark = strrchr(dlnkname,'.')))
				return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

			*mark = 0;

			/* remove .minor */
			if (!(mark = strrchr(dlnkname,'.')))
				return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

			*mark = 0;

			/* remove .major */
			if (!(mark = strrchr(dlnkname,'.')))
				return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);
		} else {
			mark = slash += strlen(slash);
		}

		strcpy(mark,".def.host");

		slbt_driver_set_ectx(
			dctx,0,
			slnkname);

		if (slbt_readlinkat(fdcwd,dlnkname,hosttag,sizeof(hosttag)))
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		if (slbt_snprintf(dot,slen,"%s.def.host",dsosuffix) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		slbt_driver_set_ectx(
			dctx,0,
			slnkname);

		if (slbt_readlinkat(fdcwd,frelease ? dlnkname : slnkname,hosttag,sizeof(hosttag)))
			return SLBT_SYSTEM_ERROR(dctx);
	}

	/* host/flabor */
	if (!(host = strrchr(hosttag,'.'))) {
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);
	} else {
		host++;
	}

	/* symlink-based alternate host */
	if (slbt_host_set_althost(dctx,host,host))
		return SLBT_NESTED_ERROR(dctx);

	fpe = !strcmp(dctx->x_cctx->x_asettings.fa_imagefmt,"pe");

	/* libfoo.a --> libfoo.so */
	strcpy(dot,dsosuffix);

	/* basename */
	if ((base = strrchr(slnkname,'/')))
		base++;
	else
		base = slnkname;

	/* source (build) symlink target */
	if (slbt_readlinkat(fdcwd,slnkname,target,sizeof(target)) < 0) {
		slbt_driver_set_ectx(
			dctx,0,
			slnkname);

		/* -avoid-version? */
		if (fstatat(fdcwd,slnkname,&st,0))
			return SLBT_SYSTEM_ERROR(dctx);

		/* dstfile */
		if (slbt_snprintf(dstfile,sizeof(dstfile),
				"%s/%s",dstdir,base) < 0)
			return SLBT_BUFFER_ERROR(dctx);

		/* single spawn, no symlinks */
		*src = slnkname;
		*dst = dest ? 0 : dstfile;

		if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
			if (slbt_output_install(ectx))
				return SLBT_NESTED_ERROR(dctx);

		if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
			return SLBT_SPAWN_ERROR(dctx);

		} else if (ectx->x_exitcode) {
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_INSTALL_ERROR);
		}

		return 0;
	}

	/* srcfile: .libs/libfoo.so.x.y.z */
	slash = strrchr(srcfile,'/');
	strcpy(++slash,target);

	/* dstfile */
	if (!dest)
		if (slbt_snprintf(dstfile,sizeof(dstfile),
				"%s/%s",dstdir,target) < 0)
			return SLBT_BUFFER_ERROR(dctx);

	/* spawn */
	*src = srcfile;
	*dst = dest ? 0 : dstfile;

	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
		if (slbt_output_install(ectx))
			return SLBT_NESTED_ERROR(dctx);

	if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
		return SLBT_SPAWN_ERROR(dctx);

	} else if (ectx->x_exitcode) {
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_INSTALL_ERROR);
	}

	/* destination symlink: dstdir/libfoo.so */
	if (slbt_snprintf(dlnkname,sizeof(dlnkname),
			"%s/%s",dstdir,base) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* create symlink: libfoo.so --> libfoo.so.x.y.z */
	if (slbt_create_symlink(
			dctx,ectx,
			target,dlnkname,
			SLBT_SYMLINK_DEFAULT))
		return SLBT_NESTED_ERROR(dctx);

	if (frelease)
		return 0;

	/* libfoo.so.x --> libfoo.so.x.y.z */
	strcpy(slnkname,target);

	if ((suffix = strrchr(slnkname,'.')))
		*suffix++ = 0;
	else
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

	if ((dot = strrchr(slnkname,'.')))
		*dot++ = 0;
	else
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

	if ((*dot < '0') || (*dot > '9'))
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

	/* libfoo.x.y.z.so? */
	if ((suffix[0] < '0') || (suffix[0] > '9')) {
		if ((dot = strrchr(slnkname,'.')))
			dot++;
		else
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

		if ((*dot < '0') || (*dot > '9'))
			return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FLOW);

		for (; *suffix; )
			*dot++ = *suffix++;

		*dot++ = 0;
	}

	/* destination symlink: dstdir/libfoo.so.x */
	if (slbt_snprintf(dlnkname,sizeof(dlnkname),
			"%s/%s",dstdir,slnkname) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	if (fpe) {
		/* copy: .libs/libfoo.so.x.y.z --> libfoo.so.x */
		if (slbt_util_copy_file(
				ectx,
				srcfile,
				dlnkname))
			return SLBT_NESTED_ERROR(dctx);

		/* import libraries */
		if (slbt_exec_install_import_libraries(
				dctx,ectx,
				srcfile,
				dstdir))
			return SLBT_NESTED_ERROR(dctx);
	} else {
		/* create symlink: libfoo.so.x --> libfoo.so.x.y.z */
		if (slbt_create_symlink(
				dctx,ectx,
				target,dlnkname,
				SLBT_SYMLINK_DEFAULT))
			return SLBT_NESTED_ERROR(dctx);
	}

	return 0;
}

int slbt_exec_install(const struct slbt_driver_ctx * dctx)
{
	int				fdout;
	char **				argv;
	char **				iargv;
	char **				src;
	char **				dst;
	char *				slash;
	char *				optsh;
	char *				script;
	char *				shtool;
	struct slbt_exec_ctx *		ectx;
	struct argv_meta *		meta;
	struct argv_entry *		entry;
	struct argv_entry *		copy;
	struct argv_entry *		dest;
	struct argv_entry *		last;
	const struct argv_option *	optv[SLBT_OPTV_ELEMENTS];
	char				dstdir[PATH_MAX];

	/* dry run */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_DRY_RUN)
		return 0;

	/* context */
	if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* initial state, install mode skin */
	slbt_ectx_reset_arguments(ectx);
	slbt_disable_placeholders(ectx);
	iargv = ectx->x_cargv;
	fdout = slbt_driver_fdout(dctx);
	optsh = 0;
	script = 0;

	/* work around non-conforming uses of --mode=install */
	if (iargv[1] && (slash = strrchr(iargv[1],'/'))) {
		if (!strcmp(++slash,"install-sh")) {
			optsh  = *iargv++;
			script = *iargv;
		}
	} else {
		slash  = strrchr(iargv[0],'/');
		shtool = slash ? ++slash : iargv[0];
		shtool = strcmp(shtool,"shtool") ? 0 : shtool;

		if (shtool && iargv[1] && !strcmp(iargv[1],"install")) {
			iargv++;
		} else if (shtool) {
			return slbt_install_usage(
				fdout,
				dctx->x_program,
				0,optv,0,
				dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER);
		}
	}

	/* missing arguments? */
	slbt_optv_init(slbt_install_options,optv);

	if (!iargv[1] && (dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_USAGE))
		return slbt_install_usage(
			fdout,
			dctx->x_program,
			0,optv,0,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_ANNOTATE_NEVER);

	/* <install> argv meta */
	if (!(meta = slbt_argv_get(
			iargv,optv,
			dctx->x_cctx->x_drvflags & SLBT_DRIVER_VERBOSITY_ERRORS
				? ARGV_VERBOSITY_ERRORS
				: ARGV_VERBOSITY_NONE,
			fdout)))
		return slbt_exec_install_fail(
			ectx,meta,
			SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_INSTALL_FAIL));

	/* dest, alternate argument vector options */
	argv = ectx->x_altv;
	copy = meta->entries;
	dest = 0;
	last = 0;

	if (optsh)
		*argv++ = script;

	*argv++ = iargv[0];

	for (entry=meta->entries; entry->fopt || entry->arg; entry++) {
		if (entry->fopt) {
			switch (entry->tag) {
				case TAG_INSTALL_SYSROOT:
					break;

				case TAG_INSTALL_COPY:
					*argv++ = "-c";
					copy = entry;
					break;

				case TAG_INSTALL_FORCE:
					*argv++ = "-f";
					break;

				case TAG_INSTALL_MKDIR:
					*argv++ = "-d";
					copy = 0;
					break;

				case TAG_INSTALL_TARGET_MKDIR:
					*argv++ = "-D";
					copy = 0;
					break;

				case TAG_INSTALL_STRIP:
					*argv++ = "-s";
					break;

				case TAG_INSTALL_PRESERVE:
					*argv++ = "-p";
					break;

				case TAG_INSTALL_USER:
					*argv++ = "-o";
					break;

				case TAG_INSTALL_GROUP:
					*argv++ = "-g";
					break;

				case TAG_INSTALL_MODE:
					*argv++ = "-m";
					break;

				case TAG_INSTALL_DSTDIR:
					*argv++ = "-t";
					dest = entry;
					break;
			}

			if (entry->tag == TAG_INSTALL_SYSROOT) {
				(void)0;

			} else if (entry->fval) {
				*argv++ = (char *)entry->arg;
			}
		} else
			last = entry;
	}

	/* install */
	if (copy) {
		/* using alternate argument vector */
		if (optsh)
			ectx->x_altv[0] = optsh;

		ectx->x_argv    = ectx->x_altv;
		ectx->x_program = ectx->x_altv[0];

		/* marks */
		src = argv++;
		dst = argv++;

		/* dstdir */
		if (slbt_exec_install_init_dstdir(dctx,dest,last,dstdir))
			return slbt_exec_install_fail(
				ectx,meta,
				SLBT_NESTED_ERROR(dctx));

		/* install entries one at a time */
		for (entry=meta->entries; entry->fopt || entry->arg; entry++)
			if (!entry->fopt && (dest || (entry != last)))
				if (slbt_exec_install_entry(
						dctx,ectx,
						entry,last,
						dest,dstdir,
						src,dst))
					return slbt_exec_install_fail(
						ectx,meta,
						SLBT_NESTED_ERROR(dctx));
	} else {
		/* using original argument vector */
		ectx->x_argv    = ectx->x_cargv;
		ectx->x_program = ectx->x_cargv[0];

		/* spawn */
		if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT))
			if (slbt_output_install(ectx))
				return SLBT_NESTED_ERROR(dctx);

		if ((slbt_spawn(ectx,true) < 0) && (ectx->x_pid < 0)) {
			return slbt_exec_install_fail(
				ectx,meta,
				SLBT_SPAWN_ERROR(dctx));

		} else if (ectx->x_exitcode) {
			return slbt_exec_install_fail(
				ectx,meta,
				SLBT_CUSTOM_ERROR(
					dctx,
					SLBT_ERR_INSTALL_ERROR));
		}
	}

	slbt_argv_free(meta);
	slbt_ectx_free_exec_ctx(ectx);

	return 0;
}
