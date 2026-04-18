/*
 * amd64 setjmp/longjmp (Stack-Safe & Kernel-Aligned)
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(R15)	/* R15 is RARG for 6c */
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(R15)
	MOVQ	BP, 16(R15)
	MOVQ	BX, 24(R15)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	/* R15 = jmp_buf, 8(SP) = val */
	MOVL	val+8(SP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(R15), BP
	MOVQ	24(R15), BX
	MOVQ	0(R15), SP
	ADDQ	$8, SP		/* Simulate pop of return address */
	MOVQ	8(R15), DI	/* Target PC */
	JMP	DI		/* Stack-safe: jump without writing */

TEXT	sigsetjmp(SB), $0
	/* R15 = sigjmp_buf, 8(SP) = savemask */
	MOVL	savemask+8(SP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)	/* set */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)	/* blocked */
	
	/* Inline setjmp at offset 16 */
	MOVQ	SP, 16(R15)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)
	MOVQ	BP, 32(R15)
	MOVQ	BX, 40(R15)
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers u in BP (kernel's RARG), msg on stack.
 */
TEXT	_notehandler(SB), 1, $0
	MOVQ	BP, R15		/* u into R15 for 6c */
	MOVQ	8(SP), AX	/* msg */
	PUSHQ	AX
	PUSHQ	R15
	CALL	_ape_notehandler(SB)
	POPQ	R15
	POPQ	AX
	/* If we return, must terminate */
	MOVQ	$1, AX		/* NDFLT */
	PUSHQ	AX
	CALL	_signoted(SB)
	RET

/*
 * Stack-safe kernel restore bridge.
 */
TEXT	_signoted(SB), $0
	MOVL	v+8(SP), AX
	MOVQ	AX, 8(SP)
	MOVQ	$33, BP		/* syscall noted in BP (kernel RARG) */
	SYSCALL
	RET
