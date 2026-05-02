#ifndef _OBSTACK_H
#define _OBSTACK_H

#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _OBSTACK_SIZE_T
#define _OBSTACK_SIZE_T size_t
#endif

#ifndef _OBSTACK_CHUNK_SIZE_T
#define _OBSTACK_CHUNK_SIZE_T size_t
#endif

#ifndef _OBSTACK_INDEX_T
#define _OBSTACK_INDEX_T size_t
#endif

#ifndef _CHUNK_SIZE_T
#define _CHUNK_SIZE_T size_t
#endif

#ifndef __PTR_ALIGN
#define __PTR_ALIGN(B, P, A) \
  ((P) + ((-(uintptr_t)(P)) & (A)))
#endif

struct _obstack_chunk {
	char *limit;
	struct _obstack_chunk *prev;
	char contents[4];
};

struct obstack {
	_CHUNK_SIZE_T chunk_size;
	struct _obstack_chunk *chunk;
	char *object_base;
	char *next_free;
	char *chunk_limit;
	union { _OBSTACK_SIZE_T i; void *p; } temp;
	_OBSTACK_SIZE_T alignment_mask;
	union {
		void *(*plain)(size_t);
		void *(*extra)(void *, size_t);
	} chunkfun;
	union {
		void (*plain)(void *);
		void (*extra)(void *, void *);
	} freefun;
	void *extra_arg;
	unsigned use_extra_arg:1;
	unsigned maybe_empty_object:1;
	unsigned alloc_failed:1;
};

extern void (*obstack_alloc_failed_handler)(void);

extern int  _obstack_begin(struct obstack *, _OBSTACK_SIZE_T, _OBSTACK_SIZE_T,
                           void *(*)(size_t), void (*)(void *));
extern int  _obstack_begin_1(struct obstack *, _OBSTACK_SIZE_T, _OBSTACK_SIZE_T,
                              void *(*)(void *, size_t),
                              void (*)(void *, void *), void *);
extern void _obstack_newchunk(struct obstack *, _OBSTACK_SIZE_T);
extern void _obstack_free(struct obstack *, void *);
extern _OBSTACK_SIZE_T  _obstack_memory_used(struct obstack *);

extern int obstack_printf(struct obstack *, const char *, ...);
extern int obstack_vprintf(struct obstack *, const char *, va_list);

/* User must define these before using obstack macros:
 *   #define obstack_chunk_alloc  malloc
 *   #define obstack_chunk_free   free
 */

#define obstack_init(h) \
  _obstack_begin((h), 0, 0, \
    (void *(*)(size_t))obstack_chunk_alloc, \
    (void (*)(void *))obstack_chunk_free)

#define obstack_begin(h, size) \
  _obstack_begin((h), (size), 0, \
    (void *(*)(size_t))obstack_chunk_alloc, \
    (void (*)(void *))obstack_chunk_free)

#define obstack_specify_allocation(h, size, alignment, chunkfun, freefun) \
  _obstack_begin((h), (size), (alignment), \
    (void *(*)(size_t))(chunkfun), (void (*)(void *))(freefun))

#define obstack_specify_allocation_with_arg(h, size, alignment, chunkfun, freefun, arg) \
  _obstack_begin_1((h), (size), (alignment), \
    (void *(*)(void *, size_t))(chunkfun), (void (*)(void *, void *))(freefun), (arg))

/* Object growing */
#define obstack_object_size(h) \
  ((_OBSTACK_SIZE_T)((h)->next_free - (h)->object_base))

#define obstack_room(h) \
  ((_OBSTACK_SIZE_T)((h)->chunk_limit - (h)->next_free))

#define obstack_make_room(h, length) \
  ((h)->next_free + (length) > (h)->chunk_limit \
    ? (_obstack_newchunk((h), (length)), 0) : 0)

#define obstack_empty_p(h) \
  ((h)->chunk->prev == 0 \
   && (h)->next_free == (char *)__PTR_ALIGN((h)->chunk, (h)->chunk->contents, (h)->alignment_mask))

#define obstack_grow(h, where, length) \
  ((h)->temp.i = (length), \
   ((h)->next_free + (h)->temp.i > (h)->chunk_limit \
    ? _obstack_newchunk((h), (h)->temp.i) : (void)0), \
   memcpy((h)->next_free, (where), (size_t)(h)->temp.i), \
   (void)((h)->next_free += (h)->temp.i))

#define obstack_grow0(h, where, length) \
  ((h)->temp.i = (length), \
   ((h)->next_free + (h)->temp.i + 1 > (h)->chunk_limit \
    ? _obstack_newchunk((h), (h)->temp.i + 1) : (void)0), \
   memcpy((h)->next_free, (where), (size_t)(h)->temp.i), \
   (h)->next_free += (h)->temp.i, \
   (void)(*((h)->next_free)++ = '\0'))

#define obstack_1grow(h, datum) \
  (((h)->next_free + 1 > (h)->chunk_limit \
    ? _obstack_newchunk((h), 1) : (void)0), \
   (void)(*((h)->next_free)++ = (datum)))

#define obstack_blank(h, length) \
  ((h)->temp.i = (length), \
   ((h)->temp.i > 0 && (h)->next_free + (h)->temp.i > (h)->chunk_limit \
    ? _obstack_newchunk((h), (h)->temp.i) : (void)0), \
   (void)((h)->next_free += (h)->temp.i))

#define obstack_ptr_grow(h, ptr) \
  (obstack_blank((h), sizeof(void *)), \
   (void)(((void **)((h)->next_free))[-1] = (ptr)))

/* Obstack accessors */
#define obstack_base(h) ((void *) (h)->object_base)
#define obstack_next_free(h) ((void *) (h)->next_free)
#define obstack_blank_fast(h, n) ((h)->next_free += (n))

/* Finishing an object */
#define obstack_finish(h) \
  ((h)->next_free == (h)->object_base \
   ? ((h)->maybe_empty_object = 1, (h)->object_base) \
   : ((h)->temp.p = (h)->object_base, \
      (h)->object_base = (h)->next_free = \
        (char *)__PTR_ALIGN((h)->object_base, (h)->next_free, (h)->alignment_mask), \
      (h)->temp.p))

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
