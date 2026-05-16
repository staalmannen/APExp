#include "map.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>

static unsigned long hash(const char *s)
{
	unsigned long h;

	h = 1469598103934665603ULL;
	while (*s) {
		h ^= (unsigned char)*s++;
		h *= 1099511628211ULL;
	}
	return h;
}

void map_init(struct Map *m)
{
	m->e = NULL;
	m->cap = 0;
	m->len = 0;
}

void map_free(struct Map *m, void (*freefn)(void *))
{
	size_t i;

	if (m->e) {
		for (i = 0; i < m->cap; i++) {
			if (!m->e[i].used)
				continue;
			free(m->e[i].k);
			if (freefn)
				freefn(m->e[i].v);
		}
	}
	free(m->e);
	m->e = NULL;
	m->cap = 0;
	m->len = 0;
}

static int map_rehash(struct Map *m, size_t ncap)
{
	struct MapEnt *old;
	size_t i, ocap;

	old = m->e;
	ocap = m->cap;

	m->e = xmalloc(ncap * sizeof(m->e[0]));
	m->cap = ncap;
	m->len = 0;
	for (i = 0; i < ncap; i++) {
		m->e[i].k = NULL;
		m->e[i].v = NULL;
		m->e[i].used = 0;
	}

	if (old) {
		for (i = 0; i < ocap; i++) {
			if (!old[i].used)
				continue;
			map_set(m, old[i].k, old[i].v);
			free(old[i].k);
		}
		free(old);
	}
	return 0;
}

int map_set(struct Map *m, const char *k, void *v)
{
	unsigned long h;
	size_t i;

	if (!m->cap)
		map_rehash(m, 64);
	if ((m->len + 1) * 10 >= m->cap * 7)
		map_rehash(m, m->cap * 2);

	h = hash(k);
	for (i = 0; i < m->cap; i++) {
		size_t idx = (h + i) & (m->cap - 1);
		if (!m->e[idx].used) {
			m->e[idx].used = 1;
			m->e[idx].k = xstrdup(k);
			m->e[idx].v = v;
			m->len++;
			return 0;
		}
		if (strcmp(m->e[idx].k, k) == 0) {
			m->e[idx].v = v;
			return 0;
		}
	}
	return -1;
}

void *map_get(const struct Map *m, const char *k)
{
	unsigned long h;
	size_t i;

	if (!m->cap)
		return NULL;
	h = hash(k);
	for (i = 0; i < m->cap; i++) {
		size_t idx = (h + i) & (m->cap - 1);
		if (!m->e[idx].used)
			return NULL;
		if (strcmp(m->e[idx].k, k) == 0)
			return m->e[idx].v;
	}
	return NULL;
}

int map_has(const struct Map *m, const char *k)
{
	return map_get(m, k) != NULL;
}

void map_iter(struct Map *m, void (*fn)(const char *k, void *v, void *arg), void *arg)
{
	size_t i;

	if (!m || !m->e || !fn)
		return;
	for (i = 0; i < m->cap; i++) {
		if (!m->e[i].used)
			continue;
		fn(m->e[i].k, m->e[i].v, arg);
	}
}
