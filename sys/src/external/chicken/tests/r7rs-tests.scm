;; R7RS Tests

(import (only (chicken port) with-input-from-string with-output-to-string)
	(chicken condition))

;; Copied from R4RS tests
(define cur-section '())

(define errs '())

(define (SECTION . args)
  (newline)
  (write (cons 'SECTION args))
  (newline)
  (newline)
  (set! cur-section args) #t)

(define (record-error e)
  (set! errs (cons (list cur-section e) errs)))

(define (test expect fun . args)
  (write (cons fun args))
  (display "  ==> ")
  (let ((res (if (procedure? fun) (apply fun args) (car args))))
    (write res)
    (newline)
    (if (equal? expect res)
        #t
        (begin
          (record-error (list res expect (cons fun args)))
          (display " BUT EXPECTED ")
          (write expect)
          (newline)
          #f))))

(define (test-error expected? fun . args)
  (write (cons fun args))
  (newline)
  (handle-exceptions exn
    (or (expected? exn)
        (begin
          (record-error (list exn expected? (cons fun args)))
          (display " EXPECTED A DIFFERENT ERROR")
          (newline)
          #f))
    (apply fun args)
    (display " EXPECTED AN ERROR BUT DIDN'T GET ONE")
    #f))

(define (report-errs)
  (newline)
  (if (null? errs) (display "Passed all tests")
      (begin
	(display "errors were:")
	(newline)
	(display "(SECTION (got expected (call)))")
	(newline)
	(for-each (lambda (l) (write l) (newline))
		  errs)
        (exit 1)))
  (newline))

(SECTION 4 2 1)

;; cond clause with only <test>
(test 1 (lambda () (cond (1))))
(test 'foo (lambda () (cond ('foo))))

;; case with => clause
(test "a" (lambda () (case 'a ((a) => symbol->string))))
(test "a" (lambda () (case 'a (else => symbol->string))))
(test-error condition? (lambda () (case 'a ((a) =>))))
(test-error condition? (lambda () (case 'a (else =>))))

(SECTION 4 2 5)


;; make-promise test
(test #t promise? (make-promise 1))
(test #t promise? (make-promise (lambda _ 'foo)))
(test #t promise? (make-promise (make-promise 1)))

(test 1 force (make-promise 1))
(test #t procedure? (force (make-promise (lambda _ 1))))
(test 1 force (make-promise (make-promise 1)))

;; delay/force/delay-force
(test #t promise? (delay 1))
(test #t promise? (delay (delay 1)))
(test 1 force 1)
(test force force (force (delay force)))

(test 3 force (delay (+ 1 2))) ; pp. 18
(let ((p (delay (+ 1 2))))
  (test '(3 3) list (force p) (force p)))

(let () ; pp. 19
  (define integers
    (letrec ((next
	      (lambda (n)
		(delay (cons n (next (+ n 1)))))))
      (next 0)))
  (define head
    (lambda (stream) (car (force stream))))
  (define tail
    (lambda (stream) (cdr (force stream))))
  (test 0 head integers)
  (test 0 head integers)
  (test 1 head (tail integers))
  (test 2 head (tail (tail integers))))

(let () ; later on pp. 19
  (define count 0)
  (define p
    (delay (begin (set! count (+ count 1))
	     (if (> count x)
		 count
		 (force p)))))
  (define x 5)
  (test #t promise? p)
  (test 6 force p)
  (test #t promise? p)
  (set! x 10)
  (test 6 force p))

(test #t promise? (delay-force 1))
(test 1 force (delay-force 1))
(test 6 force (delay-force (+ 1 2 3)))
(test #t promise? (delay-force (delay 1)))

;; delayed MVs
(call-with-values
 (lambda () (force (delay (values 1 2 3))))
 (lambda mv (test '(1 2 3) #f mv)))
(call-with-values
 (lambda () (force (delay-force (values 4 5 6))))
 (lambda mv (test '(4 5 6) #f mv)))
(call-with-values
 (lambda () (force (delay (values))))
 (lambda mv (test '() #f mv)))


(SECTION 5 3)

(test '(1 2)
      (lambda ()
        (define-values (a b) (values 1 2))
        (list a b)))

(test '(1 (2))
      (lambda ()
        (define-values (a . b) (values 1 2))
        (list a b)))

(test '((1 2))
      (lambda ()
        (define-values a (values 1 2))
        (list a)))

(test 'ok ; Just tests that no error is thrown.
      (lambda ()
        (define-values () (values))
        'ok))


(SECTION 6 6)


(define (integer->named-char x)
  (with-output-to-string (lambda () (write (integer->char x)))))

(test "#\\alarm" integer->named-char #x07)
(test "#\\backspace" integer->named-char #x08)
(test "#\\delete" integer->named-char #x7f)
(test "#\\escape" integer->named-char #x1b)
(test "#\\newline" integer->named-char #x0a)
(test "#\\null" integer->named-char #x00)
(test "#\\return" integer->named-char #x0d)
(test "#\\space" integer->named-char #x20)
(test "#\\tab" integer->named-char #x09)



(SECTION 6 7)


;; We try to avoid using the very constructs that we are testing here,
;; hence the slightly cumbersome string construction of <x> -> "\"\\<x>\""
(define (read-escaped-string x)
  (with-input-from-string (string-append (string #\" #\\) x (string #\"))
    read))
(define (escaped-char x)
  (string-ref (read-escaped-string x) 0))

(test #\alarm escaped-char "a")
(test #\backspace escaped-char "b")
(test #\tab escaped-char "t")
(test #\newline escaped-char "n")
(test #\return escaped-char "r")
(test #\" escaped-char "\"")
(test #\\ escaped-char "\\")
(test #\| escaped-char "|")
;; *ONE* line ending following a backslash escape, along with any
;; preceding or trailing intraline whitespace is collapsed and ignored.
(test #\E escaped-char (string-append (string #\newline) "       END"))
;; This also works with CR instead of LF...
(test #\E escaped-char (string-append (string #\return) "       END"))
;; And CRLF, too
(test #\E escaped-char (string-append (string #\return) (string #\newline) "       END"))
(test #\E escaped-char (string-append "    " (string #\newline) "END"))
(test #\E escaped-char (string-append "    " (string #\newline) "END"))
(test #\E escaped-char (string-append "     " (string #\newline) "   END"))
;; But not more than one!
(test #\newline escaped-char (string-append "     " (string #\newline) "    " (string #\newline) " END"))
;; CR and LF both counted
(test #\newline escaped-char (string-append "     " (string #\return) "    " (string #\newline) " END"))
;; Tabs count as intraline whitespace too
(test #\E escaped-char (string-append (string #\tab) (string #\newline) (string #\tab) "   END"))
;; Edge case
(test "" read-escaped-string (string-append "    " (string #\newline) "    "))

;; NOT YET (is ambiguous with existing \xNN syntax in CHICKEN)
#;(test #\tab escaped-char "x9;")
#;(test #\tab escaped-char "x09;")



(SECTION 6 8)

;; Symbols are implicitly quoted inside self-evaluating vectors.
;; This is not as clear from draft 9 as it could be.
(test '#(0 (2 2 2 2) "Anna") #f #(0 (2 2 2 2) "Anna"))
(test #t vector? '#(0 (a b) c))
(test #t vector? #(0 (a b) c))
(test '#(0 (a b) c d #(1 2 (e) f) g) #f #(0 (a b) c d #(1 2 (e) f) g))

(report-errs)
