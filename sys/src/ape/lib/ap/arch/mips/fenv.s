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

#ifndef __mips_soft_float

// .set noreorder

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R5
	OR	R4, R5, R5
	XOR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R5
	OR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	AND	$0x7c, R4, R4
	MOVW	FCR31, R2
	RET
	AND	R4, R2, R2

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	MOVW	FCR31, R2
	RET
	AND	$3, R2, R2

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	MOVW	FCR31, R5
	MOVW	$-4, R6
	AND	R6, R5, R5
	OR	R4, R5, R5
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	MOVW	FCR31, R5
	MOVW	R5, 0(R4)
	RET
	MOVW	$0, R2

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	ADD	$1, R4, R5
	BEQ	R5, .Lnum1_0
	NOP
	MOVW	0(R4), R5
.Lnum1_0:
	MOVW	R5, FCR31
	RET
	MOVW	$0, R2

#endif
