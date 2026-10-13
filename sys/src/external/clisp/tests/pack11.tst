;; -*- Lisp -*- vim:filetype=lisp
;; packages-test
;; -------------

;;test file for chapter 11

(packagep  *package*)
T

;; `list-all-packages' and type test
(every #'packagep (list-all-packages))
T

;;11.6 obligate Paketnamen u. deren Abkuerzungen

;;vorhandensein der standardpakete und find-package dafuer

(and (find-package 'lisp) t)
T
(and (find-package 'user) t)
T
(and (find-package 'keyword) t)
T
(and (find-package 'system) t)
T
(and (find-package 'sys) t)
T
(and (find-package "sys") t)
NIL
(and (find-package "sys") t)
NIL
(and (find-package "system") t)
NIL
(and (find-package "SYSTEM") t)
T
(and (find-package "SYS") t)
T

(eq (find-package (find-package "CL")) (find-package "CL"))
t

(defparameter cl-user::*saved-package* *package*) cl-user::*saved-package*

;nicknames
(find "SYS" (package-nicknames 'sys) :test #'string=)
"SYS"

;package-name
(package-name 'sys)
"SYSTEM"
(package-name 'system)
"SYSTEM"
(package-name "COMMON-LISP-USER")
"COMMON-LISP-USER"
(package-name "SYS")
"SYSTEM"

(let ((p (make-package #\p)))
  (prog1 (eq p (find-package #\p))
    (delete-package p)))
t

(progn (make-package #\p) (delete-package #\p))
T

;;; 11.7 anlegen von paketen, export import ...

  ;package-funktionen mit nutzerdefinierten paketen

;; make-package
(package-name (make-package 'pack11-p1 :nicknames '(t1 tst1)))
"PACK11-P1"

(package-name (rename-package (find-package "PACK11-P1")
                              (find-package "PACK11-P1")))
"PACK11-P1"

;package-use-list
;(package-use-list (find-package 'test1))
;("LISP")


(and (in-package "PACK11-P1") T)
T


(export '(pack11-p1::test1-y pack11-p1::test1-z)
        (find-package '"PACK11-P1"))
T

(export '(pack11-p1::test1-a pack11-p1::test1-b pack11-p1::test1-c)
        (find-package 'pack11-p1))
T

(setf test1-a -2
      test1-b -1
      test1-c  0
      test1-x  1
      test1-y  2
      test1-z  3)
3

(package-name (defpackage pack11-p2
                (:nicknames "PACK11-T2" "PACK11-TST2")
                (:use pack11-p1)))
"PACK11-P2"

(progn (in-package "PACK11-P2") t)
LISP:T

(cl:package-name (cl:find-package 'pack11-p2))
"PACK11-P2"

(cl:package-name cl:*package*)
"PACK11-P2"

(cl:import '(cl:error) (cl:find-package 'pack11-p2))
CL:T

(cl:and (cl:boundp 'test1-x) test1-x)
CL:NIL

(cl:unintern 'test1-x)
CL:T

(eval (read-from-string
       "(cl:and (cl:boundp 'pack11-p1:test1-x) pack11-p1:test1-x)"))
#+XCL 1 #-XCL ERROR

(cl:and (cl:boundp 'pack11-p1::test1-x) pack11-p1::test1-x)
1

(cl:and (cl:boundp 'test1-y) test1-y)
#+XCL CL:NIL #-XCL 2

(cl:unintern 'test1-y)
#+XCL CL:T #-XCL CL:NIL

(cl:and (cl:boundp 'pack11-p1:test1-y) pack11-p1:test1-y)
#+XCL ERROR #-XCL 2

(cl:and (cl:boundp 'pack11-p1::test1-y) pack11-p1::test1-y)
2

(cl:import '(pack11-p1::test1-x pack11-p1::test1-y)
           (cl:find-package 'pack11-p2))
CL:T

(cl:and (cl:boundp 'test1-x) test1-x)
1

(eval (read-from-string
       "(cl:and (cl:boundp 'pack11-p1:test1-x) pack11-p1:test1-x)"))
#+XCL 1 #-XCL ERROR

(cl:and (cl:boundp 'pack11-p1::test1-x) pack11-p1::test1-x)
1

(cl:and (cl:boundp 'test1-z) test1-z)
#+XCL CL:NIL #-XCL 3

(cl:unintern 'test1-z (cl:find-package 'pack11-p2))
#+XCL CL:T #-XCL CL:NIL

(cl:and (cl:boundp 'pack11-p1:test1-z) pack11-p1:test1-z)
#+XCL ERROR #-XCL 3

pack11-p1::test1-z
3

(cl:unexport  '(pack11-p1::test1-x pack11-p1::test1-y)
              (cl:find-package 'pack11-p1))
CL:T

(cl:and (cl:boundp 'test1-x) test1-x)
1

(cl:and (cl:boundp 'test1-y) test1-y)
#+XCL CL:NIL #-XCL 2

(cl:unintern 'test1-x (cl:find-package 'pack11-p2))
CL:T

(eval (read-from-string "pack11-p1:test1-x"))
ERROR

pack11-p1::test1-x
1

test1-z
3

(cl:unintern 'test1-z (cl:find-package 'pack11-p2))
#+XCL CL:T #-XCL CL:NIL

pack11-p1:test1-z
3

pack11-p1::test1-z
3

(cl:import 'pack11-p1::test1-z (cl:find-package 'pack11-p2))
CL:T

test1-z
3

pack11-p1:test1-z
3

pack11-p1::test1-z
3

test1-c
#+XCL ERROR #-XCL 0

(cl:unintern 'test-c (cl:find-package 'pack11-p2))
CL:T

pack11-p1:test1-c
0

pack11-p1::test1-c
0

(cl:import '(pack11-p1::test1-a pack11-p1::test1-b pack11-p1::test1-c)
             (cl:find-package 'pack11-p2))
CL:T

test1-c
0

pack11-p1:test1-c
0

pack11-p1::test1-c
0

(cl:eq 'test1-c 'pack11-p1::test1-c)
CL:T

  ;Ende nutzerdefinierte Pakete

;; test in standardmaessig vorgegebenen paketen

; export | import | unintern

(cl:packagep (cl:make-package "PACK11")) cl:T

(cl:and (cl:in-package "PACK11") cl:T)
CL:T

(setf x 1 y 2 z 3)
3

(and (defpackage "PACK11-EDITOR") T)
T

(and (in-package "PACK11-EDITOR") T)
T

(unintern 'x)
T

(unintern 'y)
T

(unintern 'z)
T

pack11::x
1

(eval (read-from-string "pack11:x"))
ERROR

x
error

(eq 'x 'pack11::x)
NIL

(unintern 'x)
T

(export '(pack11::x pack11::y) (find-package 'pack11))
T

pack11::x
1

pack11:x
1

x
error

(unintern 'x)
T

(import 'pack11:x (find-package 'pack11-editor))
T

x
1

(eq 'x 'pack11::x)
t

(eq 'x 'pack11:x)
t

(eq 'pack11-editor::x 'pack11::x)
t

;; unexport

(and (in-package "PACK11") T)
T

(unexport 'y)
T

(and (in-package "PACK11-EDITOR") T)
T

y
ERROR

(eval (read-from-string "pack11:y"))
ERROR

pack11::y
2

(and (in-package "PACK11") (package-name *package*)) "PACK11"

(ext:appease-cerrors
 (let ((*package* "not a package - just a string"))
   (multiple-value-list (read-from-string "READ-FROM-STRING"))))
(READ-FROM-STRING 16)

;; http://www.lisp.org/HyperSpec/Issues/iss194-writeup.html
(let ((tmp-sym (make-symbol "FOO"))
      (old-sym (find-symbol "FOO" "PACK11")))
  (when old-sym (unintern old-sym "PACK11"))
  (list (import tmp-sym "PACK11")
        (package-name (symbol-package tmp-sym))
        (unintern tmp-sym "PACK11")
        (find-symbol "FOO" "PACK11")))
(T "PACK11" T NIL)

;; shadowing-import -- zunaechst ohne geerbte symbole!!

(setf d 4 e 5 f 6 y 111 x 222)
222

(export '(pack11::a pack11::b pack11::c pack11::y pack11::x)
        (find-package 'pack11))
T

(import '(pack11::a pack11::b pack11::c pack11::y)
        (find-package 'pack11-editor))
ERROR

(and (make-package 'pack11-shadow) (in-package "PACK11-SHADOW") t)
T

(setf x 'pack11-shadow)
pack11-shadow

(shadowing-import '(pack11::d pack11::e pack11::f pack11::x)
                  (find-package 'pack11-shadow))
T

x
222

(eq pack11::x x)
T

; shadow

(shadow '(e #\F) (find-package 'pack11-shadow))
t

(setf e 'pack11-shadow-e)
pack11-shadow-e

(eq 'e 'pack11::e)
#+XCL nil #-XCL t

e
pack11-shadow-e

(eval (read-from-string "pack11:e"))
error

pack11::e
#+XCL 5 #-XCL pack11-shadow-e

;; unintern a shadowing symbol
(progn
  (setq pg3 (make-package "PACK11-G3")
        pg1 (make-package "PACK11-G1" :use (list pg3))
        pg2 (make-package "PACK11-G2" :use (list pg3))
        ph (make-package "PACK11-H" :use (list pg1 pg2)))
  (shadow "FOO" ph))
t

(setq gsym (intern "FOO" pg3))   pack11-g3::foo

(export gsym pg3)                t
(export gsym pg1)                t
(export gsym pg2)                t

(multiple-value-list (setf (values sym access) (find-symbol "FOO" ph)))
(pack11-h::foo :internal)

(package-shadowing-symbols ph)   (pack11-h::foo)
(eq sym gsym)                    nil
(equal (symbol-package sym) ph)  t

(unintern sym ph)             t

(delete-package ph)           t
(delete-package pg1)          t
(delete-package pg2)          t
(delete-package pg3)          t
(delete-package "PACK11-P2")  t
(delete-package "PACK11-P1")  t

; use-package | unuse-package

(and (make-package 'pack11-use) (in-package "PACK11-USE") t)
t

(use-package '(pack11))
T

pack11::d
4

(eval (read-from-string "pack11:d"))
#+XCL 4 #-XCL ERROR

d
ERROR

(unuse-package 'pack11)
T

pack11::d
4

(eval (read-from-string "pack11:d"))
ERROR

d
ERROR

;make-package mit beutzung eines paketes, dass geerbte symbole enthaelt

(and (make-package 'pack11-inherit :nicknames '(inh i))
     (in-package "PACK11-INHERIT") T)
T

(setf a 'inherita b 'inheritb)
inheritb

(export '(a b) (find-package 'pack11-inherit))
T

(and (make-package 'pack11-inherit1 :use '(pack11-inherit))
     (in-package "PACK11-INHERIT1") T)
T

a
pack11-inherit::inherita

b
pack11-inherit::inheritb

(cl:setf c 'inherit1c)
inherit1c

(cl:and (cl:make-package 'pack11-inherit2 :use '(pack11-inherit1))
        (cl:in-package "PACK11-INHERIT2") cl:T)
CL:T

a
#+XCL inherita #-XCL CL:ERROR

b
#+XCL inheritb #-XCL CL:ERROR

c
#+XCL inherit1c #-XCL CL:ERROR

(eval (read-from-string "(cl:eq 'c 'pack11-inherit1:c)"))
#+XCL CL:T #-XCL CL:ERROR

(eval (read-from-string "(cl:eq 'a 'pack11-inherit:a)"))
#+XCL CL:T #-XCL CL:ERROR

(eval (read-from-string "(cl:eq 'b 'pack11-inherit:b)"))
#+XCL CL:T #-XCL CL:ERROR

(cl:eq 'c 'pack11-inherit1::c)
#+XCL CL:T #-XCL CL:NIL

(cl:eq 'a 'pack11-inherit::a)
#+XCL CL:T #-XCL CL:NIL

(cl:eq 'b 'pack11-inherit::b)
#+XCL CL:T #-XCL CL:NIL

;find-all-symbols

(cl:and (cl:in-package "PACK11") cl:T)
CL:T

(delete-package "PACK11-EDITOR")   T
(delete-package "PACK11-SHADOW")   T
(delete-package "PACK11-USE")      T
(delete-package "PACK11-INHERIT2") T
(delete-package "PACK11-INHERIT1") T
(delete-package "PACK11-INHERIT")  T

; find-all-symbols fehlerhaft
(and (member 'pack11::x (setf s (find-all-symbols 'x)))T)
T

(eval (read-from-string "(and (member 'pack11-editor:x s) t)"))
#+XCL T #-XCL ERROR

(and (member 'pack11::x (setf s1 (find-all-symbols 'x)))T)
T

(set-difference s s1)
nil                              ;Ende Kommentar

;do-symbols | do-external-symbols | do-all-symbols

(setf sym nil
      esym nil
      asym nil
)
nil

(do-symbols (s (find-package 'pack11))
  (push (symbol-name s) sym))
nil

(do-external-symbols (s (find-package 'pack11))
  (push (symbol-name s) esym))
nil

(do-all-symbols (s)(push (symbol-name s) asym))
nil

(find "ESYM" sym :test #'string=)
"ESYM"

(find "ESYM" esym :test #'string=)
nil

(find "LAMBDA-LIST-KEYWORDS" esym :test #'string=)
#+XCL "LAMBDA-LIST-KEYWORDS" #-XCL NIL

;(count "LAMBDA-LIST-KEYWORDS" asym :test #'string=)
;T                                                  ;viel zu lang

; modules | provide | (require nicht getestet !)

(and *modules* T)
#+(or XCL ECL LISPWORKS) T #+CLISP NIL #-(or XCL CLISP ECL LISPWORKS) UNKNOWN

(let ((*modules* *modules*))
  (provide 'provide-test)
  (find "PROVIDE-TEST" *modules* :test #'string=))
"PROVIDE-TEST"

;; from ansi-tests
(unless (member "z" *modules* :test #'string=)
  (let ((*modules* *modules*)) (provide "z") (require #\z) nil))
NIL

(let ((*modules* *modules*))
  (provide :ABAZONK)
  (not (member :ABAZONK *modules* :test #'string=)))
NIL

;; <HS>/Body/mac_with-package-iterator.html
(defun test-package-iterator (package)
  (unless (packagep package)
    (setq package (find-package package)))
  (let ((all-entries '())
        (generated-entries '()))
    (do-symbols (x package)
      (multiple-value-bind (symbol accessibility)
          (find-symbol (symbol-name x) package)
        (push (list symbol accessibility) all-entries)))
    (with-package-iterator (generator-fn package
                                         :internal :external :inherited)
      (loop
        (multiple-value-bind (more? symbol accessibility pkg)
            (generator-fn)
          (declare (ignore pkg))
          (unless more? (return))
          (let ((l (multiple-value-list (find-symbol (symbol-name symbol)
                                                     package))))
            (unless (equal l (list symbol accessibility))
              (error "Symbol ~S not found as ~S in package ~A [~S]"
                     symbol accessibility (package-name package) l))
            (push l generated-entries)))))
    (unless (and (subsetp all-entries generated-entries :test #'equal)
                 (subsetp generated-entries all-entries :test #'equal))
      (error "Generated entries and Do-Symbols entries do not correspond"))
    t))
test-package-iterator

(compile 'test-package-iterator) test-package-iterator

(test-package-iterator :common-lisp-user) t

(test-package-iterator :common-lisp)      t

(progn ; from gcl/ansi-test
(defconstant +fail-count-limit+ 20)
(defmacro test-with-package-iterator (package-list-expr &rest symbol-types)
  "Build an expression that tests the with-package-iterator form."
  (let ((name (gensym))
        (cht-var (gensym))
        (pkg-list-var (gensym)))
    `(let ((,cht-var (make-hash-table))
           (,pkg-list-var ,package-list-expr)
           (fail-count 0))
       (with-package-iterator (,name ,pkg-list-var
                                     ,@(copy-list symbol-types))
         ;; For each symbol, check that name is returning appropriate things
         (loop
           (block fail
             (multiple-value-bind (more sym access pkg)
                 (,name)
               (unless more (return nil))
               (setf (gethash sym ,cht-var) t)  ;; note presence of symbol
               ;; Check that its access status is in the list,
               ;;  that pkg is a package,
               ;;  that the symbol is in the package,
               ;;  and that (in the package) it has the correct access type
               (unless (member access (quote ,(copy-list symbol-types)))
                 (unless (> fail-count +fail-count-limit+)
                   (format t "Bad access type: ~S ==> ~A~%" sym access))
                 (when (= fail-count +fail-count-limit+)
                   (format t "Further messages suppressed~%"))
                 (incf fail-count)
                 (return-from fail nil))

               (unless (packagep pkg)
                 (unless (> fail-count +fail-count-limit+)
                   (format t "Not a package: ~S ==> ~S~%" sym pkg))
                 (when (= fail-count +fail-count-limit+)
                   (format t "Further messages suppressed~%"))
                 (incf fail-count)
                 (return-from fail nil))
               (multiple-value-bind (sym2 access2)
                   (find-symbol (symbol-name sym) pkg)
                 (unless (or (eq sym sym2)
                             (member sym2 (package-shadowing-symbols pkg)))
                   (unless (> fail-count +fail-count-limit+)
                     (format t "Not same symbol: ~S ~S~%" sym sym2))
                   (when (= fail-count +fail-count-limit+)
                     (format t "Further messages suppressed~%"))
                   (incf fail-count)
                   (return-from fail nil))
                 (unless (eq access access2)
                   (unless (> fail-count +fail-count-limit+)
                     (format t "Not same access type: ~S ~S ~S~%"
                             sym access access2))
                   (when (= fail-count +fail-count-limit+)
                     (format t "Further messages suppressed~%"))
                   (incf fail-count)
                   (return-from fail nil)))))))
       ;; now, check that each symbol in each package has
       ;; been properly found
       (loop
         for p in ,pkg-list-var do
           (block fail
             (do-symbols (sym p)
               (multiple-value-bind (sym2 access)
                   (find-symbol (symbol-name sym) p)
                 (unless (eq sym sym2)
                   (unless (> fail-count +fail-count-limit+)
                     (format t "Not same symbol (2): ~S ~S~%"
                             sym sym2))
                   (when (= fail-count +fail-count-limit+)
                     (format t "Further messages suppressed~%"))
                   (incf fail-count)
                   (return-from fail nil))
                 (unless (or (not (member access
                                          (quote ,(copy-list symbol-types))))
                             (gethash sym ,cht-var))
                   (format t "Symbol not found: ~S~%" sym)
                   (incf fail-count)
                   (return-from fail nil))))))
       (or (zerop fail-count) fail-count))))
(defun with-package-iterator-internal (packages)
  (test-with-package-iterator packages :internal))
(compile 'with-package-iterator-internal)
(defun with-package-iterator-external (packages)
  (test-with-package-iterator packages :external))
(compile 'with-package-iterator-external)
(defun with-package-iterator-inherited (packages)
  (test-with-package-iterator packages :inherited))
(compile 'with-package-iterator-inherited)
(defun with-package-iterator-all (packages)
  (test-with-package-iterator packages :internal :external :inherited))
(compile 'with-package-iterator-all)
t)
T

(with-package-iterator-internal (list (find-package "COMMON-LISP-USER"))) t
(with-package-iterator-external (list (find-package "COMMON-LISP-USER"))) t
(with-package-iterator-inherited (list (find-package "COMMON-LISP-USER"))) t
(with-package-iterator-all (list (find-package "COMMON-LISP-USER"))) t

(with-package-iterator-internal (list (find-package "COMMON-LISP"))) t
(with-package-iterator-external (list (find-package "COMMON-LISP"))) t
(with-package-iterator-inherited (list (find-package "COMMON-LISP"))) t
(with-package-iterator-all (list (find-package "COMMON-LISP"))) t

(with-package-iterator-internal
 (list (find-package "COMMON-LISP-USER") (find-package "COMMON-LISP"))) t
(with-package-iterator-external
 (list (find-package "COMMON-LISP-USER") (find-package "COMMON-LISP"))) t
(with-package-iterator-inherited
 (list (find-package "COMMON-LISP-USER") (find-package "COMMON-LISP"))) t
(with-package-iterator-all
 (list (find-package "COMMON-LISP-USER") (find-package "COMMON-LISP"))) t

(map nil #'print (list-all-packages))
nil

#+CLISP
(ext:appease-cerrors
 (let (SYSTEM::*COUTPUT-STREAM*)
   (setq SYSTEM::*COUTPUT-STREAM* 123)))
#+CLISP 123

#+CLISP
(ext:package-case-sensitive-p
 (make-package "PACK11-PACKAGE-CASE" :case-sensitive t :case-inverted t))
#+CLISP
T

#+CLISP
(ext:package-case-inverted-p
 (defpackage "PACK11-PACKAGE-CASE" (:case-sensitive nil) (:case-inverted nil)))
#+CLISP
NIL

#+CLISP
(setf (ext:package-case-inverted-p "PACK11-PACKAGE-CASE") t
      (ext:package-case-sensitive-p "PACK11-PACKAGE-CASE") t)
#+CLISP
T

#+CLISP
(let ((*break-on-signals* 'warning))
  (ext:package-case-sensitive-p
    (defpackage "PACK11-PACKAGE-CASE" (:case-inverted t) (:case-sensitive t))))
#+CLISP
T

#+CLISP
(delete-package "PACK11-PACKAGE-CASE")
#+CLISP
T

(progn (setq *package* cl-user::*saved-package*) (delete-package "PACK11"))
T

;; https://sourceforge.net/tracker/?func=detail&atid=101355&aid=1612313&group_id=1355
(let ((f "pack11-tst.lisp"))
  (unwind-protect
       (progn
         (with-open-file (out f :direction :output)
           (princ ";; test non-top-level defpackage compilation
\(defmacro my-defpackage (name use)
  `(eval-when (:compile-toplevel :load-toplevel :execute)
     (let ((pkg (defpackage ,name (:use))))
       (use-package '(,use) pkg)
       pkg)))
\(my-defpackage #:pack11-bar #:cl)
\(in-package #:pack11-bar)
\(defun baz (x) x)
" out))
         (list (cdr (multiple-value-list (compile-file f)))
               (equal (package-use-list '#:pack11-bar)
                      (list (find-package '#:cl)))))
    (delete-package '#:pack11-bar)
    (post-compile-file-cleanup f)))
((NIL NIL) T)

; Clean up.
(symbol-cleanup 'cl-user::*saved-package*)
NIL
