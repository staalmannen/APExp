;; -*- Lisp -*- vim:filetype=lisp
;; Test CLISP specific extensions (typically in package EXT)
;; Many tests already in alltest.tst, map.tst etc., but
;; here we avoid using #+clisp all over the place.
;; Jörg Höhle, 2007
;; Sam Steingold, 2007-2008

;(setf if) 5.1.6
(mapcar (lambda (x &aux a b) (list (setf (if x a b) 2) a b)) '(t nil))
((2 2 nil) (2 nil 2))

(loop with a and b for x below 2
      collect (multiple-value-list
               (setf (if (zerop x) (values a b) (values b a)) (floor 7 5)))
      collect (cons a b))
((1 2) (1 . 2) (1 2) (2 . 1))

(let (x a b c) (setf (if (zerop x) (values a b) c) x))
ERROR ; different number of values in if branches

;(setf progn)

;(setf funcall)

;(setf locally)

;(setf values-list)

;5.1.2 fcase
(ext:fcase string= (let ((foo "two third")) (subseq foo 0 (position #\Space foo)))
  ("first" 1)
  (("second" "two") 2)
  (("true" "yes") t)
  (otherwise nil))
2

;5.1.3 xor
(multiple-value-list (xor nil nil nil))
(nil)

(multiple-value-list (ext:xor nil (block nil (return 'a)) nil))
(a 2)

;5.1.10 custom:*defun-accept-specialized-lambda-list*

;12. long-float-digits + setf long-float-digits

;12.3.2 ! (factorial)
(ext:! 10)
3628800
(ext:! 11)
39916800

(ext:! 0)
1

(ext:! 3/2)
ERROR

;14.2 push, pop and pushnew operate on multiple VALUES places in parallel
(multiple-value-list
 (let (a b)
   (push (values 1 2) (values a b))))
((1) (2))

(let (a b)
  (list (multiple-value-list
         (pushnew (values 1 2) (values a b)))
        a b))
(((1) (2)) (1) (2))

(let ((a '(1)) (b '(2 3)))
  (list (multiple-value-list
         (pop (values a b))) a b))
((1 2) () (3))

;17.1 ext:doseq

;18.1.4 ext:dohash
(defun test-dohash (hash-table)
  (let ((all-entries '())
        (generated-entries '())
        (unique (list nil)))
    (maphash #'(lambda (key value) (push (list key value) all-entries))
             hash-table)
    (dohash (key value hash-table)
      (declare (optimize safety))
      (unless (eql value (gethash key hash-table unique))
        (error "Key ~S not found for value ~S" key value))
      (push (list key value) generated-entries))
    (unless (= (length all-entries)
               (length generated-entries)
               (length (union all-entries generated-entries
                              :key #'car :test (hash-table-test hash-table))))
      (error "MAPHASH and EXT:DOHASH entries don't correspond"))
    t))
test-dohash

(let ((tab (make-hash-table :test #'equal))) ; see alltest.tst
  (setf (gethash "Richard" tab) "Gabriel")
  (setf (gethash "Bruno" tab) "Haible")
  (setf (gethash "Michael" tab) "Stoll")
  (setf (gethash "Linus" tab) "Torvalds")
  (setf (gethash "Richard" tab) "Stallman")
  (test-dohash tab)
)
T

(let ((hash-table (make-hash-table)) (entries '()))
  (setf (gethash 1 hash-table) 100)
  (setf (gethash 2 hash-table) 200)
  (sort (ext:dohash (key value hash-table entries)
          (declare (ignore key))
          (push value entries)) #'<))
(100 200)

(let ((hash-table (make-hash-table
                   :initial-contents '((1 . 100) (2 . 200))))
      (entries '()))
  (sort (ext:dohash (key value hash-table entries)
          (push value entries)
          (go skip)
          (push key entries)
          skip) #'<))
(100 200)

;30.11 ext:letf
(let ((x (list 1))) (list (ext:letf (((car x) 3)) (list x (copy-list x))) x))
(((1) (3)) (1))

(let ((x (list 1))) ; Bug #[ 1731462 ]
  (list (ext:letf (((car x) 3)
                   ((cdr x) (copy-list x)))
          (list x (copy-list x))) x))
(((1) (3 1)) (1))

(let (a b) (list (letf  (((values a b) (values 1 2))) (list a b)) (list a b)))
((1 2) (nil nil))

;ext:letf*
(let ((x (list 2))) (list (ext:letf* (((car x) 3)) (list x (copy-list x))) x))
(((2) (3)) (2))

(let ((x (list 1)))
  (list (ext:letf* (((car x) 3)
                    ((cdr x) (copy-list x)))
          (list x (copy-list x))) x))
(((1) (3 3)) (1))

(let (a b) (list (letf* (((values a b) (values 1 2))) (list a b)) (list a b)))
((1 2) (nil nil))

(let ((x (list 1)))
  (block nil (letf (((car x) 2)
                    ((cdr (progn (return) x)) 3)) x))
  x)
(1)

;letf ldb unsurprisingly restores bitfield bits, not the whole integer value
(let ((x (list #xAAAAAA)))
  (letf (((ldb (byte 5 9) (first x)) -1))
    (setf (first x) 0)) x)
(#x002a00)

(let ((x (list 1))) (letf (((first x) 3))))
nil

;letf/* within macrolet
(let ((x (list 1)))
  (macrolet ((frob () '(first x)))
    (letf  (((frob) 2)) (copy-list x))))
(2)

(let ((x (list 1)))
  (macrolet ((frob () '(first x)))
    (letf* (((frob) 2)) (copy-list x))))
(2)

(symbol-macrolet ((a *print-base*)) (letf  ((a 36)) (princ-to-string 20)))
"K"
(symbol-macrolet ((a *print-base*)) (letf* ((a 36)) (princ-to-string 20)))
"K"

(let (a b c) (symbol-macrolet ((a *print-base*)) (letf  (((values a b c) 36)) (princ-to-string 20))))
"K"

(let (a b c) (symbol-macrolet ((a *print-base*)) (letf* (((values a b c) 36)) (princ-to-string 20))))
"K"

(let ((a (vector 0 0))) (letf  (((values (aref a 0) (aref a 1)) (floor 7 5))) (copy-seq a)))
#(1 2)

(let ((a (vector 0 0))) (letf* (((values (aref a 0) (aref a 1)) (floor 7 5))) (copy-seq a)))
#(1 2)

(letf  (((values) 1)) 2)
2
(letf* (((values) 1)) 2)
2

;letf values-list

(makunbound 'xx)
xx

;letf on symbol-value breaks on unbound variable,
; so it's different from let + special declaration or progv (wishlist)
(letf (((symbol-value 'xx) 3)) (declare (special xx)) xx)
ERROR
;(progv (list 'xx) (list 3) ...)

;letf with gethash leaves default entry, not missing entry in table!
(multiple-value-list
 (gethash 1 (letf* ((h (make-hash-table)) ((gethash 1 h) 'a)) h) 2))
(nil t)

(multiple-value-list
 (gethash 1 (letf* ((h (make-hash-table)) ((gethash 1 h 'b) 'a)) h) 2))
(b t)

;letf on property lists leaves default value!
(let ((a '())) (letf* (((getf a :key) 1))) a)
(:key ())

(let ((a '())) (letf* (((getf a :key :default) 1))) a)
(:key :default)

(let ((a '())) (letf (((getf a :key :default) 1))) a)
(:key :default)

(let* ((x 9) (f (lambda () x)))
  (letf (((values x y) (floor 7 5)))
    (list x (funcall f))))
(1 9) ; use LET, not SETF
(let* ((x 9) (f (lambda () x)))
  (letf* (((values x y) (floor 7 5)))
    (list x (funcall f))))
(1 9) ; use LET, not SETF

(let* ((x 9) (fx (lambda () x)) (y 3) (fy (lambda () y)))
  (ext:letf* (((values (values x) y) (floor 7 5)))
    (list x (funcall fx) y (funcall fy))))
(1 1 2 2) ; SETF is used, no LET -- for both variables

(let* ((x (list 9)) (y 8) (fy (lambda () y)))
  (ext:letf* (((values (car x) y) (floor 7 5)))
    (list y (funcall fy))))
(2 2) ; SETF is used, no LET at all

;21.3 read-char-will-hang-p etc.

;make-buffered-input-stream

;24.1.2 featurep
(every #'ext:featurep *features*)
T

(notany (lambda (x) (featurep `(not ,x))) *features*)
T

;30.11 ethe
((lambda (x) (declare (compile)) (ext:ethe integer x)) 3)
3

((lambda (x) (declare (compile)) (ext:ethe integer x)) t)
ERROR

(locally (declare (compile))
  (multiple-value-list (ethe (values integer float) (truncate 3.2 2))))
(1 1.2)

(locally (declare (compile)) (ethe (values float integer) (truncate 3.2 2)))
ERROR

(canonicalize 1 `(,#'1+)) ERROR
(canonicalize "foo" `(,#'string-upcase) :test 'equal) "FOO"
(canonicalize "iso1234"
 `(,(lambda (s)
      (if (and (<= 4 (length s))
               (string-equal s "iso" :end1 3)
               (not (char= #\- (char s 3))))
          (concatenate 'string "ISO-" (subseq s 3))
          s)))
 :test 'equal)
"ISO-1234"

(defun check-load (file)
  (let* ((dir (ext:string-concat (second (pathname-directory file)) "/"))
         (*load-paths* (list '#p"" (pathname (ext:string-concat dir "**/")))))
    (unwind-protect
         (progn
           (prepare-directory file)
           (with-open-file (s file :direction :output)
             (prin1 '(setf (cdr *load-paths*) nil) s))
           (load (pathname-name file))
           *load-paths*)
      (rmrf dir))))
CHECK-LOAD

(check-load "ext-clisp-tst/foo/bar/baz/zot.lisp") (#p"")
(check-load "ext-clisp-tst/foo/bar/baz/zot") (#p"")

(defparameter *s1* (open "ext-clisp-tst-abazonk" :direction :output)) *s1*
(open "ext-clisp-tst-abazonk" :direction :output) ERROR
(defparameter *s2* (appease-cerrors (open "ext-clisp-tst-abazonk"))) *s2*
(equal (truename *s1*) (truename *s2*)) T
(open-stream-p *s1*) T
(open-stream-p *s2*) T
(defparameter *s3* (let ((*reopen-open-file* 'warn))
                     (open "ext-clisp-tst-abazonk"))) *s3*
(open-stream-p *s1*) T
(open-stream-p *s2*) T
(open-stream-p *s3*) T
(equal (truename *s1*) (truename *s3*)) T
(defparameter *s4* (let ((*reopen-open-file* 'close))
                     (open "ext-clisp-tst-abazonk"))) *s4*
(open-stream-p *s1*) NIL
(open-stream-p *s2*) T
(open-stream-p *s3*) T
(open-stream-p *s4*) T
(equal (truename *s1*) (truename *s4*)) T
(defparameter *s1* (let ((*reopen-open-file* 'close))
                     (open "ext-clisp-tst-abazonk" :direction :output))) *s1*
(open-stream-p *s1*) T
(open-stream-p *s2*) NIL
(open-stream-p *s3*) NIL
(open-stream-p *s4*) NIL
(equal (truename *s1*) (truename *s4*)) T
(let ((*reopen-open-file* 0)) (open "ext-clisp-tst-abazonk")) ERROR
(close *s1*) T
(pathnamep (delete-file *s1*)) T

(multiple-value-bind (cmd args) (cmd-args)
  (list (ext:run-program cmd :arguments (append args '("-x" "(exit 42)")))
        (ext:run-program cmd :arguments (append args '("-x" "(exit)")))))
(42 NIL)

(multiple-value-bind (cmd args) (cmd-args)
  (with-open-stream (s (ext:make-pipe-input-stream
                        (with-output-to-string (s)
                          (princ cmd s)
                          (dolist (a args) (princ #\space s) (princ a s))
                          (princ " -x \"(quote hello)\"" s))))
    (read-line s)))
"HELLO"

(multiple-value-bind (cmd args) (cmd-args)
  (with-open-stream (s (ext:make-pipe-output-stream
                        (with-output-to-string (s)
                          (princ cmd s)
                          (dolist (a args) (princ #\space s) (princ a s)))))
    (write-line "(quit)" s)))
"(quit)"

(multiple-value-bind (cmd args) (cmd-args)
  (multiple-value-bind (pid in out err)
      (ext::launch cmd :arguments args :input :pipe :output :pipe :error :pipe)
    (unwind-protect
         (list (integerp (show pid))
               (output-stream-p in)
               (input-stream-p out)
               (input-stream-p err)
               (write-line "(quit)" in) (force-output in)
               (read-line out))
    (close in) (close out) (close err))))
(T T T T "(quit)" NIL "[1]> ")

;; c-CONCATENATE
(let ((args (list (code-char (random char-code-limit))
                  (user-homedir-pathname)
                  'args)))
  (loop :for l :in
    '((lambda (a b c) (concatenate 'string "[" (symbol-name c) " "
                                   (namestring b) " " (char-name a) "]")))
    :for c = (compile nil l) :do (disassemble c)
    :always (string= (apply (coerce l 'function) args)
                     (show (apply c args)))))
T

;; (declare (compile [name]))
(type-of (lambda (x) (declare (compile ident)) x)) COMPILED-FUNCTION
(sys::closure-name (lambda (x) (declare (compile ident)) x)) IDENT
(let ((l (let ((x 12))
           (declare (compile increment))
           (list (lambda () (incf x))
                 (lambda () (decf x))))))
  (list (every #'compiled-function-p l)
        (mapcar #'sys::closure-name l)
        (mapcar #'funcall l)))
(T (INCREMENT-1 INCREMENT-2) (13 12))

(multiple-value-bind (mypush mypop)
    (let ((acc nil))
      (values (lambda (x) (push x acc))
              (lambda () (pop acc))))
  (list (list (funcall mypop)
              (funcall mypush 1) (funcall mypop) (funcall mypop)
              (funcall mypush 2) (funcall mypush 3)
              (funcall mypop) (funcall mypop) (funcall mypop))
        (let ((pair (read-from-string
                     (with-standard-io-syntax
                       (let ((*print-closure* t))
                         (prin1-to-string (cons mypush mypop)))))))
          (list (funcall (cdr pair))
                (funcall (car pair) 1) (funcall (cdr pair)) (funcall (cdr pair))
                (funcall (car pair) 2) (funcall (car pair) 3)
                (funcall (cdr pair)) (funcall (cdr pair))
                (funcall (cdr pair))))))
((NIL
  (1) 1 NIL
  (2) (3 2)
  3 2 NIL)
 (NIL
  (1) 1 NIL
  (2) (3 2)
  3 2 NIL))

(progn (symbol-cleanup 'check-load) (symbol-cleanup 'test-dohash)
       (symbol-cleanup '*s1*) (symbol-cleanup '*s2*)
       (symbol-cleanup '*s3*) (symbol-cleanup '*s4*))
T
