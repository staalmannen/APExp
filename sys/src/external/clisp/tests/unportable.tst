;; -*- Lisp -*- vim:filetype=lisp
;; Test unportable code of which some implementations specify the behaviour
;; These fall into 3 categories in ANSI-CL:
;; - "implementation defined",
;; - "implementation dependent" or
;; - "undefined consequences"
;; - none of the above, simply a gap in the spec
;; Use #-(or ...) to avoid implementations where the unportable form
;; may drop the bomb

;;;;
;;;;  Implementation-defined
;;;;

;; 13.1.4.6 & 13.6
#+(and clisp unicode)
(digit-char-p #\KHMER_DIGIT_ZERO) ; #\U17e0
#+(and clisp unicode) 0

;; In CLISP, there are unicode digits beside 0-9 a-Z yet they form no numbers
#+(and clisp unicode)
(type-of (read-from-string (string #\KHMER_DIGIT_ZERO)))
#+(and clisp unicode) SYMBOL


;;;;
;;;;  Implementation-dependent
;;;;

(proclaim '(inline some-function))
#+cmu ext::%undefined%
#+(or clisp) nil
#+(or sbcl) () ; no values

(declaim (inline some-function))
#+(or clisp cmu) nil
#+(or sbcl) () ; no values

;; 6.1.1.4 Whether initial value forms of for/as variables include
;; lexical environment of all loop variables or only preceding ones.
;; CLISP changed its behaviour across versions

#-(or clisp)
(let ((vars '(1 2))) (loop for vars on vars collect (length vars)))
#+(or cmu sbcl cormanlisp) (2 1)

#-(or clisp)
(let ((vars '(1 2 3))) (loop for i from 0 below 5 for vars on vars collect (length vars)))
#+(or cmu sbcl cormanlisp) (3 2 1)

;; Whether the iteration constructs establish a new binding of var on
;; each iteration or whether it establishes a binding for var once at
;; the beginning and then assigns it on any subsequent iterations

;; Actually, CLISP does not guarantee the (3 3 3) or (2 2 2) result,
;; it just guarantees that it won't be (2 1 0), but rather (x x x),
;; because a single binding is assigned on each iteration.
;; CMUCL 19d switched dotimes behaviour from (3 3 3) to (2 1 0)

(let (a)
  (dotimes (i 3) (push (lambda () i) a))
  (loop for x in a collect (funcall x)))
#+(or clisp cmu sbcl cormanlisp) (3 3 3)
#+(or) (2 1 0)

(let (a)
  (dolist (i '(0 1 2)) (push (lambda () i) a))
  (loop for x in a collect (funcall x)))
#+(or clisp) (2 2 2)
#+(or cmu sbcl) (2 1 0)
#+(or cormanlisp) (nil nil nil)


#|
;; 1.4.1.5 Coerce designator to function once or every time
(defun add-some (x) ; TODO not reproducible past first run
  (defun add-some (x) (+ x 2))
  (+ x 1))
add-some
;; ffi callback: coerce immediately, IIRC don't even accept name

#-(or)
(mapcar 'add-some '(1 2 3 4))
#+(or clisp cormanlisp) (2 4 5 6)
|#

#|
;; 3.2.5 error handler for type error in compile[-file]
(with-simple-restart (error "test handler")
  (compile '(macrolet ((foo () (error "at compile-time")))
              (foo))))
|#

;; 5.1.1.2 setf expander vs. setf function of standardized accessors
(fboundp '(setf car))
#+(or clisp) NIL
#+(or cmu sbcl cormanlisp) T


(let ((l (list 1 2 3))) (nreverse l) l)
#+(or clisp) (3 2 1)
#+(or sbcl cmu) (1)
#+(or) (1 2 3) ; permitted by standard

;; nreconc is required to be aligned on nreverse behaviour
(let ((l (list 1 2 3))) (nreconc l 'a) l)
#+(or clisp) (3 2 1 . a)
#+(or sbcl cmu) (1 . a)
#+(or) (1 2 3)

(let ((s (make-string 2)))
  (setf (char s 0) #\a) (setf (char s 1) #\b)
  (nreverse s) s)
#-(or) "ba"
#+(or) "ab" ; permitted, but nobody seems to do that

;; 14.2 whether or not pushnew actually executes the storing form for
;; its place in the situation where the item is already a member of
;; the list held by place.
(let ((h (make-hash-table)))
  (pushnew 1 (gethash 2 h '(1)))
  (multiple-value-list (gethash 2 h)))
#+(or clisp sbcl cmu) ((1) t) ; executed
#+(or) (nil nil) ; not executed


;;;;
;;;; Undefined Consequences
;;;;

;; 2.4.8.3
#-(or) (read-from-string "#3()")
#+(or clisp) ERROR
#+(or sbcl cmu cormanlisp) #(nil nil nil)


;; 5.2
;; "The consequences are undefined if an attempt is made to transfer
;; control to an exit point whose dynamic extent has ended."

;; define-symbol-macro
;; "If symbol is already defined as a global variable, an error of
;; type program-error is signaled."  See excepsit.tst foo16-1
(progn (proclaim '(special first-special-then-macro)) t)
T

(define-symbol-macro first-special-then-macro *print-case*)
ERROR ; only excepsit can check for PROGRAM-ERROR

;; "The consequences are unspecified if a special declaration is made
;; for symbol while in the scope of this definition". See excepsit.tst foo16-2
(define-symbol-macro first-macro-then-special *print-case*)
first-macro-then-special

(progn (proclaim '(special first-macro-then-special)) t)
#+(or clisp) ERROR
#+(or sbcl cmu) t

;; Exit points are abandoned first
;; "The consequences are undefined if an attempt is made to transfer
;; control to an exit point whose dynamic extent has ended."
;; observed 2008 by Kaz Kylheku
(tagbody
   (block try-return
     (unwind-protect (go exit) (return-from try-return)))
 exit)
;#+ANSI-CL ERROR
#+(or clisp allegro) nil
#-(or clisp allegro) ERROR

(block try-return
  (tagbody
     (block try-return
       (unwind-protect (go exit) (return-from try-return)))
   exit)
  (return-from try-return t))
;#+ANSI-CL nil
#+(or clisp allegro) t
#-(or clisp allegro) nil


;;;;
;;;; Simply unspecified (missing from the specification)
;;;;

;; CLHS has a note on PROG where it is "explained" as (BLOCK (LET (TAGBODY ...))
;; whereas Mario Latendresse's paper on list comprehensions shows a macroexpansion
;; with the nesting (LET (BLOCK (TAGBODY ...))) -- what implementation was used?
;; Note that notes in ANSI-CL are not a binding part of the standard.

(block nil (prog ((x (return :outer-let))) (return :never)) (return :clhs))
#-(or cormanlisp) :clhs
#+(or cormanlisp) :outer-let

(dolist (i '(1 2 . 3) i))
ERROR

(loop for i in '(1 2 . 3) count t)      ; for comparison, well-defined
ERROR                                   ; 6.1.2.1.2 via ENDP

;; http://www.cliki.net/Issue%20BUTLAST-DOTTED-LIST
(butlast '(1 2 . 3) 0)
#+(or clisp cmu) (1 2)
#+(or sbcl Emacs) (1 2 . 3)
#+(or cormanlisp) ERROR

(list 1 #.(values) 2)
#+(or clisp) (1 nil 2)
#+(or sbcl cmu cormanlisp) (1 2)


;;;;
;;;; Portable code, but care to depend on this?
;;;;

;; 5.1.2.3 Values forms as places
(let ((x (list 1)))
  (multiple-value-list
   (setf (values (car x) (cdr x)) (values 2 3 4))))
(2 3)

(let (a (b t) c)
  (setf (values (values a b) c) (values 1 2 3 4))
  (list a b c))
(1 nil 2)


;; 6.1.9
;; "The clause repeat n is roughly equivalent to a clause such as
;; for downfrom (- n 1) to 0"
;; Iterate differs and uses ceiling instead.
(loop repeat 3.5 count t)
#+(or cmu) 3
#+(or clisp sbcl cormanlisp) 4

(loop for i downfrom (- 3.5 1) to 0 count t) ; for comparison, well-defined
3

;; "the concept [of length] does not make sense for dotted lists",
;; says ANSI-CL issue DOTTED-LIST-ARGUMENTS
(length '(1 2 . 3))                     ; dotted list is not a sequence
ERROR                                   ; how annoying

(list-length '(1 2 . 3))
ERROR                                   ; agreed


;;;;
;;;; Completely bogus code, disrespecting the standard
;;;;

(let ((l (list 1 2 3))) (delete 2 l) l) ; do not depend on such code!
#-(or) (1 3)
#+(or) (1 2 3) ; perfectly legitimate, no side-effect is guaranteed

;; By contrast, NCONC's side effects are precisely defined, eg. lists152.tst


;; Paul Dietz' ANSI testsuite (part of gcl) checks some border cases
;; http://cvs.savannah.gnu.org/viewcvs/gcl/ansi-tests/beyond-ansi/?root=gcl
