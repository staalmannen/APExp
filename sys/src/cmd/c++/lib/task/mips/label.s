
TEXT	setlabel(SB), $-4

	MOVW	R31, 0(R1)
	MOVW	R29, 4(R1)
	MOVW	$0, R1
	RET

TEXT	gotolabel(SB), $-4	/* set return value when returning to a label */

	MOVW	4(FP), R2
	MOVW	0(R2), R31
	MOVW	4(R2), R29
	RET
