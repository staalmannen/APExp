;;;; core.scm - The CHICKEN Scheme compiler (core module)
;
;
; "This is insane. What we clearly want to do is not exactly clear, and is rooted in NCOMPLR."
;
;
;--------------------------------------------------------------------------------------------
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
;
;
; Supported syntax:
;
; - Declaration specifiers:
;
; ([not] extended-bindings {<name>})
; ([not] inline {<var>})
; ([not] safe)
; ([not] standard-bindings {<name>})
; ([not] usual-integrations {<name>})
; (local {<name> ...})
; ([not] inline-global {<name>})
; ([number-type] <type>)
; (always-bound {<name>})
; (block)
; (block-global {<name>})
; (bound-to-procedure {<var>})
; (compile-syntax)
; (disable-interrupts)
; (emit-import-library {<module> | (<module> <filename>)})
; (emit-types-file [<filename>])
; (export {<name>})
; (fixnum-arithmetic)
; (foreign-declare {<string>})
; (hide {<name>})
; (inline-limit <limit>)
; (unroll-limit <limit>)
; (keep-shadowed-macros)
; (no-argc-checks)
; (no-bound-checks)
; (no-procedure-checks)
; (no-procedure-checks-for-usual-bindings)
; (no-procedure-checks-for-toplevel-bindings)
; (profile <symbol> ...)
; (safe-globals)
; (separate)
; (type (<symbol> <typespec>) ...)
; (unit <unitname>)
; (unsafe)
; (unused <symbol> ...)
; (uses {<unitname>})
; (strict-types)
; (specialize)
; (enforce-argument-types [<symbol> ...])
;
;   <type> = fixnum | generic

; - Global symbol properties:
;
;   ##compiler#always-bound -> BOOL
;   ##compiler#always-bound-to-procedure -> BOOL
;   ##compiler#local -> BOOL
;   ##compiler#visibility -> #f | 'hidden | 'exported
;   ##compiler#constant -> BOOL                             defined as constant
;   ##compiler#intrinsic -> #f | 'standard | 'extended
;   ##compiler#inline -> 'no | 'yes
;   ##compiler#inline-global -> 'yes | 'no | <node>
;   ##compiler#profile -> BOOL
;   ##compiler#unused -> BOOL
;   ##compiler#foldable -> BOOL
;   ##compiler#pure -> BOOL                                 referentially transparent
;   ##compiler#clean -> BOOL                                does not modify local state
;   ##compiler#type -> TYPE
;   ##compiler#type-source -> 'db | 'local | 'inference

; - Source language:
;
; <variable>
; <constant>
; (##core#declare {<spec>})
; (##core#local-specialization <variable> <alias> {<spec>})
; (##core#immutable <exp>)
; (##core#quote <exp>)
; (##core#syntax <exp>)
; (##core#if <exp> <exp> [<exp>])
; (##core#let <variable> ({(<variable> <exp>)}) <body>)
; (##core#let ({(<variable> <exp>)}) <body>)
; (##core#letrec ({(<variable> <exp>)}) <body>)
; (##core#letrec* ({(<variable> <exp>)}) <body>)
; (##core#let-location <symbol> <type> [<init>] <exp>)
; (##core#lambda <variable> <body>)
; (##core#lambda ({<variable>}+ [. <variable>]) <body>)
; (##core#set! <variable> <exp>)
; (##core#ensure-toplevel-definition <variable>)
; (##core#begin <exp> ...)
; (##core#include <string> <string> | #f [<body>])
; (##core#loop-lambda <llist> <body>)
; (##core#undefined)
; (##core#primitive <name>)
; (##core#provide <id>)
; (##core#inline {<op>} <exp>)
; (##core#inline_allocate (<op> <words>) {<exp>})
; (##core#inline_ref (<name> <type>))
; (##core#inline_update (<name> <type>) <exp>)
; (##core#inline_loc_ref (<type>) <exp>)
; (##core#inline_loc_update (<type>) <exp> <exp>)
; (##core#compiletimetoo <exp>)
; (##core#compiletimeonly <exp>)
; (##core#elaborationtimetoo <exp>)
; (##core#elaborationtimeonly <exp>)
; (##core#define-foreign-variable <symbol> <type> [<string>])
; (##core#define-foreign-type <symbol> <type> [<proc1> [<proc2>]])
; (##core#foreign-lambda <type> <string> {<type>})
; (##core#foreign-lambda* <type> ({(<type> <var>)})) {<string>})
; (##core#foreign-safe-lambda <type> <string> {<type>})
; (##core#foreign-safe-lambda* <type> ({(<type> <var>)})) {<string>})
; (##core#foreign-primitive <type> ({(<type> <var>)}) {<string>})
; (##core#define-inline <name> <exp>)
; (##core#define-constant <name> <exp*>)
; (##core#foreign-callback-wrapper '<name> <qualifiers> '<type> '({<type>}) <exp>)
; (##core#define-external-variable <name> <type> <bool> [<symbol>])
; (##core#check <exp>)
; (##core#require-for-syntax <id>)
; (##core#require <id> [<id>])
; (##core#app <exp> {<exp>})
; (##core#define-syntax <symbol> <expr>)
; (##core#define-compiler-syntax <symbol> <expr>)
; (##core#let-compiler-syntax ((<symbol> <expr>) ...) <expr> ...)
; (##core#module <symbol> #t | (<name> | (<name> ...) ...) <body>)
; (##core#let-module-alias ((<alias> <name>) ...) <body>)
; (##core#the <type> <strict?> <exp>)
; (##core#typecase <info> <exp> (<type> <body>) ... [(else <body>)])
; (##core#debug-event {<event> <loc>})
; (##core#with-forbidden-refs (<var> ...) <loc> <expr>)
; (<exp> {<exp>})

; - Core language:
;
; [##core#variable {<variable>}]
; [##core#float-variable {<index>}]
; [if {} <exp> <exp> <exp>)]
; [quote {<const>}]
; [##core#float {<const>}]
; [let {<variable>} <exp-v> <exp>]
; [##core#lambda {<id> <mode> (<variable>... [. <variable>]) <size>} <exp>]
; [set! {<variable> [always-immediate?]} <exp>]
; [##core#undefined {}]
; [##core#primitive {<name>}]
; [##core#let_float {<index>} <exp> <exp>]
; [##core#box_float {} <exp>]
; [##core#unbox_float {} <exp>]
; [##core#inline {<op>} <exp>...]
; [##core#inline_allocate {<op> <words>} <exp>...]
; [##core#inline_ref {<name> <type>}]
; [##core#inline_update {<name> <type>} <exp>]
; [##core#inline_loc_ref {<type>} <exp>]
; [##core#inline_loc_update {<type>} <exp> <exp>]
; [##core#debug-event {<event> <loc> <ln>}]
; [##core#call {<safe-flag> [<debug-info>]} <exp-f> <exp>...]
; [##core#callunit {<unitname>} <exp>...]
; [##core#switch {<count>} <exp> <const1> <body1> ... <defaultbody>]
; [##core#rest-car {restvar depth [<debug-info>]}]
; [##core#rest-cdr {restvar depth [<debug-info>]}]
; [##core#rest-null? {restvar depth [<debug-info>]}]
; [##core#rest-length {restvar depth [<debug-info>]}]
; [##core#cond <exp> <exp> <exp>]
; [##core#provide <id>]
; [##core#recurse {<tail-flag>} <exp1> ...]
; [##core#return <exp>]
; [##core#direct_call {<safe-flag> <debug-info> <call-id> <words>} <exp-f> <exp>...]
; [##core#direct_lambda {<id> <mode> (<variable>... [. <variable>]) <size>} <exp>]
; [##core#the {<type> <strict>} <exp>]
; [##core#the/result {<typelist>} <exp>]
; [##core#typecase {<info> (<type> ...)} <exp> <body1> ... [<elsebody>]]

; - Closure converted/prepared language:
;
; [if {} <exp> <exp> <exp>]
; [quote {<exp>}]
; [##core#float {<const>}]
; [##core#bind {<count>} <exp-v>... <exp>]
; [##core#float-variable {<index>}]
; [##core#undefined {}]
; [##core#let_float {<index>} <exp> <exp>]
; [##core#box_float {} <exp>]
; [##core#unbox_float {} <exp>]
; [##core#inline {<op>} <exp>...]
; [##core#inline_allocate {<op <words>} <exp>...]
; [##core#inline_ref {<name> <type>}]
; [##core#inline_update {<name> <type>} <exp>]
; [##core#inline_loc_ref {<type>} <exp>]
; [##core#inline_loc_update {<type>} <exp> <exp>]
; [##core#debug-event {<index> <event> <loc> <ln>}]
; [##core#closure {<count>} <exp>...]
; [##core#box {} <exp>]
; [##core#unbox {} <exp>]
; [##core#ref {<index>} <exp>]
; [##core#update {<index>} <exp> <exp>]
; [##core#updatebox {} <exp> <exp>]
; [##core#update_i {<index>} <exp> <exp>]
; [##core#updatebox_i {} <exp> <exp>]
; [##core#call {<dbg-info-index> <safe-flag> [<debug-info> [<call-id> <customizable-flag>]]} <exp-f> <exp>...]
; [##core#callunit {<unitname>} <exp>...]
; [##core#cond <exp> <exp> <exp>]
; [##core#local {<index>}]
; [##core#setlocal {<index>} <exp>]
; [##core#global {<literal> <safe-flag> <block-mode> [<name>]}]
; [##core#setglobal {<literal> <block-mode> <name>} <exp>]
; [##core#setglobal_i {<literal> <block-mode> <name>} <exp>]
; [##core#literal {<literal>}]
; [##core#immediate {<type> [<immediate>]}]     - type: bool/fix/nil/char/bwp
; [##core#proc {<name> [<non-internal>]}]
; [##core#provide <literal>]
; [##core#recurse {<tail-flag> <call-id>} <exp1> ...]
; [##core#return <exp>]
; [##core#direct_call {<dbg-info-index> <safe-flag> <debug-info> <call-id> <words>} <exp-f> <exp>...]

; Analysis database entries:
;
; <variable>:
;
;   captured -> <boolean>                    If true: variable is used outside it's home-scope
;   global -> <boolean>                      If true: variable does not occur in any lambda-list
;   call-sites -> ((<lambda-id> <node>) ...) Known call-nodes of a named procedure
;   home -> <lambda-id>                      Procedure which introduces this variable
;   unknown -> <boolean>                     If true: variable cannot have a known value
;   assigned -> <boolean>                    If true: variable is assigned somewhere
;   assigned-locally -> <boolean>            If true: variable has been assigned inside user lambda
;   undefined -> <boolean>                   If true: variable is unknown yet but can be known later
;   value -> <node>                          Variable has a known value
;   local-value -> <node>                    Variable is declared local and has value
;   potential-values -> (<node> ...)         Global variable was assigned this value (used for lambda-info)
;   references -> (<node> ...)               Nodes that are accesses of this variable (##core#variable nodes)
;   boxed -> <boolean>                       If true: variable has to be boxed after closure-conversion
;   contractable -> <boolean>                If true: variable names contractable procedure
;   inlinable -> <boolean>                   If true: variable names potentially inlinable procedure
;   collapsable -> <boolean>                 If true: variable refers to collapsable constant
;   removable -> <boolean>                   If true: variable is not used
;   replacable -> <variable>                 Variable can be replaced by another variable
;   replacing -> <boolean>                   If true: variable can replace another variable (don't remove)
;   standard-binding -> <boolean>            If true: variable names a standard binding
;   extended-binding -> <boolean>            If true: variable names an extended binding
;   unused -> <boolean>                      If true: variable is a formal parameter that is never used
;   rest-parameter -> #f | 'list             If true: variable holds rest-argument list
;   consed-rest-arg -> <boolean>             If true: variable is a rest variable in a procedure called with consed rest list
;   rest-cdr -> (rvar . n)                   Variable references the cdr of rest list rvar after n cdrs (0 = rest list itself)
;   rest-null? -> (rvar . n)                 Variable checks if the cdr of rest list rvar after n cdrs is empty (0 = rest list itself)
;   derived-rest-vars -> (v1 v2 ...)         Other variables aliasing or referencing cdrs of a rest variable
;   constant -> <boolean>                    If true: variable has fixed value
;   hidden-refs -> <boolean>                 If true: procedure that refers to hidden global variables
;   inline-transient -> <boolean>            If true: was introduced during inlining
;
; <lambda-id>:
;
;   contains -> (<lambda-id> ...)            Procedures contained in this lambda
;   contained-in -> <lambda-id>              Procedure containing this lambda
;   has-unused-parameters -> <boolean>       If true: procedure has unused formal parameters
;   use-expr -> (<lambda-id> ...)            Marks non-direct use-sites of common subexpression
;   closure-size -> <integer>                Number of free variables stored in a closure
;   customizable -> <boolean>                If true: all call sites are known, procedure does not escape
;   simple -> <boolean>                      If true: procedure only calls its continuation
;   explicit-rest -> <boolean>               If true: procedure is called with consed rest list
;   captured-variables -> (<var> ...)        List of closed over variables
;   inline-target -> <boolean>               If true: was target of an inlining operation


(declare
 (unit compiler)
 (uses eval extras expand data-structures scrutinizer support))

(module chicken.compiler.core
    (analyze-expression canonicalize-expression compute-database-statistics
     initialize-compiler perform-closure-conversion perform-cps-conversion
     prepare-for-code-generation build-toplevel-procedure

     ;; Various ugly global boolean flags that get set by the (batch) driver
     all-import-libraries preserve-unchanged-import-libraries
     bootstrap-mode compiler-syntax-enabled
     emit-closure-info emit-profile enable-inline-files explicit-use-flag
     first-analysis no-bound-checks compile-module-registration
     optimize-leaf-routines standalone-executable undefine-shadowed-macros
     verbose-mode local-definitions enable-specialization block-compilation
     inline-locally inline-substitutions-enabled strict-variable-types
     static-extensions emit-link-file types-output-file

     ;; These are set by the (batch) driver, and read by the (c) backend
     disable-stack-overflow-checking emit-trace-info external-protos-first
     external-variables insert-timer-checks no-argc-checks
     no-global-procedure-checks no-procedure-checks emit-debug-info

     ;; Other, non-boolean, flags set by (batch) driver
     profiled-procedures import-libraries inline-max-size
     unroll-limit
     extended-bindings standard-bindings

     ;; Non-booleans set and read by the (batch) driver
     required-extensions linked-libraries used-libraries

     ;; non-booleans set by the (batch) driver, and read by the (c) backend
     target-heap-size target-stack-size unit-name used-units

     ;; bindings, set by the (c) platform
     default-extended-bindings default-standard-bindings internal-bindings

     ;; Only read or called by the (c) backend
     foreign-declarations foreign-lambda-stubs foreign-stub-argument-types
     foreign-stub-argument-names foreign-stub-body foreign-stub-callback
     foreign-stub-cps foreign-stub-id foreign-stub-name foreign-stub-return-type
     lambda-literal-id lambda-literal-external lambda-literal-argument-count
     lambda-literal-rest-argument lambda-literal-rest-argument-mode
     lambda-literal-temporaries lambda-literal-float-temporaries
     lambda-literal-callee-signatures lambda-literal-allocated
     lambda-literal-closure-size lambda-literal-looping
     lambda-literal-customizable lambda-literal-body lambda-literal-direct

     ;; Tables and databases that really should not be exported
     constant-table immutable-constants inline-table line-number-database-2
     line-number-database-size)

(import scheme
	chicken.base
	chicken.condition
	chicken.compiler.scrutinizer
	chicken.compiler.support
	chicken.eval
	chicken.fixnum
	chicken.file
	chicken.foreign
	chicken.format
	chicken.internal
	chicken.io
	chicken.keyword
	chicken.load
	chicken.platform
	chicken.pretty-print
	chicken.pathname
	chicken.string
	chicken.syntax
	chicken.type)

(define (d arg1 . more)
  (when (##sys#debug-mode?)
    (if (null? more)
	(pp arg1)
	(apply print arg1 more))))

(define-syntax d (syntax-rules () ((_ . _) (void))))

(include "tweaks")
(include "mini-srfi-1.scm")

(define-inline (gensym-f-id) (gensym 'f_))

(define-constant initial-analysis-database-size 3001)
(define-constant default-line-number-database-size 997)
(define-constant inline-table-size 301)
(define-constant constant-table-size 301)
(define-constant default-inline-max-size 20)
(define-constant default-unroll-limit 1)


;;; Global variables containing compilation parameters:

(define unit-name #f)
(define standard-bindings '())
(define extended-bindings '())
(define insert-timer-checks #t)
(define used-units '())
(define foreign-declarations '())
(define emit-trace-info #f)
(define emit-debug-info #f)
(define block-compilation #f)
(define line-number-database-size default-line-number-database-size)
(define target-heap-size #f)
(define target-stack-size #f)
(define optimize-leaf-routines #f)
(define emit-profile #f)
(define no-bound-checks #f)
(define no-argc-checks #f)
(define no-procedure-checks #f)
(define no-global-procedure-checks #f)
(define safe-globals-flag #f)
(define explicit-use-flag #f)
(define disable-stack-overflow-checking #f)
(define external-protos-first #f)
(define inline-max-size default-inline-max-size)
(define unroll-limit default-unroll-limit)
(define emit-closure-info #t)
(define undefine-shadowed-macros #t)
(define profiled-procedures #f)
(define import-libraries '())
(define all-import-libraries #f)
(define preserve-unchanged-import-libraries #t)
(define compile-module-registration #f) ; 'no | 'yes
(define standalone-executable #t)
(define local-definitions #f)
(define inline-locally #f)
(define enable-inline-files #f)
(define compiler-syntax-enabled #t)
(define bootstrap-mode #f)
(define strict-variable-types #f)
(define enable-specialization #f)
(define static-extensions #f)
(define emit-link-file #f)
(define types-output-file #f) ; #t | <filename>

;;; Other global variables:

(define verbose-mode #f)
(define original-program-size #f)
(define current-program-size 0)
(define current-analysis-database-size initial-analysis-database-size)
(define line-number-database-2 #f)
(define immutable-constants '())
(define inline-table #f)
(define constant-table #f)
(define inline-substitutions-enabled #f)
(define direct-call-ids '())
(define first-analysis #t)
(define foreign-variables '())
(define foreign-lambda-stubs '())
(define external-variables '())
(define external-to-pointer '())
(define location-pointer-map '())
(define pending-canonicalizations '())
(define defconstant-bindings '())
(define callback-names '())
(define toplevel-scope #t)
(define toplevel-lambda-id #f)
(define required-extensions '())
(define linked-libraries '())
(define used-libraries '())

(define unlikely-variables '(unquote unquote-splicing))

;;; Initial bindings.  These are supplied (set!) by the (c-)platform
(define default-extended-bindings '())
(define default-standard-bindings '())
(define internal-bindings '())

;;; Initialize globals:

(define (initialize-compiler)
  (if line-number-database-2
      (vector-fill! line-number-database-2 '())
      (set! line-number-database-2 (make-vector line-number-database-size '())) )
  (if inline-table
      (vector-fill! inline-table '())
      (set! inline-table (make-vector inline-table-size '())) )
  (if constant-table
      (vector-fill! constant-table '())
      (set! constant-table (make-vector constant-table-size '())) )
  (reset-profile-info-vector-name!)
  (clear-real-name-table!)
  (clear-foreign-type-table!) )


;;; Compute general statistics from analysis database:
;
; - Returns:
;
;   current-program-size
;   original-program-size
;   number of known variables
;   number of known procedures
;   number of global variables
;   number of known call-sites
;   number of database entries
;   average bucket load

(define (compute-database-statistics db)
  (let ((nprocs 0)
	(nvars 0)
	(nglobs 0)
	(entries 0)
	(nsites 0) )
    (hash-table-for-each
     (lambda (sym plist)
       (for-each
	(lambda (prop)
	  (set! entries (+ entries 1))
	  (case (car prop)
	    ((global) (set! nglobs (+ nglobs 1)))
	    ((value)
	     (set! nvars (+ nvars 1))
	     (if (eq? '##core#lambda (node-class (cdr prop)))
		 (set! nprocs (+ nprocs 1)) ) )
	    ((call-sites) (set! nsites (+ nsites (length (cdr prop))))) ) )
	plist) )
     db)
    (values current-program-size
	    original-program-size
	    nvars
	    nprocs
	    nglobs
	    nsites
	    entries) ) )

;;; Expand macros and canonicalize expressions:

(define (canonicalize-expression exp)
  (let ((compiler-syntax '())
        (forbidden-refs '()))

  (define (find-id id se)		; ignores macro bindings
    (cond ((null? se) #f)
	  ((and (eq? id (caar se)) (symbol? (cdar se))) (cdar se))
	  (else (find-id id (cdr se)))))

  (define (lookup id)
    (cond ((find-id id (##sys#current-environment)))
	  ((##sys#get id '##core#macro-alias) symbol? => values)
	  (else id)))

  (define (macro-alias var)
    (let ((alias (gensym var)))
      (##sys#put! alias '##core#macro-alias (lookup var))
      alias) )

  (define (handle-expansion-result outer-ln)
    (lambda (input output)
      (and-let* (((not (eq? input output)))
		 (ln (or (get-line-number input) outer-ln)))
	(##sys#update-line-number-database! output ln))
      output))

  (define (canonicalize-body/ln ln body cs?)
    (fluid-let ((chicken.syntax#expansion-result-hook
		 (handle-expansion-result ln)))
      (##sys#canonicalize-body body (##sys#current-environment) cs?)))

  (define (set-real-names! as ns)
    (for-each (lambda (a n) (set-real-name! a n)) as ns) )

  (define (write-to-string x)
    (let ([out (open-output-string)])
      (write x out)
      (get-output-string out) ) )

  (define (unquotify x)
    (if (and (list? x)
	     (= 2 (length x))
	     (symbol? (car x))
	     (eq? 'quote (lookup (car x))))
	(cadr x)
	x) )

  (define (resolve-variable x0 e dest ldest h outer-ln)
    (when (memq x0 unlikely-variables)
      (warning
       (sprintf "reference to variable `~s' possibly unintended" x0) ))
    (let ((x (lookup x0)))
      (d `(RESOLVE-VARIABLE: ,x0 ,x ,(map (lambda (x) (car x)) (##sys#current-environment))))
      (cond ((not (symbol? x)) x0)	; syntax?
	    ((hash-table-ref constant-table x)
	     => (lambda (val) (walk val e dest ldest h #f #f)))
	    ((hash-table-ref inline-table x)
	     => (lambda (val) (walk val e dest ldest h #f #f)))
	    ((assq x foreign-variables)
	     => (lambda (fv)
		  (let* ((t (second fv))
			 (ft (final-foreign-type t))
			 (body `(##core#inline_ref (,(third fv) ,t))))
		    (walk
		     (foreign-type-convert-result
		      (finish-foreign-result ft body)
		      t)
		     e dest ldest h #f #f))))
	    ((assq x location-pointer-map)
	     => (lambda (a)
		  (let* ((t (third a))
			 (ft (final-foreign-type t))
			 (body `(##core#inline_loc_ref (,t) ,(second a))))
		    (walk
		     (foreign-type-convert-result
		      (finish-foreign-result ft body)
		      t)
		     e dest ldest h #f #f))))
	    ((not (memq x e)) (##sys#alias-global-hook x #f (cons h outer-ln))) ; only if global
            ((assq x forbidden-refs) =>
             (lambda (a)
               (let ((ln (cdr a)))
                 (quit-compiling
                   "~acyclical reference in LETREC binding for variable `~a'"
                   (if ln (sprintf "(~a) - " ln) "")
                   (get-real-name x)))))
	    (else x))))

  (define (emit-import-lib name mod il)
    (let* ((fname (if all-import-libraries
		      (string-append (symbol->string name) ".import.scm")
		      (cdr il)))
	   (imps (##sys#compiled-module-registration mod #f))
	   (oldimps
	    (and (file-exists? fname)
		 (call-with-input-file fname read-expressions))))
      (cond ((and (equal? imps oldimps) preserve-unchanged-import-libraries)
	     (when verbose-mode
	       (print "not generating import library `" fname "' for module `"
		      name "' because imports did not change")) )
	    (else
	     (when verbose-mode
	       (print "generating import library `" fname "' for module `"
		      name "' ..."))
	     (with-output-to-file fname
	       (lambda ()
		 (print ";;;; " fname " - GENERATED BY CHICKEN "
			(chicken-version) " -*- Scheme -*-\n")
		 (for-each pretty-print imps)
		 (print "\n;; END OF FILE"))))) ) )

  (define (walk x e dest ldest h outer-ln tl?)
    (cond ((keyword? x) `(quote ,x))
	  ((symbol? x) (resolve-variable x e dest ldest h outer-ln))
	  ((not (pair? x))
	   (if (constant? x)
	       `(quote ,x)
	       (##sys#syntax-error/context "illegal atomic form" x)))
	  ((symbol? (car x))
	   (let ((ln (or (get-line-number x) outer-ln)))
	     (emit-syntax-trace-info x #f)
	     (unless (list? x)
	       (if ln
		   (##sys#syntax-error/context (sprintf "(~a) - malformed expression" ln) x)
		   (##sys#syntax-error/context "malformed expression" x)))
	     (set! ##sys#syntax-error-culprit x)
	     (let* ((name (lookup (car x)))
		    (xexpanded
		     (fluid-let ((chicken.syntax#expansion-result-hook
				  (handle-expansion-result ln)))
		       (expand x (##sys#current-environment) compiler-syntax-enabled))))
	       (cond ((not (eq? x xexpanded))
		      (walk xexpanded e dest ldest h ln tl?))

		     ((hash-table-ref inline-table name)
		      => (lambda (val)
			   (walk (cons val (cdr x)) e dest ldest h ln #f)))

		     (else
		      (case name

			((##core#if)
			 `(if
			   ,(walk (cadr x) e #f #f h ln #f)
			   ,(walk (caddr x) e #f #f h ln #f)
			   ,(if (null? (cdddr x))
				'(##core#undefined)
				(walk (cadddr x) e #f #f h ln #f) ) ) )

			((##core#syntax ##core#quote)
			 `(quote ,(strip-syntax (cadr x))))

			((##core#check)
			 (if unsafe
			     '(quote #t)
			     (walk (cadr x) e dest ldest h ln tl?) ) )

			((##core#the)
			 `(##core#the
			   ,(strip-syntax (cadr x))
			   ,(caddr x)
			   ,(walk (cadddr x) e dest ldest h ln tl?)))

			((##core#local-specialization)
			 (let* ((name (resolve-variable (cadr x) e dest ldest h outer-ln))
				(raw-alias (caddr x))
				(resolved-alias (resolve-variable raw-alias e dest ldest h outer-ln))
				(specs (##sys#get name '##compiler#local-specializations '())))
			   (letrec ((resolve-alias (lambda (form)
						     (cond ((pair? form) (cons (resolve-alias (car form)) (resolve-alias (cdr form))))
							   ((eq? form raw-alias) resolved-alias)
							   (else form)))))
			     (##sys#put! name '##compiler#local-specializations (##sys#append specs (resolve-alias (cdddr x))))
			     '(##core#undefined))))

			((##core#typecase)
			 `(##core#typecase
			   ,(or ln (cadr x))
			   ,(walk (caddr x) e #f #f h ln tl?)
			   ,@(map (lambda (cl)
				    (list (strip-syntax (car cl))
					  (walk (cadr cl) e dest ldest h ln tl?)))
				  (cdddr x))))

			((##core#immutable)
			 (let ((c (cadadr x)))
			   (cond [(assoc c immutable-constants) => cdr]
				 [else
				  (let ([var (gensym 'c)])
				    (set! immutable-constants (alist-cons c var immutable-constants))
				    (mark-variable var '##compiler#always-bound)
				    (hide-variable var)
				    var) ] ) ) )

			((##core#provide ##core#primitive ##core#undefined) x)

			((##core#callunit)
			 (let ((unit (cadr x)))
			   (set! used-units (lset-adjoin/eq? used-units unit))
			   `(##core#callunit ,unit)))

			((##core#inline_ref)
			 `(##core#inline_ref
			   (,(caadr x) ,(strip-syntax (cadadr x)))))

			((##core#inline_loc_ref)
			 `(##core#inline_loc_ref
			   ,(strip-syntax (cadr x))
			   ,(walk (caddr x) e dest ldest h ln #f)))

			((##core#require-for-syntax)
			 (chicken.load#load-extension (cadr x) #f #f)
			 '(##core#undefined))

			((##core#require)
			 (let ((lib (cadr x))
			       (mod (and (pair? (cddr x)) (caddr x))))
			   (unless (chicken.load#core-library? lib)
			     (set! required-extensions (lset-adjoin/eq? required-extensions lib)))
			   (walk (##sys#process-require
				  lib mod
				  (if (or (memq lib linked-libraries) static-extensions)
				      'static
				      'dynamic))
				 e dest ldest h ln #f)))

			((##core#let)
			 (let* ((bindings (cadr x))
				(vars (unzip1 bindings))
				(aliases (map gensym vars))
				(se2 (##sys#extend-se (##sys#current-environment) vars aliases))
				(ln (or (get-line-number x) outer-ln)))
			   (set-real-names! aliases vars)
			   `(let
			     ,(map (lambda (alias b)
				     (list alias (walk (cadr b) e (car b) #t h ln #f)) )
				   aliases bindings)
			     ,(parameterize ((##sys#current-environment se2))
				(walk (canonicalize-body/ln
				       ln (cddr x) compiler-syntax-enabled)
				      (append aliases e)
				      dest ldest h ln #f)) ) )  )

			((##core#letrec*)
			 (let ((bindings (cadr x))
			       (body (cddr x)) )
			   (walk
			    `(##core#let
			      ,(map (lambda (b)
				      (list (car b) '(##core#undefined)))
				    bindings)
			      ,@(map (lambda (b)
				       `(##core#set! ,(car b) ,(cadr b)))
				     bindings)
			      (##core#let () ,@body) )
			    e dest ldest h ln #f)))

			((##core#letrec)
			 (let* ((bindings (cadr x))
				(vars (unzip1 bindings))
				(tmps (map gensym vars))
				(body (cddr x)) )
			   (walk
			    `(##core#let
			      ,(map (lambda (b)
				      (list (car b) '(##core#undefined)))
				    bindings)
			      (##core#let
			       ,(map (lambda (t b)
                                       (list t `(##core#with-forbidden-refs
                                                  ,vars ,ln ,(cadr b))))
                                     tmps bindings)
			       ,@(map (lambda (v t)
					`(##core#set! ,v ,t))
				      vars tmps)
			       (##core#let () ,@body) ) )
			    e dest ldest h ln #f)))

                        ((##core#with-forbidden-refs)
                         (let* ((loc (caddr x))
                                (vars (map (lambda (v)
                                             (cons (resolve-variable v e dest ldest h outer-ln)
                                                   loc))
                                        (cadr x))))
                           (fluid-let ((forbidden-refs
                                         (append vars forbidden-refs)))
                             (walk (cadddr x) e dest ldest h ln #f))))

			((##core#lambda)
			 (let ((llist (cadr x))
			       (obody (cddr x)) )
			   (when (##sys#extended-lambda-list? llist)
			     (set!-values
			      (llist obody)
			      (##sys#expand-extended-lambda-list
			       llist obody ##sys#error (##sys#current-environment)) ) )
			   (##sys#decompose-lambda-list
			    llist
			    (lambda (vars argc rest)
			      (let* ((aliases (map gensym vars))
				     (ln (or (get-line-number x) outer-ln))
				     (se2 (##sys#extend-se (##sys#current-environment) vars aliases))
				     (body (parameterize ((##sys#current-environment se2))
					     (let ((body0 (canonicalize-body/ln
							   ln obody compiler-syntax-enabled)))
                                               (fluid-let ((forbidden-refs '()))
                                                 (walk
                                                   (if emit-debug-info
                                                       `(##core#begin
                                                          (##core#debug-event C_DEBUG_ENTRY (##core#quote ,dest))
                                                         ,body0)
                                                       body0)
                                                   (append aliases e)
                                                   #f #f dest ln #f)))))
				     (llist2
				      (build-lambda-list
				       aliases argc
				       (and rest (list-ref aliases (posq rest vars))) ) )
				     (l `(##core#lambda ,llist2 ,body)) )
				(set-real-names! aliases vars)
				(cond ((or (not dest)
					   ldest
					   (assq dest (##sys#current-environment))) ; not global?
				       l)
				      ((and emit-profile
					    (or (eq? profiled-procedures 'all)
						(and
						 (eq? profiled-procedures 'some)
						 (variable-mark dest '##compiler#profile))))
				       (expand-profile-lambda
					(if (memq dest e) ; should normally not be the case
					    e
					    (##sys#alias-global-hook dest #f #f))
					llist2 body) )
				      (else l)))))))

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
					 (car b))))
				     (cadr x) )
				(##sys#current-environment)) ))
			   (let ((ln (or (get-line-number x) outer-ln)))
			     (walk
			      (canonicalize-body/ln
			       ln (cddr x) compiler-syntax-enabled)
			      e dest ldest h ln #f)) ) )

		       ((##core#letrec-syntax)
			(let* ((ms (map (lambda (b)
					  (list
					   (car b)
					   #f
					   (##sys#ensure-transformer
					    (##sys#eval/meta (cadr b))
					    (car b))))
					(cadr x) ) )
			       (se2 (append ms (##sys#current-environment)))
			       (ln (or (get-line-number x) outer-ln)) )
			  (for-each
			   (lambda (sb)
			     (set-car! (cdr sb) se2) )
			   ms)
			  (parameterize ((##sys#current-environment se2))
			    (walk
			     (canonicalize-body/ln
			      ln (cddr x) compiler-syntax-enabled)
			     e dest ldest h ln #f))))

		       ((##core#define-syntax)
			(##sys#check-syntax
			 (car x) x
			 (if (pair? (cadr x))
			     '(_ (variable . lambda-list) . #(_ 1))
			     '(_ variable _) )
			 #f (##sys#current-environment))
			(let* ((var (if (pair? (cadr x)) (caadr x) (cadr x)))
			       (body (if (pair? (cadr x))
					 `(##core#lambda ,(cdadr x) ,@(cddr x))
					 (caddr x)))
			       (name (lookup var)))
                          (##sys#put/restore! name '##sys#override 'syntax)
			  (##sys#register-syntax-export name (##sys#current-module) body)
			  (##sys#extend-macro-environment
			   name
			   (##sys#current-environment)
			   (##sys#eval/meta body))
			  (walk
			   (if ##sys#enable-runtime-macros
			       `(##sys#extend-macro-environment
				 (##core#quote ,var)
				 (##sys#current-environment) ,body) ;XXX possibly wrong se?
			       '(##core#undefined) )
			   e dest ldest h ln #f)) )

                       ((##core#define-compiler-syntax)
                        (let* ((var (cadr x))
                               (body (caddr x))
                               (name (lookup var)))
                          (when body
                            (set! compiler-syntax
                              (alist-cons
                               name
                               (##sys#get name '##compiler#compiler-syntax)
                               compiler-syntax)))
                          (##sys#put!
                           name '##compiler#compiler-syntax
                           (and body
                                (##sys#cons
                                 (##sys#ensure-transformer
                                  (##sys#eval/meta body)
                                  var)
                                 (##sys#current-environment))))
                          (walk
                           (if ##sys#enable-runtime-macros
                               `(##sys#put!
                                (##core#syntax ,name)
                                '##compiler#compiler-syntax
                                ,(and body
                                      `(##sys#cons
                                        (##sys#ensure-transformer
                                         ,body
                                         (##core#quote ,var))
                                        (##sys#current-environment))))
                               '(##core#undefined) )
                           e dest ldest h ln #f)))

		       ((##core#let-compiler-syntax)
			(let ((bs (map
				   (lambda (b)
				     (##sys#check-syntax
				      'let-compiler-syntax b '(symbol . #(_ 0 1)))
				     (let ((name (lookup (car b))))
				       (list
					name
					(and (pair? (cdr b))
					     (cons (##sys#ensure-transformer
						    (##sys#eval/meta (cadr b))
						    (car b))
						   (##sys#current-environment)))
					(##sys#get name '##compiler#compiler-syntax) ) ) )
				   (cadr x)))
			      (ln (or (get-line-number x) outer-ln)))
			  (dynamic-wind
			      (lambda ()
				(for-each
				 (lambda (b)
				   (##sys#put! (car b) '##compiler#compiler-syntax (cadr b)))
				 bs) )
			      (lambda ()
				(walk
				 (canonicalize-body/ln
				  ln (cddr x) compiler-syntax-enabled)
				 e dest ldest h ln tl?) )
			      (lambda ()
				(for-each
				 (lambda (b)
				   (##sys#put!
				    (car b)
				    '##compiler#compiler-syntax (caddr b)))
				 bs) ) ) ) )

		       ((##core#include)
                         (##sys#include-forms-from-file
                          (cadr x)
                          (caddr x)
                          (lambda (forms path)
                            (let ((code (if (pair? (cdddr x)) ; body?
                                            (canonicalize-body/ln
                                              ln
                                              (append forms (cadddr x))
                                              compiler-syntax-enabled)
                                            `(##core#begin ,@forms))))
                              (fluid-let ((##sys#current-source-filename path))
                                (walk code e dest ldest h ln tl?))))))

		       ((##core#let-module-alias)
			(##sys#with-module-aliases
			 (map (lambda (b)
				(##sys#check-syntax 'functor b '(symbol symbol))
				(strip-syntax b))
			      (cadr x))
			 (lambda ()
			   (walk `(##core#begin ,@(cddr x)) e dest ldest h ln #t))))

		       ((##core#module)
			(let* ((name (strip-syntax (cadr x)))
			       (il  (or (assq name import-libraries) all-import-libraries))
			       (lib (and (not standalone-executable) il (or unit-name name)))
			       (mod (##sys#register-module
				     name lib
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
					      (strip-syntax (caddr x))))))
			       (csyntax compiler-syntax))
			  (when (##sys#current-module)
			    (##sys#syntax-error-hook
			     'module "modules may not be nested" name))
			  (let ((body (parameterize ((##sys#current-module mod)
						     (##sys#current-environment '())
						     (##sys#macro-environment
						      ##sys#initial-macro-environment)
						     (##sys#module-alias-environment
						      (##sys#module-alias-environment)))
					(##sys#with-property-restore
					 (lambda ()
					   (let loop ((body (cdddr x)) (xs '()))
					     (if (null? body)
						 (handle-exceptions ex
						     (begin
						       ;; avoid backtrace
						       (print-error-message ex (current-error-port))
						       (exit 1))
						   (##sys#finalize-module
						    mod
						    (lambda (id)
						      (cond
							((assq id foreign-variables)
							 "a foreign variable")
							((hash-table-ref inline-table id)
							 "an inlined function")
							((hash-table-ref constant-table id)
							 "a constant")
							((##sys#get id '##compiler#type-abbreviation)
							 "a type abbreviation")
							(else #f))))
						   (reverse xs))
						 (loop
						  (cdr body)
						  (cons (walk (car body)
							      e #f #f
							      h ln #t) ; reset to toplevel!
							xs)))))))))
			    (do ((cs compiler-syntax (cdr cs)))
				((eq? cs csyntax) (set! compiler-syntax csyntax))
			      (##sys#put! (caar cs) '##compiler#compiler-syntax (cdar cs)))
			    (when il
			      (emit-import-lib name mod il)
			      (when (pair? il)
				(set! import-libraries
				  (delete il import-libraries equal?))))
			    (canonicalize-begin-body
			     (append
			      (list (list '##core#provide (module-requirement name)))
			      (if (or (eq? compile-module-registration 'yes)
				      (and (not il) ; default behaviour
					   (not compile-module-registration)))
				  (parameterize ((##sys#macro-environment
						  (##sys#meta-macro-environment))
						 (##sys#current-environment ; ???
						  (##sys#current-meta-environment)))
				    (map (lambda (x) (walk x e #f #f h ln tl?))
					 (##sys#compiled-module-registration
					  mod
					  (if static-extensions 'static 'dynamic))))
			          '())
			      body)))))

		       ((##core#loop-lambda) ;XXX is this really needed?
			(let* ((vars (cadr x))
			       (obody (cddr x))
			       (aliases (map gensym vars))
			       (se2 (##sys#extend-se (##sys#current-environment) vars aliases))
			       (ln (or (get-line-number x) outer-ln))
			       (body
				(parameterize ((##sys#current-environment se2))
				  (walk
				   (canonicalize-body/ln ln obody compiler-syntax-enabled)
				   (append aliases e)
				   #f #f dest ln #f)) ) )
			  (set-real-names! aliases vars)
			  `(##core#lambda ,aliases ,body) ) )

		       ((##core#ensure-toplevel-definition)
                         (let* ((var0 (cadr x))
                                (var (lookup var0)))
                           (unless tl?
                             (let ((ln (get-line-number x)))
                               (quit-compiling
                                 "~atoplevel definition of `~s' in non-toplevel context"
                                (if ln (sprintf "(~a) - " ln) "")
                                var)))
                           (##sys#put/restore! var '##sys#override 'value)
                           '(##core#undefined)))

		       ((##core#set!)
			(let* ((var0 (cadr x))
			       (var (lookup var0))
			       (ln (get-line-number x))
			       (val (caddr x)))
			  (when (memq var unlikely-variables)
			    (warning
			     (sprintf "~aassignment to variable `~s' possibly unintended"
			       (if ln (sprintf "(~a) - " ln) "")
			       var)))
			  (cond ((assq var foreign-variables)
				 => (lambda (fv)
				      (let ((type (second fv))
					    (tmp (gensym)))
					(walk
					 `(##core#let ((,tmp ,(foreign-type-convert-argument val type)))
					    (##core#inline_update
					     (,(third fv) ,type)
					     ,(foreign-type-check tmp type)))
					 e #f #f h ln #f))))
				((assq var location-pointer-map)
				 => (lambda (a)
				      (let* ((type (third a))
					     (tmp (gensym)))
					(walk
					 `(##core#let ((,tmp ,(foreign-type-convert-argument val type)))
					    (##core#inline_loc_update
					     (,type)
					     ,(second a)
					     ,(foreign-type-check tmp type)))
					 e #f #f h ln #f))))
				(else
				 (unless (memq var e) ; global?
				   (set! var (##sys#alias-global-hook var #t dest))
				   (when safe-globals-flag
				     (mark-variable var '##compiler#always-bound-to-procedure)
				     (mark-variable var '##compiler#always-bound))
				   (when emit-debug-info
				     (set! val
				       `(##core#let ((,var ,val))
					  (##core#debug-event C_DEBUG_GLOBAL_ASSIGN (##core#quote ,var))
					  ,var)))
				   ;; We use `var0` instead of `var` because the {macro,current}-environment
				   ;; are keyed by the raw and unqualified name
				   (cond ((##sys#macro? var0 (##sys#current-environment))
					  (warning
					   (sprintf "~aassignment to syntax `~S'"
					    (if ln (sprintf "(~a) - " ln) "") var0))
					  (when undefine-shadowed-macros
					    (##sys#undefine-macro! var0)
					    (##sys#unregister-syntax-export var0 (##sys#current-module))))
					 ((assq var0 (##sys#current-environment))
					  (warning
					   (sprintf "~aassignment to imported value binding `~S'"
					    (if ln (sprintf "(~a) - " ln) "") var0)))))
				 `(set! ,var ,(walk val e var0 (memq var e) h ln #f))))))

			((##core#debug-event)
			 `(##core#debug-event
			   ,(cadr x)
			   ,ln ; this arg is added - from this phase on ##core#debug-event has an additional argument!
			   ,@(map (lambda (arg)
				    (unquotify (walk arg e #f #f h ln tl?)))
				  (cddr x))))

			((##core#inline)
			 `(##core#inline
			   ,(unquotify (cadr x)) ,@(mapwalk (cddr x) e h ln #f)))

			((##core#inline_allocate)
			 `(##core#inline_allocate
			   ,(map unquotify (second x))
			   ,@(mapwalk (cddr x) e h ln #f)))

			((##core#inline_update)
			 `(##core#inline_update ,(cadr x) ,(walk (caddr x) e #f #f h ln #f)) )

			((##core#inline_loc_update)
			 `(##core#inline_loc_update
			   ,(cadr x)
			   ,(walk (caddr x) e #f #f h ln #f)
			   ,(walk (cadddr x) e #f #f h ln #f)) )

			((##core#compiletimetoo ##core#elaborationtimetoo)
			 (let ((exp (cadr x)))
			   (##sys#eval/meta exp)
			   (walk exp e dest #f h ln tl?) ) )

			((##core#compiletimeonly ##core#elaborationtimeonly)
			 (##sys#eval/meta (cadr x))
			 '(##core#undefined) )

			((##core#begin)
			 (if (pair? (cdr x))
			     (canonicalize-begin-body
			      (let fold ([xs (cdr x)])
				(let ([x (car xs)]
				      [r (cdr xs)] )
				  (if (null? r)
				      (list (walk x e dest ldest h ln tl?))
				      (cons (walk x e #f #f h ln tl?) (fold r)) ) ) ) )
			     '(##core#undefined) ) )

			((##core#foreign-lambda)
			 (walk (expand-foreign-lambda x #f) e dest ldest h ln #f) )

			((##core#foreign-safe-lambda)
			 (walk (expand-foreign-lambda x #t) e dest ldest h ln #f) )

			((##core#foreign-lambda*)
			 (walk (expand-foreign-lambda* x #f) e dest ldest h ln #f) )

			((##core#foreign-safe-lambda*)
			 (walk (expand-foreign-lambda* x #t) e dest ldest h ln #f) )

			((##core#foreign-primitive)
			 (walk (expand-foreign-primitive x) e dest ldest h ln #f) )

			((##core#define-foreign-variable)
			 (let* ((var (strip-syntax (second x)))
				(type (strip-syntax (third x)))
				(name (if (pair? (cdddr x))
					  (fourth x)
					  (symbol->string var))))
			   (set! foreign-variables
			     (cons (list var type name)
				   foreign-variables))
			   '(##core#undefined) ) )

			((##core#define-foreign-type)
			 (let ((name (second x))
			       (type (strip-syntax (third x)))
			       (conv (cdddr x)))
			   (unless tl?
			     (quit-compiling
			      "~adefinition of foreign type `~s' in non-toplevel context"
			      (if ln (sprintf "(~a) - " ln) "")
			      name))
			   (cond [(pair? conv)
				  (let ([arg (gensym)]
					[ret (gensym)] )
				    (register-foreign-type! name type arg ret)
				    (mark-variable arg '##compiler#always-bound)
				    (mark-variable ret '##compiler#always-bound)
				    (hide-variable arg)
				    (hide-variable ret)
				    ;; NOTE: Above we already check we're in toplevel context,
				    ;; so we can unconditionally register the export here.
				    ;; TODO: Remove after fixing #1615
				    (##sys#register-export arg (##sys#current-module))
				    (##sys#register-export ret (##sys#current-module))
				    (walk
				     `(##core#begin
					(##core#set! ,arg ,(first conv))
					(##core#set!
					 ,ret
					 ,(if (pair? (cdr conv)) (second conv) '##sys#values)) )
				     e dest ldest h ln tl?))]
				 [else
				  (register-foreign-type! name type)
				  '(##core#undefined) ] ) ) )

			((##core#define-external-variable)
			 (let* ((sym (second x))
				(ln (get-line-number x))
				(name (symbol->string sym))
				(type (third x))
				(exported (fourth x))
				(rname (make-random-name)) )
			   (unless tl?
			     (quit-compiling
			      "~aexternal variable definition of `~s' in non-toplevel context"
			      (if ln (sprintf "(~a) - " ln) "")
			      sym))
			   (unless exported (set! name (symbol->string (fifth x))))
			   (set! external-variables (cons (vector name type exported) external-variables))
			   (set! foreign-variables
			     (cons (list rname 'c-pointer (string-append "&" name))
				   foreign-variables) )
			   (set! external-to-pointer (alist-cons sym rname external-to-pointer))
			   '(##core#undefined) ) )

			((##core#let-location)
			 (let* ((var (second x))
				(type (strip-syntax (third x)))
				(alias (gensym))
				(store (gensym))
				(init (and (pair? (cddddr x)) (fourth x))))
			   (set-real-name! alias var)
			   (set! location-pointer-map
			     (cons (list alias store type) location-pointer-map) )
			   (parameterize ((##sys#current-environment
					   (alist-cons var alias (##sys#current-environment))))
			    (walk
			     `(##core#let (,(let ((size (bytes->words (estimate-foreign-result-location-size type))))
				       ;; Add 2 words: 1 for the header, 1 for double-alignment:
				       ;; Note: C_a_i_bytevector takes number of words, not bytes
				       (list
					store
					`(##core#inline_allocate
					  ("C_a_i_bytevector" ,(+ 2 size))
					  ',size)) ) )
				(##core#begin
				 ,@(if init
				       `((##core#set! ,alias ,init))
				       '() )
				 ,(if init (fifth x) (fourth x)) ) )
			     e
			     dest ldest h ln #f)) ) )

			((##core#define-inline)
			 (let* ((name (second x))
				(val `(##core#lambda ,@(cdaddr x)))
				(ln (get-line-number x)))
			   (unless tl?
			     (quit-compiling
			      "~ainline definition of `~s' in non-toplevel context"
			      (if ln (sprintf "(~a) - " ln) "")
			      name))
			     (hash-table-set! inline-table name val)
			     '(##core#undefined)))

			((##core#define-constant)
			 (let* ((name (second x))
				(ln (get-line-number x))
				(valexp (third x))
				(val (handle-exceptions ex
					 ;; could show line number here
					 (quit-compiling "error in constant evaluation of ~S for named constant `~S'"
					       valexp name)
				       (if (and (not (symbol? valexp))
						(collapsable-literal? valexp))
					   valexp
					   (eval
					    `(##core#let
					      ,defconstant-bindings ,valexp))))))
			   (unless tl?
			     (quit-compiling
			      "~aconstant definition of `~s' in non-toplevel context"
			      (if ln (sprintf "(~a) - " ln) "")
			      name))
			   (set! defconstant-bindings
			     (cons (list name `(##core#quote ,val)) defconstant-bindings))
			   (cond ((collapsable-literal? val)
				  (hash-table-set! constant-table name `(##core#quote ,val))
				  '(##core#undefined))
				 ((basic-literal? val)
				  (let ((var (gensym "constant")))
				    (hash-table-set! constant-table name var)
				    (hide-variable var)
				    (mark-variable var '##compiler#constant)
				    (mark-variable var '##compiler#always-bound)
				    (walk `(define ,var (##core#quote ,val)) e #f #f h ln tl?)))
				 (else
				  (quit-compiling
				   "~ainvalid compile-time value for named constant `~S'"
				   (if ln (sprintf "(~a) - " ln) "")
				   name)))))

			((##core#declare)
			 (walk
			  `(##core#begin
			    ,@(map (lambda (d)
				     (process-declaration d lookup (lambda (id) (memq (lookup id) e))))
				   (cdr x) ) )
			  e #f #f h ln #f) )

			((##core#foreign-callback-wrapper)
			 (let-values ([(args lam) (split-at (cdr x) 4)])
			   (let* ([lam (car lam)]
				  [raw-c-name (cadr (first args))]
				  [name (##sys#alias-global-hook raw-c-name #t dest)]
				  [rtype (cadr (third args))]
				  [atypes (cadr (fourth args))]
				  [vars (second lam)] )
			     (if (valid-c-identifier? raw-c-name)
				 (set! callback-names
				   (cons (cons raw-c-name name) callback-names))
				 (let ((ln (get-line-number x)))
				   (quit-compiling
				    "~aname `~S' of external definition is not a valid C identifier"
				    (if ln (sprintf "(~a) - " ln) "")
				    raw-c-name)))
			     (when (or (not (list? vars))
				       (not (list? atypes))
				       (not (= (length vars) (length atypes))) )
			       (syntax-error
				"non-matching or invalid argument list to foreign callback-wrapper"
				vars atypes) )
			     `(##core#foreign-callback-wrapper
			       ,@(mapwalk args e h ln #f)
			       ,(walk `(##core#lambda
					,vars
					(##core#let
					 ,(let loop ([vars vars] [types atypes])
					    (if (null? vars)
						'()
						(let ([var (car vars)]
						      [type (car types)] )
						  (cons
						   (list
						    var
						    (foreign-type-convert-result
						     (finish-foreign-result
						      (final-foreign-type type)
						      var)
						     type) )
						   (loop (cdr vars) (cdr types)) ) ) ) )
					 ,(foreign-type-convert-argument
					   `(##core#let
					     ()
					     ,@(cond
						((member
						  rtype
						  '((const nonnull-c-string)
						    (const nonnull-unsigned-c-string)
						    nonnull-unsigned-c-string
						    nonnull-c-string))
						 `((##sys#make-c-string
						    (##core#let
						     () ,@(cddr lam))
						    (##core#quote ,name))))
						((member
						  rtype
						  '((const c-string*)
						    (const unsigned-c-string*)
						    unsigned-c-string*
						    c-string*
						    c-string-list
						    c-string-list*))
						 (syntax-error
						  "not a valid result type for callback procedures"
						  rtype
						  name) )
						((member
						  rtype
						  '(c-string
						    (const unsigned-c-string)
						    unsigned-c-string
						    (const c-string)) )
						 `((##core#let
						    ((r (##core#let () ,@(cddr lam))))
						    (,(macro-alias 'and)
						     r
						     (##sys#make-c-string r (##core#quote ,name))) ) ) )
						(else (cddr lam)) ) )
					   rtype) ) )
				      e #f #f h ln #f) ) ) ) )

			((##core#location)
			 (let ([sym (cadr x)])
			   (if (symbol? sym)
			       (cond ((assq (lookup sym) location-pointer-map)
				      => (lambda (a)
					   (walk
					    `(##sys#make-locative ,(second a) 0 #f (##core#quote location))
					    e #f #f h ln #f) ) )
				     ((assq sym external-to-pointer)
				      => (lambda (a) (walk (cdr a) e #f #f h ln #f)) )
				     ((assq sym callback-names)
				      `(##core#inline_ref (,(symbol->string sym) c-pointer)) )
				     (else
				      (walk
				       `(##sys#make-locative ,sym 0 #f (##core#quote location))
				       e #f #f h ln #f) ) )
			       (walk
				`(##sys#make-locative ,sym 0 #f (##core#quote location))
				e #f #f h ln #f) ) ) )

			(else
			 (let* ((x2 (fluid-let ((##sys#syntax-context
						 (cons name ##sys#syntax-context)))
				      (mapwalk x e h ln tl?)))
				(head2 (car x2))
				(old (hash-table-ref line-number-database-2 head2)))
			   (when ln
			     (hash-table-set!
			      line-number-database-2
			      head2
			      (cons name (alist-cons x2 ln (if old (cdr old) '()))) ) )
			   x2))))))))

	  ((not (list? x))
	   (##sys#syntax-error/context "malformed expression" x) )

	  ((constant? (car x))
	   (emit-syntax-trace-info x #f)
	   (warning "literal in operator position" x)
	   (mapwalk x e h outer-ln tl?) )

	  (else
	   (emit-syntax-trace-info x #f)
	   (let ((tmp (gensym)))
	     (walk
	      `(##core#let
		((,tmp ,(car x)))
		(,tmp ,@(cdr x)))
	      e dest ldest h outer-ln #f)))))

  (define (mapwalk xs e h ln tl?)
    (map (lambda (x) (walk x e #f #f h ln tl?)) xs) )

  (when (memq 'c debugging-chicken) (newline) (pretty-print exp))
  (foreign-code "C_clear_trace_buffer();")
  ;; Process visited definitions and main expression:
  (walk
   `(##core#begin
     ,@(let ([p (reverse pending-canonicalizations)])
	 (set! pending-canonicalizations '())
	 p)
     ,(begin
	(set! extended-bindings (append internal-bindings extended-bindings))
	exp) )
   '() #f #f #f #f #t) ) )


(define (process-declaration spec lookup local?)
  (define (check-decl spec minlen . maxlen)
    (let ([n (length (cdr spec))])
      (if (or (< n minlen) (> n (optional maxlen 99999)))
	  (syntax-error "invalid declaration" spec) ) ) )
  (define (globalize var)
    (cond ((local? var)
	   (note-local var)
	   #f)
	  (else (##sys#alias-global-hook (lookup var) #t #f))))
  (define (globalize-all vars)
    (filter-map globalize vars))
  (define (note-local var)
    (##sys#notice
     (sprintf "ignoring declaration for locally bound variable `~a'" var)))
  (call-with-current-continuation
   (lambda (return)
     (unless (pair? spec)
       (syntax-error "invalid declaration specification" spec) )
     (case (strip-syntax (car spec)) ; no global aliasing
       ((uses)
	(let ((units (strip-syntax (cdr spec))))
	  (set! used-libraries (lset-union/eq? used-libraries units))
	  (set! linked-libraries (lset-union/eq? linked-libraries units))))
       ((unit)
	(check-decl spec 1 1)
	(let ((u (strip-syntax (cadr spec))))
	  (when (and unit-name (not (eq? unit-name u)))
	    (warning "unit was already given a name (new name is ignored)"))
	  (set! unit-name u)
	  (set! standalone-executable #f)))
       ((standard-bindings)
	(if (null? (cdr spec))
	    (set! standard-bindings default-standard-bindings)
	    (set! standard-bindings (append (globalize-all (cdr spec)) standard-bindings)) ) )
       ((extended-bindings)
	(if (null? (cdr spec))
	    (set! extended-bindings default-extended-bindings)
	    (set! extended-bindings (append (globalize-all (cdr spec)) extended-bindings)) ) )
       ((usual-integrations)
	(cond [(null? (cdr spec))
	       (set! standard-bindings default-standard-bindings)
	       (set! extended-bindings default-extended-bindings) ]
	      [else
	       (let ([syms (globalize-all (cdr spec))])
		 (set! standard-bindings (lset-intersection/eq? syms default-standard-bindings))
		 (set! extended-bindings (lset-intersection/eq? syms default-extended-bindings)))]))
       ((number-type)
	(check-decl spec 1 1)
	(set! number-type (strip-syntax (cadr spec))))
       ((fixnum fixnum-arithmetic) (set! number-type 'fixnum))
       ((generic) (set! number-type 'generic))
       ((unsafe) (set! unsafe #t))
       ((safe) (set! unsafe #f))
       ((no-bound-checks) (set! no-bound-checks #t))
       ((no-argc-checks) (set! no-argc-checks #t))
       ((no-procedure-checks) (set! no-procedure-checks #t))
       ((disable-interrupts) (set! insert-timer-checks #f))
       ((always-bound)
	(for-each (cut mark-variable <> '##compiler#always-bound) (cdr spec)))
       ((safe-globals) (set! safe-globals-flag #t))
       ((no-procedure-checks-for-usual-bindings)
	(for-each
	 (cut mark-variable <> '##compiler#always-bound-to-procedure)
	 (append default-standard-bindings default-extended-bindings))
	(for-each
	 (cut mark-variable <> '##compiler#always-bound)
	 (append default-standard-bindings default-extended-bindings)))
       ((no-procedure-checks-for-toplevel-bindings)
	(set! no-global-procedure-checks #t))
       ((bound-to-procedure)
	(let ((vars (globalize-all (cdr spec))))
	  (for-each (cut mark-variable <> '##compiler#always-bound-to-procedure) vars)
	  (for-each (cut mark-variable <> '##compiler#always-bound) vars)))
       ((foreign-declare)
	(let ([fds (cdr spec)])
	  (if (every string? fds)
	      (set! foreign-declarations (append foreign-declarations fds))
	      (syntax-error 'declare "invalid declaration" spec) ) ) )
       ((block) (set! block-compilation #t))
       ((separate) (set! block-compilation #f))
       ((keep-shadowed-macros) (set! undefine-shadowed-macros #f))
       ((unused)
	(for-each (cut mark-variable <> '##compiler#unused) (globalize-all (cdr spec))))
       ((enforce-argument-types)
	(for-each
	 (cut mark-variable <> '##compiler#enforce)
	 (globalize-all (cdr spec))))
       ((not)
	(check-decl spec 1)
	(case (strip-syntax (second spec)) ; strip all
	  [(standard-bindings)
	   (if (null? (cddr spec))
	       (set! standard-bindings '())
	       (set! standard-bindings
		 (lset-difference/eq? default-standard-bindings
				      (globalize-all (cddr spec)))))]
	  [(extended-bindings)
	   (if (null? (cddr spec))
	       (set! extended-bindings '())
	       (set! extended-bindings
		 (lset-difference/eq? default-extended-bindings
				      (globalize-all (cddr spec)))))]
	  [(inline)
	   (if (null? (cddr spec))
	       (set! inline-locally #f)
	       (for-each
		(cut mark-variable <> '##compiler#inline 'no)
		(globalize-all (cddr spec)))) ]
	  [(usual-integrations)
	   (cond [(null? (cddr spec))
		  (set! standard-bindings '())
		  (set! extended-bindings '()) ]
		 [else
		  (let ([syms (globalize-all (cddr spec))])
		    (set! standard-bindings (lset-difference/eq? default-standard-bindings syms))
		    (set! extended-bindings (lset-difference/eq? default-extended-bindings syms)))])]
	  ((inline-global)
	   (set! enable-inline-files #t)
	   (when (pair? (cddr spec))
	     (for-each
	      (cut mark-variable <> '##compiler#inline-global 'no)
	      (globalize-all (cddr spec)))))
	  [else
	   (check-decl spec 1 1)
	   (let ((id (strip-syntax (cadr spec))))
	     (case id
	       [(safe) (set! unsafe #t)]
	       [else (warning "unsupported declaration specifier" id)]))]))
       ((compile-syntax)
	(set! ##sys#enable-runtime-macros #t))
       ((block-global hide)
	(let ([syms (globalize-all (cdr spec))])
	  (if (null? syms)
	      (set! block-compilation #t)
	      (for-each hide-variable syms))))
       ((export)
	(set! block-compilation #t)
	(let ((syms (globalize-all (cdr spec))))
	  (for-each export-variable syms)))
       ((emit-external-prototypes-first)
	(set! external-protos-first #t) )
       ((inline)
	(if (null? (cdr spec))
	    (set! inline-locally #t)
	    (for-each
	     (cut mark-variable <> '##compiler#local)
	     (globalize-all (cdr spec)))))
       ((inline-limit)
	(check-decl spec 1 1)
	(let ([n (cadr spec)])
	  (if (number? n)
	      (set! inline-max-size n)
	      (warning
	       "invalid argument to `inline-limit' declaration"
	       spec) ) ) )
       ((unroll-limit)
	(check-decl spec 1 1)
	(let ((n (cadr spec)))
	  (if (number? n)
	      (set! unroll-limit n)
	      (warning
	       "invalid argument to `unroll-limit' declaration"
	       spec) ) ) )
       ((pure)
	(let ((syms (globalize-all (cdr spec))))
	  (if (every symbol? syms)
	      (for-each
	       (cut mark-variable <> '##compiler#pure #t)
	       (globalize-all syms))
	      (quit-compiling
	       "invalid arguments to `pure' declaration: ~S" spec))))
       ((emit-import-library)
	(set! import-libraries
	  (append
	   import-libraries
	   (map (lambda (il)
		  (cond ((symbol? il)
			 (cons il (string-append (symbol->string il) ".import.scm")) )
			((and (list? il) (= 2 (length il))
			      (symbol? (car il)) (string? (cadr il)))
			 (cons (car il) (cadr il)))
			(else
			 (quit-compiling "invalid `import-library' specification: ~S" il))))
		(strip-syntax (cdr spec))))))
	((emit-types-file)
	 (unless types-output-file
	   (set! types-output-file
	     (or (null? (cdr spec))
		 (and (string? (cadr spec)) (null? (cddr spec)) (cadr spec))
		 (quit-compiling "invalid `emit-types-file' declaration: ~S" spec)))))
       ((profile)
	(set! emit-profile #t)
	(cond ((null? (cdr spec))
	       (set! profiled-procedures 'all) )
	      (else
	       (set! profiled-procedures 'some)
	       (for-each
		(cut mark-variable <> '##compiler#profile)
		(globalize-all (cdr spec))))))
       ((local)
	(cond ((null? (cdr spec))
	       (set! local-definitions #t) )
	      (else
	       (for-each
		(cut mark-variable <> '##compiler#local)
		(globalize-all (cdr spec))))))
       ((inline-global)
	(set! enable-inline-files #t)
	(set! inline-locally #t)
	(when (pair? (cdr spec))
	  (for-each
	   (cut mark-variable <> '##compiler#inline-global 'yes)
	   (globalize-all (cdr spec)))))
       ((type)
	(for-each
	 (lambda (spec)
	   (if (not (and (list? spec)
			 (>= (length spec) 2)
			 (symbol? (car spec))))
	       (warning "illegal type declaration" (strip-syntax spec))
	       (let ((name (globalize (car spec)))
		     (type (strip-syntax (cadr spec))))
		 (if (local? (car spec))
		     (note-local (car spec))
		     (let-values (((type pred pure) (validate-type type name)))
		       (cond (type
			      ;; HACK: since `:' doesn't have access to the SE, we
			      ;; fixup the procedure name if type is a named procedure type
			      ;; Quite terrible.
			      (when (and (pair? type)
					 (eq? 'procedure (car type))
					 (symbol? (cadr type)))
				(set-car! (cdr type) name))
			      (mark-variable name '##compiler#type type)
			      (mark-variable name '##compiler#type-source 'local)
			      (when pure
				(mark-variable name '##compiler#pure #t))
			      (when pred
				(mark-variable name '##compiler#predicate pred))
			      (when (pair? (cddr spec))
				(install-specializations
				 name
				 (strip-syntax (cddr spec)))))
			     (else
			      (warning
			       "illegal `type' declaration"
			       (strip-syntax spec)))))))))
	 (cdr spec)))
       ((predicate)
	(for-each
	 (lambda (spec)
	   (cond ((and (list? spec) (symbol? (car spec)) (= 2 (length spec)))
		  (let ((name (globalize (car spec)))
			(type (strip-syntax (cadr spec))))
		    (if (local? (car spec))
			(note-local (car spec))
			(let-values (((type pred pure) (validate-type type name)))
			  (if (and type (not pred))
			      (mark-variable name '##compiler#predicate type)
			      (warning "illegal `predicate' declaration" spec))))))
		 (else
		  (warning "illegal `type' declaration item" spec))))
	 (cdr spec)))
       ((specialize)
	(set! enable-specialization #t))
       ((strict-types)
	(set! strict-variable-types #t))
       (else (warning "unknown declaration specifier" spec)) )
     '(##core#undefined) ) ) )


;;; Create entry procedure:

(define (build-toplevel-procedure node)
  (make-node 'lambda '(()) (list node)))


;;; Expand "foreign-lambda"/"foreign-safe-lambda" forms and add item to stub-list:

(define-record-type foreign-stub
  (make-foreign-stub id return-type name argument-types argument-names body cps callback)
  foreign-stub?
  (id foreign-stub-id)			; symbol
  (return-type foreign-stub-return-type)	  ; type-specifier
  (name foreign-stub-name)			  ; string or #f
  (argument-types foreign-stub-argument-types) ; (type-specifier...)
  (argument-names foreign-stub-argument-names) ; #f or (symbol ...)
  (body foreign-stub-body)		       ; #f or string
  (cps foreign-stub-cps)		       ; boolean
  (callback foreign-stub-callback))	       ; boolean

(define (create-foreign-stub rtype sname argtypes argnames body callback cps)
  ;; try to describe a foreign-lambda type specification
  ;; eg. (type->symbol '(c-pointer (struct "point"))) => point*
  (define (type->symbol type-spec)
    (let loop ([type type-spec])
      (cond
       ((null? type) 'a)
       ((list? type)
	(case (car type)
	  ((c-pointer) (string->symbol (conc (loop (cdr type)) "*"))) ;; if pointer, append *
	  ((const struct) (loop (cdr type))) ;; ignore these
	  (else (loop (car type)))))
       ((or (symbol? type) (string? type)) type)
       (else 'a))))
  (let* ((rtype (strip-syntax rtype))
	 (argtypes (strip-syntax argtypes))
	 (params (if argnames
		     (map gensym argnames)
		     (map (o gensym type->symbol) argtypes)))
	 (f-id (gensym 'stub))
	 (bufvar (gensym))
	 (rsize (estimate-foreign-result-size rtype)))
    (when sname (set-real-name! f-id (string->symbol sname)))
    (set! foreign-lambda-stubs
      (cons (make-foreign-stub f-id rtype sname argtypes argnames body cps callback)
	    foreign-lambda-stubs) )
    (let ([rsize (if callback (+ rsize 24) rsize)] ; 24 -> has to hold cons on 64-bit platforms!
	  [head (if cps
		    `((##core#primitive ,f-id))
		    `(##core#inline ,f-id) ) ]
	  [rest (map (lambda (p t) (foreign-type-check (foreign-type-convert-argument p t) t)) params argtypes)] )
      `(##core#lambda ,params
	 ;; Do minor GC (if callback) to make room on stack:
	 ,@(if callback '((##sys#gc #f)) '())
	 ,(if (zero? rsize)
	      (foreign-type-convert-result (append head (cons '(##core#undefined) rest)) rtype)
	      (let ([ft (final-foreign-type rtype)]
		    [ws (bytes->words rsize)] )
		`(##core#let ([,bufvar (##core#inline_allocate ("C_a_i_bytevector" ,(+ 2 ws)) (##core#quote ,ws))])
		   ,(foreign-type-convert-result
		     (finish-foreign-result ft (append head (cons bufvar rest)))
		     rtype) ) ) ) ) ) ) )

(define (expand-foreign-lambda exp callback?)
  (let* ((name (third exp))
	 (sname (cond ((symbol? name) (symbol->string (strip-syntax name)))
		      ((string? name) name)
		      (else (quit-compiling
			     "name `~s' of foreign procedure has wrong type"
			     name)) ) )
	 (rtype (second exp))
	 (argtypes (cdddr exp)) )
    (create-foreign-stub rtype sname argtypes #f #f callback? callback?) ) )

(define (expand-foreign-lambda* exp callback?)
  (let* ((rtype (second exp))
	 (args (third exp))
	 (body (string-intersperse (cdddr exp) "\n"))
 	 (argtypes (map (lambda (x) (car x)) args))
	 ;; C identifiers aren't hygienically renamed inside body strings
	 (argnames (map cadr (strip-syntax args))))
    (create-foreign-stub rtype #f argtypes argnames body callback? callback?) ) )

;; TODO: Try to fold this procedure into expand-foreign-lambda*
(define (expand-foreign-primitive exp)
  (let* ((hasrtype (and (pair? (cddr exp)) (not (string? (caddr exp)))))
	 (rtype (if hasrtype (second exp) 'void))
	 (args (strip-syntax (if hasrtype (third exp) (second exp))))
	 (body (string-intersperse (if hasrtype (cdddr exp) (cddr exp)) "\n"))
 	 (argtypes (map (lambda (x) (car x)) args))
	 ;; C identifiers aren't hygienically renamed inside body strings
	 (argnames (map cadr (strip-syntax args))))
    (create-foreign-stub rtype #f argtypes argnames body #f #t) ) )


;;; Convert canonicalized node-graph into continuation-passing-style:

(define (perform-cps-conversion node)
  (let ((called-units '()))

  (define (cps-lambda id llist subs k)
    (let ([t1 (gensym 'k)])
      (k (make-node
	  '##core#lambda (list id #t (cons t1 llist) 0)
	  (list (walk (car subs)
		      (lambda (r)
			(make-node '##core#call (list #t) (list (varnode t1) r)) ) ) ) ) ) ) )

  (define (node-for-var? node var)
     (and (eq? (node-class node) '##core#variable)
	  (eq? (car (node-parameters node)) var)))

  (define (walk n k)
    (let ((subs (node-subexpressions n))
	  (params (node-parameters n))
	  (class (node-class n)) )
      (case (node-class n)
	((##core#variable quote ##core#undefined ##core#primitive ##core#provide)
          (k n))
	((if) (let* ((t1 (gensym 'k))
		     (t2 (gensym 'r))
		     (k1 (lambda (r) (make-node '##core#call (list #t) (list (varnode t1) r)))) )
		(make-node
		 'let
		 (list t1)
		 (list (make-node '##core#lambda (list (gensym-f-id) #f (list t2) 0)
				  (list (k (varnode t2))) )
		       (walk (car subs)
			     (lambda (v)
			       (make-node 'if '()
					  (list v
						(walk (cadr subs) k1)
						(walk (caddr subs) k1) ) ) ) ) ) ) ) )
	((let)
	 (let loop ((vars params) (vals subs))
	   (if (null? vars)
	       (walk (car vals) k)
	       (walk (car vals)
		     (lambda (r)
		       (if (node-for-var? r (car vars)) ; Don't generate unneccessary lets
			   (loop (cdr vars) (cdr vals))
			   (make-node 'let
				      (list (car vars))
				      (list r (loop (cdr vars) (cdr vals))) )) ) ) ) ) )
	((lambda ##core#lambda) (cps-lambda (gensym-f-id) (first params) subs k))
	((set!) (let* ((t1 (gensym 't))
		       (immediate? (and (pair? (cdr params)) (cadr params)))
		       (new-params (list (first params) immediate?)))
		  (walk (car subs)
			(lambda (r)
			  (make-node 'let (list t1)
				     (list (make-node 'set! new-params (list r))
					   (k (varnode t1)) ) ) ) ) ) )
	((##core#foreign-callback-wrapper)
	 (let ((id (gensym-f-id))
	       (lam (first subs)) )
	   (register-foreign-callback-stub! id params)
	   (cps-lambda id (first (node-parameters lam)) (node-subexpressions lam) k) ) )
	((##core#inline ##core#inline_allocate ##core#inline_ref ##core#inline_update ##core#inline_loc_ref
			##core#inline_loc_update ##core#debug-event)
	 (walk-inline-call class params subs k) )
	((##core#call) (walk-call (car subs) (cdr subs) params k))
	((##core#callunit)
	 (let ((unit (first params)))
	   (if (memq unit called-units)
	       (walk (make-node '##core#undefined '() '()) k)
	       (fluid-let ((called-units (cons unit called-units)))
		 (walk-call-unit unit k)))))
	((##core#the ##core#the/result)
	 ;; remove "the" nodes, as they are not used after scrutiny
	 (walk (car subs) k))
	((##core#typecase)
	 ;; same here, the last clause is chosen, exp is dropped
	 (walk (last subs) k))
	(else (bomb "bad node (cps)")) ) ) )

  (define (walk-call fn args params k)
    (let ((t0 (gensym 'k))
	  (t3 (gensym 'r)) )
      (make-node
       'let (list t0)
       (list (make-node '##core#lambda (list (gensym-f-id) #f (list t3) 0)
			(list (k (varnode t3))) )
	     (walk-arguments
	      args
	      (lambda (vars)
		(walk fn
		      (lambda (r)
			(make-node '##core#call params (cons* r (varnode t0) vars) ) ) ) ) ) ) ) ) )

  (define (walk-call-unit unitname k)
    (let ((t0 (gensym 'k))
	  (t3 (gensym 'r)) )
      (make-node
       'let (list t0)
       (list (make-node '##core#lambda (list (gensym-f-id) #f (list t3) 0)
			(list (k (varnode t3))) )
	     (make-node '##core#callunit (list unitname)
			(list (varnode t0)) ) ) ) ) )

  (define (walk-inline-call class op args k)
    (walk-arguments
     args
     (lambda (vars)
       (k (make-node class op vars)) ) ) )

  (define (walk-arguments args wk)
    (let loop ((args args) (vars '()))
      (cond ((null? args) (wk (reverse vars)))
	    ((atomic? (car args))
	     (loop (cdr args) (cons (car args) vars)) )
	    (else
	     (let ((t1 (gensym 'a)))
	       (walk (car args)
		     (lambda (r)
		       (if (node-for-var? r t1) ; Don't generate unneccessary lets
			   (loop (cdr args) (cons (varnode t1) vars) )
			   (make-node 'let (list t1)
				      (list r
					    (loop (cdr args)
						  (cons (varnode t1) vars) ) ) )) ) ) ) ) ) ) )

  (define (atomic? n)
    (let ((class (node-class n)))
      (or (memq class '(quote ##core#variable ##core#undefined))
	  (and (memq class '(##core#inline_allocate
			     ##core#inline_ref ##core#inline_update
			     ##core#inline_loc_ref ##core#inline_loc_update))
	       (every atomic? (node-subexpressions n)) ) ) ) )

  (walk node values)))


;;; Perform source-code analysis:

(define (analyze-expression node)
  ;; Avoid crowded hash tables by using previous run's size as heuristic
  (let* ((db-size (fx* (fxmax current-analysis-database-size 1) 3))
	 (db (make-vector db-size '())))

    (define (grow n)
      (set! current-program-size (+ current-program-size n)) )

    ;; fullenv is constantly (append localenv env). It's there to avoid
    ;; exponential behaviour by APPEND calls when compiling deeply nested LETs
    (define (walk n env localenv fullenv here)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n))
	    (class (node-class n)) )
	(grow 1)
	(case class
	  ((quote ##core#undefined ##core#provide ##core#proc) #f)

	  ;; Uneliminated rest-cdr calls need to hang on to rest var
	  ((##core#variable ##core#rest-cdr)
	   (let ((var (first params)))
	     (ref var n)
	     (unless (memq var localenv)
	       (grow 1)
	       (cond ((memq var env)
		      (db-put! db var 'captured #t))
		     ((not (db-get db var 'global))
		      (db-put! db var 'global #t) ) ) ) ) )

	  ((##core#callunit ##core#recurse)
	   (grow 1)
	   (walkeach subs env localenv fullenv here))

	  ((##core#call)
	   (grow 1)
	   (let ([fun (car subs)])
	     (when (eq? '##core#variable (node-class fun))
	       (let* ((name (first (node-parameters fun)))
                      (val (db-get db name 'value)))
                 (when (and first-analysis
                            val
                            (not (db-get db name 'global))
                            (not (db-get db name 'unknown))
                            (eq? '##core#lambda (node-class val))
                            (not (llist-match? (third (node-parameters val))
                                               (cdr subs))))
                    (quit-compiling
		      "known procedure called with wrong number of arguments: `~A'"
	              (real-name name)))
		 (collect! db name 'call-sites (cons here n))))
	     (walk (first subs) env localenv fullenv here)
	     (walkeach (cdr subs) env localenv fullenv here)))

	  ((let ##core#let)
	   (let ([env2 (append params fullenv)])
	     (let loop ([vars params] [vals subs])
	       (if (null? vars)
		   (walk (car vals) env (append params localenv) env2 here)
		   (let ([var (car vars)]
			 [val (car vals)] )
		     (db-put! db var 'home here)
		     (assign var val env2 here)
		     (walk val env localenv fullenv here)
		     (loop (cdr vars) (cdr vals)) ) ) ) ) )

	  ((lambda) ; this is an intermediate lambda, slightly different
	   (grow 1) ; from '##core#lambda nodes (params = (LLIST));
	   (##sys#decompose-lambda-list	; CPS will convert this into ##core#lambda
	    (first params)
	    (lambda (vars argc rest)
	      (for-each
	       (lambda (var) (db-put! db var 'unknown #t))
	       vars)
	      (let ([tl toplevel-scope])
		(set! toplevel-scope #f)
		(walk (car subs) fullenv vars (append vars fullenv) #f)
		(set! toplevel-scope tl) ) ) ) )

	  ((##core#lambda ##core#direct_lambda)
	   (grow 1)
	   (##sys#decompose-lambda-list
	    (third params)
	    (lambda (vars argc rest)
	      (let ([id (first params)]
		    [size0 current-program-size] )
		(when here
		  (collect! db here 'contains id)
		  (db-put! db id 'contained-in here) )
		(for-each
		 (lambda (var)
		   (db-put! db var 'home here)
		   (db-put! db var 'unknown #t) )
		 vars)
		(when rest
		  (db-put! db rest 'rest-parameter 'list)
		  (db-put! db rest 'rest-cdr (cons rest 0)))
		(when (simple-lambda-node? n) (db-put! db id 'simple #t))
		(let ([tl toplevel-scope])
		  (unless toplevel-lambda-id (set! toplevel-lambda-id id))
		  (when (and (second params) (not (eq? toplevel-lambda-id id)))
		    (set! toplevel-scope #f)) ; only if non-CPS lambda
		  (walk (car subs) fullenv vars (append vars fullenv) id)
		  (set! toplevel-scope tl)
		  ;; decorate ##core#call node with size
		  (set-car! (cdddr (node-parameters n)) (- current-program-size size0)) ) ) ) ) )

	  ((set! ##core#set!) 		;XXX ##core#set! still used?
	   (let* ((var (first params))
		  (val (car subs)) )
	     (when (and first-analysis (not bootstrap-mode))
	       (case (variable-mark var '##compiler#intrinsic)
		 ((standard)
		  (warning "redefinition of standard binding" var) )
		 ((extended)
		  (warning "redefinition of extended binding" var) ) ))
	     (collect! db var 'potential-values val)
	     (unless (memq var localenv)
	       (grow 1)
	       (cond ((memq var env)
		      (db-put! db var 'captured #t))
		     ((not (db-get db var 'global))
		      (db-put! db var 'global #t) ) ) )
	     (assign var val fullenv here)
	     (unless toplevel-scope (db-put! db var 'assigned-locally #t))
	     (db-put! db var 'assigned #t)
	     (walk (car subs) env localenv fullenv here)))

	  ((##core#primitive ##core#inline)
	   (let ((id (first params)))
	     (when (and first-analysis here (symbol? id) (get-real-name id))
	       (set-real-name! id here) )
	     (walkeach subs env localenv fullenv here)))

	  (else (walkeach subs env localenv fullenv here)))))

    (define (walkeach xs env lenv fenv here)
      (for-each (lambda (x) (walk x env lenv fenv here)) xs) )

    (define (mark-rest-cdr var rvar depth)
      (db-put! db var 'rest-cdr (cons rvar depth))
      (collect! db rvar 'derived-rest-vars var))

    (define (mark-rest-null? var rvar depth)
      (db-put! db var 'rest-null? (cons rvar depth))
      (collect! db rvar 'derived-rest-vars var))

    (define (assign var val env here)
      ;; Propagate rest-cdr and rest-null? onto aliased variables
      (and-let* (((eq? '##core#variable (node-class val)))
		 (v (db-get db (first (node-parameters val)) 'rest-cdr)))
	(mark-rest-cdr var (car v) (cdr v)) )

      (and-let* (((eq? '##core#variable (node-class val)))
		 (v (db-get db (first (node-parameters val)) 'rest-null?)))
	(mark-rest-null? var (car v) (cdr v)) )

      (cond ((eq? '##core#undefined (node-class val))
	     (db-put! db var 'undefined #t) )
	    ((and (eq? '##core#variable (node-class val)) ; assignment to itself
		  (eq? var (first (node-parameters val))) ) )

	    ;; Propagate info from ##core#rest-{cdr,null?} nodes to var
	    ((eq? '##core#rest-cdr (node-class val))
	     (let ((restvar (car (node-parameters val)))
		   (depth (cadr (node-parameters val))))
	       (mark-rest-cdr var restvar (add1 depth)) ) )

	    ((eq? '##core#rest-null? (node-class val))
	     (let ((restvar (car (node-parameters val)))
		   (depth (cadr (node-parameters val))))
	       (mark-rest-null? var restvar depth) ) )

	    ;; (##core#cond (null? r) '() (cdr r)) => result is tagged as a rest-cdr var
	    ((and-let* ((env (match-node val '(##core#cond ()
							   (##core#variable (test-var))
							   (quote (()))
							   (##core#rest-cdr (rvar depth)))
					 '(test-var rvar depth)))
			((db-get db (alist-ref 'test-var env) 'rest-null?)))
	       env)
	     => (lambda (env)
		  (let ((rvar (alist-ref 'rvar env))
			(depth (alist-ref 'depth env)))
		    (mark-rest-cdr var rvar (add1 depth)) ) ) )

	    ((or (memq var env)
		 (variable-mark var '##compiler#constant)
		 (not (variable-visible? var block-compilation)))
	     (let ((props (db-get-all db var 'unknown 'value))
		   (home (db-get db var 'home)) )
	       (unless (assq 'unknown props)
		 (if (assq 'value props)
		     (db-put! db var 'unknown #t)
		     (if (or (not home) (eq? here home))
			 (db-put! db var 'value val)
			 (db-put! db var 'unknown #t) ) ) ) ) )
	    ((and (or local-definitions
		      (variable-mark var '##compiler#local))
		  (not (db-get db var 'unknown)))
	     (let ((home (db-get db var 'home)))
	       (cond ((db-get db var 'local-value)
		      (db-put! db var 'unknown #t))
		     ((or (not home) (eq? here home))
		      (db-put! db var 'local-value val)	       )
		     (else (db-put! db var 'unknown #t)))))
	    (else (db-put! db var 'unknown #t)) ) )

    (define (ref var node)
      (collect! db var 'references node) )

    (define (quick-put! plist prop val)
      (set-cdr! plist (alist-cons prop val (cdr plist))) )

    ;; Walk toplevel expression-node:
    (debugging 'p "analysis traversal phase...")
    (set! current-program-size 0)
    (walk node '() '() '() #f)

    ;; Complete gathered database information:
    (debugging 'p "analysis gathering phase...")
    (set! current-analysis-database-size 0)
    (hash-table-for-each
     (lambda (sym plist)
       (let ([unknown #f]
	     [value #f]
	     [local-value #f]
	     [potential-values #f]
	     [references '()]
	     [captured #f]
	     [call-sites '()]
	     [assigned #f]
	     [assigned-locally #f]
	     [undefined #f]
	     [global #f]
	     [nreferences 0]
	     [rest-cdr #f]
	     [ncall-sites 0] )

	 (set! current-analysis-database-size (fx+ current-analysis-database-size 1))

	 (for-each
	  (lambda (prop)
	    (case (car prop)
	      [(unknown) (set! unknown #t)]
	      [(references)
	       (set! references (cdr prop))
	       (set! nreferences (length references)) ]
	      [(captured) (set! captured #t)]
	      [(potential-values)
	       (set! potential-values (cdr prop))]
	      [(call-sites)
	       (set! call-sites (cdr prop))
	       (set! ncall-sites (length call-sites)) ]
	      [(assigned) (set! assigned #t)]
	      [(assigned-locally) (set! assigned-locally #t)]
	      [(undefined) (set! undefined #t)]
	      [(global) (set! global #t)]
	      [(value) (set! value (cdr prop))]
	      [(local-value) (set! local-value (cdr prop))]
	      [(rest-cdr) (set! rest-cdr (cdr prop))] ) )
	  plist)

	 (set! value (and (not unknown) value))
	 (set! local-value (and (not unknown) local-value))

	 ;; If this is the first analysis, register known local or potentially known global
	 ;;  lambda-value id's along with their names:
         (when first-analysis
	   (and-let* ((vals (or (and value (list value))
				(and global potential-values))))
	     (for-each
	      (lambda (val)
		(when (eq? (node-class val) '##core#lambda)
		  (set-real-name! (first (node-parameters val)) sym)))
	      vals)))

	 ;; If this is the first analysis and the variable is global and has no references
	 ;;  and is hidden then issue warning:
	 (when (and first-analysis
		    global
		    (null? references)
		    (not (variable-mark sym '##compiler#unused))
		    (not (variable-hidden? sym))
		    (not (variable-visible? sym block-compilation))
		    (not (variable-mark sym '##compiler#constant)) )
	   (##sys#notice
	    (sprintf "global variable `~S' is only locally visible and never used"
	      sym) ) )

 	 ;; Make 'boxed, if 'assigned & 'captured:
	 (when (and assigned captured)
	   (quick-put! plist 'boxed #t) )

	 ;; Make 'contractable, if it has a procedure as known value, has only one use
	 ;;  and one call-site and if the lambda has no free non-global variables
	 ;;  or is an internal lambda. Make 'inlinable if
	 ;;  use/call count is not 1:
	 (cond (value
		(let ((valparams (node-parameters value)))
		  (when (and (eq? '##core#lambda (node-class value))
			     (or (not (second valparams))
				 (every
				  (lambda (v) (db-get db v 'global))
				  (nth-value 0 (scan-free-variables
						value block-compilation)) ) ) )
		    (if (and (= 1 nreferences) (= 1 ncall-sites))
			(quick-put! plist 'contractable #t)
			(quick-put! plist 'inlinable #t) ) ) ) )
	       (local-value
		;; Make 'inlinable, if it is declared local and has a value
		(let ((valparams (node-parameters local-value)))
		  (when (eq? '##core#lambda (node-class local-value))
		    (let-values (((vars hvars) (scan-free-variables
						local-value block-compilation)))
		      (when (and (db-get db sym 'global)
				 (pair? hvars))
			(quick-put! plist 'hidden-refs #t))
		      (when (or (not (second valparams))
				(every
				 (lambda (v) (db-get db v 'global))
				 vars))
			(quick-put! plist 'inlinable #t) ) ) ) ) )
	       ((variable-mark sym '##compiler#inline-global) =>
		(lambda (n)
		  (when (node? n)
		    (cond (assigned
			   (debugging
			    'i
			    "global inlining candidate was assigned and will not be inlined"
			    sym)
			   (mark-variable sym '##compiler#inline-global 'no))
			  (else
			   (let ((lparams (node-parameters n)))
			     (quick-put! plist 'inlinable #t)
			     (quick-put! plist 'local-value n))))))))

	 ;; Make 'collapsable, if it has a known constant value which
	 ;; is either collapsable or is only referenced once:
	 (when (and value (eq? 'quote (node-class value)) )
	   (let ((val (first (node-parameters value))))
	     (when (or (collapsable-literal? val)
		       (= 1 nreferences) )
	       (quick-put! plist 'collapsable #t) ) ) )

	 ;; If it has a known value that is a procedure, and if the number of call-sites is equal to the
	 ;;  number of references (does not escape), then make all formal parameters 'unused which are
	 ;;  never referenced or assigned (if no rest parameter exist):
	 ;;  - also marks the procedure as 'has-unused-parameters (if not in `callback-names')
	 ;;  - if the procedure is internal (a continuation) do NOT mark unused parameters.
	 ;;  - also: if procedure has rest-parameter and no unused params, mark f-id as 'explicit-rest.
	 (when value
	   (let ((has #f))
	     (when (and (eq? '##core#lambda (node-class value))
			(= nreferences ncall-sites) )
	       (let ((lparams (node-parameters value)))
		 (when (second lparams)
		   (##sys#decompose-lambda-list
		    (third lparams)
		    (lambda (vars argc rest)
		      (unless rest
			(for-each
			 (lambda (var)
			   (cond ((and (not (db-get db var 'references))
				       (not (db-get db var 'assigned)) )
				  (db-put! db var 'unused #t)
				  (set! has #t)
				  #t)
				 (else #f) ) )
			 vars) )
		      (cond ((and has (not (rassoc sym callback-names eq?)))
			     (db-put! db (first lparams) 'has-unused-parameters #t) )
			    (rest
			     (db-put! db (first lparams) 'explicit-rest #t)
			     (db-put! db rest 'consed-rest-arg #t) ) ) ) ) ) ) ) ) )

	 ;; Make 'removable, if it has no references and is not assigned to, and one of the following:
	 ;; - it has either a value that does not cause any side-effects
	 ;; - it is 'undefined
	 ;; - it holds only a 'rest-cdr reference (strictly speaking, it may bomb but we don't care)
	 (when (and (not assigned)
		    (null? references)
		    (or (and value
			     (if (eq? '##core#variable (node-class value))
				 (let ((varname (first (node-parameters value))))
				   (or (not (db-get db varname 'global))
				       (variable-mark varname '##core#always-bound)
				       (intrinsic? varname)))
				 (not (expression-has-side-effects? value db)) ))
			undefined
			rest-cdr) )
	   (quick-put! plist 'removable #t) )

	 ;; Make 'replacable, if
	 ;; - it has a variable as known value and
	 ;; - it is not a global
	 ;; - it is never assigned to and
	 ;; - if either the substitute has a known value itself or
	 ;;   * the substitute is never assigned to and
	 ;;   * we are in block-mode or the substitute is non-global
	 ;;
	 ;;  - The variable that can be substituted for the current one is marked as 'replacing.
	 ;;    This is done to prohibit beta-contraction of the replacing variable (It wouldn't be there, if
	 ;;    it was contracted).
	 (when (and value (not global))
	   (when (eq? '##core#variable (node-class value))
	     (let ((name (first (node-parameters value))) )
	       (when (and (not assigned)
			  (or (and (not (db-get db name 'unknown))
				   (db-get db name 'value))
			      (and (not (db-get db name 'assigned))
				   (or (not (variable-visible?
					     name block-compilation))
				       (not (db-get db name 'global))) ) ))
		 (quick-put! plist 'replacable name)
		 (db-put! db name 'replacing #t) ) ) ) )

	 ;; Make 'replacable, if it has a known value of the form: '(lambda (<xvar>) (<kvar> <xvar>))' and
	 ;;  is an internally created procedure: (See above for 'replacing)
	 (when (and value (eq? '##core#lambda (node-class value)))
	   (let ((params (node-parameters value)))
	     (when (not (second params))
	       (let ((llist (third params))
		     (body (first (node-subexpressions value))) )
		 (when (and (pair? llist)
			    (null? (cdr llist))
			    (eq? '##core#call (node-class body)) )
		   (let ((subs (node-subexpressions body)))
		     (when (= 2 (length subs))
		       (let ((v1 (first subs))
			     (v2 (second subs)) )
			 (when (and (eq? '##core#variable (node-class v1))
				    (eq? '##core#variable (node-class v2))
				    (eq? (first llist) (first (node-parameters v2))) )
			   (let ((kvar (first (node-parameters v1))))
			     (quick-put! plist 'replacable kvar)
			     (db-put! db kvar 'replacing #t) ) ) ) ) ) ) ) ) ) ) ) )

     db)

    ;; Set original program-size, if this is the first analysis-pass:
    (unless original-program-size
      (set! original-program-size current-program-size) )

    ;; return database
    db) )


;;; Collect unsafe global procedure calls that are assigned:

;;; Convert closures to explicit data structures (effectively flattens function-binding
;   structure):

(define (perform-closure-conversion node db)
  (let ((direct-calls 0)
	(customizable '())
	(lexicals '()))

    (define (test sym item) (db-get db sym item))

    (define (register-customizable! var id)
      (set! customizable (lset-adjoin/eq? customizable var))
      (db-put! db id 'customizable #t) )

    (define (register-direct-call! id)
      (set! direct-calls (add1 direct-calls))
      (set! direct-call-ids (lset-adjoin/eq? direct-call-ids id)))

    ;; Gather free-variable information:
    ;; (and: - register direct calls
    ;;       - update (by mutation) call information in "##core#call" nodes)
    (define (gather n here locals)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n)) )
	(case (node-class n)

	  ((##core#variable ##core#rest-cdr)
	   (let ((var (first params)))
	     (if (memq var lexicals)
		 (list var)
		 '())))

	  ((quote ##core#undefined ##core#provide ##core#proc ##core#primitive)
	   '())

	  ((let)
	   ;;XXX remove this test later, shouldn't be needed:
	   (when (pair? (cdr params)) (bomb "let-node has invalid format" params))
	   (let ((c (gather (first subs) here locals))
		 (var (first params)))
	     (append c (delete var (gather (second subs) here (cons var locals)) eq?))))

	  ((set!)
	   (let ((var (first params))
		 (c (gather (first subs) here locals)))
	     (if (memq var lexicals)
		 (cons var c)
		 c)))

	  ((##core#call)
	   (let* ([fn (first subs)]
		  [mode (first params)]
		  [name (and (pair? (cdr params)) (second params))]
		  [varfn (eq? '##core#variable (node-class fn))] )
	     (node-parameters-set!
	      n
	      (cons mode
		    (if (or name varfn)
			(cons name
			      (if varfn
				  (let* ([varname (first (node-parameters fn))]
					 [val (and (not (test varname 'unknown))
						   (not (eq?
							 'no
							 (variable-mark
							  varname '##compiler#inline)))
						   ;; May not be external, see #1665
						   (not (node? (variable-mark varname '##compiler#inline-global)))
						   (or (test varname 'value)
						       (test varname 'local-value)))] )
				    (if (and val (eq? '##core#lambda (node-class val)))
					(let* ([params (node-parameters val)]
					       [llist (third params)]
					       [id (first params)]
					       [refs (test varname 'references)]
					       [sites (test varname 'call-sites)]
					       [custom
						(and refs sites
						     (= (length refs) (length sites))
						     (test varname 'value)
						     (list? llist) ) ] )
					  (cond ((and name
                                                      (not (llist-match? llist (cdr subs))))
                                                   '())
                                                (else
   					          (register-direct-call! id)
					          (when custom (register-customizable! varname id))
					          (list id custom) ) ) )
					'() ) )
				  '() ) )
			'() ) ) )
	     (concatenate (map (lambda (n) (gather n here locals)) subs) ) ))

	  ((##core#lambda ##core#direct_lambda)
	   (##sys#decompose-lambda-list
	    (third params)
	    (lambda (vars argc rest)
	      (let ((id (if here (first params) 'toplevel)))
		(fluid-let ((lexicals (append locals lexicals)))
		  (let ((c (delete-duplicates (gather (first subs) id vars) eq?)))
		    (db-put! db id 'closure-size (length c))
		    (db-put! db id 'captured-variables c)
		    (lset-difference/eq? c locals vars)))))))

	  (else (concatenate (map (lambda (n) (gather n here locals)) subs)) ) ) ))

    ;; Create explicit closures:
    (define (transform n here closure)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n))
	    (class (node-class n)) )
	(case class

	  ((quote ##core#undefined ##core#provide ##core#proc ##core#float
           ##core#float-variable)
            n)

	  ((##core#variable)
	   (let* ((var (first params))
		  (val (ref-var n here closure)) )
	     (if (test var 'boxed)
		 (make-node '##core#unbox '() (list val))
		 val) ) )

	  ((##core#rest-cdr ##core#rest-car ##core#rest-null? ##core#rest-length)
	   (let* ((val (ref-var n here closure))
		  (rest-var (if (eq? val n) (varnode (first params)) val)))
	     (unless (or (eq? val n)
			 (match-node val `(##core#ref (i) (##core#variable (,here))) '(i)))
	       ;; If it's captured, replacement in optimizer was incorrect
	       (bomb "Saw rest op for captured variable.  This should not happen!" class) )
	     ;; If rest-cdrs have not all been eliminated, restore
	     ;; them as regular cdr calls on the rest list variable.
	     ;; This can be improved, as it can actually introduce
	     ;; many more cdr calls than necessary.
	     (cond ((eq? class '##core#rest-cdr)
		    (transform (replace-rest-op-with-list-ops class rest-var params) here closure))

		   ;; If n isn't val, this node was processed and the
		   ;; variable got replaced by a closure access.
		   ((not (eq? val n))
		    (transform (replace-rest-op-with-list-ops class rest-var params) here closure))

		   (else val)) ) )

	  ((if ##core#call ##core#inline ##core#inline_allocate ##core#callunit
	       ##core#inline_ref ##core#inline_update ##core#debug-event
	       ##core#switch ##core#cond ##core#direct_call ##core#recurse ##core#return
               ##core#let_float ##core#box_float ##core#unbox_float
	       ##core#inline_loc_ref
	       ##core#inline_loc_update)
	   (make-node (node-class n) params (maptransform subs here closure)) )

	  ((let)
	   (let* ([var (first params)]
		  [boxedvar (test var 'boxed)]
		  [boxedalias (gensym var)] )
	     (if boxedvar
		 (make-node
		  'let (list boxedalias)
		  (list (transform (first subs) here closure)
			(make-node
			 'let (list var)
			 (list (make-node '##core#box '() (list (varnode boxedalias)))
			       (transform (second subs) here closure) ) ) ) )
		 (make-node
		  'let params
		  (maptransform subs here closure) ) ) ) )

	  ((##core#lambda ##core#direct_lambda)
	   (let ((llist (third params)))
	     (##sys#decompose-lambda-list
	      llist
	      (lambda (vars argc rest)
		(let* ((boxedvars (filter (lambda (v) (test v 'boxed)) vars))
		       (boxedaliases (map cons boxedvars (map gensym boxedvars)))
		       (cvar (gensym 'c))
		       (id (if here (first params) 'toplevel))
		       (capturedvars (or (test id 'captured-variables) '()))
		       (csize (or (test id 'closure-size) 0))
		       (info (and emit-closure-info (second params) (pair? llist))) )
		  ;; If rest-parameter is boxed: mark it as 'boxed-rest
		  ;;  (if we don't do this than preparation will think the (boxed) alias
		  ;;  of the rest-parameter is never used)
		  (and-let* ((rest)
			     ((test rest 'boxed))
			     (rp (test rest 'rest-parameter)) )
		    (db-put! db (cdr (assq rest boxedaliases)) 'boxed-rest #t) )
		  (make-node
		   '##core#closure (list (+ csize (if info 2 1)))
		   (cons
		    (make-node
		     class
		     (list id
			   (second params)
			   (cons
			    cvar
			    (build-lambda-list
			     (map (lambda (v)
				    (cond ((assq v boxedaliases) => cdr)
					  (else v) ) )
				  vars)
			     argc
			     (cond ((and rest (assq rest boxedaliases)) => cdr)
				   (else rest) ) ) )
			   (fourth params) )
		     (list (let ((body (transform (car subs) cvar capturedvars)))
			     (if (pair? boxedvars)
				 (let loop ((aliases (unzip1 boxedaliases))
					    (values
					     (map (lambda (a)
						    (make-node '##core#box '() (list (varnode (cdr a)))))
						  boxedaliases) ))
				   (if (null? aliases)
				       body
				       (make-node 'let (list (car aliases))
						  (list (car values)
							(loop (cdr aliases) (cdr values))))))
				 body) ) ) )
		    (let ((cvars (map (lambda (v) (ref-var (varnode v) here closure))
				      capturedvars) ) )
		      (if info
			  (append
			   cvars
			   (list
			    (qnode
			     (##sys#make-lambda-info
			      (->string (cons (or (real-name id) '?)
					      ;; this is not always correct, due to optimizations
					      (strip-syntax (cdr llist))))))))
			  cvars) ) ) ) ) ) ) ) )

	  ((set!)
	   (let* ((var (first params))
		  (val (first subs))
		  (cval (node-class val))
		  (immf (or (and (eq? 'quote cval) (immediate? (first (node-parameters val))))
			    (and (pair? (cdr params)) (second params))
			    (eq? '##core#undefined cval))))
	     (cond ((posq var closure)
		    => (lambda (i)
			 (if (test var 'boxed)
			     (make-node
			      (if immf '##core#updatebox_i '##core#updatebox)
			      '()
			      (list (make-node '##core#ref (list (add1 i)) (list (varnode here)))
				    (transform val here closure) ) )
			     ;; Is the following actually used???
			     (make-node
			      (if immf '##core#update_i '##core#update)
			      (list (add1 i))
			      (list (varnode here)
				    (transform val here closure) ) ) ) ) )
		   ((test var 'boxed)
		    (make-node
		     (if immf '##core#updatebox_i '##core#updatebox)
		     '()
		     (list (varnode var)
			   (transform val here closure) ) ) )
		   (else (make-node
			  'set! (list var immf)
			  (list (transform val here closure) ) ) ) ) ) )

	  ((##core#primitive)
	   (make-node
	    '##core#closure (list (if emit-closure-info 2 1))
	    (cons (make-node '##core#proc (list (car params) #t) '())
		  (if emit-closure-info
		      (list (qnode (##sys#make-lambda-info (car params))))
		      '() ) ) ) )

	  ((##core#ref) n)

	  (else (bomb "bad node (closure2)")) ) ) )

    (define (maptransform xs here closure)
      (map (lambda (x) (transform x here closure)) xs) )

    (define (ref-var n here closure)
      (let ((var (first (node-parameters n))))
	(cond ((posq var closure)
	       => (lambda (i)
		    (make-node '##core#ref (list (+ i 1))
			       (list (varnode here)) ) ) )
	      (else n) ) ) )

    (debugging 'p "closure conversion gathering phase...")
    (gather node #f '())
    (when (pair? customizable)
      (debugging 'o "customizable procedures" customizable))
    (debugging 'p "closure conversion transformation phase...")
    (let ((node2 (transform node #f #f)))
      (unless (zero? direct-calls)
	(debugging 'o "calls to known targets" direct-calls))
      node2) ) )


;;; Do some preparations before code-generation can commence:

(define-record-type lambda-literal
  (make-lambda-literal id external arguments argument-count rest-argument temporaries
		       float-temporaries callee-signatures allocated directly-called
		       closure-size looping customizable rest-argument-mode body direct)
  lambda-literal?
  (id lambda-literal-id)			       ; symbol
  (external lambda-literal-external)		       ; boolean
  ;; lambda-literal-arguments is used nowhere
  (arguments lambda-literal-arguments)		       ; (symbol ...)
  (argument-count lambda-literal-argument-count)       ; integer
  (rest-argument lambda-literal-rest-argument)	       ; symbol | #f
  (temporaries lambda-literal-temporaries)	       ; integer
  (float-temporaries lambda-literal-float-temporaries)   ; (integer ...)
  (callee-signatures lambda-literal-callee-signatures) ; (integer ...)
  (allocated lambda-literal-allocated)		       ; integer
  ;; lambda-literal-directly-called is used nowhere
  (directly-called lambda-literal-directly-called)     ; boolean
  (closure-size lambda-literal-closure-size)	       ; integer
  (looping lambda-literal-looping)		       ; boolean
  (customizable lambda-literal-customizable)	       ; boolean
  (rest-argument-mode lambda-literal-rest-argument-mode) ; #f | LIST | NONE
  (body lambda-literal-body)				 ; expression
  (direct lambda-literal-direct))			 ; boolean

(define (prepare-for-code-generation node db)
  (let ((literals '())
	(literal-count 0)
	(lambda-info-literals '())
	(lambda-info-literal-count 0)
	;; Use analysis db as optimistic heuristic for procedure table size
	(lambda-table (make-vector (fx* (fxmax current-analysis-database-size 1) 3) '()))
	(temporaries 0)
        (float-temporaries '())
	(allocated 0)
	(looping 0)
	(signatures '())
	(fastinits 0)
	(fastrefs 0)
	(fastsets 0)
	(dbg-index 0)
	(debug-info '()))

    (define (walk-var var e e-count sf)
      (cond [(posq var e)
	     => (lambda (i)
		  (make-node '##core#local (list (fx- e-count (fx+ i 1))) '()))]
	    [(keyword? var) (make-node '##core#literal (list (literal var)) '())]
	    [else (walk-global var sf)] ) )

    (define (walk-global var sf)
      (let* ([safe (or sf
		       no-bound-checks
		       unsafe
		       (variable-mark var '##compiler#always-bound)
		       (intrinsic? var))]
	     [blockvar (and (db-get db var 'assigned)
			    (not (variable-visible? var block-compilation)))])
	(when blockvar (set! fastrefs (add1 fastrefs)))
	(make-node
	 '##core#global
	 (list (if blockvar
		   (blockvar-literal var)
		   (literal var) )
	       safe
	       blockvar
	       var)
	 '() ) ) )

    (define (walk n e e-count here boxes)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n))
	    (class (node-class n)) )
	(case class

	  ((##core#undefined ##core#proc ##core#float) n)

	  ((##core#variable)
	   (walk-var (first params) e e-count #f) )

	  ((##core#direct_call)
	   (let* ((source-info (second params))
		  (demand (fourth params)))
	     (if (and emit-debug-info source-info)
		 (let ((info (list dbg-index 'C_DEBUG_CALL
				   (source-info->line source-info)
				   (source-info->name source-info))))
		   (set! params (cons dbg-index params))
		   (set! debug-info (cons info debug-info))
		   (set! dbg-index (add1 dbg-index)))
		 (set! params (cons #f params)))
	     (set! allocated (+ allocated demand))
	     (make-node class params (mapwalk subs e e-count here boxes))))

	  ((##core#inline_allocate)
	   (set! allocated (+ allocated (second params)))
	   (make-node class params (mapwalk subs e e-count here boxes)) )

          ((##core#box_float)
           (set! allocated (+ allocated 4)) ;; words-per-flonum
           (make-node class params (mapwalk subs e e-count here boxes)))

	  ((##core#inline_ref)
	   (set! allocated (+ allocated (bytes->words (estimate-foreign-result-size (second params)))))
	   (make-node class params '()) )

	  ((##core#inline_loc_ref)
	   (set! allocated (+ allocated (bytes->words (estimate-foreign-result-size (first params)))))
	   (make-node class params (mapwalk subs e e-count here boxes)) )

	  ((##core#closure)
	   (set! allocated (+ allocated (first params) 1))
	   (make-node '##core#closure params (mapwalk subs e e-count here boxes)) )

	  ((##core#box)
	   (set! allocated (+ allocated 2))
	   (make-node '##core#box params (list (walk (first subs) e e-count here boxes))) )

	  ((##core#updatebox)
	   (let* ([b (first subs)]
		  [subs (mapwalk subs e e-count here boxes)] )
	     (make-node
	      (cond [(and (eq? '##core#variable (node-class b))
			  (memq (first (node-parameters b)) boxes) )
		     (set! fastinits (add1 fastinits))
		     '##core#updatebox_i]
		    [else class] )
	      '()
	      subs) ) )

	  ((##core#provide)
	   ;; Allocate enough space for the ##core#provided property.
	   (let ((id (literal (first params))))
	     (set! allocated (+ allocated 8))
	     (make-node class (list id) '())))

	  ((##core#lambda ##core#direct_lambda)
	   (let ((temps temporaries)
                 (ftemps float-temporaries)
		 (sigs signatures)
		 (lping looping)
		 (alc allocated)
		 (direct (eq? class '##core#direct_lambda)) )
	     (set! temporaries 0)
             (set! float-temporaries '())
	     (set! allocated 0)
	     (set! signatures '())
	     (set! looping 0)
	     (##sys#decompose-lambda-list
	      (third params)
	      (lambda (vars argc rest)
		(let* ((id (first params))
		       (rest-mode
			(and rest
			     (let ((rrefs (db-get db rest 'references)))
			       (cond ((db-get db rest 'assigned) 'list)
				     ((and (not (db-get db rest 'boxed-rest))
					   (or (not rrefs) (null? rrefs))) 'none)
				     (else (db-get db rest 'rest-parameter)) ) ) ) )
		       (body (walk
			      (car subs)
			      (##sys#fast-reverse (if (eq? 'none rest-mode)
						      (butlast vars)
						      vars))
			      (if (eq? 'none rest-mode)
				  (fx- (length vars) 1)
				  (length vars))
			      id
			      '()) ) )
		  (when (eq? rest-mode 'none)
		    (debugging 'o "unused rest argument" rest id))
		  (when (and direct rest)
		    (bomb "bad direct lambda" id allocated rest) )
		  (hash-table-set!
		   lambda-table
		   id
		   (make-lambda-literal
		    id
		    (second params)
		    vars
		    argc
		    rest
		    (add1 temporaries)
                    float-temporaries
		    signatures
		    allocated
		    (or direct (memq id direct-call-ids))
		    (or (db-get db id 'closure-size) 0)
		    (and (not rest)
			 (> looping 0)
			 (begin
			   (debugging 'o "identified direct recursive calls" id looping)
			   #t) )
		    (or direct (db-get db id 'customizable))
		    rest-mode
		    body
		    direct) )
		  (set! looping lping)
		  (set! temporaries temps)
                  (set! float-temporaries ftemps)
		  (set! allocated alc)
		  (set! signatures (lset-adjoin/eq? sigs argc))
		  (make-node '##core#proc (list (first params)) '()) ) ) ) ) )

	  ((let)
	   (let* ([var (first params)]
		  [val (first subs)]
		  [boxvars (if (eq? '##core#box (node-class val)) (list var) '())] )
	     (set! temporaries (add1 temporaries))
	     (make-node
	      '##core#bind (list 1)	; is actually never used with more than 1 variable
	      (list (walk val e e-count here boxes)
		    (walk (second subs)
			  (append (##sys#fast-reverse params) e) (fx+ e-count 1)
			  here (append boxvars boxes)) ) ) ) )

	  ((##core#let_float)
	   (let ((i (first params))
	         (val (first subs)))
             (set! float-temporaries (cons i float-temporaries))
	     (make-node
	      '##core#let_float params
	      (list (walk val e e-count here boxes)
		    (walk (second subs) e e-count here boxes) ) ) ) )

	  ((set!)
	   (let ((var (first params))
		 (val (first subs)) )
	     (cond ((posq var e)
		    => (lambda (i)
			 (make-node '##core#setlocal
				    (list (fx- e-count (fx+ i 1)))
				    (list (walk val e e-count here boxes)) ) ) )
		   (else
		    (let* ((cval (node-class val))
			   (blockvar (not (variable-visible?
					   var block-compilation)))
			   (immf (or (and (eq? cval 'quote) (immediate? (first (node-parameters val))))
				     (and (pair? (cdr params)) (second params))
				     (eq? '##core#undefined cval) ) ) )
		      (when blockvar (set! fastsets (add1 fastsets)))
		      (make-node
		       (if immf '##core#setglobal_i '##core#setglobal)
		       (list (if blockvar
				 (blockvar-literal var)
				 (literal var) )
			     blockvar
			     var)
		       (list (walk (car subs) e e-count here boxes)) ) ) ) ) ) )

	  ((##core#call)
	   (let* ((len (length (cdr subs)))
		  (p2 (pair? (cdr params)))
		  (source-info (and p2 (second params))))
	     (set! signatures (lset-adjoin/eq? signatures len))
	     (when (and (>= (length params) 3) (eq? here (third params)))
	       (set! looping (add1 looping)) )
               (if (and emit-debug-info source-info)
                 (let ((info (list dbg-index 'C_DEBUG_CALL
				   (source-info->line source-info)
				   (source-info->name source-info))))
                   (set! params (cons dbg-index params))
                   (set! debug-info (cons info debug-info))
                   (set! dbg-index (add1 dbg-index)))
                 (set! params (cons #f params)))
	     (make-node class params (mapwalk subs e e-count here boxes))))

	  ((##core#recurse)
	   (when (first params) (set! looping (add1 looping)))
	   (make-node class params (mapwalk subs e e-count here boxes)) )

	  ((quote)
	   (let ((c (first params)))
	     (cond ((and (fixnum? c) (not (big-fixnum? c)))
		    (immediate-literal c) )
		   ((number? c)
		    (cond ((eq? 'fixnum number-type)
			   (cond ((and (integer? c) (not (big-fixnum? c)))
				  (warning
				   (sprintf
				       "coerced inexact literal number `~S' to fixnum ~S"
				     c (inexact->exact c)))
				  (immediate-literal (inexact->exact c)) )
				 (else (quit-compiling "cannot coerce inexact literal `~S' to fixnum" c)) ) )
			  (else (make-node '##core#literal (list (literal c)) '())) ) )
		   ((immediate? c) (immediate-literal c))
		   (else (make-node '##core#literal (list (literal c)) '())) ) ) )

	  ((if ##core#cond)
	   (let* ((test (walk (first subs) e e-count here boxes))
		  (t0 temporaries)
		  (a0 allocated)
		  (x1 (walk (second subs) e e-count here boxes))
		  (t1 temporaries)
		  (a1 allocated)
		  (x2 (walk (third subs) e e-count here boxes)))
	     (set! allocated (+ a0 (max (- allocated a1) (- a1 a0))))
	     (set! temporaries (+ t0 (max (- temporaries t1) (- t1 t0))))
	     (make-node class params (list test x1 x2))))

	  ((##core#switch)
	   (let* ((exp (walk (first subs) e e-count here boxes))
		  (a0 allocated))
	     (make-node
	      class
	      params
	      (cons
	       exp
	       (let loop ((j (first params)) (subs (cdr subs)) (ma 0))
		 (set! allocated a0)
		 (if (zero? j)
		     (let ((def (walk (car subs) e e-count here boxes)))
		       (set! allocated (+ a0 (max ma (- allocated a0))))
		       (list def))
		     (let* ((const (walk (car subs) e e-count here boxes))
			    (body (walk (cadr subs) e e-count here boxes)))
		       (cons*
			const body
			(loop (sub1 j) (cddr subs) (max (- allocated a0) ma))))))))))

	  ((##core#debug-event)
	   (let* ((i dbg-index)
		  (params (cons i params)))
	     (set! debug-info (cons params debug-info))
	     (set! dbg-index (add1 dbg-index))
	     (make-node class params '())))

	  (else (make-node class params (mapwalk subs e e-count here boxes)) ) ) ) )

    (define (mapwalk xs e e-count here boxes)
      (map (lambda (x) (walk x e e-count here boxes)) xs) )

    (define (literal x)
      (cond [(immediate? x) (immediate-literal x)]
	    ;; Fixnums that don't fit in 32 bits are treated as non-immediates,
	    ;; that's why we do the (apparently redundant) C_blockp check here.
	    ((and (##core#inline "C_blockp" x) (##core#inline "C_lambdainfop" x))
	     (let ((i lambda-info-literal-count))
	       (set! lambda-info-literals (cons x lambda-info-literals))
	       (set! lambda-info-literal-count (add1 lambda-info-literal-count))
	       (vector i) ) )
	    [(posv x literals) => (lambda (p) (fx- literal-count (fx+ p 1)))]
	    [else (new-literal x)] ) )

    (define (new-literal x)
      (let ([i literal-count])
	(set! literals (cons x literals))
	(set! literal-count (add1 literal-count))
	i) )

    (define (blockvar-literal var)
      (cond
       ((list-index (lambda (lit)
		      (and (block-variable-literal? lit)
			   (eq? var (block-variable-literal-name lit)) ) )
		    literals)
	=> (lambda (p) (fx- literal-count (fx+ p 1))))
       (else (new-literal (make-block-variable-literal var))) ) )

    (define (immediate-literal x)
      (if (eq? (void) x)
	  (make-node '##core#undefined '() '())
	  (make-node '##core#immediate
		     (cond ((fixnum? x) `(fix ,x))
			   ((boolean? x) `(bool ,x))
			   ((char? x) `(char ,x))
			   ((null? x) '(nil))
			   ((eof-object? x) '(eof))
			   ;; TODO: Remove once we have a bootstrapping libchicken with bwp-object?
			   ((##core#inline "C_bwpp" x) #;(bwp-object? x) '(bwp))
			   (else (bomb "bad immediate (prepare)")) )
		     '() ) ) )

    (debugging 'p "preparation phase...")
    (let ((node2 (walk node '() 0 #f '())))
      (when (positive? fastinits)
	(debugging 'o "fast box initializations" fastinits))
      (when (positive? fastrefs)
	(debugging 'o "fast global references" fastrefs))
      (when (positive? fastsets)
	(debugging 'o "fast global assignments" fastsets))
      (values node2
	      (##sys#fast-reverse literals)
	      (##sys#fast-reverse lambda-info-literals)
	      lambda-table
	      (reverse debug-info) ) ) ))
)
