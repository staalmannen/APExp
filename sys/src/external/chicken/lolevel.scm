;;;; lolevel.scm - Low-level routines for CHICKEN
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
  (unit lolevel)
  (foreign-declare #<<EOF
#ifndef C_NONUNIX
# include <sys/mman.h>
#endif

#define C_memmove_o(to, from, n, toff, foff) C_memmove((char *)(to) + (toff), (char *)(from) + (foff), (n))
EOF
) )

(include "common-declarations.scm")

(module chicken.memory
  (address->pointer align-to-word allocate free make-pointer-vector
   move-memory! object->pointer pointer+ pointer->address
   pointer->object pointer-f32-ref pointer-f32-set! pointer-f64-ref
   pointer-f64-set! pointer-like? pointer-s16-ref pointer-s16-set!
   pointer-s32-ref pointer-s32-set! pointer-s64-ref pointer-s64-set!
   pointer-s8-ref pointer-s8-set! pointer-tag pointer-u16-ref
   pointer-u16-set! pointer-u32-ref pointer-u32-set! pointer-u64-ref
   pointer-u64-set! pointer-u8-ref pointer-u8-set! pointer-vector
   pointer-vector-fill! pointer-vector-length pointer-vector-ref
   pointer-vector-set! pointer-vector? pointer=? pointer? tag-pointer
   tagged-pointer?)

(import scheme chicken.base chicken.fixnum chicken.foreign)


;;; Helpers:

(define-inline (%pointer? x)
  (##core#inline "C_i_safe_pointerp" x))

(define-inline (%generic-pointer? x)
  (or (%pointer? x)
      (##core#inline "C_locativep" x) ) )

(define-inline (%special-block? x)
  ; generic-pointer, port, closure
  (and (##core#inline "C_blockp" x) (##core#inline "C_specialp" x)) )

(define-inline (%generic-vector? x)
  (and (##core#inline "C_blockp" x)
       (not (or (##core#inline "C_specialp" x)
	        (##core#inline "C_byteblockp" x)))) )

(define-inline (%record-structure? x)
  (and (##core#inline "C_blockp" x) (##core#inline "C_structurep" x)) )



;;; Argument checking:

(define (##sys#check-block x . loc)
  (unless (##core#inline "C_blockp" x)
    (##sys#error-hook
     (foreign-value "C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR" int) (and (pair? loc) (car loc))
     x) ) )

(define (##sys#check-become-alist x loc)
  (##sys#check-list x loc)
  (let loop ([lst x])
    (cond [(null? lst) ]
	  [(pair? lst)
	   (let ([a (car lst)])
	     (##sys#check-pair a loc)
	     (##sys#check-block (car a) loc)
	     (##sys#check-block (cdr a) loc)
	     (loop (cdr lst)) ) ]
	  [else
	   (##sys#signal-hook
	    #:type-error loc
	    "bad argument type - not an a-list of block objects" x) ] ) ) )

(define (##sys#check-generic-structure x . loc)
  (unless (%record-structure? x)
    (##sys#signal-hook
     #:type-error (and (pair? loc) (car loc))
     "bad argument type - not a structure" x) ) )

;; Vector, Structure, Pair, and Symbol

(define (##sys#check-generic-vector x . loc)
  (unless (%generic-vector? x)
    (##sys#signal-hook
     #:type-error (and (pair? loc) (car loc))
     "bad argument type - not a vector-like object" x) ) )

(define (##sys#check-pointer x . loc)
  (unless (%pointer? x)
    (##sys#error-hook
     (foreign-value "C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR" int)
     (and (pair? loc) (car loc))
     "bad argument type - not a pointer" x) ) )


;;; Move arbitrary blocks of memory around:

(define move-memory!
  (let ((memmove1 (foreign-lambda void "C_memmove_o" c-pointer c-pointer int int int))
	(memmove2 (foreign-lambda void "C_memmove_o" c-pointer scheme-pointer int int int))
	(memmove3 (foreign-lambda void "C_memmove_o" scheme-pointer c-pointer int int int))
	(memmove4 (foreign-lambda void "C_memmove_o" scheme-pointer scheme-pointer int int int))
	(typerr (lambda (x)
		  (##sys#error-hook
		   (foreign-value "C_BAD_ARGUMENT_TYPE_ERROR" int)
		   'move-memory! x)))
	(slot1structs '(mmap
			u8vector u16vector u32vector u64vector
			s8vector s16vector s32vector s64vector
			f32vector f64vector)) )
    (lambda (from to #!optional n (foffset 0) (toffset 0))
      ;
      (define (nosizerr)
	(##sys#error 'move-memory! "need number of bytes to move" from to))
      ;
      (define (sizerr . args)
	(apply ##sys#error 'move-memory! "number of bytes to move too large" from to args))
      ;
      (define (checkn1 n nmax off)
	(if (fx<= n (fx- nmax off))
	    n
	    (sizerr n nmax) ) )
      ;
      (define (checkn2 n nmax nmax2 off1 off2)
	(if (and (fx<= n (fx- nmax off1)) (fx<= n (fx- nmax2 off2)))
	    n
	    (sizerr n nmax nmax2) ) )
      ;
      (##sys#check-block from 'move-memory!)
      (##sys#check-block to 'move-memory!)
      (when (fx< foffset 0)
	(##sys#error 'move-memory! "negative source offset" foffset))
      (when (fx< toffset 0)
	(##sys#error 'move-memory! "negative destination offset" toffset))
      (let move ([from from] [to to])
	(cond [(##sys#generic-structure? from)
	       (if (memq (##sys#slot from 0) slot1structs)
		   (move (##sys#slot from 1) to)
		   (typerr from) ) ]
	      [(##sys#generic-structure? to)
	       (if (memq (##sys#slot to 0) slot1structs)
		   (move from (##sys#slot to 1))
		   (typerr to) ) ]
	      [(%generic-pointer? from)
	       (cond [(%generic-pointer? to)
		      (memmove1 to from (or n (nosizerr)) toffset foffset)]
		     [(or (##sys#bytevector? to) (string? to))
		      (memmove3 to from (checkn1 (or n (nosizerr)) (##sys#size to) toffset) toffset foffset) ]
		     [else
		      (typerr to)] ) ]
	      [(or (##sys#bytevector? from) (string? from))
	       (let ([nfrom (##sys#size from)])
		 (cond [(%generic-pointer? to)
			(memmove2 to from (checkn1 (or n nfrom) nfrom foffset) toffset foffset)]
		       [(or (##sys#bytevector? to) (string? to))
			(memmove4 to from (checkn2 (or n nfrom) nfrom (##sys#size to) foffset toffset)
				  toffset foffset) ]
		       [else
			(typerr to)] ) ) ]
	      [else
	       (typerr from)] ) ) ) ) )


;;; Pointer operations:

(define allocate (foreign-lambda c-pointer "C_malloc" int))
(define free (foreign-lambda void "C_free" c-pointer))

(define (pointer? x) (%pointer? x))

(define (pointer-like? x) (%special-block? x))

(define (address->pointer addr)
  (##sys#check-integer addr 'address->pointer)
  (##sys#address->pointer addr) )

(define (pointer->address ptr)
  (##sys#check-special ptr 'pointer->address)
  (##sys#pointer->address ptr) )

(define (object->pointer x)
  (and (##core#inline "C_blockp" x)
       ((foreign-lambda* nonnull-c-pointer ((scheme-object x)) "C_return((void *)x);") x) ) )

(define (pointer->object ptr)
  (##sys#check-pointer ptr 'pointer->object)
  (##core#inline "C_pointer_to_object" ptr) )

(define (pointer=? p1 p2)
  (##sys#check-special p1 'pointer=?)
  (##sys#check-special p2 'pointer=?)
  (##core#inline "C_pointer_eqp" p1 p2) )

(define pointer+
  (foreign-lambda* nonnull-c-pointer ([c-pointer ptr] [integer off])
    "C_return((unsigned char *)ptr + off);") )

(define align-to-word
  (let ([align (foreign-lambda integer "C_align" integer)])
    (lambda (x)
      (cond [(integer? x)
	     (align x)]
	    [(%special-block? x)
	     (##sys#address->pointer (align (##sys#pointer->address x))) ]
	    [else
	     (##sys#signal-hook
	      #:type-error 'align-to-word
	      "bad argument type - not a pointer or integer" x)] ) ) ) )


;;; Tagged-pointers:

(define (tag-pointer ptr tag)
  (let ([tp (##sys#make-tagged-pointer tag)])
    (if (%special-block? ptr)
	(##core#inline "C_copy_pointer" ptr tp)
	(##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR" int) 'tag-pointer ptr) )
    tp) )

(define (tagged-pointer? x #!optional tag)
  (and (##core#inline "C_blockp" x)  (##core#inline "C_taggedpointerp" x)
       (or (not tag)
	   (equal? tag (##sys#slot x 1)) ) ) )

(define (pointer-tag x)
  (if (%special-block? x)
      (and (##core#inline "C_taggedpointerp" x)
	   (##sys#slot x 1) )
      (##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR" int) 'pointer-tag x) ) )




;;; SRFI-4 number-vector:

(define (pointer-u8-set! p n) (##core#inline "C_u_i_pointer_u8_set" p n))
(define (pointer-s8-set! p n) (##core#inline "C_u_i_pointer_s8_set" p n))
(define (pointer-u16-set! p n) (##core#inline "C_u_i_pointer_u16_set" p n))
(define (pointer-s16-set! p n) (##core#inline "C_u_i_pointer_s16_set" p n))
(define (pointer-u32-set! p n) (##core#inline "C_u_i_pointer_u32_set" p n))
(define (pointer-s32-set! p n) (##core#inline "C_u_i_pointer_s32_set" p n))
(define (pointer-u64-set! p n) (##core#inline "C_u_i_pointer_u64_set" p n))
(define (pointer-s64-set! p n) (##core#inline "C_u_i_pointer_s64_set" p n))
(define (pointer-f32-set! p n) (##core#inline "C_u_i_pointer_f32_set" p n))
(define (pointer-f64-set! p n) (##core#inline "C_u_i_pointer_f64_set" p n))

(define pointer-u8-ref
  (getter-with-setter
   (lambda (p) (##core#inline "C_u_i_pointer_u8_ref" p))
   pointer-u8-set!
   "(chicken.memory#pointer-u8-ref p)"))

(define pointer-s8-ref
  (getter-with-setter
   (lambda (p) (##core#inline "C_u_i_pointer_s8_ref" p))
   pointer-s8-set!
   "(chicken.memory#pointer-s8-ref p)"))

(define pointer-u16-ref
  (getter-with-setter
   (lambda (p) (##core#inline "C_u_i_pointer_u16_ref" p))
   pointer-u16-set!
   "(chicken.memory#pointer-u16-ref p)"))

(define pointer-s16-ref
  (getter-with-setter
   (lambda (p) (##core#inline "C_u_i_pointer_s16_ref" p))
   pointer-s16-set!
   "(chicken.memory#pointer-s16-ref p)"))

(define pointer-u32-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_u32_ref" 6) p)) ;XXX hardcoded size
   pointer-u32-set!
   "(chicken.memory#pointer-u32-ref p)"))

(define pointer-s32-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_s32_ref" 6) p)) ;XXX hardcoded size
   pointer-s32-set!
   "(chicken.memory#pointer-s32-ref p)"))

(define pointer-u64-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_u64_ref" 7) p)) ;XXX hardcoded size
   pointer-u64-set!
   "(chicken.memory#pointer-u64-ref p)"))

(define pointer-s64-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_s64_ref" 7) p)) ;XXX hardcoded size
   pointer-s64-set!
   "(chicken.memory#pointer-s64-ref p)"))

(define pointer-f32-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_f32_ref" 4) p)) ;XXX hardcoded size
   pointer-f32-set!
   "(chicken.memory#pointer-f32-ref p)"))

(define pointer-f64-ref
  (getter-with-setter
   (lambda (p) (##core#inline_allocate ("C_a_u_i_pointer_f64_ref" 4) p)) ;XXX hardcoded size
   pointer-f64-set!
   "(chicken.memory#pointer-f64-ref p)"))


;;; pointer vectors

(define make-pointer-vector
  (let ((unset (list 'unset)))
    (lambda (n #!optional (init unset))
      (##sys#check-fixnum n 'make-pointer-vector)
      (let* ((words->bytes (foreign-lambda int "C_wordstobytes" int))
	     (size (words->bytes n))
	     (buf (##sys#make-blob size)))
	(unless (eq? init unset)
	  (when init
	    (##sys#check-pointer init 'make-pointer-vector))
	  (do ((i 0 (fx+ i 1)))
	      ((fx>= i n))
	    (pv-buf-set! buf i init)))
	(##sys#make-structure 'pointer-vector n buf)))))

(define (pointer-vector? x)
  (##sys#structure? x 'pointer-vector))

(define (pointer-vector . ptrs)
  (let* ((n (length ptrs))
	 (pv (make-pointer-vector n))
	 (buf (##sys#slot pv 2)))	; buf
    (do ((ptrs ptrs (cdr ptrs))
	 (i 0 (fx+ i 1)))
	((null? ptrs) pv)
      (let ((ptr (car ptrs)))
	(##sys#check-pointer ptr 'pointer-vector)
	(pv-buf-set! buf i ptr)))))

(define (pointer-vector-fill! pv ptr)
  (##sys#check-structure pv 'pointer-vector 'pointer-vector-fill!)
  (when ptr (##sys#check-pointer ptr 'pointer-vector-fill!))
  (let ((buf (##sys#slot pv 2))		; buf
	(n (##sys#slot pv 1)))		; n
    (do ((i 0 (fx+ i 1)))
	((fx>= i n))
      (pv-buf-set! buf i ptr))))

(define pv-buf-ref
  (foreign-lambda* c-pointer ((scheme-object buf) (unsigned-int i))
    "C_return(*((void **)C_data_pointer(buf) + i));"))

(define pv-buf-set!
  (foreign-lambda* void ((scheme-object buf) (unsigned-int i) (c-pointer ptr))
    "*((void **)C_data_pointer(buf) + i) = ptr;"))

(define (pointer-vector-set! pv i ptr)
  (##sys#check-structure pv 'pointer-vector 'pointer-vector-ref)
  (##sys#check-range i 0 (##sys#slot pv 1)) ; len
  (when ptr (##sys#check-pointer ptr 'pointer-vector-set!))
  (pv-buf-set! (##sys#slot pv 2) i ptr))

(define pointer-vector-ref
  (getter-with-setter
   (lambda (pv i)
     (##sys#check-structure pv 'pointer-vector 'pointer-vector-ref)
     (##sys#check-range i 0 (##sys#slot pv 1)) ; len
     (pv-buf-ref (##sys#slot pv 2) i))	; buf
   pointer-vector-set!
   "(chicken.memory#pointer-vector-ref pv i)"))

(define (pointer-vector-length pv)
  (##sys#check-structure pv 'pointer-vector 'pointer-vector-length)
  (##sys#slot pv 1))

) ; chicken.memory


(module chicken.memory.representation
  (block-ref block-set! extend-procedure extended-procedure?
   make-record-instance mutate-procedure! number-of-bytes
   number-of-slots object-become! object-copy procedure-data
   record->vector record-instance-length record-instance-slot
   record-instance-slot-set! record-instance-type record-instance?
   set-procedure-data! vector-like?)

(import scheme chicken.base chicken.fixnum chicken.foreign)


;;; Copy arbitrary object:

(define (object-copy x)
  (let copy ((x x))
    (cond ((not (##core#inline "C_blockp" x)) x)
	  ((symbol? x) (##sys#intern-symbol (##sys#slot x 1)))
	  (else
	   (let* ((n (##sys#size x))
		  (words (if (##core#inline "C_byteblockp" x) (##core#inline "C_words" n) n))
		  (y (##core#inline "C_copy_block" x (##sys#make-vector words))))
	     (unless (##core#inline "C_byteblockp" x)
	       (do ((i (if (##core#inline "C_specialp" x) 1 0) (fx+ i 1)))
		   ((fx>= i n))
		 (##sys#setslot y i (copy (##sys#slot y i)))))
	     y)))))


;;; Procedures extended with data:

; Unique id for extended-procedures
(define xproc-tag (vector 'extended))

(define (extend-procedure proc data)
  (##sys#check-closure proc 'extend-procedure)
  (##sys#decorate-lambda
   proc
   (lambda (x) (and (pair? x) (eq? xproc-tag (##sys#slot x 0)))) 
   (lambda (x i) (##sys#setslot x i (cons xproc-tag data)) x) ) )

(define-inline (%procedure-data proc)
  (##sys#lambda-decoration proc (lambda (x) (and (pair? x) (eq? xproc-tag (##sys#slot x 0))))) )

(define (extended-procedure? x)
  (and (##core#inline "C_blockp" x) (##core#inline "C_closurep" x)
       (%procedure-data x)
       #t) )

(define (procedure-data x)
  (and (##core#inline "C_blockp" x) (##core#inline "C_closurep" x)
       (and-let* ([d (%procedure-data x)])
	 (##sys#slot d 1) ) ) )

(define (set-procedure-data! proc x)
  (unless (eq? proc (extend-procedure proc x))
    (##sys#signal-hook #:type-error 'set-procedure-data!
     "bad argument type - not an extended procedure" proc)))

;;; Accessors for arbitrary vector-like block objects:

(define (vector-like? x) (%generic-vector? x))

(define block-set! ##sys#block-set!)

(define block-ref 
  (getter-with-setter
   ##sys#block-ref ##sys#block-set! "(chicken.memory.representation#block-ref x i)"))

(define (number-of-slots x)
  (##sys#check-generic-vector x 'number-of-slots)
  (##sys#size x) )

(define (number-of-bytes x)
  (cond [(not (##core#inline "C_blockp" x))
	 (##sys#signal-hook
	  #:type-error 'number-of-bytes
	  "cannot compute number of bytes of immediate object" x) ]
	[(##core#inline "C_byteblockp" x)
	 (##sys#size x)]
	[else
	 (##core#inline "C_bytes" (##sys#size x))] ) )


;;; Record objects:

;; Record layout:
;
; 0	Tag (symbol)
; 1..N	Slot (object)

(define (make-record-instance type . args)
  (##sys#check-symbol type 'make-record-instance)
  (apply ##sys#make-structure type args) )

(define (record-instance? x #!optional type)
  (and (%record-structure? x)
       (or (not type)
	   (eq? type (##sys#slot x 0)))) )

(define (record-instance-type x)
  (##sys#check-generic-structure x 'record-instance-type)
  (##sys#slot x 0) )

(define (record-instance-length x)
  (##sys#check-generic-structure x 'record-instance-length)
  (fx- (##sys#size x) 1) )

(define (record-instance-slot-set! x i y)
  (##sys#check-generic-structure x 'record-instance-slot-set!)
  (##sys#check-range i 0 (fx- (##sys#size x) 1) 'record-instance-slot-set!)
  (##sys#setslot x (fx+ i 1) y) )

(define record-instance-slot
  (getter-with-setter
   (lambda (x i)
     (##sys#check-generic-structure x 'record-instance-slot)
     (##sys#check-range i 0 (fx- (##sys#size x) 1) 'record-instance-slot)
     (##sys#slot x (fx+ i 1)) )
   record-instance-slot-set!
   "(chicken.memory.representation#record-instance-slot x i)"))

(define (record->vector x)
  (##sys#check-generic-structure x 'record->vector)
  (let* ([n (##sys#size x)]
	 [v (##sys#make-vector n)] )
    (do ([i 0 (fx+ i 1)])
	 [(fx>= i n) v]
      (##sys#setslot v i (##sys#slot x i)) ) ) )


;;; `become':

(define (object-become! alst)
  (##sys#check-become-alist alst 'object-become!)
  (##sys#become! alst) )

(define (mutate-procedure! old proc)
  (##sys#check-closure old 'mutate-procedure!)
  (##sys#check-closure proc 'mutate-procedure!)
  (let* ([n (##sys#size old)]
	 [words (##core#inline "C_words" n)]
	 [new (##core#inline "C_copy_block" old (##sys#make-vector words))] )
    (##sys#become! (list (cons old (proc new))))
    new ) )

) ; chicken.memory.representation


(module chicken.locative
  (locative? make-locative make-weak-locative
   locative-ref locative-set! locative->object locative-index)

(import scheme chicken.base)

;;; locatives:

;; Locative layout:
;
; 0	Object-address + Byte-offset (address)
; 1	Byte-offset (fixnum)
; 2	Type (fixnum)
;	0	vector or pair		(C_SLOT_LOCATIVE)
;	1	string			(C_CHAR_LOCATIVE)
;	2	u8vector or blob        (C_U8_LOCATIVE)
;	3	s8vector	        (C_S8_LOCATIVE)
;	4	u16vector		(C_U16_LOCATIVE)
;	5	s16vector		(C_S16_LOCATIVE)
;	6	u32vector		(C_U32_LOCATIVE)
;	7	s32vector		(C_S32_LOCATIVE)
;	8	u64vector		(C_U32_LOCATIVE)
;	9	s64vector		(C_S32_LOCATIVE)
;	10	f32vector		(C_F32_LOCATIVE)
;	11	f64vector		(C_F64_LOCATIVE)
; 3	Object or #f, if weak (C_word)

(define (make-locative obj . index)
  (##sys#make-locative obj (optional index 0) #f 'make-locative))

(define (make-weak-locative obj . index)
  (##sys#make-locative obj (optional index 0) #t 'make-weak-locative))

(define (locative-set! x y) (##core#inline "C_i_locative_set" x y))

(define locative-ref
  (getter-with-setter
   (lambda (loc)
     (##core#inline_allocate ("C_a_i_locative_ref" 6) loc))
   locative-set!
   "(chicken.locative#locative-ref loc)"))

(define (locative->object x)
  (##core#inline "C_i_locative_to_object" x))

(define (locative-index x)
  (##core#inline "C_i_locative_index" x))

(define (locative? x)
  (and (##core#inline "C_blockp" x) (##core#inline "C_locativep" x))))
