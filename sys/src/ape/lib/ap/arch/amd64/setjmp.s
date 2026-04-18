/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15 (RARG)
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
	/* RARG = jmp_buf, 8(FP) = val */
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
	
	MOVQ	0(RARG), SP	/* Restore SP */
	MOVQ	8(RARG), DI	/* Target PC */
	MOVQ	56(RARG), R15	/* Restore RARG last */
	
	MOVQ	DI, 0(SP)	/* Put target PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	/* RARG = sigjmp_buf, 8(FP) = savemask */
	MOVL	savemask+8(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)	/* store savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)	/* store blocked mask */
	
	/* Inline setjmp logic into the sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(RARG)	/* jmpbuf[0] */
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)	/* jmpbuf[1] */
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
TEXT	_notehandler(SB), 1, $32
	MOVQ	u+0(FP), RARG	/* u is first arg at 0(FP) in frame */
	MOVQ	msg+8(FP), AX	/* msg is second arg at 8(FP) */
	MOVQ	AX, 8(SP)	/* msg at 8(FP) for C implementation */
	CALL	_ape_notehandler(SB)
	RET

/*
 * Stack-safe kernel restore bridge.
 * _signoted(Ureg *u, int v, unsigned long long pc, unsigned long long sp)
 */
TEXT	_signoted(SB), 1, $32
	MOVQ	u+0(FP), RARG	/* RARG = u */
	MOVL	v+8(FP), AX	/* AX = v */
	
	/* If v == NRSTR (3), synchronize manual overrides */
	CMPL	AX, $3
	JNE	doit
	MOVQ	pc+16(FP), BX
	MOVQ	BX, 144(RARG)	/* u->pc */
	MOVQ	sp+24(FP), BX
	MOVQ	BX, 168(RARG)	/* u->sp */
doit:
	PUSHQ	R12		/* callee-saved scratch */
	MOVQ	SP, R12
	SUBQ	$128, SP	/* safe zone */
	ANDQ	$~15, SP
	
	MOVQ	AX, 8(SP)	/* noted(v) */
	MOVQ	$33, R15	/* syscall 33 (noted) */
	SYSCALL
	
	MOVQ	R12, SP
	POPQ	R12
	RET
