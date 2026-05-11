;;;; scrutiny-tests.scm

(define (a)
  (define (b)
    (define (c)
      (let ((x (+ 3 4)))
	(if x 1 2)))))			; expected boolean but got number in conditional

(define (b)
  (let ((x #t))
    (if x 1 2)))			; #t is always true

(define (foo x)
  (if x 				; branches return differing number of results
      (values 1 2)
      (values 1 2 (+ (+ (+ (+  3)))))))

(let ((bar +))
  (bar 3 'a))				; expected number, got symbol

(string?)				; expected 1 argument, got 0

(print (values 1 2))			; expected 1 result, got 2
(print (values))			; expected 1 result, got 0

(let ((x 100))
  (x))					; expected procedure, got fixnum

(print (+ 'a 'b))			; expected 2 numbers, but got symbols

(set! car 33)				; 33 does not match type of car

((values 1 2))				; expected procedure, got fixnum (canonicalizes to 1 result)

; this should *not* signal a warning:
(define (test-values x)
  (define (fail) (error "failed"))
  (if x
      (values 42 43)
      (fail)))

; same case, but nested
(define (test-values2 x y)
  (define (fail) (error "failed"))
  (if x
      (values 42 43)
      (if y (values 99 100) (fail))))

(define (foo)
  (define (bar) (if foo 1))		; should not warn (local)
  (for-each void '(1 2 3))		; should not warn (self-call)
  (if foo 2)				; not in tail position
  (if bar 3))				; should warn

;; noreturn conditional branch enforces "number" on x
(define (foo2 x)
  (if (string? x) (error "foo") (+ x 3))
  (string-append x "abc"))

;; implicit declaration of foo3
(declare (hide foo3))

(define (foo3 x)
  (string-append x "abc"))

(foo3 99)

;; predicate
(define (foo4 x)
  (if (string? x)
      (+ x 1)
      (+ x 2)))				; ok

;; enforcement
(define (foo5 x)
  (string-append x "abc")
  (+ x 3))

;; aliasing
(define (foo6 x)
  (let ((y x))
    (string-append x "abc")
    (+ x 3)))				;XXX (+ y 3) does not work yet

;; user-defined predicate
(: foo7 (* -> boolean : string))
(define (foo7 x) (string? x))

(when (foo7 x)
  (+ x 1))				; will warn about "x" being a string

;; declared procedure types are enforcing
(define-type s2s (string -> symbol))

(: foo8 s2s)
(define (foo8 x) (string->symbol x))
(: foo9 s2s)
(declare (enforce-argument-types foo9))
(define (foo9 x) (string->symbol x))

(define (foo10 x)
  (foo8 x)
  (+ x 1)			; foo8 does not enforce x (no warning)
  (foo9 x)			; + enforces number on x
  (+ x 1))			; foo9 does enforce

;; trigger warnings for incompatible types in "the" forms
(define (foo10 x)
  (string-append (the pair (substring x 0 10))) ; 1
  (the * (values 1 2))				; 1 + 2
  (the * (values))				; 3
  (the fixnum (* x y)))				; nothing (but warns about "x" being string)


;; Reported by Joerg Wittenberger:
;
; - assignment inside first conditional does not invalidate blist
;;  entries for "ins"/"del" in outer flow.

(define (write-blob-to-sql sql identifier last blob c-c)
 (define ins '())
 (define del '())
 (if (vector? blob)
     (begin
	(set! ins (vector-ref blob 1))
	(set! del (vector-ref blob 2))
	(set! blob (vector-ref blob 0))))
 (if (or (pair? ins)
	 (pair? del))
     (<handle-ins-and-del>))
 (<do-some-more>))

;; Checking whether reported line numbers inside modules are correct
(module foo (blabla)
  (import scheme)
  (define (blabla)
    (+ 1 'x)))

;; Reported by megane in #884:
;;
;; Custom types defined in modules need to be resolved during canonicalization
(module bar ()
  (import scheme chicken.type)
  (define-type footype string)
  (the footype "bar"))

;; Record type tags with module namespaces should not warn (#1513)
(module foo *
  (import (scheme) (chicken base) (chicken type))
  (: make-foo (string --> (struct foo)))
  (define-record foo bar))

(: deprecated-procedure deprecated)
(define (deprecated-procedure x) (+ x x))
(deprecated-procedure 1)

(: another-deprecated-procedure (deprecated replacement-procedure))
(define (another-deprecated-procedure x) (+ x x))
(another-deprecated-procedure 2)

;; Needed to use "over-all-instantiations" or matching "vector"/"list" type
;; with "vector-of"/"list-of" type (reported by megane)
(: apply1 (forall (a b) (procedure ((procedure (#!rest a) b) (list-of a)) b)))

(define (apply1 f args)
  (apply f args))

(apply1 + (list 'a 2 3)) ; <- no type warning (#948)
(apply1 + (cons 'a (cons 2 (cons 3 '())))) ; <- same here (#952)

;; multiple-value return syntax
(: mv (-> . *))
(: mv (procedure () . *))

;; procedures from the type environment should still enforce, etc.
(let ((x (the (or fixnum string) _))
      (f (the (forall (a)
                (a -> (-> a)))
              (lambda (a)
                (lambda () a)))))
  (((f +)) x)  ; (or fixnum string) -> fixnum
  (fixnum? x)) ; should report

;; typeset reduction

(: char-or-string? (* -> boolean : (or char string)))

(let ((x _))
  (if (char-or-string? x)
      (symbol? x)   ; should report with x = (or char string)
      (string? x))) ; should report with x = (not (or char string))

(let ((x (the fixnum _)))
  (if (char-or-string? x)
      (symbol? x)   ; should report with x = (or char string)
      (string? x))) ; should report with x = fixnum

(let ((x (the (or char symbol) _)))
  (if (char-or-string? x)
      (symbol? x)   ; should report with x = char
      (string? x))) ; should report with x = symbol

(let ((x (the (or char symbol string) _)))
  (if (char-or-string? x)
      (symbol? x)   ; should report with x = (or char string)
      (string? x))) ; should report with x = symbol

;; list- and pair-type argument matching

(let ((f (the (pair -> *) _))) (f (list)))        ; warning
(let ((f (the (pair -> *) _))) (f (make-list x))) ; no warning
(let ((f (the (null -> *) _))) (f (list 1)))      ; warning
(let ((f (the (null -> *) _))) (f (make-list x))) ; no warning
(let ((f (the (list -> *) _))) (f (cons 1 2)))    ; warning
(let ((f (the (list -> *) _))) (f (cons 1 x)))    ; no warning


;; Indexing into vectors or lists of known size.
(let ((v1 (vector 'a 'b 'c)))
  (define (vector-ref-warn1) (vector-ref v1 -1))
  ;; After the first expression, v1's type is smashed to (vector * * *)!
  (define (vector-ref-warn2) (vector-ref v1 3))
  (define (vector-ref-warn3) (vector-ref v1 4))
  (define (vector-ref-nowarn1) (vector-ref v1 0))
  (define (vector-ref-nowarn2) (vector-ref v1 2))
  (define (vector-ref-standard-warn1) (vector-ref v1 'bad))
  (define (vector-set!-warn1) (vector-set! v1 -1 'whatever))
  (define (vector-set!-warn2) (vector-set! v1 3 'whatever))
  (define (vector-set!-warn3) (vector-set! v1 4 'whatever))
  (define (vector-set!-nowarn1) (vector-set! v1 0 'whatever))
  (define (vector-set!-nowarn2) (vector-set! v1 2 'whatever))
  (define (vector-set!-standard-warn1) (vector-set! v1 'bad 'whatever)))

;; The specific list type will be smashed to just "(or pair null)"
;; after the first operation.  This is why the let is repeated;
;; otherwise we won't get the warnings for subsequent references.
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-warn1) (list-ref l1 -1)))
;; This warns regardless of not knowing the length of the list
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-warn2) (list-ref l2 -1)))
;; Not knowing the length of a "list-of" is not an issue here
(let ((l3 (the (list-of symbol) '(x y z))))
  (define (list-ref-warn3) (list-ref l3 -1)))
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-warn4) (list-ref l1 3)))
;; This can't warn: it strictly doesn't know the length of the list.
;; The eval could return a list of length >= 1!
#;(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-warn5) (list-ref l2 3)))
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-warn5) (list-ref l1 4)))
;; Same as above
#;(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-warn6) (list-ref l2 4)))

;; We add the second check to ensure that we don't give false warnings
;; for smashed types, because we don't know the original size.
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-nowarn1) (list-ref l1 0))
  (define (list-ref-nowarn2) (list-ref l1 0)))
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-nowarn3) (list-ref l2 0))
  (define (list-ref-nowarn4) (list-ref l2 0)))
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-nowarn5) (list-ref l1 2))
  (define (list-ref-nowarn6) (list-ref l1 2)))
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-nowarn7) (list-ref l2 2))
  (define (list-ref-nowarn8) (list-ref l2 2)))
;; Verify that we don't give bogus warnings, like mentioned above.
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-nowarn9) (list-ref l2 5)))
;; We don't know the length of a "list-of", so we can't warn
(let ((l3 (the (list-of symbol) '(x y z))))
  (define (list-ref-nowarn10) (list-ref l3 100)))

;; The second check here should still give a warning, this has
;; nothing to do with component smashing.
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-standard-warn1) (list-ref l1 'bad))
  (define (list-ref-standard-warn2) (list-ref l1 'bad)))
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-standard-warn3) (list-ref l2 'bad))
  (define (list-ref-standard-warn4) (list-ref l2 'bad)))

;; Test type preservation of list-ref
(let ((l1 (list 'a 'b 'c)))
  (define (list-ref-type-warn1) (add1 (list-ref l1 1))))
(let ((l2 (cons 'a (cons 'b (cons 'c (eval '(list)))))))
  (define (list-ref-type-warn2) (add1 (list-ref l2 1))))
;; This is handled by the list-ref entry in types.db, *not* the
;; special-cased code.
(let ((l3 (the (list-of symbol) '(a b c))))
  (define (list-ref-type-warn3) (add1 (list-ref l3 1))))

;; Sanity check
(let ((l1 (list 1 2 3)))
  (define (list-ref-type-nowarn1) (add1 (list-ref l1 1))))
(let ((l2 (cons 1 (cons 2 (cons 3 (eval '(list)))))))
  (define (list-ref-type-nowarn2) (add1 (list-ref l2 1))))
(let ((l3 (the (list-of fixnum) '(1 2 3))))
  (define (list-ref-type-nowarn3) (add1 (list-ref l3 1))))

;; Test type preservation of append (TODO: decouple from list-ref)
(let ((l1 (append (list 'x 'y) (list 1 2 (eval '(list))))))
  (define (append-result-type-warn1) (add1 (list-ref l1 1))))
;; This currently doesn't warn because pair types aren't joined yet
#;(let ((l2 (append (cons 'x (cons 'y (eval '(list)))) (list 'x 'y))))
  (define (append-result-type-warn2) (add1 (list-ref l2 1))))
(let ((l3 (append (the (list-of symbol) '(x y)) '(a b))))
  (define (append-result-type-warn2) (add1 (list-ref l3 3))))

(let ((l1 (append (list 1 2) (list 'x 'y (eval '(list))))))
  (define (append-result-type-nowarn1) (add1 (list-ref l1 1))))
(let ((l2 (append (cons 1 (cons 2 (eval '(list)))) (list 'x))))
  (define (append-result-type-nowarn2) (add1 (list-ref l2 1))))
(let ((l3 (append (the (list-of fixnum) '(1 2)) '(x y))))
  (define (append-result-type-nowarn3) (add1 (list-ref l3 1))))

;; Check the trail is restored from the combined typeenv
(compiler-typecase (list 2 'a)
  ((forall (x) (list x x)) 1)
  (else #t))
