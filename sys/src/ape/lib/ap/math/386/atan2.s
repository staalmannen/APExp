// GLOBL atan2
// .type atan2,@function
atan2:
	FMOVD	4(SP)
	FMOVD	12(SP)
	FPATAN
	FMOVDP	4(SP)
	FMOVD	4(SP)
	MOV	8(SP), AX
	ADD	AX, AX
	CMP	AX, $0x00200000
	JCC	1f

	FMOVF	4(SP)
1:
	RET

