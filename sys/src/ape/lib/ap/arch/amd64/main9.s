GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = kernel SP */

	/* Shift stack down 128KB so signal frames are never near USTKTOP. */
	SUBQ	$131072, SP
	ANDQ	$~15, SP

	/*
	 * Copy [argc, argv[0], ..., NULL] from kernel stack to new stack.
	 * The reads are from kernel SP (USTKTOP - ssize - 8) upward; the
	 * last read is at most USTKTOP - ssize + argc*8 < USTKTOP - 8, so
	 * no boundary check is required.  CX = argc + 2 is always small.
	 *
	 * IMPORTANT: do NOT use R13 here.  R13 is a callee-saved REGEXT
	 * register; if sigsetjmp saves a garbage R13 value and longjmp
	 * restores it, any subsequent REGEXT write would fault at that
	 * address.  Use only AX/CX/SI/DI (all caller-saved) for the copy.
	 */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX			/* CX = argc + 2 (argc + argv ptrs + NULL) */
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* DI = new_SP + 8 (target for argc) */
	CLD
	REP; MOVSQ

	/* Set up _callmain(f, argc, arg0): f in RARG, argc at 8(FP), arg0 at 16(FP). */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* shadow slot for first arg */
	PUSHQ	$0			/* fake return address */
	JMPF	_callmain(SB)
