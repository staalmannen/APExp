#include "label.h"
#include <assert.h>

typedef unsigned long ulong;

/* 
 * return stack location guaranteed to have args for f in it
 */
unsigned long *
argbase(Label f)
{
	f = upframe(upframe(f));
	return (ulong *)f.sp;
}

/*
 * adjust label to reflect a moved stack location
 */
Label
movelabel(Label f, ulong sp)
{
	f.sp = sp;
	return f;
}

/*
 * return the top of main's stack
 * main => _main => __task__init => setlabel(m)
 */
ulong *
stackbase(Label m)
{
	return (ulong *)upframe(upframe(upframe(m))).sp;
}

#define MASKI	0xffffe000	/* mask SUBI reg bits in instruction */
#define MASKHI	0xfffc0000	/* mask SETHI reg bits in instruction */
#define SUBTSP	0x8220400e	/* SUB	R14, R1; for large stack frames */
#define	SUBISP	0x82206000	/* SUBI	const, R1 */
#define SETHI	0x1d000000	/* load hi part of R14 with constant << 10 */
#define ADDI	0x9c03a000	/* add low part to R14 */

#include <stdio.h>

/*
  * find the label for the frame calling f
 */
Label
upframe(Label f)
{
	ulong *pc;
	long offset;

	/* look for MOV R14,R1 or ADDIU const,R1 */
	for(pc = (ulong *)f.pc; (*pc & MASKI) != SUBISP; pc--)
		if(*pc == SUBTSP){
			/* look for sethi & optional add low into R14 */
			offset = 0;
			while((*--pc & MASKHI) != SETHI)
				if((*pc & MASKI) == ADDI){
					offset = *pc &~ MASKI;
					if(offset & 0x1000)
						offset |= MASKI;
				}
			offset += (*pc &~ MASKHI) << 10;
			break;
		}

	/* get the constant */
	if((*pc & MASKI) == SUBISP){
		offset = *pc &~ MASKI;
		/* sign extend */
		if (offset & 0x1000)
			offset |= MASKI;
	}

	/* return pc = 0(R1) */
	f.pc = *(ulong *)f.sp;

	f.sp += offset;
	return f;
}
