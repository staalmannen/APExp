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

// AND THIS IS THE ONE THAT DOES NOT EVEN ASSEMBLE.  `objtype=386 mk
// install' stopped here, in `arch/386', with eleven diagnostics and
// `too many errors'.  **Three of them are `as' bugs and they are worth
// having written down, because the next translated file meets them
// too:**
//
//  1. ***`CALLL' and `JMPL'.***  The GAS operand-size suffix was
//     appended to CONTROL-TRANSFER mnemonics.  8a's table has `CALL',
//     `JMP' and `JMPF' and no suffixed forms, so `CALLL' lexes as an
//     ordinary LNAME and the parser then wants `:' or `=' after it --
//     which is what `inst: LNAME .= expr' and `saw LNAME' in the
//     diagnostic are saying.  *The `.' in those messages is yacc's item
//     dot, not a character in the file*, so the offending token is the
//     one named by `saw', not the one named by `last name'.
//
//  2. ***GAS numeric local labels passed through verbatim.***
//     `ADDL $__hwcap-1b, (SP)' -- `1b' is GAS for "the nearest `1:'
//     above", and 8a lexes it as the number 1 followed by a name `b'.
//     Hence `last name: b'.
//
//  3. ***TEST's operands are the wrong way round.***  8a's grammar is
//     `rimrem: rim ',' rem' with `rim: rem | imm' and `rem: reg | mem',
//     so **an immediate is legal as the FIRST operand and illegal as
//     the second**.  `TESTL (DX), $0x02000000' and `TESTL AX, $0x3f'
//     are both parse errors for that one reason, and the diagnostic
//     prints the production: `rimrem: rim ,,rem' / `saw $'.
//
// **But fixing all three would still leave this file useless**, and
// that is the point: `__hwcap' DOES NOT EXIST ANYWHERE IN libap -- the
// only five references to it in the whole tree are the five lines in
// this file.  musl's i386 fenv.s reads it at run time to choose between
// the SSE (MXCSR) and x87 (FSTENV) paths, and the PIC sequence those
// `CALLL'/`1b' lines implement exists only to address it.  *So the
// source cannot be translated into anything that works here however
// good the translator gets.*
//
// A real 386 fenv is the x87-only path, written by hand, with TEXT
// directives -- `getfcr.s' in this directory is the shape to follow.

// .hidden __hwcap

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	MOVL	4(SP), CX
	ANDL	$0x3f, CX
	FSTSW	AX

	CALLL	.Lnum1_0
.Lnum1_0:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum2_0

	TESTL	AX, CX
	JEQ	.Lnum1_1
	FCLEX
.Lnum1_1:
	PUSHL	DX
	STMXCSR	(SP)
	POPL	DX
	ANDL	$0x3f, AX
	ORL	AX, DX
	TESTL	DX, CX
	JEQ	.Lnum1_2
	NOTL	CX
	ANDL	CX, DX
	PUSHL	DX
	LDMXCSR	(SP)
	POPL	DX
.Lnum1_2:
	XORL	AX, AX
	RET

.Lnum2_0:
	TESTL	AX, CX
	JEQ	.Lnum1_2
	NOTL	CX
	ANDL	CX, AX
	TESTL	AX, $0x3f
	JEQ	.Lnum1_3
	FCLEX
	JMPL	.Lnum1_2
.Lnum1_3:
	SUBL	$32, SP
	FSTENV	(SP)
	MOVB	AL, 4(SP)
	FLDENV	(SP)
	ADDL	$32, SP
	XORL	AX, AX
	RET

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	MOVL	4(SP), AX
	ANDL	$0x3f, AX
	SUBL	$32, SP
	FSTENV	(SP)
	ORB	AL, 4(SP)
	FLDENV	(SP)
	ADDL	$32, SP
	XORL	AX, AX
	RET

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	MOVL	4(SP), CX
	PUSHL	AX
	XORL	AX, AX
	FSTCW	(SP)
	ANDB	$0xf3, 1(SP)
	ORB	CH, 1(SP)
	FLDCW	(SP)

	CALLL	.Lnum1_4
.Lnum1_4:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_5
	STMXCSR	(SP)
	SHLB	$3, CH
	ANDB	$0x9f, 1(SP)
	ORB	CH, 1(SP)
	LDMXCSR	(SP)
.Lnum1_5:
	POPL	CX
	RET

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	PUSHL	AX
	FSTCW	(SP)
	POPL	AX
	ANDL	$0xc00, AX
	RET

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	MOVL	4(SP), CX
	XORL	AX, AX
	FSTENV	(CX)

	CALLL	.Lnum1_6
.Lnum1_6:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_7
	PUSHL	AX
	STMXCSR	(SP)
	POPL	DX
	ANDL	$0x3f, DX
	ORL	DX, 4(CX)
.Lnum1_7:
	RET

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	MOVL	4(SP), CX
	XORL	AX, AX
	INCL	CX
	JEQ	.Lnum1_8
	FLDENV	-1(CX)
	MOVL	-1(CX), CX
	JMPL	.Lnum2_1
.Lnum1_8:
	PUSHL	AX
	PUSHL	AX
	PUSHL	AX
	PUSHL	AX
	PUSHL	$0xffff
	PUSHL	AX
	PUSHL	$0x37f
	FLDENV	(SP)
	ADDL	$28, SP

.Lnum2_1:
	CALLL	.Lnum1_9
.Lnum1_9:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_10

	ANDL	$0xc00, CX
	SHLL	$3, CX
	ORL	$0x1f80, CX
	MOVL	CX, 4(SP)
	LDMXCSR	4(SP)
.Lnum1_10:
	RET

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	MOVL	4(SP), CX
	ANDL	$0x3f, CX
	FSTSW	AX

	CALLL	.Lnum1_11
.Lnum1_11:
	ADDL	$__hwcap-1b, (SP)
	POPL	DX
	TESTL	(DX), $0x02000000
	JEQ	.Lnum1_12
	STMXCSR	4(SP)
	ORL	4(SP), AX
.Lnum1_12:
	ANDL	CX, AX
	RET
