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
	
	MOVQ	0(RARG), SP
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
	
	/* Save rest into jmpbuf at offset 16 without modifying RARG */
	MOVQ	RARG, R11
	ADDQ	$16, R11
	MOVQ	SP, 0(R11)
	MOVQ	0(SP), AX
	MOVQ	AX, 8(R11)	/* PC */
	MOVQ	BP, 16(R11)
	MOVQ	BX, 24(R11)
	MOVQ	R12, 32(R11)
	MOVQ	R13, 40(R11)
	MOVQ	R14, 48(R11)
	MOVQ	R15, 56(R11)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	MOVQ	SP, R11		/* Use R11 as scratch to save SP */
	SUBQ	$32, SP		/* Create frame and align */
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)	/* msg at 8(FP) */
	CALL	_ape_notehandler(SB)
	
	/* If handler returns, terminate (NDFLT) */
	MOVQ	R11, SP		/* Restore SP to find u again */
	MOVQ	$1, RARG	/* Arg 0: NDFLT */
	CALL	_signoted(SB)
	RET

/*
 * Stack-safe kernel restore.
 */
TEXT	_signoted(SB), 1, $0
	/* v is in RARG */
	MOVQ	SP, R13		/* Use R13 (preserved by SYSCALL) to save SP */
	SUBQ	$128, SP	/* Stay away from USTKTOP */
	ANDQ	$~15, SP
	
	MOVQ	RARG, 8(SP)	/* Arg 0: v on stack */
	MOVQ	$33, R15	/* Syscall 33 (noted) in R15 */
	SYSCALL
	
	MOVQ	R13, SP
	RET
