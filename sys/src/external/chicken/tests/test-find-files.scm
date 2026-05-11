(import (chicken file)
        (chicken file posix)
        (chicken process-context)
        (chicken sort)
        (chicken string))

(include "test.scm")

(handle-exceptions exn
  'ignore
  (delete-directory "find-files-test-dir" #t))

(define (file-list=? a b)
  (equal? (sort a string<?) (sort b string<?)))

(for-each (lambda (d)
            (create-directory d #t))
          '("find-files-test-dir/foo/bar/baz/.quux"
            "find-files-test-dir/dir-link-target"
            "find-files-test-dir/foo/.x"))

(for-each (lambda (f)
            (with-output-to-file f (cut display "")))
          '("find-files-test-dir/file1"
            "find-files-test-dir/file2"
            "find-files-test-dir/dir-link-target/foo"
            "find-files-test-dir/dir-link-target/bar"))

(change-directory "find-files-test-dir")

(cond-expand
  ((and windows (not cygwin))		; Cannot handle symlinks
   (define (path lst)
     (map (cut string-translate <> "/" "\\") lst)) )
  (else
   (create-symbolic-link "dir-link-target" "dir-link-name")
   (define (path lst) lst)))

(test-begin "find-files")

(test-equal "no keyword args"
            (find-files ".")
            (path 
	     `("./foo/bar/baz"
              "./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "dotfiles: #t"
            (find-files "." dotfiles: #t)
	    (path
            `("./foo/bar/baz/.quux"
              "./foo/bar/baz"
              "./foo/bar"
              "./foo/.x"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "follow-symlinks: #t"
            (find-files "." follow-symlinks: #t)
            (path
	     `("./foo/bar/baz"
              "./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name/foo"
			  "./dir-link-name/bar"
			  "./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "limit: 1"
            (find-files "." limit: 1)
            (path
	     `("./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "limit: 1 follow-symlinks: #t"
            (find-files "." limit: 1 follow-symlinks: #t)
	    (path
            `("./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name/foo"
			  "./dir-link-name/bar"
			  "./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "limit: 2"
            (find-files "." limit: 2)
	    (path
            `("./foo/bar/baz"
              "./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "limit: 2 follow-symlinks: #t"
            (find-files "." limit: 2 follow-symlinks: #t)
	    (path
            `("./foo/bar/baz"
              "./foo/bar"
              "./foo"
              "./dir-link-target/foo"
              "./dir-link-target/bar"
              "./dir-link-target"
              "./file1"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name/foo"
			  "./dir-link-name/bar"
			  "./dir-link-name")))
              "./file2"))
            file-list=?)

(test-equal "test: (lambda (f) (directory? f))"
            (find-files "." test: (lambda (f) (directory? f)))
            (path
	     `("./foo/bar/baz"
              "./foo/bar"
              "./foo"
              "./dir-link-target"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))))
            file-list=?)

(test-equal "test: (lambda (f) (directory? f)) action: (lambda (f p) (cons (string-append \"--\" f) p))"
            (find-files "."
                        test: (lambda (f) (directory? f))
                        action: (lambda (f p) (cons (string-append "--" f) p)))
            (path
	     `("--./foo/bar/baz"
              "--./foo/bar"
              "--./foo"
              "--./dir-link-target"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("--./dir-link-name")))))
            file-list=?)

(test-equal "dotfiles: #t test: (lambda (f) (directory? f)) follow-symlinks: #t"
            (find-files "." dotfiles: #t test: (lambda (f) (directory? f)) follow-symlinks: #t)
            (path
	     `("./foo/bar/baz/.quux"
              "./foo/bar/baz"
              "./foo/bar"
              "./foo/.x"
              "./foo"
              "./dir-link-target"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))))
            file-list=?)

(test-equal "dotfiles: #t test: (lambda (f) (directory? f)) follow-symlinks: #t limit: 1"
            (find-files "."
                        dotfiles: #t
                        test: (lambda (f) (directory? f))
                        follow-symlinks: #t
                        limit: 1)
            (path
	     `("./foo/bar"
              "./foo/.x"
              "./foo"
              "./dir-link-target"
	      ,@(cond-expand
		  ((and windows (not cygwin)) '())
		  (else '("./dir-link-name")))))
            file-list=?)

(test-end "find-files")

(change-directory "..")
(delete-directory "find-files-test-dir" #t)

(test-exit)
