#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <lock.h>

enum
{
	MAGIC		= 0xbada110c,
	MAX2SIZE	= 32,
	CUTOFF		= 12,
};

#define NPAD(t, align) \
	((sizeof(t) + align - 1) & ~(align - 1))
typedef struct Bucket Bucket;
typedef struct Header Header;
struct Header {
	int	size;
	int	magic;
	Bucket	*next;
};

struct Bucket
{
	union {
		Header;
		char _pad[NPAD(Header, 16)];
	};
	char	data[1];
};

typedef struct Arena Arena;
struct Arena
{
	Bucket	*btab[MAX2SIZE];	
	Lock;
};
extern Arena __malloc_arena;

#define datoff		((int)((Bucket*)0)->data)
#define nil		((void*)0)

extern	void	*sbrk(unsigned long);


void
free(void *ptr)
{
	Bucket *bp, **l;

	if(ptr == nil)
		return;

	/* Find the start of the structure */
	bp = (Bucket*)((uintptr_t)ptr - datoff);

	if(bp->magic != MAGIC)
		abort();
	if(bp->size <= 0 || bp->size >= MAX2SIZE)
		abort();

	bp->magic = 0;
	l = &__malloc_arena.btab[bp->size];
	lock(&__malloc_arena);
	bp->next = *l;
	*l = bp;
	unlock(&__malloc_arena);
}
