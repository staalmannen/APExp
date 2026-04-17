TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP
	MOVQ	8(RARG), BX
	MOVQ	BX, 0(SP)	/* Put return PC where RET expects it */
	RET

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), BX	/* Store the return PC */
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
 * Kernel pushes: msg(16(SP)), u(8(SP)), dummy_pc(0(SP)).
 * 6c expects u in RARG, msg at 8(FP).
 */
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	MOVQ	SP, BX		/* Save old SP */
	SUBQ	$16, SP
	ANDQ	$~15, SP	/* Force 16-byte alignment */
	MOVQ	AX, 8(SP)	/* msg at 8(FP) */
	CALL	_ape_notehandler(SB)
	MOVQ	BX, SP		/* Restore old SP */
	RET

/*
 * Trampoline for notecont.
 * Kernel restores registers and SP and jumps here.
 * u and msg are on the stack as above.
 */
TEXT	_notecont_trampoline(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	MOVQ	SP, BX
	SUBQ	$16, SP
	ANDQ	$~15, SP	/* Force 16-byte alignment */
	MOVQ	AX, 8(SP)
	CALL	notecont(SB)
	MOVQ	BX, SP
	RET
