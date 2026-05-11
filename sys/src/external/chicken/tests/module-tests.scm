;;;; module-tests.scm

(import (chicken eval) (chicken load))

(cond-expand
 (compiling
  (include "test.scm") )
 (else
  (load-relative "test.scm")))

(test-begin "modules")

(test-assert
 "r4rs"
 (module test-r4rs ()
   (import r4rs)
   (equal? 1 1)))

(test-assert
 "r4rs-null"
 (module test-r4rs-null ()
   (import r4rs-null)
   (begin #t)))

(test-equal "internal/variable"
(module foo (abc def)
  (import scheme)
  (define (abc x) (+ x 33))
  (define-syntax def
    (syntax-rules ()
      ((_ x) (+ 99 (abc x)))))
  (abc 1))
34)

(test-error "external/unimported variable (fail)" (abc 2))
(test-error "external/unimported syntax (fail)" (def 3))

(import foo)

(test-equal "external/imported variable" (abc 4) 37)
(test-equal "external/imported syntax" (def 5) 137)

(module bar (x y)
  (import (prefix scheme s:))
  (s:define (x y) (s:* y 2))
  (s:define y 1))

(import (prefix (only (except (rename bar (x z)) y) z) "bar-"))
(test-equal "modified import" (bar-z 10) 20)
(test-error "hidden import" y)

(module baz ((x s:list))
  (import (prefix scheme s:))
  (s:define-syntax x
    (syntax-rules ()
      ((_ x) (s:list x)))))

(import baz)
(test-equal "prefixed import and reexport" (x 1) '(1))

(module m1 ((bar gna))
  (import scheme)
  (define (gna x) (list 'gna x))
  (define-syntax bar
    (syntax-rules ()
      ((_ x) (baz x))))
  (define-syntax baz
    (syntax-rules ()
      ((_ x) (gna 'x)))))

(module m2 (run)
  (import scheme (chicken base) m1)
  (define-syntax baz
    (syntax-rules ()
      ((_ x) (list 'goo 'x))))
  (define (gna x) (print "ok."))
  (define (run) (gna 9) (bar 99)))

(import (only m2 run))
(test-equal "indirect imports" (run) '(gna 99))

(module m1 ((s1 f1))
  (import scheme (chicken base))
  (define (f1) (print "f1") 'f1)
  (define-syntax s1
    (syntax-rules ()
      ((_) (f1)))))

(module m2 (s2)
  (import scheme m1)
  (define-syntax s2
    (syntax-rules ()
      ((_) (s1)))))

(module m3 (s3)
  (import scheme m2)
  (define-syntax s3
    (syntax-rules ()
      ((_) (s2)))))

(import m3)
(test-equal "chained indirect imports" (s3) 'f1)

(module literal-compare-test (s1)
  (import scheme)
  (define-syntax s1
    (syntax-rules (and)
      ((_ (and x)) (list x))))
)

(import literal-compare-test)
(test-equal "literal compare and export" (s1 (and 100)) '(100))

(module y (y1)
  (import scheme)
  (define y1 10))

(module x (magnitude)
  (import (except scheme magnitude) y)
  (define magnitude y1))

(test-equal "redefinition of indirect import" (procedure? magnitude) #t)

(import x)
(test-equal "redefinition of indirect import (II)" magnitude 10)

(module m10 (m10x m10y)
  (import scheme)
  (define m10x 99)
  (define-syntax m10y
    (syntax-rules ()
      ((_ x) (list 'x)))))

(module m11 (m10x m10y)
  (import m10))

(import m11)
(test-equal "value reexport" m10x 99)
(test-equal "syntax reexport" (m10y 3) '(3))

;; found by Jim Ursetto;

(module m12 (begin0)
  (import scheme)
  (define-syntax begin0
    (syntax-rules ()
      ((_ e0 e1 ...)
       (##sys#call-with-values
	(lambda () e0)
	(lambda var
	  (begin
	    e1 ...
	    (apply ##sys#values var))))))))

(test-equal "primitive indirect value-binding reexport"
	    (module m13 ()
	      (import m12)		; note absence of "scheme"
	      (begin0 1 2 3))
	    1)

(module m14 (test-extlambda)
  (import scheme)
  (define (test-extlambda string #!optional whatever)
    string))

(import m14)

(test-equal "extended lambda list uses expansion environment"
            "some text"
            (test-extlambda "some text"))

;;; import-forms in `require-extension':

(module m15 ()
  (import scheme (chicken base))
  (import (prefix (rename srfi-4 (u8vector u)) 99:))
  (print 99:u))


;;; expansion of macros into modules:

(module m16 (foo-module)

(import scheme)

(define-syntax foo-module
  (syntax-rules ()
    ((_ name)
     (module name (maker definer)
       (import scheme)
       (define (maker) 'name)
       (define-syntax definer
         (syntax-rules () 
           ((_) (define (name) 'name))))))))

)

(import m16)
(foo-module abc)
(import abc)

(test-equal 
 "function defined in module that is the result of an expansion"
 'abc (maker))

(definer)

(test-equal 
 "syntax defined in module that is the result of an expansion"
 'abc (abc))

(module m17 (a) (import scheme) (define a 1))
(begin-for-syntax ; XXX workaround for missing module alias functionality
  (##sys#register-module-alias 'm18 'm17))
(module m19 (a) (import scheme) (define a 2))

(test-equal
 "global module alias scope (1)"
 (module m20 ()
   (import scheme) 
   (import m18)
   a)
 1)

(test-equal
 "local module alias scope"
 (module m21 ()
   (import scheme (chicken syntax))
   (begin-for-syntax ; XXX s.a.
     (##sys#register-module-alias 'm18 'm19))
   (import m18)
   a)
 2)

(test-equal
 "global module alias scope (2)"
 (module m20 ()
   (import scheme) 
   (import m18)
   a)
 1)

;; #865 - "*" export list needs special treatment when using "export"
;; (fix contributed by "megane")

(module
 m22
 *
 (import scheme)
 (define b 2))

(module
 m23
 *
 (import (chicken module))
 (import m22)
 (export b) )

(test-equal
 "`*' export-list + explicit export"
 (module m24 ()
   (import m23)
   b)
 2)

;; (contributed by "megane")

(module m25 *
  (import scheme)
  (define foo 1))

(module m26 (bar)
  (import (chicken module) scheme)
  (reexport m25)
  (define bar 2))

(module m27 *
  (import (chicken module) scheme)
  (reexport m25) ;; <- oops, bar not exported anymore
  (define bar 2))

(test-equal
 "handle star-exporting module with reexport"
 (module m28 ()
   (import scheme (chicken base))
   (import (prefix m26 b/))
   (import (prefix m27 c/))
   (print b/foo)
   (print c/foo)
   (print b/bar)
   c/bar) ;; <- Error: unbound variable: c/bar
 2)

;; somewhat related, but with syntax (#882, found by megane):

(module m29 *
  (import (chicken syntax) scheme)
  (define-syntax m29-baz
    (er-macro-transformer
     (lambda _
       ''foo))))

(module m30 *
  (import (chicken module))
  (import m29)
  (export m29-baz))

(test-equal
 "star-export with explicit re-export of syntax"
 (module m31 ()
   (import scheme)
   (import m30)
   (m29-baz))
 'foo)

;; list-style library names

(test-assert
 (module (m33 a) *
   (import (scheme))
   (define (foo) 'ok)))

(test-assert
 (module (m33 b) ()
   (import (scheme) (m33 a))
   (eq? (foo) 'ok)))

(test-assert (import (prefix (m33 a) m33/a/)))
(test-assert (eq? (m33/a/foo) 'ok))
(test-assert (module-environment '(m33 a)))

;; Ensure that the modules system is simply an aliasing mechanism:
;; Module instantion does not create multiple variable copies.

(module m31 *
  (import (chicken base) scheme)
  (define mutation-count 0)
  (define (internally-mutate!)
    (set! mutation-count (add1 mutation-count)))
  (define (get-count)
    mutation-count))

(module m32 *
  (import (chicken base) scheme m31)
  (define (externally-mutate!)
    (set! mutation-count (add1 mutation-count))))

(import m31 m32)
(test-equal
 "initial state"
 0 mutation-count)

(internally-mutate!)

(test-equal
 "After mutating inside defining module"
 1 mutation-count)

(set! mutation-count 2)

(test-equal
 "After mutating outside module"
 2 mutation-count)

(externally-mutate!)

(test-equal
 "After mutation by another module"
 3 mutation-count)

(test-equal
 "Internal getter returns same thing"
 3 (get-count))

(test-assert
 (not (current-module)))

(test-assert
 (module m33 ()
   (import (scheme) (chicken module))
   (eq? (current-module) 'm33)))

(module m34 ((syn bar) alias)
  (import scheme (chicken base) (chicken module))
  (export/rename (bar baz) (syn syn2))
  (define bar 123)
  (assert (equal? bar 123))
  (define-syntax alias 
    (syntax-rules () 
      ((_) (syn))))
  (define-syntax syn
    (syntax-rules ()
      ((_) (list bar)))))

(module m35 ()
  (import scheme (chicken base) (chicken module))
  (import (only (rename m34 (syn2 syn3)) syn3 alias))
  (import (rename m34 (baz bax)))
  (define bar 99)
  (assert (equal? bax 123))
  (assert (equal? (syn3) '(123)))
  (assert (equal? (alias) '(123)))
  (assert (equal? bar 99)))

;; corner case, found by DeeEff, actually not really a good idea,
;; but the expander looped here endlessly
(module m36 (xcons)
  (import scheme)
  (define (xcons x y) (cons y x)))
  
(module m37 ()
  (import (rename m36
                  (xcons m36#xcons)))
  (import scheme (chicken base))
  (define (xcons x y) (m36#xcons 'X x))
  (assert (equal? '(1 . X) (xcons 1 2))))

(test-end "modules")

(test-exit)
