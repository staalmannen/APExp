/*
 * malloc_impl.h -- the block layout, in ONE place.
 *
 * It used to be copied verbatim into malloc.c, free.c and realloc.c,
 * and realloc.c's copy had drifted: it carried its own "static Arena
 * arena" that nothing ever used, beside the real __malloc_arena the
 * other two share. Three copies of a struct layout is the HFILES trap
 * in miniature -- edit one and the other two go on reading the old
 * offsets of the same object, which is exactly how Tk's event source
 * broke once (see CLAUDE.md).
 *
 * NOTE for the mkfile: a header is only rebuilt against if it is named
 * in $HFILES. sys/src/cmd/mksyslib makes every object depend on
 * $HFILES and nothing else, so this file must stay listed there.
 *
 * THE LAYOUT. One free list per power-of-two size class. A block of
 * class p is BLKSZ(p) bytes -- a 16-byte header (padded to
 * max_align_t) followed by 1<<p bytes of payload, rounded up to 16.
 * So BLKSZ(p) is 32 + 2**p once 2**p is itself a multiple of 16, i.e.
 * there are sixteen bytes of slack per block beyond the header.
 *
 * WHY THERE IS NO SPLITTING, since it is the obvious fix and does not
 * work: two class-p blocks need 2*BLKSZ(p) = 64 + 2**(p+1), which is
 * thirty-two bytes MORE than the single BLKSZ(p+1) = 32 + 2**(p+1)
 * they would be carved from. Tightening the slack does not save it
 * either -- with an exact 16+2**p stride two still need 32+2**(p+1)
 * against 16+2**(p+1). A header that lives outside the power of two
 * cannot buddy-split, whatever the padding. Splitting here means
 * changing the layout or replacing the allocator.
 *
 * And measurement says it is not where the win is anyway: see the
 * malloc note in CLAUDE.md and sys/lib/tests/malloc-reuse-test.c.
 */

#ifndef _MALLOC_IMPL_H
#define _MALLOC_IMPL_H

#include <stdint.h>

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
	int	size;		/* the power, not the byte count */
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
#ifndef nil
#define nil		((void*)0)
#endif

/*
 * Bytes a block of class pow occupies, header included. The cast
 * matters: "1<<pow" is an int, so for pow 31 it is signed overflow and
 * comes out negative -- which then converts to a vast size_t and every
 * allocation above 1 GB quietly failed.
 */
#define BLKSZ(pow)	((sizeof(Bucket) + ((size_t)1<<(pow)) + 15) & ~(size_t)15)

extern	void	*sbrk(unsigned long);

/*
 * Take n bytes from the break, 16-aligned, wasting nothing.
 *
 * The old code sbrk'd n+15 and aligned inside it, THROWING THE SLACK
 * AWAY every time -- measurably 47 bytes of overhead on a 1 MB block
 * where the layout says 32. That waste is not merely untidy: it means
 * a block does not end where the break is, so realloc below cannot
 * recognise the block sitting at the top of the heap and grow it in
 * place. Aligning the break itself costs the gap once and never again,
 * because every BLKSZ is a multiple of 16.
 *
 * Must be called with the arena locked.
 */
extern	void	*_malloc_brk(size_t n);

/*
 * Grow bp to class pow without moving it, if and only if it is the
 * last block on the heap. Returns 0 if it is not, and the caller must
 * then fall back to allocate-copy-free.
 */
extern	int	_malloc_growtop(Bucket *bp, int pow);

#endif /* _MALLOC_IMPL_H */
