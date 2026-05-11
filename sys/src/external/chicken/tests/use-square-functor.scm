;;; use-square-functor.scm

(import square-functor)

(module num (*) (import scheme))
(module lst (*) (import (except scheme *)) (define (* x y) (list x y)))

(module sf1 = (square-functor num))
(module sf2 = (square-functor lst))

(import (prefix sf1 sf1:))
(import (prefix sf2 sf2:))

(assert (= 9 (sf1:square 3)))
(assert (equal? '(3 3) (sf2:square 3)))
