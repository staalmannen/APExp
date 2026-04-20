/*
 * amd64 setjmp/longjmp for APExp.
 *
 * jmp_buf layout (8-byte slots):
 *  [0]: SP   [1]: PC   [2]: BP   [3]: BX
 *  [4]: R12  [5]: R13  [6]: R14  [7]: R15
 *
 * sigjmp_buf layout:
 *  [0]:  set (savemask flag, 4 bytes; upper 4 zero-padded)
 *  [8]:  blocked (_psigblocked VALUE)
 *  [16]: jmpbuf[0..7] as above
 *
 * Plan 9 amd64 calling convention (APExp / 6c):
 *   RARG (= BP register) carries the first argument.
 *   regaalloc1() reserves a 0(FP) slot for the first arg even when it is
 *   in RARG, so the SECOND arg is at 8(FP)=[SP+16], same as upstream.
 *
 * Why 8 registers: APExp's 6c uses REGEXT=D_R15, meaning R15 (and R14 down)
 * can be allocated as persistent register caches for global variables within
 * a function.  longjmp must restore these so the setjmp-site code sees the
 * correct global-variable-in-register values.  Saving only SP+PC (upstream)
 * is not sufficient; without restoring R15 et al., code at the setjmp target
 * reads stale/garbage global-register values → GPV.
 *
 * Suicide-trap fix: upstream writes the target PC to 0(SP) then RETs.
 * This faults when SP is at USTKTOP.  Instead: ADDQ $8,SP + JMP (no write).
 *
 * sigsetjmp _psigblocked: upstream stores the ADDRESS ($symbol).  We load
 * the value through the symbol instead.
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)		/* BP=RARG=buf ptr; restored by longjmp */
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)		/* R15 = REGEXT (global register cache) */
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	MOVL	val+8(FP), AX		/* second arg at 8(FP) */
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	RARG, R11		/* R11 = jmpbuf ptr (scratch) */
	MOVQ	16(R11), BP
	MOVQ	24(R11), BX
	MOVQ	32(R11), R12
	MOVQ	40(R11), R13
	MOVQ	48(R11), R14
	MOVQ	56(R11), R15		/* restore R15 (REGEXT global cache) */
	MOVQ	0(R11), SP		/* restore SP */
	ADDQ	$8, SP			/* skip return-address slot; no stack write */
	MOVQ	8(R11), R11		/* R11 = target PC */
	JMP	R11			/* stack-safe: no write near USTKTOP */

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+8(FP), AX	/* second arg at 8(FP) */
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)		/* store savemask (low 32 bits) */
	MOVQ	_psigblocked(SB), AX	/* VALUE of _psigblocked, not address */
	MOVQ	AX, 8(RARG)
	/* inline setjmp at offset 16 (jmpbuf[0..7]) */
	MOVQ	RARG, R11
	ADDQ	$16, R11		/* R11 = &jmpbuf[0] */
	MOVQ	SP, 0(R11)
	MOVQ	0(SP), AX		/* return PC */
	MOVQ	AX, 8(R11)
	MOVQ	BP, 16(R11)
	MOVQ	BX, 24(R11)
	MOVQ	R12, 32(R11)
	MOVQ	R13, 40(R11)
	MOVQ	R14, 48(R11)
	MOVQ	R15, 56(R11)		/* R15 = REGEXT */
	MOVL	$0, AX
	RET
