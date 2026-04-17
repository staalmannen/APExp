TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	
	/* 
	 * Provide 32KB of headroom at the top of the stack.
	 * Plan 9 kernel pushes signal context onto the current stack.
	 * 32KB ensures plenty of room for signals and nested calls.
	 */
	SUBQ	$32768, SP
	ANDQ	$~15, SP

	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMP	_callmain(SB)

GLOBL	_tos(SB), $8
