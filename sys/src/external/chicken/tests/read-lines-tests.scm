;; Tests for `read-lines'

(import (chicken file)
        (chicken io))

(include "test.scm")

(define input-test-file "read-lines.in")

(with-output-to-file input-test-file
 (lambda ()
   (print #<<EOF
1
2
3
4
5
EOF
)))

(test-begin "read-lines")

(test-equal
 "without arguments"
 '("1" "2" "3" "4" "5")
 (with-input-from-file input-test-file read-lines))

(test-equal
 "with a port as argument"
 '("1" "2" "3" "4" "5")
 (call-with-input-file input-test-file
  (lambda (port)
    (read-lines port))))

(test-equal
 "with a limit"
 '("1" "2")
 (call-with-input-file input-test-file
  (lambda (port)
    (read-lines port 2))))

(test-error
 "with an invalid first argument (port)"
 (read-lines input-test-file))

(test-error
 "with an invalid second argument (max)"
 (call-with-input-file input-test-file
   (lambda (port)
     (dynamic-wind
	 void
	 (lambda () (read-lines port 2.0))
	 (lambda () (close-input-port port))))))

(test-end "read-lines")

(delete-file input-test-file)

(test-exit)
