TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMP	_callmain(SB)

GLOBL	_tos(SB), $8
