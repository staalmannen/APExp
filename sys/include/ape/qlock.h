#ifndef __QLOCK_H_
#define __QLOCK_H_
#pragma lib "/$M/lib/ape/libap.a"

#include <u.h>
#include <lock.h>

/*
 * `Lock' comes from <lock.h>, included directly above, and the
 * duplicate that used to sit here could never be suppressed.
 *
 * It was guarded with `#ifndef Lock' -- and **Lock is a typedef, not
 * a macro**, so the preprocessor has never heard of it and that test
 * is ALWAYS TRUE. The second definition was emitted every time.
 *
 * Textually identical is not the same as compatible: each
 * `typedef struct { ... } Lock;' defines its own ANONYMOUS struct, so
 * the two were distinct types sharing a name. C permits a repeated
 * typedef only for compatible types, so this is a constraint
 * violation -- gcc says `conflicting types for Lock' and refuses, and
 * <pthread.h> includes both files, so SIXTEEN of the 149 headers in
 * sys/include/ape could not be compiled by a standards-strict C
 * compiler at all. kencc tolerated it, which is why it survived.
 *
 * Found by `sys/lib/tests/apehdr-sweep.py', which exists because of
 * it. See also the `PATH_MAX'/`NGROUPS_MAX' rounds: *when a name is
 * wrong, grep for EVERY definition of it* -- this is that rule for a
 * TYPE rather than a constant, where the cost is a layout rather than
 * a value.
 */


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

typedef
struct RWLock
{
	Lock	lock;
	int	readers;	/* number of readers */
	int	writer;		/* number of writers */
	QLp	*head;		/* list of waiting processes */
	QLp	*tail;
} RWLock;

#ifdef __cplusplus
extern "C" {
#endif

extern	void	qlock(QLock*);
extern	void	qunlock(QLock*);
extern	int	canqlock(QLock*);

extern	void	rsleep(Rendez*);
extern	int	rwakeup(Rendez*);
extern	int	rwakeupall(Rendez*);

extern	void	rlock(RWLock*);
extern	void	runlock(RWLock*);
extern	int	canrlock(RWLock*);
extern	void	wlock(RWLock*);
extern	void	wunlock(RWLock*);
extern	int	canwlock(RWLock*);

#ifdef __cplusplus
}
#endif

#endif
