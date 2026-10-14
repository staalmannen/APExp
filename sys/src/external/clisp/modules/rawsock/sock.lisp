;; Module for Raw Sockets / CLISP
;; Fred Cohen, 2003-2004
;; Don Cohen, 2003-2004
;; Sam Steingold 2004-2008
;; <http://www.opengroup.org/onlinepubs/007908799/xns/syssocket.h.html>

(defpackage #:rawsock
  (:documentation "Raw Socket access")
  (:use #:lisp)
  (:shadowing-import-from "EXPORTING" #:defun #:defstruct #:define-condition)
  (:export #:buffer #:resize-buffer #:accept #:bind #:connect
           #:getpeername #:getsockname #:protocol #:network #:message
           #:sock-listen #:recv #:recvfrom #:recvmsg
           #:send #:sendmsg #:sendto #:socket-option
           #:socket #:socketpair #:sockatmark #:getnameinfo #:getaddrinfo
           #:sock-read #:sock-write #:sock-close
           #:sockaddr #:make-sockaddr #:sockaddr-family #:sockaddr-p
           #:htonl #:htons #:ntohl #:ntohs #:convert-address #:if-name-index
           #:configdev #:ipcsum #:icmpcsum #:tcpcsum #:udpcsum #:ifaddrs
           #:failure #:failure-code #:failure-message #:eai
           #:rawsock-error #:rawsock-error-socket
           #:open-unix-socket #:open-unix-socket-stream))

(in-package "RAWSOCK")
(pushnew :rawsock *features*)
(provide "rawsock")
(pushnew "RAWSOCK" custom:*system-package-list* :test #'string=)

(setf (documentation (find-package '#:rawsock) 'sys::impnotes) "rawsock")

(cl:defstruct (sockaddr (:constructor make-sa (%data)))
  (%data #() :read-only t :type (vector (unsigned-byte 8))))

(defstruct (message)
  (addr nil :type sockaddr) ; Optional address.
  (iovec #() :type (vector (vector (unsigned-byte 8)))) ; Scatter/gather array.
  (control #A((unsigned-byte 8) 0 nil) :type (vector (unsigned-byte 8)))
  (flags () :type list))        ; Flags on received message.

(defstruct (ifaddrs (:constructor make-ifaddrs (name flags address netmask
                                                destination data)))
  (name "" :type string)
  (flags nil :type list)
  (address nil :type (or null sockaddr))
  (netmask nil :type (or null sockaddr))
  (destination nil :type (or null sockaddr))
  (data nil :type (or null foreign-pointer)))

(defstruct (addrinfo (:constructor make-addrinfo
                                   (flags family type protocol address name)))
  (flags nil :type list)
  (family 0 :type integer)
  (type 0 :type integer)
  (protocol 0 :type integer)
  (address nil :type (or null sockaddr))
  (name nil :type (or null string)))

(defstruct (protocol (:constructor make-protocol (name aliases proto)))
  (name "" :type string)
  (aliases nil :type list)
  (proto 0 :type integer))

(defstruct (network (:constructor make-network (name aliases type net)))
  (name "" :type string)
  (aliases nil :type list)
  (type 0 :type integer)
  (net 0 :type integer))

(defsetf socket-option (&rest args) (value) `(set-socket-option ,value ,@args))

(defun sockaddr-data (sa)
  (let ((%data (sockaddr-%data sa)) (offset #,(sockaddr-slot :data)))
    (make-array (- (length %data) offset) :displaced-to %data
                :displaced-index-offset offset
                :element-type '(unsigned-byte 8))))

(defun open-unix-socket (pathname &optional (type :STREAM))
  "Return the socket (fixnum) pointing to this UNIX socket special device."
  (let* ((socket (socket :UNIX type 0))
         (address (make-sockaddr :UNIX
                                 (ext:convert-string-to-bytes
                                  (namestring (ext:absolute-pathname pathname))
                                  #+UNICODE custom:*pathname-encoding*
                                  #-UNICODE :default))))
    (connect socket address)
    (values socket address)))

(defun open-unix-socket-stream (pathname &rest opts &key (type :STREAM)
                                &allow-other-keys)
  "Return the lisp STREAM pointing to this UNIX socket special device.
The return value is already FINALIZEd by CLOSE.
Passes :TYPE to SOCKET and all the other options to MAKE-STREAM."
  (multiple-value-bind (sock address) (open-unix-socket pathname type)
    (setq opts (ext:remove-plist opts :type))
    (let ((stream (apply #'ext:make-stream sock opts)))
      (ext:finalize stream #'close)
      (sock-close sock)
      (values stream address))))

(ext:without-package-lock ("CL")
(defmethod close ((sock integer) &key abort)
  (declare (ignore abort))
  (sock-close sock))
)

(defmethod describe-object ((addr sockaddr) (out stream))
  (call-next-method)
  (when (fboundp 'rawsock:getnameinfo)
    (multiple-value-bind (node service) (rawsock:getnameinfo addr)
      (format out "sockaddr node: ~S, service: ~S~%" node service))))

(defun report-failure  (c out)
  (format out "[~S]: ~A" (failure-code c) (failure-message c)))

(define-condition failure (error)
  (($ecode :reader failure-code :initarg :code)
   ($message :reader failure-message :initarg :message))
  (:documentation "OS error")
  (:report report-failure))

(define-condition eai (failure) ()
  (:documentation "getaddrinfo()/getnameinfo() error, see <netdb.h>"))

(define-condition rawsock-error (failure)
  (($socket :reader rawsock-error-socket :initarg :socket))
  (:documentation "OS error on a raw socket")
  (:report (lambda (c out)
             (format out "OS Error on socket ~S: "
                     (rawsock-error-socket c))
             (report-failure c out))))
