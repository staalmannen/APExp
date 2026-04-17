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
	
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), DI	/* target PC */
	MOVQ	56(RARG), R15	/* restore RARG last */
	
	MOVQ	DI, 0(SP)	/* put return PC on stack for RET */
	RET

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)
	MOVQ	0(SP), AX	/* Use AX as scratch for return PC */
	MOVQ	AX, 8(RARG)
	MOVL	$0, AX
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store savemask */
	MOVQ	_psigblocked(SB), CX
	MOVQ	CX, 8(RARG)	/* store blocked mask */
	
	/* jmp_buf starts at offset 16 in sigjmp_buf */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), CX	/* Use CX as scratch for return PC */
	MOVQ	CX, 24(RARG)
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
 * 6c expects u in RARG, msg at 8(FP).
 */
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	SUBQ	$16, SP		/* Align stack */
	MOVQ	AX, 8(SP)	/* msg at 8(FP) */
	CALL	_ape_notehandler(SB)
	RET
