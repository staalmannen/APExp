;;;; private-repository-test.scm


(import (chicken pathname)
	(chicken platform)
        (chicken process-context)
        (chicken file)
        (chicken file posix))

(define read-symbolic-link*
  (cond-expand
   ((and windows (not cygwin)) (lambda (filename _) filename))
   (else read-symbolic-link)))

(define repo (normalize-pathname (read-symbolic-link* (car (repository-path)) #t)))
(define dir (normalize-pathname (read-symbolic-link* (car (command-line-arguments)) #t)))

(print (list dir repo))

(assert (string=? repo dir))

