// GLOBL fegetround
// .type fegetround,%function
fegetround:
	MRS	FPCR, R0
	AND	$0xc00000, R0, R0
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,%function
__fesetround:
	MRS	FPCR, R1
	BIC	$0xc00000, R1, R1
	ORR	R0, R1, R1
	MSR	FPCR, R1
	MOVW	$0, R0
	RET

// GLOBL fetestexcept
// .type fetestexcept,%function
fetestexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	AND	R1, R0, R0
	RET

// GLOBL feclearexcept
// .type feclearexcept,%function
feclearexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	BIC	R0, R1, R1
	MSR	FPSR, R1
	MOVW	$0, R0
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,%function
feraiseexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	ORR	R0, R1, R1
	MSR	FPSR, R1
	MOVW	$0, R0
	RET

// GLOBL fegetenv
// .type fegetenv,%function
fegetenv:
	MRS	FPCR, R1
	MRS	FPSR, R2
	STP	(R1, R2), 0(R0)
	MOVW	$0, R0
	RET


// GLOBL fesetenv
// .type fesetenv,%function
fesetenv:
	MOVD	$0, R1
	MOVD	$0, R2
	CMN	$1, R0
	BEQ	.Lnum1_0
	LDP	0(R0), (R1, R2)
.Lnum1_0:
	MSR	FPCR, R1
	MSR	FPSR, R2
	MOVW	$0, R0
	RET
