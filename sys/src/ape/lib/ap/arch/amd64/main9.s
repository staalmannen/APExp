GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $0
	MOVQ	AX, _tos(SB)
	MOVQ	SP, R12			/* R12 = kernel SP */
	
	/* 1. diagnostic jump over NOPs to move binary offsets */
	JMP	start
	BYTE	$0x90; BYTE	$0x90; BYTE	$0x90; BYTE	$0x90
	BYTE	$0x90; BYTE	$0x90; BYTE	$0x90; BYTE	$0x90
	BYTE	$0x90; BYTE	$0x90; BYTE	$0x90; BYTE	$0x90
	BYTE	$0x90; BYTE	$0x90; BYTE	$0x90; BYTE	$0x90

start:
	/* 2. simple 64KB stack shift */
	SUBQ	$65536, SP
	ANDQ	$~15, SP
	
	/* 3. copy argc, argv block */
	MOVQ	0(R12), AX		/* AX = argc */
	MOVQ	AX, CX
	ADDQ	$2, CX
	MOVQ	R12, SI
	MOVQ	SP, DI
	ADDQ	$8, DI			/* target for argc */
	CLD
	REP; MOVSQ
	
	/* 4. dispatch to _callmain(f, argc, arg0) */
	MOVQ	$_apemain(SB), RARG
	MOVQ	RARG, 0(SP)		/* f shadow slot */
	PUSHQ	$0
	JMPF	_callmain(SB)
