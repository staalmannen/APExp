;; This allocates several large objects directly in the heap via the
;; toplevel entry point, for a total of about 10MB on 64-bit machines.
;; This guards against regressions in heap reallocation (#1221).

(define-syntax generate-literals
  (ir-macro-transformer
    (lambda (i r c)
      (let lp ((i 0)
	       (exprs '()))
	(if (= i 1000)
	    (cons 'begin exprs)
	    (lp (add1 i)
		(cons `(define ,(gensym)
			 (quote ,(make-vector 1000))) exprs)))))))

(generate-literals)
