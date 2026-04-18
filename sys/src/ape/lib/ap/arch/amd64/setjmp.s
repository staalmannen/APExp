/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), $0
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

TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	RARG, R11	/* Use R11 as scratch pointer to jmp_buf */
	MOVQ	16(R11), BP
	MOVQ	24(R11), BX
	MOVQ	32(R11), R12
	MOVQ	40(R11), R13
	MOVQ	48(R11), R14
	MOVQ	56(R11), R15
	
	MOVQ	0(R11), SP	/* Restore SP */
	MOVQ	8(R11), DI	/* Target PC */
	MOVQ	DI, 0(SP)	/* Put PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store blocked mask */
	
	/* Inline setjmp logic into the sigjmp_buf starting at offset 16 */
	MOVQ	RARG, R11
	ADDQ	$16, R11
	MOVQ	SP, 0(R11)
	MOVQ	0(SP), AX
	MOVQ	AX, 8(R11)
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
	PUSHQ	RARG		/* Save context pointer */
	MOVQ	8(SP), RARG	/* u into RARG for 6c */
	MOVQ	16(SP), AX	/* msg */
	PUSHQ	AX
	PUSHQ	RARG
	CALL	_ape_notehandler(SB)
	POPQ	RARG
	POPQ	AX
	POPQ	RARG
	_NOTED(0)		/* Continue */
	RET
