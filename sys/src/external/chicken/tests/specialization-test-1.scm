;;;; specialization-test-1.scm


(module foo (foo bar)
(import scheme chicken.base chicken.foreign chicken.type)

#>
static int inlined(int i) {
static int n = 0;
n += i;
return n;}
<#

(: foo (fixnum -> fixnum))

(define (foo i)
  (print "foo: " i)
  0)

(: bar (number -> fixnum)
   ((fixnum) (##core#inline "inlined" #(1))))

(define (bar i)
  (print "bar: " i)
  0)

(assert (zero? (foo 1)))
(assert (zero? (bar 1.0)))
(assert (= 1 (bar 1)))

(: spec (* -> *))
(define (spec x) x)

(define-specialization (spec (x fixnum)) fixnum
  (+ x 1))

(assert (= 2 (spec 1)))

;; "smash-component-types!" had to convert "list[-of]" types to "pair" (#803)
(let ((x (list 'a)))
  (set-cdr! x x)
  (assert (not (list? x))))

;(define (some-proc x y) (if (string->number y) (set-cdr! x x) x))
;(assert (null? (some-proc (list) "invalid number syntax")))

(assert (null? (the (or undefined *) (list))))

;; Ensure a foreign-primitive returning multiple values with C_values()
;; isn't specialized to a single result.
(let ((result (receive ((foreign-primitive ()
			  "C_word av[ 4 ];"
			  "av[ 0 ] = C_SCHEME_UNDEFINED;"
			  "av[ 1 ] = C_k;"
			  "av[ 2 ] = C_fix(1);"
			  "av[ 3 ] = C_fix(2);"
			  "C_values(4, av);")))))
  (assert (equal? '(1 2) result)))

;; dropped conditional branch is ignored
(compiler-typecase (if #t 'a "a")
  (symbol 1))

;; specializations are prioritized by order of appearance
(: abc (* -> boolean))
(define (abc x) #f)
(define-specialization (abc (x number)) #t)
(define-specialization (abc (x fixnum)) #f)
(assert (abc 1))

;; user-defined specializations take precedence over built-ins
(: foo (-> fixnum))
(define (foo) (begin))
(define-specialization (+ fixnum) fixnum 1)
(assert (= (+ (foo)) 1))

)
