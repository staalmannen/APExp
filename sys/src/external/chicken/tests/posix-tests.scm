(import (chicken bitwise)
	(chicken pathname)
        (chicken file)
        (chicken file posix)
        (chicken platform)
        (chicken process)
        (chicken process-context)
        (chicken memory representation))

(include "programs-path.scm")

(define-syntax assert-error
  (syntax-rules ()
    ((_ expr) 
     (assert (handle-exceptions _ #t expr #f)))))

(define-constant SOME-POS 123456)

(let ((tnpfilpn (create-temporary-file)))
  (let ((tmpfilno (file-open tnpfilpn (+ open/rdwr open/creat open/text))))
    (set-file-position! tmpfilno SOME-POS seek/end)
    (assert (= SOME-POS (file-position tmpfilno)))
    (file-close tmpfilno)
    (delete-file* tnpfilpn) ) )

(let ((tnpfilpn (create-temporary-file)))
  (let ((tmpfilno (file-open tnpfilpn (+ open/rdwr open/creat open/text))))
    (let ((port (open-output-file* tmpfilno)))
      (set-file-position! port SOME-POS seek/end)
      (assert (= SOME-POS (file-position port)))
      (close-output-port port)
      (delete-file* tnpfilpn) ) ) )

(assert-error (get-environment-variable "with\x00embedded-NUL"))
(assert-error (set-environment-variable! "with\x00embedded-NUL" "blabla"))
(assert-error (set-environment-variable! "blabla" "with\x00embedded-NUL"))
(assert-error (system "echo this is \x00 not okay"))
;; Use "false" to signal to the calling script that there was an error,
;; even if the process will get called
(assert-error (process-execute "false\x00123"))
(assert-error (process-execute "false" '("1" "123\x00456")))
(assert-error (process-execute "false" '("123\x00456") '("foo\x00bar" "blabla") '("lalala" "qux\x00mooh")))

(receive (in out pid)
    (process csi-path '("-n" "-I" ".." "-e"
                        "(write 'err (current-error-port)) (write 'ok)"))
  (assert (equal? 'ok (read in)))
  (newline (current-error-port)))

(receive (in out pid err)
    (process* csi-path '("-n" "-I" ".." "-e"
                         "(write 'err (current-error-port)) (write 'ok)"))
  (assert (equal? 'ok (read in)))
  (assert (equal? 'err (read err))))

;; delete-directory
(let* ((t (create-temporary-directory))
       (t/a (make-pathname t "a"))
       (t/a/file (make-pathname t/a "file"))
       (t/b (make-pathname t "b"))
       (t/b/c (make-pathname t/b "c"))
       (t/b/c/link (make-pathname t/b/c "link"))
       (t/b/c/.file (make-pathname t/b/c ".file")))
  ;; Create file under a:
  (create-directory t/a)
  (with-output-to-file t/a/file void)
  ;; Create directories under b:
  (create-directory t/b/c/.file 'recursively)
  (assert (directory? t/b/c/.file))
  (when (or (feature? #:unix) (feature? #:cygwin))
    (create-symbolic-link t/a t/b/c/link)
    (assert (directory? t/b/c/link)))
  ;; Delete directory tree at b:
  (delete-directory t/b 'recursively)
  (assert (not (directory? t/b/c/.file)))
  (assert (not (directory? t/b/c/link)))
  (assert (not (directory? t/b/c)))
  (assert (not (directory? t/b)))
  ;; Make sure symlink wasn't followed:
  (assert (directory? t/a))
  (assert (regular-file? t/a/file))
  ;; Clean up temporary directory:
  (delete-directory t 'recursively)
  (assert (not (directory? t))))

;; unset-environment-variable!
(set-environment-variable! "FOO" "bar")
(assert (equal? (get-environment-variable "FOO") "bar"))
(unset-environment-variable! "FOO")
(assert (not (get-environment-variable "FOO")))

;; file creation and umask interaction

;; For windows, the file must be writable before it can be deleted!
(define (delete-maybe-readonly-file filename)
  (cond-expand
    (windows (when (file-exists? filename)
	       (set-file-permissions! filename #o666)))
    (else))
  (delete-file* filename))

#+(not windows)
(letrec-syntax ((test (syntax-rules ()
                        ((test umask expected)
                         (test umask "expected" expected "given"))
                        ((test umask given expected)
                         (test umask "expected" expected "given" given))
                        ((test umask "expected" expected "given" given ...)
                         (let ((mode (file-creation-mode)))
                           (set! (file-creation-mode) umask)
                           (delete-file* "posix-tests.out")
                           (file-close (file-open "posix-tests.out" open/creat given ...))
                           (assert (equal? (file-permissions "posix-tests.out") expected))
                           (set! (file-creation-mode) mode))))))
  ;; default file mode
  (test #o000 #o666)
  (test #o002 #o664)
  (test #o020 #o646)
  (test #o022 #o644)
  (test #o027 #o640)
  (test #o072 #o604)
  (test #o077 #o600)
  (test #o777 #o000)
  ;; explicit file mode argument
  (test #o000 #o644 #o644)
  (test #o002 #o644 #o644)
  (test #o020 #o644 #o644)
  (test #o022 #o644 #o644)
  (test #o027 #o644 #o640)
  (test #o072 #o644 #o604)
  (test #o077 #o644 #o600)
  (test #o777 #o644 #o000)
  (test #o000 #o777 #o777)
  (test #o002 #o777 #o775)
  (test #o020 #o777 #o757)
  (test #o022 #o777 #o755)
  (test #o027 #o777 #o750)
  (test #o072 #o777 #o705)
  (test #o077 #o777 #o700)
  (test #o777 #o777 #o000))
