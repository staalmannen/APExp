/* Generated from posix.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: posix.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file posixunix.c -feature platform-unix -emit-import-library chicken.errno -emit-import-library chicken.file.posix -emit-import-library chicken.time.posix -emit-import-library chicken.process -emit-import-library chicken.process.signal -emit-import-library chicken.process-context.posix -no-module-registration
   unit: posix
   uses: extras scheduler port pathname lolevel library
*/
#include "chicken.h"


#include <signal.h>

static int C_not_implemented(void);
int C_not_implemented() { return -1; }

static C_TLS struct stat C_statbuf;

#define C_stat_type         (C_statbuf.st_mode & S_IFMT)
#define C_stat_perm         (C_statbuf.st_mode & ~S_IFMT)

#define C_u_i_stat(fn)      C_fix(C_stat(C_c_string(fn), &C_statbuf))
#define C_u_i_fstat(fd)     C_fix(fstat(C_unfix(fd), &C_statbuf))

#ifndef S_IFSOCK
# define S_IFSOCK           0140000
#endif

#ifndef S_IRUSR
# define S_IRUSR  S_IREAD
#endif
#ifndef S_IWUSR
# define S_IWUSR  S_IWRITE
#endif
#ifndef S_IXUSR
# define S_IXUSR  S_IEXEC
#endif

#ifndef S_IRGRP
# define S_IRGRP  S_IREAD
#endif
#ifndef S_IWGRP
# define S_IWGRP  S_IWRITE
#endif
#ifndef S_IXGRP
# define S_IXGRP  S_IEXEC
#endif

#ifndef S_IROTH
# define S_IROTH  S_IREAD
#endif
#ifndef S_IWOTH
# define S_IWOTH  S_IWRITE
#endif
#ifndef S_IXOTH
# define S_IXOTH  S_IEXEC
#endif

#define cpy_tmvec_to_tmstc08(ptm, v) \
    ((ptm)->tm_sec = C_unfix(C_block_item((v), 0)), \
    (ptm)->tm_min = C_unfix(C_block_item((v), 1)), \
    (ptm)->tm_hour = C_unfix(C_block_item((v), 2)), \
    (ptm)->tm_mday = C_unfix(C_block_item((v), 3)), \
    (ptm)->tm_mon = C_unfix(C_block_item((v), 4)), \
    (ptm)->tm_year = C_unfix(C_block_item((v), 5)), \
    (ptm)->tm_wday = C_unfix(C_block_item((v), 6)), \
    (ptm)->tm_yday = C_unfix(C_block_item((v), 7)), \
    (ptm)->tm_isdst = (C_block_item((v), 8) != C_SCHEME_FALSE))

#define cpy_tmvec_to_tmstc9(ptm, v) \
    (((struct tm *)ptm)->tm_gmtoff = -C_unfix(C_block_item((v), 9)))

#define C_tm_set_08(v, tm)  cpy_tmvec_to_tmstc08( (tm), (v) )
#define C_tm_set_9(v, tm)   cpy_tmvec_to_tmstc9( (tm), (v) )

static struct tm *
C_tm_set( C_word v, void *tm )
{
  C_tm_set_08( v, (struct tm *)tm );
#if defined(C_GNU_ENV) && !defined(__CYGWIN__) && !defined(__uClinux__)
  C_tm_set_9( v, (struct tm *)tm );
#endif
  return tm;
}

#define TIME_STRING_MAXLENGTH 255
static char C_time_string [TIME_STRING_MAXLENGTH + 1];
#undef TIME_STRING_MAXLENGTH

#define C_strftime(v, f, tm) \
        (strftime(C_time_string, sizeof(C_time_string), C_c_string(f), C_tm_set((v), (tm))) ? C_time_string : NULL)
#define C_a_mktime(ptr, c, v, tm)  C_int64_to_num(ptr, mktime(C_tm_set((v), C_data_pointer(tm))))
#define C_asctime(v, tm)    (asctime(C_tm_set((v), (tm))))

#define C_fdopen(a, n, fd, m) C_mpointer(a, fdopen(C_unfix(fd), C_c_string(m)))
#define C_dup(x)            C_fix(dup(C_unfix(x)))
#define C_dup2(x, y)        C_fix(dup2(C_unfix(x), C_unfix(y)))

#define C_set_file_ptr(port, ptr)  (C_set_block_item(port, 0, (C_block_item(ptr, 0))), C_SCHEME_UNDEFINED)

/* It is assumed that 'int' is-a 'long' */
#define C_ftell(a, n, p)    C_int64_to_num(a, ftell(C_port_file(p)))
#define C_fseek(p, n, w)    C_mk_nbool(fseek(C_port_file(p), C_num_to_int64(n), C_unfix(w)))
#define C_lseek(fd, o, w)     C_fix(lseek(C_unfix(fd), C_num_to_int64(o), C_unfix(w)))

#ifndef S_IFLNK
#define S_IFLNK S_IFREG
#endif

#ifndef S_IFREG
#define S_IFREG S_IFREG
#endif

#ifndef S_IFDIR
#define S_IFDIR S_IFREG
#endif

#ifndef S_IFCHR
#define S_IFCHR S_IFREG
#endif

#ifndef S_IFBLK
#define S_IFBLK S_IFREG
#endif

#ifndef S_IFSOCK
#define S_IFSOCK S_IFREG
#endif

#ifndef S_IFIFO
#define S_IFIFO S_IFREG
#endif



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



static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_scheduler_toplevel)
C_externimport void C_ccall C_scheduler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lolevel_toplevel)
C_externimport void C_ccall C_lolevel_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[508];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,28),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,115,121,115,116,101,109,32,99,109,100,41,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,115,121,115,116,101,109,42,32,115,116,114,41,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,8),40,103,50,54,48,32,99,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,50,53,52,32,103,50,54,54,41,0,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,113,115,32,115,116,114,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,112,111,115,105,120,45,101,114,114,111,114,32,116,121,112,101,32,108,111,99,32,109,115,103,32,46,32,97,114,103,115,41,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,115,116,97,116,32,102,105,108,101,32,108,105,110,107,32,101,114,114,32,108,111,99,41,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,115,116,97,116,32,102,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,101,116,45,102,105,108,101,45,112,101,114,109,105,115,115,105,111,110,115,33,32,102,32,112,41,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,109,111,100,105,102,105,99,97,116,105,111,110,45,116,105,109,101,32,102,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,97,99,99,101,115,115,45,116,105,109,101,32,102,41,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,99,104,97,110,103,101,45,116,105,109,101,32,102,41,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,101,116,45,102,105,108,101,45,116,105,109,101,115,33,32,102,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,115,105,122,101,32,102,41};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,101,116,45,102,105,108,101,45,111,119,110,101,114,33,32,102,32,117,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,101,116,45,102,105,108,101,45,103,114,111,117,112,33,32,102,32,103,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,116,121,112,101,32,102,105,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,114,101,103,117,108,97,114,45,102,105,108,101,63,32,102,105,108,101,41,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,121,109,98,111,108,105,99,45,108,105,110,107,63,32,102,105,108,101,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,98,108,111,99,107,45,100,101,118,105,99,101,63,32,102,105,108,101,41,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,99,104,97,114,97,99,116,101,114,45,100,101,118,105,99,101,63,32,102,105,108,101,41,0,0,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,102,111,63,32,102,105,108,101,41,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,111,99,107,101,116,63,32,102,105,108,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,100,105,114,101,99,116,111,114,121,63,32,102,105,108,101,41,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,57),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,115,101,116,45,102,105,108,101,45,112,111,115,105,116,105,111,110,33,32,112,111,114,116,32,112,111,115,32,46,32,119,104,101,110,99,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,16),40,109,111,100,101,32,105,110,112,32,109,32,108,111,99,41};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,20),40,99,104,101,99,107,32,108,111,99,32,102,100,32,105,110,112,32,114,41,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,111,112,101,110,45,105,110,112,117,116,45,102,105,108,101,42,32,102,100,32,46,32,109,41,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,111,112,101,110,45,111,117,116,112,117,116,45,102,105,108,101,42,32,102,100,32,46,32,109,41,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,112,111,114,116,45,62,102,105,108,101,110,111,32,112,111,114,116,41,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,100,117,112,108,105,99,97,116,101,45,102,105,108,101,110,111,32,111,108,100,32,46,32,110,101,119,41,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,50),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,112,114,111,99,101,115,115,45,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,104,97,110,103,101,45,100,105,114,101,99,116,111,114,121,42,32,102,100,41,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,33),40,35,35,115,121,115,35,99,104,97,110,103,101,45,100,105,114,101,99,116,111,114,121,45,104,111,111,107,32,100,105,114,41,0,0,0,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,16),67,95,100,101,99,111,100,101,95,115,101,99,111,110,100,115};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,104,101,99,107,45,116,105,109,101,45,118,101,99,116,111,114,32,108,111,99,32,116,109,41};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,115,101,99,111,110,100,115,45,62,108,111,99,97,108,45,116,105,109,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,115,101,99,111,110,100,115,45,62,117,116,99,45,116,105,109,101,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,115,101,99,111,110,100,115,45,62,115,116,114,105,110,103,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,108,111,99,97,108,45,116,105,109,101,45,62,115,101,99,111,110,100,115,32,116,109,41,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,116,105,109,101,45,62,115,116,114,105,110,103,32,116,109,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,53),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,101,116,45,115,105,103,110,97,108,45,104,97,110,100,108,101,114,33,32,115,105,103,32,112,114,111,99,41,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,11),40,97,51,57,52,52,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,10),40,103,57,55,57,32,115,105,103,41,0,0,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,15),40,102,95,51,57,53,51,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,57,55,56,32,103,57,56,53,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,109,97,107,101,45,115,105,103,110,97,108,45,104,97,110,100,108,101,114,32,46,32,115,105,103,115,41,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,105,103,110,111,114,101,32,115,105,103,41,0,0,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,100,101,102,97,117,108,116,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,108,101,101,112,32,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,7),40,97,52,48,52,52,41,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,24),40,97,52,48,53,48,32,101,112,105,100,32,101,110,111,114,109,32,101,99,111,100,101,41};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,119,97,105,116,32,46,32,97,114,103,115,41,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,7),40,97,52,49,49,57,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,11),40,97,52,49,49,51,32,101,120,110,41,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,17),40,100,111,108,111,111,112,49,48,53,53,32,115,108,32,105,41,0,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,10),40,116,109,112,49,50,53,57,48,41,0,0,0,0,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,7),40,97,52,49,57,51,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,15),40,116,109,112,50,50,53,57,49,32,97,114,103,115,41,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,7),40,97,52,49,50,56,41,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,9),40,97,52,49,48,55,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,61),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,108,105,115,116,45,62,99,45,115,116,114,105,110,103,45,98,117,102,102,101,114,32,115,116,114,105,110,103,45,108,105,115,116,32,99,111,110,118,101,114,116,32,108,111,99,41,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,14),40,100,111,108,111,111,112,49,48,55,52,32,105,41,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,102,114,101,101,45,99,45,115,116,114,105,110,103,45,98,117,102,102,101,114,32,98,117,102,102,101,114,45,97,114,114,97,121,41,0,0,0,0,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,7),40,103,49,48,56,55,41,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,48,56,54,41,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,104,101,99,107,45,101,110,118,105,114,111,110,109,101,110,116,45,108,105,115,116,32,108,115,116,32,108,111,99,41,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,7),40,110,111,112,32,120,41,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,7),40,97,52,51,49,56,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,11),40,97,52,51,49,50,32,101,120,110,41,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,49,50,56,32,103,49,49,52,48,41,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,7),40,97,52,51,51,57,41,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,7),40,97,52,52,50,48,41,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,14),40,97,52,52,49,52,32,46,32,97,114,103,115,41,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,7),40,97,52,51,51,51,41,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,9),40,97,52,51,48,54,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,77),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,97,108,108,45,119,105,116,104,45,101,120,101,99,45,97,114,103,115,32,108,111,99,32,102,105,108,101,110,97,109,101,32,97,114,103,99,111,110,118,32,97,114,103,108,105,115,116,32,101,110,118,108,105,115,116,32,112,114,111,99,41,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,21),40,99,104,101,99,107,32,108,111,99,32,99,109,100,32,105,110,112,32,114,41,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,111,112,101,110,45,105,110,112,117,116,45,112,105,112,101,32,99,109,100,32,46,32,109,41,0,0,0,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,111,112,101,110,45,111,117,116,112,117,116,45,112,105,112,101,32,99,109,100,32,46,32,109,41,0,0,0,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,108,111,115,101,45,105,110,112,117,116,45,112,105,112,101,32,112,111,114,116,41,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,108,111,115,101,45,111,117,116,112,117,116,45,112,105,112,101,32,112,111,114,116,41};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,7),40,97,52,53,56,51,41,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,17),40,97,52,53,57,52,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,7),40,97,52,53,56,56,41,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,7),40,97,52,54,48,51,41,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,119,105,116,104,45,105,110,112,117,116,45,102,114,111,109,45,112,105,112,101,32,99,109,100,32,116,104,117,110,107,32,46,32,109,111,100,101,41,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,7),40,97,52,54,49,55,41,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,17),40,97,52,54,50,51,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,97,108,108,45,119,105,116,104,45,111,117,116,112,117,116,45,112,105,112,101,32,99,109,100,32,112,114,111,99,32,46,32,109,111,100,101,41,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,7),40,97,52,54,52,49,41,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,17),40,97,52,54,52,55,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,97,108,108,45,119,105,116,104,45,105,110,112,117,116,45,112,105,112,101,32,99,109,100,32,112,114,111,99,32,46,32,109,111,100,101,41,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,7),40,97,52,54,54,53,41,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,17),40,97,52,54,55,54,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,7),40,97,52,54,55,48,41,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,7),40,97,52,54,56,53,41,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,119,105,116,104,45,111,117,116,112,117,116,45,116,111,45,112,105,112,101,32,99,109,100,32,116,104,117,110,107,32,46,32,109,111,100,101,41,0,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,102,105,108,101,45,110,111,110,98,108,111,99,107,105,110,103,33,32,102,100,49,51,51,48,41};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,102,105,108,101,45,115,101,108,101,99,116,45,111,110,101,32,105,110,116,49,51,51,53,41,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,99,111,110,116,114,111,108,32,102,100,32,99,109,100,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,111,112,101,110,32,102,105,108,101,110,97,109,101,32,102,108,97,103,115,32,46,32,109,111,100,101,41,0,0,0,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,99,108,111,115,101,32,102,100,41,0,0,0,0,0,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,114,101,97,100,32,102,100,32,115,105,122,101,32,46,32,98,117,102,102,101,114,41,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,119,114,105,116,101,32,102,100,32,98,117,102,102,101,114,32,46,32,115,105,122,101,41};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,109,107,115,116,101,109,112,32,116,101,109,112,108,97,116,101,41,0,0,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,18),40,100,111,108,111,111,112,49,52,50,57,32,102,100,115,114,108,41,0,0,0,0,0,0};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,18),40,100,111,108,111,111,112,49,52,51,48,32,102,100,115,119,108,41,0,0,0,0,0,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,14),40,108,112,32,105,32,114,101,115,32,102,100,115,41,0,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,14),40,108,112,32,105,32,114,101,115,32,102,100,115,41,0,0};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,115,101,108,101,99,116,32,102,100,115,114,32,102,100,115,119,32,46,32,116,105,109,101,111,117,116,41,0,0,0,0};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,114,101,97,116,101,45,112,105,112,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,53,52,50,32,103,49,53,52,57,41,0,0,0,0,0,0,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,101,116,45,115,105,103,110,97,108,45,109,97,115,107,33,32,115,105,103,115,41,0,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,109,97,115,107,101,100,63,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,109,97,115,107,33,32,115,105,103,41,0,0,0,0,0,0,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,117,110,109,97,115,107,33,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,60),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,117,115,101,114,45,105,110,102,111,114,109,97,116,105,111,110,32,117,115,101,114,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,117,115,101,114,45,110,97,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,59),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,101,102,102,101,99,116,105,118,101,45,117,115,101,114,45,110,97,109,101,41,0,0,0,0,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,104,111,119,110,32,108,111,99,32,102,32,117,105,100,32,103,105,100,41,0,0,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,114,101,97,116,101,45,115,101,115,115,105,111,110,41,0,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,99,114,101,97,116,101,45,115,121,109,98,111,108,105,99,45,108,105,110,107,32,111,108,100,32,110,101,119,41,0,0,0,0,0,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,41),40,35,35,115,121,115,35,114,101,97,100,45,115,121,109,98,111,108,105,99,45,108,105,110,107,32,102,110,97,109,101,32,108,111,99,97,116,105,111,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,7),40,97,53,54,57,53,41,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,24),40,108,111,111,112,32,99,111,109,112,111,110,101,110,116,115,32,114,101,115,117,108,116,41};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,55),40,97,53,55,48,49,32,98,97,115,101,45,111,114,105,103,105,110,32,98,97,115,101,45,100,105,114,101,99,116,111,114,121,32,100,105,114,101,99,116,111,114,121,45,99,111,109,112,111,110,101,110,116,115,41,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,114,101,97,100,45,115,121,109,98,111,108,105,99,45,108,105,110,107,32,102,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,105,110,107,32,111,108,100,32,110,101,119,41,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,8),40,114,101,97,100,121,63,41};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,7),40,102,101,116,99,104,41,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,7),40,97,53,57,57,49,41,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,7),40,97,54,48,49,54,41,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,7),40,97,54,48,50,56,41,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,7),40,97,54,48,52,52,41,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,110,32,109,32,115,116,97,114,116,41};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,25),40,97,54,48,53,57,32,112,111,114,116,32,110,32,100,101,115,116,32,115,116,97,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,11),40,97,54,49,54,51,32,112,111,115,41,0,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,7),40,97,54,49,53,51,41,0};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,28),40,97,54,50,48,57,32,110,101,120,116,32,108,105,110,101,32,102,117,108,108,45,108,105,110,101,63,41,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,15),40,97,54,49,51,53,32,112,32,108,105,109,105,116,41,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,12),40,97,54,50,53,52,32,112,111,114,116,41,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,43),40,35,35,115,121,115,35,99,117,115,116,111,109,45,105,110,112,117,116,45,112,111,114,116,32,108,111,99,32,110,97,109,32,102,100,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,18),40,112,111,107,101,49,56,50,48,32,115,116,114,32,108,101,110,41,0,0,0,0,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,11),40,97,54,52,51,48,32,115,116,114,41,0,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,7),40,97,54,52,51,54,41,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,7),40,97,54,52,53,50,41,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,12),40,102,95,54,52,54,49,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,20),40,108,111,111,112,32,114,101,109,32,115,116,97,114,116,32,108,101,110,41,0,0,0,0};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,12),40,102,95,54,52,55,54,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,44),40,35,35,115,121,115,35,99,117,115,116,111,109,45,111,117,116,112,117,116,45,112,111,114,116,32,108,111,99,32,110,97,109,32,102,100,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,116,114,117,110,99,97,116,101,32,102,110,97,109,101,32,111,102,102,41,0,0,0,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,21),40,115,101,116,117,112,32,112,111,114,116,32,97,114,103,115,32,108,111,99,41,0,0,0};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,111,99,107,32,112,111,114,116,32,46,32,97,114,103,115,41,0,0,0,0,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,111,99,107,47,98,108,111,99,107,105,110,103,32,112,111,114,116,32,46,32,97,114,103,115,41,0,0,0,0,0};
static C_char C_TLS li160[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,116,101,115,116,45,108,111,99,107,32,112,111,114,116,32,46,32,97,114,103,115,41,0};
static C_char C_TLS li161[] C_aligned={C_lihdr(0,0,7),40,97,54,56,51,52,41,0};
static C_char C_TLS li162[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,117,110,108,111,99,107,32,108,111,99,107,41,0,0,0};
static C_char C_TLS li163[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,99,114,101,97,116,101,45,102,105,102,111,32,102,110,97,109,101,32,46,32,109,111,100,101,41,0,0,0};
static C_char C_TLS li164[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,115,116,114,105,110,103,45,62,116,105,109,101,32,116,105,109,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li165[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,117,116,99,45,116,105,109,101,45,62,115,101,99,111,110,100,115,32,116,109,41,0,0,0,0,0,0,0};
static C_char C_TLS li166[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,108,111,99,97,108,45,116,105,109,101,122,111,110,101,45,97,98,98,114,101,118,105,97,116,105,111,110,41};
static C_char C_TLS li167[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,101,116,45,97,108,97,114,109,33,32,105,110,116,49,57,56,51,41,0,0,0,0,0};
static C_char C_TLS li168[] C_aligned={C_lihdr(0,0,14),40,102,95,55,48,50,54,32,116,104,117,110,107,41,0,0};
static C_char C_TLS li169[] C_aligned={C_lihdr(0,0,7),40,97,55,48,49,55,41,0};
static C_char C_TLS li170[] C_aligned={C_lihdr(0,0,7),40,97,55,48,49,49,41,0};
static C_char C_TLS li171[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,102,111,114,107,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li172[] C_aligned={C_lihdr(0,0,9),40,97,55,48,56,57,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li173[] C_aligned={C_lihdr(0,0,25),40,97,55,48,57,50,32,112,114,103,32,97,114,103,98,117,102,32,101,110,118,98,117,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li174[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,101,120,101,99,117,116,101,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li175[] C_aligned={C_lihdr(0,0,7),40,97,55,49,53,57,41,0};
static C_char C_TLS li176[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,112,114,111,99,101,115,115,45,119,97,105,116,45,105,109,112,108,32,112,105,100,32,110,111,104,97,110,103,41,0,0,0,0};
static C_char C_TLS li177[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,112,97,114,101,110,116,45,112,114,111,99,101,115,115,45,105,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li178[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,105,103,110,97,108,32,105,100,32,46,32,115,105,103,41,0,0,0,0,0,0,0};
static C_char C_TLS li179[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,114,117,110,32,102,32,46,32,97,114,103,115,41,0,0};
static C_char C_TLS li180[] C_aligned={C_lihdr(0,0,7),40,97,55,50,57,53,41,0};
static C_char C_TLS li181[] C_aligned={C_lihdr(0,0,17),40,97,55,51,48,49,32,95,32,102,108,103,32,99,111,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li182[] C_aligned={C_lihdr(0,0,8),40,102,95,55,50,56,49,41};
static C_char C_TLS li183[] C_aligned={C_lihdr(0,0,44),40,109,97,107,101,45,111,110,45,99,108,111,115,101,32,108,111,99,32,112,105,100,32,99,108,115,118,101,99,32,105,100,120,32,105,100,120,97,32,105,100,120,98,41,0,0,0,0};
static C_char C_TLS li184[] C_aligned={C_lihdr(0,0,7),40,97,55,51,50,52,41,0};
static C_char C_TLS li185[] C_aligned={C_lihdr(0,0,11),40,97,55,51,51,48,32,105,32,111,41,0,0,0,0,0};
static C_char C_TLS li186[] C_aligned={C_lihdr(0,0,18),40,110,101,101,100,101,100,45,112,105,112,101,32,112,111,114,116,41,0,0,0,0,0,0};
static C_char C_TLS li187[] C_aligned={C_lihdr(0,0,26),40,99,111,110,110,101,99,116,45,112,97,114,101,110,116,32,112,105,112,101,32,112,111,114,116,41,0,0,0,0,0,0};
static C_char C_TLS li188[] C_aligned={C_lihdr(0,0,31),40,99,111,110,110,101,99,116,45,99,104,105,108,100,32,112,105,112,101,32,112,111,114,116,32,115,116,100,102,100,41,0};
static C_char C_TLS li189[] C_aligned={C_lihdr(0,0,7),40,97,55,51,57,57,41,0};
static C_char C_TLS li190[] C_aligned={C_lihdr(0,0,43),40,115,112,97,119,110,32,99,109,100,32,97,114,103,115,32,101,110,118,32,115,116,100,111,117,116,102,32,115,116,100,105,110,102,32,115,116,100,101,114,114,102,41,0,0,0,0,0};
static C_char C_TLS li191[] C_aligned={C_lihdr(0,0,39),40,105,110,112,117,116,45,112,111,114,116,32,108,111,99,32,99,109,100,32,112,105,112,101,32,115,116,100,102,32,111,110,45,99,108,111,115,101,41,0};
static C_char C_TLS li192[] C_aligned={C_lihdr(0,0,40),40,111,117,116,112,117,116,45,112,111,114,116,32,108,111,99,32,99,109,100,32,112,105,112,101,32,115,116,100,102,32,111,110,45,99,108,111,115,101,41};
static C_char C_TLS li193[] C_aligned={C_lihdr(0,0,7),40,97,55,52,52,57,41,0};
static C_char C_TLS li194[] C_aligned={C_lihdr(0,0,34),40,97,55,52,53,53,32,105,110,112,105,112,101,32,111,117,116,112,105,112,101,32,101,114,114,112,105,112,101,32,112,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li195[] C_aligned={C_lihdr(0,0,68),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,112,114,111,99,101,115,115,45,105,109,112,108,32,108,111,99,32,99,109,100,32,97,114,103,115,32,101,110,118,32,115,116,100,111,117,116,102,32,115,116,100,105,110,102,32,115,116,100,101,114,114,102,41,0,0,0,0};
static C_char C_TLS li196[] C_aligned={C_lihdr(0,0,7),40,103,50,49,55,57,41,0};
static C_char C_TLS li197[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,49,55,56,41,0,0,0,0,0};
static C_char C_TLS li198[] C_aligned={C_lihdr(0,0,15),40,99,104,107,115,116,114,108,115,116,32,108,115,116,41,0};
static C_char C_TLS li199[] C_aligned={C_lihdr(0,0,7),40,97,55,53,53,48,41,0};
static C_char C_TLS li200[] C_aligned={C_lihdr(0,0,34),40,37,112,114,111,99,101,115,115,32,108,111,99,32,101,114,114,63,32,99,109,100,32,97,114,103,115,32,101,110,118,32,107,41,0,0,0,0,0,0};
static C_char C_TLS li201[] C_aligned={C_lihdr(0,0,15),40,97,55,53,57,52,32,105,32,111,32,112,32,101,41,0};
static C_char C_TLS li202[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,32,99,109,100,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li203[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,42,32,99,109,100,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li204[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,115,101,116,45,114,111,111,116,45,100,105,114,101,99,116,111,114,121,33,32,100,105,114,41,0};
static C_char C_TLS li205[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,112,97,119,110,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li206[] C_aligned={C_lihdr(0,0,21),40,99,104,105,99,107,101,110,46,101,114,114,110,111,35,101,114,114,110,111,41,0,0,0};
static C_char C_TLS li207[] C_aligned={C_lihdr(0,0,11),40,97,55,55,56,48,32,112,105,100,41,0,0,0,0,0};
static C_char C_TLS li208[] C_aligned={C_lihdr(0,0,16),40,97,55,55,57,57,32,112,105,100,32,112,103,105,100,41};
static C_char C_TLS li209[] C_aligned={C_lihdr(0,0,7),40,97,55,56,50,50,41,0};
static C_char C_TLS li210[] C_aligned={C_lihdr(0,0,10),40,97,55,56,50,53,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li211[] C_aligned={C_lihdr(0,0,7),40,97,55,56,52,53,41,0};
static C_char C_TLS li212[] C_aligned={C_lihdr(0,0,10),40,97,55,56,52,56,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li213[] C_aligned={C_lihdr(0,0,7),40,97,55,56,54,56,41,0};
static C_char C_TLS li214[] C_aligned={C_lihdr(0,0,10),40,97,55,56,55,49,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li215[] C_aligned={C_lihdr(0,0,7),40,97,55,56,57,49,41,0};
static C_char C_TLS li216[] C_aligned={C_lihdr(0,0,10),40,97,55,56,57,52,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li217[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,115,105,103,115,32,109,97,115,107,41};
static C_char C_TLS li218[] C_aligned={C_lihdr(0,0,7),40,97,55,57,49,52,41,0};
static C_char C_TLS li219[] C_aligned={C_lihdr(0,0,8),40,118,97,56,56,55,49,41};
static C_char C_TLS li220[] C_aligned={C_lihdr(0,0,8),40,118,97,56,56,55,51,41};
static C_char C_TLS li221[] C_aligned={C_lihdr(0,0,8),40,118,97,56,56,55,53,41};
static C_char C_TLS li222[] C_aligned={C_lihdr(0,0,8),40,118,97,56,56,55,55,41};
static C_char C_TLS li223[] C_aligned={C_lihdr(0,0,11),40,97,55,57,52,52,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li224[] C_aligned={C_lihdr(0,0,14),40,97,55,57,53,51,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li225[] C_aligned={C_lihdr(0,0,10),40,97,55,57,55,56,32,117,109,41,0,0,0,0,0,0};
static C_char C_TLS li226[] C_aligned={C_lihdr(0,0,12),40,97,55,57,56,52,32,112,111,114,116,41,0,0,0,0};
static C_char C_TLS li227[] C_aligned={C_lihdr(0,0,9),40,97,56,48,50,49,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li228[] C_aligned={C_lihdr(0,0,9),40,97,56,48,50,55,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li229[] C_aligned={C_lihdr(0,0,9),40,97,56,48,51,51,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li230[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from k7700 in chicken.process-context.posix#set-root-directory! in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
C_regparm static C_word C_fcall stub2249(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_c_string(C_a0);
C_r=C_fix((C_word)chroot(t0));
return C_r;}

/* from chicken.process-context.posix#parent-process-id in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
C_regparm static C_word C_fcall stub2054(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getppid());
return C_r;}

/* from k6984 */
C_regparm static C_word C_fcall stub2008(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_c_pointer_or_null(C_a0);
C_r=C_fix((C_word)C_fflush(t0));
return C_r;}

/* from fork */
C_regparm static C_word C_fcall stub1988(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_fork());
return C_r;}

/* from k6961 */
C_regparm static C_word C_fcall stub1984(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_alarm(t0));
return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1980(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;

#if !defined(__CYGWIN__) && !defined(__SVR4) && !defined(__uClinux__) && !defined(__hpux__) && !defined(_AIX)

time_t clock = time(NULL);
struct tm *ltm = C_localtime(&clock);
char *z = ltm ? (char *)ltm->tm_zone : 0;

#else

char *z = (daylight ? tzname[1] : tzname[0]);

#endif

C_return(z);
C_ret:
#undef return

return C_r;}

/* from k6889 */
C_regparm static C_word C_fcall stub1953(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word t0=(C_word )(C_a0);
C_word t1=(C_word )(C_a1);
C_word t2=(C_word )(C_a2);
void * t3=(void * )C_data_pointer_or_null(C_a3);
C_r=((C_word)C_strptime(t0,t1,t2,t3));
return C_r;}

/* from k5785 in k5781 in chicken.file.posix#file-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
C_regparm static C_word C_fcall stub1673(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_c_string(C_a0);
char * t1=(char * )C_c_string(C_a1);
C_r=C_fix((C_word)link(t0,t1));
return C_r;}

/* from a7822 in k5475 in k5471 in k5467 in k5425 */
C_regparm static C_word C_fcall stub1592(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getegid());
return C_r;}

/* from a7845 in k5471 in k5467 in k5425 */
C_regparm static C_word C_fcall stub1588(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getgid());
return C_r;}

/* from a7868 in k5467 in k5425 */
C_regparm static C_word C_fcall stub1584(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_geteuid());
return C_r;}

/* from a7891 in k5425 */
C_regparm static C_word C_fcall stub1580(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getuid());
return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1515(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int i=(int )C_unfix(C_a0);
void * p=(void * )C_data_pointer_or_null(C_a1);
struct pollfd *fds = p;
C_return(fds[i].revents & (POLLOUT|POLLERR|POLLHUP|POLLNVAL));
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1496(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int i=(int )C_unfix(C_a0);
void * p=(void * )C_data_pointer_or_null(C_a1);
struct pollfd *fds = p;
C_return(fds[i].revents & (POLLIN|POLLERR|POLLHUP|POLLNVAL));
C_ret:
#undef return

return C_r;}

/* from k4979 */
C_regparm static C_word C_fcall stub1471(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_data_pointer_or_null(C_a0);
int t1=(int )C_unfix(C_a1);
int t2=(int )C_unfix(C_a2);
C_r=C_fix((C_word)poll(t0,t1,t2));
return C_r;}

#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1456(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int i=(int )C_unfix(C_a0);
int fd=(int )C_unfix(C_a1);
void * p=(void * )C_data_pointer_or_null(C_a2);
struct pollfd *fds = p;
fds[i].fd = fd; fds[i].events = POLLOUT;
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1439(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int i=(int )C_unfix(C_a0);
int fd=(int )C_unfix(C_a1);
void * p=(void * )C_data_pointer_or_null(C_a2);
struct pollfd *fds = p;
fds[i].fd = fd; fds[i].events = POLLIN;
C_ret:
#undef return

return C_r;}

/* from k4734 */
C_regparm static C_word C_fcall stub1343(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int t1=(int )C_unfix(C_a1);
long t2=(long )C_num_to_long(C_a2);
C_r=C_fix((C_word)fcntl(t0,t1,t2));
return C_r;}

/* from k4701 */
C_regparm static C_word C_fcall stub1336(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_check_fd_ready(t0));
return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1331(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int fd=(int )C_unfix(C_a0);
int val = fcntl(fd, F_GETFL, 0);
if(val == -1) C_return(0);
C_return(fcntl(fd, F_SETFL, val | O_NONBLOCK) != -1);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1038(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word o=(C_word )(C_a0);
char *ptr = C_malloc(C_header_size(o)); 

if (ptr != NULL) {

  C_memcpy(ptr, C_data_pointer(o), C_header_size(o)); 

}

C_return(ptr);
C_ret:
#undef return

return C_r;}

/* from k3846 */
C_regparm static C_word C_fcall stub941(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word t0=(C_word )(C_a0);
C_word t1=(C_word )(C_a1);
void * t2=(void * )C_data_pointer_or_null(C_a2);
C_r=C_mpointer(&C_a,(void*)C_strftime(t0,t1,t2));
return C_r;}

/* from k3833 */
C_regparm static C_word C_fcall stub931(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word t0=(C_word )(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
C_r=C_mpointer(&C_a,(void*)C_asctime(t0,t1));
return C_r;}

/* from k3765 */
C_regparm static C_word C_fcall stub904(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_num_to_int(C_a0);
C_r=C_mpointer(&C_a,(void*)C_ctime(t0));
return C_r;}

/* from chicken.process-context.posix#current-process-id in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
C_regparm static C_word C_fcall stub848(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getpid());
return C_r;}

/* from k3176 in k3170 in k3167 in k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
C_regparm static C_word C_fcall stub729(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_string_or_null(C_a0);
C_word t1=(C_word )(C_a1);
C_word t2=(C_word )(C_a2);
C_r=C_fix((C_word)set_file_mtime(t0,t1,t2));
return C_r;}

/* from k3006 */
C_regparm static C_word C_fcall stub655(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)strerror(t0));
return C_r;}

C_noret_decl(f8882)
static void C_ccall f8882(C_word c,C_word *av) C_noret;
C_noret_decl(f8886)
static void C_ccall f8886(C_word c,C_word *av) C_noret;
C_noret_decl(f8930)
static void C_ccall f8930(C_word c,C_word *av) C_noret;
C_noret_decl(f8936)
static void C_ccall f8936(C_word c,C_word *av) C_noret;
C_noret_decl(f_2683)
static void C_ccall f_2683(C_word c,C_word *av) C_noret;
C_noret_decl(f_2686)
static void C_ccall f_2686(C_word c,C_word *av) C_noret;
C_noret_decl(f_2689)
static void C_ccall f_2689(C_word c,C_word *av) C_noret;
C_noret_decl(f_2692)
static void C_ccall f_2692(C_word c,C_word *av) C_noret;
C_noret_decl(f_2695)
static void C_ccall f_2695(C_word c,C_word *av) C_noret;
C_noret_decl(f_2698)
static void C_ccall f_2698(C_word c,C_word *av) C_noret;
C_noret_decl(f_2784)
static void C_ccall f_2784(C_word c,C_word *av) C_noret;
C_noret_decl(f_2801)
static void C_ccall f_2801(C_word c,C_word *av) C_noret;
C_noret_decl(f_2803)
static void C_ccall f_2803(C_word c,C_word *av) C_noret;
C_noret_decl(f_2807)
static void C_ccall f_2807(C_word c,C_word *av) C_noret;
C_noret_decl(f_2819)
static void C_ccall f_2819(C_word c,C_word *av) C_noret;
C_noret_decl(f_2823)
static void C_ccall f_2823(C_word c,C_word *av) C_noret;
C_noret_decl(f_2833)
static void C_fcall f_2833(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2854)
static void C_ccall f_2854(C_word c,C_word *av) C_noret;
C_noret_decl(f_2857)
static void C_ccall f_2857(C_word c,C_word *av) C_noret;
C_noret_decl(f_2868)
static void C_ccall f_2868(C_word c,C_word *av) C_noret;
C_noret_decl(f_2874)
static void C_fcall f_2874(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2899)
static void C_ccall f_2899(C_word c,C_word *av) C_noret;
C_noret_decl(f_3009)
static void C_ccall f_3009(C_word c,C_word *av) C_noret;
C_noret_decl(f_3013)
static void C_ccall f_3013(C_word c,C_word *av) C_noret;
C_noret_decl(f_3020)
static void C_ccall f_3020(C_word c,C_word *av) C_noret;
C_noret_decl(f_3024)
static void C_ccall f_3024(C_word c,C_word *av) C_noret;
C_noret_decl(f_3027)
static void C_fcall f_3027(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3031)
static void C_ccall f_3031(C_word c,C_word *av) C_noret;
C_noret_decl(f_3052)
static void C_ccall f_3052(C_word c,C_word *av) C_noret;
C_noret_decl(f_3056)
static void C_ccall f_3056(C_word c,C_word *av) C_noret;
C_noret_decl(f_3065)
static void C_ccall f_3065(C_word c,C_word *av) C_noret;
C_noret_decl(f_3073)
static void C_ccall f_3073(C_word c,C_word *av) C_noret;
C_noret_decl(f_3080)
static void C_ccall f_3080(C_word c,C_word *av) C_noret;
C_noret_decl(f_3091)
static void C_ccall f_3091(C_word c,C_word *av) C_noret;
C_noret_decl(f_3095)
static void C_ccall f_3095(C_word c,C_word *av) C_noret;
C_noret_decl(f_3098)
static void C_ccall f_3098(C_word c,C_word *av) C_noret;
C_noret_decl(f_3116)
static void C_ccall f_3116(C_word c,C_word *av) C_noret;
C_noret_decl(f_3120)
static void C_ccall f_3120(C_word c,C_word *av) C_noret;
C_noret_decl(f_3130)
static void C_ccall f_3130(C_word c,C_word *av) C_noret;
C_noret_decl(f_3135)
static void C_ccall f_3135(C_word c,C_word *av) C_noret;
C_noret_decl(f_3139)
static void C_ccall f_3139(C_word c,C_word *av) C_noret;
C_noret_decl(f_3141)
static void C_ccall f_3141(C_word c,C_word *av) C_noret;
C_noret_decl(f_3145)
static void C_ccall f_3145(C_word c,C_word *av) C_noret;
C_noret_decl(f_3147)
static void C_ccall f_3147(C_word c,C_word *av) C_noret;
C_noret_decl(f_3151)
static void C_ccall f_3151(C_word c,C_word *av) C_noret;
C_noret_decl(f_3153)
static void C_ccall f_3153(C_word c,C_word *av) C_noret;
C_noret_decl(f_3157)
static void C_ccall f_3157(C_word c,C_word *av) C_noret;
C_noret_decl(f_3169)
static void C_ccall f_3169(C_word c,C_word *av) C_noret;
C_noret_decl(f_3172)
static void C_ccall f_3172(C_word c,C_word *av) C_noret;
C_noret_decl(f_3178)
static void C_ccall f_3178(C_word c,C_word *av) C_noret;
C_noret_decl(f_3188)
static void C_fcall f_3188(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3232)
static void C_ccall f_3232(C_word c,C_word *av) C_noret;
C_noret_decl(f_3236)
static void C_ccall f_3236(C_word c,C_word *av) C_noret;
C_noret_decl(f_3238)
static void C_ccall f_3238(C_word c,C_word *av) C_noret;
C_noret_decl(f_3244)
static void C_ccall f_3244(C_word c,C_word *av) C_noret;
C_noret_decl(f_3252)
static void C_ccall f_3252(C_word c,C_word *av) C_noret;
C_noret_decl(f_3256)
static void C_ccall f_3256(C_word c,C_word *av) C_noret;
C_noret_decl(f_3260)
static void C_ccall f_3260(C_word c,C_word *av) C_noret;
C_noret_decl(f_3262)
static void C_ccall f_3262(C_word c,C_word *av) C_noret;
C_noret_decl(f_3281)
static void C_ccall f_3281(C_word c,C_word *av) C_noret;
C_noret_decl(f_3349)
static void C_ccall f_3349(C_word c,C_word *av) C_noret;
C_noret_decl(f_3357)
static void C_ccall f_3357(C_word c,C_word *av) C_noret;
C_noret_decl(f_3359)
static void C_ccall f_3359(C_word c,C_word *av) C_noret;
C_noret_decl(f_3367)
static void C_ccall f_3367(C_word c,C_word *av) C_noret;
C_noret_decl(f_3369)
static void C_ccall f_3369(C_word c,C_word *av) C_noret;
C_noret_decl(f_3377)
static void C_ccall f_3377(C_word c,C_word *av) C_noret;
C_noret_decl(f_3379)
static void C_ccall f_3379(C_word c,C_word *av) C_noret;
C_noret_decl(f_3387)
static void C_ccall f_3387(C_word c,C_word *av) C_noret;
C_noret_decl(f_3389)
static void C_ccall f_3389(C_word c,C_word *av) C_noret;
C_noret_decl(f_3397)
static void C_ccall f_3397(C_word c,C_word *av) C_noret;
C_noret_decl(f_3399)
static void C_ccall f_3399(C_word c,C_word *av) C_noret;
C_noret_decl(f_3407)
static void C_ccall f_3407(C_word c,C_word *av) C_noret;
C_noret_decl(f_3409)
static void C_ccall f_3409(C_word c,C_word *av) C_noret;
C_noret_decl(f_3417)
static void C_ccall f_3417(C_word c,C_word *av) C_noret;
C_noret_decl(f_3422)
static void C_ccall f_3422(C_word c,C_word *av) C_noret;
C_noret_decl(f_3429)
static void C_ccall f_3429(C_word c,C_word *av) C_noret;
C_noret_decl(f_3432)
static void C_ccall f_3432(C_word c,C_word *av) C_noret;
C_noret_decl(f_3438)
static void C_ccall f_3438(C_word c,C_word *av) C_noret;
C_noret_decl(f_3444)
static void C_ccall f_3444(C_word c,C_word *av) C_noret;
C_noret_decl(f_3477)
static void C_ccall f_3477(C_word c,C_word *av) C_noret;
C_noret_decl(f_3505)
static void C_fcall f_3505(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3513)
static void C_ccall f_3513(C_word c,C_word *av) C_noret;
C_noret_decl(f_3542)
static void C_fcall f_3542(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3555)
static void C_ccall f_3555(C_word c,C_word *av) C_noret;
C_noret_decl(f_3561)
static void C_ccall f_3561(C_word c,C_word *av) C_noret;
C_noret_decl(f_3565)
static void C_ccall f_3565(C_word c,C_word *av) C_noret;
C_noret_decl(f_3573)
static void C_ccall f_3573(C_word c,C_word *av) C_noret;
C_noret_decl(f_3575)
static void C_ccall f_3575(C_word c,C_word *av) C_noret;
C_noret_decl(f_3579)
static void C_ccall f_3579(C_word c,C_word *av) C_noret;
C_noret_decl(f_3587)
static void C_ccall f_3587(C_word c,C_word *av) C_noret;
C_noret_decl(f_3589)
static void C_ccall f_3589(C_word c,C_word *av) C_noret;
C_noret_decl(f_3605)
static void C_ccall f_3605(C_word c,C_word *av) C_noret;
C_noret_decl(f_3614)
static void C_ccall f_3614(C_word c,C_word *av) C_noret;
C_noret_decl(f_3628)
static void C_ccall f_3628(C_word c,C_word *av) C_noret;
C_noret_decl(f_3634)
static void C_ccall f_3634(C_word c,C_word *av) C_noret;
C_noret_decl(f_3638)
static void C_ccall f_3638(C_word c,C_word *av) C_noret;
C_noret_decl(f_3641)
static void C_fcall f_3641(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3644)
static void C_ccall f_3644(C_word c,C_word *av) C_noret;
C_noret_decl(f_3659)
static void C_ccall f_3659(C_word c,C_word *av) C_noret;
C_noret_decl(f_3661)
static void C_ccall f_3661(C_word c,C_word *av) C_noret;
C_noret_decl(f_3664)
static void C_ccall f_3664(C_word c,C_word *av) C_noret;
C_noret_decl(f_3668)
static void C_ccall f_3668(C_word c,C_word *av) C_noret;
C_noret_decl(f_3671)
static void C_ccall f_3671(C_word c,C_word *av) C_noret;
C_noret_decl(f_3680)
static void C_ccall f_3680(C_word c,C_word *av) C_noret;
C_noret_decl(f_3694)
static void C_ccall f_3694(C_word c,C_word *av) C_noret;
C_noret_decl(f_3697)
static void C_fcall f_3697(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3716)
static void C_ccall f_3716(C_word c,C_word *av) C_noret;
C_noret_decl(f_3720)
static void C_ccall f_3720(C_word c,C_word *av) C_noret;
C_noret_decl(f_3723)
static void C_ccall f_3723(C_word c,C_word *av) C_noret;
C_noret_decl(f_3737)
static void C_ccall f_3737(C_word c,C_word *av) C_noret;
C_noret_decl(f_3741)
static void C_ccall f_3741(C_word c,C_word *av) C_noret;
C_noret_decl(f_3744)
static void C_ccall f_3744(C_word c,C_word *av) C_noret;
C_noret_decl(f_3769)
static void C_ccall f_3769(C_word c,C_word *av) C_noret;
C_noret_decl(f_3773)
static void C_ccall f_3773(C_word c,C_word *av) C_noret;
C_noret_decl(f_3776)
static void C_ccall f_3776(C_word c,C_word *av) C_noret;
C_noret_decl(f_3779)
static void C_ccall f_3779(C_word c,C_word *av) C_noret;
C_noret_decl(f_3807)
static void C_ccall f_3807(C_word c,C_word *av) C_noret;
C_noret_decl(f_3811)
static void C_ccall f_3811(C_word c,C_word *av) C_noret;
C_noret_decl(f_3815)
static void C_ccall f_3815(C_word c,C_word *av) C_noret;
C_noret_decl(f_3852)
static void C_ccall f_3852(C_word c,C_word *av) C_noret;
C_noret_decl(f_3859)
static void C_ccall f_3859(C_word c,C_word *av) C_noret;
C_noret_decl(f_3868)
static void C_ccall f_3868(C_word c,C_word *av) C_noret;
C_noret_decl(f_3878)
static void C_ccall f_3878(C_word c,C_word *av) C_noret;
C_noret_decl(f_3882)
static void C_ccall f_3882(C_word c,C_word *av) C_noret;
C_noret_decl(f_3885)
static void C_ccall f_3885(C_word c,C_word *av) C_noret;
C_noret_decl(f_3906)
static void C_ccall f_3906(C_word c,C_word *av) C_noret;
C_noret_decl(f_3914)
static void C_ccall f_3914(C_word c,C_word *av) C_noret;
C_noret_decl(f_3918)
static void C_ccall f_3918(C_word c,C_word *av) C_noret;
C_noret_decl(f_3929)
static void C_ccall f_3929(C_word c,C_word *av) C_noret;
C_noret_decl(f_3931)
static void C_ccall f_3931(C_word c,C_word *av) C_noret;
C_noret_decl(f_3935)
static void C_ccall f_3935(C_word c,C_word *av) C_noret;
C_noret_decl(f_3936)
static void C_fcall f_3936(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3940)
static void C_ccall f_3940(C_word c,C_word *av) C_noret;
C_noret_decl(f_3945)
static void C_ccall f_3945(C_word c,C_word *av) C_noret;
C_noret_decl(f_3952)
static void C_ccall f_3952(C_word c,C_word *av) C_noret;
C_noret_decl(f_3953)
static void C_ccall f_3953(C_word c,C_word *av) C_noret;
C_noret_decl(f_3974)
static void C_fcall f_3974(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3984)
static void C_ccall f_3984(C_word c,C_word *av) C_noret;
C_noret_decl(f_3997)
static void C_ccall f_3997(C_word c,C_word *av) C_noret;
C_noret_decl(f_4001)
static void C_ccall f_4001(C_word c,C_word *av) C_noret;
C_noret_decl(f_4006)
static void C_ccall f_4006(C_word c,C_word *av) C_noret;
C_noret_decl(f_4010)
static void C_ccall f_4010(C_word c,C_word *av) C_noret;
C_noret_decl(f_4015)
static void C_ccall f_4015(C_word c,C_word *av) C_noret;
C_noret_decl(f_4019)
static void C_ccall f_4019(C_word c,C_word *av) C_noret;
C_noret_decl(f_4021)
static void C_ccall f_4021(C_word c,C_word *av) C_noret;
C_noret_decl(f_4040)
static void C_ccall f_4040(C_word c,C_word *av) C_noret;
C_noret_decl(f_4045)
static void C_ccall f_4045(C_word c,C_word *av) C_noret;
C_noret_decl(f_4051)
static void C_ccall f_4051(C_word c,C_word *av) C_noret;
C_noret_decl(f_4092)
static void C_fcall f_4092(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4100)
static void C_ccall f_4100(C_word c,C_word *av) C_noret;
C_noret_decl(f_4103)
static void C_ccall f_4103(C_word c,C_word *av) C_noret;
C_noret_decl(f_4108)
static void C_ccall f_4108(C_word c,C_word *av) C_noret;
C_noret_decl(f_4114)
static void C_ccall f_4114(C_word c,C_word *av) C_noret;
C_noret_decl(f_4120)
static void C_ccall f_4120(C_word c,C_word *av) C_noret;
C_noret_decl(f_4124)
static void C_ccall f_4124(C_word c,C_word *av) C_noret;
C_noret_decl(f_4129)
static void C_ccall f_4129(C_word c,C_word *av) C_noret;
C_noret_decl(f_4131)
static void C_fcall f_4131(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4135)
static void C_ccall f_4135(C_word c,C_word *av) C_noret;
C_noret_decl(f_4137)
static void C_fcall f_4137(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4153)
static void C_ccall f_4153(C_word c,C_word *av) C_noret;
C_noret_decl(f_4159)
static void C_ccall f_4159(C_word c,C_word *av) C_noret;
C_noret_decl(f_4162)
static void C_ccall f_4162(C_word c,C_word *av) C_noret;
C_noret_decl(f_4178)
static void C_ccall f_4178(C_word c,C_word *av) C_noret;
C_noret_decl(f_4188)
static void C_fcall f_4188(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4194)
static void C_ccall f_4194(C_word c,C_word *av) C_noret;
C_noret_decl(f_4205)
static void C_ccall f_4205(C_word c,C_word *av) C_noret;
C_noret_decl(f_4209)
static void C_fcall f_4209(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4213)
static void C_ccall f_4213(C_word c,C_word *av) C_noret;
C_noret_decl(f_4218)
static void C_fcall f_4218(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4228)
static void C_ccall f_4228(C_word c,C_word *av) C_noret;
C_noret_decl(f_4231)
static void C_ccall f_4231(C_word c,C_word *av) C_noret;
C_noret_decl(f_4243)
static void C_fcall f_4243(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4248)
static C_word C_fcall f_4248(C_word t0,C_word t1);
C_noret_decl(f_4267)
static C_word C_fcall f_4267(C_word t0,C_word t1);
C_noret_decl(f_4290)
static void C_ccall f_4290(C_word c,C_word *av) C_noret;
C_noret_decl(f_4292)
static void C_fcall f_4292(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7) C_noret;
C_noret_decl(f_4299)
static void C_ccall f_4299(C_word c,C_word *av) C_noret;
C_noret_decl(f_4302)
static void C_ccall f_4302(C_word c,C_word *av) C_noret;
C_noret_decl(f_4307)
static void C_ccall f_4307(C_word c,C_word *av) C_noret;
C_noret_decl(f_4313)
static void C_ccall f_4313(C_word c,C_word *av) C_noret;
C_noret_decl(f_4319)
static void C_ccall f_4319(C_word c,C_word *av) C_noret;
C_noret_decl(f_4323)
static void C_ccall f_4323(C_word c,C_word *av) C_noret;
C_noret_decl(f_4326)
static void C_ccall f_4326(C_word c,C_word *av) C_noret;
C_noret_decl(f_4334)
static void C_ccall f_4334(C_word c,C_word *av) C_noret;
C_noret_decl(f_4340)
static void C_ccall f_4340(C_word c,C_word *av) C_noret;
C_noret_decl(f_4344)
static void C_fcall f_4344(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4351)
static void C_ccall f_4351(C_word c,C_word *av) C_noret;
C_noret_decl(f_4354)
static void C_ccall f_4354(C_word c,C_word *av) C_noret;
C_noret_decl(f_4358)
static void C_ccall f_4358(C_word c,C_word *av) C_noret;
C_noret_decl(f_4379)
static void C_ccall f_4379(C_word c,C_word *av) C_noret;
C_noret_decl(f_4381)
static void C_fcall f_4381(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4406)
static void C_ccall f_4406(C_word c,C_word *av) C_noret;
C_noret_decl(f_4415)
static void C_ccall f_4415(C_word c,C_word *av) C_noret;
C_noret_decl(f_4421)
static void C_ccall f_4421(C_word c,C_word *av) C_noret;
C_noret_decl(f_4446)
static void C_fcall f_4446(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_4459)
static void C_ccall f_4459(C_word c,C_word *av) C_noret;
C_noret_decl(f_4465)
static void C_ccall f_4465(C_word c,C_word *av) C_noret;
C_noret_decl(f_4479)
static void C_ccall f_4479(C_word c,C_word *av) C_noret;
C_noret_decl(f_4486)
static void C_ccall f_4486(C_word c,C_word *av) C_noret;
C_noret_decl(f_4496)
static void C_ccall f_4496(C_word c,C_word *av) C_noret;
C_noret_decl(f_4505)
static void C_ccall f_4505(C_word c,C_word *av) C_noret;
C_noret_decl(f_4519)
static void C_ccall f_4519(C_word c,C_word *av) C_noret;
C_noret_decl(f_4526)
static void C_ccall f_4526(C_word c,C_word *av) C_noret;
C_noret_decl(f_4536)
static void C_ccall f_4536(C_word c,C_word *av) C_noret;
C_noret_decl(f_4545)
static void C_ccall f_4545(C_word c,C_word *av) C_noret;
C_noret_decl(f_4552)
static void C_ccall f_4552(C_word c,C_word *av) C_noret;
C_noret_decl(f_4560)
static void C_ccall f_4560(C_word c,C_word *av) C_noret;
C_noret_decl(f_4567)
static void C_ccall f_4567(C_word c,C_word *av) C_noret;
C_noret_decl(f_4575)
static void C_ccall f_4575(C_word c,C_word *av) C_noret;
C_noret_decl(f_4579)
static void C_ccall f_4579(C_word c,C_word *av) C_noret;
C_noret_decl(f_4584)
static void C_ccall f_4584(C_word c,C_word *av) C_noret;
C_noret_decl(f_4589)
static void C_ccall f_4589(C_word c,C_word *av) C_noret;
C_noret_decl(f_4595)
static void C_ccall f_4595(C_word c,C_word *av) C_noret;
C_noret_decl(f_4599)
static void C_ccall f_4599(C_word c,C_word *av) C_noret;
C_noret_decl(f_4604)
static void C_ccall f_4604(C_word c,C_word *av) C_noret;
C_noret_decl(f_4609)
static void C_ccall f_4609(C_word c,C_word *av) C_noret;
C_noret_decl(f_4613)
static void C_ccall f_4613(C_word c,C_word *av) C_noret;
C_noret_decl(f_4618)
static void C_ccall f_4618(C_word c,C_word *av) C_noret;
C_noret_decl(f_4624)
static void C_ccall f_4624(C_word c,C_word *av) C_noret;
C_noret_decl(f_4628)
static void C_ccall f_4628(C_word c,C_word *av) C_noret;
C_noret_decl(f_4633)
static void C_ccall f_4633(C_word c,C_word *av) C_noret;
C_noret_decl(f_4637)
static void C_ccall f_4637(C_word c,C_word *av) C_noret;
C_noret_decl(f_4642)
static void C_ccall f_4642(C_word c,C_word *av) C_noret;
C_noret_decl(f_4648)
static void C_ccall f_4648(C_word c,C_word *av) C_noret;
C_noret_decl(f_4652)
static void C_ccall f_4652(C_word c,C_word *av) C_noret;
C_noret_decl(f_4657)
static void C_ccall f_4657(C_word c,C_word *av) C_noret;
C_noret_decl(f_4661)
static void C_ccall f_4661(C_word c,C_word *av) C_noret;
C_noret_decl(f_4666)
static void C_ccall f_4666(C_word c,C_word *av) C_noret;
C_noret_decl(f_4671)
static void C_ccall f_4671(C_word c,C_word *av) C_noret;
C_noret_decl(f_4677)
static void C_ccall f_4677(C_word c,C_word *av) C_noret;
C_noret_decl(f_4681)
static void C_ccall f_4681(C_word c,C_word *av) C_noret;
C_noret_decl(f_4686)
static void C_ccall f_4686(C_word c,C_word *av) C_noret;
C_noret_decl(f_4691)
static void C_ccall f_4691(C_word c,C_word *av) C_noret;
C_noret_decl(f_4698)
static void C_ccall f_4698(C_word c,C_word *av) C_noret;
C_noret_decl(f_4738)
static void C_ccall f_4738(C_word c,C_word *av) C_noret;
C_noret_decl(f_4745)
static void C_ccall f_4745(C_word c,C_word *av) C_noret;
C_noret_decl(f_4748)
static void C_ccall f_4748(C_word c,C_word *av) C_noret;
C_noret_decl(f_4771)
static void C_ccall f_4771(C_word c,C_word *av) C_noret;
C_noret_decl(f_4781)
static void C_ccall f_4781(C_word c,C_word *av) C_noret;
C_noret_decl(f_4784)
static void C_ccall f_4784(C_word c,C_word *av) C_noret;
C_noret_decl(f_4788)
static void C_ccall f_4788(C_word c,C_word *av) C_noret;
C_noret_decl(f_4791)
static void C_ccall f_4791(C_word c,C_word *av) C_noret;
C_noret_decl(f_4803)
static void C_ccall f_4803(C_word c,C_word *av) C_noret;
C_noret_decl(f_4807)
static void C_ccall f_4807(C_word c,C_word *av) C_noret;
C_noret_decl(f_4812)
static void C_ccall f_4812(C_word c,C_word *av) C_noret;
C_noret_decl(f_4834)
static void C_ccall f_4834(C_word c,C_word *av) C_noret;
C_noret_decl(f_4838)
static void C_ccall f_4838(C_word c,C_word *av) C_noret;
C_noret_decl(f_4841)
static void C_ccall f_4841(C_word c,C_word *av) C_noret;
C_noret_decl(f_4844)
static void C_ccall f_4844(C_word c,C_word *av) C_noret;
C_noret_decl(f_4847)
static void C_ccall f_4847(C_word c,C_word *av) C_noret;
C_noret_decl(f_4850)
static void C_ccall f_4850(C_word c,C_word *av) C_noret;
C_noret_decl(f_4874)
static void C_ccall f_4874(C_word c,C_word *av) C_noret;
C_noret_decl(f_4878)
static void C_ccall f_4878(C_word c,C_word *av) C_noret;
C_noret_decl(f_4881)
static void C_ccall f_4881(C_word c,C_word *av) C_noret;
C_noret_decl(f_4887)
static void C_ccall f_4887(C_word c,C_word *av) C_noret;
C_noret_decl(f_4890)
static void C_ccall f_4890(C_word c,C_word *av) C_noret;
C_noret_decl(f_4911)
static void C_ccall f_4911(C_word c,C_word *av) C_noret;
C_noret_decl(f_4918)
static void C_ccall f_4918(C_word c,C_word *av) C_noret;
C_noret_decl(f_4924)
static void C_ccall f_4924(C_word c,C_word *av) C_noret;
C_noret_decl(f_4931)
static void C_ccall f_4931(C_word c,C_word *av) C_noret;
C_noret_decl(f_4943)
static void C_ccall f_4943(C_word c,C_word *av) C_noret;
C_noret_decl(f_4950)
static void C_fcall f_4950(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4953)
static void C_fcall f_4953(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4961)
static void C_ccall f_4961(C_word c,C_word *av) C_noret;
C_noret_decl(f_5022)
static void C_ccall f_5022(C_word c,C_word *av) C_noret;
C_noret_decl(f_5025)
static void C_ccall f_5025(C_word c,C_word *av) C_noret;
C_noret_decl(f_5032)
static void C_fcall f_5032(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5062)
static void C_fcall f_5062(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5121)
static void C_fcall f_5121(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5182)
static void C_ccall f_5182(C_word c,C_word *av) C_noret;
C_noret_decl(f_5189)
static void C_ccall f_5189(C_word c,C_word *av) C_noret;
C_noret_decl(f_5197)
static void C_ccall f_5197(C_word c,C_word *av) C_noret;
C_noret_decl(f_5199)
static C_word C_fcall f_5199(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_5241)
static C_word C_fcall f_5241(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_5322)
static void C_ccall f_5322(C_word c,C_word *av) C_noret;
C_noret_decl(f_5329)
static void C_ccall f_5329(C_word c,C_word *av) C_noret;
C_noret_decl(f_5378)
static void C_ccall f_5378(C_word c,C_word *av) C_noret;
C_noret_decl(f_5387)
static void C_ccall f_5387(C_word c,C_word *av) C_noret;
C_noret_decl(f_5390)
static void C_ccall f_5390(C_word c,C_word *av) C_noret;
C_noret_decl(f_5402)
static void C_fcall f_5402(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5427)
static void C_ccall f_5427(C_word c,C_word *av) C_noret;
C_noret_decl(f_5429)
static void C_ccall f_5429(C_word c,C_word *av) C_noret;
C_noret_decl(f_5433)
static void C_ccall f_5433(C_word c,C_word *av) C_noret;
C_noret_decl(f_5435)
static void C_ccall f_5435(C_word c,C_word *av) C_noret;
C_noret_decl(f_5439)
static void C_ccall f_5439(C_word c,C_word *av) C_noret;
C_noret_decl(f_5451)
static void C_ccall f_5451(C_word c,C_word *av) C_noret;
C_noret_decl(f_5455)
static void C_ccall f_5455(C_word c,C_word *av) C_noret;
C_noret_decl(f_5469)
static void C_ccall f_5469(C_word c,C_word *av) C_noret;
C_noret_decl(f_5473)
static void C_ccall f_5473(C_word c,C_word *av) C_noret;
C_noret_decl(f_5477)
static void C_ccall f_5477(C_word c,C_word *av) C_noret;
C_noret_decl(f_5481)
static void C_ccall f_5481(C_word c,C_word *av) C_noret;
C_noret_decl(f_5483)
static void C_ccall f_5483(C_word c,C_word *av) C_noret;
C_noret_decl(f_5490)
static void C_fcall f_5490(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5503)
static void C_ccall f_5503(C_word c,C_word *av) C_noret;
C_noret_decl(f_5507)
static void C_ccall f_5507(C_word c,C_word *av) C_noret;
C_noret_decl(f_5511)
static void C_ccall f_5511(C_word c,C_word *av) C_noret;
C_noret_decl(f_5515)
static void C_ccall f_5515(C_word c,C_word *av) C_noret;
C_noret_decl(f_5519)
static void C_ccall f_5519(C_word c,C_word *av) C_noret;
C_noret_decl(f_5529)
static void C_ccall f_5529(C_word c,C_word *av) C_noret;
C_noret_decl(f_5537)
static void C_ccall f_5537(C_word c,C_word *av) C_noret;
C_noret_decl(f_5545)
static void C_ccall f_5545(C_word c,C_word *av) C_noret;
C_noret_decl(f_5549)
static void C_ccall f_5549(C_word c,C_word *av) C_noret;
C_noret_decl(f_5551)
static void C_ccall f_5551(C_word c,C_word *av) C_noret;
C_noret_decl(f_5559)
static void C_ccall f_5559(C_word c,C_word *av) C_noret;
C_noret_decl(f_5563)
static void C_ccall f_5563(C_word c,C_word *av) C_noret;
C_noret_decl(f_5565)
static void C_fcall f_5565(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5569)
static void C_ccall f_5569(C_word c,C_word *av) C_noret;
C_noret_decl(f_5572)
static void C_ccall f_5572(C_word c,C_word *av) C_noret;
C_noret_decl(f_5575)
static void C_ccall f_5575(C_word c,C_word *av) C_noret;
C_noret_decl(f_5587)
static void C_ccall f_5587(C_word c,C_word *av) C_noret;
C_noret_decl(f_5591)
static void C_ccall f_5591(C_word c,C_word *av) C_noret;
C_noret_decl(f_5607)
static void C_ccall f_5607(C_word c,C_word *av) C_noret;
C_noret_decl(f_5612)
static void C_ccall f_5612(C_word c,C_word *av) C_noret;
C_noret_decl(f_5616)
static void C_ccall f_5616(C_word c,C_word *av) C_noret;
C_noret_decl(f_5626)
static void C_ccall f_5626(C_word c,C_word *av) C_noret;
C_noret_decl(f_5630)
static void C_ccall f_5630(C_word c,C_word *av) C_noret;
C_noret_decl(f_5632)
static void C_ccall f_5632(C_word c,C_word *av) C_noret;
C_noret_decl(f_5653)
static void C_ccall f_5653(C_word c,C_word *av) C_noret;
C_noret_decl(f_5657)
static void C_ccall f_5657(C_word c,C_word *av) C_noret;
C_noret_decl(f_5661)
static void C_ccall f_5661(C_word c,C_word *av) C_noret;
C_noret_decl(f_5662)
static void C_ccall f_5662(C_word c,C_word *av) C_noret;
C_noret_decl(f_5667)
static void C_ccall f_5667(C_word c,C_word *av) C_noret;
C_noret_decl(f_5681)
static void C_ccall f_5681(C_word c,C_word *av) C_noret;
C_noret_decl(f_5696)
static void C_ccall f_5696(C_word c,C_word *av) C_noret;
C_noret_decl(f_5702)
static void C_ccall f_5702(C_word c,C_word *av) C_noret;
C_noret_decl(f_5710)
static void C_ccall f_5710(C_word c,C_word *av) C_noret;
C_noret_decl(f_5712)
static void C_fcall f_5712(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5722)
static void C_ccall f_5722(C_word c,C_word *av) C_noret;
C_noret_decl(f_5728)
static void C_ccall f_5728(C_word c,C_word *av) C_noret;
C_noret_decl(f_5737)
static void C_ccall f_5737(C_word c,C_word *av) C_noret;
C_noret_decl(f_5740)
static void C_ccall f_5740(C_word c,C_word *av) C_noret;
C_noret_decl(f_5743)
static void C_ccall f_5743(C_word c,C_word *av) C_noret;
C_noret_decl(f_5749)
static void C_ccall f_5749(C_word c,C_word *av) C_noret;
C_noret_decl(f_5783)
static void C_ccall f_5783(C_word c,C_word *av) C_noret;
C_noret_decl(f_5787)
static void C_ccall f_5787(C_word c,C_word *av) C_noret;
C_noret_decl(f_5796)
static void C_ccall f_5796(C_word c,C_word *av) C_noret;
C_noret_decl(f_5818)
static void C_ccall f_5818(C_word c,C_word *av) C_noret;
C_noret_decl(f_5846)
static void C_ccall f_5846(C_word c,C_word *av) C_noret;
C_noret_decl(f_5852)
static void C_ccall f_5852(C_word c,C_word *av) C_noret;
C_noret_decl(f_5853)
static void C_fcall f_5853(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5857)
static void C_ccall f_5857(C_word c,C_word *av) C_noret;
C_noret_decl(f_5882)
static C_word C_fcall f_5882(C_word t0);
C_noret_decl(f_5890)
static void C_fcall f_5890(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5896)
static void C_ccall f_5896(C_word c,C_word *av) C_noret;
C_noret_decl(f_5915)
static void C_ccall f_5915(C_word c,C_word *av) C_noret;
C_noret_decl(f_5918)
static void C_ccall f_5918(C_word c,C_word *av) C_noret;
C_noret_decl(f_5948)
static void C_ccall f_5948(C_word c,C_word *av) C_noret;
C_noret_decl(f_5951)
static void C_ccall f_5951(C_word c,C_word *av) C_noret;
C_noret_decl(f_5957)
static void C_ccall f_5957(C_word c,C_word *av) C_noret;
C_noret_decl(f_5986)
static void C_ccall f_5986(C_word c,C_word *av) C_noret;
C_noret_decl(f_5992)
static void C_ccall f_5992(C_word c,C_word *av) C_noret;
C_noret_decl(f_5996)
static void C_ccall f_5996(C_word c,C_word *av) C_noret;
C_noret_decl(f_6017)
static void C_ccall f_6017(C_word c,C_word *av) C_noret;
C_noret_decl(f_6029)
static void C_ccall f_6029(C_word c,C_word *av) C_noret;
C_noret_decl(f_6033)
static void C_ccall f_6033(C_word c,C_word *av) C_noret;
C_noret_decl(f_6045)
static void C_ccall f_6045(C_word c,C_word *av) C_noret;
C_noret_decl(f_6049)
static void C_ccall f_6049(C_word c,C_word *av) C_noret;
C_noret_decl(f_6060)
static void C_ccall f_6060(C_word c,C_word *av) C_noret;
C_noret_decl(f_6070)
static void C_fcall f_6070(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_6118)
static void C_ccall f_6118(C_word c,C_word *av) C_noret;
C_noret_decl(f_6136)
static void C_ccall f_6136(C_word c,C_word *av) C_noret;
C_noret_decl(f_6140)
static void C_ccall f_6140(C_word c,C_word *av) C_noret;
C_noret_decl(f_6154)
static void C_ccall f_6154(C_word c,C_word *av) C_noret;
C_noret_decl(f_6164)
static void C_ccall f_6164(C_word c,C_word *av) C_noret;
C_noret_decl(f_6184)
static void C_ccall f_6184(C_word c,C_word *av) C_noret;
C_noret_decl(f_6210)
static void C_ccall f_6210(C_word c,C_word *av) C_noret;
C_noret_decl(f_6255)
static void C_ccall f_6255(C_word c,C_word *av) C_noret;
C_noret_decl(f_6265)
static void C_ccall f_6265(C_word c,C_word *av) C_noret;
C_noret_decl(f_6331)
static void C_ccall f_6331(C_word c,C_word *av) C_noret;
C_noret_decl(f_6353)
static void C_ccall f_6353(C_word c,C_word *av) C_noret;
C_noret_decl(f_6354)
static void C_ccall f_6354(C_word c,C_word *av) C_noret;
C_noret_decl(f_6360)
static void C_ccall f_6360(C_word c,C_word *av) C_noret;
C_noret_decl(f_6379)
static void C_ccall f_6379(C_word c,C_word *av) C_noret;
C_noret_decl(f_6410)
static void C_ccall f_6410(C_word c,C_word *av) C_noret;
C_noret_decl(f_6420)
static void C_fcall f_6420(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6425)
static void C_ccall f_6425(C_word c,C_word *av) C_noret;
C_noret_decl(f_6431)
static void C_ccall f_6431(C_word c,C_word *av) C_noret;
C_noret_decl(f_6437)
static void C_ccall f_6437(C_word c,C_word *av) C_noret;
C_noret_decl(f_6441)
static void C_ccall f_6441(C_word c,C_word *av) C_noret;
C_noret_decl(f_6453)
static void C_ccall f_6453(C_word c,C_word *av) C_noret;
C_noret_decl(f_6461)
static void C_ccall f_6461(C_word c,C_word *av) C_noret;
C_noret_decl(f_6475)
static void C_ccall f_6475(C_word c,C_word *av) C_noret;
C_noret_decl(f_6476)
static void C_ccall f_6476(C_word c,C_word *av) C_noret;
C_noret_decl(f_6493)
static void C_fcall f_6493(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_6503)
static void C_ccall f_6503(C_word c,C_word *av) C_noret;
C_noret_decl(f_6586)
static void C_ccall f_6586(C_word c,C_word *av) C_noret;
C_noret_decl(f_6590)
static void C_ccall f_6590(C_word c,C_word *av) C_noret;
C_noret_decl(f_6596)
static void C_fcall f_6596(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6603)
static void C_ccall f_6603(C_word c,C_word *av) C_noret;
C_noret_decl(f_6610)
static void C_ccall f_6610(C_word c,C_word *av) C_noret;
C_noret_decl(f_6616)
static void C_ccall f_6616(C_word c,C_word *av) C_noret;
C_noret_decl(f_6620)
static void C_ccall f_6620(C_word c,C_word *av) C_noret;
C_noret_decl(f_6631)
static void C_fcall f_6631(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6649)
static void C_ccall f_6649(C_word c,C_word *av) C_noret;
C_noret_decl(f_6652)
static void C_ccall f_6652(C_word c,C_word *av) C_noret;
C_noret_decl(f_6717)
static void C_ccall f_6717(C_word c,C_word *av) C_noret;
C_noret_decl(f_6723)
static void C_ccall f_6723(C_word c,C_word *av) C_noret;
C_noret_decl(f_6727)
static void C_ccall f_6727(C_word c,C_word *av) C_noret;
C_noret_decl(f_6748)
static void C_ccall f_6748(C_word c,C_word *av) C_noret;
C_noret_decl(f_6754)
static void C_ccall f_6754(C_word c,C_word *av) C_noret;
C_noret_decl(f_6758)
static void C_ccall f_6758(C_word c,C_word *av) C_noret;
C_noret_decl(f_6779)
static void C_ccall f_6779(C_word c,C_word *av) C_noret;
C_noret_decl(f_6783)
static void C_ccall f_6783(C_word c,C_word *av) C_noret;
C_noret_decl(f_6806)
static void C_ccall f_6806(C_word c,C_word *av) C_noret;
C_noret_decl(f_6835)
static void C_ccall f_6835(C_word c,C_word *av) C_noret;
C_noret_decl(f_6849)
static void C_ccall f_6849(C_word c,C_word *av) C_noret;
C_noret_decl(f_6859)
static void C_ccall f_6859(C_word c,C_word *av) C_noret;
C_noret_decl(f_6873)
static void C_ccall f_6873(C_word c,C_word *av) C_noret;
C_noret_decl(f_6895)
static void C_ccall f_6895(C_word c,C_word *av) C_noret;
C_noret_decl(f_6912)
static void C_ccall f_6912(C_word c,C_word *av) C_noret;
C_noret_decl(f_6916)
static void C_ccall f_6916(C_word c,C_word *av) C_noret;
C_noret_decl(f_6924)
static void C_ccall f_6924(C_word c,C_word *av) C_noret;
C_noret_decl(f_6932)
static void C_ccall f_6932(C_word c,C_word *av) C_noret;
C_noret_decl(f_6936)
static void C_ccall f_6936(C_word c,C_word *av) C_noret;
C_noret_decl(f_6940)
static void C_ccall f_6940(C_word c,C_word *av) C_noret;
C_noret_decl(f_6951)
static void C_ccall f_6951(C_word c,C_word *av) C_noret;
C_noret_decl(f_6958)
static void C_ccall f_6958(C_word c,C_word *av) C_noret;
C_noret_decl(f_6967)
static void C_ccall f_6967(C_word c,C_word *av) C_noret;
C_noret_decl(f_6998)
static void C_ccall f_6998(C_word c,C_word *av) C_noret;
C_noret_decl(f_7012)
static void C_ccall f_7012(C_word c,C_word *av) C_noret;
C_noret_decl(f_7018)
static void C_ccall f_7018(C_word c,C_word *av) C_noret;
C_noret_decl(f_7022)
static void C_ccall f_7022(C_word c,C_word *av) C_noret;
C_noret_decl(f_7026)
static void C_ccall f_7026(C_word c,C_word *av) C_noret;
C_noret_decl(f_7066)
static void C_ccall f_7066(C_word c,C_word *av) C_noret;
C_noret_decl(f_7090)
static void C_ccall f_7090(C_word c,C_word *av) C_noret;
C_noret_decl(f_7093)
static void C_ccall f_7093(C_word c,C_word *av) C_noret;
C_noret_decl(f_7144)
static void C_fcall f_7144(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7160)
static void C_ccall f_7160(C_word c,C_word *av) C_noret;
C_noret_decl(f_7182)
static void C_ccall f_7182(C_word c,C_word *av) C_noret;
C_noret_decl(f_7185)
static void C_ccall f_7185(C_word c,C_word *av) C_noret;
C_noret_decl(f_7192)
static void C_ccall f_7192(C_word c,C_word *av) C_noret;
C_noret_decl(f_7195)
static void C_ccall f_7195(C_word c,C_word *av) C_noret;
C_noret_decl(f_7225)
static void C_ccall f_7225(C_word c,C_word *av) C_noret;
C_noret_decl(f_7232)
static void C_ccall f_7232(C_word c,C_word *av) C_noret;
C_noret_decl(f_7275)
static void C_ccall f_7275(C_word c,C_word *av) C_noret;
C_noret_decl(f_7279)
static void C_fcall f_7279(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_7281)
static void C_ccall f_7281(C_word c,C_word *av) C_noret;
C_noret_decl(f_7296)
static void C_ccall f_7296(C_word c,C_word *av) C_noret;
C_noret_decl(f_7302)
static void C_ccall f_7302(C_word c,C_word *av) C_noret;
C_noret_decl(f_7316)
static void C_fcall f_7316(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7325)
static void C_ccall f_7325(C_word c,C_word *av) C_noret;
C_noret_decl(f_7331)
static void C_ccall f_7331(C_word c,C_word *av) C_noret;
C_noret_decl(f_7336)
static void C_fcall f_7336(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7347)
static void C_ccall f_7347(C_word c,C_word *av) C_noret;
C_noret_decl(f_7348)
static void C_fcall f_7348(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7359)
static void C_ccall f_7359(C_word c,C_word *av) C_noret;
C_noret_decl(f_7377)
static void C_fcall f_7377(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7) C_noret;
C_noret_decl(f_7381)
static void C_ccall f_7381(C_word c,C_word *av) C_noret;
C_noret_decl(f_7384)
static void C_ccall f_7384(C_word c,C_word *av) C_noret;
C_noret_decl(f_7387)
static void C_ccall f_7387(C_word c,C_word *av) C_noret;
C_noret_decl(f_7394)
static void C_fcall f_7394(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7398)
static void C_ccall f_7398(C_word c,C_word *av) C_noret;
C_noret_decl(f_7400)
static void C_ccall f_7400(C_word c,C_word *av) C_noret;
C_noret_decl(f_7404)
static void C_ccall f_7404(C_word c,C_word *av) C_noret;
C_noret_decl(f_7407)
static void C_ccall f_7407(C_word c,C_word *av) C_noret;
C_noret_decl(f_7410)
static void C_ccall f_7410(C_word c,C_word *av) C_noret;
C_noret_decl(f_7422)
static void C_fcall f_7422(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_7426)
static void C_ccall f_7426(C_word c,C_word *av) C_noret;
C_noret_decl(f_7433)
static void C_fcall f_7433(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_7437)
static void C_ccall f_7437(C_word c,C_word *av) C_noret;
C_noret_decl(f_7444)
static void C_fcall f_7444(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7,C_word t8) C_noret;
C_noret_decl(f_7450)
static void C_ccall f_7450(C_word c,C_word *av) C_noret;
C_noret_decl(f_7456)
static void C_ccall f_7456(C_word c,C_word *av) C_noret;
C_noret_decl(f_7467)
static void C_ccall f_7467(C_word c,C_word *av) C_noret;
C_noret_decl(f_7471)
static void C_ccall f_7471(C_word c,C_word *av) C_noret;
C_noret_decl(f_7475)
static void C_ccall f_7475(C_word c,C_word *av) C_noret;
C_noret_decl(f_7479)
static void C_ccall f_7479(C_word c,C_word *av) C_noret;
C_noret_decl(f_7483)
static void C_ccall f_7483(C_word c,C_word *av) C_noret;
C_noret_decl(f_7487)
static void C_ccall f_7487(C_word c,C_word *av) C_noret;
C_noret_decl(f_7500)
static void C_fcall f_7500(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_7502)
static void C_fcall f_7502(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7507)
static C_word C_fcall f_7507(C_word t0,C_word t1);
C_noret_decl(f_7516)
static C_word C_fcall f_7516(C_word t0,C_word t1);
C_noret_decl(f_7543)
static void C_ccall f_7543(C_word c,C_word *av) C_noret;
C_noret_decl(f_7546)
static void C_ccall f_7546(C_word c,C_word *av) C_noret;
C_noret_decl(f_7551)
static void C_ccall f_7551(C_word c,C_word *av) C_noret;
C_noret_decl(f_7571)
static void C_ccall f_7571(C_word c,C_word *av) C_noret;
C_noret_decl(f_7595)
static void C_ccall f_7595(C_word c,C_word *av) C_noret;
C_noret_decl(f_7637)
static void C_ccall f_7637(C_word c,C_word *av) C_noret;
C_noret_decl(f_7702)
static void C_ccall f_7702(C_word c,C_word *av) C_noret;
C_noret_decl(f_7707)
static void C_ccall f_7707(C_word c,C_word *av) C_noret;
C_noret_decl(f_7726)
static void C_ccall f_7726(C_word c,C_word *av) C_noret;
C_noret_decl(f_7732)
static void C_ccall f_7732(C_word c,C_word *av) C_noret;
C_noret_decl(f_7781)
static void C_ccall f_7781(C_word c,C_word *av) C_noret;
C_noret_decl(f_7785)
static void C_ccall f_7785(C_word c,C_word *av) C_noret;
C_noret_decl(f_7788)
static void C_ccall f_7788(C_word c,C_word *av) C_noret;
C_noret_decl(f_7798)
static void C_ccall f_7798(C_word c,C_word *av) C_noret;
C_noret_decl(f_7800)
static void C_ccall f_7800(C_word c,C_word *av) C_noret;
C_noret_decl(f_7804)
static void C_ccall f_7804(C_word c,C_word *av) C_noret;
C_noret_decl(f_7807)
static void C_ccall f_7807(C_word c,C_word *av) C_noret;
C_noret_decl(f_7820)
static void C_ccall f_7820(C_word c,C_word *av) C_noret;
C_noret_decl(f_7823)
static void C_ccall f_7823(C_word c,C_word *av) C_noret;
C_noret_decl(f_7826)
static void C_ccall f_7826(C_word c,C_word *av) C_noret;
C_noret_decl(f_7830)
static void C_ccall f_7830(C_word c,C_word *av) C_noret;
C_noret_decl(f_7843)
static void C_ccall f_7843(C_word c,C_word *av) C_noret;
C_noret_decl(f_7846)
static void C_ccall f_7846(C_word c,C_word *av) C_noret;
C_noret_decl(f_7849)
static void C_ccall f_7849(C_word c,C_word *av) C_noret;
C_noret_decl(f_7853)
static void C_ccall f_7853(C_word c,C_word *av) C_noret;
C_noret_decl(f_7866)
static void C_ccall f_7866(C_word c,C_word *av) C_noret;
C_noret_decl(f_7869)
static void C_ccall f_7869(C_word c,C_word *av) C_noret;
C_noret_decl(f_7872)
static void C_ccall f_7872(C_word c,C_word *av) C_noret;
C_noret_decl(f_7876)
static void C_ccall f_7876(C_word c,C_word *av) C_noret;
C_noret_decl(f_7889)
static void C_ccall f_7889(C_word c,C_word *av) C_noret;
C_noret_decl(f_7892)
static void C_ccall f_7892(C_word c,C_word *av) C_noret;
C_noret_decl(f_7895)
static void C_ccall f_7895(C_word c,C_word *av) C_noret;
C_noret_decl(f_7899)
static void C_ccall f_7899(C_word c,C_word *av) C_noret;
C_noret_decl(f_7912)
static void C_ccall f_7912(C_word c,C_word *av) C_noret;
C_noret_decl(f_7915)
static void C_ccall f_7915(C_word c,C_word *av) C_noret;
C_noret_decl(f_7921)
static void C_fcall f_7921(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7945)
static void C_ccall f_7945(C_word c,C_word *av) C_noret;
C_noret_decl(f_7949)
static void C_ccall f_7949(C_word c,C_word *av) C_noret;
C_noret_decl(f_7954)
static void C_ccall f_7954(C_word c,C_word *av) C_noret;
C_noret_decl(f_7961)
static void C_ccall f_7961(C_word c,C_word *av) C_noret;
C_noret_decl(f_7979)
static void C_ccall f_7979(C_word c,C_word *av) C_noret;
C_noret_decl(f_7983)
static void C_ccall f_7983(C_word c,C_word *av) C_noret;
C_noret_decl(f_7985)
static void C_ccall f_7985(C_word c,C_word *av) C_noret;
C_noret_decl(f_7989)
static void C_ccall f_7989(C_word c,C_word *av) C_noret;
C_noret_decl(f_7992)
static void C_ccall f_7992(C_word c,C_word *av) C_noret;
C_noret_decl(f_8001)
static void C_ccall f_8001(C_word c,C_word *av) C_noret;
C_noret_decl(f_8022)
static void C_ccall f_8022(C_word c,C_word *av) C_noret;
C_noret_decl(f_8026)
static void C_ccall f_8026(C_word c,C_word *av) C_noret;
C_noret_decl(f_8028)
static void C_ccall f_8028(C_word c,C_word *av) C_noret;
C_noret_decl(f_8032)
static void C_ccall f_8032(C_word c,C_word *av) C_noret;
C_noret_decl(f_8034)
static void C_ccall f_8034(C_word c,C_word *av) C_noret;
C_noret_decl(f_8038)
static void C_ccall f_8038(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externexport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(va8871)
static void C_fcall va8871(C_word t0,C_word t1) C_noret;
C_noret_decl(va8873)
static void C_fcall va8873(C_word t0,C_word t1) C_noret;
C_noret_decl(va8875)
static void C_fcall va8875(C_word t0,C_word t1) C_noret;
C_noret_decl(va8877)
static void C_fcall va8877(C_word t0,C_word t1) C_noret;

C_noret_decl(trf_2833)
static void C_ccall trf_2833(C_word c,C_word *av) C_noret;
static void C_ccall trf_2833(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2833(t0,t1,t2);}

C_noret_decl(trf_2874)
static void C_ccall trf_2874(C_word c,C_word *av) C_noret;
static void C_ccall trf_2874(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2874(t0,t1,t2);}

C_noret_decl(trf_3027)
static void C_ccall trf_3027(C_word c,C_word *av) C_noret;
static void C_ccall trf_3027(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3027(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3188)
static void C_ccall trf_3188(C_word c,C_word *av) C_noret;
static void C_ccall trf_3188(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3188(t0,t1);}

C_noret_decl(trf_3505)
static void C_ccall trf_3505(C_word c,C_word *av) C_noret;
static void C_ccall trf_3505(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3505(t0,t1,t2,t3);}

C_noret_decl(trf_3542)
static void C_ccall trf_3542(C_word c,C_word *av) C_noret;
static void C_ccall trf_3542(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3542(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3641)
static void C_ccall trf_3641(C_word c,C_word *av) C_noret;
static void C_ccall trf_3641(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3641(t0,t1);}

C_noret_decl(trf_3697)
static void C_ccall trf_3697(C_word c,C_word *av) C_noret;
static void C_ccall trf_3697(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3697(t0,t1,t2);}

C_noret_decl(trf_3936)
static void C_ccall trf_3936(C_word c,C_word *av) C_noret;
static void C_ccall trf_3936(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3936(t0,t1,t2);}

C_noret_decl(trf_3974)
static void C_ccall trf_3974(C_word c,C_word *av) C_noret;
static void C_ccall trf_3974(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3974(t0,t1,t2);}

C_noret_decl(trf_4092)
static void C_ccall trf_4092(C_word c,C_word *av) C_noret;
static void C_ccall trf_4092(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4092(t0,t1,t2,t3);}

C_noret_decl(trf_4131)
static void C_ccall trf_4131(C_word c,C_word *av) C_noret;
static void C_ccall trf_4131(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4131(t0,t1);}

C_noret_decl(trf_4137)
static void C_ccall trf_4137(C_word c,C_word *av) C_noret;
static void C_ccall trf_4137(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4137(t0,t1,t2,t3);}

C_noret_decl(trf_4188)
static void C_ccall trf_4188(C_word c,C_word *av) C_noret;
static void C_ccall trf_4188(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4188(t0,t1,t2);}

C_noret_decl(trf_4209)
static void C_ccall trf_4209(C_word c,C_word *av) C_noret;
static void C_ccall trf_4209(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4209(t0,t1);}

C_noret_decl(trf_4218)
static void C_ccall trf_4218(C_word c,C_word *av) C_noret;
static void C_ccall trf_4218(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4218(t0,t1,t2);}

C_noret_decl(trf_4243)
static void C_ccall trf_4243(C_word c,C_word *av) C_noret;
static void C_ccall trf_4243(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4243(t0,t1,t2);}

C_noret_decl(trf_4292)
static void C_ccall trf_4292(C_word c,C_word *av) C_noret;
static void C_ccall trf_4292(C_word c,C_word *av){
C_word t0=av[7];
C_word t1=av[6];
C_word t2=av[5];
C_word t3=av[4];
C_word t4=av[3];
C_word t5=av[2];
C_word t6=av[1];
C_word t7=av[0];
f_4292(t0,t1,t2,t3,t4,t5,t6,t7);}

C_noret_decl(trf_4344)
static void C_ccall trf_4344(C_word c,C_word *av) C_noret;
static void C_ccall trf_4344(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4344(t0,t1);}

C_noret_decl(trf_4381)
static void C_ccall trf_4381(C_word c,C_word *av) C_noret;
static void C_ccall trf_4381(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4381(t0,t1,t2);}

C_noret_decl(trf_4446)
static void C_ccall trf_4446(C_word c,C_word *av) C_noret;
static void C_ccall trf_4446(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_4446(t0,t1,t2,t3,t4);}

C_noret_decl(trf_4950)
static void C_ccall trf_4950(C_word c,C_word *av) C_noret;
static void C_ccall trf_4950(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4950(t0,t1);}

C_noret_decl(trf_4953)
static void C_ccall trf_4953(C_word c,C_word *av) C_noret;
static void C_ccall trf_4953(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4953(t0,t1);}

C_noret_decl(trf_5032)
static void C_ccall trf_5032(C_word c,C_word *av) C_noret;
static void C_ccall trf_5032(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5032(t0,t1);}

C_noret_decl(trf_5062)
static void C_ccall trf_5062(C_word c,C_word *av) C_noret;
static void C_ccall trf_5062(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5062(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5121)
static void C_ccall trf_5121(C_word c,C_word *av) C_noret;
static void C_ccall trf_5121(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5121(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5402)
static void C_ccall trf_5402(C_word c,C_word *av) C_noret;
static void C_ccall trf_5402(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5402(t0,t1,t2);}

C_noret_decl(trf_5490)
static void C_ccall trf_5490(C_word c,C_word *av) C_noret;
static void C_ccall trf_5490(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5490(t0,t1);}

C_noret_decl(trf_5565)
static void C_ccall trf_5565(C_word c,C_word *av) C_noret;
static void C_ccall trf_5565(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5565(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5712)
static void C_ccall trf_5712(C_word c,C_word *av) C_noret;
static void C_ccall trf_5712(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5712(t0,t1,t2,t3);}

C_noret_decl(trf_5853)
static void C_ccall trf_5853(C_word c,C_word *av) C_noret;
static void C_ccall trf_5853(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5853(t0,t1);}

C_noret_decl(trf_5890)
static void C_ccall trf_5890(C_word c,C_word *av) C_noret;
static void C_ccall trf_5890(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5890(t0,t1);}

C_noret_decl(trf_6070)
static void C_ccall trf_6070(C_word c,C_word *av) C_noret;
static void C_ccall trf_6070(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_6070(t0,t1,t2,t3,t4);}

C_noret_decl(trf_6420)
static void C_ccall trf_6420(C_word c,C_word *av) C_noret;
static void C_ccall trf_6420(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6420(t0,t1);}

C_noret_decl(trf_6493)
static void C_ccall trf_6493(C_word c,C_word *av) C_noret;
static void C_ccall trf_6493(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_6493(t0,t1,t2,t3,t4);}

C_noret_decl(trf_6596)
static void C_ccall trf_6596(C_word c,C_word *av) C_noret;
static void C_ccall trf_6596(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6596(t0,t1);}

C_noret_decl(trf_6631)
static void C_ccall trf_6631(C_word c,C_word *av) C_noret;
static void C_ccall trf_6631(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6631(t0,t1,t2,t3);}

C_noret_decl(trf_7144)
static void C_ccall trf_7144(C_word c,C_word *av) C_noret;
static void C_ccall trf_7144(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7144(t0,t1,t2);}

C_noret_decl(trf_7279)
static void C_ccall trf_7279(C_word c,C_word *av) C_noret;
static void C_ccall trf_7279(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_7279(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_7316)
static void C_ccall trf_7316(C_word c,C_word *av) C_noret;
static void C_ccall trf_7316(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7316(t0,t1);}

C_noret_decl(trf_7336)
static void C_ccall trf_7336(C_word c,C_word *av) C_noret;
static void C_ccall trf_7336(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7336(t0,t1,t2);}

C_noret_decl(trf_7348)
static void C_ccall trf_7348(C_word c,C_word *av) C_noret;
static void C_ccall trf_7348(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7348(t0,t1,t2,t3);}

C_noret_decl(trf_7377)
static void C_ccall trf_7377(C_word c,C_word *av) C_noret;
static void C_ccall trf_7377(C_word c,C_word *av){
C_word t0=av[7];
C_word t1=av[6];
C_word t2=av[5];
C_word t3=av[4];
C_word t4=av[3];
C_word t5=av[2];
C_word t6=av[1];
C_word t7=av[0];
f_7377(t0,t1,t2,t3,t4,t5,t6,t7);}

C_noret_decl(trf_7394)
static void C_ccall trf_7394(C_word c,C_word *av) C_noret;
static void C_ccall trf_7394(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7394(t0,t1);}

C_noret_decl(trf_7422)
static void C_ccall trf_7422(C_word c,C_word *av) C_noret;
static void C_ccall trf_7422(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_7422(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_7433)
static void C_ccall trf_7433(C_word c,C_word *av) C_noret;
static void C_ccall trf_7433(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_7433(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_7444)
static void C_ccall trf_7444(C_word c,C_word *av) C_noret;
static void C_ccall trf_7444(C_word c,C_word *av){
C_word t0=av[8];
C_word t1=av[7];
C_word t2=av[6];
C_word t3=av[5];
C_word t4=av[4];
C_word t5=av[3];
C_word t6=av[2];
C_word t7=av[1];
C_word t8=av[0];
f_7444(t0,t1,t2,t3,t4,t5,t6,t7,t8);}

C_noret_decl(trf_7500)
static void C_ccall trf_7500(C_word c,C_word *av) C_noret;
static void C_ccall trf_7500(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_7500(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_7502)
static void C_ccall trf_7502(C_word c,C_word *av) C_noret;
static void C_ccall trf_7502(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7502(t0,t1,t2);}

C_noret_decl(trf_7921)
static void C_ccall trf_7921(C_word c,C_word *av) C_noret;
static void C_ccall trf_7921(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7921(t0,t1,t2,t3);}

C_noret_decl(trva8871)
static void C_ccall trva8871(C_word c,C_word *av) C_noret;
static void C_ccall trva8871(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va8871(t0,t1);}

C_noret_decl(trva8873)
static void C_ccall trva8873(C_word c,C_word *av) C_noret;
static void C_ccall trva8873(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va8873(t0,t1);}

C_noret_decl(trva8875)
static void C_ccall trva8875(C_word c,C_word *av) C_noret;
static void C_ccall trva8875(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va8875(t0,t1);}

C_noret_decl(trva8877)
static void C_ccall trva8877(C_word c,C_word *av) C_noret;
static void C_ccall trva8877(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va8877(t0,t1);}

/* f8882 in chicken.time.posix#seconds->local-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f8882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f8882,c,av);}
/* posix-common.scm:585: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[258]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[258];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}

/* f8886 in chicken.time.posix#seconds->utc-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f8886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f8886,c,av);}
/* posix-common.scm:590: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[258]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[258];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
tp(4,av2);}}

/* f8930 in k7230 in chicken.process#process-run in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f8930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f8930,c,av);}
a=C_alloc(6);
t2=(C_truep(t1)?t1:lf[419]);
t3=C_a_i_list2(&a,2,lf[420],((C_word*)t0)[2]);
/* posixunix.scm:1149: chicken.process#process-execute */
t4=*((C_word*)lf[107]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* f8936 in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f8936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f8936,c,av);}
t2=(C_truep(t1)?t1:lf[419]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_7543(2,av2);}}

/* k2681 */
static void C_ccall f_2683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2683,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k2684 in k2681 */
static void C_ccall f_2686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2686,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2689,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k2687 in k2684 in k2681 */
static void C_ccall f_2689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2689,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2692,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2692,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2695,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lolevel_toplevel(2,av2);}}

/* k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_2695,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2698,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word t43;
C_word t44;
C_word t45;
C_word t46;
C_word t47;
C_word t48;
C_word t49;
C_word t50;
C_word t51;
C_word t52;
C_word t53;
C_word t54;
C_word t55;
C_word t56;
C_word t57;
C_word t58;
C_word t59;
C_word t60;
C_word t61;
C_word t62;
C_word t63;
C_word t64;
C_word t65;
C_word t66;
C_word t67;
C_word t68;
C_word t69;
C_word t70;
C_word t71;
C_word t72;
C_word t73;
C_word t74;
C_word t75;
C_word t76;
C_word t77;
C_word t78;
C_word t79;
C_word t80;
C_word t81;
C_word t82;
C_word t83;
C_word t84;
C_word t85;
C_word t86;
C_word t87;
C_word t88;
C_word t89;
C_word t90;
C_word t91;
C_word t92;
C_word t93;
C_word t94;
C_word t95;
C_word t96;
C_word t97;
C_word t98;
C_word t99;
C_word t100;
C_word t101;
C_word t102;
C_word t103;
C_word t104;
C_word t105;
C_word t106;
C_word t107;
C_word t108;
C_word t109;
C_word t110;
C_word t111;
C_word t112;
C_word t113;
C_word t114;
C_word t115;
C_word t116;
C_word t117;
C_word t118;
C_word t119;
C_word t120;
C_word t121;
C_word t122;
C_word t123;
C_word t124;
C_word t125;
C_word t126;
C_word t127;
C_word t128;
C_word t129;
C_word t130;
C_word t131;
C_word t132;
C_word t133;
C_word t134;
C_word t135;
C_word t136;
C_word t137;
C_word t138;
C_word t139;
C_word t140;
C_word t141;
C_word t142;
C_word t143;
C_word t144;
C_word t145;
C_word t146;
C_word t147;
C_word t148;
C_word t149;
C_word t150;
C_word t151;
C_word t152;
C_word t153;
C_word t154;
C_word t155;
C_word t156;
C_word t157;
C_word t158;
C_word t159;
C_word t160;
C_word t161;
C_word t162;
C_word t163;
C_word t164;
C_word t165;
C_word t166;
C_word t167;
C_word t168;
C_word t169;
C_word t170;
C_word t171;
C_word t172;
C_word t173;
C_word t174;
C_word t175;
C_word t176;
C_word t177;
C_word t178;
C_word t179;
C_word t180;
C_word t181;
C_word t182;
C_word t183;
C_word t184;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(88,c,6)))){
C_save_and_reclaim((void *)f_2698,c,av);}
a=C_alloc(88);
t2=C_set_block_item(lf[2] /* chicken.file.posix#create-fifo */,0,C_SCHEME_UNDEFINED);
t3=C_set_block_item(lf[3] /* chicken.file.posix#create-symbolic-link */,0,C_SCHEME_UNDEFINED);
t4=C_set_block_item(lf[4] /* chicken.file.posix#read-symbolic-link */,0,C_SCHEME_UNDEFINED);
t5=C_set_block_item(lf[5] /* chicken.file.posix#duplicate-fileno */,0,C_SCHEME_UNDEFINED);
t6=C_set_block_item(lf[6] /* chicken.file.posix#fcntl/dupfd */,0,C_SCHEME_UNDEFINED);
t7=C_set_block_item(lf[7] /* chicken.file.posix#fcntl/getfd */,0,C_SCHEME_UNDEFINED);
t8=C_set_block_item(lf[8] /* chicken.file.posix#fcntl/getfl */,0,C_SCHEME_UNDEFINED);
t9=C_set_block_item(lf[9] /* chicken.file.posix#fcntl/setfd */,0,C_SCHEME_UNDEFINED);
t10=C_set_block_item(lf[10] /* chicken.file.posix#fcntl/setfl */,0,C_SCHEME_UNDEFINED);
t11=C_set_block_item(lf[11] /* chicken.file.posix#file-close */,0,C_SCHEME_UNDEFINED);
t12=C_set_block_item(lf[12] /* chicken.file.posix#file-control */,0,C_SCHEME_UNDEFINED);
t13=C_set_block_item(lf[13] /* chicken.file.posix#file-creation-mode */,0,C_SCHEME_UNDEFINED);
t14=C_set_block_item(lf[14] /* chicken.file.posix#file-group */,0,C_SCHEME_UNDEFINED);
t15=C_set_block_item(lf[15] /* chicken.file.posix#file-link */,0,C_SCHEME_UNDEFINED);
t16=C_set_block_item(lf[16] /* chicken.file.posix#file-lock */,0,C_SCHEME_UNDEFINED);
t17=C_set_block_item(lf[17] /* chicken.file.posix#file-lock/blocking */,0,C_SCHEME_UNDEFINED);
t18=C_set_block_item(lf[18] /* chicken.file.posix#file-mkstemp */,0,C_SCHEME_UNDEFINED);
t19=C_set_block_item(lf[19] /* chicken.file.posix#file-open */,0,C_SCHEME_UNDEFINED);
t20=C_set_block_item(lf[20] /* chicken.file.posix#file-owner */,0,C_SCHEME_UNDEFINED);
t21=C_set_block_item(lf[21] /* chicken.file.posix#file-permissions */,0,C_SCHEME_UNDEFINED);
t22=C_set_block_item(lf[22] /* chicken.file.posix#file-position */,0,C_SCHEME_UNDEFINED);
t23=C_set_block_item(lf[23] /* chicken.file.posix#file-read */,0,C_SCHEME_UNDEFINED);
t24=C_set_block_item(lf[24] /* chicken.file.posix#file-select */,0,C_SCHEME_UNDEFINED);
t25=C_set_block_item(lf[25] /* chicken.file.posix#file-test-lock */,0,C_SCHEME_UNDEFINED);
t26=C_set_block_item(lf[26] /* chicken.file.posix#file-truncate */,0,C_SCHEME_UNDEFINED);
t27=C_set_block_item(lf[27] /* chicken.file.posix#file-unlock */,0,C_SCHEME_UNDEFINED);
t28=C_set_block_item(lf[28] /* chicken.file.posix#file-write */,0,C_SCHEME_UNDEFINED);
t29=C_set_block_item(lf[29] /* chicken.file.posix#file-type */,0,C_SCHEME_UNDEFINED);
t30=C_set_block_item(lf[30] /* chicken.file.posix#block-device? */,0,C_SCHEME_UNDEFINED);
t31=C_set_block_item(lf[31] /* chicken.file.posix#character-device? */,0,C_SCHEME_UNDEFINED);
t32=C_set_block_item(lf[32] /* chicken.file.posix#directory? */,0,C_SCHEME_UNDEFINED);
t33=C_set_block_item(lf[33] /* chicken.file.posix#fifo? */,0,C_SCHEME_UNDEFINED);
t34=C_set_block_item(lf[34] /* chicken.file.posix#regular-file? */,0,C_SCHEME_UNDEFINED);
t35=C_set_block_item(lf[35] /* chicken.file.posix#socket? */,0,C_SCHEME_UNDEFINED);
t36=C_set_block_item(lf[36] /* chicken.file.posix#symbolic-link? */,0,C_SCHEME_UNDEFINED);
t37=C_set_block_item(lf[37] /* chicken.file.posix#fileno/stderr */,0,C_SCHEME_UNDEFINED);
t38=C_set_block_item(lf[38] /* chicken.file.posix#fileno/stdin */,0,C_SCHEME_UNDEFINED);
t39=C_set_block_item(lf[39] /* chicken.file.posix#fileno/stdout */,0,C_SCHEME_UNDEFINED);
t40=C_set_block_item(lf[40] /* chicken.file.posix#open-input-file* */,0,C_SCHEME_UNDEFINED);
t41=C_set_block_item(lf[41] /* chicken.file.posix#open-output-file* */,0,C_SCHEME_UNDEFINED);
t42=C_set_block_item(lf[42] /* chicken.file.posix#open/append */,0,C_SCHEME_UNDEFINED);
t43=C_set_block_item(lf[43] /* chicken.file.posix#open/binary */,0,C_SCHEME_UNDEFINED);
t44=C_set_block_item(lf[44] /* chicken.file.posix#open/creat */,0,C_SCHEME_UNDEFINED);
t45=C_set_block_item(lf[45] /* chicken.file.posix#open/excl */,0,C_SCHEME_UNDEFINED);
t46=C_set_block_item(lf[46] /* chicken.file.posix#open/fsync */,0,C_SCHEME_UNDEFINED);
t47=C_set_block_item(lf[47] /* chicken.file.posix#open/noctty */,0,C_SCHEME_UNDEFINED);
t48=C_set_block_item(lf[48] /* chicken.file.posix#open/noinherit */,0,C_SCHEME_UNDEFINED);
t49=C_set_block_item(lf[49] /* chicken.file.posix#open/nonblock */,0,C_SCHEME_UNDEFINED);
t50=C_set_block_item(lf[50] /* chicken.file.posix#open/rdonly */,0,C_SCHEME_UNDEFINED);
t51=C_set_block_item(lf[51] /* chicken.file.posix#open/rdwr */,0,C_SCHEME_UNDEFINED);
t52=C_set_block_item(lf[52] /* chicken.file.posix#open/read */,0,C_SCHEME_UNDEFINED);
t53=C_set_block_item(lf[53] /* chicken.file.posix#open/sync */,0,C_SCHEME_UNDEFINED);
t54=C_set_block_item(lf[54] /* chicken.file.posix#open/text */,0,C_SCHEME_UNDEFINED);
t55=C_set_block_item(lf[55] /* chicken.file.posix#open/trunc */,0,C_SCHEME_UNDEFINED);
t56=C_set_block_item(lf[56] /* chicken.file.posix#open/write */,0,C_SCHEME_UNDEFINED);
t57=C_set_block_item(lf[57] /* chicken.file.posix#open/wronly */,0,C_SCHEME_UNDEFINED);
t58=C_set_block_item(lf[58] /* chicken.file.posix#perm/irgrp */,0,C_SCHEME_UNDEFINED);
t59=C_set_block_item(lf[59] /* chicken.file.posix#perm/iroth */,0,C_SCHEME_UNDEFINED);
t60=C_set_block_item(lf[60] /* chicken.file.posix#perm/irusr */,0,C_SCHEME_UNDEFINED);
t61=C_set_block_item(lf[61] /* chicken.file.posix#perm/irwxg */,0,C_SCHEME_UNDEFINED);
t62=C_set_block_item(lf[62] /* chicken.file.posix#perm/irwxo */,0,C_SCHEME_UNDEFINED);
t63=C_set_block_item(lf[63] /* chicken.file.posix#perm/irwxu */,0,C_SCHEME_UNDEFINED);
t64=C_set_block_item(lf[64] /* chicken.file.posix#perm/isgid */,0,C_SCHEME_UNDEFINED);
t65=C_set_block_item(lf[65] /* chicken.file.posix#perm/isuid */,0,C_SCHEME_UNDEFINED);
t66=C_set_block_item(lf[66] /* chicken.file.posix#perm/isvtx */,0,C_SCHEME_UNDEFINED);
t67=C_set_block_item(lf[67] /* chicken.file.posix#perm/iwgrp */,0,C_SCHEME_UNDEFINED);
t68=C_set_block_item(lf[68] /* chicken.file.posix#perm/iwoth */,0,C_SCHEME_UNDEFINED);
t69=C_set_block_item(lf[69] /* chicken.file.posix#perm/iwusr */,0,C_SCHEME_UNDEFINED);
t70=C_set_block_item(lf[70] /* chicken.file.posix#perm/ixgrp */,0,C_SCHEME_UNDEFINED);
t71=C_set_block_item(lf[71] /* chicken.file.posix#perm/ixoth */,0,C_SCHEME_UNDEFINED);
t72=C_set_block_item(lf[72] /* chicken.file.posix#perm/ixusr */,0,C_SCHEME_UNDEFINED);
t73=C_set_block_item(lf[73] /* chicken.file.posix#port->fileno */,0,C_SCHEME_UNDEFINED);
t74=C_set_block_item(lf[74] /* chicken.file.posix#seek/cur */,0,C_SCHEME_UNDEFINED);
t75=C_set_block_item(lf[75] /* chicken.file.posix#seek/end */,0,C_SCHEME_UNDEFINED);
t76=C_set_block_item(lf[76] /* chicken.file.posix#seek/set */,0,C_SCHEME_UNDEFINED);
t77=C_set_block_item(lf[77] /* chicken.file.posix#set-file-position! */,0,C_SCHEME_UNDEFINED);
t78=C_a_i_provide(&a,1,lf[78]);
t79=C_set_block_item(lf[79] /* chicken.time.posix#seconds->utc-time */,0,C_SCHEME_UNDEFINED);
t80=C_set_block_item(lf[80] /* chicken.time.posix#utc-time->seconds */,0,C_SCHEME_UNDEFINED);
t81=C_set_block_item(lf[81] /* chicken.time.posix#seconds->local-time */,0,C_SCHEME_UNDEFINED);
t82=C_set_block_item(lf[82] /* chicken.time.posix#seconds->string */,0,C_SCHEME_UNDEFINED);
t83=C_set_block_item(lf[83] /* chicken.time.posix#local-time->seconds */,0,C_SCHEME_UNDEFINED);
t84=C_set_block_item(lf[84] /* chicken.time.posix#string->time */,0,C_SCHEME_UNDEFINED);
t85=C_set_block_item(lf[85] /* chicken.time.posix#time->string */,0,C_SCHEME_UNDEFINED);
t86=C_set_block_item(lf[86] /* chicken.time.posix#local-timezone-abbreviation */,0,C_SCHEME_UNDEFINED);
t87=C_a_i_provide(&a,1,lf[87]);
t88=C_mutate((C_word*)lf[88]+1 /* (set! chicken.process#system ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2784,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t89=C_mutate((C_word*)lf[94]+1 /* (set! chicken.process#system* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2803,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t90=C_mutate((C_word*)lf[97]+1 /* (set! chicken.process#qs ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2819,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t91=C_set_block_item(lf[107] /* chicken.process#process-execute */,0,C_SCHEME_UNDEFINED);
t92=C_set_block_item(lf[108] /* chicken.process#process-fork */,0,C_SCHEME_UNDEFINED);
t93=C_set_block_item(lf[109] /* chicken.process#process-run */,0,C_SCHEME_UNDEFINED);
t94=C_set_block_item(lf[110] /* chicken.process#process-signal */,0,C_SCHEME_UNDEFINED);
t95=C_set_block_item(lf[111] /* chicken.process#process-spawn */,0,C_SCHEME_UNDEFINED);
t96=C_set_block_item(lf[112] /* chicken.process#process-wait */,0,C_SCHEME_UNDEFINED);
t97=C_set_block_item(lf[113] /* chicken.process#call-with-input-pipe */,0,C_SCHEME_UNDEFINED);
t98=C_set_block_item(lf[114] /* chicken.process#call-with-output-pipe */,0,C_SCHEME_UNDEFINED);
t99=C_set_block_item(lf[115] /* chicken.process#close-input-pipe */,0,C_SCHEME_UNDEFINED);
t100=C_set_block_item(lf[116] /* chicken.process#close-output-pipe */,0,C_SCHEME_UNDEFINED);
t101=C_set_block_item(lf[117] /* chicken.process#create-pipe */,0,C_SCHEME_UNDEFINED);
t102=C_set_block_item(lf[118] /* chicken.process#open-input-pipe */,0,C_SCHEME_UNDEFINED);
t103=C_set_block_item(lf[119] /* chicken.process#open-output-pipe */,0,C_SCHEME_UNDEFINED);
t104=C_set_block_item(lf[120] /* chicken.process#with-input-from-pipe */,0,C_SCHEME_UNDEFINED);
t105=C_set_block_item(lf[121] /* chicken.process#with-output-to-pipe */,0,C_SCHEME_UNDEFINED);
t106=C_set_block_item(lf[122] /* chicken.process#process */,0,C_SCHEME_UNDEFINED);
t107=C_set_block_item(lf[123] /* chicken.process#process* */,0,C_SCHEME_UNDEFINED);
t108=C_set_block_item(lf[124] /* chicken.process#process-sleep */,0,C_SCHEME_UNDEFINED);
t109=C_set_block_item(lf[125] /* chicken.process#pipe/buf */,0,C_SCHEME_UNDEFINED);
t110=C_set_block_item(lf[126] /* chicken.process#spawn/overlay */,0,C_SCHEME_UNDEFINED);
t111=C_set_block_item(lf[127] /* chicken.process#spawn/wait */,0,C_SCHEME_UNDEFINED);
t112=C_set_block_item(lf[128] /* chicken.process#spawn/nowait */,0,C_SCHEME_UNDEFINED);
t113=C_set_block_item(lf[129] /* chicken.process#spawn/nowaito */,0,C_SCHEME_UNDEFINED);
t114=C_set_block_item(lf[130] /* chicken.process#spawn/detach */,0,C_SCHEME_UNDEFINED);
t115=C_a_i_provide(&a,1,lf[131]);
t116=C_set_block_item(lf[132] /* chicken.process.signal#set-alarm! */,0,C_SCHEME_UNDEFINED);
t117=C_set_block_item(lf[133] /* chicken.process.signal#set-signal-handler! */,0,C_SCHEME_UNDEFINED);
t118=C_set_block_item(lf[134] /* chicken.process.signal#set-signal-mask! */,0,C_SCHEME_UNDEFINED);
t119=C_set_block_item(lf[135] /* chicken.process.signal#signal-handler */,0,C_SCHEME_UNDEFINED);
t120=C_set_block_item(lf[136] /* chicken.process.signal#make-signal-handler */,0,C_SCHEME_UNDEFINED);
t121=C_set_block_item(lf[137] /* chicken.process.signal#signal-ignore */,0,C_SCHEME_UNDEFINED);
t122=C_set_block_item(lf[138] /* chicken.process.signal#signal-default */,0,C_SCHEME_UNDEFINED);
t123=C_set_block_item(lf[139] /* chicken.process.signal#signal-mask */,0,C_SCHEME_UNDEFINED);
t124=C_set_block_item(lf[140] /* chicken.process.signal#signal-mask! */,0,C_SCHEME_UNDEFINED);
t125=C_set_block_item(lf[141] /* chicken.process.signal#signal-masked? */,0,C_SCHEME_UNDEFINED);
t126=C_set_block_item(lf[142] /* chicken.process.signal#signal-unmask! */,0,C_SCHEME_UNDEFINED);
t127=C_set_block_item(lf[143] /* chicken.process.signal#signal/abrt */,0,C_SCHEME_UNDEFINED);
t128=C_set_block_item(lf[144] /* chicken.process.signal#signal/alrm */,0,C_SCHEME_UNDEFINED);
t129=C_set_block_item(lf[145] /* chicken.process.signal#signal/break */,0,C_SCHEME_UNDEFINED);
t130=C_set_block_item(lf[146] /* chicken.process.signal#signal/bus */,0,C_SCHEME_UNDEFINED);
t131=C_set_block_item(lf[147] /* chicken.process.signal#signal/chld */,0,C_SCHEME_UNDEFINED);
t132=C_set_block_item(lf[148] /* chicken.process.signal#signal/cont */,0,C_SCHEME_UNDEFINED);
t133=C_set_block_item(lf[149] /* chicken.process.signal#signal/fpe */,0,C_SCHEME_UNDEFINED);
t134=C_set_block_item(lf[150] /* chicken.process.signal#signal/hup */,0,C_SCHEME_UNDEFINED);
t135=C_set_block_item(lf[151] /* chicken.process.signal#signal/ill */,0,C_SCHEME_UNDEFINED);
t136=C_set_block_item(lf[152] /* chicken.process.signal#signal/int */,0,C_SCHEME_UNDEFINED);
t137=C_set_block_item(lf[153] /* chicken.process.signal#signal/io */,0,C_SCHEME_UNDEFINED);
t138=C_set_block_item(lf[154] /* chicken.process.signal#signal/kill */,0,C_SCHEME_UNDEFINED);
t139=C_set_block_item(lf[155] /* chicken.process.signal#signal/pipe */,0,C_SCHEME_UNDEFINED);
t140=C_set_block_item(lf[156] /* chicken.process.signal#signal/prof */,0,C_SCHEME_UNDEFINED);
t141=C_set_block_item(lf[157] /* chicken.process.signal#signal/quit */,0,C_SCHEME_UNDEFINED);
t142=C_set_block_item(lf[158] /* chicken.process.signal#signal/segv */,0,C_SCHEME_UNDEFINED);
t143=C_set_block_item(lf[159] /* chicken.process.signal#signal/stop */,0,C_SCHEME_UNDEFINED);
t144=C_set_block_item(lf[160] /* chicken.process.signal#signal/term */,0,C_SCHEME_UNDEFINED);
t145=C_set_block_item(lf[161] /* chicken.process.signal#signal/trap */,0,C_SCHEME_UNDEFINED);
t146=C_set_block_item(lf[162] /* chicken.process.signal#signal/tstp */,0,C_SCHEME_UNDEFINED);
t147=C_set_block_item(lf[163] /* chicken.process.signal#signal/urg */,0,C_SCHEME_UNDEFINED);
t148=C_set_block_item(lf[164] /* chicken.process.signal#signal/usr1 */,0,C_SCHEME_UNDEFINED);
t149=C_set_block_item(lf[165] /* chicken.process.signal#signal/usr2 */,0,C_SCHEME_UNDEFINED);
t150=C_set_block_item(lf[166] /* chicken.process.signal#signal/vtalrm */,0,C_SCHEME_UNDEFINED);
t151=C_set_block_item(lf[167] /* chicken.process.signal#signal/winch */,0,C_SCHEME_UNDEFINED);
t152=C_set_block_item(lf[168] /* chicken.process.signal#signal/xcpu */,0,C_SCHEME_UNDEFINED);
t153=C_set_block_item(lf[169] /* chicken.process.signal#signal/xfsz */,0,C_SCHEME_UNDEFINED);
t154=C_set_block_item(lf[170] /* chicken.process.signal#signals-list */,0,C_SCHEME_UNDEFINED);
t155=C_a_i_provide(&a,1,lf[171]);
t156=C_set_block_item(lf[172] /* chicken.process-context.posix#change-directory* */,0,C_SCHEME_UNDEFINED);
t157=C_set_block_item(lf[173] /* chicken.process-context.posix#set-root-directory! */,0,C_SCHEME_UNDEFINED);
t158=C_set_block_item(lf[174] /* chicken.process-context.posix#current-effective-group-id */,0,C_SCHEME_UNDEFINED);
t159=C_set_block_item(lf[175] /* chicken.process-context.posix#current-effective-user-id */,0,C_SCHEME_UNDEFINED);
t160=C_set_block_item(lf[176] /* chicken.process-context.posix#current-group-id */,0,C_SCHEME_UNDEFINED);
t161=C_set_block_item(lf[177] /* chicken.process-context.posix#current-user-id */,0,C_SCHEME_UNDEFINED);
t162=C_set_block_item(lf[178] /* chicken.process-context.posix#current-process-id */,0,C_SCHEME_UNDEFINED);
t163=C_set_block_item(lf[179] /* chicken.process-context.posix#parent-process-id */,0,C_SCHEME_UNDEFINED);
t164=C_set_block_item(lf[180] /* chicken.process-context.posix#current-user-name */,0,C_SCHEME_UNDEFINED);
t165=C_set_block_item(lf[181] /* chicken.process-context.posix#current-effective-user-name */,0,C_SCHEME_UNDEFINED);
t166=C_set_block_item(lf[182] /* chicken.process-context.posix#create-session */,0,C_SCHEME_UNDEFINED);
t167=C_set_block_item(lf[183] /* chicken.process-context.posix#process-group-id */,0,C_SCHEME_UNDEFINED);
t168=C_set_block_item(lf[184] /* chicken.process-context.posix#user-information */,0,C_SCHEME_UNDEFINED);
t169=C_a_i_provide(&a,1,lf[185]);
t170=C_mutate(&lf[186] /* (set! chicken.posix#posix-error ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3009,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t171=C_mutate((C_word*)lf[189]+1 /* (set! ##sys#posix-error ...) */,lf[186]);
t172=C_mutate(&lf[190] /* (set! chicken.posix#stat ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3027,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t173=C_mutate((C_word*)lf[198]+1 /* (set! chicken.file.posix#file-stat ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3073,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t174=C_mutate((C_word*)lf[200]+1 /* (set! chicken.file.posix#set-file-permissions! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3091,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t175=C_mutate((C_word*)lf[206]+1 /* (set! chicken.file.posix#file-modification-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3135,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t176=C_mutate((C_word*)lf[208]+1 /* (set! chicken.file.posix#file-access-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3141,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t177=C_mutate((C_word*)lf[210]+1 /* (set! chicken.file.posix#file-change-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3147,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t178=C_mutate((C_word*)lf[212]+1 /* (set! chicken.file.posix#set-file-times! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3153,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t179=C_mutate((C_word*)lf[217]+1 /* (set! chicken.file.posix#file-size ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3232,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t180=C_mutate((C_word*)lf[219]+1 /* (set! chicken.file.posix#set-file-owner! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3238,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t181=C_mutate((C_word*)lf[222]+1 /* (set! chicken.file.posix#set-file-group! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3244,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t182=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3252,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t183=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8034,a[2]=((C_word)li229),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:313: chicken.base#getter-with-setter */
t184=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t184;
av2[1]=t182;
av2[2]=t183;
av2[3]=*((C_word*)lf[219]+1);
av2[4]=lf[507];
((C_proc)(void*)(*((C_word*)t184+1)))(5,av2);}}

/* chicken.process#system in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2784(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2784,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[89]);
t4=C_execute_shell_command(t2);
if(C_truep(C_fixnum_lessp(t4,C_fix(0)))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2801,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix.scm:203: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k2799 in chicken.process#system in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2801,c,av);}
/* posix.scm:202: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[90]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[90]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[91];
av2[3]=t1;
av2[4]=lf[89];
av2[5]=lf[92];
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}

/* chicken.process#system* in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2803,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2807,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix.scm:209: system */
t4=*((C_word*)lf[88]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k2805 in chicken.process#system* in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2807,c,av);}
t2=C_eqp(t1,C_fix(0));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* posix.scm:211: ##sys#error */
t3=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[96];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2819,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2823,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_rest_nullp(c,3))){
/* posix.scm:216: chicken.platform#software-version */
t4=*((C_word*)lf[106]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_get_rest_arg(c,3,av,3,t0);
f_2823(2,av2);}}}

/* k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2823(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_2823,c,av);}
a=C_alloc(18);
t2=C_eqp(t1,lf[98]);
t3=(C_truep(t2)?C_make_character(34):C_make_character(39));
t4=C_eqp(t1,lf[98]);
t5=(C_truep(t4)?lf[99]:lf[100]);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2833,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=((C_word)li2),tmp=(C_word)a,a+=6,tmp);
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2854,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t8,a[5]=t10,a[6]=t9,tmp=(C_word)a,a+=7,tmp);
/* ##sys#string->list */
t12=*((C_word*)lf[105]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t12;
av2[1]=t11;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}

/* g260 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_2833(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,0,4)))){
C_save_and_reclaim_args((void *)trf_2833,3,t0,t1,t2);}
a=C_alloc(2);
if(C_truep(C_i_char_equalp(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_u_i_char_equalp(t2,C_make_character(0)))){
/* posix.scm:224: chicken.base#error */
t3=*((C_word*)lf[101]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[102];
av2[3]=lf[103];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_a_i_string(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* k2852 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_2854,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2857,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2874,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li3),tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_2874(t6,t2,t1);}

/* k2855 in k2852 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2857,c,av);}
a=C_alloc(7);
t2=C_a_i_string(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2868,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[104]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* k2866 in k2855 in k2852 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_2868,c,av);}
a=C_alloc(2);
t2=C_a_i_string(&a,1,((C_word*)t0)[2]);
/* posix.scm:227: scheme#string-append */
t3=*((C_word*)lf[104]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* map-loop254 in k2852 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_2874(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2874,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2899,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posix.scm:220: g260 */
t4=((C_word*)t0)[4];
f_2833(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2897 in map-loop254 in k2852 in k2821 in chicken.process#qs in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_2899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2899,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_2874(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* chicken.posix#posix-error in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-5)*C_SIZEOF_PAIR +7,c,2)))){
C_save_and_reclaim((void*)f_3009,c,av);}
a=C_alloc((c-5)*C_SIZEOF_PAIR+7);
t5=C_build_rest(&a,c,5,av);
C_word t6;
C_word t7;
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3013,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t5,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:191: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t6;
tp(2,av2);}}

/* k3011 in chicken.posix#posix-error in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_3013,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3020,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3024,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t1);
/* posix-common.scm:188: ##sys#peek-c-string */
t6=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=stub655(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k3018 in k3011 in chicken.posix#posix-error in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_3020,c,av);}{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[90]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=t1;
av2[7]=((C_word*)t0)[6];
C_apply(8,av2);}}

/* k3022 in k3011 in chicken.posix#posix-error in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3024,c,av);}
/* posix-common.scm:193: string-append */
t2=*((C_word*)lf[104]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[187];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.posix#stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3027(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_3027,5,t1,t2,t3,t4,t5);}
a=C_alloc(12);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3031,a[2]=t4,a[3]=t1,a[4]=t5,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnump(t2))){
t7=t6;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_u_i_fstat(t2);
f_3031(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3052,a[2]=t6,a[3]=t2,a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:236: chicken.base#port? */
t8=*((C_word*)lf[197]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}

/* k3029 in chicken.posix#stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3031,c,av);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
if(C_truep(((C_word*)t0)[2])){
/* posix-common.scm:247: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[192];
av2[5]=((C_word*)t0)[5];
f_3009(6,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3050 in chicken.posix#stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3052,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3056,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:236: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3065,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:238: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}
else{
/* posix-common.scm:243: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[195];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[196];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k3054 in k3050 in chicken.posix#stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3056,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_u_i_fstat(t1);
f_3031(2,av2);}}

/* k3063 in k3050 in chicken.posix#stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3065,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(((C_word*)t0)[3])?C_u_i_lstat(t1):C_u_i_stat(t1));
f_3031(2,av2);}}

/* chicken.file.posix#file-stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3073,c,av);}
a=C_alloc(3);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3080,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:253: stat */
f_3027(t5,t2,t4,C_SCHEME_TRUE,lf[199]);}

/* k3078 in chicken.file.posix#file-stat in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_3080,c,av);}
a=C_alloc(42);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_vector(&a,13,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_ino),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_mode),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_nlink),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_uid),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_gid),C_int64_to_num(&a,C_statbuf.st_size),C_int64_to_num(&a,C_statbuf.st_atime),C_int64_to_num(&a,C_statbuf.st_ctime),C_int64_to_num(&a,C_statbuf.st_mtime),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_dev),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_rdev),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_blksize),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_blocks));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3091(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3091,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3095,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:262: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[201];
tp(4,av2);}}

/* k3093 in chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3095,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3098,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnump(((C_word*)t0)[3]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_fchmod(((C_word*)t0)[3],((C_word*)t0)[4]);
f_3098(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3116,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:264: chicken.base#port? */
t4=*((C_word*)lf[197]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3096 in k3093 in chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3098(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_3098,c,av);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
/* posix-common.scm:273: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=lf[201];
av2[4]=lf[202];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
f_3009(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3114 in k3093 in chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3116,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3120,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:264: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[4]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3130,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:267: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[201];
tp(4,av2);}}
else{
/* posix-common.scm:269: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[195];
av2[3]=lf[203];
av2[4]=lf[204];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k3118 in k3114 in k3093 in chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3120,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fchmod(t1,((C_word*)t0)[3]);
f_3098(2,av2);}}

/* k3128 in k3114 in k3093 in chicken.file.posix#set-file-permissions! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3130(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3130,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_chmod(t1,((C_word*)t0)[3]);
f_3098(2,av2);}}

/* chicken.file.posix#file-modification-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3135,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3139,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:277: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[207]);}

/* k3137 in chicken.file.posix#file-modification-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3139(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3139,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_mtime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-access-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3141,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3145,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:281: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[209]);}

/* k3143 in chicken.file.posix#file-access-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3145(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3145,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_atime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-change-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3147,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3151,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:285: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[211]);}

/* k3149 in chicken.file.posix#file-change-time in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3151,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_ctime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_3153,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3157,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* posix-common.scm:290: chicken.time#current-seconds */
t5=*((C_word*)lf[216]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_car(t3);
f_3157(2,av2);}}}

/* k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3157,c,av);}
a=C_alloc(7);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?t1:C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3169,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t1)){
/* posix-common.scm:291: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t8;
av2[2]=t1;
av2[3]=lf[213];
tp(4,av2);}}
else{
t9=t8;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
f_3169(2,av2);}}}

/* k3167 in k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3169,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3172,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[6])){
/* posix-common.scm:292: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[213];
tp(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_3172(2,av2);}}}

/* k3170 in k3167 in k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3172(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3172,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3188,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3178,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
/* posix-common.scm:293: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t3;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[3]);
tp(3,av2);}}
else{
t4=t2;
f_3188(t4,stub729(C_SCHEME_UNDEFINED,C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6]));}}

/* k3176 in k3170 in k3167 in k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3178,c,av);}
t2=((C_word*)t0)[2];
f_3188(t2,stub729(C_SCHEME_UNDEFINED,t1,((C_word*)t0)[3],((C_word*)t0)[4]));}

/* k3186 in k3170 in k3167 in k3155 in chicken.file.posix#set-file-times! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3188(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_3188,2,t0,t1);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){{
C_word av2[8];
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[186];
av2[3]=lf[191];
av2[4]=lf[213];
av2[5]=lf[214];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[4];
C_apply(8,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.file.posix#file-size in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3232,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3236,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:302: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[218]);}

/* k3234 in chicken.file.posix#file-size in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3236(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3236,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_size);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-owner! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3238(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3238,c,av);}
/* posix-common.scm:306: chown */
f_5565(t1,lf[221],t2,t3,C_fix(-1));}

/* chicken.file.posix#set-file-group! in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3244,c,av);}
/* posix-common.scm:310: chown */
f_5565(t1,lf[223],t2,C_fix(-1),t3);}

/* k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3252(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3252,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[20]+1 /* (set! chicken.file.posix#file-owner ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3256,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8028,a[2]=((C_word)li228),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:319: chicken.base#getter-with-setter */
t5=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[222]+1);
av2[4]=lf[505];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3256,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[14]+1 /* (set! chicken.file.posix#file-group ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3260,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8022,a[2]=((C_word)li227),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:325: chicken.base#getter-with-setter */
t5=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[200]+1);
av2[4]=lf[503];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,4)))){
C_save_and_reclaim((void *)f_3260,c,av);}
a=C_alloc(33);
t2=C_mutate((C_word*)lf[21]+1 /* (set! chicken.file.posix#file-permissions ...) */,t1);
t3=C_mutate((C_word*)lf[29]+1 /* (set! chicken.file.posix#file-type ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3262,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[34]+1 /* (set! chicken.file.posix#regular-file? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3349,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[36]+1 /* (set! chicken.file.posix#symbolic-link? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3359,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[30]+1 /* (set! chicken.file.posix#block-device? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3369,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[31]+1 /* (set! chicken.file.posix#character-device? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3379,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[33]+1 /* (set! chicken.file.posix#fifo? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3389,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[35]+1 /* (set! chicken.file.posix#socket? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3399,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[32]+1 /* (set! chicken.file.posix#directory? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3409,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp));
t11=C_set_block_item(lf[76] /* chicken.file.posix#seek/set */,0,C_fix((C_word)SEEK_SET));
t12=C_set_block_item(lf[75] /* chicken.file.posix#seek/end */,0,C_fix((C_word)SEEK_END));
t13=C_set_block_item(lf[74] /* chicken.file.posix#seek/cur */,0,C_fix((C_word)SEEK_CUR));
t14=C_mutate((C_word*)lf[77]+1 /* (set! chicken.file.posix#set-file-position! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3422,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3477,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t16=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7985,a[2]=((C_word)li226),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:402: chicken.base#getter-with-setter */
t17=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t17;
av2[1]=t15;
av2[2]=t16;
av2[3]=*((C_word*)lf[77]+1);
av2[4]=lf[502];
((C_proc)(void*)(*((C_word*)t17+1)))(5,av2);}}

/* chicken.file.posix#file-type in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3262,c,av);}
a=C_alloc(3);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_TRUE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3281,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:334: stat */
f_3027(t9,t2,t4,t7,lf[231]);}

/* k3279 in chicken.file.posix#file-type in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3281,c,av);}
if(C_truep(t1)){
t2=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_stat_type);
t3=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFREG));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=lf[224];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFLNK));
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[225];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFDIR));
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=lf[226];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFCHR));
if(C_truep(t6)){
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[227];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFBLK));
if(C_truep(t7)){
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=lf[228];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFIFO));
if(C_truep(t8)){
t9=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t9;
av2[1]=lf[229];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFSOCK));
t10=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t10;
av2[1]=(C_truep(t9)?lf[230]:lf[224]);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}}}}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file.posix#regular-file? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3349(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3349,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3357,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:348: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3355 in chicken.file.posix#regular-file? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3357(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3357,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[224],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#symbolic-link? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3359,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3367,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:352: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3365 in chicken.file.posix#symbolic-link? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3367(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3367,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[225],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#block-device? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3369(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3369,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3377,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:356: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3375 in chicken.file.posix#block-device? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3377,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[228],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#character-device? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3379,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3387,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:360: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3385 in chicken.file.posix#character-device? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3387,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[227],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#fifo? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3389,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3397,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:364: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3395 in chicken.file.posix#fifo? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3397,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[229],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#socket? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3399,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3407,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:368: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3405 in chicken.file.posix#socket? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3407,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[230],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#directory? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3409,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3417,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:372: chicken.file.posix#file-type */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3415 in chicken.file.posix#directory? in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3417,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[226],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-position! in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_3422,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_get_rest_arg(c,4,av,4,t0):C_fix((C_word)SEEK_SET));
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3429,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:388: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t7;
av2[2]=t3;
av2[3]=lf[232];
tp(4,av2);}}

/* k3427 in chicken.file.posix#set-file-position! in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3429(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3429,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3432,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:389: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[232];
tp(4,av2);}}

/* k3430 in k3427 in chicken.file.posix#set-file-position! in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3432(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3432,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3438,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3444,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:390: chicken.base#port? */
t4=*((C_word*)lf[197]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3436 in k3430 in k3427 in chicken.file.posix#set-file-position! in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_3438,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* posix-common.scm:399: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=lf[232];
av2[4]=lf[233];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
f_3009(7,av2);}}}

/* k3442 in k3430 in k3427 in chicken.file.posix#set-file-position! in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3444,c,av);}
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(7));
t3=C_eqp(t2,lf[234]);
if(C_truep(t3)){
t4=C_fseek(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
if(C_truep(t4)){
t5=C_i_set_i_slot(((C_word*)t0)[2],C_fix(6),C_SCHEME_FALSE);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t4;
f_3438(2,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_3438(2,av2);}}}
else{
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_3438(2,av2);}}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_lseek(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
f_3438(2,av2);}}
else{
/* posix-common.scm:398: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[195];
av2[3]=lf[232];
av2[4]=lf[235];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word t43;
C_word t44;
C_word t45;
C_word t46;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(45,c,6)))){
C_save_and_reclaim((void *)f_3477,c,av);}
a=C_alloc(45);
t2=C_mutate((C_word*)lf[22]+1 /* (set! chicken.file.posix#file-position ...) */,t1);
t3=C_set_block_item(lf[38] /* chicken.file.posix#fileno/stdin */,0,C_fix((C_word)STDIN_FILENO));
t4=C_set_block_item(lf[39] /* chicken.file.posix#fileno/stdout */,0,C_fix((C_word)STDOUT_FILENO));
t5=C_set_block_item(lf[37] /* chicken.file.posix#fileno/stderr */,0,C_fix((C_word)STDERR_FILENO));
t6=C_set_block_item(lf[50] /* chicken.file.posix#open/rdonly */,0,C_fix((C_word)O_RDONLY));
t7=C_set_block_item(lf[57] /* chicken.file.posix#open/wronly */,0,C_fix((C_word)O_WRONLY));
t8=C_set_block_item(lf[51] /* chicken.file.posix#open/rdwr */,0,C_fix((C_word)O_RDWR));
t9=C_set_block_item(lf[52] /* chicken.file.posix#open/read */,0,C_fix((C_word)O_RDONLY));
t10=C_set_block_item(lf[56] /* chicken.file.posix#open/write */,0,C_fix((C_word)O_WRONLY));
t11=C_set_block_item(lf[44] /* chicken.file.posix#open/creat */,0,C_fix((C_word)O_CREAT));
t12=C_set_block_item(lf[42] /* chicken.file.posix#open/append */,0,C_fix((C_word)O_APPEND));
t13=C_set_block_item(lf[45] /* chicken.file.posix#open/excl */,0,C_fix((C_word)O_EXCL));
t14=C_set_block_item(lf[55] /* chicken.file.posix#open/trunc */,0,C_fix((C_word)O_TRUNC));
t15=C_set_block_item(lf[43] /* chicken.file.posix#open/binary */,0,C_fix((C_word)O_BINARY));
t16=C_set_block_item(lf[54] /* chicken.file.posix#open/text */,0,C_fix((C_word)O_TEXT));
t17=C_set_block_item(lf[60] /* chicken.file.posix#perm/irusr */,0,C_fix((C_word)S_IRUSR));
t18=C_set_block_item(lf[69] /* chicken.file.posix#perm/iwusr */,0,C_fix((C_word)S_IWUSR));
t19=C_set_block_item(lf[72] /* chicken.file.posix#perm/ixusr */,0,C_fix((C_word)S_IXUSR));
t20=C_set_block_item(lf[58] /* chicken.file.posix#perm/irgrp */,0,C_fix((C_word)S_IRGRP));
t21=C_set_block_item(lf[67] /* chicken.file.posix#perm/iwgrp */,0,C_fix((C_word)S_IWGRP));
t22=C_set_block_item(lf[70] /* chicken.file.posix#perm/ixgrp */,0,C_fix((C_word)S_IXGRP));
t23=C_set_block_item(lf[59] /* chicken.file.posix#perm/iroth */,0,C_fix((C_word)S_IROTH));
t24=C_set_block_item(lf[68] /* chicken.file.posix#perm/iwoth */,0,C_fix((C_word)S_IWOTH));
t25=C_set_block_item(lf[71] /* chicken.file.posix#perm/ixoth */,0,C_fix((C_word)S_IXOTH));
t26=C_set_block_item(lf[63] /* chicken.file.posix#perm/irwxu */,0,C_fix((C_word)S_IRUSR | S_IWUSR | S_IXUSR));
t27=C_set_block_item(lf[61] /* chicken.file.posix#perm/irwxg */,0,C_fix((C_word)S_IRGRP | S_IWGRP | S_IXGRP));
t28=C_set_block_item(lf[62] /* chicken.file.posix#perm/irwxo */,0,C_fix((C_word)S_IROTH | S_IWOTH | S_IXOTH));
t29=C_SCHEME_UNDEFINED;
t30=(*a=C_VECTOR_TYPE|1,a[1]=t29,tmp=(C_word)a,a+=2,tmp);
t31=C_SCHEME_UNDEFINED;
t32=(*a=C_VECTOR_TYPE|1,a[1]=t31,tmp=(C_word)a,a+=2,tmp);
t33=C_set_block_item(t30,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3505,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp));
t34=C_set_block_item(t32,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3542,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp));
t35=C_mutate((C_word*)lf[40]+1 /* (set! chicken.file.posix#open-input-file* ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3561,a[2]=t32,a[3]=t30,a[4]=((C_word)li27),tmp=(C_word)a,a+=5,tmp));
t36=C_mutate((C_word*)lf[41]+1 /* (set! chicken.file.posix#open-output-file* ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3575,a[2]=t32,a[3]=t30,a[4]=((C_word)li28),tmp=(C_word)a,a+=5,tmp));
t37=C_mutate((C_word*)lf[73]+1 /* (set! chicken.file.posix#port->fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3589,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[5]+1 /* (set! chicken.file.posix#duplicate-fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3634,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[178]+1 /* (set! chicken.process-context.posix#current-process-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3661,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t40=C_mutate((C_word*)lf[172]+1 /* (set! chicken.process-context.posix#change-directory* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3664,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp));
t41=*((C_word*)lf[257]+1);
t42=C_mutate((C_word*)lf[257]+1 /* (set! ##sys#change-directory-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3680,a[2]=t41,a[3]=((C_word)li33),tmp=(C_word)a,a+=4,tmp));
t43=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3694,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t44=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7954,a[2]=((C_word)li224),tmp=(C_word)a,a+=3,tmp);
t45=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7979,a[2]=((C_word)li225),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:561: chicken.base#getter-with-setter */
t46=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t46;
av2[1]=t43;
av2[2]=t44;
av2[3]=t45;
av2[4]=lf[498];
((C_proc)(void*)(*((C_word*)t46+1)))(5,av2);}}

/* mode in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3505(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_3505,4,t1,t2,t3,t4);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3513,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(t3))){
t6=C_u_i_car(t3);
t7=C_eqp(t6,lf[236]);
if(C_truep(t7)){
if(C_truep(C_i_not(t2))){
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t1;
av2[2]=lf[237];
av2[3]=t4;
tp(4,av2);}}
else{
/* posix-common.scm:487: ##sys#error */
t8=*((C_word*)lf[95]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[238];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
/* posix-common.scm:488: ##sys#error */
t8=*((C_word*)lf[95]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[239];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
if(C_truep(t2)){
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t1;
av2[2]=lf[240];
av2[3]=t4;
tp(4,av2);}}
else{
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t1;
av2[2]=lf[241];
av2[3]=t4;
tp(4,av2);}}}}

/* k3511 in mode in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3513,c,av);}
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* check in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3542(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_3542,5,t1,t2,t3,t4,t5);}
a=C_alloc(4);
if(C_truep(C_null_pointerp(t5))){
/* posix-common.scm:494: posix-error */
t6=lf[186];{
C_word av2[6];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[191];
av2[3]=t2;
av2[4]=lf[242];
av2[5]=t3;
f_3009(6,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3555,a[2]=t5,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* posix-common.scm:495: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[243]+1);
av2[1]=t6;
av2[2]=C_fix(1);
av2[3]=*((C_word*)lf[244]+1);
av2[4]=lf[245];
av2[5]=lf[234];
tp(6,av2);}}
else{
/* posix-common.scm:495: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[243]+1);
av2[1]=t6;
av2[2]=C_fix(2);
av2[3]=*((C_word*)lf[244]+1);
av2[4]=lf[245];
av2[5]=lf[234];
tp(6,av2);}}}}

/* k3553 in check in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3555,c,av);}
t2=C_set_file_ptr(t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.file.posix#open-input-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3561(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +7,c,3)))){
C_save_and_reclaim((void*)f_3561,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+7);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3565,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:500: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[246];
tp(4,av2);}}

/* k3563 in chicken.file.posix#open-input-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3565,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3573,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:501: mode */
f_3505(t2,C_SCHEME_TRUE,((C_word*)t0)[6],lf[246]);}

/* k3571 in k3563 in chicken.file.posix#open-input-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3573(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_3573,c,av);}
a=C_alloc(2);
t2=C_fdopen(&a,2,((C_word*)t0)[2],t1);
/* posix-common.scm:501: check */
f_3542(((C_word*)t0)[4],lf[246],((C_word*)t0)[2],C_SCHEME_TRUE,t2);}

/* chicken.file.posix#open-output-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +7,c,3)))){
C_save_and_reclaim((void*)f_3575,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+7);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3579,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:504: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[247];
tp(4,av2);}}

/* k3577 in chicken.file.posix#open-output-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3579,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3587,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:505: mode */
f_3505(t2,C_SCHEME_FALSE,((C_word*)t0)[6],lf[247]);}

/* k3585 in k3577 in chicken.file.posix#open-output-file* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_3587,c,av);}
a=C_alloc(2);
t2=C_fdopen(&a,2,((C_word*)t0)[2],t1);
/* posix-common.scm:505: check */
f_3542(((C_word*)t0)[4],lf[247],((C_word*)t0)[2],C_SCHEME_FALSE,t2);}

/* chicken.file.posix#port->fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3589(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3589,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[248]);
t4=C_slot(t2,C_fix(7));
t5=C_eqp(lf[230],t4);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3605,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:515: ##sys#port-data */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[249]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[249]+1);
av2[1]=t6;
av2[2]=t2;
tp(3,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3628,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:516: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[252]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[252]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=C_fix(0);
tp(4,av2);}}}

/* k3603 in chicken.file.posix#port->fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3605,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(t1,C_fix(0));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3612 in k3626 in chicken.file.posix#port->fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3614,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3626 in chicken.file.posix#port->fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3628,c,av);}
a=C_alloc(4);
if(C_truep(C_i_not(C_i_zerop(t1)))){
t2=C_port_fileno(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3614,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t2,C_fix(0)))){
/* posix-common.scm:519: posix-error */
t4=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[191];
av2[3]=lf[248];
av2[4]=lf[250];
av2[5]=((C_word*)t0)[2];
f_3009(6,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
/* posix-common.scm:521: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[195];
av2[3]=lf[248];
av2[4]=lf[251];
av2[5]=((C_word*)t0)[2];
f_3009(6,av2);}}}

/* chicken.file.posix#duplicate-fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_3634,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3638,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:525: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[253];
tp(4,av2);}}

/* k3636 in chicken.file.posix#duplicate-fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3638,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3641,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
t3=t2;
f_3641(t3,C_dup(((C_word*)t0)[3]));}
else{
t3=C_i_car(((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3659,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:529: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[253];
tp(4,av2);}}}

/* k3639 in k3636 in chicken.file.posix#duplicate-fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3641(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_3641,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3644,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
/* posix-common.scm:532: posix-error */
t3=lf[186];{
C_word av2[6];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=lf[253];
av2[4]=lf[254];
av2[5]=((C_word*)t0)[3];
f_3009(6,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3642 in k3639 in k3636 in chicken.file.posix#duplicate-fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3644,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3657 in k3636 in chicken.file.posix#duplicate-fileno in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3659,c,av);}
t2=((C_word*)t0)[2];
f_3641(t2,C_dup2(((C_word*)t0)[3],((C_word*)t0)[4]));}

/* chicken.process-context.posix#current-process-id in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3661,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub848(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process-context.posix#change-directory* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3664(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3664,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3668,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:546: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[255];
tp(4,av2);}}

/* k3666 in chicken.process-context.posix#change-directory* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3668,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3671,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_eqp(C_fix(0),C_fchdir(((C_word*)t0)[3]));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* posix-common.scm:548: posix-error */
t4=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=lf[255];
av2[4]=lf[256];
av2[5]=((C_word*)t0)[3];
f_3009(6,av2);}}}

/* k3669 in k3666 in chicken.process-context.posix#change-directory* in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3671,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#change-directory-hook in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3680,c,av);}
if(C_truep(C_fixnump(t2))){
t3=*((C_word*)lf[172]+1);
t4=*((C_word*)lf[172]+1);
/* posix-common.scm:553: g855 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[172]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[172]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}
else{
/* posix-common.scm:553: g855 */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,4)))){
C_save_and_reclaim((void *)f_3694,c,av);}
a=C_alloc(32);
t2=C_mutate((C_word*)lf[13]+1 /* (set! chicken.file.posix#file-creation-mode ...) */,t1);
t3=C_mutate(&lf[258] /* (set! chicken.posix#decode-seconds ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)C_decode_seconds,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate(&lf[259] /* (set! chicken.posix#check-time-vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3697,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[81]+1 /* (set! chicken.time.posix#seconds->local-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3716,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[79]+1 /* (set! chicken.time.posix#seconds->utc-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3737,a[2]=((C_word)li37),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[82]+1 /* (set! chicken.time.posix#seconds->string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3769,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t8=C_fix((C_word)sizeof(struct tm));
t9=C_mutate((C_word*)lf[83]+1 /* (set! chicken.time.posix#local-time->seconds ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3807,a[2]=t8,a[3]=((C_word)li39),tmp=(C_word)a,a+=4,tmp));
t10=C_fix((C_word)sizeof(struct tm));
t11=C_mutate((C_word*)lf[85]+1 /* (set! chicken.time.posix#time->string ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3852,a[2]=t10,a[3]=((C_word)li40),tmp=(C_word)a,a+=4,tmp));
t12=C_mutate((C_word*)lf[133]+1 /* (set! chicken.process.signal#set-signal-handler! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3914,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp));
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3929,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7945,a[2]=((C_word)li223),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:636: chicken.base#getter-with-setter */
t15=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t15;
av2[1]=t13;
av2[2]=t14;
av2[3]=*((C_word*)lf[133]+1);
av2[4]=lf[496];
((C_proc)(void*)(*((C_word*)t15+1)))(5,av2);}}

/* chicken.posix#check-time-vector in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3697(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3697,3,t1,t2,t3);}
t4=C_i_check_vector_2(t3,t2);
t5=C_block_size(t3);
if(C_truep(C_fixnum_lessp(t5,C_fix(10)))){
/* posix-common.scm:580: ##sys#error */
t6=*((C_word*)lf[95]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[260];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* chicken.time.posix#seconds->local-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3716,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3720,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:583: chicken.time#current-seconds */
t3=*((C_word*)lf[216]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_get_rest_arg(c,2,av,2,t0);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8882,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:584: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[261];
tp(4,av2);}}}

/* k3718 in chicken.time.posix#seconds->local-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3720,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3723,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:584: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[261];
tp(4,av2);}}

/* k3721 in k3718 in chicken.time.posix#seconds->local-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3723,c,av);}
/* posix-common.scm:585: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[258]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[258];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}

/* chicken.time.posix#seconds->utc-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3737,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3741,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:588: chicken.time#current-seconds */
t3=*((C_word*)lf[216]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_get_rest_arg(c,2,av,2,t0);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8886,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:589: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[262];
tp(4,av2);}}}

/* k3739 in chicken.time.posix#seconds->utc-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3741,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3744,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:589: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[262];
tp(4,av2);}}

/* k3742 in k3739 in chicken.time.posix#seconds->utc-time in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3744,c,av);}
/* posix-common.scm:590: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[258]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[258];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
tp(4,av2);}}

/* chicken.time.posix#seconds->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3769(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3769,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3773,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:594: chicken.time#current-seconds */
t3=*((C_word*)lf[216]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_get_rest_arg(c,2,av,2,t0);
f_3773(2,av2);}}}

/* k3771 in chicken.time.posix#seconds->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3773,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3776,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:595: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[264];
tp(4,av2);}}

/* k3774 in k3771 in chicken.time.posix#seconds->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3776,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3779,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_fix((C_word)sizeof(int) * CHAR_BIT);
t5=C_i_foreign_ranged_integer_argumentp(((C_word*)t0)[3],t4);
/* posix-common.scm:593: ##sys#peek-c-string */
t6=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub904(t3,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k3777 in k3774 in k3771 in chicken.time.posix#seconds->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3779,c,av);}
if(C_truep(t1)){
t2=C_block_size(t1);
/* posix-common.scm:598: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[263]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[263]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t2,C_fix(1));
tp(5,av2);}}
else{
/* posix-common.scm:599: ##sys#error */
t2=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[264];
av2[3]=lf[265];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* chicken.time.posix#local-time->seconds in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3807,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3811,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:604: check-time-vector */
f_3697(t3,lf[266],t2);}

/* k3809 in chicken.time.posix#local-time->seconds in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3811(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3811,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3815,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:605: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k3813 in k3809 in chicken.time.posix#local-time->seconds in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3815,c,av);}
a=C_alloc(7);
t2=C_a_mktime(&a,2,((C_word*)t0)[2],t1);
if(C_truep(C_i_nequalp(C_fix(-1),t2))){
/* posix-common.scm:607: ##sys#error */
t3=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[266];
av2[3]=lf[267];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3852,c,av);}
a=C_alloc(6);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3859,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:615: check-time-vector */
f_3697(t5,lf[269],t2);}

/* k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3859,c,av);}
a=C_alloc(9);
if(C_truep(((C_word*)t0)[2])){
t2=C_i_check_string_2(((C_word*)t0)[2],lf[269]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3868,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3878,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:619: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[269];
tp(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3885,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3906,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:621: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_make_character(0);
tp(4,av2);}}}

/* k3866 in k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3868,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* posix-common.scm:620: ##sys#error */
t2=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[269];
av2[3]=lf[270];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k3876 in k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3878,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3882,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:619: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k3880 in k3876 in k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3882,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
if(C_truep(t1)){
t3=C_i_foreign_block_argumentp(t1);
/* posix-common.scm:612: ##sys#peek-c-string */
t4=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=stub941(t2,((C_word*)t0)[3],((C_word*)t0)[4],t3);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* posix-common.scm:612: ##sys#peek-c-string */
t3=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=stub941(t2,((C_word*)t0)[3],((C_word*)t0)[4],C_SCHEME_FALSE);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k3883 in k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3885,c,av);}
if(C_truep(t1)){
t2=C_block_size(t1);
/* posix-common.scm:623: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[263]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[263]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t2,C_fix(1));
tp(5,av2);}}
else{
/* posix-common.scm:624: ##sys#error */
t2=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[269];
av2[3]=lf[271];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k3904 in k3857 in chicken.time.posix#time->string in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3906,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
if(C_truep(t1)){
t3=C_i_foreign_block_argumentp(t1);
/* posix-common.scm:611: ##sys#peek-c-string */
t4=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=stub931(t2,((C_word*)t0)[3],t3);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* posix-common.scm:611: ##sys#peek-c-string */
t3=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=stub931(t2,((C_word*)t0)[3],C_SCHEME_FALSE);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* chicken.process.signal#set-signal-handler! in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3914,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3918,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:631: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[273];
tp(4,av2);}}

/* k3916 in chicken.process.signal#set-signal-handler! in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3918,c,av);}
if(C_truep(((C_word*)t0)[2])){
t2=C_establish_signal_handler(((C_word*)t0)[3],((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[272]+1),((C_word*)t0)[3],((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_establish_signal_handler(((C_word*)t0)[3],C_SCHEME_FALSE);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[272]+1),((C_word*)t0)[3],((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word t43;
C_word t44;
C_word t45;
C_word t46;
C_word t47;
C_word t48;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(90,c,8)))){
C_save_and_reclaim((void *)f_3929,c,av);}
a=C_alloc(90);
t2=C_mutate((C_word*)lf[135]+1 /* (set! chicken.process.signal#signal-handler ...) */,t1);
t3=C_mutate((C_word*)lf[136]+1 /* (set! chicken.process.signal#make-signal-handler ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3931,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[137]+1 /* (set! chicken.process.signal#signal-ignore ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3997,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[138]+1 /* (set! chicken.process.signal#signal-default ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4006,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[124]+1 /* (set! chicken.process#process-sleep ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4015,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[112]+1 /* (set! chicken.process#process-wait ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4021,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate(&lf[285] /* (set! chicken.posix#list->c-string-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4092,a[2]=((C_word)li61),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate(&lf[287] /* (set! chicken.posix#free-c-string-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4209,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate(&lf[296] /* (set! chicken.posix#check-environment-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4243,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4290,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp);
t12=C_mutate(&lf[297] /* (set! chicken.posix#call-with-exec-args ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4292,a[2]=t11,a[3]=((C_word)li76),tmp=(C_word)a,a+=4,tmp));
t13=C_set_block_item(lf[125] /* chicken.process#pipe/buf */,0,C_fix((C_word)PIPE_BUF));
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4446,a[2]=((C_word)li77),tmp=(C_word)a,a+=3,tmp);
t15=C_mutate((C_word*)lf[118]+1 /* (set! chicken.process#open-input-pipe ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4465,a[2]=t14,a[3]=((C_word)li78),tmp=(C_word)a,a+=4,tmp));
t16=C_mutate((C_word*)lf[119]+1 /* (set! chicken.process#open-output-pipe ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4505,a[2]=t14,a[3]=((C_word)li79),tmp=(C_word)a,a+=4,tmp));
t17=C_mutate((C_word*)lf[115]+1 /* (set! chicken.process#close-input-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4545,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[116]+1 /* (set! chicken.process#close-output-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4560,a[2]=((C_word)li81),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[120]+1 /* (set! chicken.process#with-input-from-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4575,a[2]=((C_word)li86),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[114]+1 /* (set! chicken.process#call-with-output-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4609,a[2]=((C_word)li89),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[113]+1 /* (set! chicken.process#call-with-input-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4633,a[2]=((C_word)li92),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[121]+1 /* (set! chicken.process#with-output-to-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4657,a[2]=((C_word)li97),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate((C_word*)lf[315]+1 /* (set! ##sys#file-nonblocking! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4691,a[2]=((C_word)li98),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[316]+1 /* (set! ##sys#file-select-one ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4698,a[2]=((C_word)li99),tmp=(C_word)a,a+=3,tmp));
t25=C_set_block_item(lf[6] /* chicken.file.posix#fcntl/dupfd */,0,C_fix((C_word)F_DUPFD));
t26=C_set_block_item(lf[7] /* chicken.file.posix#fcntl/getfd */,0,C_fix((C_word)F_GETFD));
t27=C_set_block_item(lf[9] /* chicken.file.posix#fcntl/setfd */,0,C_fix((C_word)F_SETFD));
t28=C_set_block_item(lf[8] /* chicken.file.posix#fcntl/getfl */,0,C_fix((C_word)F_GETFL));
t29=C_set_block_item(lf[10] /* chicken.file.posix#fcntl/setfl */,0,C_fix((C_word)F_SETFL));
t30=C_set_block_item(lf[49] /* chicken.file.posix#open/nonblock */,0,C_fix((C_word)O_NONBLOCK));
t31=C_set_block_item(lf[47] /* chicken.file.posix#open/noctty */,0,C_fix((C_word)O_NOCTTY));
t32=C_set_block_item(lf[46] /* chicken.file.posix#open/fsync */,0,C_fix((C_word)O_FSYNC));
t33=C_set_block_item(lf[53] /* chicken.file.posix#open/sync */,0,C_fix((C_word)O_SYNC));
t34=C_set_block_item(lf[48] /* chicken.file.posix#open/noinherit */,0,C_fix(0));
t35=C_set_block_item(lf[126] /* chicken.process#spawn/overlay */,0,C_fix(0));
t36=C_set_block_item(lf[127] /* chicken.process#spawn/wait */,0,C_fix(0));
t37=C_set_block_item(lf[128] /* chicken.process#spawn/nowait */,0,C_fix(0));
t38=C_set_block_item(lf[129] /* chicken.process#spawn/nowaito */,0,C_fix(0));
t39=C_set_block_item(lf[130] /* chicken.process#spawn/detach */,0,C_fix(0));
t40=C_set_block_item(lf[66] /* chicken.file.posix#perm/isvtx */,0,C_fix((C_word)S_ISVTX));
t41=C_set_block_item(lf[65] /* chicken.file.posix#perm/isuid */,0,C_fix((C_word)S_ISUID));
t42=C_set_block_item(lf[64] /* chicken.file.posix#perm/isgid */,0,C_fix((C_word)S_ISGID));
t43=C_mutate((C_word*)lf[12]+1 /* (set! chicken.file.posix#file-control ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4738,a[2]=((C_word)li100),tmp=(C_word)a,a+=3,tmp));
t44=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va8871,a[2]=((C_word*)t0)[2],a[3]=((C_word)li219),tmp=(C_word)a,a+=4,tmp);
t45=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va8873,a[2]=t44,a[3]=((C_word)li220),tmp=(C_word)a,a+=4,tmp);
t46=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va8875,a[2]=t45,a[3]=((C_word)li221),tmp=(C_word)a,a+=4,tmp);
t47=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va8877,a[2]=t46,a[3]=((C_word)li222),tmp=(C_word)a,a+=4,tmp);
t48=t47;
va8877(t48,C_s_a_i_bitwise_ior(&a,2,C_fix((C_word)S_IRUSR),C_fix((C_word)S_IWUSR)));}

/* chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3931(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_3931,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3935,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:645: ##sys#make-event-queue */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[278]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[278]+1);
av2[1]=t3;
tp(2,av2);}}

/* k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_3935,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3936,a[2]=t1,a[3]=((C_word)li43),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3952,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3974,a[2]=t5,a[3]=t2,a[4]=((C_word)li45),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_3974(t7,t3,((C_word*)t0)[3]);}

/* g979 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3936(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_3936,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3940,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:648: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[275];
tp(4,av2);}}

/* k3938 in g979 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3940,c,av);}
a=C_alloc(4);
t2=C_establish_signal_handler(((C_word*)t0)[2],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3945,a[2]=((C_word*)t0)[3],a[3]=((C_word)li42),tmp=(C_word)a,a+=4,tmp);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_vector_set(*((C_word*)lf[272]+1),((C_word*)t0)[2],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a3944 in k3938 in g979 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3945(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3945,c,av);}
/* posix-common.scm:651: ##sys#add-event-to-queue! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[274]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[274]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
tp(4,av2);}}

/* k3950 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3952(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3952,c,av);}
a=C_alloc(4);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3953,a[2]=((C_word*)t0)[3],a[3]=((C_word)li44),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_3953 in k3950 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3953,c,av);}
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:656: ##sys#get-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[276]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[276]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
if(C_truep(C_get_rest_arg(c,2,av,2,t0))){
/* posix-common.scm:655: ##sys#wait-for-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[277]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[277]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
/* posix-common.scm:656: ##sys#get-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[276]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[276]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* for-each-loop978 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_3974(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3974,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3984,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:646: g979 */
t4=((C_word*)t0)[3];
f_3936(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3982 in for-each-loop978 in k3933 in chicken.process.signal#make-signal-handler in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3984,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3974(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.process.signal#signal-ignore in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_3997(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3997,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4001,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:660: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[279];
tp(4,av2);}}

/* k3999 in chicken.process.signal#signal-ignore in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4001,c,av);}
t2=C_establish_signal_handler(((C_word*)t0)[2],C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[272]+1),((C_word*)t0)[2],C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process.signal#signal-default in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4006,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4010,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:666: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[280];
tp(4,av2);}}

/* k4008 in chicken.process.signal#signal-default in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4010,c,av);}
t2=C_establish_signal_handler(((C_word*)t0)[2],C_SCHEME_TRUE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[272]+1),((C_word*)t0)[2],C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#process-sleep in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4015,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4019,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:675: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[281];
tp(4,av2);}}

/* k4017 in chicken.process#process-sleep in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4019,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_process_sleep(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#process-wait in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4021,c,av);}
a=C_alloc(5);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=(C_truep(t3)?t3:C_fix(-1));
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4040,a[2]=t8,a[3]=t6,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:682: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t9;
av2[2]=t8;
av2[3]=lf[283];
tp(4,av2);}}

/* k4038 in chicken.process#process-wait in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_4040,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4045,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li50),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4051,a[2]=((C_word*)t0)[2],a[3]=((C_word)li51),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:683: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a4044 in k4038 in chicken.process#process-wait in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4045,c,av);}
/* posix-common.scm:683: process-wait-impl */
f_7144(t1,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* a4050 in k4038 in chicken.process#process-wait in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4051(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4051,c,av);}
t5=C_eqp(t2,C_fix(-1));
if(C_truep(t5)){
/* posix-common.scm:685: posix-error */
t6=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[91];
av2[3]=lf[283];
av2[4]=lf[284];
av2[5]=((C_word*)t0)[2];
f_3009(6,av2);}}
else{
/* posix-common.scm:686: scheme#values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
C_values(5,av2);}}}

/* chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4092(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_4092,4,t1,t2,t3,t4);}
a=C_alloc(12);
t5=C_i_check_list_2(t2,t4);
t6=C_u_i_length(t2);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4100,a[2]=t1,a[3]=t6,a[4]=t4,a[5]=t3,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
t8=C_a_i_fixnum_plus(&a,2,t6,C_fix(1));
/* posix-common.scm:702: chicken.memory#make-pointer-vector */
t9=*((C_word*)lf[292]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
av2[3]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_4100,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4103,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4108,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li60),tmp=(C_word)a,a+=8,tmp);
/* posix-common.scm:704: scheme#call-with-current-continuation */
t4=*((C_word*)lf[291]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4101 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4103,c,av);}
/* posix-common.scm:700: g1050 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_4108,c,av);}
a=C_alloc(14);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4114,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li54),tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4129,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=((C_word)li59),tmp=(C_word)a,a+=9,tmp);
/* posix-common.scm:704: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[290]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* a4113 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4114,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4120,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li53),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:704: k1047 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a4119 in a4113 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4120,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4124,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:706: free-c-string-buffer */
f_4209(t2,((C_word*)t0)[3]);}

/* k4122 in a4119 in a4113 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4124,c,av);}
/* posix-common.scm:706: chicken.condition#signal */
t2=*((C_word*)lf[286]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_4129,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4131,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li56),tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4188,a[2]=((C_word*)t0)[7],a[3]=((C_word)li58),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4205,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tmp12590 */
t5=t2;
f_4131(t5,t4);}

/* tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4131(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_4131,2,t0,t1);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4135,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4137,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],a[7]=((C_word)li55),tmp=(C_word)a,a+=8,tmp));
t6=((C_word*)t4)[1];
f_4137(t6,t2,((C_word*)t0)[6],C_fix(0));}

/* k4133 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4135,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* doloop1055 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4137(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4137,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_nullp(t2);
t5=(C_truep(t4)?t4:C_eqp(t3,((C_word*)t0)[2]));
if(C_truep(t5)){
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t6=C_i_car(t2);
t7=C_i_check_string_2(t6,((C_word*)t0)[3]);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4153,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4178,a[2]=t8,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:715: convert */
t10=((C_word*)t0)[6];{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=C_u_i_car(t2);
((C_proc)C_fast_retrieve_proc(t10))(3,av2);}}}

/* k4151 in doloop1055 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4153,c,av);}
a=C_alloc(13);
t2=C_a_i_bytevector(&a,1,C_fix(3));
t3=stub1038(t2,t1);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4159,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t3,tmp=(C_word)a,a+=8,tmp);
if(C_truep(t3)){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_4159(2,av2);}}
else{
/* posix-common.scm:717: chicken.base#error */
t5=*((C_word*)lf[101]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[7];
av2[3]=lf[289];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k4157 in k4151 in doloop1055 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4159,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4162,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:718: chicken.memory#pointer-vector-set! */
t3=*((C_word*)lf[288]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4160 in k4157 in k4151 in doloop1055 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4162(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4162,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4137(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* k4176 in doloop1055 in tmp12590 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4178,c,av);}
/* posix-common.scm:715: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* tmp22591 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4188(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4188,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4194,a[2]=t2,a[3]=((C_word)li57),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:704: k1047 */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a4193 in tmp22591 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4194(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4194,c,av);}{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
C_apply_values(3,av2);}}

/* k4203 in a4128 in a4107 in k4098 in chicken.posix#list->c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4205,c,av);}
a=C_alloc(3);
/* tmp22591 */
t2=((C_word*)t0)[2];
f_4188(t2,((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* chicken.posix#free-c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4209(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4209,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4213,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:723: chicken.memory#pointer-vector-length */
t4=*((C_word*)lf[295]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4211 in chicken.posix#free-c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4213,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4218,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li62),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_4218(t5,((C_word*)t0)[3],C_fix(0));}

/* doloop1074 in k4211 in chicken.posix#free-c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4218(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4218,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_eqp(t2,((C_word*)t0)[2]);
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4228,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:726: chicken.memory#pointer-vector-ref */
t5=*((C_word*)lf[294]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k4226 in doloop1074 in k4211 in chicken.posix#free-c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4228,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4231,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
/* posix-common.scm:727: chicken.memory#free */
t3=*((C_word*)lf[293]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=((C_word*)((C_word*)t0)[2])[1];
f_4218(t3,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}}

/* k4229 in k4226 in doloop1074 in k4211 in chicken.posix#free-c-string-buffer in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4231(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4231,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4218(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* chicken.posix#check-environment-list in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4243(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_4243,3,t1,t2,t3);}
a=C_alloc(8);
t4=C_i_check_list_2(t2,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4248,a[2]=t3,a[3]=((C_word)li64),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4267,a[2]=t5,a[3]=((C_word)li65),tmp=(C_word)a,a+=4,tmp);
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=(
  f_4267(t6,t2)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* g1087 in chicken.posix#check-environment-list in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static C_word C_fcall f_4248(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_i_check_pair_2(t1,((C_word*)t0)[2]);
t3=C_i_check_string_2(C_u_i_car(t1),((C_word*)t0)[2]);
return(C_i_check_string_2(C_u_i_cdr(t1),((C_word*)t0)[2]));}

/* for-each-loop1086 in chicken.posix#check-environment-list in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static C_word C_fcall f_4267(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* posix-common.scm:732: g1087 */
  f_4248(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* nop in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4290,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4292(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_4292,8,t0,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(11);
t8=C_a_i_cons(&a,2,t3,t5);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4299,a[2]=t1,a[3]=t7,a[4]=t3,a[5]=t2,a[6]=t6,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* posix-common.scm:743: list->c-string-buffer */
f_4092(t9,t8,t4,t2);}

/* k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_4299,c,av);}
a=C_alloc(15);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4302,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4307,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li75),tmp=(C_word)a,a+=10,tmp);
/* posix-common.scm:746: scheme#call-with-current-continuation */
t6=*((C_word*)lf[291]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k4300 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4302,c,av);}
/* posix-common.scm:742: g1120 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_4307,c,av);}
a=C_alloc(17);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4313,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word)li69),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4334,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t2,a[10]=((C_word)li74),tmp=(C_word)a,a+=11,tmp);
/* posix-common.scm:746: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[290]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* a4312 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4313(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4313,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4319,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li68),tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:746: k1117 */
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a4318 in a4312 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4319,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4323,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:748: free-c-string-buffer */
f_4209(t2,((C_word*)t0)[4]);}

/* k4321 in a4318 in a4312 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4323,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4326,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
/* posix-common.scm:749: free-c-string-buffer */
f_4209(t2,((C_word*)((C_word*)t0)[4])[1]);}
else{
/* posix-common.scm:750: chicken.condition#signal */
t3=*((C_word*)lf[286]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k4324 in k4321 in a4318 in a4312 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4326,c,av);}
/* posix-common.scm:750: chicken.condition#signal */
t2=*((C_word*)lf[286]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_4334,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4340,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word)li71),tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4415,a[2]=((C_word*)t0)[9],a[3]=((C_word)li73),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:746: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4340(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_4340,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4344,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[7])){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4354,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:754: check-environment-list */
f_4243(t3,((C_word*)t0)[7],((C_word*)t0)[6]);}
else{
t3=t2;
f_4344(t3,C_SCHEME_UNDEFINED);}}

/* k4342 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4344(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_4344,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4351,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:760: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
tp(4,av2);}}

/* k4349 in k4342 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4351,c,av);}
/* posix-common.scm:760: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)((C_word*)t0)[5])[1];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* k4352 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_4354,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4358,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[298]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4379,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4381,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li70),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_4381(t12,t8,((C_word*)t0)[4]);}

/* k4356 in k4352 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4358,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_4344(t3,t2);}

/* k4377 in k4352 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4379,c,av);}
/* posix-common.scm:756: list->c-string-buffer */
f_4092(((C_word*)t0)[2],t1,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* map-loop1128 in k4352 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4381(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_4381,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4406,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
/* posix-common.scm:757: scheme#string-append */
t5=*((C_word*)lf[104]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t3;
av2[2]=C_i_car(t4);
av2[3]=lf[299];
av2[4]=C_u_i_cdr(t4);
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4404 in map-loop1128 in k4352 in a4339 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4406,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4381(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a4414 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4415,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4421,a[2]=t2,a[3]=((C_word)li72),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:746: k1117 */
t4=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a4420 in a4414 in a4333 in a4306 in k4297 in chicken.posix#call-with-exec-args in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4421,c,av);}{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
C_apply_values(3,av2);}}

/* check in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall f_4446(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_4446,5,t1,t2,t3,t4,t5);}
a=C_alloc(4);
if(C_truep(C_null_pointerp(t5))){
/* posix-common.scm:772: posix-error */
t6=lf[186];{
C_word av2[6];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[191];
av2[3]=t2;
av2[4]=lf[300];
av2[5]=t3;
f_3009(6,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4459,a[2]=t5,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* posix-common.scm:773: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[243]+1);
av2[1]=t6;
av2[2]=C_fix(1);
av2[3]=*((C_word*)lf[244]+1);
av2[4]=lf[301];
av2[5]=lf[234];
tp(6,av2);}}
else{
/* posix-common.scm:773: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[243]+1);
av2[1]=t6;
av2[2]=C_fix(2);
av2[3]=*((C_word*)lf[244]+1);
av2[4]=lf[301];
av2[5]=lf[234];
tp(6,av2);}}}}

/* k4457 in check in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4459,c,av);}
t2=C_set_file_ptr(t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#open-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +10,c,3)))){
C_save_and_reclaim((void*)f_4465,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+10);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
t4=C_i_check_string_2(t2,lf[302]);
t5=C_i_pairp(t3);
t6=(C_truep(t5)?C_slot(t3,C_fix(0)):lf[303]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4479,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(t6,lf[303]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4486,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:784: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t9;
av2[2]=t2;
av2[3]=lf[302];
tp(4,av2);}}
else{
t9=C_eqp(t6,lf[304]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4496,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:785: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t10;
av2[2]=t2;
av2[3]=lf[302];
tp(4,av2);}}
else{
/* posix-common.scm:769: ##sys#error */
t10=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t7;
av2[2]=lf[305];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}}

/* k4477 in chicken.process#open-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4479,c,av);}
/* posix-common.scm:780: check */
f_4446(((C_word*)t0)[3],lf[302],((C_word*)t0)[4],C_SCHEME_TRUE,t1);}

/* k4484 in chicken.process#open-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4486(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4486,c,av);}
a=C_alloc(2);
t2=open_text_input_pipe(&a,1,t1);
/* posix-common.scm:780: check */
f_4446(((C_word*)t0)[3],lf[302],((C_word*)t0)[4],C_SCHEME_TRUE,t2);}

/* k4494 in chicken.process#open-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4496,c,av);}
a=C_alloc(2);
t2=open_binary_input_pipe(&a,1,t1);
/* posix-common.scm:780: check */
f_4446(((C_word*)t0)[3],lf[302],((C_word*)t0)[4],C_SCHEME_TRUE,t2);}

/* chicken.process#open-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4505(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +10,c,3)))){
C_save_and_reclaim((void*)f_4505,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+10);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
t4=C_i_check_string_2(t2,lf[306]);
t5=C_i_pairp(t3);
t6=(C_truep(t5)?C_slot(t3,C_fix(0)):lf[303]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4519,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(t6,lf[303]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4526,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:795: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t9;
av2[2]=t2;
av2[3]=lf[306];
tp(4,av2);}}
else{
t9=C_eqp(t6,lf[304]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4536,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:796: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t10;
av2[2]=t2;
av2[3]=lf[306];
tp(4,av2);}}
else{
/* posix-common.scm:769: ##sys#error */
t10=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t7;
av2[2]=lf[305];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}}

/* k4517 in chicken.process#open-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4519,c,av);}
/* posix-common.scm:791: check */
f_4446(((C_word*)t0)[3],lf[306],((C_word*)t0)[4],C_SCHEME_FALSE,t1);}

/* k4524 in chicken.process#open-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4526,c,av);}
a=C_alloc(2);
t2=open_text_output_pipe(&a,1,t1);
/* posix-common.scm:791: check */
f_4446(((C_word*)t0)[3],lf[306],((C_word*)t0)[4],C_SCHEME_FALSE,t2);}

/* k4534 in chicken.process#open-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4536(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4536,c,av);}
a=C_alloc(2);
t2=open_binary_output_pipe(&a,1,t1);
/* posix-common.scm:791: check */
f_4446(((C_word*)t0)[3],lf[306],((C_word*)t0)[4],C_SCHEME_FALSE,t2);}

/* chicken.process#close-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_4545,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(1),C_SCHEME_TRUE,lf[307]);
t4=close_pipe(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4552,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(C_fix(-1),t4);
if(C_truep(t6)){
/* posix-common.scm:803: posix-error */
t7=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=lf[191];
av2[3]=lf[307];
av2[4]=lf[308];
av2[5]=t2;
f_3009(6,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k4550 in chicken.process#close-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4552,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#close-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_4560,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(2),C_SCHEME_TRUE,lf[309]);
t4=close_pipe(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4567,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(C_fix(-1),t4);
if(C_truep(t6)){
/* posix-common.scm:810: posix-error */
t7=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=lf[191];
av2[3]=lf[309];
av2[4]=lf[310];
av2[5]=t2;
f_3009(6,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k4565 in chicken.process#close-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4567,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4575,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4579,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[118]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_4579,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4584,a[2]=t5,a[3]=t3,a[4]=((C_word)li82),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4589,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word)li84),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4604,a[2]=t3,a[3]=t5,a[4]=((C_word)li85),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:816: ##sys#dynamic-wind */
t9=*((C_word*)lf[313]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[3];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a4583 in k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4584(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4584,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[311]+1));
t3=C_mutate((C_word*)lf[311]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4588 in k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4589(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4589,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4595,a[2]=((C_word*)t0)[2],a[3]=((C_word)li83),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:817: scheme#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
C_call_with_values(4,av2);}}

/* a4594 in a4588 in k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4595,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4599,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:819: chicken.process#close-input-pipe */
t4=*((C_word*)lf[115]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4597 in a4594 in a4588 in k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4599,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[312]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* a4603 in k4577 in chicken.process#with-input-from-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4604,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[311]+1));
t3=C_mutate((C_word*)lf[311]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.process#call-with-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4609,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4613,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[119]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4611 in chicken.process#call-with-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4613,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4618,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li87),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4624,a[2]=t1,a[3]=((C_word)li88),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:825: scheme#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a4617 in k4611 in chicken.process#call-with-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4618,c,av);}
/* posix-common.scm:826: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a4623 in k4611 in chicken.process#call-with-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4624(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4624,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4628,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:828: chicken.process#close-output-pipe */
t4=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4626 in a4623 in k4611 in chicken.process#call-with-output-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4628,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[312]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* chicken.process#call-with-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4633,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4637,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[118]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4635 in chicken.process#call-with-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4637,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4642,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li90),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4648,a[2]=t1,a[3]=((C_word)li91),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:834: scheme#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a4641 in k4635 in chicken.process#call-with-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4642(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4642,c,av);}
/* posix-common.scm:835: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a4647 in k4635 in chicken.process#call-with-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4648(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4648,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4652,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:837: chicken.process#close-input-pipe */
t4=*((C_word*)lf[115]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4650 in a4647 in k4635 in chicken.process#call-with-input-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4652,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[312]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4657,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4661,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[119]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_4661,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4666,a[2]=t5,a[3]=t3,a[4]=((C_word)li93),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4671,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word)li95),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4686,a[2]=t3,a[3]=t5,a[4]=((C_word)li96),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:843: ##sys#dynamic-wind */
t9=*((C_word*)lf[313]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[3];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a4665 in k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4666,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[314]+1));
t3=C_mutate((C_word*)lf[314]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4670 in k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4671,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4677,a[2]=((C_word*)t0)[2],a[3]=((C_word)li94),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:844: scheme#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
C_call_with_values(4,av2);}}

/* a4676 in a4670 in k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4677,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4681,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:846: chicken.process#close-output-pipe */
t4=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4679 in a4676 in a4670 in k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4681,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[312]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* a4685 in k4659 in chicken.process#with-output-to-pipe in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4686,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[314]+1));
t3=C_mutate((C_word*)lf[314]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* ##sys#file-nonblocking! in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4691,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub1331(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* ##sys#file-select-one in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4698,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub1336(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.file.posix#file-control in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4738,c,av);}
a=C_alloc(6);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_fix(0):C_get_rest_arg(c,4,av,4,t0));
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4745,a[2]=t2,a[3]=t3,a[4]=t5,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:330: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=lf[317];
tp(4,av2);}}

/* k4743 in chicken.file.posix#file-control in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4745,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4748,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:331: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[317];
tp(4,av2);}}

/* k4746 in k4743 in chicken.file.posix#file-control in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_4748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4748,c,av);}
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=C_fix((C_word)sizeof(long) * CHAR_BIT);
t5=C_i_foreign_ranged_integer_argumentp(((C_word*)t0)[4],t4);
t6=stub1343(C_SCHEME_UNDEFINED,t2,t3,t5);
t7=C_eqp(t6,C_fix(-1));
if(C_truep(t7)){
/* posixunix.scm:334: posix-error */
t8=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t8;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[191];
av2[3]=lf[317];
av2[4]=lf[318];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[3];
f_3009(7,av2);}}
else{
t8=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t8;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* chicken.file.posix#file-open */
static void C_ccall f_4771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4771,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_get_rest_arg(c,4,av,4,t0):((C_word*)t0)[2]);
t7=C_i_check_string_2(t2,lf[319]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4781,a[2]=t3,a[3]=t6,a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:342: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t8;
av2[2]=t3;
av2[3]=lf[319];
tp(4,av2);}}

/* k4779 in chicken.file.posix#file-open */
static void C_ccall f_4781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4781,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4784,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:343: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[319];
tp(4,av2);}}

/* k4782 in k4779 in chicken.file.posix#file-open */
static void C_ccall f_4784(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4784,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4788,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:344: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[319];
tp(4,av2);}}

/* k4786 in k4782 in k4779 in chicken.file.posix#file-open */
static void C_ccall f_4788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,7)))){
C_save_and_reclaim((void *)f_4788,c,av);}
a=C_alloc(4);
t2=C_open(t1,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4791,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
/* posixunix.scm:346: posix-error */
t5=lf[186];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[191];
av2[3]=lf[319];
av2[4]=lf[320];
av2[5]=((C_word*)t0)[5];
av2[6]=((C_word*)t0)[2];
av2[7]=((C_word*)t0)[3];
f_3009(8,av2);}}
else{
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4789 in k4786 in k4782 in k4779 in chicken.file.posix#file-open */
static void C_ccall f_4791(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4791,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-close */
static void C_ccall f_4803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4803,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4807,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:351: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[322];
tp(4,av2);}}

/* k4805 in chicken.file.posix#file-close */
static void C_ccall f_4807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4807,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4812,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li102),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
f_4812(2,av2);}}

/* loop in k4805 in chicken.file.posix#file-close */
static void C_ccall f_4812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4812,c,av);}
if(C_truep(C_fixnum_lessp(C_close(((C_word*)t0)[2]),C_fix(0)))){
t2=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t2)){
/* posixunix.scm:355: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[321]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
tp(3,av2);}}
else{
/* posixunix.scm:357: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[191];
av2[3]=lf[322];
av2[4]=lf[323];
av2[5]=((C_word*)t0)[2];
f_3009(6,av2);}}}
else{
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.file.posix#file-read */
static void C_ccall f_4834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4834,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4838,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:361: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[324];
tp(4,av2);}}

/* k4836 in chicken.file.posix#file-read */
static void C_ccall f_4838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4838,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4841,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:362: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[324];
tp(4,av2);}}

/* k4839 in k4836 in chicken.file.posix#file-read */
static void C_ccall f_4841(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4841,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4844,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[5]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_car(((C_word*)t0)[5]);
f_4844(2,av2);}}
else{
/* posixunix.scm:363: scheme#make-string */
t3=*((C_word*)lf[327]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k4842 in k4839 in k4836 in chicken.file.posix#file-read */
static void C_ccall f_4844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_4844,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4847,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_blockp(t1))){
if(C_truep(C_byteblockp(t1))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4847(2,av2);}}
else{
/* posixunix.scm:365: ##sys#signal-hook */
t3=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=lf[324];
av2[4]=lf[326];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}
else{
/* posixunix.scm:365: ##sys#signal-hook */
t3=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=lf[324];
av2[4]=lf[326];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* k4845 in k4842 in k4839 in k4836 in chicken.file.posix#file-read */
static void C_ccall f_4847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,6)))){
C_save_and_reclaim((void *)f_4847,c,av);}
a=C_alloc(11);
t2=C_read(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4850,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
/* posixunix.scm:368: posix-error */
t5=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[191];
av2[3]=lf[324];
av2[4]=lf[325];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[4];
f_3009(7,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4848 in k4845 in k4842 in k4839 in k4836 in chicken.file.posix#file-read */
static void C_ccall f_4850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4850,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-write */
static void C_ccall f_4874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4874,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4878,a[2]=t4,a[3]=t3,a[4]=t2,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:373: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[328];
tp(4,av2);}}

/* k4876 in chicken.file.posix#file-write */
static void C_ccall f_4878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_4878,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4881,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_blockp(((C_word*)t0)[3]))){
if(C_truep(C_byteblockp(((C_word*)t0)[3]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4881(2,av2);}}
else{
/* posixunix.scm:375: ##sys#signal-hook */
t3=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=lf[328];
av2[4]=lf[330];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}
else{
/* posixunix.scm:375: ##sys#signal-hook */
t3=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=lf[328];
av2[4]=lf[330];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* k4879 in k4876 in chicken.file.posix#file-write */
static void C_ccall f_4881(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4881,c,av);}
a=C_alloc(6);
t2=C_i_pairp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_u_i_car(((C_word*)t0)[2]):C_block_size(((C_word*)t0)[3]));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4887,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:377: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[328];
tp(4,av2);}}

/* k4885 in k4879 in k4876 in chicken.file.posix#file-write */
static void C_ccall f_4887(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,6)))){
C_save_and_reclaim((void *)f_4887,c,av);}
a=C_alloc(4);
t2=C_write(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4890,a[2]=((C_word*)t0)[5],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
/* posixunix.scm:380: posix-error */
t5=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[191];
av2[3]=lf[328];
av2[4]=lf[329];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[4];
f_3009(7,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4888 in k4885 in k4879 in k4876 in chicken.file.posix#file-write */
static void C_ccall f_4890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4890,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-mkstemp */
static void C_ccall f_4911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4911,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[331]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4918,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:386: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[331];
tp(4,av2);}}

/* k4916 in chicken.file.posix#file-mkstemp */
static void C_ccall f_4918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_4918,c,av);}
a=C_alloc(6);
t2=C_mkstemp(t1);
t3=C_block_size(t1);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4924,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=C_eqp(C_fix(-1),t2);
if(C_truep(t5)){
/* posixunix.scm:390: posix-error */
t6=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=lf[191];
av2[3]=lf[331];
av2[4]=lf[332];
av2[5]=((C_word*)t0)[3];
f_3009(6,av2);}}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_4924(2,av2);}}}

/* k4922 in k4916 in chicken.file.posix#file-mkstemp */
static void C_ccall f_4924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4924,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4931,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:391: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[263]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[263]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(((C_word*)t0)[5],C_fix(1));
tp(5,av2);}}

/* k4929 in k4922 in k4916 in chicken.file.posix#file-mkstemp */
static void C_ccall f_4931(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4931,c,av);}
/* posixunix.scm:391: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
C_values(4,av2);}}

/* chicken.file.posix#file-select */
static void C_ccall f_4943(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +9,c,2)))){
C_save_and_reclaim((void*)f_4943,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+9);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_get_rest_arg(c,4,av,4,t0):C_SCHEME_FALSE);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4950,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_not(t2))){
t8=t7;
f_4950(t8,C_SCHEME_END_OF_LIST);}
else{
if(C_truep(C_fixnump(t2))){
t8=t7;
f_4950(t8,C_a_i_list1(&a,1,t2));}
else{
t8=C_i_check_list_2(t2,lf[333]);
t9=t7;
f_4950(t9,t2);}}}

/* k4948 in chicken.file.posix#file-select */
static void C_fcall f_4950(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_4950,2,t0,t1);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4953,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_not(((C_word*)t0)[4]))){
t3=t2;
f_4953(t3,C_SCHEME_END_OF_LIST);}
else{
if(C_truep(C_fixnump(((C_word*)t0)[4]))){
t3=t2;
f_4953(t3,C_a_i_list1(&a,1,((C_word*)t0)[4]));}
else{
t3=C_i_check_list_2(((C_word*)t0)[4],lf[333]);
t4=t2;
f_4953(t4,((C_word*)t0)[4]);}}}

/* k4951 in k4948 in chicken.file.posix#file-select */
static void C_fcall f_4953(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_4953,2,t0,t1);}
a=C_alloc(10);
t2=C_u_i_length(((C_word*)t0)[2]);
t3=C_u_i_length(t1);
t4=C_fixnum_plus(t2,t3);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4961,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t1,a[5]=t4,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
t6=C_fix((C_word)sizeof(struct pollfd));
/* posixunix.scm:410: ##sys#make-blob */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[339]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[339]+1);
av2[1]=t5;
av2[2]=C_fixnum_times(t4,t6);
tp(3,av2);}}

/* k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_4961(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_4961,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5241,a[2]=t1,a[3]=((C_word)li107),tmp=(C_word)a,a+=4,tmp);
t3=(
  f_5241(t2,C_fix(0),((C_word*)t0)[2])
);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5199,a[2]=t1,a[3]=((C_word)li108),tmp=(C_word)a,a+=4,tmp);
t5=(
  f_5199(t4,((C_word*)t0)[3],((C_word*)t0)[4])
);
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5182,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[2],tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)t0)[9])){
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5189,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5197,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:425: scheme#max */
t9=*((C_word*)lf[338]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=C_fix(0);
av2[3]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t7=t6;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_fix(-1);
f_5182(2,av2);}}}

/* k5020 in k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_5022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_5022,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5062,a[2]=((C_word*)t0)[5],a[3]=t4,a[4]=((C_word)li109),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_5062(t6,t2,((C_word*)t0)[6],C_SCHEME_END_OF_LIST,((C_word*)t0)[7]);}

/* k5023 in k5020 in k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_5025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5025,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5032,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[4])){
if(C_truep(C_fixnump(((C_word*)t0)[4]))){
t3=C_i_memq(((C_word*)t0)[4],((C_word*)t0)[5]);
t4=t2;
f_5032(t4,(C_truep(t3)?((C_word*)t0)[4]:C_SCHEME_FALSE));}
else{
t3=t2;
f_5032(t3,((C_word*)t0)[5]);}}
else{
t3=t2;
f_5032(t3,C_SCHEME_FALSE);}}

/* k5030 in k5023 in k5020 in k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_fcall f_5032(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_5032,2,t0,t1);}
if(C_truep(((C_word*)t0)[2])){
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
if(C_truep(C_i_memq(((C_word*)t0)[2],((C_word*)t0)[3]))){
/* posixunix.scm:446: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=((C_word*)t0)[2];
C_values(4,av2);}}
else{
/* posixunix.scm:446: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}
else{
/* posixunix.scm:446: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
C_values(4,av2);}}}
else{
/* posixunix.scm:446: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}

/* lp in k5020 in k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_fcall f_5062(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_5062,5,t0,t1,t2,t3,t4);}
a=C_alloc(3);
if(C_truep(C_i_nullp(t4))){
/* posixunix.scm:439: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[335]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[335]+1);
av2[1]=t1;
av2[2]=t3;
tp(3,av2);}}
else{
t5=C_i_foreign_fixnum_argumentp(t2);
t6=(C_truep(((C_word*)t0)[2])?stub1515(C_SCHEME_UNDEFINED,t5,C_i_foreign_block_argumentp(((C_word*)t0)[2])):stub1515(C_SCHEME_UNDEFINED,t5,C_SCHEME_FALSE));
if(C_truep(t6)){
t7=C_fixnum_plus(t2,C_fix(1));
t8=C_i_car(t4);
t9=C_a_i_cons(&a,2,t8,t3);
/* posixunix.scm:444: lp */
t11=t1;
t12=t7;
t13=t9;
t14=C_u_i_cdr(t4);
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}
else{
/* posixunix.scm:445: lp */
t11=t1;
t12=C_fixnum_plus(t2,C_fix(1));
t13=t3;
t14=C_i_cdr(t4);
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}}}

/* lp in k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_fcall f_5121(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_5121,5,t0,t1,t2,t3,t4);}
a=C_alloc(3);
if(C_truep(C_i_nullp(t4))){
/* posixunix.scm:431: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[335]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[335]+1);
av2[1]=t1;
av2[2]=t3;
tp(3,av2);}}
else{
t5=C_i_foreign_fixnum_argumentp(t2);
t6=(C_truep(((C_word*)t0)[2])?stub1496(C_SCHEME_UNDEFINED,t5,C_i_foreign_block_argumentp(((C_word*)t0)[2])):stub1496(C_SCHEME_UNDEFINED,t5,C_SCHEME_FALSE));
if(C_truep(t6)){
t7=C_fixnum_plus(t2,C_fix(1));
t8=C_i_car(t4);
t9=C_a_i_cons(&a,2,t8,t3);
/* posixunix.scm:436: lp */
t11=t1;
t12=t7;
t13=t9;
t14=C_u_i_cdr(t4);
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}
else{
/* posixunix.scm:437: lp */
t11=t1;
t12=C_fixnum_plus(t2,C_fix(1));
t13=t3;
t14=C_i_cdr(t4);
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}}}

/* k5180 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_5182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,6)))){
C_save_and_reclaim((void *)f_5182,c,av);}
a=C_alloc(15);
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_block_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=C_i_foreign_fixnum_argumentp(t1);
t5=stub1471(C_SCHEME_UNDEFINED,t2,t3,t4);
if(C_truep(C_fixnum_lessp(t5,C_fix(0)))){
/* posixunix.scm:427: posix-error */
t6=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[191];
av2[3]=lf[333];
av2[4]=lf[334];
av2[5]=((C_word*)t0)[5];
av2[6]=((C_word*)t0)[6];
f_3009(7,av2);}}
else{
t6=C_eqp(t5,C_fix(0));
if(C_truep(t6)){
t7=C_i_pairp(((C_word*)t0)[5]);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_SCHEME_FALSE);
if(C_truep(C_i_pairp(((C_word*)t0)[6]))){
/* posixunix.scm:428: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t8;
av2[3]=C_SCHEME_END_OF_LIST;
C_values(4,av2);}}
else{
/* posixunix.scm:428: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t8;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}
else{
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5022,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5121,a[2]=((C_word*)t0)[2],a[3]=t9,a[4]=((C_word)li110),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_5121(t11,t7,C_fix(0),C_SCHEME_END_OF_LIST,((C_word*)t0)[9]);}}}

/* k5187 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_5189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5189,c,av);}
/* posixunix.scm:425: scheme#inexact->exact */
t2=*((C_word*)lf[336]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k5195 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static void C_ccall f_5197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_5197,c,av);}
a=C_alloc(33);
t2=C_s_a_i_times(&a,2,t1,C_fix(1000));
/* posixunix.scm:425: scheme#truncate */
t3=*((C_word*)lf[337]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* doloop1430 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static C_word C_fcall f_5199(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
return(t3);}
else{
t3=C_i_car(t2);
t4=C_i_foreign_fixnum_argumentp(t1);
t5=C_i_foreign_fixnum_argumentp(t3);
t6=(C_truep(((C_word*)t0)[2])?stub1456(C_SCHEME_UNDEFINED,t4,t5,C_i_foreign_block_argumentp(((C_word*)t0)[2])):stub1456(C_SCHEME_UNDEFINED,t4,t5,C_SCHEME_FALSE));
t8=C_fixnum_plus(t1,C_fix(1));
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}

/* doloop1429 in k4959 in k4951 in k4948 in chicken.file.posix#file-select */
static C_word C_fcall f_5241(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
return(t3);}
else{
t3=C_i_car(t2);
t4=C_i_foreign_fixnum_argumentp(t1);
t5=C_i_foreign_fixnum_argumentp(t3);
t6=(C_truep(((C_word*)t0)[2])?stub1439(C_SCHEME_UNDEFINED,t4,t5,C_i_foreign_block_argumentp(((C_word*)t0)[2])):stub1439(C_SCHEME_UNDEFINED,t4,t5,C_SCHEME_FALSE));
t8=C_fixnum_plus(t1,C_fix(1));
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}

/* chicken.process#create-pipe */
static void C_ccall f_5322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_5322,c,av);}
a=C_alloc(3);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5329,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_fixnum_lessp(C_pipe(C_SCHEME_FALSE),C_fix(0)))){
/* posixunix.scm:459: posix-error */
t5=lf[186];{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[191];
av2[3]=lf[340];
av2[4]=lf[341];
f_3009(5,av2);}}
else{
/* posixunix.scm:460: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=C_fix((C_word)C_pipefds[ 0 ]);
av2[3]=C_fix((C_word)C_pipefds[ 1 ]);
C_values(4,av2);}}}

/* k5327 in chicken.process#create-pipe */
static void C_ccall f_5329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5329,c,av);}
/* posixunix.scm:460: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix((C_word)C_pipefds[ 0 ]);
av2[3]=C_fix((C_word)C_pipefds[ 1 ]);
C_values(4,av2);}}

/* chicken.process.signal#set-signal-mask! */
static void C_ccall f_5378(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5378,c,av);}
a=C_alloc(9);
t3=C_i_check_list_2(t2,lf[342]);
t4=C_sigemptyset(C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5390,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5402,a[2]=t7,a[3]=((C_word)li113),tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_5402(t9,t5,t2);}

/* k5385 in for-each-loop1542 in chicken.process.signal#set-signal-mask! */
static void C_ccall f_5387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5387,c,av);}
t2=C_sigaddset(((C_word*)t0)[2]);
t3=((C_word*)((C_word*)t0)[3])[1];
f_5402(t3,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k5388 in chicken.process.signal#set-signal-mask! */
static void C_ccall f_5390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5390,c,av);}
if(C_truep(C_fixnum_lessp(C_sigprocmask_set(C_fix(0)),C_fix(0)))){
/* posixunix.scm:560: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[91];
av2[3]=lf[342];
av2[4]=lf[343];
f_3009(5,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* for-each-loop1542 in chicken.process.signal#set-signal-mask! */
static void C_fcall f_5402(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5402,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5387,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:556: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[342];
tp(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k5425 */
static void C_ccall f_5427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_5427,c,av);}
a=C_alloc(18);
t2=C_mutate((C_word*)lf[139]+1 /* (set! chicken.process.signal#signal-mask ...) */,t1);
t3=C_mutate((C_word*)lf[141]+1 /* (set! chicken.process.signal#signal-masked? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5429,a[2]=((C_word)li115),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[140]+1 /* (set! chicken.process.signal#signal-mask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5435,a[2]=((C_word)li116),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[142]+1 /* (set! chicken.process.signal#signal-unmask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5451,a[2]=((C_word)li117),tmp=(C_word)a,a+=3,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5469,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7892,a[2]=((C_word)li215),tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7895,a[2]=((C_word)li216),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:601: chicken.base#getter-with-setter */
t9=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=t6;
av2[2]=t7;
av2[3]=t8;
av2[4]=lf[493];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* chicken.process.signal#signal-masked? in k5425 */
static void C_ccall f_5429(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5429,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5433,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:577: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[344];
tp(4,av2);}}

/* k5431 in chicken.process.signal#signal-masked? in k5425 */
static void C_ccall f_5433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5433,c,av);}
t2=C_sigprocmask_get(C_fix(0));
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_sigismember(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process.signal#signal-mask! in k5425 */
static void C_ccall f_5435(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5435,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5439,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:583: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[345];
tp(4,av2);}}

/* k5437 in chicken.process.signal#signal-mask! in k5425 */
static void C_ccall f_5439(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5439,c,av);}
t2=C_sigemptyset(C_fix(0));
t3=C_sigaddset(((C_word*)t0)[2]);
if(C_truep(C_fixnum_lessp(C_sigprocmask_block(C_fix(0)),C_fix(0)))){
/* posixunix.scm:587: posix-error */
t4=lf[186];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[91];
av2[3]=lf[345];
av2[4]=lf[346];
f_3009(5,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* chicken.process.signal#signal-unmask! in k5425 */
static void C_ccall f_5451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5451,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5455,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:591: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[347];
tp(4,av2);}}

/* k5453 in chicken.process.signal#signal-unmask! in k5425 */
static void C_ccall f_5455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5455,c,av);}
t2=C_sigemptyset(C_fix(0));
t3=C_sigaddset(((C_word*)t0)[2]);
if(C_truep(C_fixnum_lessp(C_sigprocmask_unblock(C_fix(0)),C_fix(0)))){
/* posixunix.scm:595: posix-error */
t4=lf[186];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[91];
av2[3]=lf[347];
av2[4]=lf[348];
f_3009(5,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k5467 in k5425 */
static void C_ccall f_5469(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_5469,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[177]+1 /* (set! chicken.process-context.posix#current-user-id ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5473,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7869,a[2]=((C_word)li213),tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7872,a[2]=((C_word)li214),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:611: chicken.base#getter-with-setter */
t6=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=lf[489];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5471 in k5467 in k5425 */
static void C_ccall f_5473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_5473,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[175]+1 /* (set! chicken.process-context.posix#current-effective-user-id ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5477,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7846,a[2]=((C_word)li211),tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7849,a[2]=((C_word)li212),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:622: chicken.base#getter-with-setter */
t6=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=lf[485];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_5477,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[176]+1 /* (set! chicken.process-context.posix#current-group-id ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5481,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7823,a[2]=((C_word)li209),tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7826,a[2]=((C_word)li210),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:632: chicken.base#getter-with-setter */
t6=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=lf[481];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5481(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,6)))){
C_save_and_reclaim((void *)f_5481,c,av);}
a=C_alloc(24);
t2=C_mutate((C_word*)lf[174]+1 /* (set! chicken.process-context.posix#current-effective-group-id ...) */,t1);
t3=C_mutate((C_word*)lf[184]+1 /* (set! chicken.process-context.posix#user-information ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5483,a[2]=((C_word)li118),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[180]+1 /* (set! chicken.process-context.posix#current-user-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5537,a[2]=((C_word)li119),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[181]+1 /* (set! chicken.process-context.posix#current-effective-user-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5551,a[2]=((C_word)li120),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate(&lf[220] /* (set! chicken.posix#chown ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5565,a[2]=((C_word)li121),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[182]+1 /* (set! chicken.process-context.posix#create-session ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5612,a[2]=((C_word)li122),tmp=(C_word)a,a+=3,tmp));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5630,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7781,a[2]=((C_word)li207),tmp=(C_word)a,a+=3,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7800,a[2]=((C_word)li208),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:704: chicken.base#getter-with-setter */
t11=*((C_word*)lf[476]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t11;
av2[1]=t8;
av2[2]=t9;
av2[3]=t10;
av2[4]=lf[477];
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}

/* chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5483,c,av);}
a=C_alloc(7);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5490,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnump(t2))){
t6=t5;
f_5490(t6,C_getpwuid(t2));}
else{
t6=C_i_check_string_2(t2,lf[352]);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5529,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:656: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t7;
av2[2]=t2;
av2[3]=lf[352];
tp(4,av2);}}}

/* k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_5490(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_5490,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(C_truep(((C_word*)t0)[2])?*((C_word*)lf[349]+1):*((C_word*)lf[350]+1));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5503,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* ##sys#peek-nonnull-c-string */
t4=*((C_word*)lf[351]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_user->pw_name);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5501 in k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5503(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5503,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5507,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* ##sys#peek-nonnull-c-string */
t3=*((C_word*)lf[351]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_user->pw_passwd);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5505 in k5501 in k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5507(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5507,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5511,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* ##sys#peek-nonnull-c-string */
t3=*((C_word*)lf[351]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_PW_GECOS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5509 in k5505 in k5501 in k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_5511,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5515,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_user->pw_dir);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5513 in k5509 in k5505 in k5501 in k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_5515,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5519,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_user->pw_shell);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5517 in k5513 in k5509 in k5505 in k5501 in k5488 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_5519,c,av);}
/* posixunix.scm:657: g1610 */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=C_fix((C_word)C_user->pw_uid);
av2[5]=C_fix((C_word)C_user->pw_gid);
av2[6]=((C_word*)t0)[6];
av2[7]=((C_word*)t0)[7];
av2[8]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(9,av2);}}

/* k5527 in chicken.process-context.posix#user-information in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5529,c,av);}
t2=((C_word*)t0)[2];
f_5490(t2,C_getpwnam(t1));}

/* chicken.process-context.posix#current-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5537,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5545,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5549,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:670: chicken.process-context.posix#current-user-id */
t4=*((C_word*)lf[177]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5543 in chicken.process-context.posix#current-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5545,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_car(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5547 in chicken.process-context.posix#current-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5549,c,av);}
/* posixunix.scm:669: chicken.process-context.posix#user-information */
t2=*((C_word*)lf[184]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* chicken.process-context.posix#current-effective-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5551,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5559,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5563,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:675: chicken.process-context.posix#current-effective-user-id */
t4=*((C_word*)lf[175]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5557 in chicken.process-context.posix#current-effective-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5559,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_car(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5561 in chicken.process-context.posix#current-effective-user-name in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5563,c,av);}
/* posixunix.scm:674: chicken.process-context.posix#user-information */
t2=*((C_word*)lf[184]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_5565(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_5565,5,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5569,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t4,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:679: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t6;
av2[2]=t4;
av2[3]=t2;
tp(4,av2);}}

/* k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5569,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5572,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:680: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k5570 in k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_5572,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5575,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5587,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:682: chicken.base#port? */
t4=*((C_word*)lf[197]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k5573 in k5570 in k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_5575,c,av);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
/* posixunix.scm:693: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[353];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[5];
av2[7]=((C_word*)t0)[6];
f_3009(8,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5585 in k5570 in k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_5587,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5591,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:683: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[5]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fchown(((C_word*)t0)[5],((C_word*)t0)[3],((C_word*)t0)[4]);
f_5575(2,av2);}}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[5]))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5607,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:688: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}
else{
/* posixunix.scm:689: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[195];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[354];
av2[5]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}}

/* k5589 in k5585 in k5570 in k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5591(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5591,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fchown(t1,((C_word*)t0)[3],((C_word*)t0)[4]);
f_5575(2,av2);}}

/* k5605 in k5585 in k5570 in k5567 in chicken.posix#chown in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5607,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_chown(t1,((C_word*)t0)[3],((C_word*)t0)[4]);
f_5575(2,av2);}}

/* chicken.process-context.posix#create-session in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5612(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5612,c,av);}
a=C_alloc(7);
t2=C_setsid(C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5616,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t2,C_fix(0)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5626,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:699: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t4;
tp(2,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k5614 in chicken.process-context.posix#create-session in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5616,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5624 in chicken.process-context.posix#create-session in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5626,c,av);}
/* posixunix.scm:699: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[356];
av2[4]=lf[357];
tp(5,av2);}}

/* k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5630(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5630,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[183]+1 /* (set! chicken.process-context.posix#process-group-id ...) */,t1);
t3=C_mutate((C_word*)lf[3]+1 /* (set! chicken.file.posix#create-symbolic-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5632,a[2]=((C_word)li123),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5661,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t4;
av2[2]=C_fixnum_plus(C_fix((C_word)FILENAME_MAX),C_fix(1));
av2[3]=C_make_character(32);
tp(4,av2);}}

/* chicken.file.posix#create-symbolic-link in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5632,c,av);}
a=C_alloc(5);
t4=C_i_check_string_2(t2,lf[358]);
t5=C_i_check_string_2(t3,lf[358]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5653,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:730: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=lf[358];
tp(4,av2);}}

/* k5651 in chicken.file.posix#create-symbolic-link in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5653(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5653,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5657,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:731: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[358];
tp(4,av2);}}

/* k5655 in k5651 in chicken.file.posix#create-symbolic-link in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5657,c,av);}
if(C_truep(C_fixnum_lessp(C_symlink(((C_word*)t0)[2],t1),C_fix(0)))){
/* posixunix.scm:733: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[358];
av2[4]=lf[359];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[5];
f_3009(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word t43;
C_word t44;
C_word t45;
C_word t46;
C_word t47;
C_word t48;
C_word t49;
C_word t50;
C_word t51;
C_word t52;
C_word t53;
C_word t54;
C_word t55;
C_word t56;
C_word t57;
C_word t58;
C_word t59;
C_word t60;
C_word t61;
C_word t62;
C_word t63;
C_word t64;
C_word t65;
C_word t66;
C_word t67;
C_word t68;
C_word t69;
C_word t70;
C_word t71;
C_word t72;
C_word t73;
C_word t74;
C_word t75;
C_word t76;
C_word t77;
C_word t78;
C_word t79;
C_word t80;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(132,c,9)))){
C_save_and_reclaim((void *)f_5661,c,av);}
a=C_alloc(132);
t2=C_mutate((C_word*)lf[360]+1 /* (set! ##sys#read-symbolic-link ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5662,a[2]=t1,a[3]=((C_word)li124),tmp=(C_word)a,a+=4,tmp));
t3=C_mutate((C_word*)lf[4]+1 /* (set! chicken.file.posix#read-symbolic-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5681,a[2]=((C_word)li128),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[15]+1 /* (set! chicken.file.posix#file-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5796,a[2]=((C_word)li129),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[374]+1 /* (set! ##sys#custom-input-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5818,a[2]=((C_word)li144),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[388]+1 /* (set! ##sys#custom-output-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6331,a[2]=((C_word)li153),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[26]+1 /* (set! chicken.file.posix#file-truncate ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6586,a[2]=((C_word)li154),tmp=(C_word)a,a+=3,tmp));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6631,a[2]=((C_word)li155),tmp=(C_word)a,a+=3,tmp);
t9=C_mutate((C_word*)lf[16]+1 /* (set! chicken.file.posix#file-lock ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6717,a[2]=t8,a[3]=((C_word)li157),tmp=(C_word)a,a+=4,tmp));
t10=C_mutate((C_word*)lf[17]+1 /* (set! chicken.file.posix#file-lock/blocking ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6748,a[2]=t8,a[3]=((C_word)li159),tmp=(C_word)a,a+=4,tmp));
t11=C_mutate((C_word*)lf[25]+1 /* (set! chicken.file.posix#file-test-lock ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6779,a[2]=t8,a[3]=((C_word)li160),tmp=(C_word)a,a+=4,tmp));
t12=C_mutate((C_word*)lf[27]+1 /* (set! chicken.file.posix#file-unlock ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6806,a[2]=((C_word)li162),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[2]+1 /* (set! chicken.file.posix#create-fifo ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6849,a[2]=((C_word)li163),tmp=(C_word)a,a+=3,tmp));
t14=C_fix((C_word)sizeof(struct tm));
t15=C_mutate((C_word*)lf[84]+1 /* (set! chicken.time.posix#string->time ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6895,a[2]=t14,a[3]=((C_word)li164),tmp=(C_word)a,a+=4,tmp));
t16=C_fix((C_word)sizeof(struct tm));
t17=C_mutate((C_word*)lf[80]+1 /* (set! chicken.time.posix#utc-time->seconds ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6932,a[2]=t16,a[3]=((C_word)li165),tmp=(C_word)a,a+=4,tmp));
t18=C_mutate((C_word*)lf[86]+1 /* (set! chicken.time.posix#local-timezone-abbreviation ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6951,a[2]=((C_word)li166),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[132]+1 /* (set! chicken.process.signal#set-alarm! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6958,a[2]=((C_word)li167),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[108]+1 /* (set! chicken.process#process-fork ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6967,a[2]=((C_word)li171),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[107]+1 /* (set! chicken.process#process-execute ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7066,a[2]=((C_word)li174),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate(&lf[282] /* (set! chicken.posix#process-wait-impl ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7144,a[2]=((C_word)li176),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate((C_word*)lf[179]+1 /* (set! chicken.process-context.posix#parent-process-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7182,a[2]=((C_word)li177),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[110]+1 /* (set! chicken.process#process-signal ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7185,a[2]=((C_word)li178),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate((C_word*)lf[109]+1 /* (set! chicken.process#process-run ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7225,a[2]=((C_word)li179),tmp=(C_word)a,a+=3,tmp));
t26=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7279,a[2]=((C_word)li183),tmp=(C_word)a,a+=3,tmp);
t27=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7316,a[2]=((C_word)li186),tmp=(C_word)a,a+=3,tmp);
t28=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7336,a[2]=((C_word)li187),tmp=(C_word)a,a+=3,tmp);
t29=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7348,a[2]=((C_word)li188),tmp=(C_word)a,a+=3,tmp);
t30=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7377,a[2]=t29,a[3]=t27,a[4]=((C_word)li190),tmp=(C_word)a,a+=5,tmp);
t31=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7422,a[2]=t28,a[3]=((C_word)li191),tmp=(C_word)a,a+=4,tmp);
t32=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7433,a[2]=t28,a[3]=((C_word)li192),tmp=(C_word)a,a+=4,tmp);
t33=C_mutate(&lf[424] /* (set! chicken.posix#process-impl ...) */,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7444,a[2]=t30,a[3]=t31,a[4]=t26,a[5]=t32,a[6]=((C_word)li195),tmp=(C_word)a,a+=7,tmp));
t34=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7500,a[2]=((C_word)li200),tmp=(C_word)a,a+=3,tmp);
t35=C_mutate((C_word*)lf[122]+1 /* (set! chicken.process#process ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7571,a[2]=t34,a[3]=((C_word)li202),tmp=(C_word)a,a+=4,tmp));
t36=C_mutate((C_word*)lf[123]+1 /* (set! chicken.process#process* ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7637,a[2]=t34,a[3]=((C_word)li203),tmp=(C_word)a,a+=4,tmp));
t37=C_mutate((C_word*)lf[173]+1 /* (set! chicken.process-context.posix#set-root-directory! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7707,a[2]=((C_word)li204),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[111]+1 /* (set! chicken.process#process-spawn ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7726,a[2]=((C_word)li205),tmp=(C_word)a,a+=3,tmp));
t39=C_a_i_provide(&a,1,lf[430]);
t40=C_mutate((C_word*)lf[431]+1 /* (set! chicken.errno#errno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7732,a[2]=((C_word)li206),tmp=(C_word)a,a+=3,tmp));
t41=C_set_block_item(lf[433] /* chicken.errno#errno/2big */,0,C_fix((C_word)E2BIG));
t42=C_set_block_item(lf[434] /* chicken.errno#errno/acces */,0,C_fix((C_word)EACCES));
t43=C_set_block_item(lf[435] /* chicken.errno#errno/again */,0,C_fix((C_word)EAGAIN));
t44=C_set_block_item(lf[436] /* chicken.errno#errno/badf */,0,C_fix((C_word)EBADF));
t45=C_set_block_item(lf[437] /* chicken.errno#errno/busy */,0,C_fix((C_word)EBUSY));
t46=C_set_block_item(lf[438] /* chicken.errno#errno/child */,0,C_fix((C_word)ECHILD));
t47=C_set_block_item(lf[439] /* chicken.errno#errno/deadlk */,0,C_fix((C_word)EDEADLK));
t48=C_set_block_item(lf[440] /* chicken.errno#errno/dom */,0,C_fix((C_word)EDOM));
t49=C_set_block_item(lf[441] /* chicken.errno#errno/exist */,0,C_fix((C_word)EEXIST));
t50=C_set_block_item(lf[442] /* chicken.errno#errno/fault */,0,C_fix((C_word)EFAULT));
t51=C_set_block_item(lf[443] /* chicken.errno#errno/fbig */,0,C_fix((C_word)EFBIG));
t52=C_set_block_item(lf[444] /* chicken.errno#errno/ilseq */,0,C_fix((C_word)EILSEQ));
t53=C_set_block_item(lf[445] /* chicken.errno#errno/intr */,0,C_fix((C_word)EINTR));
t54=C_set_block_item(lf[446] /* chicken.errno#errno/inval */,0,C_fix((C_word)EINVAL));
t55=C_set_block_item(lf[447] /* chicken.errno#errno/io */,0,C_fix((C_word)EIO));
t56=C_set_block_item(lf[448] /* chicken.errno#errno/isdir */,0,C_fix((C_word)EISDIR));
t57=C_set_block_item(lf[449] /* chicken.errno#errno/mfile */,0,C_fix((C_word)EMFILE));
t58=C_set_block_item(lf[450] /* chicken.errno#errno/mlink */,0,C_fix((C_word)EMLINK));
t59=C_set_block_item(lf[451] /* chicken.errno#errno/nametoolong */,0,C_fix((C_word)ENAMETOOLONG));
t60=C_set_block_item(lf[452] /* chicken.errno#errno/nfile */,0,C_fix((C_word)ENFILE));
t61=C_set_block_item(lf[453] /* chicken.errno#errno/nodev */,0,C_fix((C_word)ENODEV));
t62=C_set_block_item(lf[454] /* chicken.errno#errno/noent */,0,C_fix((C_word)ENOENT));
t63=C_set_block_item(lf[455] /* chicken.errno#errno/noexec */,0,C_fix((C_word)ENOEXEC));
t64=C_set_block_item(lf[456] /* chicken.errno#errno/nolck */,0,C_fix((C_word)ENOLCK));
t65=C_set_block_item(lf[457] /* chicken.errno#errno/nomem */,0,C_fix((C_word)ENOMEM));
t66=C_set_block_item(lf[458] /* chicken.errno#errno/nospc */,0,C_fix((C_word)ENOSPC));
t67=C_set_block_item(lf[459] /* chicken.errno#errno/nosys */,0,C_fix((C_word)ENOSYS));
t68=C_set_block_item(lf[460] /* chicken.errno#errno/notdir */,0,C_fix((C_word)ENOTDIR));
t69=C_set_block_item(lf[461] /* chicken.errno#errno/notempty */,0,C_fix((C_word)ENOTEMPTY));
t70=C_set_block_item(lf[462] /* chicken.errno#errno/notty */,0,C_fix((C_word)ENOTTY));
t71=C_set_block_item(lf[463] /* chicken.errno#errno/nxio */,0,C_fix((C_word)ENXIO));
t72=C_set_block_item(lf[464] /* chicken.errno#errno/perm */,0,C_fix((C_word)EPERM));
t73=C_set_block_item(lf[465] /* chicken.errno#errno/pipe */,0,C_fix((C_word)EPIPE));
t74=C_set_block_item(lf[466] /* chicken.errno#errno/range */,0,C_fix((C_word)ERANGE));
t75=C_set_block_item(lf[467] /* chicken.errno#errno/rofs */,0,C_fix((C_word)EROFS));
t76=C_set_block_item(lf[468] /* chicken.errno#errno/spipe */,0,C_fix((C_word)ESPIPE));
t77=C_set_block_item(lf[469] /* chicken.errno#errno/srch */,0,C_fix((C_word)ESRCH));
t78=C_set_block_item(lf[470] /* chicken.errno#errno/wouldblock */,0,C_fix((C_word)EWOULDBLOCK));
t79=C_set_block_item(lf[471] /* chicken.errno#errno/xdev */,0,C_fix((C_word)EXDEV));
t80=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t80;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t80+1)))(2,av2);}}

/* ##sys#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5662,c,av);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5667,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:742: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=t3;
tp(4,av2);}}

/* k5665 in ##sys#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5667,c,av);}
t2=C_do_readlink(t1,((C_word*)t0)[2]);
if(C_truep(C_fixnum_lessp(t2,C_fix(0)))){
/* posixunix.scm:744: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[361];
av2[5]=((C_word*)t0)[5];
f_3009(6,av2);}}
else{
/* posixunix.scm:745: scheme#substring */
t3=*((C_word*)lf[362]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(0);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_5681,c,av);}
a=C_alloc(7);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_string_2(t2,lf[363]);
if(C_truep(t4)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5696,a[2]=t2,a[3]=((C_word)li125),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5702,a[2]=((C_word)li127),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:751: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t6;
av2[3]=t7;
C_call_with_values(4,av2);}}
else{
/* posixunix.scm:766: ##sys#read-symbolic-link */
t6=*((C_word*)lf[360]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[363];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* a5695 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5696,c,av);}
/* posixunix.scm:751: chicken.pathname#decompose-directory */
t2=*((C_word*)lf[364]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5702,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5710,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(C_truep(t2)?t2:lf[369]);
if(C_truep(t3)){
/* posixunix.scm:753: scheme#string-append */
t7=*((C_word*)lf[104]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
/* posixunix.scm:753: scheme#string-append */
t7=*((C_word*)lf[104]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=lf[370];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5710,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5712,a[2]=t3,a[3]=((C_word)li126),tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_5712(t5,((C_word*)t0)[2],((C_word*)t0)[3],t1);}

/* loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_5712(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5712,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5722,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:756: chicken.pathname#make-pathname */
t5=*((C_word*)lf[365]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_5722,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5728,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:757: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[368]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[368]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[363];
tp(6,av2);}}

/* k5726 in k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_5728,c,av);}
a=C_alloc(13);
if(C_truep(t1)){
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5737,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5740,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:759: chicken.file.posix#symbolic-link? */
t5=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
/* posixunix.scm:765: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[191];
av2[3]=lf[363];
av2[4]=lf[367];
av2[5]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k5735 in k5726 in k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5737,c,av);}
/* posixunix.scm:758: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_5712(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k5738 in k5726 in k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5740,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5743,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:760: ##sys#read-symbolic-link */
t3=*((C_word*)lf[360]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=lf[363];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* posixunix.scm:758: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_5712(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[7]);}}

/* k5741 in k5738 in k5726 in k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5743,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5749,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:761: chicken.pathname#absolute-pathname? */
t3=*((C_word*)lf[366]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5747 in k5741 in k5738 in k5726 in k5720 in loop in k5708 in a5701 in chicken.file.posix#read-symbolic-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5749,c,av);}
if(C_truep(t1)){
/* posixunix.scm:758: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_5712(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
/* posixunix.scm:763: chicken.pathname#make-pathname */
t2=*((C_word*)lf[365]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[6];
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k5781 in chicken.file.posix#file-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5783,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5787,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:769: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[4]);
tp(3,av2);}}

/* k5785 in k5781 in chicken.file.posix#file-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5787,c,av);}
if(C_truep(C_fixnum_lessp(stub1673(C_SCHEME_UNDEFINED,((C_word*)t0)[2],t1),C_fix(0)))){
/* posixunix.scm:774: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[372];
av2[4]=lf[373];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[5];
f_3009(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.file.posix#file-link in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5796(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5796,c,av);}
a=C_alloc(5);
t4=C_i_check_string_2(t2,lf[371]);
t5=C_i_check_string_2(t3,lf[371]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5783,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:769: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t6;
av2[2]=C_i_foreign_string_argumentp(t2);
tp(3,av2);}}

/* ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_5818,c,av);}
a=C_alloc(9);
t5=C_rest_nullp(c,5);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,5,t0));
t7=C_rest_nullp(c,5);
t8=C_rest_nullp(c,6);
t9=(C_truep(t8)?C_fix(1):C_get_rest_arg(c,6,av,5,t0));
t10=C_rest_nullp(c,6);
t11=C_rest_nullp(c,7);
t12=(C_truep(t11)?*((C_word*)lf[375]+1):C_get_rest_arg(c,7,av,5,t0));
t13=C_rest_nullp(c,7);
t14=C_rest_nullp(c,8);
t15=(C_truep(t14)?C_SCHEME_FALSE:C_get_rest_arg(c,8,av,5,t0));
t16=C_rest_nullp(c,8);
t17=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5846,a[2]=t9,a[3]=t2,a[4]=t4,a[5]=t3,a[6]=t15,a[7]=t1,a[8]=t12,tmp=(C_word)a,a+=9,tmp);
if(C_truep(t6)){
/* posixunix.scm:779: ##sys#file-nonblocking! */
t18=*((C_word*)lf[315]+1);{
C_word *av2=av;
av2[0]=t18;
av2[1]=t17;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t18+1)))(3,av2);}}
else{
t18=t17;{
C_word *av2=av;
av2[0]=t18;
av2[1]=C_SCHEME_UNDEFINED;
f_5846(2,av2);}}}

/* k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_5846,c,av);}
a=C_alloc(9);
t2=C_fixnump(((C_word*)t0)[2]);
t3=(C_truep(t2)?((C_word*)t0)[2]:C_block_size(((C_word*)t0)[2]));
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5852,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t3,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
/* posixunix.scm:781: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
f_5852(2,av2);}}}

/* k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(80,c,8)))){
C_save_and_reclaim((void *)f_5852,c,av);}
a=C_alloc(80);
t2=C_fix(0);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_fix(0);
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5853,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li130),tmp=(C_word)a,a+=6,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5882,a[2]=t5,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5890,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[6],a[8]=t3,a[9]=t5,a[10]=((C_word)li132),tmp=(C_word)a,a+=11,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5986,a[2]=t10,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5992,a[2]=t7,a[3]=t5,a[4]=t3,a[5]=t8,a[6]=((C_word)li133),tmp=(C_word)a,a+=7,tmp);
t13=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6017,a[2]=t5,a[3]=t3,a[4]=t6,a[5]=((C_word)li134),tmp=(C_word)a,a+=6,tmp);
t14=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6029,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word)li135),tmp=(C_word)a,a+=7,tmp);
t15=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6045,a[2]=t7,a[3]=t5,a[4]=t3,a[5]=t8,a[6]=((C_word)li136),tmp=(C_word)a,a+=7,tmp);
t16=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6060,a[2]=t5,a[3]=t3,a[4]=t1,a[5]=t8,a[6]=((C_word)li138),tmp=(C_word)a,a+=7,tmp);
t17=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6136,a[2]=t5,a[3]=t3,a[4]=t1,a[5]=t8,a[6]=((C_word)li142),tmp=(C_word)a,a+=7,tmp);
t18=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6255,a[2]=t5,a[3]=t3,a[4]=t1,a[5]=((C_word)li143),tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:831: chicken.port#make-input-port */
t19=*((C_word*)lf[387]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t19;
av2[1]=t11;
av2[2]=t12;
av2[3]=t13;
av2[4]=t14;
av2[5]=t15;
av2[6]=t16;
av2[7]=t17;
av2[8]=t18;
((C_proc)(void*)(*((C_word*)t19+1)))(9,av2);}}

/* ready? in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_5853(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5853,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5857,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:786: ##sys#file-select-one */
t3=*((C_word*)lf[316]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5855 in ready? in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5857,c,av);}
t2=C_eqp(C_fix(-1),t1);
if(C_truep(t2)){
t3=C_eqp(C_fix((C_word)errno),C_fix((C_word)EWOULDBLOCK));
t4=(C_truep(t3)?t3:C_eqp(C_fix((C_word)errno),C_fix((C_word)EAGAIN)));
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* posixunix.scm:791: posix-error */
t5=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[376];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[5];
f_3009(7,av2);}}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_eqp(C_fix(1),t1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* peek in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static C_word C_fcall f_5882(C_word t0){
C_word tmp;
C_word t1;
C_word t2;
C_stack_overflow_check;{}
t1=C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
return((C_truep(t1)?C_SCHEME_END_OF_FILE:C_subchar(((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1])));}

/* fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_5890(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,2)))){
C_save_and_reclaim_args((void *)trf_5890,2,t0,t1);}
a=C_alloc(14);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5896,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word)li131),tmp=(C_word)a,a+=12,tmp));
t5=((C_word*)t3)[1];{
C_word av2[2];
av2[0]=t5;
av2[1]=t1;
f_5896(2,av2);}}

/* loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,6)))){
C_save_and_reclaim((void *)f_5896,c,av);}
a=C_alloc(11);
t2=C_read(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=C_eqp(t2,C_fix(-1));
if(C_truep(t3)){
t4=C_eqp(C_fix((C_word)errno),C_fix((C_word)EWOULDBLOCK));
t5=(C_truep(t4)?t4:C_eqp(C_fix((C_word)errno),C_fix((C_word)EAGAIN)));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5915,a[2]=((C_word*)t0)[5],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:806: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[378]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[378]+1);
av2[1]=t6;
av2[2]=*((C_word*)lf[379]+1);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[380];
tp(5,av2);}}
else{
t6=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t6)){
/* posixunix.scm:810: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[321]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[5])[1];
tp(3,av2);}}
else{
/* posixunix.scm:811: posix-error */
t7=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t7;
av2[1]=t1;
av2[2]=lf[191];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[381];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[7];
f_3009(7,av2);}}}}
else{
t4=(C_truep(((C_word*)t0)[8])?C_eqp(t2,C_fix(0)):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5948,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
/* posixunix.scm:815: more? */
t6=((C_word*)t0)[8];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)C_fast_retrieve_proc(t6))(2,av2);}}
else{
t5=C_mutate(((C_word *)((C_word*)t0)[9])+1,t2);
t6=C_set_block_item(((C_word*)t0)[10],0,C_fix(0));
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}

/* k5913 in loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5915,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5918,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:807: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[377]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[377]+1);
av2[1]=t2;
tp(2,av2);}}

/* k5916 in k5913 in loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5918,c,av);}
/* posixunix.scm:808: loop */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_5896(2,av2);}}

/* k5946 in loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,6)))){
C_save_and_reclaim((void *)f_5948,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5951,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:817: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[377]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[377]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_read(((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5957,a[2]=((C_word*)t0)[7],a[3]=t3,a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t5=C_eqp(((C_word*)t3)[1],C_fix(-1));
if(C_truep(t5)){
t6=C_eqp(C_fix((C_word)errno),C_fix((C_word)EWOULDBLOCK));
t7=(C_truep(t6)?t6:C_eqp(C_fix((C_word)errno),C_fix((C_word)EAGAIN)));
if(C_truep(t7)){
t8=C_set_block_item(t3,0,C_fix(0));
t9=C_mutate(((C_word *)((C_word*)t0)[7])+1,((C_word*)t3)[1]);
t10=C_set_block_item(((C_word*)t0)[8],0,C_fix(0));
t11=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
/* posixunix.scm:824: posix-error */
t8=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t8;
av2[1]=t4;
av2[2]=lf[191];
av2[3]=((C_word*)t0)[9];
av2[4]=lf[382];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[10];
f_3009(7,av2);}}}
else{
t6=C_mutate(((C_word *)((C_word*)t0)[7])+1,((C_word*)t3)[1]);
t7=C_set_block_item(((C_word*)t0)[8],0,C_fix(0));
t8=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}

/* k5949 in k5946 in loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5951,c,av);}
/* posixunix.scm:818: loop */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_5896(2,av2);}}

/* k5955 in k5946 in loop in fetch in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5957(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5957,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=C_set_block_item(((C_word*)t0)[4],0,C_fix(0));
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5984 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5986,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(3),((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a5991 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5992,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5996,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1]))){
/* posixunix.scm:834: fetch */
t3=((C_word*)t0)[5];
f_5890(t3,t2);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5996(2,av2);}}}

/* k5994 in a5991 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_5996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5996,c,av);}
t2=(
/* posixunix.scm:835: peek */
  f_5882(((C_word*)t0)[2])
);
if(C_truep(C_eofp(t2))){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_fixnum_plus(((C_word*)((C_word*)t0)[4])[1],C_fix(1));
t4=C_set_block_item(((C_word*)t0)[4],0,t3);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* a6016 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6017,c,av);}
t2=C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
if(C_truep(t2)){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* posixunix.scm:840: ready? */
t3=((C_word*)t0)[4];
f_5853(t3,t1);}}

/* a6028 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,6)))){
C_save_and_reclaim((void *)f_6029,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6033,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(C_close(((C_word*)t0)[3]),C_fix(0)))){
/* posixunix.scm:843: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[383];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[5];
f_3009(7,av2);}}
else{
/* posixunix.scm:844: on-close */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}}

/* k6031 in a6028 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6033,c,av);}
/* posixunix.scm:844: on-close */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a6044 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6045,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6049,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1]))){
/* posixunix.scm:847: fetch */
t3=((C_word*)t0)[5];
f_5890(t3,t2);}
else{
/* posixunix.scm:848: peek */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
/* posixunix.scm:848: peek */
  f_5882(((C_word*)t0)[2])
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6047 in a6044 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6049,c,av);}
/* posixunix.scm:848: peek */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* posixunix.scm:848: peek */
  f_5882(((C_word*)t0)[3])
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a6059 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_6060,c,av);}
a=C_alloc(11);
t6=(C_truep(t3)?t3:C_fixnum_difference(C_block_size(t4),t5));
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6070,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=t8,a[7]=((C_word*)t0)[5],a[8]=((C_word)li137),tmp=(C_word)a,a+=9,tmp));
t10=((C_word*)t8)[1];
f_6070(t10,t1,t6,C_fix(0),t5);}

/* loop in a6059 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_6070(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_6070,5,t0,t1,t2,t3,t4);}
a=C_alloc(8);
t5=C_eqp(C_fix(0),t2);
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t6=C_fixnum_difference(((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[2])[1]);
t7=C_fixnum_lessp(t2,t6);
t8=(C_truep(t7)?t2:t6);
t9=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],t8);
t10=C_substring_copy(((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)((C_word*)t0)[2])[1],t9,t4);
t11=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],t8);
t12=C_set_block_item(((C_word*)t0)[2],0,t11);
/* posixunix.scm:857: loop */
t14=t1;
t15=C_fixnum_difference(t2,t8);
t16=C_fixnum_plus(t3,t8);
t17=C_fixnum_plus(t4,t8);
t1=t14;
t2=t15;
t3=t16;
t4=t17;
goto loop;}
else{
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6118,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=t4,tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:859: fetch */
t7=((C_word*)t0)[7];
f_5890(t7,t6);}}}

/* k6116 in loop in a6059 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6118,c,av);}
t2=C_eqp(C_fix(0),((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* posixunix.scm:862: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_6070(t3,((C_word*)t0)[3],((C_word*)t0)[6],((C_word*)t0)[4],((C_word*)t0)[7]);}}

/* a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6136,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6140,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=t2,tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
/* posixunix.scm:865: fetch */
t5=((C_word*)t0)[5];
f_5890(t5,t4);}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_6140(2,av2);}}}

/* k6138 in a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_6140,c,av);}
a=C_alloc(15);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(C_truep(((C_word*)t0)[5])?((C_word*)t0)[5]:C_fixnum_difference(*((C_word*)lf[384]+1),((C_word*)((C_word*)t0)[2])[1]));
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6154,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word)li140),tmp=(C_word)a,a+=8,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6210,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[2],a[4]=((C_word)li141),tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:869: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}}

/* a6153 in k6138 in a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6154(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_6154,c,av);}
a=C_alloc(8);
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
t3=C_i_fixnum_min(((C_word*)((C_word*)t0)[4])[1],t2);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6164,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li139),tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:870: ##sys#scan-buffer-line */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[385]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[385]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[5];
av2[3]=t3;
av2[4]=((C_word*)((C_word*)t0)[2])[1];
av2[5]=t4;
tp(6,av2);}}

/* a6163 in a6153 in k6138 in a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6164(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_6164,c,av);}
a=C_alloc(7);
t3=C_fixnum_difference(t2,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)((C_word*)t0)[3])[1]))){
/* posixunix.scm:877: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=t2;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}
else{
t4=C_fixnum_difference(((C_word*)((C_word*)t0)[3])[1],t3);
t5=C_set_block_item(((C_word*)t0)[3],0,t4);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6184,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:880: fetch */
t7=((C_word*)t0)[6];
f_5890(t7,t6);}}

/* k6182 in a6163 in a6153 in k6138 in a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6184,c,av);}
if(C_truep(C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[4])[1]);
/* posixunix.scm:882: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)((C_word*)t0)[2])[1];
av2[4]=C_i_fixnum_min(((C_word*)((C_word*)t0)[3])[1],t2);
C_values(5,av2);}}
else{
/* posixunix.scm:885: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)((C_word*)t0)[2])[1];
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}}

/* a6209 in k6138 in a6135 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6210,c,av);}
if(C_truep(t4)){
t5=C_slot(((C_word*)t0)[2],C_fix(4));
t6=C_fixnum_plus(t5,C_fix(1));
t7=C_i_set_i_slot(((C_word*)t0)[2],C_fix(4),t6);
t8=C_i_set_i_slot(((C_word*)t0)[2],C_fix(5),C_fix(0));
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t5=C_slot(((C_word*)t0)[2],C_fix(5));
t6=C_block_size(t3);
t7=C_fixnum_plus(t5,t6);
t8=C_i_set_i_slot(((C_word*)t0)[2],C_fix(5),t7);
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}

/* a6254 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6255,c,av);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[386];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6265,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:898: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[263]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[263]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)((C_word*)t0)[2])[1];
av2[4]=((C_word*)((C_word*)t0)[3])[1];
tp(5,av2);}}}

/* k6263 in a6254 in k5850 in k5844 in ##sys#custom-input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6265(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6265,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6331,c,av);}
a=C_alloc(8);
t5=C_rest_nullp(c,5);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,5,t0));
t7=C_rest_nullp(c,5);
t8=C_rest_nullp(c,6);
t9=(C_truep(t8)?C_fix(0):C_get_rest_arg(c,6,av,5,t0));
t10=C_rest_nullp(c,6);
t11=C_rest_nullp(c,7);
t12=(C_truep(t11)?*((C_word*)lf[375]+1):C_get_rest_arg(c,7,av,5,t0));
t13=C_rest_nullp(c,7);
t14=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6353,a[2]=t4,a[3]=t2,a[4]=t3,a[5]=t9,a[6]=t1,a[7]=t12,tmp=(C_word)a,a+=8,tmp);
if(C_truep(t6)){
/* posixunix.scm:907: ##sys#file-nonblocking! */
t15=*((C_word*)lf[315]+1);{
C_word *av2=av;
av2[0]=t15;
av2[1]=t14;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t15+1)))(3,av2);}}
else{
t15=t14;{
C_word *av2=av;
av2[0]=t15;
av2[1]=C_SCHEME_UNDEFINED;
f_6353(2,av2);}}}

/* k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,4)))){
C_save_and_reclaim((void *)f_6353,c,av);}
a=C_alloc(26);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6354,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li146),tmp=(C_word)a,a+=7,tmp);
t7=C_fixnump(((C_word*)t0)[5]);
t8=(C_truep(t7)?((C_word*)t0)[5]:C_block_size(((C_word*)t0)[5]));
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6420,a[2]=t3,a[3]=t6,a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[2],a[9]=((C_word*)t0)[3],tmp=(C_word)a,a+=10,tmp);
t10=C_eqp(C_fix(0),t8);
if(C_truep(t10)){
t11=t9;
f_6420(t11,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6461,a[2]=t3,a[3]=((C_word)li150),tmp=(C_word)a,a+=4,tmp));}
else{
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6475,a[2]=t9,a[3]=t8,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnump(((C_word*)t0)[5]))){
/* posixunix.scm:930: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t11;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}
else{
t12=t11;{
C_word *av2=av;
av2[0]=t12;
av2[1]=((C_word*)t0)[5];
f_6475(2,av2);}}}}

/* poke1820 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6354,c,av);}
a=C_alloc(12);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6360,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[3],a[6]=t5,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word)li145),tmp=(C_word)a,a+=10,tmp));
t7=((C_word*)t5)[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
f_6360(2,av2);}}

/* loop in poke1820 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_6360,c,av);}
a=C_alloc(6);
t2=C_write(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=C_eqp(C_fix(-1),t2);
if(C_truep(t3)){
t4=C_eqp(C_fix((C_word)errno),C_fix((C_word)EWOULDBLOCK));
t5=(C_truep(t4)?t4:C_eqp(C_fix((C_word)errno),C_fix((C_word)EAGAIN)));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6379,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:916: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[377]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[377]+1);
av2[1]=t6;
tp(2,av2);}}
else{
t6=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t6)){
/* posixunix.scm:919: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[321]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
tp(3,av2);}}
else{
/* posixunix.scm:921: posix-error */
t7=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t7;
av2[1]=t1;
av2[2]=((C_word*)t0)[7];
av2[3]=lf[191];
av2[4]=lf[389];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[8];
f_3009(7,av2);}}}}
else{
if(C_truep(C_fixnum_lessp(t2,((C_word*)t0)[4]))){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6410,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:923: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[263]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[263]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* k6377 in loop in poke1820 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6379,c,av);}
/* posixunix.scm:917: poke */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k6408 in loop in poke1820 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6410,c,av);}
/* posixunix.scm:923: poke */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_fixnum_difference(((C_word*)t0)[4],((C_word*)t0)[5]);
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_6420(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,4)))){
C_save_and_reclaim_args((void *)trf_6420,2,t0,t1);}
a=C_alloc(22);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,t1);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6425,a[2]=t5,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6431,a[2]=((C_word*)t0)[4],a[3]=((C_word)li147),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6437,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[5],a[6]=((C_word)li148),tmp=(C_word)a,a+=7,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6453,a[2]=((C_word*)t0)[4],a[3]=((C_word)li149),tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:948: chicken.port#make-output-port */
t10=*((C_word*)lf[391]+1);{
C_word av2[5];
av2[0]=t10;
av2[1]=t6;
av2[2]=t7;
av2[3]=t8;
av2[4]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}

/* k6423 in k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6425,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(3),((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a6430 in k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6431,c,av);}
/* posixunix.scm:950: store */
t3=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* a6436 in k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,6)))){
C_save_and_reclaim((void *)f_6437,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6441,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(C_close(((C_word*)t0)[3]),C_fix(0)))){
/* posixunix.scm:953: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[390];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[5];
f_3009(7,av2);}}
else{
/* posixunix.scm:954: on-close */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}}

/* k6439 in a6436 in k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6441,c,av);}
/* posixunix.scm:954: on-close */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a6452 in k6418 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6453(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6453,c,av);}
/* posixunix.scm:956: store */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* f_6461 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6461,c,av);}
if(C_truep(t2)){
/* posixunix.scm:929: poke */
t3=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_block_size(t2);
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6473 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6475,c,av);}
a=C_alloc(9);
t2=C_fix(0);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=((C_word*)t0)[2];
f_6420(t4,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6476,a[2]=((C_word*)t0)[3],a[3]=t3,a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word)li152),tmp=(C_word)a,a+=7,tmp));}

/* f_6476 in k6473 in k6351 in ##sys#custom-output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6476(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_6476,c,av);}
a=C_alloc(11);
if(C_truep(t2)){
t3=C_fixnum_difference(((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t4=C_block_size(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6493,a[2]=((C_word*)t0)[3],a[3]=t6,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t2,a[8]=((C_word)li151),tmp=(C_word)a,a+=9,tmp));
t8=((C_word*)t6)[1];
f_6493(t8,t1,t3,C_fix(0),t4);}
else{
if(C_truep(C_fixnum_lessp(C_fix(0),((C_word*)((C_word*)t0)[3])[1]))){
/* posixunix.scm:946: poke */
t3=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* loop */
static void C_fcall f_6493(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_6493,5,t0,t1,t2,t3,t4);}
a=C_alloc(7);
t5=C_eqp(C_fix(0),t2);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6503,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:936: poke */
t7=((C_word*)((C_word*)t0)[5])[1];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}
else{
if(C_truep(C_fixnum_lessp(t2,t4))){
t6=C_substring_copy(((C_word*)t0)[7],((C_word*)t0)[6],t3,t2,((C_word*)((C_word*)t0)[2])[1]);
/* posixunix.scm:941: loop */
t10=t1;
t11=C_fix(0);
t12=t2;
t13=C_fixnum_difference(t4,t2);
t1=t10;
t2=t11;
t3=t12;
t4=t13;
goto loop;}
else{
t6=C_substring_copy(((C_word*)t0)[7],((C_word*)t0)[6],t3,t4,((C_word*)((C_word*)t0)[2])[1]);
t7=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],t4);
t8=C_set_block_item(((C_word*)t0)[2],0,t7);
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}}

/* k6501 in loop */
static void C_ccall f_6503(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6503,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_fix(0));
/* posixunix.scm:938: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6493(t3,((C_word*)t0)[4],((C_word*)t0)[5],C_fix(0),((C_word*)t0)[6]);}

/* chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6586,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6590,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:965: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[392];
tp(4,av2);}}

/* k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_6590,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6596,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6603,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_stringp(((C_word*)t0)[3]))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6610,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:966: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[392];
tp(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6616,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:967: chicken.base#port? */
t5=*((C_word*)lf[197]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k6594 in k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_6596(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_6596,2,t0,t1);}
if(C_truep(t1)){
/* posixunix.scm:971: posix-error */
t2=lf[186];{
C_word av2[7];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=lf[392];
av2[4]=lf[393];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
f_3009(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6601 in k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6603,c,av);}
t2=((C_word*)t0)[2];
f_6596(t2,C_fixnum_lessp(t1,C_fix(0)));}

/* k6608 in k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6610(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6610,c,av);}
t2=((C_word*)t0)[2];
f_6596(t2,C_fixnum_lessp(C_truncate(t1,((C_word*)t0)[3]),C_fix(0)));}

/* k6614 in k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6616,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6620,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:967: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[4]))){
t2=((C_word*)t0)[2];
f_6596(t2,C_fixnum_lessp(C_ftruncate(((C_word*)t0)[4],((C_word*)t0)[3]),C_fix(0)));}
else{
/* posixunix.scm:969: ##sys#error */
t2=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[392];
av2[3]=lf[394];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}}

/* k6618 in k6614 in k6588 in chicken.file.posix#file-truncate in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6620,c,av);}
t2=((C_word*)t0)[2];
f_6596(t2,C_fixnum_lessp(C_ftruncate(t1,((C_word*)t0)[3]),C_fix(0)));}

/* setup in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_6631(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_6631,4,t1,t2,t3,t4);}
a=C_alloc(9);
t5=C_i_nullp(t3);
t6=(C_truep(t5)?C_fix(0):C_i_car(t3));
t7=C_i_nullp(t3);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_i_car(t8));
t11=t10;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_i_nullp(t8);
t14=(C_truep(t13)?C_SCHEME_END_OF_LIST:C_i_cdr(t8));
t15=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,t4);
t16=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6649,a[2]=t2,a[3]=t6,a[4]=t12,a[5]=t1,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* posixunix.scm:985: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t16;
av2[2]=t6;
av2[3]=t4;
tp(4,av2);}}

/* k6647 in setup in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6649,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_eqp(C_SCHEME_TRUE,((C_word*)((C_word*)t0)[4])[1]);
if(C_truep(t3)){
t4=C_set_block_item(((C_word*)t0)[4],0,C_fix(0));
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_6652(2,av2);}}
else{
/* posixunix.scm:988: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[215]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[215]+1);
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}}

/* k6650 in k6647 in setup in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_6652,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=C_i_nequalp(t2,C_fix(1));
t4=(C_truep(t3)?C_fix((C_word)F_RDLCK):C_fix((C_word)F_WRLCK));
t5=C_flock_setup(t4,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_record4(&a,4,lf[395],((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* chicken.file.posix#file-lock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +9,c,2)))){
C_save_and_reclaim((void*)f_6717,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+9);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6723,a[2]=t2,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=t3,a[6]=((C_word)li156),tmp=(C_word)a,a+=7,tmp));
t7=((C_word*)t5)[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
f_6723(2,av2);}}

/* loop in chicken.file.posix#file-lock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6723,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6727,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:996: setup */
f_6631(t2,((C_word*)t0)[2],((C_word*)t0)[5],lf[396]);}

/* k6725 in loop in chicken.file.posix#file-lock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6727,c,av);}
if(C_truep(C_fixnum_lessp(C_flock_lock(((C_word*)t0)[2]),C_fix(0)))){
t2=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t2)){
/* posixunix.scm:999: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[321]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)((C_word*)t0)[4])[1];
tp(3,av2);}}
else{
/* posixunix.scm:992: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[396];
av2[4]=lf[397];
av2[5]=C_slot(t1,C_fix(1));
av2[6]=C_slot(t1,C_fix(2));
av2[7]=C_slot(t1,C_fix(3));
f_3009(8,av2);}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file.posix#file-lock/blocking in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +9,c,2)))){
C_save_and_reclaim((void*)f_6748,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+9);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6754,a[2]=t2,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=t3,a[6]=((C_word)li158),tmp=(C_word)a,a+=7,tmp));
t7=((C_word*)t5)[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
f_6754(2,av2);}}

/* loop in chicken.file.posix#file-lock/blocking in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6754,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6758,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1005: setup */
f_6631(t2,((C_word*)t0)[2],((C_word*)t0)[5],lf[398]);}

/* k6756 in loop in chicken.file.posix#file-lock/blocking in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6758(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6758,c,av);}
if(C_truep(C_fixnum_lessp(C_flock_lockw(((C_word*)t0)[2]),C_fix(0)))){
t2=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t2)){
/* posixunix.scm:1008: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[321]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)((C_word*)t0)[4])[1];
tp(3,av2);}}
else{
/* posixunix.scm:992: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[398];
av2[4]=lf[399];
av2[5]=C_slot(t1,C_fix(1));
av2[6]=C_slot(t1,C_fix(2));
av2[7]=C_slot(t1,C_fix(3));
f_3009(8,av2);}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file.posix#file-test-lock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_6779,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+4);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6783,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1013: setup */
f_6631(t4,t2,t3,lf[400]);}

/* k6781 in chicken.file.posix#file-test-lock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6783,c,av);}
t2=C_flock_test(((C_word*)t0)[2]);
if(C_truep(t2)){
t3=C_eqp(t2,C_fix(0));
t4=C_i_not(t3);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?t2:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* posixunix.scm:992: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[400];
av2[4]=lf[401];
av2[5]=C_slot(t1,C_fix(1));
av2[6]=C_slot(t1,C_fix(2));
av2[7]=C_slot(t1,C_fix(3));
f_3009(8,av2);}}}

/* chicken.file.posix#file-unlock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_6806,c,av);}
a=C_alloc(4);
t3=C_i_check_structure_2(t2,lf[395],lf[402]);
t4=C_slot(t2,C_fix(2));
t5=C_slot(t2,C_fix(3));
t6=C_flock_setup(C_fix((C_word)F_UNLCK),t4,t5);
t7=C_slot(t2,C_fix(1));
if(C_truep(C_fixnum_lessp(C_flock_lock(t7),C_fix(0)))){
t8=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6835,a[2]=t2,a[3]=((C_word)li161),tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1024: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[321]+1);
av2[1]=t1;
av2[2]=t9;
tp(3,av2);}}
else{
/* posixunix.scm:1026: posix-error */
t9=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t9;
av2[1]=t1;
av2[2]=lf[191];
av2[3]=lf[402];
av2[4]=lf[403];
av2[5]=t2;
f_3009(6,av2);}}}
else{
t8=C_SCHEME_UNDEFINED;
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* a6834 in chicken.file.posix#file-unlock in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6835,c,av);}
/* posixunix.scm:1025: chicken.file.posix#file-unlock */
t2=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* chicken.file.posix#create-fifo in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_6849,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t4=C_i_check_string_2(t2,lf[404]);
t5=C_i_pairp(t3);
t6=(C_truep(t5)?C_get_rest_arg(c,3,av,3,t0):C_fixnum_or(C_fix((C_word)S_IRUSR | S_IWUSR | S_IXUSR),C_fixnum_or(C_fix((C_word)S_IRGRP | S_IWGRP | S_IXGRP),C_fix((C_word)S_IROTH | S_IWOTH | S_IXOTH))));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6859,a[2]=t6,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1035: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t7;
av2[2]=t6;
av2[3]=lf[404];
tp(4,av2);}}

/* k6857 in chicken.file.posix#create-fifo in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6859,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6873,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1036: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[404];
tp(4,av2);}}

/* k6871 in k6857 in chicken.file.posix#create-fifo in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_6873,c,av);}
if(C_truep(C_fixnum_lessp(C_mkfifo(t1,((C_word*)t0)[2]),C_fix(0)))){
/* posixunix.scm:1037: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[191];
av2[3]=lf[404];
av2[4]=lf[405];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[2];
f_3009(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.time.posix#string->time in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6895,c,av);}
a=C_alloc(5);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?lf[406]:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_string_2(t2,lf[407]);
t6=C_i_check_string_2(t4,lf[407]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6912,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1048: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t7;
av2[2]=t2;
av2[3]=lf[407];
tp(4,av2);}}

/* k6910 in chicken.time.posix#string->time in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6912,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6916,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1048: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k6914 in k6910 in chicken.time.posix#string->time in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_6916,c,av);}
a=C_alloc(17);
t2=C_a_i_vector(&a,10,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6924,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:1048: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k6922 in k6914 in k6910 in chicken.time.posix#string->time in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6924,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?stub1953(C_SCHEME_UNDEFINED,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],C_i_foreign_block_argumentp(t1)):stub1953(C_SCHEME_UNDEFINED,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],C_SCHEME_FALSE));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.time.posix#utc-time->seconds in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6932,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6936,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1053: check-time-vector */
f_3697(t3,lf[408],t2);}

/* k6934 in chicken.time.posix#utc-time->seconds in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6936,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6940,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1054: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[268]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[268]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k6938 in k6934 in chicken.time.posix#utc-time->seconds in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_6940,c,av);}
a=C_alloc(7);
t2=C_a_timegm(&a,2,((C_word*)t0)[2],t1);
if(C_truep(C_i_nequalp(C_fix(-1),t2))){
/* posixunix.scm:1056: ##sys#error */
t3=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[408];
av2[3]=lf[409];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.time.posix#local-timezone-abbreviation in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6951,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
/* posixunix.scm:1060: ##sys#peek-c-string */
t3=*((C_word*)lf[188]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=stub1980(t2);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.process.signal#set-alarm! in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6958,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub1984(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6967,c,av);}
a=C_alloc(6);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=stub2008(C_SCHEME_UNDEFINED,C_SCHEME_FALSE);
t9=stub1988(C_SCHEME_UNDEFINED);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6998,a[2]=t3,a[3]=t9,a[4]=t6,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t11=C_eqp(C_fix(-1),t9);
if(C_truep(t11)){
/* posixunix.scm:1086: posix-error */
t12=lf[186];{
C_word av2[5];
av2[0]=t12;
av2[1]=t10;
av2[2]=lf[91];
av2[3]=lf[413];
av2[4]=lf[414];
f_3009(5,av2);}}
else{
t12=t10;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_SCHEME_UNDEFINED;
f_6998(2,av2);}}}

/* k6996 in chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_6998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6998,c,av);}
a=C_alloc(7);
t2=(C_truep(((C_word*)t0)[2])?C_eqp(((C_word*)t0)[3],C_fix(0)):C_SCHEME_FALSE);
if(C_truep(t2)){
t3=(C_truep(((C_word*)t0)[4])?*((C_word*)lf[410]+1):(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7026,a[2]=((C_word)li168),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7012,a[2]=((C_word*)t0)[2],a[3]=((C_word)li170),tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1087: g2015 */
t5=t3;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[5];
av2[2]=t4;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}
else{
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a7011 in k6996 in chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7012,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7018,a[2]=((C_word*)t0)[2],a[3]=((C_word)li169),tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1092: ##sys#call-with-cthulhu */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[412]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[412]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a7017 in a7011 in k6996 in chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7018,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7022,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:1094: thunk */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k7020 in a7017 in a7011 in k6996 in chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7022,c,av);}
/* posixunix.scm:1095: chicken.base#exit */
t2=*((C_word*)lf[411]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* f_7026 in k6996 in chicken.process#process-fork in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7026,c,av);}
/* posixunix.scm:1090: thunk */
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* chicken.process#process-execute in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,7)))){
C_save_and_reclaim((void *)f_7066,c,av);}
a=C_alloc(7);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7090,a[2]=((C_word)li172),tmp=(C_word)a,a+=3,tmp);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7093,a[2]=t2,a[3]=((C_word)li173),tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1100: call-with-exec-args */
t14=lf[297];
f_4292(t14,t1,lf[415],t2,t12,t4,t7,t13);}

/* a7089 in chicken.process#process-execute in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7090,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a7092 in chicken.process#process-execute in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7093,c,av);}
t5=(C_truep(t4)?C_u_i_execve(t2,t3,t4):C_u_i_execvp(t2,t3));
t6=C_eqp(t5,C_fix(-1));
if(C_truep(t6)){
/* posixunix.scm:1107: posix-error */
t7=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t1;
av2[2]=lf[91];
av2[3]=lf[415];
av2[4]=lf[416];
av2[5]=((C_word*)t0)[2];
f_3009(6,av2);}}
else{
t7=C_SCHEME_UNDEFINED;
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* chicken.posix#process-wait-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7144(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_7144,3,t1,t2,t3);}
a=C_alloc(5);
t4=(C_truep(t3)?C_fix((C_word)WNOHANG):C_fix(0));
t5=C_waitpid(t2,t4);
t6=C_WIFEXITED(C_fix((C_word)C_wait_status));
t7=C_eqp(t5,C_fix(-1));
t8=(C_truep(t7)?C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR)):C_SCHEME_FALSE);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7160,a[2]=t2,a[3]=t3,a[4]=((C_word)li175),tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1116: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[321]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[321]+1);
av2[1]=t1;
av2[2]=t9;
tp(3,av2);}}
else{
if(C_truep(t6)){
/* posixunix.scm:1118: scheme#values */{
C_word av2[5];
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
av2[4]=C_WEXITSTATUS(C_fix((C_word)C_wait_status));
C_values(5,av2);}}
else{
if(C_truep(C_WIFSIGNALED(C_fix((C_word)C_wait_status)))){
/* posixunix.scm:1118: scheme#values */{
C_word av2[5];
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
av2[4]=C_WTERMSIG(C_fix((C_word)C_wait_status));
C_values(5,av2);}}
else{
/* posixunix.scm:1118: scheme#values */{
C_word av2[5];
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
av2[4]=C_WSTOPSIG(C_fix((C_word)C_wait_status));
C_values(5,av2);}}}}}

/* a7159 in chicken.posix#process-wait-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7160(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7160,c,av);}
/* posixunix.scm:1117: process-wait-impl */
f_7144(t1,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* chicken.process-context.posix#parent-process-id in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7182,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub2054(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#process-signal in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_7185,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=C_i_pairp(t3);
t5=(C_truep(t4)?C_get_rest_arg(c,3,av,3,t0):C_fix((C_word)SIGTERM));
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7192,a[2]=t2,a[3]=t5,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1131: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=lf[417];
tp(4,av2);}}

/* k7190 in chicken.process#process-signal in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7192,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7195,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1132: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[417];
tp(4,av2);}}

/* k7193 in k7190 in chicken.process#process-signal in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7195,c,av);}
t2=C_kill(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_eqp(t2,C_fix(-1));
if(C_truep(t3)){
/* posixunix.scm:1134: posix-error */
t4=lf[186];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[91];
av2[3]=lf[417];
av2[4]=lf[418];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[3];
f_3009(7,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* chicken.process#process-run in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_7225,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=C_i_pairp(t3);
t5=(C_truep(t4)?C_get_rest_arg(c,3,av,3,t0):C_SCHEME_FALSE);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7232,a[2]=t1,a[3]=t5,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1145: chicken.process#process-fork */
t7=*((C_word*)lf[108]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k7230 in chicken.process#process-run in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7232,c,av);}
a=C_alloc(4);
t2=C_eqp(C_fix(0),t1);
if(C_truep(C_i_not(t2))){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[3])){
/* posixunix.scm:1147: chicken.process#process-execute */
t3=*((C_word*)lf[107]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8930,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1137: chicken.process-context#get-environment-variable */
t4=*((C_word*)lf[421]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[422];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}}

/* k7273 in k7357 in connect-child in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7275,c,av);}
/* posixunix.scm:1177: chicken.file.posix#file-close */
t2=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* make-on-close in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7279(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_7279,7,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(9);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7281,a[2]=t4,a[3]=t5,a[4]=t6,a[5]=t7,a[6]=t3,a[7]=t2,a[8]=((C_word)li182),tmp=(C_word)a,a+=9,tmp);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* f_7281 in make-on-close in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_7281,c,av);}
a=C_alloc(9);
t2=C_i_vector_set(((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_TRUE);
t3=C_i_vector_ref(((C_word*)t0)[2],((C_word*)t0)[4]);
t4=(C_truep(t3)?C_i_vector_ref(((C_word*)t0)[2],((C_word*)t0)[5]):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7296,a[2]=((C_word*)t0)[6],a[3]=((C_word)li180),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7302,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[6],a[4]=((C_word)li181),tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1183: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* a7295 */
static void C_ccall f_7296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7296,c,av);}
/* posixunix.scm:1183: process-wait-impl */
f_7144(t1,((C_word*)t0)[2],C_SCHEME_FALSE);}

/* a7301 */
static void C_ccall f_7302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7302,c,av);}
if(C_truep(t3)){
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* posixunix.scm:1185: ##sys#signal-hook */
t5=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[91];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[423];
av2[5]=((C_word*)t0)[3];
av2[6]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(7,av2);}}}

/* needed-pipe in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7316(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_7316,2,t1,t2);}
a=C_alloc(6);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7325,a[2]=((C_word)li184),tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7331,a[2]=((C_word)li185),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:1190: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a7324 in needed-pipe in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7325(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7325,c,av);}
/* posixunix.scm:1190: chicken.process#create-pipe */
t2=*((C_word*)lf[117]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7330 in needed-pipe in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7331,c,av);}
a=C_alloc(3);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* connect-parent in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7336(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_7336,3,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(t3)){
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7347,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1196: chicken.file.posix#file-close */
t7=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7345 in connect-parent in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7347,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* connect-child in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7348(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7348,4,t1,t2,t3,t4);}
a=C_alloc(5);
if(C_truep(t3)){
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7359,a[2]=t4,a[3]=t5,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:1202: chicken.file.posix#file-close */
t8=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k7357 in connect-child in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7359,c,av);}
a=C_alloc(4);
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7275,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1176: chicken.file.posix#duplicate-fileno */
t4=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7377(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_7377,8,t0,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(11);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7381,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t4,a[6]=((C_word*)t0)[2],a[7]=t7,a[8]=t5,a[9]=t6,a[10]=((C_word*)t0)[3],tmp=(C_word)a,a+=11,tmp);
/* posixunix.scm:1211: needed-pipe */
f_7316(t8,t6);}

/* k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7381(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7381,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7384,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* posixunix.scm:1212: needed-pipe */
f_7316(t2,((C_word*)t0)[8]);}

/* k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7384(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7384,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7387,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* posixunix.scm:1213: needed-pipe */
f_7316(t2,((C_word*)t0)[8]);}

/* k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_7387,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7394,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
if(C_truep(((C_word*)t0)[10])){
t3=C_i_cdr(((C_word*)t0)[10]);
t4=C_u_i_car(((C_word*)t0)[10]);
t5=t2;
f_7394(t5,C_a_i_cons(&a,2,t3,t4));}
else{
t3=t2;
f_7394(t3,C_SCHEME_FALSE);}}

/* k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7394(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,0,2)))){
C_save_and_reclaim_args((void *)trf_7394,2,t0,t1);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7398,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7400,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word)li189),tmp=(C_word)a,a+=13,tmp);
/* posixunix.scm:1216: chicken.process#process-fork */
t4=*((C_word*)lf[108]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k7396 in k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7398,c,av);}
/* posixunix.scm:1214: scheme#values */{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=t1;
C_values(6,av2);}}

/* a7399 in k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_7400,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7404,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* posixunix.scm:1218: connect-child */
f_7348(t2,((C_word*)t0)[10],((C_word*)t0)[11],*((C_word*)lf[38]+1));}

/* k7402 in a7399 in k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_7404,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7407,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[9])){
t3=C_i_cdr(((C_word*)t0)[9]);
t4=C_u_i_car(((C_word*)t0)[9]);
t5=C_a_i_cons(&a,2,t3,t4);
/* posixunix.scm:1219: connect-child */
f_7348(t2,t5,((C_word*)t0)[10],*((C_word*)lf[39]+1));}
else{
/* posixunix.scm:1219: connect-child */
f_7348(t2,C_SCHEME_FALSE,((C_word*)t0)[10],*((C_word*)lf[39]+1));}}

/* k7405 in k7402 in a7399 in k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_7407,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7410,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[6])){
t3=C_i_cdr(((C_word*)t0)[6]);
t4=C_u_i_car(((C_word*)t0)[6]);
t5=C_a_i_cons(&a,2,t3,t4);
/* posixunix.scm:1220: connect-child */
f_7348(t2,t5,((C_word*)t0)[8],*((C_word*)lf[37]+1));}
else{
/* posixunix.scm:1220: connect-child */
f_7348(t2,C_SCHEME_FALSE,((C_word*)t0)[8],*((C_word*)lf[37]+1));}}

/* k7408 in k7405 in k7402 in a7399 in k7392 in k7385 in k7382 in k7379 in spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7410,c,av);}
/* posixunix.scm:1221: chicken.process#process-execute */
t2=*((C_word*)lf[107]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7422(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7422,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(6);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7426,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:1224: connect-parent */
f_7336(t7,t4,t5);}

/* k7424 in input-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_7426,c,av);}
if(C_truep(t1)){
/* posixunix.scm:1225: ##sys#custom-input-port */
t2=*((C_word*)lf[374]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
av2[5]=C_SCHEME_TRUE;
av2[6]=C_fix(256);
av2[7]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7433(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7433,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(6);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7437,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* posixunix.scm:1228: connect-parent */
f_7336(t7,t4,t5);}

/* k7435 in output-port in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_7437,c,av);}
if(C_truep(t1)){
/* posixunix.scm:1229: ##sys#custom-output-port */
t2=*((C_word*)lf[388]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
av2[5]=C_SCHEME_TRUE;
av2[6]=C_fix(0);
av2[7]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7444(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7,C_word t8){
C_word tmp;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,6)))){
C_save_and_reclaim_args((void *)trf_7444,9,t0,t1,t2,t3,t4,t5,t6,t7,t8);}
a=C_alloc(21);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7450,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t4,a[5]=t5,a[6]=t6,a[7]=t7,a[8]=t8,a[9]=((C_word)li193),tmp=(C_word)a,a+=10,tmp);
t10=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7456,a[2]=t7,a[3]=t6,a[4]=t8,a[5]=((C_word*)t0)[3],a[6]=t2,a[7]=t3,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word)li194),tmp=(C_word)a,a+=11,tmp);
/* posixunix.scm:1231: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t9;
av2[3]=t10;
C_call_with_values(4,av2);}}

/* a7449 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7450(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_7450,c,av);}
/* posixunix.scm:1232: spawn */
t2=((C_word*)t0)[2];
f_7377(t2,t1,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8]);}

/* a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(26,c,7)))){
C_save_and_reclaim((void *)f_7456,c,av);}
a=C_alloc(26);
t6=C_i_not(((C_word*)t0)[2]);
t7=C_i_not(((C_word*)t0)[3]);
t8=C_i_not(((C_word*)t0)[4]);
t9=C_a_i_vector3(&a,3,t6,t7,t8);
t10=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7467,a[2]=t1,a[3]=t5,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=t4,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[8],a[10]=t9,a[11]=((C_word*)t0)[9],a[12]=t3,a[13]=((C_word*)t0)[3],tmp=(C_word)a,a+=14,tmp);
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7487,a[2]=((C_word*)t0)[5],a[3]=t10,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t2,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:1240: make-on-close */
f_7279(t11,((C_word*)t0)[6],t5,t9,C_fix(0),C_fix(1),C_fix(2));}

/* k7465 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,7)))){
C_save_and_reclaim((void *)f_7467,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7471,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7483,a[2]=((C_word*)t0)[11],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[13],tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:1243: make-on-close */
f_7279(t3,((C_word*)t0)[5],((C_word*)t0)[3],((C_word*)t0)[10],C_fix(1),C_fix(0),C_fix(2));}

/* k7469 in k7465 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,7)))){
C_save_and_reclaim((void *)f_7471,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7475,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7479,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:1247: make-on-close */
f_7279(t3,((C_word*)t0)[6],((C_word*)t0)[4],((C_word*)t0)[11],C_fix(2),C_fix(0),C_fix(1));}

/* k7473 in k7469 in k7465 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7475,c,av);}
/* posixunix.scm:1237: scheme#values */{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=t1;
C_values(6,av2);}}

/* k7477 in k7469 in k7465 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7479,c,av);}
/* posixunix.scm:1245: input-port */
t2=((C_word*)t0)[2];
f_7422(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t1);}

/* k7481 in k7465 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7483,c,av);}
/* posixunix.scm:1241: output-port */
t2=((C_word*)t0)[2];
f_7433(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t1);}

/* k7485 in a7455 in chicken.posix#process-impl in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7487(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7487,c,av);}
/* posixunix.scm:1238: input-port */
t2=((C_word*)t0)[2];
f_7422(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t1);}

/* %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7500(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,3)))){
C_save_and_reclaim_args((void *)trf_7500,7,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(27);
t8=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7502,a[2]=t2,a[3]=((C_word)li198),tmp=(C_word)a,a+=4,tmp);
t11=C_i_check_string_2(((C_word*)t8)[1],t2);
t12=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7543,a[2]=t2,a[3]=t8,a[4]=t9,a[5]=t6,a[6]=t3,a[7]=t1,a[8]=t7,tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t9)[1])){
/* posixunix.scm:1260: chkstrlst */
t13=t10;
f_7502(t13,t12,((C_word*)t9)[1]);}
else{
t13=((C_word*)t8)[1];
t14=C_a_i_list2(&a,2,lf[420],t13);
t15=C_set_block_item(t9,0,t14);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8936,a[2]=t8,a[3]=t12,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1137: chicken.process-context#get-environment-variable */
t17=*((C_word*)lf[421]+1);{
C_word av2[3];
av2[0]=t17;
av2[1]=t16;
av2[2]=lf[422];
((C_proc)(void*)(*((C_word*)t17+1)))(3,av2);}}}

/* chkstrlst in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_fcall f_7502(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_7502,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_i_check_list_2(t2,((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7507,a[2]=((C_word*)t0)[2],a[3]=((C_word)li196),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7516,a[2]=t4,a[3]=((C_word)li197),tmp=(C_word)a,a+=4,tmp);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
  f_7516(t5,t2)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* g2179 in chkstrlst in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static C_word C_fcall f_7507(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_check_string_2(t1,((C_word*)t0)[2]));}

/* for-each-loop2178 in chkstrlst in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static C_word C_fcall f_7516(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* posixunix.scm:1257: g2179 */
  f_7507(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k7541 in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7543(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_7543,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7546,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[5])){
/* posixunix.scm:1264: check-environment-list */
f_4243(t2,((C_word*)t0)[5],((C_word*)t0)[2]);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_7546(2,av2);}}}

/* k7544 in k7541 in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7546(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7546,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7551,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li199),tmp=(C_word)a,a+=8,tmp);
/* posixunix.scm:1265: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[7];
av2[2]=t2;
av2[3]=((C_word*)t0)[8];
C_call_with_values(4,av2);}}

/* a7550 in k7544 in k7541 in %process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_7551,c,av);}
/* posixunix.scm:1266: process-impl */
t2=lf[424];
f_7444(t2,t1,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],C_SCHEME_TRUE,C_SCHEME_TRUE,((C_word*)t0)[6]);}

/* chicken.process#process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_7571,c,av);}
a=C_alloc(3);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7595,a[2]=((C_word)li201),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:1270: %process */
f_7500(t1,lf[425],C_SCHEME_FALSE,t2,t4,t7,t12);}

/* a7594 in chicken.process#process in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7595,c,av);}
/* posixunix.scm:1272: scheme#values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
C_values(5,av2);}}

/* chicken.process#process* in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_7637,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
if(C_truep(C_rest_nullp(c,5))){
/* posixunix.scm:1275: %process */
f_7500(t1,lf[426],C_SCHEME_TRUE,t2,t4,t7,*((C_word*)lf[312]+1));}
else{
/* posixunix.scm:1275: %process */
f_7500(t1,lf[426],C_SCHEME_TRUE,t2,t4,t7,*((C_word*)lf[312]+1));}}

/* k7700 in chicken.process-context.posix#set-root-directory! in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7702,c,av);}
if(C_truep(C_fixnum_lessp(stub2249(C_SCHEME_UNDEFINED,t1),C_fix(0)))){
/* posixunix.scm:1287: posix-error */
t2=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=lf[427];
av2[4]=lf[428];
av2[5]=((C_word*)t0)[3];
f_3009(6,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.process-context.posix#set-root-directory! in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7707,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[427]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7702,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:1283: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[193]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[193]+1);
av2[1]=t4;
av2[2]=C_i_foreign_string_argumentp(t2);
tp(3,av2);}}

/* chicken.process#process-spawn in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7726,c,av);}
/* posixunix.scm:1291: chicken.base#error */
t2=*((C_word*)lf[101]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[111];
av2[3]=lf[429];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.errno#errno in k5659 in k5628 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7732,c,av);}
/* posix.scm:379: ##sys#errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[432]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[432]+1);
av2[1]=t1;
tp(2,av2);}}

/* a7780 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7781,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7785,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:706: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[472];
tp(4,av2);}}

/* k7783 in a7780 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7785,c,av);}
a=C_alloc(8);
t2=C_getpgid(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7788,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t2,C_fix(0)))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7798,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:709: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t4;
tp(2,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7786 in k7783 in a7780 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7788,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7796 in k7783 in a7780 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7798,c,av);}
/* posixunix.scm:709: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[472];
av2[4]=lf[473];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* a7799 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7800,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7804,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:714: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[474];
tp(4,av2);}}

/* k7802 in a7799 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7804,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7807,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:715: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[474];
tp(4,av2);}}

/* k7805 in k7802 in a7799 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7807,c,av);}
a=C_alloc(5);
if(C_truep(C_fixnum_lessp(C_setpgid(((C_word*)t0)[2],((C_word*)t0)[3]),C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7820,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posixunix.scm:717: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7818 in k7805 in k7802 in a7799 in k5479 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7820(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_7820,c,av);}
/* posixunix.scm:717: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[474];
av2[4]=lf[475];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
tp(7,av2);}}

/* a7822 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7823(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7823,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub1592(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7825 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7826,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7830,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:635: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[480];
tp(4,av2);}}

/* k7828 in a7825 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7830,c,av);}
a=C_alloc(4);
if(C_truep(C_fixnum_lessp(C_setegid(((C_word*)t0)[2]),C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7843,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:637: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7841 in k7828 in a7825 in k5475 in k5471 in k5467 in k5425 */
static void C_ccall f_7843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7843,c,av);}
/* posixunix.scm:637: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[478];
av2[4]=lf[479];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* a7845 in k5471 in k5467 in k5425 */
static void C_ccall f_7846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7846,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub1588(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7848 in k5471 in k5467 in k5425 */
static void C_ccall f_7849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7849,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7853,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:625: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[484];
tp(4,av2);}}

/* k7851 in a7848 in k5471 in k5467 in k5425 */
static void C_ccall f_7853(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7853,c,av);}
a=C_alloc(4);
if(C_truep(C_fixnum_lessp(C_setgid(((C_word*)t0)[2]),C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7866,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:627: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7864 in k7851 in a7848 in k5471 in k5467 in k5425 */
static void C_ccall f_7866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7866,c,av);}
/* posixunix.scm:627: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[482];
av2[4]=lf[483];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* a7868 in k5467 in k5425 */
static void C_ccall f_7869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7869,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub1584(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7871 in k5467 in k5425 */
static void C_ccall f_7872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7872,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7876,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:614: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[488];
tp(4,av2);}}

/* k7874 in a7871 in k5467 in k5425 */
static void C_ccall f_7876(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7876,c,av);}
a=C_alloc(4);
if(C_truep(C_fixnum_lessp(C_seteuid(((C_word*)t0)[2]),C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7889,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:616: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7887 in k7874 in a7871 in k5467 in k5425 */
static void C_ccall f_7889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7889,c,av);}
/* posixunix.scm:616: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[486];
av2[4]=lf[487];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* a7891 in k5425 */
static void C_ccall f_7892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7892,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub1580(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7894 in k5425 */
static void C_ccall f_7895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7895,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7899,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:604: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[492];
tp(4,av2);}}

/* k7897 in a7894 in k5425 */
static void C_ccall f_7899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7899,c,av);}
a=C_alloc(4);
if(C_truep(C_fixnum_lessp(C_setuid(((C_word*)t0)[2]),C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7912,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posixunix.scm:606: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t2;
tp(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7910 in k7897 in a7894 in k5425 */
static void C_ccall f_7912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7912,c,av);}
/* posixunix.scm:606: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[355]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[355]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[490];
av2[4]=lf[491];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* a7914 */
static void C_ccall f_7915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_7915,c,av);}
a=C_alloc(6);
t2=C_sigprocmask_get(C_fix(0));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7921,a[2]=t4,a[3]=((C_word)li217),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_7921(t6,t1,*((C_word*)lf[170]+1),C_SCHEME_END_OF_LIST);}

/* loop in a7914 */
static void C_fcall f_7921(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_7921,4,t0,t1,t2,t3);}
a=C_alloc(3);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
if(C_truep(C_sigismember(t4))){
t6=C_a_i_cons(&a,2,t4,t3);
/* posixunix.scm:570: loop */
t8=t1;
t9=t5;
t10=t6;
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* posixunix.scm:570: loop */
t8=t1;
t9=t5;
t10=t3;
t1=t8;
t2=t9;
t3=t10;
goto loop;}}}

/* a7944 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7945(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7945,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7949,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:638: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[495];
tp(4,av2);}}

/* k7947 in a7944 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7949(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7949,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(*((C_word*)lf[272]+1),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7953 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7954,c,av);}
a=C_alloc(4);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7961,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
/* posix-common.scm:563: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[497];
tp(4,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_7961(2,av2);}}}

/* k7959 in a7953 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7961(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7961,c,av);}
if(C_truep(((C_word*)t0)[2])){
t2=C_umask(((C_word*)t0)[2]);
if(C_truep(((C_word*)t0)[2])){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_umask(t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t2=C_umask(C_fix(0));
if(C_truep(((C_word*)t0)[2])){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_umask(t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* a7978 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7979(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7979,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7983,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:568: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[205]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[205]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[497];
tp(4,av2);}}

/* k7981 in a7978 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7983,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_umask(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7984 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7985,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7989,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8001,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:404: chicken.base#port? */
t5=*((C_word*)lf[197]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7987 in a7984 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_7989,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7992,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_lessp(t1,C_fix(0)))){
/* posix-common.scm:413: posix-error */
t3=lf[186];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=lf[499];
av2[4]=lf[500];
av2[5]=((C_word*)t0)[3];
f_3009(6,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7990 in k7987 in a7984 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_7992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7992,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7999 in a7984 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_8001,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(7));
t3=C_eqp(t2,lf[234]);
if(C_truep(t3)){
t4=C_ftell(&a,1,((C_word*)t0)[2]);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_7989(2,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_fix(-1);
f_7989(2,av2);}}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_lseek(((C_word*)t0)[2],C_fix(0),C_fix((C_word)SEEK_CUR));
f_7989(2,av2);}}
else{
/* posix-common.scm:411: ##sys#signal-hook */
t2=*((C_word*)lf[194]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[195];
av2[3]=lf[499];
av2[4]=lf[501];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* a8021 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_8022,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8026,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:327: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[203]);}

/* k8024 in a8021 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8026,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_stat_perm);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a8027 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_8028,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8032,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:320: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[504]);}

/* k8030 in a8027 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8032,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_gid);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a8033 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_8034,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8038,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:314: stat */
f_3027(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[506]);}

/* k8036 in a8033 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_ccall f_8038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8038,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_uid);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_posix_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("posix"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_posix_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(2751))){
C_save(t1);
C_rereclaim2(2751*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,508);
lf[0]=C_h_intern(&lf[0],5, C_text("posix"));
lf[1]=C_h_intern(&lf[1],19, C_text("chicken.file.posix#"));
lf[2]=C_h_intern(&lf[2],30, C_text("chicken.file.posix#create-fifo"));
lf[3]=C_h_intern(&lf[3],39, C_text("chicken.file.posix#create-symbolic-link"));
lf[4]=C_h_intern(&lf[4],37, C_text("chicken.file.posix#read-symbolic-link"));
lf[5]=C_h_intern(&lf[5],35, C_text("chicken.file.posix#duplicate-fileno"));
lf[6]=C_h_intern(&lf[6],30, C_text("chicken.file.posix#fcntl/dupfd"));
lf[7]=C_h_intern(&lf[7],30, C_text("chicken.file.posix#fcntl/getfd"));
lf[8]=C_h_intern(&lf[8],30, C_text("chicken.file.posix#fcntl/getfl"));
lf[9]=C_h_intern(&lf[9],30, C_text("chicken.file.posix#fcntl/setfd"));
lf[10]=C_h_intern(&lf[10],30, C_text("chicken.file.posix#fcntl/setfl"));
lf[11]=C_h_intern(&lf[11],29, C_text("chicken.file.posix#file-close"));
lf[12]=C_h_intern(&lf[12],31, C_text("chicken.file.posix#file-control"));
lf[13]=C_h_intern(&lf[13],37, C_text("chicken.file.posix#file-creation-mode"));
lf[14]=C_h_intern(&lf[14],29, C_text("chicken.file.posix#file-group"));
lf[15]=C_h_intern(&lf[15],28, C_text("chicken.file.posix#file-link"));
lf[16]=C_h_intern(&lf[16],28, C_text("chicken.file.posix#file-lock"));
lf[17]=C_h_intern(&lf[17],37, C_text("chicken.file.posix#file-lock/blocking"));
lf[18]=C_h_intern(&lf[18],31, C_text("chicken.file.posix#file-mkstemp"));
lf[19]=C_h_intern(&lf[19],28, C_text("chicken.file.posix#file-open"));
lf[20]=C_h_intern(&lf[20],29, C_text("chicken.file.posix#file-owner"));
lf[21]=C_h_intern(&lf[21],35, C_text("chicken.file.posix#file-permissions"));
lf[22]=C_h_intern(&lf[22],32, C_text("chicken.file.posix#file-position"));
lf[23]=C_h_intern(&lf[23],28, C_text("chicken.file.posix#file-read"));
lf[24]=C_h_intern(&lf[24],30, C_text("chicken.file.posix#file-select"));
lf[25]=C_h_intern(&lf[25],33, C_text("chicken.file.posix#file-test-lock"));
lf[26]=C_h_intern(&lf[26],32, C_text("chicken.file.posix#file-truncate"));
lf[27]=C_h_intern(&lf[27],30, C_text("chicken.file.posix#file-unlock"));
lf[28]=C_h_intern(&lf[28],29, C_text("chicken.file.posix#file-write"));
lf[29]=C_h_intern(&lf[29],28, C_text("chicken.file.posix#file-type"));
lf[30]=C_h_intern(&lf[30],32, C_text("chicken.file.posix#block-device\077"));
lf[31]=C_h_intern(&lf[31],36, C_text("chicken.file.posix#character-device\077"));
lf[32]=C_h_intern(&lf[32],29, C_text("chicken.file.posix#directory\077"));
lf[33]=C_h_intern(&lf[33],24, C_text("chicken.file.posix#fifo\077"));
lf[34]=C_h_intern(&lf[34],32, C_text("chicken.file.posix#regular-file\077"));
lf[35]=C_h_intern(&lf[35],26, C_text("chicken.file.posix#socket\077"));
lf[36]=C_h_intern(&lf[36],33, C_text("chicken.file.posix#symbolic-link\077"));
lf[37]=C_h_intern(&lf[37],32, C_text("chicken.file.posix#fileno/stderr"));
lf[38]=C_h_intern(&lf[38],31, C_text("chicken.file.posix#fileno/stdin"));
lf[39]=C_h_intern(&lf[39],32, C_text("chicken.file.posix#fileno/stdout"));
lf[40]=C_h_intern(&lf[40],35, C_text("chicken.file.posix#open-input-file\052"));
lf[41]=C_h_intern(&lf[41],36, C_text("chicken.file.posix#open-output-file\052"));
lf[42]=C_h_intern(&lf[42],30, C_text("chicken.file.posix#open/append"));
lf[43]=C_h_intern(&lf[43],30, C_text("chicken.file.posix#open/binary"));
lf[44]=C_h_intern(&lf[44],29, C_text("chicken.file.posix#open/creat"));
lf[45]=C_h_intern(&lf[45],28, C_text("chicken.file.posix#open/excl"));
lf[46]=C_h_intern(&lf[46],29, C_text("chicken.file.posix#open/fsync"));
lf[47]=C_h_intern(&lf[47],30, C_text("chicken.file.posix#open/noctty"));
lf[48]=C_h_intern(&lf[48],33, C_text("chicken.file.posix#open/noinherit"));
lf[49]=C_h_intern(&lf[49],32, C_text("chicken.file.posix#open/nonblock"));
lf[50]=C_h_intern(&lf[50],30, C_text("chicken.file.posix#open/rdonly"));
lf[51]=C_h_intern(&lf[51],28, C_text("chicken.file.posix#open/rdwr"));
lf[52]=C_h_intern(&lf[52],28, C_text("chicken.file.posix#open/read"));
lf[53]=C_h_intern(&lf[53],28, C_text("chicken.file.posix#open/sync"));
lf[54]=C_h_intern(&lf[54],28, C_text("chicken.file.posix#open/text"));
lf[55]=C_h_intern(&lf[55],29, C_text("chicken.file.posix#open/trunc"));
lf[56]=C_h_intern(&lf[56],29, C_text("chicken.file.posix#open/write"));
lf[57]=C_h_intern(&lf[57],30, C_text("chicken.file.posix#open/wronly"));
lf[58]=C_h_intern(&lf[58],29, C_text("chicken.file.posix#perm/irgrp"));
lf[59]=C_h_intern(&lf[59],29, C_text("chicken.file.posix#perm/iroth"));
lf[60]=C_h_intern(&lf[60],29, C_text("chicken.file.posix#perm/irusr"));
lf[61]=C_h_intern(&lf[61],29, C_text("chicken.file.posix#perm/irwxg"));
lf[62]=C_h_intern(&lf[62],29, C_text("chicken.file.posix#perm/irwxo"));
lf[63]=C_h_intern(&lf[63],29, C_text("chicken.file.posix#perm/irwxu"));
lf[64]=C_h_intern(&lf[64],29, C_text("chicken.file.posix#perm/isgid"));
lf[65]=C_h_intern(&lf[65],29, C_text("chicken.file.posix#perm/isuid"));
lf[66]=C_h_intern(&lf[66],29, C_text("chicken.file.posix#perm/isvtx"));
lf[67]=C_h_intern(&lf[67],29, C_text("chicken.file.posix#perm/iwgrp"));
lf[68]=C_h_intern(&lf[68],29, C_text("chicken.file.posix#perm/iwoth"));
lf[69]=C_h_intern(&lf[69],29, C_text("chicken.file.posix#perm/iwusr"));
lf[70]=C_h_intern(&lf[70],29, C_text("chicken.file.posix#perm/ixgrp"));
lf[71]=C_h_intern(&lf[71],29, C_text("chicken.file.posix#perm/ixoth"));
lf[72]=C_h_intern(&lf[72],29, C_text("chicken.file.posix#perm/ixusr"));
lf[73]=C_h_intern(&lf[73],31, C_text("chicken.file.posix#port->fileno"));
lf[74]=C_h_intern(&lf[74],27, C_text("chicken.file.posix#seek/cur"));
lf[75]=C_h_intern(&lf[75],27, C_text("chicken.file.posix#seek/end"));
lf[76]=C_h_intern(&lf[76],27, C_text("chicken.file.posix#seek/set"));
lf[77]=C_h_intern(&lf[77],37, C_text("chicken.file.posix#set-file-position!"));
lf[78]=C_h_intern(&lf[78],19, C_text("chicken.time.posix#"));
lf[79]=C_h_intern(&lf[79],36, C_text("chicken.time.posix#seconds->utc-time"));
lf[80]=C_h_intern(&lf[80],36, C_text("chicken.time.posix#utc-time->seconds"));
lf[81]=C_h_intern(&lf[81],38, C_text("chicken.time.posix#seconds->local-time"));
lf[82]=C_h_intern(&lf[82],34, C_text("chicken.time.posix#seconds->string"));
lf[83]=C_h_intern(&lf[83],38, C_text("chicken.time.posix#local-time->seconds"));
lf[84]=C_h_intern(&lf[84],31, C_text("chicken.time.posix#string->time"));
lf[85]=C_h_intern(&lf[85],31, C_text("chicken.time.posix#time->string"));
lf[86]=C_h_intern(&lf[86],46, C_text("chicken.time.posix#local-timezone-abbreviation"));
lf[87]=C_h_intern(&lf[87],16, C_text("chicken.process#"));
lf[88]=C_h_intern(&lf[88],22, C_text("chicken.process#system"));
lf[89]=C_h_intern(&lf[89],6, C_text("system"));
lf[90]=C_h_intern(&lf[90],23, C_text("##sys#signal-hook/errno"));
lf[91]=C_h_intern_kw(&lf[91],13, C_text("process-error"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032`system\047 invocation failed"));
lf[93]=C_h_intern(&lf[93],18, C_text("##sys#update-errno"));
lf[94]=C_h_intern(&lf[94],23, C_text("chicken.process#system\052"));
lf[95]=C_h_intern(&lf[95],11, C_text("##sys#error"));
lf[96]=C_decode_literal(C_heaptop,C_text("\376B\000\0003shell invocation failed with non-zero return status"));
lf[97]=C_h_intern(&lf[97],18, C_text("chicken.process#qs"));
lf[98]=C_h_intern(&lf[98],7, C_text("mingw32"));
lf[99]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002\042\042"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004\047\134\047\047"));
lf[101]=C_h_intern(&lf[101],18, C_text("chicken.base#error"));
lf[102]=C_h_intern(&lf[102],2, C_text("qs"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376B\000\0004NUL character can not be represented in shell string"));
lf[104]=C_h_intern(&lf[104],20, C_text("scheme#string-append"));
lf[105]=C_h_intern(&lf[105],18, C_text("##sys#string->list"));
lf[106]=C_h_intern(&lf[106],33, C_text("chicken.platform#software-version"));
lf[107]=C_h_intern(&lf[107],31, C_text("chicken.process#process-execute"));
lf[108]=C_h_intern(&lf[108],28, C_text("chicken.process#process-fork"));
lf[109]=C_h_intern(&lf[109],27, C_text("chicken.process#process-run"));
lf[110]=C_h_intern(&lf[110],30, C_text("chicken.process#process-signal"));
lf[111]=C_h_intern(&lf[111],29, C_text("chicken.process#process-spawn"));
lf[112]=C_h_intern(&lf[112],28, C_text("chicken.process#process-wait"));
lf[113]=C_h_intern(&lf[113],36, C_text("chicken.process#call-with-input-pipe"));
lf[114]=C_h_intern(&lf[114],37, C_text("chicken.process#call-with-output-pipe"));
lf[115]=C_h_intern(&lf[115],32, C_text("chicken.process#close-input-pipe"));
lf[116]=C_h_intern(&lf[116],33, C_text("chicken.process#close-output-pipe"));
lf[117]=C_h_intern(&lf[117],27, C_text("chicken.process#create-pipe"));
lf[118]=C_h_intern(&lf[118],31, C_text("chicken.process#open-input-pipe"));
lf[119]=C_h_intern(&lf[119],32, C_text("chicken.process#open-output-pipe"));
lf[120]=C_h_intern(&lf[120],36, C_text("chicken.process#with-input-from-pipe"));
lf[121]=C_h_intern(&lf[121],35, C_text("chicken.process#with-output-to-pipe"));
lf[122]=C_h_intern(&lf[122],23, C_text("chicken.process#process"));
lf[123]=C_h_intern(&lf[123],24, C_text("chicken.process#process\052"));
lf[124]=C_h_intern(&lf[124],29, C_text("chicken.process#process-sleep"));
lf[125]=C_h_intern(&lf[125],24, C_text("chicken.process#pipe/buf"));
lf[126]=C_h_intern(&lf[126],29, C_text("chicken.process#spawn/overlay"));
lf[127]=C_h_intern(&lf[127],26, C_text("chicken.process#spawn/wait"));
lf[128]=C_h_intern(&lf[128],28, C_text("chicken.process#spawn/nowait"));
lf[129]=C_h_intern(&lf[129],29, C_text("chicken.process#spawn/nowaito"));
lf[130]=C_h_intern(&lf[130],28, C_text("chicken.process#spawn/detach"));
lf[131]=C_h_intern(&lf[131],23, C_text("chicken.process.signal#"));
lf[132]=C_h_intern(&lf[132],33, C_text("chicken.process.signal#set-alarm!"));
lf[133]=C_h_intern(&lf[133],42, C_text("chicken.process.signal#set-signal-handler!"));
lf[134]=C_h_intern(&lf[134],39, C_text("chicken.process.signal#set-signal-mask!"));
lf[135]=C_h_intern(&lf[135],37, C_text("chicken.process.signal#signal-handler"));
lf[136]=C_h_intern(&lf[136],42, C_text("chicken.process.signal#make-signal-handler"));
lf[137]=C_h_intern(&lf[137],36, C_text("chicken.process.signal#signal-ignore"));
lf[138]=C_h_intern(&lf[138],37, C_text("chicken.process.signal#signal-default"));
lf[139]=C_h_intern(&lf[139],34, C_text("chicken.process.signal#signal-mask"));
lf[140]=C_h_intern(&lf[140],35, C_text("chicken.process.signal#signal-mask!"));
lf[141]=C_h_intern(&lf[141],37, C_text("chicken.process.signal#signal-masked\077"));
lf[142]=C_h_intern(&lf[142],37, C_text("chicken.process.signal#signal-unmask!"));
lf[143]=C_h_intern(&lf[143],34, C_text("chicken.process.signal#signal/abrt"));
lf[144]=C_h_intern(&lf[144],34, C_text("chicken.process.signal#signal/alrm"));
lf[145]=C_h_intern(&lf[145],35, C_text("chicken.process.signal#signal/break"));
lf[146]=C_h_intern(&lf[146],33, C_text("chicken.process.signal#signal/bus"));
lf[147]=C_h_intern(&lf[147],34, C_text("chicken.process.signal#signal/chld"));
lf[148]=C_h_intern(&lf[148],34, C_text("chicken.process.signal#signal/cont"));
lf[149]=C_h_intern(&lf[149],33, C_text("chicken.process.signal#signal/fpe"));
lf[150]=C_h_intern(&lf[150],33, C_text("chicken.process.signal#signal/hup"));
lf[151]=C_h_intern(&lf[151],33, C_text("chicken.process.signal#signal/ill"));
lf[152]=C_h_intern(&lf[152],33, C_text("chicken.process.signal#signal/int"));
lf[153]=C_h_intern(&lf[153],32, C_text("chicken.process.signal#signal/io"));
lf[154]=C_h_intern(&lf[154],34, C_text("chicken.process.signal#signal/kill"));
lf[155]=C_h_intern(&lf[155],34, C_text("chicken.process.signal#signal/pipe"));
lf[156]=C_h_intern(&lf[156],34, C_text("chicken.process.signal#signal/prof"));
lf[157]=C_h_intern(&lf[157],34, C_text("chicken.process.signal#signal/quit"));
lf[158]=C_h_intern(&lf[158],34, C_text("chicken.process.signal#signal/segv"));
lf[159]=C_h_intern(&lf[159],34, C_text("chicken.process.signal#signal/stop"));
lf[160]=C_h_intern(&lf[160],34, C_text("chicken.process.signal#signal/term"));
lf[161]=C_h_intern(&lf[161],34, C_text("chicken.process.signal#signal/trap"));
lf[162]=C_h_intern(&lf[162],34, C_text("chicken.process.signal#signal/tstp"));
lf[163]=C_h_intern(&lf[163],33, C_text("chicken.process.signal#signal/urg"));
lf[164]=C_h_intern(&lf[164],34, C_text("chicken.process.signal#signal/usr1"));
lf[165]=C_h_intern(&lf[165],34, C_text("chicken.process.signal#signal/usr2"));
lf[166]=C_h_intern(&lf[166],36, C_text("chicken.process.signal#signal/vtalrm"));
lf[167]=C_h_intern(&lf[167],35, C_text("chicken.process.signal#signal/winch"));
lf[168]=C_h_intern(&lf[168],34, C_text("chicken.process.signal#signal/xcpu"));
lf[169]=C_h_intern(&lf[169],34, C_text("chicken.process.signal#signal/xfsz"));
lf[170]=C_h_intern(&lf[170],35, C_text("chicken.process.signal#signals-list"));
lf[171]=C_h_intern(&lf[171],30, C_text("chicken.process-context.posix#"));
lf[172]=C_h_intern(&lf[172],47, C_text("chicken.process-context.posix#change-directory\052"));
lf[173]=C_h_intern(&lf[173],49, C_text("chicken.process-context.posix#set-root-directory!"));
lf[174]=C_h_intern(&lf[174],56, C_text("chicken.process-context.posix#current-effective-group-id"));
lf[175]=C_h_intern(&lf[175],55, C_text("chicken.process-context.posix#current-effective-user-id"));
lf[176]=C_h_intern(&lf[176],46, C_text("chicken.process-context.posix#current-group-id"));
lf[177]=C_h_intern(&lf[177],45, C_text("chicken.process-context.posix#current-user-id"));
lf[178]=C_h_intern(&lf[178],48, C_text("chicken.process-context.posix#current-process-id"));
lf[179]=C_h_intern(&lf[179],47, C_text("chicken.process-context.posix#parent-process-id"));
lf[180]=C_h_intern(&lf[180],47, C_text("chicken.process-context.posix#current-user-name"));
lf[181]=C_h_intern(&lf[181],57, C_text("chicken.process-context.posix#current-effective-user-name"));
lf[182]=C_h_intern(&lf[182],44, C_text("chicken.process-context.posix#create-session"));
lf[183]=C_h_intern(&lf[183],46, C_text("chicken.process-context.posix#process-group-id"));
lf[184]=C_h_intern(&lf[184],46, C_text("chicken.process-context.posix#user-information"));
lf[185]=C_h_intern(&lf[185],14, C_text("chicken.posix#"));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 - "));
lf[188]=C_h_intern(&lf[188],19, C_text("##sys#peek-c-string"));
lf[189]=C_h_intern(&lf[189],17, C_text("##sys#posix-error"));
lf[191]=C_h_intern_kw(&lf[191],10, C_text("file-error"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot access file"));
lf[193]=C_h_intern(&lf[193],19, C_text("##sys#make-c-string"));
lf[194]=C_h_intern(&lf[194],17, C_text("##sys#signal-hook"));
lf[195]=C_h_intern_kw(&lf[195],10, C_text("type-error"));
lf[196]=C_decode_literal(C_heaptop,C_text("\376B\000\0000bad argument type - not a fixnum, port or string"));
lf[197]=C_h_intern(&lf[197],18, C_text("chicken.base#port\077"));
lf[198]=C_h_intern(&lf[198],28, C_text("chicken.file.posix#file-stat"));
lf[199]=C_h_intern(&lf[199],9, C_text("file-stat"));
lf[200]=C_h_intern(&lf[200],40, C_text("chicken.file.posix#set-file-permissions!"));
lf[201]=C_h_intern(&lf[201],21, C_text("set-file-permissions!"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036cannot change file permissions"));
lf[203]=C_h_intern(&lf[203],16, C_text("file-permissions"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\0000bad argument type - not a fixnum, port or string"));
lf[205]=C_h_intern(&lf[205],18, C_text("##sys#check-fixnum"));
lf[206]=C_h_intern(&lf[206],41, C_text("chicken.file.posix#file-modification-time"));
lf[207]=C_h_intern(&lf[207],22, C_text("file-modification-time"));
lf[208]=C_h_intern(&lf[208],35, C_text("chicken.file.posix#file-access-time"));
lf[209]=C_h_intern(&lf[209],16, C_text("file-access-time"));
lf[210]=C_h_intern(&lf[210],35, C_text("chicken.file.posix#file-change-time"));
lf[211]=C_h_intern(&lf[211],16, C_text("file-change-time"));
lf[212]=C_h_intern(&lf[212],34, C_text("chicken.file.posix#set-file-times!"));
lf[213]=C_h_intern(&lf[213],15, C_text("set-file-times!"));
lf[214]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot set file times"));
lf[215]=C_h_intern(&lf[215],25, C_text("##sys#check-exact-integer"));
lf[216]=C_h_intern(&lf[216],28, C_text("chicken.time#current-seconds"));
lf[217]=C_h_intern(&lf[217],28, C_text("chicken.file.posix#file-size"));
lf[218]=C_h_intern(&lf[218],9, C_text("file-size"));
lf[219]=C_h_intern(&lf[219],34, C_text("chicken.file.posix#set-file-owner!"));
lf[221]=C_h_intern(&lf[221],15, C_text("set-file-owner!"));
lf[222]=C_h_intern(&lf[222],34, C_text("chicken.file.posix#set-file-group!"));
lf[223]=C_h_intern(&lf[223],15, C_text("set-file-group!"));
lf[224]=C_h_intern(&lf[224],12, C_text("regular-file"));
lf[225]=C_h_intern(&lf[225],13, C_text("symbolic-link"));
lf[226]=C_h_intern(&lf[226],9, C_text("directory"));
lf[227]=C_h_intern(&lf[227],16, C_text("character-device"));
lf[228]=C_h_intern(&lf[228],12, C_text("block-device"));
lf[229]=C_h_intern(&lf[229],4, C_text("fifo"));
lf[230]=C_h_intern(&lf[230],6, C_text("socket"));
lf[231]=C_h_intern(&lf[231],9, C_text("file-type"));
lf[232]=C_h_intern(&lf[232],18, C_text("set-file-position!"));
lf[233]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030cannot set file position"));
lf[234]=C_h_intern(&lf[234],6, C_text("stream"));
lf[235]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid file"));
lf[236]=C_h_intern_kw(&lf[236],6, C_text("append"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001a"));
lf[238]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033invalid mode for input file"));
lf[239]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025invalid mode argument"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001r"));
lf[241]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001w"));
lf[242]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[243]=C_h_intern(&lf[243],15, C_text("##sys#make-port"));
lf[244]=C_h_intern(&lf[244],23, C_text("##sys#stream-port-class"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010(fdport)"));
lf[246]=C_h_intern(&lf[246],16, C_text("open-input-file\052"));
lf[247]=C_h_intern(&lf[247],17, C_text("open-output-file\052"));
lf[248]=C_h_intern(&lf[248],12, C_text("port->fileno"));
lf[249]=C_h_intern(&lf[249],15, C_text("##sys#port-data"));
lf[250]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot access file-descriptor of port"));
lf[251]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031port has no attached file"));
lf[252]=C_h_intern(&lf[252],27, C_text("##sys#peek-unsigned-integer"));
lf[253]=C_h_intern(&lf[253],16, C_text("duplicate-fileno"));
lf[254]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot duplicate file-descriptor"));
lf[255]=C_h_intern(&lf[255],17, C_text("change-directory\052"));
lf[256]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037cannot change current directory"));
lf[257]=C_h_intern(&lf[257],27, C_text("##sys#change-directory-hook"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025time vector too short"));
lf[261]=C_h_intern(&lf[261],19, C_text("seconds->local-time"));
lf[262]=C_h_intern(&lf[262],17, C_text("seconds->utc-time"));
lf[263]=C_h_intern(&lf[263],15, C_text("##sys#substring"));
lf[264]=C_h_intern(&lf[264],15, C_text("seconds->string"));
lf[265]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot convert seconds to string"));
lf[266]=C_h_intern(&lf[266],19, C_text("local-time->seconds"));
lf[267]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot convert time vector to seconds"));
lf[268]=C_h_intern(&lf[268],17, C_text("##sys#make-string"));
lf[269]=C_h_intern(&lf[269],12, C_text("time->string"));
lf[270]=C_decode_literal(C_heaptop,C_text("\376B\000\000 time formatting overflows buffer"));
lf[271]=C_decode_literal(C_heaptop,C_text("\376B\000\000$cannot convert time vector to string"));
lf[272]=C_h_intern(&lf[272],19, C_text("##sys#signal-vector"));
lf[273]=C_h_intern(&lf[273],19, C_text("set-signal-handler!"));
lf[274]=C_h_intern(&lf[274],25, C_text("##sys#add-event-to-queue!"));
lf[275]=C_h_intern(&lf[275],19, C_text("make-signal-handler"));
lf[276]=C_h_intern(&lf[276],20, C_text("##sys#get-next-event"));
lf[277]=C_h_intern(&lf[277],25, C_text("##sys#wait-for-next-event"));
lf[278]=C_h_intern(&lf[278],22, C_text("##sys#make-event-queue"));
lf[279]=C_h_intern(&lf[279],13, C_text("signal-ignore"));
lf[280]=C_h_intern(&lf[280],14, C_text("signal-default"));
lf[281]=C_h_intern(&lf[281],13, C_text("process-sleep"));
lf[283]=C_h_intern(&lf[283],12, C_text("process-wait"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376B\000\000 waiting for child process failed"));
lf[286]=C_h_intern(&lf[286],24, C_text("chicken.condition#signal"));
lf[288]=C_h_intern(&lf[288],34, C_text("chicken.memory#pointer-vector-set!"));
lf[289]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015Out of memory"));
lf[290]=C_h_intern(&lf[290],40, C_text("chicken.condition#with-exception-handler"));
lf[291]=C_h_intern(&lf[291],37, C_text("scheme#call-with-current-continuation"));
lf[292]=C_h_intern(&lf[292],34, C_text("chicken.memory#make-pointer-vector"));
lf[293]=C_h_intern(&lf[293],19, C_text("chicken.memory#free"));
lf[294]=C_h_intern(&lf[294],33, C_text("chicken.memory#pointer-vector-ref"));
lf[295]=C_h_intern(&lf[295],36, C_text("chicken.memory#pointer-vector-length"));
lf[298]=C_h_intern(&lf[298],3, C_text("map"));
lf[299]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001="));
lf[300]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open pipe"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006(pipe)"));
lf[302]=C_h_intern(&lf[302],15, C_text("open-input-pipe"));
lf[303]=C_h_intern_kw(&lf[303],4, C_text("text"));
lf[304]=C_h_intern_kw(&lf[304],6, C_text("binary"));
lf[305]=C_decode_literal(C_heaptop,C_text("\376B\000\000#illegal input/output mode specifier"));
lf[306]=C_h_intern(&lf[306],16, C_text("open-output-pipe"));
lf[307]=C_h_intern(&lf[307],16, C_text("close-input-pipe"));
lf[308]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030error while closing pipe"));
lf[309]=C_h_intern(&lf[309],17, C_text("close-output-pipe"));
lf[310]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030error while closing pipe"));
lf[311]=C_h_intern(&lf[311],20, C_text("##sys#standard-input"));
lf[312]=C_h_intern(&lf[312],13, C_text("scheme#values"));
lf[313]=C_h_intern(&lf[313],18, C_text("##sys#dynamic-wind"));
lf[314]=C_h_intern(&lf[314],21, C_text("##sys#standard-output"));
lf[315]=C_h_intern(&lf[315],23, C_text("##sys#file-nonblocking!"));
lf[316]=C_h_intern(&lf[316],21, C_text("##sys#file-select-one"));
lf[317]=C_h_intern(&lf[317],12, C_text("file-control"));
lf[318]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023cannot control file"));
lf[319]=C_h_intern(&lf[319],9, C_text("file-open"));
lf[320]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[321]=C_h_intern(&lf[321],24, C_text("##sys#dispatch-interrupt"));
lf[322]=C_h_intern(&lf[322],10, C_text("file-close"));
lf[323]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021cannot close file"));
lf[324]=C_h_intern(&lf[324],9, C_text("file-read"));
lf[325]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot read from file"));
lf[326]=C_decode_literal(C_heaptop,C_text("\376B\000\000(bad argument type - not a string or blob"));
lf[327]=C_h_intern(&lf[327],18, C_text("scheme#make-string"));
lf[328]=C_h_intern(&lf[328],10, C_text("file-write"));
lf[329]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot write to file"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376B\000\000(bad argument type - not a string or blob"));
lf[331]=C_h_intern(&lf[331],12, C_text("file-mkstemp"));
lf[332]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034cannot create temporary file"));
lf[333]=C_h_intern(&lf[333],11, C_text("file-select"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006failed"));
lf[335]=C_h_intern(&lf[335],18, C_text("##sys#fast-reverse"));
lf[336]=C_h_intern(&lf[336],21, C_text("scheme#inexact->exact"));
lf[337]=C_h_intern(&lf[337],15, C_text("scheme#truncate"));
lf[338]=C_h_intern(&lf[338],10, C_text("scheme#max"));
lf[339]=C_h_intern(&lf[339],15, C_text("##sys#make-blob"));
lf[340]=C_h_intern(&lf[340],11, C_text("create-pipe"));
lf[341]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot create pipe"));
lf[342]=C_h_intern(&lf[342],16, C_text("set-signal-mask!"));
lf[343]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026cannot set signal mask"));
lf[344]=C_h_intern(&lf[344],14, C_text("signal-masked\077"));
lf[345]=C_h_intern(&lf[345],12, C_text("signal-mask!"));
lf[346]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023cannot block signal"));
lf[347]=C_h_intern(&lf[347],14, C_text("signal-unmask!"));
lf[348]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot unblock signal"));
lf[349]=C_h_intern(&lf[349],13, C_text("scheme#vector"));
lf[350]=C_h_intern(&lf[350],11, C_text("scheme#list"));
lf[351]=C_h_intern(&lf[351],27, C_text("##sys#peek-nonnull-c-string"));
lf[352]=C_h_intern(&lf[352],16, C_text("user-information"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030cannot change file owner"));
lf[354]=C_decode_literal(C_heaptop,C_text("\376B\000\0000bad argument type - not a fixnum, port or string"));
lf[355]=C_h_intern(&lf[355],17, C_text("##sys#error/errno"));
lf[356]=C_h_intern(&lf[356],14, C_text("create-session"));
lf[357]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot create session"));
lf[358]=C_h_intern(&lf[358],20, C_text("create-symbolic-link"));
lf[359]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033cannot create symbolic link"));
lf[360]=C_h_intern(&lf[360],24, C_text("##sys#read-symbolic-link"));
lf[361]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031cannot read symbolic link"));
lf[362]=C_h_intern(&lf[362],16, C_text("scheme#substring"));
lf[363]=C_h_intern(&lf[363],18, C_text("read-symbolic-link"));
lf[364]=C_h_intern(&lf[364],36, C_text("chicken.pathname#decompose-directory"));
lf[365]=C_h_intern(&lf[365],30, C_text("chicken.pathname#make-pathname"));
lf[366]=C_h_intern(&lf[366],35, C_text("chicken.pathname#absolute-pathname\077"));
lf[367]=C_decode_literal(C_heaptop,C_text("\376B\000\000Icould not canonicalize path with symbolic links, component does not exist"));
lf[368]=C_h_intern(&lf[368],18, C_text("##sys#file-exists\077"));
lf[369]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[370]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[371]=C_h_intern(&lf[371],9, C_text("file-link"));
lf[372]=C_h_intern(&lf[372],9, C_text("hard-link"));
lf[373]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032could not create hard link"));
lf[374]=C_h_intern(&lf[374],23, C_text("##sys#custom-input-port"));
lf[375]=C_h_intern(&lf[375],17, C_text("chicken.base#void"));
lf[376]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015cannot select"));
lf[377]=C_h_intern(&lf[377],19, C_text("##sys#thread-yield!"));
lf[378]=C_h_intern(&lf[378],27, C_text("##sys#thread-block-for-i/o!"));
lf[379]=C_h_intern(&lf[379],20, C_text("##sys#current-thread"));
lf[380]=C_h_intern_kw(&lf[380],5, C_text("input"));
lf[381]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013cannot read"));
lf[382]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013cannot read"));
lf[383]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014cannot close"));
lf[384]=C_h_intern(&lf[384],35, C_text("chicken.fixnum#most-positive-fixnum"));
lf[385]=C_h_intern(&lf[385],22, C_text("##sys#scan-buffer-line"));
lf[386]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[387]=C_h_intern(&lf[387],28, C_text("chicken.port#make-input-port"));
lf[388]=C_h_intern(&lf[388],24, C_text("##sys#custom-output-port"));
lf[389]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014cannot write"));
lf[390]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014cannot close"));
lf[391]=C_h_intern(&lf[391],29, C_text("chicken.port#make-output-port"));
lf[392]=C_h_intern(&lf[392],13, C_text("file-truncate"));
lf[393]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot truncate file"));
lf[394]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid file"));
lf[395]=C_h_intern(&lf[395],4, C_text("lock"));
lf[396]=C_h_intern(&lf[396],9, C_text("file-lock"));
lf[397]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot lock file"));
lf[398]=C_h_intern(&lf[398],18, C_text("file-lock/blocking"));
lf[399]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot lock file"));
lf[400]=C_h_intern(&lf[400],14, C_text("file-test-lock"));
lf[401]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot unlock file"));
lf[402]=C_h_intern(&lf[402],11, C_text("file-unlock"));
lf[403]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot unlock file"));
lf[404]=C_h_intern(&lf[404],11, C_text("create-fifo"));
lf[405]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot create FIFO"));
lf[406]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027%a %b %e %H:%M:%S %Z %Y"));
lf[407]=C_h_intern(&lf[407],12, C_text("string->time"));
lf[408]=C_h_intern(&lf[408],17, C_text("utc-time->seconds"));
lf[409]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot convert time vector to seconds"));
lf[410]=C_h_intern(&lf[410],24, C_text("##sys#kill-other-threads"));
lf[411]=C_h_intern(&lf[411],17, C_text("chicken.base#exit"));
lf[412]=C_h_intern(&lf[412],23, C_text("##sys#call-with-cthulhu"));
lf[413]=C_h_intern(&lf[413],12, C_text("process-fork"));
lf[414]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033cannot create child process"));
lf[415]=C_h_intern(&lf[415],15, C_text("process-execute"));
lf[416]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026cannot execute process"));
lf[417]=C_h_intern(&lf[417],14, C_text("process-signal"));
lf[418]=C_decode_literal(C_heaptop,C_text("\376B\000\000 could not send signal to process"));
lf[419]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007/bin/sh"));
lf[420]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-c"));
lf[421]=C_h_intern(&lf[421],48, C_text("chicken.process-context#get-environment-variable"));
lf[422]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005SHELL"));
lf[423]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025abnormal process exit"));
lf[425]=C_h_intern(&lf[425],7, C_text("process"));
lf[426]=C_h_intern(&lf[426],8, C_text("process\052"));
lf[427]=C_h_intern(&lf[427],19, C_text("set-root-directory!"));
lf[428]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037unable to change root directory"));
lf[429]=C_decode_literal(C_heaptop,C_text("\376B\000\000/this function is not available on this platform"));
lf[430]=C_h_intern(&lf[430],14, C_text("chicken.errno#"));
lf[431]=C_h_intern(&lf[431],19, C_text("chicken.errno#errno"));
lf[432]=C_h_intern(&lf[432],11, C_text("##sys#errno"));
lf[433]=C_h_intern(&lf[433],24, C_text("chicken.errno#errno/2big"));
lf[434]=C_h_intern(&lf[434],25, C_text("chicken.errno#errno/acces"));
lf[435]=C_h_intern(&lf[435],25, C_text("chicken.errno#errno/again"));
lf[436]=C_h_intern(&lf[436],24, C_text("chicken.errno#errno/badf"));
lf[437]=C_h_intern(&lf[437],24, C_text("chicken.errno#errno/busy"));
lf[438]=C_h_intern(&lf[438],25, C_text("chicken.errno#errno/child"));
lf[439]=C_h_intern(&lf[439],26, C_text("chicken.errno#errno/deadlk"));
lf[440]=C_h_intern(&lf[440],23, C_text("chicken.errno#errno/dom"));
lf[441]=C_h_intern(&lf[441],25, C_text("chicken.errno#errno/exist"));
lf[442]=C_h_intern(&lf[442],25, C_text("chicken.errno#errno/fault"));
lf[443]=C_h_intern(&lf[443],24, C_text("chicken.errno#errno/fbig"));
lf[444]=C_h_intern(&lf[444],25, C_text("chicken.errno#errno/ilseq"));
lf[445]=C_h_intern(&lf[445],24, C_text("chicken.errno#errno/intr"));
lf[446]=C_h_intern(&lf[446],25, C_text("chicken.errno#errno/inval"));
lf[447]=C_h_intern(&lf[447],22, C_text("chicken.errno#errno/io"));
lf[448]=C_h_intern(&lf[448],25, C_text("chicken.errno#errno/isdir"));
lf[449]=C_h_intern(&lf[449],25, C_text("chicken.errno#errno/mfile"));
lf[450]=C_h_intern(&lf[450],25, C_text("chicken.errno#errno/mlink"));
lf[451]=C_h_intern(&lf[451],31, C_text("chicken.errno#errno/nametoolong"));
lf[452]=C_h_intern(&lf[452],25, C_text("chicken.errno#errno/nfile"));
lf[453]=C_h_intern(&lf[453],25, C_text("chicken.errno#errno/nodev"));
lf[454]=C_h_intern(&lf[454],25, C_text("chicken.errno#errno/noent"));
lf[455]=C_h_intern(&lf[455],26, C_text("chicken.errno#errno/noexec"));
lf[456]=C_h_intern(&lf[456],25, C_text("chicken.errno#errno/nolck"));
lf[457]=C_h_intern(&lf[457],25, C_text("chicken.errno#errno/nomem"));
lf[458]=C_h_intern(&lf[458],25, C_text("chicken.errno#errno/nospc"));
lf[459]=C_h_intern(&lf[459],25, C_text("chicken.errno#errno/nosys"));
lf[460]=C_h_intern(&lf[460],26, C_text("chicken.errno#errno/notdir"));
lf[461]=C_h_intern(&lf[461],28, C_text("chicken.errno#errno/notempty"));
lf[462]=C_h_intern(&lf[462],25, C_text("chicken.errno#errno/notty"));
lf[463]=C_h_intern(&lf[463],24, C_text("chicken.errno#errno/nxio"));
lf[464]=C_h_intern(&lf[464],24, C_text("chicken.errno#errno/perm"));
lf[465]=C_h_intern(&lf[465],24, C_text("chicken.errno#errno/pipe"));
lf[466]=C_h_intern(&lf[466],25, C_text("chicken.errno#errno/range"));
lf[467]=C_h_intern(&lf[467],24, C_text("chicken.errno#errno/rofs"));
lf[468]=C_h_intern(&lf[468],25, C_text("chicken.errno#errno/spipe"));
lf[469]=C_h_intern(&lf[469],24, C_text("chicken.errno#errno/srch"));
lf[470]=C_h_intern(&lf[470],30, C_text("chicken.errno#errno/wouldblock"));
lf[471]=C_h_intern(&lf[471],24, C_text("chicken.errno#errno/xdev"));
lf[472]=C_h_intern(&lf[472],16, C_text("process-group-id"));
lf[473]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot retrieve process group ID"));
lf[474]=C_h_intern(&lf[474],13, C_text("process-group"));
lf[475]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033cannot set process group ID"));
lf[476]=C_h_intern(&lf[476],31, C_text("chicken.base#getter-with-setter"));
lf[477]=C_decode_literal(C_heaptop,C_text("\376B\000\0004(chicken.process-context.posix#process-group-id pid)"));
lf[478]=C_h_intern(&lf[478],26, C_text("effective-group-id!-setter"));
lf[479]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035cannot set effective group ID"));
lf[480]=C_h_intern(&lf[480],26, C_text("current-effective-group-id"));
lf[481]=C_decode_literal(C_heaptop,C_text("\376B\000\000:(chicken.process-context.posix#current-effective-group-id)"));
lf[482]=C_h_intern(&lf[482],24, C_text("current-group-id!-setter"));
lf[483]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023cannot set group ID"));
lf[484]=C_h_intern(&lf[484],16, C_text("current-group-id"));
lf[485]=C_decode_literal(C_heaptop,C_text("\376B\000\0000(chicken.process-context.posix#current-group-id)"));
lf[486]=C_h_intern(&lf[486],25, C_text("effective-user-id!-setter"));
lf[487]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034cannot set effective user ID"));
lf[488]=C_h_intern(&lf[488],25, C_text("current-effective-user-id"));
lf[489]=C_decode_literal(C_heaptop,C_text("\376B\000\0009(chicken.process-context.posix#current-effective-user-id)"));
lf[490]=C_h_intern(&lf[490],23, C_text("current-user-id!-setter"));
lf[491]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot set user ID"));
lf[492]=C_h_intern(&lf[492],15, C_text("current-user-id"));
lf[493]=C_decode_literal(C_heaptop,C_text("\376B\000\000/(chicken.process-context.posix#current-user-id)"));
lf[494]=C_decode_literal(C_heaptop,C_text("\376B\000\000$(chicken.process.signal#signal-mask)"));
lf[495]=C_h_intern(&lf[495],14, C_text("signal-handler"));
lf[496]=C_decode_literal(C_heaptop,C_text("\376B\000\000+(chicken.process.signal#signal-handler sig)"));
lf[497]=C_h_intern(&lf[497],18, C_text("file-creation-mode"));
lf[498]=C_decode_literal(C_heaptop,C_text("\376B\000\000,(chicken.file.posix#file-creation-mode mode)"));
lf[499]=C_h_intern(&lf[499],13, C_text("file-position"));
lf[500]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot retrieve file position of port"));
lf[501]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid file"));
lf[502]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047(chicken.file.posix#file-position port)"));
lf[503]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047(chicken.file.posix#file-permissions f)"));
lf[504]=C_h_intern(&lf[504],10, C_text("file-group"));
lf[505]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.file.posix#file-group f)"));
lf[506]=C_h_intern(&lf[506],10, C_text("file-owner"));
lf[507]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.file.posix#file-owner f)"));
C_register_lf2(lf,508,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2683,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_scheduler_toplevel(2,av2);}}

/* va8871 in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall va8871(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(114,0,4)))){
C_save_and_reclaim_args((void *)trva8871,2,t0,t1);}
a=C_alloc(114);
t2=C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IWOTH));
t3=C_mutate((C_word*)lf[19]+1 /* (set! chicken.file.posix#file-open ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4771,a[2]=t2,a[3]=((C_word)li101),tmp=(C_word)a,a+=4,tmp));
t4=C_mutate((C_word*)lf[11]+1 /* (set! chicken.file.posix#file-close ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4803,a[2]=((C_word)li103),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[23]+1 /* (set! chicken.file.posix#file-read ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4834,a[2]=((C_word)li104),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[28]+1 /* (set! chicken.file.posix#file-write ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4874,a[2]=((C_word)li105),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[18]+1 /* (set! chicken.file.posix#file-mkstemp ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4911,a[2]=((C_word)li106),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[24]+1 /* (set! chicken.file.posix#file-select ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4943,a[2]=((C_word)li111),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[117]+1 /* (set! chicken.process#create-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5322,a[2]=((C_word)li112),tmp=(C_word)a,a+=3,tmp));
t10=C_set_block_item(lf[160] /* chicken.process.signal#signal/term */,0,C_fix((C_word)SIGTERM));
t11=C_set_block_item(lf[154] /* chicken.process.signal#signal/kill */,0,C_fix((C_word)SIGKILL));
t12=C_set_block_item(lf[152] /* chicken.process.signal#signal/int */,0,C_fix((C_word)SIGINT));
t13=C_set_block_item(lf[150] /* chicken.process.signal#signal/hup */,0,C_fix((C_word)SIGHUP));
t14=C_set_block_item(lf[149] /* chicken.process.signal#signal/fpe */,0,C_fix((C_word)SIGFPE));
t15=C_set_block_item(lf[151] /* chicken.process.signal#signal/ill */,0,C_fix((C_word)SIGILL));
t16=C_set_block_item(lf[158] /* chicken.process.signal#signal/segv */,0,C_fix((C_word)SIGSEGV));
t17=C_set_block_item(lf[143] /* chicken.process.signal#signal/abrt */,0,C_fix((C_word)SIGABRT));
t18=C_set_block_item(lf[161] /* chicken.process.signal#signal/trap */,0,C_fix((C_word)SIGTRAP));
t19=C_set_block_item(lf[157] /* chicken.process.signal#signal/quit */,0,C_fix((C_word)SIGQUIT));
t20=C_set_block_item(lf[144] /* chicken.process.signal#signal/alrm */,0,C_fix((C_word)SIGALRM));
t21=C_set_block_item(lf[166] /* chicken.process.signal#signal/vtalrm */,0,C_fix((C_word)SIGVTALRM));
t22=C_set_block_item(lf[156] /* chicken.process.signal#signal/prof */,0,C_fix((C_word)SIGPROF));
t23=C_set_block_item(lf[153] /* chicken.process.signal#signal/io */,0,C_fix((C_word)SIGIO));
t24=C_set_block_item(lf[163] /* chicken.process.signal#signal/urg */,0,C_fix((C_word)SIGURG));
t25=C_set_block_item(lf[147] /* chicken.process.signal#signal/chld */,0,C_fix((C_word)SIGCHLD));
t26=C_set_block_item(lf[148] /* chicken.process.signal#signal/cont */,0,C_fix((C_word)SIGCONT));
t27=C_set_block_item(lf[159] /* chicken.process.signal#signal/stop */,0,C_fix((C_word)SIGSTOP));
t28=C_set_block_item(lf[162] /* chicken.process.signal#signal/tstp */,0,C_fix((C_word)SIGTSTP));
t29=C_set_block_item(lf[155] /* chicken.process.signal#signal/pipe */,0,C_fix((C_word)SIGPIPE));
t30=C_set_block_item(lf[168] /* chicken.process.signal#signal/xcpu */,0,C_fix((C_word)SIGXCPU));
t31=C_set_block_item(lf[169] /* chicken.process.signal#signal/xfsz */,0,C_fix((C_word)SIGXFSZ));
t32=C_set_block_item(lf[164] /* chicken.process.signal#signal/usr1 */,0,C_fix((C_word)SIGUSR1));
t33=C_set_block_item(lf[165] /* chicken.process.signal#signal/usr2 */,0,C_fix((C_word)SIGUSR2));
t34=C_set_block_item(lf[167] /* chicken.process.signal#signal/winch */,0,C_fix((C_word)SIGWINCH));
t35=C_set_block_item(lf[146] /* chicken.process.signal#signal/bus */,0,C_fix((C_word)SIGBUS));
t36=C_set_block_item(lf[145] /* chicken.process.signal#signal/break */,0,C_fix(0));
t37=C_a_i_list(&a,26,*((C_word*)lf[160]+1),*((C_word*)lf[154]+1),*((C_word*)lf[152]+1),*((C_word*)lf[150]+1),*((C_word*)lf[149]+1),*((C_word*)lf[151]+1),*((C_word*)lf[158]+1),*((C_word*)lf[143]+1),*((C_word*)lf[161]+1),*((C_word*)lf[157]+1),*((C_word*)lf[144]+1),*((C_word*)lf[166]+1),*((C_word*)lf[156]+1),*((C_word*)lf[153]+1),*((C_word*)lf[163]+1),*((C_word*)lf[147]+1),*((C_word*)lf[148]+1),*((C_word*)lf[159]+1),*((C_word*)lf[162]+1),*((C_word*)lf[155]+1),*((C_word*)lf[168]+1),*((C_word*)lf[169]+1),*((C_word*)lf[164]+1),*((C_word*)lf[165]+1),*((C_word*)lf[167]+1),*((C_word*)lf[146]+1));
t38=C_mutate((C_word*)lf[170]+1 /* (set! chicken.process.signal#signals-list ...) */,t37);
t39=C_mutate((C_word*)lf[134]+1 /* (set! chicken.process.signal#set-signal-mask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5378,a[2]=((C_word)li114),tmp=(C_word)a,a+=3,tmp));
t40=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5427,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t41=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7915,a[2]=((C_word)li218),tmp=(C_word)a,a+=3,tmp);
/* posixunix.scm:563: chicken.base#getter-with-setter */
t42=*((C_word*)lf[476]+1);{
C_word av2[5];
av2[0]=t42;
av2[1]=t40;
av2[2]=t41;
av2[3]=*((C_word*)lf[134]+1);
av2[4]=lf[494];
((C_proc)(void*)(*((C_word*)t42+1)))(5,av2);}}

/* va8873 in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall va8873(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva8873,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va8871(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IROTH)));}

/* va8875 in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall va8875(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva8875,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va8873(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IWGRP)));}

/* va8877 in k3927 in k3692 in k3475 in k3258 in k3254 in k3250 in k2696 in k2693 in k2690 in k2687 in k2684 in k2681 */
static void C_fcall va8877(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva8877,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va8875(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IRGRP)));}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[531] = {
{C_text("f8882:posix_2escm"),(void*)f8882},
{C_text("f8886:posix_2escm"),(void*)f8886},
{C_text("f8930:posix_2escm"),(void*)f8930},
{C_text("f8936:posix_2escm"),(void*)f8936},
{C_text("f_2683:posix_2escm"),(void*)f_2683},
{C_text("f_2686:posix_2escm"),(void*)f_2686},
{C_text("f_2689:posix_2escm"),(void*)f_2689},
{C_text("f_2692:posix_2escm"),(void*)f_2692},
{C_text("f_2695:posix_2escm"),(void*)f_2695},
{C_text("f_2698:posix_2escm"),(void*)f_2698},
{C_text("f_2784:posix_2escm"),(void*)f_2784},
{C_text("f_2801:posix_2escm"),(void*)f_2801},
{C_text("f_2803:posix_2escm"),(void*)f_2803},
{C_text("f_2807:posix_2escm"),(void*)f_2807},
{C_text("f_2819:posix_2escm"),(void*)f_2819},
{C_text("f_2823:posix_2escm"),(void*)f_2823},
{C_text("f_2833:posix_2escm"),(void*)f_2833},
{C_text("f_2854:posix_2escm"),(void*)f_2854},
{C_text("f_2857:posix_2escm"),(void*)f_2857},
{C_text("f_2868:posix_2escm"),(void*)f_2868},
{C_text("f_2874:posix_2escm"),(void*)f_2874},
{C_text("f_2899:posix_2escm"),(void*)f_2899},
{C_text("f_3009:posix_2escm"),(void*)f_3009},
{C_text("f_3013:posix_2escm"),(void*)f_3013},
{C_text("f_3020:posix_2escm"),(void*)f_3020},
{C_text("f_3024:posix_2escm"),(void*)f_3024},
{C_text("f_3027:posix_2escm"),(void*)f_3027},
{C_text("f_3031:posix_2escm"),(void*)f_3031},
{C_text("f_3052:posix_2escm"),(void*)f_3052},
{C_text("f_3056:posix_2escm"),(void*)f_3056},
{C_text("f_3065:posix_2escm"),(void*)f_3065},
{C_text("f_3073:posix_2escm"),(void*)f_3073},
{C_text("f_3080:posix_2escm"),(void*)f_3080},
{C_text("f_3091:posix_2escm"),(void*)f_3091},
{C_text("f_3095:posix_2escm"),(void*)f_3095},
{C_text("f_3098:posix_2escm"),(void*)f_3098},
{C_text("f_3116:posix_2escm"),(void*)f_3116},
{C_text("f_3120:posix_2escm"),(void*)f_3120},
{C_text("f_3130:posix_2escm"),(void*)f_3130},
{C_text("f_3135:posix_2escm"),(void*)f_3135},
{C_text("f_3139:posix_2escm"),(void*)f_3139},
{C_text("f_3141:posix_2escm"),(void*)f_3141},
{C_text("f_3145:posix_2escm"),(void*)f_3145},
{C_text("f_3147:posix_2escm"),(void*)f_3147},
{C_text("f_3151:posix_2escm"),(void*)f_3151},
{C_text("f_3153:posix_2escm"),(void*)f_3153},
{C_text("f_3157:posix_2escm"),(void*)f_3157},
{C_text("f_3169:posix_2escm"),(void*)f_3169},
{C_text("f_3172:posix_2escm"),(void*)f_3172},
{C_text("f_3178:posix_2escm"),(void*)f_3178},
{C_text("f_3188:posix_2escm"),(void*)f_3188},
{C_text("f_3232:posix_2escm"),(void*)f_3232},
{C_text("f_3236:posix_2escm"),(void*)f_3236},
{C_text("f_3238:posix_2escm"),(void*)f_3238},
{C_text("f_3244:posix_2escm"),(void*)f_3244},
{C_text("f_3252:posix_2escm"),(void*)f_3252},
{C_text("f_3256:posix_2escm"),(void*)f_3256},
{C_text("f_3260:posix_2escm"),(void*)f_3260},
{C_text("f_3262:posix_2escm"),(void*)f_3262},
{C_text("f_3281:posix_2escm"),(void*)f_3281},
{C_text("f_3349:posix_2escm"),(void*)f_3349},
{C_text("f_3357:posix_2escm"),(void*)f_3357},
{C_text("f_3359:posix_2escm"),(void*)f_3359},
{C_text("f_3367:posix_2escm"),(void*)f_3367},
{C_text("f_3369:posix_2escm"),(void*)f_3369},
{C_text("f_3377:posix_2escm"),(void*)f_3377},
{C_text("f_3379:posix_2escm"),(void*)f_3379},
{C_text("f_3387:posix_2escm"),(void*)f_3387},
{C_text("f_3389:posix_2escm"),(void*)f_3389},
{C_text("f_3397:posix_2escm"),(void*)f_3397},
{C_text("f_3399:posix_2escm"),(void*)f_3399},
{C_text("f_3407:posix_2escm"),(void*)f_3407},
{C_text("f_3409:posix_2escm"),(void*)f_3409},
{C_text("f_3417:posix_2escm"),(void*)f_3417},
{C_text("f_3422:posix_2escm"),(void*)f_3422},
{C_text("f_3429:posix_2escm"),(void*)f_3429},
{C_text("f_3432:posix_2escm"),(void*)f_3432},
{C_text("f_3438:posix_2escm"),(void*)f_3438},
{C_text("f_3444:posix_2escm"),(void*)f_3444},
{C_text("f_3477:posix_2escm"),(void*)f_3477},
{C_text("f_3505:posix_2escm"),(void*)f_3505},
{C_text("f_3513:posix_2escm"),(void*)f_3513},
{C_text("f_3542:posix_2escm"),(void*)f_3542},
{C_text("f_3555:posix_2escm"),(void*)f_3555},
{C_text("f_3561:posix_2escm"),(void*)f_3561},
{C_text("f_3565:posix_2escm"),(void*)f_3565},
{C_text("f_3573:posix_2escm"),(void*)f_3573},
{C_text("f_3575:posix_2escm"),(void*)f_3575},
{C_text("f_3579:posix_2escm"),(void*)f_3579},
{C_text("f_3587:posix_2escm"),(void*)f_3587},
{C_text("f_3589:posix_2escm"),(void*)f_3589},
{C_text("f_3605:posix_2escm"),(void*)f_3605},
{C_text("f_3614:posix_2escm"),(void*)f_3614},
{C_text("f_3628:posix_2escm"),(void*)f_3628},
{C_text("f_3634:posix_2escm"),(void*)f_3634},
{C_text("f_3638:posix_2escm"),(void*)f_3638},
{C_text("f_3641:posix_2escm"),(void*)f_3641},
{C_text("f_3644:posix_2escm"),(void*)f_3644},
{C_text("f_3659:posix_2escm"),(void*)f_3659},
{C_text("f_3661:posix_2escm"),(void*)f_3661},
{C_text("f_3664:posix_2escm"),(void*)f_3664},
{C_text("f_3668:posix_2escm"),(void*)f_3668},
{C_text("f_3671:posix_2escm"),(void*)f_3671},
{C_text("f_3680:posix_2escm"),(void*)f_3680},
{C_text("f_3694:posix_2escm"),(void*)f_3694},
{C_text("f_3697:posix_2escm"),(void*)f_3697},
{C_text("f_3716:posix_2escm"),(void*)f_3716},
{C_text("f_3720:posix_2escm"),(void*)f_3720},
{C_text("f_3723:posix_2escm"),(void*)f_3723},
{C_text("f_3737:posix_2escm"),(void*)f_3737},
{C_text("f_3741:posix_2escm"),(void*)f_3741},
{C_text("f_3744:posix_2escm"),(void*)f_3744},
{C_text("f_3769:posix_2escm"),(void*)f_3769},
{C_text("f_3773:posix_2escm"),(void*)f_3773},
{C_text("f_3776:posix_2escm"),(void*)f_3776},
{C_text("f_3779:posix_2escm"),(void*)f_3779},
{C_text("f_3807:posix_2escm"),(void*)f_3807},
{C_text("f_3811:posix_2escm"),(void*)f_3811},
{C_text("f_3815:posix_2escm"),(void*)f_3815},
{C_text("f_3852:posix_2escm"),(void*)f_3852},
{C_text("f_3859:posix_2escm"),(void*)f_3859},
{C_text("f_3868:posix_2escm"),(void*)f_3868},
{C_text("f_3878:posix_2escm"),(void*)f_3878},
{C_text("f_3882:posix_2escm"),(void*)f_3882},
{C_text("f_3885:posix_2escm"),(void*)f_3885},
{C_text("f_3906:posix_2escm"),(void*)f_3906},
{C_text("f_3914:posix_2escm"),(void*)f_3914},
{C_text("f_3918:posix_2escm"),(void*)f_3918},
{C_text("f_3929:posix_2escm"),(void*)f_3929},
{C_text("f_3931:posix_2escm"),(void*)f_3931},
{C_text("f_3935:posix_2escm"),(void*)f_3935},
{C_text("f_3936:posix_2escm"),(void*)f_3936},
{C_text("f_3940:posix_2escm"),(void*)f_3940},
{C_text("f_3945:posix_2escm"),(void*)f_3945},
{C_text("f_3952:posix_2escm"),(void*)f_3952},
{C_text("f_3953:posix_2escm"),(void*)f_3953},
{C_text("f_3974:posix_2escm"),(void*)f_3974},
{C_text("f_3984:posix_2escm"),(void*)f_3984},
{C_text("f_3997:posix_2escm"),(void*)f_3997},
{C_text("f_4001:posix_2escm"),(void*)f_4001},
{C_text("f_4006:posix_2escm"),(void*)f_4006},
{C_text("f_4010:posix_2escm"),(void*)f_4010},
{C_text("f_4015:posix_2escm"),(void*)f_4015},
{C_text("f_4019:posix_2escm"),(void*)f_4019},
{C_text("f_4021:posix_2escm"),(void*)f_4021},
{C_text("f_4040:posix_2escm"),(void*)f_4040},
{C_text("f_4045:posix_2escm"),(void*)f_4045},
{C_text("f_4051:posix_2escm"),(void*)f_4051},
{C_text("f_4092:posix_2escm"),(void*)f_4092},
{C_text("f_4100:posix_2escm"),(void*)f_4100},
{C_text("f_4103:posix_2escm"),(void*)f_4103},
{C_text("f_4108:posix_2escm"),(void*)f_4108},
{C_text("f_4114:posix_2escm"),(void*)f_4114},
{C_text("f_4120:posix_2escm"),(void*)f_4120},
{C_text("f_4124:posix_2escm"),(void*)f_4124},
{C_text("f_4129:posix_2escm"),(void*)f_4129},
{C_text("f_4131:posix_2escm"),(void*)f_4131},
{C_text("f_4135:posix_2escm"),(void*)f_4135},
{C_text("f_4137:posix_2escm"),(void*)f_4137},
{C_text("f_4153:posix_2escm"),(void*)f_4153},
{C_text("f_4159:posix_2escm"),(void*)f_4159},
{C_text("f_4162:posix_2escm"),(void*)f_4162},
{C_text("f_4178:posix_2escm"),(void*)f_4178},
{C_text("f_4188:posix_2escm"),(void*)f_4188},
{C_text("f_4194:posix_2escm"),(void*)f_4194},
{C_text("f_4205:posix_2escm"),(void*)f_4205},
{C_text("f_4209:posix_2escm"),(void*)f_4209},
{C_text("f_4213:posix_2escm"),(void*)f_4213},
{C_text("f_4218:posix_2escm"),(void*)f_4218},
{C_text("f_4228:posix_2escm"),(void*)f_4228},
{C_text("f_4231:posix_2escm"),(void*)f_4231},
{C_text("f_4243:posix_2escm"),(void*)f_4243},
{C_text("f_4248:posix_2escm"),(void*)f_4248},
{C_text("f_4267:posix_2escm"),(void*)f_4267},
{C_text("f_4290:posix_2escm"),(void*)f_4290},
{C_text("f_4292:posix_2escm"),(void*)f_4292},
{C_text("f_4299:posix_2escm"),(void*)f_4299},
{C_text("f_4302:posix_2escm"),(void*)f_4302},
{C_text("f_4307:posix_2escm"),(void*)f_4307},
{C_text("f_4313:posix_2escm"),(void*)f_4313},
{C_text("f_4319:posix_2escm"),(void*)f_4319},
{C_text("f_4323:posix_2escm"),(void*)f_4323},
{C_text("f_4326:posix_2escm"),(void*)f_4326},
{C_text("f_4334:posix_2escm"),(void*)f_4334},
{C_text("f_4340:posix_2escm"),(void*)f_4340},
{C_text("f_4344:posix_2escm"),(void*)f_4344},
{C_text("f_4351:posix_2escm"),(void*)f_4351},
{C_text("f_4354:posix_2escm"),(void*)f_4354},
{C_text("f_4358:posix_2escm"),(void*)f_4358},
{C_text("f_4379:posix_2escm"),(void*)f_4379},
{C_text("f_4381:posix_2escm"),(void*)f_4381},
{C_text("f_4406:posix_2escm"),(void*)f_4406},
{C_text("f_4415:posix_2escm"),(void*)f_4415},
{C_text("f_4421:posix_2escm"),(void*)f_4421},
{C_text("f_4446:posix_2escm"),(void*)f_4446},
{C_text("f_4459:posix_2escm"),(void*)f_4459},
{C_text("f_4465:posix_2escm"),(void*)f_4465},
{C_text("f_4479:posix_2escm"),(void*)f_4479},
{C_text("f_4486:posix_2escm"),(void*)f_4486},
{C_text("f_4496:posix_2escm"),(void*)f_4496},
{C_text("f_4505:posix_2escm"),(void*)f_4505},
{C_text("f_4519:posix_2escm"),(void*)f_4519},
{C_text("f_4526:posix_2escm"),(void*)f_4526},
{C_text("f_4536:posix_2escm"),(void*)f_4536},
{C_text("f_4545:posix_2escm"),(void*)f_4545},
{C_text("f_4552:posix_2escm"),(void*)f_4552},
{C_text("f_4560:posix_2escm"),(void*)f_4560},
{C_text("f_4567:posix_2escm"),(void*)f_4567},
{C_text("f_4575:posix_2escm"),(void*)f_4575},
{C_text("f_4579:posix_2escm"),(void*)f_4579},
{C_text("f_4584:posix_2escm"),(void*)f_4584},
{C_text("f_4589:posix_2escm"),(void*)f_4589},
{C_text("f_4595:posix_2escm"),(void*)f_4595},
{C_text("f_4599:posix_2escm"),(void*)f_4599},
{C_text("f_4604:posix_2escm"),(void*)f_4604},
{C_text("f_4609:posix_2escm"),(void*)f_4609},
{C_text("f_4613:posix_2escm"),(void*)f_4613},
{C_text("f_4618:posix_2escm"),(void*)f_4618},
{C_text("f_4624:posix_2escm"),(void*)f_4624},
{C_text("f_4628:posix_2escm"),(void*)f_4628},
{C_text("f_4633:posix_2escm"),(void*)f_4633},
{C_text("f_4637:posix_2escm"),(void*)f_4637},
{C_text("f_4642:posix_2escm"),(void*)f_4642},
{C_text("f_4648:posix_2escm"),(void*)f_4648},
{C_text("f_4652:posix_2escm"),(void*)f_4652},
{C_text("f_4657:posix_2escm"),(void*)f_4657},
{C_text("f_4661:posix_2escm"),(void*)f_4661},
{C_text("f_4666:posix_2escm"),(void*)f_4666},
{C_text("f_4671:posix_2escm"),(void*)f_4671},
{C_text("f_4677:posix_2escm"),(void*)f_4677},
{C_text("f_4681:posix_2escm"),(void*)f_4681},
{C_text("f_4686:posix_2escm"),(void*)f_4686},
{C_text("f_4691:posix_2escm"),(void*)f_4691},
{C_text("f_4698:posix_2escm"),(void*)f_4698},
{C_text("f_4738:posix_2escm"),(void*)f_4738},
{C_text("f_4745:posix_2escm"),(void*)f_4745},
{C_text("f_4748:posix_2escm"),(void*)f_4748},
{C_text("f_4771:posix_2escm"),(void*)f_4771},
{C_text("f_4781:posix_2escm"),(void*)f_4781},
{C_text("f_4784:posix_2escm"),(void*)f_4784},
{C_text("f_4788:posix_2escm"),(void*)f_4788},
{C_text("f_4791:posix_2escm"),(void*)f_4791},
{C_text("f_4803:posix_2escm"),(void*)f_4803},
{C_text("f_4807:posix_2escm"),(void*)f_4807},
{C_text("f_4812:posix_2escm"),(void*)f_4812},
{C_text("f_4834:posix_2escm"),(void*)f_4834},
{C_text("f_4838:posix_2escm"),(void*)f_4838},
{C_text("f_4841:posix_2escm"),(void*)f_4841},
{C_text("f_4844:posix_2escm"),(void*)f_4844},
{C_text("f_4847:posix_2escm"),(void*)f_4847},
{C_text("f_4850:posix_2escm"),(void*)f_4850},
{C_text("f_4874:posix_2escm"),(void*)f_4874},
{C_text("f_4878:posix_2escm"),(void*)f_4878},
{C_text("f_4881:posix_2escm"),(void*)f_4881},
{C_text("f_4887:posix_2escm"),(void*)f_4887},
{C_text("f_4890:posix_2escm"),(void*)f_4890},
{C_text("f_4911:posix_2escm"),(void*)f_4911},
{C_text("f_4918:posix_2escm"),(void*)f_4918},
{C_text("f_4924:posix_2escm"),(void*)f_4924},
{C_text("f_4931:posix_2escm"),(void*)f_4931},
{C_text("f_4943:posix_2escm"),(void*)f_4943},
{C_text("f_4950:posix_2escm"),(void*)f_4950},
{C_text("f_4953:posix_2escm"),(void*)f_4953},
{C_text("f_4961:posix_2escm"),(void*)f_4961},
{C_text("f_5022:posix_2escm"),(void*)f_5022},
{C_text("f_5025:posix_2escm"),(void*)f_5025},
{C_text("f_5032:posix_2escm"),(void*)f_5032},
{C_text("f_5062:posix_2escm"),(void*)f_5062},
{C_text("f_5121:posix_2escm"),(void*)f_5121},
{C_text("f_5182:posix_2escm"),(void*)f_5182},
{C_text("f_5189:posix_2escm"),(void*)f_5189},
{C_text("f_5197:posix_2escm"),(void*)f_5197},
{C_text("f_5199:posix_2escm"),(void*)f_5199},
{C_text("f_5241:posix_2escm"),(void*)f_5241},
{C_text("f_5322:posix_2escm"),(void*)f_5322},
{C_text("f_5329:posix_2escm"),(void*)f_5329},
{C_text("f_5378:posix_2escm"),(void*)f_5378},
{C_text("f_5387:posix_2escm"),(void*)f_5387},
{C_text("f_5390:posix_2escm"),(void*)f_5390},
{C_text("f_5402:posix_2escm"),(void*)f_5402},
{C_text("f_5427:posix_2escm"),(void*)f_5427},
{C_text("f_5429:posix_2escm"),(void*)f_5429},
{C_text("f_5433:posix_2escm"),(void*)f_5433},
{C_text("f_5435:posix_2escm"),(void*)f_5435},
{C_text("f_5439:posix_2escm"),(void*)f_5439},
{C_text("f_5451:posix_2escm"),(void*)f_5451},
{C_text("f_5455:posix_2escm"),(void*)f_5455},
{C_text("f_5469:posix_2escm"),(void*)f_5469},
{C_text("f_5473:posix_2escm"),(void*)f_5473},
{C_text("f_5477:posix_2escm"),(void*)f_5477},
{C_text("f_5481:posix_2escm"),(void*)f_5481},
{C_text("f_5483:posix_2escm"),(void*)f_5483},
{C_text("f_5490:posix_2escm"),(void*)f_5490},
{C_text("f_5503:posix_2escm"),(void*)f_5503},
{C_text("f_5507:posix_2escm"),(void*)f_5507},
{C_text("f_5511:posix_2escm"),(void*)f_5511},
{C_text("f_5515:posix_2escm"),(void*)f_5515},
{C_text("f_5519:posix_2escm"),(void*)f_5519},
{C_text("f_5529:posix_2escm"),(void*)f_5529},
{C_text("f_5537:posix_2escm"),(void*)f_5537},
{C_text("f_5545:posix_2escm"),(void*)f_5545},
{C_text("f_5549:posix_2escm"),(void*)f_5549},
{C_text("f_5551:posix_2escm"),(void*)f_5551},
{C_text("f_5559:posix_2escm"),(void*)f_5559},
{C_text("f_5563:posix_2escm"),(void*)f_5563},
{C_text("f_5565:posix_2escm"),(void*)f_5565},
{C_text("f_5569:posix_2escm"),(void*)f_5569},
{C_text("f_5572:posix_2escm"),(void*)f_5572},
{C_text("f_5575:posix_2escm"),(void*)f_5575},
{C_text("f_5587:posix_2escm"),(void*)f_5587},
{C_text("f_5591:posix_2escm"),(void*)f_5591},
{C_text("f_5607:posix_2escm"),(void*)f_5607},
{C_text("f_5612:posix_2escm"),(void*)f_5612},
{C_text("f_5616:posix_2escm"),(void*)f_5616},
{C_text("f_5626:posix_2escm"),(void*)f_5626},
{C_text("f_5630:posix_2escm"),(void*)f_5630},
{C_text("f_5632:posix_2escm"),(void*)f_5632},
{C_text("f_5653:posix_2escm"),(void*)f_5653},
{C_text("f_5657:posix_2escm"),(void*)f_5657},
{C_text("f_5661:posix_2escm"),(void*)f_5661},
{C_text("f_5662:posix_2escm"),(void*)f_5662},
{C_text("f_5667:posix_2escm"),(void*)f_5667},
{C_text("f_5681:posix_2escm"),(void*)f_5681},
{C_text("f_5696:posix_2escm"),(void*)f_5696},
{C_text("f_5702:posix_2escm"),(void*)f_5702},
{C_text("f_5710:posix_2escm"),(void*)f_5710},
{C_text("f_5712:posix_2escm"),(void*)f_5712},
{C_text("f_5722:posix_2escm"),(void*)f_5722},
{C_text("f_5728:posix_2escm"),(void*)f_5728},
{C_text("f_5737:posix_2escm"),(void*)f_5737},
{C_text("f_5740:posix_2escm"),(void*)f_5740},
{C_text("f_5743:posix_2escm"),(void*)f_5743},
{C_text("f_5749:posix_2escm"),(void*)f_5749},
{C_text("f_5783:posix_2escm"),(void*)f_5783},
{C_text("f_5787:posix_2escm"),(void*)f_5787},
{C_text("f_5796:posix_2escm"),(void*)f_5796},
{C_text("f_5818:posix_2escm"),(void*)f_5818},
{C_text("f_5846:posix_2escm"),(void*)f_5846},
{C_text("f_5852:posix_2escm"),(void*)f_5852},
{C_text("f_5853:posix_2escm"),(void*)f_5853},
{C_text("f_5857:posix_2escm"),(void*)f_5857},
{C_text("f_5882:posix_2escm"),(void*)f_5882},
{C_text("f_5890:posix_2escm"),(void*)f_5890},
{C_text("f_5896:posix_2escm"),(void*)f_5896},
{C_text("f_5915:posix_2escm"),(void*)f_5915},
{C_text("f_5918:posix_2escm"),(void*)f_5918},
{C_text("f_5948:posix_2escm"),(void*)f_5948},
{C_text("f_5951:posix_2escm"),(void*)f_5951},
{C_text("f_5957:posix_2escm"),(void*)f_5957},
{C_text("f_5986:posix_2escm"),(void*)f_5986},
{C_text("f_5992:posix_2escm"),(void*)f_5992},
{C_text("f_5996:posix_2escm"),(void*)f_5996},
{C_text("f_6017:posix_2escm"),(void*)f_6017},
{C_text("f_6029:posix_2escm"),(void*)f_6029},
{C_text("f_6033:posix_2escm"),(void*)f_6033},
{C_text("f_6045:posix_2escm"),(void*)f_6045},
{C_text("f_6049:posix_2escm"),(void*)f_6049},
{C_text("f_6060:posix_2escm"),(void*)f_6060},
{C_text("f_6070:posix_2escm"),(void*)f_6070},
{C_text("f_6118:posix_2escm"),(void*)f_6118},
{C_text("f_6136:posix_2escm"),(void*)f_6136},
{C_text("f_6140:posix_2escm"),(void*)f_6140},
{C_text("f_6154:posix_2escm"),(void*)f_6154},
{C_text("f_6164:posix_2escm"),(void*)f_6164},
{C_text("f_6184:posix_2escm"),(void*)f_6184},
{C_text("f_6210:posix_2escm"),(void*)f_6210},
{C_text("f_6255:posix_2escm"),(void*)f_6255},
{C_text("f_6265:posix_2escm"),(void*)f_6265},
{C_text("f_6331:posix_2escm"),(void*)f_6331},
{C_text("f_6353:posix_2escm"),(void*)f_6353},
{C_text("f_6354:posix_2escm"),(void*)f_6354},
{C_text("f_6360:posix_2escm"),(void*)f_6360},
{C_text("f_6379:posix_2escm"),(void*)f_6379},
{C_text("f_6410:posix_2escm"),(void*)f_6410},
{C_text("f_6420:posix_2escm"),(void*)f_6420},
{C_text("f_6425:posix_2escm"),(void*)f_6425},
{C_text("f_6431:posix_2escm"),(void*)f_6431},
{C_text("f_6437:posix_2escm"),(void*)f_6437},
{C_text("f_6441:posix_2escm"),(void*)f_6441},
{C_text("f_6453:posix_2escm"),(void*)f_6453},
{C_text("f_6461:posix_2escm"),(void*)f_6461},
{C_text("f_6475:posix_2escm"),(void*)f_6475},
{C_text("f_6476:posix_2escm"),(void*)f_6476},
{C_text("f_6493:posix_2escm"),(void*)f_6493},
{C_text("f_6503:posix_2escm"),(void*)f_6503},
{C_text("f_6586:posix_2escm"),(void*)f_6586},
{C_text("f_6590:posix_2escm"),(void*)f_6590},
{C_text("f_6596:posix_2escm"),(void*)f_6596},
{C_text("f_6603:posix_2escm"),(void*)f_6603},
{C_text("f_6610:posix_2escm"),(void*)f_6610},
{C_text("f_6616:posix_2escm"),(void*)f_6616},
{C_text("f_6620:posix_2escm"),(void*)f_6620},
{C_text("f_6631:posix_2escm"),(void*)f_6631},
{C_text("f_6649:posix_2escm"),(void*)f_6649},
{C_text("f_6652:posix_2escm"),(void*)f_6652},
{C_text("f_6717:posix_2escm"),(void*)f_6717},
{C_text("f_6723:posix_2escm"),(void*)f_6723},
{C_text("f_6727:posix_2escm"),(void*)f_6727},
{C_text("f_6748:posix_2escm"),(void*)f_6748},
{C_text("f_6754:posix_2escm"),(void*)f_6754},
{C_text("f_6758:posix_2escm"),(void*)f_6758},
{C_text("f_6779:posix_2escm"),(void*)f_6779},
{C_text("f_6783:posix_2escm"),(void*)f_6783},
{C_text("f_6806:posix_2escm"),(void*)f_6806},
{C_text("f_6835:posix_2escm"),(void*)f_6835},
{C_text("f_6849:posix_2escm"),(void*)f_6849},
{C_text("f_6859:posix_2escm"),(void*)f_6859},
{C_text("f_6873:posix_2escm"),(void*)f_6873},
{C_text("f_6895:posix_2escm"),(void*)f_6895},
{C_text("f_6912:posix_2escm"),(void*)f_6912},
{C_text("f_6916:posix_2escm"),(void*)f_6916},
{C_text("f_6924:posix_2escm"),(void*)f_6924},
{C_text("f_6932:posix_2escm"),(void*)f_6932},
{C_text("f_6936:posix_2escm"),(void*)f_6936},
{C_text("f_6940:posix_2escm"),(void*)f_6940},
{C_text("f_6951:posix_2escm"),(void*)f_6951},
{C_text("f_6958:posix_2escm"),(void*)f_6958},
{C_text("f_6967:posix_2escm"),(void*)f_6967},
{C_text("f_6998:posix_2escm"),(void*)f_6998},
{C_text("f_7012:posix_2escm"),(void*)f_7012},
{C_text("f_7018:posix_2escm"),(void*)f_7018},
{C_text("f_7022:posix_2escm"),(void*)f_7022},
{C_text("f_7026:posix_2escm"),(void*)f_7026},
{C_text("f_7066:posix_2escm"),(void*)f_7066},
{C_text("f_7090:posix_2escm"),(void*)f_7090},
{C_text("f_7093:posix_2escm"),(void*)f_7093},
{C_text("f_7144:posix_2escm"),(void*)f_7144},
{C_text("f_7160:posix_2escm"),(void*)f_7160},
{C_text("f_7182:posix_2escm"),(void*)f_7182},
{C_text("f_7185:posix_2escm"),(void*)f_7185},
{C_text("f_7192:posix_2escm"),(void*)f_7192},
{C_text("f_7195:posix_2escm"),(void*)f_7195},
{C_text("f_7225:posix_2escm"),(void*)f_7225},
{C_text("f_7232:posix_2escm"),(void*)f_7232},
{C_text("f_7275:posix_2escm"),(void*)f_7275},
{C_text("f_7279:posix_2escm"),(void*)f_7279},
{C_text("f_7281:posix_2escm"),(void*)f_7281},
{C_text("f_7296:posix_2escm"),(void*)f_7296},
{C_text("f_7302:posix_2escm"),(void*)f_7302},
{C_text("f_7316:posix_2escm"),(void*)f_7316},
{C_text("f_7325:posix_2escm"),(void*)f_7325},
{C_text("f_7331:posix_2escm"),(void*)f_7331},
{C_text("f_7336:posix_2escm"),(void*)f_7336},
{C_text("f_7347:posix_2escm"),(void*)f_7347},
{C_text("f_7348:posix_2escm"),(void*)f_7348},
{C_text("f_7359:posix_2escm"),(void*)f_7359},
{C_text("f_7377:posix_2escm"),(void*)f_7377},
{C_text("f_7381:posix_2escm"),(void*)f_7381},
{C_text("f_7384:posix_2escm"),(void*)f_7384},
{C_text("f_7387:posix_2escm"),(void*)f_7387},
{C_text("f_7394:posix_2escm"),(void*)f_7394},
{C_text("f_7398:posix_2escm"),(void*)f_7398},
{C_text("f_7400:posix_2escm"),(void*)f_7400},
{C_text("f_7404:posix_2escm"),(void*)f_7404},
{C_text("f_7407:posix_2escm"),(void*)f_7407},
{C_text("f_7410:posix_2escm"),(void*)f_7410},
{C_text("f_7422:posix_2escm"),(void*)f_7422},
{C_text("f_7426:posix_2escm"),(void*)f_7426},
{C_text("f_7433:posix_2escm"),(void*)f_7433},
{C_text("f_7437:posix_2escm"),(void*)f_7437},
{C_text("f_7444:posix_2escm"),(void*)f_7444},
{C_text("f_7450:posix_2escm"),(void*)f_7450},
{C_text("f_7456:posix_2escm"),(void*)f_7456},
{C_text("f_7467:posix_2escm"),(void*)f_7467},
{C_text("f_7471:posix_2escm"),(void*)f_7471},
{C_text("f_7475:posix_2escm"),(void*)f_7475},
{C_text("f_7479:posix_2escm"),(void*)f_7479},
{C_text("f_7483:posix_2escm"),(void*)f_7483},
{C_text("f_7487:posix_2escm"),(void*)f_7487},
{C_text("f_7500:posix_2escm"),(void*)f_7500},
{C_text("f_7502:posix_2escm"),(void*)f_7502},
{C_text("f_7507:posix_2escm"),(void*)f_7507},
{C_text("f_7516:posix_2escm"),(void*)f_7516},
{C_text("f_7543:posix_2escm"),(void*)f_7543},
{C_text("f_7546:posix_2escm"),(void*)f_7546},
{C_text("f_7551:posix_2escm"),(void*)f_7551},
{C_text("f_7571:posix_2escm"),(void*)f_7571},
{C_text("f_7595:posix_2escm"),(void*)f_7595},
{C_text("f_7637:posix_2escm"),(void*)f_7637},
{C_text("f_7702:posix_2escm"),(void*)f_7702},
{C_text("f_7707:posix_2escm"),(void*)f_7707},
{C_text("f_7726:posix_2escm"),(void*)f_7726},
{C_text("f_7732:posix_2escm"),(void*)f_7732},
{C_text("f_7781:posix_2escm"),(void*)f_7781},
{C_text("f_7785:posix_2escm"),(void*)f_7785},
{C_text("f_7788:posix_2escm"),(void*)f_7788},
{C_text("f_7798:posix_2escm"),(void*)f_7798},
{C_text("f_7800:posix_2escm"),(void*)f_7800},
{C_text("f_7804:posix_2escm"),(void*)f_7804},
{C_text("f_7807:posix_2escm"),(void*)f_7807},
{C_text("f_7820:posix_2escm"),(void*)f_7820},
{C_text("f_7823:posix_2escm"),(void*)f_7823},
{C_text("f_7826:posix_2escm"),(void*)f_7826},
{C_text("f_7830:posix_2escm"),(void*)f_7830},
{C_text("f_7843:posix_2escm"),(void*)f_7843},
{C_text("f_7846:posix_2escm"),(void*)f_7846},
{C_text("f_7849:posix_2escm"),(void*)f_7849},
{C_text("f_7853:posix_2escm"),(void*)f_7853},
{C_text("f_7866:posix_2escm"),(void*)f_7866},
{C_text("f_7869:posix_2escm"),(void*)f_7869},
{C_text("f_7872:posix_2escm"),(void*)f_7872},
{C_text("f_7876:posix_2escm"),(void*)f_7876},
{C_text("f_7889:posix_2escm"),(void*)f_7889},
{C_text("f_7892:posix_2escm"),(void*)f_7892},
{C_text("f_7895:posix_2escm"),(void*)f_7895},
{C_text("f_7899:posix_2escm"),(void*)f_7899},
{C_text("f_7912:posix_2escm"),(void*)f_7912},
{C_text("f_7915:posix_2escm"),(void*)f_7915},
{C_text("f_7921:posix_2escm"),(void*)f_7921},
{C_text("f_7945:posix_2escm"),(void*)f_7945},
{C_text("f_7949:posix_2escm"),(void*)f_7949},
{C_text("f_7954:posix_2escm"),(void*)f_7954},
{C_text("f_7961:posix_2escm"),(void*)f_7961},
{C_text("f_7979:posix_2escm"),(void*)f_7979},
{C_text("f_7983:posix_2escm"),(void*)f_7983},
{C_text("f_7985:posix_2escm"),(void*)f_7985},
{C_text("f_7989:posix_2escm"),(void*)f_7989},
{C_text("f_7992:posix_2escm"),(void*)f_7992},
{C_text("f_8001:posix_2escm"),(void*)f_8001},
{C_text("f_8022:posix_2escm"),(void*)f_8022},
{C_text("f_8026:posix_2escm"),(void*)f_8026},
{C_text("f_8028:posix_2escm"),(void*)f_8028},
{C_text("f_8032:posix_2escm"),(void*)f_8032},
{C_text("f_8034:posix_2escm"),(void*)f_8034},
{C_text("f_8038:posix_2escm"),(void*)f_8038},
{C_text("toplevel:posix_2escm"),(void*)C_posix_toplevel},
{C_text("va8871:posix_2escm"),(void*)va8871},
{C_text("va8873:posix_2escm"),(void*)va8873},
{C_text("va8875:posix_2escm"),(void*)va8875},
{C_text("va8877:posix_2escm"),(void*)va8877},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
o|hiding unexported module binding: chicken.posix#d 
o|hiding unexported module binding: chicken.posix#define-alias 
o|hiding unexported module binding: chicken.posix#define-unimplemented 
o|hiding unexported module binding: chicken.posix#set!-unimplemented 
o|hiding unexported module binding: chicken.posix#posix-error 
o|hiding unexported module binding: chicken.posix#stat-mode 
o|hiding unexported module binding: chicken.posix#stat 
o|hiding unexported module binding: chicken.posix#decode-seconds 
o|hiding unexported module binding: chicken.posix#check-time-vector 
o|hiding unexported module binding: chicken.posix#list->c-string-buffer 
o|hiding unexported module binding: chicken.posix#free-c-string-buffer 
o|hiding unexported module binding: chicken.posix#check-environment-list 
o|hiding unexported module binding: chicken.posix#call-with-exec-args 
o|hiding unexported module binding: chicken.posix#chown 
o|hiding unexported module binding: chicken.posix#process-wait-impl 
o|hiding unexported module binding: chicken.posix#shell-command 
o|hiding unexported module binding: chicken.posix#shell-command-arguments 
o|hiding unexported module binding: chicken.posix#process-impl 
S|applied compiler syntax:
S|  scheme#for-each		4
S|  scheme#map		2
o|eliminated procedure checks: 130 
o|specializations:
o|  1 (scheme#make-string fixnum)
o|  1 (##sys#check-output-port * * *)
o|  1 (##sys#check-input-port * * *)
o|  1 (##sys#call-with-values (procedure () *) *)
o|  11 (scheme#cdr pair)
o|  1 (chicken.base#add1 fixnum)
o|  3 (##sys#length list)
o|  1 (scheme#zero? *)
o|  2 (##sys#check-open-port * *)
o|  5 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  12 (scheme#car pair)
o|  5 (##sys#check-list (or pair list) *)
o|  1 (scheme#char=? char char)
o|  2 (scheme#zero? integer)
(o e)|safe calls: 754 
(o e)|assignments to immediate values: 123 
o|dropping redundant toplevel assignment: chicken.file.posix#file-stat 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-permissions! 
o|dropping redundant toplevel assignment: chicken.file.posix#file-modification-time 
o|dropping redundant toplevel assignment: chicken.file.posix#file-access-time 
o|dropping redundant toplevel assignment: chicken.file.posix#file-change-time 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-times! 
o|dropping redundant toplevel assignment: chicken.file.posix#file-size 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-owner! 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-group! 
o|safe globals: (chicken.file.posix#set-file-group! chicken.file.posix#set-file-owner! chicken.file.posix#file-size chicken.file.posix#set-file-times! chicken.file.posix#file-change-time chicken.file.posix#file-access-time chicken.file.posix#file-modification-time chicken.file.posix#set-file-permissions! chicken.file.posix#file-stat chicken.posix#stat ##sys#posix-error chicken.posix#posix-error chicken.process-context.posix#user-information chicken.process-context.posix#process-group-id chicken.process-context.posix#create-session chicken.process-context.posix#current-effective-user-name chicken.process-context.posix#current-user-name chicken.process-context.posix#parent-process-id chicken.process-context.posix#current-process-id chicken.process-context.posix#current-user-id chicken.process-context.posix#current-group-id chicken.process-context.posix#current-effective-user-id chicken.process-context.posix#current-effective-group-id chicken.process-context.posix#set-root-directory! chicken.process-context.posix#change-directory* chicken.process.signal#signals-list chicken.process.signal#signal/xfsz chicken.process.signal#signal/xcpu chicken.process.signal#signal/winch chicken.process.signal#signal/vtalrm chicken.process.signal#signal/usr2 chicken.process.signal#signal/usr1 chicken.process.signal#signal/urg chicken.process.signal#signal/tstp chicken.process.signal#signal/trap chicken.process.signal#signal/term chicken.process.signal#signal/stop chicken.process.signal#signal/segv chicken.process.signal#signal/quit chicken.process.signal#signal/prof chicken.process.signal#signal/pipe chicken.process.signal#signal/kill chicken.process.signal#signal/io chicken.process.signal#signal/int chicken.process.signal#signal/ill chicken.process.signal#signal/hup chicken.process.signal#signal/fpe chicken.process.signal#signal/cont chicken.process.signal#signal/chld chicken.process.signal#signal/bus chicken.process.signal#signal/break chicken.process.signal#signal/alrm chicken.process.signal#signal/abrt chicken.process.signal#signal-unmask! chicken.process.signal#signal-masked? chicken.process.signal#signal-mask! chicken.process.signal#signal-mask chicken.process.signal#signal-default chicken.process.signal#signal-ignore chicken.process.signal#make-signal-handler chicken.process.signal#signal-handler chicken.process.signal#set-signal-mask! chicken.process.signal#set-signal-handler! chicken.process.signal#set-alarm! chicken.process#spawn/detach chicken.process#spawn/nowaito chicken.process#spawn/nowait chicken.process#spawn/wait chicken.process#spawn/overlay chicken.process#pipe/buf chicken.process#process-sleep chicken.process#process* chicken.process#process chicken.process#with-output-to-pipe chicken.process#with-input-from-pipe chicken.process#open-output-pipe chicken.process#open-input-pipe chicken.process#create-pipe chicken.process#close-output-pipe chicken.process#close-input-pipe chicken.process#call-with-output-pipe chicken.process#call-with-input-pipe chicken.process#process-wait chicken.process#process-spawn chicken.process#process-signal chicken.process#process-run chicken.process#process-fork chicken.process#process-execute chicken.process#qs chicken.process#system* chicken.process#system chicken.time.posix#local-timezone-abbreviation chicken.time.posix#time->string chicken.time.posix#string->time chicken.time.posix#local-time->seconds chicken.time.posix#seconds->string chicken.time.posix#seconds->local-time chicken.time.posix#utc-time->seconds chicken.time.posix#seconds->utc-time chicken.file.posix#set-file-position! chicken.file.posix#seek/set chicken.file.posix#seek/end chicken.file.posix#seek/cur chicken.file.posix#port->fileno chicken.file.posix#perm/ixusr chicken.file.posix#perm/ixoth chicken.file.posix#perm/ixgrp chicken.file.posix#perm/iwusr chicken.file.posix#perm/iwoth chicken.file.posix#perm/iwgrp chicken.file.posix#perm/isvtx chicken.file.posix#perm/isuid chicken.file.posix#perm/isgid chicken.file.posix#perm/irwxu chicken.file.posix#perm/irwxo chicken.file.posix#perm/irwxg chicken.file.posix#perm/irusr chicken.file.posix#perm/iroth chicken.file.posix#perm/irgrp chicken.file.posix#open/wronly chicken.file.posix#open/write chicken.file.posix#open/trunc chicken.file.posix#open/text chicken.file.posix#open/sync chicken.file.posix#open/read chicken.file.posix#open/rdwr chicken.file.posix#open/rdonly chicken.file.posix#open/nonblock chicken.file.posix#open/noinherit chicken.file.posix#open/noctty chicken.file.posix#open/fsync chicken.file.posix#open/excl chicken.file.posix#open/creat chicken.file.posix#open/binary chicken.file.posix#open/append chicken.file.posix#open-output-file* chicken.file.posix#open-input-file* chicken.file.posix#fileno/stdout chicken.file.posix#fileno/stdin chicken.file.posix#fileno/stderr chicken.file.posix#symbolic-link? chicken.file.posix#socket? chicken.file.posix#regular-file? chicken.file.posix#fifo? chicken.file.posix#directory? chicken.file.posix#character-device? chicken.file.posix#block-device? chicken.file.posix#file-type chicken.file.posix#file-write chicken.file.posix#file-unlock chicken.file.posix#file-truncate chicken.file.posix#file-test-lock chicken.file.posix#file-select chicken.file.posix#file-read chicken.file.posix#file-position chicken.file.posix#file-permissions chicken.file.posix#file-owner chicken.file.posix#file-open chicken.file.posix#file-mkstemp chicken.file.posix#file-lock/blocking chicken.file.posix#file-lock chicken.file.posix#file-link chicken.file.posix#file-group chicken.file.posix#file-creation-mode chicken.file.posix#file-control chicken.file.posix#file-close chicken.file.posix#fcntl/setfl chicken.file.posix#fcntl/setfd chicken.file.posix#fcntl/getfl chicken.file.posix#fcntl/getfd chicken.file.posix#fcntl/dupfd chicken.file.posix#duplicate-fileno chicken.file.posix#read-symbolic-link chicken.file.posix#create-symbolic-link chicken.file.posix#create-fifo c2260) 
o|inlining procedure: k2789 
o|inlining procedure: k2789 
o|inlining procedure: k2808 
o|inlining procedure: k2808 
o|inlining procedure: k2835 
o|inlining procedure: k2835 
o|substituted constant variable: a2845 
o|inlining procedure: k2876 
o|inlining procedure: k2876 
o|contracted procedure: "(posix-common.scm:193) strerror652" 
o|inlining procedure: k3032 
o|inlining procedure: k3032 
o|inlining procedure: k3047 
o|inlining procedure: k3047 
o|inlining procedure: k3066 
o|inlining procedure: k3066 
o|inlining procedure: k3099 
o|inlining procedure: k3099 
o|inlining procedure: k3111 
o|inlining procedure: k3111 
o|inlining procedure: k3189 
o|inlining procedure: k3189 
o|contracted procedure: "(posix-common.scm:293) g724725" 
o|inlining procedure: k3176 
o|inlining procedure: k3176 
o|inlining procedure: k3276 
o|inlining procedure: k3288 
o|inlining procedure: k3288 
o|inlining procedure: k3300 
o|inlining procedure: k3300 
o|inlining procedure: k3312 
o|inlining procedure: k3312 
o|inlining procedure: k3276 
o|inlining procedure: k3433 
o|inlining procedure: k3433 
o|inlining procedure: k3448 
o|inlining procedure: k3448 
o|inlining procedure: k3461 
o|inlining procedure: k3461 
o|inlining procedure: k3511 
o|inlining procedure: k3524 
o|inlining procedure: k3524 
o|substituted constant variable: a3537 
o|inlining procedure: k3511 
o|inlining procedure: k3544 
o|inlining procedure: k3544 
o|inlining procedure: k3557 
o|inlining procedure: k3557 
o|substituted constant variable: a3592 
o|inlining procedure: k3593 
o|inlining procedure: k3593 
o|inlining procedure: k3612 
o|inlining procedure: k3612 
o|inlining procedure: k3642 
o|inlining procedure: k3642 
o|inlining procedure: k3669 
o|inlining procedure: k3669 
o|inlining procedure: k3682 
o|propagated global variable: r36838103 chicken.process-context.posix#change-directory* 
o|inlining procedure: k3682 
o|inlining procedure: k3702 
o|inlining procedure: k3702 
o|inlining procedure: k3780 
o|inlining procedure: k3780 
o|contracted procedure: "(posix-common.scm:596) ctime902" 
o|inlining procedure: k3816 
o|inlining procedure: k3816 
o|inlining procedure: k3860 
o|contracted procedure: "(posix-common.scm:619) strftime927" 
o|inlining procedure: k3846 
o|inlining procedure: k3846 
o|inlining procedure: k3860 
o|contracted procedure: "(posix-common.scm:621) asctime926" 
o|inlining procedure: k3833 
o|inlining procedure: k3833 
o|inlining procedure: k3958 
o|inlining procedure: k3958 
o|inlining procedure: k3976 
o|inlining procedure: k3976 
o|inlining procedure: k4053 
o|inlining procedure: k4053 
o|inlining procedure: k4139 
o|inlining procedure: k4139 
o|contracted procedure: "(posix-common.scm:716) c-string->allocated-pointer1036" 
o|merged explicitly consed rest parameter: args10481069 
o|consed rest parameter at call site: tmp22591 1 
o|inlining procedure: k4220 
o|inlining procedure: k4220 
o|inlining procedure: k4269 
o|inlining procedure: k4269 
o|inlining procedure: k4324 
o|inlining procedure: k4324 
o|inlining procedure: k4383 
o|contracted procedure: "(posix-common.scm:757) g11341143" 
o|inlining procedure: k4383 
o|inlining procedure: k4430 
o|inlining procedure: k4430 
o|inlining procedure: k4448 
o|inlining procedure: k4448 
o|inlining procedure: k4461 
o|inlining procedure: k4461 
o|inlining procedure: k4477 
o|inlining procedure: k4477 
o|inlining procedure: "(posix-common.scm:786) badmode1157" 
o|substituted constant variable: a4501 
o|substituted constant variable: a4503 
o|inlining procedure: k4517 
o|inlining procedure: k4517 
o|inlining procedure: "(posix-common.scm:797) badmode1157" 
o|substituted constant variable: a4541 
o|substituted constant variable: a4543 
o|substituted constant variable: a4548 
o|substituted constant variable: a4549 
o|inlining procedure: k4550 
o|inlining procedure: k4550 
o|substituted constant variable: a4563 
o|substituted constant variable: a4564 
o|inlining procedure: k4565 
o|inlining procedure: k4565 
o|inlining procedure: k4752 
o|inlining procedure: k4752 
o|contracted procedure: "(posixunix.scm:332) fcntl1339" 
o|inlining procedure: k4789 
o|inlining procedure: k4789 
o|inlining procedure: k4814 
o|inlining procedure: k4814 
o|inlining procedure: k4848 
o|inlining procedure: k4848 
o|inlining procedure: k4888 
o|inlining procedure: k4888 
o|inlining procedure: k4988 
o|inlining procedure: k4988 
o|inlining procedure: k5011 
o|inlining procedure: k5011 
o|inlining procedure: k5034 
o|inlining procedure: k5043 
o|inlining procedure: k5043 
o|inlining procedure: k5034 
o|inlining procedure: k5049 
o|inlining procedure: k5049 
o|inlining procedure: k5064 
o|inlining procedure: k5064 
o|contracted procedure: "(posixunix.scm:439) g15111512" 
o|inlining procedure: k5083 
o|inlining procedure: k5083 
o|inlining procedure: k5123 
o|inlining procedure: k5123 
o|contracted procedure: "(posixunix.scm:431) g14921493" 
o|inlining procedure: k5142 
o|inlining procedure: k5142 
o|contracted procedure: "(posixunix.scm:424) g14661467" 
o|inlining procedure: k5201 
o|inlining procedure: k5201 
o|contracted procedure: "(posixunix.scm:418) g14511452" 
o|inlining procedure: k5218 
o|inlining procedure: k5218 
o|inlining procedure: k5243 
o|inlining procedure: k5243 
o|contracted procedure: "(posixunix.scm:412) g14341435" 
o|inlining procedure: k5260 
o|inlining procedure: k5260 
o|inlining procedure: k5290 
o|inlining procedure: k5290 
o|inlining procedure: k5305 
o|inlining procedure: k5305 
o|inlining procedure: k5327 
o|inlining procedure: k5327 
o|inlining procedure: k5391 
o|inlining procedure: k5391 
o|inlining procedure: k5404 
o|contracted procedure: "(posixunix.scm:554) g15431550" 
o|inlining procedure: k5404 
o|inlining procedure: k5440 
o|inlining procedure: k5440 
o|inlining procedure: k5456 
o|inlining procedure: k5456 
o|inlining procedure: k5491 
o|inlining procedure: k5491 
o|inlining procedure: k5576 
o|inlining procedure: k5576 
o|inlining procedure: k5592 
o|inlining procedure: k5592 
o|inlining procedure: k5614 
o|inlining procedure: k5614 
o|inlining procedure: k5640 
o|inlining procedure: k5640 
o|inlining procedure: k5668 
o|inlining procedure: k5668 
o|inlining procedure: k5689 
o|inlining procedure: k5714 
o|inlining procedure: k5714 
o|inlining procedure: k5735 
o|inlining procedure: k5735 
o|inlining procedure: k5765 
o|inlining procedure: k5765 
o|inlining procedure: k5689 
o|inlining procedure: k5804 
o|inlining procedure: k5804 
o|contracted procedure: "(posixunix.scm:773) link1670" 
o|inlining procedure: k5858 
o|inlining procedure: k5858 
o|inlining procedure: k5884 
o|inlining procedure: k5884 
o|inlining procedure: k5898 
o|inlining procedure: k5922 
o|inlining procedure: k5922 
o|inlining procedure: k5898 
o|inlining procedure: k5943 
o|inlining procedure: k5943 
o|inlining procedure: k5963 
o|inlining procedure: k5963 
o|inlining procedure: k6000 
o|inlining procedure: k6000 
o|inlining procedure: k6022 
o|inlining procedure: k6022 
o|inlining procedure: k6031 
o|inlining procedure: k6031 
o|inlining procedure: k6047 
o|inlining procedure: k6047 
o|inlining procedure: k6072 
o|inlining procedure: k6072 
o|inlining procedure: k6119 
o|inlining procedure: k6119 
o|inlining procedure: k6141 
o|inlining procedure: k6141 
o|inlining procedure: k6169 
o|inlining procedure: k6169 
o|inlining procedure: k6212 
o|inlining procedure: k6212 
o|inlining procedure: k6257 
o|inlining procedure: k6257 
o|inlining procedure: k6362 
o|inlining procedure: k6383 
o|inlining procedure: k6383 
o|inlining procedure: k6362 
o|inlining procedure: k6439 
o|inlining procedure: k6439 
o|inlining procedure: k6463 
o|inlining procedure: k6463 
o|inlining procedure: k6478 
o|inlining procedure: k6495 
o|inlining procedure: k6495 
o|inlining procedure: k6478 
o|inlining procedure: k6591 
o|inlining procedure: k6591 
o|inlining procedure: k6601 
o|inlining procedure: k6601 
o|inlining procedure: k6621 
o|inlining procedure: k6621 
o|inlining procedure: k6728 
o|inlining procedure: k6728 
o|inlining procedure: k6759 
o|inlining procedure: k6759 
o|inlining procedure: k6784 
o|contracted procedure: "(posixunix.scm:1014) g19271928" 
o|inlining procedure: k6789 
o|inlining procedure: k6789 
o|inlining procedure: k6784 
o|inlining procedure: k6819 
o|inlining procedure: k6819 
o|inlining procedure: k6860 
o|inlining procedure: k6860 
o|contracted procedure: "(posixunix.scm:1048) strptime1947" 
o|inlining procedure: k6889 
o|inlining procedure: k6889 
o|inlining procedure: k6941 
o|inlining procedure: k6941 
o|inlining procedure: k6999 
o|inlining procedure: k6999 
o|contracted procedure: "(posixunix.scm:1084) fork1987" 
o|contracted procedure: "(posixunix.scm:1081) g20052006" 
o|inlining procedure: k6984 
o|inlining procedure: k6984 
o|inlining procedure: k7098 
o|inlining procedure: k7098 
o|inlining procedure: k7150 
o|inlining procedure: k7150 
o|inlining procedure: k7169 
o|inlining procedure: k7169 
o|inlining procedure: k7196 
o|inlining procedure: k7196 
o|removed unused formal parameters: (loc2063) 
o|inlining procedure: k7215 
o|inlining procedure: k7215 
o|inlining procedure: k7233 
o|inlining procedure: k7233 
o|inlining procedure: "(posixunix.scm:1151) chicken.posix#shell-command-arguments" 
o|removed unused parameter to known procedure: loc2063 "(posixunix.scm:1150) chicken.posix#shell-command" 
o|inlining procedure: k7286 
o|inlining procedure: k7304 
o|inlining procedure: k7304 
o|inlining procedure: k7286 
o|removed unused formal parameters: (loc2098) 
o|inlining procedure: k7318 
o|inlining procedure: k7318 
o|removed unused formal parameters: (loc2103 fd2106) 
o|inlining procedure: k7338 
o|inlining procedure: k7338 
o|inlining procedure: k7350 
o|contracted procedure: "(posixunix.scm:1203) replace-fd2078" 
o|inlining procedure: k7267 
o|inlining procedure: k7267 
o|inlining procedure: k7350 
o|inlining procedure: k7365 
o|inlining procedure: k7365 
o|removed unused parameter to known procedure: loc2098 "(posixunix.scm:1213) needed-pipe2084" 
o|removed unused parameter to known procedure: loc2098 "(posixunix.scm:1212) needed-pipe2084" 
o|removed unused parameter to known procedure: loc2098 "(posixunix.scm:1211) needed-pipe2084" 
o|removed unused formal parameters: (pid2138) 
o|inlining procedure: k7427 
o|inlining procedure: k7427 
o|removed unused parameter to known procedure: loc2103 "(posixunix.scm:1224) connect-parent2085" 
o|removed unused parameter to known procedure: fd2106 "(posixunix.scm:1224) connect-parent2085" 
o|removed unused formal parameters: (pid2147) 
o|inlining procedure: k7438 
o|inlining procedure: k7438 
o|removed unused parameter to known procedure: loc2103 "(posixunix.scm:1228) connect-parent2085" 
o|removed unused parameter to known procedure: fd2106 "(posixunix.scm:1228) connect-parent2085" 
o|removed unused parameter to known procedure: pid2138 "(posixunix.scm:1245) input-port2119" 
o|removed unused parameter to known procedure: pid2147 "(posixunix.scm:1241) output-port2120" 
o|removed unused parameter to known procedure: pid2138 "(posixunix.scm:1238) input-port2119" 
o|inlining procedure: k7518 
o|inlining procedure: k7518 
o|removed unused parameter to known procedure: loc2063 "(posixunix.scm:1263) chicken.posix#shell-command" 
o|inlining procedure: "(posixunix.scm:1262) chicken.posix#shell-command-arguments" 
o|inlining procedure: k7712 
o|inlining procedure: k7712 
o|contracted procedure: "(posixunix.scm:1286) chroot2247" 
o|substituted constant variable: c2260 
o|inlining procedure: k7786 
o|inlining procedure: k7786 
o|inlining procedure: k7808 
o|inlining procedure: k7808 
o|inlining procedure: k7831 
o|inlining procedure: k7831 
o|inlining procedure: k7854 
o|inlining procedure: k7854 
o|inlining procedure: k7877 
o|inlining procedure: k7877 
o|inlining procedure: k7900 
o|inlining procedure: k7900 
o|inlining procedure: k7923 
o|inlining procedure: k7923 
o|inlining procedure: k7938 
o|inlining procedure: k7938 
o|inlining procedure: k7966 
o|inlining procedure: k7966 
o|inlining procedure: k7990 
o|inlining procedure: k7990 
o|inlining procedure: k8002 
o|inlining procedure: k8002 
o|inlining procedure: k8012 
o|inlining procedure: k8012 
o|replaced variables: 1232 
o|removed binding forms: 689 
o|removed side-effect free assignment to unused variable: c2260 
o|substituted constant variable: r30338048 
o|substituted constant variable: r31778061 
o|substituted constant variable: r31778061 
o|substituted constant variable: r32898064 
o|substituted constant variable: r33018066 
o|substituted constant variable: r33138068 
o|substituted constant variable: r32778070 
o|substituted constant variable: r34498074 
o|inlining procedure: k3511 
o|substituted constant variable: r35258079 
o|inlining procedure: k3511 
o|inlining procedure: k3511 
o|substituted constant variable: r35588085 
o|substituted constant variable: r35588085 
o|substituted constant variable: r35588087 
o|substituted constant variable: r35588087 
o|propagated global variable: g8558568104 chicken.process-context.posix#change-directory* 
o|substituted constant variable: r38478123 
o|substituted constant variable: r38478123 
o|substituted constant variable: r38348130 
o|substituted constant variable: r38348130 
o|substituted constant variable: r44318158 
o|removed side-effect free assignment to unused variable: badmode1157 
o|substituted constant variable: r44628161 
o|substituted constant variable: r44628161 
o|substituted constant variable: r44628163 
o|substituted constant variable: r44628163 
o|inlining procedure: k4477 
o|inlining procedure: k4517 
o|substituted constant variable: r50128215 
o|substituted constant variable: r50128215 
o|substituted constant variable: r50128217 
o|substituted constant variable: r50128217 
o|inlining procedure: k5034 
o|inlining procedure: k5034 
o|substituted constant variable: r50448222 
o|inlining procedure: k5034 
o|substituted constant variable: r50358223 
o|substituted constant variable: r50358223 
o|substituted constant variable: r50848231 
o|substituted constant variable: r50848231 
o|substituted constant variable: r51438237 
o|substituted constant variable: r51438237 
o|substituted constant variable: r52198243 
o|substituted constant variable: r52198243 
o|substituted constant variable: r52618249 
o|substituted constant variable: r52618249 
o|substituted constant variable: r54928274 
o|inlining procedure: k5735 
o|substituted constant variable: r57668296 
o|substituted constant variable: r57668296 
o|substituted constant variable: r58858303 
o|inlining procedure: k5955 
o|inlining procedure: k5955 
o|substituted constant variable: r61428343 
o|substituted constant variable: r62588355 
o|inlining procedure: k6601 
o|inlining procedure: k6601 
o|substituted constant variable: r67908391 
o|substituted constant variable: r68908399 
o|substituted constant variable: r68908399 
o|substituted constant variable: c-pointer20072011 
o|substituted constant variable: c-pointer20072011 
o|substituted constant variable: r69858407 
o|substituted constant variable: r69858407 
o|inlining procedure: k7169 
o|substituted constant variable: r72168420 
o|removed side-effect free assignment to unused variable: chicken.posix#shell-command-arguments 
o|substituted constant variable: r73198433 
o|substituted constant variable: r73398435 
o|substituted constant variable: r73668441 
o|removed unused formal parameters: (stdfd2142) 
o|substituted constant variable: r74288443 
o|removed unused formal parameters: (stdfd2151) 
o|substituted constant variable: r74398445 
o|removed unused parameter to known procedure: stdfd2142 "(posixunix.scm:1245) input-port2119" 
o|removed unused parameter to known procedure: stdfd2151 "(posixunix.scm:1241) output-port2120" 
o|removed unused parameter to known procedure: stdfd2142 "(posixunix.scm:1238) input-port2119" 
o|substituted constant variable: r80038484 
o|replaced variables: 151 
o|removed binding forms: 1007 
o|removed conditional forms: 1 
o|inlining procedure: k3920 
o|inlining procedure: k3920 
o|inlining procedure: k3955 
o|inlining procedure: k4229 
o|inlining procedure: k4860 
o|inlining procedure: k4860 
o|inlining procedure: k4904 
o|inlining procedure: k4904 
o|substituted constant variable: r50358523 
o|inlining procedure: k5410 
o|inlining procedure: k5814 
o|contracted procedure: k7169 
o|removed unused formal parameters: (loc2111) 
o|removed unused parameter to known procedure: loc2111 "(posixunix.scm:1220) connect-child2086" 
o|removed unused parameter to known procedure: loc2111 "(posixunix.scm:1219) connect-child2086" 
o|removed unused parameter to known procedure: loc2111 "(posixunix.scm:1218) connect-child2086" 
o|inlining procedure: k7654 
o|inlining procedure: k7722 
o|replaced variables: 6 
o|removed binding forms: 213 
o|substituted constant variable: r35128489 
o|substituted constant variable: r35128491 
o|substituted constant variable: r35128493 
o|substituted constant variable: r39218595 
o|substituted constant variable: r39568597 
o|contracted procedure: k4154 
o|contracted procedure: k4749 
o|substituted constant variable: r48618615 
o|substituted constant variable: r49058617 
o|contracted procedure: k4985 
o|contracted procedure: k6990 
o|contracted procedure: k6993 
o|removed unused formal parameters: (loc2124) 
o|removed unused parameter to known procedure: loc2124 "(posixunix.scm:1232) spawn2118" 
o|inlining procedure: k7963 
o|inlining procedure: k7963 
o|simplifications: ((let . 2)) 
o|replaced variables: 1 
o|removed binding forms: 20 
o|removed conditional forms: 3 
o|substituted constant variable: r79648698 
o|replaced variables: 1 
o|removed binding forms: 9 
o|removed binding forms: 2 
o|simplifications: ((let . 50) (if . 95) (##core#call . 555)) 
o|  call simplifications:
o|    scheme#<
o|    chicken.bitwise#bitwise-ior
o|    scheme#vector-ref	2
o|    scheme#make-vector
o|    chicken.fixnum#fxior	2
o|    ##sys#check-structure
o|    ##sys#make-structure
o|    chicken.fixnum#fxmin	2
o|    scheme#eof-object?
o|    chicken.fixnum#fx>=	7
o|    chicken.fixnum#fx*
o|    scheme#*
o|    scheme#memq	2
o|    scheme#list	7
o|    scheme#call-with-values	4
o|    ##sys#check-pair
o|    ##sys#check-list	7
o|    ##sys#apply	2
o|    chicken.fixnum#fx+	21
o|    ##sys#call-with-values	8
o|    scheme#values	19
o|    scheme#vector-set!	6
o|    ##sys#foreign-block-argument	8
o|    scheme#=	3
o|    ##sys#foreign-ranged-integer-argument	2
o|    chicken.fixnum#fx-	12
o|    ##sys#check-vector
o|    ##sys#size	11
o|    ##sys#null-pointer?	2
o|    scheme#not	9
o|    ##sys#setislot	4
o|    chicken.fixnum#fx=	42
o|    scheme#cdr	29
o|    ##sys#foreign-string-argument	4
o|    scheme#vector	2
o|    chicken.base#fixnum?	16
o|    scheme#string?	4
o|    ##sys#foreign-fixnum-argument	14
o|    scheme#null?	73
o|    scheme#car	52
o|    scheme#string->list
o|    scheme#pair?	18
o|    scheme#cons	10
o|    ##sys#setslot	4
o|    ##sys#slot	29
o|    scheme#apply	11
o|    scheme#char=?
o|    scheme#string	3
o|    scheme#eq?	29
o|    ##sys#check-string	21
o|    chicken.fixnum#fx<	42
o|contracted procedure: k2786 
o|contracted procedure: k2792 
o|contracted procedure: k2811 
o|contracted procedure: k2910 
o|contracted procedure: k2824 
o|contracted procedure: k2907 
o|contracted procedure: k2827 
o|contracted procedure: k2830 
o|contracted procedure: k2838 
o|contracted procedure: k2862 
o|contracted procedure: k2870 
o|contracted procedure: k2879 
o|contracted procedure: k2882 
o|contracted procedure: k2885 
o|contracted procedure: k2893 
o|contracted procedure: k2901 
o|contracted procedure: k2913 
o|contracted procedure: k3006 
o|contracted procedure: k3035 
o|contracted procedure: k3044 
o|contracted procedure: k3060 
o|contracted procedure: k3084 
o|contracted procedure: k3075 
o|contracted procedure: k3102 
o|contracted procedure: k3108 
o|contracted procedure: k3124 
o|contracted procedure: k3216 
o|contracted procedure: k3158 
o|contracted procedure: k3210 
o|contracted procedure: k3161 
o|contracted procedure: k3204 
o|contracted procedure: k3164 
o|contracted procedure: k3192 
o|contracted procedure: k3183 
o|contracted procedure: k3222 
o|contracted procedure: k3342 
o|contracted procedure: k3264 
o|contracted procedure: k3336 
o|contracted procedure: k3267 
o|contracted procedure: k3330 
o|contracted procedure: k3270 
o|contracted procedure: k3324 
o|contracted procedure: k3273 
o|contracted procedure: k3285 
o|contracted procedure: k3291 
o|contracted procedure: k3297 
o|contracted procedure: k3303 
o|contracted procedure: k3309 
o|contracted procedure: k3315 
o|contracted procedure: k3321 
o|contracted procedure: k3470 
o|contracted procedure: k3424 
o|contracted procedure: k3458 
o|contracted procedure: k3445 
o|contracted procedure: k3454 
o|contracted procedure: k3464 
o|contracted procedure: k3514 
o|contracted procedure: k3521 
o|contracted procedure: k3527 
o|contracted procedure: k3547 
o|contracted procedure: k3630 
o|contracted procedure: k3596 
o|contracted procedure: k3609 
o|contracted procedure: k3615 
o|contracted procedure: k3645 
o|contracted procedure: k3651 
o|contracted procedure: k3654 
o|contracted procedure: k3672 
o|contracted procedure: k3688 
o|contracted procedure: k3699 
o|contracted procedure: k3712 
o|contracted procedure: k3705 
o|contracted procedure: k3727 
o|inlining procedure: k3718 
o|contracted procedure: k3748 
o|inlining procedure: k3739 
o|contracted procedure: k3791 
o|contracted procedure: k3787 
o|contracted procedure: k3765 
o|contracted procedure: k3797 
o|contracted procedure: k3819 
o|contracted procedure: k3907 
o|contracted procedure: k3854 
o|contracted procedure: k3863 
o|contracted procedure: k3846 
o|contracted procedure: k3897 
o|contracted procedure: k3893 
o|contracted procedure: k3833 
o|contracted procedure: k3967 
o|contracted procedure: k3955 
o|contracted procedure: k3979 
o|contracted procedure: k3989 
o|contracted procedure: k3993 
o|contracted procedure: k4083 
o|contracted procedure: k4023 
o|contracted procedure: k4077 
o|contracted procedure: k4026 
o|contracted procedure: k4071 
o|contracted procedure: k4029 
o|contracted procedure: k4065 
o|contracted procedure: k4032 
o|contracted procedure: k4035 
o|contracted procedure: k4056 
o|contracted procedure: k4094 
o|contracted procedure: k4142 
o|contracted procedure: k4145 
o|contracted procedure: k4182 
o|contracted procedure: k4148 
o|contracted procedure: k4169 
o|contracted procedure: k4223 
o|contracted procedure: k4236 
o|contracted procedure: k42368605 
o|contracted procedure: k4245 
o|contracted procedure: k4250 
o|contracted procedure: k4253 
o|contracted procedure: k4272 
o|contracted procedure: k4282 
o|contracted procedure: k4286 
o|contracted procedure: k4294 
o|contracted procedure: k4360 
o|contracted procedure: k4374 
o|contracted procedure: k4386 
o|contracted procedure: k4389 
o|contracted procedure: k4392 
o|contracted procedure: k4400 
o|contracted procedure: k4408 
o|contracted procedure: k4369 
o|contracted procedure: k4433 
o|contracted procedure: k4451 
o|contracted procedure: k4467 
o|contracted procedure: k4480 
o|contracted procedure: k4490 
o|contracted procedure: k4507 
o|contracted procedure: k4520 
o|contracted procedure: k4530 
o|contracted procedure: k4553 
o|contracted procedure: k4568 
o|contracted procedure: k4694 
o|contracted procedure: k4701 
o|contracted procedure: k4761 
o|contracted procedure: k4740 
o|contracted procedure: k4726 
o|contracted procedure: k4730 
o|contracted procedure: k4734 
o|contracted procedure: k4755 
o|contracted procedure: k4798 
o|contracted procedure: k4773 
o|contracted procedure: k4776 
o|contracted procedure: k4792 
o|contracted procedure: k4817 
o|contracted procedure: k4823 
o|contracted procedure: k4854 
o|contracted procedure: k4866 
o|contracted procedure: k4897 
o|contracted procedure: k4882 
o|contracted procedure: k4891 
o|contracted procedure: k4913 
o|contracted procedure: k4919 
o|contracted procedure: k4933 
o|contracted procedure: k4936 
o|contracted procedure: k5317 
o|contracted procedure: k4945 
o|contracted procedure: k4956 
o|contracted procedure: k4971 
o|contracted procedure: k4975 
o|contracted procedure: k4979 
o|contracted procedure: k4991 
o|contracted procedure: k5000 
o|contracted procedure: k5017 
o|contracted procedure: k5007 
o|contracted procedure: k5014 
o|contracted procedure: k5040 
o|contracted procedure: k5046 
o|contracted procedure: k5052 
o|contracted procedure: k5058 
o|contracted procedure: k5067 
o|contracted procedure: k5096 
o|contracted procedure: k5106 
o|contracted procedure: k5100 
o|contracted procedure: k5113 
o|contracted procedure: k5117 
o|contracted procedure: k5079 
o|contracted procedure: k5083 
o|contracted procedure: k5126 
o|contracted procedure: k5155 
o|contracted procedure: k5165 
o|contracted procedure: k5159 
o|contracted procedure: k5172 
o|contracted procedure: k5176 
o|contracted procedure: k5138 
o|contracted procedure: k5142 
o|contracted procedure: k5191 
o|contracted procedure: k5204 
o|contracted procedure: k5231 
o|contracted procedure: k5237 
o|contracted procedure: k5210 
o|contracted procedure: k5214 
o|contracted procedure: k5218 
o|contracted procedure: k5246 
o|contracted procedure: k5273 
o|contracted procedure: k5279 
o|contracted procedure: k5252 
o|contracted procedure: k5256 
o|contracted procedure: k5260 
o|contracted procedure: k5283 
o|contracted procedure: k5287 
o|contracted procedure: k5293 
o|contracted procedure: k5299 
o|contracted procedure: k5302 
o|contracted procedure: k5308 
o|contracted procedure: k5314 
o|contracted procedure: k5340 
o|contracted procedure: k5324 
o|contracted procedure: k5333 
o|contracted procedure: k5374 
o|contracted procedure: k5380 
o|contracted procedure: k5394 
o|contracted procedure: k5407 
o|contracted procedure: k5421 
o|contracted procedure: k54178629 
o|contracted procedure: k5443 
o|contracted procedure: k5459 
o|contracted procedure: k5530 
o|contracted procedure: k5485 
o|contracted procedure: k5494 
o|contracted procedure: k5520 
o|contracted procedure: k5523 
o|contracted procedure: k5579 
o|contracted procedure: k5595 
o|contracted procedure: k5601 
o|contracted procedure: k5617 
o|contracted procedure: k5634 
o|contracted procedure: k5637 
o|contracted procedure: k5643 
o|contracted procedure: k5671 
o|contracted procedure: k5771 
o|contracted procedure: k5683 
o|contracted procedure: k5686 
o|contracted procedure: k5717 
o|contracted procedure: k5757 
o|contracted procedure: k5761 
o|contracted procedure: k5798 
o|contracted procedure: k5801 
o|contracted procedure: k5807 
o|contracted procedure: k5789 
o|contracted procedure: k5793 
o|contracted procedure: k6324 
o|contracted procedure: k5820 
o|contracted procedure: k6318 
o|contracted procedure: k5823 
o|contracted procedure: k6312 
o|contracted procedure: k5826 
o|contracted procedure: k6306 
o|contracted procedure: k5829 
o|contracted procedure: k6300 
o|contracted procedure: k5832 
o|contracted procedure: k6294 
o|contracted procedure: k5835 
o|contracted procedure: k6288 
o|contracted procedure: k5838 
o|contracted procedure: k6282 
o|contracted procedure: k5841 
o|contracted procedure: k6273 
o|contracted procedure: k5847 
o|contracted procedure: k5861 
o|contracted procedure: k5867 
o|contracted procedure: k5870 
o|contracted procedure: k5887 
o|contracted procedure: k5901 
o|contracted procedure: k5907 
o|contracted procedure: k5910 
o|contracted procedure: k5925 
o|contracted procedure: k5940 
o|contracted procedure: k5960 
o|contracted procedure: k5966 
o|contracted procedure: k5969 
o|contracted procedure: k5988 
o|contracted procedure: k6003 
o|contracted procedure: k6007 
o|contracted procedure: k6010 
o|contracted procedure: k6019 
o|contracted procedure: k6037 
o|contracted procedure: k6053 
o|contracted procedure: k6075 
o|contracted procedure: k6081 
o|contracted procedure: k6084 
o|contracted procedure: k6113 
o|contracted procedure: k6087 
o|contracted procedure: k6091 
o|contracted procedure: k6095 
o|contracted procedure: k6102 
o|contracted procedure: k6106 
o|contracted procedure: k6110 
o|contracted procedure: k6122 
o|contracted procedure: k6132 
o|contracted procedure: k6144 
o|contracted procedure: k6147 
o|contracted procedure: k6206 
o|contracted procedure: k6160 
o|contracted procedure: k6166 
o|contracted procedure: k6172 
o|contracted procedure: k6179 
o|contracted procedure: k6188 
o|contracted procedure: k6199 
o|contracted procedure: k6195 
o|contracted procedure: k6227 
o|contracted procedure: k6223 
o|contracted procedure: k6216 
o|inlining procedure: k6212 
o|contracted procedure: k6238 
o|contracted procedure: k6242 
o|contracted procedure: k6234 
o|inlining procedure: k6212 
o|contracted procedure: k6248 
o|contracted procedure: k6260 
o|contracted procedure: k6267 
o|contracted procedure: k6579 
o|contracted procedure: k6333 
o|contracted procedure: k6573 
o|contracted procedure: k6336 
o|contracted procedure: k6567 
o|contracted procedure: k6339 
o|contracted procedure: k6561 
o|contracted procedure: k6342 
o|contracted procedure: k6555 
o|contracted procedure: k6345 
o|contracted procedure: k6549 
o|contracted procedure: k6348 
o|contracted procedure: k6365 
o|contracted procedure: k6371 
o|contracted procedure: k6374 
o|contracted procedure: k6386 
o|contracted procedure: k6401 
o|contracted procedure: k6412 
o|contracted procedure: k6540 
o|contracted procedure: k6415 
o|contracted procedure: k6427 
o|contracted procedure: k6445 
o|contracted procedure: k6458 
o|contracted procedure: k6470 
o|contracted procedure: k6485 
o|contracted procedure: k6489 
o|contracted procedure: k6498 
o|contracted procedure: k6511 
o|contracted procedure: k6518 
o|contracted procedure: k6522 
o|contracted procedure: k6528 
o|contracted procedure: k6534 
o|contracted procedure: k6604 
o|contracted procedure: k6624 
o|contracted procedure: k6692 
o|contracted procedure: k6633 
o|contracted procedure: k6686 
o|contracted procedure: k6636 
o|contracted procedure: k6680 
o|contracted procedure: k6639 
o|contracted procedure: k6674 
o|contracted procedure: k6642 
o|contracted procedure: k6664 
o|contracted procedure: k6660 
o|contracted procedure: k6654 
o|contracted procedure: k6667 
o|contracted procedure: k6705 
o|contracted procedure: k6709 
o|contracted procedure: k6713 
o|contracted procedure: k6731 
o|contracted procedure: k6737 
o|contracted procedure: k6762 
o|contracted procedure: k6768 
o|contracted procedure: k6796 
o|contracted procedure: k6792 
o|contracted procedure: k6808 
o|contracted procedure: k6812 
o|contracted procedure: k6816 
o|contracted procedure: k6845 
o|contracted procedure: k6822 
o|contracted procedure: k6828 
o|contracted procedure: k6851 
o|contracted procedure: k6863 
o|contracted procedure: k6874 
o|contracted procedure: k6882 
o|contracted procedure: k6925 
o|contracted procedure: k6897 
o|contracted procedure: k6900 
o|contracted procedure: k6903 
o|contracted procedure: k6918 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|substituted constant variable: g8865 
o|contracted procedure: k6889 
o|contracted procedure: k6944 
o|contracted procedure: k6961 
o|contracted procedure: k7059 
o|contracted procedure: k6969 
o|contracted procedure: k7053 
o|contracted procedure: k6972 
o|contracted procedure: k7047 
o|contracted procedure: k6975 
o|contracted procedure: k7041 
o|contracted procedure: k6978 
o|contracted procedure: k7002 
o|contracted procedure: k7005 
o|contracted procedure: k7035 
o|contracted procedure: k7137 
o|contracted procedure: k7068 
o|contracted procedure: k7131 
o|contracted procedure: k7071 
o|contracted procedure: k7125 
o|contracted procedure: k7074 
o|contracted procedure: k7119 
o|contracted procedure: k7077 
o|contracted procedure: k7113 
o|contracted procedure: k7080 
o|contracted procedure: k7107 
o|contracted procedure: k7083 
o|contracted procedure: k7095 
o|contracted procedure: k7101 
o|contracted procedure: k7147 
o|contracted procedure: k7175 
o|contracted procedure: k7153 
o|contracted procedure: k7205 
o|contracted procedure: k7187 
o|contracted procedure: k7199 
o|contracted procedure: k7260 
o|contracted procedure: k7227 
o|contracted procedure: k7257 
o|contracted procedure: k7236 
o|contracted procedure: k7253 
o|inlining procedure: "(posixunix.scm:1150) chicken.posix#shell-command" 
o|contracted procedure: k7283 
o|contracted procedure: k7310 
o|contracted procedure: k7289 
o|contracted procedure: k7341 
o|contracted procedure: k7353 
o|contracted procedure: k7270 
o|contracted procedure: k7372 
o|contracted procedure: k7489 
o|contracted procedure: k7493 
o|contracted procedure: k7497 
o|contracted procedure: k7458 
o|contracted procedure: k7504 
o|contracted procedure: k7521 
o|contracted procedure: k7531 
o|contracted procedure: k7535 
o|contracted procedure: k7538 
o|contracted procedure: k7563 
o|inlining procedure: "(posixunix.scm:1263) chicken.posix#shell-command" 
o|contracted procedure: k7630 
o|contracted procedure: k7573 
o|contracted procedure: k7624 
o|contracted procedure: k7576 
o|contracted procedure: k7618 
o|contracted procedure: k7579 
o|contracted procedure: k7612 
o|contracted procedure: k7582 
o|contracted procedure: k7606 
o|contracted procedure: k7585 
o|contracted procedure: k7600 
o|contracted procedure: k7588 
o|contracted procedure: k7690 
o|contracted procedure: k7639 
o|contracted procedure: k7684 
o|contracted procedure: k7642 
o|contracted procedure: k7678 
o|contracted procedure: k7645 
o|contracted procedure: k7672 
o|contracted procedure: k7648 
o|contracted procedure: k7666 
o|contracted procedure: k7651 
o|contracted procedure: k7660 
o|contracted procedure: k7654 
o|contracted procedure: k7709 
o|contracted procedure: k7715 
o|contracted procedure: k7704 
o|contracted procedure: k7777 
o|contracted procedure: k7789 
o|contracted procedure: k7811 
o|contracted procedure: k7834 
o|contracted procedure: k7857 
o|contracted procedure: k7880 
o|contracted procedure: k7903 
o|contracted procedure: k7926 
o|contracted procedure: k7929 
o|contracted procedure: k7938 
o|contracted procedure: k7972 
o|contracted procedure: k7956 
o|contracted procedure: k7993 
o|contracted procedure: k8009 
o|contracted procedure: k8005 
o|contracted procedure: k8015 
o|simplifications: ((##core#call . 5) (if . 7) (let . 148)) 
o|  call simplifications:
o|    chicken.bitwise#bitwise-ior	5
o|removed binding forms: 481 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest241243 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest241243 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest688690 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest688690 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest754756 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest754756 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest754756 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest754756 0 
(o x)|known list op on rest arg sublist: ##core#rest-car whence783 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest883884 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest883884 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest894895 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest894895 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest912913 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest912913 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest953955 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest953955 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest10001001 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest10001001 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? args1016 0 
(o x)|known list op on rest arg sublist: ##core#rest-car args1016 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? args1016 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr args1016 0 
o|inlining procedure: "(posix-common.scm:779) mode1156" 
o|inlining procedure: "(posix-common.scm:790) mode1156" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest13521355 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest13521355 0 
o|contracted procedure: k4768 
(o x)|known list op on rest arg sublist: ##core#rest-car mode1367 0 
(o x)|known list op on rest arg sublist: ##core#rest-car timeout1410 0 
o|contracted procedure: k5089 
o|contracted procedure: k5148 
o|contracted procedure: k5224 
o|contracted procedure: k5266 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest15311532 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest15311532 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest15991601 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest15991601 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16461648 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16461648 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16851689 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16851689 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16851689 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest16851689 0 
o|contracted procedure: k6066 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest18031807 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest18031807 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest18031807 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest18031807 0 
o|inlining procedure: "(posixunix.scm:1000) err1879" 
o|inlining procedure: "(posixunix.scm:1009) err1879" 
o|inlining procedure: "(posixunix.scm:1015) err1879" 
o|contracted procedure: k6854 
(o x)|known list op on rest arg sublist: ##core#rest-car mode1943 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest19651967 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest19651967 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest19931994 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest19931994 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest19931994 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest19931994 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest20242026 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest20242026 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest20242026 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest20242026 0 
(o x)|known list op on rest arg sublist: ##core#rest-car sig2057 0 
o|removed side-effect free assignment to unused variable: chicken.posix#shell-command 
(o x)|known list op on rest arg sublist: ##core#rest-car args2070 0 
o|inlining procedure: "(posixunix.scm:1220) swapped-ends2121" 
o|inlining procedure: "(posixunix.scm:1219) swapped-ends2121" 
o|inlining procedure: "(posixunix.scm:1215) swapped-ends2121" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest22092211 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest22092211 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest22092211 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest22092211 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest22312233 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest22312233 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest22312233 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest22312233 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest860861 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest860861 0 
o|replaced variables: 2 
o|removed binding forms: 9 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3268 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r3268 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3268 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r3268 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4027 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4027 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4027 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4027 1 
o|removed side-effect free assignment to unused variable: mode1156 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5824 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r5824 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5824 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5824 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6337 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r6337 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6337 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r6337 1 
o|removed side-effect free assignment to unused variable: err1879 
o|substituted constant variable: loc18998983 
o|substituted constant variable: msg18978981 
o|substituted constant variable: loc18998989 
o|substituted constant variable: msg18978987 
o|substituted constant variable: loc18998995 
o|substituted constant variable: msg18978993 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6973 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r6973 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6973 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r6973 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7072 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r7072 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7072 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7072 1 
o|inlining procedure: k7249 
o|inlining procedure: k7567 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7577 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r7577 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7577 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7577 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7643 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r7643 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7643 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7643 1 
o|replaced variables: 33 
o|removed binding forms: 4 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5830 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r5830 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5830 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5830 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6343 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r6343 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6343 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r6343 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7078 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r7078 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7078 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7078 2 
o|inlining procedure: k7415 
o|inlining procedure: k7415 
o|inlining procedure: k7419 
o|inlining procedure: k7419 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7583 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r7583 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7583 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7583 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7649 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r7649 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7649 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7649 2 
o|converted assignments to bindings: (setup1878) 
o|converted assignments to bindings: (check1158) 
o|simplifications: ((let . 2)) 
o|removed binding forms: 39 
o|contracted procedure: k4470 
o|contracted procedure: k4510 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5836 3 
(o x)|known list op on rest arg sublist: ##core#rest-car r5836 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5836 3 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5836 3 
o|substituted constant variable: r74169097 
o|substituted constant variable: r74209099 
o|removed binding forms: 13 
o|removed binding forms: 4 
o|direct leaf routine/allocation: g10871094 0 
o|direct leaf routine/allocation: doloop14301448 0 
o|direct leaf routine/allocation: doloop14291431 0 
o|direct leaf routine/allocation: peek1709 0 
o|direct leaf routine/allocation: g21792186 0 
o|contracted procedure: "(posix-common.scm:732) k4275" 
o|contracted procedure: k4962 
o|contracted procedure: k4965 
o|converted assignments to bindings: (doloop14301448) 
o|converted assignments to bindings: (doloop14291431) 
o|contracted procedure: "(posixunix.scm:835) k5997" 
o|contracted procedure: "(posixunix.scm:1257) k7524" 
o|simplifications: ((let . 2)) 
o|removed binding forms: 5 
o|direct leaf routine/allocation: for-each-loop10861099 0 
o|direct leaf routine/allocation: for-each-loop21782196 0 
o|converted assignments to bindings: (for-each-loop10861099) 
o|converted assignments to bindings: (for-each-loop21782196) 
o|simplifications: ((let . 2)) 
o|customizable procedures: (va8877 va8875 va8873 va8871 loop1563 %process2167 chkstrlst2174 chicken.posix#process-impl output-port2120 make-on-close2083 input-port2119 spawn2118 connect-parent2085 needed-pipe2084 k7392 connect-child2086 chicken.posix#call-with-exec-args setup1878 k6594 loop1848 k6418 loop1755 ready?1708 fetch1710 loop1657 k5488 for-each-loop15421554 k4948 k4951 lp1484 lp1503 k5030 check1158 chicken.posix#check-environment-list map-loop11281146 chicken.posix#list->c-string-buffer k4342 doloop10741075 tmp12590 tmp22591 doloop10551056 chicken.posix#free-c-string-buffer chicken.posix#process-wait-impl g979986 for-each-loop978992 chicken.posix#check-time-vector k3639 mode802 check803 chicken.posix#chown k3186 chicken.posix#stat g260269 map-loop254276) 
o|calls to known targets: 220 
o|unused rest argument: rest241243 f_2819 
o|unused rest argument: rest688690 f_3073 
o|unused rest argument: rest754756 f_3262 
o|unused rest argument: rest883884 f_3716 
o|unused rest argument: rest894895 f_3737 
o|unused rest argument: rest912913 f_3769 
o|unused rest argument: rest953955 f_3852 
o|unused rest argument: rest10001001 f_3953 
o|unused rest argument: args1016 f_4021 
o|identified direct recursive calls: f_4267 1 
o|unused rest argument: rest13521355 f_4738 
o|identified direct recursive calls: f_5241 1 
o|identified direct recursive calls: f_5199 1 
o|identified direct recursive calls: f_5062 2 
o|identified direct recursive calls: f_5121 2 
o|unused rest argument: rest15311532 f_5322 
o|unused rest argument: rest15991601 f_5483 
o|unused rest argument: rest16461648 f_5681 
o|identified direct recursive calls: f_6070 1 
o|unused rest argument: rest16851689 f_5818 
o|identified direct recursive calls: f_6493 1 
o|unused rest argument: rest18031807 f_6331 
o|unused rest argument: rest19651967 f_6895 
o|unused rest argument: rest19931994 f_6967 
o|unused rest argument: rest20242026 f_7066 
o|identified direct recursive calls: f_7516 1 
o|unused rest argument: rest22092211 f_7571 
o|unused rest argument: rest22312233 f_7637 
o|unused rest argument: _22562259 f_7726 
o|identified direct recursive calls: f_7921 2 
o|unused rest argument: rest860861 f_7954 
o|fast box initializations: 20 
o|fast global references: 76 
o|fast global assignments: 11 
o|dropping unused closure argument: f_3027 
o|dropping unused closure argument: f_3505 
o|dropping unused closure argument: f_3542 
o|dropping unused closure argument: f_3697 
o|dropping unused closure argument: f_4092 
o|dropping unused closure argument: f_4209 
o|dropping unused closure argument: f_4243 
o|dropping unused closure argument: f_4446 
o|dropping unused closure argument: f_5565 
o|dropping unused closure argument: f_6631 
o|dropping unused closure argument: f_7144 
o|dropping unused closure argument: f_7279 
o|dropping unused closure argument: f_7316 
o|dropping unused closure argument: f_7336 
o|dropping unused closure argument: f_7348 
o|dropping unused closure argument: f_7500 
*/
/* end of file */
