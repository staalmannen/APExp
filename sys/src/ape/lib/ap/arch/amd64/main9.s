GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMPF	_callmain(SB)
