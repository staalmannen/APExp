;;;; library-tests.scm

(import chicken.blob chicken.bitwise chicken.fixnum chicken.flonum
	chicken.keyword chicken.port chicken.condition)

(define-syntax assert-fail
  (syntax-rules ()
    ((_ exp)
     (assert (handle-exceptions ex #t exp #f)))))

(define (list-tabulate n proc)
  (let loop ((i 0))
    (if (fx>= i n)
	'()
	(cons (proc i) (loop (fx+ i 1))))))

(define (every pred lst)
  (let loop ((lst lst))
    (cond ((null? lst))
	  ((not (pred (car lst))) #f)
	  (else (loop (cdr lst))))))

;; numbers

(assert (not (not 3)))
(assert (= -4.0 (round -4.3)))
(assert (= -4.0 (round -4.5)))          ; R5RS
(assert (= 4.0 (round 3.5)))
(assert (= 4.0 (round 4.5)))            ; R5RS
(assert (= 4 (round (string->number "7/2"))))
(assert (= 7 (round 7)))
(assert (zero? (round -0.5))) 		; is actually -0.0
(assert (zero? (round -0.3)))
(assert (= -1 (round -0.6)))
(assert (zero? (round 0.5)))
(assert (zero? (round 0.3)))
(assert (= 1.0 (round 0.6)))
(assert (rational? 1))
(assert (finite? 1))
(assert-fail (finite? 'foo))
(assert (rational? 1.0))
(assert (finite? 1.0))
(assert (not (rational? +inf.0)))
(assert (not (finite? +inf.0)))
(assert (not (rational? -inf.0)))
(assert (not (finite? -inf.0)))
(assert (not (rational? +nan.0)))
(assert (not (finite? +nan.0)))
(assert (not (rational? 'foo)))
(assert (not (rational? "foo")))
(assert (integer? 2))
(assert (integer? 2.0))
(assert (not (integer? 1.1)))
(assert (not (integer? +inf.0)))
(assert (not (integer? -inf.0)))
(assert (not (integer? +nan.0)))
(assert (not (integer? 'foo)))
(assert (not (integer? "foo")))
; XXX number missing

;; Negative vs positive zero (see #1627)
(assert (not (eqv? 0.0 -0.0)))
(assert (not (equal? 0.0 -0.0)))
(assert (= 0.0 -0.0))

(assert (not (positive? 0.0)))
(assert (not (negative? 0.0)))
(assert (zero? 0.0))

(assert (not (positive? -0.0)))
(assert (not (negative? -0.0)))
(assert (zero? -0.0))

;; Exactness
(assert (exact? 1))
(assert (not (exact? 1.0)))
(assert (not (exact? 1.1)))
(assert-fail (exact? 'foo))
(assert (not (inexact? 1)))
(assert (inexact? 1.0))
(assert (inexact? 1.1))
(assert-fail (inexact? 'foo))

;; Division by inexact zero used to fail, but now it returns +inf.0
(assert-fail (/ 1 1 0))
(assert (eqv? +inf.0 (/ 1 1 0.0)))
(assert (eqv? +inf.0 (/ 1 0.0)))
(assert-fail (/ 1 0))
(assert-fail (/ 0))
(assert (eqv? +inf.0 (/ 0.0)))

(assert (fixnum? (/ 1)))

(assert (= -3 (- 3)))
(assert (= 3 (- -3)))
(assert (= 2 (- 5 3)))
(assert (> 1 (/ 3)))
(assert (> 1 (/ 3.0)))
(assert (= 2 (/ 8 4)))
(assert (zero? (+)))
(assert (= 1 (*)))

(assert (= 2.5 (/ 5 2)))

;; Use equal? instead of = to check equality and exactness in one go
(assert (equal? 0 (numerator 0)))
(assert (equal? 1 (denominator 0)))
(assert (equal? 3 (numerator 3)))
(assert (equal? 1 (denominator 3)))
(assert (equal? -3 (numerator -3)))
(assert (equal? 1 (denominator -3)))
(assert (equal? 1.0 (numerator 0.5)))
(assert (equal? 2.0 (denominator 0.5)))
(assert (equal? 5.0 (numerator 1.25)))
(assert (equal? 4.0 (denominator 1.25)))
(assert (equal? -5.0 (numerator -1.25)))

;;; A few denormalised numbers, cribbed from NetBSD ATF tests for ldexp():
;; On some machines/OSes these tests fail due to missing hardware support
;; and sometimes due to broken libc/libm support, so we have disabled them.
;(assert (equal? 1.0 (numerator 1.1125369292536006915451e-308)))
;(assert (equal? +inf.0 (denominator 1.1125369292536006915451e-308)))
;(assert (equal? -1.0 (numerator -5.5626846462680034577256e-309)))
;(assert (equal? +inf.0 (denominator -5.5626846462680034577256e-309)))
;(assert (equal? 1.0 (numerator 4.9406564584124654417657e-324)))
;(assert (equal? +inf.0 (denominator 4.9406564584124654417657e-324)))

(assert (equal? 4.0 (denominator -1.25)))
(assert (equal? 1e10 (numerator 1e10)))
(assert (equal? 1.0 (denominator 1e10)))
(assert-fail (numerator +inf.0))
(assert-fail (numerator +nan.0))
(assert-fail (denominator +inf.0))
(assert-fail (denominator +nan.0))

(assert (even? 2))
(assert (even? 2.0))
(assert (even? 0))
(assert (even? 0.0))
(assert (not (even? 3)))
(assert (not (even? 3.0)))
(assert (odd? 1))
(assert (odd? 1.0))
(assert (not (odd? 0)))
(assert (not (odd? 0.0)))
(assert (not (odd? 2)))
(assert (not (odd? 2.0)))
(assert-fail (even? 1.2))
(assert-fail (odd? 1.2))
(assert-fail (even? +inf.0))
(assert-fail (odd? +inf.0))
(assert-fail (even? +nan.0))
(assert-fail (odd? +nan.0))
(assert-fail (even? 'x))
(assert-fail (odd? 'x))

(assert (= 60 (arithmetic-shift 15 2)))
(assert (= 3 (arithmetic-shift 15 -2)))
(assert (= -60 (arithmetic-shift -15 2)))
(assert (= -4 (arithmetic-shift -15 -2))) ; 2's complement
(assert-fail (arithmetic-shift 0.1 2))
;; XXX Do the following two need to fail?  Might as well use the integral value
(assert-fail (arithmetic-shift #xf 2.0))
(assert-fail (arithmetic-shift #xf -2.0))
(assert-fail (arithmetic-shift #xf 2.1))
(assert-fail (arithmetic-shift #xf -2.1))
(assert-fail (arithmetic-shift +inf.0 2))
(assert-fail (arithmetic-shift +nan.0 2))

(assert (= 0 (gcd)))
(assert (= 6 (gcd 6)))
(assert (= 2 (gcd 6 8)))
(assert (= 1 (gcd 6 8 5)))
(assert (= 1 (gcd 6 -8 5)))
(assert (= 2.0 (gcd 6.0 8.0)))
(assert-fail (gcd 6.1 8.0))
(assert-fail (gcd 6.0 8.1))
(assert-fail (gcd +inf.0))
(assert-fail (gcd +nan.0))
(assert-fail (gcd 6.0 +inf.0))
(assert-fail (gcd +inf.0 6.0))
(assert-fail (gcd +nan.0 6.0))
(assert-fail (gcd 6.0 +nan.0))

(assert (= 1 (lcm)))
(assert (= 6 (lcm 6)))
(assert (= 24 (lcm 6 8)))
(assert (= 120 (lcm 6 8 5)))
(assert (= 24.0 (lcm 6.0 8.0)))
(assert-fail (lcm +inf.0))
(assert-fail (lcm +nan.0))
(assert-fail (lcm 6.1 8.0))
(assert-fail (lcm 6.0 8.1))
(assert-fail (lcm 6.0 +inf.0))
(assert-fail (lcm +inf.0 6.0))
(assert-fail (lcm +nan.0 6.0))
(assert-fail (lcm 6.0 +nan.0))

(assert (= 3 (quotient 13 4)))
(assert (= 3.0 (quotient 13.0 4.0)))
(assert-fail (quotient 13.0 4.1))
(assert-fail (quotient 13.2 4.0))
(assert-fail (quotient +inf.0 4.0))
(assert-fail (quotient +nan.0 4.0))
(assert-fail (quotient 4.0 +inf.0))
(assert-fail (quotient 4.0 +nan.0))

(assert (= 1 (remainder 13 4)))
(assert (= 1.0 (remainder 13.0 4.0)))
(assert-fail (remainder 13.0 4.1))
(assert-fail (remainder 13.2 4.0))
(assert-fail (remainder +inf.0 4.0))
(assert-fail (remainder +nan.0 4.0))
(assert-fail (remainder 4.0 +inf.0))
(assert-fail (remainder 4.0 +nan.0))

(assert (= 1 (modulo 13 4)))
(assert (= 1.0 (modulo 13.0 4.0)))
(assert-fail (modulo 13.0 4.1))
(assert-fail (modulo 13.2 4.0))
(assert-fail (modulo +inf.0 4.0))
(assert-fail (modulo +nan.0 4.0))
(assert-fail (modulo 4.0 +inf.0))
(assert-fail (modulo 4.0 +nan.0))

(assert-fail (min 'x))
(assert-fail (max 'x))
(assert (eq? 1 (min 1 2)))
(assert (eq? 1 (min 2 1)))
(assert (eq? 2 (max 1 2)))
(assert (eq? 2 (max 2 1)))
;; must be flonum
(assert (fp= 1.0 (min 1 2.0)))           
(assert (fp= 1.0 (min 2.0 1)))
(assert (fp= 2.0 (max 2 1.0)))           
(assert (fp= 2.0 (max 1.0 2)))

;; number->string conversion

(for-each
 (lambda (x)
   (let ((number (car x))
	 (radix (cadr x)))
     (assert (eqv? number (string->number (number->string number radix) radix)))))
 '((123 10)
   (123 2)
   (123 8)
   (-123 10)
   (-123 2)
   (-123 8)
   (99.2 10)
   (-99.2 10)))

;; by Christian Kellermann
(assert 
 (equal?
  (map (lambda (n) (number->string 32 n)) (list-tabulate 15 (cut + 2 <>)))
  '("100000" "1012" "200" "112" "52" "44" "40" "35" "32" "2a" "28" "26" "24" "22" "20")))

;; #1422
(assert (equal? (map + '(1 2 3) '(1 2)) '(2 4)))
(assert (equal? (map + '(1 2) '(1 2 3)) '(2 4)))
(let ((result '()))
  (for-each (lambda (x y) (set! result (cons (+ x y) result)))
            '(1 2) '(1 2 3))
  (assert (equal? result '(4 2))))
(let ((result '()))
  (for-each (lambda (x y) (set! result (cons (+ x y) result)))
            '(1 2 3) '(1 2))
  (assert (equal? result '(4 2))))

;; string->number conversion

(assert (= 255 (string->number "ff" 16)))
(assert (not (string->number "fg" 16)))


;; fp-math

(define (inexact= a b)
  (< (abs (- 1 (abs (/ a b)))) 1e-10))

(assert (inexact= (sin 42.0) (fpsin 42.0)))
(assert (inexact= (cos 42.0) (fpcos 42.0)))
(assert (inexact= (tan 42.0) (fptan 42.0)))
(assert (inexact= (asin 0.5) (fpasin 0.5)))
(assert (inexact= (acos 0.5) (fpacos 0.5)))
(assert (inexact= (atan 0.5) (fpatan 0.5)))
(assert (inexact= (atan 42.0 1.2) (fpatan2 42.0 1.2)))
(assert (inexact= (atan 42.0 1) (fpatan2 42.0 1.0)))
(assert (inexact= (atan 42 1.0) (fpatan2 42.0 1.0)))
(assert (inexact= (exp 42.0) (fpexp 42.0)))
(assert (inexact= (log 42.0) (fplog 42.0)))
(assert (inexact= (expt 42.0 3.5) (fpexpt 42.0 3.5)))
(assert (inexact= (sqrt 42.0) (fpsqrt 42.0)))
(assert (inexact= 43.0 (fpround 42.5)))
(assert (inexact= -43.0 (fpround -42.5)))
(assert (inexact= 42.0 (fpround 42.2)))
(assert (inexact= 42.0 (fptruncate 42.5)))
(assert (inexact= -42.0 (fptruncate -42.5)))
(assert (inexact= 42.0 (fpfloor 42.2)))
(assert (inexact= -43.0 (fpfloor -42.5)))
(assert (inexact= 43.0 (fpceiling 42.5)))
(assert (inexact= -42.0 (fpceiling -42.2)))
(assert (not (fpinteger? 2.3)))
(assert (fpinteger? 1.0))
(assert (inexact= 7.0 (fp*+ 2.0 3.0 1.0)))
(assert (inexact= 53.0 (fp*+ 10.0 5.0 3.0)))

;;; Tests contributed by Christian Himpe:

;; original tests:
(assert (inexact= 7.0 (fp*+ 2.0 3.0 1.0)))
(assert (inexact= 53.0 (fp*+ 10.0 5.0 3.0)))

;; my new tests:
(assert (inexact= 5.0 (fp*+ 1.0 2.0 3.0)))
(assert (inexact= 2.0 (fp*+ 1.0 2.0 0.0)))
(assert (inexact= 3.0 (fp*+ 1.0 0.0 3.0)))
(assert (inexact= 3.0 (fp*+ 0.0 2.0 3.0)))
(assert (inexact= 3.0 (fp*+ 0.0 0.0 3.0)))
(assert (inexact= -1.0 (fp*+ 2.0 0.5 -2.0)))
(assert (zero? (fp*+ 0.0 0.0 0.0)))
(assert (zero? (fp*+ -1.0 1.0 1.0)))
(assert (zero? (fp*+ 1.0 -1.0 1.0)))
(assert (zero? (fp*+ -1.0 -1.0 -1.0)))

(assert (infinite? (fp*+ +inf.0 1.0 1.0)))
(assert (infinite? (fp*+ 1.0 +inf.0 1.0)))
(assert (infinite? (fp*+ 1.0 1.0 +inf.0)))
(assert (infinite? (fp*+ +inf.0 1.0 +inf.0)))
(assert (nan? (fp*+ -inf.0 1.0 +inf.0)))
(assert (nan? (fp*+ +nan.0 1.0 1.0)))
(assert (nan? (fp*+ 1.0 +nan.0 1.0)))
(assert (nan? (fp*+ 1.0 1.0 +nan.0)))
(assert (nan? (fp*+ 0.0 +inf.0 1.0)))
(assert (nan? (fp*+ -inf.0 0.0 1.0)))

;; Hyperbolic function tests

(assert (fp= (fpsinh -inf.0) -inf.0))
(assert (fp= (fpsinh 0.0) 0.0))
(assert (fp= (fpsinh +inf.0) +inf.0))

(assert (fp= (fpcosh -inf.0) +inf.0))
(assert (fp= (fpcosh 0.0) 1.0))
(assert (fp= (fpcosh +inf.0) +inf.0))

(assert (fp= (fptanh -inf.0) -1.0))
(assert (fp= (fptanh 0.0) 0.0))
(assert (fp= (fptanh +inf.0) 1.0))

(assert (fp= (fpasinh -inf.0) -inf.0))
(assert (fp= (fpasinh 0.0) 0.0))
(assert (fp= (fpasinh +inf.0) +inf.0))

(assert (fp= (fpacosh 1.0) 0.0))
(assert (fp= (fpacosh +inf.0) +inf.0))
(assert (nan? (fpacosh 0.0)))

(assert (fp= (fpatanh -1.0) -inf.0))
(assert (fp= (fpatanh 0.0) 0.0))
(assert (fp= (fpatanh 1.0) +inf.0))

;; string->symbol

;; by Jim Ursetto
(assert 
 (eq? '|3|
      (with-input-from-string
	  (with-output-to-string
	    (lambda ()
	      (write (string->symbol "3"))))
	read)))

;;; escaped symbol syntax

(assert (string=? "abc" (symbol->string '|abc|)))
(assert (string=? "abcdef" (symbol->string '|abc||def|)))
(assert (string=? "abcxyzdef" (symbol->string '|abc|xyz|def|)))
(assert (string=? "abc|def" (symbol->string '|abc\|def|)))
(assert (string=? "abc|def" (symbol->string '|abc\|def|)))
(assert (string=? "abc" (symbol->string 'abc)))
(assert (string=? "a c" (symbol->string 'a\ c)))
(assert (string=? "aBc" (symbol->string 'aBc)))

(parameterize ((case-sensitive #f))
  (assert (string=? "abc" (symbol->string (with-input-from-string "aBc" read))))
  (assert (string=? "aBc" (symbol->string (with-input-from-string "|aBc|" read))))
  (assert (string=? "aBc" (symbol->string (with-input-from-string "a\\Bc" read)))))

(parameterize ((symbol-escape #f))
  (assert (string=? "aBc" (symbol->string (with-input-from-string "aBc" read))))
  (assert-fail (with-input-from-string "|aBc|" read))
  (assert-fail (with-input-from-string "a|Bc" read)))
(parameterize ((symbol-escape #t))
  (assert (string=? "aBc" (symbol->string (with-input-from-string "aBc" read))))
  (assert (string=? "aBc" (symbol->string (with-input-from-string "|aBc|" read))))
  (assert (string=? "aB c" (symbol->string (with-input-from-string "|aB c|" read))))
  ;; The following is an extension/generalisation of r7RS
  (assert (string=? "aBc" (symbol->string (with-input-from-string "a|Bc|" read))))
  ;; "Unterminated string" (unterminated identifier?)
  (assert-fail (with-input-from-string "a|Bc" read)))

;;; Old style qualified low byte, see #1077

(assert (string=? "##foo#bar" (symbol->string '|##foo#bar|)))
(assert (string=? "##foo#bar" (symbol->string '##foo#bar)))
(assert (eq? '##foo#bar '|##foo#bar|))

(assert (string=? "|\\x0a|" (with-output-to-string (lambda () (write '|\n|)))))
;; #1576
(assert (string=? "|\\x00foo|" (with-output-to-string (lambda () (write '|\000foo|)))))
(assert (not (keyword? '|\000foo|)))
(assert (string=? "|###foo#bar|" (with-output-to-string (lambda () (write '|###foo#bar|)))))

;;; Paren synonyms

(parameterize ((parentheses-synonyms #f))
  (assert (eq? '() (with-input-from-string "()" read)))
  (assert-fail (with-input-from-string "[]" read))
  (assert-fail (with-input-from-string "{}" read)))
(parameterize ((parentheses-synonyms #t))
  (assert (eq? '() (with-input-from-string "()" read)))
  (assert (eq? '() (with-input-from-string "[]" read)))
  (assert (eq? '() (with-input-from-string "{}" read))))

;;; keywords

(parameterize ((keyword-style #:suffix))
  (assert (string=? "abc:" (symbol->string (with-input-from-string "|abc:|" read))))
  (assert (string=? "abc" (keyword->string (with-input-from-string "|abc|:" read)))) ; keyword
  (let ((kw (with-input-from-string "|foo bar|:" read))
	(sym1 (with-input-from-string "|foo:|" read))
	(sym2 (with-input-from-string "|:foo|" read)))

    (assert (symbol? sym1))
    (assert (not (keyword? sym1)))

    (assert (symbol? sym2))
    (assert (not (keyword? sym2)))

    (assert (keyword? kw))
    (assert (not (symbol? kw)))

    (assert (eq? kw (with-input-from-string "#:|foo bar|" read)))
    (assert (string=? "foo bar" (keyword->string kw)))
    (assert (string=? "foo:" (symbol->string sym1)))
    (assert (string=? ":foo" (symbol->string sym2)))

    (assert (string=? "foo bar:"
		      (with-output-to-string (lambda () (display kw)))))
    (assert (string=? "#:|foo bar|"
		      (with-output-to-string (lambda () (write kw)))))

    (assert (string=? "|foo:|"
		      (with-output-to-string (lambda () (write sym1)))))
    ;; Regardless of keyword style, symbols must be quoted to avoid
    ;; issues when reading it back with a different keyword style.
    (assert (string=? "|:foo|"
		      (with-output-to-string (lambda () (write sym2)))))))

(parameterize ((keyword-style #:prefix))
  (assert (string=? "abc" (keyword->string (with-input-from-string ":|abc|" read))))
  (assert (string=? ":abc" (symbol->string (with-input-from-string "|:abc|" read))))
  (let ((kw (with-input-from-string ":|foo bar|" read))
	(sym1 (with-input-from-string "|:foo|" read))
	(sym2 (with-input-from-string "|foo:|" read)))

    (assert (symbol? sym1))
    (assert (not (keyword? sym1)))

    (assert (symbol? sym2))
    (assert (not (keyword? sym2)))

    (assert (keyword? kw))
    (assert (not (symbol? kw)))

    (assert (eq? kw (with-input-from-string "#:|foo bar|" read)))
    (assert (string=? "foo bar" (keyword->string kw)))
    (assert (string=? ":foo" (symbol->string sym1)))
    (assert (string=? "foo:" (symbol->string sym2)))

    (assert (string=? ":foo bar"
		      (with-output-to-string (lambda () (display kw)))))
    (assert (string=? "#:|foo bar|"
		      (with-output-to-string (lambda () (write kw)))))

    (assert (string=? "|:foo|"
		      (with-output-to-string (lambda () (write sym1)))))
    ;; Regardless of keyword style, symbols must be quoted to avoid
    ;; issues when reading it back with a different keyword style.
    (assert (string=? "|foo:|"
		      (with-output-to-string (lambda () (write sym2)))))))

(parameterize ((keyword-style #:none))
  (let ((kw (with-input-from-string "#:|foo bar|" read))
	(sym1 (with-input-from-string "|:foo|" read))
	(sym2 (with-input-from-string "|foo:|" read)))

    (assert (symbol? sym1))
    (assert (not (keyword? sym1)))

    (assert (symbol? sym2))
    (assert (not (keyword? sym2)))

    (assert (keyword? kw))
    (assert (not (symbol? kw)))

    (assert (eq? kw (string->keyword "foo bar"))
    (assert (string=? "foo bar" (keyword->string kw)))
    (assert (string=? ":foo" (symbol->string sym1)))
    (assert (string=? "foo:" (symbol->string sym2)))

    (assert (string=? ":foo"
		      (with-output-to-string (lambda () (display kw)))))
    (assert (string=? "#:|foo bar|"
		      (with-output-to-string (lambda () (write kw)))))

    ;; Regardless of keyword style, symbols must be quoted to avoid
    ;; issues when reading it back with a different keyword style.
    (assert (string=? "|:foo|"
		      (with-output-to-string (lambda () (write sym1)))))
    (assert (string=? "|foo:|"
		      (with-output-to-string (lambda () (write sym2))))))))

(assert (eq? '|#:| (string->symbol "#:")))
(assert-fail (with-input-from-string "#:" read)) ; empty keyword
(assert (eq? '|#:| (with-input-from-string (with-output-to-string (cut write '|#:|)) read)))

(parameterize ((keyword-style #:suffix))
  (assert (keyword? (with-input-from-string "abc:" read)))
  (assert (keyword? (with-input-from-string "|abc|:" read)))
  (assert (keyword? (with-input-from-string "a|bc|d:" read)))
  (assert (not (keyword? (with-input-from-string "abc:||" read))))
  (assert (not (keyword? (with-input-from-string "abc\\:" read))))
  (assert (not (keyword? (with-input-from-string "abc|:|" read))))
  (assert (not (keyword? (with-input-from-string "|abc:|" read)))))

(parameterize ((keyword-style #:prefix))
  (assert (keyword? (with-input-from-string ":abc" read)))
  (assert (keyword? (with-input-from-string ":|abc|" read)))
  (assert (keyword? (with-input-from-string ":a|bc|d" read)))
  (assert (not (keyword? (with-input-from-string "||:abc" read))))
  (assert (not (keyword? (with-input-from-string "\\:abc" read))))
  (assert (not (keyword? (with-input-from-string "|:|abc" read))))
  (assert (not (keyword? (with-input-from-string "|:abc|" read)))))

(parameterize ((keyword-style #f))
  (assert (not (keyword? (with-input-from-string ":||" read))))
  (assert (not (keyword? (with-input-from-string "||:" read))))
  (assert (not (keyword? (with-input-from-string ":abc" read))))
  (assert (not (keyword? (with-input-from-string ":abc:" read))))
  (assert (not (keyword? (with-input-from-string "abc:" read)))))

(parameterize ((keyword-style #:suffix))
  (let ((colon-sym (with-input-from-string ":" read)))
    (assert (symbol? colon-sym))
    (assert (not (keyword? colon-sym)))
    (assert (string=? ":" (symbol->string colon-sym)))))

(parameterize ((keyword-style #:prefix))
  (let ((colon-sym (with-input-from-string ":" read)))
    (assert (symbol? colon-sym))
    (assert (not (keyword? colon-sym)))
    (assert (string=? ":" (symbol->string colon-sym)))))

;; The next two cases are a bit dubious, but we follow SRFI-88 (see
;; also #1625).
(parameterize ((keyword-style #:suffix))
  (let ((colon-sym (with-input-from-string ":||" read)))
    (assert (symbol? colon-sym))
    (assert (not (keyword? colon-sym)))
    (assert (string=? ":" (symbol->string colon-sym))))

  (let ((empty-kw (with-input-from-string "||:" read)))
    (assert (not (symbol? empty-kw)))
    (assert (keyword? empty-kw))
    (assert (string=? "" (keyword->string empty-kw)))))

(parameterize ((keyword-style #:prefix))
  (let ((empty-kw (with-input-from-string ":||" read)))
    (assert (not (symbol? empty-kw)))
    (assert (keyword? empty-kw))
    (assert (string=? "" (keyword->string empty-kw))))

  (let ((colon-sym (with-input-from-string "||:" read)))
    (assert (symbol? colon-sym))
    (assert (not (keyword? colon-sym)))
    (assert (string=? ":" (symbol->string colon-sym)))))

(assert-fail (with-input-from-string "#:" read))

(let ((empty-kw (with-input-from-string "#:||" read)))
  (assert (not (symbol? empty-kw)))
  (assert (keyword? empty-kw))
  (assert (string=? "" (keyword->string empty-kw))))

;; TODO: It should eventually be possible to distinguish these (#1077)
#;(let ((nul-sym (with-input-from-string "|\\x00|" read)))
  (assert (not (keyword? nul-sym)))
  (assert (string=? "\x00" (symbol->string nul-sym))))

(assert (keyword? (with-input-from-string "42:" read)))
(assert (keyword? (with-input-from-string ".:" read)))

(assert (equal? (cons 1 2) (with-input-from-string "(1 . 2)" read)))
(assert (every keyword? (with-input-from-string "(42: abc: .: #:: ::)" read)))

;; symbols and keywords are now distinct
(assert (not (symbol? #:foo)))
(assert (not (symbol? (string->keyword "foo"))))
(assert (not (keyword? 'foo)))
(assert (not (keyword? (string->symbol "foo"))))

;;; reading unterminated objects

(assert-fail (with-input-from-string "(" read))
(assert-fail (with-input-from-string "(1 . 2" read))
(assert-fail (with-input-from-string "|" read))
(assert-fail (with-input-from-string "\"" read))
(assert-fail (with-input-from-string "#|" read))
(assert-fail (with-input-from-string "#(" read))
(assert-fail (with-input-from-string "#${" read))
(assert-fail (with-input-from-string "\\" read))
(assert-fail (with-input-from-string "|\\" read))
(assert-fail (with-input-from-string "\"\\" read))

;;; here documents

(assert (string=? "" #<<A
A
))

(assert (string=? "foo" #<<A
foo
A
))

(assert (string=? "\nfoo\n" #<<A

foo

A
))

(assert (string=? "foo\nbar\nbaz" #<<A
foo
bar
baz
A
))

;;; setters

(define x '(a b c))
(define kar car)
(set! (kar (cdr x)) 99)
(assert (equal? '(a 99 c) x))
(define p (make-parameter 100))
(assert (= 100 (p)))
(set! (p) 1000)
(assert (= 1000 (p)))


;;; blob-literal syntax

(assert (equal? '#${a} '#${0a}))
(assert (equal? '#${ab cd} '#${abcd}))
(assert (equal? '#${ab c} '#${ab0c}))
(assert (equal? '#${abc} '#${ab0c}))
(assert (equal? '#${a b c} '#${0a0b0c}))

;; self-evaluating
(assert (equal? '#${a} #${a}))
(assert (equal? '#${abcd} #${abcd}))
(assert (equal? '#${abc} #${abc}))


;; #808: blobs and strings with embedded nul bytes should not be compared
;; with ASCIIZ string comparison functions
(assert (equal? '#${a b 0 c} '#${a b 0 c}))
(assert (blob=? '#${a b 0 c} '#${a b 0 c}))
(assert (equal=? "foo\x00a" "foo\x00a"))
(assert (string=? "foo\x00a" "foo\x00a"))
(assert (string-ci=? "foo\x00a" "foo\x00a"))
(assert (string-ci=? "foo\x00a" "foo\x00A"))
(assert (not (equal? '#${a b 0 c} '#${a b 0 d})))
(assert (not (blob=? '#${a b 0 c} '#${a b 0 d})))
(assert (not (equal=? "foo\x00a" "foo\x00b")))
(assert (not (string=? "foo\x00a" "foo\x00b")))
(assert (not (string-ci=? "foo\x00a" "foo\x00b")))
(assert (string<? "foo\x00a" "foo\x00b"))
(assert (string>? "foo\x00b" "foo\x00a"))
(assert (string-ci<? "foo\x00a" "foo\x00B"))
(assert (string-ci>? "foo\x00b" "foo\x00A"))

;; reported by Nils Holm (#1534)
;; https://groups.google.com/group/comp.lang.scheme/t/6b8be06b84b39a7
(assert (not (string-ci<=? "test" "tes")))
(assert (string-ci>=? "test" "tes"))


;;; getter-with-setter

(define foo
  (let ((m 2))
    (getter-with-setter
     (lambda (x) (* x m))
     (lambda (x) 
       (set! m x)))))

(assert (= 6 (foo 3)))
(set! (foo) 4)
(assert (= 20 (foo 5)))

(define bar
  (getter-with-setter
   foo
   (lambda (x)
     (+ x 99))))

(assert (= 12 (bar 3)))
(assert (= 100 (set! (bar) 1)))
(assert (= 12 (foo 3)))


;;; equal=?

(assert (not (equal=? 1 2)))
(assert (equal=? 1 1))
(assert (equal=? 1 1.0))
(assert (not (equal=? 1 1.2)))
(assert (equal=? 1.0 1))
(assert (equal=? '#(1) '#(1.0)))
(assert (not (equal=? 'a "a")))
(assert (equal=? "abc" "abc"))
(assert (equal=? '(1 2.0 3) '(1 2 3)))
(assert (equal=? '#(1 2.0 3) '#(1 2 3)))
(assert (equal=? '#(1 2 (3)) '#(1 2 (3))))
(assert (not (equal=? '#(1 2 (4)) '#(1 2 (3)))))
(assert (not (equal=? 123 '(123))))

;;; parameters

(define guard-called 0)

(define p
  (make-parameter 
   1
   (lambda (x)
     (set! guard-called (+ guard-called 1))
     x)))

(define k
  (parameterize ((p 2))
    (call/cc
     (lambda (k) 
       (assert (= 2 (p)))
       k))))

(and k (k #f))

(assert (= 2 guard-called))

;; Parameters are reset correctly (#1227, pointed out by Joo ChurlSoo)

(let ((a (make-parameter 1 number->string))
      (b (make-parameter 2 number->string)))
  (assert (equal? (list "1" "2") (list (a) (b))))

  (assert (equal? (list "10" "20")
		  (parameterize ((a 10) (b 20)) (list (a) (b)))))

  (assert (equal? (list "1" "2") (list (a) (b))))

  (handle-exceptions exn #f (parameterize ((a 10) (b 'x)) (void)))

  (assert (equal? (list "1" "2") (list (a) (b))))

  (parameterize ((a 10) (b 30) (a 20))
    (assert (equal? (list "20" "30") (list (a) (b)))))

  (assert (equal? (list "1" "2") (list (a) (b)))) )

;; Special-cased parameters are reset correctly (#1285, regression
;; caused by fix for #1227)

(let ((original-input (current-input-port))
      (original-output (current-output-port))
      (original-error (current-error-port))
      (original-exception-handler (current-exception-handler)))
  (call-with-output-string
   (lambda (out)
     (call-with-input-string
      "foo"
      (lambda (in)
	(parameterize ((current-output-port out)
		       (current-error-port out)
		       (current-input-port in)
		       (current-exception-handler list))
	  (display "bar")
	  (display "!" (current-error-port))
	  (assert (equal? (read) 'foo))
	  (assert (equal? (get-output-string out) "bar!"))
	  (assert (equal? (signal 'baz) '(baz))))))))
  (assert (equal? original-input (current-input-port)))
  (assert (equal? original-output (current-output-port)))
  (assert (equal? original-error (current-error-port)))
  (assert (equal? original-exception-handler (current-exception-handler))))

;; Re-entering dynamic extent of a parameterize should not reset to
;; original outer values but remember values when jumping out (another
;; regression due to #1227, pointed out by Joo ChurlSoo in #1336).

(let ((f (make-parameter 'a))
      (path '())
      (g (make-parameter 'g))
      (c #f))
  (let ((add (lambda () (set! path (cons (f) path)))))
    (add)
    (parameterize ((f 'b)
		   (g (call-with-current-continuation
		       (lambda (c0) (set! c c0) 'c))))
      (add) (f (g)) (add))
    (f 'd)
    (add)
    (if (< (length path) 8)
	(c 'e)
	(assert (equal? '(a b c d b e d b e d) (reverse path))))))

(let ((f (make-parameter 'a))
      (path '())
      (g (make-parameter 'g))
      (c #f))
  (let ((add (lambda () (set! path (cons (f) path)))))
    (add)
    (parameterize ((f 'b))
      (g (call-with-current-continuation (lambda (c0) (set! c c0) 'c)))
      (add) (f (g)) (add))
    (f 'd)
    (add)
    (if (< (length path) 8)
	(c 'e)
	(assert (equal? '(a b c d c e d e e d) (reverse path))))))

;;; vector and blob limits

(assert-fail (make-blob -1))
(assert-fail (make-vector -1))

;;; Resizing of vectors works to both sides
(let ((original (vector 1 2 3 4 5 6)))
  (assert (equal? (vector-resize original 6 -1) original))
  (assert (not (eq? (vector-resize original 6 -1) original))))

(let ((original (vector 1 2 3 4 5 6))
      (smaller (vector 1 2 3)))
  (assert (equal? (vector-resize original 3 -1) smaller)))

(let ((original (vector 1 2 3))
      (larger (vector 1 2 3 -1 -1 -1)))
  (assert (equal? (vector-resize original 6 -1) larger)))

;;; eval return values

(assert (= 1 (eval 1)))
(assert (eq? '() (receive (eval '(values)))))
(assert (equal? '(1 2 3) (receive (eval '(values 1 2 3)))))

;;; message checks for invalid strings

(assert-fail (##sys#message "123\x00456"))

;;; vector procedures

(assert (equal? '#(2 3) (subvector '#(1 2 3) 1)))
(assert (equal? '#(2)   (subvector '#(1 2 3) 1 2)))
(assert (equal? '#()    (subvector '#(1 2 3) 1 1)))
(assert (equal? '#()    (subvector '#(1 2 3) 3)))
(assert-fail (subvector '#(1 2 3) 4))
(assert-fail (subvector '#(1 2 3) 3 4))

;;; alist accessors

(assert (equal? '(foo) (assq 'foo '((foo)))))
(assert (not (assq 'foo '())))
(assert-fail (assq 'foo '(bar)))
(assert-fail (assq 'foo 'bar))


(assert (equal? '(foo) (assv 'foo '((foo)))))
(assert (not (assv 'foo '())))
(assert-fail (assv 'foo '(bar)))
(assert-fail (assv 'foo 'bar))

(assert (equal? '("foo") (assoc "foo" '(("foo")))))
(assert (not (assoc "foo" '())))
(assert-fail (assoc "foo" '("bar")))
(assert-fail (assoc "foo" "bar"))

;;; list membership

(assert (equal? '(foo) (memq 'foo '(bar foo))))
(assert (not (memq 'foo '(bar))))
(assert (not (memq 'foo '())))
(assert-fail (memq 'foo 'foo))

(assert (equal? '(foo) (memv 'foo '(bar foo))))
(assert (not (memv 'foo '(bar))))
(assert (not (memv 'foo '())))
(assert-fail (memv 'foo 'foo))

(assert (equal? '("foo") (member "foo" '("bar" "foo"))))
(assert (not (member "foo" '("bar"))))
(assert (not (member "foo" '())))
(assert-fail (member "foo" "foo"))

;; length

(assert-fail (length 1))
(assert-fail (length '(x . y)))
