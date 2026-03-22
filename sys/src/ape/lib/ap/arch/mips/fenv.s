

// .set noreorder

// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	AND	$4, $4, 0x7c
	CFC1	$5, $31
	OR	$5, $5, $4
	XOR	$5, $5, $4
	CTC1	$5, $31
	JR	$ra
	LI	$2, 0

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	AND	$4, $4, 0x7c
	CFC1	$5, $31
	OR	$5, $5, $4
	CTC1	$5, $31
	JR	$ra
	LI	$2, 0

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	AND	$4, $4, 0x7c
	CFC1	$2, $31
	JR	$ra
	AND	$2, $2, $4

// GLOBL fegetround
// .type fegetround,@function
fegetround:
	CFC1	$2, $31
	JR	$ra
	ANDI	$2, $2, 3

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:
	CFC1	$5, $31
	LI	$6, -4
	AND	$5, $5, $6
	OR	$5, $5, $4
	CTC1	$5, $31
	JR	$ra
	LI	$2, 0

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:
	CFC1	$5, $31
	SW	$5, 0($4)
	JR	$ra
	LI	$2, 0

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	ADDIU	$5, $4, 1
	BEQ	$5, $0, 1f
	NOP
	LW	$5, 0($4)
1:
	CTC1	$5, $31
	JR	$ra
	LI	$2, 0



