TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX	/* return value is the second argument */
	TESTL	AX, AX
	JNZ	ok		/* ansi: "longjmp(0) => longjmp(1)" */
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP	/* restore sp from env[0] */
	MOVQ	8(RARG), BX	/* get return pc from env[1] */
	MOVQ	BX, 0(SP)	/* put return pc back on stack for RET */
	RET

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)	/* store sp in env[0] */
	MOVQ	0(SP), BX	/* store return pc in env[1] */
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX		/* return 0 */
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), BX /* savemask is the second argument */
	MOVQ	$0, 0(RARG)	/* clear first 8 bytes of sigjmp_buf */
	MOVL	BX, 0(RARG)	/* store 32-bit savemask at offset 0 */
	MOVQ	_psigblocked(SB), CX
	MOVQ	CX, 8(RARG)	/* store 64-bit blocked mask at offset 8 */
	MOVQ	SP, 16(RARG)	/* store sp at offset 16 (jmp_buf[0]) */
	MOVQ	0(SP), DX
	MOVQ	DX, 24(RARG)	/* store return pc at offset 24 (jmp_buf[1]) */
	MOVL	$0, AX		/* return 0 */
	RET
