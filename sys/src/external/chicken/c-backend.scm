;;; c-backend.scm - C-generating backend for the CHICKEN compiler
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
  (unit c-backend)
  (uses data-structures extras c-platform compiler internal support))

(module chicken.compiler.c-backend
    (generate-code
     ;; For "foreign" (aka chicken-ffi-syntax):
     foreign-type-declaration)

(import scheme
	chicken.base
	chicken.bitwise
	chicken.fixnum
	chicken.flonum
	chicken.foreign
	chicken.format
	chicken.internal
	chicken.keyword
	chicken.platform
	chicken.sort
	chicken.string
	chicken.time
	chicken.compiler.core
	chicken.compiler.c-platform
	chicken.compiler.support)

(include "mini-srfi-1.scm")

;;; Write atoms to output-port:

(define output #f)

(define (gen . data)
  (for-each
   (lambda (x) 
     (if (eq? #t x)
	 (newline output)
	 (display x output) ) )
   data) )

(define (gen-list lst)
  (for-each
   (lambda (x) (display x output))
   (intersperse lst #\space) ) )

;; Hacky procedures to make certain names more suitable for use in C.
(define (backslashify s) (string-translate* (->string s) '(("\\" . "\\\\"))))
(define (uncommentify s) (string-translate* (->string s) '(("*/" . "*_/"))))
(define (c-identifier s) (string->c-identifier (->string s)))

;; Generate a sorted alist out of a symbol table
(define (table->sorted-alist t)
  (let ((alist '()))
    (hash-table-for-each
      (lambda (id ll)
	(set! alist
	  (cons (cons id ll) alist)))
      t)

    (sort! alist (lambda (p1 p2) (string<? (symbol->string (car p1))
					   (symbol->string (car p2)))))))


;;; Generate target code:

(define (generate-code literals lliterals lambda-table out source-file user-supplied-options dynamic db dbg-info-table)
  (let ((lambda-table* (table->sorted-alist lambda-table)) ;; sort the symbol table to make the compiler output deterministic.
	(non-av-proc #f))

  ;; Don't truncate floating-point precision!
  (flonum-print-precision (+ flonum-maximum-decimal-exponent 1))

    ;; Some helper procedures

    (define (find-lambda id)
      (or (hash-table-ref lambda-table id)
	  (bomb "can't find lambda" id) ) )

    ;; Compile a single expression
    (define (expression node temps ll)

      (define (expr n i)
	(let ((subs (node-subexpressions n))
	      (params (node-parameters n)) )
	  (case (node-class n)

	    ((##core#immediate)
	     (case (first params)
	       ((bool) (gen (if (second params) "C_SCHEME_TRUE" "C_SCHEME_FALSE")))
	       ((char) (gen "C_make_character(" (char->integer (second params)) #\)))
	       ((nil) (gen "C_SCHEME_END_OF_LIST"))
	       ((fix) (gen "C_fix(" (second params) #\)))
	       ((eof) (gen "C_SCHEME_END_OF_FILE"))
	       ((bwp) (gen "C_SCHEME_BROKEN_WEAK_PTR"))
	       (else (bomb "bad immediate")) ) )

	    ((##core#literal) 
	     (let ((lit (first params)))
	       (if (vector? lit)
		   (gen "((C_word)li" (vector-ref lit 0) ")") 
		   (gen "lf[" (first params) #\])) ) )

            ((##core#float)
	     (let ((n (first params)))
	       (gen "(double)")
	       (cond ((nan? n) (gen "NAN"))
		     ((infinite? n)
		      (when (negative? n) (gen #\-))
		      (gen "INFINITY"))
		     (else (gen n)))))

	    ((if)
	     (gen #t "if(C_truep(")
	     (expr (car subs) i)
	     (gen ")){")
	     (expr (cadr subs) i)
	     (gen #\} #t "else{")
	     (expr (caddr subs) i)
	     (gen #\}) )

	    ((##core#proc)
	     (gen "(C_word)" (first params)) )

	    ((##core#bind) 
	     (let loop ((bs subs) (i i) (count (first params)))
	       (cond [(> count 0)
		      (gen #t #\t i #\=)
		      (expr (car bs) i)
		      (gen #\;) 
		      (loop (cdr bs) (add1 i) (sub1 count)) ]
		     [else (expr (car bs) i)] ) ) )

	    ((##core#let_float)
	     (let ((fi (first params)))
	       (gen #t #\f fi #\=)
	       (expr (first subs) i)
	       (gen #\;)
	       (expr (second subs) i)))

            ((##core#float-variable)
             (gen #\f (first params)))

            ((##core#unbox_float)
             (gen "C_flonum_magnitude(")
             (expr (first subs) i)
             (gen ")"))

            ((##core#box_float)
             (gen "C_flonum(&a,")
             (expr (first subs) i)
             (gen ")"))

	    ((##core#ref) 
	     (gen "((C_word*)")
	     (expr (car subs) i)
	     (gen ")[" (+ (first params) 1) #\]) )

	    ((##core#rest-car)
	     (let* ((n (lambda-literal-argument-count ll))
		    (depth (second params))
		    (have-av? (not (or (lambda-literal-customizable ll)
				       (lambda-literal-direct ll)))))
	       (if have-av?
		   (gen "C_get_rest_arg(c," (+ depth n) ",av," n ",t0)")
		   (gen "C_u_i_list_ref(t" (sub1 n) "," depth ")"))))

	    ((##core#rest-null?)
	     (let* ((n (lambda-literal-argument-count ll))
		    (depth (second params))
		    (have-av? (not (or (lambda-literal-customizable ll)
				       (lambda-literal-direct ll)))))
	       (if have-av?
		   (gen "C_rest_nullp(c," (+ depth n) ")")
		   (gen "C_mk_bool(C_unfix(C_i_length(t" (sub1 n) ")) >= " depth ")"))))

	    ((##core#rest-length)
	     (let* ((n (lambda-literal-argument-count ll))
		    (depth (second params))
		    (have-av? (not (or (lambda-literal-customizable ll)
				       (lambda-literal-direct ll)))))
	       (if have-av?
		   (gen "C_fix(c - " (+ depth n) ")")
		   (gen "C_u_i_length(t" (sub1 n) ")"))))

	    ((##core#unbox) 
	     (gen "((C_word*)")
	     (expr (car subs) i)
	     (gen ")[1]") )

	    ((##core#update_i)
	     (gen "C_set_block_item(")
	     (expr (car subs) i)
	     (gen #\, (first params) #\,)
	     (expr (cadr subs) i) 
	     (gen #\)) )

	    ((##core#update)
	     (gen "C_mutate(((C_word *)")
	     (expr (car subs) i)
	     (gen ")+" (+ (first params) 1) ",")
	     (expr (cadr subs) i) 
	     (gen #\)) )

	    ((##core#updatebox_i)
	     (gen "C_set_block_item(")
	     (expr (car subs) i)
	     (gen ",0,")
	     (expr (cadr subs) i) 
	     (gen #\)) )

	    ((##core#updatebox)
	     (gen "C_mutate(((C_word *)")
	     (expr (car subs) i)
	     (gen ")+1,")
	     (expr (cadr subs) i) 
	     (gen #\)) )

	    ((##core#closure)
	     (let ((n (first params)))
	       (gen "(*a=C_CLOSURE_TYPE|" n #\,)
	       (for-each 
		(lambda (x j)
		  (gen "a[" j "]=")
		  (expr x i)
		  (gen #\,) )
		subs (list-tabulate n add1))
	       (gen "tmp=(C_word)a,a+=" (add1 n) ",tmp)") ) )

	    ((##core#box) 
	     (gen "(*a=C_VECTOR_TYPE|1,a[1]=")
	     (expr (car subs) i)
	     (gen ",tmp=(C_word)a,a+=2,tmp)") )

	    ((##core#local) (gen #\t (first params)))

	    ((##core#setlocal) 
	     (gen #\t (first params) #\=)
	     (expr (car subs) i) )

	    ((##core#global)
	     (let ((index (first params))
		   (safe (second params)) 
		   (block (third params)) )
	       (cond [block
		      (if safe
			  (gen "lf[" index "]")
			  (gen "C_retrieve2(lf[" index "],C_text("
			       (c-ify-string (##sys#symbol->string
					      (fourth params))) "))"))]
		     [safe (gen "*((C_word*)lf[" index "]+1)")]
		     [else (gen "C_fast_retrieve(lf[" index "])")] ) ) )

	    ((##core#setglobal)
	     (let ((index (first params))
		   (block (second params)) 
		   (var (third params)))
	       (if block
		   (gen "C_mutate(&lf[" index "]")
		   (gen "C_mutate((C_word*)lf[" index "]+1"))
	       (gen " /* (set! " (uncommentify (##sys#symbol->string var)) " ...) */,")
	       (expr (car subs) i)
	       (gen #\)) ) )

	    ((##core#setglobal_i)
	     (let ((index (first params))
		   (block (second params)) 
		   (var (third params)) )
	       (cond [block
		      (gen "lf[" index "] /* "
			   (uncommentify (##sys#symbol->string var)) " */ =")
		      (expr (car subs) i)
		      (gen #\;) ]
		     [else
		      (gen "C_set_block_item(lf[" index "] /* "
			   (uncommentify (##sys#symbol->string var)) " */,0,")
		      (expr (car subs) i)
		      (gen #\)) ] ) ) )

	    ((##core#undefined) (gen "C_SCHEME_UNDEFINED"))

	    ((##core#call) 
	     (let* ((args (cdr subs))
		    (n (length args))
		    (nc i)
		    (nf (add1 n)) 
		    (dbi (first params))
		    (safe-to-call (second params))
		    (p2 (pair? (cddr params)))
		    (name (and p2 (third params)))
		    (name-str (source-info->string name))
		    (call-id (and p2 (pair? (cdddr params)) (fourth params)))
		    (customizable (and call-id (fifth params)))
		    (empty-closure (and customizable (zero? (lambda-literal-closure-size (find-lambda call-id)))))
		    (fn (car subs)) )
	       (when name
		 (if emit-trace-info
		     (gen #t "C_trace(C_text(\"" (backslashify name-str) "\"));")
		     (gen #t "/* " (uncommentify name-str) " */"))
		 (when (and emit-debug-info dbi)
		   (gen #t "C_debugger(&(C_debug_info[" dbi "]),"
			(if non-av-proc "0,NULL" "c,av") ");")))
	       (cond ((eq? '##core#proc (node-class fn))
		      (gen #\{)
		      (push-args args i "0")
		      (let ([fpars (node-parameters fn)])
			(gen #t (first fpars) #\( nf ",av2);}") ))
		     (call-id
		      (cond ((and (eq? call-id (lambda-literal-id ll))
				  (lambda-literal-looping ll) )
			     (let* ((temps (lambda-literal-temporaries ll))
				    (ts (list-tabulate n (lambda (i) (+ temps nf i)))))
			       (for-each
				(lambda (arg tr)
				  (gen #t #\t tr #\=)
				  (expr arg i) 
				  (gen #\;) )
				args ts)
			       (for-each
				(lambda (from to) (gen #t #\t to "=t" from #\;))
				ts (list-tabulate n add1))
			       (unless customizable (gen #t "c=" nf #\;))
			       (gen #t "goto loop;") ) )
			    (else
			     (unless empty-closure
			       (gen #t #\t nc #\=)
			       (expr fn i)
			       (gen #\;) )
			     (cond (customizable
				    (gen #t call-id #\()
				    (unless empty-closure (gen #\t nc #\,))
				    (expr-args args i)
				    (gen ");") )
				   (else
				    (gen #\{)
				    (push-args args i (and (not empty-closure) (string-append "t" (number->string nc))))
				    (gen #t call-id #\()
				    (unless customizable (gen nf #\,))
				    (gen "av2);}") ) ) )))
		     ((and (eq? '##core#global (node-class fn))
			   (not unsafe) 
			   (not no-procedure-checks)
			   (not safe-to-call))
		      (let* ((gparams (node-parameters fn))
			     (index (first gparams))
			     (safe (second gparams)) 
			     (block (third gparams)) 
			     (carg #f))
			(gen #t "{C_proc tp=(C_proc)")
			(cond (no-global-procedure-checks
			       (set! carg
				 (if block
				     (string-append "lf[" (number->string index) "]")
				     (string-append "*((C_word*)lf[" (number->string index) "]+1)")))
			       (gen "(void*)(*((C_word*)(" carg ")+1))"))
			      (block
			       (set! carg (string-append "lf[" (number->string index) "]"))
			       (if safe
				   (gen "C_fast_retrieve_proc(" carg ")")
				   (gen "C_retrieve2_symbol_proc(" carg ",C_text("
					(c-ify-string (##sys#symbol->string (fourth gparams))) "))")))
			      (safe
			       (set! carg 
				 (string-append "*((C_word*)lf[" (number->string index) "]+1)"))
			       (gen "C_fast_retrieve_proc(" carg ")"))
			      (else
			       (set! carg 
				 (string-append "*((C_word*)lf[" (number->string index) "]+1)"))
			       (gen "C_fast_retrieve_symbol_proc(lf[" index "])") ))
			(gen #\;)
			(push-args args i carg)
			(gen #t "tp(" nf ",av2);}")))
		     (else
		      (gen #t #\t nc #\=)
		      (expr fn i)
		      (gen ";{")
		      (push-args args i (string-append "t" (number->string nc)))
		      (gen #t "((C_proc)")
		      (if (or unsafe no-procedure-checks safe-to-call)
			  (gen "(void*)(*((C_word*)t" nc "+1))")
			  (gen "C_fast_retrieve_proc(t" nc ")") )
		      (gen ")(" nf ",av2);}") ) ) ) )
	  
	    ((##core#recurse) 
	     (let* ([n (length subs)]
		    [nf (add1 n)]
		    [tailcall (first params)]
		    [call-id (second params)] 
		    [empty-closure (zero? (lambda-literal-closure-size ll))] )
	       (cond (tailcall
		      (let* ((temps (lambda-literal-temporaries ll))
			     (ts (list-tabulate n (cut + temps nf <>))))
			(for-each
			 (lambda (arg tr)
			   (gen #t #\t tr #\=)
			   (expr arg i) 
			   (gen #\;) )
			 subs ts)
			(for-each
			 (lambda (from to) (gen #t #\t to "=t" from #\;))
			 ts (list-tabulate n add1))
			(gen #t "goto loop;") ) )
		     (else
		      (gen call-id #\()
		      (unless empty-closure (gen "t0,"))
		      (expr-args subs i)
		      (gen #\)) ) ) ) )

	    ((##core#direct_call) 
	     (let* ((args (cdr subs))
		    (n (length args))
		    (nf (add1 n))
		    (dbi (first params))
		    ;; (safe-to-call (second params))
		    (name (third params))
		    (name-str (source-info->string name))
		    (call-id (fourth params))
		    (demand (fifth params))
		    (allocating (not (zero? demand)))
		    (empty-closure (zero? (lambda-literal-closure-size (find-lambda call-id))))
		    (fn (car subs)) )
	       (gen #\()
	       (when name
		 (if emit-trace-info
		     (gen #t "C_trace(\"" (backslashify name-str) "\"),")
		     (gen #t "/* " (uncommentify name-str) " */"))
		 (when (and emit-debug-info dbi)
		   (gen #t "C_debugger(&(C_debug_info[" dbi "]),"
			(if non-av-proc "0,NULL" "c,av") "),")))
	       (gen #t "  " call-id #\()
	       (when allocating 
		 (gen "C_a_i(&a," demand #\))
		 (when (or (not empty-closure) (pair? args)) (gen #\,)) )
	       (unless empty-closure
		 (expr fn i)
		 (when (pair? args) (gen #\,)) )
	       (when (pair? args) (expr-args args i))
	       (gen #\))		; function call
	       (gen #t #\))))		; complete expression

	    ((##core#provide)
	     (gen "C_a_i_provide(&a,1,lf[" (first params) "])"))

	    ((##core#callunit)
	     ;; The code generated here does not use the extra temporary needed for standard calls, so we have
	     ;;  one unused variable:
	     (let* ((n (length subs))
		    (nf (+ n 1)) )
	       (gen #\{)
	       (push-args subs i "C_SCHEME_UNDEFINED")
	       (gen #t "C_" (toplevel (first params)) "(" nf ",av2);}")))

	    ((##core#return)
	     (gen #t "return(")
	     (expr (first subs) i)
	     (gen ");") )

	    ((##core#inline)
	     (gen (first params) #\()
	     (expr-args subs i)
	     (gen #\)) )

	    ((##core#debug-event)
	     (gen "C_debugger(&(C_debug_info[" (first params) "]),"
		  (if non-av-proc "0,NULL" "c,av") ")"))

	    ((##core#inline_allocate)
	     (gen (first params) "(&a," (length subs))
	     (if (pair? subs)
		 (begin
		   (gen #\,)
		   (expr-args subs i) ) )
	     (gen #\)) )

	    ((##core#inline_ref)
	     (gen (foreign-result-conversion (second params) "a") (first params) #\)) )

	    ((##core#inline_update)
	     (let ([t (second params)])
	       (gen #\( (first params) "=(" (foreign-type-declaration t "") #\) (foreign-argument-conversion t)) 
	       (expr (first subs) i)
	       (gen "),C_SCHEME_UNDEFINED)") ) )

	    ((##core#inline_loc_ref)
	     (let ([t (first params)])
	       (gen (foreign-result-conversion t "a") "*((" (foreign-type-declaration t "") "*)C_data_pointer(")
	       (expr (first subs) i)
	       (gen ")))") ) )

	    ((##core#inline_loc_update)
	     (let ([t (first params)])
	       (gen "((*(" (foreign-type-declaration t "") "*)C_data_pointer(")
	       (expr (first subs) i)
	       (gen "))=" (foreign-argument-conversion t))
	       (expr (second subs) i) 
	       (gen "),C_SCHEME_UNDEFINED)") ) )

	    ((##core#switch)
	     (gen #t "switch(")
	     (expr (first subs) i)
	     (gen "){")
	     (do ([j (first params) (sub1 j)]
		  [ps (cdr subs) (cddr ps)] )
		 ((zero? j)
		  (gen #t "default:")
		  (expr (car ps) i)
		  (gen #\}) )
	       (gen #t "case ")
	       (expr (car ps) i)
	       (gen #\:)
	       (expr (cadr ps) i) ) )

	    ((##core#cond)
	     (gen "(C_truep(")
	     (expr (first subs) i)
	     (gen ")?")
	     (expr (second subs) i)
	     (gen #\:)
	     (expr (third subs) i)
	     (gen #\)) )

	    (else (bomb "bad form" (node-class n))) ) ) )
    
      (define (expr-args args i)
	(let loop ((xs args))
	  (unless (null? xs)
	    (unless (eq? xs args) (gen #\,))
	    (expr (car xs) i)
	    (loop (cdr xs)))))

      (define (contains-restop? args)
	(let loop ((args args))
	  (if (null? args)
	      #f
	      (let ((node (car args)))
		;; Only rest-car accesses av
		(or (eq? (node-class node) '##core#rest-car)
		    (contains-restop? (node-subexpressions node))
		    (loop (cdr args)))))))

      (define (push-args args i selfarg)
	(let* ((n (length args))
	       (avl (+ n (if selfarg 1 0)))
	       (caller-has-av? (not (or (lambda-literal-customizable ll)
					(lambda-literal-direct ll))))
	       (caller-argcount (lambda-literal-argument-count ll))
	       (caller-rest-mode (lambda-literal-rest-argument-mode ll)))
	  ;; Try to re-use argvector from current function if it is
	  ;; large enough.  push-args gets used only for functions in
	  ;; CPS context, so callee never returns to current function.
	  ;; And even so, av[] is already copied into temporaries.
	  (cond
	   ((or (not caller-has-av?)	     ; Argvec missing or
		(and (< caller-argcount avl) ; known to be too small?
		     (eq? caller-rest-mode 'none))
		(contains-restop? args))     ; Restops work on original av
	    (gen #t "C_word av2[" avl "];"))
	   ((>= caller-argcount avl)   ; Argvec known to be re-usable?
	    (gen #t "C_word *av2=av;")) ; Re-use our own argvector
	   (else      ; Need to determine dynamically. This is slower.
	    (gen #t "C_word *av2;")
	    (gen #t "if(c >= " avl ") {")
	    (gen #t "  av2=av;") ; Re-use our own argvector
	    (gen #t "} else {")
	    (gen #t "  av2=C_alloc(" avl ");")
	    (gen #t "}")))
	  (when selfarg (gen #t "av2[0]=" selfarg ";"))
	  (do ((j (if selfarg 1 0) (add1 j))
	       (args args (cdr args)))
	      ((null? args))
	    (gen #t "av2[" j "]=")
	    (expr (car args) i)
	    (gen ";"))))

      (expr node temps) )
 
    (define (header)
      (gen "/* Generated from " source-file " by the CHICKEN compiler" #t
	   "   http://www.call-cc.org" #t
	   (string-intersperse
	    (map (cut string-append "   " <> "\n")
		 (string-split (chicken-version #t) "\n") )
	    "")
	   "   command line: ")
      (gen-list user-supplied-options)
      (unless (not unit-name)
	(gen #t "   unit: " unit-name))
      (unless (null? used-units)
	(gen #t "   uses: ")
	(gen-list used-units))
      (gen #t "*/")
      (gen #t "#include \"" target-include-file "\"")
      (when external-protos-first
	(generate-foreign-callback-stub-prototypes foreign-callback-stubs) )
      (when (pair? foreign-declarations)
	(gen #t)
	(for-each (lambda (decl) (gen #t decl)) foreign-declarations) )
      (unless external-protos-first
	(generate-foreign-callback-stub-prototypes foreign-callback-stubs) ) )

    (define (trailer)
      (gen #t #t "/*" #t 
	   (uncommentify
	    (get-output-string
	     collected-debugging-output))
	   "*/"
	   #t "/* end of file */" #t))
  
    (define (declarations)
      (let ((n (length literals)))
	(gen #t #t "static C_PTABLE_ENTRY *create_ptable(void);")
	(for-each
	 (lambda (uu)
	   (gen #t "C_noret_decl(C_" uu ")"
		#t "C_externimport void C_ccall C_" uu "(C_word c,C_word *av) C_noret;"))
	 (map toplevel used-units))
	(unless (zero? n)
	  (gen #t #t "static C_TLS C_word lf[" n "];") )
	(gen #t "static double C_possibly_force_alignment;")
	(do ((i 0 (add1 i))
	     (llits lliterals (cdr llits)))
	    ((null? llits))
	  (let* ((ll (##sys#lambda-info->string (car llits)))
		 (llen (string-length ll)))
	    (gen #t "static C_char C_TLS li" i "[] C_aligned={C_lihdr(" 
		 (arithmetic-shift llen -16) #\,
		 (bitwise-and #xff (arithmetic-shift llen -8)) #\,
		 (bitwise-and #xff llen)
		 #\))
	    (do ((n 0 (add1 n)))
		((>= n llen))
	      (gen #\, (char->integer (string-ref ll n))) )
	    (do ((n (- (bitwise-and #xfffff8 (+ llen 7)) llen) (sub1 n))) ; fill up with zeros to align following entry
		((zero? n))
	      (gen ",0") )
	    (gen "};")))))
  
    (define (prototypes)
      (gen #t)
      (for-each
       (lambda (p)
	 (let* ((id (car p))
		(ll (cdr p))
		(n (lambda-literal-argument-count ll))
		(customizable (lambda-literal-customizable ll))
		(empty-closure (and customizable (zero? (lambda-literal-closure-size ll))))
		(varlist (intersperse (make-variable-list (if empty-closure (sub1 n) n) "t") #\,))
		(direct (lambda-literal-direct ll))
		(allocated (lambda-literal-allocated ll)) )
	   (gen #t)
	   (cond ((not (eq? 'toplevel id))
		  (gen "C_noret_decl(" id ")" #t)
		  (gen "static ")
		  (gen (if direct "C_word " "void "))
		  (if customizable
		      (gen "C_fcall ")
		      (gen "C_ccall ") )
		  (gen id) )
		 (else
		  (let ((uname (toplevel unit-name)))
		    (gen "C_noret_decl(C_" uname ")" #t) ;XXX what's this for?
		    (gen "C_externexport void C_ccall ")
		    (gen "C_" uname) ) ) )
	   (gen #\()
	   (unless customizable (gen "C_word c,"))
	   (when (and direct (not (zero? allocated)))
	     (gen "C_word *a")
	     (when (pair? varlist) (gen #\,)) )
	   (if (or customizable direct)
	       (apply gen varlist)
	       (gen "C_word *av"))
	   (gen #\))
	   (unless direct (gen " C_noret"))
	   (gen #\;) ))
       lambda-table*) )
  
    (define (trampolines)
      (let ([ns '()]
	    [nsr '()] 
	    [nsrv '()] )

	(define (restore n)
	  (do ((i 0 (add1 i))
	       (j (sub1 n) (sub1 j)))
	      ((>= i n))
	    (gen #t "C_word t" i "=av[" j "];")))

	(for-each
	 (lambda (p)
	   (let* ([id (car p)]
		  [ll (cdr p)]
		  [argc (lambda-literal-argument-count ll)]
		  [customizable (lambda-literal-customizable ll)]
		  [empty-closure (and customizable (zero? (lambda-literal-closure-size ll)))] )
	     (when empty-closure (set! argc (sub1 argc)))
	     (when (and (not (lambda-literal-direct ll)) customizable)
	       (gen #t #t "C_noret_decl(tr" id ")"
		    #t "static void C_ccall tr" id "(C_word c,C_word *av) C_noret;")
	       (gen #t "static void C_ccall tr" id "(C_word c,C_word *av){")
	       (restore argc)
	       (gen #t id #\()
	       (let ([al (make-argument-list argc "t")])
		 (apply gen (intersperse al #\,)) )
	       (gen ");}") )))
	 lambda-table*)))
  
    (define (literal-frame)
      (do ([i 0 (add1 i)]
	   [lits literals (cdr lits)] )
	  ((null? lits))
	(gen-lit (car lits) (sprintf "lf[~s]" i)) ) )

    (define (bad-literal lit)
      (bomb "type of literal not supported" lit) )

    (define (literal-size lit)
      (cond ((immediate? lit) 0)
	    ((big-fixnum? lit) 2)       ; immediate if fixnum, bignum see below
	    ((string? lit) 0)		; statically allocated
	    ((bignum? lit) 2)		; internal vector statically allocated
	    ((flonum? lit) words-per-flonum)
	    ((symbol? lit) 7)           ; size of symbol, and possibly a bucket
	    ((keyword? lit) 7)          ; size of keyword (symbol), and possibly a bucket
	    ((pair? lit) (+ 3 (literal-size (car lit)) (literal-size (cdr lit))))
	    ((vector? lit)
	     (+ 1 (vector-length lit)
                (foldl + 0 (map literal-size (vector->list lit)))))
	    ((block-variable-literal? lit) 0) ; excluded from generated code
	    ((##sys#immediate? lit) (bad-literal lit))
	    ((##core#inline "C_lambdainfop" lit) 0) ; statically allocated
	    ((##sys#bytevector? lit) (+ 2 (bytes->words (##sys#size lit))) ) ; drops "permanent" property!
	    ((##sys#generic-structure? lit)
	     (let ([n (##sys#size lit)])
	       (let loop ([i 0] [s (+ 2 n)])
		 (if (>= i n)
		     s
		     (loop (add1 i) (+ s (literal-size (##sys#slot lit i)))) ) ) ) )
	    ;; We could access rat/cplx slots directly, but let's not.
	    ((ratnum? lit) (+ (##sys#size lit)
			      (literal-size (numerator lit))
			      (literal-size (denominator lit))))
	    ((cplxnum? lit) (+ (##sys#size lit)
			       (literal-size (real-part lit))
			       (literal-size (imag-part lit))))
	    (else (bad-literal lit))) )

    (define (gen-lit lit to)
      ;; we do simple immediate literals directly to avoid a function call:
      (cond ((and (fixnum? lit) (not (big-fixnum? lit)))
	     (gen #t to "=C_fix(" lit ");") )
	    ((block-variable-literal? lit))
	    ((eq? lit (void))
	     (gen #t to "=C_SCHEME_UNDEFINED;") )
	    ((boolean? lit) 
	     (gen #t to #\= (if lit "C_SCHEME_TRUE" "C_SCHEME_FALSE") #\;) )
	    ((char? lit)
	     (gen #t to "=C_make_character(" (char->integer lit) ");") )
	    ((or (keyword? lit) (symbol? lit)) ; handled slightly specially (see C_h_intern_in)
	     (let* ((str (##sys#slot lit 1))
		    (cstr (c-ify-string str))
		    (len (##sys#size str))
		    (intern (if (keyword? lit)
				"C_h_intern_kw"
				"C_h_intern")))
	       (gen #t to "=")
	       (gen intern "(&" to #\, len ", C_text(" cstr "));")))
	    ((null? lit) 
	     (gen #t to "=C_SCHEME_END_OF_LIST;") )
	    ((and (not (##sys#immediate? lit)) ; nop
		  (##core#inline "C_lambdainfop" lit)))
	    ((or (fixnum? lit) (not (##sys#immediate? lit)))
	     (gen #t to "=C_decode_literal(C_heaptop,C_text(")
	     (gen-string-constant (encode-literal lit))
	     (gen "));"))
	    (else (bad-literal lit))))

    (define (gen-string-constant str)
      (let* ([len (##sys#size str)]
	     [ns (fx/ len 80)]
	     [srest (modulo len 80)] )
	(do ([i ns (sub1 i)]
	     [offset 0 (+ offset 80)] )
	    ((zero? i)
	     (when (or (zero? len) (not (zero? srest)))
	       (gen (c-ify-string (string-like-substring str offset len))) ) )
	  (gen (c-ify-string (string-like-substring str offset (+ offset 80))) #t) ) ) )
 
    (define (string-like-substring s start end)
      (let* ([len (- end start)]
	     [s2 (make-string len)] )
	(##sys#copy-bytes s s2 start 0 len)
	s2) )

    (define (procedures)
      (for-each
       (lambda (p)
	 (let* ((id (car p))
		(ll (cdr p))
		(n (lambda-literal-argument-count ll))
		(rname (real-name id db))
		(demand (lambda-literal-allocated ll))
		(max-av (apply max 0 (lambda-literal-callee-signatures ll)))
		(rest (lambda-literal-rest-argument ll))
		(customizable (lambda-literal-customizable ll))
		(empty-closure (and customizable (zero? (lambda-literal-closure-size ll))))
		(nec (- n (if empty-closure 1 0)))
		(vlist0 (make-variable-list n "t"))
		(alist0 (make-argument-list n "t"))
		(varlist (intersperse (if empty-closure (cdr vlist0) vlist0) #\,))
		(arglist (intersperse (if empty-closure (cdr alist0) alist0) #\,))
		(external (lambda-literal-external ll))
		(looping (lambda-literal-looping ll))
		(direct (lambda-literal-direct ll))
		(rest-mode (lambda-literal-rest-argument-mode ll))
		(temps (lambda-literal-temporaries ll))
                (ftemps (lambda-literal-float-temporaries ll))
		(topname (toplevel unit-name)))
	   (when empty-closure (debugging 'o "dropping unused closure argument" id))
	   (gen #t #t)
	   (gen "/* " (cleanup rname) " */" #t)
	   (cond [(not (eq? 'toplevel id)) 
		  (gen "static ")
		  (gen (if direct "C_word " "void "))
		  (if customizable
		      (gen "C_fcall ")
		      (gen "C_ccall ") )
		  (gen id) ]
		 [else
		  (gen "static C_TLS int toplevel_initialized=0;")
		  (unless unit-name
		    (gen #t "C_main_entry_point") )
		  (gen #t #t "void C_ccall C_" topname) ] )
	   (gen #\()
	   (unless customizable (gen "C_word c,"))
	   (when (and direct (not (zero? demand))) 
	     (gen "C_word *a")
	     (when (pair? varlist) (gen #\,)) )
	   (if (or customizable direct)
	       (apply gen varlist)
	       (gen "C_word *av"))
	   (gen "){")
	   (when (eq? rest-mode 'none) (set! rest #f))
	   (gen #t "C_word tmp;")
	   (unless (or customizable direct)
	     (do ((i 0 (add1 i)))
		 ((>= i n))
	       (gen #t "C_word t" i "=av[" i "];")))
	   (if rest
	       (gen #t "C_word t" n #\;) ; To hold rest-list if demand is met
	       (begin
		 (do ([i n (add1 i)]
		      [j (+ temps (if looping (sub1 n) 0)) (sub1 j)] )
		     ((zero? j))
		   (gen #t "C_word t" i #\;))
                 (for-each
                   (lambda (i)
                     (gen #t "double f" i #\;))
                   ftemps)))
	   (cond ((eq? 'toplevel id)
		  (let ([ldemand (foldl (lambda (n lit) (+ n (literal-size lit))) 0 literals)]
			[llen (length literals)] )
		    (gen #t "C_word *a;"
			 #t "if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}"
			 #t "else C_toplevel_entry(C_text(\"" (or unit-name topname) "\"));")
		    (when emit-debug-info
		      (gen #t "C_register_debug_info(C_debug_info);"))
		    (when disable-stack-overflow-checking
		      (gen #t "C_disable_overflow_check=1;") )
		    (unless unit-name
		      (when target-heap-size
			(gen #t "C_set_or_change_heap_size(" target-heap-size ",1);"
			     #t "C_heap_size_is_fixed=1;"))
		      (when target-stack-size
			(gen #t "C_resize_stack(" target-stack-size ");") ) )
		    (gen #t "C_check_nursery_minimum(C_calculate_demand(" demand ",c," max-av "));"
			 #t "if(C_unlikely(!C_demand(C_calculate_demand(" demand ",c," max-av ")))){"
			 #t "C_save_and_reclaim((void*)C_" topname ",c,av);}"
			 #t "toplevel_initialized=1;"
			 #t "if(C_unlikely(!C_demand_2(" ldemand "))){"
			 #t "C_save(t1);"
			 #t "C_rereclaim2(" ldemand "*sizeof(C_word),1);"
			 #t "t1=C_restore;}"
			 #t "a=C_alloc(" demand ");")
		    (when (not (zero? llen))
		      (gen #t "C_initialize_lf(lf," llen ");")
		      (literal-frame)
		      (gen #t "C_register_lf2(lf," llen ",create_ptable());"))
		    (gen #\{)))
		 (rest
		  (gen #t "C_word *a;")
		  (when (and (not unsafe) (not no-argc-checks) (> n 2) (not empty-closure))
		    (gen #t "if(c<" n ") C_bad_min_argc_2(c," n ",t0);") )
		  (when insert-timer-checks (gen #t "C_check_for_interrupt;"))
		  (gen #t "if(C_unlikely(!C_demand(C_calculate_demand((c-" n ")*C_SIZEOF_PAIR +" demand ",c," max-av ")))){"))
		 (else
		  (unless direct (gen #t "C_word *a;"))
		  (when (and direct (not unsafe) (not disable-stack-overflow-checking))
		    (gen #t "C_stack_overflow_check;"))
		  (when looping (gen #t "loop:"))
		  (when (and external (not unsafe) (not no-argc-checks) (not customizable))
		    ;; (not customizable) implies empty-closure
		    (if (eq? rest-mode 'none)
			(when (> n 2) (gen #t "if(c<" n ") C_bad_min_argc_2(c," n ",t0);"))
			(gen #t "if(c!=" n ") C_bad_argc_2(c," n ",t0);") ) )
		  (cond ((not direct)
			 ;; The interrupt handler may fill the stack, so we only
			 ;; check for an interrupt when the procedure is restartable
			 (when insert-timer-checks (gen #t "C_check_for_interrupt;"))
			 (gen #t "if(C_unlikely(!C_demand(C_calculate_demand("
			      demand
			      (if customizable ",0," ",c,")
			      max-av ")))){"))
			(else
			 (gen #\{)))))
	   (cond ((and (not (eq? 'toplevel id)) (not direct))
		  (when (and looping (not customizable))
		    ;; Loop will update t_n copy of av[n]; refresh av.
		    (do ((i 0 (add1 i)))
			((>= i n))
		      (gen #t "av[" i "]=t" i ";")))
		  (cond (rest
			 (gen #t "C_save_and_reclaim((void*)" id ",c,av);}"
			      #t "a=C_alloc((c-" n ")*C_SIZEOF_PAIR+" demand ");")
			 (gen #t "t" n "=C_build_rest(&a,c," n ",av);")
			 (do ((i (+ n 1) (+ i 1))
			      (j temps (- j 1)))
			     ((zero? j))
			   (gen #t "C_word t" i #\;)))
			(else
			 (cond ((and customizable (> nec 0))
				(gen #t "C_save_and_reclaim_args((void *)tr" id #\, nec #\,)
				(apply gen arglist)
				(gen ");}"))
			       (else
				(gen #t "C_save_and_reclaim((void *)" id ",c,av);}")))
			 (when (> demand 0)
			   (gen #t "a=C_alloc(" demand ");")))))
		 (else (gen #\})))
           (set! non-av-proc customizable)
	   (expression
	    (lambda-literal-body ll)
	    (if rest
		(add1 n) ; One temporary is needed to hold the rest-list
		n)
	    ll)
	   (gen #\}) ) )
       lambda-table*) )

    (debugging 'p "code generation phase...")
    (set! output out)
    (header)
    (declarations)
    (generate-external-variables external-variables)
    (generate-foreign-stubs foreign-lambda-stubs db)
    (prototypes)
    (generate-foreign-callback-stubs foreign-callback-stubs db)
    (trampolines)
    (when emit-debug-info
      (emit-debug-table dbg-info-table))
    (procedures)
    (emit-procedure-table lambda-table* source-file)
    (trailer) ) )


;;; Emit global tables for debug-info

(define (emit-debug-table dbg-info-table)
  (gen #t #t "static C_DEBUG_INFO C_debug_info[]={")
  (for-each
   (lambda (info)
     (gen #t "{" (second info) ",0,")
     (for-each
      (lambda (x)
	(if (not x)
	    (gen "NULL,")
	    (gen "C_text(\"" (backslashify (->string x)) "\"),")))
      (cddr info))
     (gen "},"))
   (sort dbg-info-table (lambda (i1 i2) (< (car i1) (car i2)))))
  (gen #t "{0,0,NULL,NULL}};\n"))


;;; Emit procedure table:

(define (emit-procedure-table lambda-table* sf)
  (gen #t #t "#ifdef C_ENABLE_PTABLES"
       #t "static C_PTABLE_ENTRY ptable[" (add1 (length lambda-table*)) "] = {")
  (for-each
   (lambda (p)
     (let ((id (car p))
	   (ll (cdr p)))
       (gen #t "{C_text(\"" id #\: (string->c-identifier sf) "\"),(void*)")
       (if (eq? 'toplevel id)
	   (gen "C_" (toplevel unit-name) "},")
	   (gen id "},") ) ) )
    lambda-table*)
  (gen #t "{NULL,NULL}};")
  (gen #t "#endif")
  (gen #t #t "static C_PTABLE_ENTRY *create_ptable(void)")
  (gen "{" #t "#ifdef C_ENABLE_PTABLES"
       #t "return ptable;"
       #t "#else"
       #t "return NULL;"
       #t "#endif"
       #t "}") )


;;; Generate top-level procedure name:

(define (toplevel name)
  (if (not name)
      "toplevel"
      (string-append (c-identifier name) "_toplevel")))


;;; Create name that is safe for C comments:

(define (cleanup s)
  (let ([s2 #f] 
	[len (string-length s)] )
    (let loop ([i 0])
      (if (>= i len)
	  (or s2 s)
	  (let ([c (string-ref s i)])
	    (if (or (char<? c #\space)
		    (char>? c #\~)
		    (and (char=? c #\*) (< i (sub1 len)) (char=? #\/ (string-ref s (add1 i)))) )
		(begin
		  (unless s2 (set! s2 (string-copy s)))
		  (string-set! s2 i #\~) )
		(when s2 (string-set! s2 i c)) ) 
	    (loop (add1 i)) ) ) ) ) )


;;; Create list of variables/parameters, interspersed with a special token:

(define (make-variable-list n prefix)
  (list-tabulate
   n
   (lambda (i) (string-append "C_word " prefix (number->string i))) ) )
  
(define (make-argument-list n prefix)
  (list-tabulate
   n
   (lambda (i) (string-append prefix (number->string i))) ) )


;;; Generate external variable declarations:

(define (generate-external-variables vars)
  (gen #t)
  (for-each
   (lambda (v)
     (let ((name (vector-ref v 0))
	   (type (vector-ref v 1))
	   (exported (vector-ref v 2)) )
       (gen #t (if exported "" "static ") (foreign-type-declaration type name) #\;) ) )
   vars) )


;;; Generate foreign stubs:

(define (generate-foreign-callback-stub-prototypes stubs)
  (for-each
   (lambda (stub)
     (gen #t)
     (generate-foreign-callback-header "C_externexport " stub)
     (gen #\;) )
   stubs) )

(define (generate-foreign-stubs stubs db)
  (for-each
   (lambda (stub)
     (let* ([id (foreign-stub-id stub)]
	    [rname (real-name2 id db)]
	    [types (foreign-stub-argument-types stub)]
	    [n (length types)]
	    [rtype (foreign-stub-return-type stub)] 
	    [sname (foreign-stub-name stub)] 
	    [body (foreign-stub-body stub)]
	    [names (or (foreign-stub-argument-names stub) (make-list n #f))]
	    [rconv (foreign-result-conversion rtype "C_a")] 
	    [cps (foreign-stub-cps stub)]
	    [callback (foreign-stub-callback stub)] )
       (gen #t)
       (when rname
	 (gen #t "/* from " (cleanup rname) " */") )
       (when body
	 (gen #t "#define return(x) C_cblock C_r = (" rconv 
	      "(x))); goto C_ret; C_cblockend"))
       (cond (cps
	      (gen #t "C_noret_decl(" id ")"
		   #t "static void C_ccall " id "(C_word C_c,C_word *C_av){"
		   #t "C_word C_k=C_av[1],C_buf=C_av[2];")
	      (do ((i 0 (add1 i)))
		  ((>= i n))
		(gen #t "C_word C_a" i "=C_av[" (+ i 3) "];")))
	     (else
	      (gen #t "C_regparm static C_word C_fcall " id #\()
	      (apply gen (intersperse (cons "C_word C_buf" (make-variable-list n "C_a")) #\,))
	      (gen "){")))
       (gen #t "C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;")
       (for-each
	(lambda (type index name)
	  (gen #t 
	       (foreign-type-declaration 
		type
		(if name (symbol->string name) (sprintf "t~a" index)) )
	       "=(" (foreign-type-declaration type "") #\)
	       (foreign-argument-conversion type) "C_a" index ");") )
	types (iota n) names)
       (when callback (gen #t "int C_level=C_save_callback_continuation(&C_a,C_k);"))
       (cond [body
	      (gen #t body
		   #t "C_ret:")
	      (gen #t "#undef return" #t)
	      (cond [callback
		     (gen #t "C_k=C_restore_callback_continuation2(C_level);"
			  #t "C_kontinue(C_k,C_r);") ]
		    [cps (gen #t "C_kontinue(C_k,C_r);")]
		    [else (gen #t "return C_r;")] ) ]
	     [else
	      (if (not (eq? rtype 'void))
		  (gen #t "C_r=" rconv)
		  (gen #t) )
	      (gen sname #\()
	      (apply gen (intersperse (make-argument-list n "t") #\,))
	      (unless (eq? rtype 'void) (gen #\)))
	      (gen ");")
	      (cond [callback
		     (gen #t "C_k=C_restore_callback_continuation2(C_level);"
			  #t "C_kontinue(C_k,C_r);") ]
		    [cps (gen "C_kontinue(C_k,C_r);")]
		    [else (gen #t "return C_r;")] ) ] )
       (gen #\}) ) )
   stubs) )

(define (generate-foreign-callback-stubs stubs db)
  (for-each
   (lambda (stub)
     (let* ((id (foreign-callback-stub-id stub))
	    (rname (real-name2 id db))
	    (rtype (foreign-callback-stub-return-type stub))
	    (argtypes (foreign-callback-stub-argument-types stub))
	    (n (length argtypes))
	    (vlist (make-argument-list n "t")) )

       (define (compute-size type var ns)
	 (case type
	   ((char int int32 short bool void unsigned-short scheme-object unsigned-char unsigned-int unsigned-int32
		  byte unsigned-byte)
	    ns)
	   ((float double c-pointer nonnull-c-pointer
		   c-string-list c-string-list*)
	    (string-append ns "+3") )
	   ((unsigned-integer unsigned-integer32 long integer integer32 
			      unsigned-long number)
	    (string-append ns "+C_SIZEOF_FIX_BIGNUM"))
	   ((unsigned-integer64 integer64 size_t ssize_t)
	    ;; On 32-bit systems, needs 2 digits
	    (string-append ns "+C_SIZEOF_BIGNUM(2)"))
	   ((c-string c-string* unsigned-c-string unsigned-c-string unsigned-c-string*)
	    (string-append ns "+2+(" var "==NULL?1:C_bytestowords(C_strlen(" var ")))") )
	   ((nonnull-c-string nonnull-c-string* nonnull-unsigned-c-string nonnull-unsigned-c-string* symbol)
	    (string-append ns "+2+C_bytestowords(C_strlen(" var "))") )
	   (else
	    (cond ((and (symbol? type) (lookup-foreign-type type)) 
		   => (lambda (t) (compute-size (vector-ref t 0) var ns) ) )
		  ((pair? type)
		   (case (car type)
		     ((ref pointer c-pointer nonnull-pointer nonnull-c-pointer function instance 
			   nonnull-instance instance-ref)
		      (string-append ns "+3") )
		     ((const) (compute-size (cadr type) var ns))
		     (else ns) ) )
		  (else ns) ) ) ) )

       (let ((sizestr (let loop ((types argtypes) (vars vlist) (ns "0"))
			(if (null? types)
			    ns
			    (loop (cdr types) (cdr vars) 
				  (compute-size (car types) (car vars) ns))))))
	 (gen #t)
	 (when rname
	   (gen #t "/* from " (cleanup rname) " */") )
	 (generate-foreign-callback-header "" stub)
	 (gen #\{ #t "C_word x,s=" sizestr ",*a="
	      (if (string=? "0" sizestr) "C_stack_pointer;" "C_alloc(s);"))
	 (gen #t "C_callback_adjust_stack(a,s);") ; make sure content is below stack_bottom as well
	 (for-each
	  (lambda (v t)
	    (gen #t "x=" (foreign-result-conversion t "a") v ");"
		 #t "C_save(x);") )
	  (reverse vlist)
	  (reverse argtypes))
	 (unless (eq? 'void rtype)
	   (gen #t "return " (foreign-argument-conversion rtype)) )
	 (gen "C_callback_wrapper((void *)" id #\, n #\))
	 (unless (eq? 'void rtype) (gen #\)))
	 (gen ";}") ) ) )
   stubs) )

(define (generate-foreign-callback-header cls stub)
  (let* ((name (foreign-callback-stub-name stub))
	 (quals (foreign-callback-stub-qualifiers stub))
	 (rtype (foreign-callback-stub-return-type stub))
	 (argtypes (foreign-callback-stub-argument-types stub))
	 (n (length argtypes))
	 (vlist (make-argument-list n "t")) )
    (gen #t cls #\space (foreign-type-declaration rtype "") quals #\space name #\()
    (let loop ((vs vlist) (ts argtypes))
      (unless (null? vs)
	(gen (foreign-type-declaration (car ts) (car vs)))
	(when (pair? (cdr vs)) (gen #\,))
	(loop (cdr vs) (cdr ts))))
    (gen #\)) ) )


;; Create type declarations

(define (foreign-type-declaration type target)
  (let ((err (lambda () (quit-compiling "illegal foreign type `~A'" type)))
	(str (lambda (ts) (string-append ts " " target))) )
    (case type
      ((scheme-object) (str "C_word"))
      ((char byte) (str "C_char"))
      ((unsigned-char unsigned-byte) (str "unsigned C_char"))
      ((unsigned-int unsigned-integer) (str "unsigned int"))
      ((unsigned-int32 unsigned-integer32) (str "C_u32"))
      ((int integer bool) (str "int"))
      ((size_t) (str "size_t"))
      ((ssize_t) (str "ssize_t"))
      ((int32 integer32) (str "C_s32"))
      ((integer64) (str "C_s64"))
      ((unsigned-integer64) (str "C_u64"))
      ((short) (str "short"))
      ((long) (str "long"))
      ((unsigned-short) (str "unsigned short"))
      ((unsigned-long) (str "unsigned long"))
      ((float) (str "float"))
      ((double number) (str "double"))
      ((c-pointer nonnull-c-pointer scheme-pointer nonnull-scheme-pointer) (str "void *"))
      ((c-string-list c-string-list*) "C_char **")
      ((blob nonnull-blob u8vector nonnull-u8vector) (str "unsigned char *"))
      ((u16vector nonnull-u16vector) (str "unsigned short *"))
      ((s8vector nonnull-s8vector) (str "signed char *"))
      ((u32vector nonnull-u32vector) (str "unsigned int *")) ;; C_u32?
      ((u64vector nonnull-u64vector) (str "C_u64 *"))
      ((s16vector nonnull-s16vector) (str "short *"))
      ((s32vector nonnull-s32vector) (str "int *")) ;; C_s32?
      ((s64vector nonnull-s64vector) (str "C_s64 *"))
      ((f32vector nonnull-f32vector) (str "float *"))
      ((f64vector nonnull-f64vector) (str "double *"))
      ((pointer-vector nonnull-pointer-vector) (str "void **"))
      ((nonnull-c-string c-string nonnull-c-string* c-string* symbol) 
       (str "char *"))
      ((nonnull-unsigned-c-string nonnull-unsigned-c-string* unsigned-c-string unsigned-c-string*)
       (str "unsigned char *"))
      ((void) (str "void"))
      (else
       (cond ((and (symbol? type) (lookup-foreign-type type))
	      => (lambda (t)
		   (foreign-type-declaration (vector-ref t 0) target)) )
	     ((string? type) (str type))
	     ((list? type)
	      (let ((len (length type)))
		(cond 
		 ((and (= 2 len)
		       (memq (car type) '(pointer nonnull-pointer c-pointer 
						  scheme-pointer nonnull-scheme-pointer
						  nonnull-c-pointer) ) )
		  (foreign-type-declaration (cadr type) (string-append "*" target)) )
		 ((and (= 2 len)
		       (eq? 'ref (car type)))
		  (foreign-type-declaration (cadr type) (string-append "&" target)) )
		 ((and (> len 2)
		       (eq? 'template (car type)))
		  (str
		   (string-append 
		    (foreign-type-declaration (cadr type) "")
		    "<"
		    (string-intersperse
		     (map (cut foreign-type-declaration <> "") (cddr type))
		     ",")
		    "> ") ) )
		 ((and (= len 2) (eq? 'const (car type)))
		  (string-append "const " (foreign-type-declaration (cadr type) target)))
		 ((and (= len 2) (eq? 'struct (car type)))
		  (string-append "struct " (->string (cadr type)) " " target))
		 ((and (= len 2) (eq? 'union (car type)))
		  (string-append "union " (->string (cadr type)) " " target))
		 ((and (= len 2) (eq? 'enum (car type)))
		  (string-append "enum " (->string (cadr type)) " " target))
		 ((and (= len 3) (memq (car type) '(instance nonnull-instance)))
		  (string-append (->string (cadr type)) "*" target))
		 ((and (= len 3) (eq? 'instance-ref (car type)))
		  (string-append (->string (cadr type)) "&" target))
		 ((and (>= len 3) (eq? 'function (car type)))
		  (let ((rtype (cadr type))
			(argtypes (caddr type))
			(callconv (optional (cdddr type) "")))
		    (string-append
		     (foreign-type-declaration rtype "")
		     callconv
		     " (*" target ")("
		     (string-intersperse
		      (map (lambda (at)
			     (if (eq? '... at) 
				 "..."
				 (foreign-type-declaration at "") ) )
			   argtypes) 
		      ",")
		     ")" ) ) )
		 (else (err)) ) ) )
	     (else (err)) ) ) ) ) )


;; Generate expression to convert argument from Scheme data

(define (foreign-argument-conversion type)
  (let ((err (lambda ()
	       (quit-compiling "illegal foreign argument type `~A'" type))))
    (case type
      ((scheme-object) "(")
      ((char unsigned-char) "C_character_code((C_word)")
      ((byte int int32 unsigned-int unsigned-int32 unsigned-byte) "C_unfix(")
      ((short) "C_unfix(")
      ((unsigned-short) "(unsigned short)C_unfix(")
      ((unsigned-long) "C_num_to_unsigned_long(")
      ((double number float) "C_c_double(")
      ((integer integer32) "C_num_to_int(")
      ((integer64) "C_num_to_int64(")
      ((size_t) "(size_t)C_num_to_uint64(")
      ((ssize_t) "(ssize_t)C_num_to_int64(")
      ((unsigned-integer64) "C_num_to_uint64(")
      ((long) "C_num_to_long(")
      ((unsigned-integer unsigned-integer32) "C_num_to_unsigned_int(")
      ((scheme-pointer) "C_data_pointer_or_null(")
      ((nonnull-scheme-pointer) "C_data_pointer(")
      ((c-pointer) "C_c_pointer_or_null(")
      ((nonnull-c-pointer) "C_c_pointer_nn(")
      ((blob) "C_c_bytevector_or_null(")
      ((nonnull-blob) "C_c_bytevector(")
      ((u8vector) "C_c_u8vector_or_null(")
      ((nonnull-u8vector) "C_c_u8vector(")
      ((u16vector) "C_c_u16vector_or_null(")
      ((nonnull-u16vector) "C_c_u16vector(")
      ((u32vector) "C_c_u32vector_or_null(")
      ((nonnull-u32vector) "C_c_u32vector(")
      ((u64vector) "C_c_u64vector_or_null(")
      ((nonnull-u64vector) "C_c_u64vector(")
      ((s8vector) "C_c_s8vector_or_null(")
      ((nonnull-s8vector) "C_c_s8vector(")
      ((s16vector) "C_c_s16vector_or_null(")
      ((nonnull-s16vector) "C_c_s16vector(")
      ((s32vector) "C_c_s32vector_or_null(")
      ((nonnull-s32vector) "C_c_s32vector(")
      ((s64vector) "C_c_s64vector_or_null(")
      ((nonnull-s64vector) "C_c_s64vector(")
      ((f32vector) "C_c_f32vector_or_null(")
      ((nonnull-f32vector) "C_c_f32vector(")
      ((f64vector) "C_c_f64vector_or_null(")
      ((nonnull-f64vector) "C_c_f64vector(")
      ((pointer-vector) "C_c_pointer_vector_or_null(")
      ((nonnull-pointer-vector) "C_c_pointer_vector(")
      ((c-string c-string* unsigned-c-string unsigned-c-string*) "C_string_or_null(")
      ((nonnull-c-string nonnull-c-string* nonnull-unsigned-c-string 
			 nonnull-unsigned-c-string* symbol) "C_c_string(")
      ((bool) "C_truep(")
      (else
       (cond ((and (symbol? type) (lookup-foreign-type type))
	      => (lambda (t)
		   (foreign-argument-conversion (vector-ref t 0)) ) )
	     ((and (list? type) (>= (length type) 2))
	      (case (car type)
		((c-pointer) "C_c_pointer_or_null(")
		((nonnull-c-pointer) "C_c_pointer_nn(")
		((instance) "C_c_pointer_or_null(")
		((nonnull-instance) "C_c_pointer_nn(")
		((scheme-pointer) "C_data_pointer_or_null(")
		((nonnull-scheme-pointer) "C_data_pointer(")
		((function) "C_c_pointer_or_null(")
		((const) (foreign-argument-conversion (cadr type)))
		((enum) "C_num_to_int(")
		((ref)
		 (string-append "*(" (foreign-type-declaration (cadr type) "*")
				")C_c_pointer_nn("))
		((instance-ref)
		 (string-append "*(" (cadr type) "*)C_c_pointer_nn("))
		(else (err)) ) )
	     (else (err)) ) ) ) ) )


;; Generate suitable conversion of a result value into Scheme data
	    
(define (foreign-result-conversion type dest)
  (let ((err (lambda ()
	       (quit-compiling "illegal foreign return type `~A'" type))))
    (case type
      ((char unsigned-char) "C_make_character((C_word)")
      ((int int32) "C_fix((C_word)")
      ((unsigned-int unsigned-int32) "C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)")
      ((short) "C_fix((short)")
      ((unsigned-short) "C_fix(0xffff&(C_word)")
      ((byte) "C_fix((char)")
      ((unsigned-byte) "C_fix(0xff&(C_word)")
      ((float double) (sprintf "C_flonum(&~a," dest))	;XXX suboptimal for int64
      ((number) (sprintf "C_number(&~a," dest))
      ((nonnull-c-string c-string nonnull-c-pointer c-string* nonnull-c-string* 
			 unsigned-c-string unsigned-c-string* nonnull-unsigned-c-string
			 nonnull-unsigned-c-string* symbol c-string-list c-string-list*) 
       (sprintf "C_mpointer(&~a,(void*)" dest) )
      ((c-pointer) (sprintf "C_mpointer_or_false(&~a,(void*)" dest))
      ((integer integer32) (sprintf "C_int_to_num(&~a," dest))
      ((integer64 ssize_t) (sprintf "C_int64_to_num(&~a," dest))
      ((unsigned-integer64 size_t) (sprintf "C_uint64_to_num(&~a," dest))
      ((unsigned-integer unsigned-integer32) (sprintf "C_unsigned_int_to_num(&~a," dest))
      ((long) (sprintf "C_long_to_num(&~a," dest))
      ((unsigned-long) (sprintf "C_unsigned_long_to_num(&~a," dest))
      ((bool) "C_mk_bool(")
      ((void scheme-object) "((C_word)")
      (else
       (cond ((and (symbol? type) (lookup-foreign-type type))
	      => (lambda (x)
		   (foreign-result-conversion (vector-ref x 0) dest)) )
	     ((and (list? type) (>= (length type) 2))
	      (case (car type)
		((nonnull-pointer nonnull-c-pointer)
		 (sprintf "C_mpointer(&~A,(void*)" dest) )
		((ref)
		 (sprintf "C_mpointer(&~A,(void*)&" dest) )
		((instance)
		 (sprintf "C_mpointer_or_false(&~A,(void*)" dest) )
		((nonnull-instance)
		 (sprintf "C_mpointer(&~A,(void*)" dest) )
		((instance-ref)
		 (sprintf "C_mpointer(&~A,(void*)&" dest) )
		((const) (foreign-result-conversion (cadr type) dest))
		((pointer c-pointer)
		 (sprintf "C_mpointer_or_false(&~a,(void*)" dest) )
		((function) (sprintf "C_mpointer(&~a,(void*)" dest))
		((enum) (sprintf "C_int_to_num(&~a," dest))
		(else (err)) ) )
	     (else (err)) ) ) ) ) )


;;; Encoded literals as strings, to be decoded by "C_decode_literal()"
;; 
;; - everything hardcoded, using the FFI would be the ugly, but safer method.

(define (encode-literal lit)
  (define getbits
    (foreign-lambda* int ((scheme-object lit))
      "
#ifdef C_SIXTY_FOUR
return((C_header_bits(lit) >> (24 + 32)) & 0xff);
#else
return((C_header_bits(lit) >> 24) & 0xff);
#endif
") )
  (define getsize
    (foreign-lambda* int ((scheme-object lit))
      "return(C_header_size(lit));"))
  (define (encode-size n)
    (if (fx> (fxlen n) 24)
	;; Unfortunately we can't do much more to help the user.
	;; Printing the literal is not helpful because it's *huge*,
	;; and we have no line number information here.
	(quit-compiling
	 "Encoded literal size of ~S is too large (must fit in 24 bits)" n)
	(string
	 (integer->char (bitwise-and #xff (arithmetic-shift n -16)))
	 (integer->char (bitwise-and #xff (arithmetic-shift n -8)))
	 (integer->char (bitwise-and #xff n)))))
  (define (finish str)		   ; can be taken out at a later stage
    (string-append (string #\xfe) str))
  (finish
   (cond ((eq? #t lit) "\xff\x06\x01")
	 ((eq? #f lit) "\xff\x06\x00")
	 ((char? lit) (string-append "\xff\x0a" (encode-size (char->integer lit))))
	 ((null? lit) "\xff\x0e")
	 ((eof-object? lit) "\xff\x3e")
	 ((eq? (void) lit) "\xff\x1e")
	 ;; The big-fixnum? check can probably be simplified
	 ((and (fixnum? lit) (not (big-fixnum? lit)))
	  (string-append
	   "\xff\x01"
	   (string (integer->char (bitwise-and #xff (arithmetic-shift lit -24)))
		   (integer->char (bitwise-and #xff (arithmetic-shift lit -16)))
		   (integer->char (bitwise-and #xff (arithmetic-shift lit -8)))
		   (integer->char (bitwise-and #xff lit)) ) ) )
	 ((exact-integer? lit)
	  ;; Encode as hex to save space and get exact size
	  ;; calculation.  We could encode as base 32 to save more
	  ;; space, but that makes debugging harder.  The type tag is
	  ;; a bit of a hack: we encode as "GC forwarded" string to
	  ;; get a unique new type, as bignums don't have their own
	  ;; type tag (they're encoded as structures).
	  (let ((str (number->string lit 16)))
	    (string-append "\xc2" (encode-size (string-length str)) str)))
	 ((flonum? lit)
	  (string-append "\x55" (number->string lit) "\x00") )
	 ((or (keyword? lit) (symbol? lit))
	  (let ((str (##sys#slot lit 1)))
	    (string-append 
	     "\x01"
	     (encode-size (string-length str))
	     (if (keyword? lit) "\x02" "\x01")
	     str) ) )
	 ((##sys#immediate? lit)
	  (bomb "invalid literal - cannot encode" lit))
	 ((##core#inline "C_byteblockp" lit)
	  (##sys#string-append ; relies on the fact that ##sys#string-append doesn't check
	   (string-append
	    (string (integer->char (getbits lit)))
	    (encode-size (getsize lit)) )
	   lit) )
	 (else
	  (let ((len (getsize lit)))
	    (string-intersperse
	     (cons*
	      (string (integer->char (getbits lit)))
	      (encode-size len)
	      (list-tabulate len (lambda (i) (encode-literal (##sys#slot lit i)))))
	     ""))))) )
)
