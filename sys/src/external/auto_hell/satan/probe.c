#include "probe.h"
#include "str.h"
#include "util.h"

#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

struct ProbeLogEntry {
	char *kind;
	char *name;
	int ok;
};

static void probe_log_entry_free(void *p)
{
	struct ProbeLogEntry *e = p;
	if (!e)
		return;
	free(e->kind);
	free(e->name);
	free(e);
}

static void probe_emit_now(struct GenCtx *g, const char *kind, const char *name, int ok)
{
	size_t total;

	g->probe_done++;
	if (g->probe_done > g->probe_total)
		g->probe_total = g->probe_done;
	total = g->probe_total ? g->probe_total : g->probe_done;
	if (!name)
		name = "";
	fprintf(stderr, "[%zu/%zu] %s %s -> %s\n", g->probe_done, total,
		kind ? kind : "probe", name, ok ? "OK" : "FAIL");
}

static void probe_emit(struct GenCtx *g, const char *kind, const char *name, int ok)
{
	struct ProbeLogEntry *e;

	if (!g || !g->probe_quiet) {
		probe_emit_now(g, kind, name, ok);
		return;
	}
	e = xmalloc(sizeof(*e));
	e->kind = xstrdup(kind ? kind : "probe");
	e->name = xstrdup(name ? name : "");
	e->ok = ok ? 1 : 0;
	vec_push(&g->probe_log, e);
}

void probe_log_free(struct GenCtx *g)
{
	if (!g)
		return;
	vec_free(&g->probe_log, probe_log_entry_free);
}

void probe_log_flush(struct GenCtx *g)
{
	if (!g)
		return;
	for (size_t i = 0; i < g->probe_log.len; i++) {
		struct ProbeLogEntry *e = vec_get(&g->probe_log, i);
		if (!e)
			continue;
		probe_emit_now(g, e->kind, e->name, e->ok);
	}
	vec_free(&g->probe_log, probe_log_entry_free);
	vec_init(&g->probe_log);
}

static size_t count_words_str(const char *s)
{
	struct Vec words;
	size_t n;

	if (!s || !*s)
		return 0;
	split_words(&words, s);
	n = words.len;
	vec_free(&words, free);
	return n;
}

static const char *probe_kind_name(enum ProbeKind kind)
{
	switch (kind) {
	case PROBE_HEADER:
		return "header";
	case PROBE_FUNC:
		return "func";
	case PROBE_LIB:
		return "lib";
	case PROBE_DECL:
		return "decl";
	default:
		return "probe";
	}
}

static int probe_jobs(struct GenCtx *g)
{
	long n;
	int jobs;

	jobs = conf_get_int(g->conf, "PROBE_JOBS", 0);
	if (jobs > 0)
		return jobs;
	n = sysconf(_SC_NPROCESSORS_ONLN);
	if (n > 0 && n < INT32_MAX)
		return (int)n;
	return 1;
}

static char *header_cond_key(const char *hdr)
{
	struct Str key;
	size_t n;

	if (!hdr || !*hdr)
		return NULL;
	str_init(&key);
	str_add(&key, "HAVE_");
	n = strlen(hdr);
	for (size_t i = 0; i < n; i++) {
		unsigned char c = (unsigned char)hdr[i];
		if (isalnum(c))
			str_addc(&key, (char)toupper(c));
		else
			str_addc(&key, '_');
	}
	str_add(&key, "_H");
	return str_finish(&key);
}

static int cond_is_true(struct GenCtx *g, const char *key)
{
	void *v;

	v = map_get(&g->conds, key);
	if (!v)
		return 0;
	return (int)(intptr_t)v != 0;
}

static void add_include(struct Str *out, struct Map *seen, const char *hdr)
{
	if (!hdr || !*hdr)
		return;
	if (map_has(seen, hdr))
		return;
	map_set(seen, hdr, (void *)1);
	str_add(out, "#include <");
	str_add(out, hdr);
	str_add(out, ">\n");
}

static int pkgconf_exists(const char *pc, const char *pkg)
{
	char cmd[512];
	int rc;

	snprintf(cmd, sizeof(cmd), "%s --exists %s > /dev/null 2>&1", pc, pkg);
	rc = system(cmd);
	if (rc == -1)
		return 0;
	if (!WIFEXITED(rc))
		return 0;
	return WEXITSTATUS(rc) == 0;
}

static char *pkgconf_out(const char *pc, const char *args, const char *pkg)
{
	char cmd[512];
	FILE *p;
	char buf[4096];
	struct Str out;

	snprintf(cmd, sizeof(cmd), "%s %s %s", pc, args, pkg);
	p = popen(cmd, "r");
	if (!p)
		return NULL;
	str_init(&out);
	while (fgets(buf, sizeof(buf), p))
		str_add(&out, buf);
	pclose(p);
	if (out.s)
		str_trim(out.s);
	return str_finish(&out);
}

int probe_pkgconf(struct GenCtx *g, const char *list, int add_flags)
{
	struct Vec words;
	const char *pc;

	pc = conf_get(g->conf, "PKGCONF");
	if (!pc)
		pc = "pkgconf";
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *pkg = vec_get(&words, i);
		char *upper;
		struct Str key;

		if (!pkgconf_exists(pc, pkg)) {
			probe_emit(g, "pkgconf", pkg, 0);
			fprintf(stderr, "satan: missing pkgconf package %s\n", pkg);
			vec_free(&words, free);
			return -1;
		}
		probe_emit(g, "pkgconf", pkg, 1);
		upper = xstrdup(pkg);
		for (char *p = upper; *p; p++) {
			if (isalnum((unsigned char)*p))
				*p = (char)toupper((unsigned char)*p);
			else
				*p = '_';
		}
		str_init(&key);
		str_add(&key, "HAVE_PKG_");
		str_add(&key, upper);
		{
			char *cond = str_finish(&key);
			map_set(&g->conds, cond, (void *)1);
			free(cond);
		}
		free(upper);

		if (add_flags) {
			char *cflags = pkgconf_out(pc, "--cflags", pkg);
			char *libs = pkgconf_out(pc, "--libs --static", pkg);
			{
				char *joined = str_join_space(g->conf->pkg_cflags, cflags);
				free(g->conf->pkg_cflags);
				g->conf->pkg_cflags = joined;
			}
			{
				char *joined = str_join_space(g->conf->pkg_libs, libs);
				free(g->conf->pkg_libs);
				g->conf->pkg_libs = joined;
			}
			free(cflags);
			free(libs);
		}
	}
	vec_free(&words, free);
	return 0;
}

static int run_probe_cmd(const char *cmd)
{
	int rc = system(cmd);
	int status = 0;
	if (rc == -1)
		return 0;
	if (!WIFEXITED(rc))
		return 0;
	status = WEXITSTATUS(rc) == 0;
	return status;
}

static int probe_header_raw(struct GenCtx *g, const char *hdr)
{
	char src[] = "/tmp/satan_hdr_XXXXXX";
	char obj[] = "/tmp/satan_obj_XXXXXX";
	char cmd[1024];
	int fd;
	FILE *f;
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	int ok;

	/* fuck off garbage */
	if (cppflags && (!*cppflags || *cppflags < ' '))
		cppflags = NULL;
	if (cflags && (!*cflags || *cflags < ' '))
		cflags = NULL;
	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;

	fd = mkstemp(src);
	if (fd < 0)
		return 0;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return 0;
	}
	fprintf(f, "#include <%s>\nint main(void){return 0;}\n", hdr);
	fclose(f);
	fd = mkstemp(obj);
	if (fd < 0) {
		unlink(src);
		return 0;
	}
	close(fd);

	snprintf(cmd, sizeof(cmd), "%s -x c -c %s -o %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", src, obj,
			cppflags ? cppflags : "",
			cflags ? cflags : "");

	ok = run_probe_cmd(cmd);
	unlink(src);
	unlink(obj);
	return ok;
}

int probe_header(struct GenCtx *g, const char *hdr)
{
	int ok = probe_header_raw(g, hdr);
	probe_emit(g, "header", hdr, ok);
	return ok;
}

static int probe_func_raw(struct GenCtx *g, const char *fn)
{
	char src[] = "/tmp/satan_fn_XXXXXX";
	char bin[] = "/tmp/satan_fn_XXXXXX";
	char cmd[1024];
	int fd;
	int ok;
	FILE *f;
	const char *cc = conf_get(g->conf, "CC");
	int fully = conf_get_int(g->conf, "FULLY_STATIC", 1);
	int use_static = fully && g->probe_static_ok;
	const char *sflag = use_static ? "-static" : "";
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	const char *ldflags = conf_get(g->conf, "LDFLAGS");

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
	if (fd < 0) {
		return 0;
	}
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return 0;
	}
	fprintf(f, "int %s(void);\nint main(void){ (void)%s(); return 0; }\n", fn, fn);
	fclose(f);
	fd = mkstemp(bin);
	if (fd < 0) {
		unlink(src);
		return 0;
	}
	close(fd);

	/* dont escape flags or theyd become one arg */
	snprintf(cmd, sizeof(cmd), "%s -x c %s -o %s %s %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", src, bin,
			cppflags ? cppflags : "",
			cflags ? cflags : "",
			ldflags ? ldflags : "",
			sflag ? sflag : "");
	ok = run_probe_cmd(cmd);
	unlink(src);
	unlink(bin);
	return ok;
}

int probe_func(struct GenCtx *g, const char *fn)
{
	int ok = probe_func_raw(g, fn);
	probe_emit(g, "func", fn, ok);
	return ok;
}

static int probe_lib_raw(struct GenCtx *g, const char *lib)
{
	char src[] = "/tmp/satan_lib_XXXXXX";
	char bin[] = "/tmp/satan_lib_XXXXXX";
	char cmd[1024];
	int fd;
	FILE *f;
	const char *cc = conf_get(g->conf, "CC");
	int fully = conf_get_int(g->conf, "FULLY_STATIC", 1);
	int use_static = fully && g->probe_static_ok;
	const char *sflag = use_static ? "-static" : "";
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	const char *ldflags = conf_get(g->conf, "LDFLAGS");
	int ok;

	fd = mkstemp(src);
	if (fd < 0)
		return 0;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return 0;
	}
	fprintf(f, "int main(void){return 0;}\n");
	fclose(f);
	fd = mkstemp(bin);
	if (fd < 0) {
		unlink(src);
		return 0;
	}
	close(fd);

	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;
	if (ldflags && str_has_bad_chars(ldflags))
		ldflags = NULL;

	snprintf(cmd, sizeof(cmd), "%s -x c %s -o %s -l%s %s %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", src, bin, lib,
			cppflags ? cppflags : "",
			cflags ? cflags : "",
			ldflags ? ldflags : "",
			sflag);

	ok = run_probe_cmd(cmd);
	unlink(src);
	unlink(bin);
	return ok;
}

int probe_lib(struct GenCtx *g, const char *lib)
{
	int ok = probe_lib_raw(g, lib);
	probe_emit(g, "lib", lib, ok);
	return ok;
}

static int probe_decl_raw(struct GenCtx *g, const char *sym)
{
	char src[] = "/tmp/satan_decl_XXXXXX";
	char obj[] = "/tmp/satan_obj_XXXXXX";
	char cmd[1024];
	int fd;
	FILE *f;
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	int ok;

	fd = mkstemp(src);
	if (fd < 0)
		return 0;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return 0;
	}
	fprintf(f,
		"#include <sys/types.h>\n"
		"#include <sys/stat.h>\n"
		"#include <sys/time.h>\n"
		"#include <fcntl.h>\n"
		"#include <stdint.h>\n"
		"#include <inttypes.h>\n"
		"#include <limits.h>\n"
		"#include <stddef.h>\n"
		"#include <unistd.h>\n"
		"#include <stdlib.h>\n"
		"#include <string.h>\n"
		"#include <errno.h>\n"
		"#include <wchar.h>\n"
		"#include <time.h>\n"
		"int main(void){ (void)%s; return 0; }\n", sym);
	fclose(f);
	fd = mkstemp(obj);
	if (fd < 0) {
		unlink(src);
		return 0;
	}
	close(fd);

	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;

	snprintf(cmd, sizeof(cmd), "%s -x c -c %s -o %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", src, obj,
			cppflags ? cppflags : "",
			cflags ? cflags : "");

	ok = run_probe_cmd(cmd);
	unlink(src);
	unlink(obj);
	return ok;
}

int probe_decl(struct GenCtx *g, const char *sym)
{
	int ok = probe_decl_raw(g, sym);
	probe_emit(g, "decl", sym, ok);
	return ok;
}

static int probe_run_raw(struct GenCtx *g, enum ProbeKind kind, const char *name)
{
	switch (kind) {
	case PROBE_HEADER:
		return probe_header_raw(g, name);
	case PROBE_FUNC:
		return probe_func_raw(g, name);
	case PROBE_LIB:
		return probe_lib_raw(g, name);
	case PROBE_DECL:
		return probe_decl_raw(g, name);
	default:
		return 0;
	}
}

static char *cmake_header_name(const char *name)
{
	size_t n;
	char *base, *out;

	if (!starts_with(name, "HAVE_") || !ends_with(name, "_H"))
		return NULL;
	if (starts_with(name, "HAVE_DECL_"))
		return NULL;
	n = strlen(name);
	if (n <= 7)
		return NULL;
	base = xstrndup(name + 5, n - 7);
	for (char *p = base; *p; p++) {
		if (*p == '_')
			*p = '/';
		else
			*p = (char)tolower((unsigned char)*p);
	}
	out = xmalloc(strlen(base) + 3);
	snprintf(out, strlen(base) + 3, "%s.h", base);
	free(base);
	return out;
}

static char *cmake_lib_name(const char *name)
{
	char *out;

	if (!starts_with(name, "HAVE_LIB"))
		return NULL;
	if (!name[8])
		return NULL;
	out = xstrdup(name + 8);
	for (char *p = out; *p; p++)
		*p = (char)tolower((unsigned char)*p);
	return out;
}

static char *cmake_func_name(const char *name)
{
	char *out;

	if (!starts_with(name, "HAVE_"))
		return NULL;
	if (starts_with(name, "HAVE_DECL_"))
		return NULL;
	if (starts_with(name, "HAVE_LIB") || ends_with(name, "_H"))
		return NULL;
	out = xstrdup(name + 5);
	for (char *p = out; *p; p++)
		*p = (char)tolower((unsigned char)*p);
	return out;
}

size_t probe_count_cmake_pending(struct GenCtx *g, const char *tmpl)
{
	FILE *in;
	char line[4096];
	size_t count = 0;

	in = fopen(tmpl, "r");
	if (!in)
		return 0;
	while (fgets(line, sizeof(line), in)) {
		char *p;
		char name[256];
		size_t i;
		char *hdr;
		char *lib;
		char *fn;

		if (strncmp(line, "#cmakedefine", 12) != 0)
			continue;
		p = line + 12;
		while (*p && isspace((unsigned char)*p))
			p++;
		if (!*p)
			continue;
		i = 0;
		while (*p && !isspace((unsigned char)*p) && i + 1 < sizeof(name))
			name[i++] = *p++;
		name[i] = '\0';
		if (!*name)
			continue;
		if (map_has(&g->conds, name))
			continue;
		if (starts_with(name, "HAVE_DECL_")) {
			count++;
			continue;
		}
		hdr = cmake_header_name(name);
		if (hdr) {
			free(hdr);
			count++;
			continue;
		}
		lib = cmake_lib_name(name);
		if (lib) {
			free(lib);
			count++;
			continue;
		}
		fn = cmake_func_name(name);
		if (fn) {
			free(fn);
			count++;
			continue;
		}
	}
	fclose(in);
	return count;
}

int probe_cmake_defs(struct GenCtx *g, const char *tmpl)
{
	FILE *in;
	char line[4096];

	in = fopen(tmpl, "r");
	if (!in)
		return -1;
	while (fgets(line, sizeof(line), in)) {
		char *p;
		char name[256];
		size_t i;
		char *hdr;
		char *lib;
		int ok;

		if (strncmp(line, "#cmakedefine", 12) != 0)
			continue;
		p = line + 12;
		while (*p && isspace((unsigned char)*p))
			p++;
		if (!*p)
			continue;
		i = 0;
		while (*p && !isspace((unsigned char)*p) && i + 1 < sizeof(name))
			name[i++] = *p++;
		name[i] = '\0';
		if (!*name)
			continue;
		if (map_has(&g->conds, name))
			continue;
		if (starts_with(name, "HAVE_DECL_")) {
			ok = probe_decl(g, name + 10);
			map_set(&g->conds, name, (void *)(intptr_t)(ok ? 1 : 0));
			continue;
		}
		hdr = cmake_header_name(name);
		if (hdr) {
			ok = probe_header(g, hdr);
			map_set(&g->conds, name, (void *)(intptr_t)(ok ? 1 : 0));
			free(hdr);
			continue;
		}
		lib = cmake_lib_name(name);
		if (lib) {
			ok = probe_lib(g, lib);
			if (ok && strcmp(name, "HAVE_LIBCHARSET") == 0) {
				if (!probe_iconv_version(g))
					ok = 0;
			}
			map_set(&g->conds, name, (void *)(intptr_t)(ok ? 1 : 0));
			free(lib);
			continue;
		}
		{
			char *fn = cmake_func_name(name);
			if (fn) {
				ok = probe_decl(g, fn);
				map_set(&g->conds, name, (void *)(intptr_t)(ok ? 1 : 0));
				free(fn);
				continue;
			}
		}
	}
	fclose(in);
	return 0;
}

void probe_count_init(struct GenCtx *g, const char *root)
{
	size_t total = 0;

	(void)root;
	total += count_words_str(conf_get(g->conf, "EXTRA_PKG"));
	total += count_words_str(conf_get(g->conf, "CHECK_PKG"));
	total += count_words_str(conf_get(g->conf, "CHECK_HEADER"));
	total += count_words_str(conf_get(g->conf, "CHECK_FUNC"));
	total += count_words_str(conf_get(g->conf, "REPLACE_FUNC"));
	total += count_words_str(conf_get(g->conf, "CHECK_LIB"));
	total += count_words_str(conf_get(g->conf, "CHECK_DECL"));
	total += 20; /* std headers */
	total += 3;  /* std funcs */
	total += 1;  /* SAFE_TO_DEFINE_EXTENSIONS */
	if (conf_get_int(g->conf, "FULLY_STATIC", 1))
		total += 1; /* static link check */

	g->probe_total = total;
	g->probe_done = 0;
}

void probe_static_init(struct GenCtx *g)
{
	char srcpath[] = "/tmp/satan_static_XXXXXX";
	char binpath[] = "/tmp/satan_bin_XXXXXX";
	char cmd[1024];
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	const char *ldflags = conf_get(g->conf, "LDFLAGS");
	int fully = conf_get_int(g->conf, "FULLY_STATIC", 1);
	int fd;
	FILE *f;
	int ok = 0;
	int have_src = 0;
	int have_bin = 0;

	if (!fully) {
		g->probe_static_ok = 0;
		return;
	}
	g->probe_static_ok = 0;
	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;
	if (ldflags && str_has_bad_chars(ldflags))
		ldflags = NULL;

	fd = mkstemp(srcpath);
	if (fd < 0)
		goto fail;
	have_src = 1;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		goto fail;
	}
	fputs("int main(void){return 0;}\n", f);
	fclose(f);
	fd = mkstemp(binpath);
	if (fd < 0) {
		goto fail;
	}
	have_bin = 1;
	close(fd);

	snprintf(cmd, sizeof(cmd), "%s -x c %s -o %s %s %s %s -static > /dev/null 2>&1",
			cc ? cc : "clang", srcpath, binpath,
			cppflags ? cppflags : "",
			cflags ? cflags : "",
			ldflags ? ldflags : "");
	ok = run_probe_cmd(cmd);
	g->probe_static_ok = ok ? 1 : 0;
	if (!ok)
		warn_once(g, "static probe failed, using dynamic for probe checks");
	probe_emit(g, "static", "link", ok);

	if (have_src)
		unlink(srcpath);
	if (have_bin)
		unlink(binpath);
	return;

fail:
	if (have_src)
		unlink(srcpath);
	if (have_bin)
		unlink(binpath);
	warn_once(g, "static probe failed, using dynamic for probe checks");
	probe_emit(g, "static", "link", 0);
}

static void set_have_cond(struct GenCtx *g, const char *name, int val)
{
	char *up = xstrdup(name);
	struct Str key;

	for (char *p = up; *p; p++) {
		if (isalnum((unsigned char)*p))
			*p = (char)toupper((unsigned char)*p);
		else
			*p = '_';
	}
	str_init(&key);
	str_add(&key, "HAVE_");
	str_add(&key, up);
	{
		char *cond = str_finish(&key);
		map_set(&g->conds, cond, (void *)(intptr_t)(val ? 1 : 0));
		free(cond);
	}
	free(up);
}

static void set_have_decl_cond(struct GenCtx *g, const char *name, int val);

struct ProbeChild {
	pid_t pid;
	size_t idx;
};

static int probe_words_parallel(struct GenCtx *g, struct Vec *words, enum ProbeKind kind, int *results)
{
	size_t n;
	size_t next = 0;
	size_t done = 0;
	size_t active = 0;
	int jobs;
	int fork_failed = 0;
	struct ProbeChild *children;

	n = words->len;
	if (n == 0)
		return 0;
	jobs = probe_jobs(g);
	if (jobs <= 1 || n < 2) {
		const char *label = probe_kind_name(kind);
		for (size_t i = 0; i < n; i++) {
			char *w = vec_get(words, i);
			int ok = probe_run_raw(g, kind, w);
			results[i] = ok;
			probe_emit(g, label, w, ok);
		}
		return 0;
	}

	children = xmalloc((size_t)jobs * sizeof(*children));
	while (done < n) {
		while (!fork_failed && active < (size_t)jobs && next < n) {
			pid_t pid = fork();
			if (pid == 0) {
				char *w = vec_get(words, next);
				int ok = probe_run_raw(g, kind, w);
				_exit(ok ? 0 : 1);
			}
			if (pid < 0) {
				fork_failed = 1;
				break;
			}
			children[active].pid = pid;
			children[active].idx = next;
			active++;
			next++;
		}
		if (active == 0 && fork_failed) {
			const char *label = probe_kind_name(kind);
			for (size_t i = next; i < n; i++) {
				char *w = vec_get(words, i);
				int ok = probe_run_raw(g, kind, w);
				results[i] = ok;
				probe_emit(g, label, w, ok);
			}
			break;
		}
		{
			int status = 0;
			pid_t pid = waitpid(-1, &status, 0);
			if (pid < 0) {
				if (errno == EINTR)
					continue;
				fork_failed = 1;
				active = 0;
				continue;
			}
			for (size_t i = 0; i < active; i++) {
				if (children[i].pid == pid) {
					size_t idx = children[i].idx;
					int ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
					results[idx] = ok;
					probe_emit(g, probe_kind_name(kind), vec_get(words, idx), ok);
					children[i] = children[active - 1];
					active--;
					done++;
					break;
				}
			}
		}
	}

	free(children);
	return 0;
}

int probe_list(struct GenCtx *g, const char *key, int (*fn)(struct GenCtx *, const char *))
{
	const char *list = conf_get(g->conf, key);
	struct Vec words;

	if (!list || !*list)
		return 0;
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		set_have_cond(g, w, fn(g, w) ? 1 : 0);
	}
	vec_free(&words, free);
	return 0;
}

int probe_list_parallel(struct GenCtx *g, const char *key, enum ProbeKind kind)
{
	const char *list = conf_get(g->conf, key);
	struct Vec words;
	int *results;

	if (!list || !*list)
		return 0;
	split_words(&words, list);
	results = xmalloc(words.len * sizeof(*results));
	memset(results, 0, words.len * sizeof(*results));
	probe_words_parallel(g, &words, kind, results);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		if (kind == PROBE_DECL)
			set_have_decl_cond(g, w, results[i] ? 1 : 0);
		else
			set_have_cond(g, w, results[i] ? 1 : 0);
	}
	free(results);
	vec_free(&words, free);
	return 0;
}

int probe_replace_funcs(struct GenCtx *g, const char *key)
{
	const char *list = conf_get(g->conf, key);
	struct Vec words;

	if (!list || !*list)
		return 0;
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		int has_func = probe_func(g, w);
		set_have_cond(g, w, has_func ? 1 : 0);
		/* add replacement .c if missing */
		if (!has_func) {
			char *src = xmalloc(strlen(w) + 3);
			sprintf(src, "%s.c", w);
			vec_push(&g->replace_srcs, src);
		}
	}
	vec_free(&words, free);
	return 0;
}

int probe_replace_funcs_parallel(struct GenCtx *g, const char *key)
{
	const char *list = conf_get(g->conf, key);
	struct Vec words;
	int *results;

	if (!list || !*list)
		return 0;
	split_words(&words, list);
	results = xmalloc(words.len * sizeof(*results));
	memset(results, 0, words.len * sizeof(*results));
	probe_words_parallel(g, &words, PROBE_FUNC, results);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		int has_func = results[i];
		set_have_cond(g, w, has_func ? 1 : 0);
		if (!has_func) {
			char *src = xmalloc(strlen(w) + 3);
			sprintf(src, "%s.c", w);
			vec_push(&g->replace_srcs, src);
		}
	}
	free(results);
	vec_free(&words, free);
	return 0;
}

static void set_have_decl_cond(struct GenCtx *g, const char *name, int val)
{
	char *up = xstrdup(name);
	struct Str key;

	for (char *p = up; *p; p++) {
		if (isalnum((unsigned char)*p))
			*p = (char)toupper((unsigned char)*p);
		else
			*p = '_';
	}
	str_init(&key);
	str_add(&key, "HAVE_DECL_");
	str_add(&key, up);
	{
		char *cond = str_finish(&key);
		map_set(&g->conds, cond, (void *)(intptr_t)(val ? 1 : 0));
		free(cond);
	}
	free(up);
}

int probe_list_decl(struct GenCtx *g, const char *key)
{
	const char *list = conf_get(g->conf, key);
	struct Vec words;

	if (!list || !*list)
		return 0;
	split_words(&words, list);
	for (size_t i = 0; i < words.len; i++) {
		char *w = vec_get(&words, i);
		set_have_decl_cond(g, w, probe_decl(g, w) ? 1 : 0);
	}
	vec_free(&words, free);
	return 0;
}

void probe_std_headers(struct GenCtx *g)
{
	const char *hdrs[] = {
		"stdlib.h",
		"string.h",
		"errno.h",
		"limits.h",
		"stdarg.h",
		"stddef.h",
		"stdio.h",
		"ctype.h",
		"time.h",
		"sys/types.h",
		"sys/stat.h",
		"sys/time.h",
		"sys/param.h",
		"unistd.h",
		"fcntl.h",
		"pwd.h",
		"grp.h",
		"stdint.h",
		"inttypes.h",
		"wchar.h"
	};
	for (size_t i = 0; i < sizeof(hdrs) / sizeof(hdrs[0]); i++)
		set_have_cond(g, hdrs[i], probe_header(g, hdrs[i]) ? 1 : 0);
}

void probe_std_funcs(struct GenCtx *g)
{
	const char *fns[] = {
		"wcwidth",
		"wcsdup",
		"pledge"
	};
	for (size_t i = 0; i < sizeof(fns) / sizeof(fns[0]); i++)
		set_have_cond(g, fns[i], probe_func(g, fns[i]) ? 1 : 0);
}

int probe_safe_extensions(struct GenCtx *g)
{
	struct Str src;
	struct Map seen;
	struct Vec headers;
	char srcpath[] = "/tmp/satan_ext_XXXXXX";
	char objpath[] = "/tmp/satan_obj_XXXXXX";
	char cmd[1024];
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	int fd;
	FILE *f;
	int ok;

	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;

	str_init(&src);
	str_add(&src, "#define __EXTENSIONS__ 1\n");
	map_init(&seen);
	if (cond_is_true(g, "HAVE_SYS_TYPES_H"))
		add_include(&src, &seen, "sys/types.h");

	vec_init(&headers);
	split_words(&headers, conf_get(g->conf, "CHECK_HEADER"));
	for (size_t i = 0; i < headers.len; i++) {
		char *hdr = vec_get(&headers, i);
		char *key = header_cond_key(hdr);
		if (key) {
			if (cond_is_true(g, key))
				add_include(&src, &seen, hdr);
			free(key);
		}
	}
	vec_free(&headers, free);

	{
		const char *std_hdrs[] = {
			"stdlib.h",
			"string.h",
			"errno.h",
			"limits.h",
			"stdarg.h",
			"stddef.h",
			"stdio.h",
			"ctype.h",
			"time.h",
			"sys/stat.h",
			"sys/time.h",
			"sys/param.h",
			"unistd.h",
			"fcntl.h",
			"pwd.h",
			"grp.h",
			"stdint.h",
			"inttypes.h",
			"wchar.h"
		};
		for (size_t i = 0; i < sizeof(std_hdrs) / sizeof(std_hdrs[0]); i++) {
			char *key = header_cond_key(std_hdrs[i]);
			if (key) {
				if (cond_is_true(g, key))
					add_include(&src, &seen, std_hdrs[i]);
				free(key);
			}
		}
	}
	str_add(&src, "int main(void){return 0;}\n");

	fd = mkstemp(srcpath);
	if (fd < 0) {
		map_free(&seen, NULL);
		str_free(&src);
		return 0;
	}
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		map_free(&seen, NULL);
		str_free(&src);
		return 0;
	}
	fputs(src.s ? src.s : "", f);
	fclose(f);

	fd = mkstemp(objpath);
	if (fd < 0) {
		unlink(srcpath);
		map_free(&seen, NULL);
		str_free(&src);
		return 0;
	}
	close(fd);

	snprintf(cmd, sizeof(cmd), "%s -x c -c %s -o %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", srcpath, objpath,
			cppflags ? cppflags : "",
			cflags ? cflags : "");
	ok = run_probe_cmd(cmd);
	if (ok)
	map_set(&g->conds, "SAFE_TO_DEFINE_EXTENSIONS", (void *)1);
	probe_emit(g, "ext", "SAFE_TO_DEFINE_EXTENSIONS", ok);

	unlink(srcpath);
	unlink(objpath);
	map_free(&seen, NULL);
	str_free(&src);
	return ok;
}

int probe_iconv_version(struct GenCtx *g)
{
	char srcpath[] = "/tmp/satan_iconv_XXXXXX";
	char objpath[] = "/tmp/satan_obj_XXXXXX";
	char cmd[1024];
	const char *cc = conf_get(g->conf, "CC");
	const char *cppflags = conf_get(g->conf, "CPPFLAGS");
	const char *cflags = conf_get(g->conf, "CFLAGS");
	int fd;
	FILE *f;
	int ok;

	if (cppflags && str_has_bad_chars(cppflags))
		cppflags = NULL;
	if (cflags && str_has_bad_chars(cflags))
		cflags = NULL;

	fd = mkstemp(srcpath);
	if (fd < 0)
		return 0;
	f = fdopen(fd, "w");
	if (!f) {
		close(fd);
		return 0;
	}
	fputs("#include <iconv.h>\nint main(void){ (void)_libiconv_version; return 0; }\n", f);
	fclose(f);

	fd = mkstemp(objpath);
	if (fd < 0) {
		unlink(srcpath);
		return 0;
	}
	close(fd);

	snprintf(cmd, sizeof(cmd), "%s -x c -c %s -o %s %s %s > /dev/null 2>&1",
			cc ? cc : "clang", srcpath, objpath,
			cppflags ? cppflags : "",
			cflags ? cflags : "");
	ok = run_probe_cmd(cmd);

	unlink(srcpath);
	unlink(objpath);
	return ok;
}
