;;;; compiler-tests.scm


(import (chicken bitwise) (chicken flonum) (chicken foreign)
	(chicken condition) (srfi 4))
(import-for-syntax (chicken syntax) (chicken string))

;; test dropping of previous toplevel assignments

(define (foo) (define (bar) 1) (bar 2))	; will trigger error later
(define bar 1)
(define (baz) 2)
(define (foo) 'ok)

(assert (eq? 'ok (foo)))

(assert (= 1 (foreign-type-size "char")))
(let* ((words->bytes (foreign-lambda int "C_wordstobytes" int))
       (bytes-in-a-word (words->bytes 1)))
  (assert (= bytes-in-a-word (foreign-type-size "C_word"))))

;; test hiding of unexported toplevel variables

(module foo (bar)
  (import scheme chicken.base)
  (declare (hide bar))
  (define (bar x) (+ x 1)))

(assert (not (##sys#symbol-has-toplevel-binding? 'foo#bar)))


;;; rev. 12104 (reported by Jörg Wittenberger)
;
; - canonicalization of assignment to location didn't walk expansion recursively

(define test-location
  (let-location ((again bool #f))
    (lambda ()
      ((foreign-lambda*
	   int
	   (((c-pointer bool) again))
	 "*again=1; return(1);")
       (location again))
      again)))

(assert (test-location))


;;; rev. 12188 (reported by Jörg Wittenberger)
;
; - generated init-assignment refers to alias, but alias isn't seen later)

(module
 x
 (bar)
 (import scheme chicken.base chicken.foreign)

 (define (bar n)
  (let-location ((off integer 0))
    (lambda () 
      ((foreign-lambda*
	   void
	   (((c-pointer integer) i))
	 "(*i)++;")
       (location off))
      off)))
)

(import x)
(assert (= 1 ((bar 42))))


;; Test custom foreign type conversions

(module y (my-add1)
  (import scheme (chicken base) (chicken foreign))

  (define-foreign-type my-int integer add1 sub1)

  (define my-add1 (foreign-lambda* my-int ((my-int x)) "C_return(x+1);")))

(import y)
(assert (= 2 (my-add1 1)))

;;; rev. 14574 (reported by Peter Bex)
;
; - type specifiers in foreign-lambda in macros are incorrectly renamed
; - variable names and type specifiers in foreign-lambda* and
;    foreign-primitive in macros are incorrectly renamed

(let-syntax ((strlen-macro
              (syntax-rules ()
                ((strlen-macro arg)
                 (print ((foreign-lambda int strlen c-string) arg)))))
             (strlen-macro*
              (syntax-rules ()
                ((strlen-macro* arg)
                 (print ((foreign-lambda* int ((c-string str))
                                          "C_return(strlen(str));") arg)))))
             (strlen-safe-macro
              (syntax-rules ()
                ((strlen-safe-macro arg)
                 (print ((foreign-safe-lambda int strlen c-string) arg)))))
             (strlen-safe-macro*
              (syntax-rules ()
                ((strlen-safe-macro* arg)
                 (print ((foreign-safe-lambda* int ((c-string str))
                                               "C_return(strlen(str));") arg)))))
             (strlen-primitive-macro
              (syntax-rules ()
                ((strlen-primitive-macro* arg)
                 (print ((foreign-primitive int ((c-string str))
                                            "C_return(strlen(str));") arg))))))
  (strlen-macro "hello, world")
  (strlen-macro* "hello, world")
  (strlen-safe-macro "hello, world")
  (strlen-safe-macro* "hello, world")
  (strlen-primitive-macro "hello, world"))

;; Type specifiers and variable names in foreign-lambda in macros
;; are incorrectly renamed in modules, too.
(foreign-declare "void foo(void *abc) { printf(\"hi\\n\"); }")
;; This is silly but at least it ensures we can represent enum values
(foreign-declare "enum intlimits {min=INT_MIN, zero=0, max=INT_MAX};")

(module foo ()
  (import scheme chicken.base chicken.foreign)

  (let-syntax ((fl
                (syntax-rules ()
                  ((_)
                   (foreign-lambda void foo (c-pointer void)))))
               (fl*
                (syntax-rules ()
                  ((_)
                   (foreign-lambda* void (((c-pointer void) a))
                                    "C_return(a);"))))
               (fp
                (syntax-rules ()
                  ((_)
                   (foreign-primitive void (((c-pointer void) a))
                                      "C_return(a);")))))
    (fl)
    (fl*)
    (fp)))


;; "const" qualifier should have no visible effect in Scheme
(define-syntax generate-external
  (syntax-rules ()
    ((_) (define-external
           (print_foo ((const c-string) foo))
           void
           (assert (string? foo))
           (print foo)))))
(generate-external)
((foreign-safe-lambda* void () 
   "print_foo(\"bar\");"))


;; Unused arguments in foreign callback wrappers are not optimized away (#584)
(module bla (foo)

(import (prefix scheme s:) (only chicken.base assert) chicken.foreign)

(define-external
  (blabla (int a) (c-string b) (int c) (int d) (c-string e) (int f))
  int
  f)

(s:define (foo) ((foreign-safe-lambda* int () "C_return(blabla(1, \"2\", 3, 4, \"5\", 6));")))

(assert (location blabla))
)

(import bla)
(assert (= (foo) 6))


;;; compiler-syntax for map/for-each must be careful when the
;   operator may have side-effects (currently only lambda exprs and symbols
;   are allowed)

(let ((x #f))
  (define (f1 x) (print* x " "))
  (map f1 '(1 2 3))
  (newline)
  (map (begin (assert (not x)) 
	      (set! x #t)
	      f1)
       '(1 2 3))
  (map (lambda (x) (print* ":" x)) '(1 2 3))
  (newline))

(let ((x #f))
  (define (f1 x) (print* x " "))
  (let-syntax ((f1 (syntax-rules ()
		     ((_ y) 
		      (begin
			(assert (not x))
			(set! x #t)
			f1)))))
    (for-each f1 '(1 2 3))))

(newline)

;; Test safety of ##sys#make-c-string
(handle-exceptions exn (print "Good, unrepresentable C strings cause errors")
                   (print "BUG! We got, without error, length = "
                          ((foreign-lambda* int ((c-string str))
                                            "C_return(strlen(str));")
                           "foo\x00bar")))


;; failed compile-time argument count check (reported by Alan Post)
;; cbb27fe380ff8e45cdf04d812e1ec649bf45ca47

(define (foo)
  (define (bar #!key a)
    (define (baz)
      (bar a: #t))
    baz)
  bar)


;; global-propagation must also invalidate alias to global if global
;; itself is assigned (reported by Sven Hartrumpf)

(define gp-test-global 0)

(define (gp-test)
  (let ((a gp-test-global)
	(b gp-test-global))
    (set! gp-test-global 1)
    (assert (zero? a))
    (assert (zero? b))))

(gp-test)

;; Optimizer would "lift" inner-bar out of its let and replace
;; outer-bar with it, even though it wasn't visible yet.  Caused by
;; broken cps-conversion (underlying problem for #1068).
(assert (equal? 1 (let ((outer-bar (##core#undefined)))
                    (let ((inner-bar (let ((tmp (lambda (x)
                                                  (if x '1 (outer-bar '#t)))))
                                       tmp)))
                      (set! outer-bar inner-bar)
                      (outer-bar #f)))))

;; Slightly modified version which broke after fixing the above due 
;; to replacement optimization getting triggered.  This replacement 
;; caused outer-bar to get replaced by inner-bar, even within itself, 
;; thereby causing an undefined variable reference. 
(assert (equal? 1 (let ((outer-bar (##core#undefined))) 
                    (let ((inner-bar (lambda (x)
                                       (if x '1 (outer-bar outer-bar))))) 
                      (set! outer-bar inner-bar) 
                      (outer-bar '#f))))) 

;; Found by Claude Marinier: Huge literals with a length which need
;; more than 3 bytes to encode would get silently truncated.  We'll
;; prevent constant-folding if it would lead to such large literals.
(let* ((bignum (expt 2 70000000))
       ;; This prevents complete evaluation at compile-time
       (unknown-bignum ((foreign-lambda* scheme-object
			    ((scheme-object n)) "C_return(n);") bignum)))
  (assert (equal? 70000001 (integer-length unknown-bignum))))


;; Test that encode-literal/decode-literal use the proper functions
;; to decode number literals.
(assert (equal? '(+inf.0 -inf.0) (list (fp/ 1.0 0.0) (fp/ -1.0 0.0))))

;; Test that encode-literal doesn't drop digits for extreme flonum values.

;; This number is 2^971 * (2^53 - 1), and is the positive "all ones" number for
;; 64-bit flonums with precision 53 and significand/mantissa 10.
;; If we want to support 32-bit flonums or flonums with different precision
;; or significand, we need a cond-expand here or something.
;; Technically, even larger decimal numbers can be represented by flonums.
;; This number can correctly be compared exactly.
(assert (= (* (- (expt 2 flonum-precision) 1)
              (expt 2 (- flonum-maximum-exponent flonum-precision)))
           179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
           (string->number "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0")))

;; #955: unsigned-integer64 arg returned magnitude instead of Scheme object.
(assert (eqv? #xAB54A98CEB1F0AD2
	      ((foreign-lambda* unsigned-integer64 ((unsigned-integer64 x))
		 "C_return(x);")
	       #xAB54A98CEB1F0AD2)))


;; Test the maximum and minimum values of the FFI's integer types
(define-syntax test-ffi-type-limits
  (syntax-rules (signed unsigned)
    ((_ ?type-name unsigned ?bits)
     (let ((limit (arithmetic-shift 1 ?bits)))
       (print "Testing unsigned FFI type \"" '?type-name "\" (" ?bits " bits):")
       (print "Can hold maximum value " (sub1 limit) "...")
       (assert
	(eqv? (sub1 limit)
	      ((foreign-lambda* ?type-name ((?type-name x))
		 "C_return(x);") (sub1 limit))))
       (print "Cannot hold one more than maximum value, " limit "...")
       (assert
	(handle-exceptions exn #t
	  (begin ((foreign-lambda* ?type-name ((?type-name x))
		    "C_return(x);") limit)
		 #f)))
       (print "Cannot hold -1 (any fixnum negative value)")
       (assert
	(handle-exceptions exn #t
	  (begin ((foreign-lambda* ?type-name ((?type-name x))
		    "C_return(x);") -1)
		 #f)))
       (print "Cannot hold -2^64 (any bignum negative value < smallest int64)")
       (assert
	(handle-exceptions exn #t
	  (begin ((foreign-lambda* ?type-name ((?type-name x))
		    "C_return(x);") #x-10000000000000000)
		 #f)))))
    ((_ ?type-name signed ?bits)
     (let ((limit (arithmetic-shift 1 (sub1 ?bits))))
       (print "Testing signed FFI type \"" '?type-name "\" (" ?bits " bits):")
       (print "Can hold maximum value " (sub1 limit) "...")
       (assert
	(eqv? (sub1 limit)
	      ((foreign-lambda* ?type-name ((?type-name x))
		 "C_return(x);") (sub1 limit))))
       (print "Can hold minimum value " (- limit) "...")
       (assert
	(eqv? (- limit)
	      ((foreign-lambda* ?type-name ((?type-name x))
		 "C_return(x);") (- limit))))
       (print "Cannot hold one more than maximum value " limit "...")
       (assert
	(handle-exceptions exn #t
	  (begin ((foreign-lambda* ?type-name ((?type-name x))
		    "C_return(x);") limit)
		 #f)))
       (print "Cannot hold one less than minimum value " (- limit) "...")
       (assert
	(handle-exceptions exn #t
	  (begin ((foreign-lambda* ?type-name ((?type-name x))
		    "C_return(x);") (sub1 (- limit)))
		 #f)))))))

(test-ffi-type-limits unsigned-integer32 unsigned 32)
(test-ffi-type-limits integer32 signed 32)

(test-ffi-type-limits unsigned-integer64 unsigned 64)
(test-ffi-type-limits integer64 signed 64)

(test-ffi-type-limits
 unsigned-integer unsigned
 (foreign-value "sizeof(unsigned int) * CHAR_BIT" int))

(test-ffi-type-limits
 integer signed (foreign-value "sizeof(int) * CHAR_BIT" int))

(test-ffi-type-limits
 (enum intlimits) signed
 (foreign-value "sizeof(enum intlimits) * CHAR_BIT" int))

(test-ffi-type-limits
 unsigned-long unsigned
 (foreign-value "sizeof(unsigned long) * CHAR_BIT" int))

(test-ffi-type-limits
 long signed (foreign-value "sizeof(long) * CHAR_BIT" int))

(test-ffi-type-limits
 ssize_t signed (foreign-value "sizeof(ssize_t) * CHAR_BIT" int))

(test-ffi-type-limits
 size_t unsigned (foreign-value "sizeof(size_t) * CHAR_BIT" int))


;; #1059: foreign vector types use wrong lolevel accessors, causing
;; paranoid DEBUGBUILD assertions to fail.
(define-syntax srfi-4-vector-length
  (er-macro-transformer
   (lambda (e r c)
     (let* ((type (symbol->string (strip-syntax (cadr e))))
	    (base-type (string-translate* type '(("nonnull-" . ""))))
	    (length-procedure-name (string-append base-type "-length")))
       `(,(string->symbol length-procedure-name) ,(caddr e))))))

(define-syntax s4v-sum
  (syntax-rules ()
    ((_ "integer" type arg)
     ((foreign-lambda* int ((type v) (int len))
        "int i, result = 0;"
        "for (i = 0; i < len; ++i) {"
        "  result += (int)v[i];"
        "}"
        "C_return(result);") arg (srfi-4-vector-length type arg)))
    ((_ "float" type arg)
     ((foreign-lambda* double ((type v) (int len))
        "int i; double result = 0.0;"
        "for (i = 0; i < len; ++i) {"
        "  result += v[i];"
        "}"
        "C_return(result);") arg (srfi-4-vector-length type arg)))))
(assert (= 10 (s4v-sum "integer" u8vector '#u8(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" u16vector '#u16(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" u32vector '#u32(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" s64vector '#s64(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" nonnull-u8vector '#u8(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" nonnull-u16vector '#u16(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" nonnull-u32vector '#u32(1 2 3 4))))
(assert (= 10 (s4v-sum "integer" nonnull-u64vector '#u64(1 2 3 4))))
(assert (= -10 (s4v-sum "integer" s8vector '#s8(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" s16vector '#s16(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" s32vector '#s32(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" s64vector '#s64(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" nonnull-s8vector '#s8(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" nonnull-s16vector '#s16(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" nonnull-s32vector '#s32(-1 -2 -3 -4))))
(assert (= -10 (s4v-sum "integer" nonnull-s64vector '#s64(-1 -2 -3 -4))))
(assert (= 12.0 (s4v-sum "float" f32vector '#f32(1.5 2.5 3.5 4.5))))
(assert (= 12.0 (s4v-sum "float" f64vector '#f64(1.5 2.5 3.5 4.5))))
(assert (= 12.0 (s4v-sum "float" nonnull-f32vector '#f32(1.5 2.5 3.5 4.5))))
(assert (= 12.0 (s4v-sum "float" nonnull-f64vector '#f64(1.5 2.5 3.5 4.5))))


;; Reported by Jörg Wittenberger: in some cases, -profile would
;; generate calls to procedures.  This was due to calls to pure
;; procedures not getting replaced with explicitly consed rest
;; list when the procedures themselves were hidden.
(module explicitly-consed-rest-args-bug (do-it also-do-it)
 (import scheme chicken.base chicken.type)

 (: get-value (* * #!rest * --> *))
 (define (get-value x y . rest)
   (apply x y rest))
 (define (do-it arg)
   (get-value arg 2))
 (define (also-do-it arg)
   (get-value arg 3))
)

; let-location with const-wrapped type
(let-location ((foo (const c-string) "boo"))
  (assert (equal? foo "boo")))

; #1424: a foreign lambda with const return type was wrongly rejected
(let ((v0 ((foreign-lambda* c-string () "C_return(\"str\");")))
      (v1 ((foreign-lambda* (const c-string) () "C_return(\"str\");"))))
  (assert (equal? v0 v1)))

; #1630: inlining may result in incorrectly flagged argument-
;   count errors.
(define (outer x y)
  (define (append-map proc . lsts)
    (if (null? lsts)
        (proc 1)
        (apply proc lsts)))
  (append-map (lambda (a) (assert (= a 1))))
  (append-map (lambda (a b) (assert (and (= a 3) (= b 4))))
    x y))
(outer 3 4)

; #1703: argvector re-use interfered with rest-arg optimization
(define reduce (lambda (_l ini) (+ ini 1)))

(print ((lambda xs (reduce xs (car xs))) 1 2 3)) ;; prints 2

(define fold- (lambda xs (reduce xs (car xs))))
(print (fold- 1 2 3))

; libraries are only loaded when entry point is called
(let ()
  (if #f (require-library (chicken repl)))
  (assert (not (##sys#symbol-has-toplevel-binding? 'chicken.repl#repl)))
  (if #t (require-library (chicken repl)))
  (assert (##sys#symbol-has-toplevel-binding? 'chicken.repl#repl)))
