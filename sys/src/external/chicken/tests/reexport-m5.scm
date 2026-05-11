;;; export syntax, one definition refering to another
;   used for testing reexport wth renaming (reexport-test-2.scm)
(module reexport-m5 *
(import scheme)
(define-syntax s1
  (syntax-rules () ((_) (s2))))
(define-syntax s2
  (syntax-rules () ((_) (display 1)))))
