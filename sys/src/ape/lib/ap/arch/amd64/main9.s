GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old (kernel) SP */
	MOVQ	0(R12), AX		/* AX = argc */
	
	/* Move stack down by 512KB to provide massive headroom */
	SUBQ	$524288, SP
	ANDQ	$~15, SP		/* 16-byte alignment */
	
	/* Copy argc and all argv pointers (including NULL) to the new stack.
	 * Total slots to copy: argc (1) + argv pointers (argc + 1).
	 */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = number of 8-byte slots */
	MOVQ	R12, SI
	MOVQ	SP, DI
	CLD
	REP; MOVSQ			/* Relocate the block */
	
	/* Now 0(SP) is argc, 8(SP) is argv[0] ...
	 * _callmain(f, argc, arg0) expects:
	 *   f in RARG (BP)
	 *   argc at 8(FP)
	 *   arg0 at 16(FP)
	 */
	MOVQ	$_apemain(SB), RARG
	MOVQ	0(SP), AX		/* AX = argc */
	MOVQ	SP, R13
	ADDQ	$8, R13			/* R13 = &argv[0] (arg0) */
	
	/* Set up _callmain frame (32 bytes) */
	SUBQ	$32, SP
	MOVQ	RARG, 0(SP)		/* Shadow slot for 1st arg */
	MOVQ	AX, 8(SP)		/* argc at 8(FP) */
	MOVQ	R13, 16(SP)		/* arg0 at 16(FP) */
	
	/* Fake return address and jump to C runtime.
	 * Using JMPF suppresses linker balance checks for PUSH/POP.
	 */
	PUSHQ	$0
	JMPF	_callmain(SB)
