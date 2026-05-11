;;; export syntax that refers to reexported syntax (reexport-test-2.scm)
(module
 reexport-m4
 (baz)
 (import (scheme) (chicken base) (chicken module) (reexport-m3))
 (reexport (reexport-m3))
 (define-syntax baz
   (ir-macro-transformer
    (lambda (e i c)
      `(foo)))))
