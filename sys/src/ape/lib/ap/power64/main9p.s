GLOBL	_tos(SB), $8

TEXT	_mainp(SB), 1, $-8
	ADD	$-16, R1
	MOVD	$0, R0
	MOVD	$setSB(SB), R2
	MOVD	RARG, _tos(SB)

	MOVD	$_profmain(SB), RARG
	MOVD	R0, LR
	MOVD	$_callmain(SB), R4
	MOVD	R4, CTR
	BR	(CTR)

TEXT	_callpc(SB), 1, $-8
	MOVD	argp-8(FP), RARG
TEXT	_saveret(SB), 1, $-8
TEXT	_savearg(SB), 1, $-8
	RETURN
