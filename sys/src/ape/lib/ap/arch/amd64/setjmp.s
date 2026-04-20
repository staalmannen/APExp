/*
 * amd64 setjmp/longjmp
 *
 * jmp_buf layout (8-byte slots):
 *  [0]: SP   [1]: PC   [2]: BP   [3]: BX
 *  [4]: R12  [5]: R13  [6]: R14  [7]: R15
 *
 * sigjmp_buf layout:
 *  [0]: set (savemask flag, 4 bytes used)
 *  [8]: blocked (_psigblocked value)
 * [16]: jmpbuf[0..7] as above (SP, PC, BP, BX, R12..R15)
 *
 * Plan 9 amd64 calling convention:
 *   RARG (= BP) carries the first argument (pointer).
 *   Subsequent args are on the stack at 0(FP), 8(FP), ...
 *   (FP = SP + frame_size + 8; for frame $0: FP = SP + 8)
 *
 * Syscall convention:
 *   RARG = syscall number; first user arg at 0(FP) = 8(SP).
 *
 * _notehandler assembly:
 *   The kernel calls the notify handler with RARG=nureg,
 *   [sp+8]=nureg, [sp+16]=msg.  The assembly wrapper moves msg
 *   from [sp+16] to 0(FP) of _ape_notehandler (APExp C convention).
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	MOVL	val+0(FP), AX		/* second arg: val at 0(FP) */
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(RARG), BP
	MOVQ	24(RARG), BX
	MOVQ	32(RARG), R12
	MOVQ	40(RARG), R13
	MOVQ	48(RARG), R14
	MOVQ	56(RARG), R15
	MOVQ	0(RARG), SP
	ADDQ	$8, SP			/* simulate pop of return address */
	MOVQ	8(RARG), DI		/* target PC into scratch reg */
	JMP	DI			/* no write to stack */

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+0(FP), AX	/* second arg: savemask at 0(FP) */
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)		/* set savemask flag (low 32 bits) */
	MOVQ	_psigblocked(SB), AX	/* VALUE of _psigblocked, not address */
	MOVQ	AX, 8(RARG)
	/* inline setjmp at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 24(RARG)
	MOVQ	BP, 32(RARG)
	MOVQ	BX, 40(RARG)
	MOVQ	R12, 48(RARG)
	MOVQ	R13, 56(RARG)
	MOVQ	R14, 64(RARG)
	MOVQ	R15, 72(RARG)
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes (registered via _NOTIFY).
 *
 * The kernel delivers notes by jumping here with:
 *   RARG (BP) = nureg*
 *   [sp+0]   = 0  (return PC placeholder)
 *   [sp+8]   = nureg*  (first arg, also in RARG)
 *   [sp+16]  = msg*    (second arg)
 *
 * APExp's C calling convention: first arg in RARG only (not on stack);
 * second arg at 0(FP) = 8(SP_in_callee).
 * We must move msg from [sp+16] to 0(SP) before CALL so that after
 * CALL pushes the return PC, msg ends up at 8(SP) = 0(FP). ✓
 *
 * _ape_notehandler never returns — it always calls _NOTED before returning.
 */
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG		/* nureg (redundant: kernel already set RARG) */
	MOVQ	16(SP), AX		/* msg */
	MOVQ	SP, R11			/* save SP for return */
	SUBQ	$16, SP
	ANDQ	$~15, SP		/* align stack to 16 bytes */
	MOVQ	AX, 0(SP)		/* msg at 0(SP): after CALL → 0(FP) in callee */
	CALL	_ape_notehandler(SB)	/* RARG=nureg, 0(FP)=msg */
	/* _ape_notehandler always calls _NOTED; should not return here */
	MOVQ	R11, SP
	RET
