// GLOBL log10l
// .type log10l,@function
log10l:
	FLDLG2
	FMOVX	8(SP)
	FYL2X
	RET

