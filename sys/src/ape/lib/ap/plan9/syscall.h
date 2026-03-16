/* syscall.h - musl syscall.h compatibility shim for APExp/Plan9 9front
 *
 * musl's syscall.h normally provides:
 *   - __syscall(n, ...) macro invoking Linux syscall ABI via inline asm
 *   - SYS_* constants (Linux syscall numbers)
 *   - __syscall_ret() for errno translation
 *
 * This replacement:
 *   - Defines SYS_* constants as internal tokens (not Linux numbers)
 *   - Routes __syscall() through __p9_syscall() - a pure C dispatch function
 *   - No inline asm, no Linux ABI, no arch-specific bits/syscall.h
 *   - Works on all APExp target architectures (amd64, 386, arm, arm64, etc.)
 *
 * Only syscalls actually referenced by the musl source files used in APExp
 * are defined here. Add new entries as needed when porting more musl modules.
 */

#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ */
/* SYS_* constants                                                     */
/*                                                                     */
/* These are NOT Linux syscall numbers. They are internal tokens used  */
/* only as case labels in __p9_syscall(). The values are chosen to     */
/* be well clear of any real syscall space.                            */
/* ------------------------------------------------------------------ */

/* I/O */
#define SYS_read            1001
#define SYS_write           1002
#define SYS_open            1003
#define SYS_close           1004
#define SYS_lseek           1005
#define SYS_pread64         1006
#define SYS_pwrite64        1007
#define SYS_readv           1008
#define SYS_writev          1009
#define SYS_dup             1010
#define SYS_dup2            1011
#define SYS_pipe            1012
#define SYS_pipe2           1013
#define SYS_fcntl           1014
#define SYS_ioctl           1015

/* filesystem */
#define SYS_stat            1020
#define SYS_fstat           1021
#define SYS_lstat           1022
#define SYS_access          1023
#define SYS_unlink          1024
#define SYS_rename          1025
#define SYS_mkdir           1026
#define SYS_rmdir           1027
#define SYS_chdir           1028
#define SYS_getcwd          1029
#define SYS_link            1030
#define SYS_symlink         1031
#define SYS_readlink        1032
#define SYS_chmod           1033
#define SYS_chown           1034
#define SYS_truncate        1035
#define SYS_ftruncate       1036
#define SYS_fsync           1037
#define SYS_getdents        1038
#define SYS_getdents64      1039

/* memory */
#define SYS_brk             1040
#define SYS_mmap            1041
#define SYS_munmap          1042
#define SYS_mremap          1043
#define SYS_mprotect        1044
#define SYS_madvise         1045
#define SYS_mlock           1046
#define SYS_munlock         1047

/* process */
#define SYS_fork            1050
#define SYS_vfork           1051
#define SYS_execve          1052
#define SYS_exit            1053
#define SYS_exit_group      1054
#define SYS_wait4           1055
#define SYS_waitpid         1056
#define SYS_getpid          1057
#define SYS_getppid         1058
#define SYS_getpgrp         1059
#define SYS_setpgid         1060
#define SYS_setsid          1061
#define SYS_getsid          1062

/* credentials */
#define SYS_getuid          1070
#define SYS_getgid          1071
#define SYS_geteuid         1072
#define SYS_getegid         1073
#define SYS_setuid          1074
#define SYS_setgid          1075

/* signals */
#define SYS_kill            1080
#define SYS_rt_sigaction    1081
#define SYS_rt_sigprocmask  1082
#define SYS_rt_sigpending   1083
#define SYS_rt_sigsuspend   1084
#define SYS_sigaltstack     1085
#define SYS_alarm           1086
#define SYS_pause           1087

/* time */
#define SYS_clock_gettime   1090
#define SYS_clock_getres    1091
#define SYS_clock_settime   1092
#define SYS_gettimeofday    1093
#define SYS_settimeofday    1094
#define SYS_nanosleep       1095
#define SYS_times           1096
#define SYS_time            1097

/* misc */
#define SYS_uname           1100
#define SYS_sysinfo         1101
#define SYS_getrlimit       1102
#define SYS_setrlimit       1103
#define SYS_getrusage       1104
#define SYS_umask           1105
#define SYS_poll            1106
#define SYS_select          1107

/* socket (Plan9 network via _sock helpers) */
#define SYS_socket          1110
#define SYS_bind            1111
#define SYS_connect         1112
#define SYS_listen          1113
#define SYS_accept          1114
#define SYS_accept4         1115
#define SYS_getsockname     1116
#define SYS_getpeername     1117
#define SYS_getsockopt      1118
#define SYS_setsockopt      1119
#define SYS_send            1120
#define SYS_sendto          1121
#define SYS_recv            1122
#define SYS_recvfrom        1123
#define SYS_shutdown        1124
#define SYS_socketpair      1125
#define SYS_sendmsg         1126
#define SYS_recvmsg         1127

/* ------------------------------------------------------------------ */
/* __syscall_ret: translate negative-errno returns to errno+(-1)       */
/* Matches musl's convention: negative return = -errno                 */
/* ------------------------------------------------------------------ */
static inline long __syscall_ret(unsigned long r)
{
	if(r > (unsigned long)-4096UL){
		errno = -(int)r;
		return -1L;
	}
	return (long)r;
}

/* ------------------------------------------------------------------ */
/* __p9_syscall: pure C dispatch, implemented in syscall/__p9_syscall.c */
/* ------------------------------------------------------------------ */
extern long __p9_syscall(long n, long a1, long a2, long a3,
                         long a4, long a5, long a6);

/* ------------------------------------------------------------------ */
/* __syscall variadic macro                                            */
/*                                                                     */
/* Pads missing arguments with 0 so __p9_syscall always gets 6 args.  */
/* The ## before __VA_ARGS__ suppresses the comma when args is empty.  */
/* ------------------------------------------------------------------ */
#define __syscall(n, ...) \
	__p9_syscall((long)(n), ##__VA_ARGS__, 0L, 0L, 0L, 0L, 0L, 0L)

#define syscall(n, ...) \
	__syscall_ret((unsigned long)__syscall((n), ##__VA_ARGS__))

/* ------------------------------------------------------------------ */
/* Convenience typed wrappers used by some musl internals              */
/* ------------------------------------------------------------------ */
#define __syscall1(n,a)         __p9_syscall((long)(n),(long)(a),0,0,0,0,0)
#define __syscall2(n,a,b)       __p9_syscall((long)(n),(long)(a),(long)(b),0,0,0,0)
#define __syscall3(n,a,b,c)     __p9_syscall((long)(n),(long)(a),(long)(b),(long)(c),0,0,0)
#define __syscall4(n,a,b,c,d)   __p9_syscall((long)(n),(long)(a),(long)(b),(long)(c),(long)(d),0,0)
#define __syscall5(n,a,b,c,d,e) __p9_syscall((long)(n),(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),0)
#define __syscall6(n,a,b,c,d,e,f) __p9_syscall((long)(n),(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f))

#ifdef __cplusplus
}
#endif

#endif /* _SYSCALL_H */
