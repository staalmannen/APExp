;;;; file.scm - File operations
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met:
;
;   Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
;
;   Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in the
;   documentation and/or other materials provided with the distribution.
;
;   Neither the name of the author nor the names of its contributors may
;   be used to endorse or promote products derived from this software
;   without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
; INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
; BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
; OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
; ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
; TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
; USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
; DAMAGE.


(declare
  (unit file)
  (uses extras irregex pathname)
  (fixnum)
  (disable-interrupts)
  (foreign-declare #<<EOF
#include <errno.h>

#define C_test_access(fn, m) C_fix(access(C_c_string(fn), C_unfix(m)))

/* For Windows */
#ifndef R_OK
# define R_OK 2
#endif
#ifndef W_OK
# define W_OK 4
#endif
#ifndef X_OK
# define X_OK 2
#endif

#define C_rename(old, new)  C_fix(rename(C_c_string(old), C_c_string(new)))
#define C_remove(str)       C_fix(remove(C_c_string(str)))
#define C_rmdir(str)        C_fix(rmdir(C_c_string(str)))

#ifndef _WIN32
# include <sys/stat.h>
# define C_mkdir(str)       C_fix(mkdir(C_c_string(str), S_IRWXU | S_IRWXG | S_IRWXO))
#else
# define C_mkdir(str)       C_fix(mkdir(C_c_string(str)))
#endif

#include <sys/types.h>
#include <dirent.h>

#define C_opendir(s,h)      C_set_block_item(h, 0, (C_word) opendir(C_c_string(s)))
#define C_readdir(h,e)      C_set_block_item(e, 0, (C_word) readdir((DIR *)C_block_item(h, 0)))
#define C_closedir(h)       (closedir((DIR *)C_block_item(h, 0)), C_SCHEME_UNDEFINED)
#define C_foundfile(e,b,l)  (C_strlcpy(C_c_string(b), ((struct dirent *) C_block_item(e, 0))->d_name, l), C_fix(strlen(((struct dirent *) C_block_item(e, 0))->d_name)))

static C_word C_fcall C_u_i_symbolic_linkp(C_word path)
{
#if !defined(_WIN32) || defined(__CYGWIN__)
  struct stat buf;
  if (lstat(C_c_string(path), &buf) == 0)
    return C_mk_bool(S_ISLNK(buf.st_mode));
#endif
  return C_SCHEME_FALSE;
}

EOF
))

(module chicken.file
  (create-directory delete-directory
   create-temporary-file create-temporary-directory
   delete-file delete-file* copy-file move-file rename-file
   file-exists? directory-exists?
   file-readable? file-writable? file-executable?
   directory find-files glob)

(import scheme
	chicken.base
	chicken.condition
	chicken.fixnum
	chicken.foreign
	chicken.io
	chicken.irregex
	chicken.pathname
	chicken.process-context)

(include "common-declarations.scm")

(define-foreign-variable strerror c-string "strerror(errno)")

;; TODO: Some duplication from POSIX, to give better error messages.
;; This really isn't so much posix-specific, and code like this is
;; also in library.scm.  This should be deduplicated across the board.
(define posix-error
  (let ([strerror (foreign-lambda c-string "strerror" int)]
	[string-append string-append] )
    (lambda (type loc msg . args)
      (let ([rn (##sys#update-errno)])
        (apply ##sys#signal-hook/errno
               type rn loc (string-append msg " - " (strerror rn)) args)))))


;;; Existence checks:

(define (file-exists? name)
  (##sys#check-string name 'file-exists?)
  (and (##sys#file-exists? name #f #f 'file-exists?) name))

(define (directory-exists? name)
  (##sys#check-string name 'directory-exists?)
  (and (##sys#file-exists? name #f #t 'directory-exists?) name))


;;; Permissions:

(define-foreign-variable _r_ok int "R_OK")
(define-foreign-variable _w_ok int "W_OK")
(define-foreign-variable _x_ok int "X_OK")

(define (test-access filename acc loc)
  (##sys#check-string filename loc)
  (let ((r (##core#inline "C_test_access" (##sys#make-c-string filename loc) acc)))
    (or (fx= r 0)
	(if (fx= (##sys#update-errno) (foreign-value "EACCES" int))
	    #f
	    (posix-error #:file-error loc "cannot access file" filename)))))

(define (file-readable? filename) (test-access filename _r_ok 'file-readable?))
(define (file-writable? filename) (test-access filename _w_ok 'file-writable?))
(define (file-executable? filename) (test-access filename _x_ok 'file-executable?))


;;; Directories:

(define (directory #!optional (spec (current-directory)) show-dotfiles?)
  (##sys#check-string spec 'directory)
  (let ((buffer (make-string 256))
	(handle (##sys#make-pointer))
	(entry (##sys#make-pointer)))
    (##core#inline
     "C_opendir"
     (##sys#make-c-string spec 'directory) handle)
    (if (##sys#null-pointer? handle)
	(posix-error #:file-error 'directory "cannot open directory" spec)
	(let loop ()
	  (##core#inline "C_readdir" handle entry)
	  (if (##sys#null-pointer? entry)
	      (begin (##core#inline "C_closedir" handle) '())
	      (let* ((flen (##core#inline "C_foundfile" entry buffer (string-length buffer)))
		     (file (##sys#substring buffer 0 flen))
		     (char1 (string-ref file 0))
		     (char2 (and (fx> flen 1) (string-ref file 1))))
		(if (and (eq? #\. char1)
			 (or (not char2)
			     (and (eq? #\. char2) (eq? 2 flen))
			     (not show-dotfiles?)))
		    (loop)
		    (cons file (loop)))))))))

(define-inline (*symbolic-link? name loc)
  (##core#inline "C_u_i_symbolic_linkp" (##sys#make-c-string name loc)))

(define-inline (*create-directory loc name)
  (unless (fx= 0 (##core#inline "C_mkdir" (##sys#make-c-string name loc)))
    (posix-error #:file-error loc "cannot create directory" name)))

(define create-directory
  (lambda (name #!optional recursive)
    (##sys#check-string name 'create-directory)
    (unless (or (fx= 0 (##sys#size name))
                (file-exists? name))
      (if recursive
	  (let loop ((dir (let-values (((dir file ext) (decompose-pathname name)))
			    (if file (make-pathname dir file ext) dir))))
	    (when (and dir (not (directory-exists? dir)))
	      (loop (pathname-directory dir))
	      (*create-directory 'create-directory dir)))
	  (*create-directory 'create-directory name)))
    name))

(define delete-directory
  (lambda (name #!optional recursive)
    (define (rmdir dir)
      (let ((sname (##sys#make-c-string dir)))
	(unless (fx= 0 (##core#inline "C_rmdir" sname))
	  (posix-error #:file-error 'delete-directory "cannot delete directory" dir))))
    (##sys#check-string name 'delete-directory)
    (if recursive
	(let ((files (find-files ; relies on `find-files' to list dir-contents before dir
		      name
		      dotfiles: #t
		      follow-symlinks: #f)))
	  (for-each
	   (lambda (f)
	     ((cond ((*symbolic-link? f 'delete-directory) delete-file)
		    ((directory-exists? f) rmdir)
		    (else delete-file))
	      f))
	   files)
	  (rmdir name))
	(rmdir name))))


;;; File management:

(define (delete-file filename)
  (##sys#check-string filename 'delete-file)
  (unless (eq? 0 (##core#inline "C_remove" (##sys#make-c-string filename 'delete-file)))
    (##sys#signal-hook/errno
     #:file-error (##sys#update-errno) 'delete-file
     (##sys#string-append "cannot delete file - " strerror) filename)
    filename))

(define (delete-file* file)
  (and (file-exists? file) (delete-file file)))

(define (rename-file oldfile newfile #!optional (clobber #f))
  (##sys#check-string oldfile 'rename-file)
  (##sys#check-string newfile 'rename-file)
  (when (and (not clobber) (file-exists? newfile))
    (##sys#error 'rename-file "newfile exists but clobber is false" newfile))
  (unless (eq? 0 (##core#inline
		  "C_rename"
		  (##sys#make-c-string oldfile 'rename-file)
		  (##sys#make-c-string newfile 'rename-file)))
    (##sys#signal-hook/errno
     #:file-error (##sys#update-errno) 'rename-file
     (##sys#string-append "cannot rename file - " strerror) oldfile newfile))
  newfile)

(define (copy-file oldfile newfile #!optional (clobber #f) (blocksize 1024))
  (##sys#check-string oldfile 'copy-file)
  (##sys#check-string newfile 'copy-file)
  (##sys#check-number blocksize 'copy-file)
  (unless (and (integer? blocksize) (> blocksize 0))
    (##sys#error 'copy-file "invalid blocksize - not a positive integer" blocksize))
  (when (directory-exists? oldfile)
    (##sys#error 'copy-file "cannot copy directories" oldfile))
  (when (and (not clobber) (file-exists? newfile))
    (##sys#error 'copy-file "newfile exists but clobber is false" newfile))
  (let* ((i (open-input-file oldfile #:binary))
	 (o (open-output-file newfile #:binary))
	 (s (make-string blocksize)))
    (let loop ((d (read-string! blocksize s i))
	       (l 0))
      (if (fx= 0 d)
	  (begin
	    (close-input-port i)
	    (close-output-port o)
	    l)
	  (begin
	    (write-string s d o)
	    (loop (read-string! blocksize s i) (fx+ d l)))))))

(define (move-file oldfile newfile #!optional (clobber #f) (blocksize 1024))
  (##sys#check-string oldfile 'move-file)
  (##sys#check-string newfile 'move-file)
  (##sys#check-number blocksize 'move-file)
  (unless (and (integer? blocksize) (> blocksize 0))
    (##sys#error 'move-file "invalid blocksize - not a positive integer" blocksize))
  (when (directory-exists? oldfile)
    (##sys#error 'move-file "cannot move directories" oldfile))
  (when (and (not clobber) (file-exists? newfile))
    (##sys#error 'move-file "newfile exists but clobber is false" newfile))
  (let* ((i (open-input-file oldfile #:binary))
	 (o (open-output-file newfile #:binary))
	 (s (make-string blocksize)))
    (let loop ((d (read-string! blocksize s i))
	       (l 0))
      (if (fx= 0 d)
	  (begin
	    (close-input-port i)
	    (close-output-port o)
	    (delete-file oldfile)
	    l)
	  (begin
	    (write-string s d o)
	    (loop (read-string! blocksize s i) (fx+ d l)))))))


;;; Temporary file creation:

(define create-temporary-file)
(define create-temporary-directory)

(let ((temp-prefix "temp")
      (string-append string-append))
  (define (tempdir)
    (or (get-environment-variable "TMPDIR")
        (get-environment-variable "TEMP")
        (get-environment-variable "TMP")
        (if ##sys#windows-platform
            (let ((up (get-environment-variable "USERPROFILE")))
              (if up
                  (string-append up "/AppData/Local/Temp")
                  "."))
            "/tmp")))
  (set! create-temporary-file
    (lambda (#!optional (ext "tmp"))
      (##sys#check-string ext 'create-temporary-file)
      (let loop ()
	(let* ((n (##core#inline "C_random_fixnum" #x10000))
	       (getpid (foreign-lambda int "C_getpid"))
	       (pn (make-pathname
		    (tempdir)
		    (string-append
		     temp-prefix
		     (number->string n 16)
		     "."
		     (##sys#number->string (getpid)))
		    ext)))
	  (if (file-exists? pn)
	      (loop)
	      (call-with-output-file pn (lambda (p) pn)))))))
  (set! create-temporary-directory
    (lambda ()
      (let loop ()
	(let* ((n (##core#inline "C_random_fixnum" #x10000))
	       (getpid (foreign-lambda int "C_getpid"))
	       (pn (make-pathname
		    (tempdir)
		    (string-append
		     temp-prefix
		     (number->string n 16)
		     "."
		     (##sys#number->string (getpid))))))
	  (if (file-exists? pn)
	      (loop)
	      (let ((r (##core#inline "C_mkdir" (##sys#make-c-string pn 'create-temporary-directory))))
		(if (eq? r 0)
		    pn
		    (##sys#signal-hook
		     #:file-error 'create-temporary-directory
		     (##sys#string-append "cannot create temporary directory - " strerror)
		     pn)))))))))


;;; Filename globbing:

(define (glob . paths)
  (let conc-loop ((paths paths))
    (if (null? paths)
	'()
	(let ((path (car paths)))
	  (let-values (((dir fil ext) (decompose-pathname path)))
	    (let ((dir* (or dir "."))
		  (rx   (irregex (glob->sre (make-pathname #f (or fil "*") ext)))))
	      (let loop ((fns (condition-case (directory dir* #t)
				((exn i/o file) #f))))
		(cond ((not (pair? fns)) (conc-loop (cdr paths)))
		      ((irregex-match rx (car fns)) =>
		       (lambda (m)
			 (cons (make-pathname dir (irregex-match-substring m))
			       (loop (cdr fns)))))
		      (else (loop (cdr fns)))))))))))


;;; Find matching files:

(define (find-files dir #!key (test (lambda _ #t))
			      (action (lambda (x y) (cons x y)))
			      (seed '())
			      (limit #f)
			      (dotfiles #f)
			      (follow-symlinks #f))
  (##sys#check-string dir 'find-files)
  (let* ((depth 0)
	 (lproc
	  (cond ((not limit) (lambda _ #t))
		((fixnum? limit) (lambda _ (fx< depth limit)))
		(else limit)))
	 (pproc
	  (if (procedure? test)
	      test
	      (let ((test (irregex test))) ; force compilation
		(lambda (x) (irregex-match test x))))))
    (let loop ((dir dir)
	       (fs (directory dir dotfiles))
	       (r seed))
      (if (null? fs)
	  r
	  (let* ((filename (##sys#slot fs 0))
		 (f (make-pathname dir filename))
		 (rest (##sys#slot fs 1)))
	    (cond ((directory-exists? f)
		   (cond ((member filename '("." "..")) (loop dir rest r))
			 ((and (*symbolic-link? f 'find-files) (not follow-symlinks))
			  (loop dir rest (if (pproc f) (action f r) r)))
			 ((lproc f)
			  (loop dir
				rest
				(fluid-let ((depth (fx+ depth 1)))
				  (loop f
					(directory f dotfiles)
					(if (pproc f) (action f r) r)))))
			 (else (loop dir rest (if (pproc f) (action f r) r)))))
		  ((pproc f) (loop dir rest (action f r)))
		  (else (loop dir rest r))))))))

)
