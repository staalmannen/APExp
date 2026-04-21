GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12
	SUBQ	$131072, SP
	ANDQ	$~15, SP
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI
	MOVQ	$64, CX
copy_loop:
	DECQ	CX
	MOVQ	(SI)(CX*8), AX
	MOVQ	AX, (DI)(CX*8)
	JNZ	copy_loop
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)
	PUSHQ	$0
	JMPF	_callmain(SB)
