#include "gen.h"
#include "gen_internal.h"
#include "probe.h"
#include "am.h"
#include "conf.h"
#include "map.h"
#include "str.h"
#include "util.h"
#include "vec.h"

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

enum {
	TGT_PROG = 1,
	TGT_LIB = 2
};

enum {
	INST_NONE = 0,
	INST_BIN = 1,
	INST_SBIN = 2,
	INST_LIB = 3,
	INST_HDR = 4,
	INST_LIBEXEC = 5
};

struct Target {
	int type;
	int inst;
	int has_cxx;
	char *name;
	char *orig;
	char *stem;
	struct Vec srcs;
	char *cppflags;
	char *cflags;
	char *cxxflags;
	char *asflags;
	char *ldflags;
	char *libs;
	struct Vec implibs;
};

struct GenRule {
	char *tgt;
	char *deps;
	char *cmd;
};

struct DataItem {
	char *file;
	char *dir;
};

struct HellInstall {
	char *src;
	char *dst;
	int mode;
};

struct Dir {
	char *path;
	char *rel;
	struct AmCtx am;
	struct Vec subdirs;
	struct Vec targets;
	struct Vec gens;
	struct Vec built;
	struct Vec headers;
	struct Vec data;
	struct Vec hell_installs;
};

struct InstItem {
	char *src;
	char *dst;
	int mode;
};

static char *path_simplify(const char *p);
static int is_make_cmd(const char *cmd);

static void tgt_free(void *p)
{
	struct Target *t = p;
	if (!t)
		return;
	vec_free(&t->srcs, free);
	vec_free(&t->implibs, free);
	free(t->name);
	free(t->orig);
	free(t->stem);
	free(t->cppflags);
	free(t->cflags);
	free(t->cxxflags);
	free(t->asflags);
	free(t->ldflags);
	free(t->libs);
	free(t);
}

static void genrule_free(void *p)
{
	struct GenRule *r = p;
	if (!r)
		return;
	free(r->tgt);
	free(r->deps);
	free(r->cmd);
	free(r);
}

static void data_free(void *p)
{
	struct DataItem *di = p;
	if (!di)
		return;
	free(di->file);
	free(di->dir);
	free(di);
}

static void hell_install_free(void *p)
{
	struct HellInstall *hi = p;
	if (!hi)
		return;
	free(hi->src);
	free(hi->dst);
	free(hi);
}

static void dir_free(void *p)
{
	struct Dir *d = p;
	if (!d)
		return;
	am_ctx_free(&d->am);
	vec_free(&d->subdirs, free);
	vec_free(&d->targets, tgt_free);
	vec_free(&d->gens, genrule_free);
	vec_free(&d->built, free);
	vec_free(&d->headers, free);
	vec_free(&d->data, data_free);
	vec_free(&d->hell_installs, hell_install_free);
	free(d->path);
	free(d->rel);
	free(d);
}

static void inst_free(void *p)
{
	struct InstItem *it = p;
	if (!it)
		return;
	free(it->src);
	free(it->dst);
	free(it);
}

static void gen_init(struct GenCtx *g, struct Conf *conf)
{
	g->conf = conf;
	map_init(&g->seen_dirs);
	map_init(&g->warn_flags);
	map_init(&g->conds);
	map_init(&g->defs);
	map_init(&g->undefs);
	map_init(&g->need_gen);
	map_init(&g->gen_pick);
	g->have_config_h = 0;
	g->probe_static_ok = conf_get_int(conf, "FULLY_STATIC", 1);
	g->probe_quiet = 0;
	g->probe_total = 0;
	g->probe_done = 0;
	vec_init(&g->probe_log);
	vec_init(&g->dirs);
	vec_init(&g->installs);
	vec_init(&g->replace_srcs);
}

static void gen_free(struct GenCtx *g)
{
	vec_free(&g->dirs, dir_free);
	vec_free(&g->installs, inst_free);
	vec_free(&g->replace_srcs, free);
	probe_log_free(g);
	map_free(&g->seen_dirs, NULL);
	map_free(&g->warn_flags, NULL);
	map_free(&g->conds, NULL);
	map_free(&g->defs, free);
	map_free(&g->undefs, NULL);
	map_free(&g->need_gen, NULL);
	map_free(&g->gen_pick, NULL);
}

int warn_once(struct GenCtx *g, const char *msg)
{
	if (map_has(&g->warn_flags, msg))
		return 0;
	map_set(&g->warn_flags, msg, (void *)1);
	fprintf(stderr, "satan: warning: %s\n", msg);
	return 0;
}

static void stub_add_cond(struct Vec *lines, struct Map *seen, struct Conf *conf,
	int have_conf, const char *name)
{
	struct Str key;
	struct Str line;
	char *k;

	if (!name || !*name)
		return;
	str_init(&key);
	str_add(&key, "COND_");
	str_add(&key, name);
	k = str_finish(&key);
	if (have_conf && conf_get(conf, k)) {
		free(k);
		return;
	}
	if (map_has(seen, k)) {
		free(k);
		return;
	}
	map_set(seen, k, (void *)1);
	str_init(&line);
	str_add(&line, k);
	str_add(&line, "=0");
	vec_push(lines, str_finish(&line));
	free(k);
}

static void stub_add_at(struct Vec *lines, struct Map *seen, struct Conf *conf,
	int have_conf, const char *name)
{
	struct Str line;
	const char *cur;
	size_t nlen;
	size_t vlen;

	if (!name || !*name)
		return;
	cur = have_conf ? conf_get(conf, name) : NULL;
	if (cur) {
		nlen = strlen(name);
		vlen = strlen(cur);
		if (!(vlen == nlen + 2 && cur[0] == '@' && cur[vlen - 1] == '@' &&
			strncmp(cur + 1, name, nlen) == 0))
			return;
	}
	if (map_has(seen, name))
		return;
	map_set(seen, name, (void *)1);
	str_init(&line);
	str_add(&line, name);
	str_add(&line, "=");
	vec_push(lines, str_finish(&line));
}

static void stub_add_var(struct Vec *lines, struct Map *seen, struct Conf *conf,
	int have_conf, const char *name)
{
	struct Str key;
	struct Str line;
	char *k;

	if (!name || !*name)
		return;
	str_init(&key);
	str_add(&key, "VAR_");
	str_add(&key, name);
	k = str_finish(&key);
	if (have_conf && conf_get(conf, k)) {
		free(k);
		return;
	}
	if (map_has(seen, k)) {
		free(k);
		return;
	}
	map_set(seen, k, (void *)1);
	str_init(&line);
	str_add(&line, k);
	str_add(&line, "=");
	vec_push(lines, str_finish(&line));
	free(k);
}

static int write_stub_lists(const char *root, struct Vec *conds, struct Vec *atvars,
	struct Vec *vars)
{
	struct Conf conf;
	struct Map seen;
	struct Vec lines;
	char *path;
	FILE *f;
	int have_file = 0;
	int have_conf = 0;

	if ((!conds || conds->len == 0) &&
		(!atvars || atvars->len == 0) &&
		(!vars || vars->len == 0))
		return 0;
	conf_init(&conf);
	map_init(&seen);
	vec_init(&lines);

	path = path_join(root, ".satan");
	if (access(path, F_OK) == 0) {
		have_file = 1;
		if (conf_load(&conf, path) == 0)
			have_conf = 1;
		else
			fprintf(stderr, "satan: %s: unable to read, appending anyway\n", path);
	}
	if (conds) {
		for (size_t i = 0; i < conds->len; i++)
			stub_add_cond(&lines, &seen, &conf, have_conf, vec_get(conds, i));
	}
	if (atvars) {
		for (size_t i = 0; i < atvars->len; i++)
			stub_add_at(&lines, &seen, &conf, have_conf, vec_get(atvars, i));
	}
	if (vars) {
		for (size_t i = 0; i < vars->len; i++)
			stub_add_var(&lines, &seen, &conf, have_conf, vec_get(vars, i));
	}
	if (lines.len == 0) {
		free(path);
		vec_free(&lines, free);
		map_free(&seen, NULL);
		conf_free(&conf);
		return 0;
	}
	f = fopen(path, have_file ? "a" : "w");
	if (!f) {
		fprintf(stderr, "satan: %s: %s\n", path, strerror(errno));
		free(path);
		vec_free(&lines, free);
		map_free(&seen, NULL);
		conf_free(&conf);
		return -1;
	}
	if (!have_file)
		fprintf(f, "# satan stub\n");
	for (size_t i = 0; i < lines.len; i++) {
		char *line = vec_get(&lines, i);
		fprintf(f, "%s\n", line);
	}
	fclose(f);
	fprintf(stderr, "satan: %s .satan with %zu unknowns\n",
		have_file ? "updated" : "wrote", lines.len);
	free(path);
	vec_free(&lines, free);
	map_free(&seen, NULL);
	conf_free(&conf);
	return 0;
}

static int write_stub(const char *root, struct AmCtx *am)
{
	if (!am)
		return 0;
	return write_stub_lists(root, &am->unknowns, &am->unknown_at, &am->unknown_vars);
}

static int write_stub_all(struct GenCtx *g, const char *root)
{
	struct Vec conds;
	struct Vec atvars;
	struct Vec vars;

	vec_init(&conds);
	vec_init(&atvars);
	vec_init(&vars);
	for (size_t i = 0; i < g->dirs.len; i++) {
		struct Dir *d = vec_get(&g->dirs, i);
		for (size_t j = 0; j < d->am.unknowns.len; j++)
			vec_push(&conds, vec_get(&d->am.unknowns, j));
		for (size_t j = 0; j < d->am.unknown_at.len; j++)
			vec_push(&atvars, vec_get(&d->am.unknown_at, j));
		for (size_t j = 0; j < d->am.unknown_vars.len; j++)
			vec_push(&vars, vec_get(&d->am.unknown_vars, j));
	}
	{
		int rc = write_stub_lists(root, &conds, &atvars, &vars);
		vec_free(&conds, NULL);
		vec_free(&atvars, NULL);
		vec_free(&vars, NULL);
		return rc;
	}
}

static int is_space(int c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static int is_zero_word(const char *s)
{
	return s && strcmp(s, "0") == 0;
}

static int is_comment_word(const char *s)
{
	return s && (s[0] == '#' || (s[0] == '\\' && s[1] == '#'));
}

void split_words(struct Vec *out, const char *s)
{
	const char *p, *start;
	char quote;
	int stop;

	vec_init(out);
	if (!s)
		return;
	p = s;
	stop = 0;
	while (*p) {
		while (*p && is_space((unsigned char)*p))
			p++;
		if (!*p)
			break;
		quote = 0;
		start = p;
		if (*p == '\"' || *p == '\'') {
			quote = *p;
			p++;
			while (*p && *p != quote)
				p++;
			if (*p == quote)
				p++;
		} else {
			while (*p && !is_space((unsigned char)*p))
				p++;
		}
		{
			char *tok = xstrndup(start, (size_t)(p - start));
			if (is_comment_word(tok)) {
				free(tok);
				stop = 1;
			} else if (!is_zero_word(tok)) {
				vec_push(out, tok);
			} else {
				free(tok);
			}
		}
		if (stop)
			break;
	}
}

int ends_with(const char *s, const char *suf)
{
	size_t n, m;

	if (!s || !suf)
		return 0;
	n = strlen(s);
	m = strlen(suf);
	if (m > n)
		return 0;
	return strcmp(s + (n - m), suf) == 0;
}

static int is_config_status_word(const char *s)
{
	return s && (strcmp(s, "config.status") == 0 || ends_with(s, "/config.status"));
}

static int has_glob_chars(const char *s)
{
	if (!s)
		return 0;
	return strchr(s, '*') || strchr(s, '?') || strchr(s, '[');
}

static int src_in_vec(struct Vec *v, const char *s)
{
	for (size_t i = 0; i < v->len; i++) {
		char *cur = vec_get(v, i);
		if (strcmp(cur, s) == 0)
			return 1;
	}
	return 0;
}

int starts_with(const char *s, const char *pre)
{
	size_t n, m;

	if (!s || !pre)
		return 0;
	n = strlen(s);
	m = strlen(pre);
	if (m > n)
		return 0;
	return strncmp(s, pre, m) == 0;
}

static int path_is_dir(const char *p)
{
	struct stat st;
	if (!p || !*p)
		return 0;
	if (stat(p, &st) != 0)
		return 0;
	return S_ISDIR(st.st_mode);
}

static char *rel_path(const char *rel, const char *p)
{
	size_t n;
	char *out;

	if (!p || !*p)
		return xstrdup("");
	if (!rel || !*rel)
		return path_simplify(p);
	if (path_is_abs(p))
		return xstrdup(p);
	n = strlen(rel);
	if (starts_with(p, rel) && (p[n] == '/' || p[n] == '\0'))
		return path_simplify(p);
	out = path_join(rel, p);
	{
		char *simp = path_simplify(out);
		free(out);
		return simp;
	}
}

static char *src_rel_from_full(struct Dir *d, const char *full)
{
	size_t len;
	if (!full)
		return xstrdup("");
	if (!d || !d->path || !*d->path)
		return xstrdup(full);
	len = strlen(d->path);
	if (starts_with(full, d->path) && (full[len] == '/' || full[len] == '\0')) {
		if (full[len] == '\0')
			return xstrdup(".");
		return xstrdup(full + len + 1);
	}
	return xstrdup(full);
}

static char *rel_up(const char *rel)
{
	const char *p;
	struct Str out;
	int count;

	if (!rel || !*rel)
		return xstrdup(".");
	count = 1;
	for (p = rel; *p; p++) {
		if (*p == '/')
			count++;
	}
	str_init(&out);
	for (int i = 0; i < count; i++) {
		if (i)
			str_addc(&out, '/');
		str_add(&out, "..");
	}
	return str_finish(&out);
}

static char *path_simplify(const char *p)
{
	struct Vec parts;
	struct Str out;
	const char *s;
	int abs;

	if (!p || !*p)
		return xstrdup("");
	abs = path_is_abs(p);
	vec_init(&parts);
	s = p;
	while (*s) {
		const char *e;
		char *seg;
		while (*s == '/')
			s++;
		if (!*s)
			break;
		e = s;
		while (*e && *e != '/')
			e++;
		seg = xstrndup(s, (size_t)(e - s));
		if (strcmp(seg, ".") == 0) {
			free(seg);
		} else if (strcmp(seg, "..") == 0) {
			if (parts.len && strcmp(vec_get(&parts, parts.len - 1), "..") != 0) {
				free(vec_get(&parts, parts.len - 1));
				parts.len--;
				free(seg);
			} else if (!abs) {
				vec_push(&parts, seg);
			} else {
				free(seg);
			}
		} else {
			vec_push(&parts, seg);
		}
		s = e;
	}
	str_init(&out);
	if (abs)
		str_addc(&out, '/');
	for (size_t i = 0; i < parts.len; i++) {
		char *seg = vec_get(&parts, i);
		if (out.len && out.s[out.len - 1] != '/')
			str_addc(&out, '/');
		str_add(&out, seg);
		free(seg);
	}
	vec_free(&parts, NULL);
	if (out.len == 0)
		return abs ? xstrdup("/") : xstrdup(".");
	return str_finish(&out);
}

static void unknown_at_add(struct Dir *d, const char *name)
{
	for (size_t i = 0; i < d->am.unknown_at.len; i++) {
		char *cur = vec_get(&d->am.unknown_at, i);
		if (strcmp(cur, name) == 0)
			return;
	}
	vec_push(&d->am.unknown_at, xstrdup(name));
}

static char *expand_vars_basic(struct Dir *d, const char *s);
static char *expand_atvar_loc(struct Dir *d, const char *name, const char *path, int line, int *err)
{
	const char *v;
	int perm;
	size_t nlen;
	size_t vlen;

	(void)err;
	perm = conf_get_int(d->am.conf, "PERMISSIVE", 0);
	v = conf_get(d->am.conf, name);
	if (!v && strcmp(name, "prefix") == 0)
		v = conf_get(d->am.conf, "PREFIX");
	if (!v && strcmp(name, "bindir") == 0)
		v = conf_get(d->am.conf, "BINDIR");
	if (!v && strcmp(name, "libdir") == 0)
		v = conf_get(d->am.conf, "LIBDIR");
	if (!v && strcmp(name, "includedir") == 0)
		v = conf_get(d->am.conf, "INCLUDEDIR");
	if (!v && strcmp(name, "mandir") == 0)
		v = conf_get(d->am.conf, "MANDIR");
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
		if (line > 0)
			fprintf(stderr, "satan: %s:%d: unknown @%s@ substitution\n", path, line, name);
		else
			fprintf(stderr, "satan: %s: unknown @%s@ substitution\n", path, name);
		unknown_at_add(d, name);
		return xstrdup("");
	}
	{
		char *exp = expand_vars_basic(d, v);
		return exp ? exp : xstrdup("");
	}
}

static char *expand_atvar(struct Dir *d, const char *name, int *err)
{
	return expand_atvar_loc(d, name, d->path ? d->path : "?", 0, err);
}

static char *expand_vars_basic(struct Dir *d, const char *s)
{
	struct Str out;
	size_t i, n;

	if (!s)
		return xstrdup("");
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
			char *name;
			char *val;
			while (j < n && s[j] != endc)
				j++;
			if (j >= n)
				break;
			name = xstrndup(s + i + 2, j - (i + 2));
			val = am_var_get(&d->am, name, NULL);
			if (val) {
				str_add(&out, val);
				free(val);
			}
			free(name);
			i = j;
			continue;
		}
		if (s[i] == '$' && i + 1 < n &&
			(isalpha((unsigned char)s[i + 1]) || s[i + 1] == '_')) {
			size_t j = i + 1;
			char *name;
			char *val;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			name = xstrndup(s + i + 1, j - (i + 1));
			val = am_var_get(&d->am, name, NULL);
			if (val) {
				str_add(&out, val);
				free(val);
			}
			free(name);
			i = j - 1;
			continue;
		}
		str_addc(&out, s[i]);
	}
	return str_finish(&out);
}

static char *expand_vars(struct Dir *d, const char *s, const char *tgt, const char *deps, int use_cd, int *err)
{
	struct Str out;
	size_t i, n;
	char *first;

	*err = 0;
	if (!s)
		return xstrdup("");
	str_init(&out);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == '$' && i + 1 < n && s[i + 1] == '$') {
			str_addc(&out, '$');
			i++;
			continue;
		}
		if (s[i] == '$' && i + 1 < n && s[i + 1] == '@') {
			if (tgt)
				str_add(&out, tgt);
			i++;
			continue;
		}
		if (s[i] == '$' && i + 1 < n && s[i + 1] == '<') {
			if (deps) {
				const char *p = deps;
				while (*p && isspace((unsigned char)*p))
					p++;
				if (*p) {
					const char *q = p;
					while (*q && !isspace((unsigned char)*q))
						q++;
					first = xstrndup(p, (size_t)(q - p));
					str_add(&out, first);
					free(first);
				}
			}
			i++;
			continue;
		}
		if (s[i] == '$' && i + 1 < n && s[i + 1] == '^') {
			if (deps)
				str_add(&out, deps);
			i++;
			continue;
		}
		if (s[i] == '$' && i + 1 < n && (s[i + 1] == '(' || s[i + 1] == '{')) {
			char endc = (s[i + 1] == '(') ? ')' : '}';
			size_t j = i + 2;
			char *name, *val;
			while (j < n && s[j] != endc)
				j++;
			if (j >= n) {
				*err = 1;
				break;
			}
			name = xstrndup(s + i + 2, j - (i + 2));
			if (use_cd && strcmp(name, "srcdir") == 0) {
				val = xstrdup(".");
			} else if (use_cd && strcmp(name, "builddir") == 0) {
				val = xstrdup(".");
			} else if (use_cd && strcmp(name, "top_srcdir") == 0) {
				val = rel_up(d->rel);
			} else if (use_cd && strcmp(name, "top_builddir") == 0) {
				val = rel_up(d->rel);
			} else if (strcmp(name, "@F") == 0) {
				const char *base = tgt ? strrchr(tgt, '/') : NULL;
				val = xstrdup(base ? base + 1 : (tgt ? tgt : ""));
			} else if (strcmp(name, "@D") == 0) {
				const char *base = tgt ? strrchr(tgt, '/') : NULL;
				if (base) {
					val = xstrndup(tgt, (size_t)(base - tgt));
				} else {
					val = xstrdup(".");
				}
			} else {
				val = am_var_get(&d->am, name, err);
			}
			free(name);
			if (*err) {
				free(val);
				break;
			}
			if (val) {
				str_add(&out, val);
				free(val);
			}
			i = j;
			continue;
		}
		if (s[i] == '@') {
			size_t j = i + 1;
			char *name, *val;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				name = xstrndup(s + i + 1, j - (i + 1));
				val = expand_atvar(d, name, err);
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

static char *ninja_escape(const char *s)
{
	struct Str out;

	str_init(&out);
	for (const char *p = s; p && *p; p++) {
		if (*p == '$') {
			str_add(&out, "$$");
			continue;
		}
		str_addc(&out, *p);
	}
	return str_finish(&out);
}

static char *subst_atvars(struct Dir *d, const char *path, int line, const char *s, int *err)
{
	struct Str out;
	size_t i, n;

	*err = 0;
	if (!s)
		return xstrdup("");
	str_init(&out);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] == '@') {
			size_t j = i + 1;
			char *name, *val;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				name = xstrndup(s + i + 1, j - (i + 1));
				val = expand_atvar_loc(d, name, path, line, err);
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

static int write_subst_header(struct Dir *d, const char *inpath, const char *outpath)
{
	FILE *in, *out;
	char line[4096];
	int lineno = 0;

	in = fopen(inpath, "r");
	if (!in)
		return -1;
	out = fopen(outpath, "w");
	if (!out) {
		fclose(in);
		return -1;
	}
	while (fgets(line, sizeof(line), in)) {
		int err = 0;
		char *exp = subst_atvars(d, inpath, ++lineno, line, &err);
		if (err) {
			free(exp);
			fclose(in);
			fclose(out);
			return -1;
		}
		fputs(exp, out);
		free(exp);
	}
	fclose(in);
	fclose(out);
	return 0;
}

static int skip_stamp(struct Dir *d, const char *name)
{
	char *base;
	char *tmpl;
	char *full;
	int skip;

	if (!starts_with(name, "stamp-"))
		return 0;
	base = (char *)name + 6;
	if (!*base)
		return 0;
	tmpl = xmalloc(strlen(base) + 6);
	sprintf(tmpl, "%s.h.in", base);
	full = path_join(d->path, tmpl);
	skip = (access(full, R_OK) == 0);
	free(tmpl);
	free(full);
	return skip;
}

static struct GenRule *find_gen(struct Dir *d, const char *tgt)
{
	for (size_t i = 0; i < d->gens.len; i++) {
		struct GenRule *r = vec_get(&d->gens, i);
		if (strcmp(r->tgt, tgt) == 0)
			return r;
	}
	return NULL;
}

static char *expand_deps(struct Dir *d, const char *deps)
{
	int err;
	char *exp;
	struct Vec words;
	struct Str out;
	size_t reln;

	exp = expand_vars(d, deps, NULL, NULL, 0, &err);
	if (err) {
		free(exp);
		return NULL;
	}
	vec_init(&words);
	split_words(&words, exp);
	free(exp);
	str_init(&out);
	reln = d->rel ? strlen(d->rel) : 0;
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		char *use = w;
		char *rp;
		if (is_config_status_word(use))
			continue;
		if (strcmp(w, "Makefile") == 0)
			use = "Makefile.am";
		if (starts_with(use, "./")) {
			rp = xstrdup(use + 2);
		} else if (use[0] == '/') {
			rp = xstrdup(use);
		} else if (reln && starts_with(use, "./") &&
			strncmp(use + 2, d->rel, reln) == 0 &&
			(use[2 + reln] == '/' || use[2 + reln] == '\0')) {
			rp = xstrdup(use + 2);
		} else if (reln && strncmp(use, d->rel, reln) == 0 &&
			(use[reln] == '/' || use[reln] == '\0')) {
			rp = xstrdup(use);
		} else {
			rp = rel_path(d->rel, use);
		}
		{
			char *simp = path_simplify(rp);
			free(rp);
			rp = simp;
		}
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, rp);
		free(rp);
	}
	vec_free(&words, free);
	return str_finish(&out);
}

static char *expand_deps_cmd(struct Dir *d, const char *deps)
{
	int err;
	char *exp;
	struct Vec words;
	struct Str out;

	exp = expand_vars(d, deps, NULL, NULL, 0, &err);
	if (err) {
		free(exp);
		return NULL;
	}
	vec_init(&words);
	split_words(&words, exp);
	free(exp);
	str_init(&out);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		char *use = w;
		if (is_config_status_word(use))
			continue;
		if (strcmp(w, "Makefile") == 0)
			use = "Makefile.am";
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, use);
	}
	vec_free(&words, free);
	return str_finish(&out);
}

static int deps_words(struct Dir *d, const char *deps, struct Vec *out)
{
	int err;
	char *exp;

	exp = expand_vars(d, deps, NULL, NULL, 0, &err);
	if (err) {
		free(exp);
		return -1;
	}
	split_words(out, exp);
	for (size_t i = 0; i < out->len; ) {
		char *w = vec_get(out, i);
		if (is_config_status_word(w)) {
			free(w);
			out->v[i] = out->v[out->len - 1];
			out->len--;
			continue;
		}
		i++;
	}
	free(exp);
	return 0;
}

static char *replace_suffix(const char *s, const char *suf, const char *rep)
{
	size_t n, m, r;
	char *out;

	n = strlen(s);
	m = strlen(suf);
	r = strlen(rep);
	if (m > n)
		return xstrdup(s);
	out = xmalloc(n - m + r + 1);
	memcpy(out, s, n - m);
	memcpy(out + (n - m), rep, r);
	out[n - m + r] = '\0';
	return out;
}

static char *stem_from_target(const char *name)
{
	char *s;

	s = xstrdup(name);
	for (char *p = s; *p; p++) {
		if (!isalnum((unsigned char)*p))
			*p = '_';
	}
	return s;
}

static char *join_flags(const char *a, const char *b, const char *c, const char *d, const char *e)
{
	struct Str out;
	const char *vals[5] = {a, b, c, d, e};

	str_init(&out);
	for (int i = 0; i < 5; i++) {
		if (!vals[i] || !*vals[i])
			continue;
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, vals[i]);
	}
	return str_finish(&out);
}

static int token_is_clean(const char *tok)
{
	const unsigned char *p;

	if (!tok || !*tok)
		return 0;
	for (p = (const unsigned char *)tok; *p; p++) {
		if (*p < 0x20 || *p == 0x7f || *p >= 0x80)
			return 0;
	}
	return 1;
}

int str_has_bad_chars(const char *s)
{
	const unsigned char *p;

	if (!s || !*s)
		return 0;
	for (p = (const unsigned char *)s; *p; p++) {
		if (*p >= 0x80)
			return 1;
		if (*p < 0x20 && *p != ' ' && *p != '\t')
			return 1;
	}
	return 0;
}

static char *filter_flags(const char *s)
{
	struct Vec words;
	struct Str out;

	if (!s)
		return xstrdup("");
	split_words(&words, s);
	str_init(&out);
	for (size_t i = 0; i < words.len; i++) {
		char *tok = vec_get(&words, i);
		if (strcmp(tok, "0") == 0)
			continue;
		if (!token_is_clean(tok))
			continue;
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, tok);
	}
	vec_free(&words, free);
	return str_finish(&out);
}

static int flag_has(const char *flags, const char *tok)
{
	struct Vec words;

	if (!flags || !*flags || !tok || !*tok)
		return 0;
	split_words(&words, flags);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		if (strcmp(w, tok) == 0) {
			vec_free(&words, free);
			return 1;
		}
	}
	vec_free(&words, free);
	return 0;
}

static int is_shared_flag(const char *t)
{
	return strcmp(t, "-shared") == 0 ||
		strcmp(t, "-module") == 0 ||
		strcmp(t, "-avoid-version") == 0 ||
		strncmp(t, "-version-info", 13) == 0 ||
		strncmp(t, "-export-symbols", 15) == 0 ||
		strncmp(t, "-Wl,-soname,", 12) == 0;
}

static char *filter_ldflags(struct GenCtx *g, const char *s)
{
	struct Vec words;
	struct Str out;

	if (!s)
		return xstrdup("");
	split_words(&words, s);
	str_init(&out);
	for (size_t i = 0; i < words.len; i++) {
		char *tok = vec_get(&words, i);
		if (strcmp(tok, "0") == 0)
			continue;
		if (!token_is_clean(tok)) {
			warn_once(g, "dropping non-printable ldflags token");
			continue;
		}
		if (is_shared_flag(tok)) {
			char msg[256];
			snprintf(msg, sizeof(msg), "ignoring libtool flag %s for static build", tok);
			warn_once(g, msg);
			continue;
		}
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, tok);
	}
	vec_free(&words, free);
	return str_finish(&out);
}

static char *normalize_libs(struct GenCtx *g, const char *s, const char *rel, struct Vec *implibs)
{
	struct Vec words;
	struct Str out;

	vec_init(implibs);
	if (!s)
		return xstrdup("");
	split_words(&words, s);
	str_init(&out);
	for (size_t i = 0; i < words.len; i++) {
		char *tok = vec_get(&words, i);
		char *use = tok;
		char *pref = NULL;
		if (strcmp(tok, "0") == 0)
			continue;
		if (!token_is_clean(tok))
			continue;
		if (ends_with(tok, ".la")) {
			char *conv = replace_suffix(tok, ".la", ".a");
			char msg[256];
			snprintf(msg, sizeof(msg), "converting %s -> %s", tok, conv);
			warn_once(g, msg);
			use = conv;
			free(tok);
			words.v[i] = conv;
		}
		if (rel && *rel && ends_with(use, ".a") && !strchr(use, '/')) {
			pref = path_join(rel, use);
			use = pref;
		}
		if (ends_with(use, ".a"))
			vec_push(implibs, xstrdup(use));
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, use);
		free(pref);
	}
	vec_free(&words, free);
	return str_finish(&out);
}

static int emit_gen_rule(struct GenCtx *g, struct Dir *d, FILE *f, struct Map *done, const char *tgt)
{
	struct GenRule *r;
	struct Vec depv;
	char *out, *deps, *cmd;
	int err;
	int use_cd;

	r = find_gen(d, tgt);
	if (!r)
		return 0;
	out = rel_path(d->rel, r->tgt);
	if (map_has(done, out)) {
		free(out);
		return 0;
	}
	map_set(done, out, (void *)1);

	if (r->deps && *r->deps) {
		if (deps_words(d, r->deps, &depv) != 0)
			goto fail;
		for (size_t i = 0; i < depv.len; i++) {
			char *dep = vec_get(&depv, i);
			if (find_gen(d, dep)) {
				if (emit_gen_rule(g, d, f, done, dep) != 0) {
					vec_free(&depv, free);
					goto fail;
				}
			}
		}
		vec_free(&depv, free);
	}

	if (d->rel && *d->rel) {
		size_t n = strlen(d->rel);
		if (!(starts_with(out, d->rel) && (out[n] == '/' || out[n] == '\0'))) {
			if (is_make_cmd(r->cmd)) {
				free(out);
				return 0;
			}
		}
	}
	deps = expand_deps(d, r->deps);
	use_cd = d->rel && *d->rel;
	if (!r->cmd) {
		if (deps && *deps)
			fprintf(f, "build %s: phony %s\n\n", out, deps);
		free(out);
		free(deps);
		return 0;
	}
	if (r->cmd && r->deps && is_make_cmd(r->cmd) && strstr(r->deps, "stamp-")) {
		if (deps && *deps)
			fprintf(f, "build %s: phony %s\n\n", out, deps);
		free(out);
		free(deps);
		return 0;
	}
	if (use_cd) {
		char *cmd_tgt;
		char *cmd_deps = expand_deps_cmd(d, r->deps);
		char *old_src = am_var_get(&d->am, "srcdir", &err);
		char *old_build = am_var_get(&d->am, "builddir", &err);
		char *old_top_src = am_var_get(&d->am, "top_srcdir", &err);
		char *old_top_build = am_var_get(&d->am, "top_builddir", &err);
		char *up = rel_up(d->rel);
		am_var_set(&d->am, "srcdir", ".");
		am_var_set(&d->am, "builddir", ".");
		am_var_set(&d->am, "top_srcdir", up);
		am_var_set(&d->am, "top_builddir", up);
		free(up);
		{
			char *simp = path_simplify(r->tgt);
			size_t n = strlen(d->rel);
			if (starts_with(simp, d->rel) && (simp[n] == '/' || simp[n] == '\0')) {
				cmd_tgt = xstrdup(simp[n] == '/' ? simp + n + 1 : ".");
			} else {
				cmd_tgt = xstrdup(simp);
			}
			free(simp);
		}
		cmd = expand_vars(d, r->cmd, cmd_tgt, cmd_deps ? cmd_deps : deps, 0, &err);
		free(cmd_tgt);
		if (old_src) {
			am_var_set(&d->am, "srcdir", old_src);
			free(old_src);
		}
		if (old_build) {
			am_var_set(&d->am, "builddir", old_build);
			free(old_build);
		}
		if (old_top_src) {
			am_var_set(&d->am, "top_srcdir", old_top_src);
			free(old_top_src);
		}
		if (old_top_build) {
			am_var_set(&d->am, "top_builddir", old_top_build);
			free(old_top_build);
		}
		free(cmd_deps);
	} else {
		cmd = expand_vars(d, r->cmd, r->tgt, deps, 0, &err);
	}
	if (cmd && strstr(cmd, "config.status")) {
		free(cmd);
		cmd = xmalloc(strlen(out) + 32);
		snprintf(cmd, strlen(out) + 32, "printf \"timestamp\" > %s", out);
		use_cd = 0;
	}
	if (deps && cmd && !err) {
		char *esc = ninja_escape(cmd);
		fprintf(f, "build %s: gen %s\n", out, deps);
		if (use_cd) {
			struct Str wrap;
			str_init(&wrap);
			str_add(&wrap, "cd ");
			str_add(&wrap, d->rel);
			str_add(&wrap, " && ");
			str_add(&wrap, esc);
			fprintf(f, "  cmd = %s\n\n", wrap.s ? wrap.s : "");
			str_free(&wrap);
		} else {
			fprintf(f, "  cmd = %s\n\n", esc);
		}
		free(esc);
	}
	free(out);
	free(deps);
	free(cmd);
	return 0;
fail:
	free(out);
	return -1;
}

static char *obj_name(const char *src)
{
	char *s;
	char *dot;

	s = xstrdup(src);
	dot = strrchr(s, '.');
	if (dot && dot > strrchr(s, '/')) {
		strcpy(dot, ".o");
		return s;
	}
	{
		struct Str out;
		str_init(&out);
		str_add(&out, s);
		str_add(&out, ".o");
		free(s);
		return str_finish(&out);
	}
}

static int is_c_src(const char *s)
{
	return ends_with(s, ".c") || ends_with(s, ".S") || ends_with(s, ".s");
}

static int is_cxx_src(const char *s)
{
	return ends_with(s, ".cc") || ends_with(s, ".cpp") ||
		ends_with(s, ".cxx") || ends_with(s, ".C");
}

static int is_asm_src(const char *s)
{
	return ends_with(s, ".S") || ends_with(s, ".s");
}

static int is_lex_src(const char *s)
{
	return ends_with(s, ".l");
}

static int is_yacc_src(const char *s)
{
	return ends_with(s, ".y");
}

static char *normalize_src_token(struct Dir *d, const char *s)
{
	const char *exts[] = { "c", "S", "s", "l", "y", "h", "cc", "cpp", "cxx", "C" };
	if (!d || !d->path || !s || !*s)
		return NULL;
	if (!ends_with(s, "."))
		return NULL;
	for (size_t i = 0; i < (sizeof(exts) / sizeof(exts[0])); i++) {
		char *cand;
		char *full;
		{
			struct Str out;
			str_init(&out);
			str_add(&out, s);
			str_add(&out, exts[i]);
			cand = str_finish(&out);
		}
		full = path_join(d->path, cand);
		if (access(full, R_OK) == 0) {
			free(full);
			return cand;
		}
		free(full);
		free(cand);
	}
	return NULL;
}

static void add_gen_src(struct Dir *d, const char *src)
{
	char *full;

	if (!src || !*src)
		return;
	full = path_join(d->path, src);
	if (access(full, R_OK) == 0) {
		free(full);
		return;
	}
	free(full);
	if (!find_gen(d, src))
		return;
	if (!src_in_vec(&d->built, src))
		vec_push(&d->built, xstrdup(src));
}

static void add_lex_src(struct Dir *d, struct Target *t, const char *src)
{
	char *out;
	struct GenRule *r;

	if (!src || !*src)
		return;
	out = replace_suffix(src, ".l", ".c");
	if (!src_in_vec(&t->srcs, out))
		vec_push(&t->srcs, xstrdup(out));
	if (!src_in_vec(&d->built, out))
		vec_push(&d->built, xstrdup(out));
	r = find_gen(d, out);
	if (!r) {
		r = xmalloc(sizeof(*r));
		memset(r, 0, sizeof(*r));
		r->tgt = xstrdup(out);
		r->deps = xstrdup(src);
		r->cmd = xstrdup("$(LEX) -o $@ $<");
		vec_push(&d->gens, r);
	}
	free(out);
}

static void add_yacc_src(struct Dir *d, struct Target *t, const char *src)
{
	char *out_c, *out_h;
	struct GenRule *r;
	struct Str cmd;

	if (!src || !*src)
		return;
	out_c = replace_suffix(src, ".y", ".c");
	out_h = replace_suffix(src, ".y", ".h");
	if (!src_in_vec(&t->srcs, out_c))
		vec_push(&t->srcs, xstrdup(out_c));
	if (!src_in_vec(&d->built, out_c))
		vec_push(&d->built, xstrdup(out_c));
	if (!src_in_vec(&d->built, out_h))
		vec_push(&d->built, xstrdup(out_h));
	r = find_gen(d, out_c);
	if (!r) {
		str_init(&cmd);
		str_add(&cmd, "$(YACC) -d -o ");
		str_add(&cmd, out_c);
		str_add(&cmd, " $<");
		str_add(&cmd, " && if [ -f y.tab.h ]; then mv y.tab.h ");
		str_add(&cmd, out_h);
		str_add(&cmd, "; fi");
		str_add(&cmd, " && if [ -f ");
		str_add(&cmd, out_c);
		str_add(&cmd, ".h ]; then mv ");
		str_add(&cmd, out_c);
		str_add(&cmd, ".h ");
		str_add(&cmd, out_h);
		str_add(&cmd, "; fi");
		r = xmalloc(sizeof(*r));
		memset(r, 0, sizeof(*r));
		r->tgt = xstrdup(out_c);
		r->deps = xstrdup(src);
		r->cmd = str_finish(&cmd);
		vec_push(&d->gens, r);
	}
	free(out_c);
	free(out_h);
}

static void add_repl_sources(struct Dir *d, struct Target *t, const char *list)
{
	struct Vec words;

	if (!list || !*list)
		return;
	vec_init(&words);
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *tok = vec_get(&words, i);
		if (is_zero_word(tok))
			continue;
		char *src = NULL;
		if (ends_with(tok, ".lo"))
			src = replace_suffix(tok, ".lo", ".c");
		else if (ends_with(tok, ".o"))
			src = replace_suffix(tok, ".o", ".c");
		else if (ends_with(tok, ".c"))
			src = xstrdup(tok);
		if (src) {
			if (is_c_src(src) && !src_in_vec(&t->srcs, src)) {
				char *full = path_join(d->path, src);
				if (access(full, R_OK) == 0) {
					vec_push(&t->srcs, xstrdup(src));
				} else {
					fprintf(stderr, "satan: %s: missing %s\n", d->path, src);
				}
				free(full);
			}
			free(src);
		}
	}
	vec_free(&words, free);
}

static void cond_set_cb(const char *k, void *v, void *arg)
{
	struct AmCtx *ctx = arg;
	am_set_cond(ctx, k, (int)(intptr_t)v);
}

static void var_from_conf(const char *k, void *v, void *arg)
{
	struct AmCtx *ctx = arg;
	const char *val = v;

	if (strncmp(k, "VAR_", 4) == 0) {
		if (val && *val) {
			am_var_set(ctx, k + 4, val);
		} else {
			int err = 0;
			char *cur = am_var_get(ctx, k + 4, &err);
			if (!err && (!cur || !*cur))
				am_var_set(ctx, k + 4, "");
			free(cur);
		}
	}
}

static const char *conf_pick(const struct Conf *conf, const char *lower, const char *upper)
{
	const char *val;

	val = conf_get(conf, lower);
	if (val && *val)
		return val;
	return conf_get(conf, upper);
}

static int parse_makefile(struct GenCtx *g, const char *root, const char *rel);
static int parse_hell_line(struct Dir *d, const char *line, const char *path, int lineno);

static int scan_rules_file(struct Dir *d, const char *path, struct Map *seen)
{
	FILE *f;
	char line[4096];
	struct Vec cur;
	struct Str cont;
	char *basedir;
	int lineno = 0;

	if (map_has(seen, path))
		return 0;
	map_set(seen, path, (void *)1);
	f = fopen(path, "r");
	if (!f)
		return -1;
	str_init(&cont);
	vec_init(&cur);
	basedir = path_dir(path);
	while (fgets(line, sizeof(line), f)) {
		lineno++;
		size_t len = strlen(line);
		char *work;
		char *p;
		int saw_tab;
		while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
			line[--len] = '\0';
		if (len > 0 && line[len - 1] == '\\') {
			line[--len] = '\0';
			str_add(&cont, line);
			str_addc(&cont, ' ');
			continue;
		}
		if (cont.len) {
			str_add(&cont, line);
			work = cont.s;
		} else {
			work = line;
		}
		p = work;
		saw_tab = 0;
		while (*p == ' ' || *p == '\t') {
			if (*p == '\t')
				saw_tab = 1;
			p++;
		}
		if (*p == '\0' || *p == '#') {
			if (cont.len)
				str_free(&cont);
			continue;
		}
		if (saw_tab) {
			if (cur.len) {
				char *cmd = str_trim(p);
				while (*cmd == '@' || *cmd == '-')
					cmd++;
				while (*cmd && isspace((unsigned char)*cmd))
					cmd++;
				if (cmd && *cmd) {
					for (size_t i = 0; i < cur.len; i++) {
						struct GenRule *r = vec_get(&cur, i);
						if (r->cmd) {
							char *joined = str_join_space(r->cmd, "&&");
							free(r->cmd);
							r->cmd = joined;
							joined = str_join_space(r->cmd, cmd);
							free(r->cmd);
							r->cmd = joined;
						} else {
							r->cmd = xstrdup(cmd);
						}
					}
				}
			}
			if (cont.len)
				str_free(&cont);
			continue;
		}
		if (cur.len) {
			for (size_t i = 0; i < cur.len; i++)
				vec_push(&d->gens, vec_get(&cur, i));
			cur.len = 0;
		}
		if ((starts_with(p, "include") && isspace((unsigned char)p[7])) ||
			(starts_with(p, "-include") && isspace((unsigned char)p[8]))) {
			int optional = (p[0] == '-');
			char *args = p + (optional ? 8 : 7);
			char *exp;
			struct Vec incs;
			int err = 0;
			while (*args && isspace((unsigned char)*args))
				args++;
			exp = expand_vars(d, args, NULL, NULL, 0, &err);
			if (err) {
				free(exp);
				if (cont.len)
					str_free(&cont);
				free(basedir);
				fclose(f);
				return -1;
			}
			vec_init(&incs);
			split_words(&incs, exp);
			free(exp);
			for (size_t ii = 0; ii < incs.len; ii++) {
				char *inc = vec_get(&incs, ii);
				char *full;
				int rc;
				if (inc[0] == '/')
					full = xstrdup(inc);
				else
					full = path_join(basedir, inc);
				rc = scan_rules_file(d, full, seen);
				free(full);
				if (rc != 0 && !optional) {
					fprintf(stderr, "satan: warning: %s: include failed\n", inc);
					continue;
				}
			}
			vec_free(&incs, free);
			if (cont.len)
				str_free(&cont);
			continue;
		}
		if (strchr(p, '=') && (!strchr(p, ':') || strchr(p, '=') < strchr(p, ':'))) {
			if (cont.len)
				str_free(&cont);
			continue;
		}
		if (starts_with(p, "hell.")) {
			if (parse_hell_line(d, p, path, lineno) != 0) {
				if (cont.len)
					str_free(&cont);
				free(basedir);
				fclose(f);
				return -1;
			}
			if (cont.len)
				str_free(&cont);
			continue;
		}
		{
			char *colon = strchr(p, ':');
			struct Vec tgts;
			char *exp;
			if (!colon) {
				if (cont.len)
					str_free(&cont);
				continue;
			}
			*colon = '\0';
			str_trim(p);
			vec_init(&tgts);
			{
				int err = 0;
				exp = expand_vars(d, p, NULL, NULL, 0, &err);
				if (err) {
					vec_free(&tgts, free);
					if (cont.len)
						str_free(&cont);
					free(basedir);
					fclose(f);
					return -1;
				}
				split_words(&tgts, exp);
				free(exp);
			}
			colon++;
			str_trim(colon);
			for (size_t i = 0; i < tgts.len; i++) {
				struct GenRule *r = xmalloc(sizeof(*r));
				memset(r, 0, sizeof(*r));
				r->tgt = xstrdup(vec_get(&tgts, i));
				r->deps = xstrdup(colon);
				vec_push(&cur, r);
			}
			vec_free(&tgts, free);
		}
		if (cont.len)
			str_free(&cont);
	}
	if (cur.len) {
		for (size_t i = 0; i < cur.len; i++)
			vec_push(&d->gens, vec_get(&cur, i));
		cur.len = 0;
	}
	vec_free(&cur, NULL);
	str_free(&cont);
	free(basedir);
	fclose(f);
	return 0;
}

static int scan_rules(struct Dir *d, const char *path)
{
	struct Map seen;
	int rc;

	map_init(&seen);
	rc = scan_rules_file(d, path, &seen);
	map_free(&seen, NULL);
	return rc;
}

static int cmp_str_ptr(const void *a, const void *b)
{
	const char *const *sa = a;
	const char *const *sb = b;
	return strcmp(*sa, *sb);
}

static char *ensure_trailing_slash(const char *s)
{
	size_t n;
	char *out;
	if (!s)
		return xstrdup("");
	if (ends_with(s, "/"))
		return xstrdup(s);
	n = strlen(s);
	out = xmalloc(n + 2);
	memcpy(out, s, n);
	out[n] = '/';
	out[n + 1] = '\0';
	return out;
}

static void hell_add_install(struct Dir *d, const char *src, const char *dst, int mode)
{
	struct HellInstall *hi;
	hi = xmalloc(sizeof(*hi));
	hi->src = xstrdup(src ? src : "");
	hi->dst = xstrdup(dst ? dst : "");
	hi->mode = mode;
	vec_push(&d->hell_installs, hi);
}

static int hell_walk_dir(struct Dir *d, const char *full_dir, const char *rel, const char *dst,
	const char *hf, int line)
{
	DIR *dp;
	struct dirent *de;
	struct Vec names;
	int rc = 0;

	dp = opendir(full_dir);
	if (!dp) {
		fprintf(stderr, "satan: %s:%d: cannot open %s: %s\n",
			hf, line, full_dir, strerror(errno));
		return -1;
	}
	vec_init(&names);
	while ((de = readdir(dp)) != NULL) {
		if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
			continue;
		vec_push(&names, xstrdup(de->d_name));
	}
	closedir(dp);
	if (names.len)
		qsort(names.v, names.len, sizeof(char *), cmp_str_ptr);
	for (size_t i = 0; i < names.len; i++) {
		char *name = vec_get(&names, i);
		char *full = path_join(full_dir, name);
		char *relpath = rel && *rel ? path_join(rel, name) : xstrdup(name);
		struct stat st;
		if (stat(full, &st) != 0) {
			fprintf(stderr, "satan: %s:%d: cannot stat %s: %s\n",
				hf, line, full, strerror(errno));
			free(full);
			free(relpath);
			continue;
		}
		if (S_ISDIR(st.st_mode)) {
			if (hell_walk_dir(d, full, relpath, dst, hf, line) != 0)
				rc = -1;
		} else if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
			char *src_rel = src_rel_from_full(d, full);
			char *dst_path = path_join(dst, relpath);
			hell_add_install(d, src_rel, dst_path, 0644);
			free(src_rel);
			free(dst_path);
		}
		free(full);
		free(relpath);
	}
	vec_free(&names, free);
	return rc;
}

static int hell_install_dir(struct Dir *d, const char *src, const char *dst,
	const char *hf, int line)
{
	char *full;
	int rc;

	full = path_is_abs(src) ? xstrdup(src) : path_join(d->path, src);
	if (!path_is_dir(full)) {
		fprintf(stderr, "satan: %s:%d: not a directory: %s\n", hf, line, src);
		free(full);
		return -1;
	}
	rc = hell_walk_dir(d, full, "", dst, hf, line);
	free(full);
	return rc;
}

static int hell_install_glob(struct Dir *d, const char *pat, const char *dst,
	const char *hf, int line)
{
	glob_t g;
	char *fullpat;
	int rc;
	char *dst_dir;

	fullpat = path_is_abs(pat) ? xstrdup(pat) : path_join(d->path, pat);
	memset(&g, 0, sizeof(g));
	rc = glob(fullpat, GLOB_NOSORT, NULL, &g);
	if (rc == GLOB_NOMATCH) {
		fprintf(stderr, "satan: %s:%d: no matches for %s\n", hf, line, pat);
		free(fullpat);
		globfree(&g);
		return 0;
	}
	if (rc != 0) {
		fprintf(stderr, "satan: %s:%d: glob failed for %s\n", hf, line, pat);
		free(fullpat);
		globfree(&g);
		return -1;
	}
	if (g.gl_pathc)
		qsort(g.gl_pathv, g.gl_pathc, sizeof(char *), cmp_str_ptr);
	dst_dir = ensure_trailing_slash(dst);
	for (size_t i = 0; i < g.gl_pathc; i++) {
		char *p = g.gl_pathv[i];
		struct stat st;
		if (stat(p, &st) != 0)
			continue;
		if (!(S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)))
			continue;
		{
			char *src_rel = src_rel_from_full(d, p);
			hell_add_install(d, src_rel, dst_dir, 0644);
			free(src_rel);
		}
	}
	free(dst_dir);
	globfree(&g);
	free(fullpat);
	return 0;
}

static int hell_install_file(struct Dir *d, const char *src, const char *dst,
	const char *hf, int line)
{
	char *full;
	char *src_rel;
	int exists;

	full = path_is_abs(src) ? xstrdup(src) : path_join(d->path, src);
	exists = (access(full, R_OK) == 0);
	src_rel = src_rel_from_full(d, full);
	if (!exists && !find_gen(d, src_rel)) {
		fprintf(stderr, "satan: %s:%d: missing file %s\n", hf, line, src);
	}
	hell_add_install(d, src_rel, dst, 0644);
	free(full);
	free(src_rel);
	return 0;
}

static int parse_hell_line(struct Dir *d, const char *line, const char *path, int lineno)
{
	int err = 0;
	char *exp;
	struct Vec words;
	char *cmd;
	const char *op;
	const char *src;
	const char *dst;
	char *src_full;
	int is_dir;

	exp = expand_vars(d, line, NULL, NULL, 0, &err);
	if (err) {
		free(exp);
		return -1;
	}
	split_words(&words, exp);
	free(exp);
	if (words.len == 0) {
		vec_free(&words, free);
		return 0;
	}
	cmd = vec_get(&words, 0);
	if (!starts_with(cmd, "hell.")) {
		vec_free(&words, free);
		return 0;
	}
	op = cmd + 5;
	if (words.len < 3) {
		fprintf(stderr, "satan: %s:%d: expected 'hell.%s <src> <dest>'\n",
			path, lineno, op);
		vec_free(&words, free);
		return -1;
	}
	src = vec_get(&words, 1);
	dst = vec_get(&words, 2);
	if (strcmp(op, "install_dir") == 0) {
		hell_install_dir(d, src, dst, path, lineno);
	} else if (strcmp(op, "install_glob") == 0) {
		hell_install_glob(d, src, dst, path, lineno);
	} else if (strcmp(op, "install") == 0) {
		if (has_glob_chars(src)) {
			hell_install_glob(d, src, dst, path, lineno);
		} else {
			src_full = path_is_abs(src) ? xstrdup(src) : path_join(d->path, src);
			is_dir = path_is_dir(src_full);
			free(src_full);
			if (is_dir)
				hell_install_dir(d, src, dst, path, lineno);
			else
				hell_install_file(d, src, dst, path, lineno);
		}
	} else {
		fprintf(stderr, "satan: %s:%d: unknown command %s\n", path, lineno, cmd);
	}
	vec_free(&words, free);
	return 0;
}

static int collect_targets(struct GenCtx *g, struct Dir *d)
{
	const char *vars[] = {
		"bin_PROGRAMS",
		"sbin_PROGRAMS",
		"libexec_PROGRAMS",
		"noinst_PROGRAMS",
		"lib_LIBRARIES",
		"noinst_LIBRARIES",
		"lib_LTLIBRARIES",
		"noinst_LTLIBRARIES"
	};
	int types[] = {TGT_PROG, TGT_PROG, TGT_PROG, TGT_PROG, TGT_LIB, TGT_LIB, TGT_LIB, TGT_LIB};
	int insts[] = {INST_BIN, INST_SBIN, INST_LIBEXEC, INST_NONE, INST_LIB, INST_NONE, INST_LIB, INST_NONE};

	for (size_t vi = 0; vi < sizeof(vars) / sizeof(vars[0]); vi++) {
		char *list;
		struct Vec words;
		int err = 0;

		list = am_var_get(&d->am, vars[vi], &err);
		if (err)
			return -1;
		if (!list || !*list) {
			free(list);
			continue;
		}
		split_words(&words, list);
		free(list);
		for (size_t i = 0; i < words.len; i++) {
			char *name = vec_get(&words, i);
			struct Target *t;
			char *stem, *srcs, *cpp, *ldflags, *ldadd;
			struct Vec srcv;
			struct Vec implibs;

			t = xmalloc(sizeof(*t));
			memset(t, 0, sizeof(*t));
			vec_init(&t->srcs);
			vec_init(&t->implibs);
			t->type = types[vi];
			t->inst = insts[vi];
			t->orig = xstrdup(name);
			if (ends_with(name, ".la"))
				t->name = replace_suffix(name, ".la", ".a");
			else
				t->name = xstrdup(name);
			stem = stem_from_target(name);
			t->stem = xstrdup(stem);

			{
				struct Str vn;
				char *key;
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_SOURCES");
				key = str_finish(&vn);
				srcs = am_var_get(&d->am, key, &err);
				free(key);
			}
			if (err) {
				free(stem);
				free(srcs);
				free(t->orig);
				free(t->name);
				free(t->stem);
				free(t);
				return -1;
			}
			if (!srcs || !*srcs) {
				if (t->type == TGT_PROG) {
					char *cand = xmalloc(strlen(t->orig) + 3);
					char *full;
					sprintf(cand, "%s.c", t->orig);
					full = path_join(d->path, cand);
					if (access(full, R_OK) == 0) {
						free(srcs);
						srcs = cand;
					} else {
						fprintf(stderr, "satan: %s: missing %s_SOURCES\n", d->path, stem);
						free(cand);
						free(full);
						free(stem);
						free(srcs);
						free(t->orig);
						free(t->name);
						free(t->stem);
						free(t);
						return -1;
					}
					free(full);
				} else {
					fprintf(stderr, "satan: %s: missing %s_SOURCES\n", d->path, stem);
					free(stem);
					free(srcs);
					free(t->orig);
					free(t->name);
					free(t->stem);
					free(t);
					return -1;
				}
			}
			split_words(&srcv, srcs);
			free(srcs);
			for (size_t si = 0; si < srcv.len; si++) {
				char *s = vec_get(&srcv, si);
				char *norm = normalize_src_token(d, s);
				if (norm)
					s = norm;
				if (is_c_src(s)) {
					vec_push(&t->srcs, xstrdup(s));
					add_gen_src(d, s);
					free(norm);
					continue;
				}
				if (is_cxx_src(s)) {
					t->has_cxx = 1;
					vec_push(&t->srcs, xstrdup(s));
					add_gen_src(d, s);
					free(norm);
					continue;
				}
				if (is_lex_src(s)) {
					add_lex_src(d, t, s);
					free(norm);
					continue;
				}
				if (is_yacc_src(s)) {
					add_yacc_src(d, t, s);
					free(norm);
					continue;
				}
				if (ends_with(s, ".h")) {
					free(norm);
					continue;
				}
				fprintf(stderr, "satan: %s: unsupported source %s for %s\n", d->path, s, t->name);
				free(norm);
				vec_free(&srcv, free);
				free(stem);
				tgt_free(t);
				return -1;
			}
			vec_free(&srcv, free);
			if (t->srcs.len == 0) {
				if (t->type == TGT_LIB) {
					fprintf(stderr, "satan: warning: %s: no C sources for %s\n", d->path, t->name);
				} else {
					fprintf(stderr, "satan: %s: no C sources for %s\n", d->path, t->name);
					free(stem);
					tgt_free(t);
					return -1;
				}
			}
			if (t->type == TGT_LIB) {
				char *lt = am_var_get(&d->am, "LTLIBOBJS", &err);
				if (!err && lt && *lt)
					add_repl_sources(d, t, lt);
				free(lt);
				err = 0;
				lt = am_var_get(&d->am, "LIBOBJS", &err);
				if (!err && lt && *lt)
					add_repl_sources(d, t, lt);
				free(lt);
				/* add probed replacement sources */
				for (size_t j = 0; j < g->replace_srcs.len; j++) {
					char *src = vec_get(&g->replace_srcs, j);
					if (src && !src_in_vec(&t->srcs, src)) {
						char *full = path_join(d->path, src);
						if (access(full, R_OK) == 0) {
							vec_push(&t->srcs, xstrdup(src));
						}
						free(full);
					}
				}
			}

			{
				struct Str vn;
				char *key;
				char *am_cpp, *t_cpp, *am_c, *t_c, *am_cxx, *t_cxx, *am_as, *t_as, *am_ld, *t_ld;
				char *inc;
				char *extra_cpp, *extra_c, *extra_cxx, *extra_as, *extra_ld, *extra_libs;
				char *cfg_cpp, *cfg_c, *cfg_cxx, *cfg_cxxcpp, *cfg_as, *cfg_ld;
				char *idir;

				am_cpp = am_var_get(&d->am, "AM_CPPFLAGS", &err);
				am_c = am_var_get(&d->am, "AM_CFLAGS", &err);
				am_cxx = am_var_get(&d->am, "AM_CXXFLAGS", &err);
				am_as = am_var_get(&d->am, "AM_ASFLAGS", &err);
				am_ld = am_var_get(&d->am, "AM_LDFLAGS", &err);
				inc = am_var_get(&d->am, "INCLUDES", &err);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_CPPFLAGS");
				key = str_finish(&vn);
				t_cpp = am_var_get(&d->am, key, &err);
				free(key);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_CFLAGS");
				key = str_finish(&vn);
				t_c = am_var_get(&d->am, key, &err);
				free(key);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_CXXFLAGS");
				key = str_finish(&vn);
				t_cxx = am_var_get(&d->am, key, &err);
				free(key);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_ASFLAGS");
				key = str_finish(&vn);
				t_as = am_var_get(&d->am, key, &err);
				free(key);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_LDFLAGS");
				key = str_finish(&vn);
				t_ld = am_var_get(&d->am, key, &err);
				free(key);

				if (err) {
					free(am_cpp);
					free(am_c);
					free(am_cxx);
					free(am_as);
					free(am_ld);
					free(inc);
					free(t_cpp);
					free(t_c);
					free(t_cxx);
					free(t_as);
					free(t_ld);
					free(stem);
					tgt_free(t);
					return -1;
				}
				if (inc && *inc) {
					char *joined = str_join_space(am_cpp, inc);
					free(am_cpp);
					am_cpp = joined;
				}
				free(inc);

				cfg_cpp = (char *)conf_get(g->conf, "CPPFLAGS");
				cfg_c = (char *)conf_get(g->conf, "CFLAGS");
				cfg_cxx = (char *)conf_get(g->conf, "CXXFLAGS");
				cfg_cxxcpp = (char *)conf_get(g->conf, "CXXCPPFLAGS");
				cfg_as = (char *)conf_get(g->conf, "ASFLAGS");
				cfg_ld = (char *)conf_get(g->conf, "LDFLAGS");
				extra_cpp = (char *)conf_get(g->conf, "EXTRA_CPPFLAGS");
				extra_c = (char *)conf_get(g->conf, "EXTRA_CFLAGS");
				extra_cxx = (char *)conf_get(g->conf, "EXTRA_CXXFLAGS");
				extra_as = (char *)conf_get(g->conf, "EXTRA_ASFLAGS");
				extra_ld = (char *)conf_get(g->conf, "EXTRA_LDFLAGS");
				extra_libs = (char *)conf_get(g->conf, "EXTRA_LDLIBS");

				/* skip garbage conf values */
				if (cfg_cpp && (!*cfg_cpp || *cfg_cpp < ' ')) cfg_cpp = NULL;
				if (cfg_c && (!*cfg_c || *cfg_c < ' ')) cfg_c = NULL;
				if (cfg_cxx && (!*cfg_cxx || *cfg_cxx < ' ')) cfg_cxx = NULL;
				if (cfg_cxxcpp && (!*cfg_cxxcpp || *cfg_cxxcpp < ' ')) cfg_cxxcpp = NULL;
				if (cfg_as && (!*cfg_as || *cfg_as < ' ')) cfg_as = NULL;
				if (cfg_ld && (!*cfg_ld || *cfg_ld < ' ')) cfg_ld = NULL;
				if (extra_cpp && (!*extra_cpp || *extra_cpp < ' ')) extra_cpp = NULL;
				if (extra_c && (!*extra_c || *extra_c < ' ')) extra_c = NULL;
				if (extra_cxx && (!*extra_cxx || *extra_cxx < ' ')) extra_cxx = NULL;
				if (extra_as && (!*extra_as || *extra_as < ' ')) extra_as = NULL;
				if (extra_ld && (!*extra_ld || *extra_ld < ' ')) extra_ld = NULL;
				if (extra_libs && (!*extra_libs || *extra_libs < ' ')) extra_libs = NULL;
				if (cfg_cpp && str_has_bad_chars(cfg_cpp)) {
					warn_once(g, "dropping CPPFLAGS with non-printable chars");
					cfg_cpp = NULL;
				}
				if (cfg_c && str_has_bad_chars(cfg_c)) {
					warn_once(g, "dropping CFLAGS with non-printable chars");
					cfg_c = NULL;
				}
				if (cfg_cxx && str_has_bad_chars(cfg_cxx)) {
					warn_once(g, "dropping CXXFLAGS with non-printable chars");
					cfg_cxx = NULL;
				}
				if (cfg_cxxcpp && str_has_bad_chars(cfg_cxxcpp)) {
					warn_once(g, "dropping CXXCPPFLAGS with non-printable chars");
					cfg_cxxcpp = NULL;
				}
				if (cfg_as && str_has_bad_chars(cfg_as)) {
					warn_once(g, "dropping ASFLAGS with non-printable chars");
					cfg_as = NULL;
				}
				if (cfg_ld && str_has_bad_chars(cfg_ld)) {
					warn_once(g, "dropping LDFLAGS with non-printable chars");
					cfg_ld = NULL;
				}
				if (extra_cpp && str_has_bad_chars(extra_cpp)) {
					warn_once(g, "dropping EXTRA_CPPFLAGS with non-printable chars");
					extra_cpp = NULL;
				}
				if (extra_c && str_has_bad_chars(extra_c)) {
					warn_once(g, "dropping EXTRA_CFLAGS with non-printable chars");
					extra_c = NULL;
				}
				if (extra_cxx && str_has_bad_chars(extra_cxx)) {
					warn_once(g, "dropping EXTRA_CXXFLAGS with non-printable chars");
					extra_cxx = NULL;
				}
				if (extra_as && str_has_bad_chars(extra_as)) {
					warn_once(g, "dropping EXTRA_ASFLAGS with non-printable chars");
					extra_as = NULL;
				}
				if (extra_ld && str_has_bad_chars(extra_ld)) {
					warn_once(g, "dropping EXTRA_LDFLAGS with non-printable chars");
					extra_ld = NULL;
				}
				if (extra_libs && str_has_bad_chars(extra_libs)) {
					warn_once(g, "dropping EXTRA_LDLIBS with non-printable chars");
					extra_libs = NULL;
				}

				if (d->rel && *d->rel) {
					struct Str ib;
					str_init(&ib);
					str_add(&ib, "-I. -I");
					str_add(&ib, d->rel);
					idir = str_finish(&ib);
				} else {
					idir = xstrdup("-I.");
				}
				{
					char *tmp = join_flags(cfg_cpp, idir, am_cpp, t_cpp, extra_cpp);
					t->cppflags = filter_flags(tmp);
					free(tmp);
				}
				if (g->conf->pkg_cflags) {
					char *tmp = str_join_space(t->cppflags, g->conf->pkg_cflags);
					free(t->cppflags);
					t->cppflags = filter_flags(tmp);
					free(tmp);
				}
				if (g->have_config_h && !flag_has(t->cppflags, "-DHAVE_CONFIG_H")) {
					char *tmp = str_join_space(t->cppflags, "-DHAVE_CONFIG_H");
					free(t->cppflags);
					t->cppflags = filter_flags(tmp);
					free(tmp);
				}
				if (t->has_cxx && cfg_cxxcpp) {
					char *tmp = str_join_space(t->cppflags, cfg_cxxcpp);
					free(t->cppflags);
					t->cppflags = filter_flags(tmp);
					free(tmp);
				}
				free(idir);
				{
					char *tmp = join_flags(cfg_c, am_c, t_c, extra_c, NULL);
					t->cflags = filter_flags(tmp);
					free(tmp);
				}
				{
					char *tmp = join_flags(cfg_cxx, am_cxx, t_cxx, extra_cxx, NULL);
					t->cxxflags = filter_flags(tmp);
					free(tmp);
				}
				{
					char *tmp = join_flags(cfg_as, am_as, t_as, extra_as, NULL);
					t->asflags = filter_flags(tmp);
					free(tmp);
				}
				{
					char *tmp = join_flags(cfg_ld, am_ld, t_ld, extra_ld, NULL);
					ldflags = filter_flags(tmp);
					free(tmp);
				}
				t->ldflags = filter_ldflags(g, ldflags);
				free(ldflags);

				ldadd = am_var_get(&d->am, "LDADD", &err);
				str_init(&vn);
				str_add(&vn, stem);
				str_add(&vn, "_LDADD");
				key = str_finish(&vn);
				cpp = am_var_get(&d->am, key, &err);
				free(key);
				if (err) {
					free(ldadd);
					free(cpp);
					free(am_cpp);
					free(am_c);
					free(am_cxx);
					free(am_as);
					free(am_ld);
					free(t_cpp);
					free(t_c);
					free(t_cxx);
					free(t_as);
					free(t_ld);
					free(stem);
					tgt_free(t);
					return -1;
				}

				{
					char *libs_join = join_flags(ldadd, cpp, extra_libs, g->conf->pkg_libs, NULL);
					free(ldadd);
					free(cpp);
					t->libs = normalize_libs(g, libs_join, d->rel, &implibs);
					free(libs_join);
				}

				t->implibs = implibs;
				free(am_cpp);
				free(am_c);
				free(am_cxx);
				free(am_as);
				free(am_ld);
				free(t_cpp);
				free(t_c);
				free(t_cxx);
				free(t_as);
				free(t_ld);
			}

			free(stem);
			vec_push(&d->targets, t);
		}
		vec_free(&words, free);
	}

	{
		int err = 0;
		char *hdrs = am_var_get(&d->am, "include_HEADERS", &err);
		struct Vec words;
		if (!err && hdrs && *hdrs) {
			split_words(&words, hdrs);
			for (size_t i = 0; i < words.len; i++) {
				vec_push(&d->headers, xstrdup(vec_get(&words, i)));
			}
			vec_free(&words, free);
		}
		free(hdrs);
		err = 0;
		hdrs = am_var_get(&d->am, "nobase_include_HEADERS", &err);
		if (!err && hdrs && *hdrs) {
			split_words(&words, hdrs);
			for (size_t i = 0; i < words.len; i++) {
				vec_push(&d->headers, xstrdup(vec_get(&words, i)));
			}
			vec_free(&words, free);
		}
		free(hdrs);
	}

	/* parse _DATA variables */
	{
		static const struct { const char *var; const char *dir; } data_vars[] = {
			{ "pkgdata_DATA", "$PKGDATADIR" },
			{ "data_DATA", "$DATADIR" },
			{ "sysconf_DATA", "$SYSCONFDIR" },
			{ "pkgconfigexec_DATA", "$PKGCONFIGEXECDIR" },
			{ "pkgconfig_DATA", "$PKGCONFIGDIR" },
			{ NULL, NULL }
		};
		for (size_t vi = 0; data_vars[vi].var; vi++) {
			int err = 0;
			char *files = am_var_get(&d->am, data_vars[vi].var, &err);
			struct Vec words;
			if (!err && files && *files) {
				split_words(&words, files);
				for (size_t i = 0; i < words.len; i++) {
					struct DataItem *di = xmalloc(sizeof(*di));
					di->file = xstrdup(vec_get(&words, i));
					di->dir = xstrdup(data_vars[vi].dir);
					vec_push(&d->data, di);
				}
				vec_free(&words, free);
			}
			free(files);
		}
	}

	{
		int err = 0;
		char *built = am_var_get(&d->am, "BUILT_SOURCES", &err);
		struct Vec words;
		if (!err && built && *built) {
			split_words(&words, built);
			for (size_t i = 0; i < words.len; i++) {
				char *b = vec_get(&words, i);
				if (find_gen(d, b)) {
					vec_push(&d->built, xstrdup(b));
				} else {
					char *full = path_join(d->path, b);
					if (access(full, R_OK) == 0) {
						free(full);
						continue;
					}
					free(full);
					fprintf(stderr, "satan: %s: missing rule for %s\n", d->path, b);
				}
			}
			vec_free(&words, free);
		}
		free(built);
	}
	return 0;
}

static int parse_makefile(struct GenCtx *g, const char *root, const char *rel)
{
	struct Dir *d;
	char *dirpath, *mf, *key, *src;
	int err;

	key = rel && *rel ? xstrdup(rel) : xstrdup(".");
	if (map_has(&g->seen_dirs, key)) {
		free(key);
		return 0;
	}
	map_set(&g->seen_dirs, key, (void *)1);
	free(key);

	d = xmalloc(sizeof(*d));
	memset(d, 0, sizeof(*d));
	vec_init(&d->subdirs);
	vec_init(&d->targets);
	vec_init(&d->gens);
	vec_init(&d->built);
	vec_init(&d->headers);
	vec_init(&d->data);
	vec_init(&d->hell_installs);
	am_ctx_init(&d->am, g->conf);
	d->rel = xstrdup(rel ? rel : "");
	dirpath = rel && *rel ? path_join(root, rel) : xstrdup(root);
	d->path = xstrdup(dirpath);

	{
		const char *prefix = conf_pick(g->conf, "prefix", "PREFIX");
		const char *bindir = conf_pick(g->conf, "bindir", "BINDIR");
		const char *libexecdir = conf_pick(g->conf, "libexecdir", "LIBEXECDIR");
		const char *libdir = conf_pick(g->conf, "libdir", "LIBDIR");
		const char *includedir = conf_pick(g->conf, "includedir", "INCLUDEDIR");
		const char *mandir = conf_pick(g->conf, "mandir", "MANDIR");
		const char *pkgconfdir = conf_pick(g->conf, "pkgconfigdir", "PKGCONFIGDIR");
		const char *datadir = conf_pick(g->conf, "datadir", "DATADIR");
		const char *pkgdatadir = conf_pick(g->conf, "pkgdatadir", "PKGDATADIR");
		const char *sysconfdir = conf_pick(g->conf, "sysconfdir", "SYSCONFDIR");
		char datadir_buf[512];
		char pkgdatadir_buf[512];

		if (!prefix || !*prefix)
			prefix = "/usr";
		if (!datadir || !*datadir) {
			snprintf(datadir_buf, sizeof(datadir_buf), "%s/share", prefix);
			datadir = datadir_buf;
		}
		if (!pkgdatadir || !*pkgdatadir) {
			const char *pkg = conf_pick(g->conf, "package", "PACKAGE");
			if (!pkg || !*pkg)
				pkg = "unknown";
			snprintf(pkgdatadir_buf, sizeof(pkgdatadir_buf), "%s/%s", datadir, pkg);
			pkgdatadir = pkgdatadir_buf;
		}
		if (!sysconfdir || !*sysconfdir)
			sysconfdir = "/etc";

		am_var_set(&d->am, "prefix", prefix);
		am_var_set(&d->am, "bindir", bindir);
		am_var_set(&d->am, "libexecdir", libexecdir);
		am_var_set(&d->am, "libdir", libdir);
		am_var_set(&d->am, "includedir", includedir);
		am_var_set(&d->am, "mandir", mandir);
		am_var_set(&d->am, "pkgconfigdir", pkgconfdir);
		am_var_set(&d->am, "datadir", datadir);
		am_var_set(&d->am, "pkgdatadir", pkgdatadir);
		am_var_set(&d->am, "sysconfdir", sysconfdir);
	}
	{
		const char *cc = conf_get(g->conf, "CC");
		const char *cpp = conf_get(g->conf, "CPP");
		if (!cc || !*cc)
			cc = "clang";
		am_var_set(&d->am, "CC", cc);
		if (!cpp || !*cpp) {
			char *tmp = str_join_space(cc, "-E");
			am_var_set(&d->am, "CPP", tmp);
			free(tmp);
		} else {
			am_var_set(&d->am, "CPP", cpp);
		}
	}
	am_var_set(&d->am, "AWK", "awk");
	am_var_set(&d->am, "MKDIR_P", "mkdir -p");
	am_var_set(&d->am, "MAKE", "make");
	am_var_set(&d->am, "RM", "rm -f");
	am_var_set(&d->am, "SED", "sed");
	am_var_set(&d->am, "AM_MAKEFLAGS", "");
	am_var_set(&d->am, "PYTHON", "python3");
	am_var_set(&d->am, "GPERF", "gperf");
	am_var_set(&d->am, "LEX", "lex");
	am_var_set(&d->am, "YACC", "yacc");
	am_var_set(&d->am, "srcdir", ".");
	am_var_set(&d->am, "builddir", ".");
	{
		char *up = rel && *rel ? rel_up(rel) : xstrdup(".");
		am_var_set(&d->am, "top_srcdir", up);
		am_var_set(&d->am, "top_builddir", up);
		free(up);
	}
	{
		const char *cc = conf_get(g->conf, "CC");
		const char *ar = conf_get(g->conf, "AR");
		const char *ranlib = conf_get(g->conf, "RANLIB");
		const char *lex = conf_get(g->conf, "LEX");
		const char *yacc = conf_get(g->conf, "YACC");
		const char *cflags = conf_get(g->conf, "CFLAGS");
		const char *cppflags = conf_get(g->conf, "CPPFLAGS");
		const char *ldflags = conf_get(g->conf, "LDFLAGS");
		const char *prefix = conf_pick(g->conf, "prefix", "PREFIX");
		const char *bindir = conf_pick(g->conf, "bindir", "BINDIR");
		const char *libexecdir = conf_pick(g->conf, "libexecdir", "LIBEXECDIR");
		const char *libdir = conf_pick(g->conf, "libdir", "LIBDIR");
		const char *includedir = conf_pick(g->conf, "includedir", "INCLUDEDIR");
		const char *mandir = conf_pick(g->conf, "mandir", "MANDIR");
		const char *pkgconfdir = conf_pick(g->conf, "pkgconfigdir", "PKGCONFIGDIR");
		const char *datadir = conf_pick(g->conf, "datadir", "DATADIR");
		const char *pkgdatadir = conf_pick(g->conf, "pkgdatadir", "PKGDATADIR");
		const char *sysconfdir = conf_pick(g->conf, "sysconfdir", "SYSCONFDIR");

		if (cc)
			am_var_set(&d->am, "CC", cc);
		if (ar)
			am_var_set(&d->am, "AR", ar);
		if (ranlib)
			am_var_set(&d->am, "RANLIB", ranlib);
		if (lex && *lex)
			am_var_set(&d->am, "LEX", lex);
		if (yacc && *yacc)
			am_var_set(&d->am, "YACC", yacc);
		if (cflags)
			am_var_set(&d->am, "CFLAGS", cflags);
		if (cppflags)
			am_var_set(&d->am, "CPPFLAGS", cppflags);
		if (ldflags)
			am_var_set(&d->am, "LDFLAGS", ldflags);
		if (prefix)
			am_var_set(&d->am, "prefix", prefix);
		if (bindir)
			am_var_set(&d->am, "bindir", bindir);
		if (libexecdir)
			am_var_set(&d->am, "libexecdir", libexecdir);
		if (libdir)
			am_var_set(&d->am, "libdir", libdir);
		if (includedir)
			am_var_set(&d->am, "includedir", includedir);
		if (mandir)
			am_var_set(&d->am, "mandir", mandir);
		if (pkgconfdir)
			am_var_set(&d->am, "pkgconfigdir", pkgconfdir);
		if (datadir)
			am_var_set(&d->am, "datadir", datadir);
		if (pkgdatadir)
			am_var_set(&d->am, "pkgdatadir", pkgdatadir);
		if (sysconfdir)
			am_var_set(&d->am, "sysconfdir", sysconfdir);
	}
	if (conf_get(g->conf, "LTLIBOBJS"))
		am_var_set(&d->am, "LTLIBOBJS", conf_get(g->conf, "LTLIBOBJS"));
	if (conf_get(g->conf, "LIBOBJS"))
		am_var_set(&d->am, "LIBOBJS", conf_get(g->conf, "LIBOBJS"));

	map_iter(&g->conf->kv, var_from_conf, &d->am);
	map_iter(&g->conds, cond_set_cb, &d->am);

	mf = path_join(dirpath, "Makefile.am");
	if (access(mf, R_OK) != 0 && errno == ENOENT) {
		char *alt = NULL;
		free(mf);
		mf = NULL;
		alt = path_join(dirpath, "hellfile");
		if (access(alt, R_OK) != 0) {
			free(alt);
			alt = path_join(dirpath, "Hellfile");
			if (access(alt, R_OK) != 0) {
				free(alt);
				alt = NULL;
			}
		}
		mf = alt;
	}
	if (!mf || access(mf, R_OK) != 0) {
		if (rel && *rel && errno == ENOENT) {
			fprintf(stderr, "satan: warning: %s: missing, skipping\n",
				mf ? mf : "Makefile.am");
			d->am.err = 1;
			free(mf);
			free(dirpath);
			dir_free(d);
			return 1;
		}
		fprintf(stderr, "satan: %s: %s\n", mf ? mf : "Makefile.am", strerror(errno));
		d->am.err = 1;
		free(mf);
		free(dirpath);
		dir_free(d);
		return -1;
	}
	if (am_parse_file(&d->am, mf) != 0) {
		write_stub(root, &d->am);
		d->am.err = 1;
		free(mf);
		free(dirpath);
		dir_free(d);
		return -1;
	}
	if (scan_rules(d, mf) != 0) {
		fprintf(stderr, "satan: %s: unable to scan rules\n", mf);
		write_stub(root, &d->am);
		d->am.err = 1;
		free(mf);
		free(dirpath);
		dir_free(d);
		return -1;
	}
	free(mf);
	free(dirpath);

	{
		const char *relpath = d->rel && *d->rel ? d->rel : ".";
		am_var_set(&d->am, "srcdir", relpath);
		am_var_set(&d->am, "builddir", relpath);
		am_var_set(&d->am, "top_srcdir", ".");
		am_var_set(&d->am, "top_builddir", ".");
	}

	vec_push(&g->dirs, d);

	if (collect_targets(g, d) != 0) {
		write_stub(root, &d->am);
		d->am.err = 1;
		return -1;
	}

	err = 0;
	src = am_var_get(&d->am, "SUBDIRS", &err);
	if (!err && src && *src) {
		struct Vec words;
		split_words(&words, src);
		for (size_t i = 0; i < words.len; i++) {
			char *sub = vec_get(&words, i);
			if (!*sub || strcmp(sub, ".") == 0)
				continue;
			{
				char *child_rel;
				int rc;
				if (rel && *rel)
					child_rel = path_join(rel, sub);
				else
					child_rel = xstrdup(sub);
				rc = parse_makefile(g, root, child_rel);
				if (rc < 0) {
					free(child_rel);
					vec_free(&words, free);
					free(src);
					return -1;
				}
				if (rc == 0)
					vec_push(&d->subdirs, xstrdup(sub));
				free(child_rel);
			}
		}
		vec_free(&words, free);
	}
	free(src);
	return 0;
}

static char *path_rel(const char *rel, const char *name)
{
	if (!rel || !*rel) {
		struct Str out;
		str_init(&out);
		str_add(&out, "./");
		str_add(&out, name);
		return str_finish(&out);
	}
	{
		char *base = path_join("./", rel);
		char *out = path_join(base, name);
		free(base);
		return out;
	}
}

static void add_install(struct GenCtx *g, const char *src, const char *dst, int mode)
{
	struct InstItem *it;

	it = xmalloc(sizeof(*it));
	it->src = xstrdup(src);
	it->dst = xstrdup(dst);
	it->mode = mode;
	vec_push(&g->installs, it);
}

static int gather_installs(struct GenCtx *g)
{
	for (size_t di = 0; di < g->dirs.len; di++) {
		struct Dir *d = vec_get(&g->dirs, di);
		for (size_t ti = 0; ti < d->targets.len; ti++) {
			struct Target *t = vec_get(&d->targets, ti);
			char *src;
			if (t->inst == INST_NONE)
				continue;
			src = path_rel(d->rel, t->name);
			if (t->inst == INST_BIN)
				add_install(g, src, "$BINDIR/", 0755);
			else if (t->inst == INST_SBIN)
				add_install(g, src, "$SBINDIR/", 0755);
			else if (t->inst == INST_LIBEXEC)
				add_install(g, src, "$LIBEXECDIR/", 0755);
			else if (t->inst == INST_LIB)
				add_install(g, src, "$LIBDIR/", 0644);
			free(src);
		}
		for (size_t hi = 0; hi < d->headers.len; hi++) {
			char *h = vec_get(&d->headers, hi);
			char *src = path_rel(d->rel, h);
			struct Str dst;
			str_init(&dst);
			str_add(&dst, "$INCLUDEDIR/");
			str_add(&dst, h);
			add_install(g, src, str_finish(&dst), 0644);
			free(src);
		}
		for (size_t dti = 0; dti < d->data.len; dti++) {
			struct DataItem *di = vec_get(&d->data, dti);
			char *src = path_rel(d->rel, di->file);
			struct Str dst;
			str_init(&dst);
			str_add(&dst, di->dir);
			str_add(&dst, "/");
			str_add(&dst, di->file);
			add_install(g, src, str_finish(&dst), 0644);
			free(src);
		}
		for (size_t hi = 0; hi < d->hell_installs.len; hi++) {
			struct HellInstall *item = vec_get(&d->hell_installs, hi);
			char *src = path_rel(d->rel, item->src);
			add_install(g, src, item->dst, item->mode);
			free(src);
		}
	}
	return 0;
}

static size_t count_built_sources(struct GenCtx *g)
{
	size_t total = 0;

	for (size_t i = 0; i < g->dirs.len; i++) {
		struct Dir *d = vec_get(&g->dirs, i);
		for (size_t j = 0; j < d->built.len; j++) {
			char *b = vec_get(&d->built, j);
			struct GenRule *r = find_gen(d, b);
			if (r && r->cmd)
				total++;
		}
	}
	return total;
}

static char *obj_path(const char *rel, const char *src)
{
	char *objdir, *full, *oname;

	objdir = xstrdup("obj");
	if (rel && *rel) {
		char *tmp = path_join(objdir, rel);
		free(objdir);
		objdir = tmp;
	}
	oname = obj_name(src);
	full = path_join(objdir, oname);
	free(objdir);
	free(oname);
	return full;
}

static int emit_dir_build(struct GenCtx *g, struct Dir *d, int root)
{
	char *bn;
	FILE *f;
	char *built_list;

	bn = path_join(d->path, "build.ninja");
	f = fopen(bn, "w");
	if (!f) {
		fprintf(stderr, "satan: %s: %s\n", bn, strerror(errno));
		free(bn);
		return -1;
	}
		if (root) {
			const char *cc = conf_get(g->conf, "CC");
			const char *ar = conf_get(g->conf, "AR");
			const char *ranlib = conf_get(g->conf, "RANLIB");
			int fully = conf_get_int(g->conf, "FULLY_STATIC", 1);

			{
				const char *cxx = conf_get(g->conf, "CXX");
				fprintf(f, "rule cc\n");
				fprintf(f, "  command = mkdir -p $$(dirname $out) && %s $cppflags $cflags $asflags -MMD -MF $out.d -c $in -o $out\n", cc ? cc : "clang");
				fprintf(f, "  description = cc $out\n");
				fprintf(f, "  depfile = $out.d\n");
				fprintf(f, "  deps = gcc\n\n");
				fprintf(f, "rule cxx\n");
				fprintf(f, "  command = mkdir -p $$(dirname $out) && %s $cppflags $cxxflags -MMD -MF $out.d -c $in -o $out\n", cxx ? cxx : "c++");
				fprintf(f, "  description = cxx $out\n");
				fprintf(f, "  depfile = $out.d\n");
				fprintf(f, "  deps = gcc\n\n");
			}
		fprintf(f, "rule ar\n");
		if (ranlib && *ranlib)
			fprintf(f, "  command = %s rcs $out $in && %s $out\n", ar ? ar : "ar", ranlib);
		else
			fprintf(f, "  command = %s rcs $out $in\n", ar ? ar : "ar");
		fprintf(f, "  description = ar $out\n\n");
		fprintf(f, "rule link\n");
		fprintf(f, "  command = %s $in -o $out $ldflags $libs%s\n", cc ? cc : "clang", fully ? " -static" : "");
		fprintf(f, "  description = ld $out\n\n");
		{
			const char *cxx = conf_get(g->conf, "CXX");
			fprintf(f, "rule linkcxx\n");
			fprintf(f, "  command = %s $in -o $out $ldflags $libs%s\n", cxx ? cxx : "c++", fully ? " -static" : "");
			fprintf(f, "  description = ld $out\n\n");
		}
		fprintf(f, "rule gen\n");
		fprintf(f, "  command = $cmd\n");
		fprintf(f, "  description = gen $out\n\n");
		fprintf(f, "rule install\n");
		fprintf(f, "  command = mkdir -p $$(dirname $out) && cp -f $in $out && chmod $mode $out\n");
		fprintf(f, "  description = install $in -> $out\n\n");
	}

	for (size_t i = 0; i < d->subdirs.len; i++) {
		char *sub = vec_get(&d->subdirs, i);
		char *base;
		char *path;
		if (d->rel && *d->rel)
			base = path_join(d->rel, sub);
		else
			base = xstrdup(sub);
		path = path_join(base, "build.ninja");
		fprintf(f, "subninja %s\n", path);
		free(path);
		free(base);
	}
	if (d->subdirs.len)
		fprintf(f, "\n");

	built_list = NULL;
	if (d->built.len) {
		struct Str bl;
		str_init(&bl);
		for (size_t i = 0; i < d->built.len; i++) {
			char *b = vec_get(&d->built, i);
			if (skip_stamp(d, b))
				continue;
			char *out = rel_path(d->rel, b);
			if (bl.len)
				str_addc(&bl, ' ');
			str_add(&bl, out);
			free(out);
		}
		built_list = str_finish(&bl);
	}

	{
		struct Map done;
		map_init(&done);
		for (size_t gi = 0; gi < d->gens.len; gi++) {
			struct GenRule *r = vec_get(&d->gens, gi);
			char *out = rel_path(d->rel, r->tgt);
			struct GenRule *pick;
			if (!map_has(&g->need_gen, out)) {
				free(out);
				continue;
			}
			pick = map_get(&g->gen_pick, out);
			if (pick && pick != r) {
				free(out);
				continue;
			}
			free(out);
			if (emit_gen_rule(g, d, f, &done, r->tgt) != 0) {
				map_free(&done, NULL);
				free(built_list);
				fclose(f);
				free(bn);
				return -1;
			}
		}
		map_free(&done, NULL);
	}

	{
		struct Map obj_done;
		map_init(&obj_done);
	for (size_t ti = 0; ti < d->targets.len; ti++) {
		struct Target *t = vec_get(&d->targets, ti);
		struct Str objs;
		struct Vec objv;

		vec_init(&objv);
		str_init(&objs);
		for (size_t si = 0; si < t->srcs.len; si++) {
			char *src = vec_get(&t->srcs, si);
			char *obj = obj_path(d->rel, src);
			char *srcpath = rel_path(d->rel, src);

			if (!map_has(&obj_done, obj)) {
				const char *rule = is_cxx_src(src) ? "cxx" : "cc";
				if (built_list && *built_list)
					fprintf(f, "build %s: %s %s | %s\n", obj, rule, srcpath, built_list);
				else
					fprintf(f, "build %s: %s %s\n", obj, rule, srcpath);
				if (t->cppflags && *t->cppflags)
					fprintf(f, "  cppflags = %s\n", t->cppflags);
				if (!is_cxx_src(src) && t->cflags && *t->cflags)
					fprintf(f, "  cflags = %s\n", t->cflags);
				if (is_cxx_src(src) && t->cxxflags && *t->cxxflags)
					fprintf(f, "  cxxflags = %s\n", t->cxxflags);
				if (is_asm_src(src) && t->asflags && *t->asflags)
					fprintf(f, "  asflags = %s\n", t->asflags);
				fprintf(f, "\n");
				map_set(&obj_done, obj, (void *)1);
			}

			vec_push(&objv, obj);
			free(srcpath);
		}
		for (size_t oi = 0; oi < objv.len; oi++) {
			char *o = vec_get(&objv, oi);
			if (objs.len)
				str_addc(&objs, ' ');
			str_add(&objs, o);
		}

		{
			char *out = rel_path(d->rel, t->name);
			if (t->type == TGT_LIB) {
				fprintf(f, "build %s: ar %s\n\n", out, objs.s ? objs.s : "");
			} else {
				if (t->implibs.len) {
					struct Str deps;
					str_init(&deps);
					for (size_t li = 0; li < t->implibs.len; li++) {
						char *l = vec_get(&t->implibs, li);
						char *dep;
						if (starts_with(l, "./")) {
							dep = xstrdup(l + 2);
						} else if (l[0] == '/') {
							dep = xstrdup(l);
						} else {
							dep = rel_path(d->rel, l);
						}
						if (deps.len)
							str_addc(&deps, ' ');
						str_add(&deps, dep);
						free(dep);
					}
					fprintf(f, "build %s: %s %s | %s\n", out, t->has_cxx ? "linkcxx" : "link",
						objs.s ? objs.s : "", deps.s ? deps.s : "");
					str_free(&deps);
				} else {
					fprintf(f, "build %s: %s %s\n", out, t->has_cxx ? "linkcxx" : "link",
						objs.s ? objs.s : "");
				}
				if (t->ldflags && *t->ldflags)
					fprintf(f, "  ldflags = %s\n", t->ldflags);
				if (t->libs && *t->libs)
					fprintf(f, "  libs = %s\n", t->libs);
				fprintf(f, "\n");
			}
			free(out);
		}

		vec_free(&objv, free);
		str_free(&objs);
	}
		map_free(&obj_done, NULL);
	}
	free(built_list);

	if (!root) {
		struct Str all;
		str_init(&all);
		for (size_t ti = 0; ti < d->targets.len; ti++) {
			struct Target *t = vec_get(&d->targets, ti);
			char *out = rel_path(d->rel, t->name);
			if (all.len)
				str_addc(&all, ' ');
			str_add(&all, out);
			free(out);
		}
		for (size_t di = 0; di < d->subdirs.len; di++) {
			char *sub = vec_get(&d->subdirs, di);
			char *dep = rel_path(d->rel, sub);
			if (all.len)
				str_addc(&all, ' ');
			str_add(&all, dep);
			str_add(&all, "/all");
			free(dep);
		}
		{
			char *allname = rel_path(d->rel, "all");
			fprintf(f, "build %s: phony %s\n", allname, all.s ? all.s : "");
			free(allname);
		}
		str_free(&all);
	}

	fclose(f);
	free(bn);
	return 0;
}

static int emit_root_all(struct GenCtx *g, struct Dir *root)
{
	char *bn;
	FILE *f;
	struct Str all;

	(void)g;
	bn = path_join(root->path, "build.ninja");
	f = fopen(bn, "a");
	if (!f) {
		fprintf(stderr, "satan: %s: %s\n", bn, strerror(errno));
		free(bn);
		return -1;
	}
	str_init(&all);
	for (size_t ti = 0; ti < root->targets.len; ti++) {
		struct Target *t = vec_get(&root->targets, ti);
		if (all.len)
			str_addc(&all, ' ');
		str_add(&all, t->name);
	}
	for (size_t di = 0; di < root->subdirs.len; di++) {
		char *sub = vec_get(&root->subdirs, di);
		if (all.len)
			str_addc(&all, ' ');
		str_add(&all, sub);
		str_add(&all, "/all");
	}
	fprintf(f, "build all: phony %s\n", all.s ? all.s : "");
	fprintf(f, "default all\n");
	str_free(&all);
	fclose(f);
	free(bn);
	return 0;
}

static int emit_install(struct GenCtx *g, const char *root)
{
	char *path;
	FILE *f;
	const char *destdir;
	const char *prefix;
	const char *bindir;
	const char *sbindir;
	const char *libexecdir;
	const char *libdir;
	const char *incdir;
	const char *datadir;
	const char *sysconfdir;
	const char *pkgdatadir;
	const char *pkgconfigdir;
	const char *pkgconfigexecdir;
	struct Str all_installs;

	if (g->installs.len == 0)
		return 0;

	/* get install dirs from config */
	destdir = conf_get(g->conf, "DESTDIR");
	prefix = conf_get(g->conf, "PREFIX");
	if (!prefix || !*prefix)
		prefix = "/usr";

	bindir = conf_get(g->conf, "BINDIR");
	if (!bindir || !*bindir) {
		static char buf1[512];
		snprintf(buf1, sizeof(buf1), "%s/bin", prefix);
		bindir = buf1;
	}

	sbindir = conf_get(g->conf, "SBINDIR");
	if (!sbindir || !*sbindir) {
		static char buf2[512];
		snprintf(buf2, sizeof(buf2), "%s/sbin", prefix);
		sbindir = buf2;
	}

	libdir = conf_get(g->conf, "LIBDIR");
	if (!libdir || !*libdir) {
		static char buf3[512];
		snprintf(buf3, sizeof(buf3), "%s/lib", prefix);
		libdir = buf3;
	}

	libexecdir = conf_get(g->conf, "LIBEXECDIR");
	if (!libexecdir || !*libexecdir) {
		static char buf3b[512];
		snprintf(buf3b, sizeof(buf3b), "%s/libexec", prefix);
		libexecdir = buf3b;
	}

	incdir = conf_get(g->conf, "INCLUDEDIR");
	if (!incdir || !*incdir) {
		static char buf4[512];
		snprintf(buf4, sizeof(buf4), "%s/include", prefix);
		incdir = buf4;
	}

	datadir = conf_get(g->conf, "datadir");
	if (!datadir || !*datadir) {
		static char buf5[512];
		snprintf(buf5, sizeof(buf5), "%s/share", prefix);
		datadir = buf5;
	}

	sysconfdir = conf_get(g->conf, "sysconfdir");
	if (!sysconfdir || !*sysconfdir)
		sysconfdir = "/etc";

	pkgdatadir = conf_get(g->conf, "pkgdatadir");
	if (!pkgdatadir || !*pkgdatadir) {
		static char buf6[512];
		const char *pkg = conf_get(g->conf, "PACKAGE");
		if (!pkg || !*pkg)
			pkg = "unknown";
		snprintf(buf6, sizeof(buf6), "%s/%s", datadir, pkg);
		pkgdatadir = buf6;
	}

	pkgconfigdir = conf_get(g->conf, "pkgconfigdir");
	if (!pkgconfigdir || !*pkgconfigdir) {
		static char buf7[512];
		snprintf(buf7, sizeof(buf7), "%s/pkgconfig", libdir);
		pkgconfigdir = buf7;
	}

	pkgconfigexecdir = conf_get(g->conf, "pkgconfigexecdir");
	if (!pkgconfigexecdir || !*pkgconfigexecdir) {
		static char buf8[512];
		snprintf(buf8, sizeof(buf8), "%s/pkgconfig", libdir);
		pkgconfigexecdir = buf8;
	}

	/* append to build.ninja */
	path = path_join(root, "build.ninja");
	f = fopen(path, "a");
	if (!f) {
		fprintf(stderr, "satan: %s: %s\n", path, strerror(errno));
		free(path);
		return -1;
	}

	fprintf(f, "\n# install targets\n");
	str_init(&all_installs);

	for (size_t i = 0; i < g->installs.len; i++) {
		struct InstItem *it = vec_get(&g->installs, i);
		char *dst = xstrdup(it->dst);
		const char *base;
		const char *dir = NULL;
		size_t dir_len = 0;
		size_t var_len = 0;
		char *out_path;
		struct {
			const char *var;
			const char *dir;
		} prefixes[] = {
			{ "$BINDIR", bindir },
			{ "$SBINDIR", sbindir },
			{ "$LIBEXECDIR", libexecdir },
			{ "$LIBDIR", libdir },
			{ "$INCLUDEDIR", incdir },
			{ "$PKGDATADIR", pkgdatadir },
			{ "$DATADIR", datadir },
			{ "$SYSCONFDIR", sysconfdir },
			{ "$PKGCONFIGDIR", pkgconfigdir },
			{ "$PKGCONFIGEXECDIR", pkgconfigexecdir },
		};

		base = strrchr(it->src, '/');
		base = base ? base + 1 : it->src;
		for (size_t pi = 0; pi < sizeof(prefixes) / sizeof(prefixes[0]); pi++) {
			if (starts_with(dst, prefixes[pi].var)) {
				dir = prefixes[pi].dir;
				var_len = strlen(prefixes[pi].var);
				break;
			}
		}
		if (dir) {
			dir_len = strlen(dir);
			out_path = xmalloc(dir_len + strlen(dst) + 256);
		} else {
			out_path = xmalloc(strlen(dst) + 256);
		}
		if (dir) {
			if (ends_with(dst, "/")) {
				const char *suffix = dst + var_len;
				sprintf(out_path, "%s%s%s", dir, suffix, base);
			} else {
				sprintf(out_path, "%s%s", dir, dst + var_len);
			}
		} else {
			strcpy(out_path, dst);
			if (ends_with(dst, "/"))
				sprintf(out_path + strlen(out_path), "%s", base);
		}

		if (destdir && *destdir) {
			char *full;
			size_t dlen = strlen(destdir);
			size_t plen = strlen(out_path);
			full = xmalloc(dlen + plen + 2);
			if (destdir[dlen - 1] == '/' && out_path[0] == '/')
				snprintf(full, dlen + plen + 2, "%s%s", destdir, out_path + 1);
			else if (destdir[dlen - 1] == '/' || out_path[0] == '/')
				snprintf(full, dlen + plen + 2, "%s%s", destdir, out_path);
			else
				snprintf(full, dlen + plen + 2, "%s/%s", destdir, out_path);
			free(out_path);
			out_path = full;
		}

		fprintf(f, "build %s: install %s\n", out_path, it->src);
		fprintf(f, "  mode = %04o\n", it->mode);

		if (all_installs.len)
			str_add(&all_installs, " ");
		str_add(&all_installs, out_path);

		free(out_path);
		free(dst);
	}

	fprintf(f, "\nbuild install: phony %s\n", str_finish(&all_installs));
	fclose(f);
	free(path);
	return 0;
}

static int cond_val(struct GenCtx *g, const char *name, int *found)
{
	void *v;

	v = map_get(&g->conds, name);
	if (!v) {
		*found = 0;
		return 0;
	}
	*found = 1;
	return (int)(intptr_t)v;
}

static const char *def_val(struct GenCtx *g, const char *name)
{
	if (map_has(&g->undefs, name))
		return NULL;
	{
		const char *val = map_get(&g->defs, name);
		const char *cond;
		const char *sep;
		char *cond_name;
		int found, ok;
		int neg = 0;

		if (!val || strncmp(val, "COND:", 5) != 0)
			return val;
		cond = val + 5;
		sep = strchr(cond, ':');
		if (!sep)
			return NULL;
		cond_name = xstrndup(cond, (size_t)(sep - cond));
		if (cond_name[0] == '!') {
			neg = 1;
			memmove(cond_name, cond_name + 1, strlen(cond_name));
		}
		ok = cond_val(g, cond_name, &found);
		free(cond_name);
		if (!found)
			return NULL;
		if (neg)
			ok = !ok;
		if (!ok)
			return NULL;
		return sep + 1;
	}
}

static int write_config_h(struct GenCtx *g, const char *tmpl, const char *out)
{
	FILE *in, *f;
	char line[4096];

	in = fopen(tmpl, "r");
	if (!in)
		return -1;
	f = fopen(out, "w");
	if (!f) {
		fclose(in);
		return -1;
	}
	while (fgets(line, sizeof(line), in)) {
		if (strstr(line, "#include \"sys.h\"") != NULL) {
			int found, val;
			val = cond_val(g, "HAVE_SYS_TYPES_H", &found);
			if (found && val)
				fprintf(f, "#include <sys/types.h>\n");
			val = cond_val(g, "HAVE_INTTYPES_H", &found);
			if (found && val)
				fprintf(f, "#include <inttypes.h>\n");
			val = cond_val(g, "HAVE_STDINT_H", &found);
			if (found && val)
				fprintf(f, "#include <stdint.h>\n");
			val = cond_val(g, "HAVE_WCHAR_H", &found);
			if (found && val)
				fprintf(f, "#include <wchar.h>\n");
			val = cond_val(g, "HAVE_STDINT_H", &found);
			if (found && val)
				fprintf(f, "#define HAVE_SIZE_MAX 1\n");
			fprintf(f, "int wcwidth(wchar_t);\n");
		}
		if (strncmp(line, "#undef ", 7) == 0) {
			char *p = line + 7;
			char name[256];
			size_t i = 0;
			int found, val;
			const char *dval;
			while (*p && isspace((unsigned char)*p))
				p++;
			while (*p && !isspace((unsigned char)*p) && i + 1 < sizeof(name))
				name[i++] = *p++;
			name[i] = '\0';
			dval = def_val(g, name);
			if (dval) {
				if (*dval) {
					fprintf(f, "#define %s %s\n", name, dval);
				} else if (strcmp(name, "X_BYTE_ORDER") == 0) {
					fprintf(f,
						"#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)\n"
						"# if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__\n"
						"#  define X_BYTE_ORDER X_LITTLE_ENDIAN\n"
						"# elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n"
						"#  define X_BYTE_ORDER X_BIG_ENDIAN\n"
						"# endif\n"
						"#endif\n");
				} else {
					fprintf(f, "/* #undef %s */\n", name);
				}
				continue;
			}
			val = cond_val(g, name, &found);
			if (found && val) {
				fprintf(f, "#define %s 1\n", name);
				continue;
			}
		}
		fputs(line, f);
	}
	fclose(in);
	fclose(f);
	return 0;
}

static void config_min_cb(const char *k, void *v, void *arg)
{
	FILE *f = arg;
	if (!starts_with(k, "HAVE_"))
		return;
	if ((int)(intptr_t)v)
		fprintf(f, "#define %s 1\n", k);
}

struct DefEmitCtx {
	FILE *f;
	struct GenCtx *g;
};

static void config_def_cb(const char *k, void *v, void *arg)
{
	struct DefEmitCtx *ctx = arg;
	const char *val = v;
	const char *cond;
	const char *sep;
	char *cond_name;
	int found, ok;
	int neg = 0;
	if (!ctx || !ctx->f || !ctx->g)
		return;
	if (map_has(&ctx->g->undefs, k))
		return;
	if (!k || !*k)
		return;
	if (val && strncmp(val, "COND:", 5) == 0) {
		cond = val + 5;
		sep = strchr(cond, ':');
		if (!sep)
			return;
		cond_name = xstrndup(cond, (size_t)(sep - cond));
		if (cond_name[0] == '!') {
			neg = 1;
			memmove(cond_name, cond_name + 1, strlen(cond_name));
		}
		ok = cond_val(ctx->g, cond_name, &found);
		free(cond_name);
		if (!found)
			return;
		if (neg)
			ok = !ok;
		if (!ok)
			return;
		val = sep + 1;
	}
	if (val && *val)
		fprintf(ctx->f, "#define %s %s\n", k, val);
	else
		fprintf(ctx->f, "#define %s\n", k);
}

static int write_config_min(struct GenCtx *g, const char *out)
{
	FILE *f = fopen(out, "w");
	const char *ver;
	const char *pver;
	const char *ver_def;
	const char *pver_def;
	struct DefEmitCtx defctx;
	if (!f)
		return -1;
	fprintf(f, "/* satan config.h */\n");
	/* feature test macros must be first */
	fprintf(f, "#define _GNU_SOURCE 1\n");
	fprintf(f, "#define _DEFAULT_SOURCE 1\n");
	fprintf(f, "#define _POSIX_C_SOURCE 200809L\n");
	fprintf(f, "\n");
	map_iter(&g->conds, config_min_cb, f);
	ver = conf_get(g->conf, "VERSION");
	pver = conf_get(g->conf, "PACKAGE_VERSION");
	if (!ver || !*ver)
		ver = "0";
	if (!pver || !*pver)
		pver = ver;
	ver_def = def_val(g, "VERSION");
	pver_def = def_val(g, "PACKAGE_VERSION");
	if (!ver_def)
		fprintf(f, "#define VERSION \"%s\"\n", ver);
	if (!pver_def)
		fprintf(f, "#define PACKAGE_VERSION \"%s\"\n", pver);
	defctx.f = f;
	defctx.g = g;
	map_iter(&g->defs, config_def_cb, &defctx);
	fprintf(f, "\n#ifndef HAVE_PLEDGE\n#  define pledge(...) 0\n#endif\n");
	fclose(f);
	return 0;
}

static int write_config_h_cmake(struct GenCtx *g, const char *tmpl, const char *out)
{
	FILE *in, *f;
	char line[4096];

	in = fopen(tmpl, "r");
	if (!in)
		return -1;
	f = fopen(out, "w");
	if (!f) {
		fclose(in);
		return -1;
	}

	while (fgets(line, sizeof(line), in)) {
		if (strstr(line, "@SIZEOF_SHORT_CODE@") || strstr(line, "${SIZEOF_SHORT_CODE}")) {
			fprintf(f, "#define SIZEOF_SHORT __SIZEOF_SHORT__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_INT_CODE@") || strstr(line, "${SIZEOF_INT_CODE}")) {
			fprintf(f, "#define SIZEOF_INT __SIZEOF_INT__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_LONG_CODE@") || strstr(line, "${SIZEOF_LONG_CODE}")) {
			fprintf(f, "#define SIZEOF_LONG __SIZEOF_LONG__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_LONG_LONG_CODE@") ||
			strstr(line, "${SIZEOF_LONG_LONG_CODE}")) {
			fprintf(f, "#define SIZEOF_LONG_LONG __SIZEOF_LONG_LONG__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_UNSIGNED_SHORT_CODE@") ||
			strstr(line, "${SIZEOF_UNSIGNED_SHORT_CODE}")) {
			fprintf(f, "#define SIZEOF_UNSIGNED_SHORT __SIZEOF_SHORT__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_UNSIGNED_CODE@") || strstr(line, "${SIZEOF_UNSIGNED_CODE}")) {
			fprintf(f, "#define SIZEOF_UNSIGNED __SIZEOF_INT__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_UNSIGNED_LONG_CODE@") ||
			strstr(line, "${SIZEOF_UNSIGNED_LONG_CODE}")) {
			fprintf(f, "#define SIZEOF_UNSIGNED_LONG __SIZEOF_LONG__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_UNSIGNED_LONG_LONG_CODE@") ||
			strstr(line, "${SIZEOF_UNSIGNED_LONG_LONG_CODE}")) {
			fprintf(f, "#define SIZEOF_UNSIGNED_LONG_LONG __SIZEOF_LONG_LONG__\n");
			continue;
		}
		if (strstr(line, "@SIZEOF_SIZE_T_CODE@") || strstr(line, "${SIZEOF_SIZE_T_CODE}")) {
			fprintf(f, "#define SIZEOF_SIZE_T __SIZEOF_SIZE_T__\n");
			continue;
		}
		if (strncmp(line, "#cmakedefine", 12) == 0) {
			char *p = line + 12;
			char name[256];
			size_t i = 0;
			int found, val;
			char *v;
			while (*p && isspace((unsigned char)*p))
				p++;
			while (*p && !isspace((unsigned char)*p) && i + 1 < sizeof(name))
				name[i++] = *p++;
			name[i] = '\0';
			while (*p && isspace((unsigned char)*p))
				p++;
			if (strcmp(name, "SIZEOF_WCHAR_T") == 0) {
				fprintf(f, "#define SIZEOF_WCHAR_T __SIZEOF_WCHAR_T__\n");
				continue;
			}
			v = str_trim(p);
			val = cond_val(g, name, &found);
			if (!found || !val) {
				fprintf(f, "/* #undef %s */\n", name);
				continue;
			}
			if (v && *v) {
				if (strchr(v, '@')) {
					char msg[256];
					snprintf(msg, sizeof(msg), "cmake: unresolved @...@ for %s", name);
					warn_once(g, msg);
					fprintf(f, "/* #undef %s */\n", name);
					continue;
				}
				fprintf(f, "#define %s %s\n", name, v);
			} else {
				fprintf(f, "#define %s 1\n", name);
			}
			continue;
		}
		fputs(line, f);
	}
	fclose(in);
	fclose(f);
	return 0;
}

static int emit_config_headers(struct GenCtx *g, const char *root)
{
	char *tmpl = path_join(root, "config.h.in");
	int cmake = 0;
	if (access(tmpl, R_OK) != 0) {
		free(tmpl);
		tmpl = path_join(root, "build/cmake/config.h.in");
		if (access(tmpl, R_OK) != 0) {
			free(tmpl);
			for (size_t i = 0; i < g->dirs.len; i++) {
				struct Dir *d = vec_get(&g->dirs, i);
				char *out;
				if (d->targets.len == 0 && i != 0)
					continue;
				out = path_join(d->path, "config.h");
				if (write_config_min(g, out) != 0) {
					fprintf(stderr, "satan: failed to write %s\n", out);
					free(out);
					return -1;
				}
				free(out);
			}
			return 0;
		}
		cmake = 1;
	}
	if (cmake) {
		if (probe_cmake_defs(g, tmpl) != 0) {
			free(tmpl);
			return -1;
		}
	}
	for (size_t i = 0; i < g->dirs.len; i++) {
		struct Dir *d = vec_get(&g->dirs, i);
		if (d->targets.len == 0 && i != 0)
			continue;
		{
			char *out = path_join(d->path, "config.h");
			if ((cmake ? write_config_h_cmake(g, tmpl, out) :
				write_config_h(g, tmpl, out)) != 0) {
				fprintf(stderr, "satan: failed to write %s\n", out);
				free(out);
				free(tmpl);
				return -1;
			}
			free(out);
		}
	}
	free(tmpl);
	return 0;
}

/* process extra config headers from AC_CONFIG_HEADERS */
static int emit_extra_config_headers(struct GenCtx *g, const char *root)
{
	const char *ch_list = conf_get(g->conf, "CONFIG_HEADERS");
	struct Vec headers;
	if (!ch_list || !*ch_list)
		return 0;
	split_words(&headers, ch_list);
	for (size_t i = 0; i < headers.len; i++) {
		char *h = vec_get(&headers, i);
		char *infile = xmalloc(strlen(h) + 4);
		char *inpath;
		char *outpath;
		sprintf(infile, "%s.in", h);
		inpath = path_join(root, infile);
		outpath = path_join(root, h);
		if (access(inpath, R_OK) == 0) {
			if (write_config_h(g, inpath, outpath) != 0) {
				fprintf(stderr, "satan: failed to write %s\n", outpath);
				free(infile);
				free(inpath);
				free(outpath);
				vec_free(&headers, free);
				return -1;
			}
		}
		free(infile);
		free(inpath);
		free(outpath);
	}
	vec_free(&headers, free);
	return 0;
}

static int emit_subst_headers(struct GenCtx *g)
{
	struct Map cfg_headers;
	struct Vec headers;
	const char *ch_list;

	map_init(&cfg_headers);
	vec_init(&headers);
	ch_list = conf_get(g->conf, "CONFIG_HEADERS");
	if (ch_list && *ch_list) {
		split_words(&headers, ch_list);
		for (size_t i = 0; i < headers.len; i++) {
			char *h = vec_get(&headers, i);
			if (h && *h)
				map_set(&cfg_headers, h, (void *)1);
		}
	}
	vec_free(&headers, free);

	for (size_t i = 0; i < g->dirs.len; i++) {
		struct Dir *d = vec_get(&g->dirs, i);
		DIR *dir = opendir(d->path);
		struct dirent *ent;
		if (!dir)
			continue;
		while ((ent = readdir(dir))) {
			const char *name = ent->d_name;
			size_t n;
			char *inpath;
			char *outname;
			char *outpath;
			char *rel;
			if (!name || name[0] == '.')
				continue;
			n = strlen(name);
			if (n < 6)
				continue;
			if (strcmp(name, "config.h.in") == 0)
				continue;
			if (!ends_with(name, ".h.in"))
				continue;
			inpath = path_join(d->path, name);
			outname = xstrndup(name, n - 3);
			outpath = path_join(d->path, outname);
			rel = rel_path(d->rel, outname);
			if (map_has(&cfg_headers, rel)) {
				free(rel);
				free(inpath);
				free(outname);
				free(outpath);
				continue;
			}
			free(rel);
			if (write_subst_header(d, inpath, outpath) != 0) {
				fprintf(stderr, "satan: failed to write %s\n", outpath);
				free(inpath);
				free(outname);
				free(outpath);
				closedir(dir);
				map_free(&cfg_headers, NULL);
				return -1;
			}
			free(inpath);
			free(outname);
			free(outpath);
		}
		closedir(dir);
	}
	map_free(&cfg_headers, NULL);
	return 0;
}

static int emit_gdk_config_h(struct GenCtx *g, const char *root)
{
	const char *gdktarget;
	char *gdkdir;
	char *outpath;
	FILE *f;
	int found;
	int val;

	gdkdir = path_join(root, "gdk");
	if (access(gdkdir, R_OK) != 0) {
		free(gdkdir);
		return 0;
	}
	free(gdkdir);
	outpath = path_join(root, "gdk/gdkconfig.h");
	f = fopen(outpath, "w");
	if (!f) {
		free(outpath);
		return -1;
	}
	fprintf(f,
		"/* gdkconfig.h\n"
		" *\n"
		" * This is a generated file.  Please modify `configure.in'\n"
		" */\n\n"
		"#ifndef GDKCONFIG_H\n"
		"#define GDKCONFIG_H\n\n"
		"#ifdef __cplusplus\n"
		"extern \"C\" {\n"
		"#endif /* __cplusplus */\n\n"
		"#ifndef GSEAL\n"
		"#  ifdef GSEAL_ENABLE\n"
		"#    define GSEAL(ident)      _g_sealed__ ## ident\n"
		"#  else\n"
		"#    define GSEAL(ident)      ident\n"
		"#  endif\n"
		"#endif /* !GSEAL */\n");

	gdktarget = conf_get(g->conf, "gdktarget");
	if ((!gdktarget || !*gdktarget)) {
		val = cond_val(g, "USE_X11", &found);
		if (found && val)
			gdktarget = "x11";
	}
	if (gdktarget && strcmp(gdktarget, "x11") == 0)
		fprintf(f, "\n#define GDK_WINDOWING_X11\n");
	else if (gdktarget && strcmp(gdktarget, "directfb") == 0)
		fprintf(f, "\n#define GDK_WINDOWING_DIRECTFB\n");

	val = cond_val(g, "HAVE_WCHAR_H", &found);
	if (found && val)
		fprintf(f, "\n#define GDK_HAVE_WCHAR_H 1\n");
	val = cond_val(g, "HAVE_WCTYPE_H", &found);
	if (found && val)
		fprintf(f, "#define GDK_HAVE_WCTYPE_H 1\n");

	fprintf(f,
		"\n#ifdef __cplusplus\n"
		"}\n"
		"#endif /* __cplusplus */\n\n"
		"#endif /* GDKCONFIG_H */\n");
	fclose(f);
	free(outpath);
	return 0;
}

static void add_config_file(struct Vec *files, struct Map *seen, const char *path)
{
	if (!path || !*path)
		return;
	if (map_has(seen, path))
		return;
	map_set(seen, path, (void *)1);
	vec_push(files, xstrdup(path));
}

static int scan_skip_dir(const char *name)
{
	if (!name || !*name)
		return 1;
	if (name[0] == '.')
		return 1;
	if (strcmp(name, "autom4te.cache") == 0)
		return 1;
	if (strcmp(name, "build") == 0)
		return 1;
	return 0;
}

static void scan_makefile_in(struct Vec *files, struct Map *seen, const char *root, const char *rel)
{
	DIR *d;
	struct dirent *de;
	char *path;

	if (!root)
		return;
	path = rel ? path_join(root, rel) : xstrdup(root);
	d = opendir(path);
	if (!d) {
		free(path);
		return;
	}
	while ((de = readdir(d)) != NULL) {
		char *npath;
		if (scan_skip_dir(de->d_name))
			continue;
		if (rel && *rel)
			npath = path_join(rel, de->d_name);
		else
			npath = xstrdup(de->d_name);
		{
			char *full = path_join(root, npath);
			struct stat st;
			if (stat(full, &st) == 0) {
				if (S_ISDIR(st.st_mode)) {
					scan_makefile_in(files, seen, root, npath);
				} else if (S_ISREG(st.st_mode) &&
					strcmp(de->d_name, "Makefile.in") == 0) {
					char *out = (rel && *rel) ? path_join(rel, "Makefile") :
						xstrdup("Makefile");
					add_config_file(files, seen, out);
					free(out);
				}
			}
			free(full);
		}
		free(npath);
	}
	closedir(d);
	free(path);
}

static void collect_config_files(struct Vec *files, const struct Conf *conf,
	const char *root, int scan_if_empty, int scan_always)
{
	struct Map seen;
	const char *cf_list = conf_get(conf, "CONFIG_FILES");
	map_init(&seen);
	if (cf_list && *cf_list) {
		struct Vec list;
		split_words(&list, cf_list);
		for (size_t i = 0; i < list.len; i++) {
			char *f = vec_get(&list, i);
			if (f && *f)
				add_config_file(files, &seen, f);
		}
		vec_free(&list, free);
		if (scan_always)
			scan_makefile_in(files, &seen, root, NULL);
	} else if (scan_if_empty) {
		scan_makefile_in(files, &seen, root, NULL);
	}
	map_free(&seen, NULL);
}

static int emit_config_files(const char *root, const struct Conf *conf,
	int missing_empty, int scan_if_empty, int scan_always)
{
	struct Vec files;
	int wrote = 0;

	vec_init(&files);
	collect_config_files(&files, conf, root, scan_if_empty, scan_always);
	for (size_t i = 0; i < files.len; i++) {
		char *f = vec_get(&files, i);
		char *infile = xmalloc(strlen(f) + 4);
		char *outfile = xstrdup(f);
		char *inpath;
		char *outpath;
		char *content;
		FILE *in, *out;

		sprintf(infile, "%s.in", f);
		inpath = path_join(root, infile);
		outpath = path_join(root, outfile);

		in = fopen(inpath, "r");
		if (!in) {
			free(infile);
			free(outfile);
			free(inpath);
			free(outpath);
			continue;
		}

		fseek(in, 0, SEEK_END);
		long size = ftell(in);
		fseek(in, 0, SEEK_SET);
		content = xmalloc(size + 1);
		if (fread(content, 1, size, in) != (size_t)size && !feof(in)) {
			fclose(in);
			free(content);
			free(infile);
			free(outfile);
			free(inpath);
			free(outpath);
			continue;
		}
		content[size] = '\0';
		fclose(in);

		out = fopen(outpath, "w");
		if (!out) {
			free(content);
			free(infile);
			free(outfile);
			free(inpath);
			free(outpath);
			continue;
		}

		{
			const char *base = strrchr(outpath, '/');
			base = base ? base + 1 : outpath;
			int is_makefile = (strncmp(base, "Makefile", 8) == 0);

			for (char *p = content; *p; ) {
				if (*p == '@') {
					char *q = p + 1;
					while (*q && *q != '@' && *q != '\n' &&
						(isalnum((unsigned char)*q) || *q == '_')) {
						q++;
					}
					if (*q == '@' && q > p + 1) {
					char *var = xstrndup(p + 1, q - p - 1);
					const char *val = conf_get(conf, var);
					char *mv = NULL;
					char *sv = NULL;
					if (val && str_has_bad_chars(val)) {
						fprintf(stderr,
							"satan: warning: dropping %s with non-printable chars in %s\n",
							var, outpath);
						val = NULL;
					}
					if (val && is_makefile) {
						struct Str tmp;
						const char *s = val;
						size_t vlen = strlen(var);
						str_init(&tmp);
						while (*s) {
							if (*s == '$') {
								if (s[1] == '{' && strncmp(s + 2, var, vlen) == 0 &&
									s[2 + vlen] == '}') {
									s += 3 + vlen;
									continue;
								}
								if (s[1] == '(' && strncmp(s + 2, var, vlen) == 0 &&
									s[2 + vlen] == ')') {
									s += 3 + vlen;
									continue;
								}
								if (strncmp(s + 1, var, vlen) == 0) {
									s += 1 + vlen;
									continue;
								}
							}
							str_addc(&tmp, *s++);
						}
						sv = str_finish(&tmp);
						val = sv;
					}
					if (val && is_makefile) {
						/* convert $FOO to $(FOO) for make */
						struct Str tmp;
						str_init(&tmp);
						for (const char *s = val; *s; ) {
								if (*s == '$') {
									if (s[1] == '(' || s[1] == '{' || isdigit((unsigned char)s[1])) {
										str_addc(&tmp, *s++);
										continue;
									}
									if (isalpha((unsigned char)s[1]) || s[1] == '_') {
										const char *t = s + 1;
										while (isalnum((unsigned char)*t) || *t == '_')
											t++;
										str_addc(&tmp, '$');
										str_addc(&tmp, '(');
										{
											char *name = xstrndup(s + 1,
												(size_t)(t - (s + 1)));
											str_add(&tmp, name);
											free(name);
										}
										str_addc(&tmp, ')');
										s = t;
										continue;
									}
								}
								str_addc(&tmp, *s++);
						}
						mv = str_finish(&tmp);
					}
					if (val || mv) {
						fprintf(out, "%s", mv ? mv : val);
						} else if (missing_empty) {
							fprintf(out, "%s", "");
						} else {
							fprintf(out, "@%s@", var);
						}
					free(mv);
					free(sv);
					free(var);
						p = q + 1;
					} else {
						fputc(*p, out);
						p++;
					}
				} else {
					fputc(*p, out);
					p++;
				}
			}
		}

		fclose(out);
		free(content);
		free(infile);
		free(outfile);
		free(inpath);
		free(outpath);
		wrote = 1;
	}
	vec_free(&files, free);
	return wrote ? 0 : -1;
}

static int parse_config_header_entry(const char *s, char **out, char **in)
{
	const char *sep;
	if (!s || !*s)
		return -1;
	sep = strchr(s, ':');
	if (!sep) {
		*out = xstrdup(s);
		*in = NULL;
		return 0;
	}
	if (sep == s)
		return -1;
	*out = xstrndup(s, (size_t)(sep - s));
	*in = xstrdup(sep + 1);
	return 0;
}

static int emit_config_headers_only(struct GenCtx *g, const char *root)
{
	const char *ch_list = conf_get(g->conf, "CONFIG_HEADERS");
	if (ch_list && *ch_list) {
		struct Vec headers;
		split_words(&headers, ch_list);
		for (size_t i = 0; i < headers.len; i++) {
			char *h = vec_get(&headers, i);
			char *outname = NULL;
			char *inname = NULL;
			char *infile = NULL;
			char *inpath = NULL;
			char *outpath = NULL;
			if (parse_config_header_entry(h, &outname, &inname) != 0)
				continue;
			if (inname && *inname) {
				inpath = path_join(root, inname);
			} else {
				infile = xmalloc(strlen(outname) + 4);
				sprintf(infile, "%s.in", outname);
				inpath = path_join(root, infile);
			}
			outpath = path_join(root, outname);
			if (access(inpath, R_OK) == 0) {
				if (write_config_h(g, inpath, outpath) != 0) {
					fprintf(stderr, "satan: failed to write %s\n", outpath);
					free(outname);
					free(inname);
					free(infile);
					free(inpath);
					free(outpath);
					vec_free(&headers, free);
					return -1;
				}
			}
			free(outname);
			free(inname);
			free(infile);
			free(inpath);
			free(outpath);
		}
		vec_free(&headers, free);
		return 0;
	}
	{
		char *tmpl = path_join(root, "config.h.in");
		char *out = path_join(root, "config.h");
		if (access(tmpl, R_OK) == 0) {
			if (write_config_h(g, tmpl, out) != 0) {
				fprintf(stderr, "satan: failed to write %s\n", out);
				free(tmpl);
				free(out);
				return -1;
			}
			free(tmpl);
			free(out);
			return 0;
		}
		free(tmpl);
		free(out);
	}
	{
		char *tmpl = path_join(root, "build/cmake/config.h.in");
		char *out = path_join(root, "config.h");
		if (access(tmpl, R_OK) == 0) {
			if (write_config_h_cmake(g, tmpl, out) != 0) {
				fprintf(stderr, "satan: failed to write %s\n", out);
				free(tmpl);
				free(out);
				return -1;
			}
		}
		free(tmpl);
		free(out);
	}
	return 0;
}

static void collect_needed_gen(struct GenCtx *g)
{
	for (size_t di = 0; di < g->dirs.len; di++) {
		struct Dir *d = vec_get(&g->dirs, di);
		for (size_t i = 0; i < d->built.len; i++) {
			char *b = vec_get(&d->built, i);
			if (skip_stamp(d, b))
				continue;
			char *out = rel_path(d->rel, b);
			map_set(&g->need_gen, out, (void *)1);
			free(out);
		}
		for (size_t i = 0; i < d->data.len; i++) {
			struct DataItem *di = vec_get(&d->data, i);
			char *out = rel_path(d->rel, di->file);
			map_set(&g->need_gen, out, (void *)1);
			free(out);
		}
		for (size_t i = 0; i < d->headers.len; i++) {
			char *h = vec_get(&d->headers, i);
			char *out = rel_path(d->rel, h);
			map_set(&g->need_gen, out, (void *)1);
			free(out);
		}
		for (size_t i = 0; i < d->hell_installs.len; i++) {
			struct HellInstall *hi = vec_get(&d->hell_installs, i);
			char *out = rel_path(d->rel, hi->src);
			map_set(&g->need_gen, out, (void *)1);
			free(out);
		}
	}
}

static int is_make_cmd(const char *cmd)
{
	return cmd && (strstr(cmd, "MAKE") || strstr(cmd, "make"));
}

static void collect_gen_pick(struct GenCtx *g)
{
	for (size_t di = 0; di < g->dirs.len; di++) {
		struct Dir *d = vec_get(&g->dirs, di);
		for (size_t i = 0; i < d->gens.len; i++) {
			struct GenRule *r = vec_get(&d->gens, i);
			char *out = rel_path(d->rel, r->tgt);
			struct GenRule *prev;
			if (!map_has(&g->need_gen, out)) {
				free(out);
				continue;
			}
			prev = map_get(&g->gen_pick, out);
			if (!prev || (is_make_cmd(prev->cmd) && !is_make_cmd(r->cmd)))
				map_set(&g->gen_pick, out, r);
			free(out);
		}
	}
}

static void cond_from_conf(const char *k, void *v, void *arg)
{
	struct GenCtx *g = arg;
	const char *val = v;
	if (strncmp(k, "COND_", 5) == 0) {
		map_set(&g->conds, k + 5, (void *)(intptr_t)(atoi(val) ? 1 : 0));
	}
}

static char *resolve_conf_value(const struct Conf *conf, const char *s)
{
	struct Str out;
	size_t i, n;

	if (!s)
		return xstrdup("");
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
			char *name;
			const char *val;
			while (j < n && s[j] != endc)
				j++;
			if (j >= n)
				break;
			name = xstrndup(s + i + 2, j - (i + 2));
			val = conf_get(conf, name);
			if (val)
				str_add(&out, val);
			free(name);
			i = j;
			continue;
		}
		if (s[i] == '$' && i + 1 < n &&
			(isalpha((unsigned char)s[i + 1]) || s[i + 1] == '_')) {
			size_t j = i + 1;
			char *name;
			const char *val;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			name = xstrndup(s + i + 1, j - (i + 1));
			val = conf_get(conf, name);
			if (val)
				str_add(&out, val);
			free(name);
			i = j - 1;
			continue;
		}
		if (s[i] == '@') {
			size_t j = i + 1;
			char *name;
			const char *val;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				name = xstrndup(s + i + 1, j - (i + 1));
				val = conf_get(conf, name);
				if (val)
					str_add(&out, val);
				free(name);
				i = j;
				continue;
			}
		}
		str_addc(&out, s[i]);
	}
	return str_finish(&out);
}

static void def_from_conf(const char *k, void *v, void *arg)
{
	struct GenCtx *g = arg;
	const char *val = v;
	if (strncmp(k, "DEF_", 4) == 0) {
		if (map_has(&g->undefs, k + 4))
			return;
		char *exp = resolve_conf_value(g->conf, val);
		map_set(&g->defs, k + 4, exp ? exp : xstrdup(""));
	}
}

static void undef_from_conf(const char *k, void *v, void *arg)
{
	struct GenCtx *g = arg;
	const char *val = v;
	if (strncmp(k, "UNDEF_", 6) == 0) {
		if (!val || !*val)
			return;
		if (atoi(val) == 0)
			return;
		map_set(&g->undefs, k + 6, (void *)1);
	}
}

static int run_cmd_exit(const char *cmd)
{
	int rc = system(cmd);
	if (rc == -1)
		return -1;
	if (!WIFEXITED(rc))
		return -1;
	return WEXITSTATUS(rc);
}

static int probe_endian_value(struct GenCtx *g)
{
	char src[] = "/tmp/satan_endian_XXXXXX";
	char bin[] = "/tmp/satan_endian_XXXXXX";
	char cmd[1024];
	int fd;
	FILE *f;
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	const char *ldflags = conf_get(g->conf, "LDFLAGS");
	int fully = conf_get_int(g->conf, "FULLY_STATIC", 1);
	int use_static = fully && g->probe_static_ok;
	const char *sflag = use_static ? "-static" : "";
	int rc;

	if (cppflags && (!*cppflags || *cppflags < ' '))
		cppflags = NULL;
	if (cflags && (!*cflags || *cflags < ' '))
		cflags = NULL;
	if (ldflags && (!*ldflags || *ldflags < ' '))
		ldflags = NULL;
	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;
	if (ldflags && str_has_bad_chars(ldflags))
		ldflags = NULL;

	fd = mkstemp(src);
	if (fd < 0)
		return -1;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		unlink(src);
		return -1;
	}
	fputs("#include <stdint.h>\n"
	      "int main(void){\n"
	      "#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)\n"
	      "# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__\n"
	      "  return 0;\n"
	      "# elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__\n"
	      "  return 1;\n"
	      "# else\n"
	      "  return 2;\n"
	      "# endif\n"
	      "#else\n"
	      "  union { uint32_t i; unsigned char c[4]; } u;\n"
	      "  u.i = 0x01020304U;\n"
	      "  return u.c[0] == 0x01 ? 0 : 1;\n"
	      "#endif\n"
	      "}\n", f);
	fclose(f);
	fd = mkstemp(bin);
	if (fd < 0) {
		unlink(src);
		return -1;
	}
	close(fd);

	snprintf(cmd, sizeof(cmd), "%s -x c %s -o %s %s %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", src, bin,
			cppflags ? cppflags : "",
			cflags ? cflags : "",
			ldflags ? ldflags : "",
			sflag);
	rc = run_cmd_exit(cmd);
	if (rc != 0) {
		unlink(src);
		unlink(bin);
		return -1;
	}
	rc = run_cmd_exit(bin);
	unlink(src);
	unlink(bin);
	if (rc == 0)
		return 1;
	if (rc == 1)
		return 0;
	return -1;
}

static int split_endian_entry(const char *s, char **name, char **big,
	char **little, char **unknown)
{
	char *dup;
	char *p1;
	char *p2;
	char *p3;

	if (!s || !name || !big || !little || !unknown)
		return 0;
	*name = NULL;
	*big = NULL;
	*little = NULL;
	*unknown = NULL;
	dup = xstrdup(s);
	p1 = strchr(dup, ':');
	if (!p1) {
		free(dup);
		return 0;
	}
	*p1++ = '\0';
	p2 = strchr(p1, ':');
	if (!p2) {
		free(dup);
		return 0;
	}
	*p2++ = '\0';
	p3 = strchr(p2, ':');
	if (p3)
		*p3++ = '\0';
	*name = xstrdup(dup);
	*big = xstrdup(p1);
	*little = xstrdup(p2);
	if (p3 && *p3)
		*unknown = xstrdup(p3);
	free(dup);
	return 1;
}

static void apply_endian_checks(struct GenCtx *g)
{
	const char *list = conf_get(g->conf, "CHECK_ENDIAN");
	struct Vec words;
	int endian;

	if (!list || !*list)
		return;
	endian = probe_endian_value(g);
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *tok = vec_get(&words, i);
		char *name;
		char *big;
		char *little;
		char *unknown;
		const char *val = NULL;
		if (!split_endian_entry(tok, &name, &big, &little, &unknown))
			continue;
		if (endian == 1)
			val = big;
		else if (endian == 0)
			val = little;
		else if (unknown && *unknown)
			val = unknown;
		if (val && *val)
			conf_set(g->conf, name, val);
		free(name);
		free(big);
		free(little);
		free(unknown);
	}
	vec_free(&words, free);
}

int gen_project(const char *root, struct Conf *conf)
{
	struct GenCtx g;
	const char *extra_pkg;
	const char *check_pkg;
	size_t built_total = 0;
	char *cmake_tmpl = NULL;

	gen_init(&g, conf);
	g.have_config_h = 1;
	map_set(&g.conds, "ENABLE_SHARED", (void *)0);
	map_set(&g.conds, "ENABLE_STATIC", (void *)1);
	map_set(&g.conds, "BUILD_SHARED_LIBS", (void *)0);
	if (conf_get(conf, "ENABLE_SHARED"))
		map_set(&g.conds, "ENABLE_SHARED", (void *)(intptr_t)conf_get_int(conf, "ENABLE_SHARED", 0));
	if (conf_get(conf, "ENABLE_STATIC"))
		map_set(&g.conds, "ENABLE_STATIC", (void *)(intptr_t)conf_get_int(conf, "ENABLE_STATIC", 1));
	if (conf_get(conf, "BUILD_SHARED_LIBS"))
		map_set(&g.conds, "BUILD_SHARED_LIBS", (void *)(intptr_t)conf_get_int(conf, "BUILD_SHARED_LIBS", 0));
	apply_endian_checks(&g);
	map_iter(&conf->kv, undef_from_conf, &g);
	map_iter(&conf->kv, def_from_conf, &g);
	map_iter(&conf->kv, cond_from_conf, &g);

	probe_count_init(&g, root);
	g.probe_quiet = 1;
	probe_static_init(&g);
	extra_pkg = conf_get(conf, "EXTRA_PKG");
	if (extra_pkg && *extra_pkg) {
		if (probe_pkgconf(&g, extra_pkg, 1) != 0) {
			gen_free(&g);
			return -1;
		}
	}
	check_pkg = conf_get(conf, "CHECK_PKG");
	if (check_pkg && *check_pkg) {
		if (probe_pkgconf(&g, check_pkg, 0) != 0) {
			gen_free(&g);
			return -1;
		}
	}

	probe_list_parallel(&g, "CHECK_HEADER", PROBE_HEADER);
	probe_list_parallel(&g, "CHECK_FUNC", PROBE_FUNC);
	probe_replace_funcs_parallel(&g, "REPLACE_FUNC");
	probe_list_parallel(&g, "CHECK_LIB", PROBE_LIB);
	probe_list_parallel(&g, "CHECK_DECL", PROBE_DECL);
	probe_std_headers(&g);
	probe_std_funcs(&g);
	probe_safe_extensions(&g);

	if (parse_makefile(&g, root, "") != 0) {
		gen_free(&g);
		return -1;
	}

	built_total = count_built_sources(&g);
	if (built_total) {
		if (g.probe_total < g.probe_done)
			g.probe_total = g.probe_done;
		g.probe_total += built_total;
	}
	cmake_tmpl = path_join(root, "config.h.in");
	if (access(cmake_tmpl, R_OK) != 0) {
		free(cmake_tmpl);
		cmake_tmpl = path_join(root, "build/cmake/config.h.in");
		if (access(cmake_tmpl, R_OK) == 0) {
			size_t pending = probe_count_cmake_pending(&g, cmake_tmpl);
			if (pending) {
				if (g.probe_total < g.probe_done)
					g.probe_total = g.probe_done;
				g.probe_total += pending;
			}
		} else {
			free(cmake_tmpl);
			cmake_tmpl = NULL;
		}
	} else {
		free(cmake_tmpl);
		cmake_tmpl = NULL;
	}

	g.probe_quiet = 0;
	g.probe_done = 0;
	probe_log_flush(&g);

	if (cmake_tmpl) {
		free(cmake_tmpl);
		cmake_tmpl = NULL;
	}

	if (emit_config_headers(&g, root) != 0) {
		gen_free(&g);
		return -1;
	}
	if (emit_extra_config_headers(&g, root) != 0) {
		gen_free(&g);
		return -1;
	}
	if (emit_subst_headers(&g) != 0) {
		gen_free(&g);
		return -1;
	}
	if (emit_gdk_config_h(&g, root) != 0) {
		gen_free(&g);
		return -1;
	}

	collect_needed_gen(&g);
	collect_gen_pick(&g);

	/* run BUILT_SOURCES rules */
	for (size_t i = 0; i < g.dirs.len; i++) {
		struct Dir *d = vec_get(&g.dirs, i);
		for (size_t j = 0; j < d->built.len; j++) {
			char *b = vec_get(&d->built, j);
			struct GenRule *r = find_gen(d, b);
			if (!r || !r->cmd) {
				char *full = path_join(d->path, b);
				if (access(full, R_OK) != 0) {
					fprintf(stderr, "satan: warning: missing BUILT_SOURCE rule for %s\n", b);
				}
				free(full);
				continue;
			}
			if (strstr(r->cmd, "config.status") || strstr(r->cmd, "$(MAKE") ||
				strstr(r->cmd, "${MAKE")) {
				char *full = path_join(d->path, b);
				if (access(full, R_OK) != 0) {
					fprintf(stderr,
						"satan: warning: skipping BUILT_SOURCE %s (config.status/make)\n",
						b);
				}
				free(full);
				continue;
			}
			g.probe_done++;
			if (g.probe_done > g.probe_total)
				g.probe_total = g.probe_done;
			fprintf(stderr, "[%zu/%zu] gen %s\n", g.probe_done, g.probe_total, b);
			{
				char *cmd_exp;
				char *cmd_deps;
				int err = 0;
				/* todo: skip if newer than deps */
				cmd_deps = expand_deps_cmd(d, r->deps);
				cmd_exp = expand_vars(d, r->cmd, b, cmd_deps ? cmd_deps : r->deps, 1, &err);
				free(cmd_deps);
				if (err) {
					free(cmd_exp);
					fprintf(stderr, "satan: failed to expand command for %s\n", b);
					continue;
				}
				{
					char cwd[2048];
					char dirpath[2048];
					if (!getcwd(cwd, sizeof(cwd))) {
						free(cmd_exp);
						continue;
					}
					snprintf(dirpath, sizeof(dirpath), "%s/%s", root, d->rel && *d->rel ? d->rel : ".");
					if (chdir(dirpath) != 0) {
						free(cmd_exp);
						chdir(cwd);
						continue;
					}
					if (system(cmd_exp) != 0)
						fprintf(stderr, "satan: warning: BUILT_SOURCE command failed for %s\n", b);
					chdir(cwd);
				}
				free(cmd_exp);
			}
		}
	}

	/* generate CONFIG_FILES from .in templates */
	(void)emit_config_files(root, g.conf, 0, 0, 0);

	for (size_t i = 0; i < g.dirs.len; i++) {
		struct Dir *d = vec_get(&g.dirs, i);
		int is_root = (i == 0 && (!d->rel || !*d->rel));
		if (emit_dir_build(&g, d, is_root) != 0) {
			gen_free(&g);
			return -1;
		}
	}

	if (g.dirs.len) {
		struct Dir *rootdir = vec_get(&g.dirs, 0);
		if (emit_root_all(&g, rootdir) != 0) {
			gen_free(&g);
			return -1;
		}
	}

	gather_installs(&g);
	if (emit_install(&g, root) != 0) {
		gen_free(&g);
		return -1;
	}
	write_stub_all(&g, root);

	gen_free(&g);
	return 0;
}

int gen_config_only(const char *root, struct Conf *conf)
{
	struct GenCtx g;
	const char *extra_pkg;
	const char *check_pkg;
	const char *host;

	host = conf_get(conf, "CONFIGURE_HOST");
	if (host && *host) {
		if (strstr(host, "aix") == NULL && strstr(host, "AIX") == NULL) {
			/* avoid bogus aix defines, little bit hardcoded, sue me*/
			if (conf_get(conf, "DEF_AIX"))
				conf_set(conf, "UNDEF_AIX", "1");
		}
	}

	gen_init(&g, conf);
	g.have_config_h = 1;
	map_set(&g.conds, "ENABLE_SHARED", (void *)0);
	map_set(&g.conds, "ENABLE_STATIC", (void *)1);
	map_set(&g.conds, "BUILD_SHARED_LIBS", (void *)0);
	if (conf_get(conf, "ENABLE_SHARED"))
		map_set(&g.conds, "ENABLE_SHARED",
			(void *)(intptr_t)conf_get_int(conf, "ENABLE_SHARED", 0));
	if (conf_get(conf, "ENABLE_STATIC"))
		map_set(&g.conds, "ENABLE_STATIC",
			(void *)(intptr_t)conf_get_int(conf, "ENABLE_STATIC", 1));
	if (conf_get(conf, "BUILD_SHARED_LIBS"))
		map_set(&g.conds, "BUILD_SHARED_LIBS",
			(void *)(intptr_t)conf_get_int(conf, "BUILD_SHARED_LIBS", 0));
	apply_endian_checks(&g);
	map_iter(&conf->kv, undef_from_conf, &g);
	map_iter(&conf->kv, def_from_conf, &g);
	map_iter(&conf->kv, cond_from_conf, &g);

	probe_count_init(&g, root);
	g.probe_quiet = 1;
	probe_static_init(&g);
	extra_pkg = conf_get(conf, "EXTRA_PKG");
	if (extra_pkg && *extra_pkg) {
		if (probe_pkgconf(&g, extra_pkg, 1) != 0) {
			gen_free(&g);
			return -1;
		}
	}
	check_pkg = conf_get(conf, "CHECK_PKG");
	if (check_pkg && *check_pkg) {
		if (probe_pkgconf(&g, check_pkg, 0) != 0) {
			gen_free(&g);
			return -1;
		}
	}

	probe_list_parallel(&g, "CHECK_HEADER", PROBE_HEADER);
	probe_list_parallel(&g, "CHECK_FUNC", PROBE_FUNC);
	probe_replace_funcs_parallel(&g, "REPLACE_FUNC");
	probe_list_parallel(&g, "CHECK_LIB", PROBE_LIB);
	probe_list_parallel(&g, "CHECK_DECL", PROBE_DECL);
	probe_std_headers(&g);
	probe_std_funcs(&g);
	probe_safe_extensions(&g);

	g.probe_quiet = 0;
	g.probe_done = 0;
	probe_log_flush(&g);

	{
		struct Map seen;
		map_init(&seen);
		for (size_t i = 0; i < g.conds.cap; i++) {
			struct MapEnt *e = &g.conds.e[i];
			if (!e->used || !e->k)
				continue;
			if (strncmp(e->k, "HAVE_", 5) != 0)
				continue;
			if (map_has(&seen, e->k))
				continue;
			map_set(&seen, e->k, (void *)1);
			if ((int)(intptr_t)e->v) {
				char *k = xmalloc(strlen(e->k) + 5);
				snprintf(k, strlen(e->k) + 5, "DEF_%s", e->k);
				if (conf_get(conf, k)) {
					char *uk = xmalloc(strlen(e->k) + 7);
					snprintf(uk, strlen(e->k) + 7, "UNDEF_%s", e->k);
					conf_set(conf, uk, "1");
					free(uk);
				}
				free(k);
				continue;
			}
			{
				char *uk = xmalloc(strlen(e->k) + 7);
				snprintf(uk, strlen(e->k) + 7, "UNDEF_%s", e->k);
				conf_set(conf, uk, "1");
				free(uk);
			}
		}
		map_free(&seen, NULL);
	}

	if (emit_config_headers_only(&g, root) != 0) {
		gen_free(&g);
		return -1;
	}
	if (emit_config_files(root, g.conf, 1, 1, 1) != 0)
		fprintf(stderr, "satan: warning: no CONFIG_FILES or Makefile.in found\n");
	gen_free(&g);
	return 0;
}
