GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = kernel SP */
	
	/* 1. Shift stack down by 128KB */
	SUBQ	$131072, SP
	ANDQ	$~15, SP
	
	/* 2. Boundary-Safe Relocation of argc and argv.
	 * Plan 9 kernel SP points to argc. [SP+8] is argv[0].
	 * We only copy quads that are strictly below 0x7ffffffff000.
	 */
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* DI target: SP+8 */
	
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 (argc slot + argv pointers + NULL) */
	
	MOVQ	$0x7ffffffff000, R13	/* Load boundary into register for CMPQ */
copy_loop:
	MOVQ	SI, R11
	CMPQ	R11, R13		/* Check if next read hits boundary */
	JAE	copy_done
	MOVSQ
	LOOP	copy_loop
copy_done:
	
	/* 3. Set up _callmain(f, argc, arg0)
	 * f is in RARG (BP)
	 * argc at 8(FP) = 16(SP)
	 * arg0 at 16(FP) = 24(SP)
	 */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* f shadow slot */
	PUSHQ	$0			/* fake return address */
	JMPF	_callmain(SB)
