/* Generated from posix.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: posix.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file posixwin.c -feature platform-windows -emit-import-library chicken.errno -emit-import-library chicken.file.posix -emit-import-library chicken.time.posix -emit-import-library chicken.process -emit-import-library chicken.process.signal -emit-import-library chicken.process-context.posix -no-module-registration
   unit: posix
   uses: extras scheduler data-structures port pathname lolevel library
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



#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif

#include <direct.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <process.h>
#include <signal.h>
#include <stdio.h>
#include <utime.h>
#include <windows.h>
#include <winsock2.h>

#define PIPE_BUF	512

#ifndef EWOULDBLOCK
# define EWOULDBLOCK 0
#endif

static C_TLS int C_pipefds[ 2 ];
static C_TLS time_t C_secs;

/* pipe handles */
static C_TLS HANDLE C_rd0, C_wr0, C_wr0_, C_rd1, C_wr1, C_rd1_;
static C_TLS HANDLE C_save0, C_save1; /* saved I/O handles */
static C_TLS char C_rdbuf; /* one-char buffer for read */
static C_TLS int C_exstatus;

/* platform information; initialized for cached testing */
static C_TLS char C_shlcmd[256] = "";

/* Current user name */
static C_TLS TCHAR C_username[255 + 1] = "";

#define open_binary_input_pipe(a, n, name)   C_mpointer(a, _popen(C_c_string(name), "r"))
#define open_text_input_pipe(a, n, name)     open_binary_input_pipe(a, n, name)
#define open_binary_output_pipe(a, n, name)  C_mpointer(a, _popen(C_c_string(name), "w"))
#define open_text_output_pipe(a, n, name)    open_binary_output_pipe(a, n, name)
#define close_pipe(p)			     C_fix(_pclose(C_port_file(p)))

#define C_chmod(fn, m)	    C_fix(chmod(C_c_string(fn), C_unfix(m)))
#define C_pipe(d, m)	    C_fix(_pipe(C_pipefds, PIPE_BUF, C_unfix(m)))
#define C_close(fd)	    C_fix(close(C_unfix(fd)))

#define C_u_i_lstat(fn)     C_u_i_stat(fn)

#define C_u_i_execvp(f,a)   C_fix(execvp(C_c_string(f), (const char *const *)C_c_pointer_vector_or_null(a)))
#define C_u_i_execve(f,a,e) C_fix(execve(C_c_string(f), (const char *const *)C_c_pointer_vector_or_null(a), (const char *const *)C_c_pointer_vector_or_null(e)))

/* MS replacement for the fork-exec pair */
#define C_u_i_spawnvp(m,f,a)    C_fix(spawnvp(C_unfix(m), C_c_string(f), (const char *const *)C_c_pointer_vector_or_null(a)))
#define C_u_i_spawnvpe(m,f,a,e) C_fix(spawnvpe(C_unfix(m), C_c_string(f), (const char *const *)C_c_pointer_vector_or_null(a), (const char *const *)C_c_pointer_vector_or_null(e)))

#define C_open(fn, fl, m)   C_fix(open(C_c_string(fn), C_unfix(fl), C_unfix(m)))
#define C_read(fd, b, n)    C_fix(read(C_unfix(fd), C_data_pointer(b), C_unfix(n)))
#define C_write(fd, b, n)   C_fix(write(C_unfix(fd), C_data_pointer(b), C_unfix(n)))

#define C_flushall()	    C_fix(_flushall())

#define C_umask(m)          C_fix(_umask(C_unfix(m)))

#define C_ctime(n)	    (C_secs = (n), ctime(&C_secs))

#define TIME_STRING_MAXLENGTH 255
static char C_time_string [TIME_STRING_MAXLENGTH + 1];
#undef TIME_STRING_MAXLENGTH

/*
  mapping from Win32 error codes to errno
*/

typedef struct
{
    DWORD   win32;
    int	    libc;
} errmap_t;

static errmap_t errmap[] =
{
    {ERROR_INVALID_FUNCTION,	  EINVAL},
    {ERROR_FILE_NOT_FOUND,	  ENOENT},
    {ERROR_PATH_NOT_FOUND,	  ENOENT},
    {ERROR_TOO_MANY_OPEN_FILES,	  EMFILE},
    {ERROR_ACCESS_DENIED,	  EACCES},
    {ERROR_INVALID_HANDLE,	  EBADF},
    {ERROR_ARENA_TRASHED,	  ENOMEM},
    {ERROR_NOT_ENOUGH_MEMORY,	  ENOMEM},
    {ERROR_INVALID_BLOCK,	  ENOMEM},
    {ERROR_BAD_ENVIRONMENT,	  E2BIG},
    {ERROR_BAD_FORMAT,		  ENOEXEC},
    {ERROR_INVALID_ACCESS,	  EINVAL},
    {ERROR_INVALID_DATA,	  EINVAL},
    {ERROR_INVALID_DRIVE,	  ENOENT},
    {ERROR_CURRENT_DIRECTORY,	  EACCES},
    {ERROR_NOT_SAME_DEVICE,	  EXDEV},
    {ERROR_NO_MORE_FILES,	  ENOENT},
    {ERROR_LOCK_VIOLATION,	  EACCES},
    {ERROR_BAD_NETPATH,		  ENOENT},
    {ERROR_NETWORK_ACCESS_DENIED, EACCES},
    {ERROR_BAD_NET_NAME,	  ENOENT},
    {ERROR_FILE_EXISTS,		  EEXIST},
    {ERROR_CANNOT_MAKE,		  EACCES},
    {ERROR_FAIL_I24,		  EACCES},
    {ERROR_INVALID_PARAMETER,	  EINVAL},
    {ERROR_NO_PROC_SLOTS,	  EAGAIN},
    {ERROR_DRIVE_LOCKED,	  EACCES},
    {ERROR_BROKEN_PIPE,		  EPIPE},
    {ERROR_DISK_FULL,		  ENOSPC},
    {ERROR_INVALID_TARGET_HANDLE, EBADF},
    {ERROR_INVALID_HANDLE,	  EINVAL},
    {ERROR_WAIT_NO_CHILDREN,	  ECHILD},
    {ERROR_CHILD_NOT_COMPLETE,	  ECHILD},
    {ERROR_DIRECT_ACCESS_HANDLE,  EBADF},
    {ERROR_NEGATIVE_SEEK,	  EINVAL},
    {ERROR_SEEK_ON_DEVICE,	  EACCES},
    {ERROR_DIR_NOT_EMPTY,	  ENOTEMPTY},
    {ERROR_NOT_LOCKED,		  EACCES},
    {ERROR_BAD_PATHNAME,	  ENOENT},
    {ERROR_MAX_THRDS_REACHED,	  EAGAIN},
    {ERROR_LOCK_FAILED,		  EACCES},
    {ERROR_ALREADY_EXISTS,	  EEXIST},
    {ERROR_FILENAME_EXCED_RANGE,  ENOENT},
    {ERROR_NESTING_NOT_ALLOWED,	  EAGAIN},
    {ERROR_NOT_ENOUGH_QUOTA,	  ENOMEM},
    {0, 0}
};

static void C_fcall
set_errno(DWORD w32err)
{
    errmap_t *map;
    for (map = errmap; map->win32; ++map)
    {
	if (map->win32 == w32err)
	{
	    errno = map->libc;
	    return;
	}
    }
    errno = ENOSYS; /* For lack of anything better */
}

static int C_fcall
set_last_errno()
{
    set_errno(GetLastError());
    return 0;
}

static int fd_to_path(C_word fd, TCHAR path[])
{
  DWORD result;
  HANDLE fh = (HANDLE)_get_osfhandle(C_unfix(fd));

  if (fh == INVALID_HANDLE_VALUE) {
    set_last_errno();
    return -1;
  }

  result = GetFinalPathNameByHandle(fh, path, MAX_PATH, VOLUME_NAME_DOS);
  if (result == 0) {
    set_last_errno();
    return -1;
  } else if (result >= MAX_PATH) { /* Shouldn't happen */
    errno = ENOMEM; /* For lack of anything better */
    return -1;
  } else {
    return 0;
  }
}

static C_word C_fchmod(C_word fd, C_word m)
{
  TCHAR path[MAX_PATH];
  if (fd_to_path(fd, path) == -1) return C_fix(-1);
  else return C_fix(chmod(path, C_unfix(m)));
}

static C_word C_fchdir(C_word fd)
{
  TCHAR path[MAX_PATH];
  if (fd_to_path(fd, path) == -1) return C_fix(-1);
  else return C_fix(chdir(path));
}

static int C_fcall
process_wait(C_word h, C_word t)
{
    if (WaitForSingleObject((HANDLE)h, (t ? 0 : INFINITE)) == WAIT_OBJECT_0)
    {
	DWORD ret;
	if (GetExitCodeProcess((HANDLE)h, &ret))
	{
	    CloseHandle((HANDLE)h);
	    C_exstatus = ret;
	    return 1;
	}
    }
    return set_last_errno();
}

#define C_process_wait(p, t) (process_wait(C_unfix(p), C_truep(t)) ? C_SCHEME_TRUE : C_SCHEME_FALSE)


static C_TLS int C_isNT = 0;


static int C_fcall
C_windows_nt()
{
  static int has_info = 0;

  if(!has_info) {
    OSVERSIONINFO ovf;
    ZeroMemory(&ovf, sizeof(ovf));
    ovf.dwOSVersionInfoSize = sizeof(ovf);
    has_info = 1;

    if(GetVersionEx(&ovf)) {
      SYSTEM_INFO si;

      switch (ovf.dwPlatformId) {
      case VER_PLATFORM_WIN32_NT:
        return C_isNT = 1;
      }
    }
  }

  return C_isNT;
}


static int C_fcall
get_shlcmd()
{
    /* Do we need to build the shell command pathname? */
    if (!strlen(C_shlcmd))
    {
      char *cmdnam = C_windows_nt() ? "\\cmd.exe" : "\\command.com";
      UINT len = GetSystemDirectory(C_shlcmd, sizeof(C_shlcmd) - strlen(cmdnam));
      if (len)
	C_strlcpy(C_shlcmd + len, cmdnam, sizeof(C_shlcmd));
      else
	return set_last_errno();
    }

    return 1;
}

#define C_sysinfo() (sysinfo() ? C_SCHEME_TRUE : C_SCHEME_FALSE)
#define C_get_shlcmd() (get_shlcmd() ? C_SCHEME_TRUE : C_SCHEME_FALSE)

/* GetUserName */

static int C_fcall
get_user_name()
{
    if (!strlen(C_username))
    {
	DWORD bufCharCount = sizeof(C_username) / sizeof(C_username[0]);
	if (!GetUserName(C_username, &bufCharCount))
	    return set_last_errno();
    }
    return 1;
}

#define C_get_user_name() (get_user_name() ? C_SCHEME_TRUE : C_SCHEME_FALSE)

/*
    Spawn a process directly.
    Params:
    app		Command to execute.
    cmdlin	Command line (arguments).
    env		Environment for the new process (may be NULL).
    handle, stdin, stdout, stderr
		Spawned process info are returned in integers.
		When spawned process shares standard io stream with the parent
		process the respective value in handle, stdin, stdout, stderr
		is -1.
    params	A bitmask controling operation.
		Bit 1: Child & parent share standard input if this bit is set.
		Bit 2: Share standard output if bit is set.
		Bit 3: Share standard error if bit is set.

    Returns: zero return value indicates failure.
*/
static int C_fcall
C_process(const char *app, const char *cmdlin, const char **env,
	  int *phandle, int *pstdin_fd, int *pstdout_fd, int *pstderr_fd,
	  int params)
{
    int i;
    int success = TRUE;
    const int f_share_io[3] = { params & 1, params & 2, params & 4};
    int io_fds[3] = { -1, -1, -1 };
    HANDLE
	child_io_handles[3] = { NULL, NULL, NULL },
	standard_io_handles[3] = {
	    GetStdHandle(STD_INPUT_HANDLE),
	    GetStdHandle(STD_OUTPUT_HANDLE),
	    GetStdHandle(STD_ERROR_HANDLE)};
    const char modes[3] = "rww";
    HANDLE cur_process = GetCurrentProcess(), child_process = NULL;
    void* envblk = NULL;

    /****** create io handles & fds ***/

    for (i=0; i<3 && success; ++i)
    {
	if (f_share_io[i])
	{
	    success = DuplicateHandle(
		cur_process, standard_io_handles[i],
		cur_process, &child_io_handles[i],
		0, FALSE, DUPLICATE_SAME_ACCESS);
	}
	else
	{
	    HANDLE a, b;
	    success = CreatePipe(&a,&b,NULL,0);
	    if(success)
	    {
		HANDLE parent_end;
		if (modes[i]=='r') { child_io_handles[i]=a; parent_end=b; }
		else		   { parent_end=a; child_io_handles[i]=b; }
		success = (io_fds[i] = _open_osfhandle((C_word)parent_end,0)) >= 0;
                /* Make new handle inheritable */
		if (success)
		  success = SetHandleInformation(child_io_handles[i], HANDLE_FLAG_INHERIT, -1);
	    }
	}
    }

#if 0 /* Requires a sorted list by key! */
    /****** create environment block if necessary ****/

    if (env && success)
    {
	char** p;
	int len = 0;

	for (p = env; *p; ++p) len += strlen(*p) + 1;

	if (envblk = C_malloc(len + 1))
	{
	    char* pb = (char*)envblk;
	    for (p = env; *p; ++p)
	    {
		C_strlcpy(pb, *p, len+1);
		pb += strlen(*p) + 1;
	    }
	    *pb = '\0';
            /* This _should_ already have been checked for embedded NUL bytes */
	}
	else
	    success = FALSE;
    }
#endif

    /****** finally spawn process ****/

    if (success)
    {
	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	ZeroMemory(&pi,sizeof pi);
	ZeroMemory(&si,sizeof si);
	si.cb = sizeof si;
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = child_io_handles[0];
	si.hStdOutput = child_io_handles[1];
	si.hStdError = child_io_handles[2];

	/* FIXME passing 'app' param causes failure & possible stack corruption */
	success = CreateProcess(
	    NULL, (char*)cmdlin, NULL, NULL, TRUE, 0, envblk, NULL, &si, &pi);

	if (success)
	{
	    child_process=pi.hProcess;
	    CloseHandle(pi.hThread);
	}
	else
	    set_last_errno();
    }
    else
	set_last_errno();

    /****** cleanup & return *********/

    /* parent must close child end */
    for (i=0; i<3; ++i) {
	if (child_io_handles[i] != NULL)
	    CloseHandle(child_io_handles[i]);
    }

    if (success)
    {
	*phandle = (C_word)child_process;
	*pstdin_fd = io_fds[0];
	*pstdout_fd = io_fds[1];
	*pstderr_fd = io_fds[2];
    }
    else
    {
	for (i=0; i<3; ++i) {
	    if (io_fds[i] != -1)
		_close(io_fds[i]);
	}
    }

    return success;
}

static int set_file_mtime(char *filename, C_word atime, C_word mtime)
{
  struct stat sb;
  struct _utimbuf tb;

  /* Only stat if needed */
  if (atime == C_SCHEME_FALSE || mtime == C_SCHEME_FALSE) {
    if (C_stat(filename, &sb) == -1) return -1;
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
  return _utime(filename, &tb);
}



static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_scheduler_toplevel)
C_externimport void C_ccall C_scheduler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lolevel_toplevel)
C_externimport void C_ccall C_lolevel_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[419];
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
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,11),40,97,51,53,53,56,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,10),40,103,57,55,57,32,115,105,103,41,0,0,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,15),40,102,95,51,53,54,55,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,57,55,56,32,103,57,56,53,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,109,97,107,101,45,115,105,103,110,97,108,45,104,97,110,100,108,101,114,32,46,32,115,105,103,115,41,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,105,103,110,111,114,101,32,115,105,103,41,0,0,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,100,101,102,97,117,108,116,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,108,101,101,112,32,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,7),40,97,51,54,53,56,41,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,24),40,97,51,54,54,52,32,101,112,105,100,32,101,110,111,114,109,32,101,99,111,100,101,41};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,119,97,105,116,32,46,32,97,114,103,115,41,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,7),40,97,51,55,51,51,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,11),40,97,51,55,50,55,32,101,120,110,41,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,17),40,100,111,108,111,111,112,49,48,53,53,32,115,108,32,105,41,0,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,10),40,116,109,112,49,50,50,51,57,41,0,0,0,0,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,7),40,97,51,56,48,55,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,15),40,116,109,112,50,50,50,52,48,32,97,114,103,115,41,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,7),40,97,51,55,52,50,41,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,9),40,97,51,55,50,49,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,61),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,108,105,115,116,45,62,99,45,115,116,114,105,110,103,45,98,117,102,102,101,114,32,115,116,114,105,110,103,45,108,105,115,116,32,99,111,110,118,101,114,116,32,108,111,99,41,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,14),40,100,111,108,111,111,112,49,48,55,52,32,105,41,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,102,114,101,101,45,99,45,115,116,114,105,110,103,45,98,117,102,102,101,114,32,98,117,102,102,101,114,45,97,114,114,97,121,41,0,0,0,0,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,7),40,103,49,48,56,55,41,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,48,56,54,41,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,104,101,99,107,45,101,110,118,105,114,111,110,109,101,110,116,45,108,105,115,116,32,108,115,116,32,108,111,99,41,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,7),40,110,111,112,32,120,41,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,7),40,97,51,57,51,50,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,11),40,97,51,57,50,54,32,101,120,110,41,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,49,50,56,32,103,49,49,52,48,41,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,7),40,97,51,57,53,51,41,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,7),40,97,52,48,51,52,41,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,14),40,97,52,48,50,56,32,46,32,97,114,103,115,41,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,7),40,97,51,57,52,55,41,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,9),40,97,51,57,50,48,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,77),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,99,97,108,108,45,119,105,116,104,45,101,120,101,99,45,97,114,103,115,32,108,111,99,32,102,105,108,101,110,97,109,101,32,97,114,103,99,111,110,118,32,97,114,103,108,105,115,116,32,101,110,118,108,105,115,116,32,112,114,111,99,41,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,21),40,99,104,101,99,107,32,108,111,99,32,99,109,100,32,105,110,112,32,114,41,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,111,112,101,110,45,105,110,112,117,116,45,112,105,112,101,32,99,109,100,32,46,32,109,41,0,0,0,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,111,112,101,110,45,111,117,116,112,117,116,45,112,105,112,101,32,99,109,100,32,46,32,109,41,0,0,0,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,108,111,115,101,45,105,110,112,117,116,45,112,105,112,101,32,112,111,114,116,41,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,108,111,115,101,45,111,117,116,112,117,116,45,112,105,112,101,32,112,111,114,116,41};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,7),40,97,52,49,57,55,41,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,17),40,97,52,50,48,56,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,7),40,97,52,50,48,50,41,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,7),40,97,52,50,49,55,41,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,119,105,116,104,45,105,110,112,117,116,45,102,114,111,109,45,112,105,112,101,32,99,109,100,32,116,104,117,110,107,32,46,32,109,111,100,101,41,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,7),40,97,52,50,51,49,41,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,17),40,97,52,50,51,55,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,97,108,108,45,119,105,116,104,45,111,117,116,112,117,116,45,112,105,112,101,32,99,109,100,32,112,114,111,99,32,46,32,109,111,100,101,41,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,7),40,97,52,50,53,53,41,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,17),40,97,52,50,54,49,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,97,108,108,45,119,105,116,104,45,105,110,112,117,116,45,112,105,112,101,32,99,109,100,32,112,114,111,99,32,46,32,109,111,100,101,41,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,7),40,97,52,50,55,57,41,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,17),40,97,52,50,57,48,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,7),40,97,52,50,56,52,41,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,7),40,97,52,50,57,57,41,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,119,105,116,104,45,111,117,116,112,117,116,45,116,111,45,112,105,112,101,32,99,109,100,32,116,104,117,110,107,32,46,32,109,111,100,101,41,0,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,111,112,101,110,32,102,105,108,101,110,97,109,101,32,102,108,97,103,115,32,46,32,109,111,100,101,41,0,0,0,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,99,108,111,115,101,32,102,100,41,0,0,0,0,0,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,114,101,97,100,32,102,100,32,115,105,122,101,32,46,32,98,117,102,102,101,114,41,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,119,114,105,116,101,32,102,100,32,98,117,102,102,101,114,32,46,32,115,105,122,101,41};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,13),40,115,117,102,102,105,120,45,108,111,111,112,41,0,0,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,54,48,41};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,99,111,117,110,116,41,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,54,56,41};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,109,107,115,116,101,109,112,32,116,101,109,112,108,97,116,101,41,0,0,0,0,0,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,99,114,101,97,116,101,45,112,105,112,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,100,117,112,108,105,99,97,116,101,45,102,105,108,101,110,111,32,111,108,100,32,46,32,110,101,119,41,0,0,0,0,0,0};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,108,111,99,97,108,45,116,105,109,101,122,111,110,101,45,97,98,98,114,101,118,105,97,116,105,111,110,41};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,113,117,111,116,101,45,97,114,103,45,115,116,114,105,110,103,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,10),40,102,95,52,56,49,51,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,25),40,97,52,55,57,56,32,112,114,103,32,97,114,103,98,117,102,32,101,110,118,98,117,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,101,120,101,99,117,116,101,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,10),40,102,95,52,56,57,54,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,25),40,97,52,56,56,49,32,112,114,103,32,97,114,103,98,117,102,32,101,110,118,98,117,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,112,97,119,110,32,109,111,100,101,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,111,115,105,120,35,115,104,101,108,108,45,99,111,109,109,97,110,100,32,108,111,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,114,117,110,32,102,32,46,32,97,114,103,115,41,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,7),40,103,49,54,51,55,41,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,54,51,54,41,0,0,0,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,15),40,99,104,107,115,116,114,108,115,116,32,108,115,116,41,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,53,54,49,32,103,49,53,55,51,41,0,0,0,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,7),40,97,53,50,51,55,41,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,22),40,97,53,50,52,51,32,105,110,32,111,117,116,32,112,105,100,32,101,114,114,41,0,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,39),40,37,112,114,111,99,101,115,115,32,108,111,99,32,101,114,114,63,32,99,109,100,32,97,114,103,115,32,101,110,118,32,101,120,97,99,116,102,41,0};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,32,99,109,100,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,42,32,99,109,100,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,117,115,101,114,45,110,97,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,99,114,101,97,116,101,45,102,105,102,111,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,50),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,114,101,97,116,101,45,115,101,115,115,105,111,110,32,46,32,95,41,0,0,0,0,0,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,99,114,101,97,116,101,45,115,121,109,98,111,108,105,99,45,108,105,110,107,32,46,32,95,41,0,0,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,62),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,101,102,102,101,99,116,105,118,101,45,103,114,111,117,112,45,105,100,32,46,32,95,41,0,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,61),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,101,102,102,101,99,116,105,118,101,45,117,115,101,114,45,105,100,32,46,32,95,41,0,0,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,63),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,101,102,102,101,99,116,105,118,101,45,117,115,101,114,45,110,97,109,101,32,46,32,95,41,0};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,103,114,111,117,112,45,105,100,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,99,117,114,114,101,110,116,45,117,115,101,114,45,105,100,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,99,111,110,116,114,111,108,32,46,32,95,41,0,0,0};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,105,110,107,32,46,32,95,41,0,0,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,111,99,107,32,46,32,95,41,0,0,0,0,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,108,111,99,107,47,98,108,111,99,107,105,110,103,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,115,101,108,101,99,116,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,116,101,115,116,45,108,111,99,107,32,46,32,95,41,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,116,114,117,110,99,97,116,101,32,46,32,95,41,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,102,105,108,101,45,117,110,108,111,99,107,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,53),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,112,97,114,101,110,116,45,112,114,111,99,101,115,115,45,105,100,32,46,32,95,41,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,102,111,114,107,32,46,32,95,41,0,0,0,0,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,112,114,111,99,101,115,115,45,103,114,111,117,112,45,105,100,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,35,112,114,111,99,101,115,115,45,115,105,103,110,97,108,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,46,112,111,115,105,120,35,114,101,97,100,45,115,121,109,98,111,108,105,99,45,108,105,110,107,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,101,116,45,97,108,97,114,109,33,32,46,32,95,41,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,115,101,116,45,114,111,111,116,45,100,105,114,101,99,116,111,114,121,33,32,46,32,95,41,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,101,116,45,115,105,103,110,97,108,45,109,97,115,107,33,32,46,32,95,41,0,0,0};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,109,97,115,107,32,46,32,95,41};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,109,97,115,107,33,32,46,32,95,41,0,0,0,0,0,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,109,97,115,107,101,100,63,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,46,115,105,103,110,97,108,35,115,105,103,110,97,108,45,117,110,109,97,115,107,33,32,46,32,95,41,0,0,0,0,0};
static C_char C_TLS li160[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,114,111,99,101,115,115,45,99,111,110,116,101,120,116,46,112,111,115,105,120,35,117,115,101,114,45,105,110,102,111,114,109,97,116,105,111,110,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li161[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,117,116,99,45,116,105,109,101,45,62,115,101,99,111,110,100,115,32,46,32,95,41,0,0,0,0,0,0};
static C_char C_TLS li162[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,116,105,109,101,46,112,111,115,105,120,35,115,116,114,105,110,103,45,62,116,105,109,101,32,46,32,95,41,0,0,0};
static C_char C_TLS li163[] C_aligned={C_lihdr(0,0,21),40,99,104,105,99,107,101,110,46,101,114,114,110,111,35,101,114,114,110,111,41,0,0,0};
static C_char C_TLS li164[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,55,54,41};
static C_char C_TLS li165[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,55,56,41};
static C_char C_TLS li166[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,56,48,41};
static C_char C_TLS li167[] C_aligned={C_lihdr(0,0,8),40,118,97,54,50,56,50,41};
static C_char C_TLS li168[] C_aligned={C_lihdr(0,0,11),40,97,53,54,54,55,32,115,105,103,41,0,0,0,0,0};
static C_char C_TLS li169[] C_aligned={C_lihdr(0,0,14),40,97,53,54,55,54,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li170[] C_aligned={C_lihdr(0,0,10),40,97,53,55,48,49,32,117,109,41,0,0,0,0,0,0};
static C_char C_TLS li171[] C_aligned={C_lihdr(0,0,12),40,97,53,55,48,55,32,112,111,114,116,41,0,0,0,0};
static C_char C_TLS li172[] C_aligned={C_lihdr(0,0,9),40,97,53,55,52,52,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li173[] C_aligned={C_lihdr(0,0,9),40,97,53,55,53,48,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li174[] C_aligned={C_lihdr(0,0,9),40,97,53,55,53,54,32,102,41,0,0,0,0,0,0,0};
static C_char C_TLS li175[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from k5021 */
C_regparm static C_word C_fcall stub1516(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4,C_word C_a5,C_word C_a6,C_word C_a7){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_string_or_null(C_a0);
char * t1=(char * )C_string_or_null(C_a1);
void * t2=(void * )C_c_pointer_or_null(C_a2);
int *t3=(int *)C_c_pointer_or_null(C_a3);
int *t4=(int *)C_c_pointer_or_null(C_a4);
int *t5=(int *)C_c_pointer_or_null(C_a5);
int *t6=(int *)C_c_pointer_or_null(C_a6);
int t7=(int )C_unfix(C_a7);
C_r=C_mk_bool(C_process(t0,t1,t2,t3,t4,t5,t6,t7));
return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub1428(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char *z = (_daylight ? _tzname[1] : _tzname[0]);

C_return(z);
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

/* from k3460 */
C_regparm static C_word C_fcall stub941(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word t0=(C_word )(C_a0);
C_word t1=(C_word )(C_a1);
void * t2=(void * )C_data_pointer_or_null(C_a2);
C_r=C_mpointer(&C_a,(void*)C_strftime(t0,t1,t2));
return C_r;}

/* from k3447 */
C_regparm static C_word C_fcall stub931(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word t0=(C_word )(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
C_r=C_mpointer(&C_a,(void*)C_asctime(t0,t1));
return C_r;}

/* from k3379 */
C_regparm static C_word C_fcall stub904(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_num_to_int(C_a0);
C_r=C_mpointer(&C_a,(void*)C_ctime(t0));
return C_r;}

/* from chicken.process-context.posix#current-process-id in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
C_regparm static C_word C_fcall stub848(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getpid());
return C_r;}

/* from k2790 in k2784 in k2781 in k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
C_regparm static C_word C_fcall stub729(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_string_or_null(C_a0);
C_word t1=(C_word )(C_a1);
C_word t2=(C_word )(C_a2);
C_r=C_fix((C_word)set_file_mtime(t0,t1,t2));
return C_r;}

/* from k2620 */
C_regparm static C_word C_fcall stub655(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)strerror(t0));
return C_r;}

C_noret_decl(f6287)
static void C_ccall f6287(C_word c,C_word *av) C_noret;
C_noret_decl(f6291)
static void C_ccall f6291(C_word c,C_word *av) C_noret;
C_noret_decl(f_2294)
static void C_ccall f_2294(C_word c,C_word *av) C_noret;
C_noret_decl(f_2297)
static void C_ccall f_2297(C_word c,C_word *av) C_noret;
C_noret_decl(f_2300)
static void C_ccall f_2300(C_word c,C_word *av) C_noret;
C_noret_decl(f_2303)
static void C_ccall f_2303(C_word c,C_word *av) C_noret;
C_noret_decl(f_2306)
static void C_ccall f_2306(C_word c,C_word *av) C_noret;
C_noret_decl(f_2309)
static void C_ccall f_2309(C_word c,C_word *av) C_noret;
C_noret_decl(f_2312)
static void C_ccall f_2312(C_word c,C_word *av) C_noret;
C_noret_decl(f_2398)
static void C_ccall f_2398(C_word c,C_word *av) C_noret;
C_noret_decl(f_2415)
static void C_ccall f_2415(C_word c,C_word *av) C_noret;
C_noret_decl(f_2417)
static void C_ccall f_2417(C_word c,C_word *av) C_noret;
C_noret_decl(f_2421)
static void C_ccall f_2421(C_word c,C_word *av) C_noret;
C_noret_decl(f_2433)
static void C_ccall f_2433(C_word c,C_word *av) C_noret;
C_noret_decl(f_2437)
static void C_ccall f_2437(C_word c,C_word *av) C_noret;
C_noret_decl(f_2447)
static void C_fcall f_2447(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2468)
static void C_ccall f_2468(C_word c,C_word *av) C_noret;
C_noret_decl(f_2471)
static void C_ccall f_2471(C_word c,C_word *av) C_noret;
C_noret_decl(f_2482)
static void C_ccall f_2482(C_word c,C_word *av) C_noret;
C_noret_decl(f_2488)
static void C_fcall f_2488(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2513)
static void C_ccall f_2513(C_word c,C_word *av) C_noret;
C_noret_decl(f_2623)
static void C_ccall f_2623(C_word c,C_word *av) C_noret;
C_noret_decl(f_2627)
static void C_ccall f_2627(C_word c,C_word *av) C_noret;
C_noret_decl(f_2634)
static void C_ccall f_2634(C_word c,C_word *av) C_noret;
C_noret_decl(f_2638)
static void C_ccall f_2638(C_word c,C_word *av) C_noret;
C_noret_decl(f_2641)
static void C_fcall f_2641(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2645)
static void C_ccall f_2645(C_word c,C_word *av) C_noret;
C_noret_decl(f_2666)
static void C_ccall f_2666(C_word c,C_word *av) C_noret;
C_noret_decl(f_2670)
static void C_ccall f_2670(C_word c,C_word *av) C_noret;
C_noret_decl(f_2679)
static void C_ccall f_2679(C_word c,C_word *av) C_noret;
C_noret_decl(f_2687)
static void C_ccall f_2687(C_word c,C_word *av) C_noret;
C_noret_decl(f_2694)
static void C_ccall f_2694(C_word c,C_word *av) C_noret;
C_noret_decl(f_2705)
static void C_ccall f_2705(C_word c,C_word *av) C_noret;
C_noret_decl(f_2709)
static void C_ccall f_2709(C_word c,C_word *av) C_noret;
C_noret_decl(f_2712)
static void C_ccall f_2712(C_word c,C_word *av) C_noret;
C_noret_decl(f_2730)
static void C_ccall f_2730(C_word c,C_word *av) C_noret;
C_noret_decl(f_2734)
static void C_ccall f_2734(C_word c,C_word *av) C_noret;
C_noret_decl(f_2744)
static void C_ccall f_2744(C_word c,C_word *av) C_noret;
C_noret_decl(f_2749)
static void C_ccall f_2749(C_word c,C_word *av) C_noret;
C_noret_decl(f_2753)
static void C_ccall f_2753(C_word c,C_word *av) C_noret;
C_noret_decl(f_2755)
static void C_ccall f_2755(C_word c,C_word *av) C_noret;
C_noret_decl(f_2759)
static void C_ccall f_2759(C_word c,C_word *av) C_noret;
C_noret_decl(f_2761)
static void C_ccall f_2761(C_word c,C_word *av) C_noret;
C_noret_decl(f_2765)
static void C_ccall f_2765(C_word c,C_word *av) C_noret;
C_noret_decl(f_2767)
static void C_ccall f_2767(C_word c,C_word *av) C_noret;
C_noret_decl(f_2771)
static void C_ccall f_2771(C_word c,C_word *av) C_noret;
C_noret_decl(f_2783)
static void C_ccall f_2783(C_word c,C_word *av) C_noret;
C_noret_decl(f_2786)
static void C_ccall f_2786(C_word c,C_word *av) C_noret;
C_noret_decl(f_2792)
static void C_ccall f_2792(C_word c,C_word *av) C_noret;
C_noret_decl(f_2802)
static void C_fcall f_2802(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2846)
static void C_ccall f_2846(C_word c,C_word *av) C_noret;
C_noret_decl(f_2850)
static void C_ccall f_2850(C_word c,C_word *av) C_noret;
C_noret_decl(f_2852)
static void C_ccall f_2852(C_word c,C_word *av) C_noret;
C_noret_decl(f_2858)
static void C_ccall f_2858(C_word c,C_word *av) C_noret;
C_noret_decl(f_2866)
static void C_ccall f_2866(C_word c,C_word *av) C_noret;
C_noret_decl(f_2870)
static void C_ccall f_2870(C_word c,C_word *av) C_noret;
C_noret_decl(f_2874)
static void C_ccall f_2874(C_word c,C_word *av) C_noret;
C_noret_decl(f_2876)
static void C_ccall f_2876(C_word c,C_word *av) C_noret;
C_noret_decl(f_2895)
static void C_ccall f_2895(C_word c,C_word *av) C_noret;
C_noret_decl(f_2963)
static void C_ccall f_2963(C_word c,C_word *av) C_noret;
C_noret_decl(f_2971)
static void C_ccall f_2971(C_word c,C_word *av) C_noret;
C_noret_decl(f_2973)
static void C_ccall f_2973(C_word c,C_word *av) C_noret;
C_noret_decl(f_2981)
static void C_ccall f_2981(C_word c,C_word *av) C_noret;
C_noret_decl(f_2983)
static void C_ccall f_2983(C_word c,C_word *av) C_noret;
C_noret_decl(f_2991)
static void C_ccall f_2991(C_word c,C_word *av) C_noret;
C_noret_decl(f_2993)
static void C_ccall f_2993(C_word c,C_word *av) C_noret;
C_noret_decl(f_3001)
static void C_ccall f_3001(C_word c,C_word *av) C_noret;
C_noret_decl(f_3003)
static void C_ccall f_3003(C_word c,C_word *av) C_noret;
C_noret_decl(f_3011)
static void C_ccall f_3011(C_word c,C_word *av) C_noret;
C_noret_decl(f_3013)
static void C_ccall f_3013(C_word c,C_word *av) C_noret;
C_noret_decl(f_3021)
static void C_ccall f_3021(C_word c,C_word *av) C_noret;
C_noret_decl(f_3023)
static void C_ccall f_3023(C_word c,C_word *av) C_noret;
C_noret_decl(f_3031)
static void C_ccall f_3031(C_word c,C_word *av) C_noret;
C_noret_decl(f_3036)
static void C_ccall f_3036(C_word c,C_word *av) C_noret;
C_noret_decl(f_3043)
static void C_ccall f_3043(C_word c,C_word *av) C_noret;
C_noret_decl(f_3046)
static void C_ccall f_3046(C_word c,C_word *av) C_noret;
C_noret_decl(f_3052)
static void C_ccall f_3052(C_word c,C_word *av) C_noret;
C_noret_decl(f_3058)
static void C_ccall f_3058(C_word c,C_word *av) C_noret;
C_noret_decl(f_3091)
static void C_ccall f_3091(C_word c,C_word *av) C_noret;
C_noret_decl(f_3119)
static void C_fcall f_3119(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3127)
static void C_ccall f_3127(C_word c,C_word *av) C_noret;
C_noret_decl(f_3156)
static void C_fcall f_3156(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3169)
static void C_ccall f_3169(C_word c,C_word *av) C_noret;
C_noret_decl(f_3175)
static void C_ccall f_3175(C_word c,C_word *av) C_noret;
C_noret_decl(f_3179)
static void C_ccall f_3179(C_word c,C_word *av) C_noret;
C_noret_decl(f_3187)
static void C_ccall f_3187(C_word c,C_word *av) C_noret;
C_noret_decl(f_3189)
static void C_ccall f_3189(C_word c,C_word *av) C_noret;
C_noret_decl(f_3193)
static void C_ccall f_3193(C_word c,C_word *av) C_noret;
C_noret_decl(f_3201)
static void C_ccall f_3201(C_word c,C_word *av) C_noret;
C_noret_decl(f_3203)
static void C_ccall f_3203(C_word c,C_word *av) C_noret;
C_noret_decl(f_3219)
static void C_ccall f_3219(C_word c,C_word *av) C_noret;
C_noret_decl(f_3228)
static void C_ccall f_3228(C_word c,C_word *av) C_noret;
C_noret_decl(f_3242)
static void C_ccall f_3242(C_word c,C_word *av) C_noret;
C_noret_decl(f_3248)
static void C_ccall f_3248(C_word c,C_word *av) C_noret;
C_noret_decl(f_3252)
static void C_ccall f_3252(C_word c,C_word *av) C_noret;
C_noret_decl(f_3255)
static void C_fcall f_3255(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3258)
static void C_ccall f_3258(C_word c,C_word *av) C_noret;
C_noret_decl(f_3273)
static void C_ccall f_3273(C_word c,C_word *av) C_noret;
C_noret_decl(f_3275)
static void C_ccall f_3275(C_word c,C_word *av) C_noret;
C_noret_decl(f_3278)
static void C_ccall f_3278(C_word c,C_word *av) C_noret;
C_noret_decl(f_3282)
static void C_ccall f_3282(C_word c,C_word *av) C_noret;
C_noret_decl(f_3285)
static void C_ccall f_3285(C_word c,C_word *av) C_noret;
C_noret_decl(f_3294)
static void C_ccall f_3294(C_word c,C_word *av) C_noret;
C_noret_decl(f_3308)
static void C_ccall f_3308(C_word c,C_word *av) C_noret;
C_noret_decl(f_3311)
static void C_fcall f_3311(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3330)
static void C_ccall f_3330(C_word c,C_word *av) C_noret;
C_noret_decl(f_3334)
static void C_ccall f_3334(C_word c,C_word *av) C_noret;
C_noret_decl(f_3337)
static void C_ccall f_3337(C_word c,C_word *av) C_noret;
C_noret_decl(f_3351)
static void C_ccall f_3351(C_word c,C_word *av) C_noret;
C_noret_decl(f_3355)
static void C_ccall f_3355(C_word c,C_word *av) C_noret;
C_noret_decl(f_3358)
static void C_ccall f_3358(C_word c,C_word *av) C_noret;
C_noret_decl(f_3383)
static void C_ccall f_3383(C_word c,C_word *av) C_noret;
C_noret_decl(f_3387)
static void C_ccall f_3387(C_word c,C_word *av) C_noret;
C_noret_decl(f_3390)
static void C_ccall f_3390(C_word c,C_word *av) C_noret;
C_noret_decl(f_3393)
static void C_ccall f_3393(C_word c,C_word *av) C_noret;
C_noret_decl(f_3421)
static void C_ccall f_3421(C_word c,C_word *av) C_noret;
C_noret_decl(f_3425)
static void C_ccall f_3425(C_word c,C_word *av) C_noret;
C_noret_decl(f_3429)
static void C_ccall f_3429(C_word c,C_word *av) C_noret;
C_noret_decl(f_3466)
static void C_ccall f_3466(C_word c,C_word *av) C_noret;
C_noret_decl(f_3473)
static void C_ccall f_3473(C_word c,C_word *av) C_noret;
C_noret_decl(f_3482)
static void C_ccall f_3482(C_word c,C_word *av) C_noret;
C_noret_decl(f_3492)
static void C_ccall f_3492(C_word c,C_word *av) C_noret;
C_noret_decl(f_3496)
static void C_ccall f_3496(C_word c,C_word *av) C_noret;
C_noret_decl(f_3499)
static void C_ccall f_3499(C_word c,C_word *av) C_noret;
C_noret_decl(f_3520)
static void C_ccall f_3520(C_word c,C_word *av) C_noret;
C_noret_decl(f_3528)
static void C_ccall f_3528(C_word c,C_word *av) C_noret;
C_noret_decl(f_3532)
static void C_ccall f_3532(C_word c,C_word *av) C_noret;
C_noret_decl(f_3543)
static void C_ccall f_3543(C_word c,C_word *av) C_noret;
C_noret_decl(f_3545)
static void C_ccall f_3545(C_word c,C_word *av) C_noret;
C_noret_decl(f_3549)
static void C_ccall f_3549(C_word c,C_word *av) C_noret;
C_noret_decl(f_3550)
static void C_fcall f_3550(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3554)
static void C_ccall f_3554(C_word c,C_word *av) C_noret;
C_noret_decl(f_3559)
static void C_ccall f_3559(C_word c,C_word *av) C_noret;
C_noret_decl(f_3566)
static void C_ccall f_3566(C_word c,C_word *av) C_noret;
C_noret_decl(f_3567)
static void C_ccall f_3567(C_word c,C_word *av) C_noret;
C_noret_decl(f_3588)
static void C_fcall f_3588(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3598)
static void C_ccall f_3598(C_word c,C_word *av) C_noret;
C_noret_decl(f_3611)
static void C_ccall f_3611(C_word c,C_word *av) C_noret;
C_noret_decl(f_3615)
static void C_ccall f_3615(C_word c,C_word *av) C_noret;
C_noret_decl(f_3620)
static void C_ccall f_3620(C_word c,C_word *av) C_noret;
C_noret_decl(f_3624)
static void C_ccall f_3624(C_word c,C_word *av) C_noret;
C_noret_decl(f_3629)
static void C_ccall f_3629(C_word c,C_word *av) C_noret;
C_noret_decl(f_3633)
static void C_ccall f_3633(C_word c,C_word *av) C_noret;
C_noret_decl(f_3635)
static void C_ccall f_3635(C_word c,C_word *av) C_noret;
C_noret_decl(f_3654)
static void C_ccall f_3654(C_word c,C_word *av) C_noret;
C_noret_decl(f_3659)
static void C_ccall f_3659(C_word c,C_word *av) C_noret;
C_noret_decl(f_3665)
static void C_ccall f_3665(C_word c,C_word *av) C_noret;
C_noret_decl(f_3706)
static void C_fcall f_3706(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3714)
static void C_ccall f_3714(C_word c,C_word *av) C_noret;
C_noret_decl(f_3717)
static void C_ccall f_3717(C_word c,C_word *av) C_noret;
C_noret_decl(f_3722)
static void C_ccall f_3722(C_word c,C_word *av) C_noret;
C_noret_decl(f_3728)
static void C_ccall f_3728(C_word c,C_word *av) C_noret;
C_noret_decl(f_3734)
static void C_ccall f_3734(C_word c,C_word *av) C_noret;
C_noret_decl(f_3738)
static void C_ccall f_3738(C_word c,C_word *av) C_noret;
C_noret_decl(f_3743)
static void C_ccall f_3743(C_word c,C_word *av) C_noret;
C_noret_decl(f_3745)
static void C_fcall f_3745(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3749)
static void C_ccall f_3749(C_word c,C_word *av) C_noret;
C_noret_decl(f_3751)
static void C_fcall f_3751(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3767)
static void C_ccall f_3767(C_word c,C_word *av) C_noret;
C_noret_decl(f_3773)
static void C_ccall f_3773(C_word c,C_word *av) C_noret;
C_noret_decl(f_3776)
static void C_ccall f_3776(C_word c,C_word *av) C_noret;
C_noret_decl(f_3792)
static void C_ccall f_3792(C_word c,C_word *av) C_noret;
C_noret_decl(f_3802)
static void C_fcall f_3802(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3808)
static void C_ccall f_3808(C_word c,C_word *av) C_noret;
C_noret_decl(f_3819)
static void C_ccall f_3819(C_word c,C_word *av) C_noret;
C_noret_decl(f_3823)
static void C_fcall f_3823(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3827)
static void C_ccall f_3827(C_word c,C_word *av) C_noret;
C_noret_decl(f_3832)
static void C_fcall f_3832(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3842)
static void C_ccall f_3842(C_word c,C_word *av) C_noret;
C_noret_decl(f_3845)
static void C_ccall f_3845(C_word c,C_word *av) C_noret;
C_noret_decl(f_3857)
static void C_fcall f_3857(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3862)
static C_word C_fcall f_3862(C_word t0,C_word t1);
C_noret_decl(f_3881)
static C_word C_fcall f_3881(C_word t0,C_word t1);
C_noret_decl(f_3904)
static void C_ccall f_3904(C_word c,C_word *av) C_noret;
C_noret_decl(f_3906)
static void C_fcall f_3906(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7) C_noret;
C_noret_decl(f_3913)
static void C_ccall f_3913(C_word c,C_word *av) C_noret;
C_noret_decl(f_3916)
static void C_ccall f_3916(C_word c,C_word *av) C_noret;
C_noret_decl(f_3921)
static void C_ccall f_3921(C_word c,C_word *av) C_noret;
C_noret_decl(f_3927)
static void C_ccall f_3927(C_word c,C_word *av) C_noret;
C_noret_decl(f_3933)
static void C_ccall f_3933(C_word c,C_word *av) C_noret;
C_noret_decl(f_3937)
static void C_ccall f_3937(C_word c,C_word *av) C_noret;
C_noret_decl(f_3940)
static void C_ccall f_3940(C_word c,C_word *av) C_noret;
C_noret_decl(f_3948)
static void C_ccall f_3948(C_word c,C_word *av) C_noret;
C_noret_decl(f_3954)
static void C_ccall f_3954(C_word c,C_word *av) C_noret;
C_noret_decl(f_3958)
static void C_fcall f_3958(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3965)
static void C_ccall f_3965(C_word c,C_word *av) C_noret;
C_noret_decl(f_3968)
static void C_ccall f_3968(C_word c,C_word *av) C_noret;
C_noret_decl(f_3972)
static void C_ccall f_3972(C_word c,C_word *av) C_noret;
C_noret_decl(f_3993)
static void C_ccall f_3993(C_word c,C_word *av) C_noret;
C_noret_decl(f_3995)
static void C_fcall f_3995(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4020)
static void C_ccall f_4020(C_word c,C_word *av) C_noret;
C_noret_decl(f_4029)
static void C_ccall f_4029(C_word c,C_word *av) C_noret;
C_noret_decl(f_4035)
static void C_ccall f_4035(C_word c,C_word *av) C_noret;
C_noret_decl(f_4060)
static void C_fcall f_4060(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_4073)
static void C_ccall f_4073(C_word c,C_word *av) C_noret;
C_noret_decl(f_4079)
static void C_ccall f_4079(C_word c,C_word *av) C_noret;
C_noret_decl(f_4093)
static void C_ccall f_4093(C_word c,C_word *av) C_noret;
C_noret_decl(f_4100)
static void C_ccall f_4100(C_word c,C_word *av) C_noret;
C_noret_decl(f_4110)
static void C_ccall f_4110(C_word c,C_word *av) C_noret;
C_noret_decl(f_4119)
static void C_ccall f_4119(C_word c,C_word *av) C_noret;
C_noret_decl(f_4133)
static void C_ccall f_4133(C_word c,C_word *av) C_noret;
C_noret_decl(f_4140)
static void C_ccall f_4140(C_word c,C_word *av) C_noret;
C_noret_decl(f_4150)
static void C_ccall f_4150(C_word c,C_word *av) C_noret;
C_noret_decl(f_4159)
static void C_ccall f_4159(C_word c,C_word *av) C_noret;
C_noret_decl(f_4166)
static void C_ccall f_4166(C_word c,C_word *av) C_noret;
C_noret_decl(f_4174)
static void C_ccall f_4174(C_word c,C_word *av) C_noret;
C_noret_decl(f_4181)
static void C_ccall f_4181(C_word c,C_word *av) C_noret;
C_noret_decl(f_4189)
static void C_ccall f_4189(C_word c,C_word *av) C_noret;
C_noret_decl(f_4193)
static void C_ccall f_4193(C_word c,C_word *av) C_noret;
C_noret_decl(f_4198)
static void C_ccall f_4198(C_word c,C_word *av) C_noret;
C_noret_decl(f_4203)
static void C_ccall f_4203(C_word c,C_word *av) C_noret;
C_noret_decl(f_4209)
static void C_ccall f_4209(C_word c,C_word *av) C_noret;
C_noret_decl(f_4213)
static void C_ccall f_4213(C_word c,C_word *av) C_noret;
C_noret_decl(f_4218)
static void C_ccall f_4218(C_word c,C_word *av) C_noret;
C_noret_decl(f_4223)
static void C_ccall f_4223(C_word c,C_word *av) C_noret;
C_noret_decl(f_4227)
static void C_ccall f_4227(C_word c,C_word *av) C_noret;
C_noret_decl(f_4232)
static void C_ccall f_4232(C_word c,C_word *av) C_noret;
C_noret_decl(f_4238)
static void C_ccall f_4238(C_word c,C_word *av) C_noret;
C_noret_decl(f_4242)
static void C_ccall f_4242(C_word c,C_word *av) C_noret;
C_noret_decl(f_4247)
static void C_ccall f_4247(C_word c,C_word *av) C_noret;
C_noret_decl(f_4251)
static void C_ccall f_4251(C_word c,C_word *av) C_noret;
C_noret_decl(f_4256)
static void C_ccall f_4256(C_word c,C_word *av) C_noret;
C_noret_decl(f_4262)
static void C_ccall f_4262(C_word c,C_word *av) C_noret;
C_noret_decl(f_4266)
static void C_ccall f_4266(C_word c,C_word *av) C_noret;
C_noret_decl(f_4271)
static void C_ccall f_4271(C_word c,C_word *av) C_noret;
C_noret_decl(f_4275)
static void C_ccall f_4275(C_word c,C_word *av) C_noret;
C_noret_decl(f_4280)
static void C_ccall f_4280(C_word c,C_word *av) C_noret;
C_noret_decl(f_4285)
static void C_ccall f_4285(C_word c,C_word *av) C_noret;
C_noret_decl(f_4291)
static void C_ccall f_4291(C_word c,C_word *av) C_noret;
C_noret_decl(f_4295)
static void C_ccall f_4295(C_word c,C_word *av) C_noret;
C_noret_decl(f_4300)
static void C_ccall f_4300(C_word c,C_word *av) C_noret;
C_noret_decl(f_4309)
static void C_ccall f_4309(C_word c,C_word *av) C_noret;
C_noret_decl(f_4319)
static void C_ccall f_4319(C_word c,C_word *av) C_noret;
C_noret_decl(f_4322)
static void C_ccall f_4322(C_word c,C_word *av) C_noret;
C_noret_decl(f_4326)
static void C_ccall f_4326(C_word c,C_word *av) C_noret;
C_noret_decl(f_4329)
static void C_ccall f_4329(C_word c,C_word *av) C_noret;
C_noret_decl(f_4339)
static void C_ccall f_4339(C_word c,C_word *av) C_noret;
C_noret_decl(f_4345)
static void C_ccall f_4345(C_word c,C_word *av) C_noret;
C_noret_decl(f_4349)
static void C_ccall f_4349(C_word c,C_word *av) C_noret;
C_noret_decl(f_4354)
static void C_ccall f_4354(C_word c,C_word *av) C_noret;
C_noret_decl(f_4376)
static void C_ccall f_4376(C_word c,C_word *av) C_noret;
C_noret_decl(f_4380)
static void C_ccall f_4380(C_word c,C_word *av) C_noret;
C_noret_decl(f_4383)
static void C_ccall f_4383(C_word c,C_word *av) C_noret;
C_noret_decl(f_4386)
static void C_ccall f_4386(C_word c,C_word *av) C_noret;
C_noret_decl(f_4389)
static void C_ccall f_4389(C_word c,C_word *av) C_noret;
C_noret_decl(f_4392)
static void C_ccall f_4392(C_word c,C_word *av) C_noret;
C_noret_decl(f_4405)
static void C_ccall f_4405(C_word c,C_word *av) C_noret;
C_noret_decl(f_4420)
static void C_ccall f_4420(C_word c,C_word *av) C_noret;
C_noret_decl(f_4424)
static void C_ccall f_4424(C_word c,C_word *av) C_noret;
C_noret_decl(f_4427)
static void C_ccall f_4427(C_word c,C_word *av) C_noret;
C_noret_decl(f_4433)
static void C_ccall f_4433(C_word c,C_word *av) C_noret;
C_noret_decl(f_4436)
static void C_ccall f_4436(C_word c,C_word *av) C_noret;
C_noret_decl(f_4446)
static void C_ccall f_4446(C_word c,C_word *av) C_noret;
C_noret_decl(f_4461)
static void C_ccall f_4461(C_word c,C_word *av) C_noret;
C_noret_decl(f_4474)
static void C_ccall f_4474(C_word c,C_word *av) C_noret;
C_noret_decl(f_4483)
static void C_ccall f_4483(C_word c,C_word *av) C_noret;
C_noret_decl(f_4488)
static void C_fcall f_4488(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4496)
static void C_ccall f_4496(C_word c,C_word *av) C_noret;
C_noret_decl(f_4535)
static C_word C_fcall f_4535(C_word t0,C_word t1);
C_noret_decl(f_4576)
static void C_ccall f_4576(C_word c,C_word *av) C_noret;
C_noret_decl(f_4580)
static void C_ccall f_4580(C_word c,C_word *av) C_noret;
C_noret_decl(f_4589)
static C_word C_fcall f_4589(C_word t0,C_word t1);
C_noret_decl(f_4620)
static void C_ccall f_4620(C_word c,C_word *av) C_noret;
C_noret_decl(f_4627)
static void C_ccall f_4627(C_word c,C_word *av) C_noret;
C_noret_decl(f_4640)
static void C_ccall f_4640(C_word c,C_word *av) C_noret;
C_noret_decl(f_4683)
static void C_ccall f_4683(C_word c,C_word *av) C_noret;
C_noret_decl(f_4687)
static void C_ccall f_4687(C_word c,C_word *av) C_noret;
C_noret_decl(f_4690)
static void C_fcall f_4690(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4693)
static void C_ccall f_4693(C_word c,C_word *av) C_noret;
C_noret_decl(f_4703)
static void C_ccall f_4703(C_word c,C_word *av) C_noret;
C_noret_decl(f_4712)
static void C_ccall f_4712(C_word c,C_word *av) C_noret;
C_noret_decl(f_4714)
static void C_ccall f_4714(C_word c,C_word *av) C_noret;
C_noret_decl(f_4735)
static C_word C_fcall f_4735(C_word t0,C_word t1);
C_noret_decl(f_4760)
static void C_ccall f_4760(C_word c,C_word *av) C_noret;
C_noret_decl(f_4772)
static void C_ccall f_4772(C_word c,C_word *av) C_noret;
C_noret_decl(f_4799)
static void C_ccall f_4799(C_word c,C_word *av) C_noret;
C_noret_decl(f_4813)
static void C_ccall f_4813(C_word c,C_word *av) C_noret;
C_noret_decl(f_4852)
static void C_ccall f_4852(C_word c,C_word *av) C_noret;
C_noret_decl(f_4877)
static void C_ccall f_4877(C_word c,C_word *av) C_noret;
C_noret_decl(f_4882)
static void C_ccall f_4882(C_word c,C_word *av) C_noret;
C_noret_decl(f_4889)
static void C_ccall f_4889(C_word c,C_word *av) C_noret;
C_noret_decl(f_4896)
static void C_ccall f_4896(C_word c,C_word *av) C_noret;
C_noret_decl(f_4935)
static void C_fcall f_4935(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4939)
static void C_ccall f_4939(C_word c,C_word *av) C_noret;
C_noret_decl(f_4955)
static void C_ccall f_4955(C_word c,C_word *av) C_noret;
C_noret_decl(f_4963)
static void C_ccall f_4963(C_word c,C_word *av) C_noret;
C_noret_decl(f_4980)
static void C_ccall f_4980(C_word c,C_word *av) C_noret;
C_noret_decl(f_4995)
static void C_ccall f_4995(C_word c,C_word *av) C_noret;
C_noret_decl(f_4999)
static void C_ccall f_4999(C_word c,C_word *av) C_noret;
C_noret_decl(f_5063)
static void C_ccall f_5063(C_word c,C_word *av) C_noret;
C_noret_decl(f_5080)
static void C_ccall f_5080(C_word c,C_word *av) C_noret;
C_noret_decl(f_5084)
static void C_ccall f_5084(C_word c,C_word *av) C_noret;
C_noret_decl(f_5088)
static void C_ccall f_5088(C_word c,C_word *av) C_noret;
C_noret_decl(f_5104)
static void C_ccall f_5104(C_word c,C_word *av) C_noret;
C_noret_decl(f_5108)
static void C_ccall f_5108(C_word c,C_word *av) C_noret;
C_noret_decl(f_5112)
static void C_ccall f_5112(C_word c,C_word *av) C_noret;
C_noret_decl(f_5116)
static void C_ccall f_5116(C_word c,C_word *av) C_noret;
C_noret_decl(f_5120)
static void C_ccall f_5120(C_word c,C_word *av) C_noret;
C_noret_decl(f_5140)
static void C_ccall f_5140(C_word c,C_word *av) C_noret;
C_noret_decl(f_5148)
static void C_fcall f_5148(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5173)
static void C_ccall f_5173(C_word c,C_word *av) C_noret;
C_noret_decl(f_5187)
static void C_fcall f_5187(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_5189)
static void C_fcall f_5189(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5194)
static C_word C_fcall f_5194(C_word t0,C_word t1);
C_noret_decl(f_5203)
static C_word C_fcall f_5203(C_word t0,C_word t1);
C_noret_decl(f_5230)
static void C_ccall f_5230(C_word c,C_word *av) C_noret;
C_noret_decl(f_5233)
static void C_ccall f_5233(C_word c,C_word *av) C_noret;
C_noret_decl(f_5238)
static void C_ccall f_5238(C_word c,C_word *av) C_noret;
C_noret_decl(f_5244)
static void C_ccall f_5244(C_word c,C_word *av) C_noret;
C_noret_decl(f_5269)
static void C_ccall f_5269(C_word c,C_word *av) C_noret;
C_noret_decl(f_5271)
static void C_ccall f_5271(C_word c,C_word *av) C_noret;
C_noret_decl(f_5331)
static void C_ccall f_5331(C_word c,C_word *av) C_noret;
C_noret_decl(f_5403)
static void C_ccall f_5403(C_word c,C_word *av) C_noret;
C_noret_decl(f_5417)
static void C_ccall f_5417(C_word c,C_word *av) C_noret;
C_noret_decl(f_5425)
static void C_ccall f_5425(C_word c,C_word *av) C_noret;
C_noret_decl(f_5431)
static void C_ccall f_5431(C_word c,C_word *av) C_noret;
C_noret_decl(f_5437)
static void C_ccall f_5437(C_word c,C_word *av) C_noret;
C_noret_decl(f_5443)
static void C_ccall f_5443(C_word c,C_word *av) C_noret;
C_noret_decl(f_5449)
static void C_ccall f_5449(C_word c,C_word *av) C_noret;
C_noret_decl(f_5455)
static void C_ccall f_5455(C_word c,C_word *av) C_noret;
C_noret_decl(f_5461)
static void C_ccall f_5461(C_word c,C_word *av) C_noret;
C_noret_decl(f_5467)
static void C_ccall f_5467(C_word c,C_word *av) C_noret;
C_noret_decl(f_5473)
static void C_ccall f_5473(C_word c,C_word *av) C_noret;
C_noret_decl(f_5479)
static void C_ccall f_5479(C_word c,C_word *av) C_noret;
C_noret_decl(f_5485)
static void C_ccall f_5485(C_word c,C_word *av) C_noret;
C_noret_decl(f_5491)
static void C_ccall f_5491(C_word c,C_word *av) C_noret;
C_noret_decl(f_5497)
static void C_ccall f_5497(C_word c,C_word *av) C_noret;
C_noret_decl(f_5503)
static void C_ccall f_5503(C_word c,C_word *av) C_noret;
C_noret_decl(f_5509)
static void C_ccall f_5509(C_word c,C_word *av) C_noret;
C_noret_decl(f_5515)
static void C_ccall f_5515(C_word c,C_word *av) C_noret;
C_noret_decl(f_5521)
static void C_ccall f_5521(C_word c,C_word *av) C_noret;
C_noret_decl(f_5527)
static void C_ccall f_5527(C_word c,C_word *av) C_noret;
C_noret_decl(f_5533)
static void C_ccall f_5533(C_word c,C_word *av) C_noret;
C_noret_decl(f_5539)
static void C_ccall f_5539(C_word c,C_word *av) C_noret;
C_noret_decl(f_5545)
static void C_ccall f_5545(C_word c,C_word *av) C_noret;
C_noret_decl(f_5551)
static void C_ccall f_5551(C_word c,C_word *av) C_noret;
C_noret_decl(f_5557)
static void C_ccall f_5557(C_word c,C_word *av) C_noret;
C_noret_decl(f_5563)
static void C_ccall f_5563(C_word c,C_word *av) C_noret;
C_noret_decl(f_5569)
static void C_ccall f_5569(C_word c,C_word *av) C_noret;
C_noret_decl(f_5575)
static void C_ccall f_5575(C_word c,C_word *av) C_noret;
C_noret_decl(f_5581)
static void C_ccall f_5581(C_word c,C_word *av) C_noret;
C_noret_decl(f_5587)
static void C_ccall f_5587(C_word c,C_word *av) C_noret;
C_noret_decl(f_5593)
static void C_ccall f_5593(C_word c,C_word *av) C_noret;
C_noret_decl(f_5599)
static void C_ccall f_5599(C_word c,C_word *av) C_noret;
C_noret_decl(f_5605)
static void C_ccall f_5605(C_word c,C_word *av) C_noret;
C_noret_decl(f_5623)
static void C_ccall f_5623(C_word c,C_word *av) C_noret;
C_noret_decl(f_5668)
static void C_ccall f_5668(C_word c,C_word *av) C_noret;
C_noret_decl(f_5672)
static void C_ccall f_5672(C_word c,C_word *av) C_noret;
C_noret_decl(f_5677)
static void C_ccall f_5677(C_word c,C_word *av) C_noret;
C_noret_decl(f_5684)
static void C_ccall f_5684(C_word c,C_word *av) C_noret;
C_noret_decl(f_5702)
static void C_ccall f_5702(C_word c,C_word *av) C_noret;
C_noret_decl(f_5706)
static void C_ccall f_5706(C_word c,C_word *av) C_noret;
C_noret_decl(f_5708)
static void C_ccall f_5708(C_word c,C_word *av) C_noret;
C_noret_decl(f_5712)
static void C_ccall f_5712(C_word c,C_word *av) C_noret;
C_noret_decl(f_5715)
static void C_ccall f_5715(C_word c,C_word *av) C_noret;
C_noret_decl(f_5724)
static void C_ccall f_5724(C_word c,C_word *av) C_noret;
C_noret_decl(f_5745)
static void C_ccall f_5745(C_word c,C_word *av) C_noret;
C_noret_decl(f_5749)
static void C_ccall f_5749(C_word c,C_word *av) C_noret;
C_noret_decl(f_5751)
static void C_ccall f_5751(C_word c,C_word *av) C_noret;
C_noret_decl(f_5755)
static void C_ccall f_5755(C_word c,C_word *av) C_noret;
C_noret_decl(f_5757)
static void C_ccall f_5757(C_word c,C_word *av) C_noret;
C_noret_decl(f_5761)
static void C_ccall f_5761(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externexport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(va6260)
static void C_fcall va6260(C_word t0,C_word t1) C_noret;
C_noret_decl(va6268)
static void C_fcall va6268(C_word t0,C_word t1) C_noret;
C_noret_decl(va6276)
static void C_fcall va6276(C_word t0,C_word t1) C_noret;
C_noret_decl(va6278)
static void C_fcall va6278(C_word t0,C_word t1) C_noret;
C_noret_decl(va6280)
static void C_fcall va6280(C_word t0,C_word t1) C_noret;
C_noret_decl(va6282)
static void C_fcall va6282(C_word t0,C_word t1) C_noret;

C_noret_decl(trf_2447)
static void C_ccall trf_2447(C_word c,C_word *av) C_noret;
static void C_ccall trf_2447(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2447(t0,t1,t2);}

C_noret_decl(trf_2488)
static void C_ccall trf_2488(C_word c,C_word *av) C_noret;
static void C_ccall trf_2488(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2488(t0,t1,t2);}

C_noret_decl(trf_2641)
static void C_ccall trf_2641(C_word c,C_word *av) C_noret;
static void C_ccall trf_2641(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2641(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2802)
static void C_ccall trf_2802(C_word c,C_word *av) C_noret;
static void C_ccall trf_2802(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2802(t0,t1);}

C_noret_decl(trf_3119)
static void C_ccall trf_3119(C_word c,C_word *av) C_noret;
static void C_ccall trf_3119(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3119(t0,t1,t2,t3);}

C_noret_decl(trf_3156)
static void C_ccall trf_3156(C_word c,C_word *av) C_noret;
static void C_ccall trf_3156(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3156(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3255)
static void C_ccall trf_3255(C_word c,C_word *av) C_noret;
static void C_ccall trf_3255(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3255(t0,t1);}

C_noret_decl(trf_3311)
static void C_ccall trf_3311(C_word c,C_word *av) C_noret;
static void C_ccall trf_3311(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3311(t0,t1,t2);}

C_noret_decl(trf_3550)
static void C_ccall trf_3550(C_word c,C_word *av) C_noret;
static void C_ccall trf_3550(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3550(t0,t1,t2);}

C_noret_decl(trf_3588)
static void C_ccall trf_3588(C_word c,C_word *av) C_noret;
static void C_ccall trf_3588(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3588(t0,t1,t2);}

C_noret_decl(trf_3706)
static void C_ccall trf_3706(C_word c,C_word *av) C_noret;
static void C_ccall trf_3706(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3706(t0,t1,t2,t3);}

C_noret_decl(trf_3745)
static void C_ccall trf_3745(C_word c,C_word *av) C_noret;
static void C_ccall trf_3745(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3745(t0,t1);}

C_noret_decl(trf_3751)
static void C_ccall trf_3751(C_word c,C_word *av) C_noret;
static void C_ccall trf_3751(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3751(t0,t1,t2,t3);}

C_noret_decl(trf_3802)
static void C_ccall trf_3802(C_word c,C_word *av) C_noret;
static void C_ccall trf_3802(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3802(t0,t1,t2);}

C_noret_decl(trf_3823)
static void C_ccall trf_3823(C_word c,C_word *av) C_noret;
static void C_ccall trf_3823(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3823(t0,t1);}

C_noret_decl(trf_3832)
static void C_ccall trf_3832(C_word c,C_word *av) C_noret;
static void C_ccall trf_3832(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3832(t0,t1,t2);}

C_noret_decl(trf_3857)
static void C_ccall trf_3857(C_word c,C_word *av) C_noret;
static void C_ccall trf_3857(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3857(t0,t1,t2);}

C_noret_decl(trf_3906)
static void C_ccall trf_3906(C_word c,C_word *av) C_noret;
static void C_ccall trf_3906(C_word c,C_word *av){
C_word t0=av[7];
C_word t1=av[6];
C_word t2=av[5];
C_word t3=av[4];
C_word t4=av[3];
C_word t5=av[2];
C_word t6=av[1];
C_word t7=av[0];
f_3906(t0,t1,t2,t3,t4,t5,t6,t7);}

C_noret_decl(trf_3958)
static void C_ccall trf_3958(C_word c,C_word *av) C_noret;
static void C_ccall trf_3958(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3958(t0,t1);}

C_noret_decl(trf_3995)
static void C_ccall trf_3995(C_word c,C_word *av) C_noret;
static void C_ccall trf_3995(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3995(t0,t1,t2);}

C_noret_decl(trf_4060)
static void C_ccall trf_4060(C_word c,C_word *av) C_noret;
static void C_ccall trf_4060(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_4060(t0,t1,t2,t3,t4);}

C_noret_decl(trf_4488)
static void C_ccall trf_4488(C_word c,C_word *av) C_noret;
static void C_ccall trf_4488(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4488(t0,t1,t2);}

C_noret_decl(trf_4690)
static void C_ccall trf_4690(C_word c,C_word *av) C_noret;
static void C_ccall trf_4690(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4690(t0,t1);}

C_noret_decl(trf_4935)
static void C_ccall trf_4935(C_word c,C_word *av) C_noret;
static void C_ccall trf_4935(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4935(t0,t1);}

C_noret_decl(trf_5148)
static void C_ccall trf_5148(C_word c,C_word *av) C_noret;
static void C_ccall trf_5148(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5148(t0,t1,t2);}

C_noret_decl(trf_5187)
static void C_ccall trf_5187(C_word c,C_word *av) C_noret;
static void C_ccall trf_5187(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_5187(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_5189)
static void C_ccall trf_5189(C_word c,C_word *av) C_noret;
static void C_ccall trf_5189(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5189(t0,t1,t2);}

C_noret_decl(trva6260)
static void C_ccall trva6260(C_word c,C_word *av) C_noret;
static void C_ccall trva6260(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6260(t0,t1);}

C_noret_decl(trva6268)
static void C_ccall trva6268(C_word c,C_word *av) C_noret;
static void C_ccall trva6268(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6268(t0,t1);}

C_noret_decl(trva6276)
static void C_ccall trva6276(C_word c,C_word *av) C_noret;
static void C_ccall trva6276(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6276(t0,t1);}

C_noret_decl(trva6278)
static void C_ccall trva6278(C_word c,C_word *av) C_noret;
static void C_ccall trva6278(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6278(t0,t1);}

C_noret_decl(trva6280)
static void C_ccall trva6280(C_word c,C_word *av) C_noret;
static void C_ccall trva6280(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6280(t0,t1);}

C_noret_decl(trva6282)
static void C_ccall trva6282(C_word c,C_word *av) C_noret;
static void C_ccall trva6282(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va6282(t0,t1);}

/* f6287 in chicken.time.posix#seconds->local-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f6287(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f6287,c,av);}
/* posix-common.scm:585: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[260]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[260];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}

/* f6291 in chicken.time.posix#seconds->utc-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f6291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f6291,c,av);}
/* posix-common.scm:590: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[260]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[260];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
tp(4,av2);}}

/* k2292 */
static void C_ccall f_2294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2294,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2297,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k2295 in k2292 */
static void C_ccall f_2297(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2297,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2300,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k2298 in k2295 in k2292 */
static void C_ccall f_2300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2300,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2303,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2303,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2306,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lolevel_toplevel(2,av2);}}

/* k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2306,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2309,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2309(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_2309,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[2]);
t3=C_a_i_provide(&a,1,lf[3]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2312,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2312(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2312,c,av);}
a=C_alloc(88);
t2=C_set_block_item(lf[4] /* chicken.file.posix#create-fifo */,0,C_SCHEME_UNDEFINED);
t3=C_set_block_item(lf[5] /* chicken.file.posix#create-symbolic-link */,0,C_SCHEME_UNDEFINED);
t4=C_set_block_item(lf[6] /* chicken.file.posix#read-symbolic-link */,0,C_SCHEME_UNDEFINED);
t5=C_set_block_item(lf[7] /* chicken.file.posix#duplicate-fileno */,0,C_SCHEME_UNDEFINED);
t6=C_set_block_item(lf[8] /* chicken.file.posix#fcntl/dupfd */,0,C_SCHEME_UNDEFINED);
t7=C_set_block_item(lf[9] /* chicken.file.posix#fcntl/getfd */,0,C_SCHEME_UNDEFINED);
t8=C_set_block_item(lf[10] /* chicken.file.posix#fcntl/getfl */,0,C_SCHEME_UNDEFINED);
t9=C_set_block_item(lf[11] /* chicken.file.posix#fcntl/setfd */,0,C_SCHEME_UNDEFINED);
t10=C_set_block_item(lf[12] /* chicken.file.posix#fcntl/setfl */,0,C_SCHEME_UNDEFINED);
t11=C_set_block_item(lf[13] /* chicken.file.posix#file-close */,0,C_SCHEME_UNDEFINED);
t12=C_set_block_item(lf[14] /* chicken.file.posix#file-control */,0,C_SCHEME_UNDEFINED);
t13=C_set_block_item(lf[15] /* chicken.file.posix#file-creation-mode */,0,C_SCHEME_UNDEFINED);
t14=C_set_block_item(lf[16] /* chicken.file.posix#file-group */,0,C_SCHEME_UNDEFINED);
t15=C_set_block_item(lf[17] /* chicken.file.posix#file-link */,0,C_SCHEME_UNDEFINED);
t16=C_set_block_item(lf[18] /* chicken.file.posix#file-lock */,0,C_SCHEME_UNDEFINED);
t17=C_set_block_item(lf[19] /* chicken.file.posix#file-lock/blocking */,0,C_SCHEME_UNDEFINED);
t18=C_set_block_item(lf[20] /* chicken.file.posix#file-mkstemp */,0,C_SCHEME_UNDEFINED);
t19=C_set_block_item(lf[21] /* chicken.file.posix#file-open */,0,C_SCHEME_UNDEFINED);
t20=C_set_block_item(lf[22] /* chicken.file.posix#file-owner */,0,C_SCHEME_UNDEFINED);
t21=C_set_block_item(lf[23] /* chicken.file.posix#file-permissions */,0,C_SCHEME_UNDEFINED);
t22=C_set_block_item(lf[24] /* chicken.file.posix#file-position */,0,C_SCHEME_UNDEFINED);
t23=C_set_block_item(lf[25] /* chicken.file.posix#file-read */,0,C_SCHEME_UNDEFINED);
t24=C_set_block_item(lf[26] /* chicken.file.posix#file-select */,0,C_SCHEME_UNDEFINED);
t25=C_set_block_item(lf[27] /* chicken.file.posix#file-test-lock */,0,C_SCHEME_UNDEFINED);
t26=C_set_block_item(lf[28] /* chicken.file.posix#file-truncate */,0,C_SCHEME_UNDEFINED);
t27=C_set_block_item(lf[29] /* chicken.file.posix#file-unlock */,0,C_SCHEME_UNDEFINED);
t28=C_set_block_item(lf[30] /* chicken.file.posix#file-write */,0,C_SCHEME_UNDEFINED);
t29=C_set_block_item(lf[31] /* chicken.file.posix#file-type */,0,C_SCHEME_UNDEFINED);
t30=C_set_block_item(lf[32] /* chicken.file.posix#block-device? */,0,C_SCHEME_UNDEFINED);
t31=C_set_block_item(lf[33] /* chicken.file.posix#character-device? */,0,C_SCHEME_UNDEFINED);
t32=C_set_block_item(lf[34] /* chicken.file.posix#directory? */,0,C_SCHEME_UNDEFINED);
t33=C_set_block_item(lf[35] /* chicken.file.posix#fifo? */,0,C_SCHEME_UNDEFINED);
t34=C_set_block_item(lf[36] /* chicken.file.posix#regular-file? */,0,C_SCHEME_UNDEFINED);
t35=C_set_block_item(lf[37] /* chicken.file.posix#socket? */,0,C_SCHEME_UNDEFINED);
t36=C_set_block_item(lf[38] /* chicken.file.posix#symbolic-link? */,0,C_SCHEME_UNDEFINED);
t37=C_set_block_item(lf[39] /* chicken.file.posix#fileno/stderr */,0,C_SCHEME_UNDEFINED);
t38=C_set_block_item(lf[40] /* chicken.file.posix#fileno/stdin */,0,C_SCHEME_UNDEFINED);
t39=C_set_block_item(lf[41] /* chicken.file.posix#fileno/stdout */,0,C_SCHEME_UNDEFINED);
t40=C_set_block_item(lf[42] /* chicken.file.posix#open-input-file* */,0,C_SCHEME_UNDEFINED);
t41=C_set_block_item(lf[43] /* chicken.file.posix#open-output-file* */,0,C_SCHEME_UNDEFINED);
t42=C_set_block_item(lf[44] /* chicken.file.posix#open/append */,0,C_SCHEME_UNDEFINED);
t43=C_set_block_item(lf[45] /* chicken.file.posix#open/binary */,0,C_SCHEME_UNDEFINED);
t44=C_set_block_item(lf[46] /* chicken.file.posix#open/creat */,0,C_SCHEME_UNDEFINED);
t45=C_set_block_item(lf[47] /* chicken.file.posix#open/excl */,0,C_SCHEME_UNDEFINED);
t46=C_set_block_item(lf[48] /* chicken.file.posix#open/fsync */,0,C_SCHEME_UNDEFINED);
t47=C_set_block_item(lf[49] /* chicken.file.posix#open/noctty */,0,C_SCHEME_UNDEFINED);
t48=C_set_block_item(lf[50] /* chicken.file.posix#open/noinherit */,0,C_SCHEME_UNDEFINED);
t49=C_set_block_item(lf[51] /* chicken.file.posix#open/nonblock */,0,C_SCHEME_UNDEFINED);
t50=C_set_block_item(lf[52] /* chicken.file.posix#open/rdonly */,0,C_SCHEME_UNDEFINED);
t51=C_set_block_item(lf[53] /* chicken.file.posix#open/rdwr */,0,C_SCHEME_UNDEFINED);
t52=C_set_block_item(lf[54] /* chicken.file.posix#open/read */,0,C_SCHEME_UNDEFINED);
t53=C_set_block_item(lf[55] /* chicken.file.posix#open/sync */,0,C_SCHEME_UNDEFINED);
t54=C_set_block_item(lf[56] /* chicken.file.posix#open/text */,0,C_SCHEME_UNDEFINED);
t55=C_set_block_item(lf[57] /* chicken.file.posix#open/trunc */,0,C_SCHEME_UNDEFINED);
t56=C_set_block_item(lf[58] /* chicken.file.posix#open/write */,0,C_SCHEME_UNDEFINED);
t57=C_set_block_item(lf[59] /* chicken.file.posix#open/wronly */,0,C_SCHEME_UNDEFINED);
t58=C_set_block_item(lf[60] /* chicken.file.posix#perm/irgrp */,0,C_SCHEME_UNDEFINED);
t59=C_set_block_item(lf[61] /* chicken.file.posix#perm/iroth */,0,C_SCHEME_UNDEFINED);
t60=C_set_block_item(lf[62] /* chicken.file.posix#perm/irusr */,0,C_SCHEME_UNDEFINED);
t61=C_set_block_item(lf[63] /* chicken.file.posix#perm/irwxg */,0,C_SCHEME_UNDEFINED);
t62=C_set_block_item(lf[64] /* chicken.file.posix#perm/irwxo */,0,C_SCHEME_UNDEFINED);
t63=C_set_block_item(lf[65] /* chicken.file.posix#perm/irwxu */,0,C_SCHEME_UNDEFINED);
t64=C_set_block_item(lf[66] /* chicken.file.posix#perm/isgid */,0,C_SCHEME_UNDEFINED);
t65=C_set_block_item(lf[67] /* chicken.file.posix#perm/isuid */,0,C_SCHEME_UNDEFINED);
t66=C_set_block_item(lf[68] /* chicken.file.posix#perm/isvtx */,0,C_SCHEME_UNDEFINED);
t67=C_set_block_item(lf[69] /* chicken.file.posix#perm/iwgrp */,0,C_SCHEME_UNDEFINED);
t68=C_set_block_item(lf[70] /* chicken.file.posix#perm/iwoth */,0,C_SCHEME_UNDEFINED);
t69=C_set_block_item(lf[71] /* chicken.file.posix#perm/iwusr */,0,C_SCHEME_UNDEFINED);
t70=C_set_block_item(lf[72] /* chicken.file.posix#perm/ixgrp */,0,C_SCHEME_UNDEFINED);
t71=C_set_block_item(lf[73] /* chicken.file.posix#perm/ixoth */,0,C_SCHEME_UNDEFINED);
t72=C_set_block_item(lf[74] /* chicken.file.posix#perm/ixusr */,0,C_SCHEME_UNDEFINED);
t73=C_set_block_item(lf[75] /* chicken.file.posix#port->fileno */,0,C_SCHEME_UNDEFINED);
t74=C_set_block_item(lf[76] /* chicken.file.posix#seek/cur */,0,C_SCHEME_UNDEFINED);
t75=C_set_block_item(lf[77] /* chicken.file.posix#seek/end */,0,C_SCHEME_UNDEFINED);
t76=C_set_block_item(lf[78] /* chicken.file.posix#seek/set */,0,C_SCHEME_UNDEFINED);
t77=C_set_block_item(lf[79] /* chicken.file.posix#set-file-position! */,0,C_SCHEME_UNDEFINED);
t78=C_a_i_provide(&a,1,lf[80]);
t79=C_set_block_item(lf[81] /* chicken.time.posix#seconds->utc-time */,0,C_SCHEME_UNDEFINED);
t80=C_set_block_item(lf[82] /* chicken.time.posix#utc-time->seconds */,0,C_SCHEME_UNDEFINED);
t81=C_set_block_item(lf[83] /* chicken.time.posix#seconds->local-time */,0,C_SCHEME_UNDEFINED);
t82=C_set_block_item(lf[84] /* chicken.time.posix#seconds->string */,0,C_SCHEME_UNDEFINED);
t83=C_set_block_item(lf[85] /* chicken.time.posix#local-time->seconds */,0,C_SCHEME_UNDEFINED);
t84=C_set_block_item(lf[86] /* chicken.time.posix#string->time */,0,C_SCHEME_UNDEFINED);
t85=C_set_block_item(lf[87] /* chicken.time.posix#time->string */,0,C_SCHEME_UNDEFINED);
t86=C_set_block_item(lf[88] /* chicken.time.posix#local-timezone-abbreviation */,0,C_SCHEME_UNDEFINED);
t87=C_a_i_provide(&a,1,lf[89]);
t88=C_mutate((C_word*)lf[90]+1 /* (set! chicken.process#system ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2398,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t89=C_mutate((C_word*)lf[96]+1 /* (set! chicken.process#system* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2417,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t90=C_mutate((C_word*)lf[99]+1 /* (set! chicken.process#qs ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2433,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t91=C_set_block_item(lf[109] /* chicken.process#process-execute */,0,C_SCHEME_UNDEFINED);
t92=C_set_block_item(lf[110] /* chicken.process#process-fork */,0,C_SCHEME_UNDEFINED);
t93=C_set_block_item(lf[111] /* chicken.process#process-run */,0,C_SCHEME_UNDEFINED);
t94=C_set_block_item(lf[112] /* chicken.process#process-signal */,0,C_SCHEME_UNDEFINED);
t95=C_set_block_item(lf[113] /* chicken.process#process-spawn */,0,C_SCHEME_UNDEFINED);
t96=C_set_block_item(lf[114] /* chicken.process#process-wait */,0,C_SCHEME_UNDEFINED);
t97=C_set_block_item(lf[115] /* chicken.process#call-with-input-pipe */,0,C_SCHEME_UNDEFINED);
t98=C_set_block_item(lf[116] /* chicken.process#call-with-output-pipe */,0,C_SCHEME_UNDEFINED);
t99=C_set_block_item(lf[117] /* chicken.process#close-input-pipe */,0,C_SCHEME_UNDEFINED);
t100=C_set_block_item(lf[118] /* chicken.process#close-output-pipe */,0,C_SCHEME_UNDEFINED);
t101=C_set_block_item(lf[119] /* chicken.process#create-pipe */,0,C_SCHEME_UNDEFINED);
t102=C_set_block_item(lf[120] /* chicken.process#open-input-pipe */,0,C_SCHEME_UNDEFINED);
t103=C_set_block_item(lf[121] /* chicken.process#open-output-pipe */,0,C_SCHEME_UNDEFINED);
t104=C_set_block_item(lf[122] /* chicken.process#with-input-from-pipe */,0,C_SCHEME_UNDEFINED);
t105=C_set_block_item(lf[123] /* chicken.process#with-output-to-pipe */,0,C_SCHEME_UNDEFINED);
t106=C_set_block_item(lf[124] /* chicken.process#process */,0,C_SCHEME_UNDEFINED);
t107=C_set_block_item(lf[125] /* chicken.process#process* */,0,C_SCHEME_UNDEFINED);
t108=C_set_block_item(lf[126] /* chicken.process#process-sleep */,0,C_SCHEME_UNDEFINED);
t109=C_set_block_item(lf[127] /* chicken.process#pipe/buf */,0,C_SCHEME_UNDEFINED);
t110=C_set_block_item(lf[128] /* chicken.process#spawn/overlay */,0,C_SCHEME_UNDEFINED);
t111=C_set_block_item(lf[129] /* chicken.process#spawn/wait */,0,C_SCHEME_UNDEFINED);
t112=C_set_block_item(lf[130] /* chicken.process#spawn/nowait */,0,C_SCHEME_UNDEFINED);
t113=C_set_block_item(lf[131] /* chicken.process#spawn/nowaito */,0,C_SCHEME_UNDEFINED);
t114=C_set_block_item(lf[132] /* chicken.process#spawn/detach */,0,C_SCHEME_UNDEFINED);
t115=C_a_i_provide(&a,1,lf[133]);
t116=C_set_block_item(lf[134] /* chicken.process.signal#set-alarm! */,0,C_SCHEME_UNDEFINED);
t117=C_set_block_item(lf[135] /* chicken.process.signal#set-signal-handler! */,0,C_SCHEME_UNDEFINED);
t118=C_set_block_item(lf[136] /* chicken.process.signal#set-signal-mask! */,0,C_SCHEME_UNDEFINED);
t119=C_set_block_item(lf[137] /* chicken.process.signal#signal-handler */,0,C_SCHEME_UNDEFINED);
t120=C_set_block_item(lf[138] /* chicken.process.signal#make-signal-handler */,0,C_SCHEME_UNDEFINED);
t121=C_set_block_item(lf[139] /* chicken.process.signal#signal-ignore */,0,C_SCHEME_UNDEFINED);
t122=C_set_block_item(lf[140] /* chicken.process.signal#signal-default */,0,C_SCHEME_UNDEFINED);
t123=C_set_block_item(lf[141] /* chicken.process.signal#signal-mask */,0,C_SCHEME_UNDEFINED);
t124=C_set_block_item(lf[142] /* chicken.process.signal#signal-mask! */,0,C_SCHEME_UNDEFINED);
t125=C_set_block_item(lf[143] /* chicken.process.signal#signal-masked? */,0,C_SCHEME_UNDEFINED);
t126=C_set_block_item(lf[144] /* chicken.process.signal#signal-unmask! */,0,C_SCHEME_UNDEFINED);
t127=C_set_block_item(lf[145] /* chicken.process.signal#signal/abrt */,0,C_SCHEME_UNDEFINED);
t128=C_set_block_item(lf[146] /* chicken.process.signal#signal/alrm */,0,C_SCHEME_UNDEFINED);
t129=C_set_block_item(lf[147] /* chicken.process.signal#signal/break */,0,C_SCHEME_UNDEFINED);
t130=C_set_block_item(lf[148] /* chicken.process.signal#signal/bus */,0,C_SCHEME_UNDEFINED);
t131=C_set_block_item(lf[149] /* chicken.process.signal#signal/chld */,0,C_SCHEME_UNDEFINED);
t132=C_set_block_item(lf[150] /* chicken.process.signal#signal/cont */,0,C_SCHEME_UNDEFINED);
t133=C_set_block_item(lf[151] /* chicken.process.signal#signal/fpe */,0,C_SCHEME_UNDEFINED);
t134=C_set_block_item(lf[152] /* chicken.process.signal#signal/hup */,0,C_SCHEME_UNDEFINED);
t135=C_set_block_item(lf[153] /* chicken.process.signal#signal/ill */,0,C_SCHEME_UNDEFINED);
t136=C_set_block_item(lf[154] /* chicken.process.signal#signal/int */,0,C_SCHEME_UNDEFINED);
t137=C_set_block_item(lf[155] /* chicken.process.signal#signal/io */,0,C_SCHEME_UNDEFINED);
t138=C_set_block_item(lf[156] /* chicken.process.signal#signal/kill */,0,C_SCHEME_UNDEFINED);
t139=C_set_block_item(lf[157] /* chicken.process.signal#signal/pipe */,0,C_SCHEME_UNDEFINED);
t140=C_set_block_item(lf[158] /* chicken.process.signal#signal/prof */,0,C_SCHEME_UNDEFINED);
t141=C_set_block_item(lf[159] /* chicken.process.signal#signal/quit */,0,C_SCHEME_UNDEFINED);
t142=C_set_block_item(lf[160] /* chicken.process.signal#signal/segv */,0,C_SCHEME_UNDEFINED);
t143=C_set_block_item(lf[161] /* chicken.process.signal#signal/stop */,0,C_SCHEME_UNDEFINED);
t144=C_set_block_item(lf[162] /* chicken.process.signal#signal/term */,0,C_SCHEME_UNDEFINED);
t145=C_set_block_item(lf[163] /* chicken.process.signal#signal/trap */,0,C_SCHEME_UNDEFINED);
t146=C_set_block_item(lf[164] /* chicken.process.signal#signal/tstp */,0,C_SCHEME_UNDEFINED);
t147=C_set_block_item(lf[165] /* chicken.process.signal#signal/urg */,0,C_SCHEME_UNDEFINED);
t148=C_set_block_item(lf[166] /* chicken.process.signal#signal/usr1 */,0,C_SCHEME_UNDEFINED);
t149=C_set_block_item(lf[167] /* chicken.process.signal#signal/usr2 */,0,C_SCHEME_UNDEFINED);
t150=C_set_block_item(lf[168] /* chicken.process.signal#signal/vtalrm */,0,C_SCHEME_UNDEFINED);
t151=C_set_block_item(lf[169] /* chicken.process.signal#signal/winch */,0,C_SCHEME_UNDEFINED);
t152=C_set_block_item(lf[170] /* chicken.process.signal#signal/xcpu */,0,C_SCHEME_UNDEFINED);
t153=C_set_block_item(lf[171] /* chicken.process.signal#signal/xfsz */,0,C_SCHEME_UNDEFINED);
t154=C_set_block_item(lf[172] /* chicken.process.signal#signals-list */,0,C_SCHEME_UNDEFINED);
t155=C_a_i_provide(&a,1,lf[173]);
t156=C_set_block_item(lf[174] /* chicken.process-context.posix#change-directory* */,0,C_SCHEME_UNDEFINED);
t157=C_set_block_item(lf[175] /* chicken.process-context.posix#set-root-directory! */,0,C_SCHEME_UNDEFINED);
t158=C_set_block_item(lf[176] /* chicken.process-context.posix#current-effective-group-id */,0,C_SCHEME_UNDEFINED);
t159=C_set_block_item(lf[177] /* chicken.process-context.posix#current-effective-user-id */,0,C_SCHEME_UNDEFINED);
t160=C_set_block_item(lf[178] /* chicken.process-context.posix#current-group-id */,0,C_SCHEME_UNDEFINED);
t161=C_set_block_item(lf[179] /* chicken.process-context.posix#current-user-id */,0,C_SCHEME_UNDEFINED);
t162=C_set_block_item(lf[180] /* chicken.process-context.posix#current-process-id */,0,C_SCHEME_UNDEFINED);
t163=C_set_block_item(lf[181] /* chicken.process-context.posix#parent-process-id */,0,C_SCHEME_UNDEFINED);
t164=C_set_block_item(lf[182] /* chicken.process-context.posix#current-user-name */,0,C_SCHEME_UNDEFINED);
t165=C_set_block_item(lf[183] /* chicken.process-context.posix#current-effective-user-name */,0,C_SCHEME_UNDEFINED);
t166=C_set_block_item(lf[184] /* chicken.process-context.posix#create-session */,0,C_SCHEME_UNDEFINED);
t167=C_set_block_item(lf[185] /* chicken.process-context.posix#process-group-id */,0,C_SCHEME_UNDEFINED);
t168=C_set_block_item(lf[186] /* chicken.process-context.posix#user-information */,0,C_SCHEME_UNDEFINED);
t169=C_a_i_provide(&a,1,lf[187]);
t170=C_mutate(&lf[188] /* (set! chicken.posix#posix-error ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2623,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t171=C_mutate((C_word*)lf[191]+1 /* (set! ##sys#posix-error ...) */,lf[188]);
t172=C_mutate(&lf[192] /* (set! chicken.posix#stat ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2641,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t173=C_mutate((C_word*)lf[200]+1 /* (set! chicken.file.posix#file-stat ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2687,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t174=C_mutate((C_word*)lf[202]+1 /* (set! chicken.file.posix#set-file-permissions! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2705,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t175=C_mutate((C_word*)lf[208]+1 /* (set! chicken.file.posix#file-modification-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2749,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t176=C_mutate((C_word*)lf[210]+1 /* (set! chicken.file.posix#file-access-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2755,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t177=C_mutate((C_word*)lf[212]+1 /* (set! chicken.file.posix#file-change-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2761,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t178=C_mutate((C_word*)lf[214]+1 /* (set! chicken.file.posix#set-file-times! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2767,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t179=C_mutate((C_word*)lf[219]+1 /* (set! chicken.file.posix#file-size ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2846,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t180=C_mutate((C_word*)lf[221]+1 /* (set! chicken.file.posix#set-file-owner! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2852,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t181=C_mutate((C_word*)lf[224]+1 /* (set! chicken.file.posix#set-file-group! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2858,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t182=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2866,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t183=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5757,a[2]=((C_word)li174),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:313: chicken.base#getter-with-setter */
t184=*((C_word*)lf[406]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t184;
av2[1]=t182;
av2[2]=t183;
av2[3]=*((C_word*)lf[221]+1);
av2[4]=lf[418];
((C_proc)(void*)(*((C_word*)t184+1)))(5,av2);}}

/* chicken.process#system in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2398(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2398,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[91]);
t4=C_execute_shell_command(t2);
if(C_truep(C_fixnum_lessp(t4,C_fix(0)))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2415,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix.scm:203: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k2413 in chicken.process#system in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2415,c,av);}
/* posix.scm:202: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[93];
av2[3]=t1;
av2[4]=lf[91];
av2[5]=lf[94];
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}

/* chicken.process#system* in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2417,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2421,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix.scm:209: system */
t4=*((C_word*)lf[90]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k2419 in chicken.process#system* in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2421,c,av);}
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
t3=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[98];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2433,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2437,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_rest_nullp(c,3))){
/* posix.scm:216: chicken.platform#software-version */
t4=*((C_word*)lf[108]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_get_rest_arg(c,3,av,3,t0);
f_2437(2,av2);}}}

/* k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2437(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2437,c,av);}
a=C_alloc(18);
t2=C_eqp(t1,lf[100]);
t3=(C_truep(t2)?C_make_character(34):C_make_character(39));
t4=C_eqp(t1,lf[100]);
t5=(C_truep(t4)?lf[101]:lf[102]);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2447,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=((C_word)li2),tmp=(C_word)a,a+=6,tmp);
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2468,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t8,a[5]=t10,a[6]=t9,tmp=(C_word)a,a+=7,tmp);
/* ##sys#string->list */
t12=*((C_word*)lf[107]+1);{
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

/* g260 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_2447(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,0,4)))){
C_save_and_reclaim_args((void *)trf_2447,3,t0,t1,t2);}
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
t3=*((C_word*)lf[103]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[104];
av2[3]=lf[105];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_a_i_string(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* k2466 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2468(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2468,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2471,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2488,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li3),tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_2488(t6,t2,t1);}

/* k2469 in k2466 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2471,c,av);}
a=C_alloc(7);
t2=C_a_i_string(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2482,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[106]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* k2480 in k2469 in k2466 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_2482,c,av);}
a=C_alloc(2);
t2=C_a_i_string(&a,1,((C_word*)t0)[2]);
/* posix.scm:227: scheme#string-append */
t3=*((C_word*)lf[106]+1);{
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

/* map-loop254 in k2466 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_2488(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2488,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2513,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posix.scm:220: g260 */
t4=((C_word*)t0)[4];
f_2447(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2511 in map-loop254 in k2466 in k2435 in chicken.process#qs in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2513,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_2488(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* chicken.posix#posix-error in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2623(C_word c,C_word *av){
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
C_save_and_reclaim((void*)f_2623,c,av);}
a=C_alloc((c-5)*C_SIZEOF_PAIR+7);
t5=C_build_rest(&a,c,5,av);
C_word t6;
C_word t7;
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2627,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t5,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:191: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t6;
tp(2,av2);}}

/* k2625 in chicken.posix#posix-error in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2627(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2627,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2634,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2638,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t1);
/* posix-common.scm:188: ##sys#peek-c-string */
t6=*((C_word*)lf[190]+1);{
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

/* k2632 in k2625 in chicken.posix#posix-error in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_2634,c,av);}{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[92]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=t1;
av2[7]=((C_word*)t0)[6];
C_apply(8,av2);}}

/* k2636 in k2625 in chicken.posix#posix-error in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2638,c,av);}
/* posix-common.scm:193: string-append */
t2=*((C_word*)lf[106]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[189];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.posix#stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_2641(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_2641,5,t1,t2,t3,t4,t5);}
a=C_alloc(12);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2645,a[2]=t4,a[3]=t1,a[4]=t5,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnump(t2))){
t7=t6;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_u_i_fstat(t2);
f_2645(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2666,a[2]=t6,a[3]=t2,a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:236: chicken.base#port? */
t8=*((C_word*)lf[199]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}

/* k2643 in chicken.posix#stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2645,c,av);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
if(C_truep(((C_word*)t0)[2])){
/* posix-common.scm:247: posix-error */
t2=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[193];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[194];
av2[5]=((C_word*)t0)[5];
f_2623(6,av2);}}
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

/* k2664 in chicken.posix#stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_2666,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2670,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:236: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[75]+1);{
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
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2679,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:238: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}
else{
/* posix-common.scm:243: ##sys#signal-hook */
t2=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[197];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[198];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k2668 in k2664 in chicken.posix#stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2670,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_u_i_fstat(t1);
f_2645(2,av2);}}

/* k2677 in k2664 in chicken.posix#stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2679,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(((C_word*)t0)[3])?C_u_i_lstat(t1):C_u_i_stat(t1));
f_2645(2,av2);}}

/* chicken.file.posix#file-stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2687(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2687,c,av);}
a=C_alloc(3);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2694,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:253: stat */
f_2641(t5,t2,t4,C_SCHEME_TRUE,lf[201]);}

/* k2692 in chicken.file.posix#file-stat in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_2694,c,av);}
a=C_alloc(42);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_vector(&a,13,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_ino),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_mode),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_nlink),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_uid),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_gid),C_int64_to_num(&a,C_statbuf.st_size),C_int64_to_num(&a,C_statbuf.st_atime),C_int64_to_num(&a,C_statbuf.st_ctime),C_int64_to_num(&a,C_statbuf.st_mtime),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_dev),C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_rdev),((C_word)C_SCHEME_UNDEFINED),((C_word)C_SCHEME_UNDEFINED));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2705(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2705,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2709,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:262: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[203];
tp(4,av2);}}

/* k2707 in chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2709,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2712,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnump(((C_word*)t0)[3]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_fchmod(((C_word*)t0)[3],((C_word*)t0)[4]);
f_2712(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2730,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:264: chicken.base#port? */
t4=*((C_word*)lf[199]+1);{
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

/* k2710 in k2707 in chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2712,c,av);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
/* posix-common.scm:273: posix-error */
t2=lf[188];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=lf[203];
av2[4]=lf[204];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
f_2623(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2728 in k2707 in chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_2730,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2734,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:264: chicken.file.posix#port->fileno */
t3=*((C_word*)lf[75]+1);{
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
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2744,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:267: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[203];
tp(4,av2);}}
else{
/* posix-common.scm:269: ##sys#signal-hook */
t2=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[197];
av2[3]=lf[205];
av2[4]=lf[206];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k2732 in k2728 in k2707 in chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2734,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fchmod(t1,((C_word*)t0)[3]);
f_2712(2,av2);}}

/* k2742 in k2728 in k2707 in chicken.file.posix#set-file-permissions! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2744,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_chmod(t1,((C_word*)t0)[3]);
f_2712(2,av2);}}

/* chicken.file.posix#file-modification-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2749,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2753,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:277: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[209]);}

/* k2751 in chicken.file.posix#file-modification-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2753,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_mtime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-access-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2755,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2759,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:281: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[211]);}

/* k2757 in chicken.file.posix#file-access-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2759,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_atime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#file-change-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2761,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2765,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:285: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[213]);}

/* k2763 in chicken.file.posix#file-change-time in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2765,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_ctime);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_2767,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2771,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* posix-common.scm:290: chicken.time#current-seconds */
t5=*((C_word*)lf[218]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_car(t3);
f_2771(2,av2);}}}

/* k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2771(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2771,c,av);}
a=C_alloc(7);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?t1:C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2783,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t1)){
/* posix-common.scm:291: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t8;
av2[2]=t1;
av2[3]=lf[215];
tp(4,av2);}}
else{
t9=t8;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
f_2783(2,av2);}}}

/* k2781 in k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2783,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2786,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[6])){
/* posix-common.scm:292: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[215];
tp(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2786(2,av2);}}}

/* k2784 in k2781 in k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2786,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2802,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2792,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
/* posix-common.scm:293: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t3;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[3]);
tp(3,av2);}}
else{
t4=t2;
f_2802(t4,stub729(C_SCHEME_UNDEFINED,C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6]));}}

/* k2790 in k2784 in k2781 in k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2792,c,av);}
t2=((C_word*)t0)[2];
f_2802(t2,stub729(C_SCHEME_UNDEFINED,t1,((C_word*)t0)[3],((C_word*)t0)[4]));}

/* k2800 in k2784 in k2781 in k2769 in chicken.file.posix#set-file-times! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_2802(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_2802,2,t0,t1);}
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){{
C_word av2[8];
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[188];
av2[3]=lf[193];
av2[4]=lf[215];
av2[5]=lf[216];
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

/* chicken.file.posix#file-size in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2846,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2850,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:302: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[220]);}

/* k2848 in chicken.file.posix#file-size in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2850,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_int64_to_num(&a,C_statbuf.st_size);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-owner! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2852,c,av);}
a=C_alloc(12);
t4=C_a_i_list(&a,4,lf[222],t2,t3,C_fix(-1));
/* posixwin.scm:874: chicken.base#error */
t5=*((C_word*)lf[103]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[223];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* chicken.file.posix#set-file-group! in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2858,c,av);}
a=C_alloc(12);
t4=C_a_i_list(&a,4,lf[225],t2,C_fix(-1),t3);
/* posixwin.scm:874: chicken.base#error */
t5=*((C_word*)lf[103]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[223];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2866,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[22]+1 /* (set! chicken.file.posix#file-owner ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2870,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5751,a[2]=((C_word)li173),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:319: chicken.base#getter-with-setter */
t5=*((C_word*)lf[406]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[224]+1);
av2[4]=lf[416];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2870,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[16]+1 /* (set! chicken.file.posix#file-group ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2874,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5745,a[2]=((C_word)li172),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:325: chicken.base#getter-with-setter */
t5=*((C_word*)lf[406]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[202]+1);
av2[4]=lf[414];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2874(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2874,c,av);}
a=C_alloc(33);
t2=C_mutate((C_word*)lf[23]+1 /* (set! chicken.file.posix#file-permissions ...) */,t1);
t3=C_mutate((C_word*)lf[31]+1 /* (set! chicken.file.posix#file-type ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2876,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[36]+1 /* (set! chicken.file.posix#regular-file? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2963,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[38]+1 /* (set! chicken.file.posix#symbolic-link? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2973,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[32]+1 /* (set! chicken.file.posix#block-device? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2983,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[33]+1 /* (set! chicken.file.posix#character-device? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2993,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[35]+1 /* (set! chicken.file.posix#fifo? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3003,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[37]+1 /* (set! chicken.file.posix#socket? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3013,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[34]+1 /* (set! chicken.file.posix#directory? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3023,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp));
t11=C_set_block_item(lf[78] /* chicken.file.posix#seek/set */,0,C_fix((C_word)SEEK_SET));
t12=C_set_block_item(lf[77] /* chicken.file.posix#seek/end */,0,C_fix((C_word)SEEK_END));
t13=C_set_block_item(lf[76] /* chicken.file.posix#seek/cur */,0,C_fix((C_word)SEEK_CUR));
t14=C_mutate((C_word*)lf[79]+1 /* (set! chicken.file.posix#set-file-position! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3036,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3091,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t16=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5708,a[2]=((C_word)li171),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:402: chicken.base#getter-with-setter */
t17=*((C_word*)lf[406]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t17;
av2[1]=t15;
av2[2]=t16;
av2[3]=*((C_word*)lf[79]+1);
av2[4]=lf[413];
((C_proc)(void*)(*((C_word*)t17+1)))(5,av2);}}

/* chicken.file.posix#file-type in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2876(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2876,c,av);}
a=C_alloc(3);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_TRUE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2895,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:334: stat */
f_2641(t9,t2,t4,t7,lf[233]);}

/* k2893 in chicken.file.posix#file-type in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2895(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2895,c,av);}
if(C_truep(t1)){
t2=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_stat_type);
t3=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFREG));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=lf[226];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFLNK));
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[227];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFDIR));
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=lf[228];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFCHR));
if(C_truep(t6)){
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[229];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFBLK));
if(C_truep(t7)){
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=lf[230];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFIFO));
if(C_truep(t8)){
t9=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t9;
av2[1]=lf[231];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_eqp(t2,C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)S_IFSOCK));
t10=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t10;
av2[1]=(C_truep(t9)?lf[232]:lf[226]);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}}}}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file.posix#regular-file? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2963,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2971,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:348: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k2969 in chicken.file.posix#regular-file? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2971,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[226],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#symbolic-link? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2973,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2981,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:352: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k2979 in chicken.file.posix#symbolic-link? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2981,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[227],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#block-device? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2983,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2991,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:356: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k2989 in chicken.file.posix#block-device? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2991,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[230],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#character-device? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_2993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2993,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3001,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:360: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k2999 in chicken.file.posix#character-device? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3001,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[229],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#fifo? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3003,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3011,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:364: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k3009 in chicken.file.posix#fifo? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3011,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[231],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#socket? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3013,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3021,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:368: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k3019 in chicken.file.posix#socket? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3021,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[232],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#directory? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3023(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3023,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3031,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:372: chicken.file.posix#file-type */
t4=*((C_word*)lf[31]+1);{
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

/* k3029 in chicken.file.posix#directory? in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3031,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(lf[228],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file.posix#set-file-position! in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3036(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_3036,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_get_rest_arg(c,4,av,4,t0):C_fix((C_word)SEEK_SET));
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3043,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:388: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t7;
av2[2]=t3;
av2[3]=lf[234];
tp(4,av2);}}

/* k3041 in chicken.file.posix#set-file-position! in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3043(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3043,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3046,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:389: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[234];
tp(4,av2);}}

/* k3044 in k3041 in chicken.file.posix#set-file-position! in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3046,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3052,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3058,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:390: chicken.base#port? */
t4=*((C_word*)lf[199]+1);{
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

/* k3050 in k3044 in k3041 in chicken.file.posix#set-file-position! in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_3052,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* posix-common.scm:399: posix-error */
t2=lf[188];{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=lf[234];
av2[4]=lf[235];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
f_2623(7,av2);}}}

/* k3056 in k3044 in k3041 in chicken.file.posix#set-file-position! in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3058(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3058,c,av);}
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(7));
t3=C_eqp(t2,lf[236]);
if(C_truep(t3)){
t4=C_fseek(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
if(C_truep(t4)){
t5=C_i_set_i_slot(((C_word*)t0)[2],C_fix(6),C_SCHEME_FALSE);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t4;
f_3052(2,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_3052(2,av2);}}}
else{
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_3052(2,av2);}}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_lseek(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
f_3052(2,av2);}}
else{
/* posix-common.scm:398: ##sys#signal-hook */
t2=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[197];
av2[3]=lf[234];
av2[4]=lf[237];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3091(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3091,c,av);}
a=C_alloc(45);
t2=C_mutate((C_word*)lf[24]+1 /* (set! chicken.file.posix#file-position ...) */,t1);
t3=C_set_block_item(lf[40] /* chicken.file.posix#fileno/stdin */,0,C_fix((C_word)STDIN_FILENO));
t4=C_set_block_item(lf[41] /* chicken.file.posix#fileno/stdout */,0,C_fix((C_word)STDOUT_FILENO));
t5=C_set_block_item(lf[39] /* chicken.file.posix#fileno/stderr */,0,C_fix((C_word)STDERR_FILENO));
t6=C_set_block_item(lf[52] /* chicken.file.posix#open/rdonly */,0,C_fix((C_word)O_RDONLY));
t7=C_set_block_item(lf[59] /* chicken.file.posix#open/wronly */,0,C_fix((C_word)O_WRONLY));
t8=C_set_block_item(lf[53] /* chicken.file.posix#open/rdwr */,0,C_fix((C_word)O_RDWR));
t9=C_set_block_item(lf[54] /* chicken.file.posix#open/read */,0,C_fix((C_word)O_RDONLY));
t10=C_set_block_item(lf[58] /* chicken.file.posix#open/write */,0,C_fix((C_word)O_WRONLY));
t11=C_set_block_item(lf[46] /* chicken.file.posix#open/creat */,0,C_fix((C_word)O_CREAT));
t12=C_set_block_item(lf[44] /* chicken.file.posix#open/append */,0,C_fix((C_word)O_APPEND));
t13=C_set_block_item(lf[47] /* chicken.file.posix#open/excl */,0,C_fix((C_word)O_EXCL));
t14=C_set_block_item(lf[57] /* chicken.file.posix#open/trunc */,0,C_fix((C_word)O_TRUNC));
t15=C_set_block_item(lf[45] /* chicken.file.posix#open/binary */,0,C_fix((C_word)O_BINARY));
t16=C_set_block_item(lf[56] /* chicken.file.posix#open/text */,0,C_fix((C_word)O_TEXT));
t17=C_set_block_item(lf[62] /* chicken.file.posix#perm/irusr */,0,C_fix((C_word)S_IRUSR));
t18=C_set_block_item(lf[71] /* chicken.file.posix#perm/iwusr */,0,C_fix((C_word)S_IWUSR));
t19=C_set_block_item(lf[74] /* chicken.file.posix#perm/ixusr */,0,C_fix((C_word)S_IXUSR));
t20=C_set_block_item(lf[60] /* chicken.file.posix#perm/irgrp */,0,C_fix((C_word)S_IRGRP));
t21=C_set_block_item(lf[69] /* chicken.file.posix#perm/iwgrp */,0,C_fix((C_word)S_IWGRP));
t22=C_set_block_item(lf[72] /* chicken.file.posix#perm/ixgrp */,0,C_fix((C_word)S_IXGRP));
t23=C_set_block_item(lf[61] /* chicken.file.posix#perm/iroth */,0,C_fix((C_word)S_IROTH));
t24=C_set_block_item(lf[70] /* chicken.file.posix#perm/iwoth */,0,C_fix((C_word)S_IWOTH));
t25=C_set_block_item(lf[73] /* chicken.file.posix#perm/ixoth */,0,C_fix((C_word)S_IXOTH));
t26=C_set_block_item(lf[65] /* chicken.file.posix#perm/irwxu */,0,C_fix((C_word)S_IRUSR | S_IWUSR | S_IXUSR));
t27=C_set_block_item(lf[63] /* chicken.file.posix#perm/irwxg */,0,C_fix((C_word)S_IRGRP | S_IWGRP | S_IXGRP));
t28=C_set_block_item(lf[64] /* chicken.file.posix#perm/irwxo */,0,C_fix((C_word)S_IROTH | S_IWOTH | S_IXOTH));
t29=C_SCHEME_UNDEFINED;
t30=(*a=C_VECTOR_TYPE|1,a[1]=t29,tmp=(C_word)a,a+=2,tmp);
t31=C_SCHEME_UNDEFINED;
t32=(*a=C_VECTOR_TYPE|1,a[1]=t31,tmp=(C_word)a,a+=2,tmp);
t33=C_set_block_item(t30,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3119,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp));
t34=C_set_block_item(t32,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3156,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp));
t35=C_mutate((C_word*)lf[42]+1 /* (set! chicken.file.posix#open-input-file* ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3175,a[2]=t32,a[3]=t30,a[4]=((C_word)li27),tmp=(C_word)a,a+=5,tmp));
t36=C_mutate((C_word*)lf[43]+1 /* (set! chicken.file.posix#open-output-file* ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3189,a[2]=t32,a[3]=t30,a[4]=((C_word)li28),tmp=(C_word)a,a+=5,tmp));
t37=C_mutate((C_word*)lf[75]+1 /* (set! chicken.file.posix#port->fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3203,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[7]+1 /* (set! chicken.file.posix#duplicate-fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3248,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[180]+1 /* (set! chicken.process-context.posix#current-process-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3275,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t40=C_mutate((C_word*)lf[174]+1 /* (set! chicken.process-context.posix#change-directory* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3278,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp));
t41=*((C_word*)lf[259]+1);
t42=C_mutate((C_word*)lf[259]+1 /* (set! ##sys#change-directory-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3294,a[2]=t41,a[3]=((C_word)li33),tmp=(C_word)a,a+=4,tmp));
t43=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3308,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t44=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5677,a[2]=((C_word)li169),tmp=(C_word)a,a+=3,tmp);
t45=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5702,a[2]=((C_word)li170),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:561: chicken.base#getter-with-setter */
t46=*((C_word*)lf[406]+1);{
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
av2[4]=lf[409];
((C_proc)(void*)(*((C_word*)t46+1)))(5,av2);}}

/* mode in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3119(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_3119,4,t1,t2,t3,t4);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3127,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(t3))){
t6=C_u_i_car(t3);
t7=C_eqp(t6,lf[238]);
if(C_truep(t7)){
if(C_truep(C_i_not(t2))){
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t1;
av2[2]=lf[239];
av2[3]=t4;
tp(4,av2);}}
else{
/* posix-common.scm:487: ##sys#error */
t8=*((C_word*)lf[97]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[240];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
/* posix-common.scm:488: ##sys#error */
t8=*((C_word*)lf[97]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[241];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
if(C_truep(t2)){
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t1;
av2[2]=lf[242];
av2[3]=t4;
tp(4,av2);}}
else{
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t1;
av2[2]=lf[243];
av2[3]=t4;
tp(4,av2);}}}}

/* k3125 in mode in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3127,c,av);}
/* posix-common.scm:483: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* check in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3156(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_3156,5,t1,t2,t3,t4,t5);}
a=C_alloc(4);
if(C_truep(C_null_pointerp(t5))){
/* posix-common.scm:494: posix-error */
t6=lf[188];{
C_word av2[6];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[193];
av2[3]=t2;
av2[4]=lf[244];
av2[5]=t3;
f_2623(6,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3169,a[2]=t5,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* posix-common.scm:495: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[245]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[245]+1);
av2[1]=t6;
av2[2]=C_fix(1);
av2[3]=*((C_word*)lf[246]+1);
av2[4]=lf[247];
av2[5]=lf[236];
tp(6,av2);}}
else{
/* posix-common.scm:495: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[245]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[245]+1);
av2[1]=t6;
av2[2]=C_fix(2);
av2[3]=*((C_word*)lf[246]+1);
av2[4]=lf[247];
av2[5]=lf[236];
tp(6,av2);}}}}

/* k3167 in check in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3169,c,av);}
t2=C_set_file_ptr(t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.file.posix#open-input-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3175(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +7,c,3)))){
C_save_and_reclaim((void*)f_3175,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+7);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3179,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:500: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[248];
tp(4,av2);}}

/* k3177 in chicken.file.posix#open-input-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3179,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3187,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:501: mode */
f_3119(t2,C_SCHEME_TRUE,((C_word*)t0)[6],lf[248]);}

/* k3185 in k3177 in chicken.file.posix#open-input-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3187(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_3187,c,av);}
a=C_alloc(2);
t2=C_fdopen(&a,2,((C_word*)t0)[2],t1);
/* posix-common.scm:501: check */
f_3156(((C_word*)t0)[4],lf[248],((C_word*)t0)[2],C_SCHEME_TRUE,t2);}

/* chicken.file.posix#open-output-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +7,c,3)))){
C_save_and_reclaim((void*)f_3189,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+7);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3193,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:504: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[249];
tp(4,av2);}}

/* k3191 in chicken.file.posix#open-output-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3193(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3193,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3201,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:505: mode */
f_3119(t2,C_SCHEME_FALSE,((C_word*)t0)[6],lf[249]);}

/* k3199 in k3191 in chicken.file.posix#open-output-file* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3201(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_3201,c,av);}
a=C_alloc(2);
t2=C_fdopen(&a,2,((C_word*)t0)[2],t1);
/* posix-common.scm:505: check */
f_3156(((C_word*)t0)[4],lf[249],((C_word*)t0)[2],C_SCHEME_FALSE,t2);}

/* chicken.file.posix#port->fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3203(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3203,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[250]);
t4=C_slot(t2,C_fix(7));
t5=C_eqp(lf[232],t4);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3219,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:515: ##sys#port-data */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[251]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[251]+1);
av2[1]=t6;
av2[2]=t2;
tp(3,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3242,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:516: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[254]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[254]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=C_fix(0);
tp(4,av2);}}}

/* k3217 in chicken.file.posix#port->fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3219(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3219,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(t1,C_fix(0));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3226 in k3240 in chicken.file.posix#port->fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3228,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3240 in chicken.file.posix#port->fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3242,c,av);}
a=C_alloc(4);
if(C_truep(C_i_not(C_i_zerop(t1)))){
t2=C_port_fileno(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3228,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t2,C_fix(0)))){
/* posix-common.scm:519: posix-error */
t4=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[193];
av2[3]=lf[250];
av2[4]=lf[252];
av2[5]=((C_word*)t0)[2];
f_2623(6,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
/* posix-common.scm:521: posix-error */
t2=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[197];
av2[3]=lf[250];
av2[4]=lf[253];
av2[5]=((C_word*)t0)[2];
f_2623(6,av2);}}}

/* chicken.file.posix#duplicate-fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_3248,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3252,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:525: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[255];
tp(4,av2);}}

/* k3250 in chicken.file.posix#duplicate-fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3252(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3252,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3255,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
t3=t2;
f_3255(t3,C_dup(((C_word*)t0)[3]));}
else{
t3=C_i_car(((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3273,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:529: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[255];
tp(4,av2);}}}

/* k3253 in k3250 in chicken.file.posix#duplicate-fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3255(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_3255,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3258,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
/* posix-common.scm:532: posix-error */
t3=lf[188];{
C_word av2[6];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[193];
av2[3]=lf[255];
av2[4]=lf[256];
av2[5]=((C_word*)t0)[3];
f_2623(6,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3256 in k3253 in k3250 in chicken.file.posix#duplicate-fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3258,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3271 in k3250 in chicken.file.posix#duplicate-fileno in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3273,c,av);}
t2=((C_word*)t0)[2];
f_3255(t2,C_dup2(((C_word*)t0)[3],((C_word*)t0)[4]));}

/* chicken.process-context.posix#current-process-id in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3275,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub848(C_SCHEME_UNDEFINED);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process-context.posix#change-directory* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3278,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3282,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:546: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[257];
tp(4,av2);}}

/* k3280 in chicken.process-context.posix#change-directory* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3282,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3285,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_eqp(C_fix(0),C_fchdir(((C_word*)t0)[3]));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* posix-common.scm:548: posix-error */
t4=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[193];
av2[3]=lf[257];
av2[4]=lf[258];
av2[5]=((C_word*)t0)[3];
f_2623(6,av2);}}}

/* k3283 in k3280 in chicken.process-context.posix#change-directory* in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3285(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3285,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#change-directory-hook in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3294(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3294,c,av);}
if(C_truep(C_fixnump(t2))){
t3=*((C_word*)lf[174]+1);
t4=*((C_word*)lf[174]+1);
/* posix-common.scm:553: g855 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[174]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[174]+1);
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

/* k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3308(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3308,c,av);}
a=C_alloc(32);
t2=C_mutate((C_word*)lf[15]+1 /* (set! chicken.file.posix#file-creation-mode ...) */,t1);
t3=C_mutate(&lf[260] /* (set! chicken.posix#decode-seconds ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)C_decode_seconds,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate(&lf[261] /* (set! chicken.posix#check-time-vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3311,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[83]+1 /* (set! chicken.time.posix#seconds->local-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3330,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[81]+1 /* (set! chicken.time.posix#seconds->utc-time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3351,a[2]=((C_word)li37),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[84]+1 /* (set! chicken.time.posix#seconds->string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3383,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t8=C_fix((C_word)sizeof(struct tm));
t9=C_mutate((C_word*)lf[85]+1 /* (set! chicken.time.posix#local-time->seconds ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3421,a[2]=t8,a[3]=((C_word)li39),tmp=(C_word)a,a+=4,tmp));
t10=C_fix((C_word)sizeof(struct tm));
t11=C_mutate((C_word*)lf[87]+1 /* (set! chicken.time.posix#time->string ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3466,a[2]=t10,a[3]=((C_word)li40),tmp=(C_word)a,a+=4,tmp));
t12=C_mutate((C_word*)lf[135]+1 /* (set! chicken.process.signal#set-signal-handler! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3528,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp));
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3543,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5668,a[2]=((C_word)li168),tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:636: chicken.base#getter-with-setter */
t15=*((C_word*)lf[406]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t15;
av2[1]=t13;
av2[2]=t14;
av2[3]=*((C_word*)lf[135]+1);
av2[4]=lf[407];
((C_proc)(void*)(*((C_word*)t15+1)))(5,av2);}}

/* chicken.posix#check-time-vector in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3311(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3311,3,t1,t2,t3);}
t4=C_i_check_vector_2(t3,t2);
t5=C_block_size(t3);
if(C_truep(C_fixnum_lessp(t5,C_fix(10)))){
/* posix-common.scm:580: ##sys#error */
t6=*((C_word*)lf[97]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[262];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* chicken.time.posix#seconds->local-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3330,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3334,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:583: chicken.time#current-seconds */
t3=*((C_word*)lf[218]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_get_rest_arg(c,2,av,2,t0);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f6287,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:584: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[263];
tp(4,av2);}}}

/* k3332 in chicken.time.posix#seconds->local-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3334,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3337,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:584: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[263];
tp(4,av2);}}

/* k3335 in k3332 in chicken.time.posix#seconds->local-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3337,c,av);}
/* posix-common.scm:585: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[260]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[260];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}

/* chicken.time.posix#seconds->utc-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3351,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3355,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:588: chicken.time#current-seconds */
t3=*((C_word*)lf[218]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_get_rest_arg(c,2,av,2,t0);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f6291,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:589: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[264];
tp(4,av2);}}}

/* k3353 in chicken.time.posix#seconds->utc-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3355(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3355,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3358,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:589: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[264];
tp(4,av2);}}

/* k3356 in k3353 in chicken.time.posix#seconds->utc-time in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3358,c,av);}
/* posix-common.scm:590: decode-seconds */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[260]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=lf[260];
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
tp(4,av2);}}

/* chicken.time.posix#seconds->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3383,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3387,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:594: chicken.time#current-seconds */
t3=*((C_word*)lf[218]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_get_rest_arg(c,2,av,2,t0);
f_3387(2,av2);}}}

/* k3385 in chicken.time.posix#seconds->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3387,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3390,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:595: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[266];
tp(4,av2);}}

/* k3388 in k3385 in chicken.time.posix#seconds->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3390(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3390,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3393,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_fix((C_word)sizeof(int) * CHAR_BIT);
t5=C_i_foreign_ranged_integer_argumentp(((C_word*)t0)[3],t4);
/* posix-common.scm:593: ##sys#peek-c-string */
t6=*((C_word*)lf[190]+1);{
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

/* k3391 in k3388 in k3385 in chicken.time.posix#seconds->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3393,c,av);}
if(C_truep(t1)){
t2=C_block_size(t1);
/* posix-common.scm:598: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[265]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[265]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t2,C_fix(1));
tp(5,av2);}}
else{
/* posix-common.scm:599: ##sys#error */
t2=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[266];
av2[3]=lf[267];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* chicken.time.posix#local-time->seconds in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3421,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3425,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:604: check-time-vector */
f_3311(t3,lf[268],t2);}

/* k3423 in chicken.time.posix#local-time->seconds in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3425,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3429,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:605: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[270]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[270]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k3427 in k3423 in chicken.time.posix#local-time->seconds in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3429(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3429,c,av);}
a=C_alloc(7);
t2=C_a_mktime(&a,2,((C_word*)t0)[2],t1);
if(C_truep(C_i_nequalp(C_fix(-1),t2))){
/* posix-common.scm:607: ##sys#error */
t3=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[268];
av2[3]=lf[269];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3466(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3466,c,av);}
a=C_alloc(6);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3473,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:615: check-time-vector */
f_3311(t5,lf[271],t2);}

/* k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3473,c,av);}
a=C_alloc(9);
if(C_truep(((C_word*)t0)[2])){
t2=C_i_check_string_2(((C_word*)t0)[2],lf[271]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3482,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3492,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:619: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[271];
tp(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3499,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3520,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:621: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[270]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[270]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_make_character(0);
tp(4,av2);}}}

/* k3480 in k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3482,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* posix-common.scm:620: ##sys#error */
t2=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[271];
av2[3]=lf[272];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k3490 in k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3492,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3496,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:619: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[270]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[270]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_make_character(0);
tp(4,av2);}}

/* k3494 in k3490 in k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3496,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
if(C_truep(t1)){
t3=C_i_foreign_block_argumentp(t1);
/* posix-common.scm:612: ##sys#peek-c-string */
t4=*((C_word*)lf[190]+1);{
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
t3=*((C_word*)lf[190]+1);{
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

/* k3497 in k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3499(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3499,c,av);}
if(C_truep(t1)){
t2=C_block_size(t1);
/* posix-common.scm:623: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[265]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[265]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t2,C_fix(1));
tp(5,av2);}}
else{
/* posix-common.scm:624: ##sys#error */
t2=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[271];
av2[3]=lf[273];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k3518 in k3471 in chicken.time.posix#time->string in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3520,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
if(C_truep(t1)){
t3=C_i_foreign_block_argumentp(t1);
/* posix-common.scm:611: ##sys#peek-c-string */
t4=*((C_word*)lf[190]+1);{
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
t3=*((C_word*)lf[190]+1);{
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

/* chicken.process.signal#set-signal-handler! in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3528(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3528,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3532,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:631: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[275];
tp(4,av2);}}

/* k3530 in chicken.process.signal#set-signal-handler! in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3532,c,av);}
if(C_truep(((C_word*)t0)[2])){
t2=C_establish_signal_handler(((C_word*)t0)[3],((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[274]+1),((C_word*)t0)[3],((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_establish_signal_handler(((C_word*)t0)[3],C_SCHEME_FALSE);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[274]+1),((C_word*)t0)[3],((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3543(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(81,c,8)))){
C_save_and_reclaim((void *)f_3543,c,av);}
a=C_alloc(81);
t2=C_mutate((C_word*)lf[137]+1 /* (set! chicken.process.signal#signal-handler ...) */,t1);
t3=C_mutate((C_word*)lf[138]+1 /* (set! chicken.process.signal#make-signal-handler ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3545,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[139]+1 /* (set! chicken.process.signal#signal-ignore ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3611,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[140]+1 /* (set! chicken.process.signal#signal-default ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3620,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[126]+1 /* (set! chicken.process#process-sleep ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3629,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[114]+1 /* (set! chicken.process#process-wait ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3635,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate(&lf[286] /* (set! chicken.posix#list->c-string-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3706,a[2]=((C_word)li61),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate(&lf[288] /* (set! chicken.posix#free-c-string-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3823,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate(&lf[297] /* (set! chicken.posix#check-environment-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3857,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3904,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp);
t12=C_mutate(&lf[298] /* (set! chicken.posix#call-with-exec-args ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3906,a[2]=t11,a[3]=((C_word)li76),tmp=(C_word)a,a+=4,tmp));
t13=C_set_block_item(lf[127] /* chicken.process#pipe/buf */,0,C_fix((C_word)PIPE_BUF));
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4060,a[2]=((C_word)li77),tmp=(C_word)a,a+=3,tmp);
t15=C_mutate((C_word*)lf[120]+1 /* (set! chicken.process#open-input-pipe ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4079,a[2]=t14,a[3]=((C_word)li78),tmp=(C_word)a,a+=4,tmp));
t16=C_mutate((C_word*)lf[121]+1 /* (set! chicken.process#open-output-pipe ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4119,a[2]=t14,a[3]=((C_word)li79),tmp=(C_word)a,a+=4,tmp));
t17=C_mutate((C_word*)lf[117]+1 /* (set! chicken.process#close-input-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4159,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[118]+1 /* (set! chicken.process#close-output-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4174,a[2]=((C_word)li81),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[122]+1 /* (set! chicken.process#with-input-from-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4189,a[2]=((C_word)li86),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[116]+1 /* (set! chicken.process#call-with-output-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4223,a[2]=((C_word)li89),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[115]+1 /* (set! chicken.process#call-with-input-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4247,a[2]=((C_word)li92),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[123]+1 /* (set! chicken.process#with-output-to-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4271,a[2]=((C_word)li97),tmp=(C_word)a,a+=3,tmp));
t23=C_set_block_item(lf[50] /* chicken.file.posix#open/noinherit */,0,C_fix((C_word)O_NOINHERIT));
t24=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va6276,a[2]=((C_word*)t0)[2],a[3]=((C_word)li164),tmp=(C_word)a,a+=4,tmp);
t25=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va6278,a[2]=t24,a[3]=((C_word)li165),tmp=(C_word)a,a+=4,tmp);
t26=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va6280,a[2]=t25,a[3]=((C_word)li166),tmp=(C_word)a,a+=4,tmp);
t27=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va6282,a[2]=t26,a[3]=((C_word)li167),tmp=(C_word)a,a+=4,tmp);
t28=t27;
va6282(t28,C_s_a_i_bitwise_ior(&a,2,C_fix((C_word)S_IRUSR),C_fix((C_word)S_IWUSR)));}

/* chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_3545,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3549,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:645: ##sys#make-event-queue */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[280]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[280]+1);
av2[1]=t3;
tp(2,av2);}}

/* k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3549(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3549,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3550,a[2]=t1,a[3]=((C_word)li43),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3566,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3588,a[2]=t5,a[3]=t2,a[4]=((C_word)li45),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_3588(t7,t3,((C_word*)t0)[3]);}

/* g979 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3550(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_3550,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3554,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:648: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[277];
tp(4,av2);}}

/* k3552 in g979 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3554,c,av);}
a=C_alloc(4);
t2=C_establish_signal_handler(((C_word*)t0)[2],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3559,a[2]=((C_word*)t0)[3],a[3]=((C_word)li42),tmp=(C_word)a,a+=4,tmp);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_vector_set(*((C_word*)lf[274]+1),((C_word*)t0)[2],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a3558 in k3552 in g979 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3559,c,av);}
/* posix-common.scm:651: ##sys#add-event-to-queue! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[276]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[276]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
tp(4,av2);}}

/* k3564 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3566,c,av);}
a=C_alloc(4);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3567,a[2]=((C_word*)t0)[3],a[3]=((C_word)li44),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_3567 in k3564 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3567,c,av);}
if(C_truep(C_rest_nullp(c,2))){
/* posix-common.scm:656: ##sys#get-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[278]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[278]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
if(C_truep(C_get_rest_arg(c,2,av,2,t0))){
/* posix-common.scm:655: ##sys#wait-for-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[279]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[279]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
/* posix-common.scm:656: ##sys#get-next-event */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[278]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[278]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* for-each-loop978 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3588(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3588,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3598,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:646: g979 */
t4=((C_word*)t0)[3];
f_3550(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3596 in for-each-loop978 in k3547 in chicken.process.signal#make-signal-handler in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3598(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3598,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3588(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.process.signal#signal-ignore in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3611,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3615,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:660: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[281];
tp(4,av2);}}

/* k3613 in chicken.process.signal#signal-ignore in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3615,c,av);}
t2=C_establish_signal_handler(((C_word*)t0)[2],C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[274]+1),((C_word*)t0)[2],C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process.signal#signal-default in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3620,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3624,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:666: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[282];
tp(4,av2);}}

/* k3622 in chicken.process.signal#signal-default in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3624(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3624,c,av);}
t2=C_establish_signal_handler(((C_word*)t0)[2],C_SCHEME_TRUE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_vector_set(*((C_word*)lf[274]+1),((C_word*)t0)[2],C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#process-sleep in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3629,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3633,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:675: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[283];
tp(4,av2);}}

/* k3631 in chicken.process#process-sleep in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3633,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_process_sleep(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#process-wait in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3635(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3635,c,av);}
a=C_alloc(5);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=(C_truep(t3)?t3:C_fix(-1));
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3654,a[2]=t8,a[3]=t6,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:682: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t9;
av2[2]=t8;
av2[3]=lf[284];
tp(4,av2);}}

/* k3652 in chicken.process#process-wait in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3654(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_3654,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3659,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li50),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3665,a[2]=((C_word*)t0)[2],a[3]=((C_word)li51),tmp=(C_word)a,a+=4,tmp);
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

/* a3658 in k3652 in chicken.process#process-wait in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3659,c,av);}
if(C_truep(C_process_wait(((C_word*)t0)[2],((C_word*)t0)[3]))){
/* posixwin.scm:856: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_fix((C_word)C_exstatus);
C_values(5,av2);}}
else{
/* posixwin.scm:857: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=C_fix(-1);
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}}

/* a3664 in k3652 in chicken.process#process-wait in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3665(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3665,c,av);}
t5=C_eqp(t2,C_fix(-1));
if(C_truep(t5)){
/* posix-common.scm:685: posix-error */
t6=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[93];
av2[3]=lf[284];
av2[4]=lf[285];
av2[5]=((C_word*)t0)[2];
f_2623(6,av2);}}
else{
/* posix-common.scm:686: scheme#values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
C_values(5,av2);}}}

/* chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3706(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_3706,4,t1,t2,t3,t4);}
a=C_alloc(12);
t5=C_i_check_list_2(t2,t4);
t6=C_u_i_length(t2);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3714,a[2]=t1,a[3]=t6,a[4]=t4,a[5]=t3,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
t8=C_a_i_fixnum_plus(&a,2,t6,C_fix(1));
/* posix-common.scm:702: chicken.memory#make-pointer-vector */
t9=*((C_word*)lf[293]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
av2[3]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_3714,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3717,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3722,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li60),tmp=(C_word)a,a+=8,tmp);
/* posix-common.scm:704: scheme#call-with-current-continuation */
t4=*((C_word*)lf[292]+1);{
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

/* k3715 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3717,c,av);}
/* posix-common.scm:700: g1050 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3722(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3722,c,av);}
a=C_alloc(14);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3728,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li54),tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3743,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=((C_word)li59),tmp=(C_word)a,a+=9,tmp);
/* posix-common.scm:704: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[291]+1);{
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

/* a3727 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3728,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3734,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li53),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:704: k1047 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a3733 in a3727 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3734,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3738,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:706: free-c-string-buffer */
f_3823(t2,((C_word*)t0)[3]);}

/* k3736 in a3733 in a3727 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3738,c,av);}
/* posix-common.scm:706: chicken.condition#signal */
t2=*((C_word*)lf[287]+1);{
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

/* a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3743(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3743,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3745,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li56),tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3802,a[2]=((C_word*)t0)[7],a[3]=((C_word)li58),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3819,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tmp12239 */
t5=t2;
f_3745(t5,t4);}

/* tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3745(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_3745,2,t0,t1);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3749,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3751,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],a[7]=((C_word)li55),tmp=(C_word)a,a+=8,tmp));
t6=((C_word*)t4)[1];
f_3751(t6,t2,((C_word*)t0)[6],C_fix(0));}

/* k3747 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3749,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* doloop1055 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3751(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3751,4,t0,t1,t2,t3);}
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
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3767,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3792,a[2]=t8,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:715: convert */
t10=((C_word*)t0)[6];{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=C_u_i_car(t2);
((C_proc)C_fast_retrieve_proc(t10))(3,av2);}}}

/* k3765 in doloop1055 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_3767,c,av);}
a=C_alloc(13);
t2=C_a_i_bytevector(&a,1,C_fix(3));
t3=stub1038(t2,t1);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3773,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t3,tmp=(C_word)a,a+=8,tmp);
if(C_truep(t3)){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_3773(2,av2);}}
else{
/* posix-common.scm:717: chicken.base#error */
t5=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[7];
av2[3]=lf[290];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k3771 in k3765 in doloop1055 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3773,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3776,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:718: chicken.memory#pointer-vector-set! */
t3=*((C_word*)lf[289]+1);{
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

/* k3774 in k3771 in k3765 in doloop1055 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 in ... */
static void C_ccall f_3776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3776,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3751(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* k3790 in doloop1055 in tmp12239 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3792,c,av);}
/* posix-common.scm:715: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* tmp22240 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3802(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3802,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3808,a[2]=t2,a[3]=((C_word)li57),tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:704: k1047 */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a3807 in tmp22240 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3808,c,av);}{
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

/* k3817 in a3742 in a3721 in k3712 in chicken.posix#list->c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3819,c,av);}
a=C_alloc(3);
/* tmp22240 */
t2=((C_word*)t0)[2];
f_3802(t2,((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* chicken.posix#free-c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3823(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3823,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3827,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:723: chicken.memory#pointer-vector-length */
t4=*((C_word*)lf[296]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3825 in chicken.posix#free-c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3827,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3832,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li62),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3832(t5,((C_word*)t0)[3],C_fix(0));}

/* doloop1074 in k3825 in chicken.posix#free-c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3832(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_3832,3,t0,t1,t2);}
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
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3842,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:726: chicken.memory#pointer-vector-ref */
t5=*((C_word*)lf[295]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k3840 in doloop1074 in k3825 in chicken.posix#free-c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3842,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3845,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
/* posix-common.scm:727: chicken.memory#free */
t3=*((C_word*)lf[294]+1);{
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
f_3832(t3,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}}

/* k3843 in k3840 in doloop1074 in k3825 in chicken.posix#free-c-string-buffer in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3845,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3832(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* chicken.posix#check-environment-list in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3857(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_3857,3,t1,t2,t3);}
a=C_alloc(8);
t4=C_i_check_list_2(t2,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3862,a[2]=t3,a[3]=((C_word)li64),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3881,a[2]=t5,a[3]=((C_word)li65),tmp=(C_word)a,a+=4,tmp);
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=(
  f_3881(t6,t2)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* g1087 in chicken.posix#check-environment-list in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static C_word C_fcall f_3862(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_i_check_pair_2(t1,((C_word*)t0)[2]);
t3=C_i_check_string_2(C_u_i_car(t1),((C_word*)t0)[2]);
return(C_i_check_string_2(C_u_i_cdr(t1),((C_word*)t0)[2]));}

/* for-each-loop1086 in chicken.posix#check-environment-list in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static C_word C_fcall f_3881(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* posix-common.scm:732: g1087 */
  f_3862(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* nop in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3904,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3906(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_3906,8,t0,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(11);
t8=C_a_i_cons(&a,2,t3,t5);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3913,a[2]=t1,a[3]=t7,a[4]=t3,a[5]=t2,a[6]=t6,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* posix-common.scm:743: list->c-string-buffer */
f_3706(t9,t8,t4,t2);}

/* k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3913(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3913,c,av);}
a=C_alloc(15);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3916,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3921,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li75),tmp=(C_word)a,a+=10,tmp);
/* posix-common.scm:746: scheme#call-with-current-continuation */
t6=*((C_word*)lf[292]+1);{
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

/* k3914 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3916,c,av);}
/* posix-common.scm:742: g1120 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3921(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3921,c,av);}
a=C_alloc(17);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3927,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word)li69),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3948,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t2,a[10]=((C_word)li74),tmp=(C_word)a,a+=11,tmp);
/* posix-common.scm:746: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[291]+1);{
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

/* a3926 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3927,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3933,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li68),tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:746: k1117 */
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a3932 in a3926 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3933,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3937,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:748: free-c-string-buffer */
f_3823(t2,((C_word*)t0)[4]);}

/* k3935 in a3932 in a3926 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3937,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3940,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
/* posix-common.scm:749: free-c-string-buffer */
f_3823(t2,((C_word*)((C_word*)t0)[4])[1]);}
else{
/* posix-common.scm:750: chicken.condition#signal */
t3=*((C_word*)lf[287]+1);{
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

/* k3938 in k3935 in a3932 in a3926 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3940,c,av);}
/* posix-common.scm:750: chicken.condition#signal */
t2=*((C_word*)lf[287]+1);{
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

/* a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_3948,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3954,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word)li71),tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4029,a[2]=((C_word*)t0)[9],a[3]=((C_word)li73),tmp=(C_word)a,a+=4,tmp);
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

/* a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_3954,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3958,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[7])){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3968,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* posix-common.scm:754: check-environment-list */
f_3857(t3,((C_word*)t0)[7],((C_word*)t0)[6]);}
else{
t3=t2;
f_3958(t3,C_SCHEME_UNDEFINED);}}

/* k3956 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3958(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3958,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3965,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posix-common.scm:760: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
tp(4,av2);}}

/* k3963 in k3956 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3965,c,av);}
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

/* k3966 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3968(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3968,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3972,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[299]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3993,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3995,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li70),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_3995(t12,t8,((C_word*)t0)[4]);}

/* k3970 in k3966 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3972(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3972,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_3958(t3,t2);}

/* k3991 in k3966 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_3993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3993,c,av);}
/* posix-common.scm:756: list->c-string-buffer */
f_3706(((C_word*)t0)[2],t1,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* map-loop1128 in k3966 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_3995(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_3995,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4020,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
/* posix-common.scm:757: scheme#string-append */
t5=*((C_word*)lf[106]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t3;
av2[2]=C_i_car(t4);
av2[3]=lf[300];
av2[4]=C_u_i_cdr(t4);
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4018 in map-loop1128 in k3966 in a3953 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4020,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3995(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a4028 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4029,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4035,a[2]=t2,a[3]=((C_word)li72),tmp=(C_word)a,a+=4,tmp);
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

/* a4034 in a4028 in a3947 in a3920 in k3911 in chicken.posix#call-with-exec-args in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4035(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4035,c,av);}{
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

/* check in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall f_4060(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_4060,5,t1,t2,t3,t4,t5);}
a=C_alloc(4);
if(C_truep(C_null_pointerp(t5))){
/* posix-common.scm:772: posix-error */
t6=lf[188];{
C_word av2[6];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[193];
av2[3]=t2;
av2[4]=lf[301];
av2[5]=t3;
f_2623(6,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4073,a[2]=t5,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* posix-common.scm:773: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[245]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[245]+1);
av2[1]=t6;
av2[2]=C_fix(1);
av2[3]=*((C_word*)lf[246]+1);
av2[4]=lf[302];
av2[5]=lf[236];
tp(6,av2);}}
else{
/* posix-common.scm:773: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[245]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[245]+1);
av2[1]=t6;
av2[2]=C_fix(2);
av2[3]=*((C_word*)lf[246]+1);
av2[4]=lf[302];
av2[5]=lf[236];
tp(6,av2);}}}}

/* k4071 in check in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4073,c,av);}
t2=C_set_file_ptr(t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#open-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +10,c,3)))){
C_save_and_reclaim((void*)f_4079,c,av);}
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
t4=C_i_check_string_2(t2,lf[303]);
t5=C_i_pairp(t3);
t6=(C_truep(t5)?C_slot(t3,C_fix(0)):lf[304]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4093,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(t6,lf[304]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4100,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:784: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t9;
av2[2]=t2;
av2[3]=lf[303];
tp(4,av2);}}
else{
t9=C_eqp(t6,lf[305]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4110,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:785: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t10;
av2[2]=t2;
av2[3]=lf[303];
tp(4,av2);}}
else{
/* posix-common.scm:769: ##sys#error */
t10=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t7;
av2[2]=lf[306];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}}

/* k4091 in chicken.process#open-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4093,c,av);}
/* posix-common.scm:780: check */
f_4060(((C_word*)t0)[3],lf[303],((C_word*)t0)[4],C_SCHEME_TRUE,t1);}

/* k4098 in chicken.process#open-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4100,c,av);}
a=C_alloc(2);
t2=open_text_input_pipe(&a,1,t1);
/* posix-common.scm:780: check */
f_4060(((C_word*)t0)[3],lf[303],((C_word*)t0)[4],C_SCHEME_TRUE,t2);}

/* k4108 in chicken.process#open-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4110,c,av);}
a=C_alloc(2);
t2=open_binary_input_pipe(&a,1,t1);
/* posix-common.scm:780: check */
f_4060(((C_word*)t0)[3],lf[303],((C_word*)t0)[4],C_SCHEME_TRUE,t2);}

/* chicken.process#open-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +10,c,3)))){
C_save_and_reclaim((void*)f_4119,c,av);}
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
t4=C_i_check_string_2(t2,lf[307]);
t5=C_i_pairp(t3);
t6=(C_truep(t5)?C_slot(t3,C_fix(0)):lf[304]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4133,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(t6,lf[304]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4140,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:795: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t9;
av2[2]=t2;
av2[3]=lf[307];
tp(4,av2);}}
else{
t9=C_eqp(t6,lf[305]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4150,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:796: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t10;
av2[2]=t2;
av2[3]=lf[307];
tp(4,av2);}}
else{
/* posix-common.scm:769: ##sys#error */
t10=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t7;
av2[2]=lf[306];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}}

/* k4131 in chicken.process#open-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4133,c,av);}
/* posix-common.scm:791: check */
f_4060(((C_word*)t0)[3],lf[307],((C_word*)t0)[4],C_SCHEME_FALSE,t1);}

/* k4138 in chicken.process#open-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4140,c,av);}
a=C_alloc(2);
t2=open_text_output_pipe(&a,1,t1);
/* posix-common.scm:791: check */
f_4060(((C_word*)t0)[3],lf[307],((C_word*)t0)[4],C_SCHEME_FALSE,t2);}

/* k4148 in chicken.process#open-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,5)))){
C_save_and_reclaim((void *)f_4150,c,av);}
a=C_alloc(2);
t2=open_binary_output_pipe(&a,1,t1);
/* posix-common.scm:791: check */
f_4060(((C_word*)t0)[3],lf[307],((C_word*)t0)[4],C_SCHEME_FALSE,t2);}

/* chicken.process#close-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4159(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4159,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(1),C_SCHEME_TRUE,lf[308]);
t4=close_pipe(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4166,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(C_fix(-1),t4);
if(C_truep(t6)){
/* posix-common.scm:803: posix-error */
t7=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=lf[193];
av2[3]=lf[308];
av2[4]=lf[309];
av2[5]=t2;
f_2623(6,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k4164 in chicken.process#close-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4166,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#close-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4174(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4174,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(2),C_SCHEME_TRUE,lf[310]);
t4=close_pipe(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4181,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(C_fix(-1),t4);
if(C_truep(t6)){
/* posix-common.scm:810: posix-error */
t7=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=lf[193];
av2[3]=lf[310];
av2[4]=lf[311];
av2[5]=t2;
f_2623(6,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k4179 in chicken.process#close-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4181(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4181,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4189,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4193,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[120]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4193(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4193,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4198,a[2]=t5,a[3]=t3,a[4]=((C_word)li82),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4203,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word)li84),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4218,a[2]=t3,a[3]=t5,a[4]=((C_word)li85),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:816: ##sys#dynamic-wind */
t9=*((C_word*)lf[314]+1);{
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

/* a4197 in k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4198(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4198,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[312]+1));
t3=C_mutate((C_word*)lf[312]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4202 in k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4203,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4209,a[2]=((C_word*)t0)[2],a[3]=((C_word)li83),tmp=(C_word)a,a+=4,tmp);
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

/* a4208 in a4202 in k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4209,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4213,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:819: chicken.process#close-input-pipe */
t4=*((C_word*)lf[117]+1);{
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

/* k4211 in a4208 in a4202 in k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4213,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[313]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* a4217 in k4191 in chicken.process#with-input-from-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4218,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[312]+1));
t3=C_mutate((C_word*)lf[312]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.process#call-with-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4223,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4227,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4225 in chicken.process#call-with-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4227,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4232,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li87),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4238,a[2]=t1,a[3]=((C_word)li88),tmp=(C_word)a,a+=4,tmp);
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

/* a4231 in k4225 in chicken.process#call-with-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4232,c,av);}
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

/* a4237 in k4225 in chicken.process#call-with-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4238(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4238,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4242,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:828: chicken.process#close-output-pipe */
t4=*((C_word*)lf[118]+1);{
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

/* k4240 in a4237 in k4225 in chicken.process#call-with-output-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4242,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[313]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* chicken.process#call-with-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4247(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4247,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4251,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[120]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4249 in chicken.process#call-with-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4251,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4256,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li90),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4262,a[2]=t1,a[3]=((C_word)li91),tmp=(C_word)a,a+=4,tmp);
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

/* a4255 in k4249 in chicken.process#call-with-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4256,c,av);}
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

/* a4261 in k4249 in chicken.process#call-with-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4262,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4266,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:837: chicken.process#close-input-pipe */
t4=*((C_word*)lf[117]+1);{
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

/* k4264 in a4261 in k4249 in chicken.process#call-with-input-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4266,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[313]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4271(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4271,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4275,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=t2;
av2[4]=t4;
C_apply(5,av2);}}

/* k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4275(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4275,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4280,a[2]=t5,a[3]=t3,a[4]=((C_word)li93),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4285,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word)li95),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4300,a[2]=t3,a[3]=t5,a[4]=((C_word)li96),tmp=(C_word)a,a+=5,tmp);
/* posix-common.scm:843: ##sys#dynamic-wind */
t9=*((C_word*)lf[314]+1);{
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

/* a4279 in k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4280,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[315]+1));
t3=C_mutate((C_word*)lf[315]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4284 in k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4285(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4285,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4291,a[2]=((C_word*)t0)[2],a[3]=((C_word)li94),tmp=(C_word)a,a+=4,tmp);
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

/* a4290 in a4284 in k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_4291,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4295,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:846: chicken.process#close-output-pipe */
t4=*((C_word*)lf[118]+1);{
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

/* k4293 in a4290 in a4284 in k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4295,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[313]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* a4299 in k4273 in chicken.process#with-output-to-pipe in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_4300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4300,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[315]+1));
t3=C_mutate((C_word*)lf[315]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.file.posix#file-open */
static void C_ccall f_4309(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4309,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_get_rest_arg(c,4,av,4,t0):((C_word*)t0)[2]);
t7=C_i_check_string_2(t2,lf[316]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4319,a[2]=t3,a[3]=t6,a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:524: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t8;
av2[2]=t3;
av2[3]=lf[316];
tp(4,av2);}}

/* k4317 in chicken.file.posix#file-open */
static void C_ccall f_4319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4319,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4322,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:525: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[316];
tp(4,av2);}}

/* k4320 in k4317 in chicken.file.posix#file-open */
static void C_ccall f_4322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4322,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4326,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:526: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[316];
tp(4,av2);}}

/* k4324 in k4320 in k4317 in chicken.file.posix#file-open */
static void C_ccall f_4326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4326,c,av);}
a=C_alloc(10);
t2=C_open(t1,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4329,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4339,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:529: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4327 in k4324 in k4320 in k4317 in chicken.file.posix#file-open */
static void C_ccall f_4329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4329,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4337 in k4324 in k4320 in k4317 in chicken.file.posix#file-open */
static void C_ccall f_4339(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_4339,c,av);}
/* posixwin.scm:528: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=t1;
av2[4]=lf[316];
av2[5]=lf[317];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[4];
av2[8]=((C_word*)t0)[5];
tp(9,av2);}}

/* chicken.file.posix#file-close */
static void C_ccall f_4345(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4345,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4349,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:534: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[319];
tp(4,av2);}}

/* k4347 in chicken.file.posix#file-close */
static void C_ccall f_4349(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4349,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4354,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li99),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
f_4354(2,av2);}}

/* loop in k4347 in chicken.file.posix#file-close */
static void C_ccall f_4354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4354,c,av);}
if(C_truep(C_fixnum_lessp(C_close(((C_word*)t0)[2]),C_fix(0)))){
t2=C_eqp(C_fix((C_word)errno),C_fix((C_word)EINTR));
if(C_truep(t2)){
/* posixwin.scm:538: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[318]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[318]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
tp(3,av2);}}
else{
/* posixwin.scm:540: posix-error */
t3=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[193];
av2[3]=lf[319];
av2[4]=lf[320];
av2[5]=((C_word*)t0)[2];
f_2623(6,av2);}}}
else{
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.file.posix#file-read */
static void C_ccall f_4376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4376,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4380,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:544: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[321];
tp(4,av2);}}

/* k4378 in chicken.file.posix#file-read */
static void C_ccall f_4380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4380,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4383,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:545: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[321];
tp(4,av2);}}

/* k4381 in k4378 in chicken.file.posix#file-read */
static void C_ccall f_4383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4383,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4386,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[5]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_car(((C_word*)t0)[5]);
f_4386(2,av2);}}
else{
/* posixwin.scm:546: scheme#make-string */
t3=*((C_word*)lf[324]+1);{
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

/* k4384 in k4381 in k4378 in chicken.file.posix#file-read */
static void C_ccall f_4386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_4386,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4389,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_blockp(t1))){
if(C_truep(C_byteblockp(t1))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4389(2,av2);}}
else{
/* posixwin.scm:548: ##sys#signal-hook */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[197];
av2[3]=lf[321];
av2[4]=lf[323];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}
else{
/* posixwin.scm:548: ##sys#signal-hook */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[197];
av2[3]=lf[321];
av2[4]=lf[323];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* k4387 in k4384 in k4381 in k4378 in chicken.file.posix#file-read */
static void C_ccall f_4389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4389,c,av);}
a=C_alloc(11);
t2=C_read(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4392,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4405,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:552: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4390 in k4387 in k4384 in k4381 in k4378 in chicken.file.posix#file-read */
static void C_ccall f_4392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4392,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4403 in k4387 in k4384 in k4381 in k4378 in chicken.file.posix#file-read */
static void C_ccall f_4405(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4405,c,av);}
/* posixwin.scm:551: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=t1;
av2[4]=lf[321];
av2[5]=lf[322];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[4];
tp(8,av2);}}

/* chicken.file.posix#file-write */
static void C_ccall f_4420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_4420,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4424,a[2]=t4,a[3]=t3,a[4]=t2,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:557: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[325];
tp(4,av2);}}

/* k4422 in chicken.file.posix#file-write */
static void C_ccall f_4424(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_4424,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4427,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_blockp(((C_word*)t0)[3]))){
if(C_truep(C_byteblockp(((C_word*)t0)[3]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4427(2,av2);}}
else{
/* posixwin.scm:559: ##sys#signal-hook */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[197];
av2[3]=lf[325];
av2[4]=lf[327];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}
else{
/* posixwin.scm:559: ##sys#signal-hook */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[197];
av2[3]=lf[325];
av2[4]=lf[327];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* k4425 in k4422 in chicken.file.posix#file-write */
static void C_ccall f_4427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4427,c,av);}
a=C_alloc(6);
t2=C_i_pairp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_u_i_car(((C_word*)t0)[2]):C_block_size(((C_word*)t0)[3]));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4433,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:561: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[325];
tp(4,av2);}}

/* k4431 in k4425 in k4422 in chicken.file.posix#file-write */
static void C_ccall f_4433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4433,c,av);}
a=C_alloc(9);
t2=C_write(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4436,a[2]=((C_word*)t0)[5],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_eqp(C_fix(-1),t2);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4446,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:565: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k4434 in k4431 in k4425 in k4422 in chicken.file.posix#file-write */
static void C_ccall f_4436(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4436,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4444 in k4431 in k4425 in k4422 in chicken.file.posix#file-write */
static void C_ccall f_4446(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4446,c,av);}
/* posixwin.scm:564: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=t1;
av2[4]=lf[325];
av2[5]=lf[326];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[4];
tp(8,av2);}}

/* chicken.file.posix#file-mkstemp */
static void C_ccall f_4461(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(40,c,2)))){
C_save_and_reclaim((void *)f_4461,c,av);}
a=C_alloc(40);
t3=C_i_check_string_2(t2,lf[328]);
t4=lf[329];
t5=C_block_size(t4);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)va6268,a[2]=t5,a[3]=t4,a[4]=t2,a[5]=t1,a[6]=((C_word)li107),tmp=(C_word)a,a+=7,tmp);
t7=t6;
va6268(t7,C_s_a_i_times(&a,2,t5,t5));}

/* k4472 */
static void C_ccall f_4474(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,2)))){
C_save_and_reclaim((void *)f_4474,c,av);}
a=C_alloc(23);
t2=C_block_size(t1);
t3=C_fixnum_difference(t2,C_fix(1));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4589,a[2]=t1,a[3]=((C_word)li103),tmp=(C_word)a,a+=4,tmp);
t5=(
  f_4589(t4,t3)
);
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4483,a[2]=t2,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=t1,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4576,a[2]=t6,a[3]=((C_word*)t0)[5],a[4]=t5,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4580,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* posixwin.scm:581: chicken.pathname#pathname-directory */
t9=*((C_word*)lf[335]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k4481 in k4472 */
static void C_ccall f_4483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4483,c,av);}
a=C_alloc(13);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4488,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word*)t0)[8],a[10]=((C_word)li106),tmp=(C_word)a,a+=11,tmp));
t5=((C_word*)t3)[1];
f_4488(t5,((C_word*)t0)[9],C_fix(1));}

/* loop in k4481 in k4472 */
static void C_fcall f_4488(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_4488,3,t0,t1,t2);}
a=C_alloc(15);
t3=C_fixnum_difference(((C_word*)t0)[2],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4535,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li104),tmp=(C_word)a,a+=7,tmp);
t5=(
  f_4535(t4,t3)
);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4496,a[2]=t2,a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=t1,a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* posixwin.scm:595: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[316];
tp(4,av2);}}

/* k4494 in loop in k4481 in k4472 */
static void C_ccall f_4496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4496,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)va6260,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li105),tmp=(C_word)a,a+=10,tmp);
t3=t2;
va6260(t3,C_s_a_i_bitwise_ior(&a,2,*((C_word*)lf[53]+1),*((C_word*)lf[46]+1)));}

/* suffix-loop in loop in k4481 in k4472 */
static C_word C_fcall f_4535(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
t2=C_i_string_ref(((C_word*)t0)[3],C_rand(((C_word*)t0)[4]));
t3=C_i_string_set(((C_word*)t0)[5],t1,t2);
t5=C_fixnum_difference(t1,C_fix(1));
t1=t5;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k4574 in k4472 */
static void C_ccall f_4576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4576,c,av);}
if(C_truep(C_i_not(t1))){
/* posixwin.scm:585: ##sys#signal-hook */
t2=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=lf[328];
av2[4]=lf[331];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],((C_word*)t0)[5]);
if(C_truep(t2)){
/* posixwin.scm:587: ##sys#signal-hook */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=lf[328];
av2[4]=lf[332];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_4483(2,av2);}}}}

/* k4578 in k4472 */
static void C_ccall f_4580(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4580,c,av);}
if(C_truep(t1)){
/* posixwin.scm:581: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[333]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[333]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[328];
tp(6,av2);}}
else{
/* posixwin.scm:581: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[333]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[333]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[334];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[328];
tp(6,av2);}}}

/* loop in k4472 */
static C_word C_fcall f_4589(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
t2=C_fixnum_greater_or_equal_p(t1,C_fix(0));
t3=(C_truep(t2)?C_eqp(C_i_string_ref(((C_word*)t0)[2],t1),C_make_character(88)):C_SCHEME_FALSE);
if(C_truep(t3)){
t5=C_fixnum_difference(t1,C_fix(1));
t1=t5;
goto loop;}
else{
return(C_fixnum_plus(t1,C_fix(1)));}}

/* chicken.process#create-pipe */
static void C_ccall f_4620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4620,c,av);}
a=C_alloc(6);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_fixnum_or(*((C_word*)lf[45]+1),*((C_word*)lf[50]+1)):C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4627,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_fixnum_lessp(C_pipe(C_SCHEME_FALSE,t3),C_fix(0)))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4640,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* posixwin.scm:616: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t5;
tp(2,av2);}}
else{
/* posixwin.scm:617: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=C_fix((C_word)C_pipefds[ 0 ]);
av2[3]=C_fix((C_word)C_pipefds[ 1 ]);
C_values(4,av2);}}}

/* k4625 in chicken.process#create-pipe */
static void C_ccall f_4627(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4627,c,av);}
/* posixwin.scm:617: scheme#values */{
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

/* k4638 in chicken.process#create-pipe */
static void C_ccall f_4640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4640,c,av);}
/* posixwin.scm:615: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=t1;
av2[4]=lf[337];
av2[5]=lf[338];
tp(6,av2);}}

/* chicken.posix#duplicate-fileno */
static void C_ccall f_4683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_4683,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4687,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:672: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[339];
tp(4,av2);}}

/* k4685 in chicken.posix#duplicate-fileno */
static void C_ccall f_4687(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4687,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4690,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
t3=t2;
f_4690(t3,C_dup(((C_word*)t0)[3]));}
else{
t3=C_i_car(((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4712,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:676: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[255];
tp(4,av2);}}}

/* k4688 in k4685 in chicken.posix#duplicate-fileno */
static void C_fcall f_4690(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_4690,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4693,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t1,C_fix(0)))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4703,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:680: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t3;
tp(2,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4691 in k4688 in k4685 in chicken.posix#duplicate-fileno */
static void C_ccall f_4693(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4693,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4701 in k4688 in k4685 in chicken.posix#duplicate-fileno */
static void C_ccall f_4703(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4703,c,av);}
/* posixwin.scm:679: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[193];
av2[3]=t1;
av2[4]=lf[255];
av2[5]=lf[340];
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}

/* k4710 in k4685 in chicken.posix#duplicate-fileno */
static void C_ccall f_4712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4712,c,av);}
t2=((C_word*)t0)[2];
f_4690(t2,C_dup2(((C_word*)t0)[3],((C_word*)t0)[4]));}

/* chicken.time.posix#local-timezone-abbreviation */
static void C_ccall f_4714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4714,c,av);}
a=C_alloc(5);
t2=C_a_i_bytevector(&a,1,C_fix(3));
/* posixwin.scm:687: ##sys#peek-c-string */
t3=*((C_word*)lf[190]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=stub1428(t2);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* loop in chicken.posix#quote-arg-string */
static C_word C_fcall f_4735(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
t2=C_eqp(t1,((C_word*)t0)[2]);
if(C_truep(t2)){
return(C_SCHEME_FALSE);}
else{
t3=C_i_string_ref(((C_word*)t0)[3],t1);
if(C_truep(C_u_i_char_whitespacep(t3))){
return(C_SCHEME_TRUE);}
else{
t5=C_fixnum_plus(t1,C_fix(1));
t1=t5;
goto loop;}}}

/* chicken.posix#quote-arg-string */
static void C_ccall f_4760(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4760,c,av);}
a=C_alloc(5);
t3=C_i_string_length(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4735,a[2]=t3,a[3]=t2,a[4]=((C_word)li112),tmp=(C_word)a,a+=5,tmp);
t5=(
  f_4735(t4,C_fix(0))
);
if(C_truep(t5)){
/* posixwin.scm:721: scheme#string-append */
t6=*((C_word*)lf[106]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[342];
av2[3]=t2;
av2[4]=lf[343];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* chicken.process#process-execute */
static void C_ccall f_4772(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4772,c,av);}
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
t12=(C_truep(t10)?(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4813,a[2]=((C_word)li114),tmp=(C_word)a,a+=3,tmp):lf[341]);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4799,a[2]=t2,a[3]=((C_word)li115),tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:726: call-with-exec-args */
t14=lf[298];
f_3906(t14,t1,lf[344],t2,t12,t4,t7,t13);}

/* a4798 in chicken.process#process-execute */
static void C_ccall f_4799(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4799,c,av);}
t5=C_flushall();
t6=(C_truep(t4)?C_u_i_execve(t2,t3,t4):C_u_i_execvp(t2,t3));
t7=C_eqp(t6,C_fix(-1));
if(C_truep(t7)){
/* posixwin.scm:734: posix-error */
t8=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t8;
av2[1]=t1;
av2[2]=lf[93];
av2[3]=lf[344];
av2[4]=lf[345];
av2[5]=((C_word*)t0)[2];
f_2623(6,av2);}}
else{
t8=C_SCHEME_UNDEFINED;
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* f_4813 in chicken.process#process-execute */
static void C_ccall f_4813(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4813,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.process#process-spawn */
static void C_ccall f_4852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
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
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_4852,c,av);}
a=C_alloc(11);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_rest_nullp(c,6);
t11=(C_truep(t10)?C_SCHEME_FALSE:C_get_rest_arg(c,6,av,4,t0));
t12=C_rest_nullp(c,6);
t13=(C_truep(t11)?(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4896,a[2]=((C_word)li117),tmp=(C_word)a,a+=3,tmp):lf[341]);
t14=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4877,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=t13,a[6]=t5,a[7]=t8,tmp=(C_word)a,a+=8,tmp);
/* posixwin.scm:739: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t14;
av2[2]=t2;
av2[3]=lf[346];
tp(4,av2);}}

/* k4875 in chicken.process#process-spawn */
static void C_ccall f_4877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,7)))){
C_save_and_reclaim((void *)f_4877,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4882,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li118),tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:740: call-with-exec-args */
t3=lf[298];
f_3906(t3,((C_word*)t0)[4],lf[346],((C_word*)t0)[3],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2);}

/* a4881 in k4875 in chicken.process#process-spawn */
static void C_ccall f_4882(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_4882,c,av);}
a=C_alloc(4);
t5=C_flushall();
t6=(C_truep(t4)?C_u_i_spawnvpe(((C_word*)t0)[2],t2,t3,t4):C_u_i_spawnvp(((C_word*)t0)[2],t2,t3));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4889,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=C_eqp(t6,C_fix(-1));
if(C_truep(t8)){
/* posixwin.scm:748: posix-error */
t9=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t9;
av2[1]=t7;
av2[2]=lf[93];
av2[3]=lf[346];
av2[4]=lf[347];
av2[5]=((C_word*)t0)[3];
f_2623(6,av2);}}
else{
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* k4887 in a4881 in k4875 in chicken.process#process-spawn */
static void C_ccall f_4889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4889,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4896 in chicken.process#process-spawn */
static void C_ccall f_4896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4896,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.posix#shell-command */
static void C_fcall f_4935(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4935,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4939,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:754: chicken.process-context#get-environment-variable */
t4=*((C_word*)lf[351]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[352];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4937 in chicken.posix#shell-command */
static void C_ccall f_4939(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4939,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_get_shlcmd())){
/* ##sys#peek-c-string */
t2=*((C_word*)lf[190]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_mpointer(&a,(void*)C_shlcmd);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4955,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:758: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t2;
tp(2,av2);}}}}

/* k4953 in k4937 in chicken.posix#shell-command */
static void C_ccall f_4955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4955,c,av);}
/* posixwin.scm:757: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[349]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[349]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
av2[4]=lf[350];
tp(5,av2);}}

/* chicken.process#process-run */
static void C_ccall f_4963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +4,c,4)))){
C_save_and_reclaim((void*)f_4963,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+4);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=C_i_pairp(t3);
t5=(C_truep(t4)?C_get_rest_arg(c,3,av,3,t0):C_SCHEME_FALSE);
if(C_truep(t5)){
/* posixwin.scm:767: chicken.process#process-spawn */
t6=*((C_word*)lf[113]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=*((C_word*)lf[130]+1);
av2[3]=t2;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4980,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:771: shell-command */
f_4935(t6,lf[354]);}}

/* k4978 in chicken.process#process-run */
static void C_ccall f_4980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4980,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,lf[353],((C_word*)t0)[2]);
/* posixwin.scm:769: chicken.process#process-spawn */
t3=*((C_word*)lf[113]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=*((C_word*)lf[130]+1);
av2[3]=t1;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_4995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_4995,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4999,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],tmp=(C_word)a,a+=16,tmp);
if(C_truep(((C_word*)t0)[14])){
/* posixwin.scm:795: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t2;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[14]);
tp(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_4999(2,av2);}}}

/* k4997 in k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_4999(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4999,c,av);}
a=C_alloc(7);
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_pointer_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_pointer_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=(C_truep(((C_word*)t0)[4])?C_i_foreign_pointer_argumentp(((C_word*)t0)[4]):C_SCHEME_FALSE);
t5=(C_truep(((C_word*)t0)[5])?C_i_foreign_pointer_argumentp(((C_word*)t0)[5]):C_SCHEME_FALSE);
t6=C_i_foreign_fixnum_argumentp(((C_word*)t0)[6]);
if(C_truep(stub1516(C_SCHEME_UNDEFINED,((C_word*)t0)[7],t1,C_SCHEME_FALSE,t2,t3,t4,t5,t6))){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5080,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[12],tmp=(C_word)a,a+=7,tmp);
/* posixwin.scm:815: chicken.file.posix#open-input-file* */
t8=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[13])));
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5104,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[14],a[4]=((C_word*)t0)[15],tmp=(C_word)a,a+=5,tmp);
/* posixwin.scm:823: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t7;
tp(2,av2);}}}

/* k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5063(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,5)))){
C_save_and_reclaim((void *)f_5063,c,av);}
a=C_alloc(23);
t2=C_a_i_bytevector(&a,1,C_fix(1));
t3=((*(int *)C_data_pointer(t2))=C_unfix(C_fix(-1)),C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(1));
t5=((*(int *)C_data_pointer(t4))=C_unfix(C_fix(-1)),C_SCHEME_UNDEFINED);
t6=C_a_i_bytevector(&a,1,C_fix(1));
t7=((*(int *)C_data_pointer(t6))=C_unfix(C_fix(-1)),C_SCHEME_UNDEFINED);
t8=C_a_i_bytevector(&a,1,C_fix(1));
t9=((*(int *)C_data_pointer(t8))=C_unfix(C_fix(-1)),C_SCHEME_UNDEFINED);
t10=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5108,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t8,a[6]=t4,a[7]=t6,a[8]=((C_word*)t0)[4],a[9]=t1,a[10]=((C_word*)t0)[5],tmp=(C_word)a,a+=11,tmp);
/* posixwin.scm:810: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[356]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[356]+1);
av2[1]=t10;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[357];
tp(6,av2);}}

/* k5078 in k4997 in k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5080,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5084,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* posixwin.scm:817: chicken.file.posix#open-output-file* */
t3=*((C_word*)lf[43]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[6])));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5082 in k5078 in k4997 in k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_5084,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5088,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
/* posixwin.scm:820: chicken.file.posix#open-input-file* */
t3=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[6])));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* posixwin.scm:814: scheme#values */{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[4])));
av2[5]=C_SCHEME_FALSE;
C_values(6,av2);}}}

/* k5086 in k5082 in k5078 in k4997 in k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5088,c,av);}
/* posixwin.scm:814: scheme#values */{
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
av2[4]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[5])));
av2[5]=t1;
C_values(6,av2);}}

/* k5102 in k4997 in k4993 in k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5104,c,av);}
/* posixwin.scm:822: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[92]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[92]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[93];
av2[3]=t1;
av2[4]=((C_word*)t0)[3];
av2[5]=lf[355];
av2[6]=((C_word*)t0)[4];
tp(7,av2);}}

/* k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_5108,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5112,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* posixwin.scm:811: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[356]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[356]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[357];
tp(6,av2);}}

/* k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_5112,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_5116,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* posixwin.scm:811: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[356]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[356]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[357];
tp(6,av2);}}

/* k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_5116,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_5120,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* posixwin.scm:811: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[356]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[356]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[357];
tp(6,av2);}}

/* k5118 in k5114 in k5110 in k5106 in k5061 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_5120,c,av);}
a=C_alloc(15);
t2=(C_truep(((C_word*)t0)[2])?C_fix(0):C_fix(4));
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_4995,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=t2,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=((C_word*)t0)[11],a[14]=((C_word*)t0)[12],tmp=(C_word)a,a+=15,tmp);
if(C_truep(((C_word*)t0)[13])){
/* posixwin.scm:795: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[195]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[195]+1);
av2[1]=t3;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[13]);
tp(3,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_4995(2,av2);}}}

/* k5138 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5140,c,av);}
/* posixwin.scm:802: chicken.string#string-intersperse */
t2=*((C_word*)lf[358]+1);{
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

/* map-loop1561 in a5237 in k5231 in k5228 in %process */
static void C_fcall f_5148(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5148,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5173,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* posixwin.scm:805: g1567 */
t4=lf[341];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_4760(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5171 in map-loop1561 in a5237 in k5231 in k5228 in %process */
static void C_ccall f_5173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5173,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5148(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* %process */
static void C_fcall f_5187(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
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
C_word t18;
C_word t19;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,0,3)))){
C_save_and_reclaim_args((void *)trf_5187,7,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(29);
t8=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5189,a[2]=t2,a[3]=((C_word)li124),tmp=(C_word)a,a+=4,tmp);
t12=C_i_check_string_2(((C_word*)t8)[1],t2);
t13=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5230,a[2]=t8,a[3]=t9,a[4]=t10,a[5]=t3,a[6]=t2,a[7]=t1,a[8]=t6,tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t9)[1])){
/* posixwin.scm:834: chkstrlst */
t14=t11;
f_5189(t14,t13,((C_word*)t9)[1]);}
else{
t14=C_set_block_item(t10,0,C_SCHEME_TRUE);
t15=((C_word*)t8)[1];
t16=C_a_i_list2(&a,2,lf[353],t15);
t17=C_set_block_item(t9,0,t16);
t18=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5269,a[2]=t8,a[3]=t13,tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:838: shell-command */
f_4935(t18,t2);}}

/* chkstrlst in %process */
static void C_fcall f_5189(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_5189,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_i_check_list_2(t2,((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5194,a[2]=((C_word*)t0)[2],a[3]=((C_word)li122),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5203,a[2]=t4,a[3]=((C_word)li123),tmp=(C_word)a,a+=4,tmp);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
  f_5203(t5,t2)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* g1637 in chkstrlst in %process */
static C_word C_fcall f_5194(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_check_string_2(t1,((C_word*)t0)[2]));}

/* for-each-loop1636 in chkstrlst in %process */
static C_word C_fcall f_5203(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* posixwin.scm:831: g1637 */
  f_5194(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k5228 in %process */
static void C_ccall f_5230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5230,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5233,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[8])){
/* posixwin.scm:839: check-environment-list */
f_3857(t2,((C_word*)t0)[8],((C_word*)t0)[6]);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5233(2,av2);}}}

/* k5231 in k5228 in %process */
static void C_ccall f_5233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,6)))){
C_save_and_reclaim((void *)f_5233,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5238,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li126),tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5244,a[2]=((C_word*)t0)[5],a[3]=((C_word)li127),tmp=(C_word)a,a+=4,tmp);
/* posixwin.scm:840: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[7];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a5237 in k5231 in k5228 in %process */
static void C_ccall f_5238(C_word c,C_word *av){
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
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_5238,c,av);}
a=C_alloc(28);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)((C_word*)t0)[3])[1];
t4=C_a_i_list(&a,1,((C_word*)((C_word*)t0)[4])[1]);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_i_car(t4));
t7=C_a_i_cons(&a,2,t2,t3);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5063,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=((C_word*)t0)[6],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5140,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
if(C_truep(t6)){
/* posixwin.scm:802: chicken.string#string-intersperse */
t10=*((C_word*)lf[358]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t10;
av2[1]=t8;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t10=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t11=t10;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=((C_word*)t12)[1];
t14=lf[341];
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5148,a[2]=t12,a[3]=t16,a[4]=t13,a[5]=((C_word)li125),tmp=(C_word)a,a+=6,tmp));
t18=((C_word*)t16)[1];
f_5148(t18,t9,t7);}}

/* a5243 in k5231 in k5228 in %process */
static void C_ccall f_5244(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5244,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* posixwin.scm:843: scheme#values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
av2[5]=t5;
C_values(6,av2);}}
else{
/* posixwin.scm:844: scheme#values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
C_values(5,av2);}}}

/* k5267 in %process */
static void C_ccall f_5269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5269,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_5230(2,av2);}}

/* chicken.process#process */
static void C_ccall f_5271(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5271,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
if(C_truep(C_rest_nullp(c,5))){
/* posixwin.scm:847: %process */
f_5187(t1,lf[359],C_SCHEME_FALSE,t2,t4,t7,t10);}
else{
/* posixwin.scm:847: %process */
f_5187(t1,lf[359],C_SCHEME_FALSE,t2,t4,t7,t10);}}

/* chicken.process#process* */
static void C_ccall f_5331(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5331,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
if(C_truep(C_rest_nullp(c,5))){
/* posixwin.scm:850: %process */
f_5187(t1,lf[360],C_SCHEME_TRUE,t2,t4,t7,t10);}
else{
/* posixwin.scm:850: %process */
f_5187(t1,lf[360],C_SCHEME_TRUE,t2,t4,t7,t10);}}

/* chicken.process-context.posix#current-user-name */
static void C_ccall f_5403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5403,c,av);}
a=C_alloc(3);
if(C_truep(C_get_user_name())){
/* ##sys#peek-c-string */
t2=*((C_word*)lf[190]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=C_mpointer(&a,(void*)C_username);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5417,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posixwin.scm:869: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[95]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[95]+1);
av2[1]=t2;
tp(2,av2);}}}

/* k5415 in chicken.process-context.posix#current-user-name */
static void C_ccall f_5417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5417,c,av);}
/* posixwin.scm:868: ##sys#error/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[349]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[349]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[361];
av2[4]=lf[362];
tp(5,av2);}}

/* chicken.file.posix#create-fifo */
static void C_ccall f_5425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5425,c,av);}
/* posixwin.scm:875: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[4];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#create-session */
static void C_ccall f_5431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5431,c,av);}
/* posixwin.scm:876: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[184];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#create-symbolic-link */
static void C_ccall f_5437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5437,c,av);}
/* posixwin.scm:877: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[5];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#current-effective-group-id */
static void C_ccall f_5443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5443,c,av);}
/* posixwin.scm:878: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[176];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#current-effective-user-id */
static void C_ccall f_5449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5449,c,av);}
/* posixwin.scm:879: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[177];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#current-effective-user-name */
static void C_ccall f_5455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5455,c,av);}
/* posixwin.scm:880: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[183];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#current-group-id */
static void C_ccall f_5461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5461,c,av);}
/* posixwin.scm:881: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[178];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#current-user-id */
static void C_ccall f_5467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5467,c,av);}
/* posixwin.scm:882: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[179];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-control */
static void C_ccall f_5473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5473,c,av);}
/* posixwin.scm:884: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[14];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-link */
static void C_ccall f_5479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5479,c,av);}
/* posixwin.scm:885: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[17];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-lock */
static void C_ccall f_5485(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5485,c,av);}
/* posixwin.scm:886: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[18];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-lock/blocking */
static void C_ccall f_5491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5491,c,av);}
/* posixwin.scm:887: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[19];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-select */
static void C_ccall f_5497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5497,c,av);}
/* posixwin.scm:888: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[26];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-test-lock */
static void C_ccall f_5503(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5503,c,av);}
/* posixwin.scm:889: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[27];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-truncate */
static void C_ccall f_5509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5509,c,av);}
/* posixwin.scm:890: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[28];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#file-unlock */
static void C_ccall f_5515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5515,c,av);}
/* posixwin.scm:891: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[29];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#parent-process-id */
static void C_ccall f_5521(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5521,c,av);}
/* posixwin.scm:892: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[181];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process#process-fork */
static void C_ccall f_5527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5527,c,av);}
/* posixwin.scm:893: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[110];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#process-group-id */
static void C_ccall f_5533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5533,c,av);}
/* posixwin.scm:894: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[185];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process#process-signal */
static void C_ccall f_5539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5539,c,av);}
/* posixwin.scm:895: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[112];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.file.posix#read-symbolic-link */
static void C_ccall f_5545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5545,c,av);}
/* posixwin.scm:896: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#set-alarm! */
static void C_ccall f_5551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5551,c,av);}
/* posixwin.scm:897: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[134];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#set-root-directory! */
static void C_ccall f_5557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5557,c,av);}
/* posixwin.scm:898: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[175];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#set-signal-mask! */
static void C_ccall f_5563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5563,c,av);}
/* posixwin.scm:899: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[136];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#signal-mask */
static void C_ccall f_5569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5569,c,av);}
/* posixwin.scm:900: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[141];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#signal-mask! */
static void C_ccall f_5575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5575,c,av);}
/* posixwin.scm:901: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[142];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#signal-masked? */
static void C_ccall f_5581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5581,c,av);}
/* posixwin.scm:902: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[143];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process.signal#signal-unmask! */
static void C_ccall f_5587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5587,c,av);}
/* posixwin.scm:903: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[144];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.process-context.posix#user-information */
static void C_ccall f_5593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5593,c,av);}
/* posixwin.scm:904: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[186];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.time.posix#utc-time->seconds */
static void C_ccall f_5599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5599,c,av);}
/* posixwin.scm:905: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[82];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.time.posix#string->time */
static void C_ccall f_5605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5605,c,av);}
/* posixwin.scm:906: chicken.base#error */
t2=*((C_word*)lf[103]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[86];
av2[3]=lf[0];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.errno#errno */
static void C_ccall f_5623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5623,c,av);}
/* posix.scm:379: ##sys#errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[365]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[365]+1);
av2[1]=t1;
tp(2,av2);}}

/* a5667 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5668,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5672,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:638: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[405];
tp(4,av2);}}

/* k5670 in a5667 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5672,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(*((C_word*)lf[274]+1),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5676 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5677,c,av);}
a=C_alloc(4);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5684,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
/* posix-common.scm:563: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[408];
tp(4,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_5684(2,av2);}}}

/* k5682 in a5676 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5684(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5684,c,av);}
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

/* a5701 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5702,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5706,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:568: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[207]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[207]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[408];
tp(4,av2);}}

/* k5704 in a5701 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5706,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_umask(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5707 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5708(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5708,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5712,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5724,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* posix-common.scm:404: chicken.base#port? */
t5=*((C_word*)lf[199]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k5710 in a5707 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_5712,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5715,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_lessp(t1,C_fix(0)))){
/* posix-common.scm:413: posix-error */
t3=lf[188];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[193];
av2[3]=lf[410];
av2[4]=lf[411];
av2[5]=((C_word*)t0)[3];
f_2623(6,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5713 in k5710 in a5707 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5715(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5715,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5722 in a5707 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5724(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_5724,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(7));
t3=C_eqp(t2,lf[236]);
if(C_truep(t3)){
t4=C_ftell(&a,1,((C_word*)t0)[2]);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_5712(2,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_fix(-1);
f_5712(2,av2);}}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_lseek(((C_word*)t0)[2],C_fix(0),C_fix((C_word)SEEK_CUR));
f_5712(2,av2);}}
else{
/* posix-common.scm:411: ##sys#signal-hook */
t2=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[197];
av2[3]=lf[410];
av2[4]=lf[412];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* a5744 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5745,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5749,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:327: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[205]);}

/* k5747 in a5744 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5749,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_stat_perm);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5750 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5751(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5751,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5755,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:320: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[415]);}

/* k5753 in a5750 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5755,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_statbuf.st_gid);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5756 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5757,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5761,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* posix-common.scm:314: stat */
f_2641(t3,t2,C_SCHEME_FALSE,C_SCHEME_TRUE,lf[417]);}

/* k5759 in a5756 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_ccall f_5761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5761,c,av);}
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
C_word t4;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("posix"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_posix_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(2373))){
C_save(t1);
C_rereclaim2(2373*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,419);
lf[1]=C_decode_literal(C_heaptop,C_text("\376B\000\000/this function is not available on this platform"));
lf[2]=C_h_intern(&lf[2],5, C_text("posix"));
lf[3]=C_h_intern(&lf[3],19, C_text("chicken.file.posix#"));
lf[4]=C_h_intern(&lf[4],30, C_text("chicken.file.posix#create-fifo"));
lf[5]=C_h_intern(&lf[5],39, C_text("chicken.file.posix#create-symbolic-link"));
lf[6]=C_h_intern(&lf[6],37, C_text("chicken.file.posix#read-symbolic-link"));
lf[7]=C_h_intern(&lf[7],35, C_text("chicken.file.posix#duplicate-fileno"));
lf[8]=C_h_intern(&lf[8],30, C_text("chicken.file.posix#fcntl/dupfd"));
lf[9]=C_h_intern(&lf[9],30, C_text("chicken.file.posix#fcntl/getfd"));
lf[10]=C_h_intern(&lf[10],30, C_text("chicken.file.posix#fcntl/getfl"));
lf[11]=C_h_intern(&lf[11],30, C_text("chicken.file.posix#fcntl/setfd"));
lf[12]=C_h_intern(&lf[12],30, C_text("chicken.file.posix#fcntl/setfl"));
lf[13]=C_h_intern(&lf[13],29, C_text("chicken.file.posix#file-close"));
lf[14]=C_h_intern(&lf[14],31, C_text("chicken.file.posix#file-control"));
lf[15]=C_h_intern(&lf[15],37, C_text("chicken.file.posix#file-creation-mode"));
lf[16]=C_h_intern(&lf[16],29, C_text("chicken.file.posix#file-group"));
lf[17]=C_h_intern(&lf[17],28, C_text("chicken.file.posix#file-link"));
lf[18]=C_h_intern(&lf[18],28, C_text("chicken.file.posix#file-lock"));
lf[19]=C_h_intern(&lf[19],37, C_text("chicken.file.posix#file-lock/blocking"));
lf[20]=C_h_intern(&lf[20],31, C_text("chicken.file.posix#file-mkstemp"));
lf[21]=C_h_intern(&lf[21],28, C_text("chicken.file.posix#file-open"));
lf[22]=C_h_intern(&lf[22],29, C_text("chicken.file.posix#file-owner"));
lf[23]=C_h_intern(&lf[23],35, C_text("chicken.file.posix#file-permissions"));
lf[24]=C_h_intern(&lf[24],32, C_text("chicken.file.posix#file-position"));
lf[25]=C_h_intern(&lf[25],28, C_text("chicken.file.posix#file-read"));
lf[26]=C_h_intern(&lf[26],30, C_text("chicken.file.posix#file-select"));
lf[27]=C_h_intern(&lf[27],33, C_text("chicken.file.posix#file-test-lock"));
lf[28]=C_h_intern(&lf[28],32, C_text("chicken.file.posix#file-truncate"));
lf[29]=C_h_intern(&lf[29],30, C_text("chicken.file.posix#file-unlock"));
lf[30]=C_h_intern(&lf[30],29, C_text("chicken.file.posix#file-write"));
lf[31]=C_h_intern(&lf[31],28, C_text("chicken.file.posix#file-type"));
lf[32]=C_h_intern(&lf[32],32, C_text("chicken.file.posix#block-device\077"));
lf[33]=C_h_intern(&lf[33],36, C_text("chicken.file.posix#character-device\077"));
lf[34]=C_h_intern(&lf[34],29, C_text("chicken.file.posix#directory\077"));
lf[35]=C_h_intern(&lf[35],24, C_text("chicken.file.posix#fifo\077"));
lf[36]=C_h_intern(&lf[36],32, C_text("chicken.file.posix#regular-file\077"));
lf[37]=C_h_intern(&lf[37],26, C_text("chicken.file.posix#socket\077"));
lf[38]=C_h_intern(&lf[38],33, C_text("chicken.file.posix#symbolic-link\077"));
lf[39]=C_h_intern(&lf[39],32, C_text("chicken.file.posix#fileno/stderr"));
lf[40]=C_h_intern(&lf[40],31, C_text("chicken.file.posix#fileno/stdin"));
lf[41]=C_h_intern(&lf[41],32, C_text("chicken.file.posix#fileno/stdout"));
lf[42]=C_h_intern(&lf[42],35, C_text("chicken.file.posix#open-input-file\052"));
lf[43]=C_h_intern(&lf[43],36, C_text("chicken.file.posix#open-output-file\052"));
lf[44]=C_h_intern(&lf[44],30, C_text("chicken.file.posix#open/append"));
lf[45]=C_h_intern(&lf[45],30, C_text("chicken.file.posix#open/binary"));
lf[46]=C_h_intern(&lf[46],29, C_text("chicken.file.posix#open/creat"));
lf[47]=C_h_intern(&lf[47],28, C_text("chicken.file.posix#open/excl"));
lf[48]=C_h_intern(&lf[48],29, C_text("chicken.file.posix#open/fsync"));
lf[49]=C_h_intern(&lf[49],30, C_text("chicken.file.posix#open/noctty"));
lf[50]=C_h_intern(&lf[50],33, C_text("chicken.file.posix#open/noinherit"));
lf[51]=C_h_intern(&lf[51],32, C_text("chicken.file.posix#open/nonblock"));
lf[52]=C_h_intern(&lf[52],30, C_text("chicken.file.posix#open/rdonly"));
lf[53]=C_h_intern(&lf[53],28, C_text("chicken.file.posix#open/rdwr"));
lf[54]=C_h_intern(&lf[54],28, C_text("chicken.file.posix#open/read"));
lf[55]=C_h_intern(&lf[55],28, C_text("chicken.file.posix#open/sync"));
lf[56]=C_h_intern(&lf[56],28, C_text("chicken.file.posix#open/text"));
lf[57]=C_h_intern(&lf[57],29, C_text("chicken.file.posix#open/trunc"));
lf[58]=C_h_intern(&lf[58],29, C_text("chicken.file.posix#open/write"));
lf[59]=C_h_intern(&lf[59],30, C_text("chicken.file.posix#open/wronly"));
lf[60]=C_h_intern(&lf[60],29, C_text("chicken.file.posix#perm/irgrp"));
lf[61]=C_h_intern(&lf[61],29, C_text("chicken.file.posix#perm/iroth"));
lf[62]=C_h_intern(&lf[62],29, C_text("chicken.file.posix#perm/irusr"));
lf[63]=C_h_intern(&lf[63],29, C_text("chicken.file.posix#perm/irwxg"));
lf[64]=C_h_intern(&lf[64],29, C_text("chicken.file.posix#perm/irwxo"));
lf[65]=C_h_intern(&lf[65],29, C_text("chicken.file.posix#perm/irwxu"));
lf[66]=C_h_intern(&lf[66],29, C_text("chicken.file.posix#perm/isgid"));
lf[67]=C_h_intern(&lf[67],29, C_text("chicken.file.posix#perm/isuid"));
lf[68]=C_h_intern(&lf[68],29, C_text("chicken.file.posix#perm/isvtx"));
lf[69]=C_h_intern(&lf[69],29, C_text("chicken.file.posix#perm/iwgrp"));
lf[70]=C_h_intern(&lf[70],29, C_text("chicken.file.posix#perm/iwoth"));
lf[71]=C_h_intern(&lf[71],29, C_text("chicken.file.posix#perm/iwusr"));
lf[72]=C_h_intern(&lf[72],29, C_text("chicken.file.posix#perm/ixgrp"));
lf[73]=C_h_intern(&lf[73],29, C_text("chicken.file.posix#perm/ixoth"));
lf[74]=C_h_intern(&lf[74],29, C_text("chicken.file.posix#perm/ixusr"));
lf[75]=C_h_intern(&lf[75],31, C_text("chicken.file.posix#port->fileno"));
lf[76]=C_h_intern(&lf[76],27, C_text("chicken.file.posix#seek/cur"));
lf[77]=C_h_intern(&lf[77],27, C_text("chicken.file.posix#seek/end"));
lf[78]=C_h_intern(&lf[78],27, C_text("chicken.file.posix#seek/set"));
lf[79]=C_h_intern(&lf[79],37, C_text("chicken.file.posix#set-file-position!"));
lf[80]=C_h_intern(&lf[80],19, C_text("chicken.time.posix#"));
lf[81]=C_h_intern(&lf[81],36, C_text("chicken.time.posix#seconds->utc-time"));
lf[82]=C_h_intern(&lf[82],36, C_text("chicken.time.posix#utc-time->seconds"));
lf[83]=C_h_intern(&lf[83],38, C_text("chicken.time.posix#seconds->local-time"));
lf[84]=C_h_intern(&lf[84],34, C_text("chicken.time.posix#seconds->string"));
lf[85]=C_h_intern(&lf[85],38, C_text("chicken.time.posix#local-time->seconds"));
lf[86]=C_h_intern(&lf[86],31, C_text("chicken.time.posix#string->time"));
lf[87]=C_h_intern(&lf[87],31, C_text("chicken.time.posix#time->string"));
lf[88]=C_h_intern(&lf[88],46, C_text("chicken.time.posix#local-timezone-abbreviation"));
lf[89]=C_h_intern(&lf[89],16, C_text("chicken.process#"));
lf[90]=C_h_intern(&lf[90],22, C_text("chicken.process#system"));
lf[91]=C_h_intern(&lf[91],6, C_text("system"));
lf[92]=C_h_intern(&lf[92],23, C_text("##sys#signal-hook/errno"));
lf[93]=C_h_intern_kw(&lf[93],13, C_text("process-error"));
lf[94]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032`system\047 invocation failed"));
lf[95]=C_h_intern(&lf[95],18, C_text("##sys#update-errno"));
lf[96]=C_h_intern(&lf[96],23, C_text("chicken.process#system\052"));
lf[97]=C_h_intern(&lf[97],11, C_text("##sys#error"));
lf[98]=C_decode_literal(C_heaptop,C_text("\376B\000\0003shell invocation failed with non-zero return status"));
lf[99]=C_h_intern(&lf[99],18, C_text("chicken.process#qs"));
lf[100]=C_h_intern(&lf[100],7, C_text("mingw32"));
lf[101]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002\042\042"));
lf[102]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004\047\134\047\047"));
lf[103]=C_h_intern(&lf[103],18, C_text("chicken.base#error"));
lf[104]=C_h_intern(&lf[104],2, C_text("qs"));
lf[105]=C_decode_literal(C_heaptop,C_text("\376B\000\0004NUL character can not be represented in shell string"));
lf[106]=C_h_intern(&lf[106],20, C_text("scheme#string-append"));
lf[107]=C_h_intern(&lf[107],18, C_text("##sys#string->list"));
lf[108]=C_h_intern(&lf[108],33, C_text("chicken.platform#software-version"));
lf[109]=C_h_intern(&lf[109],31, C_text("chicken.process#process-execute"));
lf[110]=C_h_intern(&lf[110],28, C_text("chicken.process#process-fork"));
lf[111]=C_h_intern(&lf[111],27, C_text("chicken.process#process-run"));
lf[112]=C_h_intern(&lf[112],30, C_text("chicken.process#process-signal"));
lf[113]=C_h_intern(&lf[113],29, C_text("chicken.process#process-spawn"));
lf[114]=C_h_intern(&lf[114],28, C_text("chicken.process#process-wait"));
lf[115]=C_h_intern(&lf[115],36, C_text("chicken.process#call-with-input-pipe"));
lf[116]=C_h_intern(&lf[116],37, C_text("chicken.process#call-with-output-pipe"));
lf[117]=C_h_intern(&lf[117],32, C_text("chicken.process#close-input-pipe"));
lf[118]=C_h_intern(&lf[118],33, C_text("chicken.process#close-output-pipe"));
lf[119]=C_h_intern(&lf[119],27, C_text("chicken.process#create-pipe"));
lf[120]=C_h_intern(&lf[120],31, C_text("chicken.process#open-input-pipe"));
lf[121]=C_h_intern(&lf[121],32, C_text("chicken.process#open-output-pipe"));
lf[122]=C_h_intern(&lf[122],36, C_text("chicken.process#with-input-from-pipe"));
lf[123]=C_h_intern(&lf[123],35, C_text("chicken.process#with-output-to-pipe"));
lf[124]=C_h_intern(&lf[124],23, C_text("chicken.process#process"));
lf[125]=C_h_intern(&lf[125],24, C_text("chicken.process#process\052"));
lf[126]=C_h_intern(&lf[126],29, C_text("chicken.process#process-sleep"));
lf[127]=C_h_intern(&lf[127],24, C_text("chicken.process#pipe/buf"));
lf[128]=C_h_intern(&lf[128],29, C_text("chicken.process#spawn/overlay"));
lf[129]=C_h_intern(&lf[129],26, C_text("chicken.process#spawn/wait"));
lf[130]=C_h_intern(&lf[130],28, C_text("chicken.process#spawn/nowait"));
lf[131]=C_h_intern(&lf[131],29, C_text("chicken.process#spawn/nowaito"));
lf[132]=C_h_intern(&lf[132],28, C_text("chicken.process#spawn/detach"));
lf[133]=C_h_intern(&lf[133],23, C_text("chicken.process.signal#"));
lf[134]=C_h_intern(&lf[134],33, C_text("chicken.process.signal#set-alarm!"));
lf[135]=C_h_intern(&lf[135],42, C_text("chicken.process.signal#set-signal-handler!"));
lf[136]=C_h_intern(&lf[136],39, C_text("chicken.process.signal#set-signal-mask!"));
lf[137]=C_h_intern(&lf[137],37, C_text("chicken.process.signal#signal-handler"));
lf[138]=C_h_intern(&lf[138],42, C_text("chicken.process.signal#make-signal-handler"));
lf[139]=C_h_intern(&lf[139],36, C_text("chicken.process.signal#signal-ignore"));
lf[140]=C_h_intern(&lf[140],37, C_text("chicken.process.signal#signal-default"));
lf[141]=C_h_intern(&lf[141],34, C_text("chicken.process.signal#signal-mask"));
lf[142]=C_h_intern(&lf[142],35, C_text("chicken.process.signal#signal-mask!"));
lf[143]=C_h_intern(&lf[143],37, C_text("chicken.process.signal#signal-masked\077"));
lf[144]=C_h_intern(&lf[144],37, C_text("chicken.process.signal#signal-unmask!"));
lf[145]=C_h_intern(&lf[145],34, C_text("chicken.process.signal#signal/abrt"));
lf[146]=C_h_intern(&lf[146],34, C_text("chicken.process.signal#signal/alrm"));
lf[147]=C_h_intern(&lf[147],35, C_text("chicken.process.signal#signal/break"));
lf[148]=C_h_intern(&lf[148],33, C_text("chicken.process.signal#signal/bus"));
lf[149]=C_h_intern(&lf[149],34, C_text("chicken.process.signal#signal/chld"));
lf[150]=C_h_intern(&lf[150],34, C_text("chicken.process.signal#signal/cont"));
lf[151]=C_h_intern(&lf[151],33, C_text("chicken.process.signal#signal/fpe"));
lf[152]=C_h_intern(&lf[152],33, C_text("chicken.process.signal#signal/hup"));
lf[153]=C_h_intern(&lf[153],33, C_text("chicken.process.signal#signal/ill"));
lf[154]=C_h_intern(&lf[154],33, C_text("chicken.process.signal#signal/int"));
lf[155]=C_h_intern(&lf[155],32, C_text("chicken.process.signal#signal/io"));
lf[156]=C_h_intern(&lf[156],34, C_text("chicken.process.signal#signal/kill"));
lf[157]=C_h_intern(&lf[157],34, C_text("chicken.process.signal#signal/pipe"));
lf[158]=C_h_intern(&lf[158],34, C_text("chicken.process.signal#signal/prof"));
lf[159]=C_h_intern(&lf[159],34, C_text("chicken.process.signal#signal/quit"));
lf[160]=C_h_intern(&lf[160],34, C_text("chicken.process.signal#signal/segv"));
lf[161]=C_h_intern(&lf[161],34, C_text("chicken.process.signal#signal/stop"));
lf[162]=C_h_intern(&lf[162],34, C_text("chicken.process.signal#signal/term"));
lf[163]=C_h_intern(&lf[163],34, C_text("chicken.process.signal#signal/trap"));
lf[164]=C_h_intern(&lf[164],34, C_text("chicken.process.signal#signal/tstp"));
lf[165]=C_h_intern(&lf[165],33, C_text("chicken.process.signal#signal/urg"));
lf[166]=C_h_intern(&lf[166],34, C_text("chicken.process.signal#signal/usr1"));
lf[167]=C_h_intern(&lf[167],34, C_text("chicken.process.signal#signal/usr2"));
lf[168]=C_h_intern(&lf[168],36, C_text("chicken.process.signal#signal/vtalrm"));
lf[169]=C_h_intern(&lf[169],35, C_text("chicken.process.signal#signal/winch"));
lf[170]=C_h_intern(&lf[170],34, C_text("chicken.process.signal#signal/xcpu"));
lf[171]=C_h_intern(&lf[171],34, C_text("chicken.process.signal#signal/xfsz"));
lf[172]=C_h_intern(&lf[172],35, C_text("chicken.process.signal#signals-list"));
lf[173]=C_h_intern(&lf[173],30, C_text("chicken.process-context.posix#"));
lf[174]=C_h_intern(&lf[174],47, C_text("chicken.process-context.posix#change-directory\052"));
lf[175]=C_h_intern(&lf[175],49, C_text("chicken.process-context.posix#set-root-directory!"));
lf[176]=C_h_intern(&lf[176],56, C_text("chicken.process-context.posix#current-effective-group-id"));
lf[177]=C_h_intern(&lf[177],55, C_text("chicken.process-context.posix#current-effective-user-id"));
lf[178]=C_h_intern(&lf[178],46, C_text("chicken.process-context.posix#current-group-id"));
lf[179]=C_h_intern(&lf[179],45, C_text("chicken.process-context.posix#current-user-id"));
lf[180]=C_h_intern(&lf[180],48, C_text("chicken.process-context.posix#current-process-id"));
lf[181]=C_h_intern(&lf[181],47, C_text("chicken.process-context.posix#parent-process-id"));
lf[182]=C_h_intern(&lf[182],47, C_text("chicken.process-context.posix#current-user-name"));
lf[183]=C_h_intern(&lf[183],57, C_text("chicken.process-context.posix#current-effective-user-name"));
lf[184]=C_h_intern(&lf[184],44, C_text("chicken.process-context.posix#create-session"));
lf[185]=C_h_intern(&lf[185],46, C_text("chicken.process-context.posix#process-group-id"));
lf[186]=C_h_intern(&lf[186],46, C_text("chicken.process-context.posix#user-information"));
lf[187]=C_h_intern(&lf[187],14, C_text("chicken.posix#"));
lf[189]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 - "));
lf[190]=C_h_intern(&lf[190],19, C_text("##sys#peek-c-string"));
lf[191]=C_h_intern(&lf[191],17, C_text("##sys#posix-error"));
lf[193]=C_h_intern_kw(&lf[193],10, C_text("file-error"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot access file"));
lf[195]=C_h_intern(&lf[195],19, C_text("##sys#make-c-string"));
lf[196]=C_h_intern(&lf[196],17, C_text("##sys#signal-hook"));
lf[197]=C_h_intern_kw(&lf[197],10, C_text("type-error"));
lf[198]=C_decode_literal(C_heaptop,C_text("\376B\000\0000bad argument type - not a fixnum, port or string"));
lf[199]=C_h_intern(&lf[199],18, C_text("chicken.base#port\077"));
lf[200]=C_h_intern(&lf[200],28, C_text("chicken.file.posix#file-stat"));
lf[201]=C_h_intern(&lf[201],9, C_text("file-stat"));
lf[202]=C_h_intern(&lf[202],40, C_text("chicken.file.posix#set-file-permissions!"));
lf[203]=C_h_intern(&lf[203],21, C_text("set-file-permissions!"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036cannot change file permissions"));
lf[205]=C_h_intern(&lf[205],16, C_text("file-permissions"));
lf[206]=C_decode_literal(C_heaptop,C_text("\376B\000\0000bad argument type - not a fixnum, port or string"));
lf[207]=C_h_intern(&lf[207],18, C_text("##sys#check-fixnum"));
lf[208]=C_h_intern(&lf[208],41, C_text("chicken.file.posix#file-modification-time"));
lf[209]=C_h_intern(&lf[209],22, C_text("file-modification-time"));
lf[210]=C_h_intern(&lf[210],35, C_text("chicken.file.posix#file-access-time"));
lf[211]=C_h_intern(&lf[211],16, C_text("file-access-time"));
lf[212]=C_h_intern(&lf[212],35, C_text("chicken.file.posix#file-change-time"));
lf[213]=C_h_intern(&lf[213],16, C_text("file-change-time"));
lf[214]=C_h_intern(&lf[214],34, C_text("chicken.file.posix#set-file-times!"));
lf[215]=C_h_intern(&lf[215],15, C_text("set-file-times!"));
lf[216]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot set file times"));
lf[217]=C_h_intern(&lf[217],25, C_text("##sys#check-exact-integer"));
lf[218]=C_h_intern(&lf[218],28, C_text("chicken.time#current-seconds"));
lf[219]=C_h_intern(&lf[219],28, C_text("chicken.file.posix#file-size"));
lf[220]=C_h_intern(&lf[220],9, C_text("file-size"));
lf[221]=C_h_intern(&lf[221],34, C_text("chicken.file.posix#set-file-owner!"));
lf[222]=C_h_intern(&lf[222],15, C_text("set-file-owner!"));
lf[223]=C_h_intern(&lf[223],5, C_text("chown"));
lf[224]=C_h_intern(&lf[224],34, C_text("chicken.file.posix#set-file-group!"));
lf[225]=C_h_intern(&lf[225],15, C_text("set-file-group!"));
lf[226]=C_h_intern(&lf[226],12, C_text("regular-file"));
lf[227]=C_h_intern(&lf[227],13, C_text("symbolic-link"));
lf[228]=C_h_intern(&lf[228],9, C_text("directory"));
lf[229]=C_h_intern(&lf[229],16, C_text("character-device"));
lf[230]=C_h_intern(&lf[230],12, C_text("block-device"));
lf[231]=C_h_intern(&lf[231],4, C_text("fifo"));
lf[232]=C_h_intern(&lf[232],6, C_text("socket"));
lf[233]=C_h_intern(&lf[233],9, C_text("file-type"));
lf[234]=C_h_intern(&lf[234],18, C_text("set-file-position!"));
lf[235]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030cannot set file position"));
lf[236]=C_h_intern(&lf[236],6, C_text("stream"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid file"));
lf[238]=C_h_intern_kw(&lf[238],6, C_text("append"));
lf[239]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001a"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033invalid mode for input file"));
lf[241]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025invalid mode argument"));
lf[242]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001r"));
lf[243]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001w"));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[245]=C_h_intern(&lf[245],15, C_text("##sys#make-port"));
lf[246]=C_h_intern(&lf[246],23, C_text("##sys#stream-port-class"));
lf[247]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010(fdport)"));
lf[248]=C_h_intern(&lf[248],16, C_text("open-input-file\052"));
lf[249]=C_h_intern(&lf[249],17, C_text("open-output-file\052"));
lf[250]=C_h_intern(&lf[250],12, C_text("port->fileno"));
lf[251]=C_h_intern(&lf[251],15, C_text("##sys#port-data"));
lf[252]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot access file-descriptor of port"));
lf[253]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031port has no attached file"));
lf[254]=C_h_intern(&lf[254],27, C_text("##sys#peek-unsigned-integer"));
lf[255]=C_h_intern(&lf[255],16, C_text("duplicate-fileno"));
lf[256]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot duplicate file-descriptor"));
lf[257]=C_h_intern(&lf[257],17, C_text("change-directory\052"));
lf[258]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037cannot change current directory"));
lf[259]=C_h_intern(&lf[259],27, C_text("##sys#change-directory-hook"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025time vector too short"));
lf[263]=C_h_intern(&lf[263],19, C_text("seconds->local-time"));
lf[264]=C_h_intern(&lf[264],17, C_text("seconds->utc-time"));
lf[265]=C_h_intern(&lf[265],15, C_text("##sys#substring"));
lf[266]=C_h_intern(&lf[266],15, C_text("seconds->string"));
lf[267]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot convert seconds to string"));
lf[268]=C_h_intern(&lf[268],19, C_text("local-time->seconds"));
lf[269]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot convert time vector to seconds"));
lf[270]=C_h_intern(&lf[270],17, C_text("##sys#make-string"));
lf[271]=C_h_intern(&lf[271],12, C_text("time->string"));
lf[272]=C_decode_literal(C_heaptop,C_text("\376B\000\000 time formatting overflows buffer"));
lf[273]=C_decode_literal(C_heaptop,C_text("\376B\000\000$cannot convert time vector to string"));
lf[274]=C_h_intern(&lf[274],19, C_text("##sys#signal-vector"));
lf[275]=C_h_intern(&lf[275],19, C_text("set-signal-handler!"));
lf[276]=C_h_intern(&lf[276],25, C_text("##sys#add-event-to-queue!"));
lf[277]=C_h_intern(&lf[277],19, C_text("make-signal-handler"));
lf[278]=C_h_intern(&lf[278],20, C_text("##sys#get-next-event"));
lf[279]=C_h_intern(&lf[279],25, C_text("##sys#wait-for-next-event"));
lf[280]=C_h_intern(&lf[280],22, C_text("##sys#make-event-queue"));
lf[281]=C_h_intern(&lf[281],13, C_text("signal-ignore"));
lf[282]=C_h_intern(&lf[282],14, C_text("signal-default"));
lf[283]=C_h_intern(&lf[283],13, C_text("process-sleep"));
lf[284]=C_h_intern(&lf[284],12, C_text("process-wait"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376B\000\000 waiting for child process failed"));
lf[287]=C_h_intern(&lf[287],24, C_text("chicken.condition#signal"));
lf[289]=C_h_intern(&lf[289],34, C_text("chicken.memory#pointer-vector-set!"));
lf[290]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015Out of memory"));
lf[291]=C_h_intern(&lf[291],40, C_text("chicken.condition#with-exception-handler"));
lf[292]=C_h_intern(&lf[292],37, C_text("scheme#call-with-current-continuation"));
lf[293]=C_h_intern(&lf[293],34, C_text("chicken.memory#make-pointer-vector"));
lf[294]=C_h_intern(&lf[294],19, C_text("chicken.memory#free"));
lf[295]=C_h_intern(&lf[295],33, C_text("chicken.memory#pointer-vector-ref"));
lf[296]=C_h_intern(&lf[296],36, C_text("chicken.memory#pointer-vector-length"));
lf[299]=C_h_intern(&lf[299],3, C_text("map"));
lf[300]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001="));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open pipe"));
lf[302]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006(pipe)"));
lf[303]=C_h_intern(&lf[303],15, C_text("open-input-pipe"));
lf[304]=C_h_intern_kw(&lf[304],4, C_text("text"));
lf[305]=C_h_intern_kw(&lf[305],6, C_text("binary"));
lf[306]=C_decode_literal(C_heaptop,C_text("\376B\000\000#illegal input/output mode specifier"));
lf[307]=C_h_intern(&lf[307],16, C_text("open-output-pipe"));
lf[308]=C_h_intern(&lf[308],16, C_text("close-input-pipe"));
lf[309]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030error while closing pipe"));
lf[310]=C_h_intern(&lf[310],17, C_text("close-output-pipe"));
lf[311]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030error while closing pipe"));
lf[312]=C_h_intern(&lf[312],20, C_text("##sys#standard-input"));
lf[313]=C_h_intern(&lf[313],13, C_text("scheme#values"));
lf[314]=C_h_intern(&lf[314],18, C_text("##sys#dynamic-wind"));
lf[315]=C_h_intern(&lf[315],21, C_text("##sys#standard-output"));
lf[316]=C_h_intern(&lf[316],9, C_text("file-open"));
lf[317]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[318]=C_h_intern(&lf[318],24, C_text("##sys#dispatch-interrupt"));
lf[319]=C_h_intern(&lf[319],10, C_text("file-close"));
lf[320]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021cannot close file"));
lf[321]=C_h_intern(&lf[321],9, C_text("file-read"));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot read from file"));
lf[323]=C_decode_literal(C_heaptop,C_text("\376B\000\000(bad argument type - not a string or blob"));
lf[324]=C_h_intern(&lf[324],18, C_text("scheme#make-string"));
lf[325]=C_h_intern(&lf[325],10, C_text("file-write"));
lf[326]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot write to file"));
lf[327]=C_decode_literal(C_heaptop,C_text("\376B\000\000(bad argument type - not a string or blob"));
lf[328]=C_h_intern(&lf[328],12, C_text("file-mkstemp"));
lf[329]=C_decode_literal(C_heaptop,C_text("\376B\000\000$0123456789abcdefghijklmnopqrstuvwxyz"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034cannot create temporary file"));
lf[331]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026non-existent directory"));
lf[332]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020invalid template"));
lf[333]=C_h_intern(&lf[333],18, C_text("##sys#file-exists\077"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[335]=C_h_intern(&lf[335],35, C_text("chicken.pathname#pathname-directory"));
lf[336]=C_h_intern(&lf[336],18, C_text("scheme#string-copy"));
lf[337]=C_h_intern(&lf[337],11, C_text("create-pipe"));
lf[338]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot create pipe"));
lf[340]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot duplicate file descriptor"));
lf[342]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[343]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[344]=C_h_intern(&lf[344],15, C_text("process-execute"));
lf[345]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026cannot execute process"));
lf[346]=C_h_intern(&lf[346],13, C_text("process-spawn"));
lf[347]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot spawn process"));
lf[349]=C_h_intern(&lf[349],17, C_text("##sys#error/errno"));
lf[350]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot retrieve system directory"));
lf[351]=C_h_intern(&lf[351],48, C_text("chicken.process-context#get-environment-variable"));
lf[352]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007COMSPEC"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002/c"));
lf[354]=C_h_intern(&lf[354],11, C_text("process-run"));
lf[355]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026cannot execute process"));
lf[356]=C_h_intern(&lf[356],19, C_text("##sys#make-locative"));
lf[357]=C_h_intern(&lf[357],8, C_text("location"));
lf[358]=C_h_intern(&lf[358],33, C_text("chicken.string#string-intersperse"));
lf[359]=C_h_intern(&lf[359],7, C_text("process"));
lf[360]=C_h_intern(&lf[360],8, C_text("process\052"));
lf[361]=C_h_intern(&lf[361],17, C_text("current-user-name"));
lf[362]=C_decode_literal(C_heaptop,C_text("\376B\000\000!cannot retrieve current user-name"));
lf[363]=C_h_intern(&lf[363],14, C_text("chicken.errno#"));
lf[364]=C_h_intern(&lf[364],19, C_text("chicken.errno#errno"));
lf[365]=C_h_intern(&lf[365],11, C_text("##sys#errno"));
lf[366]=C_h_intern(&lf[366],24, C_text("chicken.errno#errno/2big"));
lf[367]=C_h_intern(&lf[367],25, C_text("chicken.errno#errno/acces"));
lf[368]=C_h_intern(&lf[368],25, C_text("chicken.errno#errno/again"));
lf[369]=C_h_intern(&lf[369],24, C_text("chicken.errno#errno/badf"));
lf[370]=C_h_intern(&lf[370],24, C_text("chicken.errno#errno/busy"));
lf[371]=C_h_intern(&lf[371],25, C_text("chicken.errno#errno/child"));
lf[372]=C_h_intern(&lf[372],26, C_text("chicken.errno#errno/deadlk"));
lf[373]=C_h_intern(&lf[373],23, C_text("chicken.errno#errno/dom"));
lf[374]=C_h_intern(&lf[374],25, C_text("chicken.errno#errno/exist"));
lf[375]=C_h_intern(&lf[375],25, C_text("chicken.errno#errno/fault"));
lf[376]=C_h_intern(&lf[376],24, C_text("chicken.errno#errno/fbig"));
lf[377]=C_h_intern(&lf[377],25, C_text("chicken.errno#errno/ilseq"));
lf[378]=C_h_intern(&lf[378],24, C_text("chicken.errno#errno/intr"));
lf[379]=C_h_intern(&lf[379],25, C_text("chicken.errno#errno/inval"));
lf[380]=C_h_intern(&lf[380],22, C_text("chicken.errno#errno/io"));
lf[381]=C_h_intern(&lf[381],25, C_text("chicken.errno#errno/isdir"));
lf[382]=C_h_intern(&lf[382],25, C_text("chicken.errno#errno/mfile"));
lf[383]=C_h_intern(&lf[383],25, C_text("chicken.errno#errno/mlink"));
lf[384]=C_h_intern(&lf[384],31, C_text("chicken.errno#errno/nametoolong"));
lf[385]=C_h_intern(&lf[385],25, C_text("chicken.errno#errno/nfile"));
lf[386]=C_h_intern(&lf[386],25, C_text("chicken.errno#errno/nodev"));
lf[387]=C_h_intern(&lf[387],25, C_text("chicken.errno#errno/noent"));
lf[388]=C_h_intern(&lf[388],26, C_text("chicken.errno#errno/noexec"));
lf[389]=C_h_intern(&lf[389],25, C_text("chicken.errno#errno/nolck"));
lf[390]=C_h_intern(&lf[390],25, C_text("chicken.errno#errno/nomem"));
lf[391]=C_h_intern(&lf[391],25, C_text("chicken.errno#errno/nospc"));
lf[392]=C_h_intern(&lf[392],25, C_text("chicken.errno#errno/nosys"));
lf[393]=C_h_intern(&lf[393],26, C_text("chicken.errno#errno/notdir"));
lf[394]=C_h_intern(&lf[394],28, C_text("chicken.errno#errno/notempty"));
lf[395]=C_h_intern(&lf[395],25, C_text("chicken.errno#errno/notty"));
lf[396]=C_h_intern(&lf[396],24, C_text("chicken.errno#errno/nxio"));
lf[397]=C_h_intern(&lf[397],24, C_text("chicken.errno#errno/perm"));
lf[398]=C_h_intern(&lf[398],24, C_text("chicken.errno#errno/pipe"));
lf[399]=C_h_intern(&lf[399],25, C_text("chicken.errno#errno/range"));
lf[400]=C_h_intern(&lf[400],24, C_text("chicken.errno#errno/rofs"));
lf[401]=C_h_intern(&lf[401],25, C_text("chicken.errno#errno/spipe"));
lf[402]=C_h_intern(&lf[402],24, C_text("chicken.errno#errno/srch"));
lf[403]=C_h_intern(&lf[403],30, C_text("chicken.errno#errno/wouldblock"));
lf[404]=C_h_intern(&lf[404],24, C_text("chicken.errno#errno/xdev"));
lf[405]=C_h_intern(&lf[405],14, C_text("signal-handler"));
lf[406]=C_h_intern(&lf[406],31, C_text("chicken.base#getter-with-setter"));
lf[407]=C_decode_literal(C_heaptop,C_text("\376B\000\000+(chicken.process.signal#signal-handler sig)"));
lf[408]=C_h_intern(&lf[408],18, C_text("file-creation-mode"));
lf[409]=C_decode_literal(C_heaptop,C_text("\376B\000\000,(chicken.file.posix#file-creation-mode mode)"));
lf[410]=C_h_intern(&lf[410],13, C_text("file-position"));
lf[411]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot retrieve file position of port"));
lf[412]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid file"));
lf[413]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047(chicken.file.posix#file-position port)"));
lf[414]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047(chicken.file.posix#file-permissions f)"));
lf[415]=C_h_intern(&lf[415],10, C_text("file-group"));
lf[416]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.file.posix#file-group f)"));
lf[417]=C_h_intern(&lf[417],10, C_text("file-owner"));
lf[418]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.file.posix#file-owner f)"));
C_register_lf2(lf,419,create_ptable());{}
t2=C_mutate(&lf[0] /* (set! c1715 ...) */,lf[1]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2294,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_scheduler_toplevel(2,av2);}}

/* va6260 in k4494 in loop in k4481 in k4472 */
static void C_fcall va6260(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,5)))){
C_save_and_reclaim_args((void *)trva6260,2,t0,t1);}
a=C_alloc(5);
t2=C_s_a_i_bitwise_ior(&a,2,t1,*((C_word*)lf[47]+1));
t3=C_fixnum_or(C_fix((C_word)S_IRUSR),C_fix((C_word)S_IWUSR));
t4=C_open(((C_word*)t0)[2],t2,t3);
t5=C_eqp(C_fix(-1),t4);
if(C_truep(t5)){
if(C_truep(C_fixnum_lessp(((C_word*)t0)[3],((C_word*)t0)[4]))){
/* posixwin.scm:602: loop */
t6=((C_word*)((C_word*)t0)[5])[1];
f_4488(t6,((C_word*)t0)[6],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}
else{
/* posixwin.scm:603: posix-error */
t6=lf[188];{
C_word av2[6];
av2[0]=t6;
av2[1]=((C_word*)t0)[6];
av2[2]=lf[193];
av2[3]=lf[328];
av2[4]=lf[330];
av2[5]=((C_word*)t0)[7];
f_2623(6,av2);}}}
else{
/* posixwin.scm:604: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=t4;
av2[3]=((C_word*)t0)[8];
C_values(4,av2);}}}

/* va6268 in chicken.file.posix#file-mkstemp */
static void C_fcall va6268(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(40,0,2)))){
C_save_and_reclaim_args((void *)trva6268,2,t0,t1);}
a=C_alloc(40);
t2=C_s_a_i_times(&a,2,t1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4474,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* posixwin.scm:574: scheme#string-copy */
t4=*((C_word*)lf[336]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* va6276 in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall va6276(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(184,0,8)))){
C_save_and_reclaim_args((void *)trva6276,2,t0,t1);}
a=C_alloc(184);
t2=C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IWOTH));
t3=C_mutate((C_word*)lf[21]+1 /* (set! chicken.file.posix#file-open ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4309,a[2]=t2,a[3]=((C_word)li98),tmp=(C_word)a,a+=4,tmp));
t4=C_mutate((C_word*)lf[13]+1 /* (set! chicken.file.posix#file-close ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4345,a[2]=((C_word)li100),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[25]+1 /* (set! chicken.file.posix#file-read ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4376,a[2]=((C_word)li101),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[30]+1 /* (set! chicken.file.posix#file-write ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4420,a[2]=((C_word)li102),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[20]+1 /* (set! chicken.file.posix#file-mkstemp ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4461,a[2]=((C_word)li108),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[119]+1 /* (set! chicken.process#create-pipe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4620,a[2]=((C_word)li109),tmp=(C_word)a,a+=3,tmp));
t9=C_set_block_item(lf[162] /* chicken.process.signal#signal/term */,0,C_fix((C_word)SIGTERM));
t10=C_set_block_item(lf[154] /* chicken.process.signal#signal/int */,0,C_fix((C_word)SIGINT));
t11=C_set_block_item(lf[151] /* chicken.process.signal#signal/fpe */,0,C_fix((C_word)SIGFPE));
t12=C_set_block_item(lf[153] /* chicken.process.signal#signal/ill */,0,C_fix((C_word)SIGILL));
t13=C_set_block_item(lf[160] /* chicken.process.signal#signal/segv */,0,C_fix((C_word)SIGSEGV));
t14=C_set_block_item(lf[145] /* chicken.process.signal#signal/abrt */,0,C_fix((C_word)SIGABRT));
t15=C_set_block_item(lf[147] /* chicken.process.signal#signal/break */,0,C_fix((C_word)SIGBREAK));
t16=C_set_block_item(lf[146] /* chicken.process.signal#signal/alrm */,0,C_fix(0));
t17=C_set_block_item(lf[148] /* chicken.process.signal#signal/bus */,0,C_fix(0));
t18=C_set_block_item(lf[149] /* chicken.process.signal#signal/chld */,0,C_fix(0));
t19=C_set_block_item(lf[150] /* chicken.process.signal#signal/cont */,0,C_fix(0));
t20=C_set_block_item(lf[152] /* chicken.process.signal#signal/hup */,0,C_fix(0));
t21=C_set_block_item(lf[155] /* chicken.process.signal#signal/io */,0,C_fix(0));
t22=C_set_block_item(lf[156] /* chicken.process.signal#signal/kill */,0,C_fix(0));
t23=C_set_block_item(lf[157] /* chicken.process.signal#signal/pipe */,0,C_fix(0));
t24=C_set_block_item(lf[158] /* chicken.process.signal#signal/prof */,0,C_fix(0));
t25=C_set_block_item(lf[159] /* chicken.process.signal#signal/quit */,0,C_fix(0));
t26=C_set_block_item(lf[161] /* chicken.process.signal#signal/stop */,0,C_fix(0));
t27=C_set_block_item(lf[163] /* chicken.process.signal#signal/trap */,0,C_fix(0));
t28=C_set_block_item(lf[164] /* chicken.process.signal#signal/tstp */,0,C_fix(0));
t29=C_set_block_item(lf[165] /* chicken.process.signal#signal/urg */,0,C_fix(0));
t30=C_set_block_item(lf[166] /* chicken.process.signal#signal/usr1 */,0,C_fix(0));
t31=C_set_block_item(lf[167] /* chicken.process.signal#signal/usr2 */,0,C_fix(0));
t32=C_set_block_item(lf[168] /* chicken.process.signal#signal/vtalrm */,0,C_fix(0));
t33=C_set_block_item(lf[169] /* chicken.process.signal#signal/winch */,0,C_fix(0));
t34=C_set_block_item(lf[170] /* chicken.process.signal#signal/xcpu */,0,C_fix(0));
t35=C_set_block_item(lf[171] /* chicken.process.signal#signal/xfsz */,0,C_fix(0));
t36=C_a_i_list7(&a,7,*((C_word*)lf[162]+1),*((C_word*)lf[154]+1),*((C_word*)lf[151]+1),*((C_word*)lf[153]+1),*((C_word*)lf[160]+1),*((C_word*)lf[145]+1),*((C_word*)lf[147]+1));
t37=C_mutate((C_word*)lf[172]+1 /* (set! chicken.process.signal#signals-list ...) */,t36);
t38=C_mutate(&lf[339] /* (set! chicken.posix#duplicate-fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4683,a[2]=((C_word)li110),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[88]+1 /* (set! chicken.time.posix#local-timezone-abbreviation ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4714,a[2]=((C_word)li111),tmp=(C_word)a,a+=3,tmp));
t40=C_set_block_item(lf[128] /* chicken.process#spawn/overlay */,0,C_fix((C_word)P_OVERLAY));
t41=C_set_block_item(lf[129] /* chicken.process#spawn/wait */,0,C_fix((C_word)P_WAIT));
t42=C_set_block_item(lf[130] /* chicken.process#spawn/nowait */,0,C_fix((C_word)P_NOWAIT));
t43=C_set_block_item(lf[131] /* chicken.process#spawn/nowaito */,0,C_fix((C_word)P_NOWAITO));
t44=C_set_block_item(lf[132] /* chicken.process#spawn/detach */,0,C_fix((C_word)P_DETACH));
t45=C_mutate(&lf[341] /* (set! chicken.posix#quote-arg-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4760,a[2]=((C_word)li113),tmp=(C_word)a,a+=3,tmp));
t46=C_mutate((C_word*)lf[109]+1 /* (set! chicken.process#process-execute ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4772,a[2]=((C_word)li116),tmp=(C_word)a,a+=3,tmp));
t47=C_mutate((C_word*)lf[113]+1 /* (set! chicken.process#process-spawn ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4852,a[2]=((C_word)li119),tmp=(C_word)a,a+=3,tmp));
t48=C_mutate(&lf[348] /* (set! chicken.posix#shell-command ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4935,a[2]=((C_word)li120),tmp=(C_word)a,a+=3,tmp));
t49=C_mutate((C_word*)lf[111]+1 /* (set! chicken.process#process-run ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4963,a[2]=((C_word)li121),tmp=(C_word)a,a+=3,tmp));
t50=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5187,a[2]=((C_word)li128),tmp=(C_word)a,a+=3,tmp);
t51=C_mutate((C_word*)lf[124]+1 /* (set! chicken.process#process ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5271,a[2]=t50,a[3]=((C_word)li129),tmp=(C_word)a,a+=4,tmp));
t52=C_mutate((C_word*)lf[125]+1 /* (set! chicken.process#process* ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5331,a[2]=t50,a[3]=((C_word)li130),tmp=(C_word)a,a+=4,tmp));
t53=C_mutate((C_word*)lf[182]+1 /* (set! chicken.process-context.posix#current-user-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5403,a[2]=((C_word)li131),tmp=(C_word)a,a+=3,tmp));
t54=C_mutate((C_word*)lf[4]+1 /* (set! chicken.file.posix#create-fifo ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5425,a[2]=((C_word)li132),tmp=(C_word)a,a+=3,tmp));
t55=C_mutate((C_word*)lf[184]+1 /* (set! chicken.process-context.posix#create-session ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5431,a[2]=((C_word)li133),tmp=(C_word)a,a+=3,tmp));
t56=C_mutate((C_word*)lf[5]+1 /* (set! chicken.file.posix#create-symbolic-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5437,a[2]=((C_word)li134),tmp=(C_word)a,a+=3,tmp));
t57=C_mutate((C_word*)lf[176]+1 /* (set! chicken.process-context.posix#current-effective-group-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5443,a[2]=((C_word)li135),tmp=(C_word)a,a+=3,tmp));
t58=C_mutate((C_word*)lf[177]+1 /* (set! chicken.process-context.posix#current-effective-user-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5449,a[2]=((C_word)li136),tmp=(C_word)a,a+=3,tmp));
t59=C_mutate((C_word*)lf[183]+1 /* (set! chicken.process-context.posix#current-effective-user-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5455,a[2]=((C_word)li137),tmp=(C_word)a,a+=3,tmp));
t60=C_mutate((C_word*)lf[178]+1 /* (set! chicken.process-context.posix#current-group-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5461,a[2]=((C_word)li138),tmp=(C_word)a,a+=3,tmp));
t61=C_mutate((C_word*)lf[179]+1 /* (set! chicken.process-context.posix#current-user-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5467,a[2]=((C_word)li139),tmp=(C_word)a,a+=3,tmp));
t62=C_mutate((C_word*)lf[14]+1 /* (set! chicken.file.posix#file-control ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5473,a[2]=((C_word)li140),tmp=(C_word)a,a+=3,tmp));
t63=C_mutate((C_word*)lf[17]+1 /* (set! chicken.file.posix#file-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5479,a[2]=((C_word)li141),tmp=(C_word)a,a+=3,tmp));
t64=C_mutate((C_word*)lf[18]+1 /* (set! chicken.file.posix#file-lock ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5485,a[2]=((C_word)li142),tmp=(C_word)a,a+=3,tmp));
t65=C_mutate((C_word*)lf[19]+1 /* (set! chicken.file.posix#file-lock/blocking ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5491,a[2]=((C_word)li143),tmp=(C_word)a,a+=3,tmp));
t66=C_mutate((C_word*)lf[26]+1 /* (set! chicken.file.posix#file-select ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5497,a[2]=((C_word)li144),tmp=(C_word)a,a+=3,tmp));
t67=C_mutate((C_word*)lf[27]+1 /* (set! chicken.file.posix#file-test-lock ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5503,a[2]=((C_word)li145),tmp=(C_word)a,a+=3,tmp));
t68=C_mutate((C_word*)lf[28]+1 /* (set! chicken.file.posix#file-truncate ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5509,a[2]=((C_word)li146),tmp=(C_word)a,a+=3,tmp));
t69=C_mutate((C_word*)lf[29]+1 /* (set! chicken.file.posix#file-unlock ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5515,a[2]=((C_word)li147),tmp=(C_word)a,a+=3,tmp));
t70=C_mutate((C_word*)lf[181]+1 /* (set! chicken.process-context.posix#parent-process-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5521,a[2]=((C_word)li148),tmp=(C_word)a,a+=3,tmp));
t71=C_mutate((C_word*)lf[110]+1 /* (set! chicken.process#process-fork ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5527,a[2]=((C_word)li149),tmp=(C_word)a,a+=3,tmp));
t72=C_mutate((C_word*)lf[185]+1 /* (set! chicken.process-context.posix#process-group-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5533,a[2]=((C_word)li150),tmp=(C_word)a,a+=3,tmp));
t73=C_mutate((C_word*)lf[112]+1 /* (set! chicken.process#process-signal ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5539,a[2]=((C_word)li151),tmp=(C_word)a,a+=3,tmp));
t74=C_mutate((C_word*)lf[6]+1 /* (set! chicken.file.posix#read-symbolic-link ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5545,a[2]=((C_word)li152),tmp=(C_word)a,a+=3,tmp));
t75=C_mutate((C_word*)lf[134]+1 /* (set! chicken.process.signal#set-alarm! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5551,a[2]=((C_word)li153),tmp=(C_word)a,a+=3,tmp));
t76=C_mutate((C_word*)lf[175]+1 /* (set! chicken.process-context.posix#set-root-directory! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5557,a[2]=((C_word)li154),tmp=(C_word)a,a+=3,tmp));
t77=C_mutate((C_word*)lf[136]+1 /* (set! chicken.process.signal#set-signal-mask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5563,a[2]=((C_word)li155),tmp=(C_word)a,a+=3,tmp));
t78=C_mutate((C_word*)lf[141]+1 /* (set! chicken.process.signal#signal-mask ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5569,a[2]=((C_word)li156),tmp=(C_word)a,a+=3,tmp));
t79=C_mutate((C_word*)lf[142]+1 /* (set! chicken.process.signal#signal-mask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5575,a[2]=((C_word)li157),tmp=(C_word)a,a+=3,tmp));
t80=C_mutate((C_word*)lf[143]+1 /* (set! chicken.process.signal#signal-masked? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5581,a[2]=((C_word)li158),tmp=(C_word)a,a+=3,tmp));
t81=C_mutate((C_word*)lf[144]+1 /* (set! chicken.process.signal#signal-unmask! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5587,a[2]=((C_word)li159),tmp=(C_word)a,a+=3,tmp));
t82=C_mutate((C_word*)lf[186]+1 /* (set! chicken.process-context.posix#user-information ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5593,a[2]=((C_word)li160),tmp=(C_word)a,a+=3,tmp));
t83=C_mutate((C_word*)lf[82]+1 /* (set! chicken.time.posix#utc-time->seconds ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5599,a[2]=((C_word)li161),tmp=(C_word)a,a+=3,tmp));
t84=C_mutate((C_word*)lf[86]+1 /* (set! chicken.time.posix#string->time ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5605,a[2]=((C_word)li162),tmp=(C_word)a,a+=3,tmp));
t85=C_set_block_item(lf[8] /* chicken.file.posix#fcntl/dupfd */,0,C_fix(0));
t86=C_set_block_item(lf[9] /* chicken.file.posix#fcntl/getfd */,0,C_fix(0));
t87=C_set_block_item(lf[11] /* chicken.file.posix#fcntl/setfd */,0,C_fix(0));
t88=C_set_block_item(lf[10] /* chicken.file.posix#fcntl/getfl */,0,C_fix(0));
t89=C_set_block_item(lf[12] /* chicken.file.posix#fcntl/setfl */,0,C_fix(0));
t90=C_set_block_item(lf[49] /* chicken.file.posix#open/noctty */,0,C_fix(0));
t91=C_set_block_item(lf[51] /* chicken.file.posix#open/nonblock */,0,C_fix(0));
t92=C_set_block_item(lf[48] /* chicken.file.posix#open/fsync */,0,C_fix(0));
t93=C_set_block_item(lf[55] /* chicken.file.posix#open/sync */,0,C_fix(0));
t94=C_set_block_item(lf[66] /* chicken.file.posix#perm/isgid */,0,C_fix(0));
t95=C_set_block_item(lf[67] /* chicken.file.posix#perm/isuid */,0,C_fix(0));
t96=C_set_block_item(lf[68] /* chicken.file.posix#perm/isvtx */,0,C_fix(0));
t97=C_a_i_provide(&a,1,lf[363]);
t98=C_mutate((C_word*)lf[364]+1 /* (set! chicken.errno#errno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5623,a[2]=((C_word)li163),tmp=(C_word)a,a+=3,tmp));
t99=C_set_block_item(lf[366] /* chicken.errno#errno/2big */,0,C_fix((C_word)E2BIG));
t100=C_set_block_item(lf[367] /* chicken.errno#errno/acces */,0,C_fix((C_word)EACCES));
t101=C_set_block_item(lf[368] /* chicken.errno#errno/again */,0,C_fix((C_word)EAGAIN));
t102=C_set_block_item(lf[369] /* chicken.errno#errno/badf */,0,C_fix((C_word)EBADF));
t103=C_set_block_item(lf[370] /* chicken.errno#errno/busy */,0,C_fix((C_word)EBUSY));
t104=C_set_block_item(lf[371] /* chicken.errno#errno/child */,0,C_fix((C_word)ECHILD));
t105=C_set_block_item(lf[372] /* chicken.errno#errno/deadlk */,0,C_fix((C_word)EDEADLK));
t106=C_set_block_item(lf[373] /* chicken.errno#errno/dom */,0,C_fix((C_word)EDOM));
t107=C_set_block_item(lf[374] /* chicken.errno#errno/exist */,0,C_fix((C_word)EEXIST));
t108=C_set_block_item(lf[375] /* chicken.errno#errno/fault */,0,C_fix((C_word)EFAULT));
t109=C_set_block_item(lf[376] /* chicken.errno#errno/fbig */,0,C_fix((C_word)EFBIG));
t110=C_set_block_item(lf[377] /* chicken.errno#errno/ilseq */,0,C_fix((C_word)EILSEQ));
t111=C_set_block_item(lf[378] /* chicken.errno#errno/intr */,0,C_fix((C_word)EINTR));
t112=C_set_block_item(lf[379] /* chicken.errno#errno/inval */,0,C_fix((C_word)EINVAL));
t113=C_set_block_item(lf[380] /* chicken.errno#errno/io */,0,C_fix((C_word)EIO));
t114=C_set_block_item(lf[381] /* chicken.errno#errno/isdir */,0,C_fix((C_word)EISDIR));
t115=C_set_block_item(lf[382] /* chicken.errno#errno/mfile */,0,C_fix((C_word)EMFILE));
t116=C_set_block_item(lf[383] /* chicken.errno#errno/mlink */,0,C_fix((C_word)EMLINK));
t117=C_set_block_item(lf[384] /* chicken.errno#errno/nametoolong */,0,C_fix((C_word)ENAMETOOLONG));
t118=C_set_block_item(lf[385] /* chicken.errno#errno/nfile */,0,C_fix((C_word)ENFILE));
t119=C_set_block_item(lf[386] /* chicken.errno#errno/nodev */,0,C_fix((C_word)ENODEV));
t120=C_set_block_item(lf[387] /* chicken.errno#errno/noent */,0,C_fix((C_word)ENOENT));
t121=C_set_block_item(lf[388] /* chicken.errno#errno/noexec */,0,C_fix((C_word)ENOEXEC));
t122=C_set_block_item(lf[389] /* chicken.errno#errno/nolck */,0,C_fix((C_word)ENOLCK));
t123=C_set_block_item(lf[390] /* chicken.errno#errno/nomem */,0,C_fix((C_word)ENOMEM));
t124=C_set_block_item(lf[391] /* chicken.errno#errno/nospc */,0,C_fix((C_word)ENOSPC));
t125=C_set_block_item(lf[392] /* chicken.errno#errno/nosys */,0,C_fix((C_word)ENOSYS));
t126=C_set_block_item(lf[393] /* chicken.errno#errno/notdir */,0,C_fix((C_word)ENOTDIR));
t127=C_set_block_item(lf[394] /* chicken.errno#errno/notempty */,0,C_fix((C_word)ENOTEMPTY));
t128=C_set_block_item(lf[395] /* chicken.errno#errno/notty */,0,C_fix((C_word)ENOTTY));
t129=C_set_block_item(lf[396] /* chicken.errno#errno/nxio */,0,C_fix((C_word)ENXIO));
t130=C_set_block_item(lf[397] /* chicken.errno#errno/perm */,0,C_fix((C_word)EPERM));
t131=C_set_block_item(lf[398] /* chicken.errno#errno/pipe */,0,C_fix((C_word)EPIPE));
t132=C_set_block_item(lf[399] /* chicken.errno#errno/range */,0,C_fix((C_word)ERANGE));
t133=C_set_block_item(lf[400] /* chicken.errno#errno/rofs */,0,C_fix((C_word)EROFS));
t134=C_set_block_item(lf[401] /* chicken.errno#errno/spipe */,0,C_fix((C_word)ESPIPE));
t135=C_set_block_item(lf[402] /* chicken.errno#errno/srch */,0,C_fix((C_word)ESRCH));
t136=C_set_block_item(lf[403] /* chicken.errno#errno/wouldblock */,0,C_fix((C_word)EWOULDBLOCK));
t137=C_set_block_item(lf[404] /* chicken.errno#errno/xdev */,0,C_fix((C_word)EXDEV));
t138=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t138;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t138+1)))(2,av2);}}

/* va6278 in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall va6278(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva6278,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va6276(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IROTH)));}

/* va6280 in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall va6280(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva6280,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va6278(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IWGRP)));}

/* va6282 in k3541 in k3306 in k3089 in k2872 in k2868 in k2864 in k2310 in k2307 in k2304 in k2301 in k2298 in k2295 in k2292 */
static void C_fcall va6282(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,1)))){
C_save_and_reclaim_args((void *)trva6282,2,t0,t1);}
a=C_alloc(5);
t2=((C_word*)t0)[2];
va6280(t2,C_s_a_i_bitwise_ior(&a,2,t1,C_fix((C_word)S_IRGRP)));}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[370] = {
{C_text("f6287:posix_2escm"),(void*)f6287},
{C_text("f6291:posix_2escm"),(void*)f6291},
{C_text("f_2294:posix_2escm"),(void*)f_2294},
{C_text("f_2297:posix_2escm"),(void*)f_2297},
{C_text("f_2300:posix_2escm"),(void*)f_2300},
{C_text("f_2303:posix_2escm"),(void*)f_2303},
{C_text("f_2306:posix_2escm"),(void*)f_2306},
{C_text("f_2309:posix_2escm"),(void*)f_2309},
{C_text("f_2312:posix_2escm"),(void*)f_2312},
{C_text("f_2398:posix_2escm"),(void*)f_2398},
{C_text("f_2415:posix_2escm"),(void*)f_2415},
{C_text("f_2417:posix_2escm"),(void*)f_2417},
{C_text("f_2421:posix_2escm"),(void*)f_2421},
{C_text("f_2433:posix_2escm"),(void*)f_2433},
{C_text("f_2437:posix_2escm"),(void*)f_2437},
{C_text("f_2447:posix_2escm"),(void*)f_2447},
{C_text("f_2468:posix_2escm"),(void*)f_2468},
{C_text("f_2471:posix_2escm"),(void*)f_2471},
{C_text("f_2482:posix_2escm"),(void*)f_2482},
{C_text("f_2488:posix_2escm"),(void*)f_2488},
{C_text("f_2513:posix_2escm"),(void*)f_2513},
{C_text("f_2623:posix_2escm"),(void*)f_2623},
{C_text("f_2627:posix_2escm"),(void*)f_2627},
{C_text("f_2634:posix_2escm"),(void*)f_2634},
{C_text("f_2638:posix_2escm"),(void*)f_2638},
{C_text("f_2641:posix_2escm"),(void*)f_2641},
{C_text("f_2645:posix_2escm"),(void*)f_2645},
{C_text("f_2666:posix_2escm"),(void*)f_2666},
{C_text("f_2670:posix_2escm"),(void*)f_2670},
{C_text("f_2679:posix_2escm"),(void*)f_2679},
{C_text("f_2687:posix_2escm"),(void*)f_2687},
{C_text("f_2694:posix_2escm"),(void*)f_2694},
{C_text("f_2705:posix_2escm"),(void*)f_2705},
{C_text("f_2709:posix_2escm"),(void*)f_2709},
{C_text("f_2712:posix_2escm"),(void*)f_2712},
{C_text("f_2730:posix_2escm"),(void*)f_2730},
{C_text("f_2734:posix_2escm"),(void*)f_2734},
{C_text("f_2744:posix_2escm"),(void*)f_2744},
{C_text("f_2749:posix_2escm"),(void*)f_2749},
{C_text("f_2753:posix_2escm"),(void*)f_2753},
{C_text("f_2755:posix_2escm"),(void*)f_2755},
{C_text("f_2759:posix_2escm"),(void*)f_2759},
{C_text("f_2761:posix_2escm"),(void*)f_2761},
{C_text("f_2765:posix_2escm"),(void*)f_2765},
{C_text("f_2767:posix_2escm"),(void*)f_2767},
{C_text("f_2771:posix_2escm"),(void*)f_2771},
{C_text("f_2783:posix_2escm"),(void*)f_2783},
{C_text("f_2786:posix_2escm"),(void*)f_2786},
{C_text("f_2792:posix_2escm"),(void*)f_2792},
{C_text("f_2802:posix_2escm"),(void*)f_2802},
{C_text("f_2846:posix_2escm"),(void*)f_2846},
{C_text("f_2850:posix_2escm"),(void*)f_2850},
{C_text("f_2852:posix_2escm"),(void*)f_2852},
{C_text("f_2858:posix_2escm"),(void*)f_2858},
{C_text("f_2866:posix_2escm"),(void*)f_2866},
{C_text("f_2870:posix_2escm"),(void*)f_2870},
{C_text("f_2874:posix_2escm"),(void*)f_2874},
{C_text("f_2876:posix_2escm"),(void*)f_2876},
{C_text("f_2895:posix_2escm"),(void*)f_2895},
{C_text("f_2963:posix_2escm"),(void*)f_2963},
{C_text("f_2971:posix_2escm"),(void*)f_2971},
{C_text("f_2973:posix_2escm"),(void*)f_2973},
{C_text("f_2981:posix_2escm"),(void*)f_2981},
{C_text("f_2983:posix_2escm"),(void*)f_2983},
{C_text("f_2991:posix_2escm"),(void*)f_2991},
{C_text("f_2993:posix_2escm"),(void*)f_2993},
{C_text("f_3001:posix_2escm"),(void*)f_3001},
{C_text("f_3003:posix_2escm"),(void*)f_3003},
{C_text("f_3011:posix_2escm"),(void*)f_3011},
{C_text("f_3013:posix_2escm"),(void*)f_3013},
{C_text("f_3021:posix_2escm"),(void*)f_3021},
{C_text("f_3023:posix_2escm"),(void*)f_3023},
{C_text("f_3031:posix_2escm"),(void*)f_3031},
{C_text("f_3036:posix_2escm"),(void*)f_3036},
{C_text("f_3043:posix_2escm"),(void*)f_3043},
{C_text("f_3046:posix_2escm"),(void*)f_3046},
{C_text("f_3052:posix_2escm"),(void*)f_3052},
{C_text("f_3058:posix_2escm"),(void*)f_3058},
{C_text("f_3091:posix_2escm"),(void*)f_3091},
{C_text("f_3119:posix_2escm"),(void*)f_3119},
{C_text("f_3127:posix_2escm"),(void*)f_3127},
{C_text("f_3156:posix_2escm"),(void*)f_3156},
{C_text("f_3169:posix_2escm"),(void*)f_3169},
{C_text("f_3175:posix_2escm"),(void*)f_3175},
{C_text("f_3179:posix_2escm"),(void*)f_3179},
{C_text("f_3187:posix_2escm"),(void*)f_3187},
{C_text("f_3189:posix_2escm"),(void*)f_3189},
{C_text("f_3193:posix_2escm"),(void*)f_3193},
{C_text("f_3201:posix_2escm"),(void*)f_3201},
{C_text("f_3203:posix_2escm"),(void*)f_3203},
{C_text("f_3219:posix_2escm"),(void*)f_3219},
{C_text("f_3228:posix_2escm"),(void*)f_3228},
{C_text("f_3242:posix_2escm"),(void*)f_3242},
{C_text("f_3248:posix_2escm"),(void*)f_3248},
{C_text("f_3252:posix_2escm"),(void*)f_3252},
{C_text("f_3255:posix_2escm"),(void*)f_3255},
{C_text("f_3258:posix_2escm"),(void*)f_3258},
{C_text("f_3273:posix_2escm"),(void*)f_3273},
{C_text("f_3275:posix_2escm"),(void*)f_3275},
{C_text("f_3278:posix_2escm"),(void*)f_3278},
{C_text("f_3282:posix_2escm"),(void*)f_3282},
{C_text("f_3285:posix_2escm"),(void*)f_3285},
{C_text("f_3294:posix_2escm"),(void*)f_3294},
{C_text("f_3308:posix_2escm"),(void*)f_3308},
{C_text("f_3311:posix_2escm"),(void*)f_3311},
{C_text("f_3330:posix_2escm"),(void*)f_3330},
{C_text("f_3334:posix_2escm"),(void*)f_3334},
{C_text("f_3337:posix_2escm"),(void*)f_3337},
{C_text("f_3351:posix_2escm"),(void*)f_3351},
{C_text("f_3355:posix_2escm"),(void*)f_3355},
{C_text("f_3358:posix_2escm"),(void*)f_3358},
{C_text("f_3383:posix_2escm"),(void*)f_3383},
{C_text("f_3387:posix_2escm"),(void*)f_3387},
{C_text("f_3390:posix_2escm"),(void*)f_3390},
{C_text("f_3393:posix_2escm"),(void*)f_3393},
{C_text("f_3421:posix_2escm"),(void*)f_3421},
{C_text("f_3425:posix_2escm"),(void*)f_3425},
{C_text("f_3429:posix_2escm"),(void*)f_3429},
{C_text("f_3466:posix_2escm"),(void*)f_3466},
{C_text("f_3473:posix_2escm"),(void*)f_3473},
{C_text("f_3482:posix_2escm"),(void*)f_3482},
{C_text("f_3492:posix_2escm"),(void*)f_3492},
{C_text("f_3496:posix_2escm"),(void*)f_3496},
{C_text("f_3499:posix_2escm"),(void*)f_3499},
{C_text("f_3520:posix_2escm"),(void*)f_3520},
{C_text("f_3528:posix_2escm"),(void*)f_3528},
{C_text("f_3532:posix_2escm"),(void*)f_3532},
{C_text("f_3543:posix_2escm"),(void*)f_3543},
{C_text("f_3545:posix_2escm"),(void*)f_3545},
{C_text("f_3549:posix_2escm"),(void*)f_3549},
{C_text("f_3550:posix_2escm"),(void*)f_3550},
{C_text("f_3554:posix_2escm"),(void*)f_3554},
{C_text("f_3559:posix_2escm"),(void*)f_3559},
{C_text("f_3566:posix_2escm"),(void*)f_3566},
{C_text("f_3567:posix_2escm"),(void*)f_3567},
{C_text("f_3588:posix_2escm"),(void*)f_3588},
{C_text("f_3598:posix_2escm"),(void*)f_3598},
{C_text("f_3611:posix_2escm"),(void*)f_3611},
{C_text("f_3615:posix_2escm"),(void*)f_3615},
{C_text("f_3620:posix_2escm"),(void*)f_3620},
{C_text("f_3624:posix_2escm"),(void*)f_3624},
{C_text("f_3629:posix_2escm"),(void*)f_3629},
{C_text("f_3633:posix_2escm"),(void*)f_3633},
{C_text("f_3635:posix_2escm"),(void*)f_3635},
{C_text("f_3654:posix_2escm"),(void*)f_3654},
{C_text("f_3659:posix_2escm"),(void*)f_3659},
{C_text("f_3665:posix_2escm"),(void*)f_3665},
{C_text("f_3706:posix_2escm"),(void*)f_3706},
{C_text("f_3714:posix_2escm"),(void*)f_3714},
{C_text("f_3717:posix_2escm"),(void*)f_3717},
{C_text("f_3722:posix_2escm"),(void*)f_3722},
{C_text("f_3728:posix_2escm"),(void*)f_3728},
{C_text("f_3734:posix_2escm"),(void*)f_3734},
{C_text("f_3738:posix_2escm"),(void*)f_3738},
{C_text("f_3743:posix_2escm"),(void*)f_3743},
{C_text("f_3745:posix_2escm"),(void*)f_3745},
{C_text("f_3749:posix_2escm"),(void*)f_3749},
{C_text("f_3751:posix_2escm"),(void*)f_3751},
{C_text("f_3767:posix_2escm"),(void*)f_3767},
{C_text("f_3773:posix_2escm"),(void*)f_3773},
{C_text("f_3776:posix_2escm"),(void*)f_3776},
{C_text("f_3792:posix_2escm"),(void*)f_3792},
{C_text("f_3802:posix_2escm"),(void*)f_3802},
{C_text("f_3808:posix_2escm"),(void*)f_3808},
{C_text("f_3819:posix_2escm"),(void*)f_3819},
{C_text("f_3823:posix_2escm"),(void*)f_3823},
{C_text("f_3827:posix_2escm"),(void*)f_3827},
{C_text("f_3832:posix_2escm"),(void*)f_3832},
{C_text("f_3842:posix_2escm"),(void*)f_3842},
{C_text("f_3845:posix_2escm"),(void*)f_3845},
{C_text("f_3857:posix_2escm"),(void*)f_3857},
{C_text("f_3862:posix_2escm"),(void*)f_3862},
{C_text("f_3881:posix_2escm"),(void*)f_3881},
{C_text("f_3904:posix_2escm"),(void*)f_3904},
{C_text("f_3906:posix_2escm"),(void*)f_3906},
{C_text("f_3913:posix_2escm"),(void*)f_3913},
{C_text("f_3916:posix_2escm"),(void*)f_3916},
{C_text("f_3921:posix_2escm"),(void*)f_3921},
{C_text("f_3927:posix_2escm"),(void*)f_3927},
{C_text("f_3933:posix_2escm"),(void*)f_3933},
{C_text("f_3937:posix_2escm"),(void*)f_3937},
{C_text("f_3940:posix_2escm"),(void*)f_3940},
{C_text("f_3948:posix_2escm"),(void*)f_3948},
{C_text("f_3954:posix_2escm"),(void*)f_3954},
{C_text("f_3958:posix_2escm"),(void*)f_3958},
{C_text("f_3965:posix_2escm"),(void*)f_3965},
{C_text("f_3968:posix_2escm"),(void*)f_3968},
{C_text("f_3972:posix_2escm"),(void*)f_3972},
{C_text("f_3993:posix_2escm"),(void*)f_3993},
{C_text("f_3995:posix_2escm"),(void*)f_3995},
{C_text("f_4020:posix_2escm"),(void*)f_4020},
{C_text("f_4029:posix_2escm"),(void*)f_4029},
{C_text("f_4035:posix_2escm"),(void*)f_4035},
{C_text("f_4060:posix_2escm"),(void*)f_4060},
{C_text("f_4073:posix_2escm"),(void*)f_4073},
{C_text("f_4079:posix_2escm"),(void*)f_4079},
{C_text("f_4093:posix_2escm"),(void*)f_4093},
{C_text("f_4100:posix_2escm"),(void*)f_4100},
{C_text("f_4110:posix_2escm"),(void*)f_4110},
{C_text("f_4119:posix_2escm"),(void*)f_4119},
{C_text("f_4133:posix_2escm"),(void*)f_4133},
{C_text("f_4140:posix_2escm"),(void*)f_4140},
{C_text("f_4150:posix_2escm"),(void*)f_4150},
{C_text("f_4159:posix_2escm"),(void*)f_4159},
{C_text("f_4166:posix_2escm"),(void*)f_4166},
{C_text("f_4174:posix_2escm"),(void*)f_4174},
{C_text("f_4181:posix_2escm"),(void*)f_4181},
{C_text("f_4189:posix_2escm"),(void*)f_4189},
{C_text("f_4193:posix_2escm"),(void*)f_4193},
{C_text("f_4198:posix_2escm"),(void*)f_4198},
{C_text("f_4203:posix_2escm"),(void*)f_4203},
{C_text("f_4209:posix_2escm"),(void*)f_4209},
{C_text("f_4213:posix_2escm"),(void*)f_4213},
{C_text("f_4218:posix_2escm"),(void*)f_4218},
{C_text("f_4223:posix_2escm"),(void*)f_4223},
{C_text("f_4227:posix_2escm"),(void*)f_4227},
{C_text("f_4232:posix_2escm"),(void*)f_4232},
{C_text("f_4238:posix_2escm"),(void*)f_4238},
{C_text("f_4242:posix_2escm"),(void*)f_4242},
{C_text("f_4247:posix_2escm"),(void*)f_4247},
{C_text("f_4251:posix_2escm"),(void*)f_4251},
{C_text("f_4256:posix_2escm"),(void*)f_4256},
{C_text("f_4262:posix_2escm"),(void*)f_4262},
{C_text("f_4266:posix_2escm"),(void*)f_4266},
{C_text("f_4271:posix_2escm"),(void*)f_4271},
{C_text("f_4275:posix_2escm"),(void*)f_4275},
{C_text("f_4280:posix_2escm"),(void*)f_4280},
{C_text("f_4285:posix_2escm"),(void*)f_4285},
{C_text("f_4291:posix_2escm"),(void*)f_4291},
{C_text("f_4295:posix_2escm"),(void*)f_4295},
{C_text("f_4300:posix_2escm"),(void*)f_4300},
{C_text("f_4309:posix_2escm"),(void*)f_4309},
{C_text("f_4319:posix_2escm"),(void*)f_4319},
{C_text("f_4322:posix_2escm"),(void*)f_4322},
{C_text("f_4326:posix_2escm"),(void*)f_4326},
{C_text("f_4329:posix_2escm"),(void*)f_4329},
{C_text("f_4339:posix_2escm"),(void*)f_4339},
{C_text("f_4345:posix_2escm"),(void*)f_4345},
{C_text("f_4349:posix_2escm"),(void*)f_4349},
{C_text("f_4354:posix_2escm"),(void*)f_4354},
{C_text("f_4376:posix_2escm"),(void*)f_4376},
{C_text("f_4380:posix_2escm"),(void*)f_4380},
{C_text("f_4383:posix_2escm"),(void*)f_4383},
{C_text("f_4386:posix_2escm"),(void*)f_4386},
{C_text("f_4389:posix_2escm"),(void*)f_4389},
{C_text("f_4392:posix_2escm"),(void*)f_4392},
{C_text("f_4405:posix_2escm"),(void*)f_4405},
{C_text("f_4420:posix_2escm"),(void*)f_4420},
{C_text("f_4424:posix_2escm"),(void*)f_4424},
{C_text("f_4427:posix_2escm"),(void*)f_4427},
{C_text("f_4433:posix_2escm"),(void*)f_4433},
{C_text("f_4436:posix_2escm"),(void*)f_4436},
{C_text("f_4446:posix_2escm"),(void*)f_4446},
{C_text("f_4461:posix_2escm"),(void*)f_4461},
{C_text("f_4474:posix_2escm"),(void*)f_4474},
{C_text("f_4483:posix_2escm"),(void*)f_4483},
{C_text("f_4488:posix_2escm"),(void*)f_4488},
{C_text("f_4496:posix_2escm"),(void*)f_4496},
{C_text("f_4535:posix_2escm"),(void*)f_4535},
{C_text("f_4576:posix_2escm"),(void*)f_4576},
{C_text("f_4580:posix_2escm"),(void*)f_4580},
{C_text("f_4589:posix_2escm"),(void*)f_4589},
{C_text("f_4620:posix_2escm"),(void*)f_4620},
{C_text("f_4627:posix_2escm"),(void*)f_4627},
{C_text("f_4640:posix_2escm"),(void*)f_4640},
{C_text("f_4683:posix_2escm"),(void*)f_4683},
{C_text("f_4687:posix_2escm"),(void*)f_4687},
{C_text("f_4690:posix_2escm"),(void*)f_4690},
{C_text("f_4693:posix_2escm"),(void*)f_4693},
{C_text("f_4703:posix_2escm"),(void*)f_4703},
{C_text("f_4712:posix_2escm"),(void*)f_4712},
{C_text("f_4714:posix_2escm"),(void*)f_4714},
{C_text("f_4735:posix_2escm"),(void*)f_4735},
{C_text("f_4760:posix_2escm"),(void*)f_4760},
{C_text("f_4772:posix_2escm"),(void*)f_4772},
{C_text("f_4799:posix_2escm"),(void*)f_4799},
{C_text("f_4813:posix_2escm"),(void*)f_4813},
{C_text("f_4852:posix_2escm"),(void*)f_4852},
{C_text("f_4877:posix_2escm"),(void*)f_4877},
{C_text("f_4882:posix_2escm"),(void*)f_4882},
{C_text("f_4889:posix_2escm"),(void*)f_4889},
{C_text("f_4896:posix_2escm"),(void*)f_4896},
{C_text("f_4935:posix_2escm"),(void*)f_4935},
{C_text("f_4939:posix_2escm"),(void*)f_4939},
{C_text("f_4955:posix_2escm"),(void*)f_4955},
{C_text("f_4963:posix_2escm"),(void*)f_4963},
{C_text("f_4980:posix_2escm"),(void*)f_4980},
{C_text("f_4995:posix_2escm"),(void*)f_4995},
{C_text("f_4999:posix_2escm"),(void*)f_4999},
{C_text("f_5063:posix_2escm"),(void*)f_5063},
{C_text("f_5080:posix_2escm"),(void*)f_5080},
{C_text("f_5084:posix_2escm"),(void*)f_5084},
{C_text("f_5088:posix_2escm"),(void*)f_5088},
{C_text("f_5104:posix_2escm"),(void*)f_5104},
{C_text("f_5108:posix_2escm"),(void*)f_5108},
{C_text("f_5112:posix_2escm"),(void*)f_5112},
{C_text("f_5116:posix_2escm"),(void*)f_5116},
{C_text("f_5120:posix_2escm"),(void*)f_5120},
{C_text("f_5140:posix_2escm"),(void*)f_5140},
{C_text("f_5148:posix_2escm"),(void*)f_5148},
{C_text("f_5173:posix_2escm"),(void*)f_5173},
{C_text("f_5187:posix_2escm"),(void*)f_5187},
{C_text("f_5189:posix_2escm"),(void*)f_5189},
{C_text("f_5194:posix_2escm"),(void*)f_5194},
{C_text("f_5203:posix_2escm"),(void*)f_5203},
{C_text("f_5230:posix_2escm"),(void*)f_5230},
{C_text("f_5233:posix_2escm"),(void*)f_5233},
{C_text("f_5238:posix_2escm"),(void*)f_5238},
{C_text("f_5244:posix_2escm"),(void*)f_5244},
{C_text("f_5269:posix_2escm"),(void*)f_5269},
{C_text("f_5271:posix_2escm"),(void*)f_5271},
{C_text("f_5331:posix_2escm"),(void*)f_5331},
{C_text("f_5403:posix_2escm"),(void*)f_5403},
{C_text("f_5417:posix_2escm"),(void*)f_5417},
{C_text("f_5425:posix_2escm"),(void*)f_5425},
{C_text("f_5431:posix_2escm"),(void*)f_5431},
{C_text("f_5437:posix_2escm"),(void*)f_5437},
{C_text("f_5443:posix_2escm"),(void*)f_5443},
{C_text("f_5449:posix_2escm"),(void*)f_5449},
{C_text("f_5455:posix_2escm"),(void*)f_5455},
{C_text("f_5461:posix_2escm"),(void*)f_5461},
{C_text("f_5467:posix_2escm"),(void*)f_5467},
{C_text("f_5473:posix_2escm"),(void*)f_5473},
{C_text("f_5479:posix_2escm"),(void*)f_5479},
{C_text("f_5485:posix_2escm"),(void*)f_5485},
{C_text("f_5491:posix_2escm"),(void*)f_5491},
{C_text("f_5497:posix_2escm"),(void*)f_5497},
{C_text("f_5503:posix_2escm"),(void*)f_5503},
{C_text("f_5509:posix_2escm"),(void*)f_5509},
{C_text("f_5515:posix_2escm"),(void*)f_5515},
{C_text("f_5521:posix_2escm"),(void*)f_5521},
{C_text("f_5527:posix_2escm"),(void*)f_5527},
{C_text("f_5533:posix_2escm"),(void*)f_5533},
{C_text("f_5539:posix_2escm"),(void*)f_5539},
{C_text("f_5545:posix_2escm"),(void*)f_5545},
{C_text("f_5551:posix_2escm"),(void*)f_5551},
{C_text("f_5557:posix_2escm"),(void*)f_5557},
{C_text("f_5563:posix_2escm"),(void*)f_5563},
{C_text("f_5569:posix_2escm"),(void*)f_5569},
{C_text("f_5575:posix_2escm"),(void*)f_5575},
{C_text("f_5581:posix_2escm"),(void*)f_5581},
{C_text("f_5587:posix_2escm"),(void*)f_5587},
{C_text("f_5593:posix_2escm"),(void*)f_5593},
{C_text("f_5599:posix_2escm"),(void*)f_5599},
{C_text("f_5605:posix_2escm"),(void*)f_5605},
{C_text("f_5623:posix_2escm"),(void*)f_5623},
{C_text("f_5668:posix_2escm"),(void*)f_5668},
{C_text("f_5672:posix_2escm"),(void*)f_5672},
{C_text("f_5677:posix_2escm"),(void*)f_5677},
{C_text("f_5684:posix_2escm"),(void*)f_5684},
{C_text("f_5702:posix_2escm"),(void*)f_5702},
{C_text("f_5706:posix_2escm"),(void*)f_5706},
{C_text("f_5708:posix_2escm"),(void*)f_5708},
{C_text("f_5712:posix_2escm"),(void*)f_5712},
{C_text("f_5715:posix_2escm"),(void*)f_5715},
{C_text("f_5724:posix_2escm"),(void*)f_5724},
{C_text("f_5745:posix_2escm"),(void*)f_5745},
{C_text("f_5749:posix_2escm"),(void*)f_5749},
{C_text("f_5751:posix_2escm"),(void*)f_5751},
{C_text("f_5755:posix_2escm"),(void*)f_5755},
{C_text("f_5757:posix_2escm"),(void*)f_5757},
{C_text("f_5761:posix_2escm"),(void*)f_5761},
{C_text("toplevel:posix_2escm"),(void*)C_posix_toplevel},
{C_text("va6260:posix_2escm"),(void*)va6260},
{C_text("va6268:posix_2escm"),(void*)va6268},
{C_text("va6276:posix_2escm"),(void*)va6276},
{C_text("va6278:posix_2escm"),(void*)va6278},
{C_text("va6280:posix_2escm"),(void*)va6280},
{C_text("va6282:posix_2escm"),(void*)va6282},
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
o|hiding unexported module binding: chicken.posix#duplicate-fileno 
o|hiding unexported module binding: chicken.posix#quote-arg-string 
o|hiding unexported module binding: chicken.posix#shell-command 
o|hiding unexported module binding: chicken.posix#shell-command-arguments 
o|hiding unexported module binding: chicken.posix#process-impl 
o|hiding unexported module binding: chicken.posix#process-wait-impl 
o|hiding unexported module binding: chicken.posix#chown 
S|applied compiler syntax:
S|  scheme#for-each		3
S|  scheme#map		3
o|eliminated procedure checks: 80 
o|specializations:
o|  4 (##sys#foreign-fixnum-argument fixnum)
o|  2 (scheme#string-length string)
o|  1 (##sys#check-output-port * * *)
o|  1 (##sys#check-input-port * * *)
o|  1 (##sys#call-with-values (procedure () *) *)
o|  3 (scheme#cdr pair)
o|  1 (chicken.base#add1 fixnum)
o|  1 (##sys#length list)
o|  1 (scheme#zero? *)
o|  1 (##sys#check-open-port * *)
o|  5 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  8 (scheme#car pair)
o|  5 (##sys#check-list (or pair list) *)
o|  1 (scheme#char=? char char)
o|  1 (scheme#zero? integer)
(o e)|safe calls: 473 
(o e)|assignments to immediate values: 114 
o|dropping redundant toplevel assignment: chicken.file.posix#file-stat 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-permissions! 
o|dropping redundant toplevel assignment: chicken.file.posix#file-modification-time 
o|dropping redundant toplevel assignment: chicken.file.posix#file-access-time 
o|dropping redundant toplevel assignment: chicken.file.posix#file-change-time 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-times! 
o|dropping redundant toplevel assignment: chicken.file.posix#file-size 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-owner! 
o|dropping redundant toplevel assignment: chicken.file.posix#set-file-group! 
o|dropping redundant toplevel assignment: chicken.process-context.posix#user-information 
o|safe globals: (chicken.file.posix#set-file-group! chicken.file.posix#set-file-owner! chicken.file.posix#file-size chicken.file.posix#set-file-times! chicken.file.posix#file-change-time chicken.file.posix#file-access-time chicken.file.posix#file-modification-time chicken.file.posix#set-file-permissions! chicken.file.posix#file-stat chicken.posix#stat ##sys#posix-error chicken.posix#posix-error chicken.process-context.posix#user-information chicken.process-context.posix#process-group-id chicken.process-context.posix#create-session chicken.process-context.posix#current-effective-user-name chicken.process-context.posix#current-user-name chicken.process-context.posix#parent-process-id chicken.process-context.posix#current-process-id chicken.process-context.posix#current-user-id chicken.process-context.posix#current-group-id chicken.process-context.posix#current-effective-user-id chicken.process-context.posix#current-effective-group-id chicken.process-context.posix#set-root-directory! chicken.process-context.posix#change-directory* chicken.process.signal#signals-list chicken.process.signal#signal/xfsz chicken.process.signal#signal/xcpu chicken.process.signal#signal/winch chicken.process.signal#signal/vtalrm chicken.process.signal#signal/usr2 chicken.process.signal#signal/usr1 chicken.process.signal#signal/urg chicken.process.signal#signal/tstp chicken.process.signal#signal/trap chicken.process.signal#signal/term chicken.process.signal#signal/stop chicken.process.signal#signal/segv chicken.process.signal#signal/quit chicken.process.signal#signal/prof chicken.process.signal#signal/pipe chicken.process.signal#signal/kill chicken.process.signal#signal/io chicken.process.signal#signal/int chicken.process.signal#signal/ill chicken.process.signal#signal/hup chicken.process.signal#signal/fpe chicken.process.signal#signal/cont chicken.process.signal#signal/chld chicken.process.signal#signal/bus chicken.process.signal#signal/break chicken.process.signal#signal/alrm chicken.process.signal#signal/abrt chicken.process.signal#signal-unmask! chicken.process.signal#signal-masked? chicken.process.signal#signal-mask! chicken.process.signal#signal-mask chicken.process.signal#signal-default chicken.process.signal#signal-ignore chicken.process.signal#make-signal-handler chicken.process.signal#signal-handler chicken.process.signal#set-signal-mask! chicken.process.signal#set-signal-handler! chicken.process.signal#set-alarm! chicken.process#spawn/detach chicken.process#spawn/nowaito chicken.process#spawn/nowait chicken.process#spawn/wait chicken.process#spawn/overlay chicken.process#pipe/buf chicken.process#process-sleep chicken.process#process* chicken.process#process chicken.process#with-output-to-pipe chicken.process#with-input-from-pipe chicken.process#open-output-pipe chicken.process#open-input-pipe chicken.process#create-pipe chicken.process#close-output-pipe chicken.process#close-input-pipe chicken.process#call-with-output-pipe chicken.process#call-with-input-pipe chicken.process#process-wait chicken.process#process-spawn chicken.process#process-signal chicken.process#process-run chicken.process#process-fork chicken.process#process-execute chicken.process#qs chicken.process#system* chicken.process#system chicken.time.posix#local-timezone-abbreviation chicken.time.posix#time->string chicken.time.posix#string->time chicken.time.posix#local-time->seconds chicken.time.posix#seconds->string chicken.time.posix#seconds->local-time chicken.time.posix#utc-time->seconds chicken.time.posix#seconds->utc-time chicken.file.posix#set-file-position! chicken.file.posix#seek/set chicken.file.posix#seek/end chicken.file.posix#seek/cur chicken.file.posix#port->fileno chicken.file.posix#perm/ixusr chicken.file.posix#perm/ixoth chicken.file.posix#perm/ixgrp chicken.file.posix#perm/iwusr chicken.file.posix#perm/iwoth chicken.file.posix#perm/iwgrp chicken.file.posix#perm/isvtx chicken.file.posix#perm/isuid chicken.file.posix#perm/isgid chicken.file.posix#perm/irwxu chicken.file.posix#perm/irwxo chicken.file.posix#perm/irwxg chicken.file.posix#perm/irusr chicken.file.posix#perm/iroth chicken.file.posix#perm/irgrp chicken.file.posix#open/wronly chicken.file.posix#open/write chicken.file.posix#open/trunc chicken.file.posix#open/text chicken.file.posix#open/sync chicken.file.posix#open/read chicken.file.posix#open/rdwr chicken.file.posix#open/rdonly chicken.file.posix#open/nonblock chicken.file.posix#open/noinherit chicken.file.posix#open/noctty chicken.file.posix#open/fsync chicken.file.posix#open/excl chicken.file.posix#open/creat chicken.file.posix#open/binary chicken.file.posix#open/append chicken.file.posix#open-output-file* chicken.file.posix#open-input-file* chicken.file.posix#fileno/stdout chicken.file.posix#fileno/stdin chicken.file.posix#fileno/stderr chicken.file.posix#symbolic-link? chicken.file.posix#socket? chicken.file.posix#regular-file? chicken.file.posix#fifo? chicken.file.posix#directory? chicken.file.posix#character-device? chicken.file.posix#block-device? chicken.file.posix#file-type chicken.file.posix#file-write chicken.file.posix#file-unlock chicken.file.posix#file-truncate chicken.file.posix#file-test-lock chicken.file.posix#file-select chicken.file.posix#file-read chicken.file.posix#file-position chicken.file.posix#file-permissions chicken.file.posix#file-owner chicken.file.posix#file-open chicken.file.posix#file-mkstemp chicken.file.posix#file-lock/blocking chicken.file.posix#file-lock chicken.file.posix#file-link chicken.file.posix#file-group chicken.file.posix#file-creation-mode chicken.file.posix#file-control chicken.file.posix#file-close chicken.file.posix#fcntl/setfl chicken.file.posix#fcntl/setfd chicken.file.posix#fcntl/getfl chicken.file.posix#fcntl/getfd chicken.file.posix#fcntl/dupfd chicken.file.posix#duplicate-fileno chicken.file.posix#read-symbolic-link chicken.file.posix#create-symbolic-link chicken.file.posix#create-fifo c1715) 
o|inlining procedure: k2403 
o|inlining procedure: k2403 
o|inlining procedure: k2422 
o|inlining procedure: k2422 
o|inlining procedure: k2449 
o|inlining procedure: k2449 
o|substituted constant variable: a2459 
o|inlining procedure: k2490 
o|inlining procedure: k2490 
o|contracted procedure: "(posix-common.scm:193) strerror652" 
o|inlining procedure: k2646 
o|inlining procedure: k2646 
o|inlining procedure: k2661 
o|inlining procedure: k2661 
o|inlining procedure: k2680 
o|inlining procedure: k2680 
o|inlining procedure: k2713 
o|inlining procedure: k2713 
o|inlining procedure: k2725 
o|inlining procedure: k2725 
o|inlining procedure: k2803 
o|inlining procedure: k2803 
o|contracted procedure: "(posix-common.scm:293) g724725" 
o|inlining procedure: k2790 
o|inlining procedure: k2790 
o|consed rest parameter at call site: "(posix-common.scm:306) chicken.posix#chown" 1 
o|consed rest parameter at call site: "(posix-common.scm:310) chicken.posix#chown" 1 
o|inlining procedure: k2890 
o|inlining procedure: k2902 
o|inlining procedure: k2902 
o|inlining procedure: k2914 
o|inlining procedure: k2914 
o|inlining procedure: k2926 
o|inlining procedure: k2926 
o|inlining procedure: k2890 
o|inlining procedure: k3047 
o|inlining procedure: k3047 
o|inlining procedure: k3062 
o|inlining procedure: k3062 
o|inlining procedure: k3075 
o|inlining procedure: k3075 
o|inlining procedure: k3125 
o|inlining procedure: k3138 
o|inlining procedure: k3138 
o|substituted constant variable: a3151 
o|inlining procedure: k3125 
o|inlining procedure: k3158 
o|inlining procedure: k3158 
o|inlining procedure: k3171 
o|inlining procedure: k3171 
o|substituted constant variable: a3206 
o|inlining procedure: k3207 
o|inlining procedure: k3207 
o|inlining procedure: k3226 
o|inlining procedure: k3226 
o|inlining procedure: k3256 
o|inlining procedure: k3256 
o|inlining procedure: k3283 
o|inlining procedure: k3283 
o|inlining procedure: k3296 
o|propagated global variable: r32975826 chicken.process-context.posix#change-directory* 
o|inlining procedure: k3296 
o|inlining procedure: k3316 
o|inlining procedure: k3316 
o|inlining procedure: k3394 
o|inlining procedure: k3394 
o|contracted procedure: "(posix-common.scm:596) ctime902" 
o|inlining procedure: k3430 
o|inlining procedure: k3430 
o|inlining procedure: k3474 
o|contracted procedure: "(posix-common.scm:619) strftime927" 
o|inlining procedure: k3460 
o|inlining procedure: k3460 
o|inlining procedure: k3474 
o|contracted procedure: "(posix-common.scm:621) asctime926" 
o|inlining procedure: k3447 
o|inlining procedure: k3447 
o|inlining procedure: k3572 
o|inlining procedure: k3572 
o|inlining procedure: k3590 
o|inlining procedure: k3590 
o|contracted procedure: "(posix-common.scm:683) chicken.posix#process-wait-impl" 
o|inlining procedure: k5393 
o|inlining procedure: k5393 
o|inlining procedure: k3667 
o|inlining procedure: k3667 
o|inlining procedure: k3753 
o|inlining procedure: k3753 
o|contracted procedure: "(posix-common.scm:716) c-string->allocated-pointer1036" 
o|merged explicitly consed rest parameter: args10481069 
o|consed rest parameter at call site: tmp22240 1 
o|inlining procedure: k3834 
o|inlining procedure: k3834 
o|inlining procedure: k3883 
o|inlining procedure: k3883 
o|inlining procedure: k3938 
o|inlining procedure: k3938 
o|inlining procedure: k3997 
o|contracted procedure: "(posix-common.scm:757) g11341143" 
o|inlining procedure: k3997 
o|inlining procedure: k4044 
o|inlining procedure: k4044 
o|inlining procedure: k4062 
o|inlining procedure: k4062 
o|inlining procedure: k4075 
o|inlining procedure: k4075 
o|inlining procedure: k4091 
o|inlining procedure: k4091 
o|inlining procedure: "(posix-common.scm:786) badmode1157" 
o|substituted constant variable: a4115 
o|substituted constant variable: a4117 
o|inlining procedure: k4131 
o|inlining procedure: k4131 
o|inlining procedure: "(posix-common.scm:797) badmode1157" 
o|substituted constant variable: a4155 
o|substituted constant variable: a4157 
o|substituted constant variable: a4162 
o|substituted constant variable: a4163 
o|inlining procedure: k4164 
o|inlining procedure: k4164 
o|substituted constant variable: a4177 
o|substituted constant variable: a4178 
o|inlining procedure: k4179 
o|inlining procedure: k4179 
o|inlining procedure: k4327 
o|inlining procedure: k4327 
o|inlining procedure: k4356 
o|inlining procedure: k4356 
o|inlining procedure: k4390 
o|inlining procedure: k4390 
o|inlining procedure: k4434 
o|inlining procedure: k4434 
o|inlining procedure: k4505 
o|inlining procedure: k4505 
o|inlining procedure: k4537 
o|inlining procedure: k4537 
o|inlining procedure: k4564 
o|inlining procedure: k4564 
o|inlining procedure: k4581 
o|inlining procedure: k4581 
o|inlining procedure: k4591 
o|inlining procedure: k4591 
o|inlining procedure: k4625 
o|inlining procedure: k4625 
o|inlining procedure: k4691 
o|inlining procedure: k4691 
o|inlining procedure: k4762 
o|inlining procedure: k4762 
o|contracted procedure: "(posixwin.scm:721) needs-quoting?1432" 
o|inlining procedure: k4737 
o|inlining procedure: k4737 
o|inlining procedure: k4804 
o|inlining procedure: k4804 
o|inlining procedure: k4887 
o|inlining procedure: k4887 
o|inlining procedure: k4940 
o|inlining procedure: k4940 
o|inlining procedure: k4968 
o|inlining procedure: k4968 
o|inlining procedure: "(posixwin.scm:772) chicken.posix#shell-command-arguments" 
o|merged explicitly consed rest parameter: rest15431551 
o|substituted constant variable: g158515861593 
o|substituted constant variable: g158515861593 
o|substituted constant variable: g158515861593 
o|substituted constant variable: g158715881594 
o|substituted constant variable: g158715881594 
o|substituted constant variable: g158715881594 
o|substituted constant variable: g158915901595 
o|substituted constant variable: g158915901595 
o|substituted constant variable: g158915901595 
o|substituted constant variable: g159115921596 
o|substituted constant variable: g159115921596 
o|substituted constant variable: g159115921596 
o|inlining procedure: k5071 
o|inlining procedure: k5086 
o|inlining procedure: k5086 
o|inlining procedure: k5071 
o|contracted procedure: "(posixwin.scm:809) c-process1507" 
o|inlining procedure: k5134 
o|inlining procedure: k5134 
o|inlining procedure: k5138 
o|inlining procedure: k5138 
o|inlining procedure: k5150 
o|inlining procedure: k5150 
o|inlining procedure: k5205 
o|inlining procedure: k5205 
o|consed rest parameter at call site: "(posixwin.scm:841) chicken.posix#process-impl" 8 
o|inlining procedure: k5246 
o|inlining procedure: k5246 
o|inlining procedure: "(posixwin.scm:837) chicken.posix#shell-command-arguments" 
o|inlining procedure: k5405 
o|inlining procedure: k5405 
o|merged explicitly consed rest parameter: _17101714 
o|inlining procedure: k5689 
o|inlining procedure: k5689 
o|inlining procedure: k5713 
o|inlining procedure: k5713 
o|inlining procedure: k5725 
o|inlining procedure: k5725 
o|inlining procedure: k5735 
o|inlining procedure: k5735 
o|replaced variables: 795 
o|removed binding forms: 583 
o|substituted constant variable: r26475771 
o|substituted constant variable: r27915784 
o|substituted constant variable: r27915784 
o|inlining procedure: "(posix-common.scm:306) chicken.posix#chown" 
o|inlining procedure: "(posix-common.scm:310) chicken.posix#chown" 
o|substituted constant variable: r29035787 
o|substituted constant variable: r29155789 
o|substituted constant variable: r29275791 
o|substituted constant variable: r28915793 
o|substituted constant variable: r30635797 
o|inlining procedure: k3125 
o|substituted constant variable: r31395802 
o|inlining procedure: k3125 
o|inlining procedure: k3125 
o|substituted constant variable: r31725808 
o|substituted constant variable: r31725808 
o|substituted constant variable: r31725810 
o|substituted constant variable: r31725810 
o|propagated global variable: g8558565827 chicken.process-context.posix#change-directory* 
o|substituted constant variable: r34615846 
o|substituted constant variable: r34615846 
o|substituted constant variable: r34485853 
o|substituted constant variable: r34485853 
o|substituted constant variable: r40455883 
o|removed side-effect free assignment to unused variable: badmode1157 
o|substituted constant variable: r40765886 
o|substituted constant variable: r40765886 
o|substituted constant variable: r40765888 
o|substituted constant variable: r40765888 
o|inlining procedure: k4091 
o|inlining procedure: k4131 
o|substituted constant variable: r45825944 
o|substituted constant variable: r45825944 
o|substituted constant variable: r47385964 
o|removed side-effect free assignment to unused variable: chicken.posix#shell-command-arguments 
o|contracted procedure: "(posixwin.scm:841) chicken.posix#process-impl" 
o|substituted constant variable: r50875984 
o|substituted constant variable: r50875984 
o|substituted constant variable: c-pointer15101527 
o|substituted constant variable: c-pointer15101527 
o|substituted constant variable: r51355987 
o|substituted constant variable: r51355987 
o|substituted constant variable: r51355989 
o|substituted constant variable: r51355989 
o|removed unused formal parameters: (_17101714) 
o|substituted constant variable: r57266017 
o|replaced variables: 84 
o|removed binding forms: 666 
o|removed conditional forms: 1 
o|inlining procedure: k3534 
o|inlining procedure: k3534 
o|inlining procedure: k3569 
o|inlining procedure: k3843 
o|inlining procedure: k4406 
o|inlining procedure: k4406 
o|inlining procedure: k4454 
o|inlining procedure: k4454 
o|substituted constant variable: stdinf1549 
o|substituted constant variable: stdoutf1548 
o|contracted procedure: k5001 
o|substituted constant variable: stdoutf1548 
o|substituted constant variable: stdinf1549 
o|inlining procedure: k5288 
o|inlining procedure: k5348 
o|removed side-effect free assignment to unused variable: chicken.posix#chown 
o|replaced variables: 8 
o|removed binding forms: 123 
o|removed conditional forms: 4 
o|substituted constant variable: r31266032 
o|substituted constant variable: r31266034 
o|substituted constant variable: r31266036 
o|substituted constant variable: r35356098 
o|substituted constant variable: r35706100 
o|contracted procedure: k3768 
o|substituted constant variable: r44076118 
o|substituted constant variable: r44556120 
o|contracted procedure: k5068 
o|substituted constant variable: r5002 
o|contracted procedure: k5126 
o|contracted procedure: k5130 
o|inlining procedure: k5686 
o|inlining procedure: k5686 
o|simplifications: ((let . 3)) 
o|replaced variables: 1 
o|removed binding forms: 18 
o|removed conditional forms: 3 
o|substituted constant variable: r5127 
o|substituted constant variable: r5131 
o|folded constant expression: (scheme#+ (quote 0) (quote 0) (quote 0)) 
o|substituted constant variable: r5127 
o|substituted constant variable: r5131 
o|folded constant expression: (scheme#+ (quote 0) (quote 0) (quote 4)) 
o|substituted constant variable: r56876164 
o|replaced variables: 1 
o|removed binding forms: 10 
o|removed binding forms: 4 
o|simplifications: ((let . 22) (if . 58) (##core#call . 317)) 
o|  call simplifications:
o|    scheme#<
o|    ##sys#foreign-pointer-argument	4
o|    scheme#string-length
o|    scheme#char-whitespace?
o|    scheme#*
o|    chicken.fixnum#fx>=	2
o|    scheme#string-ref	3
o|    scheme#string-set!
o|    chicken.bitwise#bitwise-ior	2
o|    chicken.fixnum#fxior	2
o|    scheme#list	5
o|    scheme#call-with-values	4
o|    ##sys#check-pair
o|    ##sys#check-list	4
o|    ##sys#apply	2
o|    chicken.fixnum#fx+	6
o|    ##sys#call-with-values	3
o|    scheme#values	10
o|    scheme#vector-set!	5
o|    ##sys#foreign-block-argument	2
o|    scheme#=
o|    ##sys#foreign-ranged-integer-argument
o|    chicken.fixnum#fx-	6
o|    ##sys#check-vector
o|    ##sys#size	6
o|    ##sys#null-pointer?	2
o|    scheme#not	3
o|    ##sys#setislot
o|    chicken.fixnum#fx=	16
o|    scheme#cdr	18
o|    ##sys#foreign-string-argument	3
o|    scheme#vector
o|    chicken.base#fixnum?	5
o|    scheme#string?	2
o|    ##sys#foreign-fixnum-argument	2
o|    scheme#null?	49
o|    scheme#car	32
o|    scheme#string->list
o|    scheme#pair?	13
o|    scheme#cons	8
o|    ##sys#setslot	3
o|    ##sys#slot	21
o|    scheme#apply	11
o|    scheme#char=?
o|    scheme#string	3
o|    scheme#eq?	25
o|    ##sys#check-string	11
o|    chicken.fixnum#fx<	11
o|contracted procedure: k2400 
o|contracted procedure: k2406 
o|contracted procedure: k2425 
o|contracted procedure: k2524 
o|contracted procedure: k2438 
o|contracted procedure: k2521 
o|contracted procedure: k2441 
o|contracted procedure: k2444 
o|contracted procedure: k2452 
o|contracted procedure: k2476 
o|contracted procedure: k2484 
o|contracted procedure: k2493 
o|contracted procedure: k2496 
o|contracted procedure: k2499 
o|contracted procedure: k2507 
o|contracted procedure: k2515 
o|contracted procedure: k2527 
o|contracted procedure: k2620 
o|contracted procedure: k2649 
o|contracted procedure: k2658 
o|contracted procedure: k2674 
o|contracted procedure: k2698 
o|contracted procedure: k2689 
o|contracted procedure: k2716 
o|contracted procedure: k2722 
o|contracted procedure: k2738 
o|contracted procedure: k2830 
o|contracted procedure: k2772 
o|contracted procedure: k2824 
o|contracted procedure: k2775 
o|contracted procedure: k2818 
o|contracted procedure: k2778 
o|contracted procedure: k2806 
o|contracted procedure: k2797 
o|contracted procedure: k2836 
o|contracted procedure: k2956 
o|contracted procedure: k2878 
o|contracted procedure: k2950 
o|contracted procedure: k2881 
o|contracted procedure: k2944 
o|contracted procedure: k2884 
o|contracted procedure: k2938 
o|contracted procedure: k2887 
o|contracted procedure: k2899 
o|contracted procedure: k2905 
o|contracted procedure: k2911 
o|contracted procedure: k2917 
o|contracted procedure: k2923 
o|contracted procedure: k2929 
o|contracted procedure: k2935 
o|contracted procedure: k3084 
o|contracted procedure: k3038 
o|contracted procedure: k3072 
o|contracted procedure: k3059 
o|contracted procedure: k3068 
o|contracted procedure: k3078 
o|contracted procedure: k3128 
o|contracted procedure: k3135 
o|contracted procedure: k3141 
o|contracted procedure: k3161 
o|contracted procedure: k3244 
o|contracted procedure: k3210 
o|contracted procedure: k3223 
o|contracted procedure: k3229 
o|contracted procedure: k3259 
o|contracted procedure: k3265 
o|contracted procedure: k3268 
o|contracted procedure: k3286 
o|contracted procedure: k3302 
o|contracted procedure: k3313 
o|contracted procedure: k3326 
o|contracted procedure: k3319 
o|contracted procedure: k3341 
o|inlining procedure: k3332 
o|contracted procedure: k3362 
o|inlining procedure: k3353 
o|contracted procedure: k3405 
o|contracted procedure: k3401 
o|contracted procedure: k3379 
o|contracted procedure: k3411 
o|contracted procedure: k3433 
o|contracted procedure: k3521 
o|contracted procedure: k3468 
o|contracted procedure: k3477 
o|contracted procedure: k3460 
o|contracted procedure: k3511 
o|contracted procedure: k3507 
o|contracted procedure: k3447 
o|contracted procedure: k3581 
o|contracted procedure: k3569 
o|contracted procedure: k3593 
o|contracted procedure: k3603 
o|contracted procedure: k3607 
o|contracted procedure: k3697 
o|contracted procedure: k3637 
o|contracted procedure: k3691 
o|contracted procedure: k3640 
o|contracted procedure: k3685 
o|contracted procedure: k3643 
o|contracted procedure: k3679 
o|contracted procedure: k3646 
o|contracted procedure: k3649 
o|contracted procedure: k3670 
o|contracted procedure: k3708 
o|contracted procedure: k3756 
o|contracted procedure: k3759 
o|contracted procedure: k3796 
o|contracted procedure: k3762 
o|contracted procedure: k3783 
o|contracted procedure: k3837 
o|contracted procedure: k3850 
o|contracted procedure: k38506108 
o|contracted procedure: k3859 
o|contracted procedure: k3864 
o|contracted procedure: k3867 
o|contracted procedure: k3886 
o|contracted procedure: k3896 
o|contracted procedure: k3900 
o|contracted procedure: k3908 
o|contracted procedure: k3974 
o|contracted procedure: k3988 
o|contracted procedure: k4000 
o|contracted procedure: k4003 
o|contracted procedure: k4006 
o|contracted procedure: k4014 
o|contracted procedure: k4022 
o|contracted procedure: k3983 
o|contracted procedure: k4047 
o|contracted procedure: k4065 
o|contracted procedure: k4081 
o|contracted procedure: k4094 
o|contracted procedure: k4104 
o|contracted procedure: k4121 
o|contracted procedure: k4134 
o|contracted procedure: k4144 
o|contracted procedure: k4167 
o|contracted procedure: k4182 
o|contracted procedure: k4340 
o|contracted procedure: k4311 
o|contracted procedure: k4314 
o|contracted procedure: k4330 
o|contracted procedure: k4359 
o|contracted procedure: k4365 
o|contracted procedure: k4396 
o|contracted procedure: k4412 
o|contracted procedure: k4447 
o|contracted procedure: k4428 
o|contracted procedure: k4437 
o|contracted procedure: k4463 
o|contracted procedure: k4466 
o|contracted procedure: k4475 
o|contracted procedure: k4502 
o|contracted procedure: k4508 
o|contracted procedure: k4514 
o|contracted procedure: k4521 
o|contracted procedure: k4531 
o|contracted procedure: k4540 
o|contracted procedure: k4554 
o|contracted procedure: k4543 
o|contracted procedure: k4550 
o|contracted procedure: k4558 
o|contracted procedure: k4567 
o|contracted procedure: k4585 
o|contracted procedure: k4601 
o|contracted procedure: k4607 
o|contracted procedure: k4614 
o|contracted procedure: k4642 
o|contracted procedure: k4622 
o|contracted procedure: k4631 
o|contracted procedure: k4679 
o|contracted procedure: k4694 
o|contracted procedure: k4704 
o|contracted procedure: k4707 
o|contracted procedure: k4728 
o|contracted procedure: k4740 
o|contracted procedure: k4757 
o|contracted procedure: k4746 
o|contracted procedure: k4753 
o|contracted procedure: k4845 
o|contracted procedure: k4774 
o|contracted procedure: k4839 
o|contracted procedure: k4777 
o|contracted procedure: k4833 
o|contracted procedure: k4780 
o|contracted procedure: k4827 
o|contracted procedure: k4783 
o|contracted procedure: k4821 
o|contracted procedure: k4786 
o|contracted procedure: k4815 
o|contracted procedure: k4789 
o|contracted procedure: k4792 
o|contracted procedure: k4801 
o|contracted procedure: k4807 
o|contracted procedure: k4928 
o|contracted procedure: k4854 
o|contracted procedure: k4922 
o|contracted procedure: k4857 
o|contracted procedure: k4916 
o|contracted procedure: k4860 
o|contracted procedure: k4910 
o|contracted procedure: k4863 
o|contracted procedure: k4904 
o|contracted procedure: k4866 
o|contracted procedure: k4898 
o|contracted procedure: k4869 
o|contracted procedure: k4872 
o|contracted procedure: k4884 
o|contracted procedure: k4890 
o|contracted procedure: k4985 
o|contracted procedure: k4965 
o|contracted procedure: k4982 
o|contracted procedure: k5191 
o|contracted procedure: k5208 
o|contracted procedure: k5218 
o|contracted procedure: k5222 
o|contracted procedure: k5225 
o|contracted procedure: k5181 
o|contracted procedure: k5055 
o|contracted procedure: k5058 
o|contracted procedure: k5122 
o|contracted procedure: k5005 
o|contracted procedure: k5009 
o|contracted procedure: k5013 
o|contracted procedure: k5017 
o|contracted procedure: k5021 
o|contracted procedure: k5043 
o|contracted procedure: k5050 
o|contracted procedure: k5141 
o|contracted procedure: k5153 
o|contracted procedure: k5156 
o|contracted procedure: k5159 
o|contracted procedure: k5167 
o|contracted procedure: k5175 
o|contracted procedure: k5263 
o|contracted procedure: k5324 
o|contracted procedure: k5273 
o|contracted procedure: k5318 
o|contracted procedure: k5276 
o|contracted procedure: k5312 
o|contracted procedure: k5279 
o|contracted procedure: k5306 
o|contracted procedure: k5282 
o|contracted procedure: k5300 
o|contracted procedure: k5285 
o|contracted procedure: k5294 
o|contracted procedure: k5288 
o|contracted procedure: k5384 
o|contracted procedure: k5333 
o|contracted procedure: k5378 
o|contracted procedure: k5336 
o|contracted procedure: k5372 
o|contracted procedure: k5339 
o|contracted procedure: k5366 
o|contracted procedure: k5342 
o|contracted procedure: k5360 
o|contracted procedure: k5345 
o|contracted procedure: k5354 
o|contracted procedure: k5348 
o|contracted procedure: k5695 
o|contracted procedure: k5679 
o|contracted procedure: k5716 
o|contracted procedure: k5732 
o|contracted procedure: k5728 
o|contracted procedure: k5738 
o|simplifications: ((if . 1) (##core#call . 9) (let . 73)) 
o|  call simplifications:
o|    scheme#*	2
o|    chicken.bitwise#bitwise-ior	7
o|removed binding forms: 262 
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
o|contracted procedure: k4306 
(o x)|known list op on rest arg sublist: ##core#rest-car mode1345 0 
o|contracted procedure: k4469 
o|contracted procedure: k4498 
o|contracted procedure: k4594 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14121413 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest14121413 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14461448 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest14461448 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14461448 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest14461448 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14711474 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest14711474 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14711474 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest14711474 0 
(o x)|known list op on rest arg sublist: ##core#rest-car args1504 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16721674 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16721674 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16721674 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest16721674 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16901692 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16901692 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16901692 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest16901692 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest860861 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest860861 0 
o|removed binding forms: 4 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2882 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2882 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2882 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2882 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3641 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r3641 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3641 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r3641 1 
o|removed side-effect free assignment to unused variable: mode1156 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4778 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4778 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4778 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4778 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4858 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4858 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4858 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4858 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5277 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r5277 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5277 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5277 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5337 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r5337 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5337 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5337 1 
o|replaced variables: 6 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4784 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r4784 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4784 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4784 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4864 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r4864 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4864 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4864 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5283 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r5283 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5283 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5283 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5343 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r5343 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r5343 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r5343 2 
o|converted assignments to bindings: (check1158) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 14 
o|contracted procedure: k4084 
o|contracted procedure: k4124 
o|removed binding forms: 10 
o|direct leaf routine/allocation: g10871094 0 
o|direct leaf routine/allocation: suffix-loop1400 0 
o|direct leaf routine/allocation: loop1387 0 
o|direct leaf routine/allocation: loop1435 0 
o|direct leaf routine/allocation: g16371644 0 
o|contracted procedure: "(posix-common.scm:732) k3889" 
o|contracted procedure: k4478 
o|contracted procedure: k4490 
o|converted assignments to bindings: (suffix-loop1400) 
o|converted assignments to bindings: (loop1387) 
o|contracted procedure: k4765 
o|converted assignments to bindings: (loop1435) 
o|contracted procedure: "(posixwin.scm:831) k5211" 
o|simplifications: ((let . 3)) 
o|removed binding forms: 5 
o|direct leaf routine/allocation: for-each-loop10861099 0 
o|direct leaf routine/allocation: for-each-loop16361654 0 
o|converted assignments to bindings: (for-each-loop10861099) 
o|converted assignments to bindings: (for-each-loop16361654) 
o|simplifications: ((let . 2)) 
o|customizable procedures: (va6282 va6280 va6278 va6276 %process1625 chkstrlst1632 map-loop15611578 chicken.posix#shell-command chicken.posix#call-with-exec-args k4688 va6268 va6260 loop1398 check1158 chicken.posix#check-environment-list map-loop11281146 chicken.posix#list->c-string-buffer k3956 doloop10741075 tmp12239 tmp22240 doloop10551056 chicken.posix#free-c-string-buffer g979986 for-each-loop978992 chicken.posix#check-time-vector k3253 mode802 check803 k2800 chicken.posix#stat g260269 map-loop254276) 
o|calls to known targets: 117 
o|unused rest argument: rest241243 f_2433 
o|unused rest argument: rest688690 f_2687 
o|unused rest argument: rest754756 f_2876 
o|unused rest argument: rest883884 f_3330 
o|unused rest argument: rest894895 f_3351 
o|unused rest argument: rest912913 f_3383 
o|unused rest argument: rest953955 f_3466 
o|unused rest argument: rest10001001 f_3567 
o|unused rest argument: args1016 f_3635 
o|identified direct recursive calls: f_3881 1 
o|identified direct recursive calls: f_4589 1 
o|identified direct recursive calls: f_4535 1 
o|unused rest argument: rest14121413 f_4620 
o|identified direct recursive calls: f_4735 1 
o|unused rest argument: rest14461448 f_4772 
o|unused rest argument: rest14711474 f_4852 
o|identified direct recursive calls: f_5203 1 
o|unused rest argument: rest16721674 f_5271 
o|unused rest argument: rest16901692 f_5331 
o|unused rest argument: _17181721 f_5425 
o|unused rest argument: _17241727 f_5431 
o|unused rest argument: _17301733 f_5437 
o|unused rest argument: _17361739 f_5443 
o|unused rest argument: _17421745 f_5449 
o|unused rest argument: _17481751 f_5455 
o|unused rest argument: _17541757 f_5461 
o|unused rest argument: _17601763 f_5467 
o|unused rest argument: _17721775 f_5473 
o|unused rest argument: _17781781 f_5479 
o|unused rest argument: _17841787 f_5485 
o|unused rest argument: _17901793 f_5491 
o|unused rest argument: _17961799 f_5497 
o|unused rest argument: _18021805 f_5503 
o|unused rest argument: _18081811 f_5509 
o|unused rest argument: _18141817 f_5515 
o|unused rest argument: _18201823 f_5521 
o|unused rest argument: _18261829 f_5527 
o|unused rest argument: _18321835 f_5533 
o|unused rest argument: _18381841 f_5539 
o|unused rest argument: _18441847 f_5545 
o|unused rest argument: _18501853 f_5551 
o|unused rest argument: _18561859 f_5557 
o|unused rest argument: _18621865 f_5563 
o|unused rest argument: _18681871 f_5569 
o|unused rest argument: _18741877 f_5575 
o|unused rest argument: _18801883 f_5581 
o|unused rest argument: _18861889 f_5587 
o|unused rest argument: _18921895 f_5593 
o|unused rest argument: _18981901 f_5599 
o|unused rest argument: _19041907 f_5605 
o|unused rest argument: rest860861 f_5677 
o|fast box initializations: 11 
o|fast global references: 83 
o|fast global assignments: 12 
o|dropping unused closure argument: f_2641 
o|dropping unused closure argument: f_3119 
o|dropping unused closure argument: f_3156 
o|dropping unused closure argument: f_3311 
o|dropping unused closure argument: f_3706 
o|dropping unused closure argument: f_3823 
o|dropping unused closure argument: f_3857 
o|dropping unused closure argument: f_4060 
o|dropping unused closure argument: f_4935 
o|dropping unused closure argument: f_5187 
*/
/* end of file */
