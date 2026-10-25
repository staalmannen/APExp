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


