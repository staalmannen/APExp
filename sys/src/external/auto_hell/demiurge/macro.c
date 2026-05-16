#include "macro.h"
#include "builtins.h"
#include "str.h"
#include "util.h"

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

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

static void split_words(struct Vec *out, const char *s)
{
	const char *p, *start;

	vec_init(out);
	if (!s)
		return;
	p = s;
	while (*p) {
		while (*p && isspace((unsigned char)*p))
			p++;
		if (!*p)
			break;
		start = p;
		while (*p && !isspace((unsigned char)*p))
			p++;
		vec_push(out, xstrndup(start, (size_t)(p - start)));
	}
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

void macroset_add(struct MacroSet *m, const char *name, const char *body)
{
	char *cur;
	char *dup;

	if (!m || !name || !*name || !body)
		return;
	cur = map_get(&m->bodies, name);
	if (!cur)
		vec_push(&m->names, xstrdup(name));
	dup = xstrdup(body);
	if (cur)
		free(cur);
	map_set(&m->bodies, name, dup);
}

static void macroset_parse_buf(struct MacroSet *m, const char *buf)
{
	static const char *const defs[] = {
		"AC_DEFUN",
		"AC_DEFUN_ONCE",
	};

	if (!m || !buf)
		return;
	for (size_t i = 0; buf[i]; i++) {
		for (size_t di = 0; di < sizeof(defs) / sizeof(defs[0]); di++) {
			const char *name = defs[di];
			size_t j;
			char *args;
			struct Vec argv;
			char *arg;
			char *arg2;

			if (!match_word(buf, i, name))
				continue;
			j = i + strlen(name);
			while (buf[j] && isspace((unsigned char)buf[j]))
				j++;
			if (buf[j] != '(')
				continue;
			args = extract_args(buf, &j);
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
				char *mname = xstrdup(arg);
				char *mbody = NULL;
				strip_quotes(mname);
				if (arg2 && *arg2)
					mbody = xstrdup(arg2);
				if (mbody)
					macroset_add(m, mname, mbody);
				free(mbody);
				free(mname);
			}
			vec_free(&argv, free);
			i = j;
			break;
		}
	}
}

static void macroset_load_file(struct MacroSet *m, const char *path)
{
	char *raw;
	char *buf;

	raw = read_file(path);
	if (!raw)
		return;
	buf = strip_comments(raw);
	free(raw);
	macroset_parse_buf(m, buf);
	free(buf);
}

static int macroset_load_dir(struct MacroSet *m, const char *dir)
{
	DIR *d;
	struct dirent *de;

	if (!dir || !*dir)
		return -1;
	d = opendir(dir);
	if (!d)
		return -1;
	while ((de = readdir(d)) != NULL) {
		char *path;
		struct stat st;
		if (de->d_name[0] == '.')
			continue;
		if (!ends_with(de->d_name, ".m4"))
			continue;
		path = path_join(dir, de->d_name);
		if (stat(path, &st) == 0 && S_ISREG(st.st_mode))
			macroset_load_file(m, path);
		free(path);
	}
	closedir(d);
	return 0;
}

static void macroset_load_env_paths(struct MacroSet *m)
{
	const char *env = getenv("HELL_M4_PATH");
	if (env && *env) {
		char *dup = xstrdup(env);
		char *save = NULL;
		for (char *p = strtok_r(dup, ":", &save); p; p = strtok_r(NULL, ":", &save))
			macroset_load_dir(m, p);
		free(dup);
	}
}

static void macroset_load_macro_dirs(struct MacroSet *m, const char *root,
	const char *buf)
{
	static const char *const keys[] = {
		"AC_CONFIG_MACRO_DIRS",
		"AC_CONFIG_MACRO_DIR",
	};

	if (!buf)
		return;
	for (size_t i = 0; buf[i]; i++) {
		for (size_t ki = 0; ki < sizeof(keys) / sizeof(keys[0]); ki++) {
			const char *name = keys[ki];
			size_t j;
			char *args;
			struct Vec argv;
			char *arg;
			if (!match_word(buf, i, name))
				continue;
			j = i + strlen(name);
			while (buf[j] && isspace((unsigned char)buf[j]))
				j++;
			if (buf[j] != '(')
				continue;
			args = extract_args(buf, &j);
			if (!args)
				continue;
			split_args(&argv, args);
			free(args);
			arg = argv.len > 0 ? vec_get(&argv, 0) : NULL;
			if (arg) {
				struct Vec dirs;
				char *clean = xstrdup(arg);
				strip_brackets(clean);
				strip_quotes(clean);
				split_words(&dirs, clean);
				for (size_t di = 0; di < dirs.len; di++) {
					char *dir = vec_get(&dirs, di);
					char *path = path_join(root, dir);
					macroset_load_dir(m, path);
					free(path);
				}
				vec_free(&dirs, free);
				free(clean);
			}
			vec_free(&argv, free);
			i = j;
			break;
		}
	}
}

void macroset_init(struct MacroSet *m)
{
	vec_init(&m->names);
	map_init(&m->bodies);
}

void macroset_free(struct MacroSet *m)
{
	vec_free(&m->names, free);
	map_free(&m->bodies, free);
}

int macroset_load_project(struct MacroSet *m, const char *config_path,
	const char *config_buf)
{
	char *root;
	char *aclocal;

	if (!m)
		return -1;
	root = path_dir(config_path ? config_path : ".");
	macro_builtins_register(m);
	macroset_load_env_paths(m);
	macroset_load_macro_dirs(m, root, config_buf);
	aclocal = path_join(root, "aclocal.m4");
	macroset_load_file(m, aclocal);
	free(aclocal);
	free(root);
	return 0;
}

static char *join_args(const struct Vec *args)
{
	struct Str out;

	str_init(&out);
	for (size_t i = 0; i < args->len; i++) {
		const char *s = vec_get((struct Vec *)args, i);
		if (!s)
			continue;
		if (out.len)
			str_add(&out, ", ");
		str_add(&out, s);
	}
	return str_finish(&out);
}

static char *macro_expand_body(const char *name, const char *body,
	const struct Vec *args)
{
	struct Str out;
	size_t n;

	if (!body)
		return NULL;
	str_init(&out);
	n = strlen(body);
	for (size_t i = 0; i < n; i++) {
		char c = body[i];
		if (c == '$' && i + 1 < n) {
			char n1 = body[i + 1];
			if (n1 == '$') {
				str_addc(&out, '$');
				i++;
				continue;
			}
			if (n1 == '0') {
				if (name)
					str_add(&out, name);
				i++;
				continue;
			}
			if (isdigit((unsigned char)n1)) {
				int idx = n1 - '0';
				if (idx >= 1 && (size_t)idx <= args->len) {
					const char *s = vec_get((struct Vec *)args, (size_t)(idx - 1));
					if (s)
						str_add(&out, s);
				}
				i++;
				continue;
			}
			if (n1 == '@' || n1 == '*') {
				char *joined = join_args(args);
				if (joined) {
					str_add(&out, joined);
					free(joined);
				}
				i++;
				continue;
			}
		}
		str_addc(&out, c);
	}
	return str_finish(&out);
}

static char *macroset_expand(struct MacroSet *m, const char *name,
	const struct Vec *argv)
{
	const char *body;
	struct Vec args;
	char *exp;

	if (!m || !name || !*name)
		return NULL;
	body = map_get(&m->bodies, name);
	if (!body)
		return NULL;
	vec_init(&args);
	for (size_t i = 0; i < argv->len; i++) {
		char *arg = vec_get((struct Vec *)argv, i);
		char *dup = xstrdup(arg ? arg : "");
		strip_brackets(dup);
		strip_quotes(dup);
		vec_push(&args, dup);
	}
	exp = macro_expand_body(name, body, &args);
	vec_free(&args, free);
	return exp;
}

char *macroset_expand_all(struct MacroSet *m, const char *buf)
{
	struct Str out;
	size_t i;
	size_t n;

	if (!buf)
		return xstrdup("");
	if (!m || m->names.len == 0)
		return xstrdup(buf);
	str_init(&out);
	n = strlen(buf);
	for (i = 0; i < n; ) {
		if (is_word((unsigned char)buf[i])) {
			size_t j = i;
			while (j < n && is_word((unsigned char)buf[j]))
				j++;
			{
				char *name = xstrndup(buf + i, j - i);
				size_t k = j;
				while (k < n && isspace((unsigned char)buf[k]))
					k++;
				if (map_has(&m->bodies, name) && k < n && buf[k] == '(') {
					size_t end = k;
					char *args = extract_args(buf, &end);
					if (args) {
						struct Vec argv;
						char *exp;
						split_args(&argv, args);
						exp = macroset_expand(m, name, &argv);
						if (exp)
							str_add(&out, exp);
						else {
							char *seg = xstrndup(buf + i, (end + 1) - i);
							str_add(&out, seg);
							free(seg);
						}
						free(exp);
						vec_free(&argv, free);
						free(args);
						free(name);
						i = end + 1;
						continue;
					}
				}
				if (map_has(&m->bodies, name) && (k >= n || buf[k] != '(')) {
					struct Vec argv;
					char *exp;
					vec_init(&argv);
					exp = macroset_expand(m, name, &argv);
					if (exp)
						str_add(&out, exp);
					free(exp);
					vec_free(&argv, free);
					free(name);
					i = j;
					continue;
				}
				str_add(&out, name);
				free(name);
			}
			i = j;
			continue;
		}
		str_addc(&out, buf[i]);
		i++;
	}
	return str_finish(&out);
}
