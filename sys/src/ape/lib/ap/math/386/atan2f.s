// GLOBL atan2f
// .type atan2f,@function
atan2f:
	FMOVF	4(SP)
	FMOVF	8(SP)
	FPATAN
	FMOVFP	4(SP)
	FMOVF	4(SP)
	MOV	4(SP), AX
	ADD	AX, AX
	CMP	AX, $0x01000000
	JCC	1f

	FLD	F0
	FMUL	F1
	FMOVFP	4(SP)
1:
	RET

