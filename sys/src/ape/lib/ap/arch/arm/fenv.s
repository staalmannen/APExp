

// .syntax unified
// .fpu vfp

// GLOBL fegetround
// .type fegetround,%function
fegetround:
	FMRX	r0, fpscr
	AND	r0, r0
	BX	lr

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,%function
__fesetround:
	FMRX	r3, fpscr
	BIC	r3, r3
	ORR	r3, r3, r0
	FMXR	fpscr, r3
	MOV	r0
	BX	lr

// GLOBL fetestexcept
// .type fetestexcept,%function
fetestexcept:
	AND	r0, r0
	FMRX	r3, fpscr
	AND	r0, r0, r3
	BX	lr

// GLOBL feclearexcept
// .type feclearexcept,%function
feclearexcept:
	AND	r0, r0
	FMRX	r3, fpscr
	BIC	r3, r3, r0
	FMXR	fpscr, r3
	MOV	r0
	BX	lr

// GLOBL feraiseexcept
// .type feraiseexcept,%function
feraiseexcept:
	AND	r0, r0
	FMRX	r3, fpscr
	ORR	r3, r3, r0
	FMXR	fpscr, r3
	MOV	r0
	BX	lr

// GLOBL fegetenv
// .type fegetenv,%function
fegetenv:
	FMRX	r3, fpscr
	STR	r3, [r0]
	MOV	r0
	BX	lr

// GLOBL fesetenv
// .type fesetenv,%function
fesetenv:
	CMN	r0
	MOVEQ	r3
	LDRNE	r3, [r0]
	FMXR	fpscr, r3
	MOV	r0
	BX	lr


