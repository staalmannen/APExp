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
 * _notejmp(Ureg *u, int ret, unsigned long long pc, unsigned long long sp)
 * RARG = u
 * 8(FP) = ret
 * 16(FP) = pc
 * 24(FP) = sp
 */
TEXT	_notejmp(SB), $0
	MOVL	ret+8(FP), AX
	MOVQ	AX, 0(RARG)	/* u->ax = ret */
	MOVQ	pc+16(FP), BX
	MOVQ	BX, 144(RARG)	/* u->pc = pc */
	MOVQ	sp+24(FP), CX
	MOVQ	CX, 168(RARG)	/* u->sp = sp */
	MOVL	$3, AX		/* NRSTR (noted(3)) */
	SYSCALL
	RET
