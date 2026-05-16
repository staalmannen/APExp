#ifndef CONF_H
#define CONF_H

#include "map.h"

struct Conf {
	struct Map kv;
	char *pkg_cflags;
	char *pkg_libs;
};

void conf_init(struct Conf *c);
void conf_free(struct Conf *c);
int conf_load(struct Conf *c, const char *path);
int conf_set(struct Conf *c, const char *k, const char *v);
const char *conf_get(const struct Conf *c, const char *k);
int conf_get_int(const struct Conf *c, const char *k, int def);
int conf_apply_defaults(struct Conf *c);

#endif
