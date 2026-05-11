;;;
;;; Numerical syntax "torture test"
;;;
;;; This tries to test a lot of edge cases in Scheme's numerical syntax.
;;;
;;; Output is written so that if you run it through "grep ERROR" it will
;;; output nothing (and exit status will be nonzero) if there are no errors.
;;; If you run it through "tail -n 1" you will just get the total error summary.
;;;
;;; This code assumes that string->number accepts numbers with embedded radix
;;; specifiers (R5RS mentions that it's allowed to return #f in those cases).
;;; It also doesn't try to support Schemes which support *only* integers or
;;; *only* flonums (which is also allowed by R5RS).
;;;

;;;
;; The prelude below is messy but required to get everything working
;; with some of the major Schemes.
;;
;; Also note that to test with Gambit, it appears you first need to type in
;; (load "~~/lib/syntax-case") and then load this file, or use gsi's -:s switch
;;;

(import (chicken format)) ; Chicken w/ numbers
;(use-syntax (ice-9 syncase)) ; Guile

;; Set this to #f if the Scheme has no compnums at all, 'inexact if it only
;; supports inexact compnums or 'exact if it supports exact compnums.
;; (Gauche, Guile, SCM: inexact, Chicken w/o numbers: #f)
(define compnum-type 'exact)

;; Set this to #f if the Scheme has no fractional number support,
;; 'exact if it supports rational numbers and 'inexact if it converts fractions
;; to floating-point, inexact numbers
(define fraction-type 'exact)

;; Fix these if your Scheme doesn't allow division by zero
(define the-nan (/ 0.0 0.0))
(define pos-inf (/ 1.0 0.0))
(define neg-inf (/ -1.0 0.0))

; Scheme48, Racket, Gambit, SCM
;(define (nan? x) (and (number? x) (not (= x x))))

(define total-errors 0)

(define (check-string-against-values! str . possible-values)
  (let ((res (string->number str)))
    (let lp ((values possible-values))
      (if (null? values)
          (begin (display       "PARSE ERROR         ")
                 (write (cons str possible-values))
                 (display " => ") (write res) (newline)
                 (set! total-errors (+ total-errors 1)))
          (let ((value (car values)))
            (if (not (or (and (not (string? value)) (equal? res value))
                         (and res (nan? res) (or (and value (nan? value))))))
                (lp (cdr values))
                (let ((re-str (and res (number->string res))))
                  (let lp2 ((values possible-values))
                    (if (null? values)
                        (begin (display "SERIALIZATION ERROR ")
                               (write (cons str possible-values))
                               (display " => ") (write re-str) (newline)
                               (set! total-errors (+ total-errors 1)))
                        (let ((value (car values)))
                          (if (not (or (and res (string=? re-str str))
                                       (and (not res) (not value))
                                       (and res (string? value) (string=? re-str value))))
                              (lp2 (cdr values))
                              (begin (display "OK                  ")
                                     (write (cons str possible-values))
                                     (newline)))))))))))))

(define-syntax test-numbers
  (syntax-rules (compnums fractions)
    ((_ (compnums (types e1 ...) ...) rest ...)
     (begin
       (case compnum-type (types (test-numbers e1 ... "no-totals")) ...)
       (test-numbers rest ...)))
    ((_ (fractions (types e1 ...) ...) rest ...)
     (begin
       (case fraction-type (types (test-numbers e1 ... "no-totals")) ...)
       (test-numbers rest ...)))
    ((_ (str value ...) rest ...)
     (begin
       (check-string-against-values! str value ...)
       (test-numbers rest ...)))
    ((_ "no-totals") #f)
    ((_ x rest ...)
     (begin (newline) (display "-> ") (display x) (newline)
            (display "-----------------------------------------------------")
            (newline)
            (test-numbers rest ...)))
    ((_)
     (if (= 0 total-errors)
         (begin (newline)
                (display "-----> Everything OK, no errors!")
                (newline))
         (begin (newline)
                (display "-----> TOTAL ERRORS: ")
                (display total-errors)
                (newline)
		(exit 1))))))

(test-numbers
 "Simple integers"
 ("1" 1)
 ("+1" 1 "1")
 ("-1" (- 1))
 ("#i1" 1.0 "1.0" "1.")
 ("#I1" 1.0 "1.0" "1.")
 ("#i-1" (- 1.0) "-1.0" "-1.")
 ("123\x00456" #f) 
 ("-#i1" #f)
 ("+-1" #f)
 ("" #f)
 ("-" #f)
 ("+" #f)
 ("+-" #f)

 "Basic decimal notation"
 ("1.0" (exact->inexact 1) "1.")
 ("1." 1.0 "1.0" "1.")
 ("1.#" 1.0 1.5 "1.0" "1." "1.5")
 (".1" 0.1 "0.1" "100.0e-3")
 ("-.1" (- 0.1) "-0.1" "-100.0e-3")
 ;; Some Schemes don't allow negative zero. This is okay with the standard
 ("-.0" -0.0 "-0." "-0.0" "0.0" "0." ".0")
 ("-0." -0.0 "-.0" "-0.0" "0.0" "0." ".0")
 ("." #f)
 (".1." #f)
 ("..1" #f)
 ("1.." #f)
 ("#i1.0" 1.0 "1.0" "1.")
 ("#e1.0" 1 "1")
 ("#e-.0" 0 "0")
 ("#e-0." 0 "0")
 ("-#e.0" #f)

 "Decimal notation with padding"
 ("1#" 10.0 15.0 "10.0" "15.0" "10." "15.")
 ("#e1#" 10 15 "10" "15")
 ("#E1#" 10 15 "10" "15")
 ("#1" #f)
 ("#" #f)
 ("1#2" #f)
 ("1.#2" #f)
 (".#" #f)
 ("#.#" #f)
 ("#.1" #f)
 ("1#.2" #f)
 ("1#." 10.0 15.0 "10.0" "15.0" "10." "15.")

 "Decimal notation with suffix"
 ("1e2" 100.0 "100.0" "100.")
 ("1E2" 100.0 "100.0" "100.")
 ("1s2" 100.0 "100.0" "100.")
 ("1S2" 100.0 "100.0" "100.")
 ("1f2" 100.0 "100.0" "100.")
 ("1F2" 100.0 "100.0" "100.")
 ("1d2" 100.0 "100.0" "100.")
 ("1D2" 100.0 "100.0" "100.")
 ("1l2" 100.0 "100.0" "100.")
 ("1L2" 100.0 "100.0" "100.")
 ("1e2e3" #f)
 ("1e2s3" #f)
 ("1e2.0" #f)

 "Decimal notation with suffix and padding"
 ("1#e2" 1000.0 1500.0 "1000.0" "1500.0" "1000." "1500." "1.0e3" "15.0e2")
 ("1e2#" #f)

 "NaN, Inf"
 ("+nan.0" the-nan "+NaN.0")
 ("+NAN.0" the-nan "+nan.0" "+NaN.0")
 ("+nan.1" #f)
 ("+nan.01" #f)
 ("+inf.0" pos-inf "+Inf.0")
 ("+InF.0" pos-inf "+inf.0" "+Inf.0")
 ("-inf.0" neg-inf "-Inf.0")
 ("-iNF.0" neg-inf "-inf.0" "-Inf.0")
 ("+inf.01" #f)
 ("+inf.1" #f)
 ("-inf.01" #f)
 ("-inf.1" #f)
 ("+inf.0/1" #f)
 ("1/+inf.0" #f)
 ("+nan" #f)
 ("+inf" #f)
 ("-inf" #f)
 ("nan.0" #f)
 ("inf.0" #f)
 ;; Thanks to John Cowan for these
 ("#e+nan.0" #f)
 ("#e+inf.0" #f)
 ("#e-inf.0" #f)
 ("#i+nan.0" the-nan "+nan.0" "+NaN.0")
 ("#i+inf.0" pos-inf "+inf.0" "+Inf.0")
 ("#i-inf.0" neg-inf "-inf.0" "-Inf.0")

 "Fractions"
 (fractions
  ((exact)
   ("1/2" (/ 1 2))
   ("#e1/2" (/ 1 2) "1/2")
   ("10/2" 5 "5")
   ("-1/2" (- (/ 1 2)))
   ("10/0" #f)
   ("0/10" 0 "0")
   ("#e0/10" 0 "0")
   ("#e1#/2" 5 (/ 15 2) "5" "15/2")
   ("#e1/2#" (/ 1 20) "1/20")
   ("#i3/2" (/ 3.0 2.0) "1.5"))
  ((inexact)
   ("1/2" (/ 1 2) "0.5" ".5" "500.0e-3")
   ("0/10" 0.0 "0.0")
   ("10/2" 5.0 "5.0" "5.")
   ;; Unsure what "#e1/2" is supposed to do in Scheme w/o exact fractions
   ("#i10/2" 5.0 "5.0" "5.")
   ("-1/2" (- (/ 1 2)) "-0.5" "-.5" "-500.0e-3")))
 (fractions
  ((inexact exact)
   ("#i1/0" pos-inf "+inf.0" "+Inf.0")
   ("#i-1/0" neg-inf "-inf.0" "-Inf.0")
   ("#i0/0" the-nan "+nan.0" "+NaN.0")
   ;; This _could_ be valid in some Schemes (but isn't as pretty)
   ;("#i1/0" #f)
   ;("#i-1/0" #f)
   ;("#i0/0" #f)
   
   ("1/-2" #f)
   ("1.0/2" #f)
   ("1/2.0" #f)
   ("1/2e2" #f)
   ("1/2e2" #f)
   ("1#/2" 5.0 7.5 "5.0" "5." "7.5")
   ("1/2#" 0.05 "0.05" ".05" "50.0e-3" "5.e-002")
   ("1#/#" #f)
   ("1/" #f)
   ("1/+" #f)
   ("+/1" #f)
   ("/1" #f)
   ("/" #f)))
 
 "Basic complex numbers (rectangular notation)"
 (compnums
  ((exact)
   ("1+2i" (make-rectangular 1 2))
   ("1+2I" (make-rectangular 1 2) "1+2i")
   ("1-2i" (make-rectangular 1 -2))
   ("-1+2i" (make-rectangular -1 2))
   ("-1-2i" (make-rectangular -1 -2))
   ("+i" (make-rectangular 0 1) "+1i" "0+i" "0+1i")
   ("0+i" (make-rectangular 0 1) "+i" "+1i" "0+1i")
   ("0+1i" (make-rectangular 0 1) "+i" "+1i" "0+i")
   ("-i" (make-rectangular 0 -1) "-1i" "0-i" "0-1i")
   ("0-i" (make-rectangular 0 -1) "-i" "-1i" "0-1i")
   ("0-1i" (make-rectangular 0 -1) "-i" "-1i" "0-i")
   ("+2i" (make-rectangular 0 2) "0+2i")
   ("-2i" (make-rectangular 0 -2) "-2i" "0-2i"))
  ((inexact)
   ("1+2i" (make-rectangular 1 2) "1.0+2.0i" "1.+2.i")
   ("1+2I" (make-rectangular 1 2) "1.0+2.0i" "1.+2.i")
   ("1-2i" (make-rectangular 1 -2) "1.0-2.0i" "1.-2.i")
   ("-1+2i" (make-rectangular -1 2) "-1.0+2.0i" "-1.+2.i")
   ("-1-2i" (make-rectangular -1 -2) "-1.0-2.0i" "-1.-2.i")
   ("+i" (make-rectangular 0 1) "+1.i" "+1.0i" "0.+1.i" "0.0+1.0i")
   ("0+i" (make-rectangular 0 1) "0+1i" "+1.i" "+1.0i" "0.+1.i" "0.0+1.0i")
   ("0+1i" (make-rectangular 0 1) "+1.i" "+1.0i" "0.+1.i" "0.0+1.0i")
   ("-i" (make-rectangular 0 -1) "-1.i" "-1.0i" "0.-1.i" "0.0-1.0i")
   ("0-i" (make-rectangular 0 -1) "-1.i" "-1.0i" "0.-1.i" "0.0-1.0i")
   ("0-1i" (make-rectangular 0 -1) "-1.i" "-1.0i" "0.-1.i" "0.0-1.0i")
   ("+2i" (make-rectangular 0 2) "+2.0i" "+2.i" "0.+2.i" "0.0+2.0i")
   ("-2i" (make-rectangular 0 -2) "-2.0i" "-2.i" "0.-2.i" "0.0-2.0i")))
 (compnums
  ((exact inexact)
   ("1#+1#i" (make-rectangular 10.0 10.0) (make-rectangular 15.0 15.0)
    "10.0+10.0i" "10.+10.i" "15.0+15.0i" "15.+15.i")))
 ("2i" #f)
 ("+-i" #f)
 ("i" #f)
 ("1+2i1" #f)
 ("1+2" #f)
 ("1#+#i" #f)

 (compnums
  ((exact inexact)
   "Decimal-notation complex numbers (rectangular notation)"
   ("1.0+2i" (make-rectangular 1.0 2) "1.0+2.0i" "1.0+2i" "1.+2i" "1.+2.i")
   ("1+2.0i" (make-rectangular 1 2.0) "1.0+2.0i" "1+2.0i" "1.+2.i" "1+2.i")
   ("1#.+1#.i" (make-rectangular 10.0 10.0) (make-rectangular 15.0 15.0)
    "10.0+10.0i" "10.+10.i" "15.0+15.0i" "15.+15.i")
   ("1e2+1.0i" (make-rectangular 100.0 1.0) "100.0+1.0i" "100.+1.i")
   ("1s2+1.0i" (make-rectangular 100.0 1.0) "100.0+1.0i" "100.+1.i")
   ("1.0+1e2i" (make-rectangular 1.0 100.0) "1.0+100.0i" "1.+100.i")
   ("1.0+1s2i" (make-rectangular 1.0 100.0) "1.0+100.0i" "1.+100.i")
   ("1#e2+1.0i" (make-rectangular 1000.0 1.0) (make-rectangular 1500.0 1.0)
    "1000.0+1.0i" "1000.+1.i" "1500.0+1.0i" "1500.+1.i" "1.0e3+1.0i" "15.0e2+1.0i")
   ("1.0+1#e2i" (make-rectangular 1.0 1000.0) (make-rectangular 1.0 1500.0)
    "1.0+1000.0i" "1.+1000.i" "1.0+1500.0i" "1.+1500.i" "1.0+1.0e3i" "1.0+15.0e2i")
   (".i" #f)
   ("+.i" #f)
   (".+i" #f)))

 (compnums
  ((exact)
   "Fractional complex numbers (rectangular notation)"
   ("1/2+3/4i" (make-rectangular (/ 1 2) (/ 3 4))))
  ((inexact)
   "Fractional complex numbers (rectangular notation)"
   ("1/2+3/4i" (make-rectangular (/ 1 2) (/ 3 4)) "0.5+0.75i" ".5+.75i" "500.0e-3+750.0e-3i")))

 (compnums
  ((exact inexact)
   "Mixed fractional/decimal notation complex numbers (rectangular notation)"
   ("1#/2+3/4i" (make-rectangular 5.0 (/ 3 4)) (make-rectangular 7.5 (/ 3 4))
    "5.0+0.75i" "5.+.75i" "7.5+0.75i" "5.0+3/4i" "5.+3/4i" "7.5+3/4i" "5.0+750.0e-3i")
   ("0.5+3/4i" (make-rectangular 0.5 (/ 3 4))
    "0.5+0.75i" ".5+.75i" "0.5+3/4i" ".5+3/4i" "500.0e-3+750.0e-3i")
   ("1.5+1#/4i" (make-rectangular 1.5 2.5) (make-rectangular 1.5 3.75)
    "1.5+2.5i" "1.5+3.75i")
   ("0.5+1/#i" #f)
   ("0.5+1/1#2i" #f)
   ("1/#+0.5i" #f)
   ("1/1#2+0.5i" #f)

   "Mixed notation with infinity (might fail on mixed exactness compnums)"
   ;; This is a nasty one. Switch to inexact *after* reading the first number.
   ;; Note that it's perfectly acceptable for a scheme with *mixed* exactness
   ;; in complex values to return #f here.  TODO: How to parameterize this, we
   ;; *really* want to test that single-exactness compnums systems accept this.
   ("1/0+1.2i" (make-rectangular pos-inf 1.2) "+inf.0+1.2i" "+Inf.0+1.2i")
   ;; Less nasty, most get this right.  Same caveat as above re: mixed exactness
   ("1.2+1/0i" (make-rectangular 1.2 pos-inf) "1.2+inf.0i" "1.2+Inf.0")))

 (compnums
  ((exact inexact)
   "Complex NaN, Inf (rectangular notation)"
   ("+nan.0+nan.0i" (make-rectangular the-nan the-nan) "+NaN.0+NaN.0i")
   ("+inf.0+inf.0i" (make-rectangular pos-inf pos-inf) "+Inf.0+Inf.0i")
   ("-inf.0+inf.0i" (make-rectangular neg-inf pos-inf) "-Inf.0+Inf.0i")
   ("-inf.0-inf.0i" (make-rectangular neg-inf neg-inf) "-Inf.0-Inf.0i")
   ("+inf.0-inf.0i" (make-rectangular pos-inf neg-inf) "+Inf.0-Inf.0i")
 
   "Complex numbers (polar notation)"
   ;; TODO: Add some here. The problem is the representation
   ;;       is hard to nail down when echoed back as rectangular
   ;;       since they're floating point with many digits, and depend
   ;;       on the precision of PI used internally.
   ("1@2i" #f)
   ("0.5@1/#" #f)
   ("0.5@1/1#2" #f)
   ("1/#@0.5" #f)
   ("1/1#2@0.5" #f)
   ("1@" #f)
   ("1#@#" #f)
   ("1/@" #f)
   ("@/1" #f)
   ("@1" #f)
   ("1@+" #f)
   ("+@1" #f)
   ("@" #f)))

 "Base prefixes"
 ("#x11" 17 "17")
 ("#X11" 17 "17")
 ("#d11" 11 "11")
 ("#D11" 11 "11")
 ("#o11" 9 "9")
 ("#O11" 9 "9")
 ("#b11" 3 "3")
 ("#B11" 3 "3")
 ("#da1" #f)
 ("#o8" #f)
 ("#b2" #f)
 ("#o7" 7 "7")
 ("#xa" 10 "10")
 ("#xA" 10 "10")
 ("#xf" 15 "15")
 ("#xg" #f)
 ("#x-10" -16 "-16")
 ("#d-10" -10 "-10")
 ("#o-10" -8 "-8")
 ("#b-10" -2 "-2")
 ("-#x10" #f)
 ("-#d10" #f)
 ("-#o10" #f)
 ("-#b10" #f)
 ("#x-" #f)
 ("#x" #f)
 ("#d" #f)
 ("#d-" #f)
 ("#d+" #f)
 ("#o" #f)
 ("#o-" #f)
 ("#b" #f)
 ("#b-" #f)
 ("#e" #f)
 ("#e-" #f)
 ("#i" #f)
 ("#i-" #f)

 "Combination of prefixes"
 ("#x#x11" #f)
 ("#x#b11" #f)
 ("#b#o11" #f)
 ("#e#x10" 16 "16")
 ("#i#x10" 16.0 "16.0" "16.")
 ("#e#e10" #f)
 ("#e#e#x10" #f)
 ("#E#e#X10" #f)
 ("#i#e#x10" #f)
 ("#e#x#e10" #f)
 ("#x#x#e10" #f)
 ("#x#e#x10" #f)

 "Base prefixes with padding"
 ("#x1#0" #f)
 ("#d1#0" #f)
 ("#o1#0" #f)
 ("#b1#0" #f)
 ("#x1#" 16.0 24.0 "16.0" "24.0" "16." "24.")
 ("#d1#" 10.0 15.0 "10.0" "15.0" "10." "15.")
 ("#o1#" 8.0 12.0 "8.0" "12.0" "8." "12.")
 ("#b1#" 2.0 3.0 "2.0" "3.0" "2." "3.")

 "(Attempted) decimal notation with base prefixes"
 ("#x1.0" #f)
 ("#d1.0" 1.0 "1.0" "1.")
 ("#o1.0" #f)
 ("#b1.0" #f)
 ("#x1.#" #f)
 ("#d1.#" 1.0 1.5 "1.0" "1.5" "1.")
 ("#o1.#" #f)
 ("#b1.#" #f)
 ("#x1." #f)
 ("#d1." 1.0 "1.0" "1.")
 ("#o1." #f)
 ("#b1." #f)
 ("#x.1" #f)
 ("#d.1" 0.1 "0.1" ".1" "100.0e-3")
 ("#o.1" #f)
 ("#b.1" #f)
 ("#x1e2" 482 "482")
 ("#d1e2" 100.0 "100.0" "100.")
 ("#o1e2" #f)
 ("#b1e2" #f)

 "Fractions with prefixes"
 (fractions
  ((inexact)
   ("#x10/2" 8.0 "8.0" "8.")
   ("#x11/2" 8.5 "8.5")
   ("#d11/2" 5.5 "5.5")
   ("#o11/2" 4.5 "4.5")
   ("#b11/10" 1.5 "1.5"))
  ((exact)
   ("#x10/2" 8 "8")
   ("#x11/2" (/ 17 2) "17/2")
   ("#d11/2" (/ 11 2) "11/2")
   ("#o11/2" (/ 9 2) "9/2")
   ("#b11/10" (/ 3 2) "3/2")))
 (fractions
  ((inexact exact)
   ("#b11/2" #f)
   ("#x10/#o10" #f)
   ("10/#o10" #f)
   ("#x1#/2" 8.0 12.0 "8.0" "8." "12.0" "12.")
   ("#d1#/2" 5.0 7.5 "5.0" "5." "7.5")
   ("#o1#/2" 4.0 6.0 "4.0" "4." "6.0" "6.")
   ("#b1#/2" #f)
   ("#b1#/10" 1.0 1.5 "1.0" "1." "1.5")))

 (compnums
  ((exact inexact)
   "Complex numbers with prefixes"
   ("#x1#+1#i" (make-rectangular 16.0 16.0) (make-rectangular 24.0 24.0)
    "16.0+16.0i" "16.+16.i" "24.0+24.0i" "24.+24.i")
   ("#x1.0+1.0i" #f)
   ("#d1.0+1.0i" (make-rectangular 1.0 1.0) "1.0+1.0i" "1.+1.i")
   ("#o1.0+1.0i" #f)
   ("#b1.0+1.0i" #f)
   ("#x10+#o10i" #f)
   ("10+#o10i" #f)
   ("#x1@#x1" #f)
   ("1@#x1" #f)))
 (compnums
  ((exact)
   ("#x10+11i" (make-rectangular 16 17) "16+17i")
   ("#d10+11i" (make-rectangular 10 11) "10+11i")
   ("#o10+11i" (make-rectangular 8 9) "8+9i")
   ("#b10+11i" (make-rectangular 2 3) "2+3i")
   ("#e1.0+1.0i" (make-rectangular 1 1) "1+1i" "1+i")
   ("#i1.0+1.0i" (make-rectangular 1.0 1.0) "1.0+1.0i" "1.+1.i"))
  ((inexact)
   ("#x10+11i" (make-rectangular 16 17) "16.0+17.0i" "16.+17.i")
   ("#d10+11i" (make-rectangular 10 11) "10.0+11.0i" "10.+11.i")
   ("#o10+11i" (make-rectangular 8 9) "8.0+9.0i" "8.+9.i")
   ("#b10+11i" (make-rectangular 2 3) "2.0+3.0i" "2.+3.i")))

 )

;; #1272 - Bases not in [2,36] throw errors.
(let ((check-base (lambda (b)
                    (string->number "123" b)
                    (error "No error on invalid base" b))))
  (condition-case (check-base 1)  ((exn type) 'ok))
  (condition-case (check-base 37) ((exn type) 'ok)))

;; #1627 - Even though R7RS Scheme allows not distinguishing negative
;; zero (as in the test above), we do.
(assert (string=? "-0.0" (number->string -0.0)))
(assert (string=? "0.0" (number->string +0.0)))
(assert (eqv? -0.0 (string->number "-0.0")))
(assert (eqv? 0.0 (string->number "+0.0")))
(assert (eqv? 0.0 (string->number "0.0")))
(assert (eqv? -0.0 (string->number "-0e1")))
(assert (eqv? 0.0 (string->number "0e-1")))
