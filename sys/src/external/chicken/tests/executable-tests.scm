;;; Compiled executable tests

(include "test.scm")

(import (chicken file)
        (chicken file posix)
        (chicken pathname)
        (chicken process-context)
        (chicken string))

(define program-path
  (cond-expand
    ((and windows (not cygwin))
     (string-translate (car (command-line-arguments)) "/" "\\"))
    (else (car (command-line-arguments)))))

(define (read-symbolic-link* p)
  (cond-expand
    ((and windows (not cygwin)) p)
    (else (read-symbolic-link p #t))))

(test-begin "executable tests")

(let ((p (program-name)))
  (test-equal "program-name"
              (pathname-strip-directory p)
              (pathname-strip-directory program-path)))

(and-let* ((p (executable-pathname)))
  (test-equal "executable-pathname"
              (read-symbolic-link* p)
              (read-symbolic-link* program-path)))

(test-end)

(test-exit)
