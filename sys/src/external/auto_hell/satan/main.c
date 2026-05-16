#include "conf.h"
#include "gen.h"
#include "str.h"
#include "util.h"
#include "vec.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static void usage(void)
{
	fprintf(stderr, "usage: satan configure\n");
	fprintf(stderr, "       satan gen [-c] [-j N] [-Dkey=val] [PREFIX=val] [DESTDIR=val] [root]\n");
	fprintf(stderr, "       satan clean [root]\n");
}

static int tool_exists(const char *name)
{
	char *path, *dup, *tok, *full;

	if (strchr(name, '/'))
		return access(name, X_OK) == 0;
	path = getenv("PATH");
	if (!path)
		return 0;
	dup = xstrdup(path);
	for (tok = strtok(dup, ":"); tok; tok = strtok(NULL, ":")) {
		full = path_join(tok, name);
		if (access(full, X_OK) == 0) {
			free(full);
			free(dup);
			return 1;
		}
		free(full);
	}
	free(dup);
	return 0;
}

static char *tool_abs(const char *name)
{
	char *path, *dup, *tok, *full;

	if (!name || !*name)
		return NULL;
	if (strchr(name, '/')) {
		if (access(name, X_OK) == 0)
			return xstrdup(name);
		return NULL;
	}
	path = getenv("PATH");
	if (!path)
		return NULL;
	dup = xstrdup(path);
	for (tok = strtok(dup, ":"); tok; tok = strtok(NULL, ":")) {
		full = path_join(tok, name);
		if (access(full, X_OK) == 0) {
			free(dup);
			return full;
		}
		free(full);
	}
	free(dup);
	return NULL;
}

static const char *pick_tool(const char *a, const char *b)
{
	if (a && tool_exists(a))
		return a;
	if (b && tool_exists(b))
		return b;
	return NULL;
}

static void conf_set_default(struct Conf *conf, const char *k, const char *v)
{
	const char *cur;

	if (!k || !*k || !v)
		return;
	cur = conf_get(conf, k);
	if (cur && *cur)
		return;
	conf_set(conf, k, v);
}

static void conf_set_default_upper(struct Conf *conf, const char *k, const char *v)
{
	char *up;
	size_t n;

	if (!k || !*k || !v)
		return;
	n = strlen(k);
	up = xmalloc(n + 1);
	for (size_t i = 0; i < n; i++) {
		if (isalnum((unsigned char)k[i]))
			up[i] = (char)toupper((unsigned char)k[i]);
		else
			up[i] = '_';
	}
	up[n] = '\0';
	if (strcmp(up, k) != 0)
		conf_set_default(conf, up, v);
	free(up);
}

static int is_placeholder(const char *key, const char *val)
{
	size_t n;

	if (!key || !val)
		return 0;
	n = strlen(key);
	if (strlen(val) != n + 2)
		return 0;
	if (val[0] != '@' || val[n + 1] != '@')
		return 0;
	return strncmp(val + 1, key, n) == 0;
}

struct MergeArg {
	struct Conf *dst;
};

static void merge_cb(const char *k, void *v, void *arg)
{
	struct MergeArg *ma = arg;
	struct Conf *d = ma->dst;
	const char *val = v;
	const char *cur = conf_get(d, k);

	if (is_placeholder(k, val))
		return;
	if ((!val || !*val) && cur && *cur)
		return;
	conf_set(d, k, val ? val : "");
}

static void merge_conf(struct Conf *dst, struct Conf *src)
{
	struct MergeArg ma;

	ma.dst = dst;
	map_iter(&src->kv, merge_cb, &ma);
}

static void override_cb(const char *k, void *v, void *arg)
{
	struct Conf *dst = arg;

	conf_set(dst, k, v ? v : "");
}

static char *strip_quotes(char *s)
{
	size_t n;

	if (!s)
		return NULL;
	str_trim(s);
	n = strlen(s);
	if (n >= 2 && ((s[0] == '"' && s[n - 1] == '"') || (s[0] == '\'' && s[n - 1] == '\''))) {
		memmove(s, s + 1, n - 2);
		s[n - 2] = '\0';
		str_trim(s);
	}
	return s;
}

static void load_version(struct Conf *conf, const char *root)
{
	char *path;
	FILE *f;
	char buf[4096];
	char *eq;
	char *key;
	char *val;
	const char *maj;
	const char *min;
	const char *rel;
	const char *greek;

	path = path_join(root, "VERSION");
	f = fopen(path, "r");
	if (!f) {
		free(path);
		return;
	}
	while (fgets(buf, sizeof(buf), f)) {
		if (buf[0] == '#')
			continue;
		eq = strchr(buf, '=');
		if (!eq)
			continue;
		*eq = '\0';
		key = str_trim(buf);
		val = str_trim(eq + 1);
		if (!*key)
			continue;
		strip_quotes(val);
		conf_set_default(conf, key, val);
		conf_set_default_upper(conf, key, val);
	}
	fclose(f);
	free(path);

	maj = conf_get(conf, "major");
	min = conf_get(conf, "minor");
	rel = conf_get(conf, "release");
	greek = conf_get(conf, "greek");
	if (maj && *maj && min && *min && rel && *rel) {
		char ver[128];
		if (greek && *greek)
			snprintf(ver, sizeof(ver), "%s.%s.%s%s", maj, min, rel, greek);
		else
			snprintf(ver, sizeof(ver), "%s.%s.%s", maj, min, rel);
		conf_set_default(conf, "VERSION", ver);
		conf_set_default(conf, "PACKAGE_VERSION", ver);
	}
}

static char *get_user(void)
{
	const char *u;
	struct passwd *pw;

	u = getenv("USER");
	if (u && *u)
		return xstrdup(u);
	pw = getpwuid(getuid());
	if (pw && pw->pw_name)
		return xstrdup(pw->pw_name);
	return NULL;
}

static char *get_host(void)
{
	char buf[256];

	if (gethostname(buf, sizeof(buf)) == 0) {
		buf[sizeof(buf) - 1] = '\0';
		if (buf[0])
			return xstrdup(buf);
	}
	return NULL;
}

static char *get_date(void)
{
	time_t now;
	struct tm tm;
	char buf[64];

	now = time(NULL);
	if (localtime_r(&now, &tm) == NULL)
		return NULL;
	if (strftime(buf, sizeof(buf), "%Y-%m-%d", &tm) == 0)
		return NULL;
	return xstrdup(buf);
}

static void fill_common(struct Conf *conf, const char *root)
{
	char *user;
	char *host;
	char *date;
	char *abs;
	const char *cc;
	const char *cxx;
	const char *cpp;
	const char *cflags;
	const char *cppflags;
	const char *ldflags;
	user = get_user();
	host = get_host();
	date = get_date();
	if (user)
		conf_set_default(conf, "CONFIGURE_USER", user);
	if (host)
		conf_set_default(conf, "CONFIGURE_HOST", host);
	if (date)
		conf_set_default(conf, "CONFIGURE_DATE", date);
	free(user);
	free(host);
	free(date);

	if (!conf_get(conf, "CXX") || !*conf_get(conf, "CXX")) {
		if (tool_exists("clang++"))
			conf_set(conf, "CXX", "clang++");
		else if (tool_exists("c++"))
			conf_set(conf, "CXX", "c++");
	}
	cc = conf_get(conf, "CC");
	cxx = conf_get(conf, "CXX");
	cpp = conf_get(conf, "CPP");
	cflags = conf_get(conf, "CFLAGS");
	cppflags = conf_get(conf, "CPPFLAGS");
	ldflags = conf_get(conf, "LDFLAGS");

	if (cc) {
		abs = tool_abs(cc);
		if (abs) {
			conf_set_default(conf, "CC_ABSOLUTE", abs);
			free(abs);
		}
	}
	if (cxx) {
		abs = tool_abs(cxx);
		if (abs) {
			conf_set_default(conf, "CXX_ABSOLUTE", abs);
			free(abs);
		}
	}
	if (cpp) {
		abs = tool_abs(cpp);
		if (abs) {
			conf_set_default(conf, "CPP_ABSOLUTE", abs);
			free(abs);
		}
	}
	conf_set_default(conf, "CXXFLAGS", cflags ? cflags : "");
	conf_set_default(conf, "CXXCPPFLAGS", cppflags ? cppflags : "");
	conf_set_default(conf, "FFLAGS", "");
	conf_set_default(conf, "FCFLAGS", "");
	conf_set_default(conf, "LIBS", "");
	conf_set_default(conf, "LDFLAGS", ldflags ? ldflags : "");

	load_version(conf, root);
}

static int write_conf(const char *path, const char *cc, const char *cxx,
		      const char *ar, const char *as, const char *ranlib,
		      const char *ld, const char *strip, const char *objcopy,
		      const char *nm, const char *pc, const char *ninja,
		      const char *lex, const char *yacc, const char *sed,
		      const char *awk, const char *ln_s, const char *grep)
{
	int fd;
	FILE *f;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return -1;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return -1;
	}
	fprintf(f, "# satan system config\n");
	fprintf(f, "CC=%s\n", cc);
	fprintf(f, "CXX=%s\n", cxx);
	fprintf(f, "CPP=%s -E\n", cc);
	fprintf(f, "AR=%s\n", ar);
	fprintf(f, "AS=%s\n", as);
	fprintf(f, "RANLIB=%s\n", ranlib);
	fprintf(f, "LD=%s\n", ld);
	fprintf(f, "STRIP=%s\n", strip);
	fprintf(f, "OBJCOPY=%s\n", objcopy);
	fprintf(f, "NM=%s\n", nm);
	fprintf(f, "PKGCONF=%s\n", pc);
	fprintf(f, "NINJA=%s\n", ninja);
	if (lex && *lex)
		fprintf(f, "LEX=%s\n", lex);
	if (yacc && *yacc)
		fprintf(f, "YACC=%s\n", yacc);
	if (sed && *sed)
		fprintf(f, "SED=%s\n", sed);
	if (awk && *awk)
		fprintf(f, "AWK=%s\n", awk);
	if (ln_s && *ln_s)
		fprintf(f, "LN_S=%s\n", ln_s);
	if (grep && *grep)
		fprintf(f, "GREP=%s\n", grep);
	fprintf(f, "\n# global policy\n");
	fprintf(f, "STATIC=1\n");
	fprintf(f, "FULLY_STATIC=1\n\n");
	fprintf(f, "# filesystem policy\n");
	fprintf(f, "PREFIX=/usr\n");
	fprintf(f, "BINDIR=/usr/bin\n");
	fprintf(f, "SBINDIR=/usr/sbin\n");
	fprintf(f, "LIBDIR=/usr/lib\n");
	fprintf(f, "INCLUDEDIR=/usr/include\n");
	fprintf(f, "MANDIR=/usr/share/man\n");
	fprintf(f, "PKGCONFIGDIR=/usr/lib/pkgconfig\n\n");
	fprintf(f, "# default flags\n");
	fprintf(f, "CFLAGS=-O2 -pipe\n");
	fprintf(f, "CXXFLAGS=\n");
	fprintf(f, "CPPFLAGS=\n");
	fprintf(f, "LDFLAGS=\n");
	if (fclose(f) != 0)
		return -1;
	return 0;
}

static int cmd_configure(void)
{
	const char *cc;
	const char *cxx;
	const char *ar;
	const char *as;
	const char *ranlib;
	const char *ld;
	const char *strip;
	const char *objcopy;
	const char *nm;
	const char *pc;
	const char *ninja;
	const char *lex;
	const char *yacc;
	const char *sed;
	const char *awk;
	const char *ln_s;
	const char *grep;
	char tmp[256];

	if (geteuid() != 0) {
		fprintf(stderr, "satan: configure requires root\n");
		return 1;
	}

	cc = pick_tool("clang", NULL);
	cxx = pick_tool("clang++", NULL);
	ar = pick_tool("llvm-ar", "ar");
	as = pick_tool("llvm-as", "as");
	ranlib = pick_tool("llvm-ranlib", "ranlib");
	ld = pick_tool("ld", NULL);
	strip = pick_tool("llvm-strip", "strip");
	objcopy = pick_tool("llvm-objcopy", "objcopy");
	nm = pick_tool("llvm-nm", "nm");
	sed = pick_tool("sed", NULL);
	awk = pick_tool("awk", NULL);
	grep = pick_tool("grep", NULL);
	pc = pick_tool("pkgconf", NULL);
	ninja = pick_tool("samu", "ninja");
	lex = pick_tool("reflex", "flex");
	yacc = pick_tool("byacc", "bison");
	ln_s = "ln -s";

	if (!cc || !cxx || !ar || !as || !ranlib || !ld || !strip || !objcopy || !nm || !pc || !ninja || !sed || !awk || !grep) {
		fprintf(stderr, "satan: missing required tools in PATH\n");
		return 1;
	}

	if (!lex)
		fprintf(stderr, "satan: warning: no lex found (reflex or flex), .l sources will fail\n");
	if (!yacc)
		fprintf(stderr, "satan: warning: no yacc found (byacc or bison), .y sources will fail\n");

	snprintf(tmp, sizeof(tmp), "/etc/satan.conf.tmp");
	if (write_conf(tmp, cc, cxx, ar, as, ranlib, ld, strip, objcopy, nm, pc, ninja, lex, yacc, sed, awk, ln_s, grep) != 0) {
		fprintf(stderr, "satan: failed to write %s: %s\n", tmp, strerror(errno));
		return 1;
	}
	if (rename(tmp, "/etc/satan.conf") != 0) {
		fprintf(stderr, "satan: failed to move config into place: %s\n", strerror(errno));
		return 1;
	}
	printf("satan: wrote /etc/satan.conf\n");
	return 0;
}

static void apply_overrides(struct Conf *conf, struct Conf *overrides)
{
	if (!overrides)
		return;
	map_iter(&overrides->kv, override_cb, conf);
}

static int load_conf_common(struct Conf *conf, const char *root, int strict,
			    struct Conf *overrides)
{
	char *local;
	struct Conf override;

	conf_init(conf);
	if (conf_load(conf, "/etc/satan.conf") != 0) {
		if (strict) {
			fprintf(stderr, "satan: missing /etc/satan.conf (run satan configure)\n");
			return -1;
		}
	} else {
		conf_apply_defaults(conf);
	}
	local = path_join(root, ".demiurge");
	if (conf_load(conf, local) == 0)
		conf_apply_defaults(conf);
	free(local);
	local = path_join(root, ".satan");
	conf_init(&override);
	if (conf_load(&override, local) == 0) {
		merge_conf(conf, &override);
		conf_apply_defaults(conf);
	}
	conf_free(&override);
	free(local);
	apply_overrides(conf, overrides);
	if (strict)
		fill_common(conf, root);
	else if (!conf_get(conf, "NINJA"))
		conf_set(conf, "NINJA", "ninja");
	return 0;
}

static int load_conf(struct Conf *conf, const char *root)
{
	return load_conf_common(conf, root, 1, NULL);
}

static void load_conf_best_effort(struct Conf *conf, const char *root)
{
	load_conf_common(conf, root, 0, NULL);
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
	return strcmp(s + n - m, suf) == 0;
}

static int unlink_if_exists(const char *path)
{
	struct stat st;

	if (lstat(path, &st) != 0)
		return 0;
	if (S_ISDIR(st.st_mode))
		return 0;
	if (unlink(path) != 0) {
		fprintf(stderr, "satan: %s: %s\n", path, strerror(errno));
		return -1;
	}
	return 0;
}

static int run_ninja_clean(const char *ninja, const char *dir)
{
	struct Str cmd;
	char *esc_ninja;
	char *esc_dir;
	int rc;

	esc_ninja = shell_escape(ninja && *ninja ? ninja : "ninja");
	esc_dir = shell_escape(dir);
	str_init(&cmd);
	str_add(&cmd, esc_ninja);
	str_add(&cmd, " -C ");
	str_add(&cmd, esc_dir);
	str_add(&cmd, " -t clean");
	rc = system(cmd.s ? cmd.s : "");
	str_free(&cmd);
	free(esc_ninja);
	free(esc_dir);
	if (rc == -1 || !WIFEXITED(rc) || WEXITSTATUS(rc) != 0) {
		fprintf(stderr, "satan: %s: ninja clean failed\n", dir);
		return -1;
	}
	return 0;
}

static int is_space(int c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static int is_comment_word(const char *s)
{
	return s && (s[0] == '#' || (s[0] == '\\' && s[1] == '#'));
}

static void split_words(struct Vec *out, const char *s)
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
			} else {
				vec_push(out, tok);
			}
		}
		if (stop)
			break;
	}
}

static int remove_config_outputs(const char *root, const struct Conf *conf)
{
	const char *list;
	struct Vec files;
	int rc = 0;

	list = conf_get(conf, "CONFIG_FILES");
	if (!list || !*list)
		return 0;
	split_words(&files, list);
	for (size_t i = 0; i < files.len; i++) {
		char *name = vec_get(&files, i);
		char *colon = strchr(name, ':');
		char *outpath;
		if (colon)
			*colon = '\0';
		if (!*name)
			continue;
		outpath = path_join(root, name);
		if (unlink_if_exists(outpath) != 0)
			rc = -1;
		free(outpath);
	}
	vec_free(&files, free);
	return rc;
}

static int clean_walk(const char *dir, const char *ninja)
{
	DIR *d;
	struct dirent *ent;
	int rc = 0;

	d = opendir(dir);
	if (!d)
		return 0;
	while ((ent = readdir(d))) {
		const char *name = ent->d_name;
		char *path;
		struct stat st;

		if (!name || strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
			continue;
		if (strcmp(name, ".git") == 0)
			continue;
		path = path_join(dir, name);
		if (lstat(path, &st) != 0) {
			free(path);
			continue;
		}
		if (S_ISDIR(st.st_mode)) {
			if (clean_walk(path, ninja) != 0)
				rc = -1;
			free(path);
			continue;
		}
		if (strcmp(name, "build.ninja") == 0) {
			if (run_ninja_clean(ninja, dir) != 0)
				rc = -1;
			if (unlink_if_exists(path) != 0)
				rc = -1;
		} else if (strcmp(name, ".ninja_deps") == 0 ||
			strcmp(name, ".ninja_log") == 0) {
			if (unlink_if_exists(path) != 0)
				rc = -1;
		} else if (strcmp(name, "config.h") == 0) {
			if (unlink_if_exists(path) != 0)
				rc = -1;
		} else if (strcmp(name, ".demiurge") == 0) {
			if (unlink_if_exists(path) != 0)
				rc = -1;
		} else if (ends_with(name, ".h.in") && strcmp(name, "config.h.in") != 0) {
			size_t n = strlen(path);
			if (n > 3) {
				char *out = xstrndup(path, n - 3);
				if (unlink_if_exists(out) != 0)
					rc = -1;
				free(out);
			}
		}
		free(path);
	}
	closedir(d);
	return rc;
}

static int cmd_clean(const char *root)
{
	struct Conf conf;
	const char *ninja;
	int rc = 0;

	load_conf_best_effort(&conf, root);
	ninja = conf_get(&conf, "NINJA");
	if (!ninja || !*ninja)
		ninja = "ninja";
	if (clean_walk(root, ninja) != 0)
		rc = 1;
	if (remove_config_outputs(root, &conf) != 0)
		rc = 1;
	conf_free(&conf);
	return rc;
}

static int cmd_gen(const char *root, int jobs, struct Conf *overrides)
{
	struct Conf conf;
	int rc;

	if (load_conf_common(&conf, root, 1, overrides) != 0)
		return 1;
	if (jobs > 0) {
		char buf[32];
		snprintf(buf, sizeof(buf), "%d", jobs);
		conf_set(&conf, "PROBE_JOBS", buf);
	}
	rc = gen_project(root, &conf);
	conf_free(&conf);
	return rc == 0 ? 0 : 1;
}

static int cmd_gen_config(const char *root, struct Conf *overrides)
{
	struct Conf conf;
	int rc;

	if (load_conf_common(&conf, root, 1, overrides) != 0)
		return 1;
	rc = gen_config_only(root, &conf);
	conf_free(&conf);
	return rc == 0 ? 0 : 1;
}

static int parse_jobs_arg(const char *s, int *out)
{
	char *end;
	long n;

	if (!s || !*s)
		return -1;
	n = strtol(s, &end, 10);
	if (*end || n <= 0 || n > INT_MAX)
		return -1;
	*out = (int)n;
	return 0;
}

static char *join_prefix(const char *prefix, const char *suffix)
{
	size_t plen;
	size_t slen;
	char *out;

	if (!prefix)
		prefix = "";
	if (!suffix)
		suffix = "";
	plen = strlen(prefix);
	slen = strlen(suffix);
	out = xmalloc(plen + slen + 2);
	if (plen == 0) {
		snprintf(out, plen + slen + 2, "%s", suffix);
		return out;
	}
	if (prefix[plen - 1] == '/')
		snprintf(out, plen + slen + 2, "%s%s", prefix, suffix);
	else
		snprintf(out, plen + slen + 2, "%s/%s", prefix, suffix);
	return out;
}

static int parse_key_value(const char *s, char **key_out, char **val_out)
{
	const char *eq;
	char *key;
	char *val;

	if (!s)
		return -1;
	eq = strchr(s, '=');
	if (!eq || eq == s)
		return -1;
	key = xstrndup(s, (size_t)(eq - s));
	val = xstrdup(eq + 1);
	*key_out = key;
	*val_out = val;
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
		return 1;
	}
	if (strcmp(argv[1], "configure") == 0)
		return cmd_configure();
	if (strcmp(argv[1], "gen") == 0) {
		const char *root = ".";
		int jobs = 0;
		int root_set = 0;
		int i = 2;
		int prefix_set = 0;
		int config_only = 0;
		struct Conf overrides;
		struct {
			int bindir;
			int sbindir;
			int libexecdir;
			int libdir;
			int includedir;
			int mandir;
		} override_dir = { 0, 0, 0, 0, 0, 0 };

		conf_init(&overrides);

		while (i < argc) {
			if (strcmp(argv[i], "-c") == 0) {
				config_only = 1;
				i++;
				continue;
			}
			if (strcmp(argv[i], "-j") == 0) {
				if (i + 1 >= argc || parse_jobs_arg(argv[i + 1], &jobs) != 0) {
					usage();
					return 1;
				}
				i += 2;
				continue;
			}
			if (strncmp(argv[i], "-j", 2) == 0) {
				if (parse_jobs_arg(argv[i] + 2, &jobs) != 0) {
					usage();
					return 1;
				}
				i++;
				continue;
			}
			if (strncmp(argv[i], "-D", 2) == 0) {
				char *key = NULL;
				char *val = NULL;
				if (parse_key_value(argv[i] + 2, &key, &val) != 0) {
					usage();
					conf_free(&overrides);
					return 1;
				}
				conf_set(&overrides, key, val);
				if (strcmp(key, "PREFIX") == 0)
					prefix_set = 1;
				else if (strcmp(key, "BINDIR") == 0)
					override_dir.bindir = 1;
				else if (strcmp(key, "SBINDIR") == 0)
					override_dir.sbindir = 1;
				else if (strcmp(key, "LIBEXECDIR") == 0)
					override_dir.libexecdir = 1;
				else if (strcmp(key, "LIBDIR") == 0)
					override_dir.libdir = 1;
				else if (strcmp(key, "INCLUDEDIR") == 0)
					override_dir.includedir = 1;
				else if (strcmp(key, "MANDIR") == 0)
					override_dir.mandir = 1;
				free(key);
				free(val);
				i++;
				continue;
			}
			{
				char *key = NULL;
				char *val = NULL;
				if (parse_key_value(argv[i], &key, &val) == 0) {
					if (strcmp(key, "PREFIX") == 0 || strcmp(key, "DESTDIR") == 0) {
						conf_set(&overrides, key, val);
						if (strcmp(key, "PREFIX") == 0)
							prefix_set = 1;
						free(key);
						free(val);
						i++;
						continue;
					}
					free(key);
					free(val);
					usage();
					conf_free(&overrides);
					return 1;
				}
			}
			if (argv[i][0] == '-') {
				usage();
				conf_free(&overrides);
				return 1;
			}
			if (root_set) {
				usage();
				conf_free(&overrides);
				return 1;
			}
			root = argv[i];
			root_set = 1;
			i++;
		}
		if (prefix_set) {
			const char *prefix = conf_get(&overrides, "PREFIX");
			if (prefix && *prefix) {
				if (!override_dir.bindir) {
					char *p = join_prefix(prefix, "bin");
					conf_set(&overrides, "BINDIR", p);
					free(p);
				}
				if (!override_dir.sbindir) {
					char *p = join_prefix(prefix, "sbin");
					conf_set(&overrides, "SBINDIR", p);
					free(p);
				}
				if (!override_dir.libexecdir) {
					char *p = join_prefix(prefix, "libexec");
					conf_set(&overrides, "LIBEXECDIR", p);
					free(p);
				}
				if (!override_dir.libdir) {
					char *p = join_prefix(prefix, "lib");
					conf_set(&overrides, "LIBDIR", p);
					free(p);
				}
				if (!override_dir.includedir) {
					char *p = join_prefix(prefix, "include");
					conf_set(&overrides, "INCLUDEDIR", p);
					free(p);
				}
				if (!override_dir.mandir) {
					char *p = join_prefix(prefix, "share/man");
					conf_set(&overrides, "MANDIR", p);
					free(p);
				}
			}
		}
		{
			int rc = config_only ? cmd_gen_config(root, &overrides)
				: cmd_gen(root, jobs, &overrides);
			conf_free(&overrides);
			return rc;
		}
	}
	if (strcmp(argv[1], "clean") == 0) {
		const char *root = argc > 2 ? argv[2] : ".";
		return cmd_clean(root);
	}
	usage();
	return 1;
}
