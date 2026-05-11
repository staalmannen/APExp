;;;; chicken-syntax.scm - non-standard syntax extensions
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
  (unit chicken-syntax)
  (uses expand internal)
  (disable-interrupts)
  (fixnum) )

;; IMPORTANT: These macros expand directly into fully qualified names
;; from the scrutinizer and support modules.

#+(not debugbuild)
(declare
  (no-bound-checks)
  (no-procedure-checks))

(import (scheme)
        (chicken base)
        (chicken fixnum)
        (chicken syntax)
        (chicken internal)
        (chicken platform))

(include "common-declarations.scm")
(include "mini-srfi-1.scm")

;;; Exceptions:
(set! ##sys#chicken.condition-macro-environment
  (let ((me0 (##sys#macro-environment)))

(##sys#extend-macro-environment
 'handle-exceptions
 `((call-with-current-continuation . scheme#call-with-current-continuation))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'handle-exceptions form '(_ variable _ . _))
    (let ((k (r 'k))
	  (args (r 'args)))
      `((,(r 'call-with-current-continuation)
	 (##core#lambda
	  (,k)
	  (chicken.condition#with-exception-handler
	   (##core#lambda (,(cadr form)) (,k (##core#lambda () ,(caddr form))))
	   (##core#lambda
	    ()
	    (##sys#call-with-values
	     (##core#lambda () ,@(cdddr form))
	     (##core#lambda
	      ,args
	      (,k (##core#lambda () (##sys#apply ##sys#values ,args))))))))))))))

(##sys#extend-macro-environment
 'condition-case
 `((memv . scheme#memv))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'condition-case form '(_ _ . _))
    (let ((exvar (r 'exvar))
	  (kvar (r 'kvar))
	  (%and (r 'and))
	  (%memv (r 'memv))
	  (%else (r 'else)))
      (define (parse-clause c)
	(let* ((var (and (symbol? (car c)) (car c)))
	       (kinds (if var (cadr c) (car c)))
	       (body (if var
			 `(##core#let ((,var ,exvar)) ,@(cddr c))
			 `(##core#let () ,@(cdr c)))))
	  (if (null? kinds)
	      `(,%else ,body)
	      `((,%and ,kvar ,@(map (lambda (k)
				      `(,%memv (##core#quote ,k) ,kvar)) kinds))
		,body))))
      `(,(r 'handle-exceptions) ,exvar
	(##core#let ((,kvar (,%and (##sys#structure? ,exvar
						     (##core#quote condition))
				   (##sys#slot ,exvar 1))))
		    ,(let ((clauses (map parse-clause (cddr form))))
		       `(,(r 'cond)
			 ,@clauses
			 ,@(if (assq %else clauses)
			       `()   ; Don't generate two else clauses
			       `((,%else (chicken.condition#signal ,exvar)))))))
	,(cadr form))))))

(macro-subset me0 ##sys#default-macro-environment)))


;;; type-related syntax

(set! ##sys#chicken.type-macro-environment
  (let ((me0 (##sys#macro-environment)))

(##sys#extend-macro-environment
 ': '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax ': x '(_ symbol _ . _))
    (if (not (memq #:compiling ##sys#features))
	'(##core#undefined)
	(let* ((type1 (strip-syntax (caddr x)))
	       (name1 (cadr x)))
	  ;; we need pred/pure info, so not using
	  ;; "chicken.compiler.scrutinizer#check-and-validate-type"
	  (let-values (((type pred pure)
			(chicken.compiler.scrutinizer#validate-type
			 type1
			 (strip-syntax name1))))
	    (cond ((not type)
		   (syntax-error ': "invalid type syntax" name1 type1))
		  (else
		   `(##core#declare
		     (type (,name1 ,type1 ,@(cdddr x)))
		     ,@(if pure `((pure ,name1)) '())
		     ,@(if pred `((predicate (,name1 ,pred))) '()))))))))))

(##sys#extend-macro-environment
 'the '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'the x '(_ _ _))
    (if (not (memq #:compiling ##sys#features))
	(caddr x)
	`(##core#the ,(chicken.compiler.scrutinizer#check-and-validate-type (cadr x) 'the)
		     #t
		     ,(caddr x))))))

(##sys#extend-macro-environment
 'assume '()
 (syntax-rules ()
   ((_ ((var type) ...) body ...)
    (let ((var (the type var)) ...) body ...))))

(##sys#extend-macro-environment
 'define-specialization '()
 (##sys#er-transformer
  (lambda (x r c)
    (cond ((not (memq #:compiling ##sys#features)) '(##core#undefined))
	  (else
	   (##sys#check-syntax 'define-specialization x '(_ (variable . #(_ 0)) _ . #(_ 0 1)))
	   (let* ((head (cadr x))
		  (name (car head))
		  (args (cdr head))
		  (alias (gensym name))
		  (rtypes (and (pair? (cdddr x)) (strip-syntax (caddr x))))
		  (%define (r 'define))
		  (body (if rtypes (cadddr x) (caddr x))))
	     (let loop ((args args) (anames '()) (atypes '()))
	       (cond ((null? args)
		      (let ((anames (reverse anames))
			    (atypes (reverse atypes))
			    (spec
			     `(,alias ,@(let loop2 ((anames anames) (i 1))
					  (if (null? anames)
					      '()
					      (cons (vector i)
						    (loop2 (cdr anames) (fx+ i 1))))))))
			`(##core#begin
			  (##core#local-specialization
			   ,name
			   ,alias
			   ,(cons atypes
				  (if (and rtypes (pair? rtypes))
				      (list
				       (map (cut chicken.compiler.scrutinizer#check-and-validate-type
					      <>
					      'define-specialization)
					    rtypes)
				       spec)
				      (list spec))))
			  (##core#declare (inline ,alias) (hide ,alias))
			  (,%define (,alias ,@anames)
				    (##core#let ,(map (lambda (an at)
							(list an `(##core#the ,at #t ,an)))
						      anames atypes)
						,body)))))
		     (else
		      (let ((arg (car args)))
			(cond ((symbol? arg)
			       (loop (cdr args) (cons arg anames) (cons '* atypes)))
			      ((and (list? arg) (fx= 2 (length arg)) (symbol? (car arg)))
			       (loop
				(cdr args)
				(cons (car arg) anames)
				(cons
				 (chicken.compiler.scrutinizer#check-and-validate-type
				  (cadr arg)
				  'define-specialization)
				 atypes)))
			      (else (syntax-error
				     'define-specialization
				     "invalid argument syntax" arg head)))))))))))))

(##sys#extend-macro-environment
 'compiler-typecase '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'compiler-typecase x '(_ _ . #((_ . #(_ 1)) 1)))
    (let ((val (memq #:compiling ##sys#features))
	  (var (gensym))
	  (ln (get-line-number x)))
      `(##core#let ((,var ,(cadr x)))
	 (##core#typecase
	  ,ln
	  ,var		; must be variable (see: CPS transform)
	  ,@(map (lambda (clause)
		 (let ((hd (strip-syntax (car clause))))
		   (list
		    (if (eq? hd 'else)
			'else
			(if val
			    (chicken.compiler.scrutinizer#check-and-validate-type
			     hd
			     'compiler-typecase)
			    hd))
		    `(##core#begin ,@(cdr clause)))))
		 (cddr x))))))))

(##sys#extend-macro-environment
 'define-type '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'define-type x '(_ variable _))
    (cond ((not (memq #:compiling ##sys#features)) '(##core#undefined))
	  (else
	   (let ((name (strip-syntax (cadr x)))
		 (%quote (r 'quote))
		 (t0 (strip-syntax (caddr x))))
	     `(##core#elaborationtimeonly
	       (##sys#put/restore!
		(,%quote ,name)
		(,%quote ##compiler#type-abbreviation)
		(,%quote
		 ,(chicken.compiler.scrutinizer#check-and-validate-type
		   t0 'define-type name))))))))))

(macro-subset me0 ##sys#default-macro-environment)))

;;; Syntax-related syntax (for use in macro transformers)

(set! ##sys#chicken.syntax-macro-environment
  (let ((me0 (##sys#macro-environment)))

(##sys#extend-macro-environment
 'syntax
 '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'syntax x '(_ _))
    `(##core#syntax ,(cadr x)))))

(##sys#extend-macro-environment
 'begin-for-syntax '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'begin-for-syntax x '(_ . #(_ 0)))
    (##sys#register-meta-expression `(##core#begin ,@(cdr x)))
    `(##core#elaborationtimeonly (##core#begin ,@(cdr x))))))

(##sys#extend-macro-environment
 'define-for-syntax '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-for-syntax form '(_ _ . _))
    `(,(r 'begin-for-syntax)
      (,(r 'define) ,@(cdr form))))))


;;; Compiler syntax

(##sys#extend-macro-environment
 'define-compiler-syntax '()
 (syntax-rules ()
   ((_ name)
    (##core#define-compiler-syntax name #f))
   ((_ name transformer)
    (##core#define-compiler-syntax name transformer))))

(##sys#extend-macro-environment
 'let-compiler-syntax '()
 (syntax-rules ()
   ((_ (binding ...) body ...)
    (##core#let-compiler-syntax (binding ...) body ...))))

(macro-subset me0 ##sys#default-macro-environment)))


;;; Non-standard macros that provide core/"base" functionality:

(set! ##sys#chicken.base-macro-environment
  (let ((me0 (##sys#macro-environment)))

(##sys#extend-macro-environment
 'define-constant
 '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-constant form '(_ variable _))
    `(##core#define-constant ,@(cdr form)))))

(##sys#extend-macro-environment
 'define-record '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'define-record x '(_ variable . _))
    (let* ((type-name (cadr x))
	   (plain-name (strip-syntax type-name))
	   (prefix (symbol->string plain-name))
	   (tag (if (##sys#current-module)
		    (symbol-append
		     (##sys#module-name (##sys#current-module)) '|#| plain-name)
		    plain-name))
	   (slots (cddr x))
	   (%define (r 'define))
	   (%setter (r 'chicken.base#setter))
	   (%getter-with-setter (r 'chicken.base#getter-with-setter))
	   (slotnames
	    (map (lambda (slot)
		   (cond ((symbol? slot) slot)
			 ((and (pair? slot)
			       (c (car slot) %setter) 
			       (pair? (cdr slot))
			       (symbol? (cadr slot))
			       (null? (cddr slot)))
			  (cadr slot))
			 (else
			  (syntax-error
			   'define-record "invalid slot specification" slot))))
		 slots)))
      `(##core#begin
	(,%define ,type-name (##core#quote ,tag))
	(,%define 
	 ,(string->symbol (string-append "make-" prefix))
	 (##core#lambda 
	  ,slotnames
	  (##sys#make-structure (##core#quote ,tag) ,@slotnames)))
	(,%define
	 ,(string->symbol (string-append prefix "?"))
	 (##core#lambda (x) (##sys#structure? x (##core#quote ,tag))))
	,@(let mapslots ((slots slots) (i 1))
	    (if (eq? slots '())
		slots
		(let* ((a (car slots))
		       (has-setter (not (symbol? a)))
		       (slotname (symbol->string (if has-setter (cadr a) a)))
		       (setr (string->symbol (string-append prefix "-" slotname "-set!")))
		       (getr (string->symbol (string-append prefix "-" slotname)))
		       (setrcode
			`(##core#lambda 
			  (x val)
			  (##core#check (##sys#check-structure x (##core#quote ,tag)))
			  (##sys#block-set! x ,i val) ) ))
		  (cons
		   `(##core#begin
		     ,@(if has-setter
			   '()
			   `((,%define ,setr ,setrcode)))
		     (,%define
		      ,getr
		      ,(if has-setter
			   `(,%getter-with-setter
			     (##core#lambda
			      (x) 
			      (##core#check (##sys#check-structure x (##core#quote ,tag)))
			      (##sys#block-ref x ,i) )
			     ,setrcode)
			   `(##core#lambda 
			     (x)
			     (##core#check (##sys#check-structure x (##core#quote ,tag)))
			     (##sys#block-ref x ,i) ) ) ) )
		   (mapslots (##sys#slot slots 1) (fx+ i 1)) ) ) ) ) ) ) ) ) )

(##sys#extend-macro-environment
 'receive
 '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'receive form '(_ _ . #(_ 0)))
    (cond ((null? (cddr form))
	   `(##sys#call-with-values (##core#lambda () ,@(cdr form)) ##sys#list) )
	  (else
	   (##sys#check-syntax 'receive form '(_ lambda-list _ . #(_ 1)))
	   (let ((vars (cadr form))
		 (exp (caddr form))
		 (rest (cdddr form)))
	     (if (and (pair? vars) (null? (cdr vars)))
		 `(##core#let ((,(car vars) ,exp)) ,@rest)
		 `(##sys#call-with-values 
		   (##core#lambda () ,exp)
		   (##core#lambda ,vars ,@rest)) ) ) ) ) )))

(##sys#extend-macro-environment
 'declare '()
 (##sys#er-transformer
  (lambda (form r c)
    `(##core#declare ,@(cdr form)))))

(##sys#extend-macro-environment
 'delay-force
 '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'delay-force form '(_ _))
    `(##sys#make-promise (##core#lambda () ,(cadr form))))))

(##sys#extend-macro-environment
 'include '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'include form '(_ string))
    `(##core#include ,(cadr form) #f))))

(##sys#extend-macro-environment
 'include-relative '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'include-relative form '(_ string))
    `(##core#include ,(cadr form) ,##sys#current-source-filename))))

(##sys#extend-macro-environment
 'fluid-let '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'fluid-let form '(_ #((variable _) 0) . _))
     (let* ((clauses (cadr form))
	   (body (cddr form))
	   (ids (##sys#map car clauses))
	   (new-tmps (##sys#map (lambda (x) (r (gensym))) clauses))
	   (old-tmps (##sys#map (lambda (x) (r (gensym))) clauses)))
       `(##core#let
	 (,@(map ##sys#list new-tmps (##sys#map cadr clauses))
	  ,@(map ##sys#list old-tmps
		 (let loop ((n (length clauses)))
		   (if (eq? n 0)
		       '()
		       (cons #f (loop (fx- n 1))) ) ) ) )
	 (##sys#dynamic-wind
	  (##core#lambda ()
		    ,@(map (lambda (ot id) `(##core#set! ,ot ,id))
			   old-tmps ids)
		    ,@(map (lambda (id nt) `(##core#set! ,id ,nt))
			   ids new-tmps)
		    (##core#undefined) )
	  (##core#lambda () ,@body)
	  (##core#lambda ()
		    ,@(map (lambda (nt id) `(##core#set! ,nt ,id))
			   new-tmps ids)
		    ,@(map (lambda (id ot) `(##core#set! ,id ,ot))
			   ids old-tmps)
		    (##core#undefined) ) ) ) ) )))

(##sys#extend-macro-environment
 'parameterize '()
 (##sys#er-transformer
  (lambda (form r c)
    (define (pname p)
      (if (symbol? p)
	  (gensym p)
	  (gensym "parameter")))
    (##sys#check-syntax 'parameterize form '#(_ 2))
    (let* ((bindings (cadr form))
	   (body (cddr form))
	   (convert? (r 'convert?))
	   (params (##sys#map car bindings))
	   (vals (##sys#map cadr bindings))
	   (param-aliases (##sys#map (lambda (z) (r (pname z))) params))
	   (saveds (##sys#map (lambda (z) (r (gensym 'saved))) params))
	   (temps (##sys#map (lambda (z) (r (gensym 'tmp))) params)) )
      `(##core#let
	,(map ##sys#list param-aliases params) ; These may be expressions
	(##core#let
	 ,(map ##sys#list saveds vals)
	 (##core#let
	  ;; Inner names are actually set.  This hides the exact
	  ;; ordering of the let if any call/cc is used in the
	  ;; value expressions (see first example in #1336).
	  ,(map ##sys#list saveds saveds)
	  (##core#let
	   ((,convert? (##core#the boolean #t #t))) ; Convert only first time extent is entered!
	   (##sys#dynamic-wind
	    (##core#lambda ()
	      (##core#let
	       ;; First, call converters (which may throw exceptions!)
	       ,(map (lambda (p s temp)
		       `(,temp (##core#if ,convert? (,p ,s #t #f) ,s)))
		     param-aliases saveds temps)
	       ;; Save current values so we can restore them later
	       ,@(map (lambda (p s) `(##core#set! ,s (,p)))
		      param-aliases saveds)
	       ;; Set parameters to their new values.  This can't fail.
	       ,@(map (lambda (p t) `(,p ,t #f #t)) param-aliases temps)
	       ;; Remember we already converted (only call converters once!)
	       (##core#set! ,convert? #f)))
	    (##core#lambda () ,@body)
	    (##core#lambda ()
	      (##core#let
	       ;; Remember the current value of each parameter.
	       ,(map (lambda (p s temp) `(,temp (,p)))
		     param-aliases saveds temps)
	       ;; Restore each parameter to its old value.
	       ,@(map (lambda (p s) `(,p ,s #f #t)) param-aliases saveds)
	       ;; Save current value for later re-invocations.
	       ,@(map (lambda (s temp) `(##core#set! ,s ,temp))
		      saveds temps))))))))))))

(##sys#extend-macro-environment
 'require-library
 '()
 (##sys#er-transformer
  (lambda (x r c)
    `(##core#begin
      ,@(map (lambda (x)
	       (let-values (((name lib _ _ _ _) (##sys#decompose-import x r c 'import)))
		 (if (not lib)
		     '(##core#undefined)
		     `(##core#require ,lib ,name))))
	     (cdr x))))))

(##sys#extend-macro-environment
 'when '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'when form '#(_ 2))
    `(##core#if ,(cadr form)
		(##core#begin ,@(cddr form))))))

(##sys#extend-macro-environment
 'unless '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'unless form '#(_ 2))
    `(##core#if ,(cadr form)
		(##core#undefined)
		(##core#begin ,@(cddr form))))))

(##sys#extend-macro-environment
 'set!-values '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'set!-values form '(_ lambda-list _))
    (##sys#expand-multiple-values-assignment (cadr form) (caddr form)))))

(set! chicken.syntax#define-values-definition
  (##sys#extend-macro-environment
   'define-values '()
   (##sys#er-transformer
    (lambda (form r c)
      (##sys#check-syntax 'define-values form '(_ lambda-list _))
      `(##core#begin
	,@(##sys#decompose-lambda-list
	   (cadr form)
	   (lambda (vars argc rest)
	     (for-each (lambda (nm)
			 (let ((name (##sys#get nm '##core#macro-alias nm)))
			   (##sys#register-export name (##sys#current-module))))
		       vars)
	     (map (lambda (nm) `(##core#ensure-toplevel-definition ,nm))
		  vars)))
	,(##sys#expand-multiple-values-assignment (cadr form) (caddr form)))))))

(##sys#extend-macro-environment
 'let-values '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'let-values form '(_ list . _))
    (let ((vbindings (cadr form))
	  (body (cddr form)))
      (letrec ((append* (lambda (il l)
			  (if (not (pair? il))
			      (cons il l)
			      (cons (car il)
				    (append* (cdr il) l)))))
	       (map* (lambda (proc l)
		       (cond ((null? l) '())
			     ((not (pair? l)) (proc l))
			     (else (cons (proc (car l)) (map* proc (cdr l))))))))
	(let* ([llists (map car vbindings)]
	       [vars (let loop ((llists llists) (acc '()))
		       (if (null? llists)
			   acc
			   (let* ((llist (car llists))
				  (new-acc
				   (cond ((list? llist) (append llist acc))
					 ((pair? llist) (append* llist acc))
					 (else (cons llist acc)))))
			     (loop (cdr llists) new-acc))))]
	       [aliases (map (lambda (v) (cons v (r (gensym v)))) vars)]
	       [lookup (lambda (v) (cdr (assq v aliases)))]
	       [llists2 (let loop ((llists llists) (acc '()))
			  (if (null? llists)
			      (reverse acc)
			      (let* ((llist (car llists))
				     (new-acc
				      (cond ((not (pair? llist)) (cons (lookup llist) acc))
					    (else (cons (map* lookup llist) acc)))))
				(loop (cdr llists) new-acc))))])
	  (let fold ([llists llists]
		     [exps (map (lambda (x) (cadr x)) vbindings)]
		     [llists2 llists2] )
	    (cond ((null? llists)
		   `(##core#let
		     ,(map (lambda (v) (##sys#list v (lookup v))) vars) 
		     ,@body) )
		  ((and (pair? (car llists2)) (null? (cdar llists2)))
		   `(##core#let
		     ((,(caar llists2) ,(car exps)))
		     ,(fold (cdr llists) (cdr exps) (cdr llists2)) ) )
		  (else
		   `(##sys#call-with-values
		     (##core#lambda () ,(car exps))
		     (##core#lambda
		      ,(car llists2) 
		      ,(fold (cdr llists) (cdr exps) (cdr llists2))) ) ) ) ) ) ) ) ) ) )

(##sys#extend-macro-environment
 'let*-values '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'let*-values form '(_ list . _))
    (let ((vbindings (cadr form))
	  (body (cddr form))
	  (%let-values (r 'let-values)) )
      (let fold ([vbindings vbindings])
	(if (null? vbindings)
	    `(##core#let () ,@body)
	    `(,%let-values (,(car vbindings))
			   ,(fold (cdr vbindings))) ) ) ))))

;;XXX do we need letrec*-values ?
(##sys#extend-macro-environment
 'letrec-values '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'letrec-values form '(_ #((lambda-list . _) 0) . _))
    (let ((vbindings (cadr form))
          (body (cddr form)))
      (let ((vars  (map car vbindings))
            (exprs (map cadr vbindings)))
        `(##core#let
          ,(map (lambda (v) (##sys#list v '(##core#undefined)))
                (foldl (lambda (l v) ; flatten multi-value formals
                         (##sys#append l (##sys#decompose-lambda-list
					  v (lambda (a _ _) a))))
                       '()
                       vars))
          ,@(map ##sys#expand-multiple-values-assignment vars exprs)
          ,@body))))))

(##sys#extend-macro-environment
 'letrec*
 '()
 (##sys#er-transformer
  (lambda (x r c)
    (##sys#check-syntax 'letrec* x '(_ #((variable _) 0) . #(_ 1)))
    (check-for-multiple-bindings (cadr x) x "letrec*")
    `(##core#letrec* ,@(cdr x)))))

(##sys#extend-macro-environment
 'nth-value 
 `((list-ref . scheme#list-ref))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'nth-value form '(_ _ _))
    (let ((v (r 'tmp)))
      `(##sys#call-with-values
	(##core#lambda () ,(caddr form))
	(##core#lambda ,v (,(r 'list-ref) ,v ,(cadr form))))))))

(##sys#extend-macro-environment
 'define-inline '()
 (##sys#er-transformer
  (lambda (form r c)
    (letrec ([quotify-proc 
	      (lambda (xs id)
		(##sys#check-syntax id xs '#(_ 1))
		(let* ([head (car xs)]
		       [name (if (pair? head) (car head) head)]
		       [val (if (pair? head)
				`(##core#lambda ,(cdr head) ,@(cdr xs))
				(cadr xs) ) ] )
		  (when (or (not (pair? val)) 
			    (and (not (eq? '##core#lambda (car val)))
				 (not (c (r 'lambda) (car val)))))
		    (syntax-error
		     'define-inline "invalid substitution form - must be lambda"
		     name val) )
		  (list name val) ) ) ] )
      `(##core#define-inline ,@(quotify-proc (cdr form) 'define-inline)))) ) )

(##sys#extend-macro-environment
 'and-let* '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'and-let* form '(_ #(_ 0) . _))
    (let ((bindings (cadr form))
	  (body (cddr form)))
      (let fold ([bs bindings] [last #t])
	(if (null? bs)
	    `(##core#begin ,last . ,body)
	    (let ([b (car bs)]
		  [bs2 (cdr bs)] )
	      (cond [(not (pair? b))
                     (##sys#check-syntax 'and-let* b 'variable)
                     (let ((var (r (gensym))))
                       `(##core#let ((,var ,b))
                          (##core#if ,var ,(fold bs2 var) #f)))]
		    [(null? (cdr b))
                     (let ((var (r (gensym))))
                       `(##core#let ((,var ,(car b)))
                          (##core#if ,var ,(fold bs2 var) #f)))]
		    [else
		     (##sys#check-syntax 'and-let* b '(variable _))
		     (let ((var (car b)))
		       `(##core#let ((,var ,(cadr b)))
			 (##core#if ,var ,(fold bs2 var) #f)))]))))))))



;;; Optional argument handling:

;;; Copyright (C) 1996 by Olin Shivers.
;;;
;;; This file defines three macros for parsing optional arguments to procs:
;;; 	(LET-OPTIONALS  arg-list ((var1 default1) ...) . body)
;;; 	(LET-OPTIONALS* arg-list ((var1 default1) ...) . body)
;;; 	(:OPTIONAL rest-arg default-exp)
;;;
;;; The LET-OPTIONALS macro is defined using the Clinger/Rees
;;; explicit-renaming low-level macro system. You'll have to do some work to
;;; port it to another macro system.
;;;
;;; The LET-OPTIONALS* and :OPTIONAL macros are defined with simple
;;; high-level macros, and should be portable to any R4RS system.
;;;
;;; These macros are all careful to evaluate their default forms *only* if
;;; their values are needed.
;;;
;;; The only non-R4RS dependencies in the macros are ERROR 
;;; and CALL-WITH-VALUES.
;;; 	-Olin

;;; (LET-OPTIONALS arg-list ((var1 default1) ...) 
;;;   body
;;;   ...)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; This form is for binding a procedure's optional arguments to either
;;; the passed-in values or a default.
;;;
;;; The expression takes a rest list ARG-LIST and binds the VARi to
;;; the elements of the rest list. When there are no more elements, then
;;; the remaining VARi are bound to their corresponding DEFAULTi values.
;;;
;;; - The default expressions are *not* evaluated unless needed.
;;;
;;; - When evaluated, the default expressions are carried out in the *outer*
;;;   environment. That is, the DEFAULTi forms do *not* see any of the VARi
;;;   bindings.
;;;
;;;   I originally wanted to have the DEFAULTi forms get eval'd in a LET*
;;;   style scope -- DEFAULT3 would see VAR1 and VAR2, etc. But this is
;;;   impossible to implement without side effects or redundant conditional
;;;   tests. If I drop this requirement, I can use the efficient expansion
;;;   shown below. If you need LET* scope, use the less-efficient 
;;;   LET-OPTIONALS* form defined below.
;;;
;;; Example:
;;; (define (read-string! str . maybe-args)
;;;   (let-optionals maybe-args ((port (current-input-port))
;;;                              (start 0)
;;;                              (end (string-length str)))
;;;     ...))
;;;
;;; expands to:
;;; 
;;; (let* ((body (lambda (port start end) ...))
;;;        (end-def (lambda (%port %start) (body %port %start <end-default>)))
;;;        (start-def (lambda (%port) (end-def %port <start-default>)))
;;;        (port-def  (lambda () (start-def <port-def>))))
;;;   (if (null? rest) (port-def)
;;;       (let ((%port (car rest))
;;; 	        (rest (cdr rest)))
;;; 	  (if (null? rest) (start-def %port)
;;; 	      (let ((%start (car rest))
;;; 		    (rest (cdr rest)))
;;; 	        (if (null? rest) (end-def %port %start)
;;; 		    (let ((%end (car rest))
;;; 			  (rest (cdr rest)))
;;; 		      (if (null? rest) (body %port %start %end)
;;; 			  (error ...)))))))))


;;; (LET-OPTIONALS args ((var1 default1) ...) body1 ...)

(##sys#extend-macro-environment
 'let-optionals 
 `((null? . scheme#null?)
   (car . scheme#car)
   (cdr . scheme#cdr))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'let-optionals form '(_ _ . _))
    (let ((arg-list (cadr form))
	  (var/defs (caddr form))
	  (body (cdddr form)))

      ;; This guy makes the END-DEF, START-DEF, PORT-DEF definitions above.
      ;; I wish I had a reasonable loop macro.

      (define (make-default-procs vars body-proc defaulter-names defs rename)
	(let recur ((vars (reverse vars))
		    (defaulter-names (reverse defaulter-names))
		    (defs (reverse defs))
		    (next-guy body-proc))
	  (if (null? vars) '()
	      (let ((vars (cdr vars)))
		`((,(car defaulter-names)
		   (##core#lambda ,(reverse vars)
			     (,next-guy ,@(reverse vars) ,(car defs))))
		  . ,(recur vars
			    (cdr defaulter-names)
			    (cdr defs)
			    (car defaulter-names)))))))


      ;; This guy makes the (IF (NULL? REST) (PORT-DEF) ...) tree above.

      (define (make-if-tree vars defaulters body-proc rest rename)
	(let recur ((vars vars) (defaulters defaulters) (non-defaults '()))
	  (if (null? vars)
	      `(,body-proc . ,(reverse non-defaults))
	      (let ((v (car vars)))
		`(##core#if (,(r 'null?) ,rest)
		       (,(car defaulters) . ,(reverse non-defaults))
		       (##core#let ((,v (,(r 'car) ,rest)) ; we use car/cdr, because of rest-list optimization
			       (,rest (,(r 'cdr) ,rest)))
			      ,(recur (cdr vars)
				      (cdr defaulters)
				      (cons v non-defaults))))))))

      (##sys#check-syntax 'let-optionals var/defs '#((variable _) 0))
      (##sys#check-syntax 'let-optionals body '#(_ 1))
      (let* ((vars (map car var/defs))
	     (prefix-sym (lambda (prefix sym)
			   (string->symbol (string-append prefix (symbol->string sym)))))

	     ;; Private vars, one for each user var.
	     ;; We prefix the % to help keep macro-expanded code from being
	     ;; too confusing.
	     (vars2 (map (lambda (v) (r (prefix-sym "%" v)))
			 vars))

	     (defs (map cadr var/defs))
	     (body-proc (r 'body))

	     ;; A private var, bound to the value of the ARG-LIST expression.
	     (rest-var (r '_%rest))

	     (defaulter-names (map (lambda (var) (r (prefix-sym "def-" var)))
				   vars))

	     (defaulters (make-default-procs vars2 body-proc
					     defaulter-names defs gensym))
	     (if-tree (make-if-tree vars2 defaulter-names body-proc
				    rest-var gensym)))

	`(,(r 'let*) ((,rest-var ,arg-list)
		      (,body-proc (##core#lambda ,vars . ,body))
		      . ,defaulters)
	  ,if-tree) ) ))))


;;; (optional rest-arg default-exp)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; This form is for evaluating optional arguments and their defaults
;;; in simple procedures that take a *single* optional argument. It is
;;; a macro so that the default will not be computed unless it is needed.
;;; 
;;; REST-ARG is a rest list from a lambda -- e.g., R in
;;;     (lambda (a b . r) ...)
;;; - If REST-ARG has 0 elements, evaluate DEFAULT-EXP and return that.
;;; - If REST-ARG has 1 element, return that element.

(##sys#extend-macro-environment
 'optional 
 `((null? . scheme#null?)
   (car . scheme#car)
   (cdr . scheme#cdr) )
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'optional form '(_ _ . #(_ 0 1)))
    (let ((var (r 'tmp)))
      `(##core#let ((,var ,(cadr form)))
	(##core#if (,(r 'null?) ,var) 
		   ,(optional (cddr form) #f)
		   (,(r 'car) ,var)))))))


;;; (LET-OPTIONALS* args ((var1 default1) ... [rest]) body1 ...)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; This is just like LET-OPTIONALS, except that the DEFAULTi forms
;;; are evaluated in a LET*-style environment. That is, DEFAULT3 is evaluated
;;; within the scope of VAR1 and VAR2, and so forth.
;;;
;;; - If the last form in the ((var1 default1) ...) list is not a 
;;;   (VARi DEFAULTi) pair, but a simple variable REST, then it is
;;;   bound to any left-over values. For example, if we have VAR1 through
;;;   VAR7, and ARGS has 9 values, then REST will be bound to the list of
;;;   the two values of ARGS. If ARGS is too short, causing defaults to
;;;   be used, then REST is bound to '().

(##sys#extend-macro-environment
 'let-optionals* 
 `((null? . scheme#null?)
   (car . scheme#car)
   (cdr . scheme#cdr))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'let-optionals* form '(_ _ list . _))
    (let ((args (cadr form))
	  (var/defs (caddr form))
	  (body (cdddr form))
	  (%null? (r 'null?))
	  (%car (r 'car))
	  (%cdr (r 'cdr)))
      (let ((rvar (r 'tmp)))
	`(##core#let
	  ((,rvar ,args))
	  ,(let loop ((args rvar) (vardefs var/defs))
	     (if (null? vardefs)
		 `(##core#let () ,@body)
		 (let ((head (car vardefs)))
		   (if (pair? head)
		       (let ((rvar2 (r 'tmp2)))
			 `(##core#let ((,(car head) (##core#if (,%null? ,args)
							       ,(cadr head)
							       (,%car ,args)))
				       (,rvar2 (##core#if (,%null? ,args) 
							  (##core#quote ())
							  (,%cdr ,args))) )
				      ,(loop rvar2 (cdr vardefs)) ) )
		       `(##core#let ((,head ,args)) ,@body) ) ) ) ) ) ) ))))


;;; case-lambda (SRFI-16):

(##sys#extend-macro-environment
 'case-lambda 
 `((>= . scheme#>=)
   (car . scheme#car)
   (cdr . scheme#cdr)
   (eq? . scheme#eq?)
   (length . scheme#length))
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'case-lambda form '(_ . _))
    (define (genvars n)
      (let loop ([i 0])
	(if (fx>= i n)
	    '()
	    (cons (r (gensym)) (loop (fx+ i 1))) ) ) )
    (let* ((mincount (apply min (map (lambda (c)
				       (##sys#decompose-lambda-list 
					(car c)
					(lambda (vars argc rest) argc) ) )
				     (cdr form))))
	   (minvars (genvars mincount))
	   (rvar (r 'rvar))
	   (lvar (r 'lvar))
	   (%>= (r '>=))
	   (%eq? (r 'eq?))
	   (%car (r 'car))
	   (%cdr (r 'cdr))
	   (%length (r 'length)))
      `(##core#lambda
	,(append minvars rvar)
	(##core#let
        ((,lvar (,%length ,rvar)))
	 ,(foldr
	   (lambda (c body)
	     (##sys#decompose-lambda-list
	      (car c)
	      (lambda (vars argc rest)
		(##sys#check-syntax 'case-lambda (car c) 'lambda-list)
		`(##core#if ,(let ((a2 (fx- argc mincount)))
			       (if rest
				   (if (zero? a2)
				       #t
				       `(,%>= ,lvar ,a2) )
				   `(,%eq? ,lvar ,a2) ) )
			    ,(receive (vars1 vars2)
				 (split-at (take vars argc) mincount)
			       (let ((bindings
				      (let build ((vars2 vars2) (vrest rvar))
					(if (null? vars2)
					    (cond (rest `(##core#let ((,rest ,vrest)) ,@(cdr c)))
						  ((null? (cddr c)) (cadr c))
						  (else `(##core#let () ,@(cdr c))) )
					    (let ((vrest2 (r (gensym))))
					      `(##core#let ((,(car vars2) (,%car ,vrest))
							    (,vrest2 (,%cdr ,vrest)) )
							   ,(if (pair? (cdr vars2))
								(build (cdr vars2) vrest2)
								(build '() vrest2) ) ) ) ) ) ) )
				 (if (null? vars1)
				     bindings
				     `(##core#let ,(map list vars1 minvars) ,bindings) ) ) )
			    ,body) ) ) )
	   '(##core#check (##sys#error (##core#immutable (##core#quote "no matching clause in call to 'case-lambda' form"))))
	   (cdr form))))))))


;;; Record printing:

(##sys#extend-macro-environment
 'define-record-printer '() ;; DEPRECATED
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'define-record-printer form '(_ _ . _))
    (let ((head (cadr form))
	  (body (cddr form))
	  (%set-record-printer! (r 'chicken.base#set-record-printer!)))
      (cond [(pair? head)
	     (##sys#check-syntax 
	      'define-record-printer (cons head body)
	      '((variable variable variable) . #(_ 1)))
	     (let* ((plain-name (strip-syntax (##sys#slot head 0)))
		    (tag (if (##sys#current-module)
			     (symbol-append
			      (##sys#module-name (##sys#current-module))
			      '|#| plain-name)
			     plain-name)))
	       `(,%set-record-printer!
		 (##core#quote ,tag)
		 (##core#lambda ,(##sys#slot head 1) ,@body)))]
	    (else
	     (##sys#check-syntax 'define-record-printer (cons head body) '(variable _))
	     (let* ((plain-name (strip-syntax head))
		    (tag (if (##sys#current-module)
			     (symbol-append
			      (##sys#module-name (##sys#current-module))
			      '|#| plain-name)
			     plain-name)))
	       `(,%set-record-printer!
		 (##core#quote ,tag) ,@body))))))))

;;; SRFI-9:

(##sys#extend-macro-environment
 'define-record-type
 `()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 
     'define-record-type 
     form
     '(_ variable #(variable 1) variable . _)) 
    (let* ((type-name (cadr form))
	   (plain-name (strip-syntax type-name))
	   (tag (if (##sys#current-module)
		    (symbol-append
		     (##sys#module-name (##sys#current-module))
		     '|#| plain-name)
		    plain-name))
	   (conser (caddr form))
	   (pred (cadddr form))
	   (slots (cddddr form))
	   (%define (r 'define))
	   (%getter-with-setter (r 'chicken.base#getter-with-setter))
	   (vars (cdr conser))
	   (x (r 'x))
	   (y (r 'y))
	   (slotnames (map car slots)))
      ;; Check for inconsistencies in slot names vs constructor args
      (for-each (lambda (vname)
		  (unless (memq vname slotnames)
		    (syntax-error
		     'define-record-type
		     "unknown slot name in constructor definition"
		     vname)))
		vars)
      `(##core#begin
	;; TODO: Maybe wrap this in an opaque object?
	(,%define ,type-name (##core#quote ,tag))
	(,%define ,conser
		  (##sys#make-structure 
		   (##core#quote ,tag)
		   ,@(map (lambda (sname)
			    (if (memq sname vars)
				sname
				'(##core#undefined) ) )
			  slotnames) ) )
	(,%define (,pred ,x) (##sys#structure? ,x (##core#quote ,tag)))
	,@(let loop ([slots slots] [i 1])
	    (if (null? slots)
		'()
		(let* ((slot (car slots))
		       (settable (pair? (cddr slot))) 
		       (setr (and settable (caddr slot)))
		       (ssetter (and (pair? setr)
				     (pair? (cdr setr))
				     (c 'setter (car setr))
				     (cadr setr)))
		       (get `(##core#lambda 
			      (,x)
			      (##core#check
			       (##sys#check-structure
				,x
				(##core#quote ,tag)
				(##core#quote ,(cadr slot))))
			      (##sys#block-ref ,x ,i) ) )
		       (set (and settable
				 `(##core#lambda
				   (,x ,y)
				   (##core#check
				    (##sys#check-structure
				     ,x
				     (##core#quote ,tag)
				     (##core#quote ,ssetter)))
				   (##sys#block-set! ,x ,i ,y)) )))
		  `((,%define
		     ,(cadr slot) 
		     ,(if (and ssetter (c ssetter (cadr slot)))
			  `(,%getter-with-setter ,get ,set)
			  get))
		    ,@(if settable
			  (if ssetter
			      (if (not (c ssetter (cadr slot)))
				  `(((##sys#setter ##sys#setter) ,ssetter ,set))
				  '())
			      `((,%define ,setr ,set)))
			  '())
		    ,@(loop (cdr slots) (add1 i)) ) ) ) ) ) ) ) ) )


;;; SRFI-26:

(##sys#extend-macro-environment
 'cut 
 `((apply . scheme#apply))
 (##sys#er-transformer
  (lambda (form r c)
    (let ((%<> (r '<>))
	  (%<...> (r '<...>))
	  (%apply (r 'apply)))
      (when (null? (cdr form))
        (syntax-error 'cut "you need to supply at least a procedure" form))
      (let loop ([xs (cdr form)] [vars '()] [vals '()] [rest #f])
	(if (null? xs)
	    (let ([rvars (reverse vars)]
		  [rvals (reverse vals)] )
	      (if rest
		  (let ([rv (r (gensym))])
		    `(##core#lambda
		      (,@rvars . ,rv)
		      (,%apply ,(car rvals) ,@(cdr rvals) ,rv) ) )
		  ;;XXX should we drop the begin?
		  `(##core#lambda ,rvars ((##core#begin ,(car rvals)) ,@(cdr rvals)) ) ) )
	    (cond ((c %<> (car xs))
		   (let ([v (r (gensym))])
		     (loop (cdr xs) (cons v vars) (cons v vals) #f) ) )
		  ((c %<...> (car xs))
		   (if (null? (cdr xs))
		       (loop '() vars vals #t)
		       (syntax-error
			'cut
			"tail patterns after <...> are not supported"
			form)))
		  (else (loop (cdr xs) vars (cons (car xs) vals) #f)) ) ) ) ) )))

(##sys#extend-macro-environment
 'cute 
 `((apply . scheme#apply))
 (##sys#er-transformer
  (lambda (form r c)
    (let ((%apply (r 'apply))
	  (%<> (r '<>))
	  (%<...> (r '<...>)))
      (when (null? (cdr form))
        (syntax-error 'cute "you need to supply at least a procedure" form))
      (let loop ([xs (cdr form)] [vars '()] [bs '()] [vals '()] [rest #f])
	(if (null? xs)
	    (let ([rvars (reverse vars)]
		  [rvals (reverse vals)] )
	      (if rest
		  (let ([rv (r (gensym))])
		    `(##core#let 
		      ,bs
		      (##core#lambda (,@rvars . ,rv)
				(,%apply ,(car rvals) ,@(cdr rvals) ,rv) ) ) )
		  `(##core#let ,bs
			  (##core#lambda ,rvars (,(car rvals) ,@(cdr rvals)) ) ) ) )
	    (cond ((c %<> (car xs))
		   (let ([v (r (gensym))])
		     (loop (cdr xs) (cons v vars) bs (cons v vals) #f) ) )
		  ((c %<...> (car xs))
		   (if (null? (cdr xs))
		       (loop '() vars bs vals #t)
		       (syntax-error
			'cute
			"tail patterns after <...> are not supported"
			form)))
		  (else 
		   (let ([v (r (gensym))])
		     (loop (cdr xs) 
			   vars
			   (cons (list v (car xs)) bs)
			   (cons v vals) #f) ) ))))))))


;;; SRFI-31

(##sys#extend-macro-environment
 'rec '()
 (##sys#er-transformer
  (lambda (form r c)
    (##sys#check-syntax 'rec form '(_ _ . _))
    (let ((head (cadr form)))
      (if (pair? head)
	  `(##core#letrec* ((,(car head) 
			     (##core#lambda ,(cdr head)
					    ,@(cddr form))))
			   ,(car head))
	  `(##core#letrec* ((,head ,@(cddr form))) ,head))))))


;;; SRFI-55

(##sys#extend-macro-environment
 'require-extension
 '()
 (##sys#er-transformer
  (lambda (x r c)
    `(,(r 'import) ,@(cdr x)))))


;;; Assertions

(##sys#extend-macro-environment
 'assert '()
 (##sys#er-transformer
  (let ((string-append string-append))
    (lambda (form r c)
      (##sys#check-syntax 'assert form '#(_ 1))
      (let* ((exp (cadr form))
	     (msg-and-args (cddr form))
	     (msg (optional msg-and-args "assertion failed"))
	     (tmp (r 'tmp)))
	(when (string? msg)
	  (and-let* ((ln (get-line-number form)))
	    (set! msg (string-append "(" ln ") " msg))))
	`(##core#let ((,tmp ,exp))
	   (##core#if (##core#check ,tmp)
		      ,tmp
		      (##sys#error
		       ,msg
		       ,@(if (pair? msg-and-args)
			     (cdr msg-and-args)
			     `((##core#quote ,(strip-syntax exp))))))))))))

(macro-subset me0 ##sys#default-macro-environment)))


;;; "time"

(set! ##sys#chicken.time-macro-environment
  (let ((me0 (##sys#macro-environment)))

(##sys#extend-macro-environment
 'time '()
 (##sys#er-transformer
  (lambda (form r c)
    (let ((rvar (r 't)))
      `(##core#begin
	(##sys#start-timer)
	(##sys#call-with-values
	 (##core#lambda () ,@(cdr form))
	 (##core#lambda
	  ,rvar
	  (##sys#display-times (##sys#stop-timer))
	  (##sys#apply ##sys#values ,rvar))))))))

(macro-subset me0 ##sys#default-macro-environment)))

;; register features

(register-feature! 'srfi-2 'srfi-8 'srfi-9 'srfi-11 'srfi-15 'srfi-16 'srfi-26 'srfi-31 'srfi-55)
