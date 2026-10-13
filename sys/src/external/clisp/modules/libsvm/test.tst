;; -*- Lisp -*- vim:filetype=lisp
;; some tests for libsvm
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "libsvm/test")'

(list (require "libsvm")) (#-LIBSVM T #+LIBSVM NIL)
(listp (show (multiple-value-list (ext:module-info "libsvm" t)) :pretty t)) T

(integerp (show libsvm:*libsvm-version*)) T

(open-stream-p (setq libsvm:*libsvm-output* (make-string-output-stream))) T

(defparameter f-parameter (libsvm:make-parameter))
F-PARAMETER

(defparameter v-parameter (show (ffi:foreign-value f-parameter)))
V-PARAMETER

(ffi:validp f-parameter) T
(libsvm:destroy-parameter f-parameter) NIL
(ffi:validp f-parameter) NIL

(equalp v-parameter
        (ffi:foreign-value (setq f-parameter (libsvm:make-parameter
                                              :v v-parameter))))
T

;; create an artificial problem:
;; predict the remainder of division by k from n-digits
(defun task (num divisor base)
  (flet ((normalize (x d) (- (/ (* 2 x) (1- d)) 1d0)))
    (values (normalize (rem num divisor) divisor)
            (do ((n num) r (ret ()) (index 0 (1+ index)))
                ((zerop n)
                 (coerce (nreverse (cons (list -1 0d0) ret)) 'vector))
              (multiple-value-setq (n r) (floor n base))
              (let ((value (normalize r base)))
                (unless (zerop value) (push (list index value) ret)))))))
TASK
(defun problem (repeat divisor base)
  (let ((x (make-array repeat)) (y (make-array repeat)))
    (dotimes (i repeat)
      (multiple-value-bind (n v) (task i divisor base)
        (setf (aref y i) n (aref x i) v)))
    (libsvm:make-problem :l repeat :x x :y y)))
PROBLEM

(defparameter f-problem-2-7 (problem 1000 2 7)) F-PROBLEM-2-7
(libsvm:problem-l f-problem-2-7) 1000
(libsvm:save-problem "svm-problem" f-problem-2-7) NIL
(multiple-value-bind (p maxindex) (libsvm:load-problem "svm-problem")
  (ffi:with-c-place (p-parameter f-parameter)
    (setf (ffi:slot p-parameter 'libsvm::gamma) (float (/ maxindex) 0d0)
          (ffi:slot p-parameter 'libsvm::C) 1d0
          (ffi:slot p-parameter 'libsvm::kernel_type) libsvm:LINEAR))
  (setf v-parameter (ffi:foreign-value f-parameter))
  (show (libsvm:parameter-alist f-parameter) :pretty t)
  (list (= maxindex (floor (log (1- 1000) 7)))
        (equalp (ffi:foreign-value p) (ffi:foreign-value f-problem-2-7))))
(T T)

(let ((vec (libsvm:cross-validation f-problem-2-7 f-parameter 3))
      (hit 0) (miss 0))
  (show (libsvm:parameter-alist f-parameter) :pretty t)
  (loop :for v :across vec :for o :across (libsvm:problem-y f-problem-2-7)
    :when (= v o) :do (incf hit) :end
    :when (= v (- o)) :do (incf miss) :end)
  (show (list :count+1 (count 1d0 vec) :count-1 (count -1d0 vec)
              :hit hit :miss miss))
  (length vec))
1000

(defparameter model (libsvm:train f-problem-2-7 f-parameter)) MODEL

(ffi:enum-from-value 'libsvm:svm_type (libsvm:get-svm-type model)) libsvm:C_SVC
(libsvm:get-nr-class model) 2
(libsvm:get-labels model) #(-1 1)
(libsvm:check-probability-model model) 0
(libsvm:get-svr-probability model) 0d0
(let* ((l (libsvm:problem-l f-problem-2-7))
       (y (libsvm:problem-y f-problem-2-7 l))
       (x (libsvm:problem-x f-problem-2-7 l)))
  (dotimes (i 10 l)
    (print (list (aref y i) (libsvm:predict-values model (aref x i))))))
1000
(libsvm:save-model "svm-model" model) 0
(libsvm:destroy-model (libsvm:load-model "svm-model")) NIL
(libsvm:destroy-model model) NIL
(libsvm:destroy-problem f-problem-2-7) NIL

(defparameter f-problem-3-7 (problem 1000 3 7)) F-PROBLEM-3-7
(libsvm:save-problem "svm-problem" f-problem-3-7) NIL
(progn
  (setf f-parameter (libsvm:make-parameter :v v-parameter 'LIBSVM::nu 5d-1
                                           'LIBSVM::svm_type libsvm:NU_SVC
                                           'LIBSVM::probability 1)
        v-parameter (show (ffi:foreign-value f-parameter)))
  (show (libsvm:parameter-alist f-parameter) :pretty t)
  (= (ffi:slot (ffi:foreign-value f-parameter) 'LIBSVM::svm_type)
     libsvm:NU_SVC))
T

(let ((vec (libsvm:cross-validation f-problem-3-7 f-parameter 3)))
  (show (list :count+1 (count 1d0 vec) :count-1 (count -1d0 vec)
              :count-0 (count 0d0 vec)))
  (length vec))
1000

(defparameter model (libsvm:train f-problem-3-7 f-parameter)) MODEL
(ffi:enum-from-value 'libsvm:svm_type (libsvm:get-svm-type model)) libsvm:NU_SVC
(libsvm:get-nr-class model) 3
(libsvm:get-labels model) #(-1 0 1)
(libsvm:check-probability-model model) 1
(libsvm:get-svr-probability model) 0d0

(let* ((l (libsvm:problem-l f-problem-3-7))
       (y (libsvm:problem-y f-problem-3-7 l))
       (x (libsvm:problem-x f-problem-3-7 l)))
  (dotimes (i 10 l)
    (print (list (aref y i) (libsvm:predict model (aref x i))
                 (multiple-value-list
                  (libsvm:predict-probability model (aref x i)))))))
1000
(libsvm:destroy-model model) NIL

(progn
  (setf f-parameter (libsvm:make-parameter :v v-parameter 'LIBSVM::nu 5d-1
                                           'LIBSVM::svm_type libsvm:EPSILON_SVR
                                           'LIBSVM::probability 1)
        v-parameter (ffi:foreign-value f-parameter))
  (show (libsvm:parameter-alist f-parameter) :pretty t)
  (= (ffi:slot (ffi:foreign-value f-parameter) 'LIBSVM::svm_type)
     libsvm:EPSILON_SVR))
T
(defparameter model (libsvm:train f-problem-3-7 f-parameter)) MODEL
(libsvm:check-probability-model model) 1
(type-of (show (libsvm:get-svr-probability model))) DOUBLE-FLOAT
(let* ((l (libsvm:problem-l f-problem-3-7))
       (y (libsvm:problem-y f-problem-3-7 l))
       (x (libsvm:problem-x f-problem-3-7 l)))
  (dotimes (i 10 l)
    (print (list (aref y i) (libsvm:predict model (aref x i))
                 (multiple-value-list
                  (libsvm:predict-probability model (aref x i)))))))
1000
(libsvm:destroy-model model) NIL

(ffi:validp f-problem-3-7) T
(libsvm:destroy-problem f-problem-3-7) NIL
(ffi:validp f-problem-3-7) NIL
(ffi:validp f-parameter) T
(libsvm:destroy-parameter f-parameter) NIL
(ffi:validp f-parameter) NIL

(stringp (show (get-output-stream-string libsvm:*libsvm-output*))) T

(progn (makunbound 'f-parameter)
       (makunbound 'v-parameter)
       (makunbound 'f-problem-2-7)
       (makunbound 'f-problem-3-7)
       (makunbound 'model)
       (makunbound 'maxindex)
       (delete-file "svm-model")
       (delete-file "svm-problem")
       T) T
