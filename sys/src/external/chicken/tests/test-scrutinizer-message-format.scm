(import (chicken time))

(: deprecated-foo deprecated)
(define deprecated-foo 1)
(: deprecated-foo2 (deprecated foo))
(define deprecated-foo2 2)
(: foo boolean)
(define foo #t)

(define (r-proc-call-argument-count-mismatch) (cons '()))
(define (r-proc-call-argument-type-mismatch) (length 'symbol))
(define (r-proc-call-argument-value-count) (list (cpu-time)) (vector (values)) ((values)))
(define (r-cond-branch-value-count-mismatch) (if (the * 1) 1 (values 1 2)))
(define (r-invalid-called-procedure-type) (1 2))
(define (r-pred-call-always-true) (list? '()))
(define (r-pred-call-always-false) (symbol? 1))
(define (r-cond-test-always-true) (if 'symbol 1))
(define (r-cond-test-always-false) (if #f 1))
(define (r-type-mismatch-in-the) (the symbol 1))
(define (r-zero-values-for-the) (the symbol (values)))
(define (r-too-many-values-for-the) (the symbol (values 1 2)))
(define (r-toplevel-var-assignment-type-mismatch) (set! foo 1))
(define (r-deprecated-identifier) (list deprecated-foo) (vector deprecated-foo2))

(set! foo 1)

;; These have special cases
(define (list-ref-negative-index) (list-ref '() -1))
(define (list-ref-out-of-range) (list-ref '() 1))
(define (append-invalid-arg) (append 1 (list 1)))
(define (vector-ref-out-of-range) (vector-ref (vector) -1))

;; This is disabled because fail-compiler-typecase is a fatal warning
;; (define (fail-compiler-typecase) (compiler-typecase 1 (symbol 1) (list 2)))

(module
 m
 ()
 (import scheme)
 (import (chicken base) (chicken type) (chicken time))

 (: foo2 boolean)
 (define foo2 #t)
 (: deprecated-foo deprecated)
 (define deprecated-foo 1)
 (: deprecated-foo2 (deprecated foo))
 (define deprecated-foo2 2)

 (define (toplevel-foo)
   (define (local-bar)
     (define (r-proc-call-argument-count-mismatch) (cons '()))
     (define (r-proc-call-argument-type-mismatch) (length 'symbol))
     (define (r-proc-call-argument-value-count) (list (cpu-time)) (vector (values)))
     (define (r-cond-branch-value-count-mismatch) (if (the * 1) 1 (cpu-time)))
     (define (r-invalid-called-procedure-type)
       (define (variable) (foo2 2))
       (define (non-variable) (1 2)))
     (define (r-pred-call-always-true) (list? '()))
     (define (r-pred-call-always-false) (symbol? 1))
     (define (r-cond-test-always-true) (if (length '()) 1))
     (define (r-cond-test-always-false) (if #f 1))
     (define (r-type-mismatch-in-the) (the symbol 1))
     (define (r-zero-values-for-the) (the symbol (values)))
     (define (r-too-many-values-for-the) (the symbol (values 1 2)))
     (define (r-toplevel-var-assignment-type-mismatch) (set! foo2 1))
     (define (r-deprecated-identifier) (list deprecated-foo) (vector deprecated-foo2))

     (define (r-let-value-count-invalid)
       (define (zero-values-for-let) (let ((a (values))) a))
       (define (too-many-values-for-let) (let ((a (values 1 2))) a)))
     (define (r-conditional-value-count-invalid)
       (define (zero-values-for-conditional) (if (values) 1))
       (define (too-many-values-for-conditional) (if (values (the * 1) 2) 1)))
     (define (r-assignment-value-count-invalid)
       (define (zero-values-for-assignment) (set! foo (values)))
       (define (too-many-values-for-assignment) (set! foo (values #t 2))))

     ;; These have special cases
     (define (list-ref-negative-index) (list-ref '() -1))
     (define (list-ref-out-of-range) (list-ref '() 1))
     (define (append-invalid-arg) (append 1 (list 1)))
     (define (vector-ref-out-of-range) (vector-ref (vector) -1))

     (define (r-cond-test-always-true-with-pred) (if (symbol? 'symbol) 1))
     (define (r-cond-test-always-false-with-pred) (if (symbol? 1) 1))

     (define (fail-compiler-typecase) (compiler-typecase 1 (symbol 1) (list 2)))
     )))
