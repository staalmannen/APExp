#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <lock.h>
#include "malloc_impl.h"

/*
 * Prototypes copied EXACTLY from ap/include/sys9.h rather than by
 * including it: kencc widens an argument at the call site only when a
 * prototype is visible, so a remembered signature is a corrupted
 * argument. `_SLEEP' takes a long and `_EXITS' a char*.
 */
extern	void	_EXITS(char *);
extern	int	_SLEEP(long);

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
 * THE LIMIT IS READ FROM _apemain, NOT FROM IN HERE, AND THE FIRST
 * VERSION OF THIS FILE BROKE EVERY APE PROGRAM BY GETTING THAT
 * WRONG. It called getenv() lazily on the first sbrk, reasoning that
 * getenv is a plain scan of `environ' and allocates nothing --
 * which is true, and was the wrong question. **`environ' is created
 * BY a malloc**: plan9/_envsetup.c:140 is
 *
 *	environ = pp = malloc((1+cnt)*sizeof(char *));
 *
 * so on the FIRST allocation of every APE program `environ' is still
 * null, and ap/env/getenv.c has no null check -- `char **p = environ;
 * while(*p != NULL)'. Every program died before main with
 * `fault read addr=0x0'. *Not a re-entrancy bug: a circular
 * dependency, where the allocator asked for state the allocation was
 * being made to create.*
 *
 * So _malloc_watchinit() is called from _apemain immediately after
 * _envsetup(), where environ is complete and main has not started.
 * The allocator itself now only tests a static, and allocations
 * before that point are simply unwatched -- there are a handful, and
 * an instrument that cannot run before its subject exists is the
 * right trade against one that kills it.
 *
 * write(2) with a hand-rolled number is still plan9/_apdbg.c's idiom,
 * and that part was fine: it has no such dependency.
 *
 * Cost when off: one load and one branch per sbrk, which is already
 * two system calls.
 */
/*
 * THE LIMIT, THE INIT AND THE TWO STRING HELPERS LIVE IN
 * `mallocwatch.c', NOT HERE, AND THAT SPLIT IS A BUG FIX.
 *
 * `_apemain' calls `_malloc_watchinit()'. While that function lived in
 * THIS file, the reference pulled this object out of libap.a for every
 * APE program -- and this object defines `malloc'. So any program
 * supplying its OWN allocator got
 *
 *	malloc: /amd64/lib/ape/libap.a(_malloc_watchinit):
 *	        redefinition: malloc
 *
 * **f2c is such a program**, and it had linked for years: its
 * `malloc.c' is upstream's optional replacement allocator, enabled by
 * `mkfile.plan9'. Nothing had ever forced libap's `malloc.$O' to be
 * pulled, because `malloc' itself was already satisfied by f2c's.
 * *The watchdog quietly made it impossible for any APE program to
 * replace malloc* -- and only a full `mk distclean' relink could show
 * it, which is why it arrived rounds after the change.
 *
 * Keeping the state in its own object restores the property: this
 * file references `_malloc_wdmax', so malloc.$O pulls mallocwatch.$O
 * and never the other way about. A program with its own allocator
 * still runs `_malloc_watchinit()' -- it simply sets a variable
 * nothing reads, which is exactly what "the watchdog is off for this
 * program" should look like.
 */
extern size_t	_malloc_wdmax;		/* 0 means off */
extern char	*_malloc_wdstr(char *p, char *e, const char *s);
extern char	*_malloc_wdnum(char *p, char *e, size_t v);

static size_t	wd_got;		/* bytes taken from the break so far */
static long	wd_calls;

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
	char buf[240], *p, *e;
	int nap;

	/*
	 * DISARM FIRST, AND THIS LINE IS THE WHOLE FUNCTION'S CORRECTNESS.
	 *
	 * **abort() ALLOCATES on Plan 9.** Measured, not assumed -- the
	 * first version without this line produced an `acid' stack that
	 * was nothing but its own recursion, thousands of frames deep:
	 *
	 *	wd_fail()            malloc.c
	 *	_malloc_brk(n=0x1e0) malloc.c
	 *	malloc()             malloc.c
	 *	open(flags=0x1, ...) fcntl/open.c:76
	 *	note(...)            signal/kill.c:16
	 *	kill(sig=0x5, ...)   signal/kill.c:58
	 *	abort()              stdlib/abort.c:8
	 *	wd_fail()            <- round again
	 *
	 * abort() raises SIGABRT, libap's kill() posts a note, and note()
	 * OPENS /proc/<pid>/note -- and open() mallocs. So the over-limit
	 * allocator is re-entered from inside its own abort, fires again,
	 * and buries the stack it exists to expose.
	 *
	 * Clearing _malloc_wdmax makes every later wd_note() return 0, so the
	 * abort path allocates freely and the message prints once. The
	 * limit has already done its job by the time we are here.
	 */
	_malloc_wdmax = 0;

	unlock(&__malloc_arena);

	p = buf;
	e = buf + sizeof buf - 2;
	p = _malloc_wdstr(p, e, "libap: APEXP_MALLOCMAX exceeded: ");
	p = _malloc_wdnum(p, e, wd_got);
	p = _malloc_wdstr(p, e, " bytes from the break in ");
	p = _malloc_wdnum(p, e, (size_t)wd_calls);
	p = _malloc_wdstr(p, e, " sbrk calls.  SLEEPING so a stack can be taken:"
		"  acid ");
	p = _malloc_wdnum(p, e, (size_t)getpid());
	p = _malloc_wdstr(p, e, "  then stk()  then echo kill > /proc/");
	p = _malloc_wdnum(p, e, (size_t)getpid());
	p = _malloc_wdstr(p, e, "/ctl");
	*p++ = '\r';
	*p++ = '\n';
	write(2, buf, p - buf);

	/*
	 * SLEEP RATHER THAN abort(), AND THE REASON IS MEASURED.
	 *
	 * The first version called abort(), and the process was simply
	 * GONE -- `ps' showed nothing and `acid <pid>' answered
	 * `can't open /proc/13576/text'. Plan 9 note semantics explain
	 * it exactly: abort() is kill(getpid(), SIGABRT), which posts a
	 * note whose string is an ordinary word; libap does not handle
	 * it, so signal.c:102 reaches `_NOTED(1)' (NDFLT), and the
	 * kernel's default for a plain note is to **EXIT**. Only a note
	 * beginning `sys:' -- a real trap -- makes a process BREAK and
	 * stay for a debugger. *So abort() could never have produced
	 * the Broken process this instrument promised.*
	 *
	 * Faulting deliberately would break it, but that puts the
	 * instrument's correctness back on note semantics and on
	 * whatever SIGSEGV handler the subject happens to have
	 * installed. Sleeping removes the question: **`acid` attaches
	 * to a LIVE process**, which is how `_buf.c:544` was found in
	 * this tree, and `ps` shows the subject sitting in `Sleep`
	 * rather than needing to be caught.
	 *
	 * Bounded at fifteen minutes so a forgotten run releases its
	 * memory by itself; the message names the pid twice, once to
	 * attach and once to kill.
	 */
	for(nap = 0; nap < 900; nap++)
		_SLEEP(1000);

	_EXITS("mallocmax");
}

/*
 * Returns non-zero when the limit has been passed. Touches nothing
 * outside this file and calls nothing at all -- the whole point.
 */
static int
wd_note(size_t n)
{
	if(_malloc_wdmax == 0)
		return 0;
	wd_calls++;
	wd_got += n;
	return wd_got > _malloc_wdmax;
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
