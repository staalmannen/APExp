;;;; pathname.scm - Pathname operations
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
;   Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
;
;   Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in
;   the documentation and/or other materials provided with the
;   distribution.
;
;   Neither the name of the author nor the names of its contributors
;     may be used to endorse or promote products derived from this
;     software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
; FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
; COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
; INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
; STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
; OF THE POSSIBILITY OF SUCH DAMAGE.

(declare
  (unit pathname)
  (uses data-structures irregex)
  (fixnum)
  (disable-interrupts))

(module chicken.pathname
  (absolute-pathname? decompose-directory decompose-pathname
   directory-null? make-absolute-pathname make-pathname
   normalize-pathname pathname-directory pathname-extension
   pathname-file pathname-replace-directory pathname-replace-extension
   pathname-replace-file pathname-strip-directory
   pathname-strip-extension)

(import scheme
        chicken.base
        chicken.fixnum
        chicken.irregex
        chicken.platform
        chicken.string)

(include "common-declarations.scm")

;;; Pathname operations:

;; Platform specific absolute pathname operations:
;; absolute-pathname-root => #f or (<match> [<origin>] <root>)
;;
;; Not for general consumption

(define absolute-pathname-root)
(define root-origin)
(define root-directory)

(if ##sys#windows-platform
    (let ((rx (irregex "([A-Za-z]:)?([\\/\\\\]).*")))
      (set! absolute-pathname-root (lambda (pn) (irregex-match rx pn)))
      (set! root-origin (lambda (rt) (and rt (irregex-match-substring rt 1))))
      (set! root-directory (lambda (rt) (and rt (irregex-match-substring rt 2)))))
    (let ((rx (irregex "(/).*")))
      (set! absolute-pathname-root (lambda (pn) (irregex-match rx pn)))
      (set! root-origin (lambda (rt) #f))
      (set! root-directory (lambda (rt) (and rt (irregex-match-substring rt 1))))))

(define (absolute-pathname? pn)
  (##sys#check-string pn 'absolute-pathname?)
  (irregex-match-data? (absolute-pathname-root pn)))

(define-inline (*char-pds? ch)
  (if ##sys#windows-platform
      (memq ch '(#\\ #\/))
      (eq? #\/ ch)))

(define (chop-pds str)
  (and str
       (let lp ((len (##sys#size str)))
	 (cond ((and (fx>= len 1)
		     (*char-pds? (##core#inline "C_subchar" str (fx- len 1))))
		(lp (fx- len 1)))
	       ((fx< len (##sys#size str))
		(##sys#substring str 0 len))
	       (else str)))))

(define make-pathname)
(define make-absolute-pathname)

(let ((pds (if ##sys#windows-platform "\\" "/")))

  (define (conc-dirs dirs)
    (##sys#check-list dirs 'make-pathname)
    (let loop ((strs dirs))
      (if (null? strs)
	  ""
	  (let ((s1 (car strs)))
	    (if (zero? (string-length s1))
		(loop (cdr strs))
		(string-append
		 (chop-pds (car strs))
		 pds
		 (loop (cdr strs))))))))

  (define (canonicalize-dirs dirs)
    (cond ((or (not dirs) (null? dirs)) "")
	  ((string? dirs) (conc-dirs (list dirs)))
	  (else           (conc-dirs dirs))))

  (define (_make-pathname loc dir file ext)
    (let ((ext (or ext ""))
	  (file (or file "")))
      (##sys#check-string dir loc)
      (##sys#check-string file loc)
      (##sys#check-string ext loc)
      (string-append
       dir
       (if (and (fx>= (##sys#size dir) 1)
		(fx>= (##sys#size file) 1)
		(*char-pds? (##core#inline "C_subchar" file 0)))
	   (##sys#substring file 1 (##sys#size file))
	   file)
       (if (and (fx> (##sys#size ext) 0)
		(not (char=? (##core#inline "C_subchar" ext 0) #\.)))
	   "."
	   "")
       ext)))

  (set! make-pathname
    (lambda (dirs file #!optional ext)
      (_make-pathname 'make-pathname (canonicalize-dirs dirs) file ext)))

  (set! make-absolute-pathname
    (lambda (dirs file #!optional ext)
      (_make-pathname
       'make-absolute-pathname
       (let ((dir (canonicalize-dirs dirs)))
	 (if (absolute-pathname? dir)
	     dir
	     (##sys#string-append pds dir)))
       file ext))))

(define decompose-pathname
  (let* ((patt1 (if ##sys#windows-platform
                    "^(.*[\\/\\\\])?([^\\/\\\\]+)(\\.([^\\/\\\\.]+))$"
                    "^(.*/)?([^/]+)(\\.([^/.]+))$"))
	 (patt2 (if ##sys#windows-platform
                    "^(.*[\\/\\\\])?((\\.)?[^\\/\\\\]+)$"
                    "^(.*/)?((\\.)?[^/]+)$"))
	 (rx1 (irregex patt1))
	 (rx2 (irregex patt2))
         (strip-pds
          (lambda (dir)
            (and dir
                 (let ((chopped (chop-pds dir)))
                   (if (fx> (##sys#size chopped) 0)
                       chopped
                       (##sys#substring dir 0 1)))))))
    (lambda (pn)
      (##sys#check-string pn 'decompose-pathname)
      (if (fx= 0 (##sys#size pn))
	  (values #f #f #f)
	  (let ((ms (irregex-search rx1 pn)))
	    (if ms
		(values
		 (strip-pds (irregex-match-substring ms 1))
		 (irregex-match-substring ms 2)
		 (irregex-match-substring ms 4))
		(let ((ms (irregex-search rx2 pn)))
		  (if ms
		      (values
		       (strip-pds (irregex-match-substring ms 1))
		       (irregex-match-substring ms 2)
		       #f)
		      (values (strip-pds pn) #f #f)))))))))

(define pathname-directory
  (lambda (pn)
    (let-values (((dir file ext) (decompose-pathname pn)))
      dir)))

(define pathname-file
  (lambda (pn)
    (let-values (((dir file ext) (decompose-pathname pn)))
      file)))

(define pathname-extension
  (lambda (pn)
    (let-values (((dir file ext) (decompose-pathname pn)))
      ext)))

(define pathname-strip-directory
  (lambda (pn)
    (let-values (((dir file ext) (decompose-pathname pn)))
      (make-pathname #f file ext))))

(define pathname-strip-extension
  (lambda (pn)
    (let-values (((dir file ext) (decompose-pathname pn)))
      (make-pathname dir file))))

(define pathname-replace-directory
  (lambda (pn dir)
    (let-values (((_ file ext) (decompose-pathname pn)))
      (make-pathname dir file ext))))

(define pathname-replace-file
  (lambda (pn file)
    (let-values (((dir _ ext) (decompose-pathname pn)))
      (make-pathname dir file ext))))

(define pathname-replace-extension
  (lambda (pn ext)
    (let-values (((dir file _) (decompose-pathname pn)))
      (make-pathname dir file ext))))

;;; normalize pathname for a particular platform

(define normalize-pathname
  (let ((bldplt (if (eq? (software-version) 'mingw32) 'windows 'unix)))
    (define (addpart part parts)
      (cond ((string=? "." part) parts)
            ((string=? ".." part)
	     (if (or (null? parts)
		     (string=? ".." (car parts)))
		 (cons part parts)
		 (cdr parts)))
            (else (cons part parts))))
    (lambda (path #!optional (platform bldplt))
      (let ((sep (if (eq? platform 'windows) #\\ #\/)))
        (define (pds? c)
          (if (eq? platform 'windows)
              (memq c '(#\/ #\\))
              (eq? c #\/)))
	(##sys#check-string path 'normalize-pathname)
	(let ((len (##sys#size path))
	      (type #f)
	      (drive #f))
	  (let loop ((i 0) (prev 0) (parts '()))
	    (cond ((fx>= i len)
		   (when (fx> i prev)
		     (set! parts (addpart (##sys#substring path prev i) parts)))
		   (if (null? parts)
		       (let ((r (if (eq? type 'abs) (string sep) ".")))
			 (if drive (##sys#string-append drive r) r))
		       (let ((out (open-output-string))
			     (parts (##sys#fast-reverse parts)))
			 (display (car parts) out)
			 (for-each
			  (lambda (p)
			    (##sys#write-char-0 sep out)
			    (display p out))
			  (cdr parts))
			 (when (fx= i prev) (##sys#write-char-0 sep out))
			 (let ((r (get-output-string out)))
			   (when (eq? type 'abs)
			     (set! r (##sys#string-append (string sep) r)))
			   (when drive
			     (set! r (##sys#string-append drive r)))
			   r))))
		  ((pds? (string-ref path i))
		   (when (not type)
		     (set! type (if (fx= i prev) 'abs 'rel)))
		   (if (fx= i prev)
		       (loop (fx+ i 1) (fx+ i 1) parts)
		       (loop (fx+ i 1)
			     (fx+ i 1)
			     (addpart (##sys#substring path prev i) parts))))
		  ((and (null? parts)
			(char=? (string-ref path i) #\:)
			(eq? platform 'windows))
		   (set! drive (##sys#substring path 0 (fx+ i 1)))
		   (loop (fx+ i 1) (fx+ i 1) '()))
		  (else (loop (fx+ i 1) prev parts)))))))))

;; directory pathname => list of strings
;; does arg check

(define split-directory
  (lambda (loc dir keep?)
    (##sys#check-string dir loc)
    (string-split dir (if ##sys#windows-platform "/\\" "/") keep?)))

;; Directory string or list only contains path-separators
;; and/or current-directory (".") names.

(define (directory-null? dir)
  (let loop ((ls (if (list? dir) dir (split-directory 'directory-null? dir #t))))
    (or (null? ls)
        (and (member (car ls) '("" "."))
             (loop (cdr ls))))))

;; Directory string => {<origin> <root> <directory-list>}
;; where any maybe #f when missing

(define (decompose-directory dir)
  (define (strip-origin-prefix org decomp)
    #;(assert (or (not org) decomp)) ;cannot have an "origin" but no "decomp"
    (if (not org)
        decomp
        (let ((1st (car decomp)))
          (let ((olen (##sys#size org)))
            (if (not (##core#inline "C_substring_compare" org 1st 0 0 olen))
                ; then origin is not a prefix (really shouldn't happen)
                decomp
                ; else is a prefix
                (let ((rst (cdr decomp))
                      (elen (##sys#size 1st)))
                  (if (fx= olen elen)
                      ; then origin is a list prefix
                      rst
                      ; else origin is a string prefix
                      (cons (##sys#substring 1st olen elen) rst))))))))
  (let* ((ls (split-directory 'decompose-directory dir #f))
         (rt (absolute-pathname-root dir))
         (org (root-origin rt)))
    (values org (root-directory rt) (strip-origin-prefix org (and (not (null? ls)) ls))))))
