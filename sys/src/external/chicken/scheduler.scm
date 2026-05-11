; scheduler.scm - Basic scheduler for multithreading
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


(declare
  (unit scheduler)
  (uses extras) ; for sprintf
  (disable-interrupts)
  (hide ready-queue-head ready-queue-tail timeout-list fd-list
	##sys#update-thread-state-buffer ##sys#restore-thread-state-buffer
	##sys#unblock-threads-for-i/o
	;; This isn't hidden ATM to allow set!ing it as a hook/workaround
	; ##sys#force-primordial
	remove-from-ready-queue fdset-test create-fdset stderr delq
	##sys#clear-i/o-state-for-thread! ##sys#abandon-mutexes) 
  (not inline chicken.base#sleep-hook ##sys#interrupt-hook ##sys#force-primordial)
  (unsafe)
  (foreign-declare #<<EOF
#ifdef HAVE_ERRNO_H
# include <errno.h>
# define C_signal_interrupted_p     C_mk_bool(errno == EINTR)
#else
# define C_signal_interrupted_p     C_SCHEME_FALSE
#endif

#ifdef _WIN32
/* TODO: Winsock select() only works for sockets */
# include <winsock2.h>
/* Beware: winsock2.h must come BEFORE windows.h */
# define C_msleep(n)   (Sleep((DWORD)C_num_to_uint64(n)), C_SCHEME_TRUE)
#else
# include <sys/time.h>
static C_word C_msleep(C_word ms);
C_word C_msleep(C_word ms) {
#ifdef __CYGWIN__
  if(usleep((useconds_t)C_num_to_uint64(ms) * 1000) == -1) return C_SCHEME_FALSE;
#else
  struct timespec ts;
  C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab,
         sec = C_s_a_u_i_integer_quotient(&a, 2, ms, C_fix(1000)),
         msec = C_s_a_u_i_integer_remainder(&a, 2, ms, C_fix(1000));
  ts.tv_sec = (time_t)C_num_to_uint64(sec);
  ts.tv_nsec = (long)C_unfix(msec) * 1000000;
  
  if(nanosleep(&ts, NULL) == -1) return C_SCHEME_FALSE;
#endif
  return C_SCHEME_TRUE;
}
#endif

#ifdef NO_POSIX_POLL

/* Shouldn't we include <sys/select.h> here? */
static fd_set C_fdset_input, C_fdset_output;

#define C_fd_input_ready(fd,pos)  C_mk_bool(FD_ISSET(C_unfix(fd), &C_fdset_input))
#define C_fd_output_ready(fd,pos)  C_mk_bool(FD_ISSET(C_unfix(fd), &C_fdset_output))

inline static int C_ready_fds_timeout(int to, unsigned int tm) {
  struct timeval timeout;
  timeout.tv_sec = tm / 1000;
  timeout.tv_usec = fmod(tm, 1000) * 1000;
  /* we use FD_SETSIZE, but really should use max fd */
  return select(FD_SETSIZE, &C_fdset_input, &C_fdset_output, NULL, to ? &timeout : NULL);
}

inline static void C_prepare_fdset(int length) {
  FD_ZERO(&C_fdset_input);
  FD_ZERO(&C_fdset_output);
}

inline static void C_fdset_add(int fd, int input, int output) {
  if (input) FD_SET(fd, &C_fdset_input);
  if (output) FD_SET(fd, &C_fdset_output);
}

#else
#  include <poll.h>
#  include <assert.h>

static int C_fdset_nfds;
static struct pollfd *C_fdset_set = NULL;

inline static int C_fd_ready(int fd, int pos, int what) {
  assert(fd == C_fdset_set[pos].fd); /* Must match position in fd-list! */
  return(C_fdset_set[pos].revents & what);
}

#define C_fd_input_ready(fd,pos)  C_mk_bool(C_fd_ready(C_unfix(fd), C_unfix(pos),POLLIN|POLLERR|POLLHUP|POLLNVAL))
#define C_fd_output_ready(fd,pos)  C_mk_bool(C_fd_ready(C_unfix(fd), C_unfix(pos),POLLOUT|POLLERR|POLLHUP|POLLNVAL))

inline static int C_ready_fds_timeout(int to, unsigned int tm) {
  return poll(C_fdset_set, C_fdset_nfds, to ? tm : -1);
}

inline static void C_prepare_fdset(int length) {
  /* TODO: Only realloc when needed? */
  C_fdset_set = realloc(C_fdset_set, sizeof(struct pollfd) * length);
  if (C_fdset_set == NULL)
    C_halt(C_SCHEME_FALSE); /* Ugly: no message */
  C_fdset_nfds = 0;
}

/* This *must* be called in order, so position will match fd-list */
inline static void C_fdset_add(int fd, int input, int output) {
  C_fdset_set[C_fdset_nfds].events = ((input ? POLLIN : 0) | (output ? POLLOUT : 0));
  C_fdset_set[C_fdset_nfds++].fd = fd;
}
#endif
EOF
) )

(import scheme chicken.base chicken.fixnum chicken.format chicken.condition)

(include "common-declarations.scm")

#;(begin
  (define stderr ##sys#standard-error) ; use default stderr port
  (define (dbg . args)
    (parameterize ((##sys#print-length-limit #f))
      (for-each
       (lambda (x)
	 (display x stderr))
       args)
      (newline stderr))))

(define-syntax dbg
  (syntax-rules ()
    ((_ . _) #f))) 

(define-syntax panic
  (syntax-rules ()
    ((_ msg) (##core#inline "C_halt" msg))))

(define (delq x lst)
  (let loop ([lst lst])
    (cond ((null? lst) lst)
	  ((eq? x (##sys#slot lst 0)) (##sys#slot lst 1))
	  (else (cons (##sys#slot lst 0) (loop (##sys#slot lst 1)))) ) ) )


(define (##sys#schedule)
  (define (switch thread)
    (dbg "switching to " thread)
    (set! ##sys#current-thread thread)
    (##sys#setslot thread 3 'running)
    (##sys#restore-thread-state-buffer thread)
    ;;XXX WRONG! this sets the t/i-period ("quantum") for the _next_ thread
    (##core#inline "C_set_initial_timer_interrupt_period" (##sys#slot thread 9))
    ;; Call upon ye ancient gods to forget about the current
    ;; continuation; it still refers to the old thread (#1367).
    (##sys#call-with-cthulhu (##sys#slot thread 1)) )
  (let* ([ct ##sys#current-thread]
	 [eintr #f]
	 [cts (##sys#slot ct 3)] )
    (dbg "==================== scheduling, current: " ct ", ready: " ready-queue-head)
    (##sys#update-thread-state-buffer ct)
    ;; Put current thread on ready-queue:
    (when (or (eq? cts 'running) (eq? cts 'ready)) ; should ct really be 'ready? - normally not.
      (##sys#setislot ct 13 #f)			   ; clear timeout-unblock flag
      (##sys#add-to-ready-queue ct) )
    (let loop1 ()
      ;; Unblock threads waiting for timeout:
      (unless (null? timeout-list)
	(let ((now (##core#inline_allocate ("C_a_i_current_process_milliseconds" 7) #f)))
	  (let loop ((lst timeout-list))
	    (if (null? lst)
		(set! timeout-list '())
		(let* ([tmo1 (caar lst)] ; timeout of thread on list
		       [tto (cdar lst)]	 ; thread on list
		       [tmo2 (##sys#slot tto 4)] ) ; timeout value stored in thread
		  (dbg "timeout: " tto " -> " tmo2 " (now: " now ")")
		  (if (equal? tmo1 tmo2)  ;XXX why do we check this?
		      (if (>= now tmo1) ; timeout reached?
			  (begin
			    (##sys#setislot tto 13 #t) ; mark as being unblocked by timeout
			    (##sys#clear-i/o-state-for-thread! tto)
			    (##sys#thread-basic-unblock! tto)
			    (loop (cdr lst)) )
			  (begin
			    (set! timeout-list lst) 
			    ;; If there are no threads blocking on a select call (fd-list)
			    ;; but there are threads in the timeout list then sleep for
			    ;; the number of milliseconds of next thread to wake up.
			    (when (and (null? ready-queue-head)
				       (null? fd-list) 
				       (pair? timeout-list))
			      (let* ((tmo1 (caar timeout-list))
				     (tmo1 (inexact->exact (round tmo1))))
				(set! eintr
				  (and (not (##core#inline 
					     "C_msleep" 
					     (max 0 (- tmo1 now))))
				       (foreign-value
					"C_signal_interrupted_p" bool) ) ) ) ) ) )
		      (loop (cdr lst)) ) ) ) ) ) )
      ;; Unblock threads blocked by I/O:
      (if eintr
          (begin
	    (##sys#update-thread-state-buffer ct)
	    (##sys#force-primordial))	; force it to handle user-interrupt
	  (unless (null? fd-list)
	    (##sys#unblock-threads-for-i/o) ) )
      ;; Fetch and activate next ready thread:
      (let loop2 ()
	(let ([nt (remove-from-ready-queue)])
	  (cond [(not nt) 
		 (if (and (null? timeout-list) (null? fd-list))
		     (panic "deadlock")
		     (loop1) ) ]
		[(eq? (##sys#slot nt 3) 'ready) (switch nt)]
		[else (loop2)] ) ) ) ) ) )

(define (##sys#force-primordial)
  (dbg "primordial thread forced due to interrupt")
  (##sys#setislot ##sys#primordial-thread 13 #f)
  (##sys#thread-unblock! ##sys#primordial-thread) )

(define ready-queue-head '())
(define ready-queue-tail '())

(define (##sys#ready-queue) ready-queue-head)

(define (##sys#add-to-ready-queue thread)
  (##sys#setslot thread 3 'ready)
  (let ((new-pair (cons thread '())))
    (cond ((eq? '() ready-queue-head) 
	   (set! ready-queue-head new-pair))
	  (else (set-cdr! ready-queue-tail new-pair)) )
    (set! ready-queue-tail new-pair) ) )

(define (remove-from-ready-queue)
  (let ((first-pair ready-queue-head))
    (and (not (null? first-pair))
	 (let ((first-cdr (cdr first-pair)))
	   (set! ready-queue-head first-cdr)
	   (when (eq? '() first-cdr) (set! ready-queue-tail '()))
	   (car first-pair) ) ) ) )

(define (##sys#update-thread-state-buffer thread)
  (let ([buf (##sys#slot thread 5)])
    (##sys#setslot buf 0 ##sys#dynamic-winds)
    (##sys#setslot buf 1 ##sys#standard-input)
    (##sys#setslot buf 2 ##sys#standard-output)
    (##sys#setslot buf 3 ##sys#standard-error)
    (##sys#setslot buf 4 ##sys#current-exception-handler)
    (##sys#setslot buf 5 ##sys#current-parameter-vector) ) )

(define (##sys#restore-thread-state-buffer thread)
  (let ([buf (##sys#slot thread 5)])
    (set! ##sys#dynamic-winds (##sys#slot buf 0))
    (set! ##sys#standard-input (##sys#slot buf 1))
    (set! ##sys#standard-output (##sys#slot buf 2))
    (set! ##sys#standard-error (##sys#slot buf 3)) 
    (set! ##sys#current-exception-handler (##sys#slot buf 4))
    (set! ##sys#current-parameter-vector (##sys#slot buf 5)) ) )

(set! ##sys#interrupt-hook
  (let ([oldhook ##sys#interrupt-hook])
    (lambda (reason state)
      (when (fx= reason 255)		; C_TIMER_INTERRUPT_NUMBER
	(let ([ct ##sys#current-thread])
	  (##sys#setslot ct 1 (lambda () (oldhook reason state))) 
	  (##sys#schedule) ) )		; expected not to return!
      (oldhook reason state) ) ) )

(define timeout-list '())

(define (##sys#timeout-queue) timeout-list)

(define (##sys#remove-from-timeout-list t)
  (let loop ((l timeout-list) (prev #f))
    (if (null? l)
	l
	(let ((h (##sys#slot l 0))
	      (r (##sys#slot l 1)))
	  (if (eq? (##sys#slot h 1) t)
	      (if prev
		  (set-cdr! prev r)
		  (set! timeout-list r))
	      (loop r l))))))

(define (##sys#thread-block-for-timeout! t tm)
  (dbg t " blocks for timeout " tm)
  (when (> tm 0)
    ;; This should really use a balanced tree:
    (let loop ([tl timeout-list] [prev #f])
      (if (or (null? tl) (< tm (caar tl)))
	  (if prev
	      (set-cdr! prev (cons (cons tm t) tl))
	      (set! timeout-list (cons (cons tm t) tl)) )
	  (loop (cdr tl) tl) ) ) 
    (##sys#setslot t 3 'blocked)
    (##sys#setislot t 13 #f)
    (##sys#setslot t 4 tm) ) )

(define (##sys#thread-block-for-termination! t t2)
  (dbg t " blocks for " t2)
  (let ([state (##sys#slot t2 3)])
    (unless (or (eq? state 'dead) (eq? state 'terminated))
      (##sys#setslot t2 12 (cons t (##sys#slot t2 12)))
      (##sys#setslot t 3 'blocked) 
      (##sys#setislot t 13 #f)
      (##sys#setslot t 11 t2) ) ) )

(define (##sys#abandon-mutexes thread)
  (let ((ms (##sys#slot thread 8)))
    (unless (null? ms)
      (##sys#for-each
       (lambda (m)
	 (##sys#setislot m 2 #f)
	 (##sys#setislot m 4 #t) 
	 (##sys#setislot m 5 #f)
	 (let ((wts (##sys#slot m 3)))
	   (unless (null? wts)
	     (for-each
	      (lambda (t2)
		(dbg "  unblocking: " t2)
		(##sys#thread-unblock! t2) )
	      wts) ) )
	 (##sys#setislot m 3 '()) )
       ms) ) ) )

(define (##sys#thread-kill! t s)
  (dbg "killing: " t " -> " s ", recipients: " (##sys#slot t 12))
  (##sys#abandon-mutexes t)
  (let ((blocked (##sys#slot t 11)))
    (cond
     ((##sys#structure? blocked 'condition-variable)
      (##sys#setslot blocked 2 (delq t (##sys#slot blocked 2))))
     ((##sys#structure? blocked 'thread)
      (##sys#setslot blocked 12 (delq t (##sys#slot blocked 12))))) )
  (##sys#remove-from-timeout-list t)
  (##sys#clear-i/o-state-for-thread! t)
  (##sys#setslot t 3 s)
  (##sys#setislot t 4 #f)
  (##sys#setislot t 11 #f)
  (##sys#setislot t 8 '())
  (let ((rs (##sys#slot t 12)))
    (unless (null? rs)
      (for-each
       (lambda (t2)
	 (dbg "  checking: " t2 " (" (##sys#slot t2 3) ") -> " (##sys#slot t2 11))
	 (when (eq? (##sys#slot t2 11) t)
	   (##sys#thread-basic-unblock! t2) ) )
       rs) ) )
  (##sys#setislot t 12 '()) )

(define (##sys#thread-basic-unblock! t)
  (dbg "unblocking: " t)
  (##sys#setislot t 11 #f)		; (FD . RWFLAGS) | #<MUTEX> | #<THREAD>
  (##sys#setislot t 4 #f)
  (##sys#add-to-ready-queue t) )

(define (##sys#default-exception-handler arg)
  (let ([ct ##sys#current-thread])
    (dbg "exception: " ct " -> " 
	 (if (##sys#structure? arg 'condition) (##sys#slot arg 2) arg))
    (cond ((foreign-value "C_abort_on_thread_exceptions" bool)
	   (let* ([pt ##sys#primordial-thread]
		  [ptx (##sys#slot pt 1)] )
	     (##sys#setslot 
	      pt 1 
	      (lambda ()
		(signal arg)
		(ptx) ) )
	     (##sys#thread-unblock! pt) ) )
	  (else
	   (##sys#show-exception-warning arg "in thread" ct)))
    (##sys#setslot ct 7 arg)
    (##sys#thread-kill! ct 'terminated)
    (##sys#schedule) ) )


;;; `select()/poll()'-based blocking:

(define fd-list '())		; ((FD1 THREAD1 ...) ...)

(define (##sys#fd-queue) fd-list)

(define (create-fdset)
  ((foreign-lambda void "C_prepare_fdset" int) (##sys#length fd-list))
  (let loop ((lst fd-list))
    (unless (null? lst)
      (let ((fd (caar lst))
	    (input #f)
	    (output #f))
	(for-each
	 (lambda (t)
	   (let ((p (##sys#slot t 11)))
	     ;; XXX: This should never be false, because otherwise the
	     ;; thread is not supposed to be on fd-list!
	     (when (pair? p) ; (FD . RWFLAGS)? (can also be mutex or thread)
	       (let ((i/o (cdr p)))
		 (case i/o
		   ((#t #:input)
		    (set! input #t))
		   ((#f #:output)
		    (set! output #t))
		   ((#:all)
		    (set! input #t)
		    (set! output #t))
		   (else
		    (panic
		     (sprintf "create-fdset: invalid i/o direction: ~S (fd = ~S)" i/o fd))))))))
	 (cdar lst))
	;; Our position in fd-list must match fdset array position, so
	;; always add an fdset entry, even if input & output are #f.
	((foreign-lambda void "C_fdset_add" int bool bool) fd input output)
	(loop (cdr lst))))))

(define (fdset-test inf outf i/o)
  (case i/o
    ((#t #:input) inf)
    ((#f #:output) outf)
    ((#:all) (or inf outf))
    (else
     (panic (sprintf "fdset-test: invalid i/o direction: ~S (i = ~S, o = ~S)"
              i/o inf outf)))))

(define (##sys#thread-block-for-i/o! t fd i/o)
  (dbg t " blocks for I/O " fd " in mode " i/o)
  #;(unless (memq i/o '(#:all #:input #:output))
    (panic (sprintf "##sys#thread-block-for-i/o!: invalid i/o mode: ~S" i/o)))
  (let loop ([lst fd-list])
    (if (null? lst) 
	(set! fd-list (cons (list fd t) fd-list)) 
	(let ([a (car lst)])
	  (if (fx= fd (car a)) 
	      (##sys#setslot a 1 (cons t (cdr a)))
	      (loop (cdr lst)) ) ) ) )
  (##sys#setslot t 3 'blocked)
  (##sys#setislot t 13 #f)
  (##sys#setslot t 11 (cons fd i/o)) )

(define (##sys#unblock-threads-for-i/o)
  (dbg "fd-list: " fd-list)
  (create-fdset)
  (let* ((to? (pair? timeout-list))
	 (rq? (pair? ready-queue-head))
	 (tmo (if (and to? (not rq?)) ; no thread was unblocked by timeout, so wait
		  (let* ((tmo1 (caar timeout-list))
			 (tmo1 (inexact->exact (round tmo1)))
			 (now (##core#inline_allocate ("C_a_i_current_process_milliseconds" 7) #f)))
		    (max 0 (- tmo1 now)) )
		  0))) ; otherwise immediate timeout.
    (dbg "waiting for I/O with timeout " tmo)
    (let ((n ((foreign-lambda int "C_ready_fds_timeout" bool unsigned-integer)
	      (or rq? to?) tmo)))
      (dbg n " fds ready")
      (cond [(eq? -1 n)
	     (dbg "select(2)/poll(2) returned with result -1" )
	     (##sys#force-primordial)]
	    [(fx> n 0)
	     (set! fd-list
	       (let loop ((n n) (pos 0) (lst fd-list))
		 (if (or (zero? n) (null? lst))
		     lst
		     (let* ((a (car lst))
			    (fd (car a))
			    ;; pos *must* match position of fd in fd-list
			    ;; This is checked in C_fd_ready with assert()
			    (inf (##core#inline "C_fd_input_ready" fd pos))
			    (outf (##core#inline "C_fd_output_ready" fd pos)))
		       (dbg "fd " fd " state: input=" inf ", output=" outf)
		       (if (or inf outf)
			   (let loop2 ((threads (cdr a)) (keep '()))
			     (if (null? threads)
				 (if (null? keep)
				     (loop (sub1 n) (add1 pos) (cdr lst))
				     (cons (cons fd keep)
                                           (loop (sub1 n) (add1 pos) (cdr lst))))
				 (let* ((t (car threads))
					(p (##sys#slot t 11)) )
				   (dbg "checking " t " " p)
				   (cond ((##sys#slot t 13) ; unblocked by timeout?
					  (dbg t " unblocked by timeout")
					  (loop2 (cdr threads) keep))
					 ((not (pair? p)) ; not blocked for I/O?
					  ;; thread on fd-list is not blocked for I/O - this
					  ;; is incorrect but will be ignored, just let it run
					  (when (##sys#slot t 4) ; also blocked for timeout?
					    (##sys#remove-from-timeout-list t))
					  (##sys#thread-basic-unblock! t) 
					  (loop2 (cdr threads) keep))
					 ((not (eq? fd (car p)))
					  (panic (sprintf "thread is registered for I/O on unknown file-descriptor: ~S (expected ~S)" (car p) fd)))
					 ((fdset-test inf outf (cdr p))
					  (when (##sys#slot t 4) ; also blocked for timeout?
					    (##sys#remove-from-timeout-list t))
					  (##sys#thread-basic-unblock! t) 
					  (loop2 (cdr threads) keep))
					 (else (loop2 (cdr threads) (cons t keep)))))))
			   (cons a (loop n (add1 pos) (cdr lst))) ) ) ) ) ) ] ))) )


;;; Clear I/O state for unblocked thread

(define (##sys#clear-i/o-state-for-thread! t)
  (when (pair? (##sys#slot t 11))
    (let ((fd (car (##sys#slot t 11))))
      (set! fd-list
	(let loop ((lst fd-list))
	  (if (null? lst)
	      '()
	      (let* ((a (car lst))
		     (fd2 (car a)) )
		(if (eq? fd fd2)
		    (let ((ts (delq t (cdr a)))) ; remove from fd-list entry
		      (cond ((null? ts) (cdr lst))
			    (else
			     (##sys#setslot a 1 ts) ; fd-list entry is list with t removed
			     lst) ) )
		    (cons a (loop (cdr lst)))))))))))


;;; Get list of all threads that are ready or waiting for timeout or waiting for I/O:
;
; (contributed by Joerg Wittenberger)

(define (##sys#all-threads #!optional
			   (cns (lambda (queue arg val init)
				  (cons val init)))
			   (init '()))
  (let loop ((l ready-queue-head) (i init))
    (if (pair? l)
	(loop (cdr l) (cns 'ready #f (car l) i))
	(let loop ((l fd-list) (i i))
	  (if (pair? l)
	      (loop (cdr l)
		    (let ((fd (caar l)))
		      (let loop ((l (cdar l)))
			(if (null? l) i
			    (cns 'i/o fd (car l) (loop (cdr l)))))))
	      (let loop ((l timeout-list) (i i))
		(if (pair? l)
		    (loop (cdr l) (cns 'timeout (caar l) (cdar l) i))
		    i)))))))


;;; Remove all waiting threads from the relevant queues with the exception of the current thread:

(define (##sys#fetch-and-clear-threads)
  (let ([all (vector ready-queue-head ready-queue-tail fd-list timeout-list)])
    (set! ready-queue-head '())
    (set! ready-queue-tail '())
    (set! fd-list '())
    (set! timeout-list '()) 
    all) )


;;; Restore list of waiting threads:

(define (##sys#restore-threads vec)
  (set! ready-queue-head (##sys#slot vec 0))
  (set! ready-queue-tail (##sys#slot vec 1))
  (set! fd-list (##sys#slot vec 2))
  (set! timeout-list (##sys#slot vec 3)) )


;;; Unblock thread cleanly:

(define (##sys#thread-unblock! t)
  (when (or (eq? 'blocked (##sys#slot t 3))
	    (eq? 'sleeping (##sys#slot t 3)))
    (##sys#remove-from-timeout-list t)
    (##sys#clear-i/o-state-for-thread! t)
    (##sys#thread-basic-unblock! t) ) )


;;; Put a thread to sleep:

(define (##sys#thread-sleep! tm)
  (##sys#call-with-current-continuation
   (lambda (return)
     (let ((ct ##sys#current-thread))
       (##sys#setslot ct 1 (lambda () (return (##core#undefined))))
       (##sys#thread-block-for-timeout! ct tm)
       (##sys#schedule)))))


;;; Override `sleep` in library.scm to operate on the current thread:

(set! chicken.base#sleep-hook
  (lambda (n)
    (##sys#thread-sleep!
     (+ (##core#inline_allocate ("C_a_i_current_process_milliseconds" 7) #f)
	(* 1000.0 n)))))


;;; Kill all threads in fd-, io- and timeout-lists and assign one thread as the
;   new primordial one. Overrides "##sys#kill-other-threads" in library.scm.

(set! ##sys#kill-other-threads 
  (let ((exit exit))
    (lambda (thunk)
      (let ((primordial ##sys#current-thread))
	(define (suspend t)
	  (unless (eq? t primordial)
	    (##sys#setslot t 3 'suspended))
	  (##sys#setslot t 11 #f)      ; block-object (thread/mutex/fd & flags)
	  (##sys#setslot t 12 '()))    ; recipients (waiting for join)
	(set! ##sys#primordial-thread primordial)
	(set! ready-queue-head (list primordial))
	(set! ready-queue-tail ready-queue-head)
	(suspend primordial)	     ; clear block-obj. and recipients
	(for-each (lambda (a) (suspend (cdr a))) timeout-list)
	(for-each (lambda (a) (for-each suspend (cdr a))) fd-list)
	(set! timeout-list '())
	(set! fd-list '())
	(thunk)
	(exit)))))
