;;;; lfa2.scm - a lightweight "secondary" flow analysis
;
; Copyright (c) 2012-2022, The CHICKEN Team
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


;; This pass does a lightweight flow-analysis on value types, mostly
;; to handle the case where user code performs a type-check followed
;; by inlined accessors (for example when using record structures).
;; Specialization takes place before inlining, so even though we have
;; the type-information, later inlining will still keep the code for
;; checking argument types. Additionally, this pass detects unboxing
;; opportunities for floating point values and replaces uses of certain
;; fp operations with unboxed ones.


(declare
  (unit lfa2)
  (uses extras support))

(module chicken.compiler.lfa2
    (perform-secondary-flow-analysis perform-unboxing)

(import scheme
	chicken.base
	chicken.compiler.support
	chicken.fixnum
	chicken.format
	chicken.keyword)

(include "tweaks")
(include "mini-srfi-1.scm")


;;; Maps checks to types

(define +type-check-map+
  '(("C_i_check_closure" procedure)
    ("C_i_check_exact" fixnum bignum integer ratnum) ;; DEPRECATED
    ("C_i_check_inexact" float)	; Or an inexact cplxnum...
    ("C_i_check_number" fixnum integer bignum ratnum float cplxnum number)
    ("C_i_check_string" string)
    ("C_i_check_bytevector" blob)
    ("C_i_check_symbol" symbol)
    ("C_i_check_keyword" keyword)
    ("C_i_check_list" null pair list)
    ("C_i_check_pair" pair)
    ("C_i_check_locative" locative)
    ("C_i_check_boolean" boolean)
    ("C_i_check_vector" vector)
    ("C_i_check_structure" *struct*)	; special case
    ("C_i_check_char" char)
    ("C_i_check_closure_2" procedure)
    ("C_i_check_exact_2" fixnum bignum integer ratnum) ;; DEPRECATED
    ("C_i_check_inexact_2" float)	; Or an inexact cplxnum...
    ("C_i_check_number_2" fixnum integer bignum ratnum float cplxnum number)
    ("C_i_check_string_2" string)
    ("C_i_check_bytevector_2" blob)
    ("C_i_check_symbol_2" symbol)
    ("C_i_check_keyword_2" keyword)
    ("C_i_check_list_2" null pair list)
    ("C_i_check_pair_2" pair)
    ("C_i_check_locative_2" locative)
    ("C_i_check_boolean_2" boolean)
    ("C_i_check_vector_2" vector)
    ("C_i_check_structure_2" *struct*)	; special case
    ("C_i_check_char_2" char)))


;; Maps predicates to types
 
(define +predicate-map+
  '(("C_i_closurep" procedure)
    ("C_fixnump" fixnum)
    ("C_bignump" bignum)
    ("C_i_exact_integerp" integer fixnum bignum)
    ("C_i_flonump" float)
    ("C_i_numberp" number fixnum integer bignum ratnum float cplxnum)
    ("C_i_ratnump" ratnum)
    ("C_i_cplxnump" cplxnum)
    ("C_stringp" string)
    ("C_bytevectorp" blob)
    ("C_i_keywordp" keyword)
    ("C_i_symbolp" symbol)
    ("C_i_listp" list)
    ("C_i_pairp" pair)
    ("C_locativep" locative)
    ("C_booleanp" boolean)
    ("C_i_vectorp" vector)
    ("C_structurep" struct)
    ("C_i_structurep" *struct*)		; special case
    ("C_charp" char)
    ("C_i_portp" port)
    ("C_i_nullp" null)))

;; Maps foreign type checks to types

(define +ffi-type-check-map+
  '(("C_i_foreign_fixnum_argumentp" fixnum)
    ("C_i_foreign_integer_argumentp" integer fixnum bignum)
    ("C_i_foreign_char_argumentp" char)
    ("C_i_foreign_flonum_argumentp" float)
    ("C_i_foreign_string_argumentp" string)
    ("C_i_foreign_symbol_argumentp" symbol)))

;; Maps constructors to types

(define +constructor-map+
  '(("C_a_i_record1" *struct*)		; special case
    ("C_a_i_record2" *struct*)
    ("C_a_i_record3" *struct*)
    ("C_a_i_record4" *struct*)
    ("C_a_i_record5" *struct*)
    ("C_a_i_record6" *struct*)
    ("C_a_i_record7" *struct*)
    ("C_a_i_record8" *struct*)
    ("C_a_i_record" *struct*)
    ("C_a_i_string" string)
    ("C_a_i_port" port)
    ("C_a_i_vector1" vector)
    ("C_a_i_vector2" vector)
    ("C_a_i_vector3" vector)
    ("C_a_i_vector4" vector)
    ("C_a_i_vector5" vector)
    ("C_a_i_vector6" vector)
    ("C_a_i_vector7" vector)
    ("C_a_i_vector8" vector)
    ("C_a_pair" pair)
    ("C_a_i_bytevector" blob)
    ("C_a_i_make_locative" locative)
    ("C_a_i_vector" vector)
    ("C_a_i_list1" pair)
    ("C_a_i_list2" pair)
    ("C_a_i_list3" pair)
    ("C_a_i_list4" pair)
    ("C_a_i_list5" pair)
    ("C_a_i_list6" pair)
    ("C_a_i_list7" pair)
    ("C_a_i_list8" pair)
    ("C_a_i_cons" pair)
    ("C_a_i_flonum" float)
    ("C_a_i_fix_to_flo" float)
    ("C_a_i_big_to_flo" float)
    ("C_a_i_fix_to_big" bignum)
    ("C_a_i_bignum0" bignum)
    ("C_a_i_bignum1" bignum)
    ("C_a_i_bignum2" bignum)
    ("C_a_i_flonum_abs" float)
    ("C_a_i_flonum_acos" float)
    ("C_a_i_flonum_acosh" float)
    ("C_a_i_flonum_actual_quotient_checked" float)
    ("C_a_i_flonum_asin" float)
    ("C_a_i_flonum_asinh" float)
    ("C_a_i_flonum_atan2" float)
    ("C_a_i_flonum_atan" float)
    ("C_a_i_flonum_atanh" float)
    ("C_a_i_flonum_ceiling" float)
    ("C_a_i_flonum_cos" float)
    ("C_a_i_flonum_cosh" float)
    ("C_a_i_flonum_difference" float)
    ("C_a_i_flonum_exp" float)
    ("C_a_i_flonum_expt" float)
    ("C_a_i_flonum_floor" float)
    ("C_a_i_flonum_gcd" float)
    ("C_a_i_flonum_log" float)
    ("C_a_i_flonum_modulo_checked" float)
    ("C_a_i_flonum_negate" float)
    ("C_a_i_flonum_plus" float)
    ("C_a_i_flonum_quotient_checked" float)
    ("C_a_i_flonum_quotient" float)
    ("C_a_i_flonum_remainder_checked" float)
    ("C_a_i_flonum_round" float)
    ("C_a_i_flonum_round_proper" float)
    ("C_a_i_flonum_sin" float)
    ("C_a_i_flonum_sinh" float)
    ("C_a_i_flonum_sqrt" float)
    ("C_a_i_flonum_tan" float)
    ("C_a_i_flonum_tanh" float)
    ("C_a_i_flonum_times" float)
    ("C_a_i_flonum_multiply_add" float)
    ("C_a_i_flonum_truncate" float)
    ("C_a_u_i_f64vector_ref" float)
    ("C_a_u_i_f32vector_ref" float)
    ;;XXX are there more?
    ))

(define +unboxed-map+
  '(("C_a_i_flonum_plus" "C_ub_i_flonum_plus" op)
    ("C_a_i_flonum_difference" "C_ub_i_flonum_difference" op)
    ("C_a_i_flonum_times" "C_ub_i_flonum_times" op)
    ("C_a_i_flonum_multiply_add" "C_ub_i_flonum_multiply_add" op)
    ("C_a_i_flonum_quotient" "C_ub_i_flonum_quotient" op)
    ("C_flonum_equalp" "C_ub_i_flonum_equalp" pred)
    ("C_flonum_greaterp" "C_ub_i_flonum_greaterp" pred)
    ("C_flonum_lessp" "C_ub_i_flonum_lessp" pred)
    ("C_flonum_greater_or_equal_p" "C_ub_i_flonum_greater_or_equal_p" pred)
    ("C_flonum_less_or_equal_p" "C_ub_i_flonum_less_or_equal_p" pred)
    ("C_u_i_flonum_nanp" "C_ub_i_flonum_nanp" pred)
    ("C_u_i_flonum_infinitep" "C_ub_i_flonum_infinitep" pred)
    ("C_u_i_flonum_finitepp" "C_ub_i_flonum_finitep" pred)
    ("C_a_i_flonum_sin" "C_sin" op)
    ("C_a_i_flonum_cos" "C_cos" op)
    ("C_a_i_flonum_tan" "C_tan" op)
    ("C_a_i_flonum_asin" "C_asin" op)
    ("C_a_i_flonum_acos" "C_acos" op)
    ("C_a_i_flonum_atan" "C_atan" op)
    ("C_a_i_flonum_atan2" "C_atan2" op)
    ("C_a_i_flonum_sinh" "C_sinh" op)
    ("C_a_i_flonum_cosh" "C_cosh" op)
    ("C_a_i_flonum_tanh" "C_tanh" op)
    ("C_a_i_flonum_asinh" "C_asinh" op)
    ("C_a_i_flonum_acosh" "C_acosh" op)
    ("C_a_i_flonum_atanh" "C_atanh" op)
    ("C_a_i_flonum_exp" "C_exp" op)
    ("C_a_i_flonum_expr" "C_pow" op)
    ("C_a_i_flonum_log" "C_log" op)
    ("C_a_i_flonum_sqrt" "C_sqrt" op)
    ("C_a_i_flonum_truncate" "C_trunc" op)
    ("C_a_i_flonum_ceiling" "C_ceil" op)
    ("C_a_i_flonum_floor" "C_floor" op)
    ("C_a_i_flonum_round" "C_round" op)
    ("C_a_i_flonum_abs" "C_fabs" op)
    ("C_a_u_i_f32vector_ref" "C_ub_i_f32vector_ref" acc)
    ("C_a_u_i_f64vector_ref" "C_ub_i_f64vector_ref" acc)))


;;; Walk nodes and perform simplified type-analysis

(define (perform-secondary-flow-analysis node db)
  (let ((stats '())
        (floatvars '()))

    (define (constant-result lit) 
      ;; a simplified variant of the one in scrutinizer.scm
      (cond ((string? lit) 'string)
	    ((keyword? lit) 'keyword)
	    ((symbol? lit) 'symbol)
	    ;; Do not assume fixnum width matches target platforms!
	    ((or (big-fixnum? lit) (small-bignum? lit)) 'integer)
	    ((fixnum? lit) 'fixnum)
	    ((bignum? lit) 'bignum)
	    ((flonum? lit) 'float)
	    ((ratnum? lit) 'ratnum)
	    ((cplxnum? lit) 'cplxnum)
	    ((boolean? lit) 'boolean)
	    ((null? lit) 'null)
	    ((list? lit) 'list)
	    ((pair? lit) 'pair)
	    ((eof-object? lit) 'eof)
	    ;; TODO: Remove once we have a bootstrapping libchicken with bwp-object?
	    ((##core#inline "C_bwpp" lit) #;(bwp-object? lit) 'bwp)
	    ((vector? lit) 'vector)
	    ((and (not (##sys#immediate? lit)) (##sys#generic-structure? lit))
	     `(struct ,(##sys#slot lit 0)))
	    ((char? lit) 'char)
	    (else '*)))
    
    (define (merge t1 t2)
      (cond ((eq? t1 t2) t1)
            ((and (pair? t1) (pair? t2)
                  (eq? (car t1) 'struct)
                  (eq? (car t2) 'struct)
                  (eq? (cadr t1) (cadr t2)))
             t1)
            (else '*)))

    (define (report elim)
      (cond ((assoc elim stats) =>
	     (lambda (a) (set-cdr! a (add1 (cdr a)))))
	    (else (set! stats (alist-cons elim 1 stats)))))
 
    (define (assigned? var)
      (db-get db var 'assigned))

    (define (droppable? n)
      (or (memq (node-class n) 
		'(quote ##core#undefined ##core#primitive ##core#lambda))
	  (and (eq? '##core#variable (node-class n))
	       (let ((var (first (node-parameters n))))
		 (or (not (db-get db var 'global))
		     (variable-mark var '##compiler#always-bound))))))

    (define (drop! n)
      (sub-boxed n)
      (node-class-set! n '##core#undefined)
      (node-parameters-set! n '())
      (node-subexpressions-set! n '()))

    (define (extinguish! node rpl)	; replace ##core#inline call
      (report (first (node-parameters node)))
      (let ((subs (node-subexpressions node))
	    (alldropped #t))
	(for-each
	 (lambda (sn)
	   (if (droppable? sn)
	       (drop! sn)
	       (set! alldropped #f)))
	 subs)
	(if alldropped
	    (drop! node)
	    (node-parameters-set!
	     node
	     (list
	      (string-append
	       rpl
	       (case (length (node-subexpressions node))
		 ((1) "1")
		 ((2) "2")
		 ((3) "3")
		 (else (bomb "bad number of arguments to extinguished ##core#inline")))))))))

    (define (vartype v te ae)
      (cond ((assq v te) => cdr)
	    (else
	     (let loop ((ae ae))
	       (cond ((null? ae) '*)
		     ((and (eq? v (cdar ae)) 
			   (assq (caar ae) te) )
		      => cdr)
		     (else (loop (cdr ae))))))))

    (define (varnode? n)
      (eq? '##core#variable (node-class n)))

    (define (floatvar? var)
      (assq var floatvars))

    (define (eliminate-floatvar var)
      (set! floatvars
        (remove (lambda (a) (eq? var (car a))) floatvars)))

    (define (count-floatvar node acc #!optional (n 1))
      (cond ((and (varnode? node)
                  (assq (first (node-parameters node)) floatvars))
             =>
             (lambda (a)
               (set-car! (acc a) (+ n (car (acc a))))))))

    (define (add-boxed node) (count-floatvar node cdr))
    (define (add-unboxed node) (count-floatvar node cddr))
    (define (sub-boxed node) (count-floatvar node cdr -1))

    (define (walk n te ae)
      (let ((class (node-class n))
	    (params (node-parameters n))
	    (subs (node-subexpressions n)))
	(case class
	  ((##core#variable)
           (when (and (floatvar? (first params))
                      (not (assq (first params) te)))
             (eliminate-floatvar (first params)))
           (add-boxed n)
	   (vartype (first params) te ae))
	  ((if ##core#cond) 
	   (let ((tr (walk (first subs) te ae)))
	     (if (and (pair? tr) (eq? 'boolean (car tr)))
                 (merge (walk (second subs)
                              (append (second tr) te)
                              ae)
                        (walk (third subs)
                              (append (third tr) te)
                              ae)))
                 (merge (walk (second subs) te ae)
                        (walk (third subs) te ae))))
	  ((quote) (constant-result (first params)))
	  ((let)
	   (let* ((val (first subs))
		  (var (first params))
		  (r (walk val te ae))
                  (avar (assigned? var)))
             (cond ((and (not avar)
                         (eq? 'float r)
                         (not (floatvar? var)))
                    (set! floatvars (cons (list var 0 0) floatvars))
                    (add-unboxed val))
                   (else (add-boxed val)))
             (walk (second subs)
		   (if avar
		       te
		       (alist-cons var r te))
		   (if (and (varnode? val)
			    (not avar)
			    (not (assigned? (first (node-parameters val)))))
		       (let ((var2 (first (node-parameters val))))
			 (alist-cons var var2 (alist-cons var2 var ae)))
		       ae))))
	  ((##core#lambda ##core#direct_lambda)
	   ;; fresh env and we don't bother to create entries in the environment
	   ;; for the llist-bound variables (missing implies type '*)
	   ;;XXX (but we could treat the first arg in non-CPS lambdas as procedure...)
	   (walk (first subs) '() '())
	   'procedure)
	  ((set! ##core#set!)	       ;XXX is ##core#set! still used?
           (let ((val (first subs)))
             (when (and (varnode? val)
                        (floatvar? (first (node-parameters val))))
               (eliminate-floatvar (first (node-parameters val))))
             (walk val te ae)
             'undefined))
	  ((##core#undefined) 'undefined)
	  ((##core#primitive) 'procedure)
	  ((##core#inline ##core#inline_allocate)
           (let ((ubop (assoc (first params) +unboxed-map+)))
             (for-each
               (lambda (arg)
                 (walk arg te ae)
                 (when ubop (add-unboxed arg)))
               subs))
	   (cond ((assoc (first params) +type-check-map+) =>
		  (lambda (a)
		    (let ((r1 (walk (first subs) te ae)))
		      (cond (unsafe
			     (extinguish! n "C_i_noop"))
			    ((eq? '*struct* (cadr a))
			     ;; handle known structure type
			     (when (and (pair? r1)
					(eq? 'struct (first r1))
					(eq? 'quote (node-class (second subs))))
			       (let ((st (first (node-parameters (second subs)))))
				 (when (and (symbol? st)
					    (eq? st (second r1)))
				   (extinguish! n "C_i_noop")))))
			    ((and (pair? r1) (eq? 'boolean (car r1)))
			     (when (memq 'boolean (cdr a))
			       (extinguish! n "C_i_noop")))
			    ;; handle other types
			    ((member r1 (cdr a))
			     (extinguish! n "C_i_noop")))
		      '*)))
		 ((assoc (first params) +ffi-type-check-map+) =>
		  (lambda (a)
		    (let* ((arg (first subs))
                           (r1 (walk arg te ae)))
		      (when (member r1 (cdr a))
                        (node-class-set! n (node-class arg))
                        (node-parameters-set! n (node-parameters arg))
	       	        (node-subexpressions-set! n (node-subexpressions arg)))
                      ;; the ffi checks are enforcing so we always end up with
		      ;; the correct type
		      r1)))
		 ((assoc (first params) +predicate-map+) =>
		  (lambda (a)
		    (let ((arg (first subs)))
		      (cond ((varnode? arg)
			      `(boolean
				((,(first (node-parameters arg))
				  .
				  ,(if (eq? '*struct* (cadr a))
				       (if (eq? 'quote (node-class (second subs)))
					   (let ((st (first
						       (node-parameters
							   (second subs)))))
					     (if (symbol? st)
						 `(struct ,st)
						 'struct))
					    'struct)
					(cadr a))))
				()))
			    (else
			      (let ((r1 (walk arg te ae)))
				(cond ((eq? '*struct* (cadr a))
				       ;; known structure type
				       (when (and (pair? r1)
						  (eq? 'struct (first r1))
						  (eq? 'quote (node-class (second subs))))
					 (let ((st (first
						    (node-parameters (second subs)))))
					   (when (and (symbol? st)
						      (eq? st (second r1)))
					     (extinguish! n "C_i_true")))))
				      ((and (pair? r1) (eq? 'boolean (car r1)))
				       (when (memq 'boolean (cdr a))
					 (extinguish! n "C_i_true")))
				      ;; other types
				      ((member r1 (cdr a))
					(extinguish! n "C_i_true")))
				'boolean))))))
		 ((assoc (first params) +constructor-map+) =>
		  (lambda (a)
		    (let ((arg1 (and (pair? subs) (first subs))))
		      (if (and arg1
			       (eq? '*struct* (cadr a))
			       (eq? 'quote (node-class arg1)))
			  (let ((tag (first (node-parameters arg1))))
			    (if (symbol? tag)
				`(struct ,tag)
				'struct))
			  (cadr a)))))))
	  (else 
	   (for-each (cut walk <> te ae) subs)
	   '*))))

    (walk node '() '())
    (when (pair? stats)
      (with-debugging-output
       '(x o)
       (lambda ()
	 (print "eliminated type checks:")
	 (for-each 
	  (lambda (ss) (printf "  ~a:\t~a~%" (car ss) (cdr ss)))
	  stats))))
    floatvars))


(define (perform-unboxing node floatvar-counts)
  (let ((floatvars (filter-map
		     (lambda (a)
		       (and (= (cadr a) (caddr a))
			    (car a)))
		     floatvar-counts))
	(count 0))

    (define (walk/unbox n)
      (let ((class (node-class n))
	    (params (node-parameters n))
	    (subs (node-subexpressions n)))
	(case class
	  ((quote)
	   (let ((c (first params)))
	     (if (##core#inline "C_i_flonump" c)
		 (make-node '##core#float (list c) '())
		 n)))
	  ((##core#variable)
	   (let ((i (posq (first params) floatvars)))
	     (if i
		 (make-node '##core#float-variable (cons i params) '())
		 (make-node '##core#unbox_float '() (list n)))))
	  ((##core#inline ##core#inline_allocate)
	   (cond ((assoc (first params) +unboxed-map+) =>
		  (lambda (a)
		    (let ((ub (second a))
			  (type (third a)))
		      (set! count (add1 count))
		      (make-node '##core#inline
				 (list ub)
				 (map (if (eq? type 'op)
					  walk/unbox
					  walk)
				   subs)))))
		 (else
		   (make-node '##core#unbox_float '()
			      (list (make-node class params
					       (map walk subs)))))))
	  (else (make-node '##core#unbox_float '() (list (walk n)))))))

    (define (walk n)
      (let ((class (node-class n))
	    (params (node-parameters n))
	    (subs (node-subexpressions n)))
	(case class
	  ((##core#variable)
	   (let ((i (posq (first params) floatvars)))
	     (if i
		 (make-node '##core#box_float '()
			    (list (make-node '##core#float-variable
					     (cons i params) '())))
		 n)))
	  ((let)
	   (let* ((val (first subs))
		  (var (first params))
		  (i (posq var floatvars)))
	     (if i
		 (make-node '##core#let_float (list i var)
			    (list (walk/unbox val)
				  (walk (second subs))))
		 (make-node 'let params (map walk subs)))))
	  ((##core#inline ##core#inline_allocate)
	   (cond ((assoc (first params) +unboxed-map+) =>
		  (lambda (a)
		    (let ((ub (second a))
			  (type (third a)))
		      (set! count (add1 count))
		      (let ((n (make-node '##core#inline
					  (list ub)
					  (map (if (eq? type 'acc)
						   walk
						   walk/unbox)
					       subs))))
			(case type
			  ((pred) n)
			  (else (make-node '##core#box_float '()
					   (list n))))))))
		 (else (make-node class params (map walk subs)))))
	  (else (make-node class params (map walk subs))))))

    (let ((node (walk node)))
      (with-debugging-output
       '(x o)
       (lambda ()
	 (printf "number of unboxed float variables: ~a\n"
	  (length floatvars))
	 (printf "number of inline operations replaced with unboxed ones: ~a\n"
		 count)))
      node)))

)
