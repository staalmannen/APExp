TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	
	/* 
	 * Provide 64KB of headroom at the top of the stack.
	 * Plan 9 kernel pushes signal context onto the current stack.
	 * 64KB ensures plenty of room for signals and nested calls
	 * and keeps SP away from the USTKTOP (0x7ffffffff000) boundary.
	 */
	SUBQ	$65536, SP
	ANDQ	$~15, SP

	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMP	_callmain(SB)

GLOBL	_tos(SB), $8
