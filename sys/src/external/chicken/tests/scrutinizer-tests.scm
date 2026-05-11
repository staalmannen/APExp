;;; scrutinizer unit tests

(import-for-syntax
  (chicken format)
  (chicken compiler scrutinizer))

(define-for-syntax success #t)

(define-syntax test
  (er-macro-transformer
   (lambda (expr rename _)
     (define extra-fail-info '())
     (define (add-fail-info msg)
       (set! extra-fail-info (cons (string-append "  " msg) extra-fail-info))
       #f)
     (define pass
       (let loop ((e (cadr expr)))
         (case (car e)
           ;; invert test
           ((not) (not (loop (cadr e))))
           ;; subtype or type equality
           ((<=)  (and (type<=? (cadr e) (caddr e))
                       (match-types (caddr e) (cadr e))))
           ;; subtype
           ((<)   (and (or (type<=? (cadr e) (caddr e))
			   (add-fail-info "<= returned #f"))
		       (or (match-types (caddr e) (cadr e))
			   (add-fail-info ">= returned #f"))
                       (or (not (type<=? (caddr e) (cadr e)))
			   (add-fail-info "not >= returned #f"))))
           ;; type equality
           ((=)   (and (or (type<=? (cadr e) (caddr e))
			   (add-fail-info "<= failed"))
                       (or (type<=? (caddr e) (cadr e))
			   (add-fail-info ">= failed"))))
           ;; fuzzy match (both directions)
           ((?)   (and (match-types (cadr e) (caddr e))
                       (match-types (caddr e) (cadr e))))
           ;; fuzzy non-match (both directions)
           ((!)   (and (or (not (match-types (cadr e) (caddr e)))
			   (add-fail-info ">= was true"))
                       (or (not (match-types (caddr e) (cadr e)))
			   (add-fail-info "<= was true"))))
           ;; strict non-match (both directions)
           ((><)  (and (not (type<=? (cadr e) (caddr e)))
                       (not (type<=? (caddr e) (cadr e)))))
           ;; A refined with B gives C
           ((~>)  (let ((t (refine-types (cadr e) (caddr e))))
		    (or (equal? t (cadddr e))
			(add-fail-info
			 (format "Refined to `~a', but expected `~a'" t (cadddr e)) )))))))
     (printf "[~a] ~a~n" (if pass " OK " "FAIL") (cadr expr))
     (unless pass
       (for-each print extra-fail-info))
     (when (not pass) (set! success #f))
     (rename '(void)))))

;;; wildcards

(test (= * *))
(test (< x *))

;;; structs

(test (= (struct x) (struct x)))
(test (! (struct x) (struct y)))

;;; undefined

(test (= undefined undefined))
(test (< undefined *))

;;; noreturn

(test (= noreturn noreturn))
(test (< noreturn *))
(test (! undefined noreturn))

;;; booleans

(test (= boolean boolean))
(test (< true boolean))
(test (< false boolean))
(test (= (or true false) boolean))

;;; numbers

(test (= number number))
(test (< fixnum number))
(test (< float number))
(test (< bignum number))
(test (< ratnum number))
(test (< cplxnum number))
(test (< integer number))
(test (= (or fixnum float bignum ratnum cplxnum) number))

(test (= integer integer))
(test (< fixnum integer))
(test (< bignum integer))
(test (not (<= float integer)))
(test (not (<= ratnum integer)))
(test (not (<= cplxnum integer)))
(test (= (or fixnum bignum) integer))

;;; vectors

(test (= vector vector))
(test (= vector (vector-of *)))
(test (< (vector-of x) (vector-of *)))

(test (= (vector *) (vector *)))
(test (= (vector x) (vector x)))
(test (< (vector x) (vector *)))
(test (< (vector *) (vector-of *)))
(test (< (vector x) (vector-of *)))
(test (< (vector x) (vector-of x)))

(test (?  (vector *) (vector-of x)))
(test (>< (vector *) (vector-of x)))

(test (>< (vector *) (vector * *)))
(test (>< (vector x) (vector * *)))
(test (>< (vector *) (vector x x)))
(test (>< (vector x) (vector x x)))

;;; pairs

(test (= pair pair))
(test (= pair (pair * *)))
(test (< (pair x *) pair))
(test (< (pair * x) pair))
(test (< (pair x x) pair))

;;; lists

(test (= null null))
(test (? null list))
(test (? null (list-of x)))
(test (! null (list x)))
(test (! null pair))

(test (= list list))
(test (= list (list-of *)))
(test (< (list-of x) (list-of *)))

(test (= (list *) (list *)))
(test (= (list x) (list x)))
(test (< (list x) (list *)))
(test (< (list *) (list-of *)))
(test (< (list x) (list-of *)))
(test (< (list x) (list-of x)))

(test (?  (list *) (list-of x)))
(test (>< (list *) (list-of x)))

(test (>< (list *) (list * *)))
(test (>< (list x) (list * *)))
(test (>< (list *) (list x x)))
(test (>< (list x) (list x x)))

(test (? (pair * *) (list-of *)))
(test (? (pair x *) (list-of *)))
(test (! (pair * x) (list-of *)))
(test (! (pair x x) (list-of *)))
(test (? (pair * *) (list-of x)))
(test (? (pair x *) (list-of x)))
(test (! (pair * x) (list-of x)))
(test (! (pair x x) (list-of x)))

;;; ports

(test (= port port))
(test (= (refine (input) port) (refine (input) port)))
(test (= (refine (input output) port) (refine (input output) port)))
(test (= (refine (output) port) (refine (output) port)))

(test (< (refine (input) port) port))
(test (< (refine (input output) port) port))
(test (< (refine (output) port) port))
(test (< (refine (input output) port) (refine (input) port)))
(test (< (refine (input output) port) (refine (output) port)))
(test (? (refine (input) port) (refine (output) port)))

;;; unions

(test (< x (or x y)))
(test (< y (or x y)))

(test (=  (or x number) (or x number)))
(test (<  (or x number) (or x number string)))
(test (>< (or x number) (or y string)))

;;; negative types

(test (< (not x) *))
(test (! (not x) x))

(test (< x (not y)))
(test (< x (not (not x))))
(test (< x (not (not (not y)))))

(test (< x (or (not x) x)))
(test (< x (or (not x) (not y))))

(test (! x (not x)))
(test (! x (not (not y))))
(test (! x (not (not (not x)))))
(test (! x (not (or x y))))
(test (! x (or (not x) y)))
(test (! x (not (not (not x)))))

(test (?  (not x) (not y)))
(test (?  (not x) (or x y)))
(test (?  (not x) (or (not x) x)))
(test (?  (not x) (or (not y) x)))
(test (?  (not x) (or (not x) (not y))))
(test (>< (not x) (not y)))
(test (>< (not x) (or x y)))
(test (>< (not x) (or (not x) x)))
(test (>< (not x) (or (not y) x)))
(test (>< (not x) (or (not x) (not y))))

(test (< (or (not x) y) (not x)))
(test (< (not (or x y)) (not x)))

;;; negative wildcards (a bit weird...)

(test (< (not *) *))
(test (< (not (not *)) *))
(test (< (not (not (not *))) *))

(test (! (not *) x))
(test (< (not *) (not x)))

;;; procedures

(test (= (procedure ()) (procedure ())))
(test (= (procedure (x)) (procedure (x))))
(test (= (procedure (#!rest x)) (procedure (#!rest x))))

(test (= (procedure ()) (procedure ())))
(test (= (procedure () x) (procedure () x)))
;; FIXME
;(test (= (procedure () . x) (procedure () . x)))

(test (>< (procedure (x)) (procedure (y))))
(test (>< (procedure () x) (procedure () y)))

(test (? (procedure (x)) (procedure (*))))
(test (? (procedure () x) (procedure () *)))

(test (! (procedure (x)) (procedure ())))
(test (! (procedure (x)) (procedure (x y))))
(test (? (procedure (x)) (procedure (x #!rest y))))

(test (! (procedure () x) (procedure ())))
(test (! (procedure () x) (procedure () x y)))
;; s.a.
;(test (? (procedure () x) (procedure () x . y)))

;;; refinements

(test (= (refine (a) x)   (refine (a) x)))
(test (< (refine (a b) x) (refine (a) x)))
(test (= (refine (a b) x) (refine (a b) x)))

(test (?  (refine (a) x) (refine (b) x)))
(test (>< (refine (a) x) (refine (b) x)))

(test (~> x y y))
(test (~> x (or x y) x))
(test (~> (or x y) x x))
(test (~> (or x y) (or y z) y))

(test (~> * (refine (a) x) (refine (a) x)))
(test (~> (refine (a) *) x (refine (a) x)))
(test (~> x (refine (a) *) (refine (a) x)))
(test (~> (refine (a) x) * (refine (a) x)))
(test (~> (refine (a) x) (refine (b) *) (refine (a b) x)))
(test (~> (refine (a) x) (refine (b) *) (refine (a b) x)))

(test (~> (refine (a) x) y y))
(test (~> x (refine (a) y) (refine (a) y)))
(test (~> (refine (a) x) (refine (b) y) (refine (b) y)))

(test (~> (list fixnum number)
          (list number fixnum)
          (list fixnum fixnum)))
(test (~> (vector x)
          (vector (refine (a) x))
          (vector (refine (a) x))))
(test (~> (list x)
          (list (refine (a) x))
          (list (refine (a) x))))
(test (~> (list x (list x))
          (list (refine (a) *) (list (refine (b) *)))
          (list (refine (a) x) (list (refine (b) x)))))
(test (~> (list * (list *))
          (list (refine (a) x) (list (refine (b) x)))
          (list (refine (a) x) (list (refine (b) x)))))
(test (~> (list (refine (a) x))
          (refine (a) (list (refine (b) x)))
          (refine (a) (list (refine (a b) x)))))
(test (~> (list (refine (a) x))
          (refine (a) (list (refine (b) y)))
          (refine (a) (list (refine (b) y)))))
(test (~> (or pair null) list list))

(begin-for-syntax
  (when (not success) (exit 1)))
