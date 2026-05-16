#ifndef PROBE_H
#define PROBE_H

#include "gen_internal.h"

enum ProbeKind {
	PROBE_HEADER = 0,
	PROBE_FUNC = 1,
	PROBE_LIB = 2,
	PROBE_DECL = 3
};

int probe_pkgconf(struct GenCtx *g, const char *list, int add_flags);
int probe_header(struct GenCtx *g, const char *hdr);
int probe_func(struct GenCtx *g, const char *fn);
int probe_lib(struct GenCtx *g, const char *lib);
int probe_decl(struct GenCtx *g, const char *sym);
size_t probe_count_cmake_pending(struct GenCtx *g, const char *tmpl);
int probe_cmake_defs(struct GenCtx *g, const char *tmpl);
int probe_list(struct GenCtx *g, const char *key, int (*fn)(struct GenCtx *, const char *));
int probe_list_parallel(struct GenCtx *g, const char *key, enum ProbeKind kind);
int probe_replace_funcs(struct GenCtx *g, const char *key);
int probe_replace_funcs_parallel(struct GenCtx *g, const char *key);
int probe_list_decl(struct GenCtx *g, const char *key);
void probe_std_headers(struct GenCtx *g);
void probe_std_funcs(struct GenCtx *g);
int probe_safe_extensions(struct GenCtx *g);
int probe_iconv_version(struct GenCtx *g);
void probe_log_free(struct GenCtx *g);
void probe_log_flush(struct GenCtx *g);
void probe_count_init(struct GenCtx *g, const char *root);
void probe_static_init(struct GenCtx *g);

#endif
