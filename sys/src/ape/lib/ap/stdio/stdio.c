#include "stdio_impl.h"
#include <pthread.h>
#include <sys/ioctl.h>
#include <unistd.h>

static struct _IO_FILE stdin_file = {
	.fd = 0,
	.flags = 0,
	.rpos = NULL, .rend = NULL,
	.wpos = NULL, .wend = NULL, .wbase = NULL,
	.buf = NULL, .buf_size = BUFSIZ,
	.read = __stdio_read,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.lbf = EOF,
};

static struct _IO_FILE stdout_file = {
	.fd = 1,
	.flags = 0,
	.rpos = NULL, .rend = NULL,
	.wpos = NULL, .wend = NULL, .wbase = NULL,
	.buf = NULL, .buf_size = BUFSIZ,
	.read = __stdio_read,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.lbf = '\n',
};

static struct _IO_FILE stderr_file = {
	.fd = 2,
	.flags = F_NOWR,
	.rpos = NULL, .rend = NULL,
	.wpos = NULL, .wend = NULL, .wbase = NULL,
	.buf = NULL, .buf_size = BUFSIZ,
	.read = __stdio_read,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = PTHREAD_MUTEX_INITIALIZER,
	.lbf = EOF,
};




FILE *const stdin = &stdin_file;
FILE *const stdout = &stdout_file;
FILE *const stderr = &stderr_file;
