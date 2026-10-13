/* Declarations for arithmetics
 German comments and names translated into English: Reini Urban 2007-11

 Type hierarchy:
 Number (N) =
    Real (R) =
       Float (F) =
          Short float (SF)
          Single float (FF)
          Double float (DF)
          Long float (LF)
       Rational (RA) =
          Integer (I) =
             Fixnum (FN)
             Bignum (BN)
          Ratio (RT)
    Complex (C)

 Notes:
  - Complex may consist of two real parts of different types. If the
    imaginary part is EQ to 0, it will be converted to a real.
    (See CLTL p. 195)
    Pro: (let ((x (sqrt -9.0))) (* x x))
      (instead of x = #C(0.0 3.0)  -> Value #C(-9.0 0.0) )
      x = #C(0 3.0)  -> Value #C(-9.0 0) = -9.0
  - Coercions with operations of different types:
      Rational -> Long-float -> Double-float -> Single-float -> Short-float
      (different from CLTL p. 195)
      Reason: mathematically
             (1.0 +- 1e-8) + (1.0 +- 1e-16) = (2.0 +- 1e-8),
             so (+ 1.0s0 1.0d0) ==> 2.0s0 justified.
      In short: unavailable accuracy may not be fooled by precision.
      See also <http://clisp.cons.org/impnotes/num-concepts.html#flocont>.
  - With Single and Double Float we hold on to the IEEE-Standard (1981),
      but without such features such as +0,-0, +inf,-inf, gradual underflow,
      NAN, ..., because COMMON LISP has no use for that.
  - Long Float accuracy is specified by the place (LONG-FLOAT-DIGITS).

 Data structures:

   Fixnum (FN) : 1 longword, immediate:
               Bits 30..24: type info and sign.
               Bits 23..0:  Value (together with the sign of the twos
               complement representation)
 Mask for the value: */
#define FN_value_mask  ((oint)wbitm(oint_data_len+oint_data_shift)-(oint)wbit(oint_data_shift))
/* Mask for the value and sign: */
#define FN_value_vz_mask  (FN_value_mask|wbit(sign_bit_o))
/* type info for FN >=0:  fixnum_type
 type info for FN <0: */
#define fixnum_vz_type  (fixnum_type|bit(sign_bit_t))
/* (defconstant most-positive-fixnum (- (expt 2 oint_data_len) 1))
   (defconstant most-negative-fixnum (- (expt 2 oint_data_len)))
 0 fixnum:
#define Fixnum_0  fixnum(0)
 1 Fixnum:
#define Fixnum_1  fixnum(1)
 -1 Fixnum:
#define Fixnum_minus1  type_data_object(fixnum_vz_type,FN_value_mask>>oint_data_shift)
 most-positive-fixnum: */
#define Fixnum_mpos  type_data_object(fixnum_type,FN_value_mask>>oint_data_shift)
/* most-negative-fixnum: */
#define Fixnum_mneg  type_data_object(fixnum_vz_type,0)
/* maximal needed length of a digit sequence for a fixnum: */
#define FN_maxlength  ceiling(oint_data_len+1,intDsize)
/* maximal needed length (without sign) of a digit sequence for a fixnum: */
#define pFN_maxlength  ceiling(oint_data_len,intDsize)
/* It applies pFN_maxlength <= FN_maxlength <= bn_minlength.

 Longword (L) - only used internally -
   as longword as signed integer, in two-complement (sint32).

 Bignum (BN) : 1 longword, indirect:
               Bits 30..24: type info and sign
               Bits 23..0: pointer X
               X^.length = length n (uintC), >= bn_minlength
               X^.data = n Digits (as normalized digit sequence) */
#define bn_minlength  ceiling(oint_data_len+2,intDsize)
/* Because bignums with n < ceiling((oint_data_len+2)/intDsize) digits
     are integers with maximal intDsize*n < oint_data_len+2 bits, so
     integers with maximal oint_data_len+1 bits (incl. sign),
     and they fit into fixnums. 1 <= bn_minlength <= 5.

 Ratio (RT) = a record with two components:
                NUM = numerator (Integer), DEN = denominator (Integer > 0)
                with coprime numerator and denominator.
   (in detail: Bits 30..24 = type info and sign
               Bits 23..0  = pointer X
               X^.rt_num   = NUM, X^.rt_den = DEN. )

 Rational (RA) = Integer or Ratio.

 For all floating point numbers:
   sign s, exponent e, mantissa mk-1,...,m0
   represents the number (-1)^s * 2^(e-_EXP_MID) * [0 . 1 mk-1 ... m0]
   e=0 is the number 0.0, always with signs=0 (and mantissa =0).
   _exp_low and _exp_high are bounds (inclusive) for e.
   Bitnumbers for  sign s     exponent e    mantisse m (= k)
   SF                   1              8             16
   FF                   1              8             23
   DF                   1              11            52
   LF                   1              32            uintDsize*n >= 53

 Short float (SF)  : 1 longword, direct:
               Bits 30..24: typeinfo and sign s.
               Bits 23..16: exponent e (8 Bits)
               Bits 15..0: mantissa m (16 Bits)
               The number 0 is represented by s=0, e=0, m=0. */
#define SF_exp_len    8  /* Number of exponent bits */
#define SF_mant_len  16  /* Number of mantissa bits */
/* Choose the same values as for single float, so that conversion from
 short float to single float always succeeds without overflow or underflow. */
#if 1
  #define SF_exp_low   1        /* minimal exponent */
  #define SF_exp_mid   126      /* value representing exponent 0 */
  #define SF_exp_high  254      /* maximal exponent */
#else
  #define SF_exp_low   1                 /* minimal exponent */
  #define SF_exp_mid   bit(SF_exp_len-1) /* value representing exponent 0 */
  #define SF_exp_high  (bit(SF_exp_len)-1)  /* maximal exponent */
#endif
#define SF_exp_shift  (SF_mant_len+SF_mant_shift) /* lowest bit of the exponenten in oint */
#define SF_mant_shift  oint_data_shift /* lowest bit of the mantissa in oint */
/* Typeinfo-Byte for SF >=0 : */
#define SF_type     sfloat_type
/* Typeinfo-Byte for SF <0, with set sign-bit: */
#define SF_vz_type  (sfloat_type|bit(sign_bit_t))
/* Creates a single float from sign (0 or -1), exponent and mantissa: */
#define make_SF(sign,exp,mant)  \
  type_data_object(SF_type | (bit(sign_bit_t) & (sign)), \
    (((exp) & (bit(SF_exp_len)-1)) << SF_mant_len) | ((mant) & (bit(SF_mant_len)-1)))
/* Short Float 0.0 : */
#define SF_0  make_SF(0,0,0)
/* Short Float 1.0 : */
#define SF_1  make_SF(0,SF_exp_mid+1,bit(SF_mant_len))
/* Short Float -1.0 : */
#define SF_minus1  make_SF(-1,SF_exp_mid+1,bit(SF_mant_len))

/* Single float (FF) : 1 longword, indirect:
               Bits 30..24: type info and sign
               Bits 23..0: pointer X
               X^.float_value = 1 longword:
                    Bit 31 = s, Bits 30..23 = e, Bits 22..0 = m.
               The number 0.0 is represented by s=0, e=0, m=0. */
#define FF_exp_len    8  /* Number of exponent bits */
#define FF_mant_len  23  /* Number of mantissa bits */
/* On platforms with FAST_FLOAT we obey the IEEE 754 values. Choose the same
   values on other platforms as well, so that most-positive-single-float etc.
   will be platform independent. */
#if defined(FAST_FLOAT) || 1
  #define FF_exp_low  1
  #define FF_exp_mid  126  /* Unclear to me why that is the "middle"... */
  #define FF_exp_high 254  /* Exponent 255 is interpreted as NaN/Inf! */
#else /* I chose the parameters even then symmetrically */
  #define FF_exp_low  1
  #define FF_exp_mid  128
  #define FF_exp_high 255
#endif
#ifdef TYPECODES
/* Typeinfo-Byte for FF >=0 : */
  #define FF_type     ffloat_type
/* Typeinfo-Byte for FF <0, with set sign-bit: */
  #define FF_vz_type  (ffloat_type|bit(vorz_bit_t))
#endif
#ifdef IMMEDIATE_FFLOAT
/* Creates a single float from sign (0 or -1), exponent and mantissa: */
  #define make_FF(sign,exp,mant)  \
    type_data_object(FF_type | (bit(vorz_bit_t) & (sign)),      \
      (ffloat)((sign) << (FF_exp_len+FF_mant_len)               \
               | (((exp) & (bit(FF_exp_len)-1)) << FF_mant_len) \
               | ((mant) & (bit(FF_mant_len)-1))))
/* Single Float 0.0 : */
  #define FF_0  make_FF(0,0,0)
/* Single Float 1.0 : */
  #define FF_1  make_FF(0,FF_exp_mid+1,bit(FF_mant_len))
/* Single Float -1.0 : */
  #define FF_minus1  make_FF(-1,FF_exp_mid+1,bit(FF_mant_len))
#else
/* Single Float 0.0 : */
  #define FF_0  (object)O(FF_zero)
/* Single Float 1.0 : */
  #define FF_1  (object)O(FF_one)
/* Single Float -1.0 : */
  #define FF_minus1  (object)O(FF_minusone)
#endif

/* Double float (DF) : 1 longword, indirect:
               Bits 30..24: type info and sign
               Bits 23..0: pointer X
               X^.float_value = 2 longwords:
                    Bit 63 = s, Bits 62..52 = e, Bits 51..0 = m.
               The number 0.0 is represented by s=0, e=0, m=0. */
#define DF_exp_len   11  /* Number of exponent bits */
#define DF_mant_len  52  /* Anzahl der Bits der Mantisse */
/* On platforms with FAST_FLOAT we obey the IEEE 754 values. Choose the same
   values on other platforms as well, so that most-positive-double-float etc.
   will be platform independent. */
#if defined(FAST_DOUBLE) || 1
  #define DF_exp_low  1
  #define DF_exp_mid  1022 /* Unclear to me why that is the "middle"... */
  #define DF_exp_high 2046 /* Exponent 2047 is interpreted as NaN/Inf! */
#else /* I chose the parameters even then symmetrically */
  #define DF_exp_low  1
  #define DF_exp_mid  1024
  #define DF_exp_high 2047
#endif
#ifdef TYPECODES
/* Typeinfo-Byte for DF >=0 : */
  #define DF_type     dfloat_type
/* Typeinfo-Byte for DF <0, with set sign-bit: */
  #define DF_vz_type  (dfloat_type|bit(vorz_bit_t))
#endif
/* Double Float 0.0 : */
#define DF_0  (object)O(DF_zero)
/* Double Float 1.0 : */
#define DF_1  (object)O(DF_one)
/* Double Float -1.0 : */
#define DF_minus1  (object)O(DF_minusone)

/* Long float (LF) : 1 longword, indirect:
     Bits 30..24: type info and sign
     Bits 23..0: pointer X
    X^.len = n = Number of following mantissa words, n>=ceiling(53/intDsize)
    X^.expo = e (32 Bits)
    X^.data[0] ... X^.data[n-1] = intDsize*n mantissa bits (MSD ... LSD)
    The number 0.0 is represented by e=0, m=0.
    For e /= 0 the highest bit is 1.
    n>=ceiling(53/intDsize), that a LF has not less mantissa bits than a DF. */
#define LF_minlen  ceiling(53,intDsize)
/* Define as 'unsigned int', not 'unsigned long', so that
   LF_exp_high+1 wraps around to 0 just like the 'expo' field does. */
#define LF_exp_low  1
#define LF_exp_mid  0x80000000U
#define LF_exp_high 0xFFFFFFFFU
#ifdef TYPECODES
/* Typeinfo-Byte for LF >=0 : */
  #define LF_type     lfloat_type
/* Typeinfo-Byte for LF <0, with set sign-Bit: */
  #define LF_vz_type  (lfloat_type|bit(vorz_bit_t))
#endif

/* Byte (BYTE) : Record with the components size and position:
             1 longword, indirect:
             Bits 30..24: type info
             Bits 23..0: pointer X
             X^.byte_size = size, a fixnum >=0.
             X^.byte_position = position, a fixnum >=0.
 Typetest with bytep and if_bytep, constructor with allocate_byte().

 NUM_STACK is some kind of a number-stack-pointer.
   Usage:
     {
      SAVE_NUM_STACK
      ...
      num_stack_need(...);
      ...
      num_stack_need(...);
      RESTORE_NUM_STACK
      ...
     }
   SAVE_NUM_STACK saves the current value of NUM_STACK.
   Then you may reserve space unlimited times on the numeric stack with
   num_stack_need().
   With RESTORE_NUM_STACK NUM_STACK will be reset to the previous value and
   the allocated stack-space will be freed.
   In each C function SAVE_NUM_STACK/RESTORE_NUM_STACK should only be
   called once.

 num_stack_need(need, low_addr = , high_addr = );
 reserves need digits on the number-stack and puts the lower (the MSDptr)
 and upper limit (the LSDptr) of the allocated space into low_addr and
 high_addr. Both are optional.

 num_stack_need_1(need, low_addr = , high_addr = );
 same as num_stack_need, with additional space for one digit below low_addr. */

#ifdef LISPARIT

#ifdef GNU
  #define SAVE_NUM_STACK
  #define RESTORE_NUM_STACK  ;
  #define num_stack_need(need,low_assignment,high_assignment)           \
    {var uintL __need = (uintL)(need);                                  \
     var uintD* __array = (uintD*)__builtin_alloca(__need*sizeof(uintD)); \
     check_SP_notUNIX();                                                \
     unused (low_assignment &__array[0]);                               \
     unused (high_assignment &__array[__need]);                         \
    }
  #define num_stack_need_1(need,low_assignment,high_assignment)         \
    {var uintL __need = (uintL)(need)+1;                                \
     var uintD* __array = (uintD*)__builtin_alloca(__need*sizeof(uintD)); \
     check_SP_notUNIX();                                                \
     unused (low_assignment &__array[1]);                               \
     unused (high_assignment &__array[__need]);                         \
    }
#elif (defined(UNIX) && !defined(NO_ALLOCA) && !defined(SPARC)) || defined(BORLAND) || defined(MICROSOFT)
  /* reserve space at the machine stack. */
  #define SAVE_NUM_STACK
  #define RESTORE_NUM_STACK  ;
  #define num_stack_need(need,low_assignment,high_assignment)           \
    {var uintL __need = (uintL)(need);                                  \
     var uintD* __array = (uintD*)alloca(__need*sizeof(uintD));         \
     unused (low_assignment &__array[0]);                               \
     unused (high_assignment &__array[__need]);                         \
    }
  #define num_stack_need_1(need,low_assignment,high_assignment) \
    {var uintL __need = (uintL)(need)+1;                        \
     var uintD* __array = (uintD*)alloca(__need*sizeof(uintD)); \
     unused (low_assignment &__array[1]);                       \
     unused (high_assignment &__array[__need]);                 \
    }
#else
/* Use malloca/freea.
   num_stack is the first stack-allocated block. freea(num_stack) also frees
   all more recently allocated blocks. */
  #define SAVE_NUM_STACK  var void* num_stack = NULL;
  #define RESTORE_NUM_STACK  if (num_stack) freea(num_stack);
  #define num_stack_need(need,low_assignment,high_assignment)           \
    {var uintL __need = (uintL)(need);                                  \
     var uintD* __array = (uintD*)malloca(__need*sizeof(uintD));        \
     if (!num_stack) { num_stack = __array; }                           \
     unused (low_assignment &__array[0]);                               \
     unused (high_assignment &__array[__need]);                         \
    }
  #define num_stack_need_1(need,low_assignment,high_assignment)         \
    {var uintL __need = (uintL)(need)+1;                                \
     var uintD* __array = (uintD*)malloca(__need*sizeof(uintD));        \
     if (!num_stack) { num_stack = __array; }                           \
     unused (low_assignment &__array[1]);                               \
     unused (high_assignment &__array[__need]);                         \
    }
#endif

#endif /* LISPARIT */

/* Returns 2^n, n being a constant expression.
   Returns the same value as bit(n), is however undefined if n<0 or n>=32. */
#define bitc(n)  (1UL << (((n) >= 0 && (n) < intLsize) ? (n) : 0))

#if defined(HAVE_LONG_LONG_INT) || defined(MICROSOFT)
/* Returns 2^n, n being a constant expression.
   Returns the same value as wbit(n), is however undefined if n<0 or n>=64. */
  #define wbitc(n)  (ULL(1) << (((n) >= 0 && (n) < 2*intLsize) ? (n) : 0))
#endif

#ifdef LISPARIT

/* Error message for division by zero */
nonreturning_function(local, divide_0, (void)) {
  pushSTACK(TheSubr(subr_self)->name); /* slot :OPERATION */
  pushSTACK(NIL);               /* slot :OPERANDS not available */
  pushSTACK(TheSubr(subr_self)->name);
  error(division_by_zero,GETTEXT("~S: division by zero"));
}

/* Error message for floating point overflow
 error_overflow(); */
nonreturning_function(local, error_overflow, (void)) {
  pushSTACK(TheSubr(subr_self)->name); /* slot :OPERATION */
  pushSTACK(NIL);               /* slot :OPERANDS not available */
  pushSTACK(TheSubr(subr_self)->name);
  error(floating_point_overflow,GETTEXT("~S: floating point overflow"));
}

/* Error message for floating point underflow
 error_underflow(); */
nonreturning_function(local, error_underflow, (void)) {
  pushSTACK(TheSubr(subr_self)->name); /* slot :OPERATION */
  pushSTACK(NIL);               /* slot :OPERANDS not available */
  pushSTACK(TheSubr(subr_self)->name);
  error(floating_point_underflow,GETTEXT("~S: floating point underflow"));
}

/* Checks if floating point underflow is allowed
 underflow_allowed() */
#define underflow_allowed() (nullpSv(inhibit_floating_point_underflow))

#endif /* LISPARIT */

