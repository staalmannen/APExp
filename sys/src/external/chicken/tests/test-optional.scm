;;;; test-optional.scm - by Alan Post


(define (test baseline result)
  (assert (equal? baseline result)))

;;
;; basic optional arguments with default value.
;;

(define (foo0 #!optional a0 a1 a2 a3)
  (list a0 a1 a2 a3))

(define (foo1 a0 #!optional a1 a2 a3)
  (list a0 a1 a2 a3))

(define (foo2 a0 a1 #!optional a2 a3)
  (list a0 a1 a2 a3))

(define (foo3 a0 a1 a2 #!optional a3)
  (list a0 a1 a2 a3))

(test '(#f #f #f #f) (foo0))
(test '(1  #f #f #f) (foo0 1))
(test '(1  2  #f #f) (foo0 1 2))
(test '(1  2   3 #f) (foo0 1 2 3))
(test '(1  2   3  4) (foo0 1 2 3 4))

;(test '(#f #f #f #f) (foo1)) ; invalid, too few arguments.
(test '(1  #f #f #f) (foo1 1))
(test '(1  2  #f #f) (foo1 1 2))
(test '(1  2   3 #f) (foo1 1 2 3))
(test '(1  2   3  4) (foo1 1 2 3 4))

;(test '(#f #f #f #f) (foo2)) ; invalid, too few arguments.
;(test '(1 #f  #f #f) (foo2 0)) ; invalid, too few arguments.
(test '(1  2  #f #f) (foo2 1 2))
(test '(1  2  #f #f) (foo2 1 2))
(test '(1  2   3 #f) (foo2 1 2 3))
(test '(1  2   3  4) (foo2 1 2 3 4))

;(test '(#f #f #f #f) (foo3)) ; invalid, too few arguments.
;(test '(1  #f #f #f) (foo3 1)) ; invalid, too few arguments.
;(test '(1  2  #f #f) (foo3 1 2)) ; invalid, too few arguments.
(test '(1  2   3 #f) (foo3 1 2 3))
(test '(1  2   3  4) (foo3 1 2 3 4))

;;
;; basic optional arguments with manual default value.
;;

(define (foo0 #!optional (a0 -1) (a1 -2) (a2 -3) (a3 -4))
  (list a0 a1 a2 a3))

(define (foo1 a0 #!optional (a1 -2) (a2 -3) (a3 -4))
  (list a0 a1 a2 a3))

(define (foo2 a0 a1 #!optional (a2 -3) (a3 -4))
  (list a0 a1 a2 a3))

(define (foo3 a0 a1 a2 #!optional (a3 -4))
  (list a0 a1 a2 a3))


(test '(-1 -2 -3 -4) (foo0))
(test '(1  -2 -3 -4) (foo0 1))
(test '(1  2  -3 -4) (foo0 1 2))
(test '(1  2   3 -4) (foo0 1 2 3))
(test '(1  2   3  4) (foo0 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo1)) ; invalid, too few arguments.
(test '(1  -2 -3 -4) (foo1 1))
(test '(1  2  -3 -4) (foo1 1 2))
(test '(1  2   3 -4) (foo1 1 2 3))
(test '(1  2   3  4) (foo1 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo2)) ; invalid, too few arguments.
;(test '(1 -2  -3 -4) (foo2 0)) ; invalid, too few arguments.
(test '(1  2  -3 -4) (foo2 1 2))
(test '(1  2  -3 -4) (foo2 1 2))
(test '(1  2   3 -4) (foo2 1 2 3))
(test '(1  2   3  4) (foo2 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo3)) ; invalid, too few arguments.
;(test '(1  -2 -3 -4) (foo3 1)) ; invalid, too few arguments.
;(test '(1  2  -3 -4) (foo3 1 2)) ; invalid, too few arguments.
(test '(1  2   3 -4) (foo3 1 2 3))
(test '(1  2   3  4) (foo3 1 2 3 4))

;;
;; optional arguments with default value set from previous default.
;;
;; NOTE: these currently fail.

(define (foo0 #!optional (a0 -1) (a1 (- a0 1)) (a2 (- a1 1)) (a3 (- a2 1)))
  (list a0 a1 a2 a3))

(define (foo1 a0 #!optional (a1 -2) (a2 (- a1 1)) (a3 (- a2 1)))
  (list a0 a1 a2 a3))

(define (foo2 a0 a1 #!optional (a2 -3) (a3 (- a2 1)))
  (list a0 a1 a2 a3))

(define (foo3 a0 a1 a2 #!optional (a3 -4))
  (list a0 a1 a2 a3))


(test '(-1 -2 -3 -4) (foo0))
(test '(1  0 -1 -2) (foo0 1))
(test '(1  2  1  0) (foo0 1 2))
(test '(1  2  3  2) (foo0 1 2 3))
(test '(1  2  3  4) (foo0 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo1)) ; invalid, too few arguments.
(test '(1  -2 -3 -4) (foo1 1))
(test '(1  2  1  0) (foo1 1 2))
(test '(1  2  3  2) (foo1 1 2 3))
(test '(1  2  3  4) (foo1 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo2)) ; invalid, too few arguments.
;(test '(1 -2  -3 -4) (foo2 0)) ; invalid, too few arguments.
(test '(1  2  -3 -4) (foo2 1 2))
(test '(1  2   3  2) (foo2 1 2 3))
(test '(1  2   3  4) (foo2 1 2 3 4))

;(test '(-1 -2 -3 -4) (foo3)) ; invalid, too few arguments.
;(test '(1  -2 -3 -4) (foo3 1)) ; invalid, too few arguments.
;(test '(1  2  -3 -4) (foo3 1 2)) ; invalid, too few arguments.
(test '(1  2   3 -4) (foo3 1 2 3))
(test '(1  2   3  4) (foo3 1 2 3 4))
