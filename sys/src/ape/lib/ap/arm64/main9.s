GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	SUB	$16, SP
	MOV	$setSB(SB), R28
	MOV	R0, _tos(SB)

	MOV	$_apemain(SB), R0

	MOV	$0, R30
	B	_callmain(SB)
