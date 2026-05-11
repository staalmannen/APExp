;;; x.scm

(import (chicken gc) (chicken platform))

(define (bar x) (gc) (* x x))

(define-external (baz (int i)) double
  (sqrt i))

(return-to-host)
