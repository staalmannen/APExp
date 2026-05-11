;;;; chicken-ffi-syntax.scm
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
  (unit chicken-ffi-syntax)
  (uses data-structures extras internal)
  (disable-interrupts)
  (fixnum))

#+(not debugbuild)
(declare
  (no-bound-checks)
  (no-procedure-checks))

(import scheme
	chicken.base
	chicken.format
	chicken.internal
	chicken.platform
	chicken.syntax
	chicken.string)

(include "common-declarations.scm")
(include "mini-srfi-1.scm")

(define ##sys#chicken-ffi-macro-environment
  (let ((me0 (##sys#macro-environment)))

;; IMPORTANT: These macros directly call fully qualified names from
;; the "chicken.compiler.c-backend" and "chicken.compiler.support"
;; modules.  These are unbound in the interpreter, so check first:
(define (compiler-only-er-transformer transformer)
  (##sys#er-transformer
   (lambda (form r c)
     (if (feature? 'compiling)
	 (transformer form r c)
	 (syntax-error
	  (car form) "The FFI is not supported in interpreted mode")))))

(##sys#extend-macro-environment
 'define-external
 `((define . ,(alist-ref 'define me0))	; Or just me0?
   (begin . ,(alist-ref 'begin me0))
   (lambda . ,(alist-ref 'lambda me0)))
 (compiler-only-er-transformer
  (lambda (form r c)
    (let* ((form (cdr form))
	   (quals (and (pair? form) (string? (car form))))
	   (var (and (not quals) (pair? form) (symbol? (car form)))) )
      (cond [var
	     (##sys#check-syntax 'define-external form '(symbol _ . #(_ 0 1)))
	     (let ([var (car form)])
	       `(,(r 'begin)
		 (##core#define-foreign-variable ,var ,(cadr form))
		 (##core#define-external-variable ,var ,(cadr form) #t)
		 ,@(if (pair? (cddr form))
		       `((##core#set! ,var ,(caddr form)))
		       '() ) ) ) ]
	    [else
	     (if quals
		 (##sys#check-syntax 'define-external form '(string (symbol . #((_ symbol) 0)) _ . #(_ 1)))
		 (##sys#check-syntax 'define-external form '((symbol . #((_ symbol) 0)) _ . #(_ 1))) )
	     (let* ((head (if quals (cadr form) (car form)))
		    (args (cdr head)) )
	       `(,(r 'define) ,(car head)
		 (##core#foreign-callback-wrapper
		  (##core#quote ,(car head))
		  ,(if quals (car form) "")
		  (##core#quote ,(if quals (caddr form) (cadr form)))
		  (##core#quote ,(map (lambda (a) (car a)) args))
		  (,(r 'lambda) 
		   ,(map (lambda (a) (cadr a)) args)
		   ,@(if quals (cdddr form) (cddr form)) ) ) ) ) ] ) ) ) ) )



;;; External locations:

(##sys#extend-macro-environment
 'location
 '()
 (compiler-only-er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'location x '(location _))
    `(##core#location ,(cadr x)))))

(##sys#extend-macro-environment
 'define-location
 `((begin . ,(alist-ref 'begin me0)))
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-location form '(_ variable _ . #(_ 0 1)))
    (let ((var (cadr form))
	  (type (caddr form))
	  (init (optional (cdddr form) #f))
	  (name (r (gensym))))
      `(,(r 'begin)
	(##core#define-foreign-variable ,var ,type ,(symbol->string name))
	(##core#define-external-variable ,var ,type #f ,name)
	,@(if (pair? init)
	      `((##core#set! ,var ,(car init)))
	      '() ) ) ) ) ) )

(##sys#extend-macro-environment
 'let-location
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'let-location form '(_ #((variable _ . #(_ 0 1)) 0) . _))
    (let* ((bindings (cadr form))
	   (body (cddr form))
	   (aliases (map (lambda (_) (r (gensym))) bindings)))
      `(##core#let
	,(append-map
	  (lambda (b a)
	    (if (pair? (cddr b))
		(list (cons a (cddr b)))
		'() ) )
	  bindings aliases)
	,(let loop ((bindings bindings) (aliases aliases))
	   (if (null? bindings)
	       `(##core#let () ,@body)
	       (let ((b (car bindings))
		     (a (car aliases))
		     (rest (loop (cdr bindings) (cdr aliases))))
		 (if (= 3 (length b))
		     `(##core#let-location
		       ,(car b)
		       ,(cadr b)
		       ,a
		       ,rest)
		     `(##core#let-location
		       ,(car b)
		       ,(cadr b)
		       ,rest) ) ))))))))


;;; Embedding code directly:

(##sys#extend-macro-environment
 'foreign-code
 `((declare . ,(alist-ref 'declare me0)))
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-code form '(_ . #(string 0)))
    (let ([tmp (gensym 'code_)])
      `(##core#begin
	 (,(r 'declare)
	  (foreign-declare
	   ,(sprintf "static C_word ~A() { ~A\n; return C_SCHEME_UNDEFINED; }\n" 
		     tmp
		     (string-intersperse (cdr form) "\n")) ) )
	 (##core#inline ,tmp) ) ) ) ) )

(##sys#extend-macro-environment
 'foreign-value
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-value form '(_ _ _))
    (let ((tmp (gensym "code_"))
	  (code (cadr form)))
      `(##core#begin
	(##core#define-foreign-variable ,tmp
	 ,(caddr form)
	 ,(cond ((string? code) code)
		((symbol? code) (symbol->string code))
		(else
		 (syntax-error
		  'foreign-value
		  "bad argument type - not a string or symbol" 
		  code))))
	(##core#the ,(chicken.compiler.support#foreign-type->scrutiny-type
		      (chicken.syntax#strip-syntax (caddr form))
		      'result) 
		    #f ,tmp) ) ) ) ) )


;;; Include foreign code fragments

(##sys#extend-macro-environment
 'foreign-declare
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-declare form '(_ . #(string 0)))
    `(##core#declare (foreign-declare ,@(cdr form))))))


;;; Aliases for internal forms

(define (annotate-foreign-procedure e argtypes rtype)
  (let ((scrut-atypes (map (cut chicken.compiler.support#foreign-type->scrutiny-type <> 'arg)
			   (chicken.syntax#strip-syntax argtypes)))
	(scrut-rtype (and rtype
			  (chicken.compiler.support#foreign-type->scrutiny-type
			   (chicken.syntax#strip-syntax rtype) 'result))))
    ;; Don't add type annotation if the scrutinizer can infer the same
    ;; or better.
    ;;
    ;; At least these cases should work:
    ;;
    ;;   (-> <some-known-type>)	=> annotate
    ;;   (-> *)			=> no annotation
    ;;   (* ... -> *)		=> no annotation
    ;;
    (if (and (or (not rtype) (eq? scrut-rtype '*))
	     (every (cut eq? '* <>) scrut-atypes))
	e
	`(##core#the
	  (procedure ,scrut-atypes
		     ,@(if rtype
			   (list scrut-rtype)
			   ;; Special case for C_values(...). Only
			   ;; triggered by foreign-primitive.
			   '*))
	  #f
	  ,e))))

(##sys#extend-macro-environment
 'define-foreign-type
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-foreign-type form '(_ symbol _ . #(_ 0 2)))
    `(##core#define-foreign-type ,@(cdr form)))))

(##sys#extend-macro-environment
 'define-foreign-variable
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-foreign-variable form '(_ symbol _ . #(string 0 1)))
    `(##core#define-foreign-variable ,@(cdr form)))))

(##sys#extend-macro-environment
 'foreign-primitive
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-primitive form '(_ _ . _))
    (let* ((hasrtype (and (pair? (cddr form)) (not (string? (caddr form)))))
	   (rtype (and hasrtype (cadr form)))
	   (args (if hasrtype (caddr form) (cadr form)))
	   (argtypes (map car args)))
      (annotate-foreign-procedure `(##core#foreign-primitive ,@(cdr form))
				  argtypes
				  rtype)))))

(##sys#extend-macro-environment
 'foreign-lambda
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-lambda form '(_ _ _ . _))
    (annotate-foreign-procedure `(##core#foreign-lambda ,@(cdr form))
				(cdddr form)
				(cadr form)))))

(##sys#extend-macro-environment
 'foreign-lambda*
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-lambda* form '(_ _ _ _ . _))
    (annotate-foreign-procedure `(##core#foreign-lambda* ,@(cdr form))
				(map car (caddr form))
				(cadr form)))))

(##sys#extend-macro-environment
 'foreign-safe-lambda
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-safe-lambda form '(_ _ _ . _))
    (annotate-foreign-procedure `(##core#foreign-safe-lambda ,@(cdr form))
				(cdddr form)
				(cadr form)))))

(##sys#extend-macro-environment
 'foreign-safe-lambda*
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-safe-lambda* form '(_ _ _ _ . _))
    (annotate-foreign-procedure `(##core#foreign-safe-lambda* ,@(cdr form))
				(map car (caddr form))
				(cadr form)))))

(##sys#extend-macro-environment
 'foreign-type-size
 '()
 (compiler-only-er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'foreign-type-size form '(_ _))
    (let* ((t (chicken.syntax#strip-syntax (cadr form)))
	   (tmp (gensym "code_"))
	   (decl
	    (if (string? t)
		t
		;; TODO: Backend should be configurable
		(chicken.compiler.c-backend#foreign-type-declaration t ""))))
      `(##core#begin
	(##core#define-foreign-variable ,tmp size_t ,(string-append "sizeof(" decl ")"))
	(##core#the fixnum #f ,tmp))))))


(macro-subset me0)))
