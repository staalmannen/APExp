;;;; reader-tests.scm

(import (only chicken.io read-line read-string)
        (only chicken.port with-input-from-string with-output-to-string)
        (only chicken.read-syntax set-read-syntax! set-sharp-read-syntax!))

(set-sharp-read-syntax! #\& (lambda (p) (read p) (values)))
(set-sharp-read-syntax! #\^ (lambda (p) (read p)))
(set-read-syntax! #\! (lambda (p) (read-line p) (values)))

(define output
  (with-output-to-string
    (lambda ()
      (print "hi") ! this is fortran
      (print "foo") #&(print "amp-comment") (print "baz")
      #^(print "bye"))))

!! output:
!! hi
!! foo
!! baz
!! bye

(assert (string=? output "hi\nfoo\nbaz\nbye\n"))
(assert (string=? "   ." (with-input-from-string "\x20\u0020\U00000020\056" read-string)))
