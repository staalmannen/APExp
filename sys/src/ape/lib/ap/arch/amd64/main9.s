TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	
	/* 
	 * Provide 8KB of headroom at the top of the stack.
	 * The Plan 9 kernel pushes signal context onto the current stack.
	 * Without this headroom, signal delivery at process start or in 
	 * deep call stacks crosses the USTKTOP boundary.
	 */
	SUBQ	$8192, SP
	ANDQ	$~15, SP

	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMPF	_callmain(SB)

GLOBL	_tos(SB), $8
