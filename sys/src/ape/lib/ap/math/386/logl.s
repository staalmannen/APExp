// GLOBL logl
// .type logl,@function
logl:
	FLDLN2
	FMOVX	4(SP)
	FYL2X
	RET

