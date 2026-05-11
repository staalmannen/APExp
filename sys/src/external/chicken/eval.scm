;;;; eval.scm - Interpreter for CHICKEN
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
  (unit eval)
  (uses modules)
  (not inline ##sys#alias-global-hook ##sys#user-read-hook ##sys#syntax-error-hook))

#>
#ifndef C_INSTALL_EGG_HOME
# define C_INSTALL_EGG_HOME    "."
#endif

#ifndef C_INSTALL_SHARE_HOME
# define C_INSTALL_SHARE_HOME NULL
#endif

#ifndef C_BINARY_VERSION
# define C_BINARY_VERSION      0
#endif
<#

(module chicken.eval
  (eval-handler module-environment)

(import scheme
	chicken.base
	chicken.blob
	chicken.fixnum
	chicken.internal
	chicken.keyword
	chicken.syntax
	chicken.type)

(include "common-declarations.scm")

(define-syntax d (syntax-rules () ((_ . _) (void))))

;;; Compile lambda to closure:

(define (eval-decorator p ll h cntr)
  (##sys#decorate-lambda
   p 
   (lambda (x) (and (not (##sys#immediate? x)) (##core#inline "C_lambdainfop" x)))
   (lambda (p i)
     (##sys#setslot 
      p i 
      (##sys#make-lambda-info 
       (let ((o (open-output-string)))
	 (write ll o)
	 (get-output-string o))))
     p) ) )

(define ##sys#unbound-in-eval #f)
(define ##sys#eval-debug-level (make-parameter 1))

(define compile-to-closure
  (let ((reverse reverse))
    (lambda (exp env #!optional cntr evalenv static tl?)
      (define-syntax thread-id
        (syntax-rules ()
          ((_ t) (##sys#slot t 14))))

      (define (find-id id se)		; ignores macro bindings
	(cond ((null? se) #f)
	      ((and (eq? id (caar se)) (symbol? (cdar se))) (cdar se))
	      (else (find-id id (cdr se)))))

      (define (rename var)
	(cond ((find-id var (##sys#current-environment)))
	      ((##sys#get var '##core#macro-alias) symbol? => values)
	      (else var)))

      (define (lookup var0 e)
	(let ((var (rename var0)))
	  (d `(LOOKUP/EVAL: ,var0 ,var ,e ,(map (lambda (x) (car x)) (##sys#current-environment))))
	  (let loop ((envs e) (ei 0))
	    (cond ((null? envs) (values #f var))
		  ((posq var (##sys#slot envs 0)) => (lambda (p) (values ei p)))
		  (else (loop (##sys#slot envs 1) (fx+ ei 1))) ) ) ))

      (define (posq x lst)
	(let loop ((lst lst) (i 0))
	  (cond ((null? lst) #f)
		((eq? x (##sys#slot lst 0)) i)
		(else (loop (##sys#slot lst 1) (fx+ i 1))) ) ) )

      (define (emit-trace-info tf ln info cntr e v)
	(when tf
	  (##core#inline 
	   "C_emit_trace_info"
	   ln
	   info
	   (##sys#make-structure 'frameinfo cntr e v)
	   (thread-id ##sys#current-thread) ) ) )
      
      (define (emit-syntax-trace-info tf info cntr) 
	(when tf
	  (##core#inline
	   "C_emit_trace_info"
	   (or (get-line-number info) "<syntax>")
	   info
	   cntr
           (thread-id ##sys#current-thread) ) ) )
	
      (define (decorate p ll h cntr)
	(eval-decorator p ll h cntr))

      (define (handle-expansion-result outer-ln)
	(lambda (input output)
	  (and-let* (((not (eq? input output)))
		     (ln (or (get-line-number input) outer-ln)))
	    (##sys#update-line-number-database! output ln))
	  output))

      (define (compile x e h tf cntr tl?)
	(cond ((keyword? x) (lambda v x))
	      ((symbol? x)
	       (receive (i j) (lookup x e)
		 (cond ((not i)
			(let ((var (cond ((not (symbol? j)) x) ; syntax?
					 ((assq x (##sys#current-environment)) j)
					 ((not static)
                                          (##sys#alias-global-hook j #f cntr))
                                         ((not (eq? x j)) j) ; has macro-alias
                                         (else #f))))
			  (when (and ##sys#unbound-in-eval
				     (or (not var)
					 (not (##sys#symbol-has-toplevel-binding? var))))
			    (set! ##sys#unbound-in-eval
			      (cons (cons var cntr) ##sys#unbound-in-eval)) )
			  (cond ((not var)
				 (lambda (v)
				   (##sys#error "unbound variable" x)))
				((##sys#symbol-has-toplevel-binding? var)
				 (lambda v (##sys#slot var 0)))
				(else
				 (lambda v (##core#inline "C_fast_retrieve" var))))))
                      (else
                       (case i
                         ((0) (lambda (v) 
                                (##sys#slot (##sys#slot v 0) j)))
                         ((1) (lambda (v) 
                                (##sys#slot (##sys#slot (##sys#slot v 1) 0) j)))
                         ((2) (lambda (v) 
                                (##sys#slot 
                                 (##sys#slot (##sys#slot (##sys#slot v 1) 1) 0)
                                 j)))
                         ((3) (lambda (v) 
                                (##sys#slot 
                                 (##sys#slot
                                  (##sys#slot (##sys#slot (##sys#slot v 1) 1) 1)
                                  0)
                                 j)))
                         (else
                          (lambda (v)
                            (##sys#slot (##core#inline "C_u_i_list_ref" v i) j))))))))
	      [(##sys#number? x)
	       (case x
		 [(-1) (lambda v -1)]
		 [(0) (lambda v 0)]
		 [(1) (lambda v 1)]
		 [(2) (lambda v 2)]
		 [else (lambda v x)] ) ]
	      [(boolean? x)
	       (if x
		   (lambda v #t)
		   (lambda v #f) ) ]
	      ((or (char? x)
		   (eof-object? x)
		   (##core#inline "C_bwpp" x) ; TODO: Remove once we have a bootstrapping libchicken with bwp-object?
		   ;;(bwp-object? x)
		   (string? x)
		   (blob? x)
		   (vector? x)
		   (##sys#srfi-4-vector? x))
	       (lambda v x) )
	      [(not (pair? x)) 
	       (##sys#syntax-error/context "illegal non-atomic object" x)]
	      [(symbol? (##sys#slot x 0))
	       (emit-syntax-trace-info tf x cntr)
	       (let* ((ln (get-line-number x))
		      (x2 (fluid-let ((chicken.syntax#expansion-result-hook
				       (handle-expansion-result ln)))
			    (expand x (##sys#current-environment)))))
		 (d `(EVAL/EXPANDED: ,x2))
		 (if (not (eq? x2 x))
		     (compile x2 e h tf cntr tl?)
		     (let ((head (rename (##sys#slot x 0))))
		       ;; here we did't resolve ##core#primitive, but that is done in compile-call (via 
		       ;; a normal walking of the operator)
		       (case head

			 [(##core#quote)
			  (let* ((c (strip-syntax (cadr x))))
			    (case c
			      [(-1) (lambda v -1)]
			      [(0) (lambda v 0)]
			      [(1) (lambda v 1)]
			      [(2) (lambda v 2)]
			      [(#t) (lambda v #t)]
			      [(#f) (lambda v #f)]
			      [(()) (lambda v '())]
			      [else (lambda v c)] ) ) ]

			 ((##core#syntax)
			  (let ((c (cadr x)))
			    (lambda v c)))

			 [(##core#check)
			  (compile (cadr x) e h tf cntr #f) ]

			 [(##core#immutable)
			  (compile (cadr x) e #f tf cntr #f) ]
		   
			 [(##core#undefined) (lambda (v) (##core#undefined))]

			 [(##core#if)
			  (let* ((test (compile (cadr x) e #f tf cntr #f))
				 (cns (compile (caddr x) e #f tf cntr #f))
				 (alt (if (pair? (cdddr x))
					  (compile (cadddr x) e #f tf cntr #f)
					  (compile '(##core#undefined) e #f tf cntr #f) ) ) )
			    (lambda (v) (if (##core#app test v) (##core#app cns v) (##core#app alt v))) ) ]

			 [(##core#begin)
			  (let* ((body (##sys#slot x 1))
				 (len (length body)) )
			    (case len
			      ((0) (compile '(##core#undefined) e #f tf cntr tl?))
			      ((1) (compile (##sys#slot body 0) e #f tf cntr tl?))
			      ((2) (let* ((x1 (compile (##sys#slot body 0) e #f tf cntr tl?))
					  (x2 (compile (cadr body) e #f tf cntr tl?)) )
				     (lambda (v) (##core#app x1 v) (##core#app x2 v)) ) )
			      (else
			       (let* ((x1 (compile (##sys#slot body 0) e #f tf cntr tl?))
				      (x2 (compile (cadr body) e #f tf cntr tl?))
				      (x3 (compile `(##core#begin ,@(##sys#slot (##sys#slot body 1) 1)) e #f tf cntr tl?)) )
				 (lambda (v) (##core#app x1 v) (##core#app x2 v) (##core#app x3 v)) ) ) ) ) ]

			 ((##core#ensure-toplevel-definition)
			  (unless tl?
			    (##sys#error "toplevel definition in non-toplevel context for variable" (cadr x)))
                          (##sys#put/restore! (cadr x) '##sys#override 'value)
			  (compile
			   '(##core#undefined) e #f tf cntr #f))

			 [(##core#set!)
			  (let ((var (cadr x)))
			    (receive (i j) (lookup var e)
			      (let ((val (compile (caddr x) e var tf cntr #f)))
				(cond ((not i)
				       (when ##sys#notices-enabled
					 (and-let* ((a (assq var (##sys#current-environment)))
						    ((symbol? (cdr a))))
					   (##sys#notice "assignment to imported value binding" var)))
				       (if static
					   (lambda (v)
					     (##sys#error 'eval "environment is not mutable" evalenv var)) ;XXX var?
					   (let ((var (##sys#alias-global-hook j #t cntr)))
					     (lambda (v)
					       (let ((result (##core#app val v)))
						 (##core#inline "C_i_persist_symbol" var)
						 (##sys#setslot var 0 result))))))
				      ((zero? i) (lambda (v) (##sys#setslot (##sys#slot v 0) j (##core#app val v))))
				      (else
				       (lambda (v)
					 (##sys#setslot
					  (##core#inline "C_u_i_list_ref" v i) j (##core#app val v))))))))]

			 [(##core#let)
			  (let* ((bindings (cadr x))
				 (n (length bindings)) 
				 (vars (map (lambda (x) (car x)) bindings))
				 (aliases (map gensym vars))
				 (e2 (cons aliases e))
				 (se2 (##sys#extend-se (##sys#current-environment) vars aliases))
				 (body (parameterize ((##sys#current-environment se2))
					 (compile-to-closure
					  (##sys#canonicalize-body (cddr x) (##sys#current-environment) #f)
					  e2 cntr evalenv static #f)) ) )
			    (case n
			      ((1) (let ([val (compile (cadar bindings) e (car vars) tf cntr #f)])
				     (lambda (v)
				       (##core#app body (cons (vector (##core#app val v)) v)) ) ) )
			      ((2) (let ((val1 (compile (cadar bindings) e (car vars) tf cntr #f))
					 (val2 (compile (cadadr bindings) e (cadr vars) tf cntr #f)) )
				     (lambda (v)
				       (##core#app body (cons (vector (##core#app val1 v) (##core#app val2 v)) v)) ) ) )
			      ((3) (let* ((val1 (compile (cadar bindings) e (car vars) tf cntr #f))
					  (val2 (compile (cadadr bindings) e (cadr vars) tf cntr #f))
					  (t (cddr bindings))
					  (val3 (compile (cadar t) e (caddr vars) tf cntr #f)) )
				     (lambda (v)
				       (##core#app 
					body
					(cons (vector (##core#app val1 v) (##core#app val2 v) (##core#app val3 v)) v)) ) ) )
			      ((4) (let* ((val1 (compile (cadar bindings) e (car vars) tf cntr #f))
					  (val2 (compile (cadadr bindings) e (cadr vars) tf cntr #f))
					  (t (cddr bindings))
					  (val3 (compile (cadar t) e (caddr vars) tf cntr #f))
					  (val4 (compile (cadadr t) e (cadddr vars) tf cntr #f)) )
				     (lambda (v)
				       (##core#app 
					body
					(cons (vector (##core#app val1 v)
						      (##core#app val2 v)
						      (##core#app val3 v)
						      (##core#app val4 v))
					      v)) ) ) )
			      [else
			       (let ((vals (map (lambda (x) (compile (cadr x) e (car x) tf cntr #f)) bindings)))
				 (lambda (v)
				   (let ([v2 (##sys#make-vector n)])
				     (do ([i 0 (fx+ i 1)]
					  [vlist vals (##sys#slot vlist 1)] )
					 ((fx>= i n))
				       (##sys#setslot v2 i (##core#app (##sys#slot vlist 0) v)) )
				     (##core#app body (cons v2 v)) ) ) ) ] ) ) ]

			 ((##core#letrec*)
			  (let ((bindings (cadr x))
				(body (cddr x)) )
			    (compile
			     `(##core#let
			       ,(##sys#map (lambda (b)
					     (list (car b) '(##core#undefined))) 
					   bindings)
			       ,@(##sys#map (lambda (b)
					      `(##core#set! ,(car b) ,(cadr b))) 
					    bindings)
			       (##core#let () ,@body) )
			     e h tf cntr #f)))

			((##core#letrec)
			 (let* ((bindings (cadr x))
				(vars (map car bindings))
				(tmps (map gensym vars))
				(body (cddr x)) )
			   (compile
			    `(##core#let
			      ,(map (lambda (b)
				      (list (car b) '(##core#undefined))) 
				    bindings)
			      (##core#let ,(map (lambda (t b) (list t (cadr b))) tmps bindings)
					  ,@(map (lambda (v t)
						   `(##core#set! ,v ,t))
						 vars tmps)
					  (##core#let () ,@body) ) )
			      e h tf cntr #f)))

			 [(##core#lambda)
			  (##sys#check-syntax 'lambda x '(_ lambda-list . #(_ 1)) #f (##sys#current-environment))
			  (let* ([llist (cadr x)]
				 [body (cddr x)] 
				 [info (cons (or h '?) llist)] )
			    (when (##sys#extended-lambda-list? llist)
			      (set!-values 
			       (llist body) 
			       (##sys#expand-extended-lambda-list 
				llist body ##sys#syntax-error-hook (##sys#current-environment)) ) ) 
			    (##sys#decompose-lambda-list
			     llist
			     (lambda (vars argc rest)
			       (let* ((aliases (map gensym vars))
				      (se2 (##sys#extend-se (##sys#current-environment) vars aliases))
				      (e2 (cons aliases e))
				      (body
				       (parameterize ((##sys#current-environment se2))
					 (compile-to-closure
					  (##sys#canonicalize-body body se2 #f)
					  e2 (or h cntr) evalenv static #f)) ) )
				 (case argc
				   [(0) (if rest
					    (lambda (v)
					      (decorate
					       (lambda r
						 (##core#app body (cons (vector r) v)))
					       info h cntr) )
					    (lambda (v)
					      (decorate
					       (lambda () (##core#app body (cons #f v)))
					       info h cntr) ) ) ]
				   [(1) (if rest
					    (lambda (v)
					      (decorate
					       (lambda (a1 . r)
						 (##core#app body (cons (vector a1 r) v)))
					       info h cntr) ) 
					    (lambda (v)
					      (decorate 
					       (lambda (a1)
						 (##core#app body (cons (vector a1) v)))
					       info h cntr) ) ) ]
				   [(2) (if rest
					    (lambda (v) 
					      (decorate
					       (lambda (a1 a2 . r)
						 (##core#app body (cons (vector a1 a2 r) v)))
					       info h cntr) )
					    (lambda (v)
					      (decorate
					       (lambda (a1 a2)
						 (##core#app body (cons (vector a1 a2) v)))
					       info h cntr) ) ) ]
				   [(3) (if rest
					    (lambda (v) 
					      (decorate
					       (lambda (a1 a2 a3 . r)
						 (##core#app body (cons (vector a1 a2 a3 r) v)))
					       info h cntr) )
					    (lambda (v)
					      (decorate
					       (lambda (a1 a2 a3)
						 (##core#app body (cons (vector a1 a2 a3) v)))
					       info h cntr) ) ) ]
				   [(4) (if rest
					    (lambda (v)
					      (decorate
					       (lambda (a1 a2 a3 a4 . r)
						 (##core#app body (cons (vector a1 a2 a3 a4 r) v)))
					       info h cntr) )
					    (lambda (v)
					      (decorate
					       (lambda (a1 a2 a3 a4)
						 (##core#app body (##sys#cons (##sys#vector a1 a2 a3 a4) v)))
					       info h cntr) ) ) ]
				   [else 
				    (if rest
					(lambda (v)
					  (decorate
					   (lambda as
					     (##core#app
					      body
					      (##sys#cons (apply ##sys#vector (fudge-argument-list argc as)) v)) )
					   info h cntr) )
					(lambda (v)
					  (decorate
					   (lambda as 
					     (let ([len (length as)])
					       (if (not (fx= len argc))
						   (##sys#error "bad argument count" argc len)
						   (##core#app body (##sys#cons (apply ##sys#vector as) v)))))
					   info h cntr) ) ) ] ) ) ) ) ) ]

			 ((##core#let-syntax)
			  (parameterize
			      ((##sys#current-environment
				(append
				 (map (lambda (b)
					(list
					 (car b)
					 (##sys#current-environment)
					 (##sys#ensure-transformer
					  (##sys#eval/meta (cadr b))
					  (strip-syntax (car b)))))
				      (cadr x) )
				 (##sys#current-environment)) ) )
			    (compile
			     (##sys#canonicalize-body (cddr x) (##sys#current-environment) #f)
			     e #f tf cntr #f)))
			       
			 ((##core#letrec-syntax)
			  (let* ((ms (map (lambda (b)
					    (list
					     (car b)
					     #f
					     (##sys#ensure-transformer
					      (##sys#eval/meta (cadr b))
					      (strip-syntax (car b)))))
					  (cadr x) ) )
				 (se2 (append ms (##sys#current-environment))) )
			    (for-each 
			     (lambda (sb)
			       (set-car! (cdr sb) se2) )
			     ms)
			    (parameterize ((##sys#current-environment se2))
			     (compile
			      (##sys#canonicalize-body (cddr x) (##sys#current-environment) #f)
			      e #f tf cntr #f))))
			       
			 ((##core#define-syntax)
			  (let* ((var (cadr x))
				 (body (caddr x))
				 (name (rename var)))
			    (when (and static (not (assq var (##sys#current-environment))))
			      (##sys#error 'eval "environment is not mutable" evalenv var))
                            (##sys#put/restore! name '##sys#override 'syntax)
			    (##sys#register-syntax-export 
			     name (##sys#current-module)
			     body)	; not really necessary, it only shouldn't be #f
			    (##sys#extend-macro-environment
			     name
			     (##sys#current-environment)
			     (##sys#eval/meta body))
			    (compile '(##core#undefined) e #f tf cntr #f) ) )

			 ((##core#define-compiler-syntax)
			  (compile '(##core#undefined) e #f tf cntr #f))

			 ((##core#let-compiler-syntax)
			  (compile
			   (##sys#canonicalize-body (cddr x) (##sys#current-environment) #f)
			   e #f tf cntr #f))

			 ((##core#include)
			  (##sys#include-forms-from-file
			   (cadr x)
			   (caddr x)
			   (lambda (forms path)
			     (let ((code (if (pair? (cdddr x)) ; body?
			 	     	     (##sys#canonicalize-body
				               (append forms (cadddr x))
				               (##sys#current-environment))
				             `(##core#begin ,@forms))))
			       (fluid-let ((##sys#current-source-filename path))
			         (compile code e #f tf cntr tl?))))))

			 ((##core#let-module-alias)
			  (##sys#with-module-aliases
			   (map (lambda (b)
				  (##sys#check-syntax 'functor b '(symbol symbol))
				  (strip-syntax b))
				(cadr x))
			   (lambda ()
			     (compile `(##core#begin ,@(cddr x)) e #f tf cntr tl?))))

			 ((##core#module)
			  (let* ((x (strip-syntax x))
				 (name (cadr x))
				 (exports 
				  (or (eq? #t (caddr x))
				      (map (lambda (exp)
					     (cond ((symbol? exp) exp)
						   ((and (pair? exp) 
							 (let loop ((exp exp))
							   (or (null? exp)
							       (and (symbol? (car exp))
								    (loop (cdr exp))))))
						    exp)
						   (else
						    (##sys#syntax-error-hook
						     'module
						     "invalid export syntax" exp name))))
					   (caddr x)))))
			    (when (##sys#current-module)
			      (##sys#syntax-error-hook 'module "modules may not be nested" name))
			    (parameterize ((##sys#current-module
					    (##sys#register-module name #f exports))
					   (##sys#current-environment '())
					   (##sys#macro-environment 
					    ##sys#initial-macro-environment)
					   (##sys#module-alias-environment
					    (##sys#module-alias-environment)))
			      (##sys#with-property-restore
			       (lambda ()
				 (let loop ((body (cdddr x)) (xs '()))
				   (if (null? body)
				       (let ((xs (reverse xs)))
					 (##sys#finalize-module (##sys#current-module))
					 (##sys#provide (module-requirement name))
					 (lambda (v)
					   (let loop2 ((xs xs))
					     (if (null? xs)
						 (##sys#void)
						 (let ((n (cdr xs)))
						   (cond ((pair? n)
							  ((car xs) v)
							  (loop2 n))
							 (else
							  ((car xs) v))))))))
				       (loop 
					(cdr body)
					(cons (compile 
					       (car body) 
					       '() #f tf cntr 
					       #t) ; reset back to toplevel!
					      xs))))) ) )))

			 [(##core#loop-lambda)
			  (compile `(,(rename 'lambda) ,@(cdr x)) e #f tf cntr #f) ]

			 [(##core#provide)
			  (compile `(##sys#provide (##core#quote ,(cadr x))) e #f tf cntr #f)]

			 [(##core#require-for-syntax)
			  (chicken.load#load-extension (cadr x) #f #f)
			  (compile '(##core#undefined) e #f tf cntr #f)]

			 [(##core#require)
			  (let ((lib (cadr x))
				(mod (and (pair? (cddr x)) (caddr x))))
			    (compile (##sys#process-require lib mod #f) e #f tf cntr #f))]

			 [(##core#elaborationtimeonly ##core#elaborationtimetoo) ; <- Note this!
			  (##sys#eval/meta (cadr x))
			  (compile '(##core#undefined) e #f tf cntr tl?) ]

			 [(##core#compiletimetoo)
			  (compile (cadr x) e #f tf cntr tl?) ]

			 [(##core#compiletimeonly ##core#callunit ##core#local-specialization)
			  (compile '(##core#undefined) e #f tf cntr tl?) ]

			 [(##core#declare)
			  (##sys#notice "declarations are ignored in interpreted code" x)
			  (compile '(##core#undefined) e #f tf cntr #f) ]

			 [(##core#define-inline ##core#define-constant)
			  (compile `(,(rename 'define) ,@(cdr x)) e #f tf cntr tl?) ]
                   
			 [(##core#primitive ##core#inline ##core#inline_allocate ##core#foreign-lambda 
					    ##core#define-foreign-variable 
					    ##core#define-external-variable ##core#let-location
					    ##core#foreign-primitive ##core#location
					    ##core#foreign-lambda* ##core#define-foreign-type)
			  (##sys#syntax-error-hook "cannot evaluate compiler-special-form" x) ]

			 [(##core#app)
			  (compile-call (cdr x) e tf cntr (##sys#current-environment)) ]

			 ((##core#the)
			  (compile (cadddr x) e h tf cntr tl?))
			 
			 ((##core#typecase)
			  ;; drops exp and requires "else" clause
			  (cond ((assq 'else (strip-syntax (cdddr x))) =>
				 (lambda (cl)
				   (compile (cadr cl) e h tf cntr tl?)))
				(else
				 (##sys#syntax-error-hook
				  'compiler-typecase
				  "no `else-clause' in unresolved `compiler-typecase' form"
				  x))))

			 (else
			  (fluid-let ((##sys#syntax-context (cons head ##sys#syntax-context)))
			    (compile-call x e tf cntr (##sys#current-environment))))))))]
	      
	      [else
	       (emit-syntax-trace-info tf x cntr)
	       (compile-call x e tf cntr (##sys#current-environment))] ) )

      (define (fudge-argument-list n alst)
	(if (null? alst) 
	    (list alst)
	    (do ((n n (fx- n 1))
		 (c 0 (fx+ c 1))
		 (args alst 
		       (if (eq? '() args)
			   (##sys#error "bad argument count" n c)
			   (##sys#slot args 1)))
		 (last #f args) )
		((fx= n 0)
		 (##sys#setslot last 1 (list args))
		 alst) ) ) )

      (define (checked-length lst)
	(let loop ([lst lst] [n 0])
	  (cond [(null? lst) n]
		[(pair? lst) (loop (##sys#slot lst 1) (fx+ n 1))]
		[else #f] ) ) )

      (define (compile-call x e tf cntr se)
	(let* ((head (##sys#slot x 0))
	       (fn (if (procedure? head) 
		       (lambda _ head)
		       (compile (##sys#slot x 0) e #f tf cntr #f)))
	       (args (##sys#slot x 1))
	       (argc (checked-length args))
	       (info x)
	       (ln (or (get-line-number info) "<eval>")))
	  (case argc
	    ((#f) (##sys#syntax-error/context "malformed expression" x))
	    ((0) (lambda (v)
		   (emit-trace-info tf ln info cntr e v)
		   ((##core#app fn v))))
	    ((1) (let ((a1 (compile (##sys#slot args 0) e #f tf cntr #f)))
		   (lambda (v)
		     (emit-trace-info tf ln info cntr e v)
		     ((##core#app fn v) (##core#app a1 v))) ) )
	    ((2) (let* ((a1 (compile (##sys#slot args 0) e #f tf cntr #f))
			(a2 (compile (##core#inline "C_u_i_list_ref" args 1) e #f tf cntr #f)) )
		   (lambda (v)
		     (emit-trace-info tf ln info cntr e v)
		     ((##core#app fn v) (##core#app a1 v) (##core#app a2 v))) ) )
	    ((3) (let* ((a1 (compile (##sys#slot args 0) e #f tf cntr #f))
			(a2 (compile (##core#inline "C_u_i_list_ref" args 1) e #f tf cntr #f))
			(a3 (compile (##core#inline "C_u_i_list_ref" args 2) e #f tf cntr #f)) )
		   (lambda (v)
		     (emit-trace-info tf ln info cntr e v)
		     ((##core#app fn v) (##core#app a1 v) (##core#app a2 v) (##core#app a3 v))) ) )
	    ((4) (let* ((a1 (compile (##sys#slot args 0) e #f tf cntr #f))
			(a2 (compile (##core#inline "C_u_i_list_ref" args 1) e #f tf cntr #f))
			(a3 (compile (##core#inline "C_u_i_list_ref" args 2) e #f tf cntr #f))
			(a4 (compile (##core#inline "C_u_i_list_ref" args 3) e #f tf cntr #f)) )
		   (lambda (v)
		     (emit-trace-info tf ln info cntr e v)
		     ((##core#app fn v) (##core#app a1 v) (##core#app a2 v) (##core#app a3 v) (##core#app a4 v))) ) )
	    (else (let ((as (##sys#map (lambda (a) (compile a e #f tf cntr #f)) args)))
		    (lambda (v)
		      (emit-trace-info tf ln info cntr e v)
		      (apply (##core#app fn v) (##sys#map (lambda (a) (##core#app a v)) as))) ) ) ) ) )

      (compile exp env #f (fx> (##sys#eval-debug-level) 0) cntr tl?) ) ) )


;;; evaluate in the macro-expansion/compile-time environment
(define (##sys#eval/meta form)
  (parameterize ((##sys#current-module #f)
		 (##sys#macro-environment (##sys#meta-macro-environment))
		 (##sys#current-environment (##sys#current-meta-environment)))
    (dynamic-wind
	void
	(lambda ()
	  ((compile-to-closure
	    form
	    '() 
	    #f #f #f			;XXX evalenv? static?
	    #t)				; toplevel.
	   '()) )
	(lambda ()
	  ;; Just before restoring the parameters, update "meta"
	  ;; environments to receive a copy of the current
	  ;; environments one level "down".  We don't support more
	  ;; than two evaluation phase levels currently.  XXX: Should
	  ;; we change this to a "stack" of environments?
	  (##sys#current-meta-environment (##sys#current-environment))
	  (##sys#meta-macro-environment (##sys#macro-environment))))))

(define eval-handler
  (make-parameter
   (lambda (x #!optional env)
     (let ((se (##sys#current-environment)))
       ;; When se is empty, it's the first time eval was called:
       ;; ensure an active default environment.  We do it here because
       ;; eval does not work yet at the end of modules.scm, and we
       ;; don't want to inject calls into every toplevel (see #1437)
       (when (null? se)
	 ((compile-to-closure
	   `(##core#begin (import-for-syntax ,@default-syntax-imports)
			  (import ,@default-imports))
	   '() #f #f #f #t) '()))
       (cond (env
	      (##sys#check-structure env 'environment 'eval)
	      (let ((se2 (##sys#slot env 2)))
		((if se2		; not interaction-environment?
		     (parameterize ((##sys#macro-environment '())
				    (##sys#current-environment se2))
		       (compile-to-closure x '() #f env (##sys#slot env 3) #t))
		     (compile-to-closure x '() #f env #f #t))
		 '() ) ) )
	     (else
	      ((compile-to-closure x '() #f #f #f #t) '())))))))

(set! scheme#eval
  (lambda (x . env)
    (apply (eval-handler) x env)))

;;; User-facing `module-environment` procedure:

(define (module-environment name)
  (chicken.module#module-environment name))


;;; Setting properties dynamically scoped

(define-values (##sys#put/restore! ##sys#with-property-restore)
  (let ((trail '())
	(restoring #f))
    (values
     (lambda (sym prop val)
       (when restoring
	 (set! trail (cons (list sym prop (##sys#get sym prop)) trail)))
       (##sys#put! sym prop val)
       val)
     (lambda (thunk)
       (let ((t0 #f)
	     (r0 restoring))
	 (dynamic-wind
	     (lambda ()
	       (set! t0 trail)
	       (set! restoring #t))
	     thunk
	     (lambda ()
	       (do () ((eq? t0 trail))
		 (apply ##sys#put! (car trail))
		 (set! trail (cdr trail)))
	       (set! restoring r0))))))))


;;; Split lambda-list into its parts:

(define ##sys#decompose-lambda-list
  (let ([reverse reverse])
    (lambda (llist0 k)

      (define (err)
	(set! ##sys#syntax-error-culprit #f)
	(##sys#syntax-error-hook "illegal lambda-list syntax" llist0) )

      (let loop ([llist llist0] [vars '()] [argc 0])
	(cond [(eq? llist '()) (k (reverse vars) argc #f)]
	      [(not (##core#inline "C_blockp" llist)) (err)]
	      [(##core#inline "C_symbolp" llist) (k (reverse (cons llist vars)) argc llist)]
	      [(not (##core#inline "C_pairp" llist)) (err)]
	      [else (loop (##sys#slot llist 1)
			  (cons (##sys#slot llist 0) vars)
			  (fx+ argc 1) ) ] ) ) ) ) )

(set! scheme#interaction-environment
  (let ((e (##sys#make-structure 'environment 'interaction-environment #f #f)))
    (lambda () e)))

(set-record-printer! 'environment
  (lambda (e p)
    (##sys#print "#<environment " #f p)
    (##sys#print (##sys#slot e 1) #f p)
    (##sys#write-char-0 #\> p)))

(let* ((r4s (chicken.module#module-environment 'r4rs 'scheme-report-environment/4))
       (r5s (chicken.module#module-environment 'scheme 'scheme-report-environment/5))
       (r4n (chicken.module#module-environment 'r4rs-null 'null-environment/4))
       (r5n (chicken.module#module-environment 'r5rs-null 'null-environment/5)))
  (define (strip se)
    (foldr
     (lambda (s r)
       (if (memq (car s)
		 '(cond-expand
		   define-interface
		   delay-force
		   export
                   export/rename
		   functor
		   import
		   import-for-syntax
		   import-syntax
		   import-syntax-for-syntax
		   letrec*
		   module
		   reexport
		   require-library
		   syntax))
	   r
	   (cons s r)))
     '()
     se))
  ;; Strip non-std syntax from SEs
  (##sys#setslot r4s 2 (strip (##sys#slot r4s 2)))
  (##sys#setslot r4n 2 (strip (##sys#slot r4n 2)))
  (##sys#setslot r5s 2 (strip (##sys#slot r5s 2)))
  (##sys#setslot r5n 2 (strip (##sys#slot r5n 2)))
  (set! scheme#scheme-report-environment
    (lambda (n)
      (##sys#check-fixnum n 'scheme-report-environment)
      (case n
	((4) r4s)
	((5) r5s)
	(else
	 (##sys#error
	  'scheme-report-environment
	  "unsupported scheme report environment version" n)))))
  (set! scheme#null-environment
    (lambda (n)
      (##sys#check-fixnum n 'null-environment)
      (case n
	((4) r4n)
	((5) r5n)
	(else
	 (##sys#error
	  'null-environment
	  "unsupported null environment version" n))))))

) ; eval module


(module chicken.load
  (dynamic-load-libraries set-dynamic-load-mode!
   load-library load-noisily load-relative load-verbose
   provide provided? require)

(import scheme
	chicken.base
	chicken.eval
	chicken.fixnum
	chicken.foreign
	chicken.internal
	chicken.platform
	chicken.syntax
	chicken.time)

(include "mini-srfi-1.scm")

;;; Installation locations

(define-foreign-variable binary-version int "C_BINARY_VERSION")
(define-foreign-variable install-lib-name c-string "C_INSTALL_LIB_NAME")
(define-foreign-variable uses-soname? bool "C_USES_SONAME")

;;; Core unit information

;; this maps built-in library names to require forms when the mapping isn't 1:1
(define-constant core-unit-requirements
  '((chicken.foreign
     . (##core#require-for-syntax chicken-ffi-syntax))
    (chicken.condition
     . (##core#begin
	(##core#require-for-syntax chicken-syntax)
	(##core#require library)))))

;; this list contains built-in units that are provided by libchicken
;; and should not be treated as separate extension libraries during
;; linking (they are omitted from types/inline/link files etc.)
(define-constant core-units
  '(chicken-syntax chicken-ffi-syntax continuation data-structures
    debugger-client eval eval-modules expand extras file internal
    irregex library lolevel pathname port posix profiler read-syntax
    repl scheduler srfi-4 tcp))

(define-constant cygwin-default-dynamic-load-libraries '("cygchicken-0"))
(define-constant macosx-load-library-extension ".dylib")
(define-constant windows-load-library-extension ".dll")
(define-constant hppa-load-library-extension ".sl")
(define-constant default-load-library-extension ".so")
(define-constant source-file-extension ".scm")

(define load-library-extension
  (cond ((eq? (software-type) 'windows) windows-load-library-extension)
	((eq? (software-version) 'macosx) macosx-load-library-extension)
	((and (eq? (software-version) 'hpux)
	      (eq? (machine-type) 'hppa)) hppa-load-library-extension)
	(else default-load-library-extension)))

(define ##sys#load-dynamic-extension default-load-library-extension)

(define (chicken.load#core-library? id) ; used by core.scm
  (or (memq id core-units)
      (assq id core-unit-requirements)))

(define default-dynamic-load-libraries
  (case (software-version)
    ((cygwin) cygwin-default-dynamic-load-libraries)
    (else `(,(string-append "lib" install-lib-name)))))


;;; Library registration (used for code loading):

(define (##sys#provide id)
  (##core#inline_allocate ("C_a_i_provide" 8) id))

(define (##sys#provided? id)
  (##core#inline "C_i_providedp" id))


;;; Pathname helpers:

(define path-separators
  (if ##sys#windows-platform '(#\\ #\/) '(#\/)))

(define (path-separator-index/right s)
  (let loop ((i (fx- (##sys#size s) 1)))
    (if (memq (##core#inline "C_subchar" s i) path-separators)
	i
	(and (fx< 0 i) (loop (fx- i 1))))))

(define (make-relative-pathname from file)
  (let ((i (and (string? from)
		(positive? (##sys#size file)) ; XXX probably an error?
		(not (memq (##core#inline "C_subchar" file 0) path-separators))
		(path-separator-index/right from))))
    (if (not i) file (string-append (##sys#substring from 0 i) "/" file))))


;;; Loading source/object files:

(define load-verbose (make-parameter (##sys#debug-mode?)))

(define ##sys#current-load-filename #f)
(define ##sys#dload-disabled #f)

(define-foreign-variable _dlerror c-string "C_dlerror")

(define (set-dynamic-load-mode! mode)
  (let ([mode (if (pair? mode) mode (list mode))]
	[now #f]
	[global #t] )
    (let loop ([mode mode])
      (when (pair? mode)
	(case (##sys#slot mode 0)
	  [(global) (set! global #t)]
	  [(local) (set! global #f)]
	  [(lazy) (set! now #f)]
	  [(now) (set! now #t)]
	  [else (##sys#signal-hook 'set-dynamic-load-mode! "invalid dynamic-load mode" (##sys#slot mode 0))] )
	(loop (##sys#slot mode 1)) ) )
    (##sys#set-dlopen-flags! now global) ) )

(define (toplevel name)
  (if (not name)
      "toplevel"
      (##sys#string-append
       (string->c-identifier (##sys#slot name 1))
       "_toplevel")))

(define (c-toplevel name loc)
  (##sys#make-c-string (##sys#string-append "C_" (toplevel name)) loc))

(define load/internal
  (let ((write write)
	(display display)
	(newline newline)
	(eval eval)
	(open-input-file open-input-file)
	(close-input-port close-input-port))
    (lambda (input evaluator #!optional pf timer printer unit)

      (define evalproc
	(or evaluator eval))

      ;; dload doesn't consider filenames without slashes to be paths,
      ;; so we prepend a dot to force a relative pathname.
      (define (dload-path path)
	(if (path-separator-index/right path)
	    path
	    (##sys#string-append "./" path)))

      (define (dload path)
	(let ((c-path (##sys#make-c-string (dload-path path) 'load)))
	  (or (##sys#dload c-path (c-toplevel unit 'load))
	      (and (symbol? unit)
		   (##sys#dload c-path (c-toplevel #f 'load))))))

      (define dload?
	(and (not ##sys#dload-disabled)
	     (feature? #:dload)))

      (define fname
	(cond ((port? input) #f)
	      ((not (string? input))
	       (##sys#signal-hook #:type-error 'load "bad argument type - not a port or string" input))
	      ((##sys#file-exists? input #t #f 'load) input)
	      ((let ((f (##sys#string-append input ##sys#load-dynamic-extension)))
		 (and dload? (##sys#file-exists? f #t #f 'load) f)))
	      ((let ((f (##sys#string-append input source-file-extension)))
		 (and (##sys#file-exists? f #t #f 'load) f)))
	      (else
	       (##sys#signal-hook #:file-error 'load "cannot open file" input))))

      (when (and (load-verbose) fname)
	(display "; loading ")
	(display fname)
	(display " ...\n")
	(flush-output))

      (or (and fname dload? (dload fname))
	  (call-with-current-continuation
	   (lambda (abrt)
	     (fluid-let ((##sys#read-error-with-line-number #t)
			 (##sys#current-load-filename fname)
			 (##sys#current-source-filename fname))
	       (let ((in (if fname (open-input-file fname) input))
		     (read-with-source-info chicken.syntax#read-with-source-info)) ; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing
		 (##sys#dynamic-wind
		  (lambda () #f)
		  (lambda ()
		    (let ((c1 (peek-char in)))
		      (when (eq? c1 (integer->char 127))
			(##sys#error
			 'load
			 (##sys#string-append
			  "unable to load compiled module - "
			  (or _dlerror "unknown reason"))
			 fname)))
		    (let ((x1 (read-with-source-info in)))
		      (do ((x x1 (read-with-source-info in)))
			  ((eof-object? x))
			(when printer (printer x))
			(##sys#call-with-values
			 (lambda ()
			   (if timer
			       (time (evalproc x))
			       (evalproc x)))
			 (lambda results
			   (when pf
			     (for-each
			      (lambda (r)
				(write r)
				(newline))
			      results)))))))
		  (lambda ()
		    (close-input-port in))))))))
      (##core#undefined))))

(set! scheme#load
  (lambda (filename #!optional evaluator)
    (load/internal filename evaluator)))

(define (load-relative filename #!optional evaluator)
  (let ((fn (make-relative-pathname ##sys#current-load-filename filename)))
    (load/internal fn evaluator)))

(define (load-noisily filename #!key (evaluator #f) (time #f) (printer #f))
  (load/internal filename evaluator #t time printer))

(define dynamic-load-libraries 
  (let ((ext
	 (if uses-soname?
	     (string-append
	      load-library-extension
	      "." 
	      (number->string binary-version))
	     load-library-extension)))
    (define complete
      (cut ##sys#string-append <> ext))
    (make-parameter
     (map complete default-dynamic-load-libraries)
     (lambda (x)
       (##sys#check-list x)
       x) ) ) )

(define (load-unit unit-name lib loc)
  (unless (##sys#provided? unit-name)
    (let ((libs
	   (if lib
	       (##sys#list lib)
	       (cons (##sys#string-append (##sys#slot unit-name 1) load-library-extension)
		     (dynamic-load-libraries))))
	  (top
	   (c-toplevel unit-name loc)))
      (when (load-verbose)
	(display "; loading library ")
	(display unit-name)
	(display " ...\n"))
      (let loop ((libs libs))
	(cond ((null? libs)
	       (##sys#error loc "unable to load library" unit-name (or _dlerror "library not found")))
	      ((##sys#dload (##sys#make-c-string (##sys#slot libs 0) 'load-library) top)
	       (##core#undefined))
	      (else
	       (loop (##sys#slot libs 1))))))))

(define (load-library unit-name #!optional lib)
  (##sys#check-symbol unit-name 'load-library)
  (unless (not lib) (##sys#check-string lib 'load-library))
  (load-unit unit-name lib 'load-library))

(define ##sys#include-forms-from-file
  (let ((call-with-input-file call-with-input-file)
        (reverse reverse))
    (lambda (filename source k)
      (let ((path (##sys#resolve-include-filename filename #t #f source))
            (read-with-source-info chicken.syntax#read-with-source-info)) ; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing
        (when (not path)
          (##sys#signal-hook #:file-error 'include "cannot open file" filename))
        (when (load-verbose)
          (print "; including " path " ..."))
        (call-with-input-file path
          (lambda (in)
            (k (fluid-let ((##sys#current-source-filename path))
                 (do ((x (read-with-source-info in) (read-with-source-info in))
                      (xs '() (cons x xs)))
                     ((eof-object? x)
                      (reverse xs))))
               path)))))))


;;; Extensions:

(define ##sys#setup-mode #f)

(define (file-exists? name) ; defined here to avoid file unit dependency
  (and (##sys#file-exists? name #t #f #f) name))

(define (find-file name search-path)
  (cond ((not search-path) #f)
        ((null? search-path) #f)
        ((string? search-path) (find-file name (list search-path)))
        ((file-exists? (string-append (car search-path) "/" name)))
        (else (find-file name (cdr search-path)))))

(define find-dynamic-extension
  (let ((string-append string-append))
    (lambda (id inc?)
      (let ((rp (repository-path))
	    (basename (if (symbol? id) (symbol->string id) id)))
	(define (check path)
	  (let ((p0 (string-append path "/" basename)))
	    (or (and rp
		     (not ##sys#dload-disabled)
		     (feature? #:dload)
		     (file-exists? (##sys#string-append p0 ##sys#load-dynamic-extension)))
		(file-exists? (##sys#string-append p0 source-file-extension)))))
	(let loop ((paths (##sys#append
			   (if ##sys#setup-mode '(".") '())
			   (or rp '())
			   (if inc? ##sys#include-pathnames '())
			   (if ##sys#setup-mode '() '("."))) ))
	  (and (pair? paths)
	       (let ((pa (##sys#slot paths 0)))
		 (or (check pa)
		     (loop (##sys#slot paths 1)) ) ) ) ) ) ) ))

(define-inline (extension-loaded? lib mod)
  (cond ((##sys#provided? lib))
	((eq? mod #t)
	 (##sys#provided? (module-requirement lib)))
	((symbol? mod)
	 (##sys#provided? (module-requirement mod)))
	(else #f)))

(define (load-extension lib mod loc)
  (unless (extension-loaded? lib mod)
    (cond ((memq lib core-units)
	   (load-unit lib #f loc))
	  ((find-dynamic-extension lib #f) =>
	   (lambda (ext)
	     (load/internal ext #f #f #f #f lib)
	     (##sys#provide lib)
	     (##core#undefined)))
	  (else
	   (##sys#error loc "cannot load extension" lib)))))

(define (require . ids)
  (for-each (cut ##sys#check-symbol <> 'require) ids)
  (for-each (cut load-extension <> #f 'require) ids))

(define (provide . ids)
  (for-each (cut ##sys#check-symbol <> 'provide) ids)
  (for-each (cut ##sys#provide <>) ids))

(define (provided? . ids)
  (for-each (cut ##sys#check-symbol <> 'provided?) ids)
  (every ##sys#provided? ids))

;; Export for internal use in the expansion of `##core#require':
(define chicken.load#load-unit load-unit)
(define chicken.load#load-extension load-extension)

;; Export for internal use in csc, modules and batch-driver:
(define chicken.load#find-file find-file)
(define chicken.load#find-dynamic-extension find-dynamic-extension)

;; Do the right thing with a `##core#require' form.
(define (##sys#process-require lib mod compile-mode)
  (let ((mod (or (eq? lib mod) mod)))
    (cond
      ((assq lib core-unit-requirements) => cdr)
      ((memq lib core-units)
       (if compile-mode
           `(##core#callunit ,lib)
           `(chicken.load#load-unit (##core#quote ,lib)
                                    (##core#quote #f)
                                    (##core#quote #f))))
      ((eq? compile-mode 'static)
       `(##core#callunit ,lib))
      (else
       `(chicken.load#load-extension (##core#quote ,lib)
                                     (##core#quote ,mod)
                                     (##core#quote #f))))))

;;; Find included file:

(define ##sys#resolve-include-filename
  (let ((string-append string-append) )
    (lambda (fname exts repo source)
      (define (test-extensions fname lst)
	(if (null? lst)
	    (and (file-exists? fname) fname)
	    (let ((fn (##sys#string-append fname (car lst))))
	      (or (file-exists? fn)
		  (test-extensions fname (cdr lst))))))
      (define (test fname)
	(test-extensions
	 fname
	 (cond ((pair? exts) exts)       ; specific list of extensions
	       ((not (feature? #:dload)) ; no dload -> source only
		(list source-file-extension))
	       ((not exts)               ; prefer compiled
		(list ##sys#load-dynamic-extension source-file-extension))
	       (else                     ; prefer source
		(list source-file-extension ##sys#load-dynamic-extension)))))
      (or (test (make-relative-pathname source fname))
	  (let loop ((paths (if repo
				(##sys#append 
				 ##sys#include-pathnames
				 (or (repository-path) '()) )
				##sys#include-pathnames) ) )
	    (cond ((eq? paths '()) #f)
		  ((test (string-append (##sys#slot paths 0)
					"/"
					fname) ) )
		  (else (loop (##sys#slot paths 1))) ) ) ) ) ) )

) ; chicken.load


;;; Simple invocation API:

(import scheme chicken.base chicken.condition chicken.eval chicken.fixnum chicken.load)

(declare
  (hide last-error run-safe store-result store-string
	CHICKEN_yield CHICKEN_eval CHICKEN_eval_string
	CHICKEN_eval_to_string CHICKEN_eval_string_to_string
	CHICKEN_apply CHICKEN_apply_to_string CHICKEN_eval_apply
	CHICKEN_read CHICKEN_load CHICKEN_get_error_message))

(define last-error #f)

(define (run-safe thunk)
  (set! last-error #f)
  (handle-exceptions ex 
      (let ((o (open-output-string)))
	(print-error-message ex o)
	(set! last-error (get-output-string o))
	#f)
    (thunk) ) )

#>
#define C_store_result(x, ptr)   (*((C_word *)C_block_item(ptr, 0)) = (x), C_SCHEME_TRUE)
<#

(define (store-result x result)
  (##sys#gc #f)
  (when result
    (##core#inline "C_store_result" x result) )
  #t)

(define-external (CHICKEN_yield) bool
  (run-safe (lambda () (begin (##sys#thread-yield!) #t))) )

(define-external (CHICKEN_eval (scheme-object exp) ((c-pointer "C_word") result)) bool
  (run-safe
   (lambda ()
     (store-result (eval exp) result))))

(define-external (CHICKEN_eval_string (c-string str) ((c-pointer "C_word") result)) bool
  (run-safe
   (lambda ()
     (let ((i (open-input-string str)))
       (store-result (eval (read i)) result)))))

#>
#define C_copy_result_string(str, buf, n)  (C_memcpy((char *)C_block_item(buf, 0), C_c_string(str), C_unfix(n)), ((char *)C_block_item(buf, 0))[ C_unfix(n) ] = '\0', C_SCHEME_TRUE)
<#

(define (store-string str bufsize buf)
  (let ((len (##sys#size str)))
    (cond ((fx>= len bufsize)
	   (set! last-error "Error: not enough room for result string")
	   #f)
	  (else (##core#inline "C_copy_result_string" str buf len)) ) ) )

(define-external (CHICKEN_eval_to_string (scheme-object exp) ((c-pointer "char") buf)
					  (int bufsize))
  bool
  (run-safe
   (lambda ()
     (let ((o (open-output-string)))
       (write (eval exp) o)
       (store-string (get-output-string o) bufsize buf)) ) ) )

(define-external (CHICKEN_eval_string_to_string (c-string str) ((c-pointer "char") buf)
						 (int bufsize) ) 
  bool
  (run-safe
   (lambda ()
     (let ((o (open-output-string)))
       (write (eval (read (open-input-string str))) o)
       (store-string (get-output-string o) bufsize buf)) ) ) )

(define-external (CHICKEN_apply (scheme-object func) (scheme-object args) 
				 ((c-pointer "C_word") result))
  bool
  (run-safe (lambda () (store-result (apply func args) result))) )

(define-external (CHICKEN_apply_to_string (scheme-object func) (scheme-object args) 
					   ((c-pointer "char") buf) (int bufsize))
  bool
  (run-safe
   (lambda ()
     (let ((o (open-output-string)))
       (write (apply func args) o) 
       (store-string (get-output-string o) bufsize buf)) ) ) )

(define-external (CHICKEN_read (c-string str) ((c-pointer "C_word") result)) bool
  (run-safe
   (lambda ()
     (let ((i (open-input-string str)))
       (store-result (read i) result) ) ) ) )

(define-external (CHICKEN_load (c-string str)) bool
  (run-safe (lambda () (load str) #t)))

(define-external (CHICKEN_get_error_message ((c-pointer "char") buf) (int bufsize)) void
  (store-string (or last-error "No error") bufsize buf) )
