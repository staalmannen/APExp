GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = old SP */
	MOVQ	0(R12), AX		/* AX = argc */
	
	/* Move stack down by 128KB to prevent boundary faults at USTKTOP */
	SUBQ	$131072, SP
	ANDQ	$~15, SP		/* Ensure 16-byte alignment */
	
	/* Reserve space for _callmain arguments and align for CALL (8 mod 16) */
	/* 256 is 0 mod 16, so SP remains 0 mod 16. CALL will make it 8 mod 16. */
	SUBQ	$256, SP
	
	/* Copy argc and all argv pointers (including NULL) to the new stack */
	MOVQ	AX, 8(SP)		/* argc at 8(FP) for _callmain */
	MOVQ	$_apemain(SB), R11
	MOVQ	R11, 0(SP)		/* f at 0(FP) for _callmain */
	
	MOVQ	AX, CX
	ADDQ	$1, CX			/* CX = argc + 1 (pointers) */
	LEA	8(R12), SI		/* SI = old argv[0] */
	LEA	16(SP), DI		/* DI = new argv[0] */
	CLD
	REP; MOVSQ			/* Relocate the argv pointer array */
	
	/* Set up first argument in RARG (BP) as per 6c convention */
	MOVQ	0(SP), RARG
	
	/* Terminate backtrace */
	XORQ	BP, BP
	
	/* Enter C runtime; _callmain never returns */
	CALL	_callmain(SB)
	BYTE	$0x00			/* Halt if it returns */
