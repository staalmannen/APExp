#ifndef _SCHED_H
#define _SCHED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <time.h>

struct sched_param {
	int sched_priority;
};

/* Scheduling policies (Linux values — most portable software uses SCHED_OTHER) */
#define SCHED_OTHER   0
#define SCHED_FIFO    1
#define SCHED_RR      2

int sched_yield(void);
int sched_get_priority_min(int policy);
int sched_get_priority_max(int policy);
int sched_getscheduler(pid_t pid);
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);
int sched_getparam(pid_t pid, struct sched_param *param);
int sched_setparam(pid_t pid, const struct sched_param *param);
int sched_rr_get_interval(pid_t pid, struct timespec *interval);

#ifdef __cplusplus
}
#endif

#endif /* _SCHED_H */
