GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old SP */
	MOVQ	0(R12), AX		/* AX = argc */
	
	/* Move stack down by 128KB to prevent boundary faults at USTKTOP */
	SUBQ	$131072, SP
	ANDQ	$~15, SP		/* Ensure 16-byte alignment */
	
	/* Reserve space for _callmain arguments (256 bytes) */
	SUBQ	$256, SP
	
	/* Copy argc and f to the new stack frame */
	MOVQ	AX, 8(SP)		/* argc at 8(FP) for _callmain */
	MOVQ	$_apemain(SB), R11
	MOVQ	R11, 0(SP)		/* f at 0(FP) for _callmain */
	
	/* Relocate the argv pointer array */
	MOVQ	AX, CX
	ADDQ	$1, CX			/* CX = argc + 1 (pointers) */
	MOVQ	R12, SI
	ADDQ	$8, SI			/* SI = old argv[0] */
	MOVQ	SP, DI
	ADDQ	$16, DI			/* DI = new argv[0] */
	CLD
	REP; MOVSQ
	
	/* Set up first argument in RARG as per 6c convention */
	MOVQ	0(SP), RARG
	
	/* Enter C runtime; _callmain never returns */
	CALL	_callmain(SB)
	XORL	AX, AX
	RET
