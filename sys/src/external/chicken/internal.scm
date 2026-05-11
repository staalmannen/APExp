;;;; internal.scm - Runtime support module for CHICKEN
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
  (unit internal)
  (disable-interrupts)
  (fixnum))

;; This is a bit of a grab-bag of stuff that's used in various places
;; in the runtime and the compiler, but which is not supposed to be
;; used by the user, and doesn't strictly belong anywhere in
;; particular.
(module chicken.internal
   (;; Convert string into valid C-identifier
    string->c-identifier

    ;; Parse library specifications
    library-id valid-library-specifier?

    ;; Requirement identifier for modules
    module-requirement

    ;;; Check for multiple bindings in "let"-style constructs
    check-for-multiple-bindings

    ;;; Macro environment manipulation
    macro-subset fixup-macro-environment

    ;; Low-level hash table support
    make-hash-table hash-table-ref hash-table-set! hash-table-update!
    hash-table-for-each hash-table-size

    ;; Modules that are made available to code by default
    default-imports default-syntax-imports)

(import scheme chicken.base chicken.fixnum)

(include "common-declarations.scm")
(include "mini-srfi-1.scm")


;;; Convert string into valid C-identifier:

(define (string->c-identifier str)
  (let ((out (open-output-string))
	(n (string-length str)))
    (do ((i 0 (fx+ i 1)))
	((fx>= i n) (get-output-string out))
      (let ((c (string-ref str i)))
	(if (and (not (char-alphabetic? c))
		 (or (not (char-numeric? c)) (fx= i 0)))
	    (let ((i (char->integer c)))
	      (write-char #\_ out)
	      (when (fx< i 16) (write-char #\0 out))
	      (display (number->string i 16) out))
	    (write-char c out))))))


;;; Parse library specifications:

(define (valid-library-specifier? x)
  (or (symbol? x)
      (and (list? x)
	   (not (null? x))
	   (every (lambda (x) (or (symbol? x) (fixnum? x))) x))))

(define (library-id lib)
  (define (fail)
    (##sys#error "invalid library specifier" lib))
  (define (srfi? x)
    (and (pair? (cdr x))
	 (null? (cddr x))
	 (eq? 'srfi (car x))
	 (fixnum? (cadr x))))
  (define (library-part->string x)
    (cond ((symbol? x) (##sys#symbol->string x))
	  ((fixnum? x) (##sys#number->string x))
	  (else (fail))))
  (cond
    ((symbol? lib) lib)
    ((null? lib) (fail))
    ((not (list? lib)) (fail))
    ((srfi? lib)
     (##sys#intern-symbol
      (##sys#string-append "srfi-" (##sys#number->string (cadr lib)))))
    (else
     (do ((lst (cdr lib) (cdr lst))
	  (str (library-part->string (car lib))
	       (string-append str "." (library-part->string (car lst)))))
	 ((null? lst)
	  (##sys#intern-symbol str))))))


;;; Requirement identifier for modules:

(define (module-requirement id)
  (##sys#string->symbol
   (##sys#string-append (##sys#slot id 1) "#")))


;;; Check for multiple bindings in "let"-style constructs:

(define (check-for-multiple-bindings bindings form loc)
  ;; assumes correct syntax
  (let loop ((bs bindings) (seen '()) (warned '()))
    (cond ((null? bs))
	  ((and (memq (caar bs) seen)
                (not (memq (caar bs) warned)))
	   (##sys#warn
	    (string-append "variable bound multiple times in " loc " construct")
	    (caar bs)
	    form)
	   (loop (cdr bs) seen (cons (caar bs) warned)))
	  (else (loop (cdr bs) (cons (caar bs) seen) warned)))))


;;; Macro environment manipulation:
(define (macro-subset me0 #!optional parent-env)
  (let ((se (let loop ((me (##sys#macro-environment)))
	      (if (or (null? me) (eq? me me0))
		  '()
		  (cons (car me) (loop (cdr me)))))))
    (fixup-macro-environment se parent-env)))

(define (fixup-macro-environment se #!optional parent-env)
  (let ((se2 (if parent-env (##sys#append se parent-env) se)))
    (for-each				; fixup se
     (lambda (sdef)
       (when (pair? (cdr sdef))
	 (set-car!
	  (cdr sdef)
	  (if (null? (cadr sdef))
	      se2
	      (##sys#append (cadr sdef) se2)))))
     se)
    se))


;;; Low-level hashtable support:

(define hash-symbol
  (let ((cache-s #f)
	(cache-h #f)
	;; NOTE: All low-level hash tables share the same randomization factor
	(rand (##core#inline "C_rand" #x10000)))
    (lambda (s n)
      (if (eq? s cache-s)
	  (##core#inline "C_fixnum_modulo" cache-h n)
	  (begin
	    (set! cache-s s)
	    (set! cache-h (##core#inline "C_u_i_string_hash" (##sys#slot s 1) rand))
	    (##core#inline "C_fixnum_modulo" cache-h n))))))

(define (make-hash-table #!optional (size 301))
  (make-vector size '()))

(define (hash-table-ref ht key)
  (let loop ((bucket (##sys#slot ht (hash-symbol key (##core#inline "C_block_size" ht)))))
    (and (not (eq? '() bucket))
	 (if (eq? key (##sys#slot (##sys#slot bucket 0) 0))
	     (##sys#slot (##sys#slot bucket 0) 1)
	     (loop (##sys#slot bucket 1))))))

(define (hash-table-set! ht key val)
  (let* ((k (hash-symbol key (##core#inline "C_block_size" ht)))
	 (ib (##sys#slot ht k)))
      (let loop ((bucket ib))
	(if (eq? '() bucket)
	    (##sys#setslot ht k (cons (cons key val) ib))
	    (if (eq? key (##sys#slot (##sys#slot bucket 0) 0))
		(##sys#setslot (##sys#slot bucket 0) 1 val)
		(loop (##sys#slot bucket 1)))))))

(define (hash-table-update! ht key updtfunc valufunc)
  (hash-table-set! ht key (updtfunc (or (hash-table-ref ht key) (valufunc)))))

(define (hash-table-for-each p ht)
  (let ((len (##core#inline "C_block_size" ht)))
    (do ((i 0 (fx+ i 1)))
	((fx>= i len))
      (##sys#for-each (lambda (bucket) (p (##sys#slot bucket 0) (##sys#slot bucket 1)))
		      (##sys#slot ht i)))))

(define (hash-table-size ht)
  (let loop ((len (##sys#size ht)) (bkt 0) (size 0))
    (if (fx= bkt len)
	size
	(loop len (fx+ bkt 1) (fx+ size (##sys#length (##sys#slot ht bkt)))))))

;;; Modules that are made available to code by default:

;; WARNING: These import libs must all exist.  They cannot be emitted,
;; because the compiler itself needs them to expand macros!
;; WARNING: These also need to be built into modules.scm, so that
;; statically linked programs can eval the imports for these modules.

(define default-imports '(scheme chicken.base chicken.syntax))
(define default-syntax-imports '(scheme chicken.base chicken.syntax))

) ; chicken.internal
