// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:

	MOV	DI, CX
	AND	$0x3f, CX
	FNSTSW	AX
	TEST	AX, CX
	JEQ	1f
	FNCLEX
1:
	STMXCSR	-8(SP)
	AND	$0x3f, AX
	OR	AX, -8(SP)
	TEST	CX, -8(SP)
	JEQ	1f
	NOT	CX
	AND	CX, -8(SP)
	LDMXCSR	-8(SP)
1:
	XOR	AX, AX
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	AND	$0x3f, DI
	STMXCSR	-8(SP)
	OR	DI, -8(SP)
	LDMXCSR	-8(SP)
	XOR	AX, AX
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	PUSH	AX
	XOR	AX, AX
	MOV	DI, CX
	FNSTCW	(SP)
	ANDB	$0xf3, 1(SP)
	OR	CH, 1(SP)
	FLDCW	(SP)
	STMXCSR	(SP)
	SHL	$3, CH
	ANDB	$0x9f, 1(SP)
	OR	CH, 1(SP)
	LDMXCSR	(SP)
	POP	CX
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	PUSH	AX
	STMXCSR	(SP)
	POP	AX
	SHR	$3, AX
	AND	$0xc00, AX
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	XOR	AX, AX
	FNSTENV	(DI)
	STMXCSR	28(DI)
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	XOR	AX, AX
	INC	DI
	JEQ	1f
	FLDENV	-1(DI)
	LDMXCSR	27(DI)
	RET
1:
	PUSH	AX
	PUSH	AX
	PUSHQ	$0xffff
	PUSHQ	$0x37f
	FLDENV	(SP)
	PUSHQ	$0x1f80
	LDMXCSR	(SP)
	ADD	$40, SP
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	AND	$0x3f, DI
	PUSH	AX
	STMXCSR	(SP)
	POP	SI
	FNSTSW	AX
	OR	SI, AX
	AND	DI, AX
	RET


