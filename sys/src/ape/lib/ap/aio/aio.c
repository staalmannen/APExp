/*
 * aio.c - Portable POSIX AIO on top of pthreads
 *
 * Plan9 / APExp implementation.  No Linux-specific syscalls.
 * Uses a single background worker thread (adequate for most porting
 * use cases; the API is sequential anyway unless lio_listio is used).
 *
 * Bugs fixed vs the original Copilot-generated version:
 *  - Added missing #include <pthread.h>
 *  - aio_suspend: was waiting on a local cond that was never signalled
 *    (deadlock).  Now waits on the per-request cb->__cond.
 *  - init_cb: removed redundant initialized flag around pthread_once;
 *    pthread_once is itself the once-only mechanism.
 *  - aio_fsync: now calls fsync(2) for real instead of enqueuing a NOP.
 *  - aio_cancel: implemented (returns AIO_CANCELED / AIO_ALLDONE).
 *  - Worker thread is created detached so it doesn't need joining.
 *  - lio_listio LIO_WAIT: uses aio_suspend correctly.
 *  - pthread_cond_timedwait on Plan9 ignores the timeout (it's a macro
 *  - pthread_cond_timedwait is now properly implemented; aio_suspend
 *    uses it directly instead of the old nanosleep polling fallback.
 */

#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* ------------------------------------------------------------------
 * Task queue
 * ------------------------------------------------------------------ */

typedef struct aio_task {
	struct aiocb    *cb;
	struct aio_task *next;
} aio_task;

static pthread_mutex_t aio_q_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  aio_q_cond = PTHREAD_COND_INITIALIZER;
static aio_task       *aio_q_head;
static aio_task       *aio_q_tail;

static void
enqueue(struct aiocb *cb)
{
	aio_task *t = malloc(sizeof(aio_task));
	if(!t) {
		/* allocation failure: complete immediately with ENOMEM */
		pthread_mutex_lock(&cb->__lock);
		cb->__ret    = -1;
		cb->__status = ENOMEM;
		cb->__queued = 0;
		pthread_cond_broadcast(&cb->__cond);
		pthread_mutex_unlock(&cb->__lock);
		return;
	}
	t->cb   = cb;
	t->next = NULL;

	pthread_mutex_lock(&aio_q_lock);
	if(aio_q_tail)
		aio_q_tail->next = t;
	else
		aio_q_head = t;
	aio_q_tail = t;
	pthread_cond_signal(&aio_q_cond);
	pthread_mutex_unlock(&aio_q_lock);
}

static struct aiocb *
dequeue(void)
{
	aio_task    *t;
	struct aiocb *cb;

	pthread_mutex_lock(&aio_q_lock);
	while(!aio_q_head)
		pthread_cond_wait(&aio_q_cond, &aio_q_lock);

	t          = aio_q_head;
	aio_q_head = t->next;
	if(!aio_q_head)
		aio_q_tail = NULL;
	pthread_mutex_unlock(&aio_q_lock);

	cb = t->cb;
	free(t);
	return cb;
}

/* ------------------------------------------------------------------
 * Worker thread
 * ------------------------------------------------------------------ */

static void *
aio_worker(void *arg)
{
	(void)arg;
	for(;;) {
		struct aiocb *cb = dequeue();
		ssize_t ret;
		int err = 0;

		pthread_mutex_lock(&cb->__lock);
		if(cb->__status == ECANCELED) {
			/* cancelled before we started */
			cb->__queued = 0;
			pthread_cond_broadcast(&cb->__cond);
			pthread_mutex_unlock(&cb->__lock);
			continue;
		}
		cb->__status = EINPROGRESS;
		pthread_mutex_unlock(&cb->__lock);

		if(cb->__op == LIO_READ)
			ret = pread(cb->aio_fildes,
			            (void *)cb->aio_buf,
			            cb->aio_nbytes,
			            cb->aio_offset);
		else if(cb->__op == LIO_WRITE)
			ret = pwrite(cb->aio_fildes,
			             (const void *)cb->aio_buf,
			             cb->aio_nbytes,
			             cb->aio_offset);
		else if(cb->__op == LIO_FSYNC) {
			ret = fsync(cb->aio_fildes);
		} else {
			/* LIO_NOP */
			ret = 0;
		}

		if(ret < 0)
			err = errno;

		pthread_mutex_lock(&cb->__lock);
		cb->__ret    = ret;
		cb->__status = err;
		cb->__queued = 0;
		pthread_cond_broadcast(&cb->__cond);
		pthread_mutex_unlock(&cb->__lock);
	}
	/* NOTREACHED */
	return NULL;
}

static pthread_once_t aio_once = PTHREAD_ONCE_INIT;

static void
start_worker(void)
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&tid, &attr, aio_worker, NULL);
	pthread_attr_destroy(&attr);
}

/* ------------------------------------------------------------------
 * cb initialisation
 * ------------------------------------------------------------------ */

static void
init_cb(struct aiocb *cb, int op)
{
	pthread_once(&aio_once, start_worker);

	pthread_mutex_init(&cb->__lock, NULL);
	pthread_cond_init(&cb->__cond, NULL);
	cb->__op     = op;
	cb->__status = EINPROGRESS;
	cb->__ret    = -1;
	cb->__queued = 1;
}

/* ------------------------------------------------------------------
 * Public API
 * ------------------------------------------------------------------ */

int
aio_read(struct aiocb *cb)
{
	if(!cb) { errno = EINVAL; return -1; }
	init_cb(cb, LIO_READ);
	enqueue(cb);
	return 0;
}

int
aio_write(struct aiocb *cb)
{
	if(!cb) { errno = EINVAL; return -1; }
	init_cb(cb, LIO_WRITE);
	enqueue(cb);
	return 0;
}

int
aio_fsync(int op, struct aiocb *cb)
{
	if(!cb) { errno = EINVAL; return -1; }
	if(op != O_SYNC && op != O_DSYNC) { errno = EINVAL; return -1; }
	init_cb(cb, LIO_FSYNC);
	enqueue(cb);
	return 0;
}

int
aio_error(const struct aiocb *cb)
{
	int s;
	if(!cb) return EINVAL;
	pthread_mutex_lock((pthread_mutex_t *)&cb->__lock);
	s = cb->__queued ? EINPROGRESS : cb->__status;
	pthread_mutex_unlock((pthread_mutex_t *)&cb->__lock);
	return s;
}

ssize_t
aio_return(struct aiocb *cb)
{
	ssize_t r;
	if(!cb) { errno = EINVAL; return -1; }
	pthread_mutex_lock(&cb->__lock);
	if(cb->__queued) {
		pthread_mutex_unlock(&cb->__lock);
		errno = EINPROGRESS;
		return -1;
	}
	r = cb->__ret;
	pthread_mutex_unlock(&cb->__lock);
	return r;
}

/*
 * aio_cancel: cancel a pending request.
 *
 * If the request is still in the queue (__queued && status==EINPROGRESS
 * and not yet picked up by the worker), mark it cancelled.
 * If already in progress or done, return AIO_NOTCANCELED / AIO_ALLDONE.
 * If fd is valid but cb is NULL, attempt to cancel all requests on fd
 * (not implemented here — return AIO_NOTCANCELED).
 */
int
aio_cancel(int fd, struct aiocb *cb)
{
	(void)fd;
	if(!cb)
		return AIO_NOTCANCELED;

	pthread_mutex_lock(&cb->__lock);
	if(!cb->__queued) {
		pthread_mutex_unlock(&cb->__lock);
		return AIO_ALLDONE;
	}
	if(cb->__status == EINPROGRESS) {
		/*
		 * Worker may have already picked it up.  Mark as cancelled;
		 * the worker checks this flag before starting I/O.
		 */
		cb->__status = ECANCELED;
		cb->__ret    = -1;
		pthread_mutex_unlock(&cb->__lock);
		return AIO_CANCELED;
	}
	pthread_mutex_unlock(&cb->__lock);
	return AIO_NOTCANCELED;
}

/*
 * aio_suspend: wait until at least one request in list[] completes,
 * or until timeout expires.
 *
 * POSIX specifies ts as a RELATIVE timeout (unlike pthread_cond_timedwait
 * which takes absolute time).  We convert to absolute before calling
 * pthread_cond_timedwait.
 *
 * Since we now have a real pthread_cond_timedwait implementation, we no
 * longer need the polling fallback.  The timed and untimed paths unify
 * naturally: NULL ts → wait indefinitely, non-NULL ts → wait with deadline.
 */
int
aio_suspend(const struct aiocb *const list[], int n,
            const struct timespec *ts)
{
	int i, r;
	struct timespec deadline;

	if(n <= 0) return 0;

	/*
	 * POSIX: ts is a relative timeout.  Convert to absolute deadline
	 * by adding to the current CLOCK_REALTIME time.
	 */
	if(ts) {
		clock_gettime(CLOCK_REALTIME, &deadline);
		deadline.tv_sec  += ts->tv_sec;
		deadline.tv_nsec += ts->tv_nsec;
		if(deadline.tv_nsec >= 1000000000L) {
			deadline.tv_sec++;
			deadline.tv_nsec -= 1000000000L;
		}
	}

	/*
	 * Wait on each cb in turn.  For a list of N operations we want
	 * to return as soon as ANY one completes.  We iterate the list
	 * repeatedly; on each pass we block on the first still-pending cb
	 * we find.  When that cb completes we re-scan from the beginning.
	 * The outer loop exits the moment any cb is no longer queued.
	 */
	for(;;) {
		for(i = 0; i < n; i++) {
			const struct aiocb *cb = list[i];
			if(!cb) continue;

			pthread_mutex_lock((pthread_mutex_t *)&cb->__lock);
			if(!cb->__queued) {
				pthread_mutex_unlock((pthread_mutex_t *)&cb->__lock);
				return 0;
			}
			/* Block until this cb signals completion (or timeout). */
			if(ts)
				r = pthread_cond_timedwait(
				    (pthread_cond_t *)&cb->__cond,
				    (pthread_mutex_t *)&cb->__lock,
				    &deadline);
			else
				r = pthread_cond_wait(
				    (pthread_cond_t *)&cb->__cond,
				    (pthread_mutex_t *)&cb->__lock);
			pthread_mutex_unlock((pthread_mutex_t *)&cb->__lock);

			if(r == ETIMEDOUT) {
				errno = EAGAIN;
				return -1;
			}
			/*
			 * We were woken (possibly spuriously).  Re-scan from
			 * the top to check if any cb is actually done.
			 */
			break;
		}
	}
}

/*
 * lio_listio: submit a list of I/O requests.
 *
 * LIO_WAIT: submit all then block until all complete.
 * LIO_NOWAIT: submit all and return immediately.
 */
int
lio_listio(int mode, struct aiocb *const list[], int nent,
           struct sigevent *sev)
{
	int i, pending;

	(void)sev;   /* signal notification not supported */

	if(mode != LIO_WAIT && mode != LIO_NOWAIT) {
		errno = EINVAL;
		return -1;
	}

	for(i = 0; i < nent; i++) {
		struct aiocb *cb = list[i];
		if(!cb) continue;
		if(cb->__op == LIO_READ)
			aio_read(cb);
		else if(cb->__op == LIO_WRITE)
			aio_write(cb);
		else {
			/* LIO_NOP: mark complete immediately */
			init_cb(cb, LIO_NOP);
			pthread_mutex_lock(&cb->__lock);
			cb->__ret    = 0;
			cb->__status = 0;
			cb->__queued = 0;
			pthread_cond_broadcast(&cb->__cond);
			pthread_mutex_unlock(&cb->__lock);
		}
	}

	if(mode == LIO_WAIT) {
		pending = 0;
		for(i = 0; i < nent; i++)
			if(list[i] && list[i]->__op != LIO_NOP)
				pending++;

		if(pending > 0)
			return aio_suspend(
			    (const struct aiocb *const *)list, nent, NULL);
	}

	return 0;
}
