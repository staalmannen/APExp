;;;; read-syntax.scm - CHICKEN reader extensions
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
  (unit read-syntax)
  (uses internal)
  (disable-interrupts))

(module chicken.read-syntax
  (copy-read-table current-read-table define-reader-ctor set-read-syntax!
   set-sharp-read-syntax! set-parameterized-read-syntax!)

(import scheme chicken.base chicken.internal chicken.platform)

(include "common-declarations.scm")

(define (set-read-mark! sym proc)
  (let ((a (assq sym ##sys#read-marks)))
    (if a
	(##sys#setslot a 1 proc)
	(set! ##sys#read-marks (cons (cons sym proc) ##sys#read-marks)))))

(define current-read-table ##sys#current-read-table)

(define ((syntax-setter loc slot wrap) chr proc)
  (if (symbol? chr)
      (set-read-mark! chr proc)
      (let ((crt (current-read-table)))
	(unless (##sys#slot crt slot)
	  (##sys#setslot crt slot (##sys#make-vector 256 #f)))
	(##sys#check-char chr loc)
	(let ((i (char->integer chr)))
	  (##sys#check-range i 0 256 loc)
	  (cond (proc
		 (##sys#check-closure proc loc)
		 (##sys#setslot (##sys#slot crt slot) i (wrap proc)))
		(else
		 (##sys#setslot (##sys#slot crt slot) i #f)))))))

(define set-read-syntax!
  (syntax-setter
   'set-read-syntax! 1
   (lambda (proc)
     (lambda (_ port)
       (##sys#read-char-0 port)
       (proc port)))))

(define set-sharp-read-syntax!
  (syntax-setter
   'set-sharp-read-syntax! 2
   (lambda (proc)
     (lambda (_ port)
       (##sys#read-char-0 port)
       (proc port)))))

(define set-parameterized-read-syntax!
  (syntax-setter
   'set-parameterized-read-syntax! 3
   (lambda (proc)
     (lambda (_ port num)
       (##sys#read-char-0 port)
       (proc port num)))))

;;; Read-table operations:

(define (copy-read-table rt)
  (##sys#check-structure rt 'read-table 'copy-read-table)
  (##sys#make-structure
   'read-table
   (let ((t1 (##sys#slot rt 1)))
     (and t1 (##sys#vector-resize t1 (##sys#size t1) #f)))
   (let ((t2 (##sys#slot rt 2)))
     (and t2 (##sys#vector-resize t2 (##sys#size t2) #f)))
   (let ((t3 (##sys#slot rt 3)))
     (and t3 (##sys#vector-resize t3 (##sys#size t3) #f)))))

;;; SRFI-10:

(define sharp-comma-reader-ctors (make-vector 301 '()))

(define (define-reader-ctor spec proc)
  (##sys#check-symbol spec 'define-reader-ctor)
  (hash-table-set! sharp-comma-reader-ctors spec proc))

(set! ##sys#user-read-hook
  (let ((old ##sys#user-read-hook)
	(read-char read-char)
	(read read))
    (lambda (char port)
      (cond ((char=? char #\,)
	     (read-char port)
	     (let* ((exp (read port))
		    (err (lambda () (##sys#read-error port "invalid sharp-comma external form" exp))))
	       (if (or (null? exp) (not (list? exp)))
		   (err)
		   (let ([spec (##sys#slot exp 0)])
		     (if (not (symbol? spec))
			 (err)
			 (let ((ctor (hash-table-ref sharp-comma-reader-ctors spec)))
			   (if ctor
			       (apply ctor (##sys#slot exp 1))
			       (##sys#read-error port "undefined sharp-comma constructor" spec))))))))
	    (else (old char port))))))

(register-feature! 'srfi-10))
