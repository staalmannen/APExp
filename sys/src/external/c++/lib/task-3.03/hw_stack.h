/*ident	"@(#)cls4:lib/task/task/hw_stack.h	1.5" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1993  UNIX System Laboratories, Inc.
Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#ifndef HW_STACK_H
#define HW_STACK_H

/* Machine-dependent macros, typedefs, and externs for task library.
 * Porting these requires intimate knowledge of the stack frame layout,
 * call and return sequences for the machine.
 * They are used by task.c and fudge.c and sim.c.
 * 
 * Some are grouped according to direction of stack growth.
 * 
 * New-style asms would eliminate function calls for TOP, AP, and FP.
 */

typedef unsigned char MACHINE_BYTE;

#define	STACK_GROWS_DOWN

/* typedefs for the hardware state saved on the stack after a call.
 * Assumes eax, ecx, edx are scratch registers, ebp is fp, esp is sp.
 */
typedef struct {
	unsigned long	edi;
	unsigned long	esi;
	unsigned long	ebx;
} HW_REGS;

struct FrameLayout {
	int	offset;			// of base of saved registers from fp
	unsigned short	mask;   	// of registers saved in frame
		FrameLayout(int*);	// called with frame pointer
};

extern int*	Skip_pc_p;		/* global for FUDGE_SP and fudge_sp */
extern "C" {
extern int* FP();			/* FP of caller */
extern void FUDGE_SP(int*, int*);	/* prepare to reset sp */
extern void fudge_sp();			/* reset sp on return through fudged
					 * frame */
extern int* TOP();			/* SP of caller
					 * (pnts to last used word in stack) */
}

#define AP()		0	/* unnecessary on i386 */
#define OLD_AP(fp)	0	/* unnecessary on i386 */
#define OLD_FP(fp)	(*((int*)(fp)))
#define	OLD_PC(fp)	(*((int*)(fp) + 1))
#define	OLD_PC_P(fp)	((int*)(fp) + 1)
#define FIRST_SAVED_REG_P(fp, o)	(((int*)(fp) - (o)) - 1)


extern void	save_saved_regs(HW_REGS*, int*);

/* Save all current regs and regs saved in this frame in reg_struct_p,
 * for restoration when child runs.
 * Note: SAVE_REGS needed in case task::restore() saves more regs
 * than task::task.
 */
#define	SAVE_CHILD_REGS(reg_struct_p)				\
	SAVE_REGS(reg_struct_p);				\
	save_saved_regs((reg_struct_p), ta_fp);

extern "C" {
extern void set_ebx(int*);
extern void set_esi(int*);
extern void set_edi(int*);
}

#define MAXINT_AS_FLOAT 2147483647.0

#endif /* HW_STACK_H */
