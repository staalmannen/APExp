TEXT	setjmp(SB), 1, $-8
	MOVD	LR, R4
	MOVD	RSP, (RARG)
	MOVD	R4, 8(RARG)
	MOVW	$0, RARG
	RETURN

TEXT	sigsetjmp(SB), 1, $-8
	MOVW	savemask+4(FP), R4
	MOVW	R4, 0(RARG)
	MOVW	$_psigblocked(SB), R4
	MOVW	R4, 4(RARG)
	MOVD	LR, R4
	MOVD	R1, 8(RARG)
	MOVD	R4, 16(RARG)
	MOVW	$0, RARG
	RETURN

TEXT	longjmp(SB), 1, $-8
	MOVD	RARG, R4
	MOVW	r+12(FP), RARG
	CMP	RARG, $0
	BNE	ok		/* ansi: "longjmp(0) => longjmp(1)" */
	MOVW	$1, RARG		/* bless their pointed heads */
ok:	MOVD	(R4), RSP
	MOVD	8(R4), R4
	MOVD	R4, LR
	BR	(LR)

/*
 * trampoline functions because the kernel smashes r3
 * in the uregs given to notejmp
 */
TEXT	__noterestore(SB), 1, $-8
	MOVD	R4, RARG
	MOVD	R5, LR
	BR	(LR)
