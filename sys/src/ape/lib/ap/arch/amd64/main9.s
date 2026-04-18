TEXT	_main(SB), 1, $24
	MOVQ	AX, _tos(SB)
	MOVQ	$_apemain(SB), R15
	/* 
	 * Kernel puts argc at 0(SP), argv at 8(SP) on entry.
	 * After SUBQ $24 for our frame, they are at 24(SP) and 32(SP).
	 * _callmain expects argc at 8(SP) (0(FP)) and argv at 16(SP) (8(FP)).
	 */
	MOVQ	24(SP), AX
	MOVQ	AX, 8(SP)
	MOVQ	32(SP), AX
	MOVQ	AX, 16(SP)
	CALL	_callmain(SB)
	RET

GLOBL	_tos(SB), $8
