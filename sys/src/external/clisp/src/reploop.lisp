;;;; Debugger, Stepper, Errors

(in-package "EXT")
(export
 '(custom::*prompt-start* custom::*prompt-step* custom::*prompt-break*
   custom::*prompt-body* custom::*prompt-finish* custom::*user-commands*)
 "CUSTOM")
(ext:re-export "CUSTOM" "EXT")
(export
 '(*command-index* prompt-new-package
   break-level step-level)
 "EXT")
(in-package "SYSTEM")

;;;--------------------------------------------------------------------------
;;;                                 Debugger

;; Number of active break-loops (Fixnum >=0)
(defvar *break-count* 0)

;; Defines how many frames will be displayed.
;; Initially nil, this means all frames will be printed.
(defvar *debug-print-frame-limit* nil)


;; Counter to avoid infinite recursion due to *error-output*
(defvar *recurse-count-error-output* 0)

;; Counter to avoid infinite recursion due to *debug-io*
(defvar *recurse-count-debug-io* 0)

; The number of commands received so far.
(defvar *command-index* 0)

;; The starting package of this session (used here and in SAVEINITMEM)
(defvar *home-package* nil)

;; Returns the current package or NIL if it never changed.
(defun prompt-new-package ()
  (unless *home-package* (setq *home-package* *package*))
  (unless (eq *home-package* *package*) *package*))

(defmacro prompt-to-string (variable)
  `(typecase ,variable
     (string ,variable)
     (function
      (multiple-value-bind (value error) (ignore-errors (funcall ,variable))
        (if error
            (string-concat ,(symbol-name variable) "->"
                           (symbol-name (type-of error)))
            (if (stringp value) value
                (princ-to-string value)))))
     (t (princ-to-string ,variable))))

;; Prompt - first part:
(defvar *prompt-start* ""
  "The initial part of the prompt, defaults to an empty string.")
(defun prompt-start () (prompt-to-string *prompt-start*))

(defun break-level () *break-count*)
(defvar *prompt-break*
  (lambda () (string-concat "Break " (princ-to-string (break-level)) " "))
  "The break level part of the prompt, may use `EXT:BREAK-LEVEL'.")
(defun prompt-break () (prompt-to-string *prompt-break*))

(defvar *prompt-body*
  (lambda ()
    ;; prompt with *package* when it is different from the initial one
    ;; or when it doesn't contain standard LISP symbols, like T.
    (if (and (packagep *package*) (package-name *package*))
        (format nil "~@[~a~][~:d]"
                (if (or (not (find-symbol "T" *package*))
                        (prompt-new-package))
                    ;; use symbol so that ~A will respect *PRINT-CASE*
                    (make-symbol (package-shortest-name *package*)))
                (incf *command-index*))
        (TEXT "[*package* invalid]")))
  "The main top level prompt.")
(defun prompt-body () (prompt-to-string *prompt-body*))

;; Prompt: last part
(defvar *prompt-finish* "> "
  "The final part of the prompt")
(defun prompt-finish () (prompt-to-string *prompt-finish*))

;; http://sourceforge.net/tracker/index.php?func=detail&aid=1865636&group_id=1355&atid=101355
;; [ 1865636 ] infinite recursive error reporting
(defun safe-wr-st (string &optional (stream *standard-output*))
  (handler-case (write-string string stream)
    (system::charset-type-error ()
      (format stream "Unprintable message: change ~S or ~S" '*current-language*
              '*terminal-encoding*))))

;; Help-function:
(defvar *key-bindings* nil)     ; list of key-bindings and help strings
(defun help ()
  (dolist (s *key-bindings*)
    (when (stringp s)
      (safe-wr-st s #|*debug-io*|#))))

(defun show-local-symbols (argline)
  (setq argline (trim-if #'whitespacep argline))
  (let ((l '())
        (package (if (equal argline "") *package*
                     (or (find-package argline)
                         argline)))) ; for error reporting
    (do-symbols (s package)
      (when (eq package (symbol-package s))
        (push s l)))
    (princ l)
    (throw 'debug 'continue)))

(defvar *saved-debug-package* *common-lisp-user-package*)
(defvar *saved-debug-readtable* (copy-readtable nil))
(defun debug-reset-io (a)
  (declare (ignore a))
  (rotatef *package* *saved-debug-package*)
  (rotatef *readtable* *saved-debug-readtable*)
  (fresh-line *debug-io*)
  (format *debug-io* (TEXT "Reset *PACKAGE* to ~s") *package*)
  (throw 'debug 'continue))

;; Components of the Break-Loop:
(defvar *debug-frame*)
(defvar *stack-mode* 4)
; lower bound for frame-down
(defvar *frame-limit-down* nil)
; upper bound for frame-up
(defvar *frame-limit-up* nil)

(defun frame-limit-down (frames-to-skip)
  (let ((frame (the-frame)))
    (let ((*frame-limit-down* nil)
          (*frame-limit-up* nil))
      (dotimes (i frames-to-skip) (setq frame (frame-up 1 frame 1))))
    frame))

(defun frame-limit-up ()
  (let ((frame (the-frame)))
    (let ((*frame-limit-down* nil)
          (*frame-limit-up* nil))
      (loop
       (let ((nextframe (frame-up 1 frame 1)))
         (when (or (eq nextframe frame) (driver-frame-p nextframe)) (return))
         (setq frame nextframe)))
      (dotimes (i 2) (setq frame (frame-down 1 frame 1))))
    frame))

(defun debug-help (a) (declare (ignore a))  (help) (throw 'debug 'continue))
(defun debug-unwind (a) (declare (ignore a)) (throw 'debug 'unwind))
(defun debug-quit (a) (declare (ignore a)) (throw 'debug 'abort-to-top))
(defun stack-mode (argline &key (start 0) (end (length argline)))
  (multiple-value-bind (mode pos)
      (read-from-string argline nil *stack-mode* :start start :end end)
    (check-type mode (integer 1 5))
    (values mode pos)))
(defun debug-mode (argline)
  (setq *stack-mode* (stack-mode argline)) (throw 'debug 'continue))

(defun debug-where (a)
  (declare (ignore a))
  (describe-frame *standard-output* *debug-frame*)
  (throw 'debug 'continue))

(defun debug-up (a)
  (declare (ignore a))
  (describe-frame *standard-output*
                  (setq *debug-frame* (frame-up 1 *debug-frame* *stack-mode*)))
  (throw 'debug 'continue))

(defun debug-top (a)
  (declare (ignore a))
  (describe-frame *standard-output*
                  (setq *debug-frame* (frame-up t *debug-frame* *stack-mode*)))
  (throw 'debug 'continue))

(defun debug-down (a)
  (declare (ignore a))
  (describe-frame *standard-output*
                  (setq *debug-frame* (frame-down 1 *debug-frame*
                                                  *stack-mode*)))
  (throw 'debug 'continue))

(defun debug-bottom (a)
  (declare (ignore a))
  (describe-frame *standard-output*
                  (setq *debug-frame* (frame-down t *debug-frame*
                                                  *stack-mode*)))
  (throw 'debug 'continue))

(defun frame-limit (argline &key (start 0) (end (length argline)))
  (multiple-value-bind (limit pos)
      (read-from-string argline nil *debug-print-frame-limit*
                        :start start :end end)
    (check-type limit (or null (eql :all) integer))
    (values (if (eq limit :all) nil limit)
            pos)))

;;; sets the limit for frames to print in a backtrace
(defun debug-frame-limit (argline)
  (setq *debug-print-frame-limit* (frame-limit argline))
  (throw 'debug 'continue))

(defun frame-up-down (limit mode) (frame-down 1 (frame-up 1 limit mode) mode))

(defun print-backtrace (&key ((:out *standard-output*) *standard-output*)
                        (mode *stack-mode*) (limit *debug-print-frame-limit*))
  ;; SHOW-STACK prints its output to *STANDARD-OUTPUT*, so we bind that
  (let ((frame-count
         (show-stack
          mode limit
          (frame-up-down (or *frame-limit-down* (frame-limit-down 13)) mode))))
    (fresh-line *standard-output*)
    (format *standard-output* (TEXT "Printed ~D frame~:P") frame-count)
    (elastic-newline *standard-output*)))

;;; debug-backtrace with-optional 'print-limit'
(defun debug-backtrace (argline)
  (multiple-value-bind (mode pos) (stack-mode argline)
    (print-backtrace :out *debug-io* :mode mode
                     :limit (frame-limit argline :start pos)))
  (throw 'debug 'continue))

(defun debug-trap-on (a)
  (declare (ignore a))
  (trap-eval-frame *debug-frame* t)
  (throw 'debug 'continue))

(defun debug-trap-off (a)
  (declare (ignore a))
  (trap-eval-frame *debug-frame* nil)
  (throw 'debug 'continue))

(defun debug-redo (a)
  (declare (ignore a))
  (redo-eval-frame *debug-frame*)
  (throw 'debug 'continue))

(defun debug-return (argline)
  (return-from-eval-frame *debug-frame* (read-from-string argline))
  (throw 'debug 'continue))
(defun debug-continue (a) (declare (ignore a)) (throw 'debug 'quit))

;;; New command to print the error message again
(defun debug-print-error (a)
  (declare (ignore a))
  ;; condition is local to break-loop so have to go back there
  (throw 'debug 'print-error))
(defun debug-inspect-error (a)
  (declare (ignore a))
  (throw 'debug 'inspect-error))

;;; print it
(defun print-error (condition)
  (fresh-line *debug-io*)
  (safe-wr-st (TEXT "The last error:") *debug-io*)
  (pretty-print-condition condition *debug-io* :text-indent 3)
  (elastic-newline *debug-io*))

(defvar *user-commands* nil
  "The list of functions, each of which should return a list of bindings.
A `binding' is either a doc string (printed by `Help' or `:h')
or a pair (STRING . FUNCTION) so that typing STRING will call FUNCTION.")

(defun wrap-user-commands (functions)
  "wrap user commands in THROWs"
  (mapcar (lambda (binding)
            (etypecase binding
              (string binding)
              (cons (cons (car binding)
                          (lambda (argline)
                            (funcall (cdr binding) argline)
                            (throw 'debug 'continue))))))
          (mapcap #'funcall functions)))

;; extended commands
(defun commands0 ()
  (list*
   (TEXT "You are in the top-level Read-Eval-Print loop.
Help (abbreviated :h) = this list
Use the usual editing capabilities.
\(quit) or (exit) leaves CLISP.")

   (cons "Help"         #'debug-help)
   (cons ":h"           #'debug-help)
   (cons "?"            #'debug-help)
   (cons "LocalSymbols" #'show-local-symbols)
   (cons ":ls"          #'show-local-symbols)
   (wrap-user-commands *user-commands*)))

(defun commands1 ()
  (list
   (TEXT "
Commands may be abbreviated as shown in the second column.
COMMAND        ABBR     DESCRIPTION
Help           :h, ?    print this command list
Error          :e       print the last error message
Inspect        :i       inspect the last error
Abort          :a       abort to the next recent input loop
Unwind         :uw      abort to the next recent input loop
Reset          :re      toggle *PACKAGE* and *READTABLE* between the
                          local bindings and the sane values
Quit           :q       quit to the top-level input loop
Where          :w       inspect this frame
Up             :u       go up one frame, inspect it
Top            :t       go to top frame, inspect it
Down           :d       go down one frame, inspect it
Bottom         :b       go to bottom (most recent) frame, inspect it
Mode mode      :m       set stack mode for Backtrace: 1=all the stack elements
             2=all the frames                         3=only lexical frames
             4=only EVAL and APPLY frames (default)   5=only APPLY frames
Frame-limit n  :fl      set the frame-limit for Backtrace. This many frames
                          will be printed in a backtrace at most.
Backtrace [mode [limit]] :bt  inspect the stack
Break+         :br+     set breakpoint in EVAL frame
Break-         :br-     disable breakpoint in EVAL frame
Redo           :rd      re-evaluate form in EVAL frame
Return value   :rt      leave EVAL frame, prescribing the return values")
   (cons "Help"         #'debug-help  )
   (cons ":h"           #'debug-help  )
   (cons "?"            #'debug-help  )
   (cons "LocalSymbols" #'show-local-symbols)
   (cons ":ls"          #'show-local-symbols)
   (cons "Error"        #'debug-print-error)
   (cons ":e"           #'debug-print-error)
   (cons "Inspect"      #'debug-inspect-error)
   (cons ":i"           #'debug-inspect-error)
   (cons "Abort"        #'debug-unwind)
   (cons ":a"           #'debug-unwind)
   (cons "Unwind"       #'debug-unwind)
   (cons ":uw"          #'debug-unwind)
   (cons "Reset"        #'debug-reset-io)
   (cons ":re"          #'debug-reset-io)
   (cons "Quit"         #'debug-quit)
   (cons ":q"           #'debug-quit)
   (cons "Where"        #'debug-where )
   (cons ":w"           #'debug-where )
   (cons "Up"           #'debug-up    )
   (cons ":u"           #'debug-up    )
   (cons "Top"          #'debug-top   )
   (cons ":t"           #'debug-top   )
   (cons "Down"         #'debug-down  )
   (cons ":d"           #'debug-down  )
   (cons "Bottom"       #'debug-bottom)
   (cons ":b"           #'debug-bottom)
   (cons "Mode"         #'debug-mode)
   (cons ":m"           #'debug-mode)
   (cons "Frame-limit"  #'debug-frame-limit)
   (cons ":fl"          #'debug-frame-limit)
   (cons "Backtrace"    #'debug-backtrace)
   (cons ":bt"          #'debug-backtrace)))

(defun commands2 ()
  (list
   (cons "Break+"       #'debug-trap-on )
   (cons ":br+"         #'debug-trap-on )
   (cons "Break-"       #'debug-trap-off)
   (cons ":br-"         #'debug-trap-off)
   (cons "Redo"         #'debug-redo  )
   (cons ":rd"          #'debug-redo  )
   (cons "Return"       #'debug-return)
   (cons ":rt"          #'debug-return)))

(defun commands3 ()
  (list
   (TEXT "
Continue       :c       continue evaluation")
   (cons "Continue"     #'debug-continue)
   (cons ":c"           #'debug-continue)))

(defun commands4 ()
  (list
   (TEXT "
Step           :s       step into form: evaluate this form in single step mode
Next           :n       step over form: evaluate this form at once
Over           :o       step over this level: evaluate at once up to the next return
Continue       :c       switch off single step mode, continue evaluation
-- Step-until :su, Next-until :nu, Over-until :ou, Continue-until :cu --
           same as above, specify a condition when to stop")
   (cons "Step"         #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'into)))
   (cons ":s"           #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'into)))
   (cons "Next"         #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'over)))
   (cons ":n"           #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'over)))
   (cons "Over"         #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'over-this-level)))
   (cons ":o"           #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'over-this-level)))
   (cons "Continue"     #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'continue)))
   (cons ":c"           #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper 'continue)))
   (cons "Step-until"   #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'into t))))
   (cons ":su"          #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'into t))))
   (cons "Next-until"   #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'over t))))
   (cons ":nu"          #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'over t))))
   (cons "Over-until"   #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'over-this-level t))))
   (cons ":ou"          #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'over-this-level t))))
   (cons "Continue-until" #'(lambda (a) (declare (ignore a))
                                    (throw 'stepper (values 'continue t))))
   (cons ":cu"          #'(lambda (a) (declare (ignore a))
                                  (throw 'stepper (values 'continue t))))))

(defun commands (may-continue commandsr)
  (nconc (commands1)
         (when (eval-frame-p *debug-frame*)
           (commands2))
         (when may-continue
           (commands3))
         commandsr
         (wrap-user-commands *user-commands*)))

;; establish the DEBUG catcher and the ABORT restart
(defmacro with-abort-restart ((&key report) &body body)
  `(catch 'debug
     (with-restarts ((ABORT () :report (lambda (s) (write-string ,report s))
                       (throw 'debug 'continue)))
       ,@body)))

;; Main-Loop with additional help-command
(defun main-loop (&optional (exit t))
  (setq *break-count* 0)
  (driver                 ; build driver-frame; do #'lambda "infinitely"
   #'(lambda ()
       (with-abort-restart (:report (TEXT "Abort main loop"))
         ;; ANSI CL wants an ABORT restart to be available.
         (when (read-eval-print   ; read-eval-print INPUT-line
                (string-concat (prompt-start) (prompt-body) (prompt-finish))
                (commands0))
           ;; T -> #<EOF>
           ;; NIL -> form is already evaluated
           ;;        result has been printed
           (if exit
               ;; if you want to change this logic, you need to make sure that
               ;; 1. "clisp -x (1+ 2) -repl" prints "3" and then the prompt
               ;; 2. "cat script | clisp" and "clisp < script" do not hang
               (exit)
               (progn (setq *command-index* 0) ; reset *command-index*
                      (handler-case (return-from main-loop)
                        (error () (exit 1))))))))))

(setq *driver* #'main-loop)

(defun break-loop (continuable &optional (condition nil) (print-it nil)
                   &aux
                   (may-continue
                    (or continuable
                        (and condition
                             (let ((restart
                                     (find-restart 'CONTINUE condition)))
                               (and restart
                                    ;; Ignore the CONTINUE restart if it is not
                                    ;; useful without prior corrective action,
                                    ;; otherwise it leads to user frustration.
                                    (restart-meaningfulp restart)
                                    restart)))))
                   (interactive-p (interactive-stream-p *debug-io*))
                   (commandsr '()))
  (when (and print-it (typep condition (clos:find-class 'condition)))
    (symbol-stream '*error-output* :output)

    ;; print something on *error-output* but catch infinite recursion.
    (let ((*recurse-count-error-output* (1+ *recurse-count-error-output*)))
      (when (> *recurse-count-error-output* 3)
        (setq *recurse-count-error-output* 0)
        (makunbound '*error-output*)
        (let ((*recurse-count-debug-io* (1+ *recurse-count-debug-io*)))
          (when (> *recurse-count-debug-io* 3)
            (setq *recurse-count-debug-io* 0)
            (makunbound '*debug-io*)
            (symbol-stream '*debug-io* :io))
          (symbol-stream '*error-output* :output)))
      (terpri *error-output*))

    (if may-continue
      (progn
        (write-string "** - " *error-output*)
        (safe-wr-st (TEXT "Continuable Error") *error-output*)
        (terpri *error-output*))
      (write-string "*** - " *error-output*))

    ;; Output the error message, but don't trap into recursive errors.
    (let ((*recursive-error-count* (1+ *recursive-error-count*)))
      (if (> *recursive-error-count* 3)
        (progn
          (setq *recursive-error-count* 0)
          (write-string (TEXT "Unprintable error message")
                        *error-output*))
        (pretty-print-condition condition *error-output*
                                :text-indent (if may-continue 5 6))))

    ;; Now the error message is on the screen; give the user some information
    ;; how to continue from continuable errors.
    (symbol-stream '*debug-io* :io)
    (when may-continue
      (if continuable
        (when interactive-p
          (fresh-line *debug-io*)
          (safe-wr-st (TEXT "You can continue (by typing 'continue').")
                      *debug-io*)
          (elastic-newline *debug-io*))
        (progn
          (fresh-line *debug-io*)
          (when interactive-p
            (safe-wr-st (TEXT "If you continue (by typing 'continue'): ")
                        *debug-io*))
          (princ may-continue *debug-io*)
          (elastic-newline *debug-io*)))))

  (when condition
    (let ((restarts (remove may-continue (compute-restarts condition)))
          (restarts-help (if may-continue
                           (TEXT "The following restarts are also available:")
                           (TEXT "The following restarts are available:"))))
      (when restarts
        (when interactive-p
          (fresh-line *debug-io*)
          (safe-wr-st restarts-help *debug-io*)
          (elastic-newline *debug-io*))
        (let ((counter 0))
          (dolist (restart restarts)
            (let* ((command
                    (string-concat ":R" (sys::decimal-string (incf counter))))
                   (name (string (restart-name restart)))
                   (helpstring (format nil "~A~15T~A~24T~A" name command
                                       (princ-to-string restart)))
                   (restart restart)  ; for FUNC
                   (func #'(lambda (a) (declare (ignore a))
                                   (invoke-restart-interactively restart))))
              ;; display the restarts:
              (when interactive-p
                (fresh-line *debug-io*)
                (safe-wr-st helpstring *debug-io*)
                (elastic-newline *debug-io*))
              (push (string-concat (string #\Newline) helpstring) commandsr)
              ;; put it into the commandsr list.
              (push (cons command func) commandsr)
              (push (cons name func) commandsr)))
          (setq commandsr (cons (string-concat (string #\Newline) restarts-help)
                                (nreverse commandsr)))))))
  (force-output *debug-io*)

  (tagbody
    (makunbound '*terminal-read-stream*)
    (makunbound '*terminal-read-open-object*)
    (clear-input *debug-io*) ; because the user did not expect a break loop
    (let* ((*break-count* (1+ *break-count*))
           (stream (make-synonym-stream '*debug-io*))
           (*standard-input* stream)
           (*standard-output* stream)
           (prompt (string-concat (prompt-start) (prompt-break)
                                  (prompt-body) (prompt-finish)))
           (*frame-limit-down* (frame-limit-down 13))
           (*frame-limit-up* (frame-limit-up))
           (*stack-mode* *stack-mode*)
           (*debug-frame* (frame-up-down *frame-limit-down* *stack-mode*))
           (*saved-debug-package* *saved-debug-package*)
           (*saved-debug-readtable* *saved-debug-readtable*)
           (commands-list (commands may-continue commandsr)))
      (driver
       ;; build driver frame and repeat #'lambda (infinitely; ...)
       #'(lambda ()
           (case (with-abort-restart (:report (TEXT "Abort debug loop"))
                   ;; ANSI CL wants an ABORT restart to be available.
                   ;; build environment *debug-frame*
                   ;; which is valid/equal for/to *debug-frame*
                   (same-env-as *debug-frame*
                     #'(lambda ()
                         (if (read-eval-print prompt commands-list)
                           ;; T -> #<EOF>
                           ;; NIL -> form is already evaluated;
                           ;;        result has been printed
                           (throw 'debug (if may-continue 'quit 'unwind))))))
             ((print-error) (print-error condition))
             ((inspect-error) (inspect condition))
             ((unwind) (go unwind))
             ((abort-to-top) (go abort-to-top))
             ((quit)            ; reached only if may-continue is T
              (if continuable
                (go quit)
                (invoke-restart-interactively may-continue)))
             (t )))))           ; other cases, especially continue
    unwind (unwind-to-driver nil)
    abort-to-top (unwind-to-driver t)
    quit))

(setq *break-driver* #'break-loop)


;;;--------------------------------------------------------------------------
;;;        convenient Stepper. (runs only if compiled!)

(defvar *step-level* 0 "current Step-depth") ; ABI
(defvar *step-quit* most-positive-fixnum "critical Step-depth") ; ABI
;; the stepper wakes up, as soon as *step-level* <= *step-quit*

(defvar *step-watch* nil)               ; terminating condition ; ABI

(defmacro step (form)
  "(STEP form), CLTL p. 441"
  `(let* ((*step-level* 0)
          (*step-quit* most-positive-fixnum)
          (*step-watch* nil)
          (*evalhook* #'step-hook-fn))
    ,form))

(defun step-values (values)
  (let ((*standard-output* *debug-io*))
    (fresh-line #|*debug-io*|#)
    (safe-wr-st (TEXT "step ") #|*debug-io*|#)
    (write *step-level* #|:stream *debug-io*|#)
    (write-string " ==> " #|*debug-io*|#)
    (case (length values)
      (0 (safe-wr-st (TEXT "no values") #|*debug-io*|#))
      (1 (safe-wr-st (TEXT "value: ") #|*debug-io*|#)
         (write (car values) #|:stream *debug-io*|#))
      (t (write (length values) #|:stream *debug-io*|#)
         (safe-wr-st (TEXT " values: ") #|*debug-io*|#)
         (do ((L values))
             ((endp L))
           (write (pop L) #|:stream *debug-io*|#)
           (unless (endp L) (write-string ", " #|*debug-io*|#)))))
    (elastic-newline #|*debug-io*|#))
  (values-list values))

(defun step-level () *step-level*)
(defvar *prompt-step*
  (lambda () (string-concat "Step " (princ-to-string (step-level)) " "))
  "The stepper part of the prompt, may use `EXT:STEP-LEVEL'." )
(defun prompt-step () (prompt-to-string *prompt-step*))

(defun step-hook-fn (form &optional (env *toplevel-environment*))
  (let ((*step-level* (1+ *step-level*)))
    (when (>= *step-level* *step-quit*) ; while *step-level* >= *step-quit*
      (if (and *step-watch* (funcall *step-watch*)) ; and no Breakpoint,
        (setq *step-quit* most-positive-fixnum)
        (return-from step-hook-fn       ; the Stepper remains passive
          (evalhook form nil nil env)))) ; (e.g. it simply evaluates the Form)
    (tagbody
      (let* ((stream (make-synonym-stream '*debug-io*))
             (*standard-input* stream)
             (*standard-output* stream)
             (prompt (string-concat (prompt-start) (prompt-step)
                                    (prompt-body) (prompt-finish)))
             (*frame-limit-down* (frame-limit-down 11))
             (*frame-limit-up* (frame-limit-up))
             (*stack-mode* *stack-mode*)
             (*debug-frame* (frame-up-down *frame-limit-down* *stack-mode*))
             (commands-list (commands nil (commands4))))
        (fresh-line #|*debug-io*|#)
        (safe-wr-st (TEXT "step ") #|*debug-io*|#)
        (write *step-level* #|:stream *debug-io*|#)
        (write-string " --> " #|*debug-io*|#)
        (write form #|:stream *debug-io*|# :length 4 :level 3)
        (loop
          (multiple-value-bind (what watchp)
              (catch 'stepper
                ;; catch the (throw 'stepper ...) and analyse ...
                (driver
                  ;;  build driver frame and repeat #'lambda (infinitely ...)
                  #'(lambda ()
                      ;; catch the (throw 'debug ...) and analyse
                      (case (with-abort-restart (:report (TEXT "Abort stepper"))
                              ;; ANSI CL wants an ABORT restart to be available.
                              (same-env-as *debug-frame*
                                ;; build environment *debug-frame* that
                                ;; is valid/equal for/to *debug-frame*
                                #'(lambda ()
                                    (if (read-eval-print prompt commands-list)
                                      ;; T -> #<EOF>
                                      (go continue)
                                      ;; NIL -> form is already evaluated;
                                      ;;        result has been printed
                                      #|(throw 'debug 'continue)|#
                                      ))))
                        ((unwind) (go unwind))
                        ((abort-to-top) (go abort-to-top))
                        (t ))))) ; other cases, especially continue
            (when watchp
              (let ((form (read-form (TEXT "condition when to stop: "))))
                (setq *step-watch*
                      ;; function which evaluates 'form' in/with *debug-frame*
                      (eval-at *debug-frame* `(function (lambda () ,form))))))
            (case what
              (into (go into))
              (over (go over))
              (over-this-level (go over-this-level))
              (continue (go continue))))))
     unwind (unwind-to-driver nil)
     abort-to-top (unwind-to-driver t)
     into
      (return-from step-hook-fn
        (step-values
         (multiple-value-list (evalhook form #'step-hook-fn nil env))))
     over-this-level
      (setq *step-quit* *step-level*)   ; keep the Stepper sleeping
     over
      (return-from step-hook-fn
        (step-values
         (multiple-value-list (evalhook form nil nil env))))
     continue
      (setq *step-quit* 0)
      (go over))))

;;;--------------------------------------------------------------------------

;; Now that condition.lisp is loaded and *break-driver* has a value:
;; Activate the Condition System.
(setq *use-clcs* t)

