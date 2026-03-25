API_SRCS = \
	src/arbits/slbt_archive_ctx.c \
	src/arbits/slbt_archive_dlsyms.c \
	src/arbits/slbt_archive_mapfile.c \
	src/arbits/slbt_archive_mapstrv.c \
	src/arbits/slbt_archive_merge.c \
	src/arbits/slbt_archive_meta.c \
	src/arbits/slbt_archive_store.c \
	src/arbits/slbt_archive_symfile.c \
	src/arbits/slbt_archive_syminfo.c \
	src/arbits/slbt_armap_bsd_32.c \
	src/arbits/slbt_armap_bsd_64.c \
	src/arbits/slbt_armap_sysv_32.c \
	src/arbits/slbt_armap_sysv_64.c \
	src/arbits/output/slbt_au_output_arname.c \
	src/arbits/output/slbt_au_output_dlsyms.c \
	src/arbits/output/slbt_au_output_mapfile.c \
	src/arbits/output/slbt_au_output_members.c \
	src/arbits/output/slbt_au_output_symbols.c \
	src/driver/slbt_amain.c \
	src/driver/slbt_driver_ctx.c \
	src/driver/slbt_link_params.c \
	src/driver/slbt_split_argv.c \
	src/driver/slbt_symlist_ctx.c \
	src/driver/slbt_txtfile_ctx.c \
	src/driver/slbt_version_info.c \
	src/host/slbt_host_flavor.c \
	src/host/slbt_host_params.c \
	src/util/slbt_archive_import.c \
	src/util/slbt_create_mapfile.c \
	src/util/slbt_create_symfile.c \
	src/util/slbt_copy_file.c \
	src/util/slbt_dump_machine.c \
	src/util/slbt_map_input.c \
	src/util/slbt_realpath.c \
	src/logic/slbt_exec_ar.c \
	src/logic/slbt_exec_compile.c \
	src/logic/slbt_exec_ctx.c \
	src/logic/slbt_exec_execute.c \
	src/logic/slbt_exec_install.c \
	src/logic/slbt_exec_link.c \
	src/logic/slbt_exec_stoolie.c \
	src/logic/slbt_exec_uninstall.c \
	src/logic/linkcmd/slbt_linkcmd_archive.c \
	src/logic/linkcmd/slbt_linkcmd_argv.c \
	src/logic/linkcmd/slbt_linkcmd_deps.c \
	src/logic/linkcmd/slbt_linkcmd_dsolib.c \
	src/logic/linkcmd/slbt_linkcmd_executable.c \
	src/logic/linkcmd/slbt_linkcmd_host.c \
	src/logic/linkcmd/slbt_linkcmd_implib.c \
	src/output/slbt_output_config.c \
	src/output/slbt_output_error.c \
	src/output/slbt_output_exec.c \
	src/output/slbt_output_fdcwd.c \
	src/output/slbt_output_features.c \
	src/output/slbt_output_info.c \
	src/output/slbt_output_machine.c \
	src/output/slbt_output_mapfile.c \
	src/skin/slbt_skin_ar.c \
	src/skin/slbt_skin_default.c \
	src/skin/slbt_skin_install.c \
	src/skin/slbt_skin_stoolie.c \
	src/skin/slbt_skin_uninstall.c \
	src/stoolie/slbt_stoolie_ctx.c \

FALLBACK_SRCS = \
	src/fallback/slbt_archive_import_mri.c \

INTERNAL_SRCS = \
	src/internal/$(PACKAGE)_coff_impl.c \
	src/internal/$(PACKAGE)_dprintf_impl.c \
	src/internal/$(PACKAGE)_errinfo_impl.c \
	src/internal/$(PACKAGE)_lconf_impl.c \
	src/internal/$(PACKAGE)_libmeta_impl.c \
	src/internal/$(PACKAGE)_m4fake_impl.c \
	src/internal/$(PACKAGE)_mapfile_impl.c \
	src/internal/$(PACKAGE)_mkvars_impl.c \
	src/internal/$(PACKAGE)_objlist_impl.c \
	src/internal/$(PACKAGE)_objmeta_impl.c \
	src/internal/$(PACKAGE)_pecoff_impl.c \
	src/internal/$(PACKAGE)_realpath_impl.c \
	src/internal/$(PACKAGE)_snprintf_impl.c \
	src/internal/$(PACKAGE)_symlink_impl.c \
	src/internal/$(PACKAGE)_tmpfile_impl.c \
	src/internal/$(PACKAGE)_txtline_impl.c \

APP_SRCS = \
	src/slibtool.c

COMMON_SRCS = $(API_SRCS) $(INTERNAL_SRCS)
