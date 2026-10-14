;; -*- Lisp -*- vim:filetype=lisp
;; some tests for RAWSOCK
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "rawsock/test")'
;; relies on some functions in the syscalls module

(list (require "rawsock")) (#-RAWSOCK T #+RAWSOCK NIL)
(listp (show (multiple-value-list (ext:module-info "rawsock" t)) :pretty t)) T

(progn
  (defun to-bytes (string)
    (ext:convert-string-to-bytes
     string #+UNICODE charset:ascii #-UNICODE :default))
  (defun from-bytes (vec &key (start 0) end)
    (ext:convert-string-from-bytes
     vec #+UNICODE charset:ascii #-UNICODE :default :start start :end end))
  (defun make-byte-vector (len)
    (make-array (etypecase len
                  (integer len)
                  (sequence (length len)))
                :element-type '(unsigned-byte 8) :initial-element 0))
  (defun show-he (he &aux (type (os:hostent-addrtype he)))
    (show (cons he
                (mapcar (lambda (ip)
                          (let* ((numeric (rawsock:convert-address type ip))
                                 (dotted (rawsock:convert-address
                                          type numeric)))
                            (assert (string= ip dotted))
                            (list :address ip numeric
                                  (handler-case
                                      (os:resolve-host-ipaddr numeric)
                                    (error (e) e)))))
                        (posix:hostent-addr-list he)))
          :pretty t))
  (defun ip->ve (ip)
    (read-from-string
     (concatenate 'string "#(" (substitute #\Space #\. ip) ")")) )
  (defun host->ip (host)
    (let* ((he (os:resolve-host-ipaddr host)) all
           (host1 (os:hostent-name he)))
      (show-he he)
      (or (handler-case
              (loop :for ip :in (os:hostent-addr-list he)
                :for h1 = (os:resolve-host-ipaddr ip)
                :do (show-he h1) (push h1 all)
                :when (string-equal host1 (os:hostent-name h1))
                :return (show (cons (ip->ve ip) (os:hostent-addrtype h1))))
            (error (e) (princ-error e) nil))
          (if (eq host :default)
              (let* ((l (rawsock:ifaddrs :flags-and '(:up :running :broadcast)))
                     (i (find :INET (show l :pretty t)
                              :key (lambda (i)
                                     (rawsock:sockaddr-family
                                      (rawsock:ifaddrs-address i)))))
                     (sa (rawsock:ifaddrs-address
                          (or (show i :pretty t)
                              (error "~S: no running broadcast INET interface"
                                     'host->ip)))))
                (cons (subseq (rawsock:sockaddr-data (show sa :pretty t)) 2 6)
                      :INET))
              (error "~S(~S): no match in ~S and ~S" 'host->ip host he all)))))
  (defun host->sa (host &optional (port 0))
    (let ((ip+type (host->ip host)) sa
          (ve (make-byte-vector (nth-value 1 (rawsock::sockaddr-slot :data)))))
      (setf port (rawsock:htons port)
            (aref ve 0) (ldb #.(byte 8 0) port)
            (aref ve 1) (ldb #.(byte 8 8) port))
      (replace ve (car ip+type) :start1 2)
      (show ve)
      (setq sa (show (rawsock:make-sockaddr (cdr ip+type) ve)))
      (assert (equalp ve (rawsock:sockaddr-data sa)))
      (show (list 'rawsock:sockaddr-family
                  (multiple-value-list (rawsock:sockaddr-family sa))))
      sa))
  (defun local-sa-check (sock sa-local)
    (let* ((sa (rawsock:getsockname sock T))
           (data (rawsock:sockaddr-data sa)))
      (show sa)
      (show (list 'port (+ (aref data 1) (ash (aref data 0) 8))))
      (and (eq (rawsock:sockaddr-family sa) (rawsock:sockaddr-family sa-local))
           (equalp (subseq data 2)
                   (subseq (rawsock:sockaddr-data sa-local) 2)))))
  (dolist (what '(nil :data :family))
    (show (cons (list 'rawsock::sockaddr-slot what)
                (multiple-value-list (rawsock::sockaddr-slot what)))))
  (defvar *sa-remote*) (defvar *sa-local*)
  (defvar *buffer* (make-byte-vector 1024))
  (defvar *sock*) (defvar *sock1*) (defvar *sock2*)
  (defvar *recv-ret*) (defvar *recvfrom-ret*) #-:win32 (defvar *read-ret*)
  (defun my-recvfrom (so ve sa &optional (status :output) &aux size)
    (when (socket:socket-status (cons so :input) 1)
      (multiple-value-bind (len sa-len sa1) (rawsock:recvfrom so ve sa)
        (assert (eq sa sa1))
        (setq size len)
        (show (list len sa-len sa (subseq ve 0 len)) :pretty t)))
    (assert (eq status (show (socket:socket-status so))))
    (rawsock:sock-close so)
    size)
  (defun my-bind (sock sa)
    (handler-case (rawsock:bind sock sa)
      (:no-error () (show (list 'my-bind sock sa) :pretty t) nil)
      (error (e) (show (list 'my-bind sock sa e (princ-to-string e)) :pretty t))))
  T) T

(progn (setq *sa-remote* (host->sa "ftp.gnu.org" 21)) T) T
(progn (setq *sa-local* (host->sa :default)) T) T

(catch 'type-error-handler
  (handler-bind ((type-error #'type-error-handler))
    (rawsock:socket :INET t nil)))
NIL
(catch 'type-error-handler
  (handler-bind ((type-error #'type-error-handler))
    (rawsock:socket t :STREAM nil)))
NIL
(catch 'type-error-handler
  (handler-bind ((type-error #'type-error-handler))
    (rawsock:socket :INET :STREAM t)))
NIL

(integerp (show (setq *sock* (rawsock:socket :INET :STREAM nil)))) T

(unless (equalp #(127 0 0 1) (subseq (rawsock:sockaddr-data *sa-local*) 2 6))
  (rawsock:bind *sock* *sa-local*)
  (not (local-sa-check *sock* *sa-local*)))
NIL
(rawsock:connect *sock* *sa-remote*) NIL
;; fails when proxied
(equalp (rawsock:getpeername *sock* T) *sa-remote*) T

(listp (show (list (multiple-value-list (socket:socket-stream-local *sock*))
                   (multiple-value-list (socket:socket-stream-peer *sock*)))))
T

(ext:socket-status (list (cons *sock* :input))) (:INPUT)

(let ((size (rawsock:recv *sock* *buffer*)))
  (show (setq *recv-ret* (list size (from-bytes *buffer* :end size))))
  (ext:socket-status *sock*))
:OUTPUT

#+unix (listp (show (rawsock:socket-option *sock* NIL) :pretty t)) T
#+unix (listp (show (rawsock:socket-option *sock* NIL :level :ALL) :pretty t))T

#+unix (setf (rawsock:socket-option *sock* NIL) '(:debug nil))
#+unix (:DEBUG NIL)

#+unix (setf (rawsock:socket-option *sock* NIL :level :all)
             '(:sol-socket (:debug nil)))
#+unix (:SOL-SOCKET (:DEBUG NIL))

#+unix (setf (rawsock:socket-option *sock* :debug) nil)
#+unix NIL

#+unix (setf (rawsock:socket-option *sock* :debug :level :all)
             '(:sol-socket nil))
#+unix (:SOL-SOCKET NIL)

(ext:socket-status *sock*) :OUTPUT
(ext:socket-stream-shutdown *sock* :io) NIL

(block foo
  (handler-bind ((rawsock:rawsock-error
                  (lambda (e)
                    (princ-error e)
                    (return-from foo (= (rawsock:rawsock-error-socket e)
                                        *sock*)))))
    (rawsock:sock-write *sock* #A((UNSIGNED-BYTE 8) (2) (1 2)))))
T

(rawsock:sock-close *sock*) 0

;; re-create the socket after it has been closed
(let ((so (rawsock:socket :INET :STREAM nil)))
  (show (list so *sock*))
  (= so *sock*))
T

(unless (equalp #(127 0 0 1) (subseq (rawsock:sockaddr-data *sa-local*) 2 6))
  (rawsock:bind *sock* *sa-local*)
  (not (local-sa-check *sock* *sa-local*)))
NIL
(rawsock:connect *sock* *sa-remote*) NIL
;; fails when proxied
(equalp (rawsock:getpeername *sock* T) *sa-remote*) T

(ext:socket-status (list (cons *sock* :input))) (:INPUT)

#-:win32 ;; on win32, read() cannot be called on a socket!
(let ((size (rawsock:sock-read *sock* *buffer*)))
  (show (setq *read-ret* (list size (from-bytes *buffer* :end size))))
  (ext:socket-status *sock*))
#-:win32 :OUTPUT

#-:win32 (equal *recv-ret* *read-ret*) #-:win32 T

(rawsock:sock-close *sock*) 0

;; re-create the socket after it has been closed
(let ((so (rawsock:socket :INET :STREAM nil)))
  (show (list so *sock*))
  (= so *sock*))
T

(unless (equalp #(127 0 0 1) (subseq (rawsock:sockaddr-data *sa-local*) 2 6))
  (rawsock:bind *sock* *sa-local*)
  (not (local-sa-check *sock* *sa-local*)))
NIL
(rawsock:connect *sock* *sa-remote*) NIL

(let ((size (my-recvfrom *sock* *buffer* *sa-remote*)))
  (show (setq *recvfrom-ret* (list size (from-bytes *buffer* :end size))))
  (equal *recv-ret* *recvfrom-ret*))
T

(progn
  (setf (values *sock1* *sock2*)
        ;; :INET works on cygwin but not on Linux
        (rawsock:socketpair #+:win32 :INET #-:win32 :UNIX :STREAM nil))
  (show `((,(rawsock:getpeername *sock1* T) ,(rawsock:getsockname *sock1* T)
           ,*sock1*)
          (,(rawsock:getpeername *sock2* T) ,(rawsock:getsockname *sock2* T)
           ,*sock2*)
          ,(multiple-value-list (socket:socket-stream-local *sock1*))
          ,(multiple-value-list (socket:socket-stream-peer *sock1*))
          ,(multiple-value-list (socket:socket-stream-local *sock2*))
          ,(multiple-value-list (socket:socket-stream-peer *sock2*)))
        :pretty t)
  T) T

(let ((message "abazonk"))
  (rawsock:sock-write *sock1* (to-bytes message))
  (string= message (from-bytes *buffer*
                               :end (rawsock:sock-read *sock2* *buffer*))))
T

#-:win32 ;; on win32, read()/write() cannot be called on a socket!
(let* ((message '("I" "love" "you"))
       (char-num (reduce #'+ message :key #'length))
       (buf1 (map 'vector #'to-bytes message))
       (buf2 (map 'vector #'make-byte-vector message)))
  (show (list buf1 buf2))
  ;; assume ASCII-compatible encoding
  (assert (= char-num (rawsock:sock-write *sock1* buf1)))
  (assert (= char-num (rawsock:sock-read *sock2* buf2)))
  (list (equalp buf1 buf2)
        (equalp message (map 'list #'from-bytes buf2))))
#-:win32 (T T)

(list (ext:socket-status *sock1*) (ext:socket-status *sock2*))
(:OUTPUT :OUTPUT)

(list (rawsock:sock-close *sock1*) (rawsock:sock-close *sock2*)) (0 0)

;; lisp implementation of socketpair
(progn (setq *sock1* (rawsock:socket :INET :STREAM nil)
             *sock2* (rawsock:socket :INET :STREAM nil)
             *sa-local* (host->sa :default))
       (rawsock:bind *sock2* *sa-local*)
       (rawsock:sock-listen *sock2* 1)
       ;; figure out what port was assigned:
       (rawsock:getsockname *sock2* *sa-local*)
       NIL)
NIL

(socket:socket-status *sock2* 0) NIL

(rawsock:connect *sock1* *sa-local*) NIL

(socket:socket-status *sock2*) :INPUT

(progn (setq *sock* (rawsock:accept *sock2* *sa-local*))
       (socket:socket-status *sock1*))
:OUTPUT
(socket:socket-status *sock*) :OUTPUT

(rawsock:send *sock* (to-bytes "dog bites man")) 13
(rawsock:recv *sock1* *buffer* :start 17 :end 30) 13
(from-bytes *buffer* :start 17 :end 30) "dog bites man"

(rawsock:send *sock1* (to-bytes "man bites dog")) 13
(rawsock:recv *sock* *buffer* :start 1000 :end 1013) 13
(from-bytes *buffer* :start 1000 :end 1013) "man bites dog"

(rawsock:sock-close *sock*)  0
(rawsock:sock-close *sock1*) 0
(rawsock:sock-close *sock2*) 0

;; message
(when (and (fboundp 'rawsock:sendmsg) (fboundp 'rawsock:recvmsg))
  (let* ((message '("man" "bites" "dog"))
         (len (reduce #'+ message :key #'length))
         (message1
          (rawsock:make-message :addr *sa-local*
                                :iovec (map 'vector #'to-bytes message)))
         (message2
          (rawsock:make-message :addr (rawsock:make-sockaddr :inet)
                                :iovec (map 'vector #'make-byte-vector
                                            message))))
    (show (list :before message1 message2) :pretty t)
    ;; new connectionless-mode sockets
    (setq *sock1* (rawsock:socket :INET :DGRAM nil)
          *sock2* (rawsock:socket :INET :DGRAM nil))
    (rawsock:bind *sock2* *sa-local*)
    (assert (= len (rawsock:sendmsg *sock1* message1)))
    (assert (= len (rawsock:recvmsg *sock2* message2)))
    (show (list :after message1 message2) :pretty t)
    (assert (equalp (rawsock:message-iovec message1)
                    (rawsock:message-iovec message2)))
    (when (fboundp 'rawsock:getnameinfo)
      (show (list 'rawsock:getnameinfo
                  (multiple-value-list
                   (rawsock:getnameinfo (rawsock:message-addr message1)))
                  (multiple-value-list
                   (rawsock:getnameinfo (rawsock:message-addr message2))))))
    ;; I get "(EFAULT): Bad address" on Linux 2.6.14-1.1637_FC4
    ;; (when (fboundp 'rawsock:sockatmark)
    ;;   (show (list 'rawsock:sockatmark
    ;;               (rawsock:sockatmark *sock1*)
    ;;               (rawsock:sockatmark *sock2*))))
    (rawsock:sock-close *sock1*) (rawsock:sock-close *sock2*))
  nil)
NIL

#-win32 (rawsock:sock-write 1 (to-bytes "foo")) #-win32 3

;;;; root only??
(integerp (show (setq *sock* (rawsock:socket :INET :DGRAM 0)))) T

(progn
  (setq *sa-remote*
        (rawsock:make-sockaddr
         :inet '(101 116 104 48 0 0 0 0 0 0 0 0 0 0 0 0)))
  (show *sa-remote*)
  ;;(show (posix:resolve-host-ipaddr
  ;;       (make-array 4 :element-type '(unsigned-byte 8)
  ;;                   :displaced-to (rawsock:sockaddr-data *sa-remote*))))
  (fill *buffer* 0)
  (loop :for (x y) :in '((12 8)(14 #x45) (17 40)(22 #x40)(23 6)(26 10)(29 10))
    :do (setf (aref *buffer* x) y))
  (rawsock:ipcsum *buffer*))
51056

(rawsock:sendto *sock* *buffer* *sa-remote*)
1024

(rawsock:sock-close *sock*) 0

(or (not (fboundp 'rawsock:protocol))
    (rawsock:protocol-p (show (rawsock:protocol "IP") :pretty t))) T
(or (not (fboundp 'rawsock:protocol))
    (listp (show (rawsock:protocol) :pretty t))) T
(or (not (fboundp 'rawsock:network))
    (listp (show (rawsock:network) :pretty t))) T
(or (not (fboundp 'rawsock:if-name-index))
    (listp (show (rawsock:if-name-index) :pretty t))) T

(when (fboundp 'rawsock:if-name-index)
  (dolist (i-n (rawsock:if-name-index))
    (assert (= (rawsock:if-name-index (cdr i-n)) (car i-n)))
    (assert (string= (rawsock:if-name-index (car i-n)) (cdr i-n)))))
NIL

(or (not (fboundp 'rawsock:ifaddrs))
    (listp (show (rawsock:ifaddrs) :pretty t))) T
(or (not (fboundp 'rawsock:ifaddrs))
    (listp (show (rawsock:ifaddrs :flags-and '(:BROADCAST)) :pretty t))) T
(or (not (fboundp 'rawsock:ifaddrs))
    (flet ((drop-data (l)
             (dolist (i l l)
               (setf (rawsock:ifaddrs-data i) nil))))
      (equalp (drop-data (rawsock:ifaddrs :flags-and '(:BROADCAST)))
              (drop-data (rawsock:ifaddrs :flags-or '(:BROADCAST)))))) T
(or (not (fboundp 'rawsock:ifaddrs))
    (listp (show (rawsock:ifaddrs :flags-or '(:BROADCAST :MULTICAST)
                                  :flags-and '(:UP :RUNNING)) :pretty t))) T
(or (not (fboundp 'rawsock:ifaddrs))
    (null (rawsock:ifaddrs :flags-and '(:LOOPBACK :BROADCAST)))) T

(or (not (fboundp 'rawsock:getaddrinfo))
    (listp (show (rawsock:getaddrinfo :node "localhost") :pretty t))) T
(or (not (fboundp 'rawsock:getaddrinfo))
    (listp (show (rawsock:getaddrinfo :service "21") :pretty t))) T
(or (not (fboundp 'rawsock:getaddrinfo))
    (listp (show (rawsock:getaddrinfo :service "www") :pretty t))) T

(or (not (fboundp 'rawsock:getnameinfo))
    (listp (show (multiple-value-list (rawsock:getnameinfo *sa-remote*))))) T
(or (not (fboundp 'rawsock:getnameinfo))
    (listp (show (multiple-value-list (rawsock:getnameinfo *sa-local*))))) T

#+unix                          ; for Don Cohen
(when (and (string-equal (posix:uname-sysname (posix:uname)) "linux")
           (zerop (posix:uid))) ; root?
  (show (setq *sock* (rawsock:socket :INET :PACKET 3)))
  (show (setq *sa-local* (rawsock:make-sockaddr :PACKET)))
  (my-recvfrom *sock* *buffer* *sa-local*)
  nil)
#+unix NIL

#+unix           ; http://article.gmane.org/gmane.lisp.clisp.devel:14852
(when (and (string-equal (posix:uname-sysname (posix:uname)) "linux")
           (zerop (posix:uid))) ; root?
  (show (setq *sock* (rawsock:socket :INET :RAW :IPPROTO-ICMP)))
  (shell "ping -c 1 localhost") ; generate one icmp packet
  (show (setq *sa-local* (rawsock:make-sockaddr :PACKET 20)))
  (my-recvfrom *sock* *buffer* *sa-local* :IO)
  nil)
#+unix NIL

;; http://article.gmane.org/gmane.lisp.clisp.devel:14865
(progn
  (show (list '*sa-local* (setq *sa-local* (host->sa :default 7777))) :pretty t)
  (show (list '*sock* (setq *sock* (rawsock:socket :INET :DGRAM nil))))
  (rawsock:bind *sock* *sa-local*)
  (loop :for i :below 256 :do (setf (aref *buffer* i) i))
  (rawsock:sendto *sock* *buffer* *sa-local* :end 256))
256

(ext:socket-status (list (cons *sock* :input))) (:INPUT)

(let* ((buf (make-byte-vector 256))
       (sa1 (rawsock:make-sockaddr 0))
       (len (my-recvfrom *sock* buf sa1)))
  (assert (equalp sa1 *sa-local*))
  (loop :for i :below 256 :do (assert (= (aref buf i) i)))
  len)
256

;; os:hostid sometimes appears to be a mangled IP address
(and (fboundp 'os:hostid)
     (let ((id (os:hostid)))
       (listp (show (cons (if (< 32 (integer-length id))
                              (rawsock:convert-address :inet6 id)
                              (rawsock:convert-address :inet id))
                          (os:hostent-addr-list
                           (os:resolve-host-ipaddr :default)))))))
T
