;;;; posixwin.scm - Miscellaneous file- and process-handling routines, available on Windows
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


; Not implemented:
;
; open/noctty  open/nonblock  open/fsync  open/sync
; perm/isvtx  perm/isuid  perm/isgid
; file-select
; set-signal-mask!  signal-mask	 signal-masked?	 signal-mask!  signal-unmask!
; user-information
; change-file-owner
; current-user-id  current-group-id  current-effective-user-id	current-effective-group-id
; current-effective-user-name
; set-user-id!	set-group-id!
; create-session
; process-group-id  set-process-group-id!
; create-symbolic-link	read-symbolic-link
; file-truncate
; file-lock  file-lock/blocking	 file-unlock  file-test-lock
; create-fifo
; prot/...
; map/...
; set-alarm!
; process-fork	process-wait
; parent-process-id
; process-signal


; Issues
;
; - Use of a UTF8 encoded string will not work properly. Windows uses a
; 16-bit UNICODE character string encoding and specialized system calls
; and/or structure settings for the use of such strings.


(declare
  (uses data-structures))

(define-foreign-variable _stat_st_blksize scheme-object "C_SCHEME_UNDEFINED")
(define-foreign-variable _stat_st_blocks scheme-object "C_SCHEME_UNDEFINED")

(include "posix-common.scm")

#>

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

<#

(import (only chicken.string string-intersperse))

;;; Lo-level I/O:

(define-foreign-variable _o_noinherit int "O_NOINHERIT")
(set! chicken.file.posix#open/noinherit _o_noinherit)

(set! chicken.file.posix#file-open
  (let ((defmode (bitwise-ior _s_irusr _s_iwusr _s_irgrp _s_iwgrp _s_iroth _s_iwoth)))
    (lambda (filename flags . mode)
      (let ([mode (if (pair? mode) (car mode) defmode)])
	(##sys#check-string filename 'file-open)
	(##sys#check-fixnum flags 'file-open)
	(##sys#check-fixnum mode 'file-open)
	(let ([fd (##core#inline "C_open" (##sys#make-c-string filename 'file-open) flags mode)])
	  (when (eq? -1 fd)
            (##sys#signal-hook/errno
             #:file-error (##sys#update-errno) 'file-open "cannot open file" filename flags mode))
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
          (##sys#signal-hook/errno
           #:file-error (##sys#update-errno) 'file-read "cannot read from file" fd size))
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
          (##sys#signal-hook/errno
           #:file-error (##sys#update-errno) 'file-write "cannot write to file" fd size))
	n) ) ) )

(set! chicken.file.posix#file-mkstemp
  (lambda (template)
    (##sys#check-string template 'file-mkstemp)
    (let* ((diz "0123456789abcdefghijklmnopqrstuvwxyz")
	   (diz-len (string-length diz))
	   (max-attempts (* diz-len diz-len diz-len))
	   (tmpl (string-copy template)) ; We'll overwrite this later
	   (tmpl-len (string-length tmpl))
	   (first-x (let loop ((i (fx- tmpl-len 1)))
		      (if (and (fx>= i 0)
			       (eq? (string-ref tmpl i) #\X))
			  (loop (fx- i 1))
			  (fx+ i 1)))))
      (cond ((not (##sys#file-exists? (or (pathname-directory template) ".") #f #t 'file-mkstemp))
	     ;; Quit early instead of looping needlessly with C_open
	     ;; failing every time.  This is a race condition, but not
	     ;; a security-critical one.
	     (##sys#signal-hook #:file-error 'file-mkstemp "non-existent directory" template))
	    ((fx= first-x tmpl-len)
	     (##sys#signal-hook #:file-error 'file-mkstemp "invalid template" template)))
      (let loop ((count 1))
	(let suffix-loop ((index (fx- tmpl-len 1)))
	  (when (fx>= index first-x)
	    (string-set! tmpl index
  		  (string-ref diz (##core#inline "C_rand" diz-len)))
	    (suffix-loop (fx- index 1))))
	(let ((fd (##core#inline "C_open"
				 (##sys#make-c-string tmpl 'file-open)
				 (bitwise-ior chicken.file.posix#open/rdwr
					      chicken.file.posix#open/creat
					      chicken.file.posix#open/excl)
				 (fxior _s_irusr _s_iwusr))))
	  (if (eq? -1 fd)
	      (if (fx< count max-attempts)
		  (loop (fx+ count 1))
		  (posix-error #:file-error 'file-mkstemp "cannot create temporary file" template))
	      (values fd tmpl)))))))

;;; Pipe primitive:

(define-foreign-variable _pipefd0 int "C_pipefds[ 0 ]")
(define-foreign-variable _pipefd1 int "C_pipefds[ 1 ]")

(set! chicken.process#create-pipe
  (lambda (#!optional (mode (fxior chicken.file.posix#open/binary
                                   chicken.file.posix#open/noinherit)))
    (when (fx< (##core#inline "C_pipe" #f mode) 0)
      (##sys#signal-hook/errno
       #:file-error (##sys#update-errno) 'create-pipe "cannot create pipe"))
    (values _pipefd0 _pipefd1) ) )

;;; Signal processing:

(define-foreign-variable _nsig int "NSIG")
(define-foreign-variable _sigterm int "SIGTERM")
(define-foreign-variable _sigint int "SIGINT")
(define-foreign-variable _sigfpe int "SIGFPE")
(define-foreign-variable _sigill int "SIGILL")
(define-foreign-variable _sigsegv int "SIGSEGV")
(define-foreign-variable _sigabrt int "SIGABRT")
(define-foreign-variable _sigbreak int "SIGBREAK")

(set! chicken.process.signal#signal/term _sigterm)
(set! chicken.process.signal#signal/int _sigint)
(set! chicken.process.signal#signal/fpe _sigfpe)
(set! chicken.process.signal#signal/ill _sigill)
(set! chicken.process.signal#signal/segv _sigsegv)
(set! chicken.process.signal#signal/abrt _sigabrt)
(set! chicken.process.signal#signal/break _sigbreak)
(set! chicken.process.signal#signal/alrm 0)
(set! chicken.process.signal#signal/bus 0)
(set! chicken.process.signal#signal/chld 0)
(set! chicken.process.signal#signal/cont 0)
(set! chicken.process.signal#signal/hup 0)
(set! chicken.process.signal#signal/io 0)
(set! chicken.process.signal#signal/kill 0)
(set! chicken.process.signal#signal/pipe 0)
(set! chicken.process.signal#signal/prof 0)
(set! chicken.process.signal#signal/quit 0)
(set! chicken.process.signal#signal/stop 0)
(set! chicken.process.signal#signal/trap 0)
(set! chicken.process.signal#signal/tstp 0)
(set! chicken.process.signal#signal/urg 0)
(set! chicken.process.signal#signal/usr1 0)
(set! chicken.process.signal#signal/usr2 0)
(set! chicken.process.signal#signal/vtalrm 0)
(set! chicken.process.signal#signal/winch 0)
(set! chicken.process.signal#signal/xcpu 0)
(set! chicken.process.signal#signal/xfsz 0)

(set! chicken.process.signal#signals-list
  (list
   chicken.process.signal#signal/term
   chicken.process.signal#signal/int
   chicken.process.signal#signal/fpe
   chicken.process.signal#signal/ill
   chicken.process.signal#signal/segv
   chicken.process.signal#signal/abrt
   chicken.process.signal#signal/break))

;;; Using file-descriptors:

(define duplicate-fileno
  (lambda (old . new)
    (##sys#check-fixnum old duplicate-fileno)
    (let ([fd (if (null? new)
		  (##core#inline "C_dup" old)
		  (let ([n (car new)])
		    (##sys#check-fixnum n 'duplicate-fileno)
		    (##core#inline "C_dup2" old n) ) ) ] )
      (when (fx< fd 0)
        (##sys#signal-hook/errno
         #:file-error (##sys#update-errno) 'duplicate-fileno "cannot duplicate file descriptor" old))
      fd) ) )


;;; Time related things:

(set! chicken.time.posix#local-timezone-abbreviation
  (foreign-lambda* c-string ()
   "char *z = (_daylight ? _tzname[1] : _tzname[0]);\n"
   "C_return(z);") )


;;; Process handling:

(define-foreign-variable _p_overlay int "P_OVERLAY")
(define-foreign-variable _p_wait int "P_WAIT")
(define-foreign-variable _p_nowait int "P_NOWAIT")
(define-foreign-variable _p_nowaito int "P_NOWAITO")
(define-foreign-variable _p_detach int "P_DETACH")

(set! chicken.process#spawn/overlay _p_overlay)
(set! chicken.process#spawn/wait _p_wait)
(set! chicken.process#spawn/nowait _p_nowait)
(set! chicken.process#spawn/nowaito _p_nowaito)
(set! chicken.process#spawn/detach _p_detach)

; Windows uses a commandline style for process arguments. Thus any
; arguments with embedded whitespace will parse incorrectly. Must
; string-quote such arguments.
(define quote-arg-string
  (let ((needs-quoting?
	 ;; This is essentially (string-any char-whitespace? s) but we
	 ;; don't want a SRFI-13 dependency. (Do we?)
	 (lambda (s)
	   (let ((len (string-length s)))
	     (let loop ((i 0))
	       (cond
		((fx= i len) #f)
		((char-whitespace? (string-ref s i)) #t)
		(else (loop (fx+ i 1)))))))))
    (lambda (str)
      (if (needs-quoting? str) (string-append "\"" str "\"") str))))

(set! chicken.process#process-execute
  (lambda (filename #!optional (arglist '()) envlist exactf)
    (let ((argconv (if exactf (lambda (x) x) quote-arg-string)))
      (call-with-exec-args
       'process-execute filename argconv arglist envlist
       (lambda (prg argbuf envbuf)
	 (##core#inline "C_flushall")
	 (let ((r (if envbuf
		      (##core#inline "C_u_i_execve" prg argbuf envbuf)
		      (##core#inline "C_u_i_execvp" prg argbuf))))
	   (when (fx= r -1)
	     (posix-error #:process-error 'process-execute "cannot execute process" filename))))))))

(set! chicken.process#process-spawn
  (lambda (mode filename #!optional (arglist '()) envlist exactf)
    (let ((argconv (if exactf (lambda (x) x) quote-arg-string)))
      (##sys#check-fixnum mode 'process-spawn)
      (call-with-exec-args
       'process-spawn filename argconv arglist envlist
       (lambda (prg argbuf envbuf)
	 (##core#inline "C_flushall")
	 (let ((r (if envbuf
		      (##core#inline "C_u_i_spawnvpe" mode prg argbuf envbuf)
		      (##core#inline "C_u_i_spawnvp" mode prg argbuf))))
	   (when (fx= r -1)
	     (posix-error #:process-error 'process-spawn "cannot spawn process" filename))
	   r))))))

(define-foreign-variable _shlcmd c-string "C_shlcmd")

(define (shell-command loc)
  (or (get-environment-variable "COMSPEC")
      (if (##core#inline "C_get_shlcmd")
	  _shlcmd
          (##sys#error/errno
           (##sys#update-errno) loc "cannot retrieve system directory"))))

(define (shell-command-arguments cmdlin)
  (list "/c" cmdlin) )

(set! chicken.process#process-run
  (lambda (f . args)
    (let ((args (if (pair? args) (car args) #f)))
      (if args
	  (chicken.process#process-spawn
	   chicken.process#spawn/nowait f args)
	  (chicken.process#process-spawn
	   chicken.process#spawn/nowait
	   (shell-command 'process-run)
	   (shell-command-arguments f)) ) ) ) )

;;; Run subprocess connected with pipes:
(define-foreign-variable _rdbuf char "C_rdbuf")
(define-foreign-variable _wr0 int "C_wr0_")
(define-foreign-variable _rd1 int "C_rd1_")

; from original by Mejedi
;; process-impl
; loc		 caller procedure symbol
; cmd		 pathname or commandline
; args		 string-list or '()
; env		 string-list or #f (currently ignored)
; stdoutf	 #f then share, or #t then create
; stdinf	 #f then share, or #t then create
; stderrf	 #f then share, or #t then create
;
; (values stdin-input-port? stdout-output-port? pid stderr-input-port?)
; where stdin-input-port?, etc. is a port or #f, indicating no port created.

(define process-impl
  ;; XXX TODO: When environment is implemented, check for embedded NUL bytes!
  (let ([c-process
	  (foreign-lambda bool "C_process" c-string c-string c-pointer
	    (c-pointer int) (c-pointer int) (c-pointer int) (c-pointer int) int)])
    ; The environment list must be sorted & include current directory
    ; information for the system drives. i.e !C:=...
    ; For now any environment is ignored.
    (lambda (loc cmd args env stdoutf stdinf stderrf #!optional exactf)
      (let* ((arglist (cons cmd args))
	     (cmdlin (string-intersperse
		      (if exactf
			  arglist
			  (map quote-arg-string arglist)))))
	(let-location ([handle int -1]
		       [stdin_fd int -1] [stdout_fd int -1] [stderr_fd int -1])
	  (let ([res
		  (c-process cmd cmdlin #f
		    (location handle)
		    (location stdin_fd) (location stdout_fd) (location stderr_fd)
		    (+ (if stdinf 0 1) (if stdoutf 0 2) (if stderrf 0 4)))])
	    (if res
	      (values
	       (and stdoutf (chicken.file.posix#open-input-file*
			     stdout_fd)) ;Parent stdin
	       (and stdinf (chicken.file.posix#open-output-file*
			    stdin_fd))  ;Parent stdout
	       handle
	       (and stderrf (chicken.file.posix#open-input-file*
			     stderr_fd)))
              (##sys#signal-hook/errno
               #:process-error (##sys#update-errno) loc "cannot execute process" cmdlin))))))))

;; TODO: See if this can be moved to posix-common
(let ((%process
	(lambda (loc err? cmd args env exactf)
	  (let ((chkstrlst
		 (lambda (lst)
		   (##sys#check-list lst loc)
		   (for-each (cut ##sys#check-string <> loc) lst) )))
	    (##sys#check-string cmd loc)
	    (if args
	      (chkstrlst args)
	      (begin
		(set! exactf #t)
		(set! args (shell-command-arguments cmd))
		(set! cmd (shell-command loc)) ) )
	    (when env (check-environment-list env loc))
	    (receive (in out pid err)
		(process-impl loc cmd args env #t #t err? exactf)
	      (if err?
		(values in out pid err)
		(values in out pid) ) ) ) )) )
  (set! chicken.process#process
    (lambda (cmd #!optional args env exactf)
      (%process 'process #f cmd args env exactf) ))
  (set! chicken.process#process*
    (lambda (cmd #!optional args env exactf)
      (%process 'process* #t cmd args env exactf) )) )

(define-foreign-variable _exstatus int "C_exstatus")

(define (process-wait-impl pid nohang)
  (if (##core#inline "C_process_wait" pid nohang)
    (values pid #t _exstatus)
    (values -1 #f #f) ) )


;;; Getting group- and user-information:

(define-foreign-variable _username c-string "C_username")

(set! chicken.process-context.posix#current-user-name
  (lambda ()
    (if (##core#inline "C_get_user_name")
        _username
        (##sys#error/errno
         (##sys#update-errno) 'current-user-name "cannot retrieve current user-name"))))


;;; unimplemented stuff:

(define-unimplemented chown) ; covers set-file-group! and set-file-owner!
(set!-unimplemented chicken.file.posix#create-fifo)
(set!-unimplemented chicken.process-context.posix#create-session)
(set!-unimplemented chicken.file.posix#create-symbolic-link)
(set!-unimplemented chicken.process-context.posix#current-effective-group-id)
(set!-unimplemented chicken.process-context.posix#current-effective-user-id)
(set!-unimplemented chicken.process-context.posix#current-effective-user-name)
(set!-unimplemented chicken.process-context.posix#current-group-id)
(set!-unimplemented chicken.process-context.posix#current-user-id)
(set!-unimplemented chicken.process-context.posix#user-information)
(set!-unimplemented chicken.file.posix#file-control)
(set!-unimplemented chicken.file.posix#file-link)
(set!-unimplemented chicken.file.posix#file-lock)
(set!-unimplemented chicken.file.posix#file-lock/blocking)
(set!-unimplemented chicken.file.posix#file-select)
(set!-unimplemented chicken.file.posix#file-test-lock)
(set!-unimplemented chicken.file.posix#file-truncate)
(set!-unimplemented chicken.file.posix#file-unlock)
(set!-unimplemented chicken.process-context.posix#parent-process-id)
(set!-unimplemented chicken.process#process-fork)
(set!-unimplemented chicken.process-context.posix#process-group-id)
(set!-unimplemented chicken.process#process-signal)
(set!-unimplemented chicken.file.posix#read-symbolic-link)
(set!-unimplemented chicken.process.signal#set-alarm!)
(set!-unimplemented chicken.process-context.posix#set-root-directory!)
(set!-unimplemented chicken.process.signal#set-signal-mask!)
(set!-unimplemented chicken.process.signal#signal-mask)
(set!-unimplemented chicken.process.signal#signal-mask!)
(set!-unimplemented chicken.process.signal#signal-masked?)
(set!-unimplemented chicken.process.signal#signal-unmask!)
(set!-unimplemented chicken.process-context.posix#user-information)
(set!-unimplemented chicken.time.posix#utc-time->seconds)
(set!-unimplemented chicken.time.posix#string->time)

;; Unix-only definitions
(set! chicken.file.posix#fcntl/dupfd 0)
(set! chicken.file.posix#fcntl/getfd 0)
(set! chicken.file.posix#fcntl/setfd 0)
(set! chicken.file.posix#fcntl/getfl 0)
(set! chicken.file.posix#fcntl/setfl 0)
(set! chicken.file.posix#open/noctty 0)
(set! chicken.file.posix#open/nonblock 0)
(set! chicken.file.posix#open/fsync 0)
(set! chicken.file.posix#open/sync 0)
(set! chicken.file.posix#perm/isgid 0)
(set! chicken.file.posix#perm/isuid 0)
(set! chicken.file.posix#perm/isvtx 0)
