GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old SP */
	MOVQ	0(R12), AX		/* AX = argc */
	SUBQ	$65536, SP		/* 64KB headroom at top of stack */
	ANDQ	$~15, SP		/* Ensure 16-byte alignment */
	
	/* Copy all argv pointers (argv[0] to argv[argc]) onto new stack */
	MOVQ	AX, CX			/* index i = argc */
copy_loop:
	MOVQ	CX, BX
	SHLQ	$3, BX			/* BX = i*8 */
	MOVQ	8(R12)(BX*1), R11	/* R11 = argv[i] */
	PUSHQ	R11
	DECQ	CX
	JGE	copy_loop		/* loop from argc down to 0 */
	
	/* Now argv array is on new stack, and SP points to argv[0] */
	MOVQ	0(R12), AX		/* argc */
	MOVQ	$_apemain(SB), RARG
	PUSHQ	AX			/* argc at 8(FP) = 16(SP) */
	PUSHQ	RARG			/* f at 0(FP) = 8(SP) */
	PUSHQ	$0			/* fake return address at 0(SP) */
	JMPF	_callmain(SB)
