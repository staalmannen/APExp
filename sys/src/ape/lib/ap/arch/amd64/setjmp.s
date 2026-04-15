TEXT	longjmp(SB), $0
	MOVL	r+8(FP), AX
	CMPL	AX, $0
	JNE	ok		/* ansi: "longjmp(0) => longjmp(1)" */
	MOVL	$1, AX		/* bless their pointed heads */
ok:
	MOVQ	0(RARG), SP	/* restore sp */
	MOVQ	8(RARG), BX	/* put return pc on the stack */
	MOVQ	BX, 0(SP)
	RET

TEXT	setjmp(SB), $0
	LEAQ	8(SP), BX	/* store sp as it would be after RET */
	MOVQ	BX, 0(RARG)
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX		/* return 0 */
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), BX
	MOVQ	$0, 0(RARG)	/* clear first 8 bytes of sigjmp_buf (mask + bits) */
	MOVL	BX, 0(RARG)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), BX
	MOVQ	BX, 8(RARG)	/* store 64-bit blocked mask at offset 8 */
	LEAQ	8(SP), BX	/* store sp as it would be after RET */
	MOVQ	BX, 16(RARG)	/* offset 16 for jmpbuf[SP] */
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 24(RARG)	/* offset 24 for jmpbuf[PC] */
	MOVL	$0, AX	/* return 0 */
	RET
