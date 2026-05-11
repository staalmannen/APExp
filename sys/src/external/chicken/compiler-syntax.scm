;;;; compiler-syntax.scm - compiler syntax used internally
;
; Copyright (c) 2009-2022, The CHICKEN Team
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
  (unit compiler-syntax)
  (uses expand extras support compiler))

(module chicken.compiler.compiler-syntax
    (compiler-syntax-statistics)

(import scheme
	chicken.base
	chicken.compiler.support
	chicken.compiler.core
	chicken.fixnum
	chicken.format
	chicken.syntax)

(include "tweaks.scm")
(include "mini-srfi-1.scm")


;;; Compiler macros (that operate in the expansion phase)

(define compiler-syntax-statistics '())

(set! ##sys#compiler-syntax-hook
  (lambda (name result)
    (let ((a (alist-ref name compiler-syntax-statistics eq? 0)))
      (set! compiler-syntax-statistics
	(alist-update! name (add1 a) compiler-syntax-statistics)))))

(define (r-c-s names transformer se)
  (let ((t (cons (##sys#ensure-transformer
		  (##sys#er-transformer transformer)
		  (car names))
		 (append se ##sys#default-macro-environment))))
    (for-each
     (lambda (name)
       (##sys#put! name '##compiler#compiler-syntax t) )
     names) ) )

(define-syntax define-internal-compiler-syntax
  (syntax-rules ()
    ((_ (names . llist) se . body)
     (r-c-s 'names (lambda llist . body) se))))

(define-internal-compiler-syntax ((scheme#for-each ##sys#for-each) x r c)
  '((pair? . scheme#pair?))
  (let ((%let (r 'let))
	(%if (r 'if))
	(%loop (r 'for-each-loop))
	(%proc (gensym))
	(%begin (r 'begin))
	(%quote (r 'quote))
	(%and (r 'and))
	(%pair? (r 'pair?))
	(%lambda (r 'lambda))
	(lsts (cddr x)))
    (if (and (memq 'scheme#for-each standard-bindings) ; we have to check this because the db (and thus 
	     (> (length+ x) 2))			 ; intrinsic marks) isn't set up yet
	(let ((vars (map (lambda _ (gensym)) lsts)))
	  `(,%let ((,%proc ,(cadr x))
		   ,@(map list vars lsts))
		  ,@(map (lambda (var)
			   `(##core#check (##sys#check-list ,var (,%quote for-each))))
			 vars)
		  (,%let ,%loop ,(map list vars vars)
			 (,%if (,%and ,@(map (lambda (v) `(,%pair? ,v)) vars))
			       (,%begin
				(,%proc
				 ,@(map (lambda (v) `(##sys#slot ,v 0)) vars))
				(##core#app 
				 ,%loop
				 ,@(map (lambda (v) `(##sys#slot ,v 1)) vars) ) )))))
	x)))

(define-internal-compiler-syntax ((scheme#map ##sys#map) x r c)
  '((pair? . scheme#pair?) (cons . scheme#cons))
  (let ((%let (r 'let))
	(%if (r 'if))
	(%loop (r 'map-loop))
	(%res (gensym))
	(%cons (r 'cons))
	(%set! (r 'set!))
	(%result (gensym))
	(%node (gensym))
	(%proc (gensym))
	(%quote (r 'quote))
	(%begin (r 'begin))
	(%lambda (r 'lambda))
	(%and (r 'and))
	(%pair? (r 'pair?))
	(lsts (cddr x)))
    (if (and (memq 'scheme#map standard-bindings) ; s.a.
	     (> (length+ x) 2))
	(let ((vars (map (lambda _ (gensym)) lsts)))
	  `(,%let ((,%node (,%cons (##core#undefined) (,%quote ()))))
	     (,%let ((,%result ,%node)
		     (,%proc ,(cadr x))
		     ,@(map list vars lsts))
		    ,@(map (lambda (var)
			     `(##core#check (##sys#check-list ,var (,%quote map))))
			   vars)
	       (,%let ,%loop ,(map list vars vars)
		 (,%if (,%and ,@(map (lambda (v) `(,%pair? ,v)) vars))
		       (,%let ((,%res
				(,%cons
				 (,%proc
				  ,@(map (lambda (v) `(##sys#slot ,v 0)) vars))
				 (,%quote ()))))
			      (##sys#setslot ,%node 1 ,%res)
			      (,%set! ,%node ,%res)
			      (##core#app
			       ,%loop
			       ,@(map (lambda (v) `(##sys#slot ,v 1)) vars)))
		       (##sys#slot ,%result 1))))))
	x)))

(define-internal-compiler-syntax ((chicken.base#o) x r c) '()
  (if (and (fx> (length x) 1)
	   (memq 'chicken.base#o extended-bindings)) ; s.a.
      (let ((%tmp (r 'tmp)))
	`(,(r 'lambda) (,%tmp) ,(foldr list %tmp (cdr x))))
      x))

(define-internal-compiler-syntax ((chicken.format#sprintf chicken.format#format) x r c)
  `((display . scheme#display)
    (write . scheme#write)
    (number->string . scheme#number->string)
    (write-char . scheme#write-char)
    (open-output-string . chicken.base#open-output-string)
    (get-output-string . chicken.base#get-output-string))
  (let* ((out (gensym 'out))
	 (code (compile-format-string
		(if (eq? (car x) 'chicken.format#sprintf) 'sprintf 'format)
		out x (cdr x) r c)))
    (if code
	`(,(r 'let) ((,out (,(r 'open-output-string))))
	  ,code
	  (,(r 'get-output-string) ,out))
	x)))

(define-internal-compiler-syntax ((chicken.format#fprintf) x r c)
  '((display . scheme#display)
    (write . scheme#write)
    (number->string . scheme#number->string)
    (write-char . scheme#write-char)
    (open-output-string . chicken.base#open-output-string)
    (get-output-string . chicken.base#get-output-string))
  (if (>= (length x) 3)
      (let ((code (compile-format-string 'fprintf (cadr x) x (cddr x) r c)))
	(or code x))
      x))

(define-internal-compiler-syntax ((chicken.format#printf) x r c)
  '((display . scheme#display)
    (write . scheme#write)
    (number->string . scheme#number->string)
    (write-char . scheme#write-char)
    (open-output-string . chicken.base#open-output-string)
    (get-output-string . chicken.base#get-output-string))
  (let ((code (compile-format-string 'printf '##sys#standard-output x (cdr x) r c)))
    (or code x)))

(define (compile-format-string func out x args r c)
  (call/cc
   (lambda (return)
     (and (>= (length args) 1)
	  (memq (symbol-append 'chicken.format# func) extended-bindings) ; s.a.
	  (or (string? (car args))
	      (and (list? (car args))
		   (c (r 'quote) (caar args))
		   (string? (cadar args))))
	  (let ((fstr (if (string? (car args)) (car args) (cadar args)))
		(args (cdr args)))
	    (define (fail ret? msg . args)
	      (let ((ln (get-line-number x)))
		(warning 
		 (sprintf "~a`~a', in format string ~s, ~?" 
		   (if ln (sprintf "(~a) " ln) "")
		   func fstr 
		   msg args) ))
	      (when ret? (return #f)))
	    (let ((code '())
		  (index 0)
		  (len (string-length fstr)) 
		  (%out (r 'out))
		  (%let (r 'let))
		  (%number->string (r 'number->string)))
	      (define (fetch)
		(let ((c (string-ref fstr index)))
		  (set! index (fx+ index 1))
		  c) )
	      (define (next)
		(if (null? args)
		    (fail #t "too few arguments to formatted output procedure")
		    (let ((x (car args)))
		      (set! args (cdr args))
		      x) ) )
	      (define (endchunk chunk)
		(when (pair? chunk)
		  (push 
		   (if (= 1 (length chunk))
		       `(##sys#write-char-0 ,(car chunk) ,%out)
		       `(##sys#print ,(##sys#reverse-list->string chunk) #f ,%out)))))
	      (define (push exp)
		(set! code (cons exp code)))
	      (let loop ((chunk '()))
		(cond ((>= index len)
		       (unless (null? args)
			 (fail #f "too many arguments to formatted output procedure"))
		       (endchunk chunk)
		       `(,%let ((,%out ,out))
			       (##sys#check-output-port ,%out #t ',func)
			       ,@(reverse code)))
		      (else
		       (let ((c (fetch)))
			 (if (eq? c #\~)
			     (let ((dchar (fetch)))
			       (endchunk chunk)
			       (case (char-upcase dchar)
				 ((#\S) (push `(##sys#print ,(next) #t ,%out)))
				 ((#\A) (push `(##sys#print ,(next) #f ,%out)))
				 ((#\C) (push `(##sys#write-char-0 ,(next) ,%out)))
				 ((#\B)
				  (push
				   `(##sys#print (,%number->string ,(next) 2) 
						  #f ,%out)))
				 ((#\O)
				  (push
				   `(##sys#print (,%number->string ,(next) 8) 
						 #f ,%out)))
				 ((#\X)
				  (push
				   `(##sys#print (,%number->string ,(next) 16) 
						 #f ,%out)))
				 ((#\!) (push `(##sys#flush-output ,%out)))
				 ((#\?)
				  (let* ([fstr (next)]
					 [lst (next)] )
				    (push `(##sys#apply chicken.format#fprintf ,%out ,fstr ,lst))))
				 ((#\~) (push `(##sys#write-char-0 #\~ ,%out)))
				 ((#\% #\N) (push `(##sys#write-char-0 #\newline ,%out)))
				 (else
				  (if (char-whitespace? dchar)
				      (let skip ((c (fetch)))
					(if (char-whitespace? c)
					    (skip (fetch))
					    (set! index (sub1 index))))
				      (fail #t "illegal format-string character `~c'" dchar) ) ) )
			       (loop '()) )
			     (loop (cons c chunk)))))))))))))

(define-internal-compiler-syntax ((chicken.base#foldr) x r c)
  '((pair? . scheme#pair?))
  (if (and (fx= (length x) 4)
	   (memq 'chicken.base#foldr extended-bindings) ) ; s.a.
      (let ((f (cadr x))
	    (z (caddr x))
	    (lst (cadddr x))
	    (%let* (r 'let*))
	    (%let (r 'let))
	    (%pair? (r 'pair?))
	    (%if (r 'if))
	    (loopvar (gensym "foldr"))
	    (lstvar (gensym)))
	`(,%let* ((,lstvar ,lst))
		 (##core#check (##sys#check-list ,lstvar (##core#quote foldr)))
		 (,%let ,loopvar ((,lstvar ,lstvar))
			(,%if (,%pair? ,lstvar)
			      (,f (##sys#slot ,lstvar 0) 
				     (##core#app ,loopvar (##sys#slot ,lstvar 1)))
			      ,z))))
      x))

(define-internal-compiler-syntax ((chicken.base#foldl) x r c)
  '((pair? . scheme#pair?))
  (if (and (fx= (length x) 4)
	   (memq 'chicken.base#foldl extended-bindings) ) ; s.a.
      (let ((f (cadr x))
	    (z (caddr x))
	    (lst (cadddr x))
	    (%let* (r 'let*))
	    (%let (r 'let))
	    (%if (r 'if))
	    (%pair? (r 'pair?))
	    (zvar (gensym))
	    (loopvar (gensym "foldl"))
	    (lstvar (gensym)))
	`(,%let* ((,zvar ,z)
		  (,lstvar ,lst))
		 (##core#check (##sys#check-list ,lstvar (##core#quote foldl)))
		 (,%let ,loopvar ((,lstvar ,lstvar) (,zvar ,zvar))
			(,%if (,%pair? ,lstvar)
			      (##core#app 
			       ,loopvar
			       (##sys#slot ,lstvar 1) 
			       (,f ,zvar (##sys#slot ,lstvar 0)))
			      ,zvar))))
      x))
)
