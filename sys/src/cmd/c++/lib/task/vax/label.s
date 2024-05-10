	.globl _setlabel
	.align	1
_setlabel:
	.word	0x0
	movl	4(ap),r2
	movl	16(fp),(r2)		#pc
	movl	12(fp),8(r2)		#fp
	movl	8(fp),12(r2)		#ap
	movl	20(fp),r3		#number of longs to pop
	mull2	$4,r3			#cvt to bytes
	addl2	$20,r3
	addl3	r3,fp,4(r2)		#sp
	movl	r6,16(r2)		#store the saved regs
	movl	r7,20(r2)
	movl	r8,24(r2)
	movl	r9,28(r2)
	movl	r10,32(r2)
	movl	r11,36(r2)
	clrl	r0
	ret

	.globl _gotolabel
	.align	1
_gotolabel:
	.word	0x0
	movl	4(ap),r0		#return value
	movl	8(ap),r2
	movl	(r2),r3			#get the pc
	movl	16(r2),r6		#restore the saved regs
	movl	20(r2),r7
	movl	24(r2),r8
	movl	28(r2),r9
	movl	32(r2),r10
	movl	36(r2),r11
	movl	12(r2),ap		#ap
	movl	8(r2),fp		#fp
	movl	4(r2),sp		#sp; this has to be next to last
	jmp	(r3)			#pc
	calls	$0, _abort
