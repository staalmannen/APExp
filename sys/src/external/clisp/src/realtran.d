/*
 *  Transcendental functions for real numbers
 *  German comments and names translated into English: Reini Urban 2008-01
 */

/* pi_F_float_F(f) returns the number pi in the same float format as f.
 can trigger GC */
local maygc object pi_F_float_F (object f)
{
  floatcase(f,
            { return O(SF_pi); },
            { return O(FF_pi); },
            { return O(DF_pi); },
            ;
           );
  var object pi = O(LF_pi);
  var uintC f_len = Lfloat_length(f); /* wanted length of Pi */
  var uintC oldlen = Lfloat_length(pi); /* given length of Pi */
  var uintC newlen;
  if (f_len < oldlen)
    return LF_shorten_LF(pi,f_len);
  if (f_len == oldlen)
    return pi;
  /* Let the length Lfloat_length(O(LF_pi)) grow by a constant factor > 1,
     so that we do not have to recalculate to often: */
  oldlen += floor(oldlen,2); /* oldlen * 3/2 */
  newlen = (f_len < oldlen ? oldlen : f_len);
  /* wanted > given length -> must recalculate:
    Method:
    [Richard P. Brent: Fast multiple-precision evaluation of elementary
     functions. J. ACM 23(1976), 242-251.]
    d=f_len, n:=16*d. Use long-floats with 16*(d+1) mantissa bits.
    (let* ((a (coerce 1 'long-float)) ; 1
           (b (sqrt (scale-float a -1))) ; 2^-(1/2)
           (eps (scale-float a (- n))) ; 2^-n
           (t (scale-float a -2)) ; 1/4
           (x 0))
      (loop
        (when (< (- a b) eps) (return))
        (let ((y a))
          (setq a (scale-float (+ a b) -1))
          (setq b (sqrt (* b y)))
          (setq t (- t (scale-float (expt (- a y) 2) x))))
        (incf x))
      (/ (expt a 2) t)) */
  var uintC len = newlen + 1; /* work with long-floats with len digits */
  if (uintWCoverflow(len)) { error_LF_toolong(); }
  var uintL uexp_limit = LF_exp_mid - intDsize*(uintL)newlen; /* LF_exp_mid - n */
  /* An absolute value of a long-float is exactly then smaller than 2^-n, if its
     exponent < LF_exp_mid-n = uexp_limit. */
  {
    var object temp = I_to_LF(Fixnum_1,len,true); /* 1 as long-float */
    pushSTACK(temp); /* =: a */
    temp = LF_I_scale_float_LF(temp,Fixnum_minus1); /* (scale-float a -1) */
    pushSTACK(LF_sqrt_LF(temp)); /* the square root, =: b */
    pushSTACK(Fixnum_0); /* x:=0 */
    temp = LF_I_scale_float_LF(STACK_2,sfixnum(-2)); /* (scale-float a -2) */
    pushSTACK(temp); /* =: t */
  }
  /* Stack layout: a, b, x, t. */
  while (1) {
    {
      var object temp;
      temp = LF_LF_minus_LF(STACK_3,STACK_2); /* (- a b) */
      if (TheLfloat(temp)->expo < uexp_limit) /* Exponent < uexp_limit */
        break; /* yes -> |a-b| < 2^-n -> finished */
    }
    {
      var object temp;
      temp = LF_LF_plus_LF(STACK_3,STACK_2); /* a+b */
      temp = LF_I_scale_float_LF(temp,Fixnum_minus1); /* (a+b)/2 */
      pushSTACK(temp); /* new a */
    }
    STACK_(2+1) = LF_sqrt_LF(LF_LF_mult_LF(STACK_(3+1),STACK_(2+1))); /* b := sqrt(a*b) */
    {
      var object temp;
      temp = STACK_(3+1); /* old a */
      temp = LF_LF_minus_LF(STACK_(3+1) = STACK_0, temp); /* new a - old a */
      temp = LF_square_LF(temp); /* square */
      temp = LF_I_scale_float_LF(temp,STACK_(1+1)); /* multiply with 2^x */
      skipSTACK(1);
      STACK_0 = LF_LF_minus_LF(STACK_0,temp); /* subtract from t */
      STACK_1 = fixnum_inc(STACK_1,1); /* x:=x+1 */
    }
  }
  {
    var object temp;
    temp = LF_square_LF(STACK_3); /* square a */
    temp = LF_LF_div_LF(temp,STACK_0); /* divide by t */
    skipSTACK(4);
    /* temp = Pi is ready. */
    temp = O(LF_pi) = LF_shorten_LF(temp,newlen); /* shorten and store as LF_pi */
    return (f_len < newlen ? LF_shorten_LF(temp,f_len) : temp);
  }
}

/* pi(x) returns the number pi in default-float-format or the format of x
 can trigger GC */
local maygc object pi (object x) {
  defaultfloatcase(S(default_float_format),x,
                   return O(SF_pi), /* pi as SF */
                   return O(FF_pi), /* pi as FF */
                   return O(DF_pi), /* pi as DF */
                   return pi_F_float_F(x), /* pi as LF in the same format as x */
                   ,); /* nothing to save */
}

/* F_atanhx_F(x) returns for a float x (absolute value < 1/2) atanh(x) as float.
 can trigger GC */
local maygc object F_atanhx_F (object x);
/* Method:
  e := exponent from (decode-float x), d := (float-digits x)
  If x=0.0 or e<=-d/2 return x
    (Because for e <= -d/2 follows x^2 < 2^(-d), so
    1 <= atanh(x)/x = 1+x^2/3+x^4/5+... < 1+x^2/2 < 1+2^(-d-1) < 1+2^(-d),
    therefore atanh(x)/x, rounded to d bits, equals 1.0).
  If e<=-sqrt(d) use te power series
    atanh(x)/x = sum(j=0..inf,(x^2)^j/(2j+1)):
    a:=x^2, b:=1, i:=1, sum:=0,
    while (/= sum (setq sum (+ sum (/ b i)))) do i:=i+2, b:=b*a.
    Result x*sum.
  Otherwise set y := x/(1+sqrt(1-x^2)), calculate recursively z:=atanh(y)
    and return 2*z = (scale-float z 1).
  This recursion is "derecursified". Instead of constructing k times
    x := x/(1+sqrt(1+x^2)), we work with the reciprocal value,
    so set x := 1/|x|, then k times x := x+sqrt(x^2-1), then x := +- 1/x.
    Cost: asymptotic d^2.5 . */

/* F_atanx_F(x) returns for a float x (absolute value <= 1) atan(x) as float.
 can trigger GC */
local maygc object F_atanx_F (object x);
/* Method:
  e := exponent from (decode-float x), d := (float-digits x)
  If x=0.0 or e <= -d/2 return x
    (because for e <= -d/2 follows x^2/3 < x^2/2 < 2^(-d)/2 = 2^(-d-1),
    so 1 >= atan(x)/x > 1-x^2/3 > 1-2^(-d-1),
    therefore atan(x)/x, rounded to d bits, equals 1.0).
  If e <= -sqrt(d) use the power series
    atan(x)/x = sum(j=0..inf,(-x^2)^j/(2j+1)):
    a:=-x^2, b:=1, i:=1, sum:=0,
    while (/= sum (setq sum (+ sum (/ b i)))) do i:=i+2, b:=b*a.
    Result x*sum.
  Otherwise set y := x/(1+sqrt(1+x^2)), calculate recursively z:=atan(y)
    and return 2*z = (scale-float z 1).
  This recursion is "derecursified". Instead of constructing k times
    x := x/(1+sqrt(1-x^2)), we work with the reciprocal value,
    so set x := 1/|x|, then k times x := x+sqrt(x^2+1), then x := +- 1/x.
    Cost: asymptotic d^2.5 . */

/* Generates both functions F_atanx_F, F_atanhx_F */
#define GEN_F_atanx(name,Fixnum_plusminus1,F_plusminus_F)               \
  local maygc object CONCAT3(F_,name,_F) (object x)                     \
  { GCTRIGGER1(x);                                                      \
    if (R_zerop(x))                                                     \
      return x;                                                         \
   {var uintL d = F_float_digits(x);                                    \
    var sintL e = F_exponent_L(x);                                      \
    if (e <= (sintL)(-d)>>1) /* e <= -d/2 <==> e <= -ceiling(d/2)    */ \
      return x; /* yes -> x as result                                */ \
    pushSTACK(x);                                                       \
    /* Stack layout: x.                                              */ \
   {var object k = Fixnum_0; /* recursion counter k:=0               */ \
    var uintL sqrt_d = UL_sqrt_UW(d); /* floor(sqrt(d))              */ \
    /* With e <= -1-floor(sqrt(d)) we can use the power series.      */ \
    if (e >= (sintL)(-sqrt_d)) {                                        \
      /* e > -1-floor(sqrt(d)) -> must decrease |x|.                 */ \
      var sintL e_limit = 1+sqrt_d; /* 1+floor(sqrt(d))              */ \
      pushSTACK(x = F_div_F(F_abs_F(x))); /* 1/|x|                   */ \
      /* Stack layout: originales x, neues x.                        */ \
      while (1) {                                                       \
        /* calculate next x with the formula x := x+sqrt(x^2 +- 1):  */ \
        x = F_sqrt_F(R_R_plus_R(F_square_F(x),Fixnum_plusminus1));      \
        STACK_0 = x = F_F_plus_F(STACK_0,x);                            \
        k = fixnum_inc(k,1); /* k:=k+1                               */ \
        if (F_exponent_L(x) > e_limit)                                  \
          break;                                                        \
      }                                                                 \
      /* loop end with exponent(x) > 1+floor(sqrt(d)), so            */ \
      /* x >= 2^(1+floor(sqrt(d))), so 1/x <= 2^(-1-floor(sqrt(d))). */ \
      /* Now we can aplly the power series to 1/x.                   */ \
     {var object x = F_div_F(popSTACK());                               \
      if (R_minusp(STACK_0)) { x = F_minus_F(x); } /* put sign back  */ \
      STACK_0 = x; /* new x replaces old x                           */ \
    }}                                                                  \
    /* Stack layout: new x.                                          */ \
    /* Apply the power series:                                       */ \
   {var object i = Fixnum_1;                                            \
    pushSTACK(F_plusminus_F(F_square_F(STACK_0))); /* a := -x^2 resp. x^2*/ \
    pushSTACK(I_F_float_F(Fixnum_1,STACK_1)); /* b := (float 1 x)    */ \
    pushSTACK(I_F_float_F(Fixnum_0,STACK_2)); /* sum := (float 0 x)  */ \
    /* Stack layout: x, a, b, sum.                                   */ \
    while (1) {                                                         \
      var object temp;                                                  \
      temp = R_R_div_R(STACK_1,i); /* (/ b i)                        */ \
      temp = F_F_plus_F(STACK_0,temp); /* (+ sum (/ b i))            */ \
      if (eql(STACK_0,temp)) /* = sum ?                              */ \
        break; /* yes -> break power series                          */ \
      STACK_0 = temp;                                                   \
      STACK_1 = F_F_mult_F(STACK_1,STACK_2); /* b := b*a             */ \
      i = fixnum_inc(i,2); /* i := i+2                               */ \
    }}                                                                  \
   {var object erg = F_F_mult_F(STACK_0,STACK_3); /* sum*x as result */ \
    skipSTACK(4);                                                       \
    return F_I_scale_float_F(erg,k); /* because of recursion multiply with 2^k */ \
   }}}}
  /* F_atanx_F : with x -> x+sqrt(x^2-1), a = -x^2 */
  GEN_F_atanx(atanx,Fixnum_1,F_minus_F)
  /* F_atanhx_F : with x -> x+sqrt(x^2+1), a = x^2 */
  GEN_F_atanx(atanhx,Fixnum_minus1,)

/* R_R_atan_R(x,y) returns for two real numbers x, y the angle of (x,y)
 in polar coordinates. Result is rational only if x>0 and y=0.
 can trigger GC */
local maygc object R_R_atan_R (object x, object y);
/* Method:
  y=0 -> if x>0: 0 as result,
         if x<0: pi as result.
         if x=0: Error.
  x=0 -> if y>0: pi/2 as result.
         if y<0: -pi/2 as result.
         if y=0: Error.
  If x and y both rational: convert both to floats.
  0 <= |y| <= x  ->  atan(y/x)
  0 <= |x| <= y  ->  pi/2 - atan(x/y)
  0 <= |x| <= -y  ->  -pi/2 - atan(x/y)
  0 <= |y| <= -x  ->  for y>=0: pi + atan(y/x), for y<0: -pi + atan(y/x) */
local maygc object R_R_atan_R (object x, object y)
{
  if (eq(y,Fixnum_0)) {
    /* y=0 (exact) */
    if (R_zerop(x)) /* x=0 -> Error */
      divide_0();
    if (R_minusp(x)) /* x<0 -> pi in default-float-format */
      return pi(x);
    else { /* x>0 -> 0 */
      if (R_floatp(x))
        return RA_F_exact_contagion_R(Fixnum_0,x);
      else
        return Fixnum_0;
    }
  } else if (eq(x,Fixnum_0)) {
    /* x=0 (exact) */
    if (R_zerop(y)) /* y=0 -> Error */
      divide_0();
    if (R_minusp(y)) /* y<0 -> -pi/2 */
      return F_minus_F(F_I_scale_float_F(pi(y),Fixnum_minus1));
    else /* y>0 -> pi/2 */
      return F_I_scale_float_F(pi(y),Fixnum_minus1);
  }
  pushSTACK(x); pushSTACK(y);
  /* Stack layout: x, y. */
  if (R_rationalp(x) && R_rationalp(y)) {
    /* convert x,y to floats: */
    STACK_1 = RA_float_F(x); STACK_0 = RA_float_F(STACK_0);
  }
  /* x,y not exactly =0, x/y and y/x will be floats. */
  pushSTACK(R_abs_R(STACK_1)); y = R_abs_R(STACK_(0+1)); x = popSTACK();
  if (R_R_comp(x,y) >= 0) { /* compare (abs x) and (abs y) */
    /* |x| >= |y| */
    var object z = F_atanx_F(R_R_div_R(STACK_0,STACK_1)); /* atan(y/x) */
    /* Division successful, so x/=0. */
    if (R_minusp(STACK_1)) {
      /* x<0 -> add pi resp. -pi: */
      STACK_1 = z; /* save atan(y/x) */
      z = pi_F_float_F(z); /* pi in the same float format */
      if (!R_minusp(STACK_0))
        z = F_F_plus_F(STACK_1,z); /* y>=0 -> atan(y/x) + pi */
      else
        z = F_F_minus_F(STACK_1,z); /* y<0 -> atan(y/x) - pi */
    }
    skipSTACK(2);
    return z;
  } else {
    /* |x| < |y| */
    var object z = F_atanx_F(R_R_div_R(STACK_1,STACK_0)); /* atan(x/y) */
    /* subtract from pi/2 resp. -pi/2: */
    STACK_1 = z; /* save atan(x/y) */
    z = pi_F_float_F(z); /* pi in the same float format */
    z = F_I_scale_float_F(z,Fixnum_minus1); /* pi/2 */
    if (R_minusp(STACK_0)) /* y<0 -> -pi/2 instead of pi/2 */
      z = F_minus_F(z);
    z = F_F_minus_F(z,STACK_1); /* +-pi/2 - atan(x/y) */
    skipSTACK(2);
    return z;
  }
}

/* R_atan_R(x) returns the Arctan of a real number x.
Result rational only if x=0.
can trigger GC */
local maygc object R_atan_R (object x);
/* Method:
 arctan(x) = arctan(X=1,Y=x). */
#if 0
  local maygc object R_atan_R (object x)
  { return R_R_atan_R(Fixnum_1,x); }
#else /* Macro saves code */
  #define R_atan_R(x)  R_R_atan_R(Fixnum_1,x)
#endif

/* F_sinx_F(x) returns for a float x (absolute value < 2) (sin(x)/x)^2 as float.
 can trigger GC */
local maygc object F_sinx_F (object x);
/* Method:
  e := exponent from (decode-float x), d := (float-digits x)
  If x=0.0 or e < =-d/2 return 1.0
    (because for e <= -d/2 follows x^2/6 < x^2/4 < 2^(-d)/4 = 2^(-d-2),
    so 1 >= sin(x)/x > 1-x^2/6 > 1-2^(-d-2), so 1 >= (sin(x)/x)^2 > 1-2^(-d-1),
    therefore (sin(x)/x)^2, rounded to d bits, equals 1.0).
  If e<=-sqrt(d) use the power series
    sin(x)/x = sum(j=0..inf,(-x^2)^j/(2j+1)!):
    a:=-x^2, b:=1, i:=1, sum:=0,
    while (/= sum (setq sum (+ sum b))) do b:=b*a/((i+1)*(i+2)), i:=i+2.
    Result sum^2.
  Otherwise set y := x/2 = (scale-float x -1),
    calculate recursively z:=(sin(y)/y)^2 and return z*(1-y^2*z).
  [The limit sqrt(d) results from this:
   The power series with x=2^-k needs about j members, with
   k*j*ln 2 + j*(ln j - 1) = d, and the cost is about 2.8*(j/2)
   multiplications of d-bit numbers. With bisections until x=2^-k the whole
   cost is about 2*(k+e)+1.4*j(k). Minimize this to k: Shall be
   -1.4 = d/dk j(k) = (d/dj k(j))^-1 = - j^2/(d+j)*ln 2, so j^2=2(d+j),
   roughly j=sqrt(2d) and therefore k=sqrt(d).]
   Cost: asymptotic d^2.5 . */

/* F_sinhx_F(x) returns for a float x (absolute value < 2) (sinh(x)/x)^2 as float.
 can trigger GC */
local maygc object F_sinhx_F (object x);
/* Method:
  e := exponent from (decode-float x), d := (float-digits x)
  If x=0.0 or e<=(1-d)/2 return 1.0
    (Because from e<=(1-d)/2 follows x^2/6 < x^2/4 < 2^(1-d)/4 = 2^(-d-1), so
    1 <= sinh(x)/x = 1+x^2/6+... < 1+2^(-d-1), so 1 <= (sinh(x)/x)^2 < 1+2^(-d),
    therefore (sinh(x)/x)^2, rounded to d bits, equals 1.0).
  If e <= -sqrt(d) use the power series
    sinh(x)/x = sum(j=0..inf,(x^2)^j/(2j+1)!):
    a:=x^2, b:=1, i:=1, sum:=0,
    while (/= sum (setq sum (+ sum b))) do b:=b*a/((i+1)*(i+2)), i:=i+2.
    Result sum^2.
  Otherwise set y := x/2 = (scale-float x -1),
    calculate recursively z:=(sinh(y)/y)^2 and return z*(1+y^2*z).
  [The limit sqrt(d) results from this:
   The power series with x=2^-k needs about j members, with
   k*j*ln 2 + j*(ln j - 1) = d, and the cost is about 2.8*(j/2)
   multiplications of d-bit numbers. With bisections until x=2^-k the whole
   cost is about 2*(k+e)+1.4*j(k). Minimize this to k: Shall be
   -1.4 = d/dk j(k) = (d/dj k(j))^-1 = - j^2/(d+j)*ln 2, so j^2=2(d+j),
   roughly j=sqrt(2d) and therefore k=sqrt(d).]
   Cost: asymptotic d^2.5 . */

/* Generates both functions F_sinx_F, F_sinhx_F */
#define GEN_F_sinx(name,f,flag,R_R_plusminus_R)                         \
  local maygc object CONCAT3(F_,name,_F) (object x)                     \
  { GCTRIGGER1(x);                                                      \
    if (R_zerop(x))                                                     \
      return I_F_float_F(Fixnum_1,x);                                   \
   {var uintL d = F_float_digits(x);                                    \
    var sintL e = F_exponent_L(x);                                      \
    if (e <= (sintL)(f-d)>>1) /* e <= (f-d)/2 <==> e <= -ceiling((d-f)/2) ?*/ \
      return I_F_float_F(Fixnum_1,x); /* ja -> 1.0 as result         */ \
    pushSTACK(x);                                                       \
    { /* If e <= -1-floor(sqrt(d)) we can use the power series.      */ \
    var sintL e_limit = -1-UL_sqrt_UW(d); /* -1-floor(sqrt(d))       */ \
    if (e > e_limit) {                                                  \
      /* e > -1-floor(sqrt(d)) -> must decrease |x|.                 */ \
      x = I_I_minus_I(L_to_FN(e_limit),L_to_I(e));                      \
      STACK_0 = F_I_scale_float_F(STACK_0,x); /* x := x*2^(e_limit-e)*/ \
    }                                                                   \
    x = STACK_0; pushSTACK(F_square_F(x));                              \
    /* Stack layout: x, x^2.                                         */ \
    /* Apply the power series:                                       */ \
    pushSTACK(STACK_0);                                                 \
    if (flag) { STACK_0 = F_minus_F(STACK_0); } /* a := -x^2 bzw. x^2*/ \
   {var object i = Fixnum_1;                                            \
    pushSTACK(I_F_float_F(Fixnum_1,STACK_2)); /* b := (float 1 x) */    \
    pushSTACK(I_F_float_F(Fixnum_0,STACK_3)); /* sum := (float 0 x)  */ \
    /* Stack layout: x, x^2, a, b, sum.                              */ \
    while (1) {                                                         \
      var object temp;                                                  \
      temp = F_F_plus_F(STACK_0,STACK_1); /* (+ sum b)               */ \
      if (eql(STACK_0,temp)) /* = sum ?                              */ \
        break; /* yes -> break the power series                      */ \
      STACK_0 = temp;                                                   \
      STACK_1 = F_F_mult_F(STACK_1,STACK_2); /* b := b*a             */ \
      temp = I_I_mult_I(fixnum_inc(i,1),fixnum_inc(i,2)); /* (i+1)*(i+2)*/ \
      i = fixnum_inc(i,2); /* i := i+2                               */ \
      STACK_1 = R_R_div_R(STACK_1,temp); /* b := b/((i+1)*(i+2))     */ \
    }}                                                                  \
   {var object z = F_square_F(STACK_0); /* sum^2 as result           */ \
    /* Stack layout: x, x^2, -, -, -.                                */ \
    /* Because of recursion change max(e-e_limit,0) times z:         */ \
    if (e > e_limit) {                                                  \
      STACK_4 = z; /* save z                                         */ \
      do {                                                              \
        z = R_R_plusminus_R(Fixnum_1,F_F_mult_F(STACK_3,z)); /* 1 +- x^2*z*/ \
        STACK_4 = F_F_mult_F(STACK_4,z); /* multiply with z          */ \
        STACK_3 = F_I_scale_float_F(STACK_3,fixnum(2)); /* x^2 := x^2*4*/ \
        z = STACK_4;                                                    \
        e_limit++;                                                      \
      } while (e > e_limit);                                            \
    }                                                                   \
    skipSTACK(5);                                                       \
    return z;                                                           \
   }}}}
  /* F_sinx_F : with z -> z*(1-y^2*z), a = -x^2, -d/2 */
  GEN_F_sinx(sinx,0,true,R_R_minus_R)
  /* F_sinhx_F : with z -> z*(1+y^2*z), a = x^2, (1-d)/2 */
  GEN_F_sinx(sinhx,1,false,R_R_plus_R)

/* F_pi2_round_I_F(x) divides a float x by pi/2.
 both values of (round x (float pi/2 x)) a pushed to the STACK.
 can trigger GC */
local maygc void F_pi2_round_I_F (object x)
{
  if (F_exponent_L(x) < 0) {
    /* Exponent <0 -> |x|<1/2 -> |x/(pi/2)| < 1/2, ==> no division necessary */
    pushSTACK(Fixnum_0); pushSTACK(x); /* quotient 0, remainder x */
  } else {
    pushSTACK(x); /* save x */
   {var object pi = pi_F_float_F(x); /* pi with the appropriate precision */
    pi = F_I_scale_float_F(pi,Fixnum_minus1); /* pi/2 with same precision */
    R_R_round_I_R(popSTACK(),pi); /* divide x by pi/2 */
    x = STACK_1; /* q mod 4 whether q is Fixnum or Bignum: */
   {var uintC m = I_fixnump(x) ? (as_oint(x) >> oint_data_shift) & (bit(2)-1)
     : TheBignum(x)->data[(uintP)Bignum_length(x)-1] & (bit(2)-1);
    STACK_1 = fixnum(m);
   }}}
}

/* compute the sin(r=STACK_0) with precision of STACK_2 */
local maygc object sin_stack (void)
{
  var object x = F_sqrt_F(F_sinx_F(STACK_0)); /* sin(r)/r */
  x = F_F_mult_F(x,STACK_0); /* sin(r) = (sin(r)/r) * r */
  return F_F_float_F(x,STACK_2); /* round */
}

/* compute the cos(r=STACK_0) with precision of STACK_2 */
local maygc object cos_stack (void)
{
  var object s = F_I_scale_float_F(STACK_0,Fixnum_minus1); /* s := r/2 */
  pushSTACK(s);
  s = F_sinx_F(s); /* (sin(s)/s)^2 */
  s = F_F_mult_F(popSTACK(),s); /* (sin(s)/s)^2 * s = sin(s)^2/s */
  s = F_F_mult_F(STACK_0,s); /* sin(s)^2/s * r = 2*sin(s)^2 */
  s = R_R_minus_R(Fixnum_1,s); /* 1 - 2*sin(s)^2 = cos(r) */
  return F_F_float_F(s,STACK_2); /* round */
}

/* R_sin_R(x) returns the sinus (sin x) for a real number x.
 can trigger GC
 Method:
 x rational -> if x=0 return 0, otherwise convert x to a float.
 x float -> increase precision
   (q,r) := (round x (float pi/2 x)), so that |r|<=pi/4.
   if r~0, return +-1 or +-r depending on q, otherwise
   use +-sin_stack() or +-cos_stack() depending on q */
local maygc object R_sin_R (object x)
{
  if (R_rationalp(x)) {
    if (eq(x,Fixnum_0)) { return x; } /* x=0 -> return 0 */
    x = RA_float_F(x); /* convert to a float */
  }
  /* x Float */
  pushSTACK(x); /* save x */
  x = F_extend_F(x); /* increase precision */
  F_pi2_round_I_F(x); /* divide by pi/2 */
  /* stack layout: Argument, q mod 4, r. */
 {var object x = STACK_0;
  var uintC mod4 = posfixnum_to_V(STACK_1); /* q mod 4 */
  if (R_zerop(x) /* r=0.0 -> 1.0 */
      || (F_exponent_L(x) <= (sintL)(-F_float_digits(x))>>1)) /* e <= -d/2 <==> e <= -ceiling(d/2) ? */
    switch (mod4) {
      case 0: x = F_F_float_F(STACK_0,STACK_2); /* (sin x) = r */ break;
      case 1: x = I_F_float_F(Fixnum_1,STACK_2); /* (sin x) = 1 */ break;
      case 2: { /* sin(x) = -r */
        var object minus_r = F_minus_F(STACK_0);
        x = F_F_float_F(minus_r,STACK_2);
        break;
      }
      case 3: x = I_F_float_F(Fixnum_minus1,STACK_2); /* (sin x) = -1 */ break;
    }
  else
    switch (mod4) {
      case 0: x = sin_stack(); /* (sin x) = (sin r) */ break;
      case 1: x = cos_stack(); /* (sin x) = (cos r) */ break;
      case 2: x = F_minus_F(sin_stack()); /* (sin x) = (- (sin r)) */ break;
      case 3: x = F_minus_F(cos_stack()); /* (sin x) = (- (cos r)) */ break;
    }
  skipSTACK(3);
  return x;
 }
}

/* R_cos_R(x) compute the cosinus (cos x) of a real number x.
 can trigger GC
 Method:
 x rational -> if x=0 return 1, otherwise convert x to a float.
 x float -> increase precision,
   (q,r) := (round x (float pi/2 x)), so that |r|<=pi/4.
   if r~0, return +-1 or +-r depending on q, otherwise
   use +-sin_stack() or +-cos_stack() depending on q */
local maygc object R_cos_R (object x)
{
  if (R_rationalp(x)) {
    if (eq(x,Fixnum_0)) { return Fixnum_1; } /* x=0 -> return 1 */
    x = RA_float_F(x); /* convert to a float */
  }
  /* x Float */
  pushSTACK(x); /* save x */
  x = F_extend_F(x); /* increase precision */
  F_pi2_round_I_F(x); /* divide by pi/2 */
  /* stack layout: argument, q mod 4, r. */
 {var object x = STACK_0;
  var uintC mod4 = posfixnum_to_V(STACK_1); /* q mod 4 */
  if (R_zerop(x) /* r=0.0 -> 1.0 */
      || (F_exponent_L(x) <= (sintL)(-F_float_digits(x))>>1)) /* e <= -d/2 <==> e <= -ceiling(d/2) ? */
    switch (mod4) {
      case 0: x = I_F_float_F(Fixnum_1,STACK_2); /* (cos x) = 1.0 */ break;
      case 1: {/* cos(x) = -r */
        var object minus_r = F_minus_F(STACK_0);
        x = F_F_float_F(minus_r,STACK_2);
        break;
      }
      case 2: x = I_F_float_F(Fixnum_minus1,STACK_2); /* (cos x) = -1 */ break;
      case 3: x = F_F_float_F(STACK_0,STACK_2); /* (cos x) = r */ break;
    }
  else
    switch (mod4) {
      case 0: x = cos_stack(); /* (cos x) = (cos r) */ break;
      case 1: x = F_minus_F(sin_stack()); /* (cos x) = (- (sin r)) */ break;
      case 2: x = F_minus_F(cos_stack()); /* (cos x) = (- (cos r)) */ break;
      case 3: x = sin_stack(); /* (cos x) = (sin r) */ break;
    }
  skipSTACK(3);
  return x;
 }
}

/* R_cos_sin_R_R(x) places ((cos x),(sin x)), on the Stack.
   when start_p, this is a start of a computation,
    so the precision will be raised.
   when end_p, this is also the end of the computation,
    so the precision will be lowered back to this number.
 can trigger GC
 Method:
 x rational -> if x=0 ==> (1,0), otherwise x ==> float.
 x float -> increase its precision,
   (q,r) := (round x (float pi/2 x)), so that |r|<=pi/4.
   e := the exponent from (decode-float r), d := (float-digits r)
  if r=0.0 or e<=-d/2 then return (1.0 0.0)
       (since e<=-d/2 , r^2/2 < 2^(-d)/2 = 2^(-d-1), thus
        1 >= cos(r) > 1-r^2/2 > 1-2^(-d-1),
        this cos(r), up to d bits, == 1.0
        similarly sin(r) = r + O(r^3)).
  else
   y:=(sin(r/2)/(r/2))^2.
   (cos r) = 1-r^2*y/2.
   (sin r) = r*sqrt(y*(1-y*(r/2)^2)).
   reduce the precision
   if q = 0 mod 4: ((cos r), (sin r))
   if q = 1 mod 4: ((- (sin r)), (cos r))
   if q = 2 mod 4: ((- (cos r)), (- (sin r)))
   if q = 3 mod 4: ((sin r), (- (cos r))) */
local maygc void R_cos_sin_R_R (object x, bool start_p, gcv_object_t *end_p)
{
  if (R_rationalp(x)) {
    if (eq(x,Fixnum_0)) /* x=0 -> return (1,0) */
      { pushSTACK(Fixnum_1); pushSTACK(Fixnum_0); return; }
    x = RA_float_F(x); /* otherwise turn into a float */
  }
  /* x -- float */
  pushSTACK(x); /* save x */
  if (start_p) /* increase computational precision */
    x = F_extend_F(x);
  F_pi2_round_I_F(x); /* divide by pi/2 */
  /* stack layout: argument, q mod 4, r. */
  x = STACK_0;
  if (R_zerop(x) /* r=0.0 -> cos=1.0+O(r^2), sin=r+O(r^3) */
      || (F_exponent_L(x) <= (sintL)(-F_float_digits(x))>>1)) { /* e <= -d/2 <==> e <= -ceiling(d/2) ? */
    if (end_p != NULL) {
      pushSTACK(RA_R_float_F(Fixnum_1,*end_p)); /* cos=1 */
      pushSTACK(F_R_float_F(STACK_1,*end_p)); /* sin=r */
    } else {
      pushSTACK(I_F_float_F(Fixnum_1,STACK_0)); /* cos=1 */
      pushSTACK(STACK_1); /* sin=r */
    }
  } else {
    pushSTACK(F_I_scale_float_F(STACK_0,Fixnum_minus1)); /* s := r/2 */
    pushSTACK(F_sinx_F(STACK_0)); /* y := (sin(s)/s)^2 */
    /* Stack layout: argument, q mod 4, r, s, y. */
    x = F_F_mult_F(STACK_0,STACK_1); /* y*s */
    x = F_F_mult_F(STACK_2,x); /* y*s*r */
    x = R_R_minus_R(Fixnum_1,x); /* 1-y*s*r */
    pushSTACK(end_p != NULL ? F_R_float_F(x,*end_p) : x); /* round and save cos(r) */
    x = F_F_mult_F(STACK_1,STACK_2); /* y*s */
    x = F_F_mult_F(x,STACK_2); /* y*s*s */
    x = R_R_minus_R(Fixnum_1,x); /* 1-y*s*s = cos(s)^2 */
    x = F_F_mult_F(x,STACK_1); /* cos(s)^2*(sin(s)/s)^2 */
    x = F_sqrt_F(x); /* cos(s)*sin(s)/s */
    x = F_F_mult_F(x,STACK_2); /* cos(s)*sin(s) */
    x = F_I_scale_float_F(x,Fixnum_1); /* 2*cos(s)*sin(s) = sin(r) */
    if (end_p != NULL) /* round sin(r) */
      x = F_R_float_F(x,*end_p);
    STACK_2 = STACK_0;
    STACK_1 = x;
    skipSTACK(1);
  } /* stack layout: argument, q mod 4, r, cos(r), sin(r) */
  { /* compute sign */
    var uintC q = posfixnum_to_V(STACK_3);
    switch (q) { /* q mod 4 whether q is Fixnum or Bignum */
      case 0:
        STACK_(2+1) = STACK_0; STACK_(3+1) = STACK_1; break;
      case 1:
        STACK_(3+1) = F_minus_F(STACK_0); STACK_(2+1) = STACK_1; break;
      case 2:
        STACK_(2+1) = F_minus_F(STACK_0);
        STACK_(3+1) = F_minus_F(STACK_1); break;
      case 3:
        STACK_(3+1) = STACK_0; STACK_(2+1) = F_minus_F(STACK_1); break;
    }
  }
  skipSTACK(2+1);
  return;
}

/* R_tan_R(x) compute the tangens (tan x) of a real number x.
 can trigger GC
 Method:
 (/ (sin x) (cos x)) */
local maygc object R_tan_R (object x)
{
  pushSTACK(x);
  R_cos_sin_R_R(x,true,NULL);
  /* stack layout: x, cos(x), sin(x). */
  var object result = R_R_div_R(STACK_0,STACK_1);
  if (floatp(STACK_0) || floatp(STACK_1))
    result = F_R_float_F(result,STACK_2); /* reduce precision */
  skipSTACK(3); return result;
}

/* F_lnx1_F(y) returns for a float y (>=-1/2, <=1) ln(y+1) as float.
 can trigger GC */
local maygc object F_lnx1_F (object y);
/* Method:
  e := exponent of (decode-float y), d := (float-digits y)
  With y=0.0 or e <= -d return y
    (because for e <= -d follows y/2 < 2^(-d)/2 = 2^(-d-1),
    so 0 <= y - ln(x) < y^2/2 < 2^(-d-1)*y
    therefore ln(y+1)/y, rounded to d bits, equals y).
  With e<=-sqrt(d) use the power series
    ln(1+y) = sum(j=0..inf,(-1)^j*y^(j+1)/(j+1)):
    a:=-y, b:=y, i:=1, sum:=0,
    while (/= sum (setq sum (+ sum (/ b i)))) do i:=i+1, b:=b*a.
    Result sum.
  Otherwise set y := sqrt(1+y)-1, calculate recursively z:=ln(y)
    and return 2*z = (scale-float z 1).
  Cost: asymptotic d^2.5 . */
local maygc object F_lnx1_F (object x)
{
  if (R_zerop(x)) /* y=0.0 -> y as result */
    return x;
  pushSTACK(x); pushSTACK(x);
  STACK_1 = R_R_plus_R(x,Fixnum_1); /* x := (+ y 1) */
  /* Stack layout: x, y. */
  var uintL d = F_float_digits(STACK_0);
  var sintL e = F_exponent_L(STACK_0);
  if (e <= (sintL)(-d)) { /* e <= -d ? */
    x = STACK_0; skipSTACK(2); return x; /* yes -> y as result */
  }
  var object k = Fixnum_0; /* recursion counter k:=0 */
  { /* If e <= -1-floor(sqrt(d)) we can use the power series. */
    var sintL e_limit = -1-UL_sqrt_UW(d); /* -1-floor(sqrt(d)) */
    while (e > e_limit) {
      /* e > -1-floor(sqrt(d)) -> must decrease |y|. */
      var object x = F_sqrt_F(STACK_1); STACK_1 = x; /* x := (sqrt x) */
      x = R_R_minus_R(x,Fixnum_1); STACK_0 = x; /* y := (- x 1) and */
      e = F_exponent_L(x); /* calculate e new */
      k = fixnum_inc(k,1); /* k:=k+1 */
    }
  }
  /* Stack layout: x, y. */
  /* Use the power series: */
  {
    var object i = Fixnum_1;
    pushSTACK(I_F_float_F(Fixnum_0,STACK_1)); /* sum := (float 0 x) */
    STACK_2 = F_minus_F(STACK_1); /* a := -y, b := y */
    /* Stack layout: a, b, sum. */
    while (1) {
      var object temp;
      temp = R_R_div_R(STACK_1,i); /* (/ b i) */
      temp = F_F_plus_F(STACK_0,temp); /* (+ sum (/ b i)) */
      if (eql(STACK_0,temp)) /* = sum ? */
        break; /* yes -> break power series */
      STACK_0 = temp;
      STACK_1 = F_F_mult_F(STACK_1,STACK_2); /* b := b*a */
      i = fixnum_inc(i,1); /* i := i+1 */
    }
  }
  var object erg = STACK_0; /* sum as result */
  skipSTACK(3);
  return F_I_scale_float_F(erg,k); /* because of recursion multiply with 2^k */
}

/* ln2_F_float_F(f) returns ln(2) as number in the same float-format as f.
 can trigger GC */
local maygc object ln2_F_float_F (object f)
{
  var object ln2 = O(LF_ln2);
  floatcase(f,
            { return LF_to_SF(ln2); },
            { return LF_to_FF(ln2); },
            { return LF_to_DF(ln2); },
            ;
           );
  var uintC f_len = Lfloat_length(f); /* wanted length of ln(2) */
  {
    var uintC len = Lfloat_length(ln2); /* given length */
    if (f_len < len)
      return LF_shorten_LF(ln2,f_len);
    if (f_len == len)
      return ln2;
  }
  { /* wanted > given length -> must recalculate: */
    var uintC len = lf_len_extend(f_len); /* need some more digits */
    var object temp = F_lnx1_F(I_to_LF(Fixnum_1,len,true)); /* (ln 2.0) */
    /* temp = ln(2) is finished. */
    return O(LF_ln2) = LF_shorten_LF(temp,f_len); /* shorten, and store as LF_ln2 */
  }
}

/* short-float 2/3 */
#define SF_two_thirds  make_SF(0,0+SF_exp_mid,floor(bit(SF_mant_len+2),3))

/* F_lnx_F computes log(x) for x > 0
 by scaling close to 1 and then using ln2 and lnx1 above */
local maygc object F_lnx_F (object x)
{
  F_decode_float_F_I_F(x); /* compute m,e,s */
  /* Stack layout: m, e, s. */
  if (F_F_comp(STACK_2,SF_two_thirds) < 0) { /* m < 2/3 -> */
    STACK_2 = F_I_scale_float_F(STACK_2,Fixnum_1); /* double m */
    STACK_1 = I_minus1_plus_I(STACK_1); /* decrement e */
  }
  STACK_2 = F_lnx1_F(R_R_plus_R(STACK_2,Fixnum_minus1)); /* ln(m) in the more accurate float format */
  if (!eq(STACK_1,Fixnum_0)) {
    x = ln2_F_float_F(STACK_0); /* ln(2) in that float format */
    x = R_R_mult_R(STACK_1,x); /* e*ln(2) */
    x = R_R_plus_R(STACK_2,x); /* ln(m)+e*ln(2) */
  } else
    /* Avoid computing 0*ln(2) since it triggers a
       warn_floating_point_rational_contagion() call. */
    x = STACK_2;
  skipSTACK(3);
  return x;
}

/* Extends a Long-Float length n, so that from d = intDsize*n
 it becomes at least d+sqrt(d)+2+(LF_exp_len-1).
 Generally: intDsize*n + sqrt(intDsize*n) + 2 + 31 < intDsize*(n+inc)
 <==>       sqrt(intDsize*n) + 33 < intDsize*inc
 <==>       sqrt(intDsize*n) < intDsize*inc - 33
 <==>       intDsize*n < intDsize^2*inc^2 - 66*intDsize*inc + 1089
 <==>       n <= intDsize*inc^2 - 66*inc + floor(1089/intDsize) */
local uintC lf_len_extend2 (uintC n)
{
  var uintC inc =
    #define FITS(n,k)  \
      ((intDsize*(k) > 33)                                              \
       && ((n) <= (uintL)((intDsize*(k)-66)*(k)+floor(1089,intDsize))))
    #define n_max  (uintL)(bitm(intWCsize)-1)
    #define TEST(i)  FITS(n_max,1UL<<i) || FITS(n,1UL<<i) ? 1UL<<i :
    TEST(0) TEST(1) TEST(2) TEST(3) TEST(4) TEST(5) TEST(6) TEST(7)
    TEST(8) TEST(9) TEST(10) TEST(11) TEST(12) TEST(13)
    (error_LF_toolong(),0);
    #undef TEST
    #undef n_max
    #undef FITS
  if ((uintWC)(n = n+inc) < (uintWC)inc) error_LF_toolong();
  return n;
}

/* F_extend2_F(x) extends the precision of a float x by one step
 SF -> FF -> DF -> LF(4) -> LF(5) -> LF(6) -> ...
 A Float with d mantissa bits and l exponent bit becomes to a Float
 with at least d+sqrt(d)+2+(l-1) mantissa bits.
 SF -> DF because of 17+sqrt(17)+2+7 = 30.2 < 53
 FF -> DF because of 24+sqrt(24)+2+7 = 37.9 < 53
 DF -> LF(5) because of 53+sqrt(53)+2+10 = 72.3 < 80
 can trigger GC */
local maygc object F_extend2_F (object x)
{
  floatcase(x,
            { return SF_to_DF(x); }, /* 17+sqrt(17)+2+7 = 30.2 < 53 */
            { return FF_to_DF(x); }, /* 24+sqrt(24)+2+7 = 37.9 < 53 */
            { return DF_to_LF(x,ceiling(73,intDsize)); }, /* 53+sqrt(53)+2+10 = 72.3 < 73 */
            { return LF_extend_LF(x,lf_len_extend2(Lfloat_length(x))); }
           );
}

/* how many digits will be used to compute the log */
local maygc uintC extend2_digits (object y) {
  defaultfloatcase(S(default_float_format),y,
                   return 53,
                   return 53,
                   return 73,
                   return lf_len_extend2(I_to_UL(O(LF_digits))),
                   _EMA_, _EMA_);
}

/* ln(x:int): shift right, dropping unnecessary digits,
 then add them back multiplied by ln2;
 disregard the rounding errors because we use extend2 anyway;
 the result has extended precision based on y
 can trigger GC */
local maygc object I_ln_F (object x, gcv_object_t *y) {
  if (I_fixnump(x))
    return F_lnx_F(F_extend2_F(RA_R_float_F(x,*y)));
  pushSTACK(x);
  var sintC need_digits = extend2_digits(*y); /* signed for subtraction below */
  var sintL have_digits = I_integer_length(STACK_0);
  if (have_digits <= need_digits)
    x = F_lnx_F(F_extend2_F(RA_R_float_F(STACK_0,*y)));
  else { /* drop have_digits-need_digits extra digits */
    x = I_I_ash_I(STACK_0,negfixnum(need_digits - have_digits)); /* x/2^(H-N) */
    STACK_0 = F_lnx_F(F_extend2_F(RA_R_float_F(x,*y))); /* ln(x)-(H-N)ln2 */
    x = ln2_F_float_F(STACK_0);                         /* ln2 */
    x = R_R_mult_R(x,posfixnum(have_digits - need_digits)); /* (H-N)ln2 */
    x = R_R_plus_R(x,STACK_0);                              /* ln(x) */
  }
  skipSTACK(1);
  return x;
}
/* ln(rational): int: I_ln_F
     ratio: I_ln_F(numerator) - I_ln_F(denominator)
 the result has extended precision based on y
 can trigger GC */
local maygc object RA_ln_F (object x, gcv_object_t *y) {
  if (RA_integerp(x))
    return I_ln_F(x,y);
  pushSTACK(x);
  pushSTACK(I_ln_F(TheRatio(x)->rt_num,y)); /* ln(N) */
  STACK_1 = I_ln_F(TheRatio(STACK_1)->rt_den,y); /* ln(D) */
  x = R_R_minus_R(STACK_0,STACK_1);            /* ln(N)-ln(D) */
  skipSTACK(2);
  return x;
}

/* extend x and compute ln(x+1) */
local maygc object F_extend_lnx1_F (object x) {
  x = F_extend2_F(x); /* increase computational precision */
  return F_exponent_L(x) < 0 /* |x|<1/2 */
    ? F_lnx1_F(x) : F_lnx_F(R_R_plus_R(x,Fixnum_1));
}

local maygc object RA_ln1_F (object x, gcv_object_t *y) {
  if (RA_integerp(x))
    return I_ln_F(I_1_plus_I(x),y);
  pushSTACK(x);
  x = R_abs_R(TheRatio(x)->rt_num);
  if (I_I_comp(x,TheRatio(STACK_0)->rt_den) < 0) /* x<1 */
    x = F_extend_lnx1_F(RA_R_float_F(STACK_0,*y));
  else x = RA_ln_F(R_R_plus_R(STACK_0,Fixnum_1),y);
  skipSTACK(1);
  return x;
}

/* R_ln1_R(x,&end_precision) returns for a real number x>-1 ln(x+1) as number.
 can trigger GC
 Method:
 x rational -> for x=0 return 0 as result, otherwise convert x to Float.
 x Float ->
   d := (float-digits x),
   Increase precision by sqrt(d)+max(integer-length(e)) bits,
   (m,e) := (decode-float x), so that 1/2 <= m < 1.
   m<2/3 -> m:=2m, e:=e-1, so that 2/3 <= m <= 4/3.
   ln(m) calculate, ln(x)=ln(m)+e*ln(2) as result. */
local maygc object R_ln1_R (object x, gcv_object_t* end_p)
{
  if (eq(x,Fixnum_0)) return Fixnum_0; /* x=1 => return 0 */
  if (R_rationalp(x)) {
    pushSTACK(Fixnum_0);
    x = RA_ln1_F(x,&STACK_0);
    skipSTACK(1);
  } else /* x -- float */
    x = F_extend_lnx1_F(x);
  if (end_p != NULL) /* (float ... x) */
    x = F_R_float_F(x,*end_p);
  return x;
}
local inline maygc object R_ln_R (object x, gcv_object_t* end_p)
{
  if (eq(x,Fixnum_1)) return Fixnum_0; /* x=1 => return 0 */
  if (R_rationalp(x)) {
    pushSTACK(Fixnum_0);
    x = RA_ln_F(x,&STACK_0);
    skipSTACK(1);
  } else { /* x -- float */
    x = F_extend2_F(x); /* increase computational precision */
    x = F_lnx_F(x);
  }
  if (end_p != NULL) /* (float ... x) */
    x = F_R_float_F(x,*end_p);
  return x;
}
#define F_ln_F  R_ln_R

/* I_I_log_RA(a,b) returns for Integers a>0, b>1 the logarithm log(a,b)
  as exact rational number, or nullobj if it is irrational.
  can trigger GC */
local maygc object I_I_log_RA (object a, object b);
/* Method:
    log(a,b) should return the ratio c/d with coprime c>=0,d>0.
    a=1 -> c=0, d=1.
    a>=b -> Divide a by b. Remainder exists -> invalid.
            Otherwise log(a,b) = 1+log(a/b,b).
            So calculate c/d := log(a/b,b) and set c:=c+d.
    1<a<b -> log(a,b) = 1/log(b,a).
            So calculate c/d := log(b,a) and swap c and d.
  One constructs in fact a continued fraction for c/d.
  Because of a>=2^c, b>=2^d are c,d < (integer-length a,b) < intDsize*2^intWCsize.
  In matrix notation:
    When one has to do a series of division steps D and swap steps V,
    e.g. (a,b) V D D = (1,*), so is
      ( c )           ( 0 )             ( 1 1 )           ( 0 1 )
      ( d )  =  V D D ( 1 )  where  D = ( 0 1 )  and  V = ( 1 0 ).
    One constructs the matrix from left to right, at the end of
                  ( 0 )
    multiply with ( 1 ) at the right.
  Derecursivied:
    We will change (a,b) and so also c/d = log(a/b).
    Invariant: Instead of (c,d) we want to return (uc*c+ud*d,vc*c+vd*d).
                                            ( uc ud )
    I.e. the previous matrix from left is ( vc vd ).
    uc:=1, ud:=0, vc:=0, vd:=1.
    Until a>1,
      a>=b -> Divide a by b. Remainder exists -> invalid.
              Otherwise a:=a/b, and (for later c:=c+d) ud:=uc+ud, vd:=vc+vd.
      1<a<b -> swap a and b, uc and ud, vc and vd.
    Return (ud,vd), the ratio ud/vd is reduced. */
local maygc object I_I_log_RA (object a, object b)
{
  var uintL uc = 1;
  var uintL ud = 0;
  var uintL vc = 0;
  var uintL vd = 1;
  while (1) {
    if (eq(a,Fixnum_1)) /* a=1 -> end of recursion */
      break;
    if (I_I_comp(a,b) >=0) {
      /* a>=b */
      pushSTACK(b);
      I_I_divide_I_I(a,b); /* divide a by b */
      if (!eq(STACK_0,Fixnum_0)) { /* remainder /=0 ? */
        skipSTACK(3); return nullobj; /* -> finished */
      }
      a = STACK_1; b = STACK_2; skipSTACK(3); /* a:=a/b */
      ud = uc + ud; vd = vc + vd;
    } else {
      /* 1<a<b -> swap a and b */
      swap(object, a, b);
      swap(uintL, uc, ud); swap(uintL, vc, vd);
    }
  }
  /* a=1 -> c=0,d=1 -> result ud/vd */
  pushSTACK(UL_to_I(ud)); /* ud as Integer */
  var object y = UL_to_I(vd); /* vd as Integer */
  var object x = popSTACK();
  return I_I_to_RA(x,y);
}

/* R_R_log_R(a,b) returns for real numbers a>0, b>0
 log(a,b)=ln(a)/ln(b) as number.
 Result is rational, only if a=1 or a and b are rational.
 can trigger GC */
local maygc object R_R_log_R (object a, object b);
/* Method:
  a and b rational:
    b=1 -> Error
    a=1 -> Result 0
    b Integer:
      a Integer: log(a,b) rational computable -> return
      a Ratio: a=a1/a2 with a1>0, a2>1.
               a1=1 and log(a2,b) rational computable -> return -log(a2,b)
    b Ratio: a=a1/a2, b=b1/b2 with a1>0, a2>0, b1>0, b2>1.
             log(a2,b2) rational computable ->
                b1=1 -> return with a1=1, otherwise not.
                b1>1 -> log(a1,b1) rational computable and
                        log(a1,b1)=log(a2,b2) -> return, otherwise nicht.
             otherwise swap a1,a2:
               log(a2/a1,b1/b2) try (as above) ->
                 -log(a2/a1,b1/b2) as return value.
    Otherwise convert a and b to Float.
  a Float, b rational -> with b=1 Error, otherwise b := (float b a)
  a rational, b Float -> with a=1 Result 0, otherwise a := (float a b)
  a,b Floats -> log(a,b) = ln(a)/ln(b) */
local maygc object R_R_log_R (object a, object b)
{
  pushSTACK(a); pushSTACK(b);
  /* Stack layout: a, b. */
  if (R_rationalp(b)) {
    /* b rational */
    if (eq(b,Fixnum_1)) /* b=1 -> Error */
      divide_0();
    if (R_rationalp(a)) {
      /* a,b both rational */
      if (eq(a,Fixnum_1)) { /* a=1 -> Result 0 */
        skipSTACK(2); return Fixnum_0;
      }
      if (RA_integerp(b)) {
        /* b Integer */
        if (RA_integerp(a)) {
          /* a,b both Integers */
          var object x = I_I_log_RA(a,b); /* try rational log(a,b) */
          if (!eq(x,nullobj)) {
            skipSTACK(2); return x;
          }
        } else {
          /* a Ratio, b Integer */
          if (eq(TheRatio(a)->rt_num,Fixnum_1)) { /* a1=1 */
            var object x = I_I_log_RA(TheRatio(a)->rt_den,b); /* try rational log(a2,b) */
            if (!eq(x,nullobj)) {
              skipSTACK(2); return RA_minus_RA(x);
            }
          }
        }
      } else {
        /* a rational, b Ratio */
        if (RA_integerp(a)) {
          pushSTACK(a); pushSTACK(a=Fixnum_1);
        } else {
          pushSTACK(TheRatio(a)->rt_num); pushSTACK(a=TheRatio(a)->rt_den);
        }
        pushSTACK(TheRatio(b)->rt_num); pushSTACK(b=TheRatio(b)->rt_den);
        /* Stack layout: a, b, a1>0, a2>0, b1>0, b2>1. */
        {
          var object x = I_I_log_RA(a,b); /* try rational log(a2,b2) */
          if (!eq(x,nullobj)) {
            if (eq(STACK_1,Fixnum_1)) { /* b1=1 ? */
              if (eq(STACK_3,Fixnum_1)) { /* a1=1 ? */
                skipSTACK(6); return x; /* yes -> return x */
              }
            } else {
              pushSTACK(x);
              var object y = I_I_log_RA(STACK_(3+1),STACK_(1+1)); /* try rational log(a1,b1) */
              if ((!eq(y,nullobj)) && eql(STACK_0,y)) { /* x=y ? */
                x = STACK_0; skipSTACK(6+1); return x;
              }
              skipSTACK(1);
            }
          }
        }
        {
          var object x = I_I_log_RA(STACK_3,STACK_0); /* try rational log(a1,b2) */
          if (!eq(x,nullobj)) {
            if (eq(STACK_1,Fixnum_1)) { /* b1=1 ? */
              if (eq(STACK_2,Fixnum_1)) { /* a2=1 ? */
                skipSTACK(6); return RA_minus_RA(x); /* yes -> return -x */
              }
            } else {
              pushSTACK(x);
              var object y = I_I_log_RA(STACK_(2+1),STACK_(1+1)); /* try rational log(a2,b1) */
              if ((!eq(y,nullobj)) && eql(STACK_0,y)) { /* x=y ? */
                x = STACK_0; skipSTACK(6+1); return RA_minus_RA(x);
              }
              skipSTACK(1);
            }
          }
        }
        skipSTACK(4);
      }
      /* both a,b are ratios: */
      pushSTACK(RA_ln_F(STACK_1,&STACK_0)); /* ln(a) */
      pushSTACK(RA_ln_F(STACK_1,&STACK_2)); /* ln(b) */
    } else { /* a Float, b ratio */
      pushSTACK(R_ln_R(STACK_1,NULL));      /* ln(a) */
      pushSTACK(RA_ln_F(STACK_1,&STACK_2)); /* ln(b) */
    }
  } else { /* b Float */
    if (R_rationalp(a)) { /* a rational */
      if (eq(a,Fixnum_1)) { /* a=1 -> Result 0 */
        skipSTACK(2); return RA_F_exact_contagion_R(Fixnum_0,b);
      }
      pushSTACK(RA_ln_F(a,&STACK_0));  /* ln(a) */
      pushSTACK(R_ln_R(STACK_1,NULL)); /* ln(b) */
    } else {                           /* both a,b are Floats */
      pushSTACK(R_ln_R(STACK_1,NULL)); /* ln(a) */
      pushSTACK(R_ln_R(STACK_1,NULL)); /* ln(b) */
    }
  }
  /* STACK layout: a,b,ln(a),ln(b). */
  STACK_0 = F_F_div_F(STACK_1,STACK_0); /* (/ (ln a) (ln b)) */
  STACK_1 = R_R_contagion_R(STACK_2,STACK_3);
  var object ret = F_R_float_F(STACK_0,STACK_1);
  skipSTACK(4);
  return ret;
}

/* F_expx_F(x) returns for a float x (absolute value < 1) exp(x) as float.
 can trigger GC */
local maygc object F_expx_F (object x);
/* Method:
  e := exponent from (decode-float x), d := (float-digits x)
  With x=0.0 or e<-d return 1.0
    (because for e <= -d-1 follows abs(exp(x)-1) = abs(x)+O(x^2) < 2^(-d-1),
     therefore exp(x), rounded to d bits, equals 1.0).
  With e<=-sqrt(d) use the power series
    exp(x) = sum(j=0..inf,x^j/j!):
    b:=1, i:=0, sum:=0,
    while (/= sum (setq sum (+ sum b))) do b:=b*x/(i+1), i:=i+1.
    Result sum.
  Otherwise set y := x/2 = (scale-float x -1),
    calculate recursively z:=exp(y) and return z^2.
  Cost: asymptotic d^2.5 . */
local maygc object F_expx_F (object x)
{
  if (R_zerop(x))
    return I_F_float_F(Fixnum_1,x);
  var uintL d = F_float_digits(x);
  var sintL e = F_exponent_L(x);
  if (e < (sintL)(-d)) /* e < -d ? */
    return I_F_float_F(Fixnum_1,x); /* ja -> 1.0 as result */
  pushSTACK(x);
  /* Stack layout: x. */
  var uintL k = 0; /* Recursion counter k:=0 */
  { /* With e <= -1-floor(sqrt(d)) one can use the power series. */
    var sintL e_limit = -1-UL_sqrt_UW(d); /* -1-floor(sqrt(d)) */
    if (e > e_limit) {
      /* e > -1-floor(sqrt(d)) -> must decrease |x|. */
      k = e - e_limit;
      var object temp = L_to_I((sintL)(-k));
      STACK_0 = F_I_scale_float_F(STACK_0,temp); /* x := x/2^k */
      /* New exponent = e-k = e_limit. */
    }
  }
  /* Apply power series: */
  {
    var object i = Fixnum_0;
    pushSTACK(I_F_float_F(Fixnum_1,STACK_0)); /* b := (float 1 x) */
    pushSTACK(I_F_float_F(Fixnum_0,STACK_1)); /* sum := (float 0 x) */
    /* Stack layout: x, b, sum. */
    while (1) {
      var object temp;
      temp = F_F_plus_F(STACK_0,STACK_1); /* (+ sum b) */
      if (eql(STACK_0,temp)) /* = sum ? */
        break; /* yes -> break power series */
      STACK_0 = temp;
      temp = F_F_mult_F(STACK_1,STACK_2); /* b*x */
      i = fixnum_inc(i,1); /* i := i+1 */
      STACK_1 = R_R_div_R(temp,i); /* b := b*x/i */
    }
  }
  var object z = STACK_0; /* sum as result */
  skipSTACK(3);
  /* Because of recursion, square k times: */
  dotimesL(k,k, { z = F_square_F(z); } );
  return z;
}

/* R_exp_R(x) returns for a real number x the exp(x) as number.
 can trigger GC
 Method:
  x rational -> with x=0 1 as result, otherwise convert x to Float.
  x Float ->
    d := (float-digits x),
    Increase precision by sqrt(d)+max(integer-length(e)) bits,
    (q,r) := (floor x ln(2))
    Result is exp(q*ln(2)+r) = (scale-float exp(r) q). */
local maygc object R_exp_R (object x, bool start_p, gcv_object_t* end_p)
{
  if (R_rationalp(x)) { /* x rational */
    if (eq(x,Fixnum_0)) { return Fixnum_1; } /* x=0 -> return 1 */
    x = RA_float_F(x); /* ==> float */
  }
  /* x -- float */
  pushSTACK(x); /* save x */
  if (start_p) /* increase computational precision */
    x = F_extend2_F(x);
  /* divide by ln(2) (if 0<=x<1/2 can immediately set q:=0) */
  if ((!R_minusp(x)) && (F_exponent_L(x)<0)) {
    /* x>=0, Exponent <0 -> 0<=x<1/2 -> division not necessary */
    pushSTACK(Fixnum_0); pushSTACK(x);
  } else {
    pushSTACK(x);
    { var object ln2 = ln2_F_float_F(x); /* ln(2) with sufficient accuracy */
      x = popSTACK();
      F_F_floor_I_F(x,ln2); /* x / ln(2) */
    }}
  /* stack layout: original x, q, r. */
  { var object temp = F_expx_F(STACK_0); /* exp(r) */
    temp = F_I_scale_float_F(temp,STACK_1); /* * 2^q */
    if (end_p != NULL) /* (float ... x) as result */
      temp = F_R_float_F(temp,*end_p);
    skipSTACK(3);
    return temp;
  }
}

/* R_sinh_R(x) returns for a real number x the sinh(x) as number.
 can trigger GC */
local maygc object R_sinh_R (object x);
/* Method:
  x rational -> for x=0 return 0 as result, otherwise convert x to float.
  x Float -> increase precision,
    e := exponent from (decode-float x)
    if e<=0: (sinh(x)/x)^2 calculate, Wurzel ziehen, multiply with x.
    if e>0: y:=exp(x) calculate, (scale-float (- y (/ y)) -1) bilden. */
local maygc object R_sinh_R (object x)
{
  if (R_rationalp(x)) { /* x rational */
    if (eq(x,Fixnum_0)) /* x=0 -> 0 as result */
      return x;
    x = RA_float_F(x); /* otherwise convert to Float */
  }
  /* x Float */
  if (F_exponent_L(x)<=0) { /* check exponent e */
    /* e<=0 */
    var object temp;
    pushSTACK(x);
    pushSTACK(temp = F_extend_F(x));  /* increase precision */
    temp = F_sqrt_F(F_sinhx_F(temp)); /* square root of (sinh(x)/x)^2 */
    temp = F_F_mult_F(temp,STACK_0);  /* multiply with more exact x */
    temp = F_F_float_F(temp,STACK_1); /* and round again */
    skipSTACK(2);
    return temp;
  } else { /* e > 0 -> use exp(x) */
    var object temp;
    pushSTACK(x);
    pushSTACK(temp = R_exp_R(x,true,NULL)); /* y:=exp(x) */
    temp = F_div_F(temp); /* (/ y) */
    temp = F_F_minus_F(popSTACK(),temp); /* von y subtrahieren */
    temp = F_I_scale_float_F(temp,Fixnum_minus1); /* (scale-float -1) */
    return F_F_float_F(temp,popSTACK());
  }
}

/* R_cosh_R(x) returns for a real number x the number cosh(x).
 can trigger GC */
local maygc object R_cosh_R (object x);
/* Method:
  x rational -> for x=0 return 1 as result, otherwise convert x to float.
  x float -> increase precision,
    e := exponent of (decode-float x), d := (float-digits x)
    if x=0.0 or e<=(1-d)/2 return 1.0
      (because for e <= (1-d)/2 follows 1 <= cosh(x) = 1+x^2/2+... < 1+2^(-d),
       so there is cosh(x), rounded to d bits, equal 1.0).
    if e<=0:
      y := x/2 = (scale-float x -1), calculate (sinh(y)/y)^2,
      calculate cosh(x) = 1+x*y*(sinh(y)/y)^2.
    if e>0: calculate y:=exp(x), (scale-float (+ y (/ y)) -1) bilden. */
local maygc object R_cosh_R (object x)
{
  if (R_rationalp(x)) { /* x rational */
    if (eq(x,Fixnum_0)) /* x=0 -> 1 as result */
      return Fixnum_1;
    x = RA_float_F(x); /* otherwise convert to float */
  }
  /* x float */
  var sintL e = F_exponent_L(x);
  if (e > 0) { /* e>0 -> use exp(x) */
    var object temp;
    pushSTACK(x);
    pushSTACK(temp = R_exp_R(x,true,NULL)); /* y:=exp(x) */
    temp = F_div_F(temp); /* (/ y) */
    temp = F_F_plus_F(popSTACK(),temp); /* add to y */
    temp = F_I_scale_float_F(temp,Fixnum_minus1); /* (scale-float -1) */
    return F_F_float_F(temp,popSTACK());
  } else { /* e<=0 */
    if (R_zerop(x))
      return I_F_float_F(Fixnum_1,x);
    {
      var uintL d = F_float_digits(x);
      if (e <= (sintL)(1-d)>>1) /* e <= (1-d)/2 <==> e <= -ceiling((d-1)/2) ? */
        return I_F_float_F(Fixnum_1,x); /* yes -> 1.0 as result */
    }
    {
      var object temp;
      pushSTACK(x);
      pushSTACK(temp = F_extend_F(x)); /* increase computational precision */
      pushSTACK(temp = F_I_scale_float_F(temp,Fixnum_minus1)); /* y=(scale-float x -1) */
      temp = F_sinhx_F(temp); /* (sinh(y)/y)^2 */
      temp = F_F_mult_F(STACK_0,temp); /* multiply with y */
      temp = F_F_mult_F(STACK_1,temp); /* multiply with x */
      temp = R_R_plus_R(Fixnum_1,temp); /* add 1 */
      temp = F_F_float_F(temp,STACK_2); /* and round again */
      skipSTACK(3);
      return temp;
    }
  }
}

/* R_cosh_sinh_R_R(x) returns ((cosh x),(sinh x)), both values on the stack.
 can trigger GC
 Method:
  x rational -> with x=0 (1,0) as result, otherwise convert x to float.
  x float -> increase precision,
    e := exponent from (decode-float x), d := (float-digits x)
    if x=0.0 or e<=(1-d)/2 return (1.0,x)
      (because with e<=(1-d)/2 follows
       1 <= sinh(x)/x < cosh(x) = 1+x^2/2+... < 1+2^(-d),
       so cosh(x), rounded to d bits, equals 1.0
       and sinh(x), rounded to d bits, equals x).
    if e<=0:
      calculate y:=(sinh(x)/x)^2,
      calculate cosh(x) = sqrt(1+x^2*y) and sinh(x) = x*sqrt(y).
    if e>0: calculate y:=exp(x),
      do (scale-float (+ y (/ y)) -1) und (scale-float (- y (/ y)) -1).
    Restore reduced precision. */
local maygc void R_cosh_sinh_R_R (object x, gcv_object_t* end_p)
{
  if (R_rationalp(x)) { /* x rational */
    if (eq(x,Fixnum_0)) /* x=0 -> return (1,0) */
      { pushSTACK(Fixnum_1); pushSTACK(Fixnum_0); return; }
    x = RA_float_F(x); /* ==> Float */
  }
  /* x -- float */
  { var sintL e = F_exponent_L(x);
    if (e > 0) { /* e>0 -> use exp(x) */
      var object temp;
      pushSTACK(x);
      pushSTACK(temp = R_exp_R(x,true,NULL)); /* y:=exp(x) */
      pushSTACK(temp = F_div_F(temp)); /* (/ y) */
      /* stack layout: x, exp(x), exp(-x). */
      temp = F_F_plus_F(STACK_1,temp); /* + y */
      temp = F_I_scale_float_F(temp,Fixnum_minus1); /* /2 */
      STACK_2 = (end_p != NULL ? F_F_float_F(temp,*end_p) : temp); /* cosh */
      temp = F_F_minus_F(STACK_1,STACK_0); /* - y */
      temp = F_I_scale_float_F(temp,Fixnum_minus1); /* /2 */
      STACK_1 = (end_p != NULL ? F_F_float_F(temp,*end_p) : temp); /* sinh */
      skipSTACK(1);
      return;
    } else { /* e<=0 */
      if (R_zerop(x) /* e <= (1-d)/2 <==> e <= -ceiling((d-1)/2) ? */
          || (e <= (sintL)(1-F_float_digits(x))>>1)) {
        x = F_extend_F(x); /* increase computational precision */
        pushSTACK(x); pushSTACK(x);
        if (end_p != NULL) {
          STACK_1 = RA_R_float_F(Fixnum_1,*end_p); /* cosh=1 */
          STACK_0 = F_R_float_F(STACK_0,*end_p); /* sinh=x */
        } else
          STACK_1 = I_F_float_F(Fixnum_1,x);
        return;
      }
      pushSTACK(x);
      { var object temp = F_extend_F(x);
        pushSTACK(temp);
        pushSTACK(F_square_F(temp)); /* x*x */
        pushSTACK(temp = F_sinhx_F(STACK_1)); /* y:=(sinh(x)/x)^2 */
        /* stack layout: original x, x, x^2, y. */
        temp = F_sqrt_F(temp); /* sqrt(y) = sinh(x)/x */
        temp = F_F_mult_F(STACK_2,temp); /* x*sqrt(y) = sinh(x) */
        STACK_2 = (end_p != NULL ? F_F_float_F(temp,STACK_3) : temp); /* restore the precision */
        temp = F_F_mult_F(STACK_1,STACK_0); /* x^2*y */
        temp = F_sqrt_F(R_R_plus_R(Fixnum_1,temp)); /* sqrt(1+x^2*y) */
        STACK_3 = (end_p != NULL ? F_F_float_F(temp,STACK_3) : temp); /* restore the precision */
        skipSTACK(2); return;
      }
    }
  }
}

/* R_tanh_R(x) compute the hyperbolic tangens (tanh x) of a real number x.
 can trigger GC
 Method:
   x = 0 => 0
   |x| < 1 => (/ (sinh x) (cosh x)) - better precision for small x
   x < 0 => - tanh(-x)
   x > 0 => 1 - exp(-2x) / 1 + exp(-2x) - better handling of very large x */
local maygc object posF_tanh_posF (object x) {
  pushSTACK(x);               /* save to be able to restore precision */
  dynamic_bind(S(inhibit_floating_point_underflow),T);
  x = R_exp_R(F_I_scale_float_F(F_minus_F(x),Fixnum_1),true,NULL);
  dynamic_unbind(S(inhibit_floating_point_underflow));
  if (R_zerop(x)) return I_F_float_F(Fixnum_1,popSTACK());
  pushSTACK(x); pushSTACK(NIL); pushSTACK(NIL); pushSTACK(NIL);
  STACK_2 = I_F_float_F(Fixnum_1,STACK_3);
  STACK_1 = F_F_minus_F(STACK_2,STACK_3);
  STACK_0 = F_F_plus_F(STACK_2,STACK_3);
  /* STACK: x, e^-2x, 1.0, 1-e^-2x, 1+e^-2x */
  x = F_F_div_F(STACK_1,STACK_0);
  skipSTACK(4);
  return F_F_float_F(x,popSTACK());
}
local maygc object R_tanh_R (object x)
{
  if (R_rationalp(x)) { /* x rational */
    if (eq(x,Fixnum_0)) /* x=0 -> 0 */
      return Fixnum_0;
    x = RA_float_F(x); /* ==> Float */
  }
  /* x -- float */
  if (F_exponent_L(x) <= 0) {   /* small => (/ (sinh x) (cosh x)) */
    pushSTACK(x);
    R_cosh_sinh_R_R(x,NULL);
    /* stack layout: x, cosh(x), sinh(x). */
    var object result = R_R_div_R(STACK_0,STACK_1);
    if (floatp(STACK_0) || floatp(STACK_1))
      result = F_R_float_F(result,STACK_2); /* reduce precision */
    skipSTACK(3); return result;
  } else return positivep(x) ? posF_tanh_posF(x)
           : F_minus_F(posF_tanh_posF(F_minus_F(x)));
}
