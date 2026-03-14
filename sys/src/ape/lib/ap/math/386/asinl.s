// GLOBL asinl
// .type asinl,@function
asinl:
	FMOVX	4(SP)
	FLD	F0
	FLD1
	FSUB	F0, F1
	FADD	F2
	FMULDP
	FSQRT
	FPATAN
	RET

