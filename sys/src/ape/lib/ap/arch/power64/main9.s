GLOBL	_tos(SB), $8

TEXT	_main(SB), 1, $-8
	ADD	$-16, R1
	MOVD	$0, R0
	MOVD	$setSB(SB), R2
	MOVD	RARG, _tos(SB)

	MOVD	$_apemain(SB), RARG
	MOVD	R0, LR
	MOVD	$_callmain(SB), R4
	MOVD	R4, CTR
	BR	(CTR)
