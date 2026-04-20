GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old (kernel) SP */
	
	/* Shift stack down by 1MB to provide massive headroom */
	SUBQ	$1048576, SP
	ANDQ	$~15, SP		/* 16-byte alignment */
	
	/* Relocate [argc, argv[0], ..., NULL] from kernel stack to new stack.
	 * We want argc at 8(FP) and argv[0] at 16(FP).
	 * If we push a fake return address, 0(FP) is at 8(SP).
	 * So argc should be at 16(SP), and argv[0] at 24(SP).
	 * This means we copy the block starting at 8(SP) before the PUSH.
	 */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 slots (argc + argv + NULL) */
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* DI = SP + 8 (target for argc) */
	CLD
	REP; MOVSQ			/* Relocate the block */
	
	/* Set up _callmain(f, argc, arg0)
	 * f is passed in RARG (BP) and also in the shadow slot at 0(FP).
	 */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* f shadow slot at 0(FP) before PUSH */
	
	/* Fake return address and jump to C runtime.
	 * After PUSHQ, shadow slot is at 8(SP), argc is at 16(SP), arg0 is at 24(SP).
	 */
	PUSHQ	$0
	JMPF	_callmain(SB)
