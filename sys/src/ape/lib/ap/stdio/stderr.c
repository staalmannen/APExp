#include "stdio_impl.h"

#undef stderr

static unsigned char buf[UNGET];

hidden FILE __stderr_FILE = {
	.flags = F_PERM | F_NORD,
	.fd = 2,
	.buf = buf+UNGET,
	.buf_size = 0,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
	.lbf = -1,
	/* Explicit initialization */
	.rpos = NULL,
	.rend = NULL,
	.wpos = buf+UNGET,
	.wend = buf+UNGET,
	.wbase = buf+UNGET,
	.prev = NULL,
	.next = NULL,
	.prev_locked = NULL,
	.next_locked = NULL,
	.locale = NULL,
	.pipe_pid = 0,
	.lockcount = 0,
	.mode = 0,
	.cookie = NULL,
	.off = 0,
	.getln_buf = NULL,
	.mustbezero_1 = NULL,
	.mustbezero_2 = NULL,
	.shend = NULL,
	.shlim = 0,
	.shcnt = 0,
};

FILE *const stderr = &__stderr_FILE;
FILE *volatile __stderr_used = &__stderr_FILE;

