;;;; specialization-test-2.scm


(module main ()
(import scheme chicken.base chicken.foreign)
(import-syntax foo) ; note: does not load foo!

#>
static int inlined(int i) {
static int n = 0;
n += i;
return n;}
<#

(assert (= 1 (bar 1)))

)


;; #855: second walk of arguments after specialization of call to "zero?"
;;       applies enforced type-assumption for argument "y" to "string-length"
;;       to call to "string-length" itself

(define (bug855 x)
  (let ((y (car x)))
    (zero? (string-length y))))

(assert (handle-exceptions ex #t (bug855 '(#f)) #f))

;; #1219: Specializations from databases loaded with "-types" should
;; be applied.
(define (specialize-me x)
  (error "Not specialized!"))

(assert (= (specialize-me 123) 123))
