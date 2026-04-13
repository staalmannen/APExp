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

# 14 "/home/claude/incl-linux32/stdio.h"
typedef char *va_list ;

# 125 "/home/claude/incl-linux32/stdio.h"
extern char *sys_errlist [];
extern int sys_nerr ;
extern unsigned char *_bufendtab [];

# 31 "/home/claude/cfront-3/src/hash.h"
typedef void (*Error_Proc )(const char *);

# 38 "/home/claude/cfront-3/src/hash.h"
typedef void (*intProc )(int );
struct HashTableEntry;
struct HashWalker;
struct Hash;
enum __Q2_4Hash13insert_action { probe__Q2_4Hash13insert_action = 0, insert__Q2_4Hash13insert_action = 1, replace__Q2_4Hash13insert_action = 2} ;

# 53 "/home/claude/cfront-3/src/hash.h"
struct Hash {	/* sizeof Hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 1 ""
extern void __dl__FPv (void *);

# 93 "/home/claude/cfront-3/src/hash.h"
struct HashWalker {	/* sizeof HashWalker == 16 */
struct Hash *h__10HashWalker ;
int pos__10HashWalker ;
};

# 106 "/home/claude/cfront-3/src/hash.h"
void reset__10HashWalkerFv (struct HashWalker *__0this );

# 1 ""
extern void *__nw__FUl (size_t );

# 89 "/home/claude/cfront-3/src/hash.h"
void error__4HashFPCc (struct Hash *__0this , const char *__1msg );

# 44 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry {	/* sizeof HashTableEntry == 12 */
int key__14HashTableEntry ;
int cont__14HashTableEntry ;
char status__14HashTableEntry ;
};
struct pointer_hash;

# 67 "/home/claude/cfront-3/src/hash.h"
struct Hash *__ct__4HashFi (struct Hash *__0this , int __1sz );

# 208 "/home/claude/cfront-3/src/hash.h"
struct pointer_hash {	/* sizeof pointer_hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 206 "/home/claude/cfront-3/src/hash.h"
extern size_t pointer_hash_fcn__FUl (size_t );

# 205 "/home/claude/cfront-3/src/hash.h"
extern int pointer_hasheq__FUlT1 (size_t , size_t );

# 68 "/home/claude/cfront-3/src/hash.h"
struct Hash *__ct__4HashFR4Hash (struct Hash *__0this , struct Hash *__1a );

# 131 "/home/claude/cfront-3/src/hash.h"
struct string_hash;

# 221 "/home/claude/cfront-3/src/hash.h"
struct string_hash {	/* sizeof string_hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 219 "/home/claude/cfront-3/src/hash.h"
extern size_t string_hash_fcn__FUl (size_t );

# 218 "/home/claude/cfront-3/src/hash.h"
extern int string_hasheq__FUlT1 (size_t , size_t );

# 131 "/home/claude/cfront-3/src/hash.h"

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

# 137 "/home/claude/incl-linux32/stdio.h"
extern void *_get_stderr (void );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 100 "/home/claude/incl-linux32/stdio.h"
extern void exit (int );

# 30 "/home/claude/cfront-3/src/hash.cpp"
void default_Hash_error_handler__FPCc (const char *__1msg )
# 31 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 32 "/home/claude/cfront-3/src/hash.cpp"
fprintf ( _get_stderr ( ) , (const char *)"Fatal Hash error: %s\n",
# 32 "/home/claude/cfront-3/src/hash.cpp"
__1msg ) ;
exit ( 1 ) ;
}

# 36 "/home/claude/cfront-3/src/hash.cpp"
static Error_Proc Hash_error_handler = (default_Hash_error_handler__FPCc );

# 47 "/home/claude/cfront-3/src/hash.cpp"
void error__4HashFPCc (struct Hash *__0this , const char *__1msg )
# 48 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 49 "/home/claude/cfront-3/src/hash.cpp"
((*Hash_error_handler ))( __1msg ) ;
}

# 52 "/home/claude/cfront-3/src/hash.cpp"
struct Hash *__ct__4HashFi (register struct Hash *__0this , int __1sz )
# 53 "/home/claude/cfront-3/src/hash.cpp"
{ if (__0this || (__0this = (struct Hash *)__nw__FUl ( (size_t)(sizeof
# 53 "/home/claude/cfront-3/src/hash.cpp"
(struct Hash))) )){ 
# 54 "/home/claude/cfront-3/src/hash.cpp"
__0this -> tab__4Hash = (((struct HashTableEntry *)__nw__FUl ( (size_t)((sizeof (struct HashTableEntry ))* (__0this -> size__4Hash = __1sz )))
# 54 "/home/claude/cfront-3/src/hash.cpp"
));
{ { int __1i ;

# 55 "/home/claude/cfront-3/src/hash.cpp"
__1i = 0 ;

# 55 "/home/claude/cfront-3/src/hash.cpp"
for(;__1i < __0this -> size__4Hash ;++ __1i ) (__0this -> tab__4Hash [__1i ]). status__14HashTableEntry = 0 ;
__0this -> entry_count__4Hash = 0 ;

# 56 "/home/claude/cfront-3/src/hash.cpp"
}

# 56 "/home/claude/cfront-3/src/hash.cpp"
}
} 
# 55 "/home/claude/cfront-3/src/hash.cpp"
return __0this ;

# 57 "/home/claude/cfront-3/src/hash.cpp"
}

# 155 "/home/claude/cfront-3/src/hash.h"

# 180 "/home/claude/cfront-3/src/hash.h"

# 191 "/home/claude/cfront-3/src/hash.h"

# 84 "/home/claude/cfront-3/src/hash.h"
int *__vc__4HashFi (struct Hash *__0this , int __1k );

# 198 "/home/claude/cfront-3/src/hash.h"

# 105 "/home/claude/cfront-3/src/hash.h"
void advance__10HashWalkerFv (struct HashWalker *__0this );

# 168 "/home/claude/cfront-3/src/hash.h"

# 59 "/home/claude/cfront-3/src/hash.cpp"
struct Hash *__ct__4HashFR4Hash (register struct Hash *__0this , struct Hash *__1a )
# 60 "/home/claude/cfront-3/src/hash.cpp"
{ if (__0this || (__0this = (struct Hash *)__nw__FUl ( (size_t)(sizeof
# 60 "/home/claude/cfront-3/src/hash.cpp"
(struct Hash))) )){ 
# 61 "/home/claude/cfront-3/src/hash.cpp"
__0this -> tab__4Hash = (((struct HashTableEntry *)__nw__FUl ( (size_t)((sizeof (struct HashTableEntry ))* (__0this -> size__4Hash = ((*__1a )).
# 61 "/home/claude/cfront-3/src/hash.cpp"
size__4Hash ))) ));

# 63 "/home/claude/cfront-3/src/hash.cpp"
__0this -> key_hash_function__4Hash = ((*__1a )). key_hash_function__4Hash ;
__0this -> key_key_equality_function__4Hash = ((*__1a )). key_key_equality_function__4Hash ;

# 66 "/home/claude/cfront-3/src/hash.cpp"
{ { int __1i ;

# 66 "/home/claude/cfront-3/src/hash.cpp"
__1i = 0 ;

# 66 "/home/claude/cfront-3/src/hash.cpp"
for(;__1i < __0this -> size__4Hash ;++ __1i ) (__0this -> tab__4Hash [__1i ]). status__14HashTableEntry = 0 ;
__0this -> entry_count__4Hash = 0 ;
{ { struct HashWalker __1p ;

# 68 "/home/claude/cfront-3/src/hash.cpp"
( (((void )( ((& __1p )-> h__10HashWalker = (__1a )), reset__10HashWalkerFv ( (& __1p )) ) )), (& __1p ))
# 68 "/home/claude/cfront-3/src/hash.cpp"
;

# 68 "/home/claude/cfront-3/src/hash.cpp"
for(;( (((void *)(((& __1p )-> pos__10HashWalker < 0 )?(((struct HashWalker *)0 )):(& __1p ))))) ;advance__10HashWalkerFv ( & __1p ) ) 
# 69 "/home/claude/cfront-3/src/hash.cpp"
((*__vc__4HashFi ( __0this ,
# 69 "/home/claude/cfront-3/src/hash.cpp"
(int )((*( (((& __1p )-> pos__10HashWalker < 0 )?(((void )error__4HashFPCc ( (& __1p )-> h__10HashWalker , (const char *)"operation on null Walker")
# 69 "/home/claude/cfront-3/src/hash.cpp"
)):(((void )0 ))), (((const int *)(& ((& __1p )-> h__10HashWalker -> tab__4Hash [(& __1p )-> pos__10HashWalker ]). key__14HashTableEntry )))) ))) ))=
# 69 "/home/claude/cfront-3/src/hash.cpp"
((*( (((& __1p )-> pos__10HashWalker < 0 )?(((void )error__4HashFPCc ( (& __1p )-> h__10HashWalker , (const char *)"operation on null Walker")
# 69 "/home/claude/cfront-3/src/hash.cpp"
)):(((void )0 ))), (((int *)(& ((& __1p )-> h__10HashWalker -> tab__4Hash [(& __1p )-> pos__10HashWalker ]). cont__14HashTableEntry )))) ));

# 69 "/home/claude/cfront-3/src/hash.cpp"
( (((void )(((void )(((void )0 ))))))) ;

# 69 "/home/claude/cfront-3/src/hash.cpp"
}

# 69 "/home/claude/cfront-3/src/hash.cpp"
}

# 69 "/home/claude/cfront-3/src/hash.cpp"
}

# 69 "/home/claude/cfront-3/src/hash.cpp"
}
} 
# 66 "/home/claude/cfront-3/src/hash.cpp"
return __0this ;

# 70 "/home/claude/cfront-3/src/hash.cpp"
}

# 112 "/home/claude/cfront-3/src/hash.h"

# 121 "/home/claude/cfront-3/src/hash.h"

# 96 "/home/claude/cfront-3/src/hash.cpp"

# 79 "/home/claude/cfront-3/src/hash.h"
void resize__4HashFi (struct Hash *__0this , int __1newsize );

# 104 "/home/claude/cfront-3/src/hash.cpp"
int *__vc__4HashFi (register struct Hash *__0this , int __1key )
# 105 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 106 "/home/claude/cfront-3/src/hash.cpp"
unsigned int __1hashval ;

# 106 "/home/claude/cfront-3/src/hash.cpp"
__1hashval = ( ((*__0this -> key_hash_function__4Hash ))( ((unsigned long )__1key )) ) ;
while (1 )
# 108 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 109 "/home/claude/cfront-3/src/hash.cpp"
int __2bestspot ;
int __2h ;

# 109 "/home/claude/cfront-3/src/hash.cpp"
__2bestspot = -1;
__2h = (__1hashval % __0this -> size__4Hash );
{ { int __2i ;

# 111 "/home/claude/cfront-3/src/hash.cpp"
__2i = 0 ;

# 111 "/home/claude/cfront-3/src/hash.cpp"
for(;__2i <= __0this -> size__4Hash ;++ __2i ) 
# 112 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 112 "/home/claude/cfront-3/src/hash.cpp"
unsigned long __1__X13 ;

# 112 "/home/claude/cfront-3/src/hash.cpp"
int __1__X14 ;

# 113 "/home/claude/cfront-3/src/hash.cpp"
if ((__0this -> tab__4Hash [__2h ]). status__14HashTableEntry == 0 )
# 114 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 116 "/home/claude/cfront-3/src/hash.cpp"
if (__0this -> entry_count__4Hash > (((__0this -> size__4Hash >> 1 )+ (__0this -> size__4Hash >> 2 ))+
# 116 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> size__4Hash >> 3 )))
# 118 "/home/claude/cfront-3/src/hash.cpp"
break ;
if (__2bestspot < 0 )__2bestspot = __2h ;
(__0this -> tab__4Hash [__2bestspot ]). key__14HashTableEntry = __1key ;
(__0this -> tab__4Hash [__2bestspot ]). status__14HashTableEntry = 1 ;
++ __0this -> entry_count__4Hash ;
return (& (__0this -> tab__4Hash [__2bestspot ]). cont__14HashTableEntry );
}
else if ((__0this -> tab__4Hash [__2h ]). status__14HashTableEntry == 2 )
# 126 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 127 "/home/claude/cfront-3/src/hash.cpp"
if (__2bestspot < 0 )__2bestspot = __2h ;
}
else if (( (__1__X13 = (__0this -> tab__4Hash [__2h ]). key__14HashTableEntry ), ( ((*__0this -> key_key_equality_function__4Hash ))( __1__X13 , ((unsigned long )__1key ))
# 129 "/home/claude/cfront-3/src/hash.cpp"
) ) )
# 130 "/home/claude/cfront-3/src/hash.cpp"
return (& (__0this -> tab__4Hash [__2h ]). cont__14HashTableEntry );
if (__2i == 0 )
# 132 "/home/claude/cfront-3/src/hash.cpp"
__2h = ((__2h + ( (__1__X14 = __0this -> size__4Hash ), ( (((int )(((__1hashval / __1__X14 )% __1__X14 )>> 1 ))))
# 132 "/home/claude/cfront-3/src/hash.cpp"
) )% __0this -> size__4Hash );
else if ((++ __2h )>= __0this -> size__4Hash )
# 134 "/home/claude/cfront-3/src/hash.cpp"
__2h -= __0this -> size__4Hash ;
}
resize__4HashFi ( __0this , __0this -> size__4Hash << 1 ) ;

# 136 "/home/claude/cfront-3/src/hash.cpp"
}

# 136 "/home/claude/cfront-3/src/hash.cpp"
}
}
}

# 112 "/home/claude/cfront-3/src/hash.h"

# 121 "/home/claude/cfront-3/src/hash.h"

# 96 "/home/claude/cfront-3/src/hash.cpp"

# 143 "/home/claude/cfront-3/src/hash.cpp"
void action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 (register struct Hash *__0this , size_t __1key , size_t __1val , int __1what , 
# 144 "/home/claude/cfront-3/src/hash.cpp"
size_t *__1found , size_t *__1old_val )
# 145 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 146 "/home/claude/cfront-3/src/hash.cpp"
size_t __1hashval ;

# 146 "/home/claude/cfront-3/src/hash.cpp"
__1hashval = ( ((*__0this -> key_hash_function__4Hash ))( __1key ) ) ;
while (1 )
# 148 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 149 "/home/claude/cfront-3/src/hash.cpp"
int __2bestspot ;
int __2h ;

# 149 "/home/claude/cfront-3/src/hash.cpp"
__2bestspot = -1;
__2h = (__1hashval % __0this -> size__4Hash );
{ { int __2i ;

# 151 "/home/claude/cfront-3/src/hash.cpp"
__2i = 0 ;

# 151 "/home/claude/cfront-3/src/hash.cpp"
for(;__2i <= __0this -> size__4Hash ;++ __2i ) 
# 152 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 152 "/home/claude/cfront-3/src/hash.cpp"
unsigned long __1__X15 ;

# 152 "/home/claude/cfront-3/src/hash.cpp"
int __1__X16 ;

# 153 "/home/claude/cfront-3/src/hash.cpp"
if ((__0this -> tab__4Hash [__2h ]). status__14HashTableEntry == 0 )
# 154 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 156 "/home/claude/cfront-3/src/hash.cpp"
if (__0this -> entry_count__4Hash > (((__0this -> size__4Hash >> 1 )+ (__0this -> size__4Hash >> 2 ))+
# 156 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> size__4Hash >> 3 )))
# 158 "/home/claude/cfront-3/src/hash.cpp"
break ;
if (__2bestspot < 0 )__2bestspot = __2h ;
((*__1found ))= 0 ;
if (__1what != 0){ 
# 162 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> tab__4Hash [__2bestspot ]). key__14HashTableEntry = __1key ;
(__0this -> tab__4Hash [__2bestspot ]). status__14HashTableEntry = 1 ;
++ __0this -> entry_count__4Hash ;
(__0this -> tab__4Hash [__2bestspot ]). cont__14HashTableEntry = __1val ;
}
return ;
}
else if ((__0this -> tab__4Hash [__2h ]). status__14HashTableEntry == 2 )
# 170 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 171 "/home/claude/cfront-3/src/hash.cpp"
if (__2bestspot < 0 )__2bestspot = __2h ;
}
else if (( (__1__X15 = (__0this -> tab__4Hash [__2h ]). key__14HashTableEntry ), ( ((*__0this -> key_key_equality_function__4Hash ))( __1__X15 , __1key ) ) )
# 173 "/home/claude/cfront-3/src/hash.cpp"
){ 
# 174 "/home/claude/cfront-3/src/hash.cpp"
((*__1found ))= 1 ;
((*__1old_val ))= (__0this -> tab__4Hash [__2h ]). cont__14HashTableEntry ;
if (__1what == 2)
# 177 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> tab__4Hash [__2h ]). cont__14HashTableEntry = __1val ;
return ;
}
if (__2i == 0 )
# 181 "/home/claude/cfront-3/src/hash.cpp"
__2h = ((__2h + ( (__1__X16 = __0this -> size__4Hash ), ( (((int )(((((unsigned int )__1hashval )/ __1__X16 )%
# 181 "/home/claude/cfront-3/src/hash.cpp"
__1__X16 )>> 1 )))) ) )% __0this -> size__4Hash );
else if ((++ __2h )>= __0this -> size__4Hash )
# 183 "/home/claude/cfront-3/src/hash.cpp"
__2h -= __0this -> size__4Hash ;
}
resize__4HashFi ( __0this , __0this -> size__4Hash << 1 ) ;

# 185 "/home/claude/cfront-3/src/hash.cpp"
}

# 185 "/home/claude/cfront-3/src/hash.cpp"
}
}
}

# 112 "/home/claude/cfront-3/src/hash.h"

# 121 "/home/claude/cfront-3/src/hash.h"

# 96 "/home/claude/cfront-3/src/hash.cpp"

# 209 "/home/claude/cfront-3/src/hash.cpp"
int del__4HashFi (register struct Hash *__0this , int __1key )
# 210 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 211 "/home/claude/cfront-3/src/hash.cpp"
unsigned int __1hashval ;
int __1h ;

# 211 "/home/claude/cfront-3/src/hash.cpp"
__1hashval = ( ((*__0this -> key_hash_function__4Hash ))( ((unsigned long )__1key )) ) ;
__1h = (__1hashval % __0this -> size__4Hash );
{ { int __1i ;

# 213 "/home/claude/cfront-3/src/hash.cpp"
__1i = 0 ;

# 213 "/home/claude/cfront-3/src/hash.cpp"
for(;__1i <= __0this -> size__4Hash ;++ __1i ) 
# 214 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 214 "/home/claude/cfront-3/src/hash.cpp"
unsigned long __1__X17 ;

# 214 "/home/claude/cfront-3/src/hash.cpp"
int __1__X18 ;

# 215 "/home/claude/cfront-3/src/hash.cpp"
if ((__0this -> tab__4Hash [__1h ]). status__14HashTableEntry == 0 )
# 216 "/home/claude/cfront-3/src/hash.cpp"
return 0 ;
else if (((__0this -> tab__4Hash [__1h ]). status__14HashTableEntry == 1 )&& ( (__1__X17 = (__0this -> tab__4Hash [__1h ]). key__14HashTableEntry ), ( ((*__0this -> key_key_equality_function__4Hash ))(
# 217 "/home/claude/cfront-3/src/hash.cpp"
__1__X17 , ((unsigned long )__1key )) ) ) )
# 218 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 219 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> tab__4Hash [__1h ]). status__14HashTableEntry = 2 ;
-- __0this -> entry_count__4Hash ;
return 1 ;
}
if (__1i == 0 )
# 224 "/home/claude/cfront-3/src/hash.cpp"
__1h = ((__1h + ( (__1__X18 = __0this -> size__4Hash ), ( (((int )(((__1hashval / __1__X18 )% __1__X18 )>> 1 ))))
# 224 "/home/claude/cfront-3/src/hash.cpp"
) )% __0this -> size__4Hash );
else if ((++ __1h )>= __0this -> size__4Hash )
# 226 "/home/claude/cfront-3/src/hash.cpp"
__1h -= __0this -> size__4Hash ;
}
return 0 ;

# 228 "/home/claude/cfront-3/src/hash.cpp"
}

# 228 "/home/claude/cfront-3/src/hash.cpp"
}
}

# 240 "/home/claude/cfront-3/src/hash.cpp"
void clear__4HashFv (register struct Hash *__0this )
# 241 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 242 "/home/claude/cfront-3/src/hash.cpp"
{ { int __1i ;

# 242 "/home/claude/cfront-3/src/hash.cpp"
__1i = 0 ;

# 242 "/home/claude/cfront-3/src/hash.cpp"
for(;__1i < __0this -> size__4Hash ;++ __1i ) 
# 243 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> tab__4Hash [__1i ]). status__14HashTableEntry = 0 ;
__0this -> entry_count__4Hash = 0 ;

# 244 "/home/claude/cfront-3/src/hash.cpp"
}

# 244 "/home/claude/cfront-3/src/hash.cpp"
}
}

# 247 "/home/claude/cfront-3/src/hash.cpp"
void resize__4HashFi (register struct Hash *__0this , int __1newsize )
# 248 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 249 "/home/claude/cfront-3/src/hash.cpp"
if (__1newsize < __0this -> entry_count__4Hash )
# 250 "/home/claude/cfront-3/src/hash.cpp"
error__4HashFPCc ( __0this , (const char *)"requested resize too small")
# 250 "/home/claude/cfront-3/src/hash.cpp"
;
{ struct HashTableEntry *__1oldtab ;
int __1oldsize ;

# 251 "/home/claude/cfront-3/src/hash.cpp"
__1oldtab = __0this -> tab__4Hash ;
__1oldsize = __0this -> size__4Hash ;
__0this -> tab__4Hash = (((struct HashTableEntry *)__nw__FUl ( (size_t)((sizeof (struct HashTableEntry ))* (__0this -> size__4Hash = __1newsize ))) ));
{ int __1i ;

# 254 "/home/claude/cfront-3/src/hash.cpp"
__1i = 0 ;
for(;__1i < __0this -> size__4Hash ;++ __1i ) 
# 256 "/home/claude/cfront-3/src/hash.cpp"
(__0this -> tab__4Hash [__1i ]). status__14HashTableEntry = 0 ;
__0this -> entry_count__4Hash = 0 ;
for(__1i = 0 ;__1i < __1oldsize ;++ __1i ) 
# 259 "/home/claude/cfront-3/src/hash.cpp"
if ((__1oldtab [__1i ]). status__14HashTableEntry == 1 )
# 260 "/home/claude/cfront-3/src/hash.cpp"
((*__vc__4HashFi ( __0this , (__1oldtab [__1i ]). key__14HashTableEntry ) ))= (__1oldtab [__1i ]). cont__14HashTableEntry ;
# 260 "/home/claude/cfront-3/src/hash.cpp"

# 261 "/home/claude/cfront-3/src/hash.cpp"
__dl__FPv ( (void *)__1oldtab ) ;

# 261 "/home/claude/cfront-3/src/hash.cpp"
}

# 261 "/home/claude/cfront-3/src/hash.cpp"
}
}

# 264 "/home/claude/cfront-3/src/hash.cpp"
void reset__10HashWalkerFv (register struct HashWalker *__0this )
# 265 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 266 "/home/claude/cfront-3/src/hash.cpp"
for(__0this -> pos__10HashWalker = 0 ;__0this -> pos__10HashWalker < __0this -> h__10HashWalker -> size__4Hash ;++ __0this -> pos__10HashWalker ) 
# 267 "/home/claude/cfront-3/src/hash.cpp"
if
# 267 "/home/claude/cfront-3/src/hash.cpp"
((__0this -> h__10HashWalker -> tab__4Hash [__0this -> pos__10HashWalker ]). status__14HashTableEntry == 1 )
# 268 "/home/claude/cfront-3/src/hash.cpp"
return ;
__0this -> pos__10HashWalker = -1;
}

# 272 "/home/claude/cfront-3/src/hash.cpp"
void advance__10HashWalkerFv (register struct HashWalker *__0this )
# 273 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 274 "/home/claude/cfront-3/src/hash.cpp"
if (__0this -> pos__10HashWalker < 0 )
# 275 "/home/claude/cfront-3/src/hash.cpp"
return ;
for(__0this -> pos__10HashWalker ++ ;__0this -> pos__10HashWalker < __0this -> h__10HashWalker -> size__4Hash ;++ __0this -> pos__10HashWalker ) 
# 277 "/home/claude/cfront-3/src/hash.cpp"
if ((__0this -> h__10HashWalker -> tab__4Hash [__0this -> pos__10HashWalker ]).
# 277 "/home/claude/cfront-3/src/hash.cpp"
status__14HashTableEntry == 1 )
# 278 "/home/claude/cfront-3/src/hash.cpp"
return ;
__0this -> pos__10HashWalker = -1;
}

# 321 "/home/claude/cfront-3/src/hash.cpp"
int pointer_hasheq__FUlT1 (size_t __1a , size_t __1b )
# 322 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 323 "/home/claude/cfront-3/src/hash.cpp"
return (__1a == __1b );
}

# 326 "/home/claude/cfront-3/src/hash.cpp"
size_t pointer_hash_fcn__FUl (size_t __1x )
# 327 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 328 "/home/claude/cfront-3/src/hash.cpp"
size_t __1X ;

# 328 "/home/claude/cfront-3/src/hash.cpp"
__1X = (((unsigned long )__1x ));
return (((__1X << 16 )| (__1X >> 16 ))^ __1x );
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 332 "/home/claude/cfront-3/src/hash.cpp"
int string_hasheq__FUlT1 (size_t __1a , size_t __1b )
# 333 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 334 "/home/claude/cfront-3/src/hash.cpp"
return (! strcmp ( (const char *)(((char *)__1a )), (const char *)(((char *)__1b )))
# 334 "/home/claude/cfront-3/src/hash.cpp"
);
}

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 337 "/home/claude/cfront-3/src/hash.cpp"
size_t string_hash_fcn__FUl (size_t __1x )
# 338 "/home/claude/cfront-3/src/hash.cpp"
{ 
# 339 "/home/claude/cfront-3/src/hash.cpp"
char *__1str ;
size_t __1l ;

# 339 "/home/claude/cfront-3/src/hash.cpp"
__1str = (((char *)__1x ));
__1l = strlen ( (const char *)__1str ) ;

# 342 "/home/claude/cfront-3/src/hash.cpp"
if (__1x <= 4 )return (unsigned long )(__1str [0 ]);
else { 
# 344 "/home/claude/cfront-3/src/hash.cpp"
unsigned int *__2f4 ;

# 344 "/home/claude/cfront-3/src/hash.cpp"
__2f4 = (((unsigned int *)__1str ));
if (__1l < 8 )return (unsigned long )(((((*__2f4 ))<< 16 )| (((*__2f4 ))>> 16 ))^ ((*__2f4 )));
else { 
# 347 "/home/claude/cfront-3/src/hash.cpp"
unsigned int *__3s4 ;

# 347 "/home/claude/cfront-3/src/hash.cpp"
__3s4 = (__2f4 ++ );
return (unsigned long )(((((*__2f4 ))<< 16 )| (((*__2f4 ))>> 16 ))^ ((*__3s4 )));
}
}
}

# 351 "/home/claude/cfront-3/src/hash.cpp"

/* the end */
