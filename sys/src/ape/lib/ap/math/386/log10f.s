// GLOBL log10f
// .type log10f,@function
log10f:
	FLDLG2
	FMOVF	4(SP)
	FYL2X
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET

