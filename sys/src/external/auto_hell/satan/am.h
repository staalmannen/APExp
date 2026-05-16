#ifndef AM_H
#define AM_H

#include "conf.h"
#include "map.h"
#include "vec.h"

struct Var {
	int type;
	char *val;
};

enum {
	VAR_RECURSIVE = 0,
	VAR_SIMPLE = 1
};

struct Cond {
	int parent_active;
	int val;
	int in_else;
	int this_active;
	int unknown;
};

struct AmCtx {
	struct Map vars;
	struct Map conds;
	struct Vec cstack;
	struct Vec unknowns;
	struct Vec unknown_at;
	struct Vec unknown_vars;
	char *root;
	int active;
	char *path;
	int err;
	struct Conf *conf;
};

enum {
	AM_ASSIGN = 0,
	AM_APPEND = 1,
	AM_IMMEDIATE = 2,
	AM_DEFAULT = 3
};

void am_ctx_init(struct AmCtx *ctx, struct Conf *conf);
void am_ctx_free(struct AmCtx *ctx);
void am_set_cond(struct AmCtx *ctx, const char *name, int val);
int am_parse_file(struct AmCtx *ctx, const char *path);
char *am_var_get(struct AmCtx *ctx, const char *name, int *err);
int am_var_set(struct AmCtx *ctx, const char *name, const char *val);
const char *am_cur_path(void);
int am_push_input(const char *path);
int am_pop_input(void);
void am_lex_reset(void);

int am_assign(const char *name, int op, const char *val);
int am_include(const char *path, int optional);
int am_if(const char *name, int neg);
int am_else(void);
int am_endif(void);
char *am_join(const char *a, const char *b);

#endif
