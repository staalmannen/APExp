#if !defined(_SOFT_FLOAT) && !defined(__NO_FPRS__)
// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	ANDISCC	$15872, R3, R3

	ANDISCC	$8192, R3, R0
	MOVWU	R1, -16(R1)
	BEQ	R0, .Lnum1_0
	ORIS	$504, R3, R3
	OR	$1792, R3, R3
.Lnum1_0:






	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	ANDN	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	ANDISCC	$15872, R3, R3

	ANDISCC	$8192, R3, R0
	MOVWU	R1, -16(R1)
	BEQ	R0, .Lnum1_1
	OR	$1024, R3, R3
.Lnum1_1:

	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	OR	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	ANDISCC	$15872, R3, R3

	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	ADD	$16, R1, R1
	AND	R9, R3, R3
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:

	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R3
	ADD	$16, R1, R1
	// clrlwi 3,3,30 (complex rotate — translate manually)
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:




	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	// clrrwi 9,9,2 (complex rotate — translate manually)
	OR	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:

	FMOVD	FPSCR, F0
	FMOVD	F0, 0(R3)

	MOVW	$0, R3
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	CMPW	$-1, R3
	BNE	.Lnum1_2
	MOVW	LR, R4
	BL	.Lnum2_0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
.Lnum2_0:
	MOVW	LR, R3
	MOVW	R4, LR
.Lnum1_2:
	FMOVD	0(R3), F0
	MTFSF	$255, F0

	MOVW	$0, R3
	RET
#endif
