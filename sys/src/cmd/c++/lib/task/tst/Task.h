/* @(#) $Header: Task.h,v 1.1 90/11/14 12:22:50 ramon Locked $ */

#ifdef mips

// NEW_TASK(new task pointer, new task constructor)
//	must be used to create all new tasks
//	mark place where child stack will start growing
//	create new task as specified
// ### allocating 32 extra words to hold new task arguments is arbitrary
// ### adding 32 assumes stack grows down
#define NEW_TASK(ntp,ntc)						\
{									\
		child_basep = TOP() + 32;				\
		ntp = new ntc;						\
}

// INIT_TASK()
//	must be first line in all user-defined task constructors
//	copy parent's top stack frame to child's stack 
//	put parent at head of run chain and save state of parent
//	when parent executes again, bypass child code by returning to caller
//	in the meantime, initialize state of child and immediately run child
#define INIT_TASK()							\
{									\
	task *parent_taskp = thxstxsk;					\
	task* child_taskp = this;					\
	int conversion = child_basep - child_taskp->t_basep;		\
	int* child_sp = (int*)(TOP() - conversion);			\
	int* child_fp = (int*)(FP() - conversion);			\
	int* child_ap = (int*)(AP() - conversion);			\
	int size = ACTIVE_STK_SZ(child_basep, TOP());			\
	if (size > t_stacksize) {					\
		task_error(E_STACK, child_taskp);			\
	}								\
	copy_stack(child_basep, size, child_taskp->t_basep);		\
	child_taskp->settrap();						\
	parent_taskp->insert(0, child_taskp);				\
	parent_taskp->checktrap();					\
	thxstxsk = child_taskp;						\
	if (setjmp(parent_taskp->t_env) == 1) {				\
		if (team_to_delete) {					\
			delete team_to_delete;				\
			team_to_delete = 0;				\
		}							\
		return;							\
	}								\
	if (fakejmp(child_taskp->t_env, child_sp, child_fp, child_ap) == 0) {\
		longjmp(child_taskp->t_env, 1);				\
	}								\
}

extern int* child_basep;	// place where child stack will start growing

#else	/* not mips */

#define NEW_TASK(ntp,ntc)						\
{									\
		ntp = new ntc;						\
}

#define	INIT_TASK()

#endif	/* mips */
