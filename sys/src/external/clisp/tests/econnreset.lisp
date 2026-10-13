#|
If a socket receives an RST packet, select will not discover it,
it will report that the socket is both readable and writable,
while, in fact, the next i/o will fail with ECONNRESET.
However, SOCKET-STATUS does discover this because it calls listen_char()
on readable sockets which calls read() and fails with ECONNRESET.
Therefore SOCKET-STATUS may signal an OS STREAM-ERROR.

This cannot be tested automatically because it requires running clisp on
a separate ("client") host as root:
server XXX.XXX.XXX.XXX:
 (setf se (socket:socket-server 1234 :interface "XXX.XXX.XXX.XXX"))
 (setf st (socket:socket-accept se))
 (socket:socket-status st)
 (write-line "foo" st)
client:
 sudo clisp -q -norc -K full -i reset.lisp -x '(waitforpkt "XXX.XXX.XXX.XXX" 1234)'

See <http://thread.gmane.org/gmane.lisp.clisp.general/12657>, specifically:
  http://article.gmane.org/gmane.lisp.clisp.general:12675
  http://article.gmane.org/gmane.lisp.clisp.general:12691
  http://article.gmane.org/gmane.lisp.clisp.general:12704
  http://article.gmane.org/gmane.lisp.clisp.general:12694
  http://article.gmane.org/gmane.lisp.clisp.general:12703

|#

(defvar default-socket (rawsock:socket :inet :packet #+ignore :all #x300))
(unless (> default-socket 0) (error "socket failed - running as root?"))
(defvar default-buffer
  (make-array 1518 :element-type '(unsigned-byte 8) :fill-pointer 100))
(defvar default-device
  (rawsock:make-sockaddr :packet
                         (make-array 14 :element-type '(unsigned-byte 8))))
(defun reset ()
  ;; change flags to from ack to rst+ack
  (setf (aref default-buffer 47) 20)
  (setf (aref default-buffer 46) 80)      ; tcp header length = 5 words
  ;; set buffer length
  (setf (fill-pointer default-buffer) 54) ; 60 ??
  (setf (aref default-buffer 17) 40)
  (rawsock:tcpcsum default-buffer)  ; not returning right answer?
  (setf ipc (rawsock:ipcsum default-buffer)) ; returns bytes reversed?
  (rawsock:sendto default-socket default-buffer default-device))
(defun waitforpkt (serverip serverport &key (show 100))
  (loop :with sock = nil :and serverip-list
    = (read-from-string (nsubstitute #\Space #\.
                                     (ext:string-concat "(" serverip ")")))
    :for i :from 0 :with len :do
    (setf (fill-pointer default-buffer) 1518)
    (setf len (rawsock:recvfrom default-socket default-buffer default-device))
    (when (= 0 (mod i show))
      (princ "*") (force-output)
      (unless sock
        (setq sock (socket:socket-connect serverport serverip))
        (princ "#") (force-output)))
    (when (and (>= len 52)
               (= (aref default-buffer 12) 8) ; ip
               (= (aref default-buffer 13) 0)
               (= (aref default-buffer 14) 69) ; ipv4, len 5
               (= (aref default-buffer 23) 6)  ; tcp
               (loop for j from 0 as a in serverip-list always
                 (= a (aref default-buffer (+ j 30)))) ; correct ip addr
               (= serverport
                  (+ (aref default-buffer 37)
                     (* 256 (aref default-buffer 36))))
               (= 16 (aref default-buffer 47)))
      (return (reset)))))
