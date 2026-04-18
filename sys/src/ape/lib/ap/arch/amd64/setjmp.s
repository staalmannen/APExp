/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(R15)	/* R15 is RARG */
	MOVQ	0(SP), AX
	MOVQ	AX, 8(R15)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	MOVL	val+8(SP), AX	/* val is second arg */
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	0(R15), SP	/* restore sp */
	MOVQ	8(R15), BX	/* return pc */
	MOVQ	BX, 0(SP)
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(SP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)	/* setmask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)	/* blocked */
	MOVQ	SP, 16(R15)	/* jmpbuf[0] (SP) */
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)	/* jmpbuf[1] (PC) */
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers u in BP (kernel's RARG), msg at 8(SP).
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	BP, R15		/* Bridge Kernel RARG (BP) to 6c RARG (R15) */
	MOVQ	40(SP), AX	/* msg (original 8(SP) + 32 byte frame) */
	MOVQ	AX, 8(SP)	/* msg to second arg slot for C */
	CALL	_ape_notehandler(SB)
	
	/* Terminate if returns */
	MOVQ	$1, R15		/* NDFLT */
	CALL	_signoted(SB)
	RET

/*
 * Internal noted() bridge
 */
TEXT	_signoted(SB), 1, $0
	MOVQ	R15, 8(SP)	/* code into first arg slot for kernel */
	MOVQ	$33, R15	/* noted syscall */
	SYSCALL
	RET
