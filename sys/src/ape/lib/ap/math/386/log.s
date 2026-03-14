// GLOBL log
// .type log,@function
log:
	FLDLN2
	FMOVD	4(SP)
	FYL2X
	FMOVDP	4(SP)
	FMOVD	4(SP)
	RET

