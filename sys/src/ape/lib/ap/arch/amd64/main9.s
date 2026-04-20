GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = pointer to argc, argv... */
	SUBQ	$65536, SP		/* 64KB headroom at top of stack */
	ANDQ	$~15, SP		/* Ensure 16-byte alignment */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	8(R12), BX		/* BX = argv[0] */
	MOVQ	$_apemain(SB), RARG
	PUSHQ	BX			/* arg0 at 16(FP) = 24(SP) */
	PUSHQ	AX			/* argc at 8(FP) = 16(SP) */
	PUSHQ	RARG			/* f at 0(FP) = 8(SP) */
	PUSHQ	$0			/* fake return address at 0(SP) */
	JMPF	_callmain(SB)
