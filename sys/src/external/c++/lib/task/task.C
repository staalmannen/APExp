/*ident	"@(#)C++env:lib/task/task/task.c	1.6" */
/**************************************************************************
			Copyright (c) 1984 AT&T
	  		  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/
// this file now assumes that the stack grows down;
// make another if the stack grows up, or split this
// into pieces such that one piece knows about stack growing
// and the other doesn't.
// DO NOT JUST USE IFDEFS!!!!

#include <task.h>
#include <assert.h>
#include <stdlib.h>

#ifdef uts
enum {SIZE = 2048};
#else
enum {SIZE = 750};
#endif

// align stack if needed
#define ALIGN(stack)	((ulong *)((long)(stack) & ~(sizeof(double) - 1)))
enum { UNTOUCHED = 052525 };	/* value considered never used */

typedef unsigned long ulong;

// a team is a collection of tasks that share one stack
class team
{
friend task;
	int	no_of_tasks;
	task	*got_stack;
	ulong	*stack;
	ulong	*stackend;	// of the stack
	team(task*, int);	// stacksize == 0 ==> using the main stack
	~team() { delete stackend; }
};

int _hwm;
static ulong *stack_base;
static int stackdown;		// does the stack grow down or up?
static task *running;		// task on the current stack

team::team(task* t, int stacksize) {
	no_of_tasks = 1;
	got_stack = t;
	if (stacksize) {
		stack = new ulong[stacksize];
		stackend = ALIGN(stack + stacksize - 1);
		while (stack == 0)
			object::task_error(E_STORE, (object*)0);
		if (_hwm)
			for (ulong *x = stack; x <= stackend; x++)
				*x = UNTOUCHED;
		if (stackdown) {
			ulong *t = stack;
			stack = stackend;
			stackend = t;
		}
	} else {
		stackend = 0;
		stack = stack_base;
	}
}

/* called from _main to set __main__base */
void __task__init()
{
	// get args for main
	// main => _main => __task__init
	Label m;
	setlabel(&m);
	stack_base = stackbase(m);
	stackdown = (ulong)stack_base > m.sp;
	new task("main");	// fire up a main task
}

Label
task::copy_task(Label top, ulong *base, ulong *stack)
{
	ulong *stop = (ulong *)top.sp;
	if (base == stop)
		task_error(E_STACK, this);
	if (stackdown)
		while (base > stop)
			*stack-- = *base--;
	else
		while (base < stop)
			*stack++ = *base++;
	*stack = *base;
	return movelabel(top, (ulong)stack);
}

void
task::swapjmp()
{
	if (t_savearea)
		delete t_savearea;
	t_savearea = 0;
	t_size = 0;
	t_team->got_stack = this;
	gotolabel(1, &t_env);
}

void
task::doswap(task *on, int ischild)
{
	// make sure we have enough room to work
	// if we are running on the stack we want to swap
	if (running == on) {
		Label m;
	
		setlabel(&m);
		ulong *t = argbase(m);
		ulong sz = stackdown
			? (ulong)t_team->stack - (ulong)t
			: (ulong)t - (ulong)t_team->stack;
		// recursive call to increase the size of this stack
		if (sz <= t_size) {
			doswap(on, ischild);
			abort();
		}
	}
	on->t_size += sizeof(double);
	on->t_savearea = new char[on->t_size];
	on->t_save = stackdown
		? on->t_savearea + on->t_size - sizeof(ulong)
		: on->t_savearea + sizeof(double) - sizeof(ulong);
	on->t_save = (char *)ALIGN(on->t_save);
	on->t_env = copy_task(on->t_env, t_team->stack, (ulong *)on->t_save);
	if (!ischild)
		t_env = copy_task(t_env, (ulong *)t_save, t_team->stack);
	swapjmp();
}

void
task::swap(int ischild)
{
	task *on = on = t_team->got_stack;
	if (this != on) {
		if (ischild)
			t_size = stackdown
				? (ulong)t_team->stack - t_env.sp
				: t_env.sp - (ulong)t_team->stack;
		on->t_size = stackdown
			? (ulong)t_team->stack - on->t_env.sp
			: (ulong)on->t_env.sp - (ulong)t_team->stack;
		doswap(on, ischild);
	}
	swapjmp();
}

inline
void
task::settrap()
{
	if (t_team->stackend)	// Don't set trap for main task
		t_trap = *t_team->stackend;
}

inline
void
task::checktrap()
{
	// Don't test for main task
	if (t_team->stackend && t_trap != *t_team->stackend)
		task_error(E_STACK, this);
}

task::task(char* name, modetype mode, int stacksize)
/*
	executed in the task creating a new task - thistask.
	1:	put thistask at head of scheduler queue,
	2:	create new task
	3:	transfer execution to new task
	derived::derived can never return - its return link is destroyed

	if thistask==0 then we are executing on main()'s stack and
	should turn it into the "main" task
*/
{
	running = thxstxsk;
	t_name = name;
	t_mode = (mode) ? mode : (modetype) DEFAULT_MODE;
	t_stacksize = (stacksize) ? stacksize : SIZE;
	t_savearea = 0;
	t_size = 0;
	t_alert = 0;
	s_state = RUNNING;
	t_next = txsk_chxin;
	txsk_chxin = this;

	if (thxstxsk == 0) {		// called from __task__init()
		// create "main" task
		t_team = new team(this, 0);	/* don't allocate stack */
		t_team->no_of_tasks = 2;   	/* never deallocate */
		thxstxsk = this;
		return;
	}
	// schedule this task to run now
	thxstxsk->insert(0, this);

	switch (t_mode) {
	case DEDICATED:
		t_team = new team(this, t_stacksize);

		if (setlabel(&thxstxsk->t_env) == 0) {
			// child; returns first
			Label child = upframe(thxstxsk->t_env);

			thxstxsk = this;
			child = copy_task(child, argbase(child), t_team->stack);
			settrap();
			gotolabel((long)this, &child);
		}
		break;

	case SHARED:
		thxstxsk->t_mode = SHARED; /* you cannot share on your own */
		t_team = thxstxsk->t_team;
		t_team->no_of_tasks++;
		if (setlabel(&thxstxsk->t_env) == 0) {
			// child; return first
			if (setlabel(&t_env) == 0)
				swap(1);
			// ok, now we are really running;
			thxstxsk = this;
			Label child = upframe(t_env);
			settrap();
			gotolabel((long)this, &child);
		}
		break;
	default:
		task_error(E_TASKMODE, this);
	}

	// parent
	if (team_to_delete) {
		delete team_to_delete;
		team_to_delete = 0;
	}
	/* return this to function that called the derived constructor */
	Label me = upframe(upframe(thxstxsk->t_env));
	gotolabel((long)this, &me);
}

void
task::resume()
{
	running = thxstxsk;
	thxstxsk = this;
	if (running && running->s_state != TERMINATED)
		running->checktrap();

	// NOTE -- need to do shared here
	if (running == 0 || setlabel(&running->t_env) == 0) {
		if (t_mode == SHARED)
			swap(0);
		else
			gotolabel(1, &this->t_env);
	}
	if (team_to_delete) {
		delete team_to_delete;
		team_to_delete = 0;
	}
}

void
task::cancel(int val)
/*
	TERMINATE and free stack space
*/
{
	if (this->s_state != TERMINATED) {
		sched::cancel(val);
		if (_hwm) t_size = curr_hwm();
		if (t_team && (t_team->no_of_tasks-- == 1)) {
			if (this != thxstxsk) {
				delete t_team;
			} else {	// don't delete current stack!
				// delete will be called from task::restore
				// immediately after task switch
				assert(team_to_delete == 0);
				team_to_delete = t_team;
			}
			t_team = 0;	// no further access to deleted team
		}
	}
	}

task::~task()
/*
	free stack space and remove task from task chain
*/
{
	if (s_state != TERMINATED) task_error(E_TASKDEL, this);
	if (this == txsk_chxin)
		txsk_chxin = t_next;
	else {
		register task* t;
		register task* tt;

		for (t=txsk_chxin; tt=t->t_next; t=tt)  
			if (tt == this) {
				t->t_next = t_next;
				break;
			}
	}

	if (t_savearea)
		delete t_savearea;
	if (this == thxstxsk) {
		delete (int*) thxstxsk;	/* fudge: free(_that) */
		thxstxsk = 0;
		schedule();
	}
}

void
task::resultis(int val)
{
	cancel(val);
	if (this == thxstxsk) schedule();
}

void
task::sleep(object* t)
{
	if (t) t->remember(this);
	if (s_state == RUNNING) remove();
	if (this == thxstxsk) schedule();
}

void
task::delay(long d)
{
	insert(d,this);
	if (thxstxsk == this) schedule();
}

long
task::preempt()
{
	if (s_state == RUNNING) {
		remove();
		return s_time - get_clock();
	}
	else {
		task_error(E_TASKPRE, this);
		return 0;
	}
}

char*
state_string(sched::statetype s)
{
	switch (s) {
	case sched::IDLE:		return "IDLE";
	case sched::TERMINATED:	return "TERMINATED";
	case sched::RUNNING:		return "RUNNING";
	default:		return 0;
	}
}

char*
mode_string(task::modetype m)
{
	switch(m) {
	case task::SHARED:	return "SHARED";
	case task::DEDICATED:	return "DEDICATED";
	default:		return 0;
	}
}

void
task::print(int n, int baseClass)
/*
	"n" values:	CHAIN, VERBOSE, STACK
*/
{
	if (!baseClass)
		fprintf(stderr, "task\n");

	char* ss = state_string(s_state);
	char* ns = (t_name) ? t_name : "";
	
	fprintf(stderr, "task %s ",ns);
	if (this == thxstxsk)
		fprintf(stderr, "(is thistask, %s) ", ss);
	else if (ss)
		fprintf(stderr, "(%s) ",ss);
	else
		fprintf(stderr, "(state==%d CORRUPTED) ",s_state);
	fprintf(stderr, "\tthis = %x:\n", this);

	if (n&VERBOSE) {
		char* ms = mode_string(t_mode);
		if (ms == 0) ms = "CORRUPTED";
		fprintf(stderr, "\tmode=%s t_alert=%x t_next=%x",
			ms, t_alert, t_next);
		fprintf(stderr, (s_state==TERMINATED) ? " result=%d\n" : " s_time=%d\n", s_time);
	}

	if (n&STACK) {
		fprintf(stderr, "\tstack: ");
		fprintf(stderr, "stack=0x%x, stackend=0x%x, ",
			t_team->stack, t_team->stackend);
		if (s_state == TERMINATED) {
			fprintf(stderr, "deleted.  ");
			if (_hwm)
				fprintf(stderr, "hwm size=%d", t_size);
			fprintf(stderr, "\n");
		} else {
			fprintf(stderr, "\tsizes:\t");
			ulong *top;
			if (this==thxstxsk) {	// figure out real current size
				Label m;

				setlabel(&m);
				top = (ulong *)m.sp;
			} else		// approximate at last switch
				top = (ulong *)t_env.sp;
			ulong sz = stackdown ? (ulong)t_team->stack - (ulong)top
					: (ulong)top - (ulong)t_team->stack;
			if (t_mode == SHARED)
				sz = t_size;
			fprintf(stderr, "max=%d, current=%d", t_stacksize, sz);
			int my_hwm;
			if (_hwm) {
				my_hwm = curr_hwm();
				fprintf(stderr, ", hwm=%d", my_hwm);
			}
			fprintf(stderr, "\n\t\taddresses:\t");
			fprintf(stderr, "top of stack=0x%x", top);
			if (_hwm)
				fprintf(stderr, ", hwm=0x%x",
					stackdown ? t_team->stack - my_hwm
					: t_team->stack + my_hwm);
			fprintf(stderr, "\n");
		}
	}

	if (n&CHAIN) {
		sched::print(n, 1);	// call sched::print here to keep
					// output for same object together
		// Start at beginning of task chain, and print all tasks
		task *tp = get_task_chain();
		if (tp == this) {
			tp = tp->t_next;	// just printed, skip it
		} else {
			fprintf(stderr, "\nChain of all tasks:\n");
		}
		for (; tp; tp = tp->t_next) {
			fprintf(stderr, "Next task on chain of all tasks is:\n");
			tp->print(n & ~CHAIN);
		}
	} else {
		sched::print(n, 1);
	}
}

int
task::curr_hwm()
{
	ulong *b = t_team->stackend;
	ulong *e = t_team->stack;
	if (stackdown)
		while (b < e && *b == UNTOUCHED)
			b++;
	else
		while (b > e && *b == UNTOUCHED)
			b--;
	return stackdown ? e - b : b - e;
}

void
task::wait(object* ob)
{
	if (ob == (object*)this) task_error(E_WAIT, this);
	t_alert = ob;
	while (ob->pending())
		sleep(ob);
}

int
task::waitlist(object* a ...)
{
	return waitvec(&a);
}

int
task::waitvec(object** v)
/*
	first determine if it is necessary to sleep(),
	return hint: who caused return
*/
{
	int i;
	int j;
	register object* ob;

	for(;;) {
		for (i = 0; ob = v[i]; i++) {
			if (!ob->pending()) goto ex;
			ob->remember(this);
		}
		if (i==1 && v[0]==(object*)this) task_error(E_WAIT, this);
		sleep();
	}
ex:
	t_alert = ob;
	for (j = 0; ob = v[j]; j++)
		ob->forget(this);
	return i;
} 

// not on plan 9 yet Interrupt_alerter	interrupt_alerter;
