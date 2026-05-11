;; weak-pointer-test.scm

(import (chicken gc) (chicken port) (chicken locative))

(include "test.scm")

;; Ensure weakly held items are not just equal to other references to it, but *identical*
(current-test-comparator eq?)

(test-group "Testing basic pair accessors work on weak pairs, too"
  (let ((my-proper-weak-list (weak-cons 1 (weak-cons 2 '())))
	(my-proper-list (cons 1 (cons 2 '())))
	(my-improper-weak-list (weak-cons 1 (weak-cons 2 3)))
	(my-improper-list (cons 1 (cons 2 3))))

    (test-assert "proper weak lists are pairs" (pair? my-proper-weak-list))
    (test-assert "improper weak lists are pairs" (pair? my-improper-weak-list))

    (test-assert "regular proper lists are not weak pairs" (not (weak-pair? my-proper-list)))
    (test-assert "regular improper lists are not weak pairs" (not (weak-pair? my-improper-list)))

    (test-assert "proper weak lists are lists" (list? my-proper-weak-list))
    (test-assert "improper weak lists are *not* lists" (not (list? my-improper-weak-list)))

    (test-equal "an weak proper list is equal to the same regular proper list" my-proper-weak-list my-proper-list equal?)
    (test-equal "an weak proper list is not *identical* to the same regular proper list" my-proper-weak-list my-proper-list (complement eq?))

    (test-equal "car of weak list returns the first item" (car my-proper-weak-list) 1)
    (test-equal "cdr of weak list returns the cdr" (cdr my-proper-weak-list) (cdr my-proper-list) equal?)
    (test-equal "cadr of weak list returns the second item" (cadr my-proper-weak-list) 2)
    (test-equal "cddr of weak list returns the cdr of the cdr" (cddr my-proper-weak-list) '())

    (test-equal "length of weak proper list returns the length" 2 (length my-proper-weak-list))
    (test-error "length of weak improper list raises an error" (length my-improper-weak-list))

    (let* ((written-proper-weak-list (with-output-to-string (lambda () (write my-proper-weak-list))))
	   (written-improper-weak-list (with-output-to-string (lambda () (write my-improper-weak-list))))
	   (reread-proper-weak-list (with-input-from-string written-proper-weak-list read))
	   (reread-improper-weak-list (with-input-from-string written-improper-weak-list read)))
      (test-equal "a proper weak list is written as a regular proper list" "(1 2)" written-proper-weak-list string=?)
      (test-equal "a proper weak list is read back as regular proper list" my-proper-list reread-proper-weak-list equal?)
      (test-equal "an improper weak list is written as a regular improper list" "(1 2 . 3)" written-improper-weak-list string=?)
      (test-equal "an improper weak list is read back as regular improper list" my-improper-list reread-improper-weak-list equal?))))

(test-group "Testing that basic weak pairs get their car reclaimed"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((not-held-onto-value (vector 42))
	 (held-onto-vector (vector 'this-one-stays))

	 (weak-list (weak-cons not-held-onto-value
			       (weak-cons (vector 'ohai)
					  (weak-cons held-onto-vector '()))))
	 (weak-immediate-pair (weak-cons 1 2)))

    ;; break other references to the values
    (set! not-held-onto-value #f)

    (gc)

    ;; First item is reclaimed
    (test-assert "first item of weak list is reclaimed" (not (vector? (car weak-list))))
    (test-assert "first item of weak list is set to the broken-weak-pointer object" (bwp-object? (car weak-list)))

    ;; Second item is reclaimed
    (test-assert "second item of weak list is reclaimed" (not (vector? (cadr weak-list))))
    (test-assert "second item of weak list is set to the broken-weak-pointer object" (bwp-object? (cadr weak-list)))

    ;; Third item stays
    (test-assert "third item of weak list is kept around due to other references existing" (vector? (caddr weak-list)))
    (test-equal "third item of weak list is identical to the other reference" (caddr weak-list) held-onto-vector)
    (test-assert "third item of weak list is not set to the broken-weak-pointer object" (not (bwp-object? (caddr weak-list))))

    (test-equal "weak car is kept around when value is an immediate" (car weak-immediate-pair) 1)
    (test-equal "weak cdr is kept around when value is an immediate" (cdr weak-immediate-pair) 2)))


(test-group "Testing that weak pairs do not get broken when holding permanent symbols"
  (gc #t) ; Improve chances we don't get a minor GC in between

  ;; NOTE: When we don't use string-append here, the strings somehow get interned as (permanent) symbols?!
  ;; Perhaps this is somehow caused by the reader.
  (let* ((sym1 (string->symbol (string-append "something" "1234")))
	 (sym2 (string->symbol (string-append "another" "1234")))
	 (weak-permanent-symbol-pair (weak-cons 'scheme#car 'scheme#cdr))
	 (weak-impermanent-symbol-pair (weak-cons sym1 sym2)))

    (set! sym1 #f)
    (set! sym2 #f)

    (gc)

    (test-equal "weak car is kept around when value is a \"permanent\" symbol" (car weak-permanent-symbol-pair) 'scheme#car)
    (test-equal "weak cdr is kept around when value is a \"permanent\" symbol" (cdr weak-permanent-symbol-pair) 'scheme#cdr)

    (test-assert "weak car is reclaimed when value is an \"impermanent\" symbol" (not (symbol? (car weak-impermanent-symbol-pair))))
    (test-assert "weak car is reclaimed when value is an \"impermanent\" symbol" (bwp-object? (car weak-impermanent-symbol-pair)))
    (test-equal "weak cdr is kept around when value is a \"impermanent\" symbol" (cdr weak-impermanent-symbol-pair) (string->symbol (string-append "an" "other1234")))))


(test-group "Testing cars of weak pairs referenced by their cdr do not get collected"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((obj-a (vector 42))
	 (ref-a (weak-cons obj-a obj-a))
	 (obj-b (vector 'ohai))
	 (ref-b (weak-cons obj-b obj-b))
	 (held-onto-vector (vector 'this-one-stays)) ; should be held onto regardless of this, but here for consistency
	 (ref-c (weak-cons held-onto-vector held-onto-vector)))

    ;; break other references to the values
    (set! obj-a #f)
    (set! obj-b #f)

    (gc)

    (test-assert "object in first weak cons is still kept around in car" (vector? (car ref-a)))
    (test-assert "object in first weak cons is still kept around in cdr" (vector? (cdr ref-a)))
    (test-equal "object in first weak cons' car is identical to its cdr" (car ref-a) (cdr ref-a))
    (test-assert "car of first weak cons is not a broken weak pair" (not (bwp-object? (car ref-a))))
    (test-assert "cdr of first weak cons is not a broken weak pair" (not (bwp-object? (cdr ref-a))))

    (test-assert "object in second weak cons is still kept around in car" (vector? (car ref-b)))
    (test-assert "object in second weak cons is still kept around in cdr" (vector? (cdr ref-b)))
    (test-equal "object in second weak cons' car is identical to its cdr" (car ref-b) (cdr ref-b))
    (test-assert "car of second weak cons is not a broken weak pair" (not (bwp-object? (car ref-b))))
    (test-assert "cdr of second weak cons is not a broken weak pair" (not (bwp-object? (cdr ref-b))))

    (test-assert "object in third weak cons is still kept around in car" (vector? (car ref-c)))
    (test-assert "object in third weak cons is still kept around in cdr" (vector? (cdr ref-c)))
    (test-equal "object in third weak cons' car is identical to its cdr" (car ref-c) (cdr ref-c))
    (test-equal "object in third weak cons' car is identical to the other reference" (car ref-c) held-onto-vector)
    (test-assert "car of third weak cons is not a broken weak pair" (not (bwp-object? (car ref-c))))
    (test-assert "cdr of third weak cons is not a broken weak pair" (not (bwp-object? (cdr ref-c))))))


(test-group "Testing that strong locatives get their object updated"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((not-held-onto-value (vector 42))
	 (held-onto-vector (vector 'this-one-stays))
	 (vec-0 (vector 0))
	 (vec-1 (vector 1))
	 (vec-2 (vector 2))

	 (nested-not-held-onto-value (vector vec-0 vec-1 vec-2))
	 (nested-held-onto-value (vector (vector 'x) (vector 'y) (vector 'z)))
	 (vec-ohai (vector 'ohai))
	 (vec-fubar (vector 'fubar))

	 (loc1 (make-locative not-held-onto-value 0))
	 (loc2 (make-locative (vector 'ohai 'fubar) 1))
	 (loc3 (make-locative held-onto-vector 0))

	 (loc4 (make-locative nested-not-held-onto-value 1))
	 (loc5 (make-locative (vector vec-ohai vec-fubar) 1))
	 (loc6 (make-locative nested-held-onto-value 1)))

    ;; break other references to the values
    (set! not-held-onto-value #f)
    (set! nested-not-held-onto-value #f)

    (gc)

    (test-equal "First locative is updated" (locative-ref loc1) 42)
    (test-equal "Second locative is updated" (locative-ref loc2) 'fubar)
    (test-equal "Third locative is updated" (locative-ref loc3) 'this-one-stays)

    (test-equal "Fourth locative is updated" (locative-ref loc4) vec-1)
    (test-equal "Fifth locative is updated" (locative-ref loc5) vec-fubar)
    (test-equal "Sixth locative is updated" (locative-ref loc6) (vector-ref nested-held-onto-value 1))))


(test-group "Testing that weak locatives get their object reclaimed"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((not-held-onto-value (vector 42))
	 (held-onto-vector (vector 'this-one-stays))
	 (vec-0 (vector 0))
	 (vec-1 (vector 1))
	 (vec-2 (vector 2))

	 (nested-not-held-onto-value (vector vec-0 vec-1 vec-2))
	 (nested-held-onto-value (vector (vector 'x) (vector 'y) (vector 'z)))
	 (vec-ohai (vector 'ohai))
	 (vec-fubar (vector 'fubar))

	 (loc1 (make-weak-locative not-held-onto-value 0))
	 (loc2 (make-weak-locative (vector 'ohai 'fubar) 1))
	 (loc3 (make-weak-locative held-onto-vector 0))

	 (loc4 (make-weak-locative nested-not-held-onto-value 1))
	 (loc5 (make-weak-locative (vector vec-ohai vec-fubar) 1))
	 (loc6 (make-weak-locative nested-held-onto-value 1)))

    ;; break other references to the values
    (set! not-held-onto-value #f)
    (set! nested-not-held-onto-value #f)

    (gc)

    (test-error "First locative is reclaimed" (locative-ref loc1))
    (test-error "Second locative is reclaimed" (locative-ref loc2))
    ;; NOTE: It seems we have to go "through" the original vector to ensure reference is kept
    (test-equal "Third locative is NOT reclaimed" (locative-ref loc3) (vector-ref held-onto-vector 0))

    (test-error "Fourth locative is reclaimed" (locative-ref loc4))
    (test-error "Fifth locative is reclaimed" (locative-ref loc5))
    (test-equal "Sixth locative is NOT reclaimed" (locative-ref loc6) (vector-ref nested-held-onto-value 1))))


(test-group "Testing that weak pairs get invalidated before finalizing would-be garbage"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((not-held-onto-value (vector 42))
	 (held-onto-value (vector 99))
	 (garbage-a (vector (weak-cons not-held-onto-value '()) (weak-cons held-onto-value '()) #f))
	 (garbage-b (vector (weak-cons not-held-onto-value '()) (weak-cons held-onto-value '()) #f))

	 (garbage-a-weak-ref (weak-cons garbage-a '()))
	 (garbage-b-weak-ref (weak-cons garbage-b '()))

	 (observed-garbage-a-0 #f)
	 (observed-garbage-a-1 #f)
	 (observed-garbage-a-2 #f)
	 (observed-garbage-b-0 #f)
	 (observed-garbage-b-1 #f)
	 (observed-garbage-b-2 #f))

    ;; Garbage weakly references eachother
    (vector-set! garbage-a 2 (weak-cons garbage-b '()))
    (vector-set! garbage-b 2 (weak-cons garbage-a '()))

    (set-finalizer! garbage-a (lambda (vec)
				(set! observed-garbage-a-0 (car (vector-ref vec 0)))
				(set! observed-garbage-a-1 (car (vector-ref vec 1)))
				(set! observed-garbage-a-2 (car (vector-ref vec 2)))))
    (set-finalizer! garbage-b (lambda (vec)
				(set! observed-garbage-b-0 (car (vector-ref vec 0)))
				(set! observed-garbage-b-1 (car (vector-ref vec 1)))
				(set! observed-garbage-b-2 (car (vector-ref vec 2)))))

    (set! not-held-onto-value #f)
    (set! garbage-a #f)
    (set! garbage-b #f)

    ;; Must be a major collection, finalizers don't get queued on minor GC
    ;; (gc #t)
    ;; NOTE: The above won't work because it triggers *another* GC after running finalizers,
    ;; which would invalidate all weak pairs anyway.  So instead, we create garbage until
    ;; the finalizers have run.  This is more like what happens in a regular program.
    (let lp ()
      (unless (and observed-garbage-a-0 observed-garbage-b-0)
	(make-vector 1000)
	(lp)))

    (test-assert "Weak pair's car which pointed to first garbage contains broken weak pointer" (bwp-object? (car garbage-a-weak-ref)))
    (test-assert "Weak pair's car in first garbage which pointed to collected object contains broken weak pointer" (bwp-object? observed-garbage-a-0))
    (test-equal "Weak pair's car in first garbage which pointed to retained object contains the original object" observed-garbage-a-1 held-onto-value)
    (test-assert "Weak pair's car in first garbage which pointed to second garbage contains broken weak pointer" (bwp-object? observed-garbage-a-2))
    (test-assert "Weak pair's car which pointed to second garbage contains broken weak pointer" (bwp-object? (car garbage-b-weak-ref)))
    (test-assert "Weak pair's car in second garbage which pointed to collected object contains broken weak pointer" (bwp-object? observed-garbage-b-0))
    (test-equal "Weak pair's car in second garbage which pointed to retained object contains the original object" observed-garbage-b-1 held-onto-value)
    (test-assert "Weak pair's car in second garbage which pointed to first garbage contains broken weak pointer" (bwp-object? observed-garbage-b-2))))


;; Safe version of locative-ref, returns !#bwp instead of raising an exception
(define (weak-locative-ref loc)
  (condition-case (locative-ref loc)
    ((exn type) #!bwp)))

(test-group "Testing that weak locatives get invalidated before finalizing would-be garbage"
  (gc #t) ; Improve chances we don't get a minor GC in between
  (let* ((not-held-onto-value (vector (vector 42)))
	 (held-onto-value (vector (vector 99)))
	 (garbage-a (vector (make-weak-locative not-held-onto-value 0) (make-weak-locative held-onto-value 0) #f))
	 (garbage-b (vector (make-weak-locative not-held-onto-value 0) (make-weak-locative held-onto-value 0) #f))

	 (garbage-a-weak-ref (make-weak-locative garbage-a 0))
	 (garbage-b-weak-ref (make-weak-locative garbage-b 0))

	 (observed-garbage-a-0 #f)
	 (observed-garbage-a-1 #f)
	 (observed-garbage-a-2 #f)
	 (observed-garbage-b-0 #f)
	 (observed-garbage-b-1 #f)
	 (observed-garbage-b-2 #f))

    ;; Garbage weakly references eachother
    (vector-set! garbage-a 2 (make-weak-locative garbage-b 0))
    (vector-set! garbage-b 2 (make-weak-locative garbage-a 0))

    (set-finalizer! garbage-a (lambda (vec)
				(set! observed-garbage-a-0 (weak-locative-ref (vector-ref vec 0)))
				(set! observed-garbage-a-1 (weak-locative-ref (vector-ref vec 1)))
				(set! observed-garbage-a-2 (weak-locative-ref (vector-ref vec 2)))))
    (set-finalizer! garbage-b (lambda (vec)
				(set! observed-garbage-b-0 (weak-locative-ref (vector-ref vec 0)))
				(set! observed-garbage-b-1 (weak-locative-ref (vector-ref vec 1)))
				(set! observed-garbage-b-2 (weak-locative-ref (vector-ref vec 2)))))

    (set! not-held-onto-value #f)
    (set! garbage-a #f)
    (set! garbage-b #f)

    ;; Must be a major collection, finalizers don't get queued on minor GC
    ;; (gc #t)
    ;; NOTE: The above won't work because it triggers *another* GC after running finalizers,
    ;; which would invalidate all weak pairs anyway.  So instead, we create garbage until
    ;; the finalizers have run.  This is more like what happens in a regular program.
    (let lp ()
      (unless (and observed-garbage-a-0 observed-garbage-b-0)
	(make-vector 1000)
	(lp)))

    (test-assert "Weak locative which pointed to first garbage contains broken weak pointer" (bwp-object? (weak-locative-ref garbage-a-weak-ref)))
    (test-assert "Weak locative in first garbage which pointed to collected object contains broken weak pointer" (bwp-object? observed-garbage-a-0))
    (test-equal "Weak locative in first garbage which pointed to retained object contains the original object" observed-garbage-a-1 (vector-ref held-onto-value 0))
    (test-assert "Weak locative in first garbage which pointed to second garbage contains broken weak pointer" (bwp-object? observed-garbage-a-2))
    (test-assert "Weak locative which pointed to second garbage contains broken weak pointer" (bwp-object? (weak-locative-ref garbage-b-weak-ref)))
    (test-assert "Weak locative in second garbage which pointed to collected object contains broken weak pointer" (bwp-object? observed-garbage-b-0))
    (test-equal "Weak locative in second garbage which pointed to retained object contains the original object" observed-garbage-b-1 (vector-ref held-onto-value 0))
    (test-assert "Weak locative in second garbage which pointed to first garbage contains broken weak pointer" (bwp-object? observed-garbage-b-2))))

(test-exit)
