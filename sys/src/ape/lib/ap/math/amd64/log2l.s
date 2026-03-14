// GLOBL log2l
// .type log2l,@function
log2l:
	FLD1
	FMOVX	8(SP)
	FYL2X
	RET


