;;;; repl.scm - CHICKEN's read/eval/print loop
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
  (unit repl)
  (uses eval)
  (not inline ##sys#repl-read-hook ##sys#repl-print-hook ##sys#read-prompt-hook))

(module chicken.repl
  (quit repl repl-prompt reset reset-handler)

(import scheme
	chicken.base
	chicken.eval
	chicken.foreign
	chicken.load
	chicken.syntax)

(include "common-declarations.scm")

(define ##sys#repl-print-length-limit #f)
(define ##sys#repl-read-hook #f)
(define ##sys#repl-recent-call-chain #f) ; used in csi for ,c command

(define (##sys#repl-print-hook x port)
  (##sys#with-print-length-limit ##sys#repl-print-length-limit (cut ##sys#print x #t port))
  (##sys#write-char-0 #\newline port))

(define (quit-hook result) (exit))
(define (quit #!optional result) (quit-hook result))

(define reset-handler ##sys#reset-handler)
(define (reset) ((reset-handler)))

(define repl-prompt
  (make-parameter (lambda () "#;> ")))

(define ##sys#read-prompt-hook
  (let ((repl-prompt repl-prompt))
    (lambda ()
      (##sys#print ((repl-prompt)) #f ##sys#standard-output)
      (##sys#flush-output ##sys#standard-output))))

(define (##sys#resize-trace-buffer i)
  (##sys#check-fixnum i)
  (##core#inline "C_resize_trace_buffer" i))

(define repl
  (let ((eval eval)
	(call-with-current-continuation call-with-current-continuation)
	(string-append string-append))
    (lambda (#!optional (evaluator eval))

      (define (write-err xs)
	(for-each (cut ##sys#repl-print-hook <> ##sys#standard-error) xs))

      (define (write-results xs)
	(cond ((null? xs)
	       (##sys#print "; no values\n" #f ##sys#standard-output))
	      ((not (eq? (##core#undefined) (car xs)))
	       (for-each (cut ##sys#repl-print-hook <> ##sys#standard-output) xs)
	       (when (pair? (cdr xs))
		 (##sys#print
		  (string-append "; " (##sys#number->string (length xs)) " values\n")
		  #f ##sys#standard-output)))))

      (let ((stdin ##sys#standard-input)
	    (stdout ##sys#standard-output)
	    (stderr ##sys#standard-error)
	    (ehandler (##sys#error-handler))
	    (rhandler (##sys#reset-handler))
	    (notices ##sys#notices-enabled)
	    (lv #f)
	    (qh quit-hook)
	    (uie ##sys#unbound-in-eval))

	(define (saveports)
	  (set! stdin ##sys#standard-input)
	  (set! stdout ##sys#standard-output)
	  (set! stderr ##sys#standard-error))

	(define (resetports)
	  (set! ##sys#standard-input stdin)
	  (set! ##sys#standard-output stdout)
	  (set! ##sys#standard-error stderr))

	(call-with-current-continuation
	 (lambda (k)
	   (##sys#dynamic-wind
	    (lambda ()
	      (set! lv (load-verbose))
	      (set! quit-hook (lambda (result) (k result)))
	      (load-verbose #t)
	      (set! ##sys#notices-enabled #t)
	      (##sys#error-handler
	       (lambda (msg . args)
		 (resetports)
		 (##sys#print "\nError" #f ##sys#standard-error)
		 (when msg
		   (##sys#print ": " #f ##sys#standard-error)
		   (##sys#print msg #f ##sys#standard-error))
		 (if (and (pair? args) (null? (cdr args)))
		     (begin
		       (##sys#print ": " #f ##sys#standard-error)
		       (write-err args))
		     (begin
		       (##sys#write-char-0 #\newline ##sys#standard-error)
		       (write-err args)))
		 (set! ##sys#repl-recent-call-chain
		   (let ((ct (or (and-let* ((lexn ##sys#last-exception) ;XXX not really right
			  	            ((##sys#structure? lexn 'condition))
				            (a (member '(exn . call-chain) (##sys#slot lexn 2))))
			           (cadr a))
                                 (get-call-chain 0 ##sys#current-thread))))
	             (##sys#really-print-call-chain
		      ##sys#standard-error ct
		      "\n\tCall history:\n")
		     ct))
		 (flush-output ##sys#standard-error))))
	    (lambda ()
	      (let loop ()
		(saveports)
		(call-with-current-continuation
		 (lambda (c)
		   (##sys#reset-handler
		    (lambda ()
		      (set! ##sys#read-error-with-line-number #f)
		      (resetports)
		      (c #f)))))
		(##sys#read-prompt-hook)
		;; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing
		(let ((exp ((or ##sys#repl-read-hook chicken.syntax#read-with-source-info))))
		  (unless (eof-object? exp)
		    (when (eq? #\newline (##sys#peek-char-0 ##sys#standard-input))
		      (##sys#read-char-0 ##sys#standard-input))
		    (foreign-code "C_clear_trace_buffer();")
		    (set! ##sys#unbound-in-eval '())
		    (receive result (evaluator exp)
		      (when (and ##sys#warnings-enabled (pair? ##sys#unbound-in-eval))
			(let loop ((vars ##sys#unbound-in-eval)
				   (u '()))
			  (cond ((null? vars)
				 (when (pair? u)
				   (when ##sys#notices-enabled
				     (##sys#notice
				      "the following toplevel variables are referenced but unbound:\n")
				     (for-each
				      (lambda (v)
					(##sys#print "  " #f ##sys#standard-error)
					(##sys#print (car v) #t ##sys#standard-error)
					(when (cdr v)
					  (##sys#print " (in " #f ##sys#standard-error)
					  (##sys#print (cdr v) #t ##sys#standard-error)
					  (##sys#write-char-0 #\) ##sys#standard-error))
					(##sys#write-char-0 #\newline ##sys#standard-error))
				      u)
				     (##sys#flush-output ##sys#standard-error))))
				((or (memq (caar vars) u)
				     (##core#inline "C_u_i_namespaced_symbolp" (caar vars))
				     (##sys#symbol-has-toplevel-binding? (caar vars)))
				 (loop (cdr vars) u))
				(else (loop (cdr vars) (cons (car vars) u)))) 9))
		      (write-results result)
		      (loop))))))
	    (lambda ()
	      (load-verbose lv)
	      (set! quit-hook qh)
	      (set! ##sys#notices-enabled notices)
	      (set! ##sys#unbound-in-eval uie)
	      (##sys#error-handler ehandler)
	      (##sys#reset-handler rhandler))))))))))
