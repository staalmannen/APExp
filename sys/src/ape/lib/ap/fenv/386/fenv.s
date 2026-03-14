// .hidden __hwcap

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	MOV	4(SP), CX
	AND	$0x3f, CX
	FNSTSW	AX

	CALL	1f
1:
	ADDL	$__hwcap-1b, (SP)
	POP	DX
	TESTL	(DX), $0x02000000
	JEQ	2f

	TEST	AX, CX
	JEQ	1f
	FNCLEX
1:
	PUSH	DX
	STMXCSR	(SP)
	POP	DX
	AND	$0x3f, AX
	OR	AX, DX
	TEST	DX, CX
	JEQ	1f
	NOT	CX
	AND	CX, DX
	PUSH	DX
	LDMXCSR	(SP)
	POP	DX
1:
	XOR	AX, AX
	RET

2:
	TEST	AX, CX
	JEQ	1b
	NOT	CX
	AND	CX, AX
	TEST	AX, $0x3f
	JEQ	1f
	FNCLEX
	JMP	1b
1:
	SUB	$32, SP
	FNSTENV	(SP)
	MOV	AL, 4(SP)
	FLDENV	(SP)
	ADD	$32, SP
	XOR	AX, AX
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	MOV	4(SP), AX
	AND	$0x3f, AX
	SUB	$32, SP
	FNSTENV	(SP)
	OR	AL, 4(SP)
	FLDENV	(SP)
	ADD	$32, SP
	XOR	AX, AX
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	MOV	4(SP), CX
	PUSH	AX
	XOR	AX, AX
	FNSTCW	(SP)
	ANDB	$0xf3, 1(SP)
	OR	CH, 1(SP)
	FLDCW	(SP)

	CALL	1f
1:
	ADDL	$__hwcap-1b, (SP)
	POP	DX
	TESTL	(DX), $0x02000000
	JEQ	1f
	STMXCSR	(SP)
	SHL	$3, CH
	ANDB	$0x9f, 1(SP)
	OR	CH, 1(SP)
	LDMXCSR	(SP)
1:
	POP	CX
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	PUSH	AX
	FNSTCW	(SP)
	POP	AX
	AND	$0xc00, AX
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	MOV	4(SP), CX
	XOR	AX, AX
	FNSTENV	(CX)

	CALL	1f
1:
	ADDL	$__hwcap-1b, (SP)
	POP	DX
	TESTL	(DX), $0x02000000
	JEQ	1f
	PUSH	AX
	STMXCSR	(SP)
	POP	DX
	AND	$0x3f, DX
	OR	DX, 4(CX)
1:
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	MOV	4(SP), CX
	XOR	AX, AX
	INC	CX
	JEQ	1f
	FLDENV	-1(CX)
	MOVL	-1(CX), CX
	JMP	2f
1:
	PUSH	AX
	PUSH	AX
	PUSH	AX
	PUSH	AX
	PUSHL	$0xffff
	PUSH	AX
	PUSHL	$0x37f
	FLDENV	(SP)
	ADD	$28, SP

2:
	CALL	1f
1:
	ADDL	$__hwcap-1b, (SP)
	POP	DX
	TESTL	(DX), $0x02000000
	JEQ	1f

	AND	$0xc00, CX
	SHL	$3, CX
	OR	$0x1f80, CX
	MOV	CX, 4(SP)
	LDMXCSR	4(SP)
1:
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	MOV	4(SP), CX
	AND	$0x3f, CX
	FNSTSW	AX

	CALL	1f
1:
	ADDL	$__hwcap-1b, (SP)
	POP	DX
	TESTL	(DX), $0x02000000
	JEQ	1f
	STMXCSR	4(SP)
	OR	4(SP), AX
1:
	AND	CX, AX
	RET


