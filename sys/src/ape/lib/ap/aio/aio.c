#include <aio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------------------------------------------
   Global worker thread
   --------------------------------------------------------- */

typedef struct aio_task {
    struct aiocb *cb;
    struct aio_task *next;
} aio_task;

static pthread_mutex_t aio_q_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  aio_q_cond = PTHREAD_COND_INITIALIZER;
static aio_task *aio_q_head = NULL;
static aio_task *aio_q_tail = NULL;

static pthread_once_t aio_once = PTHREAD_ONCE_INIT;
static pthread_t aio_worker_thread;

/* ---------------------------------------------------------
   Queue handling
   --------------------------------------------------------- */

static void enqueue(struct aiocb *cb)
{
    aio_task *t = malloc(sizeof(aio_task));
    t->cb = cb;
    t->next = NULL;

    pthread_mutex_lock(&aio_q_lock);
    if (aio_q_tail)
        aio_q_tail->next = t;
    else
        aio_q_head = t;

    aio_q_tail = t;
    pthread_cond_signal(&aio_q_cond);
    pthread_mutex_unlock(&aio_q_lock);
}

static struct aiocb *dequeue(void)
{
    pthread_mutex_lock(&aio_q_lock);
    while (!aio_q_head)
        pthread_cond_wait(&aio_q_cond, &aio_q_lock);

    aio_task *t = aio_q_head;
    aio_q_head = t->next;
    if (!aio_q_head) aio_q_tail = NULL;

    pthread_mutex_unlock(&aio_q_lock);

    struct aiocb *cb = t->cb;
    free(t);
    return cb;
}

/* ---------------------------------------------------------
   Worker thread
   --------------------------------------------------------- */

static void *aio_worker(void *arg)
{
    (void)arg;
    for (;;) {
        struct aiocb *cb = dequeue();

        pthread_mutex_lock(&cb->__lock);
        cb->__status = EINPROGRESS;
        pthread_mutex_unlock(&cb->__lock);

        ssize_t ret;
        if (cb->__op == LIO_READ)
            ret = pread(cb->aio_fildes, (void *)cb->aio_buf, cb->aio_nbytes, cb->aio_offset);
        else if (cb->__op == LIO_WRITE)
            ret = pwrite(cb->aio_fildes, (void *)cb->aio_buf, cb->aio_nbytes, cb->aio_offset);
        else
            ret = -1;

        pthread_mutex_lock(&cb->__lock);
        cb->__ret = ret;
        cb->__status = (ret < 0 ? errno : 0);
        cb->__queued = 0;
        pthread_cond_broadcast(&cb->__cond);
        pthread_mutex_unlock(&cb->__lock);
    }

    return NULL;
}

/* start worker once */
static void start_worker(void)
{
    pthread_create(&aio_worker_thread, NULL, aio_worker, NULL);
}

/* ---------------------------------------------------------
   Helpers
   --------------------------------------------------------- */

static void init_cb(struct aiocb *cb)
{
    static pthread_mutex_t init_lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&init_lock);

    static int initialized = 0;
    if (!initialized) {
        pthread_once(&aio_once, start_worker);
        initialized = 1;
    }

    pthread_mutex_unlock(&init_lock);

    cb->__status = EINPROGRESS;
    cb->__ret = -1;
    cb->__queued = 1;

    pthread_mutex_init(&cb->__lock, NULL);
    pthread_cond_init(&cb->__cond, NULL);
}

/* ---------------------------------------------------------
   Public API
   --------------------------------------------------------- */

int aio_read(struct aiocb *cb)
{
    init_cb(cb);
    cb->__op = LIO_READ;
    enqueue(cb);
    return 0;
}

int aio_write(struct aiocb *cb)
{
    init_cb(cb);
    cb->__op = LIO_WRITE;
    enqueue(cb);
    return 0;
}

int aio_fsync(int op, struct aiocb *cb)
{
    (void)op;
    /* emulate fsync: just enqueue a special nop */
    init_cb(cb);
    cb->__op = LIO_NOP;
    enqueue(cb);
    return 0;
}

int aio_error(const struct aiocb *cb)
{
    return cb->__queued ? EINPROGRESS : cb->__status;
}

ssize_t aio_return(struct aiocb *cb)
{
    if (cb->__queued)
        return -1;

    return cb->__ret;
}

int aio_suspend(const struct aiocb *const list[], int n,
                const struct timespec *ts)
{
    int i;
    int done = 0;

    pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t  cv = PTHREAD_COND_INITIALIZER;

    pthread_mutex_lock(&mx);

    while (!done) {
        done = 0;

        for (i = 0; i < n; i++) {
            const struct aiocb *cb = list[i];
            if (!cb) continue;

            if (!cb->__queued) {
                done = 1;
                break;
            }
        }

        if (!done) {
            if (ts)
                pthread_cond_timedwait(&cv, &mx, ts);
            else
                pthread_cond_wait(&cv, &mx);
        }
    }

    pthread_mutex_unlock(&mx);
    return 0;
}

int lio_listio(int mode, struct aiocb *const list[],
               int nent, struct sigevent *sev)
{
    int i;

    for (i = 0; i < nent; i++) {
        struct aiocb *cb = list[i];
        if (!cb) continue;

        if (cb->__op == LIO_READ) aio_read(cb);
        else if (cb->__op == LIO_WRITE) aio_write(cb);
        else cb->__status = 0;
    }

    if (mode == LIO_WAIT) {
        const struct aiocb *clist[nent];
        for (i = 0; i < nent; i++) clist[i] = list[i];
        return aio_suspend(clist, nent, NULL);
    }

    /* LIO_NOWAIT ignores sev in this portable implementation */
    return 0;
}
