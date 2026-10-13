/* Recursive marking routine. */

local void gc_mark (object obj)
{
  var object curr = obj; /* current object */
  var object pred = nullobj; /* predecessor-object */
  IF_DEBUG_GC_MARK(fprintf(stderr,"gc_mark obj = 0x%"PRIoint"x\n", as_oint(obj)));

#define down_pair()                                                     \
  if (in_old_generation(curr,typecode(curr),1))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)ThePointer(curr);          \
    if (marked(curr_)) goto up; /* marked -> go up */                   \
    MARK(curr_); /* mark */                                             \
  }                                                                     \
  { var object curr_ = objectplus(curr,(soint)(sizeof(cons_)-sizeof(gcv_object_t))<<(oint_addr_shift-addr_shift)); \
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)ThePointer(curr_); /* successor */\
    *(gcv_object_t*)ThePointer(curr_) = pred; /* store predecessor */   \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* successor becomes current object */                 \
    goto down; /* and descent */                                        \
  }
#define up_pair()                                       \
  { MARK(ThePointer(pred)); /* mark again */            \
    curr = pred; /* Cons becomes object */              \
    pred = prepred; goto up; /* go further up */        \
  }
#define down_varobject(The,first_offset,last_offset)                    \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)The(curr);                 \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* mark */                                             \
    mark(pointerplus(curr_,first_offset)); /* mark first pointer */     \
  }                                                                     \
  { var object curr_ = objectplus(curr,(soint)(last_offset)<<(oint_addr_shift-addr_shift)); \
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)The(curr_); /* successor */       \
    *(gcv_object_t*)The(curr_) = pred; /* store predecessor */          \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }
#define up_varobject(first_offset)                                      \
  { curr = objectplus(pred,-(soint)(first_offset)<<(oint_addr_shift-addr_shift)); /* becomes current object */ \
    pred = prepred; goto up; /* go further up */                        \
  }
#define down_nopointers(The)                    \
  if (in_old_generation(curr,typecode(curr),0)) \
    goto up; /* do not mark older generation */ \
  MARK(The(curr)); /* mark */                   \
  goto up; /* and up */
#define down_iarray()                                                   \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheIarray(curr);           \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* mark */                                             \
  }                                                                     \
  { var object curr_ = objectplus(curr,(soint)(iarray_data_offset)<<(oint_addr_shift-addr_shift)); \
    /* data vector is the first and only pointer */                     \
    var object succ = *(gcv_object_t*)TheIarray(curr_); /* successor */ \
    *(gcv_object_t*)TheIarray(curr_) = pred; /* store predecessor */    \
    MARK(TheIarray(curr_)); /* mark first and only pointer */           \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }
#define up_iarray()                                                     \
  { curr = objectplus(pred,-(soint)iarray_data_offset<<(oint_addr_shift-addr_shift)); /* array becomes current object */ \
    pred = prepred; goto up; /* go further up */                        \
  }
#define down_sistring()                                                 \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheSistring(curr);         \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* mark */                                             \
  }                                                                     \
  { var object curr_ = objectplus(curr,(soint)(sistring_data_offset)<<(oint_addr_shift-addr_shift)); \
    /* data vector is the first and only pointer */                     \
    var object succ = *(gcv_object_t*)TheSistring(curr_); /* successor */\
    *(gcv_object_t*)TheSistring(curr_) = pred; /* store predecessor */  \
    MARK(TheSistring(curr_)); /* mark first and only pointer */         \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }
#define up_sistring()                                                   \
  { curr = objectplus(pred,-(soint)sistring_data_offset<<(oint_addr_shift-addr_shift)); /* array becomes current object */ \
    pred = prepred; goto up; /* go further up */                        \
  }
#define down_svector()                                                  \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheSvector(curr);          \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* mark */                                             \
  }                                                                     \
  { var uintL len = Svector_length(curr);                               \
    if (len==0) goto up; /* Length 0: up again */                       \
   {var object curr_ = objectplus(curr,((soint)offsetofa(svector_,data) << (oint_addr_shift-addr_shift)) \
    /* the "<< 1" and "/2" are a workaround against a gcc-2.7.2         \
       missed optimization in WIDE_SOFT mode */                         \
      + (((soint)len << 1) * (soint)(sizeof(gcv_object_t)/2) << (oint_addr_shift-addr_shift)) \
      - ((soint)sizeof(gcv_object_t) << (oint_addr_shift-addr_shift)) );\
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)TheSvector(curr_); /* successor */\
    *(gcv_object_t*)TheSvector(curr_) = pred; /* store predecessor */   \
    mark(&TheSvector(curr)->data[0]); /* mark first pointer */          \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }}
#define up_svector()                            \
  { curr = objectplus(pred,-(soint)offsetofa(svector_,data)<<(oint_addr_shift-addr_shift)); /* Svector becomes current object */ \
    pred = prepred; goto up; /* go further up */ \
  }
#define down_lrecord()                                                  \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheLrecord(curr);          \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* marked */                                           \
  }                                                                     \
  { var uintL len = Lrecord_nonweak_length(curr);                       \
    if (len==0) goto up; /* Length 0: up again */                       \
   {var object curr_ = objectplus(curr,((soint)offsetofa(record_,recdata) << (oint_addr_shift-addr_shift)) \
    /* the "<< 1" and "/2" are a workaround against a gcc-2.7.2         \
       missed optimization in WIDE_SOFT mode */                         \
      + (((soint)len << 1) * (soint)(sizeof(gcv_object_t)/2) << (oint_addr_shift-addr_shift)) \
      - ((soint)sizeof(gcv_object_t) << (oint_addr_shift-addr_shift)) );\
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)TheLrecord(curr_); /* successor */\
    *(gcv_object_t*)TheLrecord(curr_) = pred; /* store predecessor */   \
    mark(&TheLrecord(curr)->recdata[0]); /* mark first pointer */       \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }}
#define up_lrecord()                             \
  { curr = objectplus(pred,-(soint)offsetofa(record_,recdata)<<(oint_addr_shift-addr_shift)); /* Lrecord becomes current object */ \
    pred = prepred; goto up; /* go further up */ \
  }
#define down_sxrecord()                                                 \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheRecord(curr);           \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* marked */                                           \
  }                                                                     \
  { var uintL len = SXrecord_nonweak_length(curr);                      \
    if (len==0) goto up; /* Length 0: up again */                       \
   {var object curr_ = objectplus(curr,((soint)offsetofa(record_,recdata) << (oint_addr_shift-addr_shift)) \
    /* the "<< 1" and "/2" are a workaround against a gcc-2.7.2         \
       missed optimization in WIDE_SOFT mode */                         \
      + (((soint)len << 1) * (soint)(sizeof(gcv_object_t)/2) << (oint_addr_shift-addr_shift)) \
      - ((soint)sizeof(gcv_object_t) << (oint_addr_shift-addr_shift)) );\
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)TheRecord(curr_); /* successor */ \
    *(gcv_object_t*)TheRecord(curr_) = pred; /* store predecessor */    \
    mark(&TheRecord(curr)->recdata[0]); /* mark first pointer */        \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }}
#if defined(USE_JITC)
 #define down_cclosure()  if (cclosurep(curr) && cclosure_jitc_p(curr)) { \
   object jitc = cclosure_jitc(curr);                                   \
   if (fpointerp(jitc)) {                                               \
     if (gc_drop_jitc) cclosure_jitc(curr) = NIL;                       \
     else gc_mark_jitc_object(TheFpointer(jitc)->fp_pointer);           \
   }                                                                    \
 }
#else
 #define down_cclosure()
#endif
#define up_sxrecord()                             \
  { curr = objectplus(pred,-(soint)offsetofa(record_,recdata)<<(oint_addr_shift-addr_shift)); /* record becomes current object */ \
    pred = prepred; goto up; /* go further up */  \
  }
#ifdef STANDARD_HEAPCODES
#define down_subr()                                                     \
  if (in_old_generation(curr,typecode(curr),0))                         \
    goto up; /* do not mark older generation */                         \
  { var gcv_object_t* curr_ = (gcv_object_t*)TheSubr(curr);             \
    if (marked(curr_)) goto up; /* marked -> up */                      \
    MARK(curr_); /* marked */                                           \
  }                                                                     \
  { var object curr_ = objectplus(curr,((soint)offsetofa(record_,recdata) << (oint_addr_shift-addr_shift)) \
      + ((soint)subr_length * (soint)sizeof(gcv_object_t) << (oint_addr_shift-addr_shift)) \
      - ((soint)sizeof(gcv_object_t) << (oint_addr_shift-addr_shift)) ); \
    /* start with the last pointer */                                   \
    var object succ = *(gcv_object_t*)TheSubr(curr_); /* successor */   \
    *(gcv_object_t*)TheSubr(curr_) = pred; /* store predecessor */      \
    mark(&((Record)TheSubr(curr))->recdata[0]); /* mark first pointer */ \
    pred = curr_; /* current object becomes new predecessor */          \
    curr = succ; /* predecessor becomes current object */               \
    goto down; /* and descent */                                        \
  }
#define up_subr()                                                       \
  { curr = objectplus(pred,-(soint)offsetofa(record_,recdata)<<(oint_addr_shift-addr_shift)); /* SUBR becomes current object */ \
    pred = prepred; goto up; /* go further up */  \
  }
#endif

 down: /* entry for further descent.
          curr = object to be marked (engl. this),
          pred = its predecessor */
  IF_DEBUG_GC_MARK(fprintf(stderr,"down: pred = 0x%"PRIoint"x, curr = 0x%"PRIoint"x\n",
                           as_oint(pred), as_oint(curr)));
 #ifdef TYPECODES
  switch (typecode(curr)) {
    case_pair: /* object with exactly two 2 pointers (Cons and similar) */
      down_pair();
    case_symbol: /* Symbol */
      down_varobject(TheSymbol,symbol_objects_offset,
                     symbol_length*sizeof(gcv_object_t));
    case_sstring: /* simple-string */
      if (sstring_reallocatedp(TheSstring(curr))) {
        down_sistring();
      }
      /*FALLTHROUGH*/
    case_sbvector: /* simple-bit-vector */
    case_sb2vector: /* simple-2bit-vector */
    case_sb4vector: /* simple-4bit-vector */
    case_sb8vector: /* simple-8bit-vector */
    case_sb16vector: /* simple-16bit-vector */
    case_sb32vector: /* simple-32bit-vector */
    case_bignum: /* bignum */
   #ifndef IMMEDIATE_FFLOAT
    case_ffloat: /* single-float */
   #endif
    case_dfloat: /* double-float */
    case_lfloat: /* long-float */
      /* objects of variable length, that do not contain pointers: */
      down_nopointers(TheVarobject);
    case_mdarray: case_obvector: case_ob2vector: case_ob4vector: case_ob8vector:
    case_ob16vector: case_ob32vector: case_ostring: case_ovector:
      /* arrays, that are not simple: */
      down_iarray();
    case_svector: /* simple-vector */
      down_svector();
    case_lrecord: /* Lrecord */
      down_lrecord();
    case_sxrecord: /* Srecord/Xrecord */
      down_cclosure();          /*FALLTHROUGH*/
    case_subr: /* SUBR */
      down_sxrecord();
    case_machine: /* machine address */
    case_char: /* character */
    case_system: /* frame-pointer, small-read-label, system */
    case_fixnum: /* fixnum */
    case_sfloat: /* short-float */
   #ifdef IMMEDIATE_FFLOAT
    case_ffloat: /* single-float */
   #endif
      /* These are direct objects, no pointers. */
      goto up;
    default: /* These are no objects. */
      /*NOTREACHED*/ abort();
  }
 #else
  switch (as_oint(curr) & nonimmediate_heapcode_mask) {
    case cons_bias+conses_misaligned: /* cons */
      #ifdef STANDARD_HEAPCODES
      /* NB: (immediate_bias & nonimmediate_heapcode_mask) == cons_bias. */
      if (immediate_object_p(curr)) goto up;
      #endif
      down_pair();
    case varobject_bias+varobjects_misaligned:
      switch (Record_type(curr)) {
        case Rectype_Sbvector:
        case Rectype_Sb2vector:
        case Rectype_Sb4vector:
        case Rectype_Sb8vector:
        case Rectype_Sb16vector:
        case Rectype_Sb32vector:
        case Rectype_S8string: case Rectype_Imm_S8string:
        case Rectype_S16string: case Rectype_Imm_S16string:
        case Rectype_S32string: case Rectype_Imm_S32string:
        case Rectype_Bignum:
        case Rectype_Ffloat:
        case Rectype_Dfloat:
        case Rectype_Lfloat:
          down_nopointers(TheRecord);
        case Rectype_Svector:
          down_svector();
        #ifdef HAVE_SMALL_SSTRING
        case Rectype_reallocstring:
          down_sistring();
        #endif
        case Rectype_mdarray:
        case Rectype_bvector:
        case Rectype_b2vector:
        case Rectype_b4vector:
        case Rectype_b8vector:
        case Rectype_b16vector:
        case Rectype_b32vector:
        case Rectype_string:
        case Rectype_vector:
          down_iarray();
        case Rectype_WeakList:
        case Rectype_WeakAnd:
        case Rectype_WeakOr:
        case Rectype_WeakAndMapping:
        case Rectype_WeakOrMapping:
        case Rectype_WeakAlist_Key:
        case Rectype_WeakAlist_Value:
        case Rectype_WeakAlist_Either:
        case Rectype_WeakAlist_Both:
        case Rectype_WeakHashedAlist_Key:
        case Rectype_WeakHashedAlist_Value:
        case Rectype_WeakHashedAlist_Either:
        case Rectype_WeakHashedAlist_Both: /* Lrecord */
          down_lrecord();
        default: /* Srecord/Xrecord */
          down_cclosure();
          down_sxrecord();
      }
    #ifdef STANDARD_HEAPCODES
    case subr_bias: /* SUBR */
      down_subr();
    #endif
    case machine_bias:
    #ifdef LINUX_NOEXEC_HEAPCODES
    case machine_bias+4:
    #endif
      /* These are direct objects, no pointers. */
      goto up;
    default:
      /*NOTREACHED*/ abort();
  }
 #endif
 up: /* entry for ascent.
        curr = currently marked object, pred = its predecessor */
  IF_DEBUG_GC_MARK(fprintf(stderr,"up:   pred = 0x%"PRIoint"x, curr = 0x%"PRIoint"x\n",
                           as_oint(pred), as_oint(curr)));
  if (eq(pred,nullobj)) /* ending flag reached? */
    return; /* yes -> finished */
  if (!marked(ThePointer(pred))) { /* already through? */
    /* no ->
       next element further left (come from 'up', go to 'down')
       curr = currently marked  object, store in *pred */
    var object prepred = *(gcv_object_t*)ThePointer(pred); /* old predecessor */
    *(gcv_object_t*)ThePointer(pred) = curr; /* write back component */
    pred = objectplus(pred,-(soint)(sizeof(gcv_object_t))<<(oint_addr_shift-addr_shift)); /* go to next component */
    if (marked(ThePointer(pred))) { /* already marked? */
      curr = /* next component, without mark */
        without_mark_bit(*(gcv_object_t*)ThePointer(pred));
      *(gcv_object_t*)ThePointer(pred) = /* further relocate old predecessor, thereby renew mark */
        with_mark_bit(prepred);
    } else {
      curr = *(gcv_object_t*)ThePointer(pred); /* next component, without mark */
      *(gcv_object_t*)ThePointer(pred) = prepred; /* further relocate old predecessor */
    }
    goto down;
  }
  { /* already through -> ascent again */
    var object prepred = /* fetch old predecessor, without mark bit */
      without_mark_bit(*(gcv_object_t*)ThePointer(pred));
    *(gcv_object_t*)ThePointer(pred) = curr; /* write back first component */
   #ifdef TYPECODES
    switch (typecode(pred)) {
      case_pair: /* object with exactly two pointers (Cons and similar) */
        up_pair();
      case_symbol: /* Symbol */
        up_varobject(symbol_objects_offset);
      case_svector: /* simple-vector with at least 1 component */
        up_svector();
      case_mdarray: case_obvector: case_ob2vector:
      case_ob4vector: case_ob8vector: case_ob16vector:
      case_ob32vector: case_ostring: case_ovector:
        /* non-simple arrays: */
        up_iarray();
      case_lrecord: /* Lrecord */
        up_lrecord();
      case_sxrecord: /* Srecord/Xrecord */
      case_subr: /* SUBR */
        up_sxrecord();
      case_sstring: /* simple-string */
        { var object pred_ = objectplus(pred,-(soint)sistring_data_offset<<(oint_addr_shift-addr_shift));
          if (sstring_reallocatedp(TheSstring(pred_)))
            up_sistring();
        }
        /*FALLTHROUGH*/
      case_machine: /* machine address */
      case_char: /* character */
      case_system: /* frame-pointer, small-read-label, system */
      case_fixnum: /* fixnum */
      case_sfloat: /* short-float */
     #ifdef IMMEDIATE_FFLOAT
      case_ffloat: /* single-float */
     #endif
        /* These are direct objects, no pointers. */
      case_sbvector: /* simple-bit-vector */
      case_sb2vector: /* simple-2bit-vector */
      case_sb4vector: /* simple-4bit-vector */
      case_sb8vector: /* simple-8bit-vector */
      case_sb16vector: /* simple-16bit-vector */
      case_sb32vector: /* simple-32bit-vector */
      case_bignum: /* bignum */
     #ifndef IMMEDIATE_FFLOAT
      case_ffloat: /* single-float */
     #endif
      case_dfloat: /* double-float */
      case_lfloat: /* long-float */
        /* Objects of variable length, that do not contain pointers. */
      default: /* these are no objects. */
        /*NOTREACHED*/ abort();
    }
   #else
    switch (as_oint(pred) & nonimmediate_heapcode_mask) {
      case cons_bias+conses_misaligned: /* Cons */
        up_pair();
      case varobject_bias+varobjects_misaligned:
        /* This works only because all varobjects have the same
           objects_offset! */
        up_sxrecord();
      #ifdef STANDARD_HEAPCODES
      case subr_bias: /* SUBR */
        up_subr();
      #endif
      default: /* these are no objects. */
        /*NOTREACHED*/ abort();
    }
   #endif
  }
#undef up_subr
#undef down_subr
#undef up_sxrecord
#undef down_sxrecord
#undef up_svector
#undef down_svector
#undef up_lrecord
#undef down_lrecord
#undef up_iarray
#undef down_iarray
#undef down_nopointers
#undef up_varobject
#undef down_varobject
#undef up_pair
#undef down_pair
#undef down_cclosure
}
