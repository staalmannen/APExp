// GLOBL atan2l
// .type atan2l,@function
atan2l:
	FMOVX	4(SP)
	FMOVX	16(SP)
	FPATAN
	RET

