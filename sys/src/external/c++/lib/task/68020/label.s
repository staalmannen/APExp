
TEXT	setlabel(SB), $0

	MOVL	p+0(FP), A0
	MOVL	A7, (A0)+		/* stack pointer */
	MOVL	(A7), (A0)+		/* pc of caller */
	CLRL	R0			/* ret 0 => not returning */
	RTS

TEXT	gotolabel(SB), $0

	MOVL	v+0(FP), R0
	MOVL	p+4(FP), A0
	MOVL	(A0)+, A7		/* stack pointer */
	MOVL	(A0)+, (A7)		/* pc; stuff into stack frame */
	RTS
