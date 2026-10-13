;;;; Saving memory images

(in-package "EXT")
(export '(saveinitmem *command-index*))
(in-package "SYSTEM")

;;---------------------------------------------------------------------------
;; Stores the current memory contents as "lispimag.mem", omitting garbage
;; collectible objects.
;; This function does not take arguments and has no local variables, since
;; otherwise in the interpreted mode the values of the variables are stored.
(defun %saveinitmem ()
  (do-all-symbols (sym) (remprop sym 'sys::definition))
  (when (fboundp 'clos::install-dispatch)
    (do-all-symbols (sym)
      (when (and (fboundp sym)
                 (typep (symbol-function sym) clos::<standard-generic-function>))
        (let ((gf (symbol-function sym)))
          (when (clos::gf-never-called-p gf)
            (clos::install-dispatch gf)
  ) ) ) ) )
  (setq - nil + nil ++ nil +++ nil * nil ** nil *** nil / nil // nil /// nil)
  (savemem "lispimag.mem" nil)
  (room nil)
)

;; Saves the current memory contents.
;; This function works only when compiled!
(defvar *saveinitmem-verbose* t
  "The default value for the :VERBOSE argument of SAVEINITMEM.")
(defun saveinitmem (&optional (filename "lispinit.mem")
                    &key ((:quiet *quiet*) nil)
                    (init-function nil init-function-p)
                    ((:verbose *saveinitmem-verbose*) *saveinitmem-verbose*)
                    ((:norc *norc*) nil)
                    ((:documentation *image-doc*)
                     (documentation init-function 'function))
                    ((:script *script*) (null init-function))
                    keep-global-handlers (start-package *package*)
                    (locked-packages *system-package-list*) executable)
  (let* ((old-driver *driver*) old-global-handlers file-size
         (*package* (sys::%find-package start-package))
         (active-restarts *active-restarts*)
         (condition-restarts *condition-restarts*)
         (fn (if (not executable)
               (merge-pathnames filename #.(make-pathname :type "mem"))
               ;; win32 executables require "exe" extension
               #+(or win32 cygwin)
               (make-pathname :type "exe" :defaults filename)
               #-(or win32 cygwin) filename)))
    ;; use setq in order not to create local per thread binding that will
    ;; not survive the savemem/loadmem. actually we need two new functions:
    ;; sys::symbol-global-value and sys::symbol-thread-value. will be added
    (setq *driver*
          #'(lambda ()
              ;;(declare (special *command-index* *home-package*))
              ;; Reset a few special variables. This must happen in the
              ;; fresh session, not in the old session, because that would
              ;; temporarily disable error handling in the old session.
              ;; Note: For GC purposes, neither is better: during savemem's
              ;; GC the old values are accessible anyway and thus not garbage
              ;; collected.
              (setq - nil
                    + nil
                    ++ nil
                    +++ nil
                    * nil
                    ** nil
                    *** nil
                    / nil
                    // nil
                    /// nil
                    *command-index* 0
                    *home-package* nil
                    ;; must make sure that the user can get clisp repl back
                    ;; from an executable image:
                    ;;  ./clisp -K boot -q -norc -x '(saveinitmem "x" :executable 0 :init-function (lambda () (print *args*) (exit)))'
                    ;; ./x --clisp-x '(ext:saveinitmem "myclisp" :executable t :init-function nil)'
                    ;; ./myclisp => [1]> ...
                    *driver* (if (and init-function-p (null init-function))
                                 #'sys::main-loop old-driver))
              (when init-function (funcall init-function))
              (funcall *driver*)))
    (unless keep-global-handlers
      (setq old-global-handlers ; disable and save all global handlers
            (ext::set-global-handler nil nil)))
    (setf (package-lock locked-packages) t)
    ;; set global not per thread ones (hopefully novody has bound them above us)
    (setq *active-restarts* nil
          *condition-restarts* nil)
    ;; we used to set *ACTIVE-RESTARTS* & *CONDITION-RESTARTS* above in the
    ;; *DRIVER* binding, but that caused mutiple ABORT restarts, bug
    ;; http://sourceforge.net/tracker/index.php?func=detail&aid=1877497&group_id=1355&atid=101355
    (setq file-size (savemem fn executable))
    ;; restore old driver
    (setq *driver* old-driver)
    ;; restore restarts
    (setq *active-restarts* active-restarts
          *condition-restarts* condition-restarts)
    (when old-global-handlers   ; re-install all global handlers
      (ext::set-global-handler old-global-handlers nil))
    (when *saveinitmem-verbose*
      (let ((*load-level* 1))   ; proper indentation
        (loading-message (TEXT "Wrote the memory image into ~A (~:D byte~:P)")
                         fn file-size))))
  (room nil))
