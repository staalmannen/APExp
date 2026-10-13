;; -*- Lisp -*- vim:filetype=lisp
;; some tests for glibc
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "bindings/glibc/test")'

(progn (require "linux") T) T
(listp (show (multiple-value-list (ext:module-info "linux" t)) :pretty t)) T

(defparameter *d* (show (linux:opendir "."))) *D*
(linux:dirent64-d_name (show (linux:readdir64 *d*))) "."
(linux:dirent64-d_name (show (linux:readdir64 *d*))) ".."
(= (linux:dirent64-d_off (show (linux:readdir64 *d*))) (linux:telldir *d*)) T
(linux:seekdir *d* 0) NIL
(linux:telldir *d*) 0
(= linux:DT_DIR (linux:dirent64-d_type (show (linux:readdir64 *d*)))) T
(linux:closedir *d*) 0

(defparameter *d* (show (linux:opendir "."))) *D*
(linux:dirent-d_name (show (linux:readdir *d*))) "."
(linux:dirent-d_name (show (linux:readdir *d*))) ".."
(= (linux:dirent-d_off (show (linux:readdir *d*))) (linux:telldir *d*)) T
(linux:seekdir *d* 0) NIL
(linux:telldir *d*) 0
(= linux:DT_DIR (linux:dirent-d_type (show (linux:readdir *d*)))) T
(linux:closedir *d*) 0

(listp (show (loop :for i :from 0 :to 140
               :collect (cons i (linux:strerror i))) :pretty t)) T

;; check that we can DESCRIBE the foreign int types
(describe 'linux:wait) NIL

;;; signal handling examples:
(listp (show (loop :for i :from 0 :to linux:_NSIG
               :collect (cons i (linux:strsignal i))) :pretty t)) T

linux:SIGSET_NWORDS #+:WORD-SIZE=64 16 #-:WORD-SIZE=64 32

;;; changing signal handlers:
(defparameter *sigact* (show (linux:signal-action-retrieve linux:SIGINT)))
*SIGACT*
(defparameter *savehandler* (linux:sa-handler *sigact*))
*SAVEHANDLER*
(defparameter *signals* nil) *SIGNALS*
(defun test-handler (s) (declare (compile)) (push s *signals*)) TEST-HANDLER

(progn (setf (linux:sa-handler *sigact*) #'test-handler)
       (linux:signal-action-install linux:SIGINT *sigact*))
NIL

;; Now Ctrl-C invokes TEST-HANDLER
*signals* NIL
(os:kill (os:process-id) :SIGINT) NIL
*signals* (2)

(progn (setf (linux:sa-handler *sigact*) *savehandler*)
       (linux:signal-action-install linux:SIGINT *sigact*))
NIL                             ; the standard behavior is restored

;; this is packaged into set-signal-handler:
(progn
  (setf *savehandler* (linux:set-signal-handler linux:SIGINT #'test-handler))
  (linux:raise linux:SIGINT))
0

*signals* (2 2)                 ; TEST-HANDLER is called - received sigint

;; Please note that if you use SA_RESETHAND, you reset the handler to
;; the system's notion of default handler, not Clisp's, so if you then
;; hit Ctrl-c, you would exit Clisp!

;;; sigprocmask & sigpending
(linux:set-sigprocmask linux:SIG_BLOCK (linux:sa-mask *sigact*)) NIL
(linux:raise linux:SIGINT)      0 ; nothing happens
*signals* (2 2)                   ; no signals

(linux:sigset-pending)
#S(LINUX:sigset_t :VAL #(2))

(linux:set-sigprocmask linux:SIG_UNBLOCK (linux:sa-mask *sigact*)) NIL
*signals* (2 2 2)               ; received SIGINT

(linux:sigset-pending)  #S(LINUX:sigset_t :VAL #())

(progn (linux:set-signal-handler linux:SIGINT *savehandler*) nil)
NIL                             ; the standard behavior is restored

;; (linux:raise linux:SIGINT)
;; ==> ** - Continuable Error/PRINT: User break
