#ifndef __QLOCK_H_
#define __QLOCK_H_
#pragma lib "/$M/lib/ape/lib9.a"

#include <u.h>
#include <lock.h>

typedef struct QLp QLp;
struct QLp
{
	int	inuse;
	int	state;
	QLp	*next;
};

typedef
struct QLock
{
	Lock	lock;
	int	locked;
	QLp	*head;
	QLp 	*tail;
} QLock;

typedef
struct Rendez
{
	QLock	*l;
	QLp	*head;
	QLp	*tail;
} Rendez;

#ifdef __cplusplus
extern "C" {
#endif

extern	void	qlock(QLock*);
extern	void	qunlock(QLock*);
extern	int	canqlock(QLock*);

extern	void	rsleep(Rendez*);
extern	int	rwakeup(Rendez*);
extern	int	rwakeupall(Rendez*);

#ifdef __cplusplus
}
#endif

#endif
