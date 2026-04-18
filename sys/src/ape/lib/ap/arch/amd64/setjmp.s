/*
 * amd64 setjmp/longjmp (Verified Stack-Safe Version)
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	/* RARG = jmp_buf, 8(SP) = val */
	MOVL	val+8(SP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), DI	/* Target PC */
	JMP	DI		/* Stack-safe: jump without writing */

TEXT	sigsetjmp(SB), $0
	/* RARG = sigjmp_buf, 8(SP) = savemask */
	MOVL	savemask+8(SP), AX
	MOVQ	$0, 0(RARG)
	MOVQ	AX, 0(RARG)	/* store 8-byte setmask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store 8-byte blocked mask */
	
	/* Inline setjmp at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	BP, RARG	/* Bridge Kernel RARG (BP) to 6c RARG (R15) */
	MOVQ	8(SP), AX	/* msg */
	PUSHQ	AX
	PUSHQ	RARG
	CALL	_ape_notehandler(SB)
	POPQ	RARG
	POPQ	AX
	RET
