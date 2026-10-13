;; miscellaneous settings for clisp development in emacs

(eval-when-compile
  (defvar vc-dir-backend)
  (defvar change-log-default-name))

(defun clisp-repo-p (dir)
  (let ((host (vc-cvs-repository-hostname dir)))
    (and host (string-match "^clisp\\." host))))

(eval-after-load "grep"         ; for rgrep
  '(progn
    (add-to-list 'grep-files-aliases
     '("clisp" . "*.[cdfh] *.lisp *.tst *.m4 *.in Makefile* *.xml"))
    (add-to-list 'grep-find-ignored-directories
     '(clisp-repo-p . "build*"))))

(defun clisp-set-change-log-default-name ()
  "Set `change-log-default-name' appropriately."
  (when (eq (vc-backend buffer-file-name) 'CVS)
    (let ((dir (file-name-directory buffer-file-name)))
      (when (clisp-repo-p dir)
        (let ((cl (expand-file-name "ChangeLog" dir)))
          (set (make-local-variable 'change-log-default-name)
               (if (file-exists-p cl) cl
                   (expand-file-name
                    "src/ChangeLog" (locate-dominating-file
                                     buffer-file-name "ANNOUNCE")))))))))

;; append: must come after vc-find-file-hook
(add-hook 'find-file-hooks 'clisp-set-change-log-default-name t)

(defun clisp-set-change-log-vc-dir ()
  (when (and (eq vc-dir-backend 'CVS)
             (clisp-repo-p default-directory))
    (set (make-local-variable 'change-log-default-name)
         (expand-file-name "src/ChangeLog" default-directory))))

(add-hook 'vc-dir-mode-hook 'clisp-set-change-log-vc-dir)

(defun clisp-bug-reference-url-format ()
  (concat "http://sourceforge.net/tracker/index.php?func=detail&aid="
          (match-string-no-properties 2)
          "&group_id=1355&atid="
          (let ((kind (match-string-no-properties 1)))
            (cond ((string-match "[Bb]ug" kind) "101355")
                  ((string-match "[Pp]atch" kind) "301355")
                  ((string-match "RFE" kind) "351355")
                  (t (error "unknown bug kind [%s]" kind))))))

(put 'clisp-bug-reference-url-format 'bug-reference-url-format t)
