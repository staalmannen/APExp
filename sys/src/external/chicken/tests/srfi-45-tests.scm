;;; Tests adapted from SRFI 45 (for "lazy" -> "delay-force").
;;; That SRFI Copyright (C) André van Tonder (2003).

(import (only chicken.format printf)
        (only chicken.port with-output-to-string))

(define *errors* 0)

(define-syntax test
  (syntax-rules ()
    ((_ name expect form)
     (let ((ok (equal? expect form)))
       (printf "(~a) ~a~n" (if ok "PASS" "FAIL") name)
       (when (not ok) (set! *errors* (add1 *errors*)))))))

(define-syntax output
  (syntax-rules ()
    ((_ . body) (with-output-to-string (lambda () . body)))))

(test "Memoization test 1"
      "hello"
      (output (define s (delay (begin (display 'hello) 1)))
	      (force s)
	      (force s)))

(test "Memoization test 2"
      "bonjour"
      (output (let ((s (delay (begin (display 'bonjour) 2))))
		(+ (force s) (force s)))))

(test "Memoization test 3"
      "hi"
      (output (define r (delay (begin (display 'hi) 1)))
	      (define s (delay-force r))
	      (define t (delay-force s))
	      (force t)
	      (force r)))

(test "Memoization test 4"
      "hohohohoho"
      (output (define (stream-drop s index)
		(delay-force
		 (if (zero? index)
		     s
		     (stream-drop (cdr (force s)) (- index 1)))))
	      (define (ones)
		(delay (begin
			 (display 'ho)
			 (cons 1 (ones)))))
	      (define s (ones))
	      (car (force (stream-drop s 4)))
	      (car (force (stream-drop s 4)))))

(let ()
  (define count 0)
  (define p
    (delay (begin (set! count (+ count 1))
		  (if (> count x)
		      count
		      (force p)))))
  (define x 5)
  (test "Reentrancy test 1 (1)" 6 (force p))
  (set! x 10)
  (test "Reentrancy test 1 (2)" 6 (force p)))

(let ()
  (define f
    (let ((first? #t))
      (delay
       (if first?
	   (begin
	     (set! first? #f)
	     (force f))
	   'second))))
  (test "Reentrancy test 2" 'second (force f)))

(let ()
  (define q
    (let ((count 5))
      (define (get-count) count)
      (define p (delay (if (<= count 0)
			   count
			   (begin (set! count (- count 1))
				  (force p)
				  (set! count (+ count 2))
				  count))))
      (list get-count p)))
  (define get-count (car q))
  (define p (cadr q))
  (test "Reentrancy test 3 (1)" 5 (get-count))
  (test "Reentrancy test 3 (2)" 0 (force p))
  (test "Reentrancy test 3 (3)" 10 (get-count)))

(exit *errors*)
