
// GLOBL feclearexcept
// .type feclearexcept,@function
feclearexcept:
	ANDIS.	3, 3, 0x3e00

	ANDIS.	0, 3, 0x2000
	STWU	1, -16(1)
	BEQ-	0, 1f
	ORIS	3, 3, 0x01f8
	ORI	3, 3, 0x0700
1:






	MFFS	0
	STFD	0, 8(1)
	LWZ	9, 12(1)
	ANDC	9, 9, 3
	STW	9, 12(1)
	LFD	0, 8(1)
	MTFSF	255, 0


	LI	3, 0
	ADDI	1, 1, 16
	BLR

// GLOBL feraiseexcept
// .type feraiseexcept,@function
feraiseexcept:
	ANDIS.	3, 3, 0x3e00

	ANDIS.	0, 3, 0x2000
	STWU	1, -16(1)
	BEQ-	0, 1f
	ORI	3, 3, 0x0400
1:

	MFFS	0
	STFD	0, 8(1)
	LWZ	9, 12(1)
	OR	9, 9, 3
	STW	9, 12(1)
	LFD	0, 8(1)
	MTFSF	255, 0


	LI	3, 0
	ADDI	1, 1, 16
	BLR

// GLOBL fetestexcept
// .type fetestexcept,@function
fetestexcept:
	ANDIS.	3, 3, 0x3e00

	STWU	1, -16(1)
	MFFS	0
	STFD	0, 8(1)
	LWZ	9, 12(1)
	ADDI	1, 1, 16
	AND	3, 3, 9
	BLR

// GLOBL fegetround
// .type fegetround,@function
fegetround:

	STWU	1, -16(1)
	MFFS	0
	STFD	0, 8(1)
	LWZ	3, 12(1)
	ADDI	1, 1, 16
	CLRLWI	3, 3, 30
	BLR

// GLOBL __fesetround
// .hidden __fesetround
// .type __fesetround,@function
__fesetround:




	STWU	1, -16(1)
	MFFS	0
	STFD	0, 8(1)
	LWZ	9, 12(1)
	CLRRWI	9, 9, 2
	OR	9, 9, 3
	STW	9, 12(1)
	LFD	0, 8(1)
	MTFSF	255, 0


	LI	3, 0
	ADDI	1, 1, 16
	BLR

// GLOBL fegetenv
// .type fegetenv,@function
fegetenv:

	MFFS	0
	STFD	0, 0(3)

	LI	3, 0
	BLR

// GLOBL fesetenv
// .type fesetenv,@function
fesetenv:
	CMPWI	3, -1
	BNE	1f
	MFLR	4
	BL	2f
// .zero 8
2:
	MFLR	3
	MTLR	4
1:
	LFD	0, 0(3)
	MTFSF	255, 0

	LI	3, 0
	BLR



