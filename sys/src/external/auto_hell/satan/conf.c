#include "conf.h"
#include "str.h"
#include "util.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conf_init(struct Conf *c)
{
	map_init(&c->kv);
	c->pkg_cflags = NULL;
	c->pkg_libs = NULL;
}

void conf_free(struct Conf *c)
{
	free(c->pkg_cflags);
	free(c->pkg_libs);
	map_free(&c->kv, free);
}

int conf_set(struct Conf *c, const char *k, const char *v)
{
	char *old;

	old = map_get(&c->kv, k);
	if (old)
		free(old);
	return map_set(&c->kv, k, xstrdup(v ? v : ""));
}

const char *conf_get(const struct Conf *c, const char *k)
{
	return map_get(&c->kv, k);
}

int conf_get_int(const struct Conf *c, const char *k, int def)
{
	const char *v;
	char *end;
	long n;

	v = conf_get(c, k);
	if (!v || !*v)
		return def;
	n = strtol(v, &end, 10);
	if (*end)
		return def;
	return (int)n;
}

int conf_load(struct Conf *c, const char *path)
{
	FILE *f;
	char buf[4096];
	char *eq, *key, *val;

	f = fopen(path, "r");
	if (!f)
		return -1;
	while (fgets(buf, sizeof(buf), f)) {
		if (buf[0] == '#')
			continue;
		eq = strchr(buf, '=');
		if (!eq)
			continue;
		*eq = '\0';
		key = buf;
		val = eq + 1;
		str_trim(key);
		str_trim(val);
		if (!*key)
			continue;
		conf_set(c, key, val);
	}
	fclose(f);
	return 0;
}

int conf_apply_defaults(struct Conf *c)
{
	if (!conf_get(c, "PREFIX"))
		conf_set(c, "PREFIX", "/usr");
	if (!conf_get(c, "BINDIR"))
		conf_set(c, "BINDIR", "/usr/bin");
	if (!conf_get(c, "SBINDIR"))
		conf_set(c, "SBINDIR", "/usr/sbin");
	if (!conf_get(c, "LIBDIR"))
		conf_set(c, "LIBDIR", "/usr/lib");
	if (!conf_get(c, "INCLUDEDIR"))
		conf_set(c, "INCLUDEDIR", "/usr/include");
	if (!conf_get(c, "MANDIR"))
		conf_set(c, "MANDIR", "/usr/share/man");
	if (!conf_get(c, "PKGCONFIGDIR"))
		conf_set(c, "PKGCONFIGDIR", "/usr/lib/pkgconfig");
	if (!conf_get(c, "CFLAGS"))
		conf_set(c, "CFLAGS", "-O2 -pipe");
	if (!conf_get(c, "CPPFLAGS"))
		conf_set(c, "CPPFLAGS", "");
	if (!conf_get(c, "LDFLAGS"))
		conf_set(c, "LDFLAGS", "");
	return 0;
}
