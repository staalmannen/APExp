/*
 * amd64 setjmp/longjmp (Back to Basics)
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12 (unused)
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(RARG), BP
	MOVQ	24(RARG), BX
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), DI	/* Target PC */
	JMP	DI

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* set */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* blocked */
	
	/* Inline setjmp at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)
	MOVQ	BP, 32(RARG)
	MOVQ	BX, 40(RARG)
	MOVL	$0, AX
	RET

TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	PUSHQ	AX
	PUSHQ	RARG
	CALL	_ape_notehandler(SB)
	POPQ	RARG
	POPQ	AX
	/* If we return, must terminate */
	MOVQ	$1, RARG	/* NDFLT */
	CALL	_signoted(SB)
	RET

TEXT	_signoted(SB), $0
	MOVL	v+8(FP), AX
	SUBQ	$128, SP
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)
	MOVQ	$33, R15	/* noted */
	SYSCALL
	RET
