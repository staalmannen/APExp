
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

#include <stddef.h>
struct exception;

typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;

typedef char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef long __int64_t;
typedef unsigned long __uint64_t;

typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;

typedef long __quad_t;
typedef unsigned long __u_quad_t;

typedef long __intmax_t;
typedef unsigned long __uintmax_t;

typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __off64_t;
typedef int __pid_t;
struct __C1;
typedef struct __fsid_t __fsid_t;
typedef long __clock_t;
typedef unsigned long __rlim_t;
typedef unsigned long __rlim64_t;
typedef unsigned int __id_t;
typedef long __time_t;
typedef unsigned int __useconds_t;
typedef long __suseconds_t;
typedef long __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void *__timer_t;

typedef long __blksize_t;

typedef long __blkcnt_t;
typedef long __blkcnt64_t;

typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsblkcnt64_t;

typedef unsigned long __fsfilcnt_t;
typedef unsigned long __fsfilcnt64_t;

typedef long __fsword_t;

typedef long __ssize_t;

typedef long __syscall_slong_t;

typedef unsigned long __syscall_ulong_t;

typedef __off64_t __loff_t;
typedef char *__caddr_t;

typedef long __intptr_t;

typedef unsigned int __socklen_t;

typedef int __sig_atomic_t;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef struct __fsid_t fsid_t;

typedef __loff_t loff_t;

typedef __ino_t ino_t;

typedef __ino64_t ino64_t;

typedef __dev_t dev_t;

typedef __gid_t gid_t;

typedef __mode_t mode_t;

typedef __nlink_t nlink_t;

typedef __uid_t uid_t;

typedef __off_t off_t;

typedef __off64_t off64_t;

typedef __pid_t pid_t;

typedef __id_t id_t;

typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;

typedef __key_t key_t;

typedef __clock_t clock_t;

typedef __clockid_t clockid_t;

typedef __time_t time_t;

typedef __timer_t timer_t;

typedef __useconds_t useconds_t;

typedef __suseconds_t suseconds_t;

typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;

typedef int register_t;
struct __C2;

typedef struct __sigset_t __sigset_t;

typedef struct __sigset_t sigset_t;
struct timeval;
struct timespec;

typedef long __fd_mask;
struct __C3;

typedef struct fd_set fd_set;

typedef __fd_mask fd_mask;

typedef __blksize_t blksize_t;

typedef __blkcnt_t blkcnt_t;

typedef __fsblkcnt_t fsblkcnt_t;

typedef __fsfilcnt_t fsfilcnt_t;

typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
union __C4;
struct __Q2_4__C44__C1;

struct __Q2_4__C44__C1 { /* sizeof __Q2_4__C44__C1 == 8 */
    unsigned int __low;
    unsigned int __high;
};
typedef union __atomic_wide_counter __atomic_wide_counter;
struct __pthread_internal_list;

typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_internal_slist;

typedef struct __pthread_internal_slist __pthread_slist_t;
struct __pthread_mutex_s;

struct __pthread_internal_list { /* sizeof __pthread_internal_list == 16 */
    struct __pthread_internal_list *__prev__23__pthread_internal_list;
    struct __pthread_internal_list *__next__23__pthread_internal_list;
};
struct __pthread_rwlock_arch_t;
struct __pthread_cond_s;

union __atomic_wide_counter { /* sizeof __atomic_wide_counter == 8 */

    unsigned long long __value64__21__atomic_wide_counter;

    struct __Q2_4__C44__C1 __value32__21__atomic_wide_counter;
};

typedef unsigned int __tss_t;
typedef unsigned long __thrd_t;
struct __C5;

typedef struct __once_flag __once_flag;

typedef unsigned long pthread_t;
union __C6;

typedef union pthread_mutexattr_t pthread_mutexattr_t;
union __C7;

typedef union pthread_condattr_t pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;
union pthread_attr_t;

typedef union pthread_attr_t pthread_attr_t;
union __C8;

struct __pthread_mutex_s { /* sizeof __pthread_mutex_s == 40 */
    int __lock__17__pthread_mutex_s;
    unsigned int __count__17__pthread_mutex_s;
    int __owner__17__pthread_mutex_s;

    unsigned int __nusers__17__pthread_mutex_s;

    int __kind__17__pthread_mutex_s;

    short __spins__17__pthread_mutex_s;
    short __elision__17__pthread_mutex_s;
    struct __pthread_internal_list __list__17__pthread_mutex_s;
};

typedef union pthread_mutex_t pthread_mutex_t;
union __C9;

struct __pthread_cond_s { /* sizeof __pthread_cond_s == 48 */
    union __atomic_wide_counter __wseq__16__pthread_cond_s;
    union __atomic_wide_counter __g1_start__16__pthread_cond_s;
    unsigned int __g_refs__16__pthread_cond_s[2];
    unsigned int __g_size__16__pthread_cond_s[2];
    unsigned int __g1_orig_size__16__pthread_cond_s;
    unsigned int __wrefs__16__pthread_cond_s;
    unsigned int __g_signals__16__pthread_cond_s[2];
};

typedef union pthread_cond_t pthread_cond_t;
union __C10;

struct __pthread_rwlock_arch_t { /* sizeof __pthread_rwlock_arch_t == 56 */
    unsigned int __readers__23__pthread_rwlock_arch_t;
    unsigned int __writers__23__pthread_rwlock_arch_t;
    unsigned int __wrphase_futex__23__pthread_rwlock_arch_t;
    unsigned int __writers_futex__23__pthread_rwlock_arch_t;
    unsigned int __pad3__23__pthread_rwlock_arch_t;
    unsigned int __pad4__23__pthread_rwlock_arch_t;

    int __cur_writer__23__pthread_rwlock_arch_t;
    int __shared__23__pthread_rwlock_arch_t;
    char __rwelision__23__pthread_rwlock_arch_t;

    unsigned char __pad1__23__pthread_rwlock_arch_t[7];

    unsigned long __pad2__23__pthread_rwlock_arch_t;

    unsigned int __flags__23__pthread_rwlock_arch_t;
};

typedef union pthread_rwlock_t pthread_rwlock_t;
union __C11;

typedef union pthread_rwlockattr_t pthread_rwlockattr_t;

typedef int pthread_spinlock_t;
union __C12;

typedef union pthread_barrier_t pthread_barrier_t;
union __C13;

typedef union pthread_barrierattr_t pthread_barrierattr_t;
struct flock;

typedef char *va_list;

extern char *sys_errlist[];
extern int sys_nerr;
extern unsigned char *_bufendtab[];
struct group;
struct passwd;
struct comment;

typedef __sig_atomic_t sig_atomic_t;
union sigval;

typedef union sigval __sigval_t;
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

struct __Q3_5__C144__C14__C1 { /* sizeof __Q3_5__C144__C14__C1 == 8 */

    __pid_t si_pid;
    __uid_t si_uid;
};

union sigval { /* sizeof sigval == 8 */
    int sival_int__6sigval;
    void *sival_ptr__6sigval;
};

struct __Q3_5__C144__C14__C2 { /* sizeof __Q3_5__C144__C14__C2 == 16 */
    int si_tid;
    int si_overrun;
    union sigval si_sigval;
};

struct __Q3_5__C144__C14__C3 { /* sizeof __Q3_5__C144__C14__C3 == 16 */
    __pid_t si_pid;
    __uid_t si_uid;
    union sigval si_sigval;
};

struct __Q3_5__C144__C14__C4 { /* sizeof __Q3_5__C144__C14__C4 == 32 */
    __pid_t si_pid;
    __uid_t si_uid;
    int si_status;
    __clock_t si_utime;
    __clock_t si_stime;
};

struct __Q5_5__C144__C14__C54__C14__C1 { /* sizeof __Q5_5__C144__C14__C54__C14__C1 == 16 */

    void *_lower;
    void *_upper;
};

union __Q4_5__C144__C14__C54__C1 { /* sizeof __Q4_5__C144__C14__C54__C1 == 16 */

    struct __Q5_5__C144__C14__C54__C14__C1 _addr_bnd;

    __uint32_t _pkey;
};

struct __Q3_5__C144__C14__C5 { /* sizeof __Q3_5__C144__C14__C5 == 32 */
    void *si_addr;

    short si_addr_lsb;

    union __Q4_5__C144__C14__C54__C1 _bounds;
};

struct __Q3_5__C144__C14__C6 { /* sizeof __Q3_5__C144__C14__C6 == 16 */
    long si_band;
    int si_fd;
};

struct __Q3_5__C144__C14__C7 { /* sizeof __Q3_5__C144__C14__C7 == 16 */
    void *_call_addr;
    int _syscall;
    unsigned int _arch;
};

union __Q2_5__C144__C1 { /* sizeof __Q2_5__C144__C1 == 112 */
    int _pad[28];

    struct __Q3_5__C144__C14__C1 _kill;

    struct __Q3_5__C144__C14__C2 _timer;

    struct __Q3_5__C144__C14__C3 _rt;

    struct __Q3_5__C144__C14__C4 _sigchld;

    struct __Q3_5__C144__C14__C5 _sigfault;

    struct __Q3_5__C144__C14__C6 _sigpoll;

    struct __Q3_5__C144__C14__C7 _sigsys;
};

typedef struct siginfo_t siginfo_t;
enum __E1 {
    SI_ASYNCNL = -60,
    SI_DETHREAD = -7,
    SI_TKILL = -6,
    SI_SIGIO = -5,
    SI_ASYNCIO = -4,
    SI_MESGQ = -3,
    SI_TIMER = -2,
    SI_QUEUE = -1,
    SI_USER = 0,
    SI_KERNEL = 128
};
enum __E2 {
    ILL_ILLOPC = 1,
    ILL_ILLOPN = 2,
    ILL_ILLADR = 3,
    ILL_ILLTRP = 4,
    ILL_PRVOPC = 5,
    ILL_PRVREG = 6,
    ILL_COPROC = 7,
    ILL_BADSTK = 8,
    ILL_BADIADDR = 9
};
enum __E3 {
    FPE_INTDIV = 1,
    FPE_INTOVF = 2,
    FPE_FLTDIV = 3,
    FPE_FLTOVF = 4,
    FPE_FLTUND = 5,
    FPE_FLTRES = 6,
    FPE_FLTINV = 7,
    FPE_FLTSUB = 8,
    FPE_FLTUNK = 14,
    FPE_CONDTRAP = 15
};
enum __E4 {
    SEGV_MAPERR = 1,
    SEGV_ACCERR = 2,
    SEGV_BNDERR = 3,
    SEGV_PKUERR = 4,
    SEGV_ACCADI = 5,
    SEGV_ADIDERR = 6,
    SEGV_ADIPERR = 7,
    SEGV_MTEAERR = 8,
    SEGV_MTESERR = 9,
    SEGV_CPERR = 10
};
enum __E5 { BUS_ADRALN = 1, BUS_ADRERR = 2, BUS_OBJERR = 3, BUS_MCEERR_AR = 4, BUS_MCEERR_AO = 5 };
enum __E6 { TRAP_BRKPT = 1, TRAP_TRACE = 2, TRAP_BRANCH = 3, TRAP_HWBKPT = 4, TRAP_UNK = 5 };
enum __E7 {
    CLD_EXITED = 1,
    CLD_KILLED = 2,
    CLD_DUMPED = 3,
    CLD_TRAPPED = 4,
    CLD_STOPPED = 5,
    CLD_CONTINUED = 6
};
enum __E8 { POLL_IN = 1, POLL_OUT = 2, POLL_MSG = 3, POLL_ERR = 4, POLL_PRI = 5, POLL_HUP = 6 };

typedef union sigval sigval_t;
struct sigevent;
union __Q2_8sigevent4__C1;
struct __Q3_8sigevent4__C14__C1;

struct __Q3_8sigevent4__C14__C1 { /* sizeof __Q3_8sigevent4__C14__C1 == 16 */

    void (*_function)(union sigval);
    union pthread_attr_t *_attribute;
};

union __Q2_8sigevent4__C1 { /* sizeof __Q2_8sigevent4__C1 == 48 */
    int _pad[12];

    __pid_t _tid;

    struct __Q3_8sigevent4__C14__C1 _sigev_thread;
};
typedef struct sigevent sigevent_t;
enum __E9 { SIGEV_SIGNAL = 0, SIGEV_NONE = 1, SIGEV_THREAD = 2, SIGEV_THREAD_ID = 4 };

typedef void (*__sighandler_t)(int);

typedef __sighandler_t sighandler_t;

typedef __sighandler_t sig_t;
struct sigaction;
union __Q2_9sigaction4__C1;

union __Q2_9sigaction4__C1 { /* sizeof __Q2_9sigaction4__C1 == 8 */

    __sighandler_t sa_handler;

    void (*sa_sigaction)(int, struct siginfo_t *, void *);
};

struct __sigset_t { /* sizeof __sigset_t == 128 */

    unsigned long __val__10__sigset_t[16];
};
struct _fpx_sw_bytes;
struct _fpreg;
struct _fpxreg;
struct _xmmreg;
struct _fpstate;

struct _fpxreg { /* sizeof _fpxreg == 16 */
    unsigned short significand__7_fpxreg[4];
    unsigned short exponent__7_fpxreg;
    unsigned short __glibc_reserved1__7_fpxreg[3];
};

struct _xmmreg { /* sizeof _xmmreg == 16 */
    __uint32_t element__7_xmmreg[4];
};
struct sigcontext;
union __Q2_10sigcontext4__C1;

union __Q2_10sigcontext4__C1 { /* sizeof __Q2_10sigcontext4__C1 == 8 */
    struct _fpstate *fpstate;
    __uint64_t __fpstate_word;
};
struct _xsave_hdr;
struct _ymmh_state;
struct _xstate;

struct _fpstate { /* sizeof _fpstate == 512 */

    __uint16_t cwd__8_fpstate;
    __uint16_t swd__8_fpstate;
    __uint16_t ftw__8_fpstate;
    __uint16_t fop__8_fpstate;
    __uint64_t rip__8_fpstate;
    __uint64_t rdp__8_fpstate;
    __uint32_t mxcsr__8_fpstate;
    __uint32_t mxcr_mask__8_fpstate;
    struct _fpxreg _st__8_fpstate[8];
    struct _xmmreg _xmm__8_fpstate[16];
    __uint32_t __glibc_reserved1__8_fpstate[24];
};

struct _xsave_hdr { /* sizeof _xsave_hdr == 64 */
    __uint64_t xstate_bv__10_xsave_hdr;
    __uint64_t __glibc_reserved1__10_xsave_hdr[2];
    __uint64_t __glibc_reserved2__10_xsave_hdr[5];
};

struct _ymmh_state { /* sizeof _ymmh_state == 256 */
    __uint32_t ymmh_space__11_ymmh_state[64];
};
struct __C15;

typedef struct stack_t stack_t;

typedef long long greg_t;

typedef greg_t gregset_t[23];
enum __E10 {
    REG_R8 = 0,
    REG_R9 = 1,
    REG_R10 = 2,
    REG_R11 = 3,
    REG_R12 = 4,
    REG_R13 = 5,
    REG_R14 = 6,
    REG_R15 = 7,
    REG_RDI = 8,
    REG_RSI = 9,
    REG_RBP = 10,
    REG_RBX = 11,
    REG_RDX = 12,
    REG_RAX = 13,
    REG_RCX = 14,
    REG_RSP = 15,
    REG_RIP = 16,
    REG_EFL = 17,
    REG_CSGSFS = 18,
    REG_ERR = 19,
    REG_TRAPNO = 20,
    REG_OLDMASK = 21,
    REG_CR2 = 22
};
struct _libc_fpxreg;
struct _libc_xmmreg;
struct _libc_fpstate;

struct _libc_fpxreg { /* sizeof _libc_fpxreg == 16 */
    unsigned short significand__12_libc_fpxreg[4];
    unsigned short exponent__12_libc_fpxreg;
    unsigned short __glibc_reserved1__12_libc_fpxreg[3];
};

struct _libc_xmmreg { /* sizeof _libc_xmmreg == 16 */
    __uint32_t element__12_libc_xmmreg[4];
};

typedef struct _libc_fpstate *fpregset_t;
struct __C16;

typedef struct mcontext_t mcontext_t;
struct ucontext_t;

struct stack_t { /* sizeof stack_t == 24 */

    void *ss_sp__7stack_t;
    int ss_flags__7stack_t;
    size_t ss_size__7stack_t;
};

struct mcontext_t { /* sizeof mcontext_t == 256 */

    gregset_t gregs__10mcontext_t;

    fpregset_t fpregs__10mcontext_t;
    unsigned long long __reserved1__10mcontext_t[8];
};

struct _libc_fpstate { /* sizeof _libc_fpstate == 512 */

    __uint16_t cwd__13_libc_fpstate;
    __uint16_t swd__13_libc_fpstate;
    __uint16_t ftw__13_libc_fpstate;
    __uint16_t fop__13_libc_fpstate;
    __uint64_t rip__13_libc_fpstate;
    __uint64_t rdp__13_libc_fpstate;
    __uint32_t mxcsr__13_libc_fpstate;
    __uint32_t mxcr_mask__13_libc_fpstate;
    struct _libc_fpxreg _st__13_libc_fpstate[8];
    struct _libc_xmmreg _xmm__13_libc_fpstate[16];
    __uint32_t __glibc_reserved1__13_libc_fpstate[24];
};

typedef struct ucontext_t ucontext_t;
enum __E11 { SS_ONSTACK = 1, SS_DISABLE = 2 };
struct sigstack;
enum idtype_t { P_ALL = 0, P_PID = 1, P_PGID = 2, P_PIDFD = 3 };

typedef int idtype_t;
struct rusage;

extern int BI_IN_WORD;
extern int BI_IN_BYTE;

extern int SZ_CHAR;
extern int AL_CHAR;

extern int SZ_SHORT;
extern int AL_SHORT;

extern int SZ_INT;
extern int AL_INT;

extern int SZ_LONG;
extern int AL_LONG;

extern int SZ_LLONG;
extern int AL_LLONG;

extern int SZ_FLOAT;
extern int AL_FLOAT;

extern int SZ_DOUBLE;
extern int AL_DOUBLE;

extern int SZ_LDOUBLE;
extern int AL_LDOUBLE;

extern int SZ_STRUCT;
extern int AL_STRUCT;

extern int SZ_WORD;

extern int SZ_WPTR;
extern int AL_WPTR;

extern int SZ_BPTR;
extern int AL_BPTR;

extern const char *LARGEST_INT;

extern const char *LARGEST_LONG;

extern const char *LARGEST_LLONG;
extern int F_SENSITIVE;
extern int F_OPTIMIZED;

extern char *sys_errlist[];
extern int sys_nerr;
extern unsigned char *_bufendtab[];

extern const char *keys[256];

#include "cfront_translated.h"

struct node { /* sizeof node == 3 */
    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;
};

void *__nw__5tableSFUl(size_t);
void __dl__5tableSFPvUl(void *, size_t);

struct table { /* sizeof table == 56 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit init_stat__5table;

    TOK t_realbase__5table;
    short size__5table;
    short hashsize__5table;
    short free_slot__5table;
    Pname *entries__5table;
    short *hashtbl__5table;
    Pstmt real_block__5table;

    Ptable next__5table;
    Pname t_name__5table;
};
extern Ptable table_free__5table;
union __Q2_6ktable4__C1;

union __Q2_6ktable4__C1 { /* sizeof __Q2_6ktable4__C1 == 8 */
    Ptable k_t;
    Pname k_n;
};

void *__nw__6ktableSFUl(size_t);
void __dl__6ktableSFPvUl(void *, size_t);

extern bit Nold;
extern bit vec_const;

extern bit fct_const;

extern Plist local_class;

extern Pname curr_fct;

extern bit new_type;
extern Pname cl_obj_vec;
extern Pname eobj;
enum Templ_type {
    VANILLA = 0,
    FCT_TEMPLATE = 1,
    CL_TEMPLATE = 2,
    BOUND_TEMPLATE = 3,
    INSTANTIATED = 4,
    UNINSTANTIATED = 5
};

struct type { /* sizeof type == 64 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;
};

TOK kind__4typeFUcN21(struct type *__0this, TOK, TOK, bit);

struct enumdef { /* sizeof enumdef == 96 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    bit e_body__7enumdef;
    short no_of_enumerators__7enumdef;
    unsigned short e_strlen__7enumdef;
    const char *string__7enumdef;
    Pname mem__7enumdef;
    Pbase e_type__7enumdef;
};
struct velem;

struct virt { /* sizeof virt == 56 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pvirt next__4virt;
    int n_init__4virt;
    struct velem *virt_init__4virt;
    Pclass vclass__4virt;
    const char *string__4virt;
    bit is_vbase__4virt;
    bit printed__4virt;
};
enum __E16 { C_VPTR = 1, C_XREF = 2, C_ASS = 4, C_VBASE = 8, C_REFM = 16 };
struct cons;

typedef struct cons *Pcons;
struct basic_template;
typedef struct basic_template *Ptempl_base;
struct toknode;

struct classdef { /* sizeof classdef == 240 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int class_base__8classdef;
    bit c_body__8classdef;
    TOK csu__8classdef;
    bit obj_align__8classdef;
    bit c_xref__8classdef;

    short virt_count__8classdef;

    bit virt_merge__8classdef;

    bit has_vvtab__8classdef;
    unsigned short c_strlen__8classdef;
    Pbcl baselist__8classdef;
    const char *string__8classdef;
    Pname c_abstract__8classdef;
    Pname mem_list__8classdef;
    Ptable memtbl__8classdef;
    Pktab k_tbl__8classdef;
    Ptable c_context__8classdef;
    int obj_size__8classdef;
    int real_size__8classdef;
    Pcons templ_friends__8classdef;
    Plist friend_list__8classdef;
    Pname pubdef__8classdef;
    Ptype this_type__8classdef;
    Pvirt virt_list__8classdef;
    Pname c_ctor__8classdef;
    Pname c_dtor__8classdef;
    Pname c_itor__8classdef;
    Pname c_vtor__8classdef;
    Pname conv__8classdef;
    struct toknode *c_funqf__8classdef;

    struct toknode *c_funqr__8classdef;
};

bit same_class__8classdefFP8classdefi(struct classdef *__0this, Pclass __1p, int);
struct clist;

struct clist { /* sizeof clist == 16 */
    Pclass cl__5clist;
    struct clist *next__5clist;
};

extern struct clist *vcllist;
struct vl;

struct vl { /* sizeof vl == 24 */
    struct vl *next__2vl;
    Pvirt vt__2vl;
    struct classdef *cl__2vl;
};

extern struct vl *vlist;

extern int nin;
extern int Noffset;
extern TOK Nvis;
extern TOK Nvirt;
extern Pexpr Nptr;
extern Pbcl Nvbc_alloc;
extern const char *Nalloc_base;

extern int Vcheckerror;
extern int ignore_const;

extern int mex;
extern Pclass mec;
extern Pclass tcl;
extern int processing_sizeof;
union __Q2_8basetype4__C1;

union __Q2_8basetype4__C1 { /* sizeof __Q2_8basetype4__C1 == 8 */
    Ptype b_fieldtype;
    const char *b_linkage;
};
enum Linkage { linkage_default = 0, linkage_C = 1, linkage_Cplusplus = 2 };

extern int linkage;

void *__nw__3fctSFUl(size_t);
void __dl__3fctSFPvUl(void *, size_t);

struct fct { /* sizeof fct == 208 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int fct_base__3fct;
    TOK nargs__3fct;
    TOK nargs_known__3fct;
    bit last_stmt__3fct;
    bit f_vdef__3fct;

    bit f_inline__3fct;
    bit f_is_inline__3fct;

    bit f_const__3fct;

    bit f_static__3fct;
    short f_virtual__3fct;
    short f_imeasure__3fct;
    Ptype returns__3fct;
    Pname argtype__3fct;
    Ptype s_returns__3fct;
    Pname f_this__3fct;
    Pclass memof__3fct;
    Pclass def_context__3fct;
    Pblock body__3fct;
    Pname f_init__3fct;
    Pexpr f_expr__3fct;
    Pexpr last_expanded__3fct;
    Pname nrv__3fct;
    Pname f_result__3fct;
    Pname f_args__3fct;
    int f_linkage__3fct;
    const char *f_signature__3fct;
    Plist local_class__3fct;
};

extern Pfct fct_free__3fct;
enum gen_types { no_templ = 0, some_templ = 1, all_templ = 2 };

struct gen { /* sizeof gen == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Plist fct_list__3gen;
    int holds_templ__3gen;
};
struct pvtyp;

struct pvtyp { /* sizeof pvtyp == 72 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;
};

void *__nw__3vecSFUl(size_t);
void __dl__3vecSFPvUl(void *, size_t);

struct vec { /* sizeof vec == 88 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;

    Pexpr dim__3vec;
    int size__3vec;
};
extern Pvec vec_free__3vec;

void *__nw__3ptrSFUl(size_t);
void __dl__3ptrSFPvUl(void *, size_t);

struct ptr { /* sizeof ptr == 88 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;

    Pclass memof__3ptr;
    Pname ptname__3ptr;
};
extern Pptr ptr_free__3ptr;


Ptype skiptypedefs__4typeFv(struct type *__0this);

extern int ref_initializer;
extern int ntok;
union __Q2_4expr4__C1;
union __Q2_4expr4__C2;
union __Q2_4expr4__C3;
union __Q2_4expr4__C4;

union __Q2_4expr4__C1 { /* sizeof __Q2_4expr4__C1 == 8 */
    Ptype tp;
    char *string4;
};
union __Q2_4expr4__C2 { /* sizeof __Q2_4expr4__C2 == 8 */
    Pexpr e1;
    long long i1;
    const char *string;
};
union __Q2_4expr4__C3 { /* sizeof __Q2_4expr4__C3 == 8 */
    Pexpr e2;
    int i2;
    const char *string2;
    Pexpr n_initializer;
    Ptype tpdef;
};
union __Q2_4expr4__C4 { /* sizeof __Q2_4expr4__C4 == 8 */
    Ptype tp2;
    Pname fct_name;
    Pexpr cond;
    Pexpr mem;
    Ptype as_type;
    Ptable n_table;
    Pin il;
    Pname query_this;
};

void *__nw__4exprSFUl(size_t);
void __dl__4exprSFPvUl(void *, size_t);

struct expr { /* sizeof expr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};
extern Pexpr expr_free__4expr;

struct expr *__ct__4exprFUcP4exprT2(struct expr *__0this, TOK, Pexpr, Pexpr);

struct texpr { /* sizeof texpr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct cast;

struct cast { /* sizeof cast == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct ival;

struct ival { /* sizeof ival == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct call { /* sizeof call == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct qexpr { /* sizeof qexpr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct ref { /* sizeof ref == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct mdot;

struct mdot { /* sizeof mdot == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct text_expr;

struct text_expr { /* sizeof text_expr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct basecl { /* sizeof basecl == 48 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    TOK ppp__6basecl;
    bit allocated__6basecl;
    bit promoted__6basecl;
    Pclass bclass__6basecl;
    Pexpr init__6basecl;
    int ptr_offset__6basecl;
    int obj_offset__6basecl;
    Pname *virt_init__6basecl;
    struct basecl *next__6basecl;
};
enum template_formal_types {
    template_type_formal = 1,
    template_expr_formal = 2,
    template_actual_arg_dummy = 3
};

extern TOK ppbase;
union __Q2_4name4__C1;
union __Q2_4name4__C2;

union __Q2_4name4__C1 { /* sizeof __Q2_4name4__C1 == 8 */
    Pname n_list;
    Pname n_hidden;
    Pname n_dtag;
};

union __Q2_4name4__C2 { /* sizeof __Q2_4name4__C2 == 8 */

    Pname n_qualifier;
    Ptable n_realscope;
    int syn_class;
};

void *__nw__4nameSFUl(size_t);
void __dl__4nameSFPvUl(void *, size_t);

struct name { /* sizeof name == 144 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;

    TOK n_oper__4name;
    TOK n_sto__4name;
    TOK n_stclass__4name;
    TOK n_scope__4name;
    TOK n_key__4name;
    bit n_evaluated__4name;
    bit n_xref__4name;
    unsigned char lex_level__4name;
    TOK n_protect__4name;
    bit n_dcl_printed__4name;

    char n_template_arg__4name;
    bit n_template_fct__4name;
    bit n_redefined__4name;

    short n_addr_taken__4name;
    short n_used__4name;
    short n_assigned_to__4name;
    struct loc where__4name;
    int n_offset__4name;
    const char *n_anon__4name;

    union __Q2_4name4__C1 __O1__4name;
    Pname n_tbl_list__4name;
    const char *n_gen_fct_name__4name;
    char *n_template_arg_string__4name;
    Pktab n_ktable__4name;

    union __Q2_4name4__C2 __O2__4name;

    long long n_val__4name;

    int argno__4name;
};

extern Pname name_free__4name;

extern int friend_in_class;
extern int in_class_dcl;

extern int in_class_decl;
extern int parsing_class_members;
extern int in_mem_fct;
extern int in_arg_list;
extern Ptype in_typedef;
extern int defer_check;
extern int declTag;
extern Pname in_tag;
extern int DECL_TYPE;
union __Q2_4stmt4__C1;
union __Q2_4stmt4__C2;
union __Q2_4stmt4__C3;

union __Q2_4stmt4__C1 { /* sizeof __Q2_4stmt4__C1 == 8 */
    Pname d;
    Pexpr e2;
    Pstmt has_default;
    int case_value;
    Ptype ret_tp;
};
union __Q2_4stmt4__C2 { /* sizeof __Q2_4stmt4__C2 == 8 */
    Pexpr e;
    bit own_tbl;
    Pstmt s2;
};

union __Q2_4stmt4__C3 { /* sizeof __Q2_4stmt4__C3 == 8 */
    Pstmt for_init;
    Pstmt else_stmt;
    Pstmt case_list;
    struct loc where2;
};

void *__nw__4stmtSFUl(size_t);
void __dl__4stmtSFPvUl(void *, size_t);

struct stmt { /* sizeof stmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};
extern Pstmt stmt_free__4stmt;

extern const char *Neval;
extern Ptable scope;
extern Ptable expand_tbl;
extern Pname expand_fn;

struct stmt *__ct__4stmtFUc3locP4stmt(struct stmt *__0this, TOK, struct loc, Pstmt);

struct estmt { /* sizeof estmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct ifstmt;

struct ifstmt { /* sizeof ifstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct lstmt;

struct lstmt { /* sizeof lstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct forstmt;

struct forstmt { /* sizeof forstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct block { /* sizeof block == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct handler;

struct handler { /* sizeof handler == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct pair;

struct pair { /* sizeof pair == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct nlist { /* sizeof nlist == 16 */
    Pname head__5nlist;
    Pname tail__5nlist;
};

struct slist { /* sizeof slist == 16 */
    Pstmt head__5slist;
    Pstmt tail__5slist;
};

struct elist { /* sizeof elist == 16 */
    Pexpr head__5elist;
    Pexpr tail__5elist;
};
struct dcl_context;

extern struct dcl_context *cc;

extern struct dcl_context *ccvec_end;

struct dcl_context { /* sizeof dcl_context == 48 */
    Pname c_this__11dcl_context;
    Ptype tot__11dcl_context;
    Pname not4__11dcl_context;
    Pclass cot__11dcl_context;
    Ptable ftbl__11dcl_context;
    Pname nof__11dcl_context;
};

extern int error__FiPCc(int, const char *);

extern const char *line_format;

extern Plist stat_mem_list;
extern Plist isf_list;
extern Pstmt st_ilist;
extern Pstmt st_dlist;
extern Ptable sti_tbl;
extern Ptable std_tbl;

extern bit enum_promote;
extern int suppress_error;

extern Pname overFound;
extern Pname Nover;
extern Pname Ncoerce;
extern int Nover_coerce;

struct ia { /* sizeof ia == 32 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname local__2ia;
    Pexpr arg__2ia;
    Ptype tp__2ia;
};

struct iline { /* sizeof iline == 48 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname fct_name__5iline;
    Pin i_next__5iline;
    Ptable i_table__5iline;
    int i_slots__5iline;
    Pia i_args__5iline;
};
struct con_dtor;

struct con_dtor { /* sizeof con_dtor == 24 */
    Pname tn__8con_dtor;
    Pexpr condition__8con_dtor;
    struct con_dtor *next__8con_dtor;
};

extern struct con_dtor *pdlist;
extern Pexpr curr_expr;
extern Pin curr_icall;

extern Pstmt curr_loop;
extern Pblock curr_block;
extern Pstmt curr_switch;
extern struct loc last_line;
extern int last_ll;
extern bit Cast;
extern bit TCast;
extern bit simpl_friend;
extern bit in_return;
extern struct loc no_where;

extern Pname vec_new_fct;
extern Pname new_fct;
extern Pname del_fct;
extern Pname vec_del_fct;

extern int Nstd;

extern int stcount;

extern int Pchecked;

extern Pname Ntmp;
extern Pname Ntmp_refd;
extern Pname Ntmp_flag;
extern Pexpr Ntmp_dtor;

extern Pclass Mptr;

extern bit fake_sizeof;

struct basetype { /* sizeof basetype == 112 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    bit b_unsigned__8basetype;
    bit b_signed__8basetype;
    bit b_volatile__8basetype;
    bit b_typedef__8basetype;
    bit b_inline__8basetype;
    bit b_virtual__8basetype;
    bit b_short__8basetype;
    bit b_long__8basetype;
    bit b_bits__8basetype;
    bit b_offset__8basetype;
    TOK b_sto__8basetype;
    Pname b_name__8basetype;
    Ptable b_table__8basetype;
    Pname b_xname__8basetype;

    union __Q2_8basetype4__C1 __O1__8basetype;
};

extern int error__FiPCcRC2eaN33(int, const char *, const struct ea *, const struct ea *,
                                const struct ea *, const struct ea *);

struct name_list { /* sizeof name_list == 24 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname f__9name_list;
    Plist l__9name_list;
};

struct name *__ct__4nameFPCc(struct name *__0this, const char *);

Pname insert__5tableFP4nameUc(struct table *__0this, Pname, TOK);

extern Pclass current_instantiation;
extern Pfct current_fct_instantiation;
struct templ;

typedef struct templ *Ptempl;
struct funct_inst;
typedef struct funct_inst *Pfunct_inst;
struct templ_inst;
typedef struct templ_inst *Ptempl_inst;
struct basic_inst;
typedef struct basic_inst *Pbase_inst;
struct function_template;

typedef struct function_template *Pfunt;
struct data_template;
typedef struct data_template *Pdata;
struct templ_state;
typedef struct templ_state *Ptstate;
struct templ_classdef;
typedef struct templ_classdef *Ptclass;
struct templ_fct;
typedef struct templ_fct *Ptfct;
struct Pslot;
typedef struct Pslot *Pbinding;

struct cons { /* sizeof cons == 16 */

    void *car__4cons;
    struct cons *cdr__4cons;
};
struct templ_compilation;

extern struct templ_compilation *templp;

struct basic_template { /* sizeof basic_template == 48 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;
};
struct templ { /* sizeof templ == 128 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Ptempl_inst insts__5templ;
    Pbase basep__5templ;
    Pfunt fns__5templ;
    Pfunt fns_end__5templ;
    Pdata data__5templ;
    Pdata data_end__5templ;

    Ptempl next__5templ;
    Pname namep__5templ;
    int defined__5templ;
    Pname members__5templ;
};

struct function_template { /* sizeof function_template == 80 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Pname fn__17function_template;
    Pfunt next__17function_template;
    Pfunt gen_list__17function_template;

    Pfunct_inst insts__17function_template;
};
struct state;

struct state { /* sizeof state == 88 */

    Pname Cdcl__5state;
    Pstmt Cstmt__5state;
    Pname dcl_list__5state;
    struct loc curloc__5state;

    int curr_file__5state;
    Pexpr curr_expr__5state;
    Pin curr_icall__5state;
    Pstmt curr_loop__5state;
    Pblock curr_block__5state;
    Pstmt curr_switch__5state;

    int bound__5state;
    int inline_restr__5state;
    struct loc last_line__5state;
};
struct pointer_hash;
struct tree_copy_info;
enum inst_status {
    uninstantiated = 0,
    function_instantiated = 1,
    data_instantiated = 2,
    class_instantiated = 3,
    body_instantiated = 4
};
struct template_instantiation;

struct basic_inst { /* sizeof basic_inst == 168 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;
};

extern Pbase_inst head__10basic_inst;

struct templ_inst { /* sizeof templ_inst == 200 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;

    Ptempl_inst next__10templ_inst;
    Ptempl_inst forward__10templ_inst;

    Ptempl def__10templ_inst;

    int refp__10templ_inst;

    int friend_refp__10templ_inst;
};

extern int zdebug;

struct templ_classdef { /* sizeof templ_classdef == 248 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int class_base__8classdef;
    bit c_body__8classdef;
    TOK csu__8classdef;
    bit obj_align__8classdef;
    bit c_xref__8classdef;

    short virt_count__8classdef;

    bit virt_merge__8classdef;

    bit has_vvtab__8classdef;
    unsigned short c_strlen__8classdef;
    Pbcl baselist__8classdef;
    const char *string__8classdef;
    Pname c_abstract__8classdef;
    Pname mem_list__8classdef;
    Ptable memtbl__8classdef;
    Pktab k_tbl__8classdef;
    Ptable c_context__8classdef;
    int obj_size__8classdef;
    int real_size__8classdef;
    Pcons templ_friends__8classdef;
    Plist friend_list__8classdef;
    Pname pubdef__8classdef;
    Ptype this_type__8classdef;
    Pvirt virt_list__8classdef;
    Pname c_ctor__8classdef;
    Pname c_dtor__8classdef;
    Pname c_itor__8classdef;
    Pname c_vtor__8classdef;
    Pname conv__8classdef;
    struct toknode *c_funqf__8classdef;

    struct toknode *c_funqr__8classdef;

    Ptempl_inst inst__14templ_classdef;
};

void __dt__8classdefFv(struct classdef *__0this, int);

extern void __dl__FPv(void *);

void *__nw__9templ_fctSFUl(size_t);
void __dl__9templ_fctSFPvUl(void *, size_t);

struct templ_fct { /* sizeof templ_fct == 216 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int fct_base__3fct;
    TOK nargs__3fct;
    TOK nargs_known__3fct;
    bit last_stmt__3fct;
    bit f_vdef__3fct;

    bit f_inline__3fct;
    bit f_is_inline__3fct;

    bit f_const__3fct;

    bit f_static__3fct;
    short f_virtual__3fct;
    short f_imeasure__3fct;
    Ptype returns__3fct;
    Pname argtype__3fct;
    Ptype s_returns__3fct;
    Pname f_this__3fct;
    Pclass memof__3fct;
    Pclass def_context__3fct;
    Pblock body__3fct;
    Pname f_init__3fct;
    Pexpr f_expr__3fct;
    Pexpr last_expanded__3fct;
    Pname nrv__3fct;
    Pname f_result__3fct;
    Pname f_args__3fct;
    int f_linkage__3fct;
    const char *f_signature__3fct;
    Plist local_class__3fct;

    Pfunct_inst inst__9templ_fct;
};

extern Ptfct ptfct_free__9templ_fct;

struct funct_inst { /* sizeof funct_inst == 200 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;

    Pfunct_inst next__10funct_inst;

    Pfunt def__10funct_inst;
    int refp__10funct_inst;
    int friend_refp__10funct_inst;
    Pbinding binding__10funct_inst;
};

#pragma lib "ape/libap.a"

typedef int (*GPT)(int, char *);
struct Block_CPchar;

struct Block_CPchar { /* sizeof Block_CPchar == 16 */

    CPchar *p__12Block_CPchar;

    size_t n__12Block_CPchar;
};

void move__12Block_CPcharFPPCcUl(struct Block_CPchar *__0this, CPchar *, size_t);

void copy__12Block_CPcharFRC12Block_CPchar(struct Block_CPchar *__0this,
                                           const struct Block_CPchar *);

size_t grow__12Block_CPcharFUl(struct Block_CPchar *__0this, size_t);
struct Block_Pchar;
struct Block_Pchar { /* sizeof Block_Pchar == 16 */

    Pchar *p__11Block_Pchar;

    size_t n__11Block_Pchar;
};

void move__11Block_PcharFPPcUl(struct Block_Pchar *__0this, Pchar *, size_t);

void copy__11Block_PcharFRC11Block_Pchar(struct Block_Pchar *__0this, const struct Block_Pchar *);

size_t grow__11Block_PcharFUl(struct Block_Pchar *__0this, size_t);
extern struct Block_Pchar instfct;
extern int noinst;
extern struct Block_Pchar instdata;
extern int nodatainst;
extern bit tempdcl;
extern bit mk_zero_init_flag;
extern int first_file;
extern bit all_flag;

extern bit alltc_flag;

extern bit data_flag;

extern bit ft_flag;

extern bit none_flag;

extern Pname righttname;

const char *prog_name = (const char *)"<<AT&T C++ Language System <3.0.3> 05/05/94>>";
static const char *prog_vers = (const char *)"__cfront_version_303_xxxxxxxx";
const char *src_file_name = (const char *)"";
const char *line_format = (const char *)"\n# %d \"%s\"\n";

struct Block_Pchar instfct = {0};

struct Block_Pchar instdata = {0};
bit all_flag = 0;

bit alltc_flag = 0;

bit data_flag = 0;

bit ft_flag = 0;

bit none_flag = 0;
int noinst = 0;

int nodatainst = 0;

extern void *_get_stderr(void);

extern int fprintf(void *, const char *, ...);

extern void ext__Fi(int);


Plist isf_list = 0;
Pstmt st_ilist = 0;
Pstmt st_dlist = 0;
Ptable sti_tbl = 0;
Ptable std_tbl = 0;
Plist stat_mem_list = 0;

int vtbl_opt = -1;

int debug_opt = 0;
static int gplus_opt;
int ansi_opt = 1;
int strict_opt = 0;

int warning_opt = 0;
int dem_opt_local = 0;
int dem_opt_mem = 0;
int perf_opt = 0;

int pt_opt = 0;
int dtpt_opt = 0;
int se_opt = 0;
bit stmtno = 0;

int inline_opt = 0;

Pname def_name = 0;
Pname pdef_name = 0;

int syn_count = 0;

extern Pname syn__Fv(void);

struct templ_compilation { /* sizeof templ_compilation == 1 */

    char __W29__17templ_compilation;
};

extern Plist param_end__17templ_compilation;
extern Ptempl list__17templ_compilation;
extern Pfunt f_list__17templ_compilation;
extern Pfunt f_owner__17templ_compilation;
extern Ptempl owner__17templ_compilation;
extern Ptempl_base parsed_template__17templ_compilation;

extern Plist params__17templ_compilation;
extern Pexpr actuals__17templ_compilation;
extern Ptable templates__17templ_compilation;

extern int in_progress__17templ_compilation;
extern Ptstate save_templ__17templ_compilation;

extern int parameters_in_progress__17templ_compilation;
extern int formals_in_progress__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;
extern Pcons friend_templ_refs__17templ_compilation;
extern Pcons last_cons__17templ_compilation;
extern Pcons last_friend_cons__17templ_compilation;

void instantiate_ref_templ__17templ_compilationFv(struct templ_compilation *__0this);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void simpl__4nameFv(struct name *__0this);

void dcl_print__4nameFUc(struct name *__0this, TOK);

void dcl_print__7enumdefFP4name(struct enumdef *__0this, Pname);

extern int strcmp(const char *, const char *);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

void del__4exprFv(struct expr *__0this);

extern void delete_local__Fv(void);

void del__4stmtFv(struct stmt *__0this);

void del__4nameFv(struct name *__0this);

extern void lex_clear__Fv(void);

void end_of_compilation__17templ_compilationFv(struct templ_compilation *__0this);

bit tconst__4typeFv(struct type *__0this);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

extern char *st_name__FPCc(const char *);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

void sign__3fctFv(struct fct *__0this);

void really_print__8classdefFP4virt(struct classdef *__0this, Pvirt);

extern int ispt_data__FP4name(Pname);

Pname is_cl_obj__4typeFv(struct type *__0this);

int tsizeof__4typeFi(struct type *__0this, int);

Pptr is_ref__4typeFv(struct type *__0this);

extern size_t strlen(const char *);

extern char *strncpy(char *, const char *, size_t);

extern void ptbl_add_pair__FPCcT1(const char *, const char *);

extern void ptbl_init__Fi(int);

void putline__3locFv(struct loc *__0this);



extern __sighandler_t signal(int __0__sig, __sighandler_t __0__handler);

extern void error_init__Fv(void);

extern int atoi(const char *);

extern int read_align__FPCc(const char *);

extern void exit(int);

extern void *fopen(const char *, const char *);

extern int fscanf(void *, const char *, ...);

extern char *strcpy(char *, const char *);

extern int fflush(void *__0stream);

extern void otbl_init__Fv(void);

extern void lex_init__Fv(void);

extern void syn_init__Fv(void);

extern void typ_init__Fv(void);

extern void simpl_init__Fv(void);

extern int error__FPCc(const char *);

extern int isalpha(int);

extern int isdigit(int);




extern Ptfct ptfct_free__9templ_fct;

extern Pbase_inst head__10basic_inst;

extern Pcons last_friend_cons__17templ_compilation;

extern Pcons last_cons__17templ_compilation;

extern Pcons friend_templ_refs__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;

extern int formals_in_progress__17templ_compilation;

extern int parameters_in_progress__17templ_compilation;

extern Ptstate save_templ__17templ_compilation;

extern int in_progress__17templ_compilation;

extern Ptable templates__17templ_compilation;

extern Pexpr actuals__17templ_compilation;

extern Plist params__17templ_compilation;

extern Ptempl_base parsed_template__17templ_compilation;

extern Ptempl owner__17templ_compilation;

extern Pfunt f_owner__17templ_compilation;

extern Pfunt f_list__17templ_compilation;

extern Ptempl list__17templ_compilation;

extern Plist param_end__17templ_compilation;

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */

