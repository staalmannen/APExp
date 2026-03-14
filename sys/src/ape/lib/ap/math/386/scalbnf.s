// GLOBL ldexpf
// .type ldexpf,@function
ldexpf:
	NOP

// GLOBL scalblnf
// .type scalblnf,@function
scalblnf:
	NOP

// GLOBL scalbnf
// .type scalbnf,@function
scalbnf:
	MOV	8(SP), AX
	ADD	$0x3fe, AX
	CMP	AX, $0x7fd
	JCS	1f
	SUB	$0x3fe, AX
	SAR	$31, AX
	XOR	$0x1ff, AX
	ADD	$0x3fe, AX
1:
	INC	AX
	SHL	$20, AX
	FMOVF	4(SP)
	MOV	AX, 8(SP)
	XOR	AX, AX
	MOV	AX, 4(SP)
	FMOVD	4(SP)
	FMULDP
	FMOVFP	4(SP)
	FMOVF	4(SP)
	RET

