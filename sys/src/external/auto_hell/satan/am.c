#include "am.h"
#include "str.h"
#include "util.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

extern int yyparse(void);
extern FILE *yyin;
extern int yylineno;

static struct AmCtx *actx;

struct Inp {
	FILE *f;
	char *path;
	int line;
};

static struct Inp istack[32];
static int istack_len;

static void var_free(void *p)
{
	struct Var *v = p;
	if (!v)
		return;
	free(v->val);
	free(v);
}

void am_ctx_init(struct AmCtx *ctx, struct Conf *conf)
{
	map_init(&ctx->vars);
	map_init(&ctx->conds);
	vec_init(&ctx->cstack);
	vec_init(&ctx->unknowns);
	vec_init(&ctx->unknown_at);
	vec_init(&ctx->unknown_vars);
	ctx->root = NULL;
	ctx->active = 1;
	ctx->path = NULL;
	ctx->err = 0;
	ctx->conf = conf;
}

void am_ctx_free(struct AmCtx *ctx)
{
	vec_free(&ctx->cstack, free);
	vec_free(&ctx->unknowns, free);
	vec_free(&ctx->unknown_at, free);
	vec_free(&ctx->unknown_vars, free);
	free(ctx->root);
	ctx->root = NULL;
	if (!ctx->err) {
		map_free(&ctx->conds, NULL);
		map_free(&ctx->vars, var_free);
	} else {
		ctx->conds.e = NULL;
		ctx->vars.e = NULL;
		ctx->conds.cap = ctx->conds.len = 0;
		ctx->vars.cap = ctx->vars.len = 0;
	}
}

void am_set_cond(struct AmCtx *ctx, const char *name, int val)
{
	map_set(&ctx->conds, name, (void *)(intptr_t)(val + 1));
}

static int cond_get(struct AmCtx *ctx, const char *name, int *found)
{
	void *v;

	v = map_get(&ctx->conds, name);
	if (!v) {
		*found = 0;
		return 0;
	}
	*found = 1;
	return ((int)(intptr_t)v) - 1;
}

static int am_err(const char *fmt, ...)
{
	va_list ap;

	fprintf(stderr, "satan: %s:%d: ", actx && actx->path ? actx->path : "?", yylineno);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	if (actx)
		actx->err = 1;
	return -1;
}

static void am_warn(const char *fmt, ...)
{
	va_list ap;

	fprintf(stderr, "satan: %s:%d: ", actx && actx->path ? actx->path : "?", yylineno);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}

static void am_unknown_add(struct AmCtx *ctx, const char *name)
{
	for (size_t i = 0; i < ctx->unknowns.len; i++) {
		char *cur = vec_get(&ctx->unknowns, i);
		if (strcmp(cur, name) == 0)
			return;
	}
	vec_push(&ctx->unknowns, xstrdup(name));
}

static void am_unknown_at_add(struct AmCtx *ctx, const char *name)
{
	for (size_t i = 0; i < ctx->unknown_at.len; i++) {
		char *cur = vec_get(&ctx->unknown_at, i);
		if (strcmp(cur, name) == 0)
			return;
	}
	vec_push(&ctx->unknown_at, xstrdup(name));
}

static void am_unknown_var_add(struct AmCtx *ctx, const char *name)
{
	for (size_t i = 0; i < ctx->unknown_vars.len; i++) {
		char *cur = vec_get(&ctx->unknown_vars, i);
		if (strcmp(cur, name) == 0)
			return;
	}
	vec_push(&ctx->unknown_vars, xstrdup(name));
}

static char *atvar_get(struct AmCtx *ctx, const char *name, int *err);

static int is_simple_var(const char *s)
{
	if (!s || !*s)
		return 0;
	if (!(isalpha((unsigned char)s[0]) || s[0] == '_'))
		return 0;
	for (const char *p = s + 1; *p; p++) {
		if (!(isalnum((unsigned char)*p) || *p == '_'))
			return 0;
	}
	return 1;
}

static char *name_expand_at(struct AmCtx *ctx, const char *s)
{
	struct Str out;
	size_t i, n;

	if (!s)
		return xstrdup("");
	str_init(&out);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == '@') {
			size_t j = i + 1;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				char *name = xmalloc(j - (i + 1) + 1);
				char *val;
				memcpy(name, s + i + 1, j - (i + 1));
				name[j - (i + 1)] = '\0';
				val = atvar_get(ctx, name, NULL);
				free(name);
				if (val) {
					str_add(&out, val);
					free(val);
				}
				i = j;
				continue;
			}
		}
		str_addc(&out, s[i]);
	}
	return str_finish(&out);
}

static char *name_canon(const char *s)
{
	char *out;

	if (!s)
		return xstrdup("");
	out = xstrdup(s);
	for (char *p = out; *p; p++) {
		if (!isalnum((unsigned char)*p))
			*p = '_';
	}
	return out;
}

static char *name_norm(struct AmCtx *ctx, const char *s)
{
	char *exp = name_expand_at(ctx, s);
	char *out = name_canon(exp);

	free(exp);
	return out;
}

const char *am_cur_path(void)
{
	return actx && actx->path ? actx->path : "?";
}

char *am_join(const char *a, const char *b)
{
	return str_join_space(a, b);
}

static struct Var *var_get(struct AmCtx *ctx, const char *name)
{
	return map_get(&ctx->vars, name);
}

static int var_set(struct AmCtx *ctx, const char *name, int type, const char *val)
{
	struct Var *v;

	v = var_get(ctx, name);
	if (!v) {
		v = xmalloc(sizeof(*v));
		v->type = type;
		v->val = xstrdup(val ? val : "");
		return map_set(&ctx->vars, name, v);
	}
	if (v->type != type) {
		v->type = type;
	}
	free(v->val);
	v->val = xstrdup(val ? val : "");
	return 0;
}

static char *am_expand_rec(struct AmCtx *ctx, const char *s, int depth, int *err);

static char *atvar_get(struct AmCtx *ctx, const char *name, int *err)
{
	const char *v;
	int perm;
	size_t nlen;
	size_t vlen;

	(void)err;
	perm = conf_get_int(ctx->conf, "PERMISSIVE", 0);
	v = conf_get(ctx->conf, name);
	if (!v && strcmp(name, "prefix") == 0)
		v = conf_get(ctx->conf, "PREFIX");
	if (!v && strcmp(name, "bindir") == 0)
		v = conf_get(ctx->conf, "BINDIR");
	if (!v && strcmp(name, "libdir") == 0)
		v = conf_get(ctx->conf, "LIBDIR");
	if (!v && strcmp(name, "includedir") == 0)
		v = conf_get(ctx->conf, "INCLUDEDIR");
	if (!v && strcmp(name, "CC") == 0)
		v = conf_get(ctx->conf, "CC");
	if (!v && strcmp(name, "CFLAGS") == 0)
		v = conf_get(ctx->conf, "CFLAGS");
	if (!v && strcmp(name, "CPPFLAGS") == 0)
		v = conf_get(ctx->conf, "CPPFLAGS");
	if (!v && strcmp(name, "LDFLAGS") == 0)
		v = conf_get(ctx->conf, "LDFLAGS");
	if (!v && strcmp(name, "prefix") == 0)
		v = conf_get(ctx->conf, "PREFIX");
	if (!v && strcmp(name, "mandir") == 0)
		v = conf_get(ctx->conf, "MANDIR");
	if (v && name) {
		nlen = strlen(name);
		vlen = strlen(v);
		if (vlen == nlen + 2 && v[0] == '@' && v[vlen - 1] == '@' &&
			strncmp(v + 1, name, nlen) == 0)
			v = NULL;
	}
	if (!v) {
		if (perm)
			return xstrdup("");
		am_unknown_at_add(ctx, name);
		am_warn("unknown @%s@ substitution", name);
		return xstrdup("");
	}
	{
		int xerr = 0;
		char *exp = am_expand_rec(ctx, v, 0, &xerr);
		if (!xerr && exp)
			return exp;
		free(exp);
		return xstrdup(v);
	}
}

char *am_var_get(struct AmCtx *ctx, const char *name, int *err)
{
	struct Var *v;
	char *key;

	key = name_norm(ctx, name);
	v = var_get(ctx, key);
	free(key);
	if (!v)
		return xstrdup("");
	if (v->type == VAR_SIMPLE)
		return xstrdup(v->val);
	return am_expand_rec(ctx, v->val, 0, err);
}

int am_var_set(struct AmCtx *ctx, const char *name, const char *val)
{
	char *key = name_norm(ctx, name);
	int rc = var_set(ctx, key, VAR_SIMPLE, val);
	free(key);
	return rc;
}

static char *am_expand_rec(struct AmCtx *ctx, const char *s, int depth, int *err)
{
	struct Str out;
	size_t i, n;
	char *name, *val;

	if (*err)
		return NULL;
	if (depth > 32) {
		am_err("variable expansion too deep");
		*err = 1;
		return NULL;
	}
	str_init(&out);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == '$' && i + 1 < n && s[i + 1] == '$') {
			str_addc(&out, '$');
			i++;
			continue;
		}
		if (s[i] == '$' && i + 1 < n && (s[i + 1] == '(' || s[i + 1] == '{')) {
			char endc = (s[i + 1] == '(') ? ')' : '}';
			size_t j = i + 2;
			while (j < n && s[j] != endc)
				j++;
			if (j >= n) {
				am_err("unterminated variable expansion");
				*err = 1;
				break;
			}
			name = xstrndup(s + i + 2, j - (i + 2));
			{
				char *key = name_norm(ctx, name);
				struct Var *v = var_get(ctx, key);
				if (!v) {
					if (is_simple_var(name))
						am_unknown_var_add(ctx, name);
					val = xstrdup("");
				} else if (v->type == VAR_SIMPLE) {
					val = xstrdup(v->val);
				} else {
					val = am_expand_rec(ctx, v->val, depth + 1, err);
				}
				free(key);
			}
			free(name);
			if (*err)
				break;
			if (val) {
				str_add(&out, val);
				free(val);
			}
			i = j;
			continue;
		}
		if (s[i] == '@') {
			size_t j = i + 1;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				name = xmalloc(j - (i + 1) + 1);
				memcpy(name, s + i + 1, j - (i + 1));
				name[j - (i + 1)] = '\0';
				val = atvar_get(ctx, name, err);
				free(name);
				if (*err)
					break;
				if (val) {
					str_add(&out, val);
					free(val);
				}
				i = j;
				continue;
			}
		}
		str_addc(&out, s[i]);
	}
	return str_finish(&out);
}

int am_assign(const char *name, int op, const char *val)
{
	struct Var *v;
	char *exp, *joined;
	int err;
	char *key;
	int rc;

	if (!actx || !actx->active)
		return 0;

	key = name_norm(actx, name);
	v = var_get(actx, key);
	if (op == AM_ASSIGN) {
		rc = var_set(actx, key, VAR_RECURSIVE, val);
		free(key);
		return rc;
	}
	if (op == AM_IMMEDIATE) {
		err = 0;
		exp = am_expand_rec(actx, val, 0, &err);
		if (err) {
			free(key);
			return -1;
		}
		{
			rc = var_set(actx, key, VAR_SIMPLE, exp);
			free(exp);
			free(key);
			return rc;
		}
	}
	if (op == AM_DEFAULT) {
		if (!v)
			rc = var_set(actx, key, VAR_RECURSIVE, val);
		else
			rc = 0;
		free(key);
		return rc;
	}
	if (op == AM_APPEND) {
		if (!v) {
			rc = var_set(actx, key, VAR_RECURSIVE, val);
			free(key);
			return rc;
		}
		if (v->type == VAR_SIMPLE) {
			err = 0;
			exp = am_expand_rec(actx, val, 0, &err);
			if (err) {
				free(key);
				return -1;
			}
			joined = str_join_space(v->val, exp);
			free(exp);
			{
				rc = var_set(actx, key, VAR_SIMPLE, joined);
				free(joined);
				free(key);
				return rc;
			}
		}
		joined = str_join_space(v->val, val);
		{
			rc = var_set(actx, key, VAR_RECURSIVE, joined);
			free(joined);
			free(key);
			return rc;
		}
	}
	free(key);
	return 0;
}

int am_if(const char *name, int neg)
{
	struct Cond *c;
	int val, found;

	val = cond_get(actx, name, &found);
	c = xmalloc(sizeof(*c));
	memset(c, 0, sizeof(*c));
	if (!found) {
		if (actx)
			am_unknown_add(actx, name);
		am_warn("unknown conditional %s", name);
		c->unknown = 1;
		c->parent_active = actx->active;
		c->val = 0;
		c->in_else = 0;
		c->this_active = (c->parent_active && 0);
		actx->active = c->this_active;
		vec_push(&actx->cstack, c);
		return 0;
	}
	if (neg)
		val = !val;
	c->parent_active = actx->active;
	c->val = val;
	c->in_else = 0;
	c->this_active = (c->parent_active && val);
	actx->active = c->this_active;
	vec_push(&actx->cstack, c);
	return 0;
}

int am_else(void)
{
	struct Cond *c;

	c = vec_get(&actx->cstack, actx->cstack.len - 1);
	if (!c)
		return am_err("else without if");
	if (c->in_else)
		return am_err("duplicate else");
	c->in_else = 1;
	if (c->unknown)
		c->this_active = c->parent_active;
	else
		c->this_active = (c->parent_active && !c->val);
	actx->active = c->this_active;
	return 0;
}

int am_endif(void)
{
	struct Cond *c;

	c = vec_get(&actx->cstack, actx->cstack.len - 1);
	if (!c)
		return am_err("endif without if");
	actx->active = c->parent_active;
	free(c);
	actx->cstack.len--;
	return 0;
}

static FILE *am_preprocess(const char *path)
{
	FILE *in, *out;
	char line[4096];
	struct Str buf;
	int cont;
	int cmd_cont;

	in = fopen(path, "r");
	if (!in)
		return NULL;
	out = tmpfile();
	if (!out) {
		fclose(in);
		return NULL;
	}
	str_init(&buf);
	cont = 0;
	cmd_cont = 0;
	while (fgets(line, sizeof(line), in)) {
		size_t len = strlen(line);
		size_t tlen;
		while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
			line[--len] = '\0';
		if (cmd_cont) {
			tlen = len;
			while (tlen > 0 && isspace((unsigned char)line[tlen - 1]))
				tlen--;
			if (tlen > 0 && line[tlen - 1] == '\\') {
				fputc('\n', out);
				continue;
			}
			fputc('\n', out);
			cmd_cont = 0;
			continue;
		}
		if (!cont) {
			size_t i = 0;
			int saw_tab = 0;
			while (line[i] == ' ' || line[i] == '\t') {
				if (line[i] == '\t')
					saw_tab = 1;
				i++;
			}
			if (!saw_tab && line[i] != '\0' && strncmp(line + i, "hell.", 5) == 0) {
				fputc('\n', out);
				continue;
			}
			if (saw_tab && line[i] != '\0') {
				tlen = len;
				while (tlen > 0 && isspace((unsigned char)line[tlen - 1]))
					tlen--;
				if (tlen > 0 && line[tlen - 1] == '\\')
					cmd_cont = 1;
				fputc('\n', out);
				continue;
			}
		}
		for (size_t i = 0; i < len; i++) {
			if (line[i] == '#' && (i == 0 || isspace((unsigned char)line[i - 1]))) {
				line[i] = '\0';
				len = i;
				break;
			}
		}
		while (len > 0 && isspace((unsigned char)line[len - 1]))
			line[--len] = '\0';
		if (len > 0 && line[len - 1] == '\\') {
			line[--len] = '\0';
			str_add(&buf, line);
			str_addc(&buf, ' ');
			cont = 1;
			continue;
		}
		if (cont)
			str_add(&buf, line);
		else
			str_add(&buf, line);
		fputs(buf.s ? buf.s : "", out);
		fputc('\n', out);
		str_free(&buf);
		str_init(&buf);
		cont = 0;
	}
	if (buf.len) {
		fputs(buf.s, out);
		fputc('\n', out);
	}
	str_free(&buf);
	fclose(in);
	rewind(out);
	return out;
}

int am_push_input(const char *path)
{
	struct Inp in;
	FILE *f;

	f = am_preprocess(path);
	if (!f)
		return -1;
	if (istack_len >= (int)(sizeof(istack) / sizeof(istack[0])))
		return am_err("include depth too deep");
	in.f = yyin;
	in.path = actx->path;
	in.line = yylineno;
	istack[istack_len++] = in;
	yyin = f;
	actx->path = xstrdup(path);
	yylineno = 1;
	am_lex_reset();
	return 0;
}

int am_pop_input(void)
{
	if (yyin)
		fclose(yyin);
	if (actx && actx->path) {
		free((char *)actx->path);
		actx->path = NULL;
	}
	if (istack_len == 0) {
		yyin = NULL;
		return 0;
	}
	istack_len--;
	yyin = istack[istack_len].f;
	actx->path = istack[istack_len].path;
	yylineno = istack[istack_len].line;
	am_lex_reset();
	return 1;
}

int am_include(const char *path, int optional)
{
	char *dir, *full;
	int err;
	int abs;

	if (!actx || !actx->active)
		return 0;
	err = 0;
	full = am_expand_rec(actx, path, 0, &err);
	if (err) {
		free(full);
		return -1;
	}
	abs = path_is_abs(full);
	if (abs) {
		dir = xstrdup(full);
	} else {
		char *base = path_dir(actx->path ? actx->path : ".");
		dir = path_join(base, full);
		free(base);
	}
	if (am_push_input(dir) != 0) {
		if (!abs && actx->root && *actx->root) {
			char *alt = path_join(actx->root, full);
			if (am_push_input(alt) == 0) {
				free(alt);
				free(dir);
				free(full);
				return 0;
			}
			free(alt);
		}
		if (optional) {
			free(dir);
			free(full);
			return 0;
		}
		am_warn("include failed: %s", dir);
		free(dir);
		free(full);
		return 0;
	}
	free(dir);
	free(full);
	return 0;
}

int am_parse_file(struct AmCtx *ctx, const char *path)
{
	FILE *f;
	int rc;

	actx = ctx;
	ctx->active = 1;
	ctx->err = 0;
	istack_len = 0;
	am_lex_reset();
	if (ctx->root) {
		free(ctx->root);
		ctx->root = NULL;
	}
	f = am_preprocess(path);
	if (!f) {
		am_err("unable to read %s", path);
		return -1;
	}
	yyin = f;
	ctx->root = path_dir(path);
	ctx->path = xstrdup(path);
	yylineno = 1;
	rc = yyparse();
	am_pop_input();
	if (rc != 0 || ctx->err)
		return -1;
	return 0;
}
