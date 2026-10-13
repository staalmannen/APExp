;;; D-Bus interface <http://www.freedesktop.org/Software/dbus>
;;;
;;; Copyright (C) 2008-2009 by Sam Steingold
;;; This is Free Software, covered by the GNU GPL (v2+)
;;; See http://www.gnu.org/copyleft/gpl.html

;; synced with dbus-1.2.14
;; to update to a new release:
;;    git clone git://anongit.freedesktop.org/git/dbus/dbus ; cd dbus
;; or cd dbus; git pull
;; git diff dbus-1.2.14 dbus-<latest> dbus/*.h

(defpackage "DBUS"
  (:modern t)
  (:use "CL" "FFI")
  (:shadowing-import-from "EXPORTING"
    #:defconstant #:defvar #:defun #:defmacro #:define-symbol-macro
    #:def-c-const #:def-c-type #:def-c-enum #:def-c-struct #:def-c-var
    #:def-call-out))

(in-package "DBUS")

(setf (documentation (find-package "DBUS") 'sys::impnotes) "dbus")

;;; foreign function definitions
(default-foreign-language :stdc)
(eval-when (compile) (setq *foreign-guard* t))

(c-lines "#include \"config.h\"~%") ; local dbus config

;; w32api/basetyps.h defines interface to struct
;; which breaks dbus declarations like dbus_message_set_interface below
(c-lines "#undef interface~%")

(c-lines "#include <dbus/dbus.h>~%")

;; === dbus-types.h
(def-c-type dbus_int64_t)
(def-c-type dbus_int32_t)
(def-c-type dbus_uint32_t)
(def-c-type dbus_int16_t)
(def-c-type dbus_unichar_t)
(def-c-type dbus_bool_t)

;; === dbus-macros.h - nothing

;; === dbus-errors.h
(def-c-struct DBusError
  (name c-string)    ; public error name field
  (message c-string) ; public error message field
  (dummy1 uint)
  (dummy2 uint)
  (dummy3 uint)
  (dummy4 uint)
  (dummy5 uint)
  (padding c-pointer))

;; void dbus_error_init (DBusError *error);
(def-call-out dbus_error_init (:return-type nil)
  (:arguments (error (c-pointer DBusError))))

;; void dbus_error_free (DBusError *error);
(def-call-out dbus_error_free (:return-type nil)
  (:arguments (error (c-pointer DBusError))))

;; void dbus_set_error (DBusError *error, const char *name, const char *message, ...);
(def-call-out dbus_set_error (:return-type nil)
  (:arguments (error (c-pointer DBusError))
              (name c-string) (message c-string)))

;; void dbus_set_error_const (DBusError *error, const char *name, const char *message);
(def-call-out dbus_set_error_const (:return-type nil)
  (:arguments (error (c-pointer DBusError))
              (name c-string) (message c-string)))

;; void dbus_move_error (DBusError *src, DBusError *dest);
(def-call-out dbus_move_error (:return-type nil)
  (:arguments (src (c-pointer DBusError))
              (dst (c-pointer DBusError))))

;; dbus_bool_t dbus_error_has_name (const DBusError *error, const char *name);
(def-call-out dbus_error_has_name (:return-type dbus_bool_t)
  (:arguments (error (c-pointer DBusError)) (name c-string)))

;; dbus_bool_t dbus_error_is_set (const DBusError *error);
(def-call-out dbus_error_is_set (:return-type dbus_bool_t)
  (:arguments (error (c-pointer DBusError))))

;; === dbus-address.h
;; Opaque type representing one of the semicolon-separated items in an address
;;   typedef struct DBusAddressEntry DBusAddressEntry;
(def-c-type DBusAddressEntry* c-pointer)

;; dbus_bool_t dbus_parse_address (const char *address, DBusAddressEntry ***entry, int *array_len, DBusError *error);
(def-call-out dbus_parse_address (:return-type dbus_bool_t)
  (:arguments (address c-string)
              (entry (c-ptr (c-pointer DBusAddressEntry*)) :out)
              (array_len (c-ptr int) :out)
              (error (c-pointer DBusError))))

;; const char *dbus_address_entry_get_value (DBusAddressEntry *entry, const char *key);
(def-call-out dbus_address_entry_get_value (:return-type c-string)
  (:arguments (entry DBusAddressEntry*) (key c-string)))

;; const char *dbus_address_entry_get_method (DBusAddressEntry *entry);
(def-call-out dbus_address_entry_get_method (:return-type c-string)
  (:arguments (entry DBusAddressEntry*)))

;; void dbus_address_entries_free (DBusAddressEntry **entries);
(def-call-out dbus_address_entries_free (:return-type nil)
  (:arguments (entries (c-pointer DBusAddressEntry*))))

;; char* dbus_address_escape_value (const char *value);
(def-call-out dbus_address_escape_value (:return-type c-string)
  (:arguments (value c-string)))

;; char* dbus_address_unescape_value (const char *value, DBusError *error);
(def-call-out dbus_address_unescape_value (:return-type c-string)
  (:arguments (value c-string) (error (c-pointer DBusError))))

;; === dbus-memory.h

;; void* dbus_malloc (size_t bytes);
(def-call-out dbus_malloc (:return-type c-pointer) (:arguments (bytes size_t)))

;; void* dbus_malloc0 (size_t bytes);
(def-call-out dbus_malloc0 (:return-type c-pointer) (:arguments (bytes size_t)))

;; void* dbus_realloc (void *memory, size_t bytes);
(def-call-out dbus_realloc (:return-type c-pointer)
  (:arguments (memory c-pointer) (bytes size_t)))

;; void dbus_free (void *memory);
(def-call-out dbus_free (:return-type nil) (:arguments (memory c-pointer)))

;; void dbus_free_string_array (char **str_array);
(def-call-out dbus_free_string_array (:return-type nil)
  (:arguments (str_array (c-array-ptr c-string))))

;; typedef void (* DBusFreeFunction) (void *memory);
(def-c-type DBusFreeFunction
  (c-function (:return-type nil) (:arguments (memory c-pointer))))

;; void dbus_shutdown (void);
(def-call-out dbus_shutdown (:return-type nil) (:arguments))

;; === dbus-message.h
;; typedef struct DBusMessage DBusMessage;
;; Opaque type representing a message iterator.
;; Can be copied by value, and contains no allocated memory so never
;; needs to be freed and can be allocated on the stack.
;; typedef struct DBusMessageIter DBusMessageIter;
(def-c-type DBusMessage* c-pointer)
(def-c-type DBusMessageIter (c-struct DBusMessageIter
  (dummy1 c-pointer)            ; Don't use this
  (dummy2 c-pointer)            ; Don't use this
  (dummy3 dbus_uint32_t)        ; Don't use this
  (dummy4 int)                  ; Don't use this
  (dummy5 int)                  ; Don't use this
  (dummy6 int)                  ; Don't use this
  (dummy7 int)                  ; Don't use this
  (dummy8 int)                  ; Don't use this
  (dummy9 int)                  ; Don't use this
  (dummy10 int)                 ; Don't use this
  (dummy11 int)                 ; Don't use this
  (pad1 int)                    ; Don't use this
  (pad2 int)                    ; Don't use this
  (pad3 c-pointer)              ; Don't use this
  ))
(def-c-type DBusMessageIter* (c-pointer DBusMessageIter))

;; DBusMessage* dbus_message_new (int message_type);
(def-call-out dbus_message_new (:return-type DBusMessage*)
  (:arguments (message_type int)))

;; DBusMessage* dbus_message_new_method_call (const char *bus_name, const char *path, const char *interface, const char *method);
(def-call-out dbus_message_new_method_call (:return-type DBusMessage*)
  (:arguments (bus_name c-string) (path c-string)
              (interface c-string) (method c-string)))

;; DBusMessage* dbus_message_new_method_return (DBusMessage *method_call);
(def-call-out dbus_message_new_method_return (:return-type DBusMessage*)
  (:arguments (method_call DBusMessage*)))

;; DBusMessage* dbus_message_new_signal (const char *path, const char *interface, const char *name);
(def-call-out dbus_message_new_signal (:return-type DBusMessage*)
  (:arguments (path c-string) (interface c-string) (name c-string)))

;; DBusMessage* dbus_message_new_error (DBusMessage *reply_to, const char *error_name, const char *error_message);
(def-call-out dbus_message_new_error (:return-type DBusMessage*)
  (:arguments (reply_to DBusMessage*) (error_name c-string)
              (error_message c-string)))

;; DBusMessage* dbus_message_new_error_printf (DBusMessage *reply_to, const char *error_name, const char *error_format, ...);
(defmacro dbus_message_new_error_format (reply_to error_name error_format
                                         &rest args)
  `(dbus_message_new_error ,reply_to ,error_name
                           (format nil ,error_format ,@args)))


;; DBusMessage* dbus_message_copy (const DBusMessage *message);
(def-call-out dbus_message_copy (:return-type DBusMessage*)
  (:arguments (message DBusMessage*)))


;; DBusMessage* dbus_message_ref (DBusMessage *message);
(def-call-out dbus_message_ref (:return-type DBusMessage*)
  (:arguments (message DBusMessage*)))

;; void dbus_message_unref (DBusMessage *message);
(def-call-out dbus_message_unref (:return-type nil)
  (:arguments (message DBusMessage*)))

;; int dbus_message_get_type (DBusMessage *message);
(def-call-out dbus_message_get_type (:return-type int)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_set_path (DBusMessage *message, const char *object_path);
(def-call-out dbus_message_set_path (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (object_path c-string)))

;; const char* dbus_message_get_path (DBusMessage *message);
(def-call-out dbus_message_get_path (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_has_path (DBusMessage *message, const char *object_path);
(def-call-out dbus_message_has_path (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (object_path c-string)))

;; dbus_bool_t dbus_message_set_interface (DBusMessage *message, const char *interface);
(def-call-out dbus_message_set_interface (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (interface c-string)))

;; const char* dbus_message_get_interface (DBusMessage *message);
(def-call-out dbus_message_get_interface (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_has_interface (DBusMessage *message, const char *interface);
(def-call-out dbus_message_has_interface (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (interface c-string)))

;; dbus_bool_t dbus_message_set_member (DBusMessage *message, const char *member);
(def-call-out dbus_message_set_member (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (member c-string)))

;; const char* dbus_message_get_member (DBusMessage *message);
(def-call-out dbus_message_get_member (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_has_member (DBusMessage *message, const char *member);
(def-call-out dbus_message_has_member (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (member c-string)))

;; dbus_bool_t dbus_message_set_error_name (DBusMessage *message, const char *name);
(def-call-out dbus_message_set_error_name (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (name c-string)))

;; const char* dbus_message_get_error_name (DBusMessage *message);
(def-call-out dbus_message_get_error_name (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_set_destination (DBusMessage *message, const char *destination);
(def-call-out dbus_message_set_destination (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (destination c-string)))

;; const char* dbus_message_get_destination (DBusMessage *message);
(def-call-out dbus_message_get_destination (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_set_sender (DBusMessage *message, const char *sender);
(def-call-out dbus_message_set_sender (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (sender c-string)))

;; const char* dbus_message_get_sender (DBusMessage *message);
(def-call-out dbus_message_get_sender (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; const char* dbus_message_get_signature (DBusMessage *message);
(def-call-out dbus_message_get_signature (:return-type c-string)
  (:arguments (message DBusMessage*)))

;; void dbus_message_set_no_reply (DBusMessage *message, dbus_bool_t no_reply);
(def-call-out dbus_message_set_no_reply (:return-type nil)
  (:arguments (message DBusMessage*) (no_reply dbus_bool_t)))

;; dbus_bool_t dbus_message_get_no_reply (DBusMessage *message);
(def-call-out dbus_message_get_no_reply (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_message_is_method_call (DBusMessage *message, const char *interface, const char *method);
(def-call-out dbus_message_is_method_call (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (interface c-string) (method c-string)))

;; dbus_bool_t dbus_message_is_signal (DBusMessage *message, const char *interface, const char *signal_name);
(def-call-out dbus_message_is_signal (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (interface c-string)
              (signal_name c-string)))

;; dbus_bool_t dbus_message_is_error (DBusMessage *message, const char *error_name);
(def-call-out dbus_message_is_error (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (error_name c-string)))

;; dbus_bool_t dbus_message_has_destination (DBusMessage *message, const char *bus_name);
(def-call-out dbus_message_has_destination (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (bus_name c-string)))

;; dbus_bool_t dbus_message_has_sender (DBusMessage *message, const char *unique_bus_name);
(def-call-out dbus_message_has_sender (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (unique_bus_name c-string)))

;; dbus_bool_t dbus_message_has_signature (DBusMessage *message, const char *signature);
(def-call-out dbus_message_has_signature (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (signature c-string)))

;; dbus_uint32_t dbus_message_get_serial (DBusMessage *message);
(def-call-out dbus_message_get_serial (:return-type dbus_uint32_t)
  (:arguments (message DBusMessage*)))

;; void dbus_message_set_serial (DBusMessage *message, dbus_uint32_t serial);
(def-call-out dbus_message_set_serial (:return-type nil)
  (:arguments (message DBusMessage*) (serial dbus_uint32_t)))

;; dbus_bool_t dbus_message_set_reply_serial (DBusMessage *message, dbus_uint32_t reply_serial);
(def-call-out dbus_message_set_reply_serial (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (reply_serial dbus_uint32_t)))

;; dbus_uint32_t dbus_message_get_reply_serial (DBusMessage *message);
(def-call-out dbus_message_get_reply_serial (:return-type dbus_uint32_t)
  (:arguments (message DBusMessage*)))


;; void dbus_message_set_auto_start (DBusMessage *message, dbus_bool_t auto_start);
(def-call-out dbus_message_set_auto_start (:return-type nil)
  (:arguments (message DBusMessage*) (auto_start dbus_bool_t)))

;; dbus_bool_t dbus_message_get_auto_start (DBusMessage *message);
(def-call-out dbus_message_get_auto_start (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*)))


;; dbus_bool_t dbus_message_get_path_decomposed (DBusMessage *message, char ***path);
(def-call-out dbus_message_get_path_decomposed (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*)
              (path (c-ptr (c-array-ptr c-string)) :out)))


;; dbus_bool_t dbus_message_append_args (DBusMessage *message, int first_arg_type, ...);
;(def-call-out dbus_message_append_args (:return-type dbus_bool_t)
;  (:arguments (message DBusMessage*) (first_arg_type int) (... )))

;; dbus_bool_t dbus_message_append_args_valist (DBusMessage *message, int first_arg_type, va_list var_args);
;(def-call-out dbus_message_append_args_valist (:return-type dbus_bool_t)
;  (:arguments (message DBusMessage*) (first_arg_type int) (var_args va_list)))

;; dbus_bool_t dbus_message_get_args (DBusMessage *message, DBusError *error, int first_arg_type, ...);
;(def-call-out dbus_message_get_args (:return-type dbus_bool_t)
;  (:arguments (message DBusMessage*) (error (c-pointer DBusError)) (first_arg_type int) (... )))

;; dbus_bool_t dbus_message_get_args_valist (DBusMessage *message, DBusError *error, int first_arg_type, va_list var_args);
;(def-call-out dbus_message_get_args_valist (:return-type dbus_bool_t)
;  (:arguments (message DBusMessage*) (error (c-pointer DBusError)) (first_arg_type int) (var_args va_list)))



;; dbus_bool_t dbus_message_iter_init (DBusMessage *message, DBusMessageIter *iter);
(def-call-out dbus_message_iter_init (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (iter DBusMessageIter*)))

;; dbus_bool_t dbus_message_iter_has_next (DBusMessageIter *iter);
(def-call-out dbus_message_iter_has_next (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*)))

;; dbus_bool_t dbus_message_iter_next (DBusMessageIter *iter);
(def-call-out dbus_message_iter_next (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*)))

;; char* dbus_message_iter_get_signature (DBusMessageIter *iter);
(def-call-out dbus_message_iter_get_signature (:return-type c-string)
  (:arguments (iter DBusMessageIter*)))

;; int dbus_message_iter_get_arg_type (DBusMessageIter *iter);
(def-call-out dbus_message_iter_get_arg_type (:return-type int)
  (:arguments (iter DBusMessageIter*)))

;; int dbus_message_iter_get_element_type (DBusMessageIter *iter);
(def-call-out dbus_message_iter_get_element_type (:return-type int)
  (:arguments (iter DBusMessageIter*)))

;; void dbus_message_iter_recurse (DBusMessageIter *iter, DBusMessageIter *sub);
(def-call-out dbus_message_iter_recurse (:return-type nil)
  (:arguments (iter DBusMessageIter*) (sub DBusMessageIter*)))

;; void dbus_message_iter_get_basic (DBusMessageIter *iter, void *value);
(def-call-out dbus_message_iter_get_basic (:return-type nil)
  (:arguments (iter DBusMessageIter*) (value c-pointer)))

;; void dbus_message_iter_get_fixed_array (DBusMessageIter *iter, void *value, int *n_elements);
(def-call-out dbus_message_iter_get_fixed_array (:return-type nil)
  (:arguments (iter DBusMessageIter*) (value c-pointer)
              (n_elements (c-ptr int) :out)))



;; void dbus_message_iter_init_append (DBusMessage *message, DBusMessageIter *iter);
(def-call-out dbus_message_iter_init_append (:return-type nil)
  (:arguments (message DBusMessage*) (iter DBusMessageIter*)))

;; dbus_bool_t dbus_message_iter_append_basic (DBusMessageIter *iter, int type, const void *value);
(def-call-out dbus_message_iter_append_basic (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*) (type int) (value c-pointer)))

;; dbus_bool_t dbus_message_iter_append_fixed_array (DBusMessageIter *iter, int element_type, const void *value, int n_elements);
(def-call-out dbus_message_iter_append_fixed_array (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*) (element_type int)
              (value c-pointer) (n_elements int)))

;; dbus_bool_t dbus_message_iter_open_container (DBusMessageIter *iter, int type, const char *contained_signature, DBusMessageIter *sub);
(def-call-out dbus_message_iter_open_container (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*) (type int)
              (contained_signature c-string) (sub DBusMessageIter*)))

;; dbus_bool_t dbus_message_iter_close_container (DBusMessageIter *iter, DBusMessageIter *sub);
(def-call-out dbus_message_iter_close_container (:return-type dbus_bool_t)
  (:arguments (iter DBusMessageIter*) (sub DBusMessageIter*)))

;; void dbus_message_lock (DBusMessage *message);
(def-call-out dbus_message_lock (:return-type nil)
  (:arguments (message DBusMessage*)))

;; dbus_bool_t dbus_set_error_from_message (DBusError *error, DBusMessage *message);
(def-call-out dbus_set_error_from_message (:return-type dbus_bool_t)
  (:arguments (error (c-pointer DBusError)) (message DBusMessage*)))



;; dbus_bool_t dbus_message_allocate_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_message_allocate_data_slot (:return-type dbus_bool_t)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; void dbus_message_free_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_message_free_data_slot (:return-type nil)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; dbus_bool_t dbus_message_set_data (DBusMessage *message, dbus_int32_t slot, void *data, DBusFreeFunction free_data_func);
(def-call-out dbus_message_set_data (:return-type dbus_bool_t)
  (:arguments (message DBusMessage*) (slot dbus_int32_t) (data c-pointer)
              (free_data_func DBusFreeFunction)))

;; void* dbus_message_get_data (DBusMessage *message, dbus_int32_t slot);
(def-call-out dbus_message_get_data (:return-type c-pointer)
  (:arguments (message DBusMessage*) (slot dbus_int32_t)))


;; int dbus_message_type_from_string (const char *type_str);
(def-call-out dbus_message_type_from_string (:return-type int)
  (:arguments (type_str c-string)))

;; const char * dbus_message_type_to_string (int type);
(def-call-out dbus_message_type_to_string (:return-type c-string)
  (:arguments (type int)))

;; dbus_bool_t dbus_message_marshal (DBusMessage *msg, char **marshalled_data_p, int *len_p);
(def-call-out dbus_message_marshal (:return-type dbus_bool_t)
  (:arguments (msg DBusMessage*)
              (marshalled_data_p (c-ptr c-pointer) :out)
              (len_p (c-ptr int) :out)))

;; DBusMessage* dbus_message_demarshal (const char *str, int len, DBusError *error);
(def-call-out dbus_message_demarshal (:return-type DBusMessage*)
  (:arguments (str c-pointer) (len int) (error (c-pointer DBusError))))

;; int dbus_message_demarshal_bytes_needed (const char *str, int len);
(def-call-out dbus_message_demarshal_bytes_needed (:return-type int)
  (:arguments (str c-pointer) (len int)))


;; === dbus-shared.h

(def-c-enum DBusBusType         ; see dbus_bus_get
  DBUS_BUS_SESSION              ; The login session bus
  DBUS_BUS_SYSTEM               ; The systemwide bus
  DBUS_BUS_STARTER)             ; The bus that started us, if any

(def-c-enum DBusHandlerResult   ; Results that a message handler can return
  DBUS_HANDLER_RESULT_HANDLED ; Message has had its effect - no need to run more handlers.
  DBUS_HANDLER_RESULT_NOT_YET_HANDLED ; Message has not had any effect - see if other handlers want it.
  DBUS_HANDLER_RESULT_NEED_MEMORY ; Need more memory in order to return #DBUS_HANDLER_RESULT_HANDLED or #DBUS_HANDLER_RESULT_NOT_YET_HANDLED. Please try again later with more memory.
  )

;; Bus names
(def-c-const DBUS_SERVICE_DBUS (:type c-string) ; "org.freedesktop.DBus"
  (:documentation "The bus name used to talk to the bus itself."))

;; Paths
(def-c-const DBUS_PATH_DBUS (:type c-string) ; "/org/freedesktop/DBus"
  (:documentation "The object path used to talk to the bus itself."))
(def-c-const DBUS_PATH_LOCAL (:type c-string) ; "/org/freedesktop/DBus/Local"
  (:documentation "The object path used in local/in-process-generated messages."))

;; Interfaces, these #define don't do much other than catch typos at compile time
(def-c-const DBUS_INTERFACE_DBUS (:type c-string) ; "org.freedesktop.DBus"
  (:documentation "The interface exported by the object with #DBUS_SERVICE_DBUS and #DBUS_PATH_DBUS"))
(def-c-const DBUS_INTERFACE_INTROSPECTABLE (:type c-string) ; "org.freedesktop.DBus.Introspectable"
  (:documentation "The interface supported by introspectable objects."))
(def-c-const DBUS_INTERFACE_PROPERTIES (:type c-string) ; "org.freedesktop.DBus.Properties"
  (:documentation "The interface supported by objects with properties."))
(def-c-const DBUS_INTERFACE_PEER (:type c-string) ; "org.freedesktop.DBus.Peer"
  (:documentation "The interface supported by most dbus peers."))
(def-c-const DBUS_INTERFACE_LOCAL (:type c-string) ; "org.freedesktop.DBus.Local"
  (:documentation "This is a special interface whose methods can only be invoked by the local implementation (messages from remote apps aren't allowed to specify this interface)."))

;; Owner flags
(def-c-const DBUS_NAME_FLAG_ALLOW_REPLACEMENT ; 0x1
  (:documentation "Allow another service to become the primary owner if requested"))
(def-c-const DBUS_NAME_FLAG_REPLACE_EXISTING ; 0x2
  (:documentation "Request to replace the current primary owner"))
(def-c-const DBUS_NAME_FLAG_DO_NOT_QUEUE ; 0x4
  (:documentation "If we can not become the primary owner do not place us in the queue"))

;; Replies to request for a name
(def-c-const DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER ; 1
  (:documentation "Service has become the primary owner of the requested name"))
(def-c-const DBUS_REQUEST_NAME_REPLY_IN_QUEUE ; 2
  (:documentation "Service could not become the primary owner and has been placed in the queue"))
(def-c-const DBUS_REQUEST_NAME_REPLY_EXISTS ; 3
  (:documentation "Service is already in the queue"))
(def-c-const DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER ; 4
  (:documentation "Service is already the primary owner"))

;; Replies to releasing a name
(def-c-const DBUS_RELEASE_NAME_REPLY_RELEASED ; 1
  (:documentation "Service was released from the given name"))
(def-c-const DBUS_RELEASE_NAME_REPLY_NON_EXISTENT ; 2
  (:documentation "The given name does not exist on the bus"))
(def-c-const DBUS_RELEASE_NAME_REPLY_NOT_OWNER ; 3
  (:documentation "Service is not an owner of the given name"))

;; Replies to service starts
(def-c-const DBUS_START_REPLY_SUCCESS ; 1
  (:documentation "Service was auto started"))
(def-c-const DBUS_START_REPLY_ALREADY_RUNNING ; 2
  (:documentation "Service was already running"))

;; === dbus-connection.h

;; documented in dbus-watch.c
;; typedef struct DBusWatch DBusWatch;
(def-c-type DBusWatch* c-pointer)

;; documented in dbus-timeout.c
;; typedef struct DBusTimeout DBusTimeout;
(def-c-type DBusTimeout* c-pointer)

;; Opaque type representing preallocated resources so a message
;; can be sent without further memory allocation.
;; typedef struct DBusPreallocatedSend DBusPreallocatedSend;
(def-c-type DBusPreallocatedSend* c-pointer)

;; Opaque type representing a method call that has not yet received a reply.
;; typedef struct DBusPendingCall DBusPendingCall;
(def-c-type DBusPendingCall* c-pointer)

;; Opaque type representing a connection to a remote application
;; and associated incoming/outgoing message queues.
;; typedef struct DBusConnection DBusConnection;
(def-c-type DBusConnection* c-pointer)

;; Set of functions that must be implemented to handle messages
;; sent to a particular object path.
;; typedef struct DBusObjectPathVTable DBusObjectPathVTable;
(def-c-type DBusObjectPathVTable* c-pointer)

(def-c-enum DBusWatchFlags        ; Indicates the status of a #DBusWatch
  (DBUS_WATCH_READABLE (ash 1 0)) ; As in POLLIN
  (DBUS_WATCH_WRITABLE (ash 1 1)) ; As in POLLOUT
  (DBUS_WATCH_ERROR (ash 1 2)) ; As in POLLERR (can't watch for this, but can be present in current state passed to dbus_watch_handle()).
  (DBUS_WATCH_HANGUP (ash 1 3)) ; As in POLLHUP (can't watch for it, but can be present in current state passed to dbus_watch_handle()).
  )

;; Indicates the status of incoming data on a #DBusConnection.
;; This determines whether dbus_connection_dispatch() needs to be called.
(def-c-enum DBusDispatchStatus
  DBUS_DISPATCH_DATA_REMAINS ; There is more data to potentially convert to messages.
  DBUS_DISPATCH_COMPLETE ; All currently available data has been processed.
  DBUS_DISPATCH_NEED_MEMORY ; More memory is needed to continue.
  )


;; Called when libdbus needs a new watch to be monitored by the main loop.
;; Returns #FALSE if it lacks enough memory to add the watch.
;; Set by dbus_connection_set_watch_functions()
;; or dbus_server_set_watch_functions().
;; typedef dbus_bool_t (* DBusAddWatchFunction) (DBusWatch *watch, void *data);
(def-c-type DBusAddWatchFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (watch DBusWatch*) (data c-pointer))))
(def-c-type DBusAddWatchFunction* (c-pointer DBusAddWatchFunction))

;; Called when dbus_watch_get_enabled() may return a different value than
;; it did before.  Set by dbus_connection_set_watch_functions() or
;; dbus_server_set_watch_functions().
;; typedef void (* DBusWatchToggledFunction) (DBusWatch *watch, void *data);
(def-c-type DBusWatchToggledFunction
  (c-function (:return-type nil)
              (:arguments (watch DBusWatch*) (data c-pointer))))
(def-c-type DBusWatchToggledFunction* (c-pointer DBusWatchToggledFunction))

;; Called when libdbus no longer needs a watch to be monitored by the main
;; loop. Set by dbus_connection_set_watch_functions() or
;; dbus_server_set_watch_functions().
;; typedef void (* DBusRemoveWatchFunction) (DBusWatch *watch, void *data);
(def-c-type DBusRemoveWatchFunction
  (c-function (:return-type nil)
              (:arguments (watch DBusWatch*) (data c-pointer))))
(def-c-type DBusRemoveWatchFunction* (c-pointer DBusRemoveWatchFunction))

;; Called when libdbus needs a new timeout to be monitored by the main
;; loop. Returns #FALSE if it lacks enough memory to add the watch.
;; Set by dbus_connection_set_timeout_functions() or
;; dbus_server_set_timeout_functions().
;; typedef dbus_bool_t (* DBusAddTimeoutFunction) (DBusTimeout *timeout, void *data);
(def-c-type DBusAddTimeoutFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (timeout DBusTimeout*) (data c-pointer))))
(def-c-type DBusAddTimeoutFunction* (c-pointer DBusAddTimeoutFunction))

;; Called when dbus_timeout_get_enabled() may return a different value than
;; it did before.  Set by dbus_connection_set_timeout_functions() or
;; dbus_server_set_timeout_functions().
;; typedef void (* DBusTimeoutToggledFunction) (DBusTimeout *timeout, void *data);
(def-c-type DBusTimeoutToggledFunction
  (c-function (:return-type nil)
              (:arguments (timeout DBusTimeout*) (data c-pointer))))
(def-c-type DBusTimeoutToggledFunction* (c-pointer DBusTimeoutToggledFunction))

;; Called when libdbus no longer needs a timeout to be monitored by the
;; main loop. Set by dbus_connection_set_timeout_functions() or
;; dbus_server_set_timeout_functions().
;; typedef void (* DBusRemoveTimeoutFunction) (DBusTimeout *timeout, void *data);
(def-c-type DBusRemoveTimeoutFunction
  (c-function (:return-type nil)
              (:arguments (timeout DBusTimeout*) (data c-pointer))))
(def-c-type DBusRemoveTimeoutFunction* (c-pointer DBusRemoveTimeoutFunction))

;; Called when the return value of dbus_connection_get_dispatch_status()
;; may have changed. Set with dbus_connection_set_dispatch_status_function().
;; typedef void (* DBusDispatchStatusFunction) (DBusConnection *connection, DBusDispatchStatus new_status, void *data);
(def-c-type DBusDispatchStatusFunction
  (c-function (:return-type nil)
              (:arguments (connection DBusConnection*)
                          (new_status DBusDispatchStatus) (data c-pointer))))
(def-c-type DBusDispatchStatusFunction* (c-pointer DBusDispatchStatusFunction))


;; Called when the main loop's thread should be notified that there's now
;; work to do. Set with dbus_connection_set_wakeup_main_function().
;; typedef void (* DBusWakeupMainFunction) (void *data);
(def-c-type DBusWakeupMainFunction
  (c-function (:return-type nil)
              (:arguments (data c-pointer))))
(def-c-type DBusWakeupMainFunction* (c-pointer DBusWakeupMainFunction))


;; Called during authentication to check whether the given UNIX user
;; ID is allowed to connect, if the client tried to auth as a UNIX user ID.
;; Normally on Windows this would never happen.
;; Set with dbus_connection_set_unix_user_function().
;; typedef dbus_bool_t (* DBusAllowUnixUserFunction) (DBusConnection *connection, unsigned long uid, void *data);
(def-c-type DBusAllowUnixUserFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (connection DBusConnection*)
                          (uid ulong) (data c-pointer))))
(def-c-type DBusAllowUnixUserFunction* (c-pointer DBusAllowUnixUserFunction))


;; Called during authentication to check whether the given Windows user
;; ID is allowed to connect, if the client tried to auth as a Windows user ID.
;; Normally on UNIX this would never happen.
;; Set with dbus_connection_set_windows_user_function().
;; typedef dbus_bool_t (* DBusAllowWindowsUserFunction) (DBusConnection *connection, const char *user_sid, void *data);
(def-c-type DBusAllowWindowsUserFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (connection DBusConnection*)
                          (user_sid c-string) (data c-pointer))))
(def-c-type DBusAllowWindowsUserFunction* (c-pointer DBusAllowWindowsUserFunction))

;; Called when a pending call now has a reply available.
;; Set with dbus_pending_call_set_notify().
;; typedef void (* DBusPendingCallNotifyFunction) (DBusPendingCall *pending, void *user_data);
(def-c-type DBusPendingCallNotifyFunction
  (c-function (:return-type nil)
              (:arguments (pending DBusPendingCall*) (user_data c-pointer))))
(def-c-type DBusPendingCallNotifyFunction*
  (c-pointer DBusPendingCallNotifyFunction))



;; Called when a message needs to be handled. The result indicates whether
;; or not more handlers should be run. Set with dbus_connection_add_filter().
;; typedef DBusHandlerResult (* DBusHandleMessageFunction) (DBusConnection *connection, DBusMessage *message, void *user_data);
(def-c-type DBusHandleMessageFunction
  (c-function (:return-type DBusHandlerResult)
              (:arguments (connection DBusConnection*) (message DBusMessage*)
                          (user_data c-pointer))))
(def-c-type DBusHandleMessageFunction* (c-pointer DBusHandleMessageFunction))


;; DBusConnection* dbus_connection_open (const char *address, DBusError *error);
(def-call-out dbus_connection_open (:return-type DBusConnection*)
  (:arguments (address c-string) (error (c-pointer DBusError))))

;; DBusConnection* dbus_connection_open_private (const char *address, DBusError *error);
(def-call-out dbus_connection_open_private (:return-type DBusConnection*)
  (:arguments (address c-string) (error (c-pointer DBusError))))

;; DBusConnection* dbus_connection_ref (DBusConnection *connection);
(def-call-out dbus_connection_ref (:return-type DBusConnection*)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_unref (DBusConnection *connection);
(def-call-out dbus_connection_unref (:return-type nil)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_close (DBusConnection *connection);
(def-call-out dbus_connection_close (:return-type nil)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_get_is_connected (DBusConnection *connection);
(def-call-out dbus_connection_get_is_connected (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_get_is_authenticated (DBusConnection *connection);
(def-call-out dbus_connection_get_is_authenticated (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_get_is_anonymous (DBusConnection *connection);
(def-call-out dbus_connection_get_is_anonymous (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)))

;; char* dbus_connection_get_server_id (DBusConnection *connection);
(def-call-out dbus_connection_get_server_id (:return-type c-string)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_set_exit_on_disconnect (DBusConnection *connection, dbus_bool_t exit_on_disconnect);
(def-call-out dbus_connection_set_exit_on_disconnect (:return-type nil)
  (:arguments (connection DBusConnection*) (exit_on_disconnect dbus_bool_t)))

;; void dbus_connection_flush (DBusConnection *connection);
(def-call-out dbus_connection_flush (:return-type nil)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_read_write_dispatch (DBusConnection *connection, int timeout_milliseconds);
(def-call-out dbus_connection_read_write_dispatch (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (timeout_milliseconds int)))

;; dbus_bool_t dbus_connection_read_write (DBusConnection *connection, int timeout_milliseconds);
(def-call-out dbus_connection_read_write (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (timeout_milliseconds int)))

;; DBusMessage* dbus_connection_borrow_message (DBusConnection *connection);
(def-call-out dbus_connection_borrow_message (:return-type DBusMessage*)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_return_message (DBusConnection *connection, DBusMessage *message);
(def-call-out dbus_connection_return_message (:return-type nil)
  (:arguments (connection DBusConnection*) (message DBusMessage*)))

;; void dbus_connection_steal_borrowed_message (DBusConnection *connection, DBusMessage *message);
(def-call-out dbus_connection_steal_borrowed_message (:return-type nil)
  (:arguments (connection DBusConnection*) (message DBusMessage*)))

;; DBusMessage* dbus_connection_pop_message (DBusConnection *connection);
(def-call-out dbus_connection_pop_message (:return-type DBusMessage*)
  (:arguments (connection DBusConnection*)))

;; DBusDispatchStatus dbus_connection_get_dispatch_status (DBusConnection *connection);
(def-call-out dbus_connection_get_dispatch_status (:return-type DBusDispatchStatus)
  (:arguments (connection DBusConnection*)))

;; DBusDispatchStatus dbus_connection_dispatch (DBusConnection *connection);
(def-call-out dbus_connection_dispatch (:return-type DBusDispatchStatus)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_has_messages_to_send (DBusConnection *connection);
(def-call-out dbus_connection_has_messages_to_send (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)))

;; dbus_bool_t dbus_connection_send (DBusConnection *connection, DBusMessage *message, dbus_uint32_t *client_serial);
(def-call-out dbus_connection_send (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (message DBusMessage*)
              (client_serial (c-ptr dbus_uint32_t) :out)))

;; dbus_bool_t dbus_connection_send_with_reply (DBusConnection *connection, DBusMessage *message, DBusPendingCall **pending_return, int timeout_milliseconds);
(def-call-out dbus_connection_send_with_reply (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (message DBusMessage*)
              (pending_return (c-ptr DBusPendingCall*) :out) ;??
              (timeout_milliseconds int)))

;; DBusMessage * dbus_connection_send_with_reply_and_block (DBusConnection *connection, DBusMessage *message, int timeout_milliseconds, DBusError *error);
(def-call-out dbus_connection_send_with_reply_and_block (:return-type DBusMessage*)
  (:arguments (connection DBusConnection*) (message DBusMessage*)
              (timeout_milliseconds int) (error (c-pointer DBusError))))

;; dbus_bool_t dbus_connection_set_watch_functions (DBusConnection *connection, DBusAddWatchFunction add_function, DBusRemoveWatchFunction remove_function, DBusWatchToggledFunction toggled_function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_watch_functions (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)
              (add_function DBusAddWatchFunction)
              (remove_function DBusRemoveWatchFunction)
              (toggled_function DBusWatchToggledFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_connection_set_timeout_functions (DBusConnection *connection, DBusAddTimeoutFunction add_function, DBusRemoveTimeoutFunction remove_function, DBusTimeoutToggledFunction toggled_function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_timeout_functions (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)
              (add_function DBusAddTimeoutFunction)
              (remove_function DBusRemoveTimeoutFunction)
              (toggled_function DBusTimeoutToggledFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; void dbus_connection_set_wakeup_main_function (DBusConnection *connection, DBusWakeupMainFunction wakeup_main_function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_wakeup_main_function (:return-type nil)
  (:arguments (connection DBusConnection*)
              (wakeup_main_function DBusWakeupMainFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; void dbus_connection_set_dispatch_status_function (DBusConnection *connection, DBusDispatchStatusFunction function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_dispatch_status_function (:return-type nil)
  (:arguments (connection DBusConnection*)
              (function DBusDispatchStatusFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_connection_get_unix_user (DBusConnection *connection, unsigned long *uid);
(def-call-out dbus_connection_get_unix_user (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (uid (c-ptr ulong) :out)))

;; dbus_bool_t dbus_connection_get_unix_process_id (DBusConnection *connection, unsigned long *pid);
(def-call-out dbus_connection_get_unix_process_id (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (pid (c-ptr ulong) :out)))

;; dbus_bool_t dbus_connection_get_adt_audit_session_data (DBusConnection *connection, void **data, dbus_int32_t *data_size);
(def-call-out dbus_connection_get_adt_audit_session_data
    (:arguments (connection DBusConnection*)
                (data (c-ptr c-pointer) :out)
                (data_size (c-ptr dbus_int32_t) :out))
  (:return-type dbus_bool_t))

;; void dbus_connection_set_unix_user_function (DBusConnection *connection, DBusAllowUnixUserFunction function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_unix_user_function (:return-type nil)
  (:arguments (connection DBusConnection*) (function DBusAllowUnixUserFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_connection_get_windows_user (DBusConnection *connection, char **windows_sid_p);
(def-call-out dbus_connection_get_windows_user (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*)
              (windows_sid_p (c-ptr c-string) :out)))

;; void dbus_connection_set_windows_user_function (DBusConnection *connection, DBusAllowWindowsUserFunction function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_set_windows_user_function (:return-type nil)
  (:arguments (connection DBusConnection*)
              (function DBusAllowWindowsUserFunction) (data c-pointer)
              (free_data_function DBusFreeFunction)))

;; void dbus_connection_set_allow_anonymous (DBusConnection *connection, dbus_bool_t value);
(def-call-out dbus_connection_set_allow_anonymous (:return-type nil)
  (:arguments (connection DBusConnection*) (value dbus_bool_t)))

;; void dbus_connection_set_route_peer_messages (DBusConnection *connection, dbus_bool_t value);
(def-call-out dbus_connection_set_route_peer_messages (:return-type nil)
  (:arguments (connection DBusConnection*) (value dbus_bool_t)))



;; Filters

;; dbus_bool_t dbus_connection_add_filter (DBusConnection *connection, DBusHandleMessageFunction function, void *user_data, DBusFreeFunction free_data_function);
(def-call-out dbus_connection_add_filter (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (function DBusHandleMessageFunction)
              (user_data c-pointer) (free_data_function DBusFreeFunction)))

;; void dbus_connection_remove_filter (DBusConnection *connection, DBusHandleMessageFunction function, void *user_data);
(def-call-out dbus_connection_remove_filter (:return-type nil)
  (:arguments (connection DBusConnection*) (function DBusHandleMessageFunction) (user_data c-pointer)))


;; Other
;; dbus_bool_t dbus_connection_allocate_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_connection_allocate_data_slot (:return-type dbus_bool_t)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; void dbus_connection_free_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_connection_free_data_slot (:return-type nil)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; dbus_bool_t dbus_connection_set_data (DBusConnection *connection, dbus_int32_t slot, void *data, DBusFreeFunction free_data_func);
(def-call-out dbus_connection_set_data (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (slot dbus_int32_t) (data c-pointer) (free_data_func DBusFreeFunction)))

;; void* dbus_connection_get_data (DBusConnection *connection, dbus_int32_t slot);
(def-call-out dbus_connection_get_data (:return-type c-pointer)
  (:arguments (connection DBusConnection*) (slot dbus_int32_t)))


;; void dbus_connection_set_change_sigpipe (dbus_bool_t will_modify_sigpipe);
(def-call-out dbus_connection_set_change_sigpipe (:return-type nil)
  (:arguments (will_modify_sigpipe dbus_bool_t)))


;; void dbus_connection_set_max_message_size (DBusConnection *connection, long size);
(def-call-out dbus_connection_set_max_message_size (:return-type nil)
  (:arguments (connection DBusConnection*) (size long)))

;; long dbus_connection_get_max_message_size (DBusConnection *connection);
(def-call-out dbus_connection_get_max_message_size (:return-type long)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_set_max_received_size (DBusConnection *connection, long size);
(def-call-out dbus_connection_set_max_received_size (:return-type nil)
  (:arguments (connection DBusConnection*) (size long)))

;; long dbus_connection_get_max_received_size (DBusConnection *connection);
(def-call-out dbus_connection_get_max_received_size (:return-type long)
  (:arguments (connection DBusConnection*)))

;; long dbus_connection_get_outgoing_size (DBusConnection *connection);
(def-call-out dbus_connection_get_outgoing_size (:return-type long)
  (:arguments (connection DBusConnection*)))


;; DBusPreallocatedSend* dbus_connection_preallocate_send (DBusConnection *connection);
(def-call-out dbus_connection_preallocate_send (:return-type DBusPreallocatedSend*)
  (:arguments (connection DBusConnection*)))

;; void dbus_connection_free_preallocated_send (DBusConnection *connection, DBusPreallocatedSend *preallocated);
(def-call-out dbus_connection_free_preallocated_send (:return-type nil)
  (:arguments (connection DBusConnection*)
              (preallocated DBusPreallocatedSend*)))

;; void dbus_connection_send_preallocated (DBusConnection *connection, DBusPreallocatedSend *preallocated, DBusMessage *message, dbus_uint32_t *client_serial);
(def-call-out dbus_connection_send_preallocated (:return-type nil)
  (:arguments (connection DBusConnection*) (preallocated DBusPreallocatedSend*)
              (message DBusMessage*)
              (client_serial (c-ptr dbus_uint32_t) :out)))


;; Object tree functionality


;; Called when a #DBusObjectPathVTable is unregistered (or its connection
;; is freed).  Found in #DBusObjectPathVTable.
;; typedef void (* DBusObjectPathUnregisterFunction) (DBusConnection *connection, void *user_data);
(def-c-type DBusObjectPathUnregisterFunction
  (c-function (:return-type nil)
              (:arguments (connection DBusConnection*) (user_data c-pointer))))
(def-c-type DBusObjectPathUnregisterFunction*
  (c-pointer DBusObjectPathUnregisterFunction))


;; Called when a message is sent to a registered object path. Found in
;; #DBusObjectPathVTable which is registered with
;; dbus_connection_register_object_path() or
;; dbus_connection_register_fallback().
;; typedef DBusHandlerResult (* DBusObjectPathMessageFunction) (DBusConnection *connection, DBusMessage *message, void *user_data);
(def-c-type DBusObjectPathMessageFunction
  (c-function (:return-type DBusHandlerResult)
              (:arguments (connection DBusConnection*) (message DBusMessage*)
                          (user_data c-pointer))))
(def-c-type DBusObjectPathMessageFunction*
  (c-pointer DBusObjectPathMessageFunction))



;; Virtual table that must be implemented to handle a portion of the object
;; path hierarchy. Attach the vtable to a particular path using
;; dbus_connection_register_object_path() or
;; dbus_connection_register_fallback().
(def-c-struct DBusObjectPathVTable
  (unregister_function DBusObjectPathUnregisterFunction) ; Function to unregister this handler
  (message_function DBusObjectPathMessageFunction) ; Function to handle messages
  (dbus_internal_pad1 c-pointer) ; Reserved for future expansion
  (dbus_internal_pad2 c-pointer) ; Reserved for future expansion
  (dbus_internal_pad3 c-pointer) ; Reserved for future expansion
  (dbus_internal_pad4 c-pointer) ; Reserved for future expansion
  )

;; dbus_bool_t dbus_connection_try_register_object_path (DBusConnection *connection, const char *path, const DBusObjectPathVTable *vtable, void *user_data, DBusError *error);
(def-call-out dbus_connection_try_register_object_path (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)
              (vtable DBusObjectPathVTable*) (user_data c-pointer)
              (error (c-pointer DBusError))))

;; dbus_bool_t dbus_connection_register_object_path (DBusConnection *connection, const char *path, const DBusObjectPathVTable *vtable, void *user_data);
(def-call-out dbus_connection_register_object_path (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)
              (vtable DBusObjectPathVTable*) (user_data c-pointer)))

;; dbus_bool_t dbus_connection_try_register_fallback (DBusConnection *connection, const char *path, const DBusObjectPathVTable *vtable, void *user_data, DBusError *error);
(def-call-out dbus_connection_try_register_fallback (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)
              (vtable DBusObjectPathVTable*) (user_data c-pointer)
              (error (c-pointer DBusError))))

;; dbus_bool_t dbus_connection_register_fallback (DBusConnection *connection, const char *path, const DBusObjectPathVTable *vtable, void *user_data);
(def-call-out dbus_connection_register_fallback (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)
              (vtable DBusObjectPathVTable*) (user_data c-pointer)))

;; dbus_bool_t dbus_connection_unregister_object_path (DBusConnection *connection, const char *path);
(def-call-out dbus_connection_unregister_object_path (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)))


;; dbus_bool_t dbus_connection_get_object_path_data (DBusConnection *connection, const char *path, void **data_p);
(def-call-out dbus_connection_get_object_path_data (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (path c-string)
              (data_p (c-ptr c-pointer) :out)))


;; dbus_bool_t dbus_connection_list_registered (DBusConnection *connection, const char *parent_path, char ***child_entries);
(def-call-out dbus_connection_list_registered (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (parent_path c-string)
              (child_entries (c-ptr (c-array-ptr c-string)) :out)))

;;  dbus_bool_t dbus_connection_get_unix_fd (DBusConnection *connection, int *fd);
(def-call-out dbus_connection_get_unix_fd (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (fd (c-ptr int) :out)))

;; dbus_bool_t dbus_connection_get_socket (DBusConnection *connection, int *fd);
(def-call-out dbus_connection_get_socket (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (fd (c-ptr int) :out)))


;; [removed in 1.2.1] char* dbus_get_local_machine_id (void);
(def-call-out dbus_get_local_machine_id (:return-type c-string)
  (:arguments))

;; [deprecated in 1.2.1] int dbus_watch_get_fd (DBusWatch *watch);
(def-call-out dbus_watch_get_fd (:return-type int)
  (:arguments (watch DBusWatch*)))

;; int dbus_watch_get_unix_fd (DBusWatch *watch);
(def-call-out dbus_watch_get_unix_fd (:return-type int)
  (:arguments (watch DBusWatch*)))

;; int dbus_watch_get_socket (DBusWatch *watch);
(def-call-out dbus_watch_get_socket (:return-type int)
  (:arguments (watch DBusWatch*)))

;; unsigned int dbus_watch_get_flags (DBusWatch *watch);
(def-call-out dbus_watch_get_flags (:return-type uint)
  (:arguments (watch DBusWatch*)))

;; void* dbus_watch_get_data (DBusWatch *watch);
(def-call-out dbus_watch_get_data (:return-type c-pointer)
  (:arguments (watch DBusWatch*)))

;; void dbus_watch_set_data (DBusWatch *watch, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_watch_set_data (:return-type nil)
  (:arguments (watch DBusWatch*) (data c-pointer)
              (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_watch_handle (DBusWatch *watch, unsigned int flags);
(def-call-out dbus_watch_handle (:return-type dbus_bool_t)
  (:arguments (watch DBusWatch*) (flags uint)))

;; dbus_bool_t dbus_watch_get_enabled (DBusWatch *watch);
(def-call-out dbus_watch_get_enabled (:return-type dbus_bool_t)
  (:arguments (watch DBusWatch*)))



;; int dbus_timeout_get_interval (DBusTimeout *timeout);
(def-call-out dbus_timeout_get_interval (:return-type int)
  (:arguments (timeout DBusTimeout*)))

;; void* dbus_timeout_get_data (DBusTimeout *timeout);
(def-call-out dbus_timeout_get_data (:return-type c-pointer)
  (:arguments (timeout DBusTimeout*)))

;; void dbus_timeout_set_data (DBusTimeout *timeout, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_timeout_set_data (:return-type nil)
  (:arguments (timeout DBusTimeout*) (data c-pointer)
              (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_timeout_handle (DBusTimeout *timeout);
(def-call-out dbus_timeout_handle (:return-type dbus_bool_t)
  (:arguments (timeout DBusTimeout*)))

;; dbus_bool_t dbus_timeout_get_enabled (DBusTimeout *timeout);
(def-call-out dbus_timeout_get_enabled (:return-type dbus_bool_t)
  (:arguments (timeout DBusTimeout*)))


;; === dbus-bus.h

;; DBusConnection *dbus_bus_get (DBusBusType type, DBusError *error);
(def-call-out dbus_bus_get (:return-type DBusConnection*)
  (:arguments (type DBusBusType) (error (c-pointer DBusError))))

;; DBusConnection *dbus_bus_get_private (DBusBusType type, DBusError *error);
(def-call-out dbus_bus_get_private (:return-type DBusConnection*)
  (:arguments (type DBusBusType) (error (c-pointer DBusError))))


;; dbus_bool_t dbus_bus_register (DBusConnection *connection, DBusError *error);
(def-call-out dbus_bus_register (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (error (c-pointer DBusError))))

;; dbus_bool_t dbus_bus_set_unique_name (DBusConnection *connection, const char *unique_name);
(def-call-out dbus_bus_set_unique_name (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (unique_name c-string)))

;; const char* dbus_bus_get_unique_name (DBusConnection *connection);
(def-call-out dbus_bus_get_unique_name (:return-type c-string)
  (:arguments (connection DBusConnection*)))

;; unsigned long dbus_bus_get_unix_user (DBusConnection *connection, const char *name, DBusError *error);
(def-call-out dbus_bus_get_unix_user (:return-type ulong)
  (:arguments (connection DBusConnection*) (name c-string)
              (error (c-pointer DBusError))))

;; char* dbus_bus_get_id (DBusConnection *connection, DBusError *error);
(def-call-out dbus_bus_get_id (:return-type c-string)
  (:arguments (connection DBusConnection*) (error (c-pointer DBusError))))

;; int dbus_bus_request_name (DBusConnection *connection, const char *name, unsigned int flags, DBusError *error);
(def-call-out dbus_bus_request_name (:return-type int)
  (:arguments (connection DBusConnection*) (name c-string)
              (flags uint) (error (c-pointer DBusError))))

;; int dbus_bus_release_name (DBusConnection *connection, const char *name, DBusError *error);
(def-call-out dbus_bus_release_name (:return-type int)
  (:arguments (connection DBusConnection*) (name c-string)
              (error (c-pointer DBusError))))

;; dbus_bool_t dbus_bus_name_has_owner (DBusConnection *connection, const char *name, DBusError *error);
(def-call-out dbus_bus_name_has_owner (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (name c-string)
              (error (c-pointer DBusError))))


;; dbus_bool_t dbus_bus_start_service_by_name (DBusConnection *connection, const char *name, dbus_uint32_t flags, dbus_uint32_t *reply, DBusError *error);
(def-call-out dbus_bus_start_service_by_name (:return-type dbus_bool_t)
  (:arguments (connection DBusConnection*) (name c-string)
              (flags dbus_uint32_t) (reply (c-ptr dbus_uint32_t) :out)
              (error (c-pointer DBusError))))


;; void dbus_bus_add_match (DBusConnection *connection, const char *rule, DBusError *error);
(def-call-out dbus_bus_add_match (:return-type nil)
  (:arguments (connection DBusConnection*) (rule c-string)
              (error (c-pointer DBusError))))

;; void dbus_bus_remove_match (DBusConnection *connection, const char *rule, DBusError *error);
(def-call-out dbus_bus_remove_match (:return-type nil)
  (:arguments (connection DBusConnection*) (rule c-string)
              (error (c-pointer DBusError))))


;; === dbus-pending-call.h

;; DBusPendingCall* dbus_pending_call_ref (DBusPendingCall *pending);
(def-call-out dbus_pending_call_ref (:return-type DBusPendingCall*)
  (:arguments (pending DBusPendingCall*)))

;; void dbus_pending_call_unref (DBusPendingCall *pending);
(def-call-out dbus_pending_call_unref (:return-type nil)
  (:arguments (pending DBusPendingCall*)))

;; dbus_bool_t dbus_pending_call_set_notify (DBusPendingCall *pending, DBusPendingCallNotifyFunction function, void *user_data, DBusFreeFunction free_user_data);
(def-call-out dbus_pending_call_set_notify (:return-type dbus_bool_t)
  (:arguments (pending DBusPendingCall*)
              (function DBusPendingCallNotifyFunction)
              (user_data c-pointer) (free_user_data DBusFreeFunction)))

;; void dbus_pending_call_cancel (DBusPendingCall *pending);
(def-call-out dbus_pending_call_cancel (:return-type nil)
  (:arguments (pending DBusPendingCall*)))

;; dbus_bool_t dbus_pending_call_get_completed (DBusPendingCall *pending);
(def-call-out dbus_pending_call_get_completed (:return-type dbus_bool_t)
  (:arguments (pending DBusPendingCall*)))

;; DBusMessage* dbus_pending_call_steal_reply (DBusPendingCall *pending);
(def-call-out dbus_pending_call_steal_reply (:return-type DBusMessage*)
  (:arguments (pending DBusPendingCall*)))

;; void dbus_pending_call_block (DBusPendingCall *pending);
(def-call-out dbus_pending_call_block (:return-type nil)
  (:arguments (pending DBusPendingCall*)))


;; dbus_bool_t dbus_pending_call_allocate_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_pending_call_allocate_data_slot (:return-type dbus_bool_t)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; void dbus_pending_call_free_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_pending_call_free_data_slot (:return-type nil)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; dbus_bool_t dbus_pending_call_set_data (DBusPendingCall *pending, dbus_int32_t slot, void *data, DBusFreeFunction free_data_func);
(def-call-out dbus_pending_call_set_data (:return-type dbus_bool_t)
  (:arguments (pending DBusPendingCall*) (slot dbus_int32_t)
              (data c-pointer) (free_data_func DBusFreeFunction)))

;; void* dbus_pending_call_get_data (DBusPendingCall *pending, dbus_int32_t slot);
(def-call-out dbus_pending_call_get_data (:return-type c-pointer)
  (:arguments (pending DBusPendingCall*) (slot dbus_int32_t)))


;; === dbus-protocol.h

;; Message byte order
(def-c-const DBUS_LITTLE_ENDIAN ; ('l')
  (:documentation "Code marking LSB-first byte order in the wire protocol."))
(def-c-const DBUS_BIG_ENDIAN ; ('B')
  (:documentation "Code marking MSB-first byte order in the wire protocol."))

(def-c-const DBUS_MAJOR_PROTOCOL_VERSION ; 1
  (:documentation "Protocol version."))

(def-c-const DBUS_TYPE_INVALID ; ((int) '\0')
  (:documentation "Type code that is never equal to a legitimate type code"))
(def-c-const DBUS_TYPE_INVALID_AS_STRING (:type c-string) ; "\0"
  (:documentation "#DBUS_TYPE_INVALID as a string literal instead of a int literal"))

;; Primitive types
(def-c-const DBUS_TYPE_BYTE ; ((int) 'y')
  (:documentation "Type code marking an 8-bit unsigned integer"))
(def-c-const DBUS_TYPE_BYTE_AS_STRING (:type c-string) ; "y"
  (:documentation "#DBUS_TYPE_BYTE as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_BOOLEAN ; ((int) 'b')
  (:documentation "Type code marking a boolean"))
(def-c-const DBUS_TYPE_BOOLEAN_AS_STRING (:type c-string) ; "b"
  (:documentation "#DBUS_TYPE_BOOLEAN as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_INT16 ; ((int) 'n')
  (:documentation "Type code marking a 16-bit signed integer"))
(def-c-const DBUS_TYPE_INT16_AS_STRING (:type c-string) ; "n"
  (:documentation "#DBUS_TYPE_INT16 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_UINT16 ; ((int) 'q')
  (:documentation "Type code marking a 16-bit unsigned integer"))
(def-c-const DBUS_TYPE_UINT16_AS_STRING (:type c-string) ; "q"
  (:documentation "#DBUS_TYPE_UINT16 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_INT32 ; ((int) 'i')
  (:documentation "Type code marking a 32-bit signed integer"))
(def-c-const DBUS_TYPE_INT32_AS_STRING (:type c-string) ; "i"
  (:documentation "#DBUS_TYPE_INT32 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_UINT32 ; ((int) 'u')
  (:documentation "Type code marking a 32-bit unsigned integer"))
(def-c-const DBUS_TYPE_UINT32_AS_STRING (:type c-string) ; "u"
  (:documentation "#DBUS_TYPE_UINT32 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_INT64 ; ((int) 'x')
  (:documentation "Type code marking a 64-bit signed integer"))
(def-c-const DBUS_TYPE_INT64_AS_STRING (:type c-string) ; "x"
  (:documentation "#DBUS_TYPE_INT64 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_UINT64 ; ((int) 't')
  (:documentation "Type code marking a 64-bit unsigned integer"))
(def-c-const DBUS_TYPE_UINT64_AS_STRING (:type c-string) ; "t"
  (:documentation "#DBUS_TYPE_UINT64 as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_DOUBLE ; ((int) 'd')
  (:documentation "Type code marking an 8-byte double in IEEE 754 format"))
(def-c-const DBUS_TYPE_DOUBLE_AS_STRING (:type c-string) ; "d"
  (:documentation "#DBUS_TYPE_DOUBLE as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_STRING ; ((int) 's')
  (:documentation "Type code marking a UTF-8 encoded, nul-terminated Unicode string"))
(def-c-const DBUS_TYPE_STRING_AS_STRING (:type c-string) ; "s"
  (:documentation "#DBUS_TYPE_STRING as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_OBJECT_PATH ; ((int) 'o')
  (:documentation "Type code marking a D-Bus object path"))
(def-c-const DBUS_TYPE_OBJECT_PATH_AS_STRING (:type c-string) ; "o"
  (:documentation "#DBUS_TYPE_OBJECT_PATH as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_SIGNATURE ; ((int) 'g')
  (:documentation "Type code marking a D-Bus type signature"))
(def-c-const DBUS_TYPE_SIGNATURE_AS_STRING (:type c-string) ; "g"
  (:documentation "#DBUS_TYPE_SIGNATURE as a string literal instead of a int literal"))

;; Compound types
(def-c-const DBUS_TYPE_ARRAY ; ((int) 'a')
  (:documentation "Type code marking a D-Bus array type"))
(def-c-const DBUS_TYPE_ARRAY_AS_STRING (:type c-string) ; "a"
  (:documentation "#DBUS_TYPE_ARRAY as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_VARIANT ; ((int) 'v')
  (:documentation "Type code marking a D-Bus variant type"))
(def-c-const DBUS_TYPE_VARIANT_AS_STRING (:type c-string) ; "v"
  (:documentation "#DBUS_TYPE_VARIANT as a string literal instead of a int literal"))

;; STRUCT and DICT_ENTRY are sort of special since their codes can't appear
;; in a type string, instead
;; DBUS_STRUCT_BEGIN_CHAR/DBUS_DICT_ENTRY_BEGIN_CHAR have to appear
(def-c-const DBUS_TYPE_STRUCT ; ((int) 'r')
  (:documentation "Type code used to represent a struct;
however, this type code does not appear in type signatures,
instead #DBUS_STRUCT_BEGIN_CHAR and #DBUS_STRUCT_END_CHAR
will appear in a signature."))
(def-c-const DBUS_TYPE_STRUCT_AS_STRING (:type c-string) ; "r"
  (:documentation "#DBUS_TYPE_STRUCT as a string literal instead of a int literal"))
(def-c-const DBUS_TYPE_DICT_ENTRY ; ((int) 'e')
  (:documentation "Type code used to represent a dict entry; \
however, this type code does not appear in type signatures,
instead #DBUS_DICT_ENTRY_BEGIN_CHAR and #DBUS_DICT_ENTRY_END_CHAR
will appear in a signature."))
(def-c-const DBUS_TYPE_DICT_ENTRY_AS_STRING (:type c-string) ; "e"
  (:documentation "#DBUS_TYPE_DICT_ENTRY as a string literal instead of a int literal"))

(def-c-const DBUS_NUMBER_OF_TYPES ; (16)
  (:documentation "Does not include #DBUS_TYPE_INVALID, #DBUS_STRUCT_BEGIN_CHAR,
#DBUS_STRUCT_END_CHAR, #DBUS_DICT_ENTRY_BEGIN_CHAR, or #DBUS_DICT_ENTRY_END_CHAR
i.e. it is the number of valid types, not the number of distinct
characters that may appear in a type signature."))

;; characters other than typecodes that appear in type signatures

(def-c-const DBUS_STRUCT_BEGIN_CHAR ; ((int) '(')
  (:documentation "Code marking the start of a struct type in a type signature"))
(def-c-const DBUS_STRUCT_BEGIN_CHAR_AS_STRING (:type c-string) ; "("
  (:documentation "#DBUS_STRUCT_BEGIN_CHAR as a string literal instead of a int literal"))
(def-c-const DBUS_STRUCT_END_CHAR ; ((int) ')')
  (:documentation "Code marking the end of a struct type in a type signature"))
(def-c-const DBUS_STRUCT_END_CHAR_AS_STRING (:type c-string) ; ")"
  (:documentation "#DBUS_STRUCT_END_CHAR a string literal instead of a int literal"))
(def-c-const DBUS_DICT_ENTRY_BEGIN_CHAR ; ((int) '{')
  (:documentation "Code marking the start of a dict entry type in a type signature"))
(def-c-const DBUS_DICT_ENTRY_BEGIN_CHAR_AS_STRING (:type c-string) ; "{"
  (:documentation "#DBUS_DICT_ENTRY_BEGIN_CHAR as a string literal instead of a int literal"))
(def-c-const DBUS_DICT_ENTRY_END_CHAR ; ((int) '}')
  (:documentation "Code marking the end of a dict entry type in a type signature"))
(def-c-const DBUS_DICT_ENTRY_END_CHAR_AS_STRING (:type c-string) ; "}"
  (:documentation "#DBUS_DICT_ENTRY_END_CHAR as a string literal instead of a int literal"))


(def-c-const DBUS_MAXIMUM_NAME_LENGTH ; 255
  (:documentation "Max length in bytes of a bus name, interface,
or member (not object path, paths are unlimited).
This is limited because lots of stuff is O(n) in this number,
plus it would be obnoxious to type in a paragraph-long method name
so most likely something like that would be an exploit."))

(def-c-const DBUS_MAXIMUM_SIGNATURE_LENGTH ; 255
  (:documentation "This one is 255 so it fits in a byte"))

(def-c-const DBUS_MAXIMUM_MATCH_RULE_LENGTH ; 1024
  (:documentation "Max length of a match rule string;
to keep people from hosing the daemon with some huge rule"))

(def-c-const DBUS_MAXIMUM_MATCH_RULE_ARG_NUMBER ; 63
  (:documentation "Max arg number you can match on in a match rule,
e.g. arg0='hello' is OK, arg3489720987='hello' is not"))

(def-c-const DBUS_MAXIMUM_ARRAY_LENGTH ; (67108864)
  (:documentation "Max length of a marshaled array in bytes (64M, 2^26)
We use signed int for lengths so must be INT_MAX or less.
We need something a bit smaller than INT_MAX because the array is inside
a message with header info, etc.  so an INT_MAX array wouldn't allow
the message overhead.  The 64M number is an attempt at a larger number than
we'd reasonably ever use, but small enough that your bus would chew
through it fairly quickly without locking up forever. If you have
data that's likely to be larger than this, you should probably be
sending it in multiple incremental messages anyhow."))
(def-c-const DBUS_MAXIMUM_ARRAY_LENGTH_BITS ; 26
  (:documentation "Number of bits you need in an unsigned to store the max array size"))

(def-c-const DBUS_MAXIMUM_MESSAGE_LENGTH ; (DBUS_MAXIMUM_ARRAY_LENGTH * 2)
  (:documentation "The maximum total message size including header and body;
similar rationale to max array size."))
(def-c-const DBUS_MAXIMUM_MESSAGE_LENGTH_BITS ; 27
  (:documentation "Number of bits you need in an unsigned to store the max message size"))

(def-c-const DBUS_MAXIMUM_TYPE_RECURSION_DEPTH ; 32
  (:documentation "Depth of recursion in the type tree.
This is automatically limited to DBUS_MAXIMUM_SIGNATURE_LENGTH since
you could only have an array of array of array of ...
that fit in the max signature.  But that's probably a bit too large."))

;; Types of message

(def-c-const DBUS_MESSAGE_TYPE_INVALID ; 0
  (:documentation "This value is never a valid message type, see dbus_message_get_type()"))
(def-c-const DBUS_MESSAGE_TYPE_METHOD_CALL ; 1
  (:documentation "Message type of a method call message, see dbus_message_get_type()"))
(def-c-const DBUS_MESSAGE_TYPE_METHOD_RETURN ; 2
  (:documentation "Message type of a method return message, see dbus_message_get_type()"))
(def-c-const DBUS_MESSAGE_TYPE_ERROR ; 3
  (:documentation "Message type of an error reply message, see dbus_message_get_type()"))
(def-c-const DBUS_MESSAGE_TYPE_SIGNAL ; 4
  (:documentation "Message type of a signal message, see dbus_message_get_type()"))

;; Header flags

(def-c-const DBUS_HEADER_FLAG_NO_REPLY_EXPECTED ; 0x1
  (:documentation "If set, this flag means that the sender of a message
does not care about getting a reply, so the recipient need not send one.
See dbus_message_set_no_reply()."))
(def-c-const DBUS_HEADER_FLAG_NO_AUTO_START ; 0x2
  (:documentation "If set, this flag means that even if the message bus
knows how to start an owner for the destination bus name (see
dbus_message_set_destination()), it should not do so. If this flag is
not set, the bus may launch a program to process the message."))

;; Header fields

(def-c-const DBUS_HEADER_FIELD_INVALID ; 0
  (:documentation "Not equal to any valid header field code"))
(def-c-const DBUS_HEADER_FIELD_PATH ; 1
  (:documentation "Header field code for the path - the path is the
object emitting a signal or the object receiving a method call.
See dbus_message_set_path()."))
(def-c-const DBUS_HEADER_FIELD_INTERFACE ; 2
  (:documentation "Header field code for the interface containing a
member (method or signal).  See dbus_message_set_interface()."))
(def-c-const DBUS_HEADER_FIELD_MEMBER ; 3
  (:documentation "Header field code for a member (method or signal).
See dbus_message_set_member()."))
(def-c-const DBUS_HEADER_FIELD_ERROR_NAME ; 4
  (:documentation "Header field code for an error name (found in #DBUS_MESSAGE_TYPE_ERROR messages).
See dbus_message_set_error_name()."))
(def-c-const DBUS_HEADER_FIELD_REPLY_SERIAL ; 5
  (:documentation "Header field code for a reply serial, used to match a #DBUS_MESSAGE_TYPE_METHOD_RETURN message with the
message that it's a reply to. See dbus_message_set_reply_serial()."))
(def-c-const DBUS_HEADER_FIELD_DESTINATION ; 6
  (:documentation "Header field code for the destination bus name of a message. See dbus_message_set_destination()."))
(def-c-const DBUS_HEADER_FIELD_SENDER ; 7
  (:documentation "Header field code for the sender of a message; usually initialized by the message bus.
See dbus_message_set_sender()."))
(def-c-const DBUS_HEADER_FIELD_SIGNATURE ; 8
  (:documentation "Header field code for the type signature of a message."))

(def-c-const DBUS_HEADER_FIELD_LAST ; DBUS_HEADER_FIELD_SIGNATURE
  (:documentation "Value of the highest-numbered header field code,
can be used to determine the size of an array indexed by header field code.
Remember though that unknown codes must be ignored,
so check for that before indexing the array."))

(def-c-const DBUS_HEADER_SIGNATURE (:type c-string)
    ;; DBUS_TYPE_BYTE_AS_STRING
    ;; DBUS_TYPE_BYTE_AS_STRING
    ;; DBUS_TYPE_BYTE_AS_STRING
    ;; DBUS_TYPE_BYTE_AS_STRING
    ;; DBUS_TYPE_UINT32_AS_STRING
    ;; DBUS_TYPE_UINT32_AS_STRING
    ;; DBUS_TYPE_ARRAY_AS_STRING
    ;; DBUS_STRUCT_BEGIN_CHAR_AS_STRING
    ;; DBUS_TYPE_BYTE_AS_STRING
    ;; DBUS_TYPE_VARIANT_AS_STRING
    ;; DBUS_STRUCT_END_CHAR_AS_STRING
  (:documentation "Header format is defined as a signature:
byte                            byte order
byte                            message type ID
byte                            flags
byte                            protocol version
uint32                          body length
uint32                          serial
array of struct (byte,variant)  (field name, value)

The length of the header can be computed as the
fixed size of the initial data, plus the length of
the array at the end, plus padding to an 8-boundary."))

(def-c-const DBUS_MINIMUM_HEADER_SIZE ; 16
  (:documentation "The smallest header size that can occur.
\(It won't be valid due to missing required header fields.)
This is 4 bytes, two uint32, an array length.
This isn't any kind of resource limit, just the
necessary/logical outcome of the header signature."))

;; Errors
;; WARNING these get autoconverted to an enum in dbus-glib.h.
;; Thus, if you change the order it breaks the ABI. Keep them in order.
;; Also, don't change the formatting since that will break the sed script.

(def-c-const DBUS_ERROR_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.Failed"
  (:documentation "A generic error; \"something went wrong\" - see the error message for more."))
(def-c-const DBUS_ERROR_NO_MEMORY (:type c-string) ; "org.freedesktop.DBus.Error.NoMemory"
  (:documentation "There was not enough memory to complete an operation."))
(def-c-const DBUS_ERROR_SERVICE_UNKNOWN (:type c-string) ; "org.freedesktop.DBus.Error.ServiceUnknown"
  (:documentation "The bus doesn't know how to launch a service to supply the bus name you wanted."))
(def-c-const DBUS_ERROR_NAME_HAS_NO_OWNER (:type c-string) ; "org.freedesktop.DBus.Error.NameHasNoOwner"
  (:documentation "The bus name you referenced doesn't exist (i.e. no application owns it)."))
(def-c-const DBUS_ERROR_NO_REPLY (:type c-string) ; "org.freedesktop.DBus.Error.NoReply"
  (:documentation "No reply to a message expecting one, usually means a timeout occurred."))
(def-c-const DBUS_ERROR_IO_ERROR (:type c-string) ; "org.freedesktop.DBus.Error.IOError"
  (:documentation "Something went wrong reading or writing to a socket, for example."))
(def-c-const DBUS_ERROR_BAD_ADDRESS (:type c-string) ; "org.freedesktop.DBus.Error.BadAddress"
  (:documentation "A D-Bus bus address was malformed."))
(def-c-const DBUS_ERROR_NOT_SUPPORTED (:type c-string) ; "org.freedesktop.DBus.Error.NotSupported"
  (:documentation "Requested operation isn't supported (like ENOSYS on UNIX)."))
(def-c-const DBUS_ERROR_LIMITS_EXCEEDED (:type c-string) ; "org.freedesktop.DBus.Error.LimitsExceeded"
  (:documentation "Some limited resource is exhausted."))
(def-c-const DBUS_ERROR_ACCESS_DENIED (:type c-string) ; "org.freedesktop.DBus.Error.AccessDenied"
  (:documentation "Security restrictions don't allow doing what you're trying to do."))
(def-c-const DBUS_ERROR_AUTH_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.AuthFailed"
  (:documentation "Authentication didn't work."))
(def-c-const DBUS_ERROR_NO_SERVER (:type c-string) ; "org.freedesktop.DBus.Error.NoServer"
  (:documentation "Unable to connect to server (probably caused by ECONNREFUSED on a socket)."))
(def-c-const DBUS_ERROR_TIMEOUT (:type c-string) ; "org.freedesktop.DBus.Error.Timeout"
  (:documentation "Certain timeout errors, possibly ETIMEDOUT on a socket.
Note that #DBUS_ERROR_NO_REPLY is used for message reply timeouts.
@warning this is confusingly-named given that #DBUS_ERROR_TIMED_OUT also exists.
We can't fix it for compatibility reasons so just be careful."))
(def-c-const DBUS_ERROR_NO_NETWORK (:type c-string) ; "org.freedesktop.DBus.Error.NoNetwork"
  (:documentation "No network access (probably ENETUNREACH on a socket)."))
(def-c-const DBUS_ERROR_ADDRESS_IN_USE (:type c-string) ; "org.freedesktop.DBus.Error.AddressInUse"
  (:documentation "Can't bind a socket since its address is in use (i.e. EADDRINUSE)."))
(def-c-const DBUS_ERROR_DISCONNECTED (:type c-string) ; "org.freedesktop.DBus.Error.Disconnected"
  (:documentation "The connection is disconnected and you're trying to use it."))
(def-c-const DBUS_ERROR_INVALID_ARGS (:type c-string) ; "org.freedesktop.DBus.Error.InvalidArgs"
  (:documentation "Invalid arguments passed to a method call."))
(def-c-const DBUS_ERROR_FILE_NOT_FOUND (:type c-string) ; "org.freedesktop.DBus.Error.FileNotFound"
  (:documentation "Missing file."))
(def-c-const DBUS_ERROR_FILE_EXISTS (:type c-string) ; "org.freedesktop.DBus.Error.FileExists"
  (:documentation "Existing file and the operation you're using does not silently overwrite."))
(def-c-const DBUS_ERROR_UNKNOWN_METHOD (:type c-string) ; "org.freedesktop.DBus.Error.UnknownMethod"
  (:documentation "Method name you invoked isn't known by the object you invoked it on."))
(def-c-const DBUS_ERROR_TIMED_OUT (:type c-string) ; "org.freedesktop.DBus.Error.TimedOut"
  (:documentation "Certain timeout errors, e.g. while starting a service.
@warning this is confusingly-named given that #DBUS_ERROR_TIMEOUT also exists.
We can't fix it for compatibility reasons so just be careful."))
(def-c-const DBUS_ERROR_MATCH_RULE_NOT_FOUND (:type c-string) ; "org.freedesktop.DBus.Error.MatchRuleNotFound"
  (:documentation "Tried to remove or modify a match rule that didn't exist."))
(def-c-const DBUS_ERROR_MATCH_RULE_INVALID (:type c-string) ; "org.freedesktop.DBus.Error.MatchRuleInvalid"
  (:documentation "The match rule isn't syntactically valid."))
(def-c-const DBUS_ERROR_SPAWN_EXEC_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ExecFailed"
  (:documentation "While starting a new process, the exec() call failed."))
(def-c-const DBUS_ERROR_SPAWN_FORK_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ForkFailed"
  (:documentation "While starting a new process, the fork() call failed."))
(def-c-const DBUS_ERROR_SPAWN_CHILD_EXITED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ChildExited"
  (:documentation "While starting a new process, the child exited with a status code."))
(def-c-const DBUS_ERROR_SPAWN_CHILD_SIGNALED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ChildSignaled"
  (:documentation "While starting a new process, the child exited on a signal."))
(def-c-const DBUS_ERROR_SPAWN_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.Failed"
  (:documentation "While starting a new process, something went wrong."))
(def-c-const DBUS_ERROR_SPAWN_SETUP_FAILED (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.FailedToSetup"
  (:documentation "We failed to setup the environment correctly."))
(def-c-const DBUS_ERROR_SPAWN_CONFIG_INVALID (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ConfigInvalid"
  (:documentation "We failed to setup the config parser correctly."))
(def-c-const DBUS_ERROR_SPAWN_SERVICE_INVALID (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ServiceNotValid"
  (:documentation "Bus name was not valid."))
(def-c-const DBUS_ERROR_SPAWN_SERVICE_NOT_FOUND (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.ServiceNotFound"
  (:documentation "Service file not found in system-services directory."))
(def-c-const DBUS_ERROR_SPAWN_PERMISSIONS_INVALID (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.PermissionsInvalid"
  (:documentation "Permissions are incorrect on the setuid helper."))
(def-c-const DBUS_ERROR_SPAWN_FILE_INVALID (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.FileInvalid"
  (:documentation "Service file invalid (Name, User or Exec missing)."))
(def-c-const DBUS_ERROR_SPAWN_NO_MEMORY (:type c-string) ; "org.freedesktop.DBus.Error.Spawn.NoMemory"
  (:documentation "Tried to get a UNIX process ID and it wasn't available."))
(def-c-const DBUS_ERROR_UNIX_PROCESS_ID_UNKNOWN (:type c-string) ; "org.freedesktop.DBus.Error.UnixProcessIdUnknown"
  (:documentation "Tried to get a UNIX process ID and it wasn't available."))
(def-c-const DBUS_ERROR_INVALID_SIGNATURE (:type c-string) ; "org.freedesktop.DBus.Error.InvalidSignature"
  (:documentation "A type signature is not valid."))
(def-c-const DBUS_ERROR_INVALID_FILE_CONTENT (:type c-string) ; "org.freedesktop.DBus.Error.InvalidFileContent"
  (:documentation "A file contains invalid syntax or is otherwise broken."))
(def-c-const DBUS_ERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN (:type c-string) ; "org.freedesktop.DBus.Error.SELinuxSecurityContextUnknown"
  (:documentation "Asked for SELinux security context and it wasn't available."))
(def-c-const DBUS_ERROR_ADT_AUDIT_DATA_UNKNOWN (:type c-string) ; "org.freedesktop.DBus.Error.AdtAuditDataUnknown"
  (:documentation "Asked for ADT audit data and it wasn't available."))
(def-c-const DBUS_ERROR_OBJECT_PATH_IN_USE (:type c-string) ; "org.freedesktop.DBus.Error.ObjectPathInUse"
  (:documentation "There's already an object with the requested object path."))

;; XML introspection format

(def-c-const DBUS_INTROSPECT_1_0_XML_NAMESPACE (:type c-string) ; "http://www.freedesktop.org/standards/dbus"
  (:documentation "XML namespace of the introspection format version 1.0"))
(def-c-const DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER (:type c-string) ; "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
  (:documentation "XML public identifier of the introspection format version 1.0"))
(def-c-const DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER (:type c-string) ; "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd"
  (:documentation "XML system identifier of the introspection format version 1.0"))
(def-c-const DBUS_INTROSPECT_1_0_XML_DOCTYPE_DECL_NODE (:type c-string) ; "<!DOCTYPE node PUBLIC \""DBUS_INTROSPECT_1_0_XML_PUBLIC_IDENTIFIER"\"\n\""DBUS_INTROSPECT_1_0_XML_SYSTEM_IDENTIFIER"\">\n"
  (:documentation "XML document type declaration of the introspection format version 1.0"))

;; === dbus-server.h

;; typedef struct DBusServer DBusServer;
(def-c-type DBusServer* c-pointer)

;; Called when a new connection to the server is available.
;; Must reference and save the new connection, or close the new connection.
;; Set with dbus_server_set_new_connection_function().
;; typedef void (* DBusNewConnectionFunction) (DBusServer *server, DBusConnection *new_connection, void *data);
(def-c-type DBusNewConnectionFunction
  (c-function (:return-type nil)
              (:arguments (server DBusServer*) (new_connection DBusConnection*)
                          (data c-pointer))))
(def-c-type DBusNewConnectionFunction* (c-pointer DBusNewConnectionFunction))


;; DBusServer* dbus_server_listen (const char *address, DBusError *error);
(def-call-out dbus_server_listen (:return-type DBusServer*)
  (:arguments (address c-string) (error (c-pointer DBusError))))

;; DBusServer* dbus_server_ref (DBusServer *server);
(def-call-out dbus_server_ref (:return-type DBusServer*)
  (:arguments (server DBusServer*)))

;; void dbus_server_unref (DBusServer *server);
(def-call-out dbus_server_unref (:return-type nil)
  (:arguments (server DBusServer*)))

;; void dbus_server_disconnect (DBusServer *server);
(def-call-out dbus_server_disconnect (:return-type nil)
  (:arguments (server DBusServer*)))

;; dbus_bool_t dbus_server_get_is_connected (DBusServer *server);
(def-call-out dbus_server_get_is_connected (:return-type dbus_bool_t)
  (:arguments (server DBusServer*)))

;; char* dbus_server_get_address (DBusServer *server);
(def-call-out dbus_server_get_address (:return-type c-string)
  (:arguments (server DBusServer*)))

;; char* dbus_server_get_id (DBusServer *server);
(def-call-out dbus_server_get_id (:return-type c-string)
  (:arguments (server DBusServer*)))

;; void dbus_server_set_new_connection_function (DBusServer *server, DBusNewConnectionFunction function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_server_set_new_connection_function (:return-type nil)
  (:arguments (server DBusServer*) (function DBusNewConnectionFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_server_set_watch_functions (DBusServer *server, DBusAddWatchFunction add_function, DBusRemoveWatchFunction remove_function, DBusWatchToggledFunction toggled_function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_server_set_watch_functions (:return-type dbus_bool_t)
  (:arguments (server DBusServer*) (add_function DBusAddWatchFunction)
              (remove_function DBusRemoveWatchFunction)
              (toggled_function DBusWatchToggledFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_server_set_timeout_functions (DBusServer *server, DBusAddTimeoutFunction add_function, DBusRemoveTimeoutFunction remove_function, DBusTimeoutToggledFunction toggled_function, void *data, DBusFreeFunction free_data_function);
(def-call-out dbus_server_set_timeout_functions (:return-type dbus_bool_t)
  (:arguments (server DBusServer*) (add_function DBusAddTimeoutFunction)
              (remove_function DBusRemoveTimeoutFunction)
              (toggled_function DBusTimeoutToggledFunction)
              (data c-pointer) (free_data_function DBusFreeFunction)))

;; dbus_bool_t dbus_server_set_auth_mechanisms (DBusServer *server, const char **mechanisms);
(def-call-out dbus_server_set_auth_mechanisms (:return-type dbus_bool_t)
  (:arguments (server DBusServer*) (*mechanisms c-string)))


;; dbus_bool_t dbus_server_allocate_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_server_allocate_data_slot (:return-type dbus_bool_t)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; void dbus_server_free_data_slot (dbus_int32_t *slot_p);
(def-call-out dbus_server_free_data_slot (:return-type nil)
  (:arguments (slot_p (c-pointer dbus_int32_t))))

;; dbus_bool_t dbus_server_set_data (DBusServer *server, int slot, void *data, DBusFreeFunction free_data_func);
(def-call-out dbus_server_set_data (:return-type dbus_bool_t)
  (:arguments (server DBusServer*) (slot int) (data c-pointer)
              (free_data_func DBusFreeFunction)))

;; void* dbus_server_get_data (DBusServer *server, int slot);
(def-call-out dbus_server_get_data (:return-type c-pointer)
  (:arguments (server DBusServer*) (slot int)))

;; === dbus-signature.h

;; contains no public fields
;; typedef struct DBusSignatureIter DBusSignatureIter
(def-c-type DBusSignatureIter* c-pointer)

;; void dbus_signature_iter_init (DBusSignatureIter *iter, const char *signature);
(def-call-out dbus_signature_iter_init (:return-type nil)
  (:arguments (iter DBusSignatureIter*) (signature c-string)))


;; int dbus_signature_iter_get_current_type (const DBusSignatureIter *iter);
(def-call-out dbus_signature_iter_get_current_type (:return-type int)
  (:arguments (iter DBusSignatureIter*)))


;; char * dbus_signature_iter_get_signature (const DBusSignatureIter *iter);
(def-call-out dbus_signature_iter_get_signature (:return-type c-string)
  (:arguments (iter DBusSignatureIter*)))


;; int dbus_signature_iter_get_element_type (const DBusSignatureIter *iter);
(def-call-out dbus_signature_iter_get_element_type (:return-type int)
  (:arguments (iter DBusSignatureIter*)))


;; dbus_bool_t dbus_signature_iter_next (DBusSignatureIter *iter);
(def-call-out dbus_signature_iter_next (:return-type dbus_bool_t)
  (:arguments (iter DBusSignatureIter*)))


;; void dbus_signature_iter_recurse (const DBusSignatureIter *iter, DBusSignatureIter *subiter);
(def-call-out dbus_signature_iter_recurse (:return-type nil)
  (:arguments (iter DBusSignatureIter*) (subiter DBusSignatureIter*)))


;; dbus_bool_t dbus_signature_validate (const char *signature, DBusError *error);
(def-call-out dbus_signature_validate (:return-type dbus_bool_t)
  (:arguments (signature c-string) (error (c-pointer DBusError))))


;; dbus_bool_t dbus_signature_validate_single (const char *signature, DBusError *error);
(def-call-out dbus_signature_validate_single (:return-type dbus_bool_t)
  (:arguments (signature c-string) (error (c-pointer DBusError))))


;; dbus_bool_t dbus_type_is_basic (int typecode);
(def-call-out dbus_type_is_basic (:return-type dbus_bool_t)
  (:arguments (typecode int)))

;; dbus_bool_t dbus_type_is_container (int typecode);
(def-call-out dbus_type_is_container (:return-type dbus_bool_t)
  (:arguments (typecode int)))

;; dbus_bool_t dbus_type_is_fixed (int typecode);
(def-call-out dbus_type_is_fixed (:return-type dbus_bool_t)
  (:arguments (typecode int)))


;; === dbus-threads.h

;; An opaque mutex type provided by the #DBusThreadFunctions
;; implementation installed by dbus_threads_init().
;; typedef struct DBusMutex DBusMutex;
(def-c-type DBusMutex* c-pointer)

;; An opaque condition variable type provided by the
;; #DBusThreadFunctions implementation installed by dbus_threads_init().
;; typedef struct DBusCondVar DBusCondVar;
(def-c-type DBusCondVar* c-pointer)

;; Deprecated, provide DBusRecursiveMutexNewFunction instead.
;; typedef DBusMutex* (* DBusMutexNewFunction) (void);
(def-c-type DBusMutexNewFunction
  (c-function (:return-type DBusMutex*)
              (:arguments)))
(def-c-type DBusMutexNewFunction* (c-pointer DBusMutexNewFunction))

;; Deprecated, provide DBusRecursiveMutexFreeFunction instead.
;; typedef void (* DBusMutexFreeFunction) (DBusMutex *mutex);
(def-c-type DBusMutexFreeFunction
  (c-function (:return-type nil)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusMutexFreeFunction* (c-pointer DBusMutexFreeFunction))

;; Deprecated, provide DBusRecursiveMutexLockFunction instead.
;; Return value is lock success, but gets ignored in practice.
;; typedef dbus_bool_t (* DBusMutexLockFunction) (DBusMutex *mutex);
(def-c-type DBusMutexLockFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusMutexLockFunction* (c-pointer DBusMutexLockFunction))

;; Deprecated, provide DBusRecursiveMutexUnlockFunction instead.
;; Return value is unlock success, but gets ignored in practice.
;; typedef dbus_bool_t (* DBusMutexUnlockFunction) (DBusMutex *mutex);
(def-c-type DBusMutexUnlockFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusMutexUnlockFunction* (c-pointer DBusMutexUnlockFunction))


;; Creates a new recursively-lockable mutex, or returns #NULL if not
;; enough memory.  Can only fail due to lack of memory.  Found in
;; #DBusThreadFunctions. Do not just use PTHREAD_MUTEX_RECURSIVE for
;; this, because it does not save/restore the recursion count when
;; waiting on a condition. libdbus requires the Java-style behavior
;; where the mutex is fully unlocked to wait on a condition.
;; typedef DBusMutex* (* DBusRecursiveMutexNewFunction) (void);
(def-c-type DBusRecursiveMutexNewFunction
  (c-function (:return-type DBusMutex*)
              (:arguments)))
(def-c-type DBusRecursiveMutexNewFunction* (c-pointer DBusRecursiveMutexNewFunction))

;; Frees a recursively-lockable mutex.  Found in #DBusThreadFunctions.
;; typedef void (* DBusRecursiveMutexFreeFunction) (DBusMutex *mutex);
(def-c-type DBusRecursiveMutexFreeFunction
  (c-function (:return-type nil)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusRecursiveMutexFreeFunction* (c-pointer DBusRecursiveMutexFreeFunction))

;; Locks a recursively-lockable mutex.  Found in #DBusThreadFunctions.
;; Can only fail due to lack of memory.
;; typedef void (* DBusRecursiveMutexLockFunction) (DBusMutex *mutex);
(def-c-type DBusRecursiveMutexLockFunction
  (c-function (:return-type nil)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusRecursiveMutexLockFunction* (c-pointer DBusRecursiveMutexLockFunction))

;; Unlocks a recursively-lockable mutex.  Found in #DBusThreadFunctions.
;; Can only fail due to lack of memory.
;; typedef void (* DBusRecursiveMutexUnlockFunction) (DBusMutex *mutex);
(def-c-type DBusRecursiveMutexUnlockFunction
  (c-function (:return-type nil)
              (:arguments (mutex DBusMutex*))))
(def-c-type DBusRecursiveMutexUnlockFunction* (c-pointer DBusRecursiveMutexUnlockFunction))


;; Creates a new condition variable.  Found in #DBusThreadFunctions.
;; Can only fail (returning #NULL) due to lack of memory.
;; typedef DBusCondVar* (* DBusCondVarNewFunction) (void);
(def-c-type DBusCondVarNewFunction
  (c-function (:return-type DBusCondVar*)
              (:arguments)))
(def-c-type DBusCondVarNewFunction* (c-pointer DBusCondVarNewFunction))

;; Frees a condition variable.  Found in #DBusThreadFunctions.
;; typedef void (* DBusCondVarFreeFunction) (DBusCondVar *cond);
(def-c-type DBusCondVarFreeFunction
  (c-function (:return-type nil)
              (:arguments (cond DBusCondVar*))))
(def-c-type DBusCondVarFreeFunction* (c-pointer DBusCondVarFreeFunction))


;; Waits on a condition variable.  Found in
;; #DBusThreadFunctions. Must work with either a recursive or
;; nonrecursive mutex, whichever the thread implementation
;; provides. Note that PTHREAD_MUTEX_RECURSIVE does not work with
;; condition variables (does not save/restore the recursion count) so
;; don't try using simply pthread_cond_wait() and a
;; PTHREAD_MUTEX_RECURSIVE to implement this, it won't work right.
;; Has no error conditions. Must succeed if it returns.
;; typedef void (* DBusCondVarWaitFunction) (DBusCondVar *cond, DBusMutex *mutex);
(def-c-type DBusCondVarWaitFunction
  (c-function (:return-type nil)
              (:arguments (cond DBusCondVar*) (mutex DBusMutex*))))
(def-c-type DBusCondVarWaitFunction* (c-pointer DBusCondVarWaitFunction))


;; Waits on a condition variable with a timeout.  Found in
;; #DBusThreadFunctions. Returns #TRUE if the wait did not
;; time out, and #FALSE if it did.
;; Has no error conditions. Must succeed if it returns.
;; typedef dbus_bool_t (* DBusCondVarWaitTimeoutFunction) (DBusCondVar *cond, DBusMutex *mutex, int timeout_milliseconds);
(def-c-type DBusCondVarWaitTimeoutFunction
  (c-function (:return-type dbus_bool_t)
              (:arguments (cond DBusCondVar*) (mutex DBusMutex*)
                          (timeout_milliseconds int))))
(def-c-type DBusCondVarWaitTimeoutFunction* (c-pointer DBusCondVarWaitTimeoutFunction))

;; Wakes one waiting thread on a condition variable.
;; Found in #DBusThreadFunctions.
;; Has no error conditions. Must succeed if it returns.
;; typedef void (* DBusCondVarWakeOneFunction) (DBusCondVar *cond);
(def-c-type DBusCondVarWakeOneFunction
  (c-function (:return-type nil)
              (:arguments (cond DBusCondVar*))))
(def-c-type DBusCondVarWakeOneFunction* (c-pointer DBusCondVarWakeOneFunction))


;; Wakes all waiting threads on a condition variable.
;; Found in #DBusThreadFunctions.
;; Has no error conditions. Must succeed if it returns.
;; typedef void (* DBusCondVarWakeAllFunction) (DBusCondVar *cond);
(def-c-type DBusCondVarWakeAllFunction
  (c-function (:return-type nil)
              (:arguments (cond DBusCondVar*))))
(def-c-type DBusCondVarWakeAllFunction* (c-pointer DBusCondVarWakeAllFunction))



;; Flags indicating which functions are present in #DBusThreadFunctions.
;; Used to allow the library to detect older callers of dbus_threads_init()
;; if new possible functions are added to #DBusThreadFunctions.
(def-c-enum DBusThreadFunctionsMask
  (DBUS_THREAD_FUNCTIONS_MUTEX_NEW_MASK (ash 1 0))
  (DBUS_THREAD_FUNCTIONS_MUTEX_FREE_MASK (ash 1 1))
  (DBUS_THREAD_FUNCTIONS_MUTEX_LOCK_MASK (ash 1 2))
  (DBUS_THREAD_FUNCTIONS_MUTEX_UNLOCK_MASK (ash 1 3))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_NEW_MASK (ash 1 4))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_FREE_MASK (ash 1 5))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_WAIT_MASK (ash 1 6))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_WAIT_TIMEOUT_MASK (ash 1 7))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_WAKE_ONE_MASK (ash 1 8))
  (DBUS_THREAD_FUNCTIONS_CONDVAR_WAKE_ALL_MASK (ash 1 9))
  (DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_NEW_MASK (ash 1 10))
  (DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_FREE_MASK (ash 1 11))
  (DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_LOCK_MASK (ash 1 12))
  (DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_UNLOCK_MASK (ash 1 13))
  (DBUS_THREAD_FUNCTIONS_ALL_MASK (1- (ash 1 14))))


;; Functions that must be implemented to make the D-Bus library
;; thread-aware. The recursive mutex functions should be specified
;; rather than the old, deprecated nonrecursive ones.

;; The condition variable functions have to work with recursive
;; mutexes if you provide those, or with nonrecursive mutexes if you
;; provide those.

;; If implementing threads using pthreads, be aware that
;; PTHREAD_MUTEX_RECURSIVE is broken in combination with condition
;; variables. libdbus relies on the Java-style behavior that when
;; waiting on a condition, the recursion count is saved and restored,
;; and the mutex is completely unlocked, not just decremented one
;; level of recursion.

;; Thus with pthreads you probably have to roll your own emulated
;; recursive mutexes, you can't use PTHREAD_MUTEX_RECURSIVE. This is
;; what dbus_threads_init_default() does on platforms that use
;; pthreads.
(def-c-struct DBusThreadFunctions
  (mask uint) ; Mask indicating which functions are present.
  (mutex_new DBusMutexNewFunction) ; Function to create a mutex; optional and deprecated.
  (mutex_free DBusMutexFreeFunction) ; Function to free a mutex; optional and deprecated.
  (mutex_lock DBusMutexLockFunction) ; Function to lock a mutex; optional and deprecated.
  (mutex_unlock DBusMutexUnlockFunction) ; Function to unlock a mutex; optional and deprecated.

  (condvar_new DBusCondVarNewFunction) ; Function to create a condition variable
  (condvar_free DBusCondVarFreeFunction) ; Function to free a condition variable
  (condvar_wait DBusCondVarWaitFunction) ; Function to wait on a condition
  (condvar_wait_timeout DBusCondVarWaitTimeoutFunction) ; Function to wait on a condition with a timeout
  (condvar_wake_one DBusCondVarWakeOneFunction) ; Function to wake one thread waiting on the condition
  (condvar_wake_all DBusCondVarWakeAllFunction) ; Function to wake all threads waiting on the condition

  (recursive_mutex_new DBusRecursiveMutexNewFunction) ; Function to create a recursive mutex
  (recursive_mutex_free DBusRecursiveMutexFreeFunction) ; Function to free a recursive mutex
  (recursive_mutex_lock DBusRecursiveMutexLockFunction) ; Function to lock a recursive mutex
  (recursive_mutex_unlock DBusRecursiveMutexUnlockFunction) ; Function to unlock a recursive mutex
  (padding1 c-pointer) ; Reserved for future expansion
  (padding2 c-pointer) ; Reserved for future expansion
  (padding3 c-pointer) ; Reserved for future expansion
  (padding4 c-pointer) ; Reserved for future expansion
  )

;; dbus_bool_t dbus_threads_init (const DBusThreadFunctions *functions);
(def-call-out dbus_threads_init (:return-type dbus_bool_t)
  (:arguments (functions (c-pointer DBusThreadFunctions))))

;; dbus_bool_t dbus_threads_init_default (void);
(def-call-out dbus_threads_init_default (:return-type dbus_bool_t)
  (:arguments))

;;; ===

(pushnew :dbus *features*)
(provide "dbus")
(pushnew "DBUS" custom:*system-package-list* :test #'string=)
