/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15 (RARG)
 */

TEXT	setjmp(SB), 1, $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX
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
	MOVQ	8(RARG), DI
	MOVQ	56(RARG), R15
	MOVQ	DI, 0(SP)
	RET

TEXT	sigsetjmp(SB), 1, $0
	MOVL	savemask+8(FP), AX
	MOVQ	AX, 0(RARG)
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)
	
	/* Save rest into jmpbuf at offset 16 */
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
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	MOVQ	SP, R11
	SUBQ	$1024, SP
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)	/* msg at 8(FP) for _ape_notehandler */
	CALL	_ape_notehandler(SB)
	
	/* If handler returns, terminate (NDFLT) */
	MOVQ	1032(SP), RARG  /* Restore u from original 8(SP) */
	MOVQ	$1, 8(SP)	/* Arg 1: NDFLT */
	CALL	_signoted(SB)
	RET

/*
 * Stack-safe kernel restore.
 */
TEXT	_signoted(SB), 1, $0
	MOVQ	v+8(FP), AX
	MOVQ	SP, R11
	SUBQ	$128, SP
	ANDQ	$~15, SP
	
	MOVQ	RARG, 8(SP)	/* Arg 0: u */
	MOVQ	AX, 16(SP)	/* Arg 1: v */
	MOVQ	$33, R15	/* syscall noted */
	SYSCALL
	
	MOVQ	R11, SP
	RET
