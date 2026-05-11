;;; clustering-tests.scm

;; triggers `determine-loop-and-dispatch`
(let ()
  (define (a x) (if (= x 0) x (b (sub1 x))))
  (define (b x) (if (= x 0) x (a (sub1 x))))
  (a 10))
