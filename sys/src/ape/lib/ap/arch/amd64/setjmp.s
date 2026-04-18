/*
 * amd64 setjmp/longjmp (Stack-Safe & Kernel-Aligned)
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), $0
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

TEXT	longjmp(SB), $0
	/* RARG = jmp_buf, 0(FP) = val */
	MOVL	val+0(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(RARG), BP
	MOVQ	24(RARG), BX
	MOVQ	32(RARG), R12
	MOVQ	40(RARG), R13
	MOVQ	48(RARG), R14
	MOVQ	56(RARG), R15
	
	MOVQ	0(RARG), SP
	ADDQ	$8, SP		/* Simulate pop of return address */
	MOVQ	8(RARG), DI	/* Target PC */
	JMP	DI		/* Jump without writing to stack */

TEXT	sigsetjmp(SB), $0
	/* RARG = sigjmp_buf, 0(FP) = savemask */
	MOVL	savemask+0(FP), AX
	MOVQ	$0, 0(RARG)
	MOVL	AX, 0(RARG)
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(RARG)
	
	/* Inline setjmp at offset 16 */
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(RARG)
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
TEXT	_notehandler(SB), $0
	MOVQ	8(SP), RARG	/* u */
	MOVQ	16(SP), AX	/* msg */
	/* Align stack to 16 bytes for C */
	MOVQ	SP, R11
	SUBQ	$16, SP
	ANDQ	$~15, SP
	MOVQ	AX, 0(SP)	/* msg -> 0(FP) */
	CALL	_ape_notehandler(SB)
	MOVQ	R11, SP
	RET

/*
 * Stack-safe kernel restore bridge.
 */
TEXT	_signoted(SB), $0
	MOVL	v+0(FP), AX
	MOVQ	AX, 8(SP)	/* Arg 0 for kernel */
	MOVQ	$33, BP		/* BP is RARG for kernel syscalls */
	SYSCALL
	RET
