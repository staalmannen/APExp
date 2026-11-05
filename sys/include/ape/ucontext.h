#ifndef __UCONTEXT_H
#define __UCONTEXT_H

#include <signal.h>
#include <ucontext_arch.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * POSIX user contexts.
 *
 * WHERE IT CAME FROM.  php's `Zend/zend_fibers.c' is unconditional --
 * `Fiber' is a language class -- and needs one of two context switches:
 * boost.context's GAS assembly, or this.  APExp had neither.  See
 * `docs/notes/php.md'.
 *
 * ***`stack_t' IS DEFINED HERE AND NOT IN <signal.h>, ON PURPOSE.***
 * POSIX puts it in <signal.h>, beside `sigaltstack' -- and **APExp has
 * no `sigaltstack'**.  Putting the type where POSIX puts it would make
 * an autoconf probe that compiles `stack_t ss;' against <signal.h>
 * answer YES, and the next thing such a package does is call
 * `sigaltstack'.  *That is this tree's commonest bug shape with the
 * sign flipped*: not a stub answering success, but a TYPE answering for
 * a capability that is not there.  Here the type is reachable only by
 * including <ucontext.h>, which is a deliberate act.
 * The `external/' grep before adding the name found 39 files; every
 * C use is a CONSUMER behind `HAVE_SIGALTSTACK', and the two `config.h'
 * hits are gnulib's `/`*` #undef stack_t *`/' replacement slot, which a
 * plain typedef does not disturb.
 */
typedef struct {
	void  *ss_sp;
	long   ss_size;
	int    ss_flags;
} stack_t;

/*
 * `uc_mcontext' IS FIRST and must stay first: `_getmcontext' and
 * friends are handed `&ucp->uc_mcontext' by the C wrappers, so nothing
 * in the assembly depends on this layout -- but keeping the machine
 * state at offset 0 means a debugger looking at a `ucontext_t' finds
 * the registers where it expects them.
 */
typedef struct __ucontext {
	mcontext_t          uc_mcontext;
	struct __ucontext  *uc_link;
	stack_t             uc_stack;
	sigset_t            uc_sigmask;
} ucontext_t;

extern int  getcontext(ucontext_t *);
extern int  setcontext(const ucontext_t *);
extern int  swapcontext(ucontext_t *, const ucontext_t *);
extern void makecontext(ucontext_t *, void (*)(void), int, ...);

#ifdef __cplusplus
}
#endif

#endif /* __UCONTEXT_H */
