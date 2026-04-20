GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old (kernel) SP */
	
	/* Shift stack down by 2MB to provide absolute safety from USTKTOP */
	SUBQ	$2097152, SP
	ANDQ	$~15, SP		/* 16-byte alignment */
	
	/* Relocate [argc, argv[0], ..., NULL] from kernel stack to new stack.
	 * Total slots: argc (1) + argv pointers (argc + 1) = argc + 2 slots.
	 * We place them starting at 16(SP) so that after PUSHQ $0 they align with 8(FP).
	 */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 slots */
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
	 * Using JMPF and TEXT flag 1 (NOPROF) suppresses linker prologues.
	 */
	PUSHQ	$0
	JMPF	_callmain(SB)
