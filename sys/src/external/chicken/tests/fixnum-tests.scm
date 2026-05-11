(import (chicken platform)
	(chicken fixnum))

(define (fxo+ x y) (##core#inline "C_i_o_fixnum_plus" x y))
(define (fxo- x y) (##core#inline "C_i_o_fixnum_difference" x y))

(define-syntax assert
  ;; compiling with -unsafe disables the original assert
  (ir-macro-transformer
   (lambda (e inj cmp)
     (apply
      (lambda (f)
	`(if (not ,f)
	     (error "assert" ',f)))
      (cdr e)))))

(assert (= 4 (fxo+ 2 2)))
(assert (= -26 (fxo+ 74 -100)))
(assert (= 1073741823 (fxo+ #x3ffffffe 1)))
(assert
 (if (feature? #:64bit)
     (not (fxo+ #x3fffffffffffffff 1))
     (not (fxo+ #x3fffffff 1))))
(assert (= 4 (fxo- 6 2)))
(assert (= -4 (fxo- 1000 1004)))
(assert (= 2004 (fxo- 1000 -1004)))
(assert
 (if (feature? #:64bit)
     (= -4611686018427387904 (fxo- (- #x3fffffffffffffff) 1))
     (= -1073741824 (fxo- (- #x3fffffff) 1))))
(assert
 (if (feature? #:64bit)
     (not (fxo- (- #x3fffffffffffffff) 2))
     (not (fxo- (- #x3fffffff) 2))))

(assert (= (modulo -3 4) (fxmod -3 4)))
