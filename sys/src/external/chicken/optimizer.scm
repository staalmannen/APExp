;;;; optimizer.scm - The CHICKEN Scheme compiler (optimizations)
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
  (unit optimizer)
  (uses data-structures internal support))

(module chicken.compiler.optimizer
    (scan-toplevel-assignments perform-high-level-optimizations
     transform-direct-lambdas! determine-loop-and-dispatch
     eq-inline-operator membership-test-operators membership-unfold-limit
     default-optimization-passes rewrite)

(import scheme
	chicken.base
	chicken.compiler.support
	chicken.fixnum
	chicken.internal
	chicken.sort
	chicken.string)

(include "tweaks")
(include "mini-srfi-1.scm")

(define-constant maximal-number-of-free-variables-for-liftable 16)

;; These are parameterized by the platform implementation
(define eq-inline-operator (make-parameter #f))
(define membership-test-operators (make-parameter #f))
(define membership-unfold-limit (make-parameter #f))
(define default-optimization-passes (make-parameter #f))

;;; Scan toplevel expressions for assignments:

(define (scan-toplevel-assignments node)
  (let ((safe '())
	(unsafe '()) 
	(escaped #f)
	(previous '()))

    (define (mark v)
      (when (and (not escaped)
		 (not (memq v unsafe)))
	(set! safe (cons v safe))) )

    (define (remember v x)
      (set! previous (alist-update! v x previous)))

    (define (touch)
      (set! escaped #t)
      (set! previous '()))

    (define (scan-each ns e clear-previous?)
      (for-each (lambda (n)
		  (when clear-previous? (set! previous '()))
		  (scan n e))
		ns))

    (define (scan n e)
      (let ([params (node-parameters n)]
	    [subs (node-subexpressions n)] )
	(case (node-class n)

	  [(##core#variable)
	   (let ((var (first params)))
	     (when (and (not (memq var e)) 
			(not (memq var unsafe)))
	       (set! unsafe (cons var unsafe)) )
	     (set! previous (filter (lambda (p) (not (eq? (car p) var))) previous)))]

	  [(if ##core#cond ##core#switch)
	   (scan (first subs) e)
	   (touch)
	   (scan-each (cdr subs) e #t)]

	  [(let)
	   (scan-each (butlast subs) e #f)
	   (scan (last subs) (append params e)) ]

	  [(lambda ##core#lambda) #f]

	  [(##core#call) (touch)]

	  [(set!)
	   (let ((var (first params))
		 (val (first subs)))
	     (scan val e)
	     (let ((p (alist-ref var previous)))
	       (when (and p (not (memq var unsafe)))
		 ;; disabled for the moment - this doesn't really look like it's helpful
		 #;(##sys#notice
		  (sprintf "dropping assignment of unused value to global variable `~s'"
		    var))
		 (debugging 'o "dropping redundant toplevel assignment" var)
		 (copy-node!
		  (make-node '##core#undefined '() '())
		  p))
	       (unless (memq var e) (mark var))
	       (remember var n) ) ) ]

	  [else (scan-each subs e #f)])))

    (debugging 'p "scanning toplevel assignments...")
    (scan node '())
    (when (pair? safe)
      (debugging 'o "safe globals" (delete-duplicates safe eq?)))
    (for-each (cut mark-variable <> '##compiler#always-bound) safe)))


;;; Do some optimizations:
;
; - optimize tail recursion by replacing trivial continuations.
; - perform beta-contraction (inline procedures called only once).
; - remove empty 'let' nodes.
; - evaluate constant expressions.
; - substitute variables bound to constants with the value.
; - remove variable-bindings which are never used (and which are not bound to side-effecting expressions).
; - perform simple copy-propagation.
; - remove assignments to unused variables if the assigned value is free of side-effects and the variable is
;   not global.
; - remove unused formal parameters from functions and change all call-sites accordingly.
; - rewrite calls to standard bindings into more efficient forms.
; - rewrite calls to known non-escaping procedures with rest parameter to cons up rest-list at call-site,
;   also: change procedure's lambda-list.

(define simplifications (make-vector 301 '()))
(define simplified-ops '())
(define broken-constant-nodes '())
;; Holds a-list mapping inlined fid's to inline-target-fid for catching runaway
;; unrolling:
(define inline-history '())

(define (perform-high-level-optimizations
	 node db block-compilation may-inline inline-limit max-unrolls may-rewrite)
  (let ((removed-lets 0)
	(removed-ifs 0)
	(replaced-vars 0)
	(rest-consers '())
	(simplified-classes '())
	(dirty #f) )

    (define (test sym item) (db-get db sym item))
    (define (constant-node? n) (eq? 'quote (node-class n)))
    (define (node-value n) (first (node-parameters n)))
    (define (touch) (set! dirty #t))

    (define (invalidate-gae! gae)
      (for-each (cut set-cdr! <> #f) gae))

    (define (simplify n)
      (or (and-let* ((entry (hash-table-ref
			     simplifications (node-class n))))
	    (any (lambda (s)
		   (and-let* ((vars (second s))
			      (env (match-node n (first s) vars)) 
			      (n2 (apply (third s) db may-rewrite
					 (map (lambda (v) (cdr (assq v env))) vars) ) ) )
		     (let* ((name (caar s))
			    (counter (assq name simplified-classes)) )
		       (if counter
			   (set-cdr! counter (add1 (cdr counter)))
			   (set! simplified-classes (alist-cons name 1 simplified-classes)) )
		       (touch)
		       (simplify n2) ) ) )
		 entry) )
	  n) )


    (define (maybe-replace-rest-arg-calls node)
      ;; Ugh, we need to match on the core inlined string instead of
      ;; the call to the intrinsic itself, because rewrites will have
      ;; introduced this after the first iteration.
      (or (and-let* (((eq? '##core#inline (node-class node)))
                     (native (car (node-parameters node)))
                     (replacement-op (cond
                                      ((member native '("C_i_car" "C_u_i_car")) '##core#rest-car)
                                      ((member native '("C_i_cdr" "C_u_i_cdr")) '##core#rest-cdr)
                                      ((member native '("C_i_nullp")) '##core#rest-null?)
                                      ((member native '("C_i_length" "C_u_i_length")) '##core#rest-length)
                                      (else #f)))
                     (arg (first (node-subexpressions node)))
                     ((eq? '##core#variable (node-class arg)))
                     (var (first (node-parameters arg)))
                     ((not (db-get db var 'captured)))
                     ((not (db-get db var 'consed-rest-arg)))
                     (info (db-get db var 'rest-cdr))
                     (restvar (car info))
                     (depth (cdr info))
                     ((not (test var 'assigned))))
            ;; callee is intrinsic and accesses rest arg sublist
	    (debugging '(o x) "known list op on rest arg sublist"
		       (call-info (node-parameters node) replacement-op) var depth)
            (touch)
            (make-node replacement-op
	               (cons* restvar depth (cdr (node-parameters node)))
	               (list) ) )
          node) )

    (define (walk n fids gae)
      (if (memq n broken-constant-nodes)
	  n
	  (simplify
	   (let* ((odirty dirty)
		  (n1 (walk1 n fids gae))
		  (subs (node-subexpressions n1)) )
	     (case (node-class n1)

	       ((if)			; (This can be done by the simplifier...)
		(cond ((constant-node? (car subs))
		       (set! removed-ifs (add1 removed-ifs))
		       (touch)
		       (walk (if (node-value (car subs))
				 (cadr subs)
				 (caddr subs) )
			     fids gae) )
		      (else n1) ) )

               ((##core#inline)
                (maybe-replace-rest-arg-calls n1))

	       ((##core#call)
		(maybe-constant-fold-call
		 n1
		 (cons (car subs) (cddr subs))
		 (lambda (ok result constant?)
		   (cond ((not ok)
			  (when constant?
			    (unless odirty (set! dirty #f))
			    (set! broken-constant-nodes
				(lset-adjoin/eq? broken-constant-nodes n1)))
			  n1)
			 (else
			  (touch)
			  ;; Build call to continuation with new result...
			  (let ((n2 (qnode result)))
			    (make-node
			     '##core#call
			     (list #t)
			     (list (cadr subs) n2) ) ) ) ))) )
	       (else n1) ) ) ) ) )

    (define (replace-var var)
      (cond ((test var 'replacable) =>
             (lambda (rvar)
               (let ((final-var (replace-var rvar)))
                 ;; Store intermediate vars to avoid recurring same chain again
                 (db-put! db var 'replacable final-var)
                 final-var)))
            (else var)))
    
    (define (walk1 n fids gae)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n)) 
	    (class (node-class n)) )
	(case class

	  ((##core#variable)
	   (let ((var (replace-var (first params))))
	     (cond ((test var 'collapsable)
		    (touch)
		    (debugging 'o "substituted constant variable" var)
		    (qnode (car (node-parameters (test var 'value)))) )
		   ((not (eq? var (first params)))
		    (touch)
		    (set! replaced-vars (+ replaced-vars 1))
		    (varnode var))
		   ((assq var gae) =>
		    (lambda (a)
		      (let ((gvar (cdr a)))
			(cond ((and gvar
				    (not (eq? 'no (variable-mark gvar '##compiler#inline))))
			       (debugging 'o "propagated global variable" var gvar)
			       (varnode gvar))
			      (else (varnode var))))))
		   (else (varnode var)))))

	  ((let)
	   (let ((var (first params)))
	     (cond ((or (test var 'removable)
			(and (test var 'contractable) 
			     (not (test var 'replacing))))
		    (touch)
		    (set! removed-lets (add1 removed-lets))
		    (walk (second subs) fids gae) )
		   (else
		    (let ((gae (if (and (eq? '##core#variable (node-class (first subs)))
					(test (first (node-parameters (first subs)))
					      'global))
				   (alist-cons var (first (node-parameters (first subs)))
					       gae)
				   gae)))
		      (make-node 'let params (map (cut walk <> fids gae) subs))) ) ) ))

	  ((##core#lambda)
	   (let ((llist (third params))
		 (id (first params)))
	     (cond [(test id 'has-unused-parameters)
		    (##sys#decompose-lambda-list
		     llist
		     (lambda (vars argc rest)
		       (receive (unused used) (partition (lambda (v) (test v 'unused)) vars)
			 (touch)
			 (debugging 'o "removed unused formal parameters" unused)
			 (make-node
			  '##core#lambda
			  (list (first params) (second params)
				(cond [(and rest (test id 'explicit-rest))
				       (debugging 
					'o "merged explicitly consed rest parameter" rest)
				       (build-lambda-list used (add1 argc) #f) ]
				      [else (build-lambda-list used argc rest)] )
				(fourth params) )
			  (list (walk (first subs) (cons id fids) '())) ) ) ) ) ]
		   [(test id 'explicit-rest)
		    (##sys#decompose-lambda-list
		     llist
		     (lambda (vars argc rest)
		       (touch)
		       (debugging 'o "merged explicitly consed rest parameter" rest)
		       (make-node
			'##core#lambda
			(list (first params)
			      (second params)
			      (build-lambda-list vars (add1 argc) #f)
			      (fourth params) )
			(list (walk (first subs) (cons id fids) '())) ) ) ) ]
		   [else (walk-generic n class params subs (cons id fids) '() #f)] ) ) )

	  ((##core#direct_lambda)
	   (walk-generic n class params subs fids '() #f))

	  ((##core#call)
	   (let* ((fun (car subs))
		  (funclass (node-class fun)))
	     (case funclass
	       [(##core#variable)
		;; Call to named procedure:
		(let* ((var (first (node-parameters fun)))
		       (info (call-info params var))
		       (lval (and (not (test var 'unknown)) 
				  (or (test var 'value)
				      (test var 'local-value))))
		       (args (cdr subs)) )
		  (cond ((and (test var 'contractable)
			      (not (test var 'replacing))
			      ;; inlinable procedure has changed
			      (not (test (first (node-parameters lval)) 'inline-target)))
			 ;; only called once
			 (let* ([lparams (node-parameters lval)]
				[llist (third lparams)] )
			   (cond ((check-signature var args llist)
                                   (debugging 'o "contracted procedure" info)
                                   (touch)
                       	           (for-each (cut db-put! db <> 'inline-target #t) 
                                     fids)
                                   (walk
                                     (inline-lambda-bindings
			               llist args (first (node-subexpressions lval)) 
                                       #f db
			               void)
			             fids gae) )
                                 (else
                                   (debugging 
                                     'i
                                     "not contracting procedure because argument list does not match"
                                     info)
                                   (walk-generic n class params subs fids gae #t)))))
			((and-let* (((variable-mark var '##compiler#pure))
				    ((eq? '##core#variable (node-class (car args))))
				    (kvar (first (node-parameters (car args))))
				    (lval (and (not (test kvar 'unknown))
					       (test kvar 'value)))
				    ((eq? '##core#lambda (node-class lval)))
				    (llist (third (node-parameters lval)))
				    ((or (test (car llist) 'unused)
					 (and (not (test (car llist) 'references))
					      (not (test (car llist) 'assigned))))))
			   ;; callee is side-effect free
			   (not (any (cut expression-has-side-effects? <> db)
				     (cdr args))))
			 (debugging
			  'o
			  "removed call to pure procedure with unused result"
			  info)
			 (make-node
			  '##core#call (list #t)
			  (list (car args)
				(make-node '##core#undefined '() '()))))
			((and lval
			      (eq? '##core#lambda (node-class lval)))
			 ;; callee is a lambda
			 (let* ((lparams (node-parameters lval))
				(llist (third lparams)) )
			   (##sys#decompose-lambda-list
			    llist
			    (lambda (vars argc rest)
			      (let ((ifid (first lparams))
				    (external (node? (variable-mark var '##compiler#inline-global))))
				(cond ((and may-inline 
					    (test var 'inlinable)
					    (not (test ifid 'inline-target)) ; inlinable procedure has changed
					    (not (test ifid 'explicit-rest))
					    (case (variable-mark var '##compiler#inline) 
					      ((no) #f)
					      (else 
					       (or external (< (fourth lparams) inline-limit))))
                                            (or (within-unrolling-limit ifid (car fids) max-unrolls)
                                                (begin
                                                  (debugging 'i "not inlining as unroll-limit is exceeded"
                                                             info ifid (car fids))
                                                  #f)))
				       (cond ((check-signature var args llist)
                                               (debugging 'i
                                                          (if external
                                                              "global inlining" 	
                                                              "inlining")
                                                          info ifid (fourth lparams))
                                               (for-each (cut db-put! db <> 'inline-target #t) 
                                                 fids)
				               (debugging 'o "inlining procedure" info)
				               (call/cc
                                                 (lambda (return)
                                                   (define (cfk cvar)
                                                     (debugging 
                                                       'i
                                                       "not inlining procedure because it refers to contractable"
                                                       info cvar)
                                                     (return (walk-generic n class params subs fids gae #t)))
                                                   (let ((n2 (inline-lambda-bindings
                                                                llist args (first (node-subexpressions lval))
                                                                #t db cfk)))
                                                     (set! inline-history
                                                       (alist-cons ifid (car fids) inline-history))
                                                     (touch)
                                                     (walk n2 fids gae)))))
                                             (else
                                               (debugging 
                                                 'i
                                                 "not inlining procedure because argument list does not match"
                                                 info)
                                               (walk-generic n class params subs fids gae #t))))
				      ((test ifid 'has-unused-parameters)
				       (if (< (length args) argc) ; Expression was already optimized (should this happen?)
					   (walk-generic n class params subs fids gae #t)
					   (let loop ((vars vars) (argc argc) (args args) (used '()))
					     (cond [(or (null? vars) (zero? argc))
						    (touch)
						    (let ((args
							   (map (cut walk <> fids gae)
								(cons 
								 fun
								 (append (reverse used) args))) ) )
						      (invalidate-gae! gae)
						      (make-node '##core#call params args))]
						   [(test (car vars) 'unused)
						    (touch)
						    (debugging
						     'o "removed unused parameter to known procedure" 
						     (car vars) info)
						    (if (expression-has-side-effects? (car args) db)
							(make-node
							 'let
							 (list (gensym 't))
							 (list (walk (car args) fids gae)
							       (loop (cdr vars) (sub1 argc) (cdr args) used) ) )
							(loop (cdr vars) (sub1 argc) (cdr args) used) ) ]
						   [else (loop (cdr vars)
							       (sub1 argc)
							       (cdr args)
							       (cons (car args) used) ) ] ) ) ) )
				      ((and (test ifid 'explicit-rest)
					    (not (memq n rest-consers)) ) ; make sure we haven't inlined rest-list already
				       (let ([n (llist-length llist)])
					 (if (< (length args) n)
					     (walk-generic n class params subs fids gae #t) 
					     (begin
					       (debugging 'o "consed rest parameter at call site" info n)
					       (let-values ([(args rargs) (split-at args n)])
						 (let ([n2 (make-node
							    '##core#call
							    params
							    (map (cut walk <> fids gae)
								 (cons fun
								       (append 
									args
									(list
									 (if (null? rargs)
									     (qnode '())
									     (make-node
									      '##core#inline_allocate 
									      (list "C_a_i_list" (* 3 (length rargs)))
									      rargs) ) ) ) ) ) ) ] )
						   (set! rest-consers (cons n2 rest-consers))
						   (invalidate-gae! gae)
						   n2) ) ) ) ) )
				      (else (walk-generic n class params subs fids gae #t)) ) ) ) ) ) )
			((and lval
			      (eq? '##core#variable (node-class lval))
			      (intrinsic? (first (node-parameters lval))))
			 ;; callee is intrinsic
			 (debugging 'i "inlining call to intrinsic alias" 
				    info (first (node-parameters lval)))
			 (walk
			  (make-node
			   '##core#call
			   params
			   (cons lval (cdr subs)))
			  fids gae))
			(else (walk-generic n class params subs fids gae #t)) ) ) ]
	       [(##core#lambda)
		(if (first params)
		    (walk-generic n class params subs fids gae #f)
		    (let ((n2 (make-node '##core#call (cons #t (cdr params))
					 (map (cut walk <> fids gae) subs)) ))
		      (invalidate-gae! gae)
		      n2))]
	       [else (walk-generic n class params subs fids gae #t)] ) ) )

	  ((set!)
	   (let ([var (first params)])
	     (cond ((test var 'contractable)
		    (touch)
		    (when (test var 'global)
		      (debugging 'i "removing global contractable" var))
		    (make-node '##core#undefined '() '()) )
		   ((test var 'replacable)
		    (touch)
		    (make-node '##core#undefined '() '()) )
		   ((and (or (not (test var 'global))
			     (not (variable-visible? var block-compilation)))
			 (not (test var 'inline-transient))
			 (not (test var 'references)) 
			 (not (expression-has-side-effects? (first subs) db)) )
		    (touch)
		    (debugging 'o "removed side-effect free assignment to unused variable" var)
		    (make-node '##core#undefined '() '()) )
		   (else
		    (let ((n2 (make-node 'set! params (list (walk (car subs) fids gae)))))
		      (for-each
		       (if (test var 'global)
			   (lambda (a)
			     (when (eq? var (cdr a)) ; assignment to alias?
			       (set-cdr! a #f)))
			   (lambda (a)
			     (when (eq? var (car a))
			       (set-cdr! a #f))))
		       gae)
		      n2)))))

          ((##core#rest-cdr ##core#rest-car ##core#rest-null? ##core#rest-length)
	   (let ((rest-var (first params)))
	     ;; If rest-arg has been replaced with regular arg which
	     ;; is explicitly consed at call sites, restore rest ops
	     ;; as regular car/cdr calls on the rest list variable.
	     ;; This can be improved, as it can actually introduce
	     ;; many more cdr calls than necessary.
	     (cond
              ((or (test rest-var 'consed-rest-arg))
	       (touch)
	       (debugging 'o "resetting rest op for explicitly consed rest parameter" rest-var class)

	       (replace-rest-op-with-list-ops class (varnode rest-var) params))

              (else (walk-generic n class params subs fids gae #f))) ) )

	  (else (walk-generic n class params subs fids gae #f)) ) ) )
    
    (define (walk-generic n class params subs fids gae invgae)
      (let lp ((same? #t)
               (subs subs)
               (subs2 '()))
        (cond ((null? subs)
               (when invgae (invalidate-gae! gae))
               ;; Create new node if walk made changes, otherwise original node
               (if same? n (make-node class params (reverse subs2))))
              (else
               (let ((sub2 (walk (car subs) fids gae)))
                 (lp (and same? (eq? sub2 (car subs)))
                     (cdr subs) (cons sub2 subs2)))) ) ))

    (if (perform-pre-optimization! node db)
	(values node #t)
	(begin
	  (debugging 'p "traversal phase...")
	  (set! simplified-ops '())
	  (let ((node2 (walk node '() '())))
	    (when (pair? simplified-classes) (debugging 'o "simplifications" simplified-classes))
	    (when (pair? simplified-ops)
	      (with-debugging-output
	       'o
	       (lambda ()
		 (print "  call simplifications:")
		 (for-each
		  (lambda (p)
		    (print* "    " (car p))
		    (if (> (cdr p) 1)
			(print #\tab (cdr p))
			(newline) ) )
		  simplified-ops) ) ) )
	    (when (> replaced-vars 0) (debugging 'o "replaced variables" replaced-vars))
	    (when (> removed-lets 0) (debugging 'o "removed binding forms" removed-lets))
	    (when (> removed-ifs 0) (debugging 'o "removed conditional forms" removed-ifs))
	    (values node2 dirty) ) ) ) ) )


;; Check whether inlined procedure has already been inlined in the
;; same target procedure and count occurrences.
;;
;; Note: This check takes O(n) time, where n is the total number of
;; performed inlines. This can be optimized to O(1) if high number of
;; inlines starts to slow down the compilation.

(define (within-unrolling-limit fid tfid max-unrolls)
  (let ((p (cons fid tfid)))
    (let loop ((h inline-history) (n 0))
      (cond ((null? h))
            ((equal? p (car h))
             (and (< n max-unrolls)
                  (loop (cdr h) (add1 n))))
            (else (loop (cdr h) n))))))


;;; Pre-optimization phase:
;
; - Transform expressions of the form '(if (not <x>) <y> <z>)' into '(if <x> <z> <y>)'.
; - Transform expressions of the form '(if (<x> <y> ...) <z> <q>)' into '<z>' if <x> names a
;   standard-binding that is never #f and if it's arguments are free of side-effects.

(define (perform-pre-optimization! node db)
  (let ((dirty #f)
	(removed-nots 0) )

    (define (touch) (set! dirty #t) #t)
    (define (test sym prop) (db-get db sym prop))

    (debugging 'p "pre-optimization phase...")

    ;; Handle '(if (not ...) ...)':
    (if (intrinsic? 'not)
	(for-each 
	 (lambda (site)
	   (let* ((n (cdr site))
		  (subs (node-subexpressions n))
		  (kont (first (node-parameters (second subs))))
		  (lnode (and (not (test kont 'unknown)) (test kont 'value)))
		  (krefs (db-get-list db kont 'references)) )
	     ;; Call-site has one argument and a known continuation (which is a ##core#lambda)
	     ;;  that has only one use:
	     (when (and lnode (= 1 (length krefs)) (= 3 (length subs))
			(eq? '##core#lambda (node-class lnode)) )
	       (let* ((llist (third (node-parameters lnode)))
		      (body (first (node-subexpressions lnode))) 
		      (bodysubs (node-subexpressions body)) )
		 ;; Continuation has one parameter?
		 (if (and (list? llist) (null? (cdr llist)))
		     (let* ((var (car llist))
			    (refs (db-get-list db var 'references)) )
		       ;; Parameter is only used once?
		       (if (and (= 1 (length refs)) (eq? 'if (node-class body)))
			   ;; Continuation contains an 'if' node?
			   (let ((iftest (first (node-subexpressions body))))
			     ;; Parameter is used only once and is the test-argument?
			     (if (and (eq? '##core#variable (node-class iftest))
				      (eq? var (first (node-parameters iftest))) )
				 ;; Modify call-site to call continuation directly and swap branches
				 ;;  in the conditional:
				 (begin
				   (set! removed-nots (+ removed-nots 1))
				   (node-parameters-set! n '(#t))
				   (node-subexpressions-set! n (cdr subs))
				   (node-subexpressions-set! 
				    body
				    (cons (car bodysubs) (reverse (cdr bodysubs))) )
				   (touch) ) ) ) ) ) ) ) ) ) )
	 (or (test 'not 'call-sites) '()) ) )
    
    (when (> removed-nots 0) (debugging 'o "Removed `not' forms" removed-nots))
    dirty) )


;;; Simplifications:

(define (register-simplifications class . ss)
  (hash-table-set! simplifications class ss))


(register-simplifications
 '##core#call
 ;; (<named-call> ...) -> (<primitive-call/inline> ...)
 `((##core#call d (##core#variable (a)) b . c)
   (a b c d)
   ,(lambda (db may-rewrite a b c d)
      (let loop ((entries (or (hash-table-ref substitution-table a) '())))
	(cond ((null? entries) #f)
	      ((simplify-named-call db may-rewrite d a b
				    (caar entries) (cdar entries) c)
	       => (lambda (r)
		    (let ((as (assq a simplified-ops)))
		      (if as 
			  (set-cdr! as (add1 (cdr as)))
			  (set! simplified-ops (alist-cons a 1 simplified-ops)) ) )
		    r) )
	      (else (loop (cdr entries))) ) ) ) ) )


(register-simplifications
 'let

 ;; (let ((<var1> (##core#inline <eq-inline-operator> <var0> <const1>)))
 ;;   (if <var1> <body1>
 ;;       (let ((<var2> (##core#inline <eq-inline-operator> <var0> <const2>)))
 ;;         (if <var2> <body2>
 ;;             <etc.>
 ;; -> (##core#switch (2) <var0> <const1> <body1> <const2> <body2> <etc.>)
 ;; - <var1> and <var2> have to be referenced once only.
 `((let (var1) (##core#inline (op) (##core#variable (var0)) (quote (const1)))
	(if d1 (##core#variable (var1))
	    body1
	    (let (var2) (##core#inline (op) (##core#variable (var0)) (quote (const2)))
		 (if d2 (##core#variable (var2))
		     body2
		     rest) ) ) )
   (var0 var1 var2 op const1 const2 body1 body2 d1 d2 rest)
   ,(lambda (db may-rewrite var0 var1 var2 op const1 const2 body1 body2 d1 d2 rest)
      (and (equal? op (eq-inline-operator))
	   (immediate? const1)
	   (immediate? const2)
	   (= 1 (length (db-get-list db var1 'references)))
	   (= 1 (length (db-get-list db var2 'references)))
	   (make-node
	    '##core#switch
	    '(2)
	    (list (varnode var0)
		  (qnode const1)
		  body1
		  (qnode const2)
		  body2
		  rest) ) ) ) )

 ;; (let ((<var> (##core#inline <eq-inline-operator> <var0> <const>)))
 ;;   (if <var>
 ;;       <body>
 ;;       (##core#switch <n> <var0> <const1> <body1> ... <rest>) ) )
 ;; -> (##core#switch <n+1> <var0> <const> <body> <const1> <body1> ... <rest>)
 ;; - <var> has to be referenced once only.
 `((let (var) (##core#inline (op) (##core#variable (var0)) (quote (const)))
	(if d (##core#variable (var))
	    body
	    (##core#switch (n) (##core#variable (var0)) . clauses) ) )
   (var op var0 const d body n clauses)
   ,(lambda (db may-rewrite var op var0 const d body n clauses)
      (and (equal? op (eq-inline-operator))
	   (immediate? const)
	   (= 1 (length (db-get-list db var 'references)))
	   (make-node
	    '##core#switch
	    (list (add1 n))
	    (cons* (varnode var0)
		   (qnode const)
		   body
		   clauses) ) ) ) )
	      
 ;; (let ((<var1> (##core#undefined)))
 ;;   (let ((<var2> (##core#undefined)))
 ;;     ...
 ;;     (let ((<tmp1> (set! <var1> <x1>))
 ;;       (let ((<tmp2> (set! <var2> <x2>)))
 ;;         ...
 ;;         <body>) ... )
 ;; -> <a simpler sequence of let's>
 ;; - <tmpI> may not be used.
 `((let (var1) (##core#undefined ())
	more)
   (var1 more)
   ,(lambda (db may-rewrite var1 more)
      (let loop1 ((vars (list var1)) 
		  (body more) )
	(let ((c (node-class body))
	      (params (node-parameters body)) 
	      (subs (node-subexpressions body)) )
	  (and (eq? c 'let)
	       (null? (cdr params))
               (not (db-get db (first params) 'inline-transient))
               (not (db-get db (first params) 'references))
	       (let* ((val (first subs))
		      (valparams (node-parameters val))
		      (valsubs (node-subexpressions val)) )
		 (case (node-class val)
		   ((##core#undefined) (loop1 (cons (first params) vars) (second subs)))
		   ((set!)
		    (let ((allvars (reverse vars)))
		      (and (pair? allvars)
			   (eq? (first valparams) (first allvars))
			   (let loop2 ((vals (list (first valsubs)))
				       (vars (cdr allvars)) 
				       (body (second subs)) )
			     (let ((c (node-class body))
				   (params (node-parameters body))
				   (subs (node-subexpressions body)) )
			       (cond ((and (eq? c 'let)
					   (null? (cdr params))
					   (not (db-get db (first params) 'inline-transient))
					   (not (db-get db (first params) 'references))
					   (pair? vars)
					   (eq? 'set! (node-class (first subs)))
					   (eq? (car vars) (first (node-parameters (first subs)))) )
				      (loop2 (cons (first (node-subexpressions (first subs))) vals)
					     (cdr vars)
					     (second subs) ) )
				     ((null? vars)
				      (receive (n progress) 
					  (reorganize-recursive-bindings allvars (reverse vals) body) 
					(and progress n) ) )
				     (else #f) ) ) ) ) ) )
		   (else #f) ) ) ) ) ) ) )

 ;; (let ((<var1> <var2>))
 ;;   (<var1> ...) )
 ;; -> (<var2> ...)
 ;; - <var1> used only once
 #| this doesn't seem to work (Sven Hartrumpf):
 `((let (var1) (##core#variable (var2))
	(##core#call p (##core#variable (var1)) . more) ) ; `p' was `#t', bombed also
   (var1 var2 p more)
   ,(lambda (db may-rewrite var1 var2 p more)
      (and (= 1 (length (db-get-list db var1 'references)))
	   (make-node
	    '##core#call p
	    (cons (varnode var2) more) ) ) ) )
 |#

 ;; (let ((<var> (##core#inline <op> ...)))
 ;;   (if <var> <x> <y>) )
 ;; -> (if (##core#inline <op> ...) <x> <y>)
 ;; - <op> may not be the eq-inline operator (so rewriting to "##core#switch" works).
 ;; - <var> has to be referenced only once.
 `((let (var) (##core#inline (op) . args)
	(if d (##core#variable (var))
	    x
	    y) ) 
   (var op args d x y)
   ,(lambda (db may-rewrite var op args d x y)
      (and (not (equal? op (eq-inline-operator)))
	   (= 1 (length (db-get-list db var 'references)))
	   (make-node
	    'if d
	    (list (make-node '##core#inline (list op) args)
		  x y) ) ) ) )
          
 ;; (let ((<var1> (##core#inline <op1> ...)))
 ;;   (<var2> (##core#inline <op2> ... <var1> ...)))
 ;; -> (<var2> (##core#inline <op2> ... (##core#inline <op2> ...)
 ;;                                  ...))
 ;; - <var1> is used only once.
 `((let (var) (##core#inline (op1) . args1)
      (##core#call p 
                   (##core#variable (kvar))
                   (##core#inline (op2) . args2)))
    (var op1 args1 p kvar op2 args2)
    ,(lambda (db may-rewrite var op1 args1 p kvar op2 args2)
       (and may-rewrite   ; give other optimizations a chance first
            (not (eq? var kvar))
            (not (db-get db kvar 'contractable))
            (= 1 (length (db-get-list db var 'references)))
            (let loop ((args args2) (nargs '()) (ok #f))
              (cond ((null? args)
                     (and ok
                          (make-node 
                           '##core#call p
                           (list (varnode kvar)
                                 (make-node 
                                   '##core#inline 
                                   (list op2)
                                 (reverse nargs))))))
                    ((and (eq? '##core#variable
                               (node-class (car args)))
                          (eq? var
                               (car (node-parameters (car args)))))
                     (loop (cdr args)
                           (cons (make-node
                                   '##core#inline
                                   (list op1)
                                   args1)
                                 nargs)
                           #t))
                    (else (loop (cdr args)
                                (cons (car args) nargs)
                                ok)))))))

 ;; (let ((<var1> (##core#inline <op> ...)))
 ;;   (<var2> ... <var1> ...))
 ;; -> (<var2> ... (##core#inline <op> ...) ...)
 ;;                                  ...))
 ;; - <var1> is used only once.
 `((let (var) (##core#inline (op) . args1)
      (##core#call p . args2))
    (var op args1 p args2)
    ,(lambda (db may-rewrite var op args1 p args2)
       (and may-rewrite   ; give other optimizations a chance first
            (= 1 (length (db-get-list db var 'references)))
            (let loop ((args args2) (nargs '()) (ok #f))
              (cond ((null? args)
                     (and ok
                          (make-node 
                           '##core#call p
                           (reverse nargs))))
                    ((and (eq? '##core#variable
                               (node-class (car args)))
                          (eq? var
                               (car (node-parameters (car args)))))
                     (loop (cdr args)
                           (cons (make-node
                                   '##core#inline
                                   (list op)
                                   args1)
                                 nargs)
                           #t))
                    (else (loop (cdr args)
                                (cons (car args) nargs)
                                ok))))))))


(register-simplifications
 'if

 ;; (if <x>
 ;;     (<var> <y>)
 ;;     (<var> <z>) )
 ;; -> (<var> (##core#cond <x> <y> <z>))
 ;; - inline-substitutions have to be enabled (so IF optimizations have already taken place).
 `((if d1 x
       (##core#call d2 (##core#variable (var)) y)
       (##core#call d3 (##core#variable (var)) z) )
   (d1 d2 d3 x y z var)
   ,(lambda (db may-rewrite d1 d2 d3 x y z var)
      (and may-rewrite
	   (make-node
	    '##core#call d2
	    (list (varnode var)
		  (make-node '##core#cond '() (list x y z)) ) ) ) ) )

 ;; (if (##core#inline <memXXX> <x> '(<c1> ...)) ...)
 ;; -> (let ((<var> <x>))
 ;;      (if (##core#cond (##core#inline XXX? <var> '<c1>) #t ...) ...)
 ;; - there is a limit on the number of items in the list of constants.
 `((if d1 (##core#inline (op) x (quote (clist)))
       y
       z)
   (d1 op x clist y z)
   ,(lambda (db may-rewrite d1 op x clist y z)
      (and-let* ([opa (assoc op (membership-test-operators))]
		 [(list? clist)]
		 [(< (length clist) (membership-unfold-limit))] )
	(let ([var (gensym)]
	      [eop (list (cdr opa))] )
	  (make-node
	   'let (list var)
	   (list 
	    x
	    (make-node
	     'if d1
	     (list
	      (foldr
	       (lambda (c rest)
		 (make-node
		  '##core#cond '()
		  (list 
		   (make-node '##core#inline eop (list (varnode var) (qnode c)))
		   (qnode #t)
		   rest) ) )
	       (qnode #f)
	       clist)
	      y
	      z) ) ) ) ) ) ) ) )


;;; Perform dependency-analysis and transform letrec's into simpler constructs (if possible):

(define (reorganize-recursive-bindings vars vals body)
  (let ([graph '()]
	[valmap (map cons vars vals)] )

    (define (find-path var1 var2)
      (let find ([var var1] [traversed '()])
	(and (not (memq var traversed))
	     (let ([arcs (cdr (assq var graph))])
	       (or (memq var2 arcs)
		   (let ([t2 (cons var traversed)])
		     (any (lambda (v) (find v t2)) arcs) ) ) ) ) ) )

    ;; Build dependency graph:
    (for-each
     (lambda (var val) (set! graph (alist-cons var (scan-used-variables val vars) graph)))
     vars vals)

    ;; Compute recursive groups:
    (let ([groups '()]
	  [done '()] )
      (for-each
       (lambda (var)
	 (when (not (memq var done))
	   (let ([g (filter
		     (lambda (v) (and (not (eq? v var)) (find-path var v) (find-path v var)))
		     vars) ] )
	     (set! groups (alist-cons (gensym) (cons var g) groups))
	     (set! done (append (list var) g done)) ) ) )
       vars)

      ;; Coalesce groups into a new graph:
      (let ([cgraph '()])
	(for-each
	 (lambda (g)
	   (let ([id (car g)]
		 [deps
		  (append-map
		   (lambda (var) (filter (lambda (v) (find-path var v)) vars)) 
		   (cdr g) ) ] )
	     (set! cgraph
	       (alist-cons 
		id
		(filter-map
		 (lambda (g2) (and (not (eq? g2 g)) (lset<=/eq? (cdr g2) deps) (car g2)))
		 groups)
		cgraph) ) ) )
	 groups) 

	;; Topologically sort secondary dependency graph:
	(let ([sgraph (topological-sort cgraph eq?)]
	      [optimized '()] )

	  ;; Construct new bindings:
	  (let ((n2
		 (foldl
		  (lambda (body gn)
		    (let* ([svars (cdr (assq gn groups))]
			   [svar (car svars)] )
		      (cond [(and (null? (cdr svars))
				  (not (memq svar (cdr (assq svar graph)))) )
			     (set! optimized (cons svar optimized))
			     (make-node 'let svars (list (cdr (assq svar valmap)) body)) ]
			    [else
			     (foldr
			      (lambda (var rest)
				(make-node
				 'let (list var)
				 (list (make-node '##core#undefined '() '()) rest) ) )
			      (foldr
			       (lambda (var rest)
				 (make-node
				  'let (list (gensym))
				  (list (make-node 'set! (list var) (list (cdr (assq var valmap))))
					rest) ) )
			       body
			       svars)
			      svars) ] ) ) )
		  body
		  sgraph) ) )
	    (cond [(pair? optimized)
		   (debugging 'o "converted assignments to bindings" optimized)
		   (values n2 #t) ]
		  [else (values n2 #f)] ) ) ) ) ) ) )


;;;; Rewrite named calls to more primitive forms:

(define substitution-table (make-vector 301 '()))

(define (rewrite name . class-and-args)
  (let ((old (or (hash-table-ref substitution-table name) '())))
    (hash-table-set! substitution-table name (append old (list class-and-args)))))

(define (simplify-named-call db may-rewrite params name cont
			     class classargs callargs)
  (define (argc-ok? argc)
    (or (not argc)
	(and (fixnum? argc)
	     (fx= argc (length callargs)))
	(and (pair? argc)
	     (argc-ok? (car argc))
	     (argc-ok? (cdr argc)))))

  (define (defarg x)
    (cond ((symbol? x) (varnode x))
	  ((and (pair? x) (eq? 'quote (car x))) (qnode (cadr x)))
	  (else (qnode x))))

  (case class

    ;; (eq?/eqv?/equal? <var> <var>) -> (quote #t)
    ;; (eq?/eqv?/equal? ...) -> (##core#inline <iop> ...)
    ((1) ; classargs = (<argc> <iop>)
     (and (intrinsic? name)
	  (or (and (= (length callargs) (first classargs))
		   (let ((arg1 (first callargs))
			 (arg2 (second callargs)) )
		     (and (eq? '##core#variable (node-class arg1))
			  (eq? '##core#variable (node-class arg2))
			  (equal? (node-parameters arg1) (node-parameters arg2))
			  (make-node '##core#call (list #t) (list cont (qnode #t))) ) ) )
	      (and may-rewrite
		   (make-node
		    '##core#call (list #t) 
		    (list cont (make-node '##core#inline (list (second classargs)) callargs)) ) ) ) ) )

    ;; (<op> ...) -> (##core#inline <iop> ...)
    ((2) ; classargs = (<argc> <iop> <safe>)
     ;; - <safe> by be 'specialized (see rule #16 below)
     (and may-rewrite
	  (= (length callargs) (first classargs))
	  (intrinsic? name)
	  (or (third classargs) unsafe)
	  (let ((arg1 (first callargs)))
	    (make-node
	     '##core#call (list #t)
	     (list 
	      cont
	      (make-node '##core#inline (list (second classargs)) callargs) ) ) ) ) )

    ;; (<op> ...) -> <var>
    ((3) ; classargs = (<var> <argc>)
     ;; - <argc> may be #f
     (and may-rewrite
	  (intrinsic? name)
	  (or (not (second classargs)) (= (length callargs) (second classargs)))
	  (foldr
	   (lambda (val body)
	     (make-node 'let (list (gensym)) (list val body)) )
	   (make-node '##core#call (list #t) (list cont (varnode (first classargs))))
	   callargs)))

    ;; (<op> a b) -> (<primitiveop> a (quote <i>) b)
    ((4) ; classargs = (<primitiveop> <i>)
     (and may-rewrite
	  unsafe
	  (= 2 (length callargs))
	  (intrinsic? name)
	  (make-node '##core#call (list #f (first classargs))
		     (list (varnode (first classargs))
			   cont
			   (first callargs)
			   (qnode (second classargs))
			   (second callargs) ) ) ) )

    ;; (<op> a) -> (##core#inline <iop> a (quote <x>))
    ((5) ; classargs = (<iop> <x> <numtype>)
     ;; - <numtype> may be #f
     (and may-rewrite
	  (intrinsic? name)
	  (= 1 (length callargs))
	  (let ((ntype (third classargs)))
	    (or (not ntype) (eq? ntype number-type)) )
	  (make-node '##core#call (list #t)
		     (list cont
			   (make-node '##core#inline (list (first classargs))
				      (list (first callargs)
					    (qnode (second classargs)) ) ) ) ) ) )

    ;; (<op> a) -> (##core#inline <iop1> (##core#inline <iop2> a))
    ((6) ; classargs = (<iop1> <iop2> <safe>)
      (and (or (third classargs) unsafe)
	   may-rewrite
	   (= 1 (length callargs))
	   (intrinsic? name)
	   (make-node '##core#call (list #t)
		      (list cont
			    (make-node '##core#inline (list (first classargs))
				       (list (make-node '##core#inline (list (second classargs))
							callargs) ) ) ) ) ) )

    ;; (<op> ...) -> (##core#inline <iop> ... (quote <x>))
    ((7) ; classargs = (<argc> <iop> <x> <safe>)
     (and (or (fourth classargs) unsafe)
	  may-rewrite
	  (= (length callargs) (first classargs))
	  (intrinsic? name)
	  (make-node '##core#call (list #t)
		     (list cont
			   (make-node '##core#inline (list (second classargs))
				      (append callargs
					      (list (qnode (third classargs))) ) ) ) ) ) )

    ;; (<op> ...) -> <<call procedure <proc> with <classargs>, <cont> and <callargs> >>
    ((8) ; classargs = (<proc> ...)
     (and may-rewrite
	  (intrinsic? name)
	  ((first classargs) db classargs cont callargs) ) )

    ;; (<op> <x1> ...) -> (##core#inline "C_and" (##core#inline <iop> <x1> <x2>) ...)
    ;; (<op> [<x>]) -> (quote #t)
    ((9) ; classargs = (<iop-fixnum> <iop-flonum> <fixnum-safe> <flonum-safe>)
     (and may-rewrite
	  (intrinsic? name)
	  (if (< (length callargs) 2)
	      (make-node '##core#call (list #t) (list cont (qnode #t)))
	      (and (or (and unsafe (not (eq? number-type 'generic)))
		       (and (eq? number-type 'fixnum) (third classargs))
		       (and (eq? number-type 'flonum) (fourth classargs)) )
		   (let* ((names (map (lambda (z) (gensym)) callargs))
			  (vars (map varnode names)) )
		     (let loop ((callargs callargs)
				(names names))
		       (if (null? callargs)
			   (make-node
			    '##core#call (list #t)
			    (list 
			     cont
			     (let ((op (list
					(if (eq? number-type 'fixnum)
					    (first classargs)
					    (second classargs) ) ) ) )
			       (fold-boolean
				(lambda (x y) (make-node '##core#inline op (list x y))) 
				vars) ) ) )
			   (make-node 'let 
				      (list (car names))
				      (list (car callargs)
					    (loop (cdr callargs) (cdr names)))))))))))

    ;; (<op> a [b]) -> (<primitiveop> a (quote <i>) b)
    ((10) ; classargs = (<primitiveop> <i> <bvar> <safe>)
     (and may-rewrite
	  (or (fourth classargs) unsafe)
	  (intrinsic? name)
	  (let ((n (length callargs)))
	    (and (< 0 n 3)
		 (make-node '##core#call (list #f (first classargs))
			    (list (varnode (first classargs))
				  cont
				  (first callargs)
				  (qnode (second classargs))
				  (if (null? (cdr callargs))
				      (varnode (third classargs))
				      (second callargs) ) ) ) ) ) ) )

    ;; (<op> ...) -> (<primitiveop> ...)
    ((11) ; classargs = (<argc> <primitiveop> <safe>)
     ;; <argc> may be #f.
     (and may-rewrite
	  (or (third classargs) unsafe)
	  (intrinsic? name)
	  (let ((argc (first classargs)))
	    (and (or (not argc)
		     (= (length callargs) (first classargs)) )
		 (make-node '##core#call (list #t (second classargs))
			    (cons* (varnode (second classargs))
				   cont
				   callargs) ) ) ) ) )

    ;; (<op> a) -> a
    ;; (<op> ...) -> (<primitiveop> ...)
    ((12) ; classargs = (<primitiveop> <safe> <maxargc>)
     (and may-rewrite
	  (intrinsic? name)
	  (or (second classargs) unsafe)
	  (let ((n (length callargs)))
	    (and (<= n (third classargs))
		 (case n
		   ((1) (make-node '##core#call (list #t) (cons cont callargs)))
		   (else (make-node '##core#call (list #t (first classargs))
				    (cons* (varnode (first classargs))
					   cont callargs) ) ) ) ) ) ) )

    ;; (<op> ...) -> ((##core#proc <primitiveop>) ...)
    ((13) ; classargs = (<argc> <primitiveop> <safe>)
     ;; - <argc> may be #f for any number of args, or a pair specifying a range
     (and may-rewrite
	  (intrinsic? name)
	  (or (third classargs) unsafe)
	  (argc-ok? (first classargs))
	  (let ((pname (second classargs)))
	    (make-node '##core#call (if (pair? params) (cons #t (cdr params)) params)
		       (cons* (make-node '##core#proc (list pname #t) '())
			      cont callargs) ) ) ) )

    ;; (<op> <x> ...) -> (##core#inline <iop-safe>/<iop-unsafe> <x> ...)
    ((14) ; classargs = (<numtype> <argc> <iop-safe> <iop-unsafe>)
     (and may-rewrite
	  (= (second classargs) (length callargs))
	  (intrinsic? name)
	  (eq? number-type (first classargs))
	  (or (fourth classargs) unsafe)
	  (make-node
	   '##core#call (list #t)
	   (list cont
		 (make-node
		  '##core#inline
		  (list (if unsafe (fourth classargs) (third classargs)))
		  callargs) ) ) ) )

    ;; (<op> <x>) -> (<primitiveop> <x>)   - if numtype1
    ;;             | <x>                   - if numtype2
    ((15) ; classargs = (<numtype1> <numtype2> <primitiveop> <safe>)
     (and may-rewrite
	  (= 1 (length callargs))
	  (or unsafe (fourth classargs))
	  (intrinsic? name)
	  (cond ((eq? number-type (first classargs))
		 (make-node '##core#call (list #t (third classargs))
			    (cons* (varnode (third classargs)) cont callargs) ) )
		((eq? number-type (second classargs))
		 (make-node '##core#call (list #t) (cons cont callargs)) )
		(else #f) ) ) )

    ;; (<alloc-op> ...) -> (##core#inline_allocate (<aiop> <words>) ...)
    ((16) ; classargs = (<argc> <aiop> <safe> <words> [<counted>])
     ;; - <argc> may be #f, saying that any number of arguments is allowed,
     ;; - <words> may be a list of two elements (the base number of words and
     ;;   the number of words per element), meaning that the words are to be
     ;;   multiplied with the number of arguments.
     ;; - <words> may also be #t, meaning that the number of words is the same as the
     ;;   number of arguments plus 1.
     ;; - if <counted> is given and true and <argc> is between 1-8, append "<count>"
     ;;   to the name of the inline routine.
     (let ((argc (first classargs))
	   (rargc (length callargs))
	   (safe (third classargs))
	   (w (fourth classargs))
	   (counted (and (pair? (cddddr classargs)) (fifth classargs))))
       (and may-rewrite
	    (or (not argc) (= rargc argc))
	    (intrinsic? name)
	    (or unsafe safe)
	    (make-node
	     '##core#call (list #t)
	     (list cont 
		   (make-node
		    '##core#inline_allocate
		    (list (if (and counted (positive? rargc) (<= rargc 8))
			      (conc (second classargs) rargc)
			      (second classargs) )
			  (cond ((eq? #t w) (add1 rargc))
				((pair? w) (+ (car w)
					      (* rargc (cadr w))))
				(else w) ) )
		    callargs) ) ) ) ) )

    ;; (<op> ...) -> (##core#inline <iop>/<unsafe-iop> ...)
    ((17) ; classargs = (<argc> <iop-safe> [<iop-unsafe>])
     (and may-rewrite
	  (= (length callargs) (first classargs))
	  (intrinsic? name)
	  (make-node
	   '##core#call (list #t)
	   (list cont
		 (make-node '##core#inline
			    (list (if (and unsafe (pair? (cddr classargs)))
				      (third classargs)
				      (second classargs) ) )
			    callargs)) ) ) )

    ;; (<op>) -> (quote <null>)
    ((18) ; classargs = (<null>)
     (and may-rewrite
	  (null? callargs)
	  (intrinsic? name)
	  (make-node '##core#call (list #t) (list cont (qnode (first classargs))) ) ) )

    ;; (<op> <x1> ... <xn>) -> (<op> (<op> <x1> ...) <xn>) [in CPS]
    ((19)
     (and may-rewrite
	  (intrinsic? name)
	  (> (length callargs) 2)
	  (let ((callargs (reverse callargs)))
	    (let lp ((xn (car callargs))
		     (xn-1 (cadr callargs))
		     (rest (cddr callargs))
		     (cont cont))
	      (if (null? rest)
		  (make-node
		   '##core#call (list #t)
		   (list (varnode name) cont xn-1 xn))
		  (let ((r (gensym 'r))
			(id (gensym 'va)))
		    (make-node
		     'let (list id)
		     (list
		      (make-node
		       '##core#lambda (list id #t (list r) 0)
		       (list (make-node
			      '##core#call (list #t)
			      (list (varnode name) cont (varnode r) xn))))
		      (lp xn-1
			  (car rest)
			  (cdr rest)
			  (varnode id))))))))))

    ;; (<op> ...) -> (##core#inline <iop> <arg1> ... (quote <x>) <argN>)
    ((20) ; classargs = (<argc> <iop> <x> <safe>)
     (let ((n (length callargs)))
       (and (or (fourth classargs) unsafe)
	    may-rewrite
	    (= n (first classargs))
	    (intrinsic? name)
	    (make-node
	     '##core#call (list #t)
	     (list cont
		   (make-node 
		    '##core#inline (list (second classargs))
		    (let-values (((head tail) (split-at callargs (sub1 n))))
		      (append head
			      (list (qnode (third classargs)))
			      tail) ) ) ) ) ) ) )

    ;; (<op>) -> <id>
    ;; (<op> <x>) -> <x>
    ;; (<op> <x1> ...) -> (##core#inline_allocate (<genop> <words>) <x1> (##core#inline_allocate (<genop> <words>) ...))
    ;; (<op> <x1> ...) -> (##core#inline <[u]fixop> <x1> (##core#inline <[u]fixop> ...)) [fixnum-mode (perhaps unsafe)]
    ;; - Remove "<id>" from arguments.
    ((21) ; classargs = (<id> <fixop> <ufixop> <genop> <words>)
     (and may-rewrite
	  (intrinsic? name)
	  (let* ((id (first classargs))
		 (words (fifth classargs))
		 (genop (fourth classargs))
		 (fixop (if unsafe (third classargs) (second classargs)))
		 (callargs 
		  (filter
		   (lambda (x)
		     (not (and (eq? 'quote (node-class x))
			       (eq? id (first (node-parameters x))) ) ) )
		   callargs) ) )
	    (cond ((null? callargs) (make-node '##core#call (list #t) (list cont (qnode id))))
		  ((null? (cdr callargs))
		   (make-node '##core#call (list #t) (list cont (first callargs))) )
		  (else
		   (make-node
		    '##core#call (list #t)
		    (list
		     cont
		     (fold-inner
		      (lambda (x y)
			(if (eq? number-type 'fixnum)
			    (make-node '##core#inline (list fixop) (list x y))
			    (make-node '##core#inline_allocate (list genop words) (list x y)) ) )
		      callargs) ) ) ) ) ) ) )

    ;; (<alloc-op> ...) -> (##core#inline_allocate (<aiop> <words>) ...)
    ;; (<alloc-op> ...) -> (##core#inline <fxop> ...) [fixnum mode]
    ((22) ; classargs = (<argc> <aiop> <safe> <words> <fxop>)
     (let ((argc (first classargs))
	   (rargc (length callargs))
	   (w (fourth classargs)) )
       (and may-rewrite
	    (= rargc argc)
	    (intrinsic? name)
	    (or (third classargs) unsafe)
	    (make-node
	     '##core#call (list #t)
	     (list cont 
		   (if (eq? number-type 'fixnum)
		       (make-node
			'##core#inline
			(list (fifth classargs))
			callargs)
		       (make-node
			'##core#inline_allocate
			(list (second classargs) w)
			callargs) ) ) ) ) ) )

    ;; (<op> <arg1> ... <argN>) -> (<primitiveop> ...)
    ;; (<op> <arg1> ... <argN-I> <defargN-I>) -> (<primitiveop> ...)
    ;; - default args in classargs should be either symbol or (optionally) 
    ;;   quoted literal
    ((23) ; classargs = (<minargc> <primitiveop> <literal1>|<varable1> ...)
     (and may-rewrite
	  (intrinsic? name)
	  (let ([argc (first classargs)])
	    (and (>= (length callargs) (first classargs))
		 (make-node 
		  '##core#call (list #t (second classargs))
		  (cons*
		   (varnode (second classargs))
		   cont
		   (let-values (((req opt) (split-at callargs argc)))
		     (append
		      req
		      (let loop ((ca opt) 
				 (da (cddr classargs)) )
			(cond ((null? ca)
			       (if (null? da)
				   '()
				   (cons (defarg (car da)) (loop '() (cdr da))) ) )
			      ((null? da) '())
			      (else (cons (car ca) (loop (cdr ca) (cdr da))))))))))))))

    (else (bomb "bad type (optimize)")) ) )


;;; Optimize direct leaf routines:

(define (transform-direct-lambdas! node db)
  (let ((dirty #f)
	(inner-ks '()) 
	(hoistable '()) 
	(allocated 0) )

    ;; Process node tree and walk lambdas that meet the following constraints:
    ;;  - Only external lambdas (no CPS redexes),
    ;;  - All calls are either to the direct continuation or (tail-) recursive calls.
    ;;  - No allocation, no rest parameter.
    ;;  - The lambda has a known container variable and all it's call-sites are known.
    ;;  - The lambda is not marked as a callback lambda

    (define (walk d n dn)
      (let ((params (node-parameters n))
	    (subs (node-subexpressions n)) )
	(case (node-class n)
	  ((##core#lambda)
	   (let ((llist (third params)))
	     (if (and d
		      (second params)
		      (not (db-get db d 'unknown))
		      (list? llist)
		      (and-let* ((val (db-get db d 'value))
				 (refs (db-get-list db d 'references))
				 (sites (db-get-list db d 'call-sites)) )
			;; val must be lambda, since `sites' is set
			(and (eq? n val)
			     (not (variable-mark
				   (first (node-parameters val))
				   '##compiler#callback-lambda))
			     (= (length refs) (length sites))
			     (scan (first subs) (first llist) d dn (cons d llist)) ) ) )
		 (transform n d inner-ks hoistable dn allocated) 
		 (walk #f (first subs) #f) ) ) )
	  ((set!) (walk (first params) (first subs) #f))
	  ((let)
	   (walk (first params) (first subs) n)
	   (walk #f (second subs) #f) )
	  (else (for-each (lambda (x) (walk #f x #f)) subs)) ) ) )

    (define (scan n kvar fnvar destn env)
      (let ((closures '())
	    (recursive #f) )
	(define (rec n v vn e)
	  (let ((params (node-parameters n))
		(subs (node-subexpressions n)) )
	    (case (node-class n)
	      ((##core#variable)
	       (let ((v (first params)))
		 (or (not (db-get db v 'boxed))
		     (not (memq v env))
		     (and (not recursive)
			  (begin
			    (set! allocated (+ allocated 2))
			    #t) ) ) ) )
	      ((##core#lambda)
	       (and v
		    (##sys#decompose-lambda-list
		     (third params)
		     (lambda (vars argc rest)
		       (set! closures (cons v closures))
		       (rec (first subs) #f #f (append vars e)) ) ) ) )
	      ((##core#inline_allocate)
	       (and (not recursive)
		    (begin
		      (set! allocated (+ allocated (second params)))
		      (every (lambda (x) (rec x #f #f e)) subs) ) ) )
	      ((##core#direct_lambda)
	       (and vn destn
		    (null? (scan-used-variables (first subs) e)) 
		    (begin
		      (set! hoistable (alist-cons v vn hoistable))
		      #t) ) )
	      ((##core#inline_ref)
	       (and (let ((n (estimate-foreign-result-size (second params))))
		      (or (zero? n)
			  (and (not recursive)
			       (begin
				 (set! allocated (+ allocated n))
				 #t) ) ) )
		    (every (lambda (x) (rec x #f #f e)) subs) ) )
	      ((##core#inline_loc_ref)
	       (and (let ((n (estimate-foreign-result-size (first params))))
		      (or (zero? n)
			  (and (not recursive)
			       (begin
				 (set! allocated (+ allocated n))
				 #t) ) ) )
		    (every (lambda (x) (rec x #f #f e)) subs) ) )
	      ((##core#call)
	       (let ((fn (first subs)))
		 (and (eq? '##core#variable (node-class fn))
		      (let ((v (first (node-parameters fn))))
			(cond ((eq? v fnvar)
			       (and (zero? allocated)
				    (let ((k (second subs)))
				      (when (eq? '##core#variable (node-class k))
					(set! inner-ks (cons (first (node-parameters k)) inner-ks)) )
				      (set! recursive #t)
				      #t) ) )
			      (else (eq? v kvar)) ) )
		      (every (lambda (x) (rec x #f #f e)) (cdr subs)) ) ) )
	      ((##core#direct_call)
	       (let ((n (fourth params)))
		 (or (zero? n)
		     (and (not recursive)
			  (begin
			    (set! allocated (+ allocated n))
			    (every (lambda (x) (rec x #f #f e)) subs) ) ) ) ) )
	      ((set!) (rec (first subs) (first params) #f e))
	      ((let)
	       (and (rec (first subs) (first params) n e)
		    (rec (second subs) #f #f (append params e)) ) )
	      (else (every (lambda (x) (rec x #f #f e)) subs)) ) ) )
	(set! inner-ks '())
	(set! hoistable '())
	(set! allocated 0)
	(and (rec n #f #f env)
	     (lset=/eq? closures (delete kvar inner-ks eq?)))))

    (define (transform n fnvar ks hoistable destn allocated)
      (if (pair? hoistable)
	  (debugging 'o "direct leaf routine with hoistable closures/allocation" fnvar (delay (unzip1 hoistable)) allocated)
	  (debugging 'o "direct leaf routine/allocation" fnvar allocated) )
      (set! dirty #t)
      (let* ((params (node-parameters n))
	     (argc (length (third params)))
	     (klambdas '()) 
	     (sites (db-get-list db fnvar 'call-sites))
	     (ksites '()) )
	(if (and (list? params) (= (length params) 4) (list? (caddr params)))
	    (let ((id (car params))
		  (kvar (caaddr params))
		  (vars (cdaddr params)) )
	      ;; Remove continuation argument:
	      (set-car! (cddr params) vars)
	   ;; Make "##core#direct_lambda":
	   (node-class-set! n '##core#direct_lambda)
	   ;; Transform recursive calls and remove unused continuations:

	   (let rec ([n (first (node-subexpressions n))])
	     (let ([params (node-parameters n)]
		   [subs (node-subexpressions n)] )
	       (case (node-class n)
		 [(##core#call)
		  (let* ([fn (first subs)]
			 [arg0 (second subs)]
			 [fnp (node-parameters fn)] 
			 [arg0p (node-parameters arg0)] )
		    (when (eq? '##core#variable (node-class fn))
		      (cond [(eq? fnvar (first fnp))
			     (set! ksites (alist-cons #f n ksites))
			     (cond [(eq? kvar (first arg0p))
				    (node-class-set! n '##core#recurse)
				    (node-parameters-set! n (list #t id))
				    (node-subexpressions-set! n (cddr subs)) ]
				   [(assq (first arg0p) klambdas)
				    => (lambda (a)
					 (let* ([klam (cdr a)]
						[kbody (first (node-subexpressions klam))] )
					   (node-class-set! n 'let)
					   (node-parameters-set! n (take (third (node-parameters klam)) 1))
					   (node-subexpressions-set!
					    n
					    (list (make-node '##core#recurse (list #f id) (cddr subs)) kbody) )
					   (rec kbody) ) ) ]
				   [else (bomb "missing kvar" arg0p)] ) ]
			    [(eq? kvar (first fnp))
			     (node-class-set! n '##core#return)
			     (node-parameters-set! n '())
			     (node-subexpressions-set! n (cdr subs)) ]
			    [else (bomb "bad call (leaf)")] ) ) ) ]
		 [(let)
		  (let ([var (first params)]
			[val (first subs)] )
		    (cond [(memq var ks)
			   (set! klambdas (alist-cons var val klambdas))
			   (copy-node! (second subs) n)
			   (rec n) ]
			  [else (for-each rec subs)] ) ) ]

		 [else (for-each rec subs)] ) ) )

	   ;; Transform call-sites:
	   (for-each
	    (lambda (site)
	      (let* ((n (cdr site))
		     (nsubs (node-subexpressions n))
		     (params (node-parameters n))
		     (debug-info (and (pair? (cdr params))
				      (second params))))
		(unless (= argc (length (cdr nsubs)))
		  (quit-compiling
		   "known procedure called with wrong number of arguments: `~A'"
		   fnvar) )
		(node-subexpressions-set!
		 n
		 (list (second nsubs)
		       (make-node
			'##core#direct_call
			(list #t debug-info id allocated)
			(cons (car nsubs) (cddr nsubs)) ) ) ) ) )
	    (filter (lambda (site)
		      (let ((s2 (cdr site)))
			(not (any (lambda (ksite) (eq? (cdr ksite) s2)) ksites))))
		    sites))

	   ;; Hoist direct lambdas out of container:
	   (when (and destn (pair? hoistable))
	     (let ([destn0 (make-node #f #f #f)])
	       (copy-node! destn destn0) ; get copy of container binding
	       (let ([hoisted
		      (foldr	; build cascade of bindings for each hoistable direct lambda...
		       (lambda (h rest)
			 (make-node
			  'let (list (car h))
			  (let ([dlam (first (node-subexpressions (cdr h)))])
			    (list (make-node (node-class dlam) (node-parameters dlam) (node-subexpressions dlam))
				  rest) ) ) )
		       destn0
		       hoistable) ] )
		 (copy-node! hoisted destn) ; mutate container binding to hold hoistable bindings
		 (for-each 
		  (lambda (h)		; change old direct lambdas bindings to dummy ones...
		    (let ([vn (cdr h)])
		      (node-parameters-set! vn (list (gensym)))
		      (set-car! (node-subexpressions vn) (make-node '##core#undefined '() '())) ) )
		  hoistable) ) ) ) )
	    (bomb "invalid parameter list" params))))

    (debugging 'p "direct leaf routine optimization pass...")
    (walk #f node #f)
    dirty) )


;;; turn groups of local procedures into dispatch loop ("clustering")
;
; This turns (in bodies)
;
;   :
;   (define (a x) (b x))
;   (define (b y) (a y))
;   (a z)))
;
; into something similar to
;
;   (letrec ((<dispatch>
;              (lambda (<a1> <i>)
;                (case <i>
;                  ((1) (let ((x <a1>)) (<dispatch> x 2)))
;                  ((2) (let ((y <a1>)) (<dispatch> y 1)))
;                  (else (<dispatch> z 1))))))
;     (<dispatch> #f 0))

(define (determine-loop-and-dispatch node db)
  (let ((groups '())
	(outer #f)
	(group '()))

    (define (close)			; "close" group of local definitions
      (when (pair? group)
	(when (> (length group) 1)
	  (set! groups (alist-cons outer group groups)))
	(set! group '())
	(set! outer #f)))

    (define (user-lambda? n)
      (and (eq? '##core#lambda (node-class n))
	   (list? (third (node-parameters n))))) ; no rest argument allowed

    (define (walk n e)
      (let ((subs (node-subexpressions n))
	    (params (node-parameters n)) 
	    (class (node-class n)) )
	(case class
	  ((let)
	   (let ((var (first params))
		 (val (first subs))
		 (body (second subs)))
	     (cond ((and (not outer) 
			 (eq? '##core#undefined (node-class val)))
		    ;; find outermost "(let ((VAR (##core#undefined))) ...)"
		    (set! outer n)
		    (walk body (cons var e)))
		   ((and outer
			 (eq? 'set! (node-class val))
			 (let ((sval (first (node-subexpressions val)))
			       (svar (first (node-parameters val))))
			   ;;XXX should we also accept "##core#direct_lambda" ?
			   (and (eq? '##core#lambda (node-class sval))
				(= (length (db-get-list db svar 'references))
				   (length (db-get-list db svar 'call-sites)))
				(memq svar e)
				(user-lambda? sval))))
		    ;; "(set! VAR (lambda ...))" - add to group
		    (set! group (cons val group))
		    (walk body (cons var e)))
		   (else
		    ;; other "let" binding, close group (if any)
		    (close)
		    (walk val e)
		    (walk body (cons var e))))))
	  ((##core#lambda ##core#direct_lambda)
	   (##sys#decompose-lambda-list
	    (third params)
	    (lambda (vars argc rest)
	      ;; walk recursively, with cleared cluster state
	      (fluid-let ((group '())
			  (outer #f))
		(walk (first subs) vars)))))
	  (else
	   ;; other form, close group (if any)
	   (close)
	   (for-each (cut walk <> e) subs)))))

    (debugging 'p "collecting clusters ...")

    ;; walk once and gather groups
    (walk node '())

    ;; process found clusters
    (for-each
     (lambda (g)
       (let* ((outer (car g))
	      (group (cdr g))
	      (dname (gensym 'dispatch))
	      (i (gensym 'i))
	      (n 1)
	      (bodies
	       (map (lambda (assign)
		      ;; collect information and replace assignment
		      ;; with "(##core#undefined)"
		      (let* ((name (first (node-parameters assign)))
			     (proc (first (node-subexpressions assign)))
			     (pparams (node-parameters proc))
			     (llist (third pparams))
			     (aliases (map gensym llist)))
			(##sys#decompose-lambda-list
			 llist
			 (lambda (vars argc rest)
			   (let ((body (first (node-subexpressions proc)))
				 (m n))
			     (set! n (add1 n))
			     (copy-node!
			      (make-node '##core#undefined '() '())
			      assign)
			     (list name m llist body))))))
		    group))
	      (k (gensym 'k))
	      (maxargs (apply max (map (o length third) bodies)))
	      (dllist (append
		       (list-tabulate maxargs (lambda _ (gensym 'a)))
		       (list i))))

	 (debugging 'x "clustering" (map first bodies)) ;XXX

	 ;; first descend into "(let ((_ (##core#undefined))) ...)" forms
	 ;; to make them visible everywhere

	 (let descend ((outer outer))
	   ;;(print "outer: " (node-parameters outer))
	   (let ((body (second (node-subexpressions outer))))
	     (if (and (eq? 'let (node-class body))
		      (let ((val (first (node-subexpressions body))))
			(eq? '##core#undefined (node-class val))))
		 (descend body)
		 ;; wrap cluster into dispatch procedure
		 (copy-node!
		  (make-node
		   'let
		   (list dname)
		   (list
		    (make-node '##core#undefined '() '())
		    (make-node
		     'let (list (gensym))
		     (list
		      (make-node 
		       'set! (list dname)
		       (list
			(make-node
			 '##core#lambda
			 (list (gensym 'f_) #t dllist 0)
			 (list
			  ;; dispatch to cluster member or main body
			  (make-node
			   '##core#switch
			   (list (sub1 n))
			   (append
			    (list (varnode i))
			    (append-map
			     (lambda (b)
			       (list (qnode (second b))
				     (let loop ((args dllist)
						(vars (third b)))
				       (if (null? vars)
					   (fourth b)
					   (make-node
					    'let (list (car vars))
					    (list (varnode (car args))
						  (loop (cdr args) (cdr vars))))))))
			     bodies)
			    (cdr (node-subexpressions outer))))))))
		      ;; call to enter dispatch loop - the current continuation is
		      ;; not used, so the first parameter is passed as "#f" (it is
		      ;; a tail call)
		      (make-node
		       '##core#call '(#t)
		       (cons* (varnode dname)
			      (append
			       (list-tabulate maxargs (lambda _ (qnode #f)))
			       (list (qnode 0)))))))))
		  outer))))

	 ;; modify call-sites to invoke dispatch loop instead
	 (for-each
	  (lambda (b)
	    (let ((sites (db-get db (car b) 'call-sites)))
	      (for-each
	       (lambda (site)
		 (let* ((callnode (cdr site))
			(args (cdr (node-subexpressions callnode))))
		   (copy-node!
		    (make-node
		     '##core#call (node-parameters callnode)
		     (cons* (varnode dname)
			    (append
			     args
			     (list-tabulate
			      (- maxargs (length args))
			      (lambda _ (qnode #f)))
			     (list (qnode (second b))))))
		    callnode)))
	       sites)))
	  bodies)))

     groups)
    (values node (pair? groups))))
)
