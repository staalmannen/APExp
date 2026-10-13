/* Conversions between Floating-Point Numbers
 German comments and names translated into English: Reini Urban 2007-11

 Conversions without rounding:

 SF_to_FF(x) converts a Short-Float x into a Single-Float.
 can trigger GC */
local maygc object SF_to_FF (object x)
{
  /* If
     1. no conversion for the exponent necessary,
     2. sign/exponent/mantissa is in the  SF (as in the FF) tightly packed,
     3. the shift, which benhances the mantissa, moves the sign to bit 31,
     it can be shifted simply. */
#if (SF_exp_len==FF_exp_len) && (SF_exp_low>=FF_exp_low) && (SF_exp_mid==FF_exp_mid) && (SF_exp_high<=FF_exp_high) && (sign_bit_o==SF_exp_len+SF_exp_shift)
  /* So also 31-sign_bit_o = 31-SF_exp_len-SF_exp_shift
                           = 31-FF_exp_len-SF_mant_len-SF_mant_shift
                           = FF_mant_len-SF_mant_len-SF_mant_shift */
  return allocate_ffloat(((uint32)(as_oint(x) >> SF_mant_shift)
                          << (FF_mant_len-SF_mant_len)));
#else
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  var uint32 mant;
  SF_decode(x, { return FF_0; }, sign=,exp=,mant=);
  /* shift mantissa by 23-16=7 Bits to the left: */
  encode_FF(sign,exp,mant<<(FF_mant_len-SF_mant_len), return);
#endif
}

/* SF_to_DF(x) converts a Short-Float x into a Double-Float.
 can trigger GC */
local maygc object SF_to_DF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  var uint32 mant;
  SF_decode(x, { return DF_0; }, sign=,exp=,mant=);
  /* enhance mantissa by 52-16=36 zero-bits: */
  #ifdef intQsize
  encode_DF(sign,exp,(uint64)mant<<(DF_mant_len-SF_mant_len), return);
  #else
  encode2_DF(sign,exp,mant<<(DF_mant_len-SF_mant_len-32),0, return);
  #endif
}

/* SF_to_LF(x,len) converts a Short-Float x into a Long-Float with len digits.
 > uintC len: wanted number of digits, >=LF_minlen
 can trigger GC */
local maygc object SF_to_LF (object x, uintC len)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uint32 mant;
  SF_decode(x, { encode_LF0(len, return); }, sign=,exp=(sintL),mant=);
  /* alloc Long-Float,
     fill mantissa with intDsize*len-SF_mant_len-1 Null-Bits: */
  var object y = allocate_lfloat(len,exp+LF_exp_mid,sign);
  var uintD* ptr = &TheLfloat(y)->data[0];
  /* fill first k := ceiling(SF_mant_len+1,intDsize) digits with mant: */
  mant = mant << (ceiling(SF_mant_len+1,intDsize)*intDsize-(SF_mant_len+1));
  set_max32_Dptr(SF_mant_len+1,ptr,mant);
  clear_loop_up(&ptr[ceiling(SF_mant_len+1,intDsize)],len-ceiling(SF_mant_len+1,intDsize));
  return y;
}

/* FF_to_DF(x) converts a Single-Float x into a Double-Float.
 can trigger GC */
local maygc object FF_to_DF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  var uint32 mant;
  FF_decode(x, { return DF_0; }, sign=,exp=,mant=);
  /* extend mantissa by 52-23=29 Null-Bits: */
  #ifdef intQsize
  encode_DF(sign,exp,(uint64)mant<<(DF_mant_len-FF_mant_len), return);
  #else
  encode2_DF(sign,exp,mant>>(32-(DF_mant_len-FF_mant_len)),mant<<(DF_mant_len-FF_mant_len), return);
  #endif
}

/* FF_to_LF(x,len) converts a Single-Float x into a Long-Float with len digits.
 > uintC len: wanted number of digits, >=LF_minlen
 can trigger GC */
local maygc object FF_to_LF (object x, uintC len)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uint32 mant;
  FF_decode(x, { encode_LF0(len, return); }, sign=,exp=(sintL),mant=);
  /* malloc Long-Float,
     fill Mantissa with intDsize*len-FF_mant_len-1 Null-Bits: */
  var object y = allocate_lfloat(len,exp+LF_exp_mid,sign);
  var uintD* ptr = &TheLfloat(y)->data[0];
  /* first fill k := ceiling(FF_mant_len+1,intDsize) digits with mant: */
  mant = mant << (ceiling(FF_mant_len+1,intDsize)*intDsize-(FF_mant_len+1));
  set_max32_Dptr(FF_mant_len+1,ptr,mant);
  clear_loop_up(&ptr[ceiling(FF_mant_len+1,intDsize)],len-ceiling(FF_mant_len+1,intDsize));
  return y;
}

/* DF_to_LF(x,len) converts a Double-Float x into a Long-Float with len digits.
 > uintC len: wanted number of digits, >=LF_minlen
 can trigger GC */
local maygc object DF_to_LF (object x, uintC len)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uint32 manthi;
  var uint32 mantlo;
  #ifdef intQsize
  var uint64 mant;
  DF_decode(x, { encode_LF0(len, return); }, sign=,exp=(sintL),mant=);
  #else
  DF_decode2(x, { encode_LF0(len, return); }, sign=,exp=(sintL),manthi=,mantlo=);
  #endif
  /* malloc Long-Float,
     fill mantissa with intDsize*len-DF_mant_len-1 Null-Bits: */
  var object y = allocate_lfloat(len,exp+LF_exp_mid,sign);
  var uintD* ptr = &TheLfloat(y)->data[0];
  /* fill first k := ceiling(DF_mant_len+1,intDsize) digits with mantissa */
  #define shiftcount  (ceiling(DF_mant_len+1,intDsize)*intDsize-(DF_mant_len+1))
  #ifdef intQsize
  mant = mant<<shiftcount;
  manthi = (uint32)(mant>>32); mantlo = (uint32)mant;
  #else
  manthi = (manthi<<shiftcount) | (mantlo>>(32-shiftcount));
  mantlo = mantlo<<shiftcount;
  #endif
  #undef shiftcount
  set_max32_Dptr(DF_mant_len+1-32,ptr,manthi);
  set_32_Dptr(&ptr[ceiling(DF_mant_len+1-32,intDsize)],mantlo);
  clear_loop_up(&ptr[ceiling(DF_mant_len+1,intDsize)],len-ceiling(DF_mant_len+1,intDsize));
  return y;
}


/* Conversions with rounding: */

/* FF_to_SF(x) converts a Single-Float x into a Short-Float. */
local object FF_to_SF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  var uint32 mant;
  FF_decode(x, { return SF_0; }, sign=,exp=,mant=);
  /* round away 23-16 Bits: */
  #define shiftcount  (FF_mant_len-SF_mant_len)
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 6 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 5..0 >0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round downwards */
    mant = mant >> shiftcount;
  } else {
    /* round upwards */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(SF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_SF(sign,exp,mant, return);
}

/* DF_to_SF(x) converts a Double-Float x into a Short-Float. */
local object DF_to_SF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  #ifdef intQsize
  var uint64 mant;
  DF_decode(x, { return SF_0; }, sign=,exp=,mant=);
  /* round away 52-16=36 Bits: */
  #define shiftcount  (DF_mant_len-SF_mant_len)
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 35 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 34..0 >0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round downwards */
    mant = mant >> shiftcount;
  } else {
    /* round upwards */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(SF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_SF(sign,exp,mant, return);
  #else
  var uint32 manthi;
  var uint32 mantlo;
  DF_decode2(x, { return SF_0; }, sign=,exp=,manthi=,mantlo=);
  /* round away 52-16=36 Bits: */
  #define shiftcount  (DF_mant_len-SF_mant_len-32)
  if ( ((manthi & bit(shiftcount-1)) ==0) /* Bit 35 was 0 -> round downwards */
       || ( ((manthi & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 34..0 >0 -> round upwards */
            && (mantlo==0)
            /* round-to-even */
            && ((manthi & bit(shiftcount)) ==0))) {
    /* round downwards */
    manthi = manthi >> shiftcount;
  } else {
    /* round upwards */
    manthi = manthi >> shiftcount;
    manthi = manthi+1;
    if (manthi >= bit(SF_mant_len+1)) {
      /* rounding overflow */
      manthi = manthi>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_SF(sign,exp,manthi, return);
  #endif
}

/* LF_to_SF(x) converts a Long-Float x into a Short-Float. */
local object LF_to_SF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uintD* ptr;
  var uintC len;
  var uint32 mant;
  LF_decode(x, { return SF_0; }, sign=,exp=,ptr=,len=,);
  /* round away intDsize*len-SF_mant_len-1 Bits of the mantissa:
     get first k := ceiling(SF_mant_len+2,intDsize) digits of mant: */
  mant = get_max32_Dptr(SF_mant_len+2,ptr);
  ptr += ceiling(SF_mant_len+2,intDsize);
  #define shiftcount  (ceiling(SF_mant_len+2,intDsize)*intDsize-(SF_mant_len+1))
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 14 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 13..0 >0 -> round upwards */
            && !test_loop_up(ptr,len-ceiling(SF_mant_len+2,intDsize)) /* more Bits /=0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round downwards */
    mant = mant >> shiftcount;
  } else {
    /* round upwards */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(SF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_SF(sign,exp,mant, return);
}

/* DF_to_FF(x) converts a Double-Float x into a Single-Float.
 can trigger GC */
local maygc object DF_to_FF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintWL exp;
  #ifdef intQsize
  var uint64 mant;
  DF_decode(x, { return FF_0; }, sign=,exp=,mant=);
  /* Round away 52-23=29 bits: */
  #define shiftcount  (DF_mant_len-FF_mant_len)
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 28 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 27..0 >0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round downwards */
    mant = mant >> shiftcount;
  } else {
    /* round upwards */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(FF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_FF(sign,exp,mant, return);
  #else
  var uint32 manthi;
  var uint32 mantlo;
  DF_decode2(x, { return FF_0; }, sign=,exp=,manthi=,mantlo=);
  /* round away 52-23=29 Bits: */
  #define shiftcount  (DF_mant_len-FF_mant_len)
  manthi = (manthi << (32-shiftcount)) | (mantlo >> shiftcount);
  if ( ((mantlo & bit(shiftcount-1)) ==0) /* Bit 28 was 0 -> round downwards */
       || ( ((mantlo & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 27..0 >0 -> round upwards */
            /* round-to-even */
            && ((mantlo & bit(shiftcount)) ==0))) {
    /* round downwards */
  } else {
    /* round upwards */
    manthi = manthi+1;
    if (manthi >= bit(FF_mant_len+1)) {
      /* rounding overflow */
      manthi = manthi>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  #undef shiftcount
  encode_FF(sign,exp,manthi, return);
  #endif
}

/* LF_to_FF(x) converts a Long-Float x into a Single-Float.
 can trigger GC */
local maygc object LF_to_FF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uintD* ptr;
  var uintC len;
  var uint32 mant;
  LF_decode(x, { return FF_0; }, sign=,exp=,ptr=,len=,);
  /* round away intDsize*len-FF_mant_len-1 Bits of the mantissa:
     get first k := ceiling(FF_mant_len+2,intDsize) digits to mant: */
  mant = get_max32_Dptr(FF_mant_len+2,ptr);
  ptr += ceiling(FF_mant_len+2,intDsize);
  #define shiftcount  (ceiling(FF_mant_len+2,intDsize)*intDsize-(FF_mant_len+1))
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 7 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 6..0 >0 -> round upwards */
            && !test_loop_up(ptr,len-ceiling(FF_mant_len+2,intDsize)) /* more Bits /=0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round to lower */
    mant = mant >> shiftcount;
  } else {
    /* round to upper */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(FF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* move mantissa right */
    }
  }
  #undef shiftcount
  encode_FF(sign,exp,mant, return);
}

/* LF_to_DF(x) converts a Long-Float x into a Double-Float.
 can trigger GC */
local maygc object LF_to_DF (object x)
{
  /* unpack x: */
  var signean sign;
  var sintL exp;
  var uintD* ptr;
  var uintC len;
  var uint32 manthi;
  var uint32 mantlo;
  LF_decode(x, { return DF_0; }, sign=,exp=,ptr=,len=,);
  /* round away intDsize*len-DF_mant_len-1 Bits of the mantissa: */
  /* get first k := ceiling(DF_mant_len+2,intDsize) digits to manthi,mantlo: */
  manthi = get_max32_Dptr(DF_mant_len+2-32,ptr);
  mantlo = get_32_Dptr(&ptr[ceiling(DF_mant_len+2-32,intDsize)]);
  ptr += ceiling(DF_mant_len+2,intDsize);
  #define shiftcount  (ceiling(DF_mant_len+2,intDsize)*intDsize-(DF_mant_len+1))
  #ifdef intQsize
  var uint64 mant = ((uint64)manthi << 32) | (uint64)mantlo;
  if ( ((mant & bit(shiftcount-1)) ==0) /* Bit 10 was 0 -> round downwards */
       || ( ((mant & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 9..0 >0 -> round upwards */
            && !test_loop_up(ptr,len-ceiling(DF_mant_len+2,intDsize)) /* more Bits /=0 -> round upwards */
            /* round-to-even */
            && ((mant & bit(shiftcount)) ==0))) {
    /* round to lower */
    mant = mant >> shiftcount;
  } else {
    /* round to upper */
    mant = mant >> shiftcount;
    mant = mant+1;
    if (mant >= bit(DF_mant_len+1)) {
      /* rounding overflow */
      mant = mant>>1; exp = exp+1; /* shift mantissa right */
    }
  }
  encode_DF(sign,exp,mant, return);
  #else
  if ( ((mantlo & bit(shiftcount-1)) ==0) /* Bit 10 was 0 -> round to lower */
       || ( ((mantlo & (bit(shiftcount-1)-1)) ==0) /* was 1, Bits 9..0 >0 -> round to upper */
            && !test_loop_up(ptr,len-ceiling(DF_mant_len+2,intDsize)) /* more Bits /=0 -> round up */
            /* round-to-even */
            && ((mantlo & bit(shiftcount)) ==0))) {
    /* round to lower */
    mantlo = (manthi << (32-shiftcount)) | (mantlo >> shiftcount);
    manthi = manthi >> shiftcount;
  } else {
    /* round to upper */
    mantlo = (manthi << (32-shiftcount)) | (mantlo >> shiftcount);
    manthi = manthi >> shiftcount;
    mantlo = mantlo+1;
    if (mantlo==0) {
      manthi = manthi+1;
      if (manthi >= bit(DF_mant_len+1-32)) {
        /* rounding overflow */
        manthi = manthi>>1; exp = exp+1; /* shift mantissa right */
      }
    }
  }
  encode2_DF(sign,exp,manthi,mantlo, return);
  #endif
  #undef shiftcount
}


/* Conversions to IEEE-Floats. */

/* NaN error message
 error_nan(); */
nonreturning_function(local, error_nan, (void)) {
  pushSTACK(TheSubr(subr_self)->name); /* slot :OPERATION */
  pushSTACK(NIL);               /* slot :OPERANDS not available */
  pushSTACK(TheSubr(subr_self)->name);
  error(arithmetic_error,GETTEXT("~S: floating point NaN occurred"));
}

/* IEEE-Single-Float:
 Bit 31 = s, Bits 30..23 = e, Bits 22..0 = m.
 e=0, m=0: signed 0.0
 e=0, m/=0: subnormal number,
   Value = (-1)^s * 2^(1-126) * [ 0 . 0 m22 ... m0 ]
 1 <= e <= 254 : normalised number,
   Value = (-1)^s * 2^(e-126) * [ 0 . 1 m22 ... m0 ]
 e=255, m=0: signed Infinity
 e=255, m/=0: NaN

 c_float_to_FF(&val) converts a IEEE-Single-Float val into a Single-Float.
 can trigger GC */
modexp maygc object c_float_to_FF (const ffloatjanus* val_)
{
  var ffloat val = val_->eksplicit;
  var uintBWL exp = (val >> FF_mant_len) & (bit(FF_exp_len)-1); /* e */
  if (exp == 0) { /* e=0 ? */
    /* signed 0.0 or subnormal number */
    if (!((val << 1) == 0) && underflow_allowed())
      error_underflow();
    else
      return FF_0; /* +/- 0.0 -> 0.0 */
  } else if (exp == 255) { /* e=255 ? */
    if (!((val << (32-FF_mant_len)) == 0))
      error_nan(); /* NaN */
    else
      error_overflow(); /* Infinity, Overflow */
  } else {
    /* The exponent must be increased by FF_exp_mid-126 */
    if ((FF_exp_mid>126) && (exp > FF_exp_high-FF_exp_mid+126))
      error_overflow(); /* Overflow */
    val += (FF_exp_mid - 126) << FF_mant_len;
    return allocate_ffloat(val);
  }
}

/* FF_to_c_float(obj,&val);
 converts a Single-Float obj into a IEEE-Single-Float val. */
modexp void FF_to_c_float (object obj, ffloatjanus* val_)
{
  var ffloat val = ffloat_value(obj);
  /* The exponent must be decreased by FF_exp_mid-126 */
  if (FF_exp_mid>126) {
    var uintBWL exp = (val >> FF_mant_len) & (bit(FF_exp_len)-1); /* e */
    if (exp < FF_exp_mid-126+1) {
      if (exp != 0) {
        /* produce denormalized float */
        val = (val & minus_bit(FF_exp_len+FF_mant_len)) /* same sign */
              | (0 << FF_mant_len) /* Exponent 0 */
              | (((val & (bit(FF_mant_len)-1)) | bit(FF_mant_len)) /* shift mantissa */
                 >> (FF_exp_mid-126+1 - exp)); /* shift */
      }
    } else {
      val -= (FF_exp_mid - 126) << FF_mant_len;
    }
  }
  val_->eksplicit = val;
}

/* IEEE-Double-Float:
 Bit 63 = s, Bits 62..52 = e, Bits 51..0 = m.
 e=0, m=0:  signed 0.0
 e=0, m/=0: subnormal number,
   Value = (-1)^s * 2^(1-1022) * [ 0 . 0 m51 ... m0 ]
 1 <= e <= 2046 : normalised number,
   Value = (-1)^s * 2^(e-1022) * [ 0 . 1 m51 ... m0 ]
 e=2047, m=0: signed Infinity
 e=2047, m/=0: NaN

 c_double_to_DF(&val) converts a IEEE-Double-Float val into a Double-Float.
 can trigger GC */
modexp maygc object c_double_to_DF (const dfloatjanus* val_)
{
  var dfloat val; val = val_->eksplicit;
  #ifdef intQsize
  var uintWL exp = (val >> DF_mant_len) & (bit(DF_exp_len)-1); /* e */
  if (exp == 0) { /* e=0 ? */
    /* signed 0.0 or subnormal number */
    if (!((val << 1) == 0) && underflow_allowed())
      error_underflow();
    else
      return DF_0; /* +/- 0.0 -> 0.0 */
  } else if (exp == 2047) { /* e=2047 ? */
    if (!((val << (64-DF_mant_len)) == 0))
      error_nan(); /* NaN */
    else
      error_overflow(); /* Infinity, Overflow */
  } else {
    /* The exponent must be increased by DF_exp_mid-1022 */
    if ((DF_exp_mid>1022) && (exp > DF_exp_high-DF_exp_mid+1022))
      error_overflow(); /* Overflow */
    val += (sint64)(DF_exp_mid - 1022) << DF_mant_len;
    return allocate_dfloat(val);
  }
  #else
  var uintWL exp = (val.semhi >> (DF_mant_len-32)) & (bit(DF_exp_len)-1); /* e */
  if (exp == 0) { /* e=0 ? */
    /* signed 0.0 or subnormal number */
    if (!(((val.semhi << 1) == 0) && (val.mlo == 0)) && underflow_allowed())
      error_underflow();
    else
      return DF_0; /* +/- 0.0 -> 0.0 */
  } else if (exp == 2047) { /* e=2047 ? */
    if (!(((val.semhi << (64-DF_mant_len)) == 0) && (val.mlo == 0)))
      error_nan(); /* NaN */
    else
      error_overflow(); /* Infinity, Overflow */
  } else {
    /* The exponent must be increased by DF_exp_mid-1022 */
    if ((DF_exp_mid>1022) && (exp > DF_exp_high-DF_exp_mid+1022))
      error_overflow(); /* Overflow */
    val.semhi += (sint32)(DF_exp_mid - 1022) << (DF_mant_len-32);
    return allocate_dfloat(val.semhi,val.mlo);
  }
  #endif
}

/* DF_to_c_double(obj,&val);
 Converts a Double-Float obj into a IEEE-Double-Float val. */
modexp void DF_to_c_double (object obj, dfloatjanus* val_)
{
  var dfloat val; val = TheDfloat(obj)->float_value;
  /* The exponent must be decreased by DF_exp_mid-1022. */
  if (DF_exp_mid>1022) {
    #ifdef intQsize
    var uintWL exp = (val >> DF_mant_len) & (bit(DF_exp_len)-1); /* e */
    if (exp < DF_exp_mid-1022+1) {
      if (exp != 0) {
        /* produce denormalised float */
        val = (val & minus_bit(DF_exp_len+DF_mant_len)) /* same sign */
              | ((sint64)0 << DF_mant_len) /* Exponent 0 */
              | (((val & (bit(DF_mant_len)-1)) | bit(DF_mant_len)) /* shift mantissa */
                 >> (DF_exp_mid-1022+1 - exp)); /* shift */
      }
    } else {
      val -= (sint64)(DF_exp_mid - 1022) << DF_mant_len;
    }
    #else
    var uintWL exp = (val.semhi >> (DF_mant_len-32)) & (bit(DF_exp_len)-1); /* e */
    if (exp < DF_exp_mid-1022+1) {
      if (exp != 0) {
        /* produce denormalised float */
        var uintWL shiftcount = DF_exp_mid-1022+1 - exp;
        val.mlo = val.mlo >> shiftcount; /* shift mantissa */
        val.mlo |= val.semhi << (32-shiftcount);
        val.semhi = (val.semhi & minus_bit(DF_exp_len+DF_mant_len-32)) /* same sign */
                    | ((sint32)0 << (DF_mant_len-32)) /* Exponent 0 */
                    | (((val.semhi & (bit(DF_mant_len-32)-1)) | bit(DF_mant_len-32)) /* shift mantissa */
                       >> shiftcount); /* shift */
      }
    } else {
      val.semhi -= (sint32)(DF_exp_mid - 1022) << (DF_mant_len-32);
    }
    #endif
  }
  val_->eksplicit = val;
}

