#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <lock.h>
#include "malloc_impl.h"

Arena __malloc_arena;

/*
 * ------------------------------------------------------------------
 * THE HEAP WATCHDOG: $APEXP_MALLOCMAX, in megabytes. Off unless set.
 *
 * WHY IT EXISTS. bash could not become /bin/sh here because it died
 * `Killed: Insufficient physical memory'. `ratrace' over one run gave
 * 3458016 lines, and numbering the non-Brk ones put 3456434 of the
 * 3456769 Brk lines -- 99.99% -- in ONE uninterrupted gap containing
 * no other system call at all. Two Brk per _malloc_brk, the break
 * stepping ~480 bytes, and BLKSZ(4)*((CUTOFF-4)+2) = 48*10 = 480
 * exactly: about 17 million live allocations of <= 16 bytes.
 *
 * **AND THAT IS WHERE EVERY ROUND OF THAT HUNT STOPPED, BECAUSE
 * `Insufficient physical memory' IS A KILL.** The kernel destroys the
 * process, so there is no stack to take and nothing for `acid' to
 * attach to -- six rounds were spent examining a corpse the kernel
 * had already disposed of, and the only evidence available was a
 * 272 MB trace of the one syscall the loop happened to make.
 *
 * So: abort EARLY, while the machine is still healthy. With
 * APEXP_MALLOCMAX=64 a runaway breaks after 64 MB instead of after
 * 800, the process is Broken rather than gone, and
 *
 *	acid <pid>
 *	stk()
 *
 * names the calling function -- which is how gnulib's self-recursive
 * `strerror' and _buf.c:544 were both settled after source reading
 * had failed on them.
 *
 * SAFE TO CALL FROM HERE. getenv() is a plain scan of `environ' and
 * allocates nothing (ap/env/getenv.c), and write(2) with a
 * hand-rolled number is the same idiom plan9/_apdbg.c uses for
 * exactly this reason. Nothing on this path can re-enter malloc.
 *
 * Cost when off: one load and one branch per sbrk, which is already
 * two system calls.
 */
static size_t	wd_got;		/* bytes taken from the break so far */
static size_t	wd_max;		/* 0 means off */
static long	wd_calls;
static int	wd_init;

static char *
wd_str(char *p, char *e, const char *s)
{
	while(*s && p < e)
		*p++ = *s++;
	return p;
}

static char *
wd_num(char *p, char *e, size_t v)
{
	char n[24];
	int i;

	i = 0;
	do {
		n[i++] = '0' + (int)(v%10);
		v /= 10;
	} while(v != 0 && i < (int)sizeof n);
	while(i > 0 && p < e)
		*p++ = n[--i];
	return p;
}

/*
 * Called with the arena LOCKED, and it unlocks before aborting.
 * abort() runs the signal machinery, which may allocate; doing that
 * under our own lock would deadlock and give a hang where a break was
 * wanted. The process is dying either way, so releasing the arena
 * first costs nothing and keeps the failure legible.
 */
static void
wd_fail(void)
{
	char buf[200], *p, *e;

	unlock(&__malloc_arena);

	p = buf;
	e = buf + sizeof buf - 2;
	p = wd_str(p, e, "libap: APEXP_MALLOCMAX exceeded: ");
	p = wd_num(p, e, wd_got);
	p = wd_str(p, e, " bytes from the break in ");
	p = wd_num(p, e, (size_t)wd_calls);
	p = wd_str(p, e, " sbrk calls; aborting so a stack can be taken"
		" (acid <pid>; stk())");
	*p++ = '\r';
	*p++ = '\n';
	write(2, buf, p - buf);

	abort();
}

/* Returns non-zero when the limit has been passed. */
static int
wd_note(size_t n)
{
	const char *s;
	size_t v;

	if(wd_init == 0){
		wd_init = 1;
		s = getenv("APEXP_MALLOCMAX");
		if(s != 0){
			v = 0;
			while(*s >= '0' && *s <= '9')
				v = v*10 + (size_t)(*s++ - '0');
			wd_max = v * 1024 * 1024;
		}
	}
	if(wd_max == 0)
		return 0;
	wd_calls++;
	wd_got += n;
	return wd_got > wd_max;
}

/*
 * Take n bytes from the break, 16-aligned. See malloc_impl.h for why
 * the alignment is done on the break rather than inside the block.
 * Called with the arena locked.
 */
void*
_malloc_brk(size_t n)
{
	uintptr_t cur, gap;
	char *p;

	cur = (uintptr_t)sbrk(0);
	if(cur == (uintptr_t)-1)
		return nil;
	gap = (-cur) & 15;

	p = sbrk(gap + n);
	if(p == (void*)-1)
		return nil;
	if(wd_note(gap + n))
		wd_fail();
	return p + gap;
}

/*
 * Grow a block in place rather than allocate-copy-free, when it is the
 * last thing on the heap.
 *
 * THIS IS THE WHOLE OF THE INTERPRETER PROBLEM. realloc was
 * malloc-copy-free unconditionally, so growing one buffer by doubling
 * -- which is how every interpreter builds a big string -- walked the
 * size classes and stranded a dead block in each one. Measured on the
 * host: building a 32 MB string that way took 62 MB from the kernel,
 * and 1 KB -> 1 MB took 2005575 bytes for a megabyte of string.
 *
 * The strands are not lost forever; the NEXT identical growth reuses
 * them class for class, which is why a second 32 MB string cost zero.
 * It is the PEAK that kills a small VM, and the peak is twice what it
 * needs to be.
 *
 * MEMORY ALREADY OWNED BEATS MEMORY FROM THE KERNEL, so a free block
 * of the target class is taken first and this returns 0. Without that
 * test the heap got BIGGER, not smaller: extending at the break walks
 * straight past the 32 MB block the previous string left on the free
 * list, and three strings in a row cost 97 MB where the unfixed
 * allocator cost 64. Measured, not reasoned -- it is the one thing in
 * this change that went the wrong way, and only the bench said so.
 *
 * Asking the kernel for the current break rather than remembering it
 * is deliberate. If anything else in the program has called sbrk since
 * -- and sbrk is a public entry point -- a remembered top would be
 * stale and LOWER than the real break, so the address test would pass
 * while the memory sbrk hands back is not contiguous with bp. That is
 * silent heap corruption. The syscall costs less than the memmove it
 * replaces.
 */
int
_malloc_growtop(Bucket *bp, int pow)
{
	size_t have, want;
	int ok;

	have = BLKSZ(bp->size);
	want = BLKSZ(pow);
	ok = 0;

	lock(&__malloc_arena);
	if(__malloc_arena.btab[pow] == nil
	&& (char*)bp + have == (char*)sbrk(0)
	&& sbrk(want - have) != (void*)-1){
		bp->size = pow;
		ok = 1;
		/*
		 * The OTHER sbrk site, and it must be counted too: it has
		 * the same two-Brk signature as _malloc_brk, so a trace
		 * cannot tell the two apart and a watchdog that watched
		 * only one could report a flat heap while the break ran
		 * away. wd_fail unlocks for itself.
		 */
		if(wd_note(want - have))
			wd_fail();
	}
	unlock(&__malloc_arena);

	return ok;
}

void*
malloc(size_t size)
{
	uintptr_t next;
	int pow, n;
	size_t bsize;
	Bucket *bp, *nbp;

	for(pow = 1; pow < MAX2SIZE; pow++) {
		if(size <= ((size_t)1<<pow))
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

		bp->next = nil;
		bp->magic = MAGIC;
		return bp->data;
	}

	bsize = BLKSZ(pow);

	if(pow < CUTOFF) {
		n = (CUTOFF-pow)+2;
		bp = _malloc_brk(bsize*n);
		if(bp == nil){
			unlock(&__malloc_arena);
			return nil;
		}

		next = (uintptr_t)bp+bsize;
		nbp = (Bucket*)next;
		__malloc_arena.btab[pow] = nbp;
		for(n -= 2; n; n--) {
			next = (uintptr_t)nbp+bsize;
			nbp->next = (Bucket*)next;
			nbp->size = pow;
			nbp->magic = 0;
			nbp = nbp->next;
		}
		nbp->size = pow;
		nbp->magic = 0;
		nbp->next = nil;
	}
	else {
		bp = _malloc_brk(bsize);
		if(bp == nil){
			unlock(&__malloc_arena);
			return nil;
		}
	}
	unlock(&__malloc_arena);

	bp->size = pow;
	bp->next = nil;
	bp->magic = MAGIC;

	return bp->data;
}
