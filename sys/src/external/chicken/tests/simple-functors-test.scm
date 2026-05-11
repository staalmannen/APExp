;;;; simple-functors-test.scm


(define-interface STUFF (a b))

(module foo ((interface: STUFF))	; test long spec
(import scheme)
(define a 1)
(define b 2))

(functor 
 (do-things (arg STUFF)) (do-it)
 (import scheme arg)
 (define (do-it) (list a b)))

(module bar = (do-things foo))

(import bar)
(assert (equal? '(1 2) (do-it)))

