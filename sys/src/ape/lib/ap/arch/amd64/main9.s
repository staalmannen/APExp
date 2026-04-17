TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	
	/* 
	 * Provide headroom at the top of the stack for signals.
	 * Plan 9 kernel pushes Ureg and msg onto the current stack.
	 * If we are too close to USTKTOP, this overwrites our own frames.
	 */
	SUBQ	$8192, SP
	ANDQ	$~15, SP	/* Ensure 16-byte alignment */

	MOVQ	$_apemain(SB), RARG
	PUSHQ	RARG
	PUSHQ	$0
	JMPF	_callmain(SB)

GLOBL	_tos(SB), $8
