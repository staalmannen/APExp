#include "stdio_impl.h"

#undef stdin

static unsigned char buf[BUFSIZ+UNGET];

hidden FILE __stdin_FILE = {
	.flags = F_PERM | F_NOWR,
	.fd = 0,
	.buf = buf+UNGET,
	.buf_size = sizeof(buf)-UNGET,
	.read = __stdio_read,
	.seek = __stdio_seek,
	.close = __stdio_close,
	.lock = -1,
	/* These are implicitly zero from .data section, but be explicit */
	.rpos = NULL,
	.rend = NULL,
	.wpos = NULL,
	.wend = NULL,
	.wbase = NULL,
	.lbf = '\n',
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

FILE *const stdin = &__stdin_FILE;
FILE *volatile __stdin_used = &__stdin_FILE;

