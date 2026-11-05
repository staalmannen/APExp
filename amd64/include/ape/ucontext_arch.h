#ifndef __UCONTEXT_ARCH_H
#define __UCONTEXT_ARCH_H

/*
 * amd64 machine context for <ucontext.h>.
 *
 * ***THE EIGHT SLOTS ARE setjmp's EIGHT, AND THAT IS DELIBERATE.***
 * `arch/amd64/setjmp.s' saves SP, PC, BP, BX, R12, R13, R14, R15 and its
 * header says why the last six are there: APExp's 6c has
 * REGEXT = D_R15, so R15 and R14 are reserved program-wide
 * (`6c/reg.c:55-57') and R13/R12 can follow them as external register
 * caches for global variables.  A context switch that restored only
 * SP and PC would leave the resumed code reading another context's
 * cached globals.  *ucontext has exactly setjmp's problem, so it gets
 * exactly setjmp's answer* -- and `arch/amd64/ucontext.s' is that file's
 * save/restore sequence with the return-value convention changed.
 *
 * The order is fixed because the assembly indexes it by number.  It is
 * the ONLY thing the assembly knows about any of these structures:
 * everything else -- `uc_link', `uc_stack', `uc_sigmask' -- is handled
 * in C, so no struct offset is ever written down twice.
 */
typedef struct mcontext_t {
	unsigned long long mc_regs[8];
} mcontext_t;

/* names for the three slots `makecontext' has to fill */
#define _MC_SP	0
#define _MC_PC	1
#define _MC_ARG	2	/* BP, which is 6c's RARG: the first argument */

#endif /* __UCONTEXT_ARCH_H */
