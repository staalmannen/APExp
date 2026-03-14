// GLOBL acosf
// .type acosf,@function
acosf:
	FMOVF	4(SP)
	FLD	F0
	FLD1
	FSUB	F0, F1
	FADD	F2
	FMULDP
	FSQRT
	FABS
	FXCH	F1
	FPATAN
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET


