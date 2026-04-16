TEXT	longjmp(SB), $0
	MOVQ	buf+0(FP), RARG	/* Ensure RARG points to jmp_buf */
	MOVL	val+8(FP), AX	/* val is the second argument */
	CMPL	AX, $0
	JNE	ok		/* ansi: "longjmp(0) => longjmp(1)" */
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP	/* restore sp exactly as it was at setjmp entry */
	MOVQ	8(RARG), BX	/* get return pc */
	MOVQ	BX, 0(SP)	/* put return pc back on stack */
	RET

TEXT	setjmp(SB), $0
	MOVQ	buf+0(FP), RARG	/* Ensure RARG points to jmp_buf */
	MOVQ	SP, 0(RARG)	/* store sp */
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX		/* return 0 */
	RET

TEXT	sigsetjmp(SB), $0
	MOVQ	buf+0(FP), RARG	/* RARG = sigjmp_buf */
	MOVL	savemask+8(FP), BX /* savemask is the second argument */
	MOVQ	$0, 0(RARG)	/* clear first 8 bytes (mask + bits) */
	MOVL	BX, 0(RARG)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), BX
	MOVQ	BX, 8(RARG)	/* store 64-bit blocked mask at offset 8 */
	MOVQ	SP, 16(RARG)	/* offset 16 for jmpbuf[SP] */
	MOVQ	0(SP), BX	/* store return pc */
	MOVQ	BX, 24(RARG)	/* offset 24 for jmpbuf[PC] */
	MOVL	$0, AX	/* return 0 */
	RET
