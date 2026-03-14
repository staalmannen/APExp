// GLOBL logf
// .type logf,@function
logf:
	FLDLN2
	FMOVF	4(SP)
	FYL2X
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET

