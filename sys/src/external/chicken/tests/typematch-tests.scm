;;;; typematch-tests.scm


(import chicken.blob chicken.condition chicken.memory chicken.locative)

(include "test.scm")

(define (bar) 42)

(define-syntax subtype
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t1 t2)
	`(test-equal ',(strip-syntax e)
	   (compiler-typecase (the ,t1 1)
	     (,t2 #t)
	     (else #f))
	   #t))
      (cdr e)))))

(define-syntax not-subtype
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t1 t2)
	`(test-equal ',(strip-syntax e)
	   (compiler-typecase (the ,t1 1)
	     (,t2 #t)
	     (else #f))
	   #f))
      (cdr e)))))

(define-syntax proper-subtype
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t1 t2)
	`(begin
	   (subtype ,t1 ,t2)
	   (not-subtype ,t2 ,t1)))
      (cdr e)))))

(define-syntax compatible
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t1 t2)
	`(begin
	   (subtype ,t1 ,t2)
	   (subtype ,t2 ,t1)))
      (cdr e)))))

(define-syntax incompatible
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t1 t2)
	`(begin
	   (not-subtype ,t1 ,t2)
	   (not-subtype ,t2 ,t1)))
      (cdr e)))))

(define-syntax infer
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t x)
	;; TODO: test-equal smashes types: change rest of the macros
	;; to handle this
	`(let ((res (compiler-typecase ,x
		      (,t #t)
		      (else #f))))
	   (test-equal ',(strip-syntax e) res #t)))
      (cdr e)))))

(define-syntax infer-not
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t x)
	`(test-equal ',(strip-syntax e)
	   (compiler-typecase ,x
	     (,t #t)
	     (else #f))
	   #f))
      (cdr e)))))

(define-syntax infer-last
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (types x)
	`(test-equal ',(strip-syntax e)
	   (compiler-typecase ,x
	     ,@(map (lambda (t) `(,t #f)) (cdr (reverse types)))
	     (,(car (reverse types)) #t)
	     ;; (else #f)
	     )
	   #t))
      (cdr e)))))

(define-syntax ms
  (er-macro-transformer
   (lambda (x r c)
     (let ((fname (gensym))
	   (fname2 (gensym))
	   (val (cadr x))
	   (nval (caddr x))
	   (type (cadddr x)))
       `(begin
	  (print "specialize " ',type)
	  (: ,fname (,type -> *)
	     ((,type) 'ok)
	     (((not ,type)) 'ok-too))
	  (define (,fname x) 'bomb)
	  (assert (eq? 'ok (,fname ,val)) "did not specialize" ',val ',type)
	  (assert (eq? 'ok-too (,fname ,nval)) "did specialize" ',nval ',type)
	  (: ,fname2 (* -> *)
	     (((not ,type)) 'bomb))
	  (define (,fname2 x) 'ok)
	  (print "specialize not " ',type)
	  (,fname2 ,val))))))

(define-syntax check
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (t of-t not-of-t)
	`(begin
	   (infer ,t ,of-t)
	   (infer-not ,t ,not-of-t)))
      (cdr e)))))

(define-syntax checkp
  (ir-macro-transformer
   (lambda (e _i _c)
     (apply
      (lambda (pred type x)
	`(begin
	   (test-equal '(inferred-type-after true (,pred ,x) is ,type)
	     (let ((tmp (the * ,x)))
	       (if (,pred tmp)
		   (compiler-typecase tmp
		     (,type #t)
		     (else #f))
		   #f))
	     #t)
	   (test-equal '((,pred ,x) is #t)
	     (let ((tmp (the * ,x)))
	       (,pred tmp))
	     #t)
	   (infer-not ,type (##sys#make-structure 'foo))))
      (cdr e)))))

(check fixnum 123 1.2)
(check string "abc" 1.2)
(check symbol 'abc 1.2)
(check char #\x 1.2)
(check true #t #f)
(check false #f #t)
(check integer (+ 1 2) 'a)
(check (list fixnum) '(1) 1.2)
(check (list symbol) '(a) 1.2)
(check (list fixnum) (list 1) '(1 . 2))
(check pair '(1 . 2) '())
(check procedure + 1.2)
(check vector '#(1) 1.2)
(check null '() 1)
(check port (current-input-port) 1.2)
(check input-port (current-input-port) 1.2)
(check blob (make-blob 10) 1.2)
(check pointer (address->pointer 0) 1.2)
(check pointer-vector (make-pointer-vector 1) 1.2)
(check locative (make-locative "a") 1.2)
(check (struct promise) (##sys#make-structure 'promise) 1)
(check (pair fixnum float) '(1 . 2.3) '(a))
(check (vector symbol) '#(a) 1)
(check (list string) '("ok") 1)

(ms 123 1.2 fixnum)
(ms "abc" 1.2 string)
(ms 'abc 1.2 symbol)
(ms #\x 1.2 char)
(ms #t #f true)
(ms #f #t false)
(ms '(1) 1.2 (list fixnum))
(ms '(1 . 2) '() pair)
(ms + 1.2 procedure)
(ms '#(1) 1.2 (vector fixnum))
(ms '() 1 null)
(ms (void) 1.2 undefined)
(ms (current-input-port) 1.2 input-port)
(ms (make-blob 10) 1.2 blob)
(ms (address->pointer 0) 1.2 pointer)
(ms (make-pointer-vector 1) 1.2 pointer-vector)
(ms (make-locative "a") 1.2 locative)
(ms (##sys#make-structure 'promise) 1 (struct promise))
(ms '(1 . 2.3) '(a) (pair fixnum float))
(ms '#(a) 1 (vector symbol))
(ms '(1) "a" (or (list fixnum) symbol))
(ms (list 1) 'a (list fixnum))
(ms '() 'a (or null pair))

(define n 1)

;; What about these? should they are not predicates currently.
;; (checkp real? number (+ n))
;; (checkp exact? fixnum '1)
(checkp exact? number '1)
;; (checkp inexact? float '1.2)
(checkp inexact? number '1.2)

(checkp boolean? boolean #f)
(checkp boolean? boolean #t)
(checkp pair? pair '(1 . 2))
(checkp null? null '())
(checkp symbol? symbol 'a)
(checkp number? number (+ n))
(checkp complex? number (+ n))
(checkp char? char #\a)
(checkp string? string "a")
(checkp vector? vector '#())
(checkp procedure? procedure +)
(checkp blob? blob (make-blob 1))
(checkp condition? (struct condition) (##sys#make-structure 'condition))
(checkp fixnum? fixnum 1)
(checkp flonum? float 1.2)
(checkp port? port (current-input-port))
(checkp input-port? input-port (current-input-port))
(checkp output-port? output-port (current-output-port))
(checkp pointer-vector? pointer-vector (make-pointer-vector 1))
(checkp pointer? pointer (address->pointer 1))

(proper-subtype null list)
(proper-subtype (list *) list)
(proper-subtype (vector *) vector)

(define-type x (struct x))

(incompatible (refine (b) x) (refine (a) x))
(incompatible (refine (a b) x) (refine (b c) x))
(proper-subtype (refine (a) x) x)
(proper-subtype (refine (a b) x) (refine (a) x))
(proper-subtype (refine (b a) x) (refine (a) x))
(proper-subtype (refine (a) false) (refine (a) boolean))

(incompatible pair null)
(incompatible pair list)

(incompatible (procedure (*) *) (procedure () *))
(compatible (procedure (#!rest) . *) (procedure (*) . *))
(incompatible (procedure () *) (procedure () * *))

(infer (forall (a) (procedure (#!rest a) a)) +)
(infer (list fixnum) '(1))

(define something)

(infer port (open-input-string "foo"))
(infer input-port (open-input-string "bar"))
(infer port (open-output-string))
(infer output-port (open-output-string))

;;; pairs

(: car-alike  (forall (a) ((pair a *) -> a)))
(: cadr-alike (forall (a) ((pair * (pair a *)) -> a)))
(: cddr-alike (forall (a) ((pair * (pair * a)) -> a)))

(define car-alike car)
(define cadr-alike cadr)
(define cddr-alike cddr)

(: l (list-of fixnum))
(: p (pair fixnum (pair fixnum fixnum)))

(define l '(1 2 3))
(define p '(1 2 . 3))

(infer fixnum (car-alike l))
(infer fixnum (car-alike p))
(infer fixnum (cadr-alike l))
(infer fixnum (cadr-alike p))
(infer list   (cddr-alike l))
(infer fixnum (cddr-alike p))

(ms '(1 . 2) '() pair)
(ms '(1 2) '() pair)
(ms '(1) '() pair)
(ms '() '(1) (not pair))
(ms '() '(1 2) (not pair))
(ms '() '(1 . 2) (not pair))
(ms '() '(1 . 2) list)
(ms '(1 . 2) '() (not list))
(ms '(1 2) '(1 . 2) (pair * pair))
(ms '(1 2) '(1 . 2) (pair * list))
(ms '(1 2) '(1 2 3) (pair * (pair * null)))
(ms '(1 2) '(1 2 3) (pair * (pair * (not pair))))
(ms '(1 2 3) '(1 2) (pair * (pair * (not null))))
(ms '(1 2 . 3) '(1 2 3) (pair * (pair * fixnum)))

(compatible (pair * null) (list *))
(compatible (pair * (list *)) (list * *))
(compatible (pair * (list fixnum)) (list * fixnum))
(compatible (pair fixnum (list *)) (list fixnum *))
(compatible (pair fixnum (pair * null)) (list fixnum *))
(compatible (pair fixnum (pair fixnum null)) (list fixnum fixnum))
(compatible (pair char (list fixnum)) (list char fixnum))
(compatible (pair fixnum (list char)) (list fixnum char))
(compatible (pair fixnum (list fixnum)) (list fixnum fixnum))

(incompatible (pair * *) list)
(incompatible (pair * list) list)
(incompatible (pair fixnum *) (list-of *))
(incompatible (pair fixnum *) (list-of fixnum))
(incompatible (pair fixnum (list-of *)) (list-of fixnum))
(incompatible (pair fixnum (list-of fixnum)) (list-of fixnum))
(incompatible (pair char (list-of fixnum)) (list-of fixnum))
(incompatible (pair fixnum (list-of char)) (list-of fixnum))
(incompatible (pair fixnum (list-of fixnum)) (list-of fixnum))

;;; special cases

(infer (struct foo) (##sys#make-structure 'foo))

(define x 1)

(infer-last (fixnum float number) (vector-ref '#(1 2 3.4) x))
(infer-last (true false boolean) (vector-ref '#(#t #f) x))

(infer (list fixnum float) (list 1 2.3))
(infer (list fixnum float) (list-tail (list 1 2.3) 0))
(infer (list fixnum string) (reverse (cons "1" (cons 2 '()))))
(infer (list float) (list-tail (list 1 2.3) 1))
(infer (list string fixnum) (reverse (list 1 "2")))
(infer (pair fixnum float) (list-tail (cons 1 2.3) 0))
(infer (vector * *) (make-vector 2))
(infer (vector fixnum float) (vector 1 2.3))
(infer (vector string string) (make-vector 2 "a"))
(infer fixnum (##sys#vector-ref '#(1 2 3.4) 0))
(infer fixnum (list-ref (cons 1 2.3) 0))
(infer fixnum (list-ref (list 1 2.3) 0))
(infer fixnum (vector-ref '#(1 2 3.4) 0))
(infer float (##sys#vector-ref '#(1 2 3.4) 2))
(infer float (list-ref (list 1 2.3) 1))
(infer float (list-tail (cons 1 2.3) 1))
(infer float (vector-ref #(1 2 3.4) 2))
(infer list (reverse (the list (list 1 "2"))))
(infer null (list-tail (list 1 2.3) 2))
(infer null (reverse '()))

(: f1 (forall (a) ((list-of a) -> a)))
(define (f1 x) (car x))
(infer fixnum (f1 '(1)))

(: f2 (forall (a) ((list-of a) -> a)))
(define (f2 x) (car x))
(infer-last (symbol fixnum (or fixnum symbol))
	    (f2 (list (if bar 1 'a))))

(: f3 (forall (a) ((list-of a) -> a)))
(define f3 car)
(define xxx '(1))

(infer fixnum (f3 (the (or (vector-of fixnum) (list-of fixnum)) xxx)))

(infer (forall (a) (or (vector-of a) (list-of a))) (list 123))

(: f4 (forall (a) ((or fixnum (list-of a)) -> a)))
(define f4 identity)
(infer fixnum (f4 '(1)))
(infer-not fixnum (f4 1))

(infer-last ((not port)
	     (not input-port)
	     (not output-port)
	     input-port
	     output-port
	     port)
	    (the port xxx))

(assert ; clause order is respected
 (compiler-typecase 1
   (number #t)
   (fixnum #f)))

;; Always a fixnum
(infer-last (bignum fixnum) #x3fffffff)

;; Is a fixnum on 64-bit, bignum on 32-bit, thus type must be 'integer
(infer-last (bignum fixnum integer) #x4fffffff)

;; Always a bignum
(infer-last (fixnum bignum) #x7fffffffffffffff)

;; Issue #1533
(let ((a (the (or pair null) (cons 1 '()))))
  (length a) ; refine (or pair null) with list (= (list-of *))
  (infer list a))

(compiler-typecase (the (list (struct foo) symbol) (the 'a 1))
  ;; The tv "foo" and "foo" in struct should have no relation
  ((forall (foo) (list (struct foo) foo)) 'ok))

;; Issue #1563
(compiler-typecase (the (forall (a) a) 1) ((forall (a) (list a)) 'ok))

(assert
 (compiler-typecase 1
   ('a #t)))

(assert
 (compiler-typecase (the (list fixnum string string) something)
   ((list 'a 'a 'b) #f)
   ((list 'a 'b 'b) #t)))

(assert
 (compiler-typecase (the (list fixnum string string) something)
   ((forall (a) (list a 'a 'b)) #f)
   ((forall (b) (list 'a 'b b)) #t)))

(assert
 (compiler-typecase (the (list string (list string fixnum)) something)
   ((list 'a (forall (a) (list 'b a))) #f)
   ((list 'b (forall (b) (list b 'a))) #t)))

(infer true (= 3 (+ 1 2))) ; Constant folding should happen before / during scrutiny


;; #1649; foreign types with retconv should not be inferred to have
;; the foreign type's corresponding Scheme type, as the retconv may
;; return a wildly different type.
(define-foreign-type retconverted-foreign-int int identity ->string)
(define-foreign-type argconverted-foreign-int int ->string)

;; retconverted-type gets annotated with type (procedure () fixnum)
;; when the return type should be whatever the retconvert argument
;; to define-foreign-type returns (string in this case)
(let ((retconverted (foreign-lambda retconverted-foreign-int "rand")))
  (infer string (retconverted)))

(let ((argconverted (foreign-lambda argconverted-foreign-int "rand")))
  ;; Currently types with only argconvert get a retconvert as well,
  ;; which is set to ##sys#values.  Ideally we should recognise this and
  ;; know the type is unmodified.
  ;(infer fixnum (argconverted))
  (infer-not fixnum (argconverted)) )

(let ((unconverted (foreign-lambda int "rand")))
  (infer fixnum (unconverted)))

(test-exit)
