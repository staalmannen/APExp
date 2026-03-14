// GLOBL ldexp
// .type ldexp,@function
ldexp:
	NOP

// GLOBL scalbln
// .type scalbln,@function
scalbln:
	NOP

// GLOBL scalbn
// .type scalbn,@function
scalbn:
	MOV	12(SP), AX
	ADD	$0x3ffe, AX
	CMP	AX, $0x7ffd
	JCS	1f
	SUB	$0x3ffe, AX
	SAR	$31, AX
	XOR	$0xfff, AX
	ADD	$0x3ffe, AX
1:
	INC	AX
	FMOVD	4(SP)
	MOV	AX, 12(SP)
	MOV	$0x80000000, AX
	MOV	AX, 8(SP)
	XOR	AX, AX
	MOV	AX, 4(SP)
	FMOVX	4(SP)
	FMULDP
	FMOVDP	4(SP)
	FMOVD	4(SP)
	RET

