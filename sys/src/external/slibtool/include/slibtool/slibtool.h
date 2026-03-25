#ifndef SLIBTOOL_H
#define SLIBTOOL_H

#include <fcntl.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "slibtool_api.h"
#include "slibtool_arbits.h"
#include "slibtool_util.h"

#ifdef __cplusplus
extern "C" {
#endif

/* status codes */
#define SLBT_OK				0x00
#define SLBT_USAGE			0x01
#define SLBT_ERROR			0x02

/* driver flags */
#define SLBT_DRIVER_XFLAG(x)		((uint64_t)(x) << 32)

#define SLBT_DRIVER_VERBOSITY_NONE	0x0000
#define SLBT_DRIVER_VERBOSITY_ERRORS	0x0001
#define SLBT_DRIVER_VERBOSITY_STATUS	0x0002
#define SLBT_DRIVER_VERBOSITY_USAGE	0x0004
#define SLBT_DRIVER_CLONE_VECTOR	0x0008

#define SLBT_DRIVER_VERSION		0x0010
#define SLBT_DRIVER_DRY_RUN		0x0020
#define SLBT_DRIVER_INFO		0x0040
#define SLBT_DRIVER_DEBUG		0x0080
#define SLBT_DRIVER_FEATURES		0x0100
#define SLBT_DRIVER_DEPS		0x0200
#define SLBT_DRIVER_SILENT		0x0400
#define SLBT_DRIVER_VERBOSE		0x0800
#define SLBT_DRIVER_PRO_PIC		0x1000
#define SLBT_DRIVER_ANTI_PIC		0x2000
#define SLBT_DRIVER_SHARED		0x4000
#define SLBT_DRIVER_STATIC		0x8000

#define SLBT_DRIVER_HEURISTICS		0x010000
#define SLBT_DRIVER_STRICT		0x020000
#define SLBT_DRIVER_NO_UNDEFINED	0x040000
#define SLBT_DRIVER_MODULE		0x080000
#define SLBT_DRIVER_AVOID_VERSION	0x100000
#define SLBT_DRIVER_IMAGE_ELF		0x200000
#define SLBT_DRIVER_IMAGE_PE		0x400000
#define SLBT_DRIVER_IMAGE_MACHO		0x800000

#define SLBT_DRIVER_ALL_STATIC		0x01000000
#define SLBT_DRIVER_DISABLE_STATIC	0x02000000
#define SLBT_DRIVER_DISABLE_SHARED	0x04000000
#define SLBT_DRIVER_LEGABITS		0x08000000

#define SLBT_DRIVER_ANNOTATE_ALWAYS	0x10000000
#define SLBT_DRIVER_ANNOTATE_NEVER	0x20000000
#define SLBT_DRIVER_ANNOTATE_FULL	0x40000000

#define SLBT_DRIVER_IMPLIB_IDATA	SLBT_DRIVER_XFLAG(0x0001)
#define SLBT_DRIVER_IMPLIB_DSODEPS	SLBT_DRIVER_XFLAG(0x0002)
#define SLBT_DRIVER_EXPORT_DYNAMIC	SLBT_DRIVER_XFLAG(0x0010)
#define SLBT_DRIVER_STATIC_LIBTOOL_LIBS	SLBT_DRIVER_XFLAG(0x0100)

#define SLBT_DRIVER_OUTPUT_SHARED_EXT	SLBT_DRIVER_XFLAG(0x0400)
#define SLBT_DRIVER_OUTPUT_STATIC_EXT	SLBT_DRIVER_XFLAG(0x0800)

#define SLBT_DRIVER_OUTPUT_MACHINE	SLBT_DRIVER_XFLAG(0x1000)
#define SLBT_DRIVER_OUTPUT_CONFIG	SLBT_DRIVER_XFLAG(0x2000)
#define SLBT_DRIVER_OUTPUT_AUX_DIR	SLBT_DRIVER_XFLAG(0x4000)
#define SLBT_DRIVER_OUTPUT_M4_DIR	SLBT_DRIVER_XFLAG(0x8000)

#define SLBT_DRIVER_MODE_AR		SLBT_DRIVER_XFLAG(0x010000)
#define SLBT_DRIVER_MODE_AR_CHECK	SLBT_DRIVER_XFLAG(0x020000)
#define SLBT_DRIVER_MODE_AR_MERGE	SLBT_DRIVER_XFLAG(0x040000)

#define SLBT_DRIVER_MODE_STOOLIE	SLBT_DRIVER_XFLAG(0x080000)
#define SLBT_DRIVER_MODE_SLIBTOOLIZE    SLBT_DRIVER_XFLAG(0x080000)

#define SLBT_DRIVER_PREFER_SHARED       SLBT_DRIVER_XFLAG(0x100000)
#define SLBT_DRIVER_PREFER_STATIC       SLBT_DRIVER_XFLAG(0x200000)
#define SLBT_DRIVER_PREFER_SLTDL        SLBT_DRIVER_XFLAG(0x400000)

#define SLBT_DRIVER_STOOLIE_COPY        SLBT_DRIVER_XFLAG(0x01000000)
#define SLBT_DRIVER_STOOLIE_FORCE       SLBT_DRIVER_XFLAG(0x02000000)
#define SLBT_DRIVER_STOOLIE_INSTALL     SLBT_DRIVER_XFLAG(0x04000000)
#define SLBT_DRIVER_STOOLIE_LTDL        SLBT_DRIVER_XFLAG(0x08000000)

#define SLBT_DRIVER_DLOPEN_SELF         SLBT_DRIVER_XFLAG(0x10000000)
#define SLBT_DRIVER_DLOPEN_FORCE        SLBT_DRIVER_XFLAG(0x20000000)
#define SLBT_DRIVER_DLPREOPEN_SELF      SLBT_DRIVER_XFLAG(0x40000000)
#define SLBT_DRIVER_DLPREOPEN_FORCE     SLBT_DRIVER_XFLAG(0x80000000)

/* unit action flags */
#define SLBT_ACTION_MAP_READWRITE	0x0001

/* error flags */
#define SLBT_ERROR_TOP_LEVEL		0x0001
#define SLBT_ERROR_NESTED		0x0002
#define SLBT_ERROR_CHILD		0x0004
#define SLBT_ERROR_CUSTOM		0x0008

enum slbt_custom_error {
	SLBT_ERR_FLOW_ERROR,
	SLBT_ERR_FLEE_ERROR,
	SLBT_ERR_COMPILE_ERROR,
	SLBT_ERR_LINK_ERROR,
	SLBT_ERR_INSTALL_ERROR,
	SLBT_ERR_AR_ERROR,
	SLBT_ERR_COPY_ERROR,
	SLBT_ERR_MDSO_ERROR,
	SLBT_ERR_DLLTOOL_ERROR,
	SLBT_ERR_ARCHIVE_IMPORT,
	SLBT_ERR_HOST_INIT,
	SLBT_ERR_INSTALL_FAIL,
	SLBT_ERR_INSTALL_FLOW,
	SLBT_ERR_INSTALL_REV,
	SLBT_ERR_LDRPATH_INIT,
	SLBT_ERR_LINK_FLOW,
	SLBT_ERR_LINK_FREQ,
	SLBT_ERR_BAD_DATA,
	SLBT_ERR_UNINSTALL_FAIL,
	SLBT_ERR_LCONF_OPEN,
	SLBT_ERR_LCONF_MAP,
	SLBT_ERR_LCONF_PARSE,
	SLBT_ERR_MKVARS_OPEN,
	SLBT_ERR_MKVARS_MAP,
	SLBT_ERR_MKVARS_PARSE,
	SLBT_ERR_AR_FAIL,
	SLBT_ERR_AR_EMPTY_FILE,
	SLBT_ERR_AR_INVALID_SIGNATURE,
	SLBT_ERR_AR_INVALID_HEADER,
	SLBT_ERR_AR_TRUNCATED_DATA,
	SLBT_ERR_AR_DUPLICATE_LONG_NAMES,
	SLBT_ERR_AR_DUPLICATE_ARMAP_MEMBER,
	SLBT_ERR_AR_MISPLACED_ARMAP_MEMBER,
	SLBT_ERR_AR_NO_ACTION_SPECIFIED,
	SLBT_ERR_AR_NO_INPUT_SPECIFIED,
	SLBT_ERR_AR_DRIVER_MISMATCH,
	SLBT_ERR_AR_ARMAP_MISMATCH,
	SLBT_ERR_AR_INVALID_ARMAP_NUMBER_OF_SYMS,
	SLBT_ERR_AR_INVALID_ARMAP_SIZE_OF_REFS,
	SLBT_ERR_AR_INVALID_ARMAP_SIZE_OF_STRS,
	SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE,
	SLBT_ERR_AR_INVALID_ARMAP_MEMBER_OFFSET,
	SLBT_ERR_AR_INVALID_ARMAP_NAME_OFFSET,
	SLBT_ERR_AR_DLUNIT_NOT_SPECIFIED,
	SLBT_ERR_AR_OUTPUT_NOT_SPECIFIED,
	SLBT_ERR_AR_OUTPUT_NOT_APPLICABLE,
};

/* execution modes */
enum slbt_mode {
	SLBT_MODE_UNKNOWN,
	SLBT_MODE_CONFIG,
	SLBT_MODE_INFO,
	SLBT_MODE_CLEAN,
	SLBT_MODE_COMPILE,
	SLBT_MODE_EXECUTE,
	SLBT_MODE_FINISH,
	SLBT_MODE_INSTALL,
	SLBT_MODE_LINK,
	SLBT_MODE_UNINSTALL,
	SLBT_MODE_AR,
	SLBT_MODE_STOOLIE,
};

enum slbt_tag {
	SLBT_TAG_UNKNOWN,
	SLBT_TAG_CC,
	SLBT_TAG_CXX,
	SLBT_TAG_FC,
	SLBT_TAG_F77,
	SLBT_TAG_ASM,
	SLBT_TAG_NASM,
	SLBT_TAG_RC,
};

enum slbt_warning_level {
	SLBT_WARNING_LEVEL_UNKNOWN,
	SLBT_WARNING_LEVEL_ALL,
	SLBT_WARNING_LEVEL_ERROR,
	SLBT_WARNING_LEVEL_NONE,
};


/* library interfaces */
struct slbt_fd_ctx {
	int                             fdin;
	int                             fdout;
	int                             fderr;
	int                             fdlog;
	int                             fdcwd;
	int                             fddst;
};

struct slbt_error_info {
	const struct slbt_driver_ctx *  edctx;
	const struct slbt_unit_ctx *    euctx;
	const char *                    eunit;
	int                             esyscode;
	int                             elibcode;
	const char *                    efunction;
	int                             eline;
	unsigned                        eflags;
	int                             excidx;
};

struct slbt_input {
	void *                          map_addr;
	size_t                          map_size;
};

struct slbt_raw_archive {
	void *                          map_addr;
	size_t                          map_size;
};

struct slbt_version_info {
	int                             vi_major;
	int                             vi_minor;
	int                             vi_revision;
	const char *                    vi_verinfo;
	const char *                    vi_vernumber;
};

struct slbt_host_params {
	const char *                    ha_host;
	const char *                    ha_flavor;
	const char *                    ha_ar;
	const char *                    ha_as;
	const char *                    ha_nm;
	const char *                    ha_ranlib;
	const char *                    ha_windres;
	const char *                    ha_dlltool;
	const char *                    ha_mdso;
	const char *                    ha_ldrpath;
};

struct slbt_flavor_settings {
	const char *                    fa_imagefmt;
	const char *                    fa_arprefix;
	const char *                    fa_arsuffix;
	const char *                    fa_dsoprefix;
	const char *                    fa_dsosuffix;
	const char *                    fa_osdsuffix;
	const char *                    fa_osdfussix;
	const char *                    fa_exeprefix;
	const char *                    fa_exesuffix;
	const char *                    fa_impprefix;
	const char *                    fa_impsuffix;
	const char *                    fa_mapsuffix;
	const char *                    fa_ldpathenv;
	char *                          fa_picswitch;
};

struct slbt_archive_meta {
	struct slbt_raw_archive         r_archive;
	struct ar_raw_signature *       r_signature;

	struct ar_meta_signature *      m_signature;

	struct ar_meta_member_info **   a_memberv;
	struct ar_meta_member_info *    a_arref_longnames;
	struct ar_meta_armap_info       a_armap_primary;
	struct ar_meta_armap_info       a_armap_pecoff;
};

struct slbt_archive_ctx {
	const char * const *            x_path;
	const struct slbt_raw_archive * x_map;
	const struct slbt_archive_meta *x_meta;
};

struct slbt_exec_ctx {
	char *                          x_program;
	char *                          x_compiler;

	char **                         x_cargv;
	char **                         x_xargv;
	char **                         x_argv;
	char **                         x_envp;
	char **                         x_altv;

	char **                         x_dpic;
	char **                         x_fpic;

	char **                         x_cass;
	char **                         x_noundef;
	char **                         x_soname;
	char **                         x_lsoname;

	char **                         x_symdefs;
	char **                         x_symfile;

	char **                         x_explarg;
	char **                         x_expsyms;

	char **                         x_lout[2];
	char **                         x_mout[2];
	char **                         x_rpath[2];

	char **                         x_sentinel;
	char *                          x_csrc;

	int                             x_ldirdepth;
	char *                          x_ldirname;
	char *                          x_lbasename;

	char *                          x_lobjname;
	char *                          x_aobjname;
	char *                          x_ltobjname;

	char *                          x_dlunit;
	char *                          x_dlopensrc;
	char *                          x_dlopenobj;
	char *                          x_dlpreopen;

	char *                          x_arfilename;
	char *                          x_lafilename;
	char *                          x_laifilename;

	char *                          x_dsobasename;
	char *                          x_dsofilename;

	char *                          x_relfilename;
	char *                          x_dsorellnkname;
	char *                          x_deffilename;
	char *                          x_mapfilename;
	char *                          x_rpathfilename;

	char *                          x_dimpfilename;
	char *                          x_pimpfilename;
	char *                          x_vimpfilename;

	char *                          x_exefilename;
	char *                          x_sonameprefix;

	pid_t                           x_pid;
	int                             x_exitcode;
};

struct slbt_common_ctx {
	uint64_t                        x_drvflags;
	uint64_t                        x_actflags;
	uint64_t                        x_fmtflags;
	struct slbt_host_params         x_host;
	struct slbt_host_params         x_cfgmeta;
	struct slbt_flavor_settings     x_settings;
	struct slbt_host_params         x_ahost;
	struct slbt_host_params         x_acfgmeta;
	struct slbt_flavor_settings     x_asettings;
	struct slbt_version_info        x_verinfo;
	enum slbt_mode                  x_mode;
	enum slbt_tag                   x_tag;
	enum slbt_warning_level         x_warnings;
	char **                         x_cargv;
	char **                         x_targv;
	char *                          x_libname;
	const char *                    x_dlunit;
	const char *                    x_ccwrap;
	const char *                    x_target;
	const char *                    x_output;
	const char *                    x_shrext;
	const char *                    x_rpath;
	const char *                    x_sysroot;
	const char *                    x_release;
	const char *                    x_expsyms;
	const char *                    x_regex;
	const char *                    x_user;
};

struct slbt_driver_ctx {
	const char *                    x_program;
	const char *                    x_module;
	const struct slbt_common_ctx *  x_cctx;
	const struct slbt_error_info ** x_errv;
};

struct slbt_symlist_ctx {
	const char * const *            x_path;
	const char **                   x_symstrv;
};

struct slbt_txtfile_ctx {
	const char * const *            x_path;
	const char **                   x_txtlinev;
};

struct slbt_stoolie_ctx {
	const char * const *            x_path;
	const struct slbt_txtfile_ctx * x_acinc;
	const struct slbt_txtfile_ctx * x_cfgac;
	const struct slbt_txtfile_ctx * x_makam;
	const char * const *            x_auxarg;
	const char * const *            x_m4arg;
	const char * const *            x_ltdldir;
};

struct slbt_unit_ctx {
	const char * const *            x_path;
};

struct slbt_source_version {
	int                             v_major;
	int                             v_minor;
	int                             v_revision;
	const char *                    v_commit;
};


/* driver api */
slbt_api int  slbt_lib_get_driver_ctx(
		char ** argv,
		char ** envp,
		uint64_t flags,
		const struct slbt_fd_ctx *,
		struct slbt_driver_ctx **);


slbt_api void slbt_lib_free_driver_ctx(
		struct slbt_driver_ctx *);


slbt_api int  slbt_lib_get_driver_fdctx(
		const struct slbt_driver_ctx *,
		struct slbt_fd_ctx *);

slbt_api int  slbt_lib_set_driver_fdctx(
		struct slbt_driver_ctx *,
		const struct slbt_fd_ctx *);


slbt_api int  slbt_lib_get_symlist_ctx(
		const struct slbt_driver_ctx *,
		const char *,
		struct slbt_symlist_ctx **);


slbt_api void slbt_lib_free_symlist_ctx(
		struct slbt_symlist_ctx *);


slbt_api int  slbt_lib_get_txtfile_ctx(
		const struct slbt_driver_ctx *,
		const char *,
		struct slbt_txtfile_ctx **);


slbt_api void slbt_lib_free_txtfile_ctx(
		struct slbt_txtfile_ctx *);


/* command execution context api */
slbt_api int  slbt_ectx_get_exec_ctx(
		const struct slbt_driver_ctx *,
		struct slbt_exec_ctx **);


slbt_api void slbt_ectx_free_exec_ctx(
		struct slbt_exec_ctx *);


slbt_api void slbt_ectx_reset_argvector(
		struct slbt_exec_ctx *);


slbt_api void slbt_ectx_reset_arguments(
		struct slbt_exec_ctx *);


/* host and flavor interfaces */
slbt_api int  slbt_host_set_althost(
		const struct slbt_driver_ctx *,
		const char * host,
		const char * flavor);

slbt_api void slbt_host_reset_althost(
		const struct slbt_driver_ctx *);


slbt_api int slbt_host_objfmt_is_coff(
		const struct slbt_driver_ctx *);


slbt_api int slbt_host_objfmt_is_macho(
		const struct slbt_driver_ctx *);


slbt_api int slbt_host_group_is_winnt(
		const struct slbt_driver_ctx *);


slbt_api int slbt_host_group_is_darwin(
		const struct slbt_driver_ctx *);


slbt_api int  slbt_host_flavor_settings(
		const char *,
		const struct slbt_flavor_settings **);


/* utility helper interfaces */
slbt_api int  slbt_util_import_archive(
		const struct slbt_exec_ctx *,
		char * dstarchive,
		char * srcarchive);


slbt_api int  slbt_util_copy_file(
		struct slbt_exec_ctx *,
		const char * from,
		const char * to);


slbt_api int  slbt_util_create_mapfile(
		const struct slbt_symlist_ctx *,
		const char *,
		mode_t);


slbt_api int  slbt_util_create_symfile(
		const struct slbt_symlist_ctx *,
		const char *,
		mode_t);


slbt_api int  slbt_util_dump_machine(
		const char * compiler,
		char * machine,
		size_t bufsize);


slbt_api int  slbt_util_real_path(
		int fdat,
		const char * path,
		int options,
		char * buffer,
		size_t buflen);


/* archiver api */
slbt_api int  slbt_ar_get_archive_ctx(
		const struct slbt_driver_ctx *,
		const char * path,
		struct slbt_archive_ctx **);


slbt_api void slbt_ar_free_archive_ctx(
		struct slbt_archive_ctx *);


slbt_api int  slbt_ar_get_varchive_ctx(
		const struct slbt_driver_ctx *,
		struct slbt_archive_ctx **);


slbt_api int  slbt_ar_get_archive_meta(
		const struct slbt_driver_ctx *,
		const struct slbt_raw_archive *,
		struct slbt_archive_meta **);


slbt_api void slbt_ar_free_archive_meta(
		struct slbt_archive_meta *);


slbt_api int  slbt_ar_merge_archives(
		struct slbt_archive_ctx * const [],
		struct slbt_archive_ctx **);

slbt_api int  slbt_ar_store_archive(
		struct slbt_archive_ctx *,
		const char *,
		mode_t);


slbt_api int  slbt_ar_create_mapfile(
		const struct slbt_archive_meta *,
		const char *, mode_t);


slbt_api int  slbt_ar_create_symfile(
		const struct slbt_archive_meta *,
		const char *, mode_t);


slbt_api int slbt_ar_create_dlsyms(
		struct slbt_archive_ctx **,
		const char *,
		const char *,
		mode_t);


/* slibtoolize api */
slbt_api int  slbt_st_get_stoolie_ctx(
		const struct slbt_driver_ctx *,
		const char * path,
		struct slbt_stoolie_ctx **);

slbt_api void slbt_st_free_stoolie_ctx(
		struct slbt_stoolie_ctx *);


/* raw input api */
slbt_api int  slbt_fs_map_input(
		const struct slbt_driver_ctx *,
		int,
		const char *,
		int,
		struct slbt_input *);


slbt_api int  slbt_fs_unmap_input(
		struct slbt_input *);


/* package info */
slbt_api const struct slbt_source_version * slbt_api_source_version(void);


#ifdef __cplusplus
}
#endif

#endif
