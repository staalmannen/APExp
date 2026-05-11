(import chicken.condition chicken.file chicken.file.posix
	chicken.flonum chicken.format chicken.io chicken.port
	chicken.process chicken.process.signal chicken.tcp srfi-4)

(include "test.scm")
(test-begin "ports")

(define-syntax assert-error
  (syntax-rules ()
    ((_ expr) 
     (assert (handle-exceptions _ #t expr #f)))))

(define *text* #<<EOF
this is a test
<foof> #;33> (let ((in (open-input-string ""))) (close-input-port in)
       (read-char in)) [09:40]
<foof> Error: (read-char) port already closed: #<input port "(string)">
<foof> #;33> (let ((in (open-input-string ""))) (close-input-port in)
       (read-line in))
<foof> Error: call of non-procedure: #t
<foof> ... that's a little odd
<Bunny351> yuck. [09:44]
<Bunny351> double yuck. [10:00]
<sjamaan> yuck squared! [10:01]
<Bunny351> yuck powered by yuck
<Bunny351> (to the power of yuck, of course) [10:02]
<pbusser3> My yuck is bigger than yours!!!
<foof> yuck!
<foof> (that's a factorial)
<sjamaan> heh
<sjamaan> I think you outyucked us all [10:03]
<foof> well, for large enough values of yuck, yuck! ~= yuck^yuck [10:04]
ERC> 
EOF
)

(define p (open-input-string *text*))

(assert (string=? "this is a test" (read-line p)))

(assert
 (string=? 
  "<foof> #;33> (let ((in (open-input-string \"\"))) (close-input-port in)"
  (read-line p)))
(assert (= 20 (length (read-lines (open-input-string *text*)))))

(assert (char-ready? (open-input-string "")))

(let ((out (open-output-string)))
  (test-equal "Initially, output string is empty"
              (get-output-string out) "")
  (display "foo" out)
  (test-equal "output can be extracted from output string"
              (get-output-string out) "foo")
  (close-output-port out)
  (test-equal "closing a string output port has no effect on the returned data"
              (get-output-string out) "foo")
  (test-error "writing to a closed string output port is an error"
              (display "bar" out)))

;;; copy-port

(assert
 (string=? 
  *text*
  (with-output-to-string
    (lambda ()
      (copy-port (open-input-string *text*) (current-output-port)))))) ; read-char -> write-char

(assert 
 (equal? 
  '(3 2 1)
  (let ((out '()))
    (copy-port				; read -> custom
     (open-input-string "1 2 3")
     #f
     read
     (lambda (x port) (set! out (cons x out))))
    out)))

(assert
 (equal? 
  "abc"
  (let ((out (open-output-string)))
    (copy-port				; read-char -> custom
     (open-input-string "abc") 
     out
     read-char
     (lambda (x out) (write-char x out)))
    (get-output-string out))))

(assert
 (equal? 
  "abc"
  (let ((in (open-input-string "abc") )
	(out (open-output-string)))
    (copy-port				; custom -> write-char
     in out
     (lambda (in) (read-char in)))
    (get-output-string out))))

;; {input,output}-port-open?

(assert (input-port-open? (open-input-string "abc")))
(assert (output-port-open? (open-output-string)))
(assert-error (input-port-open? (open-output-string)))
(assert-error (output-port-open? (open-input-string "abc")))

;; direction-specific port closure

(let* ((n 0)
       (p (make-input-port (constantly #\a)
			   (constantly #t)
			   (lambda () (set! n (add1 n))))))
  (close-output-port p)
  (assert (input-port-open? p))
  (assert (= n 0))
  (close-input-port p)
  (assert (not (input-port-open? p)))
  (assert (= n 1))
  (close-input-port p)
  (assert (not (input-port-open? p)))
  (assert (= n 1)))

(let* ((n 0)
       (p (make-output-port (lambda () (display #\a))
			    (lambda () (set! n (add1 n))))))
  (close-input-port p)
  (assert (output-port-open? p))
  (assert (= n 0))
  (close-output-port p)
  (assert (not (output-port-open? p)))
  (assert (= n 1))
  (close-output-port p)
  (assert (not (output-port-open? p)))
  (assert (= n 1)))

;; bidirectional ports

(let* ((b (string))
       (w (lambda (s)
	    (set! b (string-append b s))))
       (e (lambda ()
	    (positive? (string-length b))))
       (r (lambda ()
	    (let ((s b))
	      (set! b (substring s 1))
	      (string-ref s 0))))
       (i (make-input-port r e void))
       (o (make-output-port w void))
       (p (make-bidirectional-port i o)))
  (assert (input-port? p))
  (assert (output-port? p))
  (assert (input-port-open? p))
  (assert (output-port-open? p))
  (display "quartz ruby" p)
  (newline p)
  (assert (equal? (read p) 'quartz))
  (assert (equal? (read i) 'ruby))
  (display "emerald topaz" p)
  (newline p)
  (close-output-port p)
  (assert (not (output-port-open? o)))
  (assert (not (output-port-open? p)))
  (assert (equal? (read p) 'emerald))
  (assert (equal? (read i) 'topaz))
  (close-input-port p)
  (assert (not (input-port-open? i)))
  (assert (not (input-port-open? p))))

;; fill buffers
(with-input-from-file "compiler.scm" read-string)

(print "slow...")
(time
 (with-input-from-file "compiler.scm"
   (lambda ()
     (with-output-to-file "compiler.scm.2"
       (lambda ()
	 (copy-port 
	  (current-input-port) (current-output-port)
	  (lambda (port) (read-char port))
	  (lambda (x port) (write-char x port))))))))

(print "fast...")
(time
 (with-input-from-file "compiler.scm"
   (lambda ()
     (with-output-to-file "compiler.scm.2"
       (lambda ()
	 (copy-port (current-input-port) (current-output-port)))))))

(delete-file "compiler.scm.2")

(define-syntax check
  (syntax-rules ()
    ((_ (expr-head expr-rest ...))
     (check 'expr-head (expr-head expr-rest ...)))
    ((_ name expr)
     (let ((okay (list 'okay)))
       (assert
        (eq? okay
             (condition-case
                 (begin (print* name "...")
                        (flush-output)
                        (let ((output expr))
                          (printf "FAIL [ ~S ]\n" output)))
               ((exn i/o file) (printf "OK\n") okay))))))))

(cond-expand
  ((not mingw32)

   (define proc (process-fork (lambda () (tcp-accept (tcp-listen 8080)))))

   (on-exit (lambda () (handle-exceptions exn #f (process-signal proc))))

   (print "\n\nProcedures check on TCP ports being closed\n")

   (receive (in out)
       (let lp ()
	 (condition-case (tcp-connect "localhost" 8080)
	   ((exn i/o net) (lp))))
     (close-output-port out)
     (close-input-port in)
     (check (tcp-addresses in))
     (check (tcp-port-numbers in))
     (check (tcp-abandon-port in)))	; Not sure about abandon-port

   
   ;; This tests for two bugs which occurred on NetBSD and possibly
   ;; other platforms, possibly due to multiprocessing:
   ;; read-line with EINTR would loop endlessly and process-wait would
   ;; signal a condition when interrupted rather than retrying.
   (set-signal-handler! signal/chld void) ; Should be a noop but triggers EINTR
   (receive (in out)
     (create-pipe)
     (receive (pid ok? status)
       (process-wait
        (process-fork
         (lambda ()
           (file-close in)              ; close receiving end
           (with-output-to-port (open-output-file* out)
             (lambda ()
               (display "hello, world\n")
               ;; exit prevents buffers from being discarded by implicit _exit
               (exit 0))))))
       (file-close out)                 ; close sending end
       (assert (equal? '(#t 0 ("hello, world"))
                       (list ok? status (read-lines (open-input-file* in)))))))
   )
  (else))

(print "\n\nProcedures check on output ports being closed\n")

(with-output-to-file "empty-file" void)

(call-with-output-file "empty-file"
  (lambda (out)
    (close-output-port out)
    (check (write '(foo) out))
    (check (fprintf out "blabla"))
    (check "print-call-chain" (begin (print-call-chain out) (void)))
    (check (print-error-message (make-property-condition 'exn 'message "foo") out))
    (check "print" (with-output-to-port out
		     (lambda () (print "foo"))))
    (check "print*" (with-output-to-port out
		      (lambda () (print* "foo"))))
    (check (display "foo" out))
    (check (terminal-port? out))   ; Calls isatty() on C_SCHEME_FALSE?
    (check (newline out))
    (check (write-char #\x out))
    (check (write-line "foo" out))
    (check (write-u8vector '#u8(1 2 3) out))
    ;;(check (port->fileno in))
    (check (flush-output out))

    #+(not mingw32) 
    (begin
      (check (file-test-lock out))
      (check (file-lock out))
      (check (file-lock/blocking out)))

    (check (write-byte 120 out))
    (check (write-string "foo" #f out))))

(print "\n\nProcedures check on input ports being closed\n")
(call-with-input-file "empty-file"
  (lambda (in)
    (close-input-port in)
    (check (read in))
    (check (read-char in))
    (check (char-ready? in))
    (check (peek-char in))
    ;;(check (port->fileno in))
    (check (terminal-port? in))	   ; Calls isatty() on C_SCHEME_FALSE?
    (check (read-line in 5))
    (check (read-u8vector 5 in))
    (check "read-u8vector!" (let ((dest (make-u8vector 5)))
                              (read-u8vector! 5 dest in)))
    #+(not mingw32) 
    (begin
      (check (file-test-lock in))
      (check (file-lock in))
      (check (file-lock/blocking in)))

    (check (read-byte in))
    (check (read-token (constantly #t) in))
    (check (read-string 10 in))
    (check "read-string!" (let ((buf (make-string 10)))
                            (read-string! 10 buf in) buf))))

(print "\nEmbedded NUL bytes in filenames are rejected\n")
(assert-error (with-output-to-file "embedded\x00null-byte" void))

;;; #978 -- port-position checks for read-line

(define (read-line/pos p limit)  ;; common
  (let ((s (read-line p limit)))
    (let-values (((row col) (port-position p)))
      (list s row col))))

(define (read-string-line/pos str limit)
  (read-line/pos (open-input-string str) limit))

(define (read-process-line/pos cmd args limit)
  (let-values (((i o pid) (process cmd args)))
    (let ((rc (read-line/pos i limit)))
      (close-input-port i)
      (close-output-port o)
      rc)))
(define (read-echo-line/pos str limit)
  (read-process-line/pos "echo" (list "-n" str) limit))

(define (test-port-position proc)
  (test-equal "advance row when encountering delim" 
	      (proc "abcde\nfghi" 6)
	      '("abcde" 2 0))
  (test-equal "reaching limit sets col to limit, and does not advance row"
	      (proc "abcdefghi" 6)
	      '("abcdef" 1 6))
  (test-equal "delimiter counted in limit" ;; observed behavior, strange
	      (proc "abcdef\nghi" 6)
	      '("abcdef" 1 6))
  (test-equal "EOF reached"
	      (proc "abcde" 6)
	      '("abcde" 1 5)))

(test-group
 "read-line string port position tests"
 (test-port-position read-string-line/pos))

(test-group "read-string!"
  (let ((in (open-input-string "1234567890"))
        (buf (make-string 5)))
    (test-equal "peek-char won't influence the result of read-string!"
                (peek-char in)
                #\1)
    (test-equal "read-string! won't read past buffer if given #f"
                (read-string! #f buf in)
                5)
    (test-equal "read-string! reads the requested bytes with #f"
                buf
                "12345")
    (test-equal "read-string! won't read past buffer if given #f and offset"
                (read-string! #f buf in 3)
                2)
    (test-equal "read-string! reads the requested bytes with #f and offset"
                buf
                "12367")
    (test-equal "read-string! reads until the end correctly"
                (read-string! #f buf in)
                3)
    (test-equal "read-string! leaves the buffer's tail intact"
                buf
                "89067")
    (test-equal "after peek-char at EOF, read-string! doesn't mutate the buffer"
                (begin (peek-char in)
                       (read-string! #f buf in)
                       buf)
                "89067"))
  (let ((in (open-input-string "1234567890"))
        (buf (make-string 5)))
    (test-equal "read-string! won't read past buffer if given size"
                (read-string! 10 buf in)
                5)
    (test-equal "read-string! reads the requested bytes with buffer size"
                buf
                "12345")
    (test-equal "read-string! won't read past buffer if given size and offset"
                (read-string! 10 buf in 3)
                2)
    (test-equal "read-string! reads the requested bytes with buffer size and offset"
                buf
                "12367")
    (test-equal "read-string! reads until the end correctly with buffer size"
                (read-string! 10 buf in)
                3)
    (test-equal "read-string! leaves the buffer's tail intact"
                buf
                "89067")
    (test-equal "read-string! at EOF reads nothing"
                (read-string! 10 buf in)
                0)
    (test-equal "read-string! at EOF doesn't mutate the buffer"
                buf
                "89067")))

(test-group "line endings"
  (let ((s "foo\nbar\rbaz\r\nqux")
	(f (lambda ()
	     (test-equal "\\n" (read-line) "foo")
	     (test-equal "\\r" (read-line) "bar")
	     (test-equal "\\r\\n" (read-line) "baz")
	     (test-equal "eof" (read-line) "qux"))))
    (test-group "string port"
      (with-input-from-string s f))
    (test-group "file port"
      (let ((file "mixed-line-endings"))
	(with-output-to-file file (lambda () (display s)))
	(with-input-from-file file f)
	(delete-file* file)))
    (test-group "custom port"
      (let* ((p (open-input-string s))
	     (p* (make-input-port (lambda () (read-char p))
				  (lambda () (char-ready? p))
				  (lambda () (close-input-port p)))))
	(with-input-from-port p* f)))))

;; Disabled because it requires `echo -n` for
;; the EOF test, and that is not available on all systems.
;; Uncomment locally to run.
#;
(test-group
 "read-line process port position tests"
 (test-port-position read-echo-line/pos))

;;;

(test-end)

(test-exit)
