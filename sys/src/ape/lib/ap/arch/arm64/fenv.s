// GLOBL fegetround
// .type fegetround,%function
fegetround:
	MRS	x0, fpcr
	AND	w0, w0
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,%function
__fesetround:
	MRS	x1, fpcr
	BIC	w1, w1
	ORR	w1, w1, w0
	MSR	fpcr, x1
	MOV	w0
	RET

// GLOBL fetestexcept
// .type fetestexcept,%function
fetestexcept:
	AND	w0, w0
	MRS	x1, fpsr
	AND	w0, w0, w1
	RET

// GLOBL feclearexcept
// .type feclearexcept,%function
feclearexcept:
	AND	w0, w0
	MRS	x1, fpsr
	BIC	w1, w1, w0
	MSR	fpsr, x1
	MOV	w0
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,%function
feraiseexcept:
	AND	w0, w0
	MRS	x1, fpsr
	ORR	w1, w1, w0
	MSR	fpsr, x1
	MOV	w0
	RET

// GLOBL fegetenv
// .type fegetenv,%function
fegetenv:
	MRS	x1, fpcr
	MRS	x2, fpsr
	STP	w1, w2, [x0]
	MOV	w0
	RET


// GLOBL fesetenv
// .type fesetenv,%function
fesetenv:
	MOV	x1
	MOV	x2
	CMN	x0
	B.EQ	1f
	LDP	w1, w2, [x0]
1:
	MSR	fpcr, x1
	MSR	fpsr, x2
	MOV	w0
	RET


