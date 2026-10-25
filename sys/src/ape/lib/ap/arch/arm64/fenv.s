// NOT BUILT, AND IT WOULD DO NOTHING IF IT WERE.
//
// This is musl's fenv.s for this architecture, run through
// `sys/src/ape/cmd/as' (the GAS-to-Plan 9 translator).  The translation
// turned `.globl name' and `.type name,@function' into COMMENTS and
// emitted `name:' -- and a bare `name:' in Plan 9 asm is a LOCAL LABEL,
// not a symbol: `8a/a.y's `line: LNAME ':'' sets `type = LLAB' and
// `value = pc' and nothing reaches the object file.  Only TEXT, GLOBL
// and DATA define symbols.  **So every one of these six files assembles
// (where it assembles at all) to an object with no symbols in it.**
//
// What answers `feclearexcept', `fetestexcept', `fegetround',
// `fesetround', `fegetenv' and `fesetenv' in every APE program on every
// architecture is `../../fenv/fenv.c' -- which is musl's fallback for
// "archs lacking fenv implementation", says so in its own comment, and
// returns 0 or FE_TONEAREST to everything.  In musl the arch `.s' is
// built INSTEAD of that file; here both were, and the one with symbols
// won.
//
// `fenv.$O' is out of this directory's mkfile for that reason: removing
// an object that defines nothing cannot change a link, and leaving it in
// stopped the 386 cross build (see below).  The FP environment itself is
// still set correctly at startup -- that is `main9.s', not this file.
//
// Writing a real one means TEXT directives, the Plan 9 calling
// convention for the arguments, and checking it against
// `sys/lib/tests/' -- per architecture.  Recorded in 0.6's inventory.

// GLOBL fegetround
// .type fegetround,%function
fegetround:
	MRS	FPCR, R0
	AND	$0xc00000, R0, R0
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,%function
__fesetround:
	MRS	FPCR, R1
	BIC	$0xc00000, R1, R1
	ORR	R0, R1, R1
	MSR	FPCR, R1
	MOVW	$0, R0
	RET

// GLOBL fetestexcept
// .type fetestexcept,%function
fetestexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	AND	R1, R0, R0
	RET

// GLOBL feclearexcept
// .type feclearexcept,%function
feclearexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	BIC	R0, R1, R1
	MSR	FPSR, R1
	MOVW	$0, R0
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,%function
feraiseexcept:
	AND	$0x1f, R0, R0
	MRS	FPSR, R1
	ORR	R0, R1, R1
	MSR	FPSR, R1
	MOVW	$0, R0
	RET

// GLOBL fegetenv
// .type fegetenv,%function
fegetenv:
	MRS	FPCR, R1
	MRS	FPSR, R2
	STP	(R1, R2), 0(R0)
	MOVW	$0, R0
	RET


// GLOBL fesetenv
// .type fesetenv,%function
fesetenv:
	MOVD	$0, R1
	MOVD	$0, R2
	CMN	$1, R0
	BEQ	.Lnum1_0
	LDP	0(R0), (R1, R2)
.Lnum1_0:
	MSR	FPCR, R1
	MSR	FPSR, R2
	MOVW	$0, R0
	RET
