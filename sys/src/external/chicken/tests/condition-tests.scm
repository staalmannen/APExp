(import (chicken condition))

(define condition1 (make-property-condition 'exn 'message "foo" 'arguments '("bar") 'location 'test))
(define condition2 (make-property-condition 'sam 'age 23 'partner "max"))
(define condition3 (make-composite-condition (make-property-condition 'exn 'message "foo" 'arguments '("bar") 'location 'test)(make-property-condition 'sam 'age 23 'partner "max")))

(define conditions (list condition1 condition2 condition3))

; testing type predicate
(for-each (lambda (c) (assert (condition? c))) conditions)

;testing slot allocations
; slot 1 should be the kind key
; slot 2 should hold all properties

(assert (and (equal? '(exn) (##sys#slot condition1 1))
	     (equal? '(sam) (##sys#slot condition2 1))
	     (equal? '(exn sam) (##sys#slot condition3 1))))

(assert (equal? (##sys#slot condition1 2)
		'((exn . message) "foo" (exn . arguments) ("bar") (exn . location) test)))

(assert (equal? (##sys#slot condition3 2)
		'((exn . message) "foo" (exn . arguments) ("bar") (exn . location) test
		  (sam . age) 23 (sam . partner) "max")))

;testing condition conversion

(assert (equal? (condition->list condition1)
		'((exn message "foo" arguments ("bar") location test))))

(assert (equal? (condition->list condition3)
		'((exn message "foo" arguments ("bar") location test)
		  (sam age 23 partner "max"))))

;; testing errno in condition objects

(import (chicken errno)
        (chicken file)
        (chicken process-context))

(let ((nonexistent-path "this/path/does/not/exist/,hopefully"))
  (assert (not (file-exists? nonexistent-path)))

  (handle-exceptions exn
    (assert (= (get-condition-property exn 'exn 'errno) errno/noent))
    (delete-file nonexistent-path))

  (handle-exceptions exn
    (assert (= (get-condition-property exn 'exn 'errno) errno/noent))
    (change-directory nonexistent-path)))
