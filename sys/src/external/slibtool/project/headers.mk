API_HEADERS = \
	$(PROJECT_DIR)/include/$(PACKAGE)/slibtool.h \
	$(PROJECT_DIR)/include/$(PACKAGE)/slibtool_api.h \
	$(PROJECT_DIR)/include/$(PACKAGE)/slibtool_arbits.h \
	$(PROJECT_DIR)/include/$(PACKAGE)/slibtool_output.h \
	$(PROJECT_DIR)/include/$(PACKAGE)/slibtool_util.h \

INTERNAL_HEADERS = \
	$(PROJECT_DIR)/src/internal/argv/argv.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_ar_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_coff_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_dprintf_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_driver_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_errinfo_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_install_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_lconf_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_linkcmd_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_m4fake_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_mapfile_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_metafile_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_mkdir_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_mkvars_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_objlist_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_pecoff_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_readlink_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_realpath_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_snprintf_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_spawn_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_stoolie_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_symlink_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_tmpfile_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_txtline_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_uninstall_impl.h \
	$(PROJECT_DIR)/src/internal/$(PACKAGE)_visibility_impl.h \

ALL_HEADERS = $(API_HEADERS) $(INTERNAL_HEADERS)
