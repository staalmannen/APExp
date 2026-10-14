;; -*- Lisp -*- vim:filetype=lisp
;; some tests for SYSCALLS
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "syscalls/test")'

(require "syscalls") NIL
(listp (show (multiple-value-list (ext:module-info "syscalls" t)) :pretty t)) T

(os:hostent-p (show (os:resolve-host-ipaddr "localhost")))
T

(listp (show (os:resolve-host-ipaddr) :pretty t)) T
(os:service-p (show (os:service "smtp"))) T
(os:service-p (show (os:service 25))) T
(listp (show (os:service) :pretty t)) T

#+unix ;; (encrypt (encrypt X t) nil) == X
(handler-case
    (let* ((v (make-array 8 :element-type '(unsigned-byte 8))) (u (copy-seq v)))
      (loop :repeat 10 :do
        (dotimes (i 8) (setf (aref v i) (setf (aref u i) (random 256))))
        (os:setkey v) (show (os:encrypt v nil)) (show (os:encrypt v t))
        :never (if (equalp v u) nil (list v u))))
  (system::simple-os-error (err)
    ;; Solaris (sf cf x86-solaris1 & sparc-solaris1) encrypt fails with
    ;;  "UNIX error 89 (ENOSYS): Function not implemented"
    (format t "~S: ~A" 'os:encrypt err)
    T))
#+unix T

#+unix (crypt "foo" "bar") #+unix "ba4TuD1iozTxw"

;; same as "%F %T" on GNU, but more portable
(let* ((fmt "%Y-%m-%d %H:%M:%S") (string (show (os:string-time fmt))))
  (string= string (os:string-time fmt (show (os:string-time fmt string)))))
T

#+unix
(when (fboundp 'os:getutxent)
  (not (integerp (show (length (loop :for utmpx = (os:getutxent) :while utmpx
                                 :collect (show utmpx :pretty t)))))))
#+unix NIL

(defparameter *tmp1* (os:mkstemp "syscalls-tests-")) *tmp1*
(defparameter *tmp2* (os:mkstemp "syscalls-tests-")) *tmp2*

(let ((*standard-output* (make-broadcast-stream
                          *standard-output* *tmp1* *tmp2*)))
  (show (write *tmp1* :stream *tmp1*)) (terpri *tmp1*)
  (show (write *tmp2* :stream *tmp2*)) (terpri *tmp2*)
  T)
T

#+unix (find :rdwr (show (os:stream-options *tmp1* :fl))) #+unix :RDWR
#+unix (ext:appease-cerrors
        (with-open-file (s *tmp1*)
          (find :rdonly (show (os:stream-options s :fl)))))
#+unix :RDONLY
#+unix (os:stream-options *tmp1* :fd) NIL
#+unix (os:stream-options *tmp1* :fd '(:cloexec)) NIL
#+unix (os:stream-options *tmp1* :fd) #+unix (:cloexec)
#+unix (os:stream-options *tmp1* :fd nil) NIL
#+unix (os:stream-options *tmp1* :fd) NIL

;; may fail with ENOLCK or EOPNOTSUPP - in which case we do not test locking
(handler-case (os:stream-lock *tmp1* t)
  (system::simple-file-error (err)
    (format t "~S: ~A" 'os:stream-lock err)
    (pushnew :no-stream-lock *features*)
    T))
T
#-:no-stream-lock (os:stream-lock *tmp1* nil) #-:no-stream-lock NIL

(typep (show (os:priority (os:process-id))) '(or keyword (integer -20 20))) T

;; we are testing CLISP, not the accuracy of the underlying libc implementation
;; so we will be as lenient as necessary to ensure success
;; if FLOAT= fails, just replace it with FLOAT~
(defun float= (x y) (= y (/ (+ x y) 2))) FLOAT=
(defun float~ (x y)
  (< (abs (/ (- x y) (+ x y) 1/2)) #.(sqrt double-float-epsilon)))
FLOAT~

(float= (os:erf -6)     -1.0d0)  T
(float= (os:erf -5)     -0.9999999999984626d0)  T
(float= (os:erf -4)     -0.9999999845827421d0)  T
(float~ (os:erf -3)     -0.9999779095030014d0)  T ; MacOSX 10.4.11
(float= (os:erf -2)     -0.9953222650189527d0)  T
(float~ (os:erf -1)     -0.8427007929497149d0)  T ; MacOSX 10.4.11
(float= (os:erf 0)      0.0d0)  T
(float~ (os:erf 1)      0.8427007929497149d0)  T ; MacOSX 10.4.11
(float= (os:erf 2)      0.9953222650189527d0)  T
(float~ (os:erf 3)      0.9999779095030014d0)  T ; MacOSX 10.4.11
(float= (os:erf 4)      0.9999999845827421d0)  T
(float= (os:erf 5)      0.9999999999984626d0)  T
(float= (os:erf 6)      1.0d0)  T

(float= (os:erfc -6)    2.0d0)  T
(float= (os:erfc -5)    1.9999999999984626d0)  T
(float= (os:erfc -4)    1.999999984582742d0)  T
(float= (os:erfc -3)    1.9999779095030015d0)  T
(float= (os:erfc -2)    1.9953222650189528d0)  T
(float= (os:erfc -1)    1.842700792949715d0)  T
(float= (os:erfc 0)     1.0d0)  T
(float~ (os:erfc 1)     0.15729920705028513d0)  T ; MacOSX 10.4.11
(float= (os:erfc 2)     0.004677734981047265d0)  T
(float= (os:erfc 3)     2.209049699858544d-5)  T
(float= (os:erfc 4)     1.541725790028002d-8)  T
(float= (os:erfc 5)     1.5374597944280351d-12)  T
(float~ (os:erfc 6)     2.1519736712498916d-17)  T ; MacOSX 10.4.11
(float~ (os:erfc 7)     4.183825607779414d-23)  T  ; MacOSX 10.4.11
(float= (os:erfc 8)     1.1224297172982928d-29)  T
(float= (os:erfc 9)     4.13703174651381d-37)  T
(float= (os:erfc 10)    2.088487583762545d-45)  T
(float= (os:erfc 11)    1.4408661379436945d-54)  T
(float= (os:erfc 12)    1.3562611692059042d-64)  T
(float= (os:erfc 13)    1.7395573154667246d-75)  T
(float= (os:erfc 14)    3.037229847750312d-87)  T
(float~ (os:erfc 15)    7.212994172451206d-100)  T ; MacOSX 10.4.11
(float= (os:erfc 16)    2.3284857515715308d-113)  T
(float= (os:erfc 17)    1.0212280150942608d-127)  T
(float~ (os:erfc 18)    6.082369231816399d-143)  T ; MacOSX 10.4.11
(float= (os:erfc 19)    4.917722839256475d-159)  T
(float= (os:erfc 20)    5.3958656116079005d-176)  T
(float= (os:erfc 21)    8.032453871022456d-194)  T
(float= (os:erfc 22)    1.6219058609334726d-212)  T
(float= (os:erfc 23)    4.441265948088057d-232)  T
(float= (os:erfc 24)    1.6489825831519335d-252)  T
;; NetBSD <http://article..gmane.org/gmane.lisp.clisp.general/12716>
(float~ (os:erfc 25)    8.300172571196522d-274)  T
(float~ (os:erfc 26)    5.663192408856143d-296)  T
(float= (os:erfc 30)    0.0d0)  T

(loop :for i :from -10 :to 10
  :for e = (os:erf i) :and c = (os:erfc i)
  :for s = (+ e c)
  :unless (float= s 1) :collect (list i e c (- 1 s)))
()

(float= (os:j0 0)       1.0d0)  T
(float= (os:j0 1.0)     0.7651976865579666d0)  T
(float= (os:j1 0)       0.0d0)  T
(float= (os:j1 1.0)     0.4400505857449335d0)  T
(float= (os:jN 0 0)     1.0d0)  T
(float= (os:jN 1 1.0)   0.4400505857449335d0)     T
(float= (os:jN 2 1.0)   0.11490348493190048d0)    T
(float= (os:jN 2 1)     0.11490348493190048d0)    T
(float= (os:jN 2 0)     0.0d0)  T
(float~ (os:y0 1.0)     0.08825696421567696d0)    T
(float~ (os:y0 10.0)    0.055671167283599395d0)   T
(float~ (os:y1 1.0)     -0.7812128213002887d0)    T
(float~ (os:y1 10.0)    0.24901542420695383d0)    T
(float~ (os:yN 2 1.0)   -1.6506826068162543d0)    T
(float~ (os:yN 2 10.0)  -0.005868082442208629d0)  T
;; neither signgam not lgamma_r are defined on win32
(multiple-value-list (os:lgamma 2))   (0.0d0 #+win32 nil #-win32 1)
(mapcar (lambda (n)
          (multiple-value-bind (lg s) (os:lgamma n)
            (list n (float (/ (! (1- n)) (exp lg)) 0f0) s)))
        '(3 5 10 15 30 50 100))
((3 1f0 #+win32 nil #-win32 1) (5 1f0 #+win32 nil #-win32 1)
 (10 1f0 #+win32 nil #-win32 1) (15 1f0 #+win32 nil #-win32 1)
 (30 1f0 #+win32 nil #-win32 1) (50 1f0 #+win32 nil #-win32 1)
 (100 1f0 #+win32 nil #-win32 1))

(loop :for n :upfrom 3 :for lg = (os:lgamma n)
  :unless (= 1 (/ (log (! (1- n))) lg)) :return n)
29                    ; not bad...

(loop :for n :upfrom 3
  :for lg = (handler-case (os:lgamma n)
              (floating-point-overflow () 'floating-point-overflow))
  :for l! = (handler-case (log (float (! (1- n)) lg))
              (floating-point-overflow () 'floating-point-overflow))
  :unless (and (floatp lg) (floatp l!) (= 1 (float (/ l! lg) 0f0)))
  ;; round off at single precision: different gamma implementations have
  ;; very different levels of accuracy
  ;; <http://thread.gmane.org/gmane.lisp.clisp.devel/19047>
  :return (list n (float lg 0f0) l!))
(172 711.7147f0 FLOATING-POINT-OVERFLOW)

;; tgamma has widely varying accuracy on different platforms:
;; solaris 8: 4
;; glibc: 5
;; win32: 34
;; solaris 10: (172 FLOATING-POINT-OVERFLOW)
(loop :for n :upfrom 3
  :for tg = (handler-case (os:tgamma n)
              (floating-point-overflow () 'floating-point-overflow))
  :while (and (floatp tg) (= 1 (/ (! (1- n)) tg)))
  :finally (show (list n tg)))
NIL

(loop :for n :upfrom 3
  :for tg = (handler-case (os:tgamma n)
              (floating-point-overflow () 'floating-point-overflow))
  :unless (and (floatp tg) (= 1 (float (/ (! (1- n)) tg) 0f0)))
  :return (list n tg))
(172 FLOATING-POINT-OVERFLOW) ; ... but it IS accurate at single precision!

#+unix (= (show (os:process-id)) (show (os:getppid))) #+unix NIL
#+unix (let ((id (show (os:uid)))) (= id (setf (os:uid) id))) T
#+unix (let ((id (show (os:gid)))) (= id (setf (os:gid) id))) T
#+unix (let ((id (show (os:euid)))) (= id (setf (os:euid) id))) T
#+unix (let ((id (show (os:egid)))) (= id (setf (os:egid) id))) T
#+unix (let* ((pid (os:process-id))
              (id (show (os:pgid pid))))
         (= id (setf (os:pgid pid) id))) #+unix T
#+unix (= (os:uid) (os:euid)) T
#+unix (= (os:gid) (os:egid)) T
#+unix (multiple-value-list (os:setreuid (os:uid) (os:euid))) NIL
#+unix (multiple-value-list (os:setregid (os:gid) (os:egid))) NIL
#+unix (multiple-value-list (os:setreuid -1 -1)) NIL
#+unix (multiple-value-list (os:setregid -1 -1)) NIL
#+unix (listp (show (if (fboundp 'os:groups) (os:groups)
                        '(no os:groups)) :pretty t)) T
#+unix (if (and (fboundp 'os:groups) (fboundp 'os::%setgroups))
           (let ((g (os:groups))) ; setgroups may fail with EPERM
	     (eq g (or (ignore-errors (setf (os:groups) g)) g)))
           t) T

#+unix (listp (show (if (fboundp 'os:sysconf)
                        (os:sysconf) '(no os:sysconf)) :pretty t)) T
#+unix (listp (show (if (fboundp 'os:confstr)
                        (os:confstr) '(no os:confstr)) :pretty t)) T

#+unix (listp (show (if (fboundp 'os:pathconf)
                        (os:pathconf "/") '(no os:pathconf)) :pretty t)) T
#+unix (listp (show (if (fboundp 'os:pathconf)
                        (os:pathconf *tmp1*) '(no os:pathconf)) :pretty t)) T

#+unix
(listp (show (if (fboundp 'os:usage)
                 (multiple-value-list (os:usage)) '(no os:usage)) :pretty t))
T
#+unix
(listp (show (if (fboundp 'os:rlimit)
                 (multiple-value-list (os:rlimit)) '(no os:rlimit)) :pretty t))
T

(os:uname-p (show (os:uname) :pretty t)) T

#+unix (listp (show (os:user-info) :pretty t)) T
;; (os:user-info :default) calls getlogin which may fail in cron
#+unix (os:user-info-p
        (handler-case (show (os:user-info :default) :pretty t)
          (:error (c) (princ-error c)
                  (use-value (os:make-user-info "" "" 0 0 "" "" ""))))) T
;; some SF CF hosts (solaris, openbsd) are misconfigured:
;; user GID is 100, but there is no group with GID 100
#+unix (os:group-info-p
        (show
         (handler-bind ((error (lambda (c) (princ-error c) (use-value 0))))
           (os:group-info (os:user-info-gid (os:user-info (os:uid)))))
         :pretty t)) T
#+unix (listp (show (os:group-info) :pretty t)) T
#+unix (= (os:uid) (os:user-info-uid (os:user-info (os:uid)))) T
#+unix (= (os:gid) (os:user-info-gid (os:user-info (os:uid)))) T

(and (fboundp 'os:user-shells)
     (notevery #'stringp (show (os:user-shells)))) NIL

(os:file-stat-p (show (os:file-stat *tmp1*) :pretty t)) T
(os:file-stat-p (show (os:file-stat (pathname *tmp1*)) :pretty t)) T

#-:win32 (= (posix:file-stat-ino (os:file-stat *tmp1*))
            (posix:file-stat-ino (os:file-stat *tmp2*)))
#-:win32 NIL

(os:convert-mode #o0666)
#+unix (:RUSR :WUSR :RGRP :WGRP :ROTH :WOTH)
#+win32 (:RUSR :WUSR 54)
#-(or unix win32) ERROR

(os:convert-mode '(:RWXU #+unix :RWXG #+unix :RWXO))
#+unix #o0777
#+win32 #o0700
#-(or unix win32) ERROR

(and (fboundp 'os:stat-vfs)
     (not (os:stat-vfs-p (show (os:stat-vfs *tmp2*) :pretty t))))
NIL

;; <http://article.gmane.org/gmane.lisp.clisp.devel/19074>:
;; (FILE-OWNER *TMP1*) ==> "BUILTIN\\Administrators"
;; - local group name, which actually owns the file and includes
;; "OFFICE_DOMAIN\\Kavenchuk_Yaroslav" - a member of a windows NT domain.
;; so, if the user is not local - the test will be always broken,
;; but all functions are working correctly (in terms of MS).
#+unix
(string= (show #+win32 (ext:string-concat (ext:getenv "USERDOMAIN") "\\"
                                          (ext:getenv "USERNAME"))
               ;; $USER is void when running as root on MacOSX 10.4.11
               ;; <http://article.gmane.org/gmane.lisp.clisp.devel/20248>
               #+unix (or (ext:getenv "USER")
                          (posix:user-info-login-id
                           (show (posix:user-info :default))))
               #-(or unix win32) ERROR)
         (show (os:file-owner *tmp1*)))
#+unix T

(progn (close *tmp1*) (close *tmp2*) T) T

(listp (show (os:copy-file *tmp1* *tmp2* :if-exists :append))) T
(listp (show (os:copy-file *tmp2* *tmp1* :if-exists :append))) T
(listp (show (os:copy-file *tmp1* *tmp2* :if-exists :append))) T
(listp (show (os:copy-file *tmp2* *tmp1* :if-exists :append))) T
(listp (show (os:copy-file *tmp1* *tmp2* :if-exists :append))) T
(listp (show (os:copy-file *tmp2* *tmp1* :if-exists :append))) T
(listp (show (os:copy-file *tmp1* *tmp2* :if-exists :append))) T
(listp (show (os:copy-file *tmp2* *tmp1* :if-exists :append))) T
(listp (show (os:copy-file *tmp1* *tmp2* :if-exists :append))) T
(listp (show (os:copy-file *tmp2* *tmp1* :if-exists :append))) T

(integerp (show (with-open-file (s *tmp1* :direction :input) (file-length s))))
T

(integerp (show (with-open-file (s *tmp2* :direction :input) (file-length s))))
T

(let ((src "src-file") (dst "dst-file"))
  (open src :direction :probe :if-does-not-exist :create) ; touch
  (open dst :direction :probe :if-does-not-exist :create) ; touch
  (unwind-protect
       (handler-case
           (multiple-value-list (os:copy-file src dst :method :rename
                                              :if-exists :error))
         (error (e) (princ-error e) :good))
    (delete-file src)
    (delete-file dst)))
:GOOD

(let ((src "src-file") (dst "dst-file") inode)
  (open src :direction :probe :if-does-not-exist :create) ; touch
  (open dst :direction :probe :if-does-not-exist :create) ; touch
  (setq inode (posix:file-stat-ino (posix:file-stat src)))
  (unwind-protect
       (progn (os:copy-file src dst :method :rename :if-exists :overwrite)
              (= inode (posix:file-stat-ino (posix:file-stat dst))))
    (delete-file src)
    (delete-file dst)))
T

;; win32 functions barf on cygwin pathnames
#+win32 (os:file-info-p (show (os:file-info *tmp2*) :pretty t)) T
#+win32 (listp (show (os:file-info (make-pathname :name "syscalls-tests-*"
                                                  :defaults *tmp2*)
                                   t)
                     :pretty t))
T

#+(or win32 cygwin)
(os:system-info-p (show (os:system-info) :pretty t))
#+(or win32 cygwin) T
#+(or win32 cygwin)
(os:version-p (show (os:version) :pretty t))
T
#+(or win32 cygwin)
(os:memory-status-p (show (os:memory-status)))
T

(let ((sysconf #+unix (os:sysconf) #-unix nil))
  ;; guard against broken unixes, like FreeBSD 4.10-BETA
  (if #+unix (and (getf sysconf :PAGESIZE)
                  (getf sysconf :PHYS-PAGES)
                  (getf sysconf :AVPHYS-PAGES))
      #-unix T
      (listp (show (multiple-value-list (os:physical-memory))))
      T))
T

;; test file locking
(let ((buf (make-array 100 :fill-pointer t :adjustable t
                       :element-type 'character))
      (timeout
       (let* ((uname (os:uname)))
         (cond ((and (string= (os:uname-sysname uname) "Linux")
                     (string= (os:uname-machine uname) "ppc64"))
                (format t "~&~S: increase timeout for openpower-linux1~%"
                        'flush-clisp)
                100)
               (t 1)))))
  (defun flush-clisp (stream)
    (when #-:win32 (socket:socket-status (cons stream :input) timeout)
          ;; select on win32 does not work with pipes
          #+:win32 (progn (sleep 1) (listen stream))
      ;; read from the clisp stream until the next prompt
      (setf (fill-pointer buf) 0)
      (loop :with pos-NL = 0 :for ch = (read-char stream)
        :until (and (char= ch #\Space) (char= #\[ (char buf pos-NL))
                    (let ((pos1 (position #\] buf :start pos-NL)))
                      (and pos1 (char= #\> (char buf (1+ pos1))))))
        :do (when (char= ch #\Newline) (setq pos-NL (1+ (length buf))))
        (vector-push-extend ch buf))
      (show buf))))
FLUSH-CLISP

(defun proc-send (proc fmt &rest args)
  (apply #'format proc fmt args)
  (terpri proc) (force-output proc)
  (flush-clisp proc))
PROC-SEND

(multiple-value-bind (run args) (cmd-args)
  (push "abort" args) (push "-on-error" args)
  (show (cons run args) :pretty t)
  (defparameter *proc1* (ext:run-program run :arguments args
                                         :input :stream :output :stream))
  (defparameter *proc2* (ext:run-program run :arguments args
                                         :input :stream :output :stream))
  (flush-clisp *proc1*)
  (flush-clisp *proc2*)
  t)
T

(stringp
 (proc-send *proc1* "(setq s (open ~S :direction :output :if-exists :append))"
            (truename *tmp1*)))
T
(stringp
 (proc-send *proc2* "(setq s (open ~S :direction :output :if-exists :append))"
            (truename *tmp1*)))
T

#-:no-stream-lock (read-from-string (proc-send *proc1* "(stream-lock s t)"))
#-:no-stream-lock T
#-:no-stream-lock (proc-send *proc2* "(stream-lock s t)")
#-:no-stream-lock NIL           ; blocked

#-:no-stream-lock (read-from-string (proc-send *proc1* "(stream-lock s nil)"))
#-:no-stream-lock NIL           ; released
#-:no-stream-lock (read-from-string (flush-clisp *proc2*))
#-:no-stream-lock T             ; acquired

#-:no-stream-lock (read-from-string (proc-send *proc1* "(stream-lock s t :block nil)"))
#-:no-stream-lock NIL
#-:no-stream-lock (read-from-string (proc-send *proc2* "(stream-lock s nil)"))
#-:no-stream-lock NIL           ; released
#-:no-stream-lock (read-from-string (proc-send *proc1* "(stream-lock s t :block nil)"))
#-:no-stream-lock T
#-:no-stream-lock (read-from-string (proc-send *proc1* "(stream-lock s nil)"))
#-:no-stream-lock NIL           ; released

;; reap *proc1* & *proc2* as soon as we do not need them to avoid
;; woe32 ERROR_SHARING_VIOLATION in accessing *TMP1* & *TMP2*
(progn (proc-send *proc1* "(close s)(ext:quit)")
       (close (two-way-stream-input-stream *proc1*))
       (close (two-way-stream-output-stream *proc1*))
       (close *proc1*) (symbol-cleanup '*proc1*)
       (proc-send *proc2* "(close s)(ext:quit)")
       (close (two-way-stream-input-stream *proc2*))
       (close (two-way-stream-output-stream *proc2*))
       (close *proc2*) (symbol-cleanup '*proc2*))
T

(multiple-value-list (os:sync)) ()

;; We are testing that the inode number is different for a file created with
;; :IF-EXISTS :RENAME-AND-DELETE.
;; For that, the file has to be open by another process so that the
;; inode is not immediately reused.
;; This test cannot work on woe32: a file which is open by another process
;; cannot be renamed or removed.
#-win32
(let ((inode (show (posix:file-stat-ino (posix:file-stat *tmp1*)))))
  (multiple-value-bind (run args) (cmd-args)
    (push "abort" args) (push "-on-error" args)
    (show (cons run args) :pretty t)
    (with-open-stream (s (ext:run-program run :arguments args
                                          :input :stream :output :stream))
      (flush-clisp s)
      (proc-send s (format nil "(setq s (open ~S))" (namestring *tmp1*)))
      (unwind-protect
           (with-open-file (new *tmp1* :direction :output
                                :if-exists :rename-and-delete)
             (= inode (show (posix:file-stat-ino (posix:file-stat new)))))
        (proc-send s "(close s)(ext:quit)")))))
#-win32 NIL

(let ((file "foo.bar") (dates '(3141592653 3279321753)))
  (unwind-protect
       (progn (with-open-file (s file :direction :output) (write s :stream s))
              (loop :for d :in dates :do (posix:set-file-stat file :mtime d)
                :collect (= d (with-open-file (s file) (file-write-date s)))))
    (delete-file file)))
(T T)

(let ((s (floor (os:file-size *tmp1*) 2)))
  (list (= s (setf (os:file-size *tmp1*) s))
        (= s (os:file-size *tmp1*))))
(T T)

(with-open-file (s *tmp2* :direction :io)
  (let ((l (floor (file-length s) 2)))
    (list (= l (setf (os:file-size s) l))
          (= l (file-length s)))))
(T T)

(let ((file "foo.bar") s)
  (unwind-protect
       (progn (setq s (open file :direction :probe :if-does-not-exist :create))
              (list (os:file-size file)
                    (setf (os:file-size s) 100)
                    (os:file-size file)
                    (setf (os:file-size file) 1000)
                    (os:file-size s)))
    (delete-file file)))
(0 100 100 1000 1000)

#+ffi (defparameter *foo* (os:fopen "foo" "w")) #+ffi *foo*
#+ffi (os::%fputc 65 *foo*) #+ffi 65
#+ffi (os:feof *foo*) #+ffi NIL
#+ffi (os:ferror *foo*) #+ffi NIL
#+ffi (os:clearerr *foo*) #+ffi NIL
#+ffi (os:fflush *foo*) #+ffi NIL
#+ffi (os:fclose *foo*) #+ffi NIL
#+ffi (defparameter *foo* (os:fopen "foo" "r")) #+ffi *foo*
#+ffi (os::%fgetc *foo*) #+ffi 65
#+ffi (os:feof *foo*) #+ffi NIL
#+ffi (os::%fgetc *foo*) #+ffi -1
#+ffi (os:feof *foo*) #+ffi T
#+ffi (os:ferror *foo*) #+ffi NIL
#+ffi (os:clearerr *foo*) #+ffi NIL
#+ffi (os:fclose *foo*) #+ffi NIL
#+ffi (finish-file "foo") #+ffi 1

;; unknown errnos are reported differently on different platforms.
;; linux: "unknown error 47"
;; cygwin: "error 47"
;; win32: some localized abomination
#+ffi (loop :with all = (os:errno t)
        :for e :from 0 :to (loop :for p :in all :maximize (car p))
        :do (show (list e (os:errno e) (os:strerror)))
        :finally (os:errno nil))
#+ffi ()

(and (fboundp 'os:hostid) (not (integerp (show (os:hostid))))) NIL
#+unix (and (fboundp 'os::%sethostid)
            (zerop (os:euid))
            (not (= (setf (os:hostid) (os:hostid)) (os:hostid))))
#+unix NIL
(and (fboundp 'os:domainname) (not (stringp (show (os:domainname))))) NIL
#+unix (and (fboundp 'os::%setdomainname)
            (zerop (os:euid))
            (not (string= (setf (os:domainname) (os:domainname))
                          (os:domainname))))
#+unix NIL

(defun ipaddr-closure (address)
  (let ((ht (make-hash-table :test 'equalp)))
    (labels ((handle (s)
               (unless (gethash s ht)
                 (handler-bind ((error (lambda (c)
                                         (setf (gethash s ht) c)
                                         (return-from handle nil))))
                   (let ((he (os:resolve-host-ipaddr s)))
                     (setf (gethash s ht) he)
                     (handle (os:hostent-name he))
                     (mapc #'handle (os:hostent-aliases he))
                     (mapc #'handle (os:hostent-addr-list he)))))))
      (handle address))
    ht))
IPADDR-CLOSURE
(hash-table-p (show (ipaddr-closure "localhost") :pretty t)) T
(hash-table-p (show (ipaddr-closure :default) :pretty t)) T

;; wait
(defun run-sleep (sec)
  (ext::launch "sleep" :arguments (list (princ-to-string sec))
               :wait nil :output nil))
RUN-SLEEP

#+unix
(multiple-value-bind (pid kind status) (posix:wait :pid (run-sleep 1))
  (list (integerp (show pid)) kind status))
#+unix (T :EXITED 0)

#+unix
(progn
  (run-sleep 1)
  (multiple-value-bind (pid kind status) (posix:wait)
    (list (integerp (show pid)) kind status)))
#+unix (T :EXITED 0)

#+unix (posix:wait :pid (run-sleep 1) :nohang t) #+unix 0

#+(and :unix (not :cygwin))
(let ((pid (run-sleep 1)))
  (posix:kill pid :SIGTERM)
  (multiple-value-bind (pid1 kind status rusage) (posix:wait :pid pid :usage t)
    (assert (= pid pid1) () "pid: ~S<>~S" pid pid1)
    (list kind status (posix:usage-p (show rusage)))))
#+(and :unix (not :cygwin)) (:SIGNALED :SIGTERM T)

#+(and :unix (not :cygwin))
(let ((pid (run-sleep 1)))
  (posix:kill pid :SIGSTOP)
  (multiple-value-bind (pid1 kind status) (posix:wait :pid pid :untraced t)
    (assert (= pid pid1) () "pid: ~S<>~S" pid pid1)
    (assert (eq kind :STOPPED) () "kind=~S <> :STOPPED" kind)
    (assert (eq status :SIGSTOP) () "status=~S <> :SIGCONT" status))
  (posix:kill pid :SIGCONT)
  (multiple-value-bind (pid1 kind status) (posix:wait :pid pid :continued t)
    (assert (= pid pid1) () "pid: ~S<>~S" pid pid1)
    (assert (eq kind :CONTINUED) () "kind=~S <> :CONTINUED" kind)
    (assert (null status) () "status=~S is non-NIL" status)))
#+(and :unix (not :cygwin)) NIL

#+(and :unix (not :cygwin)) (every #'sys::double-float-p (show (multiple-value-list (os:loadavg)))) T
#+(and :unix (not :cygwin)) (every #'sys::fixnump (show (multiple-value-list (os:loadavg t)))) T

(os:version<= "a" "b") T
(os:version< "1.10" "1.8") NIL
(os:version> "foo100" "foo99") T
(os:version>= "d" "d") T
(os:version-compare "foo" "bar") >
(os:version-compare "z" "z") =
(os:version-compare "foo2" "foo10") <

(progn (delete-file *tmp1*) (symbol-cleanup '*tmp1*)
       (delete-file *tmp2*) (symbol-cleanup '*tmp2*)
       (symbol-cleanup 'flush-clisp)
       (symbol-cleanup 'proc-send)
       (setq *features* (delete :no-stream-lock *features*))
       T)
T
