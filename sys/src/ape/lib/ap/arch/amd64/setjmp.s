TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), BX
	MOVQ	BX, 0(SP)
	RET

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), BX
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), BX
	MOVQ	$0, 0(RARG)
	MOVL	BX, 0(RARG)
	MOVQ	_psigblocked(SB), CX
	MOVQ	CX, 8(RARG)
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), DX
	MOVQ	DX, 24(RARG)
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers:
 *   16(SP) = char *msg
 *   8(SP)  = Ureg *u
 *   0(SP)  = dummy PC
 */
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* RARG = u */
	MOVQ	16(SP), AX	/* AX = msg */
	MOVQ	SP, BX		/* Save original SP */
	SUBQ	$16, SP		/* Create frame and align */
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)	/* msg at 8(FP) */
	CALL	_ape_notehandler(SB)
	MOVQ	BX, SP		/* Restore SP */
	RET

/*
 * Trampoline for notecont.
 * Kernel restores SP and jumps here.
 * Arguments u and msg are on the stack as above.
 */
TEXT	_notecont_trampoline(SB), $0
	MOVQ	8(SP), RARG	/* RARG = u */
	MOVQ	16(SP), AX	/* AX = msg */
	MOVQ	SP, BX
	SUBQ	$16, SP
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)
	CALL	notecont(SB)
	MOVQ	BX, SP
	RET
