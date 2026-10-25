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

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:

	MOVL	DI, CX
	ANDL	$0x3f, CX
	FSTSW	AX
	TESTL	AX, CX
	JEQ	.Lnum1_0
	FCLEX
.Lnum1_0:
	STMXCSR	-8(SP)
	ANDL	$0x3f, AX
	ORL	AX, -8(SP)
	TESTL	CX, -8(SP)
	JEQ	.Lnum1_1
	NOTL	CX
	ANDL	CX, -8(SP)
	LDMXCSR	-8(SP)
.Lnum1_1:
	XORL	AX, AX
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	ANDL	$0x3f, DI
	STMXCSR	-8(SP)
	ORL	DI, -8(SP)
	LDMXCSR	-8(SP)
	XORL	AX, AX
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	PUSHQ	AX
	XORL	AX, AX
	MOVL	DI, CX
	FSTCW	(SP)
	ANDB	$0xf3, 1(SP)
	ORB	CH, 1(SP)
	FLDCW	(SP)
	STMXCSR	(SP)
	SHLB	$3, CH
	ANDB	$0x9f, 1(SP)
	ORB	CH, 1(SP)
	LDMXCSR	(SP)
	POPQ	CX
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	PUSHQ	AX
	STMXCSR	(SP)
	POPQ	AX
	SHRL	$3, AX
	ANDL	$0xc00, AX
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	XORL	AX, AX
	FSTENV	(DI)
	STMXCSR	28(DI)
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	XORL	AX, AX
	INCQ	DI
	JEQ	.Lnum1_2
	FLDENV	-1(DI)
	LDMXCSR	27(DI)
	RET
.Lnum1_2:
	PUSHQ	AX
	PUSHQ	AX
	PUSHQ	$0xffff
	PUSHQ	$0x37f
	FLDENV	(SP)
	PUSHQ	$0x1f80
	LDMXCSR	(SP)
	ADDQ	$40, SP
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	ANDL	$0x3f, DI
	PUSHQ	AX
	STMXCSR	(SP)
	POPQ	SI
	FSTSW	AX
	ORL	SI, AX
	ANDL	DI, AX
	RET
