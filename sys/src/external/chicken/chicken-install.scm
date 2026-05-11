;;;; chicken-install.scm
;
; Copyright (c) 2008-2022, The CHICKEN Team
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
  (uses chicken-ffi-syntax)) ; populate ##sys#chicken-ffi-macro-environment

(module main ()

(import (scheme))
(import (chicken base))
(import (chicken condition))
(import (chicken foreign))
(import (chicken keyword))
(import (chicken file))
(import (chicken file posix))
(import (chicken fixnum))
(import (chicken format))
(import (chicken irregex))
(import (chicken module))
(import (chicken tcp))
(import (chicken port))
(import (chicken platform))
(import (chicken internal))
(import (chicken io))
(import (chicken sort))
(import (chicken time))
(import (chicken pathname))
(import (chicken process))
(import (chicken process-context))
(import (chicken pretty-print))
(import (chicken string))

(define +defaults-version+ 2)
(define +module-db+ "modules.db")
(define +defaults-file+ "setup.defaults")
(define +short-options+ '(#\h #\k #\s #\r #\n #\u #\v))
(define +one-hour+ (* 60 60))
(define +internal-modules+ '(chicken.internal chicken.internal.syntax))

(include "mini-srfi-1.scm")
(include "egg-environment.scm")
(include "egg-information.scm")
(include "egg-compile.scm")
(include "egg-download.scm")

(define user-defaults #f)
(define quiet #t)
(define default-servers '())
(define default-locations '())
(define mappings '())
(define aliases '())
(define override '())
(define hacks '())
(define proxy-host #f)
(define proxy-port #f)
(define proxy-user-pass #f)
(define retrieve-only #f)
(define retrieve-recursive #f)
(define do-not-build #f)
(define no-install #f)
(define no-install-dependencies #f)
(define list-versions-only #f)
(define canonical-eggs '())
(define requested-eggs '())
(define dependencies '())
(define checked-eggs '())
(define run-tests #f)
(define force-install #f)
(define host-extension cross-chicken)
(define target-extension cross-chicken)
(define sudo-install #f)
(define sudo-program (or (get-environment-variable "SUDO") "sudo"))
(define update-module-db #f)
(define purge-mode #f)
(define keepfiles #f)
(define print-repository #f)
(define cached-only #f)

(define platform
  (if (eq? (software-version) 'mingw32) 'windows 'unix))

(define current-status 
  (list ##sys#build-id default-prefix
        (get-environment-variable "CSC_OPTIONS")
        (get-environment-variable "LD_LIBRARY_PATH")
        (get-environment-variable "DYLD_LIBRARY_PATH")
        (get-environment-variable "CHICKEN_INCLUDE_PATH")
        (get-environment-variable "DYLD_LIBRARY_PATH")))

(define (repo-path)
  (if (and cross-chicken (not host-extension))
      (##sys#split-path (destination-repository 'target))
      (repository-path)))

(define (install-path)
  (if (and cross-chicken (not host-extension))
      (destination-repository 'target)
      (destination-repository 'host)))

(define (build-script-extension mode platform)
  (string-append "build"
                 (if (eq? mode 'target) ".target" "")
                 (if (eq? platform 'windows) ".bat" ".sh")))

(define (install-script-extension mode platform)
  (string-append "install"
                 (if (eq? mode 'target) ".target" "")
                 (if (eq? platform 'windows) ".bat" ".sh")))


;;; validate egg-information tree

(define (egg-version? v)
  (and (list? v) 
       (pair? v)
       (null? (cdr v))
       (let ((str (->string (car v))))
         (irregex-match '(seq (+ numeric) 
                              (? #\. (+ numeric)
                                 (? #\. (+ numeric))))
                        str))))

(define (optname? x)
  (and (list? x) 
       (or (null? x)
           (string? (car x))
           (symbol? (car x)))))

(define (nameprop? x)
  (and (list? x) (or (symbol? (car x)) (string? (car x)))))

(define (name-or-predefd? x)
  (or (optname? x)
      (and (pair? x)
           (pair? (car x))
           (eq? 'predefined (caar x))
           (optname? (cdar x)))))

;; ENTRY = (NAME TOPLEVEL? NESTED? NAMED? [VALIDATOR])
(define egg-info-items
  `((synopsis #t #f #f)
    (author #t #f #f)
    (category #t #f #f)
    (license #t #f #f)
    (version #t #f #f ,egg-version?)
    (dependencies #t #f #f ,list?)
    (source-dependencies #f #f #f ,list?)
    (component-dependencies #f #f #f ,list?)
    (test-dependencies #t #f #f ,list?)
    (build-dependencies #t #f #f ,list?)
    (components #t #t #f)
    (foreign-dependencies #t #f #f ,list?)
    (platform #t #f #f)
    (installed-files #t #f #f ,list?)
    (maintainer #t #f #f)
    (files #f #f #f ,list?)
    (distribution-files #t #f #f ,list?) ;; handled by henrietta-cache
    (source #f #f #f)
    (csc-options #f #f #f)
    (link-options #f #f #f)
    (custom-build #f #f #f)
    (linkage #f #f #f)
    (objects #f #f #f)
    (destination #f #f #f ,list?)
    (install-name #f #f #f ,nameprop?)
    (target #f #t #f)
    (host #f #t #f)
    (types-file #f #f #f ,name-or-predefd?)
    (inline-file #f #f #f ,optname?)
    (extension #f #t #t)
    (c-object #f #t #t)
    (generated-source-file #f #t #t)
    (program #f #t #t)
    (data #f #t #t)
    (modules #f #f #f)
    (component-options #t #f #f)
    (cond-expand * #t #f)
    (error * #f #f)
    (c-include #f #f #t)
    (scheme-include #f #f #t)))

(define (validate-egg-info info)
  (define (validate info top?)
    (for-each
      (lambda (item)
        (cond ((or (not (pair? item)) 
                   (not (list? item)) 
                   (not (symbol? (car item))))
               (error "invalid egg information item" item))
              ((assq (car item) egg-info-items) =>
               (lambda (a)
                 (apply (lambda (name toplevel nested named #!optional validator)
                          (cond ((and top? 
                                      (not (eq? toplevel '*))
                                      (not toplevel))
                                 (error "egg information item not allowed at toplevel" 
                                        item))
                                ((and (not (eq? toplevel '*))
                                      toplevel
                                      (not top?))
                                 (error "egg information item only allowed at toplevel" item))
                                ((and named
                                      (or (null? (cdr item))
                                          (not (symbol? (cadr item)))))
                                 (error "unnamed egg information item" item))
                                ((and validator
                                      (not (validator (cdr item))))
                                 (error "egg information item has invalid structure" item)))
                          (when nested
                            (cond (named (validate (cddr item) #f))
                                  ((eq? name 'cond-expand)
                                   (for-each
                                     (lambda (clause)
                                       (unless (and (list? clause)
                                                    (>= (length clause) 1))
                                         (error "invalid syntax in `cond-expand' clause" clause))
                                       (validate (cdr clause) top?))
                                     (cdr item)))
                                  (else (validate (cdr item) #f)))))
                        a)))
              (else (error "unknown egg information item" item))))
      info))
  (validate info #t)
  info)


;; utilities

;; Simpler replacement for SRFI-13's "string-suffix?"
(define (string-suffix? suffix s)
  (let ((len-s (string-length s))
        (len-suffix (string-length suffix)))
     (and (not (< len-s len-suffix))
          (string=? suffix
   	            (substring s (- len-s len-suffix))))))

(define (d flag . args)
  (let ((flag (and (not (string? flag)) flag))
        (fstr (if (string? flag) flag (car args)))
        (args (if (string? flag) args (cdr args))))
    (when (or flag (not quiet))
      (flush-output)
      (let ((port (current-error-port)))
        (apply fprintf port fstr args)
        (flush-output port) ) )))

(define (version>=? v1 v2)
  (define (version->list v)
    (map (lambda (x) (or (string->number x) x))
	 (irregex-split "[-\\._]" (->string v))))
  (let loop ((p1 (version->list v1))
	     (p2 (version->list v2)))
    (cond ((null? p1) (null? p2))
	  ((null? p2))
	  ((number? (car p1))
	   (and (number? (car p2))
		(or (> (car p1) (car p2))
		    (and (= (car p1) (car p2))
			 (loop (cdr p1) (cdr p2))))))
	  ((number? (car p2)))
	  ((string>? (car p1) (car p2)))
	  (else
	   (and (string=? (car p1) (car p2))
		(loop (cdr p1) (cdr p2)))))))


;; load defaults file ("setup.defaults")

(define (load-defaults)
  (let* ((cfg-dir (system-config-directory))
         (user-file (and cfg-dir (make-pathname (list cfg-dir "chicken")
                                                +defaults-file+)))
         (deff (or user-defaults
                   (and user-file (file-exists? user-file))
                   (make-pathname host-sharedir +defaults-file+))))
      (define (broken x)
	(error "invalid entry in defaults file" deff x))
      (cond ((not (file-exists? deff)) '())
            (else
	     (for-each
	      (lambda (x)
		(unless (and (list? x) (positive? (length x)))
		  (broken x))
		(case (car x)
		  ((version)
		   (cond ((not (pair? (cdr x))) (broken x))
			 ((not (= (cadr x) +defaults-version+))
			  (error 
			   (sprintf 
			       "version of installed `~a' does not match chicken-install version (~a)"
			     +defaults-file+
			     +defaults-version+)
			   (cadr x)))
			 ;; others are ignored
			 ))
		  ((server)
		   (set! default-servers
		     (append default-servers (cdr x))))
		  ((map)
		   (set! mappings
		     (append
		      mappings
		      (map (lambda (m)
			     (let ((p (list-index (cut eq? '-> <>) m)))
			       (unless p (broken x))
			       (let-values (((from to) (split-at m p)))
				 (cons from (cdr to)))))
			   (cdr x)))))
		  ((alias)
		   (set! aliases
		     (append 
		      aliases
		      (map (lambda (a)
			     (if (and (list? a) (= 2 (length a)) (every string? a))
				 (cons (car a) (cadr a))
				 (broken x)))
			   (cdr x)))))
		  ((override)
		   (set! override
		     (if (and (pair? (cdr x)) (string? (cadr x)))
			 (call-with-input-file (cadr x) read-list)
			 (cdr x))))
                  ((location)
                   (set! default-locations
                     (append default-locations (cdr x))))
		  ((hack)
		   (set! hacks (append hacks (list (eval (cadr x))))))
		  (else (broken x))))
	      (call-with-input-file deff read-list))))))

  
;; set variables with HTTP proxy information
  
(define (setup-proxy uri)
  (and-let* (((string? uri))
             (m (irregex-match "(http://)?([^:]+):?([0-9]*)" uri))
             (port (irregex-match-substring m 3)))
    (set! proxy-user-pass (get-environment-variable "proxy_auth"))
    (set! proxy-host (irregex-match-substring m 2))
    (set! proxy-port (or (string->number port) 80))))

  
;; apply egg->egg mappings loaded from defaults

(define (canonical x)
  (cond ((symbol? x) (cons (symbol->string x) #f))
        ((string? x) (cons x #f))
        ((pair? x) x)
        (else (error "internal error - bad egg spec" x))))

(define (apply-mappings eggs)
  (define (same? e1 e2)
    (equal? (car (canonical e1)) (car (canonical e2))))
  (let ((eggs2
         (delete-duplicates
           (append-map
             (lambda (egg)
               (cond ((find (lambda (m) (find (cut same? egg <>) (car m)))
                        mappings) => 
                      (lambda (m) (map ->string (cdr m))))
                 (else (list egg))))
             eggs)
           same?)))
    (unless (and (= (length eggs) (length eggs2))
                 (every (lambda (egg) 
                          (find (cut same? <> egg) eggs2)) 
                        eggs))
      (d "mapped ~s to ~s~%" eggs eggs2))
    eggs2))

  
;; override versions, if specified in "overrides" file
  
(define (override-version egg)
  (let ((name (string->symbol (if (pair? egg) (car egg) egg))))
    (cond ((assq name override) =>
           (lambda (a)
             (if (and (pair? egg)
                      (pair? (cdr a))
                      (not (equal? (cadr a) (cdr egg))))
                 (warning
                  (sprintf
                   "version `~a' of extension `~a' overrides explicitly given version `~a'"
                   (cadr a) name (cdr egg)))
                 (d "overriding: ~a~%" a))
             (if (null? (cdr a))
                 (and (pair? egg) (cdr egg))
                 (cadr a))))
          ((pair? egg) (cdr egg))
          (else #f))))
  
  
;; "locate" egg: either perform HTTP download or copy from a file-system 
;; location, also make sure it is up to date
  
(define (locate-egg name version)
  (let* ((cached (make-pathname cache-directory name))
         (metadata-dir (make-pathname cache-metadata-directory name))
         (now (current-seconds))
         (status (make-pathname metadata-dir +status-file+))
         (eggfile (make-pathname cached name +egg-extension+)))
    (define (fetch lax)
      (when (file-exists? cached)
        (delete-directory cached #t))
      (when (file-exists? metadata-dir)
        (delete-directory metadata-dir #t))
      (create-directory cached #t)
      (create-directory metadata-dir #t)
      (fetch-egg-sources name version cached lax))
    (cond ((and (probe-dir cached)
                (not (file-exists? status)))
           ;; If for whatever reason the status file doesn't exist
           ;; (e.g., it was renamed, as in 2f6a7221), reset the cache
           ;; of the egg to prevent the object files in there from
           ;; being reused.
           (d "resetting ~a, as ~a does not exist~%" cached status)
           (fetch #f))
	  ((or (not (probe-dir cached))
               (not (file-exists? eggfile)))
           (d "~a not cached~%" name)
           (when cached-only (error "extension not cached" name))
           (fetch #f))
          ((and (file-exists? status)
                (not (equal? current-status 
                             (with-input-from-file status read))))
           (d "status changed for ~a~%" name)
           (cond (cached-only
                   (if force-install
                       (warning "cached egg does not match CHICKEN version" name)
                       (error "cached egg does not match CHICKEN version - use `-force' to install anyway" name)))
                 (else (fetch #f)))))
    (let* ((info (validate-egg-info (load-egg-info eggfile)))
           (vfile (make-pathname metadata-dir +version-file+))
           (tfile (make-pathname metadata-dir +timestamp-file+))
           (lversion (or (get-egg-property info 'version)
                         (and (file-exists? vfile)
                              (with-input-from-file vfile read)))))
      (cond ((and (not cached-only)
                  (if (string? version)
                      (not (equal? version lversion))
                      (or (and (file-exists? tfile)
                               (> (- now (with-input-from-file tfile read)) +one-hour+))
                          (not (check-remote-version name lversion cached)))))
             (d "version of ~a out of date~%" name)
             (fetch #t)
             (let* ((info (validate-egg-info (load-egg-info eggfile))) ; new egg info (fetched)
                    (lversion (or (get-egg-property info 'version)
                                  (and (file-exists? vfile)
                                       (with-input-from-file vfile read)))))
               (values cached lversion)))
            (else (values cached version))))))
    
(define (resolve-location name)
  (cond ((assoc name aliases) => 
         (lambda (a)
           (let ((new (cdr a)))
             (d "resolving alias `~a' to: ~a~%" name new)
             (resolve-location new))))
        (else name)))

(define (locate-local-egg-dir location egg-name version)
  ;; Locate the directory of egg-name, considering the following
  ;; directory layouts in order:
  ;; * <location>/<egg-name>/<egg-name>.egg
  ;; * <location>/<egg-name>/<version>/<egg-name>.egg
  ;;
  ;; Return (values <egg-dir> <version>).  <egg-dir> and <version>
  ;; will be #f in case they cannot be determined.
  (let ((egg-dir (probe-dir (make-pathname location egg-name))))
    (cond
     ((not egg-dir)
      (values #f #f))
     ;; <location>/<egg-name>/<egg-name>.egg
     ((file-exists? (make-pathname egg-dir egg-name +egg-extension+))
      (values egg-dir #f))
     (else
      ;; <location>/<egg-name>/<version>/<egg-name>.egg
      (if version
          (values (probe-dir (make-pathname egg-dir (->string version)))
                  version)
          (let ((versions (directory egg-dir)))
            (if (null? versions)
                (values #f #f)
                (let ((latest (car (sort versions version>=?))))
                  (values (make-pathname egg-dir (->string latest))
                          latest)))))))))

(define (write-cache-metadata egg egg-version)
  (let ((metadata-dir (make-pathname cache-metadata-directory egg)))
    (when egg-version
      (with-output-to-file (make-pathname metadata-dir +version-file+)
        (cut write egg-version)))
    (with-output-to-file (make-pathname metadata-dir +timestamp-file+)
      (cut write (current-seconds)))
    (with-output-to-file (make-pathname metadata-dir +status-file+)
      (cut write current-status))))

(define (fetch-egg-sources name version dest lax)
  (print "fetching " name)
  (let loop ((locs default-locations))
    (cond ((null? locs)
           (let ((tmpdir (create-temporary-directory)))
             (let loop ((srvs (map resolve-location default-servers)))
               (if (null? srvs) 
                   (if lax
                       (print "no connection to server or egg not found remotely - will use cached version")
                       (begin
                         (delete-directory dest)
                         (delete-directory tmpdir)
                         (error "extension or version not found" name)))
                   (begin
                     (d "trying server ~a ...~%" (car srvs)) 
                     (receive (dir ver)
                       (try-download name (car srvs)
                                     version: version 
                                     destination: tmpdir
                                     tests: #t ;; Always fetch tests, otherwise cached eggs can't be tested later
                                     proxy-host: proxy-host
                                     proxy-port: proxy-port 
                                     proxy-user-pass: proxy-user-pass)
                       (cond (dir
                               (copy-egg-sources tmpdir dest)
                               (delete-directory tmpdir #t)
			       (write-cache-metadata name ver))
                             (else (loop (cdr srvs))))))))))
          (else
           (receive (dir version-from-path)
               (locate-local-egg-dir (car locs) name version)
             (if dir
                 (let* ((eggfile (make-pathname dir name +egg-extension+))
                        (info (validate-egg-info (load-egg-info eggfile)))
                        (rversion
                         ;; If version-from-path is non-#f, prefer it
                         ;; over rversion, as it means the egg author
                         ;; actually tagged the egg.  rversion might
                         ;; be outdated in case the egg author forgot
                         ;; to bump it in the .egg file.
                         (or version-from-path
                             (get-egg-property info 'version))))
                   (d "trying location ~a ...~%" dir)
                   (if (or (not rversion)
                           (not version)
                           (version>=? rversion version))
                       (begin
                         (copy-egg-sources dir dest)
                         (write-cache-metadata name (or rversion version)))
                       (loop (cdr locs))))
                 (loop (cdr locs))))))))


(define (copy-egg-sources from to)
  ;;XXX should probably be done manually, instead of calling tool
  (let ((cmd (string-append
	      (copy-directory-command platform)
	      ;; Don't quote the globbing character!
	      " " (make-pathname (qs* from platform #t) "*")
	      " " (qs* to platform #t))))
    (d "~a~%" cmd)
    (system+ cmd platform)))
  
(define (check-remote-version name lversion cached)
  (let loop ((locs default-locations))
    (cond ((null? locs)
           (let loop ((srvs (map resolve-location default-servers)))
             (and (pair? srvs)
                  (let ((versions (try-list-versions name (car srvs))))
                    (or (and versions
                             (every (cut version>=? lversion <>) versions))
                        (loop (cdr srvs)))))))
          ;; The order of probe-dir's here is important.  First try
          ;; the path with version, then the path without version.
          ((or (probe-dir (make-pathname (list (car locs) name)
                                         (->string lversion)))
               (probe-dir (make-pathname (car locs) name)))
           => (lambda (dir)
                ;; for locally available eggs, check set of files and
                ;; timestamps
                (compare-trees dir cached)))
          (else (loop (cdr locs))))))

(define (compare-trees there here)
  (let walk ((there there)
             (here here))
    (let ((tfs (directory there))
          (hfs (directory here)))
      (every (lambda (f) 
               (and (member f hfs)
                    (let ((tf2 (make-pathname there f))
                          (hf2 (make-pathname here f)))
                      (and (<= (file-modification-time tf2)
                               (file-modification-time hf2))
                           (if (directory-exists? tf2)
                               (and (directory-exists? hf2)
                                    (walk tf2 hf2))
                               (not (directory-exists? hf2)))))))
             tfs))))


;; check installed eggs for already installed files

(define (matching-installed-files egg fnames)
  (let ((eggs (glob (make-pathname (install-path) "*" +egg-info-extension+))))
    (let loop ((eggs eggs) (same '()))
      (cond ((null? eggs) same)
            ((string=? egg (pathname-file (car eggs)))
             (loop (cdr eggs) same))
            (else
              (let* ((info (load-egg-info (car eggs)))
                     (files (assq 'installed-files info))
                     (mfiles (and files
                                  (filter (lambda (fname)
                                            (and (not (member fname same))
                                                 (member fname files)))
                                          fnames))))
                (loop (cdr eggs) (append (or mfiles '()) same))))))))

(define (check-installed-files name info)
  (let ((bad (matching-installed-files name (cdr (assq 'installed-files info)))))
    (unless (null? bad)
      (flush-output)
      (fprintf (current-error-port) 
               "\nthe extension `~a' will overwrite the following files:\n\n" name)
      (for-each 
        (lambda (fname)
          (fprintf (current-error-port) "  ~a~%" fname))
        bad)
      (exit 1))))


;; retrieve eggs, recursively (if needed)
  
(define (retrieve-eggs eggs)
  (for-each
    (lambda (egg)
      (cond ((assoc egg canonical-eggs) =>
             (lambda (a)
               ;; push to front
               (set! canonical-eggs (cons a (delete a canonical-eggs eq?)))))
            (else
              (let ((name (if (pair? egg) (car egg) egg))
                    (version (override-version egg)))
                (let-values (((dir ver) (locate-egg name version)))
                  (when (or (not dir)
                            (null? (directory dir)))
                    (when dir (delete-directory dir))
                    (error "extension or version not found" name))
                  (d retrieve-only "~a located at ~a~%" egg dir)
                  (set! canonical-eggs
                    (cons (list name dir ver) canonical-eggs)))))))
     eggs)
  (when (or (not retrieve-only) retrieve-recursive)
    (for-each
      (lambda (e+d+v)
        (unless (member (car e+d+v) checked-eggs)
          (d "checking ~a ...~%" (car e+d+v))
          (set! checked-eggs (cons (car e+d+v) checked-eggs))
          (let* ((fname (make-pathname (cadr e+d+v) (car e+d+v) +egg-extension+))
                 (info (validate-egg-info (load-egg-info fname))))
            (d "checking platform for `~a'~%" (car e+d+v))
            (check-platform (car e+d+v) info)
            (d "checking dependencies for `~a'~%" (car e+d+v))
            (let-values (((missing upgrade) 
                          (outdated-dependencies (car e+d+v) info)))
              (set! missing (apply-mappings missing))
              (set! dependencies
                (cons (cons (car e+d+v)
                            (map (lambda (mu)
                                   (if (pair? mu)
                                       (car mu)
                                       mu))
                              (append missing upgrade)))
                      dependencies))
              (when (pair? missing)
                (d " missing: ~a~%" (string-intersperse missing ", "))
                (retrieve-eggs missing))
              (when (and (pair? upgrade)
                         (or force-install
                             (replace-extension-question e+d+v upgrade)))
                (let ((ueggs (unzip1 upgrade)))
                  (d " upgrade: ~a~%" (string-intersperse ueggs ", "))
                  ;; XXX think about this...
                  #;(for-each
                    (lambda (e)
                      (d "removing previously installed extension `~a'" e)
                      (remove-extension e) )
                    ueggs)
                  (retrieve-eggs ueggs) ) ) ) ) ) )
      canonical-eggs)))

(define (outdated-dependencies egg info)
  (let ((ds (get-egg-dependencies info)))
    (for-each (lambda (h) (set! ds (h egg ds))) hacks)
    (let loop ((deps ds) (missing '()) (upgrade '()))
      (if (null? deps)
          (values (reverse missing) (reverse upgrade))
          (let-values (((m u) (check-dependency (car deps))))
            (loop (cdr deps)
                  (if m (cons m missing) missing)
                  (if u (cons u upgrade) upgrade)))))))

(define (get-egg-dependencies info)
  (append (get-egg-property* info 'dependencies '())
          (get-egg-property* info 'build-dependencies '())
          (if run-tests
              (get-egg-property* info 'test-dependencies '()) 
              '())))

(define (check-dependency dep)
  (cond ((or (symbol? dep) (string? dep))
         (values (and (not (ext-version dep)) (->string dep))
                 #f))
        ((and (list? dep) (eq? 'or (car dep)))
         (let scan ((ordeps (cdr dep)) (bestm #f) (bestu #f))
           (if (null? ordeps)
               (values (cond (bestu #f)	; upgrade overrides new
                             (bestm bestm)
                             (else #f))
                       bestu)
               (let-values (((m u) (check-dependency (car ordeps))))
                 (if (and (not m) (not u))
                     (values #f #f)
                     (scan (cdr ordeps)
                           (if (and m (not bestm))
                               m
                               bestm)
                           (if (and u (not bestu))
                               u
                               bestu)))))))
        ((and (list? dep) (= 2 (length dep))
              (or (string? (car dep)) (symbol? (car dep))))
         (let ((v (ext-version (car dep))))
           (cond ((not v)
                  (values (->string (car dep)) #f))
                 ((not (version>=? v (->string (cadr dep))))
                  (cond ((string=? "chicken" (->string (car dep)))
                         (if force-install
                             (values #f #f)
                             (error
                               (string-append 
                                 "Your CHICKEN version is not recent enough to use this extension - version "
                                 (cadr dep) 
				 " or newer is required"))))
                        (else
                          (values #f
                                  (cons (->string (car dep)) (->string (cadr dep)))))))
                 (else (values #f #f)))))
        (else
          (warning "invalid dependency syntax in extension meta information"
                   dep)
          (values #f #f))))

(define (ext-version x)
  (cond ((or (eq? x 'chicken) (equal? x "chicken"))
         (chicken-version))
        ((let* ((sf (chicken.load#find-file
                     (make-pathname #f (->string x) +egg-info-extension+)
                     (repo-path))))
           (and sf
                (file-exists? sf)
                (load-egg-info sf))) =>
         (lambda (info)
           (let ((a (assq 'version info)))
             (if a
                 (->string (cadr a))
                 "0.0.0"))))
        (else #f)))

(define (check-platform name info)
  (unless cross-chicken
    (and-let* ((platform (get-egg-property info 'platform)))
      (or (let loop ((p platform))
	    (cond ((symbol? p)
		   (feature? p))
		  ((not (list? p))
		   (error "invalid `platform' property" name platform))
		  ((and (eq? 'not (car p)) (pair? (cdr p)))
		   (not (loop (cadr p))))
		  ((eq? 'and (car p))
		   (every loop (cdr p)))
		  ((eq? 'or (car p))
		   (any loop (cdr p)))
		  (else (error "invalid `platform' property" name platform))))
	  (error "extension is not targeted for this system" name)))))

(define (replace-extension-question e+d+v upgrade)
  (print (string-intersperse
           (append
             (list "The following installed extensions are outdated, because `"
                   (car e+d+v)
                   "' requires later versions:\n\n")
             (filter-map
              (lambda (e)
                (cond ((assq (string->symbol (car e)) override) =>
                       (lambda (a)
                         (when (and (pair? (cdr a))
                                    (not (equal? (cadr a) (cdr e))))
                           (warning
                            (sprintf "version `~a' of extension `~a' overrides required version `~a'"
                                     (cadr a) (car a) (cdr e))))
                         #f))
                      (else
                       (conc "  " (car e) " ("
                             (or (ext-version (car e)) "unknown") " -> " (cdr e)
                             ")" #\newline))))
              upgrade))
             ""))
  (let loop ()
    (display "Do you want to replace the existing extensions? (yes/no/abort) ")
    (flush-output)
    (let ((r (trim (read-line))))
      (cond ((string=? r "yes"))
            ((string=? r "no") #f)
            ((string=? r "abort") (exit 2))
            (else (loop))))))

(define (trim str)
  (define (left lst)
    (cond ((null? lst) '())
          ((char-whitespace? (car lst)) (left (cdr lst)))
          (else (cons (car lst) (left (cdr lst))))))
  (list->string (reverse (left (reverse (left (string->list str)))))))
  
  
;; list available egg versions on servers
  
(define (list-egg-versions eggs)
  (let ((srvs (map resolve-location default-servers)))
    (let loop1 ((eggs eggs))
      (unless (null? eggs)
        (let* ((egg (car eggs))
               (name (if (pair? egg) (car egg) egg)))
          (let loop2 ((srvs srvs))
            (and (pair? srvs)
                 (let ((versions (try-list-versions name (car srvs))))
                   (or (and versions 
                            (begin
                              (printf "~a:" name)
                              (for-each (cut printf " ~a" <>) versions)
                              (newline)))
                       (loop2 (cdr srvs))))))
          (loop1 (cdr eggs)))))))

  
;; perform installation of retrieved eggs
  
(define (install-eggs)
  (for-each
    (lambda (egg)
      (let* ((name (car egg))
             (dir (cadr egg))
             (metadata-dir (make-pathname cache-metadata-directory name))
             (eggfile (make-pathname dir name +egg-extension+))
             (info (load-egg-info eggfile))
             (vfile (make-pathname metadata-dir +version-file+))
             (ver (and (file-exists? vfile)
                       (with-input-from-file vfile read))))
        (when (or host-extension 
                  (and (not target-extension)
                       (not host-extension)))
          (let-values (((build install info) (compile-egg-info eggfile 
                                                               info
                                                               ver
                                                               platform
                                                               'host)))
            (let ((bscript (make-pathname dir name 
                                          (build-script-extension 'host platform)))
                  (iscript (make-pathname dir name 
                                          (install-script-extension 'host
                                                                    platform))))
              (generate-shell-commands platform build bscript dir
                                       (build-prefix 'host name info)
                                       (build-suffix 'host name info)
                                       keepfiles)
              (generate-shell-commands platform install iscript dir
                                       (install-prefix 'host name info)
                                       (install-suffix 'host name info)
                                       keepfiles)
              (cond (do-not-build (print bscript "\n" iscript))
                    (else
                      (print "building " name)
                      (run-script dir bscript platform)
                      (unless (if (member name requested-eggs) no-install no-install-dependencies)
                        (check-installed-files name info)
                        (print "installing " name)
                        (run-script dir iscript platform sudo: sudo-install))
                      (when (and (member name requested-eggs)
                                 run-tests
                                 (not (test-egg egg platform)))
                        (exit 2)))))))
        (when target-extension
          (let-values (((build install info) (compile-egg-info eggfile
                                                               info
                                                               ver
                                                               platform
                                                               'target)))
            (let ((bscript (make-pathname dir name 
                                          (build-script-extension 'target platform)))
                  (iscript (make-pathname dir name 
                                          (install-script-extension 'target 
                                                                    platform))))
              (generate-shell-commands platform build bscript dir
                                       (build-prefix 'target name info)
                                       (build-suffix 'target name info)
                                       keepfiles)
              (generate-shell-commands platform install iscript dir
                                       (install-prefix 'target name info)
                                       (install-suffix 'target name info)
                                       keepfiles)
              (cond (do-not-build (print bscript "\n" iscript))
                    (else
                      (print "building " name " (target)")
                      (run-script dir bscript platform)
                      (unless (if (member name requested-eggs) no-install no-install-dependencies)
                        (print "installing " name " (target)")
                        (run-script dir iscript platform)))))))))
    (order-installed-eggs)))

(define (order-installed-eggs)
  (let* ((dag (reverse (sort-dependencies dependencies string=?)))
         (ordered (filter-map (cut assoc <> canonical-eggs) dag)))
    (unless quiet
      (d "install order:~%")
      (pp dag))
    ordered))

(define (test-egg egg platform)
  (let* ((name (car egg))
         (dir (cadr egg))
         (version (caddr egg))
         (testdir (make-pathname dir "tests"))
         (tscript (make-pathname testdir "run.scm")))
    (if (and (directory-exists? testdir)
             (file-exists? tscript))
        (let ((old (current-directory))
              (cmd (string-append (qs* default-csi platform)
				  " -s " (qs* tscript platform)
				  " " (qs* name platform)
				  " " (or version ""))))
          (change-directory testdir)
	  (d "running: ~a~%" cmd)
          (let ((r (system+ cmd platform)))
            (flush-output (current-error-port))
            (cond ((zero? r) 
                   (change-directory old)
                   #t)
                  (else
                    (print "test script failed with nonzero exit status")
                    #f))))
        #t)))

(define (run-script dir script platform #!key sudo (stop #t))
  (d "running script ~a~%" script)
  (exec (if (eq? platform 'windows)
            script
            (string-append
             (if sudo
                 (string-append sudo-program " ")
                 "")
             (let ((dyld (and (eq? (software-version) 'macosx)
                              (get-environment-variable "DYLD_LIBRARY_PATH"))))
               (if dyld
                   (string-append "/usr/bin/env DYLD_LIBRARY_PATH="
                                  (qs* dyld platform)
                                  " ")
                   ""))
             "sh " script))
        stop))

(define (exec cmd #!optional (stop #t))
  (d "executing: ~s~%" cmd)
  (let ((r (system+ cmd platform)))
    (unless (zero? r)
      (if stop
          (error "shell command terminated with nonzero exit code" r cmd)
          (print "shell command terminated with nonzero exit code " r ": " cmd)))
    r))


;;; update module-db

(define (update-db)
  (let* ((files (glob (make-pathname (install-path) "*.import.so")
                      (make-pathname (install-path) "*.import.scm")))
         (dbfile (create-temporary-file)))
      (print "loading import libraries ...")
      (fluid-let ((##sys#warnings-enabled #f))
        (for-each
         (lambda (path)
           (let* ((file (pathname-strip-directory path))
		  (import-name (pathname-strip-extension file))
		  (module-name (pathname-strip-extension import-name)))
	     (handle-exceptions ex
		 (print-error-message 
		  ex (current-error-port) 
		  (sprintf "Failed to import from `~a'" file))
	       (unless quiet (print "loading " file " ..."))
	       (eval `(import-syntax ,(string->symbol module-name))))))
         files))
      (print "generating database ...")
      (let ((db
             (sort
              (concatenate
               (filter-map
                (lambda (m)
                  (and-let* ((mod (cdr m))
                             (mname (##sys#module-name mod))
                             ((not (memq mname +internal-modules+)))
                             ((not (eq? mname (current-module)))))
                    (unless quiet (print "processing " mname " ..."))
                    (let-values (((_ ve se) (##sys#module-exports mod)))
                      (append (map (lambda (se) (list (car se) 'syntax mname)) se)
                              (map (lambda (ve) (list (car ve) 'value mname)) ve)))))
                ##sys#module-table))
              (lambda (e1 e2)
                (string<? (symbol->string (car e1)) (symbol->string (car e2)))))))
        (with-output-to-file dbfile
          (lambda ()
            (for-each (lambda (x) (write x) (newline)) db)))
        (unless quiet (print "installing " +module-db+ " ..."))
        (copy-file dbfile (make-pathname (install-path) +module-db+) #t)
        (delete-file dbfile))))


;; purge cache for given (or all) eggs

(define (purge-cache eggs)
  (cond ((null? eggs)
         (when (file-exists? cache-directory)
           (d "purging complete cache at ~a~%" cache-directory)
           (delete-directory cache-directory #t)))
        (else
          (for-each
            (lambda (egg)
              (let* ((name (if (pair? egg) (car egg) egg))
                     (cache-dir (make-pathname cache-directory name))
                     (metadata-dir (make-pathname cache-metadata-directory name)))
                (when (file-exists? cache-dir)
                  (d "purging ~a from cache at ~a~%" name cache-dir)
                  (delete-directory cache-dir #t))
                (when (file-exists? metadata-dir)
                  (d "purging metadata of ~a from cache at ~a~%" name metadata-dir)
                  (delete-directory metadata-dir #t))))
            eggs))))


;; command line parsing and selection of operations
  
(define (perform-actions eggs)
  (load-defaults)
  (cond (update-module-db (update-db))
        (purge-mode (purge-cache eggs))
        (print-repository (print (install-path)))
        ((null? eggs)
         (cond (list-versions-only
                 (print "no eggs specified"))
               (else
                 (let ((files (glob "*.egg" "chicken/*.egg")))
                   (when (null? files) (exit 3))
                   (set! canonical-eggs
                     (map (lambda (fname)
                            (list (pathname-file fname) (current-directory) #f))
                       files))
                   (set! requested-eggs (map car canonical-eggs))
                   (retrieve-eggs '())
                   (unless retrieve-only (install-eggs))))))
        (else
          (let ((eggs (apply-mappings eggs)))
            (cond (list-versions-only (list-egg-versions eggs))
                  (else
                    (set! requested-eggs (map (o car canonical) eggs))
                    (retrieve-eggs eggs)
                    (unless retrieve-only (install-eggs))))))))
  
(define (usage code)
  (print #<<EOF
usage: chicken-install [OPTION ...] [NAME[:VERSION] ...]

  -h   -help                    show this message and exit
       -version                 show version and exit
       -force                   don't ask, install even if versions don't match
  -k   -keep                    keep temporary files
  -s   -sudo                    use external command to elevate privileges for filesystem operations
  -l   -location DIRECTORY      get egg sources from DIRECTORY.  May be provided multiple times.
                                Locations specified on the command line have precedence over the
                                ones specified in setup.defaults.
  -r   -retrieve                only retrieve egg into cache directory, don't install (giving `-r'
                                more than once implies `-recursive')
       -recursive               if `-retrieve' is given, retrieve also dependencies
       -dry-run                 do not build or install, just print the locations of the generated
                                build & install scripts
       -list-versions           list available versions for given eggs (HTTP transport only)
  -n   -no-install              do not install, just build
       -no-install-dependencies do not install dependencies
       -purge                   remove cached files for given eggs (or purge cache completely)
       -host                    when cross-compiling, compile extension only for host
       -target                  when cross-compiling, compile extension only for target
       -test                    run included test-cases, if available
  -u   -update-db               update export database
       -repository              print path used for egg installation
       -override FILENAME       override versions for installed eggs with information from file
       -from-list FILENAME      install eggs from list obtained by `chicken-status -list'
  -v   -verbose                 be verbose
       -cached                  only install from cache
  -D   -feature NAME            define build feature
       -defaults FILENAME       use FILENAME as defaults instead of the installed `setup.defaults'
                                file

chicken-install recognizes the SUDO, http_proxy and proxy_auth environment variables, if set.

EOF
);|
    (exit code))

(define (main args)
  (setup-proxy (get-environment-variable "http_proxy"))
  (let ((eggs '())
        (rx (irregex "([^:]+):(.+)")))
    (let loop ((args args))
      (if (null? args)
          (begin
            (validate-environment)
            (perform-actions (reverse eggs)))
          (let ((arg (car args)))
            (cond ((member arg '("-h" "-help" "--help"))
                   (usage 0))
                  ((equal? arg "-test")
                   (set! run-tests #t)
                   (loop (cdr args)))
                  ((equal? arg "-repository")
                   (set! print-repository #t)
                   (loop (cdr args)))
                  ((equal? arg "-r")
                   (if retrieve-only
                       (set! retrieve-recursive #t)
                       (set! retrieve-only #t))
                   (loop (cdr args)))
                  ((equal? arg "-retrieve")
                   (set! retrieve-only #t)
                   (loop (cdr args)))
                  ((equal? arg "-version")
                   (print (chicken-version))
                   (exit 0))
                  ((member arg '("-D" "-feature"))
                   (register-feature! (cadr args))
                   (loop (cddr args)))
                  ((equal? arg "-recursive")
                   (set! retrieve-recursive #t)
                   (loop (cdr args)))
                  ((equal? arg "-list-versions")
                   (set! list-versions-only #t)
                   (loop (cdr args)))
                  ((equal? arg "-defaults")
                   (set! user-defaults (cadr args))
                   (loop (cddr args)))
                  ((equal? arg "-force")
                   (set! force-install #t)
                   (loop (cdr args)))
                  ((equal? arg "-host")
                   (set! target-extension #f)
                   (loop (cdr args)))
                  ((equal? arg "-target")
                   (set! host-extension #f)
                   (loop (cdr args)))
                  ((member arg '("-u" "-update-db"))
                   (set! update-module-db #t)
                   (loop (cdr args)))
                  ((equal? arg "-no-install-dependencies")
                   (set! no-install-dependencies #t)
                   (loop (cdr args)))
                  ((equal? arg "-dry-run")
                   (set! do-not-build #t)
                   (loop (cdr args)))
                  ((member arg '("-v" "-verbose"))
                   (set! quiet #f)
                   (loop (cdr args)))
                  ((member arg '("-k" "-keep"))
                   (set! keepfiles #t)
                   (loop (cdr args)))
                  ((member arg '("-s" "-sudo"))
                   (set! sudo-install #t)
                   (loop (cdr args)))
                  ((member arg '("-l" "-location"))
                   (when (null? (cdr args))
                     (fprintf (current-error-port) "-l|-location: missing argument.~%")
                     (exit 1))
                   (set! default-locations
                     (append (list (cadr args)) default-locations))
                   (loop (cddr args)))
                  ((member arg '("-n" "-no-install"))
                   (set! no-install #t)
                   (loop (cdr args)))
                  ((equal? arg "-purge")
                   (set! purge-mode #t)
                   (loop (cdr args)))
                  ((equal? arg "-cached")
                   (set! cached-only #t)
                   (loop (cdr args)))
                  ((equal? arg "-from-list")
                   (unless (pair? (cdr args)) (usage 1))
                   (set! eggs
                     (append eggs
                             (map (lambda (p)
                                    (if (null? (cdr p))
                                        (->string (car p))
                                        (cons (->string (car p))
                                              (cadr p))))
                                  (with-input-from-file (cadr args) read-list))))
                   (loop (cddr args)))
                  ((equal? arg "-override")
                   (unless (pair? (cdr args)) (usage 1))
                   (set! override
                     (call-with-input-file (cadr args) read-list))
                   (loop (cddr args)))

                  ;;XXX 
                  
                  ((and (positive? (string-length arg))
                        (char=? #\- (string-ref arg 0)))
                   (if (> (string-length arg) 2)
                       (let ((sos (string->list (substring arg 1))))
                         (if (every (cut memq <> +short-options+) sos)
                             (loop (append 
                                     (map (cut string #\- <>) sos)
                                     (cdr args)))
                             (usage 1)))
                       (usage 1)))
                  ((irregex-match rx arg) =>
                   (lambda (m)
                     (set! eggs
                       (alist-cons
                         (irregex-match-substring m 1)
                         (irregex-match-substring m 2)
                         eggs))
                     (loop (cdr args))))
                  (else
                    (set! eggs (cons arg eggs))
                    (loop (cdr args)))))))))

(main (command-line-arguments))
  
)
