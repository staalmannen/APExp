/* Functions for random numbers
 German comments and names translated into English: Reini Urban 2007-11
 Random number generator from [Knuth: The Art of Computer Programming, Vol. II,
   Seminumerical Algorithms, 3.3.4., Table 1, Line 30], from C. Haynes:
   X a 64-Bit-Number. Iteration X := (a*X+c) mod m
   with m=2^64, a=6364136223846793005, c=1. */

/* random_L(randomstate) generates a new random number.
 > randomstate: a Random-State, is changed
 < result: a 32-Bit random number */
local uint32 random_L (object randomstate)
{
  var object seed = /* last number, a Simple-Bit-Vector with 64 Bits */
    The_Random_state(randomstate)->random_state_seed;
  var uintD* seedMSDptr = (uintD*)(&TheSbvector(seed)->data[0]);
  /* Multiplicator a=6364136223846793005 = 0x5851F42D4C957F2D : */
  local var const uintD multiplier[64/intDsize] = {
    D(0x58,0x51,0xF4,0x2D,) D(0x4C,0x95,0x7F,0x2D,)
  };
  var uintD product[128/intDsize]; /* Produkt */
  /* multiply: */
  mulu_2loop_down(&seedMSDptr[64/intDsize],64/intDsize,
                  &multiplier[64/intDsize],64/intDsize,
                  &product[128/intDsize]);
  /* get last 64 Bits: */
  var uint32 seed_hi = get_32_Dptr(&product[64/intDsize]);
  var uint32 seed_lo = get_32_Dptr(&product[96/intDsize]);
  seed_lo += 1; if (seed_lo==0) seed_hi += 1; /* increment by 1 */
  /* fill seed anew: */
  set_32_Dptr(seedMSDptr,seed_hi);
  set_32_Dptr(&seedMSDptr[32/intDsize],seed_lo);
  /* middle 32 Bits as result: */
  return highlow32(low16(seed_hi),high16(seed_lo));
}

/* random_UDS(randomstate,MSDptr,len) fills the UDS MSDptr/len/..
 with len random digits.
 > randomstate: a Random-State, is changed
 > MSDptr/len/..: buffer for the random digits
 > len: wanted number of random digits */
local void random_UDS (object randomstate, uintD* MSDptr, uintC len)
{
  var uintC count;
  dotimesC(count,floor(len,32/intDsize), {
    var uint32 next = random_L(randomstate); /* get more 32/intDsize digits */
    set_32_Dptr(MSDptr,next); MSDptr += 32/intDsize;
  });
  len = len % (32/intDsize); /* number of missing digits */
  if (len>0) {
    var uint32 next = random_L(randomstate); /* get more 32/intDsize digits */
    set_max32_Dptr(intDsize*len,MSDptr,next);
  }
}

/* I_random_I(randomstate,n) returns for an integer n>0 a random
 integer x with 0 <= x < n.
 > randomstate: a Random-State, is changed
 can trigger GC */
local maygc object I_random_I (object randomstate, object n)
{
  var uintD* n_MSDptr;
  var uintC n_len;
  var uintD* n_LSDptr;
  I_to_NDS_nocopy(n, n_MSDptr=,n_len=,n_LSDptr=); /* Digit sequence >0 to n */
  var uintD* MSDptr;
  var uintC len = n_len + ceiling(16,intDsize); /* 16 Bits mehr */
  if ((intWCsize < 32) && ((uintWC)len < (uintWC)n_len))
    BN_ueberlauf();
  {
    SAVE_NUM_STACK /* save num_stack */
    /* generate new UDS with len random digits: */
    num_stack_need(len,MSDptr=,);
    begin_arith_call();
    random_UDS(randomstate,MSDptr,len);
    /* and divide by n: */
    var DS q;
    var DS r;
    UDS_divide(MSDptr,len,&MSDptr[(uintP)len], n_MSDptr,n_len,n_LSDptr, &q,&r);
    end_arith_call();
    /* convert rest into integer: */
    var object result = NUDS_to_I(r.MSDptr,r.len);
    RESTORE_NUM_STACK
    return result;
  }
}

/* F_random_F(randomstate,n) generates for a float n>0 a random
 float x with 0 <= x < n.
 > randomstate: a Random-State, is changed
 can trigger GC */
local maygc object F_random_F (object randomstate, object n)
{
  pushSTACK(n);
  var uintL d = F_float_digits(n); /* d = (float-digits n) > 0 */
  { /* generate new UDS with d random digits: */
    SAVE_NUM_STACK /* save num_stack */
    var uintL len = ceiling(d,intDsize);
    var uintD* MSDptr;
    num_stack_need_1(len,MSDptr=,);
    begin_arith_call();
    random_UDS(randomstate,MSDptr,len); /* len (>0) random digits */
    end_arith_call();
    { /* cut from intDsize*ceiling(d/intDsize) to d bits: */
      var uintL dr = d % intDsize;
      if (dr>0)
        MSDptr[0] &= (bit(dr)-1);
    }
    /* convert to integer: */
    var object mant = UDS_to_I(MSDptr,len);
    RESTORE_NUM_STACK /* restore num_stack */
    /* Generate random float between 0 and 1
       = (scale-float (float random-integer,d_Bits n) (- d)) : */
    mant = I_F_float_F(mant,STACK_0); /* convert into float of type of n */
    pushSTACK(mant);
    {
      var object minus_d = L_to_I(-d); /* (- d) */
      mant = popSTACK();
      mant = F_I_scale_float_F(mant,minus_d);
    }
    /* multiply it with n: */
    mant = F_F_mult_F(mant,STACK_0);
    /* mant is a random float >=0, <=n. */
    if (eql(mant,popSTACK())) /* compare with n */
      /* if (by rounding) mant=n, replace by 0: */
      mant = I_F_float_F(Fixnum_0,mant);
    return mant;
  }
}

