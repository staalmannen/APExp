arg=0
sp=13
sb=12
lr=14

GLOBL	_tos(SB), $4

TEXT	_main(SB), 1, $0
	SUB	$8, R(sp)
	MOVW	$setR12(SB), R(sb)
	MOVW	R(arg), _tos(SB)

	MOVW	$_apemain(SB), R(arg)
	MOVW	$0, R(lr)
	B	_callmain(SB)

	BL	_div(SB)	/* force loading of div */
