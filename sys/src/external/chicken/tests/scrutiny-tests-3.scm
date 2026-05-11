;;;; scrutiny-tests-3.scm - scrutinizer-tests, compiled in block mode and executed


;;; ensure implicit global type-declarations are "smashed" (i.e. have
;;; their component types invalidated, due to possible mutation)

(define vec (make-vector 10 #f))
(vector-set! vec 0 99)
(assert
 (compiler-typecase vec
   ((vector-of boolean) #f)
   (vector #t)))


;;; reduce OR-types in alternative branch of conditional with predicate

(define something)

(let ((x (the (or string number) something)))
  (if (number? x)
      (compiler-typecase x
	(number 1))
      (compiler-typecase x
	(string 2))))

(let ((x (the (or string number) something)))
  (if (fixnum? x)
      (compiler-typecase x
	(fixnum 1))
      (compiler-typecase x
	((or string number) 2))))

(let ((x (the (forall ((a string) (b number)) (or a b)) something)))
  (if (number? x)
      (compiler-typecase x
	(number 3))
      (compiler-typecase x
	(string 4))))


;;; #1399 incorrect return type after merge with noreturn procedure

(let ((x (the (->) something))
      (y (the (-> noreturn) something)))
  (compiler-typecase (if something x y)
    ((->) (error "#1399 regression test failure"))
    (else 'ok)))
