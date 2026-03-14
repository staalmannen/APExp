// GLOBL log1pl
// .type log1pl,@function
log1pl:
	MOV	10(SP), AX
	FLDLN2
	AND	$0x7fffffff, AX
	FMOVX	4(SP)
	CMP	AX, $0x3ffd9400
	JHI	1f
	FYL2XP1
	RET
1:
	FLD1
	FADDDP
	FYL2X
	RET

