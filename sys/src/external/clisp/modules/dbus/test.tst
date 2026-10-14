;; -*- Lisp -*- vim:filetype=lisp
;; tests for D-Bus
;; clisp -E 1:1 -q -norc -i ../tests/tests -x '(run-test "dbus/test")'

(list (require "dbus")) (#-DBUS T #+DBUS NIL)
(listp (show (multiple-value-list (ext:module-info "dbus" t)) :pretty t)) T

dbus:DBUS_MAJOR_PROTOCOL_VERSION 1

(stringp (show dbus:DBUS_SERVICE_DBUS)) T
(stringp (show dbus:DBUS_PATH_DBUS)) T
(stringp (show dbus:DBUS_PATH_LOCAL)) T

;; http://dbus.freedesktop.org/doc/dbus/libdbus-tutorial.html

;; == Common Code
(defparameter *dbus-error* (ffi:allocate-shallow 'dbus:DBusError)) *DBUS-ERROR*
(multiple-value-list (dbus:dbus_error_init *dbus-error*)) ()
(ffi:foreign-value *dbus-error*)
#S(DBUS:DBusError :NAME NIL :MESSAGE NIL :DUMMY1 1 :DUMMY2 0 :DUMMY3 0
                  :DUMMY4 0 :DUMMY5 0 :PADDING NIL)
(defparameter *dbus-conn*
  (dbus:dbus_bus_get dbus:DBUS_BUS_SESSION *dbus-error*))
*DBUS-CONN*
(null *dbus-conn*) NIL
(dbus:dbus_error_is_set *dbus-error*) 0 ; connection success

;; prepare for argument parsing
(defparameter *dbus-iter* (show (ffi:allocate-shallow 'dbus:DBusMessageIter)))
*DBUS-ITER*
(defparameter *dbus-args*
  (show (ffi:c-var-address (ffi:foreign-value *dbus-iter*))))
*DBUS-ARGS*

;; == Sending a Signal
(defparameter *dbus-msg*        ; create a signal
  (dbus:dbus_message_new_signal
   "/test/signal/Object"        ; object name of the signal
   "test.signal.Type"           ; interface name of the signal
   "Test"))                     ; name
*DBUS-MSG*
(null *dbus-msg*) NIL

;; append arguments
(multiple-value-list
 (dbus:dbus_message_iter_init_append *dbus-msg* *dbus-args*)) ()
(ffi:with-foreign-object (param 'dbus:dbus_uint32_t 123)
  (dbus:dbus_message_iter_append_basic
   *dbus-args* dbus:DBUS_TYPE_UINT32 param)) 1

;; send the message and flush the connection
(multiple-value-list (dbus:dbus_connection_send *dbus-conn* *dbus-msg*)) (1 2)
(multiple-value-list (dbus:dbus_connection_flush *dbus-conn*)) ()
;; free the message
(multiple-value-list (dbus:dbus_message_unref *dbus-msg*)) ()

;; == Calling a Method
(defparameter *dbus-msg*
  (dbus:dbus_message_new_method_call
   "test.method.server"         ; target for the method call
   "/test/method/Object"        ; object to call on
   "test.method.Type"           ; interface to call on
   "Method"))                   ; method name
*DBUS-MSG*
(null *dbus-msg*) NIL

;; append arguments
(multiple-value-list
 (dbus:dbus_message_iter_init_append *dbus-msg* *dbus-args*)) ()
(ffi:with-foreign-object (param 'ffi:c-string "abazonk")
  (dbus:dbus_message_iter_append_basic
   *dbus-args* dbus:DBUS_TYPE_STRING param)) 1

(defparameter *dbus-pending*
  (multiple-value-bind (status pending)
      ;; send message and get a handle for a reply
      (dbus:dbus_connection_send_with_reply *dbus-conn* *dbus-msg* -1)
                                ; -1 is default timeout
    (assert (= status 1))
    pending))
*DBUS-PENDING*
(null *dbus-pending*) NIL

(multiple-value-list (dbus:dbus_connection_flush *dbus-conn*)) ()
;; free the message
(multiple-value-list (dbus:dbus_message_unref *dbus-msg*)) ()

;; block until we receive a reply
(multiple-value-list (dbus:dbus_pending_call_block *dbus-pending*)) ()

;; get the reply message
(null (setq *dbus-msg* (dbus:dbus_pending_call_steal_reply *dbus-pending*))) NIL

;; free the pending message handle
(multiple-value-list (dbus:dbus_pending_call_unref *dbus-pending*)) ()

;; read the parameters
(dbus:dbus_message_iter_init *dbus-msg* *dbus-args*) 1
(= dbus:DBUS_TYPE_STRING (dbus:dbus_message_iter_get_arg_type *dbus-args*)) T

(ffi:with-foreign-object (param 'ffi:c-string)
  (dbus:dbus_message_iter_get_basic *dbus-args* param)
  ;; "The name test.method.server was not provided by any .service files"
  (stringp (show (ffi:foreign-value param)))) T

(dbus:dbus_message_iter_next *dbus-args*) 0 ; one argument only

;; free reply and close connection
(multiple-value-list (dbus:dbus_message_unref *dbus-msg*)) ()

;; == Receiving a Signal

;; add a rule for which messages we want to see
(multiple-value-list
 (dbus:dbus_bus_add_match *dbus-conn* ; see signals from the given interface
                          "type='signal',interface='test.signal.Type'"
                          *dbus-error*)) ()
(dbus:dbus_error_is_set *dbus-error*) 0 ; success
(multiple-value-list (dbus:dbus_connection_flush *dbus-conn*)) ()

(defun show-message (msg)
  (if msg
      (format t "~& => ~S (sender ~S) (type ~S) (path ~S) (interface ~S) (member ~S) (error_name ~S) (destination ~S) (signature ~S)~%"
              msg (dbus:dbus_message_get_sender msg)
              (dbus:dbus_message_get_type msg)
              (dbus:dbus_message_get_path msg)
              (dbus:dbus_message_get_interface msg)
              (dbus:dbus_message_get_member msg)
              (dbus:dbus_message_get_error_name msg)
              (dbus:dbus_message_get_destination msg)
              (dbus:dbus_message_get_signature msg))
      (format t "~& => no message~%"))
  msg)
SHOW-MESSAGE

(defun pop-message (conn)
  ;; non blocking read of the next available message
  (format t "~&read/write: ~S~%" (dbus:dbus_connection_read_write conn 0))
  (show-message (dbus:dbus_connection_pop_message conn)))
POP-MESSAGE

;; loop listening for signals being emmitted
(loop :repeat 5 :do
  (setq *dbus-msg* (pop-message *dbus-conn*))
  (cond (*dbus-msg*
         ;; check if the message is a signal from the correct interface
         ;; and with the correct name
         (when (= 1 (dbus:dbus_message_is_signal
                     *dbus-msg* "test.signal.Type" "Test"))
           ;; read the parameters
           (cond ((= 0 (dbus:dbus_message_iter_init *dbus-msg* *dbus-args*))
                  (format t "~& = Message has no arguments!~%"))
                 ((/= dbus:DBUS_TYPE_STRING
                      (dbus:dbus_message_iter_get_arg_type *dbus-args*))
                  (format t "~& = Argument is not string!~%"))
                 (t
                  (ffi:with-foreign-object (param 'ffi:c-string)
                    (dbus:dbus_message_iter_get_basic *dbus-args* param)
                    (format t "~& = Got Signal with value ~S~%"
                            (ffi:foreign-value param)))))
           ;; free the message
           (multiple-value-list (dbus:dbus_message_unref *dbus-msg*))))
        (t ; loop again if we haven't read a message
         (sleep 0.1))))
NIL

;; == Exposing a Method to be called

(defun reply-to-method-call (msg conn)
  (ffi:with-foreign-object (args 'dbus:DBusMessageIter)
    ;; read the arguments
    (cond ((= 0 (dbus:dbus_message_iter_init msg args))
           (format t "~& = Message has no arguments!~%"))
          ((/= dbus:DBUS_TYPE_STRING
               (dbus:dbus_message_iter_get_arg_type args))
           (format t "~& = Argument is not string!~%"))
          (t
           (ffi:with-foreign-object (param 'ffi:c-string)
             (dbus:dbus_message_iter_get_basic args param)
             (format t "~& = Method called with ~S~%"
                     (ffi:foreign-value param)))))
    ;; create a reply from the message
    (let ((reply (dbus:dbus_message_new_method_return msg)))
      ;; add the arguments to the reply
      (dbus:dbus_message_iter_init_append reply args)
      (ffi:with-foreign-object (stat 'ffi:boolean t)
        (when (zerop (dbus:dbus_message_iter_append_basic
                      args dbus:DBUS_TYPE_BOOLEAN stat))
          (error "Out Of Memory! (stat)")))
      (ffi:with-foreign-object (level 'dbus:dbus_uint32_t 21614)
        (when (zerop (dbus:dbus_message_iter_append_basic
                      args dbus:DBUS_TYPE_UINT32 level))
          (error "Out Of Memory! (level)")))
      ;; send the reply && flush the connection
      (multiple-value-bind (status serial)
          (dbus:dbus_connection_send conn reply)
        (when (zerop status) (error "Out Of Memory! (serial)"))
        (format t "~& client_serial=~S~%" serial))
      (dbus:dbus_connection_flush conn)
      ;; free the reply
      (dbus:dbus_message_unref reply))))
REPLY-TO-METHOD-CALL

;; loop, testing for new messages
(loop :repeat 5 :do
  (setq *dbus-msg* (pop-message *dbus-conn*))
  (cond (*dbus-msg*
         (when (= 1 (dbus_message_is_method_call
                     *dbus-msg* "test.method.Type" "Method"))
           (reply-to-method-call *dbus-msg* *dbus-conn))
         ;; free the message
         (multiple-value-list (dbus:dbus_message_unref *dbus-msg*)))
        (t (sleep 0.1))))
NIL

;; == Requesting a Well-known Name
(= (show dbus:DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER)
   (dbus:dbus_bus_request_name *dbus-conn* "test.method.server"
                               dbus:DBUS_NAME_FLAG_REPLACE_EXISTING
                               *dbus-error*))
T
(dbus:dbus_error_is_set *dbus-error*) 0 ; success

(progn (ffi:foreign-free *dbus-error*)
       (symbol-cleanup '*dbus-error*)
       (symbol-cleanup '*dbus-conn*)
       (symbol-cleanup '*dbus-msg*)
       (ffi:foreign-free *dbus-iter*)
       (symbol-cleanup '*dbus-iter*)
       (symbol-cleanup '*dbus-args*)
       (symbol-cleanup '*dbus-pending*)
       )
T
