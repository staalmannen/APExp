#!@CLISP@ -C
;; work around a possible bug in ln(1) on symbolic links:
;; according to the Linux ln(1):
;;    "making a hard link to a symbolic link is not portable":
;; SVR4 (Solaris, Linux) create symbolic links
;;    (breaks when the target is relative)
;; Cygwin (1.3.12) is even worse: it makes hard links to the symbolic link,
;;    instead of resolving the symbolic link.
;; Good behavior means creating a hard link to the symbolic link's target.
;; this bug is detected by CL_PROG_HLN in src/m4/ln.m4
;; cf gl_AC_FUNC_LINK_FOLLOWS_SYMLINK in gnulib/m4/link-follow.m4
;;
;; To avoid this, use this lisp program: the syscalls module works
;; around the above difficulty

(unless (cdr *args*)
  (error "~A(~S): too few arguments" *load-truename* *args*))
(setq *args* (nreverse *args*))
(defparameter *dest* (pop *args*))
(when (cdr *args*) ; more than 2 arguments ==> destination must be a directory
  (unless (char= #\/ (char *dest* (1- (length *dest*))))
    (setq *dest* (string-concat *dest* "/"))))
(dolist (f *args*)
  (posix:copy-file f *dest* :method :hardlink-or-copy))
