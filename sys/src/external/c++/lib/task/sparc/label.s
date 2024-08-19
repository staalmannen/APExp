
TEXT	setlabel(SB), $0

	MOVW	R15, (R7)
	MOVW	R1, 4(R7)
	MOVW	$0, R7
	RETURN

TEXT	gotolabel(SB), $0	/* set return value when returning to a label */

	MOVW	4(FP), R8
	MOVW	(R8), R15
	MOVW	4(R8), R1
	RETURN
