// GLOBL ldexpl
// .type ldexpl,@function
ldexpl:
	NOP

// GLOBL scalblnl
// .type scalblnl,@function
scalblnl:
	NOP

// GLOBL scalbnl
// .type scalbnl,@function
scalbnl:
	MOV	16(SP), AX
	ADD	$0x3ffe, AX
	CMP	AX, $0x7ffd
	JCC	1f
	INC	AX
	FMOVX	4(SP)
	MOV	AX, 12(SP)
	MOV	$0x80000000, AX
	MOV	AX, 8(SP)
	XOR	AX, AX
	MOV	AX, 4(SP)
	FMOVX	4(SP)
	FMULDP
	RET
1:
	FMOVL	16(SP)
	FMOVX	4(SP)
	FSCALE
	FSTP	F1
	RET

