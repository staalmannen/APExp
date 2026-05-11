;;;; square-functor.scm

(functor (square-functor (M (*))) *
  (import scheme M)
  (define (square x) (* x x)))
