// GLOBL log2l
// .type log2l,@function
log2l:
	FLD1
	FMOVX	4(SP)
	FYL2X
	RET

