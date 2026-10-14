;; Keyboard stream

(in-package "EXT")
(export '(with-keyboard *keyboard-input*))
(in-package "SYSTEM")

;;;--------------------------------------------------------------------------

(defvar *keyboard-input*)
(defmacro with-keyboard (&body body)
  `(SYS::EXEC-WITH-KEYBOARD (FUNCTION (LAMBDA () (PROGN ,@body))))
)
(defun exec-with-keyboard (fun) ; ABI
  #+WIN32 ; *keyboard-input* existiert schon
    (funcall fun)
  #+UNIX
    (let ((mode nil))
      (unless *keyboard-input*
        (setq *keyboard-input* (sys::make-keyboard-stream))
      )
      (unwind-protect
        (progn
          (setq mode (sys::terminal-raw *keyboard-input* t))
          (funcall fun)
        )
        (sys::terminal-raw *keyboard-input* mode)
)   ) )

; Used by spvw.d.
(defun wait-keypress ()
  (with-keyboard (read-char *keyboard-input*))
)

