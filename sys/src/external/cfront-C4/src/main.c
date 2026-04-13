# 1 ""

/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

# 1 ""
void *__vec_new (void *, int , int , void *);

# 1 ""
void __vec_delete (void *, int , int , void *, int , int );
typedef int (*__vptp)(void);
struct __mptr {short d; short i; __vptp f; };

# 1 ""
extern struct __mptr* __ptbl_vec___[];

# 1 ""

# 18 "/home/claude/incl-linux32/stddef.h"
typedef long ssize_t ;
typedef unsigned long size_t ;
struct exception;

# 31 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned char __u_char ;
typedef unsigned short __u_short ;
typedef unsigned int __u_int ;
typedef unsigned long __u_long ;

# 37 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef char __int8_t ;
typedef unsigned char __uint8_t ;
typedef short __int16_t ;
typedef unsigned short __uint16_t ;
typedef int __int32_t ;
typedef unsigned int __uint32_t ;

# 44 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __int64_t ;
typedef unsigned long __uint64_t ;

# 52 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef __int8_t __int_least8_t ;
typedef __uint8_t __uint_least8_t ;
typedef __int16_t __int_least16_t ;
typedef __uint16_t __uint_least16_t ;
typedef __int32_t __int_least32_t ;
typedef __uint32_t __uint_least32_t ;
typedef __int64_t __int_least64_t ;
typedef __uint64_t __uint_least64_t ;

# 63 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __quad_t ;
typedef unsigned long __u_quad_t ;

# 72 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __intmax_t ;
typedef unsigned long __uintmax_t ;

# 145 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __dev_t ;
typedef unsigned int __uid_t ;
typedef unsigned int __gid_t ;
typedef unsigned long __ino_t ;
typedef unsigned long __ino64_t ;
typedef unsigned int __mode_t ;
typedef unsigned long __nlink_t ;
typedef long __off_t ;
typedef long __off64_t ;
typedef int __pid_t ;
struct __C1;
typedef struct __fsid_t __fsid_t ;
typedef long __clock_t ;
typedef unsigned long __rlim_t ;
typedef unsigned long __rlim64_t ;
typedef unsigned int __id_t ;
typedef long __time_t ;
typedef unsigned int __useconds_t ;
typedef long __suseconds_t ;
typedef long __suseconds64_t ;

# 165 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __daddr_t ;
typedef int __key_t ;

# 169 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __clockid_t ;

# 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef void *__timer_t ;

# 175 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blksize_t ;

# 180 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __blkcnt_t ;
typedef long __blkcnt64_t ;

# 184 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __fsblkcnt_t ;
typedef unsigned long __fsblkcnt64_t ;

# 188 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __fsfilcnt_t ;
typedef unsigned long __fsfilcnt64_t ;

# 192 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __fsword_t ;

# 194 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t ;

# 197 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __syscall_slong_t ;

# 199 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned long __syscall_ulong_t ;

# 203 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef __off64_t __loff_t ;
typedef char *__caddr_t ;

# 207 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __intptr_t ;

# 210 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef unsigned int __socklen_t ;

# 215 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef int __sig_atomic_t ;

# 33 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __u_char u_char ;
typedef __u_short u_short ;
typedef __u_int u_int ;
typedef __u_long u_long ;
typedef __quad_t quad_t ;
typedef __u_quad_t u_quad_t ;
typedef struct __fsid_t fsid_t ;

# 42 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __loff_t loff_t ;

# 47 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __ino_t ino_t ;

# 54 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __ino64_t ino64_t ;

# 59 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __dev_t dev_t ;

# 64 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __gid_t gid_t ;

# 69 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __mode_t mode_t ;

# 74 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __nlink_t nlink_t ;

# 79 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __uid_t uid_t ;

# 85 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __off_t off_t ;

# 92 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __off64_t off64_t ;

# 97 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __pid_t pid_t ;

# 103 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __id_t id_t ;

# 114 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __daddr_t daddr_t ;
typedef __caddr_t caddr_t ;

# 121 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __key_t key_t ;

# 7 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h"
typedef __clock_t clock_t ;

# 7 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h"
typedef __clockid_t clockid_t ;

# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h"
typedef __time_t time_t ;

# 7 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h"
typedef __timer_t timer_t ;

# 134 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __useconds_t useconds_t ;

# 138 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __suseconds_t suseconds_t ;

# 148 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef unsigned long ulong ;
typedef unsigned short ushort ;
typedef unsigned int uint ;

# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h"
typedef __int8_t int8_t ;
typedef __int16_t int16_t ;
typedef __int32_t int32_t ;
typedef __int64_t int64_t ;

# 158 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __uint8_t u_int8_t ;
typedef __uint16_t u_int16_t ;
typedef __uint32_t u_int32_t ;
typedef __uint64_t u_int64_t ;

# 166 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef int register_t ;
struct __C2;

# 8 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h"
typedef struct __sigset_t __sigset_t ;

# 7 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h"
typedef struct __sigset_t sigset_t ;
struct timeval;
struct timespec;

# 49 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef long __fd_mask ;
struct __C3;

# 70 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef struct fd_set fd_set ;

# 77 "/usr/include/x86_64-linux-gnu/sys/select.h"
typedef __fd_mask fd_mask ;

# 185 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __blksize_t blksize_t ;

# 192 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __blkcnt_t blkcnt_t ;

# 196 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __fsblkcnt_t fsblkcnt_t ;

# 200 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __fsfilcnt_t fsfilcnt_t ;

# 219 "/usr/include/x86_64-linux-gnu/sys/types.h"
typedef __blkcnt64_t blkcnt64_t ;
typedef __fsblkcnt64_t fsblkcnt64_t ;
typedef __fsfilcnt64_t fsfilcnt64_t ;
union __C4;
struct __Q2_4__C44__C1;

# 29 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
struct  __Q2_4__C44__C1 {	/* sizeof __Q2_4__C44__C1 == 8 */
unsigned int __low ;
unsigned int __high ;
};
typedef union __atomic_wide_counter __atomic_wide_counter ;
struct __pthread_internal_list;

# 55 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef struct __pthread_internal_list __pthread_list_t ;
struct __pthread_internal_slist;

# 60 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef struct __pthread_internal_slist __pthread_slist_t ;
struct __pthread_mutex_s;

# 52 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
struct __pthread_internal_list {	/* sizeof __pthread_internal_list == 16 */
struct __pthread_internal_list *__prev__23__pthread_internal_list ;
struct __pthread_internal_list *__next__23__pthread_internal_list ;
};
struct __pthread_rwlock_arch_t;
struct __pthread_cond_s;

# 33 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
union __atomic_wide_counter {	/* sizeof __atomic_wide_counter == 8 */

# 27 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
unsigned long long __value64__21__atomic_wide_counter ;

# 32 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
struct  __Q2_4__C44__C1 __value32__21__atomic_wide_counter ;
};

# 105 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef unsigned int __tss_t ;
typedef unsigned long __thrd_t ;
struct __C5;

# 111 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
typedef struct __once_flag __once_flag ;

# 27 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef unsigned long pthread_t ;
union __C6;

# 36 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_mutexattr_t pthread_mutexattr_t ;
union __C7;

# 45 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_condattr_t pthread_condattr_t ;

# 49 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef unsigned int pthread_key_t ;

# 53 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef int pthread_once_t ;
union pthread_attr_t;

# 62 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_attr_t pthread_attr_t ;
union __C8;

# 23 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
struct __pthread_mutex_s {	/* sizeof __pthread_mutex_s == 40 */
int __lock__17__pthread_mutex_s ;
unsigned int __count__17__pthread_mutex_s ;
int __owner__17__pthread_mutex_s ;

# 28 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
unsigned int __nusers__17__pthread_mutex_s ;

# 32 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
int __kind__17__pthread_mutex_s ;

# 34 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
short __spins__17__pthread_mutex_s ;
short __elision__17__pthread_mutex_s ;
struct __pthread_internal_list __list__17__pthread_mutex_s ;
};

# 72 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_mutex_t pthread_mutex_t ;
union __C9;

# 95 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
struct __pthread_cond_s {	/* sizeof __pthread_cond_s == 48 */
union __atomic_wide_counter __wseq__16__pthread_cond_s ;
union __atomic_wide_counter __g1_start__16__pthread_cond_s ;
unsigned int __g_refs__16__pthread_cond_s [2];
unsigned int __g_size__16__pthread_cond_s [2];
unsigned int __g1_orig_size__16__pthread_cond_s ;
unsigned int __wrefs__16__pthread_cond_s ;
unsigned int __g_signals__16__pthread_cond_s [2];
};

# 80 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_cond_t pthread_cond_t ;
union __C10;

# 24 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
struct __pthread_rwlock_arch_t {	/* sizeof __pthread_rwlock_arch_t == 56 */
unsigned int __readers__23__pthread_rwlock_arch_t ;
unsigned int __writers__23__pthread_rwlock_arch_t ;
unsigned int __wrphase_futex__23__pthread_rwlock_arch_t ;
unsigned int __writers_futex__23__pthread_rwlock_arch_t ;
unsigned int __pad3__23__pthread_rwlock_arch_t ;
unsigned int __pad4__23__pthread_rwlock_arch_t ;

# 32 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
int __cur_writer__23__pthread_rwlock_arch_t ;
int __shared__23__pthread_rwlock_arch_t ;
char __rwelision__23__pthread_rwlock_arch_t ;

# 39 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
unsigned char __pad1__23__pthread_rwlock_arch_t [7];

# 42 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
unsigned long __pad2__23__pthread_rwlock_arch_t ;

# 45 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h"
unsigned int __flags__23__pthread_rwlock_arch_t ;
};

# 91 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_rwlock_t pthread_rwlock_t ;
union __C11;

# 97 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_rwlockattr_t pthread_rwlockattr_t ;

# 103 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef int pthread_spinlock_t ;
union __C12;

# 112 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_barrier_t pthread_barrier_t ;
union __C13;

# 118 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
typedef union pthread_barrierattr_t pthread_barrierattr_t ;
struct flock;

# 14 "/home/claude/incl-linux32/stdio.h"
typedef char *va_list ;

# 125 "/home/claude/incl-linux32/stdio.h"
extern char *sys_errlist [];
extern int sys_nerr ;
extern unsigned char *_bufendtab [];
struct group;
struct passwd;
struct comment;

# 8 "/usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h"
typedef __sig_atomic_t sig_atomic_t ;
union sigval;

# 30 "/usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h"
typedef union sigval __sigval_t ;
struct __C14;
union __Q2_5__C144__C1;
struct __Q3_5__C144__C14__C1;
struct __Q3_5__C144__C14__C2;
struct __Q3_5__C144__C14__C3;
struct __Q3_5__C144__C14__C4;
struct __Q3_5__C144__C14__C5;
union __Q4_5__C144__C14__C54__C1;
struct __Q5_5__C144__C14__C54__C14__C1;
struct __Q3_5__C144__C14__C6;
struct __Q3_5__C144__C14__C7;

# 52 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C1 {	/* sizeof __Q3_5__C144__C14__C1 == 8 */

# 58 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
__pid_t si_pid ;
__uid_t si_uid ;
};

# 25 "/usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h"
union sigval {	/* sizeof sigval == 8 */
int sival_int__6sigval ;
void *sival_ptr__6sigval ;
};

# 64 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C2 {	/* sizeof __Q3_5__C144__C14__C2 == 16 */
int si_tid ;
int si_overrun ;
union sigval si_sigval ;
};

# 72 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C3 {	/* sizeof __Q3_5__C144__C14__C3 == 16 */
__pid_t si_pid ;
__uid_t si_uid ;
union sigval si_sigval ;
};

# 80 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C4 {	/* sizeof __Q3_5__C144__C14__C4 == 32 */
__pid_t si_pid ;
__uid_t si_uid ;
int si_status ;
__clock_t si_utime ;
__clock_t si_stime ;
};

# 95 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q5_5__C144__C14__C54__C14__C1 {	/* sizeof __Q5_5__C144__C14__C54__C14__C1 == 16 */

# 99 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
void *_lower ;
void *_upper ;
};

# 95 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
union  __Q4_5__C144__C14__C54__C1 {	/* sizeof __Q4_5__C144__C14__C54__C1 == 16 */

# 101 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q5_5__C144__C14__C54__C14__C1 _addr_bnd ;

# 103 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
__uint32_t _pkey ;
};

# 90 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C5 {	/* sizeof __Q3_5__C144__C14__C5 == 32 */
void *si_addr ;

# 93 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
short si_addr_lsb ;

# 104 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
union  __Q4_5__C144__C14__C54__C1 _bounds ;
};

# 109 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C6 {	/* sizeof __Q3_5__C144__C14__C6 == 16 */
long si_band ;
int si_fd ;
};

# 117 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C7 {	/* sizeof __Q3_5__C144__C14__C7 == 16 */
void *_call_addr ;
int _syscall ;
unsigned int _arch ;
};

# 52 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
union  __Q2_5__C144__C1 {	/* sizeof __Q2_5__C144__C1 == 112 */
int _pad [28];

# 60 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C1 _kill ;

# 68 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C2 _timer ;

# 76 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C3 _rt ;

# 86 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C4 _sigchld ;

# 105 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C5 _sigfault ;

# 112 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C6 _sigpoll ;

# 121 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
struct  __Q3_5__C144__C14__C7 _sigsys ;
};

# 124 "/usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h"
typedef struct siginfo_t siginfo_t ;
enum __E1 { SI_ASYNCNL = -60, SI_DETHREAD = -7, SI_TKILL = -6, SI_SIGIO = -5, SI_ASYNCIO = -4, SI_MESGQ = -3, SI_TIMER = -2, SI_QUEUE = -1, SI_USER = 0, SI_KERNEL = 128} ;
enum __E2 { ILL_ILLOPC = 1, ILL_ILLOPN = 2, ILL_ILLADR = 3, ILL_ILLTRP = 4, ILL_PRVOPC = 5, ILL_PRVREG = 6, ILL_COPROC = 7, ILL_BADSTK = 8, ILL_BADIADDR = 9} ;
enum __E3 { FPE_INTDIV = 1, FPE_INTOVF = 2, FPE_FLTDIV = 3, FPE_FLTOVF = 4, FPE_FLTUND = 5, FPE_FLTRES = 6, FPE_FLTINV = 7, FPE_FLTSUB = 8, FPE_FLTUNK = 14, FPE_CONDTRAP = 15} ;
enum __E4 { SEGV_MAPERR = 1, SEGV_ACCERR = 2, SEGV_BNDERR = 3, SEGV_PKUERR = 4, SEGV_ACCADI = 5, SEGV_ADIDERR = 6, SEGV_ADIPERR = 7, SEGV_MTEAERR = 8, SEGV_MTESERR = 9, SEGV_CPERR = 10} ;
enum __E5 { BUS_ADRALN = 1, BUS_ADRERR = 2, BUS_OBJERR = 3, BUS_MCEERR_AR = 4, BUS_MCEERR_AO = 5} ;
enum __E6 { TRAP_BRKPT = 1, TRAP_TRACE = 2, TRAP_BRANCH = 3, TRAP_HWBKPT = 4, TRAP_UNK = 5} ;
enum __E7 { CLD_EXITED = 1, CLD_KILLED = 2, CLD_DUMPED = 3, CLD_TRAPPED = 4, CLD_STOPPED = 5, CLD_CONTINUED = 6} ;
enum __E8 { POLL_IN = 1, POLL_OUT = 2, POLL_MSG = 3, POLL_ERR = 4, POLL_PRI = 5, POLL_HUP = 6} ;

# 16 "/usr/include/x86_64-linux-gnu/bits/types/sigval_t.h"
typedef union sigval sigval_t ;
struct sigevent;
union __Q2_8sigevent4__C1;
struct __Q3_8sigevent4__C14__C1;

# 29 "/usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h"
struct  __Q3_8sigevent4__C14__C1 {	/* sizeof __Q3_8sigevent4__C14__C1 == 16 */

# 38 "/usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h"
void (*_function )(union sigval );
union pthread_attr_t *_attribute ;
};

# 29 "/usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h"
union  __Q2_8sigevent4__C1 {	/* sizeof __Q2_8sigevent4__C1 == 48 */
int _pad [12];

# 34 "/usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h"
__pid_t _tid ;

# 40 "/usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h"
struct  __Q3_8sigevent4__C14__C1 _sigev_thread ;
};
typedef struct sigevent sigevent_t ;
enum __E9 { SIGEV_SIGNAL = 0, SIGEV_NONE = 1, SIGEV_THREAD = 2, SIGEV_THREAD_ID = 4} ;

# 72 "/usr/include/signal.h"
typedef void (*__sighandler_t )(int );

# 188 "/usr/include/signal.h"
typedef __sighandler_t sighandler_t ;

# 193 "/usr/include/signal.h"
typedef __sighandler_t sig_t ;
struct sigaction;
union __Q2_9sigaction4__C1;

# 32 "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
union  __Q2_9sigaction4__C1 {	/* sizeof __Q2_9sigaction4__C1 == 8 */

# 34 "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
__sighandler_t sa_handler ;

# 36 "/usr/include/x86_64-linux-gnu/bits/sigaction.h"
void (*sa_sigaction )(int , struct siginfo_t *, void *);
};

# 8 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h"
struct __sigset_t {	/* sizeof __sigset_t == 128 */

# 7 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h"
unsigned long __val__10__sigset_t [16];
};
struct _fpx_sw_bytes;
struct _fpreg;
struct _fpxreg;
struct _xmmreg;
struct _fpstate;

# 47 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
struct _fpxreg {	/* sizeof _fpxreg == 16 */
unsigned short significand__7_fpxreg [4];
unsigned short exponent__7_fpxreg ;
unsigned short __glibc_reserved1__7_fpxreg [3];
};

# 54 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
struct _xmmreg {	/* sizeof _xmmreg == 16 */
__uint32_t element__7_xmmreg [4];
};
struct sigcontext;
union __Q2_10sigcontext4__C1;

# 168 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
union  __Q2_10sigcontext4__C1 {	/* sizeof __Q2_10sigcontext4__C1 == 8 */
struct _fpstate *fpstate ;
__uint64_t __fpstate_word ;
};
struct _xsave_hdr;
struct _ymmh_state;
struct _xstate;

# 124 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
struct _fpstate {	/* sizeof _fpstate == 512 */

# 126 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
__uint16_t cwd__8_fpstate ;
__uint16_t swd__8_fpstate ;
__uint16_t ftw__8_fpstate ;
__uint16_t fop__8_fpstate ;
__uint64_t rip__8_fpstate ;
__uint64_t rdp__8_fpstate ;
__uint32_t mxcsr__8_fpstate ;
__uint32_t mxcr_mask__8_fpstate ;
struct _fpxreg _st__8_fpstate [8];
struct _xmmreg _xmm__8_fpstate [16];
__uint32_t __glibc_reserved1__8_fpstate [24];
};

# 178 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
struct _xsave_hdr {	/* sizeof _xsave_hdr == 64 */
__uint64_t xstate_bv__10_xsave_hdr ;
__uint64_t __glibc_reserved1__10_xsave_hdr [2];
__uint64_t __glibc_reserved2__10_xsave_hdr [5];
};

# 185 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h"
struct _ymmh_state {	/* sizeof _ymmh_state == 256 */
__uint32_t ymmh_space__11_ymmh_state [64];
};
struct __C15;

# 31 "/usr/include/x86_64-linux-gnu/bits/types/stack_t.h"
typedef struct stack_t stack_t ;

# 37 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
typedef long long greg_t ;

# 46 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
typedef greg_t gregset_t [23];
enum __E10 { REG_R8 = 0, REG_R9 = 1, REG_R10 = 2, REG_R11 = 3, REG_R12 = 4, REG_R13 = 5, REG_R14 = 6, REG_R15 = 7, REG_RDI = 8, REG_RSI = 9, REG_RBP = 10, REG_RBX = 11, REG_RDX = 12, REG_RAX = 13,
# 47 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
REG_RCX = 14, REG_RSP = 15, REG_RIP = 16, REG_EFL = 17, REG_CSGSFS = 18, REG_ERR = 19, REG_TRAPNO = 20, REG_OLDMASK = 21, REG_CR2 = 22} ;
struct _libc_fpxreg;
struct _libc_xmmreg;
struct _libc_fpstate;

# 102 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
struct _libc_fpxreg {	/* sizeof _libc_fpxreg == 16 */
unsigned short significand__12_libc_fpxreg [4];
unsigned short exponent__12_libc_fpxreg ;
unsigned short __glibc_reserved1__12_libc_fpxreg [3];
};

# 109 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
struct _libc_xmmreg {	/* sizeof _libc_xmmreg == 16 */
__uint32_t element__12_libc_xmmreg [4];
};

# 130 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
typedef struct _libc_fpstate *fpregset_t ;
struct __C16;

# 139 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
typedef struct mcontext_t mcontext_t ;
struct ucontext_t;

# 31 "/usr/include/x86_64-linux-gnu/bits/types/stack_t.h"
struct stack_t {	/* sizeof stack_t == 24 */

# 28 "/usr/include/x86_64-linux-gnu/bits/types/stack_t.h"
void *ss_sp__7stack_t ;
int ss_flags__7stack_t ;
size_t ss_size__7stack_t ;
};

# 139 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
struct mcontext_t {	/* sizeof mcontext_t == 256 */

# 135 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
gregset_t gregs__10mcontext_t ;

# 137 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
fpregset_t fpregs__10mcontext_t ;
unsigned long long __reserved1__10mcontext_t [8];
};

# 114 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
struct _libc_fpstate {	/* sizeof _libc_fpstate == 512 */

# 116 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
__uint16_t cwd__13_libc_fpstate ;
__uint16_t swd__13_libc_fpstate ;
__uint16_t ftw__13_libc_fpstate ;
__uint16_t fop__13_libc_fpstate ;
__uint64_t rip__13_libc_fpstate ;
__uint64_t rdp__13_libc_fpstate ;
__uint32_t mxcsr__13_libc_fpstate ;
__uint32_t mxcr_mask__13_libc_fpstate ;
struct _libc_fpxreg _st__13_libc_fpstate [8];
struct _libc_xmmreg _xmm__13_libc_fpstate [16];
__uint32_t __glibc_reserved1__13_libc_fpstate [24];
};

# 151 "/usr/include/x86_64-linux-gnu/sys/ucontext.h"
typedef struct ucontext_t ucontext_t ;
enum __E11 { SS_ONSTACK = 1, SS_DISABLE = 2} ;
struct sigstack;
enum idtype_t { P_ALL = 0, P_PID = 1, P_PGID = 2, P_PIDFD = 3} ;

# 12 "/usr/include/x86_64-linux-gnu/bits/types/idtype_t.h"
typedef int idtype_t ;
struct rusage;

# 23 "/home/claude/cfront-3/src/size.h"
extern int BI_IN_WORD ;
extern int BI_IN_BYTE ;

# 26 "/home/claude/cfront-3/src/size.h"
extern int SZ_CHAR ;
extern int AL_CHAR ;

# 29 "/home/claude/cfront-3/src/size.h"
extern int SZ_SHORT ;
extern int AL_SHORT ;

# 32 "/home/claude/cfront-3/src/size.h"
extern int SZ_INT ;
extern int AL_INT ;

# 35 "/home/claude/cfront-3/src/size.h"
extern int SZ_LONG ;
extern int AL_LONG ;

# 38 "/home/claude/cfront-3/src/size.h"
extern int SZ_LLONG ;
extern int AL_LLONG ;

# 41 "/home/claude/cfront-3/src/size.h"
extern int SZ_FLOAT ;
extern int AL_FLOAT ;

# 44 "/home/claude/cfront-3/src/size.h"
extern int SZ_DOUBLE ;
extern int AL_DOUBLE ;

# 47 "/home/claude/cfront-3/src/size.h"
extern int SZ_LDOUBLE ;
extern int AL_LDOUBLE ;

# 50 "/home/claude/cfront-3/src/size.h"
extern int SZ_STRUCT ;
extern int AL_STRUCT ;

# 56 "/home/claude/cfront-3/src/size.h"
extern int SZ_WORD ;

# 58 "/home/claude/cfront-3/src/size.h"
extern int SZ_WPTR ;
extern int AL_WPTR ;

# 61 "/home/claude/cfront-3/src/size.h"
extern int SZ_BPTR ;
extern int AL_BPTR ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_INT ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_LONG ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_LLONG ;
extern int F_SENSITIVE ;
extern int F_OPTIMIZED ;

# 82 "/home/claude/cfront-3/src/size.h"

# 125 "/home/claude/incl-linux32/stdio.h"
extern char *sys_errlist [];
extern int sys_nerr ;
extern unsigned char *_bufendtab [];

# 61 "/home/claude/cfront-3/src/token.h"
extern const char *keys [256];

# 19 "/home/claude/cfront-3/src/typedef.h"
typedef unsigned char TOK ;
typedef unsigned char bit ;
struct node;
typedef struct node *PP ;
typedef int (*PFI )(void );
typedef void (*PFV )(void );
typedef struct node *Pnode ;
struct key;
typedef struct key *Pkey ;
struct name;
typedef struct name *Pname ;
struct basetype;
typedef struct basetype *Pbase ;
struct basecl;
typedef struct basecl *Pbcl ;
struct type;
typedef struct type *Ptype ;
struct fct;
typedef struct fct *Pfct ;
struct field;
typedef struct field *Pfield ;
struct expr;
typedef struct expr *Pexpr ;
struct qexpr;
typedef struct qexpr *Pqexpr ;
struct texpr;
typedef struct texpr *Ptexpr ;
struct classdef;
typedef struct classdef *Pclass ;
struct enumdef;
typedef struct enumdef *Penum ;
struct stmt;
typedef struct stmt *Pstmt ;
struct estmt;
typedef struct estmt *Pestmt ;
struct tstmt;
typedef struct tstmt *Ptstmt ;
struct vec;
typedef struct vec *Pvec ;
struct ptr;
typedef struct ptr *Pptr ;
struct block;
typedef struct block *Pblock ;
struct table;
typedef struct table *Ptable ;
struct ktable;
typedef struct ktable *Pktab ;
struct loc;
typedef struct loc Loc ;
struct call;
typedef struct call *Pcall ;
struct gen;
typedef struct gen *Pgen ;
struct ref;
typedef struct ref *Pref ;
struct name_list;
typedef struct name_list *Plist ;
struct iline;
typedef struct iline *Pin ;
struct ia;
typedef struct ia *Pia ;
struct nlist;
typedef struct nlist *Pnlist ;
struct slist;
typedef struct slist *Pslist ;
struct elist;
typedef struct elist *Pelist ;
struct virt;
typedef struct virt *Pvirt ;
typedef char *Pchar ;
typedef const char *CPchar ;

# 26 "/home/claude/cfront-3/src/cfront.h"
extern const char *prog_name ;
extern int inline_restr ;

# 40 "/home/claude/cfront-3/src/cfront.h"
extern Pname dummy_fct ;

# 50 "/home/claude/cfront-3/src/cfront.h"
struct loc {	/* sizeof loc == 4 */
short file__3loc ;
short line__3loc ;
};

# 59 "/home/claude/cfront-3/src/cfront.h"
extern struct loc curloc ;
extern int curr_file ;

# 62 "/home/claude/cfront-3/src/cfront.h"
extern const char *src_file_name ;
extern struct loc noloc ;
extern bit binary_val ;
extern bit stmtno ;
extern Ptable tmp_tbl ;
extern Ptable bound_expr_tbl ;
struct ea;
union __Q2_2ea4__C1;

# 70 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_2ea4__C1 {	/* sizeof __Q2_2ea4__C1 == 8 */
const void *p ;
size_t i ;
};

# 69 "/home/claude/cfront-3/src/cfront.h"
struct ea {	/* sizeof ea == 8 */

# 73 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_2ea4__C1 __O1__2ea ;
};

# 1 ""
extern void *__nw__FUl (unsigned long );

# 80 "/home/claude/cfront-3/src/cfront.h"
extern struct ea *ea0 ;

# 88 "/home/claude/cfront-3/src/cfront.h"
extern char emode ;

# 90 "/home/claude/cfront-3/src/cfront.h"
extern int error_count ;
extern int vtbl_opt ;
extern int debug_opt ;
extern int warning_opt ;
extern int ansi_opt ;
extern int pt_opt ;
extern int perf_opt ;
extern int dtpt_opt ;
extern int se_opt ;
extern int strict_opt ;
extern void *out_file ;
extern void *in_file ;
extern void *pt_file ;
extern void *dtpt_file ;
extern char scan_started ;

# 106 "/home/claude/cfront-3/src/cfront.h"
extern int bl_level ;

# 109 "/home/claude/cfront-3/src/cfront.h"
extern Pktab Gtbl ;
extern Pktab Ctbl ;

# 118 "/home/claude/cfront-3/src/cfront.h"
extern Ptable gtbl ;
extern Ptable ptbl ;

# 123 "/home/claude/cfront-3/src/cfront.h"
extern Pname def_name ;
extern Pname pdef_name ;
extern Pclass ccl ;
extern Pbase defa_type ;
extern Pbase moe_type ;
extern Pbase mptr_type ;

# 131 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt Cstmt ;
extern Pname Cdcl ;

# 134 "/home/claude/cfront-3/src/cfront.h"
extern int largest_int ;

# 137 "/home/claude/cfront-3/src/cfront.h"
extern Pbase any_type ;
extern Pbase int_type ;
extern Pbase char_type ;
extern Pbase short_type ;
extern Pbase long_type ;
extern Pbase llong_type ;
extern Pbase uint_type ;
extern Pbase float_type ;
extern Pbase double_type ;
extern Pbase ldouble_type ;
extern Pbase void_type ;

# 150 "/home/claude/cfront-3/src/cfront.h"
extern Pbase uchar_type ;
extern Pbase ushort_type ;
extern Pbase ulong_type ;
extern Pbase ullong_type ;
extern Ptype Pchar_type ;
extern Ptype Pint_type ;
extern Ptype Pvptr_type ;
extern Ptype Pfctvec_type ;
extern Ptype Pvoid_type ;
extern Pbase zero_type ;
extern Ptype size_t_type ;

# 162 "/home/claude/cfront-3/src/cfront.h"
extern int byte_offset ;
extern int bit_offset ;
extern int max_align ;
extern int const_save ;
extern bit const_problem ;

# 169 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr dummy ;
extern Pexpr zero ;
extern Pexpr one ;
extern Pname sta_name ;

# 178 "/home/claude/cfront-3/src/cfront.h"
struct node {	/* sizeof node == 3 */
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;
};

# 217 "/home/claude/cfront-3/src/cfront.h"
void *__nw__5tableSFUl (size_t );
void __dl__5tableSFPvUl (void *, size_t );

# 198 "/home/claude/cfront-3/src/cfront.h"
struct table {	/* sizeof table == 56 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 200 "/home/claude/cfront-3/src/cfront.h"
bit init_stat__5table ;

# 204 "/home/claude/cfront-3/src/cfront.h"
TOK t_realbase__5table ;
short size__5table ;
short hashsize__5table ;
short free_slot__5table ;
Pname *entries__5table ;
short *hashtbl__5table ;
Pstmt real_block__5table ;

# 213 "/home/claude/cfront-3/src/cfront.h"
Ptable next__5table ;
Pname t_name__5table ;
};
extern Ptable table_free__5table ;
union __Q2_6ktable4__C1;

# 244 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_6ktable4__C1 {	/* sizeof __Q2_6ktable4__C1 == 8 */
Ptable k_t ;
Pname k_n ;
};

# 257 "/home/claude/cfront-3/src/cfront.h"
void *__nw__6ktableSFUl (size_t );
void __dl__6ktableSFPvUl (void *, size_t );

# 271 "/home/claude/cfront-3/src/cfront.h"
extern bit Nold ;
extern bit vec_const ;

# 272 "/home/claude/cfront-3/src/cfront.h"
extern bit fct_const ;

# 278 "/home/claude/cfront-3/src/cfront.h"
extern Plist local_class ;

# 282 "/home/claude/cfront-3/src/cfront.h"
extern Pname curr_fct ;

# 291 "/home/claude/cfront-3/src/cfront.h"
extern bit new_type ;
extern Pname cl_obj_vec ;
extern Pname eobj ;
enum Templ_type { VANILLA = 0, FCT_TEMPLATE = 1, CL_TEMPLATE = 2, BOUND_TEMPLATE = 3, INSTANTIATED = 4, UNINSTANTIATED = 5} ;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 309 "/home/claude/cfront-3/src/cfront.h"
struct type {	/* sizeof type == 64 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;
};

# 351 "/home/claude/cfront-3/src/cfront.h"
TOK kind__4typeFUcN21 (struct type *__0this , TOK , TOK , bit );

# 323 "/home/claude/cfront-3/src/cfront.h"

# 365 "/home/claude/cfront-3/src/cfront.h"
struct enumdef {	/* sizeof enumdef == 96 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 366 "/home/claude/cfront-3/src/cfront.h"
bit e_body__7enumdef ;
short no_of_enumerators__7enumdef ;
unsigned short e_strlen__7enumdef ;
const char *string__7enumdef ;
Pname mem__7enumdef ;
Pbase e_type__7enumdef ;
};
struct velem;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 386 "/home/claude/cfront-3/src/cfront.h"
struct virt {	/* sizeof virt == 56 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 387 "/home/claude/cfront-3/src/cfront.h"
Pvirt next__4virt ;
int n_init__4virt ;
struct velem *virt_init__4virt ;
Pclass vclass__4virt ;
const char *string__4virt ;
bit is_vbase__4virt ;
bit printed__4virt ;
};
enum __E16 { C_VPTR = 1, C_XREF = 2, C_ASS = 4, C_VBASE = 8, C_REFM = 16} ;
struct cons;

# 401 "/home/claude/cfront-3/src/cfront.h"
typedef struct cons *Pcons ;
struct basic_template;
typedef struct basic_template *Ptempl_base ;
struct toknode;

# 404 "/home/claude/cfront-3/src/cfront.h"
struct classdef {	/* sizeof classdef == 240 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 405 "/home/claude/cfront-3/src/cfront.h"
int class_base__8classdef ;
bit c_body__8classdef ;
TOK csu__8classdef ;
bit obj_align__8classdef ;
bit c_xref__8classdef ;

# 416 "/home/claude/cfront-3/src/cfront.h"
short virt_count__8classdef ;

# 418 "/home/claude/cfront-3/src/cfront.h"
bit virt_merge__8classdef ;

# 420 "/home/claude/cfront-3/src/cfront.h"
bit has_vvtab__8classdef ;
unsigned short c_strlen__8classdef ;
Pbcl baselist__8classdef ;
const char *string__8classdef ;
Pname c_abstract__8classdef ;
Pname mem_list__8classdef ;
Ptable memtbl__8classdef ;
Pktab k_tbl__8classdef ;
Ptable c_context__8classdef ;
int obj_size__8classdef ;
int real_size__8classdef ;
Pcons templ_friends__8classdef ;
Plist friend_list__8classdef ;
Pname pubdef__8classdef ;
Ptype this_type__8classdef ;
Pvirt virt_list__8classdef ;
Pname c_ctor__8classdef ;
Pname c_dtor__8classdef ;
Pname c_itor__8classdef ;
Pname c_vtor__8classdef ;
Pname conv__8classdef ;
struct toknode *c_funqf__8classdef ;

# 441 "/home/claude/cfront-3/src/cfront.h"
struct toknode *c_funqr__8classdef ;
};

# 446 "/home/claude/cfront-3/src/cfront.h"
bit same_class__8classdefFP8classdefi (struct classdef *__0this , Pclass __1p , int );
struct clist;

# 503 "/home/claude/cfront-3/src/cfront.h"
struct clist {	/* sizeof clist == 16 */
Pclass cl__5clist ;
struct clist *next__5clist ;
};

# 512 "/home/claude/cfront-3/src/cfront.h"
extern struct clist *vcllist ;
struct vl;

# 514 "/home/claude/cfront-3/src/cfront.h"
struct vl {	/* sizeof vl == 24 */
struct vl *next__2vl ;
Pvirt vt__2vl ;
struct classdef *cl__2vl ;
};

# 523 "/home/claude/cfront-3/src/cfront.h"
extern struct vl *vlist ;

# 525 "/home/claude/cfront-3/src/cfront.h"
extern int nin ;
extern int Noffset ;
extern TOK Nvis ;
extern TOK Nvirt ;
extern Pexpr Nptr ;
extern Pbcl Nvbc_alloc ;
extern const char *Nalloc_base ;

# 540 "/home/claude/cfront-3/src/cfront.h"
extern int Vcheckerror ;
extern int ignore_const ;

# 543 "/home/claude/cfront-3/src/cfront.h"
extern int mex ;
extern Pclass mec ;
extern Pclass tcl ;
extern int processing_sizeof ;
union __Q2_8basetype4__C1;

# 574 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_8basetype4__C1 {	/* sizeof __Q2_8basetype4__C1 == 8 */
Ptype b_fieldtype ;
const char *b_linkage ;
};
enum Linkage { linkage_default = 0, linkage_C = 1, linkage_Cplusplus = 2} ;

# 595 "/home/claude/cfront-3/src/cfront.h"
extern int linkage ;

# 630 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3fctSFUl (size_t );
void __dl__3fctSFPvUl (void *, size_t );

# 598 "/home/claude/cfront-3/src/cfront.h"
struct fct {	/* sizeof fct == 208 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 599 "/home/claude/cfront-3/src/cfront.h"
int fct_base__3fct ;
TOK nargs__3fct ;
TOK nargs_known__3fct ;
bit last_stmt__3fct ;
bit f_vdef__3fct ;

# 605 "/home/claude/cfront-3/src/cfront.h"
bit f_inline__3fct ;
bit f_is_inline__3fct ;

# 608 "/home/claude/cfront-3/src/cfront.h"
bit f_const__3fct ;

# 610 "/home/claude/cfront-3/src/cfront.h"
bit f_static__3fct ;
short f_virtual__3fct ;
short f_imeasure__3fct ;
Ptype returns__3fct ;
Pname argtype__3fct ;
Ptype s_returns__3fct ;
Pname f_this__3fct ;
Pclass memof__3fct ;
Pclass def_context__3fct ;
Pblock body__3fct ;
Pname f_init__3fct ;
Pexpr f_expr__3fct ;
Pexpr last_expanded__3fct ;
Pname nrv__3fct ;
Pname f_result__3fct ;
Pname f_args__3fct ;
int f_linkage__3fct ;
const char *f_signature__3fct ;
Plist local_class__3fct ;
};

# 629 "/home/claude/cfront-3/src/cfront.h"
extern Pfct fct_free__3fct ;
enum gen_types { no_templ = 0, some_templ = 1, all_templ = 2} ;

# 323 "/home/claude/cfront-3/src/cfront.h"

# 663 "/home/claude/cfront-3/src/cfront.h"
struct gen {	/* sizeof gen == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 664 "/home/claude/cfront-3/src/cfront.h"
Plist fct_list__3gen ;
int holds_templ__3gen ;
};
struct pvtyp;

# 323 "/home/claude/cfront-3/src/cfront.h"

# 679 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp {	/* sizeof pvtyp == 72 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;
};

# 690 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3vecSFUl (size_t );
void __dl__3vecSFPvUl (void *, size_t );

# 681 "/home/claude/cfront-3/src/cfront.h"

# 685 "/home/claude/cfront-3/src/cfront.h"
struct vec {	/* sizeof vec == 88 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;

# 686 "/home/claude/cfront-3/src/cfront.h"
Pexpr dim__3vec ;
int size__3vec ;
};
extern Pvec vec_free__3vec ;

# 705 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3ptrSFUl (size_t );
void __dl__3ptrSFPvUl (void *, size_t );

# 681 "/home/claude/cfront-3/src/cfront.h"

# 700 "/home/claude/cfront-3/src/cfront.h"
struct ptr {	/* sizeof ptr == 88 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;

# 701 "/home/claude/cfront-3/src/cfront.h"
Pclass memof__3ptr ;
Pname ptname__3ptr ;
};
extern Pptr ptr_free__3ptr ;

# 708 "/home/claude/cfront-3/src/cfront.h"

# 708 "/home/claude/cfront-3/src/cfront.h"
static struct ptr *__ct__3ptrFUcP4type (register struct ptr *__0this , TOK __2b , Ptype __2t ){ 
# 708 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp *__0__X20 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X18 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X13 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ptr *)__nw__3ptrSFUl ( (unsigned long )(sizeof (struct ptr))) )){ __0this = (struct ptr *)( (__0__X20 =
# 708 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X20 || (__0__X20 = (struct pvtyp *)__nw__FUl ( (unsigned long )(sizeof (struct pvtyp))) ))?(__0__X20 = (struct pvtyp *)(
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X18 = (((struct type *)__0__X20 ))), ( ((__0__X18 || (__0__X18 = (struct type *)__nw__FUl ( (unsigned long )(sizeof (struct type))) ))?( (
# 708 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X18 = (struct type *)( (__0__X13 = (((struct node *)__0__X18 ))), ( ((__0__X13 ||
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X13 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X13 -> base__4node = 0 ), (__0__X13 -> permanent__4node =
# 708 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X13 -> baseclass__4node = 0 )) :0 ), __0__X13 ) ) ), (__0__X18 -> defined__4type = 0 )) , (__0__X18 ->
# 708 "/home/claude/cfront-3/src/cfront.h"
lex_level__4type = 0 )) , (__0__X18 -> templ_base__4type = 0)) , (__0__X18 -> in_class__4type = 0 )) , (__0__X18 -> nested_sig__4type = 0 ))
# 708 "/home/claude/cfront-3/src/cfront.h"
, (__0__X18 -> local_sig__4type = 0 )) , (__0__X18 -> b_const__4type = 0 )) , (__0__X18 -> ansi_const__4type = 0 )) :0 ), __0__X18 )
# 708 "/home/claude/cfront-3/src/cfront.h"
) ):0 ), __0__X20 ) ) ;

# 708 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = __2b ;

# 708 "/home/claude/cfront-3/src/cfront.h"
__0this -> typ__5pvtyp = __2t ;

# 708 "/home/claude/cfront-3/src/cfront.h"
;
} 
# 708 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 708 "/home/claude/cfront-3/src/cfront.h"
}

# 708 "/home/claude/cfront-3/src/cfront.h"

# 334 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFv (struct type *__0this );

# 743 "/home/claude/cfront-3/src/cfront.h"
extern int ref_initializer ;
extern int ntok ;
union __Q2_4expr4__C1;
union __Q2_4expr4__C2;
union __Q2_4expr4__C3;
union __Q2_4expr4__C4;

# 763 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 {	/* sizeof __Q2_4expr4__C1 == 8 */
Ptype tp ;
char *string4 ;
};
union  __Q2_4expr4__C2 {	/* sizeof __Q2_4expr4__C2 == 8 */
Pexpr e1 ;
long long i1 ;
const char *string ;
};
union  __Q2_4expr4__C3 {	/* sizeof __Q2_4expr4__C3 == 8 */
Pexpr e2 ;
int i2 ;
const char *string2 ;
Pexpr n_initializer ;
Ptype tpdef ;
};
union  __Q2_4expr4__C4 {	/* sizeof __Q2_4expr4__C4 == 8 */
Ptype tp2 ;
Pname fct_name ;
Pexpr cond ;
Pexpr mem ;
Ptype as_type ;
Ptable n_table ;
Pin il ;
Pname query_this ;
};

# 791 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4exprSFUl (size_t );
void __dl__4exprSFPvUl (void *, size_t );

# 762 "/home/claude/cfront-3/src/cfront.h"
struct expr {	/* sizeof expr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};
extern Pexpr expr_free__4expr ;

# 793 "/home/claude/cfront-3/src/cfront.h"
struct expr *__ct__4exprFUcP4exprT2 (struct expr *__0this , TOK , Pexpr , Pexpr );

# 819 "/home/claude/cfront-3/src/cfront.h"
struct texpr {	/* sizeof texpr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct cast;

# 823 "/home/claude/cfront-3/src/cfront.h"
struct cast {	/* sizeof cast == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct ival;

# 827 "/home/claude/cfront-3/src/cfront.h"
struct ival {	/* sizeof ival == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 831 "/home/claude/cfront-3/src/cfront.h"
struct call {	/* sizeof call == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 839 "/home/claude/cfront-3/src/cfront.h"
struct qexpr {	/* sizeof qexpr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 843 "/home/claude/cfront-3/src/cfront.h"
struct ref {	/* sizeof ref == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct mdot;

# 847 "/home/claude/cfront-3/src/cfront.h"
struct mdot {	/* sizeof mdot == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct text_expr;

# 851 "/home/claude/cfront-3/src/cfront.h"
struct text_expr {	/* sizeof text_expr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 187 "/home/claude/cfront-3/src/cfront.h"

# 858 "/home/claude/cfront-3/src/cfront.h"
struct basecl {	/* sizeof basecl == 48 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 860 "/home/claude/cfront-3/src/cfront.h"
TOK ppp__6basecl ;
bit allocated__6basecl ;
bit promoted__6basecl ;
Pclass bclass__6basecl ;
Pexpr init__6basecl ;
int ptr_offset__6basecl ;
int obj_offset__6basecl ;
Pname *virt_init__6basecl ;
struct basecl *next__6basecl ;
};
enum template_formal_types { template_type_formal = 1, template_expr_formal = 2, template_actual_arg_dummy = 3} ;

# 878 "/home/claude/cfront-3/src/cfront.h"
extern TOK ppbase ;
union __Q2_4name4__C1;
union __Q2_4name4__C2;

# 905 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C1 {	/* sizeof __Q2_4name4__C1 == 8 */
Pname n_list ;
Pname n_hidden ;
Pname n_dtag ;
};

# 914 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C2 {	/* sizeof __Q2_4name4__C2 == 8 */

# 921 "/home/claude/cfront-3/src/cfront.h"
Pname n_qualifier ;
Ptable n_realscope ;
int syn_class ;
};

# 931 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4nameSFUl (size_t );
void __dl__4nameSFPvUl (void *, size_t );

# 880 "/home/claude/cfront-3/src/cfront.h"
struct name {	/* sizeof name == 144 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;

# 881 "/home/claude/cfront-3/src/cfront.h"
TOK n_oper__4name ;
TOK n_sto__4name ;
TOK n_stclass__4name ;
TOK n_scope__4name ;
TOK n_key__4name ;
bit n_evaluated__4name ;
bit n_xref__4name ;
unsigned char lex_level__4name ;
TOK n_protect__4name ;
bit n_dcl_printed__4name ;

# 895 "/home/claude/cfront-3/src/cfront.h"
char n_template_arg__4name ;
bit n_template_fct__4name ;
bit n_redefined__4name ;

# 899 "/home/claude/cfront-3/src/cfront.h"
short n_addr_taken__4name ;
short n_used__4name ;
short n_assigned_to__4name ;
struct loc where__4name ;
int n_offset__4name ;
const char *n_anon__4name ;

# 909 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C1 __O1__4name ;
Pname n_tbl_list__4name ;
const char *n_gen_fct_name__4name ;
char *n_template_arg_string__4name ;
Pktab n_ktable__4name ;

# 924 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C2 __O2__4name ;

# 927 "/home/claude/cfront-3/src/cfront.h"
long long n_val__4name ;

# 929 "/home/claude/cfront-3/src/cfront.h"
int argno__4name ;
};

# 930 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_free__4name ;

# 817 "/home/claude/cfront-3/src/cfront.h"

# 964 "/home/claude/cfront-3/src/cfront.h"
extern int friend_in_class ;
extern int in_class_dcl ;

# 968 "/home/claude/cfront-3/src/cfront.h"
extern int in_class_decl ;
extern int parsing_class_members ;
extern int in_mem_fct ;
extern int in_arg_list ;
extern Ptype in_typedef ;
extern int defer_check ;
extern int declTag ;
extern Pname in_tag ;
extern int DECL_TYPE ;
union __Q2_4stmt4__C1;
union __Q2_4stmt4__C2;
union __Q2_4stmt4__C3;

# 986 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 {	/* sizeof __Q2_4stmt4__C1 == 8 */
Pname d ;
Pexpr e2 ;
Pstmt has_default ;
int case_value ;
Ptype ret_tp ;
};
union  __Q2_4stmt4__C2 {	/* sizeof __Q2_4stmt4__C2 == 8 */
Pexpr e ;
bit own_tbl ;
Pstmt s2 ;
};

# 1000 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 {	/* sizeof __Q2_4stmt4__C3 == 8 */
Pstmt for_init ;
Pstmt else_stmt ;
Pstmt case_list ;
struct loc where2 ;
};

# 1009 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4stmtSFUl (size_t );
void __dl__4stmtSFPvUl (void *, size_t );

# 980 "/home/claude/cfront-3/src/cfront.h"
struct stmt {	/* sizeof stmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};
extern Pstmt stmt_free__4stmt ;

# 1028 "/home/claude/cfront-3/src/cfront.h"
extern const char *Neval ;
extern Ptable scope ;
extern Ptable expand_tbl ;
extern Pname expand_fn ;

# 1011 "/home/claude/cfront-3/src/cfront.h"
struct stmt *__ct__4stmtFUc3locP4stmt (struct stmt *__0this , TOK , struct loc , Pstmt );

# 1041 "/home/claude/cfront-3/src/cfront.h"
struct estmt {	/* sizeof estmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct ifstmt;

# 1048 "/home/claude/cfront-3/src/cfront.h"
struct ifstmt {	/* sizeof ifstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct lstmt;

# 1058 "/home/claude/cfront-3/src/cfront.h"
struct lstmt {	/* sizeof lstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct forstmt;

# 1062 "/home/claude/cfront-3/src/cfront.h"
struct forstmt {	/* sizeof forstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 1067 "/home/claude/cfront-3/src/cfront.h"
struct block {	/* sizeof block == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct handler;

# 1076 "/home/claude/cfront-3/src/cfront.h"
struct handler {	/* sizeof handler == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct pair;

# 1082 "/home/claude/cfront-3/src/cfront.h"
struct pair {	/* sizeof pair == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 1087 "/home/claude/cfront-3/src/cfront.h"
struct nlist {	/* sizeof nlist == 16 */
Pname head__5nlist ;
Pname tail__5nlist ;
};

# 1097 "/home/claude/cfront-3/src/cfront.h"
struct slist {	/* sizeof slist == 16 */
Pstmt head__5slist ;
Pstmt tail__5slist ;
};

# 1106 "/home/claude/cfront-3/src/cfront.h"
struct elist {	/* sizeof elist == 16 */
Pexpr head__5elist ;
Pexpr tail__5elist ;
};
struct dcl_context;

# 1116 "/home/claude/cfront-3/src/cfront.h"
extern struct dcl_context *cc ;

# 1120 "/home/claude/cfront-3/src/cfront.h"
extern struct dcl_context *ccvec_end ;

# 1122 "/home/claude/cfront-3/src/cfront.h"
struct dcl_context {	/* sizeof dcl_context == 48 */
Pname c_this__11dcl_context ;
Ptype tot__11dcl_context ;
Pname not4__11dcl_context ;
Pclass cot__11dcl_context ;
Ptable ftbl__11dcl_context ;
Pname nof__11dcl_context ;
};

# 84 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiPCc (int , const char *);

# 1146 "/home/claude/cfront-3/src/cfront.h"
extern const char *line_format ;

# 1148 "/home/claude/cfront-3/src/cfront.h"
extern Plist stat_mem_list ;
extern Plist isf_list ;
extern Pstmt st_ilist ;
extern Pstmt st_dlist ;
extern Ptable sti_tbl ;
extern Ptable std_tbl ;

# 1158 "/home/claude/cfront-3/src/cfront.h"
extern bit enum_promote ;
extern int suppress_error ;

# 1163 "/home/claude/cfront-3/src/cfront.h"
extern Pname overFound ;
extern Pname Nover ;
extern Pname Ncoerce ;
extern int Nover_coerce ;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 1167 "/home/claude/cfront-3/src/cfront.h"
struct ia {	/* sizeof ia == 32 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 1168 "/home/claude/cfront-3/src/cfront.h"
Pname local__2ia ;
Pexpr arg__2ia ;
Ptype tp__2ia ;
};

# 187 "/home/claude/cfront-3/src/cfront.h"

# 1174 "/home/claude/cfront-3/src/cfront.h"
struct iline {	/* sizeof iline == 48 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 1175 "/home/claude/cfront-3/src/cfront.h"
Pname fct_name__5iline ;
Pin i_next__5iline ;
Ptable i_table__5iline ;
int i_slots__5iline ;
Pia i_args__5iline ;
};
struct con_dtor;

# 1183 "/home/claude/cfront-3/src/cfront.h"
struct con_dtor {	/* sizeof con_dtor == 24 */
Pname tn__8con_dtor ;
Pexpr condition__8con_dtor ;
struct con_dtor *next__8con_dtor ;
};

# 1191 "/home/claude/cfront-3/src/cfront.h"
extern struct con_dtor *pdlist ;
extern Pexpr curr_expr ;
extern Pin curr_icall ;

# 1198 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt curr_loop ;
extern Pblock curr_block ;
extern Pstmt curr_switch ;
extern struct loc last_line ;
extern int last_ll ;
extern bit Cast ;
extern bit TCast ;
extern bit simpl_friend ;
extern bit in_return ;
extern struct loc no_where ;

# 1214 "/home/claude/cfront-3/src/cfront.h"
extern Pname vec_new_fct ;
extern Pname new_fct ;
extern Pname del_fct ;
extern Pname vec_del_fct ;

# 1219 "/home/claude/cfront-3/src/cfront.h"
extern int Nstd ;

# 1221 "/home/claude/cfront-3/src/cfront.h"
extern int stcount ;

# 1226 "/home/claude/cfront-3/src/cfront.h"
extern int Pchecked ;

# 1236 "/home/claude/cfront-3/src/cfront.h"
extern Pname Ntmp ;
extern Pname Ntmp_refd ;
extern Pname Ntmp_flag ;
extern Pexpr Ntmp_dtor ;

# 1250 "/home/claude/cfront-3/src/cfront.h"
extern Pclass Mptr ;

# 1254 "/home/claude/cfront-3/src/cfront.h"
extern bit fake_sizeof ;

# 559 "/home/claude/cfront-3/src/cfront.h"
struct basetype {	/* sizeof basetype == 112 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 560 "/home/claude/cfront-3/src/cfront.h"
bit b_unsigned__8basetype ;
bit b_signed__8basetype ;
bit b_volatile__8basetype ;
bit b_typedef__8basetype ;
bit b_inline__8basetype ;
bit b_virtual__8basetype ;
bit b_short__8basetype ;
bit b_long__8basetype ;
bit b_bits__8basetype ;
bit b_offset__8basetype ;
TOK b_sto__8basetype ;
Pname b_name__8basetype ;
Ptable b_table__8basetype ;
Pname b_xname__8basetype ;

# 577 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_8basetype4__C1 __O1__8basetype ;
};

# 85 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiPCcRC2eaN33 (int , const char *, const struct ea *, const struct ea *, const
# 85 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 654 "/home/claude/cfront-3/src/cfront.h"
struct name_list {	/* sizeof name_list == 24 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 655 "/home/claude/cfront-3/src/cfront.h"
Pname f__9name_list ;
Plist l__9name_list ;
};

# 933 "/home/claude/cfront-3/src/cfront.h"
struct name *__ct__4nameFPCc (struct name *__0this , const char *);

# 224 "/home/claude/cfront-3/src/cfront.h"
Pname insert__5tableFP4nameUc (struct table *__0this , Pname , TOK );
enum bool { false = 0, true = 1} ;

# 26 "/home/claude/cfront-3/src/template.h"
extern Pclass current_instantiation ;
extern Pfct current_fct_instantiation ;
struct templ;

# 30 "/home/claude/cfront-3/src/template.h"
typedef struct templ *Ptempl ;
struct funct_inst;
typedef struct funct_inst *Pfunct_inst ;
struct templ_inst;
typedef struct templ_inst *Ptempl_inst ;
struct basic_inst;
typedef struct basic_inst *Pbase_inst ;
struct function_template;

# 35 "/home/claude/cfront-3/src/template.h"
typedef struct function_template *Pfunt ;
struct data_template;
typedef struct data_template *Pdata ;
struct templ_state;
typedef struct templ_state *Ptstate ;
struct templ_classdef;
typedef struct templ_classdef *Ptclass ;
struct templ_fct;
typedef struct templ_fct *Ptfct ;
struct Pslot;
typedef struct Pslot *Pbinding ;

# 43 "/home/claude/cfront-3/src/template.h"
struct cons {	/* sizeof cons == 16 */

# 48 "/home/claude/cfront-3/src/template.h"
void *car__4cons ;
struct cons *cdr__4cons ;
};
struct templ_compilation;

# 158 "/home/claude/cfront-3/src/template.h"
extern struct templ_compilation *templp ;

# 167 "/home/claude/cfront-3/src/template.h"
struct basic_template {	/* sizeof basic_template == 48 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;
};
struct templ {	/* sizeof templ == 128 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;

# 206 "/home/claude/cfront-3/src/template.h"
Ptempl_inst insts__5templ ;
Pbase basep__5templ ;
Pfunt fns__5templ ;
Pfunt fns_end__5templ ;
Pdata data__5templ ;
Pdata data_end__5templ ;

# 215 "/home/claude/cfront-3/src/template.h"
Ptempl next__5templ ;
Pname namep__5templ ;
int defined__5templ ;
Pname members__5templ ;
};

# 236 "/home/claude/cfront-3/src/template.h"
struct function_template {	/* sizeof function_template == 80 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;

# 247 "/home/claude/cfront-3/src/template.h"
Pname fn__17function_template ;
Pfunt next__17function_template ;
Pfunt gen_list__17function_template ;

# 251 "/home/claude/cfront-3/src/template.h"
Pfunct_inst insts__17function_template ;
};
struct state;

# 280 "/home/claude/cfront-3/src/template.h"
struct state {	/* sizeof state == 88 */

# 282 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__5state ;
Pstmt Cstmt__5state ;
Pname dcl_list__5state ;
struct loc curloc__5state ;

# 287 "/home/claude/cfront-3/src/template.h"
int curr_file__5state ;
Pexpr curr_expr__5state ;
Pin curr_icall__5state ;
Pstmt curr_loop__5state ;
Pblock curr_block__5state ;
Pstmt curr_switch__5state ;

# 294 "/home/claude/cfront-3/src/template.h"
int bound__5state ;
int inline_restr__5state ;
struct loc last_line__5state ;
};
struct pointer_hash;
struct tree_copy_info;
enum inst_status { uninstantiated = 0, function_instantiated = 1, data_instantiated = 2, class_instantiated = 3, body_instantiated = 4} ;
struct template_instantiation;

# 318 "/home/claude/cfront-3/src/template.h"
struct basic_inst {	/* sizeof basic_inst == 168 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;
};

# 336 "/home/claude/cfront-3/src/template.h"
extern Pbase_inst head__10basic_inst ;

# 298 "/home/claude/cfront-3/src/template.h"

# 393 "/home/claude/cfront-3/src/template.h"
struct templ_inst {	/* sizeof templ_inst == 200 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;

# 400 "/home/claude/cfront-3/src/template.h"
Ptempl_inst next__10templ_inst ;
Ptempl_inst forward__10templ_inst ;

# 417 "/home/claude/cfront-3/src/template.h"
Ptempl def__10templ_inst ;

# 419 "/home/claude/cfront-3/src/template.h"
int refp__10templ_inst ;

# 422 "/home/claude/cfront-3/src/template.h"
int friend_refp__10templ_inst ;
};

# 456 "/home/claude/cfront-3/src/template.h"
extern int zdebug ;

# 463 "/home/claude/cfront-3/src/template.h"
struct templ_classdef {	/* sizeof templ_classdef == 248 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 405 "/home/claude/cfront-3/src/cfront.h"
int class_base__8classdef ;
bit c_body__8classdef ;
TOK csu__8classdef ;
bit obj_align__8classdef ;
bit c_xref__8classdef ;

# 416 "/home/claude/cfront-3/src/cfront.h"
short virt_count__8classdef ;

# 418 "/home/claude/cfront-3/src/cfront.h"
bit virt_merge__8classdef ;

# 420 "/home/claude/cfront-3/src/cfront.h"
bit has_vvtab__8classdef ;
unsigned short c_strlen__8classdef ;
Pbcl baselist__8classdef ;
const char *string__8classdef ;
Pname c_abstract__8classdef ;
Pname mem_list__8classdef ;
Ptable memtbl__8classdef ;
Pktab k_tbl__8classdef ;
Ptable c_context__8classdef ;
int obj_size__8classdef ;
int real_size__8classdef ;
Pcons templ_friends__8classdef ;
Plist friend_list__8classdef ;
Pname pubdef__8classdef ;
Ptype this_type__8classdef ;
Pvirt virt_list__8classdef ;
Pname c_ctor__8classdef ;
Pname c_dtor__8classdef ;
Pname c_itor__8classdef ;
Pname c_vtor__8classdef ;
Pname conv__8classdef ;
struct toknode *c_funqf__8classdef ;

# 441 "/home/claude/cfront-3/src/cfront.h"
struct toknode *c_funqr__8classdef ;

# 467 "/home/claude/cfront-3/src/template.h"
Ptempl_inst inst__14templ_classdef ;
};

# 444 "/home/claude/cfront-3/src/cfront.h"
void __dt__8classdefFv (struct classdef *__0this , int );

# 1 ""
extern void __dl__FPv (void *);

# 478 "/home/claude/cfront-3/src/template.h"
void *__nw__9templ_fctSFUl (size_t );
void __dl__9templ_fctSFPvUl (void *, size_t );

# 473 "/home/claude/cfront-3/src/template.h"
struct templ_fct {	/* sizeof templ_fct == 216 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 599 "/home/claude/cfront-3/src/cfront.h"
int fct_base__3fct ;
TOK nargs__3fct ;
TOK nargs_known__3fct ;
bit last_stmt__3fct ;
bit f_vdef__3fct ;

# 605 "/home/claude/cfront-3/src/cfront.h"
bit f_inline__3fct ;
bit f_is_inline__3fct ;

# 608 "/home/claude/cfront-3/src/cfront.h"
bit f_const__3fct ;

# 610 "/home/claude/cfront-3/src/cfront.h"
bit f_static__3fct ;
short f_virtual__3fct ;
short f_imeasure__3fct ;
Ptype returns__3fct ;
Pname argtype__3fct ;
Ptype s_returns__3fct ;
Pname f_this__3fct ;
Pclass memof__3fct ;
Pclass def_context__3fct ;
Pblock body__3fct ;
Pname f_init__3fct ;
Pexpr f_expr__3fct ;
Pexpr last_expanded__3fct ;
Pname nrv__3fct ;
Pname f_result__3fct ;
Pname f_args__3fct ;
int f_linkage__3fct ;
const char *f_signature__3fct ;
Plist local_class__3fct ;

# 475 "/home/claude/cfront-3/src/template.h"
Pfunct_inst inst__9templ_fct ;
};

# 480 "/home/claude/cfront-3/src/template.h"
extern Ptfct ptfct_free__9templ_fct ;

# 371 "/home/claude/cfront-3/src/template.h"
struct funct_inst {	/* sizeof funct_inst == 200 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;

# 376 "/home/claude/cfront-3/src/template.h"
Pfunct_inst next__10funct_inst ;

# 386 "/home/claude/cfront-3/src/template.h"
Pfunt def__10funct_inst ;
int refp__10funct_inst ;
int friend_refp__10funct_inst ;
Pbinding binding__10funct_inst ;
};

# 652 "/home/claude/cfront-3/src/cfront.h"

#pragma lib "ape/libap.a"

#pragma lib "c++/libC.a"

# 20 "/home/claude/incl-linux32/generic.h"
typedef int (*GPT )(int , char *);
struct Block_CPchar;

# 491 "/home/claude/cfront-3/src/template.h"
struct Block_CPchar {	/* sizeof Block_CPchar == 16 */

# 491 "/home/claude/cfront-3/src/template.h"
CPchar *p__12Block_CPchar ;

# 491 "/home/claude/cfront-3/src/template.h"
size_t n__12Block_CPchar ;
};

# 491 "/home/claude/cfront-3/src/template.h"
void move__12Block_CPcharFPPCcUl (struct Block_CPchar *__0this , CPchar *, size_t );

# 491 "/home/claude/cfront-3/src/template.h"
void copy__12Block_CPcharFRC12Block_CPchar (struct Block_CPchar *__0this , const struct Block_CPchar *);

# 491 "/home/claude/cfront-3/src/template.h"
size_t grow__12Block_CPcharFUl (struct Block_CPchar *__0this , size_t );
struct Block_Pchar;
struct Block_Pchar {	/* sizeof Block_Pchar == 16 */

# 492 "/home/claude/cfront-3/src/template.h"
Pchar *p__11Block_Pchar ;

# 492 "/home/claude/cfront-3/src/template.h"
size_t n__11Block_Pchar ;
};

# 492 "/home/claude/cfront-3/src/template.h"
void move__11Block_PcharFPPcUl (struct Block_Pchar *__0this , Pchar *, size_t );

# 492 "/home/claude/cfront-3/src/template.h"
void copy__11Block_PcharFRC11Block_Pchar (struct Block_Pchar *__0this , const struct Block_Pchar *);

# 492 "/home/claude/cfront-3/src/template.h"
size_t grow__11Block_PcharFUl (struct Block_Pchar *__0this , size_t );
extern struct Block_Pchar instfct ;
extern int noinst ;
extern struct Block_Pchar instdata ;
extern int nodatainst ;
extern bit tempdcl ;
extern bit mk_zero_init_flag ;
extern int first_file ;
extern bit all_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit alltc_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit data_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit ft_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit none_flag ;

# 502 "/home/claude/cfront-3/src/template.h"
extern Pname righttname ;

# 42 "/home/claude/cfront-3/src/main.cpp"
const char *prog_name = (const char *)"<<AT&T C++ Language System <3.0.3> 05/05/94>>";
static const char *prog_vers = (const char *)"__cfront_version_303_xxxxxxxx";
const char *src_file_name = (const char *)"";
const char *line_format = (const char *)"\n# %d \"%s\"\n";

# 492 "/home/claude/cfront-3/src/template.h"

# 47 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar instfct = { 0 } ;

# 492 "/home/claude/cfront-3/src/template.h"

# 48 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar instdata = { 0 } ;
bit all_flag = 0 ;

# 49 "/home/claude/cfront-3/src/main.cpp"
bit alltc_flag = 0 ;

# 49 "/home/claude/cfront-3/src/main.cpp"
bit data_flag = 0 ;

# 49 "/home/claude/cfront-3/src/main.cpp"
bit ft_flag = 0 ;

# 49 "/home/claude/cfront-3/src/main.cpp"
bit none_flag = 0 ;
int noinst = 0 ;

# 50 "/home/claude/cfront-3/src/main.cpp"
int nodatainst = 0 ;

# 137 "/home/claude/incl-linux32/stdio.h"
extern void *_get_stderr (void );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 33 "/home/claude/cfront-3/src/cfront.h"
extern void ext__Fi (int );

# 59 "/home/claude/cfront-3/src/main.cpp"
static void core_dump__Fi (int __1__A38 )
# 60 "/home/claude/cfront-3/src/main.cpp"
{ 
# 61 "/home/claude/cfront-3/src/main.cpp"
if (error_count )
# 62 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"sorry, cannot recover from previous error\n")
# 62 "/home/claude/cfront-3/src/main.cpp"
;
else 
# 64 "/home/claude/cfront-3/src/main.cpp"
error__FiPCc ( (int )'i' , (const char *)"bus error (or something nasty like that)") ;

# 68 "/home/claude/cfront-3/src/main.cpp"
ext__Fi ( 99 ) ;

# 70 "/home/claude/cfront-3/src/main.cpp"
}

# 73 "/home/claude/cfront-3/src/main.cpp"
Plist isf_list = 0 ;
Pstmt st_ilist = 0 ;
Pstmt st_dlist = 0 ;
Ptable sti_tbl = 0 ;
Ptable std_tbl = 0 ;
Plist stat_mem_list = 0 ;

# 80 "/home/claude/cfront-3/src/main.cpp"
int vtbl_opt = -1;

# 84 "/home/claude/cfront-3/src/main.cpp"
int debug_opt = 0 ;
static int gplus_opt ;
int ansi_opt = 1 ;
int strict_opt = 0 ;

# 89 "/home/claude/cfront-3/src/main.cpp"
int warning_opt = 0 ;
int dem_opt_local = 0 ;
int dem_opt_mem = 0 ;
int perf_opt = 0 ;

# 94 "/home/claude/cfront-3/src/main.cpp"
int pt_opt = 0 ;
int dtpt_opt = 0 ;
int se_opt = 0 ;
bit stmtno = 0 ;

# 99 "/home/claude/cfront-3/src/main.cpp"
int inline_opt = 0 ;

# 108 "/home/claude/cfront-3/src/main.cpp"
Pname def_name = 0 ;
Pname pdef_name = 0 ;

# 111 "/home/claude/cfront-3/src/main.cpp"
int syn_count = 0 ;

# 31 "/home/claude/cfront-3/src/cfront.h"
extern Pname syn__Fv (void );

# 92 "/home/claude/cfront-3/src/template.h"
struct templ_compilation {	/* sizeof templ_compilation == 1 */

# 92 "/home/claude/cfront-3/src/template.h"
char __W29__17templ_compilation ;
};

# 98 "/home/claude/cfront-3/src/template.h"
extern Plist param_end__17templ_compilation ;
extern Ptempl list__17templ_compilation ;
extern Pfunt f_list__17templ_compilation ;
extern Pfunt f_owner__17templ_compilation ;
extern Ptempl owner__17templ_compilation ;
extern Ptempl_base parsed_template__17templ_compilation ;

# 105 "/home/claude/cfront-3/src/template.h"
extern Plist params__17templ_compilation ;
extern Pexpr actuals__17templ_compilation ;
extern Ptable templates__17templ_compilation ;

# 109 "/home/claude/cfront-3/src/template.h"
extern int in_progress__17templ_compilation ;
extern Ptstate save_templ__17templ_compilation ;

# 115 "/home/claude/cfront-3/src/template.h"
extern int parameters_in_progress__17templ_compilation ;
extern int formals_in_progress__17templ_compilation ;

# 119 "/home/claude/cfront-3/src/template.h"
extern Pcons templ_refs__17templ_compilation ;
extern Pcons friend_templ_refs__17templ_compilation ;
extern Pcons last_cons__17templ_compilation ;
extern Pcons last_friend_cons__17templ_compilation ;

# 134 "/home/claude/cfront-3/src/template.h"
void instantiate_ref_templ__17templ_compilationFv (struct templ_compilation *__0this );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 946 "/home/claude/cfront-3/src/cfront.h"
void simpl__4nameFv (struct name *__0this );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 375 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__7enumdefFP4name (struct enumdef *__0this , Pname );

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 1160 "/home/claude/cfront-3/src/cfront.h"
extern void delete_local__Fv (void );

# 1012 "/home/claude/cfront-3/src/cfront.h"
void del__4stmtFv (struct stmt *__0this );

# 959 "/home/claude/cfront-3/src/cfront.h"
void del__4nameFv (struct name *__0this );

# 48 "/home/claude/cfront-3/src/token.h"
extern void lex_clear__Fv (void );

# 126 "/home/claude/cfront-3/src/template.h"
void end_of_compilation__17templ_compilationFv (struct templ_compilation *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 749 "/home/claude/cfront-3/src/cfront.h"
extern char *st_name__FPCc (const char *);

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 648 "/home/claude/cfront-3/src/cfront.h"
void sign__3fctFv (struct fct *__0this );

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 479 "/home/claude/cfront-3/src/cfront.h"
void really_print__8classdefFP4virt (struct classdef *__0this , Pvirt );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 498 "/home/claude/cfront-3/src/main.cpp"
extern int ispt_data__FP4name (Pname );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 12 "/home/claude/incl-linux32/string.h"
extern char *strncpy (char *, const char *, size_t );

# 747 "/home/claude/cfront-3/src/cfront.h"
extern void ptbl_add_pair__FPCcT1 (const char *, const char *);

# 234 "/home/claude/cfront-3/src/cfront.h"

# 746 "/home/claude/cfront-3/src/cfront.h"
extern void ptbl_init__Fi (int );

# 55 "/home/claude/cfront-3/src/cfront.h"
void putline__3locFv (struct loc *__0this );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/main.cpp"
void run__Fv (void )
# 117 "/home/claude/cfront-3/src/main.cpp"
{ 
# 118 "/home/claude/cfront-3/src/main.cpp"
Pname __1n ;
templp = (((struct templ_compilation *)__nw__FUl ( sizeof (struct templ_compilation )) ));

# 121 "/home/claude/cfront-3/src/main.cpp"
while (__1n = syn__Fv ( ) ){ 
# 122 "/home/claude/cfront-3/src/main.cpp"
int __2oerror_count ;

# 122 "/home/claude/cfront-3/src/main.cpp"
__2oerror_count = error_count ;
if (__1n == (((struct name *)1 )))
# 124 "/home/claude/cfront-3/src/main.cpp"
continue ;
if (__1n -> __O1__4name.n_list )
# 126 "/home/claude/cfront-3/src/main.cpp"
__1n -> __O1__4expr.tp -> permanent__4node = 1 ;

# 128 "/home/claude/cfront-3/src/main.cpp"
;
instantiate_ref_templ__17templ_compilationFv ( templp ) ;

# 131 "/home/claude/cfront-3/src/main.cpp"
{ { Pname __2nx ;

# 131 "/home/claude/cfront-3/src/main.cpp"
Pname __2nn ;

# 131 "/home/claude/cfront-3/src/main.cpp"
__2nn = __1n ;

# 131 "/home/claude/cfront-3/src/main.cpp"
for(;__2nn ;__2nn = __2nx ) { 
# 132 "/home/claude/cfront-3/src/main.cpp"
Pname __3rr ;
++ syn_count ;
__2nx = __2nn -> __O1__4name.n_list ;
__2nn -> __O1__4name.n_list = 0 ;

# 138 "/home/claude/cfront-3/src/main.cpp"
;

# 140 "/home/claude/cfront-3/src/main.cpp"
if ((((__3rr = dcl__4nameFP5tableUc ( __2nn , gtbl , (unsigned char )14 ) )== 0 )|| (__2nn -> base__4node == 0 ))|| (error_count >
# 140 "/home/claude/cfront-3/src/main.cpp"
__2oerror_count ))
# 147 "/home/claude/cfront-3/src/main.cpp"
continue ;

# 152 "/home/claude/cfront-3/src/main.cpp"
;

# 154 "/home/claude/cfront-3/src/main.cpp"
;
simpl__4nameFv ( __2nn ) ;

# 157 "/home/claude/cfront-3/src/main.cpp"
if (error_count ){ 
# 158 "/home/claude/cfront-3/src/main.cpp"
continue ;
}

# 161 "/home/claude/cfront-3/src/main.cpp"
;

# 163 "/home/claude/cfront-3/src/main.cpp"
if (__2nn -> base__4node != 123 ){ 
# 164 "/home/claude/cfront-3/src/main.cpp"
Ptype __4t ;

# 164 "/home/claude/cfront-3/src/main.cpp"
__4t = skiptypedefs__4typeFv ( __2nn -> __O1__4expr.tp ) ;

# 166 "/home/claude/cfront-3/src/main.cpp"
switch (__4t -> base__4node ){ 
# 167 "/home/claude/cfront-3/src/main.cpp"
case 6 :
# 169 "/home/claude/cfront-3/src/main.cpp"
;
if (((vtbl_opt == 1 )|| gplus_opt )|| (__2nn -> n_redefined__4name == 1 ))
# 171 "/home/claude/cfront-3/src/main.cpp"
dcl_print__4nameFUc ( __2nn , (unsigned char )0 ) ;
break ;
case 13 :
# 174 "/home/claude/cfront-3/src/main.cpp"
;
dcl_print__7enumdefFP4name ( ((struct enumdef *)(((struct enumdef *)__2nn -> __O1__4expr.tp ))), (struct name *)0 ) ;
break ;
case 108 :
# 178 "/home/claude/cfront-3/src/main.cpp"
;
if ((((((struct fct *)(((struct fct *)__4t ))))-> body__3fct == 0 )|| (((debug_opt == 0 )&& (((struct fct *)(((struct fct *)__4t ))))-> f_inline__3fct )&& ((__1n -> __O4__4expr.n_table !=
# 179 "/home/claude/cfront-3/src/main.cpp"
gtbl )|| strcmp ( __2nn -> __O2__4expr.string , (const char *)"main") )))|| ((((struct fct *)(((struct
# 179 "/home/claude/cfront-3/src/main.cpp"
fct *)__4t ))))-> f_imeasure__3fct && ((((struct fct *)(((struct fct *)__4t ))))-> f_inline__3fct == 0 )))
# 198 "/home/claude/cfront-3/src/main.cpp"
break ;
;
dcl_print__4nameFUc ( __3rr , (unsigned char )0 ) ;
break ;

# 203 "/home/claude/cfront-3/src/main.cpp"
default :
# 204 "/home/claude/cfront-3/src/main.cpp"
{ 
# 209 "/home/claude/cfront-3/src/main.cpp"
;

# 211 "/home/claude/cfront-3/src/main.cpp"
{ { Ptype __6tx ;

# 211 "/home/claude/cfront-3/src/main.cpp"
__6tx = __4t ;

# 211 "/home/claude/cfront-3/src/main.cpp"
for(;;) { 
# 212 "/home/claude/cfront-3/src/main.cpp"
switch (__6tx -> base__4node ){ 
# 213 "/home/claude/cfront-3/src/main.cpp"
case 110 :
# 214 "/home/claude/cfront-3/src/main.cpp"
__6tx = (((struct vec *)(((struct vec *)__6tx ))))-> typ__5pvtyp ;
continue ;
case 97 :
# 217 "/home/claude/cfront-3/src/main.cpp"
case 119 :
# 218 "/home/claude/cfront-3/src/main.cpp"
__6tx = (((struct basetype *)(((struct basetype *)__6tx ))))-> b_name__8basetype -> __O1__4expr.tp ;
continue ;
case 6 :
# 221 "/home/claude/cfront-3/src/main.cpp"
{ 
# 222 "/home/claude/cfront-3/src/main.cpp"
Pclass __9cl ;

# 222 "/home/claude/cfront-3/src/main.cpp"
__9cl = (((struct classdef *)(((struct classdef *)__6tx ))));
if ((__9cl -> defined__4type & 3)&& (__9cl -> c_body__8classdef == 1 ))
# 228 "/home/claude/cfront-3/src/main.cpp"
dcl_print__8classdefFP4name ( __9cl , (struct name *)0 ) ;
break ;
}
}
break ;
}
dcl_print__4nameFUc ( __2nn , (unsigned char )0 ) ;

# 234 "/home/claude/cfront-3/src/main.cpp"
}

# 234 "/home/claude/cfront-3/src/main.cpp"
}
}
}
}
else 
# 239 "/home/claude/cfront-3/src/main.cpp"
dcl_print__4nameFUc ( __2nn , (unsigned char )0 ) ;

# 241 "/home/claude/cfront-3/src/main.cpp"
if (error_count )
# 242 "/home/claude/cfront-3/src/main.cpp"
continue ;

# 244 "/home/claude/cfront-3/src/main.cpp"
;
if (__2nn -> base__4node == 123 )continue ;
switch (__2nn -> __O1__4expr.tp -> base__4node ){ 
# 247 "/home/claude/cfront-3/src/main.cpp"
default :
# 248 "/home/claude/cfront-3/src/main.cpp"
{ 
# 249 "/home/claude/cfront-3/src/main.cpp"
Pexpr __5i ;

# 249 "/home/claude/cfront-3/src/main.cpp"
__5i = __2nn -> __O3__4expr.n_initializer ;
;
if (__5i && (__5i != (((struct expr *)1 )))){ 
# 252 "/home/claude/cfront-3/src/main.cpp"
if (__5i && (__5i -> permanent__4node == 0 ))del__4exprFv ( __5i ) ;
__2nn -> __O3__4expr.n_initializer = 0 ;
if ((def_name == 0 )&& (__3rr -> n_scope__4name != 31 )){ 
# 255 "/home/claude/cfront-3/src/main.cpp"
def_name = __3rr ;
}
}
break ;
}

# 261 "/home/claude/cfront-3/src/main.cpp"
case 108 :
# 262 "/home/claude/cfront-3/src/main.cpp"
{ 
# 263 "/home/claude/cfront-3/src/main.cpp"
if (__2nn -> n_oper__4name == 161 )break ;
{ Pfct __5f ;

# 264 "/home/claude/cfront-3/src/main.cpp"
__5f = (((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp ))));
;
if ((__5f -> body__3fct && (__5f -> f_inline__3fct == 0 ))&& (__5f -> f_imeasure__3fct == 0 )){ 
# 267 "/home/claude/cfront-3/src/main.cpp"
if (local_class = __5f -> local_class__3fct ){ 
# 268 "/home/claude/cfront-3/src/main.cpp"
delete_local__Fv (
# 268 "/home/claude/cfront-3/src/main.cpp"
) ;
local_class = 0 ;
}

# 272 "/home/claude/cfront-3/src/main.cpp"
if (ansi_opt && __5f -> f_this__3fct ){ 
# 273 "/home/claude/cfront-3/src/main.cpp"
__5f -> f_this__3fct -> __O4__4expr.n_table = 0 ;
{ { Pname __7n ;

# 274 "/home/claude/cfront-3/src/main.cpp"
__7n = __5f -> f_this__3fct -> __O1__4name.n_list ;

# 274 "/home/claude/cfront-3/src/main.cpp"
for(;__7n ;__7n = __7n -> __O1__4name.n_list ) 
# 275 "/home/claude/cfront-3/src/main.cpp"
__7n -> __O4__4expr.n_table = 0 ;

# 275 "/home/claude/cfront-3/src/main.cpp"
}

# 275 "/home/claude/cfront-3/src/main.cpp"
}
}

# 278 "/home/claude/cfront-3/src/main.cpp"
if (__5f -> body__3fct && (__5f -> body__3fct -> permanent__4node == 0 ))del__4stmtFv ( (struct stmt *)__5f -> body__3fct ) ;
if (def_name == 0 ){ 
# 280 "/home/claude/cfront-3/src/main.cpp"
def_name = __3rr ;
}
}
break ;

# 283 "/home/claude/cfront-3/src/main.cpp"
}
}

# 286 "/home/claude/cfront-3/src/main.cpp"
case 6 :
# 287 "/home/claude/cfront-3/src/main.cpp"
{ 
# 288 "/home/claude/cfront-3/src/main.cpp"
Pclass __5cl ;

# 288 "/home/claude/cfront-3/src/main.cpp"
__5cl = (((struct classdef *)(((struct classdef *)__2nn -> __O1__4expr.tp ))));
{ { Pname __5px ;

# 289 "/home/claude/cfront-3/src/main.cpp"
Pname __5p ;

# 289 "/home/claude/cfront-3/src/main.cpp"
__5p = __5cl -> mem_list__8classdef ;

# 289 "/home/claude/cfront-3/src/main.cpp"
for(;__5p ;__5p = __5px ) { 
# 290 "/home/claude/cfront-3/src/main.cpp"
__5px = __5p -> __O1__4name.n_list ;
__5p -> __O1__4name.n_list = 0 ;
if (__5p -> __O1__4expr.tp ){ 
# 293 "/home/claude/cfront-3/src/main.cpp"
switch (__5p -> __O1__4expr.tp -> base__4node ){ 
# 294 "/home/claude/cfront-3/src/main.cpp"
case 108 :
# 295 "/home/claude/cfront-3/src/main.cpp"
{ 
# 296 "/home/claude/cfront-3/src/main.cpp"
Pfct __9f ;

# 296 "/home/claude/cfront-3/src/main.cpp"
__9f = (((struct fct *)(((struct fct *)__5p -> __O1__4expr.tp ))));
if ((__9f -> body__3fct && (__9f -> f_inline__3fct == 0 ))&& (__9f -> f_imeasure__3fct == 0 )){ 
# 298 "/home/claude/cfront-3/src/main.cpp"
if (local_class = __9f -> local_class__3fct ){ 
# 299 "/home/claude/cfront-3/src/main.cpp"
delete_local__Fv (
# 299 "/home/claude/cfront-3/src/main.cpp"
) ;
local_class = 0 ;
}
if (__9f -> body__3fct && (__9f -> body__3fct -> permanent__4node == 0 ))del__4stmtFv ( (struct stmt *)__9f -> body__3fct ) ;
__9f -> body__3fct = 0 ;
}
}
case 6 :
# 307 "/home/claude/cfront-3/src/main.cpp"
case 13 :
# 308 "/home/claude/cfront-3/src/main.cpp"
case 97 :
# 309 "/home/claude/cfront-3/src/main.cpp"
break ;
case 119 :
# 311 "/home/claude/cfront-3/src/main.cpp"
case 121 :
# 312 "/home/claude/cfront-3/src/main.cpp"
if (__5p && (__5p -> permanent__4node == 0 ))del__4nameFv ( __5p ) ;
break ;
default :
# 315 "/home/claude/cfront-3/src/main.cpp"
( (__5p ?(((void )(__5p ?(((void )( ( ((((struct expr *)__5p ))?(((void )((((struct expr *)__5p ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 315 "/home/claude/cfront-3/src/main.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__5p , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
# 315 "/home/claude/cfront-3/src/main.cpp"

# 316 "/home/claude/cfront-3/src/main.cpp"
}
}
else { 
# 319 "/home/claude/cfront-3/src/main.cpp"
( (__5p ?(((void )(__5p ?(((void )( ( ((((struct expr *)__5p ))?(((void )((((struct expr *)__5p ))?(((void )(((void )0 )))):(((void )0 ))))):(((void
# 319 "/home/claude/cfront-3/src/main.cpp"
)0 )))) , (((void )__dl__4nameSFPvUl ( (void *)__5p , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 ))))
# 319 "/home/claude/cfront-3/src/main.cpp"
;
}
}
__5cl -> mem_list__8classdef = 0 ;
__5cl -> permanent__4node = 3 ;
break ;

# 324 "/home/claude/cfront-3/src/main.cpp"
}

# 324 "/home/claude/cfront-3/src/main.cpp"
}
}
}
if (__2nn && (__2nn -> permanent__4node == 0 ))del__4nameFv ( __2nn ) ;
Ntmp_dtor = 0 ;
}
lex_clear__Fv ( ) ;

# 330 "/home/claude/cfront-3/src/main.cpp"
}

# 330 "/home/claude/cfront-3/src/main.cpp"
}
}

# 333 "/home/claude/cfront-3/src/main.cpp"
end_of_compilation__17templ_compilationFv ( templp ) ;

# 335 "/home/claude/cfront-3/src/main.cpp"
if (error_count )
# 336 "/home/claude/cfront-3/src/main.cpp"
return ;

# 338 "/home/claude/cfront-3/src/main.cpp"
{ int __1i ;

# 338 "/home/claude/cfront-3/src/main.cpp"
__1i = 1 ;
{ { Pname __1m ;

# 340 "/home/claude/cfront-3/src/main.cpp"
struct table *__0__X42 ;

# 340 "/home/claude/cfront-3/src/main.cpp"
int __2__X43 ;

# 340 "/home/claude/cfront-3/src/main.cpp"
struct table *__0__X56 ;

# 339 "/home/claude/cfront-3/src/main.cpp"
__1m = ( (__0__X56 = gtbl ), ( (((__1i <= 0 )|| (__0__X56 -> free_slot__5table <= __1i ))?(((struct name *)0 )):(__0__X56 -> entries__5table [__1i ]))) ) ;
# 339 "/home/claude/cfront-3/src/main.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__0__X42 = gtbl ), ( (__2__X43 = (++ __1i )), ( (((__2__X43 <= 0 )|| (__0__X42 ->
# 339 "/home/claude/cfront-3/src/main.cpp"
free_slot__5table <= __2__X43 ))?(((struct name *)0 )):(__0__X42 -> entries__5table [__2__X43 ]))) ) ) )) { 
# 340 "/home/claude/cfront-3/src/main.cpp"
if (((__1m -> base__4node == 123 )|| (__1m -> n_sto__4name ==
# 340 "/home/claude/cfront-3/src/main.cpp"
14 ))|| (__1m -> n_stclass__4name == 13 ))
# 347 "/home/claude/cfront-3/src/main.cpp"
continue ;

# 349 "/home/claude/cfront-3/src/main.cpp"
{ Ptype __2t ;

# 349 "/home/claude/cfront-3/src/main.cpp"
__2t = __1m -> __O1__4expr.tp ;
if (__2t == 0 )
# 351 "/home/claude/cfront-3/src/main.cpp"
continue ;

# 353 "/home/claude/cfront-3/src/main.cpp"
switch (__2t -> base__4node ){ 
# 354 "/home/claude/cfront-3/src/main.cpp"
case 6 :
# 355 "/home/claude/cfront-3/src/main.cpp"
case 13 :
# 356 "/home/claude/cfront-3/src/main.cpp"
case 76 :
# 357 "/home/claude/cfront-3/src/main.cpp"
continue ;
case 119 :
# 359 "/home/claude/cfront-3/src/main.cpp"
case 110 :
# 360 "/home/claude/cfront-3/src/main.cpp"
break ;
case 108 :
# 362 "/home/claude/cfront-3/src/main.cpp"
if ((((struct fct *)(((struct fct *)__2t ))))-> f_inline__3fct || ((((struct fct *)(((struct fct *)__2t ))))-> body__3fct == 0 ))
# 363 "/home/claude/cfront-3/src/main.cpp"
continue ;
break ;
}

# 369 "/home/claude/cfront-3/src/main.cpp"
if (((__1m -> n_addr_taken__4name == 0 )&& (__1m -> n_used__4name == 0 ))&& (__1m -> n_sto__4name == 31 ))
# 375 "/home/claude/cfront-3/src/main.cpp"
{ 
# 376 "/home/claude/cfront-3/src/main.cpp"
for(;;) { 
# 378 "/home/claude/cfront-3/src/main.cpp"
if (__2t ->
# 378 "/home/claude/cfront-3/src/main.cpp"
base__4node == 97 ){ 
# 379 "/home/claude/cfront-3/src/main.cpp"
if (tconst__4typeFv ( __2t ) )
# 380 "/home/claude/cfront-3/src/main.cpp"
break ;
__2t = (((struct basetype *)(((struct basetype *)__2t ))))-> b_name__8basetype -> __O1__4expr.tp ;
}
else if (__2t -> base__4node == 110 ){ 
# 384 "/home/claude/cfront-3/src/main.cpp"
__2t = (((struct vec *)(((struct vec *)__2t ))))-> typ__5pvtyp ;
}
else { 
# 387 "/home/claude/cfront-3/src/main.cpp"
if (tconst__4typeFv ( __2t ) == 0 ){ 
# 389 "/home/claude/cfront-3/src/main.cpp"
if (__2t -> base__4node != 119 )
# 390 "/home/claude/cfront-3/src/main.cpp"
{ 
# 390 "/home/claude/cfront-3/src/main.cpp"
struct ea __0__V39 ;

# 390 "/home/claude/cfront-3/src/main.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1m -> where__4name , (const char *)"%n defined but not used", (const
# 390 "/home/claude/cfront-3/src/main.cpp"
struct ea *)( ((& __0__V39 )-> __O1__2ea.p = ((const void *)__1m )), (& __0__V39 )) , (const struct ea *)ea0 ,
# 390 "/home/claude/cfront-3/src/main.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 392 "/home/claude/cfront-3/src/main.cpp"
Pclass __7cl ;

# 392 "/home/claude/cfront-3/src/main.cpp"
__7cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__2t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if ((( __7cl -> c_ctor__8classdef ) == 0 )&& (__7cl -> csu__8classdef != 167 ))
# 394 "/home/claude/cfront-3/src/main.cpp"
{ 
# 394 "/home/claude/cfront-3/src/main.cpp"
struct ea __0__V40 ;

# 394 "/home/claude/cfront-3/src/main.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1m -> where__4name , (const char *)"%n defined but not used", (const
# 394 "/home/claude/cfront-3/src/main.cpp"
struct ea *)( ((& __0__V40 )-> __O1__2ea.p = ((const void *)__1m )), (& __0__V40 )) , (const struct ea *)ea0 ,
# 394 "/home/claude/cfront-3/src/main.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
break ;
}
}
}

# 400 "/home/claude/cfront-3/src/main.cpp"
}
}

# 403 "/home/claude/cfront-3/src/main.cpp"
{ Pname __1ctor ;
Pname __1dtor ;

# 403 "/home/claude/cfront-3/src/main.cpp"
__1ctor = 0 ;
__1dtor = 0 ;
-- curloc . line__3loc ;

# 407 "/home/claude/cfront-3/src/main.cpp"
if (st_ilist ){ 
# 409 "/home/claude/cfront-3/src/main.cpp"
;
{ Pname __2n ;
Pfct __2f ;

# 412 "/home/claude/cfront-3/src/main.cpp"
register struct block *__0__X44 ;

# 412 "/home/claude/cfront-3/src/main.cpp"
struct loc __2__X45 ;

# 412 "/home/claude/cfront-3/src/main.cpp"
struct stmt *__2__X46 ;

# 412 "/home/claude/cfront-3/src/main.cpp"
struct loc __2__X47 ;

# 410 "/home/claude/cfront-3/src/main.cpp"
__2n = __ct__4nameFPCc ( (struct name *)0 , (const char *)st_name__FPCc ( (const char *)"__sti__")
# 410 "/home/claude/cfront-3/src/main.cpp"
) ;
__2f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
__2n -> __O1__4expr.tp = (struct type *)__2f ;
__2f -> body__3fct = ( (__0__X44 = 0 ), ( (__2__X45 = st_ilist -> where__4stmt ), ( (__2__X46 = st_ilist ), ( (__2__X47 =
# 413 "/home/claude/cfront-3/src/main.cpp"
noloc ), ( ((__0__X44 || (__0__X44 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X44 = (struct
# 413 "/home/claude/cfront-3/src/main.cpp"
block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X44 ), (unsigned char )116 , __2__X45 , __2__X46 ) ), ( (__0__X44 -> __O1__4stmt.d = ((struct name *)0 )),
# 413 "/home/claude/cfront-3/src/main.cpp"
(__0__X44 -> __O3__4stmt.where2 = __2__X47 )) ) )):(((void )0 ))), __0__X44 ) ) ) ) ) ;
__2f -> body__3fct -> memtbl__4stmt = sti_tbl ;
__2n -> n_sto__4name = 14 ;
ignore_const ++ ;
__2f -> f_linkage__3fct = 1;
sign__3fctFv ( __2f ) ;
((void )dcl__4nameFP5tableUc ( __2n , gtbl , (unsigned char )14 ) );
ignore_const -- ;
simpl__4nameFv ( __2n ) ;
dcl_print__4nameFUc ( __2n , (unsigned char )0 ) ;
__1ctor = __2n ;

# 423 "/home/claude/cfront-3/src/main.cpp"
}
}

# 426 "/home/claude/cfront-3/src/main.cpp"
if (st_dlist ){ 
# 428 "/home/claude/cfront-3/src/main.cpp"
;
{ Pname __2n ;
Pfct __2f ;

# 431 "/home/claude/cfront-3/src/main.cpp"
register struct block *__0__X48 ;

# 431 "/home/claude/cfront-3/src/main.cpp"
struct loc __2__X49 ;

# 431 "/home/claude/cfront-3/src/main.cpp"
struct stmt *__2__X50 ;

# 431 "/home/claude/cfront-3/src/main.cpp"
struct loc __2__X51 ;

# 429 "/home/claude/cfront-3/src/main.cpp"
__2n = __ct__4nameFPCc ( (struct name *)0 , (const char *)st_name__FPCc ( (const char *)"__std__")
# 429 "/home/claude/cfront-3/src/main.cpp"
) ;
__2f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
__2n -> __O1__4expr.tp = (struct type *)__2f ;
__2f -> body__3fct = ( (__0__X48 = 0 ), ( (__2__X49 = st_dlist -> where__4stmt ), ( (__2__X50 = st_dlist ), ( (__2__X51 =
# 432 "/home/claude/cfront-3/src/main.cpp"
noloc ), ( ((__0__X48 || (__0__X48 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X48 = (struct
# 432 "/home/claude/cfront-3/src/main.cpp"
block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X48 ), (unsigned char )116 , __2__X49 , __2__X50 ) ), ( (__0__X48 -> __O1__4stmt.d = ((struct name *)0 )),
# 432 "/home/claude/cfront-3/src/main.cpp"
(__0__X48 -> __O3__4stmt.where2 = __2__X51 )) ) )):(((void )0 ))), __0__X48 ) ) ) ) ) ;
__2f -> body__3fct -> memtbl__4stmt = std_tbl ;
__2n -> n_sto__4name = 14 ;
__2f -> f_linkage__3fct = 1;
sign__3fctFv ( __2f ) ;
((void )dcl__4nameFP5tableUc ( __2n , gtbl , (unsigned char )14 ) );
simpl__4nameFv ( __2n ) ;
dcl_print__4nameFUc ( __2n , (unsigned char )0 ) ;
__1dtor = __2n ;

# 440 "/home/claude/cfront-3/src/main.cpp"
}
}

# 465 "/home/claude/cfront-3/src/main.cpp"
;
do { 
# 467 "/home/claude/cfront-3/src/main.cpp"
{ { struct vl *__2v ;

# 467 "/home/claude/cfront-3/src/main.cpp"
__2v = vlist ;

# 467 "/home/claude/cfront-3/src/main.cpp"
for(;__2v ;__2v = __2v -> next__2vl ) 
# 468 "/home/claude/cfront-3/src/main.cpp"
really_print__8classdefFP4virt ( __2v -> cl__2vl , __2v -> vt__2vl ) ;
vlist = 0 ;

# 471 "/home/claude/cfront-3/src/main.cpp"
{ { Plist __2l ;

# 471 "/home/claude/cfront-3/src/main.cpp"
__2l = isf_list ;

# 471 "/home/claude/cfront-3/src/main.cpp"
for(;__2l ;__2l = __2l -> l__9name_list ) { 
# 472 "/home/claude/cfront-3/src/main.cpp"
Pname __3n ;
Pfct __3f ;

# 472 "/home/claude/cfront-3/src/main.cpp"
__3n = __2l -> f__9name_list ;
__3f = (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))));
;
if (__3f -> base__4node == 76 ){ 
# 476 "/home/claude/cfront-3/src/main.cpp"
__3n = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen -> f__9name_list ;
__3f = (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))));
}

# 480 "/home/claude/cfront-3/src/main.cpp"
if ((debug_opt == 0 )&& __3n -> n_addr_taken__4name ){ 
# 481 "/home/claude/cfront-3/src/main.cpp"
__3f -> f_inline__3fct = 0 ;
if (__3n -> n_dcl_printed__4name < 2 ){ 
# 483 "/home/claude/cfront-3/src/main.cpp"
if (__3f -> fct_base__3fct == 4)
# 484 "/home/claude/cfront-3/src/main.cpp"
current_fct_instantiation = __3f ;
if (warning_opt )
# 486 "/home/claude/cfront-3/src/main.cpp"
{ 
# 486 "/home/claude/cfront-3/src/main.cpp"
struct ea __0__V41 ;

# 486 "/home/claude/cfront-3/src/main.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"out-of-line copy of%n created", (const struct ea *)( ((&
# 486 "/home/claude/cfront-3/src/main.cpp"
__0__V41 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V41 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 486 "/home/claude/cfront-3/src/main.cpp"
(const struct ea *)ea0 ) ;
} dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
if (__3f -> fct_base__3fct == 4)
# 489 "/home/claude/cfront-3/src/main.cpp"
current_fct_instantiation = 0 ;
}
}
}

# 492 "/home/claude/cfront-3/src/main.cpp"
}

# 492 "/home/claude/cfront-3/src/main.cpp"
}

# 492 "/home/claude/cfront-3/src/main.cpp"
}

# 492 "/home/claude/cfront-3/src/main.cpp"
}
}
while (vlist );
if (strict_opt == 0 ){ 
# 497 "/home/claude/cfront-3/src/main.cpp"
{ { Plist __2l ;

# 497 "/home/claude/cfront-3/src/main.cpp"
__2l = stat_mem_list ;

# 497 "/home/claude/cfront-3/src/main.cpp"
for(;__2l ;__2l = __2l -> l__9name_list ) { 
# 499 "/home/claude/cfront-3/src/main.cpp"
Pname __3n ;

# 499 "/home/claude/cfront-3/src/main.cpp"
__3n = __2l -> f__9name_list ;
if (ispt_data__FP4name ( __3n ) )
# 501 "/home/claude/cfront-3/src/main.cpp"
continue ;

# 503 "/home/claude/cfront-3/src/main.cpp"
if ((__3n -> __O3__4expr.n_initializer == 0 )&& (__3n -> n_evaluated__4name == 0 )){ 
# 504 "/home/claude/cfront-3/src/main.cpp"
Ptype __4t ;

# 504 "/home/claude/cfront-3/src/main.cpp"
__4t = __3n -> __O1__4expr.tp ;
__3n -> n_sto__4name = 0 ;
{ Pname __4cn ;

# 507 "/home/claude/cfront-3/src/main.cpp"
struct classdef *__0__X52 ;

# 506 "/home/claude/cfront-3/src/main.cpp"
__4cn = is_cl_obj__4typeFv ( __4t ) ;
if (__4cn == 0 )
# 508 "/home/claude/cfront-3/src/main.cpp"
__4cn = cl_obj_vec ;

# 510 "/home/claude/cfront-3/src/main.cpp"
if (__4cn && ((((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))))-> defined__4type & 3))
# 511 "/home/claude/cfront-3/src/main.cpp"
{ 
# 512 "/home/claude/cfront-3/src/main.cpp"
fake_sizeof = 1 ;
{ struct loc __5oldloc ;

# 513 "/home/claude/cfront-3/src/main.cpp"
__5oldloc = curloc ;
curloc = __3n -> where__4name ;
((void )tsizeof__4typeFi ( __4t , 0 ) );
curloc = __5oldloc ;

# 518 "/home/claude/cfront-3/src/main.cpp"
fake_sizeof = 0 ;

# 518 "/home/claude/cfront-3/src/main.cpp"
}
}

# 524 "/home/claude/cfront-3/src/main.cpp"
if (__4cn && ((( (__0__X52 = (((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))))), ( __0__X52 -> c_ctor__8classdef ) ) || is_ref__4typeFv (
# 524 "/home/claude/cfront-3/src/main.cpp"
__4t ) )|| (((((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))))-> defined__4type & 3)== 0 )))
# 534 "/home/claude/cfront-3/src/main.cpp"
;
else { 
# 536 "/home/claude/cfront-3/src/main.cpp"
if ((__3n -> __O1__4expr.tp -> base__4node == 110 )&& ((((struct vec *)(((struct vec *)__3n -> __O1__4expr.tp ))))-> size__3vec == 0 ))
# 537 "/home/claude/cfront-3/src/main.cpp"
;
else { 
# 539 "/home/claude/cfront-3/src/main.cpp"
struct loc __6oldloc ;

# 539 "/home/claude/cfront-3/src/main.cpp"
__6oldloc = curloc ;
curloc = __3n -> where__4name ;
fake_sizeof = 1 ;
dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
fake_sizeof = 0 ;
curloc = __6oldloc ;
}
}

# 546 "/home/claude/cfront-3/src/main.cpp"
}

# 549 "/home/claude/cfront-3/src/main.cpp"
}
}

# 550 "/home/claude/cfront-3/src/main.cpp"
}

# 550 "/home/claude/cfront-3/src/main.cpp"
}
}

# 553 "/home/claude/cfront-3/src/main.cpp"
__1i = 1 ;
{ { Pname __1nm ;

# 555 "/home/claude/cfront-3/src/main.cpp"
struct table *__0__X53 ;

# 555 "/home/claude/cfront-3/src/main.cpp"
int __2__X54 ;

# 555 "/home/claude/cfront-3/src/main.cpp"
struct table *__0__X55 ;

# 554 "/home/claude/cfront-3/src/main.cpp"
__1nm = ( (__0__X55 = ptbl ), ( (((__1i <= 0 )|| (__0__X55 -> free_slot__5table <= __1i ))?(((struct name *)0 )):(__0__X55 -> entries__5table [__1i ]))) ) ;
# 554 "/home/claude/cfront-3/src/main.cpp"
for(;__1nm ;__1nm = (__1nm -> n_tbl_list__4name ?__1nm -> n_tbl_list__4name :( (__0__X53 = ptbl ), ( (__2__X54 = (++ __1i )), ( (((__2__X54 <= 0 )|| (__0__X53 ->
# 554 "/home/claude/cfront-3/src/main.cpp"
free_slot__5table <= __2__X54 ))?(((struct name *)0 )):(__0__X53 -> entries__5table [__2__X54 ]))) ) ) )) { 
# 555 "/home/claude/cfront-3/src/main.cpp"
;
if (__1nm -> n_key__4name == 0 ){ 
# 557 "/home/claude/cfront-3/src/main.cpp"
int __3str1 ;
int __3str2 ;
char *__3ps ;

# 557 "/home/claude/cfront-3/src/main.cpp"
__3str1 = (((*src_file_name ))?(strlen ( src_file_name ) + 2 ):(((unsigned long )0 )));
__3str2 = (strlen ( __1nm -> __O3__4expr.string2 ) - __3str1 );
__3ps = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (__3str2 + 1 ))) ));
strncpy ( __3ps , __1nm -> __O3__4expr.string2 , (unsigned long )__3str2 ) ;
(__3ps [__3str2 ])= '\0' ;
(__3ps [2 ])= 'v' ;
fprintf ( out_file , (const char *)"extern struct __mptr %s[];\n", __3ps ) ;
ptbl_add_pair__FPCcT1 ( __1nm -> __O3__4expr.string2 , (const char *)__3ps ) ;
__dl__FPv ( (void *)__3ps ) ;
}
}

# 569 "/home/claude/cfront-3/src/main.cpp"
ptbl_init__Fi ( 1 ) ;
putline__3locFv ( & curloc ) ;
fprintf ( out_file , (const char *)"\n/* the end */\n") ;

# 571 "/home/claude/cfront-3/src/main.cpp"
}

# 571 "/home/claude/cfront-3/src/main.cpp"
}

# 571 "/home/claude/cfront-3/src/main.cpp"
}

# 571 "/home/claude/cfront-3/src/main.cpp"
}

# 571 "/home/claude/cfront-3/src/main.cpp"
}

# 571 "/home/claude/cfront-3/src/main.cpp"
}
}

# 492 "/home/claude/cfront-3/src/template.h"

# 574 "/home/claude/cfront-3/src/main.cpp"
void set_flags__Fv (void )
# 575 "/home/claude/cfront-3/src/main.cpp"
{ 
# 576 "/home/claude/cfront-3/src/main.cpp"
all_flag = 0 ;
alltc_flag = 0 ;
data_flag = 0 ;
ft_flag = 0 ;
none_flag = 0 ;
{ { int __1i ;

# 581 "/home/claude/cfront-3/src/main.cpp"
__1i = 0 ;

# 581 "/home/claude/cfront-3/src/main.cpp"
for(;__1i < noinst ;__1i ++ ) { 
# 581 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X57 ;

# 581 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X58 ;

# 581 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X59 ;

# 581 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X60 ;

# 581 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X61 ;

# 582 "/home/claude/cfront-3/src/main.cpp"
if (strcmp ( (const char *)"@all", (const char *)((*( (__0__X57 = (&
# 582 "/home/claude/cfront-3/src/main.cpp"
instfct )), ( (((Pchar *)(& (__0__X57 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 583 "/home/claude/cfront-3/src/main.cpp"
all_flag = 1 ;
if (strcmp ( (const char *)"@alltc", (const char *)((*( (__0__X58 = (&
# 584 "/home/claude/cfront-3/src/main.cpp"
instfct )), ( (((Pchar *)(& (__0__X58 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 585 "/home/claude/cfront-3/src/main.cpp"
alltc_flag = 1 ;
if (strcmp ( (const char *)"@data", (const char *)((*( (__0__X59 = (&
# 586 "/home/claude/cfront-3/src/main.cpp"
instfct )), ( (((Pchar *)(& (__0__X59 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 587 "/home/claude/cfront-3/src/main.cpp"
data_flag = 1 ;
if (strcmp ( (const char *)"@ft", (const char *)((*( (__0__X60 = (&
# 588 "/home/claude/cfront-3/src/main.cpp"
instfct )), ( (((Pchar *)(& (__0__X60 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 589 "/home/claude/cfront-3/src/main.cpp"
ft_flag = 1 ;
if (strcmp ( (const char *)"@none", (const char *)((*( (__0__X61 = (&
# 590 "/home/claude/cfront-3/src/main.cpp"
instfct )), ( (((Pchar *)(& (__0__X61 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 591 "/home/claude/cfront-3/src/main.cpp"
none_flag = 1 ;
}

# 592 "/home/claude/cfront-3/src/main.cpp"
}

# 592 "/home/claude/cfront-3/src/main.cpp"
}
}

# 88 "/usr/include/signal.h"
extern __sighandler_t signal (int __0__sig , __sighandler_t __0__handler );

# 105 "/home/claude/cfront-3/src/main.cpp"
extern void error_init__Fv (void );

# 12 "/home/claude/incl-linux32/stdlib.h"
extern int atoi (const char *);

# 1244 "/home/claude/cfront-3/src/cfront.h"
extern int read_align__FPCc (const char *);

# 15 "/home/claude/incl-linux32/stdlib.h"
extern void exit (int );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 64 "/home/claude/incl-linux32/stdio.h"
extern void *fopen (const char *, const char *);

# 82 "/home/claude/incl-linux32/stdio.h"
extern int fscanf (void *, const char *,...);

# 492 "/home/claude/cfront-3/src/template.h"

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 492 "/home/claude/cfront-3/src/template.h"

# 87 "/home/claude/incl-linux32/stdio.h"
extern int fflush (void *__0stream );

# 49 "/home/claude/cfront-3/src/token.h"
extern void otbl_init__Fv (void );

# 104 "/home/claude/cfront-3/src/main.cpp"
extern void lex_init__Fv (void );

# 103 "/home/claude/cfront-3/src/main.cpp"
extern void syn_init__Fv (void );

# 102 "/home/claude/cfront-3/src/main.cpp"
extern void typ_init__Fv (void );

# 101 "/home/claude/cfront-3/src/main.cpp"
extern void simpl_init__Fv (void );

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 658 "/home/claude/cfront-3/src/main.cpp"
int main (int __1argc , char **__1argv ){ extern void _main(); _main();
# 662 "/home/claude/cfront-3/src/main.cpp"
{ 
# 663 "/home/claude/cfront-3/src/main.cpp"
char *__1cp ;
const char *__1afile ;

# 676 "/home/claude/cfront-3/src/main.cpp"
void (*__1sick )(int ,...);

# 675 "/home/claude/cfront-3/src/main.cpp"

# 664 "/home/claude/cfront-3/src/main.cpp"
__1afile = (const char *)"";

# 676 "/home/claude/cfront-3/src/main.cpp"
__1sick = (((void (*)(int ,...))(signal )));
((*__1sick ))( 4 , core_dump__Fi ) ;
((*__1sick ))( 6 , core_dump__Fi ) ;

# 680 "/home/claude/cfront-3/src/main.cpp"
((*__1sick ))( 8 , core_dump__Fi ) ;
((*__1sick ))( 7 , core_dump__Fi ) ;
((*__1sick ))( 11 , core_dump__Fi ) ;

# 687 "/home/claude/cfront-3/src/main.cpp"
error_init__Fv ( ) ;

# 692 "/home/claude/cfront-3/src/main.cpp"
{ { int __1i ;

# 692 "/home/claude/cfront-3/src/main.cpp"
__1i = 1 ;

# 692 "/home/claude/cfront-3/src/main.cpp"
for(;__1i < __1argc ;++ __1i ) { 
# 693 "/home/claude/cfront-3/src/main.cpp"
switch ((*(__1cp = (__1argv [__1i ])))){ 
# 694 "/home/claude/cfront-3/src/main.cpp"
case '+' :
# 695 "/home/claude/cfront-3/src/main.cpp"
while ((*(++ __1cp ))){ 
# 696 "/home/claude/cfront-3/src/main.cpp"
switch ((*__1cp )){ 
# 705 "/home/claude/cfront-3/src/main.cpp"
extern
# 705 "/home/claude/cfront-3/src/main.cpp"
int size_complexity_measure ;

# 706 "/home/claude/cfront-3/src/main.cpp"
const void *__2__X63 ;

# 697 "/home/claude/cfront-3/src/main.cpp"
case 'U' :
# 698 "/home/claude/cfront-3/src/main.cpp"
dem_opt_local = 1 ;
dem_opt_mem = 1 ;
break ;
case 'I' :
# 702 "/home/claude/cfront-3/src/main.cpp"
inline_opt = 1 ;
break ;
case 'J' :
# 705 "/home/claude/cfront-3/src/main.cpp"
;
size_complexity_measure = atoi ( (const char *)(__1cp + 1 )) ;
while ((*(++ __1cp )))
# 708 "/home/claude/cfront-3/src/main.cpp"
;
__1cp -- ;
break ;
case 'f' :
# 712 "/home/claude/cfront-3/src/main.cpp"
src_file_name = (const char *)(__1cp + 1 );
goto xx ;
case 'x' :
# 715 "/home/claude/cfront-3/src/main.cpp"
if (read_align__FPCc ( __1afile = (const char *)(__1cp + 1 )) ){ 
# 716 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const
# 716 "/home/claude/cfront-3/src/main.cpp"
char *)"bad size-table (option +x)\n") ;
exit ( 11 ) ;
}
goto xx ;
case 'e' :
# 721 "/home/claude/cfront-3/src/main.cpp"
switch ((*(++ __1cp ))){ 
# 722 "/home/claude/cfront-3/src/main.cpp"
case '0' :
# 723 "/home/claude/cfront-3/src/main.cpp"
case '1' :
# 724 "/home/claude/cfront-3/src/main.cpp"
vtbl_opt = (((*__1cp ))- '0' );
break ;
default :
# 727 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"bad +e option\n") ;
exit ( 11 ) ;
}
break ;
case 'd' :
# 732 "/home/claude/cfront-3/src/main.cpp"
debug_opt = 1 ;
break ;
case 'g' :
# 735 "/home/claude/cfront-3/src/main.cpp"
gplus_opt = 1 ;
break ;
case 'D' :
# 741 "/home/claude/cfront-3/src/main.cpp"
{ 
# 741 "/home/claude/cfront-3/src/main.cpp"
struct ea __0__V62 ;

# 741 "/home/claude/cfront-3/src/main.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"cfront not compiled for debugging -- +D%s ignored", (const struct ea *)( (__2__X63 =
# 741 "/home/claude/cfront-3/src/main.cpp"
(const void *)(++ __1cp )), ( ((& __0__V62 )-> __O1__2ea.p = __2__X63 ), (& __0__V62 )) ) , (const
# 741 "/home/claude/cfront-3/src/main.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 743 "/home/claude/cfront-3/src/main.cpp"
goto xx ;
case 'w' :
# 745 "/home/claude/cfront-3/src/main.cpp"
warning_opt = 1 ;
break ;
case 'a' :
# 748 "/home/claude/cfront-3/src/main.cpp"
switch ((*(++ __1cp ))){ 
# 749 "/home/claude/cfront-3/src/main.cpp"
case '0' :
# 750 "/home/claude/cfront-3/src/main.cpp"
case '1' :
# 751 "/home/claude/cfront-3/src/main.cpp"
ansi_opt = (((*__1cp ))- '0' );
break ;
default :
# 754 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"bad +a option\n") ;
exit ( 11 ) ;
}
break ;
case 'p' :
# 759 "/home/claude/cfront-3/src/main.cpp"
strict_opt = 1 ;
break ;
case 'L' :
# 762 "/home/claude/cfront-3/src/main.cpp"
if (((*(__1cp + 1 )))== 'c' ){ 
# 763 "/home/claude/cfront-3/src/main.cpp"
++ __1cp ;
line_format = (const char *)"\n/*#line %d \"%s\"*/\n";
}
else line_format = (const char *)"\n#line %d \"%s\"\n";
break ;
case 's' :
# 769 "/home/claude/cfront-3/src/main.cpp"
se_opt = 1 ;
break ;
case 't' :
# 772 "/home/claude/cfront-3/src/main.cpp"
pt_opt = 1 ;
pt_file = fopen ( (const char *)(__1cp + 1 ), (const char *)"w") ;
# 773 "/home/claude/cfront-3/src/main.cpp"

# 774 "/home/claude/cfront-3/src/main.cpp"
if (pt_file == 0 ){ 
# 775 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"Failed to open %s\n",
# 775 "/home/claude/cfront-3/src/main.cpp"
__1cp + 1 ) ;
exit ( 11 ) ;
}
goto xx ;
case 'i' :
# 780 "/home/claude/cfront-3/src/main.cpp"
in_file = fopen ( (const char *)(__1cp + 1 ), (const char *)"r")
# 780 "/home/claude/cfront-3/src/main.cpp"
;
if (in_file == 0 ){ 
# 782 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"Failed to open %s\n",
# 782 "/home/claude/cfront-3/src/main.cpp"
__1cp + 1 ) ;
exit ( 11 ) ;
}
goto xx ;
case 'T' :
# 787 "/home/claude/cfront-3/src/main.cpp"
{ 
# 788 "/home/claude/cfront-3/src/main.cpp"
dtpt_opt = 1 ;
dtpt_file = fopen ( (const char *)(__1cp + 1 ), (const char *)"r") ;
# 789 "/home/claude/cfront-3/src/main.cpp"

# 790 "/home/claude/cfront-3/src/main.cpp"
if (dtpt_file == 0 ){ 
# 791 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"Failed to open %s\n",
# 791 "/home/claude/cfront-3/src/main.cpp"
__1cp + 1 ) ;
exit ( 11 ) ;
}
{ char __6tempstring [1024];
noinst = 0 ;
while (fscanf ( dtpt_file , (const char *)"%s", __6tempstring ) != -1){ 
# 796 "/home/claude/cfront-3/src/main.cpp"
struct
# 796 "/home/claude/cfront-3/src/main.cpp"
Block_Pchar *__0__X64 ;

# 796 "/home/claude/cfront-3/src/main.cpp"
unsigned long __2__X65 ;

# 796 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X66 ;

# 796 "/home/claude/cfront-3/src/main.cpp"
int __2__X67 ;

# 796 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X68 ;

# 796 "/home/claude/cfront-3/src/main.cpp"
int __2__X69 ;

# 797 "/home/claude/cfront-3/src/main.cpp"
( (__0__X64 = (& instfct )), ( (__2__X65 = noinst ), ( ((__2__X65 < __0__X64 -> n__11Block_Pchar )|| grow__11Block_PcharFUl ( __0__X64 , __2__X65 )
# 797 "/home/claude/cfront-3/src/main.cpp"
)) ) ) ;
((*( (__0__X66 = (& instfct )), ( (__2__X67 = noinst ), ( (((Pchar *)(& (__0__X66 -> p__11Block_Pchar [__2__X67 ]))))) ) ) ))=
# 798 "/home/claude/cfront-3/src/main.cpp"
(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( (const char *)__6tempstring ) + 1 ))) ));
# 798 "/home/claude/cfront-3/src/main.cpp"

# 799 "/home/claude/cfront-3/src/main.cpp"
strcpy ( (*( (__0__X68 = (& instfct )), ( (__2__X69 = noinst ), ( (((Pchar *)(& (__0__X68 -> p__11Block_Pchar [__2__X69 ]))))) ) )
# 799 "/home/claude/cfront-3/src/main.cpp"
), (const char *)__6tempstring ) ;
noinst ++ ;
if (strcmp ( (const char *)__6tempstring , (const char *)"@data") == 0 ){
# 801 "/home/claude/cfront-3/src/main.cpp"

# 802 "/home/claude/cfront-3/src/main.cpp"
bit __8EOLflag ;
char __8c ;

# 802 "/home/claude/cfront-3/src/main.cpp"
__8EOLflag = 0 ;

# 804 "/home/claude/cfront-3/src/main.cpp"
nodatainst = 0 ;
{ int __8index ;
char __8ntempstring [1024];

# 805 "/home/claude/cfront-3/src/main.cpp"
__8index = 0 ;

# 807 "/home/claude/cfront-3/src/main.cpp"
while ((__8EOLflag == 0 )&& (fscanf ( dtpt_file , (const char *)"%c", & __8c )
# 807 "/home/claude/cfront-3/src/main.cpp"
!= -1))
# 808 "/home/claude/cfront-3/src/main.cpp"
{ 
# 809 "/home/claude/cfront-3/src/main.cpp"
switch (__8c ){ 
# 809 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X74 ;

# 809 "/home/claude/cfront-3/src/main.cpp"
unsigned long __2__X75 ;

# 810 "/home/claude/cfront-3/src/main.cpp"
case '\n' :
# 811 "/home/claude/cfront-3/src/main.cpp"
__8EOLflag = 1 ;
case ' ' :
# 813 "/home/claude/cfront-3/src/main.cpp"
case '\t' :
# 814 "/home/claude/cfront-3/src/main.cpp"
(__8ntempstring [__8index ])= '\0' ;
if (__8index != 0 ){ 
# 815 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X70 ;

# 815 "/home/claude/cfront-3/src/main.cpp"
int __2__X71 ;

# 815 "/home/claude/cfront-3/src/main.cpp"
struct Block_Pchar *__0__X72 ;

# 815 "/home/claude/cfront-3/src/main.cpp"
int __2__X73 ;

# 816 "/home/claude/cfront-3/src/main.cpp"
((*( (__0__X70 = (& instdata )), ( (__2__X71 = nodatainst ), ( (((Pchar *)(& (__0__X70 -> p__11Block_Pchar [__2__X71 ]))))) ) ) ))=
# 816 "/home/claude/cfront-3/src/main.cpp"
(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( (const char *)__8ntempstring ) + 1 ))) ));
# 816 "/home/claude/cfront-3/src/main.cpp"

# 817 "/home/claude/cfront-3/src/main.cpp"
strcpy ( (*( (__0__X72 = (& instdata )), ( (__2__X73 = nodatainst ), ( (((Pchar *)(& (__0__X72 -> p__11Block_Pchar [__2__X73 ]))))) ) )
# 817 "/home/claude/cfront-3/src/main.cpp"
), (const char *)__8ntempstring ) ;
nodatainst ++ ;
}
__8index = 0 ;
break ;
default :
# 823 "/home/claude/cfront-3/src/main.cpp"
if (__8index == 0 )( (__0__X74 = (& instdata )), ( (__2__X75 = nodatainst ), ( ((__2__X75 < __0__X74 -> n__11Block_Pchar )||
# 823 "/home/claude/cfront-3/src/main.cpp"
grow__11Block_PcharFUl ( __0__X74 , __2__X75 ) )) ) ) ;
(__8ntempstring [__8index ])= __8c ;
__8index ++ ;
break ;
}
}

# 828 "/home/claude/cfront-3/src/main.cpp"
}
}
}

# 830 "/home/claude/cfront-3/src/main.cpp"
;
set_flags__Fv ( ) ;

# 831 "/home/claude/cfront-3/src/main.cpp"
}
}
goto xx ;
default :
# 835 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"%s: unexpected option: +%c ignored\n", prog_name , (*__1cp ))
# 835 "/home/claude/cfront-3/src/main.cpp"
;
} 
# 837 "/home/claude/cfront-3/src/main.cpp"
}
}
xx :
# 840 "/home/claude/cfront-3/src/main.cpp"
break ;
default :
# 842 "/home/claude/cfront-3/src/main.cpp"
fprintf ( _get_stderr ( ) , (const char *)"%s: bad argument \"%s\"\n", prog_name , __1cp )
# 842 "/home/claude/cfront-3/src/main.cpp"
;
exit ( 11 ) ;
}
}

# 848 "/home/claude/cfront-3/src/main.cpp"
fprintf ( out_file , line_format + 1 , 1 , src_file_name ) ;
fprintf ( out_file , (const char *)"\n/* %s */\n", prog_name ) ;
fprintf ( out_file , (const char *)"char %s;\n", prog_vers ) ;
if ((*src_file_name ))
# 852 "/home/claude/cfront-3/src/main.cpp"
fprintf ( out_file , (const char *)"/* < %s > */\n", src_file_name ) ;

# 854 "/home/claude/cfront-3/src/main.cpp"
otbl_init__Fv ( ) ;
lex_init__Fv ( ) ;
syn_init__Fv ( ) ;
typ_init__Fv ( ) ;
simpl_init__Fv ( ) ;
ptbl_init__Fi ( 0 ) ;
scan_started = 1 ;
putline__3locFv ( & curloc ) ;
if (((BI_IN_BYTE == 0 )&& (SZ_INT == 0 ))&& (SZ_WPTR == 0 ))
# 864 "/home/claude/cfront-3/src/main.cpp"
error__FPCc ( (const char *)"no size/alignment values - use +x of provide #ifdef in size.h")
# 864 "/home/claude/cfront-3/src/main.cpp"
;
run__Fv ( ) ;

# 867 "/home/claude/cfront-3/src/main.cpp"
exit ( ((0 <= error_count )&& (error_count < 127 ))?error_count :127 ) ;

# 867 "/home/claude/cfront-3/src/main.cpp"
}

# 867 "/home/claude/cfront-3/src/main.cpp"
}
}
} 
# 37 "/home/claude/incl-linux32/ctype.h"
extern int isalpha (int );

# 39 "/home/claude/incl-linux32/ctype.h"
extern int isdigit (int );

# 870 "/home/claude/cfront-3/src/main.cpp"
char *st_name__FPCc (const char *__1pref )
# 876 "/home/claude/cfront-3/src/main.cpp"
{ 
# 877 "/home/claude/cfront-3/src/main.cpp"
int __1prefl ;
int __1strl ;

# 881 "/home/claude/cfront-3/src/main.cpp"
const char *__1defs ;
int __1defl ;

# 877 "/home/claude/cfront-3/src/main.cpp"
__1prefl = strlen ( __1pref ) ;
__1strl = (__1prefl + 2 );
if ((*src_file_name ))
# 880 "/home/claude/cfront-3/src/main.cpp"
__1strl += strlen ( src_file_name ) ;
;

# 881 "/home/claude/cfront-3/src/main.cpp"
;

# 883 "/home/claude/cfront-3/src/main.cpp"
if (def_name ){ 
# 884 "/home/claude/cfront-3/src/main.cpp"
__1defs = def_name -> __O2__4expr.string ;
__1defl = (strlen ( __1defs ) + 1 );
}
else { 
# 888 "/home/claude/cfront-3/src/main.cpp"
__1defs = 0 ;
__1defl = 0 ;
}
{ char *__1name ;

# 891 "/home/claude/cfront-3/src/main.cpp"
__1name = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (__1strl + __1defl ))) ));
strcpy ( __1name , __1pref ) ;
if ((*src_file_name ))
# 894 "/home/claude/cfront-3/src/main.cpp"
strcpy ( __1name + __1prefl , src_file_name ) ;
(__1name [(__1strl - 2 )])= '_' ;
(__1name [(__1strl - 1 )])= 0 ;
{ { char *__1p ;

# 897 "/home/claude/cfront-3/src/main.cpp"
__1p = __1name ;

# 897 "/home/claude/cfront-3/src/main.cpp"
for(;(*__1p );__1p ++ ) 
# 898 "/home/claude/cfront-3/src/main.cpp"
if ((! isalpha ( (int )((*__1p ))) )&& (! isdigit ( (int )((*__1p ))) ))
# 899 "/home/claude/cfront-3/src/main.cpp"
((*__1p ))= '_' ;
# 899 "/home/claude/cfront-3/src/main.cpp"

# 900 "/home/claude/cfront-3/src/main.cpp"
if (__1defs ){ 
# 901 "/home/claude/cfront-3/src/main.cpp"
strcpy ( (__1name + __1strl )- 1 , __1defs ) ;
(__1name [((__1strl + __1defl )- 2 )])= '_' ;
(__1name [((__1strl + __1defl )- 1 )])= 0 ;
}

# 910 "/home/claude/cfront-3/src/main.cpp"
return __1name ;

# 910 "/home/claude/cfront-3/src/main.cpp"
}

# 910 "/home/claude/cfront-3/src/main.cpp"
}

# 910 "/home/claude/cfront-3/src/main.cpp"
}
}

# 911 "/home/claude/cfront-3/src/main.cpp"
void __sti___prog_name_ (void )
# 493 "/home/claude/cfront-3/src/template.h"
{ 
# 493 "/home/claude/cfront-3/src/template.h"
struct Block_Pchar *__0__X76 ;

# 493 "/home/claude/cfront-3/src/template.h"
struct Block_Pchar *__0__X77 ;

# 493 "/home/claude/cfront-3/src/template.h"
( (__0__X76 = (& instfct )), ( ((__0__X76 || (__0__X76 = (struct Block_Pchar *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Pchar))) ))?(
# 493 "/home/claude/cfront-3/src/template.h"
(__0__X76 -> n__11Block_Pchar = 0 ), (__0__X76 -> p__11Block_Pchar = 0 )) :0 ), __0__X76 ) ) ;

# 495 "/home/claude/cfront-3/src/template.h"
( (__0__X77 = (& instdata )), ( ((__0__X77 || (__0__X77 = (struct Block_Pchar *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Pchar))) ))?(
# 495 "/home/claude/cfront-3/src/template.h"
(__0__X77 -> n__11Block_Pchar = 0 ), (__0__X77 -> p__11Block_Pchar = 0 )) :0 ), __0__X77 ) ) ;

# 495 "/home/claude/cfront-3/src/template.h"
}

# 911 "/home/claude/cfront-3/src/main.cpp"
void __std___prog_name_ (void )
# 495 "/home/claude/cfront-3/src/template.h"
{ 
# 495 "/home/claude/cfront-3/src/template.h"
struct Block_Pchar *__0__X78 ;

# 495 "/home/claude/cfront-3/src/template.h"
struct Block_Pchar *__0__X79 ;

# 495 "/home/claude/cfront-3/src/template.h"
( (__0__X78 = (& instdata )), ( (__0__X78 ?(((void )( __dl__FPv ( (void *)__0__X78 -> p__11Block_Pchar ) , (__0__X78 ?(((void )(((void
# 495 "/home/claude/cfront-3/src/template.h"
)0 )))):(((void )0 )))) )):(((void )0 )))) ) ;

# 493 "/home/claude/cfront-3/src/template.h"
( (__0__X79 = (& instfct )), ( (__0__X79 ?(((void )( __dl__FPv ( (void *)__0__X79 -> p__11Block_Pchar ) , (__0__X79 ?(((void )(((void
# 493 "/home/claude/cfront-3/src/template.h"
)0 )))):(((void )0 )))) )):(((void )0 )))) ) ;

# 493 "/home/claude/cfront-3/src/template.h"
}

# 480 "/home/claude/cfront-3/src/template.h"
extern Ptfct ptfct_free__9templ_fct;

# 404 "/home/claude/cfront-3/src/cfront.h"

# 198 "/home/claude/cfront-3/src/template.h"

# 236 "/home/claude/cfront-3/src/template.h"

# 336 "/home/claude/cfront-3/src/template.h"
extern Pbase_inst head__10basic_inst;

# 236 "/home/claude/cfront-3/src/template.h"

# 198 "/home/claude/cfront-3/src/template.h"

# 92 "/home/claude/cfront-3/src/template.h"

# 404 "/home/claude/cfront-3/src/cfront.h"

# 92 "/home/claude/cfront-3/src/template.h"

# 122 "/home/claude/cfront-3/src/template.h"
extern Pcons last_friend_cons__17templ_compilation;

# 121 "/home/claude/cfront-3/src/template.h"
extern Pcons last_cons__17templ_compilation;

# 120 "/home/claude/cfront-3/src/template.h"
extern Pcons friend_templ_refs__17templ_compilation;

# 119 "/home/claude/cfront-3/src/template.h"
extern Pcons templ_refs__17templ_compilation;

# 116 "/home/claude/cfront-3/src/template.h"
extern int formals_in_progress__17templ_compilation;

# 115 "/home/claude/cfront-3/src/template.h"
extern int parameters_in_progress__17templ_compilation;

# 110 "/home/claude/cfront-3/src/template.h"
extern Ptstate save_templ__17templ_compilation;

# 109 "/home/claude/cfront-3/src/template.h"
extern int in_progress__17templ_compilation;

# 107 "/home/claude/cfront-3/src/template.h"
extern Ptable templates__17templ_compilation;

# 106 "/home/claude/cfront-3/src/template.h"
extern Pexpr actuals__17templ_compilation;

# 105 "/home/claude/cfront-3/src/template.h"
extern Plist params__17templ_compilation;

# 103 "/home/claude/cfront-3/src/template.h"
extern Ptempl_base parsed_template__17templ_compilation;

# 102 "/home/claude/cfront-3/src/template.h"
extern Ptempl owner__17templ_compilation;

# 101 "/home/claude/cfront-3/src/template.h"
extern Pfunt f_owner__17templ_compilation;

# 100 "/home/claude/cfront-3/src/template.h"
extern Pfunt f_list__17templ_compilation;

# 99 "/home/claude/cfront-3/src/template.h"
extern Ptempl list__17templ_compilation;

# 98 "/home/claude/cfront-3/src/template.h"
extern Plist param_end__17templ_compilation;

# 1008 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt stmt_free__4stmt;

# 930 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_free__4name;

# 790 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr expr_free__4expr;

# 704 "/home/claude/cfront-3/src/cfront.h"
extern Pptr ptr_free__3ptr;

# 689 "/home/claude/cfront-3/src/cfront.h"
extern Pvec vec_free__3vec;

# 629 "/home/claude/cfront-3/src/cfront.h"
extern Pfct fct_free__3fct;

# 256 "/home/claude/cfront-3/src/cfront.h"
extern Pktab table_free__6ktable;

# 216 "/home/claude/cfront-3/src/cfront.h"
extern Ptable table_free__5table;

# 911 "/home/claude/cfront-3/src/main.cpp"

/* the end */
