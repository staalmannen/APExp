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

#define MASK	0xffff0000	/* mask ADDIU reg bits in instruction */
#define ADDTSP	0x03bce820	/* ADD	R28,R29; for large stack frames */
#define ADDISP	0x23bd0000	/* ADDIU const, R29 */
#define LUI	0x3c1c0000	/* load hi part of R28 with constant << 16 */
#define ORI	0x379c0000	/* R28 <= R28 or constant */
/*
  * find the label for the frame calling f
 */
Label
upframe(Label f)
{
	ulong *pc;
	long offset;

	/* look for MOV R28,R29 or ADDIU const,R29 */
	for(pc = (ulong *)f.pc; (*pc & MASK) != ADDISP; pc--)
		if(*pc == ADDTSP){
			/* look for loading hi optiona; oring low into R28 */
			offset = 0;
			while((*--pc & MASK) != LUI)
				if((*--pc & MASK) == ORI){
					offset = *pc &~ MASK;
					if (offset & 0x8000)
						offset |= MASK;
				}
			offset += (*pc &~ MASK) << 16;
			break;
		}

	/* get the constant */
	if((*pc & MASK) == ADDISP){
		offset = *pc &~ MASK;
		/* sign extend, cause it doesn't work on vc */
		if (offset & 0x8000)
			offset |= MASK;
	}
	offset = offset < 0 ? -offset : offset;

	/* return pc = 0(R29) */
	f.pc = *(ulong *)f.sp;

	f.sp += offset;
	return f;
}
