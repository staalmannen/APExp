#ifndef __FDSET_GENERIC_H
#define __FDSET_GENERIC_H

/*
 * fd_set, IN ONE PLACE.
 *
 * WHY THIS FILE EXISTS. Three headers here declared `fd_set`
 * independently -- <select.h>, <sys/select.h> and <sys/types.h> -- each
 * with its own copy of the struct and the four macros, and they are
 * exactly the shape that drifts. This is `stdint_generic.h`'s
 * arrangement for the same reason: the content lives once and the three
 * headers include it, and none of them could have reached "the other
 * fd_set" by name because the search would have found itself.
 *
 * WHAT WAS WRONG, all three measured by sys/lib/tests/select-test.c
 * section 11 on the VM rather than reasoned about:
 *
 *	note FD_SETSIZE 96, fd_set holds 128, OPEN_MAX 256
 *	note fd_set came from THIS TREE
 *	FAIL FD_ZERO clears every byte of an fd_set
 *	note highest descriptor reached: 136 (wanted 136)
 *	FAIL a high descriptor with data is reported readable
 *	note select answered 0
 *
 * 1. THE SYSTEM GIVES OUT DESCRIPTORS NO fd_set COULD NAME.
 *    <sys/limits.h> sets OPEN_MAX to 256 and `_fdinfo[]` is that long,
 *    and a process really does reach 136 -- the run above climbed there
 *    by `dup` with nothing worse than the kernel's `warning: process
 *    exceeds 100 file descriptors`. FD_SETSIZE was 96. Descriptors
 *    96..255 were ordinary, usable descriptors that select could not be
 *    asked about, and it did not say so: it took `_buf.c`'s "no
 *    requested fds" arm, slept out the timeout and returned 0. A
 *    notifier waiting on one waits for ever and is told nothing.
 *
 * 2. `long fds_bits[3]` IS NOT 96 BITS HERE. The struct measured 128,
 *    because kencc rounds it up to an eight-byte multiple -- so there
 *    was a fourth word of storage that FD_SETSIZE denied, FD_SET could
 *    write into and FD_ZERO never cleared. The width is derived from
 *    FD_SETSIZE now, so the two cannot disagree again, and the test
 *    asserts `sizeof(fd_set)*8 >= FD_SETSIZE` outright.
 *
 * 3. FD_ZERO CLEARED THREE WORDS BY NAME. On a struct with any tail the
 *    macro does not know about, that leaves whatever the stack held --
 *    and a select would then act on a descriptor nobody asked about,
 *    which is not a missed event but an INVENTED one. It is a function
 *    now, clearing the whole object bytewise; a macro cannot do that
 *    without knowing the layout, which is what went wrong.
 *
 * `__fd_zero` is a call rather than a statement macro deliberately.
 * FD_ZERO was a comma expression, so it was legal anywhere an
 * expression is, and a `do { } while(0)` would have quietly broken any
 * such use; this keeps it one.
 *
 * FD_SETSIZE must stay >= OPEN_MAX. Tcl already assumes exactly that
 * -- tcl/unix/tclUnixPort.h says `#ifdef OPEN_MAX / #define FD_SETSIZE
 * OPEN_MAX` -- so it believed 256 while being handed 96, and its own
 * FD_SET on a high descriptor wrote past the end of the struct before
 * libap was reached at all.
 *
 * The macros index 32-bit words (`>>5`, `&0x1f`), so the array is sized
 * in those. `long` is 32 bits on every architecture kencc targets; were
 * it 64, this would allocate twice what it needs and still be correct,
 * since the highest index the macros can produce is covered either way.
 */

#ifndef FD_SETSIZE
#define FD_SETSIZE	256
#endif

#ifndef _FD_SET_T
#define _FD_SET_T

/*
 * A MARKER SO A TEST CAN SAY WHICH fd_set IT GOT. The host's stock APE
 * keeps its own <sys/types.h> and <sys/select.h> in the ARCHITECTURE
 * directory, which pcc searches first (pcc.c:234-235), and this tree
 * has no sys/ there -- mount-include unions that directory rather than
 * replacing it, so where this tree has no file stock's is still what a
 * compile sees. select-test.c section 11 prints whether this name is
 * defined; it reported "came from THIS TREE", which is how the 128 was
 * traced to kencc's padding rather than to stock's header.
 */
#ifndef _APEXP_FD_SET_T
#define _APEXP_FD_SET_T
#endif

typedef struct fd_set {
	long fds_bits[(FD_SETSIZE + 31) / 32];
} fd_set;

#define FD_SET(n,p)	((p)->fds_bits[(n)>>5] |= (1 << ((n) &0x1f)))
#define FD_CLR(n,p)	((p)->fds_bits[(n)>>5] &= ~(1 << ((n) &0x1f)))
#define FD_ISSET(n,p)	((p)->fds_bits[(n)>>5] & (1 << ((n) &0x1f)))

extern void __fd_zero(fd_set *);
#define FD_ZERO(p)	__fd_zero(p)

#endif /* _FD_SET_T */

#endif /* __FDSET_GENERIC_H */
