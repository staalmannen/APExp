GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12
	SUBQ	$131072, SP
	ANDQ	$~15, SP
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI
	MOVQ	0(R12), AX
	MOVQ	AX, CX
	ADDQ	$2, CX
	MOVQ	$0x7ffffffff000, R13
copy_loop:
	MOVQ	SI, R11
	CMPQ	R11, R13
	JAE	copy_done
	MOVSQ
	LOOP	copy_loop
copy_done:
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)
	PUSHQ	$0
	JMPF	_callmain(SB)
