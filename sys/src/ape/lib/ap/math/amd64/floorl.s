// GLOBL floorl
// .type floorl,@function
floorl:
	FMOVX	8(SP)
1:
	MOV	$0x7, AL
1:
	FSTCW	8(SP)
	MOV	9(SP), AH
	MOV	AL, 9(SP)
	FLDCW	8(SP)
	FRNDINT
	MOV	AH, 9(SP)
	FLDCW	8(SP)
	RET

// GLOBL ceill
// .type ceill,@function
ceill:
	FMOVX	8(SP)
	MOV	$0xb, AL
	JMP	1b

// GLOBL truncl
// .type truncl,@function
truncl:
	FMOVX	8(SP)
	MOV	$0xf, AL
	JMP	1b


