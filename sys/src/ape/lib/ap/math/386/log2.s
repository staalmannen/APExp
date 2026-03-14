// GLOBL log2
// .type log2,@function
log2:
	FLD1
	FMOVD	4(SP)
	FYL2X
	FMOVDP	4(SP)
	FMOVD	4(SP)
	RET

