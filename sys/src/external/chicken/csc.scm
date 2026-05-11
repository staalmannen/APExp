;;;; csc.scm - Driver program for the CHICKEN compiler - felix -*- Scheme -*-
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


(module main ()

(import scheme
	chicken.base
	chicken.file
	chicken.fixnum
	chicken.foreign
	chicken.format
	chicken.io
	chicken.pathname
	chicken.platform
	chicken.process
	chicken.process-context
	chicken.string)

(include "egg-environment.scm")
(include "mini-srfi-1.scm")

(define-foreign-variable windows-shell bool "C_WINDOWS_SHELL")
(define-foreign-variable POSTINSTALL_PROGRAM c-string "C_INSTALL_POSTINSTALL_PROGRAM")
(define-foreign-variable INSTALL_LIB_NAME c-string "C_INSTALL_LIB_NAME")
(define-foreign-variable TARGET_LIB_NAME c-string "C_TARGET_LIB_NAME")
(define host-libs (foreign-value "C_INSTALL_MORE_LIBS" c-string))
(define-foreign-variable TARGET_MORE_STATIC_LIBS c-string "C_TARGET_MORE_STATIC_LIBS")
(define-foreign-variable INSTALL_MORE_STATIC_LIBS c-string "C_INSTALL_MORE_STATIC_LIBS")
(define TARGET_CC default-cc)
(define-foreign-variable CHICKEN_PROGRAM c-string "C_CHICKEN_PROGRAM")
(define-foreign-variable TARGET_FEATURES c-string "C_TARGET_FEATURES")
(define-foreign-variable TARGET_RUN_LIB_HOME c-string "C_TARGET_RUN_LIB_HOME")
(define-foreign-variable TARGET_RC_COMPILER c-string "C_TARGET_RC_COMPILER")
(define-foreign-variable INSTALL_RC_COMPILER c-string "C_INSTALL_RC_COMPILER")
(define-foreign-variable TARGET_LDFLAGS c-string "C_TARGET_LDFLAGS")
(define-foreign-variable INSTALL_LDFLAGS c-string "C_INSTALL_LDFLAGS")
(define-foreign-variable CSC_PROGRAM c-string "C_CSC_PROGRAM")


;;; Parameters:

(define windows (eq? (software-type) 'windows))
(define mingw (eq? (software-version) 'mingw32))
(define osx (eq? (software-version) 'macosx))
(define cygwin (eq? (software-version) 'cygwin))
(define aix (eq? (build-platform) 'aix))
(define solaris (memq (software-version) '(solaris sunos)))

(define elf
  (memq (software-version) '(linux netbsd freebsd solaris openbsd hurd haiku)))

(define (stop msg . args)
  (fprintf (current-error-port) "~a: ~?~%" CSC_PROGRAM msg args)
  (exit 64) )

(define arguments (command-line-arguments))
(define cross-chicken (feature? #:cross-chicken))
(define host-mode (or (not cross-chicken) (member "-host" arguments)))

(define (back-slash->forward-slash path)
  (if windows-shell
      (string-translate path #\\ #\/)
      path))

(define (quotewrap str)
  (qs (back-slash->forward-slash (normalize-pathname str))))

(define (quotewrap-no-slash-trans str)
  (qs (normalize-pathname str)))

(define home
  (if host-mode host-sharedir default-sharedir))

(define translator
  (quotewrap (make-pathname host-bindir CHICKEN_PROGRAM)))

(define compiler (quotewrap (if host-mode host-cc default-cc)))
(define c++-compiler (quotewrap (if host-mode host-cxx default-cxx)))
(define rc-compiler (quotewrap (if host-mode INSTALL_RC_COMPILER TARGET_RC_COMPILER)))
(define linker (quotewrap (if host-mode host-cc default-cc)))
(define c++-linker (quotewrap (if host-mode host-cxx default-cxx)))
(define object-extension (if mingw "obj" "o"))
(define library-extension "a")
(define link-output-flag "-o ")
(define executable-extension "")
(define compile-output-flag "-o ")
(define shared-library-extension ##sys#load-dynamic-extension)
(define static-object-extension (##sys#string-append "static." object-extension))
(define static-library-extension (##sys#string-append "static." library-extension))
(define default-translation-optimization-options '())
(define pic-options (if (or mingw cygwin) '("-DPIC") '("-fPIC" "-DPIC")))
(define generate-manifest #f)

(define (libchicken)
  (string-append "lib"
                 (if (not host-mode)
                     TARGET_LIB_NAME
                     INSTALL_LIB_NAME)))

(define (dynamic-libchicken)
  (if cygwin
      (string-append "cyg" INSTALL_LIB_NAME "-0")  ; XXX not target
      (libchicken)))

(define (default-library)
  (make-pathname library-dir (libchicken) library-extension))

(define default-compilation-optimization-options
  (string-split (if host-mode host-cflags default-cflags)))

(define best-compilation-optimization-options 
  default-compilation-optimization-options)

(define default-linking-optimization-options
  (string-split (if host-mode INSTALL_LDFLAGS TARGET_LDFLAGS)))

(define best-linking-optimization-options
  default-linking-optimization-options)

(define extra-features (if host-mode '() (string-split TARGET_FEATURES)))

(define-constant simple-options
  '(-explicit-use -no-trace -no-warnings -no-usual-integrations -optimize-leaf-routines -unsafe
    -block -disable-interrupts -fixnum-arithmetic -to-stdout -profile -raw -accumulate-profile
    -check-syntax -case-insensitive -shared -compile-syntax -no-lambda-info
    -dynamic -disable-stack-overflow-checks -local
    -emit-external-prototypes-first -inline -release 
    -analyze-only -keep-shadowed-macros -inline-global -ignore-repository
    -no-symbol-escape -no-parentheses-synonyms -r5rs-syntax
    -no-argc-checks -no-bound-checks -no-procedure-checks -no-compiler-syntax
    -emit-all-import-libraries -no-elevation -module-registration -no-module-registration
    -no-procedure-checks-for-usual-bindings -regenerate-import-libraries
    -specialize -strict-types -clustering -lfa2 -debug-info
    -no-procedure-checks-for-toplevel-bindings))

(define-constant complex-options
  '(-debug -heap-size -nursery -stack-size -compiler -unit -uses -keyword-style
    -optimize-level -include-path -database-size -extend -prelude -postlude -prologue -epilogue -emit-link-file
    -inline-limit -profile-name -unroll-limit
    -emit-inline-file -consult-inline-file
    -emit-types-file -consult-types-file
    -feature -debug-level
    -emit-import-library
    -module -link
    -no-feature))

(define-constant shortcuts
  '((-h "-help")
    (-s "-shared")
    (-m "-module")
    (|-P| "-check-syntax")
    (-f "-fixnum-arithmetic")
    (|-D| "-feature")
    (-i "-case-insensitive")
    (|-K| "-keyword-style")
    (|-X| "-extend")
    (|-J| "-emit-all-import-libraries")
    (|-M| "-module-registration")
    (|-N| "-no-module-registration")
    (-x "-explicit-use")
    (-u "-unsafe")
    (-j "-emit-import-library")
    (-b "-block")
    (-types "-consult-types-file")))

;; TODO is this up-to-date?
(define short-options
  (string->list "PHhsfiENxubvwAOeWkctgSJM") )


;;; Variables:

(define scheme-files '())
(define c-files '())
(define rc-files '())
(define generated-c-files '())
(define generated-rc-files '())
(define object-files '())
(define generated-object-files '())
(define transient-link-files '())
(define linked-extensions '())
(define cpp-mode #f)
(define objc-mode #f)
(define embedded #f)
(define inquiry-only #f)
(define show-cflags #f)
(define show-ldflags #f)
(define show-libs #f)
(define dry-run #f)
(define gui #f)
(define deployed #f)
(define rpath #f)
(define ignore-repository #f)
(define show-debugging-help #f)

(define library-dir
  (if host-mode host-libdir default-libdir))

(define extra-libraries
  (if host-mode
      INSTALL_MORE_STATIC_LIBS
      TARGET_MORE_STATIC_LIBS))

(define extra-shared-libraries 
  (if host-mode host-libs default-libs))

(define (default-library-files)
  (list (string-append "-l" (if host-mode INSTALL_LIB_NAME TARGET_LIB_NAME))))

(define (library-files) (list (default-library)))
(define (shared-library-files) (default-library-files))

(define translate-options '())

(define include-dir
  (let ((id (if host-mode host-incdir default-incdir)))
    (and (not (member id '("/usr/include" "")))
	 id) ) )

(define compile-options '())

(define builtin-compile-options
  (append
   (if include-dir (list (conc "-I" include-dir)) '())
   (cond ((get-environment-variable "CHICKEN_C_INCLUDE_PATH") => 
	  (lambda (path) 
	    (map (cut string-append "-I" <>) (map quotewrap (string-split path ":;")))))
	 (else '()))))

(define compile-only-flag "-c")
(define translation-optimization-options default-translation-optimization-options)
(define compilation-optimization-options default-compilation-optimization-options)
(define linking-optimization-options default-linking-optimization-options)

(define link-options '())
(define rpath-option (if solaris "-R" "-rpath="))

(define (builtin-link-options)
  (append
   (cond (elf
	  (list
	   (conc "-L" library-dir)
	   (conc "-Wl," rpath-option
		 (if deployed
		     "$ORIGIN"
		     (if host-mode
			 host-libdir
			 TARGET_RUN_LIB_HOME)))))
	 (aix
	  (list (conc "-Wl," rpath-option "\"" library-dir "\"")))
	 (else
	  (list (conc "-L" library-dir))))
   (if (and deployed (memq (software-version) '(freebsd openbsd netbsd)))
       (list "-Wl,-z,origin")
       '())
   (cond ((get-environment-variable "CHICKEN_C_LIBRARY_PATH") => 
	  (lambda (path) 
	    (map (cut string-append "-L" <>) (string-split path ":;"))))
	 (else '()))))
	
(define target-filename #f)
(define verbose #f)
(define keep-files #f)
(define translate-only #f)
(define compile-only #f)
(define to-stdout #f)
(define shared #f)
(define static #f)


;;; Locate object files for linking:

(define (repo-path)
  (if host-mode
      (repository-path)
      (destination-repository 'target)))

(define (find-object-file name)
  (let ((o (make-pathname #f name object-extension))
	(a (make-pathname #f name library-extension))
	;; In setup mode, objects in build dir may also end with "static.o"
	(static-a (make-pathname #f name static-library-extension))
	(static-o (make-pathname #f name static-object-extension)))
    (or (file-exists? a)
	(file-exists? o)
	(and (eq? ##sys#setup-mode #t)
	     (or (file-exists? static-a)
		 (file-exists? static-o)))
	(and (not ignore-repository)
	     (or (chicken.load#find-file a (repo-path))
		 (chicken.load#find-file o (repo-path)))))))


;;; Display usage information:

(define (usage)
  (let ((csc CSC_PROGRAM))
    (print #<#EOF
Usage: #{csc} [OPTION ...] [FILENAME ...]

  `#{csc}' is a driver program for the CHICKEN compiler. Files given on the
  command line are translated, compiled or linked as needed.

  FILENAME is a Scheme source file name with optional extension or a
  C/C++/Objective-C source, object or library file name with extension. OPTION
  may be one of the following:

  General options:

    -h  -help                      display this text and exit
    -v  -verbose                   show compiler notes and tool-invocations
    -vv                            display information about translation
                                    progress
    -vvv                           display information about all compilation
                                    stages
    -version                       display Scheme compiler version and exit
    -release                       display release number and exit

  File and pathname options:

    -o -output-file FILENAME       specifies target executable name
    -I -include-path PATHNAME      specifies alternative path for included
                                    files
    -to-stdout                     write compiler to stdout (implies -t)
    -s -shared -dynamic            generate dynamically loadable shared object
                                    file

  Language options:

    -D  -DSYMBOL  -feature SYMBOL  register feature identifier
    -no-feature SYMBOL             disable builtin feature identifier
    -c++                           compile via a C++ source file (.cpp) 
    -objc                          compile via Objective-C source file (.m)

  Syntax related options:

    -i -case-insensitive           don't preserve case of read symbols    
    -K -keyword-style STYLE        enable alternative keyword-syntax
                                    (prefix, suffix or none)
       -no-parentheses-synonyms    disables list delimiter synonyms
       -no-symbol-escape           disables support for escaped symbols
       -r5rs-syntax                disables the CHICKEN extensions to
                                    R5RS syntax
    -compile-syntax                macros are made available at run-time
    -j -emit-import-library MODULE write compile-time module information into
                                    separate file
    -J -emit-all-import-libraries  emit import-libraries for all defined modules
    -no-compiler-syntax            disable expansion of compiler-macros
    -m -module NAME                wrap compiled code in a module
    -M -module-registration        always generate module registration code
    -N -no-module-registration     never generate module registration code
                                    (overrides `-M')

  Translation options:

    -x  -explicit-use              do not use units `library' and `eval' by
                                    default
    -P  -check-syntax              stop compilation after macro-expansion
    -A  -analyze-only              stop compilation after first analysis pass

  Debugging options:

    -w  -no-warnings               disable warnings
    -d0 -d1 -d2 -d3 -debug-level NUMBER
                                   set level of available debugging information
    -no-trace                      disable rudimentary debugging information
    -debug-info                    enable debug-information in compiled code for use
                                    with an external debugger
    -profile                       executable emits profiling information 
    -accumulate-profile            executable emits profiling information in
                                    append mode
    -profile-name FILENAME         name of the generated profile information
                                    file
    -consult-types-file FILENAME   load additional type database

  Optimization options:

    -O -O0 -O1 -O2 -O3 -O4 -O5 -optimize-level NUMBER
                                   enable certain sets of optimization options
    -optimize-leaf-routines        enable leaf routine optimization
    -no-usual-integrations         standard procedures may be redefined
    -u  -unsafe                    disable safety checks
    -local                         assume globals are only modified in current
                                    file
    -b  -block                     enable block-compilation
    -disable-interrupts            disable interrupts in compiled code
    -f  -fixnum-arithmetic         assume all numbers are fixnums
    -disable-stack-overflow-checks disables detection of stack-overflows
    -inline                        enable inlining
    -inline-limit LIMIT            set inlining threshold
    -inline-global                 enable cross-module inlining
    -specialize                    perform type-based specialization of primitive calls
    -oi -emit-inline-file FILENAME generate file with globally inlinable
                                    procedures (implies -inline -local)
    -consult-inline-file FILENAME  explicitly load inline file
    -ot  -emit-types-file FILENAME write type-declaration information into file
    -no-argc-checks                disable argument count checks
    -no-bound-checks               disable bound variable checks
    -no-procedure-checks           disable procedure call checks
    -no-procedure-checks-for-usual-bindings
                                   disable procedure call checks only for usual
                                    bindings
    -no-procedure-checks-for-toplevel-bindings
                                   disable procedure call checks for toplevel
                                    bindings
    -strict-types                  assume variable do not change their type
    -clustering                    combine groups of local procedures into dispatch
                                     loop
    -lfa2                          perform additional lightweight flow-analysis pass
    -unroll-limit LIMIT          specifies inlining limit for self-recursive calls

  Configuration options:

    -unit NAME                     compile file as a library unit
    -uses NAME                     declare library unit as used.
    -heap-size NUMBER              specifies heap-size of compiled executable
    -nursery NUMBER  -stack-size NUMBER
                                   specifies nursery size of compiled
                                   executable
    -X -extend FILENAME            load file before compilation commences
    -prelude EXPRESSION            add expression to beginning of source file
    -postlude EXPRESSION           add expression to end of source file
    -prologue FILENAME             include file before main source file
    -epilogue FILENAME             include file after main source file

    -e  -embedded                  compile as embedded
                                    (don't generate `main()')
    -gui                           compile as GUI application
    -link NAME                     link extension with compiled executable
                                    (implies -uses)
    -R  -require-extension NAME    require extension and import in compiled
                                    code
    -dll -library                  compile multiple units into a dynamic
                                    library
    -libdir DIRECTORY              override directory for runtime library

  Options to other passes:

    -C OPTION                      pass option to C compiler
    -L OPTION                      pass option to linker
    -I<DIR>                        pass \"-I<DIR>\" to C compiler
                                    (add include path)
    -L<DIR>                        pass \"-L<DIR>\" to linker
                                    (add library path)
    -k                             keep intermediate files
    -c                             stop after compilation to object files
    -t                             stop after translation to C
    -cc COMPILER                   select other C compiler than the default
    -cxx COMPILER                  select other C++ compiler than the default
    -ld COMPILER                   select other linker than the default 
    -static                        link with static CHICKEN libraries and
                                    extensions (if possible)
    -F<DIR>                        pass \"-F<DIR>\" to C compiler
                                    (add framework header path on Mac OS X)
    -framework NAME                passed to linker on Mac OS X
    -rpath PATHNAME                add directory to runtime library search path
    -Wl,...                        pass linker options
    -strip                         strip resulting binary

  Inquiry options:

    -home                          show home-directory (where support files go)
    -cflags                        show required C-compiler flags and exit
    -ldflags                       show required linker flags and exit
    -libs                          show required libraries and exit
    -cc-name                       show name of default C compiler used
    -cxx-name                      show name of default C++ compiler used
    -ld-name                       show name of default linker used
    -dry-run                       just show commands executed, don't run them
                                    (implies `-v')

  Obscure options:

    -debug MODES                   display debugging output for the given modes
    -compiler PATHNAME             use other compiler than default `chicken'
    -raw                           do not generate implicit init- and exit code
    -emit-external-prototypes-first
                                   emit prototypes for callbacks before foreign
                                    declarations
    -regenerate-import-libraries   emit import libraries even when unchanged
    -ignore-repository             do not refer to repository for extensions
    -keep-shadowed-macros          do not remove shadowed macro
    -host                          compile for host when configured for
                                    cross-compiling
    -private-repository            load extensions from executable path
    -deployed                      link support file to be used from a deployed 
                                    executable (sets `rpath' accordingly, if supported
                                    on this platform)
    -no-elevation                  embed manifest on Windows to supress elevation
                                    warnings for programs named `install' or `setup'

  Options can be collapsed if unambiguous, so

    -vkfO

  is the same as

    -v -k -fixnum-arithmetic -optimize

  The contents of the environment variable CSC_OPTIONS are implicitly passed to
  every invocation of `#{csc}'.

EOF
;|        (for emacs font-lock)
  ) ) )


;;; Parse arguments:

(define (run args)

  (define (t-options . os)
    (set! translate-options (append translate-options os)) )

  (define (check o r . n)
    (unless (>= (length r) (optional n 1))
      (stop "not enough arguments to option `~A'" o) ) )

  (define (shared-build lib)
    (set! translate-options (cons* "-feature" "chicken-compile-shared" translate-options))
    (set! compile-options (append pic-options '("-DC_SHARED") compile-options))
    (set! link-options
      (append
	(cond
          (osx (if lib '("-dynamiclib") '("-bundle" "-headerpad_max_install_names")))
          (else '("-shared"))) link-options))
    (set! shared #t) )

  (define (use-private-repository)
    (set! compile-options (cons "-DC_PRIVATE_REPOSITORY" compile-options)))

  (define (generate-target-filename source-filename)
    (pathname-replace-extension
     source-filename
     (cond (shared shared-library-extension)
	   (compile-only object-extension)
	   (else executable-extension))))

  (let loop ((args args))
    (cond [(null? args)
	   ;; Builtin search directory options do not override explicit options
           (set! compile-options (append compile-options builtin-compile-options))
           (set! link-options (append link-options (builtin-link-options)))
	   ;;
	   (when inquiry-only
	     (when show-cflags (print* (compiler-options) #\space))
	     (when show-ldflags (print* (linker-options) #\space))
	     (when show-libs (print* (linker-libraries) #\space))
	     (newline)
	     (exit) )
	   (when (and compile-only
		      (> (+ (length scheme-files)
			    (length c-files))
			 1))
	     (stop "the `-c' option cannot be used in combination with multiple input files"))
	   (cond ((null? scheme-files)
		  (when (and (null? c-files)
			     (null? object-files))
		    (when show-debugging-help
		      (command
		       (string-intersperse
			(cons* translator "bogus.scm" translate-options))))
		    (stop "no source files specified") )
		  (unless target-filename
		    (set! target-filename
		      (generate-target-filename
		       (last (if (null? c-files) object-files c-files))))))
		 (else
		  (when (and shared (not embedded))
		    (set! translate-options (cons "-dynamic" translate-options)) )
		  (unless target-filename
		    (set! target-filename
		      (generate-target-filename (first scheme-files))))
		  (run-translation)))
	   (unless translate-only 
	     (run-compilation)
	     (unless compile-only
	       (when (pair? linked-extensions)
		 (set! object-files ; add objects from linked extensions
		   (append (filter-map find-object-file linked-extensions) object-files)))
	       (when (member target-filename scheme-files)
		 (fprintf (current-error-port)
                          "Warning: output file will overwrite source file `~A' - renaming source to `~A.old'~%"
			 target-filename target-filename)
		 (command 
		  (sprintf
		      "~A ~A ~A" 
		      (if windows-shell "move" "mv")
		    ((if windows-shell quotewrap-no-slash-trans quotewrap) target-filename)
		    ((if windows-shell quotewrap-no-slash-trans quotewrap) (string-append target-filename ".old")))))
	       (run-linking)) ) ]
	  [else
	   (let* ([arg (car args)]
		  [rest (cdr args)]
		  [s (string->symbol arg)] )
	     (case s
	       [(-help --help)
		(usage)
		(exit) ]
	       [(-release)
		(print (chicken-version))
		(exit) ]
	       [(-version)
		(system (sprintf "~a ~a" translator " -version"))
		(exit)]
	       [(-c++) 
		(set! cpp-mode #t)
		(when osx (set! compile-options (cons "-no-cpp-precomp" compile-options))) ]
	       [(-objc) 
		(set! objc-mode #t) ]
	       [(-static)
		(set! translate-options (cons "-static" translate-options))
		(set! static #t)]
	       [(-cflags)
		(set! inquiry-only #t) 
		(set! show-cflags #t) ]
	       [(-ldflags)
		(set! inquiry-only #t)
		(set! show-ldflags #t) ]
	       [(-cc-name) (print compiler) (exit 0)]
	       [(-cxx-name) (print c++-compiler) (exit 0)]
	       [(-ld-name) (print linker) (exit 0)]
	       [(-home) (print home) (exit 0)]
	       [(-libs)
		(set! inquiry-only #t)
		(set! show-libs #t) ]
	       ((-v -verbose)
		(when (number? verbose)
		  (set! compile-options (cons* "-v" "-Q" compile-options))
		  (set! link-options (cons "-v" link-options)) )
		(t-options "-verbose")
		(if verbose
		    (set! verbose 2)
		    (set! verbose #t)) )
	       [(-w -no-warnings)
		(set! compile-options (cons "-w" compile-options))
		(t-options "-no-warnings") ]
	       [(|-A| -analyze-only)
		(set! translate-only #t)
		(t-options "-analyze-only") ]
	       [(|-P| -check-syntax)
		(set! translate-only #t)
		(t-options "-check-syntax") ]
	       [(-k) (set! keep-files #t)]
	       [(-c) (set! compile-only #t)]
	       [(-t) (set! translate-only #t)]
	       [(-e -embedded)
		(set! embedded #t)
		(set! compile-options (cons "-DC_EMBEDDED" compile-options)) ]
	       [(-link)
		(check s rest)
		(t-options "-link" (car rest))
		(set! linked-extensions
		  (append linked-extensions (string-split (car rest) ", ")))
		(set! rest (cdr rest))]
               ((-libdir)
                (check s rest)
                (set! library-dir (car rest))
                (set! rest (cdr rest)))
	       [(-require-extension -R)
		(check s rest)
		(t-options "-require-extension" (car rest))
		(set! rest (cdr rest)) ]
	       ((-private-repository)
		(use-private-repository))
	       ((-ignore-repository)
		(set! ignore-repository #t)
		(t-options arg))
	       ((-setup-mode)
		(set! ##sys#setup-mode #t)
		(t-options arg))
	       ((-no-elevation)
		(set! generate-manifest #t))
	       [(-gui)
		(set! gui #t)
		(set! compile-options (cons "-DC_GUI" compile-options))
		(when mingw
		  (set! object-files 
		    (cons (make-pathname 
			   host-sharedir "chicken.rc"
			   object-extension) 
			  object-files))
		  (set! link-options
		    (cons* "-lkernel32" "-luser32" "-lgdi32" "-mwindows"
			   link-options)))]
	       ((-deployed)
		(set! deployed #t))
	       [(-framework)
		(check s rest)
		(when osx 
		  (set! link-options (cons* "-framework" (car rest) link-options)) )
		(set! rest (cdr rest)) ]
	       [(-o -output-file)
		(check s rest)
		(let ([fn (car rest)])
		  (set! rest (cdr rest))
		  (set! target-filename fn) ) ]
	       [(|-O| |-O1|) (set! rest (cons* "-optimize-level" "1" rest))]
	       [(|-O0|) (set! rest (cons* "-optimize-level" "0" rest))]
	       [(|-O2|) (set! rest (cons* "-optimize-level" "2" rest))]
	       [(|-O3|) (set! rest (cons* "-optimize-level" "3" rest))]
	       [(|-O4|) (set! rest (cons* "-optimize-level" "4" rest))]
	       [(|-O5|)
		(set! rest (cons* "-optimize-level" "5" rest))]
	       [(|-d0|) (set! rest (cons* "-debug-level" "0" rest))]
	       [(|-d1|) (set! rest (cons* "-debug-level" "1" rest))]
	       [(|-d2|) (set! rest (cons* "-debug-level" "2" rest))]
	       [(|-d3|) (set! rest (cons* "-debug-level" "3" rest))]
	       ((-debug)
		(check s rest)
		(t-options arg (car rest))
		(when (memv #\h (string->list (car rest)))
		  (set! show-debugging-help #t)
		  (set! translate-only #t))
		(set! rest (cdr rest)))
	       [(-dry-run) 
		(set! verbose #t)
		(set! dry-run #t)]
	       [(-s -shared -dynamic)
		(shared-build #f) ]
	       [(-dll -library)
		(shared-build #t) ]
	       [(-compiler)
		(check s rest)
		(set! translator (car rest))
		(set! rest (cdr rest)) ]
	       [(-cc)
		(check s rest)
		(set! compiler (car rest))
		(set! rest (cdr rest)) ]
	       [(-cxx)
		(check s rest)
		(set! c++-compiler (car rest))
		(set! rest (cdr rest)) ]
	       [(-ld)
		(check s rest)
		(set! linker (car rest))
		(set! rest (cdr rest)) ]
	       [(|-I|)
		(check s rest)
		(set! rest (cons* "-include-path" (car rest) (cdr rest))) ]
	       [(|-C|)
		(check s rest)
		(set! compile-options (append compile-options (string-split (car rest))))
		(set! rest (cdr rest)) ]
	       [(-strip)
		(set! link-options (append link-options (list "-s")))]
	       [(|-L|)
		(check s rest)
		(set! link-options (append link-options (string-split (car rest))))
		(set! rest (cdr rest)) ]
	       [(-rpath)
		(check s rest)
		(set! rpath (car rest))
		(when (and (memq (build-platform) '(gnu clang))
			   (not mingw) (not osx))
		  (set! link-options
                    (append link-options (list (string-append "-Wl," rpath-option rpath)))) )
	  	(set! rest (cdr rest)) ]
	       [(-host) #f]
	       ((-oi) 
		(check s rest)
		(t-options "-emit-inline-file" (car rest))
		(set! rest (cdr rest)))
	       ((-ot) 
		(check s rest)
		(t-options "-emit-types-file" (car rest))
		(set! rest (cdr rest)))
	       [(-) 
		(set! scheme-files (append scheme-files '("-")))
		(unless target-filename
		  (set! target-filename (make-pathname #f "a" executable-extension)))]
	       [else
		(when (eq? s '-to-stdout) 
		  (set! to-stdout #t)
		  (set! translate-only #t) )
		(when (memq s '(-optimize-level -benchmark-mode))
		  (set! compilation-optimization-options best-compilation-optimization-options)
		  (set! linking-optimization-options best-linking-optimization-options) )
		(cond [(assq s shortcuts) => (lambda (a) (set! rest (cons (cadr a) rest)))]
		      [(memq s simple-options) (t-options arg)]
		      ((memq s complex-options)
		       (check s rest)
		       (t-options arg (car rest))
		       (set! rest (cdr rest)))
		      [(and (> (string-length arg) 2) (string=? "-:" (substring arg 0 2)))
		       (t-options arg) ]
		      [(and (> (string-length arg) 1)
			    (char=? #\- (string-ref arg 0)) )
		       (cond [(char=? #\L (string-ref arg 1))
			      (when (char-whitespace? (string-ref arg 2))
				    (error "bad -L argument, <DIR> starts with whitespace" arg))
 			      (set! link-options (append link-options (list arg))) ]
 			     [(char=? #\I (string-ref arg 1))
			      (when (char-whitespace? (string-ref arg 2))
				    (error "bad -I argument: <DIR> starts with whitespace" arg))
 			      (set! compile-options (append compile-options (list arg))) ]
			     [(char=? #\D (string-ref arg 1))
			      (t-options "-feature" (substring arg 2)) ]
			     [(char=? #\F (string-ref arg 1))
			      (when osx
				(set! compile-options (append compile-options (list arg))) ) ]
			     [(and (> (string-length arg) 3) (string=? "-Wl," (substring arg 0 4)))
			      (set! link-options (append link-options (list arg))) ]
			     [(> (string-length arg) 2)
			      (let ([opts (cdr (string->list arg))])
				(cond ((null? (lset-difference/eq? opts short-options))
				       (set! rest
					 (append (map (lambda (o)
							(string-append "-" (string o))) opts) 
						 rest) ))
				      ((char=? #\l (car opts))
				       (stop "invalid option `~A' - did you mean `-L -l<library>'?" arg))
				      (else (stop "invalid option `~A'" arg) ) )) ]
			     [else (stop "invalid option `~A'" s)] ) ]
		      [(file-exists? arg)
		       (let-values ([(dirs name ext) (decompose-pathname arg)])
			 (cond [(not ext)
				(set! scheme-files (append scheme-files (list arg)))]
			       [(member ext '("h" "c"))
				(set! c-files (append c-files (list arg))) ]
			       ((string-ci=? ext "rc")
				(set! rc-files (append rc-files (list arg))) )
			       [(member ext '("cpp" "C" "cc" "cxx" "hpp"))
				(when osx (set! compile-options (cons "-no-cpp-precomp" compile-options)))
				(set! cpp-mode #t)
				(set! c-files (append c-files (list arg))) ]
			       [(member ext '("m" "M" "mm"))
				(set! objc-mode #t)
				(set! c-files (append c-files (list arg))) ]
			       [(or (string=? ext object-extension)
				    (string=? ext library-extension) )
				(set! object-files (append object-files (list arg))) ]
			       [else (set! scheme-files (append scheme-files (list arg)))] ) ) ]
		      [else
		       (let ([f2 (string-append arg ".scm")])
			 (if (file-exists? f2)
			     (set! rest (cons f2 rest))
			     (stop "file `~A' does not exist" arg) ) ) ] ) ] )
	     (loop rest) ) ] ) ) )


;;; Translate all Scheme files:

(define (run-translation)
  (for-each
   (lambda (f)
     (let* ((sf (if (= 1 (length scheme-files))
		    target-filename
		    f))
	    (fc (pathname-replace-extension
		 sf
		 (cond (cpp-mode "cpp")
		       (objc-mode "m")
		       (else "c") ) ) ) )
       (when (member fc c-files)
	 (stop "C file generated from `~a' will overwrite explicitly given source file `~a'"
	       f fc))
       (command
	(string-intersperse 
	 (cons* translator (quotewrap f) 
		(append 
		 (if to-stdout 
		     '("-to-stdout")
		     `("-output-file" ,(quotewrap fc)) )
		 (if (##sys#debug-mode?)
		     '("-:d")
		     '())
		 (map quote-option
		      (append 
		       extra-features
		       translate-options 
                       (if (and static
                                (not (member "-emit-link-file"
                                             translate-options)))
                           (list "-emit-link-file"
                                 (pathname-replace-extension fc "link"))
                           '())
		       (cond (cpp-mode '("-feature" "chicken-scheme-to-c++"))
			     (objc-mode '("-feature" "chicken-scheme-to-objc"))
			     (else '()))
		       translation-optimization-options)) ) )
	 " ") )
       (when (and static compile-only)
         (set! transient-link-files 
           (cons (pathname-replace-extension f "link")
                 transient-link-files)))
       (set! c-files (append (list fc) c-files))
       (set! generated-c-files (append (list fc) generated-c-files))))
   scheme-files))


;;; Compile all C/C++  and .rc files:

(define (run-compilation)
  (let ((ofiles '()))
    (for-each
     (lambda (f)
       (let ((fo (if (and compile-only
                          target-filename
                          (= 1 (length c-files)))
                     target-filename
                     (pathname-replace-extension f object-extension))))
	 (when (member fo object-files)
	   (stop "object file generated from `~a' will overwrite explicitly given object file `~a'"
		 f fo))
	 (command
	  (string-intersperse
	   (list (cond (cpp-mode c++-compiler)
		       (else compiler) )
		 (quotewrap f)
		 (string-append compile-output-flag (quotewrap fo))
		 compile-only-flag
		 (if (and cpp-mode (string=? "g++" c++-compiler))
		     "-Wno-write-strings"
		     "")
		 (compiler-options) ) ) )
	 (set! generated-object-files (cons fo generated-object-files))
	 (set! ofiles (cons fo ofiles))))
     c-files)
    (when (and generate-manifest (eq? 'windows (software-type)))
      (let ((rcf (pathname-replace-extension target-filename "rc")))
	(create-win-manifest (pathname-file target-filename) rcf)
	(set! rc-files (cons rcf rc-files))
	(set! generated-rc-files (cons rcf generated-rc-files))))
    (for-each
     (lambda (f)
       (let ((fo (string-append f "." object-extension)))
	 (command
	  (string-intersperse
	   (list rc-compiler (quotewrap f) (quotewrap fo))))
	 (set! generated-object-files (cons fo generated-object-files))
	 (set! ofiles (cons fo ofiles))))
     rc-files)
    (set! object-files (append (reverse ofiles) object-files)) ; put generated object files first
    (unless keep-files 
      (for-each $delete-file generated-c-files)
      (for-each $delete-file generated-rc-files))))

(define (compiler-options)
  (string-intersperse
   (map quote-option
	(append
	 compilation-optimization-options
	 compile-options) ) ) )


;;; Link object files and libraries:

(define (run-linking)
  (set! object-files
    (collect-linked-objects object-files generated-object-files))
  (let* ((files (map quotewrap object-files))
	 (target (quotewrap target-filename))
	 (targetdir #f))
    (command
     (string-intersperse 
      (cons* (cond (cpp-mode c++-linker)
		   (else linker) )
	     (append
	      files
	      (list (string-append link-output-flag (quotewrap target-filename))
		    (linker-options)
		    (linker-libraries) ) ) ) ) )
    (when (and osx host-mode)
      (command
       (string-append
	POSTINSTALL_PROGRAM " -change " (libchicken) ".dylib "
	(quotewrap 
	 (let ((lib (string-append (libchicken) ".dylib")))
	   (if deployed
	       (make-pathname "@executable_path" lib)
	       (make-pathname (if host-mode
                                  host-libdir
                                  TARGET_RUN_LIB_HOME)
                       lib))))
	" " 
	target) ))
    (unless keep-files 
      (for-each $delete-file
        (append generated-object-files
                transient-link-files)))))

(define (collect-linked-objects ofiles gen-ofiles)
  (define (locate-link-file o)
    (let* ((p (pathname-strip-extension o))
	   ;; Also strip "static.o" extension when in setup mode:
	   (f (if ##sys#setup-mode (string-chomp p ".static") p)))
      (file-exists? (make-pathname #f f "link"))))
  (define (locate-objects libs)
    (map (lambda (id)
	   (or (find-object-file id)
	       (stop "could not find linked extension: ~A" id)))
	 (map ->string libs)))
  (let loop ((os ofiles) (os2 ofiles))
    (cond ((null? os)
           (delete-duplicates (reverse os2) string=?))
          ((or static (not (member (car os) gen-ofiles)))
           (let* ((lfile (locate-link-file (car os)))
                  (newos (if lfile
                             (locate-objects (with-input-from-file lfile read))
                             '())))
             (loop (append newos (cdr os)) (append newos os2))))
          (else (loop (cdr os) (cons (car os) os2))))))

(define (copy-files from to)
  (command
   (sprintf "~a ~a ~a"
     (if windows-shell 
	 "copy /Y"
	 "cp")
     ((if windows-shell quotewrap-no-slash-trans quotewrap) from)
     ((if windows-shell quotewrap-no-slash-trans quotewrap) to))))

(define (linker-options)
  (string-intersperse
   (map quote-option
	(append linking-optimization-options link-options) ) ) )

(define (linker-libraries)
  (string-intersperse
   (append
    (if static
        (library-files)
        (shared-library-files))
    (if static
        (list extra-libraries)
        (list extra-shared-libraries)))))


;;; Helper procedures:

;; Simpler replacement for SRFI-13's string-any
(define (string-any criteria s)
  (let ((end (string-length s)))
    (let lp ((i 0))
      (let ((c (string-ref s i))
            (i1 (+ i 1)))
        (if (= i1 end) (criteria c)
            (or (criteria c)
                (lp i1)))))))

(define quote-option qs)

(define last-exit-code #f)

(define ($system str)
  (let ((str (cond (windows-shell
		    (string-append "\"" str "\""))
		   ((and osx (get-environment-variable "DYLD_LIBRARY_PATH"))
		    => (lambda (path)
			 (string-append "/usr/bin/env DYLD_LIBRARY_PATH="
					(qs path) " " str)))
		   (else str))))
    (when verbose (print str))
    (let ((raw-exit-code (if dry-run 0 (system str))))
      (unless (zero? raw-exit-code)
	(printf "\nError: shell command terminated with non-zero exit status ~S: ~A~%" raw-exit-code str))
      (set! last-exit-code
	(if (zero? raw-exit-code) 0 1))
      last-exit-code)))

(define (command str)
  (unless (zero? ($system str))
    (exit last-exit-code)))

(define ($delete-file str)
  (when verbose 
    (print "rm " str) )
  (unless dry-run (delete-file str) ))

(define (create-win-manifest prg rcfname)
  (when verbose (print "generating " rcfname))
  (with-output-to-file rcfname
    (lambda ()
      (print #<#EOF
1 24 MOVEABLE PURE
BEGIN
  "<?xml version=""1.0"" encoding=""UTF-8"" standalone=""yes""?>\r\n"
  "<assembly xmlns=""urn:schemas-microsoft-com:asm.v1"" manifestVersion=""1.0"">\r\n"
  "  <assemblyIdentity version=""1.0.0.0"" processorArchitecture=""*"" name=""#{prg}"" type=""win32""/>\r\n"
  "  <ms_asmv2:trustInfo xmlns:ms_asmv2=""urn:schemas-microsoft-com:asm.v2"">\r\n"
  "    <ms_asmv2:security>\r\n"
  "      <ms_asmv2:requestedPrivileges>\r\n"
  "        <ms_asmv2:requestedExecutionLevel level=""asInvoker"" uiAccess=""false""/>\r\n"
  "      </ms_asmv2:requestedPrivileges>\r\n"
  "    </ms_asmv2:security>\r\n"
  "  </ms_asmv2:trustInfo>\r\n"
  "</assembly>\r\n"
END
EOF
) ) ) )


;;; Run it:

(run
 (append 
  (string-split (or (get-environment-variable "CSC_OPTIONS") "")) 
  arguments))

)
