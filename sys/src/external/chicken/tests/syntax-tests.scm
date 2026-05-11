;;;; syntax-tests.scm - various macro tests

(import-for-syntax chicken.pretty-print)
(import chicken.gc chicken.pretty-print chicken.port)

(define-syntax t
  (syntax-rules ()
    ((_ r x)
     (let ((tmp x))
       (if (not (equal? r tmp))
	   (error "test failed" r tmp 'x)
	   (pp tmp))))))

(define-syntax f
  (syntax-rules ()
    ((_ x)
     (let ((got-error #f))
      (handle-exceptions ex (set! got-error #t) x)
      (unless got-error
        (error "test returned, but should have failed" 'x) )))))

(t 3 3)

(f abc)
(f (t 3 4))

;; test syntax-rules

(define-syntax test
  (syntax-rules ()
    ((_ x form)
     (let ((tmp x))
       (if (number? tmp)
	   form
	   (error "not a number" tmp))))))

(t 100 (test 2 100))


;; Keywords are not symbols; don't attempt to bind them
(t 1 (let-syntax ((foo (syntax-rules () ((foo bar: qux) qux))))
       (foo bar: 1)))

;; some basic contrived testing

(define (fac n)
  (let-syntax ((m1 
		(er-macro-transformer
		 (lambda (n r c) 
		   (pp `(M1: ,n))
		   (list (r 'sub1) (cadr n))))))
    (define (sub1 . _)			; ref. transp.? (should not be used here)
      (error "argh.") )
    #;(print "fac: " n)		  
    (if (test n (zero? n))
	1
	(* n (fac (m1 n))))))

(t 3628800 (fac 10))

;; letrec-syntax

(t 34
(letrec-syntax ((foo (syntax-rules () ((_ x) (bar x))))
		(bar (syntax-rules () ((_ x) (+ x 1)))))
  (foo 33))
)

;; letrec-values

(t '(0 1 2 3 (4) (5 6))
   (letrec-values ((() (values))
                   ((a) (values 0))
                   ((b c) (values 1 2))
                   ((d . e) (values 3 4))
                   (f (values 5 6)))
     (list a b c d e f)))

;; from r5rs:

(t 45
(let ((x 5))
  (define foo (lambda (y) (bar x y)))
  (define bar (lambda (a b) (+ (* a b) a)))
  (foo (+ x 3)))
)

;; an error, according to r5rs - here it treats foo as defining a toplevel binding

#;(let-syntax
  ((foo (syntax-rules ()
          ((foo (proc args ...) body ...)
           (define proc
             (lambda (args ...)
               body ...))))))
  (let ((x 3))
    (foo (plus x y) (+ x y))
    (define foo x)
    (print (plus foo x))))

(t 'now
(let-syntax ((when (syntax-rules ()
                     ((when test stmt1 stmt2 ...)
                      (if test
                          (begin stmt1
                                 stmt2 ...))))))
  (let ((if #t))
    (when if (set! if 'now))
    if))
)

(t 'outer
(let ((x 'outer))
  (let-syntax ((m (syntax-rules () ((m) x))))
    (let ((x 'inner))
      (m))))       
)

(t 7
(letrec-syntax
  ((my-or (syntax-rules ()
            ((my-or) #f)
            ((my-or e) e)
            ((my-or e1 e2 ...)
             (let ((temp e1))
               (if temp
                   temp
                   (my-or e2 ...)))))))
  (let ((x #f)
        (y 7)
        (temp 8)
        (let odd?)
        (if even?))
    (my-or x
           (let temp)
           (if y)
           y)))
)

;; From Al* Petrofsky's "An Advanced Syntax-Rules Primer for the Mildly Insane"
(let ((a 1))
  (letrec-syntax
      ((foo (syntax-rules ()
              ((_ b)
               (bar a b))))
       (bar (syntax-rules ()
              ((_ c d)
               (cons c (let ((c 3))
                         (list d c 'c)))))))
    (let ((a 2))
      (t '(1 2 3 a) (foo a)))))

;; ER equivalent
(let ((a 1))
  (letrec-syntax
      ((foo (er-macro-transformer
             (lambda (x r c)
               `(,(r 'bar) ,(r 'a) ,(cadr x)))))
       (bar (er-macro-transformer
             (lambda (x r c)
               (let ((c (cadr x))
                     (d (caddr x)))
                `(,(r 'cons) ,c
                  (,(r 'let) ((,c 3))
                   (,(r 'list) ,d ,c ',c))))))))
    (let ((a 2))
      (t '(1 2 3 a) (foo a)))))

;; IR equivalent
(let ((a 1))
  (letrec-syntax
      ((foo (ir-macro-transformer
             (lambda (x i c)
               `(bar a ,(cadr x)))))
       (bar (ir-macro-transformer
             (lambda (x i c)
               (let ((c (cadr x))
                     (d (caddr x)))
                 `(cons ,c
                        (let ((,c 3))
                          (list ,d ,c ',c))))))))
    (let ((a 2))
      (t '(1 2 3 a) (foo a)))))

;; Strip-syntax on vectors:
(let-syntax
    ((foo (syntax-rules ()
            ((_)
             '#(b)))))
  (t '#(b) (foo)))

(define-syntax kw
  (syntax-rules (baz)
    ((_ baz) "baz")
    ((_ any) "no baz")))

(t "baz" (kw baz))
(t "no baz" (kw xxx))

(let ((baz 100))
  (t "no baz" (kw baz)))

;; Optimisation to rewrite constants with =>, reported by Michele La Monaca
(t 2 (cond (1 2)))
(f (cond (1 => string-length)))
(t #t (cond (1 => odd?)))

(t 'ok
(let ((=> #f))
  (cond (#t => 'ok)))
)

(t 1 (let ((=> 1))
       (cond (#f 'false)
             (#t =>))))

(t 3 (let ((=> 1))
       (cond (#f 'false)
             (#t => 2 3))))

(t '(3 4)
(let ((foo 3))
  (let-syntax ((bar (syntax-rules () ((_ x) (list foo x)))))
    (let ((foo 4))
      (bar foo))))
)

;;; strip-syntax cuts across multiple levels of syntax
;;; reported by Matthew Flatt
(define-syntax c 
  (syntax-rules () 
    [(_) 
     (let ([x 10]) 
       (let-syntax ([z (syntax-rules ()
                         [(_) (quote x)])])
         (z)))]))

(t "x" (symbol->string (c)))

(define-syntax c2
   (syntax-rules ()
     [(_)
      (let ([x 10])
        (let-syntax ([z (syntax-rules ()
                          [(_) (let-syntax ([w (syntax-rules ()
                                                 [(_) (quote x)])])
                                 (w))])])
          (z)))]))

(t "x" (symbol->string (c2)))

;;; strip-syntax on renamed module identifiers, as well as core identifiers
(module foo (bar)
  (import scheme)

  (define bar 1))

(import foo)

(define-syntax baz
  (er-macro-transformer
   (lambda (e r c)
     `',(strip-syntax (r 'bar)))))

(t "bar" (symbol->string (baz bar)))
(t "bar" (symbol->string (baz void)))

;; Fully qualified symbols are not mangled - these names are internal
;; and not documented, but shouldn't be messed with by the expander

(t "foo#bar" (symbol->string 'foo#bar))
(t "foo#bar" (symbol->string (strip-syntax 'foo#bar)))

(t "#!rest" (symbol->string '#!rest))
(t "#!rest" (symbol->string '|#!rest|))
(t "#!rest" (symbol->string (strip-syntax '#!rest)))

;; Read-write invariance of "special" symbols

(t '#!rest (with-input-from-string "#!rest" read))
(t '#!rest (with-input-from-string "|#!rest|" read))
(t "#!rest" (with-output-to-string (lambda () (write '#!rest))))

;; Non-special symbols starting with shebang
(f (with-input-from-string "#!foo" read))
(t '|#!foo| (with-input-from-string "|#!foo|" read))
(t "|#!foo|" (with-output-to-string (lambda () (write '|#!foo|))))

;; Namespaced symbols
(t "foo#bar" (with-output-to-string (lambda () (write 'foo#bar))))
(t "##foo#bar" (with-output-to-string (lambda () (write '##foo#bar))))

;; These used to be treated specially, but now they just trigger an
;; "invalid sharp-sign read syntax" error.
(t "|#%foo|" (with-output-to-string (lambda () (write '|#%foo|))))
(f (with-input-from-string "#%foo" read))

;;; alternative ellipsis test (SRFI-46)

(define-syntax foo
  (syntax-rules 
      ___ () 
      ((_ vals ___) (list '... vals ___))))

(t '(... 1 2 3)
   (foo 1 2 3)
)

(define-syntax defalias
  (syntax-rules ___ ()
    ((_ new old)
     (define-syntax new
       (syntax-rules ()
	 ((_ args ...) (old args ...)))))))

(defalias inc add1)

(t 3 (inc 2))

;;; Rest patterns after ellipsis (SRFI-46)

(define-syntax foo
  (syntax-rules ()
    ((_ (a ... b) ... (c d))
     (list (list (list a ...) ... b ...) c d))
    ((_ #(a ... b) ... #(c d) #(e f))
     (list (list (vector a ...) ... b ...) c d e f))
    ((_ #(a ... b) ... #(c d))
     (list (list (vector a ...) ... b ...) c d))))

(t '(() 1 2)
   (foo (1 2)))

(t '(((1) 2) 3 4)
   (foo (1 2) (3 4)))

(t '(((1 2) (4) 3 5) 6 7)
   (foo (1 2 3) (4 5) (6 7)))

(t '(() 1 2)
   (foo #(1 2)))

(t '((#() 1) 2 3)
   (foo #(1) #(2 3)))

(t '((#(1 2) 3) 4 5)
   (foo #(1 2 3) #(4 5)))

(t '((#(1 2) 3) 4 5 6 7)
   (foo #(1 2 3) #(4 5) #(6 7)))

(t '(() 1 2 3 4)
   (foo #(1 2) #(3 4)))

(t '((#(1) 2) 3 4 5 6)
   (foo #(1 2) #(3 4) #(5 6)))

(t '((#(1 2) #(4) 3 5) 6 7 8 9)
   (foo #(1 2 3) #(4 5) #(6 7) #(8 9)))

;;; Bug discovered during implementation of SRFI-46 rest patterns:

(define-syntax foo
  (syntax-rules ()
    ((_ #((a) ...)) (list a ...))))

(t '(1)
   (foo #((1))))

;;;

(define-syntax usetmp
  (syntax-rules ()
    ((_ var) 
     (list var))))

(define-syntax withtmp
  (syntax-rules ()
    ((_ val exp)
     (let ((tmp val))
       (exp tmp)))))

(t '(99)
   (withtmp 99 usetmp)
)

(t 7
(letrec-syntax
    ((my-or (syntax-rules ()
	      ((my-or) #f)
	      ((my-or e) e)
	      ((my-or e1 e2 ...)
	       (let ((temp e1))
		 (if temp
		     temp
		     (my-or e2 ...)))))))
  (let ((x #f)
        (y 7)
        (temp 8)
        (let odd?)
        (if even?))
    (my-or x
           (let temp)
           (if y)
           y)))
)

(define-syntax foo
  (syntax-rules ()
    ((_ #(a ...)) (list a ...))))

(t '(1 2 3)
   (foo #(1 2 3))
)


(define-syntax loop
  (er-macro-transformer
   (lambda (x r c)
     (let ((body (cdr x)))
       `(,(r 'call/cc)
	 (,(r 'lambda) (exit)
	  (,(r 'let) ,(r 'f) () ,@body (,(r 'f)))))))))

(let ((n 10))
  (loop
   (print* n " ") 
   (set! n (sub1 n))
   (when (zero? n) (exit #f)))
  (newline))

(define-syntax while0
  (syntax-rules ()
    ((_ t b ...)
     (loop (if (not t) (exit #f)) 
	   b ...))))

(f (while0 #f (print "no.")))

(define-syntax while
  (er-macro-transformer
   (lambda (x r c)
     `(,(r 'loop) 
       (,(r 'if) (,(r 'not) ,(cadr x)) (exit #f))
       ,@(cddr x)))))

(let ((n 10))
  (while (not (zero? n))
	 (print* n " ")
	 (set! n (- n 1)) )
  (newline))

;;; found by Jim Ursetto

(let ((lambda 0)) (define (foo) 1) (foo))


;;; define-macro implementation (only usable in a module-free environment)

(define-syntax define-macro
  (syntax-rules ()
    ((_ (name . llist) body ...)
     (define-syntax name
       (er-macro-transformer
	(lambda (x r c)
	  (apply (lambda llist body ...) (strip-syntax (cdr x)))))))))

(define-macro (loop . body)
  (let ((loop (gensym)))
    `(call/cc
      (lambda (exit)
	(let ,loop () ,@body (,loop))))))

(let ((i 1))
  (loop (when (> i 10) (exit #f))
	(print* i " ")
	(set! i (add1 i))))
(newline)


;;;; exported macro would override original name (fixed in rev. 13351)

(module xfoo (xbaz xbar)
  (import scheme)
  (define-syntax xbar
    (syntax-rules ()
      ((_ 1) (xbaz))
      ((_) 'xbar)))
  (define-syntax xbaz
    (syntax-rules ()
      ((_ 1) (xbar))
      ((_) 'xbazz))))

(import xfoo)
(assert (eq? 'xbar (xbaz 1)))
(assert (eq? 'xbazz (xbar 1)))
(assert (eq? 'xbar (xbar)))


;;;; ellipsis pattern element wasn't matched - reported by Jim Ursetto (fixed rev. 13582)

(define-syntax foo
  (syntax-rules ()
    ((_ (a b) ...)
     (list '(a b) ...))
    ((_ a ...)
     (list '(a) ...))))

(assert (equal? (foo (1 2) (3 4) (5 6)) '((1 2) (3 4) (5 6))))
(assert (equal? (foo (1 2) (3) (5 6)) '(((1 2)) ((3)) ((5 6))))) ; failed
(assert (equal? (foo 1) '((1))))


;;; incorrect lookup for keyword variables in DSSSL llists

(module broken-keyword-var ()
  (import scheme (chicken base))
  ((lambda (#!key string) (assert (not string))))) ; refered to R5RS `string'

;;; Missing check for keyword and optional variable types in DSSSL llists

(f (eval '(lambda (foo #!key (0 1)) x)))
(f (eval '(lambda (foo #!optional (0 1)) x)))

;;; compiler didn't resolve expansion into local variable
;;; (reported by Alex Shinn, #15)

(module unresolve-local (foo)
  (import scheme)
  (define (foo)
    (let ((qux 3))
      (let-syntax ((bar (syntax-rules () ((bar) qux))))
	(bar))))

  (display (foo))
  (newline)
)


;;; incorrect expansion when assigning to something marked '##core#primitive (rev. 14613)

(define x 99)

(module primitive-assign ()
  (import scheme (chicken base))
  (let ((x 100)) (set! x 20) (assert (= x 20)))
  (set! setter 123))

(assert (= x 99))
(assert (= 123 setter))


;;; prefixed import from `chicken' module with indirect reference to imported syntax
;;; (reported by Jack Trades)

(module prefixed-self-reference1 (a b c)
  (import scheme (prefix chicken.base c:))
  (c:define-values (a b c) (values 1 2 3)) )

(module prefixed-self-reference2 ()
  (import scheme (prefix (chicken base) c:) (prefix (chicken condition) c:))
  (c:define-values (a b c) (values 1 2 3))
  (c:print "ok")
  (c:condition-case 
   (c:abort "ugh")
   (ex () (c:print "caught"))))

(module prefixed-self-reference3 (a)
  ;; TODO: Switch this around when plain "chicken" has been removed
  (import (prefix scheme s.) (prefix (chicken condition) c.))
  (s.define (a x y)
	    (c.condition-case (s.+ x y) ((exn) "not numbers")))
  )

(module prefixed-self-reference4 (a)
  (import (prefix scheme s.))
  (s.define (a x y) (s.and x y)))


;;; canonicalization of body captures 'begin (reported by Abdulaziz Ghuloum)

(let ((begin (lambda (x y) (bomb)))) 1 2)


;;; redefinition of defining forms

(module m0001 (foo bar)
  (import (prefix scheme s:))
  (s:define-syntax foo (syntax-rules () ((_ x) (s:list x))))
  (s:define bar 99))

(module m0002 ()
  (import scheme m0001 chicken.pretty-print)
  (pp (foo bar)))


;;; renaming of arbitrary structures

(module m1 (s1 s2)

  (import scheme)

  (define-syntax s1 (syntax-rules () ((_ x) (list x))))

  (define-syntax s2
    (er-macro-transformer
     (lambda (x r c)
       (r `(vector (s1 ,(cadr x))))))) )	; without renaming the local version of `s1'
					; below will be captured 

(import m1)

(let-syntax ((s1 (syntax-rules () ((_ x) x))))
  (assert (equal? '#((99)) (s2 99))))

;; IR macros

(define-syntax loop2
  (ir-macro-transformer
   (lambda (x i c)
     (let ((body (cdr x)))
       `(call/cc
         (lambda (,(i 'exit))
           (let f () ,@body (f))))))))

(let ((n 10))
  (loop2
   (print* n " ") 
   (set! n (sub1 n))
   (when (zero? n) (exit #f)))
  (newline))

(define-syntax while20
  (syntax-rules ()
    ((_ t b ...)
     (loop2 (if (not t) (exit #f)) 
	    b ...))))

(f (while20 #f (print "no.")))

(define-syntax while2
  (ir-macro-transformer
   (lambda (x i c)
     `(loop 
       (if (not ,(cadr x)) (,(i 'exit) #f))
       ,@(cddr x)))))

(let ((n 10))
  (while2 (not (zero? n))
          (print* n " ")
          (set! n (- n 1)) )
  (newline))

(module m2 (s3 s4)

  (import scheme)

  (define-syntax s3 (syntax-rules () ((_ x) (list x))))

  (define-syntax s4
    (ir-macro-transformer
     (lambda (x r c)
       `(vector (s3 ,(cadr x)))))) ) ; without implicit renaming the local version
                                     ; of `s3' below would be captured 

(import m2)

(let-syntax ((s3 (syntax-rules () ((_ x) x))))
  (t '#((99)) (s4 99)))

(let ((vector list))
  (t '#((one)) (s4 'one)))

(define-syntax nest-me
  (ir-macro-transformer
   (lambda (x i c)
     `(let ((,(i 'captured) 1))
        ,@(cdr x)))))

(t '(1 #(1 #(1)))
   (nest-me (list captured
                  (let ((captured 2)
                        (let 'not-captured)
                        (list vector))
                    (nest-me (list captured
                                   (nest-me (list captured))))))))

(define-syntax cond-test
  (ir-macro-transformer
   (lambda (x i c)
     (let lp ((exprs (cdr x)))
       (cond
        ((null? exprs) '(void))
        ((c (caar exprs) 'else)
         `(begin ,@(cdar exprs)))
        ((c (cadar exprs) '=>)
         `(let ((tmp ,(caar exprs)))
            (if tmp
                (,(caddar exprs) tmp)
                ,(lp (cdr exprs)))))
        ((c (cadar exprs) (i '==>)) ;; ==> is an Unhygienic variant of =>
         `(let ((tmp ,(caar exprs)))
            (if tmp
                (,(caddar exprs) tmp)
                ,(lp (cdr exprs)))))
        (else
         `(if ,(caar exprs)
              (begin ,@(cdar exprs))
              ,(lp (cdr exprs)))))))))

(t 'yep
   (cond-test
    (#f 'false)
    (else 'yep)))

(t 1
   (cond-test
    (#f 'false)
    (1 => (lambda (x) x))
    (else 'yep)))

(let ((=> #f))
  (t 'a-procedure
     (cond-test
      (#f 'false)
      (1 => 'a-procedure)
      (else 'yep))))

(let ((else #f))
  (t (void)
     (cond-test
      (#f 'false)
      (else 'nope))))

(t 1
   (cond-test
    (#f 'false)
    (1 ==> (lambda (x) x))
    (else 'yep)))

(let ((==> #f))
  (t 1
     (cond-test
      (#f 'false)
      (1 ==> (lambda (x) x))
      (else 'yep))))

;; Undefined value (but no compiler error) on empty `else' clauses
(t (void) (cond (else)))
(t (void) (case 1 (else)))

;; Literal quotation of a symbol, injected or not, should always result in that symbol
(module ir-se-test (run)
  (import scheme chicken.base)
  (define-syntax run
    (ir-macro-transformer
     (lambda (e i c)
       `(quote ,(i 'void))))))

(import ir-se-test)
(t 'void (run))

;;; local definitions

(define-syntax s2
  (syntax-rules ()
    ((_) 1)))

(define (f1) 3)
(define-values (v1 v2) (values 9 10))
(define-values (v3 . v4) (values 11 12))
(define-values v56 (values 13))

(let ()
  (define-syntax s2
    (syntax-rules ()
      ((_) 2)))
  42
  (define-values (v1 v2) (values 1 2))
  (define-values (v3 . v4) (values 3 4))
  (define-values v56 (values 5 6))
  (define v56-again v56) ; ordering of assignments was broken #1274
  43
  (define (f1) 4)
  (define ((f2)) 4)
  (assert (= 4 (f1)))
  (assert (= 4 ((f2))))
  (assert (= 2 (s2)))
  (assert (= 1 v1))
  (assert (= 2 v2))
  (assert (= 3 v3))
  (assert (equal? (list 4) v4))
  (assert (equal? (list 5 6) v56))
  (assert (equal? (list 5 6) v56-again)))

(assert (= 1 (s2)))
(assert (= 3 (f1)))
(assert (= 9 v1))
(assert (= 10 v2))
(assert (= 11 v3))
(assert (equal? (list 12) v4))
(assert (equal? (list 13) v56))

;;; redefining definition forms (disabled, since we can not catch this error easily)

#|
(module m0a () (import chicken.module) (reexport (only scheme define)))
(module m0b () (import chicken.module) (reexport (only scheme define-syntax)))

(module m1 ()
(import (prefix scheme s:) (prefix m0b m:))
;(s:define m:define 1)
(s:define-syntax s:define-syntax (syntax-rules ()))
)
|#

;;; Definitions of non-identifiers

(f (eval '(define foo: 1)))
(f (eval '(define-syntax foo: (syntax-rules () ((_) 1)))))
(f (eval '(let foo: () 1)))
(f (eval '(let ((foo: 1)) 1)))


;;; Definitions in expression contexts are rejected (#1309)

(f (eval '(+ 1 2 (begin (define x 3) x) 4)))
(f (eval '(+ 1 2 (begin (define-values (x y) (values 3 4)) x) 4)))
(f (eval '(display (define x 1))))
;; Some tests for nested but valid definition expressions:
(t 2 (eval '(begin (define x 1) 2)))
(t 2 (eval '(module _ () (import scheme) (define x 1) 2)))
(t 1 (eval '(let ()
	      (define-record-type foo (make-foo bar) foo? (bar foo-bar))
	      (foo-bar (make-foo 1)))))

;; Nested begins inside definitions were not treated correctly
(t 3 (eval '(let () (begin 1 (begin 2 (define internal-def 3) internal-def)))))
;; Macros that expand to "define" should not cause a letrec barrier
(t 1 (eval '(let-syntax ((my-define (syntax-rules ()
				      ((_ var val) (define var val)))))
	      (let () (define (run-it) foo) (my-define foo 1) (run-it)))))
;; Begin should not cause a letrec barrier
(t 1 (eval '(let () (define (run-it) foo) (begin (define foo 1) (run-it)))))
(f (eval '(let () internal-def)))

;;; renaming of keyword argument (#277)

(define-syntax foo1
  (syntax-rules ()
    ((_ procname)
     (define (procname #!key (who "world"))
       (string-append "hello, " who)))))

(foo1 bar)

(assert (string=? "hello, XXX" (bar who: "XXX")))

;;; DSSSL keyword arguments in various combinations with optional and rest args
;;; reported on IRC by R. Winkler

(define (test-optional&rest x y #!optional z #!rest r)
  (list x y z r))

(assert (equal? '(3 4 5 (6 7)) (test-optional&rest 3 4 5 6 7)))

(define (test-optional&rest-cdrs x y #!optional z #!rest r)
  (list x y z (cdr (cdr r))))

(assert (equal? '(3 4 5 ()) (test-optional&rest-cdrs 3 4 5 6 7)))

(define (test-optional&key x y #!optional z #!key i (j 1))
  (list x y z i: i j: j))

(assert (equal? '(3 4 5 i: 6 j: 7) (test-optional&key 3 4 5 i: 6 j: 7 8)))
;; Unfortunate but correct (missing optional arg)
(assert (equal? '(3 4 i: i: #f j: 1) (test-optional&key 3 4 i: 6 j: 7 8)))

(define (test-key&rest x y #!rest r #!key i (j 1))
  (list x y i: i j: j r))

(assert (equal? '(3 4 i: 5 j: 1 (i: 5 6 7)) (test-key&rest 3 4 i: 5 6 7)))
(assert (equal? '(3 4 i: 5 j: 6 (i: 5 j: 6 7 8))
                (test-key&rest 3 4 i: 5 j: 6 7 8)))

(define (test-optional-key&rest x y #!optional z #!rest r #!key i (j 1))
  (list x y z i: i j: j r))

(assert (equal? '(3 4 5 i: 6 j: 7 (i: 6 j: 7 8))
                (test-optional-key&rest 3 4 5 i: 6 j: 7 8)))

;;; Miscellaneous DSSSL tests

;; DSSSL annotations may each appear only once
(f (eval '(lambda (x #!optional o1 #!optional o2) 'foo)))
(f (eval '(lambda (x #!rest r1 #!rest r1) 'foo)))
(f (eval '(lambda (x #!key k1 #!key k2) 'foo)))

;; DSSSL annotations must occur in order (optional, rest, key)
(f (eval '(lambda (x #!rest r1 #!optional o1) 'foo)))
(f (eval '(lambda (x #!key k1 #!optional o1) 'foo)))
(f (eval '(lambda (x #!key r1 #!rest k1) 'foo)))

;; #!rest limited to 1 arg
(f (eval '(lambda (x #!rest r1 r2) 'foo)))

;; list arguments invalid for required and rest parameters
(f (eval '(lambda ((x 0) #!rest r1) 'foo)))
(f (eval '(lambda (x #!rest (r1 0)) 'foo)))

;; "optional" expansion should not rely on user imports (hygiene)
(t '(1 2)
   (eval '(module x ()
	    (import (only scheme lambda list))
	    ((lambda (x #!optional (y 0)) (list x y)) 1 2))))

;; Dotted list syntax can be mixed in
(t '(1 2 3 4 (5 6))
   ((lambda (x y #!optional o1 o2 . r) (list x y o1 o2 r))
    1 2 3 4 5 6))

;; More DSSSL hygiene issues, from #806
(module dsssl-extended-lambda-list-hygiene ()
  (import (prefix scheme s/))
  (s/define (foo #!optional bar #!rest qux #!key baz)
	    (s/list bar baz qux)))

;;; import not seen, if explicitly exported and renamed:

(module rfoo (rbar rbaz)
(import scheme)

(define (rbaz x)
  (display x)
  (newline) )

(define-syntax rbar
  (syntax-rules ()
    ((_ x) (rbaz x))))

)

(import (prefix rfoo f:))
(f:rbar 1)

;;; SRFI-2 (and-let*)

(t 1 (and-let* ((a 1)) a))
(f (eval '(and-let* ((a 1 2 3)) a)))
(t 2 (and-let* ((a 1) (b (+ a 1))) b))
(t 3 (and-let* (((or #f #t))) 3))
(f (eval '(and-let* ((or #f #t)) 1)))
(t 4 (and-let* ((c 4) ((equal? 4 c))) c))
(t #f (and-let* ((c 4) ((equal? 5 c))) (error "not reached")))
(t #f (and-let* (((= 4 5)) ((error "not reached 1"))) (error "not reached 2")))
(t 'foo (and-let* (((= 4 4)) (a 'foo)) a))
(t #f (and-let* ((a #f) ((error "not reached 1"))) (error "not reached 2")))

(t  (and-let* () 1) 1)
(t  (and-let* () 1 2) 2)
(t  (and-let* () ) #t)

(t (let ((x #f)) (and-let* (x))) #f)
(t (let ((x 1)) (and-let* (x))) 1)
(t (and-let* ((x #f)) ) #f)
(t (and-let* ((x 1)) ) 1)
(f (eval '(and-let* ( #f (x 1))) ))
(t (and-let* ( (#f) (x 1)) ) #f)
(f (eval '(and-let* (2 (x 1))) ))
(t (and-let* ( (2) (x 1)) ) 1)
(t (and-let* ( (x 1) (2)) ) 2)
(t (let ((x #f)) (and-let* (x) x)) #f)
(t (let ((x "")) (and-let* (x) x)) "")
(t (let ((x "")) (and-let* (x)  )) "")
(t (let ((x 1)) (and-let* (x) (+ x 1))) 2)
(t (let ((x #f)) (and-let* (x) (+ x 1))) #f)
(t (let ((x 1)) (and-let* (((positive? x))) (+ x 1))) 2)
(t (let ((x 1)) (and-let* (((positive? x))) )) #t)
(t (let ((x 0)) (and-let* (((positive? x))) (+ x 1))) #f)
(t (let ((x 1)) (and-let* (((positive? x)) (x (+ x 1))) (+ x 1)))  3)
; The uniqueness of the bindings isn't enforced
(t (let ((x 1)) (and-let* (((positive? x)) (x (+ x 1)) (x (+ x 1))) (+ x 1))) 4)

(t (let ((x 1)) (and-let* (x ((positive? x))) (+ x 1))) 2)
(t (let ((x 1)) (and-let* ( ((begin x)) ((positive? x))) (+ x 1))) 2)
(t (let ((x 0)) (and-let* (x ((positive? x))) (+ x 1))) #f)
(t (let ((x #f)) (and-let* (x ((positive? x))) (+ x 1))) #f)
(t (let ((x #f)) (and-let* ( ((begin x)) ((positive? x))) (+ x 1))) #f)

(t  (let ((x 1)) (and-let* (x (y (- x 1)) ((positive? y))) (/ x y))) #f)
(t  (let ((x 0)) (and-let* (x (y (- x 1)) ((positive? y))) (/ x y))) #f)
(t  (let ((x #f)) (and-let* (x (y (- x 1)) ((positive? y))) (/ x y))) #f)
(t  (let ((x 3)) (and-let* (x (y (- x 1)) ((positive? y))) (/ x y))) 3/2)

;;; SRFI-26

;; Cut
(t '() ((cut list)))
(t '() ((cut list <...>)))
(t '(1) ((cut list 1)))
(t '(1) ((cut list <>) 1))
(t '(1) ((cut list <...>) 1))
(t '(1 2) ((cut list 1 2)))
(t '(1 2) ((cut list 1 <>) 2))
(t '(1 2) ((cut list 1 <...>) 2))
(t '(1 2 3 4) ((cut list 1 <...>) 2 3 4))
(t '(1 2 3 4) ((cut list 1 <> 3 <>) 2 4))
(t '(1 2 3 4 5 6) ((cut list 1 <> 3 <...>) 2 4 5 6))
(t '(ok) (let* ((x 'wrong)
                (y (cut list x)))
           (set! x 'ok)
           (y)))
(t 2 (let ((a 0))
       (map (cut + (begin (set! a (+ a 1)) a) <>)
            '(1 2))
       a))
(f (eval '((cut + <...> 1) 1)))

;; Cute
(t '() ((cute list)))
(t '() ((cute list <...>)))
(t '(1) ((cute list 1)))
(t '(1) ((cute list <>) 1))
(t '(1) ((cute list <...>) 1))
(t '(1 2) ((cute list 1 2)))
(t '(1 2) ((cute list 1 <>) 2))
(t '(1 2) ((cute list 1 <...>) 2))
(t '(1 2 3 4) ((cute list 1 <...>) 2 3 4))
(t '(1 2 3 4) ((cute list 1 <> 3 <>) 2 4))
(t '(1 2 3 4 5 6) ((cute list 1 <> 3 <...>) 2 4 5 6))
(t 1 (let ((a 0))
       (map (cute + (begin (set! a (+ a 1)) a) <>)
            '(1 2))
       a))
(f (eval '((cute + <...> 1) 1)))

;;; (quasi-)quotation

(f (eval '(let ((a 1)) (unquote a))))
(t 'unquote (quasiquote unquote))
(f (eval '(quasiquote (a unquote . 1)))) ; "Bad syntax". Also ok: '(a unquote . 1)
(t 'a (quasiquote a))
(f (eval '(quasiquote a b)))
(f (eval '(quote a b)))
(f (eval '(quasiquote)))
(f (eval '(quote)))
(f (eval '(quasiquote . a)))
(f (eval '(quote . a)))
(t '(foo . 1) (let ((bar 1))
                (quasiquote (foo . (unquote bar)))))
(f (eval '(let ((a 1)
                (b 2))
            (quasiquote (unquote a b))))) ; > 1 arg

(t '(quasiquote (unquote a)) (quasiquote (quasiquote (unquote a))))
(t '(quasiquote x y) (quasiquote (quasiquote x y)))

(t '(unquote-splicing a) (quasiquote (unquote-splicing a)))
(t '(1 2) (let ((a (list 2))) (quasiquote (1 (unquote-splicing a)))))
(f (eval '(let ((a 1))                  ; a is not a list
            (quasiquote (1 (unquote-splicing a) 2)))))
(f (eval '(let ((a (list 1))
                (b (list 2)))
            (quasiquote (1 (unquote-splicing a b)))))) ; > 1 arg

;; level counting
(define x (list 1 2))

;; Testing R5RS-compliance:
(t '(quasiquote (unquote (1 2)))
   (quasiquote (quasiquote (unquote (unquote x)))))
(t '(quasiquote (unquote-splicing (1 2)))
   (quasiquote (quasiquote (unquote-splicing (unquote x)))))
(t '(quasiquote (unquote 1 2))
   (quasiquote (quasiquote (unquote (unquote-splicing x)))))
(t 'x
   (quasiquote (unquote (quasiquote x))))
(t '(quasiquote (unquote-splicing (quasiquote (unquote x))))
   (quasiquote (quasiquote (unquote-splicing (quasiquote (unquote x))))))
(t '(quasiquote (unquote (quasiquote (unquote-splicing x))))
   (quasiquote (quasiquote (unquote (quasiquote (unquote-splicing x))))))
(t '(quasiquote (unquote (quasiquote (unquote (1 2)))))
   (quasiquote (quasiquote (unquote (quasiquote (unquote (unquote x)))))))

;; The following are explicitly left undefined by R5RS. For consistency
;; we define any unquote-(splicing) or quasiquote that occurs in the CAR of
;; a pair to decrease, respectively increase the level count by one.
  
(t '(quasiquote . #(1 (unquote x) 3))   ; cdr is not a pair
   (quasiquote (quasiquote . #(1 (unquote x) 3))))
(t '(quasiquote #(1 (unquote x) 3))     ; cdr is a list of one
   (quasiquote (quasiquote #(1 (unquote x) 3))))
(t '(quasiquote a #(1 (unquote x) 3) b) ; cdr is longer
   (quasiquote (quasiquote a #(1 (unquote x) 3) b)))

(t '(quasiquote (unquote . #(1 (1 2) 3))) ; cdr is not a pair
   (quasiquote (quasiquote (unquote . #(1 (unquote x) 3)))))
(t '(quasiquote (unquote #(1 (1 2) 3))) ; cdr is a list of one
   (quasiquote (quasiquote (unquote #(1 (unquote x) 3)))))
(t '(quasiquote (unquote a #(1 (1 2) 3) b)) ; cdr is longer
   (quasiquote (quasiquote (unquote a #(1 (unquote x) 3) b))))

(t '(quasiquote (unquote-splicing . #(1 (1 2) 3))) ; cdr is not a pair
   (quasiquote (quasiquote (unquote-splicing . #(1 (unquote x) 3)))))
(t '(quasiquote (unquote-splicing #(1 (1 2) 3))) ; cdr is a list of one
   (quasiquote (quasiquote (unquote-splicing #(1 (unquote x) 3)))))
(t '(quasiquote (unquote-splicing a #(1 (1 2) 3) b)) ; cdr is longer
   (quasiquote (quasiquote (unquote-splicing a #(1 (unquote x) 3) b))))

(t 'quasiquote (quasiquote quasiquote))
(t 'unquote (quasiquote unquote))
(t 'unquote-splicing (quasiquote unquote-splicing))
(t '(x quasiquote) (quasiquote (x quasiquote)))
; (quasiquote (x unquote)) is identical to (quasiquote (x . (unquote)))....
;; It's either this (error) or make all calls to unquote with more or less
;; than one argument resolve to a literal unquote.
(f (eval '(quasiquote (x unquote))))
(t '(x unquote-splicing) (quasiquote (x unquote-splicing)))
;; Let's internal defines properly compared to core define procedure when renamed
(f (eval '(let-syntax ((foo (syntax-rules () ((_ x) (begin (define x 1))))))
            (let () (foo a))
            (print "1: " a))))

(t '(a 1) (letrec-syntax ((define (syntax-rules () ((_ x y) (list 'x y))))
                          (foo (syntax-rules () ((_ x) (define x 1)))))
            (let () (foo a))))

(t '(1) (let-syntax ((define (syntax-rules () ((_ x) (list x)))))
          (let () (define 1))))

;; Local override: not a macro
(t '(1) (let ((define list)) (define 1)))

;; Toplevel (no SE)
(define-syntax foo (syntax-rules () ((_ x) (begin (define x 1)))))
(foo a)
(t 1 a)


;; ,@ in tail pos with circular object - found in trav2 benchmark and
;; reported by syn:

(let ((a '(1)))
  (set-cdr! a a)
  `(1 ,@a))


;; ##sys#alias-global-hook, when invoked via eval/meta, did resolve identifiers
;; used during evaluation of an expander body in the wrong environment and mapped
;; an identifier to something imported for the runtime environment

(module foonumbers (+)
  (import (except scheme +) (only (chicken base) error))
  (define (+ . _) (error "failed.")))

(import foonumbers)

(define-syntax foo
  (er-macro-transformer
   (lambda (x r c)
     `(print ,(+ (cadr x) 1)))))

(foo 3)


;; #578: import with specifier has no effect for internal modules on csi's top-level

(import srfi-4)
(import (prefix srfi-4 other-))
u8vector
other-u8vector

(import (prefix scheme other-))
eval
other-eval


;; #805: case-lambda is unhygienic (see 4706afb4 and bc5cc698)
(module case-lambda-and-ensure-hygiene ()
  (import (prefix (chicken base) c/) (prefix scheme s/))
  (c/case-lambda ((a) a)))


;; #816: compiler-syntax should obey hygiene in its rewrites
(module foo ()
  (import (prefix (only scheme map lambda list) ~))
  (~map (~lambda (y) y) (~list 1)))

;; #852: renamed macros should not be returned as first-class
;;       objects in the interpreter
(module renamed-macros (renamed-macro-not-firstclassed)
  (import scheme chicken.base)
  (define-syntax renamed-macro-not-firstclassed
    (er-macro-transformer
     (lambda (e r c)
       `(,(r 'list) ,(r 'define))))))

(f (eval '(begin (import renamed-macros) (renamed-macro-not-firstclassed))))

;; #893: implicitly renamed variables shouldn't be resolved to core
;;       builtins (#%xyz), but go through a level of indirection, so
;;       strip-syntax can still access the original symbol.
(module rename-builtins
 (strip-syntax-on-*)
 (import scheme chicken.base)
 (define-syntax strip-syntax-on-*
   (ir-macro-transformer
    (lambda (e r c) '(quote *)))))

(import rename-builtins)
(assert (eq? '* (strip-syntax-on-*)))

;; #1362: Double rename would cause "renamed" var to be restored to
;; the original macro aliased name (resulting in a plain symbol)
(let-syntax ((wrapper/should-do-nothing
              (er-macro-transformer
               (lambda (e r c)
                 (let* ((%x (r 'x))
                        (%%x (r %x)))
                   `(let ((,%x 1)
                          (,%%x 2))
                      ,(cadr e)))))))
  (print (let ((x 1)) (wrapper/should-do-nothing x))))

;; Same net effect as above, but more complex by the use of IR macros.
(letrec-syntax ((bind-pair
                 (ir-macro-transformer
                  (lambda (e i c)
                    (let* ((b (cadr e))
                           (exp (caddr e))
                           (body (cdddr e)))
                      `(let* ((x ,exp)
                              (,(car b) (car x))
                              (,(cadr b) (cdr x)))
                         ,@body)))))
                (foo
                 (ir-macro-transformer
                  (lambda (e i c)
                    `(bind-pair (x y) (cons 'foo-car 'foo-cdr) y)))))
  (assert (eq? 'second (bind-pair (x y) (cons 'first 'second) y)))
  (assert (eq? 'foo-cdr (foo))))

;; #944: macro-renamed defines mismatch with the names recorded in module
;;       definitions, causing the module to be unresolvable.

(module foo ()
  (import scheme)
  (define-syntax bar
    (syntax-rules ()
      ((_) (begin (define req 1) (display req) (newline)))))
  (bar))

;; The fix for the above bug causes the req to be defined at toplevel,
;; unhygienically.  The test below should probably be enabled and this
;; behavior fixed.  R5RS seems to allow the current behavior though (?),
;; and some Schemes (at least Gauche) behave the same way.  I think it's
;; broken, since it's unhygienic.
#;(module foo ()
  (import scheme)
  (define req 1)
  (define-syntax bar
    (syntax-rules ()
      ((_) (begin (define req 2) (display req) (newline)))))
  (bar)
  (assert (eq? req 1)))


;; Includes should be spliced into the surrounding body context:

(begin-for-syntax
  (with-output-to-file "x.out" (cut pp '(define x 2))))

(let ()
  (define x 1)
  (include "x.out")
  (t 2 x))

(let ()
  (define x 1)
  (let ()
    (include "x.out"))
  (t 1 x))

;; letrec vs. letrec*

;;XXX this fails - the optimizer substitutes "foo" for it's known constant value
#;(t (void) (letrec ((foo 1)
		   (bar foo))
	    bar))

;; Obscure letrec issue #1068
(t 1 (letrec ((foo (lambda () 1))
	      (bar (let ((tmp (lambda (x) (if x (foo) (bar #t)))))
		     tmp)))
       (bar #f)))

;; Deeper issue uncovered by fixing the above issue 
(t 1 (letrec ((bar (lambda (x) (if x 1 (bar bar)))))
       (bar #f)))

;; Just to verify (this has always worked)
(t 1 (letrec* ((foo (lambda () 1))
	       (bar (let ((tmp (lambda (x) (if x (foo) (bar #t)))))
		      tmp)))
       (bar #f)))

(t 1 (letrec* ((foo 1)
	       (bar foo))
       bar))


;; This would crash in nasty ways (see #1493, reported by megane)
(module self-redefinition (foo)
  (import scheme (chicken base))

  (define-syntax foo
    (ir-macro-transformer
     (lambda (e i c)
       (apply
	(lambda (name)
	  `(begin
	     (define-syntax ,(strip-syntax name)
	       (syntax-rules () ((_ . _) 'new)))
	     'old))
	(cdr e))))))

(import (rename self-redefinition (foo imported-foo)))
(import (rename self-redefinition (foo reimported-foo)))

(t 'old (imported-foo imported-foo))
(t 'new (imported-foo imported-foo))

;; Like any normal redefinition, the underlying exported identifier
;; changes, and any other imports are simply aliases.
;;(t 'old (reimported-foo reimported-foo))
(t 'new (reimported-foo reimported-foo))

;; #1166
(module val-vs-syn1 *
  (import scheme)
  (define-syntax bar (syntax-rules () ((_) 'bar)))
  (define (bar) 99)
)

(module test-val-vs-syn1 ()
   (import scheme (chicken base) val-vs-syn1)
   (assert (eq? 99 (bar))))

(module val-vs-syn2 *
  (import scheme)
  (define (bar) 99)
  (define-syntax bar (syntax-rules () ((_) 'bar)))
)

(module test-val-vs-syn2 ()
   (import scheme (chicken base) val-vs-syn2)
   (assert (eq? 'bar (bar))))

(define begin -)
(assert (eq? -1 (begin 0 1)))
