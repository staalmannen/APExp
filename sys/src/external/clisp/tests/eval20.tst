;; -*- Lisp -*- vim:filetype=lisp
;; CLtL2 20; ANSI CL 3.1

;; eval

(eval (list 'cdr (car '((quote (a . b)) c))))
b

(makunbound 'x)
x

(eval 'x)
ERROR

(setf x 3)
3

(eval 'x)
3

;; eval-when
(let ((ff "eval20-tst-eval-when-test.lisp"))
  (with-open-file (foo ff :direction :output #+(or CMU SBCL) :if-exists #+(or CMU SBCL) :supersede)
    (format foo "~%(eval-when (compile eval)
  ;; note that LAMBDA is not externalizable
  (defvar *junk* #.(lambda (x) (+ 15 x))))~%"))
  (unwind-protect (compile-file ff)
    (post-compile-file-cleanup ff))
  nil)
nil

(defvar *collector*)
*collector*

(let ((forms nil) all (ff "eval20-tst-eval-when-test.lisp"))
  (dolist (c '(nil (:compile-toplevel)))
    (dolist (l '(nil (:load-toplevel)))
      (dolist (x '(nil (:execute)))
        (push `(eval-when (,@c ,@l ,@x)
                 (push '(,@c ,@l ,@x) *collector*))
              forms))))
  (dolist (c '(nil (:compile-toplevel)))
    (dolist (l '(nil (:load-toplevel)))
      (dolist (x '(nil (:execute)))
        (push `(let () (eval-when (,@c ,@l ,@x)
                         (push '(let ,@c ,@l ,@x) *collector*)))
              forms))))
  (with-open-file (o ff :direction :output #+(or CMU SBCL) :if-exists #+(or CMU SBCL) :supersede)
    (dolist (f forms)
      (prin1 f o)
      (terpri o)))
  (let ((*collector* nil))
    (load ff)
    (push (cons "load source" *collector*) all))
  (let ((*collector* nil))
    (compile-file ff)
    (push (cons "compile source" *collector*) all))
  (let ((*collector* nil))
    (load (compile-file-pathname ff))
    (push (cons "load compiled" *collector*) all))
  (post-compile-file-cleanup ff)
  (nreverse all))
(("load source"
  (:EXECUTE) (:LOAD-TOPLEVEL :EXECUTE) (:COMPILE-TOPLEVEL :EXECUTE)
  (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE)
  (LET :EXECUTE) (LET :LOAD-TOPLEVEL :EXECUTE)
  (LET :COMPILE-TOPLEVEL :EXECUTE)
  (LET :COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE))
 ("compile source"
  (:COMPILE-TOPLEVEL) (:COMPILE-TOPLEVEL :EXECUTE)
  (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL)
  (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE))
 ("load compiled"
  (:LOAD-TOPLEVEL) (:LOAD-TOPLEVEL :EXECUTE)
  (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL)
  (:COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE)
  (LET :EXECUTE) (LET :LOAD-TOPLEVEL :EXECUTE)
  (LET :COMPILE-TOPLEVEL :EXECUTE)
  (LET :COMPILE-TOPLEVEL :LOAD-TOPLEVEL :EXECUTE)))

;; eval-when.15: in CLISP LOAD is not the same as :LOAD-TOPLEVEL
(let ((f "eval20-tst-eval-when-test.lisp") (ret ()))
  (dolist (situation '(load :load-toplevel) (nreverse ret))
    (let ((*collector* ()))
      (with-open-file (o f :direction :output)
        (prin1 `(let ((x :let))
                  (push (list (eval-when (,situation) (setq x :eval-when)) x)
                        *collector*))
               o))
      (load f) (load (compile-file f))
      (post-compile-file-cleanup f)
      (push (nreverse *collector*) ret))))
(((NIL :LET) (:EVAL-WHEN :EVAL-WHEN)) ((NIL :LET) (NIL :LET)))

;; eval-when.17: in CLISP EVAL is not the same as :EXECUTE
(let ((f "eval20-tst-eval-when-test.lisp") (ret ()))
  (dolist (situation '(eval :execute) (nreverse ret))
    (let ((*collector* ()))
      (with-open-file (o f :direction :output)
        (prin1 `(let ((x :let))
                  (push (list (eval-when (,situation) (setq x :eval-when)) x)
                        *collector*))
               o))
      (load f) (load (compile-file f))
      (post-compile-file-cleanup f)
      (push (nreverse *collector*) ret))))
(((:EVAL-WHEN :EVAL-WHEN) (NIL :LET))
 ((:EVAL-WHEN :EVAL-WHEN) (:EVAL-WHEN :EVAL-WHEN)))

;; constantp

(constantp 2)
T

(constantp #\r)
T

(constantp "max")
T

(constantp '#(110))
T

(constantp :max)
T

(constantp T)
T

(constantp NIL)
T

(constantp 'PI)
#-CLISP T #+CLISP NIL

(constantp '(quote foo))
T

(constantp '(+ 3 4))
#+CLISP T #-CLISP NIL

(constantp '((setf cons) 3 4))
NIL

;; <http://www.lisp.org/HyperSpec/Issues/iss146-writeup.html>
(let ((src "eval20-tst.lisp") (zz (cons 1 2)))
  (defun setf-foo (u v) (setf (car u) v))
  (with-open-file (s src :direction :output
                     #+(or CMU SBCL) :if-exists #+(or CMU SBCL) :supersede)
    (format s "(progn~%  (defsetf foo setf-foo)
  (defun bar (u v) (setf (foo u) v)))~%"))
  (load src #+CLISP :compiling #+CLISP t)
  (delete-file src)
  (bar zz 12)
  zz)
(12 . 2)

;; globally special
(defparameter x 1) x
(handler-bind ((unbound-variable
                (lambda (c) (princ-error c) (store-value 10))))
  (list (let (x) (makunbound 'x) x) x))
(10 1)

(handler-bind ((unbound-variable
                (lambda (c) (princ-error c) (store-value 11))))
  (list (let (x) (makunbound 'x) (symbol-value 'x)) x))
(11 1)

(handler-bind ((unbound-variable
                (lambda (c) (princ-error c) (store-value 12))))
  (list (let (x) (makunbound 'x) (list x (symbol-value 'x))) x))
((12 12) 1)

(handler-bind ((unbound-variable
                (lambda (c) (princ-error c) (store-value 13))))
  (list (let (x) (makunbound 'x) (list (symbol-value 'x) x)) x))
((13 13) 1)

(let ((count 140))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (use-value (incf count)))))
    (list (let (x) (makunbound 'x) (list x (symbol-value 'x))) x)))
((141 142) 1)

(let ((count 150))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (use-value (incf count)))))
    (list (let (x) (makunbound 'x) (list (symbol-value 'x) x)) x)))
((151 152) 1)

;; lexical: makunbound does not affect the lexical binding
(let ((y 1))
  (list (let ((y 20)) (makunbound 'y) y) y))
(20 1)

(let ((y 1))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (store-value 21))))
    (list (let (y) (makunbound 'y) (symbol-value 'y)) y)))
(21 1)

(let ((y 1))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (store-value 220))))
    (list (let ((y 22)) (makunbound 'y) (list y (symbol-value 'y))) y)))
((22 220) 1)

(let ((y 1))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (store-value 230))))
    (list (let ((y 23)) (makunbound 'y) (list (symbol-value 'y) y)) y)))
((230 23) 1)

(let ((y 1) (count 240))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (use-value (incf count)))))
    (list (let ((y 24)) (makunbound 'y) (list y (symbol-value 'y))) y)))
((24 241) 1)

(let ((y 1) (count 250))
  (handler-bind ((unbound-variable
                  (lambda (c) (princ-error c) (use-value (incf count)))))
    (list (let ((y 25)) (makunbound 'y) (list (symbol-value 'y) y)) y)))
((251 25) 1)

;;; http://www.lisp.org/HyperSpec/Body/speope_fletcm_scm_macrolet.html
(flet ((flet1 (n) (+ n n)))
  (flet ((flet1 (n) (+ 2 (flet1 n))))
    (flet1 2)))
6

(progn
  (defun dummy-function () 'top-level)
  (list
   (funcall #'dummy-function)
   (flet ((dummy-function () 'shadow))
     (funcall #'dummy-function))
   (eq (funcall #'dummy-function) (funcall 'dummy-function))
   (flet ((dummy-function () 'shadow))
     (eq (funcall #'dummy-function)
         (funcall 'dummy-function)))))
(TOP-LEVEL SHADOW T NIL)

(progn (defun recursive-times (k n)
         (labels ((temp (n)
                    (if (zerop n) 0 (+ k (temp (1- n))))))
           (temp n)))
       (recursive-times 2 3))
6

(progn
  (defmacro mlets (x &environment env)
    (let ((form `(babbit ,x)))
      (macroexpand form env)))
  (macrolet ((babbit (z) `(+ ,z ,z))) (mlets 5)))
10

(flet ((safesqrt (x) (sqrt (abs x))))
  ;; The safesqrt function is used in two places.
  (safesqrt (apply #'+ (map 'list #'safesqrt '(1 2 3 4 5 6)))))
3.2911735

(progn
  (defun integer-power (n k)
    (declare (integer n))
    (declare (type (integer 0 *) k))
    (labels ((expt0 (x k a)
               (declare (integer x a) (type (integer 0 *) k))
               (cond ((zerop k) a)
                     ((evenp k) (expt1 (* x x) (floor k 2) a))
                     (t (expt0 (* x x) (floor k 2) (* x a)))))
             (expt1 (x k a)
               (declare (integer x a) (type (integer 0 *) k))
               (cond ((evenp k) (expt1 (* x x) (floor k 2) a))
                     (t (expt0 (* x x) (floor k 2) (* x a))))))
      (expt0 n k 1)))
  (integer-power 3 5))
243

(progn
  (defun example (y l)
    (flet ((attach (x)
             (setq l (append l (list x)))))
      (declare (inline attach))
      (dolist (x y)
        (unless (null (cdr x))
          (attach x)))
      l))
  (example '((a apple apricot) (b banana) (c cherry) (d) (e))
           '((1) (2) (3) (4 2) (5) (6 3 2))))
((1) (2) (3) (4 2) (5) (6 3 2) (A APPLE APRICOT) (B BANANA) (C CHERRY))

;; https://sourceforge.net/tracker/?func=detail&aid=2868147&group_id=1355&atid=101355
(with-output-to-string (*error-output*) (declaim (optimize zot)))
"WARNING: ZOT is not a valid OPTIMIZE quality.
"

;; Clean up.
(progn (symbol-cleanup 'setf-foo)
       (symbol-cleanup 'bar)
       (symbol-cleanup 'x)
       (symbol-cleanup '*collector*)
       (symbol-cleanup 'dummy-function)
       (symbol-cleanup 'recursive-times)
       (symbol-cleanup 'mlets)
       (symbol-cleanup 'integer-power)
       (symbol-cleanup 'example))
T
