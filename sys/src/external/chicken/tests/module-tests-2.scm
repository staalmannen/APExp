;;;; module-tests-2.scm


(module oo (output-of)
  (import scheme chicken.port)
  (define-syntax output-of 
    (syntax-rules ()
      ((_ exp) (with-output-to-string (lambda () exp)))))
)

(module mscheme (lambda)
  (import (rename scheme (lambda s:lambda))
	  (chicken module))
  (reexport (except scheme lambda))
  (define-syntax lambda
    (syntax-rules ()
      ((_ llist . body)
       (let ((results #f))
	 (s:lambda 
	  llist
	  (if results
	      (apply values results)
	      (call-with-values (s:lambda () . body)
		(s:lambda rs
		  (set! results rs)
		  (apply values rs)))))))))
)

(module m (f1 f2)
  (import mscheme)
  (define (f1)
    (display 'f1) (newline)
    'f1)
  (define f2
    (lambda ()
      (display 'f2) (newline)
      'f2))
)

(module mtest ()
  (import scheme m (chicken base) oo)
  (assert (string=? "f1\n" (output-of (f1))))
  (assert (string=? "f1\n" (output-of (f1))))
  (assert (string=? "f2\n" (output-of (f2))))
  (assert (string=? "" (output-of (f2)))))

;;;

(module m1 (lambda f1 f2)
  (import (rename scheme (lambda s:lambda)))

  (define-syntax lambda
    (syntax-rules ()
      ((_ llist . body)
       (s:lambda llist (display 'llist) (newline) . body))))

  (define (f1)				; should use standard lambda
    (display 'f1)
    (newline))

  (define f2
    (lambda (x)				; should be our lambda
      (display 'f2)
      (newline)))

)

(module mtest2 (f3 f4)
  (import (except scheme lambda) m1 (chicken base) oo)

  (define (f3)				; standard lambda
    (display 'f3)
    (newline))

  (define f4				; our lambda
    (lambda (x)
      (display 'f4)
      (newline)))

  (assert (string=? "f1\n" (output-of (f1))))
  (assert (string=? "(x)\nf2\n" (output-of (f2 'yes))))
  (assert (string=? "f3\n" (output-of (f3))))
  (assert (string=? "(x)\nf4\n" (output-of (f4 'yes)))))

(module m2 ()
  (import m1)
  ((lambda () (f1)))) ; should use new lambda (but should be folded by compiler)

;; #1132 - internal definitions honor redefinitions of defining forms
(module m3 ()
  (import (rename scheme (define s:define)))
  (import (only (chicken base) assert))
  (define-syntax define
    (syntax-rules ()
      ((_) (display 'oink))
      ((_ var value) (s:define var (+ value 1)))))
  (define)
  ;; Internal definition uses new "define"
  (let ()
    (define a 1)
    (assert (= a 2)))

  ;; Toplevel definition also uses new "define"
  (define b 5)
  (assert (= b 6)))
