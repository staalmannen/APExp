GLOBL	_tos(SB), $4

TEXT	_main(SB), 1, $0
	MOVL	$a6base(SB), A6
	MOVL	R0, _tos(SB)
	PEA	_apemain(SB)
	MOVL	$0, TOS
	JMP	_callmain(SB)
