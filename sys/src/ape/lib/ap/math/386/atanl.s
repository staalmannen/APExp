// GLOBL atanl
// .type atanl,@function
atanl:
	FMOVX	4(SP)
	FLD1
	FPATAN
	RET

