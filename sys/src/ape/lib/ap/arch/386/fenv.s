// .hidden __hwcap

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	MOVL	4(SP), CX
	ANDL	$0x3f, CX
	FSTSW	AX

	CALLL	.Lnum1_0
.Lnum1_0:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum2_0

	TESTL	AX, CX
	JEQ	.Lnum1_1
	FCLEX
.Lnum1_1:
	PUSHL	DX
	STMXCSR	(SP)
	POPL	DX
	ANDL	$0x3f, AX
	ORL	AX, DX
	TESTL	DX, CX
	JEQ	.Lnum1_2
	NOTL	CX
	ANDL	CX, DX
	PUSHL	DX
	LDMXCSR	(SP)
	POPL	DX
.Lnum1_2:
	XORL	AX, AX
	RET

.Lnum2_0:
	TESTL	AX, CX
	JEQ	.Lnum1_2
	NOTL	CX
	ANDL	CX, AX
	TESTL	AX, $0x3f
	JEQ	.Lnum1_3
	FCLEX
	JMPL	.Lnum1_2
.Lnum1_3:
	SUBL	$32, SP
	FSTENV	(SP)
	MOVB	AL, 4(SP)
	FLDENV	(SP)
	ADDL	$32, SP
	XORL	AX, AX
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	MOVL	4(SP), AX
	ANDL	$0x3f, AX
	SUBL	$32, SP
	FSTENV	(SP)
	ORB	AL, 4(SP)
	FLDENV	(SP)
	ADDL	$32, SP
	XORL	AX, AX
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	MOVL	4(SP), CX
	PUSHL	AX
	XORL	AX, AX
	FSTCW	(SP)
	ANDB	$0xf3, 1(SP)
	ORB	CH, 1(SP)
	FLDCW	(SP)

	CALLL	.Lnum1_4
.Lnum1_4:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_5
	STMXCSR	(SP)
	SHLB	$3, CH
	ANDB	$0x9f, 1(SP)
	ORB	CH, 1(SP)
	LDMXCSR	(SP)
.Lnum1_5:
	POPL	CX
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	PUSHL	AX
	FSTCW	(SP)
	POPL	AX
	ANDL	$0xc00, AX
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	MOVL	4(SP), CX
	XORL	AX, AX
	FSTENV	(CX)

	CALLL	.Lnum1_6
.Lnum1_6:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_7
	PUSHL	AX
	STMXCSR	(SP)
	POPL	DX
	ANDL	$0x3f, DX
	ORL	DX, 4(CX)
.Lnum1_7:
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	MOVL	4(SP), CX
	XORL	AX, AX
	INCL	CX
	JEQ	.Lnum1_8
	FLDENV	-1(CX)
	MOVL	-1(CX), CX
	JMPL	.Lnum2_1
.Lnum1_8:
	PUSHL	AX
	PUSHL	AX
	PUSHL	AX
	PUSHL	AX
	PUSHL	$0xffff
	PUSHL	AX
	PUSHL	$0x37f
	FLDENV	(SP)
	ADDL	$28, SP

.Lnum2_1:
	CALLL	.Lnum1_9
.Lnum1_9:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_10

	ANDL	$0xc00, CX
	SHLL	$3, CX
	ORL	$0x1f80, CX
	MOVL	CX, 4(SP)
	LDMXCSR	4(SP)
.Lnum1_10:
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	MOVL	4(SP), CX
	ANDL	$0x3f, CX
	FSTSW	AX

	CALLL	.Lnum1_11
.Lnum1_11:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_12
	STMXCSR	4(SP)
	ORL	4(SP), AX
.Lnum1_12:
	ANDL	CX, AX
	RET
