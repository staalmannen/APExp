#include <signal.h>
#include <pthread.h>
#include "../plan9/sys9.h"

#define nelem(a)	(sizeof(a)/sizeof((a)[0]))

struct Thread {
	int		inuse;
	pid_t		pid;

	Lock		l;
	int		exited;
	void		*ret;
	sigset_t	sigset;
	int		state;
};
typedef struct Thread Thread;

#ifdef __cplusplus
extern "C" {
#endif

extern void	_syserrno(void);

extern Thread*	_pthreadalloc(void);
extern void	_pthreadsetpid(Thread*, pthread_t);
extern Thread*	_pthreadnew(pthread_t);
extern Thread*	_pthreadget(pthread_t);
extern void	_pthreadfree(Thread*);

#ifdef __cplusplus
}
#endif
