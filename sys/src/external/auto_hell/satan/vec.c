#include "vec.h"
#include "util.h"

#include <stdlib.h>
void vec_init(struct Vec *v)
{
	v->v = NULL;
	v->len = 0;
	v->cap = 0;
}

void vec_free(struct Vec *v, void (*freefn)(void *))
{
	size_t i;

	if (freefn) {
		for (i = 0; i < v->len; i++)
			freefn(v->v[i]);
	}
	free(v->v);
	v->v = NULL;
	v->len = 0;
	v->cap = 0;
}

int vec_push(struct Vec *v, void *p)
{
	if (v->len == v->cap) {
		v->cap = v->cap ? v->cap * 2 : 8;
		v->v = xrealloc(v->v, v->cap * sizeof(v->v[0]));
	}
	v->v[v->len++] = p;
	return 0;
}

void *vec_get(const struct Vec *v, size_t i)
{
	if (!v || i >= v->len)
		return NULL;
	return v->v[i];
}
