TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	
	/* Provide 8KB headroom at top of stack for signals */
	SUBQ	$8192, SP
	ANDQ	$~15, SP

	MOVQ	$_apemain(SB), R15
	PUSHQ	R15
	PUSHQ	$0
	CALL	_callmain(SB)
	RET

GLOBL	_tos(SB), $8
