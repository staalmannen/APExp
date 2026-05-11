;;;; record-rename-test.scm

(define-record foo a)

(define-record-type bar
  (make-bar x)
  bar?
  (x get-x))

(module m1 (make-foo make-bar foo? bar?)
(import scheme (chicken base))

(define-record foo a b)

(define-record-type bar
  (make-bar x y)
  bar?
  (x get-x) (y get-y))

(let ((f1 (make-foo 1 2))
      (f2 (make-bar 3 4)))
  (print "Inside module m1: " (list foo f1 bar f2)))

) ; m1

(define toplevel-foo? foo?)
(define toplevel-bar? foo?)

(let ((f1 (make-foo 1))
      (f2 (make-bar 2)))
  (print "At toplevel before importing m1: " (list foo f1 bar f2))
  (assert (foo? f1))
  (assert (not (bar? f1)))
  (assert (not (foo? f2)))
  (assert (bar? f2)))

(import m1)

(let ((f1 (make-foo 1 2))
      (f2 (make-bar 3 4)))
  (print "At toplevel after importing m1: " (list foo f1 bar f2))
  (assert (foo? f1))
  (assert (not (bar? f1)))
  (assert (not (foo? f2)))
  (assert (bar? f2))
  (assert (not (toplevel-foo? f1)))
  (assert (not (toplevel-bar? f1)))
  (assert (not (toplevel-foo? f2)))
  (assert (not (toplevel-bar? f2))))
