TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	$_apemain(SB), R15
	/* 
	 * Kernel puts argc at 0(SP), argv at 8(SP).
	 * C code expects argc at 0(FP) (which is 8(SP) if JMP is used).
	 * We push a dummy value so that 0(FP) points to the original 0(SP).
	 */
	PUSHQ	$0
	JMP	_callmain(SB)

GLOBL	_tos(SB), $8
