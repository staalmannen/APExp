GLOBL	_tos(SB), $4

TEXT	_main(SB), 1, $0
	MOVL	AX, _tos(SB)
	MOVL	$_apemain(SB), AX
	PUSHL	AX
	PUSHL	$0
	JMPF	_callmain(SB)
