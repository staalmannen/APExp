/*
 * sched.c — POSIX process scheduling stubs for Plan9/APExp
 *
 * Plan9 has no kernel scheduling policy API.  sched_yield() is the only
 * function that has a meaningful implementation: sleep(0) surrenders the
 * current time-slice back to the scheduler.  All other calls return
 * sensible defaults so that configure probes and library initialisers
 * that call them do not fail.
 */
#include <sched.h>
#include <errno.h>
#include <unistd.h>

/*
 * sched_yield — relinquish the CPU.
 * Plan9 has no explicit yield syscall; sleep(0) is the conventional idiom.
 */
int
sched_yield(void)
{
	sleep(0);
	return 0;
}

/*
 * sched_get_priority_min/max — return the priority range for POLICY.
 * Plan9 is SCHED_OTHER only; all policies report [0, 0].
 */
int
sched_get_priority_min(int policy)
{
	(void)policy;
	return 0;
}

int
sched_get_priority_max(int policy)
{
	(void)policy;
	return 0;
}

/*
 * sched_getscheduler — report the scheduling policy of a process.
 * Always SCHED_OTHER on Plan9.
 */
int
sched_getscheduler(pid_t pid)
{
	(void)pid;
	return SCHED_OTHER;
}

/*
 * sched_setscheduler — attempt to change policy.
 * SCHED_OTHER is accepted; anything else is EINVAL.
 */
int
sched_setscheduler(pid_t pid, int policy, const struct sched_param *param)
{
	(void)pid; (void)param;
	if(policy != SCHED_OTHER){
		errno = EINVAL;
		return -1;
	}
	return 0;
}

/*
 * sched_getparam / sched_setparam — priority is always 0.
 */
int
sched_getparam(pid_t pid, struct sched_param *param)
{
	(void)pid;
	if(param == NULL){
		errno = EINVAL;
		return -1;
	}
	param->sched_priority = 0;
	return 0;
}

int
sched_setparam(pid_t pid, const struct sched_param *param)
{
	(void)pid;
	if(param == NULL || param->sched_priority != 0){
		errno = EINVAL;
		return -1;
	}
	return 0;
}

/*
 * sched_rr_get_interval — round-robin interval (not applicable).
 * Return a nominal 10 ms interval to keep code that inspects the value
 * from treating 0 as "disabled".
 */
int
sched_rr_get_interval(pid_t pid, struct timespec *interval)
{
	(void)pid;
	if(interval == NULL){
		errno = EINVAL;
		return -1;
	}
	interval->tv_sec  = 0;
	interval->tv_nsec = 10000000L; /* 10 ms */
	return 0;
}
