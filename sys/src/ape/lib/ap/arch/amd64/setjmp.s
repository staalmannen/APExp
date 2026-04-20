/*
 * amd64 setjmp/longjmp for APExp.
 *
 * Two fixes from upstream 9front:
 *
 * 1. Arg offset: APExp 6c puts the first arg in RARG (BP) but regaalloc1 still
 *    reserves a 0(FP) slot for it.  So the second arg is at 8(FP)=[SP+16],
 *    same as upstream 9front.  main9.s uses PUSHQ RARG + PUSHQ $0 to shift
 *    the kernel's initial argc/arg0 from [SP+0]/[SP+8] to [SP+16]/[SP+24].
 *
 * 2. longjmp stack safety: upstream writes the return PC to 0(SP) then RETs,
 *    which faults if SP is at USTKTOP (0x7ffffffff000) as it often is at
 *    process start.  Fixed by using ADDQ $8,SP + JMP — no stack write.
 *
 * 3. sigsetjmp _psigblocked: upstream stores the ADDRESS ($symbol) rather
 *    than the VALUE.  Fixed by loading through the symbol.
 *
 * Everything else is identical to upstream 9front amd64/setjmp.s.
 */

TEXT	longjmp(SB), $0
	MOVL	r+8(FP), AX		/* second arg at 8(FP): regaalloc1 reserves slot at 0(FP) for RARG */
	CMPL	AX, $0
	JNE	ok			/* ansi: "longjmp(0) => longjmp(1)" */
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP		/* restore sp */
	ADDQ	$8, SP			/* skip return-address slot; no stack write */
	MOVQ	8(RARG), BX		/* target PC into scratch register */
	JMP	BX			/* stack-safe: no write near USTKTOP */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)		/* store sp */
	MOVQ	0(SP), BX		/* store return pc */
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX			/* return 0 */
	RET

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), BX	/* second arg at 8(FP): regaalloc1 reserves 0(FP) for RARG */
	MOVL	BX, 0(RARG)
	MOVQ	_psigblocked(SB), BX	/* VALUE of _psigblocked, not address */
	MOVQ	BX, 8(RARG)
	MOVQ	SP, 16(RARG)		/* store sp (offset +8 vs upstream: extra 8 for blocked) */
	MOVQ	0(SP), BX		/* store return pc */
	MOVQ	BX, 24(RARG)
	MOVL	$0, AX			/* return 0 */
	RET
