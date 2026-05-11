;;
;; Tests for file and directory access.
;;
;; These may seem silly, but some of them actually fail on MinGW without help.
;;

(import (chicken file)
        (chicken process-context))

(define /   (car (command-line-arguments)))
(define //  (string-append / /))
(define /// (string-append / / /))

(assert (not (file-exists? "")))
(assert (not (directory-exists? "")))

(assert (file-exists? /))
(assert (file-exists? //))
(assert (file-exists? ///))

(assert (directory-exists? /))
(assert (directory-exists? //))
(assert (directory-exists? ///))

(assert (file-exists? "."))
(assert (file-exists? ".."))

(assert (directory-exists? "."))
(assert (directory-exists? ".."))

(assert (file-exists? (string-append "." /)))
(assert (file-exists? (string-append "." //)))
(assert (file-exists? (string-append "." ///)))

(assert (file-exists? (string-append ".." /)))
(assert (file-exists? (string-append ".." //)))
(assert (file-exists? (string-append ".." ///)))

(assert (file-exists? (string-append ".." / "tests")))
(assert (file-exists? (string-append ".." / "tests" /)))
(assert (file-exists? (string-append ".." / "tests" //)))
(assert (file-exists? (string-append ".." / "tests" ///)))

(assert (directory-exists? (string-append "." /)))
(assert (directory-exists? (string-append "." //)))
(assert (directory-exists? (string-append "." ///)))

(assert (directory-exists? (string-append ".." /)))
(assert (directory-exists? (string-append ".." //)))
(assert (directory-exists? (string-append ".." ///)))

(assert (directory-exists? (string-append ".." / "tests")))
(assert (directory-exists? (string-append ".." / "tests" /)))
(assert (directory-exists? (string-append ".." / "tests" //)))
(assert (directory-exists? (string-append ".." / "tests" ///)))

(assert (file-exists? (program-name)))
(assert (not (directory-exists? (program-name))))

(assert (not (file-exists? (string-append (program-name) /))))
(assert (not (file-exists? (string-append (program-name) //))))
(assert (not (file-exists? (string-append (program-name) ///))))

(assert (not (directory-exists? (string-append (program-name) /))))
(assert (not (directory-exists? (string-append (program-name) //))))
(assert (not (directory-exists? (string-append (program-name) ///))))

(print "All tests passed for slash: " /)
