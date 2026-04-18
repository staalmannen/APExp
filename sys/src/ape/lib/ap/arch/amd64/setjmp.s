/*
 * amd64 setjmp/longjmp (Stack-Safe Version)
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
	/* RARG = jmp_buf, 0(FP) = val */
	MOVL	val+0(FP), AX
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
	ADDQ	$8, SP		/* Stack-safe: simulate POP of return address */
	MOVQ	8(RARG), DI	/* Target PC */
	JMP	DI		/* Jump without writing to stack */

TEXT	sigsetjmp(SB), $0
	/* RARG = sigjmp_buf, 0(FP) = savemask */
	MOVL	savemask+0(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store blocked mask */
	
	/* Inline setjmp logic into sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(RARG)	/* jmpbuf[0] */
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)	/* jmpbuf[1] */
	MOVQ	BP, 32(RARG)	/* jmpbuf[2] */
	MOVQ	BX, 40(RARG)	/* jmpbuf[3] */
	MOVQ	R12, 48(RARG)	/* jmpbuf[4] */
	MOVQ	R13, 56(RARG)	/* jmpbuf[5] */
	MOVQ	R14, 64(RARG)	/* jmpbuf[6] */
	MOVQ	R15, 72(RARG)	/* jmpbuf[7] */
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	u+8(FP), RARG	/* u */
	MOVQ	msg+16(FP), AX	/* msg */
	MOVQ	AX, 8(SP)	/* msg at 8(FP) for C */
	CALL	_ape_notehandler(SB)
	RET
