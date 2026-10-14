/*
 * system calls
 * Copyright (C) 2003-2010 Sam Steingold
 * Copyright (C) 2005,2008 Bruno Haible
 * Copyright (C) 2005,2010 Arseny Slobodyuk
 * GPL2
 */

#if defined(_WIN32)
/* need this for CreateHardLink to work */
# define WINVER 0x0500
#endif
#if defined(__CYGWIN__)
# define UNIX_CYGWIN32
#endif

/* clisp.h includes system headers among other stuff
   (windows.h on windows) */

#include "clisp.h"
#include "config.h"

#if defined(HAVE_SYS_TIME_H)
# include <sys/time.h>
#endif
#if defined(HAVE_TIME_H)
# include <time.h>
#endif
#if defined(HAVE_UNISTD_H)
# include <unistd.h>
#endif
#if defined(HAVE_SYS_UNISTD_H)
# include <sys/unistd.h>
#endif
#if defined(HAVE_ERRNO_H)
# include <errno.h>
#endif
#include <sys/types.h>
#if defined(HAVE_SYS_STAT_H)
# include <sys/stat.h>
#endif
#if defined(HAVE_SYS_RESOURCE_H)
# include <sys/resource.h>
#endif
#if defined(HAVE_SYS_WAIT_H)
# include <sys/wait.h>   /* always present on unix, but not elsewhere */
#endif
#if defined(HAVE_SYS_STATVFS_H)
# include <sys/statvfs.h>
#endif
#if defined(HAVE_CRYPT_H)
# include <crypt.h>
#endif
#if defined(HAVE_UTIME_H)
# include <utime.h>
#endif
#if defined(HAVE_WCHAR_H)
# include <wchar.h>
#endif
#include <limits.h>
#if !defined(NZERO)             /* should be defined in <limits.h> */
# define NZERO 20
#endif
#if defined(HAVE_SYSLOG_H)
# include <syslog.h>
#endif
#if defined(HAVE_UTMPX_H)
# include <utmpx.h>
#endif
#if defined(HAVE_SIGNAL_H)
# include <signal.h>
#endif
#if defined(HAVE_FCNTL_H)
# include <fcntl.h>
#endif
#if defined(HAVE_SYS_PARAM_H)   /* might not be present on woe32 */
# include <sys/param.h>
#endif

#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)
#include <initguid.h>
DEFINE_GUID(FMTID_SummaryInformation, 0xF29F85E0, 0x4FF9, 0x1068,
            0xAB, 0x91, 0x08, 0x00, 0x2B, 0x27, 0xB3, 0xD9);
DEFINE_GUID(FMTID_UserDefinedProperties, 0xD5CDD505, 0x2E9C, 0x101B,
            0x93, 0x97, 0x08, 0x00, 0x2B, 0x2C, 0xF9, 0xAE);
#endif

#include <stdio.h>              /* for BUFSIZ */
#include <stdlib.h>
#include <string.h>             /* for strcpy(), strcat() */

/* #define DEBUG */
#if defined(DEBUG)
extern object nobject_out (FILE* stream, object obj);
# define XOUT(obj,label)                                                \
  (printf("[%s:%d] %s: %s:\n",__FILE__,__LINE__,STRING(obj),label),     \
   obj=nobject_out(stdout,obj), printf("\n"))
#else
# undef OBJECT_OUT
# define OBJECT_OUT(o,l)
# define XOUT(o,l)
#endif

/* http://www.opengroup.org/onlinepubs/009695399/basedefs/sys/types.h.html
   specifies tha pid_t is signed, assume that uid_t & gid_t are signed too */
#if SIZEOF_PID_T == 8
# define pid_to_I(g)  sint64_to_I(g)
# define I_to_pid(g)  I_to_sint64(g=check_sint64(g))
#else
# define pid_to_I(g)  sint32_to_I(g)
# define I_to_pid(g)  I_to_sint32(g=check_sint32(g))
#endif
#if SIZEOF_UID_T == 8
# define uid_to_I(g)  sint64_to_I(g)
# define I_to_uid(g)  I_to_sint64(g=check_sint64(g))
#else
# define uid_to_I(g)  sint32_to_I(g)
# define I_to_uid(g)  I_to_sint32(g=check_sint32(g))
#endif
#if SIZEOF_GID_T == 8
# define gid_to_I(g)  sint64_to_I(g)
# define I_to_gid(g)  I_to_sint64(g=check_sint64(g))
#else
# define gid_to_I(g)  sint32_to_I(g)
# define I_to_gid(g)  I_to_sint32(g=check_sint32(g))
#endif

/* general convenience macros */
#define GETTER(type,conv,call)                                  \
  type id;                                                      \
  begin_system_call(); id = call(); end_system_call();          \
  VALUES1(conv##_to_I(id))
#define GETTER0(type,call)  GETTER(type##_t,type,call)
#define GETTER1(type,call)                              \
  type##_t id = I_to_##type(STACK_0);                   \
  type##_t ret;                                         \
  begin_system_call(); ret=call(id); end_system_call(); \
  if (ret==(type##_t)-1) OS_error();                    \
  VALUES1(type##_to_I(ret)); skipSTACK(1)
#define SETTER(type,conv,call)                                  \
  type val = conv(STACK_0);                                     \
  int status;                                                   \
  begin_system_call(); status = call(val); end_system_call();   \
  if (status) OS_error();                                       \
  VALUES1(popSTACK())
#define SETTER1(type,call)  SETTER(type##_t,I_to_##type,call)
#define SETTER2(type,call)                                              \
  type##_t eid = I_to_##type(STACK_0);                                  \
  type##_t rid = I_to_##type(STACK_1);                                  \
  int status;                                                           \
  begin_system_call(); status = call(rid,eid); end_system_call();       \
  if (status) OS_error();                                               \
  VALUES0; skipSTACK(2)

/* for COPY-FILE, must come before DEFMODULE for DEFCHECKER to work */
typedef enum {
  COPY_METHOD_COPY,
  COPY_METHOD_SYMLINK,
  COPY_METHOD_HARDLINK,
  COPY_METHOD_HARDLINK_OR_COPY, /* EXDEV=>COPY */
  COPY_METHOD_RENAME
} copy_method_t;

DEFMODULE(syscalls,"POSIX")

#if defined(HAVE_FCNTL) || defined(WIN32_NATIVE)
/* we use posix fcntl() on unix and win32 LockFileEx() on win32.
   since cygwin supports fcntl(), we use it there, but another option
   would be to use cygwin get_osfhandle() + win32 LockFileEx(),
   see <http://article.gmane.org/gmane.os.cygwin/35175> */

/* ============================== aux ============================== */

/* the input handle from input stream and output handle from output stream
 can trigger GC */
static Handle stream_get_handle (gcv_object_t *stream_) {
  if (uint_p(*stream_)) {
    Handle fd = (Handle)I_to_uint(*stream_);
    *stream_ = nullobj;
    return fd;
  } else {
    pushSTACK(*stream_); funcall(L(input_stream_p),1);
    return stream_lend_handle(stream_,!nullp(value1),NULL);
  }
}

/* signal the appropriate error error */
nonreturning_function(static, error_OS_stream, (object stream)) {
  if (eq(nullobj,stream)) OS_error();
  else OS_filestream_error(stream);
}

/* ============================== locking ============================== */
#if defined(WIN32_NATIVE)
/* LockFileEx does not exist on Windows95/98/ME. */
typedef BOOL (WINAPI * LockFileExFuncType)
  (HANDLE hFile, DWORD dwFlags, DWORD dwReserved,
   DWORD nNumberOfBytesToLockLow, DWORD nNumberOfBytesToLockHigh,
   LPOVERLAPPED lpOverlapped);
static LockFileExFuncType LockFileExFunc = NULL;
static BOOL my_LockFileEx
(HANDLE hFile, DWORD dwFlags, DWORD dwReserved,
 DWORD nNumberOfBytesToLockLow, DWORD nNumberOfBytesToLockHigh,
 LPOVERLAPPED lpOverlapped) {
  (void)dwFlags; (void)dwReserved;
  return LockFile(hFile,lpOverlapped->Offset,lpOverlapped->OffsetHigh,
                  nNumberOfBytesToLockLow,nNumberOfBytesToLockHigh);
}
typedef BOOL (WINAPI * UnlockFileExFuncType)
  (HANDLE hFile, DWORD dwReserved,
   DWORD nNumberOfBytesToUnlockLow, DWORD nNumberOfBytesToUnlockHigh,
   LPOVERLAPPED lpOverlapped);
static UnlockFileExFuncType UnlockFileExFunc = NULL;
static BOOL my_UnlockFileEx
(HANDLE hFile, DWORD dwReserved,
 DWORD nNumberOfBytesToUnlockLow, DWORD nNumberOfBytesToUnlockHigh,
 LPOVERLAPPED lpOverlapped) {
  (void)dwReserved;
  return UnlockFile(hFile,lpOverlapped->Offset,lpOverlapped->OffsetHigh,
                    nNumberOfBytesToUnlockLow,nNumberOfBytesToUnlockHigh);
}
#endif

#if defined(SIZEOF_OFF_T) && SIZEOF_OFF_T == 8
# define I_to_offset(x)  I_to_uint64(check_uint64(x))
#else
# define I_to_offset(x)  I_to_uint32(check_uint32(x))
#endif
DEFUN(POSIX::STREAM-LOCK, stream lockp &key :BLOCK SHARED :START :LENGTH)
{ /* the interface to fcntl(2) */
  Handle fd = (Handle)-1;
  bool lock_p = !nullp(STACK_4), failed_p;
  object stream;
  uintL start = missingp(STACK_1) ? 0 : I_to_UL(check_ulong(STACK_1));
#if defined(WIN32_NATIVE)
  uint64 length;
  DWORD flags = !lock_p ? 0 :
    (missingp(STACK_2) ? LOCKFILE_EXCLUSIVE_LOCK : 0) | /* (SHARED NIL) */
    (nullp(STACK_3) ? LOCKFILE_FAIL_IMMEDIATELY : 0);   /* (BLOCK T) */
  OVERLAPPED ol = {0,0,start,0,NULL};
#else
  off_t length;
  int cmd = nullp(STACK_3) ? F_SETLK : F_SETLKW; /* (BLOCK T) */
  struct flock fl;
  fl.l_type = !lock_p ? F_UNLCK :          /* unlock */
    missingp(STACK_2) ? F_WRLCK : F_RDLCK; /* (SHARED NIL) */
  fl.l_whence = SEEK_SET;
  fl.l_start = start;
#endif
  if (uint_p(STACK_5)) {        /* STREAM */
    fd = (Handle)I_to_uint(STACK_5);
    stream = nullobj;
  } else
    stream = open_file_stream_handle(STACK_5,&fd,false);
  if (missingp(STACK_0)) {     /* no :LENGTH => use file size */
    /* we use OS to get file size instead of calling FILE-LENGTH because
       on win32 FILE-LENGTH will fail with ERROR_LOCK_VIOLATION when the
       underlying file is locked */
#  if defined(WIN32_NATIVE)
    uint32 size_hi;
    uint32 size_lo;
    begin_blocking_system_call();
    size_lo = GetFileSize(fd,(DWORD*)&size_hi);
    /* Value returned can be (LONG) -1 even on success,
       check the last error code */
    failed_p = (size_lo == INVALID_FILE_SIZE) && (GetLastError() != 0);
    end_blocking_system_call();
    if (failed_p) goto stream_lock_error;
    length = ((uint64)size_hi << 32) | (uint64)size_lo;
#  elif defined(HAVE_FSTAT)
    struct stat st;
    begin_blocking_system_call();
    failed_p = (-1 == fstat(fd,&st));
    end_blocking_system_call();
    if (failed_p) goto stream_lock_error;
    length = st.st_size;
#  else
    length = 0;
#  endif
  } else
    length = I_to_offset(STACK_0);
  begin_blocking_system_call();
#if defined(WIN32_NATIVE)
  if (lock_p) {
    failed_p = !(*LockFileExFunc)(fd,flags,0,length,0,&ol);
    if (failed_p && nullp(STACK_3) && GetLastError() == ERROR_LOCK_VIOLATION)
      failed_p = lock_p = false; /* failed to lock, :BLOCK NIL */
  } else
    failed_p = !(*UnlockFileExFunc)(fd,0,length,0,&ol);
#else
  fl.l_len = length;
  if ((failed_p = (-1 == fcntl(fd,cmd,&fl)))
      && lock_p && (cmd == F_SETLK) && (errno == EACCES || errno == EAGAIN))
    failed_p = lock_p = false; /* failed to lock, :BLOCK NIL */
#endif
  end_blocking_system_call();
  if (failed_p) stream_lock_error:
    error_OS_stream(stream);
  skipSTACK(6);
  VALUES_IF(lock_p);
}
#endif  /* fcntl | WIN32_NATIVE */

/* ============================== fcntl ============================== */
#if defined(HAVE_FCNTL)
DEFCHECKER(check_fcntl_cmd, prefix=F_GET, delim=, default=,FD FL)
/* note that O_ACCMODE is treated specially */
DEFCHECKER(check_fl_flags, prefix=O, default=,bitmasks=both,          \
           RDONLY WRONLY RDWR :APPEND CREAT TRUNC EXCL NOCTTY SYNC NONBLOCK \
           BINARY TEXT NOINHERIT DIRECT LARGEFILE :DIRECTORY NOFOLLOW)
DEFCHECKER(check_fd_flags, prefix=FD,bitmasks=both,CLOEXEC)
DEFUN(POSIX::STREAM-OPTIONS, stream cmd &optional value)
{ /* http://www.opengroup.org/onlinepubs/009695399/functions/fcntl.html */
  int cmd = check_fcntl_cmd(STACK_1);
  Handle fd = stream_get_handle(&STACK_2);
  int value;
  if (boundp(STACK_0)) {        /* SET */
    switch (cmd) {
      case F_GETFD: value = check_fd_flags_of_list(STACK_0);
        cmd = F_SETFD; break;
      case F_GETFL: value = check_fl_flags_of_list(STACK_0);
        cmd = F_SETFL; break;
      default: NOTREACHED;
    }
    begin_blocking_system_call();
    value = fcntl(fd,cmd,value);
    end_blocking_system_call();
    if (-1 == value) error_OS_stream(STACK_2);
    VALUES0;
  } else {                      /* GET */
    begin_blocking_system_call();
    value = fcntl(fd,cmd);
    end_blocking_system_call();
    if (-1 == value) error_OS_stream(STACK_2);
    switch (cmd) {
      case F_GETFD: value1 = check_fd_flags_to_list(value); break;
      case F_GETFL:
        switch (value & O_ACCMODE) {
          case O_RDONLY: STACK_0 = `:RDONLY`; break;
          case O_WRONLY: STACK_0 = `:WRONLY`; break;
          case O_RDWR: STACK_0 = `:RDWR`; break;
          default: NOTREACHED;
        }
        STACK_1 = check_fl_flags_to_list(value & ~O_ACCMODE);
        value1 = allocate_cons();
        Car(value1) = STACK_0;
        Cdr(value1) = STACK_1;
        break;
      default: NOTREACHED;
    }
    mv_count = 1;
  }
  skipSTACK(3);
}
#endif

/* call f on physical namestring of path and data
 > path: a pathname designator
 > f: system call
 < data: anything which f accepts
 < value1: the physical namestring of path (for error reporting)
 < returns whatever f returns
 NB: on success, unix functions return 0, while woe32 functions return 1 !
 can trigger GC */
static /*maygc*/ void* on_pnamestring
(object path, void* (*f) (const char*,void*), void* data) {
  void* ret;
  pushSTACK(physical_namestring(path)); /* save for blocking */
  with_string_0(STACK_0,GLO(pathname_encoding),pathz, {
      begin_blocking_system_call();
      ret = (*f)(pathz,data);
      end_blocking_system_call();
    });
  value1 = popSTACK();
  return ret;
}
#define ON_PNAMESTRING(p,f,d)  on_pnamestring(p,(void*(*)(const char*,void*))&(f),(void*)(d))

/* =========================== file truncate =========================== */
/* NB: woe32 has ftruncate, but, just like fstat, it does not accept a Handle,
   just an integer of an unknown nature */

#if defined(WIN32_NATIVE)
typedef LARGE_INTEGER file_offset_t;
static inline void I_to_file_offset (object obj, file_offset_t *length)
{ length->QuadPart = I_to_sint64(check_sint64(obj)); }
#elif defined(UNIX)
typedef off_t file_offset_t;
static inline void I_to_file_offset (object obj, file_offset_t *length)
{ *length = I_to_offset(obj); }
#else
# error file_offset_t is not defined
#endif

/* truncate a file, STACK_0 = path */
static void* path_truncate (const char *path, file_offset_t *length) {
#if defined(WIN32_NATIVE)
  HANDLE fd = CreateFile(path,GENERIC_WRITE,0,NULL,OPEN_EXISTING,
                         FILE_ATTRIBUTE_NORMAL,NULL);
  return (void*)(!(fd != INVALID_HANDLE_VALUE
                   && SetFilePointerEx(fd,*length,NULL,FILE_BEGIN)
                   && SetEndOfFile(fd)
                   && CloseHandle(fd)));
#elif defined(HAVE_TRUNCATE)
  return (void*)(uintP)truncate(path,*length);
#else
#error FILE-SIZE: no truncate and not woe32
#endif
}

/* truncate a stream, STACK_0 = stream */
static void stream_truncate (Handle fd, file_offset_t *length) {
  begin_blocking_system_call();
#if defined(WIN32_NATIVE)
  { LARGE_INTEGER cur_pos;
    if (!(SetFilePointerEx(fd,(LARGE_INTEGER){QuadPart:0},
                           &cur_pos,FILE_CURRENT)
          && SetFilePointerEx(fd,*length,NULL,FILE_BEGIN)
          && SetEndOfFile(fd)
          && SetFilePointerEx(fd,cur_pos,NULL,FILE_BEGIN)))
      { end_blocking_system_call(); OS_filestream_error(STACK_0); }
  }
#elif defined(HAVE_FTRUNCATE)
  if (ftruncate(fd,*length))
    { end_blocking_system_call(); OS_file_error(STACK_0); }
#else
#error FILE-SIZE: no ftruncate and not woe32
#endif
  end_blocking_system_call();
}

/* separate from SET-FILE-STAT because it works only on paths
   while (setf file-size) supports streams as well */
DEFUN(POSIX::%SET-FILE-SIZE, file new-size) {
  /* http://www.opengroup.org/onlinepubs/009695399/functions/truncate.html
     http://www.opengroup.org/onlinepubs/009695399/functions/ftruncate.html
     http://msdn.microsoft.com/en-us/library/aa365542(VS.85).aspx
     http://msdn.microsoft.com/en-us/library/aa365531(VS.85).aspx */
  file_offset_t length;
  Handle fd;
  I_to_file_offset(STACK_0,&length);
  /* stream_truncate uses STACK_0 for error reporting */
  pushSTACK(open_file_stream_handle(STACK_1,&fd,true));
  if (eq(nullobj,STACK_0)) {    /* not a stream - use path */
    if (ON_PNAMESTRING(STACK_2,path_truncate,&length))
      OS_file_error(value1);
  } else stream_truncate(fd,&length); /* stream - use fd */
  VALUES1(STACK_1); skipSTACK(3);
}

#if defined(WIN32_NATIVE)
static void* get_file_size (const char *path, file_offset_t *length) {
  Handle fd = CreateFile(path,GENERIC_WRITE,0,NULL,OPEN_EXISTING,
                         FILE_ATTRIBUTE_NORMAL,NULL);
  return (void*)(!(fd != INVALID_HANDLE_VALUE
                   && GetFileSizeEx(fd,length)
                   && CloseHandle(fd)));
}
#endif
DEFUN(POSIX:FILE-SIZE, file) {
  /* we could implement this in Lisp like this:
     (defun file-size (file)
       (handler-case (file-length file)
         (file-error (c) (with-open-file (s file) (file-length s))))) */
  Handle fd;
  object stream = open_file_stream_handle(STACK_0,&fd,true);
  if (eq(nullobj,stream)) {    /* not a stream - use path */
   #if defined(WIN32_NATIVE)
    LARGE_INTEGER length;
    if (ON_PNAMESTRING(STACK_0,get_file_size,&length))
      OS_file_error(value1);
    VALUES1(sint64_to_I(length.QuadPart));
   #elif defined(HAVE_STAT)
    struct stat buf;
    if (ON_PNAMESTRING(STACK_0,stat,&buf))
      OS_file_error(value1);
    VALUES1(off_to_I(buf.st_size));
   #else
    #error FILE-SIZE: no stat and not woe32
   #endif
    skipSTACK(1);
  } else {                      /* stream - use FILE-LENGTH */
    STACK_0 = stream;
    funcall(L(file_length),1);
  }
}

/* ============================== syslog ============================== */
#if defined(HAVE_SYSLOG)
DEFCHECKER(check_syslog_severity,prefix=LOG,reverse=sint_to_I,  \
           EMERG ALERT CRIT ERR WARNING NOTICE INFO DEBUG)
DEFCHECKER(check_syslog_facility,default=LOG_USER,prefix=LOG,\
           KERN USER MAIL NEWS UUCP DAEMON AUTH CRON LPR SYSLOG AUTHPRIV FTP \
           LOCAL0 LOCAL1 LOCAL2 LOCAL3 LOCAL4 LOCAL5 LOCAL6 LOCAL7)
DEFFLAGSET(syslog_opt_flags,LOG_PID LOG_CONS LOG_NDELAY LOG_ODELAY LOG_NOWAIT)
#if defined(HAVE_OPENLOG)
static char* log_ident=NULL;
DEFUN(POSIX:OPENLOG,ident &key PID CONS NDELAY ODELAY NOWAIT FACILITY) {
  int facility = check_syslog_facility(popSTACK());
  int logopt = syslog_opt_flags();
  with_string_0(check_string(popSTACK()),GLO(misc_encoding),ident, {
      begin_blocking_system_call();
      if (log_ident) { free(log_ident); }
      log_ident = (char*)clisp_malloc(strlen(ident)+1);
      strcpy(log_ident,ident);
      openlog(log_ident,logopt,facility);
      end_blocking_system_call();
    });
  VALUES0;
}
#endif
#if defined(HAVE_SETLOGMASK)
DEFUN(POSIX:SETLOGMASK, maskpri) {
  int priority = (missingp(STACK_0) ? (skipSTACK(1),0) /*query*/ :
                  check_syslog_severity(popSTACK()));
  int logmask;
  begin_system_call();
  logmask = setlogmask(LOG_MASK(priority));
  end_system_call();
  VALUES1(check_syslog_severity_reverse(logmask));
}
#endif
DEFUN(POSIX::%SYSLOG, severity facility message) {
  int priority =
    check_syslog_severity(STACK_2) | check_syslog_facility(STACK_1);
  with_string_0(STACK_0 = check_string(STACK_0),GLO(misc_encoding),mesg, {
      begin_blocking_system_call();
      /* disable %m but avoid surprises with % special handling
         http://www.opengroup.org/onlinepubs/009695399/functions/syslog.html */
      syslog(priority,"%s",mesg);
      end_blocking_system_call();
    });
  VALUES0; skipSTACK(3);
}
#if defined(HAVE_CLOSELOG)
DEFUN(POSIX:CLOSELOG,) {
  begin_blocking_system_call();
  closelog();
#if defined(HAVE_OPENLOG)
  if(log_ident) { free(log_ident); log_ident=NULL; }
#endif
  end_blocking_system_call();
  VALUES0;
}
#endif
#endif  /* HAVE_SYSLOG */

/* ========================== time conversion ========================== */
DEFUN(POSIX:STRING-TIME, format &optional datum timezone)
{ /* http://www.opengroup.org/onlinepubs/009695399/functions/strptime.html
     http://www.opengroup.org/onlinepubs/009695399/functions/strftime.html */
  STACK_2 = check_string(STACK_2); /* format */
  if (missingp(STACK_1)) { /* datum defaults to the current time */
    funcall(L(get_universal_time),0);
    STACK_1 = value1;
  }
  if (stringp(STACK_1)) {          /* parse: strptime */
    struct tm tm;
    unsigned int offset;
    with_string_0(STACK_1,GLO(misc_encoding),buf, {
        with_string_0(STACK_2,GLO(misc_encoding),format, {
            char *ret;
            begin_system_call();
            if ((ret = strptime(buf,format,&tm))) offset = ret - buf;
            else offset = 0;
            end_system_call();
          });
      });
    if (offset == 0) {
      pushSTACK(STACK_1);/*datum*/ pushSTACK(STACK_(2+1));/*format*/
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: invalid format ~S or datum ~S"));
    }
    pushSTACK(fixnum(tm.tm_sec));
    pushSTACK(fixnum(tm.tm_min));
    pushSTACK(fixnum(tm.tm_hour));
    pushSTACK(fixnum(tm.tm_mday));
    pushSTACK(fixnum(1+tm.tm_mon));
    pushSTACK(fixnum(1900+tm.tm_year));
    pushSTACK(STACK_(0+6));     /* timezone */
    funcall(S(encode_universal_time),7);
    /* value1 from ENCODE-UNIVERSAL-TIME */
    value2 = tm.tm_isdst > 0 ? T : NIL;
    value3 = fixnum(offset);
    mv_count = 3;
    skipSTACK(3);
  } else if (integerp(STACK_1)) { /* format: strftime */
    struct tm tm;
    funcall(`CL:DECODE-UNIVERSAL-TIME`,2);
    tm.tm_sec = posfixnum_to_V(value1); /* Seconds [0,60]. */
    tm.tm_min = posfixnum_to_V(value2); /* Minutes [0,59]. */
    tm.tm_hour = posfixnum_to_V(value3); /* Hour [0,23]. */
    tm.tm_mday = posfixnum_to_V(value4); /* Day of month [1,31]. */
    tm.tm_mon = posfixnum_to_V(value5) - 1; /* Month of year [0,11]. */
    tm.tm_year = posfixnum_to_V(value6) - 1900; /* Years since 1900. */
    /* Day of week [0,6] (C: Sunday=0 <== CL: Monday=0 */
    tm.tm_wday = (posfixnum_to_V(value7) + 1) % 7;
    tm.tm_isdst = !nullp(value8); /* Daylight Savings flag. */
    /* tm.tm_yday == Day of year [0,365]. -- use mkime() */
    { time_t ret;
      begin_system_call(); ret = mktime(&tm); end_system_call();
      if (ret == (time_t)-1) OS_error();
    }
    with_string_0(STACK_0,GLO(misc_encoding),format, {
        /* at least 4 characters per each format char + safety */
        size_t bufsize = 4 * format_bytelen + 64;
        char* buf = (char*)alloca(bufsize);
        size_t retval;
        begin_system_call();
        retval = strftime(buf,bufsize,format,&tm);
        end_system_call();
        VALUES1(n_char_to_string(buf,retval,GLO(misc_encoding)));
      });
    skipSTACK(1);
  } else error_string_integer(STACK_1);
}

/* ========================== string comparison ========================== */
/* call strverscmp() on STACK_0 & STACK_1 and remove them from STACK */
static /*maygc*/ int string_version_compare (void) {
  int ret;
  STACK_0 = check_string(STACK_0);
  STACK_1 = check_string(STACK_1);
  with_string_0(STACK_0,GLO(misc_encoding),s1, {
      with_string_0(STACK_1,GLO(misc_encoding),s2, {
          begin_system_call(); ret = strverscmp(s2,s1); end_system_call();
        });
    });
  skipSTACK(2);
  return ret;
}

DEFUN(OS::VERSION-COMPARE, string1 string2) {
  int ret=string_version_compare();
  VALUES1(ret<0 ? S(smaller) : ret>0 ? S(greater) : S(numequal));
}
DEFUN(OS:VERSION<,  string1 string2){VALUES_IF(string_version_compare() <  0);}
DEFUN(OS:VERSION<=, string1 string2){VALUES_IF(string_version_compare() <= 0);}
DEFUN(OS:VERSION>,  string1 string2){VALUES_IF(string_version_compare() >  0);}
DEFUN(OS:VERSION>=, string1 string2){VALUES_IF(string_version_compare() >= 0);}

/* ========================== temporary files ========================== */
#if defined(HAVE_MKSTEMP) || defined(HAVE_TEMPNAM) || defined(WIN32_NATIVE)
#if defined(HAVE_TEMPNAM)
static object temp_name (char *dir, char *prefix) {
  char *ret_s; object ret_o;
  begin_blocking_system_call();
  ret_s = tempnam(dir,prefix);
  end_blocking_system_call();
  if (ret_s == NULL) OS_error();
  ret_o = asciz_to_string(ret_s,GLO(pathname_encoding));
  begin_system_call(); free(ret_s); end_system_call();
  return ret_o;
}
#elif defined(WIN32_NATIVE)
static object temp_name (char *dir, char *prefix) {
  char path[MAX_PATH];
  int ret;
  begin_blocking_system_call();
  ret = GetTempFileName(dir,prefix,0,path);
  end_blocking_system_call();
  if (0 == ret) OS_error();
  return asciz_to_string(path,GLO(pathname_encoding));
}
#endif
DEFUN(POSIX:MKSTEMP, template &key :DIRECTION :BUFFERED :EXTERNAL-FORMAT \
      :ELEMENT-TYPE) {
#if defined(HAVE_MKSTEMP)
  /* http://www.opengroup.org/onlinepubs/009695399/functions/mkstemp.html */
  object fname = physical_namestring(STACK_4);
  direction_t dir = (boundp(STACK_3) ? check_direction(STACK_3)
                     : DIRECTION_OUTPUT);
  Handle fd;
  with_string_0(fname,GLO(pathname_encoding),namez,{
      char *c_template;
      begin_blocking_system_call();
      if (namez_bytelen > 6
          && namez[namez_bytelen-1]=='X'
          && namez[namez_bytelen-2]=='X'
          && namez[namez_bytelen-3]=='X'
          && namez[namez_bytelen-4]=='X'
          && namez[namez_bytelen-5]=='X'
          && namez[namez_bytelen-6]=='X') {
        c_template = namez;
      } else {
        c_template = (char*)alloca(namez_bytelen+6);
        strcpy(c_template,namez);
        strcat(c_template,"XXXXXX");
      }
      fd = mkstemp(c_template);
      end_blocking_system_call();
      fname = asciz_to_string(c_template,GLO(pathname_encoding));
    });
  pushSTACK(fname);  funcall(L(pathname),1); STACK_4=value1; /* filename */
  pushSTACK(value1); funcall(L(truename),1); STACK_3=value1; /* truename */
  pushSTACK(allocate_handle(fd));
  /* stack layout: FD, eltype, extfmt, buff, truename, filename */
  VALUES1(make_file_stream(dir,false,true));
#elif defined(HAVE_TEMPNAM) || defined(WIN32_NATIVE)
  /* http://www.opengroup.org/onlinepubs/009695399/functions/tempnam.html */
  object path;
  pushSTACK(STACK_4); funcall(L(pathname),1); pushSTACK(value1);
  pushSTACK(value1); funcall(L(directory_namestring),1); pushSTACK(value1);
  pushSTACK(STACK_1); funcall(L(file_namestring),1); pushSTACK(value1);
  with_string_0(STACK_0,GLO(pathname_encoding),prefix, {
      with_string_0(STACK_1,GLO(pathname_encoding),dir, {
          /* if no directory ==> use current "." */
          STACK_7 = temp_name(dir[0] ? dir : (char*)".",prefix);
        });
    });
  pushSTACK(STACK_3);           /* ELEMENT-TYPE */
  STACK_1 = S(Kelement_type);
  STACK_2 = STACK_5;            /* EXTERNAL-FORMAT */
  STACK_3 = S(Kexternal_format);
  STACK_4 = STACK_6;            /* BUFFERED */
  STACK_5 = S(Kbuffered);
  STACK_6 = missingp(STACK_7) ? S(Koutput) : STACK_7; /* DIRECTION */
  STACK_7 = S(Kdirection);
  funcall(L(open),9);
#endif
}
#endif /* HAVE_MKSTEMP || HAVE_TEMPNAM || WIN32_NATIVE */

/* ================= user accounting database functions ================= */
#if defined(HAVE_UTMPX_H)
DEFCHECKER(check_ut_type,default=,EMPTY RUN-LVL BOOT-TIME OLD-TIME NEW-TIME \
           USER-PROCESS INIT-PROCESS LOGIN-PROCESS DEAD-PROCESS ACCOUNTING)
static int check_utmpx (gcv_object_t *arg) {
  *arg = check_classname(*arg,`POSIX::UTMPX`);
  return check_ut_type(TheStructure(*arg)->recdata[4]);
}
/* convert C struct utmpx to Lisp
 can trigger GC */
static Values utmpx_to_lisp (struct utmpx *utmpx, gcv_object_t *utmpx_o) {
  pushSTACK(check_ut_type_reverse(utmpx->ut_type));
  pushSTACK(safe_to_string(utmpx->ut_user));
  pushSTACK(safe_to_string(utmpx->ut_id));
  pushSTACK(safe_to_string(utmpx->ut_line));
  pushSTACK(L_to_I(utmpx->ut_pid));
#if defined(HAVE_UTMPX_UT_HOST)
  pushSTACK(safe_to_string(utmpx->ut_host));
#else
  pushSTACK(NIL);
#endif
  pushSTACK(sec_usec_number(utmpx->ut_tv.tv_sec,utmpx->ut_tv.tv_usec,1));
  if (utmpx_o) {
    TheStructure(*utmpx_o)->recdata[7] = popSTACK(); /* tv */
    TheStructure(*utmpx_o)->recdata[6] = popSTACK(); /* host */
    TheStructure(*utmpx_o)->recdata[5] = popSTACK(); /* pid */
    TheStructure(*utmpx_o)->recdata[4] = popSTACK(); /* line */
    TheStructure(*utmpx_o)->recdata[3] = popSTACK(); /* id */
    TheStructure(*utmpx_o)->recdata[2] = popSTACK(); /* user */
    TheStructure(*utmpx_o)->recdata[1] = popSTACK(); /* type */
    VALUES1(*utmpx_o);
  } else funcall(`POSIX::MAKE-UTMPX`,7);
}
#if defined(HAVE_ENDUTXENT)
DEFUN(POSIX::ENDUTXENT,) {
  begin_blocking_system_call(); endutxent(); end_blocking_system_call();
  VALUES0;
}
#endif
#if defined(HAVE_GETUTXENT)
DEFUN(POSIX::GETUTXENT, &optional utmpx) {
  struct utmpx *utmpx;
  if (!missingp(STACK_0)) STACK_0 = check_classname(STACK_0,`POSIX::UTMPX`);
  begin_blocking_system_call(); utmpx=getutxent(); end_blocking_system_call();
  if (utmpx) utmpx_to_lisp(utmpx,missingp(STACK_0) ? NULL : &STACK_0);
  else VALUES1(NIL);
  skipSTACK(1);
}
#endif
#if defined(HAVE_GETUTXID)
DEFUN(POSIX::GETUTXID, id) {
  struct utmpx utmpx, *utmpx_p;
  utmpx.ut_type = check_utmpx(&STACK_0);
  begin_blocking_system_call();
  utmpx_p = getutxid(&utmpx);
  end_blocking_system_call();
  if (utmpx_p) utmpx_to_lisp(utmpx_p,&STACK_0);
  else VALUES1(NIL);
  skipSTACK(1);
}
#endif
#if defined(HAVE_GETUTXLINE)
DEFUN(POSIX::GETUTXLINE, line) {
  struct utmpx utmpx, *utmpx_p;
  utmpx.ut_type = check_utmpx(&STACK_0);
  begin_blocking_system_call();
  utmpx_p = getutxline(&utmpx);
  end_blocking_system_call();
  if (utmpx_p) utmpx_to_lisp(utmpx_p,&STACK_0);
  else VALUES1(NIL);
  skipSTACK(1);
}
#endif
#if defined(HAVE_PUTUTXLINE)
DEFUN(POSIX::PUTUTXLINE, utmpx) {
  struct utmpx utmpx, *utmpx_p;
  utmpx.ut_type = check_utmpx(&STACK_0);
  begin_blocking_system_call();
  utmpx_p = pututxline(&utmpx);
  end_blocking_system_call();
  if (utmpx_p) utmpx_to_lisp(utmpx_p,&STACK_0);
  else OS_error();
  skipSTACK(1);
}
#endif
#if defined(HAVE_SETUTXENT)
DEFUN(POSIX::SETUTXENT,) {
  begin_blocking_system_call(); setutxent(); end_blocking_system_call();
  VALUES0;
}
#endif
#endif  /* HAVE_UTMPX_H */

/* ========================= processes & signals ========================= */
#if defined(HAVE_GETPPID)
DEFUN(POSIX:GETPPID,) { GETTER0(pid,getppid); }
#endif
#if defined(HAVE_GETSID)
DEFUN(POSIX:GETSID, pid) { GETTER1(pid,getsid); }
#endif
#if defined(HAVE_SETSID)
DEFUN(POSIX:SETSID,) { GETTER0(pid,setsid); } /* sic! */
#endif
#if defined(HAVE_GETPGRP)
DEFUN(POSIX:GETPGRP,) { GETTER0(pid,getpgrp); }
#endif
#if defined(HAVE_SETPGRP)
DEFUN(POSIX:SETPGRP,) {
  pid_t ret;
# if defined(HAVE_SETPGRP_POSIX)
  begin_system_call(); ret=setpgrp(); end_system_call();
# else  /* BSD version, identical to setpgid() */
  begin_system_call(); ret=setpgrp(0,0); end_system_call();
# endif
  if (ret==(pid_t)-1) OS_error();
  VALUES1(pid_to_I(ret));
}
#endif
#if defined(HAVE_GETPGID)
DEFUN(POSIX:PGID, pid) { GETTER1(pid,getpgid); }
#endif
#if defined(HAVE_SETPGID)
DEFUN(POSIX::%SETPGID, pid pgid) {
  pid_t pgid = I_to_pid(STACK_0);
  pid_t pid = I_to_pid(STACK_1);
  int ret;
  begin_system_call(); ret=setpgid(pid,pgid); end_system_call();
  if (ret==-1) OS_error();
  VALUES1(STACK_0); skipSTACK(2);
}
#endif
#if defined(HAVE_SETREUID)
DEFUN(POSIX:SETREUID, ruid euid) { SETTER2(uid,setreuid); }
#endif
#if defined(HAVE_SETREGID)
DEFUN(POSIX:SETREGID, rgid egid) { SETTER2(gid,setregid); }
#endif
/* http://www.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html */
DEFCHECKER(check_signal,SIGABRT SIGALRM SIGBUS SIGCHLD SIGCONT SIGFPE SIGHUP \
           SIGILL SIGINT SIGKILL SIGPIPE SIGQUIT SIGSEGV SIGSTOP SIGTERM \
           SIGTSTP SIGTTIN SIGTTOU SIGUSR1 SIGUSR2 SIGPOLL SIGPROF SIGSYS \
           SIGTRAP SIGURG SIGVTALRM SIGXCPU SIGXFSZ)
#if defined(HAVE_KILL)
DEFUN(POSIX:KILL, pid sig) {
  int sig = check_signal(STACK_0);
  pid_t pid = I_to_pid(STACK_1);
  int ret;
  begin_system_call(); ret=kill(pid,sig); end_system_call();
  if (ret==-1) OS_error();
  VALUES0; skipSTACK(2);
}
#endif  /* HAVE_KILL */

/* ============================= file sync ============================= */
#if defined(WIN32_NATIVE) || defined(HAVE_SYNC) || defined(HAVE_FSYNC)
DEFUN(POSIX:SYNC, &optional file) {
  if (missingp(STACK_0)) {      /* sync() */
#  if defined(HAVE_SYNC)
    begin_blocking_system_call(); sync(); end_blocking_system_call();
#  endif
  } else {                      /* fsync() */
    Handle fd = stream_get_handle(&STACK_0);
    bool failed_p;
    begin_blocking_system_call();
#  if defined(HAVE_FSYNC)
    failed_p = (-1 == fsync(fd));
#  elif defined(WIN32_NATIVE)
    failed_p = (!FlushFileBuffers(fd));
#  endif
    end_blocking_system_call();
    if (failed_p) error_OS_stream(STACK_0);
  }
  VALUES0; skipSTACK(1);
}
#endif
/* ========================== process priority ========================== */
#if defined(WIN32_NATIVE)
DEFCHECKER(check_priority_value,suffix=PRIORITY_CLASS,default=0,        \
           REALTIME :HIGH ABOVE-NORMAL :NORMAL BELOW-NORMAL :LOW IDLE)
#else
DEFCHECKER(check_priority_value,default=0,reverse=sint_to_I,                \
           REALTIME=-NZERO :HIGH=(-NZERO/2) ABOVE-NORMAL=(-NZERO/4) :NORMAL=0 \
           BELOW-NORMAL=(NZERO/4) :LOW=(NZERO/2) IDLE=NZERO)
#endif
DEFCHECKER(check_priority_which,prefix=PRIO,default=0, PROCESS PGRP USER)
DEFUN(OS:PRIORITY, pid &optional which) {
  int which = check_priority_which(popSTACK());
  int pid = I_to_uint32(check_uint32(popSTACK()));
  int res;
  bool failed_p;
#if defined(HAVE_GETPRIORITY)
  begin_system_call();
  errno = 0;
  res = getpriority(which,pid);
  failed_p = (errno != 0);
  end_system_call();
#elif defined(WIN32_NATIVE)
  {
    HANDLE handle;
    begin_system_call();
    handle = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,pid);
    if (handle != NULL) {
      res = (int)GetPriorityClass(handle);
      CloseHandle(handle);
    } else failed_p = true;
    end_system_call();
  }
#else
  NOTREACHED;
#endif
  if (failed_p) OS_error();
  VALUES1(check_priority_value_reverse(res));
}
DEFUN(OS::%SET-PRIORITY, value pid which) {
  int which = check_priority_which(popSTACK());
  int pid = I_to_uint32(check_uint32(popSTACK()));
  int value = check_priority_value(STACK_0);
  bool failed_p = true;
#if defined(HAVE_SETPRIORITY)
  begin_system_call();
  failed_p = (0 != setpriority(which,pid,value));
  end_system_call();
#elif defined(WIN32_NATIVE)
  {
    HANDLE handle;
    begin_system_call();
    handle = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,pid);
    if (handle != NULL) {
      failed_p = !SetPriorityClass(handle,value);
      CloseHandle(handle);
    }
    end_system_call();
  }
#else
  NOTREACHED;
#endif
  if (failed_p) OS_error();
  VALUES1(popSTACK());
}

/* posix math functions in <math.h> */
/* Must include <math.h> */
#define decimal_string  solaris_decimal_string  /* needed on Solaris */
#undef floor  /* needed on Linux */
#include <math.h>
#define floor(a,b)  ((a) / (b))
#undef decimal_string

#define D_S           to_double(popSTACK())
#define I_S           to_int(popSTACK())
#define N_D(n,v)  \
  { double x=n; v=c_double_to_DF((dfloatjanus*)&x); }
#define VAL_D(func)   double res=func(D_S); N_D(res,value1)
#define VAL_ID(func)  \
 double xx=D_S; int nn=I_S; double res=func(nn,xx); N_D(res,value1)

#if defined(HAVE_ERFC)
DEFUNF(POSIX::ERF,x) { VAL_D(erf); mv_count=1; }
#endif
#if defined(HAVE_ERFC)
DEFUNF(POSIX::ERFC,x) { VAL_D(erfc); mv_count=1; }
#endif

DEFUNF(POSIX::J0,x) { VAL_D(j0); mv_count=1; }
DEFUNF(POSIX::J1,x) { VAL_D(j1); mv_count=1; }
DEFUNF(POSIX::JN,i x) { VAL_ID(jn); mv_count=1; }
DEFUNF(POSIX::Y0,x) { VAL_D(y0); mv_count=1; }
DEFUNF(POSIX::Y1,x) { VAL_D(y1); mv_count=1; }
DEFUNF(POSIX::YN,i y) { VAL_ID(yn); mv_count=1; }
#if defined(HAVE_TGAMMA)
/* http://www.opengroup.org/onlinepubs/009695399/functions/tgamma.html */
DEFUNF(POSIX::TGAMMA,x) { VAL_D(tgamma); mv_count=1; }
#endif

#if defined(HAVE_LGAMMA) || HAVE_DECL_LGAMMA_R
/* http://www.opengroup.org/onlinepubs/009695399/functions/lgamma.html */
DEFUNF(POSIX::LGAMMA,x) {
# if HAVE_DECL_LGAMMA_R
  int sign;
  double res = lgamma_r(D_S,&sign);
  value2 = (sign > 0 ? Fixnum_1 : Fixnum_minus1);
# else
  double res = lgamma(D_S);
# if HAVE_DECL_SIGNGAM
  value2 = (signgam > 0 ? Fixnum_1 : Fixnum_minus1);
# else
  value2 = NIL;
# endif
# endif
  N_D(res,value1); mv_count=2;
}
#endif

extern double bogomips (void);
DEFUN(OS:BOGOMIPS,) { N_D(bogomips(),value1); mv_count=1; }

#if defined(HAVE_GETLOADAVG)
DEFUN(POSIX:LOADAVG, &optional percentp) {
  double loadavg[3];
  int ret;
  begin_system_call();
  ret = getloadavg(loadavg,3);
  end_system_call();
  if (ret != 3) OS_error();
  mv_count=3;
  if (missingp(STACK_0)) {
    N_D(loadavg[0],value1); pushSTACK(value1);
    N_D(loadavg[1],value1); pushSTACK(value1);
    N_D(loadavg[2],value3);
    value2 = popSTACK(); value1 = popSTACK();
  } else { /* return % as ints, to avoid consing */
    value1 = fixnum((int)round(loadavg[0]*100));
    value2 = fixnum((int)round(loadavg[1]*100));
    value3 = fixnum((int)round(loadavg[2]*100));
  }
  skipSTACK(1);
}
#endif  /* HAVE_GETLOADAVG */

#undef D_S
#undef I_S
#undef N_D
#undef VAL_D
#undef VAL_ID

/* "gcc --mno-cygwin -l crypt" links with cygwin lib-crypt,
   so we have to disable this explicitly */
#if defined(HAVE_CRYPT) && !defined(WIN32_NATIVE)
DEFUN(POSIX::CRYPT, key salt) {
  char *result;
  STACK_0 = check_string(STACK_0);
  STACK_1 = check_string(STACK_1);
  with_string_0(STACK_0,GLO(misc_encoding),salt, {
      with_string_0(STACK_1,GLO(misc_encoding),key, {
          begin_system_call();
          result = crypt(key,salt);
          end_system_call();
        });
    });
  if (result == NULL) OS_error();
  VALUES1(asciz_to_string(result,GLO(misc_encoding)));
  skipSTACK(2);
}
#endif
#if defined(HAVE_ENCRYPT) || defined(HAVE_SETKEY)
/* move information from a bit vector to the char block
 can trigger GC */
static void get_block (char block[64], object vector) {
  while (!bit_vector_p(Atype_8Bit,vector)
         || vector_length(vector) != 8) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(vector);          /* TYPE-ERROR slot DATUM */
    pushSTACK(`(VECTOR (UNSIGNED-BYTE 8) 8)`); /* EXPECTED-TYPE */
    pushSTACK(STACK_0); pushSTACK(vector);
    pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not of type ~S"));
    vector = value1;
  }
  {
    uintL index=0, ii, jj, kk=0;
    object dv = array_displace_check(vector,8,&index);
    uint8* ptr1 = TheSbvector(dv)->data + index;
    for (ii = 0; ii<8; ii++) {
      uint8 bb = *ptr1++;
      for (jj = 0; jj<8; jj++)
        block[kk++] = ((bb & bit(jj)) != 0);
    }
  }
}
#endif
#if defined(HAVE_ENCRYPT) && !defined(WIN32_NATIVE)
/* the inverse of get_block(): move data from block to vector,
 which is known to be a (VECTOR BIT) */
static void set_block (char block[64], object vector) {
  uintL index=0, ii, jj, kk=0;
  object dv = array_displace_check(vector,8,&index);
  uint8* ptr1 = TheSbvector(dv)->data + index;
  for (ii = 0; ii<8; ii++) {
    uint8 bb = 0;
    for (jj = 0; jj<8; jj++)
      bb |= (block[kk++]!=0) << jj;
    *ptr1++ = bb;
  }
}
DEFUN(POSIX::ENCRYPT, block flag) {
  int flag = nullp(popSTACK());
  char block[64];
  bool failed_p;
  get_block(block,STACK_0);
  begin_system_call();
  errno = 0; encrypt(block,flag); failed_p = (errno != 0);
  end_system_call();
  if (failed_p) OS_error();
  set_block(block,STACK_0);
  VALUES1(popSTACK());
}
#endif
#if defined(HAVE_SETKEY) && !defined(WIN32_NATIVE)
DEFUN(POSIX::SETKEY, key) {
  char block[64];
  bool failed_p;
  get_block(block,popSTACK());
  begin_system_call();
  errno = 0; setkey(block); failed_p = (errno != 0);
  end_system_call();
  if (failed_p) OS_error();
  VALUES0;
}
#endif

/* ========= SYSTEM INFORMATION ========== */
#include <sys/utsname.h>
DEFUN(POSIX::UNAME,)
{ /* Lisp interface to uname(2) */
  struct utsname utsname;
  begin_system_call(); uname(&utsname); end_system_call();
  pushSTACK(safe_to_string(utsname.sysname));
  pushSTACK(safe_to_string(utsname.nodename));
  pushSTACK(safe_to_string(utsname.release));
  pushSTACK(safe_to_string(utsname.version));
  pushSTACK(safe_to_string(utsname.machine));
  funcall(`POSIX::MAKE-UNAME`,5);
}

#if defined(HAVE_SYSCONF)
DEFCHECKER(sysconf_arg,prefix=_SC,default=,                             \
           AIO-LISTIO-MAX AIO-MAX AIO-PRIO-DELTA-MAX                    \
           ARG-MAX ATEXIT-MAX BC-BASE-MAX BC-DIM-MAX BC-SCALE-MAX       \
           BC-STRING-MAX CHILD-MAX CLK-TCK COLL-WEIGHTS-MAX DELAYTIMER-MAX \
           EXPR-NEST-MAX HOST-NAME-MAX IOV-MAX LINE-MAX LOGIN-NAME-MAX  \
           NGROUPS-MAX GETGR-R-SIZE-MAX GETPW-R-SIZE-MAX MQ-OPEN-MAX    \
           MQ-PRIO-MAX OPEN-MAX ADVISORY-INFO BARRIERS ASYNCHRONOUS-IO  \
           CLOCK-SELECTION CPUTIME FSYNC IPV6 JOB-CONTROL MAPPED-FILES  \
           MEMLOCK MEMLOCK-RANGE MEMORY-PROTECTION MESSAGE-PASSING      \
           MONOTONIC-CLOCK PRIORITIZED-IO PRIORITY-SCHEDULING RAW-SOCKETS \
           READER-WRITER-LOCKS REALTIME-SIGNALS REGEXP SAVED-IDS SEMAPHORES \
           SHARED-MEMORY-OBJECTS SHELL SPAWN SPIN-LOCKS SPORADIC-SERVER \
           SS-REPL-MAX SYNCHRONIZED-IO THREAD-ATTR-STACKADDR            \
           THREAD-ATTR-STACKSIZE THREAD-CPUTIME THREAD-PRIO-INHERIT     \
           THREAD-PRIO-PROTECT THREAD-PRIORITY-SCHEDULING               \
           THREAD-PROCESS-SHARED THREAD-SAFE-FUNCTIONS THREAD-SPORADIC-SERVER \
           THREAD-ROBUST-PRIO-INHERIT THREAD-ROBUST-PRIO-PROTECT THREADS \
           TIMEOUTS TIMERS TRACE TRACE-EVENT-FILTER                     \
           TRACE-EVENT-NAME-MAX TRACE-INHERIT TRACE-LOG TRACE-NAME-MAX  \
           TRACE-SYS-MAX TRACE-USER-EVENT-MAX TYPED-MEMORY-OBJECTS :VERSION \
           XBS5-ILP32-OFF32 XBS5-ILP32-OFFBIG XBS5-LP64-OFF64 XBS5-LPBIG-OFFBIG\
           V6-ILP32-OFF32 V6-ILP32-OFFBIG V6-LP64-OFF64 V6-LPBIG-OFFBIG \
           V7-ILP32-OFF32 V7-ILP32-OFFBIG V7-LP64-OFF64 V7-LPBIG-OFFBIG \
           2-C-BIND 2-C-DEV 2-CHAR-TERM 2-FORT-DEV 2-FORT-RUN 2-LOCALEDEF \
           2-PBS 2-PBS-ACCOUNTING 2-PBS-CHECKPOINT 2-PBS-LOCATE 2-PBS-MESSAGE \
           2-PBS-TRACK 2-SW-DEV 2-UPE 2-VERSION PAGESIZE PHYS-PAGES     \
           AVPHYS-PAGES THREAD-DESTRUCTOR-ITERATIONS THREAD-KEYS-MAX    \
           THREAD-STACK-MIN THREAD-THREADS-MAX RE-DUP-MAX RTSIG-MAX     \
           SEM-NSEMS-MAX SEM-VALUE-MAX SIGQUEUE-MAX STREAM-MAX SYMLOOP-MAX \
           TIMER-MAX TTY-NAME-MAX TZNAME-MAX XOPEN-CRYPT                \
           XOPEN-ENH-I18N XOPEN-LEGACY XOPEN-REALTIME XOPEN-REALTIME-THREADS \
           XOPEN-SHM XOPEN-STREAMS XOPEN-UNIX XOPEN-UUCP XOPEN-VERSION \
           NPROCESSORS-CONF NPROCESSORS-ONLN)
DEFUN(POSIX::SYSCONF, &optional what)
{ /* Lisp interface to sysconf(3c) */
  object what = popSTACK();
  if (!missingp(what)) {
    int cmd = sysconf_arg(what), res;
    begin_system_call(); res = sysconf(cmd); end_system_call();
    VALUES1(L_to_I(res));
  } else { /* all possible values */
    int pos = 0;
    for (; pos < sysconf_arg_map.size; pos++) {
      int res;
      begin_system_call();
      res = sysconf(sysconf_arg_map.table[pos].c_const);
      end_system_call();
      pushSTACK(*sysconf_arg_map.table[pos].l_const);
      pushSTACK(L_to_I(res));
    }
    VALUES1(listof(2*sysconf_arg_map.size));
  }
}
#endif /* HAVE_SYSCONF */

#if defined(HAVE_CONFSTR)
DEFCHECKER(confstr_arg,prefix=_CS,PATH POSIX-V6-ILP32-OFF32-CFLAGS      \
           POSIX-V6-ILP32-OFF32-LDFLAGS POSIX-V6-ILP32-OFF32-LIBS       \
           POSIX-V6-ILP32-OFFBIG-CFLAGS POSIX-V6-ILP32-OFFBIG-LDFLAGS   \
           POSIX-V6-ILP32-OFFBIG-LIBS POSIX-V6-LP64-OFF64-CFLAGS        \
           POSIX-V6-LP64-OFF64-LDFLAGS POSIX-V6-LP64-OFF64-LIBS         \
           POSIX-V6-LPBIG-OFFBIG-CFLAGS POSIX-V6-LPBIG-OFFBIG-LDFLAGS   \
           POSIX-V6-LPBIG-OFFBIG-LIBS POSIX-V6-WIDTH-RESTRICTED-ENVS    \
           V7-ENV POSIX-V7-ILP32-OFF32-CFLAGS POSIX-V7-ILP32-OFF32-LDFLAGS \
           POSIX-V7-ILP32-OFF32-LIBS POSIX-V7-ILP32-OFFBIG-CFLAGS       \
           POSIX-V7-ILP32-OFFBIG-LDFLAGS POSIX-V7-ILP32-OFFBIG-LIBS     \
           POSIX-V7-LP64-OFF64-CFLAGS POSIX-V7-LP64-OFF64-LDFLAGS       \
           POSIX-V7-LP64-OFF64-LIBS POSIX-V7-LPBIG-OFFBIG-CFLAGS        \
           POSIX-V7-LPBIG-OFFBIG-LDFLAGS POSIX-V7-LPBIG-OFFBIG-LIBS     \
           POSIX-V7-THREADS-CFLAGS POSIX-V7-THREADS-LDFLAGS             \
           POSIX-V7-WIDTH-RESTRICTED-ENVS                               \
           XBS5-ILP32-OFF32-CFLAGS XBS5-ILP32-OFF32-LDFLAGS             \
           XBS5-ILP32-OFF32-LIBS XBS5-ILP32-OFF32-LINTFLAGS             \
           XBS5-ILP32-OFFBIG-CFLAGS XBS5-ILP32-OFFBIG-LDFLAGS           \
           XBS5-ILP32-OFFBIG-LIBS XBS5-ILP32-OFFBIG-LINTFLAGS           \
           XBS5-LP64-OFF64-CFLAGS XBS5-LP64-OFF64-LDFLAGS               \
           XBS5-LP64-OFF64-LIBS XBS5-LP64-OFF64-LINTFLAGS               \
           XBS5-LPBIG-OFFBIG-CFLAGS XBS5-LPBIG-OFFBIG-LDFLAGS           \
           XBS5-LPBIG-OFFBIG-LIBS XBS5-LPBIG-OFFBIG-LINTFLAGS)
DEFUN(POSIX::CONFSTR, &optional what)
{ /* Lisp interface to confstr(3c) */
#define CS_S(cmd) \
  begin_system_call(); res = confstr(cmd,buf,BUFSIZ); end_system_call(); \
  if (res == 0) value1 = T;                                             \
  else if (res <= BUFSIZ) value1 = asciz_to_string(buf,GLO(misc_encoding)); \
  else {                                                                \
    /* Here we cannot use alloca(), because alloca() is generally unsafe \
       for sizes > BUFSIZ. */                                           \
    char *tmp = (char*)clisp_malloc(res);                               \
    begin_system_call();                                                \
    confstr(cmd,tmp,res);                                               \
    end_system_call();                                                  \
    /* FIXME: asciz_to_string may signal an error in which case tmp leaks */ \
    value1 = asciz_to_string(tmp,GLO(misc_encoding));                   \
    begin_system_call();                                                \
    free(tmp);                                                          \
    end_system_call();                                                  \
  }

  size_t res;
  char buf[BUFSIZ];
  object what = popSTACK();
  if (!missingp(what)) {
    int cmd = confstr_arg(what);
    CS_S(cmd); mv_count = 1;
  } else { /* all possible values */
    unsigned int pos = 0;
    for (; pos < confstr_arg_map.size; pos++) {
      CS_S(confstr_arg_map.table[pos].c_const);
      pushSTACK(*confstr_arg_map.table[pos].l_const);
      pushSTACK(value1);
    }
    VALUES1(listof(2*confstr_arg_map.size));
  }
}
#endif /* HAVE_CONFSTR */

#if defined(HAVE_PATHCONF) && defined(HAVE_FPATHCONF)
DEFCHECKER(pathconf_arg,prefix=_PC,default=,FILESIZEBITS LINK-MAX MAX-CANON \
           MAX-INPUT NAME-MAX PATH-MAX PIPE-BUF 2-SYMLINKS ALLOC-SIZE-MIN \
           REC-INCR-XFER-SIZE REC-MAX-XFER-SIZE REC-MIN-XFER-SIZE       \
           REC-XFER-ALIGN SYMLINK-MAX CHOWN-RESTRICTED NO-TRUNC VDISABLE \
           ASYNC-IO PRIO-IO SYNC-IO SOCK-MAXBUF)
#define DO_PATHCONF(f,spec,what)                                \
  if (missingp(what)) { /* all possible values */               \
    unsigned int pos = 0;                                       \
    for (; pos < pathconf_arg_map.size; pos++) {                \
      long res;                                                 \
      begin_system_call();                                      \
      res = f(spec,pathconf_arg_map.table[pos].c_const);        \
      end_system_call();                                        \
      pushSTACK(*pathconf_arg_map.table[pos].l_const);          \
      pushSTACK(res == -1 ? S(Kerror) : L_to_I(res));           \
    }                                                           \
    VALUES1(listof(2*pathconf_arg_map.size));                   \
  } else {                                                      \
    long res;                                                   \
    begin_system_call();                                        \
    if ((res = f(spec,pathconf_arg(what))) == -1) OS_error();   \
    end_system_call();                                          \
    VALUES1(L_to_I(res));                                       \
  }
DEFUN(POSIX::PATHCONF, pathspec &optional what)
{ /* http://www.opengroup.org/onlinepubs/009695399/functions/pathconf.html */
  Handle fd;
  if (integerp(STACK_1)) {
    fd = I_to_UL(STACK_1);
   pathconf_fd: DO_PATHCONF(fpathconf,fd,STACK_0);
  } else {
    object file = open_file_stream_handle(STACK_1,&fd,true);
    if (eq(nullobj,file)) {    /* not an open stream ==> use truename */
      with_string_0(STACK_1 = physical_namestring(STACK_1),
                    GLO(pathname_encoding), namez,
          { DO_PATHCONF(pathconf,namez,STACK_0); });
    } else goto pathconf_fd;       /* open stream ==> use fd */
  }
  skipSTACK(2);
}
#endif  /* HAVE_PATHCONF && HAVE_FPATHCONF */

#if defined(HAVE_SYS_RESOURCE_H)
static /*maygc*/ Values rusage_to_lisp (struct rusage *ru) {
  int count = 2;
  pushSTACK(sec_usec_number(ru->ru_utime.tv_sec,ru->ru_utime.tv_usec,0));
  pushSTACK(sec_usec_number(ru->ru_stime.tv_sec,ru->ru_stime.tv_usec,0));
  pushSTACK(L_to_I(ru->ru_maxrss)); count++;
  pushSTACK(L_to_I(ru->ru_ixrss)); count++;
  pushSTACK(L_to_I(ru->ru_idrss)); count++;
  pushSTACK(L_to_I(ru->ru_isrss)); count++;
  pushSTACK(L_to_I(ru->ru_minflt)); count++;
  pushSTACK(L_to_I(ru->ru_majflt)); count++;
  pushSTACK(L_to_I(ru->ru_nswap)); count++;
  pushSTACK(L_to_I(ru->ru_inblock)); count++;
  pushSTACK(L_to_I(ru->ru_oublock)); count++;
  pushSTACK(L_to_I(ru->ru_msgsnd)); count++;
  pushSTACK(L_to_I(ru->ru_msgrcv)); count++;
  pushSTACK(L_to_I(ru->ru_nsignals)); count++;
  pushSTACK(L_to_I(ru->ru_nvcsw)); count++;
  pushSTACK(L_to_I(ru->ru_nivcsw)); count++;
  funcall(`POSIX::MAKE-USAGE`,count);
}

#if defined(HAVE_SYS_WAIT_H)
#if !defined(HAVE_WAIT4)
#  define wait4(p,s,o,r)  (errno=ENOSYS,OS_error(),(pid_t)-1)
#endif
DEFFLAGSET(wait_flags, WNOHANG WUNTRACED WSTOPPED WEXITED WCONTINUED WNOWAIT)
DEFUN(POSIX::WAIT, &key :PID :USAGE :NOHANG :UNTRACED :STOPPED :EXITED \
      :CONTINUED :NOWAIT) {
  int status, options = wait_flags();
  bool usage = !missingp(STACK_0);
  pid_t ret, pid = missingp(STACK_1) ? (pid_t)-1 : I_to_pid(STACK_1);
  struct rusage ru;
  begin_blocking_system_call();
  begin_want_sigcld();
  ret = usage ? wait4(pid,&status,options,&ru) : waitpid(pid,&status,options);
  end_want_sigcld();
  end_blocking_system_call();
  if (ret == (pid_t)-1) OS_error();
  if (ret == (pid_t)0 && (options & WNOHANG))
    VALUES1(Fixnum_0);          /* no process changed status */
  else {                        /* some process changed status */
    if (usage) {
      rusage_to_lisp(&ru);
      STACK_0 = value1;
      mv_count = 4;
    } else mv_count = 3;
    STACK_1 = pid_to_I(ret);
    if (WIFEXITED(status)) {
      value2 = `:EXITED`;
      value3 = fixnum(WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      value3 = check_signal_reverse(WTERMSIG(status));
      value2 = `:SIGNALED`;
    } else if (WIFSTOPPED(status)) {
      value3 = check_signal_reverse(WSTOPSIG(status));
      value2 = `:STOPPED`;
#if defined(WIFCONTINUED)       /* cygwin does not have this */
    } else if (WIFCONTINUED(status)) {
      value2 = `:CONTINUED`;
      value3 = NIL;
#endif
    } else {
      value2 = NIL;
      value3 = fixnum(status);
    }
    value1 = STACK_1;
    if (usage) value4 = STACK_0;
  }
  skipSTACK(2);
}
#endif  /* HAVE_SYS_WAIT_H */

#if defined(HAVE_GETRUSAGE)
DEFUN(POSIX::USAGE,) { /* getrusage(3) */
  struct rusage ru;
#define GETRU(who) begin_system_call(); getrusage(who,&ru); end_system_call(); rusage_to_lisp(&ru); pushSTACK(value1)
  GETRU(RUSAGE_CHILDREN); GETRU(RUSAGE_SELF);
#undef GETRU
  VALUES2(STACK_0,STACK_1); skipSTACK(2);
}
#endif /* HAVE_GETRUSAGE */
#endif /* HAVE_SYS_RESOURCE_H */

#if defined(HAVE_GETRLIMIT) || defined(HAVE_SETRLIMIT)
DEFCHECKER(getrlimit_arg,prefix=RLIMIT, CPU FSIZE DATA STACK CORE RSS NOFILE \
           AS NPROC MEMLOCK LOCKS)
#if SIZEOF_RLIMT_T == 8
# define rlim_to_I_0(lim) uint64_to_I(lim)
# define I_to_rlim_0(lim) I_to_uint64(check_uint64(lim))
#else
# define rlim_to_I_0(lim) uint32_to_I(lim)
# define I_to_rlim_0(lim) I_to_uint32(check_uint32(lim))
#endif
static /* maygc */ inline object rlim_to_I (rlim_t lim)
{ return lim == RLIM_INFINITY ? NIL : rlim_to_I_0(lim); }
static /* maygc */ inline rlim_t I_to_rlim (object lim)
{ return missingp(lim) ? RLIM_INFINITY : I_to_rlim_0(lim); }
#endif /* HAVE_GETRLIMIT || HAVE_SETRLIMIT */
#if defined(HAVE_GETRLIMIT)
DEFUN(POSIX::RLIMIT, &optional what)
{ /* getrlimit(3) */
  struct rlimit rl;
  object what = popSTACK();
  if (!missingp(what)) {
    int cmd = getrlimit_arg(what);
    begin_system_call();
    if (getrlimit(cmd,&rl)) OS_error();
    end_system_call();
    pushSTACK(rlim_to_I(rl.rlim_cur)); pushSTACK(rlim_to_I(rl.rlim_max));
    VALUES2(STACK_1,STACK_0); skipSTACK(2);
  } else {
    unsigned int pos;
    for (pos = 0; pos < getrlimit_arg_map.size; pos++) {
      int status;
      pushSTACK(*getrlimit_arg_map.table[pos].l_const);
      begin_system_call();
      status = getrlimit(getrlimit_arg_map.table[pos].c_const,&rl);
      end_system_call();
      if (status) pushSTACK(S(Kerror));
      else {
        pushSTACK(rlim_to_I(rl.rlim_cur)); pushSTACK(rlim_to_I(rl.rlim_max));
        funcall(`POSIX::MAKE-RLIMIT`,2); pushSTACK(value1);
      }
    }
    VALUES1(listof(2*getrlimit_arg_map.size));
  }
}
#endif /* HAVE_GETRLIMIT */
#if defined(HAVE_SETRLIMIT)
/* parse the RLIMIT structure
   NOTE: arg is intentionally not reset by check_classname
   to avoid argument modification
 can trigger GC */
static void check_rlimit (object arg, struct rlimit *rl) {
  pushSTACK(check_classname(arg,`POSIX::RLIMIT`));
  rl->rlim_cur = I_to_rlim(TheStructure(STACK_0)->recdata[1]);
  rl->rlim_max = I_to_rlim(TheStructure(STACK_0)->recdata[2]);
  skipSTACK(1);
}
DEFUN(POSIX::SET-RLIMIT, what cur max)
{ /* setrlimit(3): 3 ways to call:
   (setf (rlimit what) (values cur max))
   (setf (rlimit what) #S(rlimit :cur cur :max max))
   (setf (rlimit) rlimit-alist-as-returned-by-rlimit-without-arguments) */
  if (nullp(STACK_2)) {         /* 3rd way */
    if (!nullp(STACK_0)) goto rlimit_bad;
    STACK_0 = STACK_1;
    while (!endp(STACK_0)) {
      int what = getrlimit_arg(Car(STACK_0));
      struct rlimit rl;
      STACK_0 = Cdr(STACK_0);
      if (!consp(STACK_0)) { STACK_0 = NIL; goto rlimit_bad; }
      check_rlimit(Car(STACK_0),&rl);
      STACK_0 = Cdr(STACK_0);
      begin_system_call();
      if (setrlimit(what,&rl)) OS_error();
      end_system_call();
    }
  } else {
    int what = getrlimit_arg(STACK_2);
    struct rlimit rl;
    if (nullp(STACK_1) || posfixnump(STACK_1)) { /* 1st way */
      rl.rlim_cur = I_to_rlim(STACK_1);
      rl.rlim_max = I_to_rlim(STACK_0);
    } else {                    /* 2nd way */
      if (!nullp(STACK_0)) goto rlimit_bad;
      check_rlimit(STACK_1,&rl);
    }
    begin_system_call();
    if (setrlimit(what,&rl)) OS_error();
    end_system_call();
  }
  VALUES2(STACK_1,STACK_0); skipSTACK(3); return;
 rlimit_bad:
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: bad arguments: ~S ~S ~S"));
}
#endif /* HAVE_SETRLIMIT */

/* ==== SOCKETS ===== */
#if defined(HAVE_NETDB_H)
# include <netdb.h>
#endif
#if defined(HAVE_NETINET_IN_H)
# include <netinet/in.h>
#endif
#if defined(HAVE_ARPA_INET_H)
# include <arpa/inet.h>
#endif

#define H_ERRMSG                                                           \
        (h_errno == HOST_NOT_FOUND ? "host not found" :                    \
         (h_errno == TRY_AGAIN ? "try again later" :                       \
          (h_errno == NO_RECOVERY ? "a non-recoverable error occurred" :   \
           (h_errno == NO_DATA ? "valid name, but no data for this host" : \
            (h_errno == NO_ADDRESS ? "no IP address for this host" :       \
             "unknown error")))))

#if 0
void print_he (struct hostent *he) {
 int ii;
 char **pp;
 struct in_addr in;
 printf("h_name: %s; h_length: %d; h_addrtype: %d\n [size in.s_addr: %d]\n",
        he->h_name,he->h_length,he->h_addrtype,sizeof(in.s_addr));
 for (pp = he->h_aliases; *pp != 0; pp++) printf("\t%s", *pp);
 printf("\n IP:");
 for (pp = he->h_addr_list; *pp != 0; pp++) {
   (void) memcpy(&in.s_addr, *pp, sizeof (in.s_addr));
   (void) printf("\t%s", inet_ntoa(in));
 }
 printf("\n");
}
#endif

/* C struct hostent --> Lisp HOSTENT structure
 can trigger GC */
Values hostent_to_lisp (struct hostent *he); /* used by NEW-CLX => not static */
Values hostent_to_lisp (struct hostent *he) {
  pushSTACK(ascii_to_string(he->h_name));
  push_string_array(he->h_aliases);
  { int ii = 0;
    for (; he->h_addr_list[ii]; ii++)
      pushSTACK(addr_to_string(he->h_addrtype,he->h_addr_list[ii]));
    { object tmp = listof(ii); pushSTACK(tmp); }}
  pushSTACK(fixnum(he->h_addrtype));
  funcall(`POSIX::MAKE-HOSTENT`,4);
}

DEFUN(POSIX::RESOLVE-HOST-IPADDR,&optional host)
{ /* Lisp interface to gethostbyname(3) and gethostbyaddr(3) */
  object arg = popSTACK();
  struct hostent *he = NULL;

  if (missingp(arg)) {
#  if !defined(HAVE_GETHOSTENT)
    VALUES1(NIL);
#  else
    int count = 0;
    begin_system_call();
    sethostent(1);
    for (; (he = gethostent()); count++) {
      end_system_call();
      hostent_to_lisp(he); pushSTACK(value1);
      begin_system_call();
    }
    endhostent();
    end_system_call();
    VALUES1(listof(count));
#  endif
    return;
  }

  he = resolve_host(arg);

  if (he == NULL) {
    pushSTACK(arg); pushSTACK(arg);
    STACK_1 = ascii_to_string(H_ERRMSG);
    pushSTACK(`POSIX::RESOLVE-HOST-IPADDR`);
    error(os_error,"~S (~S): ~S");
  }

  hostent_to_lisp(he);
}

#if (defined(HAVE_GETSERVBYPORT) && defined(HAVE_GETSERVBYNAME)) || defined(WIN32_NATIVE)
/* Lisp interface to getservbyport(3) and getservbyname(3) */

/* C struct servent --> Lisp SERVICE structure
 can trigger GC */
static Values servent_to_lisp (struct servent * se) {
  pushSTACK(safe_to_string(se->s_name));
  push_string_array(se->s_aliases);
  pushSTACK(L_to_I(ntohs(se->s_port)));
  pushSTACK(safe_to_string(se->s_proto));
  funcall(`POSIX::MAKE-SERVICE`,4);
}

DEFUN(POSIX:SERVICE, &optional service-name protocol) {
  object protocol = popSTACK();
  char *proto = NULL;
  char proto_buf[16];
  object serv;
  struct servent * se;
  if (!missingp(protocol)) {    /* check protocol */
    with_string_0(check_string(protocol),Symbol_value(GLO(misc_encoding)),
                  protocolz, {
                    begin_system_call();
                    strncpy(proto_buf,protocolz,15);
                    end_system_call();
                  });
    proto = proto_buf;
    proto_buf[15] = 0;
  }
  serv = popSTACK();
  if (missingp(serv)) {
    uintL count = 0;
#  if defined(HAVE_SETSERVENT) && defined(HAVE_GETSERVENT) && defined(HAVE_ENDSERVENT)
    begin_system_call();
    setservent(1);
    for (; (se = getservent()); count++) {
      end_system_call();
      servent_to_lisp(se); pushSTACK(value1);
      begin_system_call();
    }
    endservent();
    end_system_call();
#  else /* no getservent - emulate */
    uintL port;
    begin_system_call();
    for (port = 0; port < 0x10000; port++) {
      se = getservbyport(port,proto);
      if (se != NULL) {
        end_system_call();
        servent_to_lisp(se); pushSTACK(value1); count++;
        begin_system_call();
      }
    }
    end_system_call();
#  endif
    VALUES1(listof(count));
    return;
  } else if (symbolp(serv)) {
    serv = Symbol_name(serv);
    goto servent_string;
  } else if (stringp(serv)) { servent_string:
    with_string_0(serv,GLO(misc_encoding),servz, {
        begin_system_call();
        se = getservbyname(servz,proto);
        end_system_call();
      });
  } else if (integerp(serv)) {
    uintL port = I_to_UL(serv);
    begin_system_call();
    se = getservbyport(htons(port),proto);
    end_system_call();
  } else
    error_string_integer(serv);
  if (se == NULL) OS_error();
  servent_to_lisp(se);
}

#endif /* getservbyname getservbyport */

#if defined(HAVE_GETGRGID) && defined(HAVE_GETGRNAM)

#if defined(HAVE_GRP_H)
# include <grp.h>
#endif

/* C struct group --> Lisp GROUP-INFO structure
 can trigger GC */
static Values grp_to_lisp (struct group *group) {
  pushSTACK(safe_to_string(group->gr_name));
  pushSTACK(gid_to_I(group->gr_gid));
  push_string_array(group->gr_mem);
  funcall(`POSIX::MAKE-GROUP-INFO`,3);
}

DEFUN(POSIX::GROUP-INFO, &optional group)
{ /* return the GROUP-INFO for the group or a list thereof if it is NIL. */
  object group = popSTACK();
  struct group *gr = NULL;
  bool failed_p;
 group_info_restart:

# if defined(HAVE_GETGRENT) && defined(HAVE_SETGRENT) && defined(HAVE_ENDGRENT)
  if (missingp(group)) { /* all groups as a list */
    int count = 0;
    begin_system_call();
    setgrent();
    for (; (gr = getgrent()); count++) {
      end_system_call();
      grp_to_lisp(gr); pushSTACK(value1);
      begin_system_call();
    }
    endgrent();
    end_system_call();
    VALUES1(listof(count));
    return;
  }
# endif  /* setgrent getgrent endgrent */

  begin_system_call();
  errno = 0;
  if (integerp(group))
    gr = getgrgid(I_to_gid(group));
  else if (symbolp(group)) {
    group = Symbol_name(group);
    goto group_info_string;
  } else if (stringp(group)) { group_info_string:
    with_string_0(group,GLO(misc_encoding),groupz, { gr = getgrnam(groupz); });
  } else {
    end_system_call(); error_string_integer(group);
  }
  failed_p = (errno != 0);
  end_system_call();

  if (NULL == gr) {
    if (!failed_p) {
      pushSTACK(NIL);           /* no PLACE */
      pushSTACK(group); pushSTACK(TheSubr(subr_self)->name);
      check_value(error_condition,GETTEXT("~S(~S): No such group"));
      group = value1;
      goto group_info_restart;
    } else OS_error();
  }
  grp_to_lisp(gr);
}
#endif  /* getgrgid getgrnam */

#if defined(HAVE_GETLOGIN) && defined(HAVE_GETPWNAM) && defined(HAVE_GETPWUID) && defined(HAVE_GETUID)

#if defined(HAVE_PWD_H)
# include <pwd.h>
#endif

/* C struct passwd --> Lisp USER-INFO structure
 can trigger GC */
static Values passwd_to_lisp (struct passwd *pwd) {
  pushSTACK(safe_to_string(pwd->pw_name));
  pushSTACK(safe_to_string(pwd->pw_passwd));
  pushSTACK(UL_to_I(pwd->pw_uid));
  pushSTACK(UL_to_I(pwd->pw_gid));
  pushSTACK(safe_to_string(pwd->pw_gecos));
  pushSTACK(safe_to_string(pwd->pw_dir));
  pushSTACK(safe_to_string(pwd->pw_shell));
  funcall(`POSIX::MAKE-USER-INFO`,7);
}

DEFUN(POSIX::USER-INFO, &optional user)
{ /* return the USER-INFO for the user or a list thereof if user is NIL. */
  object user = popSTACK();
  struct passwd *pwd = NULL;
  bool failed_p;
 user_info_restart:

# if defined(HAVE_GETPWENT) && defined(HAVE_SETPWENT) && defined(HAVE_ENDPWENT)
  if (missingp(user)) { /* all users as a list */
    int count = 0;
    begin_system_call();
    setpwent();
    for (; (pwd = getpwent()); ) {
      /* on cygwin uid of -1 is returned */
      /* when user has no entry in /etc/passwd */
      if (pwd->pw_uid == (uid_t) -1) continue;
      end_system_call();
      passwd_to_lisp(pwd); pushSTACK(value1);
      begin_system_call();
      count++;
    }
    endpwent();
    end_system_call();
    VALUES1(listof(count));
    return;
  }
# endif  /* setpwent getpwent endpwent */

  begin_system_call();
  errno = 0;
  if (integerp(user))
    pwd = getpwuid(I_to_uid(user));
  else if (eq(user,S(Kdefault))) {
    char *username = getlogin();
    if (username != NULL)
      pwd = getpwnam(username);
    else pwd = getpwuid(getuid());
  } else if (symbolp(user)) {
    user = Symbol_name(user);
    goto user_info_string;
  } else if (stringp(user)) { user_info_string:
    with_string_0(user,GLO(misc_encoding),userz, { pwd = getpwnam(userz); });
  } else {
    end_system_call(); error_string_integer(user);
  }
  failed_p = (errno != 0);
  end_system_call();

  if (NULL == pwd) {
    if (!failed_p) {
      pushSTACK(NIL);           /* no PLACE */
      pushSTACK(user); pushSTACK(TheSubr(subr_self)->name);
      check_value(error_condition,GETTEXT("~S(~S): No such user"));
      user = value1;
      goto user_info_restart;
    } else OS_error();
  }
  passwd_to_lisp(pwd);
}
#elif defined(WIN32_NATIVE)
/* FIXME: use
 http://msdn.microsoft.com/library/en-us/netmgmt/netmgmt/user_info_1_str.asp
 http://msdn.microsoft.com/library/en-us/netmgmt/netmgmt/netusergetinfo.asp
 http://msdn.microsoft.com/library/en-us/netmgmt/netmgmt/netuserenum.asp */
#endif  /* user-info */

#if defined(HAVE_GETUSERSHELL) && defined(HAVE_ENDUSERSHELL)
DEFUN(POSIX:USER-SHELLS,) {
  int count = 0;
  char *shell;
  begin_system_call();
  for (;(shell = getusershell()); count++) {
    end_system_call();
    pushSTACK(asciz_to_string(shell,GLO(misc_encoding)));
    begin_system_call();
  }
  endusershell();
  end_system_call();
  VALUES1(listof(count));
}
#endif  /* HAVE_GETUSERSHELL & HAVE_ENDUSERSHELL */

#if defined(HAVE_GETUID)
DEFUN(POSIX:UID,){ GETTER0(uid,getuid); }
#endif
#if defined(HAVE_SETUID)
DEFUN(POSIX::%SETUID, uid) { SETTER1(uid,setuid); }
#endif
#if defined(HAVE_GETGID)
DEFUN(POSIX:GID,){ GETTER0(gid,getgid); }
#endif
#if defined(HAVE_SETGID)
DEFUN(POSIX::%SETGID, gid) { SETTER1(gid,setgid); }
#endif
#if defined(HAVE_GETEUID)
DEFUN(POSIX:EUID,){ GETTER0(uid,geteuid); }
#endif
#if defined(HAVE_SETEUID)
DEFUN(POSIX::%SETEUID, euid) { SETTER1(uid,seteuid); }
#endif
#if defined(HAVE_GETEGID)
DEFUN(POSIX:EGID,){ GETTER0(gid,getegid); }
#endif
#if defined(HAVE_SETEGID)
DEFUN(POSIX::%SETEGID, egid) { SETTER1(gid,setegid); }
#endif
#if defined(HAVE_GETGROUPS)
DEFUN(POSIX:GROUPS,) {
  int group_count, ret;
  gid_t *groups;
  begin_system_call(); group_count = getgroups(0,NULL); end_system_call();
  groups = (gid_t*)alloca(sizeof(gid_t) * group_count);
  begin_system_call(); ret = getgroups(group_count,groups); end_system_call();
  if (ret == -1) OS_error();
  while (ret--) pushSTACK(gid_to_I(*groups++));
  VALUES1(listof(group_count));
}
#endif
#if defined(HAVE_SETGROUPS)
DEFUN(POSIX::%SETGROUPS, groups) {
  int group_count = llength1(STACK_0,NULL), i = group_count;
  gid_t *groups = (gid_t*)alloca(sizeof(gid_t) * group_count), *pgrp = groups;
  pushSTACK(STACK_0);
  while (i--) {
    *pgrp++ = I_to_gid(Car(STACK_0));
    STACK_0 = Cdr(STACK_0);
  }
  if (!nullp(popSTACK())) NOTREACHED;
  begin_system_call(); i = setgroups(group_count,groups); end_system_call();
  if (i == -1) OS_error();
  VALUES1(popSTACK());
}
#endif
#if defined(HAVE_GETHOSTID)
/* http://www.opengroup.org/onlinepubs/009695399/functions/gethostid.html */
/* this is returned as an integer, not as a string,
   because this is NOT the IP address:
   (posix:gethostid) ==> 430729603
   (rawsock:convert-address :inet 430729603) ==>  "131.105.172.25"
   (rawsock:htonl 430729603) ==> 2204740633
   (rawsock:convert-address :inet 2204740633) ==> "25.172.105.131"
   but (rawsock:resolve-host-ipaddr :default) ==> "172.25.131.105" */
DEFUN(POSIX:HOSTID,) { GETTER(unsigned long,ulong,gethostid); }
#endif
#if defined(HAVE_SETHOSTID)
#define I_to_hid(x)   I_to_ulong(check_ulong(x))
DEFUN(POSIX::%SETHOSTID, hostid) {
  unsigned long hid = I_to_ulong(check_ulong(STACK_0 = STACK_0));
  int e;
  begin_system_call(); errno = 0; sethostid(hid); e = errno; end_system_call();
  if (e) OS_error();
  VALUES1(popSTACK());
}
#endif
#ifndef MAXHOSTNAMELEN          /* see unix.d */
# define MAXHOSTNAMELEN 256     /* see <sys/param.h> */
#endif
#if defined(HAVE_GETDOMAINNAME)
DEFUN(POSIX:DOMAINNAME,) {
  char domain[MAXHOSTNAMELEN];
  int e;
  begin_system_call();
  e = getdomainname(domain,MAXHOSTNAMELEN);
  end_system_call();
  if (e) OS_error();
  VALUES1(asciz_to_string(domain,GLO(misc_encoding)));
}
#endif
#if defined(HAVE_SETDOMAINNAME)
DEFUN(POSIX::%SETDOMAINNAME, domain) {
  int e;
  with_string_0(STACK_0 = check_string(STACK_0),GLO(misc_encoding),domain, {
      begin_system_call();
      e = setdomainname(domain,domain_len);
      end_system_call();
    });
  if (e) OS_error();
  VALUES1(popSTACK());    /* return the argument for the sake of SETF */
}
#endif

#if defined(HAVE_FSTAT) && defined(HAVE_STAT)
# if !defined(HAVE_LSTAT)
#  define lstat stat
# endif
DEFUN(POSIX::FILE-STAT, file &optional linkp)
{ /* Lisp interface to stat(2), lstat(2) and fstat(2)
 the first arg can be a pathname designator or a file descriptor designator
 the return value is the FILE-STAT structure */
  bool link_p = missingp(STACK_0);
  struct stat buf;
  object file = STACK_1;
  bool error_p;

  if (integerp(file)) {
    begin_blocking_system_call();
    error_p = (fstat(I_to_UL(file),&buf) < 0);
    end_blocking_system_call();
    if (error_p) OS_error();
  } else {
    Handle fd;
    file = open_file_stream_handle(STACK_1,&fd,true);
    if (eq(nullobj,file)) {     /* not a stream - treat as a pathname */
      if (ON_PNAMESTRING(STACK_1,*(link_p ? &stat : &lstat),&buf))
        OS_file_error(value1);
      file = value1;
    } else {                    /* file is a stream, fd is valid */
#    if defined(WIN32_NATIVE)
      /* woe32 does have fstat(), but it does not accept a file handle,
         only an integer of an unknown nature */
      BY_HANDLE_FILE_INFORMATION fi;
      begin_blocking_system_call();
      error_p = !GetFileInformationByHandle(fd,&fi);
      end_blocking_system_call();
      if (error_p) error_OS_stream(STACK_1);
      pushSTACK(STACK_1);       /* file */
      pushSTACK(uint32_to_I(fi.dwVolumeSerialNumber)); /* device */
      pushSTACK(UL2_to_I(fi.nFileIndexHigh,fi.nFileIndexLow)); /* "inode" */
      pushSTACK(check_file_attributes_to_list(fi.dwFileAttributes));
      pushSTACK(uint32_to_I(fi.nNumberOfLinks)); /* number of hard links */
      pushSTACK(NIL); pushSTACK(NIL);            /* no GID or UID */
      pushSTACK(NIL);                            /* no rdev */
      pushSTACK(UL2_to_I(fi.nFileSizeHigh,fi.nFileSizeLow)); /* size */
      pushSTACK(NIL); pushSTACK(NIL); /* no blocksize od blocks */
      pushSTACK(convert_time_to_universal(&(fi.ftLastAccessTime)));
      pushSTACK(convert_time_to_universal(&(fi.ftLastWriteTime)));
      pushSTACK(convert_time_to_universal(&(fi.ftCreationTime)));
      goto call_make_file_stat;
#    else
      begin_blocking_system_call();
      error_p = (fstat(fd,&buf) < 0);
      end_blocking_system_call();
      if (error_p) error_OS_stream(STACK_1);
      file = eq(nullobj,STACK_1) ? fixnum(fd) : (object)STACK_1; /* restore */
#    endif
    }
  }

  pushSTACK(file);                    /* the object stat'ed */
  pushSTACK(L_to_I(buf.st_dev));      /* device */
#if defined(SIZEOF_INO_T) && SIZEOF_INO_T == 8
  pushSTACK(uint64_to_I(buf.st_ino)); /* inode */
#else
  pushSTACK(uint32_to_I(buf.st_ino)); /* inode */
#endif
  pushSTACK(check_chmod_mode_to_list(buf.st_mode)); /* protection */
  pushSTACK(UL_to_I(buf.st_nlink));   /* number of hard links */
  pushSTACK(UL_to_I(buf.st_uid));     /* user ID of owner */
  pushSTACK(UL_to_I(buf.st_gid));     /* group ID of owner */
#if defined(HAVE_STAT_ST_RDEV)
  pushSTACK(L_to_I(buf.st_rdev));     /* device type (if inode device) */
#else
  pushSTACK(NIL);
#endif
  pushSTACK(L_to_I(buf.st_size));     /* total size, in bytes */
#if defined(HAVE_STAT_ST_BLKSIZE)
  pushSTACK(UL_to_I(buf.st_blksize)); /* blocksize for filesystem I/O */
#else
  pushSTACK(NIL);
#endif
#if defined(HAVE_STAT_ST_BLOCKS)
  pushSTACK(UL_to_I(buf.st_blocks));  /* number of blocks allocated */
#else
  pushSTACK(NIL);
#endif
  /* cannot use convert_time_to_universal() because this is used on win32 */
  pushSTACK(UL_to_I(buf.st_atime+UNIX_LISP_TIME_DIFF));/*time of last access*/
  pushSTACK(UL_to_I(buf.st_mtime+UNIX_LISP_TIME_DIFF));/*last modification*/
  pushSTACK(UL_to_I(buf.st_ctime+UNIX_LISP_TIME_DIFF));/*time of last change*/
 call_make_file_stat:
  funcall(`POSIX::MAKE-FILE-STAT`,14);
  skipSTACK(2);                 /* drop linkp & file */
}
#endif  /* fstat lstat fstat */

#if defined(HAVE_STAT) && (defined(HAVE_CHMOD) || defined(HAVE_CHOWN) || defined(HAVE_UTIME))
/* error-signalling replacement for chmod()
   STACK_O is the path - for error reporting
 can trigger GC */
static void my_chmod (char *path, mode_t mode) {
#if defined(WIN32_NATIVE)
  if (!SetFileAttributes(path,mode)) OS_file_error(STACK_0);
#elif defined(HAVE_CHMOD)
  if (chmod(path,mode)) OS_file_error(STACK_0);
#else
  end_blocking_system_call();
  pushSTACK(CLSTEXT("~S(~S ~S ~S): this platform lacks ~S"));
  pushSTACK(TheSubr(subr_self)->name); pushSTACK(STACK_2);
  pushSTACK(`:MODE`); pushSTACK(fixnum(mode));
  pushSTACK(`"chmod()"`);
  funcall(S(warn),5);
  begin_blocking_system_call();
#endif
}
/* error-signalling replacement for chown()
   STACK_O is the path - for error reporting
 can trigger GC */
static void my_chown (char *path, uid_t uid, gid_t gid) {
#if defined(HAVE_CHOWN)
  if (chown(path,uid,gid)) OS_file_error(STACK_0);
#else
  end_blocking_system_call();
  pushSTACK(CLSTEXT("~S(~S ~S ~S ~S ~S): this platform lacks ~S"));
  pushSTACK(TheSubr(subr_self)->name); pushSTACK(STACK_2);
  pushSTACK(`:UID`); pushSTACK((uid != (uid_t)-1) ? fixnum(uid) : NIL);
  pushSTACK(`:GID`); pushSTACK((gid != (gid_t)-1) ? fixnum(gid) : NIL);
  pushSTACK(`"chown()"`);
  funcall(S(warn),7);
  begin_blocking_system_call();
#endif
}
/* error-signalling replacement for utime()
   STACK_O is the path - for error reporting
 can trigger GC */
#if !defined(WIN32_NATIVE)
static void my_utime (char *path, bool utb_a, bool utb_m, struct utimbuf *utb) {
  if (utb_a && !utb_m) {
    struct stat st;
    if (stat(path,&st) < 0) OS_file_error(STACK_0);
    utb->modtime = st.st_mtime;
  }
  if (utb_m && !utb_a) {
    struct stat st;
    if (stat(path,&st) < 0) OS_file_error(STACK_0);
    utb->actime = st.st_atime;
  }
#if defined(HAVE_UTIME)
  if (utime(path,utb)) OS_file_error(STACK_0);
#else
  end_blocking_system_call();
  pushSTACK(CLSTEXT("~S(~S ~S ~S ~S ~S): this platform lacks ~S"));
  pushSTACK(TheSubr(subr_self)->name); pushSTACK(STACK_2);
  pushSTACK(`:ATIME`);
  pushSTACK(utb_a ? convert_time_to_universal(&(utb->actime)) : NIL);
  pushSTACK(`:MTIME`);
  pushSTACK(utb_m ? convert_time_to_universal(&(utb->modtime)) : NIL);
  pushSTACK(`"utime()"`);
  funcall(S(warn),7);
  begin_blocking_system_call();
#endif
}
#else  /* WIN32_NATIVE */
/* win32 implementation of utime() is severely broken:
   http://www.codeproject.com/datetime/dstbugs.asp */
struct a_m_time { FILETIME actime; FILETIME modtime; };
static void my_utime (char *path, bool utb_a, bool utb_m, struct a_m_time *tm) {
  HANDLE hfile = CreateFile(path, GENERIC_WRITE, 0 , NULL, OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, NULL);
  BOOL success_p;
  if (hfile == INVALID_HANDLE_VALUE) OS_file_error(STACK_0);
  success_p = SetFileTime(hfile,NULL,utb_a ? &(tm->actime) : NULL,
                          utb_m ? &(tm->modtime) : NULL);
  CloseHandle(hfile);
  if (!success_p) OS_file_error(STACK_0);
}
#endif  /* WIN32_NATIVE */
#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)
/* get WIN32_FIND_DATA from the PATH
 < sh - search handle (optional)
 < wfd - file information
 < value1 - the actual path used
 can trigger GC */
static void find_first_file (object path, WIN32_FIND_DATA *wfd, HANDLE *sh) {
  HANDLE s_h = ON_PNAMESTRING(path,FindFirstFile,wfd);
  if (s_h == INVALID_HANDLE_VALUE) OS_file_error(value1);
  if (sh) *sh = s_h;
  else {
    begin_blocking_system_call();
    FindClose(s_h);
    begin_blocking_system_call();
  }
}
/* get file times from an object
 can trigger GC */
static void get_file_time (object path, FILETIME *atime, FILETIME *mtime) {
  WIN32_FIND_DATA wfd;
  find_first_file(path,&wfd,NULL);
  if (atime) *atime = wfd.ftLastAccessTime;
  if (mtime) *mtime = wfd.ftLastWriteTime;
}
#endif  /* WIN32_NATIVE | UNIX_CYGWIN32*/
DEFUN(POSIX::SET-FILE-STAT, file &key ATIME MTIME MODE UID GID)
{ /* interface to chmod(2), chown(2), utime(2)
     http://www.opengroup.org/onlinepubs/009695399/functions/utime.html
     http://www.opengroup.org/onlinepubs/009695399/functions/chown.html
     http://www.opengroup.org/onlinepubs/009695399/functions/chmod.html */
  gid_t gid = (missingp(STACK_0) ? skipSTACK(1), (gid_t)-1
               : I_to_uint32(check_uint32(popSTACK())));
  uid_t uid = (missingp(STACK_0) ? skipSTACK(1), (uid_t)-1
               : I_to_uint32(check_uint32(popSTACK())));
  mode_t mode = (missingp(STACK_0) ? skipSTACK(1), (mode_t)-1
#               if defined(WIN32_NATIVE)
                 : (mode_t)check_file_attributes_of_list(popSTACK())
#               else
                 : check_chmod_mode_of_list(popSTACK())
#               endif
                 );
# if defined(WIN32_NATIVE)
  struct a_m_time utb;
# else
  struct utimbuf utb;
# endif
  bool utb_a = false, utb_m = false;
  if (!missingp(STACK_0)) {     /* mtime */
    if (integerp(STACK_0))
      convert_time_from_universal(STACK_0,&(utb.modtime));
    else if (eq(STACK_0,T)) {
      funcall(L(get_universal_time),0);
      convert_time_from_universal(value1,&(utb.modtime));
    } else {                    /* set from another file */
#    if defined(WIN32_NATIVE)
      get_file_time(STACK_0,NULL,&(utb.modtime));
#    else
      struct stat st;
      if (ON_PNAMESTRING(STACK_0,stat,&st)) OS_file_error(value1);
      utb.modtime = st.st_mtime;
#    endif
    }
    utb_m = true;
  }
  if (!missingp(STACK_1)) {     /* atime */
    if (integerp(STACK_1))
      convert_time_from_universal(STACK_1,&(utb.actime));
    else if (eq(STACK_1,T)) {
      funcall(L(get_universal_time),0);
      convert_time_from_universal(value1,&(utb.actime));
    } else {                    /* set from another file */
#    if defined(WIN32_NATIVE)
      get_file_time(STACK_0,&(utb.actime),NULL);
#    else
      struct stat st;
      if (ON_PNAMESTRING(STACK_1,stat,&st)) OS_file_error(value1);
      utb.actime = st.st_atime;
#    endif
   }
    utb_a = true;
  }
  skipSTACK(2);                 /* drop atime & mtime */
  STACK_0 = physical_namestring(STACK_0);
  with_string_0(STACK_0,GLO(pathname_encoding),path, {
      begin_blocking_system_call();
      if (mode != (mode_t)-1) my_chmod(path,mode);
      if ((uid != (uid_t)-1) || (gid != (gid_t)-1)) my_chown(path,uid,gid);
      if (utb_a || utb_m) my_utime(path,utb_a,utb_m,&utb);
      end_blocking_system_call();
    });
  VALUES0; skipSTACK(1);
}
#endif  /* chmod chown utime */

/* <http://www.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html> */
DEFCHECKER(check_chmod_mode, type=mode_t, reverse=UL_to_I,      \
           prefix=S_I, delim=, default=, bitmasks=both,         \
           SUID SGID SVTX RWXU RUSR WUSR XUSR RWXG RGRP         \
           WGRP XGRP RWXO ROTH WOTH XOTH)
DEFUN(POSIX::CONVERT-MODE, mode)
{ /* convert between symbolic and numeric permissions */
  VALUES1(integerp(STACK_0)
          ? check_chmod_mode_to_list(I_to_uint32(check_uint32(popSTACK())))
          : uint32_to_I(check_chmod_mode_of_list(popSTACK())));
}

#if defined(HAVE_UMASK)
DEFUN(POSIX::UMASK, cmask)
{ /* lisp interface to umask(2)
     http://www.opengroup.org/onlinepubs/009695399/functions/umask.html */
  mode_t cmask = check_chmod_mode_of_list(popSTACK());
  begin_system_call();
  cmask = umask(cmask);
  end_system_call();
  VALUES1(fixnum(cmask));
}
#endif  /* umask */

#if defined(HAVE_MKNOD) || defined(HAVE_MKFIFO) || defined(HAVE_MKDIR) || defined(HAVE_CREAT)
#if defined(HAVE_CREAT) && !defined(HAVE_MKNOD)
static int creat1 (const char *path, mode_t mode)
{ /* creat() and close() immediately  */
  int fd = creat(path,mode);
  if (fd == -1) return -1;
  return close(fd);
}
#endif
#if defined(WIN32_NATIVE)
static int mkdir1 (const char *path, mode_t mode)
{ (void)mode; return mkdir(path); }
#else
# define mkdir1 mkdir
#endif
DEFCHECKER(mknod_type_check,prefix=S_I,delim=,default=, \
           FIFO FSOCK FCHR FDIR FBLK FREG)
DEFUN(POSIX::MKNOD, path type mode)
{ /* lisp interface to mknod(2)
     http://www.opengroup.org/onlinepubs/009695399/functions/mknod.html */
  mode_t mode = check_chmod_mode_of_list(popSTACK());
#if defined(HAVE_MKNOD)
  mode |= mknod_type_check(popSTACK());
#else
  /* emulate mknod using mkfifo(), mkdir() and creat() */
#define mknod(p,m,d) mknod1(p,m)
  int (*mknod1)(const char *path, mode_t mode);
 mknod_restart:
# if defined(HAVE_MKFIFO)
  if (eq(`:FIFO`,STACK_0)) {
    mknod1 = mkfifo; skipSTACK(1);
    goto mknod_do_it;
  }
# endif  /* mkfifo */
# if defined(HAVE_MKDIR)
  if (eq(`:FDIR`,STACK_0)) {
    mknod1 = mkdir1; skipSTACK(1);
    goto mknod_do_it;
  }
# endif  /* mkfifo */
# if defined(HAVE_CREAT)
  if (eq(`:FDIR`,STACK_0)) {
    mknod1 = creat1; skipSTACK(1);
    goto mknod_do_it;
  }
# endif  /* mkfifo */
  /* invalid type */
  pushSTACK(NIL);               /* no PLACE */
  pushSTACK(STACK_1);           /* TYPE-ERROR slot DATUM */
  { int count = 1;
    pushSTACK(S(member));
#  if defined(HAVE_MKFIFO)
    pushSTACK(`:FIFO`); count++;
#  endif
#  if defined(HAVE_MKDIR)
    pushSTACK(`:FDIR`); count++;
#  endif
#  if defined(HAVE_CREAT)
    pushSTACK(`:FREG`); count++;
#  endif
    value1 = listof(count);
  } pushSTACK(value1);          /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(STACK_0); pushSTACK(STACK_2);
  pushSTACK(TheSubr(subr_self)->name);
  check_value(type_error,GETTEXT("~S: ~S is not of type ~S"));
  STACK_0 = value1;
  goto mknod_restart;
 mknod_do_it:
#endif                          /* no mknod() */
  funcall(L(namestring),1);     /* drop path from STACK */
  with_string_0(value1,GLO(pathname_encoding),path, {
      int ret;
      begin_blocking_system_call();
      ret = mknod(path,mode,0);
      end_blocking_system_call();
      if (ret) OS_file_error(value1);
    });
  VALUES0;
}
#endif  /* mknod | mkfifo | mkdir | creat */

#if defined(HAVE_MKDTEMP) || defined(WIN32_NATIVE) || (defined(HAVE_MKDIR) && defined(HAVE_TEMPNAM))
DEFUN(POSIX:MKDTEMP, template) {
#if defined(HAVE_MKDTEMP)
  object fname = physical_namestring(popSTACK());
  with_string_0(fname,GLO(pathname_encoding),namez,{
      char *c_template;
      if (namez[namez_bytelen-1] == '/') /* mkdtemp(".../") --> ENOENT */
        namez[--namez_bytelen] = 0;
      begin_blocking_system_call();
      if (namez_bytelen > 6
          && namez[namez_bytelen-1]=='X'
          && namez[namez_bytelen-2]=='X'
          && namez[namez_bytelen-3]=='X'
          && namez[namez_bytelen-4]=='X'
          && namez[namez_bytelen-5]=='X'
          && namez[namez_bytelen-6]=='X') {
        c_template = namez;
      } else {
        c_template = (char*)alloca(namez_bytelen+6);
        strcpy(c_template,namez);
        strcat(c_template,"XXXXXX");
      }
      c_template = mkdtemp(c_template);
      end_blocking_system_call();
      if (NULL == c_template) OS_error();
      fname = asciz_to_string(c_template,GLO(pathname_encoding));
    });
  pushSTACK(fname);
#else  /* WIN32_NATIVE || (MKDIR && TEMPNAM) */
  /* http://www.opengroup.org/onlinepubs/009695399/functions/tempnam.html */
  pushSTACK(STACK_0); funcall(L(pathname),1); pushSTACK(value1);
  pushSTACK(value1); funcall(L(directory_namestring),1); pushSTACK(value1);
  pushSTACK(STACK_1); funcall(L(file_namestring),1); pushSTACK(value1);
  /* stack layout: template arg, template pathname, dir, file */
  with_string_0(STACK_0,GLO(pathname_encoding),prefix, {
      with_string_0(STACK_1,GLO(pathname_encoding),dir, {
          /* if no directory ==> use current "." */
          STACK_3 = temp_name(dir[0] ? dir : (char*)".",prefix);
          with_string_0(STACK_3,GLO(pathname_encoding),newdir, {
              begin_blocking_system_call();
              if (mkdir1(newdir,0700)) OS_file_error(STACK_2);
              end_blocking_system_call();
            });
        });
    });
  skipSTACK(3);
#endif
  /* stack layout: the name of the new directory - without the trailing slash */
#if defined(WIN32_NATIVE)
  pushSTACK(GLO(backslash_string));
#else
  pushSTACK(GLO(slash_string));
#endif
  VALUES1(string_concat(2));
}
#endif

#if defined(WIN32_NATIVE) || (defined(HAVE_STATVFS) && defined(HAVE_SYS_STATVFS_H))
#if defined(WIN32_NATIVE)
/* winsup/src/winsup/cygwin/syscalls.cc */
typedef unsigned long fsblkcnt_t;
typedef unsigned long fsfilcnt_t;
struct statvfs {
  unsigned long f_bsize;        /* file system block size */
  unsigned long f_frsize;       /* fragment size */
  fsblkcnt_t f_blocks;          /* size of fs in f_frsize units */
  fsblkcnt_t f_bfree;           /* free blocks in fs */
  fsblkcnt_t f_bavail;          /* free blocks avail to non-superuser */
  fsfilcnt_t f_files;           /* total file nodes in file system */
  fsfilcnt_t f_ffree;           /* free file nodes in fs */
  fsfilcnt_t f_favail;          /* avail file nodes in fs */
  unsigned long f_fsid;         /* file system id */
  unsigned long f_flag;         /* mount flags */
  unsigned long f_namemax;      /* maximum length of filenames */
  char f_volname[MAX_PATH];     /* volume name */
  char f_fstype[MAX_PATH];      /* file system type */
};
#define HAVE_STATVFS_F_VOLNAME
#define HAVE_STATVFS_F_FSTYPE
static int statvfs (const char *fname, struct statvfs *sfs) {
  /* GetDiskFreeSpaceEx must be called before GetDiskFreeSpace on
     WinME, to avoid the MS KB 314417 bug */
  ULARGE_INTEGER availb, freeb, totalb;
  DWORD spc, bps, availc, freec, totalc, vsn, maxlen, flags, bpc;
  char root[MAX_PATH], *rootp = root;
  if (fname[1] == ':') {        /* c:\ */
    *rootp++ = *fname++;
    *rootp++ = *fname++;
  } else if (fname[0] == '\\' && fname[1] == '\\') { /* \\host\dir\ */
    const char *cp = strchr(fname + 2,'\\');
    unsigned int len;
    if (cp) cp = strchr(cp+1,'\\'); /* just host, no dir => error later */
    memcpy(root,fname,(len = cp - fname));
    rootp = root + len;
  } else {
    SetLastError(ERROR_DIRECTORY);
    return -1;
  }
  *rootp++ = '\\';
  *rootp = 0;

  if (!GetDiskFreeSpace(root,&spc,&bps,&freec,&totalc))
    return -1;               /* bytes per sector, sectors per cluster */
  bpc = spc*bps;             /* bytes per cluster */
  if (GetDiskFreeSpaceEx(root,&availb,&totalb,&freeb)) {
    availc = availb.QuadPart / bpc;
    totalc = totalb.QuadPart / bpc;
    freec = freeb.QuadPart / bpc;
  } else
    availc = freec;
  if (!GetVolumeInformation(root,sfs->f_volname,MAX_PATH,&vsn,&maxlen,&flags,
                            sfs->f_fstype,MAX_PATH))
    return -1;
  sfs->f_bsize = bpc;
  sfs->f_frsize = bpc;
  sfs->f_blocks = totalc;
  sfs->f_bfree = freec;
  sfs->f_bavail = availc;
  sfs->f_files = (fsfilcnt_t)-1;
  sfs->f_ffree = (fsfilcnt_t)-1;
  sfs->f_favail = (fsfilcnt_t)-1;
  sfs->f_fsid = vsn;
  sfs->f_flag = flags;
  sfs->f_namemax = maxlen;
  return 0;
}
#endif
DEFCHECKER(vfs_flags,default=,bitmasks=both, ST_RDONLY ST_NOSUID ST_NOTRUNC \
           ST_NODEV ST_NOEXEC ST_SYNCHRONOUS ST_MANDLOCK ST_WRITE ST_APPEND \
           ST_IMMUTABLE ST_NOATIME ST_NODIRATIME                        \
           FILE_NAMED_STREAMS FILE_READ_ONLY_VOLUME FILE_SUPPORTS_OBJECT_IDS \
           FILE_SUPPORTS_REPARSE_POINTS FILE_SUPPORTS_SPARSE_FILES      \
           FILE_VOLUME_QUOTAS FILE_SUPPORTS_ENCRYPTION                  \
           FS_CASE_IS_PRESERVED FS_CASE_SENSITIVE                       \
           FS_FILE_COMPRESSION FS_FILE_ENCRYPTION FS_PERSISTENT_ACLS    \
           FS_UNICODE_STORED_ON_DISK FS_VOL_IS_COMPRESSED)
/* there is also a legacy interface (f)statfs()
   which is not POSIX and is not supported */
DEFUN(POSIX::STAT-VFS, file)
{ /* Lisp interface to statvfs(2), fstatvfs(2)
 the first arg can be a pathname designator or a file descriptor designator
 the return value is the STAT-VFS structure */
  object file = STACK_0;
  struct statvfs buf;
  bool error_p;

#if defined(HAVE_FSTATVFS)
  if (integerp(file)) {
    begin_blocking_system_call();
    error_p = (fstatvfs(I_to_L(file),&buf) < 0);
    end_blocking_system_call();
    if (error_p) OS_error();
  } else {
    Handle fd;
    file = open_file_stream_handle(file,&fd,true);
    if (!eq(nullobj,file)) { /* an open stream */
      pushSTACK(file);
      begin_blocking_system_call();
      error_p = (fstatvfs(fd,&buf) < 0);
      end_blocking_system_call();
      file = popSTACK();
      if (error_p) error_OS_stream(STACK_0);
      STACK_0 = file;
    } else
#endif
      if (ON_PNAMESTRING(STACK_0,statvfs,&buf))
        OS_file_error(value1);
#if defined(HAVE_FSTATVFS)
  }
#endif

  /* STACK_0 is already the object statvfs'ed */
#define pushSLOT(s) pushSTACK(s==(unsigned long)-1 ? NIL : ulong_to_I(s))
  pushSLOT(buf.f_bsize);  /* file system block size */
  pushSLOT(buf.f_frsize); /* fundamental file system block size */
#if defined(SIZEOF_FSBLKCNT_T) && SIZEOF_FSBLKCNT_T == 8
# define pushBSLOT(s) pushSTACK(s==(fsblkcnt_t)-1 ? NIL : uint64_to_I(s))
#else
# define pushBSLOT(s) pushSTACK(s==(fsblkcnt_t)-1 ? NIL : uint32_to_I(s))
#endif
  pushBSLOT(buf.f_blocks); /* total # of blocks on file system */
  pushBSLOT(buf.f_bfree);  /* total number of free blocks */
  pushBSLOT(buf.f_bavail); /* # of free blocks available to
                              non-privileged processes */
#undef pushBSLOT
#if defined(SIZEOF_FSFILCNT_T) && SIZEOF_FSFILCNT_T == 8
# define pushFSLOT(s) pushSTACK(s==(fsfilcnt_t)-1 ? NIL : uint64_to_I(s))
#else
# define pushFSLOT(s) pushSTACK(s==(fsfilcnt_t)-1 ? NIL : uint32_to_I(s))
#endif
  pushFSLOT(buf.f_files);  /* total # of file serial numbers */
  pushFSLOT(buf.f_ffree);  /* total # of free file serial numbers */
  pushFSLOT(buf.f_favail); /* # of file serial numbers available to
                              non-privileged processes */
#undef pushFSLOT
#if HAVE_SCALAR_FSID
  pushSLOT(buf.f_fsid);   /* file system ID */
#else
  /* On Linux, f_fsid of 'struct statfs' is a struct consisting of two ints.
     With glibc <= 2.1, f_fsid of 'struct statvfs' is the same. We are
     prepared to return one number only, so we just return the first int.
     This matches the behaviour of glibc >= 2.2 on 32-bit platforms. */
  pushSLOT((*(uintL*)&buf.f_fsid));   /* file system ID */
#endif
  pushSTACK(vfs_flags_to_list(buf.f_flag)); /* Bit mask of f_flag values. */
  pushSLOT(buf.f_namemax);      /* maximum filename length */
#if defined(HAVE_STATVFS_F_VOLNAME)
  pushSTACK(asciz_to_string(buf.f_volname,GLO(pathname_encoding)));
#else
  pushSTACK(NIL);
#endif
#if defined(HAVE_STATVFS_F_FSTYPE)
  pushSTACK(asciz_to_string(buf.f_fstype,GLO(pathname_encoding)));
#else
  pushSTACK(NIL);
#endif
  funcall(`POSIX::MAKE-STAT-VFS`,14);
#undef pushSLOT
}

#endif  /* fstatvfs statvfs */


#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)

/* Dynamically load some functions missing in Windows95/98/ME
   to work with Security IDentifiers (SIDs). */

#include <aclapi.h>

/* Added in Windows NT 4.0 */
typedef DWORD (WINAPI * GetSecurityInfoFunc_t)
  (HANDLE handle, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo,
   PSID* ppsidOwner, PSID* ppsidGroup, PACL* ppDacl, PACL* ppSacl,
   PSECURITY_DESCRIPTOR* ppSecurityDescriptor);
static GetSecurityInfoFunc_t GetSecurityInfoFunc;
#undef GetSecurityInfo
#define GetSecurityInfo (*GetSecurityInfoFunc)

/* Added in Windows NT Workstation */
typedef BOOL (WINAPI * LookupAccountSidFunc_t)
  (LPCTSTR lpSystemName, PSID lpSid, LPTSTR lpName, LPDWORD cchName,
   LPTSTR lpReferencedDomainName, LPDWORD cchReferencedDomainName,
   PSID_NAME_USE peUse);
static LookupAccountSidFunc_t LookupAccountSidFunc;
#undef LookupAccountSid
#define LookupAccountSid (*LookupAccountSidFunc)

/* Added in Windows NT Workstation */
typedef DWORD (WINAPI * GetLengthSidFunc_t) (PSID pSid);
static GetLengthSidFunc_t GetLengthSidFunc;
#undef GetLengthSid
#define GetLengthSid (*GetLengthSidFunc)

/* Added in Windows NT Workstation */
typedef BOOL (WINAPI * CopySidFunc_t)
  (DWORD nDestinationSidLength, PSID pDestinationSid, PSID pSourceSid);
static CopySidFunc_t CopySidFunc;
#undef CopySid
#define CopySid (*CopySidFunc)

/* Added in Windows NT Workstation */
typedef BOOL (WINAPI * EqualSidFunc_t) (PSID pSid1, PSID pSid2);
static EqualSidFunc_t EqualSidFunc;
#undef EqualSid
#define EqualSid (*EqualSidFunc)

/* Added in Windows 2000 Professional */
typedef BOOL (WINAPI * ConvertSidToStringSidFunc_t)
  (IN PSID Sid, OUT LPTSTR *StringSid);
static ConvertSidToStringSidFunc_t ConvertSidToStringSidFunc;
#undef ConvertSidToStringSid
#define ConvertSidToStringSid (*ConvertSidToStringSidFunc)

static BOOL initialized_sid_apis = FALSE;

static void initialize_sid_apis () {
  HMODULE advapi32 = LoadLibrary("advapi32.dll");
  if (advapi32 != NULL) {
    GetSecurityInfoFunc = (GetSecurityInfoFunc_t)
      GetProcAddress(advapi32, "GetSecurityInfo");
    LookupAccountSidFunc = (LookupAccountSidFunc_t)
      GetProcAddress(advapi32, "LookupAccountSidA");
    GetLengthSidFunc = (GetLengthSidFunc_t)
      GetProcAddress(advapi32, "GetLengthSid");
    CopySidFunc = (CopySidFunc_t) GetProcAddress(advapi32, "CopySid");
    EqualSidFunc = (EqualSidFunc_t) GetProcAddress(advapi32, "EqualSid");
    ConvertSidToStringSidFunc = (ConvertSidToStringSidFunc_t)
      GetProcAddress(advapi32, "ConvertSidToStringSidA");
  }
  initialized_sid_apis = TRUE;
}

#endif /* (WIN32_NATIVE || UNIX_CYGWIN32) */

/* FILE-OWNER */

#if defined(HAVE_GETPWUID)
static const char * get_owner (const char *filename) {
  struct stat statbuf;
  if (lstat(filename, &statbuf) >= 0) {
    struct passwd *pwd = getpwuid(statbuf.st_uid);
    if (pwd)
      return pwd->pw_name;
  }
  return "";
}
#elif defined(WIN32_NATIVE)

/* A cache mapping SID -> owner. */
struct sid_cache_entry {
  PSID psid;
  char *name;
};
static struct sid_cache_entry *sid_cache = NULL;
static size_t sid_cache_count = 0;
static size_t sid_cache_allocated = 0;

static const char * sid_cache_get (PSID psid) {
  size_t i;
  for (i = 0; i < sid_cache_count; i++)
    if (EqualSid(psid, sid_cache[i].psid))
      return sid_cache[i].name;
  return NULL;
}

static void sid_cache_put (PSID psid, const char *name) {
  if (sid_cache_count == sid_cache_allocated) {
    size_t new_allocated = 2 * sid_cache_allocated + 5;
    sid_cache = (struct sid_cache_entry*)
      (sid_cache != NULL
       ? realloc(sid_cache, new_allocated * sizeof(struct sid_cache_entry))
       : malloc(new_allocated * sizeof(struct sid_cache_entry)));
    sid_cache_allocated = (sid_cache == NULL)?0:new_allocated;
  }
  if (sid_cache != NULL) {
    DWORD psid_len = GetLengthSid(psid);
    size_t name_len = strlen(name) + 1;
    char *memory = (char *)malloc(psid_len+name_len);
    if (memory == NULL)
      return;
    if (!CopySid(psid_len, memory, psid)) return;
    memcpy(memory+psid_len, name, name_len);
    sid_cache[sid_cache_count].psid = memory;
    sid_cache[sid_cache_count].name = memory + psid_len;
    sid_cache_count++;
  }
}

static const char * get_owner (const char *filename) {
  char *owner;

  if (!initialized_sid_apis)
    initialize_sid_apis();
  owner = "";
  if (GetSecurityInfoFunc != NULL
      && LookupAccountSidFunc != NULL
      && GetLengthSidFunc != NULL
      && CopySidFunc != NULL
      && EqualSidFunc != NULL) {
    /* On Windows, directories don't have an owner. */
    WIN32_FIND_DATA entry;
    HANDLE searchhandle = FindFirstFile(filename, &entry);
    if (searchhandle != INVALID_HANDLE_VALUE) {
      if (!(entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        /* It's a file. */
        HANDLE filehandle =
         CreateFile(filename, GENERIC_READ,
                    FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (filehandle != INVALID_HANDLE_VALUE) {
          /* Get the owner. */
          PSID psid;
          PSECURITY_DESCRIPTOR psd;
          DWORD err =
            GetSecurityInfo(filehandle, SE_FILE_OBJECT,
                            OWNER_SECURITY_INFORMATION,
                            &psid, NULL, NULL, NULL, &psd);
          if (err == 0) {
            owner = sid_cache_get(psid);
            if (owner == NULL) {
              char buf1[256];
              DWORD buf1size = sizeof(buf1);
              char buf2[256];
              DWORD buf2size = sizeof(buf2);
              SID_NAME_USE role;
              if (!LookupAccountSid(NULL, psid, buf1, &buf1size, buf2,
                                    &buf2size, &role)) {
                char *s;
                if (ConvertSidToStringSidFunc != NULL
                    && !ConvertSidToStringSidFunc(psid, &s)) {
                  /* Fallback: Use S-R-I-S-S... notation.  */
                  strncpy(buf1, s, buf1size);
                  buf1[buf1size - 1] = '\0';
                  LocalFree(s);
                  owner = buf1;
                } else (owner = buf1)[0] = '\0';
              } else { /* DOMAIN\Account */
                int len = strlen(buf2);
                buf2[len] = '\\';
                strcpy(buf2+len+1,buf1);
                owner = buf2;
              }
              sid_cache_put(psid, owner);
            }
            LocalFree(psd);
          }
          CloseHandle(filehandle);
        }
      }
      FindClose(searchhandle);
    }
  }
  return owner;
}
#else /* neither HAVE_GETPWUID nor WIN32_NATIVE - should never happen! */
static const char * get_owner (const char *filename) { return ""; }
#endif

DEFUN(OS::FILE-OWNER, file) {
  VALUES1(safe_to_string((char*)ON_PNAMESTRING(popSTACK(),get_owner,NULL)));
}

/* end of FILE-OWNER */

#if defined(WIN32_NATIVE)

/* Pointers to functions unavailable on windows 95, 98, ME */

typedef BOOL (WINAPI * CreateHardLinkFuncType)
  (LPCTSTR lpFileName, LPCTSTR lpExistingFileName,
   LPSECURITY_ATTRIBUTES lpSecurityAttributes);
static CreateHardLinkFuncType CreateHardLinkFunc = NULL;

typedef BOOL (WINAPI * BackupWriteFuncType)
  (HANDLE hFile, LPBYTE lpBuffer, DWORD nNumberOfBytesToWrite,
   LPDWORD lpNumberOfBytesWritten, BOOL bAbort, BOOL bProcessSecurity,
   LPVOID *lpContext);
static BackupWriteFuncType BackupWriteFunc = NULL;

static void init_win32_link (void) {
  HMODULE kernel32 = LoadLibrary ("kernel32.dll");
  if (kernel32 != NULL) {
    CreateHardLinkFunc = (CreateHardLinkFuncType)
      GetProcAddress (kernel32, "CreateHardLinkA");
    BackupWriteFunc = (BackupWriteFuncType)
      GetProcAddress (kernel32, "BackupWrite");
    LockFileExFunc = (LockFileExFuncType)
      GetProcAddress (kernel32, "LockFileEx");
    if (LockFileExFunc == NULL)
      LockFileExFunc = (LockFileExFuncType) &my_LockFileEx;
    UnlockFileExFunc = (UnlockFileExFuncType)
      GetProcAddress (kernel32, "UnlockFileEx");
    if (UnlockFileExFunc == NULL)
      UnlockFileExFunc = (UnlockFileExFuncType) &my_UnlockFileEx;
  }
}
#endif

#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)
typedef HRESULT (WINAPI * StgOpenStorageExFuncType) (const WCHAR* pwcsName,
            DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, void * reserved1,
            void * reserved2, REFIID riid, void ** ppObjectOpen);
static StgOpenStorageExFuncType StgOpenStorageExFunc = NULL;

static void init_win32_cygwin_open_storage (void) {
  HMODULE ole32 = LoadLibrary ("ole32.dll");
  if (ole32 != NULL)
    StgOpenStorageExFunc = (StgOpenStorageExFuncType)
      GetProcAddress (ole32, "StgOpenStorageEx");
}
#endif

/* COPY-FILE related functions. */

#if defined(WIN32_NATIVE)
/* Checks if it's safe to call OldHardLink */
static BOOL OldHardLinkGuard () {
  OSVERSIONINFO vi;
  if (BackupWriteFunc == NULL) return FALSE;
  vi.dwOSVersionInfoSize = sizeof(vi);
  if (!GetVersionEx(&vi)) return FALSE;
  return vi.dwPlatformId == VER_PLATFORM_WIN32_NT;
}

/* From knowledge base article Q234727
   This approach works on NT >= 3.51. */
static BOOL OldHardLink( LPCTSTR source, LPCTSTR dest ) {

   WCHAR  wsource[ MAX_PATH + 1 ];
   WCHAR  wdest[ MAX_PATH + 1 ];
   WCHAR  wdestfull[ MAX_PATH + 1 ];
   LPWSTR wdestfullfile;

   HANDLE hFileSource;

   WIN32_STREAM_ID StreamId;
   DWORD dwBytesWritten;
   LPVOID lpContext;
   DWORD cbPathLen;
   DWORD StreamHeaderSize;

   BOOL bSuccess;

   /* convert from ANSI to UNICODE */
   if (MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS /*error on invalid chars*/,
     dest, -1/*null terminated*/, wdest, MAX_PATH + 1) == 0) return FALSE;

   /* open existing file that we link to */
   hFileSource = CreateFile(source, FILE_WRITE_ATTRIBUTES,
     FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
     NULL, /* sa */ OPEN_EXISTING, 0, NULL );

   if (hFileSource == INVALID_HANDLE_VALUE) return FALSE;

   /* validate and sanitize supplied link path and use the result
      the full path MUST be Unicode for BackupWrite */
   cbPathLen = GetFullPathNameW( wdest , MAX_PATH, wdestfull, &wdestfullfile);

   if (cbPathLen == 0) return FALSE;

   cbPathLen = (cbPathLen + 1) * sizeof(WCHAR); // adjust for byte count

   /* prepare and write the WIN32_STREAM_ID out */
   lpContext = NULL;

   StreamId.dwStreamId = BACKUP_LINK;
   StreamId.dwStreamAttributes = 0;
   StreamId.dwStreamNameSize = 0;
   StreamId.Size.HighPart = 0;
   StreamId.Size.LowPart = cbPathLen;

   /* compute length of variable size WIN32_STREAM_ID */
   StreamHeaderSize = (LPBYTE)&StreamId.cStreamName - (LPBYTE)&StreamId
                      + StreamId.dwStreamNameSize ;

   bSuccess = BackupWriteFunc(hFileSource,
                         (LPBYTE)&StreamId,  /* buffer to write */
                         StreamHeaderSize,   /* number of bytes to write */
                         &dwBytesWritten,
                         FALSE,              /* don't abort yet */
                         FALSE,              /* don't process security */
                         &lpContext);
   bSuccess &= BackupWriteFunc(hFileSource,(LPBYTE)wdestfull, cbPathLen,
        &dwBytesWritten, FALSE, FALSE, &lpContext);
   /* free context */
   bSuccess &= BackupWriteFunc(hFileSource,NULL,0,&dwBytesWritten,TRUE, FALSE,
        &lpContext);
   CloseHandle( hFileSource );
   return bSuccess;
}

static inline int MkHardLink (char* old_pathstring, char* new_pathstring) {
  if (CreateHardLinkFunc != NULL)
    return CreateHardLinkFunc(new_pathstring,old_pathstring,NULL);
  if (OldHardLinkGuard())
    return OldHardLink(old_pathstring,new_pathstring);
  SetLastError(ERROR_INVALID_FUNCTION); /* or what ? */
  return 0;
}
#endif

/* Hard/Soft Link a file
 > old_pathstring: old file name, ASCIZ-String
 > new_pathstring: new file name, ASCIZ-String
 > STACK_3: old pathname
 > STACK_1: new pathname */
#if defined(WIN32_NATIVE)
# define HAVE_LINK
#elif !defined(LINK_FOLLOWS_SYMLINKS) && defined(HAVE_REALPATH)
static inline int my_link (const char* source, const char* destination) {
# ifndef MAXPATHLEN             /* see unix.d */
#  define MAXPATHLEN  4096      /* see <sys/param.h> */
# endif
  char path_buffer[MAXPATHLEN];
  if (NULL == realpath(source,path_buffer)) OS_file_error(STACK_3);
  return link(path_buffer,destination);
}
#else
# define my_link link
#endif
#if defined(HAVE_LINK)
static bool hardlink_file (char* old_pathstring, char* new_pathstring,
                           bool error_p) {
  gcv_object_t *failed = NULL;
  begin_blocking_system_call();
# if defined(WIN32_NATIVE)
  if (MkHardLink(old_pathstring,new_pathstring) == FALSE)
    failed = (GetLastError() == ERROR_FILE_NOT_FOUND ? &STACK_3 : &STACK_1);
# else
  if (my_link(old_pathstring,new_pathstring) < 0)
    failed = (errno==ENOENT ? &STACK_3 : &STACK_1);
# endif
  end_blocking_system_call();
  if (failed && error_p) OS_file_error(*failed);
  return failed != NULL;
}
#endif
#if defined(HAVE_SYMLINK)
static inline void symlink_file (char* old_pathstring, char* new_pathstring) {
  gcv_object_t *failed = NULL;
  begin_blocking_system_call();
  if (symlink(old_pathstring,new_pathstring) < 0) /* symlink file */
    failed = (errno==ENOENT ? &STACK_3 : &STACK_1);
  end_blocking_system_call();
  if (failed) OS_file_error(*failed);
}
#endif

/* Copy attributes from stream STACK_1 to stream STACK_0 and close them
   can trigger GC */
static void copy_attributes_and_close () {
  Handle source_fd = stream_lend_handle(&STACK_1,true,NULL);
  Handle dest_fd = stream_lend_handle(&STACK_0,false,NULL);
  struct stat source_sb;
  struct stat dest_sb;

# if defined(HAVE_FSTAT) && !defined(WIN32_NATIVE)
  begin_blocking_system_call();
  if (fstat(source_fd, &source_sb) == -1) {
    end_blocking_system_call();
    pushSTACK(file_stream_truename(STACK_1));
    goto close_and_err;
  }
  if (fstat(dest_fd, &dest_sb) == -1) {
    end_blocking_system_call();
    pushSTACK(file_stream_truename(STACK_0));
    goto close_and_err;
  }
  end_blocking_system_call();
# elif defined(HAVE_STAT)
  if (ON_PNAMESTRING(STACK_1,stat,&source_sb)) {
    pushSTACK(file_stream_truename(STACK_1));
    goto close_and_err;
  }
  if (ON_PNAMESTRING(STACK_0,stat,&dest_sb) == (void*)-1) {
    pushSTACK(file_stream_truename(STACK_0));
    goto close_and_err;
  }
# else
  goto close_success;
# endif

# if defined(WIN32_NATIVE) /*** file mode ***/
  { BOOL ret;
    BY_HANDLE_FILE_INFORMATION fi;
    begin_blocking_system_call();
    ret = GetFileInformationByHandle(source_fd,&fi);
    end_blocking_system_call();
    if (!ret) {
      pushSTACK(file_stream_truename(STACK_1));
      goto close_and_err;
    }
    if (!ON_PNAMESTRING(STACK_0,SetFileAttributes,fi.dwFileAttributes)) {
      pushSTACK(file_stream_truename(STACK_0));
      goto close_and_err;
    }
  }
# elif defined(HAVE_FCHMOD)
  begin_blocking_system_call();
  if (((source_sb.st_mode & 0777) != (dest_sb.st_mode & 0777))
      && (fchmod(dest_fd, source_sb.st_mode & 0777) == -1)) {
    end_blocking_system_call();
    pushSTACK(file_stream_truename(STACK_0));
    goto close_and_err;
  }
  end_blocking_system_call();
# elif defined(HAVE_CHMOD)
  if ((source_sb.st_mode & 0777) != (dest_sb.st_mode & 0777)
      && ON_PNAMESTRING(STACK_0,chmod,source_sb.st_mode & 0777)) {
    pushSTACK(file_stream_truename(STACK_0));
    goto close_and_err;
  }
# endif

# if defined(HAVE_FCHOWN) /*** owner/group ***/
  begin_blocking_system_call();
  if (fchown(dest_fd, source_sb.st_uid, source_sb.st_gid) == -1) {
    end_blocking_system_call();
    pushSTACK(file_stream_truename(STACK_0));
    goto close_and_err;
  }
  end_blocking_system_call();
# elif defined(HAVE_CHOWN)
  { int ret;
    with_string_0(physical_namestring(STACK_0),GLO(pathname_encoding),destz,{
        begin_blocking_system_call();
        ret = chown(destz, source_sb.st_uid, source_sb.st_gid);
        end_blocking_system_call();
      });
    if (ret == -1) {
      pushSTACK(file_stream_truename(STACK_0));
      goto close_and_err;
    }
  }
# endif

# if defined(HAVE_UTIME)
  /* we must close the streams now - before utime() -
     because close() modifies write and access times */
  builtin_stream_close(&STACK_0,0);
  builtin_stream_close(&STACK_1,0);
  { /*** access/mod times ***/
    struct utimbuf utb;
    /* first element of the array is access time, second is mod time. set
       both tv_usec to zero since the file system can't gurantee that
       kind of precision anyway. */
    utb.actime  = source_sb.st_atime;
    utb.modtime = source_sb.st_mtime;
    if (ON_PNAMESTRING(STACK_0,utime,&utb)) {
      pushSTACK(file_stream_truename(STACK_0));
      goto close_and_err;
    }
  }
  return;
# endif
 close_success:
  builtin_stream_close(&STACK_0,0);
  builtin_stream_close(&STACK_1,0);
  return;
 close_and_err:
  builtin_stream_close(&STACK_1,0);
  builtin_stream_close(&STACK_2,0);
  OS_file_error(STACK_0);
}

/* on success, push (source dest byte-count) on retval (an address in STACK)
 can trigger GC */
static void copy_file_low (object source, object dest,
                           bool preserve_p, if_exists_t if_exists,
                           if_does_not_exist_t if_not_exists,
                           gcv_object_t* retval) {
/* (let ((buffer (make-array buffer-size :element-type 'unsigned-byte)))
    (with-open-file (source-stream source :direction :input
                                   :element-type 'unsigned-byte)
     (with-open-file (dest-stream dest :direction (if append-p :append :output)
                                  :element-type 'unsigned-byte)
       (loop for bytes-read = (read-byte-sequence buffer source-stream)
             until (= 0 bytes-read)
             do (write-byte-sequence buffer dest-stream :end bytes-read)))))
*/
  uintL total_count = 0; /* return value: total byte count */
  /* create the two streams */
  pushSTACK(dest);
  /* input: */
  pushSTACK(source);            /* filename */
  pushSTACK(S(Kdirection)); pushSTACK(S(Kinput));
  pushSTACK(S(Kelement_type)); pushSTACK(S(unsigned_byte));
  pushSTACK(S(Kif_does_not_exist));
  pushSTACK(if_does_not_exist_symbol(if_not_exists));
  funcall(L(open),7); source = value1;
  if (nullp(source)) {
    skipSTACK(1); /* drop dest */
    return;
  }
  pushSTACK(STACK_0); STACK_1 = source;
  /* stack layout: 1: source stream; 0: dest path */
  /* output: */
  pushSTACK(S(Kdirection)); pushSTACK(S(Koutput));
  pushSTACK(S(Kelement_type)); pushSTACK(S(unsigned_byte));
  pushSTACK(S(Kif_exists)); pushSTACK(if_exists_symbol(if_exists));
  funcall(L(open),7); dest = value1;
  if (nullp(dest)) {
    builtin_stream_close(&STACK_0,0);
    skipSTACK(1); /* drop source */
    return;
  }
  pushSTACK(dest);
  /* stack layout: 0=output stream; 1=input stream */
  { /* make the bit buffer and copy data */
    uintL bytes_read;
    char buffer[strm_buffered_bufflen];
    /* stack layout: 0 - dest-stream; 1 - source-stream */
    Handle fd_in = stream_lend_handle(&STACK_1,true,NULL);
    Handle fd_ou = stream_lend_handle(&STACK_0,false,NULL);
    while ((bytes_read = fd_read(fd_in,buffer,strm_buffered_bufflen,
                                 persev_full))) {
      total_count += bytes_read;
      fd_write(fd_ou,buffer,bytes_read,persev_full);
    }
  }
  if (!preserve_p) {
    builtin_stream_close(&STACK_0,0);
    builtin_stream_close(&STACK_1,0);
  } else
    copy_attributes_and_close();
  /* clean up the stack */
  pushSTACK(allocate_cons());
  Cdr(STACK_0) = *retval;
  *retval = STACK_0;
  STACK_2 = file_stream_truename(STACK_2); /* source */
  STACK_1 = file_stream_truename(STACK_1); /* dest */
  STACK_0 = UL_to_I(total_count);
  Car(*retval) = listof(3);
}

DEFCHECKER(check_copy_method,enum=copy_method_t,default=COPY_METHOD_COPY,\
           prefix=COPY_METHOD, :COPY SYMLINK HARDLINK HARDLINK-OR-COPY :RENAME)
/* copy just one file: source --> dest (both STRINGs, NIL or PATHNAME)
   can trigger GC */
static void copy_one_file (object source, object src_path,
                           object dest, object dest_path,
                           copy_method_t method, bool preserve_p,
                           if_exists_t if_exists,
                           if_does_not_exist_t if_not_exists,
                           gcv_object_t* retval) {
  pushSTACK(source); pushSTACK(src_path);
  pushSTACK(dest); pushSTACK(dest_path);
  XOUT(source,"copy_one_file");
  XOUT(src_path,"copy_one_file");
  XOUT(dest,"copy_one_file");
  XOUT(dest_path,"copy_one_file");
  /* merge source into dest: "cp foo bar/" --> "cp foo bar/foo" */
  pushSTACK(STACK_2); /* src_path */
  funcall(L(merge_pathnames),2); pushSTACK(value1); /* dest_path */

  if (method == COPY_METHOD_COPY) {
    copy_file_low(STACK_2,STACK_0,preserve_p,if_exists,if_not_exists,retval);
    skipSTACK(4);
    return;
  }

  pushSTACK(STACK_0); funcall(L(probe_file),1);
  if (!nullp(value1)) { /* destination exists; value1 == truename */
    pushSTACK(value1); STACK_2 = dest = value1;
    /* STACK: 0=dest_true; 1=dest_path; 2=dest; 3=src_path; 4=src */
    switch (if_exists) {
      case IF_EXISTS_NIL: skipSTACK(5); return;
      case IF_EXISTS_APPEND:
        /* we know that method != COPY_METHOD_COPY - handled above! */
        pushSTACK(S(Kappend));
        pushSTACK(check_copy_method_reverse(method));
        pushSTACK(`POSIX::COPY-FILE`);
        error(error_condition,GETTEXT("~S: ~S forbids ~S"));
      case IF_EXISTS_OVERWRITE:
      case IF_EXISTS_SUPERSEDE:
      case IF_EXISTS_RENAME_AND_DELETE:
        /* these are the same since (sym)link/rename are atomic */
        break;
      case IF_EXISTS_UNBOUND: case IF_EXISTS_ERROR:
      case IF_EXISTS_RENAME:    /* delegate to OPEN */
        pushSTACK(value1);      /* destination */
        pushSTACK(S(Kif_exists)); pushSTACK(if_exists_symbol(if_exists));
        pushSTACK(S(Kdirection)); pushSTACK(S(Koutput));
        funcall(L(open),5);
        pushSTACK(value1); builtin_stream_close(&STACK_0,0);
        funcall(L(delete_file),1);
        break;
      default: NOTREACHED;
    }
  } else pushSTACK(STACK_0); /* destination does not exist, use dest_path */

  pushSTACK(STACK_3); funcall(L(probe_file),1);
  if (nullp(value1)) { /* source does not exist */
    if (method == COPY_METHOD_RENAME || method == COPY_METHOD_HARDLINK
        || method == COPY_METHOD_HARDLINK_OR_COPY) {
      if (if_not_exists == IF_DOES_NOT_EXIST_NIL) {
        skipSTACK(6); return;
      } else { /* delegate error to OPEN */
        pushSTACK(STACK_3);     /* source */
        pushSTACK(S(Kif_does_not_exist));
        pushSTACK(if_does_not_exist_symbol(if_not_exists));
        pushSTACK(S(Kdirection)); pushSTACK(S(Kinput));
        funcall(L(open),5);
        NOTREACHED;
      }
    }
  } else {
    pushSTACK(value1); funcall(L(truename),1); pushSTACK(value1);
  }

  /* stack layout: 0=src_true; 1=dest_true ... */
  switch (method) {
    case COPY_METHOD_RENAME:
      pushSTACK(STACK_0); pushSTACK(STACK_2);
      pushSTACK(S(Kif_exists)); pushSTACK(if_exists_symbol(if_exists));
      funcall(L(rename_file),4);
      source = STACK_4; dest = STACK_1;
      break;
    case COPY_METHOD_HARDLINK_OR_COPY: {
#    if defined(HAVE_LINK)
      bool status;
      dest = physical_namestring(STACK_1);
      source = physical_namestring(STACK_0);
      with_string_0(source, GLO(pathname_encoding), source_asciz, {
        with_string_0(dest, GLO(pathname_encoding), dest_asciz, {
          status = hardlink_file(source_asciz,dest_asciz,false);
        });
      });
      if (status) goto copy_one_file_copy;
      break;
#    endif
    } /* FALLTHROUGH if no hardlinks */
    case COPY_METHOD_SYMLINK:
#    if defined(HAVE_SYMLINK)
      dest = physical_namestring(STACK_1);
      /* use the original argument, not the truename here,
         so that the user can create relative symlinks */
      source = (stringp(STACK_5) ? (object)STACK_5
                : physical_namestring(STACK_4));
      with_string_0(source, GLO(pathname_encoding), source_asciz, {
        with_string_0(dest, GLO(pathname_encoding), dest_asciz,
                      { symlink_file(source_asciz,dest_asciz); });
      });
      break;
#    endif
      /* FALLTHROUGH if no symlinks */
    case COPY_METHOD_HARDLINK:
#    if defined(HAVE_LINK)
      dest = physical_namestring(STACK_1);
      source = physical_namestring(STACK_0);
      with_string_0(source, GLO(pathname_encoding), source_asciz, {
        with_string_0(dest, GLO(pathname_encoding), dest_asciz,
                      { hardlink_file(source_asciz,dest_asciz,true); });
      });
      break;
#    endif
      /* FALLTHROUGH if no hardlinks */
    default: copy_one_file_copy:
      copy_file_low(STACK_0,STACK_1,preserve_p,if_exists,if_not_exists,retval);
      skipSTACK(6);
      return;
  }
  /* update retval */
  STACK_0 = dest;
  STACK_1 = source;
  STACK_2 = allocate_cons();
  Cdr(STACK_2) = *retval;
  *retval = STACK_2;
  Car(*retval) = listof(2);
  skipSTACK(4);
}

/* (COPY-FILE source target &key method preserve (if-exists :supersede)
              (if-does-not-exist :error))
 source and target are pathname designators (whether or not they
 can be streams is up for debate). if target is missing a name or
 type designator it is taken from source.
 keywords:
 method := :hardlink      ; make a hard link
         | :symlink       ; make a symbolic link
         | :rename        ; move
         | :copy (or nil) ; make a copy
  if the underlying file system does not support a given operation
  a copy is made

 preserve := t ;; preserve as much of source-file's attributes as
               ;; possible
           | nil ;; don't try to preserve source-file's attributes
                 ;; when creating target-file
 for target:
 if-exists := :supersede ;; the existing file is superseded. that is
                         ;; a new file with the same name (and
                         ;; attributes if possible) is created.
            | :error ;; an error of type file-error is signaled.
            | :new-version ;; a new file is created with a larger
                           ;; version number
            | :rename ;; the existing file is renamed to "orig.bak"
            | :append ;; the contents of source-file are appended to
                      ;; the end of target-file
 for source:
 if-does-not-exist := nil ;; do nothing and return nil
                    | :error ;; (default) signal an error
 */
DEFUN(POSIX::COPY-FILE, source target &key METHOD :PRESERVE     \
      :IF-EXISTS :IF-DOES-NOT-EXIST) {
  if_does_not_exist_t if_not_exists = check_if_does_not_exist(STACK_0);
  if_exists_t if_exists = check_if_exists(STACK_1);
  bool preserve_p = (!nullp(STACK_2) && boundp(STACK_2));
  bool wild_source_p, wild_dest_p;
  copy_method_t method = check_copy_method(STACK_3);
  STACK_1 = NIL; /* return value */
  /* stack: 5 - source; 4 - dest */
  pushSTACK(STACK_5); funcall(L(pathname),1); STACK_3 = value1;
  pushSTACK(STACK_3); funcall(L(wild_pathname_p),1);
  wild_source_p = !nullp(value1);
  pushSTACK(STACK_4); funcall(L(pathname),1); STACK_2 = value1;
  pushSTACK(STACK_2); funcall(L(wild_pathname_p),1);
  wild_dest_p = !nullp(value1);
  XOUT(STACK_3,"POSIX::COPY-FILE -- source");
  XOUT(STACK_2,"POSIX::COPY-FILE -- dest");
  if (wild_source_p) {
    pushSTACK(STACK_3);         /* source pathname */
    pushSTACK(S(Kif_does_not_exist)); pushSTACK(S(Kdiscard));
    funcall(L(directory),3);
    STACK_0 = value1;
    XOUT(STACK_0,"POSIX::COPY-FILE: source list");
    if (wild_dest_p) {
      while (!nullp(STACK_0)) {
        pushSTACK(Car(STACK_0)); /* truename */
        pushSTACK(STACK_(3+1)); /* source */
        pushSTACK(STACK_(2+2)); /* dest */
        funcall(L(translate_pathname),3);
        copy_one_file(NIL,Car(STACK_0),NIL,value1,method,
                      preserve_p,if_exists,if_not_exists,&STACK_1);
        STACK_0 = Cdr(STACK_0);
      }
    } else { /* non-wild dest, must be a directory */
      pushSTACK(STACK_2); funcall(L(probe_directory),1);
      if (nullp(value1)) {      /* dest is a non-exitent dir */
        pushSTACK(STACK_2); funcall(L(make_directory),1);
      }
      while (!nullp(STACK_0)) {
        copy_one_file(NIL,Car(STACK_0),STACK_4,STACK_2,method,
                      preserve_p,if_exists,if_not_exists,&STACK_1);
        STACK_0 = Cdr(STACK_0);
      }
    }
  } else /* non-wild source */
    copy_one_file(STACK_5,STACK_3,STACK_4,STACK_2,method,preserve_p,
                  if_exists,if_not_exists,&STACK_1);
  VALUES1(STACK_1);
  skipSTACK(6);
}

DEFUN(POSIX::DUPLICATE-HANDLE, old &optional new)
{ /* Lisp interface to dup(2)/dup2(2). */
  Handle new_handle = (Handle)check_uint_defaulted(popSTACK(),(uintL)-1);
  Handle old_handle = (Handle)I_to_uint(check_uint(popSTACK()));
  begin_blocking_system_call();
  if (new_handle == (Handle)(uintL)-1)
    new_handle = handle_dup(old_handle);
  else
    new_handle = handle_dup2(old_handle,new_handle);
  end_blocking_system_call();
  VALUES1(fixnum(new_handle));
}

#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)
#include <shlobj.h>

/* also exists in w32shell.c
   redefining here for compilation with cygwin
   where no use of COM is made in base set */

static HRESULT BTCoCreateInstance(REFCLSID rclsid,  LPUNKNOWN pUnkOuter,
                                  DWORD dwClsContext, REFIID riid,
                                  LPVOID * ppv )
{
  HRESULT result;
  result = CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
  if (result != CO_E_NOTINITIALIZED
      || CoInitialize(NULL) != S_OK) return result;
  return CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
}

DEFCHECKER(check_file_attributes, type=DWORD, reverse=uint32_to_I,      \
           default=, prefix=FILE_ATTRIBUTE, bitmasks=both,              \
           ARCHIVE COMPRESSED :DEVICE :DIRECTORY ENCRYPTED HIDDEN :NORMAL \
           NOT-CONTENT-INDEXED OFFLINE READONLY REPARSE-POINT SPARSE-FILE \
           SYSTEM TEMPORARY)
DEFUN(POSIX::CONVERT-ATTRIBUTES, attributes)
{ /* convert between symbolic and numeric file attributes */
  if (posfixnump(STACK_0))
    VALUES1(check_file_attributes_to_list
            (I_to_uint32(check_uint32(popSTACK()))));
  else if (listp(STACK_0))
    VALUES1(fixnum(check_file_attributes_of_list(popSTACK())));
  else VALUES1(fixnum(check_file_attributes(popSTACK())));
}
/* convert the 8 members of WIN32_FIND_DATA to the FILE-INFO struct
 can trigger GC */
static Values wfd_to_file_info (WIN32_FIND_DATA *wfd) {
  pushSTACK(check_file_attributes_to_list(wfd->dwFileAttributes));
  pushSTACK(convert_time_to_universal_w32(&(wfd->ftCreationTime)));
  pushSTACK(convert_time_to_universal_w32(&(wfd->ftLastAccessTime)));
  pushSTACK(convert_time_to_universal_w32(&(wfd->ftLastWriteTime)));
  pushSTACK(UL2_to_I(wfd->nFileSizeHigh,wfd->nFileSizeLow));
  pushSTACK(asciz_to_string(wfd->cFileName,GLO(pathname_encoding)));
  pushSTACK(asciz_to_string(wfd->cAlternateFileName,GLO(pathname_encoding)));
  funcall(`POSIX::MAKE-FILE-INFO`,7);
}

DEFUN(POSIX::FILE-INFO, file &optional all) {
  WIN32_FIND_DATA wfd;
  if (missingp(STACK_0)) {
    find_first_file(STACK_1,&wfd,NULL);
    wfd_to_file_info(&wfd);
  } else {
    HANDLE sh;
    gcv_object_t *phys = &STACK_0;
    unsigned int count = 1;
    find_first_file(STACK_1,&wfd,&sh); *phys = value1; /* physical name */
    wfd_to_file_info(&wfd); pushSTACK(value1);
    while (1) {
      begin_blocking_system_call();
      if (!FindNextFile(sh,&wfd)) {
        if (GetLastError() == ERROR_NO_MORE_FILES) break;
        end_blocking_system_call();
        OS_file_error(*phys);
      }
      end_blocking_system_call();
      wfd_to_file_info(&wfd); pushSTACK(value1); count++;
    }
    begin_blocking_system_call(); FindClose(sh); end_blocking_system_call();
    VALUES1(listof(count));
  }
  skipSTACK(2);                 /* drop arguments */
}

DEFUN(POSIX::MAKE-SHORTCUT, file &key WORKING-DIRECTORY ARGUMENTS \
      SHOW-COMMAND ICON DESCRIPTION HOT-KEY PATH) {
  HRESULT hres;
  IShellLink* psl;
  IPersistFile* ppf;
  gcv_object_t *file = &STACK_7;

  /* Get a pointer to the IShellLink interface. */
  begin_blocking_system_call();
  hres = BTCoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
                            &IID_IShellLink, (LPVOID*)&psl);
  if (!SUCCEEDED(hres)) goto fail_none;
  end_blocking_system_call();
  if (!missingp(STACK_0)) {     /* PATH */
    object path = check_string(STACK_0);
    with_string_0(path,GLO(pathname_encoding),pathz, {
      begin_blocking_system_call();
      hres = psl->lpVtbl->SetPath(psl,pathz);
      if (!SUCCEEDED(hres)) goto fail_psl;
      end_blocking_system_call();
    });
  }
  skipSTACK(1);                 /* drop PATH */
  if (!missingp(STACK_0)) {     /* HOT-KEY */
    WORD hot_key = 0;
    object hk = STACK_0;
    BYTE *pb = (BYTE*)&hot_key;
   restart_hot_key:
    if (charp(hk)) hot_key = char_int(hk);
    else while (consp(hk)) {
      if (eq(Car(hk),`:CONTROL`)) pb[1] |= HOTKEYF_CONTROL;
      else if (eq(Car(hk),`:ALT`)) pb[1] |= HOTKEYF_ALT;
      else if (eq(Car(hk),`:EXT`)) pb[1] |= HOTKEYF_EXT;
      else if (eq(Car(hk),`:SHIFT`)) pb[1] |= HOTKEYF_SHIFT;
      else if (charp(Car(hk))) {
        pb[0] = char_int(hk);
        break;
      } else {
        pushSTACK(NIL);         /* no PLACE */
        pushSTACK(hk);          /* TYPE-ERROR slot DATUM */
        pushSTACK(`(MEMBER :ALT :CONTROL :EXT :SHIFT)`); /* EXPECTED-TYPE */
        pushSTACK(STACK_0); pushSTACK(hk); pushSTACK(TheSubr(subr_self)->name);
        check_value(type_error,GETTEXT("~S: ~S is not a ~S"));
        hk = value1;
        goto restart_hot_key;
      }
      hk = Cdr(hk);
    }
    if (pb[0] == 0) {           /* STACK_0 is the HOT-KEY arg */
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: invalid hotkey spec ~S"));
    }
    begin_blocking_system_call();
    hres = psl->lpVtbl->SetHotkey(psl,hot_key);
    if (!SUCCEEDED(hres)) goto fail_psl;
    end_blocking_system_call();
  }
  skipSTACK(1);                 /* drop HOT-KEY */
  if (!missingp(STACK_0)) {     /* DESCRIPTION */
    object desc = check_string(STACK_0);
    with_string_0(desc,GLO(pathname_encoding),descz, {
      begin_blocking_system_call();
      hres = psl->lpVtbl->SetDescription(psl,descz);
      if (!SUCCEEDED(hres)) goto fail_psl;
      end_blocking_system_call();
    });
  }
  skipSTACK(1);                 /* drop DESCRIPTION */
  if (!missingp(STACK_0)) {     /* ICON */
    object icon_name;
    int icon_idx = 0;
    if (consp(STACK_0)) {       /* (file . index) or (file index) */
      icon_name = check_string(Car(STACK_0));
      icon_idx = I_to_uint32(check_uint32(consp(Cdr(STACK_0))
                                          ? Car(Cdr(STACK_0))
                                          : Cdr(STACK_0)));
    } else icon_name = check_string(STACK_0);
    with_string_0(icon_name,GLO(pathname_encoding),iconz, {
      begin_blocking_system_call();
      hres = psl->lpVtbl->SetIconLocation(psl,iconz,icon_idx);
      if (!SUCCEEDED(hres)) goto fail_psl;
      end_blocking_system_call();
    });
  }
  skipSTACK(1);                 /* drop ICON */
  if (!missingp(STACK_0)) {     /* SHOW-COMMAND */
    object sc = STACK_0;
    int sci;
   restart_show_command:
    if (eq(sc,S(Knormal))) sci = SW_SHOWNORMAL;
    else if (eq(sc,`:MAX`)) sci = SW_SHOWMAXIMIZED;
    else if (eq(sc,`:MIN`)) sci = SW_SHOWMINIMIZED;
    else {
      pushSTACK(NIL);           /* no PLACE */
      pushSTACK(sc);            /* TYPE-ERROR slot DATUM */
      pushSTACK(`(MEMBER :NORMAL :MAX :MIN)`); /* EXPECTED-TYPE */
      pushSTACK(STACK_0); pushSTACK(sc); pushSTACK(TheSubr(subr_self)->name);
      check_value(type_error,GETTEXT("~S: ~S is not a ~S"));
      sc = value1;
      goto restart_show_command;
    }
    begin_blocking_system_call();
    hres = psl->lpVtbl->SetShowCmd(psl,sci);
    if (!SUCCEEDED(hres)) goto fail_psl;
    end_blocking_system_call();
  }
  skipSTACK(1);                 /* drop SHOW-COMMAND */
  if (!missingp(STACK_0)) {     /* ARGUMENTS */
    object args = check_string(STACK_0);
    with_string_0(args,GLO(pathname_encoding),argz, {
      begin_blocking_system_call();
      hres = psl->lpVtbl->SetArguments(psl,argz);
      if (!SUCCEEDED(hres)) goto fail_psl;
      end_blocking_system_call();
    });
  }
  skipSTACK(1);                 /* drop ARGUMENTS */
  if (!missingp(STACK_0)) {     /* WORKING-DIRECTORY */
    object wd = check_string(STACK_0);
    with_string_0(wd,GLO(pathname_encoding),wdz, {
      begin_blocking_system_call();
      hres = psl->lpVtbl->SetWorkingDirectory(psl,wdz);
      if (!SUCCEEDED(hres)) goto fail_psl;
      end_blocking_system_call();
    });
  }
  skipSTACK(1);                 /* drop WORKING-DIRECTORY */
  STACK_0 = physical_namestring(STACK_0); /* pathname */

  begin_blocking_system_call();
  hres = psl->lpVtbl->QueryInterface(psl,&IID_IPersistFile,(LPVOID*)&ppf);
  if (!SUCCEEDED(hres)) goto fail_psl;
  { /* Ensure that the string is Unicode & Save the shortcut. */
    WCHAR wsz[MAX_PATH];
    with_string_0(*file, GLO(pathname_encoding), pathz, {
      MultiByteToWideChar(CP_ACP, 0, pathz, -1, wsz, MAX_PATH);
      hres = ppf->lpVtbl->Save(ppf, wsz, TRUE);
      if (!SUCCEEDED(hres)) goto fail_ppf;
    });
  }
  ppf->lpVtbl->Release(ppf);
  psl->lpVtbl->Release(psl);
  end_blocking_system_call();
  VALUES1(popSTACK()); return;
 fail_ppf: ppf->lpVtbl->Release(ppf);
 fail_psl: psl->lpVtbl->Release(psl);
 fail_none: end_blocking_system_call(); OS_file_error(*file);
}

DEFUN(POSIX::SHORTCUT-INFO, file) {
  HRESULT hres;
  IShellLink* psl;
  char path[MAX_PATH], wd[MAX_PATH], args[MAX_PATH],
    icon[MAX_PATH], desc[MAX_PATH];
  WIN32_FIND_DATA wfd;
  IPersistFile* ppf;
  gcv_object_t *file = &STACK_0;
  int icon_idx, show_cmd;
  WORD hot_key;

  STACK_0 = physical_namestring(STACK_0);

  /* Get a pointer to the IShellLink interface. */
  begin_blocking_system_call();
  hres = BTCoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
                            &IID_IShellLink, (LPVOID*)&psl);
  if (!SUCCEEDED(hres)) goto fail_none;
  /* Get a pointer to the IPersistFile interface. */
  hres = psl->lpVtbl->QueryInterface(psl,&IID_IPersistFile,(LPVOID*)&ppf);
  if (!SUCCEEDED(hres)) goto fail_psl;
  { /* Ensure that the string is Unicode & Load the shortcut. */
    WCHAR wsz[MAX_PATH];
    with_string_0(STACK_0, GLO(pathname_encoding), pathz, {
      MultiByteToWideChar(CP_ACP, 0, pathz, -1, wsz, MAX_PATH);
      hres = ppf->lpVtbl->Load(ppf, wsz, STGM_READ);
      if (!SUCCEEDED(hres)) goto fail_ppf;
    });
  }
  /* Resolve the link. */
  hres = psl->lpVtbl->Resolve(psl,NULL,0);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 1 path, 2 file info */
  hres = psl->lpVtbl->GetPath(psl,path, MAX_PATH, &wfd, 4/*SLGP_RAWPATH*/);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 3 working directory */
  hres = psl->lpVtbl->GetWorkingDirectory(psl,wd, MAX_PATH);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 4 arguments */
  hres = psl->lpVtbl->GetArguments(psl,args, MAX_PATH);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 5 show command */
  hres = psl->lpVtbl->GetShowCmd(psl,&show_cmd);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 6 icon */
  hres = psl->lpVtbl->GetIconLocation(psl,icon, MAX_PATH, &icon_idx);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 7 description */
  hres = psl->lpVtbl->GetDescription(psl,desc, MAX_PATH);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  /* 8 hot key */
  hres = psl->lpVtbl->GetHotkey(psl,&hot_key);
  if (!SUCCEEDED(hres)) goto fail_ppf;
  ppf->lpVtbl->Release(ppf);
  psl->lpVtbl->Release(psl);
  end_blocking_system_call();
  pushSTACK(asciz_to_string(path,GLO(pathname_encoding))); /* 1 */
  wfd_to_file_info(&wfd); pushSTACK(value1);               /* 2 */
  pushSTACK(asciz_to_string(wd,GLO(pathname_encoding)));   /* 3 */
  pushSTACK(asciz_to_string(args,GLO(pathname_encoding))); /* 4 */
  switch (show_cmd) {                                   /* 5 */
    case SW_SHOWNORMAL: pushSTACK(S(Knormal)); break;
    case SW_SHOWMAXIMIZED: pushSTACK(`:MAX`); break;
    case SW_SHOWMINIMIZED: pushSTACK(`:MIN`); break;
    default: NOTREACHED;
  }
  pushSTACK(asciz_to_string(icon,GLO(pathname_encoding)));
  pushSTACK(fixnum(icon_idx));
  { object tmp = listof(2); pushSTACK(tmp); }           /* 6 */
  pushSTACK(asciz_to_string(desc,GLO(pathname_encoding))); /* 7 */
  { int count=0;                                        /* 8 */
    BYTE *pb = (BYTE*)&hot_key;
    if (pb[1] & HOTKEYF_ALT) { pushSTACK(`:ALT`); count++; }
    if (pb[1] & HOTKEYF_CONTROL) { pushSTACK(`:CONTROL`); count++; }
    if (pb[1] & HOTKEYF_EXT) { pushSTACK(`:EXT`); count++; }
    if (pb[1] & HOTKEYF_SHIFT) { pushSTACK(`:SHIFT`); count++; }
    pushSTACK(int_char(pb[0]));
    if (count) { object tmp = listof(count+1); pushSTACK(tmp); }
  }
  funcall(`POSIX::MAKE-SHORTCUT-INFO`,9);
  return;
 fail_ppf: ppf->lpVtbl->Release(ppf);
 fail_psl: psl->lpVtbl->Release(psl);
 fail_none: end_blocking_system_call(); OS_file_error(*file);
}

DEFUN(POSIX::SYSTEM-INFO,)
{ /* interface to GetSystemInfo() */
  SYSTEM_INFO si;
  begin_system_call();
  GetSystemInfo(&si);
  end_system_call();
  switch (si.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_UNKNOWN: pushSTACK(`:UNKNOWN`); break;
    case PROCESSOR_ARCHITECTURE_INTEL:   pushSTACK(`:INTEL`); break;
    case PROCESSOR_ARCHITECTURE_MIPS:    pushSTACK(`:MIPS`); break;
    case PROCESSOR_ARCHITECTURE_ALPHA:   pushSTACK(`:ALPHA`); break;
    case PROCESSOR_ARCHITECTURE_PPC:     pushSTACK(`:PPC`); break;
    case PROCESSOR_ARCHITECTURE_IA64 :   pushSTACK(`:IA64`); break;
    default: pushSTACK(UL_to_I(si.wProcessorArchitecture));
  }
  pushSTACK(UL_to_I(si.dwPageSize));
  pushSTACK(UL_to_I((DWORD)si.lpMinimumApplicationAddress));
  pushSTACK(UL_to_I((DWORD)si.lpMaximumApplicationAddress));
  pushSTACK(UL_to_I(si.dwActiveProcessorMask));
  pushSTACK(UL_to_I(si.dwNumberOfProcessors));
  pushSTACK(UL_to_I(si.dwAllocationGranularity));
  pushSTACK(fixnum(si.wProcessorLevel));
  pushSTACK(fixnum(si.wProcessorRevision));
  funcall(`POSIX::MAKE-SYSTEM-INFO`,9);
}

DEFUN(POSIX::VERSION,)
{ /* interface to GetVersionEx() */
  OSVERSIONINFOEX vi;
  bool status;
  vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  begin_system_call();
  status = GetVersionEx((OSVERSIONINFO*)&vi);
  end_system_call();
  if (!status) OS_error();

  pushSTACK(UL_to_I(vi.dwMajorVersion));
  pushSTACK(UL_to_I(vi.dwMinorVersion));
  pushSTACK(UL_to_I(vi.dwBuildNumber));
  switch (vi.dwPlatformId) {
    case VER_PLATFORM_WIN32s:        pushSTACK(`:S`); break;
    case VER_PLATFORM_WIN32_WINDOWS: pushSTACK(`:WINDOWS`); break;
    case VER_PLATFORM_WIN32_NT:      pushSTACK(`:NT`); break;
    default: pushSTACK(UL_to_I(vi.dwPlatformId));
  }
  pushSTACK(safe_to_string(vi.szCSDVersion));
  pushSTACK(UL_to_I(vi.wServicePackMajor));
  pushSTACK(UL_to_I(vi.wServicePackMinor));
  { /* wSuiteMask */
    object suites = NIL;
    unsigned int count = 0;
    if (vi.wSuiteMask & VER_SUITE_BACKOFFICE)
      { pushSTACK(`:BACKOFFICE`); count++; }
    if (vi.wSuiteMask & VER_SUITE_DATACENTER)
      { pushSTACK(`:DATACENTER`); count++; }
    if (vi.wSuiteMask & VER_SUITE_ENTERPRISE)
      { pushSTACK(`:ENTERPRISE`); count++; }
    if (vi.wSuiteMask & VER_SUITE_SMALLBUSINESS)
      { pushSTACK(`:SMALLBUSINESS`); count++; }
    if (vi.wSuiteMask & VER_SUITE_SMALLBUSINESS_RESTRICTED)
      { pushSTACK(`:SMALLBUSINESS-RESTRICTED`); count++; }
    if (vi.wSuiteMask & VER_SUITE_TERMINAL)
      { pushSTACK(`:TERMINAL`); count++; }
    if (vi.wSuiteMask & VER_SUITE_PERSONAL)
      { pushSTACK(`:PERSONAL`); count++; }
    if (count) suites = listof(count);
    pushSTACK(suites);
  }
  switch (vi.wProductType) {
    case VER_NT_WORKSTATION:       pushSTACK(`:WORKSTATION`); break;
    case VER_NT_DOMAIN_CONTROLLER: pushSTACK(`:DOMAIN-CONTROLLER`); break;
    case VER_NT_SERVER:            pushSTACK(`:SERVER`); break;
    default: pushSTACK(UL_to_I(vi.wProductType));
  }
  funcall(`POSIX::MAKE-VERSION`,9);
}

DEFUN(POSIX::MEMORY-STATUS,)
{ /* interface to GlobalMemoryStatus() */
#ifdef HAVE_GLOBALMEMORYSTATUSEX
  MEMORYSTATUSEX ms;
  bool status;
  ms.dwLength = sizeof(MEMORYSTATUSEX);
  begin_system_call();
  status = GlobalMemoryStatusEx(&ms);
  end_system_call();
  if (!status) OS_error();
  pushSTACK(UQ_to_I(ms.ullTotalPhys));
  pushSTACK(UQ_to_I(ms.ullAvailPhys));
  pushSTACK(UQ_to_I(ms.ullTotalPageFile));
  pushSTACK(UQ_to_I(ms.ullAvailPageFile));
  pushSTACK(UQ_to_I(ms.ullTotalVirtual));
  pushSTACK(UQ_to_I(ms.ullAvailVirtual));
#else
  MEMORYSTATUS ms;
  ms.dwLength = sizeof(MEMORYSTATUS);
  begin_system_call(); GlobalMemoryStatus(&ms); end_system_call();
  pushSTACK(UL_to_I(ms.dwTotalPhys));
  pushSTACK(UL_to_I(ms.dwAvailPhys));
  pushSTACK(UL_to_I(ms.dwTotalPageFile));
  pushSTACK(UL_to_I(ms.dwAvailPageFile));
  pushSTACK(UL_to_I(ms.dwTotalVirtual));
  pushSTACK(UL_to_I(ms.dwAvailVirtual));
#endif
  funcall(`POSIX::MKMEMSTAT`,6);
}

/* FILE-PROPERTIES */

#ifndef PIDSI_TITLE
#define PIDSI_TITLE               0x00000002L
#define PIDSI_SUBJECT             0x00000003L
#define PIDSI_AUTHOR              0x00000004L
#define PIDSI_KEYWORDS            0x00000005L
#define PIDSI_COMMENTS            0x00000006L
#define PIDSI_TEMPLATE            0x00000007L
#define PIDSI_LASTAUTHOR          0x00000008L
#define PIDSI_REVNUMBER           0x00000009L
#define PIDSI_EDITTIME            0x0000000aL
#define PIDSI_LASTPRINTED         0x0000000bL
#define PIDSI_CREATE_DTM          0x0000000cL
#define PIDSI_LASTSAVE_DTM        0x0000000dL
#define PIDSI_PAGECOUNT           0x0000000eL
#define PIDSI_WORDCOUNT           0x0000000fL
#define PIDSI_CHARCOUNT           0x00000010L
#define PIDSI_THUMBNAIL           0x00000011L
#define PIDSI_APPNAME             0x00000012L
#define PIDSI_DOC_SECURITY        0x00000013L
#define PRSPEC_LPWSTR	( 0 )
#define PRSPEC_PROPID	( 1 )
#define STG_E_PROPSETMISMATCHED   0x800300F0L
#endif

/* Pushes corresponding value to STACK */
static int PropVariantToLisp (PROPVARIANT *pvar) {
  if(pvar->vt & VT_ARRAY) {
    pushSTACK(S(Karray));
    return 1;
  }
  if(pvar->vt & VT_BYREF) {
    pushSTACK(`:BYREF`);
    return 1;
  }
  switch(pvar->vt) {
    case VT_EMPTY: pushSTACK(`:EMPTY`); break;
    case VT_NULL:  pushSTACK(`:NULL`);  break;
    case VT_BLOB:  pushSTACK(`:BLOB`);  break;
    case VT_BOOL:  pushSTACK(pvar->boolVal ? T : NIL); break;
    case VT_I1:    pushSTACK(sfixnum(pvar->cVal)); break;
    case VT_UI1:   pushSTACK(fixnum(pvar->bVal)); break;
    case VT_I2:    pushSTACK(sfixnum(pvar->iVal)); break;
    case VT_UI2:   pushSTACK(fixnum(pvar->uiVal)); break;
    case VT_I4:
    case VT_INT:   pushSTACK(L_to_I(pvar->lVal)); break;
    case VT_UI4:
    case VT_UINT:  pushSTACK(UL_to_I(pvar->ulVal)); break;
    case VT_ERROR: pushSTACK(UL_to_I(pvar->scode)); break;
    case VT_I8:    pushSTACK(sint64_to_I(*((sint64 *)&pvar->hVal))); break;
    case VT_CY: {
      double dbl = (*((sint64 *)&pvar->cyVal))/10000.0;
      pushSTACK(c_double_to_DF((dfloatjanus *)&dbl));
    } break;
    case VT_UI8: pushSTACK(uint64_to_I(*((uint64 *)&pvar->uhVal)));  break;
    case VT_R4:  pushSTACK(c_float_to_FF((ffloatjanus *)&pvar->fltVal)); break;
    case VT_R8:  pushSTACK(c_double_to_DF((dfloatjanus *)&pvar->dblVal));break;
    case VT_DATE:pushSTACK(c_double_to_DF((dfloatjanus *)&pvar->date)); break;
    case VT_BSTR:
      pushSTACK(n_char_to_string((const char *)pvar->bstrVal,
                                 *((DWORD *)(((const char *)pvar->bstrVal)-4)),
                                 Symbol_value(S(unicode_16_little_endian))));
      break;
    case VT_LPSTR:
      pushSTACK(safe_to_string(pvar->pszVal));
      break;
    case VT_LPWSTR:
      pushSTACK(n_char_to_string((const char *)pvar->pwszVal,
                                 wcslen(pvar->pwszVal)*2,
                                 Symbol_value(S(unicode_16_little_endian))));
      break;
    case VT_FILETIME:
      pushSTACK(convert_time_to_universal_w32(&(pvar->filetime))); break;
    case VT_CF: pushSTACK(`:CLIPBOARD-FORMAT`); break;
    default:    pushSTACK(`:NOTIMPLEMENTED`); break;
  }
  return 1;
}
/* popSTACK -> pvar  */
static int LispToPropVariant (PROPVARIANT * pvar) {
  int rv = 0;int sfp = 0;
  VARTYPE typehint = VT_EMPTY;
  if (consp(STACK_0)) {
    /* (KW VALUE) OR (KW NIL) ? */
    if (!nullp(Cdr(STACK_0)) && !nullp(Car(STACK_0))
        && consp(Cdr(STACK_0)) && nullp(Cdr(Cdr(STACK_0)))
        && symbolp(Car(STACK_0))) {
           if (eq(Car(STACK_0),`:I1`)) typehint = VT_I1;
      else if (eq(Car(STACK_0),`:UI1`)) typehint = VT_UI1;
      else if (eq(Car(STACK_0),`:I2`)) typehint = VT_I2;
      else if (eq(Car(STACK_0),`:UI2`)) typehint = VT_UI2;
      else if (eq(Car(STACK_0),`:I4`)) typehint = VT_I4;
      else if (eq(Car(STACK_0),`:INT`)) typehint = VT_INT;
      else if (eq(Car(STACK_0),`:UI4`)) typehint = VT_UI4;
      else if (eq(Car(STACK_0),`:UINT`)) typehint = VT_UINT;
      else if (eq(Car(STACK_0),`:I8`)) typehint = VT_I8;
      else if (eq(Car(STACK_0),`:UI8`)) typehint = VT_UI8;
      else if (eq(Car(STACK_0),`:R4`)) typehint = VT_R4;
      else if (eq(Car(STACK_0),`:R8`)) typehint = VT_R8;
      else if (eq(Car(STACK_0),`:CY`)) typehint = VT_CY;
      else if (eq(Car(STACK_0),`:DATE`)) typehint = VT_DATE;
      else if (eq(Car(STACK_0),`:BSTR`)) typehint = VT_BSTR;
      else if (eq(Car(STACK_0),`:BOOL`)) typehint = VT_BOOL;
      else if (eq(Car(STACK_0),`:ERROR`)) typehint = VT_ERROR;
      else if (eq(Car(STACK_0),`:FILETIME`)) typehint = VT_FILETIME;
      else if (eq(Car(STACK_0),`:LPSTR`)) typehint = VT_LPSTR;
      else if (eq(Car(STACK_0),`:LPWSTR`)) typehint = VT_LPWSTR;
      else { skipSTACK(1); return 0; }
      STACK_0 = Car(Cdr(STACK_0)); /* VALUE */
    } else { skipSTACK(1); return 0; }
  }
  if (stringp(STACK_0)
      && (typehint == VT_EMPTY || typehint == VT_BSTR
          || typehint == VT_LPSTR || typehint == VT_LPWSTR)) {
    if (typehint == VT_EMPTY) {
#    define STG_STRINGS_NONUNICODE
#    ifdef STG_STRINGS_UNICODE
      typehint = VT_LPWSTR;
#    else
      typehint = VT_LPSTR;
#    endif
    }
    do {
      uintL str_len;
      uintL str_offset;
      object str_string = unpack_string_ro(STACK_0,&str_len,&str_offset);
      const chart* ptr1;
      unpack_sstring_alloca(str_string,str_len,str_offset, ptr1=);
      if (typehint == VT_LPWSTR || typehint == VT_BSTR) {
        uintL str_bytelen =
          cslen(Symbol_value(S(unicode_16_little_endian)),ptr1,str_len);
        LPWSTR str = SysAllocStringByteLen(NULL,str_bytelen+4);
        if (typehint == VT_BSTR) {
          /* it's ok, SysAllocStringByteLen returns pointer after DWORD */
          *(((DWORD *)str)-1) = (DWORD)str_bytelen;
        }
        cstombs(Symbol_value(S(unicode_16_little_endian)),ptr1,str_len,
                (uintB *)str,str_bytelen);
        ((uintB *)str)[str_bytelen] = '\0';
        ((uintB *)str)[str_bytelen+1] = '\0';
        pvar->pwszVal = str;
        pvar->vt = typehint;
      } else { /* Win XP explorer seems to create ANSI strings. So do we. */
        uintL str_bytelen = cslen(GLO(misc_encoding),ptr1,str_len);
        char * str = (char *) SysAllocStringByteLen(NULL, str_bytelen+2);
        cstombs(GLO(misc_encoding),ptr1,str_len,(uintB *)str,str_bytelen);
        str[str_bytelen] = '\0';
        pvar->pszVal = str;
        pvar->vt = VT_LPSTR;
      }
      rv = 1;
    } while(0);
  } else if (integerp(STACK_0)) {
    if (typehint == VT_EMPTY) typehint = VT_FILETIME; /* assume FILETIME */
    if (typehint == VT_FILETIME) {
      pvar->vt = VT_FILETIME; rv = 1;
      convert_time_from_universal_w32(STACK_0,&(pvar->filetime));
    } else if (typehint == VT_I1) {
      pvar->vt = typehint; pvar->cVal = I_to_sint8(STACK_0); rv = 1;
    } else if (typehint == VT_UI1) {
      pvar->vt = typehint; pvar->bVal = I_to_uint8(STACK_0); rv = 1;
    } else if (typehint == VT_I2) {
      pvar->vt = typehint; pvar->iVal = I_to_sint16(STACK_0); rv = 1;
    } else if (typehint == VT_UI2) {
      pvar->vt = typehint; pvar->uiVal = I_to_uint16(STACK_0); rv = 1;
    } else if (typehint == VT_I4 || typehint == VT_INT) { /* VT_I4 != VT_INT */
      pvar->vt = typehint; pvar->lVal = I_to_sint32(STACK_0); rv = 1;
    } else if (typehint == VT_UI4 || typehint == VT_UINT) {
      pvar->vt = typehint; pvar->ulVal = I_to_uint32(STACK_0); rv = 1;
    } else if (typehint == VT_ERROR) {
      pvar->vt = typehint; pvar->scode = I_to_uint32(STACK_0); rv = 1;
    } else if (typehint == VT_I8) {
      pvar->vt = typehint;
      *((sint64 *)&pvar->hVal) = I_to_sint64(STACK_0);rv = 1;
    } else if (typehint == VT_UI8) {
      pvar->vt = typehint;
      *((uint64 *)&pvar->uhVal) = I_to_uint64(STACK_0);rv = 1;
    } else if (typehint == VT_CY) {
      sint64 i64 = I_to_uint64(STACK_0);
      pvar->vt = typehint;
      *((uint64 *)&pvar->cyVal) = i64*10000;rv = 1;
    }
  } else if ((sfp = single_float_p(STACK_0)) || double_float_p(STACK_0)) {
    if (typehint == VT_EMPTY) typehint = (sfp?VT_R4:VT_R8);
    if (typehint == VT_R4) {
      if (sfp) {
        pvar->vt = VT_R4;
        pvar->fltVal = 0;
        FF_to_c_float(STACK_0,(ffloatjanus *)&pvar->fltVal);
        rv = 1;
      }
    } else if (typehint == VT_R8) {
      pvar->vt = VT_R8;
      if (sfp) {
        float v = 0;
        FF_to_c_float(STACK_0,(ffloatjanus *)&v);
        pvar->dblVal = v;
      } else {
        pvar->dblVal = 0; /* DF_to_c_double takes only clean doubles */
        DF_to_c_double(STACK_0,(dfloatjanus *)&pvar->dblVal);
      }
      rv = 1;
    } else if (typehint == VT_DATE && double_float_p(STACK_0)) {
      /* A 64-bit floating point number representing the number of days
         (not seconds) since December 31, 1899. For example, January 1, 1900,
         is 2.0, January 2, 1900, is 3.0, and so on). This is stored in the
         same representation as VT_R8. */
      pvar->vt = VT_DATE;
      pvar->date = 0;
      DF_to_c_double(STACK_0,(dfloatjanus *)&pvar->date);
      rv = 1;
    } else if (typehint == VT_CY) {
      double dbl = 0; float v = 0;
      pvar->vt = typehint;
      if (sfp) {
        FF_to_c_float(STACK_0,(ffloatjanus *)&v);
        dbl = v;
      } else {
        DF_to_c_double(STACK_0,(dfloatjanus *)&dbl);
      }
      *((uint64 *)&pvar->cyVal) = (uint64) (dbl*10000 + 0.5);rv = 1;
    }
  } else if (symbolp(STACK_0)) {
    if (typehint == VT_EMPTY && eq(STACK_0,`:EMPTY`)) {
      pvar->vt = VT_EMPTY; rv = 1; } else
    if (typehint == VT_EMPTY && eq(STACK_0,`:NULL`)) {
      pvar->vt = VT_NULL;  rv = 1; } else
    if (typehint == VT_BOOL && eq(STACK_0,NIL)) {
      pvar->vt = VT_BOOL; pvar->boolVal = FALSE;  rv = 1; } else
    if (typehint == VT_BOOL && eq(STACK_0,T)) {
      pvar->vt = VT_BOOL; pvar->boolVal = TRUE;  rv = 1; }
  }
  skipSTACK(1);
  return rv;
}

WINOLEAPI PropVariantClear(PROPVARIANT* pvar);

static PROPID kwtopropid (object kw) {
  if (eq(kw,`:CODEPAGE`)) return 1 /* PID_CODEPAGE */;
  if (eq(kw,`:LOCALE`)) return 0x80000000 /* PID_LOCALE */;
  if (eq(kw,`:TITLE`)) return PIDSI_TITLE;
  if (eq(kw,`:SUBJECT`)) return PIDSI_SUBJECT;
  if (eq(kw,`:AUTHOR`)) return PIDSI_AUTHOR;
  if (eq(kw,`:KEYWORDS`)) return PIDSI_KEYWORDS;
  if (eq(kw,`:COMMENTS`)) return PIDSI_COMMENTS;
  if (eq(kw,`:TEMPLATE`)) return PIDSI_TEMPLATE;
  if (eq(kw,`:LASTAUTHOR`)) return PIDSI_LASTAUTHOR;
  if (eq(kw,`:REVNUMBER`)) return PIDSI_REVNUMBER;
  if (eq(kw,`:EDITTIME`)) return PIDSI_EDITTIME;
  if (eq(kw,`:LASTPRINTED`)) return PIDSI_LASTPRINTED;
  if (eq(kw,`:CREATE-DTM`)) return PIDSI_CREATE_DTM;
  if (eq(kw,`:LASTSAVE-DTM`)) return PIDSI_LASTSAVE_DTM;
  if (eq(kw,`:PAGECOUNT`)) return PIDSI_PAGECOUNT;
  if (eq(kw,`:WORDCOUNT`)) return PIDSI_WORDCOUNT;
  if (eq(kw,`:CHARCOUNT`)) return PIDSI_CHARCOUNT;
  if (eq(kw,`:THUMBNAIL`)) return PIDSI_THUMBNAIL;
  if (eq(kw,`:APPNAME`)) return PIDSI_APPNAME;
  if (eq(kw,`:DOC-SECURITY`)) return PIDSI_DOC_SECURITY;
  return (PROPID)-1;
}

/* string -> PROPSPEC */
static void PropSpecSetStr (object str, PROPSPEC * pspec) {
  pspec->ulKind = PRSPEC_LPWSTR;
  { uintL str_len;
    uintL str_offset;
    object str_string = unpack_string_ro(str,&str_len,&str_offset);
    const chart* ptr1;
    unpack_sstring_alloca(str_string,str_len,str_offset, ptr1=);
    { uintL str_bytelen =
        cslen(Symbol_value(S(unicode_16_little_endian)),ptr1,str_len);
      pspec->lpwstr = (LPOLESTR)clisp_malloc(str_bytelen+2);
      begin_system_call();
      cstombs(Symbol_value(S(unicode_16_little_endian)),ptr1,str_len,
              (uintB *)pspec->lpwstr,str_bytelen);
      end_system_call();
      ((uintB *)pspec->lpwstr)[str_bytelen] = '\0';
      ((uintB *)pspec->lpwstr)[str_bytelen+1] = '\0';
    }
  }
}

/* list (ID STRING) -> PROPSPEC(ID), PROPSPEC(STR)
   STACK may don't match the pattern (then function returns false)
   any of pspec1, pspec2 can be NULL */
static int propspeclistp (object arg, PROPSPEC * pspec1,PROPSPEC * pspec2) {
  /* check if it is (INT STRING) */
  if (consp(arg) && !nullp(Cdr(arg)) && !nullp(Car(arg))
      && consp(Cdr(arg)) && nullp(Cdr(Cdr(arg)))
      && !nullp(Car(Cdr(arg)))
      && (integerp(Car(arg)) || symbolp(Car(arg)))
      && stringp(Car(Cdr(arg)))) {
    /* set pspec1 to ID and pspec2 to STRING */
    if (pspec1) {
      pspec1->ulKind = PRSPEC_PROPID;
      if (integerp(Car(arg)))
        pspec1->propid = I_to_UL(Car(arg));
      else {
        pspec1->propid = kwtopropid(Car(arg));
        if (pspec1->propid == (PROPID) -1)
          return 0;
      }
    }
    if (pspec2)
      PropSpecSetStr(Car(Cdr(arg)),pspec2);
    return 1;
  }
  return 0;
}

/* (keyword, int, list (ID STRING) or string) -> PROPSPEC
   uses malloc to allocate memory for string specifiers
     (when ulKind == PRSPEC_LPWSTR)
   pspec2 can be NULL */
static int PropSpecSet (object arg, PROPSPEC * pspec1, PROPSPEC * pspec2) {
  ZeroMemory(pspec1, sizeof(PROPSPEC));
  if (pspec2) ZeroMemory(pspec2, sizeof(PROPSPEC));
  if (symbolp(arg)) {
    pspec1->ulKind = PRSPEC_PROPID;
    pspec1->propid = kwtopropid(arg);
    if (pspec1->propid == (PROPID) -1) return 0;
    return 1;
  } else if (stringp(arg)) {
    PropSpecSetStr(arg,pspec1);
    return 1;
  } else if (integerp(arg)) {
    pspec1->ulKind = PRSPEC_PROPID;
    pspec1->propid = I_to_UL(arg);
    return 1;
  } else if (propspeclistp(arg,pspec1,pspec2)) return 2;
  return 0;
}

static const char * DecodeHRESULT (HRESULT hres) {
  static char buf[128];
#define msgcase(x) case x: return #x; break;
  switch (hres) {
  msgcase(E_UNEXPECTED)
  msgcase(STG_E_FILENOTFOUND)
  msgcase(STG_E_ACCESSDENIED)
  msgcase(STG_E_INSUFFICIENTMEMORY)
  msgcase(STG_E_INVALIDFUNCTION)
  msgcase(STG_E_REVERTED)
  msgcase(STG_E_INVALIDPARAMETER)
  msgcase(STG_E_INVALIDNAME)
  msgcase(S_FALSE)
  msgcase(STG_E_INVALIDPOINTER)
  msgcase(HRESULT_FROM_WIN32(ERROR_NO_UNICODE_TRANSLATION))
  msgcase(HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED))
  msgcase(STG_E_WRITEFAULT)
  msgcase(STG_E_MEDIUMFULL)
  msgcase(STG_E_PROPSETMISMATCHED)
  }
#undef msgcase
  sprintf(buf,"0x%x",hres);
  return buf;
}

#define with_string_0w(string,wcvar,statement) \
  do { uintL wcvar##_len;                  \
    uintL wcvar##_offset;                  \
    object wcvar##_string = unpack_string_ro(string,&wcvar##_len,&wcvar##_offset); \
    const chart* ptr1;                     \
    unpack_sstring_alloca(wcvar##_string,wcvar##_len,wcvar##_offset, ptr1=); \
   {uintL wcvar##_bytelen =                \
     cslen(Symbol_value(S(unicode_16_little_endian)),ptr1,wcvar##_len); \
    DYNAMIC_ARRAY(wcvar##_data,uintB,wcvar##_bytelen+2); \
    cstombs(Symbol_value(S(unicode_16_little_endian)),ptr1,wcvar##_len,\
            &wcvar##_data[0],wcvar##_bytelen); \
    wcvar##_data[wcvar##_bytelen] = '\0';            \
    wcvar##_data[wcvar##_bytelen+1] = '\0';          \
   {WCHAR* wcvar = (WCHAR*) &wcvar##_data[0];   \
    statement                                       \
    }                                                \
    FREE_DYNAMIC_ARRAY(wcvar##_data);                \
  }} while(0)

/* there's no PropVariantInit in my cygwin headers */
#define MyPropVariantInit(ppv)     begin_system_call(); \
  ZeroMemory(ppv,sizeof(PROPVARIANT));end_system_call()

/* (OS::FILE-PROPERTIES filename set [specifier value|:INITID init-id]*)
     Wrapper for Win32 IPropertyStorage functionality
     filename - a compound file name or (on NTFS) name of any file
     set      - :BUILT-IN or :USER-DEFINED property set
     specifier - property specifier: integer, keyword, string or
       list of integer or keyword and string.
       Integer specifier - a property identifier
       Keyword:  :CODEPAGE, :LOCALE,   :TITLE, :SUBJECT, :AUTHOR,
                 :KEYWORDS, :COMMENTS, :TEMPLATE, :LASTAUTHOR,
                 :REVNUMBER, :EDITTIME, :LASTPRINTED,:CREATE-DTM,
                 :LASTSAVE-DTM, :PAGECOUNT, :WORDCOUNT, :CHARCOUNT,
                 :THUMBNAIL, :APPNAME, :DOC-SECURITY - predefined IDs.
       String: string property specifier. If no match is found, first
         ID >= init-id (which defaults to 2) is associated with the
         string and it's value is replaced with new value.
       (int|keyword string) - first element is used as specifier,
         string is associated with this ID.
     value - new value of the property, suitable lisp object, nil or list of
       keyword and value itself. If value is NIL, no assignment is done.
       :EMPTY and :NULL correspond VT_EMPTY and VT_NULL datatypes.
       Keyword in the list specifies the desired type of property being set.
       Supported types are :I1, :UI1, :I2, :UI2, :I4, :UI4, :UINT, :I8,
         :UI8, :R4, :R8, :DATE, :BSTR, :BOOL, :ERROR, :FILETIME,
         :LPSTR, :LPWSTR. FILETIMEs are converted to/from universal time format,
         while DATEs are not.

     returns multiple values - property contents before assignment. */
DEFUN(POSIX::FILE-PROPERTIES, file set &rest pairs)
{ /* TODO: close interfaces even on errors;
           support more datatypes
           use IPropertySetStorage::Create when it doesn't exist */
  IPropertyStorage * ppropstg = NULL;
  IPropertySetStorage * ppropsetstg = NULL;
  HRESULT hres;
  FMTID const * fmtid = NULL;
  PROPSPEC * pspecrd = NULL;
  PROPSPEC * pspecwr = NULL;
  PROPVARIANT * pvarrd = NULL;
  PROPVARIANT * pvarwr = NULL;
  PROPID * propidwpnvec = NULL; /* args for WritePropertyNames */
  LPWSTR * lpwstrwpnvec = NULL;
  int ifile = argcount + 1;
  int iset = argcount;
  int i;
  unsigned int initid = 2;
  int use_wpn = 0; /* should WritePropertyNames be used ? */
  int nproprd = 0, npropwr = 0; /* npropd >= npropwr */
  int cproprd = 0, cpropwr = 0;
  int cwpnpar = 0;
  /* argcount is (length pairs), not the total arg count */
  /* no &rest ? no sense. */
  if (argcount == 0) {
    skipSTACK(2);
    VALUES0;
    return;
  }
  /* count the number of r/rw props, checking arglist sanity */
  if (argcount % 2)
    error_key_odd(argcount,TheSubr(subr_self)->name);
  for(i=argcount-1;i>=0;i--) {
    if (i % 2) { /* specifier */
      if (!symbolp(STACK_(i)) && !stringp(STACK_(i))
          && !posfixnump(STACK_(i))) {
        if (!propspeclistp(STACK_(i),NULL,NULL)) {
          pushSTACK(TheSubr(subr_self)->name);
          error(program_error,
            GETTEXT("~S: bad property specifier - it must be string, "
                    "positive number, list or keyword"));
        } else { use_wpn++; nproprd++; }
      } else if (symbolp(STACK_(i)) && eq(STACK_(i),`:INITID`)) initid = 0;
      else nproprd++;
    } else { /* value */
      if (!initid) {
        if (integerp(STACK_(i))) initid = I_to_UL(STACK_(i));
        else {
          pushSTACK(STACK_(i));
          pushSTACK(TheSubr(subr_self)->name);
          error(program_error,GETTEXT("~S: bad INITID specifier: ~S"));
        }
      } else if (!nullp(STACK_(i))) npropwr++;
    }
  }
  if (!StgOpenStorageExFunc) {
    begin_system_call();
    SetLastError(ERROR_INVALID_FUNCTION);
    end_system_call();
    OS_error();
  }
  STACK_(ifile) = physical_namestring(STACK_(ifile));
  with_string_0w(STACK_(ifile), filename, {
      begin_blocking_system_call();
      hres = StgOpenStorageExFunc(filename,
                                  ((npropwr||use_wpn)?STGM_READWRITE:STGM_READ)
                                  | STGM_SHARE_EXCLUSIVE,
                                  4 /* STGFMT_ANY */, 0, NULL /*&stgOp*/, 0,
                                  &IID_IPropertySetStorage,
                                  (void **)&ppropsetstg);
      end_blocking_system_call();
  });
  if (FAILED(hres)) {
    pushSTACK(STACK_(ifile));
    pushSTACK(TheSubr(subr_self)->name);
    switch(hres) {
      case STG_E_FILENOTFOUND:
        error(file_error,GETTEXT("~S: file ~S does not exist"));
      case STG_E_FILEALREADYEXISTS:
        error(file_error,GETTEXT("~S: file ~S is not a compound file nor it is on the NTFS file system"));
      default:
        error(file_error,GETTEXT("~S: StgOpenStorageEx() failed on file ~S"));
    }
  }
  if (eq(STACK_(iset),`:USER-DEFINED`))
    fmtid = &FMTID_UserDefinedProperties;
  else if (eq(STACK_(iset),`:BUILT-IN`))
    fmtid = &FMTID_SummaryInformation;
  else {
    pushSTACK(STACK_(iset));
    pushSTACK(TheSubr(subr_self)->name);
    error(file_error,GETTEXT("~S: invalid property set specifier ~S"));
  }
  begin_blocking_system_call();
  hres = ppropsetstg->lpVtbl->Open(ppropsetstg, fmtid,
                                   ((npropwr||use_wpn)?STGM_READWRITE:STGM_READ)
                                   | STGM_SHARE_EXCLUSIVE, &ppropstg);
  end_blocking_system_call();
  if (FAILED(hres)) {
    pushSTACK(safe_to_string(DecodeHRESULT(hres)));
    pushSTACK(STACK_(ifile+1));
    pushSTACK(STACK_(iset+2));
    pushSTACK(TheSubr(subr_self)->name);
    error(file_error,GETTEXT("~S: unable to open ~S IPropertySetStorage of ~S: error ~S"));
  }
  /* fill the specifiers, init the variables */
  pspecrd =   (PROPSPEC *)clisp_malloc(sizeof(PROPSPEC)    * nproprd);
  pvarrd = (PROPVARIANT *)clisp_malloc(sizeof(PROPVARIANT) * nproprd);
  pspecwr =   (PROPSPEC *)clisp_malloc(sizeof(PROPSPEC)    * npropwr);
  pvarwr = (PROPVARIANT *)clisp_malloc(sizeof(PROPVARIANT) * npropwr);
  if (use_wpn) {
    propidwpnvec = (PROPID *)clisp_malloc(sizeof(PROPID)*use_wpn);
    lpwstrwpnvec = (LPWSTR *)clisp_malloc(sizeof(LPWSTR)*use_wpn);
  }
  for(i=0;i<argcount;i+=2) {
    /* i+1 - specifier, i - value */
    PROPSPEC second;
    int pssresult;
    if (symbolp(STACK_(i+1)) && eq(STACK_(i+1),`:INITID`)) continue;
    pssresult = PropSpecSet(STACK_(i+1),pspecrd+nproprd-cproprd-1,&second);
    MyPropVariantInit(pvarrd+nproprd-cproprd-1);
    if (!nullp(STACK_(i))) {
      PropSpecSet(STACK_(i+1),pspecwr+npropwr-cpropwr-1,NULL);
      MyPropVariantInit(pvarwr+npropwr-cpropwr-1);
      pushSTACK(STACK_(i));
      if (!LispToPropVariant(pvarwr+npropwr-cpropwr-1)) {
        pushSTACK(STACK_(i));
        pushSTACK(TheSubr(subr_self)->name);
        error(error_condition,GETTEXT("~S: cannot convert ~S to PROPVARIANT"));
      }
      cpropwr++;
    }
    if (use_wpn && pssresult == 2) {
      propidwpnvec[cwpnpar] = pspecrd[nproprd-cproprd-1].propid;
      lpwstrwpnvec[cwpnpar] = second.lpwstr;
      cwpnpar++;
    }
    cproprd++;
  }
  hres = ppropstg->lpVtbl->ReadMultiple(ppropstg,nproprd, pspecrd, pvarrd);
  if(FAILED(hres)) {
    pushSTACK(safe_to_string(DecodeHRESULT(hres)));
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: ReadMultiple error: ~S"));
  }
  if (npropwr > 0) {
    begin_blocking_system_call();
    hres = ppropstg->lpVtbl->WriteMultiple(ppropstg,npropwr,pspecwr,pvarwr,
                                           initid);
    end_blocking_system_call();
    if(FAILED(hres)) {
      pushSTACK(safe_to_string(DecodeHRESULT(hres)));
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: WriteMultiple error: ~S"));
    }
  }
  for (i=0;i<nproprd;i++)
    if (!PropVariantToLisp(pvarrd+i)) {
      pushSTACK(fixnum(i));
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: cannot convert value ~S to Lisp datatype"));
    }
  if (use_wpn) {
    hres = ppropstg->lpVtbl->WritePropertyNames(ppropstg,use_wpn,propidwpnvec,lpwstrwpnvec);
    if (FAILED(hres)) {
      pushSTACK(safe_to_string(DecodeHRESULT(hres)));
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: WritePropertyNames: ~S"));
    }
  }
  if (sizeof(mv_space)/sizeof(mv_space[0]) < nproprd) {
    pushSTACK(TheSubr(subr_self)->name);
    error(program_error,GETTEXT("~S: multiple value count limit reached"));
  }
  mv_count = nproprd;
  for (i=0;i<nproprd;i++) mv_space[nproprd-i-1] = popSTACK();
  skipSTACK(argcount+2); /* two first args */
  begin_system_call();
  for (i=0;i<nproprd;i++) {
    PropVariantClear(pvarrd+i);
    if (pspecrd[i].ulKind == PRSPEC_LPWSTR) free(pspecrd[i].lpwstr);
  }
  for (i=0;i<npropwr;i++) {
    if (pvarwr[i].vt == VT_LPWSTR || pvarwr[i].vt == VT_BSTR)
      SysFreeString(pvarwr[i].pwszVal);
    if (pvarwr[i].vt == VT_LPSTR)
      SysFreeString((BSTR)pvarwr[i].pszVal);
    if (pspecwr[i].ulKind == PRSPEC_LPWSTR) free(pspecwr[i].lpwstr);
  }
  for (i=0;i<use_wpn;i++) free(lpwstrwpnvec[i]);
  free(pspecrd); free(pvarrd); free(pspecwr); free(pvarwr);
  free(propidwpnvec); free(lpwstrwpnvec);
  ppropstg->lpVtbl->Release(ppropstg);
  ppropsetstg->lpVtbl->Release(ppropsetstg);
  end_system_call();
}

#define SIDBUFSZ 256

/* (POSIX::GET-USER-SID &optional USERNAME)
   USERNAME: string representing user's name, possibly
   containing a domain name. Current process user's SID
   is returned if no USERNAME is specified.
   Returns string representation of user's security
   identifier (SID) in S-R-I-S-S notation.
   Function could be used in conjunction with file-owner */

DEFUN(POSIX::GET-USER-SID, &optional username) {
  char buf[SIDBUFSZ];
  PSID psid;
  LPSTR sidstr;

  if (!missingp(STACK_0)) {
    WCHAR domain[SIDBUFSZ];
    DWORD sz = SIDBUFSZ, domsz = SIDBUFSZ;
    SID_NAME_USE use;

    with_string_0w(check_string(STACK_0),wstr, {
      if (!LookupAccountNameW(NULL, wstr, (PSID) buf, &sz, domain, &domsz, &use))
        OS_error();
      psid = (PSID) buf;
    });
  } else {
    HANDLE token_handle = NULL;
    TOKEN_USER * tu = ((TOKEN_USER *) buf);
    DWORD required = 0;

    if (!OpenProcessToken(GetCurrentProcess(),
                          TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,
                          &token_handle))
      OS_error();
    if (!GetTokenInformation(token_handle, TokenUser, tu, SIDBUFSZ, &required))
      OS_error();
    psid = tu->User.Sid;
  }
  if (!initialized_sid_apis)
    initialize_sid_apis();
  if (!ConvertSidToStringSidFunc) {
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: SID management library is not initialized"));
  }
  if (!ConvertSidToStringSidFunc(psid, &sidstr)) OS_error();
  VALUES1(asciz_to_string(sidstr,GLO(misc_encoding)));
  LocalFree(sidstr);
  skipSTACK(1);
}

/* helpers for CLIPBOARD and %SET-CLIPBOARD */

static int nlines_a (const char * s) {
  int result = 1;
  while (*s) if (*s++ == '\n') result++;
  return result;
}

static int nlines_w (PWSTR s) {
  int result = 1;
  while (*s) if (*s++ == (WCHAR)'\n') result++;
  return result;
}

/* copy string and convert "\n" to "\r\n" */

static void strzcpy12_a (char * dest, const char * src) {
  do {
    if (*src == '\n') *dest++ = '\r';
    *dest = *src;
    if (!*src) break;
    dest++; src++;
  } while(true);
}

static void strzcpy12_w (PWSTR dest, PCWSTR src) {
  do {
    if (*src == (WCHAR)'\n') *dest++ = (WCHAR)'\r';
    *dest = *src;
    if (!*src) break;
    dest++; src++;
  } while(true);
}

/* copy string and convert "\r\n" to "\n" */

static void strzcpy21_a (char * dest, const char * src) {
  do {
    *dest = *src;
    if (!*src) break;
    if (*src != '\r') dest++;
    src++;
  } while(true);
}

static void strzcpy21_w (PWSTR dest, PCWSTR src) {
  do {
    *dest = *src;
    if (!*src) break;
    if (*src != (WCHAR)'\r') dest++;
    src++;
  } while(true);
}

/* %SET-CLIPBOARD: set the contents of Windows clipboard to the printed
   representation of argument (PRINC-TO-STRING is used). Returns T on
   success, NIL on failure. */
DEFUN(OS::%SET-CLIPBOARD, str) {
  int textset = 0;
  pushSTACK(STACK_0); /* to return from %SET-CLIPBOARD */
  funcall(L(princ_to_string), 1);
  begin_system_call();
  if (OpenClipboard(NULL)) {
    if( EmptyClipboard() ) {
#ifdef ENABLE_UNICODE
      OSVERSIONINFO v;
      v.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
      if (GetVersionEx(&v)) {
        if (v.dwPlatformId == VER_PLATFORM_WIN32_NT) { /* Windows NT */
            with_string_0w(value1, wstr, {
              HGLOBAL sglobal =
                GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,
                            (wstr_bytelen + nlines_w(wstr) + 2)
                              * sizeof(WCHAR));
              if (sglobal != NULL) {
                void * slocal = GlobalLock(sglobal);
                if (slocal != NULL) {
                  end_system_call();
                  strzcpy12_w(slocal, wstr);
                  begin_system_call();
                  if ( SetClipboardData( CF_UNICODETEXT,  sglobal ) != NULL ) {
                    GlobalUnlock(sglobal);
                    textset = 1;
                  } else {
                    DWORD last = GetLastError();
                    GlobalFree(sglobal);
                    SetLastError(last);
                  }
                }
              }
            });
        } else {  /* Win95/98/Me - try ASCII */
#else
      { {
#endif
          with_string_0( value1, GLO(misc_encoding), cstr, {
            HGLOBAL sglobal =
              GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE, cstr_bytelen + nlines_a(cstr) + 1);
            if (sglobal != NULL) {
              void * slocal = GlobalLock(sglobal);
              if (slocal != NULL) {
                end_system_call();
                strzcpy12_a(slocal, cstr);
                begin_system_call();
                if (SetClipboardData( CF_TEXT,  sglobal ) != NULL ) {
                  GlobalUnlock(sglobal);
                  textset = 1;
                } else { /* GlobalFree only if SetClipboardData failed */
                  DWORD last = GetLastError();
                  GlobalFree(sglobal);
                  SetLastError(last);
                }
              }
            }
          });
#ifdef ENABLE_UNICODE
        } /* v.dwPlatformId */
      } /* GetVersionEx */
#else
      } } /* for MODPREP all brackets should be
             balanced like there are no ifdefs */
#endif
      CloseClipboard();
    } /* EmptyClipboard */
  } /* OpenClipboard */
  end_system_call();
  if (!textset) OS_error(); /* !textset => some system call failed
                               && LastError contain this error code */
  VALUES1(popSTACK());
}

/* CLIPBOARD: Returns the textual contents of Windows clipboard
   as a string. First try to get it as CF_UNICODETEXT, then CF_TEXT.
   On failure or when no text is available NIL is returned. */
DEFUN(OS:CLIPBOARD,) {
  VALUES1(NIL);
  begin_blocking_system_call();
  if (OpenClipboard(NULL)) {
#ifdef ENABLE_UNICODE
    HGLOBAL gltext  = GetClipboardData(CF_UNICODETEXT);
    if (gltext != NULL) { /* UNICODE TEXT */
      PWSTR wstr = (PWSTR)GlobalLock(gltext);
      if (wstr != NULL) {
        DYNAMIC_ARRAY(buf, WCHAR, wcslen(wstr) + 1);
        end_blocking_system_call();
        strzcpy21_w(buf, wstr);
        VALUES1(n_char_to_string((const char *)buf, wcslen(buf) * sizeof(WCHAR),
                                 Symbol_value(S(unicode_16_little_endian))));
        FREE_DYNAMIC_ARRAY(buf);
        begin_blocking_system_call();
        GlobalUnlock(gltext);
      }
    } else { /* Probably system just do not support UNICODE */
#endif
      gltext = GetClipboardData(CF_TEXT); /* ANSI TEXT */
      if (gltext != NULL) {
        const char * str = (const char *)GlobalLock(gltext);
        if (str != NULL) {
          DYNAMIC_ARRAY(buf, char, strlen(str) + 1);
          end_blocking_system_call();
          strzcpy21_a(buf, str);
          VALUES1(asciz_to_string(buf, GLO(misc_encoding)));
          FREE_DYNAMIC_ARRAY(buf);
          begin_blocking_system_call();
          GlobalUnlock(gltext);
        }
      }
#ifdef ENABLE_UNICODE
    }
#endif
    CloseClipboard();
  }
  end_blocking_system_call();
}

#endif  /* WIN32_NATIVE || UNIX_CYGWIN32 */

#if defined(HAVE_FFI)
/* STDIO inteface for postgresql et al */
DEFUN(POSIX::FOPEN, path mode) {
  STACK_0 = check_string(STACK_0);
  STACK_1 = check_string(STACK_1);
  with_string_0(STACK_1, GLO(pathname_encoding), pathz, {
      with_string_0(STACK_0, GLO(misc_encoding), modez, {
          FILE *fp;
          begin_blocking_system_call();
          fp = fopen(pathz,modez);
          end_blocking_system_call();
          if (fp) STACK_0 = allocate_fpointer((FOREIGN)fp);
          else OS_error();
        });
    });
  VALUES1(STACK_0); skipSTACK(2);
}
DEFUN(POSIX::FDOPEN, fd mode) {
  STACK_0 = check_string(STACK_0);
  STACK_1 = check_sint(STACK_1);
  with_string_0(STACK_0, GLO(misc_encoding), modez, {
      FILE *fp;
      begin_blocking_system_call();
      fp = fdopen(I_to_sint(STACK_1),modez);
      end_blocking_system_call();
      if (fp) STACK_0 = allocate_fpointer((FOREIGN)fp);
      else OS_error();
    });
  VALUES1(STACK_0); skipSTACK(2);
}
DEFUN(POSIX::FREOPEN, path mode file) {
  STACK_2 = check_string(STACK_2); /* path */
  STACK_1 = check_string(STACK_1); /* mode */
  STACK_0 = check_fpointer(STACK_0,1); /* file */
  with_string_0(STACK_2, GLO(pathname_encoding), pathz, {
      with_string_0(STACK_1, GLO(misc_encoding), modez, {
          FILE *fp;
          begin_blocking_system_call();
          fp = freopen(pathz,modez,(FILE*)TheFpointer(STACK_0)->fp_pointer);
          end_blocking_system_call();
          if (fp) TheFpointer(STACK_0)->fp_pointer = fp;
          else OS_error();
        });
    });
  VALUES0; skipSTACK(3);
}
#define FILE_FUNCTION(fun,finish)                                \
  int ret;                                                       \
  STACK_0 = check_fpointer(STACK_0,1);                           \
  begin_blocking_system_call();                                  \
  ret = fun((FILE*)TheFpointer(STACK_0)->fp_pointer);            \
  end_blocking_system_call();                                    \
  finish; skipSTACK(1)
DEFUN(POSIX::FILENO, fp)
{ FILE_FUNCTION(fileno,{ if(ret==-1)OS_error(); VALUES1(sint_to_I(ret)); }); }
DEFUN(POSIX::FEOF, fp) { FILE_FUNCTION(feof,VALUES_IF(ret)); }
DEFUN(POSIX::FERROR, fp) { FILE_FUNCTION(ferror,VALUES_IF(ret)); }
DEFUN(POSIX::FCLOSE, fp)
{ FILE_FUNCTION(fclose,{ if (ret == EOF) OS_error(); VALUES0; }); }
DEFUN(POSIX::FFLUSH, fp)
{ FILE_FUNCTION(fflush,{ if (ret == EOF) OS_error(); VALUES0; }); }
/* no fputs & fgets because they will mess with encodings &c */
DEFUN(POSIX::CLEARERR, fp) {
  STACK_0 = check_fpointer(STACK_0,1);
  begin_blocking_system_call();
  clearerr((FILE*)TheFpointer(STACK_0)->fp_pointer);
  end_blocking_system_call();
  VALUES0; skipSTACK(1);
}

/* --- testing only! not exported! --- */
/* fgetc returns -1 on EOF instead of signaling an error. or signal?! */
DEFUN(POSIX::%FGETC, fp) { FILE_FUNCTION(fgetc,VALUES1(sint_to_I(ret))); }
#define FILE_FUNCTION2(fun)                                             \
  int ret;                                                              \
  STACK_0 = check_fpointer(STACK_0,1);                                  \
  STACK_1 = check_sint(STACK_1);                                        \
  begin_blocking_system_call();                                         \
  ret = fun(I_to_sint(STACK_1),(FILE*)TheFpointer(STACK_0)->fp_pointer); \
  end_blocking_system_call();                                           \
  VALUES1(sint_to_I(ret)); skipSTACK(2)
DEFUN(POSIX::%FPUTC, c fp) { FILE_FUNCTION2(fputc); }
DEFUN(POSIX::%UNGETC, c fp) { FILE_FUNCTION2(ungetc); }

/* standard objects */
DEFVAR(my_stdin,allocate_fpointer(NULL))
DEFVAR(my_stdout,allocate_fpointer(NULL))
DEFVAR(my_stderr,allocate_fpointer(NULL))
static void init_stdio (void) {
  TheFpointer(O(my_stdin))->fp_pointer = stdin;
  mark_fp_valid(TheFpointer(O(my_stdin)));
  TheFpointer(O(my_stdout))->fp_pointer = stdout;
  mark_fp_valid(TheFpointer(O(my_stdout)));
  TheFpointer(O(my_stderr))->fp_pointer = stderr;
  mark_fp_valid(TheFpointer(O(my_stderr)));
}
DEFUN(POSIX::%STDIO, &optional which) {
 stdio_restart:
  if (missingp(STACK_0)) {
    init_stdio();
    VALUES0;
  } else {
    int which = I_to_sint(STACK_0 = check_sint(STACK_0));
    switch (which) {
      case 0: VALUES1(O(my_stdin)); break;
      case 1: VALUES1(O(my_stdout)); break;
      case 2: VALUES1(O(my_stderr)); break;
      default:
        pushSTACK(NIL);         /* no PLACE */
        pushSTACK(STACK_1);     /* TYPE-ERROR slot DATUM */
        pushSTACK(`(MEMBER 0 1 2)`); /* EXPECTED-TYPE */
        pushSTACK(STACK_0); pushSTACK(STACK_2);
        pushSTACK(TheSubr(subr_self)->name);
        check_value(type_error,GETTEXT("~S: ~S is not a ~S"));
        STACK_0 = value1;
        goto stdio_restart;
    }
  }
  skipSTACK(1);
}

#if (defined(HAVE_ERRNO_H) && defined(HAVE_STRERROR)) || defined(WIN32_NATIVE)
/* http://www.opengroup.org/onlinepubs/009695399/basedefs/errno.h.html */
#if defined(WIN32_NATIVE)
# include <winerror.h>
/* http://cygwin.com/cgi-bin/cvsweb.cgi/src/winsup/w32api/include/winerror.h */
/* http://msdn.microsoft.com/en-us/library/aa914935.aspx */
DEFCHECKER(check_errno,type=DWORD,reverse=uint32_to_I,     \
           ERROR_INVALID_FUNCTION ERROR_FILE_NOT_FOUND ERROR_PATH_NOT_FOUND \
           ERROR_TOO_MANY_OPEN_FILES ERROR_ACCESS_DENIED \
           ERROR_INVALID_HANDLE ERROR_ARENA_TRASHED ERROR_NOT_ENOUGH_MEMORY \
           ERROR_INVALID_BLOCK ERROR_BAD_ENVIRONMENT ERROR_BAD_FORMAT \
           ERROR_INVALID_ACCESS ERROR_INVALID_DATA ERROR_OUTOFMEMORY \
           ERROR_INVALID_DRIVE ERROR_CURRENT_DIRECTORY ERROR_NOT_SAME_DEVICE \
           ERROR_NO_MORE_FILES ERROR_WRITE_PROTECT ERROR_BAD_UNIT \
           ERROR_NOT_READY ERROR_BAD_COMMAND ERROR_CRC ERROR_BAD_LENGTH \
           ERROR_SEEK ERROR_NOT_DOS_DISK ERROR_SECTOR_NOT_FOUND \
           ERROR_OUT_OF_PAPER ERROR_WRITE_FAULT ERROR_READ_FAULT \
           ERROR_GEN_FAILURE ERROR_SHARING_VIOLATION ERROR_LOCK_VIOLATION \
           ERROR_WRONG_DISK ERROR_SHARING_BUFFER_EXCEEDED ERROR_HANDLE_EOF \
           ERROR_HANDLE_DISK_FULL ERROR_NOT_SUPPORTED ERROR_REM_NOT_LIST \
           ERROR_DUP_NAME ERROR_BAD_NETPATH ERROR_NETWORK_BUSY \
           ERROR_DEV_NOT_EXIST ERROR_TOO_MANY_CMDS ERROR_ADAP_HDW_ERR \
           ERROR_BAD_NET_RESP ERROR_UNEXP_NET_ERR ERROR_BAD_REM_ADAP \
           ERROR_PRINTQ_FULL ERROR_NO_SPOOL_SPACE ERROR_PRINT_CANCELLED \
           ERROR_NETNAME_DELETED ERROR_NETWORK_ACCESS_DENIED \
           ERROR_BAD_DEV_TYPE ERROR_BAD_NET_NAME ERROR_TOO_MANY_NAMES \
           ERROR_TOO_MANY_SESS ERROR_SHARING_PAUSED ERROR_REQ_NOT_ACCEP \
           ERROR_REDIR_PAUSED ERROR_FILE_EXISTS ERROR_CANNOT_MAKE \
           ERROR_FAIL_I24 ERROR_OUT_OF_STRUCTURES ERROR_ALREADY_ASSIGNED \
           ERROR_INVALID_PASSWORD ERROR_INVALID_PARAMETER \
           ERROR_NET_WRITE_FAULT ERROR_NO_PROC_SLOTS \
           ERROR_TOO_MANY_SEMAPHORES ERROR_EXCL_SEM_ALREADY_OWNED \
           ERROR_SEM_IS_SET ERROR_TOO_MANY_SEM_REQUESTS \
           ERROR_INVALID_AT_INTERRUPT_TIME ERROR_SEM_OWNER_DIED \
           ERROR_SEM_USER_LIMIT ERROR_DISK_CHANGE ERROR_DRIVE_LOCKED \
           ERROR_BROKEN_PIPE ERROR_OPEN_FAILED ERROR_BUFFER_OVERFLOW \
           ERROR_DISK_FULL ERROR_NO_MORE_SEARCH_HANDLES \
           ERROR_INVALID_TARGET_HANDLE ERROR_INVALID_CATEGORY \
           ERROR_INVALID_VERIFY_SWITCH ERROR_BAD_DRIVER_LEVEL \
           ERROR_CALL_NOT_IMPLEMENTED ERROR_SEM_TIMEOUT \
           ERROR_INSUFFICIENT_BUFFER ERROR_INVALID_NAME ERROR_INVALID_LEVEL \
           ERROR_NO_VOLUME_LABEL ERROR_MOD_NOT_FOUND ERROR_PROC_NOT_FOUND \
           ERROR_WAIT_NO_CHILDREN ERROR_CHILD_NOT_COMPLETE \
           ERROR_DIRECT_ACCESS_HANDLE ERROR_NEGATIVE_SEEK \
           ERROR_SEEK_ON_DEVICE ERROR_IS_JOIN_TARGET ERROR_IS_JOINED \
           ERROR_IS_SUBSTED ERROR_NOT_JOINED ERROR_NOT_SUBSTED \
           ERROR_JOIN_TO_JOIN ERROR_SUBST_TO_SUBST ERROR_JOIN_TO_SUBST \
           ERROR_SUBST_TO_JOIN ERROR_BUSY_DRIVE ERROR_SAME_DRIVE \
           ERROR_DIR_NOT_ROOT ERROR_DIR_NOT_EMPTY ERROR_IS_SUBST_PATH \
           ERROR_IS_JOIN_PATH ERROR_PATH_BUSY ERROR_IS_SUBST_TARGET \
           ERROR_SYSTEM_TRACE ERROR_INVALID_EVENT_COUNT \
           ERROR_TOO_MANY_MUXWAITERS ERROR_INVALID_LIST_FORMAT \
           ERROR_LABEL_TOO_LONG ERROR_TOO_MANY_TCBS ERROR_SIGNAL_REFUSED \
           ERROR_DISCARDED ERROR_NOT_LOCKED ERROR_BAD_THREADID_ADDR \
           ERROR_BAD_ARGUMENTS ERROR_BAD_PATHNAME ERROR_SIGNAL_PENDING \
           ERROR_MAX_THRDS_REACHED ERROR_LOCK_FAILED ERROR_BUSY \
           ERROR_CANCEL_VIOLATION ERROR_ATOMIC_LOCKS_NOT_SUPPORTED \
           ERROR_INVALID_SEGMENT_NUMBER ERROR_INVALID_ORDINAL \
           ERROR_ALREADY_EXISTS ERROR_INVALID_FLAG_NUMBER \
           ERROR_SEM_NOT_FOUND ERROR_INVALID_STARTING_CODESEG \
           ERROR_INVALID_STACKSEG ERROR_INVALID_MODULETYPE \
           ERROR_INVALID_EXE_SIGNATURE ERROR_EXE_MARKED_INVALID \
           ERROR_BAD_EXE_FORMAT ERROR_ITERATED_DATA_EXCEEDS_64k \
           ERROR_INVALID_MINALLOCSIZE ERROR_DYNLINK_FROM_INVALID_RING \
           ERROR_IOPL_NOT_ENABLED ERROR_INVALID_SEGDPL \
           ERROR_AUTODATASEG_EXCEEDS_64k ERROR_RING2SEG_MUST_BE_MOVABLE \
           ERROR_RELOC_CHAIN_XEEDS_SEGLIM ERROR_INFLOOP_IN_RELOC_CHAIN \
           ERROR_ENVVAR_NOT_FOUND ERROR_NO_SIGNAL_SENT \
           ERROR_FILENAME_EXCED_RANGE ERROR_RING2_STACK_IN_USE \
           ERROR_META_EXPANSION_TOO_LONG ERROR_INVALID_SIGNAL_NUMBER \
           ERROR_THREAD_1_INACTIVE ERROR_LOCKED ERROR_TOO_MANY_MODULES \
           ERROR_NESTING_NOT_ALLOWED ERROR_EXE_MACHINE_TYPE_MISMATCH \
           ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY \
           ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY ERROR_BAD_PIPE \
           ERROR_PIPE_BUSY ERROR_NO_DATA ERROR_PIPE_NOT_CONNECTED \
           ERROR_MORE_DATA ERROR_VC_DISCONNECTED ERROR_INVALID_EA_NAME \
           ERROR_EA_LIST_INCONSISTENT WAIT_TIMEOUT ERROR_NO_MORE_ITEMS \
           ERROR_CANNOT_COPY ERROR_DIRECTORY ERROR_EAS_DIDNT_FIT \
           ERROR_EA_FILE_CORRUPT ERROR_EA_TABLE_FULL ERROR_INVALID_EA_HANDLE \
           ERROR_EAS_NOT_SUPPORTED ERROR_NOT_OWNER ERROR_TOO_MANY_POSTS \
           ERROR_PARTIAL_COPY ERROR_OPLOCK_NOT_GRANTED \
           ERROR_INVALID_OPLOCK_PROTOCOL ERROR_DISK_TOO_FRAGMENTED \
           ERROR_DELETE_PENDING ERROR_MR_MID_NOT_FOUND ERROR_SCOPE_NOT_FOUND \
           ERROR_INVALID_ADDRESS ERROR_ARITHMETIC_OVERFLOW \
           ERROR_PIPE_CONNECTED ERROR_PIPE_LISTENING ERROR_EA_ACCESS_DENIED \
           ERROR_OPERATION_ABORTED ERROR_IO_INCOMPLETE ERROR_IO_PENDING \
           ERROR_NOACCESS ERROR_SWAPERROR ERROR_STACK_OVERFLOW \
           ERROR_INVALID_MESSAGE ERROR_CAN_NOT_COMPLETE \
           ERROR_INVALID_FLAGS ERROR_UNRECOGNIZED_VOLUME \
           ERROR_FILE_INVALID ERROR_FULLSCREEN_MODE ERROR_NO_TOKEN \
           ERROR_BADDB ERROR_BADKEY ERROR_CANTOPEN ERROR_CANTREAD \
           ERROR_CANTWRITE ERROR_REGISTRY_RECOVERED ERROR_REGISTRY_CORRUPT \
           ERROR_REGISTRY_IO_FAILED ERROR_NOT_REGISTRY_FILE \
           ERROR_KEY_DELETED ERROR_NO_LOG_SPACE ERROR_KEY_HAS_CHILDREN \
           ERROR_CHILD_MUST_BE_VOLATILE ERROR_NOTIFY_ENUM_DIR \
           ERROR_DEPENDENT_SERVICES_RUNNING ERROR_INVALID_SERVICE_CONTROL \
           ERROR_SERVICE_REQUEST_TIMEOUT ERROR_SERVICE_NO_THREAD \
           ERROR_SERVICE_DATABASE_LOCKED ERROR_SERVICE_ALREADY_RUNNING \
           ERROR_INVALID_SERVICE_ACCOUNT ERROR_SERVICE_DISABLED \
           ERROR_CIRCULAR_DEPENDENCY ERROR_SERVICE_DOES_NOT_EXIST \
           ERROR_SERVICE_CANNOT_ACCEPT_CTRL ERROR_SERVICE_NOT_ACTIVE \
           ERROR_FAILED_SERVICE_CONTROLLER_CONNECT \
           ERROR_EXCEPTION_IN_SERVICE ERROR_DATABASE_DOES_NOT_EXIST \
           ERROR_SERVICE_SPECIFIC_ERROR ERROR_PROCESS_ABORTED \
           ERROR_SERVICE_DEPENDENCY_FAIL ERROR_SERVICE_LOGON_FAILED \
           ERROR_SERVICE_START_HANG ERROR_INVALID_SERVICE_LOCK \
           ERROR_SERVICE_MARKED_FOR_DELETE ERROR_SERVICE_EXISTS \
           ERROR_ALREADY_RUNNING_LKG ERROR_SERVICE_DEPENDENCY_DELETED \
           ERROR_BOOT_ALREADY_ACCEPTED ERROR_SERVICE_NEVER_STARTED \
           ERROR_DUPLICATE_SERVICE_NAME ERROR_DIFFERENT_SERVICE_ACCOUNT \
           ERROR_CANNOT_DETECT_DRIVER_FAILURE \
           ERROR_CANNOT_DETECT_PROCESS_ABORT \
           ERROR_NO_RECOVERY_PROGRAM ERROR_SERVICE_NOT_IN_EXE \
           ERROR_NOT_SAFEBOOT_SERVICE ERROR_END_OF_MEDIA \
           ERROR_FILEMARK_DETECTED ERROR_BEGINNING_OF_MEDIA \
           ERROR_SETMARK_DETECTED ERROR_NO_DATA_DETECTED \
           ERROR_PARTITION_FAILURE ERROR_INVALID_BLOCK_LENGTH \
           ERROR_DEVICE_NOT_PARTITIONED ERROR_UNABLE_TO_LOCK_MEDIA \
           ERROR_UNABLE_TO_UNLOAD_MEDIA ERROR_MEDIA_CHANGED ERROR_BUS_RESET \
           ERROR_NO_MEDIA_IN_DRIVE ERROR_NO_UNICODE_TRANSLATION \
           ERROR_DLL_INIT_FAILED ERROR_SHUTDOWN_IN_PROGRESS \
           ERROR_NO_SHUTDOWN_IN_PROGRESS ERROR_IO_DEVICE \
           ERROR_SERIAL_NO_DEVICE ERROR_IRQ_BUSY ERROR_MORE_WRITES \
           ERROR_COUNTER_TIMEOUT ERROR_FLOPPY_ID_MARK_NOT_FOUND \
           ERROR_FLOPPY_WRONG_CYLINDER ERROR_FLOPPY_UNKNOWN_ERROR \
           ERROR_FLOPPY_BAD_REGISTERS ERROR_DISK_RECALIBRATE_FAILED \
           ERROR_DISK_OPERATION_FAILED ERROR_DISK_RESET_FAILED \
           ERROR_EOM_OVERFLOW ERROR_NOT_ENOUGH_SERVER_MEMORY \
           ERROR_POSSIBLE_DEADLOCK ERROR_MAPPED_ALIGNMENT \
           ERROR_SET_POWER_STATE_VETOED ERROR_SET_POWER_STATE_FAILED \
           ERROR_TOO_MANY_LINKS ERROR_OLD_WIN_VERSION \
           ERROR_APP_WRONG_OS ERROR_SINGLE_INSTANCE_APP ERROR_RMODE_APP \
           ERROR_INVALID_DLL ERROR_NO_ASSOCIATION ERROR_DDE_FAIL \
           ERROR_DLL_NOT_FOUND ERROR_NO_MORE_USER_HANDLES \
           ERROR_MESSAGE_SYNC_ONLY ERROR_SOURCE_ELEMENT_EMPTY \
           ERROR_DESTINATION_ELEMENT_FULL ERROR_ILLEGAL_ELEMENT_ADDRESS \
           ERROR_MAGAZINE_NOT_PRESENT ERROR_DEVICE_REINITIALIZATION_NEEDED \
           ERROR_DEVICE_REQUIRES_CLEANING ERROR_DEVICE_DOOR_OPEN \
           ERROR_DEVICE_NOT_CONNECTED ERROR_NOT_FOUND ERROR_NO_MATCH \
           ERROR_SET_NOT_FOUND ERROR_POINT_NOT_FOUND \
           ERROR_NO_TRACKING_SERVICE ERROR_NO_VOLUME_ID \
           ERROR_UNABLE_TO_REMOVE_REPLACED ERROR_UNABLE_TO_MOVE_REPLACEMENT \
           ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 \
           ERROR_JOURNAL_DELETE_IN_PROGRESS ERROR_JOURNAL_NOT_ACTIVE \
           ERROR_POTENTIAL_FILE_FOUND ERROR_JOURNAL_ENTRY_DELETED \
           ERROR_BAD_DEVICE ERROR_CONNECTION_UNAVAIL \
           ERROR_DEVICE_ALREADY_REMEMBERED ERROR_NO_NET_OR_BAD_PATH \
           ERROR_BAD_PROVIDER ERROR_CANNOT_OPEN_PROFILE ERROR_BAD_PROFILE \
           ERROR_NOT_CONTAINER ERROR_EXTENDED_ERROR ERROR_INVALID_GROUPNAME \
           ERROR_INVALID_COMPUTERNAME ERROR_INVALID_EVENTNAME \
           ERROR_INVALID_DOMAINNAME ERROR_INVALID_SERVICENAME \
           ERROR_INVALID_NETNAME ERROR_INVALID_SHARENAME \
           ERROR_INVALID_PASSWORDNAME ERROR_INVALID_MESSAGENAME \
           ERROR_INVALID_MESSAGEDEST ERROR_SESSION_CREDENTIAL_CONFLICT \
           ERROR_REMOTE_SESSION_LIMIT_EXCEEDED ERROR_DUP_DOMAINNAME \
           ERROR_NO_NETWORK ERROR_CANCELLED ERROR_USER_MAPPED_FILE \
           ERROR_CONNECTION_REFUSED ERROR_GRACEFUL_DISCONNECT \
           ERROR_ADDRESS_ALREADY_ASSOCIATED ERROR_ADDRESS_NOT_ASSOCIATED \
           ERROR_CONNECTION_INVALID ERROR_CONNECTION_ACTIVE \
           ERROR_NETWORK_UNREACHABLE ERROR_HOST_UNREACHABLE \
           ERROR_PROTOCOL_UNREACHABLE ERROR_PORT_UNREACHABLE \
           ERROR_REQUEST_ABORTED ERROR_CONNECTION_ABORTED ERROR_RETRY \
           ERROR_CONNECTION_COUNT_LIMIT ERROR_LOGIN_TIME_RESTRICTION \
           ERROR_LOGIN_WKSTA_RESTRICTION ERROR_INCORRECT_ADDRESS \
           ERROR_ALREADY_REGISTERED ERROR_SERVICE_NOT_FOUND \
           ERROR_NOT_AUTHENTICATED ERROR_NOT_LOGGED_ON ERROR_CONTINUE \
           ERROR_ALREADY_INITIALIZED ERROR_NO_MORE_DEVICES \
           ERROR_NO_SUCH_SITE ERROR_DOMAIN_CONTROLLER_EXISTS \
           ERROR_ONLY_IF_CONNECTED ERROR_OVERRIDE_NOCHANGES \
           ERROR_BAD_USER_PROFILE ERROR_NOT_SUPPORTED_ON_SBS \
           ERROR_SERVER_SHUTDOWN_IN_PROGRESS ERROR_HOST_DOWN \
           ERROR_NON_ACCOUNT_SID ERROR_NON_DOMAIN_SID \
           ERROR_APPHELP_BLOCK ERROR_ACCESS_DISABLED_BY_POLICY \
           ERROR_REG_NAT_CONSUMPTION ERROR_CSCSHARE_OFFLINE \
           ERROR_PKINIT_FAILURE ERROR_SMARTCARD_SUBSYSTEM_FAILURE \
           ERROR_DOWNGRADE_DETECTED SEC_E_SMARTCARD_CERT_REVOKED \
           SEC_E_ISSUING_CA_UNTRUSTED SEC_E_REVOCATION_OFFLINE_C \
           SEC_E_PKINIT_CLIENT_FAILUR SEC_E_SMARTCARD_CERT_EXPIRED \
           ERROR_MACHINE_LOCKED ERROR_CALLBACK_SUPPLIED_INVALID_DATA \
           ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED ERROR_DRIVER_BLOCKED \
           ERROR_INVALID_IMPORT_OF_NON_DLL ERROR_ACCESS_DISABLED_WEBBLADE \
           ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER ERROR_RECOVERY_FAILURE \
           ERROR_ALREADY_FIBER ERROR_ALREADY_THREAD \
           ERROR_STACK_BUFFER_OVERRUN ERROR_PARAMETER_QUOTA_EXCEEDED \
           ERROR_DEBUGGER_INACTIVE ERROR_NOT_ALL_ASSIGNED \
           ERROR_SOME_NOT_MAPPED ERROR_NO_QUOTAS_FOR_ACCOUNT \
           ERROR_LOCAL_USER_SESSION_KEY ERROR_NULL_LM_PASSWORD \
           ERROR_UNKNOWN_REVISION ERROR_REVISION_MISMATCH \
           ERROR_INVALID_OWNER ERROR_INVALID_PRIMARY_GROUP \
           ERROR_NO_IMPERSONATION_TOKEN ERROR_CANT_DISABLE_MANDATORY \
           ERROR_NO_LOGON_SERVERS ERROR_NO_SUCH_LOGON_SESSION \
           ERROR_NO_SUCH_PRIVILEGE ERROR_PRIVILEGE_NOT_HELD \
           ERROR_INVALID_ACCOUNT_NAME ERROR_USER_EXISTS ERROR_NO_SUCH_USER \
           ERROR_GROUP_EXISTS ERROR_NO_SUCH_GROUP ERROR_MEMBER_IN_GROUP \
           ERROR_MEMBER_NOT_IN_GROUP ERROR_LAST_ADMIN ERROR_WRONG_PASSWORD \
           ERROR_ILL_FORMED_PASSWORD ERROR_PASSWORD_RESTRICTION \
           ERROR_LOGON_FAILURE ERROR_ACCOUNT_RESTRICTION \
           ERROR_INVALID_LOGON_HOURS ERROR_INVALID_WORKSTATION \
           ERROR_PASSWORD_EXPIRED ERROR_ACCOUNT_DISABLED ERROR_NONE_MAPPED \
           ERROR_TOO_MANY_LUIDS_REQUESTED ERROR_LUIDS_EXHAUSTED \
           ERROR_INVALID_SUB_AUTHORITY ERROR_INVALID_ACL ERROR_INVALID_SID \
           ERROR_INVALID_SECURITY_DESCR ERROR_BAD_INHERITANCE_ACL \
           ERROR_SERVER_DISABLED ERROR_SERVER_NOT_DISABLED \
           ERROR_INVALID_ID_AUTHORITY ERROR_ALLOTTED_SPACE_EXCEEDED \
           ERROR_INVALID_GROUP_ATTRIBUTES ERROR_BAD_IMPERSONATION_LEVEL \
           ERROR_CANT_OPEN_ANONYMOUS ERROR_BAD_VALIDATION_CLASS \
           ERROR_BAD_TOKEN_TYPE ERROR_NO_SECURITY_ON_OBJECT \
           ERROR_CANT_ACCESS_DOMAIN_INFO ERROR_INVALID_SERVER_STATE \
           ERROR_INVALID_DOMAIN_STATE ERROR_INVALID_DOMAIN_ROLE \
           ERROR_NO_SUCH_DOMAIN ERROR_DOMAIN_EXISTS \
           ERROR_DOMAIN_LIMIT_EXCEEDED ERROR_INTERNAL_DB_CORRUPTION \
           ERROR_INTERNAL_ERROR ERROR_GENERIC_NOT_MAPPED \
           ERROR_BAD_DESCRIPTOR_FORMAT ERROR_NOT_LOGON_PROCESS \
           ERROR_LOGON_SESSION_EXISTS ERROR_NO_SUCH_PACKAGE \
           ERROR_BAD_LOGON_SESSION_STATE ERROR_LOGON_SESSION_COLLISION \
           ERROR_INVALID_LOGON_TYPE ERROR_CANNOT_IMPERSONATE \
           ERROR_RXACT_INVALID_STATE ERROR_RXACT_COMMIT_FAILURE \
           ERROR_SPECIAL_ACCOUNT ERROR_SPECIAL_GROUP ERROR_SPECIAL_USER \
           ERROR_MEMBERS_PRIMARY_GROUP ERROR_TOKEN_ALREADY_IN_USE \
           ERROR_NO_SUCH_ALIAS ERROR_MEMBER_NOT_IN_ALIAS \
           ERROR_MEMBER_IN_ALIAS ERROR_ALIAS_EXISTS ERROR_LOGON_NOT_GRANTED \
           ERROR_TOO_MANY_SECRETS ERROR_SECRET_TOO_LONG \
           ERROR_INTERNAL_DB_ERROR ERROR_TOO_MANY_CONTEXT_IDS \
           ERROR_LOGON_TYPE_NOT_GRANTED ERROR_NT_CROSS_ENCRYPTION_REQUIRED \
           ERROR_NO_SUCH_MEMBER ERROR_INVALID_MEMBER \
           ERROR_TOO_MANY_SIDS ERROR_LM_CROSS_ENCRYPTION_REQUIRED \
           ERROR_NO_INHERITANCE ERROR_FILE_CORRUPT ERROR_DISK_CORRUPT \
           ERROR_NO_USER_SESSION_KEY ERROR_LICENSE_QUOTA_EXCEEDED \
           ERROR_WRONG_TARGET_NAME ERROR_MUTUAL_AUTH_FAILED ERROR_TIME_SKEW \
           ERROR_CURRENT_DOMAIN_NOT_ALLOWED ERROR_INVALID_WINDOW_HANDLE \
           ERROR_INVALID_MENU_HANDLE ERROR_INVALID_CURSOR_HANDLE \
           ERROR_INVALID_ACCEL_HANDLE ERROR_INVALID_HOOK_HANDLE \
           ERROR_INVALID_DWP_HANDLE ERROR_TLW_WITH_WSCHILD \
           ERROR_CANNOT_FIND_WND_CLASS ERROR_WINDOW_OF_OTHER_THREAD \
           ERROR_HOTKEY_ALREADY_REGISTERED ERROR_CLASS_ALREADY_EXISTS \
           ERROR_CLASS_DOES_NOT_EXIST ERROR_CLASS_HAS_WINDOWS \
           ERROR_INVALID_INDEX ERROR_INVALID_ICON_HANDLE \
           ERROR_PRIVATE_DIALOG_INDEX ERROR_LISTBOX_ID_NOT_FOUND \
           ERROR_NO_WILDCARD_CHARACTERS ERROR_CLIPBOARD_NOT_OPEN \
           ERROR_HOTKEY_NOT_REGISTERED ERROR_WINDOW_NOT_DIALOG \
           ERROR_CONTROL_ID_NOT_FOUND ERROR_INVALID_COMBOBOX_MESSAGE \
           ERROR_WINDOW_NOT_COMBOBOX ERROR_INVALID_EDIT_HEIGHT \
           ERROR_DC_NOT_FOUND ERROR_INVALID_HOOK_FILTER \
           ERROR_INVALID_FILTER_PROC ERROR_HOOK_NEEDS_HMOD \
           ERROR_GLOBAL_ONLY_HOOK ERROR_JOURNAL_HOOK_SET \
           ERROR_HOOK_NOT_INSTALLED ERROR_INVALID_LB_MESSAGE \
           ERROR_SETCOUNT_ON_BAD_LB ERROR_LB_WITHOUT_TABSTOPS \
           ERROR_DESTROY_OBJECT_OF_OTHER_THREAD ERROR_CHILD_WINDOW_MENU \
           ERROR_NO_SYSTEM_MENU ERROR_INVALID_MSGBOX_STYLE \
           ERROR_INVALID_SPI_VALUE ERROR_SCREEN_ALREADY_LOCKED \
           ERROR_HWNDS_HAVE_DIFF_PARENT ERROR_NOT_CHILD_WINDOW \
           ERROR_INVALID_GW_COMMAND ERROR_INVALID_THREAD_ID \
           ERROR_NON_MDICHILD_WINDOW ERROR_POPUP_ALREADY_ACTIVE \
           ERROR_NO_SCROLLBARS ERROR_INVALID_SCROLLBAR_RANGE \
           ERROR_INVALID_SHOWWIN_COMMAND ERROR_NO_SYSTEM_RESOURCES \
           ERROR_NONPAGED_SYSTEM_RESOURCES ERROR_PAGED_SYSTEM_RESOURCES \
           ERROR_WORKING_SET_QUOTA ERROR_PAGEFILE_QUOTA \
           ERROR_COMMITMENT_LIMIT ERROR_MENU_ITEM_NOT_FOUND \
           ERROR_INVALID_KEYBOARD_HANDLE ERROR_HOOK_TYPE_NOT_ALLOWED \
           ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION ERROR_TIMEOUT \
           ERROR_INVALID_MONITOR_HANDLE ERROR_EVENTLOG_FILE_CORRUPT \
           ERROR_EVENTLOG_CANT_START ERROR_LOG_FILE_FULL \
           ERROR_EVENTLOG_FILE_CHANGED ERROR_INSTALL_SERVICE_FAILURE \
           ERROR_INSTALL_USEREXIT ERROR_INSTALL_FAILURE \
           ERROR_INSTALL_SUSPEND ERROR_UNKNOWN_PRODUCT ERROR_UNKNOWN_FEATURE \
           ERROR_UNKNOWN_COMPONENT ERROR_UNKNOWN_PROPERTY \
           ERROR_INVALID_HANDLE_STATE ERROR_BAD_CONFIGURATION \
           ERROR_INDEX_ABSENT ERROR_INSTALL_SOURCE_ABSENT \
           ERROR_INSTALL_PACKAGE_VERSION ERROR_PRODUCT_UNINSTALLED \
           ERROR_BAD_QUERY_SYNTAX ERROR_INVALID_FIELD ERROR_DEVICE_REMOVED \
           ERROR_INSTALL_ALREADY_RUNNING ERROR_INSTALL_PACKAGE_OPEN_FAILED \
           ERROR_INSTALL_PACKAGE_INVALID ERROR_INSTALL_UI_FAILURE \
           ERROR_INSTALL_LOG_FAILURE ERROR_INSTALL_LANGUAGE_UNSUPPORTED \
           ERROR_INSTALL_TRANSFORM_FAILURE ERROR_INSTALL_PACKAGE_REJECTED \
           ERROR_FUNCTION_NOT_CALLED ERROR_FUNCTION_FAILED \
           ERROR_INVALID_TABLE ERROR_DATATYPE_MISMATCH \
           ERROR_UNSUPPORTED_TYPE ERROR_CREATE_FAILED \
           ERROR_INSTALL_TEMP_UNWRITABLE ERROR_INSTALL_PLATFORM_UNSUPPORTED \
           ERROR_INSTALL_NOTUSED ERROR_PATCH_PACKAGE_OPEN_FAILED \
           ERROR_PATCH_PACKAGE_INVALID ERROR_PATCH_PACKAGE_UNSUPPORTED \
           ERROR_PRODUCT_VERSION ERROR_INVALID_COMMAND_LINE \
           ERROR_INSTALL_REMOTE_DISALLOWED ERROR_SUCCESS_REBOOT_INITIATED \
           ERROR_PATCH_TARGET_NOT_FOUND ERROR_PATCH_PACKAGE_REJECTED \
           ERROR_INSTALL_TRANSFORM_REJECTED ERROR_INSTALL_REMOTE_PROHIBITED \
           RPC_S_INVALID_STRING_BINDING RPC_S_WRONG_KIND_OF_BINDING \
           RPC_S_INVALID_BINDING RPC_S_PROTSEQ_NOT_SUPPORTED \
           RPC_S_INVALID_RPC_PROTSEQ RPC_S_INVALID_STRING_UUID \
           RPC_S_INVALID_ENDPOINT_FORMAT RPC_S_INVALID_NET_ADDR \
           RPC_S_NO_ENDPOINT_FOUND RPC_S_INVALID_TIMEOUT \
           RPC_S_OBJECT_NOT_FOUND RPC_S_ALREADY_REGISTERED \
           RPC_S_TYPE_ALREADY_REGISTERED RPC_S_ALREADY_LISTENING \
           RPC_S_NO_PROTSEQS_REGISTERED RPC_S_NOT_LISTENING \
           RPC_S_UNKNOWN_MGR_TYPE RPC_S_UNKNOWN_IF RPC_S_NO_BINDINGS \
           RPC_S_NO_PROTSEQS RPC_S_CANT_CREATE_ENDPOINT \
           RPC_S_OUT_OF_RESOURCES RPC_S_SERVER_UNAVAILABLE \
           RPC_S_SERVER_TOO_BUSY RPC_S_INVALID_NETWORK_OPTIONS \
           RPC_S_NO_CALL_ACTIVE RPC_S_CALL_FAILED RPC_S_CALL_FAILED_DNE \
           RPC_S_PROTOCOL_ERROR RPC_S_UNSUPPORTED_TRANS_SYN \
           RPC_S_UNSUPPORTED_TYPE RPC_S_INVALID_TAG RPC_S_INVALID_BOUND \
           RPC_S_NO_ENTRY_NAME RPC_S_INVALID_NAME_SYNTAX \
           RPC_S_UNSUPPORTED_NAME_SYNTAX RPC_S_UUID_NO_ADDRESS \
           RPC_S_DUPLICATE_ENDPOINT RPC_S_UNKNOWN_AUTHN_TYPE \
           RPC_S_MAX_CALLS_TOO_SMALL RPC_S_STRING_TOO_LONG \
           RPC_S_PROTSEQ_NOT_FOUND RPC_S_PROCNUM_OUT_OF_RANGE \
           RPC_S_BINDING_HAS_NO_AUTH RPC_S_UNKNOWN_AUTHN_SERVICE \
           RPC_S_UNKNOWN_AUTHN_LEVEL RPC_S_INVALID_AUTH_IDENTITY \
           RPC_S_UNKNOWN_AUTHZ_SERVICE EPT_S_INVALID_ENTRY \
           EPT_S_CANT_PERFORM_OP EPT_S_NOT_REGISTERED \
           RPC_S_NOTHING_TO_EXPORT RPC_S_INCOMPLETE_NAME \
           RPC_S_INVALID_VERS_OPTION RPC_S_NO_MORE_MEMBERS \
           RPC_S_NOT_ALL_OBJS_UNEXPORTED RPC_S_INTERFACE_NOT_FOUND \
           RPC_S_ENTRY_ALREADY_EXISTS RPC_S_ENTRY_NOT_FOUND \
           RPC_S_NAME_SERVICE_UNAVAILABLE RPC_S_INVALID_NAF_ID \
           RPC_S_CANNOT_SUPPORT RPC_S_NO_CONTEXT_AVAILABLE \
           RPC_S_INTERNAL_ERROR RPC_S_ZERO_DIVIDE RPC_S_ADDRESS_ERROR \
           RPC_S_FP_DIV_ZERO RPC_S_FP_UNDERFLOW RPC_S_FP_OVERFLOW \
           RPC_X_NO_MORE_ENTRIES RPC_X_SS_CHAR_TRANS_OPEN_FAIL \
           RPC_X_SS_CHAR_TRANS_SHORT_FILE RPC_X_SS_IN_NULL_CONTEXT \
           RPC_X_SS_CONTEXT_DAMAGED RPC_X_SS_HANDLES_MISMATCH \
           RPC_X_SS_CANNOT_GET_CALL_HANDLE RPC_X_NULL_REF_POINTER \
           RPC_X_ENUM_VALUE_OUT_OF_RANGE RPC_X_BYTE_COUNT_TOO_SMALL \
           RPC_X_BAD_STUB_DATA ERROR_INVALID_USER_BUFFER \
           ERROR_UNRECOGNIZED_MEDIA ERROR_NO_TRUST_LSA_SECRET \
           ERROR_NO_TRUST_SAM_ACCOUNT ERROR_TRUSTED_DOMAIN_FAILURE \
           ERROR_TRUSTED_RELATIONSHIP_FAILURE ERROR_TRUST_FAILURE \
           RPC_S_CALL_IN_PROGRESS ERROR_NETLOGON_NOT_STARTED \
           ERROR_ACCOUNT_EXPIRED ERROR_REDIRECTOR_HAS_OPEN_HANDLES \
           ERROR_PRINTER_DRIVER_ALREADY_INSTALLED ERROR_UNKNOWN_PORT \
           ERROR_UNKNOWN_PRINTER_DRIVER ERROR_UNKNOWN_PRINTPROCESSOR \
           ERROR_INVALID_SEPARATOR_FILE ERROR_INVALID_PRIORITY \
           ERROR_INVALID_PRINTER_NAME ERROR_PRINTER_ALREADY_EXISTS \
           ERROR_INVALID_PRINTER_COMMAND ERROR_INVALID_DATATYPE \
           ERROR_INVALID_ENVIRONMENT RPC_S_NO_MORE_BINDINGS \
           ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT \
           ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT \
           ERROR_NOLOGON_SERVER_TRUST_ACCOUNT \
           ERROR_DOMAIN_TRUST_INCONSISTENT ERROR_SERVER_HAS_OPEN_HANDLES \
           ERROR_RESOURCE_DATA_NOT_FOUND ERROR_RESOURCE_TYPE_NOT_FOUND \
           ERROR_RESOURCE_NAME_NOT_FOUND ERROR_RESOURCE_LANG_NOT_FOUND \
           ERROR_NOT_ENOUGH_QUOTA RPC_S_NO_INTERFACES \
           RPC_S_CALL_CANCELLED RPC_S_BINDING_INCOMPLETE \
           RPC_S_COMM_FAILURE RPC_S_UNSUPPORTED_AUTHN_LEVEL \
           RPC_S_NO_PRINC_NAME RPC_S_NOT_RPC_ERROR RPC_S_UUID_LOCAL_ONLY \
           RPC_S_SEC_PKG_ERROR RPC_S_NOT_CANCELLED RPC_X_INVALID_ES_ACTION \
           RPC_X_WRONG_ES_VERSION RPC_X_WRONG_STUB_VERSION \
           RPC_X_INVALID_PIPE_OBJECT RPC_X_WRONG_PIPE_ORDER \
           RPC_X_WRONG_PIPE_VERSION RPC_S_GROUP_MEMBER_NOT_FOUND \
           EPT_S_CANT_CREATE RPC_S_INVALID_OBJECT ERROR_INVALID_TIME \
           ERROR_INVALID_FORM_NAME ERROR_INVALID_FORM_SIZE \
           ERROR_ALREADY_WAITING ERROR_PRINTER_DELETED \
           ERROR_INVALID_PRINTER_STATE ERROR_PASSWORD_MUST_CHANGE \
           ERROR_DOMAIN_CONTROLLER_NOT_FOUND ERROR_ACCOUNT_LOCKED_OUT \
           OR_INVALID_OXID OR_INVALID_OID OR_INVALID_SET \
           RPC_S_SEND_INCOMPLETE RPC_S_INVALID_ASYNC_HANDLE \
           RPC_S_INVALID_ASYNC_CALL RPC_X_PIPE_CLOSED \
           RPC_X_PIPE_DISCIPLINE_ERROR RPC_X_PIPE_EMPTY ERROR_NO_SITENAME \
           ERROR_CANT_ACCESS_FILE ERROR_CANT_RESOLVE_FILENAME \
           RPC_S_ENTRY_TYPE_MISMATCH RPC_S_NOT_ALL_OBJS_EXPORTED \
           RPC_S_INTERFACE_NOT_EXPORTED RPC_S_PROFILE_NOT_ADDED \
           RPC_S_PRF_ELT_NOT_ADDED RPC_S_PRF_ELT_NOT_REMOVED \
           RPC_S_GRP_ELT_NOT_ADDED RPC_S_GRP_ELT_NOT_REMOVED \
           ERROR_KM_DRIVER_BLOCKED ERROR_CONTEXT_EXPIRED \
           ERROR_PER_USER_TRUST_QUOTA_EXCEEDED \
           ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED \
           ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED ERROR_INVALID_PIXEL_FORMAT \
           ERROR_BAD_DRIVER ERROR_INVALID_WINDOW_STYLE \
           ERROR_METAFILE_NOT_SUPPORTED ERROR_TRANSFORM_NOT_SUPPORTED \
           ERROR_CLIPPING_NOT_SUPPORTED ERROR_INVALID_CMM \
           ERROR_INVALID_PROFILE ERROR_TAG_NOT_FOUND ERROR_TAG_NOT_PRESENT \
           ERROR_DUPLICATE_TAG ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE \
           ERROR_PROFILE_NOT_FOUND ERROR_INVALID_COLORSPACE \
           ERROR_ICM_NOT_ENABLED ERROR_DELETING_ICM_XFORM \
           ERROR_INVALID_TRANSFORM ERROR_COLORSPACE_MISMATCH \
           ERROR_INVALID_COLORINDEX ERROR_CONNECTED_OTHER_PASSWORD \
           ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT \
           ERROR_BAD_USERNAME ERROR_NOT_CONNECTED ERROR_OPEN_FILES \
           ERROR_ACTIVE_CONNECTIONS ERROR_DEVICE_IN_USE \
           ERROR_UNKNOWN_PRINT_MONITOR ERROR_PRINTER_DRIVER_IN_USE \
           ERROR_SPOOL_FILE_NOT_FOUND ERROR_SPL_NO_STARTDOC \
           ERROR_SPL_NO_ADDJOB ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED \
           ERROR_PRINT_MONITOR_ALREADY_INSTALLED ERROR_INVALID_PRINT_MONITOR \
           ERROR_PRINT_MONITOR_IN_USE ERROR_PRINTER_HAS_JOBS_QUEUED \
           ERROR_SUCCESS_REBOOT_REQUIRED ERROR_SUCCESS_RESTART_REQUIRED \
           ERROR_PRINTER_NOT_FOUND ERROR_PRINTER_DRIVER_WARNED \
           ERROR_PRINTER_DRIVER_BLOCKED ERROR_WINS_INTERNAL \
           ERROR_CAN_NOT_DEL_LOCAL_WINS ERROR_STATIC_INIT \
           ERROR_INC_BACKUP ERROR_FULL_BACKUP ERROR_REC_NON_EXISTENT \
           ERROR_RPL_NOT_ALLOWED ERROR_DHCP_ADDRESS_CONFLICT \
           ERROR_WMI_GUID_NOT_FOUND ERROR_WMI_INSTANCE_NOT_FOUND \
           ERROR_WMI_ITEMID_NOT_FOUND ERROR_WMI_TRY_AGAIN \
           ERROR_WMI_DP_NOT_FOUND ERROR_WMI_UNRESOLVED_INSTANCE_REF \
           ERROR_WMI_ALREADY_ENABLED ERROR_WMI_GUID_DISCONNECTED \
           ERROR_WMI_SERVER_UNAVAILABLE ERROR_WMI_DP_FAILED \
           ERROR_WMI_INVALID_MOF ERROR_WMI_INVALID_REGINFO \
           ERROR_WMI_ALREADY_DISABLED ERROR_WMI_READ_ONLY \
           ERROR_WMI_SET_FAILURE ERROR_INVALID_MEDIA ERROR_INVALID_LIBRARY \
           ERROR_INVALID_MEDIA_POOL ERROR_DRIVE_MEDIA_MISMATCH \
           ERROR_MEDIA_OFFLINE ERROR_LIBRARY_OFFLINE ERROR_EMPTY \
           ERROR_NOT_EMPTY ERROR_MEDIA_UNAVAILABLE ERROR_RESOURCE_DISABLED \
           ERROR_INVALID_CLEANER ERROR_UNABLE_TO_CLEAN \
           ERROR_OBJECT_NOT_FOUND ERROR_DATABASE_FAILURE ERROR_DATABASE_FULL \
           ERROR_MEDIA_INCOMPATIBLE ERROR_RESOURCE_NOT_PRESENT \
           ERROR_INVALID_OPERATION ERROR_MEDIA_NOT_AVAILABLE \
           ERROR_DEVICE_NOT_AVAILABLE ERROR_REQUEST_REFUSED \
           ERROR_INVALID_DRIVE_OBJECT ERROR_LIBRARY_FULL \
           ERROR_MEDIUM_NOT_ACCESSIBLE ERROR_UNABLE_TO_LOAD_MEDIUM \
           ERROR_UNABLE_TO_INVENTORY_DRIVE ERROR_UNABLE_TO_INVENTORY_SLOT \
           ERROR_UNABLE_TO_INVENTORY_TRANSPORT ERROR_TRANSPORT_FULL \
           ERROR_CONTROLLING_IEPORT ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA \
           ERROR_CLEANER_SLOT_SET ERROR_CLEANER_SLOT_NOT_SET \
           ERROR_CLEANER_CARTRIDGE_SPENT ERROR_UNEXPECTED_OMID \
           ERROR_CANT_DELETE_LAST_ITEM ERROR_MESSAGE_EXCEEDS_MAX_SIZE \
           ERROR_VOLUME_CONTAINS_SYS_FILES ERROR_INDIGENOUS_TYPE \
           ERROR_NO_SUPPORTING_DRIVES ERROR_CLEANER_CARTRIDGE_INSTALLED \
           ERROR_FILE_OFFLINE ERROR_REMOTE_STORAGE_NOT_ACTIVE \
           ERROR_REMOTE_STORAGE_MEDIA_ERROR ERROR_NOT_A_REPARSE_POINT \
           ERROR_REPARSE_ATTRIBUTE_CONFLICT ERROR_INVALID_REPARSE_DATA \
           ERROR_REPARSE_TAG_INVALID ERROR_REPARSE_TAG_MISMATCH \
           ERROR_VOLUME_NOT_SIS_ENABLED ERROR_DEPENDENT_RESOURCE_EXISTS \
           ERROR_DEPENDENCY_NOT_FOUND ERROR_DEPENDENCY_ALREADY_EXISTS \
           ERROR_RESOURCE_NOT_ONLINE ERROR_HOST_NODE_NOT_AVAILABLE \
           ERROR_RESOURCE_NOT_AVAILABLE ERROR_RESOURCE_NOT_FOUND \
           ERROR_SHUTDOWN_CLUSTER ERROR_CANT_EVICT_ACTIVE_NODE \
           ERROR_OBJECT_ALREADY_EXISTS ERROR_OBJECT_IN_LIST \
           ERROR_GROUP_NOT_AVAILABLE ERROR_GROUP_NOT_FOUND \
           ERROR_GROUP_NOT_ONLINE ERROR_HOST_NODE_NOT_RESOURCE_OWNER \
           ERROR_HOST_NODE_NOT_GROUP_OWNER ERROR_RESMON_CREATE_FAILED \
           ERROR_RESMON_ONLINE_FAILED ERROR_RESOURCE_ONLINE \
           ERROR_QUORUM_RESOURCE ERROR_NOT_QUORUM_CAPABLE \
           ERROR_CLUSTER_SHUTTING_DOWN ERROR_INVALID_STATE \
           ERROR_RESOURCE_PROPERTIES_STORED ERROR_NOT_QUORUM_CLASS \
           ERROR_CORE_RESOURCE ERROR_QUORUM_RESOURCE_ONLINE_FAILED \
           ERROR_QUORUMLOG_OPEN_FAILED ERROR_CLUSTERLOG_CORRUPT \
           ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE \
           ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE \
           ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND \
           ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE ERROR_QUORUM_OWNER_ALIVE \
           ERROR_NETWORK_NOT_AVAILABLE ERROR_NODE_NOT_AVAILABLE \
           ERROR_ALL_NODES_NOT_AVAILABLE ERROR_RESOURCE_FAILED \
           ERROR_CLUSTER_INVALID_NODE ERROR_CLUSTER_NODE_EXISTS \
           ERROR_CLUSTER_JOIN_IN_PROGRESS ERROR_CLUSTER_NODE_NOT_FOUND \
           ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND ERROR_CLUSTER_NETWORK_EXISTS \
           ERROR_CLUSTER_NETWORK_NOT_FOUND ERROR_CLUSTER_NETINTERFACE_EXISTS \
           ERROR_CLUSTER_NETINTERFACE_NOT_FOUND \
           ERROR_CLUSTER_INVALID_REQUEST \
           ERROR_CLUSTER_INVALID_NETWORK_PROVIDER ERROR_CLUSTER_NODE_DOWN \
           ERROR_CLUSTER_NODE_UNREACHABLE ERROR_CLUSTER_NODE_NOT_MEMBER \
           ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS ERROR_CLUSTER_INVALID_NETWORK \
           ERROR_CLUSTER_NODE_UP ERROR_CLUSTER_IPADDR_IN_USE \
           ERROR_CLUSTER_NODE_NOT_PAUSED ERROR_CLUSTER_NO_SECURITY_CONTEXT \
           ERROR_CLUSTER_NETWORK_NOT_INTERNAL \
           ERROR_CLUSTER_NODE_ALREADY_UP ERROR_CLUSTER_NODE_ALREADY_DOWN \
           ERROR_CLUSTER_NETWORK_ALREADY_ONLINE \
           ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE \
           ERROR_CLUSTER_NODE_ALREADY_MEMBER \
           ERROR_CLUSTER_LAST_INTERNAL_NETWORK \
           ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS \
           ERROR_INVALID_OPERATION_ON_QUORUM ERROR_DEPENDENCY_NOT_ALLOWED \
           ERROR_CLUSTER_NODE_PAUSED ERROR_NODE_CANT_HOST_RESOURCE \
           ERROR_CLUSTER_NODE_NOT_READY ERROR_CLUSTER_NODE_SHUTTING_DOWN \
           ERROR_CLUSTER_JOIN_ABORTED ERROR_CLUSTER_INCOMPATIBLE_VERSIONS \
           ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED \
           ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED \
           ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND \
           ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED \
           ERROR_CLUSTER_RESNAME_NOT_FOUND \
           ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED \
           ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST \
           ERROR_CLUSTER_DATABASE_SEQMISMATCH \
           ERROR_RESMON_INVALID_STATE ERROR_CLUSTER_GUM_NOT_LOCKER \
           ERROR_QUORUM_DISK_NOT_FOUND ERROR_DATABASE_BACKUP_CORRUPT \
           ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT \
           ERROR_RESOURCE_PROPERTY_UNCHANGEABLE \
           ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE \
           ERROR_CLUSTER_QUORUMLOG_NOT_FOUND ERROR_CLUSTER_MEMBERSHIP_HALT \
           ERROR_CLUSTER_INSTANCE_ID_MISMATCH \
           ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP \
           ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH \
           ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP \
           ERROR_CLUSTER_PARAMETER_MISMATCH \
           ERROR_NODE_CANNOT_BE_CLUSTERED ERROR_CLUSTER_WRONG_OS_VERSION \
           ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME \
           ERROR_CLUSCFG_ALREADY_COMMITTED ERROR_CLUSCFG_ROLLBACK_FAILED \
           ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT \
           ERROR_CLUSTER_OLD_VERSION \
           ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME \
           ERROR_ENCRYPTION_FAILED ERROR_DECRYPTION_FAILED \
           ERROR_FILE_ENCRYPTED ERROR_NO_RECOVERY_POLICY ERROR_NO_EFS \
           ERROR_WRONG_EFS ERROR_NO_USER_KEYS ERROR_FILE_NOT_ENCRYPTED \
           ERROR_NOT_EXPORT_FORMAT ERROR_FILE_READ_ONLY \
           ERROR_DIR_EFS_DISALLOWED ERROR_EFS_SERVER_NOT_TRUSTED \
           ERROR_BAD_RECOVERY_POLICY ERROR_EFS_ALG_BLOB_TOO_BIG \
           ERROR_VOLUME_NOT_SUPPORT_EFS ERROR_EFS_DISABLED \
           ERROR_EFS_VERSION_NOT_SUPPORT ERROR_NO_BROWSER_SERVERS_FOUND \
           SCHED_E_SERVICE_NOT_LOCALSYSTEM ERROR_CTX_WINSTATION_NAME_INVALID \
           ERROR_CTX_INVALID_PD ERROR_CTX_PD_NOT_FOUND \
           ERROR_CTX_WD_NOT_FOUND ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY \
           ERROR_CTX_SERVICE_NAME_COLLISION ERROR_CTX_CLOSE_PENDING \
           ERROR_CTX_NO_OUTBUF ERROR_CTX_MODEM_INF_NOT_FOUND \
           ERROR_CTX_INVALID_MODEMNAME ERROR_CTX_MODEM_RESPONSE_ERROR \
           ERROR_CTX_MODEM_RESPONSE_TIMEOUT \
           ERROR_CTX_MODEM_RESPONSE_NO_CARRIER \
           ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE \
           ERROR_CTX_MODEM_RESPONSE_BUSY ERROR_CTX_MODEM_RESPONSE_VOICE \
           ERROR_CTX_TD_ERROR ERROR_CTX_WINSTATION_NOT_FOUND \
           ERROR_CTX_WINSTATION_ALREADY_EXISTS ERROR_CTX_WINSTATION_BUSY \
           ERROR_CTX_BAD_VIDEO_MODE ERROR_CTX_GRAPHICS_INVALID \
           ERROR_CTX_LOGON_DISABLED ERROR_CTX_NOT_CONSOLE \
           ERROR_CTX_CLIENT_QUERY_TIMEOUT ERROR_CTX_CONSOLE_DISCONNECT \
           ERROR_CTX_CONSOLE_CONNECT ERROR_CTX_SHADOW_DENIED \
           ERROR_CTX_WINSTATION_ACCESS_DENIED ERROR_CTX_INVALID_WD \
           ERROR_CTX_SHADOW_INVALID ERROR_CTX_SHADOW_DISABLED \
           ERROR_CTX_CLIENT_LICENSE_IN_USE ERROR_CTX_CLIENT_LICENSE_NOT_SET \
           ERROR_CTX_LICENSE_NOT_AVAILABLE ERROR_CTX_LICENSE_CLIENT_INVALID \
           ERROR_CTX_LICENSE_EXPIRED ERROR_CTX_SHADOW_NOT_RUNNING \
           ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE \
           ERROR_ACTIVATION_COUNT_EXCEEDED FRS_ERR_INVALID_API_SEQUENCE \
           FRS_ERR_STARTING_SERVICE FRS_ERR_STOPPING_SERVICE \
           FRS_ERR_INTERNAL_API FRS_ERR_INTERNAL \
           FRS_ERR_SERVICE_COMM FRS_ERR_INSUFFICIENT_PRIV \
           FRS_ERR_AUTHENTICATION FRS_ERR_PARENT_INSUFFICIENT_PRIV \
           FRS_ERR_PARENT_AUTHENTICATION FRS_ERR_CHILD_TO_PARENT_COMM \
           FRS_ERR_PARENT_TO_CHILD_COMM FRS_ERR_SYSVOL_POPULATE \
           FRS_ERR_SYSVOL_POPULATE_TIMEOUT FRS_ERR_SYSVOL_IS_BUSY \
           FRS_ERR_SYSVOL_DEMOTE FRS_ERR_INVALID_SERVICE_PARAMETER \
           ERROR_DS_NOT_INSTALLED ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY \
           ERROR_DS_NO_ATTRIBUTE_OR_VALUE ERROR_DS_INVALID_ATTRIBUTE_SYNTAX \
           ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED \
           ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS ERROR_DS_BUSY \
           ERROR_DS_UNAVAILABLE ERROR_DS_NO_RIDS_ALLOCATED \
           ERROR_DS_NO_MORE_RIDS ERROR_DS_INCORRECT_ROLE_OWNER \
           ERROR_DS_RIDMGR_INIT_ERROR ERROR_DS_OBJ_CLASS_VIOLATION \
           ERROR_DS_CANT_ON_NON_LEAF ERROR_DS_CANT_ON_RDN \
           ERROR_DS_CANT_MOD_OBJ_CLASS ERROR_DS_CROSS_DOM_MOVE_ERROR \
           ERROR_DS_GC_NOT_AVAILABLE ERROR_SHARED_POLICY \
           ERROR_POLICY_OBJECT_NOT_FOUND ERROR_POLICY_ONLY_IN_DS \
           ERROR_PROMOTION_ACTIVE ERROR_NO_PROMOTION_ACTIVE \
           ERROR_DS_OPERATIONS_ERROR ERROR_DS_PROTOCOL_ERROR \
           ERROR_DS_TIMELIMIT_EXCEEDED ERROR_DS_SIZELIMIT_EXCEEDED \
           ERROR_DS_ADMIN_LIMIT_EXCEEDED ERROR_DS_COMPARE_FALSE \
           ERROR_DS_COMPARE_TRUE ERROR_DS_AUTH_METHOD_NOT_SUPPORTED \
           ERROR_DS_STRONG_AUTH_REQUIRED \
           ERROR_DS_INAPPROPRIATE_AUTH ERROR_DS_AUTH_UNKNOWN \
           ERROR_DS_REFERRAL ERROR_DS_UNAVAILABLE_CRIT_EXTENSION \
           ERROR_DS_CONFIDENTIALITY_REQUIRED ERROR_DS_INAPPROPRIATE_MATCHING \
           ERROR_DS_CONSTRAINT_VIOLATION ERROR_DS_NO_SUCH_OBJECT \
           ERROR_DS_ALIAS_PROBLEM ERROR_DS_INVALID_DN_SYNTAX \
           ERROR_DS_IS_LEAF ERROR_DS_ALIAS_DEREF_PROBLEM \
           ERROR_DS_UNWILLING_TO_PERFORM ERROR_DS_LOOP_DETECT \
           ERROR_DS_NAMING_VIOLATION ERROR_DS_OBJECT_RESULTS_TOO_LARGE \
           ERROR_DS_AFFECTS_MULTIPLE_DSAS ERROR_DS_SERVER_DOWN \
           ERROR_DS_LOCAL_ERROR ERROR_DS_ENCODING_ERROR \
           ERROR_DS_DECODING_ERROR ERROR_DS_FILTER_UNKNOWN \
           ERROR_DS_PARAM_ERROR ERROR_DS_NOT_SUPPORTED \
           ERROR_DS_NO_RESULTS_RETURNED ERROR_DS_CONTROL_NOT_FOUND \
           ERROR_DS_CLIENT_LOOP ERROR_DS_REFERRAL_LIMIT_EXCEEDED \
           ERROR_DS_SORT_CONTROL_MISSING ERROR_DS_OFFSET_RANGE_ERROR \
           ERROR_DS_ROOT_MUST_BE_NC ERROR_DS_ADD_REPLICA_INHIBITED \
           ERROR_DS_ATT_NOT_DEF_IN_SCHEMA ERROR_DS_MAX_OBJ_SIZE_EXCEEDED \
           ERROR_DS_OBJ_STRING_NAME_EXISTS ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA \
           ERROR_DS_RDN_DOESNT_MATCH_SCHEMA ERROR_DS_NO_REQUESTED_ATTS_FOUND \
           ERROR_DS_USER_BUFFER_TO_SMALL ERROR_DS_ATT_IS_NOT_ON_OBJ \
           ERROR_DS_ILLEGAL_MOD_OPERATION ERROR_DS_OBJ_TOO_LARGE \
           ERROR_DS_BAD_INSTANCE_TYPE ERROR_DS_MASTERDSA_REQUIRED \
           ERROR_DS_OBJECT_CLASS_REQUIRED ERROR_DS_MISSING_REQUIRED_ATT \
           ERROR_DS_ATT_NOT_DEF_FOR_CLASS ERROR_DS_ATT_ALREADY_EXISTS \
           ERROR_DS_CANT_ADD_ATT_VALUES ERROR_DS_SINGLE_VALUE_CONSTRAINT \
           ERROR_DS_RANGE_CONSTRAINT ERROR_DS_ATT_VAL_ALREADY_EXISTS \
           ERROR_DS_CANT_REM_MISSING_ATT ERROR_DS_CANT_REM_MISSING_ATT_VAL \
           ERROR_DS_ROOT_CANT_BE_SUBREF ERROR_DS_NO_CHAINING \
           ERROR_DS_NO_CHAINED_EVAL ERROR_DS_NO_PARENT_OBJECT \
           ERROR_DS_PARENT_IS_AN_ALIAS ERROR_DS_CANT_MIX_MASTER_AND_REPS \
           ERROR_DS_CHILDREN_EXIST ERROR_DS_OBJ_NOT_FOUND \
           ERROR_DS_ALIASED_OBJ_MISSING ERROR_DS_BAD_NAME_SYNTAX \
           ERROR_DS_ALIAS_POINTS_TO_ALIAS ERROR_DS_CANT_DEREF_ALIAS \
           ERROR_DS_OUT_OF_SCOPE ERROR_DS_OBJECT_BEING_REMOVED \
           ERROR_DS_CANT_DELETE_DSA_OBJ ERROR_DS_GENERIC_ERROR \
           ERROR_DS_DSA_MUST_BE_INT_MASTER ERROR_DS_CLASS_NOT_DSA \
           ERROR_DS_INSUFF_ACCESS_RIGHTS ERROR_DS_ILLEGAL_SUPERIOR \
           ERROR_DS_ATTRIBUTE_OWNED_BY_SAM ERROR_DS_NAME_TOO_MANY_PARTS \
           ERROR_DS_NAME_TOO_LONG ERROR_DS_NAME_VALUE_TOO_LONG \
           ERROR_DS_NAME_UNPARSEABLE ERROR_DS_NAME_TYPE_UNKNOWN \
           ERROR_DS_NOT_AN_OBJECT ERROR_DS_SEC_DESC_TOO_SHORT \
           ERROR_DS_SEC_DESC_INVALID ERROR_DS_NO_DELETED_NAME \
           ERROR_DS_SUBREF_MUST_HAVE_PARENT ERROR_DS_NCNAME_MUST_BE_NC \
           ERROR_DS_CANT_ADD_SYSTEM_ONLY ERROR_DS_CLASS_MUST_BE_CONCRETE \
           ERROR_DS_INVALID_DMD ERROR_DS_OBJ_GUID_EXISTS \
           ERROR_DS_NOT_ON_BACKLINK ERROR_DS_NO_CROSSREF_FOR_NC \
           ERROR_DS_SHUTTING_DOWN ERROR_DS_UNKNOWN_OPERATION \
           ERROR_DS_INVALID_ROLE_OWNER ERROR_DS_COULDNT_CONTACT_FSMO \
           ERROR_DS_CROSS_NC_DN_RENAME ERROR_DS_CANT_MOD_SYSTEM_ONLY \
           ERROR_DS_REPLICATOR_ONLY ERROR_DS_OBJ_CLASS_NOT_DEFINED \
           ERROR_DS_OBJ_CLASS_NOT_SUBCLASS ERROR_DS_NAME_REFERENCE_INVALID \
           ERROR_DS_CROSS_REF_EXISTS ERROR_DS_CANT_DEL_MASTER_CROSSREF \
           ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD \
           ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX \
           ERROR_DS_DUP_RDN ERROR_DS_DUP_OID ERROR_DS_DUP_MAPI_ID \
           ERROR_DS_DUP_SCHEMA_ID_GUID ERROR_DS_DUP_LDAP_DISPLAY_NAME \
           ERROR_DS_SEMANTIC_ATT_TEST ERROR_DS_SYNTAX_MISMATCH \
           ERROR_DS_EXISTS_IN_MUST_HAVE ERROR_DS_EXISTS_IN_MAY_HAVE \
           ERROR_DS_NONEXISTENT_MAY_HAVE ERROR_DS_NONEXISTENT_MUST_HAVE \
           ERROR_DS_AUX_CLS_TEST_FAIL ERROR_DS_NONEXISTENT_POSS_SUP \
           ERROR_DS_SUB_CLS_TEST_FAIL ERROR_DS_BAD_RDN_ATT_ID_SYNTAX \
           ERROR_DS_EXISTS_IN_AUX_CLS ERROR_DS_EXISTS_IN_SUB_CLS \
           ERROR_DS_EXISTS_IN_POSS_SUP ERROR_DS_RECALCSCHEMA_FAILED \
           ERROR_DS_TREE_DELETE_NOT_FINISHED ERROR_DS_CANT_DELETE \
           ERROR_DS_ATT_SCHEMA_REQ_ID ERROR_DS_BAD_ATT_SCHEMA_SYNTAX \
           ERROR_DS_CANT_CACHE_ATT ERROR_DS_CANT_CACHE_CLASS \
           ERROR_DS_CANT_REMOVE_ATT_CACHE ERROR_DS_CANT_REMOVE_CLASS_CACHE \
           ERROR_DS_CANT_RETRIEVE_DN ERROR_DS_MISSING_SUPREF \
           ERROR_DS_CANT_RETRIEVE_INSTANCE ERROR_DS_CODE_INCONSISTENCY \
           ERROR_DS_DATABASE_ERROR ERROR_DS_GOVERNSID_MISSING \
           ERROR_DS_MISSING_EXPECTED_ATT ERROR_DS_NCNAME_MISSING_CR_REF \
           ERROR_DS_SECURITY_CHECKING_ERROR ERROR_DS_SCHEMA_NOT_LOADED \
           ERROR_DS_SCHEMA_ALLOC_FAILED ERROR_DS_ATT_SCHEMA_REQ_SYNTAX \
           ERROR_DS_GCVERIFY_ERROR ERROR_DS_DRA_SCHEMA_MISMATCH \
           ERROR_DS_CANT_FIND_DSA_OBJ ERROR_DS_CANT_FIND_EXPECTED_NC \
           ERROR_DS_CANT_FIND_NC_IN_CACHE ERROR_DS_CANT_RETRIEVE_CHILD \
           ERROR_DS_SECURITY_ILLEGAL_MODIFY ERROR_DS_CANT_REPLACE_HIDDEN_REC \
           ERROR_DS_BAD_HIERARCHY_FILE ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED \
           ERROR_DS_CONFIG_PARAM_MISSING ERROR_DS_COUNTING_AB_INDICES_FAILED \
           ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED ERROR_DS_INTERNAL_FAILURE \
           ERROR_DS_UNKNOWN_ERROR ERROR_DS_ROOT_REQUIRES_CLASS_TOP \
           ERROR_DS_REFUSING_FSMO_ROLES ERROR_DS_MISSING_FSMO_SETTINGS \
           ERROR_DS_UNABLE_TO_SURRENDER_ROLES ERROR_DS_DRA_GENERIC \
           ERROR_DS_DRA_INVALID_PARAMETER ERROR_DS_DRA_BUSY \
           ERROR_DS_DRA_BAD_DN ERROR_DS_DRA_BAD_NC ERROR_DS_DRA_DN_EXISTS \
           ERROR_DS_DRA_INTERNAL_ERROR ERROR_DS_DRA_INCONSISTENT_DIT \
           ERROR_DS_DRA_CONNECTION_FAILED ERROR_DS_DRA_BAD_INSTANCE_TYPE \
           ERROR_DS_DRA_OUT_OF_MEM ERROR_DS_DRA_MAIL_PROBLEM \
           ERROR_DS_DRA_REF_ALREADY_EXISTS ERROR_DS_DRA_REF_NOT_FOUND \
           ERROR_DS_DRA_OBJ_IS_REP_SOURCE ERROR_DS_DRA_DB_ERROR \
           ERROR_DS_DRA_NO_REPLICA ERROR_DS_DRA_ACCESS_DENIED \
           ERROR_DS_DRA_NOT_SUPPORTED ERROR_DS_DRA_RPC_CANCELLED \
           ERROR_DS_DRA_SOURCE_DISABLED ERROR_DS_DRA_SINK_DISABLED \
           ERROR_DS_DRA_NAME_COLLISION ERROR_DS_DRA_SOURCE_REINSTALLED \
           ERROR_DS_DRA_MISSING_PARENT ERROR_DS_DRA_PREEMPTED \
           ERROR_DS_DRA_ABANDON_SYNC ERROR_DS_DRA_SHUTDOWN \
           ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET \
           ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA \
           ERROR_DS_DRA_EXTN_CONNECTION_FAILED \
           ERROR_DS_INSTALL_SCHEMA_MISMATCH \
           ERROR_DS_DUP_LINK_ID ERROR_DS_NAME_ERROR_RESOLVING \
           ERROR_DS_NAME_ERROR_NOT_FOUND ERROR_DS_NAME_ERROR_NOT_UNIQUE \
           ERROR_DS_NAME_ERROR_NO_MAPPING ERROR_DS_NAME_ERROR_DOMAIN_ONLY \
           ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING \
           ERROR_DS_CONSTRUCTED_ATT_MOD ERROR_DS_WRONG_OM_OBJ_CLASS \
           ERROR_DS_DRA_REPL_PENDING ERROR_DS_DS_REQUIRED \
           ERROR_DS_INVALID_LDAP_DISPLAY_NAME \
           ERROR_DS_NON_BASE_SEARCH ERROR_DS_CANT_RETRIEVE_ATTS \
           ERROR_DS_BACKLINK_WITHOUT_LINK ERROR_DS_EPOCH_MISMATCH \
           ERROR_DS_SRC_NAME_MISMATCH ERROR_DS_SRC_AND_DST_NC_IDENTICAL \
           ERROR_DS_DST_NC_MISMATCH ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC \
           ERROR_DS_SRC_GUID_MISMATCH ERROR_DS_CANT_MOVE_DELETED_OBJECT \
           ERROR_DS_PDC_OPERATION_IN_PROGRESS \
           ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD \
           ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION \
           ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS \
           ERROR_DS_NC_MUST_HAVE_NC_PARENT \
           ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE ERROR_DS_DST_DOMAIN_NOT_NATIVE \
           ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER \
           ERROR_DS_CANT_MOVE_ACCOUNT_GROUP \
           ERROR_DS_CANT_MOVE_RESOURCE_GROUP ERROR_DS_INVALID_SEARCH_FLAG \
           ERROR_DS_NO_TREE_DELETE_ABOVE_NC \
           ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE \
           ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE \
           ERROR_DS_SAM_INIT_FAILURE ERROR_DS_SENSITIVE_GROUP_VIOLATION \
           ERROR_DS_CANT_MOD_PRIMARYGROUPID ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD \
           ERROR_DS_NONSAFE_SCHEMA_CHANGE ERROR_DS_SCHEMA_UPDATE_DISALLOWED \
           ERROR_DS_CANT_CREATE_UNDER_SCHEMA \
           ERROR_DS_INSTALL_NO_SRC_SCH_VERSION \
           ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE \
           ERROR_DS_INVALID_GROUP_TYPE \
           ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN \
           ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN \
           ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER \
           ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER \
           ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER \
           ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER \
           ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER \
           ERROR_DS_HAVE_PRIMARY_MEMBERS \
           ERROR_DS_STRING_SD_CONVERSION_FAILED \
           ERROR_DS_NAMING_MASTER_GC ERROR_DS_LOOKUP_FAILURE \
           ERROR_DS_COULDNT_UPDATE_SPNS ERROR_DS_CANT_RETRIEVE_SD \
           ERROR_DS_KEY_NOT_UNIQUE ERROR_DS_WRONG_LINKED_ATT_SYNTAX \
           ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD \
           ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY ERROR_DS_CANT_START \
           ERROR_DS_INIT_FAILURE ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION \
           ERROR_DS_SOURCE_DOMAIN_IN_FOREST \
           ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST \
           ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED \
           ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN \
           ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER \
           ERROR_DS_SRC_SID_EXISTS_IN_FOREST \
           ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH \
           ERROR_SAM_INIT_FAILURE ERROR_DS_DRA_SCHEMA_INFO_SHIP \
           ERROR_DS_DRA_SCHEMA_CONFLICT ERROR_DS_DRA_EARLIER_SCHEMA_CONLICT \
           ERROR_DS_DRA_OBJ_NC_MISMATCH ERROR_DS_NC_STILL_HAS_DSAS \
           ERROR_DS_GC_REQUIRED ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY \
           ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS \
           ERROR_DS_CANT_ADD_TO_GC ERROR_DS_NO_CHECKPOINT_WITH_PDC \
           ERROR_DS_SOURCE_AUDITING_NOT_ENABLED \
           ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC \
           ERROR_DS_INVALID_NAME_FOR_SPN \
           ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS \
           ERROR_DS_UNICODEPWD_NOT_IN_QUOTES \
           ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED \
           ERROR_DS_MUST_BE_RUN_ON_DST_DC \
           ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER \
           ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ \
           ERROR_DS_INIT_FAILURE_CONSOLE ERROR_DS_SAM_INIT_FAILURE_CONSOLE \
           ERROR_DS_FOREST_VERSION_TOO_HIGH ERROR_DS_DOMAIN_VERSION_TOO_HIGH \
           ERROR_DS_FOREST_VERSION_TOO_LOW ERROR_DS_DOMAIN_VERSION_TOO_LOW \
           ERROR_DS_INCOMPATIBLE_VERSION ERROR_DS_LOW_DSA_VERSION \
           ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN \
           ERROR_DS_NOT_SUPPORTED_SORT_ORDER ERROR_DS_NAME_NOT_UNIQUE \
           ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4 \
           ERROR_DS_OUT_OF_VERSION_STORE ERROR_DS_INCOMPATIBLE_CONTROLS_USED \
           ERROR_DS_NO_REF_DOMAIN ERROR_DS_RESERVED_LINK_ID \
           ERROR_DS_LINK_ID_NOT_AVAILABLE \
           ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER \
           ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE \
           ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC \
           ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG \
           ERROR_DS_MODIFYDN_WRONG_GRANDPARENT \
           ERROR_DS_NAME_ERROR_TRUST_REFERRAL \
           ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER \
           ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD \
           ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 \
           ERROR_DS_THREAD_LIMIT_EXCEEDED ERROR_DS_NOT_CLOSEST \
           ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF \
           ERROR_DS_SINGLE_USER_MODE_FAILED \
           ERROR_DS_NTDSCRIPT_SYNTAX_ERROR ERROR_DS_NTDSCRIPT_PROCESS_ERROR \
           ERROR_DS_DIFFERENT_REPL_EPOCHS ERROR_DS_DRS_EXTENSIONS_CHANGED \
           ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR \
           ERROR_DS_NO_MSDS_INTID ERROR_DS_DUP_MSDS_INTID \
           ERROR_DS_EXISTS_IN_RDNATTID \
           ERROR_DS_AUTHORIZATION_FAILED ERROR_DS_INVALID_SCRIPT \
           ERROR_DS_REMOTE_CROSSREF_OP_FAILED ERROR_DS_CROSS_REF_BUSY \
           ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN \
           ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC \
           ERROR_DS_DUPLICATE_ID_FOUND \
           ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT \
           ERROR_DS_GROUP_CONVERSION_ERROR \
           ERROR_DS_CANT_MOVE_APP_BASIC_GROUP \
           ERROR_DS_CANT_MOVE_APP_QUERY_GROUP ERROR_DS_ROLE_NOT_VERIFIED \
           ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL \
           ERROR_DS_DOMAIN_RENAME_IN_PROGRESS ERROR_DS_EXISTING_AD_CHILD_NC \
           DNS_ERROR_RCODE_FORMAT_ERROR DNS_ERROR_RCODE_SERVER_FAILURE \
           DNS_ERROR_RCODE_NAME_ERROR DNS_ERROR_RCODE_NOT_IMPLEMENTED \
           DNS_ERROR_RCODE_REFUSED DNS_ERROR_RCODE_YXDOMAIN \
           DNS_ERROR_RCODE_YXRRSET DNS_ERROR_RCODE_NXRRSET \
           DNS_ERROR_RCODE_NOTAUTH DNS_ERROR_RCODE_NOTZONE \
           DNS_ERROR_RCODE_BADSIG DNS_ERROR_RCODE_BADKEY \
           DNS_ERROR_RCODE_BADTIME DNS_INFO_NO_RECORDS DNS_ERROR_BAD_PACKET \
           DNS_ERROR_NO_PACKET DNS_ERROR_RCODE DNS_ERROR_UNSECURE_PACKET \
           DNS_ERROR_INVALID_TYPE DNS_ERROR_INVALID_IP_ADDRESS \
           DNS_ERROR_INVALID_PROPERTY DNS_ERROR_TRY_AGAIN_LATER \
           DNS_ERROR_NOT_UNIQUE DNS_ERROR_NON_RFC_NAME DNS_STATUS_FQDN \
           DNS_STATUS_DOTTED_NAME DNS_STATUS_SINGLE_PART_NAME \
           DNS_ERROR_INVALID_NAME_CHAR DNS_ERROR_NUMERIC_NAME \
           DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER \
           DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION \
           DNS_ERROR_CANNOT_FIND_ROOT_HINTS \
           DNS_ERROR_INCONSISTENT_ROOT_HINTS DNS_ERROR_ZONE_DOES_NOT_EXIST \
           DNS_ERROR_NO_ZONE_INFO DNS_ERROR_INVALID_ZONE_OPERATION \
           DNS_ERROR_ZONE_CONFIGURATION_ERROR \
           DNS_ERROR_ZONE_HAS_NO_SOA_RECORD \
           DNS_ERROR_ZONE_HAS_NO_NS_RECORDS DNS_ERROR_ZONE_LOCKED \
           DNS_ERROR_ZONE_CREATION_FAILED DNS_ERROR_ZONE_ALREADY_EXISTS \
           DNS_ERROR_AUTOZONE_ALREADY_EXISTS DNS_ERROR_INVALID_ZONE_TYPE \
           DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP \
           DNS_ERROR_ZONE_NOT_SECONDARY DNS_ERROR_NEED_SECONDARY_ADDRESSES \
           DNS_ERROR_WINS_INIT_FAILED DNS_ERROR_NEED_WINS_SERVERS \
           DNS_ERROR_NBSTAT_INIT_FAILED DNS_ERROR_SOA_DELETE_INVALID \
           DNS_ERROR_FORWARDER_ALREADY_EXISTS \
           DNS_ERROR_ZONE_REQUIRES_MASTER_IP \
           DNS_ERROR_ZONE_IS_SHUTDOWN DNS_ERROR_PRIMARY_REQUIRES_DATAFILE \
           DNS_ERROR_INVALID_DATAFILE_NAME DNS_ERROR_DATAFILE_OPEN_FAILURE \
           DNS_ERROR_FILE_WRITEBACK_FAILED DNS_ERROR_DATAFILE_PARSING \
           DNS_ERROR_RECORD_DOES_NOT_EXIST DNS_ERROR_RECORD_FORMAT \
           DNS_ERROR_NODE_CREATION_FAILED DNS_ERROR_UNKNOWN_RECORD_TYPE \
           DNS_ERROR_RECORD_TIMED_OUT DNS_ERROR_NAME_NOT_IN_ZONE \
           DNS_ERROR_CNAME_LOOP DNS_ERROR_NODE_IS_CNAME \
           DNS_ERROR_CNAME_COLLISION DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT \
           DNS_ERROR_RECORD_ALREADY_EXISTS DNS_ERROR_SECONDARY_DATA \
           DNS_ERROR_NO_CREATE_CACHE_DATA DNS_ERROR_NAME_DOES_NOT_EXIST \
           DNS_WARNING_PTR_CREATE_FAILED DNS_WARNING_DOMAIN_UNDELETED \
           DNS_ERROR_DS_UNAVAILABLE DNS_ERROR_DS_ZONE_ALREADY_EXISTS \
           DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE DNS_INFO_AXFR_COMPLETE \
           DNS_ERROR_AXFR DNS_INFO_ADDED_LOCAL_WINS \
           DNS_STATUS_CONTINUE_NEEDED DNS_ERROR_NO_TCPIP \
           DNS_ERROR_NO_DNS_SERVERS DNS_ERROR_DP_DOES_NOT_EXIST \
           DNS_ERROR_DP_ALREADY_EXISTS DNS_ERROR_DP_NOT_ENLISTED \
           DNS_ERROR_DP_ALREADY_ENLISTED DNS_ERROR_DP_NOT_AVAILABLE \
           WSABASEERR WSAEINTR WSAEBADF WSAEACCES WSAEFAULT WSAEINVAL \
           WSAEMFILE WSAEWOULDBLOCK WSAEINPROGRESS WSAEALREADY WSAENOTSOCK \
           WSAEDESTADDRREQ WSAEMSGSIZE WSAEPROTOTYPE WSAENOPROTOOPT \
           WSAEPROTONOSUPPORT WSAESOCKTNOSUPPORT WSAEOPNOTSUPP \
           WSAEPFNOSUPPORT WSAEAFNOSUPPORT WSAEADDRINUSE WSAEADDRNOTAVAIL \
           WSAENETDOWN WSAENETUNREACH WSAENETRESET WSAECONNABORTED \
           WSAECONNRESET WSAENOBUFS WSAEISCONN WSAENOTCONN WSAESHUTDOWN \
           WSAETOOMANYREFS WSAETIMEDOUT WSAECONNREFUSED WSAELOOP \
           WSAENAMETOOLONG WSAEHOSTDOWN WSAEHOSTUNREACH WSAENOTEMPTY \
           WSAEPROCLIM WSAEUSERS WSAEDQUOT WSAESTALE WSAEREMOTE \
           WSASYSNOTREADY WSAVERNOTSUPPORTED WSANOTINITIALISED WSAEDISCON \
           WSAENOMORE WSAECANCELLED WSAEINVALIDPROCTABLE WSAEINVALIDPROVIDER \
           WSAEPROVIDERFAILEDINIT WSASYSCALLFAILURE WSASERVICE_NOT_FOUND \
           WSATYPE_NOT_FOUND WSA_E_NO_MORE WSA_E_CANCELLED WSAEREFUSED \
           WSAHOST_NOT_FOUND WSATRY_AGAIN WSANO_RECOVERY WSANO_DATA \
           WSA_QOS_RECEIVERS WSA_QOS_SENDERS WSA_QOS_NO_SENDERS \
           WSA_QOS_NO_RECEIVERS WSA_QOS_REQUEST_CONFIRMED \
           WSA_QOS_ADMISSION_FAILURE WSA_QOS_POLICY_FAILURE \
           WSA_QOS_BAD_STYLE WSA_QOS_BAD_OBJECT WSA_QOS_TRAFFIC_CTRL_ERROR \
           WSA_QOS_GENERIC_ERROR WSA_QOS_ESERVICETYPE WSA_QOS_EFLOWSPEC \
           WSA_QOS_EPROVSPECBUF WSA_QOS_EFILTERSTYLE WSA_QOS_EFILTERTYPE \
           WSA_QOS_EFILTERCOUNT WSA_QOS_EOBJLENGTH WSA_QOS_EFLOWCOUNT \
           WSA_QOS_EUNKNOWNPSOBJ WSA_QOS_EPOLICYOBJ WSA_QOS_EFLOWDESC \
           WSA_QOS_EPSFLOWSPEC WSA_QOS_EPSFILTERSPEC WSA_QOS_ESDMODEOBJ \
           WSA_QOS_ESHAPERATEOBJ WSA_QOS_RESERVED_PETYPE \
           ERROR_IPSEC_QM_POLICY_EXISTS ERROR_IPSEC_QM_POLICY_NOT_FOUND \
           ERROR_IPSEC_QM_POLICY_IN_USE ERROR_IPSEC_MM_POLICY_EXISTS \
           ERROR_IPSEC_MM_POLICY_NOT_FOUND ERROR_IPSEC_MM_POLICY_IN_USE \
           ERROR_IPSEC_MM_FILTER_EXISTS ERROR_IPSEC_MM_FILTER_NOT_FOUND \
           ERROR_IPSEC_TRANSPORT_FILTER_EXISTS \
           ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND ERROR_IPSEC_MM_AUTH_EXISTS \
           ERROR_IPSEC_MM_AUTH_NOT_FOUND ERROR_IPSEC_MM_AUTH_IN_USE \
           ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND \
           ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND \
           ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND \
           ERROR_IPSEC_TUNNEL_FILTER_EXISTS \
           ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND \
           ERROR_IPSEC_MM_FILTER_PENDING_DELETION \
           ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION \
           ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION \
           ERROR_IPSEC_MM_POLICY_PENDING_DELETION \
           ERROR_IPSEC_MM_AUTH_PENDING_DELETION \
           ERROR_IPSEC_QM_POLICY_PENDING_DELETION \
           WARNING_IPSEC_MM_POLICY_PRUNED WARNING_IPSEC_QM_POLICY_PRUNED \
           ERROR_IPSEC_IKE_AUTH_FAIL ERROR_IPSEC_IKE_ATTRIB_FAIL \
           ERROR_IPSEC_IKE_NEGOTIATION_PENDING \
           ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR \
           ERROR_IPSEC_IKE_TIMED_OUT ERROR_IPSEC_IKE_NO_CERT \
           ERROR_IPSEC_IKE_SA_DELETED ERROR_IPSEC_IKE_SA_REAPED \
           ERROR_IPSEC_IKE_MM_ACQUIRE_DROP ERROR_IPSEC_IKE_QM_ACQUIRE_DROP \
           ERROR_IPSEC_IKE_QUEUE_DROP_MM ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM \
           ERROR_IPSEC_IKE_DROP_NO_RESPONSE ERROR_IPSEC_IKE_MM_DELAY_DROP \
           ERROR_IPSEC_IKE_QM_DELAY_DROP ERROR_IPSEC_IKE_ERROR \
           ERROR_IPSEC_IKE_CRL_FAILED ERROR_IPSEC_IKE_INVALID_KEY_USAGE \
           ERROR_IPSEC_IKE_INVALID_CERT_TYPE \
           ERROR_IPSEC_IKE_NO_PRIVATE_KEY ERROR_IPSEC_IKE_DH_FAIL \
           ERROR_IPSEC_IKE_INVALID_HEADER ERROR_IPSEC_IKE_NO_POLICY \
           ERROR_IPSEC_IKE_INVALID_SIGNATURE ERROR_IPSEC_IKE_KERBEROS_ERROR \
           ERROR_IPSEC_IKE_NO_PUBLIC_KEY ERROR_IPSEC_IKE_PROCESS_ERR \
           ERROR_IPSEC_IKE_PROCESS_ERR_SA ERROR_IPSEC_IKE_PROCESS_ERR_PROP \
           ERROR_IPSEC_IKE_PROCESS_ERR_TRANS ERROR_IPSEC_IKE_PROCESS_ERR_KE \
           ERROR_IPSEC_IKE_PROCESS_ERR_ID ERROR_IPSEC_IKE_PROCESS_ERR_CERT \
           ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ \
           ERROR_IPSEC_IKE_PROCESS_ERR_HASH ERROR_IPSEC_IKE_PROCESS_ERR_SIG \
           ERROR_IPSEC_IKE_PROCESS_ERR_NONCE \
           ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY \
           ERROR_IPSEC_IKE_PROCESS_ERR_DELETE \
           ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR \
           ERROR_IPSEC_IKE_INVALID_PAYLOAD \
           ERROR_IPSEC_IKE_LOAD_SOFT_SA ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN \
           ERROR_IPSEC_IKE_INVALID_COOKIE ERROR_IPSEC_IKE_NO_PEER_CERT \
           ERROR_IPSEC_IKE_PEER_CRL_FAILED ERROR_IPSEC_IKE_POLICY_CHANGE \
           ERROR_IPSEC_IKE_NO_MM_POLICY ERROR_IPSEC_IKE_NOTCBPRIV \
           ERROR_IPSEC_IKE_SECLOADFAIL ERROR_IPSEC_IKE_FAILSSPINIT \
           ERROR_IPSEC_IKE_FAILQUERYSSP ERROR_IPSEC_IKE_SRVACQFAIL \
           ERROR_IPSEC_IKE_SRVQUERYCRED ERROR_IPSEC_IKE_GETSPIFAIL \
           ERROR_IPSEC_IKE_INVALID_FILTER ERROR_IPSEC_IKE_OUT_OF_MEMORY \
           ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED \
           ERROR_IPSEC_IKE_INVALID_POLICY ERROR_IPSEC_IKE_UNKNOWN_DOI \
           ERROR_IPSEC_IKE_INVALID_SITUATION ERROR_IPSEC_IKE_DH_FAILURE \
           ERROR_IPSEC_IKE_INVALID_GROUP ERROR_IPSEC_IKE_ENCRYPT \
           ERROR_IPSEC_IKE_DECRYPT ERROR_IPSEC_IKE_POLICY_MATCH \
           ERROR_IPSEC_IKE_UNSUPPORTED_ID ERROR_IPSEC_IKE_INVALID_HASH \
           ERROR_IPSEC_IKE_INVALID_HASH_ALG \
           ERROR_IPSEC_IKE_INVALID_HASH_SIZE \
           ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG \
           ERROR_IPSEC_IKE_INVALID_AUTH_ALG \
           ERROR_IPSEC_IKE_INVALID_SIG ERROR_IPSEC_IKE_LOAD_FAILED \
           ERROR_IPSEC_IKE_RPC_DELETE ERROR_IPSEC_IKE_BENIGN_REINIT \
           ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY \
           ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN ERROR_IPSEC_IKE_MM_LIMIT \
           ERROR_IPSEC_IKE_NEGOTIATION_DISABLED \
           ERROR_IPSEC_IKE_NEG_STATUS_END \
           ERROR_SXS_SECTION_NOT_FOUND ERROR_SXS_CANT_GEN_ACTCTX \
           ERROR_SXS_INVALID_ACTCTXDATA_FORMAT ERROR_SXS_ASSEMBLY_NOT_FOUND \
           ERROR_SXS_MANIFEST_FORMAT_ERROR ERROR_SXS_MANIFEST_PARSE_ERROR \
           ERROR_SXS_ACTIVATION_CONTEXT_DISABLED ERROR_SXS_KEY_NOT_FOUND \
           ERROR_SXS_VERSION_CONFLICT ERROR_SXS_WRONG_SECTION_TYPE \
           ERROR_SXS_THREAD_QUERIES_DISABLED \
           ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET \
           ERROR_SXS_UNKNOWN_ENCODING_GROUP ERROR_SXS_UNKNOWN_ENCODING \
           ERROR_SXS_INVALID_XML_NAMESPACE_URI \
           ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED \
           ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED \
           ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE \
           ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE \
           ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE \
           ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT \
           ERROR_SXS_DUPLICATE_DLL_NAME ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME \
           ERROR_SXS_DUPLICATE_CLSID ERROR_SXS_DUPLICATE_IID \
           ERROR_SXS_DUPLICATE_TLBID ERROR_SXS_DUPLICATE_PROGID \
           ERROR_SXS_DUPLICATE_ASSEMBLY_NAME \
           ERROR_SXS_FILE_HASH_MISMATCH ERROR_SXS_POLICY_PARSE_ERROR \
           ERROR_SXS_XML_E_MISSINGQUOTE ERROR_SXS_XML_E_COMMENTSYNTAX \
           ERROR_SXS_XML_E_BADSTARTNAMECHAR ERROR_SXS_XML_E_BADNAMECHAR \
           ERROR_SXS_XML_E_BADCHARINSTRING ERROR_SXS_XML_E_XMLDECLSYNTAX \
           ERROR_SXS_XML_E_BADCHARDATA ERROR_SXS_XML_E_MISSINGWHITESPACE \
           ERROR_SXS_XML_E_EXPECTINGTAGEND ERROR_SXS_XML_E_MISSINGSEMICOLON \
           ERROR_SXS_XML_E_UNBALANCEDPAREN ERROR_SXS_XML_E_INTERNALERROR \
           ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE \
           ERROR_SXS_XML_E_INCOMPLETE_ENCODING \
           ERROR_SXS_XML_E_MISSING_PAREN ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE \
           ERROR_SXS_XML_E_MULTIPLE_COLONS ERROR_SXS_XML_E_INVALID_DECIMAL \
           ERROR_SXS_XML_E_INVALID_HEXIDECIMAL \
           ERROR_SXS_XML_E_INVALID_UNICODE \
           ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK \
           ERROR_SXS_XML_E_UNEXPECTEDENDTAG ERROR_SXS_XML_E_UNCLOSEDTAG \
           ERROR_SXS_XML_E_DUPLICATEATTRIBUTE ERROR_SXS_XML_E_MULTIPLEROOTS \
           ERROR_SXS_XML_E_INVALIDATROOTLEVEL ERROR_SXS_XML_E_BADXMLDECL \
           ERROR_SXS_XML_E_MISSINGROOT ERROR_SXS_XML_E_UNEXPECTEDEOF \
           ERROR_SXS_XML_E_BADPEREFINSUBSET ERROR_SXS_XML_E_UNCLOSEDSTARTTAG \
           ERROR_SXS_XML_E_UNCLOSEDENDTAG ERROR_SXS_XML_E_UNCLOSEDSTRING \
           ERROR_SXS_XML_E_UNCLOSEDCOMMENT ERROR_SXS_XML_E_UNCLOSEDDECL \
           ERROR_SXS_XML_E_UNCLOSEDCDATA ERROR_SXS_XML_E_RESERVEDNAMESPACE \
           ERROR_SXS_XML_E_INVALIDENCODING ERROR_SXS_XML_E_INVALIDSWITCH \
           ERROR_SXS_XML_E_BADXMLCASE ERROR_SXS_XML_E_INVALID_STANDALONE \
           ERROR_SXS_XML_E_UNEXPECTED_STANDALONE \
           ERROR_SXS_XML_E_INVALID_VERSION ERROR_SXS_XML_E_MISSINGEQUALS \
           ERROR_SXS_PROTECTION_RECOVERY_FAILED \
           ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT \
           ERROR_SXS_PROTECTION_CATALOG_NOT_VALID \
           ERROR_SXS_UNTRANSLATABLE_HRESULT \
           ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING \
           ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE \
           ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME \
           )
# define errno_to_I uint32_to_I
#else
DEFCHECKER(check_errno, E2BIG EACCES EADDRINUSE EADDRNOTAVAIL EAFNOSUPPORT \
           EAGAIN EALREADY EBADF EBADMSG EBUSY ECANCELED ECHILD ECONNABORTED \
           ECONNREFUSED ECONNRESET EDEADLK EDESTADDRREQ EDOM EDQUOT EEXIST \
           EFAULT EFBIG EHOSTUNREACH EIDRM EILSEQ EINPROGRESS EINTR EINVAL \
           EIO EISCONN EISDIR ELOOP EMFILE EMLINK EMSGSIZE EMULTIHOP    \
           ENAMETOOLONG ENETDOWN ENETRESET ENETUNREACH ENFILE ENOBUFS ENODATA \
           ENODEV ENOENT ENOEXEC ENOLCK ENOLINK ENOMEM ENOMSG ENOPROTOOPT \
           ENOSPC ENOSR ENOSTR ENOSYS ENOTCONN ENOTDIR ENOTEMPTY ENOTSOCK \
           ENOTSUP ENOTTY ENXIO EOPNOTSUPP EOVERFLOW EPERM EPIPE EPROTO \
           EPROTONOSUPPORT EPROTOTYPE ERANGE EROFS ESPIPE ESRCH ESTALE ETIME \
           ETIMEDOUT ETXTBSY EWOULDBLOCK EXDEV                          \
           /* clisp/src/errunix.d */ ERREMOTE                           \
           /* Linux extras */                                           \
           EADV EBADE EBADFD EBADR EBADRQC EBADSLT EBFONT ECHRNG ECOMM  \
           EDEADLOCK EDOTDOT EHOSTDOWN EISNAM EL2HLT EL2NSYNC EL3HLT EL3RST \
           ELIBACC ELIBBAD ELIBEXEC ELIBMAX ELIBSCN ELNRNG EMEDIUMTYPE  \
           ENAVAIL ENOANO ENOCSI ENOMEDIUM ENONET ENOPKG ENOTBLK ENOTNAM \
           ENOTUNIQ EPFNOSUPPORT EREMCHG EREMOTE EREMOTEIO ERESTART ESHUTDOWN \
           ESOCKTNOSUPPORT ESRMNT ESTRPIPE ETOOMANYREFS EUCLEAN EUNATCH \
           EUSERS EXFULL ENOKEY EKEYEXPIRED EKEYREVOKED EKEYREJECTED    \
           /* Win32 extras */                                           \
           STRUNCATE ECASECLASH EFTYPE ELBIN ENMFILE ENOFILE ENOSHARE EPROCLIM \
           /* FreeBSD extras */                                         \
           EAUTH EBADRPC EDIRIOCTL EDOOFUS EJUSTRETURN ELAST ENEEDAUTH ENOATTR \
           ENOIOCTL EPROCUNAVAIL EPROGMISMATCH EPROGUNAVAIL ERPCMISMATCH \
           /* Solaris extras */                                         \
           ELOCKUNMAPPED ENOTACTIVE ENOTRECOVERABLE EOWNERDEAD          \
           /* http://www.google.com/codesearch?q=+file:errno.h */       \
           EALIGN EDIRTY EDUPPKG EINIT EISNAME ENET ENOSYM EREMDEV      \
           EREMOTERELEASE EVERSION EAIO ECLONEME EFAIL EINPROG EMTIMERS \
           ERESTARTNOHAND ERESTARTNOINTR ERESTARTSYS                    \
           )
# define errno_to_I  sint_to_I
#endif
DEFUN(OS::ERRNO, &optional newval) {
  if (eq(T,STACK_0)) {          /* all known error codes */
    int pos = 0;
    for (; pos < check_errno_map.size; pos++) {
      pushSTACK(allocate_cons());
      Car(STACK_0) = errno_to_I(check_errno_map.table[pos].c_const);
      Cdr(STACK_0) = *check_errno_map.table[pos].l_const;
    }
    VALUES1(listof(check_errno_map.size));
  } else {
#  if defined(WIN32_NATIVE)
    DWORD error_code;
    if (missingp(STACK_0)) {
      begin_system_call();
      error_code = GetLastError();
      end_system_call();
    } else {
      error_code = check_errno(STACK_0);
      begin_system_call();
      SetLastError(error_code);
      end_system_call();
    }
    VALUES1(check_errno_reverse(error_code));
#  else
    if (!missingp(STACK_0))
      errno = check_errno(STACK_0);
    VALUES1(check_errno_reverse(errno));
#  endif
  }
  skipSTACK(1);
}
DEFUN(OS::STRERROR, &optional error_code) {
  char *ret = NULL;
# if defined(WIN32_NATIVE)
  DWORD error_code = missingp(STACK_0) ? (DWORD)-1 : check_errno(STACK_0);
  int status;
  begin_system_call();
  status = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                         FORMAT_MESSAGE_FROM_SYSTEM |
                         FORMAT_MESSAGE_IGNORE_INSERTS,
                         NULL,
                         error_code == (DWORD)-1 ? GetLastError() : error_code,
                         0,
                         (LPTSTR) &ret,
                         0,
                         NULL);
  end_system_call();
  VALUES1(status == 0 ? NIL : safe_to_string(ret));
  begin_system_call(); LocalFree(ret); end_system_call();
# else
  /* errno access must be guarded with begin/end_system_call */
  int error_code = missingp(STACK_0) ? -1 : check_errno(STACK_0);
  begin_system_call();
  ret = strerror(error_code == -1 ? errno : error_code);
  end_system_call();
  VALUES1(safe_to_string(ret));
# endif
  skipSTACK(1);
}
#endif  /* (HAVE_ERRNO_H & HAVE_STRERROR) | WIN32_NATIVE */

#endif  /* HAVE_FFI */

#if defined(DEBUG_SPVW)
/* internal playground - see spvd.d & spvw_debug.d */
extern unsigned int get_constsym_count (void);
extern object get_constsym (unsigned int);
DEFUN(CONSTSYM, &optional pos) {
  VALUES1(missingp(STACK_0) ? fixnum(get_constsym_count())
          : get_constsym(I_to_uint(check_uint(STACK_0))));
  skipSTACK(1);
}
#endif

void module__syscalls__init_function_2 (module_t* module);
void module__syscalls__init_function_2 (module_t* module) {
#if defined(WIN32_NATIVE)
  init_win32_link();
#endif
#if defined(WIN32_NATIVE) || defined(UNIX_CYGWIN32)
  init_win32_cygwin_open_storage();
#endif
#if defined(HAVE_FFI)
  init_stdio();
#endif
}
