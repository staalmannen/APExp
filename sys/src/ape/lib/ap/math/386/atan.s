// GLOBL atan
// .type atan,@function
atan:
	FMOVD	4(SP)
	MOV	8(SP), AX
	ADD	AX, AX
	CMP	AX, $0x00200000
	JCS	1f
	FLD1
	FPATAN
	FMOVDP	4(SP)
	FMOVD	4(SP)
	RET

1:
	FMOVF	4(SP)
	RET

