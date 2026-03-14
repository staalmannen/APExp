// GLOBL acosl
// .type acosl,@function
acosl:
	FMOVX	8(SP)
1:
	FLD	F0
	FLD1
	FSUB	F0, F1
	FADD	F2
	FMULDP
	FSQRT
	FABS
	FXCH	F1
	FPATAN
	RET

