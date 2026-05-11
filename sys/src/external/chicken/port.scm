;;; port.scm - Optional non-standard ports
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
;   Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
;   Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in
;   the documentation and/or other materials provided with the
;   distribution.
;   Neither the name of the author nor the names of its contributors
;   may be used to endorse or promote products derived from this
;   software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
; FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
; COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
; INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
; STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
; OF THE POSSIBILITY OF SUCH DAMAGE.


(declare
  (unit port)
  (uses extras))

(module chicken.port
  (call-with-input-string
   call-with-output-string
   copy-port
   make-input-port
   make-output-port
   port-fold
   port-for-each
   port-map
   port-name
   port-position
   make-bidirectional-port
   make-broadcast-port
   make-concatenated-port
   set-buffering-mode!
   set-port-name!
   terminal-name
   terminal-port?
   terminal-size
   with-error-output-to-port
   with-input-from-port
   with-input-from-string
   with-output-to-port
   with-output-to-string
   with-error-output-to-string)

(import scheme
	chicken.base
	chicken.fixnum
	chicken.foreign
	chicken.io)

(include "common-declarations.scm")

#>

#if !defined(_WIN32)
# include <sys/ioctl.h>
# include <termios.h>
#endif

#if !defined(__ANDROID__) && defined(TIOCGWINSZ)
static int get_tty_size(int fd, int *rows, int *cols)
{
  struct winsize tty_size;
  int r;

  memset(&tty_size, 0, sizeof tty_size);

  r = ioctl(fd, TIOCGWINSZ, &tty_size);
  if (r == 0) {
     *rows = tty_size.ws_row;
     *cols = tty_size.ws_col;
  }
  return r;
}
#else
static int get_tty_size(int fd, int *rows, int *cols)
{
  *rows = *cols = 0;
  errno = ENOSYS;
  return -1;
}
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
char *ttyname(int fd) {
  errno = ENOSYS;
  return NULL;
}
#endif

<#


(define-foreign-variable _iofbf int "_IOFBF")
(define-foreign-variable _iolbf int "_IOLBF")
(define-foreign-variable _ionbf int "_IONBF")
(define-foreign-variable _bufsiz int "BUFSIZ")

(define (port-name #!optional (port ##sys#standard-input))
  (##sys#check-port port 'port-name)
  (##sys#slot port 3))

(define (set-port-name! port name)
  (##sys#check-port port 'set-port-name!)
  (##sys#check-string name 'set-port-name!)
  (##sys#setslot port 3 name))

(define (port-position #!optional (port ##sys#standard-input))
  (##sys#check-port port 'port-position)
  (if (##core#inline "C_input_portp" port)
      (##sys#values (##sys#slot port 4) (##sys#slot port 5))
      (##sys#error 'port-position "cannot compute position of port" port)))

(define (set-buffering-mode! port mode . size)
  (##sys#check-port port 'set-buffering-mode!)
  (let ((size (if (pair? size) (car size) _bufsiz))
	(mode (case mode
		((#:full) _iofbf)
		((#:line) _iolbf)
		((#:none) _ionbf)
		(else (##sys#error 'set-buffering-mode! "invalid buffering-mode" mode port)))))
    (##sys#check-fixnum size 'set-buffering-mode!)
    (when (fx< (if (eq? 'stream (##sys#slot port 7))
		   ((foreign-lambda* int ((scheme-object p) (int m) (int s))
		     "C_return(setvbuf(C_port_file(p), NULL, m, s));")
		    port mode size)
		   -1)
	       0)
      (##sys#error 'set-buffering-mode! "cannot set buffering mode" port mode size))))

;;;; Port-mapping (found in Gauche):

(define (port-for-each fn thunk)
  (let loop ()
    (let ((x (thunk)))
      (unless (eof-object? x)
	(fn x)
	(loop) ) ) ) )

(define port-map
  (lambda (fn thunk)
    (let loop ((xs '()))
      (let ((x (thunk)))
	(if (eof-object? x)
	    (##sys#fast-reverse xs)
	    (loop (cons (fn x) xs)))))))

(define (port-fold fn acc thunk)
  (let loop ((acc acc))
    (let ((x (thunk)))
      (if (eof-object? x)
          acc
          (loop (fn x acc))) ) ) )

(define-constant +buf-size+ 1024)

(define copy-port 
  (let ((read-char read-char)
	(write-char write-char))
    (define (read-buf port writer)
      (let ((buf (make-string +buf-size+)))
	(let loop ()
	  (let ((n (read-string! +buf-size+ buf port)))
	    (unless (eq? n 0)
	      (writer buf n)
	      (loop))))))
    (define (write-buf buf n port writer)
      (do ((i 0 (fx+ i 1)))
	  ((fx>= i n))
	(writer (integer->char (##sys#byte buf i)) port)))
    (define (read-and-write reader writer)
      (let loop ()
	(let ((x (reader)))
	  (unless (eof-object? x)
	    (writer x)
	    (loop)))))
    (define (read-and-write-buf src dest reader)
      (let ((buf (make-string +buf-size+)))
	(let loop ((n 0))
	  (when (fx>= n +buf-size+)
	    (write-string buf +buf-size+ dest)
	    (set! n 0))
	  (let ((c (reader src)))
	    (cond ((eof-object? c)
		   (when (fx>= n 0)
		     (write-string buf n dest)))
		  (else
		   (##sys#setbyte buf n (char->integer c))
		   (loop (fx+ n 1))))))))
    (lambda (src dest #!optional (read read-char) (write write-char))
      ;; does not check port args intentionally
      (cond ((eq? read read-char)
	     (read-buf
	      src
	      (if (eq? write write-char)
		  (lambda (buf n) (write-string buf n dest))
		  (lambda (buf n) (write-buf buf n dest write)))))
	    ((eq? write write-char)
	     (read-and-write-buf src dest read))
	    (else
	     (read-and-write 
	      (lambda () (read src))
	      (lambda (x) (write x dest))))))))


;;;; funky-ports

(define (make-broadcast-port . ports)
  (make-output-port
   (lambda (s) (for-each (cut write-string s #f <>) ports))
   void
   (lambda () (for-each flush-output ports)) ) )

(define (make-concatenated-port p1 . ports)
  (let ((ports (cons p1 ports)))
    ;;XXX should also forward other port-methods
    (make-input-port
     (lambda ()
       (let loop ()
	 (if (null? ports)
	     #!eof
	     (let ((c (read-char (car ports))))
	       (cond ((eof-object? c)
		      (set! ports (cdr ports))
		      (loop) )
		     (else c) ) ) ) ) )
     (lambda ()
       (and (not (null? ports))
	    (char-ready? (car ports))))
     void
     (lambda ()
       (let loop ()
	 (if (null? ports)
	     #!eof
	     (let ((c (peek-char (car ports))))
	       (cond ((eof-object? c)
		      (set! ports (cdr ports))
		      (loop) )
		     (else c))))))
     (lambda (p n dest start)
       (let loop ((n n) (c 0))
	 (cond ((null? ports) c)
	       ((fx<= n 0) c)
	       (else
		(let ((m (read-string! n dest (car ports) (fx+ start c))))
		  (when (fx< m n)
		    (set! ports (cdr ports)) )
		  (loop (fx- n m) (fx+ c m))))))))))


;;; Redirect standard ports:

(define (with-input-from-port port thunk)
  (##sys#check-input-port port #t 'with-input-from-port)
  (fluid-let ((##sys#standard-input port))
    (thunk) ) )

(define (with-output-to-port port thunk)
  (##sys#check-output-port port #t 'with-output-to-port)
  (fluid-let ((##sys#standard-output port))
    (thunk) ) )

(define (with-error-output-to-port port thunk)
  (##sys#check-output-port port #t 'with-error-output-to-port)
  (fluid-let ((##sys#standard-error port))
    (thunk) ) )

;;; Extended string-port operations:
  
(define call-with-input-string 
  (lambda (str proc)
    (let ((in (open-input-string str)))
      (proc in) ) ) )

(define call-with-output-string
  (lambda (proc)
    (let ((out (open-output-string)))
      (proc out)
      (get-output-string out) ) ) )

(define with-input-from-string
  (lambda (str thunk)
    (fluid-let ([##sys#standard-input (open-input-string str)])
      (thunk) ) ) )

(define with-output-to-string
  (lambda (thunk)
    (fluid-let ((##sys#standard-output (open-output-string)))
      (thunk) 
      (get-output-string ##sys#standard-output) ) ) )

(define with-error-output-to-string
  (lambda (thunk)
    (fluid-let ((##sys#standard-error (open-output-string)))
      (thunk)
      (get-output-string ##sys#standard-error) ) ) )

;;; Custom ports:
;
; - Port-slots:
;
;   10: last

(define make-input-port
  (lambda (read ready? close #!optional peek read-string read-line read-buffered)
    (let* ((class
	    (vector 
	     (lambda (p)		; read-char
	       (let ([last (##sys#slot p 10)])
		 (cond [peek (read)]
		       [last
			(##sys#setislot p 10 #f)
			last]
		       [else (read)] ) ) )
	     (lambda (p)		; peek-char
	       (let ([last (##sys#slot p 10)])
		 (cond [peek (peek)]
		       [last last]
		       [else
			(let ([last (read)])
			  (##sys#setslot p 10 last)
			  last) ] ) ) )
	     #f				; write-char
	     #f				; write-string
	     (lambda (p d)		; close
	       (close))
	     #f				; flush-output
	     (lambda (p)		; char-ready?
	       (ready?) )
	     read-string		; read-string!
	     read-line			; read-line
	     read-buffered))
	   (data (vector #f))
	   (port (##sys#make-port 1 class "(custom)" 'custom)))
      (##sys#set-port-data! port data) 
      port) ) )

(define make-output-port
  (lambda (write close #!optional flush)
    (let* ((class
	    (vector
	     #f				; read-char
	     #f				; peek-char
	     (lambda (p c)		; write-char
	       (write (string c)) )
	     (lambda (p s)		; write-string
	       (write s) )
	     (lambda (p d)		; close
	       (close))
	     (lambda (p)		; flush-output
	       (when flush (flush)) )
	     #f				; char-ready?
	     #f				; read-string!
	     #f) )			; read-line
	   (data (vector #f))
	   (port (##sys#make-port 2 class "(custom)" 'custom)))
      (##sys#set-port-data! port data) 
      port) ) )

(define (make-bidirectional-port i o)
  (let* ((class (vector
		 (lambda (_)             ; read-char
		   (read-char i))
		 (lambda (_)             ; peek-char
		   (peek-char i))
		 (lambda (_ c)           ; write-char
		   (write-char c o))
		 (lambda (_ s)           ; write-string
		   (write-string s #f o))
		 (lambda (_ d)           ; close
		   (case d
		     ((1) (close-input-port i))
		     ((2) (close-output-port o))))
		 (lambda (_)             ; flush-output
		   (flush-output o))
		 (lambda (_)             ; char-ready?
		   (char-ready? i))
		 (lambda (_ n d s)       ; read-string!
		   (read-string! n d i s))
		 (lambda (_ l)           ; read-line
		   (read-line i l))
		 (lambda ()              ; read-buffered
		   (read-buffered i))))
	 (port (##sys#make-port 3 class "(bidirectional)" 'bidirectional)))
    (##sys#set-port-data! port (vector #f))
    port))

;; Duplication from posix-common.scm
(define posix-error
  (let ((strerror (foreign-lambda c-string "strerror" int))
	(string-append string-append))
    (lambda (type loc msg . args)
      (let ((rn (##sys#update-errno)))
        (apply ##sys#signal-hook/errno
               type rn loc (string-append msg " - " (strerror rn)) args)))))

;; Terminal ports
(define (terminal-port? port)
  (##sys#check-open-port port 'terminal-port?)
  (let ((fp (##sys#peek-unsigned-integer port 0)))
    (and (not (eq? 0 fp)) (##core#inline "C_tty_portp" port))))

(define (check-terminal! caller port)
  (##sys#check-open-port port caller)
  (unless (and (eq? 'stream (##sys#slot port 7))
	       (##core#inline "C_tty_portp" port))
    (##sys#error caller "port is not connected to a terminal" port)))

(define terminal-name
  (let ((ttyname (foreign-lambda c-string "ttyname" int)))
    (lambda (port)
      (check-terminal! 'terminal-name port)
      (or (ttyname (##core#inline "C_port_fileno" port))
	  (posix-error #:error 'terminal-name
		       "cannot determine terminal name" port)))))

(define terminal-size
  (let ((ttysize (foreign-lambda int "get_tty_size" int
				 (nonnull-c-pointer int)
				 (nonnull-c-pointer int))))
    (lambda (port)
      (check-terminal! 'terminal-size port)
      (let-location ((columns int)
		     (rows int))
	(if (fx= 0 (ttysize (##core#inline "C_port_fileno" port)
			    (location columns)
			    (location rows)))
	    (values columns rows)
	    (posix-error #:error 'terminal-size
			 "cannot determine terminal size" port))))))

)
