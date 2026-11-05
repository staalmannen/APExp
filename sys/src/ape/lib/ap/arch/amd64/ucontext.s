/*
 * amd64 context switch for <ucontext.h>: getcontext, setcontext,
 * swapcontext.  `makecontext.c' has the rest.
 *
 * ***THIS IS `setjmp.s' WITH THE RETURN-VALUE CONVENTION CHANGED, AND
 * THAT IS THE WHOLE DESIGN.*** The two problems are the same one. Read
 * that file first; both of its findings carry over unchanged:
 *
 *   - **eight registers, not two.** 6c has REGEXT = D_R15, so R15 and
 *     R14 are reserved program-wide (`6c/reg.c:55-57') and R13/R12 may
 *     follow them as caches for global variables. Restoring only SP and
 *     PC leaves the resumed code reading another context's globals.
 *   - **the restore must not WRITE to the stack.** Upstream longjmp
 *     stores the target PC at 0(SP) and RETs, which faults when SP is
 *     at USTKTOP. `ADDQ $8,SP' then `JMP' does the same without the
 *     store, and a context resumed at the top of a freshly allocated
 *     fiber stack is exactly that case.
 *
 * ***AND ALL THREE ARE ASSEMBLY BECAUSE A C WRAPPER CANNOT SAVE ITS
 * CALLER'S FRAME, WHICH COST A ROUND TO LEARN.*** The first version had
 * these as C around three register-only primitives, so what
 * `getcontext' saved was a point inside `getcontext' itself. That is
 * fine until the context is RESUMED after `getcontext' has returned --
 * by then the wrapper's frame is dead stack, its own return-address
 * slot has been reused by whatever the caller did next, and the resumed
 * epilogue RETs to that. `ucontext-test' section 0 printed its PASS
 * line once instead of twice and reported `setcontext came back round:
 * got 1 want 2': control had landed after the `setcontext' CALL,
 * because *setcontext's* return address was sitting in the slot.
 *
 * **The same reasoning says why `swapcontext' got away with it**, which
 * is worth stating so the lesson is not over-general: a context saved
 * by `swapcontext' is resumed while that stack is parked, so nothing
 * has run on it and the frame is still intact. Sections 1 to 4 passed
 * for that reason. *`getcontext' is the one that returns and then gets
 * resumed*, and it is the only one that could have shown this.
 *
 * **The cost of asm is one shared offset**, `uc_sigmask' at 64, which
 * `makecontext.c' asserts at COMPILE TIME rather than trusting. The
 * mask itself is handled as `sigsetjmp' handles it -- through
 * `_psigblocked(SB)' -- and with `MOVL', because `sigset_t' is `long'
 * and kencc's `long' is four bytes.
 *
 * Plan 9 amd64 calling convention (6c): RARG (= BP) carries the first
 * argument, and the SECOND is at 8(FP), because regaalloc1() reserves a
 * 0(FP) slot for the first even though it arrives in a register.
 *
 * ***AND NO REGISTER SURVIVES A CALL HERE, WHICH IS MEASURED.***
 * A host `6c -S' on a function that computes three values, calls
 * through a function pointer and then uses them spills all three to the
 * stack and touches BX and R12-R15 not at all. That is why
 * `makecontext' puts its bookkeeping pointer on the new stack rather
 * than in a register. (`main9.s:7' calls R12-R15 "callee-saved REGEXT
 * registers"; both can be true, since a register the allocator never
 * hands out is trivially preserved. Nothing here relies on either.)
 */

#define	UC_MASK	64		/* offsetof(ucontext_t, uc_sigmask) */

TEXT	getcontext(SB), $0
	MOVL	_psigblocked(SB), AX	/* the VALUE, not the address */
	MOVL	AX, UC_MASK(RARG)
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC: the CALLER's */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)		/* BP = RARG = ucp; restored on resume */
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)		/* R15 = REGEXT */
	MOVL	$0, AX
	RET

/*
 * setcontext does not return.  AX is zeroed before the jump so that the
 * `getcontext' or `swapcontext' being resumed appears to return 0 --
 * the same reason longjmp sets it.  *Without that line a resumed
 * getcontext returns whatever was in AX and its caller believes it.*
 */
TEXT	setcontext(SB), $0
	MOVQ	RARG, R11		/* R11: scratch, never in the saved set */
	MOVL	UC_MASK(R11), AX
	MOVL	AX, _psigblocked(SB)
	MOVQ	16(R11), BP
	MOVQ	24(R11), BX
	MOVQ	32(R11), R12
	MOVQ	40(R11), R13
	MOVQ	48(R11), R14
	MOVQ	56(R11), R15
	MOVQ	0(R11), SP
	ADDQ	$8, SP			/* skip the return-address slot */
	MOVQ	8(R11), R11
	MOVL	$0, AX
	JMP	R11			/* no stack write: safe at USTKTOP */

/*
 * swapcontext(ucontext_t *oucp, const ucontext_t *ucp)
 *
 * The second argument is read FIRST, because everything after it
 * clobbers the stack pointer it would have been read through.
 */
TEXT	swapcontext(SB), $0
	MOVQ	ucp+8(FP), R11		/* second arg, before SP moves */

	MOVL	_psigblocked(SB), AX
	MOVL	AX, UC_MASK(RARG)
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)

	MOVL	UC_MASK(R11), AX
	MOVL	AX, _psigblocked(SB)
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
 * So this hands SP to C and stops, and no frame offset is written down
 * in two languages.
 */
TEXT	_ctxreturn(SB), $0
	MOVQ	SP, RARG		/* _ctxfinish(sp) */
	JMPF	_ctxfinish(SB)
