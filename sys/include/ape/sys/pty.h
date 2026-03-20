/*
 * Pty support
 */
#ifndef __SYS_PTY_H__
#define __SYS_PTY_H__

#pragma lib "/$M/lib/ape/libap.a"

char*	ptsname(int);
char*	ptmname(int);

int	_getpty(void);

#endif /* !__SYS_UIO_H__ */
