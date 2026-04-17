/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP
 *  8: PC
 * 16: BP
 * 24: BX
 * 32: R12
 * 40: R13
 * 48: R14
 * 56: R15 (RARG)
 */

TEXT	longjmp(SB), $0
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
	/* R15 (RARG) is restored last as we are using it now */
	
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), DI	/* target PC */
	MOVQ	56(RARG), R15	/* restore RARG */
	
	MOVQ	DI, 0(SP)	/* put return PC on stack for RET */
	RET

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), BX
	MOVQ	BX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)
	MOVL	$0, AX
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), BX
	MOVQ	$0, 0(RARG)
	MOVL	BX, 0(RARG)	/* store savemask */
	MOVQ	_psigblocked(SB), CX
	MOVQ	CX, 8(RARG)	/* store blocked mask */
	
	/* jmp_buf starts at offset 16 in sigjmp_buf */
	LEAQ	16(RARG), DI	/* DI = &sigjmp_buf[16] */
	MOVQ	SP, 0(DI)
	MOVQ	0(SP), BX
	MOVQ	BX, 8(DI)
	MOVQ	BP, 16(DI)
	MOVQ	BX, 24(DI)
	MOVQ	R12, 32(DI)
	MOVQ	R13, 40(DI)
	MOVQ	R14, 48(DI)
	MOVQ	R15, 56(DI)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	SUBQ	$16, SP
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)
	CALL	_ape_notehandler(SB)
	RET
