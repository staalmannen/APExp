(define-syntax bar
  (er-macro-transformer
   (lambda (e inj cmp) (get-line-number (cadr e)))))

(define-syntax foo
  (ir-macro-transformer
   (lambda (e inj cmp) (get-line-number (cadr e)))))

(assert (equal? "test-line-numbers.scm:9" (the * (foo (hello-ir)))))
(assert (equal? "test-line-numbers.scm:10" (the * (bar (hello-er)))))

(define-syntax baz
  (ir-macro-transformer
   (lambda (e inj cmp)
     (cadr e))))

(define (f)
  (baz
   (+ 'a)))
