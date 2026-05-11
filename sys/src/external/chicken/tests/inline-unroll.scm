;; trivial test for catching runaway inlining (#1648), by
;; megane:

(module
 m1 (foo)
 (import scheme)
 (define (foo x) (bar x))
 (define (bar x) (if (null? x) x (bar (cdr x)))))
