/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP
 *  8: PC
 * 16: BP
 * 24: BX
 * 32: R12
 * 40: R13
 * 48: R14
 * 56: R15 (RARG)
 */

TEXT	setjmp(SB), 1, $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(RARG)
	MOVQ	BP, 16(RARG)
	MOVQ	BX, 24(RARG)
	MOVQ	R12, 32(RARG)
	MOVQ	R13, 40(RARG)
	MOVQ	R14, 48(RARG)
	MOVQ	R15, 56(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), 1, $0
	MOVL	val+8(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(RARG), BP
	MOVQ	24(RARG), BX
	MOVQ	32(RARG), R12
	MOVQ	40(RARG), R13
	MOVQ	48(RARG), R14
	
	MOVQ	0(RARG), SP	/* Restore SP to call site state */
	MOVQ	8(RARG), DI	/* Target PC */
	MOVQ	56(RARG), R15	/* Restore RARG (R15) */
	
	MOVQ	DI, 0(SP)	/* Put target PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store 64-bit blocked mask */
	
	/* Fully implement jmp_buf save at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)	/* PC */
	MOVQ	BP, 32(RARG)
	MOVQ	BX, 40(RARG)
	MOVQ	R12, 48(RARG)
	MOVQ	R13, 56(RARG)
	MOVQ	R14, 64(RARG)
	MOVQ	R15, 72(RARG)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	MOVQ	SP, R11		/* Save current SP in scratch register */
	SUBQ	$16, SP		/* Align stack */
	ANDQ	$~15, SP
	MOVQ	AX, 8(SP)	/* msg at 8(FP) */
	CALL	_ape_notehandler(SB)
	MOVQ	R11, SP
	RET

/*
 * Stack-safe kernel restore.
 * _signoted(Ureg *u, int ret, unsigned long long pc, unsigned long long sp)
 * Performs noted(NRSTR) without using the user stack for locals.
 */
TEXT	_signoted(SB), 1, $0
	MOVQ	RARG, R11	/* Use R11 as scratch pointer to Ureg */
	MOVL	ret+8(FP), AX
	MOVQ	AX, 0(R11)	/* u->ax = ret */
	MOVQ	pc+16(FP), AX
	MOVQ	AX, 144(R11)	/* u->pc = pc */
	MOVQ	sp+24(FP), AX
	MOVQ	AX, 168(R11)	/* u->sp = sp */
	
	MOVQ	$3, 8(SP)	/* noted(3) - NRSTR on stack */
	MOVQ	$33, R15	/* syscall 33 (noted) in RARG */
	SYSCALL
	RET
