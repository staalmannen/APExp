;;;; environment-tests.scm

(import (chicken load) (chicken eval))

(load-relative "test.scm")


(test-begin "evaluation environment tests")

(test-equal (eval 123) 123)
(test-equal (eval 123 (interaction-environment)) 123)
(test-equal (eval 'car (interaction-environment)) car)
(test-error (eval 'foo (interaction-environment)))
(test-equal (eval '(begin (set! foo 99) foo) (interaction-environment)) 99)

(test-equal (eval 123) 123)
(test-equal (eval 123 (scheme-report-environment 5)) 123)
(test-equal (eval 'car (scheme-report-environment 5)) car)
(test-error (eval 'foo (scheme-report-environment 5)))
(test-error (eval 'values (scheme-report-environment 4)))
(test-equal (eval 'values (scheme-report-environment 5)) values)
(test-error (eval '(set! foo 99) (scheme-report-environment 5)))

(test-error (eval '(define-syntax foo (syntax-rules () ((_) 1)))
		  (scheme-report-environment 5)))

(test-error (eval 'car (null-environment 5)))
(test-error (eval '(cond-expand (chicken 1) (else 2)) (null-environment 4)))
(test-error (eval '(cond-expand (chicken 1) (else 2)) (null-environment 5)))
(test-error (eval '(cond-expand (chicken 1) (else 2)) (scheme-report-environment 4)))
(test-error (eval '(cond-expand (chicken 1) (else 2)) (scheme-report-environment 5)))
(test-equal 1 (eval '(if #t 1 2) (scheme-report-environment 5)))
(test-equal 1 (eval '(if #t 1 2) (null-environment 4)))
(test-equal 1 (eval '(if #t 1 2) (null-environment 5)))
(test-equal (eval '((lambda (x) x) 123) (null-environment 5)) 123)

(import (chicken eval))

(define baz 100)

(module foo (bar)
  (import r5rs)
  (define (bar) 99))

(define foo-env (module-environment 'foo))
(define csi-env (module-environment '(chicken csi)))
(define format-env (module-environment 'chicken.format))

(test-equal (eval '(bar) foo-env) 99)
(test-error (eval 'baz foo-env))
(test-equal (eval '(editor-command) csi-env) #f)
(test-error (eval 'baz csi-env))
(test-equal (eval '(format "~a" 1) format-env) "1")
(test-error (eval 'baz format-env))

;; #1295
(module example *
  (import scheme)
  (define (add a b) (+ a b))
  (define-syntax double
    (syntax-rules ()
      ((_ x) (add x x)))))

(test-equal (eval '(double 10) (module-environment 'example)) 20)

(test-end)

(test-exit)
