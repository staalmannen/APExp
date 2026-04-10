#include "stdio_impl.h"

#undef stdout

static unsigned char buf[BUFSIZ+UNGET];

hidden FILE __stdout_FILE = {
	.flags = F_PERM | F_NORD,
	.fd = 1,
	.buf = buf+UNGET,
	.buf_size = sizeof(buf)-UNGET,
	.write = __stdio_write,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
	.lbf = '\n',
	/* Explicit initialization */
	.rpos = NULL,
	.rend = NULL,
	.wpos = NULL,
	.wend = NULL,
	.wbase = NULL,
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

FILE *const stdout = &__stdout_FILE;
FILE *volatile __stdout_used = &__stdout_FILE;

