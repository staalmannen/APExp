;; Module for GDBM / CLISP
;; <http://www.gnu.org/gdbm/>
;; Copyright (C) 2007  Masayuki Onjo <onjo@lispuser.net>
;; Copyright (C) 2007-2008  Sam Steingold <sds@gnu.org>
;; Released under GNU GPL2

(defpackage #:gdbm
  (:documentation
   "GDBM - The GNU database manager - <http://www.gnu.org/software/gdbm/>")
  (:use #:lisp)
  (:export #:gdbm #:gdbm-p #:gdbm-error #:gdbm-version
           #:gdbm-path #:gdbm-default-key-type #:gdbm-default-value-type
           #:gdbm-error-message #:gdbm-error-code
           #:gdbm-open #:gdbm-open-p #:gdbm-close #:do-db #:with-open-db
           #:gdbm-store #:gdbm-fetch #:gdbm-delete #:gdbm-exists
           #:gdbm-firstkey #:gdbm-nextkey #:gdbm-file-size
           #:gdbm-reorganize #:gdbm-sync #:gdbm-setopt))
(in-package "GDBM")

(pushnew :gdbm *features*)
(provide "gdbm")
(pushnew "GDBM" custom:*system-package-list* :test #'string=)
(setf (documentation (find-package "GDBM") 'sys::impnotes) "gdbm")

;; keep this definition in sync with check_gdbm in gdbm.c
(defstruct (gdbm (:constructor make-gdbm (dbf path key-type value-type)))
  dbf
  path
  key-type
  value-type)

(defun gdbm-open-p (gdbm) (not (null (gdbm-dbf gdbm))))

(define-condition gdbm-error (simple-error)
  ((code :reader gdbm-error-code :initarg :code)
   (message :reader gdbm-error-message :initarg :message))
  (:report (lambda (condition stream)
	     (princ (gdbm-error-message condition) stream))))

(defmacro do-db ((key-var gdbm &rest options) &body body)
  "Iterate over the GDBM keys in LOOP."
  (let ((db (gensym "DO-DB")))
    `(loop :with ,db = ,gdbm
       :for ,key-var = (gdbm:gdbm-firstkey ,db ,@options)
       :then (gdbm:gdbm-nextkey ,db ,key-var ,@options)
       :while ,key-var ,@body)))

(defmacro with-open-db ((db filename &rest options) &body body)
  "Open a GDBM database, execute BODY, ensure that the DB is closed."
  (multiple-value-bind (body-rest declarations) (system::parse-body body)
    `(let ((,db (gdbm-open ,filename ,@options)))
       (declare (read-only ,db) ,@declarations)
       (unwind-protect (multiple-value-prog1 (progn ,@body-rest)
                         (when ,db (gdbm-close ,db)))
         (when ,db (gdbm-close ,db))))))
