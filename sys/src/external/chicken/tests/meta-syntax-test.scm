;;;; meta-syntax-test.scm

;;
;; A module's syntax definitions should be accessible through either of
;; the following import forms:
;;
;;   (import-syntax-for-syntax (foo)) ; meta environment
;;
;;   (begin-for-syntax                ; compiler environment
;;     (import-syntax (foo)))         ; note that `import` will not work here
;;

(module foo (bar listify)
  (import scheme chicken.syntax)
  (begin-for-syntax
   (define (baz x) 
     (list (cadr x))))
  (define-syntax bar
    (er-macro-transformer
     (lambda (x r c)
       `(,(r 'list) (baz (list 1 ,(cadr x)))))))
  (begin-for-syntax
   (define-syntax call-it-123
     (syntax-rules ()
       ((_ x)
        '(x 'x 1 2 3)))))
  (define-syntax listify
    (er-macro-transformer
     (lambda (e r c)
       (call-it-123 list)))))

(module test-import-syntax-for-syntax (test)
  (import scheme chicken.syntax)
  (import-syntax-for-syntax (prefix foo foo:))
  (define-syntax test-import-syntax-for-syntax
    (er-macro-transformer
     (lambda (x r c)
       `(,(r 'quote) ,@(foo:bar 1 2)))))
  (define (test)
    (test-import-syntax-for-syntax)))

(module test-begin-for-syntax (test)
  (import scheme chicken.syntax)
  (begin-for-syntax
    (import-syntax (prefix foo foo:)))
  (define-syntax test-begin-for-syntax
    (er-macro-transformer
     (lambda (x r c)
       `(,(r 'quote) ,@(foo:bar 1 2)))))
  (define (test)
    (test-begin-for-syntax)))
