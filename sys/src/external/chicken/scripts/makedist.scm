;;;; makedist.scm - Make distribution tarballs


(import (chicken file)
        (chicken fixnum)
        (chicken format)
        (chicken io)
        (chicken irregex)
        (chicken pathname)
        (chicken platform)
        (chicken process)
        (chicken process-context)
        (chicken string))

(include "mini-srfi-1.scm")

(define *release* #f)
(define *help* #f)

(define BUILDVERSION (with-input-from-file "buildversion" read))

(define *platform* 
  (let ((sv (symbol->string (software-version))))
    (cond ((irregex-match ".*bsd" sv) "bsd")
	  ((string=? sv "mingw32")
	   (if (equal? (get-environment-variable "MSYSTEM") "MINGW32")
	       "mingw-msys"
	       "mingw32"))
	  (else sv))))

(define *make* 
  (cond ((string=? "bsd" *platform*) "gmake")
	((string=? "mingw32" *platform*) "mingw32-make")
	(else "make")))

(define (prefix dir . files)
  (if (null? files)
      (pathname-directory dir)
      (let ((files2 (map (cut make-pathname dir <>) (normalize files))))
	(if (or (pair? (cdr files)) (pair? (car files)))
	    files2
	    (car files2) ) ) ) )

(define (normalize fs)
  (delete-duplicates
   (map ->string
	(if (pair? fs)
	    (flatten fs)
	    (list fs) ) )
   equal?) )

(define (run . args)
  (let ((cmd (apply format args)))
    (display cmd (current-error-port))
    (newline (current-error-port))
    (system* cmd)))

(define (release full?)
  (let* ((files (with-input-from-file "distribution/manifest" read-lines))
	 (distname (conc "chicken-" BUILDVERSION)) 
	 (distfiles (map (cut prefix distname <>) files)) 
	 (tgz (conc distname ".tar.gz")))
    (run "rm -fr ~a ~a" distname tgz)
    (create-directory distname)
    (for-each
     (lambda (d)
       (let ((d (make-pathname distname d)))
	 (unless (file-exists? d)
	   (print "creating " d)
	   (create-directory d 'with-parents))))
     (delete-duplicates (filter-map prefix files) string=?))
    (let ((missing
	   (foldl (lambda (missing f)
		    (cond
		     ((file-exists? f)
		      (run "cp -p ~a ~a" (qs f) (qs (make-pathname distname f)))
		      missing)
		     (else (cons f missing))))
		  '() files)))
      (unless (null? missing)
	(warning "files missing" missing) ) )
    (run "tar cfz ~a ~a" (conc distname ".tar.gz") distname)
    (run "rm -fr ~a" distname)))

(define (usage)
  (print "usage: makedist [-release] [-make PROGRAM] [--platform=PLATFORM] MAKEOPTION ...")
  (exit))

(define *makeargs*
  (let loop ((args (command-line-arguments)))
    (if (null? args)
	'()
	(let ((arg (car args)))
	  (cond ((string=? "-release" arg) 
		 (set! *release* #t)
		 (loop (cdr args)))
		((string=? "-make" arg)
		 (set! *make* (cadr args))
		 (loop (cddr args)))
		((string=? "-help" arg)
		 (usage))
		((string=? "-platform" arg)
		 (set! *platform* (cadr args))
		 (loop (cddr args)))
		(else (cons arg (loop (cdr args)))))))))

(run "~a -f Makefile.~a distfiles ~a" *make* *platform* (string-intersperse *makeargs*))

(release *release*)
