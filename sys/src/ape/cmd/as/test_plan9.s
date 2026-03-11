#include "textflag.h"

// func myfunc(a, b int) int
TEXT ·myfunc(SB),NOSPLIT,$0-24
	MOVQ	a+0(FP), AX
	MOVQ	b+8(FP), BX
	ADDQ	BX, AX
	MOVQ	AX, ret+16(FP)
	RET

TEXT ·loopfunc(SB),NOSPLIT,$8-0
	MOVQ	$0, AX
loop:
	CMPQ	AX, $10
	JGE	done
	INCQ	AX
	JMP	loop
done:
	RET

GLOBL ·mydata(SB),RODATA,$8
DATA ·mydata+0(SB)/8,$0x1234567890abcdef
