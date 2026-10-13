;;; Parsing ordinary lambda lists
;;; Bruno Haible 1988-2004
;;; Sam Steingold 1999-2005, 2010

(in-package "SYSTEM")

;; this is the standard errfunc argument for analyze-lambdalist et al.
(defun lambda-list-error (form detail &rest args)
  (apply #'error-of-type 'ext:source-program-error
         :form form :detail detail args))

(macrolet ((push (element-form list-var)
             `(setq ,list-var (cons ,element-form ,list-var)))
           (err-misplaced (item)
             `(funcall errfunc lambdalist ,item
                       (TEXT "Lambda list marker ~S not allowed here.")
                       ,item))
           (err-invalid (item)
             `(funcall errfunc lambdalist ,item
                       (if (or (symbolp ,item) (listp ,item))
                           (TEXT "Invalid lambda list element ~S")
                           (TEXT "Invalid lambda list element ~S. A lambda list may only contain symbols and lists."))
                       ,item))
           (err-no-default (marker item)
             `(funcall errfunc lambdalist ,item
                       (TEXT "Invalid lambda list element ~S. ~S parameters cannot have default value forms in generic function lambda lists.")
                       ',marker ,item))
           (check-item (item permissible)
             `(if (memq ,item ',permissible)
                (return)
                (err-misplaced ,item)))
           (dolist ((item L) &body body)
             ;; this is different from CL:DOLIST which uses ENDP instead of ATOM
             `(loop (if (atom ,L) (return))
                (let ((,item (car ,L))) ,@body)
                (setq ,L (cdr ,L))))
           (check-exhausted (L)
             `(when ,L
                (funcall errfunc lambdalist ,L
                         (TEXT "Lambda lists with dots are only allowed in macros, not here: ~S")
                         lambdalist)))
           (symbol-or-pair-p (x) ; FOO or (FOO BAR)
             `(or (symbolp ,x)
                  (and (consp ,x)
                       (symbolp (car ,x))
                       (consp (cdr ,x))
                       (symbolp (cadr ,x))
                       (null (cddr ,x)))))
           (singleton-symbol-p (x) ; (FOO)
             `(and (consp ,x) (symbolp (car ,x)) (null (cdr ,x))))
           (err-missing (marker)
             `(funcall errfunc lambdalist lambdalist
                       (TEXT "Missing ~S parameter in lambda list ~S")
                       ',marker lambdalist))
           (last-parameter (L var marker &body body)
             `(when (and (consp ,L) (eq (car ,L) ',marker))
                (setq ,L (cdr ,L))
                (if (atom L)
                  (err-missing ,marker)
                  (prog ((item (car ,L)))
                    (if (symbolp item)
                      (if (memq item lambda-list-keywords)
                        (progn (err-missing ,marker) (return))
                        (setq ,var item))
                      (err-invalid item))
                    (setq ,L (cdr ,L))))
                ,@body))
           (process-required (L reqvar permissible &optional no-duplicates)
             `(dolist (item ,L)
                (if (symbolp item)
                  (if (memq item lambda-list-keywords)
                    (check-item item ,permissible)
                    ,(if no-duplicates
                       `(if (memq item ,reqvar)
                          (funcall errfunc lambdalist item
                                   (TEXT "Duplicate variable name ~S") item)
                          (push item ,reqvar))
                       `(push item ,reqvar)))
                  (err-invalid item))))
           (push3 (s1 s2 s3 d1 d2 d3)
             `(progn (push ,s1 ,d1) (push ,s2 ,d2) (push ,s3 ,d3)))
           (process-optional (L optvar optinit optsvar permissible)
             `(when (and (consp ,L) (eq (car ,L) '&optional))
                (setq ,L (cdr ,L))
                (dolist (item ,L)
                  (if (symbolp item)
                    (if (memq item lambda-list-keywords)
                      (check-item item ,permissible)
                      (push3 item nil 0 optvar optinit optsvar))
                    (if (and (consp item) (symbolp (car item)))
                      (if (null (cdr item))
                        (push3 (car item) nil 0 optvar optinit optsvar)
                        (if (consp (cdr item))
                          (if (null (cddr item))
                            (push3 (car item) (cadr item) 0
                                   optvar optinit optsvar)
                            (if (singleton-symbol-p (cddr item))
                              (push3 (car item) (cadr item) (caddr item)
                                     optvar optinit optsvar)
                              (err-invalid item)))
                          (err-invalid item)))
                      (err-invalid item))))))
           (process-allow-other-keys (L allow-other-keys permissible)
             `(when (and (consp ,L) (eq (car ,L) '&allow-other-keys))
                (setq ,allow-other-keys t)
                (setq ,L (cdr ,L))
                (skip-L &allow-other-keys ,permissible)))
           (process-keywords (L keyflag keyword keyvar keyinit keysvar
                              allow-other-keys permissible)
             `(when (and (consp ,L) (eq (car ,L) '&key))
                (setq ,L (cdr ,L))
                (setq ,keyflag t)
                (dolist (item ,L)
                  (if (symbolp item)
                    (if (memq item lambda-list-keywords)
                      (check-item item ,permissible)
                      (progn
                        (push (symbol-to-keyword item) ,keyword)
                        (push3 item nil 0 ,keyvar ,keyinit ,keysvar)))
                    (if (and (consp item)
                             (symbol-or-pair-p (car item))
                             (or (null (cdr item))
                                 (and (consp (cdr item))
                                      (or (null (cddr item))
                                          (singleton-symbol-p (cddr item))))))
                      (progn
                        (if (consp (car item))
                          (progn
                            (push (caar item) ,keyword)
                            (push (cadar item) ,keyvar))
                          (progn
                            (push (symbol-to-keyword (car item)) ,keyword)
                           (push (car item) ,keyvar)))
                        (if (consp (cdr item))
                          (progn
                            (push (cadr item) ,keyinit)
                            (if (consp (cddr item))
                              (push (caddr item) ,keysvar)
                              (push 0 ,keysvar)))
                          (progn (push nil ,keyinit) (push 0 ,keysvar))))
                      (err-invalid item))))
               ;; Now (or (atom L) (member (car L) permissible)).
               (process-allow-other-keys ,L ,allow-other-keys
                                         ,(cdr permissible))))
           (skip-L (lastseen items)
             `(dolist (item L)
                (if (memq item lambda-list-keywords)
                  (check-item item ,items)
                  (funcall errfunc lambdalist item
                           ,(case lastseen
                              ((&REST &ENVIRONMENT) '(TEXT "Lambda list element ~S is superfluous. Only one variable is allowed after ~S."))
                              (&ALLOW-OTHER-KEYS '(TEXT "Lambda list element ~S is superfluous. No variable is allowed right after ~S."))
                              (t '(TEXT "Lambda list element ~S (after ~S) is superfluous.")))
                           item ',lastseen)))))

;;; Analyzes a lambda-list of a function (CLtL2 p. 76, ANSI CL 3.4.1.).
;;; Reports errors through errfunc (a function taking form & detail objects,
;;;  an error format string and format string arguments).
;; Returns 13 values:
;; 1. list of required parameters
;; 2. list of optional parameters
;; 3. list of init-forms of the optional parameters
;; 4. list of supplied-vars for the optional parameters (0 for the missing)
;; 5. &rest parameter or 0
;; 6. flag, if keywords are allowed
;; 7. list of keywords
;; 8. list of keyword parameters
;; 9. list of init-forms of the keyword parameters
;; 10. list of supplied-vars for the keyword parameters (0 for the missing)
;; 11. flag, if other keywords are allowed
;; 12. list of &aux variables
;; 13. list of init-forms of the &aux variables
(defun analyze-lambdalist (lambdalist errfunc)
  (let ((L lambdalist) ; rest of the lambda-list
        (reqvar nil)
        (optvar nil)
        (optinit nil)
        (optsvar nil)
        (rest 0)
        (keyflag nil)
        (keyword nil)
        (keyvar nil)
        (keyinit nil)
        (keysvar nil)
        (allow-other-keys nil)
        (auxvar nil)
        (auxinit nil))
    ;; The lists are all accumulated in reversed order.
    ;; Required parameters:
    (process-required L reqvar (&optional &rest &key &aux))
    ;; Now (or (atom L) (member (car L) '(&optional &rest &key &aux))).
    ;; Optional parameters:
    (process-optional L optvar optinit optsvar (&rest &key &aux))
    ;; Now (or (atom L) (member (car L) '(&rest &key &aux))).
    ;; &rest parameters:
    (last-parameter L rest &rest (skip-L &rest (&key &aux)))
    ;; Now (or (atom L) (member (car L) '(&key &aux))).
    ;; Keyword & Allow-other-keys parameters:
    (process-keywords L keyflag keyword keyvar keyinit keysvar
                      allow-other-keys (&allow-other-keys &aux))
    ;; Now (or (atom L) (member (car L) '(&aux))).
    ;; &aux variables:
    (when (and (consp L) (eq (car L) '&aux))
      (setq L (cdr L))
      (dolist (item L)
        (if (symbolp item)
          (if (memq item lambda-list-keywords)
            (err-misplaced item)
            (progn (push item auxvar) (push nil auxinit)))
          (if (and (consp item) (symbolp (car item)))
            (if (null (cdr item))
              (progn (push (car item) auxvar) (push nil auxinit))
              (if (and (consp (cdr item)) (null (cddr item)))
                (progn (push (car item) auxvar) (push (cadr item) auxinit))
                (err-invalid item)))
            (err-invalid item)))))
    ;; Now (atom L).
    (check-exhausted L)
    (values
      (nreverse reqvar)
      (nreverse optvar) (nreverse optinit) (nreverse optsvar)
      rest
      keyflag
      (nreverse keyword) (nreverse keyvar) (nreverse keyinit) (nreverse keysvar)
      allow-other-keys
      (nreverse auxvar) (nreverse auxinit))))

;;; Analyzes a lambda-list of a generic function (ANSI CL 3.4.2.).
;;; Reports errors through errfunc (a function taking form & detail objects,
;;;  an error format string and format string arguments).
;; Returns 7 values:
;; 1. list of required parameters
;; 2. list of optional parameters
;; 3. &rest parameter or 0
;; 4. flag, if keywords are allowed
;; 5. list of keywords
;; 6. list of keyword parameters
;; 7. flag, if other keywords are allowed
(defun analyze-generic-function-lambdalist (lambdalist errfunc)
  (let ((L lambdalist) ; rest of the lambda-list
        (reqvar nil)
        (optvar nil)
        (rest 0)
        (keyflag nil)
        (keyword nil)
        (keyvar nil)
        (allow-other-keys nil))
    ;; The lists are all accumulated in reversed order.
    ;; Required parameters:
    ;; Need to check for duplicates here because otherwise the
    ;; :arguments-precedence-order makes no sense.
    (process-required L reqvar (&optional &rest &key) t)
    ;; Now (or (atom L) (member (car L) '(&optional &rest &key))).
    ;; Optional parameters:
    (when (and (consp L) (eq (car L) '&optional))
      (setq L (cdr L))
      (dolist (item L)
        (if (symbolp item)
          (if (memq item lambda-list-keywords)
            (check-item item (&rest &key))
            (push item optvar))
          (if (and (consp item) (symbolp (car item)))
            (if (null (cdr item))
              (push (car item) optvar)
              (err-no-default &optional item))
            (err-invalid item)))))
    ;; Now (or (atom L) (member (car L) '(&rest &key))).
    ;; &rest parameters:
    (last-parameter L rest &rest (skip-L &rest (&key)))
    ;; Now (or (atom L) (member (car L) '(&key))).
    ;; Keyword parameters:
    (when (and (consp L) (eq (car L) '&key))
      (setq L (cdr L))
      (setq keyflag t)
      (dolist (item L)
        (if (symbolp item)
          (if (memq item lambda-list-keywords)
            (check-item item (&allow-other-keys))
            (progn
              (push (symbol-to-keyword item) keyword)
              (push item keyvar)))
          (if (and (consp item)
                   (symbol-or-pair-p (car item)))
            (if (null (cdr item))
              (if (consp (car item))
                (progn
                  (push (caar item) keyword)
                  (push (cadar item) keyvar))
                (progn
                  (push (symbol-to-keyword (car item)) keyword)
                  (push (car item) keyvar)))
              (err-no-default &key item))
            (err-invalid item))))
      ;; Now (or (atom L) (member (car L) '(&allow-other-keys))).
      (process-allow-other-keys L allow-other-keys ()))
    ;; Now (atom L).
    (check-exhausted L)
    (values
      (nreverse reqvar)
      (nreverse optvar)
      rest
      keyflag
      (nreverse keyword) (nreverse keyvar)
      allow-other-keys)))

;;; Analyzes a defsetf lambda-list (ANSI CL 3.4.7.).
;;; Reports errors through errfunc (a function taking form & detail objects,
;;;  an error format string and format string arguments).
;; Returns 12 values:
;; 1. list of required parameters
;; 2. list of optional parameters
;; 3. list of init-forms of the optional parameters
;; 4. list of supplied-vars for the optional parameters (0 for the missing)
;; 5. &rest parameter or 0
;; 6. flag, if keywords are allowed
;; 7. list of keywords
;; 8. list of keyword parameters
;; 9. list of init-forms of the keyword parameters
;; 10. list of supplied-vars for the keyword parameters (0 for the missing)
;; 11. flag, if other keywords are allowed
;; 12. &environment parameter or 0
(defun analyze-defsetf-lambdalist (lambdalist errfunc)
  (let ((L lambdalist) ; rest of the lambda-list
        (reqvar nil)
        (optvar nil)
        (optinit nil)
        (optsvar nil)
        (rest 0)
        (keyflag nil)
        (keyword nil)
        (keyvar nil)
        (keyinit nil)
        (keysvar nil)
        (allow-other-keys nil)
        (env 0))
    ;; The lists are all accumulated in reversed order.
    ;; Required parameters:
    (process-required L reqvar (&optional &rest &key &environment))
    ;; Now (or (atom L) (member (car L) '(&optional &rest &key &environment))).
    ;; Optional parameters:
    (process-optional L optvar optinit optsvar (&rest &key &environment))
    ;; Now (or (atom L) (member (car L) '(&rest &key &environment))).
    ;; &rest parameters:
    (last-parameter L rest &rest (skip-L &rest (&key &environment)))
    ;; Now (or (atom L) (member (car L) '(&key &environment))).
    ;; Keyword & Allow-other-keys parameters:
    (process-keywords L keyflag keyword keyvar keyinit keysvar
                      allow-other-keys (&allow-other-keys &environment))
    ;; Now (or (atom L) (member (car L) '(&environment))).
    ;; &environment parameter:
    (last-parameter L env &environment (skip-L &environment ()))
    ;; Now (atom L).
    (check-exhausted L)
    (values
      (nreverse reqvar)
      (nreverse optvar) (nreverse optinit) (nreverse optsvar)
      rest
      keyflag
      (nreverse keyword) (nreverse keyvar) (nreverse keyinit) (nreverse keysvar)
      allow-other-keys
      env)))

;;; Analyzes a define-modify-macro lambda-list (ANSI CL 3.4.9.).
;;; Reports errors through errfunc (a function taking form & detail objects,
;;;  an error format string and format string arguments).
;; Returns 5 values:
;; 1. list of required parameters
;; 2. list of optional parameters
;; 3. list of init-forms of the optional parameters
;; 4. list of supplied-vars for the optional parameters (0 for the missing)
;; 5. &rest parameter or 0
(defun analyze-modify-macro-lambdalist (lambdalist errfunc)
  (let ((L lambdalist) ; rest of the lambda-list
        (reqvar nil)
        (optvar nil)
        (optinit nil)
        (optsvar nil)
        (rest 0))
    ;; The lists are all accumulated in reversed order.
    ;; Required parameters:
    (process-required L reqvar (&optional &rest))
    ;; Now (or (atom L) (member (car L) '(&optional &rest))).
    ;; Optional parameters:
    (process-optional L optvar optinit optsvar (&rest))
    ;; Now (or (atom L) (member (car L) '(&rest))).
    ;; &rest parameters:
    (last-parameter L rest &rest (skip-L &rest ()))
    ;; Now (atom L).
    (check-exhausted L)
    (values
      (nreverse reqvar)
      (nreverse optvar) (nreverse optinit) (nreverse optsvar)
      rest)))

;;; Analyzes a define-method-combination lambda-list (ANSI CL 3.4.10.).
;;; Reports errors through errfunc (a function taking form & detail objects,
;;;  an error format string and format string arguments).
;; Returns 14 values:
;; 1. &whole parameter or 0
;; 2. list of required parameters
;; 3. list of optional parameters
;; 4. list of init-forms of the optional parameters
;; 5. list of supplied-vars for the optional parameters (0 for the missing)
;; 6. &rest parameter or 0
;; 7. flag, if keywords are allowed
;; 8. list of keywords
;; 9. list of keyword parameters
;; 10. list of init-forms of the keyword parameters
;; 11. list of supplied-vars for the keyword parameters (0 for the missing)
;; 12. flag, if other keywords are allowed
;; 13. list of &aux variables
;; 14. list of init-forms of the &aux variables
(defun analyze-method-combination-lambdalist (lambdalist errfunc)
  (let ((L lambdalist) ; rest of the lambda-list
        (whole 0))
    ;; The lists are all accumulated in reversed order.
    ;; &whole parameter:
    (last-parameter L whole &whole)
    ;; The rest should be an ordinary lambda-list.
    (multiple-value-bind (reqvar optvar optinit optsvar rest
                          keyflag keyword keyvar keyinit keysvar allow-other-keys
                          auxvar auxinit)
        (analyze-lambdalist L errfunc)
      (values
        whole
        reqvar
        optvar optinit optsvar
        rest
        keyflag
        keyword keyvar keyinit keysvar
        allow-other-keys
        auxvar auxinit))))

) ; macrolet
