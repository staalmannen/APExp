;;;; posix.scm - Platform-specific routines
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met:
;
;   Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
;
;   Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in the
;   documentation and/or other materials provided with the distribution.
;
;   Neither the name of the author nor the names of its contributors may
;   be used to endorse or promote products derived from this software
;   without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
; INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
; BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
; OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
; ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
; TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
; USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
; DAMAGE.


(declare
  (unit posix)
  (uses scheduler pathname extras port lolevel)
  (disable-interrupts)
  (not inline ##sys#interrupt-hook ##sys#user-interrupt-hook))


(module chicken.file.posix
  (create-fifo create-symbolic-link read-symbolic-link
   duplicate-fileno fcntl/dupfd fcntl/getfd fcntl/getfl fcntl/setfd
   fcntl/setfl file-access-time file-change-time file-modification-time
   file-close file-control file-creation-mode file-group file-link
   file-lock file-lock/blocking file-mkstemp file-open file-owner
   file-permissions file-position file-read file-select file-size
   file-stat file-test-lock file-truncate file-unlock file-write
   file-type block-device? character-device? directory? fifo?
   regular-file? socket? symbolic-link?
   fileno/stderr fileno/stdin fileno/stdout
   open-input-file* open-output-file*
   open/append open/binary open/creat open/excl open/fsync open/noctty
   open/noinherit open/nonblock open/rdonly open/rdwr open/read
   open/sync open/text open/trunc open/write open/wronly
   perm/irgrp perm/iroth perm/irusr perm/irwxg perm/irwxo perm/irwxu
   perm/isgid perm/isuid perm/isvtx perm/iwgrp perm/iwoth perm/iwusr
   perm/ixgrp perm/ixoth perm/ixusr
   port->fileno set-file-group! set-file-owner!
   set-file-permissions! set-file-position! set-file-times!
   seek/cur seek/set seek/end)

(import scheme)

;; These are all set! inside the posix module
(define create-fifo)
(define create-symbolic-link)
(define read-symbolic-link)
(define duplicate-fileno)

(define fcntl/dupfd)
(define fcntl/getfd)
(define fcntl/getfl)
(define fcntl/setfd)
(define fcntl/setfl)

(define file-access-time)
(define file-change-time)
(define file-modification-time)
(define file-close)
(define file-control)
(define file-creation-mode)
(define file-group)
(define file-link)
(define file-lock)
(define file-lock/blocking)
(define file-mkstemp)
(define file-open)
(define file-owner)
(define file-permissions)
(define file-position)
(define file-read)
(define file-select)
(define file-size)
(define file-stat)
(define file-test-lock)
(define file-truncate)
(define file-unlock)
(define file-write)
(define file-type)

(define block-device?)
(define character-device?)
(define directory?)
(define fifo?)
(define regular-file?)
(define socket?)
(define symbolic-link?)
  
(define fileno/stderr)
(define fileno/stdin)
(define fileno/stdout)
  
(define open-input-file*)
(define open-output-file*)
  
(define open/append)
(define open/binary)
(define open/creat)
(define open/excl)
(define open/fsync)
(define open/noctty)
(define open/noinherit)
(define open/nonblock)
(define open/rdonly)
(define open/rdwr)
(define open/read)
(define open/sync)
(define open/text)
(define open/trunc)
(define open/write)
(define open/wronly)
  
(define perm/irgrp)
(define perm/iroth)
(define perm/irusr)
(define perm/irwxg)
(define perm/irwxo)
(define perm/irwxu)
(define perm/isgid)
(define perm/isuid)
(define perm/isvtx)
(define perm/iwgrp)
(define perm/iwoth)
(define perm/iwusr)
(define perm/ixgrp)
(define perm/ixoth)
(define perm/ixusr)
  
(define port->fileno)

(define seek/cur)
(define seek/end)
(define seek/set)

(define set-file-group!)
(define set-file-owner!)
(define set-file-permissions!)
(define set-file-position!)
(define set-file-times!)
) ; chicken.file.posix


(module chicken.time.posix
  (seconds->utc-time utc-time->seconds seconds->local-time
   seconds->string local-time->seconds string->time time->string
   local-timezone-abbreviation)

(import scheme)

;; These are all set! inside the posix module
(define seconds->utc-time)
(define utc-time->seconds)
(define seconds->local-time)
(define seconds->string)
(define local-time->seconds)
(define string->time)
(define time->string)
(define local-timezone-abbreviation)
) ; chicken.time.posix


(module chicken.process
  (qs system system* process-execute process-fork process-run
   process-signal process-spawn process-wait call-with-input-pipe
   call-with-output-pipe close-input-pipe close-output-pipe create-pipe
   open-input-pipe open-output-pipe with-input-from-pipe
   with-output-to-pipe process process* process-sleep pipe/buf
   spawn/overlay spawn/wait spawn/nowait spawn/nowaito spawn/detach)

(import scheme chicken.base chicken.fixnum chicken.platform)


;;; Execute a shell command:

(define (system cmd)
  (##sys#check-string cmd 'system)
  (let ((r (##core#inline "C_execute_shell_command" cmd)))
    (cond ((fx< r 0)
           (##sys#signal-hook/errno
            #:process-error (##sys#update-errno) 'system "`system' invocation failed" cmd))
	  (else r))))

;;; Like `system', but bombs on nonzero return code:

(define (system* str)
  (let ((n (system str)))
    (unless (zero? n)
      (##sys#error "shell invocation failed with non-zero return status" str n))))


;;; Quote string for shell:

(define (qs str #!optional (platform (software-version)))
  (let* ((delim (if (eq? platform 'mingw32) #\" #\'))
	 (escaped (if (eq? platform 'mingw32) "\"\"" "'\\''"))
	 (escaped-parts
	  (map (lambda (c)
		 (cond
		   ((char=? c delim) escaped)
		   ((char=? c #\nul)
		    (error 'qs "NUL character can not be represented in shell string" str))
		   (else (string c))))
	       (string->list str))))
    (string-append
     (string delim)
     (apply string-append escaped-parts)
     (string delim))))


;; These are all set! inside the posix module
(define process-execute)
(define process-fork)
(define process-run)
(define process-signal)
(define process-spawn)
(define process-wait)

(define call-with-input-pipe)
(define call-with-output-pipe)
(define close-input-pipe)
(define close-output-pipe)
(define create-pipe)
(define open-input-pipe)
(define open-output-pipe)
(define with-input-from-pipe)
(define with-output-to-pipe)

(define process)
(define process*)
(define process-sleep)

(define pipe/buf)

(define spawn/overlay)
(define spawn/wait)
(define spawn/nowait)
(define spawn/nowaito)
(define spawn/detach)
) ; chicken.process


(module chicken.process.signal
  (set-alarm! set-signal-mask!
   make-signal-handler signal-ignore signal-default
   set-signal-handler! signal-handler ; DEPRECATED
   signal-mask signal-mask! signal-masked? signal-unmask!
   signal/abrt signal/alrm signal/break signal/bus signal/chld
   signal/cont signal/fpe signal/hup signal/ill signal/int signal/io
   signal/kill signal/pipe signal/prof signal/quit signal/segv
   signal/stop signal/term signal/trap signal/tstp signal/urg
   signal/usr1 signal/usr2 signal/vtalrm signal/winch signal/xcpu
   signal/xfsz signals-list)

(import scheme)

;; These are all set! inside the posix module
(define set-alarm!)
(define set-signal-handler!) ; DEPRECATED
(define set-signal-mask!)
(define signal-handler) ; DEPRECATED
(define make-signal-handler)
(define signal-ignore)
(define signal-default)

(define signal-mask)
(define signal-mask!)
(define signal-masked?)
(define signal-unmask!)

(define signal/abrt)
(define signal/alrm)
(define signal/break)
(define signal/bus)
(define signal/chld)
(define signal/cont)
(define signal/fpe)
(define signal/hup)
(define signal/ill)
(define signal/int)
(define signal/io)
(define signal/kill)
(define signal/pipe)
(define signal/prof)
(define signal/quit)
(define signal/segv)
(define signal/stop)
(define signal/term)
(define signal/trap)
(define signal/tstp)
(define signal/urg)
(define signal/usr1)
(define signal/usr2)
(define signal/vtalrm)
(define signal/winch)
(define signal/xcpu)
(define signal/xfsz)

(define signals-list)
) ; chicken.process.signal


(module chicken.process-context.posix
  (change-directory* set-root-directory!
   current-effective-group-id current-effective-user-id
   current-process-id current-group-id current-user-id
   parent-process-id current-user-name
   current-effective-user-name create-session
   process-group-id user-information)

(import scheme)

(define change-directory*)
(define set-root-directory!)
(define current-effective-group-id)
(define current-effective-user-id)
(define current-group-id)
(define current-user-id)
(define current-process-id)
(define parent-process-id)
(define current-user-name)
(define current-effective-user-name)
(define create-session)
(define process-group-id)
(define user-information)
) ; chicken.process-context.posix


;; This module really exports nothing.  It is used to keep all the
;; posix stuff in one place, in a clean namespace.  The included file
;; will set! values from the modules defined above.
(module chicken.posix ()

(import scheme
	chicken.base
	chicken.bitwise
	chicken.condition
	chicken.fixnum
	chicken.foreign
	chicken.memory
	chicken.pathname
	chicken.port
	chicken.process-context
	chicken.time)

(cond-expand
  (platform-unix
   (include "posixunix.scm"))
  (platform-windows
   (include "posixwin.scm")))

) ; chicken.posix [internal, no implib generated]


(module chicken.errno *
(import scheme)
(define (errno) (##sys#errno))
(define errno/2big _e2big)
(define errno/acces _eacces)
(define errno/again _eagain)
(define errno/badf _ebadf)
(define errno/busy _ebusy)
(define errno/child _echild)
(define errno/deadlk _edeadlk)
(define errno/dom _edom)
(define errno/exist _eexist)
(define errno/fault _efault)
(define errno/fbig _efbig)
(define errno/ilseq _eilseq)
(define errno/intr _eintr)
(define errno/inval _einval)
(define errno/io _eio)
(define errno/isdir _eisdir)
(define errno/mfile _emfile)
(define errno/mlink _emlink)
(define errno/nametoolong _enametoolong)
(define errno/nfile _enfile)
(define errno/nodev _enodev)
(define errno/noent _enoent)
(define errno/noexec _enoexec)
(define errno/nolck _enolck)
(define errno/nomem _enomem)
(define errno/nospc _enospc)
(define errno/nosys _enosys)
(define errno/notdir _enotdir)
(define errno/notempty _enotempty)
(define errno/notty _enotty)
(define errno/nxio _enxio)
(define errno/perm _eperm)
(define errno/pipe _epipe)
(define errno/range _erange)
(define errno/rofs _erofs)
(define errno/spipe _espipe)
(define errno/srch _esrch)
(define errno/wouldblock _ewouldblock)
(define errno/xdev _exdev)
) ; chicken.errno
