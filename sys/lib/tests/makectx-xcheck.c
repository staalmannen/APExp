/* makectx-xcheck.c -- does `makecontext' build the frame that
 * `_ctxreturn' and `_ctxfinish' expect?  Checked on the build host.
 *
 *	sh makectx-xcheck.sh
 *
 * ***A CROSS-CHECK, AND IT COMPILES THE REAL FILE RATHER THAN A COPY
 * OF IT.*** `lib/ap/arch/amd64/makecontext.c' is compiled straight into
 * this program -- no extraction, no transcription, no markers to rot --
 * with stubs standing in for `_ctxreturn' and `setcontext'.  That is
 * possible because the frame layout lives entirely in C; the assembly
 * knows only the eight register slots and one asserted offset.
 *
 * WHY IT IS WORTH A FILE.  The one number that has to agree across the
 * two languages is where the ucontext pointer sits in the new frame:
 * `makecontext' writes it at `base[UC_ARGMAX+1]' and `_ctxfinish' reads
 * it at `sp[UC_ARGMAX]', where `sp' is what `_ctxreturn' hands over
 * after the RET has popped one slot.  **Off by one and the pointer read
 * back is an argument**, so `uc_link' is garbage -- and the usual
 * consequence is `exit(0)', which from a shell prompt is
 * indistinguishable from a clean finish.  *A silent wrong answer is
 * exactly what a host check is for*, and on the VM the same mistake
 * costs a full rebuild to find.
 *
 * It does NOT test the context switch: that is machine code for a
 * machine this is not.  `ucontext-test.c' is the instrument for that,
 * and it has glibc as a reference implementation.
 *
 * THE CONTROL IS A DELIBERATE BREAK, run and reverted, because there is
 * no external oracle for a layout this file and `ucontext.c' define
 * between them:
 *
 *   `base[UC_ARGMAX+1]' -> `base[UC_ARGMAX]'   **3 failures**
 *   `(...)base - 8' -> `(...)base'             **1 failure**
 *
 * and a third that is not a failure count at all: swapping
 * `uc_sigmask' and `uc_link' in `<ucontext.h>' is a **compile error**,
 * `size of array `_uc_layout_assert' is negative'.  That is the one
 * offset the assembly addresses by number, so it is asserted rather
 * than trusted -- a wrong answer there would be a context switch
 * quietly restoring the wrong signal mask.
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <setjmp.h>

#include <ucontext.h>		/* the tree's, through the script's -I */

/* ---- stubs for what lives in ucontext.s ---------------------- */

void _ctxreturn(void) { }

/*
 * ***THE STUB MUST NOT RETURN, AND THE FIRST VERSION DID.***  The real
 * `setcontext' jumps away and never comes back, so `_ctxfinish's
 * `exit(0)' is unreachable once a `uc_link' has been followed.  A stub
 * that simply recorded and returned fell through to that `exit', and
 * section 3's "did not exit" check failed -- *the instrument reporting
 * its own stub, which is the shape to recognise rather than to argue
 * with*.  It longjmps instead, which is what "does not return" means in
 * a host program.
 */
static const ucontext_t *last_set;
static jmp_buf away;

int
setcontext(const ucontext_t *ucp)
{
	last_set = ucp;
	longjmp(away, 1);
	return -1;
}

/* `_ctxfinish' ends in exit(0) when uc_link is null; catch that. */
static int exited;
#define exit xexit
static void xexit(int n) { (void)n; exited = 1; }

/* ---- the real file ------------------------------------------- */
#include "makecontext.c"

#undef exit

/* ---- the harness --------------------------------------------- */

static int fails;

static void
eq(const char *what, long long got, long long want)
{
	if(got == want)
		printf("  PASS %-44s %lld\n", what, got);
	else {
		printf("  FAIL %-44s got %lld want %lld\n", what, got, want);
		fails++;
	}
}

#define STKSZ 65536
static char stack[STKSZ];

static void dummy(void) { }

int
main(void)
{
	ucontext_t uc, link;
	unsigned long long *base, top;
	int i;

	printf("makectx-xcheck: makecontext's frame, host build\n\n");

	printf("Section 0: the three registers makecontext sets\n");
	memset(&uc, 0, sizeof uc);
	uc.uc_stack.ss_sp = stack;
	uc.uc_stack.ss_size = STKSZ;
	uc.uc_link = &link;
	for(i = 3; i < 8; i++)
		uc.uc_mcontext.mc_regs[i] = 0xAAAA0000ULL + i;

	makecontext(&uc, dummy, 1, 0x1234);

	top = ((unsigned long long)(uintptr_t)stack + STKSZ) & ~15ULL;
	base = (unsigned long long *)(uintptr_t)(top - (UC_ARGMAX+2)*8);

	eq("SP is one slot below the frame",
	   (long long)(uc.uc_mcontext.mc_regs[_MC_SP]
	               - (unsigned long long)(uintptr_t)base), -8);
	eq("PC is the function",
	   uc.uc_mcontext.mc_regs[_MC_PC] == (unsigned long long)(uintptr_t)dummy, 1);
	eq("the first argument is in the register slot",
	   (long long)uc.uc_mcontext.mc_regs[_MC_ARG], 0x1234);

	printf("\nSection 1: mc_regs[3..7] are LEFT ALONE\n");
	/*
	 * Not housekeeping: they may hold 6c's caches for global
	 * variables, so the right value for a new context is the one the
	 * required `getcontext' already put there.  Zeroing them is the
	 * plausible wrong thing, which is why it is asserted.
	 */
	for(i = 3; i < 8; i++){
		char nm[48];
		sprintf(nm, "mc_regs[%d] untouched", i);
		eq(nm, (long long)uc.uc_mcontext.mc_regs[i], 0xAAAA0000LL + i);
	}

	printf("\nSection 2: the frame as _ctxreturn will find it\n");
	eq("base[0] is the return stub",
	   base[0] == (unsigned long long)(uintptr_t)_ctxreturn, 1);
	eq("base[UC_ARGMAX+1] is the ucontext",
	   base[UC_ARGMAX+1] == (unsigned long long)(uintptr_t)&uc, 1);

	printf("\nSection 3: _ctxfinish finds it from the SP it is given\n");
	/*
	 * ***THE ONE NUMBER THAT SPANS THE TWO LANGUAGES.***  After the
	 * RET the stack pointer is &base[1], which is what `_ctxreturn'
	 * hands over.  If this disagrees with where makecontext wrote the
	 * pointer, uc_link is garbage and the usual result is a silent
	 * exit.
	 */
	last_set = (const ucontext_t *)0;
	exited = 0;
	if(setjmp(away) == 0)
		_ctxfinish((void *)(base + 1));
	eq("it followed uc_link", last_set == &link, 1);
	eq("and did not fall through to exit", exited, 0);

	printf("\nSection 4: a null uc_link exits instead\n");
	uc.uc_link = (ucontext_t *)0;
	base[UC_ARGMAX+1] = (unsigned long long)(uintptr_t)&uc;
	last_set = (const ucontext_t *)0;
	exited = 0;
	if(setjmp(away) == 0)
		_ctxfinish((void *)(base + 1));
	eq("it exited", exited, 1);
	eq("and followed no link", last_set == (const ucontext_t *)0, 1);

	printf("\nSection 5: every argument slot, at the cap\n");
	memset(&uc, 0, sizeof uc);
	uc.uc_stack.ss_sp = stack;
	uc.uc_stack.ss_size = STKSZ;
	uc.uc_link = &link;
	makecontext(&uc, dummy, UC_ARGMAX, 101, 102, 103, 104, 105, 106, 107, 108);
	eq("argument 0 in the register slot",
	   (long long)uc.uc_mcontext.mc_regs[_MC_ARG], 101);
	for(i = 1; i < UC_ARGMAX; i++){
		char nm[48];
		sprintf(nm, "argument %d at base[%d]", i, i+1);
		eq(nm, (long long)base[i+1], 101 + i);
	}
	eq("the ucontext cell SURVIVED the last argument",
	   base[UC_ARGMAX+1] == (unsigned long long)(uintptr_t)&uc, 1);

	printf("\nmakectx-xcheck: %d failures\n", fails);
	return fails;
}
