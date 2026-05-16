/* parses configure.ac and writes .demiurge for satan */

#include "conf.h"
#include "map.h"
#include "macro.h"
#include "str.h"
#include "util.h"
#include "vec.h"

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/* autoconf macro types */
enum {
	M_HDRS = 1,
	M_FUNCS = 2,
	M_LIBS = 3,
	M_DECLS = 4,
	M_PKGS = 5,
	M_CONDS = 6,
	M_SUBST = 7,
	M_INIT = 8,
	M_ARG_ENABLE = 9,
	M_ARG_WITH = 10,
	M_REPLACE_FUNCS = 11,
	M_CONFIG_FILES = 12,
	M_CONFIG_HEADERS = 13,
	M_DEFINE = 14,
	M_BIGENDIAN = 15,
	M_SYS_EXT = 16,
	M_XTRANS_CONN = 17,
	M_AM_INIT = 18,
	M_AM_PROG_AR = 19,
	M_AM_PROG_AS = 20,
	M_AM_PROG_LEX = 21,
	M_AC_PROG_CC = 22,
	M_AC_PROG_CXX = 23,
	M_AC_PROG_RANLIB = 24,
	M_AC_PROG_SED = 25,
	M_AC_PROG_AWK = 26,
	M_AC_PROG_YACC = 27,
	M_AC_PROG_LN_S = 28,
	M_AC_PROG_MKDIR_P = 29,
	M_AC_PROG_GREP = 30,
	M_AC_PROG_FGREP = 31,
	M_AC_PROG_EGREP = 32
};

struct Macro {
	const char *name;
	int kind;
	int arg;
};

/* autoconf data */
struct Auto {
	struct Vec hdrs;
	struct Vec funcs;
	struct Vec libs;
	struct Vec decls;
	struct Vec pkgs;
	struct Vec conds;
	struct Vec subst;          /* vars needing @VAR@ substitution */
	struct Vec vals;
	struct Vec replace_funcs;
	struct Vec config_files;
	struct Vec config_headers;
	struct Vec defs;
	struct Vec endians;
	struct Map seen_hdrs;
	struct Map seen_funcs;
	struct Map seen_libs;
	struct Map seen_decls;
	struct Map seen_pkgs;
	struct Map seen_conds;
	struct Map seen_subst;
	struct Map seen_replace_funcs;
	struct Map seen_config_files;
	struct Map seen_config_headers;
	struct Map seen_defs;
	struct Map seen_endians;
	struct Map valmap;         
	struct Map defmap;
	int am_no_define;
};

static void list_add(struct Vec *v, struct Map *seen, const char *s);
static char *resolve_value(struct Auto *a, const char *s, int depth);
static char *extract_args(const char *s, size_t *idx);
static void split_args(struct Vec *out, const char *s);

static void auto_init(struct Auto *a)
{
	vec_init(&a->hdrs);
	vec_init(&a->funcs);
	vec_init(&a->libs);
	vec_init(&a->decls);
	vec_init(&a->pkgs);
	vec_init(&a->conds);
	vec_init(&a->subst);
	vec_init(&a->vals);
	vec_init(&a->replace_funcs);
	vec_init(&a->config_files);
	vec_init(&a->config_headers);
	vec_init(&a->defs);
	vec_init(&a->endians);
	map_init(&a->seen_hdrs);
	map_init(&a->seen_funcs);
	map_init(&a->seen_libs);
	map_init(&a->seen_decls);
	map_init(&a->seen_pkgs);
	map_init(&a->seen_conds);
	map_init(&a->seen_subst);
	map_init(&a->seen_replace_funcs);
	map_init(&a->seen_config_files);
	map_init(&a->seen_config_headers);
	map_init(&a->seen_defs);
	map_init(&a->seen_endians);
	map_init(&a->valmap);
	map_init(&a->defmap);
	a->am_no_define = 0;
}

static void auto_free(struct Auto *a)
{
	vec_free(&a->hdrs, free);
	vec_free(&a->funcs, free);
	vec_free(&a->libs, free);
	vec_free(&a->decls, free);
	vec_free(&a->pkgs, free);
	vec_free(&a->conds, free);
	vec_free(&a->subst, free);
	vec_free(&a->vals, free);
	vec_free(&a->replace_funcs, free);
	vec_free(&a->config_files, free);
	vec_free(&a->config_headers, free);
	vec_free(&a->defs, free);
	vec_free(&a->endians, free);
	map_free(&a->seen_hdrs, NULL);
	map_free(&a->seen_funcs, NULL);
	map_free(&a->seen_libs, NULL);
	map_free(&a->seen_decls, NULL);
	map_free(&a->seen_pkgs, NULL);
	map_free(&a->seen_conds, NULL);
	map_free(&a->seen_subst, NULL);
	map_free(&a->seen_replace_funcs, NULL);
	map_free(&a->seen_config_files, NULL);
	map_free(&a->seen_config_headers, NULL);
	map_free(&a->seen_defs, NULL);
	map_free(&a->seen_endians, NULL);
	map_free(&a->valmap, free);
	map_free(&a->defmap, free);
}

static int is_word(int c)
{
	return isalnum((unsigned char)c) || c == '_';
}

static int match_word(const char *s, size_t i, const char *name)
{
	size_t n;

	if (!s || !name)
		return 0;
	n = strlen(name);
	if (i > 0 && is_word(s[i - 1]))
		return 0;
	if (strncmp(s + i, name, n) != 0)
		return 0;
	if (is_word(s[i + n]))
		return 0;
	return 1;
}

static char *read_file(const char *path)
{
	FILE *f;
	struct Str out;
	char buf[4096];

	f = fopen(path, "r");
	if (!f)
		return NULL;
	str_init(&out);
	while (fgets(buf, sizeof(buf), f))
		str_add(&out, buf);
	fclose(f);
	return str_finish(&out);
}

/* remove dnl m4_dnl and # comment lines */
static char *strip_comments(const char *in)
{
	struct Str out;
	const char *p;

	str_init(&out);
	p = in ? in : "";
	while (*p) {
		const char *line = p;
		const char *e = strchr(p, '\n');
		const char *q;
		if (!e)
			e = p + strlen(p);
		q = line;
		while (q < e && isspace((unsigned char)*q))
			q++;
		if ((e - q) >= 3 && strncmp(q, "dnl", 3) == 0) {
			p = (*e == '\n') ? e + 1 : e;
			continue;
		}
		if ((e - q) >= 6 && strncmp(q, "m4_dnl", 6) == 0) {
			p = (*e == '\n') ? e + 1 : e;
			continue;
		}
		if (q < e && *q == '#') {
			p = (*e == '\n') ? e + 1 : e;
			continue;
		}
		{
			char *seg = xstrndup(line, (size_t)(e - line));
			str_add(&out, seg);
			free(seg);
		}
		if (*e == '\n')
			str_addc(&out, '\n');
		p = (*e == '\n') ? e + 1 : e;
	}
	return str_finish(&out);
}

static char *strip_brackets(char *s)
{
	size_t n;

	if (!s)
		return NULL;
	str_trim(s);
	n = strlen(s);
	if (n >= 2 && s[0] == '[' && s[n - 1] == ']') {
		memmove(s, s + 1, n - 2);
		s[n - 2] = '\0';
		str_trim(s);
	}
	return s;
}

static char *strip_quotes(char *s)
{
	size_t n;

	if (!s)
		return NULL;
	str_trim(s);
	n = strlen(s);
	if (n >= 2 && ((s[0] == '"' && s[n - 1] == '"') ||
		(s[0] == '\'' && s[n - 1] == '\''))) {
		memmove(s, s + 1, n - 2);
		s[n - 2] = '\0';
		str_trim(s);
	}
	return s;
}

static char *strip_backticks(char *s)
{
	size_t n;

	if (!s)
		return NULL;
	str_trim(s);
	n = strlen(s);
	if (n >= 2 && s[0] == '`' && s[n - 1] == '`') {
		memmove(s, s + 1, n - 2);
		s[n - 2] = '\0';
		str_trim(s);
	}
	return s;
}

static void need_subst(struct Auto *a, const char *name)
{
	list_add(&a->subst, &a->seen_subst, name);
}

static void auto_set_val(struct Auto *a, const char *name, const char *val, int overwrite)
{
	char *cur;
	char *dup;

	if (!name || !*name)
		return;
	cur = map_get(&a->valmap, name);
	if (cur) {
		if (!overwrite)
			return;
	} else {
		vec_push(&a->vals, xstrdup(name));
	}
	dup = xstrdup(val ? val : "");
	if (cur)
		free(cur);
	map_set(&a->valmap, name, dup);
}

static const char *auto_get_val(struct Auto *a, const char *name)
{
	return map_get(&a->valmap, name);
}

static void def_set(struct Auto *a, const char *name, const char *val)
{
	char *cur;
	char *dup;

	if (!name || !*name)
		return;
	cur = map_get(&a->defmap, name);
	if (!cur)
		list_add(&a->defs, &a->seen_defs, name);
	dup = xstrdup(val ? val : "");
	if (cur)
		free(cur);
	map_set(&a->defmap, name, dup);
}

static const char *def_get(struct Auto *a, const char *name)
{
	return map_get(&a->defmap, name);
}

static void def_unset(struct Auto *a, const char *name)
{
	if (!name || !*name)
		return;
	map_set(&a->defmap, name, NULL);
}

static char *quote_if_needed(const char *s)
{
	size_t n;
	struct Str out;

	if (!s)
		return xstrdup("\"\"");
	n = strlen(s);
	if (n >= 2 && ((s[0] == '"' && s[n - 1] == '"') ||
		(s[0] == '\'' && s[n - 1] == '\''))) {
		return xstrdup(s);
	}
	str_init(&out);
	str_addc(&out, '"');
	str_add(&out, s);
	str_addc(&out, '"');
	return str_finish(&out);
}

static void setdefs_autoquoted(struct Auto *a, const char *key)
{
	const char *v;
	char *q;

	if (a->am_no_define)
		return;
	v = auto_get_val(a, key);
	if (!v || !*v)
		return;
	q = quote_if_needed(v);
	if (!q)
		return;
	def_set(a, key, q);
	free(q);
}

static const char *const pkg_keys[] = {
	"PACKAGE_NAME",
	"PACKAGE",
	"PACKAGE_TARNAME",
	"PACKAGE_VERSION",
	"PACKAGE_STRING",
	"PACKAGE_BUGREPORT",
	"PACKAGE_URL",
	"VERSION",
};

static int has_option(const char *opts, const char *name)
{
	size_t n;
	const char *p;

	if (!opts || !*opts || !name || !*name)
		return 0;
	n = strlen(name);
	for (p = opts; *p; ) {
		while (*p && isspace((unsigned char)*p))
			p++;
		if (!*p)
			break;
		if (strncmp(p, name, n) == 0 &&
			(p[n] == '\0' || isspace((unsigned char)p[n])))
			return 1;
		while (*p && !isspace((unsigned char)*p))
			p++;
	}
	return 0;
}

static int parse_assign_pair(struct Auto *a, const char *s, char **name_out, char **val_out)
{
	const char *p;
	const char *name_end;
	const char *eq;
	char *tmp;
	char *name;
	char *val;
	char *exp;
	char *cut;

	if (!s || !name_out || !val_out)
		return 0;
	tmp = xstrdup(s);
	cut = strpbrk(tmp, ";\n");
	if (cut)
		*cut = '\0';
	p = tmp;
	while (*p && isspace((unsigned char)*p))
		p++;
	if (!isalpha((unsigned char)*p) && *p != '_') {
		free(tmp);
		return 0;
	}
	name_end = p + 1;
	while (*name_end && (isalnum((unsigned char)*name_end) || *name_end == '_'))
		name_end++;
	eq = name_end;
	while (*eq && isspace((unsigned char)*eq))
		eq++;
	if (*eq != '=') {
		free(tmp);
		return 0;
	}
	name = xstrndup(p, (size_t)(name_end - p));
	eq++;
	while (*eq && isspace((unsigned char)*eq))
		eq++;
	val = xstrdup(eq);
	strip_brackets(val);
	strip_quotes(val);
	strip_backticks(val);
	exp = resolve_value(a, val, 0);
	free(val);
	*name_out = name;
	*val_out = exp ? exp : xstrdup("");
	free(tmp);
	return 1;
}

static void scan_define_snippets(struct Auto *a, const char *s, const char *cond)
{
	size_t i;
	static const char *const defs[] = {
		"AC_DEFINE",
		"AC_DEFINE_UNQUOTED",
	};

	if (!s || !*s)
		return;
	for (i = 0; s[i]; i++) {
		for (size_t di = 0; di < sizeof(defs) / sizeof(defs[0]); di++) {
			const char *name = defs[di];
			size_t j;
			char *args;
			struct Vec argv;
			char *arg;
			char *arg2;
			char *val;
			if (!match_word(s, i, name))
				continue;
			j = i + strlen(name);
			while (s[j] && isspace((unsigned char)s[j]))
				j++;
			if (s[j] != '(')
				continue;
			args = extract_args(s, &j);
			if (!args)
				continue;
			split_args(&argv, args);
			free(args);
			arg = argv.len > 0 ? vec_get(&argv, 0) : NULL;
			arg2 = argv.len > 1 ? vec_get(&argv, 1) : NULL;
			if (arg)
				strip_brackets(arg);
			if (arg2)
				strip_brackets(arg2);
			if (arg && *arg) {
				char *dname = xstrdup(arg);
				strip_quotes(dname);
				if (arg2 && *arg2) {
					val = xstrdup(arg2);
					str_trim(val);
					strip_quotes(val);
					strip_backticks(val);
				} else {
					val = xstrdup("");
				}
				if (cond && *cond) {
					struct Str out;
					char *cval;
					str_init(&out);
					str_add(&out, "COND:");
					str_add(&out, cond);
					str_addc(&out, ':');
					str_add(&out, val);
					cval = str_finish(&out);
					def_set(a, dname, cval);
					free(cval);
				} else {
					if (!val[0]) {
						free(val);
						val = xstrdup("1");
					}
					def_set(a, dname, val);
				}
				free(val);
				free(dname);
			}
			vec_free(&argv, free);
			i = j;
			break;
		}
	}
}

static void add_endian(struct Auto *a, const char *name, const char *big,
	const char *little, const char *unknown)
{
	struct Str out;
	char *entry;

	if (!name || !*name || !big || !little)
		return;
	if (map_has(&a->seen_endians, name))
		return;
	map_set(&a->seen_endians, name, (void *)1);
	str_init(&out);
	str_add(&out, name);
	str_addc(&out, ':');
	str_add(&out, big);
	str_addc(&out, ':');
	str_add(&out, little);
	if (unknown && *unknown) {
		str_addc(&out, ':');
		str_add(&out, unknown);
	}
	entry = str_finish(&out);
	vec_push(&a->endians, entry);
}

/* expand $(VAR) and @VAR@ references  */
static char *resolve_value(struct Auto *a, const char *s, int depth)
{
	struct Str out;
	size_t i, n;

	if (!s)
		return xstrdup("");
	if (depth > 8)
		return xstrdup(s);
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
			char *exp;
			while (j < n && s[j] != endc)
				j++;
			if (j >= n)
				break;
			name = xstrndup(s + i + 2, j - (i + 2));
			if (strcmp(name, "top_srcdir") == 0 || strcmp(name, "top_builddir") == 0 ||
				strcmp(name, "srcdir") == 0 || strcmp(name, "builddir") == 0) {
				str_addc(&out, '$');
				str_addc(&out, s[i + 1]);
				str_add(&out, name);
				str_addc(&out, endc);
				free(name);
				i = j;
				continue;
			}
			val = auto_get_val(a, name);
			if (val) {
				exp = resolve_value(a, val, depth + 1);
				str_add(&out, exp);
				free(exp);
			} else {
				str_addc(&out, '$');
				str_addc(&out, s[i + 1]);
				str_add(&out, name);
				str_addc(&out, endc);
			}
			free(name);
			i = j;
			continue;
		}
		if (s[i] == '$' && i + 1 < n &&
			(isalpha((unsigned char)s[i + 1]) || s[i + 1] == '_')) {
			size_t j = i + 1;
			char *name;
			const char *val;
			char *exp;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			name = xstrndup(s + i + 1, j - (i + 1));
			if (strcmp(name, "top_srcdir") == 0 || strcmp(name, "top_builddir") == 0 ||
				strcmp(name, "srcdir") == 0 || strcmp(name, "builddir") == 0) {
				str_addc(&out, '$');
				str_add(&out, name);
				free(name);
				i = j - 1;
				continue;
			}
			val = auto_get_val(a, name);
			if (val) {
				exp = resolve_value(a, val, depth + 1);
				str_add(&out, exp);
				free(exp);
			} else {
				str_addc(&out, '$');
				str_add(&out, name);
			}
			free(name);
			i = j - 1;
			continue;
		}
		if (s[i] == '@') {
			size_t j = i + 1;
			char *name;
			const char *val;
			char *exp;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				name = xstrndup(s + i + 1, j - (i + 1));
				if (strcmp(name, "top_srcdir") == 0 || strcmp(name, "top_builddir") == 0 ||
					strcmp(name, "srcdir") == 0 || strcmp(name, "builddir") == 0) {
					str_addc(&out, '@');
					str_add(&out, name);
					str_addc(&out, '@');
					free(name);
					i = j;
					continue;
				}
				val = auto_get_val(a, name);
				if (val) {
					exp = resolve_value(a, val, depth + 1);
					str_add(&out, exp);
					free(exp);
				} else {
					str_addc(&out, '@');
					str_add(&out, name);
					str_addc(&out, '@');
				}
				free(name);
				i = j;
				continue;
			}
		}
		str_addc(&out, s[i]);
	}
	return str_finish(&out);
}

/* join backslash continued lines */
static char *join_cont(const char *in)
{
	struct Str out;
	const char *p;

	str_init(&out);
	p = in ? in : "";
	while (*p) {
		const char *line = p;
		const char *e = strchr(p, '\n');
		const char *q;
		size_t len;
		if (!e)
			e = p + strlen(p);
		q = e;
		while (q > line && isspace((unsigned char)q[-1]))
			q--;
		len = (size_t)(q - line);
		if (len > 0 && line[len - 1] == '\\') {
			char *seg = xstrndup(line, len - 1);
			str_add(&out, seg);
			free(seg);
			str_addc(&out, ' ');
		} else {
			char *seg = xstrndup(line, len);
			str_add(&out, seg);
			free(seg);
			if (*e == '\n')
				str_addc(&out, '\n');
		}
		p = (*e == '\n') ? e + 1 : e;
	}
	return str_finish(&out);
}

/* split macro args on comma , still respect []  )*/
static void split_args(struct Vec *out, const char *s)
{
	const char *p, *start;
	int bdepth = 0;
	int pdepth = 0;

	vec_init(out);
	if (!s)
		return;
	start = s;
	for (p = s; ; p++) {
		char c = *p;
		if (c == '\0' || (c == ',' && bdepth == 0 && pdepth == 0)) {
			char *seg = xstrndup(start, (size_t)(p - start));
			str_trim(seg);
			vec_push(out, seg);
			if (c == '\0')
				break;
			start = p + 1;
			continue;
		}
		if (c == '[')
			bdepth++;
		else if (c == ']' && bdepth > 0)
			bdepth--;
		else if (c == '(' && bdepth == 0)
			pdepth++;
		else if (c == ')' && bdepth == 0 && pdepth > 0)
			pdepth--;
	}
}

static void list_add(struct Vec *v, struct Map *seen, const char *s)
{
	if (!s || !*s)
		return;
	if (map_has(seen, s))
		return;
	map_set(seen, s, (void *)1);
	vec_push(v, xstrdup(s));
}

static void split_words(struct Vec *out, const char *s)
{
	const char *p, *start;

	vec_init(out);
	if (!s)
		return;
	p = s;
	while (*p) {
		while (*p && (isspace((unsigned char)*p) || *p == ','))
			p++;
		if (!*p)
			break;
		start = p;
		while (*p && !isspace((unsigned char)*p) && *p != ',')
			p++;
		vec_push(out, xstrndup(start, (size_t)(p - start)));
	}
}

static int token_ok(const char *t)
{
	if (!t || !*t)
		return 0;
	for (const char *p = t; *p; p++) {
		if (*p == '$' || *p == '@')
			return 0;
	}
	return 1;
}

/* filter out version specs and operators from pkg list */
static int pkg_token_ok(const char *t)
{
	if (!token_ok(t))
		return 0;
	if (t[0] == '>' || t[0] == '<' || t[0] == '=' || t[0] == '!')
		return 0;
	if (strcmp(t, ">=") == 0 || strcmp(t, "<=") == 0 || strcmp(t, "==") == 0)
		return 0;
	if (strcmp(t, "!=") == 0 || strcmp(t, "||") == 0 || strcmp(t, "&&") == 0)
		return 0;
	if (isdigit((unsigned char)t[0]) && strspn(t, "0123456789.") == strlen(t))
		return 0;
	return 1;
}

static void add_words(struct Vec *dst, struct Map *seen, const char *s)
{
	struct Vec words;

	split_words(&words, s);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		if (token_ok(w))
			list_add(dst, seen, w);
	}
	vec_free(&words, free);
}

static char *cond_from_name(const char *prefix, const char *name)
{
	struct Str out;

	if (!name || !*name)
		return NULL;
	str_init(&out);
	if (prefix)
		str_add(&out, prefix);
	for (const char *p = name; *p; p++) {
		if (isalnum((unsigned char)*p))
			str_addc(&out, (char)toupper((unsigned char)*p));
		else
			str_addc(&out, '_');
	}
	return str_finish(&out);
}

static char *first_word(const char *s)
{
	struct Vec words;
	char *out = NULL;

	split_words(&words, s);
	if (words.len > 0) {
		char *w = vec_get(&words, 0);
		if (w && *w)
			out = xstrdup(w);
	}
	vec_free(&words, free);
	return out;
}

static void add_pkgs(struct Auto *a, const char *s)
{
	struct Vec words;

	split_words(&words, s);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		if (pkg_token_ok(w))
			list_add(&a->pkgs, &a->seen_pkgs, w);
	}
	vec_free(&words, free);
}

static int parse_assign(struct Auto *a, const char *s, int overwrite)
{
	const char *p = s;
	const char *name_end;
	const char *eq;
	char *name;
	char *val;
	char *exp;

	if (!p)
		return 0;
	while (*p && isspace((unsigned char)*p))
		p++;
	if (!isalpha((unsigned char)*p) && *p != '_')
		return 0;
	name_end = p + 1;
	while (*name_end && (isalnum((unsigned char)*name_end) || *name_end == '_'))
		name_end++;
	eq = name_end;
	while (*eq && isspace((unsigned char)*eq))
		eq++;
	if (*eq != '=')
		return 0;
	name = xstrndup(p, (size_t)(name_end - p));
	eq++;
	while (*eq && isspace((unsigned char)*eq))
		eq++;
	val = xstrdup(eq);
	strip_brackets(val);
	strip_quotes(val);
	strip_backticks(val);
	exp = resolve_value(a, val, 0);
	auto_set_val(a, name, exp, overwrite);
	free(exp);
	free(val);
	free(name);
	return 1;
}

static void parse_assignments(struct Auto *a, const char *buf)
{
	const char *p = buf;
	while (p && *p) {
		const char *e = strchr(p, '\n');
		char *line;
		if (!e)
			e = p + strlen(p);
		line = xstrndup(p, (size_t)(e - p));
		parse_assign(a, line, 0);
		free(line);
		p = (*e == '\n') ? e + 1 : e;
	}
}

static char *extract_args(const char *s, size_t *idx)
{
	size_t i;
	int bdepth = 0;
	int pdepth = 0;
	const char *start;

	if (!s || !idx)
		return NULL;
	i = *idx;
	if (s[i] != '(')
		return NULL;
	start = s + i + 1;
	for (i = i + 1; s[i]; i++) {
		char c = s[i];
		if (c == '[')
			bdepth++;
		else if (c == ']' && bdepth > 0)
			bdepth--;
		else if (c == '(' && bdepth == 0)
			pdepth++;
		else if (c == ')' && bdepth == 0) {
			if (pdepth == 0)
				break;
			pdepth--;
		}
	}
	if (s[i] != ')')
		return NULL;
	*idx = i;
	return xstrndup(start, (size_t)(s + i - start));
}

static int parse_configure(struct Auto *a, const char *path)
{
	static const struct Macro macros[] = {
		{ "AC_INIT", M_INIT, 0 },
		{ "AC_CHECK_HEADERS", M_HDRS, 0 },
		{ "AC_CHECK_HEADER", M_HDRS, 0 },
		{ "AC_CHECK_FUNCS", M_FUNCS, 0 },
		{ "AC_CHECK_FUNC", M_FUNCS, 0 },
		{ "AC_REPLACE_FUNCS", M_REPLACE_FUNCS, 0 },
		{ "AC_CHECK_LIB", M_LIBS, 0 },
		{ "AC_CHECK_DECLS", M_DECLS, 0 },
		{ "AC_CHECK_DECL", M_DECLS, 0 },
		{ "AC_CONFIG_FILES", M_CONFIG_FILES, 0 },
		{ "AC_CONFIG_HEADERS", M_CONFIG_HEADERS, 0 },
		{ "AC_CONFIG_HEADER", M_CONFIG_HEADERS, 0 },
		{ "AC_SUBST", M_SUBST, 0 },
		{ "AC_DEFINE", M_DEFINE, 0 },
		{ "AC_DEFINE_UNQUOTED", M_DEFINE, 0 },
		{ "AC_C_BIGENDIAN", M_BIGENDIAN, 0 },
		{ "AC_USE_SYSTEM_EXTENSIONS", M_SYS_EXT, 0 },
		{ "XTRANS_CONNECTION_FLAGS", M_XTRANS_CONN, 0 },
		{ "AC_ARG_ENABLE", M_ARG_ENABLE, 0 },
		{ "AC_ARG_WITH", M_ARG_WITH, 0 },
		{ "PKG_CHECK_MODULES", M_PKGS, 1 },
		{ "PKG_CHECK_MODULES_STATIC", M_PKGS, 1 },
		{ "PKG_CHECK_EXISTS", M_PKGS, 0 },
		{ "AM_CONDITIONAL", M_CONDS, 0 },
		{ "AM_INIT_AUTOMAKE", M_AM_INIT, 0 },
		{ "AM_PROG_AR", M_AM_PROG_AR, 0 },
		{ "AM_PROG_AS", M_AM_PROG_AS, 0 },
		{ "AM_PROG_LEX", M_AM_PROG_LEX, 0 },
		{ "AC_PROG_CC", M_AC_PROG_CC, 0 },
		{ "AC_PROG_CXX", M_AC_PROG_CXX, 0 },
		{ "AC_PROG_RANLIB", M_AC_PROG_RANLIB, 0 },
		{ "AC_PROG_SED", M_AC_PROG_SED, 0 },
		{ "AC_PROG_AWK", M_AC_PROG_AWK, 0 },
		{ "AC_PROG_YACC", M_AC_PROG_YACC, 0 },
		{ "AC_PROG_LN_S", M_AC_PROG_LN_S, 0 },
		{ "AC_PROG_MKDIR_P", M_AC_PROG_MKDIR_P, 0 },
		{ "AC_PROG_GREP", M_AC_PROG_GREP, 0 },
		{ "AC_PROG_FGREP", M_AC_PROG_FGREP, 0 },
		{ "AC_PROG_EGREP", M_AC_PROG_EGREP, 0 }
	};
	char *raw;
	char *buf;

	raw = read_file(path);
	if (!raw)
		return -1;
	buf = strip_comments(raw);
	free(raw);
	{
		char *flat = join_cont(buf);
		free(buf);
		buf = flat;
	}

	{
		struct MacroSet mset;
		char *expanded;
		macroset_init(&mset);
		macroset_load_project(&mset, path, buf);
		expanded = macroset_expand_all(&mset, buf);
		if (expanded) {
			free(buf);
			buf = expanded;
		}
		macroset_free(&mset);
	}

	parse_assignments(a, buf);

	for (size_t i = 0; buf[i]; i++) {
		for (size_t mi = 0; mi < sizeof(macros) / sizeof(macros[0]); mi++) {
			const struct Macro *m = &macros[mi];
			size_t j;
			char *args;
			struct Vec argv;
			char *arg;
			char *arg2;
			char *arg3;
			char *arg4;
			char *arg5;

			if (!match_word(buf, i, m->name))
				continue;
			j = i + strlen(m->name);
			while (buf[j] && isspace((unsigned char)buf[j]))
				j++;
			if (buf[j] != '(')
				continue;
			args = extract_args(buf, &j);
			if (!args)
				continue;
			split_args(&argv, args);
			free(args);
			arg = NULL;
			arg2 = NULL;
			arg3 = NULL;
			arg4 = NULL;
			arg5 = NULL;
			if ((size_t)m->arg < argv.len)
				arg = vec_get(&argv, m->arg);
			if (argv.len > 1)
				arg2 = vec_get(&argv, 1);
			if (argv.len > 2)
				arg3 = vec_get(&argv, 2);
			if (argv.len > 3)
				arg4 = vec_get(&argv, 3);
			if (argv.len > 4)
				arg5 = vec_get(&argv, 4);
			{
				char *args_list[] = { arg, arg2, arg3, arg4, arg5 };
				for (size_t ai = 0; ai < sizeof(args_list) / sizeof(args_list[0]); ai++) {
					if (args_list[ai])
						strip_brackets(args_list[ai]);
				}
			}
			if (m->kind == M_INIT && arg && *arg) {
				char *name = xstrdup(arg);
				char *ver = arg2 ? xstrdup(arg2) : NULL;
				char *bug = arg3 ? xstrdup(arg3) : NULL;
				char *tar = arg4 ? xstrdup(arg4) : NULL;
				char *url = arg5 ? xstrdup(arg5) : NULL;
				char *tarn;
				char *pstr;

				{
					char *qargs[] = { name, ver, bug, tar, url };
					for (size_t qi = 0; qi < sizeof(qargs) / sizeof(qargs[0]); qi++) {
						if (qargs[qi])
							strip_quotes(qargs[qi]);
					}
				}

				auto_set_val(a, "PACKAGE_NAME", name, 1);
				auto_set_val(a, "PACKAGE", name, 1);
				if (ver && *ver) {
					auto_set_val(a, "VERSION", ver, 1);
					auto_set_val(a, "PACKAGE_VERSION", ver, 1);
				}
				if (bug && *bug)
					auto_set_val(a, "PACKAGE_BUGREPORT", bug, 1);
				if (url && *url)
					auto_set_val(a, "PACKAGE_URL", url, 1);
				auto_set_val(a, "LIBS", "", 1);
				if (tar && *tar) {
					auto_set_val(a, "PACKAGE_TARNAME", tar, 1);
				} else {
					tarn = xstrdup(name);
					for (char *p = tarn; *p; p++) {
						if (isalnum((unsigned char)*p))
							*p = (char)tolower((unsigned char)*p);
						else
							*p = '-';
					}
					auto_set_val(a, "PACKAGE_TARNAME", tarn, 1);
					free(tarn);
				}
				if (ver && *ver) {
					struct Str tmp;
					str_init(&tmp);
					str_add(&tmp, name);
					str_addc(&tmp, ' ');
					str_add(&tmp, ver);
					pstr = str_finish(&tmp);
					auto_set_val(a, "PACKAGE_STRING", pstr, 1);
					free(pstr);
				}

				for (size_t pi = 0; pi < sizeof(pkg_keys) / sizeof(pkg_keys[0]); pi++)
					need_subst(a, pkg_keys[pi]);

				for (size_t pi = 0; pi < sizeof(pkg_keys) / sizeof(pkg_keys[0]); pi++)
					setdefs_autoquoted(a, pkg_keys[pi]);

				free(name);
				free(ver);
				free(bug);
				free(tar);
				free(url);
			} else if (m->kind == M_AM_INIT) {
				char *opts = NULL;
				int no_define = 0;
				if (arg) {
					opts = xstrdup(arg);
					strip_quotes(opts);
					no_define = has_option(opts, "no-define");
				}
				/* deprecated: AM_INIT_AUTOMAKE(PACKAGE, VERSION, [NO-DEFINE]) */
				if (arg2 && *arg2) {
					char *name = xstrdup(arg);
					char *ver = xstrdup(arg2);
					char *nd = arg3 ? xstrdup(arg3) : NULL;
					char *tarn;
					char *pstr;

					strip_quotes(name);
					strip_quotes(ver);
					if (nd) {
						strip_quotes(nd);
						if (strcmp(nd, "no-define") == 0)
							no_define = 1;
					}

					auto_set_val(a, "PACKAGE_NAME", name, 1);
					auto_set_val(a, "PACKAGE", name, 1);
					if (*ver) {
						auto_set_val(a, "VERSION", ver, 1);
						auto_set_val(a, "PACKAGE_VERSION", ver, 1);
					}
					tarn = xstrdup(name);
					for (char *p = tarn; *p; p++) {
						if (isalnum((unsigned char)*p))
							*p = (char)tolower((unsigned char)*p);
						else
							*p = '-';
					}
					auto_set_val(a, "PACKAGE_TARNAME", tarn, 1);
					free(tarn);
					if (*ver) {
						struct Str tmp;
						str_init(&tmp);
						str_add(&tmp, name);
						str_addc(&tmp, ' ');
						str_add(&tmp, ver);
						pstr = str_finish(&tmp);
						auto_set_val(a, "PACKAGE_STRING", pstr, 1);
						free(pstr);
					}
					for (size_t pi = 0; pi < sizeof(pkg_keys) / sizeof(pkg_keys[0]); pi++)
						need_subst(a, pkg_keys[pi]);
					if (!no_define) {
						for (size_t pi = 0; pi < sizeof(pkg_keys) / sizeof(pkg_keys[0]); pi++)
							setdefs_autoquoted(a, pkg_keys[pi]);
					}
					free(name);
					free(ver);
					free(nd);
				}
				if (no_define) {
					a->am_no_define = 1;
					for (size_t pi = 0; pi < sizeof(pkg_keys) / sizeof(pkg_keys[0]); pi++)
						def_unset(a, pkg_keys[pi]);
				}
				free(opts);
			} else if (m->kind == M_AM_PROG_AR) {
				need_subst(a, "AR");
			} else if (m->kind == M_AM_PROG_AS) {
				need_subst(a, "AS");
				if (!auto_get_val(a, "AS"))
					auto_set_val(a, "AS", "as", 0);
			} else if (m->kind == M_AM_PROG_LEX) {
				need_subst(a, "LEX");
				if (!auto_get_val(a, "LEX"))
					auto_set_val(a, "LEX", "lex", 0);
			} else if (m->kind == M_AC_PROG_CC) {
				need_subst(a, "CC");
			} else if (m->kind == M_AC_PROG_CXX) {
				need_subst(a, "CXX");
			} else if (m->kind == M_AC_PROG_RANLIB) {
				need_subst(a, "RANLIB");
			} else if (m->kind == M_AC_PROG_SED) {
				need_subst(a, "SED");
			} else if (m->kind == M_AC_PROG_AWK) {
				need_subst(a, "AWK");
			} else if (m->kind == M_AC_PROG_YACC) {
				need_subst(a, "YACC");
			} else if (m->kind == M_AC_PROG_LN_S) {
				need_subst(a, "LN_S");
			} else if (m->kind == M_AC_PROG_MKDIR_P) {
				need_subst(a, "MKDIR_P");
			} else if (m->kind == M_AC_PROG_GREP) {
				need_subst(a, "GREP");
			} else if (m->kind == M_AC_PROG_FGREP) {
				need_subst(a, "FGREP");
				if (!auto_get_val(a, "FGREP")) {
					const char *g = auto_get_val(a, "GREP");
					if (!g || !*g)
						g = "grep";
					{
						struct Str tmp;
						char *fg;
						str_init(&tmp);
						str_add(&tmp, g);
						str_add(&tmp, " -F");
						fg = str_finish(&tmp);
						auto_set_val(a, "FGREP", fg, 0);
						free(fg);
					}
				}
			} else if (m->kind == M_AC_PROG_EGREP) {
				need_subst(a, "EGREP");
				if (!auto_get_val(a, "EGREP")) {
					const char *g = auto_get_val(a, "GREP");
					if (!g || !*g)
						g = "grep";
					{
						struct Str tmp;
						char *eg;
						str_init(&tmp);
						str_add(&tmp, g);
						str_add(&tmp, " -E");
						eg = str_finish(&tmp);
						auto_set_val(a, "EGREP", eg, 0);
						free(eg);
					}
				}
			} else if (m->kind == M_SUBST && arg && *arg) {
				char *name = xstrdup(arg);
				char *val = NULL;
				char *exp;
				strip_quotes(name);
				need_subst(a, name);
				if (arg2 && *arg2) {
					val = xstrdup(arg2);
					strip_quotes(val);
					exp = resolve_value(a, val, 0);
					auto_set_val(a, name, exp, 1);
					free(exp);
				} else {
					const char *cur = auto_get_val(a, name);
					if (cur)
						auto_set_val(a, name, cur, 1);
				}
				free(val);
				free(name);
			} else if ((m->kind == M_ARG_ENABLE || m->kind == M_ARG_WITH) && arg4 && *arg4) {
				char *def = xstrdup(arg4);
				strip_quotes(def);
				parse_assign(a, def, 0);
				free(def);
			} else if (m->kind == M_BIGENDIAN) {
				char *name1 = NULL;
				char *val1 = NULL;
				char *name2 = NULL;
				char *val2 = NULL;
				char *name3 = NULL;
				char *val3 = NULL;
				if (arg && *arg)
					parse_assign_pair(a, arg, &name1, &val1);
				if (arg2 && *arg2)
					parse_assign_pair(a, arg2, &name2, &val2);
				if (arg3 && *arg3)
					parse_assign_pair(a, arg3, &name3, &val3);
				if (name1 && name2 && strcmp(name1, name2) == 0) {
					if (name3 && strcmp(name1, name3) == 0)
						add_endian(a, name1, val1, val2, val3);
					else
						add_endian(a, name1, val1, val2, NULL);
				}
				free(name1);
				free(val1);
				free(name2);
				free(val2);
				free(name3);
				free(val3);
			} else if (m->kind == M_DEFINE && arg && *arg) {
				char *name = xstrdup(arg);
				char *val = arg2 ? xstrdup(arg2) : NULL;
				strip_brackets(name);
				strip_quotes(name);
				if (val) {
					strip_brackets(val);
					str_trim(val);
					strip_backticks(val);
				}
				if (!val || !*val) {
					free(val);
					val = xstrdup("1");
				}
				def_set(a, name, val);
				free(val);
				free(name);
			} else if (arg && *arg) {
				if (m->kind == M_FUNCS) {
					char *tok = first_word(arg);
					char *cond = cond_from_name("HAVE_", tok ? tok : NULL);
					if (arg2)
						scan_define_snippets(a, arg2, cond);
					if (arg3 && cond) {
						char *neg = xmalloc(strlen(cond) + 2);
						snprintf(neg, strlen(cond) + 2, "!%s", cond);
						scan_define_snippets(a, arg3, neg);
						free(neg);
					} else if (arg3) {
						scan_define_snippets(a, arg3, NULL);
					}
					free(cond);
					free(tok);
				} else if (m->kind == M_HDRS || m->kind == M_DECLS) {
					if (arg2)
						scan_define_snippets(a, arg2, NULL);
					if (arg3)
						scan_define_snippets(a, arg3, NULL);
				} else if (m->kind == M_LIBS) {
					if (arg3)
						scan_define_snippets(a, arg3, NULL);
					if (arg4)
						scan_define_snippets(a, arg4, NULL);
				}
				if (m->kind == M_HDRS)
					add_words(&a->hdrs, &a->seen_hdrs, arg);
				else if (m->kind == M_FUNCS)
					add_words(&a->funcs, &a->seen_funcs, arg);
				else if (m->kind == M_REPLACE_FUNCS)
					add_words(&a->replace_funcs, &a->seen_replace_funcs, arg);
				else if (m->kind == M_LIBS)
					add_words(&a->libs, &a->seen_libs, arg);
				else if (m->kind == M_DECLS)
					add_words(&a->decls, &a->seen_decls, arg);
				else if (m->kind == M_CONFIG_FILES)
					add_words(&a->config_files, &a->seen_config_files, arg);
				else if (m->kind == M_CONFIG_HEADERS)
					add_words(&a->config_headers, &a->seen_config_headers, arg);
				else if (m->kind == M_PKGS)
					add_pkgs(a, arg);
				else if (m->kind == M_CONDS)
					add_words(&a->conds, &a->seen_conds, arg);
			}
			vec_free(&argv, free);
			i = j;
			break;
		}
	}
	free(buf);
	return 0;
}

static char *join_list(struct Vec *v)
{
	struct Str out;

	str_init(&out);
	for (size_t i = 0; i < v->len; i++) {
		char *s = vec_get(v, i);
		if (!s || !*s)
			continue;
		if (out.len)
			str_addc(&out, ' ');
		str_add(&out, s);
	}
	return str_finish(&out);
}

static int ends_with(const char *s, const char *suf)
{
	size_t n, m;

	if (!s || !suf)
		return 0;
	n = strlen(s);
	m = strlen(suf);
	if (m > n)
		return 0;
	return memcmp(s + (n - m), suf, m) == 0;
}

static int is_subst_file(const char *name)
{
	if (!name || !*name)
		return 0;
	if (strcmp(name, "Makefile.am") == 0)
		return 1;
	if (ends_with(name, ".am"))
		return 1;
	if (ends_with(name, ".in"))
		return 1;
	return 0;
}

/* find @VAR@  */
static void scan_subst_text(struct Auto *a, const char *s)
{
	size_t i, n;

	if (!s)
		return;
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if (s[i] != '@')
			continue;
		{
			size_t j = i + 1;
			while (j < n && (isalnum((unsigned char)s[j]) || s[j] == '_'))
				j++;
			if (j < n && s[j] == '@' && j > i + 1) {
				char *name = xstrndup(s + i + 1, j - (i + 1));
				need_subst(a, name);
				free(name);
				i = j;
				continue;
			}
		}
	}
}

static int scan_subst_file(struct Auto *a, const char *path)
{
	char *buf = read_file(path);
	if (!buf)
		return -1;
	scan_subst_text(a, buf);
	free(buf);
	return 0;
}

static int skip_dir(const char *name)
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

/* search tree for .am and .in files to find @VAR@ refs */
static void scan_subst_tree(struct Auto *a, const char *root, const char *rel)
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
		if (skip_dir(de->d_name))
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
					scan_subst_tree(a, root, npath);
				} else if (S_ISREG(st.st_mode) && is_subst_file(de->d_name)) {
					scan_subst_file(a, full);
				}
			}
			free(full);
		}
		free(npath);
	}
	closedir(d);
	free(path);
}

static char *join_path2(const char *a, const char *b)
{
	struct Str out;

	str_init(&out);
	if (a && *a)
		str_add(&out, a);
	if (b && *b) {
		if (out.len && out.s[out.len - 1] != '/')
			str_addc(&out, '/');
		str_add(&out, b);
	}
	return str_finish(&out);
}

/* set standard autoconf dir vars from satan.conf */
static void set_dir_defaults(struct Auto *a)
{
	struct Conf conf;
	const char *prefix;
	const char *bindir;
	const char *sbindir;
	const char *libdir;
	const char *includedir;
	const char *mandir;
	const char *pkg;
	char *dataroot;
	char *datadir;
	char *pkgdatadir;
	char *libexecdir;
	char *sysconfdir;
	char *localstatedir;
	const char *cc;
	const char *cxx;
	const char *cpp;
	const char *ar;
	const char *as;
	const char *ranlib;
	const char *strip;
	const char *ld;
	const char *install;
	const char *lex;
	const char *sed;
	const char *awk;
	const char *yacc;
	const char *ln_s;
	const char *grep;
	const char *cflags;
	const char *cppflags;
	const char *ldflags;
	const char *libs;

	conf_init(&conf);
// changed path for plan9/APExp
	if (conf_load(&conf, "/sys/lib/ape/satan.conf") != 0)
		conf_apply_defaults(&conf);
	else
		conf_apply_defaults(&conf);

	prefix = conf_get(&conf, "PREFIX");
	bindir = conf_get(&conf, "BINDIR");
	sbindir = conf_get(&conf, "SBINDIR");
	libdir = conf_get(&conf, "LIBDIR");
	includedir = conf_get(&conf, "INCLUDEDIR");
	mandir = conf_get(&conf, "MANDIR");
	cc = conf_get(&conf, "CC");
	cxx = conf_get(&conf, "CXX");
	cpp = conf_get(&conf, "CPP");
	ar = conf_get(&conf, "AR");
	as = conf_get(&conf, "AS");
	ranlib = conf_get(&conf, "RANLIB");
	strip = conf_get(&conf, "STRIP");
	ld = conf_get(&conf, "LD");
	install = conf_get(&conf, "INSTALL");
	lex = conf_get(&conf, "LEX");
	sed = conf_get(&conf, "SED");
	awk = conf_get(&conf, "AWK");
	yacc = conf_get(&conf, "YACC");
	ln_s = conf_get(&conf, "LN_S");
	grep = conf_get(&conf, "GREP");
	cflags = conf_get(&conf, "CFLAGS");
	cppflags = conf_get(&conf, "CPPFLAGS");
	ldflags = conf_get(&conf, "LDFLAGS");
	libs = conf_get(&conf, "LIBS");

	{
// changed to plan9 defaults
		const char *def_prefix = prefix ? prefix : "/";
		const char *def_bindir = bindir ? bindir : "/bin";
		const char *def_sbindir = sbindir ? sbindir : "/sbin";
		const char *def_libdir = libdir ? libdir : "/$M/lib/ape";
		const char *def_includedir = includedir ? includedir : "/sys/include/ape";
		const char *def_mandir = mandir ? mandir : "/sys/man";
		struct {
			const char *key;
			const char *val;
		} defaults[] = {
			{ "prefix", def_prefix },
			{ "exec_prefix", def_prefix },
			{ "bindir", def_bindir },
			{ "sbindir", def_sbindir },
			{ "libdir", def_libdir },
			{ "includedir", def_includedir },
			{ "mandir", def_mandir },
		};
		for (size_t di = 0; di < sizeof(defaults) / sizeof(defaults[0]); di++)
			auto_set_val(a, defaults[di].key, defaults[di].val, 0);
	}

	dataroot = join_path2(prefix ? prefix : "/sys/lib", "share");
	auto_set_val(a, "datarootdir", dataroot, 0);
	datadir = xstrdup(dataroot);
	auto_set_val(a, "datadir", datadir, 0);

	pkg = auto_get_val(a, "PACKAGE_TARNAME");
	if (!pkg || !*pkg)
		pkg = auto_get_val(a, "PACKAGE");
	if (pkg && *pkg) {
		pkgdatadir = join_path2(datadir, pkg);
		auto_set_val(a, "pkgdatadir", pkgdatadir, 0);
		free(pkgdatadir);
	}

	libexecdir = join_path2(prefix ? prefix : "/$M", "bin/ape");
	auto_set_val(a, "libexecdir", libexecdir, 0);
	sysconfdir = join_path2(prefix ? prefix : "/sys/lib", "etc");
	auto_set_val(a, "sysconfdir", sysconfdir, 0);
	localstatedir = join_path2(prefix ? prefix : "/sys/lib", "var");
	auto_set_val(a, "localstatedir", localstatedir, 0);

	{
		const char *const keys[] = { "top_srcdir", "top_builddir", "srcdir" };
		for (size_t ki = 0; ki < sizeof(keys) / sizeof(keys[0]); ki++)
			auto_set_val(a, keys[ki], ".", 0);
	}

	{
		const char *def_cc = (cc && *cc) ? cc : "cc";
		const char *def_cxx = (cxx && *cxx) ? cxx : "c++";
		const char *def_cpp = (cpp && *cpp) ? cpp : "cc -E";
		const char *def_ar = (ar && *ar) ? ar : "ar";
		const char *def_as = (as && *as) ? as : "as";
		const char *def_ranlib = (ranlib && *ranlib) ? ranlib : "ranlib";
		const char *def_strip = (strip && *strip) ? strip : "strip";
		const char *def_ld = (ld && *ld) ? ld : def_cc;
		const char *def_install = (install && *install) ? install : "install";
		const char *def_lex = (lex && *lex) ? lex : "lex";
		const char *def_sed = (sed && *sed) ? sed : "sed";
		const char *def_awk = (awk && *awk) ? awk : "awk";
		const char *def_yacc = (yacc && *yacc) ? yacc : "yacc";
		const char *def_ln_s = (ln_s && *ln_s) ? ln_s : "ln -s";
		const char *def_grep = (grep && *grep) ? grep : "grep";
		struct Str tmp;
		auto_set_val(a, "CC", def_cc, 0);
		auto_set_val(a, "CXX", def_cxx, 0);
		auto_set_val(a, "CPP", def_cpp, 0);
		auto_set_val(a, "AR", def_ar, 0);
		auto_set_val(a, "AS", def_as, 0);
		auto_set_val(a, "LEX", def_lex, 0);
		auto_set_val(a, "SED", def_sed, 0);
		auto_set_val(a, "AWK", def_awk, 0);
		auto_set_val(a, "YACC", def_yacc, 0);
		auto_set_val(a, "LN_S", def_ln_s, 0);
		auto_set_val(a, "GREP", def_grep, 0);
		str_init(&tmp);
		str_add(&tmp, def_grep);
		str_add(&tmp, " -F");
		{
			char *fg = str_finish(&tmp);
			auto_set_val(a, "FGREP", fg, 0);
			free(fg);
		}
		str_init(&tmp);
		str_add(&tmp, def_grep);
		str_add(&tmp, " -E");
		{
			char *eg = str_finish(&tmp);
			auto_set_val(a, "EGREP", eg, 0);
			free(eg);
		}
		auto_set_val(a, "MKDIR_P", "mkdir -p", 0);
		auto_set_val(a, "RANLIB", def_ranlib, 0);
		auto_set_val(a, "STRIP", def_strip, 0);
		auto_set_val(a, "LD", def_ld, 0);
		auto_set_val(a, "INSTALL", def_install, 0);
		if (cflags)
			auto_set_val(a, "CFLAGS", cflags, 0);
		if (cppflags)
			auto_set_val(a, "CPPFLAGS", cppflags, 0);
		if (ldflags)
			auto_set_val(a, "LDFLAGS", ldflags, 0);
		if (libs)
			auto_set_val(a, "LIBS", libs, 0);
	}

	free(dataroot);
	free(datadir);
	free(libexecdir);
	free(sysconfdir);
	free(localstatedir);
	conf_free(&conf);
}

/* write extracted data to .demiurge file */
static int write_auto(const char *root, struct Auto *a)
{
	char *out;
	char *tmp;
	FILE *f;
	char *s;
	size_t resolved = 0;
	size_t defaulted = 0;

	out = path_join(root, ".demiurge");
	tmp = path_join(root, ".demiurge.tmp");
	f = fopen(tmp, "w");
	if (!f) {
		fprintf(stderr, "demiurge: %s: %s\n", tmp, strerror(errno));
		free(out);
		free(tmp);
		return -1;
	}
	fprintf(f, "# generated by demiurge from configure.ac\n");
	if (a->hdrs.len) {
		s = join_list(&a->hdrs);
		fprintf(f, "CHECK_HEADER=%s\n", s);
		free(s);
	}
	if (a->funcs.len) {
		s = join_list(&a->funcs);
		fprintf(f, "CHECK_FUNC=%s\n", s);
		free(s);
	}
	if (a->replace_funcs.len) {
		s = join_list(&a->replace_funcs);
		fprintf(f, "REPLACE_FUNC=%s\n", s);
		free(s);
	}
	if (a->config_files.len) {
		s = join_list(&a->config_files);
		fprintf(f, "CONFIG_FILES=%s\n", s);
		free(s);
	}
	if (a->config_headers.len) {
		s = join_list(&a->config_headers);
		fprintf(f, "CONFIG_HEADERS=%s\n", s);
		free(s);
	}
	if (a->libs.len) {
		s = join_list(&a->libs);
		fprintf(f, "CHECK_LIB=%s\n", s);
		free(s);
	}
	if (a->decls.len) {
		s = join_list(&a->decls);
		fprintf(f, "CHECK_DECL=%s\n", s);
		free(s);
	}
	if (a->pkgs.len) {
		s = join_list(&a->pkgs);
		fprintf(f, "CHECK_PKG=%s\n", s);
		fprintf(f, "EXTRA_PKG=%s\n", s);
		free(s);
	}
	if (a->endians.len) {
		s = join_list(&a->endians);
		fprintf(f, "CHECK_ENDIAN=%s\n", s);
		free(s);
	}
	for (size_t i = 0; i < a->defs.len; i++) {
		char *d = vec_get(&a->defs, i);
		const char *val;
		if (!d || !*d)
			continue;
		val = def_get(a, d);
		if (!val)
			continue;
		fprintf(f, "DEF_%s=%s\n", d, val ? val : "");
	}
	for (size_t i = 0; i < a->subst.len; i++) {
		char *v = vec_get(&a->subst, i);
		const char *val;
		if (!v || !*v)
			continue;
		val = auto_get_val(a, v);
		if (val && *val)
			resolved++;
		else
			defaulted++;
		fprintf(f, "%s=%s\n", v, val ? val : "");
	}
	for (size_t i = 0; i < a->conds.len; i++) {
		char *c = vec_get(&a->conds, i);
		if (c && *c)
			fprintf(f, "COND_%s=0\n", c);
	}
	fclose(f);
	chmod(tmp, 0644);
	if (rename(tmp, out) != 0) {
		fprintf(stderr, "demiurge: %s: %s\n", out, strerror(errno));
		unlink(tmp);
		free(out);
		free(tmp);
		return -1;
	}
	fprintf(stderr, "demiurge: wrote %s (%zu resolved, %zu defaulted)\n",
		out, resolved, defaulted);
	free(out);
	free(tmp);
	return 0;
}

static char *find_configure(const char *root)
{
	char *path;

	path = path_join(root, "configure.ac");
	if (access(path, R_OK) == 0)
		return path;
	free(path);
	path = path_join(root, "configure.in");
	if (access(path, R_OK) == 0)
		return path;
	free(path);
	return NULL;
}

int main(int argc, char **argv)
{
	const char *root = ".";
	struct Auto a;
	char *path;
	int rc;

	if (access("/sys/lib/ape/satan.conf", R_OK) != 0) {
		fprintf(stderr, "demiurge: missing /sys/lib/ape/satan.conf (run satan configure)\n");
		return 1;
	}

	if (argc > 1)
		root = argv[1];
	path = find_configure(root);
	if (!path) {
		fprintf(stderr, "demiurge: %s: missing configure.ac\n", root);
		return 1;
	}
	auto_init(&a);
	set_dir_defaults(&a);
	rc = parse_configure(&a, path);
	if (rc != 0) {
		fprintf(stderr, "demiurge: %s: parse failed\n", path);
		free(path);
		auto_free(&a);
		return 1;
	}
	free(path);
	set_dir_defaults(&a);
	scan_subst_tree(&a, root, NULL);
	rc = write_auto(root, &a);
	auto_free(&a);
	return rc == 0 ? 0 : 1;
}
