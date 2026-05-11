;;;; finalizer-error-test.scm - by "megane"

(import (chicken gc))

(define n 10000)

(define (make-objects n)
  (let loop [(i 0)]
    (let [(o (make-vector 100))]
      ;(print "making " i)
      (set-finalizer! o (lambda (ob) (print* " " i)))
      (if (< i n)
	  (loop (+ 1 i))))))

(set-finalizer! (make-vector 100) (lambda (ob) (+ i 'a)))

(make-objects n)

(print "done")
