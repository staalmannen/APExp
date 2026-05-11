;;; Test user compilation passes

(import (chicken base)
        (chicken compiler user-pass)
        (chicken io)
        (chicken pretty-print))

(define passes '()) ; track user passes

(user-read-pass
 (lambda (_ _ _)
   (set! passes (cons 'user-read-pass passes))
   (list 'ok))) ; ignore file and use single datum

(user-preprocessor-pass
 (lambda (x)
   (set! passes (cons 'user-preprocessor-pass passes))
   (values x)))

(user-pass
 (lambda (x)
   (set! passes (cons 'user-pass passes))
   (values x)))

(user-post-analysis-pass
 (lambda (_ _ _ _ _ _ _)
   (set! passes (cons 'user-post-analysis-pass passes))))

(on-exit
 (lambda ()
   (assert (memq 'user-read-pass passes)          "user-read-pass not called")
   (assert (memq 'user-pass passes)               "user-pass not called")
   (assert (memq 'user-preprocessor-pass passes)  "user-preprocessor-pass not called")
   (assert (memq 'user-post-analysis-pass passes) "user-post-analysis-pass not called")))
