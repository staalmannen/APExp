;;;; modules.scm - module-system support
;
; Copyright (c) 2011-2022, The CHICKEN Team
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


;; this unit needs the "eval" unit, but must be initialized first, so it doesn't
;; declare "eval" as used - if you use "-explicit-use", take care of this.

(declare
  (unit modules)
  (uses chicken-syntax)
  (disable-interrupts)
  (fixnum)
  (not inline ##sys#alias-global-hook)
  (hide check-for-redef compiled-module-dependencies find-export
	find-module/import-library match-functor-argument merge-se
	module-indirect-exports module-rename register-undefined))

(import scheme
	chicken.base
	chicken.internal
	chicken.keyword
	chicken.platform
	chicken.syntax
	(only chicken.string string-split)
	(only chicken.format fprintf format))

(include "common-declarations.scm")
(include "mini-srfi-1.scm")

(define-syntax d (syntax-rules () ((_ . _) (void))))

(define-alias dd d)
(define-alias dm d)
(define-alias dx d)

#+debugbuild
(define (map-se se)
  (map (lambda (a) 
	 (cons (car a) (if (symbol? (cdr a)) (cdr a) '<macro>)))
       se))

(define-inline (getp sym prop)
  (##core#inline "C_i_getprop" sym prop #f))

(define-inline (putp sym prop val)
  (##core#inline_allocate ("C_a_i_putprop" 8) sym prop val))

(define-inline (namespaced-symbol? sym)
  (##core#inline "C_u_i_namespaced_symbolp" sym))

;;; Support definitions

;;; low-level module support

(define ##sys#current-module (make-parameter #f))
(define ##sys#module-alias-environment (make-parameter '()))

(declare 
  (hide make-module module? %make-module
	module-name module-library
	module-vexports module-sexports
	set-module-vexports! set-module-sexports!
	module-export-list set-module-export-list! 
	module-defined-list set-module-defined-list!
	module-import-forms set-module-import-forms!
	module-meta-import-forms set-module-meta-import-forms!
	module-exist-list set-module-exist-list!
	module-meta-expressions set-module-meta-expressions!
	module-defined-syntax-list set-module-defined-syntax-list!
	module-saved-environments set-module-saved-environments!
	module-iexports set-module-iexports!
        module-rename-list set-module-rename-list!))

(define-record-type module
  (%make-module name library export-list defined-list exist-list defined-syntax-list
		undefined-list import-forms meta-import-forms meta-expressions 
		vexports sexports iexports saved-environments rename-list) 
  module?
  (name module-name)			; SYMBOL
  (library module-library)		; SYMBOL
  (export-list module-export-list set-module-export-list!) ; (SYMBOL | (SYMBOL ...) ...)
  (defined-list module-defined-list set-module-defined-list!) ; ((SYMBOL . VALUE) ...)    - *exported* value definitions
  (exist-list module-exist-list set-module-exist-list!)	      ; (SYMBOL ...)    - only for checking refs to undef'd
  (defined-syntax-list module-defined-syntax-list set-module-defined-syntax-list!) ; ((SYMBOL . VALUE) ...)
  (undefined-list module-undefined-list set-module-undefined-list!) ; ((SYMBOL WHERE1 ...) ...)
  (import-forms module-import-forms set-module-import-forms!)	    ; (SPEC ...)
  (meta-import-forms module-meta-import-forms set-module-meta-import-forms!)	    ; (SPEC ...)
  (meta-expressions module-meta-expressions set-module-meta-expressions!) ; (EXP ...)
  (vexports module-vexports set-module-vexports!)	      ; ((SYMBOL . SYMBOL) ...)
  (sexports module-sexports set-module-sexports!)	      ; ((SYMBOL SE TRANSFORMER) ...)
  (iexports module-iexports set-module-iexports!)	      ; ((SYMBOL . SYMBOL) ...)
  ;; for csi's ",m" command, holds (<env> . <macroenv>)
  (saved-environments module-saved-environments set-module-saved-environments!)
  (rename-list module-rename-list set-module-rename-list!))

(define ##sys#module-name module-name)

(define (##sys#module-exports m)
  (values 
   (module-export-list m)
   (module-vexports m)
   (module-sexports m)))

(define (make-module name lib explist vexports sexports iexports #!optional (renames '()))
  (%make-module name lib explist '() '() '() '() '() '() '() vexports sexports iexports #f
                renames))

(define (##sys#register-module-alias alias name)
  (##sys#module-alias-environment
    (cons (cons alias name) (##sys#module-alias-environment))))

(define (##sys#with-module-aliases bindings thunk)
  (parameterize ((##sys#module-alias-environment
		  (append
		   (map (lambda (b) (cons (car b) (cadr b))) bindings)
		   (##sys#module-alias-environment))))
    (thunk)))

(define (##sys#resolve-module-name name loc)
  (let loop ((n (library-id name)) (done '()))
    (cond ((assq n (##sys#module-alias-environment)) =>
	   (lambda (a)
	     (let ((n2 (cdr a)))
	       (if (memq n2 done)
		   (error loc "module alias refers to itself" name)
		   (loop n2 (cons n2 done))))))
	  (else n))))

(define (##sys#find-module name #!optional (err #t) loc)
  (cond ((assq name ##sys#module-table) => cdr)
	(err (error loc "module not found" name))
	(else #f)))

(define ##sys#switch-module
  (let ((saved-default-envs #f))
    (lambda (mod)
      (let ((now (cons (##sys#current-environment) (##sys#macro-environment))))
	(cond ((##sys#current-module) =>
	       (lambda (m)
		 (set-module-saved-environments! m now)))
	      (else 
	       (set! saved-default-envs now)))
	(let ((saved (if mod (module-saved-environments mod) saved-default-envs)))
	  (when saved
	    (##sys#current-environment (car saved))
	    (##sys#macro-environment (cdr saved)))
	  (##sys#current-module mod))))))

(define (##sys#add-to-export-list mod exps)
  (let ((xl (module-export-list mod)))
    (if (eq? xl #t)
	(let ((el (module-exist-list mod))
	      (me (##sys#macro-environment))
	      (sexps '()))
	  (for-each
	   (lambda (exp)
	     (cond ((assq exp me) =>
		    (lambda (a)
		      (set! sexps (cons a sexps))))))
	   exps)
	  (set-module-sexports! mod (append sexps (module-sexports mod)))
	  (set-module-exist-list! mod (append el exps)))
	(set-module-export-list! mod (append xl exps)))))

(define (##sys#add-to-export/rename-list mod renames)
  (let ((rl (module-rename-list mod)))
    (set-module-rename-list! mod (append rl renames))
    (##sys#add-to-export-list mod (map car renames))))

(define (##sys#toplevel-definition-hook sym renamed exported?) #f)

(define (##sys#register-meta-expression exp)
  (and-let* ((mod (##sys#current-module)))
    (set-module-meta-expressions! mod (cons exp (module-meta-expressions mod)))))

(define (check-for-redef sym env senv)
  (and-let* ((a (assq sym env)))
    (##sys#warn "redefinition of imported value binding" sym) )
  (and-let* ((a (assq sym senv)))
    (##sys#warn "redefinition of imported syntax binding" sym)))

(define (##sys#register-export sym mod)
  (when mod
    (let ((exp (or (eq? #t (module-export-list mod))
		   (find-export sym mod #t)))
	  (ulist (module-undefined-list mod)))
      (##sys#toplevel-definition-hook	; in compiler, hides unexported bindings
       sym (module-rename sym (module-name mod)) exp)
      (and-let* ((a (assq sym ulist)))
	(set-module-undefined-list! mod (delete a ulist eq?)))
      (check-for-redef sym (##sys#current-environment) (##sys#macro-environment))
      (set-module-exist-list! mod (cons sym (module-exist-list mod)))
      (when exp
	(dm "defined: " sym)
	(set-module-defined-list! 
	 mod
	 (cons (cons sym #f)
	       (module-defined-list mod)))))) )

(define (##sys#register-syntax-export sym mod val)
  (when mod
    (let ((exp (or (eq? #t (module-export-list mod))
		   (find-export sym mod #t)))
	  (ulist (module-undefined-list mod))
	  (mname (module-name mod)))
      (when (assq sym ulist)	    
	(##sys#warn "use of syntax precedes definition" sym)) ;XXX could report locations
      (check-for-redef sym (##sys#current-environment) (##sys#macro-environment))
      (dm "defined syntax: " sym)
      (when exp
	(set-module-defined-list! 
	 mod
	 (cons (cons sym val)
	       (module-defined-list mod))) )
      (set-module-defined-syntax-list! 
       mod
       (cons (cons sym val) (module-defined-syntax-list mod))))))

(define (##sys#unregister-syntax-export sym mod)
  (when mod
    (set-module-defined-syntax-list!
     mod
     (delete sym (module-defined-syntax-list mod) (lambda (x y) (eq? x (car y)))))))

(define (register-undefined sym mod where)
  (when mod
    (let ((ul (module-undefined-list mod)))
      (cond ((assq sym ul) =>
	     (lambda (a)
	       (when (and where (not (memq where (cdr a))))
		 (set-cdr! a (cons where (cdr a))))))
	    (else
	     (set-module-undefined-list!
	      mod
	      (cons (cons sym (if where (list where) '())) ul)))))))

(define (##sys#register-module name lib explist #!optional (vexports '()) (sexports '()))
  (let ((mod (make-module name lib explist vexports sexports '())))
    (set! ##sys#module-table (cons (cons name mod) ##sys#module-table))
    mod) )

(define (module-indirect-exports mod)
  (let ((exports (module-export-list mod))
	(mname (module-name mod))
	(dlist (module-defined-list mod)))
    (define (indirect? id)
      (let loop ((exports exports))
	(and (not (null? exports))
	     (or (and (pair? (car exports))
		      (memq id (cdar exports)))
		 (loop (cdr exports))))))
    (define (warn msg id)
      (##sys#warn
       (string-append msg " in module `" (symbol->string mname) "'")
       id))
    (if (eq? #t exports)
	'()
	(let loop ((exports exports))	; walk export list
	  (cond ((null? exports) '())
		((symbol? (car exports)) (loop (cdr exports))) ; normal export
		(else
		 (let loop2 ((iexports (cdar exports))) ; walk indirect exports for a given entry
		   (cond ((null? iexports) (loop (cdr exports)))
			 ((assq (car iexports) (##sys#macro-environment))
			  (warn "indirect export of syntax binding" (car iexports))
			  (loop2 (cdr iexports)))
			 ((assq (car iexports) dlist) => ; defined in current module?
			  (lambda (a) 
			    (cons 
			     (cons 
			      (car iexports)
			      (or (cdr a) (module-rename (car iexports) mname)))
			     (loop2 (cdr iexports)))))
			 ((assq (car iexports) (##sys#current-environment)) =>
			  (lambda (a)	; imported in current env.
			    (cond ((symbol? (cdr a)) ; not syntax
				   (cons (cons (car iexports) (cdr a)) (loop2 (cdr iexports))) )
				  (else
				   (warn "indirect reexport of syntax" (car iexports))
				   (loop2 (cdr iexports))))))
			 (else 
			  (warn "indirect export of unknown binding" (car iexports))
			  (loop2 (cdr iexports)))))))))))

(define (merge-se . ses*) ; later occurrences take precedence to earlier ones
  (let ((seen (make-hash-table)) (rses (reverse ses*)))
    (let loop ((ses (cdr rses)) (last-se #f) (se2 (car rses)))
      (cond ((null? ses) se2)
	    ((or (eq? last-se (car ses)) (null? (car ses)))
	     (loop (cdr ses) last-se se2))
	    ((not last-se)
             (for-each (lambda (e) (hash-table-set! seen (car e) #t)) se2)
	     (loop ses se2 se2))
	    (else (let lp ((se (car ses)) (se2 se2))
		    (cond ((null? se) (loop (cdr ses) (car ses) se2))
			  ((hash-table-ref seen (caar se))
			   (lp (cdr se) se2))
			  (else (hash-table-set! seen (caar se) #t)
				(lp (cdr se) (cons (car se) se2))))))))))

(define (compiled-module-dependencies mod)
  (let ((libs (filter-map ; extract library names
	       (lambda (x) (nth-value 1 (##sys#decompose-import x o eq? 'module)))
	       (module-import-forms mod))))
    (map (lambda (lib) `(##core#require ,lib))
	 (delete-duplicates libs eq?))))

(define (##sys#compiled-module-registration mod compile-mode)
  (let ((dlist (module-defined-list mod))
	(mname (module-name mod))
	(ifs (module-import-forms mod))
	(sexports (module-sexports mod))
	(mifs (module-meta-import-forms mod)))
    `((##sys#with-environment
        (lambda ()
	  ,@(if (and (eq? compile-mode 'static) (pair? ifs) (pair? sexports))
		(compiled-module-dependencies mod)
		'())
          ,@(if (and (pair? ifs) (pair? sexports))
   	        `((scheme#eval '(import-syntax ,@(strip-syntax ifs))))
  	        '())
          ,@(if (and (pair? mifs) (pair? sexports))
     	        `((import-syntax ,@(strip-syntax mifs)))
	        '())
          ,@(if (or (getp mname '##core#functor) (pair? sexports))
 	        (##sys#fast-reverse (strip-syntax (module-meta-expressions mod)))
	        '())
          (##sys#register-compiled-module
            ',(module-name mod)
            ',(module-library mod)
            (scheme#list			; iexports
	      ,@(map (lambda (ie)
                       (if (symbol? (cdr ie))
                           `'(,(car ie) . ,(cdr ie))
                           `(scheme#list ',(car ie) '() ,(cdr ie))))
                 (module-iexports mod)))
            ',(module-vexports mod)		; vexports
            (scheme#list			; sexports
	    ,@(map (lambda (sexport)
	  	     (let* ((name (car sexport))
                            (a (assq name dlist)))
                       (cond ((pair? a) 
                              `(scheme#cons ',(car sexport) ,(strip-syntax (cdr a))))
                             (else
                               (dm "re-exported syntax" name mname)
			  `',name))))
	        sexports))
            (scheme#list			; sdefs
	      ,@(if (null? sexports)
	            '() 			; no syntax exported - no more info needed
                    (let loop ((sd (module-defined-syntax-list mod)))
                      (cond ((null? sd) '())
                            ((assq (caar sd) sexports) (loop (cdr sd)))
                            (else
                              (let ((name (caar sd)))
                                (cons `(scheme#cons ',(caar sd) ,(strip-syntax (cdar sd)))
                                      (loop (cdr sd)))))))))
            (scheme#list   ; renames
              ,@(map (lambda (ren)
                       `(scheme#cons ',(car ren) ',(cdr ren)))
                  (module-rename-list mod)))))))))

;; iexports = indirect exports (syntax dependencies on value idents, explicitly included in module export list)
;; vexports = value (non-syntax) exports
;; sexports = syntax exports
;; sdefs = unexported definitions from syntax environment used by exported macros (not in export list)
(define (##sys#register-compiled-module name lib iexports vexports sexports #!optional
					(sdefs '()) (renames '()))
  (define (find-reexport name)
    (let ((a (assq name (##sys#macro-environment))))
      (if (and a (pair? (cdr a)))
	  a
	  (##sys#error
	   'import "cannot find implementation of re-exported syntax"
	   name))))
  (let* ((sexps
	  (filter-map (lambda (se)
			(and (not (symbol? se))
			     (list (car se) #f (##sys#ensure-transformer (cdr se) (car se)))))
		      sexports))
	 (reexp-sexps
	  (filter-map (lambda (se) (and (symbol? se) (find-reexport se)))
		      sexports))
	 (nexps
	  (map (lambda (ne)
		 (list (car ne) #f (##sys#ensure-transformer (cdr ne) (car ne))))
	       sdefs))
	 (mod (make-module name lib '() vexports (append sexps reexp-sexps) iexports
                           renames))
	 (senv (if (or (not (null? sexps))  ; Only macros have an senv
		       (not (null? nexps))) ; which must be patched up
		   (merge-se
		    (##sys#macro-environment)
		    (##sys#current-environment)
		    iexports vexports sexps nexps)
		   '())))
    (for-each
     (lambda (sexp)
       (set-car! (cdr sexp) (merge-se (or (cadr sexp) '()) senv)))
     sexps)
    (for-each
     (lambda (nexp)
       (set-car! (cdr nexp) (merge-se (or (cadr nexp) '()) senv)))
     nexps)
    (set-module-saved-environments!
     mod
     (cons (merge-se (##sys#current-environment) vexports sexps)
	   (##sys#macro-environment)))
    (set! ##sys#module-table (cons (cons name mod) ##sys#module-table)) 
    mod))

(define (##sys#register-core-module name lib vexports #!optional (sexports '()))
  (let* ((me (##sys#macro-environment))
	 (mod (make-module
	       name lib '()
	       vexports
	       (map (lambda (se)
		      (if (symbol? se)
			  (or (assq se me)
			      (##sys#error
			       "unknown syntax referenced while registering module" 
			       se name))
			  se))
		    sexports)
	       '())))
    (set-module-saved-environments!
     mod
     (cons (merge-se (##sys#current-environment)
		     (module-vexports mod)
		     (module-sexports mod))
	   (##sys#macro-environment)))
    (set! ##sys#module-table (cons (cons name mod) ##sys#module-table)) 
    mod))

;; same as register-core-module (above) but does not load any code,
;; used to register modules that provide only syntax
(define (##sys#register-primitive-module name vexports #!optional (sexports '()))
  (##sys#register-core-module name #f vexports sexports))

(define (find-export sym mod indirect)
  (let ((exports (module-export-list mod)))
    (let loop ((xl (if (eq? #t exports) (module-exist-list mod) exports)))
      (cond ((null? xl) #f)
	    ((eq? sym (car xl)))
	    ((pair? (car xl))
	     (or (eq? sym (caar xl))
		 (and indirect (memq sym (cdar xl)))
		 (loop (cdr xl))))
	    (else (loop (cdr xl)))))))

(define ##sys#finalize-module 
  (let ((display display)
	(write-char write-char))
    (lambda (mod #!optional (invalid-export (lambda _ #f)))
      ;; invalid-export: Returns a string if given identifier names a
      ;; non-exportable object. The string names the type (e.g. "an
      ;; inline function"). Returns #f otherwise.

      ;; Given a list of (<identifier> . <source-location>), builds a nicely
      ;; formatted error message with suggestions where possible.
      (define (report-unresolved-identifiers unknowns)
	(let ((out (open-output-string)))
	  (fprintf out "Module `~a' has unresolved identifiers" (module-name mod))

	  ;; Print filename from a line number entry
	  (let lp ((locs (apply append (map cdr unknowns))))
	    (unless (null? locs)
	      (or (and-let* ((loc (car locs))
			     (ln (and (pair? loc) (cdr loc)))
			     (ss (string-split ln ":"))
			     ((= 2 (length ss))))
		    (fprintf out "\n  In file `~a':" (car ss))
		    #t)
		  (lp (cdr locs)))))

	  (for-each
	   (lambda (id.locs)
	     (fprintf out "\n\n  Unknown identifier `~a'" (car id.locs))

	     ;; Print all source locations where this ID occurs
	     (for-each
	      (lambda (loc)
		(define (ln->num ln) (let ((ss (string-split ln ":")))
				       (if (and (pair? ss) (= 2 (length ss)))
					   (cadr ss)
					   ln)))
		(and-let* ((loc-s
			    (cond
			      ((and (pair? loc) (car loc) (cdr loc)) =>
			       (lambda (ln)
				 (format "In procedure `~a' on line ~a" (car loc) (ln->num ln))))
			      ((and (pair? loc) (cdr loc))
			       (format "On line ~a" (ln->num (cdr loc))))
			      (else (format "In procedure `~a'" loc)))))
		  (fprintf out "\n    ~a" loc-s)))
	      (reverse (cdr id.locs)))

	     ;; Print suggestions from identifier db
	     (and-let* ((id (car id.locs))
			(a (getp id '##core#db)))
	       (fprintf out "\n  Suggestion: try importing ")
	       (cond
		 ((= 1 (length a))
		  (fprintf out "module `~a'" (cadar a)))
		 (else
		  (fprintf out "one of these modules:")
		  (for-each
		   (lambda (a)
		     (fprintf out "\n    ~a" (cadr a)))
		   a)))))
	   unknowns)

	  (##sys#error (get-output-string out))))

      (define (filter-sdlist mod)
        (let loop ((syms (module-defined-syntax-list mod)))
          (cond ((null? syms) '())
                ((eq? (##sys#get (caar syms) '##sys#override) 'value)
                 (loop (cdr syms)))
                (else (cons (assq (caar syms) (##sys#macro-environment))
                            (loop (cdr syms)))))))

      (let* ((explist (module-export-list mod))
	     (name (module-name mod))
	     (dlist (module-defined-list mod))
	     (elist (module-exist-list mod))
	     (missing #f)
	     (sdlist (filter-sdlist mod))
	     (sexports
	      (if (eq? #t explist)
		  (merge-se (module-sexports mod) sdlist)
		  (let loop ((me (##sys#macro-environment)))
		    (cond ((null? me) '())
                          ((eq? (##sys#get (caar me) '##sys#override) 'value)
                           (loop (cdr me)))
			  ((find-export (caar me) mod #f)
			   (cons (car me) (loop (cdr me))))
			  (else (loop (cdr me)))))))
	     (vexports
	      (let loop ((xl (if (eq? #t explist) elist explist)))
		(if (null? xl)
		    '()
		    (let* ((h (car xl))
			   (id (if (symbol? h) h (car h))))
		      (cond ((eq? (##sys#get id '##sys#override) 'syntax)
                              (loop (cdr xl)))
                            ((assq id sexports) (loop (cdr xl)))
                            (else 
                              (cons 
                                (cons 
			          id
                                  (let ((def (assq id dlist)))
                                    (if (and def (symbol? (cdr def))) 
                                        (cdr def)
                                        (let ((a (assq id (##sys#current-environment))))
					  (define (fail msg)
					    (##sys#warn msg)
					    (set! missing #t))
					  (define (id-string)
					    (string-append "`" (symbol->string id) "'"))
                                          (cond ((and a (symbol? (cdr a)))
                                                 (dm "reexporting: " id " -> " (cdr a))
                                                 (cdr a))
						(def (module-rename id name))
						((invalid-export id)
						 =>
						 (lambda (type)
						   (fail (string-append
							  "Cannot export " (id-string)
							  " because it is " type "."))))
                                                ((not def)
						 (fail (string-append
							"Exported identifier " (id-string)
							" has not been defined.")))
                                                (else (bomb "fail")))))))
                              (loop (cdr xl))))))))))

	;; Check all identifiers were resolved
	(let ((unknowns '()))
	  (for-each (lambda (u)
		      (unless (memq (car u) elist)
			(set! unknowns (cons u unknowns))))
		    (module-undefined-list mod))
	  (unless (null? unknowns)
	    (report-unresolved-identifiers unknowns)))

	(when missing
	  (##sys#error "module unresolved" name))
	(let* ((iexports 
		(map (lambda (exp)
		       (cond ((symbol? (cdr exp)) exp)
			     ((assq (car exp) (##sys#macro-environment)))
			     (else (##sys#error "(internal) indirect export not found" (car exp)))) )
		     (module-indirect-exports mod)))
	       (new-se (merge-se 
			(##sys#macro-environment) 
			(##sys#current-environment) 
			iexports vexports sexports sdlist)))
	  (for-each
	   (lambda (m)
	     (let ((se (merge-se (cadr m) new-se))) ;XXX needed?
	       (dm `(FIXUP: ,(car m) ,@(map-se se)))
	       (set-car! (cdr m) se)))
	   sdlist)
	  (dm `(EXPORTS: 
		,(module-name mod) 
		(DLIST: ,@dlist)
		(SDLIST: ,@(map-se sdlist))
		(IEXPORTS: ,@(map-se iexports))
		(VEXPORTS: ,@(map-se vexports))
		(SEXPORTS: ,@(map-se sexports))))
	  (set-module-vexports! mod vexports)
	  (set-module-sexports! mod sexports)
	  (set-module-iexports! 
	   mod
	   (merge-se (module-iexports mod) iexports)) ; "reexport" may already have added some
	  (set-module-saved-environments!
	   mod
	   (cons (merge-se (##sys#current-environment) vexports sexports)
		 (##sys#macro-environment))))))))

(define ##sys#module-table '())


;;; Import-expansion

(define (##sys#with-environment thunk)
  (parameterize ((##sys#current-module #f)
                 (##sys#current-environment '())
                 (##sys#current-meta-environment
                   (##sys#current-meta-environment))
                 (##sys#macro-environment
		   (##sys#meta-macro-environment)))
    (thunk)))

(define (##sys#import-library-hook mname)
  (and-let* ((il (chicken.load#find-dynamic-extension
		  (string-append (symbol->string mname) ".import")
		  #t)))
     (##sys#with-environment
       (lambda ()
         (fluid-let ((##sys#notices-enabled #f)) ; to avoid re-import warnings
           (load il)
           (##sys#find-module mname 'import))))))

(define (find-module/import-library lib loc)
  (let ((mname (##sys#resolve-module-name lib loc)))
    (or (##sys#find-module mname #f loc)
	(##sys#import-library-hook mname))))

(define (##sys#decompose-import x r c loc)
  (let ((%only (r 'only))
	(%rename (r 'rename))
	(%except (r 'except))
	(%prefix (r 'prefix)))
    (define (warn msg mod id)
      (##sys#warn (string-append msg " in module `" (symbol->string mod) "'") id))
    (define (tostr x)
      (cond ((string? x) x)
	    ((keyword? x) (##sys#string-append (##sys#symbol->string x) ":")) ; hack
	    ((symbol? x) (##sys#symbol->string x))
	    ((number? x) (number->string x))
	    (else (##sys#syntax-error-hook loc "invalid prefix" ))))
    (define (export-rename mod lst)
      (let ((ren (module-rename-list mod)))
        (if (null? ren)
            lst
            (map (lambda (a)
                   (cond ((assq (car a) ren) =>
                          (lambda (b) 
                            (cons (cdr b) (cdr a))))
                         (else a)))
              lst))))
    (call-with-current-continuation
     (lambda (k)
       (define (module-imports name)
	 (let* ((id  (library-id name))
	        (mod (find-module/import-library id loc)))
	   (if (not mod)
	       (k id id #f #f #f #f)
	       (values (module-name mod)
		       (module-library mod)
		       (module-name mod)
		       (export-rename mod (module-vexports mod))
		       (export-rename mod (module-sexports mod))
		       (module-iexports mod)))))
       (let outer ((x x))
	 (cond ((symbol? x)
		(module-imports (strip-syntax x)))
	       ((not (pair? x))
		(##sys#syntax-error-hook loc "invalid import specification" x))
	       (else
		(let ((head (car x)))
		  (cond ((c %only head)
			 (##sys#check-syntax loc x '(_ _ . #(symbol 0)))
			 (let-values (((name lib spec impv imps impi) (outer (cadr x)))
				      ((imports) (strip-syntax (cddr x))))
			   (let loop ((ids imports) (v '()) (s '()) (missing '()))
			     (cond ((null? ids)
				    (for-each
				     (lambda (id)
				       (warn "imported identifier doesn't exist" name id))
				     missing)
				    (values name lib `(,head ,spec ,@imports) v s impi))
				   ((assq (car ids) impv) =>
				    (lambda (a)
				      (loop (cdr ids) (cons a v) s missing)))
				   ((assq (car ids) imps) =>
				    (lambda (a)
				      (loop (cdr ids) v (cons a s) missing)))
				   (else
				    (loop (cdr ids) v s (cons (car ids) missing)))))))
			((c %except head)
			 (##sys#check-syntax loc x '(_ _ . #(symbol 0)))
			 (let-values (((name lib spec impv imps impi) (outer (cadr x)))
				      ((imports) (strip-syntax (cddr x))))
			   (let loopv ((impv impv) (v '()) (ids imports))
			     (cond ((null? impv)
				    (let loops ((imps imps) (s '()) (ids ids))
				      (cond ((null? imps)
					     (for-each
					      (lambda (id)
						(warn "excluded identifier doesn't exist" name id))
					      ids)
					     (values name lib `(,head ,spec ,@imports) v s impi))
					    ((memq (caar imps) ids) =>
								    (lambda (id)
								      (loops (cdr imps) s (delete (car id) ids eq?))))
					    (else
					     (loops (cdr imps) (cons (car imps) s) ids)))))
				   ((memq (caar impv) ids) =>
							   (lambda (id)
							     (loopv (cdr impv) v (delete (car id) ids eq?))))
				   (else
				    (loopv (cdr impv) (cons (car impv) v) ids))))))
			((c %rename head)
			 (##sys#check-syntax loc x '(_ _ . #((symbol symbol) 0)))
			 (let-values (((name lib spec impv imps impi) (outer (cadr x)))
				      ((renames) (strip-syntax (cddr x))))
			   (let loopv ((impv impv) (v '()) (ids renames))
			     (cond ((null? impv)
				    (let loops ((imps imps) (s '()) (ids ids))
				      (cond ((null? imps)
					     (for-each
					      (lambda (id)
						(warn "renamed identifier doesn't exist" name id))
					      (map car ids))
					     (values name lib `(,head ,spec ,@renames) v s impi))
					    ((assq (caar imps) ids) =>
					     (lambda (a)
					       (loops (cdr imps)
						     (cons (cons (cadr a) (cdar imps)) s)
						     (delete a ids eq?))))
					    (else
					     (loops (cdr imps) (cons (car imps) s) ids)))))
				   ((assq (caar impv) ids) =>
				    (lambda (a)
				      (loopv (cdr impv)
					     (cons (cons (cadr a) (cdar impv)) v)
					     (delete a ids eq?))))
				   (else
				    (loopv (cdr impv) (cons (car impv) v) ids))))))
			((c %prefix head)
			 (##sys#check-syntax loc x '(_ _ _))
			 (let-values (((name lib spec impv imps impi) (outer (cadr x)))
				      ((prefix) (strip-syntax (caddr x))))
			   (define (rename imp)
			     (cons
			      (##sys#string->symbol
			       (##sys#string-append (tostr prefix) (##sys#symbol->string (car imp))))
			      (cdr imp)))
			   (values name lib `(,head ,spec ,prefix) (map rename impv) (map rename imps) impi)))
			(else
			 (module-imports (strip-syntax x))))))))))))

(define (##sys#expand-import x r c import-env macro-env meta? reexp? loc)
  (##sys#check-syntax loc x '(_ . #(_ 1)))
  (for-each
   (lambda (x)
     (let-values (((name _ spec v s i) (##sys#decompose-import x r c loc)))
       (if (not spec)
	   (##sys#syntax-error-hook loc "cannot import from undefined module" name x)
	   (##sys#import spec v s i import-env macro-env meta? reexp? loc))))
   (cdr x))
  '(##core#undefined))

(define (##sys#import spec vsv vss vsi import-env macro-env meta? reexp? loc)
  (let ((cm (##sys#current-module)))
    (when cm ; save import form
      (if meta?
          (set-module-meta-import-forms!
           cm
           (append (module-meta-import-forms cm) (list spec)))
          (set-module-import-forms!
           cm
           (append (module-import-forms cm) (list spec)))))
    (dd `(IMPORT: ,loc))
    (dd `(V: ,(if cm (module-name cm) '<toplevel>) ,(map-se vsv)))
    (dd `(S: ,(if cm (module-name cm) '<toplevel>) ,(map-se vss)))
    (for-each
     (lambda (imp)
       (let ((id (car imp)))
         (##sys#put! id '##sys#override #f)
         (and-let* ((a (assq id (import-env)))
                    (aid (cdr imp))
                    ((not (eq? aid (cdr a)))))
              (##sys#notice "re-importing already imported identifier" id))))
     vsv)
    (for-each
     (lambda (imp)
       (let ((id (car imp)))
         (##sys#put! id '##sys#override #f)
         (and-let* ((a (assq (car imp) (macro-env)))
                    ((not (eq? (cdr imp) (cdr a)))))
              (##sys#notice "re-importing already imported syntax" (car imp)))))
     vss)
    (when reexp?
      (unless cm
        (##sys#syntax-error-hook loc "`reexport' only valid inside a module"))
      (let ((el (module-export-list cm)))
        (cond ((eq? #t el)
               (set-module-sexports! cm (append vss (module-sexports cm)))
               (set-module-exist-list!
                cm
                (append (module-exist-list cm)
                        (map car vsv)
                        (map car vss))))
              (else
               (set-module-export-list!
                cm
                (append
                 (let ((xl (module-export-list cm)))
                   (if (eq? #t xl) '() xl))
                 (map car vsv)
                 (map car vss))))))
      (set-module-iexports!
       cm
       (merge-se (module-iexports cm) vsi))
      (dm "export-list: " (module-export-list cm)))
    (import-env (merge-se (import-env) vsv))
    (macro-env (merge-se (macro-env) vss))))

(define (module-rename sym prefix)
  (##sys#string->symbol
   (string-append
    (##sys#slot prefix 1)
    "#"
    (##sys#slot sym 1) ) ) )

(define (##sys#alias-global-hook sym assign where)
  (define (mrename sym)
    (cond ((##sys#current-module) => 
	   (lambda (mod)
	     (dm "(ALIAS) global alias " sym " in " (module-name mod))
	     (unless assign 
	       (register-undefined sym mod where))
	     (module-rename sym (module-name mod))))
	  (else sym)))
  (cond ((namespaced-symbol? sym) sym)
	((assq sym (##sys#current-environment)) =>
	 (lambda (a)
	   (let ((sym2 (cdr a)))
	     (dm "(ALIAS) in current environment " sym " -> " sym2)
	     ;; check for macro (XXX can this be?)
	     (if (pair? sym2) (mrename sym) sym2))))
	(else (mrename sym))))

(define (##sys#validate-exports exps loc)
  ;; expects "exps" to be stripped
  (define (err . args)
    (apply ##sys#syntax-error-hook loc args))
  (define (iface name)
    (or (getp name '##core#interface)
	(err "unknown interface" name exps)))
  (cond ((eq? '* exps) exps)
	((symbol? exps) (iface exps))
	((not (list? exps))
	 (err "invalid exports" exps))
	(else
	 (let loop ((xps exps))
	   (cond ((null? xps) '())
		 ((not (pair? xps))
		  (err "invalid exports" exps))
		 (else
		  (let ((x (car xps)))
		    (cond ((symbol? x) (cons x (loop (cdr xps))))
			  ((not (list? x))
			   (err "invalid export" x exps))
			  ((eq? #:syntax (car x))
			   (cons (cdr x) (loop (cdr xps)))) ; currently not used
			  ((eq? #:interface (car x))
			   (if (and (pair? (cdr x)) (symbol? (cadr x)))
			       (append (iface (cadr x)) (loop (cdr xps)))
			       (err "invalid interface specification" x exps)))
			  (else
			   (let loop2 ((lst x))
			     (cond ((null? lst) (cons x (loop (cdr xps))))
				   ((symbol? (car lst)) (loop2 (cdr lst)))
				   (else (err "invalid export" x exps)))))))))))))

(define (##sys#register-functor name fargs fexps body)
  (putp name '##core#functor (cons fargs (cons fexps body))))

(define (##sys#instantiate-functor name fname args)
  (let ((funcdef (getp fname '##core#functor)))
    (define (err . args)
      (apply ##sys#syntax-error-hook name args))
    (unless funcdef (err "instantation of undefined functor" fname))
    (let ((fargs (car funcdef))
	  (exports (cadr funcdef))
	  (body (cddr funcdef)))
      (define (merr)
	(err "argument list mismatch in functor instantiation" 
	     (cons name args) (cons fname (map car fargs))))
      `(##core#let-module-alias
	,(let loop ((as args) (fas fargs))
	   (cond ((null? as)
		  ;; use default arguments (if available) or bail out
		  (let loop2 ((fas fas))
		    (if (null? fas)
			'()
			(let ((p (car fas)))
			  (if (pair? (car p)) ; has default argument?
			      (let ((exps (cdr p))
				    (alias (caar p))
				    (mname (library-id (cadar p))))
				(match-functor-argument alias name mname exps fname)
				(cons (list alias mname) (loop2 (cdr fas))))
			      ;; no default argument, we have too few argument modules
			      (merr))))))
		 ;; more arguments given as defined for the functor
		 ((null? fas) (merr))
		 (else
		  ;; otherwise match provided argument to functor argument
		  (let* ((p (car fas))
			 (p1 (car p))
			 (exps (cdr p))
			 (def? (pair? p1))
			 (alias (if def? (car p1) p1))
			 (mname (library-id (car as))))
		    (match-functor-argument alias name mname exps fname)
		    (cons (list alias mname)
			  (loop (cdr as) (cdr fas)))))))
	(##core#module
	 ,name
	 ,(if (eq? '* exports) #t exports)
	 ,@body)))))

(define (match-functor-argument alias name mname exps fname)
  (let ((mod (##sys#find-module (##sys#resolve-module-name mname 'module) #t 'module)))
    (unless (eq? exps '*)
      (let ((missing '()))
	(for-each
	 (lambda (exp)
	   (let ((sym (if (symbol? exp) exp (car exp))))
	     (unless (or (assq sym (module-vexports mod))
			 (assq sym (module-sexports mod)))
	       (set! missing (cons sym missing)))))
	 exps)
	(when (pair? missing)
	  (##sys#syntax-error-hook
	   'module 
	   (apply
	    string-append 
	    "argument module `" (symbol->string mname) "' does not match required signature\n"
	    "in instantiation `" (symbol->string name) "' of functor `"
	    (symbol->string fname) "', because the following required exports are missing:\n"
	    (map (lambda (s) (string-append "\n  " (symbol->string s))) missing))))))))


;;; built-in modules (needed for eval environments)

(let ((r4rs-values
       '((not . scheme#not) (boolean? . scheme#boolean?)
	 (eq? . scheme#eq?) (eqv? . scheme#eqv?) (equal? . scheme#equal?)
	 (pair? . scheme#pair?) (cons . scheme#cons)
	 (car . scheme#car) (cdr . scheme#cdr)
	 (caar . scheme#caar) (cadr . scheme#cadr) (cdar . scheme#cdar)
	 (cddr . scheme#cddr)
	 (caaar . scheme#caaar) (caadr . scheme#caadr)
	 (cadar . scheme#cadar) (caddr . scheme#caddr)
	 (cdaar . scheme#cdaar) (cdadr . scheme#cdadr)
	 (cddar . scheme#cddar) (cdddr . scheme#cdddr)
	 (caaaar . scheme#caaaar) (caaadr . scheme#caaadr)
	 (caadar . scheme#caadar) (caaddr . scheme#caaddr)
	 (cadaar . scheme#cadaar) (cadadr . scheme#cadadr)
	 (caddar . scheme#caddar) (cadddr . scheme#cadddr)
	 (cdaaar . scheme#cdaaar) (cdaadr . scheme#cdaadr)
	 (cdadar . scheme#cdadar) (cdaddr . scheme#cdaddr)
	 (cddaar . scheme#cddaar) (cddadr . scheme#cddadr)
	 (cdddar . scheme#cdddar) (cddddr . scheme#cddddr)
	 (set-car! . scheme#set-car!) (set-cdr! . scheme#set-cdr!)
	 (null? . scheme#null?) (list? . scheme#list?)
	 (list . scheme#list) (length . scheme#length)
	 (list-tail . scheme#list-tail) (list-ref . scheme#list-ref)
	 (append . scheme#append) (reverse . scheme#reverse)
	 (memq . scheme#memq) (memv . scheme#memv)
	 (member . scheme#member) (assq . scheme#assq)
	 (assv . scheme#assv) (assoc . scheme#assoc)
	 (symbol? . scheme#symbol?)
	 (symbol->string . scheme#symbol->string)
	 (string->symbol . scheme#string->symbol)
	 (number? . scheme#number?) (integer? . scheme#integer?)
	 (exact? . scheme#exact?) (real? . scheme#real?)
	 (complex? . scheme#complex?) (inexact? . scheme#inexact?)
	 (rational? . scheme#rational?) (zero? . scheme#zero?)
	 (odd? . scheme#odd?) (even? . scheme#even?)
	 (positive? . scheme#positive?) (negative? . scheme#negative?)
	 (max . scheme#max) (min . scheme#min)
	 (+ . scheme#+) (- . scheme#-) (* . scheme#*) (/ . scheme#/)
	 (= . scheme#=) (> . scheme#>) (< . scheme#<)
	 (>= . scheme#>=) (<= . scheme#<=)
	 (quotient . scheme#quotient) (remainder . scheme#remainder)
	 (modulo . scheme#modulo)
	 (gcd . scheme#gcd) (lcm . scheme#lcm) (abs . scheme#abs)
	 (floor . scheme#floor) (ceiling . scheme#ceiling)
	 (truncate . scheme#truncate) (round . scheme#round)
	 (rationalize . scheme#rationalize)
	 (exact->inexact . scheme#exact->inexact)
	 (inexact->exact . scheme#inexact->exact)
	 (exp . scheme#exp) (log . scheme#log) (expt . scheme#expt)
	 (sqrt . scheme#sqrt)
	 (sin . scheme#sin) (cos . scheme#cos) (tan . scheme#tan)
	 (asin . scheme#asin) (acos . scheme#acos) (atan . scheme#atan)
	 (number->string . scheme#number->string)
	 (string->number . scheme#string->number)
	 (char? . scheme#char?) (char=? . scheme#char=?)
	 (char>? . scheme#char>?) (char<? . scheme#char<?)
	 (char>=? . scheme#char>=?) (char<=? . scheme#char<=?)
	 (char-ci=? . scheme#char-ci=?)
	 (char-ci<? . scheme#char-ci<?) (char-ci>? . scheme#char-ci>?)
	 (char-ci>=? . scheme#char-ci>=?) (char-ci<=? . scheme#char-ci<=?)
	 (char-alphabetic? . scheme#char-alphabetic?)
	 (char-whitespace? . scheme#char-whitespace?)
	 (char-numeric? . scheme#char-numeric?)
	 (char-upper-case? . scheme#char-upper-case?)
	 (char-lower-case? . scheme#char-lower-case?)
	 (char-upcase . scheme#char-upcase)
	 (char-downcase . scheme#char-downcase)
	 (char->integer . scheme#char->integer)
	 (integer->char . scheme#integer->char)
	 (string? . scheme#string?) (string=? . scheme#string=?)
	 (string>? . scheme#string>?) (string<? . scheme#string<?)
	 (string>=? . scheme#string>=?) (string<=? . scheme#string<=?)
	 (string-ci=? . scheme#string-ci=?)
	 (string-ci<? . scheme#string-ci<?)
	 (string-ci>? . scheme#string-ci>?)
	 (string-ci>=? . scheme#string-ci>=?)
	 (string-ci<=? . scheme#string-ci<=?)
	 (make-string . scheme#make-string)
	 (string-length . scheme#string-length)
	 (string-ref . scheme#string-ref)
	 (string-set! . scheme#string-set!)
	 (string-append . scheme#string-append)
	 (string-copy . scheme#string-copy)
	 (string->list . scheme#string->list)
	 (list->string . scheme#list->string)
	 (substring . scheme#substring)
	 (string-fill! . scheme#string-fill!)
	 (vector? . scheme#vector?) (make-vector . scheme#make-vector)
	 (vector-ref . scheme#vector-ref)
	 (vector-set! . scheme#vector-set!)
	 (string . scheme#string) (vector . scheme#vector)
	 (vector-length . scheme#vector-length)
	 (vector->list . scheme#vector->list)
	 (list->vector . scheme#list->vector)
	 (vector-fill! . scheme#vector-fill!)
	 (procedure? . scheme#procedure?)
	 (map . scheme#map) (for-each . scheme#for-each)
	 (apply . scheme#apply) (force . scheme#force)
	 (call-with-current-continuation . scheme#call-with-current-continuation)
	 (input-port? . scheme#input-port?)
	 (output-port? . scheme#output-port?)
	 (current-input-port . scheme#current-input-port)
	 (current-output-port . scheme#current-output-port)
	 (call-with-input-file . scheme#call-with-input-file)
	 (call-with-output-file . scheme#call-with-output-file)
	 (open-input-file . scheme#open-input-file)
	 (open-output-file . scheme#open-output-file)
	 (close-input-port . scheme#close-input-port)
	 (close-output-port . scheme#close-output-port)
	 (load . scheme#load) (read . scheme#read)
	 (read-char . scheme#read-char) (peek-char . scheme#peek-char)
	 (write . scheme#write) (display . scheme#display)
	 (write-char . scheme#write-char) (newline . scheme#newline)
	 (eof-object? . scheme#eof-object?)
	 (with-input-from-file . scheme#with-input-from-file)
	 (with-output-to-file . scheme#with-output-to-file)
	 (char-ready? . scheme#char-ready?)
	 (imag-part . scheme#imag-part) (real-part . scheme#real-part)
	 (make-rectangular . scheme#make-rectangular)
	 (make-polar . scheme#make-polar)
	 (angle . scheme#angle) (magnitude . scheme#magnitude)
	 (numerator . scheme#numerator)
	 (denominator . scheme#denominator)
	 (scheme-report-environment . scheme#scheme-report-environment)
	 (null-environment . scheme#null-environment)
	 (interaction-environment . scheme#interaction-environment)))
      (r4rs-syntax ##sys#scheme-macro-environment))
  (##sys#register-core-module 'r4rs 'library r4rs-values r4rs-syntax)
  (##sys#register-core-module
   'scheme 'library
   (append '((dynamic-wind . scheme#dynamic-wind)
	     (eval . scheme#eval)
	     (values . scheme#values)
	     (call-with-values . scheme#call-with-values))
	   r4rs-values)
   r4rs-syntax)
  (##sys#register-core-module 'r4rs-null #f '() r4rs-syntax)
  (##sys#register-core-module 'r5rs-null #f '() r4rs-syntax))

(##sys#register-module-alias 'r5rs 'scheme)

(define-inline (se-subset names env) (map (cut assq <> env) names))

;; Hack for library.scm to use macros from modules it defines itself.
(##sys#register-primitive-module
 'chicken.internal.syntax '() (##sys#macro-environment))

(##sys#register-primitive-module
 'chicken.module '() ##sys#chicken.module-macro-environment)

(##sys#register-primitive-module
 'chicken.type '() ##sys#chicken.type-macro-environment)

(##sys#register-primitive-module
 'srfi-0 '() (se-subset '(cond-expand) ##sys#default-macro-environment))

(##sys#register-primitive-module
 'srfi-2 '() (se-subset '(and-let*) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-6 'library
 '((get-output-string . chicken.base#get-output-string)
   (open-input-string . chicken.base#open-input-string)
   (open-output-string . chicken.base#open-output-string)))

(##sys#register-primitive-module
 'srfi-8 '() (se-subset '(receive) ##sys#chicken.base-macro-environment))

(##sys#register-primitive-module
 'srfi-9 '() (se-subset '(define-record-type) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-10 'read-syntax '((define-reader-ctor . chicken.read-syntax#define-reader-ctor)))

(##sys#register-primitive-module
 'srfi-11 '() (se-subset '(let-values let*-values) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-12 'library
 '((abort . chicken.condition#abort)
   (condition? . chicken.condition#condition?)
   (condition-predicate . chicken.condition#condition-predicate)
   (condition-property-accessor . chicken.condition#condition-property-accessor)
   (current-exception-handler . chicken.condition#current-exception-handler)
   (make-composite-condition . chicken.condition#make-composite-condition)
   (make-property-condition . chicken.condition#make-property-condition)
   (signal . chicken.condition#signal)
   (with-exception-handler . chicken.condition#with-exception-handler))
 (se-subset '(handle-exceptions) ##sys#chicken.condition-macro-environment))

(##sys#register-primitive-module
 'srfi-15 '() (se-subset '(fluid-let) ##sys#chicken.base-macro-environment))

(##sys#register-primitive-module
 'srfi-16 '() (se-subset '(case-lambda) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-17 'library
 '((getter-with-setter . chicken.base#getter-with-setter)
   (setter . chicken.base#setter))
 (se-subset '(set!) ##sys#default-macro-environment))

(##sys#register-core-module
 'srfi-23 'library '((error . chicken.base#error)))

(##sys#register-primitive-module
 'srfi-26 '() (se-subset '(cut cute) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-28 'extras '((format . chicken.format#format)))

(##sys#register-primitive-module
 'srfi-31 '() (se-subset '(rec) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-39 'library '((make-parameter . chicken.base#make-parameter))
 (se-subset '(parameterize) ##sys#chicken.base-macro-environment))

(##sys#register-primitive-module
 'srfi-55 '() (se-subset '(require-extension) ##sys#chicken.base-macro-environment))

(##sys#register-core-module
 'srfi-88 'library
 '((keyword? . chicken.keyword#keyword?)
   (keyword->string . chicken.keyword#keyword->string)
   (string->keyword . chicken.keyword#string->keyword)))

(##sys#register-core-module
 'srfi-98 'posix
 '((get-environment-variable . chicken.process-context#get-environment-variable)
   (get-environment-variables . chicken.process-context#get-environment-variables)))

(define (chicken.module#module-environment mname #!optional (ename mname))
  (let ((mod (find-module/import-library mname 'module-environment)))
    (if (not mod)
	(##sys#syntax-error-hook
	 'module-environment "undefined module" mname)
	(##sys#make-structure
	 'environment ename (car (module-saved-environments mod)) #t))))

;; Ensure default modules are available in "eval", too
;; TODO: Figure out a better way to make this work for static programs.
;; The actual imports are handled lazily by eval when first called.
(include "chicken.base.import.scm")
(include "chicken.syntax.import.scm")
