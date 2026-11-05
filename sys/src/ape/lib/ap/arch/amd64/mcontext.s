/*
 * amd64 machine-context switch for <ucontext.h>.
 *
 * The file is `mcontext.s' and not `ucontext.s' because `ucontext.c'
 * sits beside it and mk derives both objects from the base name.
 *
 * ***THIS IS `setjmp.s' WITH THE RETURN-VALUE CONVENTION CHANGED, AND
 * THAT IS THE WHOLE DESIGN.*** The two problems are the same one: save
 * enough of the machine that execution can be resumed somewhere else.
 * Read `setjmp.s' first -- its header carries the two findings this
 * file inherits rather than re-derives:
 *
 *   - **eight registers, not two.** 6c has REGEXT = D_R15, so R15 and
 *     R14 are reserved program-wide and R13/R12 may follow them as
 *     caches for global variables.  Restoring only SP and PC leaves the
 *     resumed code reading another context's globals.
 *   - **the restore must not WRITE to the stack.** Upstream longjmp
 *     stores the target PC at 0(SP) and RETs, which faults when SP is
 *     at USTKTOP.  `ADDQ $8,SP' then `JMP' does the same thing without
 *     the store, and a ucontext resumed at the very top of a freshly
 *     allocated fiber stack is exactly that case.
 *
 * ***AND THE ONE THING THESE ROUTINES KNOW IS "EIGHT SLOTS".*** No
 * offset of `uc_link', `uc_stack' or `uc_sigmask' appears here;
 * `ucontext.c' passes `&ucp->uc_mcontext' and does the rest in C, so no
 * structure offset is written down in two languages.  `_ctxreturn' hands
 * its own SP to C for the same reason -- *the frame layout belongs to
 * `makecontext', which is C, so the stub carries no magic number.*
 *
 * Plan 9 amd64 calling convention (6c): RARG (= BP) carries the first
 * argument, and the SECOND is at 8(FP), because regaalloc1() reserves a
 * 0(FP) slot for the first even though it arrives in a register.
 *
 * ***AND NO REGISTER SURVIVES A CALL HERE, WHICH IS MEASURED.***
 * `out/bin/6c -S' on a function that computes three values, calls
 * through a function pointer and then uses them spills all three to the
 * stack and touches BX/R12-R15 not at all.  So `_ctxreturn' could not
 * have been written to keep the ucontext pointer in a callee-saved
 * register across the context's own function -- *there are none* --
 * which is why `makecontext' puts it on the new stack instead.
 * (`main9.s:7' calls R12-R15 "callee-saved REGEXT registers"; both can
 * be true, since a register the allocator never hands out is trivially
 * preserved. Nothing here relies on either reading.)
 */

/*
 * _getmcontext(mcontext_t *mc) -- save; returns 0 here, and 0 again
 * when a later _setmcontext resumes it.
 */
TEXT	_getmcontext(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)		/* BP = RARG = mc; restored on resume */
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)		/* R15 = REGEXT */
	MOVL	$0, AX
	RET

/*
 * _setmcontext(const mcontext_t *mc) -- resume; does not return.
 *
 * AX is zeroed before the jump so that the `_getmcontext' or
 * `_swapmcontext' being resumed appears to return 0, the same reason
 * longjmp sets it.  *Without that line a resumed getcontext returns
 * whatever happened to be in AX*, and its caller believes it.
 */
TEXT	_setmcontext(SB), $0
	MOVQ	RARG, R11		/* R11 = mc (scratch, never in the set) */
	MOVQ	16(R11), BP
	MOVQ	24(R11), BX
	MOVQ	32(R11), R12
	MOVQ	40(R11), R13
	MOVQ	48(R11), R14
	MOVQ	56(R11), R15
	MOVQ	0(R11), SP		/* restore SP */
	ADDQ	$8, SP			/* skip the return-address slot */
	MOVQ	8(R11), R11		/* R11 = target PC */
	MOVL	$0, AX			/* resumed call returns 0 */
	JMP	R11			/* no stack write: safe at USTKTOP */

/*
 * _swapmcontext(mcontext_t *old, const mcontext_t *new)
 *
 * The second argument is read FIRST, because everything after it
 * clobbers the stack pointer it would have been read through.
 */
TEXT	_swapmcontext(SB), $0
	MOVQ	newmc+8(FP), R11	/* second arg, before SP moves */

	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)

	MOVQ	16(R11), BP
	MOVQ	24(R11), BX
	MOVQ	32(R11), R12
	MOVQ	40(R11), R13
	MOVQ	48(R11), R14
	MOVQ	56(R11), R15
	MOVQ	0(R11), SP
	ADDQ	$8, SP
	MOVQ	8(R11), R11
	MOVL	$0, AX
	JMP	R11

/*
 * _ctxreturn -- where a makecontext'd function RETURNS to.
 *
 * It is reached by RET, so there is no return address at 0(SP): the
 * stack pointer is whatever `makecontext' arranged, one slot past the
 * cell that held this address.  That SP is the only thing needed to
 * find the ucontext again, and `makecontext' -- which built the frame
 * -- is the only code that should know where in it the pointer sits.
 * So this hands SP to C and stops.
 */
TEXT	_ctxreturn(SB), $0
	MOVQ	SP, RARG		/* _ctxfinish(sp) */
	JMPF	_ctxfinish(SB)
