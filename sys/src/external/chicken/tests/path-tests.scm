(import (chicken pathname))

(define-syntax test
  (syntax-rules ()
    ((_ r x) (let ((y x)) (print y) (assert (equal? r y))))))

(test "/" (pathname-directory "/"))
(test "/" (pathname-directory "/abc"))
(test "abc" (pathname-directory "abc/"))
(test "abc" (pathname-directory "abc/def"))
(test "abc" (pathname-directory "abc/def.ghi"))
(test "abc" (pathname-directory "abc/.def.ghi"))
(test "abc" (pathname-directory "abc/.ghi"))
(test "/abc" (pathname-directory "/abc/"))
(test "/abc" (pathname-directory "/abc/def"))
(test "/abc" (pathname-directory "/abc/def.ghi"))
(test "/abc" (pathname-directory "/abc/.def.ghi"))
(test "/abc" (pathname-directory "/abc/.ghi"))
(test "q/abc" (pathname-directory "q/abc/"))
(test "q/abc" (pathname-directory "q/abc/def"))
(test "q/abc" (pathname-directory "q/abc/def.ghi"))
(test "q/abc" (pathname-directory "q/abc/.def.ghi"))
(test "q/abc" (pathname-directory "q/abc/.ghi"))

(test "." (normalize-pathname "" 'unix))
(test "." (normalize-pathname "" 'windows))
(test "\\..\\" (normalize-pathname "/../" 'windows))
(test "\\" (normalize-pathname "/abc/../." 'windows))
(test "/" (normalize-pathname "/" 'unix))
(test "/" (normalize-pathname "/." 'unix))
(test "/" (normalize-pathname "/./" 'unix))
(test "/" (normalize-pathname "/./." 'unix))
(test "." (normalize-pathname "./" 'unix))
(test "a" (normalize-pathname "./a"))
(test "a" (normalize-pathname ".///a"))
(test "a" (normalize-pathname "a"))
(test "a/" (normalize-pathname "a/" 'unix))
(test "a/b" (normalize-pathname "a/b" 'unix))
(test "a\\b" (normalize-pathname "a\\b" 'unix))
(test "a\\b" (normalize-pathname "a\\b" 'windows))
(test "a\\b" (normalize-pathname "a/b" 'windows))
(test "a/b/" (normalize-pathname "a/b/" 'unix))
(test "a/b/" (normalize-pathname "a/b//" 'unix))
(test "a/b" (normalize-pathname "a//b" 'unix))
(test "/a/b" (normalize-pathname "/a//b" 'unix))
(test "/a/b" (normalize-pathname "///a//b" 'unix))
(test "c:a\\b" (normalize-pathname "c:a/./b" 'windows))
(test "c:/a/b" (normalize-pathname "c:/a/./b" 'unix))
(test "c:a\\b" (normalize-pathname "c:a/./b" 'windows))
(test "c:b" (normalize-pathname "c:a/../b" 'windows))
(test "c:\\b" (normalize-pathname "c:\\a\\..\\b" 'windows))
(test "a/b" (normalize-pathname "a/./././b" 'unix))
(test "a/b" (normalize-pathname "a/b/c/d/../.." 'unix))
(test "a/b/" (normalize-pathname "a/b/c/d/../../" 'unix))
(test "../../foo" (normalize-pathname "../../foo" 'unix))
(test "c:\\" (normalize-pathname "c:\\" 'windows))
(test "c:\\" (normalize-pathname "c:\\." 'windows))
(test "c:\\" (normalize-pathname "c:\\.\\" 'windows))
(test "c:\\" (normalize-pathname "c:\\.\\." 'windows))

(test "~/foo" (normalize-pathname "~/foo" 'unix))
(test "c:~/foo" (normalize-pathname "c:~/foo" 'unix))
(test "c:~\\foo" (normalize-pathname "c:~\\foo" 'windows))

(assert (directory-null? "/.//"))
(assert (directory-null? ""))
(assert (not (directory-null? "//foo//")))

(test '(#f "/" (".")) (receive (decompose-directory "/.//")))

(if ##sys#windows-platform
    (test '(#f "/" #f) (receive (decompose-directory "///\\///")))
    (test '(#f "/" ("\\")) (receive (decompose-directory "///\\///"))))

(test '(#f "/" ("foo")) (receive (decompose-directory "//foo//")))
(test '(#f "/" ("foo" "bar")) (receive (decompose-directory "//foo//bar")))
(test '(#f #f (".")) (receive (decompose-directory ".//")))
(test '(#f #f ("." "foo")) (receive (decompose-directory ".//foo//")))
(test '(#f #f (" " "foo" "bar")) (receive (decompose-directory " //foo//bar")))
(test '(#f #f ("foo" "bar")) (receive (decompose-directory "foo//bar/")))

(test '(#f #f #f) (receive (decompose-pathname "")))
(test '("/" #f #f) (receive (decompose-pathname "/")))

(if ##sys#windows-platform
    (test '("\\" #f #f) (receive (decompose-pathname "\\")))
    (test '(#f "\\" #f) (receive (decompose-pathname "\\"))))

(test '("/" "a" #f) (receive (decompose-pathname "/a")))

(if ##sys#windows-platform
    (test '("\\" "a" #f) (receive (decompose-pathname "\\a")))
    (test '(#f "\\a" #f) (receive (decompose-pathname "\\a"))))

(test '("/" #f #f) (receive (decompose-pathname "///")))

(if ##sys#windows-platform
    (test '("\\" #f #f) (receive (decompose-pathname "\\\\\\")))
    (test '(#f "\\\\\\" #f) (receive (decompose-pathname "\\\\\\"))))

(test '("/" "a" #f) (receive (decompose-pathname "///a")))

(if ##sys#windows-platform
    (test '("\\" "a" #f) (receive (decompose-pathname "\\\\\\a")))
    (test '(#f "\\\\\\a" #f) (receive (decompose-pathname "\\\\\\a"))))

(test '("/a" "b" #f) (receive (decompose-pathname "/a/b")))

(if ##sys#windows-platform
    (test '("\\a" "b" #f) (receive (decompose-pathname "\\a\\b")))
    (test '(#f "\\a\\b" #f) (receive (decompose-pathname "\\a\\b"))))

(test '("/a" "b" "c") (receive (decompose-pathname "/a/b.c")))

(if ##sys#windows-platform
    (test '("\\a" "b" "c") (receive (decompose-pathname "\\a\\b.c")))
    (test '(#f "\\a\\b" "c") (receive (decompose-pathname "\\a\\b.c"))))

(test '("." "a" #f) (receive (decompose-pathname "./a")))

(if ##sys#windows-platform
    (test '("." "a" #f) (receive (decompose-pathname ".\\a")))
    (test '(#f ".\\a" #f) (receive (decompose-pathname ".\\a"))))

(test '("." "a" "b") (receive (decompose-pathname "./a.b")))

(if ##sys#windows-platform
    (test '("." "a" "b") (receive (decompose-pathname ".\\a.b")))
    (test '(#f ".\\a" "b") (receive (decompose-pathname ".\\a.b"))))

(test '("./a" "b" #f) (receive (decompose-pathname "./a/b")))

(if ##sys#windows-platform
    (test '(".\\a" "b" #f) (receive (decompose-pathname ".\\a\\b")))
    (test '(#f ".\\a\\b" #f) (receive (decompose-pathname ".\\a\\b"))))

(test '(#f "a" #f) (receive (decompose-pathname "a")))
(test '(#f "a." #f) (receive (decompose-pathname "a.")))
(test '(#f ".a" #f) (receive (decompose-pathname ".a")))
(test '("a" "b" #f) (receive (decompose-pathname "a/b")))

(if ##sys#windows-platform
    (test '("a" "b" #f) (receive (decompose-pathname "a\\b")))
    (test '(#f "a\\b" #f) (receive (decompose-pathname "a\\b"))))

(test '("a" "b" #f) (receive (decompose-pathname "a///b")))

(if ##sys#windows-platform
    (test '("a" "b" #f) (receive (decompose-pathname "a\\\\\\b")))
    (test '(#f "a\\\\\\b" #f) (receive (decompose-pathname "a\\\\\\b"))))

(test '("a/b" "c" #f) (receive (decompose-pathname "a/b/c")))

(if ##sys#windows-platform
    (test '("a\\b" "c" #f) (receive (decompose-pathname "a\\b\\c")))
    (test '(#f "a\\b\\c" #f) (receive (decompose-pathname "a\\b\\c"))))

(test '("a/b/c" #f #f) (receive (decompose-pathname "a/b/c/")))

(if ##sys#windows-platform
    (test '("a\\b\\c" #f #f) (receive (decompose-pathname "a\\b\\c\\")))
    (test '(#f "a\\b\\c\\" #f) (receive (decompose-pathname "a\\b\\c\\"))))

(test '("a/b/c" #f #f) (receive (decompose-pathname "a/b/c///")))

(if ##sys#windows-platform
    (test '("a\\b\\c" #f #f) (receive (decompose-pathname "a\\b\\c\\\\\\")))
    (test '(#f "a\\b\\c\\\\\\" #f) (receive (decompose-pathname "a\\b\\c\\\\\\"))))

(test '(#f "a" "b") (receive (decompose-pathname "a.b")))
(test '("a.b" #f #f) (receive (decompose-pathname "a.b/")))

(if ##sys#windows-platform
    (test '("a.b" #f #f) (receive (decompose-pathname "a.b\\")))
    (test '(#f "a" "b\\") (receive (decompose-pathname "a.b\\"))))

(test '(#f "a.b" "c") (receive (decompose-pathname "a.b.c")))
(test '(#f "a." "b") (receive (decompose-pathname "a..b")))
(test '(#f "a.." "b") (receive (decompose-pathname "a...b")))
(test '("a." ".b" #f) (receive (decompose-pathname "a./.b")))

(if ##sys#windows-platform
    (test '("a." ".b" #f) (receive (decompose-pathname "a.\\.b")))
    (test '(#f "a.\\" "b") (receive (decompose-pathname "a.\\.b"))))

(cond (##sys#windows-platform
       (test "x/y\\z.q" (make-pathname "x/y" "z" "q"))
       (test "x/y\\z.q" (make-pathname "x/y" "z.q"))
       (test "x/y\\z.q" (make-pathname "x/y/" "z.q"))
       (test "x/y\\z.q" (make-pathname "x/y/" "z.q"))
       (test "x/y\\z.q" (make-pathname "x/y\\" "z.q"))
       (test "x//y\\z.q" (make-pathname "x//y/" "z.q"))
       (test "x\\y\\z.q" (make-pathname "x\\y" "z.q")))
      (else
       (test "x/y/z.q" (make-pathname "x/y" "z" "q"))
       (test "x/y/z.q" (make-pathname "x/y" "z.q"))
       (test "x/y/z.q" (make-pathname "x/y/" "z.q"))
       (test "x/y/z.q" (make-pathname "x/y/" "z.q"))
       (test "x/y\\/z.q" (make-pathname "x/y\\" "z.q"))
       (test "x//y/z.q" (make-pathname "x//y/" "z.q"))
       (test "x\\y/z.q" (make-pathname "x\\y" "z.q"))))

(test 'error (handle-exceptions _ 'error (make-pathname '(#f) "foo")))

(test "/x/y/z" (make-pathname #f "/x/y/z"))

(cond (##sys#windows-platform
       (test "\\x/y/z" (make-pathname "/" "x/y/z"))
       (test "/x\\y/z" (make-pathname "/x" "/y/z"))
       (test "\\x/y/z" (make-pathname '("/") "x/y/z"))
       (test "\\x\\y/z" (make-pathname '("/" "x") "y/z"))
       (test "/x\\y\\z" (make-pathname '("/x" "y") "z"))
       (test "/x\\y\\z\\" (make-pathname '("/x" "y" "z") #f)))
      (else
       (test "/x/y/z" (make-pathname "/" "x/y/z"))
       (test "/x/y/z" (make-pathname "/x" "/y/z"))
       (test "/x/y/z" (make-pathname '("/") "x/y/z"))
       (test "/x/y/z" (make-pathname '("/" "x") "y/z"))
       (test "/x/y/z" (make-pathname '("/x" "y") "z"))
       (test "/x/y/z/" (make-pathname '("/x" "y" "z") #f))))
