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
Arena __malloc_arena;

#define datoff		((int)((Bucket*)0)->data)
#define nil		((void*)0)

extern	void	*sbrk(unsigned long);

void*
malloc(size_t size)
{
	uintptr_t next;
	int pow, n;
	Bucket *bp, *nbp;

	for(pow = 1; pow < MAX2SIZE; pow++) {
		if(size <= (1<<pow))
			goto good;
	}

	return nil;
good:
	/* Allocate off this list */
	lock(&__malloc_arena);
	bp = __malloc_arena.btab[pow];
	if(bp) {
		__malloc_arena.btab[pow] = bp->next;
		unlock(&__malloc_arena);

		if(bp->magic != 0)
			abort();

		bp->magic = MAGIC;
		return bp->data;
	}

	size = sizeof(Bucket)+(1<<pow);
	size += 15;
	size &= ~15;	/* round to 16-byte boundary for POSIX max_align_t */

	if(pow < CUTOFF) {
		uintptr_t gap;
		n = (CUTOFF-pow)+2;
		bp = sbrk(size*n + 15);	/* +15 so we can align the base */
		if(bp == (void*)-1){
			unlock(&__malloc_arena);
			return nil;
		}
		gap = (-(uintptr_t)bp) & 15;
		bp = (Bucket*)((uintptr_t)bp + gap);

		next = (uintptr_t)bp+size;
		nbp = (Bucket*)next;
		__malloc_arena.btab[pow] = nbp;
		for(n -= 2; n; n--) {
			next = (uintptr_t)nbp+size;
			nbp->next = (Bucket*)next;
			nbp->size = pow;
			nbp = nbp->next;
		}
		nbp->size = pow;
		nbp->next = nil;
	}
	else {
		uintptr_t gap;
		bp = sbrk(size + 15);	/* +15 so we can align the base */
		if(bp == (void*)-1){
			unlock(&__malloc_arena);
			return nil;
		}
		gap = (-(uintptr_t)bp) & 15;
		bp = (Bucket*)((uintptr_t)bp + gap);
	}
	unlock(&__malloc_arena);
		
	bp->size = pow;
	bp->magic = MAGIC;

	return bp->data;
}
