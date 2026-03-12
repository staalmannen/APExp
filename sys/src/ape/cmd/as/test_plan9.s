// test_plan9.s - Plan 9 assembly test for the 'as' front-end
// Written in native 9front Plan 9 syntax (no Go-isms).
//
// Differences from Go assembly:
//   - No #include "textflag.h" (9front 6a has no #define support)
//   - No middle-dot (·) package prefix on symbol names
//   - TEXT flags are raw numbers: NOSPLIT=4, RODATA=8, NOPTR=16
//   - Frame size format: $localsize (no -argsize suffix in plan9 asm)

// Simple function: myfunc(a, b int) int
// TEXT flags: 4 = NOSPLIT
TEXT myfunc(SB),4,$0
	MOVQ	a+0(FP), AX
	MOVQ	b+8(FP), BX
	ADDQ	BX, AX
	MOVQ	AX, ret+16(FP)
	RET

// Loop function
TEXT loopfunc(SB),4,$8
	MOVQ	$0, AX
loop:
	CMPQ	AX, $10
	JGE	done
	INCQ	AX
	JMP	loop
done:
	RET

// Read-only global data
// GLOBL flags: 8|16 = RODATA|NOPTR = 24
GLOBL mydata(SB),24,$8
DATA mydata+0(SB)/8,$0x1234567890abcdef
