/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15 (RARG)
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
	MOVQ	56(RARG), R15
	
	MOVQ	DI, 0(SP)	/* Put target PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store 64-bit blocked mask */
	
	/* Inline setjmp logic into the jmpbuf at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)	/* PC */
	MOVQ	BP, 32(RARG)
	MOVQ	BX, 40(RARG)
	MOVQ	R12, 48(RARG)
	MOVQ	R13, 56(RARG)
	MOVQ	R14, 64(RARG)
	MOVQ	R15, 72(RARG)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel pushes: msg(16(SP)), u(8(SP)), dummy_pc(0(SP)).
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	
	PUSHQ	R12		/* Save callee-saved register */
	MOVQ	SP, R12		/* Save SP */
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
	CALL	_signoted(SB)	/* _signoted handles the rest */
	POPQ	RARG
	POPQ	AX
	POPQ	R12
	RET

/*
 * Stack-safe kernel restore.
 * _signoted(Ureg *u, int v)
 */
TEXT	_signoted(SB), 1, $0
	MOVQ	v+8(FP), AX
	/* u is in RARG */
	
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
