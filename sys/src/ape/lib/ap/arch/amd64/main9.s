GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R11			/* R11 = kernel SP */
	
	/* Move stack down by 128KB to provide headroom for signals */
	SUBQ	$131072, SP
	ANDQ	$~15, SP		/* Ensure 16-byte alignment */
	
	/* Relocate [argc, argv[0], ..., NULL] to the new stack.
	 * We place them starting at 16(SP) so that after PUSHQ $0 they align with 8(FP).
	 */
	MOVQ	0(R11), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 (argc + argv pointers + NULL) */
	MOVQ	R11, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* DI = SP + 8 (target for argc) */
	CLD
	REP; MOVSQ
	
	/* Set up _callmain(f, argc, arg0)
	 * f is in RARG (BP)
	 * argc is at 8(FP) = 16(SP) after PUSHQ
	 * arg0 is at 16(FP) = 24(SP) after PUSHQ
	 */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* Shadow slot for 1st arg (at 0(FP)) */
	PUSHQ	$0			/* Fake return address at 0(SP) */
	
	JMPF	_callmain(SB)
