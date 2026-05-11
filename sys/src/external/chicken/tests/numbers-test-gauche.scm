;;
;; test numeric system implementation
;;
;; These tests are from Gauche Scheme (v0.9.1), which can be found at
;; http://practical-scheme.net/gauche/index.html
;; Some modifications were made to allow it to be used with the "test"
;; egg for Chicken
;;
;;   Copyright (c) 2000-2010  Shiro Kawai  <shiro@acm.org>
;;
;;  Redistribution and use in source and binary forms, with or without
;;  modification, are permitted provided that the following conditions
;;  are met:
;;
;;   1. Redistributions of source code must retain the above copyright
;;      notice, this list of conditions and the following disclaimer.
;;
;;   2. Redistributions in binary form must reproduce the above copyright
;;      notice, this list of conditions and the following disclaimer in the
;;      documentation and/or other materials provided with the distribution.
;;
;;   3. Neither the name of the authors nor the names of its contributors
;;      may be used to endorse or promote products derived from this
;;      software without specific prior written permission.
;;
;;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;;  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;;  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;;  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;;  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;;  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
;;  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
;;  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
;;  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
;;  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;;  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;

(include "test.scm")

(define (exp2 pow)
  (do ((i 0 (+ i 1))
       (m 1 (+ m m)))
      ((>= i pow) m)))

(define (fermat n)                      ;Fermat's number
  (+ (expt 2 (expt 2 n)) 1))

;; Gauche compat

(import (chicken bitwise) (chicken port) (chicken format) (chicken string) (chicken fixnum))

(define (greatest-fixnum) most-positive-fixnum)
(define (least-fixnum) most-negative-fixnum)
(define (fixnum-width) fixnum-precision)

(define ash arithmetic-shift)
(define logior bitwise-ior)
(define logand bitwise-and)
(define lognot bitwise-not)
(define (logtest a b) (= (bitwise-and a b) b))

(define-syntax let1
  (syntax-rules ()
    ((_ var val forms ...)
     (let ((var val)) forms ...))))

(define (integer->digit i r)
  (and (< i r)
       (if (< i 10)
           (integer->char (+ (char->integer #\0) i))
           (integer->char (+ (char->integer #\a) (- i 10))))))

(define (read-from-string s) (with-input-from-string s read))

(define (truncate->exact x) (inexact->exact (truncate x)))
(define (round->exact x) (inexact->exact (round x)))
(define (floor->exact x) (inexact->exact (floor x)))
(define (ceiling->exact x) (inexact->exact (ceiling x)))

;; This is probably a bit silly
(define (+. . args) (if (null? args) 0.0 (apply + (map exact->inexact args))))
(define (-. . args) (apply - (map exact->inexact args)))
(define (*. . args) (if (null? args) 1.0 (apply * (map exact->inexact args))))
(define (/. . args) (apply / (map exact->inexact args)))

(test-begin "Gauche numbers test")

;;==================================================================
;; Reader/writer
;;

;;------------------------------------------------------------------
(test-begin "integer addition & reader")

(define (i-tester x)
  (list x (+ x -1 x) (+ x x) (- x) (- (+ x -1 x)) (- 0 x x) (- 0 x x 1)))

(test-equal "around 2^28"
      (i-tester (exp2 28))
      '(268435456 536870911 536870912
         -268435456 -536870911 -536870912 -536870913))

(test-equal "around 2^31"
      (i-tester (exp2 31))
       '(2147483648 4294967295 4294967296
         -2147483648 -4294967295 -4294967296 -4294967297))

(test-equal "around 2^60"
       (i-tester (exp2 60))
       '(1152921504606846976 2305843009213693951 2305843009213693952
         -1152921504606846976 -2305843009213693951 -2305843009213693952
         -2305843009213693953))

(test-equal "around 2^63"
       (i-tester (exp2 63))
       '(9223372036854775808 18446744073709551615 18446744073709551616
         -9223372036854775808 -18446744073709551615 -18446744073709551616
         -18446744073709551617))

(test-equal "around 2^127"
       (i-tester (exp2 127))
       '(170141183460469231731687303715884105728
         340282366920938463463374607431768211455
         340282366920938463463374607431768211456
         -170141183460469231731687303715884105728
         -340282366920938463463374607431768211455
         -340282366920938463463374607431768211456
         -340282366920938463463374607431768211457))

;; test for reader's overflow detection code
(test-equal "peculiarity around 2^32"
      (* 477226729 10) 4772267290)

(test-equal "radix" (list #b1010101001010101
             #o1234567
             #o12345677654321
             #d123456789
             #d123456789987654321
             #x123456
             #xdeadbeef
             #xDeadBeef)
      '(43605 342391 718048024785
                 123456789 123456789987654321
                 1193046 3735928559 3735928559))

(test-equal "exactness" (exact? #e10) #t)
(test-equal "exactness" (exact? #e10.0) #t)
(test-equal "exactness" (exact? #e10e10) #t)
(test-equal "exactness" (exact? #e12.34) #t)
(test-equal "inexactness" (exact? #i10) #f)
(test-equal "inexactness" (exact? #i10.0) #f)
(test-equal "inexactness" (exact? #i12.34) #f)

(test-equal "exactness & radix" (list (exact? #e#xdeadbeef)
             #e#xdeadbeef
             (exact? #x#edeadbeef)
             #x#edeadbeef)
      '(#t 3735928559 #t 3735928559))
(test-equal "inexactness & radix" (list (exact? #i#xdeadbeef)
             #i#xdeadbeef
             (exact? #x#ideadbeef)
             #x#ideadbeef)
      '(#f 3735928559.0 #f 3735928559.0))

(test-equal "invalid exactness/radix spec" (or (string->number "#e")
           (string->number "#i")
           (string->number "#e#i3")
           (string->number "#i#e5")
           (string->number "#x#o13")
           (string->number "#e#b#i00101"))
       #f)

(define (radix-tester radix)
  (list
   (let loop ((digits 0)
              (input "1")
              (value 1))
     (cond ((> digits 64) #t)
           ((eqv? (string->number input radix) value)
            (loop (+ digits 1) (string-append input "0") (* value radix)))
           (else #f)))
   (let loop ((digits 0)
              (input (string (integer->digit (- radix 1) radix)))
              (value (- radix 1)))
     (cond ((> digits 64) #t)
           ((eqv? (string->number input radix) value)
            (loop (+ digits 1)
                  (string-append input (string (integer->digit (- radix 1) radix)))
                  (+ (* value radix) (- radix 1))))
           (else #f)))))

(test-equal "base-2 reader" (radix-tester 2) '(#t #t))
(test-equal "base-3 reader" (radix-tester 3) '(#t #t))
(test-equal "base-4 reader" (radix-tester 4) '(#t #t))
(test-equal "base-5 reader" (radix-tester 5) '(#t #t))
(test-equal "base-6 reader" (radix-tester 6) '(#t #t))
(test-equal "base-7 reader" (radix-tester 7) '(#t #t))
(test-equal "base-8 reader" (radix-tester 8) '(#t #t))
(test-equal "base-9 reader" (radix-tester 9) '(#t #t))
(test-equal "base-10 reader" (radix-tester 10) '(#t #t))
(test-equal "base-11 reader" (radix-tester 11) '(#t #t))
(test-equal "base-12 reader" (radix-tester 12) '(#t #t))
(test-equal "base-13 reader" (radix-tester 13) '(#t #t))
(test-equal "base-14 reader" (radix-tester 14) '(#t #t))
(test-equal "base-15 reader" (radix-tester 15) '(#t #t))
(test-equal "base-16 reader" (radix-tester 16) '(#t #t))
(test-equal "base-17 reader" (radix-tester 17) '(#t #t))
(test-equal "base-18 reader" (radix-tester 18) '(#t #t))
(test-equal "base-19 reader" (radix-tester 19) '(#t #t))
(test-equal "base-20 reader" (radix-tester 20) '(#t #t))
(test-equal "base-21 reader" (radix-tester 21) '(#t #t))
(test-equal "base-22 reader" (radix-tester 22) '(#t #t))
(test-equal "base-23 reader" (radix-tester 23) '(#t #t))
(test-equal "base-24 reader" (radix-tester 24) '(#t #t))
(test-equal "base-25 reader" (radix-tester 25) '(#t #t))
(test-equal "base-26 reader" (radix-tester 26) '(#t #t))
(test-equal "base-27 reader" (radix-tester 27) '(#t #t))
(test-equal "base-28 reader" (radix-tester 28) '(#t #t))
(test-equal "base-29 reader" (radix-tester 29) '(#t #t))
(test-equal "base-30 reader" (radix-tester 30) '(#t #t))
(test-equal "base-31 reader" (radix-tester 31) '(#t #t))
(test-equal "base-32 reader" (radix-tester 32) '(#t #t))
(test-equal "base-33 reader" (radix-tester 33) '(#t #t))
(test-equal "base-34 reader" (radix-tester 34) '(#t #t))
(test-equal "base-35 reader" (radix-tester 35) '(#t #t))
(test-equal "base-36 reader" (radix-tester 36) '(#t #t))

(test-end)

;;------------------------------------------------------------------
(test-begin "rational reader")

(define (rational-test v)
  (if (number? v) (list v (exact? v)) v))

(test-equal "rational reader" (rational-test '1234/1) '(1234 #t))
(test-equal "rational reader" (rational-test '-1234/1) '(-1234 #t))
(test-equal "rational reader" (rational-test '+1234/1) '(1234 #t))
;; The following is invalid R5RS syntax, so it's commented out (it fails, too)
#;(test-equal "rational reader" (rational-test '1234/-1) '|1234/-1|)
(test-equal "rational reader" (rational-test '2468/2) '(1234 #t))
(test-equal "rational reader" (rational-test '1/2) '(1/2 #t))
(test-equal "rational reader" (rational-test '-1/2) '(-1/2 #t))
(test-equal "rational reader" (rational-test '+1/2) '(1/2 #t))
(test-equal "rational reader" (rational-test '751/1502) '(1/2 #t))

(test-equal "rational reader" (rational-test (string->number "3/03"))
       '(1 #t))
(test-equal "rational reader" (rational-test (string->number "3/0")) #;'(+inf.0 #f) ; <- I think that's wrong in Gauche
       #f)
(test-equal "rational reader" (rational-test (string->number "-3/0")) #;'(-inf.0 #f) ; same as above
       #f)
(test-equal "rational reader" (rational-test (string->number "3/3/4"))
       #f)
(test-equal "rational reader" (rational-test (string->number "1/2."))
       #f)
(test-equal "rational reader" (rational-test (string->number "1.3/2"))
       #f)

(test-error "rational reader" (rational-test (read-from-string "#e3/0")))
(test-error "rational reader" (rational-test (read-from-string "#e-3/0")))

(test-equal "rational reader w/#e" (rational-test '#e1234/1)
       '(1234 #t))
(test-equal "rational reader w/#e" (rational-test '#e-1234/1)
       '(-1234 #t))
(test-equal "rational reader w/#e" (rational-test '#e32/7)
       '(32/7 #t))
(test-equal "rational reader w/#e" (rational-test '#e-32/7)
       '(-32/7 #t))
(test-equal "rational reader w/#i" (rational-test '#i1234/1)
       '(1234.0 #f))
(test-equal "rational reader w/#i" (rational-test '#i-1234/1)
       '(-1234.0 #f))
(test-equal "rational reader w/#i" (rational-test '#i-4/32)
       '(-0.125 #f))

(test-equal "rational reader w/radix" (rational-test '#e#xff/11)
       '(15 #t))
(test-equal "rational reader w/radix" (rational-test '#o770/11)
       '(56 #t))
(test-equal "rational reader w/radix" (rational-test '#x#iff/11)
       '(15.0 #f))

(test-equal "rational reader edge case" (symbol? (read-from-string "/1")) #t)
(test-equal "rational reader edge case" (symbol? (read-from-string "-/1")) #t)
(test-equal "rational reader edge case" (symbol? (read-from-string "+/1")) #t)

(test-end)

;;------------------------------------------------------------------
(test-begin "flonum reader")

(define (flonum-test v)
  (if (number? v) (list v (inexact? v)) v))

(test-equal "flonum reader" (flonum-test 3.14)  '(3.14 #t))
(test-equal "flonum reader" (flonum-test 0.14)  '(0.14 #t))
(test-equal "flonum reader" (flonum-test .14)  '(0.14 #t))
(test-equal "flonum reader" (flonum-test 3.)  '(3.0  #t))
(test-equal "flonum reader" (flonum-test -3.14)  '(-3.14 #t))
(test-equal "flonum reader" (flonum-test -0.14)  '(-0.14 #t))
(test-equal "flonum reader" (flonum-test -.14)  '(-0.14 #t))
(test-equal "flonum reader" (flonum-test -3.)  '(-3.0  #t))
(test-equal "flonum reader" (flonum-test +3.14)  '(3.14 #t))
(test-equal "flonum reader" (flonum-test +0.14)  '(0.14 #t))
(test-equal "flonum reader" (flonum-test +.14)  '(0.14 #t))
(test-equal "flonum reader" (flonum-test +3.)  '(3.0  #t))
(test-equal "flonum reader" (flonum-test .0)  '(0.0  #t))
(test-equal "flonum reader" (flonum-test 0.)  '(0.0  #t))
(test-equal "flonum reader" (string->number ".") #f)
(test-equal "flonum reader" (string->number "-.") #f)
(test-equal "flonum reader" (string->number "+.") #f)

(test-equal "flonum reader (exp)" (flonum-test 3.14e2) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314e3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test 314e0) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test 314e-0) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test 3140000e-4) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test -3.14e2) '(-314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test -.314e3) '(-314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test -314e0) '(-314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test -314.e-0) '(-314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test -3140000e-4) '(-314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test +3.14e2) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test +.314e3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test +314.e0) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test +314e-0) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test +3140000.000e-4) '(314.0 #t))

(test-equal "flonum reader (exp)" (flonum-test .314E3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314s3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314S3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314l3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314L3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314f3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314F3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314d3) '(314.0 #t))
(test-equal "flonum reader (exp)" (flonum-test .314D3) '(314.0 #t))

;; Broken for unknown reasons on Mingw
#;(test-equal "flonum reader (minimum denormalized number 5.0e-324)" (let1 x (expt 2.0 -1074)
         (= x (string->number (number->string x))))
       #t)
#;(test-equal "flonum reader (minimum denormalized number -5.0e-324)" (let1 x (- (expt 2.0 -1074))
         (= x (string->number (number->string x))))
       #t)
       

(test-equal "padding" (flonum-test '1#) '(10.0 #t))
(test-equal "padding" (flonum-test '1#.) '(10.0 #t))
(test-equal "padding" (flonum-test '1#.#) '(10.0 #t))
(test-equal "padding" (flonum-test '10#.#) '(100.0 #t))
(test-equal "padding" (flonum-test '1##.#) '(100.0 #t))
(test-equal "padding" (flonum-test '100.0#) '(100.0 #t))
(test-equal "padding" (flonum-test '1.#) '(1.0 #t))

(test-equal "padding" (flonum-test '1#1) '|1#1|)
(test-equal "padding" (flonum-test '1##1) '|1##1|)
(test-equal "padding" (flonum-test '1#.1) '|1#.1|)
(test-equal "padding" (flonum-test '1.#1) '|1.#1|)

(test-equal "padding" (flonum-test '.#) '|.#|)
(test-equal "padding" (flonum-test '0.#) '(0.0 #t))
(test-equal "padding" (flonum-test '.0#) '(0.0 #t))
(test-equal "padding" (flonum-test '0#) '(0.0 #t))
(test-equal "padding" (flonum-test '0#.#) '(0.0 #t))
(test-equal "padding" (flonum-test '0#.0) '|0#.0|)

(test-equal "padding" (flonum-test '1#e2) '(1000.0 #t))
(test-equal "padding" (flonum-test '1##e1) '(1000.0 #t))
(test-equal "padding" (flonum-test '1#.##e2) '(1000.0 #t))
(test-equal "padding" (flonum-test '0.#e2) '(0.0 #t))
(test-equal "padding" (flonum-test '.0#e2) '(0.0 #t))
(test-equal "padding" (flonum-test '.##e2) '|.##e2|)

(test-equal "padding (exactness)" (flonum-test '#e1##) '(100 #f))
(test-equal "padding (exactness)" (flonum-test '#e12#) '(120 #f))
(test-equal "padding (exactness)" (flonum-test '#e12#.#) '(120 #f))
(test-equal "padding (exactness)" (flonum-test '#i1##) '(100.0 #t))
(test-equal "padding (exactness)" (flonum-test '#i12#) '(120.0 #t))
(test-equal "padding (exactness)" (flonum-test '#i12#.#) '(120.0 #t))

(test-equal "exponent out-of-range 1" (flonum-test '1e309) '(+inf.0 #t))
(test-equal "exponent out-of-range 2" (flonum-test '1e10000) '(+inf.0 #t))
;; TODO: Figure out what goes wrong here
;(test-equal "exponent out-of-range 3" (flonum-test '1e1000000000000000000000000000000000000000000000000000000000000000) '(+inf.0 #t))
(test-equal "exponent out-of-range 4" (flonum-test '-1e309) '(-inf.0 #t))
(test-equal "exponent out-of-range 5" (flonum-test '-1e10000) '(-inf.0 #t))
;(test-equal "exponent out-of-range 6" (flonum-test '-1e1000000000000000000000000000000000000000000000000000000000000000) '(-inf.0 #t))
(test-equal "exponent out-of-range 7" (flonum-test '1e-324) '(0.0 #t))
(test-equal "exponent out-of-range 8" (flonum-test '1e-1000) '(0.0 #t))
;(test-equal "exponent out-of-range 9" (flonum-test '1e-1000000000000000000000000000000000000000000000000000000000000000000) '(0.0 #t))

(test-equal "no integral part" (read-from-string ".5") 0.5)
(test-equal "no integral part" (read-from-string "-.5") -0.5)
(test-equal "no integral part" (read-from-string "+.5") 0.5)
(test-end)

;;------------------------------------------------------------------
(test-begin "exact fractional number")

(test-equal "exact fractonal number" (string->number "#e1.2345e4")
       12345)
(test-equal "exact fractonal number" (string->number "#e1.2345e14")
       123450000000000)
(test-equal "exact fractonal number" (string->number "#e1.2345e2")
       12345/100)
(test-equal "exact fractonal number" (string->number "#e1.2345e-2")
       12345/1000000)
(test-equal "exact fractonal number" (string->number "#e-1.2345e4")
       -12345)
(test-equal "exact fractonal number" (string->number "#e-1.2345e14")
       -123450000000000)
(test-equal "exact fractonal number" (string->number "#e-1.2345e2")
       -12345/100)
(test-equal "exact fractonal number" (string->number "#e-1.2345e-2")
       -12345/1000000)

(test-equal "exact fractonal number" (string->number "#e0.0001e300")
       (expt 10 296))
(test-equal "exact fractonal number" (string->number "#e-0.0001e300")
       (- (expt 10 296)))

(test-equal "exact fractonal number" (read-from-string "#e1e330")
      (expt 10 330))
(test-equal "exact fractonal number" (read-from-string "#e1e-330")
      (expt 10 -330))

(test-end)

;;------------------------------------------------------------------
(test-begin "complex reader")

(define (decompose-complex z)
  (cond ((real? z) z)
        ((complex? z)
         (list (real-part z) (imag-part z)))
        (else z)))

;; Fixed for exactness (Gauche's complex numbers are always inexact)
(test-equal "complex reader" (decompose-complex '1+i) '(1 1))
(test-equal "complex reader" (decompose-complex '1+1i) '(1 1))
(test-equal "complex reader" (decompose-complex '1-i) '(1 -1))
(test-equal "complex reader" (decompose-complex '1-1i) '(1 -1))
(test-equal "complex reader" (decompose-complex '1.0+1i) '(1.0 1.0))
(test-equal "complex reader" (decompose-complex '1.0+1.0i) '(1.0 1.0))
(test-equal "complex reader" (decompose-complex '1e-5+1i) '(1e-5 1.0))
(test-equal "complex reader" (decompose-complex '1e+5+1i) '(1e+5 1.0))
(test-equal "complex reader" (decompose-complex '1+1e-5i) '(1.0 1e-5))
(test-equal "complex reader" (decompose-complex '1+1e+5i) '(1.0 1e+5))
(test-equal "complex reader" (decompose-complex '0.1+0.1e+5i) '(0.1 1e+4))
(test-equal "complex reader" (decompose-complex '+i) '(0 1))
(test-equal "complex reader" (decompose-complex '-i) '(0 -1))
(test-equal "complex reader" (decompose-complex '+1i) '(0 1))
(test-equal "complex reader" (decompose-complex '-1i) '(0 -1))
(test-equal "complex reader" (decompose-complex '+1.i) '(0.0 1.0))
(test-equal "complex reader" (decompose-complex '-1.i) '(0.0 -1.0))
(test-equal "complex reader" (decompose-complex '+1.0i) '(0.0 1.0))
(test-equal "complex reader" (decompose-complex '-1.0i) '(0.0 -1.0))
(test-equal "complex reader" (decompose-complex '1+0.0i) 1.0)
(test-equal "complex reader" (decompose-complex '1+.0i) 1.0)
(test-equal "complex reader" (decompose-complex '1+0.i) 1.0)
(test-equal "complex reader" (decompose-complex '1+0.0e-43i) 1.0)
(test-equal "complex reader" (decompose-complex '1e2+0.0e-43i) 100.0)

(test-equal "complex reader" (decompose-complex 'i) 'i)
(test-equal "complex reader" (decompose-complex (string->number ".i")) #f)
(test-equal "complex reader" (decompose-complex (string->number "+.i")) #f)
(test-equal "complex reader" (decompose-complex (string->number "-.i")) #f)
(test-equal "complex reader" (decompose-complex '33i) '33i)
(test-equal "complex reader" (decompose-complex 'i+1) 'i+1)
(test-equal "complex reader" (decompose-complex '++i) '|++i|)
(test-equal "complex reader" (decompose-complex '--i) '|--i|)

(test-equal "complex reader" (decompose-complex 1/2+1/2i) '(1/2 1/2))
(test-equal "complex reader" (decompose-complex 0+1/2i) '(0 1/2))
(test-equal "complex reader" (decompose-complex -1/2i) '(0 -1/2))
(test-equal "complex reader" (decompose-complex 1/2-0/2i) 1/2)
;; The following is also invalid R5RS syntax, so it's commented out
#;(test-equal "complex reader" (decompose-complex (string->number "1/2-1/0i")) '(0.5 -inf.0))

(test-equal "complex reader (polar)" (make-polar 1.0 1.0) 1.0@1.0)
(test-equal "complex reader (polar)" (make-polar 1.0 -1.0) 1.0@-1.0)
(test-equal "complex reader (polar)" (make-polar 1.0 1.0) 1.0@+1.0)
(test-equal "complex reader (polar)" (make-polar -7.0 -3.0) -7@-3.0)
(test-equal "complex reader (polar)" (make-polar 3.5 -3.0) 7/2@-3.0)
(test-equal "complex reader (polar)" (string->number "7/2@-3.14i") #f)

(test-end)

;;------------------------------------------------------------------
(test-begin "integer writer syntax")

(define (i-tester2 x)
  (map number->string (i-tester x)))

(test-equal "around 2^28"
      (i-tester2 (exp2 28))
      '("268435456" "536870911" "536870912"
        "-268435456" "-536870911" "-536870912" "-536870913"))
      
(test-equal "around 2^31"
      (i-tester2 (exp2 31))
      '("2147483648" "4294967295" "4294967296"
        "-2147483648" "-4294967295" "-4294967296" "-4294967297"))

(test-equal "around 2^60"
      (i-tester2 (exp2 60))
      '("1152921504606846976" "2305843009213693951" "2305843009213693952"
        "-1152921504606846976" "-2305843009213693951" "-2305843009213693952"
        "-2305843009213693953"))

(test-equal "around 2^63"
      (i-tester2 (exp2 63))
      '("9223372036854775808" "18446744073709551615" "18446744073709551616"
        "-9223372036854775808" "-18446744073709551615" "-18446744073709551616"
        "-18446744073709551617"))

(test-equal "around 2^127"
      (i-tester2 (exp2 127))
      '("170141183460469231731687303715884105728"
        "340282366920938463463374607431768211455"
        "340282366920938463463374607431768211456"
        "-170141183460469231731687303715884105728"
        "-340282366920938463463374607431768211455"
        "-340282366920938463463374607431768211456"
        "-340282366920938463463374607431768211457"))

(test-end)

;;==================================================================
;; Conversions
;;

;; We first test expt, for we need to use it to test exact<->inexact
;; conversion stuff.
(test-begin "expt")

(test-equal "exact expt" (expt 5 0) 1)
(test-equal "exact expt" (expt 5 10) 9765625)
(test-equal "exact expt" (expt 5 13) 1220703125)
(test-equal "exact expt" (expt 5 123) 94039548065783000637498922977779654225493244541767001720700136502273380756378173828125)
(test-equal "exact expt" (expt 5 -123) 1/94039548065783000637498922977779654225493244541767001720700136502273380756378173828125)
(test-equal "exact expt" (expt -5 0) 1)
(test-equal "exact expt" (expt -5 10) 9765625)
(test-equal "exact expt" (expt -5 13) -1220703125)
(test-equal "exact expt" (expt -5 123) -94039548065783000637498922977779654225493244541767001720700136502273380756378173828125)
(test-equal "exact expt" (expt -5 -123) -1/94039548065783000637498922977779654225493244541767001720700136502273380756378173828125)
(test-equal "exact expt" (expt 1 720000) 1)
(test-equal "exact expt" (expt -1 720000) 1)
(test-equal "exact expt" (expt -1 720001) -1)

(test-equal "exact expt (ratinoal)" (expt 2/3 33)
       8589934592/5559060566555523)
(test-equal "exact expt (rational)" (expt -2/3 33)
       -8589934592/5559060566555523)
(test-equal "exact expt (ratinoal)" (expt 2/3 -33)
       5559060566555523/8589934592)

(test-end)

(parameterize ((current-test-epsilon 10e7))
  (test-equal "expt (coercion to inexact)" (expt 2 1/2)
        1.4142135623730951)) ;; NB: pa$ will be tested later

(test-begin "exact<->inexact")

(for-each
 (lambda (e&i)
   (let ((e (car e&i))
         (i (cdr e&i)))
     (test-equal (format "exact->inexact ~s" i) (exact->inexact e) i)
     (test-equal (format "exact->inexact ~s" (- i)) (exact->inexact (- e)) (- i))
     (test-equal (format "inexact->exact ~s" e) (inexact->exact i) e)
     (test-equal (format "inexact->exact ~s" (- e)) (inexact->exact (- i)) (- e))
     ))
 `((0  . 0.0)
   (1  . 1.0)
   (-1 . -1.0)
   (,(expt 2 52) . ,(expt 2.0 52))
   (,(expt 2 53) . ,(expt 2.0 53))
   (,(expt 2 54) . ,(expt 2.0 54))
   ))

;; Rounding bignum to flonum, edge cases.
;; Test patterns:
;;
;;   <------53bits------->
;;a) 100000000...000000000100000....0000       round down (r0)
;;b) 100000000...000000000100000....0001       round up (r1)
;;c) 100000000...000000001100000....0000       round up (r2)
;;d) 100000000...000000001011111....1111       round down (r1)
;;e) 111111111...111111111100000....0000       round up, carry over (* r0 2)
;;f) 101111111...111111111100000....0000       round up, no carry over (r3)
;;            <--32bits-->
;;g) 100..0000111.....1111100000....0000       round up; boundary on ILP32 (r4)

(let loop ((n 0)
           (a (+ (expt 2 53) 1))
           (c (+ (expt 2 53) 3))
           (e (- (expt 2 54) 1))
           (f (+ (expt 2 53) (expt 2 52) -1))
           (g (+ (expt 2 53) (expt 2 33) -1))
           (r0 (expt 2.0 53))
           (r1 (+ (expt 2.0 53) 2.0))
           (r2 (+ (expt 2.0 53) 4.0))
           (r3 (+ (expt 2.0 53) (expt 2.0 52)))
           (r4 (+ (expt 2.0 53) (expt 2.0 33))))
  (when (< n 32)
    (test-equal (format "exact->inexact, pattern a: round down (~a)" n)
           (exact->inexact a) r0)
    (test-equal (format "exact->inexact, pattern b: round up   (~a)" n)
           (exact->inexact (+ a 1)) r1)
    (test-equal (format "exact->inexact, pattern c: round up   (~a)" n)
           (exact->inexact c) r2)
    (test-equal (format "exact->inexact, pattern d: round down (~a)" n)
           (exact->inexact (- c 1)) r1)
    (test-equal (format "exact->inexact, pattern e: round up   (~a)" n)
           (exact->inexact e) (* r0 2.0))
    (test-equal (format "exact->inexact, pattern f: round up   (~a)" n)
           (exact->inexact f) r3)
    (test-equal (format "exact->inexact, pattern g: round up   (~a)" n)
           (exact->inexact g) r4)
    (loop (+ n 1) (ash a 1) (ash c 1) (ash e 1) (ash f 1) (ash g 1)
          (* r0 2.0) (* r1 2.0) (* r2 2.0) (* r3 2.0) (* r4 2.0))))


(parameterize ((current-test-epsilon 10e12))
  (test-equal "expt (ratnum with large denom and numer) with inexact conversion 1"
        (exact->inexact (expt 8/9 342))
        (expt 8/9 342.0))

  (test-equal "expt (ratnum with large denom and numer) with inexact conversion 2"
        (exact->inexact (expt -8/9 343))
        (expt -8/9 343.0)))

;; The following few tests covers RATNUM paths in Scm_GetDouble
(test-equal "expt (ratnum with large denom and numer) with inexact conversion 3"
       (exact->inexact (/ (expt 10 20) (expt 10 328))) 1.0e-308)
;; In the original Gauche test this checked for a return value of 0.0, but
;; that's quite Gauche-specific.  We return 1.0e-309.
;; It's probably wrong to test this kind of behaviour in the first place...
(test-equal "expt (ratnum with large denom and numer) with inexact conversion 4"
       (exact->inexact (/ (expt 10 20) (expt 10 329))) 1.0e-309)
(test-equal "expt (ratnum with large denom and numer) with inexact conversion 5"
       (exact->inexact (/ (expt 10 328) (expt 10 20))) 1.0e308)
(test-equal "expt (ratnum with large denom and numer) with inexact conversion 6"
       (exact->inexact (/ (expt 10 329) (expt 10 20))) +inf.0)
(test-equal "expt (ratnum with large denom and numer) with inexact conversion 7"
       (exact->inexact (/ (expt -10 329) (expt 10 20))) -inf.0)

(test-end)

;;==================================================================
;; Predicates
;;

(test-begin "predicates")

(test-equal "integer?" (integer? 0) #t)
(test-equal "integer?" (integer? 85736847562938475634534245) #t)
(test-equal "integer?" (integer? 85736.534245) #f)
(test-equal "integer?" (integer? 3.14) #f)
(test-equal "integer?" (integer? 3+4i) #f)
(test-equal "integer?" (integer? 3+0i) #t)
(test-equal "integer?" (integer? #f) #f)

(test-equal "rational?" (rational? 0) #t)
(test-equal "rational?" (rational? 85736847562938475634534245) #t)
(test-equal "rational?" (rational? 1/2) #t)
(test-equal "rational?" (rational? 85736.534245) #t)
(test-equal "rational?" (rational? 3.14) #t)
(test-equal "rational?" (rational? 3+4i) #f)
(test-equal "rational?" (rational? 3+0i) #t)
(test-equal "rational?" (rational? #f) #f)
(test-equal "rational?" (rational? +inf.0) #f)
(test-equal "rational?" (rational? -inf.0) #f)
(test-equal "rational?" (rational? +nan.0) #f)

(test-equal "real?" (real? 0) #t)
(test-equal "real?" (real? 85736847562938475634534245) #t)
(test-equal "real?" (real? 857368.4756293847) #t)
(test-equal "real?" (real? 3+0i) #t)
(test-equal "real?" (real? 3+4i) #f)
(test-equal "real?" (real? +4.3i) #f)
(test-equal "real?" (real? '()) #f)
(test-equal "real?" (real? +inf.0) #t)
(test-equal "real?" (real? -inf.0) #t)
(test-equal "real?" (real? +nan.0) #t)

(test-equal "complex?" (complex? 0) #t)
(test-equal "complex?" (complex? 85736847562938475634534245) #t)
(test-equal "complex?" (complex? 857368.4756293847) #t)
(test-equal "complex?" (complex? 3+0i) #t)
(test-equal "complex?" (complex? 3+4i) #t)
(test-equal "complex?" (complex? +4.3i) #t)
(test-equal "complex?" (complex? '()) #f)

(test-equal "number?" (number? 0) #t)
(test-equal "number?" (number? 85736847562938475634534245) #t)
(test-equal "number?" (number? 857368.4756293847) #t)
(test-equal "number?" (number? 3+0i) #t)
(test-equal "number?" (number? 3+4i) #t)
(test-equal "number?" (number? +4.3i) #t)
(test-equal "number?" (number? '()) #f)

(test-equal "exact?" (exact? 1) #t)
(test-equal "exact?" (exact? 4304953480349304983049304953804) #t)
(test-equal "exact?" (exact? 430495348034930/4983049304953804) #t)
(test-equal "exact?" (exact? 1.0) #f)
(test-equal "exact?" (exact? 4304953480349304983.049304953804) #f)
(test-equal "exact?" (exact? 1.0+0i) #f)
(test-equal "exact?" (exact? 1.0+5i) #f)
(test-equal "inexact?" (inexact? 1) #f)
(test-equal "inexact?" (inexact? 4304953480349304983049304953804) #f)
(test-equal "inexact?" (inexact? 430495348034930/4983049304953804) #f)
(test-equal "inexact?" (inexact? 1.0) #t)
(test-equal "inexact?" (inexact? 4304953480349304983.049304953804) #t)
(test-equal "inexact?" (inexact? 1.0+0i) #t)
(test-equal "inexact?" (inexact? 1.0+5i) #t)

(test-equal "odd?" (odd? 1) #t)
(test-equal "odd?" (odd? 2) #f)
(test-equal "even?" (even? 1) #f)
(test-equal "even?" (even? 2) #t)
(test-equal "odd?" (odd? 1.0) #t)
(test-equal "odd?" (odd? 2.0) #f)
(test-equal "even?" (even? 1.0) #f)
(test-equal "even?" (even? 2.0) #t)
(test-equal "odd?" (odd? 10000000000000000000000000000000000001) #t)
(test-equal "odd?" (odd? 10000000000000000000000000000000000002) #f)
(test-equal "even?" (even? 10000000000000000000000000000000000001) #f)
(test-equal "even?" (even? 10000000000000000000000000000000000002) #t)

(test-equal "zero?" (zero? 0) #t)
(test-equal "zero?" (zero? 0.0) #t)
(test-equal "zero?" (zero? (- 10 10.0)) #t)
(test-equal "zero?" (zero? 0+0i) #t)
(test-equal "zero?" (zero? 1.0) #f)
(test-equal "zero?" (zero? +5i) #f)
(test-equal "positive?" (positive? 1) #t)
(test-equal "positive?" (positive? -1) #f)
(test-equal "positive?" (positive? 1/7) #t)
(test-equal "positive?" (positive? -1/7) #f)
(test-equal "positive?" (positive? 3.1416) #t)
(test-equal "positive?" (positive? -3.1416) #f)
(test-equal "positive?" (positive? 134539485343498539458394) #t)
(test-equal "positive?" (positive? -134539485343498539458394) #f)
(test-equal "negative?" (negative? 1) #f)
(test-equal "negative?" (negative? -1) #t)
(test-equal "negative?" (negative? 1/7) #f)
(test-equal "negative?" (negative? -1/7) #t)
(test-equal "negative?" (negative? 3.1416) #f)
(test-equal "negative?" (negative? -3.1416) #t)
(test-equal "negative?" (negative? 134539485343498539458394) #f)
(test-equal "negative?" (negative? -134539485343498539458394) #t)

(let-syntax ((tester (syntax-rules ()
                       ((_ name proc result)
                        (begin (test-error name (proc #t))
                               (test-equal name (list (proc 1)
                                                       (proc +inf.0)
                                                       (proc -inf.0)
                                                       (proc +nan.0)) result))))))
  (tester "finite?"   finite?   `(#t #f #f #f))
  (tester "infinite?" infinite? `(#f #t #t #f))
  (tester "nan?"      nan?      `(#f #f #f #t))
  )


(test-equal "eqv?" (eqv? 20 20) #t)
(test-equal "eqv?" (eqv? 20.0 20.00000) #t)
(test-equal "eqv?" (eqv? 4/5 0.8) #f)
(test-equal "eqv?" (eqv? (exact->inexact 4/5) 0.8) #t)
(test-equal "eqv?" (eqv? 4/5 (inexact->exact 0.8)) #f)
(test-equal "eqv?" (eqv? 20 (inexact->exact 20.0)) #t)
(test-equal "eqv?" (eqv? 20 20.0) #f)

;; numeric comparison involving nan.  we should test both 
;; inlined case and applied case
(define-syntax test-nan-cmp
  (ir-macro-transformer
   (lambda (e r c)
     (let ((op (cadr e)))
       `(begin
          (test-equal (format "NaN ~a (inlined)" ',op) (list (,op +nan.0 +nan.0) (,op +nan.0 0) (,op 0 +nan.0))
                '(#f #f #f))
          (test-equal (format "NaN ~a (applied)" ',op) (list (apply ,op '(+nan.0 +nan.0))
                      (apply ,op '(+nan.0 0))
                      (apply ,op '(0 +nan.0)))
                '(#f #f #f)))))))
(test-nan-cmp =)
(test-nan-cmp <)
(test-nan-cmp <=)
(test-nan-cmp >)
(test-nan-cmp >=)

;; the following tests combine instructions for comparison.
(let ((zz #f))
  (set! zz 3.14)  ;; prevent the compiler from optimizing constants

  (test-equal "NUMEQF" (list (= 3.14 zz) (= zz 3.14) (= 3.15 zz) (= zz 3.15))
         '(#t #t #f #f))
  (test-equal "NLTF" (list (< 3.14 zz) (< zz 3.14)
               (< 3.15 zz) (< zz 3.15)
               (< 3.13 zz) (< zz 3.13))
         '(#f #f #f #t #t #f))
  (test-equal "NLEF" (list (<= 3.14 zz) (<= zz 3.14)
               (<= 3.15 zz) (<= zz 3.15)
               (<= 3.13 zz) (<= zz 3.13))
         '(#t #t #f #t #t #f))
  (test-equal "NGTF" (list (> 3.14 zz) (> zz 3.14)
               (> 3.15 zz) (> zz 3.15)
               (> 3.13 zz) (> zz 3.13))
         '(#f #f #t #f #f #t))
  (test-equal "NGEF" (list (>= 3.14 zz) (>= zz 3.14)
               (>= 3.15 zz) (>= zz 3.15)
               (>= 3.13 zz) (>= zz 3.13))
         '(#t #t #t #f #f #t))
  )

;; Go through number comparison routines.
;; assumes a >= b, a > 0, b > 0
;; we use apply to prevent inlining.
(define (numcmp-test msg eq a b) 
  (let ((pp (list a b))
        (pm (list a (- b)))
        (mp (list (- a) b))
        (mm (list (- a) (- b))))
    (define (test4 op opname rev results)
      (for-each (lambda (result comb args)
                  (let ((m (conc msg " " (if rev 'rev "") opname "(" comb ")")))
                   (test-equal m (apply op (if rev (reverse args) args)) result)))
                results '(++ +- -+ --) (list pp pm mp mm)))
    (test4 =  '=  #f (list eq #f #f eq))
    (test4 =  '=  #t (list eq #f #f eq))
    (test4 >= '>= #f (list #t #t #f eq))
    (test4 >= '>= #t (list eq #f #t #t))
    (test4 >  '>  #f (list (not eq) #t #f #f))
    (test4 >  '>  #t (list #f #f #t (not eq)))
    (test4 <= '<= #f (list eq #f #t #t))
    (test4 <= '<= #t (list #t #t #f eq))
    (test4 <  '<  #f (list #f #f #t (not eq)))
    (test4 <  '<  #t (list (not eq) #t #f #f))
    ))

(numcmp-test "fixnum vs fixnum eq" #t 156 156)
(numcmp-test "fixnum vs fixnum ne" #f 878252 73224)
(numcmp-test "bignum vs fixnum ne" #f (expt 3 50) 9982425)
(numcmp-test "bignum vs bignum eq" #t (expt 3 50) (expt 3 50))
(numcmp-test "bignum vs bignum ne" #f (expt 3 50) (expt 3 49))
(numcmp-test "flonum vs fixnum eq" #t 314.0 314)
(numcmp-test "flonum vs fixnum ne" #f 3140.0 314)
(numcmp-test "flonum vs bignum eq" #t (expt 2.0 64) (expt 2 64))
(numcmp-test "flonum vs bignum ne" #f (expt 2.0 64) (expt 2 63))
(numcmp-test "ratnum vs fixnum ne" #f 13/2 6)
(numcmp-test "ratnum vs ratnum eq" #t 3/5 3/5)
(numcmp-test "ratnum vs ratnum 1 ne" #f 3/5 4/7)
(numcmp-test "ratnum vs ratnum 2 ne" #f 4/5 3/7)
(numcmp-test "ratnum vs ratnum 3 ne" #f 4/7 2/5)
(numcmp-test "ratnum vs ratnum 4 ne" #f 4/7 3/7)
(numcmp-test "ratnum vs flonum eq" #t 3/8 0.375)
(numcmp-test "ratnum vs flonum ne" #f 8/9 0.6)
(numcmp-test "ratnum vs bignum ne" #f (/ (+ (expt 2 64) 1) 2) (expt 2 63))

;; This is from the bug report from Bill Schottsteadt.  Before 0.8.10
;; this yielded #t because of the precision loss in fixnum vs ratnum
;; comparison.

(test-equal "fixnum/ratnum comparison" (= -98781233389595723930250385525631360344437602649022271391716773162526352115087074898920261954897888235939429993829738630297052776667061779065100945771127020439712527398509771853491319737304616607041615012797134365574007368603232768089410097730646360760856052946465578073788924743642391638455649511108051053789425902013657106523269224045822294981391380222050223141347787674321888089837786284947870569165079491411110074602544203383038299901291952931113248943344436935596614205784436844912243069019367149526328612664067719765890897558075277707055756274228634652905751880612235340874976952880431555921814590049070979276358637989837532124647692152520447680373275200239544449293834424643702763974403094033892112967196087310232853165951285609426599617479356206218697586025251765476179158153123631158173662488102357611674821528467825910806391548770908013608889792001203039243914696463472490444573930050190716726220002151679336252008777326482398042427845860796285369622627679324605214987983884122808994422164327311297556122943400093231935477754959547620500784989043704825777186301417894825200797719289692636286337716705491307686644214213732116277102140558505945554566856673724837541141206267647285222293953181717113434757149921850120377706206012113994795124049471433490016083401216757825264766474891405185591236321448744678896448941259668731597494947127423662646933419809756274038044752395708014998820826196523041220918922611359697502638594907608648168849193813197790291360087857093790119162389573209640804111261616771827989939551840471235079945175327536638365874717775169210186608268924244639016270610098894971732892267642318266405837012482726627199088381027028630711279130575230815976484191675172279903609489448225149181063260231957171204855841611039996959582465138269247794842445177715476581512709861409446684911276158067098438009067149531119008707418601627426255891/2063950098473886055933596136103014753954685977787179797499441692283103642150668140884348149132839387663291870239435604463778573480782766958396423322880804442523056530013282118705429274303746421980903580754656364533869319744640130831962767797772323836293079599182477171562218297208495122660799328579852852969560730744211066545295945803939271680397511478811389399527913043145952054883289558914237172406636283114284363301999238526952309439259354223729114988806937903509692118585280437646676248013406270664905997291670857985754768850507766359973207600149782819306010561088246502918148146264806947375101624011387317921439210509902170092173796154464078297852707797984007992277904626058467143192149921546030028316990855470478894515952884526783686210401408859364838148201339959570732480920969000913791571631154267939054105878236201498477027265774680071188764947522112650857013491135901945605796776829525789886482760578142306057177990048751864852763036720112071475134369179525117161001517868525821398753039187062869247457336940152614866298628205010037695017885878296140891234142925514925051385440766473260338168038302226808098439763889250948602137806546736025439919604390464712793474019469457135856879584745805794574609707742445431851999335443724488636749987837445626810087003490329257105472274738811579817454656532496370562155449815456374456838912258383282154811001588175608617475540639254689723629881619252699580383612847920348111900440075645703960104081690968807839189109040568288972353424306876947127635585164905071821419089229871978994388197349499565628906992171901547121903117815637249359328193980583892566359962066242217169190169986105579733710057404319381685578470983838597020624234209884597110721892707818651210378187525863009879314177842634871978427592746452643603586344401223449546482306838947819060455178762434166799996220143825677025686435609179225302671777326568324855229172912876656233006785717920665743720753617646617017219230313226844735567400507490772935145894670445831971526014183234960075574401616682479457962912905141754252265169682318523572680657053374002911007741991220001444440319448034755483178790032581428679303588017268970 0)
       #f)


;;==================================================================
;; Fixnum stuff
;;

(test-equal "fixnum? fixnum" (fixnum? 0) #t)
(test-equal "fixnum? ratnum" (fixnum? 1/2) #f)
(test-equal "fixnum? bignum" (fixnum? (expt 2 256)) #f)
(test-equal "fixnum? flonum" (fixnum? 3.14) #f)
(test-equal "fixnum? compnum" (fixnum? 1+3i) #f)

(test-equal "fixnum? greatest"    (fixnum? (greatest-fixnum)) #t)
(test-equal "fixnum? greatest+1"  (fixnum? (+ (greatest-fixnum) 1)) #f)
(test-equal "fixnum? least"       (fixnum? (least-fixnum)) #t)
(test-equal "fixnum? least-1"     (fixnum? (- (least-fixnum) 1)) #f)

(test-equal "greatest fixnum & width" (- (ash 1 (fixnum-width)) 1)
       (greatest-fixnum))
(test-equal "least fixnum & width" (- (ash 1 (fixnum-width)))
       (least-fixnum))

(test-end)

;;==================================================================
;; Arithmetics
;;

;;------------------------------------------------------------------
(test-begin "integer addition")

(define x #xffffffff00000000ffffffff00000000)
(define xx (- x))
(define y #x00000002000000000000000200000000)
(define yy (- y))
(define z #x00000000000000010000000000000001)
(test-equal "bignum + bignum" (+ x y)
      #x100000001000000010000000100000000)
(test-equal "bignum + -bignum" (+ x yy)
      #xfffffffd00000000fffffffd00000000)
(test-equal "bignum - bignum" (- x z)
      #xfffffffefffffffffffffffeffffffff)
(test-equal "bignum - bignum" (- (+ x y) y)
      x)
(test-equal "-bignum + bignum" (+ xx y)
      #x-fffffffd00000000fffffffd00000000)
(test-equal "-bignum + -bignum" (+ xx yy)
      #x-100000001000000010000000100000000)
(test-equal "-bignum - bignum" (- xx y)
      #x-100000001000000010000000100000000)
(test-equal "-bignum - -bignum" (- xx yy)
      #x-fffffffd00000000fffffffd00000000)

;; This test a possible shortcut in Scm_Add etc.  We use apply
;; to avoid operators from being inlined.
(test-equal "0 + bignum" (list (apply + (list 0 x)) (apply + (list x 0)))
       (list x x))
(test-equal "0 - bignum" (list (apply - (list 0 x)) (apply - (list x 0)))
       (list (- x) x))
(test-equal "0 * bignum" (list (apply * (list 0 x)) (apply * (list x 0)))
       (list 0 0))
(test-equal "1 * bignum" (list (apply * (list 1 x)) (apply * (list x 1)))
       (list x x))
(test-equal "bignum / 1" (apply / (list x 1))
       x)

(test-end)

;;------------------------------------------------------------------
(test-begin "small immediate integer constants")

;; pushing small literal integer on the stack may be done
;; by combined instruction PUSHI.  These test if it works.

(define (foo a b c d e) (list a b c d e))

;; 2^19-1
(test-equal "PUSHI" (foo 0 524287 524288 -524287 -524288)
              '(0 524287 524288 -524287 -524288))
;; 2^51-1
(test-equal "PUSHI" (foo 0 2251799813685247 2251799813685248
             -2251799813685247 -2251799813685248)
              '(0 2251799813685247 2251799813685248
                  -2251799813685247 -2251799813685248 ))

(test-end)

;;------------------------------------------------------------------
(test-begin "small immediate integer additions")

;; small literal integer x (-2^19 <= x < 2^19 on 32bit architecture)
;; in binary addition/subtraction is compiled in special instructuions,
;; NUMADDI and NUMSUBI.

(define x 2)
(test-equal "NUMADDI" (+ 3 x) 5)
(test-equal "NUMADDI" (+ x 3) 5)
(test-equal "NUMADDI" (+ -1 x) 1)
(test-equal "NUMADDI" (+ x -1) 1)
(test-equal "NUMSUBI" (- 3 x) 1)
(test-equal "NUMSUBI" (- x 3) -1)
(test-equal "NUMSUBI" (- -3 x) -5)
(test-equal "NUMSUBI" (- x -3) 5)
(define x 2.0)
(test-equal "NUMADDI" (+ 3 x) 5.0)
(test-equal "NUMADDI" (+ x 3) 5.0)
(test-equal "NUMADDI" (+ -1 x) 1.0)
(test-equal "NUMADDI" (+ x -1) 1.0)
(test-equal "NUMSUBI" (- 3 x) 1.0)
(test-equal "NUMSUBI" (- x 3) -1.0)
(test-equal "NUMSUBI" (- -3 x) -5.0)
(test-equal "NUMSUBI" (- x -3) 5.0)
(define x #x100000000)
(test-equal "NUMADDI" (+ 3 x) #x100000003)
(test-equal "NUMADDI" (+ x 3) #x100000003)
(test-equal "NUMADDI" (+ -1 x) #xffffffff)
(test-equal "NUMADDI" (+ x -1) #xffffffff)
(test-equal "NUMSUBI" (- 3 x) #x-fffffffd)
(test-equal "NUMSUBI" (- x 3) #xfffffffd)
(test-equal "NUMSUBI" (- -3 x) #x-100000003)
(test-equal "NUMSUBI" (- x -3) #x100000003)
(define x 33/7)
(test-equal "NUMADDI" (+ 3 x) 54/7)
(test-equal "NUMADDI" (+ x 3) 54/7)
(test-equal "NUMADDI" (+ -1 x) 26/7)
(test-equal "NUMADDI" (+ x -1) 26/7)
(test-equal "NUMADDI" (- 3 x) -12/7)
(test-equal "NUMADDI" (- x 3) 12/7)
(test-equal "NUMADDI" (- -3 x) -54/7)
(test-equal "NUMADDI" (- x -3) 54/7)

(test-equal "NUMADDI" (+ 10 (if #t 20 25)) 30)
(test-equal "NUMADDI" (+ (if #t 20 25) 10) 30)
(test-equal "NUMADDI" (+ 10 (if #f 20 25)) 35)
(test-equal "NUMADDI" (+ (if #f 20 25) 10) 35)
(test-equal "NUMADDI" (let ((x #t)) (+ 10 (if x 20 25))) 30)
(test-equal "NUMADDI" (let ((x #t)) (+ (if x 20 25) 10)) 30)
(test-equal "NUMADDI" (let ((x #f)) (+ 10 (if x 20 25))) 35)
(test-equal "NUMADDI" (let ((x #f)) (+ (if x 20 25) 10)) 35)
(test-equal "NUMADDI" (+ 10 (do ((x 0 (+ x 1))) ((> x 10) x))) 21)
(test-equal "NUMADDI" (+ (do ((x 0 (+ x 1))) ((> x 10) x)) 10) 21)
(test-equal "NUMSUBI" (- 10 (if #t 20 25)) -10)
(test-equal "NUMSUBI" (- (if #t 20 25) 10) 10)
(test-equal "NUMSUBI" (- 10 (if #f 20 25)) -15)
(test-equal "NUMSUBI" (- (if #f 20 25) 10) 15)
(test-equal "NUMSUBI" (let ((x #t)) (- 10 (if x 20 25))) -10)
(test-equal "NUMSUBI" (let ((x #t)) (- (if x 20 25) 10)) 10)
(test-equal "NUMSUBI" (let ((x #f)) (- 10 (if x 20 25))) -15)
(test-equal "NUMSUBI" (let ((x #f)) (- (if x 20 25) 10)) 15)
(test-equal "NUMSUBI" (- 10 (do ((x 0 (+ x 1))) ((> x 10) x))) -1)
(test-equal "NUMSUBI" (- (do ((x 0 (+ x 1))) ((> x 10) x)) 10) 1)

(test-end)

;;------------------------------------------------------------------
(test-begin "immediate flonum integer arith")

;; tests special instructions for immediate flonum integer arithmetic


(define x 2.0)
(test-equal "NUMADDF" (+ 3 x) 5.0)
(test-equal "NUMADDF" (+ x 3) 5.0)
(test-equal "NUMADDF" (+ -1 x) 1.0)
(test-equal "NUMADDF" (+ x -1) 1.0)
(test-equal "NUMADDF" (+ +i x) 2.0+1.0i)
(test-equal "NUMADDF" (+ x +i) 2.0+1.0i)

(test-equal "NUMSUBF" (- 3 x) 1.0)
(test-equal "NUMSUBF" (- x 3) -1.0)
(test-equal "NUMSUBF" (- -3 x) -5.0)
(test-equal "NUMSUBF" (- x -3) 5.0)
(test-equal "NUMSUBF" (- +i x) -2.0+1.0i)
(test-equal "NUMSUBF" (- x +i) 2.0-1.0i)

(test-equal "NUMMULF" (* x 2) 4.0)
(test-equal "NUMMULF" (* 2 x) 4.0)
(test-equal "NUMMULF" (* x 1.5) 3.0)
(test-equal "NUMMULF" (* 1.5 x) 3.0)
(test-equal "NUMMULF" (* x +i) 0+2.0i)
(test-equal "NUMMULF" (* +i x) 0+2.0i)

(test-equal "NUMDIVF" (/ x 4) 0.5)
(test-equal "NUMDIVF" (/ 4 x) 2.0)
(test-equal "NUMDIVF" (/ x 4.0) 0.5)
(test-equal "NUMDIVF" (/ 4.0 x) 2.0)
(test-equal "NUMDIVF" (/ x +4i) 0.0-0.5i)
(test-equal "NUMDIVF" (/ +4i x) 0.0+2.0i)

(test-end)

;;------------------------------------------------------------------
(test-begin "rational number addition")

(test-equal "ratnum +" (+ 11/13 21/19) 482/247)
(test-equal "ratnum -" (- 11/13 21/19) -64/247)

;; tests possible shortcut in Scm_Add etc.
(test-equal "ratnum + 0" (list (apply + '(0 11/13)) (apply + '(11/13 0)))
       (list 11/13 11/13))
(test-equal "ratnum - 0" (list (apply - '(0 11/13)) (apply - '(11/13 0)))
       (list -11/13 11/13))
(test-equal "ratnum * 0" (list (apply * '(0 11/13)) (apply * '(11/13 0)))
       (list 0 0))
(test-equal "ratnum * 1" (list (apply * '(1 11/13)) (apply * '(11/13 1)))
       (list 11/13 11/13))
(test-equal "ratnum / 1" (apply / '(11/13 1))
       11/13)

(test-end)

;;------------------------------------------------------------------
(test-begin "promotions in addition")

(define-syntax +-tester
  (syntax-rules ()
    ((_ (+ args ...))
     (let ((inline (+ args ...))
           (other  (apply + `(,args ...))))
       (and (= inline other)
            (list inline (exact? inline)))))))

(test-equal "+" (+-tester (+)) '(0 #t))
(test-equal "+" (+-tester (+ 1)) '(1 #t))
(test-equal "+" (+-tester (+ 1 2)) '(3 #t))
(test-equal "+" (+-tester (+ 1 2 3)) '(6 #t))
(test-equal "+" (+-tester (+ 1/6 1/3 1/2)) '(1 #t))
(test-equal "+" (+-tester (+ 1.0)) '(1.0 #f))
(test-equal "+" (+-tester (+ 1.0 2)) '(3.0 #f))
(test-equal "+" (+-tester (+ 1 2.0)) '(3.0 #f))
(test-equal "+" (+-tester (+ 1 2 3.0)) '(6.0 #f))
(test-equal "+" (+-tester (+ 1/6 1/3 0.5)) '(1.0 #f))
(test-equal "+" (+-tester (+ 1 +i)) '(1+i #t))
(test-equal "+" (+-tester (+ 1 2 +i)) '(3+i #t))
(test-equal "+" (+-tester (+ +i 1 2)) '(3+i #t))
(test-equal "+" (+-tester (+ 1.0 2 +i)) '(3.0+i #f))
(test-equal "+" (+-tester (+ +i 1.0 2)) '(3.0+i #f))
(test-equal "+" (+-tester (+ 4294967297 1.0)) '(4294967298.0 #f))
(test-equal "+" (+-tester (+ 4294967297 1 1.0)) '(4294967299.0 #f))
(test-equal "+" (+-tester (+ 4294967297 1.0 -i)) '(4294967298.0-i #f))
(test-equal "+" (+-tester (+ -i 4294967297 1.0)) '(4294967298.0-i #f))
(test-equal "+" (+-tester (+ 1.0 4294967297 -i)) '(4294967298.0-i #f))

(test-end)

;;------------------------------------------------------------------
(test-begin "integer multiplication")

(define (m-result x) (list x (- x) (- x) x x (- x) (- x) x))
(define (m-tester x y)
  (list (* x y) (* (- x) y) (* x (- y)) (* (- x) (- y))
        (apply * (list x y)) (apply * (list (- x) y))
        (apply * (list x (- y))) (apply * (list (- x) (- y)))))

(test-equal "fix*fix->big[1]" (m-tester 41943 17353)
      (m-result 727836879))
(test-equal "fix*fix->big[1]" (m-tester 41943 87353)
      (m-result 3663846879))
(test-equal "fix*fix->big[2]" (m-tester 65536 65536)
      (m-result 4294967296))
(test-equal "fix*fix->big[2]" (m-tester 4194303 87353)
      (m-result 366384949959))
(test-equal "fix*big[1]->big[1]" (m-tester 3 1126270821)
      (m-result 3378812463))
(test-equal "fix*big[1]->big[2]" (m-tester 85746 4294967296)
      (m-result 368276265762816))
(test-equal "big[1]*fix->big[1]" (m-tester 1126270821 3)
      (m-result 3378812463))
(test-equal "big[1]*fix->big[2]" (m-tester 4294967296 85746)
      (m-result 368276265762816))
(test-equal "big[2]*fix->big[2]" (m-tester 535341266467 23)
      (m-result 12312849128741))
(test-equal "big[1]*big[1]->big[2]" (m-tester 1194726677 1126270821)
      (m-result 1345585795375391817))

;; Large number multiplication test using Fermat's number
;; The decomposition of Fermat's number is taken from
;;   http://www.dd.iij4u.or.jp/~okuyamak/Information/Fermat.html
(test-equal "fermat(7)" (* 59649589127497217 5704689200685129054721)
      (fermat 7))
(test-equal "fermat(8)" (* 1238926361552897
           93461639715357977769163558199606896584051237541638188580280321)
              (fermat 8))
(test-equal "fermat(9)" (* 2424833
           7455602825647884208337395736200454918783366342657
           741640062627530801524787141901937474059940781097519023905821316144415759504705008092818711693940737)
              (fermat 9))
(test-equal "fermat(10)" (* 45592577
           6487031809
           4659775785220018543264560743076778192897
           130439874405488189727484768796509903946608530841611892186895295776832416251471863574140227977573104895898783928842923844831149032913798729088601617946094119449010595906710130531906171018354491609619193912488538116080712299672322806217820753127014424577
           )
              (fermat 10))
(test-equal "fermat(11)" (* 319489
           974849
           167988556341760475137
           3560841906445833920513
           173462447179147555430258970864309778377421844723664084649347019061363579192879108857591038330408837177983810868451546421940712978306134189864280826014542758708589243873685563973118948869399158545506611147420216132557017260564139394366945793220968665108959685482705388072645828554151936401912464931182546092879815733057795573358504982279280090942872567591518912118622751714319229788100979251036035496917279912663527358783236647193154777091427745377038294584918917590325110939381322486044298573971650711059244462177542540706913047034664643603491382441723306598834177
           )
              (fermat 11))

(test-end)

;;------------------------------------------------------------------
(test-begin "multiplication short cuts")

(parameterize ((current-test-comparator eqv?))
;; these test shortcut in Scm_Mul
;; note the difference of 0 and 0.0
  (let1 big (read-from-string "100000000000000000000")
        (test-equal "bignum * 0"  (apply * `(,big 0)) 0)
        (test-equal "0 * bignum"  (apply * `(0 ,big)) 0)
        (test-equal "bignum * 1"  (apply * `(,big 1)) big)
        (test-equal "1 * bignum"  (apply * `(1 ,big)) big)
  
        (test-equal "bignum * 0.0"  (apply * `(,big 0.0)) 0.0)
        (test-equal "0.0 * bignum"  (apply * `(0.0 ,big)) 0.0)
        (test-equal "bignum * 1.0"  (apply * `(,big 1.0)) 1.0e20)
        (test-equal "1.0 * bignum"  (apply * `(1.0 ,big)) 1.0e20)
        )

(test-equal "ratnum * 0"  (apply * '(1/2 0)) 0)
(test-equal "0 * ratnum"  (apply * '(0 1/2)) 0)
(test-equal "ratnum * 1"  (apply * '(1/2 1)) 1/2)
(test-equal "1 * ratnum"  (apply * '(1 1/2)) 1/2)

(test-equal "ratnum * 0.0"  (apply * '(1/2 0.0)) 0.0)
(test-equal "0.0 * ratnum"  (apply * '(0.0 1/2)) 0.0)
(test-equal "ratnum * 1.0"  (apply * '(1/2 1.0)) 0.5)
(test-equal "1.0 * ratnum"  (apply * '(1.0 1/2)) 0.5)

;; Fixed for exactness (Gauche represents zero always exactly?)
(test-equal "flonum * 0"  (apply * '(3.0 0)) 0.0)
(test-equal "0 * flonum"  (apply * '(0 3.0)) 0.0)
(test-equal "flonum * 1"  (apply * '(3.0 1)) 3.0)
(test-equal "1 * flonum"  (apply * '(1 3.0)) 3.0)

(test-equal "flonum * 0.0"  (apply * '(3.0 0.0)) 0.0)
(test-equal "0.0 * flonum"  (apply * '(0.0 3.0)) 0.0)
(test-equal "flonum * 1.0"  (apply * '(3.0 1.0)) 3.0)
(test-equal "1.0 * flonum"  (apply * '(1.0 3.0)) 3.0)

(test-equal "compnum * 0" (* 0 +i) 0)
(test-equal "0 * compnum" (* +i 0) 0)
(test-equal "compnum * 1" (* 1 +i) +i)
(test-equal "1 * compnum" (* +i 1) +i)

(test-equal "compnum * 0.0" (* 0.0 +i) 0.0)
(test-equal "0.0 * compnum" (* +i 0.0) 0.0)
(test-equal "compnum * 1.0" (* 1.0 +i) +1.0i)
(test-equal "1.0 * compnum" (* +i 1.0) +1.0i))

(test-end)

;;------------------------------------------------------------------
(test-begin "division")

(test-equal "exact division" (/ 3 4 5) 3/20)
(test-equal "exact division" (/ 9223372036854775808 18446744073709551616)  1/2)
(test-equal "exact division" (/ 28153784189046 42)
       4692297364841/7)
(test-equal "exact division" (/ 42 28153784189046)
       7/4692297364841)
(test-equal "exact division" (/ 42 -28153784189046)
       -7/4692297364841)
(test-equal "exact division" (/ -42 -28153784189046)
       7/4692297364841)
(test-equal "exact reciprocal" (/ 3) 1/3)
(test-equal "exact reciprocal" (/ -3) -1/3)
(test-equal "exact reciprocal" (/ 6/5) 5/6)
(test-equal "exact reciprocal" (/ -6/5) -5/6)
(test-equal "exact reciprocal" (/ 4692297364841/7) 7/4692297364841)

(define (almost=? x y)
  (define (flonum=? x y)
    (let ((ax (abs x)) (ay (abs y)))
      (< (abs (- x y)) (* (max ax ay) 0.0000000000001))))
  (and (flonum=? (car x) (car y))
       (flonum=? (cadr x) (cadr y))
       (flonum=? (caddr x) (caddr y))
       (flonum=? (cadddr x) (cadddr y))
       (eq? (list-ref x 4) (list-ref y 4))))

(define (d-result x exact?) (list x (- x) (- x) x exact?))
(define (d-tester x y)
  (list (/ x y) (/ (- x) y) (/ x (- y)) (/ (- x) (- y))
        (exact? (/ x y))))

;; inexact division
(test-equal "exact/inexact -> inexact" (d-tester 13 4.0)
      (d-result 3.25 #f))
(test-equal "exact/inexact -> inexact" (d-tester 13/2 4.0)
      (d-result 1.625 #f))
(test-equal "inexact/exact -> inexact" (d-tester 13.0 4)
      (d-result 3.25 #f))
(test-equal "inexact/exact -> inexact" (d-tester 13.0 4/3)
      (d-result 9.75 #f))
(test-equal "inexact/inexact -> inexact" (d-tester 13.0 4.0)
      (d-result 3.25 #f))

;; complex division
(test-equal "complex division" (let ((a 3)
             (b 4+3i)
             (c 7.3))
         (- (/ a b c)
            (/ (/ a b) c)))
       0.0)

(test-end)

;;------------------------------------------------------------------
(test-begin "quotient")

(define (q-result x exact?) (list x (- x) (- x) x exact?))
(define (q-tester x y)
  (list (quotient x y) (quotient (- x) y)
        (quotient x (- y)) (quotient (- x) (- y))
        (exact? (quotient x y))))


;; these uses BignumDivSI -> bignum_sdiv
(test-equal "big[1]/fix->fix" (q-tester 727836879 41943) 
      (q-result 17353 #t))
(test-equal "big[1]/fix->fix" (q-tester 3735928559 27353)
      (q-result 136582 #t))
(test-equal "big[2]/fix->big[1]" (q-tester 12312849128741 23)
      (q-result 535341266467 #t))
(test-equal "big[2]/fix->big[2]" (q-tester 12312849128741 1)
      (q-result 12312849128741 #t))

;; these uses BignumDivSI -> bignum_gdiv
(test-equal "big[1]/fix->fix" (q-tester 3663846879 87353)
      (q-result 41943 #t))
(test-equal "big[2]/fix->fix" (q-tester 705986470884353 36984440)
      (q-result 19088743 #t))
(test-equal "big[2]/fix->fix" (q-tester 12312849128741 132546)
      (q-result 92894912 #t))
(test-equal "big[2]/fix->big[1]" (q-tester 425897458766735 164900)
      (q-result 2582762030 #t))

;; these uses BignumDivRem
(test-equal "big[1]/big[1]->fix" (q-tester 4020957098 1952679221)
      (q-result 2 #t))
(test-equal "big[1]/big[1] -> fix" (q-tester 1952679221 4020957098)
      (q-result 0 #t))
;; this tests loop in estimation phase
(test-equal "big[3]/big[2] -> big[1]" (q-tester #x10000000000000000 #x10000ffff)
      (q-result #xffff0001 #t))
;; this test goes through a rare case handling code ("add back") in
;; the algorithm.
(test-equal "big[3]/big[2] -> fix" (q-tester #x7800000000000000 #x80008889ffff)
      (q-result #xeffe #t))

;; inexact quotient
(test-equal "exact/inexact -> inexact" (q-tester 13 4.0)
      (q-result 3.0 #f))
(test-equal "inexact/exact -> inexact" (q-tester 13.0 4)
      (q-result 3.0 #f))
(test-equal "inexact/inexact -> inexact" (q-tester 13.0 4.0)
      (q-result 3.0 #f))
(test-equal "exact/inexact -> inexact" (q-tester 727836879 41943.0)
      (q-result 17353.0 #f))
(test-equal "inexact/exact -> inexact" (q-tester 727836879.0 41943)
      (q-result 17353.0 #f))
(test-equal "inexact/inexact -> inexact" (q-tester 727836879.0 41943.0)
      (q-result 17353.0 #f))

;; Test by fermat numbers
(test-equal "fermat(7)" (quotient (fermat 7) 5704689200685129054721)
      59649589127497217)
(test-equal "fermat(8)" (quotient (fermat 8) 93461639715357977769163558199606896584051237541638188580280321)
              1238926361552897)
(test-equal "fermat(9)" (quotient (quotient (fermat 9) 7455602825647884208337395736200454918783366342657)
                  741640062627530801524787141901937474059940781097519023905821316144415759504705008092818711693940737)
              2424833)
(test-equal "fermat(10)" (quotient (quotient (quotient (fermat 10)
                                      130439874405488189727484768796509903946608530841611892186895295776832416251471863574140227977573104895898783928842923844831149032913798729088601617946094119449010595906710130531906171018354491609619193912488538116080712299672322806217820753127014424577)
                            6487031809)
                  45592577)
              4659775785220018543264560743076778192897)
(test-equal "fermat(11)" (quotient (quotient (quotient (quotient (fermat 11)
                                                167988556341760475137)
                                      173462447179147555430258970864309778377421844723664084649347019061363579192879108857591038330408837177983810868451546421940712978306134189864280826014542758708589243873685563973118948869399158545506611147420216132557017260564139394366945793220968665108959685482705388072645828554151936401912464931182546092879815733057795573358504982279280090942872567591518912118622751714319229788100979251036035496917279912663527358783236647193154777091427745377038294584918917590325110939381322486044298573971650711059244462177542540706913047034664643603491382441723306598834177
                                      )
                            974849)
                  319489)
              3560841906445833920513)

(test-end)

;;------------------------------------------------------------------
(test-begin "remainder")

(define (r-result x exact?) (list x (- x) x (- x) exact?))
(define (r-tester x y)
  (list (remainder x y) (remainder (- x) y)
        (remainder x (- y)) (remainder (- x) (- y))
        (exact? (remainder x y))))

;; small int
(test-equal "fix rem fix -> fix" (r-tester 13 4)
      (r-result 1 #t))
(test-equal "fix rem fix -> fix" (r-tester 1234 87935)
      (r-result 1234 #t))
(test-equal "fix rem big[1] -> fix" (r-tester 12345 3735928559)
      (r-result 12345 #t))

;; these uses BignumDivSI -> bignum_sdiv
(test-equal "big[1] rem fix -> fix" (r-tester 727836879 41943)
      (r-result 0 #t))
(test-equal "big[1] rem fix -> fix" (r-tester 3735928559 27353)
      (r-result 1113 #t))
(test-equal "big[2] rem fix -> fix" (r-tester 12312849128756 23)
      (r-result 15 #t))
(test-equal "big[2] rem fix -> fix" (r-tester 12312849128756 1)
      (r-result 0 #t))

;; these uses BignumDivSI -> bignum_gdiv
(test-equal "big[1] rem fix -> fix" (r-tester 3663846879 87353)
      (r-result 0 #t))
(test-equal "big[2] rem fix -> fix" (r-tester 705986470884353 36984440)
      (r-result 725433 #t))
(test-equal "big[2] rem fix -> fix" (r-tester 12312849128741 132546)
      (r-result 122789 #t))
(test-equal "big[2] rem fix -> fix" (r-tester 425897458766735 164900)
      (r-result 19735 #t))

;; these uses BignumDivRem
(test-equal "big[1] rem big[1] -> fix" (r-tester 4020957098 1952679221)
      (r-result 115598656 #t))
(test-equal "big[1] rem big[1] -> fix" (r-tester 1952679221 4020957098)
      (r-result 1952679221 #t))
;; this tests loop in estimation phase
(test-equal "big[3] rem big[2] -> big[1]" (r-tester #x10000000000000000 #x10000ffff)
      (r-result #xfffe0001 #t))
;; this tests "add back" code
(test-equal "big[3] rem big[2] -> big[2]" (r-tester #x7800000000000000 #x80008889ffff)
      (r-result #x7fffb114effe #t))

;; inexact remainder
(test-equal "exact rem inexact -> inexact" (r-tester 13 4.0)
      (r-result 1.0 #f))
(test-equal "inexact rem exact -> inexact" (r-tester 13.0 4)
      (r-result 1.0 #f))
(test-equal "inexact rem inexact -> inexact" (r-tester 13.0 4.0)
      (r-result 1.0 #f))
(test-equal "exact rem inexact -> inexact" (r-tester 3735928559 27353.0)
      (r-result 1113.0 #f))
(test-equal "inexact rem exact -> inexact" (r-tester 3735928559.0 27353)
      (r-result 1113.0 #f))
(test-equal "inexact rem inexact -> inexact" (r-tester 3735928559.0 27353.0)
      (r-result 1113.0 #f))

(test-end)

;;------------------------------------------------------------------
(test-begin "modulo")

(define (m-result a b exact?) (list a b (- b) (- a) exact?))
(define (m-tester x y)
  (list (modulo x y) (modulo (- x) y)
        (modulo x (- y)) (modulo (- x) (- y))
        (exact? (modulo x y))))

;; small int
(test-equal "fix mod fix -> fix" (m-tester 13 4)
      (m-result 1 3 #t))
(test-equal "fix mod fix -> fix" (m-tester 1234 87935)
      (m-result 1234 86701 #t))
(test-equal "fix mod big[1] -> fix/big" (m-tester 12345 3735928559)
      (m-result 12345 3735916214 #t))

;; these uses BignumDivSI -> bignum_sdiv
(test-equal "big[1] mod fix -> fix" (m-tester 727836879 41943)
      (m-result 0 0 #t))
(test-equal "big[1] mod fix -> fix" (m-tester 3735928559 27353)
      (m-result 1113 26240 #t))
(test-equal "big[2] mod fix -> fix" (m-tester 12312849128756 23)
      (m-result 15 8 #t))
(test-equal "big[2] mod fix -> fix" (m-tester 12312849128756 1)
      (m-result 0 0 #t))

;; these uses BignumDivSI -> bignum_gdiv
(test-equal "big[1] mod fix -> fix" (m-tester 3663846879 87353)
      (m-result 0 0 #t))
(test-equal "big[2] mod fix -> fix" (m-tester 705986470884353 36984440)
      (m-result 725433 36259007 #t))
(test-equal "big[2] mod fix -> fix" (m-tester 12312849128741 132546)
      (m-result 122789 9757 #t))
(test-equal "big[2] mod fix -> fix" (m-tester 425897458766735 164900)
      (m-result 19735 145165 #t))

;; these uses BignumDivRem
(test-equal "big[1] mod big[1] -> fix" (m-tester 4020957098 1952679221)
      (m-result 115598656 1837080565 #t))
(test-equal "big[1] mod big[1] -> fix" (m-tester 1952679221 4020957098)
      (m-result 1952679221 2068277877 #t))
;; this tests loop in estimation phase
(test-equal "big[3] mod big[2] -> big[1]" (m-tester #x10000000000000000 #x10000ffff)
      (m-result #xfffe0001 #x2fffe #t))
;; this tests "add back" code
(test-equal "big[3] mod big[2] -> big[2]" (m-tester #x7800000000000000 #x80008889ffff)
      (m-result #x7fffb114effe #xd7751001 #t))

;; inexact modulo
(test-equal "exact mod inexact -> inexact" (m-tester 13 4.0)
      (m-result 1.0 3.0 #f))
(test-equal "inexact mod exact -> inexact" (m-tester 13.0 4)
      (m-result 1.0 3.0 #f))
(test-equal "inexact mod inexact -> inexact" (m-tester 13.0 4.0)
      (m-result 1.0 3.0 #f))
(test-equal "exact mod inexact -> inexact" (m-tester 3735928559 27353.0)
      (m-result 1113.0 26240.0 #f))
(test-equal "inexact mod exact -> inexact" (m-tester 3735928559.0 27353)
      (m-result 1113.0 26240.0 #f))
(test-equal "inexact mod inexact -> inexact" (m-tester 3735928559.0 27353.0)
      (m-result 1113.0 26240.0 #f))

;; test by mersenne prime? - code by 'hipster'

(define (mersenne-prime? p)
  (let ((m (- (expt 2 p) 1)))
    (do ((i 3 (+ i 1))
         (s 4 (modulo (- (* s s) 2) m)))
        ((= i (+ p 1)) (= s 0)))))

(test-equal "mersenne prime"
       (map mersenne-prime? '(3 5 7 13 17 19 31 61 89 107 127 521 607 1279))
       '(#t #t #t #t #t #t #t #t #t #t #t #t #t #t))

(test-end)

;;------------------------------------------------------------------
;; R6RS
#|
(test-begin "div and mod")

(let ()
  (define (do-quadrants proc)
    (lambda (x y =)
      (proc x y =)
      (proc (- x) y =)
      (proc x (- y) =)
      (proc (- x) (- y) =)))

  (define (test-div x y =)
    (test-equal (format "~a div ~a" x y) (receive (d m) (div-and-mod x y)
             (let1 z (+ (* d y) m)
               (list (or (= x z) z)
                     (or (and (<= 0 m) (< m (abs y))) m))))
           '(#t #t)))

  (define (test-div0 x y =)
    (test-equal (format "~a div0 ~a" x y) (receive (d m) (div0-and-mod0 x y)
             (let1 z (+ (* d y) m)
               (list (or (= x z) z)
                     (or (and (<= (- (abs y)) (* m 2))
                              (< (* m 2) (abs y)))
                         m))))
           '(#t #t)))

  ((do-quadrants test-div) 123 10 =)
  (parameterize ((current-test-epsilon 1e-10))
    ((do-quadrants test-div) 123.0 10.0 =))
  ((do-quadrants test-div) (read-from-string "123/7") (read-from-string "10/7") =)
  ((do-quadrants test-div) (read-from-string "123/7") 5 =)
  ((do-quadrants test-div) 123 (read-from-string "5/7") =)
  ((do-quadrants test-div) 130.75 10.5 =)

  ((do-quadrants test-div0) 123 10 =)
  ((do-quadrants test-div0) 129 10 =)
  (parameterize ((current-test-epsilon 1e-10))
   ((do-quadrants test-div0) 123.0 10.0 =)
   ((do-quadrants test-div0) 129.0 10.0 =))
  ((do-quadrants test-div0) (read-from-string "123/7") (read-from-string "10/7") =)
  ((do-quadrants test-div0) (read-from-string "129/7") (read-from-string "10/7") =)
  ((do-quadrants test-div0) (read-from-string "121/7") 5 =)
  ((do-quadrants test-div0) (read-from-string "124/7") 5 =)
  ((do-quadrants test-div0) 121 (read-from-string "5/7") =)
  ((do-quadrants test-div0) 124 (read-from-string "5/7") =)
  ((do-quadrants test-div0) 130.75 10.5 =)
  ((do-quadrants test-div0) 129.75 10.5 =)
  )

(test-end)
|#
;;------------------------------------------------------------------
(test-begin "rounding")

(define (round-tester value exactness cei flo tru rou)
  (test-equal (string-append "rounding " (number->string value))
         (let ((c (ceiling value))
               (f (floor value))
               (t (truncate value))
               (r (round value)))
           (list (and (exact? c) (exact? f) (exact? t) (exact? r))
                 c f t r))
         (list exactness cei flo tru rou)))

(round-tester 0  #t 0 0 0 0)
(round-tester 3  #t 3 3 3 3)
(round-tester -3 #t -3 -3 -3 -3)
(round-tester (expt 2 99) #t (expt 2 99) (expt 2 99) (expt 2 99) (expt 2 99))
(round-tester (- (expt 2 99)) #t
              (- (expt 2 99)) (- (expt 2 99)) (- (expt 2 99)) (- (expt 2 99)))

(round-tester 9/4  #t 3 2 2 2)
(round-tester -9/4 #t -2 -3 -2 -2)
(round-tester 34985495387484938453495/17 #t
              2057970316910878732559
              2057970316910878732558
              2057970316910878732558
              2057970316910878732559)
(round-tester -34985495387484938453495/17 #t
              -2057970316910878732558
              -2057970316910878732559
              -2057970316910878732558
              -2057970316910878732559)

(round-tester 35565/2 #t 17783 17782 17782 17782)
(round-tester -35565/2 #t -17782 -17783 -17782 -17782)
(round-tester 35567/2 #t 17784 17783 17783 17784)
(round-tester -35567/2 #t -17783 -17784 -17783 -17784)

(test-equal "round->exact" (round->exact 3.4) 3)
(test-equal "round->exact" (round->exact 3.5) 4)
(test-equal "floor->exact" (floor->exact 3.4) 3)
(test-equal "floor->exact" (floor->exact -3.5) -4)
(test-equal "ceiling->exact" (ceiling->exact 3.4) 4)
(test-equal "ceiling->exact" (ceiling->exact -3.5) -3)
(test-equal "truncate->exact" (truncate->exact 3.4) 3)
(test-equal "truncate->exact" (truncate->exact -3.5) -3)

(test-end)

;;------------------------------------------------------------------

#|
;; Nonstandard and Gauche-specific
(test-begin "clamping")

(parameterize ((current-test-comparator eqv?))
 (test-equal "clamp (1)"   (clamp 1)   1)
 (test-equal "clamp (1 #f)" (clamp 1 #f)  1)
 (test-equal "clamp (1 #f #f)" (clamp 1 #f #f)  1)
 (test-equal "clamp (1.0)"   (clamp 1.0)   1.0)
 (test-equal "clamp (1.0 #f)" (clamp 1.0 #f)  1.0)
 (test-equal "clamp (1.0 #f #f)" (clamp 1.0 #f #f)  1.0)

 (test-equal "clamp (1 0)" (clamp 1 0)   1)
 (test-equal "clamp (1 0 #f)" (clamp 1 0 #f) 1)
 (test-equal "clamp (1 0 2)" (clamp 1 0 2) 1)
 (test-equal "clamp (1 5/4)" (clamp 1 5/4) 5/4)
 (test-equal "clamp (1 5/4 #f)" (clamp 1 5/4 #f) 5/4)
 (test-equal "clamp (1 #f 5/4)" (clamp 1 #f 5/4) 1)
 (test-equal "clamp (1 0 3/4)" (clamp 1 0 3/4) 3/4)
 (test-equal "clamp (1 #f 3/4)" (clamp 1 #f 3/4) 3/4)

 (test-equal "clamp (1.0 0)" (clamp 1.0 0)   1.0)
 (test-equal "clamp (1.0 0 #f)" (clamp 1.0 0 #f) 1.0)
 (test-equal "clamp (1.0 0 2)" (clamp 1.0 0 2) 1.0)
 (test-equal "clamp (1.0 5/4)" (clamp 1.0 5/4) 1.25)
 (test-equal "clamp (1.0 5/4 #f)" (clamp 1.0 5/4 #f) 1.25)
 (test-equal "clamp (1.0 #f 5/4)" (clamp 1.0 #f 5/4) 1.0)
 (test-equal "clamp (1.0 0 3/4)" (clamp 1.0 0 3/4) 0.75)
 (test-equal "clamp (1.0 #f 3/4)" (clamp 1.0 #f 3/4) 0.75)

 (test-equal "clamp (1 0.0)" (clamp 1 0.0)   1.0)
 (test-equal "clamp (1 0.0 #f)" (clamp 1 0.0 #f) 1.0)
 (test-equal "clamp (1 0.0 2)" (clamp 1 0.0 2) 1.0)
 (test-equal "clamp (1 0 2.0)" (clamp 1 0 2.0) 1.0)
 (test-equal "clamp (1 1.25)" (clamp 1 1.25) 1.25)
 (test-equal "clamp (1 #f 1.25)" (clamp 1 #f 1.25) 1.0)
 (test-equal "clamp (1 1.25 #f)" (clamp 1 1.25 #f) 1.25)
 (test-equal "clamp (1 0.0 3/4)" (clamp 1 0.0 3/4) 0.75)
 (test-equal "clamp (1 0 0.75)" (clamp 1 0 0.75) 0.75)

 (test-equal "clamp (1 -inf.0 +inf.0)" (clamp 1 -inf.0 +inf.0) 1.0))

(test-end)
|#

;;------------------------------------------------------------------
(test-begin "logical operations")

(test-equal "ash (fixnum)" (ash #x81 15)           ;fixnum
      #x408000)
(test-equal "ash (fixnum)" (ash #x408000 -15)
      #x81)
(test-equal "ash (fixnum)" (ash #x408000 -22)
      #x01)
(test-equal "ash (fixnum)" (ash #x408000 -23)
      0)
(test-equal "ash (fixnum)" (ash #x408000 -24)
      0)
(test-equal "ash (fixnum)" (ash #x408000 -100)
      0)
(test-equal "ash (fixnum)" (ash #x81 0)
      #x81)
(test-equal "ash (neg. fixnum)" (ash #x-81 15)  ;negative fixnum
      #x-408000)
(test-equal "ash (neg. fixnum)" (ash #x-408000 -15)      ;nagative fixnum
      #x-81)
(test-equal "ash (fixnum)" (ash #x-408000 -22)
      -2)
(test-equal "ash (fixnum)" (ash #x-408000 -23)
      -1)
(test-equal "ash (fixnum)" (ash #x-408000 -24)
      -1)
(test-equal "ash (fixnum)" (ash #x-408000 -100)
      -1)
(test-equal "ash (fixnum)" (ash #x-408000 0)
      #x-408000)


(test-equal "ash (fixnum->bignum)" (ash #x81 24)
      #x81000000)
(test-equal "ash (fixnum->bignum)" (ash #x81 31)
      #x4080000000)
(test-equal "ash (fixnum->bignum)" (ash #x81 32)
      #x8100000000)
(test-equal "ash (fixnum->bignum)" (ash #x81 56)
      #x8100000000000000)
(test-equal "ash (fixnum->bignum)" (ash #x81 63)
      #x408000000000000000)
(test-equal "ash (fixnum->bignum)" (ash #x81 64)
      #x810000000000000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 24)
      #x-81000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 31)
      #x-4080000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 32)
      #x-8100000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 56)
      #x-8100000000000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 63)
      #x-408000000000000000)
(test-equal "ash (neg.fixnum->bignum)" (ash #x-81 64)
      #x-810000000000000000)

(test-equal "ash (bignum->fixnum)" (ash  #x81000000 -24)
      #x81)
(test-equal "ash (bignum->fixnum)" (ash  #x81000000 -25)
      #x40)
(test-equal "ash (bignum->fixnum)" (ash  #x81000000 -31)
      1)
(test-equal "ash (bignum->fixnum)" (ash  #x81000000 -32)
      0)
(test-equal "ash (bignum->fixnum)" (ash  #x81000000 -100)
      0)
(test-equal "ash (bignum->fixnum)" (ash #x4080000000 -31)
      #x81)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000 -32)
      #x81)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000 -33)
      #x40)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000 -39)
      1)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000 -40)
      0)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000 -100)
      0)
(test-equal "ash (bignum->fixnum)" (ash #x8100000000000000 -56)
      #x81)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -63)
      #x81)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -64)
      #x40)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -65)
      #x20)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -70)
      1)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -71)
      0)
(test-equal "ash (bignum->fixnum)" (ash #x408000000000000000 -100)
      0)

(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -24)
      #x-81)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -25)
      #x-41)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -26)
      #x-21)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -31)
      -2)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -32)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -33)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-81000000 -100)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -31)
      #x-81)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -32)
      #x-41)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -33)
      #x-21)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -38)
      -2)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -39)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-4080000000 -100)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -63)
      #x-81)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -64)
      #x-41)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -65)
      #x-21)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -70)
      -2)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -71)
      -1)
(test-equal "ash (neg.bignum->fixnum)" (ash #x-408000000000000000 -72)
      -1)

(test-equal "ash (bignum->bignum)" (ash #x1234567812345678 4)
      #x12345678123456780)
(test-equal "ash (bignum->bignum)" (ash #x1234567812345678 60)
      #x1234567812345678000000000000000)
(test-equal "ash (bignum->bignum)" (ash #x1234567812345678 64)
      #x12345678123456780000000000000000)
(test-equal "ash (bignum->bignum)" (ash #x1234567812345678 -4)
      #x123456781234567)
(test-equal "ash (bignum->bignum)" (ash #x1234567812345678 -32)
      #x12345678)
(test-equal "ash (neg.bignum->bignum)" (ash #x-1234567812345678 -4)
      #x-123456781234568)
(test-equal "ash (bignum->bignum)" (ash #x-1234567812345678 -32)
      #x-12345679)

(test-equal "lognot (fixnum)" (lognot 0) -1)
(test-equal "lognot (fixnum)" (lognot -1) 0)
(test-equal "lognot (fixnum)" (lognot 65535) -65536)
(test-equal "lognot (fixnum)" (lognot -65536) 65535)
(test-equal "lognot (bignum)" (lognot #x1000000000000000000)
      #x-1000000000000000001)
(test-equal "lognot (bignum)" (lognot #x-1000000000000000001)
      #x1000000000000000000)

(test-equal "logand (+fix & 0)" (logand #x123456 0)
      0)
(test-equal "logand (+big & 0)" (logand #x1234567812345678 0)
      0)
(test-equal "logand (+fix & -1)" (logand #x123456 -1)
      #x123456)
(test-equal "logand (+big & -1)" (logand #x1234567812345678 -1)
      #x1234567812345678)
(test-equal "logand (+fix & +fix)" (logand #xaa55 #x6666)
      #x2244)
(test-equal "logand (+fix & +big)" (logand #xaa55 #x6666666666)
      #x2244)
(test-equal "logand (+big & +fix)" (logand #xaa55aa55aa #x6666)
      #x4422)
(test-equal "logand (+big & +big)" (logand #xaa55aa55aa #x6666666666)
      #x2244224422)
(test-equal "logand (+big & +big)" (logand #x123456789abcdef #xfedcba987654321fedcba987654321fedcba)
      #x103454301aaccaa)
(test-equal "logand (+big & +big)" (logand #xaa55ea55aa #x55aa55aa55)
      #x400000)
(test-equal "logand (+fix & -fix)" (logand #xaa55 #x-6666)
      #x8810)
(test-equal "logand (+fix & -big)" (logand #xaa55 #x-6666666666)
      #x8810)
(test-equal "logand (+big & -fix)" (logand #xaa55aa55aa #x-6666)
      #xaa55aa118a)
(test-equal "logand (+big & -big)" (logand #xaa55aa55aa #x-6666666666)
      #x881188118a)
(test-equal "logand (+big & -big)" (logand #x123456789abcdef #x-fedcba987654321fedcba987654321fedcba)
      #x20002488010146)
(test-equal "logand (-fix & +fix)" (logand #x-aa55 #x6666)
      #x4422)
(test-equal "logand (-fix & +big)" (logand #x-aa55 #x6666666666)
      #x6666664422)
(test-equal "logand (-big & +fix)" (logand #x-aa55aa55aa #x6666)
      #x2246)
(test-equal "logand (-big & +big)" (logand #x-aa55aa55aa #x6666666666)
      #x4422442246)
(test-equal "logand (-big & +big)" (logand #x-123456789abcdef #xfedcba987654321fedcba987654321fedcba)
      #xfedcba987654321fedcba884200020541010)
(test-equal "logand (-fix & -fix)" (logand #x-aa55 #x-6666)
      #x-ee76)
(test-equal "logand (-fix & -big)" (logand #x-aa55 #x-6666666666)
      #x-666666ee76)
(test-equal "logand (-big & -fix)" (logand #x-aa55aa55aa #x-6666)
      #x-aa55aa77ee)
(test-equal "logand (-big & -big)" (logand #x-aa55aa55aa #x-6666666666)
      #x-ee77ee77ee)
(test-equal "logand (-big & -big)" (logand #x-123456789abcdef #x-fedcba987654321fedcba987654321fedcba)
      #x-fedcba987654321fedcba9a76567a9ffde00)

(test-equal "logior (+fix | 0)" (logior #x123456 0)
      #x123456)
(test-equal "logior (+big | 0)" (logior #x1234567812345678 0)
      #x1234567812345678)
(test-equal "logior (+fix | -1)" (logior #x123456 -1)
      -1)
(test-equal "logior (+big | -1)" (logior #x1234567812345678 -1)
      -1)
(test-equal "logior (+fix | +fix)" (logior #xaa55 #x6666)
      #xee77)
(test-equal "logior (+fix | +big)" (logior #xaa55 #x6666666666)
      #x666666ee77)
(test-equal "logior (+big | +fix)" (logior #xaa55aa55aa #x6666)
      #xaa55aa77ee)
(test-equal "logior (+big | +big)" (logior #xaa55aa55aa #x6666666666)
      #xee77ee77ee)
(test-equal "logior (+big | +big)" (logior #x123456789abcdef #xfedcba987654321fedcba987654321fedcba)
      #xfedcba987654321fedcba9a76567a9ffddff)
(test-equal "logior (+fix | -fix)" (logior #xaa55 #x-6666)
      #x-4421)
(test-equal "logior (+fix | -big)" (logior #xaa55 #x-6666666666)
      #x-6666664421)
(test-equal "logior (+big | -fix)" (logior #xaa55aa55aa #x-6666)
      #x-2246)
(test-equal "logior (+big | -big)" (logior #xaa55aa55aa #x-6666666666)
      #x-4422442246)
(test-equal "logior (+big | -big)" (logior #x123456789abcdef #x-fedcba987654321fedcba987654321fedcba)
      #x-fedcba987654321fedcba884200020541011)
(test-equal "logior (-fix | +fix)" (logior #x-aa55 #x6666)
      #x-8811)
(test-equal "logior (-fix | +big)" (logior #x-aa55 #x6666666666)
      #x-8811)
(test-equal "logior (-big | +fix)" (logior #x-aa55aa55aa #x6666)
      #x-aa55aa118a)
(test-equal "logior (-big | +big)" (logior #x-aa55aa55aa #x6666666666)
      #x-881188118a)
(test-equal "logior (-big | +big)" (logior #x-123456789abcdef #xfedcba987654321fedcba987654321fedcba)
      #x-20002488010145)
(test-equal "logior (-fix | -fix)" (logior #x-aa55 #x-6666)
      #x-2245)
(test-equal "logior (-fix | -big)" (logior #x-aa55 #x-6666666666)
      #x-2245)
(test-equal "logior (-big | -fix)" (logior #x-aa55aa55aa #x-6666)
      #x-4422)
(test-equal "logior (-big | -big)" (logior #x-aa55aa55aa #x-6666666666)
      #x-2244224422)
(test-equal "logior (-big | -big)" (logior #x-123456789abcdef #x-fedcba987654321fedcba987654321fedcba)
      #x-103454301aacca9)

(test-equal "logtest" (logtest #xfeedbabe #x10000000)
      #t)
(test-equal "logtest" (logtest #xfeedbabe #x01100101)
      #f)

#|

;; TODO: We don't have these procedures (yet?). Should there be compat
;; versions at the top?
(let loop ((a 1)   ; 1, 10, 100, ...
           (b 1)   ; 1, 11, 111, ...
           (c 2)   ; 10, 101, 1001, ...
           (n 1))  ; counter
  (when (< n 69)
    (test-equal (format "logcount (positive, 100...) ~a" n) (logcount a) 1)
    (test-equal (format "logcount (positive, 111...) ~a" n) (logcount b) n)
    (test-equal (format "logcount (negative, 100...) ~a" n) (logcount (- a)) (- n 1))
    (test-equal (format "logcount (negative, 100..1) ~a" n) (logcount (- c)) 1)
    (loop (+ b 1) (+ b b 1) (+ b b 3) (+ n 1))))

(test-equal "logbit?" (map (lambda (i) (logbit? i #b10110)) '(0 1 2 3 4 5 6))
              '(#f #t #t #f #t #f #f))
(test-equal "logbit?" (map (lambda (i) (logbit? i #b-10110)) '(0 1 2 3 4 5 6))
              '(#f #t #f #t #f #t #t))

(test-equal "copy-bit" (copy-bit 4 #b11000110 #t)
      #b11010110)
(test-equal "copy-bit" (copy-bit 4 #b11000110 #f)
      #b11000110)
(test-equal "copy-bit" (copy-bit 6 #b11000110 #f)
      #b10000110)

(test-equal "bit-field" (bit-field #b1101101010 0 4)
      #b1010)
(test-equal "bit-field" (bit-field #b1101101010 4 9)
      #b10110)

(test-equal "copy-bit-field" (copy-bit-field #b1101101010 0 4 0)
      #b1101100000)
(test-equal "copy-bit-field" (copy-bit-field #b1101101010 0 4 -1)
      #b1101101111)
(test-equal "copy-bit-field" (copy-bit-field #b1101101010 5 16 -1)
      #b1111111111101010)
|#

(test-equal "integer-length" (integer-length #b10101010)
      8)
(test-equal "integer-length" (integer-length #b1111)
      4)

(test-end)

;;------------------------------------------------------------------
(test-begin "inexact arithmetics")

(test-equal "+. (0)" (+.) 0.0)
(test-equal "+. (1)" (+. 1) 1.0)
(test-equal "+. (1big)" (+. 100000000000000000000) 1.0e20)
(test-equal "+. (1rat)" (+. 3/2) 1.5)
(test-equal "+. (1cmp)" (+. 1+i) 1.0+i)
(test-equal "+. (2)" (+. 0 1) 1.0)
(test-equal "+. (2big)" (+. 1 100000000000000000000) 1.0e20)
(test-equal "+. (2rat)" (+. 1 1/2) 1.5)
(test-equal "+. (many)" (+. 1 2 3 4 5) 15.0)

(test-equal "-. (1)" (-. 1) -1.0)
(test-equal "-. (1big)" (-. 100000000000000000000) -1.0e20)
(test-equal "-. (1rat)" (-. 3/2) -1.5)
(test-equal "-. (1cmp)" (-. 1+i) -1.0-i)
(test-equal "-. (2)" (-. 0 1) -1.0)
(test-equal "-. (2big)" (-. 1 100000000000000000000) -1.0e20)
(test-equal "-. (2rat)" (-. 1 1/2) 0.5)
(test-equal "-. (many)" (-. 1 2 3 4 5) -13.0)

(test-equal "*. (0)" (*.) 1.0)
(test-equal "*. (1)" (*. 1) 1.0)
(test-equal "*. (1big)" (*. 100000000000000000000) 1.0e20)
(test-equal "*. (1rat)" (*. 3/2) 1.5)
(test-equal "*. (1cmp)" (*. 1+i) 1.0+i)
(test-equal "*. (2)"  (*. 0 1) 0.0)
(test-equal "*. (2big)" (*. 1 100000000000000000000) 1.0e20)
(test-equal "*. (2rat)" (*. 1 1/2) 0.5)
(test-equal "*. (many)" (*. 1 2 3 4 5) 120.0)

(test-equal "/. (1)" (/. 1) 1.0)
(test-equal "/. (1big)" (/. 100000000000000000000) 1.0e-20)
(test-equal "/. (1rat)" (/. 3/2) 0.6666666666666666)
(test-equal "/. (1cmp)" (/. 1+i) 0.5-0.5i)
(test-equal "/. (2)"  (/. 0 1) 0.0)
(test-equal "/. (2big)" (/. 1 100000000000000000000) 1.0e-20)
(test-equal "/. (2rat)" (/. 1 1/2) 2.0)
(test-equal "/. (many)" (/. 1 2 5) 0.1)

(test-end)

;;------------------------------------------------------------------
(test-begin "sqrt")

;; R6RS and R7RS
(define (integer-sqrt-tester k)
  (test-equal (format "exact-integer-sqrt ~a" k) (receive (s r) (exact-integer-sqrt k)
           (list (= k (+ (* s s) r))
                 (< k (* (+ s 1) (+ s 1)))))
         '(#t #t)))

(integer-sqrt-tester 0)
(integer-sqrt-tester 1)
(integer-sqrt-tester 2)
(integer-sqrt-tester 3)
(integer-sqrt-tester 4)
(integer-sqrt-tester 10)
(integer-sqrt-tester (expt 2 32))
(integer-sqrt-tester (- (expt 2 53) 1))
(integer-sqrt-tester (expt 2 53))
(integer-sqrt-tester (+ (expt 2 53) 1))
(integer-sqrt-tester 9999999999999999999999999999999999999999999999999999)
(integer-sqrt-tester (+ (expt 10 400) 3141592653589)) ; double range overflow

(test-error "exact-integer-sqrt -1" (exact-integer-sqrt -1))
(test-error "exact-integer-sqrt 1.0" (exact-integer-sqrt 1.0))
(test-error "exact-integer-sqrt 1/4" (exact-integer-sqrt (read-from-string "1/4")))

(parameterize ((current-test-comparator eqv?))
 (test-equal "sqrt, exact" (sqrt 0) 0)
 (test-equal "sqrt, exact" (sqrt 16) 4)
 (test-equal "sqrt, inexact" (sqrt 16.0) 4.0)
 (test-equal "sqrt, inexact" (sqrt -16.0) (read-from-string "+4.0i"))
 (test-equal "sqrt, exact" (sqrt (read-from-string "1/16")) (read-from-string "1/4"))
 (test-equal "sqrt, inexact" (sqrt (exact->inexact (read-from-string "1/16"))) 0.25))

(test-end)

;;------------------------------------------------------------------
(test-begin "ffx optimization")

;; This code is provided by naoya_t to reproduce the FFX bug
;; existed until r6714.   The bug was that the ARGP words of
;; in-stack continuations were not scanned when flonum register
;; bank was cleared.  This code exhibits the case by putting
;; the result of (sqrt 2) as an unfinished argument, then calling
;; inverse-erf which caused flushing flonum regs (see "NG" line).

;; (use math.const)
(define-constant pi     3.141592653589793)


(let ()
  (define *epsilon* 1e-12)
  
  ;;
  ;; normal quantile function (probit function)
  ;;
  (define (probit p)
    (define (probit>0 p)
      (* (inverse-erf (- (* p 2) 1)) (sqrt 2))) ;; OK
    (if (< p 0)
      (- 1 (probit>0 (- p)))
      (probit>0 p) ))
  
  (define (probit p)
    (define (probit>0 p)
      (* (sqrt 2) (inverse-erf (- (* p 2) 1)))) ;; NG
    (if (< p 0)
      (- 1 (probit>0 (- p)))
      (probit>0 p) ))
  
  ;;
  ;; inverse error function (erf-1)
  ;;
  (define (inverse-erf z)
    (define (calc-next-ck k c)
      (let loop ((m 0) (sum 0) (ca c) (cz (reverse c)))
        (if (= m k) sum
            (loop (+ m 1)
                  (+ sum (/. (* (car ca) (car cz)) (+ m 1) (+ m m 1)))
                  (cdr ca) (cdr cz)))))
    (define (calc-cks k)
      (let loop ((i 0) (cks '(1)))
        (if (= i k) cks
            (loop (+ i 1) (cons (calc-next-ck (+ i 1) cks) cks)))))
    (define (calc-ck k) (car (calc-cks k)))
    
    (define (inverse-erf>0 z)
      (let1 r (* pi z z 1/4) ; (pi*z^2)/4
        (let loop ((k 0) (cks '(1)) (sum 0) (a 1))
          (let1 delta (* a (/ (car cks) (+ k k 1)))
            (if (< delta (* sum *epsilon*))
              (* 1/2 z (sqrt pi) sum)
              (loop (+ k 1)
                    (cons (calc-next-ck (+ k 1) cks) cks)
                    (+ sum delta)
                    (* a r)))))))
    
    (cond [(< z 0) (- (inverse-erf>0 (- z)))]
          [(= z 0) 0]
          [else (inverse-erf>0 z)]) )

  (define ~= (lambda (x y) (< (abs (- x y)) 1e-7)))
  ;;
  ;; TEST
  ;;
  (parameterize ((current-test-comparator ~=))
    (test-equal "probit(0.025)" (probit 0.025) -1.959964)
    (test-equal "probit(0.975)" (probit 0.975) 1.959964))
  )

(test-end)

(test-exit)
