;;;; records-and-setters-test.scm


;;; define-record-type with setters

(define-record-type foo 
  (make-foo x y z t)
  foo?
  (x get-x)
  (y get-y set-y)
  (z get-z (setter get-z))
  (t get-t (setter make-foo)))

(let ((f (make-foo 1 2 3 4)))
  (assert (foo? f))
  (assert (= 1 (get-x f)))
  (assert (= 2 (get-y f)))
  (set-y f 99)
  (assert (= 99 (get-y f)))
  (set! (get-z f) 100)
  (assert (= 100 (get-z f)))
  (set! (make-foo f) 1000)
  (assert (= 1000 (get-t f))))

(define-record bar
  a
  (setter b))

(let ((b (make-bar 1 2)))
  (assert (bar? b))
  (bar-a-set! b 3)
  (assert (= 3 (bar-a b)))
  (setter bar-b)
  (set! (bar-b b) 4)
  (assert (= (bar-b b) 4)))
