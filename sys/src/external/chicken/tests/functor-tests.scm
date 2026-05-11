;;;; functor-tests.scm


(import chicken.fixnum chicken.port chicken.pretty-print)


(include "test.scm")
(test-begin "functor tests")

;;


(include "test-queue")
(include "breadth-first")

(define (take lst n)
  (if (fx<= n 0)
      '()
      (cons (car lst) (take (cdr lst) (fx- n 1)))))


(module queue1 QUEUE
  (import (rename scheme
		  (null? empty?)
		  (car head)
		  (cdr dequeue)))
  (define empty-queue '())
  (define (enqueue q x) (append q (list x)))
  ;(define empty? null?)
  ;(define head car)
  ;(define dequeue cdr) 
  )


(module queue2 QUEUE
  (import (rename scheme (not empty?)) chicken.base)
  (define-record entry q x)
  (define empty-queue #f)
  (define enqueue make-entry)
  ;(define empty? not)
  (define (head q)
    (let ((q2 (entry-q q)))
      (if (empty? q2) (entry-x q) (head q2))))
  (define (dequeue q) 
    (let ((q2 (entry-q q)))
      (if (empty? q2) 
	  empty-queue 
	  (make-entry (dequeue q2) (entry-x q)))) ))


(module queue3 QUEUE
  (import scheme chicken.base)
  (define-record queue heads tails)
  (define empty-queue (make-queue '() '()))
  (define (norm q)
    (if (null? (queue-heads q))
	(make-queue (reverse (queue-tails q)) '())
	q))
  (define (enqueue q x)
    (norm (make-queue (queue-heads q) (cons x (queue-tails q)))))
  (define (empty? q)
    (and (null? (queue-heads q)) (null? (queue-tails q))))
  (define (head q) (car (queue-heads q)))
  (define (dequeue q)
    (norm (make-queue (cdr (queue-heads q)) (queue-tails q)))) )


(module test-q1 = (test-queue queue1))
(module test-q2 = (test-queue queue2))
(module test-q3 = (test-queue queue3))

(import (rename test-q1 (list->queue l2q1) (queue->list q2l1)))
(import (rename test-q2 (list->queue l2q2) (queue->list q2l2)))
(import (rename test-q3 (list->queue l2q3) (queue->list q2l3)))

(define (list-tabulate n proc)
  (let loop ((i 0))
    (if (fx>= i n)
	'()
	(cons (proc i) (loop (fx+ i 1))))))

(define long-list (list-tabulate (cond-expand (csi 500) (else 1000)) identity))

(print "Queue representation #1:")
(time (q2l1 (l2q1 long-list)))
(print "Queue representation #2:")
(time (q2l2 (l2q2 long-list)))
(print "Queue representation #3:")
(time (q2l3 (l2q3 long-list)))

(module breadth = (breadth-first queue3))
(import breadth)

(define (next-char lst) 
  (list (cons #\A lst) (cons #\B lst) (cons #\C lst)))

(define (show n csq) 
  (map list->string (take csq 1)))

;;XXX shows (""), which looks wrong:
(pp (show 8 (search next-char '())))	;XXX assert

;; list-style library names

(functor ((double printer) ((P (chicken base)) (print))) (print-twice)
  (import (scheme) P)
  (define (print-twice x) (print x) (print x)))

(module (noop printer) *
  (import (only (scheme) define) (only (chicken base) void))
  (define print void))

(module (2x print) = ((double printer)))

(module (2x noop) = ((double printer) (noop printer)))

(module (2x write) = (double printer)
  (import (chicken module))
  (reexport (rename (scheme) (write print))))

(define output
  (with-output-to-string
   (lambda ()
     (import (2x print))
     (print-twice #\a)
     (import (2x noop))
     (print-twice #\a)
     (import (2x write))
     (print-twice #\a))))

(test-equal "double printer" output "a\na\n#\\a#\\a")

;; Test for errors

#+csi
(begin

(module m1 ())

(test-error 
 "argument mismatch"
 (eval '(module m2 = (breadth-first m1))))

(test-error
 "undefined module"
 (eval '(module m2 = (breadth-first hunoz))))

(test-error
 "undefined interface"
 (eval '(module m2 HUNOZ)))

(test-error
 "undefined interface in functor"
 (eval '(functor (f1 (X HUNOZ)) ())))

(test-error
 "undefined interface in functor result"
 (eval '(functor (f1 (X ())) HUNOZ)))

)


;; Test alternative instantiation syntax:

(functor (frob (X (yibble))) *
  (import chicken.base X)
  yibble)

;; XXX This is somewhat iffy: functor instantiation results in a
;; value!
(test-equal
 "alternative functor instantiation syntax"
 (module yabble = frob (import scheme) (define yibble 99))
 99)


;; Test optional functor arguments

(functor (greet ((X default-writer) (write-greeting))) *
  (import scheme X)
  (define (greetings) (write-greeting 'Hello!)))

(module default-writer (write-greeting)
  (import scheme)
  (define write-greeting list))

(module writer (write-greeting)
  (import scheme)
  (define write-greeting vector))

(module greet1 = (greet writer))
(module greet2 = (greet))

(test-equal
 "optional functor argument #1"
 (module m2 ()
	 (import greet1)
	 (greetings))
 '#(Hello!))

(test-equal
 "optional functor argument #2"
 (module m3 ()
	 (import greet2)
	 (greetings))
 '(Hello!))


;; Optional functor syntax with builtin ("primitive") modules:

(functor (wrapper ((X scheme) (vector))) *
  (import (except scheme vector) X)
  (define (wrap x) (vector x)))

(module default-wrapper (vector)
  (import scheme))

(module list-wrapper (vector)
  (import (rename (only scheme list) (list vector))))

(module lwrap = (wrapper list-wrapper))
(module vwrap = (wrapper))

(test-equal
 "primitive optional functor argument #1"
 (module m4 ()
	 (import lwrap)
	 (wrap 99))
 '(99))

(test-equal
 "primitive optional functor argument #2"
 (module m5 ()
	 (import vwrap)
	 (wrap 99))
 '#(99))


;; Module implementing functor plus more exports did not expose the
;; additional exports (pointed out by Martin Schneeweis, patch
;; suggested by megane)

(define-interface iface-a (some-a))

(module iface-a-plus-extra ((interface: iface-a) extra-a)
  (import scheme (chicken base))
  (define extra-a 'extra-a)
  (define some-a 'some-a))

(test-equal
 "Functor with extra exports"
 (module m6 ()
   (import iface-a-plus-extra scheme)
   (list extra-a some-a))
 '(extra-a some-a))


;;

(test-end)

(test-exit)
