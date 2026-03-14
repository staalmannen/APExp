// GLOBL log10l
// .type log10l,@function
log10l:
	FLDLG2
	FMOVX	4(SP)
	FYL2X
	RET

