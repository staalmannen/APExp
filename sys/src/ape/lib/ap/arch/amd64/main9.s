TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG		/* fill 0(FP) slot (reserved by regaalloc1 for first arg) */
	PUSHQ	$0		/* fake return address; shifts kernel's argc to 8(FP) */
	JMP	_callmain(SB)

GLOBL	_tos(SB), $8
