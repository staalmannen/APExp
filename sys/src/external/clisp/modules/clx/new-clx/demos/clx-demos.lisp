;;; Common stuff for the demos
;;; Copyright (C) 1999-2008 by Sam Steingold (sds@gnu.org)
;;; GPL2 is applicable

(defpackage "CLX-DEMOS"
  (:use "COMMON-LISP" "XLIB" "EXT")
  (:shadowing-import-from "XLIB" "CHAR-WIDTH") ; EXT has CHAR-WIDTH
  (:export #:run-all-demos #:*demos*))

(in-package :clx-demos)

(defparameter *demos*
  ;; (demo-name [package requirements])
  '((koch) (qix) (sokoban #:xpm) (greynetic) (petal) (hanoi)
    (recurrence) (plaid) (clclock) (bball) (bwindow)))

(defmacro do-demos ((fun-var) &body body)
  (let ((demo (gensym "DO-DEMOS-DEMO-")) (reqs (gensym "DO-DEMOS-REQS-")))
    `(dolist (,demo *demos*)
       (destructuring-bind (,fun-var . ,reqs) ,demo
         (when (every #'find-package ,reqs)
           ,@body)))))

(do-demos (f)
  (let ((n (string-downcase f)))
    (require n (list (make-pathname :name n :defaults *load-truename*)))))
(do-demos (f)
  (export f)
  (format t "~&=== ~S ===~%~A~%~A~%" f (documentation f 'function)
          (cons f (ext:arglist f))))

(defun run-all-demos (&key (sleep 2))
  (do-demos (f)
    (format t "~&=== ~S ===~%" f)
    (funcall f)
    (sleep sleep)))
