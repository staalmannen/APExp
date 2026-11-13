#ifndef __SIGNAL_H
#define __SIGNAL_H
#pragma lib "/$M/lib/ape/libap.a"

#include <sys/types.h>
/*
 * `<features.h>' IS FOR `__restrict', AND IT IS LOAD-BEARING RATHER
 * THAN TIDY.  The prototypes below are spelled with `__restrict'
 * because `restrict' is a C keyword and not a C++ one, so in C++ a
 * bare `restrict' reads as a PARAMETER NAME and two per prototype is
 * `duplicate parameter name'.  That much was already recorded here.
 *
 * ***WHAT WAS NOT TRUE IS THAT `__restrict' NEEDS NO HELP.***  It is
 * reserved to the implementation, so nothing outside one may define
 * it -- but being reserved does not make it a KEYWORD, and a C++
 * compiler only has it if it chooses to.  EDG's `cpfe' enters
 * `__restrict' only under `gnu_restrict_keyword_enabled'
 * (`fe_init.c:54193'), which g++ and Microsoft modes set and the
 * default C++ mode does not -- so `<csignal>' answered
 * `signal.h, line 176: error: duplicate parameter name', the very
 * error the `__restrict' spelling was adopted to fix.
 *
 * `features.h' already holds the answer and is musl's own: with
 * neither C99 nor `__GNUC__' in play -- which is exactly C++ here --
 * it defines `__restrict' to nothing.  `<regex.h>', `<spawn.h>' and
 * `<sys/stat.h>' already include it for the same reason.
 *
 * ***AND IT IS GUARDED BY `__cplusplus' WHERE THE OTHER THREE ARE
 * NOT, WHICH IS A DELIBERATE ASYMMETRY AND THE REASON IS MEASURED.***
 * `features.h' does three other things besides `__restrict': it
 * defaults `_BSD_SOURCE' and `_XOPEN_SOURCE 700' when no source macro
 * is set, and it defines `__inline' and `_Noreturn' UNGUARDED.  Under
 * `sys/src/external', 12 packages define `__restrict' themselves, 20
 * define `__inline' and **68 define `_Noreturn'** -- gnulib's
 * `config.h', which is included before any system header, so
 * `features.h' redefines what the package just defined.
 *
 * That is already true of every translation unit reaching
 * `<sys/stat.h>', `<regex.h>', `<spawn.h>' or the seven others that
 * include `features.h' unconditionally, so it is not a new hazard --
 * but `<signal.h>' is reached by far more C than any of them, and the
 * C side does not need this include at all: kencc lexes `__restrict'
 * as a keyword already (`cc/lex.c:1678').  *Widening the C build's
 * macro environment to fix a C++ bug would be paying on the side that
 * has no fault.*
 *
 * To make it unconditional, the thing to measure first is a full
 * `mk install' with it so: the failure would be a macro redefinition
 * in one of those 68, and it would name the package rather than this
 * header.
 */
#ifdef __cplusplus
#include <features.h>
#endif

typedef int sig_atomic_t;

/*
 * A HANDLER IS `void (*)(int)', WHICH IS WHAT C AND POSIX SAY.
 *
 * It used to be the UNPROTOTYPED `void (*)()' here, under a comment
 * explaining that libap dispatches
 *
 *	void handler(int sig, char *msg, struct Ureg *u)
 *
 * -- the Plan 9 note string and the trap frame -- and that a
 * prototype would stop a program from asking for them.
 *
 * **The extension is still there and still dispatched**; what changed
 * is that the public declaration no longer LIES to every ordinary
 * caller to keep it reachable. An empty parameter list turns off
 * checking for everybody: this tree's own invariant is that a call
 * with no prototype in scope corrupts its arguments under kencc,
 * since `sizeof' is 32-bit and the return value is worse -- and here
 * the thing left unchecked is a FUNCTION POINTER a program installs
 * and the library later calls.
 *
 * *It was also not even true of libap*: `signal/signal.c' defines
 * `signal()' with the three-argument type, so the header and the
 * definition have always disagreed, and only the empty parameter
 * list made that legal.
 *
 * **Nothing in this tree uses the extension** -- swept: the only
 * files mentioning `Ureg' outside libap are go1.4's own runtime,
 * which is not built here and does not go through this `signal()'.
 * A program that wants the extra arguments casts, which is what it
 * would have to do on any other system anyway.
 *
 * The three macros move WITH the declaration and cannot be left
 * behind: they are what callers compare the return value against and
 * assign to `sa_handler', so a mismatched pair is a diagnostic in
 * every file that mentions them.
 */
#define SIG_DFL ((void (*)(int))0)
#define SIG_ERR ((void (*)(int))-1)
#define SIG_IGN ((void (*)(int))1)

#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught)*/
#define SIGABRT 5	/* used by abort */
#define	SIGFPE	6	/* floating point exception */
#define	SIGKILL	7	/* kill (cannot be caught or ignored) */
#define	SIGSEGV	8	/* segmentation violation */
#define	SIGPIPE	9	/* write on a pipe with no one to read it */
#define	SIGALRM	10	/* alarm clock */
#define	SIGTERM	11	/* software termination signal from kill */
#define	SIGUSR1	12	/* user defined signal 1 */
#define	SIGUSR2	13	/* user defined signal 2 */
#define	SIGBUS	14	/* bus error */

/* The following symbols must be defined, but the signals needn't be supported */
#define SIGCHLD	15	/* child process terminated or stopped */
#define SIGCONT 16	/* continue if stopped */
#define SIGSTOP 17	/* stop */
#define SIGTSTP	18	/* interactive stop */
#define SIGTTIN	19	/* read from ctl tty by member of background */
#define SIGTTOU	20	/* write to ctl tty by member of background */
#define SIGWINCH 21	/* window size changes */
#define SIGVTALRM 22 /* virtual alarm clock */
#define SIGPROF 23  /* profiling alarm clock */

#define SIGTRAP   24  /* not supported, defined for compatibility */
#define SIGURG    25
#define SIGXCPU   26
#define SIGXFSZ   27

#define NSIG 28

#ifdef __cplusplus
extern "C" {
#endif

extern void (*signal(int, void (*)(int)))(int);
extern int raise(int);
extern char *strsignal(int);
extern void psignal(int, const char *);

#ifdef __cplusplus
}
#endif

typedef long sigset_t;

/* sigval: integer or pointer payload for real-time signals / sigevent */
union sigval {
	int	sigval_int;
	void   *sigval_ptr;
};

/* siginfo_t: signal origin info passed to SA_SIGINFO handlers.
 * Plan 9 does not supply most of these fields; they are zero-filled. */
typedef struct {
	int	si_signo;
	int	si_errno;
	int	si_code;
	pid_t	si_pid;
	uid_t	si_uid;
	void   *si_addr;
	int	si_status;
	long	si_band;
	union sigval si_value;
} siginfo_t;

struct sigaction {
	union {
		void		(*sa_handler)(int);
		void		(*sa_sigaction)(int, siginfo_t *, void *);
	};
	sigset_t	sa_mask;
	int		sa_flags;
};
/* values for sa_flags */
  #define SA_NOCLDSTOP  0x001
  #define SA_ONSTACK    0x002
  #define SA_RESETHAND  0x004
  #define SA_RESTART    0x008
  #define SA_RESTORER   0x010
  #define SA_NODEFER    0x020
  #define SA_SIGINFO    0x040   /* use sa_sigaction; Plan 9 passes zero siginfo */

/* si_code values for siginfo_t */
#define SI_USER		0	/* sent by kill() */
#define SI_QUEUE	-1	/* sent by sigqueue() */
#define SI_TIMER	-2	/* timer expiration */
#define SI_ASYNCIO	-3	/* async I/O completion */
#define SI_MESGQ	-4	/* message queue arrival */

/* first argument to sigprocmask */
#define SIG_BLOCK	1
#define SIG_UNBLOCK	2
#define SIG_SETMASK	3

#ifdef __cplusplus
extern "C" {
#endif

extern int kill(pid_t, int);
extern int killpg(pid_t, int);
extern int sigemptyset(sigset_t *);
extern int sigfillset(sigset_t *);
extern int sigaddset(sigset_t *, int);
extern int sigdelset(sigset_t *, int);
extern int sigismember(const sigset_t *, int);
extern int sigaction(int, const struct sigaction *, struct sigaction *);
extern int sigprocmask(int, sigset_t *, sigset_t *);
extern int sigpending(sigset_t *);
extern int sigsuspend(const sigset_t *);
/*
 * `__restrict' RATHER THAN `restrict', AND IT COSTS NOTHING: kencc
 * lexes all three spellings to the same LRESTRICT (`cc/lex.c:1652,
 * 1678-1679'). `restrict' is a C keyword and NOT a C++ one, so in C++
 * these read as PARAMETER NAMES -- and two per prototype is then a
 * duplicate parameter name, which is why a C++ compiler could not
 * read these three lines at all.
 *
 * `#define restrict' away for C++ would be the wrong fix twice over:
 * it is an unreserved name, and gnulib's `config.h' already defines
 * it in a dozen packages here. `__restrict' is reserved, so nothing
 * outside an implementation may define it -- and where a package's
 * own `cdefs.h' does (twelve do), it expands to the qualifier or to
 * nothing, which is correct either way.
 *
 * ***AND THAT LAST SENTENCE WAS NOT THE WHOLE ANSWER.*** Reserving a
 * name says who may DEFINE it; it does not say any compiler has it.
 * EDG's default C++ mode does not, so this file needed <features.h>
 * to define it away -- see the note at the top. `<glob.h>',
 * `<search.h>' and `<regex.h>' use the same spelling and already
 * included `features.h'; this header was the ONE that did not, which
 * is why `<csignal>' was the only one of the fifty C++ headers to
 * fail on it. *The spelling was right and the prerequisite was
 * missing.*
 */
extern int sigwait(const sigset_t *__restrict, int *__restrict);
extern int sigwaitinfo(const sigset_t *__restrict, siginfo_t *__restrict);
struct timespec;	/* avoid pulling in time.h */
extern int sigtimedwait(const sigset_t *__restrict, siginfo_t *__restrict, const struct timespec *__restrict);
extern int sigqueue(pid_t, int, const union sigval);

/*
 * struct sigevent's only use of it is a pointer, so the typedef is all
 * that is wanted here -- and <pthread.h> reaches <lock.h> and so Plan
 * 9's <u.h>, which defines nil, uchar, ushort, ulong and uint. See the
 * note in <string.h>.
 */
#ifndef _PTHREAD_ATTR_T
#define _PTHREAD_ATTR_T
typedef int pthread_attr_t;
#endif

/* sigev_notify values */
#define SIGEV_NONE    0   /* no notification */
#define SIGEV_SIGNAL  1   /* deliver sigev_signo */
#define SIGEV_THREAD  2   /* call sigev_notify_function in new thread */

struct sigevent {
	int             sigev_notify;  /* Notification type (SIGEV_*) */
	int             sigev_signo;   /* Signal number (SIGEV_SIGNAL) */
	union sigval    sigev_value;   /* Data passed with notification */
	void          (*sigev_notify_function)(union sigval); /* SIGEV_THREAD */
	pthread_attr_t *sigev_notify_attributes;
};



#ifdef __cplusplus
}
#endif

#endif /* __SIGNAL_H */
