;;;; arithmetic-test.scm
;
; - switches:
;
; use-numbers
; check
; fx-ops


(cond-expand 
  (windows
   (begin
     (print "this test can not be run on Windows")
     (exit)))
  (else))


(import (chicken condition)
	(chicken platform)
	(chicken pretty-print)
	(chicken random)
	(chicken fixnum))

(define range 2)
(define random-range 32000)
(define result '())

(define points
  (list 0 1 -1 2 -2
	most-positive-fixnum most-negative-fixnum
	(add1 most-positive-fixnum) (sub1 most-negative-fixnum)
	1103515245			; random
	631629065			; random
	;;697012302412595925 came up in test-case by Jeronimo Pellegrini
	9007199254740992   ; but these are sufficient, since they mark
	-9007199254740992 ; the precision-limit of IEEE doubles on 64-bit systems
	12345				; random
	(expt 2 32)))

(cond-expand
  (fully-random)
  (else (set-pseudo-random-seed! "abcdefgh")))

(define (push c total opname args res)
  (let ((x (list (cons c total) (cons opname args) '-> res)))
    #+(not check) (pp x)
    (set! result (cons x result))))

(define (test-permutations opname op points)
  (let* ((np (length points))
	 (nr (add1 (* range 2)))
	 (total (* np np nr nr))
	 (c 1))
    (for-each
     (lambda (x)
       (for-each
	(lambda (y)
	  (do ((i (- range) (add1 i)))
	      ((> i range))
	    (do ((j (- range) (add1 j)))
		((> j range))
	      (let* ((args (list (+ x i) (+ y j)))
		     (res 
		      (handle-exceptions ex (get-condition-property ex 'exn 'message)
			(apply op args))))
		(push c total opname args res)
		(set! c (add1 c))))))
	points))
     points)))

(define (test-random-permutations opname op points)
  (for-each
   (lambda (x)
     (for-each
      (lambda (y)
	(do ((i 10 (sub1 i)))
	    ((zero? i))
	  (let* ((args (list (+ x (pseudo-random-integer random-range)) 
                      (+ y (pseudo-random-integer random-range))))
		 (res
		  (and (cond-expand
			 (fx-ops
			  (and (fixnum? (car args))
			       (fixnum? (cadr args))))
			 (else #t))
		       (apply op args))))
	    (push opname args res))))
      points))
   points))

(for-each
 (lambda (oo)
   (let ((args (append oo (list points))))
     (apply test-permutations args)))
 (cond-expand
   (fx-ops
    `((fx+? ,fx+?)
      (fx-? ,fx-?)
      (fx*? ,fx*?)
      (fx/? ,fx/?)))
   (else
    `((+ ,+)
      (- ,-)
      (* ,*)
      (/ ,/)))))

(define (same? x y)
  (cond ((and (number? x) (number? y)) 
	 (= x y))
	((pair? x)
	 (and (pair? y)
	      (same? (car x) (car y))
	      (same? (cdr x) (cdr y))))
	((vector? x)
	 (and (vector? y)
	      (same? (vector->list x) (vector->list y))))
	(else (equal? x y))))

(set! result (reverse result))
(define errors? #f)

#+check
(load 
 (cond-expand
   (check-numbers "arithmetic-test.numbers.expected")
   (else
    (if (feature? #:64bit)
	"arithmetic-test.64.expected"
	"arithmetic-test.32.expected")))
 (lambda (x)
   (apply
    (lambda (c/total1 exp1 _ res1)
      (apply
       (lambda (c/total2 exp2 _ res2)
	 (assert (equal? c/total1 c/total2) "output differs in the number of cases"
		 c/total1 c/total2)
	 (unless (same? res1 res2)
	   (set! errors? #t)
	   (print "FAIL: " c/total1 " " exp1 " -> expected: " res1 ", but got: " res2)))
       (car result))
      (set! result (cdr result)))
    x)))

(exit (if errors? 1 0))
