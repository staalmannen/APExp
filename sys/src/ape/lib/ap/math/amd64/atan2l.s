// GLOBL atan2l
// .type atan2l,@function
atan2l:
	FMOVX	8(SP)
	FMOVX	24(SP)
	FPATAN
	RET

