;;;; csi.scm - Interpreter stub for CHICKEN
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer. 
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution. 
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission. 
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.


(declare
  (usual-integrations)
  (disable-interrupts)
  (always-bound ##sys#windows-platform)
  (foreign-declare #<<EOF
#include <signal.h>

#if defined(HAVE_DIRECT_H)
# include <direct.h>
#else
# define _getcwd(buf, len)       NULL
#endif
EOF
) )

(module chicken.csi
  (editor-command toplevel-command set-describer! default-evaluator)

(import scheme
	chicken.base
	chicken.condition
	chicken.fixnum
	chicken.foreign
	chicken.format
	chicken.file
	chicken.gc
	chicken.internal
	chicken.io
	chicken.keyword
	chicken.load
	chicken.pathname
	chicken.platform
	chicken.port
	chicken.pretty-print
	chicken.process
	chicken.process-context
	chicken.repl
	chicken.sort
	chicken.string
	chicken.syntax
	chicken.time)

(include "banner.scm")
(include "mini-srfi-1.scm")

;;; Parameters:

(define-constant init-file "csirc")

(set! ##sys#repl-print-length-limit 2048)
(set! ##sys#features (cons #:csi ##sys#features))
(set! ##sys#notices-enabled #t)

(define editor-command (make-parameter #f))
(define selected-frame #f)

(define default-editor 
  (or (get-environment-variable "EDITOR")
      (get-environment-variable "VISUAL")
      (if (get-environment-variable "EMACS")
	  "emacsclient"
	  "vi")))			; shudder


;;; Print all sorts of information:

(define (print-usage)
  (display #<<EOF
usage: csi [OPTION ...] [FILENAME ...]

  `csi' is the CHICKEN interpreter.
  
  FILENAME is a Scheme source file name with optional extension. OPTION may be
  one of the following:

    -h  -help                     display this text and exit
        -version                  display version and exit
        -release                  print release number and exit
    -i  -case-insensitive         enable case-insensitive reading
    -e  -eval EXPRESSION          evaluate given expression
    -p  -print EXPRESSION         evaluate and print result(s)
    -P  -pretty-print EXPRESSION  evaluate and print result(s) prettily
    -D  -feature SYMBOL           register feature identifier
        -no-feature SYMBOL        disable built-in feature identifier
    -q  -quiet                    do not print banner

EOF
)
  (display #<#EOF
    -n  -no-init                  do not load initialization file #{#\`} #{init-file} #{#\'}

EOF
)
  (display  #<<EOF
    -b  -batch                    terminate after command-line processing
    -w  -no-warnings              disable all warnings
    -K  -keyword-style STYLE      enable alternative keyword-syntax
                                   (prefix, suffix or none)
        -no-parentheses-synonyms  disables list delimiter synonyms
        -no-symbol-escape         disables support for escaped symbols
        -r5rs-syntax              disables the CHICKEN extensions to
                                   R5RS syntax
    -s  -script PATHNAME          use csi as interpreter for Scheme scripts
        -ss PATHNAME              same as `-s', but invoke `main' procedure
        -sx PATHNAME              same as `-s', but print each expression
                                   as it is evaluated
        -setup-mode               prefer the current directory when locating extensions
    -R  -require-extension NAME   require extension and import before
                                   executing code
    -I  -include-path PATHNAME    add PATHNAME to include path
    --                            ignore all following options

EOF
) ) ;|  <--- for emacs font-lock

(define (print-banner)
  (print +banner+ (chicken-version #t) "\n"))


;;; Chop terminating separator from pathname:

(define (dirseparator? c)
  (or (and ##sys#windows-platform (char=? c #\\))
      (char=? c #\/)))

(define chop-separator 
  (let ([substring substring] )
    (lambda (str)
      (let* ((len (sub1 (##sys#size str)))
	     (c (string-ref str len)))
	(if (and (fx> len 0) (dirseparator? c))
	    (substring str 0 len)
	    str) ) ) ) )


;;; Find script in PATH (only used for Windows/DOS):

(define lookup-script-file 
  (let* ([buf (make-string 256)]
	 [_getcwd (foreign-lambda nonnull-c-string "_getcwd" scheme-pointer int)] )
    (define (addext name)
      (if (file-exists? name)
	  name
	  (let ([n2 (string-append name ".bat")])
	    (and (file-exists? n2) n2) ) ) )
    (define (string-index proc str1)
      (let ((len (##sys#size str1)))
	(let loop ((i 0))
	  (cond ((fx>= i len) #f)
		((proc (##core#inline "C_subchar" str1 i)) i)
		(else (loop (fx+ i 1))) ) ) ) )
    (lambda (name)
      (let ([path (get-environment-variable "PATH")])
	(and (> (##sys#size name) 0)
	     (cond [(dirseparator? (string-ref name 0)) (addext name)]
		   [(string-index dirseparator? name)
		    (let ((p (_getcwd buf 256)))
		      (addext (string-append (chop-separator p) "/" name)) ) ]
		   [(addext name)]
		   [else
		    (let ([name2 (string-append "/" name)])
		      (let loop ((ps (##sys#split-path path)))
			(and (pair? ps)
			     (let ([name2 (string-append (chop-separator (##sys#slot ps 0)) name2)])
			       (or (addext name2)
				   (loop (##sys#slot ps 1)) ) ) ) ) ) ] ) ) ) ) ) )
				   


;;; REPL history references:

(define history-list (make-vector 32))
(define history-count 1)

(define history-add
  (let ([vector-resize vector-resize])
    (lambda (vals)
      (let ([x (if (null? vals) (##sys#void) (##sys#slot vals 0))]
	    [size (##sys#size history-list)] )
	(when (fx>= history-count size)
	  (set! history-list (vector-resize history-list (fx* 2 size))) )
	(vector-set! history-list history-count x)
	(set! history-count (fx+ history-count 1))
	x) ) ) )

(define (history-clear)
  (vector-fill! history-list (##sys#void)))

(define history-show
  (let ((newline newline))
    (lambda ()
      (do ((i 1 (fx+ i 1)))
	  ((>= i history-count))
	(printf "#~a: " i)
	(##sys#with-print-length-limit
	 80
	 (lambda ()
	   (##sys#print (vector-ref history-list i) #t ##sys#standard-output)))
	(newline)))))

(define (history-ref index)
  (let ([i (inexact->exact index)])
    (if (and (fx> i 0) (fx<= i history-count))
	(vector-ref history-list i) 
	(##sys#error "history entry index out of range" index) ) ) )

;;; Reader hooks for REPL history:

(define (register-repl-history!)
  (set! ##sys#user-read-hook
    (let ((old-hook ##sys#user-read-hook))
      (lambda (char port)
	(cond ((or (char=? #\) char) (char-whitespace? char))
	       `',(history-ref (fx- history-count 1)))
	      (else (old-hook char port))))))
  (set! ##sys#sharp-number-hook
    (lambda (port n) `',(history-ref n))))

(repl-prompt
 (let ((sprintf sprintf))
   (lambda ()
     (sprintf "#;~A~A> "
       (let ((m (##sys#current-module)))
	 (if m
	     (sprintf "~a:" (##sys#module-name m))
	     ""))
       history-count))))


;;; Other REPL customizations:

(define (tty-input?)
  (or (##core#inline "C_i_tty_forcedp")
      (##sys#tty-port? ##sys#standard-input)))

(set! ##sys#read-prompt-hook
  (let ([old ##sys#read-prompt-hook])
    (lambda ()
      (when (tty-input?) (old)) ) ) )

(define command-table '())

(define (toplevel-command name proc #!optional help)
  (##sys#check-symbol name 'toplevel-command)
  (when help (##sys#check-string help 'toplevel-command))
  (cond ((assq name command-table) =>
	 (lambda (a)
	   (set-cdr! a (list proc help)) ))
	(else
	 (set! command-table (cons (list name proc help) command-table))))
  (##sys#void))

(define default-evaluator
  (let ((eval eval)
	(load-noisily load-noisily)
	(read (lambda () (chicken.syntax#read-with-source-info (current-input-port)))) ; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing
	(read-line read-line)
	(display display)
	(string-split string-split)
	(printf printf)
	(expand expand)
	(pretty-print pretty-print)
	(values values) )
    (lambda (form)
      (cond ((eof-object? form) (quit))
	    ((and (pair? form)
		  (eq? 'unquote (##sys#slot form 0)) )
	     (let ((cmd (cadr form)))
	       (cond ((assq cmd command-table) =>
		      (lambda (p)
			((cadr p))
			(##sys#void) ) )
		     (else
		      ;;XXX use `toplevel-command' to define as many as possible of these
		      (case cmd
			((x)
			 (let ([x (read)])
			   (pretty-print (strip-syntax (expand x)))
			   (##sys#void) ) )
			((p)
			 (let* ([x (read)]
				[xe (eval x)] )
			   (pretty-print xe)
			   (##sys#void) ) )
			((d)
			 (let* ([x (read)]
				[xe (eval x)] )
			   (describe xe) ) )
			((du)
			 (let* ([x (read)]
				[xe (eval x)] )
			   (dump xe) ) )
			((dur)
			 (let* ([x (read)]
				[n (read)]
				[xe (eval x)] 
				[xn (eval n)] )
			   (dump xe xn) ) )
			((r) (report))
			((q) (quit))
			((l)
			 (let ((fns (string-split (read-line))))
			   (for-each load fns)
			   (##sys#void) ) )
			((ln) 
			 (let ((fns (string-split (read-line))))
			   (for-each (cut load-noisily <> printer: (lambda (x) (pretty-print x) (print* "==> "))) fns)
			   (##sys#void) ) )
			((t)
			 (let ((x (read)))
			   (receive rs (time (eval x))
			     (history-add rs)
			     (apply values rs) ) ) )
			((exn) 
			 (when ##sys#last-exception
			   (history-add (list ##sys#last-exception))
			   (describe ##sys#last-exception) ) )
			((e)
			 (let ((r (system
				   (string-append 
				    (or (editor-command) default-editor)
				    " " (read-line)))))
			   (if (not (zero? r))
			       (printf "editor returned with non-zero exit status ~a" r))))
			((ch)
			 (history-clear)
			 (##sys#void))
			((h)
			 (history-show)
			 (##sys#void))
			((c)
			 (show-frameinfo selected-frame)
			 (##sys#void))
			((f)
			 (select-frame (read))
			 (##sys#void))
			((g)
			 (copy-from-frame (read)))
			((s)
			 (let* ((str (read-line))
				(r (system str)) )
			   (history-add (list r))
			   r) )
			((?)
			 (display 
			  "Toplevel commands:

 ,?                Show this text
 ,p EXP            Pretty print evaluated expression EXP
 ,d EXP            Describe result of evaluated expression EXP
 ,du EXP           Dump data of expression EXP
 ,dur EXP N        Dump range
 ,q                Quit interpreter
 ,l FILENAME ...   Load one or more files
 ,ln FILENAME ...  Load one or more files and print result of each top-level expression
 ,r                Show system information
 ,h                Show history of expression results
 ,ch               Clear history of expression results
 ,e FILENAME       Run external editor
 ,s TEXT ...       Execute shell-command
 ,exn              Describe last exception
 ,c                Show call-chain of most recent error
 ,f N              Select frame N
 ,g NAME           Get variable NAME from current frame
 ,t EXP            Evaluate form and print elapsed time
 ,x EXP            Pretty print expanded expression EXP\n")
			 (for-each
			  (lambda (a) 
			    (let ((help (caddr a)))
			      (if help
				  (print #\space help)
				  (print " ," (car a)) ) ) )
			  command-table)
			 (##sys#void) )
			(else
			 (printf "undefined toplevel command ~s - enter `,?' for help~%" form) 
			 (##sys#void) ) ) ) ) ) )
	    (else
	     (receive rs (eval form)
	       (history-add rs)
	       (apply values rs) ) ) ) ) ) )


;;; Builtin toplevel commands:

(toplevel-command
 'm 
 (let ((printf printf))
   (lambda ()
     (let ((name (read)))
       (cond ((not name)
	      (##sys#switch-module #f)
	      (printf "; resetting current module to toplevel~%"))
	     ((##sys#find-module (##sys#resolve-module-name name #f) #f) =>
	      (lambda (m)
		(##sys#switch-module m)
		(printf "; switching current module to `~a'~%" name)))
	     (else
	      (printf "undefined module `~a'~%" name))))))
 ",m MODULE         switch to module with name `MODULE'")


;;; Parse options from string:

(define (parse-option-string str)
  (let ([ins (open-input-string str)])
    (map (lambda (o)
	   (if (string? o)
	       o
	       (let ([os (open-output-string)])
		 (write o os)
		 (get-output-string os) ) ) )
	 (handle-exceptions ex (##sys#error "invalid option syntax" str)
	   (do ([x (read ins) (read ins)]
		[xs '() (cons x xs)] )
	       ((eof-object? x) (reverse xs)) ) ) ) ) )


;;; Print status information:

(define report
  (let ((printf printf)
	(sort sort)
	(with-output-to-port with-output-to-port)
	(current-output-port current-output-port) 
	(argv argv)
	(prefix (foreign-value "C_INSTALL_PREFIX" c-string)))
    (lambda port
      (with-output-to-port (if (pair? port) (car port) (current-output-port))
	(lambda ()
	  (gc)
	  (let ((sinfo (##sys#symbol-table-info))
		(minfo (memory-statistics))
		(interrupts (foreign-value "C_interrupts_enabled" bool))
		(fixed-heap (foreign-value "C_heap_size_is_fixed" bool))
		(downward-stack (foreign-value "C_STACK_GROWS_DOWNWARD" bool)))
	    (define (shorten n) (/ (truncate (* n 100)) 100))
	    (printf "Features:~%~%")
	    (let ((fs (sort (map keyword->string ##sys#features) string<?))
		  (c 0))
	      (for-each
	       (lambda (f)
		 (printf "  ~a" f)
		 (let* ((len (string-length f))
			(pad (- 16 len)))
		   (set! c (add1 c))
		   (when (<= pad 0)
		     (set! c (add1 c))
		     (set! pad (+ pad 18)))
		   (cond ((>= c 3)
			  (display "\n")
			  (set! c 0))
			 (else 
			  (display (make-string pad #\space))))))
	       fs))
	    (printf "~%~%~
                   Machine type:    \t~A (~A-bit)~%~
                   Software type:   \t~A~%~
                   Software version:\t~A~%~
                   Build platform:  \t~A~%~
                   Installation prefix:\t~A~%~
                   Extension installation location:\t~A~%~
                   Extension path:  \t~A~%~
                   Include path:    \t~A~%~
                   Keyword style:   \t~A~%~
                   Symbol-table load:\t~S~%  ~
                     Avg bucket length:\t~S~%  ~
                     Total symbol count:\t~S~%~
                   Memory:\theap size is ~S bytes~A with ~S bytes currently in use~%~  
                     nursery size is ~S bytes, stack grows ~A~%~
                   Command line:    \t~S~%"
		    (machine-type)
		    (foreign-value "C_WORD_SIZE" int)
		    (software-type)
		    (software-version)
		    (build-platform)
		    prefix
                    (installation-repository)
		    (repository-path)
		    ##sys#include-pathnames
		    (keyword->string (keyword-style))
		    (shorten (vector-ref sinfo 0))
		    (shorten (vector-ref sinfo 1))
		    (vector-ref sinfo 2)
		    (vector-ref minfo 0)
		    (if fixed-heap " (fixed)" "")
		    (vector-ref minfo 1)
		    (vector-ref minfo 2)
		    (if downward-stack "downward" "upward")
		    (argv))
	    (##sys#write-char-0 #\newline ##sys#standard-output)
	    (when interrupts (display "interrupts are enabled\n"))
	    (##core#undefined) ) ) ) ) ) )


;;; Describe & dump:

(define bytevector-data
  '((u8vector "vector of unsigned bytes" u8vector-length u8vector-ref)
    (s8vector "vector of signed bytes" s8vector-length s8vector-ref)
    (u16vector "vector of unsigned 16-bit words" u16vector-length u16vector-ref)
    (s16vector "vector of signed 16-bit words" s16vector-length s16vector-ref)
    (u32vector "vector of unsigned 32-bit words" u32vector-length u32vector-ref)
    (s32vector "vector of signed 32-bit words" s32vector-length s32vector-ref)
    (u64vector "vector of unsigned 64-bit words" u64vector-length u64vector-ref)
    (s64vector "vector of signed 64-bit words" s64vector-length s64vector-ref)
    (f32vector "vector of 32-bit floats" f32vector-length f32vector-ref)
    (f64vector "vector of 64-bit floats" f64vector-length f64vector-ref) ) )

(define (circular-list? x)
  (let lp ((x x) (lag x))
    (and (pair? x)
	 (let ((x (cdr x)))
	   (and (pair? x)
		(let ((x   (cdr x))
		      (lag (cdr lag)))
		  (or (eq? x lag) (lp x lag))))))))

(define (improper-pairs? x)
  (let lp ((x x))
    (if (not (pair? x)) #f
       (or (eq? x (car x))
           (lp (cdr x))))))

(define-constant max-describe-lines 40)

(define describer-table (make-vector 37 '()))

(define describe
  (let ([sprintf sprintf]
	[printf printf] 
	[fprintf fprintf]
	[length length]
	[list-ref list-ref]
	[string-ref string-ref])
    (lambda (x #!optional (out ##sys#standard-output))
      (define (descseq name plen pref start)
	(let ((len (fx- (plen x) start)))
	  (when name (fprintf out "~A of length ~S~%" name len))
	  (let loop1 ((i 0))
	    (cond ((fx>= i len))
		  ((fx>= i max-describe-lines)
		   (fprintf out "~% (~A elements not displayed)~%" (fx- len i)) )
		  (else
		   (let ((v (pref x (fx+ start i))))
		     (let loop2 ((n 1) (j (fx+ i (fx+ start 1))))
		       (cond ((fx>= j len)
			      (##sys#with-print-length-limit
			       1000
			       (lambda ()
				 (fprintf out " ~S: ~S" i v)))
			      (if (fx> n 1)
				  (fprintf out "\t(followed by ~A identical instance~a)~% ...~%" 
					   (fx- n 1)
					   (if (eq? n 2) "" "s"))
				  (newline out) )
			      (loop1 (fx+ i n)) )
			     ((eq? v (pref x j)) (loop2 (fx+ n 1) (fx+ j 1)))
			     (else (loop2 n len)) ) ) ) ) ) ) ) )
      (when (##sys#permanent? x)
	(fprintf out "statically allocated (0x~X) " (##sys#block-address x)) )
      (cond ((char? x)
	     (let ([code (char->integer x)])
	       (fprintf out "character ~S, code: ~S, #x~X, #o~O~%" x code code code) ) )
	    ((eq? x #t) (fprintf out "boolean true~%"))
	    ((eq? x #f) (fprintf out "boolean false~%"))
	    ((null? x) (fprintf out "empty list~%"))
            ((##core#inline "C_bwpp" x) 
             ;; TODO: replace with bwp-object? later
             (fprintf out "broken weak pointer~%"))
	    ((eof-object? x) (fprintf out "end-of-file object~%"))
	    ((eq? (##sys#void) x) (fprintf out "unspecified object~%"))
	    ((fixnum? x)
	     (fprintf out "exact immediate integer ~S~%  #x~X~%  #o~O~%  #b~B"
	       x x x x)
	     (let ([code (integer->char x)])
	       (when (fx< x #x10000) (fprintf out ", character ~S" code)) )
	     (##sys#write-char-0 #\newline ##sys#standard-output) )
	    ((bignum? x)
	     (fprintf out "exact large integer ~S~%  #x~X~%  #o~O~%  #b~B~%"
	       x x x x) )
	    ((##core#inline "C_unboundvaluep" x)
	     (fprintf out "unbound value~%"))
	    ((flonum? x) (fprintf out "inexact rational number ~S~%" x))
	    ((ratnum? x) (fprintf out "exact ratio ~S~%" x))
	    ((cplxnum? x) (fprintf out "~A complex number ~S~%"
			    (if (exact? x) "exact" "inexact") x))
	    ((number? x) (fprintf out "number ~S~%" x))
	    ((string? x) (descseq "string" ##sys#size string-ref 0))
	    ((vector? x) (descseq "vector" ##sys#size ##sys#slot 0))
	    ((keyword? x)
	     (fprintf out "keyword symbol with name ~s~%" 
	       (##sys#symbol->string x)))
	    ((symbol? x)
	     (unless (##sys#symbol-has-toplevel-binding? x)
	       (display "unbound " out))
	     (fprintf out "~asymbol with name ~S~%"
	       (if (##sys#interned-symbol? x) "" "uninterned ")
	       (##sys#symbol->string x))
	     (let ((plist (##sys#slot x 2)))
	       (unless (null? plist)
		 (display "  \nproperties:\n\n" out)
		 (do ((plist plist (cddr plist)))
		     ((null? plist))
		   (fprintf out "  ~s\t" (car plist))
		   (##sys#with-print-length-limit
		    1000
		    (lambda ()
		      (write (cadr plist) out) ) )
		   (newline out) ) ) ) )
	    ((or (circular-list? x) (improper-pairs? x))
	     (fprintf out "circular structure: ")
	     (let loop-print ((x x)
			      (cdr-refs (list x)))
	       (cond ((or (atom? x)
			  (null? x)) (printf "eol~%"))
		     ((memq (car x) cdr-refs)
		      (fprintf out "(circle)~%" ))
		     ((not (memq (car x) cdr-refs))
		      (fprintf out "~S -> " (car x))
		      (loop-print (cdr x) (cons (car x)  cdr-refs) )))))
	    ((list? x) (descseq "list" length list-ref 0))
	    ((pair? x) (fprintf out "pair with car ~S~%and cdr ~S~%" (car x) (cdr x)))
	    ((procedure? x)
	     (let ([len (##sys#size x)])
	       (descseq 
		(sprintf "procedure with code pointer 0x~X" (##sys#peek-unsigned-integer x 0))
		##sys#size ##sys#slot 1) ) )
	    ((port? x)
	     (fprintf out
		 "~A port of type ~A with name ~S and file pointer ~X~%"
	       (if (##sys#slot x 1) "input" "output")
	       (##sys#slot x 7)
	       (##sys#slot x 3)
	       (##sys#peek-unsigned-integer x 0) ) )
            ((not (##core#inline "C_blockp" x)) 
             ;; catch immediates here, as ##sys#locative? crashes on non-block
             (fprintf out "unknown immediate object~%"))
	    ((##sys#locative? x)
	     (fprintf out "locative~%  pointer ~X~%  index ~A~%  type ~A~%"
	       (##sys#peek-unsigned-integer x 0)
	       (##sys#slot x 1)
	       (case (##sys#slot x 2) 
		 ((0) "slot")
		 ((1) "char")
		 ((2) "u8vector")
		 ((3) "s8vector")
		 ((4) "u16vector")
		 ((5) "s16vector")
		 ((6) "u32vector")
		 ((7) "s32vector")
		 ((8) "u64vector")
		 ((9) "s64vector")
		 ((10) "f32vector")
		 ((11) "f64vector") ) ) )
	    ((##sys#pointer? x) (fprintf out "machine pointer ~X~%" (##sys#peek-unsigned-integer x 0)))
	    ((##sys#bytevector? x)
	     (let ([len (##sys#size x)])
	       (fprintf out "blob of size ~S:~%" len)
	       (hexdump x len ##sys#byte out) ) )
	    ((##core#inline "C_lambdainfop" x)
	     (fprintf out "lambda information: ~s~%" (##sys#lambda-info->string x)) )
	    ((##sys#structure? x 'hash-table)
	     (let ((n (##sys#slot x 2)))
	       (fprintf out "hash-table with ~S element~a~%  comparison procedure: ~A~%"
		 n (if (fx= n 1) "" "s")  (##sys#slot x 3)) )
	     (fprintf out "  hash function: ~a~%" (##sys#slot x 4))
	     ;; this copies code out of srfi-69.scm, but we don't want to depend on it
	     (let* ((vec (##sys#slot x 1))
		    (len (##sys#size vec)) )
	       (do ((i 0 (fx+ i 1)) )
		   ((fx>= i len))
		 (for-each
		  (lambda (bucket)
		    (fprintf out " ~S\t-> ~S~%"
		      (##sys#slot bucket 0) (##sys#slot bucket 1)) )
		  (##sys#slot vec i)) ) ) )
	    ((##sys#structure? x 'condition)
	     (fprintf out "condition: ~s~%" (##sys#slot x 1))
	     (for-each
	      (lambda (k)
		(fprintf out " ~s~%" k)
		(let loop ((props (##sys#slot x 2)))
		  (unless (null? props)
		    (when (eq? k (caar props))
		      (##sys#with-print-length-limit
		       100
		       (lambda ()
			 (fprintf out "\t~s: ~s" (cdar props) (cadr props)) ))
		      (newline out))
		    (loop (cddr props)) ) ) )
	      (##sys#slot x 1) ) )
	    ((##sys#generic-structure? x)
	     (let ([st (##sys#slot x 0)])
	       (cond ((hash-table-ref describer-table st) => (cut <> x out))
		     ((assq st bytevector-data) =>
		      (lambda (data)
			(apply descseq (append (map eval (cdr data)) (list 0)))) )
		     (else
		      (fprintf out "structure of type `~S':~%" (##sys#slot x 0))
		      (descseq #f ##sys#size ##sys#slot 1) ) ) ) )
	    (else (fprintf out "unknown object~%")) )
      (##sys#void) ) ) )

(define (set-describer! tag proc)
  (##sys#check-symbol tag 'set-describer!)
  (hash-table-set! describer-table tag proc))


;;; Display hexdump:

(define dump
  (lambda (x . len-out)
    (let-optionals len-out
	([len #f]
	 [out ##sys#standard-output] )
      (define (bestlen n) (if len (min len n) n))
      (cond [(##sys#immediate? x) (##sys#error 'dump "cannot dump immediate object" x)]
	    [(##sys#bytevector? x) (hexdump x (bestlen (##sys#size x)) ##sys#byte out)]
	    [(string? x) (hexdump x (bestlen (##sys#size x)) ##sys#byte out)]
	    [(and (not (##sys#immediate? x)) (##sys#pointer? x))
	     (hexdump x 32 ##sys#peek-byte out) ]
	    [(and (##sys#generic-structure? x) (assq (##sys#slot x 0) bytevector-data))
	     (let ([bv (##sys#slot x 1)])
	       (hexdump bv (bestlen (##sys#size bv)) ##sys#byte out) ) ]
	    [else (##sys#error 'dump "cannot dump object" x)] ) ) ) )

(define hexdump
  (let ([display display]
	[string-append string-append]
	[make-string make-string]
	[write-char write-char] )
    (lambda (bv len ref out)

      (define (justify n m base lead)
	(let* ([s (number->string n base)]
	       [len (##sys#size s)] )
	  (if (fx< len m)
	      (string-append (make-string (fx- m len) lead) s)
	      s) ) )

      (do ([a 0 (fx+ a 16)])
	  ((fx>= a len))
	(display (justify a 4 10 #\space) out)
	(write-char #\: out)
	(do ([j 0 (fx+ j 1)]
	     [a a (fx+ a 1)] )
	    ((or (fx>= j 16) (fx>= a len))
	     (when (fx>= a len)
	       (let ((o (fxmod len 16)))
		 (unless (fx= o 0)
		   (do ((k (fx- 16 o) (fx- k 1)))
		       ((fx= k 0))
		     (display "   " out) ) ) ) ) ) 
	  (write-char #\space out)
	  (display (justify (ref bv a) 2 16 #\0) out) )
	(write-char #\space out)
	(do ([j 0 (fx+ j 1)]
	     [a a (fx+ a 1)] )
	    ((or (fx>= j 16) (fx>= a len)))
	  (let ([c (ref bv a)])
	    (if (and (fx>= c 32) (fx< c 128))
		(write-char (integer->char c) out)
		(write-char #\. out) ) ) ) 
	(write-char #\newline out) ) ) ) )


;;; Frame-info operations:

(define show-frameinfo
  (let ((newline newline)
	(display display))
    (lambda (fn)
      (define (prin1 x)
	(##sys#with-print-length-limit
	 100
	 (lambda ()
	   (##sys#print x #t ##sys#standard-output))))
      (let* ((ct (or ##sys#repl-recent-call-chain '()))
	     (len (length ct)))
	(set! selected-frame 
	  (or (and (memq fn ct) fn)
	      (and (fx> len 0)
		   (list-ref ct (fx- len 1)))))
	(do ((ct ct (cdr ct))
	     (i (fx- len 1) (fx- i 1)))
	    ((null? ct))
	  (let* ((info (car ct))
		 (here (eq? selected-frame info))
		 (form (##sys#slot info 1)) ; cooked1 (expr/form)
		 (data (##sys#slot info 2)) ; cooked2 (cntr/frameinfo)
		 (finfo (##sys#structure? data 'frameinfo))
		 (cntr (if finfo (##sys#slot data 1) data))) ; cntr
	    (printf "~a~a:~a\t~a\t  " 
	      (if here #\* #\space)
	      i
	      (if (and finfo (pair? (##sys#slot data 2))) "[]" "  ") ; e
	      (##sys#slot info 0))	; raw
	    (when cntr (printf "[~a] " cntr))
	    (when form (prin1 form))
	    (newline)
	    (when (and here finfo)
	      (for-each
	       (lambda (e v)
		 (unless (null? e)
		   (display "  ---\n")
		   (do ((i 0 (fx+ i 1))
			(be e (cdr be)))
		       ((null? be))
		     (printf "  ~s:\t  " (car be))
		     (prin1 (##sys#slot v i))
		     (newline))))
	       (##sys#slot data 2)	   ; e
	       (##sys#slot data 3)))))))))	   ; v
	  
(define select-frame
  (let ((display display))
    (lambda (n)
      (cond ((or (not (number? n))
		 (not ##sys#repl-recent-call-chain)
		 (fx< n 0)
		 (fx>= n (length ##sys#repl-recent-call-chain)))
	     (display "no such frame\n"))
	    (else
	     (set! selected-frame
	       (list-ref 
		##sys#repl-recent-call-chain
		(fx- (length ##sys#repl-recent-call-chain) (fx+ n 1))))
	     (show-frameinfo selected-frame))))))

(define copy-from-frame
  (let ((display display)
	(newline newline)
	(call/cc call/cc))
    (lambda (name)
      (let* ((ct (or ##sys#repl-recent-call-chain '()))
	     (len (length ct))
	     (name 
	      (cond ((symbol? name) (##sys#slot name 1)) ; name
		    ((string? name) name)
		    (else 
		     (display "string or symbol required for `,g'\n")
		     #f))))
	(define (compare sym)
	  (let ((str (##sys#slot sym 1))) ; name
	    (string=?
	     name
	     (substring str 0 (min (string-length name) (string-length str))))))
	(if name
	    (call/cc
	     (lambda (return)
	       (define (fail msg)
		 (display msg)
		 (newline)
		 (return (##sys#void)))
	       (do ((ct ct (cdr ct)))
		   ((null? ct) (fail "no environment in frame")) 
		 ;;XXX this should be refactored as it duplicates the code above
		 (let* ((info (car ct))
			(here (eq? selected-frame info))
			(data (##sys#slot info 2)) ; cooked2 (cntr/frameinfo)
			(finfo (##sys#structure? data 'frameinfo)))
		   (when (and here finfo)
		     (for-each
		      (lambda (e v)
			(do ((i 0 (fx+ i 1))
			     (be e (cdr be)))
			    ((null? be))
			  (when (compare (car be))
			    (display "; getting ")
			    (display (car be))
			    (newline)
			    (history-add (list (##sys#slot v i)))
			    (return (##sys#slot v i)))))
		      (##sys#slot data 2)	; e
		      (##sys#slot data 3))	; v
		     (fail (##sys#string-append "no such variable: " name)))))))
	    (##sys#void))))))


;;; Handle some signals:

(define-foreign-variable _sigint int "SIGINT")

(define-syntax defhandler 
  (syntax-rules ()
    ((_ sig handler)
     (begin
       (##core#inline "C_establish_signal_handler" sig sig)
       (##sys#setslot ##sys#signal-vector sig handler)))))

(defhandler _sigint (lambda (n) (##sys#user-interrupt-hook)))


;;; Start interpreting:

(define (member* keys set)
  (let loop ((set set))
    (and (pair? set)
	 (let find ((ks keys))
	   (cond ((null? ks) (loop (cdr set)))
		 ((equal? (car ks) (car set)) set)
		 (else (find (cdr ks))) ) ) ) ) )

(define-constant short-options 
  '(#\k #\s #\h #\D #\e #\i #\R #\b #\n #\q #\w #\- #\I #\p #\P #\K) )

(define-constant long-options
  '("-ss" "-sx" "-script" "-version" "-help" "--help" "-feature" "-no-feature" "-eval"
    "-case-insensitive" "-keyword-style" "-no-parentheses-synonyms" "-no-symbol-escape"
    "-r5rs-syntax" "-setup-mode"
    "-require-extension" "-batch" "-quiet" "-no-warnings" "-no-init" 
    "-include-path" "-release" "-print" "-pretty-print" "--") )

(define (canonicalize-args args)
  (let loop ((args args))
    (if (null? args)
	'()
	(let ((x (car args)))
	  (cond ((member x '("-s" "-ss" "-script" "-sx" "--")) args)
                ((and (fx= (##sys#size x) 2)
                      (char=? #\- (##core#inline "C_subchar" x 0)))
                 (if (memq (##core#inline "C_subchar" x 1) short-options)
                     (cons x (loop (cdr args)))
                     (##sys#error "invalid option" x)))
                ((and (fx> (##sys#size x) 2)
                       (char=? #\- (##core#inline "C_subchar" x 0))
                       (not (member x long-options)) )
                 (if (char=? #\: (##core#inline "C_subchar" x 1))
                     (loop (cdr args))
                     (let ((cs (string->list (substring x 1))))
                       (if (findall cs short-options)
                           (append (map (cut string #\- <>) cs) (loop (cdr args)))
                           (##sys#error "invalid option" x) ) ) ) )
	        (else (cons x (loop (cdr args)))))))))

(define (findall chars clist)
  (let loop ((chars chars))
    (or (null? chars)
	(and (memq (car chars) clist)
	     (loop (cdr chars))))))

(define-constant simple-options
  '("--" "-b" "-batch" "-q" "-quiet" "-n" "-no-init" "-w" "-no-warnings" 
    "-i" "-case-insensitive"
    "-no-parentheses-synonyms" "-no-symbol-escape" "-r5rs-syntax" "-setup-mode"
    ; Not "simple" but processed early
    "-ss" "-sx" "-s" "-script") )

(define-constant complex-options
  '("-D" "-feature" "-I" "-include-path" "-K" "-keyword-style" "-no-feature") )

(define (string-trim str)
  (let loop ((front 0)
	     (back (string-length str)))
    (cond ((= front back) "")
	  ((char-whitespace? (string-ref str front))
	   (loop (add1 front) back))
	  ((char-whitespace? (string-ref str (sub1 back)))
	   (loop front (sub1 back)))
	  (else (substring str front back)))))
   
(define (string->extension-name str)
  (let ((str (string-trim str)))
    (if (and (positive? (string-length str))
             (char=? #\( (string-ref str 0)))
        (handle-exceptions ex 
          (##sys#error "invalid import specification" str)
          (with-input-from-string str read))
        (string->symbol str))))

(define (run)
  (let* ([extraopts (parse-option-string (or (get-environment-variable "CSI_OPTIONS") ""))]
	 [args (canonicalize-args (command-line-arguments))]
	 ; Check for these before 'args' is updated by any 'extraopts'
	 [kwstyle (member* '("-K" "-keyword-style") args)]
	 [script (member* '("-ss" "-sx" "-s" "-script") args)])
    (cond [script
	   (when (or (not (pair? (cdr script)))
		     (zero? (string-length (cadr script)))
		     (char=? #\- (string-ref (cadr script) 0)) )
	     (##sys#error "missing or invalid script argument"))
	   (program-name (cadr script))
	   (command-line-arguments (cddr script))
	   ;; 2012-10-04 (felix) left 'script activated to avoid breaking too much code
	   (register-feature! 'chicken-script)
	   (set-cdr! (cdr script) '()) 
	   (when ##sys#windows-platform
	     (and-let* ((sname (lookup-script-file (cadr script))))
	       (set-car! (cdr script) sname) ) ) ]
	  [else
	   (set! args (append (canonicalize-args extraopts) args))
	   (and-let* ([p (member "--" args)])
	     (set-cdr! p '()) ) ] )
    (let* ([eval? (member* '("-e" "-p" "-P" "-eval" "-print" "-pretty-print") args)]
	   [batch (or script (member* '("-b" "-batch") args) eval?)]
	   [quietflag (member* '("-q" "-quiet") args)]
	   [quiet (or script quietflag eval?)])
      (define (collect-options opt)
	(let loop ([opts args])
	  (cond [(member opt opts)
		 => (lambda (p)
		      (if (null? (cdr p))
			  (##sys#error "missing argument to command-line option" opt)
			  (cons (cadr p) (loop (cddr p)))) ) ]
		[else '()] ) ) )
      (define (loadinit)
        (let* ((sys-dir (system-config-directory))
               (cfg-fn (and sys-dir (make-pathname (list sys-dir "chicken")
                                                   init-file)))
               (home (get-environment-variable "HOME"))
               (home-fn (and home (not (string=? home ""))
                             (make-pathname home (string-append "." init-file)))))
          (cond ((and cfg-fn (file-exists? cfg-fn))
                 (load cfg-fn))
                ((and home-fn (file-exists? home-fn))
                 (load home-fn) ) ) ) )
      (define (evalstring str #!optional (rec (lambda _ (void))))
	(let ((in (open-input-string str))
	      (read-with-source-info chicken.syntax#read-with-source-info)) ; OBSOLETE - after bootstrapping we can get rid of this explicit namespacing
	  (do ([x (read-with-source-info in) (read-with-source-info in)])
	      ((eof-object? x))
	    (rec (receive (eval x))) ) ) )
      (when (member* '("-h" "-help" "--help") args)
	(print-usage)
	(exit 0) )
      (when (member "-version" args)
	(print-banner)
	(exit 0) )
      (when (member "-setup-mode" args)
	(set! ##sys#setup-mode #t))
      (when (member "-release" args)
	(print (chicken-version))
	(exit 0) )
      (when (member* '("-w" "-no-warnings") args)
	(unless quiet (display "Warnings are disabled\n"))
	(set! ##sys#warnings-enabled #f) )
      (when (member* '("-i" "-case-insensitive") args)
	(unless quiet (display "Identifiers and symbols are case insensitive\n"))
	(register-feature! 'case-insensitive)
	(case-sensitive #f) )
      (for-each register-feature! (collect-options "-feature"))
      (for-each register-feature! (collect-options "-D"))
      (for-each unregister-feature! (collect-options "-no-feature"))
      (set! ##sys#include-pathnames
	(delete-duplicates
	 (append (map chop-separator (collect-options "-include-path"))
		 (map chop-separator (collect-options "-I"))
		 ##sys#include-pathnames)
	 string=?) )
      (when kwstyle
	(cond [(not (pair? (cdr kwstyle)))
	       (##sys#error "missing argument to `-keyword-style' option") ]
	      [(string=? "prefix" (cadr kwstyle))
	       (keyword-style #:prefix) ]
	      [(string=? "none" (cadr kwstyle))
	       (keyword-style #:none) ]
	      [(string=? "suffix" (cadr kwstyle))
	       (keyword-style #:suffix) ] ) )
      (when (member* '("-no-parentheses-synonyms") args)
	(unless quiet (display "Disabled support for parentheses synonyms\n"))
        (parentheses-synonyms #f) )
      (when (member* '("-no-symbol-escape") args)
	(unless quiet (display "Disabled support for escaped symbols\n"))
	(symbol-escape #f) )
      (when (member* '("-r5rs-syntax") args)
	(unless quiet (display "Disabled the CHICKEN extensions to R5RS syntax\n"))
	(case-sensitive #f)
	(keyword-style #:none)
	(parentheses-synonyms #f)
	(symbol-escape #f) )
      ;; Load the the default modules into the evaluation environment.
      ;; This is done before setting load-verbose => #t to avoid
      ;; spurious import messages.
      (eval `(import-for-syntax ,@default-syntax-imports))
      (eval `(import ,@default-imports))
      (unless quiet
	(load-verbose #t)
	(print-banner)
	(print "Type ,? for help."))
      (unless (or (member* '("-n" "-no-init") args) script eval?)
	(loadinit))
      (when batch
	(set! ##sys#notices-enabled #f))
      (do ([args args (cdr args)])
	  ((null? args)
	   (register-repl-history!)
	   (unless batch
	     (repl default-evaluator)
	     (##sys#write-char-0 #\newline ##sys#standard-output) ) )
	(let* ((arg (car args)))
	  (cond ((member arg simple-options))
		((member arg complex-options)
		 (set! args (cdr args)) )
		((or (string=? "-R" arg) (string=? "-require-extension" arg))
		 (eval `(import ,(string->extension-name (cadr args))))
		 (set! args (cdr args)) )
		((or (string=? "-e" arg) (string=? "-eval" arg))
		 (evalstring (cadr args))
		 (set! args (cdr args)) )
		((or (string=? "-p" arg) (string=? "-print" arg))
		 (evalstring (cadr args) (cut for-each print <...>))
		 (set! args (cdr args)) )
		((or (string=? "-P" arg) (string=? "-pretty-print" arg))
		 (evalstring (cadr args) (cut for-each pretty-print <...>) )
		 (set! args (cdr args)) )
		(else
		 (let ((scr (and script (car script))))
		   (load
		    arg
		    (and (equal? "-sx" scr)
			 (lambda (x)
			   (let* ((str (with-output-to-string (cut pretty-print x)))
				  (len (string-length str)))
			     (flush-output ##sys#standard-output)
			     (display "\n; " ##sys#standard-error)
			     (do ((i 0 (fx+ i 1)))
				 ((fx>= i len))
			       (let ((c (string-ref str i)))
				 (write-char c ##sys#standard-error)
				 (when (char=? #\newline c)
				   (display "; " ##sys#standard-error))))
			     (newline ##sys#standard-error)
			     (eval x)))))
		   (when (equal? "-ss" scr)
		     (receive rs ((eval 'main) (command-line-arguments))
		       (let ((r (optional rs)))
			 (exit (if (fixnum? r) r 0)))))))))))))

(run))
