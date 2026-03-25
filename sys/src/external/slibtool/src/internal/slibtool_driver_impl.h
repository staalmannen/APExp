/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#ifndef SLIBTOOL_DRIVER_IMPL_H
#define SLIBTOOL_DRIVER_IMPL_H

#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <slibtool/slibtool.h>
#include "slibtool_dprintf_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"

#define SLBT_OPTV_ELEMENTS 128

#define SLBT_DRIVER_OUTPUT_MASK (SLBT_DRIVER_OUTPUT_M4_DIR    \
				| SLBT_DRIVER_OUTPUT_AUX_DIR   \
				| SLBT_DRIVER_OUTPUT_SHARED_EXT \
				| SLBT_DRIVER_OUTPUT_STATIC_EXT)

extern const struct argv_option slbt_default_options[];

enum app_tags {
	TAG_HELP,
	TAG_HELP_ALL,
	TAG_VERSION,
	TAG_INFO,
	TAG_CONFIG,
	TAG_MKVARS,
	TAG_DUMPMACHINE,
	TAG_PRINT_AUX_DIR,
	TAG_PRINT_M4_DIR,
	TAG_PRINT_SHARED_EXT,
	TAG_PRINT_STATIC_EXT,
	TAG_DEBUG,
	TAG_DRY_RUN,
	TAG_FEATURES,
	TAG_LEGABITS,
	TAG_MODE,
	TAG_FINISH,
	TAG_WARNINGS,
	TAG_ANNOTATE,
	TAG_DEPS,
	TAG_SILENT,
	TAG_TAG,
	TAG_CCWRAP,
	TAG_VERBOSE,
	TAG_TARGET,
	TAG_HOST,
	TAG_FLAVOR,
	TAG_AR,
	TAG_AS,
	TAG_NM,
	TAG_RANLIB,
	TAG_WINDRES,
	TAG_DLLTOOL,
	TAG_MDSO,
	TAG_IMPLIB,
	TAG_OUTPUT,
	TAG_BINDIR,
	TAG_LDRPATH,
	TAG_SHREXT,
	TAG_RPATH,
	TAG_SYSROOT,
	TAG_RELEASE,
	TAG_OBJECTLIST,
	TAG_DLOPEN,
	TAG_DLPREOPEN,
	TAG_EXPORT_DYNAMIC,
	TAG_EXPSYMS_FILE,
	TAG_EXPSYMS_REGEX,
	TAG_VERSION_INFO,
	TAG_VERSION_NUMBER,
	TAG_NO_SUPPRESS,
	TAG_NO_INSTALL,
	TAG_PREFER_PIC,
	TAG_PREFER_NON_PIC,
	TAG_HEURISTICS,
	TAG_SHARED,
	TAG_STATIC,
	TAG_STATIC_LIBTOOL_LIBS,
	TAG_ALL_STATIC,
	TAG_DISABLE_STATIC,
	TAG_DISABLE_SHARED,
	TAG_NO_UNDEFINED,
	TAG_PREFER_SLTDL,
	TAG_MODULE,
	TAG_AVOID_VERSION,
	TAG_COMPILER_FLAG,
	TAG_VERBATIM_FLAG,
	TAG_THREAD_SAFE,
	TAG_WEAK,
	/* ar mode */
	TAG_AR_HELP,
	TAG_AR_VERSION,
	TAG_AR_CHECK,
	TAG_AR_PRINT,
	TAG_AR_MAPFILE,
	TAG_AR_DLUNIT,
	TAG_AR_DLSYMS,
	TAG_AR_NOSORT,
	TAG_AR_REGEX,
	TAG_AR_PRETTY,
	TAG_AR_POSIX,
	TAG_AR_YAML,
	TAG_AR_MERGE,
	TAG_AR_OUTPUT,
	TAG_AR_VERBOSE,
	/* slibtoolize (stoolie) mode */
	TAG_STLE_VERSION,
	TAG_STLE_HELP,
	TAG_STLE_COPY,
	TAG_STLE_FORCE,
	TAG_STLE_INSTALL,
	TAG_STLE_DEBUG,
	TAG_STLE_DRY_RUN,
	TAG_STLE_SILENT,
	TAG_STLE_VERBOSE,
	TAG_STLE_WARNINGS,
	TAG_STLE_NO_WARNINGS,
	TAG_STLE_LTDL,
	TAG_STLE_SYSTEM_LTDL,
};

struct slbt_split_vector {
	char *		dargs;
	char **		dargv;
	char **		targv;
	char **		cargv;
};

struct slbt_host_strs {
	char *		machine;
	char *		host;
	char *		flavor;
	char *		ar;
	char *		as;
	char *		nm;
	char *		ranlib;
	char *		windres;
	char *		dlltool;
	char *		mdso;
	char **		ar_argv;
	char **		as_argv;
	char **		nm_argv;
	char **		ranlib_argv;
	char **		windres_argv;
	char **		dlltool_argv;
	char **		mdso_argv;
};

struct slbt_obj_list {
	const char *	name;
	void *		addr;
	size_t		size;
	int		objc;
	char **		objv;
};

struct slbt_driver_ctx_impl {
	struct argv_meta *		meta;
	struct slbt_common_ctx          cctx;
	struct slbt_driver_ctx          ctx;
	struct slbt_host_strs           host;
	struct slbt_host_strs           ahost;
	struct slbt_fd_ctx              fdctx;
	struct slbt_map_info            lconf;
	struct slbt_txtfile_ctx *       lconfctx;
	struct slbt_txtfile_ctx *       mkvarsctx;
	struct slbt_obj_list *          objlistv;

	struct argv_entry **            dlopenv;
	size_t                          ndlopen;

	const struct slbt_archive_ctx * arctx;
	const char *                    arpath;

	const char *                    ltdlarg;
	char *                          libname;
	char *                          dargs;
	char **                         dargv;
	char **                         targv;
	char **                         cargv;
	char **                         envp;

	const struct slbt_unit_ctx *    euctx;
	const char *                    eunit;

	const struct slbt_error_info**  errinfp;
	const struct slbt_error_info**  erricap;
	const struct slbt_error_info *  erriptr[64];
	struct slbt_error_info          erribuf[64];
	char *                          erristr[64];
};

struct slbt_driver_ctx_alloc {
	struct slbt_driver_ctx_impl	ctx;
	uint64_t			guard;
};

struct slbt_exec_ctx_impl {
	const struct slbt_driver_ctx *	dctx;
	struct slbt_symlist_ctx *       sctx;
	struct slbt_exec_ctx            ctx;
	struct slbt_archive_ctx **      dlactxv;
	struct slbt_archive_ctx *       dlpreopen;
	char **                         dlargv;
	int                             argc;
	char *                          args;
	char *                          shadow;
	char *                          dsoprefix;
	char *                          lsltdl;
	size_t                          size;
	size_t                          exts;
	int                             fdwrapper;
	char                            sbuf[PATH_MAX];
	char **                         lout[2];
	char **                         mout[2];
	char **                         vbuffer;
};

struct slbt_archive_ctx_impl {
	const struct slbt_driver_ctx *	dctx;
	const char *			path;
	char *                          pathbuf;
	struct slbt_raw_archive		map;
	struct slbt_archive_meta *	meta;
	struct slbt_archive_ctx		actx;
};

struct slbt_symlist_ctx_impl {
	const struct slbt_driver_ctx *	dctx;
	const char *                    path;
	char *                          pathbuf;
	char *                          symstrs;
	const char **                   symstrv;
	struct slbt_symlist_ctx         sctx;
};


struct slbt_txtfile_ctx_impl {
	const struct slbt_driver_ctx *	dctx;
	const char *                    path;
	char *                          pathbuf;
	char *                          txtlines;
	const char **                   txtlinev;
	struct slbt_txtfile_ctx         tctx;
};

struct slbt_stoolie_ctx_impl {
	const struct slbt_driver_ctx *	dctx;
	const char *			path;
	char *                          pathbuf;
	int                             fdtgt;
	int                             fdaux;
	int                             fdm4;
	int                             fdltdl;
	const char *                    auxarg;
	char *                          auxbuf;
	const char *                    m4arg;
	char *                          m4buf;
	char **                         m4argv;
	const char *                    ltdldir;
	char *                          ltdlbuf;
	struct slbt_txtfile_ctx *       acinc;
	struct slbt_txtfile_ctx *       cfgac;
	struct slbt_txtfile_ctx *       makam;
	struct slbt_stoolie_ctx		zctx;
};

const char * slbt_program_name(const char *);


int slbt_optv_init(
	const struct argv_option[],
	const struct argv_option **);


uint64_t slbt_argv_flags(uint64_t flags);


void slbt_argv_scan(
	char **				argv,
	const struct argv_option **	optv,
	struct argv_ctx *		ctx,
	struct argv_meta *		meta);


struct argv_meta * slbt_argv_get(
	char **,
	const struct argv_option **,
	int flags,
	int fd);

void slbt_argv_free(struct argv_meta *);


void slbt_argv_usage(
	int		fd,
	const char *	header,
	const struct	argv_option **,
	const char *	mode);


void slbt_argv_usage_plain(
	int		fd,
	const char *	header,
	const struct	argv_option **,
	const char *	mode);


int slbt_driver_usage(
	int				fdout,
	const char *			program,
	const char *			arg,
	const struct argv_option **	optv,
	struct argv_meta *		meta,
	struct slbt_split_vector *	sargv,
	struct slbt_obj_list *		objlistv,
	int				noclr);


int slbt_split_argv(
	char **				argv,
	uint64_t			flags,
	struct slbt_split_vector *	sargv,
	struct slbt_obj_list **		aobjlistv,
	int				fderr,
	int				fdcwd);


int slbt_init_version_info(
	struct slbt_driver_ctx_impl *	ictx,
	struct slbt_version_info *	verinfo);


int slbt_init_host_params(
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
	const char *                    mkvars);


void slbt_free_host_params(struct slbt_host_strs * host);


int slbt_init_link_params(struct slbt_driver_ctx_impl * ctx);


void slbt_init_flavor_settings(
	struct slbt_common_ctx *	cctx,
	const struct slbt_host_params * ahost,
	struct slbt_flavor_settings *	psettings);


int slbt_init_ldrpath(
	struct slbt_common_ctx *  cctx,
	struct slbt_host_params * host);


void slbt_reset_placeholders   (struct slbt_exec_ctx *);

void slbt_disable_placeholders (struct slbt_exec_ctx *);

int slbt_impl_get_txtfile_ctx(
	const struct slbt_driver_ctx *  dctx,
	const char *                    path,
	int                             fdsrc,
	struct slbt_txtfile_ctx **      pctx);


static inline struct slbt_archive_ctx_impl * slbt_get_archive_ictx(const struct slbt_archive_ctx * actx)
{
	uintptr_t addr;

	if (actx) {
		addr = (uintptr_t)actx - offsetof(struct slbt_archive_ctx_impl,actx);
		return (struct slbt_archive_ctx_impl *)addr;
	}

	return 0;
}

static inline struct slbt_driver_ctx_impl * slbt_get_driver_ictx(const struct slbt_driver_ctx * dctx)
{
	uintptr_t addr;

	if (dctx) {
		addr = (uintptr_t)dctx - offsetof(struct slbt_driver_ctx_impl,ctx);
		return (struct slbt_driver_ctx_impl *)addr;
	}

	return 0;
}

static inline struct slbt_symlist_ctx_impl * slbt_get_symlist_ictx(const struct slbt_symlist_ctx * sctx)
{
	uintptr_t addr;

	if (sctx) {
		addr = (uintptr_t)sctx - offsetof(struct slbt_symlist_ctx_impl,sctx);
		return (struct slbt_symlist_ctx_impl *)addr;
	}

	return 0;
}

static inline struct slbt_stoolie_ctx_impl * slbt_get_stoolie_ictx(const struct slbt_stoolie_ctx * stctx)
{
	uintptr_t addr;

	if (stctx) {
		addr = (uintptr_t)stctx - offsetof(struct slbt_stoolie_ctx_impl,zctx);
		return (struct slbt_stoolie_ctx_impl *)addr;
	}

	return 0;
}

static inline void slbt_driver_set_arctx(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_ctx * arctx,
	const char *                    arpath)
{
	struct slbt_driver_ctx_impl * ictx;


	ictx         = slbt_get_driver_ictx(dctx);
	ictx->arctx  = arctx;
	ictx->arpath = arpath;
}

static inline void slbt_driver_set_ectx(
	const struct slbt_driver_ctx * dctx,
	const struct slbt_unit_ctx *   uctx,
	const char *                   unit)
{
	struct slbt_driver_ctx_impl *  ictx;

	ictx        = slbt_get_driver_ictx(dctx);
	ictx->euctx = uctx;
	ictx->eunit = unit;
}

static inline char ** slbt_driver_envp(const struct slbt_driver_ctx * dctx)
{
	struct slbt_driver_ctx_impl * ictx;
	ictx = slbt_get_driver_ictx(dctx);
	return ictx->envp;
}

static inline int slbt_driver_fdin(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fdin;
}

static inline int slbt_driver_fdout(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fdout;
}

static inline int slbt_driver_fderr(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fderr;
}

static inline int slbt_driver_fdlog(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fdlog;
}

static inline int slbt_driver_fdcwd(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fdcwd;
}

static inline int slbt_driver_fddst(const struct slbt_driver_ctx * dctx)
{
	struct slbt_fd_ctx fdctx;
	slbt_lib_get_driver_fdctx(dctx,&fdctx);
	return fdctx.fddst;
}

static inline struct slbt_exec_ctx_impl * slbt_get_exec_ictx(const struct slbt_exec_ctx * ectx)
{
	uintptr_t addr;

	addr = (uintptr_t)ectx - offsetof(struct slbt_exec_ctx_impl,ctx);
	return (struct slbt_exec_ctx_impl *)addr;
}

static inline int slbt_exec_get_fdwrapper(const struct slbt_exec_ctx * ectx)
{
	struct slbt_exec_ctx_impl * ictx;
	ictx = slbt_get_exec_ictx(ectx);
	return ictx->fdwrapper;
}

static inline void slbt_exec_set_fdwrapper(const struct slbt_exec_ctx * ectx, int fd)
{
	struct slbt_exec_ctx_impl * ictx;
	ictx = slbt_get_exec_ictx(ectx);
	ictx->fdwrapper = fd;
}

static inline void slbt_exec_close_fdwrapper(const struct slbt_exec_ctx * ectx)
{
	struct slbt_exec_ctx_impl * ictx;
	ictx = slbt_get_exec_ictx(ectx);
	close(ictx->fdwrapper);
	ictx->fdwrapper = (-1);
}

#endif
