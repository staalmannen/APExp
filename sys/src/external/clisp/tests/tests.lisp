;; run the test suit:

;;; --- helpers for misc tests ---
(defun princ-error (c) (format t "~&[~A]: ~A~%" (type-of c) c))
(defun show (object &key ((:pretty *print-pretty*) *print-pretty*))
  "Print the object on its own line and return it. Used in many tests!"
  (fresh-line) (prin1 object) (terpri) object)
#+clisp (progn
(defun kill-down (name)
  (dolist (f (directory (ext:string-concat name "**/*")))
    (format t "~&removing file ~S~%" f)
    (delete-file f)))
(defun rmrf (name)
  (ext:dir (ext:string-concat name "**/*"))
  (ext:dir (ext:string-concat name "**/"))
  (kill-down name)
  (dolist (d (directory (ext:string-concat name "**/")))
    (format t "~&removing directory ~S~%" d)
    (ext:delete-directory d)))
(defun prepare-directory (name)
  (ensure-directories-exist name :verbose t)
  (kill-down name))
(defun cmd-args ()
  "command and arg list for cloning this clisp process"
  (let* ((argv (ext:argv))
         (lispinit (aref argv (1+ (position "-M" argv :test #'string=)))))
    (values (aref argv 0)
            (list "-q" "-norc" "-B" (namestring *lib-directory*) "-M"
                  (namestring (merge-pathnames lispinit *lib-directory*))))))
(export '(kill-down rmrf prepare-directory cmd-args))
)
(defun show-file (file)         ; return line count
  (with-open-file (st file :direction :input)
    (format t "~&~S: ~:D byte~:P:~%" file (file-length st))
    (loop :for l = (read-line st nil nil) :while l :count t
      :do (format t "--> ~S~%" l))))
(defun finish-file (file) (prog1 (show-file file) (delete-file file)))
(defun post-compile-file-cleanup (file)
  (delete-file file)
  (delete-file (compile-file-pathname file))
  #+clisp (delete-file (make-pathname :type "lib" :defaults file)))
(defun symbol-cleanup (s)
  (setf (find-class s) nil) (makunbound s) (fmakunbound s) (unintern s))
(defvar *run-test-truename*)
;; export symbols used by tests
(export '(princ-error show show-file finish-file post-compile-file-cleanup
          type-error-handler
          symbol-cleanup *run-test-truename* with-ignored-errors diff-seq))
;;; end helpers

#+OLD-CLISP
;; Binding *ERROR-HANDLER* is a hammer technique for catching errors. It also
;; disables CLCS processing and thus breaks tests that rely on the condition
;; system, such as:
;;   - the compile-file on structure literal test in clos.lisp
;;   - all tests that use IGNORE-ERRORS
(defmacro with-ignored-errors (&rest forms)
  (let ((b (gensym)))
    `(BLOCK ,b
       (LET ((*ERROR-HANDLER*
              #'(LAMBDA (&REST ARGS)
                  (with-standard-io-syntax
                    (let* ((*print-readably* nil)
                           (error-message (apply #'format nil (cdr args))))
                      (terpri) (princ error-message)
                      (return-from ,b (values 'error error-message)))))))
         ,@forms))))

#+(or (and AKCL (not GCL)) ECL)
(defmacro with-ignored-errors (&rest forms)
  (let ((b (gensym))
        (h (gensym)))
    `(BLOCK ,b
       (LET ((,h (SYMBOL-FUNCTION 'SYSTEM:UNIVERSAL-ERROR-HANDLER)))
         (UNWIND-PROTECT
           (PROGN (SETF (SYMBOL-FUNCTION 'SYSTEM:UNIVERSAL-ERROR-HANDLER)
                        #'(LAMBDA (&REST ARGS) (RETURN-FROM ,b 'ERROR)))
                  ,@forms)
           (SETF (SYMBOL-FUNCTION 'SYSTEM:UNIVERSAL-ERROR-HANDLER) ,h))))))

#+ALLEGRO
(defmacro with-ignored-errors (&rest forms)
  (let ((r (gensym)))
    `(LET ((,r (MULTIPLE-VALUE-LIST (EXCL:ERRORSET (PROGN ,@forms)))))
       (IF (CAR ,r) (VALUES-LIST (CDR ,r)) 'ERROR))))

#-(or OLD-CLISP (and AKCL (not GCL)) ECL ALLEGRO)
(defmacro with-ignored-errors (&rest forms)
  (let ((b (gensym)))
    `(BLOCK ,b
       (HANDLER-BIND
         ((ERROR #'(LAMBDA (CONDITION)
                     (PRINC-ERROR CONDITION)
                     (RETURN-FROM ,b (values 'ERROR
                                             (princ-to-string condition))))))
         ,@forms))))

(defun merge-extension (type filename)
  (make-pathname :type type :defaults filename))

;; (lisp-implementation-type) may return something quite long, e.g.,
;; on CMUCL it returns "CMU Common Lisp".
(defvar lisp-implementation
  #+CLISP "CLISP" #+(and AKCL (not GCL)) "AKCL" #+GCL "GCL" #+ECL "ECL" #+ALLEGRO "ALLEGRO" #+CMU "CMUCL"
  #-(or CLISP AKCL GCL ECL ALLEGRO CMU) (lisp-implementation-type))

(defvar *eval-method* :eval)
(defvar *eval-out* nil)
(defvar *eval-err* nil)
(defun my-eval (form)
  (when *eval-out* (get-output-stream-string *eval-out*))
  (when *eval-err* (get-output-stream-string *eval-err*))
  (ecase *eval-method*
    (:eval (eval form))
    (:compile (funcall (compile nil `(lambda () ,form))))
    (:both (let ((e-value (eval form))
                 (c-value (funcall (compile nil `(lambda () ,form)))))
             (unless (equalp e-value c-value)
               (error "eval: ~S; compile: ~S" e-value c-value))
             e-value))))

;; compare 2 sequences:
;; list of (pos first second);
;; last 3 elements can be smaller length, tail1, tail2
(defun diff-seq (s1 s2 &key (test #'eql))
  (let ((pos 0))
    (nconc
     (delete nil
             (map 'list (lambda (e1 e2)
                          (prog1 (unless (funcall test e1 e2)
                                   (list pos e1 e2))
                            (incf pos)))
                  s1 s2))
     (let ((l1 (length s1)) (l2 (length s2)))
       (cond ((< l1 l2) (list l1 nil (subseq s2 l1)))
             ((< l2 l1) (list l2 (subseq s1 l2) nil)))))))

(defgeneric pretty-compare (result my-result log)
  (:documentation "print a pretty comparison of two results")
  (:method ((result sequence) (my-result sequence) (log stream))
    (let ((pos (mismatch result my-result :test #'equalp)))
      (let ((*print-length* 10))
        (if pos
            (flet ((pretty-tail-10 (seq)
                     (if (and (> (length seq) (+ pos 10))
                              (typep seq 'string))
                         (concatenate 'string (subseq seq pos (+ pos 10)) "...")
                         (subseq seq pos))))
              (format log "~&Differ at position ~:D: ~S vs ~S~%CORRECT: ~S~%~7A: ~S~%"
                      pos
                      (if (< pos (length result))
                          (elt result pos) 'end-of-sequence)
                      (if (< pos (length my-result))
                          (elt my-result pos) 'end-of-sequence)
                      (pretty-tail-10 result)
                      lisp-implementation
                      (pretty-tail-10 my-result)))
            (format log "~&Type mismatch: ~S should be ~S~%"
                    (type-of my-result) (type-of result))))))
  (:method ((result pathname) (my-result pathname) (log stream))
    (dolist (slot '(pathname-host pathname-device pathname-directory
                    pathname-name pathname-type pathname-version))
      (let ((s-r (funcall slot result)) (s-m (funcall slot my-result)))
        (format log "~&~S:~%CORRECT: ~S~%~7A: ~S~%~:[ DIFFERENT!~;same~]~%"
                slot s-r lisp-implementation s-m (equal s-r s-m)))))
  (:method ((result t) (my-result t) (log stream)))) ; do nothing

(defun type-error-handler (err)
  "Print the condition and THROW.
Usage: (handler-bind ((type-error #'type-error-handler)) ...)"
  (princ-error err)
  (let ((da (type-error-datum err)) (et (type-error-expected-type err)))
    (show (list :datum da :expected-type et) :pretty t)
    (throw 'type-error-handler (typep da et))))

(defvar *test-ignore-errors* t)
(defvar *test-result-in-file* t
  "T: CLISP-style: evaluation result in the file after the test form.
NIL: sacla-style: forms should evaluate to non-NIL.")
(defun do-test (stream log)
  (let ((eof stream) (error-count 0) (total-count 0))
    (loop
      (let ((form (read stream nil eof)) out err (result nil))
        (when (or (eq form eof) (eq result eof)) (return))
        (if *test-result-in-file*
            (setq result (read stream))
            (setq form `(not ,form)))
        (incf total-count)
        (show form)
        (multiple-value-bind (my-result error-message)
            (if *test-ignore-errors*
                (with-ignored-errors (my-eval form)) ; return ERROR on errors
                (my-eval form)) ; don't disturb the condition system when testing it!
          (setq out (and *eval-out* (get-output-stream-string *eval-out*))
                err (and *eval-err* (get-output-stream-string *eval-err*)))
          (cond ((eql result my-result)
                 (format t "~&EQL-OK: ~S~%" result))
                ((equal result my-result)
                 (format t "~&EQUAL-OK: ~S~%" result))
                ((equalp result my-result)
                 (format t "~&EQUALP-OK: ~S~%" result))
                (t
                 (incf error-count)
                 (format t "~&ERROR!! ~S should be ~S !~%" my-result result)
                 (format log "~&Form: ~S~%CORRECT: ~S~%~7A: ~S~%~@[~A~%~]"
                             form result lisp-implementation
                             my-result error-message)
                 (pretty-compare result my-result log)
                 (format log "~[~*~:;OUT:~%~S~%~]~[~*~:;ERR:~%~S~]~2%"
                         (length out) out (length err) err)
                 (force-output log))))))
    (values total-count error-count)))

(defmacro check-ignore-errors (&body body)
  `(handler-case (progn ,@body)
     (type-error (c)
       (if (ignore-errors
             (typep (type-error-datum c) (type-error-expected-type c)))
           (format nil "[~S --> ~A]: ~S is of type ~S" ',body c
                   (type-error-datum c) (type-error-expected-type c))
           c))
     (stream-error (c)
       (if (streamp (stream-error-stream c)) c
           (format nil "[~S --> ~A]: ~S is not a ~S" ',body c
                   (stream-error-stream c) 'stream)))
     (file-error (c)
       (let ((path (file-error-pathname c)))
         (if (or (pathnamep path) (stringp path) (characterp path)) c
             (format nil "[~S --> ~A]: ~S is not a ~S" ',body c
                     (file-error-pathname c) 'pathname))))
     (package-error (c)
       (let ((pack (package-error-package c)))
         (if (or (packagep pack) (stringp pack) (characterp pack)) c
             (format nil "[~S --> ~A]: ~S is not a ~S" ',body c
                     (package-error-package c) 'package))))
     (cell-error (c)
       (if (cell-error-name c) c
           (format nil "[~S --> ~A]: no cell name" ',body c)))
     (error (c) c)
     (:no-error (v) (format t "~&no error, value: ~S~%" v))))

(defun do-errcheck (stream log)
  (let ((eof "EOF") (error-count 0) (total-count 0))
    (loop
      (let ((form (read stream nil eof))
            (errtype (read stream nil eof)))
        (when (or (eq form eof) (eq errtype eof)) (return))
        (incf total-count)
        (show form)
        (let ((my-result (check-ignore-errors (my-eval form)))
              (out (and *eval-out* (get-output-stream-string *eval-out*)))
              (err (and *eval-err* (get-output-stream-string *eval-err*))))
          (multiple-value-bind (typep-result typep-error)
              (ignore-errors (typep my-result errtype))
            (cond ((and (not typep-error) typep-result)
                   (format t "~&OK: ~S~%" errtype))
                  (t
                   (incf error-count)
                   (format t "~&ERROR!! ~S instead of ~S !~%" my-result errtype)
                   (format log "~&Form: ~S~%CORRECT: ~S~%~7A: ~S~%~
                                ~[~*~:;OUT:~%~S~%~]~[~*~:;ERR:~%~S~]~2%"
                               form errtype lisp-implementation my-result
                               (length out) out (length err) err)
                   (force-output log)))))))
    (values total-count error-count)))

(defvar *run-test-tester* #'do-test)
(defvar *run-test-type* "tst")
(defvar *run-test-erg* "erg")
(defvar *run-test-own-package* t)
(defun run-test (testname
                 &key ((:tester *run-test-tester*) *run-test-tester*)
                      ((:ignore-errors *test-ignore-errors*)
                        *test-ignore-errors*)
                      ((:eval-method *eval-method*) *eval-method*)
                      (logname testname)
                      ((:own-package *run-test-own-package*)
                       *run-test-own-package*)
                 &aux (logfile (merge-extension *run-test-erg* logname))
                      error-count total-count *run-test-truename*)
  (with-open-file (s (merge-extension *run-test-type* testname)
                     :direction :input)
    (setq *run-test-truename* (truename s))
    (format t "~&~s: started ~s~%" 'run-test s)
    (with-open-file (log logfile :direction :output
                                 #+(or CMU SBCL) :if-exists
                                 #+(or CMU SBCL) :supersede
                                 #+ANSI-CL :if-exists #+ANSI-CL :new-version)
      (setq logfile (truename log))
      (let* ((*package*
              (if *run-test-own-package*
                  (make-package (namestring logfile)
                                :use (cons *package*
                                           (package-use-list *package*)))
                  *package*))
             (*print-circle* t) (*print-pretty* nil)
             (*eval-err* (make-string-output-stream))
             (*error-output* (make-broadcast-stream *error-output* *eval-err*))
             (*eval-out* (make-string-output-stream))
             (*standard-output* (make-broadcast-stream *standard-output*
                                                       *eval-out*)))
        (setf (values total-count error-count)
              (funcall *run-test-tester* s log))
        (when *run-test-own-package*
          (delete-package *package*)))))
  (format t "~&~s: finished ~s (~:d error~:p out of ~:d test~:p)~%"
          'run-test testname error-count total-count)
  (if (zerop error-count)
      (delete-file logfile)
      (format t "~s: see ~a~%" 'run-test logfile))
  (list logname total-count error-count))

(defun report-results (res &key (here (truename "./")))
  "res = list of RUN-TEST return values (testname total-count error-count)"
  (let ((error-count (reduce #'+ res :key #'third)))
    (format
     t "~&finished ~3d file~:p:~31T ~3:d error~:p out of~50T ~6:d test~:p~%"
     (length res) error-count (reduce #'+ res :key #'second))
    (loop :for rec :in res :for count :upfrom 1 :do
      (format t "~&~3d ~25@a:~31T ~3:d error~:p out of~50T ~6:d test~:p~%"
              count (enough-namestring (first rec) here)
              (third rec) (second rec)))
    error-count))

;; see makemake.in:
;; (run-some-tests :dirlist '("zlib" "pcre") :srcdir "../modules/")
(defun run-some-tests (&key (dirlist '("./")) (srcdir "./") (outdir "./")
                       ((:eval-method *eval-method*) *eval-method*)
                       &aux #+clisp (custom:*merge-pathnames-ansi* t))
  "Run tst files in DIRLIST under SRCDIR, writing erg under OUTDIR."
  (let ((files (mapcan (lambda (dir)
                         (directory (make-pathname
                                     :name :wild :type *run-test-type*
                                     :defaults (merge-pathnames dir srcdir))))
                       dirlist))
        (src-true (truename srcdir)))
    (if files
        (report-results
         (mapcar (lambda (file)
                   (run-test file :logname
                             (merge-pathnames (enough-namestring file src-true)
                                              outdir)))
                 files)
         :here outdir)
        (warn "no ~S files in directories ~S" *run-test-type* dirlist))))

(defparameter *all-tests*
  '(#-(or AKCL ECL)   ("alltest")
                      ("array")
    #-OpenMCL         ("backquot")
    #+CLISP           ("bin-io")
    #-(and AKCL (not GCL)) ("characters")
    #+(or CLISP ALLEGRO CMU OpenMCL LISPWORKS) ("clos")
    #+CLISP           ("defhash")
    #+(and CLISP UNICODE) ("encoding")
                      ("eval20")
    #+CLISP           ("ext-clisp")
    #+(and CLISP FFI) ("ffi")
                      ("floeps")
    #-OpenMCL         ("format")
    #+CLISP           ("genstream")
    #+XCL             ("hash")
                      ("hashlong")
    #+CLISP           ("hashtable")
                      ("iofkts")
                      ("lambda")
                      ("lists151")
    #-(or GCL OpenMCL) ("lists152")
                      ("lists153")
                      ("lists154")
                      ("lists155")
                      ("lists156")
                      ("list-set")
    #+(or CLISP GCL ALLEGRO CMU SBCL OpenMCL LISPWORKS) ("loop")
                      ("macro8")
                      ("map")
    #+(or CLISP ALLEGRO OpenMCL LISPWORKS) ("mop")
                      ("number")
    #+CLISP           ("number2")
    #-(or AKCL ALLEGRO CMU OpenMCL) ("pack11")
    #+(or XCL CLISP)  ("path")
    #+XCL             ("readtable")
    #-CMU             ("setf")
    #+(and CLISP SOCKETS) ("socket")
                      ("steele7")
    #-ALLEGRO         ("streams")
                      ("streamslong")
                      ("strings")
    #-(or AKCL ECL)   ("symbol10")
                      ("symbols")
                      ("time")
    #+XCL             ("tprint")
    #+XCL             ("tread")
                      ("type")
    #-(or)            ("unportable")
    #+(and CLISP mt)  ("mt")
    #+CLISP           ("weak")
    #+(or CLISP ALLEGRO CMU19 OpenMCL LISPWORKS) ("weakhash")
    #+(or CLISP LISPWORKS) ("weakhash2")
                      ("bind" :eval-method :eval :logname "bind-eval")
                      ("bind" :eval-method :compile :logname "bind-compile")
    #+(or CLISP ALLEGRO CMU LISPWORKS) ("conditions" :ignore-errors nil)
    #+CLISP           ("restarts" :ignore-errors nil)
                      ("excepsit" :tester do-errcheck)
    ))

(defun test-weakptr ()
  (let ((tmp (list "weakptr" 0 0)))
    (dotimes (i 20 tmp)
      (let ((weak-res (run-test "weakptr")))
        (incf (second tmp) (second weak-res))
        (incf (third tmp) (third weak-res))))))

(defun run-all-tests (&key (disable-risky t)
                      ((:eval-method *eval-method*) *eval-method*))
  (let ((res ())
        #+CLISP (custom:*load-paths* nil)
        (*features* (if disable-risky *features*
                        (cons :enable-risky-tests *features*))))
    (dolist (args *all-tests*)
      (push (apply #'run-test args) res))
    #+(or CLISP ALLEGRO CMU SBCL LISPWORKS)
    (push (test-weakptr) res)
    (report-results (nreverse res))))

#+(and clisp mt)
(defun run-all-tests-parallel (&key (concurrency 5) (disable-risky t)
                               ((:eval-method *eval-method*) *eval-method*))
  (let ((res ()) (lock (mt:make-mutex :name "res"))
        (total (1+ (length *all-tests*)))
        (custom:*load-paths* nil)
        (*features* (if disable-risky *features*
                        (cons :enable-risky-tests *features*))))
    (macrolet ((run (body)
                 `(mt:make-thread
                   (lambda ()
                     (let ((ans ,body))
                       (mt:with-mutex-lock (lock)
                         (push ans res))))
                   :cstack-size 16777216)))
      (dolist (args *all-tests*)
        (let ((args args))
          ;; this is "poor man" concurrency control - not exact at all
          (loop until
            (>= concurrency
                (count t (mapcar #'mt:thread-active-p (mt:list-threads))))
             :do (sleep 1))
          (run (apply #'run-test args))))
      (run (test-weakptr))
      (loop :until (= total (length res)) :do (sleep 1))
      (report-results (nreverse res)))))
