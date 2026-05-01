#include <obstack.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void (*obstack_alloc_failed_handler)(void) = NULL;

static void
call_alloc_failed(void)
{
	if(obstack_alloc_failed_handler)
		(*obstack_alloc_failed_handler)();
	else {
		fputs("obstack: memory exhausted\n", stderr);
		exit(1);
	}
}

static void *
call_chunkfun(struct obstack *h, _OBSTACK_SIZE_T size)
{
	if(h->use_extra_arg)
		return (*h->chunkfun.extra)(h->extra_arg, size);
	return (*h->chunkfun.plain)(size);
}

static void
call_freefun(struct obstack *h, void *chunk)
{
	if(h->use_extra_arg)
		(*h->freefun.extra)(h->extra_arg, chunk);
	else
		(*h->freefun.plain)(chunk);
}

int
_obstack_begin(struct obstack *h, _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment,
               void *(*chunkfun)(size_t), void (*freefun)(void *))
{
	struct _obstack_chunk *chunk;

	if(size == 0) size = 4096;
	if(alignment == 0) alignment = sizeof(void *);

	h->chunkfun.plain = chunkfun;
	h->freefun.plain = freefun;
	h->chunk_size = size;
	h->alignment_mask = alignment - 1;
	h->use_extra_arg = 0;
	h->maybe_empty_object = 0;
	h->alloc_failed = 0;
	h->extra_arg = NULL;

	chunk = (struct _obstack_chunk *)(*chunkfun)(size);
	if(chunk == NULL){
		h->alloc_failed = 1;
		call_alloc_failed();
		return 0;
	}
	h->chunk = chunk;
	chunk->prev = NULL;
	chunk->limit = (char *)chunk + size;
	h->next_free = h->object_base = (char *)__PTR_ALIGN(chunk, chunk->contents, h->alignment_mask);
	h->chunk_limit = chunk->limit;
	return 1;
}

int
_obstack_begin_1(struct obstack *h, _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment,
                 void *(*chunkfun)(void *, size_t),
                 void (*freefun)(void *, void *), void *arg)
{
	struct _obstack_chunk *chunk;

	if(size == 0) size = 4096;
	if(alignment == 0) alignment = sizeof(void *);

	h->chunkfun.extra = chunkfun;
	h->freefun.extra = freefun;
	h->chunk_size = size;
	h->alignment_mask = alignment - 1;
	h->use_extra_arg = 1;
	h->maybe_empty_object = 0;
	h->alloc_failed = 0;
	h->extra_arg = arg;

	chunk = (struct _obstack_chunk *)(*chunkfun)(arg, size);
	if(chunk == NULL){
		h->alloc_failed = 1;
		call_alloc_failed();
		return 0;
	}
	h->chunk = chunk;
	chunk->prev = NULL;
	chunk->limit = (char *)chunk + size;
	h->next_free = h->object_base = (char *)__PTR_ALIGN(chunk, chunk->contents, h->alignment_mask);
	h->chunk_limit = chunk->limit;
	return 1;
}

void
_obstack_newchunk(struct obstack *h, _OBSTACK_SIZE_T length)
{
	struct _obstack_chunk *old_chunk = h->chunk;
	struct _obstack_chunk *new_chunk;
	_OBSTACK_SIZE_T obj_size = h->next_free - h->object_base;
	_OBSTACK_SIZE_T new_size;
	char *object_base;

	/* New chunk must hold the current partial object + length */
	new_size = obj_size + length + (obj_size >> 3) + 100;
	if(new_size < h->chunk_size)
		new_size = h->chunk_size;
	/* Round up to include chunk header and alignment */
	new_size += (_OBSTACK_SIZE_T)(h->object_base - (char *)old_chunk) + h->alignment_mask;

	new_chunk = (struct _obstack_chunk *)call_chunkfun(h, new_size);
	if(new_chunk == NULL){
		h->alloc_failed = 1;
		call_alloc_failed();
		return;
	}
	new_chunk->prev = old_chunk;
	new_chunk->limit = (char *)new_chunk + new_size;

	object_base = (char *)__PTR_ALIGN(new_chunk, new_chunk->contents, h->alignment_mask);
	memcpy(object_base, h->object_base, (size_t)obj_size);

	h->object_base = object_base;
	h->next_free = h->object_base + obj_size;
	h->chunk_limit = new_chunk->limit;
	h->chunk = new_chunk;
}

void
_obstack_free(struct obstack *h, void *obj)
{
	struct _obstack_chunk *lp, *plp;

	lp = h->chunk;
	while(lp != NULL){
		plp = lp->prev;
		if((char *)obj >= (char *)lp && (char *)obj < lp->limit){
			/* obj lives in this chunk: restore to that point */
			h->object_base = h->next_free = (char *)obj;
			h->chunk_limit = lp->limit;
			h->chunk = lp;
			return;
		}
		call_freefun(h, lp);
		lp = plp;
	}
	/* obj == NULL or not found: free everything */
	h->chunk = NULL;
	h->object_base = h->next_free = h->chunk_limit = NULL;
}

_OBSTACK_SIZE_T
_obstack_memory_used(struct obstack *h)
{
	struct _obstack_chunk *lp;
	_OBSTACK_SIZE_T total = 0;
	for(lp = h->chunk; lp != NULL; lp = lp->prev)
		total += (_OBSTACK_SIZE_T)(lp->limit - (char *)lp);
	return total;
}

int
obstack_vprintf(struct obstack *h, const char *fmt, va_list ap)
{
	va_list ap2;
	int n;

	va_copy(ap2, ap);
	n = vsnprintf(NULL, 0, fmt, ap2);
	va_end(ap2);

	if(n < 0) return -1;

	/* Ensure room for n chars plus a trailing NUL (vsnprintf needs it) */
	if(h->next_free + n + 1 > h->chunk_limit)
		_obstack_newchunk(h, n + 1);

	vsnprintf(h->next_free, (size_t)n + 1, fmt, ap);
	h->next_free += n;
	/* The NUL is not part of the growing object; next_free points past last char */
	return n;
}

int
obstack_printf(struct obstack *h, const char *fmt, ...)
{
	va_list ap;
	int ret;
	va_start(ap, fmt);
	ret = obstack_vprintf(h, fmt, ap);
	va_end(ap);
	return ret;
}
