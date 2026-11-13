/*
 * lock.h -- the Plan 9 lock interface, for the HOST build of libap's
 * allocator (sys/lib/tests/malloc-xcheck.sh).
 *
 * Nothing here is a measurement: the cross-check is single-threaded,
 * so a no-op lock is the correct model and not a shortcut.
 *
 * ***THEY TAKE `void *' AND DO NOTHING, AND BOTH HALVES MATTER.***
 * The allocator calls `lock(&__malloc_arena)', an `Arena *' where a
 * `Lock *' is expected -- legal under kencc, which converts a pointer
 * to a struct into a pointer to an unnamed member's type, and not
 * reproducible in gcc.  Taking `void *' accepts the call.
 *
 * **And the body must stay empty.**  `Lock' is the LAST member of
 * `Arena', after `btab[32]', so a stub that cast the pointer and
 * wrote through it would write over `btab[0]' on every lock -- an
 * instrument that corrupts the thing it is measuring, and one whose
 * failures would look exactly like the bug being hunted.
 *
 * `-fms-extensions' is still required and is in the harness: `Arena'
 * carries an unnamed `Lock;' member and `Bucket' an unnamed `Header;'
 * inside a union, which gcc accepts only under that flag.
 */
#ifndef _LOCK_H_STUB
#define _LOCK_H_STUB

typedef struct Lock Lock;
struct Lock { int val; };

static inline void lock(void *l)    { (void)l; }
static inline void unlock(void *l)  { (void)l; }
static inline int  canlock(void *l) { (void)l; return 1; }

#endif
