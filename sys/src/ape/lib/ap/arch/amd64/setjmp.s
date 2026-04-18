/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), 1, $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), 1, $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(RARG), BP
	MOVQ	24(RARG), BX
	MOVQ	32(RARG), R12
	MOVQ	40(RARG), R13
	MOVQ	48(RARG), R14
	
	MOVQ	0(RARG), SP	/* Restore SP to call site state */
	MOVQ	8(RARG), DI	/* Target PC */
	MOVQ	56(RARG), R15	/* Restore R15 last */
	
	MOVQ	DI, 0(SP)	/* Put target PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store 64-bit blocked mask */
	
	/* Inline setjmp logic into the sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(RARG)	/* index 0 of jmpbuf part */
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)	/* index 1 (PC) */
	MOVQ	BP, 32(RARG)	/* index 2 (BP) */
	MOVQ	BX, 40(RARG)	/* index 3 (BX) */
	MOVQ	R12, 48(RARG)	/* index 4 (R12) */
	MOVQ	R13, 56(RARG)	/* index 5 (R13) */
	MOVQ	R14, 64(RARG)	/* index 6 (R14) */
	MOVQ	R15, 72(RARG)	/* index 7 (R15) */
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	
	PUSHQ	R12		/* Save callee-saved scratch */
	MOVQ	SP, R12
	SUBQ	$32, SP		/* Create frame and align */
	ANDQ	$~15, SP
	
	MOVQ	AX, 8(SP)	/* msg at 8(FP) for C */
	CALL	_ape_notehandler(SB)
	
	/* If handler returns, terminate (NDFLT) */
	MOVQ	R12, SP		/* Restore SP to find original u */
	MOVQ	8(SP), RARG	/* Arg 0: u */
	MOVQ	$1, AX		/* Arg 1: NDFLT */
	PUSHQ	AX
	PUSHQ	RARG
	CALL	_signoted(SB)
	POPQ	RARG
	POPQ	AX
	POPQ	R12
	RET

/*
 * Stack-safe kernel restore bridge.
 * _signoted(Ureg *u, int v)
 */
TEXT	_signoted(SB), 1, $0
	/* u is in RARG, v is at 8(FP) */
	MOVL	v+8(FP), AX
	
	PUSHQ	R12		/* Save callee-saved (SYSCALL-preserved) */
	MOVQ	SP, R12
	SUBQ	$128, SP	/* Stay away from USTKTOP boundary */
	ANDQ	$~15, SP
	
	MOVQ	RARG, 8(SP)	/* Arg 0: u */
	MOVQ	AX, 16(SP)	/* Arg 1: v */
	MOVQ	$33, R15	/* syscall noted */
	SYSCALL
	
	MOVQ	R12, SP
	POPQ	R12
	RET
