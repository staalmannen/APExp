// GLOBL remquof
// .type remquof,@function
remquof:
	MOV	12(SP), CX
	FMOVF	8(SP)
	FMOVF	4(SP)
	MOV	11(SP), DH
	XOR	7(SP), DH
	JMP	1f

// GLOBL remquol
// .type remquol,@function
remquol:
	MOV	28(SP), CX
	FMOVX	16(SP)
	FMOVX	4(SP)
	MOV	25(SP), DH
	XOR	13(SP), DH
	JMP	1f

// GLOBL remquo
// .type remquo,@function
remquo:
	MOV	20(SP), CX
	FMOVD	12(SP)
	FMOVD	4(SP)
	MOV	19(SP), DH
	XOR	11(SP), DH
1:
	FPREM1
	FNSTSW	AX
	SAHF
	JPS	1b
	FSTP	F1
	MOV	AH, DL
	SHR	DL
	AND	$1, DL
	MOV	AH, AL
	SHR	$5, AL
	AND	$2, AL
	OR	AL, DL
	MOV	AH, AL
	SHL	$2, AL
	AND	$4, AL
	OR	AL, DL
	TEST	DH, DH
	JPL	1f
	NEG	DL
1:
	MOVBLSX	DL, DX
	MOV	DX, (CX)
	RET

