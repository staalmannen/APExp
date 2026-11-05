/*
 * POSIX user contexts: `makecontext' and the function a context
 * returns through.  `ucontext.s' has `getcontext', `setcontext' and
 * `swapcontext'.
 *
 * WHERE IT CAME FROM.  php's `Zend/zend_fibers.c' is unconditional --
 * `Fiber' is a language class -- and wants either boost.context's GAS
 * assembly or <ucontext.h>; APExp had neither.  `docs/notes/php.md'.
 *
 * ***THIS FILE IS ARCHITECTURE-SPECIFIC AND THE REASON IS THE ARGUMENT
 * LAYOUT***, which is 6c's amd64 convention and nothing else's.  A
 * second architecture adds its own pair beside this one.
 */
#include "lib.h"
#include <ucontext.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern void _ctxreturn(void);

/*
 * ***THE ONE OFFSET `ucontext.s' KNOWS, ASSERTED RATHER THAN TRUSTED.***
 * The three switches are assembly because a C wrapper cannot save its
 * caller's frame (see `ucontext.s'), and the price is that they address
 * `uc_sigmask' by number.  A negative array size turns a layout change
 * into a COMPILE error instead of a context switch that quietly
 * restores the wrong signal mask.
 */
typedef char _uc_layout_assert[
	(offsetof(ucontext_t, uc_mcontext) == 0
	 && offsetof(ucontext_t, uc_sigmask) == 64) ? 1 : -1];

/*
 * THE NEW CONTEXT'S STACK FRAME, as `makecontext' builds it and
 * `_ctxreturn' reads it back.  Addresses increase downward in this
 * picture; the stack itself grows the other way.
 *
 *	base[0]              the return address: _ctxreturn
 *	base[1]              6c's reserved 0(FP) slot for the first
 *	                     argument, which actually arrives in BP
 *	base[2..UC_ARGMAX]   arguments 1..UC_ARGMAX-1, at 8(FP) upwards
 *	base[UC_ARGMAX+1]    the ucontext this frame belongs to
 *
 * `func' is entered with SP = base, exactly as a CALL would leave it.
 * When it returns, the RET pops base[0] and `_ctxreturn' sees
 * SP = &base[1], so the ucontext is at sp[UC_ARGMAX] -- **one constant,
 * in one language**, which is why `_ctxreturn' hands its stack pointer
 * to C instead of dereferencing it itself.
 *
 * ***UC_ARGMAX IS A CAP AND NOT A CONVENTION, AND THE REASON IS 6c's
 * FIRST-ARGUMENT REGISTER.*** On an ABI that passes the first six
 * arguments in registers the stack image does not change shape with
 * `argc', so the bookkeeping cell can sit at a fixed offset whatever
 * the count -- which is how glibc does it.  Here only argument ZERO is
 * in a register and the rest are contiguous from 8(FP), so the cell
 * must come after a FIXED number of argument slots or its offset moves.
 * Eight is chosen rather than derived; php passes none, and POSIX only
 * promises `int' arguments.
 */
#define UC_ARGMAX	8
#define UC_SLOTS	(UC_ARGMAX + 2)

/*
 * Version marker for `ucontext-test.c'.  `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code.  Thirteenth use of the idiom.
 */
int
_ucmark(void)
{
	return 1;
}

static void
ucdie(const char *msg)
{
	write(2, "makecontext: ", 13);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	abort();
}

void
makecontext(ucontext_t *ucp, void (*func)(void), int argc, ...)
{
	unsigned long long *base;
	unsigned long long top;
	va_list ap;
	int i;

	if(ucp == 0)
		ucdie("null context");
	if(func == 0)
		ucdie("null function");
	if(argc < 0 || argc > UC_ARGMAX)
		ucdie("more arguments than this port passes");
	if(ucp->uc_stack.ss_sp == 0 || ucp->uc_stack.ss_size < UC_SLOTS*8 + 64)
		ucdie("stack missing or too small");

	top = (unsigned long long)(unsigned long)ucp->uc_stack.ss_sp
	    + (unsigned long long)ucp->uc_stack.ss_size;
	top &= ~(unsigned long long)15;		/* 6c does not require 16;
						 * its frames are not a
						 * multiple of it.  Free. */
	base = (unsigned long long *)(unsigned long)(top - UC_SLOTS*8);

	base[0] = (unsigned long long)(unsigned long)_ctxreturn;
	base[1] = 0;				/* 6c's reserved 0(FP) slot */
	for(i = 2; i <= UC_ARGMAX; i++)
		base[i] = 0;
	base[UC_ARGMAX+1] = (unsigned long long)(unsigned long)ucp;

	/*
	 * POSIX says the arguments are `int'.  They are read here as the
	 * widest integer instead, and that is not laxity: **every vararg
	 * occupies eight bytes on this ABI** -- `stdarg_arch.h' advances
	 * the list by 8 for sizes 1, 2 and 4 alike -- so reading eight is
	 * reading the whole slot.  A callee declaring `int' then takes the
	 * low four bytes and is right whatever is above them, while a
	 * caller that passed a POINTER (common, and what every real
	 * makecontext user does) is served correctly rather than
	 * truncated.  *Reading `int' here would be the narrower choice and
	 * the wrong one.*
	 */
	va_start(ap, argc);
	for(i = 0; i < argc; i++){
		unsigned long long v = (unsigned long long)va_arg(ap, long long);
		if(i == 0)
			ucp->uc_mcontext.mc_regs[_MC_ARG] = v;	/* BP = RARG */
		else
			base[i+1] = v;				/* 8(FP) up */
	}
	va_end(ap);
	if(argc == 0)
		ucp->uc_mcontext.mc_regs[_MC_ARG] = 0;

	/*
	 * `setcontext' loads SP and then adds 8 before jumping -- the
	 * no-stack-write form of a RET -- so the SP recorded here is one
	 * slot BELOW the frame, and `func' begins with SP = base.
	 */
	ucp->uc_mcontext.mc_regs[_MC_SP] =
		(unsigned long long)(unsigned long)base - 8;
	ucp->uc_mcontext.mc_regs[_MC_PC] =
		(unsigned long long)(unsigned long)func;

	/*
	 * mc_regs[3..7] -- BX, R12..R15 -- are left exactly as they are.
	 * ***THAT IS WHY POSIX MAKES `getcontext' A PRECONDITION OF
	 * `makecontext'***: those registers may hold 6c's caches for
	 * global variables (REGEXT is R15, descending), so the right value
	 * for a new context is the CALLER's, which the required
	 * `getcontext' has already put there.  Zeroing them would hand the
	 * new context a null view of every register-cached global.
	 * `uc_sigmask' is left alone for the same reason.
	 */
}

/*
 * Where a context's function returns to.  `_ctxreturn' in the assembly
 * hands over its stack pointer and nothing else; the frame layout is
 * this file's, so the arithmetic is here.
 */
void
_ctxfinish(void *sp)
{
	ucontext_t *ucp;

	ucp = ((ucontext_t **)sp)[UC_ARGMAX];
	if(ucp != 0 && ucp->uc_link != 0)
		setcontext(ucp->uc_link);
	exit(0);
}
