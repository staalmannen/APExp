;;; CLISP gtk2 & libglade interface
;;; based on http://dgym.homeunix.net/clisp-gtk2/

;;; original license:
;; Copyright (c) 2004 James Bailey (dgym.REMOVE_THIS.bailey@gmail.com).
;;
;; Permission is hereby granted, free of charge, to any person obtaining a
;; copy of this software and associated documentation files (the "Software"), to
;; deal in the Software without restriction, including without limitation the
;; rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
;; sell copies of the Software, and to permit persons to whom the Software is
;; furnished to do so, subject to the following conditions:
;;
;; The above copyright notice and this permission notice shall be
;; included in all copies or substantial portions of the Software.
;;
;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;; SOFTWARE.

;;; current license:
;; Copyright (C) 2006-2009 Sam Steingold (sds@gnu.org)
;;
;; This file is part of GNU CLISP.
;;
;; GNU CLISP is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.
;;
;; GNU CLISP is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with GNU CLISP; see the file COPYING.  If not, write to
;; the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
;; Boston, MA 02110-1301, USA.

(defpackage "GTK"
  (:use "CL" "FFI" "EXT") (:modern t)
  (:shadowing-import-from "EXPORTING"
    #:def-c-struct #:def-call-out #:def-c-type #:defun))

(in-package "GTK")
(setf (documentation (find-package "GTK") 'sys::impnotes) "GTK")
(default-foreign-language :stdc)

;;;
;;; === GTK ===
;;;

(def-c-type GtkWidget* c-pointer)

;;;
;;; callback handling
;;;

;; this is complicated as each callback can have a different number of
;; arguments and it is the last that is most interesting (a gpointer to
;; some data we manage)
;; in order to call lisp functions (and thus support closures) rather
;; than being limited to a primitive data type, the data parameter is
;; used by this module, as an index into a global vector of callback
;; functions.  so, a call is made to gtk_connect, with an object, the
;; event name and a callback function the callback is put in the global
;; vector, and its index is given as the data argument to
;; g_signal_connect_data. This module's callback function performs the
;; lookup (it gets the index as its last parameter), and calls it.
;; this could be handled directly by the ffi (passing in a lisp function
;; as the callback would work) but this causes memory leaks.

;;;
;;; make the connect functions, taking from 0-4 arguments as well as the object
;;;

(defmacro make-connect-funcs (param-count)
  (let* ((c-name (intern (format nil "g_signal_connect_data-~a" param-count)))
         (cb-name (intern (format nil "gtk-callback-~a" param-count)))
         (args (loop :for i :from 1 :upto param-count
                 :collect (intern (format nil "ARG-~a" i))))
         (arg-types (mapcar (lambda (x) `(,x c-pointer)) args)))
    `(progn
       (def-call-out ,c-name (:name "g_signal_connect_data")
         (:return-type int)
         (:arguments (widget GtkWidget*)
                     (name c-string)
                     (callback
                      (c-function (:arguments (object c-pointer)
                                              ,@arg-types
                                              (data int))
                                  (:return-type int)))
                     (data int)
                     (clean-up
                      (c-function (:arguments (data int))
                                  (:return-type nil)))
                     (b int)))
       (def-call-in ,cb-name (:return-type ffi:int)
         (:arguments (object c-pointer)
                     ,@arg-types
                     (data ffi:c-string)))
       (defun ,cb-name (object ,@args data)
         (funcall (aref *callback-funcs* data) object ,@args))
       (setf (aref *connect-funcs* ,param-count) (cons #',c-name #',cb-name)))))

(defvar *connect-funcs* (make-array 5))
(defvar *callback-funcs* (make-array 0 :adjustable t :fill-pointer 0))
(make-connect-funcs 0)
(make-connect-funcs 1)
(make-connect-funcs 2)
(make-connect-funcs 3)
(make-connect-funcs 4)

;;;
;;; our cleanup function just has to discard the entry in *callback-funcs*
;;;

(def-call-in gtk-cleanup (:arguments (data int)) (:return-type nil))

(defun gtk-cleanup (data)
  (format t "~S(~D): discarded ~S~%" 'gtk-cleanup data
          (aref *callback-funcs* data))
  (setf (aref *callback-funcs* data) nil)
  nil)

;; this must come AFTER all callbacks because they use value1
;; undefine some clisp.h definitions used by gtk.h
(c-lines "~{#undef value~d~%~}" '(1 2 3 4 5))

;; w32api/basetyps.h defines interface to struct
;; which breaks glade declarations like
;; void glade_interface_destroy (GladeInterface *interface);
(c-lines "#undef interface~%")

(c-lines "#include <gtk/gtk.h>~%")

;;;
;;; These struct definitions allow us to get the itype from an object
;;;

(def-c-type GType ulong)
(def-c-struct GTypeClass (g_type GType))
(def-c-struct GTypeInstance (g_class (c-ptr GTypeClass)))
(def-c-struct GSignalQuery
  (signal_id int)
  (signal_name c-string)
  (itype int)
  (signal_flags int)
  (return_type int)
  (n_params int)
  (param_types c-pointer))

(def-call-out g_signal_handler_disconnect (:return-type nil)
  (:arguments (obj GtkWidget*) (id int)))
(def-call-out g_signal_lookup (:return-type int)
  (:arguments (name c-string) (itype int)))
(def-call-out g_signal_query (:return-type nil)
  (:arguments (id int) (query c-pointer)))
(def-call-out g_type_from_name (:return-type int) (:arguments (name c-string)))

(defun get_type_from_instance (widget)
  "Returns the type from an instance instance->g_class->g_type"
  (with-c-var (_widget 'c-pointer widget)
    (slot (deref (slot (deref (cast _widget '(c-ptr GTypeInstance)))
                       'g_class))
          'g_type)))

(defun gtk_connect (widget signal func)
  "The exported function, gtk_connect, taking a gobject, a
signal name (e.g `delete_event') and a callback function.
The callback function will be passed the gobject, and any other
signal specific parameters, but not a data parameter."
  (let* ((n_params
          (with-c-var (query 'GSignalQuery)
            (g_signal_query (g_signal_lookup signal
                                             (get_type_from_instance widget))
                            (c-var-address query))
            (slot query 'n_params)))
         (funcs (aref *connect-funcs* n_params))
         (idx (or (position nil *callback-funcs*)
                  (vector-push-extend func *callback-funcs*))))
    (funcall (car funcs)
             widget
             signal
             (cdr funcs)
             idx
             #'gtk-cleanup
             0)))


;;;
;;; the actual imports
;;;

;; rather than coding these in by hand, they are read from gtk-server.cfg
;; this file is part of the (excellent) http://www.gtk-server.org project,
;; and defines lots of gtk functions in a simple-enough-to-parse form.
;;
;; the scanning is done in a macro, so it is performed at compile time.
;; there is no need to ship gtk-server.cfg with your project.

(defmacro read-gtk-server-cfg (filename)
  (labels ((convert-type (typ)
             (let ((sym (read-from-string typ)))
               (case sym
                 (NONE 'nil)
                 (LONG 'long)
                 (BOOL 'boolean)
                 (STRING 'c-string)
                 (FLOAT 'single-float)
                 (DOUBLE 'double-float)
                 (NULL 'c-pointer)
                 (WIDGET 'GtkWidget*)
                 (otherwise sym))))
           (proc-line (string start)
             (let* ((parts (loop :for i = start :then (1+ j)
                             :as j = (position #\, string :start i)
                             :collect (string-trim " " (subseq string i j))
                             :while j))
                    ;; parts are: API name, callback signal type, return value,
                    ;;   number of arguments, arg1, arg2...
                    (name (intern (pop parts)))
                    (callback-sig-type (pop parts))
                    (ret-type (pop parts))
                    (num-arg (parse-integer (pop parts))))
               (declare (ignore callback-sig-type))
               (unless (= num-arg (length parts))
                 (warn "~S: argument count ~D does not match argument list ~S"
                       name num-arg parts))
               `(def-call-out ,name (:return-type ,(convert-type ret-type))
                  (:arguments ,@(loop :for arg :in parts
                                  :collect `(arg ,(convert-type arg))))))))
    `(progn
       ,@(with-open-file (cfg (eval filename))
            (format t "~&;; Reading ~:D byte~:P from ~A~%"
                    (file-length cfg) (truename cfg))
            (loop :with forms = nil
              :finally (format t "~&;; Defined ~:D function~:P~%"
                               (length forms))
              :finally (return (nreverse forms))
              :for line = (read-line cfg nil)
              :while line
              :do
              (setq line (string-trim #.(coerce '(#\space #\tab) 'string) line))
              ;; check that it starts with "FUNCTION_NAME = "
              (when (and (> (length line) #1=#.(length #2="FUNCTION_NAME = "))
                         (string= line #2# :end1 #1#))
                (push (proc-line line #1#) forms)))))))

(read-gtk-server-cfg (merge-pathnames "gtk-server.cfg" *compile-file-pathname*))

(def-c-struct GtkTreeIter
  (stamp int)
  (user_data c-pointer)
  (user_data2 c-pointer)
  (user_data3 c-pointer))

(def-c-struct GValue
  (g_type int)
  (unknown1 double-float)
  (unknown2 double-float)
  (unknown3 double-float)
  (unknown4 double-float))

(def-call-out g_type_fundamental (:return-type int) (:arguments (val int)))
(def-call-out g_value_init (:return-type nil)
  (:arguments (val c-pointer) (gtype int)))
(def-call-out g_value_set_string (:return-type nil)
  (:arguments (val c-pointer) (str c-string)))
(def-call-out g_object_set_data (:return-type nil)
  (:arguments (obj c-pointer) (key c-string) (data c-pointer)))
(def-call-out g_object_get_data (:return-type c-pointer)
  (:arguments (obj c-pointer) (key c-string)))

(def-call-out gtk_tree_view_set_model (:return-type nil)
  (:arguments (widget GtkWidget*) (model c-pointer)))

(def-call-out gtk_tree_view_column_set_title (:return-type nil)
  (:arguments (view GtkWidget*) (title c-string)))
(def-call-out gtk_tree_view_column_set_attributes (:return-type nil)
  (:arguments (column c-pointer) (renderer c-pointer) (name c-string)
              (value int) (terminator nil)))
(def-call-out gtk_tree_view_column_add_attribute (:return-type nil)
  (:arguments (column c-pointer) (renderer c-pointer) (name c-string)
              (value int)))

;;;
;; memory leak test
;;;

#+nil
(defun ml-test ()
  (gtk_init 0 0)
  (let ((w (gtk_window_new 0)))
    (gtk_widget_show_all w)
    (loop :for id = (gtk_connect w "delete_event"
                                 (lambda (&rest args)
                                   (declare (ignore args))
                                   (print "destroyed") (ext:quit)))
      :do (g_signal_handler_disconnect w id)
      (ext:gc)
      (print (room))
      (sleep 0.1))
    (gtk_main)))

;;;
;;; === GLADE ===
;;;

(c-lines "#include <glade/glade-xml.h>~%")

(def-c-type GladeXML* c-pointer)
(def-c-type GCallback
    (c-pointer (c-function (:return-type nil) (:arguments))))
(def-c-type GObject* c-pointer)

(def-call-out glade_xml_new (:return-type GladeXML*)
  (:arguments (fname c-string)
              (root c-string)
              (domain c-string)))
(def-call-out glade_xml_new_from_buffer (:return-type GladeXML*)
  (:arguments (buffer c-string)
              (size int)        ; pass (length buffer)
              (root c-string)
              (domain c-string)))
(def-call-out glade_xml_construct (:return-type boolean)
  (:arguments (self GladeXML*)
              (fname c-string)
              (root c-string)
              (domain c-string)))
(def-call-out glade_xml_signal_connect (:return-type nil)
  (:arguments (self GladeXML*)
              (handlername c-string)
              (func GCallback)))
(def-call-out glade_xml_signal_connect_data (:return-type nil)
  (:arguments (self GladeXML*)
              (handlername c-string)
              (func GCallback)
              (user_data c-pointer)))
(def-call-out glade_xml_signal_autoconnect (:return-type nil)
  (:arguments (self GladeXML*)))
(def-call-out glade_xml_get_widget (:return-type GtkWidget*)
  (:arguments (self GladeXML*)
              (name c-string)))
(def-c-type GList* c-pointer)
(def-call-out glade_xml_get_widget_prefix (:return-type GList*)
  (:arguments (self GladeXML*)
              (name c-string)))
(def-call-out glade_get_widget_name (:return-type c-string)
  (:arguments  (widget GtkWidget*)))
(def-call-out glade_get_widget_tree (:return-type GladeXML*)
  (:arguments (widget GtkWidget*)))
(def-c-type GladeXMLConnectFunc
    (c-function (:return-type nil)
                (:arguments (handler_name c-string)
                            (object GObject*)
                            (signal_name c-string)
                            (signal_data c-string)
                            (connect_object GObject*)
                            (after boolean)
                            (user_data c-pointer))))
(def-call-out glade_xml_signal_connect_full (:return-type nil)
  (:arguments (self GladeXML*)
              (handler_name c-string)
              (func GladeXMLConnectFunc)
              (user_data c-pointer)))
(def-call-out glade_xml_signal_autoconnect_full (:return-type nil)
  (:arguments (self GladeXML*)
              (func GladeXMLConnectFunc)
              (user_data c-pointer)))
(def-c-type GladeXMLCustomWidgetHandler
    (c-function (:return-type GtkWidget*)
                (:arguments (xml GladeXML*)
                            (func_name c-string)
                            (name c-string)
                            (string1 c-string)
                            (string2 c-string)
                            (int1 int)
                            (int2 int)
                            (user_data c-pointer))))
(def-call-out glade_set_custom_handler (:return-type nil)
  (:arguments (handler GladeXMLCustomWidgetHandler)
              (user_data c-pointer)))

(c-lines "#include <glade/glade.h>~%#include <glade/glade-build.h>~%")

(def-c-type GladeWidgetInfo* c-pointer)

(def-c-type GladeNewFunc
    (c-function (:return-type GtkWidget*)
                (:arguments (xml GladeXML*)
                            (widget_type GType)
                            (info c-pointer))))
(def-c-type GladeBuildChildrenFunc
    (c-function (:return-type nil)
                (:arguments (xml GladeXML*)
                            (parent GtkWidget*)
                            (info c-pointer))))
(def-c-type GladeFindInternalChildFunc
    (c-function (:return-type GtkWidget*)
                (:arguments (xml GladeXML*)
                            (parent GtkWidget*)
                            (childname c-string))))

(def-c-type GladeChildInfo* c-pointer)

(def-call-out glade_xml_build_widget (:return-type GtkWidget*)
  (:arguments (self GladeXML*)
              (info c-pointer)))
(def-call-out glade_xml_handle_internal_child (:return-type nil)
  (:arguments (self GladeXML*)
              (parent GtkWidget*)
              (child_info GladeChildInfo*)))
(def-call-out glade_xml_set_common_params (:return-type nil)
  (:arguments (self GladeXML*)
              (widget GtkWidget*)
              (info c-pointer)))
(def-call-out glade_register_widget (:return-type nil)
  (:arguments (type GType)
              (new_func GladeNewFunc)
              (build_children GladeBuildChildrenFunc)
              (find_internal_child GladeFindInternalChildFunc)))
(def-call-out glade_standard_build_widget (:return-type GtkWidget*)
  (:arguments (xml GladeXML*)
              (widget_type GType)
              (info c-pointer)))
(def-call-out glade_xml_handle_widget_prop (:return-type nil)
  (:arguments (self GladeXML*)
              (widget GtkWidget*)
              (prop_name c-string)
              (value_name c-string)))
(def-call-out glade_standard_build_children (:return-type nil)
  (:arguments (self GladeXML*)
              (parent GtkWidget*)
              (info c-pointer)))
(def-call-out glade_xml_set_packing_property (:return-type nil)
  (:arguments (self GladeXML*)
              (parent GtkWidget*)
              (child GtkWidget*)
              (name c-string)
              (value c-string)))
(def-c-type GladeApplyCustomPropFunc
    (c-function (:return-type nil)
                (:arguments (xml GladeXML*)
                            (widget GtkWidget*)
                            (propname c-string)
                            (value c-string))))
(def-call-out glade_register_custom_prop (:return-type nil)
  (:arguments (type GType)
              (prop_name c-string)
              (apply_prop GladeApplyCustomPropFunc)))
(def-call-out glade_xml_relative_file (:return-type c-string)
  (:arguments (self GladeXML*)
              (filename c-string)))
(def-call-out glade_enum_from_string (:return-type int)
  (:arguments (type GType)
              (string c-string)))
(def-call-out glade_flags_from_string (:return-type uint)
  (:arguments (type GType)
              (string c-string)))
(def-c-type GParamSpec* c-pointer)
(def-call-out glade_xml_set_value_from_string (:return-type boolean)
  (:arguments (xml GladeXML*)
              (pspec GParamSpec*)
              (string c-string)
              (value (c-ptr GValue) :out :alloca)))
(def-c-type GtkWindow* c-pointer)
(def-call-out glade_xml_set_toplevel (:return-type nil)
  (:arguments (xml GladeXML*)
              (window GtkWindow*)))
(def-c-type GtkAccelGroup* c-pointer)
(def-call-out glade_xml_ensure_accel (:return-type GtkAccelGroup*)
  (:arguments (xml GladeXML*)))


;;;
;;; High-level UI
;;;

(defun glade-load (file)
  (let ((xml (or (glade_xml_new (namestring (absolute-pathname file)) nil nil)
                 (error "~S(~S): ~S failed" 'glade-load file 'glade_xml_new))))
    (glade_xml_signal_autoconnect_full
     xml
     (lambda (handler_name object signal_name signal_data connect_object
              after user_data)
       (declare (ignore signal_data connect_object after user_data))
       (gtk_connect object signal_name
                    (let ((code (read-from-string handler_name)))
                      (compile
                       (make-symbol (princ-to-string code))
                       `(lambda (&rest args)
                          (format t "~&calling ~S with arguments ~S~%"
                                  ',code args)
                          ,code
                          0))))) ; return an integer
     nil)
    xml))

(defun run-glade-file (file widget-name)
  (gtk_init nil nil)
  (gtk_widget_show_all (glade_xml_get_widget (glade-load file) widget-name))
  (gtk_main))

;;;
;;; sample clisp gui
;;; clisp -K full -x '(gtk:gui "ui.glade")'
;;;

(defstruct gui main repl apropos status about-window about-text)
(defvar *gui*)
(defun gui-from-file (file)
  (let ((xml (glade-load file)))
    (flet ((widget (name)
             (let ((w (or (glade_xml_get_widget xml name)
                          (error "~S(~S): not found ~S" 'gui-from-file
                                 file name))))
               (format t "~&~A == ~S~%" name w)
               w)))
      (make-gui :main (widget "clisp-gui-main")
                :repl (widget "textview_repl")
                :apropos (widget "entry1_apropos")
                :status (widget "statusbar1")
                :about-window (widget "dialog1_about")
                :about-text (widget "textview_about")))))

(defun gui-status-show (string &optional (*gui* *gui*))
  (gtk_statusbar_push (gui-status *gui*) (length string) string))

(defun gui-apropos-do (&optional (*gui* *gui*))
  (apropos (gtk_entry_get_text (gui-apropos *gui*))))

(defun gui-about-do (&optional (*gui* *gui*))
  (let ((about-text
         (format nil "This is a gtk2 demo.~%~A ~A~%"
                 (lisp-implementation-type) (lisp-implementation-version))))
    (gtk_text_buffer_set_text
     (gtk_text_view_get_buffer (gui-about-text *gui*))
     about-text (length about-text)))
  (gtk_widget_show (gui-about-window *gui*))
  (gui-status-show (SYS::TEXT "Displaying ABOUT")))

(defun gui-about-done (&optional (*gui* *gui*))
  (gtk_widget_hide (gui-about-window *gui*))
  (gui-status-show (SYS::TEXT "Closed ABOUT")))

(defun gui-clear-do (&optional (*gui* *gui*))
  (gui-status-show (SYS::TEXT "Clear CLISP output")))

(defun gui-eval-do (&optional (*gui* *gui*))
  (gui-status-show (SYS::TEXT "Call EVAL on the current selection")))

(defun gui-describe-do (&optional (*gui* *gui*))
  (gui-status-show (SYS::TEXT "Call DESCRIBE on the current selection")))

(defun gui-quit (&optional (*gui* *gui*))
  (gui-status-show (SYS::TEXT "Bye."))
  (gtk_main_quit)
  (throw 'gui-quit 0))

(defun gui (file)
  (gtk_init nil nil)
  (let ((*gui* (gui-from-file file)))
    (gui-status-show
     (ext:string-concat (SYS::TEXT "Welcome to") " "
                        (lisp-implementation-type) "!"))
    (gtk_widget_show (gui-main *gui*))
    (gtk_widget_hide (gui-about-window *gui*))
    (catch 'gui-quit (gtk_main))
    (format t (SYS::TEXT "Exited gui~%"))))

;;; done
(pushnew :gtk *features*)
(provide "gtk")
(pushnew "GTK" custom:*system-package-list* :test #'string=)
