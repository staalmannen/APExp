;;;; test.scm - minimal testing framework
;
; by Alex Shinn, lifted from match-test by felix

(import (only chicken.string ->string))
(import (only chicken.time current-process-milliseconds))

(define *current-group-name* "")
(define *pass* 0)
(define *fail* 0)
(define *start* 0)
(define *total-pass* 0)
(define *total-fail* 0)
(define *total-start* 0)
(define *fail-token* (gensym))

(define (run-test name thunk expect eq pass-msg fail-msg)
  (let ((result (thunk)))
    (cond
      ((eq expect result)
       (set! *pass* (+ *pass* 1))
       (format-result pass-msg name expect result))
      (else
       (set! *fail* (+ *fail* 1))
       (format-result fail-msg name expect result)))))

(define (format-result ls name expect result)
  (let lp ((ls ls))
    (cond
      ((null? ls) (newline))
      ((eq? (car ls) 'expect) (write expect) (lp (cdr ls)))
      ((eq? (car ls) 'result) (write result) (lp (cdr ls)))
      ((eq? (car ls) 'name) (if name (begin (display #\space) (display name))) (lp (cdr ls)))
      (else (display (car ls)) (lp (cdr ls))))))

(define (test-begin . o)
  (set! *current-group-name* (if (null? o) "<unnamed>" (car o)))
  (print "== " *current-group-name* " ==")
  (set! *total-pass* (+ *total-pass* *pass*))
  (set! *total-fail* (+ *total-fail* *fail*))
  (set! *pass* 0)
  (set! *fail* 0)
  (set! *start* (current-process-milliseconds))
  (when (= 0 *total-start*)
    (set! *total-start* (current-process-milliseconds))))

(define (format-float n prec)
  (let* ((str (number->string n))
         (len (string-length str)))
    (let lp ((i (- len 1)))
      (cond
        ((negative? i)
         (string-append str "." (make-string prec #\0)))
        ((eqv? #\. (string-ref str i))
         (let ((diff (+ 1 (- prec (- len i)))))
           (cond
             ((positive? diff)
              (string-append str (make-string diff #\0)))
             ((negative? diff)
              (substring str 0 (+ i prec 1)))
             (else
              str))))
        (else
         (lp (- i 1)))))))

(define (format-percent num denom)
  (let ((x (if (zero? denom) num (exact->inexact (/ num denom)))))
    (format-float (* 100 x) 2)))

(define (test-end . o)
  (let ((end (current-process-milliseconds))
        (total (+ *pass* *fail*)))
    (print "  " total " tests completed in "
	   (format-float (exact->inexact (/ (- end *start*) 1000)) 3)
	   " seconds")
    (print "  " *pass* " ("
	   (format-percent *pass* total)
	   "%) tests passed")
    (print "  " *fail* " ("
	   (format-percent *fail* total)
	   "%) tests failed"))
    (print "-- " *current-group-name* " --\n\n"))

(define (test-exit . o)
  (print " TOTALS: ")
  (set! *total-pass* (+ *total-pass* *pass*)) ; should be 0
  (set! *total-fail* (+ *total-fail* *fail*)) ; should be 0
  (let ((end (current-process-milliseconds))
        (total (+ *total-pass* *total-fail*)))
    (print "  " total " tests completed in "
	   (format-float (exact->inexact (/ (- end *total-start*) 1000)) 3)
	   " seconds")
    (print "  " *total-pass* " ("
	   (format-percent *total-pass* total)
	   "%) tests passed")
    (print "  " *total-fail* " ("
	   (format-percent *total-fail* total)
	   "%) tests failed")
    (exit (if (zero? *total-fail*) 0 1))))

(define (run-equal name thunk expect eq)
  (run-test name thunk expect eq
            '("(PASS)" name)
            '("(FAIL)" name ": expected " expect " but got " result)))

(define current-test-epsilon (make-parameter 1e-5))

(define (approx-equal? a b epsilon)
  (cond
   ((> (abs a) (abs b)) (approx-equal? b a epsilon))
   ((zero? a) (< (abs b) epsilon))
   (else (< (abs (/ (- a b) b)) epsilon))))

(define (test-equal? expect res)
  (or (equal? expect res)
      (and (number? expect)
           (inexact? expect)
           (inexact? res)
           (approx-equal? expect res (current-test-epsilon)))))

(define current-test-comparator (make-parameter test-equal?))

(define-syntax test-equal
  (syntax-rules ()
    ((_ name expr value eq) (run-equal name (lambda () expr) value eq))
    ((_ name expr value) (run-equal name (lambda () expr) value (current-test-comparator)))
    ((_ expr value) (run-equal (->string 'expr) (lambda () expr) value (current-test-comparator)))))

(define-syntax test-error
  (syntax-rules ()
    ((_ name expr)
     (run-equal
      name
      (lambda () (handle-exceptions ex *fail-token* expr))
      *fail-token* eq?) )
    ((_ expr) (test-error 'expr expr))))

(define-syntax test-assert
  (syntax-rules ()
    ((_ name expr) (run-equal name (lambda () (if expr #t #f)) #t eq?))
    ((_ expr) (run-equal (->string expr) (lambda () (if expr #t #f)) #t eq?))))

(define-syntax test-group
  (syntax-rules ()
    ((_ name body ...)
     (begin
       (print "\n" name ":\n")
       body ...))))
