(require-library import-library-test1)

(module bar (xcase)
  (import scheme (chicken base) foo)
  (assert (equal? '(123) (foo)))
  (assert (= 2 (xcase 1 ((1) 2)))))

(import bar)
(assert (= 2 (xcase 1 ((1) 2))))
