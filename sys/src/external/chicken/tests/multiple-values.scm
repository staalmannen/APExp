(define-syntax assert-fail
  (syntax-rules ()
    ((_ exp)
     (assert (handle-exceptions ex #t exp #f)))))

(define (f x) #t)

;; Relaxed cases
(assert (f (values 1 2 3)))
(assert-fail (call/cc (lambda (k) (k 1 2 3)))) ; For now it should fail, see #1601

;; Strict cases
(assert-fail (call-with-values (lambda () (values 1 2 3)) f))
(assert-fail
  (call-with-values
    (lambda () (call/cc (lambda (k) (k 1 2 3))))
    f))

;; Sanity check for strict cases with correct argument count
(assert (call-with-values (lambda () (values 1)) f))
(assert (call-with-values (lambda () 1) f))
(assert (call-with-values (lambda () (call/cc (lambda (k) (k 1)))) f))
