(module boo *
  (import scheme)
  (define var 42))

(module foo *
  (import scheme (chicken base) boo)
  (define-syntax bar
    (syntax-rules ()))
  (set! bar 42) ;; set!-ing a macro
  (set! var 42) ;; set!-ing an imported identifier
  (let ((var #f)) (set! var 42)) ;; set!-ing a local variable
  (letrec-values ((bar (values)))) ;; shadow a syntax item
  (let-syntax ((m (syntax-rules ()))) (set! m 42)))
