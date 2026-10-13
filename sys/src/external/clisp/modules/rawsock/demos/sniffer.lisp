;;; Packet sniffer
;; run as root like this:
;; $ sudo clisp sniffer.lisp [options]
;; for help:
;; $ clisp sniffer.lisp -- -help

(require "rawsock")

;; --- more or less generic command line argument parsing
(defparameter *arg-table*
  (make-hash-table :test 'equal :initial-contents
                   '(("-domain" :INET "domain argument for socket(2)")
                     ("-type" :PACKET "type argument for socket(2)")
                     ("-protocol" #x300 "protocol argument for socket(2)")
                     ("-repeat" 10 "how many times to call rcvfrom(2)")
                     ("-bufsiz" 1518 "the buffer size for rcvfrom(2)")))
  "Default argument values.")

(defun parse-args (&optional (args *args*))
  "Parse the list of command line arguments into a hash table.
Use *ARG-TABLE* for help."
  (loop :with ht = (make-hash-table :test 'equal)
    :for (key val) :on args :by #'cddr :do
    (when (string= "-help" key)
      (format t "Packet sniffer~%Arguments:~%")
      (maphash (lambda (key val)
                 (format t "  ~A  ~A (default: ~S)~%"
                         key (second val) (first val)))
               *arg-table*)
      (ext:quit 1))
    (unless val (error "Odd number of arguments: ~S" args))
    (unless (char= #\- (char key 0)) (error "Non-option argument: ~S" key))
    (let ((v (gethash key ht)))
      (when v (error "Option ~S given more than once: ~S and ~S" key v val)))
    (setf (gethash key ht) val)
    :finally (return ht)))

(defun get-opt (ht opt)
  "Get the specified option value based on the defauls in *ARG-TABLE*
and the parsed command line."
  (let ((arg (gethash opt ht))
        (dfl (gethash opt *arg-table*)))
    (if arg
        (handler-case (read-from-string arg)
          (error (c) (error "Invalid ~S argument: ~S: ~A" opt arg c)))
        (first dfl))))

;; --- the sniffer proper
(defun my-rcvfrom (socket buffer device)
  "Call RCVFROM on a buffer with a fill pointer."
  (setf (fill-pointer buffer) (array-total-size buffer))
  (let ((len (rawsock:recvfrom socket buffer device)))
    (setf (fill-pointer buffer) len)))

(defun print-buffer (buffer)
  "Print the byte buffer nicely."
  (format t " len=~:D" (length buffer))
  (loop :for byte :across buffer :do (format t " ~2,'0X"  byte))
  (terpri))

(defun print-sockaddr (device)
  "Print a SOCKADDR object nicely."
  (let ((family (rawsock:sockaddr-family device)))
    (format t "family: ~A " family)
    (case family
      (:UNIX
       (loop :for c :across (rawsock:sockaddr-data device)
         :do (format t "~c" (if (= c 0) #\space (code-char c )))))
      (t (prin1 (rawsock:sockaddr-data device))))))

(defun sniff (args)
  "Open a socket and print everything which come our way through it."
  (let ((socket (rawsock:socket
                 (get-opt args "-domain")
                 (get-opt args "-type")
                 (get-opt args "-protocol"))))
    (unwind-protect
         (loop
           :with buffer = (make-array (get-opt args "-bufsiz")
                                      :fill-pointer 0
                                      :element-type '(unsigned-byte 8))
           :and device = (rawsock:make-sockaddr :UNSPEC)
           :repeat (get-opt args "-repeat") :do
           (my-rcvfrom socket buffer device)
           (print-sockaddr device)
           (print-buffer buffer))
      (rawsock:sock-close socket))))

(sniff (parse-args))
