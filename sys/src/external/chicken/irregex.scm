;;;; irregex.scm - container for irregex-core.scm
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
  (unit irregex)
  (no-procedure-checks)
  (fixnum))

(module chicken.irregex
    (;; Constructors, accessors and predicates
     irregex irregex? string->sre maybe-string->sre sre->irregex
     irregex-names irregex-num-submatches string->irregex

     ;; Chunking constructor
     make-irregex-chunker

     ;; Main API
     irregex-extract irregex-fold irregex-match irregex-match?
     irregex-search irregex-split irregex-replace irregex-replace/all

     ;; Chunked main API
     irregex-fold/chunked irregex-match/chunked irregex-search/chunked

     ;; Match extraction API
     irregex-match-data? irregex-match-names
     irregex-match-start-index irregex-match-end-index
     irregex-match-num-submatches irregex-match-substring
     irregex-match-valid-index?

     ;; Chunked match API
     irregex-match-start-chunk irregex-match-end-chunk
     irregex-match-subchunk

     ;; Utilities
     glob->sre sre->string irregex-opt irregex-quote)


(import scheme chicken.base chicken.fixnum chicken.syntax chicken.type)

(import-for-syntax chicken.fixnum)

(include "common-declarations.scm")

;; These should probably be taken out of irregex upstream
(declare (unused filter integer-log cset-size remove))

;; Due to usual-integrations, find is the one from library.scm,
;; so find-tail is unused (it's only used in the "find" definition)
(declare (unused find-tail))

;; This is to silence an "always true" warning that we can't fix
;; because we don't want to needlessly change irregex-core.
(declare (type (*allow-utf8-mode?* boolean)))

(define-syntax build-cache
  (er-macro-transformer 
   (lambda (x r c)
     ;; (build-cache N ARG FAIL) 
     (let* ((n (cadr x))
	    (n2 (* n 2))
	    (arg (caddr x))
	    (fail (cadddr x))
	    (%cache (r 'cache))
	    (%index (r 'index))
	    (%arg (r 'arg))
	    (%let (r 'let))
	    (%let* (r 'let*))
	    (%if (r 'if))
	    (%fx+ (r 'fx+))
	    (%fxmod (r 'fxmod))
	    (%equal? (r 'equal?))
	    (%quote (r 'quote))
	    (%tmp (r 'tmp))
	    (%begin (r 'begin))
	    (cache (make-vector (add1 n2) #f)))
       (##sys#setslot cache n2 0)	 ; last slot: current index
       `(,%let* ((,%cache (,%quote ,cache)) ; we mutate a literal vector
		 (,%arg ,arg))
		,(let fold ((i 0))
		   (if (fx>= i n)
		       ;; this should be thread-safe: a context-switch can only
		       ;; happen before this code and in the call to FAIL.
		       `(,%let ((,%tmp ,fail)
				(,%index (##sys#slot ,%cache ,n2)))
			       (##sys#setslot ,%cache ,%index ,%arg)
			       (##sys#setslot ,%cache (,%fx+ ,%index 1) ,%tmp)
			       (##sys#setislot 
				,%cache ,n2 (,%fxmod (,%fx+ ,%index 2) ,n2))
			       ,%tmp)
		       `(,%if (,%equal? (##sys#slot ,%cache ,(* i 2)) ,%arg)
			      (##sys#slot ,%cache ,(add1 (* i 2)))
			      ,(fold (add1 i))))))))))

(declare (unused %%string-copy!))
(define-compiler-syntax %%string-copy!
  (syntax-rules ()
    ((_ to tstart from fstart fend)
     (let ((x to)
	   (y tstart)
	   (z from)
	   (u fstart)
	   (v fend))
       (##core#inline "C_substring_copy" z x u v y)))))

(declare (unused %substring=?))
(define-compiler-syntax %substring=?
  (syntax-rules ()
    ((_ a b start1 start2 len)
     (##core#inline "C_substring_compare" a b start1 start2 len))))

(define-compiler-syntax make-irregex 
  (syntax-rules ()
    ((_ dfa dfa/search nfa flags submatches lengths names)
     (##sys#make-structure
      'regexp dfa dfa/search nfa flags submatches lengths names))))

(define-compiler-syntax make-irregex-match
  (syntax-rules ()
    ((_ count names)
     (##sys#make-structure
      'regexp-match
      (make-vector (* 4 (+ 2 count)) #f) ; #1: submatches
      names                              ; #2: (guess)
      #f                                 ; #3: chunka
      #f))))                             ; #4: fail

(declare (unused reverse))
(define-compiler-syntax reverse
  (syntax-rules ()
    ((_ lst) (##sys#fast-reverse lst))))

(declare (unused bit-shl))
(define-compiler-syntax bit-shl
  (syntax-rules ()
    ((_ n i) (fxshl n i))))

(declare (unused bit-shr))
(define-compiler-syntax bit-shr
  (syntax-rules ()
    ((_ n i) (fxshr n i))))

(declare (unused bit-not))
(define-compiler-syntax bit-not
  (syntax-rules ()
    ((_ n) (fxnot n))))

(declare (unused bit-ior))
(define-compiler-syntax bit-ior
  (syntax-rules ()
    ((_ a b) (fxior a b))))

(declare (unused bit-and))
(define-compiler-syntax bit-and
  (syntax-rules ()
    ((_ a b) (fxand a b))))

(define-compiler-syntax match-vector-ref
  (syntax-rules ()
    ((_ m i) (##sys#slot (##sys#slot m 1) i))))

(define-compiler-syntax match-vector-set!
  (syntax-rules ()
    ((_ m i x) (##sys#setslot (##sys#slot m 1) i x))))

(declare (unused irregex-match-start-chunk-set!))
(define-compiler-syntax irregex-match-start-chunk-set!
  (syntax-rules ()
    ((_ m n start)
     (vector-set! (##sys#slot m 1) (* n 4) start))))

(declare (unused irregex-match-start-index-set!))
(define-compiler-syntax irregex-match-start-index-set!
  (syntax-rules ()
    ((_ m n start)
     (vector-set! (##sys#slot m 1) (+ 1 (* n 4)) start))))

(declare (unused irregex-match-end-chunk-set!))
(define-compiler-syntax irregex-match-end-chunk-set!
  (syntax-rules ()
    ((_ m n end)
     (vector-set! (##sys#slot m 1) (+ 2 (* n 4)) end))))

(declare (unused irregex-match-end-index-set!))
(define-compiler-syntax irregex-match-end-index-set!
  (syntax-rules ()
    ((_ m n end)
     (vector-set! (##sys#slot m 1) (+ 3 (* n 4)) end))))

(declare (unused irregex-match-chunk&index-from-tag-set!))
(define-compiler-syntax irregex-match-chunk&index-from-tag-set!
  (syntax-rules ()
    ((_ m t chunk index)
     (begin
       (vector-set! (##sys#slot m 1) (+ 4 (* t 2)) chunk)
       (vector-set! (##sys#slot m 1) (+ 5 (* t 2)) index)))))

(include "irregex-core.scm")
(include "irregex-utils.scm")

(define glob->sre
  (let ((list->string list->string)
        (string->list string->list))
    (lambda (s)
      (##sys#check-string s 'glob->sre)
      (cons
       ':
       (let loop ((cs (string->list s)) (dir #t))
	 (if (null? cs)
	     '()
	     (let ((c (car cs))
		   (rest (cdr cs)) )
	       (cond ((char=? c #\*)
		      (if dir
			  `((or (: (~ ("./\\"))
				   (* (~ ("/\\"))))
				(* (~ ("./\\"))))
			    ,@(loop rest #f))
			  `((* (~ ("/\\"))) ,@(loop rest #f))))
		     ((char=? c #\?)  (cons 'any (loop rest #f)))
		     ((char=? c #\[)
		      (let loop2 ((rest rest) (s '()))
			(cond ((not (pair? rest))
			       (error 'glob->sre
				      "unexpected end of character class" s))
			      ((char=? #\] (car rest))
			       `(,(if (> (length s) 1)
				      `(or ,@s)
				      (car s))
				 ,@(loop (cdr rest) #f)))
			      ((and (pair? (cdr rest))
				    (pair? (cddr rest))
				    (char=? #\- (cadr rest)) )
			       (loop2 (cdddr rest)
				      (cons `(/ ,(car rest) ,(caddr rest)) s)))
			      ((and (pair? (cdr rest))
				    (char=? #\- (car rest)))
			       (loop2 (cddr rest)
				      (cons `(~ ,(cadr rest)) s)))
			      (else
			       (loop2 (cdr rest) (cons (car rest) s))))))
		     (else (cons c (loop rest (memq c '(#\\ #\/)))))))))))))

)
