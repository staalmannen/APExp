// GLOBL floorf
// .type floorf,@function
floorf:
	FMOVF	4(SP)
	JMP	1f

// GLOBL floorl
// .type floorl,@function
floorl:
	FMOVX	4(SP)
	JMP	1f

// GLOBL floor
// .type floor,@function
floor:
	FMOVD	4(SP)
1:
	MOV	$0x7, AL
1:
	FSTCW	4(SP)
	MOV	5(SP), AH
	MOV	AL, 5(SP)
	FLDCW	4(SP)
	FRNDINT
	MOV	AH, 5(SP)
	FLDCW	4(SP)
	RET

// GLOBL ceil
// .type ceil,@function
ceil:
	FMOVD	4(SP)
	MOV	$0xb, AL
	JMP	1b

// GLOBL ceilf
// .type ceilf,@function
ceilf:
	FMOVF	4(SP)
	MOV	$0xb, AL
	JMP	1b

// GLOBL ceill
// .type ceill,@function
ceill:
	FMOVX	4(SP)
	MOV	$0xb, AL
	JMP	1b

// GLOBL trunc
// .type trunc,@function
trunc:
	FMOVD	4(SP)
	MOV	$0xf, AL
	JMP	1b

// GLOBL truncf
// .type truncf,@function
truncf:
	FMOVF	4(SP)
	MOV	$0xf, AL
	JMP	1b

// GLOBL truncl
// .type truncl,@function
truncl:
	FMOVX	4(SP)
	MOV	$0xf, AL
	JMP	1b

