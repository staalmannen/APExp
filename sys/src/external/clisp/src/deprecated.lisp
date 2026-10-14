;; deprecated CLISP functionality
;; present for now, will be removed later
;; Sam Steingold 2001, 2007, 2009

;; the standard way to deprecate a function is to define a
;; compiler-macro for it which will issue a warning

(in-package "SYSTEM")

(defun deprecate (symbol superseded &optional (def (fdefinition superseded)))
  (export symbol (symbol-package symbol))
  (sys::%putd symbol def)
  (push (list symbol "Use ~S instead." superseded)
        system::*deprecated-functions-alist*)
  symbol)

;; ---------------------------------------------------------
;; `type-expand-1' -- superseded by (type-expand typespec t)

(deprecate 'ext::type-expand-1 'ext::type-expand
           (lambda (typespec) (ext::type-expand typespec t)))
#+compiler
(define-compiler-macro type-expand-1 (typespec)
  (let ((ret `(type-expand ,typespec t)))
    (c-style-warn "~S is deprecated and will be removed in a future release.
Use ~S instead."
                  'type-expand-1 ret)
    ret))

;; ------------------------------------------------
;; http://www.lisp.org/HyperSpec/Issues/iss321.html
;; `special-form-p' -- renamed to `special-operator-p'

(deprecate 'ext::special-form-p 'special-operator-p)

;; ------------------------------------------------
;; http://www.lisp.org/HyperSpec/Issues/iss308.html
;; `get-setf-method-multiple-value' -- renamed to `get-setf-expansion'
;; `define-setf-method' -- renamed to `define-setf-expander'

(deprecate 'ext::get-setf-method-multiple-value 'get-setf-expansion)
(deprecate 'ext::define-setf-method 'define-setf-expander)

;; ------------------------------------------------------

#+ffi
(progn
  (deprecate 'ffi::foreign-address-null 'null)
  (setf (cdr (assoc 'ffi::foreign-address-null system::*deprecated-functions-alist*))
        (list "The FFI now returns C NULL pointers as Lisp NIL. Use the function ~S instead." 'null)))

;; ------------------------------------------------------
;; for consistency with EXT:PROBE-DIRECTORY
;;     EXT:DEFAULT-DIRECTORY CL:PATHNAME-DIRECTORY
(deprecate 'ext::delete-dir 'delete-directory)
(deprecate 'ext::make-dir 'make-directory)
(deprecate 'ext::rename-dir 'rename-directory)
