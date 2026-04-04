#ifndef PORTABLE_AIO_H
#define PORTABLE_AIO_H

#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#define AIO_CANCELED   0
#define AIO_NOTCANCELED 1
#define AIO_ALLDONE     2

#define LIO_READ        0
#define LIO_WRITE       1
#define LIO_NOP         2

#define LIO_WAIT        0
#define LIO_NOWAIT      1

typedef struct aiocb {
    int aio_fildes;
    off_t aio_offset;
    volatile void *aio_buf;
    size_t aio_nbytes;
    int aio_reqprio;
    struct sigevent aio_sigevent;

    /* internal fields */
    pthread_mutex_t __lock;
    pthread_cond_t  __cond;
    int __status;
    ssize_t __ret;
    int __op;
    int __queued;
} aiocb;

int aio_read(struct aiocb *);
int aio_write(struct aiocb *);
int aio_fsync(int op, struct aiocb *);
int aio_error(const struct aiocb *);
ssize_t aio_return(struct aiocb *);
int aio_suspend(const struct aiocb *const [], int, const struct timespec *);
int lio_listio(int mode, struct aiocb *const [], int, struct sigevent *);

#endif
