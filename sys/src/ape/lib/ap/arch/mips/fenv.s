#ifndef __mips_soft_float

// .set noreorder

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R5
	OR	R4, R5, R5
	XOR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R5
	OR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R2
	RET
	AND	R4, R2, R2

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	MOVW	FCR31, R2
	RET
	AND	$3, R2, R2

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	MOVW	FCR31, R5
	MOVW	$-4, R6
	AND	R6, R5, R5
	OR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	MOVW	FCR31, R5
	MOVW	R5, 0(R4)
	RET
	MOVW	$0, R2

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	ADD	$1, R4, R5
	BEQ	R5, .Lnum1_0
	NOP
	MOVW	0(R4), R5
.Lnum1_0:
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

#endif
