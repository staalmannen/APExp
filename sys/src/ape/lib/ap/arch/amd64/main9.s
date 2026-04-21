GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = kernel SP */
	
	/* 1. Shift stack by 128KB */
	SUBQ	$131072, SP
	ANDQ	$~15, SP
	
	/* 2. Manual relocation of the first 512 bytes of stack (64 quads)
	 * This covers argc, argv[], and initial envp[] safely.
	 */
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* target for argc */
	MOVQ	$64, CX
copy_loop:
	DECQ	CX
	MOVQ	(SI)(CX*8), AX
	MOVQ	AX, (DI)(CX*8)
	JNZ	copy_loop
	
	/* 3. Dispatch to _callmain(f, argc, arg0) */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* shadow slot */
	PUSHQ	$0
	JMPF	_callmain(SB)
