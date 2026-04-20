GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old (kernel) SP */
	MOVQ	0(R12), AX		/* AX = argc */
	
	/* Move stack down by 512KB to provide massive headroom */
	SUBQ	$524288, SP
	ANDQ	$~15, SP		/* 16-byte alignment */
	
	/* Copy argc and all argv pointers to the new stack.
	 * We need room for argc (8 bytes) + (argc+1) pointers (8 bytes each).
	 * We'll just push them in reverse order to build the array on the stack.
	 */
	MOVQ	AX, CX			/* CX = argc */
	MOVQ	CX, R11
	SHLQ	$3, R11			/* R11 = argc * 8 */
	
	/* Push NULL terminator (argv[argc]) */
	MOVQ	$0, BX
	PUSHQ	BX
	
	/* Copy argv[argc-1] down to argv[0] */
	TESTQ	CX, CX
	JZ	copy_done
copy_loop:
	DECQ	CX
	MOVQ	CX, R11
	SHLQ	$3, R11
	MOVQ	8(R12)(R11*1), BX	/* BX = argv[i] */
	PUSHQ	BX
	TESTQ	CX, CX
	JNZ	copy_loop
copy_done:
	
	/* Now SP points to new argv[0].
	 * We need to set up _callmain(f, argc, arg0).
	 * arg0 (3rd arg) should be the address of our new argv[0].
	 */
	MOVQ	SP, R13			/* R13 = &argv[0] */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	$_apemain(SB), RARG	/* f in RARG (BP) */
	
	/* Align stack for call and set up args */
	SUBQ	$32, SP			/* Room for arguments and shadow slot */
	ANDQ	$~15, SP
	
	MOVQ	RARG, 0(SP)		/* f at 0(FP) */
	MOVQ	AX, 8(SP)		/* argc at 8(FP) */
	MOVQ	R13, 16(SP)		/* &argv[0] at 16(FP) */
	
	/* Terminate backtrace */
	XORQ	BP, BP
	
	CALL	_callmain(SB)
	XORL	AX, AX
	RET
