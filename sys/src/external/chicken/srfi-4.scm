;;;; srfi-4.scm - Homogeneous numeric vectors
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer.
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution.
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.


(declare
  (unit srfi-4)
  (uses expand extras)
  (disable-interrupts)
  (not inline ##sys#user-print-hook)
  (foreign-declare #<<EOF
#define C_copy_subvector(to, from, start_to, start_from, bytes)   \
  (C_memcpy((C_char *)C_data_pointer(to) + C_unfix(start_to), (C_char *)C_data_pointer(from) + C_unfix(start_from), C_unfix(bytes)), \
    C_SCHEME_UNDEFINED)
EOF
) )

(module srfi-4
  (blob->f32vector blob->f32vector/shared
   blob->f64vector blob->f64vector/shared
   blob->s16vector blob->s16vector/shared
   blob->s32vector blob->s32vector/shared
   blob->s64vector blob->s64vector/shared
   blob->s8vector blob->s8vector/shared
   blob->u16vector blob->u16vector/shared
   blob->u32vector blob->u32vector/shared
   blob->u64vector blob->u64vector/shared
   blob->u8vector blob->u8vector/shared
   f32vector f32vector->blob f32vector->blob/shared f32vector->list
   f32vector-length f32vector-ref f32vector-set! f32vector?
   f64vector f64vector->blob f64vector->blob/shared f64vector->list
   f64vector-length f64vector-ref f64vector-set! f64vector?
   s8vector s8vector->blob s8vector->blob/shared s8vector->list
   s8vector-length s8vector-ref s8vector-set! s8vector?
   s16vector s16vector->blob s16vector->blob/shared s16vector->list
   s16vector-length s16vector-ref s16vector-set! s16vector?
   s32vector s32vector->blob s32vector->blob/shared s32vector->list
   s32vector-length s32vector-ref s32vector-set! s32vector?
   s64vector s64vector->blob s64vector->blob/shared s64vector->list
   s64vector-length s64vector-ref s64vector-set! s64vector?
   u8vector u8vector->blob u8vector->blob/shared u8vector->list
   u8vector-length u8vector-ref u8vector-set! u8vector?
   u16vector u16vector->blob u16vector->blob/shared u16vector->list
   u16vector-length u16vector-ref u16vector-set! u16vector?
   u32vector u32vector->blob u32vector->blob/shared u32vector->list
   u32vector-length u32vector-ref u32vector-set! u32vector?
   u64vector u64vector->blob u64vector->blob/shared u64vector->list
   u64vector-length u64vector-ref u64vector-set! u64vector?
   list->f32vector list->f64vector list->s16vector list->s32vector
   list->s64vector list->s8vector list->u16vector list->u32vector
   list->u8vector list->u64vector
   make-f32vector make-f64vector make-s16vector make-s32vector
   make-s64vector make-s8vector make-u16vector make-u32vector
   make-u64vector make-u8vector
   number-vector? read-u8vector read-u8vector! release-number-vector
   subf32vector subf64vector subs16vector subs32vector subs64vector
   subs8vector subu16vector subu8vector subu32vector subu64vector
   write-u8vector)

(import scheme
	chicken.base
	chicken.bitwise
	chicken.fixnum
	chicken.foreign
	chicken.gc
	chicken.platform
	chicken.syntax)

(include "common-declarations.scm")


;;; Helper routines:

(define-inline (check-int/flonum x loc)
  (unless (or (##core#inline "C_i_exact_integerp" x)
	      (##core#inline "C_i_flonump" x))
    (##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR" int) loc x) ) )

(define-inline (check-range i from to loc)
  (##sys#check-fixnum i loc)
  (unless (and (fx<= from i) (fx< i to))
    (##sys#error-hook
     (foreign-value "C_OUT_OF_RANGE_ERROR" int)
     loc i from to) ) )

(define-inline (check-uint-length obj len loc)
  (##sys#check-exact-uinteger obj loc)
  (when (fx> (integer-length obj) len)
    (##sys#error-hook
     (foreign-value "C_OUT_OF_RANGE_ERROR" int) loc obj 0 (expt 2 len))))

(define-inline (check-int-length obj len loc)
  (##sys#check-exact-integer obj loc)
  (when (fx> (integer-length obj) (fx- len 1))
    (##sys#error-hook
     (foreign-value "C_OUT_OF_RANGE_ERROR" int)
     loc obj (- (expt 2 len)) (sub1 (expt 2 len)))))

;;; Get vector length:

(define (u8vector-length x)
  (##core#inline "C_i_u8vector_length" x))

(define (s8vector-length x)
  (##core#inline "C_i_s8vector_length" x))

(define (u16vector-length x)
  (##core#inline "C_i_u16vector_length" x))

(define (s16vector-length x)
  (##core#inline "C_i_s16vector_length" x))

(define (u32vector-length x)
  (##core#inline "C_i_u32vector_length" x))

(define (s32vector-length x)
  (##core#inline "C_i_s32vector_length" x))

(define (u64vector-length x)
  (##core#inline "C_i_u64vector_length" x))

(define (s64vector-length x)
  (##core#inline "C_i_s64vector_length" x))

(define (f32vector-length x)
  (##core#inline "C_i_f32vector_length" x))

(define (f64vector-length x)
  (##core#inline "C_i_f64vector_length" x))


;;; Safe accessors:

(define (u8vector-set! x i y)
  (##core#inline "C_i_u8vector_set" x i y))

(define (s8vector-set! x i y)
  (##core#inline "C_i_s8vector_set" x i y))

(define (u16vector-set! x i y)
  (##core#inline "C_i_u16vector_set" x i y))

(define (s16vector-set! x i y)
  (##core#inline "C_i_s16vector_set" x i y))

(define (u32vector-set! x i y)
  (##core#inline "C_i_u32vector_set" x i y))

(define (s32vector-set! x i y)
  (##core#inline "C_i_s32vector_set" x i y))

(define (u64vector-set! x i y)
  (##core#inline "C_i_u64vector_set" x i y))

(define (s64vector-set! x i y)
  (##core#inline "C_i_s64vector_set" x i y))

(define (f32vector-set! x i y)
  (##core#inline "C_i_f32vector_set" x i y))

(define (f64vector-set! x i y)
  (##core#inline "C_i_f64vector_set" x i y))

(define u8vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline "C_i_u8vector_ref" x i))
   u8vector-set!
   "(chicken.srfi-4#u8vector-ref v i)"))

(define s8vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline "C_i_s8vector_ref" x i))
   s8vector-set!
   "(chicken.srfi-4#s8vector-ref v i)"))

(define u16vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline "C_i_u16vector_ref" x i))
   u16vector-set!
   "(chicken.srfi-4#u16vector-ref v i)"))

(define s16vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline "C_i_s16vector_ref" x i))
   s16vector-set!
   "(chicken.srfi-4#s16vector-ref v i)"))
   
(define u32vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_u32vector_ref" 5) x i))
   u32vector-set!
   "(chicken.srfi-4#u32vector-ref v i)"))

(define s32vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_s32vector_ref" 5) x i))
   s32vector-set!
   "(chicken.srfi-4#s32vector-ref v i)"))

(define u64vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_u64vector_ref" 7) x i))
   u64vector-set!
   "(chicken.srfi-4#u64vector-ref v i)"))

(define s64vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_s64vector_ref" 7) x i))
   s64vector-set!
   "(chicken.srfi-4#s64vector-ref v i)"))

(define f32vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_f32vector_ref" 4) x i))
   f32vector-set!
   "(chicken.srfi-4#f32vector-ref v i)"))

(define f64vector-ref
  (getter-with-setter
   (lambda (x i) (##core#inline_allocate ("C_a_i_f64vector_ref" 4) x i))
   f64vector-set!
   "(chicken.srfi-4#f64vector-ref v i)"))


;;; Basic constructors:

(define make-f32vector)
(define make-f64vector)
(define make-s16vector)
(define make-s32vector)
(define make-s64vector)
(define make-s8vector)
(define make-u8vector)
(define make-u16vector)
(define make-u32vector)
(define make-u64vector)
(define release-number-vector)

(let* ((ext-alloc
	(foreign-lambda* scheme-object ((size_t bytes))
	  "if (bytes > C_HEADER_SIZE_MASK) C_return(C_SCHEME_FALSE);"
	  "C_word *buf = (C_word *)C_malloc(bytes + sizeof(C_header));"
	  "if(buf == NULL) C_return(C_SCHEME_FALSE);"
	  "C_block_header_init(buf, C_make_header(C_BYTEVECTOR_TYPE, bytes));"
	  "C_return(buf);") )
       (ext-free
	(foreign-lambda* void ((scheme-object bv))
	  "C_free((void *)C_block_item(bv, 1));") )
       (alloc
	(lambda (loc elem-size elems ext?)
	  (##sys#check-fixnum elems loc)
	  (when (fx< elems 0) (##sys#error loc "size is negative" elems))
	  (let ((len (fx*? elems elem-size)))
	    (unless len (##sys#error "overflow - cannot allocate the required number of elements" elems))
	    (if ext?
		(let ((bv (ext-alloc len)))
		  (or bv
		      (##sys#error loc "not enough memory - cannot allocate external number vector" len)) )
		(let ((bv (##sys#allocate-vector len #t #f #t))) ; this could be made better...
		  (##core#inline "C_string_to_bytevector" bv)
		  bv) ) ) ) ))

  (set! release-number-vector
    (lambda (v)
      (if (number-vector? v)
	  (ext-free v)
	  (##sys#error 'release-number-vector "bad argument type - not a number vector" v)) ) )

  (set! make-u8vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'u8vector (alloc 'make-u8vector 1 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-uint-length init 8 'make-u8vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_u8vector_set" v i init) ) ) ) ) ) )

  (set! make-s8vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 's8vector (alloc 'make-s8vector 1 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-uint-length init 8 'make-s8vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_s8vector_set" v i init) ) ) ) ) ) )

  (set! make-u16vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'u16vector (alloc 'make-u16vector 2 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-uint-length init 16 'make-u16vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_u16vector_set" v i init) ) ) ) ) ) )

  (set! make-s16vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 's16vector (alloc 'make-s16vector 2 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-int-length init 16 'make-s16vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_s16vector_set" v i init) ) ) ) ) ) )

  (set! make-u32vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'u32vector (alloc 'make-u32vector 4 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-uint-length init 32 'make-u32vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_u32vector_set" v i init) ) ) ) ) ) )

  (set! make-u64vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'u64vector (alloc 'make-u64vector 8 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-uint-length init 64 'make-u64vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_u64vector_set" v i init) ) ) ) ) ) )

  (set! make-s32vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 's32vector (alloc 'make-s32vector 4 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-int-length init 32 'make-s32vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_s32vector_set" v i init) ) ) ) ) ) )

   (set! make-s64vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 's64vector (alloc 'make-s64vector 8 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-int-length init 64 'make-s64vector)
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_s64vector_set" v i init) ) ) ) ) ) )

  (set! make-f32vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'f32vector (alloc 'make-f32vector 4 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-int/flonum init 'make-f32vector)
	      (unless (##core#inline "C_i_flonump" init)
		(set! init (##core#inline_allocate ("C_a_u_i_int_to_flo" 4) init)))
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_f32vector_set" v i init) ) ) ) ) ) )

  (set! make-f64vector
    (lambda (len #!optional (init #f)  (ext? #f) (fin? #t))
      (let ((v (##sys#make-structure 'f64vector (alloc 'make-f64vector 8 len ext?))))
	(when (and ext? fin?) (set-finalizer! v ext-free))
	(if (not init)
	    v
	    (begin
	      (check-int/flonum init 'make-f64vector)
	      (unless (##core#inline "C_i_flonump" init)
		(set! init (##core#inline_allocate ("C_a_u_i_int_to_flo" 4) init)) )
	      (do ((i 0 (##core#inline "C_fixnum_plus" i 1)))
		  ((##core#inline "C_fixnum_greater_or_equal_p" i len) v)
		(##core#inline "C_u_i_f64vector_set" v i init) ) ) ) ) ) ) )


;;; Creating vectors from a list:

(define-syntax list->NNNvector 
  (er-macro-transformer 
   (lambda (x r c)
     (let* ((tag (strip-syntax (cadr x)))
	    (tagstr (symbol->string tag))
	    (name (string->symbol (string-append "list->" tagstr)))
	    (make (string->symbol (string-append "make-" tagstr)))
	    (set (string->symbol (string-append tagstr "-set!"))))
       `(define ,name
	  (let ((,make ,make))
	    (lambda (lst)
	      (##sys#check-list lst ',tag)
	      (let* ((n (##core#inline "C_i_length" lst))
		     (v (,make n)) )
		(do ((p lst (##core#inline "C_slot" p 1))
		     (i 0 (##core#inline "C_fixnum_plus" i 1)) )
		    ((##core#inline "C_eqp" p '()) v)
		  (if (and (##core#inline "C_blockp" p) (##core#inline "C_pairp" p))
		      (,set v i (##core#inline "C_slot" p 0))
		      (##sys#error-not-a-proper-list lst ',name) ) ) ) )))))))

(list->NNNvector u8vector)
(list->NNNvector s8vector)
(list->NNNvector u16vector)
(list->NNNvector s16vector)
(list->NNNvector u32vector)
(list->NNNvector s32vector)
(list->NNNvector u64vector)
(list->NNNvector s64vector)
(list->NNNvector f32vector)
(list->NNNvector f64vector)


;;; More constructors:

(define u8vector
  (lambda xs (list->u8vector xs)) )

(define s8vector
  (lambda xs (list->s8vector xs)) )

(define u16vector
  (lambda xs (list->u16vector xs)) )

(define s16vector
  (lambda xs (list->s16vector xs)) )

(define u32vector
  (lambda xs (list->u32vector xs)) )

(define s32vector
  (lambda xs (list->s32vector xs)) )

(define u64vector
  (lambda xs (list->u64vector xs)) )

(define s64vector
  (lambda xs (list->s64vector xs)) )

(define f32vector
  (lambda xs (list->f32vector xs)) )

(define f64vector
  (lambda xs (list->f64vector xs)) )


;;; Creating lists from a vector:

(define-syntax NNNvector->list
  (er-macro-transformer
   (lambda (x r c)
     (let* ((tag (symbol->string (strip-syntax (cadr x))))
	    (alloc (and (pair? (cddr x)) (caddr x)))
	    (name (string->symbol (string-append tag "->list"))))
       `(define (,name v)
	  (##sys#check-structure v ',(string->symbol tag) ',name)
	  (let ((len (##core#inline ,(string-append "C_u_i_" tag "_length") v)))
	    (let loop ((i 0))
	      (if (fx>= i len)
		  '()
		  (cons 
		   ,(if alloc
			`(##core#inline_allocate (,(string-append "C_a_u_i_" tag "_ref") ,alloc) v i)
			`(##core#inline ,(string-append "C_u_i_" tag "_ref") v i))
		   (loop (fx+ i 1)) ) ) ) ) ) ) )))

(NNNvector->list u8vector)
(NNNvector->list s8vector)
(NNNvector->list u16vector)
(NNNvector->list s16vector)
;; The alloc amounts here are for 32-bit words; this over-allocates on 64-bits
(NNNvector->list u32vector 6)
(NNNvector->list s32vector 6)
(NNNvector->list u64vector 7)
(NNNvector->list s64vector 7)
(NNNvector->list f32vector 4)
(NNNvector->list f64vector 4)


;;; Predicates:

(define (u8vector? x) (##core#inline "C_i_u8vectorp" x))
(define (s8vector? x) (##core#inline "C_i_s8vectorp" x))
(define (u16vector? x) (##core#inline "C_i_u16vectorp" x))
(define (s16vector? x) (##core#inline "C_i_s16vectorp" x))
(define (u32vector? x) (##core#inline "C_i_u32vectorp" x))
(define (s32vector? x) (##core#inline "C_i_s32vectorp" x))
(define (u64vector? x) (##core#inline "C_i_u64vectorp" x))
(define (s64vector? x) (##core#inline "C_i_s64vectorp" x))
(define (f32vector? x) (##core#inline "C_i_f32vectorp" x))
(define (f64vector? x) (##core#inline "C_i_f64vectorp" x))

;; Catch-all predicate
(define number-vector? ##sys#srfi-4-vector?)

;;; Accessing the packed bytevector:

(define (pack tag loc)
  (lambda (v)
    (##sys#check-structure v tag loc)
    (##sys#slot v 1) ) )

(define (pack-copy tag loc)
  (lambda (v)
    (##sys#check-structure v tag loc)
    (let* ((old (##sys#slot v 1))
	   (new (##sys#make-blob (##sys#size old))))
      (##core#inline "C_copy_block" old new) ) ) )

(define (unpack tag sz loc)
  (lambda (str)
    (##sys#check-byte-vector str loc)
    (let ([len (##sys#size str)])
      (if (or (eq? #t sz)
	      (eq? 0 (##core#inline "C_fixnum_modulo" len sz)))
	  (##sys#make-structure tag str)
	  (##sys#error loc "blob does not have correct size for packing" tag len sz) ) ) ) )

(define (unpack-copy tag sz loc)
  (lambda (str)
    (##sys#check-byte-vector str loc)
    (let* ((len (##sys#size str))
	   (new (##sys#make-blob len)))
      (if (or (eq? #t sz)
	      (eq? 0 (##core#inline "C_fixnum_modulo" len sz)))
	  (##sys#make-structure
	   tag
	   (##core#inline "C_copy_block" str new) )
	  (##sys#error loc "blob does not have correct size for packing" tag len sz) ) ) ) )

(define u8vector->blob/shared (pack 'u8vector 'u8vector->blob/shared))
(define s8vector->blob/shared (pack 's8vector 's8vector->blob/shared))
(define u16vector->blob/shared (pack 'u16vector 'u16vector->blob/shared))
(define s16vector->blob/shared (pack 's16vector 's16vector->blob/shared))
(define u32vector->blob/shared (pack 'u32vector 'u32vector->blob/shared))
(define s32vector->blob/shared (pack 's32vector 's32vector->blob/shared))
(define u64vector->blob/shared (pack 'u64vector 'u64vector->blob/shared))
(define s64vector->blob/shared (pack 's64vector 's64vector->blob/shared))
(define f32vector->blob/shared (pack 'f32vector 'f32vector->blob/shared))
(define f64vector->blob/shared (pack 'f64vector 'f64vector->blob/shared))

(define u8vector->blob (pack-copy 'u8vector 'u8vector->blob))
(define s8vector->blob (pack-copy 's8vector 's8vector->blob))
(define u16vector->blob (pack-copy 'u16vector 'u16vector->blob))
(define s16vector->blob (pack-copy 's16vector 's16vector->blob))
(define u32vector->blob (pack-copy 'u32vector 'u32vector->blob))
(define s32vector->blob (pack-copy 's32vector 's32vector->blob))
(define u64vector->blob (pack-copy 'u64vector 'u64vector->blob))
(define s64vector->blob (pack-copy 's64vector 's64vector->blob))
(define f32vector->blob (pack-copy 'f32vector 'f32vector->blob))
(define f64vector->blob (pack-copy 'f64vector 'f64vector->blob))

(define blob->u8vector/shared (unpack 'u8vector #t 'blob->u8vector/shared))
(define blob->s8vector/shared (unpack 's8vector #t 'blob->s8vector/shared))
(define blob->u16vector/shared (unpack 'u16vector 2 'blob->u16vector/shared))
(define blob->s16vector/shared (unpack 's16vector 2 'blob->s16vector/shared))
(define blob->u32vector/shared (unpack 'u32vector 4 'blob->u32vector/shared))
(define blob->s32vector/shared (unpack 's32vector 4 'blob->s32vector/shared))
(define blob->u64vector/shared (unpack 'u64vector 4 'blob->u64vector/shared))
(define blob->s64vector/shared (unpack 's64vector 4 'blob->s64vector/shared))
(define blob->f32vector/shared (unpack 'f32vector 4 'blob->f32vector/shared))
(define blob->f64vector/shared (unpack 'f64vector 8 'blob->f64vector/shared))

(define blob->u8vector (unpack-copy 'u8vector #t 'blob->u8vector))
(define blob->s8vector (unpack-copy 's8vector #t 'blob->s8vector))
(define blob->u16vector (unpack-copy 'u16vector 2 'blob->u16vector))
(define blob->s16vector (unpack-copy 's16vector 2 'blob->s16vector))
(define blob->u32vector (unpack-copy 'u32vector 4 'blob->u32vector))
(define blob->s32vector (unpack-copy 's32vector 4 'blob->s32vector))
(define blob->u64vector (unpack-copy 'u64vector 4 'blob->u64vector))
(define blob->s64vector (unpack-copy 's64vector 4 'blob->s64vector))
(define blob->f32vector (unpack-copy 'f32vector 4 'blob->f32vector))
(define blob->f64vector (unpack-copy 'f64vector 8 'blob->f64vector))


;;; Read syntax:

;; This code is too complicated. We try to avoid mapping over
;; a potentially large list anc creating lots of garbage in the
;; process, therefore the final result list is constructed 
;; via destructive updates and thus rather inelegant yet avoids
;; any re-consing unless elements are non-numeric.
(define (canonicalize-number-list! lst1)
  (let loop ((lst lst1) (prev #f))
    (if (and (##core#inline "C_blockp" lst) 
             (##core#inline "C_pairp" lst))
        (let retry ((x (##sys#slot lst 0)))
          (cond ((char? x) (retry (##sys#char->utf8-string x)))
                ((string? x)
                 (if (zero? (string-length x))
                     (loop (##sys#slot lst 1) prev)
                     (let loop2 ((ns (string->list x)) (prev prev))
                       (let ((n (cons (char->integer (##sys#slot ns 0))
                                      (##sys#slot lst 1))))
                         (if prev
                             (##sys#setslot prev 1 n)
                             (set! lst1 n))
                         (let ((ns2 (##sys#slot ns 1)))
                           (if (null? ns2)
                               (loop (##sys#slot lst 1) n)
                               (loop2 (##sys#slot ns 1) n)))))))
                (else (loop (##sys#slot lst 1) lst))))
        (cond (prev (##sys#setslot prev 1 '())
                    lst1)
              (else '())))))

(set! ##sys#user-read-hook
  (let ([old-hook ##sys#user-read-hook]
	[read read]
	[consers (list 'u8 list->u8vector
		       's8 list->s8vector
		       'u16 list->u16vector
		       's16 list->s16vector
		       'u32 list->u32vector
		       's32 list->s32vector
		       'u64 list->u64vector
		       's64 list->s64vector
		       'f32 list->f32vector
		       'f64 list->f64vector) ] )
    (lambda (char port)
      (if (memq char '(#\u #\s #\f #\U #\S #\F))
	  (let* ([x (read port)]
		 [tag (and (symbol? x) x)] )
	    (cond ((or (eq? tag 'f) (eq? tag 'F)) #f)
		  ((memq tag consers) => 
                    (lambda (c)
                      (let ((val (read port)))
                        (if (string? val)
                            (set! val (map char->integer (string->list val)))
                            (set! val (canonicalize-number-list! val)))
                        ((##sys#slot (##sys#slot c 1) 0) val))))
		  (else (##sys#read-error port "illegal bytevector syntax" tag)) ) )
	  (old-hook char port) ) ) ) )


;;; Printing:

(set! ##sys#user-print-hook
  (let ((old-hook ##sys#user-print-hook))
    (lambda (x readable port)
      (let ((tag (assq (##core#inline "C_slot" x 0)
		       `((u8vector u8 ,u8vector->list)
			 (s8vector s8 ,s8vector->list)
			 (u16vector u16 ,u16vector->list)
			 (s16vector s16 ,s16vector->list)
			 (u32vector u32 ,u32vector->list)
			 (s32vector s32 ,s32vector->list)
			 (u64vector u64 ,u64vector->list)
			 (s64vector s64 ,s64vector->list)
			 (f32vector f32 ,f32vector->list)
			 (f64vector f64 ,f64vector->list) ) ) ) )
	(cond (tag
	       (##sys#print #\# #f port)
	       (##sys#print (cadr tag) #f port)
	       (##sys#print ((caddr tag) x) #t port) )
	      (else (old-hook x readable port)) ) ) ) ) )


;;; Subvectors:

(define (subnvector v t es from to loc)
  (##sys#check-structure v t loc)
  (let* ([bv (##sys#slot v 1)]
	 [len (##sys#size bv)]
	 [ilen (##core#inline "C_u_fixnum_divide" len es)] )
    (check-range from 0 (fx+ ilen 1) loc)
    (check-range to 0 (fx+ ilen 1) loc)
    (let* ([size2 (fx* es (fx- to from))]
	   [bv2 (##sys#allocate-vector size2 #t #f #t)] )
      (##core#inline "C_string_to_bytevector" bv2)
      (let ([v (##sys#make-structure t bv2)])
	(##core#inline "C_copy_subvector" bv2 bv 0 (fx* from es) size2)
	v) ) ) )

(define (subu8vector v from to) (subnvector v 'u8vector 1 from to 'subu8vector))
(define (subu16vector v from to) (subnvector v 'u16vector 2 from to 'subu16vector))
(define (subu32vector v from to) (subnvector v 'u32vector 4 from to 'subu32vector))
(define (subu64vector v from to) (subnvector v 'u64vector 8 from to 'subu64vector))
(define (subs8vector v from to) (subnvector v 's8vector 1 from to 'subs8vector))
(define (subs16vector v from to) (subnvector v 's16vector 2 from to 'subs16vector))
(define (subs32vector v from to) (subnvector v 's32vector 4 from to 'subs32vector))
(define (subs64vector v from to) (subnvector v 's64vector 8 from to 'subs64vector))
(define (subf32vector v from to) (subnvector v 'f32vector 4 from to 'subf32vector))
(define (subf64vector v from to) (subnvector v 'f64vector 8 from to 'subf64vector))

(define (write-u8vector v #!optional (port ##sys#standard-output) (from 0) to)
  (##sys#check-structure v 'u8vector 'write-u8vector)
  (##sys#check-output-port port #t 'write-u8vector)
  (let ((len (##core#inline "C_u_i_8vector_length" v)))
    (check-range from 0 (fx+ (or to len) 1) 'write-u8vector)
    (when to (check-range to from (fx+ len 1) 'write-u8vector))
    ; using (write-string) since the "data" slot of a u8vector is
    ; represented the same as a string
    ((##sys#slot (##sys#slot port 2) 3) ; write-string
     port
     (if (and (fx= from 0) (or (not to) (fx= to len)))
	 (##sys#slot v 1)
	 (##sys#slot (subu8vector v from (or to len)) 1)))))

(define (read-u8vector! n dest #!optional (port ##sys#standard-input) (start 0))
  (##sys#check-input-port port #t 'read-u8vector!)
  (##sys#check-fixnum start 'read-u8vector!)
  (##sys#check-structure dest 'u8vector 'read-u8vector!)
  (when n (##sys#check-fixnum n 'read-u8vector!))
  (let* ((dest (##sys#slot dest 1))
	 (size (##sys#size dest)))
    (unless (and n (fx<= (fx+ start n) size))
      (set! n (fx- size start)))
    (chicken.io#read-string!/port n dest port start)))

(define (read-u8vector #!optional n (p ##sys#standard-input))
  (##sys#check-input-port p #t 'read-u8vector)
  (when n (##sys#check-fixnum n 'read-u8vector))
  (let ((str (chicken.io#read-string/port n p)))
    (cond ((eof-object? str) str)
	  (else
	   (##core#inline "C_string_to_bytevector" str)
	   (##sys#make-structure 'u8vector str)))))

(register-feature! 'srfi-4))
