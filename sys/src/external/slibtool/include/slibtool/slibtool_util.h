#ifndef SLIBTOOL_UTIL_H
#define SLIBTOOL_UTIL_H

#include "slibtool_api.h"

struct slbt_fd_ctx;
struct slbt_exec_ctx;
struct slbt_driver_ctx;
struct slbt_symlist_ctx;
struct slbt_archive_ctx;
struct slbt_archive_meta;
struct slbt_error_info;

/* utility api */
slbt_api int  slbt_main(
	char ** argv,
	char ** envp,
	const struct slbt_fd_ctx *);


/* command execution api */
slbt_api int  slbt_exec_compile         (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_execute         (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_install         (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_link            (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_uninstall       (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_ar              (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_stoolie         (const struct slbt_driver_ctx *);
slbt_api int  slbt_exec_slibtoolize     (const struct slbt_driver_ctx *);


/* output api */
slbt_api int  slbt_output_info          (const struct slbt_driver_ctx *);
slbt_api int  slbt_output_config        (const struct slbt_driver_ctx *);
slbt_api int  slbt_output_machine       (const struct slbt_driver_ctx *);
slbt_api int  slbt_output_features      (const struct slbt_driver_ctx *);
slbt_api int  slbt_output_fdcwd         (const struct slbt_driver_ctx *);

slbt_api int  slbt_output_exec          (const struct slbt_exec_ctx *, const char *);
slbt_api int  slbt_output_compile       (const struct slbt_exec_ctx *);
slbt_api int  slbt_output_execute       (const struct slbt_exec_ctx *);
slbt_api int  slbt_output_install       (const struct slbt_exec_ctx *);
slbt_api int  slbt_output_link          (const struct slbt_exec_ctx *);
slbt_api int  slbt_output_uninstall     (const struct slbt_exec_ctx *);
slbt_api int  slbt_output_mapfile       (const struct slbt_symlist_ctx *);


/* error trace api */
slbt_api int  slbt_output_error_vector  (const struct slbt_driver_ctx *);
slbt_api int  slbt_output_error_record  (const struct slbt_error_info *);


/* archiver utility api */
slbt_api int  slbt_au_output_arname     (const struct slbt_archive_ctx *);
slbt_api int  slbt_au_output_members    (const struct slbt_archive_meta *);
slbt_api int  slbt_au_output_symbols    (const struct slbt_archive_meta *);
slbt_api int  slbt_au_output_mapfile    (const struct slbt_archive_meta *);

slbt_api int  slbt_au_output_dlsyms     (struct slbt_archive_ctx **, const char *);


#endif
