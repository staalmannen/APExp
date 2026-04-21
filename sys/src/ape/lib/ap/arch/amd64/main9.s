GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)

	/*
	 * Use R11 (caller-saved scratch, NOT saved by setjmp/sigsetjmp) to
	 * hold the kernel SP.  R12-R15 are callee-saved REGEXT registers;
	 * if sigsetjmp captures a value near USTKTOP in any of them and
	 * longjmp restores it, a subsequent REGEXT write faults at USTKTOP.
	 * R11 is never in the setjmp register list, so it is safe.
	 */
	MOVQ	SP, R11			/* R11 = kernel SP */

	/* Shift stack down 128KB so signal frames are never near USTKTOP. */
	SUBQ	$131072, SP
	ANDQ	$~15, SP

	/*
	 * Copy [argc, argv[0], ..., NULL] from kernel stack to new stack.
	 * Uses only AX/CX/SI/DI/R11 — no callee-saved REGEXT registers.
	 */
	MOVQ	0(R11), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 (argc + argv ptrs + NULL) */
	MOVQ	R11, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* DI = new_SP + 8 (target for argc) */
	CLD
	REP; MOVSQ

	/* Set up _callmain(f, argc, arg0): f in RARG, argc at 8(FP), arg0 at 16(FP). */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* shadow slot for first arg */
	PUSHQ	$0			/* fake return address */
	JMPF	_callmain(SB)
