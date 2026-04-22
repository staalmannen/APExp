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

static struct _obstack_chunk *
call_chunkfun(struct obstack *h, long size)
{
	if(h->use_extra_arg)
		return (*h->chunkfun)(h->extra_arg, size);
	return (*(struct _obstack_chunk *(*)(long))(void *)h->chunkfun)(size);
}

static void
call_freefun(struct obstack *h, struct _obstack_chunk *chunk)
{
	if(h->use_extra_arg)
		(*h->freefun)(h->extra_arg, chunk);
	else
		(*(void (*)(void *))(void *)h->freefun)(chunk);
}

int
_obstack_begin(struct obstack *h, int size, int alignment,
               void *(*chunkfun)(long), void (*freefun)(void *))
{
	struct _obstack_chunk *chunk;

	if(size == 0) size = 4096;
	if(alignment == 0) alignment = sizeof(void *);

	h->chunkfun = (struct _obstack_chunk *(*)(void *, long))(void *)chunkfun;
	h->freefun = (void (*)(void *, struct _obstack_chunk *))(void *)freefun;
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
	h->next_free = h->object_base = chunk->contents;
	h->chunk_limit = chunk->limit;
	return 1;
}

int
_obstack_begin_1(struct obstack *h, int size, int alignment,
                 void *(*chunkfun)(void *, long),
                 void (*freefun)(void *, void *), void *arg)
{
	struct _obstack_chunk *chunk;

	if(size == 0) size = 4096;
	if(alignment == 0) alignment = sizeof(void *);

	h->chunkfun = (struct _obstack_chunk *(*)(void *, long))chunkfun;
	h->freefun = (void (*)(void *, struct _obstack_chunk *))freefun;
	h->chunk_size = size;
	h->alignment_mask = alignment - 1;
	h->use_extra_arg = 1;
	h->maybe_empty_object = 0;
	h->alloc_failed = 0;
	h->extra_arg = arg;

	chunk = (*chunkfun)(arg, size);
	if(chunk == NULL){
		h->alloc_failed = 1;
		call_alloc_failed();
		return 0;
	}
	h->chunk = chunk;
	chunk->prev = NULL;
	chunk->limit = (char *)chunk + size;
	h->next_free = h->object_base = chunk->contents;
	h->chunk_limit = chunk->limit;
	return 1;
}

void
_obstack_newchunk(struct obstack *h, int length)
{
	struct _obstack_chunk *old_chunk = h->chunk;
	struct _obstack_chunk *new_chunk;
	long obj_size = h->next_free - h->object_base;
	long new_size;

	/* New chunk must hold the current partial object + length */
	new_size = obj_size + length + (obj_size >> 3) + 100;
	if(new_size < h->chunk_size)
		new_size = h->chunk_size;
	/* Round up to include chunk header */
	new_size += (long)(h->object_base - (char *)old_chunk);

	new_chunk = call_chunkfun(h, new_size);
	if(new_chunk == NULL){
		h->alloc_failed = 1;
		call_alloc_failed();
		return;
	}
	new_chunk->prev = old_chunk;
	new_chunk->limit = (char *)new_chunk + new_size;

	memcpy(new_chunk->contents, h->object_base, (size_t)obj_size);

	h->object_base = new_chunk->contents;
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

int
_obstack_memory_used(struct obstack *h)
{
	struct _obstack_chunk *lp;
	int total = 0;
	for(lp = h->chunk; lp != NULL; lp = lp->prev)
		total += (int)(lp->limit - (char *)lp);
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
