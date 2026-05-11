;;;; posixunix.scm - Miscellaneous file- and process-handling routines
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer.
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution.
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.


;; these are not available on Windows

(define-foreign-variable _stat_st_blksize unsigned-int "C_statbuf.st_blksize")
(define-foreign-variable _stat_st_blocks unsigned-int "C_statbuf.st_blocks")

(include "posix-common.scm")

#>

static C_TLS int C_wait_status;

#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <utime.h>

#if defined(__sun) && defined(__SVR4)
# include <sys/tty.h>
# include <termios.h>
#endif

#include <sys/mman.h>
#include <poll.h>

#ifndef O_FSYNC
# define O_FSYNC O_SYNC
#endif

#ifndef PIPE_BUF
# ifdef __CYGWIN__
#  define PIPE_BUF       _POSIX_PIPE_BUF
# else
#  define PIPE_BUF 1024
# endif
#endif

#ifndef O_BINARY
# define O_BINARY        0
#endif
#ifndef O_TEXT
# define O_TEXT          0
#endif

#ifndef MAP_FILE
# define MAP_FILE    0
#endif

#ifndef MAP_ANON
# define MAP_ANON    0
#endif

#ifndef FILENAME_MAX
# define FILENAME_MAX          1024
#endif

static C_TLS struct flock C_flock;
static C_TLS DIR *temphandle;
static C_TLS struct passwd *C_user;

/* Android doesn't provide pw_gecos in the passwd struct */
#ifdef __ANDROID__
# define C_PW_GECOS ("")
#else
# define C_PW_GECOS (C_user->pw_gecos)
#endif

static C_TLS int C_pipefds[ 2 ];
static C_TLS time_t C_secs;
static C_TLS struct timeval C_timeval;
static C_TLS struct stat C_statbuf;

#define C_fchdir(fd)        C_fix(fchdir(C_unfix(fd)))

#define open_binary_input_pipe(a, n, name)   C_mpointer(a, popen(C_c_string(name), "r"))
#define open_text_input_pipe(a, n, name)     open_binary_input_pipe(a, n, name)
#define open_binary_output_pipe(a, n, name)  C_mpointer(a, popen(C_c_string(name), "w"))
#define open_text_output_pipe(a, n, name)    open_binary_output_pipe(a, n, name)
#define close_pipe(p)                        C_fix(pclose(C_port_file(p)))

#define C_fork              fork
#define C_waitpid(id, o)    C_fix(waitpid(C_unfix(id), &C_wait_status, C_unfix(o)))
#define C_getppid           getppid
#define C_kill(id, s)       C_fix(kill(C_unfix(id), C_unfix(s)))
#define C_getuid            getuid
#define C_getgid            getgid
#define C_geteuid           geteuid
#define C_getegid           getegid
#define C_chown(fn, u, g)   C_fix(chown(C_c_string(fn), C_unfix(u), C_unfix(g)))
#define C_fchown(fd, u, g)  C_fix(fchown(C_unfix(fd), C_unfix(u), C_unfix(g)))
#define C_chmod(fn, m)      C_fix(chmod(C_c_string(fn), C_unfix(m)))
#define C_fchmod(fd, m)     C_fix(fchmod(C_unfix(fd), C_unfix(m)))
#define C_setuid(id)        C_fix(setuid(C_unfix(id)))
#define C_setgid(id)        C_fix(setgid(C_unfix(id)))
#define C_seteuid(id)       C_fix(seteuid(C_unfix(id)))
#define C_setegid(id)       C_fix(setegid(C_unfix(id)))
#define C_setsid(dummy)     C_fix(setsid())
#define C_setpgid(x, y)     C_fix(setpgid(C_unfix(x), C_unfix(y)))
#define C_getpgid(x)        C_fix(getpgid(C_unfix(x)))
#define C_symlink(o, n)     C_fix(symlink(C_c_string(o), C_c_string(n)))
#define C_do_readlink(f, b) C_fix(readlink(C_c_string(f), C_c_string(b), FILENAME_MAX))
#define C_getpwnam(n)       C_mk_bool((C_user = getpwnam(C_c_string(n))) != NULL)
#define C_getpwuid(u)       C_mk_bool((C_user = getpwuid(C_unfix(u))) != NULL)
#define C_pipe(d)           C_fix(pipe(C_pipefds))
#define C_truncate(f, n)    C_fix(truncate(C_c_string(f), C_num_to_int(n)))
#define C_ftruncate(f, n)   C_fix(ftruncate(C_unfix(f), C_num_to_int(n)))
#define C_alarm             alarm
#define C_close(fd)         C_fix(close(C_unfix(fd)))
#define C_umask(m)          C_fix(umask(C_unfix(m)))

#define C_u_i_lstat(fn)     C_fix(lstat(C_c_string(fn), &C_statbuf))

#define C_u_i_execvp(f,a)   C_fix(execvp(C_c_string(f), (char *const *)C_c_pointer_vector_or_null(a)))
#define C_u_i_execve(f,a,e) C_fix(execve(C_c_string(f), (char *const *)C_c_pointer_vector_or_null(a), (char *const *)C_c_pointer_vector_or_null(e)))

static C_TLS int C_uw;
#define C_WIFEXITED(n)      (C_uw = C_unfix(n), C_mk_bool(WIFEXITED(C_uw)))
#define C_WIFSIGNALED(n)    (C_uw = C_unfix(n), C_mk_bool(WIFSIGNALED(C_uw)))
#define C_WIFSTOPPED(n)     (C_uw = C_unfix(n), C_mk_bool(WIFSTOPPED(C_uw)))
#define C_WEXITSTATUS(n)    (C_uw = C_unfix(n), C_fix(WEXITSTATUS(C_uw)))
#define C_WTERMSIG(n)       (C_uw = C_unfix(n), C_fix(WTERMSIG(C_uw)))
#define C_WSTOPSIG(n)       (C_uw = C_unfix(n), C_fix(WSTOPSIG(C_uw)))

#ifdef __CYGWIN__
# define C_mkfifo(fn, m)    C_fix(-1)
#else
# define C_mkfifo(fn, m)    C_fix(mkfifo(C_c_string(fn), C_unfix(m)))
#endif

#define C_flock_setup(t, s, n) (C_flock.l_type = C_unfix(t), C_flock.l_start = C_num_to_int(s), C_flock.l_whence = SEEK_SET, C_flock.l_len = C_num_to_int(n), C_SCHEME_UNDEFINED)
#define C_flock_test(p)     (fcntl(fileno(C_port_file(p)), F_GETLK, &C_flock) >= 0 ? (C_flock.l_type == F_UNLCK ? C_fix(0) : C_fix(C_flock.l_pid)) : C_SCHEME_FALSE)
#define C_flock_lock(p)     C_fix(fcntl(fileno(C_port_file(p)), F_SETLK, &C_flock))
#define C_flock_lockw(p)    C_fix(fcntl(fileno(C_port_file(p)), F_SETLKW, &C_flock))

static C_TLS sigset_t C_sigset;
#define C_sigemptyset(d)    (sigemptyset(&C_sigset), C_SCHEME_UNDEFINED)
#define C_sigaddset(s)      (sigaddset(&C_sigset, C_unfix(s)), C_SCHEME_UNDEFINED)
#define C_sigdelset(s)      (sigdelset(&C_sigset, C_unfix(s)), C_SCHEME_UNDEFINED)
#define C_sigismember(s)    C_mk_bool(sigismember(&C_sigset, C_unfix(s)))
#define C_sigprocmask_set(d)        C_fix(sigprocmask(SIG_SETMASK, &C_sigset, NULL))
#define C_sigprocmask_block(d)      C_fix(sigprocmask(SIG_BLOCK, &C_sigset, NULL))
#define C_sigprocmask_unblock(d)    C_fix(sigprocmask(SIG_UNBLOCK, &C_sigset, NULL))
#define C_sigprocmask_get(d)        C_fix(sigprocmask(SIG_SETMASK, NULL, &C_sigset))

#define C_open(fn, fl, m)   C_fix(open(C_c_string(fn), C_unfix(fl), C_unfix(m)))
#define C_read(fd, b, n)    C_fix(read(C_unfix(fd), C_data_pointer(b), C_unfix(n)))
#define C_write(fd, b, n)   C_fix(write(C_unfix(fd), C_data_pointer(b), C_unfix(n)))
#define C_mkstemp(t)        C_fix(mkstemp(C_c_string(t)))

#define C_ctime(n)          (C_secs = (n), ctime(&C_secs))

#if defined(__SVR4) || defined(C_MACOSX) || defined(__ANDROID__) || defined(_AIX)
/* Seen here: http://lists.samba.org/archive/samba-technical/2002-November/025571.html */

static time_t C_timegm(struct tm *t)
{
  time_t tl, tb;
  struct tm *tg;

  tl = mktime (t);
  if (tl == -1)
    {
      t->tm_hour--;
      tl = mktime (t);
      if (tl == -1)
        return -1; /* can't deal with output from strptime */
      tl += 3600;
    }
  tg = gmtime (&tl);
  tg->tm_isdst = 0;
  tb = mktime (tg);
  if (tb == -1)
    {
      tg->tm_hour--;
      tb = mktime (tg);
      if (tb == -1)
        return -1; /* can't deal with output from gmtime */
      tb += 3600;
    }
  return (tl - (tb - tl));
}
#else
#define C_timegm timegm
#endif

#define C_a_timegm(ptr, c, v, tm)  C_int64_to_num(ptr, C_timegm(C_tm_set((v), C_data_pointer(tm))))

#ifdef __linux__
extern char *strptime(const char *s, const char *format, struct tm *tm);
extern pid_t getpgid(pid_t pid);
#endif

/* tm_get could be in posix-common, but it's only used in here */
#define cpy_tmstc08_to_tmvec(v, ptm) \
    (C_set_block_item((v), 0, C_fix(((struct tm *)ptm)->tm_sec)), \
    C_set_block_item((v), 1, C_fix((ptm)->tm_min)), \
    C_set_block_item((v), 2, C_fix((ptm)->tm_hour)), \
    C_set_block_item((v), 3, C_fix((ptm)->tm_mday)), \
    C_set_block_item((v), 4, C_fix((ptm)->tm_mon)), \
    C_set_block_item((v), 5, C_fix((ptm)->tm_year)), \
    C_set_block_item((v), 6, C_fix((ptm)->tm_wday)), \
    C_set_block_item((v), 7, C_fix((ptm)->tm_yday)), \
    C_set_block_item((v), 8, ((ptm)->tm_isdst ? C_SCHEME_TRUE : C_SCHEME_FALSE)))

#define cpy_tmstc9_to_tmvec(v, ptm) \
    (C_set_block_item((v), 9, C_fix(-(ptm)->tm_gmtoff)))

#define C_tm_get_08(v, tm)  cpy_tmstc08_to_tmvec( (v), (tm) )
#define C_tm_get_9(v, tm)   cpy_tmstc9_to_tmvec( (v), (tm) )

static C_word
C_tm_get( C_word v, void *tm )
{
  C_tm_get_08( v, (struct tm *)tm );
#if defined(C_GNU_ENV) && !defined(__CYGWIN__) && !defined(__uClinux__)
  C_tm_get_9( v, (struct tm *)tm );
#endif
  return v;
}

#define C_strptime(s, f, v, stm) \
        (strptime(C_c_string(s), C_c_string(f), ((struct tm *)(stm))) ? C_tm_get((v), (stm)) : C_SCHEME_FALSE)

static int set_file_mtime(char *filename, C_word atime, C_word mtime)
{
  struct stat sb;
  struct utimbuf tb;

  /* Only lstat if needed */
  if (atime == C_SCHEME_FALSE || mtime == C_SCHEME_FALSE) {
    if (lstat(filename, &sb) == -1) return -1;
  }

  if (atime == C_SCHEME_FALSE) {
    tb.actime = sb.st_atime;
  } else {
    tb.actime = C_num_to_int64(atime);
  }
  if (mtime == C_SCHEME_FALSE) {
    tb.modtime = sb.st_mtime;
  } else {
    tb.modtime = C_num_to_int64(mtime);
  }
  return utime(filename, &tb);
}

<#

;; Faster versions of common operations

(define ##sys#file-nonblocking!
  (foreign-lambda* bool ([int fd])
    "int val = fcntl(fd, F_GETFL, 0);"
    "if(val == -1) C_return(0);"
    "C_return(fcntl(fd, F_SETFL, val | O_NONBLOCK) != -1);" ) )

(define ##sys#file-select-one (foreign-lambda int "C_check_fd_ready" int) )

;;; Lo-level I/O:

(define-foreign-variable _f_dupfd int "F_DUPFD")
(define-foreign-variable _f_getfd int "F_GETFD")
(define-foreign-variable _f_setfd int "F_SETFD")
(define-foreign-variable _f_getfl int "F_GETFL")
(define-foreign-variable _f_setfl int "F_SETFL")

(set! chicken.file.posix#fcntl/dupfd _f_dupfd)
(set! chicken.file.posix#fcntl/getfd _f_getfd)
(set! chicken.file.posix#fcntl/setfd _f_setfd)
(set! chicken.file.posix#fcntl/getfl _f_getfl)
(set! chicken.file.posix#fcntl/setfl _f_setfl)

(define-foreign-variable _o_nonblock int "O_NONBLOCK")
(define-foreign-variable _o_noctty int "O_NOCTTY")
(define-foreign-variable _o_fsync int "O_FSYNC")
(define-foreign-variable _o_sync int "O_SYNC")
(set! chicken.file.posix#open/nonblock _o_nonblock)
(set! chicken.file.posix#open/noctty _o_noctty)
(set! chicken.file.posix#open/fsync _o_fsync)
(set! chicken.file.posix#open/sync _o_sync)

;; Windows-only definitions
(set! chicken.file.posix#open/noinherit 0)

(set! chicken.process#spawn/overlay 0)
(set! chicken.process#spawn/wait 0)
(set! chicken.process#spawn/nowait 0)
(set! chicken.process#spawn/nowaito 0)
(set! chicken.process#spawn/detach 0)

(define-foreign-variable _s_isuid int "S_ISUID")
(define-foreign-variable _s_isgid int "S_ISGID")
(define-foreign-variable _s_isvtx int "S_ISVTX")
(set! chicken.file.posix#perm/isvtx _s_isvtx)
(set! chicken.file.posix#perm/isuid _s_isuid)
(set! chicken.file.posix#perm/isgid _s_isgid)

(set! chicken.file.posix#file-control
  (let ([fcntl (foreign-lambda int fcntl int int long)])
    (lambda (fd cmd #!optional (arg 0))
      (##sys#check-fixnum fd 'file-control)
      (##sys#check-fixnum cmd 'file-control)
      (let ([res (fcntl fd cmd arg)])
        (if (fx= res -1)
            (posix-error #:file-error 'file-control "cannot control file" fd cmd)
            res ) ) ) ) )

(set! chicken.file.posix#file-open
  (let ((defmode (bitwise-ior _s_irusr _s_iwusr _s_irgrp _s_iwgrp _s_iroth _s_iwoth)))
    (lambda (filename flags . mode)
      (let ([mode (if (pair? mode) (car mode) defmode)])
        (##sys#check-string filename 'file-open)
        (##sys#check-fixnum flags 'file-open)
        (##sys#check-fixnum mode 'file-open)
        (let ([fd (##core#inline "C_open" (##sys#make-c-string filename 'file-open) flags mode)])
          (when (eq? -1 fd)
            (posix-error #:file-error 'file-open "cannot open file" filename flags mode) )
          fd) ) ) ) )

(set! chicken.file.posix#file-close
  (lambda (fd)
    (##sys#check-fixnum fd 'file-close)
    (let loop ()
      (when (fx< (##core#inline "C_close" fd) 0)
	(cond
	  ((fx= _errno _eintr) (##sys#dispatch-interrupt loop))
	  (else
	   (posix-error #:file-error 'file-close "cannot close file" fd)))))))

(set! chicken.file.posix#file-read
  (lambda (fd size . buffer)
    (##sys#check-fixnum fd 'file-read)
    (##sys#check-fixnum size 'file-read)
    (let ([buf (if (pair? buffer) (car buffer) (make-string size))])
      (unless (and (##core#inline "C_blockp" buf) (##core#inline "C_byteblockp" buf))
	(##sys#signal-hook #:type-error 'file-read "bad argument type - not a string or blob" buf) )
      (let ([n (##core#inline "C_read" fd buf size)])
	(when (eq? -1 n)
	  (posix-error #:file-error 'file-read "cannot read from file" fd size) )
	(list buf n) ) ) ) )

(set! chicken.file.posix#file-write
  (lambda (fd buffer . size)
    (##sys#check-fixnum fd 'file-write)
    (unless (and (##core#inline "C_blockp" buffer) (##core#inline "C_byteblockp" buffer))
      (##sys#signal-hook #:type-error 'file-write "bad argument type - not a string or blob" buffer) )
    (let ([size (if (pair? size) (car size) (##sys#size buffer))])
      (##sys#check-fixnum size 'file-write)
      (let ([n (##core#inline "C_write" fd buffer size)])
        (when (eq? -1 n)
          (posix-error #:file-error 'file-write "cannot write to file" fd size) )
        n) ) ) )

(set! chicken.file.posix#file-mkstemp
  (lambda (template)
    (##sys#check-string template 'file-mkstemp)
    (let* ([buf (##sys#make-c-string template 'file-mkstemp)]
	   [fd (##core#inline "C_mkstemp" buf)]
	   [path-length (##sys#size buf)])
      (when (eq? -1 fd)
	(posix-error #:file-error 'file-mkstemp "cannot create temporary file" template) )
      (values fd (##sys#substring buf 0 (fx- path-length 1) ) ) ) ) )


;;; I/O multiplexing:

(set! chicken.file.posix#file-select
  (lambda (fdsr fdsw . timeout)
    (let* ((tm (if (pair? timeout) (car timeout) #f))
	   (fdsrl (cond ((not fdsr) '())
			((fixnum? fdsr) (list fdsr))
			(else (##sys#check-list fdsr 'file-select)
			      fdsr)))
	   (fdswl (cond ((not fdsw) '())
			((fixnum? fdsw) (list fdsw))
			(else (##sys#check-list fdsw 'file-select)
			      fdsw)))
	   (nfdsr (##sys#length fdsrl))
	   (nfdsw (##sys#length fdswl))
	   (nfds (fx+ nfdsr nfdsw))
	   (fds-blob (##sys#make-blob
		      (fx* nfds (foreign-value "sizeof(struct pollfd)" int)))))
      (do ((i 0 (fx+ i 1))
	   (fdsrl fdsrl (cdr fdsrl)))
	  ((null? fdsrl))
	((foreign-lambda* void ((int i) (int fd) (scheme-pointer p))
	   "struct pollfd *fds = p;"
	   "fds[i].fd = fd; fds[i].events = POLLIN;") i (car fdsrl) fds-blob))
      (do ((i nfdsr (fx+ i 1))
	   (fdswl fdswl (cdr fdswl)))
	  ((null? fdswl))
	((foreign-lambda* void ((int i) (int fd) (scheme-pointer p))
	   "struct pollfd *fds = p;"
	   "fds[i].fd = fd; fds[i].events = POLLOUT;") i (car fdswl) fds-blob))
      (let ((n ((foreign-lambda int "poll" scheme-pointer int int)
		fds-blob nfds (if tm (inexact->exact (truncate (* (max 0 tm) 1000))) -1))))
	(cond ((fx< n 0)
	       (posix-error #:file-error 'file-select "failed" fdsr fdsw) )
	      ((fx= n 0) (values (if (pair? fdsr) '() #f) (if (pair? fdsw) '() #f)))
	      (else
	       (let ((rl (let lp ((i 0) (res '()) (fds fdsrl))
			   (cond ((null? fds) (##sys#fast-reverse res))
				 (((foreign-lambda* bool ((int i) (scheme-pointer p))
				     "struct pollfd *fds = p;"
				     "C_return(fds[i].revents & (POLLIN|POLLERR|POLLHUP|POLLNVAL));")
				   i fds-blob)
				  (lp (fx+ i 1) (cons (car fds) res) (cdr fds)))
				 (else (lp (fx+ i 1) res (cdr fds))))))
		     (wl (let lp ((i nfdsr) (res '()) (fds fdswl))
			   (cond ((null? fds) (##sys#fast-reverse res))
				 (((foreign-lambda* bool ((int i) (scheme-pointer p))
				     "struct pollfd *fds = p;"
				     "C_return(fds[i].revents & (POLLOUT|POLLERR|POLLHUP|POLLNVAL));")
				   i fds-blob)
				  (lp (fx+ i 1) (cons (car fds) res) (cdr fds)))
				 (else (lp (fx+ i 1) res (cdr fds)))))))
		 (values
		  (and fdsr (if (fixnum? fdsr) (and (memq fdsr rl) fdsr) rl))
		  (and fdsw (if (fixnum? fdsw) (and (memq fdsw wl) fdsw) wl))))))))))


;;; Pipe primitive:

(define-foreign-variable _pipefd0 int "C_pipefds[ 0 ]")
(define-foreign-variable _pipefd1 int "C_pipefds[ 1 ]")

(set! chicken.process#create-pipe
  (lambda (#!optional mode)
   (when (fx< (##core#inline "C_pipe" #f) 0)
     (posix-error #:file-error 'create-pipe "cannot create pipe") )
   (values _pipefd0 _pipefd1))  )


;;; Signal processing:

(define-foreign-variable _nsig int "NSIG")
(define-foreign-variable _sigterm int "SIGTERM")
(define-foreign-variable _sigkill int "SIGKILL")
(define-foreign-variable _sigint int "SIGINT")
(define-foreign-variable _sighup int "SIGHUP")
(define-foreign-variable _sigfpe int "SIGFPE")
(define-foreign-variable _sigill int "SIGILL")
(define-foreign-variable _sigbus int "SIGBUS")
(define-foreign-variable _sigsegv int "SIGSEGV")
(define-foreign-variable _sigabrt int "SIGABRT")
(define-foreign-variable _sigtrap int "SIGTRAP")
(define-foreign-variable _sigquit int "SIGQUIT")
(define-foreign-variable _sigalrm int "SIGALRM")
(define-foreign-variable _sigpipe int "SIGPIPE")
(define-foreign-variable _sigusr1 int "SIGUSR1")
(define-foreign-variable _sigusr2 int "SIGUSR2")
(define-foreign-variable _sigvtalrm int "SIGVTALRM")
(define-foreign-variable _sigprof int "SIGPROF")
(define-foreign-variable _sigio int "SIGIO")
(define-foreign-variable _sigurg int "SIGURG")
(define-foreign-variable _sigchld int "SIGCHLD")
(define-foreign-variable _sigcont int "SIGCONT")
(define-foreign-variable _sigstop int "SIGSTOP")
(define-foreign-variable _sigtstp int "SIGTSTP")
(define-foreign-variable _sigxcpu int "SIGXCPU")
(define-foreign-variable _sigxfsz int "SIGXFSZ")
(define-foreign-variable _sigwinch int "SIGWINCH")

(set! chicken.process.signal#signal/term _sigterm)
(set! chicken.process.signal#signal/kill _sigkill)
(set! chicken.process.signal#signal/int _sigint)
(set! chicken.process.signal#signal/hup _sighup)
(set! chicken.process.signal#signal/fpe _sigfpe)
(set! chicken.process.signal#signal/ill _sigill)
(set! chicken.process.signal#signal/segv _sigsegv)
(set! chicken.process.signal#signal/abrt _sigabrt)
(set! chicken.process.signal#signal/trap _sigtrap)
(set! chicken.process.signal#signal/quit _sigquit)
(set! chicken.process.signal#signal/alrm _sigalrm)
(set! chicken.process.signal#signal/vtalrm _sigvtalrm)
(set! chicken.process.signal#signal/prof _sigprof)
(set! chicken.process.signal#signal/io _sigio)
(set! chicken.process.signal#signal/urg _sigurg)
(set! chicken.process.signal#signal/chld _sigchld)
(set! chicken.process.signal#signal/cont _sigcont)
(set! chicken.process.signal#signal/stop _sigstop)
(set! chicken.process.signal#signal/tstp _sigtstp)
(set! chicken.process.signal#signal/pipe _sigpipe)
(set! chicken.process.signal#signal/xcpu _sigxcpu)
(set! chicken.process.signal#signal/xfsz _sigxfsz)
(set! chicken.process.signal#signal/usr1 _sigusr1)
(set! chicken.process.signal#signal/usr2 _sigusr2)
(set! chicken.process.signal#signal/winch _sigwinch)
(set! chicken.process.signal#signal/bus _sigbus)
(set! chicken.process.signal#signal/break 0)

(set! chicken.process.signal#signals-list
  (list
   chicken.process.signal#signal/term
   chicken.process.signal#signal/kill
   chicken.process.signal#signal/int
   chicken.process.signal#signal/hup
   chicken.process.signal#signal/fpe
   chicken.process.signal#signal/ill
   chicken.process.signal#signal/segv
   chicken.process.signal#signal/abrt
   chicken.process.signal#signal/trap
   chicken.process.signal#signal/quit
   chicken.process.signal#signal/alrm
   chicken.process.signal#signal/vtalrm
   chicken.process.signal#signal/prof
   chicken.process.signal#signal/io
   chicken.process.signal#signal/urg
   chicken.process.signal#signal/chld
   chicken.process.signal#signal/cont
   chicken.process.signal#signal/stop
   chicken.process.signal#signal/tstp
   chicken.process.signal#signal/pipe
   chicken.process.signal#signal/xcpu
   chicken.process.signal#signal/xfsz
   chicken.process.signal#signal/usr1
   chicken.process.signal#signal/usr2
   chicken.process.signal#signal/winch
   chicken.process.signal#signal/bus))

(set! chicken.process.signal#set-signal-mask!
  (lambda (sigs)
    (##sys#check-list sigs 'set-signal-mask!)
    (##core#inline "C_sigemptyset" 0)
    (for-each
      (lambda (s)
        (##sys#check-fixnum s 'set-signal-mask!)
        (##core#inline "C_sigaddset" s) )
      sigs)
    (when (fx< (##core#inline "C_sigprocmask_set" 0) 0)
      (posix-error #:process-error 'set-signal-mask! "cannot set signal mask") )))

(define chicken.process.signal#signal-mask
  (getter-with-setter
   (lambda ()
     (##core#inline "C_sigprocmask_get" 0)
     (let loop ((sigs chicken.process.signal#signals-list) (mask '()))
       (if (null? sigs)
	   mask
	   (let ([sig (car sigs)])
	     (loop (cdr sigs)
		   (if (##core#inline "C_sigismember" sig) (cons sig mask) mask)) ) ) ) )
   chicken.process.signal#set-signal-mask!
   "(chicken.process.signal#signal-mask)"))

(set! chicken.process.signal#signal-masked?
  (lambda (sig)
    (##sys#check-fixnum sig 'signal-masked?)
    (##core#inline "C_sigprocmask_get" 0)
    (##core#inline "C_sigismember" sig)) )

(set! chicken.process.signal#signal-mask!
  (lambda (sig)
    (##sys#check-fixnum sig 'signal-mask!)
    (##core#inline "C_sigemptyset" 0)
    (##core#inline "C_sigaddset" sig)
    (when (fx< (##core#inline "C_sigprocmask_block" 0) 0)
      (posix-error #:process-error 'signal-mask! "cannot block signal") )))

(set! chicken.process.signal#signal-unmask!
  (lambda (sig)
    (##sys#check-fixnum sig 'signal-unmask!)
    (##core#inline "C_sigemptyset" 0)
    (##core#inline "C_sigaddset" sig)
    (when (fx< (##core#inline "C_sigprocmask_unblock" 0) 0)
      (posix-error #:process-error 'signal-unmask! "cannot unblock signal") )) )


;;; Getting group- and user-information:

(set! chicken.process-context.posix#current-user-id
  (getter-with-setter
   (foreign-lambda int "C_getuid")
   (lambda (id)
     (##sys#check-fixnum id 'current-user-id)
     (when (fx< (##core#inline "C_setuid" id) 0)
       (##sys#error/errno (##sys#update-errno)
                          'current-user-id!-setter "cannot set user ID" id)))
   "(chicken.process-context.posix#current-user-id)"))

(set! chicken.process-context.posix#current-effective-user-id
  (getter-with-setter
   (foreign-lambda int "C_geteuid")
   (lambda (id)
     (##sys#check-fixnum id 'current-effective-user-id)
     (when (fx< (##core#inline "C_seteuid" id) 0)
       (##sys#error/errno (##sys#update-errno)
                          'effective-user-id!-setter
                          "cannot set effective user ID" id)))
   "(chicken.process-context.posix#current-effective-user-id)"))

(set! chicken.process-context.posix#current-group-id
  (getter-with-setter
   (foreign-lambda int "C_getgid")
   (lambda (id)
     (##sys#check-fixnum id 'current-group-id)
     (when (fx< (##core#inline "C_setgid" id) 0)
       (##sys#error/errno (##sys#update-errno)
                          'current-group-id!-setter "cannot set group ID" id)))
   "(chicken.process-context.posix#current-group-id)") )

(set! chicken.process-context.posix#current-effective-group-id
  (getter-with-setter 
   (foreign-lambda int "C_getegid")
   (lambda (id)
     (##sys#check-fixnum id 'current-effective-group-id)
     (when (fx< (##core#inline "C_setegid" id) 0)
       (##sys#error/errno (##sys#update-errno)
                          'effective-group-id!-setter
                          "cannot set effective group ID" id)))
   "(chicken.process-context.posix#current-effective-group-id)") )

(define-foreign-variable _user-name nonnull-c-string "C_user->pw_name")
(define-foreign-variable _user-passwd nonnull-c-string "C_user->pw_passwd")
(define-foreign-variable _user-uid int "C_user->pw_uid")
(define-foreign-variable _user-gid int "C_user->pw_gid")
(define-foreign-variable _user-gecos nonnull-c-string "C_PW_GECOS")
(define-foreign-variable _user-dir c-string "C_user->pw_dir")
(define-foreign-variable _user-shell c-string "C_user->pw_shell")

(set! chicken.process-context.posix#user-information
  (lambda (user #!optional as-vector)
    (let ([r (if (fixnum? user)
		 (##core#inline "C_getpwuid" user)
		 (begin
		   (##sys#check-string user 'user-information)
		   (##core#inline "C_getpwnam" (##sys#make-c-string user 'user-information)) ) ) ] )
      (and r
	   ((if as-vector vector list)
	    _user-name
	    _user-passwd
	    _user-uid
	    _user-gid
	    _user-gecos
	    _user-dir
	    _user-shell) ) )) )

(set! chicken.process-context.posix#current-user-name
  (lambda ()
    (car (chicken.process-context.posix#user-information
	  (chicken.process-context.posix#current-user-id)))) )

(set! chicken.process-context.posix#current-effective-user-name
  (lambda ()
    (car (chicken.process-context.posix#user-information
	  (chicken.process-context.posix#current-effective-user-id)))) )

(define chown
  (lambda (loc f uid gid)
    (##sys#check-fixnum uid loc)
    (##sys#check-fixnum gid loc)
    (let ((r (cond
	      ((port? f)
	       (##core#inline "C_fchown" (chicken.file.posix#port->fileno f) uid gid))
	      ((fixnum? f)
	       (##core#inline "C_fchown" f uid gid))
	      ((string? f)
	       (##core#inline "C_chown"
			      (##sys#make-c-string f loc) uid gid))
	      (else (##sys#signal-hook
		     #:type-error loc
		     "bad argument type - not a fixnum, port or string" f)))))
      (when (fx< r 0)
	(posix-error #:file-error loc "cannot change file owner" f uid gid) )) ) )

(set! chicken.process-context.posix#create-session
  (lambda ()
   (let ([a (##core#inline "C_setsid" #f)])
     (when (fx< a 0)
       (##sys#error/errno (##sys#update-errno)
                          'create-session "cannot create session"))
     a)) )

(set! chicken.process-context.posix#process-group-id
  (getter-with-setter
   (lambda (pid)
     (##sys#check-fixnum pid 'process-group-id)
     (let ([a (##core#inline "C_getpgid" pid)])
       (when (fx< a 0)
         (##sys#error/errno (##sys#update-errno)
                            'process-group-id
                            "cannot retrieve process group ID" pid))
       a))
   (lambda (pid pgid)
     (##sys#check-fixnum pid 'process-group)
     (##sys#check-fixnum pgid 'process-group)
     (when (fx< (##core#inline "C_setpgid" pid pgid) 0)
       (##sys#error/errno (##sys#update-errno)
                          'process-group "cannot set process group ID" pid pgid)))
   "(chicken.process-context.posix#process-group-id pid)"))


;;; Hard and symbolic links:

(set! chicken.file.posix#create-symbolic-link
  (lambda (old new)
    (##sys#check-string old 'create-symbolic-link)
    (##sys#check-string new 'create-symbolic-link)
    (when (fx< (##core#inline
              "C_symlink"
              (##sys#make-c-string old 'create-symbolic-link)
              (##sys#make-c-string new 'create-symbolic-link) )
             0)
      (posix-error #:file-error 'create-symbolic-link "cannot create symbolic link" old new) ) ) )

(define-foreign-variable _filename_max int "FILENAME_MAX")

(define ##sys#read-symbolic-link
  (let ((buf (make-string (fx+ _filename_max 1))))
    (lambda (fname location)
      (let ((len (##core#inline
                  "C_do_readlink"
                  (##sys#make-c-string fname location) buf)))
        (if (fx< len 0)
            (posix-error #:file-error location "cannot read symbolic link" fname)
            (substring buf 0 len))))))

(set! chicken.file.posix#read-symbolic-link
  (lambda (fname #!optional canonicalize)
    (##sys#check-string fname 'read-symbolic-link)
    (if canonicalize
	(receive (base-origin base-directory directory-components) (decompose-directory fname)
	  (let loop ((components directory-components)
		     (result (string-append (or base-origin "") (or base-directory ""))))
	    (if (null? components)
		result
		(let ((pathname (make-pathname result (car components))))
		  (if (##sys#file-exists? pathname #f #f 'read-symbolic-link)
		      (loop (cdr components)
			    (if (chicken.file.posix#symbolic-link? pathname)
				(let ((target (##sys#read-symbolic-link pathname 'read-symbolic-link)))
				  (if (absolute-pathname? target)
				      target
				      (make-pathname result target)))
				pathname))
		      (##sys#signal-hook #:file-error 'read-symbolic-link "could not canonicalize path with symbolic links, component does not exist" pathname))))))
	(##sys#read-symbolic-link fname 'read-symbolic-link))))

(set! chicken.file.posix#file-link
  (let ((link (foreign-lambda int "link" nonnull-c-string nonnull-c-string)))
    (lambda (old new)
      (##sys#check-string old 'file-link)
      (##sys#check-string new 'file-link)
      (when (fx< (link old new) 0)
      (posix-error #:file-error 'hard-link "could not create hard link" old new) ) ) ) )


(define ##sys#custom-input-port
  (lambda (loc nam fd #!optional (nonblocking? #f) (bufi 1) (on-close void) (more? #f))
    (when nonblocking? (##sys#file-nonblocking! fd) )
    (let ([bufsiz (if (fixnum? bufi) bufi (##sys#size bufi))]
	  [buf (if (fixnum? bufi) (##sys#make-string bufi) bufi)]
	  [buflen 0]
	  [bufpos 0] )
      (let ([ready?
	     (lambda ()
	       (let ((res (##sys#file-select-one fd)))
		 (if (fx= -1 res)
		     (if (or (fx= _errno _ewouldblock)
			     (fx= _errno _eagain))
			 #f
			 (posix-error #:file-error loc "cannot select" fd nam))
		     (fx= 1 res))))]
            [peek
	     (lambda ()
	       (if (fx>= bufpos buflen)
		   #!eof
		   (##core#inline "C_subchar" buf bufpos)) )]
            [fetch
	     (lambda ()
	       (let loop ()
		 (let ([cnt (##core#inline "C_read" fd buf bufsiz)])
		   (cond ((fx= cnt -1)
			  (cond
			    ((or (fx= _errno _ewouldblock)
				 (fx= _errno _eagain))
			     (##sys#thread-block-for-i/o! ##sys#current-thread fd #:input)
			     (##sys#thread-yield!)
			     (loop) )
			    ((fx= _errno _eintr)
			     (##sys#dispatch-interrupt loop))
			    (else (posix-error #:file-error loc "cannot read" fd nam) )))
			 [(and more? (fx= cnt 0))
			  ;; When "more" keep trying, otherwise read once more
			  ;; to guard against race conditions
			  (if (more?)
			      (begin
				(##sys#thread-yield!)
				(loop) )
			      (let ([cnt (##core#inline "C_read" fd buf bufsiz)])
				(when (fx= cnt -1)
				  (if (or (fx= _errno _ewouldblock)
					  (fx= _errno _eagain))
				      (set! cnt 0)
				      (posix-error #:file-error loc "cannot read" fd nam) ) )
				(set! buflen cnt)
				(set! bufpos 0) ) )]
			 [else
			  (set! buflen cnt)
			  (set! bufpos 0)]) ) )	 )] )
	(letrec ([this-port
		  (make-input-port
		   (lambda ()		; read-char
		     (when (fx>= bufpos buflen)
		       (fetch))
		     (let ([ch (peek)])
		       (unless (eof-object? ch) (set! bufpos (fx+ bufpos 1)))
		       ch ) )
		   (lambda ()		; char-ready?
		     (or (fx< bufpos buflen)
			 (ready?)) )
		   (lambda ()		; close
		     (when (fx< (##core#inline "C_close" fd) 0)
		       (posix-error #:file-error loc "cannot close" fd nam))
		     (on-close))
		   (lambda ()		; peek-char
		     (when (fx>= bufpos buflen)
		       (fetch))
		     (peek) )
		   (lambda (port n dest start) ; read-string!
		     (let loop ([n (or n (fx- (##sys#size dest) start))] [m 0] [start start])
		       (cond [(eq? 0 n) m]
			     [(fx< bufpos buflen)
			      (let* ([rest (fx- buflen bufpos)]
				     [n2 (if (fx< n rest) n rest)])
				(##core#inline "C_substring_copy" buf dest bufpos (fx+ bufpos n2) start)
				(set! bufpos (fx+ bufpos n2))
				(loop (fx- n n2) (fx+ m n2) (fx+ start n2)) ) ]
			     [else
			      (fetch)
			      (if (eq? 0 buflen) 
				  m
				  (loop n m start) ) ] ) ) )
		   (lambda (p limit)	; read-line
		     (when (fx>= bufpos buflen)
		       (fetch))
		     (if (fx>= bufpos buflen)
			 #!eof
			 (let ((limit (or limit (fx- most-positive-fixnum bufpos))))
			   (receive (next line full-line?)
			       (##sys#scan-buffer-line
				buf
				(fxmin buflen (fx+ bufpos limit))
				bufpos
				(lambda (pos)
				  (let ((nbytes (fx- pos bufpos)))
				    (cond ((fx>= nbytes limit)
					   (values #f pos #f))
					  (else
                                           (set! limit (fx- limit nbytes))
					   (fetch)
					   (if (fx< bufpos buflen)
					       (values buf bufpos
						       (fxmin buflen
                                                              (fx+ bufpos limit)))
					       (values #f bufpos #f)))))))
			     ;; Update row & column position
			     (if full-line?
				 (begin
				   (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
				   (##sys#setislot p 5 0))
				 (##sys#setislot p 5 (fx+ (##sys#slot p 5)
							  (##sys#size line))))
			     (set! bufpos next)
			     line)) ) )
		   (lambda (port)		; read-buffered
		     (if (fx>= bufpos buflen)
			 ""
			 (let ((str (##sys#substring buf bufpos buflen)))
			   (set! bufpos buflen)
			   str)))
		   ) ] )
	  (##sys#setslot this-port 3 nam)
	  this-port ) ) ) ) )

(define ##sys#custom-output-port
  (lambda (loc nam fd #!optional (nonblocking? #f) (bufi 0) (on-close void))
    (when nonblocking? (##sys#file-nonblocking! fd) )
    (letrec ([poke
	      (lambda (str len)
		(let loop ()
		  (let ((cnt (##core#inline "C_write" fd str len)))
		    (cond ((fx= -1 cnt)
			   (cond
			    ((or (fx= _errno _ewouldblock)
				 (fx= _errno _eagain))
			     (##sys#thread-yield!)
			     (poke str len) )
			    ((fx= _errno _eintr)
			     (##sys#dispatch-interrupt loop))
			    (else
			     (posix-error loc #:file-error "cannot write" fd nam) ) ) )
			  ((fx< cnt len)
			   (poke (##sys#substring str cnt len) (fx- len cnt)) ) ) ) ))]
	     [store
	      (let ([bufsiz (if (fixnum? bufi) bufi (##sys#size bufi))])
		(if (fx= 0 bufsiz)
		    (lambda (str)
		      (when str
			(poke str (##sys#size str)) ) )
		    (let ([buf (if (fixnum? bufi) (##sys#make-string bufi) bufi)]
			  [bufpos 0])
		      (lambda (str)
			(if str
			    (let loop ([rem (fx- bufsiz bufpos)] [start 0] [len (##sys#size str)])
			      (cond [(fx= 0 rem)
				     (poke buf bufsiz)
				     (set! bufpos 0)
				     (loop bufsiz 0 len)]
				    [(fx< rem len)
				     (##core#inline "C_substring_copy" str buf start rem bufpos)
				     (loop 0 rem (fx- len rem))]
				    [else
				     (##core#inline "C_substring_copy" str buf start len bufpos)
				     (set! bufpos (fx+ bufpos len))] ) )
			    (when (fx< 0 bufpos)
			      (poke buf bufpos) ) ) ) ) ) )])
      (letrec ([this-port
		(make-output-port
		 (lambda (str)		; write-string
		   (store str) )
		 (lambda ()		; close
		   (when (fx< (##core#inline "C_close" fd) 0)
		     (posix-error #:file-error loc "cannot close" fd nam))
		   (on-close))
		 (lambda ()		; flush
		   (store #f) ) )] )
	(##sys#setslot this-port 3 nam)
	this-port ) ) ) )


;;; Other file operations:

(set! chicken.file.posix#file-truncate
  (lambda (fname off)
    (##sys#check-exact-integer off 'file-truncate)
    (when (fx< (cond ((string? fname) (##core#inline "C_truncate" (##sys#make-c-string fname 'file-truncate) off))
		     ((port? fname) (##core#inline "C_ftruncate" (chicken.file.posix#port->fileno fname) off))
		     ((fixnum? fname) (##core#inline "C_ftruncate" fname off))
		     (else (##sys#error 'file-truncate "invalid file" fname)))
	       0)
      (posix-error #:file-error 'file-truncate "cannot truncate file" fname off) ) ) )


;;; Record locking:

(define-foreign-variable _f_wrlck int "F_WRLCK")
(define-foreign-variable _f_rdlck int "F_RDLCK")
(define-foreign-variable _f_unlck int "F_UNLCK")

(let ()
  (define (setup port args loc)
    (let-optionals* args ([start 0]
                          [len #t] )
      (##sys#check-open-port port loc)
      (##sys#check-exact-integer start loc)
      (if (eq? #t len)
          (set! len 0)
          (##sys#check-exact-integer len loc) )
      (##core#inline "C_flock_setup" (if (= (##sys#slot port 1) 1) _f_rdlck _f_wrlck) start len)
      (##sys#make-structure 'lock port start len) ) )
  (define (err msg lock loc)
    (posix-error #:file-error loc msg (##sys#slot lock 1) (##sys#slot lock 2) (##sys#slot lock 3)) )
  (set! chicken.file.posix#file-lock
    (lambda (port . args)
      (let loop ()
	(let ((lock (setup port args 'file-lock)))
	  (if (fx< (##core#inline "C_flock_lock" port) 0)
	      (cond
		((fx= _errno _eintr) (##sys#dispatch-interrupt loop))
		(else (err "cannot lock file" lock 'file-lock)))
	      lock)))))
  (set! chicken.file.posix#file-lock/blocking
    (lambda (port . args)
      (let loop ()
	(let ((lock (setup port args 'file-lock/blocking)))
	  (if (fx< (##core#inline "C_flock_lockw" port) 0)
	      (cond
		((fx= _errno _eintr) (##sys#dispatch-interrupt loop))
		(else (err "cannot lock file" lock 'file-lock/blocking)))
	      lock)))))
  (set! chicken.file.posix#file-test-lock
    (lambda (port . args)
      (let ([lock (setup port args 'file-test-lock)])
        (cond [(##core#inline "C_flock_test" port) => (lambda (c) (and (not (fx= c 0)) c))]
              [else (err "cannot unlock file" lock 'file-test-lock)] ) ) ) ) )

(set! chicken.file.posix#file-unlock
  (lambda (lock)
    (##sys#check-structure lock 'lock 'file-unlock)
    (##core#inline "C_flock_setup" _f_unlck (##sys#slot lock 2) (##sys#slot lock 3))
    (when (fx< (##core#inline "C_flock_lock" (##sys#slot lock 1)) 0)
      (cond
       ((fx= _errno _eintr)
	(##sys#dispatch-interrupt
	 (lambda () (chicken.file.posix#file-unlock lock))))
       (else (posix-error #:file-error 'file-unlock "cannot unlock file" lock))))))


;;; FIFOs:

(set! chicken.file.posix#create-fifo
  (lambda (fname . mode)
    (##sys#check-string fname 'create-fifo)
    (let ([mode (if (pair? mode) (car mode) (fxior _s_irwxu (fxior _s_irwxg _s_irwxo)))])
      (##sys#check-fixnum mode 'create-fifo)
      (when (fx< (##core#inline "C_mkfifo" (##sys#make-c-string fname 'create-fifo) mode) 0)
      (posix-error #:file-error 'create-fifo "cannot create FIFO" fname mode) ) ) ) )


;;; Time related things:

(set! chicken.time.posix#string->time
  (let ((strptime (foreign-lambda scheme-object "C_strptime" scheme-object scheme-object scheme-object scheme-pointer))
        (tm-size (foreign-value "sizeof(struct tm)" int)))
    (lambda (tim #!optional (fmt "%a %b %e %H:%M:%S %Z %Y"))
      (##sys#check-string tim 'string->time)
      (##sys#check-string fmt 'string->time)
      (strptime (##sys#make-c-string tim 'string->time) (##sys#make-c-string fmt) (make-vector 10 #f) (##sys#make-string tm-size #\nul)) ) ) )

(set! chicken.time.posix#utc-time->seconds
  (let ((tm-size (foreign-value "sizeof(struct tm)" int)))
    (lambda (tm)
      (check-time-vector 'utc-time->seconds tm)
      (let ((t (##core#inline_allocate ("C_a_timegm" 7) tm (##sys#make-string tm-size #\nul))))
        (if (= -1 t)
            (##sys#error 'utc-time->seconds "cannot convert time vector to seconds" tm)
            t)))))

(set! chicken.time.posix#local-timezone-abbreviation
  (foreign-lambda* c-string ()
   "\n#if !defined(__CYGWIN__) && !defined(__SVR4) && !defined(__uClinux__) && !defined(__hpux__) && !defined(_AIX)\n"
   "time_t clock = time(NULL);"
   "struct tm *ltm = C_localtime(&clock);"
   "char *z = ltm ? (char *)ltm->tm_zone : 0;"
   "\n#else\n"
   "char *z = (daylight ? tzname[1] : tzname[0]);"
   "\n#endif\n"
   "C_return(z);") )


;;; Other things:

(set! chicken.process.signal#set-alarm!
  (foreign-lambda int "C_alarm" int))


;;; Process handling:

(set! chicken.process#process-fork
  (let ((fork (foreign-lambda int "C_fork")))
    (lambda (#!optional thunk killothers)
      ;; flush all stdio streams before fork
      ((foreign-lambda int "C_fflush" c-pointer) #f)
      (let ((pid (fork)))
	(when (fx= -1 pid) 
	  (posix-error #:process-error 'process-fork "cannot create child process"))
	(if (and thunk (zero? pid))
	    ((if killothers
		 ##sys#kill-other-threads
		 (lambda (thunk) (thunk)))
	     (lambda ()
	       (##sys#call-with-cthulhu
		(lambda ()
		  (thunk)
		  (exit 0)))))
	    pid)))))

(set! chicken.process#process-execute
  (lambda (filename #!optional (arglist '()) envlist exactf)
    (call-with-exec-args
     'process-execute filename (lambda (x) x) arglist envlist
     (lambda (prg argbuf envbuf)
       (let ((r (if envbuf
		    (##core#inline "C_u_i_execve" prg argbuf envbuf)
		    (##core#inline "C_u_i_execvp" prg argbuf))))
	 (when (fx= r -1)
	   (posix-error #:process-error 'process-execute "cannot execute process" filename)))))))

(define-foreign-variable _wnohang int "WNOHANG")
(define-foreign-variable _wait-status int "C_wait_status")

(define (process-wait-impl pid nohang)
  (let* ((res (##core#inline "C_waitpid" pid (if nohang _wnohang 0)))
	 (norm (##core#inline "C_WIFEXITED" _wait-status)) )
    (if (and (fx= res -1) (fx= _errno _eintr))
	(##sys#dispatch-interrupt
         (lambda () (process-wait-impl pid nohang)))
	(values
	 res
	 norm
	 (cond (norm (##core#inline "C_WEXITSTATUS" _wait-status))
	       ((##core#inline "C_WIFSIGNALED" _wait-status)
		(##core#inline "C_WTERMSIG" _wait-status))
	       (else (##core#inline "C_WSTOPSIG" _wait-status)) ) )) ) )

(set! chicken.process-context.posix#parent-process-id (foreign-lambda int "C_getppid"))

(set! chicken.process#process-signal
  (lambda (id . sig)
    (let ((sig (if (pair? sig) (car sig) _sigterm)))
      (##sys#check-fixnum id 'process-signal)
      (##sys#check-fixnum sig 'process-signal)
      (let ((r (##core#inline "C_kill" id sig)))
      (when (fx= r -1) (posix-error #:process-error 'process-signal "could not send signal to process" id sig) ) ) ) ) )

(define (shell-command loc)
  (or (get-environment-variable "SHELL") "/bin/sh") )

(define (shell-command-arguments cmdlin)
  (list "-c" cmdlin) )

(set! chicken.process#process-run
  (lambda (f . args)
    (let ((args (if (pair? args) (car args) #f))
	  (pid (chicken.process#process-fork)) )
      (cond ((not (eq? 0 pid)) pid)
	    (args (chicken.process#process-execute f args))
	    (else
	     (chicken.process#process-execute
	      (shell-command 'process-run)
	      (shell-command-arguments f)) ) ) ) ) )

;;; Run subprocess connected with pipes:

;; process-impl
; loc            caller procedure symbol
; cmd            pathname or commandline
; args           string-list or '()
; env            string-list or #f
; stdoutf        #f then share, or #t then create
; stdinf         #f then share, or #t then create
; stderrf        #f then share, or #t then create
;
; (values stdin-input-port? stdout-output-port? pid stderr-input-port?)
; where stdin-input-port?, etc. is a port or #f, indicating no port created.

(define-constant DEFAULT-INPUT-BUFFER-SIZE 256)
(define-constant DEFAULT-OUTPUT-BUFFER-SIZE 0)

;FIXME process-execute, process-fork don't show parent caller

(define process-impl
  (let ((replace-fd
	 (lambda (loc fd stdfd)
	   (unless (fx= stdfd fd)
	     (chicken.file.posix#duplicate-fileno fd stdfd)
	     (chicken.file.posix#file-close fd) ) )) )
    (let ((make-on-close
	   (lambda (loc pid clsvec idx idxa idxb)
	     (lambda ()
	       (vector-set! clsvec idx #t)
	       (when (and (vector-ref clsvec idxa) (vector-ref clsvec idxb))
		 (receive (_ flg cod) (process-wait-impl pid #f)
		   (unless flg
		     (##sys#signal-hook #:process-error loc
					"abnormal process exit" pid cod)) ) ) ) ))
	  (needed-pipe
	   (lambda (loc port)
	     (and port
		  (receive (i o) (chicken.process#create-pipe)
		    (cons i o))) ))
        [connect-parent
          (lambda (loc pipe port fd)
            (and port
                 (let ([usefd (car pipe)] [clsfd (cdr pipe)])
                   (chicken.file.posix#file-close clsfd)
                   usefd) ) )]
        [connect-child
          (lambda (loc pipe port stdfd)
            (when port
              (let ([usefd (car pipe)] [clsfd (cdr pipe)])
                (chicken.file.posix#file-close clsfd)
                (replace-fd loc usefd stdfd)) ) )] )
      (let (
          (spawn
	   (let ([swapped-ends
		  (lambda (pipe)
		    (and pipe
			 (cons (cdr pipe) (car pipe)) ) )])
	     (lambda (loc cmd args env stdoutf stdinf stderrf)
	       (let ([ipipe (needed-pipe loc stdinf)]
		     [opipe (needed-pipe loc stdoutf)]
		     [epipe (needed-pipe loc stderrf)])
		 (values
		  ipipe (swapped-ends opipe) epipe
		  (chicken.process#process-fork
		   (lambda ()
		     (connect-child loc opipe stdinf chicken.file.posix#fileno/stdin)
		     (connect-child loc (swapped-ends ipipe) stdoutf chicken.file.posix#fileno/stdout)
		     (connect-child loc (swapped-ends epipe) stderrf chicken.file.posix#fileno/stderr)
		     (chicken.process#process-execute cmd args env)))) ) ) ))
          [input-port
            (lambda (loc pid cmd pipe stdf stdfd on-close)
              (and-let* ([fd (connect-parent loc pipe stdf stdfd)])
                (##sys#custom-input-port loc cmd fd #t DEFAULT-INPUT-BUFFER-SIZE on-close) ) )]
          [output-port
            (lambda (loc pid cmd pipe stdf stdfd on-close)
              (and-let* ([fd (connect-parent loc pipe stdf stdfd)])
                (##sys#custom-output-port loc cmd fd #t DEFAULT-OUTPUT-BUFFER-SIZE on-close) ) )] )
        (lambda (loc cmd args env stdoutf stdinf stderrf)
          (receive [inpipe outpipe errpipe pid]
                     (spawn loc cmd args env stdoutf stdinf stderrf)
            ;When shared assume already "closed", since only created ports
            ;should be explicitly closed, and when one is closed we want
            ;to wait.
            (let ((clsvec (vector (not stdinf) (not stdoutf) (not stderrf))))
              (values
	       (input-port loc pid cmd inpipe stdinf
			   chicken.file.posix#fileno/stdin
			   (make-on-close loc pid clsvec 0 1 2))
	       (output-port loc pid cmd outpipe stdoutf
			    chicken.file.posix#fileno/stdout
			    (make-on-close loc pid clsvec 1 0 2))
	       pid
	       (input-port loc pid cmd errpipe stderrf
			   chicken.file.posix#fileno/stderr
			   (make-on-close loc pid clsvec 2 0 1)) ) ) ) ) ) ) ) )

;;; Run subprocess connected with pipes:

;; TODO: See if this can be moved to posix-common
(let ((%process
        (lambda (loc err? cmd args env k)
          (let ((chkstrlst
		 (lambda (lst)
		   (##sys#check-list lst loc)
		   (for-each (cut ##sys#check-string <> loc) lst) )))
            (##sys#check-string cmd loc)
            (if args
                (chkstrlst args)
                (begin
                  (set! args (shell-command-arguments cmd))
                  (set! cmd (shell-command loc)) ) )
	    (when env (check-environment-list env loc))
	    (##sys#call-with-values
	     (lambda () (process-impl loc cmd args env #t #t err?))
	     k)))))
  (set! chicken.process#process
    (lambda (cmd #!optional args env exactf)
      (%process 
       'process #f cmd args env
       (lambda (i o p e) (values i o p)))))
  (set! chicken.process#process*
    (lambda (cmd #!optional args env exactf)
      (%process
       'process* #t cmd args env
       values))))


;;; chroot:

(set! chicken.process-context.posix#set-root-directory!
  (let ((chroot (foreign-lambda int "chroot" nonnull-c-string)))
    (lambda (dir)
      (##sys#check-string dir 'set-root-directory!)
      (when (fx< (chroot dir) 0)
        (posix-error #:file-error 'set-root-directory! "unable to change root directory" dir) ) ) ) )

;;; unimplemented stuff:

(set!-unimplemented chicken.process#process-spawn)
