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
 * Kernel puts u at 0(SP) and msg at 8(SP).
 * 6c expects u in RARG (R15).
 */
TEXT	_notehandler(SB), $0
	MOVQ	0(SP), RARG
	JMP	_ape_notehandler(SB)

/*
 * _notejmp(Ureg *u)
 * Safely switch to the Ureg stack and restore via NRSTR.
 */
TEXT	_notejmp(SB), $0
	MOVQ	RARG, SP
	MOVQ	$3, RARG	/* NRSTR */
	MOVL	$33, AX		/* sys noted */
	SYSCALL
	RET
