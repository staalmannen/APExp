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
static Arena arena;

#define datoff		((int)((Bucket*)0)->data)
#define nil		((void*)0)

extern	void	*sbrk(unsigned long);


void*
realloc(void *ptr, size_t n)
{
	void *new;
	size_t osize;
	Bucket *bp;

	if(ptr == nil)
		return malloc(n);

	/* Find the start of the structure */
	bp = (Bucket*)((uintptr_t)ptr - datoff);

	if(bp->magic != MAGIC)
		abort();

	/* enough space in this bucket */
	osize = 1<<bp->size;
	if(osize >= n)
		return ptr;

	new = malloc(n);
	if(new == nil)
		return nil;

	memmove(new, ptr, osize);
	free(ptr);

	return new;
}

