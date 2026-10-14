;; -*- Lisp -*- vim:filetype=lisp

(READ-FROM-STRING "123") 123

(PRIN1-TO-STRING 123) "123"

(SETQ *A* (MAKE-ARRAY 10. :ELEMENT-TYPE #-(or CMU SBCL LISPWORKS) 'STRING-CHAR #+(or CMU SBCL LISPWORKS) 'CHARACTER :FILL-POINTER 0)) ""

(FORMAT *A* "XXX") NIL

*A* "XXX"

#+XCL (SYS::CHECK-STREAM-SYSTEM) #+XCL T

(defun bin-stream-test (&key (size (integer-length most-positive-fixnum))
                        (type 'unsigned-byte) (file-name "streamslong-tst-foo")
                        (num-bytes 10)
                        (bytes (if (eq type 'signed-byte)
                                   (loop :repeat num-bytes :collect
                                         (- (random (ash 1 size))
                                            (ash 1 (1- size))))
                                   (loop :repeat num-bytes :collect
                                         (random (ash 1 size))))))
  (with-open-file (foo file-name :direction :output #+(or CMU SBCL) :if-exists #+(or CMU SBCL) :supersede
                       :element-type (list type size))
    (dolist (byte bytes)
      (write-byte byte foo)))
  (unwind-protect
       (with-open-file (foo file-name :direction :input
                            :element-type (list type size))
         (list (stream-element-type foo) (file-length foo) bytes
               (loop :for byte :in bytes :for nb = (read-byte foo) :collect nb
                     :unless (= nb byte) :do
                     (flet ((by-out (sz by)
                              (format nil "~v,'0,' ,4:b"
                                      (+ sz (floor sz 4)) by)))
                       (error "~& * [(~s ~s)] ~a != ~a~%" type size
                              (by-out size byte) (by-out size nb))))))
    (delete-file file-name)))
bin-stream-test

(loop for size from 2 to 40 do (bin-stream-test :size size))
nil

(loop for size from 2 to 40 do (bin-stream-test :size size :type 'signed-byte))
nil

;; <http://www.lisp.org/HyperSpec/Body/fun_file-position.html>
(let ((noticed '()) file-written)
  (flet ((notice (x) (push x noticed) x))
    (unwind-protect (progn
         (with-open-file (s "streamslong-tst-footest.bin"
                            :element-type '(unsigned-byte 8)
                            :direction :output #+(or CMU SBCL) :if-exists #+(or CMU SBCL) :supersede
                            :if-exists :error)
           (notice (file-position s)) ;1
           (write-byte 5 s)
           (write-byte 6 s)
           (let ((p (file-position s)))
             (notice p) ;2
             (notice (when p (file-position s (1- p))))) ;3
           (write-byte 7 s)
           (notice (file-position s)) ;4
           (setq file-written (truename s)))
         (with-open-file (s file-written
                            :element-type '(unsigned-byte 8)
                            :direction :input)
           (notice (file-position s)) ;5
           (let ((length (file-length s)))
             (notice length) ;6
             (when length
               (dotimes (i length)
                 (notice (read-byte s)))))) ;7,...
         (nreverse noticed))
      (delete-file file-written))))
(0 2
 #+(or CLISP OpenMCL LISPWORKS) 1 #+(or GCL CMU SBCL) T #-(or CLISP GCL CMU SBCL OpenMCL LISPWORKS) UNKNOWN
 2 0 2 5 7)

(let ((s (make-string-input-stream
          (make-array 10 :element-type (array-element-type "")
                         :displaced-to "abcdefghijklmnopqrst"
                         :displaced-index-offset 5))))
  (prog1
      (list (read-char s) (read-char s) (file-position s)
            (file-position s 4) (read-char s)
            (file-position s :start) (read-char s)
            (file-position s :end) (file-position s))
    (close s)))
(#\f #\g 2 4 #\j 0 #\f 10 10)

(let ((s (make-string-output-stream)))
  (prog1
      (list (write-char #\a s) (write-char #\b s) (file-position s)
            (get-output-stream-string s)
            (write-string "foo" s) (file-position s 1) (write-char #\z s)
            (get-output-stream-string s)
            (file-position s :start) (write-char #\u s)
            (file-position s :end) (write-char #\w s)
            (get-output-stream-string s))
    (close s)))
#+CLISP (#\a #\b 2 "ab" "foo" 1 #\z "fz" 0 #\u 1 #\w "uw")
#+GCL (#\a #\b 2 "ab" "foo" T #\z "fz" T #\u T #\w "uw")
#+(or SBCL LISPWORKS) (#\a #\b 2 "ab" "foo" 1 #\z "fzo" 0 #\u 1 #\w "uw")
#-(or CLISP GCL SBCL LISPWORKS) UNKNOWN

(let ((v (make-array 3 :adjustable t :fill-pointer 0
                       :element-type 'character)))
  (with-output-to-string (s v)
    (list (write-string "foo" s) (cons (file-position s) (copy-seq v))
          (file-position s 2) (write-string "bar" s)
          (cons (file-position s) (copy-seq v))
          (file-position s :start) (write-string "zot" s)
          (cons (file-position s) (copy-seq v))
          (file-position s :end) (write-string "plonk" s)
          (cons (file-position s) (copy-seq v)) v)))
("foo" (3 . "foo")
 2 "bar" (5 . "fobar")
 0 "zot" (3 . "zot")
 3 "plonk" (8 . "zotplonk")
 "zotplonk")

;; <https://sourceforge.net/tracker/?func=detail&aid=959549&group_id=1355&atid=101355>
#+CLISP
(let ((f "streamslong-tst-foo") (s "12345") l)
  (with-open-file (o f :direction :output) (write-string s o))
  (with-open-file (i f :buffered t) (listen i) (push (read-char i) l))
  (with-open-file (i f :buffered nil) (listen i) (push (read-char i) l))
  (delete-file f)
  l)
#+CLISP
(#\1 #\1)

#+CLISP
(let ((file "streamslong-tst-foo") s1 s2)
  (with-open-file (out file :direction :output)
    (write out :stream out) (terpri out)
    (setq s1 (write-to-string out))
    (force-output out)
    (ext:appease-cerrors
     (with-open-file (in file :direction :input)
       (setq s2 (read-line in)))))
  (delete-file file)
  (string= s1 s2))
#+CLISP T

#+CLISP
(progn
  (defclass gray-out (fundamental-character-output-stream)
    ((accumulator :type string)))
  (defmethod initialize-instance :after ((s gray-out) &rest args)
    (setf (slot-value s 'accumulator)
          (make-array 0 :element-type 'character :adjustable t :fill-pointer 0)))
  (defmethod stream-write-char ((s gray-out) ch)
    (vector-push-extend ch (slot-value s 'accumulator)))
  (defmacro with-g-o ((v) &body forms)
    `(let ((,v (make-instance 'gray-out)))
       ,@forms
       (close ,v)
       (coerce (slot-value ,v 'accumulator) 'simple-string)))
  (list (with-g-o (v) (write-char #\a v))
        (with-g-o (v) (write-char-sequence "abc" v))
        (handler-case (with-g-o (v) (write-sequence #(#\a #\b #\c) v))
          (clos:method-call-error (e)
            (clos:generic-function-name
             (clos:method-call-error-generic-function e))))
        (with-g-o (v) (stream-write-char-sequence v "abc"))
        (handler-case (with-g-o (v) (stream-write-sequence v #(#\a #\b #\c)))
          (clos:method-call-error (e)
            (clos:generic-function-name
             (clos:method-call-error-generic-function e))))
        (with-g-o (v) (stream-write-sequence "abc" v))
        (setf (find-class 'gray-out) nil)
        (fmakunbound 'with-g-o)))
#+CLISP ("a" "abc" gray:stream-write-char-sequence
         "abc" gray:stream-write-sequence "abc" NIL WITH-G-O)

;; https://sourceforge.net/tracker/index.php?func=detail&aid=2022362&group_id=1355&atid=101355
(let ((fname "streamslong-tst-foo")
      (vec (make-array 5 :element-type '(unsigned-byte 8))))
  (flet ((foo (l)
           (unwind-protect
                (list
                 (with-open-file (f fname :external-format :dos :direction :io)
                   (dolist (s l) (write-line s f))
                   (file-position f 0)
                   (read-line f)
                   (setf (stream-element-type f) '(unsigned-byte 8))
                   (read-byte f nil))
                 (mapcar (lambda (b)
                           (with-open-file (f fname :direction :input
                                              :buffered b)
                             (read-line f)
                             (setf (stream-element-type f) '(unsigned-byte 8))
                             (list b (read-byte f nil))))
                         '(t nil))
                 (mapcar (lambda (b)
                           (with-open-file (f fname :direction :input
                                              :buffered b)
                             (read-line f)
                             (setf (stream-element-type f) '(unsigned-byte 8))
                             (list b (subseq vec 0 (read-sequence vec f)))))
                         '(t nil)))
             (delete-file fname))))
    (list (foo '("1"))
          (foo '("1" "2")))))
((NIL ((T NIL) (NIL NIL)) ((T #()) (NIL #())))
 (50 ((T 50) (NIL 50)) ((T #(50 13 10)) (NIL #(50 13 10)))))

(let ((fname "streamslong-tst-foo"))
  (flet ((line-term (s) (encoding-line-terminator (stream-external-format s))))
    (unwind-protect
         (list
          (with-open-file (f fname :direction :output :external-format :dos)
            (let ((b (make-broadcast-stream f)))
              (list (list (line-term b) (line-term f))
                    (progn (setf (stream-external-format b :output) :unix)
                           (list (line-term b) (line-term f)))
                    (list (stream-element-type b) (stream-element-type f))
                    (setf (stream-element-type b) '(unsigned-byte 8))
                    (list (stream-element-type b) (stream-element-type f)))))
          (with-open-file (f fname :direction :input :external-format :dos)
            (let ((c (make-concatenated-stream f)))
              (list (list (line-term c) (line-term f))
                    (progn (setf (stream-external-format c :input) :unix)
                           (list (line-term c) (line-term f)))
                    (list (stream-element-type c) (stream-element-type f))
                    (setf (stream-element-type c) '(unsigned-byte 8))
                    (list (stream-element-type c) (stream-element-type f))))))
      (delete-file fname))))
(((:DOS :DOS) (:UNIX :UNIX)
  (CHARACTER CHARACTER) (UNSIGNED-BYTE 8)
  ((UNSIGNED-BYTE 8) (UNSIGNED-BYTE 8)))
 ((:DOS :DOS) (:UNIX :UNIX)
  (CHARACTER CHARACTER) (UNSIGNED-BYTE 8)
  ((UNSIGNED-BYTE 8) (UNSIGNED-BYTE 8))))

(let ((fname "test-eof")
      #+clisp (custom:*reopen-open-file* nil))
  (open fname :direction :probe :if-exists :overwrite ; touch
        :if-does-not-exist :create)
  (flet ((f (buf new)
           (with-open-file (in fname :direction :input)
             (list (read-line in nil :eof)
                   (progn
                     (with-open-file (out fname :direction :output
                                          :if-exists :append)
                       (write-line new out))
                     #+clisp (clear-input in)
                     (read-line in nil :eof))))))
    (unwind-protect (list (f t "foo") (f nil "bar"))
      (delete-file fname))))
((:EOF "foo") ("foo" "bar"))

#+CLISP
(let* ((list ())
       (out (ext:make-buffered-output-stream (lambda (c) (push c list)))))
  (list (write-char #\a out)
        (close out)
        list))
#+CLISP (#\a T ("a"))

#+CLISP
(let* ((list ())
       (out (ext:make-buffered-output-stream
             (lambda (c) (push c list) (error (string c))))))
  (list (write-char #\a out)
        (block b
          (handler-bind ((error (lambda (c)
                                  (princ-error c) (return-from b list))))
            (close out)))))
#+CLISP (#\a ("a"))

#+CLISP
(let* ((list ())
       (out (ext:make-buffered-output-stream
             (lambda (c) (push c list) (error (string c))))))
  (list (write-char #\a out)
        (close out :abort t)
        list
        (princ-to-string out)))
#+CLISP (#\a T ("a") "#<CLOSED OUTPUT BUFFERED-OUTPUT-STREAM NIL>")

#+CLISP
(let ((file-in "test-extfmt-in") (file-out "test-extfmt-out"))
  (open file-in :direction :probe :if-does-not-exist :create)
  (unwind-protect
       (with-open-file (out file-out :direction :output :external-format :dos)
         (with-open-file (in file-in :direction :input :external-format :dos)
           (with-open-stream (io (make-two-way-stream in out))
             (list (ext:encoding-line-terminator (stream-external-format io))
                   (ext:encoding-line-terminator
                    (setf (stream-external-format io) :unix))
                   (ext:encoding-line-terminator (stream-external-format io))
                   (ext:encoding-line-terminator (stream-external-format in))
                   (ext:encoding-line-terminator (stream-external-format out))))))
    (delete-file file-in) (delete-file file-out)))
#+CLISP (:DOS :UNIX :UNIX :UNIX :UNIX)

#+CLISP
(let ((file "test-extfmt"))
  (with-open-file (out file :direction :output :external-format :dos
                       :if-exists :supersede)
    (terpri out)
    (setf (stream-external-format out) :unix)
    (terpri out))
  (unwind-protect
       (with-open-file (in file :direction :input
                           :element-type '(unsigned-byte 8))
         (let ((v (make-array (file-length in))))
           (read-sequence v in)
           (map 'vector #'code-char v)))
    (delete-file file)))
#+CLISP #(#\Return #\Newline #\Newline)

;; https://sourceforge.net/tracker/?func=detail&atid=101355&aid=3024887&group_id=1355
#+(and CLISP UNIX)
(let ((file "test-pipe"))
  (unwind-protect
       (dolist (b '(nil t))
         (with-open-stream (out (ext:make-pipe-output-stream
                                 (format nil "/bin/cat > ~A" file)
                                 :external-format charset:utf-8 :buffered b))
           (loop for i below 1000 do (print i out)))
         (sleep 1)              ; let cat terminate
         (with-open-file (in file :direction :input
                             :external-format charset:utf-8)
           (loop for i below 1000 do (assert (= i (read in))))))
    (delete-file file)))
#+(and CLISP UNIX) NIL
