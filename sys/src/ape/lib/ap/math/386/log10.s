// GLOBL log10
// .type log10,@function
log10:
	FLDLG2
	FMOVD	4(SP)
	FYL2X
	FMOVDP	4(SP)
	FMOVD	4(SP)
	RET

