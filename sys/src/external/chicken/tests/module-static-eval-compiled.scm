;;;; test eval in statically compiled code

(declare (uses lolevel))

(eval '(import (chicken memory representation)))
(assert (eval '(= 1 (block-ref #(1) 0))))
(module static (foo)
  (import scheme (chicken memory representation))
  (define (foo x) (block-ref x 0)))
(eval '(import static))
(assert (eval '(= 99 (foo #(99)))))
