/*
 *  Transcendental functions for complex numbers
 *  German comments and names translated into English: Reini Urban 2007-11
 */

/* N_phase_R(x,want_exact) returns (phase x), being x a number.
 Result is rational only when (= x 0) or if x is real and >0.
 can trigger GC */
local maygc object N_phase_R (object x, bool want_exact);
/* Method:
 (= x 0)   -> random result 0
 x real    -> angle of (x,0) in polar coordinates
 x complex -> angle of ((realpart x),(imagpart x)) in polar coordinates */
local maygc object N_phase_R (object x, bool want_exact)
{
  if (N_realp(x)) {
    /* For nonnegative real numbers, the natural mathematical result is the
       exact 0. But ANSI CL wants a floating-point 0.0 result. If x is a non-
       negative float, *FLOATING-POINT-RATIONAL-CONTAGION-ANSI* achieves this.
       If x is a nonnegative rational number, we look at *PHASE-ANSI*. */
    if (!R_minusp(x)) {
      if (want_exact)
        return Fixnum_0;
      else if (R_rationalp(x))
        return (nullpSv(phase_ansi) ? Fixnum_0 : I_float_F(Fixnum_0));
      else
        return RA_F_exact_contagion_R(Fixnum_0,x);
    } else
      return R_R_atan_R(x,Fixnum_0);
  } else { /* Special case (= x 0). */
    if (N_zerop(x)) {
      if (want_exact)
        return Fixnum_0;
      else {
        var object fx = R_R_contagion_R(TheComplex(x)->c_real,
                                        TheComplex(x)->c_imag);
        return RA_F_exact_contagion_R(Fixnum_0,fx);
      }
    } else
      return R_R_atan_R(TheComplex(x)->c_real,TheComplex(x)->c_imag);
  }
}

/* Bind S to NIL or itself, depending on v */
#define maybe_rebind(s,v)  dynamic_bind(s,v ? NIL : (object)Symbol_value(s))

/* N_exp_N(x) returns (exp x), being x a number.
 can trigger GC
 Method:
 x real -> straightforward.
 x = a+bi -> (exp a) with (cos b) + i (sin b) multiply:
             (complex (* (exp a) (cos b)) (* (exp a) (sin b))) */
local maygc object N_exp_N (object x, bool start_p, gcv_object_t* end_p)
{
  if (N_realp(x)) {
    return R_exp_R(x,start_p,end_p);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    pushSTACK(R_R_contagion_R(STACK_0,STACK_1));
    /* since x is complex, the result is a float anyway */
    if (R_rationalp(STACK_1)) /* b */
      STACK_1 = RA_R_float_F(STACK_1,STACK_0);
    if (R_rationalp(STACK_2)) /* a */
      STACK_2 = RA_R_float_F(STACK_2,STACK_0);
    var bool same_precision = (F_float_digits(STACK_2) == F_float_digits(STACK_1));
    R_cos_sin_R_R(STACK_1,start_p,NULL); /* (cos b), (sin b) */
    /* Stack layout: a, b, contagion, cos(b), sin(b).
       b != Fixnum_0 ==> sin(b) != Fixnum_0. */
    STACK_2 = R_exp_R(STACK_4,true,NULL); /* (exp a) */
    /* Stack layout: a, exp(a), cos(b), sin(b). */
    var object temp;
    /* Bind variables, to avoid unjustified contagion warnings. */
    maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
    dynamic_bind(S(floating_point_contagion_ansi),NIL);
    temp = R_R_mult_R(STACK_(2+6),STACK_(0+6)); /* (* (exp a) (sin b)) != Fixnum_0 */
    STACK_(0+6) = F_R_float_F(temp,*end_p);
    temp = R_R_mult_R(STACK_(2+6),STACK_(1+6)); /* (* (exp a) (cos b)) */
    temp = F_R_float_F(temp,*end_p);
    dynamic_unbind(S(floating_point_contagion_ansi));
    dynamic_unbind(S(warn_on_floating_point_contagion));
    temp = R_R_complex_C(temp,STACK_0); /* (complex ... ...) */
    skipSTACK(5); return temp;
  }
}

/* N_log_abs_R(z,&end_precision) returns (log (abs z)), z being a number
 can trigger GC
 Method: (/ (log (+ x^2 y^2)) 2) */
local maygc object R_R_norm2_1_R (object x, object y) {
  /* helper for N_log_abs_R: for abs(x)>=abs(y), compute (x+1)(x-1)+y^2 */
  pushSTACK(x); pushSTACK(R_square_R(y));
  pushSTACK(R_1_plus_R(STACK_1));
  STACK_2 = R_minus1_plus_R(STACK_2);
  STACK_0 = R_R_mult_R(STACK_0,STACK_2);
  { var object tmp = R_R_plus_R(STACK_0,STACK_1);
    skipSTACK(3); return tmp; }
}
local maygc object N_log_abs_R (object z, gcv_object_t *end_p) {
  if (N_realp(z)) {
    z = R_abs_R(z);
    if (R_zerop(z))
      divide_0();
    return R_ln_R(z,end_p);
  } else { /* 1/2 * lnx1 (x^2 + y^2 - 1) */
    pushSTACK(z);
    pushSTACK(R_abs_R(TheComplex(z)->c_real));
    pushSTACK(R_abs_R(TheComplex(STACK_1)->c_imag));
    if (R_zerop(STACK_0) && R_zerop(STACK_1))
      divide_0();
    if (   R_R_comp(STACK_0,SF_two_thirds) < 0
        && R_R_comp(STACK_1,SF_two_thirds) < 0) {
      /* z is small ==> log(x^2 + y^2) */
      STACK_0 = R_square_R(STACK_0); /* y^2 */
      STACK_1 = R_square_R(STACK_1); /* x^2 */
      z = R_R_plus_R(STACK_1,STACK_0); /* x^2 + y^2 */
      z = R_ln_R(z,end_p);             /* log (x^2 + y^2) */
    } else {                  /* z is big => log(1 + (x^2 + y^2 - 1)) */
      z = R_R_comp(STACK_0,STACK_1) < 0
        ? R_R_norm2_1_R(TheComplex(STACK_2)->c_real,
                        TheComplex(STACK_2)->c_imag)
        : R_R_norm2_1_R(TheComplex(STACK_2)->c_imag,
                        TheComplex(STACK_2)->c_real);
      if (R_R_equal(z,Fixnum_minus1))
        divide_0();
      z = R_ln1_R(z,end_p);     /* log(1 + (x^2 + y^2 - 1)) */
    }
    z = floatp(z)               /* log(x^2 + y^2)/2 */
      ? F_I_scale_float_F(z,Fixnum_minus1)
      : RA_RA_div_RA(z,fixnum(2));
    skipSTACK(3);
    return z;
  }
}

/* N_log_N(x,&end_precision) returns (log x), x being a number.
 can trigger GC
 Method:
  (complex (log (abs x)) (phase x)) */
local maygc object N_log_N (object x, gcv_object_t *end_p)
{
  pushSTACK(x); /* save x */
  /* Increase precision: */
  if (floatp(STACK_0))
    STACK_0 = F_extend_F(STACK_0);
  else if (complexp(STACK_0)
           && (floatp(TheComplex(STACK_0)->c_real)
               || floatp(TheComplex(STACK_0)->c_imag))) {
    var object realpart = TheComplex(STACK_0)->c_real;
    if (floatp(realpart))
      realpart = F_extend_F(realpart);
    pushSTACK(realpart);
    var object imagpart = TheComplex(STACK_(0+1))->c_imag;
    if (floatp(imagpart))
      imagpart = F_extend_F(imagpart);
    realpart = popSTACK();
    STACK_0 = R_R_complex_C(realpart,imagpart);
  }
  pushSTACK(N_log_abs_R(STACK_0,end_p)); /* (log (abs x)) */
  STACK_1 = N_phase_R(STACK_1,true); /* (phase x) */
  if (end_p != NULL && floatp(STACK_1))
    STACK_1 = F_R_float_F(STACK_1,*end_p);
  { /* (complex (log (abs x)) (phase x)) */
    var object ret = R_R_complex_N(STACK_0,STACK_1);
    skipSTACK(2); return ret;
  }
}

#define C_rationalp(x)  (R_rationalp(TheComplex(x)->c_real) && R_rationalp(TheComplex(x)->c_imag))

/* N_N_log_N(a,b) returns (log a b), where a and b are numbers.
 can trigger GC */
local maygc object N_N_log_N (object a, object b);
/* Method:
  (log a b) =
   if b real, >0:
     (complex (/ (log (abs a)) (log b)) (/ (phase a) (log b))), more exactly:
     if a real, >0: known
     if (= a 0): Error
     else: (phase a) calculate, a float.
            b (if rational) convert into same float format,
            imagpart := (/ (phase a) (log this_b)).
            if a rational: (log (abs a) b).
            if a complex with rational real- and imagpart,
              exact calculation of (expt (abs a) 2) as
              (+ (expt (realpart a) 2) (expt (imagpart a) 2)).
              set realpart := (/ (log quadrat_of b) 2).
              [Eventually (log b) will be calculated here twice,
               but only in single precision.]
            else do (abs a), a float, and (log (abs a)), a float,
              convert b (if rational) into the same float format,
              set realpart := (/ (log (abs a)) (log this_b)).
   else: (/ (log a) (log b)) */
local maygc object N_N_log_N (object a, object b)
{
  if (N_realp(b) && R_plusp(b)) {
    /* b is real and >0 */
    if (N_realp(a) && R_plusp(a)) { /* a and b are both real and >0 */
      return R_R_log_R(a,b);
    } else { /* b is real and >0, but a not */
      pushSTACK(a); pushSTACK(b); /* save a,b */
      { /* calculate imagpart (/ (phase a) (log b)) : */
        var object angle = N_phase_R(a,true); /* (phase a) */
        if (eq(angle,Fixnum_0)) /* = fixnum 0 <==> (= a 0) -> Error */
          divide_0();
        /* divide by (log b), returns the imagpart: */
        pushSTACK(angle);
        b = STACK_1;
        if (R_rationalp(b))
          b = RA_F_float_F(b,angle,true);
        b = F_ln_F(b,&STACK_1); STACK_0 = F_F_div_F(STACK_0,b);
      }
      /* Stack layout: a, b, imagpart. */
      /* calculate realpart (/ (log (abs a)) (log b)): */
      a = STACK_2;
      if (N_realp(a)) {
        if (R_rationalp(a)) {
          /* calculate a rational -> (log (abs a) b): */
          a = R_abs_R(a); /* absolute value (>0) */
          pushSTACK(R_R_log_R(a,STACK_1));
          goto real_ok;
        }
      } else {
        if (C_rationalp(a)) {
          /* a complex with rational real- and imagpart a1,a2
             calculate squared value a1^2+a2^2: */
          pushSTACK(TheComplex(a)->c_imag);
          var object a1 = TheComplex(a)->c_real;
          a1 = RA_RA_mult_RA(a1,a1); /* a1*a1 */
          var object a2 = STACK_0; STACK_0 = a1;
          a1 = RA_RA_mult_RA(a2,a2); /* a2*a2 */
          a = RA_RA_plus_RA(STACK_0,a1);
          /* logarithm base b, div by 2: */
          STACK_0 = R_R_div_R(R_R_log_R(a,STACK_2),fixnum(2));
          goto real_ok;
        }
      }
      /* no chance for rational realpart */
      pushSTACK(N_log_abs_R(a,&STACK_3)); /* (log (abs a)), a float */
      /* divide by (log b), return the realpart: */
      b = STACK_2;
      if (R_rationalp(b))
        b = RA_F_float_F(b,STACK_0,true);
      b = F_ln_F(b,&STACK_2); STACK_0 = F_F_div_F(STACK_0,b);
     real_ok: { /* Stack layout: a, b, imagpart, realpart. */
        var object erg = R_R_complex_C(STACK_0,STACK_1);
        skipSTACK(4); return erg;
      }
    }
  } else { /* normal complex case */
    pushSTACK(a); pushSTACK(b);
    STACK_1 = N_log_N(STACK_1,&STACK_1); /* (log a) */
    STACK_0 = N_log_N(STACK_0,&STACK_0); /* (log b) */
    a = N_N_div_N(STACK_1,STACK_0); /* divide */
    skipSTACK(2); return a;
  }
}

/* N_I_expt_N(x,y) = (expt x y), being x a number and y an integer.
 can trigger GC */
local maygc object N_I_expt_N (object x, object y);
/* Method:
 for y>0:
   a:=x, b:=y.
   While b is even, set a:=a*a, b:=b/2. [a^b stays invariant, = x^y.]
   c:=a.
   While b:=floor(b/2) is >0,
     set a:=a*a, and if b is uneven, set c:=a*c.
   return c.
 for y=0: return 1.
 for y<0: (/ (expt x (- y))). */
local maygc object N_I_expt_N (object x, object y)
{
  if (N_realp(x)) /* x real -> faster function */
    return R_I_expt_R(x,y);
  if (eq(y,Fixnum_0)) {
    /* y=0 -> return 1 */
    if (C_rationalp(x)) {
      return Fixnum_1;
    } else {
      var object fx = R_R_contagion_R(TheComplex(x)->c_real,
                                      TheComplex(x)->c_imag);
      pushSTACK(fx);
      pushSTACK(RA_F_exact_contagion_R(Fixnum_0,fx));
      fx = STACK_1;
      STACK_1 = RA_F_exact_contagion_R(Fixnum_1,fx);
      var object z = R_R_complex_N(STACK_1,STACK_0);
      skipSTACK(2);
      return z;
    }
  }
  pushSTACK(x);
  /* take absolute of y: */
  var bool y_negative = false;
  if (R_minusp(y)) {
    y = I_minus_I(y); y_negative = true;
  }
  /* Now y>0. */
  pushSTACK(y);
  /* Stack layout: a, b. */
  while (!I_oddp(y)) {
    STACK_1 = N_square_N(STACK_1); /* a:=a*a */
    STACK_0 = y = I_I_ash_I(STACK_0,Fixnum_minus1); /* b := (ash b -1) */
  }
  pushSTACK(STACK_1); /* c:=a */
  /* Stack layout: a, b, c. */
  while (!eq(y=STACK_1,Fixnum_1)) { /* until b/=1 */
    STACK_1 = I_I_ash_I(y,Fixnum_minus1); /* b := (ash b -1) */
    var object a = STACK_2 = N_square_N(STACK_2); /* a:=a*a */
    if (I_oddp(STACK_1))
      STACK_0 = N_N_mult_N(a,STACK_0); /* evtl. c:=a*c */
  }
  x = STACK_0; skipSTACK(3);
  /* (expt x (abs y)) is now in x. */
  return (y_negative ? N_div_N(x) : x); /* evtl. return the reciprocal */
}

/* N_N_expt_N(x,y) = (expt x y), where x and y are numbers.
 can trigger GC */
local maygc object N_N_expt_N (object x, object y);
/* Method:
   If y rational:
     If y integer:
       If y=0: return 1,
         [Following CLTL:
           x real:
             x rational -> fixnum 1
             x float -> (float 1 x)
           x complex:
             x complex rational -> fixnum 1
             else: #C(1.0 0.0) in float format of the real- resp. the imaginary parts of x
         ]
       If x rational or complex rational or |y| is small:
         Calculate x^|y| by repeated squaring and multiplying and evtl. doing a
         reciprocical.
       Else same as with 'y float'.
     If y ratio m/n:
       It is valid (expt x m/n) = (expt (expt x 1/n) m).
       If x lies in Q(i) (so is rational or complex rational):
         Should x^(m/n) lie in Q(i), so also a n-th root x^(1/n)
         (and with n=2 or n=4, so also all n-th roots x^(1/n) ).
         If x rational >=0: take n-th root of x. If this is rational,
           its m-th power as result.
         If x is rational <=0 or komplex rational and n powers of two:
           Take n-th root of x (multiple sqrt). If this is rational or
           complex rational, return its m-th power as result.
           [Look at any n!??]
       If n powers of two and |m|,n small: Take n-th root of x
         (multiple sqrt), from this the m-th power by repetative
         quadratizing and multiplication and evtl. reciprocal.
       Else as with 'y float'.
   If y float or complex:
     If (zerop x):
       If realpart of y >0 :
         return 0.0 if x and y real, #C(0.0 0.0) otherwise.
       Else Error.
     If y=0.0:
       return 1.0 if x and y real, #C(1.0 0.0) otherwise.
     Otherwise: (exp (* (log x) y))
   The result lies in Q(i), if x lies in Q(i) and 4y is an integer.??
   Increase precision, log2(|y|) bits more??
   With x or y rational and the other long-float: please no single-float!?? */
local maygc object N_N_expt_N (object x, object y)
{
  if (N_realp(y) && R_rationalp(y)) {
    /* y rational */
    if (RA_integerp(y)) {
      /* y integer */
      if (eq(y,Fixnum_0)) {
        /* y=0 -> 1 in the format of x. */
        if (N_realp(x)) {
          if (R_rationalp(x))
            return Fixnum_1;
          else
            return RA_F_exact_contagion_R(Fixnum_1,x);
        } else {
          if (C_rationalp(x)) {
            return Fixnum_1;
          } else {
            var object fx = R_R_contagion_R(TheComplex(x)->c_real,
                                            TheComplex(x)->c_imag);
            pushSTACK(fx);
            pushSTACK(RA_F_exact_contagion_R(Fixnum_0,fx));
            fx = STACK_1;
            STACK_1 = RA_F_exact_contagion_R(Fixnum_1,fx);
            var object z = R_R_complex_N(STACK_1,STACK_0);
            skipSTACK(2);
            return z;
          }
        }
      }
      if (I_fixnump(y)) /* |y| small ? */
        return N_I_expt_N(x,y);
      if (N_realp(x)) {
        if (R_rationalp(x))
          return R_I_expt_R(x,y);
      } else {
        if (C_rationalp(x))
          return N_I_expt_N(x,y);
      }
    } else {
      /* y Ratio */
      if (N_realp(x)) {
        if (R_rationalp(x)) {
          if (R_minusp(x))
            goto complex_rational;
          /* x rational >=0 */
          pushSTACK(x); pushSTACK(y);
          var object temp = RA_rootp(x,TheRatio(y)->rt_den); /* try n-th root */
          if (!eq(temp,nullobj)) { /* root rational? */
            var object m = TheRatio(STACK_0)->rt_num;
            skipSTACK(2);
            return R_I_expt_R(temp,m); /* (x^(1/n))^m */
          }
          y = popSTACK(); x = popSTACK();
        }
      } else {
        if (C_rationalp(x)) {
         complex_rational: /* x in Q(i) */
          var uintL k = I_power2p(TheRatio(y)->rt_den);
          if (!(k==0)) {
            /* n powers of two = 2^(k-1). n>1, so k>1 */
            pushSTACK(TheRatio(y)->rt_num); /* save m */
            dotimespL(k,k-1, { x = N_sqrt_N(x); } ); /* k-1 times squareroot */
            return N_I_expt_N(x,popSTACK()); /* then power of m */
          }
        }
      }
      if (I_fixnump(TheRatio(y)->rt_num) /* |m| small */
          && I_fixnump(TheRatio(y)->rt_den) /* n small */
         ) {
        var uintV n = posfixnum_to_V(TheRatio(y)->rt_den);
        if ((n & (n-1)) == 0) { /* n powers of two? */
          pushSTACK(TheRatio(y)->rt_num); /* save m */
          while ((n = n>>1)) { x = N_sqrt_N(x); } /* take n-th root */
          return N_I_expt_N(x,popSTACK()); /* then power of m */
        }
      }
    }
  }
  /* common case (e.g. y float or complex): */
  if (N_zerop(x)) { /* x=0.0 ? */
    if (!R_plusp(N_realpart_R(y))) /* realpart of y <=0 ? */
      divide_0(); /* yes -> error */
    if (N_realp(x) && N_realp(y)) {
      x = R_R_contagion_R(x,y); /* a float, otherwise x would be fixnum 0 */
      return I_F_float_F(Fixnum_0,x); /* 0.0 */
    } else {
      if (!N_realp(x))
        x = R_R_contagion_R(TheComplex(x)->c_real,TheComplex(x)->c_imag);
      if (!N_realp(y))
        y = R_R_contagion_R(TheComplex(y)->c_real,TheComplex(y)->c_imag);
      x = R_R_contagion_R(x,y); /* float, otherwise x would be Fixnum 0 */
      x = I_F_float_F(Fixnum_0,x); /* 0.0 */
      return R_R_complex_C(x,x); /* #C(0.0 0.0) */
    }
  }
  if (N_zerop(y)) { /* y=0.0 ? */
    if (N_realp(x) && N_realp(y)) {
      x = R_R_contagion_R(x,y); /* float, otherwise y would be Fixnum 0 */
      return I_F_float_F(Fixnum_1,x); /* 1.0 */
    } else {
      if (!N_realp(x))
        x = R_R_contagion_R(TheComplex(x)->c_real,TheComplex(x)->c_imag);
      if (!N_realp(y))
        y = R_R_contagion_R(TheComplex(y)->c_real,TheComplex(y)->c_imag);
      x = R_R_contagion_R(x,y); /* float, otherwise y would be Fixnum 0 */
      x = I_F_float_F(Fixnum_0,x); /* 0.0 */
      pushSTACK(x);
      x = I_F_float_F(Fixnum_1,x); /* 1.0 */
      return R_R_complex_C(x,popSTACK()); /* #C(1.0 0.0) */
    }
  }
  pushSTACK(y);
  pushSTACK(x);
  pushSTACK(N_N_contagion_R(x,y));
  /* The number of precision bits needed is:
     the number d of mantissa bits  of this result
     + (sqrt(d)+2) as in F_extend_F
     + the exponent length of y. */
  var uintL prec = R_float_digits(STACK_0);
  {
    var uintL d = prec;
    var uintL s;
    integerlength32(d,s=);
    s = floor(32-s,2);
    d = d << (2*s);
    var uintL sqrtd;
    isqrt_32_16(d, sqrtd =, );
    sqrtd = sqrtd >> s;
    prec += sqrtd;
  }
  prec += 2;
  defaultfloatcase(S(default_float_format),STACK_2,
                   { prec += SF_exp_len-1; },
                   { prec += FF_exp_len-1; },
                   { prec += DF_exp_len-1; },
                   { prec += 31; },
                   ,);
  var object tempfloat;
  if (prec < 53)
    tempfloat = DF_0;
  else
    encode_LF0(ceiling(prec,intDsize),tempfloat=);
  pushSTACK(tempfloat);
  /* stack layout: y, x, resfloat, tempfloat. */
  var uintL x_prec = R_float_digits(STACK_2/*x*/);
  if (x_prec < F_float_digits(STACK_0))
    STACK_2 = N_N_float_N(STACK_2,STACK_0); /* extend precision of x */
  STACK_2 = N_log_N(STACK_2,NULL); /* (log x) */
  STACK_2 = N_N_float_N(STACK_2,STACK_0); /* rounded (log x) */
  STACK_4 = N_N_float_N(STACK_4,STACK_0); /* rounded y */
  var object temp = N_N_mult_N(STACK_2,STACK_4); /* (* (log x) y) */
  /* No need to re-extend the precision inside N_exp_N, because we have
     already chosen the needed precision. */
  var object result = N_exp_N(temp,false,&STACK_1); /* exp */
  skipSTACK(4); return result;
}

/* N_sin_N(x) returns (sin x), being x a number.
 can trigger GC
 Method:
 x real -> straightforward
 x = a+bi -> (complex (* (sin a) (cosh b)) (* (cos a) (sinh b))) */
local maygc object N_sin_N (object x)
{
  if (N_realp(x)) {
    return R_sin_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object temp = R_sinh_R(STACK_0); /* sinh(b), != Fixnum_0 */
      temp = R_R_complex_C(Fixnum_0,temp);
      skipSTACK(2); return temp;
    } else { /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cosh_sinh_R_R(STACK_0,NULL); /* cosh(b) sinh(b) */
      /* Stack layout: a, b, cosh(b), sinh(b).
         b != Fixnum_0 ==> sinh(b) != Fixnum_0. */
      R_cos_sin_R_R(STACK_3,true,NULL); /* cos(a)!=0, sin(a) */
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(1+6) = R_R_mult_R(STACK_(1+6),STACK_(4+6)); /* sin(a)*cosh(b), != Fixnum_0 */
      STACK_(2+6) = R_R_mult_R(STACK_(2+6),STACK_(3+6)); /* cos(a)*sinh(b), != Fixnum_0 */
      STACK_(1+6) = F_F_float_F(STACK_(1+6),STACK_(0+6));
      STACK_(2+6) = F_F_float_F(STACK_(2+6),STACK_(0+6));
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = R_R_complex_C(STACK_1,STACK_2);
      skipSTACK(7); return result;
    }
  }
}

/* N_cos_N(x) returns (cos x), being x a number.
 can trigger GC
 Method:
 x real -> straightforward
 x = a+bi -> (complex (* (cos a) (cosh b)) (- (* (sin a) (sinh b)))) */
local maygc object N_cos_N (object x)
{
  if (N_realp(x)) {
    return R_cos_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object result = R_cosh_R(STACK_0); /* cosh(b) */
      skipSTACK(2); return result;
    } else { /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cosh_sinh_R_R(STACK_0,NULL); /* cosh(b), sinh(b) */
      /* Stack layout: a, b, cosh(b), sinh(b). */
      R_cos_sin_R_R(STACK_3,true,NULL); /* cos(a), sin(a) */
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(1+6) = R_minus_R(R_R_mult_R(STACK_(1+6),STACK_(3+6))); /* -sin(a)*sinh(b), != Fixnum_0 */
      STACK_(2+6) = R_R_mult_R(STACK_(2+6),STACK_(4+6)); /* cos(a)*cosh(b), != Fixnum_0 */
      STACK_(1+6) = F_F_float_F(STACK_(1+6),STACK_(0+6));
      STACK_(2+6) = F_F_float_F(STACK_(2+6),STACK_(0+6));
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = R_R_complex_C(STACK_2,STACK_1);
      skipSTACK(7); return result;
    }
  }
}

/* N_tan_N(x) returns (tan x), being x a number.
 can trigger GC
 Method:
 x real -> (/ (sin x) (cos x))
 x = a+bi -> (/ (complex (* (sin a) (cosh b)) (* (cos a) (sinh b)))
                (complex (* (cos a) (cosh b)) (- (* (sin a) (sinh b)))) ) */
local maygc object N_tan_N (object x)
{
  if (N_realp(x)) {
    return R_tan_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object temp = R_tanh_R(STACK_0); /* tanh(b), != Fixnum_0 */
      temp = R_R_complex_C(Fixnum_0,temp);
      skipSTACK(2); return temp;
    } else {
      /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cosh_sinh_R_R(STACK_0,NULL); /* cosh(b), sinh(b) */
      /* Stack layout: a, b, cosh(b), sinh(b). */
      R_cos_sin_R_R(STACK_3,true,NULL); /* cos(a), sin(a) */
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cosh(b), sinh(b), cos(a), sin(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(6+6) = R_R_mult_R(STACK_(1+6),STACK_(4+6)); /* sin(a)*cosh(b) */
      var object temp = R_R_mult_R(STACK_(2+6),STACK_(3+6)); /* cos(a)*sinh(b) /= 0 */
      STACK_(6+6) = R_R_complex_C(STACK_(6+6),temp); /* numerator */
      /* Stack layout: numerator, b, cosh(b), sinh(b), cos(a), sin(a), resfloat, [2 bindings]. */
      STACK_(5+6) = R_R_mult_R(STACK_(2+6),STACK_(4+6)); /* cos(a)*cosh(b) */
      temp = R_minus_R(R_R_mult_R(STACK_(1+6),STACK_(3+6))); /* -sin(a)*sinh(b) */
      temp = R_R_complex_N(STACK_(5+6),temp); /* denominator */
      temp = N_N_div_N(STACK_(6+6),temp); /* numerator/denominator */
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = C_R_float_C(temp,STACK_0);
      skipSTACK(7); return result;
    }
  }
}

/* N_cis_N(x) returns (cis x), being x a number.
 can trigger GC
 Method:
 x real -> (complex (cos x) (sin x))
 x = a+bi -> (complex (* (exp (- b)) (cos a)) (* (exp (- b)) (sin a))) */
local maygc object N_cis_N (object x)
{
  if (N_realp(x)) {
    pushSTACK(x);
    R_cos_sin_R_R(x,true,&STACK_0);
    /* Stack layout: x, cos(x), sin(x). */
    var object erg = R_R_complex_N(STACK_1,STACK_0);
    skipSTACK(3); return erg;
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object result = R_exp_R(R_minus_R(STACK_0),true,NULL); /* (exp (- b)) */
      skipSTACK(2); return result;
    } else {
      /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cos_sin_R_R(STACK_1,true,NULL); /* (cos a), (sin a) */
      /* Stack layout: a, b, cos(a), sin(a). */
      pushSTACK(R_exp_R(R_minus_R(STACK_2),true,NULL)); /* (exp (- b)) */
      /* Stack layout: a, b, cos(a), sin(a), exp(-b). */
      pushSTACK(R_R_contagion_R(STACK_3,STACK_4));
      /* Stack layout: a, b, cos(a), sin(a), exp(-b), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(3+6) = R_R_mult_R(STACK_(3+6),STACK_(1+6)); /* (* (exp (- b)) (cos a)) */
      STACK_(2+6) = R_R_mult_R(STACK_(2+6),STACK_(1+6)); /* (* (exp (- b)) (sin a)) */
      STACK_(3+6) = F_F_float_F(STACK_(3+6),STACK_(0+6));
      STACK_(2+6) = F_F_float_F(STACK_(2+6),STACK_(0+6));
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = R_R_complex_C(STACK_3,STACK_2); /* (complex ... ...) */
      skipSTACK(6); return result;
    }
  }
}

/* N_sinh_N(x) returns (sinh x), being x a number.
 can trigger GC
 Method:
 x real -> straightforward
 x = a+bi -> (complex (* (sinh a) (cos b)) (* (cosh a) (sin b))) */
local maygc object N_sinh_N (object x)
{
  if (N_realp(x)) {
    return R_sinh_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object temp = R_sin_R(STACK_0); /* sin(b), != Fixnum_0 */
      temp = R_R_complex_C(Fixnum_0,temp);
      skipSTACK(2); return temp;
    } else {
      /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cos_sin_R_R(STACK_0,true,NULL); /* cos(b), sin(b) */
      /* Stack layout: a, b, cos(b), sin(b).
         b != Fixnum_0 ==> sin(b) != Fixnum_0. */
      R_cosh_sinh_R_R(STACK_3,NULL); /* cosh(a), sinh(a); cosh(a) != Fixnum 0 */
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(1+6) = R_R_mult_R(STACK_(1+6),STACK_(4+6)); /* sinh(a)*cos(b) */
      STACK_(2+6) = R_R_mult_R(STACK_(2+6),STACK_(3+6)); /* cosh(a)*sin(b), != Fixnum_0 */
      STACK_(1+6) = F_F_float_F(STACK_(1+6),STACK_(0+6));
      STACK_(2+6) = F_F_float_F(STACK_(2+6),STACK_(0+6));
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = R_R_complex_C(STACK_1,STACK_2);
      skipSTACK(7); return result;
    }
  }
}

/* N_cosh_N(x) returns (cosh x), being x a number.
 can trigger GC
 Method:
 x real -> straightforward
 x = a+bi -> (complex (* (cosh a) (cos b)) (* (sinh a) (sin b))) */
local maygc object N_cosh_N (object x)
{
  if (N_realp(x)) {
    return R_cosh_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* save a */
    pushSTACK(TheComplex(x)->c_imag); /* save b */
    if (eq(STACK_1,Fixnum_0)) {
      var object result = R_cos_R(STACK_0); /* cos(b) */
      skipSTACK(2); return result;
    } else {
      /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cos_sin_R_R(STACK_0,true,NULL); /* cos(b), sin(b) */
      /* Stack layout: a, b, cos(b), sin(b). */
      R_cosh_sinh_R_R(STACK_3,NULL); /* cosh(a), sinh(a) */
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(1+6) = R_R_mult_R(STACK_(1+6),STACK_(3+6)); /* sinh(a)*sin(b) */
      STACK_(2+6) = R_R_mult_R(STACK_(2+6),STACK_(4+6)); /* cosh(a)*cos(b) */
      STACK_(1+6) = F_F_float_F(STACK_(1+6),STACK_(0+6));
      STACK_(2+6) = F_F_float_F(STACK_(2+6),STACK_(0+6));
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = R_R_complex_C(STACK_2,STACK_1);
      skipSTACK(7); return result;
    }
  }
}

/* N_tanh_N(x) returns (tanh x), being x a number.
 can trigger GC
 Method:
 x real -> (/ (sinh x) (cosh x))
 x = a+bi -> (/ (complex (* (sinh a) (cos b)) (* (cosh a) (sin b)))
                (complex (* (cosh a) (cos b)) (* (sinh a) (sin b))) ) */
local maygc object N_tanh_N (object x)
{
  if (N_realp(x)) {
    return R_tanh_R(x);
  } else { /* x=a+bi */
    pushSTACK(TheComplex(x)->c_real); /* a */
    pushSTACK(TheComplex(x)->c_imag); /* b */
    if (eq(STACK_1,Fixnum_0)) {
      var object temp = R_tan_R(STACK_0); /* tan(b), != Fixnum_0 */
      temp = R_R_complex_C(Fixnum_0,temp);
      skipSTACK(2); return temp;
    } else {
      /* a and b must be converted to floats. */
      if (R_rationalp(STACK_1)) /* a */
        STACK_1 = RA_float_F(STACK_1);
      if (R_rationalp(STACK_0)) /* b */
        STACK_0 = RA_float_F(STACK_0);
      var bool same_precision = (F_float_digits(STACK_1) == F_float_digits(STACK_0));
      R_cos_sin_R_R(STACK_0,true,NULL); /* cos(b), sin(b) */
      /* Stack layout: a, b, cos(b), sin(b). */
      R_cosh_sinh_R_R(STACK_3,NULL); /* cosh(a), sinh(a) */
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a). */
      pushSTACK(R_R_contagion_R(STACK_4,STACK_5));
      /* Stack layout: a, b, cos(b), sin(b), cosh(a), sinh(a), resfloat. */
      /* Bind variables, to avoid unjustified contagion warnings. */
      maybe_rebind(S(warn_on_floating_point_contagion), same_precision);
      dynamic_bind(S(floating_point_contagion_ansi),NIL);
      STACK_(6+6) = R_R_mult_R(STACK_(1+6),STACK_(4+6)); /* sinh(a)*cos(b) */
      var object temp = R_R_mult_R(STACK_(2+6),STACK_(3+6)); /* cosh(a)*sin(b) /= Fixnum 0 */
      STACK_(6+6) = R_R_complex_C(STACK_(6+6),temp); /* numerator */
      /* Stack layout: numerator, b, cos(b), sin(b), cosh(a), sinh(a), resfloat, [2 bindings]. */
      STACK_(5+6) = R_R_mult_R(STACK_(2+6),STACK_(4+6)); /* cosh(a)*cos(b) */
      temp = R_R_mult_R(STACK_(1+6),STACK_(3+6)); /* sinh(a)*sin(b) */
      temp = R_R_complex_N(STACK_(5+6),temp); /* denominator */
      temp = N_N_div_N(STACK_(6+6),temp); /* numerator/denominator */
      dynamic_unbind(S(floating_point_contagion_ansi));
      dynamic_unbind(S(warn_on_floating_point_contagion));
      var object result = C_R_float_C(temp,STACK_0);
      skipSTACK(7); return result;
    }
  }
}

/* N_atanh_N(z) returns the hyperbolic arc tangent of the number z.
 can trigger GC */
local maygc object N_atanh_N (object z);
/* Method:
 Principal value and branch cuts by the formula CLTL2, p. 315:
   atanh(z) = (log(1+z)-log(1-z)) / 2
 Let z=x+iy, return u+iv.
 If x=0 und y=0: u=0, v=0.
 If x=0: u = 0, v = atan(X=1,Y=y).
 If y=0:
   x rational -> convert x to float.
   |x|<1/2: u = atanh(x), v = 0.
   |x|>=1/2: calculate (1+x)/(1-x),
             =0 -> error,
             >0 (also |x|<1) -> u = 1/2 log((1+x)/(1-x)), v = 0.
             <0 (also |x|>1) -> u = 1/2 log(-(1+x)/(1-x)),
                                v = (-pi/2 for x>1, pi/2 for x<-1).
 Else:
   Calculate 1+x and 1-x.
   Convert x and y to floats.
   Calculate |4x| and 1+x^2+y^2,
   |4x| < 1+x^2+y^2 -> u = 1/2 atanh(2x/(1+x^2+y^2)),
   |4x| >= 1+x^2+y^2 -> u = 1/4 ln ((1+x^2+y^2)+2x)/((1+x^2+y^2)-2x)
                        or better (at the singularity: |x|-1,|y| small):
                        u = 1/4 ln ((1+x)^2+y^2)/((1-x)^2+y^2).
   v = 1/2 atan(X=(1-x)(1+x)-y^2,Y=2y) * (-1 if Y=0.0 and X<0.0 and x>=0.0,
                                          1 otherwise)
 Result is only real, if z is real.
 Real- and imagpart of the result are floats, except if z is real or
 strictly imaginary. */

/* Helper function for both: u+iv := atanh(x+iy), u,v both on the stack. */
local maygc void R_R_atanh_R_R (object x, object y)
{
  if (eq(x,Fixnum_0)) { /* x=0 -> u=0, v=atan(X=1,Y=y) (y=0 is included) */
    pushSTACK(x); pushSTACK(R_R_atan_R(Fixnum_1,y)); return;
  }
  if (eq(y,Fixnum_0)) {
    if (R_rationalp(x))
      x = RA_float_F(x); /* x --> float */
    /* x -- float */
    if (R_zerop(x)) { /* x=0.0 -> return x */
      pushSTACK(x); pushSTACK(Fixnum_0); return;
    }
    if (F_exponent_L(x) < 0) {
      /* exponent e<0, ==> |x|<1/2 */
      pushSTACK(F_atanhx_F(x)); pushSTACK(Fixnum_0); return;
    }
    /* e>=0, ==> |x|>=1/2 */
    pushSTACK(x);
    pushSTACK(R_R_minus_R(Fixnum_1,x)); /* 1-x */
    /* Stack layout: x, 1-x. */
    var object temp;
    temp = R_R_plus_R(Fixnum_1,STACK_1); /* 1+x */
    temp = F_F_div_F(temp,STACK_0); /* (1+x)/(1-x) */
    if (!R_minusp(temp)) {
      STACK_1 = temp; STACK_0 = Fixnum_0; /* imag part :=0 */
      if (R_zerop(temp)) /* x = -1 -> error */
        divide_0();
    } else { /* (1+x)/(1-x) < 0 -> negate, compute Im: */
      STACK_1 = F_minus_F(temp);
      STACK_0 = F_I_scale_float_F(pi(STACK_1),Fixnum_minus1); /* (scale-float pi -1) = pi/2 */
    }
    /* Stack layout: |(1+x)/(1-x)| (>0), Im. */
    STACK_1 = F_I_scale_float_F(R_ln_R(STACK_1,&STACK_1),Fixnum_minus1); /* ln / 2 */
    return;
  }
  pushSTACK(x); pushSTACK(y);
  /* Stack layout: x, y
   x , y --> float: */
  if (R_rationalp(STACK_1)) {
    if (R_rationalp(STACK_0))
      STACK_0 = RA_float_F(STACK_0);
    STACK_1 = RA_F_float_F(STACK_1,STACK_0,true);
  } else {
    if (R_rationalp(STACK_0))
      STACK_0 = RA_F_float_F(STACK_0,STACK_1,true);
  }
  pushSTACK(R_R_contagion_R(STACK_0,STACK_1));
  STACK_1 = F_extend_F(STACK_1); /* increase precision y */
  STACK_2 = F_extend_F(STACK_2); /* increase precision x */
  pushSTACK(R_R_plus_R(Fixnum_1,STACK_2)); /* 1+x */
  pushSTACK(R_R_minus_R(Fixnum_1,STACK_3)); /* 1-x */
  /* Stack layout: x, y, contagion, 1+x, 1-x. */
  pushSTACK(R_square_R(STACK_3)); /* y^2 */
  pushSTACK(R_square_R(STACK_(4+1))); /* x^2 */
  STACK_0 = R_R_plus_R(STACK_0,STACK_1); /* x^2+y^2 */
  STACK_0 = R_R_plus_R(Fixnum_1,STACK_0); /* 1+x^2+y^2 */
  /* Stack layout: x, y, contagion, 1+x, 1-x, y^2, 1+x^2+y^2. */
  { var object temp = F_abs_F(F_I_scale_float_F(STACK_6,fixnum(2))); /* |4x| */
    if (F_F_comp(temp,STACK_0) < 0) { /* |4x| < 1+x^2+y^2 ? */
      temp = F_I_scale_float_F(STACK_6,Fixnum_1); /* 2x */
      temp = F_F_div_F(temp,STACK_0); /* 2x/(1+x^2+y^2) */
      temp = F_atanhx_F(temp); /* atanh */
      STACK_6 = F_I_scale_float_F(temp,Fixnum_minus1); /* .../2 =: u */
    } else {
      temp = R_square_R(STACK_3); /* (1+x)^2 */
      STACK_0 = R_R_plus_R(temp,STACK_1); /* (1+x)^2+y^2, a float >=0 */
      temp = R_square_R(STACK_2); /* (1-x)^2 */
      temp = R_R_plus_R(temp,STACK_1); /* (1-x)^2+y^2, a float >=0 */
      temp = F_F_div_F(STACK_0,temp); /* ((1+x)^2+y^2)/((1-x)^2+y^2), a float >=0 */
      if (R_zerop(temp)) /* should be >0 */
        divide_0();
      temp = R_ln_R(temp,NULL); /* ln(temp), a float */
      STACK_6 = F_I_scale_float_F(temp,sfixnum(-2)); /* .../4 =: u */
    }
  }
  { var signean x_sign = R_sign(STACK_5);
    var object temp = R_R_mult_R(STACK_3,STACK_2); /* (1+x)(1-x) */
    /* Stack layout: u, y, contagion, 1+x, 1-x, y^2, -. */
    STACK_0 = R_R_minus_R(temp,STACK_1); /* (1+x)(1-x)-y^2, a float */
    temp = F_I_scale_float_F(STACK_5,Fixnum_1); /* 2y, a float */
    temp = R_R_atan_R(STACK_0,temp); /* atan(X=(1-x)(1+x)-y^2,Y=2y), a float */
    if (R_minusp(STACK_0) && (x_sign<0) && R_zerop(STACK_5)) /* X<0.0 and x>=0.0 and Y=0.0 ? */
      temp = F_minus_F(temp); /* change sign */
    STACK_5 = F_I_scale_float_F(temp,Fixnum_minus1); /* .../2 =: v */
    STACK_5 = F_F_float_F(STACK_5,STACK_4); /* restore the precision */
    STACK_6 = F_F_float_F(STACK_6,STACK_4); /* restore the precision */
    /* Stack layout: u, v, 1+x, 1-x, y^2, -. */
    skipSTACK(5); return;
  }
}

local maygc object N_atanh_N (object  z)
{
  if (N_realp(z)) {
    R_R_atanh_R_R(z,Fixnum_0);
  } else {
    R_R_atanh_R_R(TheComplex(z)->c_real,TheComplex(z)->c_imag);
  }
  /* Stack layout: z, u, v. */
  z = R_R_complex_N(STACK_1,STACK_0);
  skipSTACK(2); return z;
}

local maygc object N_atan_N (object z)
{ /* compute atanh(iz): */
  if (N_realp(z)) {
    R_R_atanh_R_R(Fixnum_0,z);
  } else {
    pushSTACK(TheComplex(z)->c_real);
    z = R_minus_R(TheComplex(z)->c_imag);
    R_R_atanh_R_R(z,popSTACK());
  }
  /* stack layout: z, u, v. */
  z = R_minus_R(STACK_1); z = R_R_complex_N(STACK_0,z); /* z := v-iu */
  skipSTACK(2); return z;
}

/* To compute for two numbers u,v with u^2-v^2=1 and u,v both in Bild(sqrt)
 (i.e. realpart>0.0 or realpart=0.0 and imagpart>=0.0)
 log(u+v):
               log(u+v) = 2 atanh(v/(u+1))                            (!)
 (Proof: 2 atanh(v/(u+1)) = log(1+(v/(u+1))) - log(1-(v/(u+1)))
  = log((1+u+v)/(u+1)) - log((1+u-v)/(u+1)) == log((1+u+v)/(1+u-v))
  = log(u+v) mod 2 pi i, and both imaginary parts are > -pi and <= pi.) */

/* N_asinh_N(z) returns the hyperbolic sine of the number z.
 can trigger GC */
local maygc object N_asinh_N (object z);
/* Method:
 Principal value and branch cuts from the formula CLTL2, p. 313:
   asinh(z) = log(z+sqrt(1+z^2))
 z=x+iy, Result u+iv.
 If x=0 and y=0: u=0, v=0.
 If x=0: asinh(iy) = i arcsin(y).
   y rational ->
     With y=1: u = 0, v = pi/2.
     With y=1/2: u = 0, v = pi/6.
     With y=0: u = 0, v = 0.
     With y=-1/2: u = 0, v = -pi/6.
     With y=-1: u = 0, v = -pi/2.
     Else convert y to float.
   e := exponent from (decode-float y), d := (float-digits y)
   With y=0.0 or e<=-d/2 return u = 0, v = y
     (because with e<=-d/2 is y^2/3 < y^2/2 < 2^(-d)/2 = 2^(-d-1), so
     1 <= asin(y)/y < 1+y^2/3 < 1+2^(-d-1) < 1+2^(-d),
     so there is asin(y)/y, rounded to d bits, equal to 1.0).
   Calculate 1-y^2.
   With y>1 return  u = ln(y+sqrt(y^2-1)), v = pi/2.
   With y<-1 return  u = -ln(|y|+sqrt(|y|^2-1)), v = -pi/2.
   With |y|<=1 return  u = 0, v = atan(X=sqrt(1-y^2),Y=y).
 If y=0:
   x rational -> convert x to float.
   |x|<1/2: u = atanh(x/sqrt(1+x^2)),
   x>=1/2: u = ln(x+sqrt(1+x^2)),
   x<=-1/2: u = -ln(-x+sqrt(1+x^2)).
   v = 0.
 Otherwise:
   z in Bild(sqrt) -> log(sqrt(1+z^2)+z) = (!) = 2 atanh(z/(1+sqrt(1+z^2))).
   z not in Bild(sqrt) ->
     asinh(z) = -asinh(-z).
     (because asinh(z)+asinh(-z) == log((z+sqrt(1+z^2))(-z+sqrt(1+z^2)))
           = log((1+z^2)-z^2) = log(1) = 0 mod 2 pi i, and at the absolute
      left side the imaginary part is <=pi.)
     So asinh(z) = -asinh(-z) = - 2 atanh(-z/(1+sqrt(1+z^2)))
          = (wegen -atanh(-w) = atanh(w)) = 2 atanh(z/(1+sqrt(1+z^2))).
 Real- and imaginary part of the result are always floats; only not, if z is real or
 strictly imaginary. */

/* N_asin_N(z) returns the Arcsin of a number z.
 can trigger GC */
local maygc object N_asin_N (object z);
/* Method:
 Principal value and branch cuts from the formula CLTL2, p. 311:
   asin(z) = log(iz+sqrt(1-z^2))/i
 Let z=x+iy, calculate u+iv = asinh(-y+ix) as above, result v-iu.
 Real- and imaginary part of the result are always floats;
 only not, if z is real or strictly imaginary. */

/* Helper function for both: u+iv := asinh(x+iy), u,v both on the stack. */
local maygc void R_R_asinh_R_R (object x, object y)
{
  if (eq(x,Fixnum_0)) { /* x=0 ? */
    pushSTACK(x); pushSTACK(y);
    if (R_rationalp(y)) {
      /* y rational */
      if (eq(y,Fixnum_0)) /* x=0, y=0 -> u=0, v=0 already on the stack */
        return;
      if (RA_integerp(y)) {
        /* y integer */
        if (eq(y,Fixnum_1)) { /* x=0, y=1 -> v = pi/2 */
          STACK_0 = F_I_scale_float_F(pi(y),Fixnum_minus1); return;
        }
        if (eq(y,Fixnum_minus1)) { /* x=0, y=-1 -> v = -pi/2 */
          STACK_0 = F_minus_F(F_I_scale_float_F(pi(y),Fixnum_minus1)); return;
        }
        STACK_0 = y = I_float_F(y); /* convert y to float */
      } else {
        /* y ratio */
        if (eq(TheRatio(y)->rt_den,fixnum(2))) { /* denominator = 2 ? */
          var object temp = TheRatio(y)->rt_num; /* numerator */
          if (eq(temp,Fixnum_1)) { /* x=0, y=1/2 -> v = pi/6 */
            STACK_0 = R_R_div_R(pi(y),fixnum(6)); return;
          }
          if (eq(temp,Fixnum_minus1)) { /* x=0, y=-1/2 -> v = -pi/6 */
            STACK_0 = F_minus_F(R_R_div_R(pi(y),fixnum(6))); return;
          }
        }
        STACK_0 = y = RA_float_F(y); /* convert y to float */
      }
    }
    /* y float */
    if (R_zerop(y) /* y=0.0 -> arcsin(y) = y as result */
        || (F_exponent_L(y) <= (sintL)(-F_float_digits(y))>>1)) /* e <= -d/2 <==> e <= -ceiling(d/2) ? */
      return; /* u=0, v=y already on the stack */
    /* stack layout: 0, y. */
    var object temp = R_R_minus_R(Fixnum_1,F_square_F(y)); /* 1-y*y */
    if (!R_minusp(temp)) {
      /* 1-y*y>=0, so |y|<=1 */
      temp = F_sqrt_F(temp); /* sqrt(1-y*y) */
      STACK_0 = R_R_atan_R(temp,STACK_0); /* v = atan(X=sqrt(1-y*y),Y=y) */
    } else {
      /* 1-y*y<0, so |y|>1 */
      temp = F_sqrt_F(F_minus_F(temp)); /* sqrt(y*y-1) */
      y = STACK_0; /* add |y| to temp: */
      if (R_minusp(y))
        temp = F_F_minus_F(temp,y);
      else
        temp = F_F_plus_F(temp,y);
      /* temp = sqrt(y^2-1)+|y|, a float >1 */
      STACK_1 = R_ln_R(temp,&STACK_0); /* ln(|y|+sqrt(y^2-1)), a float >0 */
      temp = F_I_scale_float_F(pi(STACK_1),Fixnum_minus1); /* (scale-float pi -1) = pi/2 */
      if (!R_minusp(STACK_0)) { /* sign of y */
        /* y>1 -> v = pi/2 */
        STACK_0 = temp;
      } else {
        /* y<-1 -> v = -pi/2, u = -ln(...) */
        STACK_0 = F_minus_F(temp); STACK_1 = F_minus_F(STACK_1);
      }
    }
    return;
  }
  if (eq(y,Fixnum_0)) { /* y=0 ? */
    if (R_rationalp(x))
      x = RA_float_F(x); /* convert x into float */
    /* x Float */
    pushSTACK(x); pushSTACK(Fixnum_0); /* save x, v = 0 */
    if (R_zerop(x)) /* x=0.0 -> u=x, v=0. */
      return;
    var object temp = /* sqrt(1+x^2) */
      F_sqrt_F(R_R_plus_R(Fixnum_1,F_square_F(x)));
    x = STACK_1;
    if (F_exponent_L(x) < 0) { /* exponent e (of x/=0) <0 ? */
      /* |x|<1/2 */
      STACK_1 = F_atanhx_F(F_F_div_F(x,temp)); /* u = atanh(x/sqrt(1+x^2)) */
    } else { /* |x| >= 1/2 */
      if (!R_minusp(x)) /* x >= 1/2 */
        STACK_1 = R_ln_R(F_F_plus_F(temp,x),&STACK_1); /* u = ln(x+sqrt(1+x^2)) */
      else /* x <= -1/2 */
        STACK_1 = F_minus_F(R_ln_R(F_F_minus_F(temp,x),&STACK_1)); /* u = -ln(-x+sqrt(1+x^2)) */
    }
    return;
  }
  var object z = R_R_complex_C(x,y); /* z=x+iy */
  pushSTACK(z);
  z = N_1_plus_N(N_sqrt_N(N_1_plus_N(N_square_N(z)))); /* 1+sqrt(1+z^2) */
  z = N_N_div_N(popSTACK(),z); /* z/(1+sqrt(1+z^2)) */
  /* Because z=x+iy is neither real nor stricly imaginary, so is also
     w := z/(1+sqrt(1+z^2)) neither real nor stricly imaginary.
     (Proof: Would have sqrt(1+z^2) have rational real- and imaginary part,
     so also z, so also w, and the formula z = 2w/(1-w^2) shows, that then
     z would be real or strictly imaginary. So sqrt(1+z^2) has a
     float as real- or imaginary part, so the absolute square of the denominator
     is also a float, and because real- and imaginary part of z are /=0,
     the real- and imaginary part of w are floats.)
     So also atanh(...) has floats as real part u and imaginary part v. */
  R_R_atanh_R_R(TheComplex(z)->c_real,TheComplex(z)->c_imag); /* take atanh */
  /* multiply u and v with 2: */
  STACK_1 = F_I_scale_float_F(STACK_1,Fixnum_1); /* u:=2*u */
  STACK_0 = F_I_scale_float_F(STACK_0,Fixnum_1); /* v:=2*v */
  return;
}

local maygc object N_asinh_N (object z)
{
  if (N_realp(z))
    R_R_asinh_R_R(z,Fixnum_0);
  else
    R_R_asinh_R_R(TheComplex(z)->c_real,TheComplex(z)->c_imag);
  /* stack layout: u, v. */
  z = R_R_complex_N(STACK_1,STACK_0); skipSTACK(2); return z;
}

local maygc object N_asin_N (object z)
{
  /* Calculate asinh(iz): */
  if (N_realp(z))
    R_R_asinh_R_R(Fixnum_0,z);
  else {
    pushSTACK(TheComplex(z)->c_real);
    z = R_minus_R(TheComplex(z)->c_imag);
    R_R_asinh_R_R(z,popSTACK());
  }
  /* stack layout: u, v. */
  z = R_minus_R(STACK_1); z = R_R_complex_N(STACK_0,z); /* z := v-iu */
  skipSTACK(2); return z;
}

/* N_acos_N(z) returns the Arccos of a number z.
 can trigger GC */
local maygc object N_acos_N (object z);
/* Method:
 Principal value and branch cuts from the formula CLTL2, p. 312:
 arccos(z) = log(z+i*sqrt(1-z^2))/i = pi/2 - arcsin(z)
 Let z=x+iy.
 If y=0:
 If x rational:
   With x=1: return 0.
   With x=1/2: return pi/3.
   With x=0: return pi/2.
   With x=-1/2: returnt 2pi/3.
   With x=-1: return pi.
   Else convert x into float.
 If x>1: return i ln(x+sqrt(x^2-1)).
 Else calculate u+iv = asinh(-y+ix) as above, return (pi/2-v)+iu. */
local maygc object N_acos_N (object z)
{
  if (N_realp(z)) { /* y=0 ? */
    if (R_rationalp(z)) {
      /* z rational */
      if (RA_integerp(z)) {
        /* z integer */
        if (eq(z,Fixnum_0)) /* x=0 -> Result pi/2 */
          return F_I_scale_float_F(pi(Fixnum_0),Fixnum_minus1);
        if (eq(z,Fixnum_1)) /* x=1 -> Result 0 */
          return Fixnum_0;
        if (eq(z,Fixnum_minus1)) /* x=-1 -> Result pi */
          return pi(Fixnum_0);
        z = I_float_F(z); /* convert z into float */
      } else {
        /* z Ratio */
        if (eq(TheRatio(z)->rt_den,fixnum(2))) { /* denominator = 2 ? */
          var object temp = TheRatio(z)->rt_num; /* numerator */
          if (eq(temp,Fixnum_1)) /* x=1/2 -> Result pi/3 */
            return R_R_div_R(pi(Fixnum_0),fixnum(3));
          if (eq(temp,Fixnum_minus1)) /* x=-1/2 -> Result 2pi/3 */
            return R_R_div_R(F_I_scale_float_F(pi(Fixnum_0),Fixnum_1),fixnum(3));
        }
        z = RA_float_F(z); /* convert z into float */
      }
    }
    /* z float */
    pushSTACK(z);
    if (R_R_comp(Fixnum_1,z)<0) { /* 1<z ? */
      var object temp = STACK_0; /* z */
      temp = R_R_minus_R(F_square_F(temp),Fixnum_1); /* z^2-1, a float >=0 */
      temp = F_sqrt_F(temp); /* sqrt(z^2-1), a float >=0 */
      temp = F_F_plus_F(STACK_0,temp); /* z+sqrt(z^2-1), float >1 */
      temp = R_ln_R(temp,&STACK_0); /* ln(z+sqrt(z^2-1)), float >=0 */
      skipSTACK(1);
      return R_R_complex_C(Fixnum_0,temp);
    }
    R_R_asinh_R_R(Fixnum_0,popSTACK());
  } else {
    pushSTACK(TheComplex(z)->c_real);
    z = R_minus_R(TheComplex(z)->c_imag);
    R_R_asinh_R_R(z,popSTACK());
  }
  /* stack layout: u, v.
     Construct pi/2-v : */
  z = STACK_0;
  z = (R_rationalp(z) ? pi(z) : pi_F_float_F(z)); /* pi in the same float format as v */
  z = F_I_scale_float_F(z,Fixnum_minus1); /* pi/2 */
  z = R_R_minus_R(z,STACK_0); /* pi/2-v */
  z = R_R_complex_N(z,STACK_1); /* (pi/2-v)+iu */
  skipSTACK(2); return z;
}

/* N_acosh_N(z) returns the Acosh of a number z.
 can trigger GC */
local maygc object N_acosh_N (object z);
/* Method:
 Principal value and branch cuts from the formula CLTL2, p. 314:
   acosh(z) = 2 log(sqrt((z+1)/2)+sqrt((z-1)/2))
 Let z=x+iy.
 If y=0:
   If x rational:
     With x=1: Result 0.
     With x=1/2: Result pi/3 i.
     With x=0: Result pi/2 i.
     With x=-1/2: Result 2pi/3 i.
     With x=-1: Result pi i.
   If x<-1:
     convert x to float, Result log(sqrt(x^2-1)-x) + i pi.
 Else (!) with u = sqrt((z+1)/2) and v = sqrt((z-1)/2) :
 acosh(z) = 4 atanh(v/(u+1)) = 4 atanh(sqrt((z-1)/2)/(1+sqrt((z+1)/2))) */
local maygc object N_acosh_N (object z)
{
  if (N_realp(z)) { /* y=0 ? */
    if (R_rationalp(z)) {
      /* z rational */
      if (RA_integerp(z)) {
        /* z Integer */
        if (eq(z,Fixnum_0)) /* x=0 -> return pi/2 i */
          return R_R_complex_C(Fixnum_0,F_I_scale_float_F(pi(z),Fixnum_minus1));
        if (eq(z,Fixnum_1)) /* x=1 -> return 0 */
          return Fixnum_0;
        if (eq(z,Fixnum_minus1)) /* x=-1 -> return pi i */
          return R_R_complex_C(Fixnum_0,pi(z));
      } else {
        /* z Ratio */
        if (eq(TheRatio(z)->rt_den,fixnum(2))) { /* denominator = 2 ? */
          var object temp = TheRatio(z)->rt_num; /* numerator */
          if (eq(temp,Fixnum_1)) /* x=1/2 -> return pi/3 i */
            return R_R_complex_C(Fixnum_0,R_R_div_R(pi(z),fixnum(3)));
          if (eq(temp,Fixnum_minus1)) /* x=-1/2 -> return 2pi/3 i */
            return R_R_complex_C(Fixnum_0,R_R_div_R(F_I_scale_float_F(pi(z),Fixnum_1),fixnum(3)));
        }
      }
    }
    pushSTACK(z);
    if (R_R_comp(z,Fixnum_minus1)<0) { /* z<-1 ? */
      z = STACK_0;
      if (R_rationalp(z))
        STACK_0 = z = RA_float_F(z);
      /* z float <= -1 */
      z = F_sqrt_F(R_R_minus_R(F_square_F(z),Fixnum_1)); /* sqrt(z^2-1), a float >=0 */
      STACK_0 = R_ln_R(F_F_minus_F(z,STACK_0),&STACK_0); /* log(sqrt(z^2-1)-z), a float >=0 */
      z = pi(STACK_0); /* and imaginary part == pi */
      return R_R_complex_C(popSTACK(),z);
    }
    z = popSTACK();
  }
  pushSTACK(z);
  var object temp;
  temp = N_sqrt_N(N_N_div_N(N_minus1_plus_N(z),fixnum(2))); /* numerator */
  z = STACK_0; STACK_0 = temp;
  temp = N_1_plus_N(N_sqrt_N(N_N_div_N(N_1_plus_N(z),fixnum(2)))); /* denominator */
  return N_N_mult_N(fixnum(4),N_atanh_N(N_N_div_N(popSTACK(),temp)));
}
