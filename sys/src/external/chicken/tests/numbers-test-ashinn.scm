(include "test.scm")

(import (chicken bitwise))

(current-test-epsilon 0) ;; We want exact comparisons by default

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; run tests

(test-begin "numbers (Alex Shinn's tests)")

(test-group "basic cases, fixnum base"
  (test-equal (expt 0 0) 1)
  (test-equal (expt 2 0) 1)
  (test-equal (expt 2 1) 2)
  (test-equal (expt 2 2) 4)
  (test-equal (expt 3 2) 9)
  (test-equal (expt 3 2.0) 9.0)
  (parameterize ((current-test-epsilon 0.001))
    (test-equal (expt 3 2.1) 10.0451)
    (test-equal (expt 3 0.1) 1.1161)
    (test-equal (expt 3 -1) (/ 1 3))
    (test-equal (expt 3 -2) (/ 1 9))
    (test-equal (expt 3 -2.1) 0.09955)))

(test-group "basic cases, flonum base"
  (test-equal (expt 0.0 0) 1.0)
  (test-equal (expt 3.14 0) 1.0)
  (test-equal (expt 3.14 1) 3.14)
  (test-equal (expt 3.14 2) 9.8596)
  (test-equal (expt 3.14 2.0) 9.8596)
  (parameterize ((current-test-epsilon 0.001))
    (test-equal (expt 3.14 2.1) 11.0548)
    (test-equal (expt 3.14 0.1) 1.1212)
    (test-equal (expt 3.14 -1) 0.31847)
    (test-equal (expt 3.14 -2) 0.10142)
    (test-equal (expt 3.14 -2.1) 0.090458)))

(test-group "overflows into bignums"
  (test-equal (expt 2 30) 1073741824)
  (test-equal (expt 2 31) 2147483648)
  (test-equal (expt 2 32) 4294967296)
  (test-equal (expt 2 62) 4611686018427387904)
  (test-equal (expt 2 63) 9223372036854775808)
  (test-equal (expt 2 64) 18446744073709551616))

(define (one-followed-by-n-zeros n)
  (string->number (string-append "1" (make-string n #\0))))

(test-group "bug reported on the chicken list"
  (test-equal (expt 10 100) (one-followed-by-n-zeros 100)))

(test-group "bignum base"
  (test-equal (expt (one-followed-by-n-zeros 100) 0) 1)
  (parameterize ((current-test-epsilon 0.001))
    (test-equal (expt (one-followed-by-n-zeros 100) 1) (one-followed-by-n-zeros 100))
    (test-equal (expt (one-followed-by-n-zeros 100) 2) (one-followed-by-n-zeros 200))
    (test-equal (expt (one-followed-by-n-zeros 100) 0.1) 10000000000.0)))

(define (real-approx= expected result)
  (cond ((zero? result) (< (abs expected) (current-test-epsilon)))
        ((zero? expected) (< (abs result) (current-test-epsilon)))
        (else (< (min (abs (- 1 (/ expected result)))
                      (abs (- 1 (/ result expected))))
                 (current-test-epsilon)))))

;; test-equal? doesn't work on compnums
(define (test-equal/comp? a b)
  (and (real-approx= (real-part a) (real-part b))
       (real-approx= (imag-part a) (imag-part b))))

(test-group "e^(pi*i) = -1"
  (parameterize ((current-test-epsilon 0.001)
                 (current-test-comparator test-equal/comp?))
    (test-equal (expt (exp 1) (* (acos -1) (sqrt -1))) -1.0)))

(test-group "rational rounding"
  (test-equal (round (/ 9 10)) 1)
  (test-equal (round (/ 6 10)) 1)
  (test-equal (round (/ 5 10)) 0)
  (test-equal (round (/ 1 10)) 0)
  (test-equal (round (/ 0 10)) 0)
  (test-equal (round (/ -1 10)) 0)
  (test-equal (round (/ -5 10)) 0)
  (test-equal (round (/ -6 10)) -1)
  (test-equal (round (/ -9 10)) -1)
  (test-equal (round (/ (expt 10 10000) (+ (expt 10 10000) 1))) 1)
  (test-equal (round (/ (+ 1 (expt 10 10000)) (expt 10 100))) (expt 10 9900)))

(test-group "srfi-33"
  (test-equal (bitwise-and #b0 #b1) 0)
  (test-equal (bitwise-and #b1 #b1) 1)
  (test-equal (bitwise-and #b1 #b10) 0)
  (test-equal (bitwise-and #b11 #b10) #b10)
  (test-equal (bitwise-and #b101 #b111) #b101)
  (test-equal (bitwise-and -1 #b111) #b111)
  (test-equal (bitwise-and -2 #b111) #b110)
  (test-equal (bitwise-and -4290775858 1694076839) 3769478)
  (test-equal (bitwise-and -193073517 1689392892) 1680869008)
  ;; (test-equal (bitwise-ior 1694076839 -4290775858) -2600468497)
  ;; (test-equal (bitwise-ior -193073517 1689392892) -184549633)
  ;; (test-equal (bitwise-xor 1694076839 -4290775858) -2604237975)
  ;; (test-equal (bitwise-xor -193073517 1689392892) -1865418641)

  (test-equal (arithmetic-shift 1 0) 1)
  (test-equal (arithmetic-shift 1 1) 2)
  (test-equal (arithmetic-shift 1 2) 4)
  (test-equal (arithmetic-shift 1 3) 8)
  (test-equal (arithmetic-shift 1 4) 16)
  (test-equal (arithmetic-shift 1 31) (expt 2 31))
  (test-equal (arithmetic-shift 1 32) (expt 2 32))
  (test-equal (arithmetic-shift 1 33) (expt 2 33))
  (test-equal (arithmetic-shift 1 63) (expt 2 63))
  (test-equal (arithmetic-shift 1 64) (expt 2 64))
  (test-equal (arithmetic-shift 1 65) (expt 2 65))
  (test-equal (arithmetic-shift 1 127) (expt 2 127))
  (test-equal (arithmetic-shift 1 128) (expt 2 128))
  (test-equal (arithmetic-shift 1 129) (expt 2 129))
  (test-equal (arithmetic-shift 11829675785914119 8) 3028397001194014464)

  (test-equal (arithmetic-shift -1 0) -1)
  (test-equal (arithmetic-shift -1 1) -2)
  (test-equal (arithmetic-shift -1 2) -4)
  (test-equal (arithmetic-shift -1 3) -8)
  (test-equal (arithmetic-shift -1 4) -16)
  (test-equal (arithmetic-shift -1 31) (- (expt 2 31)))
  (test-equal (arithmetic-shift -1 32) (- (expt 2 32)))
  (test-equal (arithmetic-shift -1 33) (- (expt 2 33)))
  (test-equal (arithmetic-shift -1 63) (- (expt 2 63)))
  (test-equal (arithmetic-shift -1 64) (- (expt 2 64)))
  (test-equal (arithmetic-shift -1 65) (- (expt 2 65)))
  (test-equal (arithmetic-shift -1 127) (- (expt 2 127)))
  (test-equal (arithmetic-shift -1 128) (- (expt 2 128)))
  (test-equal (arithmetic-shift -1 129) (- (expt 2 129)))

  (test-equal (arithmetic-shift 1 -63) 0)
  (test-equal (arithmetic-shift 1 -64) 0)
  (test-equal (arithmetic-shift 1 -65) 0)

  (test-equal (arithmetic-shift #x100000000000000010000000000000000 64)
	      #x1000000000000000100000000000000000000000000000000)

  (test-assert (not (bit->boolean 1 64)))
  (test-assert (bit->boolean #x10000000000000000 64)))

(test-end)

(test-exit)
