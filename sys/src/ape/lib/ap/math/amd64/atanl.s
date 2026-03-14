// GLOBL atanl
// .type atanl,@function
atanl:
	FMOVX	8(SP)
	FLD1
	FPATAN
	RET

