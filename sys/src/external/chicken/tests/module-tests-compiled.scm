;;;; module-tests-compiled.scm


(include "test.scm")

(test-begin "modules/compiled")


;; inlines where walked twice (once for extracting mutable constants)
;; and then when expanded, this caused inline function names to be
;; aliased/renamed twice - also, aliasing in syntax-defs could make
;; inline func unrecognizable for canonicalizer.

(module m1 (f1)
  (import scheme (chicken base))
  (define-inline (bar x) (cons x '(foo)))
  (define-syntax s1
    (syntax-rules ()
      ((_ x) (list (bar x)))))
  (define (f1 x) (s1 x)))

(import m1)
(test-equal "inline in syntax" (f1 'ok) '((ok foo)))


;; here, the identical names of alias/real id pairs in primitive
;; modules with prefix applied would cause the second to be marked
;; ##core#aliase'd. That would avoid renaming of the newly defined
;; vector-fill!.

(module m2 (vector-fill!)
  (import (except scheme vector-fill!)
          (prefix (only scheme vector-fill!) %))
  (define (vector-fill! x v)
    (%vector-fill! v x)
    v))

(import m2)
(define v (vector 1 2 3))
(test-equal "unmarked primitive exports" (vector-fill! 99 v) '#(99 99 99))

(module m3 (op)
  (import scheme)
  (define op -))

(module m4 (op)
  (import scheme)
  (define op +))

;; Lexically scoped import, see #1437

(import m4)
(test-equal "lexically scoped import uses imported module"
	    3 (let () (import m3) (op 5 2)))

(test-equal "After leaving scope, fall back to old import" 7 (op 5 2))

(eval '(import m4))
(test-equal "Interpreted code behaves identically on lexical import"
	    3 (eval '(let () (import m3) (op 5 2))))

(test-equal "Interpreted code behaves identically after leaving scope"
	    7 (eval '(op 5 2)))

;; This was the remaining bug: imports would be evaluated during
;; macro expansion, mutating ##sys#current-environment, but the
;; code walker would keep the old syntax environment.
(begin
  (import m3)
  (test-equal "In begin, imports are seen immediately" 3 (op 5 2)))

(test-equal "begin splices; imports still active afterwards" 3 (op 5 2))

(test-end "modules")

(test-exit)
