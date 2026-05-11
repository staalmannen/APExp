;;;; batch-driver.scm - Driver procedure for the compiler
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
  (unit batch-driver)
  (uses extras data-structures pathname expand
	support compiler-syntax compiler optimizer internal
	;; TODO: Backend should be configurable
	scrutinizer lfa2 c-platform c-backend user-pass))

(module chicken.compiler.batch-driver
    (compile-source-file)

(import scheme
	chicken.base
	chicken.fixnum
	chicken.format
	chicken.gc
	chicken.internal
	chicken.load
	chicken.pathname
	chicken.platform
	chicken.pretty-print
	chicken.process-context
	chicken.string
	chicken.syntax
        chicken.port
	chicken.time
        chicken.condition
	chicken.compiler.support
	chicken.compiler.compiler-syntax
	chicken.compiler.core
	chicken.compiler.optimizer
	chicken.compiler.scrutinizer
	chicken.compiler.lfa2
	chicken.compiler.c-platform
	chicken.compiler.c-backend
	chicken.compiler.user-pass)

(include "tweaks")
(include "mini-srfi-1.scm")

(define-constant funny-message-timeout 60000)

;;; Emit collected information from various statistics about the program

(define (print-program-statistics db)
  (receive
   (size osize kvars kprocs globs sites entries) (compute-database-statistics db)
   (when (debugging 's "program statistics:")
     (printf ";   program size: \t~s \toriginal program size: \t~s\n" size osize)
     (printf ";   variables with known values: \t~s\n" kvars)
     (printf ";   known procedures: \t~s\n" kprocs)
     (printf ";   global variables: \t~s\n" globs)
     (printf ";   known call sites: \t~s\n" sites) 
     (printf ";   database entries: \t~s\n" entries) ) ) )

;;; Initialize analysis database:
;;
;; - Simply marks the symbols directly in the plist.
;; - Does nothing after the first invocation, but we leave it this way to
;;    have the option to add default entries for each new db.

(define initialize-analysis-database
  (let ((initial #t))
    (lambda ()
      (when initial
	(for-each
	 (lambda (s)
	   (mark-variable s '##compiler#intrinsic 'standard))
	 standard-bindings)
	(for-each
	 (lambda (s)
	   (mark-variable s '##compiler#intrinsic 'extended))
	 extended-bindings)
	(for-each
	 (lambda (s)
	   (mark-variable s '##compiler#intrinsic 'internal))
	 internal-bindings))
      (set! initial #f))))

;;; Display analysis database:

(define display-analysis-database
  (let ((names '((captured . cpt) (assigned . set) (boxed . box) (global . glo)
		 (assigned-locally . stl)
		 (contractable . con) (standard-binding . stb) (simple . sim)
		 (inlinable . inl)
		 (collapsable . col) (removable . rem) (constant . con)
		 (inline-target . ilt) (inline-transient . itr)
		 (undefined . und) (replacing . rpg) (unused . uud) (extended-binding . xtb)
		 (inline-export . ilx) (hidden-refs . hrf)
		 (value-ref . vvf)
		 (customizable . cst) (has-unused-parameters . hup) (boxed-rest . bxr) ) ) 
	(omit #f))
    (lambda (db)
      (unless omit
	(set! omit 
	  (append default-standard-bindings
		  default-extended-bindings
		  internal-bindings) ) )
      (hash-table-for-each
       (lambda (sym plist)
	 (let ((val #f)
	       (lval #f)
	       (pvals #f)
	       (csites '())
	       (refs '())
	       (derived-rvars '()))
	   (unless (memq sym omit)
	     (write sym)
	     (let loop ((es plist))
	       (if (pair? es)
		   (begin
		     (case (caar es)
		       ((captured assigned boxed global contractable standard-binding assigned-locally
				  collapsable removable undefined replacing unused simple inlinable inline-export
				  has-unused-parameters extended-binding customizable constant boxed-rest hidden-refs)
			(printf "\t~a" (cdr (assq (caar es) names))) )
		       ((unknown)
			(set! val 'unknown) )
		       ((value)
			(unless (eq? val 'unknown) (set! val (cdar es))) )
		       ((local-value)
			(unless (eq? val 'unknown) (set! lval (cdar es))) )
		       ((potential-values)
			(set! pvals (cdar es)))
		       ((replacable home contains contained-in use-expr closure-size rest-parameter
				    captured-variables explicit-rest rest-cdr rest-null? consed-rest-arg)
			(printf "\t~a=~s" (caar es) (cdar es)) )
		       ((derived-rest-vars)
			(set! derived-rvars (cdar es)))
		       ((references)
			(set! refs (cdar es)) )
		       ((call-sites)
			(set! csites (cdar es)) )
		       (else (bomb "Illegal property" (car es))) )
		     (loop (cdr es)) ) ) )
	     (when (pair? refs) (printf "\trefs=~s" (length refs)))
	     (when (pair? derived-rvars) (printf "\tdrvars=~s" (length derived-rvars)))
	     (when (pair? csites) (printf "\tcss=~s" (length csites)))
	     (cond [(and val (not (eq? val 'unknown)))
		    (printf "\tval=~s" (cons (node-class val) (node-parameters val))) ]
		   [(and lval (not (eq? val 'unknown)))
		    (printf "\tlval=~s" (cons (node-class lval) (node-parameters lval)))])
	     (when (pair? pvals)
	       (for-each
		(lambda (pval)
		  (printf "\tpval=~s" (cons (node-class pval) (node-parameters pval))))
		pvals))
	     (newline) ) ) )
       db) ) ) )

;;; Compile a complete source file:

(define (compile-source-file filename user-supplied-options . options)
  (define (option-arg p)
    (if (null? (cdr p))
	(quit-compiling "missing argument to `-~A' option" (car p))
	(let ([arg (cadr p)])
	  (if (symbol? arg)
	      (quit-compiling "invalid argument to `~A' option" arg)
	      arg) ) ) )
  (initialize-compiler)
  (set! explicit-use-flag (memq 'explicit-use options))
  (set! emit-debug-info (memq 'debug-info options))
  (when (memq 'module-registration options)
    (set! compile-module-registration 'yes))
  (when (memq 'no-module-registration options)
    (set! compile-module-registration 'no))
  (when (memq 'static options)
    (set! static-extensions #t)
    (register-feature! 'chicken-compile-static))
  (let* ((dynamic (memq 'dynamic options))
	(unit (memq 'unit options))
	(init-forms `((##core#declare
		      ,@(append 
			 default-declarations
			 (if emit-debug-info
			     '((uses debugger-client))
			     '())
			 (if explicit-use-flag
			     '()
			     `((uses ,@default-units)))
			 (if (and static-extensions
				  (not dynamic)
				  (not unit)
				  (not explicit-use-flag)
				  (or (not compile-module-registration)
				      (eq? compile-module-registration 'yes)))
			     '((uses eval-modules))
			     '())))))
	(import-forms `((import-for-syntax ,@default-syntax-imports)
			,@(if explicit-use-flag
			      '()
			      `((import-syntax ,@default-imports)))))
	(cleanup-forms '(((chicken.base#implicit-exit-handler))))
	(outfile (cond ((memq 'output-file options)
			=> (lambda (node)
			     (let ((oname (option-arg node)))
			       (if (symbol? oname)
				   (symbol->string oname)
				   oname) ) ) )
		       ((memq 'to-stdout options) #f)
		       (else (make-pathname #f (if filename (pathname-file filename) "out") "c")) ) )
	(opasses (default-optimization-passes))
	(time0 #f)
	(time-breakdown #f)
	(forms '())
	(inline-output-file #f)
	(profile (or (memq 'profile options)
		     (memq 'accumulate-profile options)
		     (memq 'profile-name options)))
	(profile-name
	 (and-let* ((pn (memq 'profile-name options))) (cadr pn)))
	(hsize (memq 'heap-size options))
	(kwstyle (memq 'keyword-style options))
	(loop/dispatch (memq 'clustering options))
	(a-only (memq 'analyze-only options))
	(do-scrutinize #t)
	(do-lfa2 (memq 'lfa2 options))
	(dumpnodes #f)
	(start-time #f)
	(upap #f)
	(ssize (or (memq 'nursery options) (memq 'stack-size options)))
	(module-name
	 (and-let* ((m (memq 'module options)))
	   (option-arg m))))

    (define (cputime) (current-process-milliseconds))

    (define (dribble fstr . args)
      (debugging 'p (apply sprintf fstr args)))

    (define (print-header mode dbgmode)
      (debugging 'p "pass" mode)
      (and (memq dbgmode debugging-chicken)
	   (begin
	     (printf "[~a]~%" mode)
	     #t) ) )

    (define (print-node mode dbgmode n)
      (when (print-header mode dbgmode)
	(if dumpnodes
	    (dump-nodes n)
	    (pretty-print (build-expression-tree n)) ) ) )

    (define (print-db mode dbgmode db pass)
      (when (print-header mode dbgmode)
	(printf "(iteration ~s)~%" pass)
	(display-analysis-database db) ) )

    (define (print-expr mode dbgmode xs)
      (when (print-header mode dbgmode)
	(for-each 
	 (lambda (x) 
	   (pretty-print x)
	   (newline))
	 xs) ) )

    (define (string-trim str)
      (let loop ((front 0)
		 (back (string-length str)))
	(cond ((= front back) "")
	      ((char-whitespace? (string-ref str front))
	       (loop (add1 front) back))
	      ((char-whitespace? (string-ref str (sub1 back)))
	       (loop front (sub1 back)))
	      (else (substring str front back)))))
       
    (define (string->extension-name str)
      (let ((str (string-trim str)))
        (if (and (positive? (string-length str))
                 (char=? #\( (string-ref str 0)))
            (handle-exceptions ex 
              (##sys#error "invalid import specification" str)
              (with-input-from-string str read))
            (string->symbol str))))

    (define (arg-val str)
      (let* ((len (string-length str))
	     (len1 (- len 1)) )
	(or (if (< len 2)
		(string->number str)
		(case (string-ref str len1)
		  ((#\m #\M) (* (string->number (substring str 0 len1)) (* 1024 1024)))
		  ((#\k #\K) (* (string->number (substring str 0 len1)) 1024))
		  (else (string->number str)) ) )
	    (quit-compiling "invalid numeric argument ~S" str) ) ) )

    (define (collect-options opt)
      (let loop ([opts options])
	(cond [(memq opt opts) => (lambda (p) (cons (option-arg p) (loop (cddr p))))]
	      [else '()] ) ) )

    (define (begin-time)
      (when time-breakdown (set! time0 (cputime))) )

    (define (end-time pass)
      (when time-breakdown
	(printf "milliseconds needed for ~a: \t~s~%" 
	  pass
	  (inexact->exact (round (- (cputime) time0)) ) )))

    (define (analyze pass node . args)
      (let-optionals args ((no 0) (contf #t))
        (let ((db (analyze-expression node)))
	  (when upap
	    (upap pass db node
		  (cut db-get db <> <>)
		  (cut db-put! db <> <> <>)
		  no contf) )
	  db) ) )

    (define (chop-separator str)
      (let ((len (sub1 (string-length str))))
        (if (and (> len 0)
                 (memq (string-ref str len) '(#\\ #\/)))
            (substring str 0 len)
            str) ) )

    (when unit
      (set! unit-name (string->symbol (option-arg unit))))
    (when (or unit-name dynamic)
      (set! standalone-executable #f))
    (when (memq 'ignore-repository options)
      (set! ##sys#dload-disabled #t)
      (repository-path #f))
    (set! enable-specialization (memq 'specialize options))
    (set! debugging-chicken
      (append-map
       (lambda (do)
	 (map (lambda (c) (string->symbol (string c)))
	      (string->list do) ) )
       (collect-options 'debug) ) )
    (when (memq 'h debugging-chicken)
      (print-debug-options)
      (exit))
    (set! dumpnodes (memq '|D| debugging-chicken))
    (set! import-libraries
      (map (lambda (il)
	     (cons (string->symbol il) 
		   (string-append il ".import.scm")))
	   (collect-options 'emit-import-library)))
    (when (and (memq 'emit-all-import-libraries options)
	       (not a-only))
      (set! all-import-libraries #t))
    (when enable-specialization
      (set! do-scrutinize #t))
    (when (memq 't debugging-chicken) (##sys#start-timer))
    (when (memq 'b debugging-chicken) (set! time-breakdown #t))
    (when (memq 'raw options)
      (set! explicit-use-flag #t)
      (set! init-forms '())
      (set! import-forms '())
      (set! cleanup-forms '()))
    (when (memq 'no-lambda-info options)
      (set! emit-closure-info #f) )
    (when (memq 'no-compiler-syntax options)
      (set! compiler-syntax-enabled #f))
    (when (memq 'local options)
      (set! local-definitions #t))
    (when (memq 'inline-global options)
      (set! enable-inline-files #t)
      (set! inline-locally #t))
    (when (memq 'verbose options)
      (set! verbose-mode #t)
      (set! ##sys#notices-enabled #t))
    (when (memq 'strict-types options)
      (set! strict-variable-types #t)
      (set! enable-specialization #t))
    (when (memq 'no-warnings options) 
      (dribble "Warnings are disabled")
      (set! ##sys#warnings-enabled #f) 
      (set! do-scrutinize #f))		; saves some processing time
    (when (memq 'optimize-leaf-routines options) (set! optimize-leaf-routines #t))
    (when (memq 'unsafe options) 
      (set! unsafe #t) )
    (when (memq 'setup-mode options)
      (set! ##sys#setup-mode #t))
    (when (memq 'regenerate-import-libraries options)
      (set! preserve-unchanged-import-libraries #f))
    (when (memq 'disable-interrupts options) (set! insert-timer-checks #f))
    (when (memq 'fixnum-arithmetic options) (set! number-type 'fixnum))
    (when (memq 'block options) (set! block-compilation #t))
    (when (memq 'emit-external-prototypes-first options)
      (set! external-protos-first #t))
    (when (memq 'inline options) (set! inline-locally #t))
    (and-let* ((elf (memq 'emit-link-file options)))
      (set! emit-link-file (option-arg elf)))
    (and-let* ((ifile (memq 'emit-inline-file options)))
      (set! inline-locally #t)		; otherwise this option makes no sense
      (set! local-definitions #t)
      (set! inline-output-file (option-arg ifile)))
    (and-let* ((tfile (memq 'emit-types-file options)))
      (set! types-output-file (option-arg tfile)))
    (and-let* ([inlimit (memq 'inline-limit options)])
      (set! inline-max-size 
	(let ([arg (option-arg inlimit)])
	  (or (string->number arg)
	      (quit-compiling
	       "invalid argument to `-inline-limit' option: `~A'" arg) ) ) ) )
    (and-let* ((ulimit (memq 'unroll-limit options)))
      (set! unroll-limit
	(let ((arg (option-arg ulimit)))
	  (or (string->number arg)
	      (quit-compiling
	       "invalid argument to `-unroll-limit' option: `~A'" arg) ) ) ) )
    (when (memq 'case-insensitive options) 
      (dribble "Identifiers and symbols are case insensitive")
      (register-feature! 'case-insensitive)
      (case-sensitive #f) )
    (when kwstyle
      (let ([val (option-arg kwstyle)])
	(cond [(string=? "prefix" val) (keyword-style #:prefix)]
	      [(string=? "none" val) (keyword-style #:none)]
	      [(string=? "suffix" val) (keyword-style #:suffix)]
	      [else (quit-compiling
		     "invalid argument to `-keyword-style' option")] ) ) )
    (when (memq 'no-parentheses-synonyms options)
      (dribble "Disabled support for parentheses synonyms")
      (parentheses-synonyms #f) )
    (when (memq 'no-symbol-escape options) 
      (dribble "Disabled support for escaped symbols")
      (symbol-escape #f) )
    (when (memq 'r5rs-syntax options)
      (dribble "Disabled the CHICKEN extensions to R5RS syntax")
      (case-sensitive #f)
      (keyword-style #:none)
      (parentheses-synonyms #f)
      (symbol-escape #f) )
    (set! ##sys#read-error-with-line-number #t)
    (set! ##sys#include-pathnames
      (append (map chop-separator (collect-options 'include-path))
	      ##sys#include-pathnames) )
    (when (and outfile filename (string=? outfile filename))
      (quit-compiling "source- and output-filename are the same") )
    (when (memq 'keep-shadowed-macros options)
      (set! undefine-shadowed-macros #f) )
    (when (memq 'no-argc-checks options)
      (set! no-argc-checks #t) )
    (when (memq 'no-bound-checks options)
      (set! no-bound-checks #t) )
    (when (memq 'no-procedure-checks options)
      (set! no-procedure-checks #t) )
    (when (memq 'no-procedure-checks-for-toplevel-bindings options)
      (set! no-global-procedure-checks #t) )
    (when (memq 'no-procedure-checks-for-usual-bindings options)
      (for-each 
       (lambda (v)
         (mark-variable v '##compiler#always-bound-to-procedure)
         (mark-variable v '##compiler#always-bound) )
       default-standard-bindings)
      (for-each 
       (lambda (v)
         (mark-variable v '##compiler#always-bound-to-procedure)
         (mark-variable v '##compiler#always-bound) )
       default-extended-bindings) )
    (when (memq 'p debugging-chicken) (load-verbose #t))

    ;; Handle feature options:
    (for-each 
     register-feature!
     (append-map (cut string-split <> ", ") (collect-options 'feature)))
    (for-each 
     unregister-feature!
     (append-map (cut string-split <> ",") (collect-options 'no-feature)))

    ;; Load extensions:
    (set! ##sys#features (cons #:compiler-extension ##sys#features))
    (let ([extends (collect-options 'extend)])
      (dribble "Loading compiler extensions...")
      (for-each
       (lambda (e)
	 (let ((f (##sys#resolve-include-filename e #f #t #f)))
	   (when (not f) (quit-compiling "cannot load extension: ~a" e))
	   (load f)))
       extends) )
    (set! ##sys#features (delete #:compiler-extension ##sys#features eq?))
    (set! ##sys#features (cons '#:compiling ##sys#features))
    (set! upap (user-post-analysis-pass))

    ;; Handle units added with the "-uses" flag.
    (let ((uses (append-map
		 (lambda (u) (map string->symbol (string-split u ", ")))
		 (collect-options 'uses))))
      (unless (null? uses)
	(set! init-forms
	  (append init-forms `((##core#declare (uses . ,uses)))))))

    ;; Mark linked libraries so they will be compiled as unit dependencies.
    (let ((link (append-map
		 (lambda (l) (map string->symbol (string-split l ", ")))
		 (collect-options 'link))))
      (set! linked-libraries (lset-union/eq? linked-libraries link)))

    ;; Append required extensions to imports:
    (set! import-forms
      (append
       import-forms
       (map (lambda (r) `(import ,(string->extension-name r)))
	    (collect-options 'require-extension))))

    (when (memq 'compile-syntax options)
      (set! ##sys#enable-runtime-macros #t) )
    (set! target-heap-size
      (and hsize
	   (arg-val (option-arg hsize))))
    (set! target-stack-size
      (and ssize
	   (arg-val (option-arg ssize))))
    (set! emit-trace-info (not (memq 'no-trace options)))
    (set! disable-stack-overflow-checking (memq 'disable-stack-overflow-checks options))
    (set! bootstrap-mode (feature? #:chicken-bootstrap))
    (when (memq 'm debugging-chicken) (set-gc-report! #t))
    (cond ((memq 'no-usual-integrations options)
	   (set! do-scrutinize #f))
	  (else
	   (set! standard-bindings default-standard-bindings)
	   (set! extended-bindings default-extended-bindings) ))
    (dribble "debugging info: ~A"
	     (if emit-trace-info
		 "calltrace"
		 "none") )
    (when profile
      (let ((acc (eq? 'accumulate-profile (car profile))))
	(when (and acc (not profile-name))
	  (quit-compiling
	   "you need to specify -profile-name if using accumulated profiling runs"))
	(set! emit-profile #t)
	(set! profiled-procedures 'all)
	(set! init-forms
	  (append
	   init-forms
	   default-profiling-declarations
	   (if acc
	       '((set! ##sys#profile-append-mode #t))
	       '() ) ) )
	(dribble "generating ~aprofiled code" (if acc "accumulative " "")) ))

    ;;XXX hardcoded "modules.db" is bad (also used in chicken-install.scm)
    (load-identifier-database "modules.db")

    (cond ((memq 'version options)
	   (print-version #t)
	   (newline) )
	  ((or (memq 'help options) (memq '-help options) (memq 'h options) (memq '-h options))
	   (print-usage))
	  ((memq 'release options)
	   (display (chicken-version)) 
	   (newline) )
	  ((not filename)
	   (print-version #t)
	   (display "\nEnter `chicken -help' for information on how to use the compiler,\n")
	   (display "or try `csc' for a more convenient interface.\n")
	   (display "\nRun `csi' to start the interactive interpreter.\n"))
	  (else

	   ;; Display header:
	   (dribble "compiling `~a' ..." filename)
	   (debugging 'r "options" options)
	   (debugging 'r "debugging options" debugging-chicken)
	   (debugging 'r "target heap size" target-heap-size)
	   (debugging 'r "target stack size" target-stack-size)
	   (set! start-time (cputime))

	   ;; Read toplevel expressions:
	   (set! ##sys#line-number-database (make-vector line-number-database-size '()))
	   (let ([prelude (collect-options 'prelude)]
		 [postlude (collect-options 'postlude)] 
		 [files (append 
			 (collect-options 'prologue)
			 (list filename)
			 (collect-options 'epilogue) ) ]  )

	     (let ([proc (user-read-pass)])
	       (cond [proc
		      (dribble "User read pass...")
		      (set! forms (proc prelude files postlude)) ]
		     [else
		      (do ([files files (cdr files)])
			  ((null? files)
			   (set! forms
			     (append (map string->expr prelude)
				     (reverse forms)
				     (map string->expr postlude) ) ) )
			(let* ((f (car files))
			       (in (check-and-open-input-file f)) )
			  (fluid-let ((##sys#current-source-filename f))
			    (let loop ()
			      (let ((x (chicken.syntax#read-with-source-info in))) ; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing

				(cond ((eof-object? x) 
				       (close-checked-input-file in f) )
				      (else
				       (set! forms (cons x forms))
				       (loop)))))))) ] ) ) )

	   ;; Start compilation passes:
	   (let ([proc (user-preprocessor-pass)])
	     (when proc
	       (dribble "User preprocessing pass...")
	       (set! forms (map proc forms))))

	   (print-expr "source" '|1| forms)
	   (begin-time)
	   ;; Canonicalize s-expressions
	   (let* ((init0 (map canonicalize-expression init-forms))
		  (exps0 (map (lambda (x)
				(fluid-let ((##sys#current-source-filename filename))
				  (canonicalize-expression x)))
			      (let ((forms (append import-forms forms)))
				(if (not module-name)
				    forms
				    `((##core#module
				       ,(string->symbol module-name) ()
				       ,@forms))))))
		  (uses0 (map (lambda (u)
				(canonicalize-expression `(##core#require ,u)))
			      (##sys#fast-reverse used-libraries)))
		  (exps (append
			 (map (lambda (ic) `(set! ,(cdr ic) ',(car ic))) immutable-constants)
			 init0
			 uses0
			 (if unit-name `((##core#provide ,unit-name)) '())
			 (if emit-profile
			     (profiling-prelude-exps (and (not unit-name)
							  (or profile-name #t)))
			     '() )
			 exps0
			 (if standalone-executable
			     cleanup-forms
			     '((##core#undefined))))))

	     (unless (null? import-libraries)
	       (quit-compiling
		"No module definition found for import libraries to emit: ~A"
		;; ~S would be confusing: separate with a comma
		(string-intersperse
		 (map (lambda (il) (->string (car il)))
		      import-libraries) ", ")))

	     (when (pair? compiler-syntax-statistics)
	       (with-debugging-output
		'S
		(lambda ()
		  (print "applied compiler syntax:")
		  (for-each 
		   (lambda (cs) (printf "  ~a\t\t~a~%" (car cs) (cdr cs)))
		   compiler-syntax-statistics))))
   	     (when (debugging '|N| "real name table:")
	       (display-real-name-table) )
	     (when (debugging 'n "line number database:")
	       (##sys#display-line-number-database) )

	     (set! ##sys#line-number-database line-number-database-2)
	     (set! line-number-database-2 #f)

	     (end-time "canonicalization")
	     (print-expr "canonicalized" '|2| exps)

	     (when (memq 'check-syntax options) (exit))

	     ;; User-defined pass (s-expressions)
	     (let ([proc (user-pass)])
	       (when proc
		 (dribble "User pass...")
		 (begin-time)
		 (set! exps (map proc exps))
		 (end-time "user pass") ) )

	     ;; Convert s-expressions to node tree
	     (let ((node0 (build-toplevel-procedure
			   (build-node-graph
			    (canonicalize-begin-body exps))))
		   (db #f))
	       (print-node "initial node tree" '|T| node0)
	       (initialize-analysis-database)

	       ;; collect requirements and load inline files
	       (let ((extensions required-extensions))
		 (when enable-inline-files
		   (for-each
		    (lambda (id)
		      (and-let* ((ifile (##sys#resolve-include-filename
					 (symbol->string id) '(".inline") #t #f)))
			(dribble "Loading inline file ~a ..." ifile)
			(load-inline-file ifile)))
		    extensions))
		 (let ((ifs (collect-options 'consult-inline-file)))
		   (unless (null? ifs)
		     (set! inline-locally #t)
		     (for-each 
		      (lambda (ilf)
			(dribble "Loading inline file ~a ..." ilf)
			(load-inline-file ilf) )
		      ifs)))
		 ;; Perform scrutiny and optionally specialization
		 (when (or do-scrutinize enable-specialization)
		   ;;XXX hardcoded database file name
		   (unless (memq 'ignore-repository options)
		     (unless (load-type-database "types.db"
						 enable-specialization)
		       (quit-compiling
			"default type-database `types.db' not found")))
		   (for-each 
		    (lambda (fn)
		      (or (load-type-database fn enable-specialization #f)
			  (quit-compiling "type-database `~a' not found" fn)))
		    (collect-options 'consult-types-file))
		   (for-each
		    (lambda (id)
		      (load-type-database
		       (make-pathname #f (symbol->string id) "types")
		       enable-specialization))
		    extensions)
		   (begin-time)
		   (set! first-analysis #f)
		   (set! db (analyze 'scrutiny node0))
		   (print-db "analysis" '|0| db 0)
		   (end-time "pre-analysis (scrutiny)")
		   (begin-time)
		   (debugging 'p "performing scrutiny")
		   (scrutinize node0 db
			       do-scrutinize enable-specialization
			       strict-variable-types block-compilation)
		   (end-time "scrutiny")
		   (when enable-specialization
		     (print-node "specialization" '|P| node0))
		   (set! first-analysis #t) ) )

	       ;; TODO: Move this so that we don't need to export these
	       (set! ##sys#line-number-database #f)
	       (set! constant-table #f)
	       (set! inline-table #f)
	       ;; Analyze toplevel assignments
	       (unless unsafe
		 (scan-toplevel-assignments (first (node-subexpressions node0))) )

	       (begin-time)
	       ;; Convert to CPS
	       (let ([node1 (perform-cps-conversion node0)])
		 (end-time "cps conversion")
		 (print-node "cps" '|3| node1)

		 ;; Optimization loop:
		 (let loop ((i 1)
			    (node2 node1)
			    (progress #t)
			    (l/d #f)
			    (l/d-done #f))
		   (begin-time)
		   ;; Analyze node tree for optimization
		   (let ([db (analyze 'opt node2 i progress)])
		     (when first-analysis
		       (when (memq 'u debugging-chicken)
			 (dump-undefined-globals db))
		       (when (memq 'd debugging-chicken)
			 (dump-defined-globals db))
		       (when (memq 'v debugging-chicken)
			 (dump-global-refs db))
		       ;; do this here, because we must make sure we have a db
		       (and-let* ((tfile (or (and (eq? types-output-file #t)
						  (pathname-replace-extension filename "types"))
					     (and (string? types-output-file)
						  types-output-file))))
			 (dribble "generating type file `~a' ..." tfile)
			 (emit-types-file filename tfile db block-compilation)))
		     (set! first-analysis #f)
		     (end-time "analysis")
		     (print-db "analysis" '|4| db i)

		     (when (memq 's debugging-chicken) 
		       (print-program-statistics db))

		     ;; Optimize (once)
		     (cond (progress
			    (debugging 'p "optimization pass" i)
			    (begin-time)
			    (receive (node2 progress-flag)
				(if l/d
				    (determine-loop-and-dispatch node2 db)
				    (perform-high-level-optimizations
				     node2 db block-compilation
				     inline-locally inline-max-size
                                     unroll-limit
				     inline-substitutions-enabled))
			      (end-time "optimization")
			      (print-node "optimized-iteration" '|5| node2)
			      (cond (progress-flag
				     (loop (add1 i) node2 #t #f l/d))
				    ((and (not l/d-done) loop/dispatch)
				     (debugging 'p "clustering enabled")
				     (loop (add1 i) node2 #t #t #t))
				    ((not inline-substitutions-enabled)
				     (debugging 'p "rewritings enabled")
				     (set! inline-substitutions-enabled #t)
				     (loop (add1 i) node2 #t #f l/d-done) )
				    (optimize-leaf-routines
				     (begin-time)
				     (let ([db (analyze 'leaf node2)])
				       (end-time "analysis")
				       (begin-time)
				       (let ((progress
					      (transform-direct-lambdas! node2 db)))
					 (end-time "leaf routine optimization")
					 (loop (add1 i) 
					       node2
					       progress
					       #f
					       l/d-done) ) ) )
				    (else
				     (loop (add1 i) node2 #f #f l/d-done)) ) ) )
			   
			   (else
			    ;; Secondary flow-analysis
			    (when do-lfa2
			      (begin-time)
			      (debugging 'p "doing lfa2")
                              (let ((floatvars (perform-secondary-flow-analysis node2 db)))
  			        (end-time "secondary flow analysis")
                                (unless (null? floatvars)
                                  (begin-time)
                                  (debugging 'p "doing unboxing")
                                  (set! node2 (perform-unboxing node2 floatvars)))
    			          (end-time "unboxing")))
			    (print-node "optimized" '|7| node2)
			    ;; inlining into a file with interrupts enabled would
			    ;; change semantics
			    (when (and inline-output-file insert-timer-checks)
			      (let ((f inline-output-file))
				(dribble "generating global inline file `~a' ..." f)
				(emit-global-inline-file
				 filename f db block-compilation
				 inline-max-size
				 (map foreign-stub-id foreign-lambda-stubs)) ) )
			    (begin-time)
			    ;; Closure conversion
			    (set! node2 (perform-closure-conversion node2 db))
			    (end-time "closure conversion")
			    (print-db "final-analysis" '|8| db i)
			    (when (and ##sys#warnings-enabled
				       (> (- (cputime) start-time) funny-message-timeout))
			      (display "(don't worry - still compiling...)\n") )
			    (print-node "closure-converted" '|9| node2)
			    (when a-only (exit 0))
			    (begin-time)
			    ;; Preparation
			    (receive (node literals lliterals lambda-table dbg-info)
				(prepare-for-code-generation node2 db)
			      (end-time "preparation")
			      (begin-time)

                              ;; generate link file
			      (when emit-link-file
				(let ((exts required-extensions))
				  (dribble "generating link file `~a' ..." emit-link-file)
				  (with-output-to-file emit-link-file (cut pp exts))))

                               ;; Code generation
			      (let ((out (if outfile (open-output-file outfile) (current-output-port))) )
				(dribble "generating `~A' ..." outfile)
				(generate-code literals lliterals lambda-table out filename
					       user-supplied-options dynamic db dbg-info)
				(when outfile
				  (close-output-port out)))
			      (end-time "code generation")
			      (when (memq 't debugging-chicken)
				(##sys#display-times (##sys#stop-timer)))
			      (compiler-cleanup-hook)
			      (dribble "compilation finished.") ) ) ) ) ) ) ) ) ) ) ) )
)
