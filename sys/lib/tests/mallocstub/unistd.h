/*
 * unistd.h -- a SHADOW of the host's, for the host build of libap's
 * allocator (sys/lib/tests/malloc-xcheck.sh).
 *
 * `malloc.c' includes <unistd.h> for `sbrk', and `malloc_impl.h'
 * declares it as `void *sbrk(unsigned long)'.  The host's own
 * unistd.h declares `void *sbrk(intptr_t)', and the harness renames
 * the name, so BOTH declarations would become declarations of
 * `ap_sbrk' -- with `long' against `unsigned long', which is a hard
 * `conflicting types' error.  Shadowing is the smallest fix, and
 * `malloc_impl.h's declaration is the one that must win, since it is
 * the one the allocator was compiled against on the target.
 *
 * `mallocwatch.c' wants `write', so that one is declared here: with
 * the real header shadowed this is the only declaration of it, and
 * without it the call is an implicit declaration returning int.
 */
#ifndef _UNISTD_H_STUB
#define _UNISTD_H_STUB

#include <sys/types.h>

extern ssize_t write(int, const void *, size_t);
extern pid_t   getpid(void);

#endif
