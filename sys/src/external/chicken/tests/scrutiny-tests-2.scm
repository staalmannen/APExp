;;;; scrutiny-tests-2.scm


(define-syntax predicate
  (syntax-rules ()
    ((_ pred (proto ...) (nonproto ...))
     (begin
       (assert (pred proto)) ...
       (assert (not (pred nonproto))) ...))))


;;;

(let* ((p '(1 . 2))
       (l (list))
       (n '())
       (i 123)
       (f 12.3)
       (u (+ i f)))
  (predicate pair? (p) (l n i f))
  (predicate list? (l n) (p i f))
  (predicate null? (n l) (p i f))
  (predicate fixnum? (i) (f u))
  (predicate exact? (i) (f u))
  (predicate flonum? (f u) (i))
  (predicate inexact? (f u) (i))
  (predicate number? (i f u) (n)))
