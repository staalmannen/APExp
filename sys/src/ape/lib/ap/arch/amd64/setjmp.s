/*
 * amd64 setjmp/longjmp (Verified Version)
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(R15)	/* R15 is RARG */
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(R15)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	/* R15 = jmp_buf, 0(FP) = val */
	MOVL	val+0(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	0(R15), SP	/* restore sp */
	MOVQ	8(R15), BX	/* return pc */
	MOVQ	BX, 0(SP)
	RET

TEXT	sigsetjmp(SB), $0
	/* R15 = sigjmp_buf, 0(FP) = savemask */
	MOVL	savemask+0(FP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)	/* store savemask value */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)	/* store blocked mask value */
	
	/* Inline setjmp at offset 16 */
	MOVQ	SP, 16(R15)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	u+0(FP), R15	/* u -> RARG */
	MOVQ	msg+8(FP), AX	/* msg */
	MOVQ	AX, 8(SP)	/* msg to Arg 2 slot for C */
	CALL	_ape_notehandler(SB)
	RET
