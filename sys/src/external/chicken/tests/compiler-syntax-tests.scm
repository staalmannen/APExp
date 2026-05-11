(define (foo) 1)

(assert (= 1 (foo)))

(define-compiler-syntax foo
  (syntax-rules ()
    ((_ x) 2) ) )

(assert (= 2 (foo 42)))
(assert (= 1 (foo)))

(let-compiler-syntax ((foo (syntax-rules () ((_ x) 3))))
  (assert (= 3 (foo 42))))

(assert (= 2 (foo 42)))

(module m1 (bar)
  (import (prefix scheme s:) (chicken syntax))
  (define-compiler-syntax s:+
    (syntax-rules ()
      ((_ x y) (s:- x y))))
  (define-compiler-syntax bar
    (syntax-rules ()
      ((_ x y) "oink!")))
  (s:define (bar x) (s:+ x 1)) )

(module m2 ()
  (import scheme (chicken base) (prefix m1 m-))
  (print (m-bar 10))
  (assert (= 9 (m-bar 10)))
  (print (+ 4 3)))

(define (goo x) `(goo ,x))

(assert (eq? 'goo (car (goo 1))))

(define-compiler-syntax goo
  (syntax-rules ()
    ((_ x) `(cs-goo ,x))))

(print (goo 2))
(assert (eq? 'cs-goo (car (goo 2))))

(define-compiler-syntax goo)

(assert (eq? 'goo (car (goo 3))))

(define-compiler-syntax goo
  (syntax-rules ()
    ((_ x) `(cs-goo2 ,x))))

(let-compiler-syntax ((goo))
		     (assert (eq? 'goo (car (goo 4)))))

(assert (eq? 'cs-goo2 (car (goo 5))))

(module bar (xxx)
  (import scheme (chicken syntax) (chicken base))
  (define (xxx) 'yyy)			; ineffective - suboptimal
  ;(assert (eq? 'yyy (xxx)))
  (define-compiler-syntax xxx
    (syntax-rules ()
      ((_) 'zzz)))
  (define-syntax alias
    (syntax-rules ()
      ((_ name x)
       (define-compiler-syntax name
	 (syntax-rules ()
	   ((_ . args) (x . args)))))))
  (alias pof +)
  (alias pif xxx)
  (assert (= 7 (pof 3 4)))
  (assert (eq? 'zzz (pif)))
  (print (xxx))
  (assert (eq? 'zzz (xxx))))

;;; local to module

(define (f1 x) x)

(module m3 ()
(import scheme (chicken syntax))
(define-compiler-syntax f1
  (syntax-rules () ((_ x) (list x))))
)

(assert (= 2 (f1 2)))
