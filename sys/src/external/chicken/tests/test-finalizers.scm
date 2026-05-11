;;;; test-finalizers.scm

;; NOTE: This may fail, reopen #1426 if it does

(import (chicken format))
(import (chicken gc))

(##sys#eval-debug-level 0)		; disable keeping trace-buffer with frameinfo

(define x (list 1 2 3))
(define y (list 4 5 6))
(define x-f #f)
(define y-f #f)

(begin
  (set-finalizer! 
   x
   (lambda (o)
     (format #t "Delete: ~A (y: ~a)~%" o y-f)
     (set! x-f #t)))
  #t) 
(begin 
  (set-finalizer! 
   y 
   (let ((p x))
     (lambda (o)
       (format #t "Delete: ~A: ~A~%" o p)
       (set! y-f #t))))
  #t)
(gc #t)
(assert (not x-f))

#|

This ought to work, see patches/finalizer.closures.diff for
a fix that unfortunately disables finalizers in the interpreter
(probably due to the different closure representation).

(assert (not y-f))
(set! x #f)
(gc #t)
(assert (not x-f))
(assert (not y-f))
(set! y #f)
(gc #t)
(assert y-f)
(assert x-f)
|#

(define foo-f #f)

(let ((foo (vector 1 2 3)))
  (set-finalizer! foo (lambda _ (set! foo-f #t)))
  #t)

(gc #t)
(assert foo-f)


;; double finalizer

(define n 0)
(define (bump . _) (set! n (add1 n)))
(define x (vector 1))
(set-finalizer! x bump)
(set-finalizer! x bump)
(set! x #f)
(gc #t)
(print n)
(assert (= 2 n))

;; Finalizers on constants are ignored in compiled mode (because
;; they're never GCed).  Reported by "Pluijzer".

#| this doesn't always work in csi, for some unknown reason,
   depending on unrelated factors (command-line options,
   memory usage patterns, etc.)
                                                
(set! n 0)
(define bar "constant string")
(set-finalizer! bar bump)
(set! bar #f)
(gc #t)
(print n)
(cond-expand
  (compiling (assert (= 0 n)))
  (else (assert (= 1 n))))
|#
