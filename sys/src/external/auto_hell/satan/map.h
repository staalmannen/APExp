#ifndef MAP_H
#define MAP_H

#include <stddef.h>

struct MapEnt {
	char *k;
	void *v;
	int used;
};

struct Map {
	struct MapEnt *e;
	size_t cap;
	size_t len;
};

void map_init(struct Map *m);
void map_free(struct Map *m, void (*freefn)(void *));
int map_set(struct Map *m, const char *k, void *v);
void *map_get(const struct Map *m, const char *k);
int map_has(const struct Map *m, const char *k);
void map_iter(struct Map *m, void (*fn)(const char *k, void *v, void *arg), void *arg);

#endif
