// GLOBL atanf
// .type atanf,@function
atanf:
	FMOVF	4(SP)
	MOV	4(SP), AX
	ADD	AX, AX
	CMP	AX, $0x01000000
	JCS	1f
	FLD1
	FPATAN
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET

1:
	FLD	F0
	FMUL	F1
	FMOVFP	4(SP)
	RET

