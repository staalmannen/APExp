#ifndef _OBSTACK_H
#define _OBSTACK_H

#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>
#include <stdarg.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _obstack_chunk {
	char *limit;
	struct _obstack_chunk *prev;
	char contents[4];
};

struct obstack {
	long chunk_size;
	struct _obstack_chunk *chunk;
	char *object_base;
	char *next_free;
	char *chunk_limit;
	union { long tempint; void *tempptr; } temp;
	int alignment_mask;
	struct _obstack_chunk *(*chunkfun)(void *, long);
	void (*freefun)(void *, struct _obstack_chunk *);
	void *extra_arg;
	unsigned use_extra_arg:1;
	unsigned maybe_empty_object:1;
	unsigned alloc_failed:1;
};

extern void (*obstack_alloc_failed_handler)(void);

extern int  _obstack_begin(struct obstack *, int, int,
                           void *(*)(long), void (*)(void *));
extern int  _obstack_begin_1(struct obstack *, int, int,
                              void *(*)(void *, long),
                              void (*)(void *, void *), void *);
extern void _obstack_newchunk(struct obstack *, int);
extern void _obstack_free(struct obstack *, void *);
extern int  _obstack_memory_used(struct obstack *);

extern int obstack_printf(struct obstack *, const char *, ...);
extern int obstack_vprintf(struct obstack *, const char *, va_list);

/* User must define these before using obstack macros:
 *   #define obstack_chunk_alloc  malloc
 *   #define obstack_chunk_free   free
 */

#define obstack_init(h) \
  _obstack_begin((h), 0, 0, \
    (void *(*)(long))obstack_chunk_alloc, \
    (void (*)(void *))obstack_chunk_free)

#define obstack_begin(h, size) \
  _obstack_begin((h), (size), 0, \
    (void *(*)(long))obstack_chunk_alloc, \
    (void (*)(void *))obstack_chunk_free)

#define obstack_specify_allocation(h, size, alignment, chunkfun, freefun) \
  _obstack_begin((h), (size), (alignment), \
    (void *(*)(long))(chunkfun), (void (*)(void *))(freefun))

#define obstack_specify_allocation_with_arg(h, size, alignment, chunkfun, freefun, arg) \
  _obstack_begin_1((h), (size), (alignment), \
    (void *(*)(void *, long))(chunkfun), (void (*)(void *, void *))(freefun), (arg))

/* Object growing */
#define obstack_object_size(h) \
  ((size_t)((h)->next_free - (h)->object_base))

#define obstack_room(h) \
  ((size_t)((h)->chunk_limit - (h)->next_free))

#define obstack_make_room(h, length) \
  ((h)->next_free + (length) > (h)->chunk_limit \
    ? (_obstack_newchunk((h), (length)), 0) : 0)

#define obstack_empty_p(h) \
  ((h)->chunk->prev == 0 \
   && (h)->next_free == (h)->chunk->contents \
     + ((h)->alignment_mask + 1))

#define obstack_grow(h, where, length) \
  do { \
    int __len = (length); \
    if((h)->next_free + __len > (h)->chunk_limit) \
      _obstack_newchunk((h), __len); \
    memcpy((h)->next_free, (where), (size_t)__len); \
    (h)->next_free += __len; \
  } while(0)

#define obstack_grow0(h, where, length) \
  do { \
    int __len = (length); \
    if((h)->next_free + __len + 1 > (h)->chunk_limit) \
      _obstack_newchunk((h), __len + 1); \
    memcpy((h)->next_free, (where), (size_t)__len); \
    (h)->next_free += __len; \
    *((h)->next_free)++ = '\0'; \
  } while(0)

#define obstack_1grow(h, datum) \
  do { \
    if((h)->next_free + 1 > (h)->chunk_limit) \
      _obstack_newchunk((h), 1); \
    *((h)->next_free)++ = (datum); \
  } while(0)

#define obstack_blank(h, length) \
  do { \
    int __len = (length); \
    if(__len > 0 && (h)->next_free + __len > (h)->chunk_limit) \
      _obstack_newchunk((h), __len); \
    (h)->next_free += __len; \
  } while(0)

#define obstack_ptr_grow(h, ptr) \
  obstack_blank((h), sizeof(void *)); \
  ((void **)((h)->next_free))[-1] = (ptr)

/* Finishing an object */
#define obstack_finish(h) \
  ((h)->next_free == (h)->object_base \
   ? ((h)->maybe_empty_object = 1, (h)->object_base) \
   : ((h)->temp.tempptr = (h)->object_base, \
      (h)->object_base = (h)->next_free = \
        (char *)(((unsigned long)(h)->next_free + (h)->alignment_mask) \
          & ~(unsigned long)(h)->alignment_mask), \
      (h)->temp.tempptr))

#define obstack_alloc(h, length) \
  (obstack_blank((h), (length)), obstack_finish((h)))

#define obstack_copy(h, where, length) \
  (obstack_grow((h), (where), (length)), obstack_finish((h)))

#define obstack_copy0(h, where, length) \
  (obstack_grow0((h), (where), (length)), obstack_finish((h)))

/* Free */
#define obstack_free(h, obj) _obstack_free((h), (obj))

/* String convenience */
#define obstack_strdup(h, str) \
  obstack_copy0((h), (str), strlen(str))

#ifdef __cplusplus
}
#endif

#endif /* _OBSTACK_H */
