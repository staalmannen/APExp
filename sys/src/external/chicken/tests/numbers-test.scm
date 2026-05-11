;;;; numbers-test.scm

(include "test.scm")

(import (chicken bitwise)
	(chicken fixnum)
        (chicken flonum)
        (chicken format)
        (chicken platform)
        (chicken time))

;; The default "comparator" doesn't know how to deal with extended number types
(current-test-comparator
 (lambda (exp act)
   (or (equal? exp act)
       (if (or (and (cplxnum? exp) (number? act))
               (and (cplxnum? act) (number? exp)))
           (and (< (abs (real-part (- exp act)))
                   (current-test-epsilon))
                (< (abs (imag-part (- exp act)))
                   (current-test-epsilon)))
           (and (number? exp)
                (inexact? exp)
                (< (abs (- 1 (abs (if (zero? act) (+ 1 exp) (/ exp act)))))
                   (current-test-epsilon)))))))

(test-begin "numbers")

(current-test-epsilon 0) ;; We want exact comparisons

(define max-fix most-positive-fixnum)
(define min-fix most-negative-fixnum)
;; The minimal bignum in the sense that any smaller makes it a fixnum
(define min-big (+ most-positive-fixnum 1))

(define 64-bits? (feature? #:64bit))

(define (show x) 
  (print (and x (number->string x)))
  x)

;(set-gc-report! #t)

(define max2 (+ max-fix max-fix))

(define b1 (+ 22 max2))          ; 2147483668 or 4611686018427387928

(define c1 (make-rectangular 33 44))
(define c2 (make-rectangular -1.2 44))

(define b2 (- min-fix 22))
(define r1 (/ 33 44))
(define r2 (/ 1000 44))

;; Found with the pi-ratios benchmark (find-pi 10 20 50)
(define pi    3.14159265358979323881089001960817518141234854964894)
(define ratpi 314159265358979323881089001960817518141234854964894/100000000000000000000000000000000000000000000000000)

(test-group "basic constructors"
 (test-assert "some bignum (twice maxint)" (show max2))
 (test-assert "some other bignum (2147483668 or 9223372036854775828)" (show b1))
 (test-assert "negative bignum" (show b2))
 (test-assert "exact complex" (show c1))
 (test-assert "inexact complex" (show c2))
 (test-assert "rational" (show r1))
)

(test-group "addition"
 (test-equal "+: no arguments" (+) 0) 
 (test-equal "+: single argument" (+ 33) 33)
 (test-equal "+: adding fixnums" (+ 33 44) 77)
 (test-equal "+: adding fixnums (2nd negative)" (+ 33 -44) -11)
 (test-equal "+: adding fix/flo" (+ 33 44.5) 77.5)
 (test-assert "+: adding fix/big" (show (+ 22 max2)))
 (test-assert "+: adding fix/rat" (show (+ 22 r1)))
 (test-equal "+: adding fix/complex" (+ 99 c1) (make-rectangular 132 44))
 (test-equal "+: adding complex/fix (inexact)" (+ c2 99) (make-rectangular 97.8 44))
 (test-equal "+: flo/flo" (+ 3.4 5.6) 9.0)
 (test-equal "+: flo/big"
	     (+ 3.4 b1)
	     (if 64-bits? 9223372036854775809.4 2147483671.4))
 (test-assert "+: flo/rat" (show (+ 33.4 r1)))
 (test-equal "+: flo/comp" (+ 3.4 c1) (make-rectangular 36.4 44))
 (test-assert "+: big/rat" (show (+ b1 r1)))
 (test-equal "+: comp+comp" (+ c1 c1) (make-rectangular 66 88))
 (test-equal "+: comp+comp (inexact)" (+ c1 c2) (make-rectangular 31.8 88))
 (test-equal "+: multiarg" (+ 33 44 55) 132)
)

(test-group "subtraction"

 (test-equal "-: negate fix" (- 33) -33)
 (test-equal "-: negate most negative fix" (- min-fix) min-big)
 (test-equal "abs: most negative fix" (abs most-negative-fixnum) min-big)
 (test-equal "-: negate flo" (- 33.2) -33.2)
 (test-assert "-: negate rat" (show (- r1)))
 (test-equal "-: double-negate big" (- (- b1)) b1)
 (test-equal "-: negate comp" (- c1) (make-rectangular -33 -44))
 (test-equal "-: fixnums" (- 33 44) -11)
 (test-equal "-: fixnums (2nd negative)" (- 33 -44) 77)
 (test-assert "-: fixnums (overflow)" (show (- min-fix min-fix)))
 (test-equal "-: fix/flo" (- 33 44.5) -11.5)
 (test-equal "-: flo/fix" (- 44.5 33) 11.5)
 (test-assert "-: fix/big" (show (- 22 b2)))
 (test-assert "-: big/fix" (show (- b2 22)))
 (test-equal "-: big/fix (normalizing to fix)" (- min-big 1) max-fix)
 (test-assert "-: fix/rat" (show (- 22 r1)))
 (test-assert "-: rat/fix" (show (- r1 22)))
 (test-equal "-: fix/complex" (- 99 c1) (make-rectangular 66 -44))
 (test-equal "-: complex/fix" (- c1 99) (make-rectangular -66 44))
 (test-equal "-: complex/fix (inexact)" (- c2 99) (make-rectangular -100.2 44))
 (test-equal "-: fix/complex (inexact)" (- 99 c2) (make-rectangular 100.2 -44))
 (test-equal "-: fix/complex (negative im)" (- 99 1+2i) 98-2i)
 (test-equal "-: fix/complex (negative im, inexact)" (- 99 1.0+2.0i) 98.0-2.0i)
 (test-equal "-: fix/complex (negative real, inexact)" (- 99 -1.0+2.0i) 100.0-2.0i)
 (test-equal "-: rat/complex (negative real)" (- 3/2 -1+2i) 5/2-2i)
 
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "-: flo/flo" (- 5.6 3.4) 2.2))
 
 (test-assert "-: flo/big" (show (- 3.4 b1)))
 (test-assert "-: big/flo" (show (- b1 3.4)))
 (test-assert "-: flo/rat" (show (- 3.4 r1)))
 (test-assert "-: rat/flo" (show (- r1 3.4)))
 (test-assert "-: big/rat" (show (- b1 r1)))
 (test-assert "-: rat/big" (show (- r1 b1)))
 (test-equal "-: flo/comp" (- 3.4 c1) (make-rectangular -29.6 -44))
 (test-equal "-: comp/flo" (- c1 3.4) (make-rectangular 29.6 44))
 (test-equal "-: comp-comp" (- c1 c1) 0)
 (test-equal "-: comp-comp (inexact)" (- c1 c2) 34.2)
 (test-equal "-: multiarg" (- 33 44 55) -66)
)


(test-group "multiplication"

 (test-equal "*: no arguments" (*) 1)
 (test-equal "*: single argument" (* 33) 33)
 (test-equal "*: multiplying fixnums" (* 33 44) 1452)
 (test-equal "*: multiplying fixnums (2nd negative)" (* 33 -44) -1452)
 (test-equal "*: multiplying fix/flo" (* 33 44.5) 1468.5)
 (test-assert "*: multiplying fix/big (-> 47244640212)" (show (* 22 max2)))
 (test-assert "*: multiplying fix/rat" (show (* 33 r1)))
 (test-equal "*: multiplying fix/complex" (* 99 c1) (make-rectangular 3267 4356))
 (test-equal "*: multiplying complex/fix (inexact)" (* c2 99) (make-rectangular -118.8 4356.0))
 (test-equal "*: multiplying most negative fixnum by one (edge case)"
       (list (* most-negative-fixnum 1) (fixnum? (* most-negative-fixnum 1)))
       (list most-negative-fixnum #t))
 (test-equal "*: flo/flo" (* 3.4 5.6) 19.04)
 (test-equal "*: flo/big"
       (* 0.001 b1)
       (if 64-bits? 9223372036854775.806 2147483.668))
 (test-assert "*: flo/rat" (show (* 3.4 r1)))
 (test-assert "*: big/rat" (show (* b1 r1)))
 (test-equal "*: flo/comp" (* 3.4 c1) (make-rectangular 112.2 149.6))
 (test-equal "*: comp*comp" (* c1 c1) (make-rectangular -847 2904))
 (test-equal "*: comp*comp (inexact)" (* c1 c2) (make-rectangular -1975.6 1399.2))
 (test-equal "*: multiarg" (* 33 44 55) 79860)
)

(test-group "division"

 (test-assert "/: rec. fix" (show (/ 33)))
 (test-assert "/: rec. flo" (show (/ 33.2)))
 (test-assert "/: rec. rat" (show (/ r1)))
 (test-assert "/: rec. big" (show (/ b1)))
 (test-assert "/: rec. comp" (/ c1))
 (test-assert "/: fixnums" (show (/ 33 44)))
 (test-equal "/: fixnums (both negative, fixnum result)" (show (/ -2 -2)) 1)
 (test-assert "/: fixnums (2nd negative)" (show (/ 33 -44)))
 (test-assert "/: fixnums" (show (/ min-fix min-fix)))
 (test-equal "/: fix/flo" (/ 33 44.5) (fp/ 33.0 44.5))
 (test-equal "/: flo/fix" (/ 44.5 33) (fp/ 44.5 33.0))
 (test-assert "/: fix/big" (show (/ 22 b2)))
 (test-assert "/: big/fix" (show (/ b2 22)))
 (test-assert "/: fix/rat" (show (/ 22 r1)))
 (test-assert "/: rat/fix" (show (/ r1 22)))
 (test-assert "/: fix/complex" (show (/ 99 c1)))
 (test-assert "/: complex/fix" (show (/ c1 99)))
 (test-assert "/: complex/fix (inexact)" (show (- c2 99)))
 (test-assert "/: fix/complex (inexact)" (show (- 99 c2)))
 (test-equal "/: flo/flo" (/ 5.6 3.4) (fp/ 5.6 3.4))
 (test-assert "/: flo/big" (show (/ 3.4 b1)))
 (test-assert "/: big/flo" (show (/ b1 3.4)))
 (test-assert "/: flo/rat" (show (/ 3.4 r1)))
 (test-assert "/: rat/flo" (show (/ r1 3.4)))
 (test-assert "/: big/rat" (show (/ b1 r1)))
 (test-assert "/: rat/big" (show (/ r1 b1)))
 (test-assert "/: rat/rat" (show (/ r1 r1)))
 (test-assert "/: flo/comp" (show (/ 3.4 c1)))
 (test-assert "/: comp/flo" (show (/ c1 3.4)))
 (test-assert "/: comp/comp" (show (/ c1 c1)))
 (test-assert "/: comp/comp (inexact)" (show (/ c1 c2)))
 (test-equal "/: rat/complex" (/ 1/2 1+2i) 1/10-1/5i)
 (test-equal "/: rat/complex (negative im)" (/ 1/2 1-2i) 1/10+1/5i)
 (test-equal "/: rat/complex (negative real)" (/ 1/2 -1+2i) -1/10-1/5i)
 (test-equal "/: rat/complex (negative real&im)" (/ 1/2 -1-2i) -1/10+1/5i)
 
 (test-assert "/: multiarg" (show (/ 66 2 44)))
 (test-error "/: div fixnum by 0" (/ 33 0))
 ;; R7RS says it is an error if any but the first argument is an exact
 ;; zero.  R5RS doesn't say anything at all (??).
 (test-error "/: div flonum by 0" (/ 33.0 0))
 (test-equal "/: div fixnum by 0.0" (/ 33 0.0) +inf.0)
 (test-equal "/: div flonum by 0.0" (/ 33.0 0.0) +inf.0)
 (test-equal "/: div by 0 (inexact)" (/ 33 0.0) +inf.0)
 (test-assert "/: big result" (show (/ b1 2)))
)

(test-group "quotient"
  (test-equal "quotient: fix/fix" (quotient 22 11) 2)
  (test-equal "quotient: fix/big" (quotient 22 b1) 0)
  (test-equal "quotient: fix/big (most negative)" (quotient min-fix (- min-fix)) -1)
  (test-equal "quotient: big/fix (most negative)" (quotient (- min-fix) min-fix) -1)
  (test-equal "quotient: fix/fix (most negative)" (quotient min-fix -1) (* min-fix -1))
  (test-equal "quotient: flo/flo" (quotient 22.0 11.0) 2.0)
  (test-equal "quotient: fix/flo" (quotient 22 11.0) 2.0)
  (test-equal "quotient: flo/fix" (quotient 22.0 11) 2.0)
  (test-equal "quotient: flo/big" (quotient 22.0 b1) 0.0)
  (test-equal "quotient: big/flo" (quotient b1 (/ b1 2.0)) 2.0)
  (test-equal "quotient: big/big" (quotient (- min-fix) (- min-fix)) 1)
  (test-equal "quotient: big/big" (quotient (+ (- min-fix) 5) (- min-fix)) 1)
  
  (test-error "quotient: flo/flo (fractional)" (quotient 23.0 11.5))
  (test-error "quotient: fix/flo (fractional)" (quotient 23 11.5))
  (test-error "quotient: flo/fix (fractional)" (quotient 13.5 6))
)

(test-group "remainder"
  (test-equal "remainder: fix/fix" (remainder 22 11) 0)
  (test-equal "remainder: fix/big" (remainder 22 b1) 22)
  (test-equal "remainder: fix/big (most negative)" (remainder min-fix (- min-fix)) 0)
  (test-equal "remainder: big/fix (most negative)" (remainder (- min-fix) min-fix) 0)
  (test-equal "remainder: big/big" (remainder (- min-fix) (- min-fix)) 0)
  (test-equal "remainder: big/big" (remainder (+ (- min-fix) 5) (- min-fix)) 5)
  
  (test-equal "remainder: flo/flo" (remainder 22.0 11.0) 0.0)
  (test-equal "remainder: fix/flo" (remainder 22 11.0) 0.0)
  (test-equal "remainder: flo/fix" (remainder 22.0 11) 0.0)
  (unless 64-bits?  ;; We lose so much precision when converting to double this makes no sense
    (test-equal "remainder: flo/big" (remainder 22.0 b1) 22.0))
  
  (test-error "remainder: flo/flo (fractional)" (remainder 22.5 2.25))
  (test-error "remainder: fix/flo (fractional)" (remainder 6 12.5))
  (test-error "remainder: flo/fix (fractional)" (remainder 13.5 6))
  (unless 64-bits?
    (test-error "remainder: flo/big (fractional)" (remainder (+ b1 0.5) b1)))
)

(test-group "quotient&remainder"
  (test-equal "quotient&remainder: fix/fix"
              (receive (quotient&remainder 22 11)) '(2 0))
  (test-equal "quotient&remainder: fix/big"
              (receive (quotient&remainder 22 b1)) '(0 22))
  (test-equal "quotient&remainder: fix/big (most negative)"
              (receive (quotient&remainder min-fix (- min-fix))) '(-1 0))
  (test-equal "quotient&remainder: big/fix (most negative)"
              (receive (quotient&remainder (- min-fix) min-fix)) '(-1 0))
  (test-equal "quotient&remainder: fix/fix (most negative)"
        (receive (quotient&remainder min-fix -1)) `(,(* min-fix -1) 0))
  (test-equal "quotient&remainder: big/big" (receive (quotient&remainder (- min-fix) (- min-fix)))
        '(1 0))
  (test-equal "quotient&remainder: big/big" (receive (quotient&remainder (+ (- min-fix) 5) (- min-fix)))
        '(1 5))

  (test-equal "quotient&remainder: flo/flo"
        (receive (quotient&remainder 22.0 4.0)) '(5.0 2.0))
  (test-equal "quotient&remainder: flo/fix"
        (receive (quotient&remainder 22.0 4)) '(5.0 2.0))
  (test-equal "quotient&remainder: fix/flo"
        (receive (quotient&remainder 22 4.0)) '(5.0 2.0))
  (test-error "quotient&remainder: flo/fix (fractional)"
              (receive (quotient&remainder 0.1 2)))
  (test-error "quotient&remainder: flo/big (fractional)"
              (receive (quotient&remainder 0.5 b1)))
  (test-error "quotient&remainder: big/flo (fractional)"
              (receive (quotient&remainder b1 0.5)))
)

(test-group "gcd"
  (test-equal "gcd: fix (64-bit)/big" (gcd 907947775416515 11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111) 1)
  (test-equal "gcd: big/big" (gcd 234897235923342343242 234790237101762305340234) 6)
  (test-equal (gcd) 0)
  (test-equal (gcd 6) 6)
  (test-equal (gcd -2) 2)
  (test-equal (gcd 6 8) 2)
  (test-equal (gcd 6 8 5) 1)
  (test-equal (gcd 6 -8 5) 1)
  (test-equal (gcd 6.0) 6.0)
  (test-equal (gcd 6.0 8.0) 2.0)
  (test-error (gcd 6.1))
  (test-error (gcd 6.1 8.0))
  (test-error (gcd 6.0 8.1))
  (test-error (gcd +inf.0))
  (test-error (gcd +nan.0))
  (test-error (gcd 6.0 +inf.0))
  (test-error (gcd +inf.0 6.0))
  (test-error (gcd +nan.0 6.0))
  (test-error (gcd 6.0 +nan.0))
  (test-error (gcd 1+2i 3+4i))
  (test-error (gcd 1/2 3/4)))

(test-group "lcm"
  (test-equal (lcm) 1)
  (test-equal (lcm 5) 5)
  (test-equal (lcm -8) 8)
  (test-equal (lcm 6 8) 24)
  (test-equal (lcm 6 8 5) 120)
  (test-equal (lcm 6.0 8.0) 24.0)
  (test-error (lcm 6.1 8.0))
  (test-error (lcm 6.0 8.1))
  (test-error (lcm +inf.0))
  (test-error (lcm +nan.0))
  (test-error (lcm 6.0 +inf.0))
  (test-error (lcm +inf.0 6.0))
  (test-error (lcm +nan.0 6.0))
  (test-error (lcm 6.0 +nan.0))
  (test-error (lcm 1+2i 3+4i))
  (test-error (lcm 1/2 3/4)))


(test-group "equality"

 (test-equal "=: fix/fix" (= 33 33) #t)
 (test-equal "=: fix/flo" (= 33 33.0) #t)
 (test-equal "=: !fix/fix" (= 33 34) #f)
 (test-equal "=: !fix/flo" (= 33 33.1) #f)
 (test-equal "=: !fix/flo (overflow)" (= 9007199254740993 9007199254740992.0) #f)
 (test-equal "=: !fix/flo (inf)" (= 0 +inf.0) #f)
 (test-equal "=: !fix/flo (-inf)" (= 0 -inf.0) #f)
 (test-equal "=: !fix/flo (+nan)" (= 0 -nan.0) #f)
 (test-equal "=: flo/fix" (= 33.0 33) #t)
 (test-equal "=: !flo/fix (overflow)" (= 9007199254740992.0 9007199254740993) #f)
 (test-equal "=: !flo/fix (inf)" (= +inf.0 0) #f)
 (test-equal "=: !flo/fix (-inf)" (= -inf.0 0) #f)
 (test-equal "=: !flo/fix (+nan)" (= -nan.0 0) #f)
 (test-equal "=: flo/flo" (= 33.1 33.1) #t)
 (test-equal "=: !flo/flo" (= 33.1 -33.1) #f)
 ;; Flonums are only 53 bits of precision, so it will drop data.
 ;; Comparison is exact
 (unless 64-bits?
   (test-equal "=: big/flo" (= b1 (+ 0.0 b1)) #t))
 (test-equal "=: big/big" (= b1 b1) #t)
 (test-equal "=: !big/big" (= b2 b1) #f)
 (test-equal "=: rat/flo" (= r1 (+ r1 0.0)) #t)
 (test-equal "=: rat/rat" (= r1 r1) #t)
 (test-equal "=: !rat/rat" (= r1 r2) #f)
 (test-equal "=: comp/comp" (= c1 c1) #t)
 (test-equal "=: !comp/comp" (= c1 c2) #f)
)

(test-group "generic equality"
 (test-equal "equal?: fix/fix" (equal? 33 33) #t)
 (test-equal "equal?: fix/flo" (equal? 33 33.0) #f)
 (test-equal "equal?: !fix/fix" (equal? 33 34) #f)
 (test-equal "equal?: !fix/flo" (equal? 33 33.1) #f)
 (test-equal "equal?: flo/fix" (equal? 33.0 33) #f)
 (test-equal "equal?: flo/flo" (equal? 33.1 33.1) #t)
 (test-equal "equal?: !flo/flo" (equal? 33.1 -33.1) #f)
 (test-equal "equal?: big/flo" (equal? b1 (+ 0.0 b1)) #f)
 (test-equal "equal?: big/big" (equal? b1 b1) #t)
 (test-equal "equal?: big/big2" (equal? b1 (+ 1 b1 -1)) #t)
 (test-equal "equal?: !big/big" (equal? b2 b1) #f)
 (test-equal "equal?: rat/flo" (equal? r1 (+ r1 0.0)) #f)
 (test-equal "equal?: rat/rat" (equal? r1 r1) #t)
 (test-equal "equal?: !rat/rat" (equal? r1 r2) #f)
 (test-equal "equal?: comp/comp" (equal? c1 c1) #t)
 (test-equal "equal?: !comp/comp" (equal? c1 c2) #f)
 (test-equal "equal?: nan/nan" (equal? (/ 0.0 0.0) (/ 0.0 0.0)) #f)
 (test-equal "equal?: nan+nan/nan+nan" (equal? (make-rectangular (/ 0.0 0.0)
                                                              (/ 0.0 0.0))
                                            (make-rectangular (/ 0.0 0.0)
                                                              (/ 0.0 0.0))) #f)
)


(test-group "greater & greater/equal"

 (test-equal ">: fix/fix" (> 44 33) #t)
 (test-equal ">=: fix/fix" (>= 44 33) #t)
 (test-equal ">: fix/fix/fix" (> 44 33 22) #t)
 (test-equal ">=: fix/fix/fix" (>= 44 33 22) #t)
 (test-equal ">: !fix/fix" (> 33 44) #f)
 (test-equal ">=: !fix/fix" (>= 33 44) #f)
 (test-equal ">: !fix/fix/fix" (> 22 33 44) #f)
 (test-equal ">=: !fix/fix/fix" (>= 22 33 44) #f)
 (test-equal ">: fix/fix" (> 33 33) #f)
 (test-equal ">=: !fix/fix" (>= 33 33) #t)
 (test-equal ">: fix/flo" (> 44 33.0) #t)
 (test-equal ">=: fix/flo" (>= 44 33.0) #t)
 (test-equal ">: !fix/flo" (> 33 44.0) #f)
 (test-equal ">=: !fix/flo" (>= 33 44.0) #f)
 (test-equal ">: !fix/flo" (> 33 33.0) #f)
 (test-equal ">=: !fix/flo" (>= 33 33.0) #t)
 (test-equal ">: fix/flo (flo overflow), on 64 bits"
       (> 9007199254740993 9007199254740992.0) #t) ; 2^53
 (test-equal ">=: fix/flo (flo overflow), on 64 bits"
       (>= 9007199254740993 9007199254740992.0) #t)
 (test-equal ">: fix/flo (flo underflow), on 64 bits"
       (> -9007199254740992 -9007199254740991.0) #f)
 (test-equal ">=: fix/flo (flo underflow), on 64 bits"
       (>= -9007199254740992 -9007199254740991.0) #f)
 (test-equal ">: fix/big" (> 44 b2) #t)
 (test-equal ">=: fix/big" (>= 44 b2) #t)
 (test-equal ">: !fix/big" (> 33 b1) #f)
 (test-equal ">=: !fix/big" (>= 33 b1) #f)
 (test-equal ">: fix/rat" (> 44 r1) #t)
 (test-equal ">=: fix/rat" (>= 44 r1) #t)
 (test-equal ">: !fix/rat" (> 0 r1) #f)
 (test-equal ">=: !fix/rat" (>= 0 r1) #f)

 (test-equal ">: flo/fix" (> 44.0 33) #t)
 (test-equal ">=: flo/fix" (>= 44.0 33) #t)
 (test-equal ">: !flo/fix" (> 33.0 44) #f)
 (test-equal ">=: !flo/fix" (>= 33.0 44) #f)
 (test-equal ">: !flo/fix" (> 33.0 33) #f)
 (test-equal ">=: flo/fix" (>= 33.0 33) #t)
 (test-equal ">: flo/flo" (> 44.0 33.0) #t)
 (test-equal ">=: flo/flo" (>= 44.0 33.0) #t)
 (test-equal ">: !flo/flo" (> 33.0 44.0) #f)
 (test-equal ">=: !flo/flo" (>= 33.0 44.0) #f)
 (test-equal ">: flo/big" (> 44.0 b2) #t)
 (test-equal ">=: flo/big" (>= 44.0 b2) #t)
 (test-equal ">: flo/fix (flo overflow), on 64 bits"
       (> 9007199254740992.0 9007199254740993) #f) ; 2^53
 (test-equal ">=: flo/fix (flo overflow), on 64 bits"
       (>= 9007199254740992.0 9007199254740993) #f)
 (test-equal ">: fix/flo (flo underflow), on 64 bits"
       (> -9007199254740991.0 -9007199254740992) #t)
 (test-equal ">=: fix/flo (flo underflow), on 64 bits"
       (>= -9007199254740991.0 -9007199254740992) #t)
 (test-equal ">: flo/big (flo overflow)"
       (> 1237940039285380274899124224.0 1237940039285380274899124225) #f)
 (test-equal ">=: flo/big (flo overflow)"
       (>= 1237940039285380274899124224.0 1237940039285380274899124225) #f)
 (test-equal ">: !flo/big" (> 33.0 b1) #f)
 (test-equal ">=: !flo/big" (>= 33.0 b1) #f)
 (test-equal ">: flo/rat" (> 44.0 r1) #t)
 (test-equal ">=: flo/rat" (>= 44.0 r1) #t)
 (test-equal ">: !flo/rat" (> 0.0 r1) #f)
 (test-equal ">=: !flo/rat" (>= 0.0 r1) #f)
 (test-equal ">: !rat/rat" (> r1 r1) #f)
 (test-equal ">=: rat/rat" (>= r1 r1) #t)
 (test-equal ">: flo/nan" (> 0.0 +nan.0) #f)
 (test-equal ">=: flo/nan" (>= 0.0 +nan.0) #f)
 (test-equal ">: nan/flo" (> +nan.0 0.0) #f)
 (test-equal ">=: nan/flo" (>= +nan.0 0.0) #f)
 (test-equal ">: flo/flo/nan" (> 1.0 0.0 +nan.0) #f)
 (test-equal ">=: flo/flo/nan" (>= 1.0 0.0 +nan.0) #f)

 (test-equal ">: big/fix" (> b1 33) #t)
 (test-equal ">=: big/fix" (>= b1 33) #t)
 (test-equal ">: !big/fix" (> b2 44) #f)
 (test-equal ">=: !big/fix" (>= b2 44) #f)
 (test-equal ">: big/flo" (> b1 33.0) #t)
 (test-equal ">=: big/flo" (>= b1 33.0) #t)
 (test-equal ">: big/flo (flo overflow)"
       (> 1237940039285380274899124225 1237940039285380274899124224.0) #t)
 (test-equal ">=: big/flo (flo overflow)"
       (>= 1237940039285380274899124225 1237940039285380274899124224.0) #t)
 (test-equal ">: !big/flo" (> b2 44.0) #f)
 (test-equal ">=: !big/flo" (>= b2 44.0) #f)
 (test-equal ">: big/big" (> b1 b2) #t)
 (test-equal ">=: big/big" (>= b1 b2) #t)
 (test-equal ">: !big/big" (> b2 b1) #f)
 (test-equal ">=: !big/big" (>= b2 b1) #f)
 (test-equal ">: big/rat" (> b1 r1) #t)
 (test-equal ">=: big/rat" (>= b1 r1) #t)
 (test-equal ">: !big/rat" (> b2 r1) #f)
 (test-equal ">=: !big/rat" (>= b2 r1) #f)

 (test-equal ">: rat/fix" (> r1 2) #f)
 (test-equal ">=: rat/fix" (>= r1 2) #f)
 (test-equal ">: !rat/fix" (> r1 44) #f)
 (test-equal ">=: !rat/fix" (>= r1 44) #f)
 (test-equal ">: rat/flo" (> r2 2.0) #t)
 (test-equal ">=: rat/flo" (>= r2 2.0) #t)
 (test-equal ">: !rat/flo" (> b2 44.0) #f)
 (test-equal ">=: !rat/flo" (>= b2 44.0) #f)
 (test-equal ">: !rat/big" (> r1 b1) #f)
 (test-equal ">=: !rat/big" (>= r1 b1) #f)
 (test-equal ">: rat/rat" (> r2 r1) #t)
 (test-equal ">=: rat/rat" (>= r2 r1) #t)
 (test-equal ">: !rat/rat" (> r1 r2) #f)
 (test-equal ">=: !rat/rat" (>= r1 r2) #f)
 (test-equal ">: rat/flo (flo overflow)"
       (> 1237940039285380274899124224/1237940039285380274899124223 1.0) #t)
 (test-equal ">: rat/flo (flo overflow)"
       (> 1237940039285380274899124224/1237940039285380274899124223 1.5) #f)
 (test-equal ">=: rat/flo (flo overflow)"
       (>= 1237940039285380274899124224/1237940039285380274899124223 1.0) #t)
 (test-equal ">=: rat/flo (flo overflow)"
       (>= 1237940039285380274899124224/1237940039285380274899124223 1.5) #f)
 (test-equal ">: rat/flo (flo underflow)"
       (> -1237940039285380274899124224/1237940039285380274899124223 -1.0) #f)
 (test-equal ">: rat/flo (flo underflow)"
       (> -1237940039285380274899124224/1237940039285380274899124223 -1.5) #t)
 (test-equal ">=: rat/flo (flo underflow)"
       (>= -1237940039285380274899124224/1237940039285380274899124223 -1.0) #f)
 (test-equal ">=: rat/flo (flo underflow)"
       (>= -1237940039285380274899124224/1237940039285380274899124223 -1.5) #t)
)


(test-group "less & less/equal"

 (test-equal "<: !fix/fix" (< 44 33) #f)
 (test-equal "<=: !fix/fix" (<= 44 33) #f)
 (test-equal "<: fix/fix/fix" (< 33 44 55) #t)
 (test-equal "<=: fix/fix/fix" (<= 33 44 55) #t)
 (test-equal "<: !fix/fix/fix" (< 33 55 44) #f)
 (test-equal "<=: !fix/fix/fix" (<= 33 55 44) #f)
 (test-equal "<: !fix/fix/fix" (< 44 33 55) #f)
 (test-equal "<=: !fix/fix/fix" (<= 44 33 55) #f)
 (test-equal "<: !fix/fix/fix" (< 44 44 44) #f)
 (test-equal "<=: fix/fix/fix" (<= 44 44 44) #t)
 (test-equal "<: fix/fix" (< 33 44) #t)
 (test-equal "<=: fix/fix" (<= 33 44) #t)
 (test-equal "<: !fix/fix" (< 33 33) #f)
 (test-equal "<=: fix/fix" (<= 33 33) #t)
 (test-equal "<: !fix/flo" (< 44 33.0) #f)
 (test-equal "<=: !fix/flo" (<= 44 33.0) #f)
 (test-equal "<: fix/flo" (< 33 44.0) #t)
 (test-equal "<=: fix/flo" (<= 33 44.0) #t)
 (test-equal "<: fix/flo (flo overflow), on 64 bits"
       (< 9007199254740993 9007199254740992.0) #f) ; 2^53
 (test-equal "<=: fix/flo (flo overflow), on 64 bits"
       (< 9007199254740993 9007199254740992.0) #f)
 (test-equal "<: fix/flo (flo underflow), on 64 bits"
       (< -9007199254740993 -9007199254740992.0) #t)
 (test-equal "<=: fix/flo (flo underflow), on 64 bits"
       (<= -9007199254740993 -9007199254740992.0) #t)
 (test-equal "<: !fix/flo" (< 33.0 33.0) #f)
 (test-equal "<=: fix/flo" (<= 33.0 33.0) #t)
 (test-equal "<: !fix/big" (< 44 b2) #f)
 (test-equal "<=: !fix/big" (<= 44 b2) #f)
 (test-equal "<: fix/big" (< 33 b1) #t)
 (test-equal "<=: fix/big" (<= 33 b1) #t)
 (test-equal "<: !big/big" (< b1 b1) #f)
 (test-equal "<=: big/big" (<= b1 b1) #t)
 (test-equal "<: !fix/rat" (< 44 r1) #f)
 (test-equal "<=: !fix/rat" (<= 44 r1) #f)
 (test-equal "<: fix/rat" (< 0 r1) #t)
 (test-equal "<=: fix/rat" (<= 0 r1) #t)

 (test-equal "<: !flo/fix" (< 44.0 33) #f)
 (test-equal "<=: !flo/fix" (<= 44.0 33) #f)
 (test-equal "<: flo/fix" (< 33.0 44) #t)
 (test-equal "<=: flo/fix" (<= 33.0 44) #t)
 (test-equal "<: !flo/flo" (< 44.0 33.0) #f)
 (test-equal "<=: !flo/flo" (<= 44.0 33.0) #f)
 (test-equal "<: flo/flo" (< 33.0 44.0) #t)
 (test-equal "<=: flo/flo" (<= 33.0 44.0) #t)
 (test-equal "<: !flo/big" (< 44.0 b2) #f)
 (test-equal "<=: !flo/big" (<= 44.0 b2) #f)
 (test-equal "<: flo/big" (< 33.0 b1) #t)
 (test-equal "<=: flo/big" (<= 33.0 b1) #t)
 (test-equal "<: flo/fix (flo overflow), on 64 bits"
       (< 9007199254740992.0 9007199254740993) #t) ; 2^53
 (test-equal "<=: flo/fix (flo overflow), on 64 bits"
       (< 9007199254740992.0 9007199254740993) #t)
 (test-equal "<: flo/fix (flo underflow), on 64 bits"
       (< -9007199254740992.0 -9007199254740993) #f)
 (test-equal "<=: flo/fix (flo underflow), on 64 bits"
       (<= -9007199254740992.0 -9007199254740993) #f)
 (test-equal "<: flo/big (flo overflow)"
       (< 1237940039285380274899124224.0 1237940039285380274899124225) #t)
 (test-equal "<=: flo/big (flo overflow)"
       (<= 1237940039285380274899124224.0 1237940039285380274899124225) #t)
 (test-equal "<: !flo/rat" (< 44.0 r1) #f)
 (test-equal "<=: !flo/rat" (<= 44.0 r1) #f)
 (test-equal "<: flo/rat" (< 0.0 r1) #t)
 (test-equal "<=: flo/rat" (<= 0.0 r1) #t)
 (test-equal "<: flo/nan" (< 0.0 +nan.0) #f)
 (test-equal "<=: flo/nan" (<= 0.0 +nan.0) #f)
 (test-equal "<: nan/flo" (< +nan.0 0.0) #f)
 (test-equal "<=: nan/flo" (<= +nan.0 0.0) #f)
 (test-equal "<: flo/flo/nan" (< 0.0 1.0 +nan.0) #f)
 (test-equal "<=: flo/flo/nan" (<= 0.0 1.0 +nan.0) #f)

 (test-equal "<: !big/fix" (< b1 33) #f)
 (test-equal "<=: !big/fix" (<= b1 33) #f)
 (test-equal "<: big/fix" (< b2 44) #t)
 (test-equal "<=: big/fix" (<= b2 44) #t)
 (test-equal "<: !big/flo" (< b1 33.0) #f)
 (test-equal "<=: !big/flo" (<= b1 33.0) #f)
 (test-equal "<: big/flo" (< b2 44.0) #t)
 (test-equal "<=: big/flo" (<= b2 44.0) #t)
 (test-equal "<: big/flo (max flo)"
       (< 1237940039285380274899124224 1237940039285380274899124224.0) #f)
 (test-equal "<=: big/flo (max flo)"
       (<= 1237940039285380274899124224 1237940039285380274899124224.0) #t)
 (test-equal "<: big/flo (max flo, smaller bignum)"
       (< 1237940039285380274899124223 1237940039285380274899124224.0) #t)
 (test-equal "<: big/flo (max flo, smaller bignum)"
       (<= 1237940039285380274899124223 1237940039285380274899124224.0) #t)
 (test-equal "<: !big/big" (< b1 b2) #f)
 (test-equal "<=: !big/big" (<= b1 b2) #f)
 (test-equal "<: big/big" (< b2 b1) #t)
 (test-equal "<=: big/big" (<= b2 b1) #t)
 (test-equal "<: !big/rat" (< b1 r1) #f)
 (test-equal "<=: !big/rat" (<= b1 r1) #f)
 (test-equal "<: big/rat" (< b2 r1) #t)
 (test-equal "<=: big/rat" (<= b2 r1) #t)

 (test-equal "<: !rat/fix" (< r2 2) #f)
 (test-equal "<=: !rat/fix" (<= r2 2) #f)
 (test-equal "<: rat/fix" (< r1 44) #t)
 (test-equal "<=: rat/fix" (<= r1 44) #t)
 (test-equal "<: !rat/flo" (< r2 2.0) #f)
 (test-equal "<=: !rat/flo" (<= r2 2.0) #f)
 (test-equal "<: rat/flo" (< b2 44.0) #t)
 (test-equal "<=: rat/flo" (<= b2 44.0) #t)
 (test-equal "<: rat/big" (< r1 b1) #t)
 (test-equal "<=: rat/big" (<= r1 b1) #t)
 (test-equal "<: !rat/rat" (< r2 r1) #f)
 (test-equal "<=: !rat/rat" (<= r2 r1) #f)
 (test-equal "<: rat/rat" (< r1 r2) #t)
 (test-equal "<=: rat/rat" (<= r1 r2) #t)
 (test-equal "<: rat/flo (flo overflow)"
       (< 1237940039285380274899124224/1237940039285380274899124223 1.0) #f)
 (test-equal "<: rat/flo (flo overflow)"
       (< 1237940039285380274899124224/1237940039285380274899124223 1.5) #t)
 (test-equal "<=: rat/flo (flo overflow)"
       (<= 1237940039285380274899124224/1237940039285380274899124223 1.0) #f)
 (test-equal "<=: rat/flo (flo overflow)"
       (<= 1237940039285380274899124224/1237940039285380274899124223 1.5) #t)
 (test-equal "<: rat/flo (flo underflow)"
       (< -1237940039285380274899124224/1237940039285380274899124223 -1.0) #t)
 (test-equal "<: rat/flo (flo underflow)"
       (< -1237940039285380274899124224/1237940039285380274899124223 -1.5) #f)
 (test-equal "<=: rat/flo (flo underflow)"
       (<= -1237940039285380274899124224/1237940039285380274899124223 -1.0) #t)
 (test-equal "<=: rat/flo (flo underflow)"
       (<= -1237940039285380274899124224/1237940039285380274899124223 -1.5) #f)
)

(test-group "complex"

 (test-equal "real-part" (real-part c1) 33)
 (test-equal "real-part of flonum" (real-part 1.23) 1.23)
 (test-equal "real-part of fixnum" (real-part 123) 123)
 (test-equal "real-part of ratnum" (real-part 1/2) 1/2)
 (test-equal "real-part of bignum" (real-part b1) b1)
 (test-equal "real-part of negative flonum" (real-part -1.23) -1.23)
 (test-equal "real-part of negative fixnum" (real-part -123) -123)
 (test-equal "real-part of negative ratnum" (real-part -1/2) -1/2)
 (test-equal "real-part of negative bignum" (real-part (- b1)) (- b1))
 (test-equal "imag-part" (imag-part c1) 44)
 (test-equal "imag-part of flonum" (imag-part 1.23) 0.0)
 (test-equal "imag-part of fixnum" (imag-part 123) 0)
 (test-equal "imag-part of ratnum" (imag-part 1/2) 0)
 (test-equal "imag-part of bignum" (imag-part b1) 0)
 (test-assert "make-polar" (show (make-polar 33 44)))
 (test-equal "magnitude" (magnitude 0+8i) 8)
 (test-equal "magnitude" (magnitude 0+1/2i) 1/2)
 (test-equal "magnitude of flonum" (magnitude 1.23) 1.23)
 (test-equal "magnitude of fixnum" (magnitude 123) 123)
 (test-equal "magnitude of ratnum" (magnitude 1/2) 1/2)
 (test-equal "magnitude of bignum" (magnitude b1) b1)
 (test-equal "magnitude of negative flonum" (magnitude -1.23) 1.23)
 (test-equal "magnitude of negative fixnum" (magnitude -123) 123)
 (test-equal "magnitude of negative ratnum" (magnitude -1/2) 1/2)
 (test-equal "magnitude of negative bignum" (magnitude (- b1)) b1)
 (test-assert "angle" (show (angle c1)))
 (test-equal "angle of flonum" (angle 1.23) 0.0)
 (test-equal "angle of fixnum" (angle 123) 0.0)
 (test-equal "angle of ratnum" (angle 1/2) 0.0)
 (test-equal "angle of bignum" (angle b1) 0.0)
 (test-equal "angle of negative flonum" (angle -1.23) pi)
 (test-equal "angle of negative fixnum" (angle -123) pi)
 (test-equal "angle of negative ratnum" (angle -1/2) pi)
 (test-equal "angle of negative bignum" (angle (- b1)) pi)
)

(test-group "rational"

 ;; Use equal? instead of = to check equality and exactness in one go
 (parameterize ((current-test-comparator equal?))
   (test-assert (show (numerator b1)))
   (test-equal (numerator r1) 3)
   (test-equal (numerator 33) 33)
   (test-equal (denominator r1) 4)
   (test-equal (denominator b1) 1)
   (test-equal (denominator 33) 1)
   (test-equal (numerator 0) 0)
   (test-equal (denominator 0) 1)
   (test-equal (numerator 3) 3)
   (test-equal (denominator 3) 1)
   (test-equal (numerator -3) -3)
   (test-equal (denominator -3) 1)
   (test-equal (numerator 0.5) 1.0)
   (test-equal (denominator 0.5) 2.0)
   (test-equal (numerator 1.25) 5.0)
   (test-equal (denominator 1.25) 4.0)
   (test-equal (numerator -1.25) -5.0)
   (test-equal (denominator -1.25) 4.0)
   (test-equal (numerator 1e10) 1e10)
   (test-equal (denominator 1e10) 1.0))
 (test-error (numerator +inf.0))
 (test-error (numerator +nan.0))
 (test-error (denominator +inf.0))
 (test-error (denominator +nan.0))

)

(test-group "misc"

 (test-equal "inexact->exact" (inexact->exact 2.3) 2589569785738035/1125899906842624)
 (test-error "inexact->exact +inf" (inexact->exact +inf.0))
 (test-error "inexact->exact -inf" (inexact->exact -inf.0))
 (test-error "inexact->exact -NaN" (inexact->exact +nan.0))
 (test-equal "sqrt (integer result)" (sqrt 16) 4)
 (test-equal "sqrt (exact result)" (sqrt 1/4) 1/2)
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "sqrt (inexact result)" (sqrt 2) 1.4142135623730951))
 (test-equal "sqrt (inexact input)" (sqrt 4.0) 2.0)
 (test-equal "sqrt (exact large number)" (sqrt (* max-fix max-fix)) max-fix)
 (test-error "exact-integer-sqrt (nonint flonum)" (exact-integer-sqrt 1.5))
 (test-error "exact-integer-sqrt (ratnum)" (exact-integer-sqrt 1/2))
 (test-error "exact-integer-sqrt (int flonum)" (exact-integer-sqrt 4.0))
 (test-equal "exact-integer-sqrt (w/o rest)"
       (receive x (exact-integer-sqrt (* max-fix max-fix)) x)
       (list max-fix 0))
 (test-equal "exact-integer-sqrt (with rest)"
       (receive x (exact-integer-sqrt (+ (* max-fix max-fix) 5)) x)
       (list max-fix 5))
 (test-equal "exact-integer-nth-root without rest"
       (receive x (exact-integer-nth-root 243 5) x)
       (list 3 0))
 (test-equal "exact-integer-nth-root with rest"
       (receive x (exact-integer-nth-root 128 4) x)
       (list 3 47))
 (test-equal "exact-integer-nth-root with insanely large base"
       (receive x (exact-integer-nth-root 5 (if 64-bits? 10000000000 100000000)) x)
       (list 1 4))
 (test-equal "expt" (expt 2 4) 16)
 (test-assert "expt" (show (expt 2 100)))
 ;; The next three according to R7RS
 (test-equal "expt 0.0^0.0)" (expt 0.0 0.0) 1.0)
 (test-equal "expt 0.0^{pos}" (expt 0.0 1.0) 0.0)
 ;; An error is not mandatory:
 ;; "[...] either an error is signalled or an unspecified number is returned."
 ;(test-error "expt 0.0^{neg}" (expt 0.0 -1.0))
 ;; R7 doesn't say anything specific about fixnums, so I guess this should behave the same
 (test-equal "expt 0^0" (expt 0 0) 1)
 (test-equal "expt 0^{pos}" (expt 0 1) 0)
 (test-error "expt 0^{neg}" (expt 0 -1))
 (test-equal "expt (rat base)" (expt 1/2 2) 1/4)
 (test-equal "expt (rat exponent)" (expt 16 1/4) 2)
 (test-equal "expt (negative rat exponent)" (expt 16 -1/4) 1/2)
 (test-equal "expt (inexact from rat exponent)" (expt 2 1/7) 1.1040895136738123)
 (test-equal "expt (> 1 rat exponent)" (expt 1/64 3/2) 1/512)
 (test-equal "expt (rat base & exponent)" (expt 1/4 1/2) 1/2)
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "expt (negative w/ rat exponent)" (expt -16 1/4) 1.4142135623731+1.41421356237309i))
 (test-assert "expt" (show (expt 2 2.0)))
 (test-assert "expt" (show (expt 2 -1)))
 (test-equal "expt between double and 64-bit integer value"
       (expt 999 6) 994014980014994001)
 (parameterize ((current-test-epsilon 1e-10)) 
   (test-equal "expt with complex result" (expt -1 1.5) -1.836909530733566e-16-1.0i))
 (test-equal "exact expt with complex number" (expt 0+1i 5) 0+1i)
 (test-equal "exact expt with complex number, real result" (expt 0+1i 6) -1)
 (test-equal "inexact expt with complex number" (expt 0.0+1.0i 5.0) 0.0+1.0i)
 (test-equal "inexact expt with complex number, real result" (expt 0.0+1.0i 6.0) -1.0)
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "inexact noninteger expt with complex number"
         (expt 0.0+4.0i 0.5) 1.4142135623731+1.41421356237309i)
   (test-equal "exp with complex numbers" (exp 1+i) 1.4686939399158851+2.2873552871788423i))

 (test-equal "log of exp = 1" (log (exp 1)) 1.0)
 (test-assert "log(-x) = compnum" (cplxnum? (log -2.0)))
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "log of -1" (log -1) 0.0+3.141592653589793i))
 ;; XXX We should probably attempt to make this return an exact number
 (parameterize ((current-test-epsilon 1e-10))
   (test-equal "log(expt(2,x),2) = x" (log (expt 2 500) 2) 500.0)
   (test-equal "log with complex number" (log +i) 0.0+1.5707963267948966i)

   (test-equal "exp(log(x)) = x" (exp (log 2.0-3.0i)) 2.0-3.0i)
   (test-equal "log(exp(x)) = x" (log (exp 2.0-3.0i)) 2.0-3.0i)
   (test-equal "log(expt(2,x),2) = x" (log (expt 2 2.0-3.0i) 2) 2.0-3.0i))

 (letrec ((fac (lambda (n)
                 (if (zero? n)
                     1
                     (* n (fac (- n 1))) ) ) ) )
   (test-assert "bigfac" (show (fac 100)))
   (test-equal "zero signum fixnum" (signum 0) 0)
   (test-equal "zero signum flonum" (signum .0) 0.0)
   (test-equal "positive signum fixnum" (signum 2) 1)
   (test-equal "positive signum ratnum" (signum 1/2) 1)
   (test-equal "positive signum flonum" (signum 2.0) 1.0)
   (test-equal "positive signum bignum" (signum b1) 1)
   (test-equal "negative signum fixnum" (signum -2) -1)
   (test-equal "negative signum ratnum" (signum -1/2) -1)
   (test-equal "negative signum flonum" (signum -2) -1)
   (test-equal "negative signum bignum" (signum (- b1)) -1)
   ;; From CLHS
   (parameterize ((current-test-epsilon 1e-10))
     (test-equal "positive signum compnum(1)" (signum 0+33i) 0+1i)
     (test-equal "positive signum compnum(2)" (signum 7.5+10.0i) 0.6+0.8i)
     (test-equal "negative signum compnum " (signum 0.0-14.7i) 0.0-1.0i)))
 (test-equal "most-negative-fixnum + most-negative-fixnum = 2 * most-negative-fixnum"
       (+ most-negative-fixnum most-negative-fixnum) (* 2 most-negative-fixnum))
 (test-equal "most-negative-fixnum - most-negative-fixnum = 0"
       (- most-negative-fixnum most-negative-fixnum) 0)
 (test-equal "most-positive-fixnum + most-positive-fixnum = 2 * most-positive-fixnum"
       (+ most-positive-fixnum most-positive-fixnum) (* 2 most-positive-fixnum))
 (test-equal "most-positive-fixnum - most-positive-fixnum = 0"
       (- most-positive-fixnum most-positive-fixnum) 0)
)


(test-group "R5RS"

 (test-equal "+" (+ 3 4) 7)
 (test-equal "+" (+ 3) 3)
 (test-equal "+" (+) 0)
 (test-equal "*" (* 4) 4)
 (test-equal "*" (*) 1)

 (test-equal "-" (- 3 4) -1)
 (test-equal "-" (- 3 4 5) -6)
 (test-equal "-" (- 3) -3)
 (test-assert "/ (3/20)" (show (/ 3 4 5)))
 (test-assert "/ (1/3)" (show (/ 3)))

 (test-equal "numerator" (numerator (/ 6 4)) 3)
 (test-equal "denominator" (denominator (/ 6 4)) 2)

 (test-equal "complex?" (complex? c1) #t)
 (test-equal "complex?" (complex? 3) #t)
 (test-equal "real?" (real? 3) #t)
 (test-equal "real?" (real? (make-rectangular -2.5 0.0)) #t)
 (test-equal "real?" (real? -2+1i) #f)
 (test-equal "real?" (real? 1e0) #t)
 (test-equal "rational?" (rational? (/ 6 10)) #t)
 (test-assert "check rational" (show (/ 6 3)))
 (test-equal "rational?" (rational? (/ 6 3)) #t)
 (test-equal "integer?" (integer? (make-rectangular 3 0)) #t)
 (test-equal "integer?" (integer? 1+3i) #f)
 (test-equal "integer?" (integer? 3.0) #t)
 (test-equal "integer?" (integer? (/ 8 4)) #t)
 (test-equal "integer?" (integer? 1/2) #f)
 (test-equal "exact-integer?" (exact-integer? (make-rectangular 3 0)) #t)
 (test-equal "exact-integer?" (exact-integer? 1+3i) #f)
 (test-equal "exact-integer?" (exact-integer? 3.0) #f)
 (test-equal "exact-integer?" (exact-integer? (/ 8 4)) #t)
 (test-equal "exact-integer?" (exact-integer? 1/2) #f)

 (test-equal "max" (max 3 4) 4)
 (test-equal "max" (max 3.9 4) 4.0)

 (test-equal "modulo" (modulo 13 4) 1)
 (test-equal "modulo" (modulo 13.0 4) 1.0)
 (test-equal "modulo" (modulo 13 4.0) 1.0)
 (test-error "modulo" (modulo 13.1 4.0))
 (test-error "modulo" (modulo 13.0 4.1))
 (test-equal "remainder" (remainder 13 4) 1)
 (test-error "remainder" (remainder 13.1 4.0))
 (test-error "remainder" (remainder 13.0 4.1))
 (test-equal "modulo" (modulo -13 4) 3)
 (test-equal "remainder" (remainder -13 4) -1)
 (test-equal "modulo" (modulo 13 -4) -3)
 (test-equal "remainder" (remainder 13 -4) 1)
 (test-equal "modulo" (modulo -13 -4) -1)
 (test-equal "remainder" (remainder -13 -4) -1)
 (test-equal "remainder" (remainder -13 -4.0) -1.0)

 (test-assert (even? 2))
 (test-assert (not (even? 1)))
 (test-assert (even? -2))
 (test-assert (not (even? -1)))
 (test-assert (even? 2.0))
 (test-assert (not (even? 1.0)))
 (test-assert (even? -2.0))
 (test-assert (not (even? -1.0)))
 (test-error (even? 2.1))
 (test-error (even? -2.3))
 (test-error (even? +inf.0))
 (test-error (even? +nan.0))
 (test-assert (even? (* most-positive-fixnum 2)))
 (test-assert (not (even? (+ (* most-positive-fixnum 2) 1))))
 (test-assert (odd? (+ (* most-positive-fixnum 2) 1)))
 (test-assert (not (odd? (* most-positive-fixnum 2))))
 (test-error (even? 2.0+3.0i))
 (test-error (even? 2+3i))
 (test-error (odd? 2.0+3.0i))
 (test-error (odd? 2+3i))

 (test-equal "floor" (floor -4.3) -5.0)
 (test-equal "ceiling" (ceiling -4.3) -4.0)
 (test-equal "truncate" (truncate -4.3) -4.0)
 (test-equal "round" (round -4.3) -4.0)
 (test-equal "floor" (floor 3.5) 3.0)
 (test-equal "ceiling" (ceiling 3.5) 4.0)
 (test-equal "truncate" (truncate 3.5) 3.0)
 (test-equal "round" (round 3.5) 4.0)
 (test-equal "round" (round 4.5) 4.0)
 (test-equal "round" (round (/ 7 2)) 4)
 (test-equal "round" (round 7) 7)

 (test-equal "rationalize (1/3)" (rationalize (inexact->exact .3) (/ 1 10)) 1/3)
 (test-equal "rationalize (#i1/3)" (rationalize .3 (/ 1 10)) #i1/3)
)

(test-group "bitwise ops"

 (test-equal "and" (bitwise-and #xff #x1) 1)
 (test-equal "zero-arg and" (bitwise-and) -1) ; Arbitrary, but specified by srfi-33
 (test-equal "ior" (bitwise-ior #x0f #x1) #xf)
 (test-equal "zero-arg ior" (bitwise-ior) 0)  ; Same
 (test-equal "xor" (bitwise-xor #x0f #x1) 14)
 (test-equal "zero-arg xor" (bitwise-xor) 0)  ; Same
 (test-assert "not" (show (bitwise-not #x0f)))
 (test-error (bitwise-and 'x))
 (test-error (bitwise-xor 'x))
 (test-error (bitwise-ior 'x))
 (test-error (bitwise-and 1 'x))
 (test-error (bitwise-xor 1 'x))
 (test-error (bitwise-ior 1 'x))
 (test-error (bit->boolean 1 -1))
 (test-error (bit->boolean b1 -1))
 (test-error (bit->boolean 1 1.0))
 (test-error (bit->boolean 1.0 1))
 (test-equal (bit->boolean -1 b1) #t)
 (test-equal (bit->boolean 0 b1) #f)
 (test-equal (bit->boolean 5 2) #t)
 (test-equal (bit->boolean 5 0) #t)
 (test-equal (bit->boolean 5 1) #f)
 (test-equal (bit->boolean -2 0) #f)
 (test-equal (bit->boolean -2 1) #t)
 (test-equal (bit->boolean (expt -2 63) 256) #t)
 (test-equal (bit->boolean (expt 2 63) 256) #f)
 (test-equal (arithmetic-shift 15 2) 60)
 (test-equal (arithmetic-shift 15 -2) 3)
 (test-equal (arithmetic-shift -15 2) -60)
 (test-equal (arithmetic-shift -15 -2) -4) ; 2's complement
 (test-equal (arithmetic-shift -31 most-negative-fixnum) -1)
 (test-equal (arithmetic-shift 31 most-negative-fixnum) 0)
 (test-equal (arithmetic-shift b1 0) b1)
 (test-equal (arithmetic-shift (arithmetic-shift b1 -1) 1) b1)
 (test-error (arithmetic-shift 0.1 2))
 ;; XXX Do the following two need to fail?  Might as well use the integral value
 (test-error (arithmetic-shift #xf 2.0))
 (test-error (arithmetic-shift #xf -2.0))
 (test-error (arithmetic-shift #xf 2.1))
 (test-error (arithmetic-shift #xf -2.1))
 (test-error (arithmetic-shift +inf.0 2))
 (test-error (arithmetic-shift +nan.0 2))
 (when 64-bits?
   (test-equal (arithmetic-shift (expt 2 31) (- (expt 2 31))) 0))

 ;; by Jeremy Sydik
 (let ((leftrot32
        (lambda (value amount)
          (let ((shifted (arithmetic-shift value amount)))
            (let ((anded (bitwise-and #xFFFFFFFF shifted)))
              (bitwise-ior anded
                           (arithmetic-shift shifted -32)))) ))) 
   (test-equal "leftrot32 28" (leftrot32 1 28) 268435456)
   (test-equal "leftrot32 29" (leftrot32 1 29) 536870912)
   (test-equal "leftrot32 30" (leftrot32 1 30) 1073741824))
)

(test-group "string conversion"

 (test-assert "fix" (number->string 123))
 (test-assert "fix/base" (number->string 123 16))
 (test-assert "flo" (number->string 99.2))
 (test-assert "big" (number->string b1))
 (test-assert "big/base" (number->string b1 2))
 (test-assert "rat" (number->string r1))
 (test-assert "comp" (number->string c1))

 (test-equal "edge case printing"
       (number->string (expt 2 256) 16)
       "10000000000000000000000000000000000000000000000000000000000000000")
 (test-equal "non-exact multiple of 64 length edge case printing"
       "4000000000000000000000" (number->string (expt 2 65) 8))
 (test-equal "another non-exact multiple of 64 length edge case printing"
       "200000000000000000000000" (number->string (expt 2 70) 8))
 (test-equal "edge case length calculation"
       "10000000000000000000000000000000000000000000000000000000000000000000000" (number->string (expt 2 210) 8))
 (test-equal "positive hexdigit invariance"
       (number->string
        (string->number "123456789abcdef123456789abcdef123456789abcdef" 16)
        16)
       "123456789abcdef123456789abcdef123456789abcdef")
 (test-equal "negative hexdigit invariance"
       (number->string
        (string->number "-123456789abcdef123456789abcdef123456789abcdef" 16)
        16)
       "-123456789abcdef123456789abcdef123456789abcdef")

 (test-equal "fix" (string->number "123") 123)
 (test-equal "fix/base" (string->number "ff" 16) 255)
 (test-equal "fix/base-o" (string->number "16" 8) 14)
 (test-equal "fix/unusual-base" (string->number "1234" 5) 194)
 (test-equal "fix/wrong-base" (string->number "1234" 4) #f)
 (test-error "fix/invalid-base" (string->number "1234" 0))
 (test-error "fix/invalid-base" (string->number "1234" 1))
 (test-equal "embedded base overrides supplied base" (string->number "#x10" 10) 16)
 (test-equal "flo" (string->number "123.23") 123.23)
 (test-equal "flo2" (string->number "1e2") 100.0)
 (test-assert "big" (show (string->number "123873487384737447")))
 (test-assert "big/neg" (show (string->number "-123873487384737447")))
 (test-assert "big/pos" (show (string->number "+123873487384737447")))
 (test-assert "rat" (show (string->number "123/456")))
 (test-assert "rat/neg" (show (string->number "-123/456")))
 (test-assert "rat/pos" (show (string->number "+123/456")))
 (test-assert "rat2" (show (string->number "#o123/456")))
 (test-equal "rat/inexact" (show (string->number "#i123/456")) (/ 123.0 456))
 (test-equal "invalid rat" (string->number "123/0") #f)
 (test-assert "comp" (show (string->number "+12i")))
 (test-assert "comp" (show (string->number "12+34i")))
 (test-assert "comp" (show (string->number "-i")))
 (test-assert "comp" (show (string->number "99@55")))
 (test-assert "comp" (show (string->number "1/2@3/4")))
 (test-assert "comp2" (show (string->number "#x99+55i")))
 ;; This is to check for a silly problem cause by representing numbers exactly
 ;; all the way until the end, then converting to inexact.  This "silly problem"
 ;; could probably be exploited in a resource consumption attack.
 (let* ((t1 (current-seconds))
        (i1 (string->number "1e1000000"))
        (i2 (string->number "1.0e1000000"))
        (e1 (string->number "#e1e1000000"))
        (e2 (string->number "#e1.0e1000000"))
        (t2 (current-seconds)))
   (test-assert "read time for inexacts with large positive exp isn't insanely high" (< (- t2 t1) 2))
   (test-equal "inexact read back are equal" i2 i1)
   (test-equal "inexact are inf" +inf.0 i1)
   (test-equal "exact are equal" e2 e1)
   (test-equal "exact are false" #f e1))
 (let* ((t1 (current-seconds))
        (i1 (string->number "-1e1000000"))
        (i2 (string->number "-1.0e1000000"))
        (e1 (string->number "#e-1e1000000"))
        (e2 (string->number "#e-1.0e1000000"))
        (t2 (current-seconds)))
   (test-assert "read time for inexacts with large positive exp isn't insanely high" (< (- t2 t1) 2))
   (test-equal "negative inexact read back are equal" i2 i1)
   (test-equal "negative inexact are negative inf" -inf.0 i1)
   (test-equal "negative exact are equal" e2 e1)
   (test-equal "negative exact are false" #f e1))
 (let* ((t1 (current-seconds))
        (i1 (string->number "1e-1000000"))
        (i2 (string->number "1.0e-1000000"))
        (e1 (string->number "#e1e-1000000"))
        (e2 (string->number "#e1.0e-1000000"))
        (t2 (current-seconds)))
   (test-assert "read time for inexacts with large negative exp isn't insanely high" (< (- t2 t1) 2))
   (test-equal "inexact read back are equal" i2 i1)
   (test-equal "inexact are 0" +0.0 i1)
   (test-equal "exact are equal" e2 e1)
   (test-equal "exact are false" #f e1))

 (test-group "read/write invariance of simple integers for different radices"
   (let lp ((radix 2)
            (digit 0))
     (cond ((= digit radix) (lp (add1 radix) 0))
           ((<= radix 36)
            (let* ((char (string-ref (number->string digit radix) 0))
                   (str (make-string 10 char)))
              (test-equal (sprintf "radix ~A digits ~S" radix digit)
			  (number->string (string->number str) radix)
			  (if (char=? char #\0) "0" str)))))))
)

(test-group "non-standard type procedures"

 (test-equal "fixnum" (fixnum? max-fix) #t)

 (test-equal "bignum" (bignum? b1) #t)
 (test-equal "bignum" (bignum? min-big) #t)

 (test-equal "ratnum" (ratnum? r1) #t)

 (test-equal "nan: fix" (nan? 1) #f)
 (test-equal "nan: flo" (nan? 1.0) #f)
 (test-equal "nan: +inf" (nan? (/ 1.0 0.0)) #f)
 (test-equal "nan: -inf" (nan? (/ -1.0 0.0)) #f)
 (test-equal "nan: nan" (nan? (/ 0.0 0.0)) #t) 
 (test-equal "nan: nan+nani" (nan? (make-rectangular (/ 0.0 0.0) (/ 0.0 0.0))) #t)
 (test-equal "nan: flo+nani" (nan? (make-rectangular 1.0 (/ 0.0 0.0))) #t)
 (test-equal "nan: nan+floi" (nan? (make-rectangular (/ 0.0 0.0) 1.0)) #t)
 (test-error "nan: no number" (nan? 'x))

 (test-equal "finite: fix" (finite? 1) #t)
 (test-equal "finite: flo" (finite? 1.0) #t)
 (test-equal "finite: +inf" (finite? (/ 1.0 0.0)) #f)
 (test-equal "finite: -inf" (finite? (/ 1.0 0.0)) #f)
 (test-equal "finite: nan" (finite? (/ 0.0 0.0)) #f)
 (test-equal "finite: nan+floi" (finite? (make-rectangular (/ 0.0 0.0) 1.0)) #f)
 (test-equal "finite: inf+infi" (finite? (make-rectangular (/ 1.0 0.0) (/ 1.0 0.0))) #f)
 (test-equal "finite: flo+infi" (finite? (make-rectangular 1.0 (/ 1.0 0.0))) #f)
 (test-equal "finite: inf+floi" (finite? (make-rectangular (/ 1.0 0.0) 1.0)) #f)
 (test-error "finite: no number" (finite? 'x))
 
 (test-equal "infinite: fix" (infinite? 1) #f)
 (test-equal "infinite: flo" (infinite? 1.0) #f)
 (test-equal "infinite: +inf" (infinite? (/ 1.0 0.0)) #t)
 (test-equal "infinite: -inf" (infinite? (/ 1.0 0.0)) #t)
 (test-equal "infinite: nan" (infinite? (/ 0.0 0.0)) #f)
 (test-equal "infinite: inf+infi" (infinite? (make-rectangular (/ 1.0 0.0) (/ 1.0 0.0))) #t)
 (test-equal "infinite: flo+infi" (infinite? (make-rectangular 1.0 (/ 1.0 0.0))) #t)
 (test-equal "infinite: inf+floi" (infinite? (make-rectangular (/ 1.0 0.0) 1.0)) #t)
 (test-error "infinite: no number" (infinite? 'x))

 (test-equal "cplxnum: compintintnum" (cplxnum? c1) #t)
 (test-equal "cplxnum: compintflointnum" (cplxnum? 1.0+1i) #t)
 (test-equal "cplxnum: compflointnum" (cplxnum? c2) #t)
 (test-equal "cplxnum: compfloflonum" (cplxnum? 3.4-4.3i) #t)
 (test-equal "not cplxnum: fixnum" (cplxnum? 1) #f)
)

;; The usual comparator doesn't work, because zero or a very small number
;; is many times any other small number, but the absolute difference should
;; be minimal, so we compare for that instead.
(parameterize ((current-test-epsilon 1e-9)
               (current-test-comparator
                (lambda (exp act)
                  (or (and (nan? exp) (nan? act))
                      (and (< (abs (- (real-part exp) (real-part act)))
                              (current-test-epsilon))
                           (< (abs (- (imag-part exp) (imag-part act)))
                              (current-test-epsilon)))))))

  ;; We're using (acos (cos x)) instead of just (acos y) because we want
  ;; to test the compiler's specialization rules of cos output.

  (test-group "trigonometric functions"
    (test-group "flonums"
      ;; Note: we don't *actually* distinguish -nan from +nan, but whatever :)
      (test-equal "acos(-inf)" (acos -inf.0) -nan.0)
      (test-equal "acos(<small number>)" (acos -1e100) -nan.0)
      (test-equal "cos(-1/3pi)" (cos (- (/ pi 3))) 0.5)
      (test-equal "acos(cos(-1/3pi))" (acos (cos (- (/ pi 3)))) (/ pi 3))
      (test-equal "cos(-1/4pi)" (cos (- (/ pi 4))) 0.7071067811865476)
      (test-equal "acos(cos(-1/4pi))" (acos (cos (- (/ pi 4)))) (/ pi 4))
      (test-equal "cos(-1/2pi)" (cos (- (/ pi 2))) 0.0)
      (test-equal "acos(cos(-1/2pi))" (acos (cos (- (/ pi 2)))) (/ pi 2))
      (test-equal "cos(-pi)" (cos (- pi)) -1.0)
      (test-equal "acos(cos(-pi))" (acos (cos (- pi))) pi)
      (test-equal "cos(0)" (cos 0.0) 1.0)
      (test-equal "acos(cos(0))" (acos (cos 0.0)) 0.0)
      (test-equal "cos( 1/4pi)" (cos (/ pi 4)) 0.7071067811865476)
      (test-equal "acos(cos( 1/4pi))" (acos (cos (/ pi 4))) (/ pi 4))
      (test-equal "cos( 1/3pi)" (cos (/ pi 3)) 0.5)
      (test-equal "acos(cos( 1/3pi))" (acos (cos (/ pi 3))) (/ pi 3))
      (test-equal "cos( 1/2pi)" (cos (/ pi 2)) 0.0)
      (test-equal "acos(cos( 1/2pi))" (acos (cos (/ pi 2))) (/ pi 2))
      (test-equal "cos( 2/3pi)" (cos (/ (* 2 pi) 3)) -0.5)
      (test-equal "acos(cos( 2/3pi))" (acos (cos (/ (* 2 pi) 3))) (/ (* 2 pi) 3))
      (test-equal "cos( 3/4pi)" (cos (* (/ pi 4) 3)) -0.7071067811865476)
      (test-equal "acos(cos( 3/4pi))" (acos (cos (* (/ pi 4) 3))) (* (/ pi 4) 3))
      (test-equal "cos(    pi)" (cos pi) -1.0)
      (test-equal "acos(cos(    pi))" (acos (cos pi)) pi)
      (test-equal "cos( 3/2pi)" (cos (+ pi (/ pi 2))) 0.0)
      (test-equal "acos(cos( 3/2pi))" (acos (cos (+ pi (/ pi 2)))) (/ pi 2))
      (test-equal "cos( 4/3pi)" (cos (+ pi (/ pi 3))) -0.5)
      (test-equal "acos(cos( 4/3pi))" (acos (cos (+ pi (/ pi 3)))) (* 2 (/ pi 3)))
      (test-equal "cos( 5/4pi)" (cos (+ pi (/ pi 4))) -0.7071067811865476)
      (test-equal "acos(cos( 5/4pi))" (acos (cos (+ pi (/ pi 4)))) (* 3 (/ pi 4)))
      (test-equal "cos(   2pi)" (cos (* 2 pi)) 1.0)
      (test-equal "acos(cos(   2pi))" (acos (cos (* 2 pi))) 0)
      (test-equal "acos(pi)" (acos pi) 0.0+1.81152627246085i)
      (test-equal "acos(+inf)" (acos +inf.0) -nan.0)

      (test-equal "asin(-inf)" (asin -inf.0) -nan.0)
      (test-equal "asin(<small number>)" (asin -1e100) -nan.0)
      (test-equal "sin(-1/3pi)" (sin (- (/ pi 3))) -0.8660254037844386)
      (test-equal "asin(sin(-1/3pi))" (asin (sin (- (/ pi 3)))) (- (/ pi 3)))
      (test-equal "sin(-1/4pi)" (sin (- (/ pi 4))) -0.7071067811865476)
      (test-equal "asin(sin(-1/4pi))" (asin (sin (- (/ pi 4)))) (- (/ pi 4)))
      (test-equal "sin(-1/2pi)" (sin (- (/ pi 2))) -1.0)
      (test-equal "asin(sin(-1/2pi))" (asin (sin (- (/ pi 2)))) (- (/ pi 2)))
      (test-equal "sin(-pi)" (sin (- pi)) 0.0)
      (test-equal "asin(sin(-pi))" (asin (sin (- pi))) 0.0)
      (test-equal "sin(0)" (sin 0.0) 0.0)
      (test-equal "asin(sin(0))" (asin (sin 0.0)) 0.0)
      (test-equal "sin( 1/4pi)" (sin (/ pi 4)) 0.7071067811865476)
      (test-equal "asin(sin( 1/4pi))" (asin (sin (/ pi 4))) (/ pi 4))
      (test-equal "sin( 1/3pi)" (sin (/ pi 3)) 0.8660254037844386)
      (test-equal "asin(sin( 1/3pi))" (asin (sin (/ pi 3))) (/ pi 3))
      (test-equal "sin( 1/2pi)" (sin (/ pi 2)) 1.0)
      (test-equal "asin(sin( 1/2pi))" (asin (sin (/ pi 2))) (/ pi 2))
      (test-equal "sin( 2/3pi)" (sin (/ (* 2 pi) 3)) 0.8660254037844386)
      (test-equal "asin(sin( 2/3pi))" (asin (sin (/ (* 2 pi) 3))) (/ pi 3))
      (test-equal "sin( 3/4pi)" (sin (* (/ pi 4) 3)) 0.7071067811865476)
      (test-equal "asin(sin( 3/4pi))" (asin (sin (* (/ pi 4) 3))) (/ pi 4))
      (test-equal "sin(    pi)" (sin pi) 0.0)
      (test-equal "asin(sin(    pi))" (asin (sin pi)) 0.0)
      (test-equal "sin( 3/2pi)" (sin (+ pi (/ pi 2))) -1.0)
      (test-equal "asin(sin( 3/2pi))" (asin (sin (+ pi (/ pi 2)))) (- (/ pi 2)))
      (test-equal "sin( 4/3pi)" (sin (+ pi (/ pi 3))) -0.8660254037844386)
      (test-equal "asin(sin( 4/3pi))" (asin (sin (+ pi (/ pi 3)))) (- (/ pi 3)))
      (test-equal "sin( 5/4pi)" (sin (+ pi (/ pi 4))) -0.7071067811865476)
      (test-equal "asin(sin( 5/4pi))" (asin (sin (+ pi (/ pi 4)))) (- (/ pi 4)))
      (test-equal "sin(   2pi)" (sin (* 2 pi)) 0.0)
      (test-equal "asin(sin(   2pi))" (asin (sin (* 2 pi))) 0.0)
      (test-equal "asin(pi)" (asin pi) 1.57079632679490-1.81152627246085i)
      (test-equal "asin(+inf)" (asin +inf.0) -nan.0)
      
      (test-equal "atan(-inf)" (atan -inf.0) (- (/ pi 2)))
      (test-equal "atan(<small number>)" (atan -1e100) (- (/ pi 2)))
      (test-equal "tan(-1/3pi)" (tan (- (/ pi 3))) -1.7320508075688773)
      (test-equal "atan(tan(-1/3pi))" (atan (tan (- (/ pi 3)))) (- (/ pi 3)))
      (test-equal "tan(-1/4pi)" (tan (- (/ pi 4))) -1.0)
      (test-equal "atan(tan(-1/4pi))" (atan (tan (- (/ pi 4)))) (- (/ pi 4)))
      ;; NOTE: tan(-(/ pi 2)) should be -inf(?), but isn't.  Is that a bug?
      (test-equal "tan(-pi)" (tan (- pi)) 0.0)
      (test-equal "atan(tan(-pi))" (atan (tan (- pi))) 0.0)
      (test-equal "tan(0)" (tan 0.0) 0.0)
      (test-equal "atan(tan(0))" (atan (tan 0.0)) 0.0)
      (test-equal "tan( 1/4pi)" (tan (/ pi 4)) 1.0)
      (test-equal "atan(tan( 1/4pi))" (atan (tan (/ pi 4))) (/ pi 4))
      (test-equal "tan( 1/3pi)" (tan (/ pi 3)) 1.7320508075688773)
      (test-equal "atan(tan( 1/3pi))" (atan (tan (/ pi 3))) (/ pi 3))
      (test-equal "tan( 2/3pi)" (tan (/ (* 2 pi) 3)) -1.7320508075688773)
      (test-equal "atan(tan( 2/3pi))" (atan (tan (/ (* 2 pi) 3))) (- (/ pi 3)))
      (test-equal "tan( 3/4pi)" (tan (* (/ pi 4) 3)) -1.0)
      (test-equal "atan(tan( 3/4pi))" (atan (tan (* (/ pi 4) 3))) (- (/ pi 4)))
      (test-equal "tan(    pi)" (tan pi) 0.0)
      (test-equal "atan(tan(    pi))" (atan (tan pi)) 0.0)
      (test-equal "tan( 4/3pi)" (tan (+ pi (/ pi 3))) 1.7320508075688773)
      (test-equal "atan(tan( 4/3pi))" (atan (tan (+ pi (/ pi 3)))) (/ pi 3))
      (test-equal "tan( 5/4pi)" (tan (+ pi (/ pi 4))) 1.0)
      (test-equal "atan(tan( 5/4pi))" (atan (tan (+ pi (/ pi 4)))) (/ pi 4))
      (test-equal "tan(   2pi)" (tan (* 2 pi)) 0.0)
      (test-equal "atan(tan(   2pi))" (atan (tan (* 2 pi))) 0.0)
      (test-equal "atan(pi)" (atan 1e100) (/ pi 2))
      (test-equal "atan(+inf)" (atan +inf.0) (/ pi 2))

      (test-equal "atan2(3, tan(pi))" (atan 3 (tan pi)) (/ pi 2))
      (test-equal "atan2(3, -tan(pi))" (atan 3 (- (tan pi))) (/ pi 2))
      (test-equal "atan2(-3, tan(pi))" (atan -3 (tan pi)) (- (/ pi 2)))
      (test-equal "atan2(-3, -tan(pi))" (atan -3 (- (tan pi))) (- (/ pi 2)))
      ;; Equivalence described in R5RS
      (test-equal "atan2(1, 2) = angle(2+i)"
            (angle (make-rectangular 2 1)) (atan 1 2))
      (test-equal "atan2(1, b1) = angle(2+i)"
            (angle (make-rectangular b1 1)) (atan 1 b1))
      (test-equal "atan2(b1, 1) = angle(2+i)"
            (angle (make-rectangular 1 b1)) (atan b1 1))
      (test-equal "atan2(-0.1, 3.2) = angle(3.2-0.1i)"
            (angle (make-rectangular 3.2 -0.1)) (atan -0.1 3.2))
      )

    ;; Cross-checked against Gauche and Scheme48's output
    (test-group "compnums"
      (test-equal "cos(0.0+1.0i)" (cos (make-rectangular 0.0 1.0))
            1.5430806348152437)
      (test-equal "acos(cos(0.0+1.0i))" (acos (cos (make-rectangular 0.0 1.0)))
            0.0+1.0i)
      (test-equal "cos(0.0-1.0i)" (cos (make-rectangular 0.0 -1.0))
            1.5430806348152437)
      (test-equal "acos(cos(0.0-1.0i))" (acos (cos (make-rectangular 0.0 -1.0)))
            0.0+1.0i)
      (test-equal "cos(0.0+3.0i)" (cos (make-rectangular 0.0 3.0))
            10.067661995777765)
      (test-equal "acos(cos(0.0+3.0i))" (acos (cos (make-rectangular 0.0 3.0)))
            0.0+3.0i)
      (test-equal "cos(0.0-3.0i)" (cos (make-rectangular 0.0 -3.0))
            10.067661995777765)
      (test-equal "acos(cos(0.0-3.0i))" (acos (cos (make-rectangular 0.0 -3.0)))
            0.0+3.0i)
      (test-equal "cos(0.5+0.5i)"
            (cos (make-rectangular 0.5 0.5))
            (make-rectangular 0.9895848833999199 -0.24982639750046154))
      (test-equal "acos(cos(0.5+0.5i))"
            (acos (cos (make-rectangular 0.5 0.5)))
            (make-rectangular 0.5 0.5))
      (test-equal "cos(0.5-0.5i)"
            (cos (make-rectangular 0.5 -0.5))
            (make-rectangular 0.9895848833999199 0.24982639750046154))
      (test-equal "acos(cos(0.5-0.5i))"
            (acos (cos (make-rectangular 0.5 -0.5)))
            (make-rectangular 0.5 -0.5))
      (test-equal "cos(-0.5-0.5i)"
            (cos (make-rectangular -0.5 -0.5))
            (make-rectangular 0.9895848833999199 -0.24982639750046154))
      (test-equal "acos(cos(-0.5-0.5i))"
            (acos (cos (make-rectangular -0.5 -0.5)))
            (make-rectangular 0.5 0.5))
      (test-equal "cos(-0.5+0.5i)"
            (cos (make-rectangular -0.5 0.5))
            (make-rectangular 0.9895848833999199 0.24982639750046154))
      (test-equal "acos(cos(-0.5+0.5i))"
            (acos (cos (make-rectangular -0.5 0.5)))
            (make-rectangular 0.5 -0.5))
      (test-equal "cos(-1.0+1.0i)"
            (cos (make-rectangular -1.0 1.0))
            (make-rectangular 0.8337300251311491 0.9888977057628651))
      (test-equal "acos(cos(-1.0+1.0i))"
            (acos (cos (make-rectangular -1.0 1.0)))
            (make-rectangular 1.0 -1.0))
      (test-equal "cos(-1.0-1.0i)"
            (cos (make-rectangular -1.0 -1.0))
            (make-rectangular 0.8337300251311491 -0.9888977057628651))
      (test-equal "acos(cos(-1.0-1.0i))"
            (acos (cos (make-rectangular -1.0 -1.0)))
            (make-rectangular 1.0 1.0))
      (test-equal "cos(1.0-1.0i)"
            (cos (make-rectangular 1.0 -1.0))
            (make-rectangular 0.8337300251311491 0.9888977057628651))
      (test-equal "acos(cos(1.0-1.0i))"
            (acos (cos (make-rectangular 1.0 -1.0)))
            (make-rectangular 1.0 -1.0))
      (test-equal "cos(1.0+1.0i)"
            (cos (make-rectangular 1.0 1.0))
            (make-rectangular 0.8337300251311491 -0.9888977057628651))
      (test-equal "acos(cos(1.0+1.0i))"
            (acos (cos (make-rectangular 1.0 1.0)))
            (make-rectangular 1.0 1.0))
      (test-equal "cos(2.0+3.0i)"
            (cos (make-rectangular 2.0 3.0))
            (make-rectangular -4.189625690968807 -9.109227893755337))
      (test-equal "acos(cos(2.0+3.0i))"
            (acos (cos (make-rectangular 2.0 3.0)))
            (make-rectangular 2.0 3.0))
      (test-equal "cos(-2.0+3.0i)"
            (cos (make-rectangular -2.0 3.0))
            (make-rectangular -4.189625690968807 9.109227893755337))
      (test-equal "acos(cos(-2.0+3.0i))"
            (acos (cos (make-rectangular -2.0 3.0)))
            (make-rectangular 2.0 -3.0))
      (test-equal "cos(-2.0-3.0i)"
            (cos (make-rectangular -2.0 -3.0))
            (make-rectangular -4.189625690968807 -9.109227893755337))
      (test-equal "acos(cos(-2.0-3.0i))"
            (acos (cos (make-rectangular -2.0 -3.0)))
            (make-rectangular 2.0 3.0))
      (test-equal "cos(2.0-3.0i)"
            (cos (make-rectangular 2.0 -3.0))
            (make-rectangular -4.189625690968807 9.109227893755337))
      (test-equal "acos(cos(2.0-3.0i))"
            (acos (cos (make-rectangular 2.0 -3.0)))
            (make-rectangular 2.0 -3.0))
      ;; Specialization check
      (test-equal "cos(acos(2.0-3.0i))"
            (cos (acos (make-rectangular 2.0 -3.0)))
            (make-rectangular 2.0 -3.0))

      (test-equal "sin(0.0+1.0i)"
            (sin (make-rectangular 0.0 1.0))
            (make-rectangular 0.0 1.1752011936438014))
      (test-equal "asin(sin(0.0+1.0i))"
            (asin (sin (make-rectangular 0.0 1.0)))
            (make-rectangular 0.0 1.0))
      (test-equal "sin(0.0-1.0i)"
            (sin (make-rectangular 0.0 -1.0))
            (make-rectangular 0.0 -1.1752011936438014))
      (test-equal "asin(sin(0.0-1.0i))"
            (asin (sin (make-rectangular 0.0 -1.0)))
            (make-rectangular 0.0 -1.0))
      (test-equal "sin(0.0+3.0i)"
            (sin (make-rectangular 0.0 3.0))
            (make-rectangular 0.0 10.017874927409903))
      (test-equal "asin(sin(0.0+3.0i))"
            (asin (sin (make-rectangular 0.0 3.0)))
            (make-rectangular 0.0 3.0))
      (test-equal "sin(0.0-3.0i)"
            (sin (make-rectangular 0.0 -3.0))
            (make-rectangular 0.0 -10.017874927409903))
      (test-equal "asin(sin(0.0-3.0i))"
            (asin (sin (make-rectangular 0.0 -3.0)))
            (make-rectangular 0.0 -3.0))
      (test-equal "sin(0.5+0.5i)"
            (sin (make-rectangular 0.5 0.5))
            (make-rectangular 0.5406126857131534 0.4573041531842493))
      (test-equal "asin(sin(0.5+0.5i))"
            (asin (sin (make-rectangular 0.5 0.5)))
            (make-rectangular 0.5 0.5))
      (test-equal "sin(0.5-0.5i)"
            (sin (make-rectangular 0.5 -0.5))
            (make-rectangular 0.5406126857131534 -0.4573041531842493))
      (test-equal "asin(sin(0.5-0.5i))"
            (asin (sin (make-rectangular 0.5 -0.5)))
            (make-rectangular 0.5 -0.5))
      (test-equal "sin(-0.5-0.5i)"
            (sin (make-rectangular -0.5 -0.5))
            (make-rectangular -0.5406126857131534 -0.4573041531842493))
      (test-equal "asin(sin(-0.5-0.5i))"
            (asin (sin (make-rectangular -0.5 -0.5)))
            (make-rectangular -0.5 -0.5))
      (test-equal "sin(-0.5+0.5i)"
            (sin (make-rectangular -0.5 0.5))
            (make-rectangular -0.5406126857131534 +0.457304153184249))
      (test-equal "asin(sin(-0.5+0.5i))"
            (asin (sin (make-rectangular -0.5 0.5)))
            (make-rectangular -0.5 +0.5))
      (test-equal "sin(-1.0+1.0i)"
            (sin (make-rectangular -1.0 1.0))
            (make-rectangular -1.2984575814159773 0.6349639147847361))
      (test-equal "asin(sin(-1.0+1.0i))"
            (asin (sin (make-rectangular -1.0 1.0)))
            (make-rectangular -1.0 1.0))
      (test-equal "sin(-1.0-1.0i)"
            (sin (make-rectangular -1.0 -1.0))
            (make-rectangular -1.2984575814159773 -0.6349639147847361))
      (test-equal "asin(sin(-1.0-1.0i))"
            (asin (sin (make-rectangular -1.0 -1.0)))
            (make-rectangular -1.0 -1.0))
      (test-equal "sin(1.0-1.0i)"
            (sin (make-rectangular 1.0 -1.0))
            (make-rectangular 1.2984575814159773 -0.6349639147847361))
      (test-equal "asin(sin(1.0-1.0i))"
            (asin (sin (make-rectangular 1.0 -1.0)))
            (make-rectangular 1.0 -1.0))
      (test-equal "sin(2.0+3.0i)"
            (sin (make-rectangular 2.0 3.0))
            (make-rectangular 9.15449914691143 -4.168906959966565))
      (test-equal "asin(sin(2.0+3.0i))"
            (asin (sin (make-rectangular 2.0 3.0)))
            (make-rectangular 1.1415926535898042 -3.0))
      (test-equal "sin(-2.0+3.0i)"
            (sin (make-rectangular -2.0 3.0))
            (make-rectangular -9.15449914691143 -4.168906959966565))
      (test-equal "asin(sin(-2.0+3.0i))"
            (asin (sin (make-rectangular -2.0 3.0)))
            (make-rectangular -1.1415926535898042 -3.0))
      (test-equal "sin(-2.0-3.0i)"
            (sin (make-rectangular -2.0 -3.0))
            (make-rectangular -9.15449914691143 4.168906959966565))
      (test-equal "asin(sin(-2.0-3.0i))"
            (asin (sin (make-rectangular -2.0 -3.0)))
            (make-rectangular -1.1415926535898042 3.0))
      (test-equal "sin(2.0-3.0i)"
            (sin (make-rectangular 2.0 -3.0))
            (make-rectangular 9.15449914691143 4.168906959966565))
      (test-equal "asin(sin(2.0-3.0i))"
            (asin (sin (make-rectangular 2.0 -3.0)))
            (make-rectangular 1.1415926535898042 3.0))
      ;; Specialization check
      (test-equal "sin(asin(1.1415926535898042+3.0i))"
            (sin (asin (make-rectangular 2.0 3.0)))
            (make-rectangular 2.0 3.0))

      (test-equal "tan(0.0+1.0i)"
            (tan (make-rectangular 0.0 1.0))
            (make-rectangular 0.0 0.7615941559557649))
      (test-equal "atan(tan(0.0+1.0i))"
            (atan (tan (make-rectangular 0.0 1.0)))
            (make-rectangular 0.0 1.0))
      (test-equal "tan(0.0-1.0i)"
            (tan (make-rectangular 0.0 -1.0))
            (make-rectangular 0.0 -0.7615941559557649))
      (test-equal "atan(tan(0.0-1.0i))"
            (atan (tan (make-rectangular 0.0 -1.0)))
            (make-rectangular 0.0 -1.0))
      (test-equal "tan(0.0+3.0i)"
            (tan (make-rectangular 0.0 3.0))
            (make-rectangular 0.0 0.9950547536867306))
      (test-equal "atan(tan(0.0+3.0i))"
            (atan (tan (make-rectangular 0.0 3.0)))
            (make-rectangular 0.0 3.0))
      (test-equal "tan(0.0-3.0i)"
            (tan (make-rectangular 0.0 -3.0))
            (make-rectangular 0.0 -0.9950547536867306))
      (test-equal "atan(tan(0.0-3.0i))"
            (atan (tan (make-rectangular 0.0 -3.0)))
            (make-rectangular 0.0 -3.0))
      (test-equal "tan(0.5+0.5i)"
            (tan (make-rectangular 0.5 0.5))
            (make-rectangular 0.4038964553160257 0.5640831412674985))
      (test-equal "atan(tan(0.5+0.5i))"
            (atan (tan (make-rectangular 0.5 0.5)))
            (make-rectangular 0.5 0.5))
      (test-equal "tan(0.5-0.5i)"
            (tan (make-rectangular 0.5 -0.5))
            (make-rectangular 0.4038964553160257 -0.5640831412674985))
      (test-equal "atan(tan(0.5-0.5i))"
            (atan (tan (make-rectangular 0.5 -0.5)))
            (make-rectangular 0.5 -0.5))
      (test-equal "tan(-0.5-0.5i)"
            (tan (make-rectangular -0.5 -0.5))
            (make-rectangular -0.4038964553160257 -0.5640831412674985))
      (test-equal "atan(tan(-0.5-0.5i))"
            (atan (tan (make-rectangular -0.5 -0.5)))
            (make-rectangular -0.5 -0.5))
      (test-equal "tan(-0.5+0.5i)"
            (tan (make-rectangular -0.5 0.5))
            (make-rectangular -0.4038964553160257 0.5640831412674985))
      (test-equal "atan(tan(-0.5+0.5i))"
            (atan (tan (make-rectangular -0.5 0.5)))
            (make-rectangular -0.5 0.5))
      (test-equal "tan(-1.0+1.0i)"
            (tan (make-rectangular -1.0 1.0))
            (make-rectangular -0.27175258531951174 1.0839233273386948))
      (test-equal "atan(tan(-1.0+1.0i))"
            (atan (tan (make-rectangular -1.0 1.0)))
            (make-rectangular -1.0 1.0))
      (test-equal "tan(-1.0-1.0i)"
            (tan (make-rectangular -1.0 -1.0))
            (make-rectangular -0.27175258531951174 -1.0839233273386948))
      (test-equal "atan(tan(-1.0-1.0i))"
            (atan (tan (make-rectangular -1.0 -1.0)))
            (make-rectangular -1.0 -1.0))
      (test-equal "tan(1.0-1.0i)"
            (tan (make-rectangular 1.0 -1.0))
            (make-rectangular 0.27175258531951174 -1.0839233273386948))
      (test-equal "atan(tan(1.0-1.0i))"
            (atan (tan (make-rectangular 1.0 -1.0)))
            (make-rectangular 1.0 -1.0))
      (test-equal "tan(2.0+3.0i)"
            (tan (make-rectangular 2.0 3.0))
            (make-rectangular -0.0037640256415040815 1.0032386273536098))
      (test-equal "atan(tan(2.0+3.0i))"
            (atan (tan (make-rectangular 2.0 3.0)))
            (make-rectangular -1.1415926535898042 3.0))
      (test-equal "tan(-2.0+3.0i)"
            (tan (make-rectangular -2.0 3.0))
            (make-rectangular 0.0037640256415040815 1.0032386273536098))
      (test-equal "atan(tan(-2.0+3.0i))"
            (atan (tan (make-rectangular -2.0 3.0)))
            (make-rectangular 1.1415926535898042 3.0))
      (test-equal "tan(-2.0-3.0i)"
            (tan (make-rectangular -2.0 -3.0))
            (make-rectangular 0.0037640256415040815 -1.0032386273536098))
      (test-equal "atan(tan(-2.0-3.0i))"
            (atan (tan (make-rectangular -2.0 -3.0)))
            (make-rectangular 1.1415926535898042 -3.0))
      (test-equal "tan(2.0-3.0i)"
            (tan (make-rectangular 2.0 -3.0))
            (make-rectangular -0.0037640256415040815 -1.0032386273536098))
      (test-equal "atan(tan(2.0-3.0i))"
            (atan (tan (make-rectangular 2.0 -3.0)))
            (make-rectangular -1.1415926535898042 -3.0))
      ;; Specialization check
      (test-equal "tan(atan(2.0-3.0i))"
            (tan (atan (make-rectangular 2.0 -3.0)))
            (make-rectangular 2.0 -3.0))
      
      )

    ;; This is just a handful to determine that we're able to accept these.
    ;; Maybe determine better values to test with?
    (test-group "bignums"
      (test-equal "acos(<negative bignum>)" (acos (- b1)) -nan.0)
      ;; These are bogus (maybe the negative ones too!), but I don't want to
      ;; "fix" them by copying the output and assume it's alright.
      #;(test-equal "acos(<bignum>)" (acos b1) +nan.0)
      (test-equal "asin(<negative bignum>)" (asin (- b1)) -nan.0)
      #;(test-equal "asin(<bignum>)" (asin b1) +nan.0)
      (test-equal "atan(<negative bignum>)" (atan (- b1)) (- (/ pi 2)))
      (test-equal "atan(<bignum>)" (atan b1) (/ pi 2)))

    ;; This should probably be enough; we're only testing conversion to flonums
    ;; and specialization.  The actual functionality of cos is checked above.
    (test-group "fixnums"
      (test-equal "cos(0)" (cos 0) 1.0)
      (test-equal "acos(0)" (acos 0) (/ pi 2))
      (test-equal "cos(1)" (cos 1) (cos 1.0))
      (test-equal "acos(1)" (acos 1) 0.0)
      (test-equal "cos(-1)" (cos -1) (cos -1.0))
      (test-equal "acos(-1)" (acos -1) pi)
      (test-equal "acos(-2)" (acos -2) (make-rectangular pi -1.31695789692482))
      (test-equal "acos(2)" (acos 2) 0.0+1.31695789692482i)
      (test-equal "asin(1)" (asin 1) (/ pi 2))
      (test-equal "asin(-1)" (asin -1) (/ pi -2))
      (test-equal "asin(2)" (asin 2) (make-rectangular (/ pi 2) -1.31695789692482))
      (test-equal "asin(-2)" (asin -2) (make-rectangular (/ pi -2) 1.31695789692482)))

    (test-group "ratnums"
      (test-equal "acos(<small number>)" (acos (/ -999999999 2)) -nan.0)
      (test-equal "cos(-1/3pi)" (cos (- (/ ratpi 3))) 0.5)
      (test-equal "acos(cos(-1/3pi))" (acos (cos (- (/ ratpi 3)))) (/ pi 3))
      (test-equal "cos(-1/4pi)" (cos (- (/ ratpi 4))) 0.7071067811865476)
      (test-equal "acos(cos(-1/4pi))" (acos (cos (- (/ ratpi 4)))) (/ pi 4))
      (test-equal "cos(-1/2pi)" (cos (- (/ ratpi 2))) 0.0)
      (test-equal "acos(cos(-1/2pi))" (acos (cos (- (/ ratpi 2)))) (/ pi 2))
      (test-equal "cos(-pi)" (cos (- ratpi)) -1.0)
      (test-equal "acos(cos(-pi))" (acos (cos (- ratpi))) pi)
      (test-equal "cos(0)" (cos 0.0) 1.0)
      (test-equal "acos(cos(0))" (acos (cos 0.0)) 0.0)
      (test-equal "cos( 1/4pi)" (cos (/ ratpi 4)) 0.7071067811865476)
      (test-equal "acos(cos( 1/4pi))" (acos (cos (/ ratpi 4))) (/ pi 4))
      (test-equal "cos( 1/3pi)" (cos (/ ratpi 3)) 0.5)
      (test-equal "acos(cos( 1/3pi))" (acos (cos (/ ratpi 3))) (/ pi 3))
      (test-equal "cos( 1/2pi)" (cos (/ ratpi 2)) 0.0)
      (test-equal "acos(cos( 1/2pi))" (acos (cos (/ ratpi 2))) (/ pi 2))
      (test-equal "cos( 2/3pi)" (cos (/ (* 2 ratpi) 3)) -0.5)
      (test-equal "acos(cos( 2/3pi))" (acos (cos (/ (* 2 ratpi) 3))) (/ (* 2 pi) 3))
      (test-equal "cos( 3/4pi)" (cos (* (/ ratpi 4) 3)) -0.7071067811865476)
      (test-equal "acos(cos( 3/4pi))" (acos (cos (* (/ ratpi 4) 3))) (* (/ pi 4) 3))
      (test-equal "cos(    pi)" (cos ratpi) -1.0)
      (test-equal "acos(cos(    pi))" (acos (cos ratpi)) pi)
      (test-equal "cos( 3/2pi)" (cos (+ ratpi (/ ratpi 2))) 0.0)
      (test-equal "acos(cos( 3/2pi))" (acos (cos (+ ratpi (/ ratpi 2)))) (/ pi 2))
      (test-equal "cos( 4/3pi)" (cos (+ ratpi (/ ratpi 3))) -0.5)
      (test-equal "acos(cos( 4/3pi))" (acos (cos (+ ratpi (/ ratpi 3)))) (* 2 (/ pi 3)))
      (test-equal "cos( 5/4pi)" (cos (+ ratpi (/ ratpi 4))) -0.7071067811865476)
      (test-equal "acos(cos( 5/4pi))" (acos (cos (+ ratpi (/ ratpi 4)))) (* 3 (/ pi 4)))
      (test-equal "cos(   2pi)" (cos (* 2 pi)) 1.0)
      (test-equal "acos(cos(   2pi))" (acos (cos (* 2 ratpi))) 0)

      (test-equal "sin(-1/3pi)" (sin (- (/ ratpi 3))) -0.8660254037844386)
      (test-equal "asin(sin(-1/3pi))" (asin (sin (- (/ ratpi 3)))) (- (/ pi 3)))
      (test-equal "sin(-1/4pi)" (sin (- (/ ratpi 4))) -0.7071067811865476)
      (test-equal "asin(sin(-1/4pi))" (asin (sin (- (/ ratpi 4)))) (- (/ pi 4)))
      (test-equal "sin(-1/2pi)" (sin (- (/ ratpi 2))) -1.0)
      (test-equal "asin(sin(-1/2pi))" (asin (sin (- (/ ratpi 2)))) (- (/ pi 2)))
      (test-equal "sin(-pi)" (sin (- ratpi)) 0.0)
      (test-equal "asin(sin(-pi))" (asin (sin (- ratpi))) 0.0)
      (test-equal "sin(0)" (sin 0.0) 0.0)
      (test-equal "asin(sin(0))" (asin (sin 0.0)) 0.0)
      (test-equal "sin( 1/4pi)" (sin (/ ratpi 4)) 0.7071067811865476)
      (test-equal "asin(sin( 1/4pi))" (asin (sin (/ ratpi 4))) (/ pi 4))
      (test-equal "sin( 1/3pi)" (sin (/ ratpi 3)) 0.8660254037844386)
      (test-equal "asin(sin( 1/3pi))" (asin (sin (/ ratpi 3))) (/ pi 3))
      (test-equal "sin( 1/2pi)" (sin (/ ratpi 2)) 1.0)
      (test-equal "asin(sin( 1/2pi))" (asin (sin (/ ratpi 2))) (/ pi 2))
      (test-equal "sin( 2/3pi)" (sin (/ (* 2 ratpi) 3)) 0.8660254037844386)
      (test-equal "asin(sin( 2/3pi))" (asin (sin (/ (* 2 ratpi) 3))) (/ pi 3))
      (test-equal "sin( 3/4pi)" (sin (* (/ ratpi 4) 3)) 0.7071067811865476)
      (test-equal "asin(sin( 3/4pi))" (asin (sin (* (/ ratpi 4) 3))) (/ pi 4))
      (test-equal "sin(    pi)" (sin ratpi) 0.0)
      (test-equal "asin(sin(    pi))" (asin (sin ratpi)) 0.0)
      (test-equal "sin( 3/2pi)" (sin (+ ratpi (/ ratpi 2))) -1.0)
      (test-equal "asin(sin( 3/2pi))" (asin (sin (+ ratpi (/ ratpi 2)))) (- (/ pi 2)))
      (test-equal "sin( 4/3pi)" (sin (+ ratpi (/ ratpi 3))) -0.8660254037844386)
      (test-equal "asin(sin( 4/3pi))" (asin (sin (+ ratpi (/ ratpi 3)))) (- (/ pi 3)))
      (test-equal "sin( 5/4pi)" (sin (+ ratpi (/ ratpi 4))) -0.7071067811865476)
      (test-equal "asin(sin( 5/4pi))" (asin (sin (+ ratpi (/ ratpi 4)))) (- (/ pi 4)))
      (test-equal "sin(   2pi)" (sin (* 2 ratpi)) 0.0)
      (test-equal "asin(sin(   2pi))" (asin (sin (* 2 ratpi))) 0.0)
      
      (test-equal "tan(-1/3pi)" (tan (- (/ ratpi 3))) -1.7320508075688773)
      (test-equal "atan(tan(-1/3pi))" (atan (tan (- (/ ratpi 3)))) (- (/ pi 3)))
      (test-equal "tan(-1/4pi)" (tan (- (/ ratpi 4))) -1.0)
      (test-equal "atan(tan(-1/4pi))" (atan (tan (- (/ ratpi 4)))) (- (/ pi 4)))
      ;; NOTE: tan(-(/ pi 2)) should be -inf(?), but isn't.  Is that a bug?
      (test-equal "tan(-pi)" (tan (- ratpi)) 0.0)
      (test-equal "atan(tan(-pi))" (atan (tan (- ratpi))) 0.0)
      (test-equal "tan(0)" (tan 0.0) 0.0)
      (test-equal "atan(tan(0))" (atan (tan 0.0)) 0.0)
      (test-equal "tan( 1/4pi)" (tan (/ ratpi 4)) 1.0)
      (test-equal "atan(tan( 1/4pi))" (atan (tan (/ ratpi 4))) (/ pi 4))
      (test-equal "tan( 1/3pi)" (tan (/ ratpi 3)) 1.7320508075688773)
      (test-equal "atan(tan( 1/3pi))" (atan (tan (/ ratpi 3))) (/ pi 3))
      (test-equal "tan( 2/3pi)" (tan (/ (* 2 ratpi) 3)) -1.7320508075688773)
      (test-equal "atan(tan( 2/3pi))" (atan (tan (/ (* 2 ratpi) 3))) (- (/ pi 3)))
      (test-equal "tan( 3/4pi)" (tan (* (/ ratpi 4) 3)) -1.0)
      (test-equal "atan(tan( 3/4pi))" (atan (tan (* (/ ratpi 4) 3))) (- (/ pi 4)))
      (test-equal "tan(    pi)" (tan ratpi) 0.0)
      (test-equal "atan(tan(    pi))" (atan (tan ratpi)) 0.0)
      (test-equal "tan( 4/3pi)" (tan (+ ratpi (/ ratpi 3))) 1.7320508075688773)
      (test-equal "atan(tan( 4/3pi))" (atan (tan (+ ratpi (/ ratpi 3)))) (/ pi 3))
      (test-equal "tan( 5/4pi)" (tan (+ ratpi (/ ratpi 4))) 1.0)
      (test-equal "atan(tan( 5/4pi))" (atan (tan (+ ratpi (/ ratpi 4)))) (/ pi 4))
      (test-equal "tan(   2pi)" (tan (* 2 ratpi)) 0.0)
      (test-equal "atan(tan(   2i))" (atan (tan (* 2 ratpi))) 0.0)

      (test-equal "atan2(3, tan(pi))" (atan 3 (tan ratpi)) (/ pi 2))
      (test-equal "atan2(3, -tan(pi))" (atan 3 (- (tan ratpi))) (/ pi 2))
      (test-equal "atan2(-3, tan(pi))" (atan -3 (tan ratpi)) (- (/ pi 2)))
      (test-equal "atan2(-3, -tan(pi))" (atan -3 (- (tan ratpi))) (- (/ pi 2))))))

(test-end)

;(unless (zero? (test-failure-count)) (exit 1))
(test-exit)
