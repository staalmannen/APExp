;;; csc interface tests

(import (chicken file)
        (chicken pathname)
        (chicken platform)
        (chicken process)
        (chicken process-context)
        (chicken string))

(include "programs-path.scm")

(define (realpath x)
  (normalize-pathname (make-pathname (current-directory) x)))

(define (run x . args)
  (system* (string-intersperse (cons (realpath x) args))))

(define (csc . args)
  (apply run csc-path "-v" "-I.." "-compiler" (realpath chicken-path) "-libdir" ".." args))

(csc "null.scm" "-t")
(assert (file-exists? "null.c"))

(define obj-file (if (eq? (software-version) 'mingw32) "null.obj" "null.o"))

(csc "null.c" "-c")
(assert (file-exists? obj-file))

(csc obj-file)
(run "null")
