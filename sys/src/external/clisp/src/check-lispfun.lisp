;;; Copyright (C) 2002-2009 by Sam Steingold
;;; This is Free Software, covered by the GNU GPL (v2)
;;; See http://www.gnu.org/copyleft/gpl.html
;;;
;;; Check LISPFUN, LISPFUNN and LISPSPECFORM

(in-package "USER")

(defun make-c-rt (&optional (rt (copy-readtable)))
  (set-syntax-from-char #\, #\Space rt)
  rt)
(defvar *c-rt* (make-c-rt))
(defun get-lisp-def (line st)
  (let* ((*readtable* *c-rt*)
         (in (make-concatenated-stream (make-string-input-stream line) st))
         (fn (read in))
         (li (read in)))
    (values li fn)))

(defvar *form-decls* '("subr" "fsubr"))
(defvar *const-decls* '("constsym" "constobj" "constobj_tl" "constpack"))

(defun get-lisp-defs (file &optional decs &aux (pos 0) (error-count 0))
  (with-open-file (st file :direction :input :external-format charset:utf-8)
    (format t "~&~s: file ~s~%" 'get-lisp-defs file)
    (values (ext:with-collect (keep)
              (loop (let ((line (read-line st nil nil)) p s)
                      (unless line (return)) (incf pos)
                      (when (and decs (setq p (search #1="funcall(S(" line)))
                        (let ((fn (subseq line (+ p #.(length #1#))
                                          (position #\) line :start p))))
                          (when (and (setq s (find fn decs :test #'string-equal
                                                   :key #'car))
                                     ;; load is called as S(load) because
                                     ;; it is redefined in init.lisp
                                     (sys::subr-info (car s)))
                            (cerror "proceed with checks"
                                    "~a:~d: funcall(S(~a)) for a subr ~s"
                                    file pos fn s)
                            (incf error-count))))
                      (when (sys::string-beg-with "LISP" line)
                        (multiple-value-bind (li fn) (get-lisp-def line st)
                          (push fn (cdr li))
                          (keep li))))))
            error-count)))

(defun check-lisp-defs (dir)
  (format t "~&~s: ~s~%" 'check-lisp-defs dir)
  (let* ((exclude (append *const-decls* *form-decls*))
         (error-count 0) kwd kw-forms
         (dec-forms
          (delete-duplicates
           (sort (mapcan #'get-lisp-defs
                         (mapcar (lambda (fi)
                                   (make-pathname :name fi :type "d"
                                                  :defaults dir))
                                 *form-decls*))
                 #'string< :key #'car)
           :test #'equal))
         (def-forms
          (delete-duplicates
           (sort (mapcan (lambda (f)
                           (multiple-value-bind (forms errors)
                               (get-lisp-defs f dec-forms)
                             (incf error-count errors)
                             forms))
                         (delete-if (lambda (fi)
                                      (member (pathname-name fi) exclude
                                              :test #'string-equal))
                                    (directory (merge-pathnames "*.d" dir))))
                 #'string< :key #'car)
           :test #'equal)))
    (cond ((= (length def-forms) (length dec-forms))
           (format t "~d forms~%" (length def-forms)))
          (t (cerror #1="proceed with checks"
                     "# of defined forms ~s != # of declared forms ~s"
                     (length def-forms) (length dec-forms))
             (incf error-count)))
    (when (set-difference dec-forms def-forms :test #'equal)
      (cerror #1# "declaration (subr.d) differs from the definition:~%~s"
              (set-difference dec-forms def-forms :test #'equal))
      (incf error-count))
    (when (set-difference def-forms dec-forms :test #'equal)
      (cerror #1# "definition differs from the declaration (subr.d):~%~s"
              (set-difference def-forms dec-forms :test #'equal))
      (incf error-count))
    (with-open-file (st (merge-pathnames "subrkw.d" dir)
                        :direction :input :external-format charset:utf-8)
      (format t "~&~s: file ~s~%" 'check-lisp-defs
              (merge-pathnames "subrkw.d" dir))
      (loop (let* ((line (read-line st nil nil)) (len (length line)))
              (unless line (return))
              (when (plusp len)
                (cond ((char= #\v (char line 0))
                       (setq kwd (get-lisp-def line st)))
                      ((char= #\s (char line 0))
                       (let* ((fn (car (get-lisp-def line st)))
                              (fk (cdr (member 'key (assoc fn dec-forms)))))
                         (push (cons fn fk) kw-forms)
                         (unless (equal fk kwd)
                           (cerror #1# "subrkw.d vs subr.d (~s):~%~s~%~s"
                                   fn kwd fk)
                           (incf error-count)))))))))
    (dolist (fn dec-forms)
      (when (and (member 'key fn)
                 (not (member (car fn) kw-forms :key #'car)))
        (cerror #1# "in subr.d but not in subrkw.d: ~s" fn)))
    (when (plusp error-count)
      (error "~d errors" error-count))))

(defun write-subrs (file)
  (let ((count 0) (*package* (find-package "CL-USER")))
    (with-open-file (out file :direction :output)
      (do-all-symbols (sy)
        (let ((sig (multiple-value-list (sys::subr-info sy))))
          (when sig
            (incf count)
            (write sig :stream out)
            (terpri out)))))
    count))

;;; file check-lispfun.lisp ends here
