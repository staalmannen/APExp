;;;; Unit lolevel testing

(import chicken.format chicken.locative chicken.platform
        chicken.memory chicken.memory.representation srfi-4)

(define-syntax assert-error
  (syntax-rules ()
    ((_ expr) 
     (assert (handle-exceptions _ #t expr #f)))))

; move-memory!

(let ((s "..."))
  (assert-error (move-memory! "abc" s 3 -1)))

; overlapping src and dest, moving "right" (from SRFI-13 tests)
(assert (string=?
	 "aabce"
	 (let ((str (string-copy "abcde")))
	   (move-memory! str str 3 0 1) str)))
;; Specialisation rewrite from types.db
(assert (string=?
	 "aabce"
	 (let ((str (string-copy "abcde")))
	   (move-memory! (make-locative str) (make-locative str) 3 0 1) str)))

; overlapping src and dest, moving "left" (from SRFI-13 tests)
(assert (string=?
	 "bcdde"
	 (let ((str (string-copy "abcde")))
	   (move-memory! str str 3 1) str)))
;; Specialisation rewrite from types.db
(assert (string=?
	 "bcdde"
	 (let ((str (string-copy "abcde")))
	   (move-memory! (make-locative str) (make-locative str) 3 1) str)))

; object-copy

; allocate

(define some-chunk (allocate 23))

(assert some-chunk)

; free

(free some-chunk)

(define some-chunk (allocate 23))

; pointer?

(assert (pointer? some-chunk))

; pointer-like?

(assert (pointer-like? some-chunk))

(assert (pointer-like? allocate))

; address->pointer

; pointer->address

; object->pointer

; pointer->object

; pointer=?

(assert (pointer=? some-chunk (address->pointer (pointer->address some-chunk))))

; pointer+

(assert (pointer=? (address->pointer #x9) (pointer+ (address->pointer #x5) #x4)))

; align-to-word

; pointer-u8-set!

; pointer-s8-set!

; pointer-u16-set!

; pointer-s16-set!

; pointer-u32-set!

; pointer-s32-set!

; pointer-u64-set!

; pointer-s64-set!

; pointer-f32-set!

; pointer-f64-set!

; pointer-u8-ref

(set! (pointer-u8-ref some-chunk) 255)

(assert (= 255 (pointer-u8-ref some-chunk)))

; pointer-s8-ref

(set! (pointer-s8-ref some-chunk) -1)

(assert (= -1 (pointer-s8-ref some-chunk)))

; pointer-u16-ref

; pointer-s16-ref

; pointer-u32-ref

; pointer-s32-ref

; pointer-u64-ref

; pointer-s64-ref

; pointer-f32-ref

; pointer-f64-ref

; tag-pointer

(define some-unique-tag '#(vector foo bar))

(define some-tagged-pointer (tag-pointer some-chunk some-unique-tag))

(assert some-tagged-pointer)

; tagged-pointer?

(assert (tagged-pointer? some-tagged-pointer))

(assert (tagged-pointer? some-tagged-pointer some-unique-tag))

; pointer-tag

(assert (eq? some-unique-tag (pointer-tag some-tagged-pointer)))

; make-locative, locative-ref, locative-set!, locative?

;; Reverse an object vector of the given type by going through
;; locatives.
(define-syntax check-type-locative
  (ir-macro-transformer
   (lambda (e i c)
     (let* ((type (strip-syntax (cadr e)))
	    (inits (cddr e))
	    (size (length inits))
	    (construct type)
	    (make (i (symbol-append 'make- type)))
	    (ref (i (symbol-append type '-ref))))
       `(let* ((old (,construct ,@inits))
	       (new (,make ,size)))
	  ;; Copy first
	  (do ((i 0 (add1 i)))
	      ((= i ,size))
	    (let ((loc-src (make-locative old i))
		  (loc-dst (make-locative new (- ,size i 1))))
	      (assert (locative? loc-src))
	      (assert (locative? loc-dst))
	      (locative-set! loc-dst (locative-ref loc-src))))
	  (printf "\nold: ~S\nnew: ~S\n" old new)
	  ;; Now compare (unroll loop for better error reporting)
	  ,@(let lp ((i 0) (res '()))
	      (if (= i size)
		  res
		  (lp (add1 i)
		      ;; Note: we must use eqv? because extraction
		      ;; may cause fresh object allocation.
		      (cons `(assert (eqv? (,ref old ,i)
					   (,ref new ,(- size i 1))))
			    res)))))))))

(check-type-locative string #\nul #\y #\o #\xff)
(check-type-locative vector 'yo 1 2 #f #t '(1 2 3) #(1 2 3))
(check-type-locative u8vector 0 1 2 #xfe #xff)
(check-type-locative s8vector #x-80 #x-7f -2 -1 0 1 2 #x7e #x7f)
(check-type-locative u16vector 0 1 2 #xfffe #xffff)
(check-type-locative s16vector #x-8000 #x-7fff -2 -1 0 1 2 #x7ffe #x7fff)
(check-type-locative u32vector 0 1 2 #xfffffffe #xffffffff)
(check-type-locative s32vector
		     #x-80000000 #x-7fffffff -2 -1
		     0 1 2 #x7ffffffe #x7fffffff)
(check-type-locative u64vector
		     0 1 2 #xfffffffffffffffe #xffffffffffffffff)
(check-type-locative s64vector
		     #x-8000000000000000 #x-7fffffffffffffff -2 -1
		     0 1 2 #x7ffffffffffffffe #x7fffffffffffffff)
;; TODO: better/more extreme values?
(check-type-locative f32vector -1e100 -2.0 -1.0 0.0 1.0 2.0 1e100)
(check-type-locative f64vector -1e200 -2.0 -1.0 0.0 1.0 2.0 1e200)

; make-weak-locative

; locative->object

; locative-index

;; Default index (0)
(assert (= 0 (locative-index (make-locative '(0 . 1)))))
(assert (= 0 (locative-index (make-locative #(a b c d e)))))
(assert (= 0 (locative-index (make-locative "abcde"))))
(assert (= 0 (locative-index (make-locative #${012345}))))
(assert (= 0 (locative-index (make-locative #u8(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #s8(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #u16(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #s16(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #u32(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #s32(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #u64(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #s64(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #f32(0 1 2 3 4)))))
(assert (= 0 (locative-index (make-locative #f64(0 1 2 3 4)))))

;; Given index argument
(assert (= 1 (locative-index (make-locative '(0 . 1) 1))))
(assert (= 2 (locative-index (make-locative #(a b c d e) 2))))
(assert (= 3 (locative-index (make-locative "abcde" 3))))
(assert (= 2 (locative-index (make-locative #${01234} 2))))
(assert (= 1 (locative-index (make-locative #u8(0 1 2 3 4) 1))))
(assert (= 2 (locative-index (make-locative #s8(0 1 2 3 4) 2))))
(assert (= 3 (locative-index (make-locative #u16(0 1 2 3 4) 3))))
(assert (= 2 (locative-index (make-locative #s16(0 1 2 3 4) 2))))
(assert (= 1 (locative-index (make-locative #u32(0 1 2 3 4) 1))))
(assert (= 2 (locative-index (make-locative #s32(0 1 2 3 4) 2))))
(assert (= 3 (locative-index (make-locative #u64(0 1 2 3 4) 3))))
(assert (= 2 (locative-index (make-locative #s64(0 1 2 3 4) 2))))
(assert (= 1 (locative-index (make-locative #f32(0 1 2 3 4) 1))))
(assert (= 2 (locative-index (make-locative #f64(0 1 2 3 4) 2))))

; extend-procedure

(define (foo a b) (list a b))

(define unique-proc-data-1 '(23 'skidoo))

(define new-foo (extend-procedure foo unique-proc-data-1))

(assert (not (eq? foo new-foo)))

(define foo new-foo)

; extended-procedure?

(assert (extended-procedure? foo))

; procedure-data

(assert (eq? unique-proc-data-1 (procedure-data foo)))

; set-procedure-data!

(define unique-proc-data-2 '(23 'skidoo))

(set-procedure-data! foo unique-proc-data-2)

(assert (eq? unique-proc-data-2 (procedure-data foo)))

; block-set!

(define some-block (vector 1 2 3 4))

(block-set! some-block 2 5)

; block-ref

(assert (= 5 (block-ref some-block 2)))

; number-of-slots

(assert (= 4 (number-of-slots some-block)))

; number-of-bytes

(assert (= 4 (number-of-bytes "abcd")))

(assert (= (if (feature? #:64bit) 8 4) (number-of-bytes '#(1))))

; make-record-instance

(define some-record (make-record-instance 'test 'a 1))

(assert some-record)

; record-instance?

(assert (record-instance? some-record))

(assert (record-instance? some-record 'test))

; record-instance-type

(assert (eq? 'test (record-instance-type some-record)))

; record-instance-length

(assert (= 2 (record-instance-length some-record)))

; record-instance-slot-set!

; record-instance-slot

(assert (eq? 1 (record-instance-slot some-record 1)))

(record-instance-slot-set! some-record 1 'b)

(assert (eq? 'b (record-instance-slot some-record 1)))

; record->vector

(assert (equal? '#(test a b) (record->vector some-record)))

; object-become!

(define some-foo '#(1 2 3))

(define some-bar '(1 2 3))

(object-become! (list (cons some-foo '(1 2 3)) (cons some-bar '#(1 2 3))))

(assert (pair? some-foo))

(assert (vector? some-bar))

; mutate-procedure!

(assert (equal? '(1 2) (foo 1 2)))

(define new-foo
  (mutate-procedure! foo (lambda (new) (lambda args (cons 'hello (apply new args))))))

(assert (not (eq? foo new-foo)))

(assert (equal? '(hello 1 2) (foo 1 2)))

; pointer vectors

(define pv (make-pointer-vector 42 #f))
(assert (= 42 (pointer-vector-length pv)))
(assert (not (pointer-vector-ref pv 0)))
(pointer-vector-set! pv 1 (address->pointer 999))
(set! (pointer-vector-ref pv 40) (address->pointer 777))
(assert (not (pointer-vector-ref pv 0)))
(assert (not (pointer-vector-ref pv 41)))
(assert (= (pointer->address (pointer-vector-ref pv 1)) 999))
(assert (= (pointer->address (pointer-vector-ref pv 40)) 777))
(pointer-vector-fill! pv (address->pointer 1))
(assert (= 1 (pointer->address (pointer-vector-ref pv 0))))

#+(not csi)
(begin
  (define pv1
    (foreign-lambda* bool ((pointer-vector pv))
      "C_return(pv == NULL);"))
  (define pv2
    (foreign-lambda* c-pointer ((pointer-vector pv) (bool f))
      "static void *xx = (void *)123;"
      "if(f) pv[ 0 ] = xx;"
      "C_return(xx);"))
  (assert (eq? #t (pv1 #f)))
  (define p (pv2 pv #t))
  (assert (pointer=? p (pv2 pv #f))))
