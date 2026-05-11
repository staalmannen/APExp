;;;; library.scm - R5RS library for the CHICKEN compiler
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
  (unit library)
  (uses build-version)
  (disable-interrupts)
  (hide ##sys#dynamic-unwind
	##sys#vector-resize ##sys#default-parameter-vector 
	current-print-length setter-tag
	##sys#print-exit
	##sys#format-here-doc-warning
	exit-in-progress cleanup-before-exit chicken.base#cleanup-tasks
        maximal-string-length find-ratio-between find-ratio
	make-complex flonum->ratnum ratnum
	+maximum-allowed-exponent+ mantexp->dbl ldexp round-quotient
	##sys#string->compnum ##sys#internal-gcd)
  (not inline chicken.base#sleep-hook ##sys#change-directory-hook
       ##sys#user-read-hook ##sys#error-hook ##sys#signal-hook ##sys#signal-hook/errno
       ##sys#default-read-info-hook ##sys#infix-list-hook
       ##sys#sharp-number-hook ##sys#user-print-hook
       ##sys#user-interrupt-hook ##sys#windows-platform
       ##sys#resume-thread-on-event ##sys#suspend-thread-on-event
       ##sys#schedule ##sys#features)
  (foreign-declare #<<EOF
#include <errno.h>
#include <float.h>

#ifdef HAVE_SYSEXITS_H
# include <sysexits.h>
#endif

#ifndef EX_SOFTWARE
# define EX_SOFTWARE	70
#endif

#define C_close_file(p)	      (C_fclose((C_FILEPTR)(C_port_file(p))), C_SCHEME_UNDEFINED)
#define C_a_f64peek(ptr, c, b, i)  C_flonum(ptr, ((double *)C_data_pointer(b))[ C_unfix(i) ])
#define C_fetch_c_strlen(b, i) C_fix(strlen((C_char *)C_block_item(b, C_unfix(i))))
#define C_asciiz_strlen(str) C_fix(strlen(C_c_string(str)))
#define C_peek_c_string(b, i, to, len) (C_memcpy(C_data_pointer(to), (C_char *)C_block_item(b, C_unfix(i)), C_unfix(len)), C_SCHEME_UNDEFINED)
#define C_free_mptr(p, i)     (C_free((void *)C_block_item(p, C_unfix(i))), C_SCHEME_UNDEFINED)
#define C_free_sptr(p, i)     (C_free((void *)(((C_char **)C_block_item(p, 0))[ C_unfix(i) ])), C_SCHEME_UNDEFINED)

#define C_a_get_current_seconds(ptr, c, dummy)  C_int64_to_num(ptr, time(NULL))
#define C_peek_c_string_at(ptr, i)    ((C_char *)(((C_char **)ptr)[ i ]))

static C_word
fast_read_line_from_file(C_word str, C_word port, C_word size) {
  int n = C_unfix(size);
  int i;
  int c;
  char *buf = C_c_string(str);
  C_FILEPTR fp = C_port_file(port);

  if ((c = C_getc(fp)) == EOF) {
    if (ferror(fp)) {
      clearerr(fp);
      return C_fix(-1);
    } else { /* feof (fp) */
      return C_SCHEME_END_OF_FILE;
    }
  }

  C_ungetc(c, fp);

  for (i = 0; i < n; i++) {
    c = C_getc(fp);

    if(c == EOF && ferror(fp)) {
      clearerr(fp);
      return C_fix(-(i + 1));
    }

    switch (c) {
    case '\r':	if ((c = C_getc(fp)) != '\n') C_ungetc(c, fp);
    case EOF:	clearerr(fp);
    case '\n':	return C_fix(i);
    }
    buf[i] = c;
  }
  return C_SCHEME_FALSE;
}

static C_word
fast_read_string_from_file(C_word dest, C_word port, C_word len, C_word pos)
{
  size_t m;
  int n = C_unfix (len);
  char * buf = ((char *)C_data_pointer (dest) + C_unfix (pos));
  C_FILEPTR fp = C_port_file (port);

  if(feof(fp)) return C_SCHEME_END_OF_FILE;

  m = fread (buf, sizeof (char), n, fp);

  if (m < n) {
    if (ferror(fp)) /* Report to Scheme, which may retry, so clear errors */
      clearerr(fp);
    else if (feof(fp) && 0 == m) /* eof but m > 0? Return data first, below */
      return C_SCHEME_END_OF_FILE; /* Calling again will get us here */
  }

  return C_fix (m);
}

static C_word
shallow_equal(C_word x, C_word y)
{
  /* assumes x and y are non-immediate */
  int i, len = C_header_size(x);

  if(C_header_size(y) != len) return C_SCHEME_FALSE;      
  else return C_mk_bool(!C_memcmp((void *)x, (void *)y, len * sizeof(C_word)));
}

static C_word
signal_debug_event(C_word mode, C_word msg, C_word args)
{
  C_DEBUG_INFO cell;
  C_word av[ 3 ];
  cell.enabled = 1;
  cell.event = C_DEBUG_SIGNAL;
  cell.loc = "";
  cell.val = "";
  av[ 0 ] = mode;
  av[ 1 ] = msg;
  av[ 2 ] = args;
  C_debugger(&cell, 3, av);
  return C_SCHEME_UNDEFINED;
}
                   
static C_word C_i_sleep_until_interrupt(C_word secs)
{
   while(C_i_process_sleep(secs) == C_fix(-1) && errno == EINTR);
   return C_SCHEME_UNDEFINED;
}
                   
#ifdef NO_DLOAD2
# define HAVE_DLOAD 0
#else
# define HAVE_DLOAD 1
#endif

#ifdef C_ENABLE_PTABLES
# define HAVE_PTABLES 1
#else
# define HAVE_PTABLES 0
#endif

#ifdef C_GC_HOOKS
# define HAVE_GCHOOKS 1
#else
# define HAVE_GCHOOKS 0
#endif

#if defined(C_CROSS_CHICKEN) && C_CROSS_CHICKEN
# define IS_CROSS_CHICKEN 1
#else
# define IS_CROSS_CHICKEN 0
#endif
EOF
) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; NOTE: Modules defined here will typically exclude syntax
;; definitions, those are handled by expand.scm or modules.scm.
;; Handwritten import libraries (or a special-case module in
;; modules.scm for scheme) contain the value exports merged with
;; syntactic exports.  The upshot of this is that any module that
;; refers to another module defined *earlier* in this file cannot use
;; macros from the earlier module!
;;
;; We get around this problem by using the "chicken.internal.syntax"
;; module, which is baked in and exports *every* available core macro.
;; See modules.scm, expand.scm and chicken-syntax.scm for details.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Pre-declaration of scheme, so it can be used later on.  We only use
;; scheme macros and core language forms in here, to avoid a cyclic
;; dependency on itself.  All actual definitions are set! below.
;; Also, this declaration is incomplete: the module itself is defined
;; as a primitive module due to syntax exports, which are missing
;; here.  See modules.scm for the full definition.
(module scheme
    (;; [syntax]
     ;; We are reexporting these because otherwise the module here
     ;; will be inconsistent with the built-in one, and be void of
     ;; syntax definitions, causing problems below.
     begin and case cond define define-syntax delay do lambda
     if let let* let-syntax letrec letrec-syntax or
     quasiquote quote set! syntax-rules

     not boolean? eq? eqv? equal? pair?
     cons car cdr caar cadr cdar cddr caaar caadr cadar caddr cdaar
     cdadr cddar cdddr caaaar caaadr caadar caaddr cadaar cadadr
     caddar cadddr cdaaar cdaadr cdadar cdaddr cddaar cddadr cdddar
     cddddr set-car! set-cdr!
     null? list? list length list-tail list-ref append reverse memq memv
     member assq assv assoc symbol? symbol->string string->symbol number?
     integer? exact? real? complex? inexact? rational? zero? odd? even?
     positive? negative?  max min + - * / = > < >= <= quotient remainder
     modulo gcd lcm abs floor ceiling truncate round rationalize
     exact->inexact inexact->exact exp log expt sqrt
     sin cos tan asin acos atan
     number->string string->number char? char=? char>? char<? char>=?
     char<=? char-ci=? char-ci<? char-ci>?  char-ci>=? char-ci<=?
     char-alphabetic? char-whitespace? char-numeric? char-upper-case?
     char-lower-case? char-upcase char-downcase
     char->integer integer->char
     string? string=?  string>? string<? string>=? string<=? string-ci=?
     string-ci<? string-ci>? string-ci>=? string-ci<=?  make-string
     string-length string-ref string-set! string-append string-copy
     string->list list->string substring string-fill! vector? make-vector
     vector-ref vector-set! string vector vector-length vector->list
     list->vector vector-fill! procedure? map for-each apply force
     call-with-current-continuation input-port? output-port?
     current-input-port current-output-port call-with-input-file
     call-with-output-file open-input-file open-output-file
     close-input-port close-output-port
     read read-char peek-char write display write-char newline
     eof-object? with-input-from-file with-output-to-file
     char-ready? imag-part real-part make-rectangular make-polar angle
     magnitude numerator denominator values call-with-values dynamic-wind

     ;; The following procedures are overwritten in eval.scm:
     eval interaction-environment null-environment
     scheme-report-environment load)

(import chicken.internal.syntax) ;; See note above

;;; Operations on booleans:

(define (not x) (##core#inline "C_i_not" x))
(define (boolean? x) (##core#inline "C_booleanp" x))


;;; Equivalence predicates:

(define (eq? x y) (##core#inline "C_eqp" x y))
(define (eqv? x y) (##core#inline "C_i_eqvp" x y))
(define (equal? x y) (##core#inline "C_i_equalp" x y))


;;; Pairs and lists:

(define (pair? x) (##core#inline "C_i_pairp" x))
(define (cons x y) (##core#inline_allocate ("C_a_i_cons" 3) x y))
(define (car x) (##core#inline "C_i_car" x))
(define (cdr x) (##core#inline "C_i_cdr" x))

(define (set-car! x y) (##core#inline "C_i_set_car" x y))
(define (set-cdr! x y) (##core#inline "C_i_set_cdr" x y))
(define (cadr x) (##core#inline "C_i_cadr" x))
(define (caddr x) (##core#inline "C_i_caddr" x))
(define (cadddr x) (##core#inline "C_i_cadddr" x))
(define (cddddr x) (##core#inline "C_i_cddddr" x))

(define (caar x) (##core#inline "C_i_caar" x))
(define (cdar x) (##core#inline "C_i_cdar" x))
(define (cddr x) (##core#inline "C_i_cddr" x))
(define (caaar x) (car (car (car x))))
(define (caadr x) (car (##core#inline "C_i_cadr" x)))
(define (cadar x) (##core#inline "C_i_cadr" (car x)))
(define (cdaar x) (cdr (car (car x))))
(define (cdadr x) (cdr (##core#inline "C_i_cadr" x)))
(define (cddar x) (cdr (cdr (car x))))
(define (cdddr x) (cdr (cdr (cdr x))))
(define (caaaar x) (car (car (car (car x)))))
(define (caaadr x) (car (car (##core#inline "C_i_cadr" x))))
(define (caadar x) (car (##core#inline "C_i_cadr" (car x))))
(define (caaddr x) (car (##core#inline "C_i_caddr" x)))
(define (cadaar x) (##core#inline "C_i_cadr" (car (car x))))
(define (cadadr x) (##core#inline "C_i_cadr" (##core#inline "C_i_cadr" x)))
(define (caddar x) (##core#inline "C_i_caddr" (car x)))
(define (cdaaar x) (cdr (car (car (car x)))))
(define (cdaadr x) (cdr (car (##core#inline "C_i_cadr" x))))
(define (cdadar x) (cdr (##core#inline "C_i_cadr" (car x))))
(define (cdaddr x) (cdr (##core#inline "C_i_caddr" x)))
(define (cddaar x) (cdr (cdr (car (car x)))))
(define (cddadr x) (cdr (cdr (##core#inline "C_i_cadr" x))))
(define (cdddar x) (cdr (cdr (cdr (car x)))))

(define (null? x) (eq? x '()))
(define (list . lst) lst)
(define (length lst) (##core#inline "C_i_length" lst))
(define (list-tail lst i) (##core#inline "C_i_list_tail" lst i))
(define (list-ref lst i) (##core#inline "C_i_list_ref" lst i))

(define append)

(define (reverse lst0)
  (let loop ((lst lst0) (rest '()))
    (cond ((eq? lst '()) rest)
	  ((pair? lst)
	   (loop (##sys#slot lst 1) (cons (##sys#slot lst 0) rest)) )
	  (else (##sys#error-not-a-proper-list lst0 'reverse)) ) ))

(define (memq x lst) (##core#inline "C_i_memq" x lst))
(define (memv x lst) (##core#inline "C_i_memv" x lst))
(define (member x lst) (##core#inline "C_i_member" x lst))
(define (assq x lst) (##core#inline "C_i_assq" x lst))
(define (assv x lst) (##core#inline "C_i_assv" x lst))
(define (assoc x lst) (##core#inline "C_i_assoc" x lst))

(define (list? x) (##core#inline "C_i_listp" x))

;;; Strings:

(define make-string)

(define (string? x) (##core#inline "C_i_stringp" x))
(define (string-length s) (##core#inline "C_i_string_length" s))
(define (string-ref s i) (##core#inline "C_i_string_ref" s i))
(define (string-set! s i c) (##core#inline "C_i_string_set" s i c))

(define (string=? x y)
  (##core#inline "C_i_string_equal_p" x y))

(define (string-ci=? x y) (##core#inline "C_i_string_ci_equal_p" x y))

(define string->list)
(define list->string)
(define string-fill)
(define string-copy)
(define substring)
(define string-fill!)

(define string<?)
(define string>?)
(define string<=?)
(define string>=?)

(define string-ci<?)
(define string-ci>?)
(define string-ci<=?)
(define string-ci>=?)

(define string)
(define string-append)

;; Complex numbers
(define make-rectangular)
(define make-polar)
(define real-part)
(define imag-part)
(define angle)
(define magnitude)

;; Rational numbers
(define numerator)
(define denominator)
(define inexact->exact)
(define (exact->inexact x)
  (##core#inline_allocate ("C_a_i_exact_to_inexact" 12) x))

;; Numerical operations
(define (abs x) (##core#inline_allocate ("C_s_a_i_abs" 7) x))
(define + (##core#primitive "C_plus"))
(define - (##core#primitive "C_minus"))
(define * (##core#primitive "C_times"))
(define /)
(define floor)
(define ceiling)
(define truncate)
(define round)
(define rationalize)

(define (quotient a b) (##core#inline_allocate ("C_s_a_i_quotient" 5) a b))
(define (remainder a b) (##core#inline_allocate ("C_s_a_i_remainder" 5) a b))
(define (modulo a b) (##core#inline_allocate ("C_s_a_i_modulo" 5) a b))

(define (even? n) (##core#inline "C_i_evenp" n))
(define (odd? n) (##core#inline "C_i_oddp" n))

(define max)
(define min)
(define exp)
(define log)
(define sin)
(define cos)
(define tan)
(define asin)
(define acos)
(define atan)

(define sqrt)
(define expt)
(define gcd)
(define lcm)

(define = (##core#primitive "C_nequalp"))
(define > (##core#primitive "C_greaterp"))
(define < (##core#primitive "C_lessp"))
(define >= (##core#primitive "C_greater_or_equal_p"))
(define <= (##core#primitive "C_less_or_equal_p"))
(define (number? x) (##core#inline "C_i_numberp" x))
(define complex? number?)
(define (real? x) (##core#inline "C_i_realp" x))
(define (rational? n) (##core#inline "C_i_rationalp" n))
(define (integer? x) (##core#inline "C_i_integerp" x))
(define (exact? x) (##core#inline "C_i_exactp" x))
(define (inexact? x) (##core#inline "C_i_inexactp" x))
(define (zero? n) (##core#inline "C_i_zerop" n))
(define (positive? n) (##core#inline "C_i_positivep" n))
(define (negative? n) (##core#inline "C_i_negativep" n))

(define number->string (##core#primitive "C_number_to_string"))
(define string->number)

;;; Symbols:

(define (symbol? x) (##core#inline "C_i_symbolp" x))
(define symbol->string)
(define string->symbol)

;;; Vectors:

(define (vector? x) (##core#inline "C_i_vectorp" x))
(define (vector-length v) (##core#inline "C_i_vector_length" v))
(define (vector-ref v i) (##core#inline "C_i_vector_ref" v i))
(define (vector-set! v i x) (##core#inline "C_i_vector_set" v i x))
(define make-vector)
(define list->vector)
(define vector->list)
(define vector)
(define vector-fill!)

;;; Characters:

(define (char? x) (##core#inline "C_charp" x))
(define (char->integer c)
  (##sys#check-char c 'char->integer)
  (##core#inline "C_fix" (##core#inline "C_character_code" c)) )

(define (integer->char n)
  (##sys#check-fixnum n 'integer->char)
  (##core#inline "C_make_character" (##core#inline "C_unfix" n)) )

(define (char=? c1 c2) (##core#inline "C_i_char_equalp" c1 c2))
(define (char>? c1 c2) (##core#inline "C_i_char_greaterp" c1 c2))
(define (char<? c1 c2) (##core#inline "C_i_char_lessp" c1 c2))
(define (char>=? c1 c2) (##core#inline "C_i_char_greater_or_equal_p" c1 c2))
(define (char<=? c1 c2) (##core#inline "C_i_char_less_or_equal_p" c1 c2))

(define (char-upcase c)
  (##sys#check-char c 'char-upcase)
  (##core#inline "C_u_i_char_upcase" c))

(define (char-downcase c)
  (##sys#check-char c 'char-downcase)
  (##core#inline "C_u_i_char_downcase" c))

(define char-ci=?)
(define char-ci>?)
(define char-ci<?)
(define char-ci>=?)
(define char-ci<=?)

(define (char-upper-case? c)
  (##sys#check-char c 'char-upper-case?)
  (##core#inline "C_u_i_char_upper_casep" c) )

(define (char-lower-case? c)
  (##sys#check-char c 'char-lower-case?)
  (##core#inline "C_u_i_char_lower_casep" c) )

(define (char-numeric? c)
  (##sys#check-char c 'char-numeric?)
  (##core#inline "C_u_i_char_numericp" c) )

(define (char-whitespace? c)
  (##sys#check-char c 'char-whitespace?)
  (##core#inline "C_u_i_char_whitespacep" c) )

(define (char-alphabetic? c)
  (##sys#check-char c 'char-alphabetic?)
  (##core#inline "C_u_i_char_alphabeticp" c) )

;;; Procedures:

(define (procedure? x) (##core#inline "C_i_closurep" x))
(define apply (##core#primitive "C_apply"))
(define values (##core#primitive "C_values"))
(define call-with-values (##core#primitive "C_call_with_values"))
(define call-with-current-continuation)

;;; Ports:

(define (input-port? x)
  (and (##core#inline "C_blockp" x)
       (##core#inline "C_input_portp" x)))

(define (output-port? x)
  (and (##core#inline "C_blockp" x)
       (##core#inline "C_output_portp" x)))

(define current-input-port)
(define current-output-port)
(define open-input-file)
(define open-output-file)
(define close-input-port)
(define close-output-port)
(define call-with-input-file)
(define call-with-output-file)
(define with-input-from-file)
(define with-output-to-file)

;;; Input:

(define (eof-object? x) (##core#inline "C_eofp" x))
(define char-ready?)
(define read-char)
(define peek-char)
(define read)

;;; Output:

(define write-char)
(define newline)
(define write)
(define display)

;;; Evaluation environments:

;; All of the stuff below is overwritten with their "real"
;; implementations by chicken.eval (see eval.scm)

(define (eval x . env)
  (##sys#error 'eval "`eval' is not defined - the `eval' unit was probably not linked with this executable"))

(define (interaction-environment)
  (##sys#error 'interaction-environment "`interaction-environment' is not defined - the `eval' unit was probably not linked with this executable"))

(define (scheme-report-environment n)
  (##sys#error 'scheme-report-environment "`scheme-report-environment' is not defined - the `eval' unit was probably not linked with this executable"))

(define (null-environment)
  (##sys#error 'null-environment "`null-environment' is not defined - the `eval' unit was probably not linked with this executable"))

(define (load filename . evaluator)
  (##sys#error 'load "`load' is not defined - the `eval' unit was probably not linked with this executable"))

;; Other stuff:

(define force)
(define for-each)
(define map)
(define dynamic-wind)

) ; scheme

(import scheme)

;; Pre-declaration of chicken.base, so it can be used later on.  Much
;; like the "scheme" module, most declarations will be set! further
;; down in this file, mostly to avoid a cyclic dependency on itself.
;; The full definition (with macros) is in its own import library.
(module chicken.base
  (;; [syntax] and-let* case-lambda cut cute declare define-constant
   ;; define-inline define-record define-record-type
   ;; define-record-printer define-values delay-force fluid-let include
   ;; include-relative let-optionals let-values let*-values letrec*
   ;; letrec-values nth-value optional parameterize rec receive
   ;; require-library require-extension set!-values syntax unless when
   bignum? flonum? fixnum? ratnum? cplxnum? finite? infinite? nan?
   exact-integer? exact-integer-sqrt exact-integer-nth-root

   port? port-closed? input-port-open? output-port-open? flush-output
   get-output-string open-input-string open-output-string
   get-call-chain print print* add1 sub1 sleep call/cc
   current-error-port error void gensym print-call-chain
   make-promise promise? char-name enable-warnings
   equal=? finite? foldl foldr getter-with-setter make-parameter
   notice procedure-information setter signum string->uninterned-symbol
   subvector symbol-append vector-copy! vector-resize
   warning quotient&remainder quotient&modulo
   record-printer set-record-printer!
   alist-ref alist-update alist-update! rassoc atom? butlast chop
   compress flatten intersperse join list-of? tail? constantly
   complement compose conjoin disjoin each flip identity o

   case-sensitive keyword-style parentheses-synonyms symbol-escape

   on-exit exit exit-handler implicit-exit-handler emergency-exit
   bwp-object? weak-cons weak-pair?)

(import scheme chicken.internal.syntax)

(define (fixnum? x) (##core#inline "C_fixnump" x))
(define (flonum? x) (##core#inline "C_i_flonump" x))
(define (bignum? x) (##core#inline "C_i_bignump" x))
(define (ratnum? x) (##core#inline "C_i_ratnump" x))
(define (cplxnum? x) (##core#inline "C_i_cplxnump" x))
(define (exact-integer? x) (##core#inline "C_i_exact_integerp" x))
(define exact-integer-sqrt)
(define exact-integer-nth-root)

(define quotient&remainder (##core#primitive "C_quotient_and_remainder"))
;; Modulo's sign follows y (whereas remainder's sign follows x)
;; Inlining this is not much use: quotient&remainder is primitive
(define (quotient&modulo x y)
  (call-with-values (lambda () (quotient&remainder x y))
    (lambda (div rem)
      (if (positive? y)
	  (if (negative? rem)
	      (values div (+ rem y))
	      (values div rem))
	  (if (positive? rem)
	      (values div (+ rem y))
	      (values div rem))))))


(define (finite? x) (##core#inline "C_i_finitep" x))
(define (infinite? x) (##core#inline "C_i_infinitep" x))
(define (nan? x) (##core#inline "C_i_nanp" x))

(define signum (##core#primitive "C_signum"))

(define equal=?)
(define get-call-chain)
(define print-call-chain)
(define print)
(define print*)
(define (add1 n) (+ n 1))
(define (sub1 n) (- n 1))
(define current-error-port)

(define (error . args)
  (if (pair? args)
      (apply ##sys#signal-hook #:error args)
      (##sys#signal-hook #:error #f)))

(define (void . _) (##core#undefined))

(define sleep)

(define call/cc)
(define char-name)
(define enable-warnings)
; (define enable-notices)???
(define getter-with-setter)
(define make-parameter)
(define procedure-information)
(define setter)
(define string->uninterned-symbol)
(define record-printer)
(define set-record-printer!)

(define gensym)

(define vector-copy!)
(define subvector)
(define vector-resize)

(define symbol-append)
(define warning)
(define notice)

(define port?)
(define port-closed?)
(define input-port-open?)
(define output-port-open?)
(define get-output-string)
(define open-input-string)
(define open-output-string)
(define flush-output)

;;; Promises:

(define (promise? x)
  (##sys#structure? x 'promise))

(define (##sys#make-promise proc)
  (##sys#make-structure 'promise proc))

(define (make-promise obj)
  (if (promise? obj) obj
      (##sys#make-promise (lambda () obj))))

;;; fast folds with correct argument order

(define (foldl f z lst)
  (##sys#check-list lst 'foldl)
  (let loop ((lst lst) (z z))
    (if (not (pair? lst))
	z
	(loop (##sys#slot lst 1) (f z (##sys#slot lst 0))))))

(define (foldr f z lst)
  (##sys#check-list lst 'foldr)
  (let loop ((lst lst))
    (if (not (pair? lst))
	z
	(f (##sys#slot lst 0) (loop (##sys#slot lst 1))))))

;;; Exit:

(define implicit-exit-handler)
(define exit-handler)

(define chicken.base#cleanup-tasks '())

(define (on-exit thunk)
  (set! cleanup-tasks (cons thunk chicken.base#cleanup-tasks)))

(define (exit #!optional (code 0))
  ((exit-handler) code))

(define (emergency-exit #!optional (code 0))
  (##sys#check-fixnum code 'emergency-exit)
  (##core#inline "C_exit_runtime" code))

;;; Parameters:

(define case-sensitive)
(define keyword-style)
(define parentheses-synonyms)
(define symbol-escape)

;;; Combinators:

(define (identity x) x)

(define (conjoin . preds)
  (lambda (x)
    (let loop ((preds preds))
      (or (null? preds)
	  (and ((##sys#slot preds 0) x)
	       (loop (##sys#slot preds 1)) ) ) ) ) )

(define (disjoin . preds)
  (lambda (x)
    (let loop ((preds preds))
      (and (not (null? preds))
	   (or ((##sys#slot preds 0) x)
	       (loop (##sys#slot preds 1)) ) ) ) ) )

(define (constantly . xs)
  (if (eq? 1 (length xs))
      (let ((x (car xs)))
	(lambda _ x) )
      (lambda _ (apply values xs)) ) )

(define (flip proc) (lambda (x y) (proc y x)))

(define complement
  (lambda (p)
    (lambda args (not (apply p args))) ) )

(define (compose . fns)
  (define (rec f0 . fns)
    (if (null? fns)
	f0
	(lambda args
	  (call-with-values
	      (lambda () (apply (apply rec fns) args))
	    f0) ) ) )
  (if (null? fns)
      values
      (apply rec fns) ) )

(define (o . fns)
  (if (null? fns)
      identity
      (let loop ((fns fns))
	(let ((h (##sys#slot fns 0))
	      (t (##sys#slot fns 1)) )
	  (if (null? t)
	      h
	      (lambda (x) (h ((loop t) x))))))))

(define (list-of? pred)
  (lambda (lst)
    (let loop ((lst lst))
      (cond ((null? lst) #t)
	    ((not (pair? lst)) #f)
	    ((pred (##sys#slot lst 0)) (loop (##sys#slot lst 1)))
	    (else #f) ) ) ) )

(define (each . procs)
  (cond ((null? procs) (lambda _ (void)))
	((null? (##sys#slot procs 1)) (##sys#slot procs 0))
	(else
	 (lambda args
	   (let loop ((procs procs))
	     (let ((h (##sys#slot procs 0))
		   (t (##sys#slot procs 1)) )
	       (if (null? t)
		   (apply h args)
		   (begin
		     (apply h args)
		     (loop t) ) ) ) ) ) ) ) )


;;; Weak pairs:
(define (bwp-object? x) (##core#inline "C_bwpp" x))
(define (weak-cons x y) (##core#inline_allocate ("C_a_i_weak_cons" 3) x y))
(define (weak-pair? x) (##core#inline "C_i_weak_pairp" x))

;;; List operators:

(define (atom? x) (##core#inline "C_i_not_pair_p" x))

(define (tail? x y)
  (##sys#check-list y 'tail?)
  (let loop ((y y))
    (cond ((##core#inline "C_eqp" x y) #t)
          ((and (##core#inline "C_blockp" y)
                (##core#inline "C_pairp" y))
           (loop (##sys#slot y 1)))
          (else #f))))

(define intersperse
  (lambda (lst x)
    (let loop ((ns lst))
      (if (##core#inline "C_eqp" ns '())
	  ns
	  (let ((tail (cdr ns)))
	    (if (##core#inline "C_eqp" tail '())
		ns
		(cons (##sys#slot ns 0) (cons x (loop tail))) ) ) ) ) ) )

(define (butlast lst)
  (##sys#check-pair lst 'butlast)
  (let loop ((lst lst))
    (let ((next (##sys#slot lst 1)))
      (if (and (##core#inline "C_blockp" next) (##core#inline "C_pairp" next))
	  (cons (##sys#slot lst 0) (loop next))
	  '() ) ) ) )

(define (flatten . lists0)
  (let loop ((lists lists0) (rest '()))
    (cond ((null? lists) rest)
	  (else
	   (let ((head (##sys#slot lists 0))
		 (tail (##sys#slot lists 1)) )
	     (if (list? head)
		 (loop head (loop tail rest))
		 (cons head (loop tail rest)) ) ) ) ) ) )

(define chop)

(define (join lsts . lst)
  (let ((lst (if (pair? lst) (car lst) '())))
    (##sys#check-list lst 'join)
    (let loop ((lsts lsts))
      (cond ((null? lsts) '())
	    ((not (pair? lsts))
	     (##sys#error-not-a-proper-list lsts) )
	    (else
	     (let ((l (##sys#slot lsts 0))
		   (r (##sys#slot lsts 1)) )
	       (if (null? r)
		   l
		   (##sys#append l lst (loop r)) ) ) ) ) ) ) )

(define compress
  (lambda (blst lst)
    (let ((msg "bad argument type - not a proper list"))
      (##sys#check-list lst 'compress)
      (let loop ((blst blst) (lst lst))
	(cond ((null? blst) '())
	      ((not (pair? blst))
	       (##sys#signal-hook #:type-error 'compress msg blst) )
	      ((not (pair? lst))
	       (##sys#signal-hook #:type-error 'compress msg lst) )
	      ((##sys#slot blst 0)
	       (cons (##sys#slot lst 0) (loop (##sys#slot blst 1) (##sys#slot lst 1))))
	      (else (loop (##sys#slot blst 1) (##sys#slot lst 1))) ) ) ) ) )


;;; Alists:

(define (alist-update! x y lst #!optional (cmp eqv?))
  (let* ((aq (cond ((eq? eq? cmp) assq)
		   ((eq? eqv? cmp) assv)
		   ((eq? equal? cmp) assoc)
		   (else
		    (lambda (x lst)
		      (let loop ((lst lst))
			(and (pair? lst)
			     (let ((a (##sys#slot lst 0)))
			       (if (and (pair? a) (cmp x (##sys#slot a 0)))
				   a
				   (loop (##sys#slot lst 1)) ) ) ) ) ) ) ) )
	 (item (aq x lst)) )
    (if item
	(begin
	  (##sys#setslot item 1 y)
	  lst)
	(cons (cons x y) lst) ) ) )

(define (alist-update k v lst #!optional (cmp eqv?))
  (let loop ((lst lst))
    (cond ((null? lst)
           (list (cons k v)))
          ((not (pair? lst))
           (error 'alist-update "bad argument type" lst))
          (else
           (let ((a (##sys#slot lst 0)))
             (cond ((not (pair? a))
                    (error 'alist-update "bad argument type" a))
                   ((cmp k (##sys#slot a 0))
                    (cons (cons k v) (##sys#slot lst 1)))
                   (else
                    (cons (cons (##sys#slot a 0) (##sys#slot a 1))
                          (loop (##sys#slot lst 1))))))))))

(define (alist-ref x lst #!optional (cmp eqv?) (default #f))
  (let* ((aq (cond ((eq? eq? cmp) assq)
		   ((eq? eqv? cmp) assv)
		   ((eq? equal? cmp) assoc)
		   (else
		    (lambda (x lst)
		      (let loop ((lst lst))
			(cond
			 ((null? lst) #f)
			 ((pair? lst)
			  (let ((a (##sys#slot lst 0)))
			    (##sys#check-pair a 'alist-ref)
			    (if (cmp x (##sys#slot a 0))
				a
				(loop (##sys#slot lst 1)) ) ))
			 (else (error 'alist-ref "bad argument type" lst)) )  ) ) ) ) )
	 (item (aq x lst)) )
    (if item
	(##sys#slot item 1)
	default) ) )

;; TODO: Make inlineable in C without "tst", to be more like assoc?
(define (rassoc x lst . tst)
  (##sys#check-list lst 'rassoc)
  (let ((tst (if (pair? tst) (car tst) eqv?)))
    (let loop ((l lst))
      (and (pair? l)
	   (let ((a (##sys#slot l 0)))
	     (##sys#check-pair a 'rassoc)
	     (if (tst x (##sys#slot a 1))
		 a
		 (loop (##sys#slot l 1)) ) ) ) ) ) )

) ; chicken.base

(import chicken.base)

(define-constant char-name-table-size 37)
(define-constant output-string-initial-size 256)
(define-constant read-line-buffer-initial-size 1024)
(define-constant default-parameter-vector-size 16)
(define maximal-string-length (foreign-value "C_HEADER_SIZE_MASK" unsigned-long))

;;; Fixnum arithmetic:

(module chicken.fixnum *
(import scheme)
(import chicken.foreign)

(define most-positive-fixnum (foreign-value "C_MOST_POSITIVE_FIXNUM" int))
(define most-negative-fixnum (foreign-value "C_MOST_NEGATIVE_FIXNUM" int))
(define fixnum-bits (foreign-value "(C_WORD_SIZE - 1)" int))
(define fixnum-precision (foreign-value "(C_WORD_SIZE - (1 + 1))" int))

(define (fx+ x y) (##core#inline "C_fixnum_plus" x y))
(define (fx- x y) (##core#inline "C_fixnum_difference" x y))
(define (fx* x y) (##core#inline "C_fixnum_times" x y))
(define (fx= x y) (eq? x y))
(define (fx> x y) (##core#inline "C_fixnum_greaterp" x y))
(define (fx< x y) (##core#inline "C_fixnum_lessp" x y))
(define (fx>= x y) (##core#inline "C_fixnum_greater_or_equal_p" x y))
(define (fx<= x y) (##core#inline "C_fixnum_less_or_equal_p" x y))
(define (fxmin x y) (##core#inline "C_i_fixnum_min" x y))
(define (fxmax x y) (##core#inline "C_i_fixnum_max" x y))
(define (fxneg x) (##core#inline "C_fixnum_negate" x))
(define (fxand x y) (##core#inline "C_fixnum_and" x y))
(define (fxior x y) (##core#inline "C_fixnum_or" x y))
(define (fxxor x y) (##core#inline "C_fixnum_xor" x y))
(define (fxnot x) (##core#inline "C_fixnum_not" x))
(define (fxshl x y) (##core#inline "C_fixnum_shift_left" x y))
(define (fxshr x y) (##core#inline "C_fixnum_shift_right" x y))
(define (fxodd? x) (##core#inline "C_i_fixnumoddp" x))
(define (fxeven? x) (##core#inline "C_i_fixnumevenp" x))
(define (fxlen x) (##core#inline "C_i_fixnum_length" x))
(define (fx/ x y) (##core#inline "C_fixnum_divide" x y) )
(define (fxgcd x y) (##core#inline "C_i_fixnum_gcd" x y))
(define (fxmod x y) (##core#inline "C_fixnum_modulo" x y) )
(define (fxrem x y) (##core#inline "C_i_fixnum_remainder_checked" x y) )

;; Overflow-detecting versions of some of the above
(define (fx+? x y) (##core#inline "C_i_o_fixnum_plus" x y) )
(define (fx-? x y) (##core#inline "C_i_o_fixnum_difference" x y) )
(define (fx*? x y) (##core#inline "C_i_o_fixnum_times" x y) )
(define (fx/? x y) (##core#inline "C_i_o_fixnum_quotient" x y))

) ; chicken.fixnum

(import chicken.fixnum)


;;; System routines:

(define (##sys#debug-mode?) (##core#inline "C_i_debug_modep"))

(define ##sys#warnings-enabled #t)
(define ##sys#notices-enabled (##sys#debug-mode?))

(set! chicken.base#warning
  (lambda (msg . args)
    (when ##sys#warnings-enabled
      (apply ##sys#signal-hook #:warning msg args))))

(set! chicken.base#notice
  (lambda (msg . args)
    (when (and ##sys#notices-enabled
	       ##sys#warnings-enabled)
      (apply ##sys#signal-hook #:notice msg args))))

(set! chicken.base#enable-warnings
  (lambda bool
    (if (pair? bool)
	(set! ##sys#warnings-enabled (car bool))
	##sys#warnings-enabled)))

(define ##sys#error error)
(define ##sys#warn warning)
(define ##sys#notice notice)

(define (##sys#error/errno err . args)
  (if (pair? args)
      (apply ##sys#signal-hook/errno #:error err #f args)
      (##sys#signal-hook/errno #:error err #f)))

(define-foreign-variable strerror c-string "strerror(errno)")

(define ##sys#gc (##core#primitive "C_gc"))
(define (##sys#setslot x i y) (##core#inline "C_i_setslot" x i y))
(define (##sys#setislot x i y) (##core#inline "C_i_set_i_slot" x i y))
(define ##sys#allocate-vector (##core#primitive "C_allocate_vector"))
(define ##sys#make-structure (##core#primitive "C_make_structure"))
(define ##sys#ensure-heap-reserve (##core#primitive "C_ensure_heap_reserve"))
(define ##sys#symbol-table-info (##core#primitive "C_get_symbol_table_info"))
(define ##sys#memory-info (##core#primitive "C_get_memory_info"))

(define (##sys#start-timer)
  (##sys#gc #t)
  (##core#inline "C_start_timer"))

(define (##sys#stop-timer)
  (let ((info ((##core#primitive "C_stop_timer"))))
    ;; Run a major GC one more time to get memory usage information in
    ;; case there was no major GC while the timer was running
    (##sys#gc #t)
    (##sys#setslot info 6 (##sys#slot ((##core#primitive "C_stop_timer")) 6))
    info))

(define (##sys#immediate? x) (not (##core#inline "C_blockp" x)))
(define (##sys#message str) (##core#inline "C_message" str))
(define (##sys#byte x i) (##core#inline "C_subbyte" x i))
(define (##sys#setbyte x i n) (##core#inline "C_setbyte" x i n))
(define ##sys#void void)
(define ##sys#undefined-value (##core#undefined))
(define (##sys#halt msg) (##core#inline "C_halt" msg))
(define ##sys#become! (##core#primitive "C_become"))
(define (##sys#block-ref x i) (##core#inline "C_i_block_ref" x i))
(define ##sys#apply-values (##core#primitive "C_apply_values"))
(define ##sys#copy-closure (##core#primitive "C_copy_closure"))

(define (##sys#block-set! x i y)
  (when (or (not (##core#inline "C_blockp" x)) 
	    (and (##core#inline "C_specialp" x) (fx= i 0))
	    (##core#inline "C_byteblockp" x) ) 
    (##sys#signal-hook '#:type-error '##sys#block-set! "slot not accessible" x) )
  (##sys#check-range i 0 (##sys#size x) '##sys#block-set!)
  (##sys#setslot x i y) )

(module chicken.time
    ;; NOTE: We don't emit the import lib.  Due to syntax exports, it has
    ;; to be a hardcoded primitive module.
    ;;
    ;; [syntax] time
    (cpu-time 
     current-milliseconds ; DEPRECATED
     current-process-milliseconds current-seconds)

(import scheme)
(import (only chicken.module reexport))

;; Deprecated
(define (current-milliseconds)
  (##core#inline_allocate ("C_a_i_current_milliseconds" 7) #f))

(define (current-process-milliseconds)
  (##core#inline_allocate ("C_a_i_current_process_milliseconds" 7) #f))

(define (current-seconds) 
  (##core#inline_allocate ("C_a_get_current_seconds" 7) #f))

(define cpu-time
  (let () ;; ((buf (vector #f #f))) Disabled for now: vector is defined below!
    (lambda ()
      (let ((buf (vector #f #f)))
	;; should be thread-safe as no context-switch will occur after
	;; function entry and `buf' contents will have been extracted
	;; before `values' gets called.
	(##core#inline_allocate ("C_a_i_cpu_time" 8) buf)
	(values (##sys#slot buf 0) (##sys#slot buf 1)) )) ))

) ; chicken.time

(define (##sys#check-structure x y . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_structure_2" x y (car loc))
      (##core#inline "C_i_check_structure" x y) ) )

(define (##sys#check-blob x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_bytevector_2" x (car loc))
      (##core#inline "C_i_check_bytevector" x) ) )

(define ##sys#check-byte-vector ##sys#check-blob)

(define (##sys#check-pair x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_pair_2" x (car loc))
      (##core#inline "C_i_check_pair" x) ) )

(define (##sys#check-list x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_list_2" x (car loc))
      (##core#inline "C_i_check_list" x) ) )

(define (##sys#check-string x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_string_2" x (car loc))
      (##core#inline "C_i_check_string" x) ) )

(define (##sys#check-number x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_number_2" x (car loc))
      (##core#inline "C_i_check_number" x) ) )

(define (##sys#check-fixnum x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_fixnum_2" x (car loc))
      (##core#inline "C_i_check_fixnum" x) ) )

(define (##sys#check-exact x . loc) ;; DEPRECATED
  (if (pair? loc)
      (##core#inline "C_i_check_exact_2" x (car loc))
      (##core#inline "C_i_check_exact" x) ) )

(define (##sys#check-inexact x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_inexact_2" x (car loc))
      (##core#inline "C_i_check_inexact" x) ) )

(define (##sys#check-symbol x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_symbol_2" x (car loc))
      (##core#inline "C_i_check_symbol" x) ) )

(define (##sys#check-keyword x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_keyword_2" x (car loc))
      (##core#inline "C_i_check_keyword" x) ) )

(define (##sys#check-vector x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_vector_2" x (car loc))
      (##core#inline "C_i_check_vector" x) ) )

(define (##sys#check-char x . loc) 
  (if (pair? loc)
      (##core#inline "C_i_check_char_2" x (car loc))
      (##core#inline "C_i_check_char" x) ) )

(define (##sys#check-boolean x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_boolean_2" x (car loc))
      (##core#inline "C_i_check_boolean" x) ) )

(define (##sys#check-locative x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_locative_2" x (car loc))
      (##core#inline "C_i_check_locative" x) ) )

(define (##sys#check-integer x . loc)
  (unless (##core#inline "C_i_integerp" x)
    (##sys#error-bad-integer x (and (pair? loc) (car loc))) ) )

(define (##sys#check-exact-integer x . loc)
  (unless (##core#inline "C_i_exact_integerp" x)
    (##sys#error-bad-exact-integer x (and (pair? loc) (car loc))) ) )

(define (##sys#check-exact-uinteger x . loc)
  (when (or (not (##core#inline "C_i_exact_integerp" x))
	    (##core#inline "C_i_integer_negativep" x))
    (##sys#error-bad-exact-uinteger x (and (pair? loc) (car loc))) ) )

(define (##sys#check-real x . loc)
  (unless (##core#inline "C_i_realp" x)
    (##sys#error-bad-real x (and (pair? loc) (car loc))) ) )

(define (##sys#check-range i from to . loc)
  (##sys#check-fixnum i loc)
  (unless (and (fx<= from i) (fx< i to))
    (##sys#error-hook
     (foreign-value "C_OUT_OF_RANGE_ERROR" int)
     (and (pair? loc) (car loc)) i from to) ) )

(define (##sys#check-special ptr . loc)
  (unless (and (##core#inline "C_blockp" ptr) (##core#inline "C_specialp" ptr))
    (##sys#signal-hook #:type-error (and (pair? loc) (car loc)) "bad argument type - not a pointer-like object" ptr) ) )

(define (##sys#check-closure x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_closure_2" x (car loc))
      (##core#inline "C_i_check_closure" x) ) )

(set! scheme#force
  (lambda (obj)
    (if (##sys#structure? obj 'promise)
	(let lp ((promise obj)
		 (forward #f))
	  (let ((val (##sys#slot promise 1)))
	    (cond ((null? val) (##sys#values))
		  ((pair? val) (apply ##sys#values val))
		  ((procedure? val)
		   (when forward (##sys#setslot forward 1 promise))
		   (let ((results (##sys#call-with-values val ##sys#list)))
		     (cond ((not (procedure? (##sys#slot promise 1)))
			    (lp promise forward)) ; in case of reentrance
			   ((and (not (null? results)) (null? (cdr results))
				 (##sys#structure? (##sys#slot results 0) 'promise))
			    (let ((result0 (##sys#slot results 0)))
			      (##sys#setslot promise 1 (##sys#slot result0 1))
			      (lp promise result0)))
			   (else
			    (##sys#setslot promise 1 results)
			    (apply ##sys#values results)))))
		  ((##sys#structure? val 'promise)
		   (lp val forward)))))
	obj)))


;;; Dynamic Load

(define ##sys#dload (##core#primitive "C_dload"))
(define ##sys#set-dlopen-flags! (##core#primitive "C_set_dlopen_flags"))

(define (##sys#error-not-a-proper-list arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_NOT_A_PROPER_LIST_ERROR" int) loc arg))

(define (##sys#error-bad-number arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR" int) loc arg))

(define (##sys#error-bad-integer arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR" int) loc arg))

(define (##sys#error-bad-exact-integer arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR" int) loc arg))

(define (##sys#error-bad-exact-uinteger arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR" int) loc arg))

(define (##sys#error-bad-inexact arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_CANT_REPRESENT_INEXACT_ERROR" int) loc arg))

(define (##sys#error-bad-real arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_NO_REAL_ERROR" int) loc arg))

(define (##sys#error-bad-base arg #!optional loc)
  (##sys#error-hook
   (foreign-value "C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR" int) loc arg))

(set! scheme#append
  (lambda lsts
    (if (eq? lsts '())
	lsts
	(let loop ((lsts lsts))
	  (if (eq? (##sys#slot lsts 1) '())
	      (##sys#slot lsts 0)
	      (let copy ((node (##sys#slot lsts 0)))
		(cond ((eq? node '()) (loop (##sys#slot lsts 1)))
		      ((pair? node)
		       (cons (##sys#slot node 0) (copy (##sys#slot node 1))) )
		      (else
		       (##sys#error-not-a-proper-list
			(##sys#slot lsts 0) 'append)) ) )))) ) )

(define (##sys#fast-reverse lst0)
  (let loop ((lst lst0) (rest '()))
    (if (pair? lst)
	(loop (##sys#slot lst 1) (cons (##sys#slot lst 0) rest))
	rest)))


;;; Strings:

(define-inline (%make-string size fill)
  (##sys#allocate-vector size #t fill #f) )

(define (##sys#make-string size #!optional (fill #\space))
  (%make-string size fill))

(set! scheme#make-string
  (lambda (size . fill)
    (##sys#check-fixnum size 'make-string)
    (when (fx< size 0)
      (##sys#signal-hook #:bounds-error 'make-string "size is negative" size))
    (%make-string
     size
     (if (null? fill)
	 #\space
	 (let ((c (car fill)))
	   (##sys#check-char c 'make-string)
	   c ) ) ) ) )

(set! scheme#string->list
  (lambda (s)
    (##sys#check-string s 'string->list)
    (let ((len (##sys#size s)))
      (let loop ((i (fx- len 1)) (ls '()))
	(if (fx< i 0)
	    ls
	    (loop (fx- i 1)
		  (cons (##core#inline "C_subchar" s i) ls)) ) ) )))

(define ##sys#string->list string->list)

(set! scheme#list->string
  (lambda (lst0)
    (if (not (list? lst0))
	(##sys#error-not-a-proper-list lst0 'list->string)
	(let* ([len (length lst0)]
	       [s (##sys#make-string len)] )
	  (do ([i 0 (fx+ i 1)]
	       [lst lst0 (##sys#slot lst 1)] )
	      ((fx>= i len) s)
	    (let ([c (##sys#slot lst 0)])
	      (##sys#check-char c 'list->string)
	      (##core#inline "C_setsubchar" s i c) ) ) ) )))

(define ##sys#list->string list->string)

;;; By Sven Hartrumpf:

(define (##sys#reverse-list->string l)
  (if (list? l)
      (let* ((n (length l))
	     (s (##sys#make-string n)))
	(let iter ((l2 l) (n2 (fx- n 1)))
	  (cond ((fx>= n2 0)
		 (let ((c (##sys#slot l2 0)))
		   (##sys#check-char c 'reverse-list->string)
		   (##core#inline "C_setsubchar" s n2 c) )
		 (iter (##sys#slot l2 1) (fx- n2 1)) ) ) )
	s )
      (##sys#error-not-a-proper-list l 'reverse-list->string) ) )

(set! scheme#string-fill!
  (lambda (s c)
    (##sys#check-string s 'string-fill!)
    (##sys#check-char c 'string-fill!)
    (##core#inline "C_set_memory" s c (##sys#size s))
    (##core#undefined) ))

(set! scheme#string-copy
  (lambda (s)
    (##sys#check-string s 'string-copy)
    (let* ([len (##sys#size s)]
	   [s2 (##sys#make-string len)] )
      (##core#inline "C_copy_memory" s2 s len)
      s2) ) )

(set! scheme#substring
  (lambda (s start . end)
    (##sys#check-string s 'substring)
    (##sys#check-fixnum start 'substring)
    (let ((end (if (pair? end)
		   (let ((end (car end)))
		     (##sys#check-fixnum end 'substring)
		     end)
		   (##sys#size s) ) ) )
      (let ((len (##sys#size s)))
	(if (and (fx<= start end)
		 (fx>= start 0)
		 (fx<= end len) )
	    (##sys#substring s start end)
	    (##sys#error-hook
	     (foreign-value "C_OUT_OF_RANGE_ERROR" int)
	     'substring start end) ) ) )))

(define (##sys#substring s start end)
  (let ([s2 (##sys#make-string (fx- end start))])
    (##core#inline "C_substring_copy" s s2 start end 0)
    s2 ) )

(letrec ((compare
	  (lambda (s1 s2 loc k)
	    (##sys#check-string s1 loc)
	    (##sys#check-string s2 loc)
	    (let ((len1 (##core#inline "C_block_size" s1))
		  (len2 (##core#inline "C_block_size" s2)) )
	      (k len1 len2
		 (##core#inline "C_string_compare"
			    s1
			    s2
			    (if (fx< len1 len2)
				len1
				len2) ) ) ) ) ) )
  (set! scheme#string<? (lambda (s1 s2)
			  (compare
			   s1 s2 'string<?
			   (lambda (len1 len2 cmp)
			     (or (fx< cmp 0)
				 (and (fx< len1 len2)
				      (eq? cmp 0) ) ) ) ) ) )
  (set! scheme#string>? (lambda (s1 s2)
			  (compare
			   s1 s2 'string>?
			   (lambda (len1 len2 cmp)
			     (or (fx> cmp 0)
				 (and (fx< len2 len1)
				      (eq? cmp 0) ) ) ) ) ) )
  (set! scheme#string<=? (lambda (s1 s2)
			   (compare
			    s1 s2 'string<=?
			    (lambda (len1 len2 cmp)
			      (if (eq? cmp 0)
				  (fx<= len1 len2)
				  (fx< cmp 0) ) ) ) ) )
  (set! scheme#string>=? (lambda (s1 s2)
			   (compare
			    s1 s2 'string>=?
			    (lambda (len1 len2 cmp)
			      (if (eq? cmp 0)
				  (fx>= len1 len2)
				  (fx> cmp 0) ) ) ) ) ) )

(letrec ((compare
	  (lambda (s1 s2 loc k)
	    (##sys#check-string s1 loc)
	    (##sys#check-string s2 loc)
	    (let ((len1 (##core#inline "C_block_size" s1))
		  (len2 (##core#inline "C_block_size" s2)) )
	      (k len1 len2
		 (##core#inline "C_string_compare_case_insensitive"
				s1
				s2
				(if (fx< len1 len2)
				    len1
				    len2) ) ) ) ) ) )
  (set! scheme#string-ci<? (lambda (s1 s2)
			     (compare
			      s1 s2 'string-ci<?
			      (lambda (len1 len2 cmp)
				(or (fx< cmp 0)
				    (and (fx< len1 len2)
					 (eq? cmp 0) ) ) ) ) ) )
  (set! scheme#string-ci>? (lambda (s1 s2)
			     (compare
			      s1 s2 'string-ci>?
			      (lambda (len1 len2 cmp)
				(or (fx> cmp 0)
				    (and (fx< len2 len1)
					 (eq? cmp 0) ) ) ) ) ) )
  (set! scheme#string-ci<=? (lambda (s1 s2)
			      (compare
			       s1 s2 'string-ci<=?
			       (lambda (len1 len2 cmp)
				 (if (eq? cmp 0)
				     (fx<= len1 len2)
				     (fx< cmp 0) ) ) ) ) )
  (set! scheme#string-ci>=? (lambda (s1 s2)
			      (compare
			       s1 s2 'string-ci>=?
			       (lambda (len1 len2 cmp)
				 (if (eq? cmp 0)
				     (fx>= len1 len2)
				     (fx> cmp 0) ) ) ) ) ) )

(define (##sys#string-append x y)
  (let* ([s1 (##sys#size x)]
	 [s2 (##sys#size y)] 
	 [z (##sys#make-string (fx+ s1 s2))] )
    (##core#inline "C_substring_copy" x z 0 s1 0)
    (##core#inline "C_substring_copy" y z 0 s2 s1)
    z) )

(set! scheme#string-append
  (lambda all
    (let ([snew #f])
      (let loop ([strs all] [n 0])
	(if (eq? strs '())
	    (set! snew (##sys#make-string n))
	    (let ([s (##sys#slot strs 0)])
	      (##sys#check-string s 'string-append)
	      (let ([len (##sys#size s)])
		(loop (##sys#slot strs 1) (fx+ n len))
		(##core#inline "C_substring_copy" s snew 0 len n) ) ) ) )
      snew ) ))

(set! scheme#string
  (let ([list->string list->string])
    (lambda chars (list->string chars)) ) )

(define (##sys#fragments->string total fs)
  (let ([dest (##sys#make-string total)])
    (let loop ([fs fs] [pos 0])
      (if (null? fs)
	  dest
	  (let* ([f (##sys#slot fs 0)]
		 [flen (##sys#size f)] )
	    (##core#inline "C_substring_copy" f dest 0 flen pos)
	    (loop (##sys#slot fs 1) (fx+ pos flen)) ) ) ) ) )

(set! chicken.base#chop
  (lambda (lst n)
    (##sys#check-fixnum n 'chop)
    (when (fx<= n 0) (##sys#error 'chop "invalid numeric argument" n))
    (let ((len (length lst)))
      (let loop ((lst lst) (i len))
	(cond ((null? lst) '())
	      ((fx< i n) (list lst))
	      (else
	       (do ((hd '() (cons (##sys#slot tl 0) hd))
		    (tl lst (##sys#slot tl 1))
		    (c n (fx- c 1)) )
		   ((fx= c 0)
		    (cons (reverse hd) (loop tl (fx- i n))) ) ) ) ) ) ) ) )

;;; Numeric routines:
;; Abbreviations of paper and book titles used in comments are:
;; [Knuth] Donald E. Knuth, "The Art of Computer Programming", Volume 2
;; [MpNT]  Tiplea at al., "MpNT: A Multi-Precision Number Theory Package"
;; [MCA]   Richard P. Brent & Paul Zimmermann, "Modern Computer Arithmetic"

(module chicken.flonum *
(import scheme)
(import chicken.foreign)
(import (only chicken.base flonum?))
(import chicken.internal.syntax)

(define maximum-flonum (foreign-value "DBL_MAX" double))
(define minimum-flonum (foreign-value "DBL_MIN" double))
(define flonum-radix (foreign-value "FLT_RADIX" int))
(define flonum-epsilon (foreign-value "DBL_EPSILON" double))
(define flonum-precision (foreign-value "DBL_MANT_DIG" int))
(define flonum-decimal-precision (foreign-value "DBL_DIG" int))
(define flonum-maximum-exponent (foreign-value "DBL_MAX_EXP" int))
(define flonum-minimum-exponent (foreign-value "DBL_MIN_EXP" int))
(define flonum-maximum-decimal-exponent (foreign-value "DBL_MAX_10_EXP" int))
(define flonum-minimum-decimal-exponent (foreign-value "DBL_MIN_10_EXP" int))

(define-inline (fp-check-flonum x loc)
  (unless (flonum? x)
    (##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR" int) loc x) ) )

(define-inline (fp-check-flonums x y loc)
  (unless (and (flonum? x) (flonum? y))
    (##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR" int) loc x y) ) )

(define (fp+ x y) 
  (fp-check-flonums x y 'fp+)
  (##core#inline_allocate ("C_a_i_flonum_plus" 4) x y) )

(define (fp- x y) 
  (fp-check-flonums x y 'fp-)
  (##core#inline_allocate ("C_a_i_flonum_difference" 4) x y) )

(define (fp* x y) 
  (fp-check-flonums x y 'fp*)
  (##core#inline_allocate ("C_a_i_flonum_times" 4) x y) )

(define (fp/ x y)
  (fp-check-flonums x y 'fp/)
  (##core#inline_allocate ("C_a_i_flonum_quotient" 4) x y) )

(define (fp*+ x y z)
  (unless (and (flonum? x) (flonum? y) (flonum? z))
    (##sys#error-hook (foreign-value "C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR" int)
      'fp*+ x y z) )
  (##core#inline_allocate ("C_a_i_flonum_multiply_add" 4) x y z) )

(define (fpgcd x y)
  (fp-check-flonums x y 'fpgcd)
  (##core#inline_allocate ("C_a_i_flonum_gcd" 4) x y))

(define (fp/? x y)			; undocumented
  (fp-check-flonums x y 'fp/?)
  (##core#inline_allocate ("C_a_i_flonum_quotient_checked" 4) x y) )

(define (fp= x y) 
  (fp-check-flonums x y 'fp=)
  (##core#inline "C_flonum_equalp" x y) )

(define (fp> x y) 
  (fp-check-flonums x y 'fp>)
  (##core#inline "C_flonum_greaterp" x y) )

(define (fp< x y) 
  (fp-check-flonums x y 'fp<)
  (##core#inline "C_flonum_lessp" x y) )

(define (fp>= x y) 
  (fp-check-flonums x y 'fp>=)
  (##core#inline "C_flonum_greater_or_equal_p" x y) )

(define (fp<= x y) 
  (fp-check-flonums x y 'fp<=)
  (##core#inline "C_flonum_less_or_equal_p" x y) )

(define (fpneg x) 
  (fp-check-flonum x 'fpneg)
  (##core#inline_allocate ("C_a_i_flonum_negate" 4) x) )

(define (fpmax x y) 
  (fp-check-flonums x y 'fpmax)
  (##core#inline "C_i_flonum_max" x y) )

(define (fpmin x y) 
  (fp-check-flonums x y 'fpmin)
  (##core#inline "C_i_flonum_min" x y) )

(define (fpfloor x)
  (fp-check-flonum x 'fpfloor)
  (##core#inline_allocate ("C_a_i_flonum_floor" 4) x))

(define (fptruncate x)
  (fp-check-flonum x 'fptruncate)
  (##core#inline_allocate ("C_a_i_flonum_truncate" 4) x))

(define (fpround x)
  (fp-check-flonum x 'fpround)
  (##core#inline_allocate ("C_a_i_flonum_round" 4) x))

(define (fpceiling x)
  (fp-check-flonum x 'fpceiling)
  (##core#inline_allocate ("C_a_i_flonum_ceiling" 4) x))

(define (fpsin x)
  (fp-check-flonum x 'fpsin)
  (##core#inline_allocate ("C_a_i_flonum_sin" 4) x))

(define (fpcos x)
  (fp-check-flonum x 'fpcos)
  (##core#inline_allocate ("C_a_i_flonum_cos" 4) x))

(define (fptan x)
  (fp-check-flonum x 'fptan)
  (##core#inline_allocate ("C_a_i_flonum_tan" 4) x))

(define (fpasin x)
  (fp-check-flonum x 'fpasin)
  (##core#inline_allocate ("C_a_i_flonum_asin" 4) x))

(define (fpacos x)
  (fp-check-flonum x 'fpacos)
  (##core#inline_allocate ("C_a_i_flonum_acos" 4) x))

(define (fpatan x)
  (fp-check-flonum x 'fpatan)
  (##core#inline_allocate ("C_a_i_flonum_atan" 4) x))

(define (fpatan2 x y)
  (fp-check-flonums x y 'fpatan2)
  (##core#inline_allocate ("C_a_i_flonum_atan2" 4) x y))

(define (fpsinh x)
  (fp-check-flonum x 'fpsinh)
  (##core#inline_allocate ("C_a_i_flonum_sinh" 4) x))

(define (fpcosh x)
  (fp-check-flonum x 'fpcosh)
  (##core#inline_allocate ("C_a_i_flonum_cosh" 4) x))

(define (fptanh x)
  (fp-check-flonum x 'fptanh)
  (##core#inline_allocate ("C_a_i_flonum_tanh" 4) x))

(define (fpasinh x)
  (fp-check-flonum x 'fpasinh)
  (##core#inline_allocate ("C_a_i_flonum_asinh" 4) x))

(define (fpacosh x)
  (fp-check-flonum x 'fpacosh)
  (##core#inline_allocate ("C_a_i_flonum_acosh" 4) x))

(define (fpatanh x)
  (fp-check-flonum x 'fpatanh)
  (##core#inline_allocate ("C_a_i_flonum_atanh" 4) x))

(define (fpexp x)
  (fp-check-flonum x 'fpexp)
  (##core#inline_allocate ("C_a_i_flonum_exp" 4) x))

(define (fpexpt x y)
  (fp-check-flonums x y 'fpexpt)
  (##core#inline_allocate ("C_a_i_flonum_expt" 4) x y))

(define (fplog x)
  (fp-check-flonum x 'fplog)
  (##core#inline_allocate ("C_a_i_flonum_log" 4) x))

(define (fpsqrt x)
  (fp-check-flonum x 'fpsqrt)
  (##core#inline_allocate ("C_a_i_flonum_sqrt" 4) x))

(define (fpabs x)
  (fp-check-flonum x 'fpabs)
  (##core#inline_allocate ("C_a_i_flonum_abs" 4) x))

(define (fpinteger? x)
  (fp-check-flonum x 'fpinteger?)
  (##core#inline "C_u_i_fpintegerp" x))

(define (flonum-print-precision #!optional prec)
  (let ((prev (##core#inline "C_get_print_precision")))
    (when prec
      (##sys#check-fixnum prec 'flonum-print-precision)
      (##core#inline "C_set_print_precision" prec))
    prev)))

(import chicken.flonum)

(define-inline (integer-negate x)
  (##core#inline_allocate ("C_s_a_u_i_integer_negate" 5) x))

(define ##sys#number? number?)
(define ##sys#integer? integer?)
(define ##sys#exact? exact?)
(define ##sys#inexact? inexact?)

;;; Complex numbers

(define-inline (%cplxnum-real c) (##core#inline "C_u_i_cplxnum_real" c))
(define-inline (%cplxnum-imag c) (##core#inline "C_u_i_cplxnum_imag" c))

(define (make-complex r i)
  (if (or (eq? i 0) (and (##core#inline "C_i_flonump" i) (fp= i 0.0)))
      r
      (##core#inline_allocate ("C_a_i_cplxnum" 3)
			      (if (inexact? i) (exact->inexact r) r)
			      (if (inexact? r) (exact->inexact i) i)) ) )

(set! scheme#make-rectangular
  (lambda (r i)
    (##sys#check-real r 'make-rectangular)
    (##sys#check-real i 'make-rectangular)
    (make-complex r i) ))

(set! scheme#make-polar
  (lambda (r phi)
    (##sys#check-real r 'make-polar)
    (##sys#check-real phi 'make-polar)
    (let ((fphi (exact->inexact phi)))
      (make-complex
       (* r (##core#inline_allocate ("C_a_i_cos" 4) fphi))
       (* r (##core#inline_allocate ("C_a_i_sin" 4) fphi))) ) ))

(set! scheme#real-part
  (lambda (x)
    (cond ((cplxnum? x) (%cplxnum-real x))
	  ((number? x) x)
	  (else (##sys#error-bad-number x 'real-part)) )))

(set! scheme#imag-part
  (lambda (x)
    (cond ((cplxnum? x) (%cplxnum-imag x))
	  ((##core#inline "C_i_flonump" x) 0.0)
	  ((number? x) 0)
	  (else (##sys#error-bad-number x 'imag-part)) )))

(set! scheme#angle
  (lambda (n)
    (##sys#check-number n 'angle)
    (##core#inline_allocate ("C_a_i_atan2" 4)
			    (exact->inexact (imag-part n))
			    (exact->inexact (real-part n))) ))

(set! scheme#magnitude
  (lambda (x)
    (cond ((cplxnum? x)
	   (let ((r (%cplxnum-real x))
		 (i (%cplxnum-imag x)) )
	     (sqrt (+ (* r r) (* i i))) ))
	  ((number? x) (abs x))
	  (else (##sys#error-bad-number x 'magnitude))) ))

;;; Rational numbers

(define-inline (%ratnum-numerator r) (##core#inline "C_u_i_ratnum_num" r))
(define-inline (%ratnum-denominator r) (##core#inline "C_u_i_ratnum_denom" r))
(define-inline (%make-ratnum n d) (##core#inline_allocate ("C_a_i_ratnum" 3) n d))

(define (ratnum m n)
  (cond
   ((eq? n 1) m)
   ((eq? n -1) (integer-negate m))
   ((negative? n)
    (%make-ratnum (integer-negate m) (integer-negate n)))
   (else (%make-ratnum m n))))

(set! scheme#numerator
  (lambda (n)
    (cond ((exact-integer? n) n)
	  ((##core#inline "C_i_flonump" n)
	   (cond ((not (finite? n)) (##sys#error-bad-inexact n 'numerator))
		 ((##core#inline "C_u_i_fpintegerp" n) n)
		 (else (exact->inexact (numerator (inexact->exact n))))))
	  ((ratnum? n) (%ratnum-numerator n))
	  (else (##sys#signal-hook
		 #:type-error 'numerator
		 "bad argument type - not a rational number" n) ) )))

(set! scheme#denominator
  (lambda (n)
    (cond ((exact-integer? n) 1)
	  ((##core#inline "C_i_flonump" n)
	   (cond ((not (finite? n)) (##sys#error-bad-inexact n 'denominator))
		 ((##core#inline "C_u_i_fpintegerp" n) 1.0)
		 (else (exact->inexact (denominator (inexact->exact n))))))
	  ((ratnum? n) (%ratnum-denominator n))
	  (else (##sys#signal-hook
		 #:type-error 'numerator
		 "bad argument type - not a rational number" n) ) )))

(define (##sys#extended-signum x)
  (cond
   ((ratnum? x) (##core#inline "C_u_i_integer_signum" (%ratnum-numerator x)))
   ((cplxnum? x) (make-polar 1 (angle x)))
   (else (##sys#error-bad-number x 'signum))))

(define-inline (%flo->int x)
  (##core#inline_allocate ("C_s_a_u_i_flo_to_int" 5) x))

(define (flonum->ratnum x)
  ;; Try to multiply by two until we reach an integer
  (define (float-fraction-length x)
    (do ((x x (fp* x 2.0))
         (i 0 (fx+ i 1)))
        ((##core#inline "C_u_i_fpintegerp" x) i)))

  (define (deliver y d)
    (let* ((q (##sys#integer-power 2 (float-fraction-length y)))
           (scaled-y (* y (exact->inexact q))))
      (if (finite? scaled-y)          ; Shouldn't this always be true?
          (##sys#/-2 (##sys#/-2 (%flo->int scaled-y) q) d)
          (##sys#error-bad-inexact x 'inexact->exact))))

  (if (and (fp< x 1.0)         ; Watch out for denormalized numbers
           (fp> x -1.0))       ; XXX: Needs a test, it seems pointless
      (deliver (* x (expt 2.0 flonum-precision))
               ;; Can be bignum (is on 32-bit), so must wait until after init.
               ;; We shouldn't need to calculate this every single time, tho..
               (##sys#integer-power 2 flonum-precision))
      (deliver x 1)))

(set! scheme#inexact->exact
  (lambda (x)
    (cond ((exact? x) x)
	  ((##core#inline "C_i_flonump" x)
	   (cond ((##core#inline "C_u_i_fpintegerp" x) (%flo->int x))
		 ((##core#inline "C_u_i_flonum_finitep" x) (flonum->ratnum x))
		 (else (##sys#error-bad-inexact x 'inexact->exact))))
	  ((cplxnum? x)
	   (make-complex (inexact->exact (%cplxnum-real x))
			 (inexact->exact (%cplxnum-imag x))))
	  (else (##sys#error-bad-number x 'inexact->exact)) )))

(define ##sys#exact->inexact exact->inexact)
(define ##sys#inexact->exact inexact->exact)


;;; Bitwise operations:

;; From SRFI-33

(module chicken.bitwise *
(import scheme)
(define bitwise-and (##core#primitive "C_bitwise_and"))
(define bitwise-ior (##core#primitive "C_bitwise_ior"))
(define bitwise-xor (##core#primitive "C_bitwise_xor"))
(define (bitwise-not n) (##core#inline_allocate ("C_s_a_i_bitwise_not" 5) n))
(define (bit->boolean n i) (##core#inline "C_i_bit_to_bool" n i)) ; DEPRECATED
;; XXX NOT YET! Reintroduce at a later time.  See #1385:
;; (define (bit-set? i n) (##core#inline "C_i_bit_setp" i n))
(define (integer-length x) (##core#inline "C_i_integer_length" x))
(define (arithmetic-shift n m)
  (##core#inline_allocate ("C_s_a_i_arithmetic_shift" 5) n m))

) ; chicken.bitwise

(import chicken.bitwise)

;;; Basic arithmetic:

(define-inline (%integer-gcd a b)
  (##core#inline_allocate ("C_s_a_u_i_integer_gcd" 5) a b))

(set! scheme#/
  (lambda (arg1 . args)
    (if (null? args)
	(##sys#/-2 1 arg1)
	(let loop ((args (##sys#slot args 1))
		   (x (##sys#/-2 arg1 (##sys#slot args 0))))
	  (if (null? args)
	      x
	      (loop (##sys#slot args 1)
		    (##sys#/-2 x (##sys#slot args 0))) ) ) ) ))

(define-inline (%integer-quotient a b)
  (##core#inline_allocate ("C_s_a_u_i_integer_quotient" 5) a b))

(define (##sys#/-2 x y)
  (when (eq? y 0)
    (##sys#error-hook (foreign-value "C_DIVISION_BY_ZERO_ERROR" int) '/ x y))
  (cond ((and (exact-integer? x) (exact-integer? y))
         (let ((g (%integer-gcd x y)))
           (ratnum (%integer-quotient x g) (%integer-quotient y g))))
        ;; Compnum *must* be checked first
        ((or (cplxnum? x) (cplxnum? y))
         (let* ((a (real-part x)) (b (imag-part x))
                (c (real-part y)) (d (imag-part y))
                (r (+ (* c c) (* d d)))
                (x (##sys#/-2 (+ (* a c) (* b d)) r))
                (y (##sys#/-2 (- (* b c) (* a d)) r)) )
           (make-complex x y) ))
        ((or (##core#inline "C_i_flonump" x) (##core#inline "C_i_flonump" y))
         ;; This may be incorrect when one is a ratnum consisting of bignums
         (fp/ (exact->inexact x) (exact->inexact y)))
        ((ratnum? x)
         (if (ratnum? y)
             ;; a/b / c/d = a*d / b*c  [generic]
             ;;   = ((a / g1) * (d / g2) * sign(a)) / abs((b / g2) * (c / g1))
             ;; With   g1 = gcd(a, c)   and    g2 = gcd(b, d) [Knuth, 4.5.1 ex. 4]
             (let* ((a (%ratnum-numerator x)) (b (%ratnum-denominator x))
                    (c (%ratnum-numerator y)) (d (%ratnum-denominator y))
                    (g1 (%integer-gcd a c))
                    (g2 (%integer-gcd b d)))
               (ratnum (* (quotient a g1) (quotient d g2))
                       (* (quotient b g2) (quotient c g1))))
             ;; a/b / c/d = a*d / b*c  [with d = 1]
             ;;   = ((a / g) * sign(a)) / abs(b * (c / g))
             ;; With   g = gcd(a, c)   and  c = y  [Knuth, 4.5.1 ex. 4]
             (let* ((a (%ratnum-numerator x))
                    (g (##sys#internal-gcd '/ a y))
                    (num (quotient a g))
                    (denom (* (%ratnum-denominator x) (quotient y g))))
               (if (##core#inline "C_i_flonump" denom)
                   (##sys#/-2 num denom)
                   (ratnum num denom)))))
        ((ratnum? y)
         ;; a/b / c/d = a*d / b*c  [with b = 1]
         ;;   = ((a / g1) * d * sign(a)) / abs(c / g1)
         ;; With   g1 = gcd(a, c)   and   a = x  [Knuth, 4.5.1 ex. 4]
         (let* ((c (%ratnum-numerator y))
                (g (##sys#internal-gcd '/ x c))
                (num (* (quotient x g) (%ratnum-denominator y)))
                (denom (quotient c g)))
           (if (##core#inline "C_i_flonump" denom)
               (##sys#/-2 num denom)
               (ratnum num denom))))
        ((not (number? x)) (##sys#error-bad-number x '/))
        (else (##sys#error-bad-number y '/))) )

(set! scheme#floor
  (lambda (x)
    (cond ((exact-integer? x) x)
	  ((##core#inline "C_i_flonump" x) (fpfloor x))
	  ;; (floor x) = greatest integer <= x
	  ((ratnum? x) (let* ((n (%ratnum-numerator x))
			      (q (quotient n (%ratnum-denominator x))))
			 (if (>= n 0) q (- q 1))))
	  (else (##sys#error-bad-real x 'floor)) )))

(set! scheme#ceiling
  (lambda (x)
    (cond ((exact-integer? x) x)
	  ((##core#inline "C_i_flonump" x) (fpceiling x))
	  ;; (ceiling x) = smallest integer >= x
	  ((ratnum? x) (let* ((n (%ratnum-numerator x))
			      (q (quotient n (%ratnum-denominator x))))
			 (if (>= n 0) (+ q 1) q)))
	  (else (##sys#error-bad-real x 'ceiling)) )))

(set! scheme#truncate
  (lambda (x)
    (cond ((exact-integer? x) x)
	  ((##core#inline "C_i_flonump" x) (fptruncate x))
	  ;; (rational-truncate x) = integer of largest magnitude <= (abs x)
	  ((ratnum? x) (quotient (%ratnum-numerator x)
				 (%ratnum-denominator x)))
	  (else (##sys#error-bad-real x 'truncate)) )))

(set! scheme#round
  (lambda (x)
    (cond ((exact-integer? x) x)
	  ((##core#inline "C_i_flonump" x)
	   (##core#inline_allocate ("C_a_i_flonum_round_proper" 4) x))
	  ((ratnum? x)
	   (let* ((x+1/2 (+ x (%make-ratnum 1 2)))
		  (r (floor x+1/2)))
	     (if (and (= r x+1/2) (odd? r)) (- r 1) r)))
	  (else (##sys#error-bad-real x 'round)) )))

(define (find-ratio-between x y)
  (define (sr x y)
    (let ((fx (inexact->exact (floor x))) 
	  (fy (inexact->exact (floor y))))
      (cond ((not (< fx x)) (list fx 1))
	    ((= fx fy) 
	     (let ((rat (sr (##sys#/-2 1 (- y fy))
			    (##sys#/-2 1 (- x fx)))))
	       (list (+ (cadr rat) (* fx (car rat)))
		     (car rat))))
	    (else (list (+ 1 fx) 1)))))
  (cond ((< y x) (find-ratio-between y x))
	((not (< x y)) (list x 1))
	((positive? x) (sr x y))
	((negative? y) (let ((rat (sr (- y) (- x))))
                         (list (- (car rat)) (cadr rat))))
	(else '(0 1))))

(define (find-ratio x e) (find-ratio-between (- x e) (+ x e)))

(set! scheme#rationalize
  (lambda (x e)
    (let ((result (apply ##sys#/-2 (find-ratio x e))))
      (if (or (inexact? x) (inexact? e))
	  (exact->inexact result)
	  result)) ))

(set! scheme#max
  (lambda (x1 . xs)
    (let loop ((i (##core#inline "C_i_flonump" x1)) (m x1) (xs xs))
      (##sys#check-number m 'max)
      (if (null? xs)
	  (if i (exact->inexact m) m)
	  (let ((h (##sys#slot xs 0)))
	    (loop (or i (##core#inline "C_i_flonump" h))
		  (if (> h m) h m)
		  (##sys#slot xs 1)) ) ) ) ))

(set! scheme#min
  (lambda (x1 . xs)
    (let loop ((i (##core#inline "C_i_flonump" x1)) (m x1) (xs xs))
      (##sys#check-number m 'min)
      (if (null? xs)
	  (if i (exact->inexact m) m)
	  (let ((h (##sys#slot xs 0)))
	    (loop (or i (##core#inline "C_i_flonump" h))
		  (if (< h m) h m)
		  (##sys#slot xs 1)) ) ) ) ))

(set! scheme#exp
  (lambda (n)
    (##sys#check-number n 'exp)
    (if (cplxnum? n)
	(* (##core#inline_allocate ("C_a_i_exp" 4)
				   (exact->inexact (%cplxnum-real n)))
	   (let ((p (%cplxnum-imag n)))
	     (make-complex
	      (##core#inline_allocate ("C_a_i_cos" 4) (exact->inexact p))
	      (##core#inline_allocate ("C_a_i_sin" 4) (exact->inexact p)) ) ) )
	(##core#inline_allocate ("C_a_i_flonum_exp" 4) (exact->inexact n)) ) ))

(define (##sys#log-1 x)		       ; log_e(x)
  (cond
   ((eq? x 0)			       ; Exact zero?  That's undefined
    (##sys#signal-hook #:arithmetic-error 'log "log of exact 0 is undefined" x))
   ;; avoid calling inexact->exact on X here (to avoid overflow?)
   ((or (cplxnum? x) (negative? x)) ; General case
    (+ (##sys#log-1 (magnitude x))
       (* (make-complex 0 1) (angle x))))
   (else ; Real number case (< already ensured the argument type is a number)
    (##core#inline_allocate ("C_a_i_log" 4) (exact->inexact x)))))

(set! scheme#log
  (lambda (a #!optional b)
    (if b (##sys#/-2 (##sys#log-1 a) (##sys#log-1 b)) (##sys#log-1 a))))

(set! scheme#sin
  (lambda (n)
    (##sys#check-number n 'sin)
    (if (cplxnum? n)
	(let ((in (* +i n)))
	  (##sys#/-2 (- (exp in) (exp (- in))) +2i))
	(##core#inline_allocate ("C_a_i_sin" 4) (exact->inexact n)) ) ))

(set! scheme#cos
  (lambda (n)
    (##sys#check-number n 'cos)
    (if (cplxnum? n)
	(let ((in (* +i n)))
	  (##sys#/-2 (+ (exp in) (exp (- in))) 2) )
	(##core#inline_allocate ("C_a_i_cos" 4) (exact->inexact n)) ) ))

(set! scheme#tan
  (lambda (n)
    (##sys#check-number n 'tan)
    (if (cplxnum? n)
	(##sys#/-2 (sin n) (cos n))
	(##core#inline_allocate ("C_a_i_tan" 4) (exact->inexact n)) ) ))

;; General case: sin^{-1}(z) = -i\ln(iz + \sqrt{1-z^2})
(set! scheme#asin
  (lambda (n)
    (##sys#check-number n 'asin)
    (cond ((and (##core#inline "C_i_flonump" n) (fp>= n -1.0) (fp<= n 1.0))
	   (##core#inline_allocate ("C_a_i_asin" 4) n))
	  ((and (##core#inline "C_fixnump" n) (fx>= n -1) (fx<= n 1))
	   (##core#inline_allocate ("C_a_i_asin" 4)
				   (##core#inline_allocate
				    ("C_a_i_fix_to_flo" 4) n)))
	  ;; General definition can return compnums
	  (else (* -i (##sys#log-1
		       (+ (* +i n)
			  (##sys#sqrt/loc 'asin (- 1 (* n n))))) )) ) ))

;; General case:
;; cos^{-1}(z) = 1/2\pi + i\ln(iz + \sqrt{1-z^2}) = 1/2\pi - sin^{-1}(z) = sin(1) - sin(z)
(set! scheme#acos
  (let ((asin1 (##core#inline_allocate ("C_a_i_asin" 4) 1)))
    (lambda (n)
      (##sys#check-number n 'acos)
      (cond ((and (##core#inline "C_i_flonump" n) (fp>= n -1.0) (fp<= n 1.0))
             (##core#inline_allocate ("C_a_i_acos" 4) n))
            ((and (##core#inline "C_fixnump" n) (fx>= n -1) (fx<= n 1))
             (##core#inline_allocate ("C_a_i_acos" 4)
                                     (##core#inline_allocate
                                      ("C_a_i_fix_to_flo" 4) n)))
            ;; General definition can return compnums
            (else (- asin1 (asin n)))))))

(set! scheme#atan
  (lambda (n #!optional b)
    (##sys#check-number n 'atan)
    (cond ((cplxnum? n)
	   (if b
	       (##sys#error-bad-real n 'atan)
	       (let ((in (* +i n)))
		 (##sys#/-2 (- (##sys#log-1 (+ 1 in))
			       (##sys#log-1 (- 1 in))) +2i))))
	  (b
	   (##core#inline_allocate
	    ("C_a_i_atan2" 4) (exact->inexact n) (exact->inexact b)))
	  (else
	   (##core#inline_allocate
	    ("C_a_i_atan" 4) (exact->inexact n))) ) ))

;; This is "Karatsuba Square Root" as described by Paul Zimmermann,
;; which is 3/2K(n) + O(n log n) for an input of 2n words, where K(n)
;; is the number of operations performed by Karatsuba multiplication.
(define (##sys#exact-integer-sqrt a)
  ;; Because we assume a3b+a2 >= b^2/4, we must check a few edge cases:
  (if (and (fixnum? a) (fx<= a 4))
      (case a
        ((0 1) (values a 0))
        ((2)   (values 1 1))
        ((3)   (values 1 2))
        ((4)   (values 2 0))
        (else  (error "this should never happen")))
      (let*-values
          (((len/4) (fxshr (fx+ (integer-length a) 1) 2))
           ((len/2) (fxshl len/4 1))
           ((s^ r^) (##sys#exact-integer-sqrt
		     (arithmetic-shift a (fxneg len/2))))
           ((mask)  (- (arithmetic-shift 1 len/4) 1))
           ((a0)    (bitwise-and a mask))
           ((a1)    (bitwise-and (arithmetic-shift a (fxneg len/4)) mask))
           ((q u)   ((##core#primitive "C_u_integer_quotient_and_remainder")
		     (+ (arithmetic-shift r^ len/4) a1)
		     (arithmetic-shift s^ 1)))
           ((s)     (+ (arithmetic-shift s^ len/4) q))
           ((r)     (+ (arithmetic-shift u len/4) (- a0 (* q q)))))
        (if (negative? r)
            (values (- s 1)
		    (- (+ r (arithmetic-shift s 1)) 1))
            (values s r)))))

(set! chicken.base#exact-integer-sqrt
  (lambda (x)
    (##sys#check-exact-uinteger x 'exact-integer-sqrt)
    (##sys#exact-integer-sqrt x)))

;; This procedure is so large because it tries very hard to compute
;; exact results if at all possible.
(define (##sys#sqrt/loc loc n)
  (cond ((cplxnum? n)     ; Must be checked before we call "negative?"
         (let ((p (##sys#/-2 (angle n) 2))
               (m (##core#inline_allocate ("C_a_i_sqrt" 4) (magnitude n))) )
           (make-complex (* m (cos p)) (* m (sin p)) ) ))
        ((negative? n)
         (make-complex .0 (##core#inline_allocate
			   ("C_a_i_sqrt" 4) (exact->inexact (- n)))))
        ((exact-integer? n)
         (receive (s^2 r) (##sys#exact-integer-sqrt n)
           (if (eq? 0 r)
               s^2
               (##core#inline_allocate ("C_a_i_sqrt" 4) (exact->inexact n)))))
        ((ratnum? n) ; Try to compute exact sqrt (we already know n is positive)
         (receive (ns^2 nr) (##sys#exact-integer-sqrt (%ratnum-numerator n))
           (if (eq? nr 0)
               (receive (ds^2 dr)
		   (##sys#exact-integer-sqrt (%ratnum-denominator n))
                 (if (eq? dr 0)
                     (##sys#/-2 ns^2 ds^2)
                     (##sys#sqrt/loc loc (exact->inexact n))))
               (##sys#sqrt/loc loc (exact->inexact n)))))
        (else (##core#inline_allocate ("C_a_i_sqrt" 4) (exact->inexact n)))))

(set! scheme#sqrt (lambda (x) (##sys#sqrt/loc 'sqrt x)))

(set! chicken.base#exact-integer-nth-root
  (lambda (k n)
    (##sys#check-exact-uinteger k 'exact-integer-nth-root)
    (##sys#check-exact-uinteger n 'exact-integer-nth-root)
    (##sys#exact-integer-nth-root/loc 'exact-integer-nth-root k n)))

;; Generalized Newton's algorithm for positive integers, with a little help
;; from Wikipedia ;)  https://en.wikipedia.org/wiki/Nth_root_algorithm
(define (##sys#exact-integer-nth-root/loc loc k n)
  (if (or (eq? 0 k) (eq? 1 k) (eq? 1 n)) ; Maybe call exact-integer-sqrt on n=2?
      (values k 0)
      (let ((len (integer-length k)))
	(if (< len n)	  ; Idea from Gambit: 2^{len-1} <= k < 2^{len}
	    (values 1 (- k 1)) ; Since x >= 2, we know x^{n} can't exist
	    ;; Set initial guess to (at least) 2^ceil(ceil(log2(k))/n)
	    (let* ((shift-amount (inexact->exact (ceiling (/ (fx+ len 1) n))))
		   (g0 (arithmetic-shift 1 shift-amount))
		   (n-1 (- n 1)))
	      (let lp ((g0 g0)
		       (g1 (quotient
			    (+ (* n-1 g0)
			       (quotient k (##sys#integer-power g0 n-1)))
			    n)))
		(if (< g1 g0)
		    (lp g1 (quotient
			    (+ (* n-1 g1)
			       (quotient k (##sys#integer-power g1 n-1)))
			    n))
		    (values g0 (- k (##sys#integer-power g0 n))))))))))

(define (##sys#integer-power base e)
  (define (square x) (* x x))
  (if (negative? e)
      (##sys#/-2 1 (##sys#integer-power base (integer-negate e)))
      (let lp ((res 1) (e2 e))
        (cond
         ((eq? e2 0) res)
         ((even? e2)	     ; recursion is faster than iteration here
          (* res (square (lp 1 (arithmetic-shift e2 -1)))))
         (else
          (lp (* res base) (- e2 1)))))))

(set! scheme#expt
  (lambda (a b)
    (define (log-expt a b)
      (exp (* b (##sys#log-1 a))))
    (define (slow-expt a b)
      (if (eq? 0 a)
	  (##sys#signal-hook
	   #:arithmetic-error 'expt
	   "exponent of exact 0 with complex argument is undefined" a b)
	  (exp (* b (##sys#log-1 a)))))
    (cond ((not (number? a)) (##sys#error-bad-number a 'expt))
	  ((not (number? b)) (##sys#error-bad-number b 'expt))
	  ((and (ratnum? a) (not (inexact? b)))
	   ;; (n*d)^b = n^b * d^b = n^b * x^{-b}  | x = 1/b
	   ;; Hopefully faster than integer-power
	   (* (expt (%ratnum-numerator a) b)
	      (expt (%ratnum-denominator a) (- b))))
	  ((ratnum? b)
	   ;; x^{a/b} = (x^{1/b})^a
	   (cond
	    ((exact-integer? a)
	     (if (negative? a)
		 (log-expt (exact->inexact a) (exact->inexact b))
		 (receive (ds^n r)
		     (##sys#exact-integer-nth-root/loc
		      'expt a (%ratnum-denominator b))
		   (if (eq? r 0)
		       (##sys#integer-power ds^n (%ratnum-numerator b))
		       (##core#inline_allocate ("C_a_i_flonum_expt" 4)
					       (exact->inexact a)
					       (exact->inexact b))))))
	    ((##core#inline "C_i_flonump" a)
	     (log-expt a (exact->inexact b)))
	    (else (slow-expt a b))))
	  ((or (cplxnum? b) (and (cplxnum? a) (not (integer? b))))
	   (slow-expt a b))
	  ((and (##core#inline "C_i_flonump" b)
		(not (##core#inline "C_u_i_fpintegerp" b)))
	   (if (negative? a)
	       (log-expt (exact->inexact a) (exact->inexact b))
	       (##core#inline_allocate
		("C_a_i_flonum_expt" 4) (exact->inexact a) b)))
	  ((##core#inline "C_i_flonump" a)
	   (##core#inline_allocate ("C_a_i_flonum_expt" 4) a (exact->inexact b)))
	  ;; this doesn't work that well, yet...
	  ;; (XXX: What does this mean? why not? I do know this is ugly... :P)
	  (else (if (or (inexact? a) (inexact? b))
		    (exact->inexact (##sys#integer-power a (inexact->exact b)))
		    (##sys#integer-power a b)))) ))

;; Useful for sane error messages
(define (##sys#internal-gcd loc a b)
  (cond ((exact-integer? a)
         (cond ((exact-integer? b) (%integer-gcd a b))
               ((and (##core#inline "C_i_flonump" b)
                     (##core#inline "C_u_i_fpintegerp" b))
                (exact->inexact (%integer-gcd a (inexact->exact b))))
               (else (##sys#error-bad-integer b loc))))
        ((and (##core#inline "C_i_flonump" a)
              (##core#inline "C_u_i_fpintegerp" a))
         (cond ((##core#inline "C_i_flonump" b)
                (##core#inline_allocate ("C_a_i_flonum_gcd" 4) a b))
               ((exact-integer? b)
                (exact->inexact (%integer-gcd (inexact->exact a) b)))
               (else (##sys#error-bad-integer b loc))))
        (else (##sys#error-bad-integer a loc))))
;; For compat reasons, we define this
(define (##sys#gcd a b) (##sys#internal-gcd 'gcd a b))

(set! scheme#gcd
  (lambda ns
    (if (eq? ns '())
	0
	(let loop ((head (##sys#slot ns 0))
		   (next (##sys#slot ns 1)))
	  (if (null? next)
	      (if (integer? head) (abs head) (##sys#error-bad-integer head 'gcd))
	      (let ((n2 (##sys#slot next 0)))
		(loop (##sys#internal-gcd 'gcd head n2)
		      (##sys#slot next 1)) ) ) ) ) ))

(define (##sys#lcm x y)
  (let ((gcd (##sys#internal-gcd 'lcm x y))) ; Ensure better error message
    (abs (quotient (* x y) gcd) ) ) )

(set! scheme#lcm
  (lambda ns
    (if (null? ns)
	1
	(let loop ((head (##sys#slot ns 0))
		   (next (##sys#slot ns 1)))
	  (if (null? next)
	      (if (integer? head) (abs head) (##sys#error-bad-integer head 'lcm))
	      (let* ((n2 (##sys#slot next 0))
		     (gcd (##sys#internal-gcd 'lcm head n2)))
		(loop (quotient (* head n2) gcd)
		      (##sys#slot next 1)) ) ) ) ) ))

;; This simple enough idea is from
;; http://www.numberworld.org/y-cruncher/internals/radix-conversion.html
(define (##sys#integer->string/recursive n base expected-string-size)
  (let*-values (((halfsize) (fxshr (fx+ expected-string-size 1) 1))
                ((b^M/2) (##sys#integer-power base halfsize))
                ((hi lo) ((##core#primitive "C_u_integer_quotient_and_remainder")
			  n b^M/2))
                ((strhi) (number->string hi base))
                ((strlo) (number->string (abs lo) base)))
    (string-append strhi
                   ;; Fix up any leading zeroes that were stripped from strlo
                   (make-string (fx- halfsize (string-length strlo)) #\0)
                   strlo)))

(define ##sys#extended-number->string
  (let ((string-append string-append))
    (lambda (n base)
      (cond
       ((ratnum? n)
	(string-append (number->string (%ratnum-numerator n) base)
		       "/"
		       (number->string (%ratnum-denominator n) base)))
       ;; What about bases that include an "i"?  That could lead to
       ;; ambiguous results.
       ((cplxnum? n) (let ((r (%cplxnum-real n))
                           (i (%cplxnum-imag n)) )
                       (string-append
                        (number->string r base)
                        ;; The infinities and NaN always print their sign
                        (if (and (finite? i) (positive? i)) "+" "")
                        (number->string i base) "i") ))
       (else (##sys#error-bad-number n 'number->string)))  ) ) )

(define ##sys#number->string number->string) ; for printer

;; We try to prevent memory exhaustion attacks by limiting the
;; maximum exponent value.  Perhaps this should be a parameter?
(define-constant +maximum-allowed-exponent+ 10000)

;; From "Easy Accurate Reading and Writing of Floating-Point Numbers"
;; by Aubrey Jaffer.
(define (mantexp->dbl mant point)
  (if (not (negative? point))
      (exact->inexact (* mant (##sys#integer-power 10 point)))
      (let* ((scl (##sys#integer-power 10 (abs point)))
	     (bex (fx- (fx- (integer-length mant)
			    (integer-length scl))
                       flonum-precision)))
        (if (fx< bex 0)
            (let* ((num (arithmetic-shift mant (fxneg bex)))
                   (quo (round-quotient num scl)))
              (cond ((> (integer-length quo) flonum-precision)
                     ;; Too many bits of quotient; readjust
                     (set! bex (fx+ 1 bex))
                     (set! quo (round-quotient num (* scl 2)))))
              (ldexp (exact->inexact quo) bex))
            ;; Fall back to exact calculation in extreme cases
            (* mant (##sys#integer-power 10 point))))))

(define ldexp (foreign-lambda double "ldexp" double int))

;; Should we export this?
(define (round-quotient n d)
  (let ((q (%integer-quotient n d)))
    (if ((if (even? q) > >=) (* (abs (remainder n d)) 2) (abs d))
        (+ q (if (eqv? (negative? n) (negative? d)) 1 -1))
        q)))

;; Shorthand for readability.  TODO: Replace other C_subchar calls with this
(define-inline (%subchar s i) (##core#inline "C_subchar" s i))
(define (##sys#string->compnum radix str offset exactness)
  ;; Flipped when a sign is encountered (for inexact numbers only)
  (define negative #f)
  ;; Go inexact unless exact was requested (with #e prefix)
  (define (go-inexact! neg?)
    (unless (eq? exactness 'e)
      (set! exactness 'i)
      (set! negative (or negative neg?))))
  (define (safe-exponent value e)
    (and e (cond
            ((not value) 0)
            ((> e +maximum-allowed-exponent+)
             (and (eq? exactness 'i)
                  (cond ((zero? value) 0.0)
                        ((> value 0.0) +inf.0)
                        (else -inf.0))))
            ((< e (fxneg +maximum-allowed-exponent+))
             (and (eq? exactness 'i) +0.0))
            ((eq? exactness 'i) (mantexp->dbl value e))
            (else (* value (##sys#integer-power 10 e))))))
  (define (make-nan)
    ;; Return fresh NaNs, so eqv? returns #f on two read NaNs.  This
    ;; is not mandated by the standard, but compatible with earlier
    ;; CHICKENs and it just makes more sense.
    (##core#inline_allocate ("C_a_i_flonum_quotient" 4) 0.0 0.0))
  (let* ((len (##sys#size str))
         (0..r (integer->char (fx+ (char->integer #\0) (fx- radix 1))))
         (a..r (integer->char (fx+ (char->integer #\a) (fx- radix 11))))
         (A..r (integer->char (fx+ (char->integer #\A) (fx- radix 11))))
         ;; Ugly flag which we need (note that "exactness" is mutated too!)
         ;; Since there is (almost) no backtracking we can do this.
         (seen-hashes? #f)
         ;; All these procedures return #f or an object consed onto an end
         ;; position.  If the cdr is false, that's the end of the string.
         ;; If just #f is returned, the string contains invalid number syntax.
         (scan-digits
          (lambda (start)
            (let lp ((i start))
              (if (fx= i len)
                  (and (fx> i start) (cons i #f))
                  (let ((c (%subchar str i)))
                    (if (fx<= radix 10)
                        (if (and (char>=? c #\0) (char<=? c 0..r))
                            (lp (fx+ i 1))
                            (and (fx> i start) (cons i i)))
                        (if (or (and (char>=? c #\0) (char<=? c #\9))
                                (and (char>=? c #\a) (char<=? c a..r))
                                (and (char>=? c #\A) (char<=? c A..r)))
                            (lp (fx+ i 1))
                            (and (fx> i start) (cons i i)))))))))
         (scan-hashes
          (lambda (start)
            (let lp ((i start))
              (if (fx= i len)
                  (and (fx> i start) (cons i #f))
                  (let ((c (%subchar str i)))
                    (if (eq? c #\#)
                        (lp (fx+ i 1))
                        (and (fx> i start) (cons i i))))))))
         (scan-digits+hashes
          (lambda (start neg? all-hashes-ok?)
            (let* ((digits (and (not seen-hashes?) (scan-digits start)))
                   (hashes (if digits
                               (and (cdr digits) (scan-hashes (cdr digits)))
                               (and all-hashes-ok? (scan-hashes start))))
                   (end (or hashes digits)))
              (and-let* ((end)
                         (num (##core#inline_allocate
			       ("C_s_a_i_digits_to_integer" 6)
			       str start (car end) radix neg?)))
                (when hashes            ; Eeewww. Feeling dirty yet?
                  (set! seen-hashes? #t)
                  (go-inexact! neg?))
                (cons num (cdr end))))))
         (scan-exponent
          (lambda (start)
            (and (fx< start len)
                 (let ((sign (case (%subchar str start)
                               ((#\+) 'pos) ((#\-) 'neg) (else #f))))
                   (and-let* ((start (if sign (fx+ start 1) start))
                              (end (scan-digits start)))
                     (cons (##core#inline_allocate
			    ("C_s_a_i_digits_to_integer" 6)
			    str start (car end) radix (eq? sign 'neg))
                           (cdr end)))))))
         (scan-decimal-tail             ; The part after the decimal dot
          (lambda (start neg? decimal-head)
            (and (fx< start len)
                 (let* ((tail (scan-digits+hashes start neg? decimal-head))
                        (next (if tail (cdr tail) start)))
                   (and (or decimal-head (not next)
                            (fx> next start)) ; Don't allow empty "."
                        (case (and next (%subchar str next))
                          ((#\e #\s #\f #\d #\l
                            #\E #\S #\F #\D #\L)
                           (and-let* (((fx> len next))
                                      (ee (scan-exponent (fx+ next 1)))
                                      (e (car ee))
                                      (h (safe-exponent decimal-head e)))
                             (let* ((te (and tail (fx- e (fx- (cdr tail) start))))
                                    (num (and tail (car tail)))
                                    (t (safe-exponent num te)))
                               (cons (if t (+ h t) h) (cdr ee)))))
                          (else (let* ((last (or next len))
                                       (te (and tail (fx- start last)))
                                       (num (and tail (car tail)))
                                       (t (safe-exponent num te))
                                       (h (or decimal-head 0)))
                                  (cons (if t (+ h t) h) next)))))))))
         (scan-ureal
          (lambda (start neg?)
            (if (and (fx> len (fx+ start 1)) (eq? radix 10)
                     (eq? (%subchar str start) #\.))
                (begin
                  (go-inexact! neg?)
                  (scan-decimal-tail (fx+ start 1) neg? #f))
                (and-let* ((end (scan-digits+hashes start neg? #f)))
                  (case (and (cdr end) (%subchar str (cdr end)))
                    ((#\.)
                     (go-inexact! neg?)
                     (and (eq? radix 10)
                          (if (fx> len (fx+ (cdr end) 1))
                              (scan-decimal-tail (fx+ (cdr end) 1) neg? (car end))
                              (cons (car end) #f))))
                    ((#\e #\s #\f #\d #\l
                      #\E #\S #\F #\D #\L)
                     (go-inexact! neg?)
                     (and-let* (((eq? radix 10))
                                ((fx> len (cdr end)))
                                (ee (scan-exponent (fx+ (cdr end) 1)))
                                (num (car end))
                                (val (safe-exponent num (car ee))))
                       (cons val (cdr ee))))
                    ((#\/)
                     (set! seen-hashes? #f) ; Reset flag for denominator
                     (and-let* (((fx> len (cdr end)))
                                (d (scan-digits+hashes (fx+ (cdr end) 1) #f #f))
                                (num (car end))
                                (denom (car d)))
                       (if (not (eq? denom 0))
                           (cons (##sys#/-2 num denom) (cdr d))
                           ;; Hacky: keep around an inexact until we decide we
                           ;; *really* need exact values, then fail at the end.
                           (and (not (eq? exactness 'e))
                                (case (signum num)
                                  ((-1) (cons -inf.0 (cdr d)))
                                  ((0)  (cons (make-nan) (cdr d)))
                                  ((+1) (cons +inf.0 (cdr d))))))))
                    (else end))))))
         (scan-real
          (lambda (start)
            (and (fx< start len)
                 (let* ((sign (case (%subchar str start)
                                ((#\+) 'pos) ((#\-) 'neg) (else #f)))
                        (next (if sign (fx+ start 1) start)))
                   (and (fx< next len)
                        (case (%subchar str next)
                          ((#\i #\I)
                           (or (and sign
                                    (cond
                                     ((fx= (fx+ next 1) len) ; [+-]i
                                      (cons (if (eq? sign 'neg) -1 1) next))
                                     ((and (fx<= (fx+ next 5) len)
                                           (string-ci=? (substring str next (fx+ next 5)) "inf.0"))
                                      (go-inexact! (eq? sign 'neg))
                                      (cons (if (eq? sign 'neg) -inf.0 +inf.0)
                                            (and (fx< (fx+ next 5) len)
                                                 (fx+ next 5))))
                                     (else #f)))
                               (scan-ureal next (eq? sign 'neg))))
                          ((#\n #\N)
                           (or (and sign
                                    (fx<= (fx+ next 5) len)
                                    (string-ci=? (substring str next (fx+ next 5)) "nan.0")
                                    (begin (go-inexact! (eq? sign 'neg))
                                           (cons (make-nan)
                                                 (and (fx< (fx+ next 5) len)
                                                      (fx+ next 5)))))
                               (scan-ureal next (eq? sign 'neg))))
                          (else (scan-ureal next (eq? sign 'neg)))))))))
         (number (and-let* ((r1 (scan-real offset)))
                   (case (and (cdr r1) (%subchar str (cdr r1)))
                     ((#f) (car r1))
                     ((#\i #\I) (and (fx= len (fx+ (cdr r1) 1))
                                     (or (eq? (%subchar str offset) #\+) ; ugh
                                         (eq? (%subchar str offset) #\-))
                                     (make-rectangular 0 (car r1))))
                     ((#\+ #\-)
                      (set! seen-hashes? #f) ; Reset flag for imaginary part
                      (and-let* ((r2 (scan-real (cdr r1)))
                                 ((cdr r2))
                                 ((fx= len (fx+ (cdr r2) 1)))
                                 ((or (eq? (%subchar str (cdr r2)) #\i)
                                      (eq? (%subchar str (cdr r2)) #\I))))
                        (make-rectangular (car r1) (car r2))))
                     ((#\@)
                      (set! seen-hashes? #f) ; Reset flag for angle
                      (and-let* ((r2 (scan-real (fx+ (cdr r1) 1)))
                                 ((not (cdr r2))))
                        (make-polar (car r1) (car r2))))
                     (else #f)))))
    (and number (if (eq? exactness 'i)
                    (let ((r (exact->inexact number)))
                      ;; Stupid hack because flonums can represent negative zero,
                      ;; but we're coming from an exact which has no such thing.
                      (if (and negative (zero? r)) (fpneg r) r))
                    ;; Ensure we didn't encounter +inf.0 or +nan.0 with #e
                    (and (finite? number) number)))))

(set! scheme#string->number
  (lambda (str #!optional (base 10))
    (##sys#check-string str 'string->number)
    (unless (and (##core#inline "C_fixnump" base)
		 (fx< 1 base) (fx< base 37)) ; We only have 0-9 and the alphabet!
      (##sys#error-bad-base base 'string->number))
    (let scan-prefix ((i 0)
		      (exness #f)
		      (radix #f)
		      (len (##sys#size str)))
      (if (and (fx< (fx+ i 2) len) (eq? (%subchar str i) #\#))
	  (case (%subchar str (fx+ i 1))
	    ((#\i #\I) (and (not exness) (scan-prefix (fx+ i 2) 'i radix len)))
	    ((#\e #\E) (and (not exness) (scan-prefix (fx+ i 2) 'e radix len)))
	    ((#\b #\B) (and (not radix) (scan-prefix (fx+ i 2) exness 2 len)))
	    ((#\o #\O) (and (not radix) (scan-prefix (fx+ i 2) exness 8 len)))
	    ((#\d #\D) (and (not radix) (scan-prefix (fx+ i 2) exness 10 len)))
	    ((#\x #\X) (and (not radix) (scan-prefix (fx+ i 2) exness 16 len)))
	    (else #f))
	  (##sys#string->compnum (or radix base) str i exness)))))

(define (##sys#string->number str #!optional (radix 10) exactness)
  (##sys#string->compnum radix str 0 exactness))

(define ##sys#fixnum->string (##core#primitive "C_fixnum_to_string"))
(define ##sys#flonum->string (##core#primitive "C_flonum_to_string"))
(define ##sys#integer->string (##core#primitive "C_integer_to_string"))
(define ##sys#number->string number->string)

(set! chicken.base#equal=?
  (lambda (x y)
    (define (compare-slots x y start)
      (let ((l1 (##sys#size x))
	    (l2 (##sys#size y)))
	(and (eq? l1 l2)
	     (or (fx<= l1 start)
		 (let ((l1n (fx- l1 1)))
		   (let loop ((i start))
		     (if (fx= i l1n)
			 (walk (##sys#slot x i) (##sys#slot y i)) ; tailcall
			 (and (walk (##sys#slot x i) (##sys#slot y i))
			      (loop (fx+ i 1))))))))))
    (define (walk x y)
      (cond ((eq? x y))
	    ((number? x)
	     (if (number? y)
		 (= x y)
		 (eq? x y)))
	    ((not (##core#inline "C_blockp" x)) #f)
	    ((not (##core#inline "C_blockp" y)) #f)
	    ((not (##core#inline "C_sametypep" x y)) #f)
	    ((##core#inline "C_specialp" x)
	     (and (##core#inline "C_specialp" y)
		  (if (##core#inline "C_closurep" x)
		      (##core#inline "shallow_equal" x y)
		      (compare-slots x y 1))))
	    ((##core#inline "C_byteblockp" x)
	     (and (##core#inline "C_byteblockp" y)
		  (let ((s1 (##sys#size x)))
		    (and (eq? s1 (##sys#size y))
			 (##core#inline "C_substring_compare" x y 0 0 s1)))))
	    (else
	     (let ((s1 (##sys#size x)))
	       (and (eq? s1 (##sys#size y))
		    (compare-slots x y 0))))))
    (walk x y) ))


;;; Symbols:

(define ##sys#snafu '##sys#fnord)
(define ##sys#intern-symbol (##core#primitive "C_string_to_symbol"))
(define ##sys#intern-keyword (##core#primitive "C_string_to_keyword"))
(define (##sys#interned-symbol? x) (##core#inline "C_lookup_symbol" x))

(define (##sys#string->symbol str)
  (##sys#check-string str)
  (##sys#intern-symbol str) )

(define (##sys#symbol->string s)
  (##sys#slot s 1))

(set! scheme#symbol->string
  (lambda (s)
    (##sys#check-symbol s 'symbol->string)
    (string-copy (##sys#symbol->string s) ) ))

(set! scheme#string->symbol
  (let ((string-copy string-copy))
    (lambda (str)
      (##sys#check-string str 'string->symbol)
      (##sys#intern-symbol (string-copy str)) ) ) )

(set! chicken.base#string->uninterned-symbol
  (let ((string-copy string-copy))
    (lambda (str)
      (##sys#check-string str 'string->uninterned-symbol)
      ((##core#primitive "C_make_symbol") (string-copy str)))))

(set! chicken.base#gensym
  (let ((counter -1))
    (lambda str-or-sym
      (let ((err (lambda (prefix) (##sys#signal-hook #:type-error 'gensym "argument is not a string or symbol" prefix))))
	(set! counter (fx+ counter 1))
	((##core#primitive "C_make_symbol")
	 (##sys#string-append
	  (if (eq? str-or-sym '())
	      "g"
	      (let ((prefix (car str-or-sym)))
		(or (and (##core#inline "C_blockp" prefix)
			 (cond ((##core#inline "C_stringp" prefix) prefix)
			       ((##core#inline "C_symbolp" prefix) (##sys#symbol->string prefix))
			       (else (err prefix))))
		    (err prefix) ) ) )
	  (##sys#number->string counter) ) ) ) ) ) )

(set! chicken.base#symbol-append
  (let ((string-append string-append))
    (lambda ss
      (##sys#intern-symbol
       (apply
	string-append 
	(map (lambda (s)
	       (##sys#check-symbol s 'symbol-append)
	       (##sys#symbol->string s))
	     ss))))))

;;; Keywords:

(module chicken.keyword
  (keyword? get-keyword keyword->string string->keyword)

(import scheme)
(import chicken.fixnum)

(define (keyword? x) (##core#inline "C_i_keywordp" x) )

(define string->keyword
  (let ([string string] )
    (lambda (s)
      (##sys#check-string s 'string->keyword)
      (##sys#intern-keyword s) ) ) )

(define keyword->string
  (let ([keyword? keyword?])
    (lambda (kw)
      (if (keyword? kw)
	  (##sys#symbol->string kw)
	  (##sys#signal-hook #:type-error 'keyword->string "bad argument type - not a keyword" kw) ) ) ) )

(define get-keyword
  (let ((tag (list 'tag)))
    (lambda (key args #!optional thunk)
      (##sys#check-keyword key 'get-keyword)
      (##sys#check-list args 'get-keyword)
      (let ((r (##core#inline "C_i_get_keyword" key args tag)))
	(if (eq? r tag)			; not found
	    (and thunk (thunk))
	    r)))))

(define ##sys#get-keyword get-keyword))

(import chicken.keyword)


;;; Blob:

(module chicken.blob
  (blob->string string->blob blob? blob=? blob-size make-blob)

(import scheme)

(define (##sys#make-blob size)
  (let ([bv (##sys#allocate-vector size #t #f #t)])
    (##core#inline "C_string_to_bytevector" bv)
    bv) )

(define (make-blob size)
  (##sys#check-fixnum size 'make-blob)
  (##sys#make-blob size) )

(define (blob? x)
  (and (##core#inline "C_blockp" x)
       (##core#inline "C_bytevectorp" x) ) )

(define (blob-size bv)
  (##sys#check-blob bv 'blob-size)
  (##sys#size bv) )

(define (string->blob s)
  (##sys#check-string s 'string->blob)
  (let* ([n (##sys#size s)]
	 [bv (##sys#make-blob n)] )
    (##core#inline "C_copy_memory" bv s n) 
    bv) )

(define (blob->string bv)
  (##sys#check-blob bv 'blob->string)
  (let* ([n (##sys#size bv)]
	 [s (##sys#make-string n)] )
    (##core#inline "C_copy_memory" s bv n) 
    s) )

(define (blob=? b1 b2)
  (##sys#check-blob b1 'blob=?)
  (##sys#check-blob b2 'blob=?)
  (let ((n (##sys#size b1)))
    (and (eq? (##sys#size b2) n)
	 (zero? (##core#inline "C_string_compare" b1 b2 n)))))

) ; chicken.blob



;;; Vectors:
(set! scheme#make-vector
  (lambda (size . fill)
    (##sys#check-fixnum size 'make-vector)
    (when (fx< size 0) (##sys#error 'make-vector "size is negative" size))
    (##sys#allocate-vector
     size #f
     (if (null? fill)
	 (##core#undefined)
	 (car fill) )
     #f) ))

(define ##sys#make-vector make-vector)

(set! scheme#list->vector
  (lambda (lst0)
    (if (not (list? lst0))
	(##sys#error-not-a-proper-list lst0 'list->vector)
	(let* ([len (length lst0)]
	       [v (##sys#make-vector len)] )
	  (let loop ([lst lst0]
		     [i 0])
	    (if (null? lst)
		v
		(begin
		  (##sys#setslot v i (##sys#slot lst 0))
		  (loop (##sys#slot lst 1) (fx+ i 1)) ) ) ) ) )))

(set! scheme#vector->list
  (lambda (v)
    (##sys#check-vector v 'vector->list)
    (let ((len (##core#inline "C_block_size" v)))
      (let loop ((i 0))
	(if (fx>= i len)
	    '()
	    (cons (##sys#slot v i)
		  (loop (fx+ i 1)) ) ) ) ) ))

(set! scheme#vector (lambda xs (list->vector xs) ))

(set! scheme#vector-fill!
  (lambda (v x)
    (##sys#check-vector v 'vector-fill!)
    (let ((len (##core#inline "C_block_size" v)))
      (do ((i 0 (fx+ i 1)))
	  ((fx>= i len))
	(##sys#setslot v i x) ) ) ))

(set! chicken.base#vector-copy!
  (lambda (from to . n)
    (##sys#check-vector from 'vector-copy!)
    (##sys#check-vector to 'vector-copy!)
    (let* ((len-from (##sys#size from))
	   (len-to (##sys#size to))
	   (n (if (pair? n) (car n) (fxmin len-to len-from))))
      (##sys#check-fixnum n 'vector-copy!)
      (when (or (fx> n len-to) (fx> n len-from))
	(##sys#signal-hook
	 #:bounds-error 'vector-copy!
	 "cannot copy vector - count exceeds length" from to n))
      (do ((i 0 (fx+ i 1)))
	  ((fx>= i n))
	(##sys#setslot to i (##sys#slot from i))))))

(set! chicken.base#subvector
  (lambda (v i #!optional j)
    (##sys#check-vector v 'subvector)
    (let* ((len (##sys#size v))
	   (j (or j len))
	   (len2 (fx- j i)))
      (##sys#check-range i 0 (fx+ len 1) 'subvector)
      (##sys#check-range j 0 (fx+ len 1) 'subvector)
      (let ((v2 (make-vector len2)))
	(do ((k 0 (fx+ k 1)))
	    ((fx>= k len2) v2)
	  (##sys#setslot v2 k (##sys#slot v (fx+ k i))))))))

(set! chicken.base#vector-resize
  (lambda (v n #!optional init)
    (##sys#check-vector v 'vector-resize)
    (##sys#check-fixnum n 'vector-resize)
    (##sys#vector-resize v n init)))

(define (##sys#vector-resize v n init)
  (let ((v2 (##sys#make-vector n init))
	(len (min (##sys#size v) n)) )
    (do ((i 0 (fx+ i 1)))
	((fx>= i len) v2)
      (##sys#setslot v2 i (##sys#slot v i)) ) ) )

;;; Characters:

(let ((char-downcase char-downcase))
  (set! scheme#char-ci=? (lambda (x y)
			   (eq? (char-downcase x)
				(char-downcase y))))
  (set! scheme#char-ci>? (lambda (x y)
			   (##core#inline "C_u_i_char_greaterp"
					  (char-downcase x)
					  (char-downcase y))))
  (set! scheme#char-ci<? (lambda (x y)
			   (##core#inline "C_u_i_char_lessp"
					  (char-downcase x)
					  (char-downcase y))))
  (set! scheme#char-ci>=? (lambda (x y)
			    (##core#inline "C_u_i_char_greater_or_equal_p"
					   (char-downcase x)
					   (char-downcase y))))
  (set! scheme#char-ci<=? (lambda (x y)
			    (##core#inline "C_u_i_char_less_or_equal_p"
					   (char-downcase x)
					   (char-downcase y)))) )

(set! chicken.base#char-name
  (let ((chars-to-names (make-vector char-name-table-size '()))
	(names-to-chars '()))
    (define (lookup-char c)
      (let* ([code (char->integer c)]
	     [key (##core#inline "C_fixnum_modulo" code char-name-table-size)] )
	(let loop ([b (##sys#slot chars-to-names key)])
	  (and (pair? b)
	       (let ([a (##sys#slot b 0)])
		 (if (eq? (##sys#slot a 0) c)
		     a
		     (loop (##sys#slot b 1)) ) ) ) ) ) )
    (lambda (x . y)
      (let ([chr (if (pair? y) (car y) #f)])
	(cond [(char? x)
	       (and-let* ([a (lookup-char x)])
		 (##sys#slot a 1) ) ]
	      [chr
	       (##sys#check-symbol x 'char-name)
	       (##sys#check-char chr 'char-name)
	       (when (fx< (##sys#size (##sys#slot x 1)) 2)
		 (##sys#signal-hook #:type-error 'char-name "invalid character name" x) )
	       (let ([a (lookup-char chr)])
		 (if a 
		     (let ([b (assq x names-to-chars)])
		       (##sys#setslot a 1 x)
		       (if b
			   (##sys#setislot b 1 chr)
			   (set! names-to-chars (cons (cons x chr) names-to-chars)) ) )
		     (let ([key (##core#inline "C_fixnum_modulo" (char->integer chr) char-name-table-size)])
		       (set! names-to-chars (cons (cons x chr) names-to-chars))
		       (##sys#setslot 
			chars-to-names key
			(cons (cons chr x) (##sys#slot chars-to-names key))) ) ) ) ]
	      [else
	       (##sys#check-symbol x 'char-name)
	       (and-let* ([a (assq x names-to-chars)])
		 (##sys#slot a 1) ) ] ) ) ) ) )

;; TODO: Use the character names here in the next release?  Or just
;; use the numbers everywhere, for clarity?
(char-name 'space #\space)
(char-name 'tab #\tab)
(char-name 'linefeed #\linefeed)
(char-name 'newline #\newline)
(char-name 'vtab (integer->char 11))
(char-name 'delete (integer->char 127))
(char-name 'esc (integer->char 27))
(char-name 'escape (integer->char 27))
(char-name 'alarm (integer->char 7))
(char-name 'nul (integer->char 0))
(char-name 'null (integer->char 0))
(char-name 'return #\return)
(char-name 'page (integer->char 12))
(char-name 'backspace (integer->char 8))


;;; Procedures:

(define ##sys#call-with-current-continuation (##core#primitive "C_call_cc"))
(define ##sys#call-with-cthulhu (##core#primitive "C_call_with_cthulhu"))
(define ##sys#call-with-values call-with-values)

(define (##sys#for-each p lst0)
  (let loop ((lst lst0))
    (cond ((eq? lst '()) (##core#undefined))
	  ((pair? lst)
	   (p (##sys#slot lst 0))
	   (loop (##sys#slot lst 1)) )
	  (else (##sys#error-not-a-proper-list lst0 'for-each)) ) ))

(define (##sys#map p lst0)
  (let loop ((lst lst0))
    (cond ((eq? lst '()) lst)
	  ((pair? lst)
	   (cons (p (##sys#slot lst 0)) (loop (##sys#slot lst 1))) )
	  (else (##sys#error-not-a-proper-list lst0 'map)) ) ))

(letrec ((mapsafe
	  (lambda (p lsts loc)
	    (call-with-current-continuation
	     (lambda (empty)
	       (let lp ((lsts lsts))
		 (if (eq? lsts '())
		     lsts
		     (let ((item (##sys#slot lsts 0)))
		       (cond ((eq? item '()) (empty '()))
			     ((pair? item)
			      (cons (p item) (lp (##sys#slot lsts 1))))
			     (else (##sys#error-not-a-proper-list item loc)))))))))))

  (set! scheme#for-each
    (lambda (fn lst1 . lsts)
      (if (null? lsts)
	  (##sys#for-each fn lst1)
	  (let loop ((all (cons lst1 lsts)))
	    (let* ((first (##sys#slot all 0))
		   (safe-args (mapsafe (lambda (x) (car x)) all 'for-each))) ; ensure inlining
	      (when (pair? safe-args)
		(apply fn safe-args)
		(loop (mapsafe (lambda (x) (cdr x)) all 'for-each))))))))

  (set! scheme#map
    (lambda (fn lst1 . lsts)
      (if (null? lsts)
	  (##sys#map fn lst1)
	  (let loop ((all (cons lst1 lsts)))
	    (let* ((first (##sys#slot all 0))
		   (safe-args (mapsafe (lambda (x) (car x)) all 'map)))
	      (if (pair? safe-args)
		  (cons (apply fn safe-args)
			(loop (mapsafe (lambda (x) (cdr x)) all 'map)))
		  '())))))))


;;; dynamic-wind:
;
; (taken more or less directly from SLIB)
;
; This implementation is relatively costly: we have to shadow call/cc
; with a new version that unwinds suspended thunks, but for this to
; happen the return-values of the escaping procedure have to be saved
; temporarily in a list. Since call/cc is very efficient under this
; implementation, and because allocation of memory that is to be
; garbage soon has also quite low overhead, the performance-penalty
; might be acceptable (ctak needs about 4 times longer).

(define ##sys#dynamic-winds '())

(set! scheme#dynamic-wind
  (lambda (before thunk after)
    (before)
    (set! ##sys#dynamic-winds (cons (cons before after) ##sys#dynamic-winds))
    (##sys#call-with-values
     thunk
     (lambda results
       (set! ##sys#dynamic-winds (##sys#slot ##sys#dynamic-winds 1))
       (after)
       (apply ##sys#values results) ) ) ))

(define ##sys#dynamic-wind dynamic-wind)

(set! scheme#call-with-current-continuation
  (lambda (proc)
    (let ((winds ##sys#dynamic-winds))
      (##sys#call-with-current-continuation
       (lambda (cont)
	 (define (continuation . results)
	   (unless (eq? ##sys#dynamic-winds winds)
	     (##sys#dynamic-unwind winds (fx- (length ##sys#dynamic-winds) (length winds))) )
	   (apply cont results) )
	 (proc continuation) ))) ))

(set! chicken.base#call/cc call-with-current-continuation)

(define (##sys#dynamic-unwind winds n)
  (cond [(eq? ##sys#dynamic-winds winds)]
	[(fx< n 0)
	 (##sys#dynamic-unwind (##sys#slot winds 1) (fx+ n 1))
	 ((##sys#slot (##sys#slot winds 0) 0))
	 (set! ##sys#dynamic-winds winds) ]
	[else
	 (let ([after (##sys#slot (##sys#slot ##sys#dynamic-winds 0) 1)])
	   (set! ##sys#dynamic-winds (##sys#slot ##sys#dynamic-winds 1))
	   (after)
	   (##sys#dynamic-unwind winds (fx- n 1)) ) ] ) )


;;; Ports:

(set! chicken.base#port?
  (lambda (x)
    (and (##core#inline "C_blockp" x)
         (##core#inline "C_portp" x))))

(set! chicken.base#input-port-open?
  (lambda (p)
    (##sys#check-input-port p 'input-port-open?)
    (##core#inline "C_input_port_openp" p)))

(set! chicken.base#output-port-open?
  (lambda (p)
    (##sys#check-output-port p 'output-port-open?)
    (##core#inline "C_output_port_openp" p)))

(set! chicken.base#port-closed?
  (lambda (p)
    (##sys#check-port p 'port-closed?)
    (eq? (##sys#slot p 8) 0)))

;;; Custom ports:

;;; Port layout:
;
; 0:  FP (special)
; 1:  direction (fixnum)
; 2:  class (vector of procedures)
; 3:  name (string)
; 4:  row (fixnum)
; 5:  col (fixnum)
; 6:  EOF (bool)
; 7:  type ('stream | 'custom | 'string | 'socket)
; 8:  closed (fixnum)
; 9:  data
; 10-15: reserved, port class specific
;
; Port-class:
;
; 0:  (read-char PORT) -> CHAR | EOF
; 1:  (peek-char PORT) -> CHAR | EOF
; 2:  (write-char PORT CHAR)
; 3:  (write-string PORT STRING)
; 4:  (close PORT)
; 5:  (flush-output PORT)
; 6:  (char-ready? PORT) -> BOOL
; 7:  (read-string! PORT COUNT STRING START) -> COUNT'
; 8:  (read-line PORT LIMIT) -> STRING | EOF
; 9:  (read-buffered PORT) -> STRING

(define (##sys#make-port i/o class name type)
  (let ([port (##core#inline_allocate ("C_a_i_port" 17))])
    (##sys#setislot port 1 i/o)
    (##sys#setslot port 2 class)
    (##sys#setslot port 3 name)
    (##sys#setislot port 4 1)
    (##sys#setislot port 5 0)
    (##sys#setslot port 7 type)
    (##sys#setslot port 8 i/o)
    port) )

;;; Stream ports:
; Input port slots:
;   12: Static buffer for read-line, allocated on-demand

(define ##sys#stream-port-class
  (vector (lambda (p)			; read-char
	    (let loop ()
	      (let ((c (##core#inline "C_read_char" p)))
		(cond
		 ((eq? -1 c)
                  (let ((err (##sys#update-errno)))
                    (if (eq? err (foreign-value "EINTR" int))
                        (##sys#dispatch-interrupt loop)
                        (##sys#signal-hook/errno
                         #:file-error err 'read-char
                         (##sys#string-append "cannot read from port - " strerror)
                         p))))
		 (else c)))))
	  (lambda (p)			; peek-char
	    (let loop ()
	      (let ((c (##core#inline "C_peek_char" p)))
		(cond
		 ((eq? -1 c)
                  (let ((err (##sys#update-errno)))
                    (if (eq? err (foreign-value "EINTR" int))
                        (##sys#dispatch-interrupt loop)
                        (##sys#signal-hook/errno
                         #:file-error err 'peek-char
                         (##sys#string-append "cannot read from port - " strerror)
                         p))))
		 (else c)))))
	  (lambda (p c)			; write-char
	    (##core#inline "C_display_char" p c) )
	  (lambda (p s)			; write-string
	    (##core#inline "C_display_string" p s) )
	  (lambda (p d)			; close
	    (##core#inline "C_close_file" p)
	    (##sys#update-errno) )
	  (lambda (p)			; flush-output
	    (##core#inline "C_flush_output" p) )
	  (lambda (p)			; char-ready?
	    (##core#inline "C_char_ready_p" p) )
	  (lambda (p n dest start)		; read-string!
	    (let loop ([rem (or n (fx- (##sys#size dest) start))] [act 0] [start start])
	      (let ([len (##core#inline "fast_read_string_from_file" dest p rem start)])
		(cond ((eof-object? len) ; EOF returns 0 bytes read
		       act)
		      ((fx< len 0)
                       (let ((err (##sys#update-errno)))
                         (if (eq? err (foreign-value "EINTR" int))
                             (##sys#dispatch-interrupt
                              (lambda ()
                                (loop (fx- rem len) (fx+ act len) (fx+ start len))))
                             (##sys#signal-hook/errno
                              #:file-error err 'read-string!
                              (##sys#string-append "cannot read from port - " strerror)
                              p n dest start))))
		      ((fx< len rem)
		       (loop (fx- rem len) (fx+ act len) (fx+ start len)))
		      (else
		       (fx+ act len) ) ) )))
	  (lambda (p rlimit)		; read-line
	    (if rlimit (##sys#check-fixnum rlimit 'read-line))
	    (let ((sblen read-line-buffer-initial-size))
	      (unless (##sys#slot p 12)
		(##sys#setslot p 12 (##sys#make-string sblen)))
	      (let loop ([len sblen]
			 [limit (or rlimit maximal-string-length)]   ; guaranteed fixnum?
			 [buffer (##sys#slot p 12)]
			 [result ""]
			 [f #f])
		(let ([n (##core#inline "fast_read_line_from_file" buffer p
					(fxmin limit len))])
		  (cond [(eof-object? n) (if f result #!eof)]
			[(not n)
			 (if (fx< limit len)
			     (##sys#string-append result (##sys#substring buffer 0 limit))
			     (loop (fx* len 2)
				   (fx- limit len)
				   (##sys#make-string (fx* len 2))
				   (##sys#string-append result buffer)
				   #t)) ]
			((fx< n 0)
                         (let ((err (##sys#update-errno)))
                           (if (eq? err (foreign-value "EINTR" int))
                               (let ((n (fx- (fxneg n) 1)))
                                 (##sys#dispatch-interrupt
                                  (lambda ()
                                    (loop len limit buffer
                                          (##sys#string-append
                                           result (##sys#substring buffer 0 n))
                                          #t))))
                               (##sys#signal-hook/errno
                                #:file-error err 'read-line
                                (##sys#string-append "cannot read from port - " strerror)
                                p rlimit))))
			[f (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
			   (##sys#string-append result (##sys#substring buffer 0 n))]
			[else
			 (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
			 (##sys#substring buffer 0 n)] ) ) ) ) )
	  #f	; read-buffered
	  ) )

(define ##sys#open-file-port (##core#primitive "C_open_file_port"))

(define ##sys#standard-input (##sys#make-port 1 ##sys#stream-port-class "(stdin)" 'stream))
(define ##sys#standard-output (##sys#make-port 2 ##sys#stream-port-class "(stdout)" 'stream))
(define ##sys#standard-error (##sys#make-port 2 ##sys#stream-port-class "(stderr)" 'stream))

(##sys#open-file-port ##sys#standard-input 0 #f)
(##sys#open-file-port ##sys#standard-output 1 #f)
(##sys#open-file-port ##sys#standard-error 2 #f)

(define (##sys#check-input-port x open . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_port_2" x 1 open (car loc))
      (##core#inline "C_i_check_port" x 1 open)))

(define (##sys#check-output-port x open . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_port_2" x 2 open (car loc))
      (##core#inline "C_i_check_port" x 2 open)))

(define (##sys#check-port x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_port_2" x 0 #f (car loc))
      (##core#inline "C_i_check_port" x 0 #f) ) )

(define (##sys#check-open-port x . loc)
  (if (pair? loc)
      (##core#inline "C_i_check_port_2" x 0 #t (car loc))
      (##core#inline "C_i_check_port" x 0 #t) ) )

(set! scheme#current-input-port
  (lambda args
    (if (null? args)
	##sys#standard-input
	(let ((p (car args)))
	  (##sys#check-port p 'current-input-port)
	  (let-optionals (cdr args) ((convert? #t) (set? #t))
	    (when set? (set! ##sys#standard-input p)))
	  p) ) ))

(set! scheme#current-output-port
  (lambda args
    (if (null? args)
	##sys#standard-output
	(let ((p (car args)))
	  (##sys#check-port p 'current-output-port)
	  (let-optionals (cdr args) ((convert? #t) (set? #t))
	    (when set? (set! ##sys#standard-output p)))
	  p) ) ))

(set! chicken.base#current-error-port
  (lambda args
    (if (null? args)
	##sys#standard-error
	(let ((p (car args)))
	  (##sys#check-port p 'current-error-port)
	  (let-optionals (cdr args) ((convert? #t) (set? #t))
	    (when set? (set! ##sys#standard-error p)))
	  p))))

(define (##sys#tty-port? port)
  (and (not (zero? (##sys#peek-unsigned-integer port 0)))
       (##core#inline "C_tty_portp" port) ) )

(define (##sys#port-data port) (##sys#slot port 9))
(define (##sys#set-port-data! port data) (##sys#setslot port 9 data))

(let ()
  (define (open name inp modes loc)
    (##sys#check-string name loc)
    (let ([fmode (if inp "r" "w")]
          [bmode ""] )
      (do ([modes modes (##sys#slot modes 1)])
        ((null? modes))
        (let ([o (##sys#slot modes 0)])
          (case o
            [(#:binary) (set! bmode "b")]
            [(#:text) (set! bmode "")]
            [(#:append)
             (if inp
               (##sys#error loc "cannot use append mode with input file")
               (set! fmode "a") ) ]
            [else (##sys#error loc "invalid file option" o)] ) ) )
      (let ((port (##sys#make-port (if inp 1 2) ##sys#stream-port-class name 'stream)))
        (unless (##sys#open-file-port port name (##sys#string-append fmode bmode))
          (##sys#signal-hook/errno #:file-error (##sys#update-errno) loc
                                   (##sys#string-append "cannot open file - " strerror)
                                   name))
        port) ) )

  (define (close port inp loc)
    (##sys#check-port port loc)
    ; repeated closing is ignored
    (let ((direction (if inp 1 2)))
      (when (##core#inline "C_port_openp" port direction)
	(##sys#setislot port 8 (fxand (##sys#slot port 8) (fxnot direction)))
	((##sys#slot (##sys#slot port 2) 4) port direction))))

  (set! scheme#open-input-file (lambda (name . mode) (open name #t mode 'open-input-file)))
  (set! scheme#open-output-file (lambda (name . mode) (open name #f mode 'open-output-file)))
  (set! scheme#close-input-port (lambda (port) (close port #t 'close-input-port)))
  (set! scheme#close-output-port (lambda (port) (close port #f 'close-output-port))))

(set! scheme#call-with-input-file
  (let ((open-input-file open-input-file)
	(close-input-port close-input-port) )
    (lambda (name p . mode)
      (let ((f (apply open-input-file name mode)))
	(##sys#call-with-values
	 (lambda () (p f))
	 (lambda results
	   (close-input-port f)
	   (apply ##sys#values results) ) ) ) ) ) )

(set! scheme#call-with-output-file
  (let ((open-output-file open-output-file)
	(close-output-port close-output-port) )
    (lambda (name p . mode)
      (let ((f (apply open-output-file name mode)))
	(##sys#call-with-values
	 (lambda () (p f))
	 (lambda results
	   (close-output-port f)
	   (apply ##sys#values results) ) ) ) ) ) )

(set! scheme#with-input-from-file
  (let ((open-input-file open-input-file)
	(close-input-port close-input-port) )
    (lambda (str thunk . mode)
      (let ((file (apply open-input-file str mode)))
	(fluid-let ((##sys#standard-input file))
	  (##sys#call-with-values thunk
	    (lambda results
	      (close-input-port file)
	      (apply ##sys#values results) ) ) ) ) ) ) )

(set! scheme#with-output-to-file
  (let ((open-output-file open-output-file)
	(close-output-port close-output-port) ) 
    (lambda (str thunk . mode)
      (let ((file (apply open-output-file str mode)))
	(fluid-let ((##sys#standard-output file))
	  (##sys#call-with-values thunk
	    (lambda results
	      (close-output-port file)
	      (apply ##sys#values results) ) ) ) ) ) ) )

(define (##sys#file-exists? name file? dir? loc)
  (case (##core#inline "C_i_file_exists_p" (##sys#make-c-string name loc) file? dir?)
    ((#f) #f)
    ((#t) #t)
    (else 
     (##sys#signal-hook 
      #:file-error loc "system error while trying to access file" 
      name))))

(define (##sys#flush-output port)
  ((##sys#slot (##sys#slot port 2) 5) port) ; flush-output
  (##core#undefined) )

(set! chicken.base#flush-output
  (lambda (#!optional (port ##sys#standard-output))
    (##sys#check-output-port port #t 'flush-output)
    (##sys#flush-output port)))

(define (##sys#port-line port)
  (and (##core#inline "C_input_portp" port)
       (##sys#slot port 4) ) )

;;; Decorate procedure with arbitrary data
;
; warning: may modify proc, if it already has a suitable decoration!

(define (##sys#decorate-lambda proc pred decorator)
  (let ((len (##sys#size proc)))
    (let loop ((i (fx- len 1)))
      (cond ((zero? i)
	     (let ((p2 (make-vector (fx+ len 1))))
	       (do ((i 1 (fx+ i 1)))
		   ((fx>= i len)
		    (##core#inline "C_vector_to_closure" p2)
		    (##core#inline "C_copy_pointer" proc p2)
		    (decorator p2 i) )
		 (##sys#setslot p2 i (##sys#slot proc i)) ) ) )
	    (else
	     (let ((x (##sys#slot proc i)))
	       (if (pred x)
		   (decorator proc i)
		   (loop (fx- i 1)) ) ) ) ) ) ) )

(define (##sys#lambda-decoration proc pred)
  (let loop ((i (fx- (##sys#size proc) 1)))
    (and (fx> i 0)
	 (let ((x (##sys#slot proc i)))
	   (if (pred x)
	       x
	       (loop (fx- i 1)) ) ) ) ) )


;;; Create lambda-info object

(define (##sys#make-lambda-info str)
  (let* ((sz (##sys#size str))
	 (info (##sys#make-string sz)) )
    (##core#inline "C_copy_memory" info str sz)
    (##core#inline "C_string_to_lambdainfo" info)
    info) )


;;; Function debug info:

(define (##sys#lambda-info? x)
  (and (not (##sys#immediate? x)) (##core#inline "C_lambdainfop" x)))

(define (##sys#lambda-info proc)
  (##sys#lambda-decoration proc ##sys#lambda-info?))

(define (##sys#lambda-info->string info)
  (let* ((sz (##sys#size info))
	 (s (##sys#make-string sz)) )
    (##core#inline "C_copy_memory" s info sz)
    s) )

(set! chicken.base#procedure-information
  (lambda (x)
    (##sys#check-closure x 'procedure-information)
    (and-let* ((info (##sys#lambda-info x)))
      (##sys#read (open-input-string (##sys#lambda-info->string info)) #f) ) ) )


;;; SRFI-17

(define setter-tag (vector 'setter))

(define-inline (setter? x) 
  (and (pair? x) (eq? setter-tag (##sys#slot x 0))) )

(set! chicken.base#setter
  (##sys#decorate-lambda 
   (lambda (proc)
     (or (and-let* (((procedure? proc))
		    (d (##sys#lambda-decoration proc setter?)) )
	   (##sys#slot d 1) )
	 (##sys#error 'setter "no setter defined" proc) ) )
   setter?
   (lambda (proc i)
     (##sys#setslot 
      proc i
      (cons 
       setter-tag
       (lambda (get set)
	 (if (procedure? get)
	     (let ((get2 (##sys#decorate-lambda
			  get
			  setter?
			  (lambda (proc i) (##sys#setslot proc i (cons setter-tag set)) proc))))
	       (if (eq? get get2)
		   get
		   (##sys#become! (list (cons get get2))) ) )
	     (error "can not set setter of non-procedure" get) ) ) ) )
     proc) ) )

(define ##sys#setter setter)

(set! chicken.base#getter-with-setter
  (lambda (get set #!optional info)
    (##sys#check-closure get 'getter-with-setter)
    (##sys#check-closure set 'getter-with-setter)
    (let ((getdec (cond (info
			 (##sys#check-string info 'getter-with-setter)
			 (##sys#make-lambda-info info))
			(else (##sys#lambda-info get))))
	  (p1 (##sys#decorate-lambda
	       (##sys#copy-closure get)
	       setter?
	       (lambda (proc i)
		 (##sys#setslot proc i (cons setter-tag set))
		 proc))))
      (if getdec
	  (##sys#decorate-lambda
	   p1
	   ##sys#lambda-info?
	   (lambda (p i)
	     (##sys#setslot p i getdec)
	     p))
	  p1))))

(set! scheme#car (getter-with-setter scheme#car set-car!))
(set! scheme#cdr (getter-with-setter scheme#cdr set-cdr!))
(set! scheme#caar (getter-with-setter scheme#caar (lambda (x y) (set-car! (car x) y))))
(set! scheme#cadr (getter-with-setter scheme#cadr (lambda (x y) (set-car! (cdr x) y))))
(set! scheme#cdar (getter-with-setter scheme#cdar (lambda (x y) (set-cdr! (car x) y))))
(set! scheme#cddr (getter-with-setter scheme#cddr (lambda (x y) (set-cdr! (cdr x) y))))
(set! scheme#caaar (getter-with-setter scheme#caaar (lambda (x y) (set-car! (caar x) y))))
(set! scheme#caadr (getter-with-setter scheme#caadr (lambda (x y) (set-car! (cadr x) y))))
(set! scheme#cadar (getter-with-setter scheme#cadar (lambda (x y) (set-car! (cdar x) y))))
(set! scheme#caddr (getter-with-setter scheme#caddr (lambda (x y) (set-car! (cddr x) y))))
(set! scheme#cdaar (getter-with-setter scheme#cdaar (lambda (x y) (set-cdr! (caar x) y))))
(set! scheme#cdadr (getter-with-setter scheme#cdadr (lambda (x y) (set-cdr! (cadr x) y))))
(set! scheme#cddar (getter-with-setter scheme#cddar (lambda (x y) (set-cdr! (cdar x) y))))
(set! scheme#cdddr (getter-with-setter scheme#cdddr (lambda (x y) (set-cdr! (cddr x) y))))
(set! scheme#string-ref (getter-with-setter scheme#string-ref string-set!))
(set! scheme#vector-ref (getter-with-setter scheme#vector-ref vector-set!))

(set! scheme#list-ref
  (getter-with-setter
   scheme#list-ref
   (lambda (x i y) (set-car! (list-tail x i) y))))


;;; Parameters:

(define ##sys#default-parameter-vector (##sys#make-vector default-parameter-vector-size))
(define ##sys#current-parameter-vector '#())

(set! chicken.base#make-parameter
  (let ((count 0))
    (lambda (init #!optional (guard (lambda (x) x)))
      (let* ((val (guard init))
	     (i count)
	     (assign (lambda (val n convert? set?)
		       (when (fx>= i n)
			 (set! ##sys#current-parameter-vector
			   (##sys#vector-resize
			    ##sys#current-parameter-vector
			    (fx+ i 1)
			    ##sys#snafu) ) )
		       (let ((val (if convert? (guard val) val)))
			 (when set?
			   (##sys#setslot ##sys#current-parameter-vector i val))
			 val))))

	(set! count (fx+ count 1))
	(when (fx>= i (##sys#size ##sys#default-parameter-vector))
	  (set! ##sys#default-parameter-vector
	    (##sys#vector-resize
	     ##sys#default-parameter-vector
	     (fx+ i 1)
	     (##core#undefined)) ) )
	(##sys#setslot ##sys#default-parameter-vector i val)

	(getter-with-setter
	 (lambda args
	   (let ((n (##sys#size ##sys#current-parameter-vector)))
	     (cond ((pair? args)
		    (let-optionals (cdr args) ((convert? #t)
					       (set? #t))
		      (assign (car args) n convert? set?)))
		   ((fx>= i n)
		    (##sys#slot ##sys#default-parameter-vector i) )
		   (else
		    (let ((val (##sys#slot ##sys#current-parameter-vector i)))
		      (if (eq? val ##sys#snafu)
			  (##sys#slot ##sys#default-parameter-vector i)
			  val) ) ) ) ) )
	 (lambda (val)
	   (let ((n (##sys#size ##sys#current-parameter-vector)))
	     (assign val n #f #t))))))))
  

;;; Input:

(set! scheme#char-ready?
  (lambda (#!optional (port ##sys#standard-input))
    (##sys#check-input-port port #t 'char-ready?)
    ((##sys#slot (##sys#slot port 2) 6) port) )) ; char-ready?

(set! scheme#read-char
  (lambda (#!optional (port ##sys#standard-input))
    (##sys#check-input-port port #t 'read-char)
    (##sys#read-char-0 port) ))

(define (##sys#read-char-0 p)
  (let ([c (if (##sys#slot p 6)
	       (begin
		 (##sys#setislot p 6 #f)
		 #!eof)
	       ((##sys#slot (##sys#slot p 2) 0) p) ) ] ) ; read-char
    (cond [(eq? c #\newline)
	   (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
	   (##sys#setislot p 5 0) ]
	  [(not (##core#inline "C_eofp" c))
	   (##sys#setislot p 5 (fx+ (##sys#slot p 5) 1)) ] )
    c) )

(define (##sys#read-char/port port)
  (##sys#check-input-port port #t 'read-char)
  (##sys#read-char-0 port) )

(define (##sys#peek-char-0 p)
  (if (##sys#slot p 6)
      #!eof
      (let ([c ((##sys#slot (##sys#slot p 2) 1) p)]) ; peek-char
	(when (##core#inline "C_eofp" c)
	  (##sys#setislot p 6 #t) )
	c) ) )

(set! scheme#peek-char
  (lambda (#!optional (port ##sys#standard-input))
    (##sys#check-input-port port #t 'peek-char)
    (##sys#peek-char-0 port) ))

(set! scheme#read
  (lambda (#!optional (port ##sys#standard-input))
    (##sys#check-input-port port #t 'read)
    (##sys#read port ##sys#default-read-info-hook) ))

(define ##sys#default-read-info-hook #f)
(define ##sys#read-error-with-line-number #f)
(define (##sys#read-prompt-hook) #f)	; just here so that srfi-18 works without eval
(define (##sys#infix-list-hook lst) lst)

(define (##sys#sharp-number-hook port n)
  (##sys#read-error port "invalid `#...' read syntax" n) )

(set! chicken.base#case-sensitive (make-parameter #t))
(set! chicken.base#parentheses-synonyms (make-parameter #t))
(set! chicken.base#symbol-escape (make-parameter #t))

(set! chicken.base#keyword-style
  (make-parameter #:suffix (lambda (x) (when x (##sys#check-keyword x 'keyword-style)) x)))

(define ##sys#current-read-table (make-parameter (##sys#make-structure 'read-table #f #f #f)))

(define ##sys#read-warning
  (let ([string-append string-append])
    (lambda (port msg . args)
      (apply
       ##sys#warn
       (let ((ln (##sys#port-line port)))
	 (if (and ##sys#read-error-with-line-number ln)
	     (string-append "(line " (##sys#number->string ln) ") " msg)
	     msg) )
       args) ) ) )

(define ##sys#read-error
  (let ([string-append string-append] )
    (lambda (port msg . args)
      (apply
       ##sys#signal-hook
       #:syntax-error
       (let ((ln (##sys#port-line port)))
	 (if (and ##sys#read-error-with-line-number ln)
	     (string-append "(line " (##sys#number->string ln) ") " msg)
	     msg) )
       args) ) ) )

(define ##sys#read
  (let ((string-append string-append)
	(keyword-style keyword-style)
	(case-sensitive case-sensitive)
	(parentheses-synonyms parentheses-synonyms)
	(symbol-escape symbol-escape)
	(current-read-table ##sys#current-read-table))
    (lambda (port infohandler)
      (let ((csp (case-sensitive))
	    (ksp (keyword-style))
	    (psp (parentheses-synonyms))
	    (sep (symbol-escape))
	    (crt (current-read-table))
	    ; set below - needs more state to make a decision
	    (terminating-characters '(#\, #\; #\( #\) #\' #\" #\[ #\] #\{ #\}))
	    (reserved-characters #f) )

	(define (container c)
	  (##sys#read-error port "unexpected list terminator" c) )

	(define (info class data val)
	  (if infohandler
	      (infohandler class data val)
	      data) )

	(define (skip-to-eol)
	  (let skip ((c (##sys#read-char-0 port)))
	    (if (and (not (##core#inline "C_eofp" c)) (not (eq? #\newline c)))
		(skip (##sys#read-char-0 port)) ) ) )

        (define (reserved-character c)
          (##sys#read-char-0 port)
          (##sys#read-error port "reserved character" c) )

        (define (read-unreserved-char-0 port)
          (let ((c (##sys#read-char-0 port)))
            (if (memq c reserved-characters)
                (reserved-character c)
                c) ) )

	(define (readrec)

	  (define (r-spaces)
	    (let loop ([c (##sys#peek-char-0 port)])
	      (cond ((##core#inline "C_eofp" c))
		    ((eq? #\; c) 
		     (skip-to-eol)
		     (loop (##sys#peek-char-0 port)) )
		    ((char-whitespace? c)
		     (##sys#read-char-0 port)
		     (loop (##sys#peek-char-0 port)) ) ) ) )

	  (define (r-usequence u n base)
	    (let loop ((seq '()) (n n))
	      (if (eq? n 0)
		  (let* ((str (##sys#reverse-list->string seq))
			 (n (string->number str base)))
		    (or n
			(##sys#read-error
			 port
			 (string-append
			  "invalid escape-sequence '\\" u str "\'")) ) )
		  (let ((x (##sys#read-char-0 port)))
		    (if (or (eof-object? x) (char=? #\" x))
			(##sys#read-error port "unterminated string constant") 
			(loop (cons x seq) (fx- n 1)) ) ) ) ) )

	  (define (r-cons-codepoint cp lst)
	    (let* ((s (##sys#char->utf8-string (integer->char cp)))
		   (len (##sys#size s)))
	      (let lp ((i 0) (lst lst))
		(if (fx>= i len)
		  lst
		  (lp (fx+ i 1) (cons (##core#inline "C_subchar" s i) lst))))))

	  (define (r-string term)
	    (let loop ((c (##sys#read-char-0 port)) (lst '()))
	      (cond ((##core#inline "C_eofp" c) 
		     (##sys#read-error port "unterminated string") )
		    ((eq? #\\ c)
		     (set! c (##sys#read-char-0 port))
		     (case c
		       ((#\t) (loop (##sys#read-char-0 port) (cons #\tab lst)))
		       ((#\r) (loop (##sys#read-char-0 port) (cons #\return lst)))
		       ((#\b) (loop (##sys#read-char-0 port) (cons #\backspace lst)))
		       ((#\n) (loop (##sys#read-char-0 port) (cons #\newline lst)))
		       ((#\a) (loop (##sys#read-char-0 port) (cons (integer->char 7) lst)))
		       ((#\v) (loop (##sys#read-char-0 port) (cons (integer->char 11) lst)))
		       ((#\f) (loop (##sys#read-char-0 port) (cons (integer->char 12) lst)))
		       ((#\x) 
			(let ([ch (integer->char (r-usequence "x" 2 16))])
			  (loop (##sys#read-char-0 port) (cons ch lst)) ) )
		       ((#\u)
			(let ([n (r-usequence "u" 4 16)])
			  (if (##sys#unicode-surrogate? n)
			      (if (and (eqv? #\\ (##sys#read-char-0 port))
				       (eqv? #\u (##sys#read-char-0 port)))
				  (let* ((m (r-usequence "u" 4 16))
					 (cp (##sys#surrogates->codepoint n m)))
				    (if cp
					(loop (##sys#read-char-0 port)
					      (r-cons-codepoint cp lst))
					(##sys#read-error port "bad surrogate pair" n m)))
				  (##sys#read-error port "unpaired escaped surrogate" n))
			      (loop (##sys#read-char-0 port) (r-cons-codepoint n lst)) ) ))
		       ((#\U)
			(let ([n (r-usequence "U" 8 16)])
			  (if (##sys#unicode-surrogate? n)
			      (##sys#read-error port "invalid escape (surrogate)" n)
			      (loop (##sys#read-char-0 port) (r-cons-codepoint n lst)) )))
		       ((#\\ #\' #\" #\|)
			(loop (##sys#read-char-0 port) (cons c lst)))
		       ((#\newline #\return #\space #\tab)
			;; Read "escaped" <intraline ws>* <nl> <intraline ws>*
			(let eat-ws ((c c) (nl? #f))
			  (case c
			    ((#\space #\tab)
			     (eat-ws (##sys#read-char-0 port) nl?))
			    ((#\return)
			     (if nl?
				 (loop c lst)
			         (let ((nc (##sys#read-char-0 port)))
			           (if (eq? nc #\newline) ; collapse \r\n
				       (eat-ws (##sys#read-char-0 port) #t)
				       (eat-ws nc #t)))))
			    ((#\newline)
			     (if nl?
				 (loop c lst)
				 (eat-ws (##sys#read-char-0 port) #t)))
			    (else
                             (unless nl?
                               (##sys#read-warning 
				port 
				"escaped whitespace, but no newline - collapsing anyway"))
                             (loop c lst)))))
		       (else
			(cond ((##core#inline "C_eofp" c)
			       (##sys#read-error port "unterminated string"))
			      ((and (char-numeric? c)
				    (char>=? c #\0)
				    (char<=? c #\7))
			       (let ((ch (integer->char 
					  (fx+ (fx* (fx- (char->integer c) 48) 64)
					       (r-usequence "" 2 8)))))
				 (loop (##sys#read-char-0 port) (cons ch lst)) ))
			      (else
			       (##sys#read-warning 
				port 
				"undefined escape sequence in string - probably forgot backslash"
				c)
			       (loop (##sys#read-char-0 port) (cons c lst))) ) )))
		    ((eq? term c) (##sys#reverse-list->string lst))
		    (else (loop (##sys#read-char-0 port) (cons c lst))) ) ))
		    
	  (define (r-list start end)
	    (if (eq? (##sys#read-char-0 port) start)
		(let ((first #f)
		      (ln0 #f)
		      (outer-container container) )
		  (define (starting-line msg)
		    (if (and ln0 ##sys#read-error-with-line-number)
			(string-append 
			 msg ", starting in line "
			 (##sys#number->string ln0))
			msg))
		  (##sys#call-with-current-continuation
		   (lambda (return)
		     (set! container
		       (lambda (c)
			 (if (eq? c end)
			     (return #f)
			     (##sys#read-error
			      port
			      (starting-line "list-terminator mismatch")
			      c end) ) ) )
		     (let loop ([last '()])
		       (r-spaces)
		       (unless first (set! ln0 (##sys#port-line port)))
		       (let ([c (##sys#peek-char-0 port)])
			 (cond ((##core#inline "C_eofp" c)
				(##sys#read-error 
				 port
				 (starting-line "unterminated list") ) )
			       ((eq? c end)
				(##sys#read-char-0 port) )
			       ((eq? c #\.)
				(##sys#read-char-0 port)
				(let ((c2 (##sys#peek-char-0 port)))
				  (cond ((or (char-whitespace? c2)
					     (eq? c2 #\()
					     (eq? c2 #\))
					     (eq? c2 #\")
					     (eq? c2 #\;) )
					 (unless (pair? last)
					   (##sys#read-error port "invalid use of `.'") )
					 (r-spaces)
					 (##sys#setslot last 1 (readrec))
					 (r-spaces)
					 (unless (eq? (##sys#read-char-0 port) end)
					   (##sys#read-error
					    port
					    (starting-line "missing list terminator")
					    end)))
					(else
					 (r-xtoken
					  (lambda (tok kw)
					    (let* ((tok (##sys#string-append "." tok))
						   (val
						    (cond ((and (string=? tok ".:")
								(eq? ksp #:suffix))
							   ;; Edge case: r-xtoken sees
							   ;; a bare ":" and sets kw to #f
							   (build-keyword "."))
							  (kw (build-keyword tok))
							  ((and (char-numeric? c2)
								(##sys#string->number tok)))
							  (else (build-symbol tok))))
						   (node (cons val '())))
					      (if first 
						  (##sys#setslot last 1 node)
						  (set! first node) )
					      (loop node))))))))
			       (else
				(let ([node (cons (readrec) '())])
				  (if first
				      (##sys#setslot last 1 node)
				      (set! first node) )
				  (loop node) ) ) ) ) ) ) )
		  (set! container outer-container)
		  (if first
		      (info 'list-info (##sys#infix-list-hook first) ln0)
		      '() ) )
		(##sys#read-error port "missing token" start) ) )
	  
	  (define (r-vector)
	    (let ((lst (r-list #\( #\))))
	      (if (list? lst)
		  (##sys#list->vector lst)
		  (##sys#read-error port "invalid vector syntax" lst) ) ) )
	  
	  (define (r-number radix exactness)
	    (r-xtoken
	     (lambda (tok kw)
	       (cond (kw
		      (let ((s (build-keyword tok)))
			(info 'symbol-info s (##sys#port-line port)) ))
		     ((string=? tok ".")
		      (##sys#read-error port "invalid use of `.'"))
		     ((and (fx> (##sys#size tok) 0) (char=? (string-ref tok 0) #\#))
		      (##sys#read-error port "unexpected prefix in number syntax" tok))
		     ((##sys#string->number tok (or radix 10) exactness))
		     (radix (##sys#read-error port "illegal number syntax" tok))
		     (else (build-symbol tok))  ) ) ))

	  (define (r-number-with-exactness radix)
	    (cond [(eq? #\# (##sys#peek-char-0 port))
		   (##sys#read-char-0 port)
		   (let ([c2 (##sys#read-char-0 port)])
		     (cond [(eof-object? c2) 
			    (##sys#read-error port "unexpected end of numeric literal")]
			   [(char=? c2 #\i) (r-number radix 'i)]
			   [(char=? c2 #\e) (r-number radix 'e)]
			   [else
			    (##sys#read-error
			     port
			     "illegal number syntax - invalid exactness prefix" c2)] ) ) ]
		  [else (r-number radix #f)] ) )
	  
	  (define (r-number-with-radix exactness)
	    (cond [(eq? #\# (##sys#peek-char-0 port))
		   (##sys#read-char-0 port)
		   (let ([c2 (##sys#read-char-0 port)])
		     (cond [(eof-object? c2) (##sys#read-error port "unexpected end of numeric literal")]
			   [(char=? c2 #\x) (r-number 16 exactness)]
			   [(char=? c2 #\d) (r-number 10 exactness)]
			   [(char=? c2 #\o) (r-number 8 exactness)]
			   [(char=? c2 #\b) (r-number 2 exactness)]
			   [else (##sys#read-error port "illegal number syntax - invalid radix" c2)] ) ) ]
		  [else (r-number 10 exactness)] ) )
	
	  (define (r-token)
	    (let loop ((c (##sys#peek-char-0 port)) (lst '()))
	      (cond ((or (eof-object? c)
			 (char-whitespace? c)
			 (memq c terminating-characters) )
		     (##sys#reverse-list->string lst) )
		    ((char=? c #\x00)
		     (##sys#read-error port "attempt to read expression from something that looks like binary data"))
		    (else
		     (read-unreserved-char-0 port)
		     (loop (##sys#peek-char-0 port) 
		           (cons (if csp c (char-downcase c)) lst) ) ) ) ) )

	  (define (r-digits)
	    (let loop ((c (##sys#peek-char-0 port)) (lst '()))
	      (cond ((or (eof-object? c) (not (char-numeric? c)))
		     (##sys#reverse-list->string lst) )
		    (else
		     (##sys#read-char-0 port)
		     (loop (##sys#peek-char-0 port) (cons c lst)) ) ) ) )

	  (define (r-symbol)
	    (r-xtoken
	     (lambda (str kw)
	       (let ((s (if kw (build-keyword str) (build-symbol str))))
		 (info 'symbol-info s (##sys#port-line port)) ) )))

	  (define (r-xtoken k)
	    (define pkw ; check for prefix keyword immediately
	      (and (eq? ksp #:prefix)
		   (eq? #\: (##sys#peek-char-0 port))
		   (begin (##sys#read-char-0 port) #t)))
	    (let loop ((lst '()) (skw #f) (qtd #f))
	      (let ((c (##sys#peek-char-0 port)))
		(cond ((or (eof-object? c)
			   (char-whitespace? c)
			   (memq c terminating-characters))
		       ;; The various cases here cover:
		       ;; - Nonempty keywords formed with colon in the ksp position
		       ;; - Empty keywords formed explicitly with vbar quotes
		       ;; - Bare colon, which should always be a symbol
		       (cond ((and skw (eq? ksp #:suffix) (or qtd (not (null? (cdr lst)))))
			      (k (##sys#reverse-list->string (cdr lst)) #t))
			     ((and pkw (or qtd (not (null? lst))))
			      (k (##sys#reverse-list->string lst) #t))
			     ((and pkw (not qtd) (null? lst))
			      (k ":" #f))
			     (else
			      (k (##sys#reverse-list->string lst) #f))))
		      ((memq c reserved-characters)
		       (reserved-character c))
		      (else
		       (let ((c (##sys#read-char-0 port)))
			 (case c
			   ((#\|)
			    (let ((part (r-string #\|)))
			      (loop (append (##sys#fast-reverse (##sys#string->list part)) lst)
				    #f #t)))
			   ((#\newline)
			    (##sys#read-warning
			     port "escaped symbol syntax spans multiple lines"
			     (##sys#reverse-list->string lst))
			    (loop (cons #\newline lst) #f qtd))
			   ((#\:)
			    (loop (cons #\: lst) #t qtd))
			   ((#\\)
			    (let ((c (##sys#read-char-0 port)))
			      (if (eof-object? c)
				  (##sys#read-error
				   port
				   "unexpected end of file while reading escaped character")
				  (loop (cons c lst) #f qtd))))
			   (else
			    (loop
			     (cons (if csp c (char-downcase c)) lst)
			     #f qtd)))))))))
	  
	  (define (r-char)
	    ;; Code contributed by Alex Shinn
	    (let* ([c (##sys#peek-char-0 port)]
		   [tk (r-token)]
		   [len (##sys#size tk)])
	      (cond [(fx> len 1)
		     (cond [(and (or (char=? #\x c) (char=? #\u c) (char=? #\U c))
				 (##sys#string->number (##sys#substring tk 1 len) 16) )
			    => (lambda (n) (integer->char n)) ]
			   [(and-let* ((c0 (char->integer (##core#inline "C_subchar" tk 0)))
				       ((fx<= #xC0 c0)) ((fx<= c0 #xF7))
				       (n0 (fxand (fxshr c0 4) 3))
				       (n (fx+ 2 (fxand (fxior n0 (fxshr n0 1)) (fx- n0 1))))
				       ((fx= len n))
				       (res (fx+ (fxshl (fxand c0 (fx- (fxshl 1 (fx- 8 n)) 1))
							6)
						 (fxand (char->integer 
							 (##core#inline "C_subchar" tk 1)) 
							#b111111))))
			      (cond ((fx>= n 3)
				     (set! res (fx+ (fxshl res 6)
						    (fxand 
						     (char->integer
						      (##core#inline "C_subchar" tk 2)) 
						     #b111111)))
				     (if (fx= n 4)
					 (set! res (fx+ (fxshl res 6)
							(fxand (char->integer
								(##core#inline "C_subchar" tk 3)) 
							       #b111111))))))
			      (integer->char res))]
			   [(char-name (##sys#intern-symbol tk))]
			   [else (##sys#read-error port "unknown named character" tk)] ) ]
		    [(memq c terminating-characters) (##sys#read-char-0 port)]
		    [else c] ) ) )

	  (define (r-comment)
	    (let loop ((i 0))
	      (let ((c (##sys#read-char-0 port)))
		(case c
		  ((#\|) (if (eq? #\# (##sys#read-char-0 port))
			     (if (not (eq? i 0))
				 (loop (fx- i 1)) )
			     (loop i) ) )
		  ((#\#) (loop (if (eq? #\| (##sys#read-char-0 port))
				   (fx+ i 1)
				   i) ) )
		  (else (if (eof-object? c)
			    (##sys#read-error port "unterminated block-comment")
			    (loop i) ) ) ) ) ) )

	  (define (r-ext-symbol)
	    (let ((tok (r-token)))
	      (build-symbol (string-append "##" tok))))

	  (define (r-quote q)
	    (let ((ln (##sys#port-line port)))
	      (info 'list-info (list q (readrec)) ln)))

	  (define (build-symbol tok)
	    (##sys#intern-symbol tok) )

	  (define (build-keyword tok)
	    (##sys#intern-keyword tok))

          ;; now have the state to make a decision.
          (set! reserved-characters
                (append (if (not psp) '(#\[ #\] #\{ #\}) '())
                        (if (not sep) '(#\|) '())))

	  (r-spaces)
	  (let* ((c (##sys#peek-char-0 port))
		 (srst (##sys#slot crt 1))
		 (h (and (not (eof-object? c)) srst
			 (##sys#slot srst (char->integer c)) ) ) )
	    (if h
                ;; then handled by read-table entry
		(##sys#call-with-values
		 (lambda () (h c port))
		 (lambda xs (if (null? xs) (readrec) (car xs))))
		;; otherwise chicken extended r5rs syntax
		(case c
		  ((#\')
		   (##sys#read-char-0 port)
		   (r-quote 'quote))
		  ((#\`)
		   (##sys#read-char-0 port)
		   (r-quote 'quasiquote))
		  ((#\,)
		   (##sys#read-char-0 port)
		   (cond ((eq? (##sys#peek-char-0 port) #\@)
			  (##sys#read-char-0 port)
			  (r-quote 'unquote-splicing))
			 (else (r-quote 'unquote))))
		  ((#\#)
		   (##sys#read-char-0 port)
		   (let ((dchar (##sys#peek-char-0 port)))
		     (cond
		      ((eof-object? dchar)
		       (##sys#read-error
			port "unexpected end of input after reading #-sign"))
		      ((char-numeric? dchar)
		       (let* ((n (string->number (r-digits)))
			      (dchar2 (##sys#peek-char-0 port))
			      (spdrst (##sys#slot crt 3))
			      (h (and (char? dchar2) spdrst
				      (##sys#slot spdrst (char->integer dchar2)) ) ) )
			 ;; #<num> handled by parameterized # read-table entry?
			 (cond ((eof-object? dchar2)
                                (##sys#read-error
                                 port "unexpected end of input after reading"
                                 c n))
                               (h (##sys#call-with-values
				   (lambda () (h dchar2 port n))
				   (lambda xs (if (null? xs) (readrec) (car xs)))))
                               ;; #<num>?
			       ((or (eq? dchar2 #\)) (char-whitespace? dchar2))
				(##sys#sharp-number-hook port n))
			       (else (##sys#read-char-0 port) ; Consume it first
				     (##sys#read-error
				      port
				      "invalid parameterized read syntax"
				      c n dchar2) ) ) ))
		      (else (let* ((sdrst (##sys#slot crt 2))
				   (h (and sdrst (##sys#slot sdrst (char->integer dchar)) ) ) )
			      (if h
                                  ;; then handled by # read-table entry
				  (##sys#call-with-values
				   (lambda () (h dchar port))
				   (lambda xs (if (null? xs) (readrec) (car xs))))
                                  ;; otherwise chicken extended r5rs syntax
				  (case (char-downcase dchar)
				    ((#\x) (##sys#read-char-0 port) (r-number-with-exactness 16))
				    ((#\d) (##sys#read-char-0 port) (r-number-with-exactness 10))
				    ((#\o) (##sys#read-char-0 port) (r-number-with-exactness 8))
				    ((#\b) (##sys#read-char-0 port) (r-number-with-exactness 2))
				    ((#\i) (##sys#read-char-0 port) (r-number-with-radix 'i))
				    ((#\e) (##sys#read-char-0 port) (r-number-with-radix 'e))
				    ((#\c)
				     (##sys#read-char-0 port)
				     (let ([c (##sys#read-char-0 port)])
				       (fluid-let ([csp
						    (cond [(eof-object? c)
							   (##sys#read-error port "unexpected end of input while reading `#c...' sequence")]
							  [(eq? c #\i) #f]
							  [(eq? c #\s) #t]
							  [else (##sys#read-error port "invalid case specifier in `#c...' sequence" c)] ) ] )
					 (readrec) ) ) )
				    ((#\() (r-vector))
				    ((#\\) (##sys#read-char-0 port) (r-char))
				    ((#\|)
				     (##sys#read-char-0 port)
				     (r-comment) (readrec) )
				    ((#\#)
				     (##sys#read-char-0 port)
				     (r-ext-symbol) )
				    ((#\;)
				     (##sys#read-char-0 port)
				     (readrec) (readrec) )
				    ((#\`)
				     (##sys#read-char-0 port)
				     (r-quote 'quasisyntax))
				    ((#\$)
				     (##sys#read-char-0 port)
				     (let ((c (##sys#peek-char-0 port)))
				       (cond ((char=? c #\{)
					      (##sys#read-char-0 port)
					      (##sys#read-bytevector-literal port))
					     (else
					      ;; HACK: reuse r-quote to add line number info
					      (r-quote 'location)))))
				    ((#\:)
				     (##sys#read-char-0 port)
				     (let ((c (##sys#peek-char-0 port)))
				       (fluid-let ((ksp #f))
					 (r-xtoken
					  (lambda (str kw)
					    (if (and (eq? 0 (##sys#size str))
						     (not (char=? c #\|)))
						(##sys#read-error port "empty keyword")
						(build-keyword str)))))))
				    ((#\+)
				     (##sys#read-char-0 port)
				     (let* ((ln (##sys#port-line port))
					    (tst (readrec)))
				       (info 'list-info
					     (list 'cond-expand (list tst (readrec)) '(else))
					     ln)))
				    ((#\!)
				     (##sys#read-char-0 port)
				     (let ((c (##sys#peek-char-0 port)))
				       (cond ((and (char? c)
						   (or (char-whitespace? c) (char=? #\/ c)))
					      (skip-to-eol)
					      (readrec) )
					     (else
					      (let ([tok (r-token)])
						(cond [(string=? "eof" tok) #!eof]
						      ;; TODO: use #!bwp when we have a bootstrapping compiler whose reader supports it
						      [(string=? "bwp" tok) (foreign-value "C_SCHEME_BROKEN_WEAK_PTR" scheme-object)]
						      [(member tok '("optional" "rest" "key"))
						       (build-symbol (##sys#string-append "#!" tok)) ]
						      [else
						       (let ((a (assq (string->symbol tok) ##sys#read-marks)))
							 (if a
							     ((##sys#slot a 1) port)
							     (##sys#read-error
							      port
							      "invalid `#!' token" tok) ) ) ] ) ) ) ) ) )
				    (else
				     (##sys#call-with-values (lambda () (##sys#user-read-hook dchar port))
							     (lambda xs (if (null? xs) (readrec) (car xs)))) ) ) ) )) ) ) )
		  ((#\() (r-list #\( #\)))
		  ((#\)) (##sys#read-char-0 port) (container c))
		  ((#\") (##sys#read-char-0 port) (r-string #\"))
		  ((#\.) (r-number #f #f))
		  ((#\- #\+) (r-number #f #f))
		  (else
		   (cond [(eof-object? c) c]
			 [(char-numeric? c) (r-number #f #f)]
			 ((memq c reserved-characters)
			  (reserved-character c))
			 (else
			  (case c
			    ((#\[) (r-list #\[ #\]))
			    ((#\{) (r-list #\{ #\}))
			    ((#\] #\}) (##sys#read-char-0 port) (container c))
			    (else (r-symbol) ) ) ) ) ) ) ) ) )
	
	(readrec) ) ) ) )


;;; This is taken from Alex Shinn's UTF8 egg:

(define (##sys#char->utf8-string c)
  (let ([i (char->integer c)])
    (cond [(fx<= i #x7F)
           (string c) ]
          [(fx<= i #x7FF)
           (string (integer->char (fxior #b11000000 (fxshr i 6)))
	           (integer->char (fxior #b10000000 (fxand i #b111111)))) ]
          [(fx<= i #xFFFF)
           (string (integer->char (fxior #b11100000 (fxshr i 12)))
	           (integer->char (fxior #b10000000 (fxand (fxshr i 6) #b111111)))
	           (integer->char (fxior #b10000000 (fxand i #b111111)))) ]
          [(fx<= i #x1FFFFF)
           (string (integer->char (fxior #b11110000 (fxshr i 18)))
	           (integer->char (fxior #b10000000 (fxand (fxshr i 12) #b111111)))
	           (integer->char (fxior #b10000000 (fxand (fxshr i 6) #b111111)))
	           (integer->char (fxior #b10000000 (fxand i #b111111)))) ]
          [else
           (error "UTF-8 codepoint out of range:" i) ] ) ) )

(define (##sys#unicode-surrogate? n)
  (and (fx<= #xD800 n) (fx<= n #xDFFF)) )

;; returns #f if the inputs are not a valid surrogate pair (hi followed by lo)
(define (##sys#surrogates->codepoint hi lo)
  (and (fx<= #xD800 hi) (fx<= hi #xDBFF)
       (fx<= #xDC00 lo) (fx<= lo #xDFFF)
       (fxior (fxshl (fx+ 1 (fxand (fxshr hi 6) #b11111)) 16)
	      (fxior (fxshl (fxand hi #b111111) 10)
		     (fxand lo #b1111111111)))) )

(define (##sys#read-bytevector-literal port)
  (define (hex c)
    (let ((c (char-downcase c)))
      (cond ((and (char>=? c #\a) (char<=? c #\f))
	     (fx- (char->integer c) 87)	) ; - #\a + 10
	    ((and (char>=? c #\0) (char<=? c #\9))
	     (fx- (char->integer c) 48))
	    (else (##sys#read-error port "invalid hex-code in blob-literal")))))
  (let loop ((lst '()) (h #f))
    (let ((c (##sys#read-char-0 port)))
      (cond ((eof-object? c)
	     (##sys#read-error port "unexpected end of blob literal"))
	    ((char=? #\} c)
	     (let ((str (##sys#reverse-list->string
			 (if h
			     (cons (integer->char (fxshr h 4)) lst)
			     lst))))
	       (##core#inline "C_string_to_bytevector" str)
	       str))
	    ((char-whitespace? c) 
	     (if h
		 (loop (cons (integer->char (fxshr h 4)) lst) #f)
		 (loop lst h)))
	    (h (loop (cons (integer->char (fxior h (hex c))) lst) #f))
	    (else (loop lst (fxshl (hex c) 4)))))))


;;; Hooks for user-defined read-syntax:
;
; - Redefine this to handle new read-syntaxes. If 'char' doesn't match
;   your character then call the previous handler.
; - Don't forget to read 'char', it's only peeked at this point.

(define (##sys#user-read-hook char port)
  (case char
    ;; I put it here, so the SRFI-4 unit can intercept '#f...'
    ((#\f #\F) (##sys#read-char-0 port) #f)
    ((#\t #\T) (##sys#read-char-0 port) #t)
    (else (##sys#read-error port "invalid sharp-sign read syntax" char) ) ) )


;;; Table for specially-handled read-syntax:
;
; - entries should be #f or a 256-element vector containing procedures
; - each procedure is called with two arguments, a char (peeked) and a
;   port, and should return an expression

(define ##sys#read-marks '()) ; TODO move to read-syntax module


;;; Output:

(define (##sys#write-char-0 c p)
  ((##sys#slot (##sys#slot p 2) 2) p c) 
  (##sys#void))

(define (##sys#write-char/port c port)
  (##sys#check-output-port port #t 'write-char)
  (##sys#check-char c 'write-char)
  (##sys#write-char-0 c port) )

(set! scheme#write-char
  (lambda (c #!optional (port ##sys#standard-output))
    (##sys#check-char c 'write-char)
    (##sys#check-output-port port #t 'write-char)
    (##sys#write-char-0 c port) ))

(set! scheme#newline
  (lambda (#!optional (port ##sys#standard-output))
    (##sys#write-char/port #\newline port) ))

(set! scheme#write
  (lambda (x #!optional (port ##sys#standard-output))
    (##sys#check-output-port port #t 'write)
    (##sys#print x #t port) ))

(set! scheme#display
  (lambda (x #!optional (port ##sys#standard-output))
    (##sys#check-output-port port #t 'display)
    (##sys#print x #f port) ))

(define-inline (*print-each lst)
  (for-each (cut ##sys#print <> #f ##sys#standard-output) lst) )
 
(set! chicken.base#print
  (lambda args
    (##sys#check-output-port ##sys#standard-output #t 'print)
    (*print-each args)
    (##sys#write-char-0 #\newline ##sys#standard-output)
    (void)))

(set! chicken.base#print*
  (lambda args
    (##sys#check-output-port ##sys#standard-output #t 'print)
    (*print-each args)
    (##sys#flush-output ##sys#standard-output)
    (void)))

(define current-print-length (make-parameter 0))
(define ##sys#print-length-limit (make-parameter #f))
(define ##sys#print-exit (make-parameter #f))

(define ##sys#print
  (let ((case-sensitive case-sensitive)
	(keyword-style keyword-style))
    (lambda (x readable port)
      (##sys#check-output-port port #t #f)
      (let ([csp (case-sensitive)]
	    [ksp (keyword-style)]
	    [length-limit (##sys#print-length-limit)]
	    [special-characters '(#\( #\) #\, #\[ #\] #\{ #\} #\' #\" #\; #\ #\` #\| #\\)] )

	(define (outstr port str)
	  (if length-limit
	      (let* ((len (##sys#size str))
		     (cpp0 (current-print-length))
		     (cpl (fx+ cpp0 len)) )
		(if (fx> cpl length-limit)
		    (let ((n (fx- length-limit cpp0)))
		      (when (fx> n 0) (outstr0 port (##sys#substring str 0 n)))
		      (outstr0 port "...")
		      ((##sys#print-exit) (##sys#void)))
		    (outstr0 port str) )
		(current-print-length cpl) )
	      (outstr0 port str) ) )
	       
	(define (outstr0 port str)
	  ((##sys#slot (##sys#slot port 2) 3) port str) )

	(define (outchr port chr)
	  (when length-limit
	    (let ((cpp0 (current-print-length)))
	      (current-print-length (fx+ cpp0 1))
	      (when (fx>= cpp0 length-limit)
		(outstr0 port "...")
		((##sys#print-exit) (##sys#void)))))
	  ((##sys#slot (##sys#slot port 2) 2) port chr))

	(define (specialchar? chr)
	  (let ([c (char->integer chr)])
	    (or (fx<= c 32)
		(memq chr special-characters) ) ) )

	(define (outsym port sym)
	  (let ((str (##sys#symbol->string sym)))
	    (if (or (not readable) (sym-is-readable? str))
		(outstr port str)
		(outreadablesym port str))))

	(define (outreadablesym port str)
	  (let ((len (##sys#size str)))
	    (outchr port #\|)
	    (let loop ((i 0))
	      (if (fx>= i len)
		  (outchr port #\|)
		  (let ((c (##core#inline "C_subchar" str i)))
		    (cond ((or (char<? c #\space) (char>? c #\~))
			   (outstr port "\\x")
			   (let ((n (char->integer c)))
			     (when (fx< n 16) (outchr port #\0))
			     (outstr port (##sys#number->string n 16))
			     (loop (fx+ i 1))))
			  (else
			   (when (or (eq? c #\|) (eq? c #\\)) (outchr port #\\))
			   (outchr port c)
			   (loop (fx+ i 1)) ) ) ) ) )))

	(define (sym-is-readable? str)
	  (let ((len (##sys#size str)))
	    (cond ((eq? len 0) #f)
		  ((eq? len 1)
		   (let ((c (##core#inline "C_subchar" str 0)))
		     (cond ((or (eq? #\# c) (eq? #\. c)) #f)
			   ((specialchar? c) #f)
			   ((char-numeric? c) #f)
			   (else #t))))
		  (else
		   (let loop ((i (fx- len 1)))
		     (if (eq? i 0)
			 (let ((c (##core#inline "C_subchar" str 0)))
			   (cond ((or (char-numeric? c)
				      (eq? c #\+)
				      (eq? c #\.)
				      (eq? c #\-) )
				  (not (##sys#string->number str)) )
				 ((eq? c #\:) #f)
				 ((and (eq? c #\#)
				       ;; Not a qualified symbol?
				       (not (and (fx> len 2)
						 (eq? (##core#inline "C_subchar" str 1) #\#)
						 (not (eq? (##core#inline "C_subchar" str 2) #\#)))))
				  (member str '("#!rest" "#!key" "#!optional")))
				 ((specialchar? c) #f)
				 (else #t) ) )
			 (let ((c (##core#inline "C_subchar" str i)))
			   (and (or csp (not (char-upper-case? c)))
				(not (specialchar? c))
				(or (not (eq? c #\:))
				    (fx< i (fx- len 1)))
				(loop (fx- i 1)) ) ) ) ) ) ) ) )

	(let out ([x x])
	  (cond ((eq? x '()) (outstr port "()"))
		((eq? x #t) (outstr port "#t"))
		((eq? x #f) (outstr port "#f"))
		((##core#inline "C_eofp" x) (outstr port "#!eof"))
		((##core#inline "C_undefinedp" x) (outstr port "#<unspecified>"))
		((##core#inline "C_bwpp" x) (outstr port "#!bwp"))
		((##core#inline "C_charp" x)
		 (cond [readable
			(outstr port "#\\")
			(let ([code (char->integer x)])
			  (cond [(char-name x) 
				 => (lambda (cn) 
				      (outstr port (##sys#slot cn 1)) ) ]
				[(or (fx< code 32) (fx> code 255))
				 (outchr port #\x)
				 (outstr port (##sys#number->string code 16)) ]
				[else (outchr port x)] ) ) ] 
		       [else (outchr port x)] ) )
		((##core#inline "C_fixnump" x) (outstr port (##sys#number->string x)))
		((##core#inline "C_unboundvaluep" x) (outstr port "#<unbound value>"))
		((not (##core#inline "C_blockp" x)) (outstr port "#<invalid immediate object>"))
		((##core#inline "C_forwardedp" x) (outstr port "#<invalid forwarded object>"))
		((##core#inline "C_i_keywordp" x)
                 ;; Force portable #: style for readable output
		 (case (and (not readable) ksp)
                   ((#:prefix)
                    (outchr port #\:)
                    (outsym port x))
                   ((#:suffix)
                    (outsym port x)
                    (outchr port #\:))
                   (else
                    (outstr port "#:")
                    (outsym port x))))
		((##core#inline "C_i_symbolp" x) (outsym port x))
		((##sys#number? x) (outstr port (##sys#number->string x)))
		((##core#inline "C_anypointerp" x) (outstr port (##sys#pointer->string x)))
		((##core#inline "C_stringp" x)
		 (cond (readable
			(outchr port #\")
			(do ((i 0 (fx+ i 1))
			     (c (##core#inline "C_block_size" x) (fx- c 1)) )
			    ((eq? c 0)
			     (outchr port #\") )
			  (let ((chr (##core#inline "C_subbyte" x i)))
			    (case chr
			      ((34) (outstr port "\\\""))
			      ((92) (outstr port "\\\\"))
			      (else
			       (cond ((or (fx< chr 32)
					  (fx= chr 127))
				      (outchr port #\\)
				      (case chr
                                        ((7) (outchr port #\a))
					((8) (outchr port #\b))
					((9) (outchr port #\t))
					((10) (outchr port #\n))
					((11) (outchr port #\v))
					((12) (outchr port #\f))
					((13) (outchr port #\r))
					(else
					 (outchr port #\x)
					 (when (fx< chr 16) (outchr port #\0))
					 (outstr port (##sys#number->string chr 16)) ) ) )
				     (else (outchr port (##core#inline "C_fix_to_char" chr)) ) ) ) ) ) ) )
		       (else (outstr port x)) ) )
		((##core#inline "C_pairp" x)
		 (outchr port #\()
		 (out (##sys#slot x 0))
		 (do ((x (##sys#slot x 1) (##sys#slot x 1)))
		     ((or (not (##core#inline "C_blockp" x)) (not (##core#inline "C_pairp" x)))
		      (if (not (eq? x '()))
			  (begin
			    (outstr port " . ")
			    (out x) ) )
		      (outchr port #\)) )
		   (outchr port #\space)
		   (out (##sys#slot x 0)) ) )
		((##core#inline "C_bytevectorp" x)
		 (outstr port "#${")
		 (let ((len (##sys#size x)))
		   (do ((i 0 (fx+ i 1)))
		       ((fx>= i len))
		     (let ((b (##sys#byte x i)))
		       (when (fx< b 16)
			 (outchr port #\0))
		       (outstr port (##sys#number->string b 16)))))
		 (outchr port #\}) )
		((##core#inline "C_structurep" x) (##sys#user-print-hook x readable port))
		((##core#inline "C_closurep" x) (outstr port (##sys#procedure->string x)))
		((##core#inline "C_locativep" x) (outstr port "#<locative>"))
		((##core#inline "C_lambdainfop" x)
		 (outstr port "#<lambda info ")
		 (outstr port (##sys#lambda-info->string x))
		 (outchr port #\>) )
		((##core#inline "C_portp" x)
		 (case (##sys#slot x 1)
		   ((1)  (outstr port "#<input port \""))
		   ((2)  (outstr port "#<output port \""))
		   (else (outstr port "#<port \"")))
		 (outstr port (##sys#slot x 3))
		 (outstr port "\">") )
		((##core#inline "C_vectorp" x)
		 (let ((n (##core#inline "C_block_size" x)))
		   (cond ((eq? 0 n)
			  (outstr port "#()") )
			 (else
			  (outstr port "#(")
			  (out (##sys#slot x 0))
			  (do ((i 1 (fx+ i 1))
			       (c (fx- n 1) (fx- c 1)) )
			      ((eq? c 0)
			       (outchr port #\)) )
			    (outchr port #\space)
			    (out (##sys#slot x i)) ) ) ) ) )
		(else (##sys#error "unprintable block object encountered")))))
      (##sys#void))))

(define ##sys#procedure->string 
  (let ((string-append string-append))
    (lambda (x)
      (let ((info (##sys#lambda-info x)))
	(if info
	    (string-append "#<procedure " (##sys#lambda-info->string info) ">")
	    "#<procedure>") ) ) ) )

(define ##sys#record-printers '())

(set! chicken.base#record-printer
  (lambda (type)
    (##sys#check-symbol type 'record-printer)
    (let ((a (assq type ##sys#record-printers)))
      (and a (cdr a)))))

(set! chicken.base#set-record-printer!
  (lambda (type proc)
    (##sys#check-symbol type 'set-record-printer!)
    (##sys#check-closure proc 'set-record-printer!)
    (let ((a (assq type ##sys#record-printers)))
      (if a
	  (##sys#setslot a 1 proc)
	  (set! ##sys#record-printers (cons (cons type proc) ##sys#record-printers)))
      (##core#undefined))))

;; OBSOLETE can be removed after bootstrapping
(set! ##sys#register-record-printer chicken.base#set-record-printer!)

(set! chicken.base#record-printer
  (getter-with-setter record-printer set-record-printer!))

(define (##sys#user-print-hook x readable port)
  (let* ((type (##sys#slot x 0))
	 (a (assq type ##sys#record-printers)) )
    (cond (a (handle-exceptions ex
		(begin
		  (##sys#print "#<Error in printer of record type `" #f port)
		  (##sys#print (##sys#symbol->string type) #f port)
		  (if (##sys#structure? ex 'condition)
		      (and-let* ((a (member '(exn . message) (##sys#slot ex 2))))
			(##sys#print "': " #f port)
			(##sys#print (cadr a) #f port)
			(##sys#write-char-0 #\> port))
		      (##sys#print "'>" #f port)))
	       ((##sys#slot a 1) x port)))
	  (else
	   (##sys#print "#<" #f port)
	   (##sys#print (##sys#symbol->string type) #f port)
	   (case type
	     ((condition)
	      (##sys#print ": " #f port)
	      (##sys#print (##sys#slot x 1) #f port) )
	     ((thread)
	      (##sys#print ": " #f port)
	      (##sys#print (##sys#slot x 6) #f port) ) )
	   (##sys#write-char-0 #\> port) ) ) ) )

(define ##sys#with-print-length-limit
  (let ([call-with-current-continuation call-with-current-continuation])
    (lambda (limit thunk)
      (call-with-current-continuation
       (lambda (return)
	 (parameterize ((##sys#print-length-limit limit)
			(##sys#print-exit return)
			(current-print-length 0))
	   (thunk)))))))


;;; String ports:
;
; - Port-slots:
;
;   Input:
;
;   10: position
;   11: len
;   12: string
;
;   Output:
;
;   10: position
;   11: limit
;   12: output

(define ##sys#string-port-class
  (letrec ([check 
	    (lambda (p n)
	      (let* ([position (##sys#slot p 10)]
		     [limit (##sys#slot p 11)] 
		     [output (##sys#slot p 12)]
		     [limit2 (fx+ position n)] )
		(when (fx>= limit2 limit)
		  (when (fx>= limit2 maximal-string-length)
		    (##sys#error "string buffer full" p) )
		  (let* ([limit3 (fxmin maximal-string-length (fx+ limit limit))]
			 [buf (##sys#make-string limit3)] )
		    (##sys#copy-bytes output buf 0 0 position)
		    (##sys#setslot p 12 buf)
		    (##sys#setislot p 11 limit3)
		    (check p n) ) ) ) ) ] )
    (vector
     (lambda (p)			; read-char
       (let ([position (##sys#slot p 10)]
	     [string (##sys#slot p 12)]
	     [len (##sys#slot p 11)] )
	 (if (fx>= position len)
	     #!eof
	     (let ((c (##core#inline "C_subchar" string position)))
	       (##sys#setislot p 10 (fx+ position 1))
	       c) ) ) )
     (lambda (p)			; peek-char
       (let ([position (##sys#slot p 10)]
	     [string (##sys#slot p 12)]
	     [len (##sys#slot p 11)] )
	 (if (fx>= position len)
	     #!eof
	     (##core#inline "C_subchar" string position) ) ) )
     (lambda (p c)			; write-char
       (check p 1)	
       (let ([position (##sys#slot p 10)]
	     [output (##sys#slot p 12)] )
	 (##core#inline "C_setsubchar" output position c)
	 (##sys#setislot p 10 (fx+ position 1)) ) )
     (lambda (p str)			; write-string
       (let ([len (##core#inline "C_block_size" str)])
	 (check p len)
	 (let ([position (##sys#slot p 10)]
	       [output (##sys#slot p 12)] )
	   (##core#inline "C_substring_copy" str output 0 len position)
	   (##sys#setislot p 10 (fx+ position len)) ) ) )
     void ; close
     (lambda (p) #f)			; flush-output
     (lambda (p) #t)			; char-ready?
     (lambda (p n dest start)		; read-string!
       (let* ((pos (##sys#slot p 10))
	      (n2 (fx- (##sys#slot p 11) pos) ) )
	 (when (or (not n) (fx> n n2)) (set! n n2))
	 (##core#inline "C_substring_copy" (##sys#slot p 12) dest pos (fx+ pos n) start)
	 (##sys#setislot p 10 (fx+ pos n))
	 n))
     (lambda (p limit)			; read-line
       (let* ((pos (##sys#slot p 10))
	      (size (##sys#slot p 11)) 
	      (buf (##sys#slot p 12)) 
	      (end (if limit (fx+ pos limit) size)))
	 (if (fx>= pos size)
	     #!eof
	     (receive (next line full-line?)
		 (##sys#scan-buffer-line
		  buf (if (fx> end size) size end) pos
		  (lambda (pos) (values #f pos #f) ) )
	       ;; Update row & column position
	       (if full-line?
		   (begin
		     (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
		     (##sys#setislot p 5 0))
		   (##sys#setislot p 5 (fx+ (##sys#slot p 5) (##sys#size line))))
	       (##sys#setislot p 10 next)
	       line) ) ) )
     (lambda (p)			; read-buffered
       (let ((pos (##sys#slot p 10))
	     (string (##sys#slot p 12))
	     (len (##sys#slot p 11)) )
	 (if (fx>= pos len)
	     ""
	     (let ((buffered (##sys#substring string pos len)))
	       (##sys#setislot p 10 len)
	       buffered))))
     )))

;; Invokes the eos handler when EOS is reached to get more data.
;; The eos-handler is responsible for stopping, either when EOF is hit or
;; a user-supplied limit is reached (ie, it's indistinguishable from EOF)
(define (##sys#scan-buffer-line buf limit start-pos eos-handler)
  (define (copy&append buf offset pos old-line)
    (let* ((old-line-len (##sys#size old-line))
	   (new-line (##sys#make-string (fx+ old-line-len (fx- pos offset)))))
      (##core#inline "C_substring_copy" old-line new-line 0 old-line-len 0)
      (##core#inline "C_substring_copy" buf new-line offset pos old-line-len)
      new-line))
  (let loop ((buf buf)
	     (offset start-pos)
	     (pos start-pos)
	     (limit limit)
	     (line ""))
    (if (fx= pos limit)
	(let ((line (copy&append buf offset pos line)))
	  (receive (buf offset limit) (eos-handler pos)
	    (if buf
		(loop buf offset offset limit line)
		(values offset line #f))))
	(let ((c (##core#inline "C_subchar" buf pos)))
	  (cond ((eq? c #\newline)
		 (values (fx+ pos 1) (copy&append buf offset pos line) #t))
		((and (eq? c #\return)	; \r\n -> drop \r from string
		      (fx> limit (fx+ pos 1))
		      (eq? (##core#inline "C_subchar" buf (fx+ pos 1)) #\newline))
		 (values (fx+ pos 2) (copy&append buf offset pos line) #t))
		((and (eq? c #\return)	; Edge case (#568): \r{read}[\n|xyz]
		      (fx= limit (fx+ pos 1)))
		 (let ((line (copy&append buf offset pos line)))
		   (receive (buf offset limit) (eos-handler pos)
		     (if buf
			 (if (eq? (##core#inline "C_subchar" buf offset) #\newline)
			     (values (fx+ offset 1) line #t)
			     ;; "Restore" \r we didn't copy, loop w/ new string
			     (loop buf offset offset limit
				   (##sys#string-append line "\r")))
			 ;; Restore \r here, too (when we reached EOF)
			 (values offset (##sys#string-append line "\r") #t)))))
		((eq? c #\return)
		 (values (fx+ pos 1) (copy&append buf offset pos line) #t))
		(else (loop buf offset (fx+ pos 1) limit line)) ) ) ) ) )

(set! chicken.base#open-input-string
  (lambda (string)
    (##sys#check-string string 'open-input-string)
    (let ((port (##sys#make-port 1 ##sys#string-port-class "(string)" 'string)))
      (##sys#setislot port 11 (##core#inline "C_block_size" string))
      (##sys#setislot port 10 0)
      (##sys#setslot port 12 string)
      port)))

(set! chicken.base#open-output-string
  (lambda ()
    (let ((port (##sys#make-port 2 ##sys#string-port-class "(string)" 'string)))
      (##sys#setislot port 10 0)
      (##sys#setislot port 11 output-string-initial-size)
      (##sys#setslot port 12 (##sys#make-string output-string-initial-size))
      port)))

(set! chicken.base#get-output-string
  (lambda (port)
    (##sys#check-output-port port #f 'get-output-string)
    (if (not (eq? 'string (##sys#slot port 7)))
        (##sys#signal-hook
         #:type-error 'get-output-string "argument is not a string-output-port" port)
        (##sys#substring (##sys#slot port 12) 0 (##sys#slot port 10)))))

(define ##sys#print-to-string
  (let ([get-output-string get-output-string]
	[open-output-string open-output-string] )
    (lambda (xs)
      (let ([out (open-output-string)])
	(for-each (lambda (x) (##sys#print x #f out)) xs)
	(get-output-string out) ) ) ) )

(define ##sys#pointer->string
  (let ((string-append string-append))
    (lambda (x)
      (if (##core#inline "C_taggedpointerp" x)
	  (string-append
	   "#<tagged pointer "
	   (##sys#print-to-string
	    (let ((tag (##sys#slot x 1)))
	      (list (if (pair? tag) (car tag) tag) ) ) )
	   " "
	   (##sys#number->string (##sys#pointer->address x) 16)
	   ">")
	  (string-append "#<pointer 0x" (##sys#number->string (##sys#pointer->address x) 16) ">") ) ) ) )


;;; Access backtrace:

(define-constant +trace-buffer-entry-slot-count+ 5)

(set! chicken.base#get-call-chain
  (let ((extract
	 (foreign-lambda* nonnull-c-string ((scheme-object x)) "C_return((C_char *)x);")))
    (lambda (#!optional (start 0) (thread ##sys#current-thread))
      (let* ((tbl (foreign-value "C_trace_buffer_size" int))
	     ;; 5 slots: "raw" location (for compiled code), "cooked" location (for interpreted code), cooked1, cooked2, thread
	     (c +trace-buffer-entry-slot-count+)
	     (vec (##sys#make-vector (fx* c tbl) #f))
	     (r (##core#inline "C_fetch_trace" start vec))
	     (n (if (fixnum? r) r (fx* c tbl)))
             (t-id (and thread (##sys#slot thread 14))))
	(let loop ((i 0))
	  (if (fx>= i n)
	      '()
	      (let ((t (##sys#slot vec (fx+ i 4)))) ; thread id
		(if (or (not t) (not thread) (eq? t-id t))
		    (cons (vector
			   (or (##sys#slot vec (fx+ i 1)) ; cooked_location
			       (extract (##sys#slot vec i))) ; raw_location
			   (##sys#slot vec (fx+ i 2))   ; cooked1
			   (##sys#slot vec (fx+ i 3)))  ; cooked2
			  (loop (fx+ i c)))
		    (loop (fx+ i c))))))))))

(define (##sys#really-print-call-chain port chain header)
  (when (pair? chain)
    (##sys#print header #f port)
    (for-each
     (lambda (info)
       (let* ((more1 (##sys#slot info 1)) ; cooked1 (expr/form)
	      (more2 (##sys#slot info 2)) ; cooked2 (cntr/frameinfo)
	      (fi (##sys#structure? more2 'frameinfo)))
	 (##sys#print "\n\t" #f port)
	 (##sys#print (##sys#slot info 0) #f port) ; raw (mode)
	 (##sys#print "\t  " #f port)
	 (when (and more2 (if fi (##sys#slot more2 1)))
	   (##sys#write-char-0 #\[ port)
	   (##sys#print
	    (if fi
		(##sys#slot more2 1)	; cntr
		more2)
	    #f port)
	   (##sys#print "] " #f port))
	 (when more1
	   (##sys#with-print-length-limit
	    100
	    (lambda ()
	      (##sys#print more1 #t port))))))
     chain)
    (##sys#print "\t<--\n" #f port)))

(set! chicken.base#print-call-chain
  (lambda (#!optional (port ##sys#standard-output) (start 0)
		      (thread ##sys#current-thread)
		      (header "\n\tCall history:\n"))
    (##sys#check-output-port port #t 'print-call-chain)
    (##sys#check-fixnum start 'print-call-chain)
    (##sys#check-string header 'print-call-chain)
    (##sys#really-print-call-chain port (get-call-chain start thread) header)))


;;; Interrupt handling:

(define (##sys#user-interrupt-hook)
  (define (break) (##sys#signal-hook #:user-interrupt #f))
  (if (eq? ##sys#current-thread ##sys#primordial-thread)
      (break)
      (##sys#setslot ##sys#primordial-thread 1 break) ) )


;;; Default handlers

(define-foreign-variable _ex_software int "EX_SOFTWARE")

(define exit-in-progress #f)

(define (cleanup-before-exit)
  (set! exit-in-progress #t)
  (when (##core#inline "C_i_dump_heap_on_exitp")
    (##sys#print "\n" #f ##sys#standard-error)
    (##sys#dump-heap-state))
  (when (##core#inline "C_i_profilingp")
    (##core#inline "C_i_dump_statistical_profile"))
  (let loop ()
    (let ((tasks chicken.base#cleanup-tasks))
      (set! chicken.base#cleanup-tasks '())
      (unless (null? tasks)
	(for-each (lambda (t) (t)) tasks)
	(loop))))
  (when (fx> (##sys#slot ##sys#pending-finalizers 0) 0)
    (##sys#run-pending-finalizers #f))
  (when (fx> (##core#inline "C_i_live_finalizer_count") 0)
    (when (##sys#debug-mode?)
      (##sys#print "[debug] forcing finalizers...\n" #f ##sys#standard-error))
    (when (chicken.gc#force-finalizers)
      (##sys#force-finalizers))))

(set! chicken.base#exit-handler
  (make-parameter
   (lambda (#!optional (code 0))
     (##sys#check-fixnum code)
     (cond (exit-in-progress
	    (##sys#warn "\"exit\" called while processing on-exit tasks"))
	   (else
	    (cleanup-before-exit)
	    (##core#inline "C_exit_runtime" code))))))

(set! chicken.base#implicit-exit-handler
  (make-parameter
   (lambda ()
     (cleanup-before-exit))))

(define ##sys#reset-handler ; Exposed by chicken.repl
  (make-parameter
   (lambda ()
     ((exit-handler) _ex_software))))


;;; Condition handling:

(module chicken.condition
    ;; NOTE: We don't emit the import lib.  Due to syntax exports, it
    ;; has to be a hardcoded primitive module.
    (abort signal current-exception-handler
     print-error-message with-exception-handler

     ;; [syntax] condition-case handle-exceptions

     ;; Condition object manipulation
     make-property-condition make-composite-condition
     condition condition? condition->list condition-predicate
     condition-property-accessor get-condition-property)

(import scheme chicken.base chicken.fixnum chicken.foreign)
(import chicken.internal.syntax)

(define (##sys#signal-hook/errno mode errno msg . args)
  (##core#inline "C_dbg_hook" #f)
  (##core#inline "signal_debug_event" mode msg args)
  (case mode
    [(#:user-interrupt)
     (abort
      (##sys#make-structure
       'condition
       '(user-interrupt)
       '() ) ) ]
    [(#:warning #:notice)
     (##sys#print
      (if (eq? mode #:warning) "\nWarning: " "\nNote: ")
      #f ##sys#standard-error)
     (##sys#print msg #f ##sys#standard-error)
     (if (or (null? args) (fx> (length args) 1))
	 (##sys#write-char-0 #\newline ##sys#standard-error)
	 (##sys#print ": " #f ##sys#standard-error))
     (for-each
      (lambda (x)
	(##sys#with-print-length-limit
	 400
	 (lambda ()
	   (##sys#print x #t ##sys#standard-error)
	   (##sys#write-char-0 #\newline ##sys#standard-error))))
      args)
     (##sys#flush-output ##sys#standard-error)]
    (else
     (when (and (symbol? msg) (null? args))
       (set! msg (symbol->string msg)))
     (let* ([hasloc (and (or (not msg) (symbol? msg)) (pair? args))]
	    [loc (and hasloc msg)]
	    [msg (if hasloc (##sys#slot args 0) msg)]
	    [args (if hasloc (##sys#slot args 1) args)] )
       (abort
	(##sys#make-structure
	 'condition 
	 (case mode
	   [(#:type-error)		'(exn type)]
	   [(#:syntax-error)		'(exn syntax)]
	   [(#:bounds-error)		'(exn bounds)]
	   [(#:arithmetic-error)	'(exn arithmetic)]
	   [(#:file-error)		'(exn i/o file)]
	   [(#:runtime-error)		'(exn runtime)]
	   [(#:process-error)		'(exn process)]
	   [(#:network-error)		'(exn i/o net)]
	   [(#:network-timeout-error)   '(exn i/o net timeout)]
	   [(#:limit-error)		'(exn runtime limit)]
	   [(#:arity-error)		'(exn arity)]
	   [(#:access-error)		'(exn access)]
	   [(#:domain-error)		'(exn domain)]
	   ((#:memory-error)            '(exn memory))
	   [else			'(exn)] )
         (let ((props
                (list '(exn . message) msg
                      '(exn . arguments) args
                      '(exn . call-chain) (get-call-chain)
                      '(exn . location) loc)))
           (if errno
               (cons '(exn . errno) (cons errno props))
               props))))))))

(define (##sys#signal-hook mode msg . args)
  (if (pair? args)
      (apply ##sys#signal-hook/errno mode #f msg args)
      (##sys#signal-hook/errno mode #f msg)))

(define (abort x)
  (##sys#current-exception-handler x)
  (abort
   (##sys#make-structure
    'condition
    '(exn) 
    (list '(exn . message) "exception handler returned"
	  '(exn . arguments) '()
	  '(exn . location) #f) ) ) )

(define (signal x)
  (##sys#current-exception-handler x) )

(define ##sys#error-handler
  (make-parameter
   (let ([string-append string-append])
     (lambda (msg . args)
       (##sys#error-handler (lambda args (##core#inline "C_halt" "error in error")))
       (cond ((not (foreign-value "C_gui_mode" bool))
	      (##sys#print "\nError" #f ##sys#standard-error)
	      (when msg
		(##sys#print ": " #f ##sys#standard-error)
		(##sys#print msg #f ##sys#standard-error))
	      (##sys#with-print-length-limit
	       400
	       (lambda ()
		 (cond [(fx= 1 (length args))
			(##sys#print ": " #f ##sys#standard-error)
			(##sys#print (##sys#slot args 0) #t ##sys#standard-error)]
		       [else
			(##sys#for-each
			 (lambda (x)
			   (##sys#print #\newline #f ##sys#standard-error)
			   (##sys#print x #t ##sys#standard-error))
			 args)])))
	      (##sys#print #\newline #f ##sys#standard-error)
	      (print-call-chain ##sys#standard-error)
	      (##core#inline "C_halt" #f))
	     (else
	      (let ((out (open-output-string)))
		(when msg (##sys#print msg #f out))
		(##sys#print #\newline #f out)
		(##sys#for-each (lambda (x) (##sys#print x #t out) (##sys#print #\newline #f out)) args)
		(##core#inline "C_halt" (get-output-string out)))))))))


(define ##sys#last-exception #f)	; used in csi for ,exn command

(define ##sys#current-exception-handler
  ;; Exception-handler for the primordial thread:
  (let ((string-append string-append))
    (lambda (c)
      (when (##sys#structure? c 'condition)
	(set! ##sys#last-exception c)
	(let ((kinds (##sys#slot c 1)))
	  (cond ((memq 'exn kinds)
		 (let* ((props (##sys#slot c 2))
			(msga (member '(exn . message) props))
			(argsa (member '(exn . arguments) props))
			(loca (member '(exn . location) props)) )
		   (apply
		    (##sys#error-handler)
		    (if msga
			(let ((msg (cadr msga))
			      (loc (and loca (cadr loca))) )
			  (if (and loc (symbol? loc))
			      (string-append
			       "(" (##sys#symbol->string loc) ") "
			       (cond ((symbol? msg) (##sys#slot msg 1))
				     ((string? msg) msg)
				     (else "") ) ) ; Hm...
			      msg) )
			"<exn: has no `message' property>")
		    (if argsa
			(cadr argsa)
			'() ) )
		   ;; in case error-handler returns, which shouldn't happen:
		   ((##sys#reset-handler)) ) )
		((eq? 'user-interrupt (##sys#slot kinds 0))
		 (##sys#print "\n*** user interrupt ***\n" #f ##sys#standard-error)
		 ((##sys#reset-handler)) )
		((eq? 'uncaught-exception (##sys#slot kinds 0))
		 ((##sys#error-handler)
		  "uncaught exception"
		  (cadr (member '(uncaught-exception . reason) (##sys#slot c 2))) )
		 ((##sys#reset-handler)) ) ) ) )
      (abort
       (##sys#make-structure
	'condition 
	'(uncaught-exception) 
	(list '(uncaught-exception . reason) c)) ) ) ) )

(define (with-exception-handler handler thunk)
  (let ([oldh ##sys#current-exception-handler])
    (##sys#dynamic-wind 
      (lambda () (set! ##sys#current-exception-handler handler))
      thunk
      (lambda () (set! ##sys#current-exception-handler oldh)) ) ) )

;; TODO: Make this a proper parameter
(define (current-exception-handler . args)
  (if (null? args)
      ##sys#current-exception-handler
      (let ((proc (car args)))
	(##sys#check-closure proc 'current-exception-handler)
	(let-optionals (cdr args) ((convert? #t) (set? #t))
	  (when set? (set! ##sys#current-exception-handler proc)))
	proc)))

;;; Condition object manipulation

(define (prop-list->kind-prefixed-prop-list loc kind plist)
  (let loop ((props plist))
    (cond ((null? props) '())
	  ((or (not (pair? props)) (not (pair? (cdr props))))
	   (##sys#signal-hook
	    #:type-error loc "argument is not an even property list" plist))
	  (else (cons (cons kind (car props))
		      (cons (cadr props)
			    (loop (cddr props))))))))

(define (make-property-condition kind . props)
  (##sys#make-structure
   'condition (list kind)
   (prop-list->kind-prefixed-prop-list
    'make-property-condition kind props)))

(define (make-composite-condition c1 . conds)
  (let ([conds (cons c1 conds)])
    (for-each (lambda (c) (##sys#check-structure c 'condition 'make-composite-condition)) conds)
    (##sys#make-structure
     'condition
     (apply ##sys#append (map (lambda (c) (##sys#slot c 1)) conds))
     (apply ##sys#append (map (lambda (c) (##sys#slot c 2)) conds)) ) ) )

(define (condition arg1 . args)
  (let* ((args (cons arg1 args))
	 (keys (apply ##sys#append
		      (map (lambda (c)
			     (prop-list->kind-prefixed-prop-list
			      'condition (car c) (cdr c)))
			     args))))
    (##sys#make-structure 'condition (map car args) keys)))

(define (condition? x) (##sys#structure? x 'condition))

(define (condition->list x)
  (unless (condition? x)
    (##sys#signal-hook
     #:type-error 'condition->list
     "argument is not a condition object" x))
  (map (lambda (k)
	 (cons k (let loop ((props (##sys#slot x 2)))
		   (cond ((null? props) '())
			 ((eq? (caar props) k)
			  (cons (cdar props)
				(cons (cadr props)
				      (loop (cddr props)))))
			 (else
			  (loop (cddr props)))))))
       (##sys#slot x 1)))

(define (condition-predicate kind)
  (lambda (c) 
    (and (condition? c)
         (if (memv kind (##sys#slot c 1)) #t #f)) ) )

(define (condition-property-accessor kind prop . err-def)
  (let ((err? (null? err-def))
	(k+p (cons kind prop)) )
    (lambda (c)
      (##sys#check-structure c 'condition)
      (and (memv kind (##sys#slot c 1))
	   (let ([a (member k+p (##sys#slot c 2))])
	     (cond [a (cadr a)]
		   [err? (##sys#signal-hook 
			  #:type-error 'condition-property-accessor
			  "condition has no such property" prop) ]
		   [else (car err-def)] ) ) ) ) ) )

(define get-condition-property
  (lambda (c kind prop . err-def)
    ((apply condition-property-accessor kind prop err-def) c)))


;;; Convenient error printing:

(define print-error-message
  (let* ((display display)
	 (newline newline)
	 (write write)
	 (string-append string-append)
	 (errmsg (condition-property-accessor 'exn 'message #f))
	 (errloc (condition-property-accessor 'exn 'location #f))
	 (errargs (condition-property-accessor 'exn 'arguments #f))
	 (writeargs
	  (lambda (args port)
	    (##sys#for-each
	     (lambda (x)
	       (##sys#with-print-length-limit 80 (lambda () (write x port)))
	       (newline port) )
	     args) ) ) )
    (lambda (ex . args)
      (let-optionals args ((port ##sys#standard-output)
			   (header "Error"))
	(##sys#check-output-port port #t 'print-error-message)
	(newline port)
	(display header port)
	(cond ((and (not (##sys#immediate? ex)) (eq? 'condition (##sys#slot ex 0)))
	       (cond ((errmsg ex) =>
		      (lambda (msg)
			(display ": " port)
			(let ((loc (errloc ex)))
			  (when (and loc (symbol? loc))
			    (display (string-append "(" (##sys#symbol->string loc) ") ") port) ) )
			(display msg port) ) )
		     (else
		      (let ((kinds (##sys#slot ex 1)))
			(if (equal? '(user-interrupt) kinds)
			    (display ": *** user interrupt ***" port)
			    (begin
			      (display ": <condition> " port)
			      (display (##sys#slot ex 1) port) ) ) ) ) )
	       (let ((args (errargs ex)))
		 (cond
		   ((not args))
		   ((fx= 1 (length args))
		    (display ": " port)
		    (writeargs args port))
		   (else
		    (newline port)
		    (writeargs args port)))))
	      ((string? ex)
	       (display ": " port)
	       (display ex port)
	       (newline port))
	      (else
	       (display ": uncaught exception: " port)
	       (writeargs (list ex) port) ) ) ) ) ) )


;;; Show exception message and backtrace as warning
;;; (used for threads and finalizers)

(define ##sys#show-exception-warning
  (let ((print-error-message print-error-message)
	(display display)
	(write-char write-char)
	(print-call-chain print-call-chain)
	(open-output-string open-output-string)
	(get-output-string get-output-string) )
    (lambda (exn cause #!optional (thread ##sys#current-thread))
      (when ##sys#warnings-enabled
	(let ((o (open-output-string)))
	  (display "Warning" o)
	  (when thread
	    (display " (" o)
	    (display thread o)
	    (write-char #\) o))
	  (display ": " o)
	  (display cause o)
	  (print-error-message exn ##sys#standard-error (get-output-string o))
	  (print-call-chain ##sys#standard-error 0 thread) ) ))))


;;; Error hook (called by runtime-system):

(define ##sys#error-hook
  (let ([string-append string-append])
    (lambda (code loc . args)
      (case code
	((1) (let ([c (car args)]
		   [n (cadr args)] 
		   [fn (caddr args)] )
	       (apply
		##sys#signal-hook 
		#:arity-error loc
		(string-append "bad argument count - received " (##sys#number->string n) " but expected "
			       (##sys#number->string c) )
		(if fn (list fn) '())) ) )
	((2) (let ([c (car args)]
		   [n (cadr args)] 
		   [fn (caddr args)] )
	       (apply
		##sys#signal-hook
		#:arity-error loc
		(string-append "too few arguments - received " (##sys#number->string n) " but expected "
			       (##sys#number->string c) )
		(if fn (list fn) '()))))
	((3) (apply ##sys#signal-hook #:type-error loc "bad argument type" args))
	((4) (apply ##sys#signal-hook #:runtime-error loc "unbound variable" args))
	((5) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a keyword" args))
	((6) (apply ##sys#signal-hook #:limit-error loc "out of memory" args))
	((7) (apply ##sys#signal-hook #:arithmetic-error loc "division by zero" args))
	((8) (apply ##sys#signal-hook #:bounds-error loc "out of range" args))
	((9) (apply ##sys#signal-hook #:type-error loc "call of non-procedure" args))
	((10) (apply ##sys#signal-hook #:arity-error loc "continuation cannot receive multiple values" args))
	((11) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a non-cyclic list" args))
	((12) (apply ##sys#signal-hook #:limit-error loc "recursion too deep" args))
	((13) (apply ##sys#signal-hook #:type-error loc "inexact number cannot be represented as an exact number" args))
	((14) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a proper list" args))
	((15) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a fixnum" args))
	((16) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a number" args))
	((17) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a string" args))
	((18) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a pair" args))
	((19) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a list" args))
	((20) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a character" args))
	((21) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a vector" args))
	((22) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a symbol" args))
	((23) (apply ##sys#signal-hook #:limit-error loc "stack overflow" args))
	((24) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a structure of the required type" args))
	((25) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a blob" args))
	((26) (apply ##sys#signal-hook #:type-error loc "locative refers to reclaimed object" args))
	((27) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a block object" args))
	((28) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a number vector" args))
	((29) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an integer" args))
	((30) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an unsigned integer" args))
	((31) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a pointer" args))
	((32) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a tagged pointer" args))
	((33) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a flonum" args))
	((34) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a procedure" args))
	((35) (apply ##sys#signal-hook #:type-error loc "bad argument type - invalid base" args))
	((36) (apply ##sys#signal-hook #:limit-error loc "recursion too deep or circular data encountered" args))
	((37) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a boolean" args))
	((38) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a locative" args))
	((39) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a port" args))
	((40) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a port of the correct type" args))
	((41) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an input-port" args))
	((42) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an output-port" args))
	((43) (apply ##sys#signal-hook #:file-error loc "port already closed" args))
	((44) (apply ##sys#signal-hook #:type-error loc "cannot represent string with NUL bytes as C string" args))
	((45) (apply ##sys#signal-hook #:memory-error loc "segmentation violation" args))
	((46) (apply ##sys#signal-hook #:arithmetic-error loc "floating-point exception" args))
	((47) (apply ##sys#signal-hook #:runtime-error loc "illegal instruction" args))
	((48) (apply ##sys#signal-hook #:memory-error loc "bus error" args))
	((49) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an exact number" args))
	((50) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an inexact number" args))
	((51) (apply ##sys#signal-hook #:type-error loc "bad argument type - not a real" args))
	((52) (apply ##sys#signal-hook #:type-error loc "bad argument type - complex number has no ordering" args))
	((53) (apply ##sys#signal-hook #:type-error loc "bad argument type - not an exact integer" args))
	((54) (apply ##sys#signal-hook #:type-error loc "number does not fit in foreign type" args))
	((55) (apply ##sys#signal-hook #:type-error loc "cannot compute absolute value of complex number" args))
	((56) (let ((c (car args))
		    (n (cadr args))
		    (fn (caddr args)))
	        (apply
		 ##sys#signal-hook
		 #:bounds-error loc
		 (string-append "attempted rest argument access at index " (##sys#number->string n)
                                " but rest list length is " (##sys#number->string c) )
		 (if fn (list fn) '()))))
	(else (apply ##sys#signal-hook #:runtime-error loc "unknown internal error" args)) ) ) ) )

) ; chicken.condition

(import chicken.condition)

;;; Miscellaneous low-level routines:

(define (##sys#structure? x s) (##core#inline "C_i_structurep" x s))
(define (##sys#generic-structure? x) (##core#inline "C_structurep" x))
(define (##sys#slot x i) (##core#inline "C_slot" x i))
(define (##sys#size x) (##core#inline "C_block_size" x))
(define ##sys#make-pointer (##core#primitive "C_make_pointer"))
(define ##sys#make-tagged-pointer (##core#primitive "C_make_tagged_pointer"))
(define (##sys#pointer? x) (##core#inline "C_anypointerp" x))
(define (##sys#set-pointer-address! ptr addr) (##core#inline "C_update_pointer" addr ptr))
(define (##sys#bytevector? x) (##core#inline "C_bytevectorp" x))
(define (##sys#string->pbytevector s) (##core#inline "C_string_to_pbytevector" s))
(define (##sys#permanent? x) (##core#inline "C_permanentp" x))
(define (##sys#block-address x) (##core#inline_allocate ("C_block_address" 6) x))
(define (##sys#locative? x) (##core#inline "C_locativep" x))
(define (##sys#srfi-4-vector? x) (##core#inline "C_i_srfi_4_vectorp" x))

(define (##sys#null-pointer)
  (let ([ptr (##sys#make-pointer)])
    (##core#inline "C_update_pointer" 0 ptr)
    ptr) )

(define (##sys#null-pointer? x)
  (eq? 0 (##sys#pointer->address x)) )

(define (##sys#address->pointer addr)
  (let ([ptr (##sys#make-pointer)])
    (##core#inline "C_update_pointer" addr ptr)
    ptr) )

(define (##sys#pointer->address ptr)
  ;;XXX '6' is platform dependent!
  (##core#inline_allocate ("C_a_unsigned_int_to_num" 6) (##sys#slot ptr 0)) )

(define (##sys#make-c-string str #!optional (loc '##sys#make-c-string))
  (let* ([len (##sys#size str)]
         [buf (##sys#make-string (fx+ len 1))] )
    (##core#inline "C_substring_copy" str buf 0 len 0)
    (##core#inline "C_setsubchar" buf len #\nul)
    (if (fx= (##core#inline "C_asciiz_strlen" buf) len)
        buf
        (##sys#error-hook (foreign-value "C_ASCIIZ_REPRESENTATION_ERROR" int)
                          loc str))) )

(define ##sys#peek-signed-integer (##core#primitive "C_peek_signed_integer"))
(define ##sys#peek-unsigned-integer (##core#primitive "C_peek_unsigned_integer"))
(define (##sys#peek-fixnum b i) (##core#inline "C_peek_fixnum" b i))
(define (##sys#peek-byte ptr i) (##core#inline "C_peek_byte" ptr i))

(define (##sys#vector->structure! vec) (##core#inline "C_vector_to_structure" vec))

(define (##sys#peek-double b i)
  (##core#inline_allocate ("C_a_f64peek" 4) b i))

(define (##sys#peek-c-string b i)
  (and (not (##sys#null-pointer? b))
       (let* ([len (##core#inline "C_fetch_c_strlen" b i)]
	      [str2 (##sys#make-string len)] )
	 (##core#inline "C_peek_c_string" b i str2 len)
	 str2 ) ) )

(define (##sys#peek-nonnull-c-string b i)
  (let* ([len (##core#inline "C_fetch_c_strlen" b i)]
	 [str2 (##sys#make-string len)] )
    (##core#inline "C_peek_c_string" b i str2 len)
    str2 ) )

(define (##sys#peek-and-free-c-string b i)
  (and (not (##sys#null-pointer? b))
       (let* ([len (##core#inline "C_fetch_c_strlen" b i)]
	      [str2 (##sys#make-string len)] )
	 (##core#inline "C_peek_c_string" b i str2 len)
	 (##core#inline "C_free_mptr" b i)
	 str2 ) ) )

(define (##sys#peek-and-free-nonnull-c-string b i)
  (let* ([len (##core#inline "C_fetch_c_strlen" b i)]
	 [str2 (##sys#make-string len)] )
    (##core#inline "C_peek_c_string" b i str2 len)
    (##core#inline "C_free_mptr" b i)
    str2 ) )

(define (##sys#poke-c-string b i s) 
  (##core#inline "C_poke_c_string" b i (##sys#make-c-string s) s) )

(define (##sys#poke-integer b i n) (##core#inline "C_poke_integer" b i n))
(define (##sys#poke-double b i n) (##core#inline "C_poke_double" b i n))

(define ##sys#peek-c-string-list 
  (let ((fetch (foreign-lambda c-string "C_peek_c_string_at" c-pointer int)))
    (lambda (ptr n)
      (let loop ((i 0))
	(if (and n (fx>= i n))
	    '()
	    (let ((s (fetch ptr i)))
	      (if s
		  (cons s (loop (fx+ i 1)))
		  '() ) ) ) ) ) ) )

(define ##sys#peek-and-free-c-string-list 
  (let ((fetch (foreign-lambda c-string "C_peek_c_string_at" c-pointer int))
	(free (foreign-lambda void "C_free" c-pointer)))
    (lambda (ptr n)
      (let ((lst (let loop ((i 0))
		   (if (and n (fx>= i n))
		       '()
		       (let ((s (fetch ptr i)))
			 (cond (s
				(##core#inline "C_free_sptr" ptr i)
				(cons s (loop (fx+ i 1))) )
			       (else '() ) ) ) ) ) ) )
	(free ptr)
	lst) ) ) )

(define (##sys#vector->closure! vec addr)
  (##core#inline "C_vector_to_closure" vec)
  (##core#inline "C_update_pointer" addr vec) )

(define (##sys#symbol-has-toplevel-binding? s)
  (##core#inline "C_boundp" s))

(define (##sys#copy-bytes from to offset1 offset2 bytes)
  (##core#inline 
   "C_substring_copy"
   from to
   offset1 (fx+ offset1 bytes)
   offset2) )

(define (##sys#copy-words from to offset1 offset2 words)
  (##core#inline 
   "C_subvector_copy"
   from to
   offset1 (fx+ offset1 words)
   offset2) )

(define (##sys#compare-bytes from to offset1 offset2 bytes)
  (##core#inline 
   "C_substring_compare"
   from to
   offset1 offset2 bytes) )

(define (##sys#block-pointer x)
  (let ([ptr (##sys#make-pointer)])
    (##core#inline "C_pointer_to_block" ptr x)
    ptr) )


;;; Support routines for foreign-function calling:

(define (##sys#foreign-char-argument x) (##core#inline "C_i_foreign_char_argumentp" x))
(define (##sys#foreign-fixnum-argument x) (##core#inline "C_i_foreign_fixnum_argumentp" x))
(define (##sys#foreign-flonum-argument x) (##core#inline "C_i_foreign_flonum_argumentp" x))
(define (##sys#foreign-block-argument x) (##core#inline "C_i_foreign_block_argumentp" x))

(define (##sys#foreign-struct-wrapper-argument t x) 
  (##core#inline "C_i_foreign_struct_wrapper_argumentp" t x))

(define (##sys#foreign-string-argument x) (##core#inline "C_i_foreign_string_argumentp" x))
(define (##sys#foreign-symbol-argument x) (##core#inline "C_i_foreign_symbol_argumentp" x))
(define (##sys#foreign-pointer-argument x) (##core#inline "C_i_foreign_pointer_argumentp" x))
(define (##sys#foreign-tagged-pointer-argument x tx) (##core#inline "C_i_foreign_tagged_pointer_argumentp" x tx))

(define (##sys#foreign-ranged-integer-argument obj size)
  (##core#inline "C_i_foreign_ranged_integer_argumentp" obj size))
(define (##sys#foreign-unsigned-ranged-integer-argument obj size)
  (##core#inline "C_i_foreign_unsigned_ranged_integer_argumentp" obj size))

;;; Low-level threading interface:

(define ##sys#default-thread-quantum 10000)

(define (##sys#default-exception-handler arg) 
  (##core#inline "C_halt" "internal error: default exception handler shouldn't be called!") )

(define (##sys#make-thread thunk state name q)
  (##sys#make-structure
   'thread
   thunk				; #1 thunk
   #f					; #2 result list
   state				; #3 state
   #f					; #4 block-timeout
   (vector				; #5 state buffer
    ##sys#dynamic-winds
    ##sys#standard-input
    ##sys#standard-output
    ##sys#standard-error
    ##sys#default-exception-handler
    (##sys#vector-resize ##sys#current-parameter-vector
			 (##sys#size ##sys#current-parameter-vector) #f) )
   name					; #6 name
   (##core#undefined)			; #7 end-exception
   '()					; #8 owned mutexes
   q					; #9 quantum
   (##core#undefined)			; #10 specific
   #f					; #11 block object (type depends on blocking type)
   '()					; #12 recipients
   #f					; #13 unblocked by timeout?
   (cons #f #f)))            		; #14 ID (just needs to be unique)

(define ##sys#primordial-thread
  (##sys#make-thread #f 'running 'primordial ##sys#default-thread-quantum))

(define ##sys#current-thread ##sys#primordial-thread)

(define (##sys#make-mutex id owner)
  (##sys#make-structure
   'mutex
   id					; #1 name
   owner				; #2 thread or #f
   '()					; #3 list of waiting threads
   #f					; #4 abandoned
   #f					; #5 locked
   (##core#undefined) ) )		; #6 specific

(define (##sys#schedule) ((##sys#slot ##sys#current-thread 1)))

(define (##sys#thread-yield!)
  (##sys#call-with-current-continuation
   (lambda (return)
     (let ((ct ##sys#current-thread))
       (##sys#setslot ct 1 (lambda () (return (##core#undefined))))
       (##sys#schedule) ) ) ) )

(define (##sys#kill-other-threads thunk)
  (thunk))	     ; does nothing, will be modified by scheduler.scm

;; these two procedures should redefined in thread APIs (e.g. srfi-18):
(define (##sys#resume-thread-on-event t) #f)
 
(define (##sys#suspend-thread-on-event t)
  ;; wait until signal handler fires. If we are only waiting for a finalizer,
  ;; then this will wait forever:
  (##sys#sleep-until-interrupt))

(define (##sys#sleep-until-interrupt)
  (##core#inline "C_i_sleep_until_interrupt" 100)
  (##sys#dispatch-interrupt (lambda _ #f)))

  
;;; event queues (for signals and finalizers)
  
(define (##sys#make-event-queue)
  (##sys#make-structure 'event-queue 
                        '() ; head
                        '() ; tail
                        #f)) ; suspended thread

(define (##sys#add-event-to-queue! q e)
  (let ((h (##sys#slot q 1))
        (t (##sys#slot q 2))
        (item (cons e '())))
    (if (null? h)
        (##sys#setslot q 1 item)
        (##sys#setslot t 1 item))
    (##sys#setslot q 2 item)
    (let ((st (##sys#slot q 3))) ; thread suspended?
      (when st
        (##sys#setslot q 3 #f)
        (##sys#resume-thread-on-event st)))))

(define (##sys#get-next-event q)
  (let ((st (##sys#slot q 3)))
    (and (not st)
         (let ((h (##sys#slot q 1)))
           (and (not (null? h))
                (let ((x (##sys#slot h 0))
                      (n (##sys#slot h 1)))
                  (##sys#setslot q 1 n)
                  (when (null? n) (##sys#setslot q 2 '()))
                  x))))))

(define (##sys#wait-for-next-event q)
  (let ((st (##sys#slot q 3)))
    (when st
      (##sys#signal-hook #:runtime-error #f "event queue blocked" q))
    (let again ()
      (let ((h (##sys#slot q 1)))
        (cond ((null? h)
               (##sys#setslot q 3 ##sys#current-thread)
               (##sys#suspend-thread-on-event ##sys#current-thread)
               (again))
              (else
                (let ((x (##sys#slot h 0))
                      (n (##sys#slot h 1)))
                  (##sys#setslot q 1 n)
                  (when (null? n) (##sys#setslot q 2 '()))
                  x)))))))
  

;;; Sleeping:

(define (chicken.base#sleep-hook n) ; modified by scheduler.scm
  (##core#inline "C_i_process_sleep" n))

(set! chicken.base#sleep
  (lambda (n)
    (##sys#check-fixnum n 'sleep)
    (chicken.base#sleep-hook n)
    (##core#undefined)))


;;; Interrupt-handling:

(define ##sys#context-switch (##core#primitive "C_context_switch"))

(define ##sys#signal-vector (make-vector 256 #f))

(define (##sys#interrupt-hook reason state)
  (let loop ((reason reason))
    (when reason
      (let ((handler (##sys#slot ##sys#signal-vector reason)))
	(when handler
	  (handler reason))
	(loop (##core#inline "C_i_pending_interrupt" #f)))))
    (cond ((fx> (##sys#slot ##sys#pending-finalizers 0) 0)
	   (##sys#run-pending-finalizers state) )
	  ((procedure? state) (state))
	  (else (##sys#context-switch state) ) ) )

(define (##sys#dispatch-interrupt k)
  (##sys#interrupt-hook
   (##core#inline "C_i_pending_interrupt" #f)
   k))


;;; Accessing "errno":

(define-foreign-variable _errno int "errno")

(define ##sys#update-errno)
(define ##sys#errno)

(let ((n 0))
  (set! ##sys#update-errno (lambda () (set! n _errno) n))
  (set! ##sys#errno (lambda () n)))


;;; Format error string for unterminated here-docs:

(define (##sys#format-here-doc-warning end)
  (##sys#print-to-string `("unterminated here-doc string literal `" ,end "'")))

;;; Special string quoting syntax:

(set! ##sys#user-read-hook
  (let ([old ##sys#user-read-hook]
	[read read]
	[display display] )
    (define (readln port)
      (let ([ln (open-output-string)])
	(do ([c (##sys#read-char-0 port) (##sys#read-char-0 port)])
	    ((or (eof-object? c) (char=? #\newline c))
	     (if (eof-object? c) c (get-output-string ln)))
	  (##sys#write-char-0 c ln) ) ) )
    (define (read-escaped-sexp port skip-brace?)
      (when skip-brace? (##sys#read-char-0 port))
      (let* ((form (read port)))
	(when skip-brace?
	      (let loop ()
		;; Skips all characters until #\}
		(let ([c (##sys#read-char-0 port)])
		  (cond [(eof-object? c)
			 (##sys#read-error port "unexpected end of file - unterminated `#{...}' item in `here' string literal") ]
			[(not (char=? #\} c)) (loop)] ) ) ) )
	form))
    (lambda (char port)
      (cond [(not (char=? #\< char)) (old char port)]
	    [else
	     (read-char port)
	     (case (##sys#peek-char-0 port)
	       [(#\<)
		(##sys#read-char-0 port)
		(let ([str (open-output-string)]
		      [end (readln port)] 
		      [f #f] )
		  (let ((endlen (if (eof-object? end) 0 (string-length end))))
		    (cond
		     ((fx= endlen 0)
		      (##sys#read-warning
		       port "Missing tag after #<< here-doc token"))
		     ((or (char=? (string-ref end (fx- endlen 1)) #\space)
			  (char=? (string-ref end (fx- endlen 1)) #\tab))
		      (##sys#read-warning
		       port "Whitespace after #<< here-doc tag"))
		     ))			    
		  (do ([ln (readln port) (readln port)])
		      ((or (eof-object? ln) (string=? end ln))
		       (when (eof-object? ln)
			 (##sys#read-warning port
			  (##sys#format-here-doc-warning end)))
		       (get-output-string str) )
		    (if f 
			(##sys#write-char-0 #\newline str)
			(set! f #t) )
		    (display ln str) ) ) ]
	       [(#\#)
		(##sys#read-char-0 port)
		(let ([end (readln port)] 
		      [str (open-output-string)] )
		  (define (get/clear-str)
		    (let ((s (get-output-string str)))
		      (set! str (open-output-string))
		      s))

		  (let ((endlen (if (eof-object? end) 0 (string-length end))))
		    (cond
		     ((fx= endlen 0)
		      (##sys#read-warning
		       port "Missing tag after #<# here-doc token"))
		     ((or (char=? (string-ref end (fx- endlen 1)) #\space)
			  (char=? (string-ref end (fx- endlen 1)) #\tab))
		      (##sys#read-warning
		       port "Whitespace after #<# here-doc tag"))
		     ))

		  (let loop [(lst '())]
		    (let ([c (##sys#read-char-0 port)])
		      (case c
			[(#\newline #!eof)
			 (let ([s (get/clear-str)])
			   (cond [(or (eof-object? c) (string=? end s))
				  (when (eof-object? c)
				    (##sys#read-warning
				     port (##sys#format-here-doc-warning end))
				     )
				  `(##sys#print-to-string
				    ;;Can't just use `(list ,@lst) because of 126 argument apply limit
				    ,(let loop2 ((lst (cdr lst)) (next-string '()) (acc ''())) ; drop last newline
				       (cond ((null? lst)
					      `(cons ,(##sys#print-to-string next-string) ,acc))
					     ((or (string? (car lst)) (char? (car lst)))
					      (loop2 (cdr lst) (cons (car lst) next-string) acc))
					     (else
					      (loop2 (cdr lst)
						     '()
						     `(cons ,(car lst)
							    (cons ,(##sys#print-to-string next-string) ,acc))))))) ]
				 [else (loop (cons #\newline (cons s lst)))] ) ) ]
			[(#\#)
			 (let ([c (##sys#peek-char-0 port)])
			   (case c
			     [(#\#)
			      (##sys#write-char-0 (##sys#read-char-0 port) str)
			      (loop lst) ]
			     [(#\{) (loop (cons (read-escaped-sexp port #t)
						(cons (get/clear-str) lst) ) ) ]
			     [else  (loop (cons (read-escaped-sexp port #f)
						(cons (get/clear-str) lst) ) ) ] ) ) ]
			[else
			 (##sys#write-char-0 c str)
			 (loop lst) ] ) ) ) ) ]
	       [else (##sys#read-error port "unreadable object")] ) ] ) ) ) )


;;; Accessing process information (cwd, environ, etc.)

#>

#define C_chdir(str) C_fix(chdir(C_c_string(str)))
#define C_curdir(buf, size) (getcwd(C_c_string(buf), size) ? C_fix(strlen(C_c_string(buf))) : C_SCHEME_FALSE)
#define C_getenventry(i) (environ[ i ])

#ifdef HAVE_CRT_EXTERNS_H
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#else
extern char **environ;
#endif

#ifdef HAVE_SETENV
# define C_unsetenv(s)    (unsetenv((char *)C_data_pointer(s)), C_SCHEME_TRUE)
# define C_setenv(x, y)   C_fix(setenv((char *)C_data_pointer(x), (char *)C_data_pointer(y), 1))
#else
# if defined(_WIN32) && !defined(__CYGWIN__)
#  define C_unsetenv(s)   C_setenv(s, C_SCHEME_FALSE)
# else
#  define C_unsetenv(s)   C_fix(putenv((char *)C_data_pointer(s)))
# endif
static C_word C_fcall C_setenv(C_word x, C_word y) {
  char *sx = C_c_string(x),
       *sy = (y == C_SCHEME_FALSE ? "" : C_c_string(y));
  int n1 = C_strlen(sx), n2 = C_strlen(sy);
  int buf_len = n1 + n2 + 2;
  char *buf = (char *)C_malloc(buf_len);
  if(buf == NULL) return(C_fix(0));
  else {
    C_strlcpy(buf, sx, buf_len);
    C_strlcat(buf, "=", buf_len);
    C_strlcat(buf, sy, buf_len);
    return(C_fix(putenv(buf)));
  }
}
#endif

<#

(module chicken.process-context
  (argv argc+argv command-line-arguments
   program-name executable-pathname
   change-directory current-directory
   get-environment-variable get-environment-variables
   set-environment-variable! unset-environment-variable!)

(import scheme)
(import chicken.base chicken.fixnum chicken.foreign)
(import chicken.internal.syntax)


;;; Current directory access:

(define (change-directory name)
  (##sys#check-string name 'change-directory)
  (let ((sname (##sys#make-c-string name 'change-directory)))
    (unless (fx= (##core#inline "C_chdir" sname) 0)
      (##sys#signal-hook/errno #:file-error (##sys#update-errno) 'change-directory
       (string-append "cannot change current directory - " strerror) name))
    name))

(define (##sys#change-directory-hook dir) ; set! by posix for fd support
  (change-directory dir))

(define current-directory
  (getter-with-setter
   (lambda ()
     (let* ((buffer-size (foreign-value "C_MAX_PATH" size_t))
            (buffer (make-string buffer-size))
            (len (##core#inline "C_curdir" buffer buffer-size)))
      (unless ##sys#windows-platform ; FIXME need `cond-expand' here
	(##sys#update-errno))
      (if len
	  (##sys#substring buffer 0 len)
          (##sys#signal-hook/errno
           #:file-error
           (##sys#errno)
           'current-directory "cannot retrieve current directory"))))
   (lambda (dir)
     (##sys#change-directory-hook dir))
   "(chicken.process-context#current-directory)"))


;;; Environment access:

(define get-environment-variable
  (foreign-lambda c-string "C_getenv" nonnull-c-string))

(define (set-environment-variable! var val)
  (##sys#check-string var 'set-environment-variable!)
  (##sys#check-string val 'set-environment-variable!)
  (##core#inline "C_setenv"
   (##sys#make-c-string var 'set-environment-variable!)
   (##sys#make-c-string val 'set-environment-variable!))
  (##core#undefined))

(define (unset-environment-variable! var)
  (##sys#check-string var 'unset-environment-variable!)
  (##core#inline "C_unsetenv"
   (##sys#make-c-string var 'unset-environment-variable!))
  (##core#undefined))

(define get-environment-variables
  (let ((get (foreign-lambda c-string "C_getenventry" int)))
    (lambda ()
      (let loop ((i 0))
        (let ((entry (get i)))
          (if entry
              (let scan ((j 0))
                (if (char=? #\= (##core#inline "C_subchar" entry j))
                    (cons (cons (##sys#substring entry 0 j)
                                (##sys#substring entry (fx+ j 1) (##sys#size entry)))
                          (loop (fx+ i 1)))
                    (scan (fx+ j 1))))
              '()))))))


;;; Command line handling

(define-foreign-variable main_argc int "C_main_argc")
(define-foreign-variable main_argv c-pointer "C_main_argv")

(define executable-pathname
  (foreign-lambda c-string* "C_executable_pathname"))

(define (argc+argv)
  (##sys#values main_argc main_argv))

(define argv				; includes program name
  (let ((cache #f)
        (fetch-arg (foreign-lambda* c-string ((scheme-object i))
                     "C_return(C_main_argv[C_unfix(i)]);")))
    (lambda ()
      (unless cache
        (set! cache (do ((i (fx- main_argc 1) (fx- i 1))
                         (v '() (cons (fetch-arg i) v)))
                        ((fx< i 0) v))))
      cache)))

(define program-name
  (make-parameter
   (if (null? (argv))
       "<unknown>" ; may happen if embedded in C application
       (car (argv)))
   (lambda (x)
     (##sys#check-string x 'program-name)
     x) ) )

(define command-line-arguments
  (make-parameter
   (let ((args (argv)))
     (if (pair? args)
	 (let loop ((args (##sys#slot args 1)))	; Skip over program name (argv[0])
	   (if (null? args)
	       '()
	       (let ((arg (##sys#slot args 0))
		     (rest (##sys#slot args 1)) )
		 (cond
		  ((string=? "-:" arg)	; Consume first "empty" runtime options list, return rest
		   rest)

		  ((and (fx>= (##sys#size arg) 3)
			(string=? "-:" (##sys#substring arg 0 2)))
		   (loop rest))

		  ;; First non-runtime option and everything following it is returned as-is
		  (else args) ) ) ) )
	 args) )
   (lambda (x)
     (##sys#check-list x 'command-line-arguments)
     x) ) )

) ; chicken.process-context


(module chicken.gc
    (current-gc-milliseconds gc memory-statistics 
     set-finalizer! make-finalizer add-to-finalizer
     set-gc-report! force-finalizers)

(import scheme)
(import chicken.base chicken.fixnum chicken.foreign)
(import chicken.internal.syntax)

;;; GC info:

(define (current-gc-milliseconds)
  (##core#inline "C_i_accumulated_gc_time"))

(define (set-gc-report! flag)
  (##core#inline "C_set_gc_report" flag))

;;; Memory info:

(define (memory-statistics)
  (let* ((free (##sys#gc #t))
	 (info (##sys#memory-info))
	 (half-size (fx/ (##sys#slot info 0) 2)))
    (vector half-size (fx- half-size free) (##sys#slot info 1))))

;;; Finalization:

(define-foreign-variable _max_pending_finalizers int "C_max_pending_finalizers")

(define ##sys#pending-finalizers 
  (##sys#make-vector (fx+ (fx* 2 _max_pending_finalizers) 1) (##core#undefined)) )

(##sys#setislot ##sys#pending-finalizers 0 0)

(define ##sys#set-finalizer! (##core#primitive "C_register_finalizer"))

(define ##sys#init-finalizer
  (let ((string-append string-append))
    (lambda (x y)
      (when (fx>= (##core#inline "C_i_live_finalizer_count") _max_pending_finalizers)
	(cond ((##core#inline "C_resize_pending_finalizers" (fx* 2 _max_pending_finalizers))
	       (set! ##sys#pending-finalizers
		 (##sys#vector-resize ##sys#pending-finalizers
				      (fx+ (fx* 2 _max_pending_finalizers) 1)
				      (##core#undefined)))
	       (when (##sys#debug-mode?)
		 (##sys#print 
		  (string-append
		   "[debug] too many finalizers (" 
		   (##sys#number->string
		    (##core#inline "C_i_live_finalizer_count"))
		   "), resized max finalizers to "
		   (##sys#number->string _max_pending_finalizers)
		   "\n")
		  #f ##sys#standard-error)))
	      (else
	       (when (##sys#debug-mode?)
		 (##sys#print 
		  (string-append
		   "[debug] too many finalizers ("
		   (##core#inline "C_i_live_finalizer_count")
		   "), forcing ...\n")
		  #f ##sys#standard-error))
	       (##sys#force-finalizers) ) ) )
      (##sys#set-finalizer! x y) ) ) )

(define set-finalizer! ##sys#init-finalizer)

(define finalizer-tag (vector 'finalizer))

(define (finalizer? x)
  (and (pair? x) (eq? finalizer-tag (##sys#slot x 0))) )

(define (make-finalizer . objects)
  (let ((q (##sys#make-event-queue)))
    (define (handler o) (##sys#add-event-to-queue! q o))
    (define (handle o) (##sys#init-finalizer o handler))
    (for-each handle objects)
    (##sys#decorate-lambda
       (lambda (#!optional mode)
         (if mode
             (##sys#wait-for-next-event q)
             (##sys#get-next-event q)))
       finalizer?
       (lambda (proc i)
         (##sys#setslot proc i (cons finalizer-tag handle))
         proc))))

(define (add-to-finalizer f . objects)
  (let ((af (and (procedure? f)
                 (##sys#lambda-decoration f finalizer?))))
    (unless af
      (error 'add-to-finalizer "bad argument type - not a finalizer procedure" 
             f))
    (for-each (cdr af) objects)))

(define ##sys#run-pending-finalizers
  (let ((vector-fill! vector-fill!)
	(string-append string-append)
	(working-thread #f) )
    (lambda (state)
      (cond
       ((not working-thread)
	(set! working-thread ##sys#current-thread)
	(let* ((c (##sys#slot ##sys#pending-finalizers 0)) )
	  (when (##sys#debug-mode?)
	    (##sys#print 
	     (string-append "[debug] running " (##sys#number->string c)
			    " finalizer(s) ("
			    (##sys#number->string
			     (##core#inline "C_i_live_finalizer_count"))
			    " live, "
			    (##sys#number->string
			     (##core#inline "C_i_allocated_finalizer_count"))
			    " allocated) ...\n")
	     #f ##sys#standard-error))
	  (do ([i 0 (fx+ i 1)])
	      ((fx>= i c))
	    (let ([i2 (fx+ 1 (fx* i 2))])
	      (handle-exceptions ex
		  (##sys#show-exception-warning ex "in finalizer" #f)
		((##sys#slot ##sys#pending-finalizers (fx+ i2 1))
		 (##sys#slot ##sys#pending-finalizers i2)) ) ))
	  (vector-fill! ##sys#pending-finalizers (##core#undefined))
	  (##sys#setislot ##sys#pending-finalizers 0 0) 
	  (set! working-thread #f)))
       (state)         ; Got here due to interrupt; continue w/o error
       ((eq? working-thread ##sys#current-thread)
	 (##sys#signal-hook
	  #:error '##sys#run-pending-finalizers
	  "re-entry from finalizer thread (maybe (gc #t) was called from a finalizer)"))
       (else
	;; Give finalizer thread a change to run
	(##sys#thread-yield!)))
      (cond ((not state))
	    ((procedure? state) (state))
	    (state (##sys#context-switch state) ) ) ) ))

(define force-finalizers (make-parameter #t))

(define (##sys#force-finalizers)
  (let loop ()
    (let ([n (##sys#gc)])
      (cond ((fx> (##sys#slot ##sys#pending-finalizers 0) 0)
	     (##sys#run-pending-finalizers #f)
	     (loop) )
	    (else n) ) ) ))

(define (gc . arg)
  (let ((a (and (pair? arg) (car arg))))
    (if a
	(##sys#force-finalizers)
	(##sys#gc a)))))

;;; Auxilliary definitions for safe use in quasiquoted forms and evaluated code:

(define ##sys#list->vector list->vector)
(define ##sys#list list)
(define ##sys#length length)
(define ##sys#cons cons)
(define ##sys#append append)
(define ##sys#vector vector)
(define ##sys#apply apply)
(define ##sys#values values)
(define ##sys#equal? equal?)
(define ##sys#car car)
(define ##sys#cdr cdr)
(define ##sys#pair? pair?)
(define ##sys#vector? vector?)
(define ##sys#vector->list vector->list)
(define ##sys#vector-length vector-length)
(define ##sys#vector-ref vector-ref)
(define ##sys#>= >=)
(define ##sys#= =)
(define ##sys#+ +)
(define ##sys#eq? eq?)
(define ##sys#eqv? eqv?)
(define ##sys#list? list?)
(define ##sys#null? null?)
(define ##sys#map-n map)

;;; We need this here so `location' works:
 
(define (##sys#make-locative obj index weak? loc)
  (cond [(##sys#immediate? obj)
	 (##sys#signal-hook #:type-error loc "locative cannot refer to immediate object" obj) ]
	[(or (vector? obj) (pair? obj))
	 (##sys#check-range index 0 (##sys#size obj) loc)
	 (##core#inline_allocate ("C_a_i_make_locative" 5) 0 obj index weak?) ]
	#;[(symbol? obj)
	 (##sys#check-range index 0 1 loc)
	 (##core#inline_allocate ("C_a_i_make_locative" 5) 0 obj index weak?) ]
	[(and (##core#inline "C_blockp" obj)
	      (##core#inline "C_bytevectorp" obj) )
	 (##sys#check-range index 0 (##sys#size obj) loc)
	 (##core#inline_allocate ("C_a_i_make_locative" 5) 2 obj index weak?) ]
	[(##sys#generic-structure? obj)
	 (case (##sys#slot obj 0)
	   ((u8vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 2 v index weak?))  )
	   ((s8vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 3 v index weak?) ) )
	   ((u16vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 4 v index weak?) ) )
	   ((s16vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 5 v index weak?) ) )
	   ((u32vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 6 v index weak?) ) )
	   ((s32vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 7 v index weak?) ) )
	   ((u64vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 8 v index weak?) ) )
	   ((s64vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 9 v index weak?) ) )
	   ((f32vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 10 v index weak?) ) )
	   ((f64vector)
	    (let ([v (##sys#slot obj 1)])
	      (##sys#check-range index 0 (##sys#size v) loc)
	      (##core#inline_allocate ("C_a_i_make_locative" 5) 11 v index weak?) ) )
	   ;;XXX pointer-vector currently not supported
	   (else 
	    (##sys#check-range index 0 (fx- (##sys#size obj) 1) loc)
	    (##core#inline_allocate ("C_a_i_make_locative" 5) 0 obj (fx+ index 1) weak?) ) ) ]
	[(string? obj)
	 (##sys#check-range index 0 (##sys#size obj) loc)
	 (##core#inline_allocate ("C_a_i_make_locative" 5) 1 obj index weak?) ] 
	[else
	 (##sys#signal-hook
	  #:type-error loc
	  "bad argument type - locative cannot refer to objects of this type" 
	  obj) ] ) )


;;; Property lists

(module chicken.plist
  (get get-properties put! remprop! symbol-plist)

(import scheme)
(import (only chicken.base getter-with-setter))
(import chicken.internal.syntax)

(define (put! sym prop val)
  (##sys#check-symbol sym 'put!)
  (##core#inline_allocate ("C_a_i_putprop" 8) sym prop val) )

(define (get sym prop #!optional default)
  (##sys#check-symbol sym 'get)
  (##core#inline "C_i_getprop" sym prop default))

(define ##sys#put! put!)
(define ##sys#get get)

(set! get (getter-with-setter get put!))

(define (remprop! sym prop)
  (##sys#check-symbol sym 'remprop!)
  (let loop ((plist (##sys#slot sym 2)) (ptl #f))
    (and (not (null? plist))
	 (let* ((tl (##sys#slot plist 1))
		(nxt (##sys#slot tl 1)))
	   (or (and (eq? (##sys#slot plist 0) prop)
		    (begin
		      (if ptl
			  (##sys#setslot ptl 1 nxt)
			  (##sys#setslot sym 2 nxt) )
		      #t ) )
	       (loop nxt tl) ) ) ) )
  (when (null? (##sys#slot sym 2))
    ;; This will only unpersist if symbol is also unbound
    (##core#inline "C_i_unpersist_symbol" sym) ) )

(define symbol-plist
  (getter-with-setter
   (lambda (sym)
     (##sys#check-symbol sym 'symbol-plist)
     (##sys#slot sym 2) )
   (lambda (sym lst)
     (##sys#check-symbol sym 'symbol-plist)
     (##sys#check-list lst 'symbol-plist/setter)
     (if (##core#inline "C_i_fixnumevenp" (##core#inline "C_i_length" lst))
	 (##sys#setslot sym 2 lst) 
	 (##sys#signal-hook
	  #:type-error "property-list must be of even length"
	  lst sym))
     (if (null? lst)
	 (##core#inline "C_i_unpersist_symbol" sym)
	 (##core#inline "C_i_persist_symbol" sym)))
   "(chicken.plist#symbol-plist sym)"))

(define (get-properties sym props)
  (##sys#check-symbol sym 'get-properties)
  (when (symbol? props)
    (set! props (list props)) )
  (##sys#check-list props 'get-properties)
  (let loop ((plist (##sys#slot sym 2)))
    (if (null? plist)
	(values #f #f #f)
	(let* ((prop (##sys#slot plist 0))
	       (tl (##sys#slot plist 1))
	       (nxt (##sys#slot tl 1)))
	  (if (memq prop props)
	      (values prop (##sys#slot tl 0) nxt)
	      (loop nxt) ) ) ) ) )

) ; chicken.plist


;;; Print timing information (support for "time" macro):

(define (##sys#display-times info)
  (define (pstr str) (##sys#print str #f ##sys#standard-error))
  (define (pchr chr) (##sys#write-char-0 chr ##sys#standard-error))
  (define (pnum num)
    (##sys#print (if (zero? num) "0" (##sys#number->string num)) #f ##sys#standard-error))
  (define (round-to x y) ; Convert to fp with y digits after the point
    (/ (round (* x (expt 10 y))) (expt 10.0 y)))
  (define (pmem bytes)
    (cond ((> bytes (expt 1024 3))
	   (pnum (round-to (/ bytes (expt 1024 3)) 2)) (pstr " GiB"))
	  ((> bytes (expt 1024 2))
	   (pnum (round-to (/ bytes (expt 1024 2)) 2)) (pstr " MiB"))
	  ((> bytes 1024)
	   (pnum (round-to (/ bytes 1024) 2)) (pstr " KiB"))
	  (else (pnum bytes) (pstr " bytes"))))
  (##sys#flush-output ##sys#standard-output)
  (pnum (##sys#slot info 0))
  (pstr "s CPU time")
  (let ((gctime (##sys#slot info 1)))
    (when (> gctime 0)
      (pstr ", ")
      (pnum gctime)
      (pstr "s GC time (major)")))
  (let ((mut (##sys#slot info 2))
	(umut (##sys#slot info 3)))
    (when (fx> mut 0)
      (pstr ", ")
      (pnum mut)
      (pchr #\/)
      (pnum umut)
      (pstr " mutations (total/tracked)")))
  (let ((minor (##sys#slot info 4))
	(major (##sys#slot info 5)))
    (when (or (fx> minor 0) (fx> major 0))
      (pstr ", ")
      (pnum major)
      (pchr #\/)
      (pnum minor)
      (pstr " GCs (major/minor)")))
  (let ((maximum-heap-usage (##sys#slot info 6)))
    (pstr ", maximum live heap: ")
    (pmem maximum-heap-usage))
  (##sys#write-char-0 #\newline ##sys#standard-error)
  (##sys#flush-output ##sys#standard-error))


;;; Dump heap state to stderr:

(define ##sys#dump-heap-state (##core#primitive "C_dump_heap_state"))
(define ##sys#filter-heap-objects (##core#primitive "C_filter_heap_objects"))


;;; Platform configuration inquiry:

(module chicken.platform
    (build-platform chicken-version
     chicken-home 	;; DEPRECATED
     include-path
     feature? features machine-byte-order machine-type
     repository-path installation-repository
     register-feature! unregister-feature!
     software-type software-version return-to-host
     system-config-directory system-cache-directory
     )

(import scheme)
(import chicken.fixnum chicken.foreign chicken.keyword chicken.process-context)
(import chicken.internal.syntax)
(import (only chicken.base make-parameter))

(define software-type
  (let ((sym (string->symbol ((##core#primitive "C_software_type")))))
    (lambda () sym)))

(define machine-type
  (let ((sym (string->symbol ((##core#primitive "C_machine_type")))))
    (lambda () sym)))

(define machine-byte-order
  (let ((sym (string->symbol ((##core#primitive "C_machine_byte_order")))))
    (lambda () sym)))

(define software-version
  (let ((sym (string->symbol ((##core#primitive "C_software_version")))))
    (lambda () sym)))

(define build-platform
  (let ((sym (string->symbol ((##core#primitive "C_build_platform")))))
    (lambda () sym)))

(define ##sys#windows-platform
  (and (eq? 'windows (software-type))
       ;; Still windows even if 'Linux-like'
       (not (eq? 'cygwin (software-version)))))

(define (chicken-version #!optional full)
  (define (get-config)
    (let ((bp (build-platform))
	  (st (software-type))
	  (sv (software-version))
	  (mt (machine-type)))
      (define (str x)
	(if (eq? 'unknown x)
	    ""
	    (string-append (symbol->string x) "-")))
      (string-append (str sv) (str st) (str bp) (##sys#symbol->string mt))))
  (if full
      (let ((spec (string-append
		   " " (number->string (foreign-value "C_WORD_SIZE" int)) "bit"
		   (if (feature? #:dload) " dload" "")
		   (if (feature? #:ptables) " ptables" "")
		   (if (feature? #:gchooks) " gchooks" "")
		   (if (feature? #:cross-chicken) " cross" ""))))
	(string-append
	 "Version " ##sys#build-version
	 (if ##sys#build-branch (string-append " (" ##sys#build-branch ")") "")
	 (if ##sys#build-id (string-append " (rev " ##sys#build-id ")") "")
	 "\n"
	 (get-config)
	 (if (zero? (##sys#size spec))
	     ""
	     (string-append " [" spec " ]"))))
      ##sys#build-version))

;;; Installation locations

(define-foreign-variable binary-version int "C_BINARY_VERSION")
(define-foreign-variable installation-home c-string "C_INSTALL_SHARE_HOME")
(define-foreign-variable install-egg-home c-string "C_INSTALL_EGG_HOME")

;; DEPRECATED
(define (chicken-home) installation-home)

(define path-list-separator
  (if ##sys#windows-platform #\; #\:))

(define ##sys#split-path
  (let ((cache '(#f)))
    (lambda (path)
      (cond ((not path) '())
            ((equal? path (car cache))
             (cdr cache))
            (else
              (let* ((len (string-length path))
                     (lst (let loop ((start 0) (pos 0))
                            (cond ((fx>= pos len)
                                   (if (fx= pos start)
                                       '()
                                       (list (substring path start pos))))
                                  ((char=? (string-ref path pos)
                                           path-list-separator)
                                   (cons (substring path start pos)
                                         (loop (fx+ pos 1)
                                               (fx+ pos 1))))
                                  (else
                                    (loop start (fx+ pos 1)))))))
                (set! cache (cons path lst))
                lst))))))

(define repository-path
  (make-parameter
   (cond ((foreign-value "C_private_repository_path()" c-string)
           => list)
         ((get-environment-variable "CHICKEN_REPOSITORY_PATH")
           => ##sys#split-path)
         (install-egg-home
           => list)
         (else #f))
   (lambda (new)
     (and new
          (begin
            (##sys#check-list new 'repository-path)
            (for-each (lambda (p) (##sys#check-string p 'repository-path)) new)
            new)))))

(define installation-repository
  (make-parameter
   (or (foreign-value "C_private_repository_path()" c-string)
       (get-environment-variable "CHICKEN_INSTALL_REPOSITORY")
       install-egg-home)))

(define (chop-separator str)
  (let ((len (fx- (string-length str) 1)))
    (if (and (> len 0)
             (memq (string-ref str len) '(#\\ #\/)))
        (substring str 0 len)
        str) ) )

(define ##sys#include-pathnames
  (cond ((get-environment-variable "CHICKEN_INCLUDE_PATH")
         => (lambda (p)
              (map chop-separator (##sys#split-path p))))
        (else (list installation-home))))

(define (include-path) ##sys#include-pathnames)


;;; Feature identifiers:

(define ->feature-id ; TODO: export this?  It might be useful..
  (let ()
    (define (err . args)
      (apply ##sys#signal-hook #:type-error "bad argument type - not a valid feature identifer" args))
    (define (prefix s)
      (if s (##sys#string-append s "-") ""))
    (lambda (x)
      (cond ((keyword? x) x)
	    ((string? x) (string->keyword x))
	    ((symbol? x) (string->keyword (##sys#symbol->string x)))
	    (else (err x))))))

(define ##sys#features
  '(#:chicken
    #:srfi-6 #:srfi-12 #:srfi-17 #:srfi-23 #:srfi-30
    #:srfi-39 #:srfi-62 #:srfi-88 #:full-numeric-tower))

;; Add system features:

(let ((check (lambda (f)
	       (unless (eq? 'unknown f)
		 (set! ##sys#features (cons (->feature-id f) ##sys#features))))))
  (check (software-type))
  (check (software-version))
  (check (build-platform))
  (check (machine-type))
  (check (machine-byte-order)))

(when (foreign-value "HAVE_DLOAD" bool)
  (set! ##sys#features (cons #:dload ##sys#features)))
(when (foreign-value "HAVE_PTABLES" bool)
  (set! ##sys#features (cons #:ptables ##sys#features)))
(when (foreign-value "HAVE_GCHOOKS" bool)
  (set! ##sys#features (cons #:gchooks ##sys#features)))
(when (foreign-value "IS_CROSS_CHICKEN" bool)
  (set! ##sys#features (cons #:cross-chicken ##sys#features)))

;; Register a feature to represent the word size (e.g., 32bit, 64bit)
(set! ##sys#features
      (cons (string->keyword
             (string-append
              (number->string (foreign-value "C_WORD_SIZE" int))
              "bit"))
            ##sys#features))

(set! ##sys#features
  (let ((major (##sys#number->string (foreign-value "C_MAJOR_VERSION" int)))
	(minor (##sys#number->string (foreign-value "C_MINOR_VERSION" int))))
    (cons (->feature-id (string-append "chicken-" major))
	  (cons (->feature-id (string-append "chicken-" major "." minor))
		##sys#features))))

(define (register-feature! . fs)
  (for-each
   (lambda (f)
     (let ((id (->feature-id f)))
       (unless (memq id ##sys#features) (set! ##sys#features (cons id ##sys#features)))))
   fs)
  (##core#undefined))

(define (unregister-feature! . fs)
  (let ((fs (map ->feature-id fs)))
    (set! ##sys#features
      (let loop ((ffs ##sys#features))
	(if (null? ffs)
	    '()
	    (let ((f (##sys#slot ffs 0))
		  (r (##sys#slot ffs 1)))
	      (if (memq f fs)
		  (loop r)
		  (cons f (loop r)))))))
    (##core#undefined)))

(define (features) ##sys#features)

(define (feature? . ids)
  (let loop ((ids ids))
    (or (null? ids)
	(and (memq (->feature-id (##sys#slot ids 0)) ##sys#features)
	     (loop (##sys#slot ids 1))))))

(define return-to-host
  (##core#primitive "C_return_to_host"))

(define (system-config-directory)
  (or (get-environment-variable "XDG_CONFIG_HOME")
      (if ##sys#windows-platform
          (get-environment-variable "APPDATA")
          (let ((home (get-environment-variable "HOME")))
            (and home (string-append home "/.config"))))))

(define (system-cache-directory)
  (or (get-environment-variable "XDG_CACHE_HOME")
      (if ##sys#windows-platform
          (or (get-environment-variable "LOCALAPPDATA")
              (get-environment-variable "APPDATA"))
          (let ((home (get-environment-variable "HOME")))
            (and home (string-append home "/.cache"))))))

) ; chicken.platform
