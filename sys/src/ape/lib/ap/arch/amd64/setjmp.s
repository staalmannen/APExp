TEXT	longjmp(SB), $0
	MOVL	val+0(FP), AX	/* return value in 0(FP) */
	CMPL	AX, $0
	JNE	ok		/* ansi: "longjmp(0) => longjmp(1)" */
	MOVL	$1, AX
ok:
	MOVQ	0(DI), SP	/* restore sp */
	MOVQ	8(DI), BX	/* get return pc */
	MOVQ	BX, 0(SP)	/* put return pc on stack for RET */
	RET

TEXT	setjmp(SB), $0
	LEAQ	8(SP), BX	/* store sp as it would be after RET */
	MOVQ	BX, 0(DI)
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 8(DI)
	MOVL	$0, AX		/* return 0 */
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+0(FP), BX /* savemask in 0(FP) */
	MOVQ	$0, 0(DI)	/* clear first 8 bytes (mask + bits) */
	MOVL	BX, 0(DI)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), BX
	MOVQ	BX, 8(DI)	/* store 64-bit blocked mask at offset 8 */
	LEAQ	8(SP), BX	/* store sp as it would be after RET */
	MOVQ	BX, 16(DI)	/* offset 16 for jmpbuf[SP] */
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 24(DI)	/* offset 24 for jmpbuf[PC] */
	MOVL	$0, AX	/* return 0 */
	RET
