;;;; posix-common.scm - common code for UNIX and Windows versions of the posix unit
;
; Copyright (c) 2010-2022, The CHICKEN Team
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


(declare 
  (foreign-declare #<<EOF

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

EOF
))

(include "common-declarations.scm")

(define-syntax define-unimplemented
  (syntax-rules ()
    ((_ ?name)
     (define (?name . _)
       (error '?name (##core#immutable '"this function is not available on this platform")) ) ) ) )

(define-syntax set!-unimplemented
  (syntax-rules ()
    ((_ ?name)
     (set! ?name
       (lambda _
	 (error '?name (##core#immutable '"this function is not available on this platform"))) ) ) ) )


;;; Error codes:

(define-foreign-variable _errno int "errno")

(define-foreign-variable _eperm int "EPERM")
(define-foreign-variable _enoent int "ENOENT")
(define-foreign-variable _esrch int "ESRCH")
(define-foreign-variable _eintr int "EINTR")
(define-foreign-variable _eio int "EIO")
(define-foreign-variable _enoexec int "ENOEXEC")
(define-foreign-variable _ebadf int "EBADF")
(define-foreign-variable _echild int "ECHILD")
(define-foreign-variable _enomem int "ENOMEM")
(define-foreign-variable _eacces int "EACCES")
(define-foreign-variable _efault int "EFAULT")
(define-foreign-variable _ebusy int "EBUSY")
(define-foreign-variable _eexist int "EEXIST")
(define-foreign-variable _enotdir int "ENOTDIR")
(define-foreign-variable _eisdir int "EISDIR")
(define-foreign-variable _einval int "EINVAL")
(define-foreign-variable _emfile int "EMFILE")
(define-foreign-variable _enospc int "ENOSPC")
(define-foreign-variable _espipe int "ESPIPE")
(define-foreign-variable _epipe int "EPIPE")
(define-foreign-variable _eagain int "EAGAIN")
(define-foreign-variable _erofs int "EROFS")
(define-foreign-variable _enxio int "ENXIO")
(define-foreign-variable _e2big int "E2BIG")
(define-foreign-variable _exdev int "EXDEV")
(define-foreign-variable _enodev int "ENODEV")
(define-foreign-variable _enfile int "ENFILE")
(define-foreign-variable _enotty int "ENOTTY")
(define-foreign-variable _efbig int "EFBIG")
(define-foreign-variable _emlink int "EMLINK")
(define-foreign-variable _edom int "EDOM")
(define-foreign-variable _erange int "ERANGE")
(define-foreign-variable _edeadlk int "EDEADLK")
(define-foreign-variable _enametoolong int "ENAMETOOLONG")
(define-foreign-variable _enolck int "ENOLCK")
(define-foreign-variable _enosys int "ENOSYS")
(define-foreign-variable _enotempty int "ENOTEMPTY")
(define-foreign-variable _eilseq int "EILSEQ")
(define-foreign-variable _ewouldblock int "EWOULDBLOCK")

(define posix-error
  (let ([strerror (foreign-lambda c-string "strerror" int)]
	[string-append string-append] )
    (lambda (type loc msg . args)
      (let ([rn (##sys#update-errno)])
        (apply ##sys#signal-hook/errno
               type rn loc (string-append msg " - " (strerror rn)) args)))))

(define ##sys#posix-error posix-error)


;;; File properties

(define-foreign-variable _stat_st_ino unsigned-int "C_statbuf.st_ino")
(define-foreign-variable _stat_st_nlink unsigned-int "C_statbuf.st_nlink")
(define-foreign-variable _stat_st_gid unsigned-int "C_statbuf.st_gid")
(define-foreign-variable _stat_st_size integer64 "C_statbuf.st_size")
(define-foreign-variable _stat_st_mtime integer64 "C_statbuf.st_mtime")
(define-foreign-variable _stat_st_atime integer64 "C_statbuf.st_atime")
(define-foreign-variable _stat_st_ctime integer64 "C_statbuf.st_ctime")
(define-foreign-variable _stat_st_uid unsigned-int "C_statbuf.st_uid")
(define-foreign-variable _stat_st_mode unsigned-int "C_statbuf.st_mode")
(define-foreign-variable _stat_st_dev unsigned-int "C_statbuf.st_dev")
(define-foreign-variable _stat_st_rdev unsigned-int "C_statbuf.st_rdev")

(define-syntax stat-mode
  (er-macro-transformer
   (lambda (x r c)
     ;; no need to rename here
     (let* ((mode (cadr x))
	    (name (symbol->string mode)))
       `(##core#begin
	 (declare
	   (foreign-declare
	     ,(string-append "#ifndef " name "\n"
			     "#define " name " S_IFREG\n"
			     "#endif\n")))
	 (define-foreign-variable ,mode unsigned-int))))))

(stat-mode S_IFLNK)
(stat-mode S_IFREG)
(stat-mode S_IFDIR)
(stat-mode S_IFCHR)
(stat-mode S_IFBLK)
(stat-mode S_IFSOCK)
(stat-mode S_IFIFO)

(define (stat file link err loc)
  (let ((r (cond ((fixnum? file) (##core#inline "C_u_i_fstat" file))
                 ((port? file) (##core#inline "C_u_i_fstat" (chicken.file.posix#port->fileno file)))
                 ((string? file)
                  (let ((path (##sys#make-c-string file loc)))
		    (if link
			(##core#inline "C_u_i_lstat" path)
			(##core#inline "C_u_i_stat" path))))
                 (else
		  (##sys#signal-hook
		   #:type-error loc "bad argument type - not a fixnum, port or string" file)) ) ) )
    (if (fx< r 0)
	(if err
	    (posix-error #:file-error loc "cannot access file" file) 
	    #f)
	#t)))

(set! chicken.file.posix#file-stat
  (lambda (f #!optional link)
    (stat f link #t 'file-stat)
    (vector _stat_st_ino _stat_st_mode _stat_st_nlink
	    _stat_st_uid _stat_st_gid _stat_st_size
	    _stat_st_atime _stat_st_ctime _stat_st_mtime
	    _stat_st_dev _stat_st_rdev
	    _stat_st_blksize _stat_st_blocks) ) )

(set! chicken.file.posix#set-file-permissions!
  (lambda (f p)
    (##sys#check-fixnum p 'set-file-permissions!)
    (let ((r (cond ((fixnum? f) (##core#inline "C_fchmod" f p))
		   ((port? f) (##core#inline "C_fchmod" (chicken.file.posix#port->fileno f) p))
		   ((string? f)
		    (##core#inline "C_chmod"
				   (##sys#make-c-string f 'set-file-permissions!) p))
		   (else
		    (##sys#signal-hook
		     #:type-error 'file-permissions
		     "bad argument type - not a fixnum, port or string" f)) ) ) )
      (when (fx< r 0)
	(posix-error #:file-error 'set-file-permissions! "cannot change file permissions" f p) ) )))

(set! chicken.file.posix#file-modification-time
  (lambda (f)
    (stat f #f #t 'file-modification-time)
    _stat_st_mtime))
(set! chicken.file.posix#file-access-time
  (lambda (f)
    (stat f #f #t 'file-access-time)
    _stat_st_atime))
(set! chicken.file.posix#file-change-time
  (lambda (f)
    (stat f #f #t 'file-change-time)
    _stat_st_ctime))

(set! chicken.file.posix#set-file-times!
  (lambda (f . rest)
    (let-optionals* rest ((atime (current-seconds)) (mtime atime))
      (when atime (##sys#check-exact-integer atime 'set-file-times!))
      (when mtime (##sys#check-exact-integer mtime 'set-file-times!))
      (let ((r ((foreign-lambda int "set_file_mtime"
		  c-string scheme-object scheme-object)
		f atime mtime)))
	(when (fx< r 0)
	  (apply posix-error
		 #:file-error
		 'set-file-times! "cannot set file times" f rest))))))

(set! chicken.file.posix#file-size
  (lambda (f) (stat f #f #t 'file-size) _stat_st_size))

(set! chicken.file.posix#set-file-owner!
  (lambda (f uid)
    (chown 'set-file-owner! f uid -1)))

(set! chicken.file.posix#set-file-group!
  (lambda (f gid)
    (chown 'set-file-group! f -1 gid)))

(set! chicken.file.posix#file-owner
  (getter-with-setter
   (lambda (f) (stat f #f #t 'file-owner) _stat_st_uid)
   chicken.file.posix#set-file-owner!
   "(chicken.file.posix#file-owner f)") )

(set! chicken.file.posix#file-group
  (getter-with-setter
   (lambda (f) (stat f #f #t 'file-group) _stat_st_gid)
   chicken.file.posix#set-file-group!
   "(chicken.file.posix#file-group f)") )

(set! chicken.file.posix#file-permissions
  (getter-with-setter
   (lambda (f)
     (stat f #f #t 'file-permissions)
     (foreign-value "C_stat_perm" unsigned-int))
   chicken.file.posix#set-file-permissions!
   "(chicken.file.posix#file-permissions f)"))

(set! chicken.file.posix#file-type
  (lambda (file #!optional link (err #t))
    (and (stat file link err 'file-type)
	 (let ((res (foreign-value "C_stat_type" unsigned-int)))
	   (cond
	    ((fx= res S_IFREG) 'regular-file)
	    ((fx= res S_IFLNK) 'symbolic-link)
	    ((fx= res S_IFDIR) 'directory)
	    ((fx= res S_IFCHR) 'character-device)
	    ((fx= res S_IFBLK) 'block-device)
	    ((fx= res S_IFIFO) 'fifo)
	    ((fx= res S_IFSOCK) 'socket)
	    (else 'regular-file))))))

(set! chicken.file.posix#regular-file?
  (lambda (file)
    (eq? 'regular-file (chicken.file.posix#file-type file #f #f))))

(set! chicken.file.posix#symbolic-link?
  (lambda (file)
    (eq? 'symbolic-link (chicken.file.posix#file-type file #t #f))))

(set! chicken.file.posix#block-device?
  (lambda (file)
    (eq? 'block-device (chicken.file.posix#file-type file #f #f))))

(set! chicken.file.posix#character-device?
  (lambda (file)
    (eq? 'character-device (chicken.file.posix#file-type file #f #f))))

(set! chicken.file.posix#fifo?
  (lambda (file)
    (eq? 'fifo (chicken.file.posix#file-type file #f #f))))

(set! chicken.file.posix#socket?
  (lambda (file)
    (eq? 'socket (chicken.file.posix#file-type file #f #f))))

(set! chicken.file.posix#directory?
  (lambda (file)
    (eq? 'directory (chicken.file.posix#file-type file #f #f))))


;;; File position access:

(define-foreign-variable _seek_set int "SEEK_SET")
(define-foreign-variable _seek_cur int "SEEK_CUR")
(define-foreign-variable _seek_end int "SEEK_END")

(set! chicken.file.posix#seek/set _seek_set)
(set! chicken.file.posix#seek/end _seek_end)
(set! chicken.file.posix#seek/cur _seek_cur)

(set! chicken.file.posix#set-file-position!
  (lambda (port pos . whence)
    (let ((whence (if (pair? whence) (car whence) _seek_set)))
      (##sys#check-fixnum pos 'set-file-position!)
      (##sys#check-fixnum whence 'set-file-position!)
      (unless (cond ((port? port)
		     (and-let* ((stream (eq? (##sys#slot port 7) 'stream))
				(res (##core#inline "C_fseek" port pos whence)))
			(##sys#setislot port 6 #f) ;; Reset EOF status
			res))
		    ((fixnum? port)
		     (##core#inline "C_lseek" port pos whence))
		    (else
		     (##sys#signal-hook #:type-error 'set-file-position! "invalid file" port)) )
	(posix-error #:file-error 'set-file-position! "cannot set file position" port pos) ) ) ) )

(set! chicken.file.posix#file-position
  (getter-with-setter
   (lambda (port)
     (let ((pos (cond ((port? port)
		       (if (eq? (##sys#slot port 7) 'stream)
			   (##core#inline_allocate ("C_ftell" 7) port)
			   -1) )
		      ((fixnum? port)
		       (##core#inline "C_lseek" port 0 _seek_cur) )
		      (else
		       (##sys#signal-hook #:type-error 'file-position "invalid file" port)) ) ) )
       (when (< pos 0)
	 (posix-error #:file-error 'file-position "cannot retrieve file position of port" port) )
       pos) )
   chicken.file.posix#set-file-position! ; doesn't accept WHENCE
   "(chicken.file.posix#file-position port)"))


;;; Using file-descriptors:

(define-foreign-variable _stdin_fileno int "STDIN_FILENO")
(define-foreign-variable _stdout_fileno int "STDOUT_FILENO")
(define-foreign-variable _stderr_fileno int "STDERR_FILENO")

(set! chicken.file.posix#fileno/stdin _stdin_fileno)
(set! chicken.file.posix#fileno/stdout _stdout_fileno)
(set! chicken.file.posix#fileno/stderr _stderr_fileno)

(define-foreign-variable _o_rdonly int "O_RDONLY")
(define-foreign-variable _o_wronly int "O_WRONLY")
(define-foreign-variable _o_rdwr int "O_RDWR")
(define-foreign-variable _o_creat int "O_CREAT")
(define-foreign-variable _o_append int "O_APPEND")
(define-foreign-variable _o_excl int "O_EXCL")
(define-foreign-variable _o_trunc int "O_TRUNC")
(define-foreign-variable _o_binary int "O_BINARY")
(define-foreign-variable _o_text int "O_TEXT")

(set! chicken.file.posix#open/rdonly _o_rdonly)
(set! chicken.file.posix#open/wronly _o_wronly)
(set! chicken.file.posix#open/rdwr _o_rdwr)
(set! chicken.file.posix#open/read _o_rdonly)
(set! chicken.file.posix#open/write _o_wronly)
(set! chicken.file.posix#open/creat _o_creat)
(set! chicken.file.posix#open/append _o_append)
(set! chicken.file.posix#open/excl _o_excl)
(set! chicken.file.posix#open/trunc _o_trunc)
(set! chicken.file.posix#open/binary _o_binary)
(set! chicken.file.posix#open/text _o_text)

;; open/noinherit is platform-specific

(define-foreign-variable _s_irusr int "S_IRUSR")
(define-foreign-variable _s_iwusr int "S_IWUSR")
(define-foreign-variable _s_ixusr int "S_IXUSR")
(define-foreign-variable _s_irgrp int "S_IRGRP")
(define-foreign-variable _s_iwgrp int "S_IWGRP")
(define-foreign-variable _s_ixgrp int "S_IXGRP")
(define-foreign-variable _s_iroth int "S_IROTH")
(define-foreign-variable _s_iwoth int "S_IWOTH")
(define-foreign-variable _s_ixoth int "S_IXOTH")
(define-foreign-variable _s_irwxu int "S_IRUSR | S_IWUSR | S_IXUSR")
(define-foreign-variable _s_irwxg int "S_IRGRP | S_IWGRP | S_IXGRP")
(define-foreign-variable _s_irwxo int "S_IROTH | S_IWOTH | S_IXOTH")

(set! chicken.file.posix#perm/irusr _s_irusr)
(set! chicken.file.posix#perm/iwusr _s_iwusr)
(set! chicken.file.posix#perm/ixusr _s_ixusr)
(set! chicken.file.posix#perm/irgrp _s_irgrp)
(set! chicken.file.posix#perm/iwgrp _s_iwgrp)
(set! chicken.file.posix#perm/ixgrp _s_ixgrp)
(set! chicken.file.posix#perm/iroth _s_iroth)
(set! chicken.file.posix#perm/iwoth _s_iwoth)
(set! chicken.file.posix#perm/ixoth _s_ixoth)
(set! chicken.file.posix#perm/irwxu _s_irwxu)
(set! chicken.file.posix#perm/irwxg _s_irwxg)
(set! chicken.file.posix#perm/irwxo _s_irwxo)

;; perm/isvtx, perm/isuid and perm/isgid are platform-specific

(let ()
  (define (mode inp m loc)
    (##sys#make-c-string
     (cond ((pair? m)
            (let ([m (car m)])
              (case m
                ((#:append) (if (not inp) "a" (##sys#error "invalid mode for input file" m)))
                (else (##sys#error "invalid mode argument" m)) ) ) )
           [inp "r"]
           [else "w"] )
     loc) )
  (define (check loc fd inp r)
    (if (##sys#null-pointer? r)
        (posix-error #:file-error loc "cannot open file" fd)
        (let ((port (##sys#make-port (if inp 1 2) ##sys#stream-port-class "(fdport)" 'stream)))
          (##core#inline "C_set_file_ptr" port r)
          port) ) )
  (set! chicken.file.posix#open-input-file*
    (lambda (fd . m)
      (##sys#check-fixnum fd 'open-input-file*)
      (check 'open-input-file* fd #t (##core#inline_allocate ("C_fdopen" 2) fd (mode #t m 'open-input-file*))) ) )
  (set! chicken.file.posix#open-output-file*
    (lambda (fd . m)
      (##sys#check-fixnum fd 'open-output-file*)
      (check 'open-output-file* fd #f (##core#inline_allocate ("C_fdopen" 2) fd (mode #f m 'open-output-file*)) ) ) ) )

(set! chicken.file.posix#port->fileno
  (lambda (port)
    (##sys#check-open-port port 'port->fileno)
    (cond ((eq? 'socket (##sys#slot port 7))
	   ;; Extract socket-FD from the port's "data" object - this is identical
	   ;; to "##sys#tcp-port->fileno" in the tcp unit (tcp.scm). We code it in
	   ;; this low-level manner to avoid depend on code defined there.
	   ;; Peter agrees with that. I think. Have a nice day.
	   (##sys#slot (##sys#port-data port) 0) )
          ((not (zero? (##sys#peek-unsigned-integer port 0)))
           (let ([fd (##core#inline "C_port_fileno" port)])
             (when (fx< fd 0)
               (posix-error #:file-error 'port->fileno "cannot access file-descriptor of port" port) )
             fd) )
          (else (posix-error #:type-error 'port->fileno "port has no attached file" port)) ) ) )

(set! chicken.file.posix#duplicate-fileno
  (lambda (old . new)
    (##sys#check-fixnum old 'duplicate-fileno)
    (let ([fd (if (null? new)
                  (##core#inline "C_dup" old)
                  (let ([n (car new)])
                    (##sys#check-fixnum n 'duplicate-fileno)
                    (##core#inline "C_dup2" old n) ) ) ] )
      (when (fx< fd 0)
        (posix-error #:file-error 'duplicate-fileno "cannot duplicate file-descriptor" old) )
      fd) ) )


;;; Access process ID:

(set! chicken.process-context.posix#current-process-id
  (foreign-lambda int "C_getpid"))


;;; Set or get current directory by file descriptor:

(set! chicken.process-context.posix#change-directory*
  (lambda (fd)
    (##sys#check-fixnum fd 'change-directory*)
    (unless (fx= 0 (##core#inline "C_fchdir" fd))
      (posix-error #:file-error 'change-directory* "cannot change current directory" fd))
    fd))

(set! ##sys#change-directory-hook
  (let ((cd ##sys#change-directory-hook))
    (lambda (dir)
      ((if (fixnum? dir)
	   chicken.process-context.posix#change-directory*
	   cd) dir))))

;;; umask

(set! chicken.file.posix#file-creation-mode
  (getter-with-setter
   (lambda (#!optional um)
     (when um (##sys#check-fixnum um 'file-creation-mode))
     (let ((um2 (##core#inline "C_umask" (or um 0))))
       (unless um (##core#inline "C_umask" um2)) ; restore
       um2))
   (lambda (um)
     (##sys#check-fixnum um 'file-creation-mode)
     (##core#inline "C_umask" um))
   "(chicken.file.posix#file-creation-mode mode)"))


;;; Time related things:

(define decode-seconds (##core#primitive "C_decode_seconds"))

(define (check-time-vector loc tm)
  (##sys#check-vector tm loc)
  (when (fx< (##sys#size tm) 10)
    (##sys#error loc "time vector too short" tm) ) )

(set! chicken.time.posix#seconds->local-time
  (lambda (#!optional (secs (current-seconds)))
    (##sys#check-exact-integer secs 'seconds->local-time)
    (decode-seconds secs #f) ))

(set! chicken.time.posix#seconds->utc-time
  (lambda (#!optional (secs (current-seconds)))
    (##sys#check-exact-integer secs 'seconds->utc-time)
    (decode-seconds secs #t) ) )

(set! chicken.time.posix#seconds->string
  (let ([ctime (foreign-lambda c-string "C_ctime" integer)])
    (lambda (#!optional (secs (current-seconds)))
      (##sys#check-exact-integer secs 'seconds->string)
      (let ([str (ctime secs)])
        (if str
            (##sys#substring str 0 (fx- (##sys#size str) 1))
            (##sys#error 'seconds->string "cannot convert seconds to string" secs) ) ) ) ) )

(set! chicken.time.posix#local-time->seconds
  (let ((tm-size (foreign-value "sizeof(struct tm)" int)))
    (lambda (tm)
      (check-time-vector 'local-time->seconds tm)
      (let ((t (##core#inline_allocate ("C_a_mktime" 7) tm (##sys#make-string tm-size #\nul))))
        (if (= -1 t)
            (##sys#error 'local-time->seconds "cannot convert time vector to seconds" tm)
            t)))))

(set! chicken.time.posix#time->string
  (let ((asctime (foreign-lambda c-string "C_asctime" scheme-object scheme-pointer))
        (strftime (foreign-lambda c-string "C_strftime" scheme-object scheme-object scheme-pointer))
        (tm-size (foreign-value "sizeof(struct tm)" int)))
    (lambda (tm #!optional fmt)
      (check-time-vector 'time->string tm)
      (if fmt
          (begin
            (##sys#check-string fmt 'time->string)
            (or (strftime tm (##sys#make-c-string fmt 'time->string) (##sys#make-string tm-size #\nul))
                (##sys#error 'time->string "time formatting overflows buffer" tm)) )
          (let ([str (asctime tm (##sys#make-string tm-size #\nul))])
            (if str
                (##sys#substring str 0 (fx- (##sys#size str) 1))
                (##sys#error 'time->string "cannot convert time vector to string" tm) ) ) ) ) ) )


;;; Signals

(set! chicken.process.signal#set-signal-handler!   ; DEPRECATED
  (lambda (sig proc)
    (##sys#check-fixnum sig 'set-signal-handler!)
    (##core#inline "C_establish_signal_handler" sig (and proc sig))
    (vector-set! ##sys#signal-vector sig proc) ) )

(set! chicken.process.signal#signal-handler   ; DEPRECATED
  (getter-with-setter
   (lambda (sig)
     (##sys#check-fixnum sig 'signal-handler)
     (##sys#slot ##sys#signal-vector sig) )
   chicken.process.signal#set-signal-handler!
   "(chicken.process.signal#signal-handler sig)"))
                        
(set! chicken.process.signal#make-signal-handler
  (lambda sigs
    (let ((q (##sys#make-event-queue)))
      (for-each
        (lambda (sig)
          (##sys#check-fixnum sig 'make-signal-handler)
          (##core#inline "C_establish_signal_handler" sig sig)
          (vector-set! ##sys#signal-vector sig 
                       (lambda (sig) (##sys#add-event-to-queue! q sig))))
        sigs)
      (lambda (#!optional wait) 
        (if wait
            (##sys#wait-for-next-event q)
            (##sys#get-next-event q))))))
                        
(set! chicken.process.signal#signal-ignore
  (lambda (sig)
    (##sys#check-fixnum sig 'signal-ignore)
    (##core#inline "C_establish_signal_handler" sig #f)
    (vector-set! ##sys#signal-vector sig #f)))

(set! chicken.process.signal#signal-default
  (lambda (sig)
    (##sys#check-fixnum sig 'signal-default)
    (##core#inline "C_establish_signal_handler" sig #t)
    (vector-set! ##sys#signal-vector sig #f)))


;;; Processes

(set! chicken.process#process-sleep
  (lambda (n)
    (##sys#check-fixnum n 'process-sleep)
    (##core#inline "C_i_process_sleep" n)))

(set! chicken.process#process-wait
  (lambda args
    (let-optionals* args ((pid #f) (nohang #f))
      (let ((pid (or pid -1)))
        (##sys#check-fixnum pid 'process-wait)
        (receive (epid enorm ecode) (process-wait-impl pid nohang)
          (if (fx= epid -1)
              (posix-error #:process-error 'process-wait "waiting for child process failed" pid)
              (values epid enorm ecode) ) ) ) ) ) )

;; This can construct argv or envp for process-execute or process-run
(define list->c-string-buffer
  (let ((c-string->allocated-pointer
	 (foreign-lambda* c-pointer ((scheme-object o))
	   "char *ptr = C_malloc(C_header_size(o)); \n"
	   "if (ptr != NULL) {\n"
	   "  C_memcpy(ptr, C_data_pointer(o), C_header_size(o)); \n"
	   "}\n"
	   "C_return(ptr);")))
    (lambda (string-list convert loc)
      (##sys#check-list string-list loc)

      (let* ((string-count (##sys#length string-list))
	     ;; NUL-terminated, so we must add one
	     (buffer (make-pointer-vector (add1 string-count) #f)))

	(handle-exceptions exn
	    ;; Free to avoid memory leak, then reraise
	    (begin (free-c-string-buffer buffer) (signal exn))

	  (do ((sl string-list (cdr sl))
	       (i 0 (fx+ i 1)))
	      ((or (null? sl) (fx= i string-count))) ; Should coincide

	    (##sys#check-string (car sl) loc)
	    ;; This avoids embedded NULs and appends a NUL, so "cs" is
	    ;; safe to copy and use as-is in the pointer-vector.
	    (let* ((cs (##sys#make-c-string (convert (car sl)) loc))
		   (csp (c-string->allocated-pointer cs)))
	      (unless csp (error loc "Out of memory"))
	      (pointer-vector-set! buffer i csp)))

	  buffer)))))

(define (free-c-string-buffer buffer-array)
  (let ((size (pointer-vector-length buffer-array)))
    (do ((i 0 (fx+ i 1)))
	((fx= i size))
      (and-let* ((s (pointer-vector-ref buffer-array i)))
	(free s)))))

;; Environments are represented as string->string association lists
(define (check-environment-list lst loc)
  (##sys#check-list lst loc)
  (for-each
   (lambda (p)
     (##sys#check-pair p loc)
     (##sys#check-string (car p) loc)
     (##sys#check-string (cdr p) loc))
   lst))

(define call-with-exec-args
  (let ((nop (lambda (x) x)))
    (lambda (loc filename argconv arglist envlist proc)
      (let* ((args (cons filename arglist)) ; Add argv[0]
	     (argbuf (list->c-string-buffer args argconv loc))
	     (envbuf #f))

	(handle-exceptions exn
	    ;; Free to avoid memory leak, then reraise
	    (begin (free-c-string-buffer argbuf)
		   (when envbuf (free-c-string-buffer envbuf))
		   (signal exn))

	  ;; Envlist is never converted, so we always use nop here
	  (when envlist
	    (check-environment-list envlist loc)
	    (set! envbuf
	      (list->c-string-buffer
	       (map (lambda (p) (string-append (car p) "=" (cdr p))) envlist)
	       nop loc)))

	  (proc (##sys#make-c-string filename loc) argbuf envbuf))))))

;; Pipes:

(define-foreign-variable _pipe_buf int "PIPE_BUF")
(set! chicken.process#pipe/buf _pipe_buf)

(let ()
  (define (mode arg) (if (pair? arg) (##sys#slot arg 0) #:text))
  (define (badmode m) (##sys#error "illegal input/output mode specifier" m))
  (define (check loc cmd inp r)
    (if (##sys#null-pointer? r)
	(posix-error #:file-error loc "cannot open pipe" cmd)
	(let ((port (##sys#make-port (if inp 1 2) ##sys#stream-port-class "(pipe)" 'stream)))
	  (##core#inline "C_set_file_ptr" port r)
	  port) ) )
  (set! chicken.process#open-input-pipe
    (lambda (cmd . m)
      (##sys#check-string cmd 'open-input-pipe)
      (let ([m (mode m)])
	(check
	 'open-input-pipe
	 cmd #t
	 (case m
	   ((#:text) (##core#inline_allocate ("open_text_input_pipe" 2) (##sys#make-c-string cmd 'open-input-pipe)))
	   ((#:binary) (##core#inline_allocate ("open_binary_input_pipe" 2) (##sys#make-c-string cmd 'open-input-pipe)))
	   (else (badmode m)) ) ) ) ) )
  (set! chicken.process#open-output-pipe
    (lambda (cmd . m)
      (##sys#check-string cmd 'open-output-pipe)
      (let ((m (mode m)))
	(check
	 'open-output-pipe
	 cmd #f
	 (case m
	   ((#:text) (##core#inline_allocate ("open_text_output_pipe" 2) (##sys#make-c-string cmd 'open-output-pipe)))
	   ((#:binary) (##core#inline_allocate ("open_binary_output_pipe" 2) (##sys#make-c-string cmd 'open-output-pipe)))
	   (else (badmode m)) ) ) ) ) )
  (set! chicken.process#close-input-pipe
    (lambda (port)
      (##sys#check-input-port port #t 'close-input-pipe)
      (let ((r (##core#inline "close_pipe" port)))
	(when (eq? -1 r)
	  (posix-error #:file-error 'close-input-pipe "error while closing pipe" port))
	r) ) )
  (set! chicken.process#close-output-pipe
    (lambda (port)
      (##sys#check-output-port port #t 'close-output-pipe)
      (let ((r (##core#inline "close_pipe" port)))
	(when (eq? -1 r)
	  (posix-error #:file-error 'close-output-pipe "error while closing pipe" port))
	r) ) ))

(set! chicken.process#with-input-from-pipe
  (lambda (cmd thunk . mode)
    (let ((p (apply chicken.process#open-input-pipe cmd mode)))
      (fluid-let ((##sys#standard-input p))
	(call-with-values thunk
	  (lambda results
	    (chicken.process#close-input-pipe p)
	    (apply values results) ) ) ) ) ) )

(set! chicken.process#call-with-output-pipe
  (lambda (cmd proc . mode)
    (let ((p (apply chicken.process#open-output-pipe cmd mode)))
      (call-with-values
       (lambda () (proc p))
       (lambda results
	 (chicken.process#close-output-pipe p)
	 (apply values results) ) ) ) ) )

(set! chicken.process#call-with-input-pipe
  (lambda (cmd proc . mode)
    (let ([p (apply chicken.process#open-input-pipe cmd mode)])
      (call-with-values
       (lambda () (proc p))
       (lambda results
	 (chicken.process#close-input-pipe p)
	 (apply values results) ) ) ) ) )

(set! chicken.process#with-output-to-pipe
  (lambda (cmd thunk . mode)
    (let ((p (apply chicken.process#open-output-pipe cmd mode)))
      (fluid-let ((##sys#standard-output p))
	(call-with-values thunk
	  (lambda results
	    (chicken.process#close-output-pipe p)
	    (apply values results) ) ) ) ) ) )
