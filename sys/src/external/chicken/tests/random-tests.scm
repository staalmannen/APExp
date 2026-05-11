;;;; random number tests


(import (chicken random))

(define seed (random-bytes))

(define (nums n)
  (let loop ((n n))
    (if (zero? n)
        '()
        (cons (pseudo-random-integer 10000)
              (nums (- n 1))))))

(set-pseudo-random-seed! seed)
(define n1 (nums 100))
(set-pseudo-random-seed! seed)
(assert n1 (nums 100))
