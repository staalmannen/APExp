/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), 1, $0
	MOVQ	SP, 0(R15)	/* R15 is RARG */
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(R15)
	MOVQ	BP, 16(R15)
	MOVQ	BX, 24(R15)
	MOVQ	R12, 32(R15)
	MOVQ	R13, 40(R15)
	MOVQ	R14, 48(R15)
	MOVQ	R15, 56(R15)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), 1, $0
	MOVL	val+8(FP), AX	/* val is second arg */
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(R15), BP
	MOVQ	24(R15), BX
	MOVQ	32(R15), R12
	MOVQ	40(R15), R13
	MOVQ	48(R15), R14
	
	MOVQ	0(R15), SP
	MOVQ	8(R15), DI	/* Target PC */
	MOVQ	56(R15), R15
	
	MOVQ	DI, 0(SP)	/* Put target PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)
	
	/* Inline setjmp logic into sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(R15)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)
	MOVQ	BP, 32(R15)
	MOVQ	BX, 40(R15)
	MOVQ	R12, 48(R15)
	MOVQ	R13, 56(R15)
	MOVQ	R14, 64(R15)
	MOVQ	R15, 72(R15)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers u in BP (kernel's RARG), msg at 8(SP).
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	BP, R15		/* Bridge Kernel RARG to 6c R15 */
	MOVQ	40(SP), AX	/* Original 8(SP) is msg */
	MOVQ	AX, 8(SP)	/* msg to Arg 2 slot for C */
	CALL	_ape_notehandler(SB)
	
	/* Terminate if returns */
	MOVQ	BP, R15
	MOVQ	$1, AX
	MOVQ	AX, 8(SP)
	CALL	_signoted(SB)
	RET

/*
 * Stack-safe kernel noted(u, v) bridge.
 */
TEXT	_signoted(SB), 1, $128
	MOVQ	u+0(FP), R11
	MOVL	v+8(FP), AX
	MOVQ	R11, 8(SP)	/* Arg 0: u */
	MOVQ	AX, 16(SP)	/* Arg 1: v */
	MOVQ	$33, BP		/* syscall noted in BP (kernel RARG) */
	SYSCALL
	RET
