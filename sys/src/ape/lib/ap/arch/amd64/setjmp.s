/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), 1, $0
	MOVQ	SP, 0(R15)	/* R15 is RARG for 6c */
	MOVQ	0(SP), AX	/* Return PC */
	MOVQ	AX, 8(R15)
	MOVQ	BP, 16(R15)
	MOVQ	BX, 24(R15)
	MOVQ	R12, 32(R15)
	MOVQ	R13, 40(R15)
	MOVQ	R14, 48(R15)
	MOVQ	R15, 56(R15)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), 1, $0
	/* R15 = jmp_buf, 0(FP) = val */
	MOVL	val+0(FP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	MOVQ	16(R15), BP
	MOVQ	24(R15), BX
	MOVQ	32(R15), R12
	MOVQ	40(R15), R13
	MOVQ	48(R15), R14
	
	MOVQ	0(R15), SP	/* Restore SP */
	MOVQ	8(R15), DI	/* Target PC */
	MOVQ	56(R15), R15	/* Restore R15 last */
	
	MOVQ	DI, 0(SP)	/* Put PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), 1, $0
	/* R15 = sigjmp_buf, 0(FP) = savemask */
	MOVL	savemask+0(FP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)	/* store 32-bit savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)	/* store 64-bit blocked mask */
	
	/* Inline setjmp logic into the sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(R15)	/* jmpbuf[0] */
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)	/* jmpbuf[1] */
	MOVQ	BP, 32(R15)	/* jmpbuf[2] */
	MOVQ	BX, 40(R15)	/* jmpbuf[3] */
	MOVQ	R12, 48(R15)	/* jmpbuf[4] */
	MOVQ	R13, 56(R15)	/* jmpbuf[5] */
	MOVQ	R14, 64(R15)	/* jmpbuf[6] */
	MOVQ	R15, 72(R15)	/* jmpbuf[7] */
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers: 0(SP)=dummy, 8(SP)=u, 16(SP)=msg.
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	u+0(FP), R15	/* u -> RARG */
	MOVQ	msg+8(FP), AX	/* msg */
	MOVQ	AX, 8(SP)	/* msg to Arg 2 slot for C */
	CALL	_ape_notehandler(SB)
	RET

/*
 * Stack-safe kernel restore bridge.
 * _signoted(Ureg *u, int v)
 */
TEXT	_signoted(SB), 1, $32
	/* u is in R15, v is at 0(FP) (which is 40(SP)) */
	MOVL	v+0(FP), AX	/* v */
	MOVQ	R15, 8(SP)	/* Arg 0: u for kernel */
	MOVQ	AX, 16(SP)	/* Arg 1: v for kernel */
	MOVQ	$33, BP		/* BP is RARG for kernel syscalls */
	SYSCALL
	RET
