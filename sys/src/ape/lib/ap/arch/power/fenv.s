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

#if !defined(_SOFT_FLOAT) && !defined(__NO_FPRS__)
// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	ANDISCC	$15872, R3, R3

	ANDISCC	$8192, R3, R0
	MOVWU	R1, -16(R1)
	BEQ	R0, .Lnum1_0
	ORIS	$504, R3, R3
	OR	$1792, R3, R3
.Lnum1_0:






	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	ANDN	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	ANDISCC	$15872, R3, R3

	ANDISCC	$8192, R3, R0
	MOVWU	R1, -16(R1)
	BEQ	R0, .Lnum1_1
	OR	$1024, R3, R3
.Lnum1_1:

	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	OR	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	ANDISCC	$15872, R3, R3

	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	ADD	$16, R1, R1
	AND	R9, R3, R3
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:

	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R3
	ADD	$16, R1, R1
	// clrlwi 3,3,30 (complex rotate — translate manually)
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:




	MOVWU	R1, -16(R1)
	FMOVD	FPSCR, F0
	FMOVD	F0, 8(R1)
	MOVWZ	12(R1), R9
	// clrrwi 9,9,2 (complex rotate — translate manually)
	OR	R3, R9, R9
	MOVW	R9, 12(R1)
	FMOVD	8(R1), F0
	MTFSF	$255, F0


	MOVW	$0, R3
	ADD	$16, R1, R1
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:

	FMOVD	FPSCR, F0
	FMOVD	F0, 0(R3)

	MOVW	$0, R3
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	CMPW	$-1, R3
	BNE	.Lnum1_2
	MOVW	LR, R4
	BL	.Lnum2_0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
	BYTE	$0
.Lnum2_0:
	MOVW	LR, R3
	MOVW	R4, LR
.Lnum1_2:
	FMOVD	0(R3), F0
	MTFSF	$255, F0

	MOVW	$0, R3
	RET
#endif
