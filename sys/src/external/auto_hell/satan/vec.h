#ifndef VEC_H
#define VEC_H

#include <stddef.h>

struct Vec {
	void **v;
	size_t len;
	size_t cap;
};

void vec_init(struct Vec *v);
void vec_free(struct Vec *v, void (*freefn)(void *));
int vec_push(struct Vec *v, void *p);
void *vec_get(const struct Vec *v, size_t i);

#endif
