// GLOBL log2f
// .type log2f,@function
log2f:
	FLD1
	FMOVF	4(SP)
	FYL2X
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET

