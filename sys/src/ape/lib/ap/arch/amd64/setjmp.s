/*
 * amd64 setjmp/longjmp
 * jmp_buf layout (8-byte slots):
 *  0: SP, 1: PC, 2: BP, 3: BX, 4: R12, 5: R13, 6: R14, 7: R15
 */

TEXT	setjmp(SB), $0
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

TEXT	longjmp(SB), $0
	/* R15 = jmp_buf, val is at 8(SP) */
	MOVL	val+8(SP), AX
	TESTL	AX, AX
	JNZ	ok
	MOVL	$1, AX
ok:
	/* Restore registers from indices 2-7 */
	MOVQ	16(R15), BP
	MOVQ	24(R15), BX
	MOVQ	32(R15), R12
	MOVQ	40(R15), R13
	MOVQ	48(R15), R14
	
	MOVQ	0(R15), SP	/* Index 0: SP */
	MOVQ	8(R15), DI	/* Index 1: PC */
	MOVQ	56(R15), R15	/* Index 7: R15 */
	
	MOVQ	DI, 0(SP)	/* Put PC on stack for RET */
	RET

TEXT	sigsetjmp(SB), $0
	/* R15 = sigjmp_buf, savemask is at 8(SP) */
	MOVL	savemask+8(SP), AX
	MOVQ	$0, 0(R15)
	MOVL	AX, 0(R15)	/* store savemask */
	MOVQ	_psigblocked(SB), AX
	MOVQ	AX, 8(R15)	/* store blocked mask */
	
	/* Inline setjmp logic into the sigjmp_buf starting at offset 16 */
	MOVQ	SP, 16(R15)
	MOVQ	0(SP), AX
	MOVQ	AX, 24(R15)
	MOVQ	BP, 32(R15)
	MOVQ	BX, 40(R15)
	MOVQ	R12, 48(R15)
	MOVQ	R13, 56(R15)
	MOVQ	R14, 64(R15)
	MOVQ	R15, 72(R15)
	
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes.
 * Kernel delivers u in BP (kernel's RARG), msg at 8(SP).
 */
TEXT	_notehandler(SB), 1, $32
	MOVQ	BP, R15		/* Bridge Kernel RARG (BP) to 6c RARG (R15) */
	MOVQ	40(SP), AX	/* msg (original 8(SP) + 32 byte frame) */
	MOVQ	AX, 8(SP)	/* msg to Arg 2 slot for C */
	CALL	_ape_notehandler(SB)
	RET

/*
 * Stack-safe kernel restore bridge.
 * _signoted(int v)
 */
TEXT	_signoted(SB), 1, $0
	/* R15 contains v */
	MOVQ	R15, 8(SP)	/* Arg 0 for kernel */
	MOVQ	$33, BP		/* BP is RARG for kernel syscalls */
	SYSCALL
	RET
