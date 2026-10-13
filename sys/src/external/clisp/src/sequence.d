/*
 * Sequences for CLISP
 * Bruno Haible 1987-2005
 * Sam Steingold 1998-2009
 * German comments and names translated into English: Reini Urban 2008-01
 */
#include "lispbibl.c"

/* O(seq_types) contains a list of type descriptors for sequences.
 These are simple-vectors of length 16, containing:
  SEQ-TYPE        ; the type of the sequence, usually a symbol
 Access functions:
  SEQ-INIT
  SEQ-UPD
  SEQ-ENDTEST
  SEQ-FE-INIT
  SEQ-FE-UPD
  SEQ-FE-ENDTEST
  SEQ-ACCESS
  SEQ-ACCESS-SET
  SEQ-COPY
  SEQ-LENGTH
  SEQ-MAKE
  SEQ-ELT
  SEQ-SET-ELT
  SEQ-INIT-START
  SEQ-FE-INIT-END

Explanation of the functions SEQ-XXX:

A "pointer" is something, that can step through a sequence.
There are pointers, that move from left to right;
  they are created with INIT or INIT-START, copied with COPY,
    UPD to advance one step,
    ENDTEST for testing, if they have reached the end of the Sequence,
    ACCESS  for fetching the element, which is pointed to by the pointer,
    ACCESS-SET for setting the element, which is pointed to by the pointer.
There are also pointers, that move from right to left;
  they are created with FE-INIT or FE-INIT-END, copied with COPY,
    FE-UPD for moving them one step to the left,
    FE-ENDTEST for testing, if they have reached the end of the Sequence,
    ACCESS for fetching the element, which is pointed to by the pointer.
  For them, ACCESS-SET does not work.

Movement operations:
INIT          (lambda (seq) ...) -> pointer
              returns the leftmost pointer of SEQ.
UPD           (lambda (seq pointer) ...) -> pointer
              returns a pointer to the adjacent neighbor at the right.
              SEQ-UPD can assume, that the right border of
              SEQ is not stepped over.
ENDTEST       (lambda (seq pointer) ...) -> bool
              tests, if this pointer is at the right end of SEQ.
The same "FROM END" :
FE-INIT       (lambda (seq) ...) -> pointer
              returns the rightmost pointer of SEQ.
FE-UPD        (lambda (seq pointer) ...) -> pointer
              returns a pointer to the adjacent neighbor at the left.
              SEQ-FE-UPD can assume, that the left border of
              SEQ is not stepped over.
FE-ENDTEST    (lambda (seq pointer) ...) -> bool
              tests, if this pointer is at the left end of SEQ.
Access via pointer:
ACCESS        (lambda (seq pointer) ...) -> value
              returns the element in SEQ the pointer is pointing to.
ACCESS-SET    (lambda (seq pointer value) ...) ->
              sets the element where the pointer is pointing to in SEQ, to the
              specified value. Works only for pointers that move from left to
              right!
COPY          (lambda (pointer) ...) -> pointer
              returns a copy of the Pointer to SEQ (because UPD and FE-UPD
              can operate destructively on the pointers)
Total length:
LENGTH        (lambda (seq) ...) -> size
              returns the (active) length of the Sequence SEQ.
MAKE          (lambda (size) ...) -> sequence
              returns a newly allocated, empty sequence, that has the type
              SEQ-TYPE and the specified length.
Access via index (usually more inefficient than via pointer):
ELT           (lambda (seq index) ...) -> value
              returns (ELT SEQ index)
SET-ELT       (lambda (seq index value) ...) ->
              sets (ELT SEQ index) to value.
INIT-START    (lambda (seq index) ...) -> pointer
              returns a pointer which moves in SEQ from left to right
              from Position index. Must execute the Range-test by itself.
FE-INIT-END   (lambda (seq index) ...) -> pointer
              returns a pointer which moves in SEQ from right to left
              from Position index. Must execute the Range-test by itself.
*/

#define seq_type(seqdesc)         (TheSvector(seqdesc)->data[0])
#define seq_init(seqdesc)         (TheSvector(seqdesc)->data[1])
#define seq_upd(seqdesc)          (TheSvector(seqdesc)->data[2])
#define seq_endtest(seqdesc)      (TheSvector(seqdesc)->data[3])
#define seq_fe_init(seqdesc)      (TheSvector(seqdesc)->data[4])
#define seq_fe_upd(seqdesc)       (TheSvector(seqdesc)->data[5])
#define seq_fe_endtest(seqdesc)   (TheSvector(seqdesc)->data[6])
#define seq_access(seqdesc)       (TheSvector(seqdesc)->data[7])
#define seq_access_set(seqdesc)   (TheSvector(seqdesc)->data[8])
#define seq_copy(seqdesc)         (TheSvector(seqdesc)->data[9])
#define seq_length(seqdesc)       (TheSvector(seqdesc)->data[10])
#define seq_make(seqdesc)         (TheSvector(seqdesc)->data[11])
#define seq_elt(seqdesc)          (TheSvector(seqdesc)->data[12])
#define seq_set_elt(seqdesc)      (TheSvector(seqdesc)->data[13])
#define seq_init_start(seqdesc)   (TheSvector(seqdesc)->data[14])
#define seq_fe_init_end(seqdesc)  (TheSvector(seqdesc)->data[15])

/* find sequence type NAME in O(seq_types)
 return a typedescr or NIL if no such sequence */
local object find_seq_type (object name) {
  var object list = O(seq_types);
  while (consp(list)) {
    var object typdescr = Car(list); list = Cdr(list); /* (pop list) */
    if (eq(name,seq_type(typdescr))) return typdescr;
  }
  return NIL;
}

/* UP: checks whether the given type is a valid sequence type name (otherwise
 error) and returns the corresponding type descriptor.
 valid_type(&type)
 > type: sequence type name
 < type: expanded type
 < result: corresponding type descriptor
 < pushed on STACK: length constraint (an integer, -1 means at least 1) or
                    type (if the length constraint is more complicated) or
                    unbound (means the length is unconstrained)
 can trigger GC */
local maygc object valid_type1 (gcv_object_t* type_) {
  var object name = *type_;
  /* Our elementary sequence types are LIST, VECTOR, STRING, BIT-VECTOR.
   We also allow certain alias names:
   - DEFTYPE-defined types are expanded.
   - ([SIMPLE-]ARRAY [eltype [1 | (dim)]]), (VECTOR [eltype [size]]) expand into
     STRING if eltype = CHARACTER,
     BIT-VECTOR if eltype = BIT,
     n [stands for (VECTOR (UNSIGNED-BYTE n))] if eltype = n BIT,
     VECTOR otherwise.
   - (SIMPLE-VECTOR [size]), VECTOR, SIMPLE-VECTOR expand into VECTOR.
   - ([SIMPLE-]STRING [size]), [SIMPLE-]STRING expand into STRING.
   - ([SIMPLE-]BASE-STRING [size]), [SIMPLE-]BASE-STRING expand into STRING.
   - ([SIMPLE-]BIT-VECTOR [size]), [SIMPLE-]BIT-VECTOR expand into BIT-VECTOR.
   - Additionally (not very nice): [SIMPLE-]ARRAY expands into VECTOR.
   - Class objects referring to built-in types are recognized as well. */
  name = expand_deftype(name,false);
  if (symbolp(name)) {
    if (eq(name,S(list))) { goto expanded_unconstrained; }
    if (eq(name,S(null)))
      { pushSTACK(Fixnum_0); name = S(list); goto expanded; }
    if (eq(name,S(cons)))
      /* -1 means length at least 1 */
      { pushSTACK(Fixnum_minus1); name = S(list); goto expanded; }
    if (eq(name,S(vector))) { goto expanded_unconstrained; }
    if (eq(name,S(simple_vector)))
      { name = S(vector); goto expanded_unconstrained; }
    if (eq(name,S(string))) { goto expanded_unconstrained; }
    if (eq(name,S(cs_string))
        || eq(name,S(simple_string)) || eq(name,S(base_string))
        || eq(name,S(simple_base_string)))
      { name = S(string); goto expanded_unconstrained; }
    if (eq(name,S(bit_vector)) || eq(name,S(simple_bit_vector)))
      { name = fixnum(1); goto expanded_unconstrained; }
    if (eq(name,S(array)) || eq(name,S(simple_array)))
      { name = S(vector); goto expanded_unconstrained; }
    goto expanded_unconstrained; /* other symbols may be DEFSTRUCT types */
  } else if (consp(name)) {
    var object name1 = Car(name);
    if (symbolp(name1)) {
      var object name2 = Cdr(name);
      if (nullp(name2) || (consp(name2) && nullp(Cdr(name2)))) {
        if (eq(name1,S(simple_vector)))
          { name = S(vector); goto expanded_maybe_constrained; }
        if (eq(name1,S(string)) || eq(name1,S(cs_string))
            || eq(name1,S(simple_string))
            || eq(name1,S(base_string)) || eq(name1,S(simple_base_string)))
          { name = S(string); goto expanded_maybe_constrained; }
        if (eq(name1,S(bit_vector)) || eq(name1,S(simple_bit_vector)))
          { name = fixnum(1); goto expanded_maybe_constrained; }
        if (false) {
         expanded_maybe_constrained:
          if (consp(name2) && integerp(Car(name2)))
            { pushSTACK(Car(name2)); goto expanded; }
          else goto expanded_unconstrained;
        }
      }
      {
        var object name3;
        if (nullp(name2)) { name2 = S(star); name3 = S(star); goto try_vector; }
        if (consp(name2))
          { name3=Cdr(name2); name2 = Car(name2);
          if (nullp(name3)) { name3 = S(star); goto try_vector; }
          if (consp(name3) && nullp(Cdr(name3)))
            { name3 = Car(name3); goto try_vector; }
          }
        if (false) {
         try_vector: /* Here is name2 = (second name), name3 = (third name), Defaults: * */
          if (eq(name1,S(vector))
              || (   (eq(name1,S(array)) || eq(name1,S(simple_array)))
                  && (eq(name3,S(star)) || eq(name3,Fixnum_1)
                      || (consp(name3) && nullp(Cdr(name3)))))) {
            if (eq(name1,S(vector))) {
              if (integerp(name3)) pushSTACK(name3); else pushSTACK(unbound);
            } else {
              if (consp(name3) && integerp(Car(name3))) pushSTACK(Car(name3));
              else pushSTACK(unbound);
            }
            var uintB atype = (eq(name2,S(star)) ? Atype_T : eltype_code(name2));
            if (atype==Atype_T) { /* (VECTOR T) */
              name = S(vector); goto expanded;
            } else if (atype==Atype_Char) { /* (VECTOR CHARACTER) */
              name = S(string); goto expanded;
            } else if (atype == Atype_NIL) { /* (VECTOR NIL) */
              name = Fixnum_0; goto expanded;
            } else { /* (VECTOR (UNSIGNED-BYTE n)) */
              name = fixnum(bit(atype)); goto expanded; }
          }
        }
      }
    }
  } else if_defined_class_p(name, {
    if (eq(name,O(class_list)))
      { name = S(list); goto expanded_unconstrained; }
    if (eq(name,O(class_null)))
      { pushSTACK(Fixnum_0); name = S(list); goto expanded; }
    if (eq(name,O(class_cons)))
      /* -1 means length at least 1 */
      { pushSTACK(Fixnum_minus1); name = S(list); goto expanded; }
    if (eq(name,O(class_vector)))
      { name = S(vector); goto expanded_unconstrained; }
    if (eq(name,O(class_string)))
      { name = S(string); goto expanded_unconstrained; }
    if (eq(name,O(class_bit_vector)))
      { name = fixnum(1); goto expanded_unconstrained; }
    if (eq(name,O(class_array)))
      { name = S(vector); goto expanded_unconstrained; }
    name = TheClass(name)->classname;
    goto expanded_unconstrained; /* other classes could be DEFSTRUCT defined types */
  }, {});
  { pushSTACK(name); /* possibly complicated length constraint */
    /* Call (SYS::SUBTYPE-SEQUENCE name): */
    pushSTACK(name); funcall(S(subtype_sequence),1);
    if (eq(value1,S(sequence)) || eq(value1,NIL))
      return NIL;
  }
  /* Return the expanded but unsimplified type. */
  *type_ = STACK_0;
  name = value1;
  /* Search for name in SEQ-TYPES list: */
  return find_seq_type(name);

 expanded_unconstrained:
  { pushSTACK(unbound); } /* no length constraint */
 expanded:
  /* Return the expanded elementary type, without the length constraint. */
  *type_ = name;
  /* Search for name in SEQ-TYPES list: */
  return find_seq_type(name);
}

/* Same as valid_type1, but signal an error instead of returning NIL
 when name does not name a sequence */
local maygc object valid_type (gcv_object_t* type_) {
  var object typedescr = valid_type1(type_);
  if (!nullp(typedescr))
    return typedescr;
  /* otherwise -- signal an error */
  pushSTACK(*type_);                             /* TYPE-ERROR slot DATUM */
  pushSTACK(O(type_recognizable_sequence_type)); /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(*type_);
  error(type_error,GETTEXT("There are no sequences of type ~S"));
}

/* UP: returns the type descriptor of a sequence
 get_seq_type(seq)
 > seq: a sequence
 < result: type descriptor or NIL */
local object get_seq_type (object seq) {
  var object name;
  if (listp(seq)) name = S(list); /* type LIST */
  else if (vectorp(seq)) {
    switch (Array_type(seq)) {
      case Array_type_string:
        switch (Iarray_flags(seq) & arrayflags_atype_mask) {
          case Atype_NIL: /* type (VECTOR NIL) */
            { name = Fixnum_0; break; }
          case Atype_Char: /* type STRING */
            { name = S(string); break; }
          default:
            NOTREACHED;
        }
        break;
      case Array_type_sstring:
        { name = S(string); break; } /* type STRING */
      case Array_type_sbvector:
      case Array_type_sb2vector:
      case Array_type_sb4vector:
      case Array_type_sb8vector:
      case Array_type_sb16vector:
      case Array_type_sb32vector: /* type n, meaning (VECTOR (UNSIGNED-BYTE n)) */
        { name = fixnum(bit(sbNvector_atype(seq))); break; }
      case Array_type_bvector:
      case Array_type_b2vector:
      case Array_type_b4vector:
      case Array_type_b8vector:
      case Array_type_b16vector:
      case Array_type_b32vector: /* type n, meaning (VECTOR (UNSIGNED-BYTE n)) */
        { name = fixnum(bit(bNvector_atype(seq))); break; }
      case Array_type_vector: case Array_type_svector:
        { name = S(vector); break; } /* type [GENERAL-]VECTOR */
      default:
        NOTREACHED;
    }
  } else if (structurep(seq)) {
    name = TheStructure(seq)->structure_types; /* list of structures types */
    /* Take the last type (excluding the final STRUCTURE-OBJECT): */
    while (consp(name) && consp(Cdr(name)) && consp(Cdr(Cdr(name))))
      name = Cdr(name);
    name = Car(name);
  } else return NIL;
  /* Search for name in SEQ-TYPES list: */
  return find_seq_type(name);
}

/* Signal a "not a SEQUENCE" type-error */
nonreturning_function(local, error_sequence, (object obj)) {
  pushSTACK(obj);         /* TYPE-ERROR slot DATUM */
  pushSTACK(S(sequence)); /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(S(sequence)); pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
  error(type_error,GETTEXT("~S: ~S is not a ~S"));
}
/* UP: Return the type descriptor for the sequence, or report an error.
 get_valid_seq_type(seq)
 > seq: a sequence
 < result: type descriptor */
local object get_valid_seq_type (object seq)
{
  var object typdescr = get_seq_type(seq); /* find type descriptor */
  if (!(nullp(typdescr))) { return typdescr; } /* found -> OK */
  error_sequence(seq);
}

/* Error, if the sequence type defines another length as the sequence
 actually has. */
nonreturning_function(local, error_seqtype_length,
                      (object seqtype_length, object computed_length)) {
  pushSTACK(computed_length); /* TYPE-ERROR slot DATUM */
  pushSTACK(NIL); /* TYPE-ERROR slot EXPECTED-TYPE - filled later */
  pushSTACK(computed_length);
  if (eq(seqtype_length,Fixnum_minus1)) {
    pushSTACK(O(type_posfixnum1));
    STACK_2 = O(type_posfixnum1); /* EXPECTED-TYPE */
  } else {
    pushSTACK(seqtype_length);
    pushSTACK(S(eql)); pushSTACK(seqtype_length);
    { var object type = listof(2); STACK_2 = type; } /* EXPECTED-TYPE */
  }
  pushSTACK(TheSubr(subr_self)->name);
  error(type_error,GETTEXT("~S: sequence type forces length ~S, but result has length ~S"));
}
/* Check whether the computed_length CL matches seqtype_length STL */
#define SEQTYPE_LENGTH_MATCH(cl,stl)                            \
  (eq(cl,Fixnum_minus1) ? !eq(Fixnum_0,stl) : eql(cl,stl))

/* Error when the argument is not an integer >=0
 YES, we _CAN_ create lists longer than MOST-POSITIVE-FIXNUM! */
nonreturning_function(local, error_posint, (object kw, object obj)) {
  pushSTACK(obj);                /* TYPE-ERROR slot DATUM */
  pushSTACK(O(type_posinteger)); /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(obj); pushSTACK(kw); pushSTACK(TheSubr(subr_self)->name);
  error(type_error,GETTEXT("~S: ~S should be an integer >=0, not ~S"));
}

/* Macro: Puts NIL as default parameter value onto the stack:
 default_NIL(par); */
#define default_NIL(par)                        \
  if (!boundp(par)) { par = NIL; }

/* Macro: Puts numeric zero as default parameter value onto the stack:
 start_default_0(start); */
#define start_default_0(start)                  \
  if (!boundp(start)) { start = Fixnum_0; }

/* Macro: Puts (SEQ-LENGTH sequence) as default parameter value onto the stack:
 end_default_len(end,seq,typdescr);
 can trigger GC */
#define end_default_len(end,seq,typdescr)               \
  if (missingp(end)) {                                  \
    var object lengthfun = seq_length(typdescr);        \
    pushSTACK(seq); funcall(lengthfun,1);               \
    end = value1;                                       \
  }

/* UP: Checks START and END arguments
 > kwptr: kwptr[0] = START keyword,
          kwptr[1] = END keyword
 > argptr: *(argptr STACKop 1) = START argument,
           *(argptr STACKop 0) = END argument */
local void test_start_end (const gcv_object_t* kwptr,
                           const gcv_object_t* argptr) {
  /* START argument must be an integer >= 0: */
  var object start = *(argptr STACKop 1);
  if (!(integerp(start) && positivep(start)))
    error_posint(kwptr[0],start);
  /* END argument must be an integer >= 0: */
  var object end = *(argptr STACKop 0);
  if (!(integerp(end) && positivep(end)))
    error_posint(kwptr[1],end);
  /* compare arguments: */
  if (!(I_I_comp(end,start)>=0)) { /* end >= start ? */
    /* no -> error: */
    pushSTACK(end); pushSTACK(kwptr[1]);
    pushSTACK(start); pushSTACK(kwptr[0]);
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: ~S = ~S should not be greater than ~S = ~S"));
  }
}

/* UP: Checks START- and END- arguments (END argument may be NIL)
 > kwptr: kwptr[0] = START keyword,
          kwptr[1] = END keyword
 > argptr: *(argptr STACKop 1) = START argument,
           *(argptr STACKop 0) = END argument */
local void test_start_end_1 (const gcv_object_t* kwptr,
                             const gcv_object_t* argptr) {
  /* START argument must be an integer >= 0: */
  var object start = *(argptr STACKop 1);
  if (!(integerp(start) && positivep(start)))
    error_posint(kwptr[0],start);
  /* END argument must be NIL or an integer >= 0: */
  var object end = *(argptr STACKop 0);
  if (nullp(end)) /* end=NIL -> OK, return */
    return;
  if (!(integerp(end) && positivep(end)))
    error_posint(kwptr[1],end);
  /* compare arguments: */
  if (!(I_I_comp(end,start)>=0)) { /* end >= start ? */
    /* no -> error: */
    pushSTACK(end); pushSTACK(kwptr[1]);
    pushSTACK(start); pushSTACK(kwptr[0]);
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: ~S = ~S should not be greater than ~S = ~S"));
  }
}

/* Macro: Increments an integer variable (on the stack).
 increment(var)
 > var: old value
 < var: new value
 < result: new value
 can trigger GC */
#define increment(var)  (var = I_1_plus_I(var)) /* var := (1+ var) */

/* Macro: Decrements an integer variable (on the stack).
 decrement(var)
 > var: old value
 < var: new value
 < result: new value
 can trigger GC */
#define decrement(var)  (var = I_minus1_plus_I(var)) /* var := (1- var) */

/* Macro: Advances a forward pointer (on the stack).
 pointer_update(pointer,sequence,typdescr);
 pointer must be of the form STACK_i!
 can trigger GC */
#define pointer_update(pointer,sequence,typdescr) do {   \
  object updatefun = seq_upd(typdescr);                  \
  pushSTACK(sequence); /* sequence */                    \
  pushSTACK(*(&(pointer) STACKop 1)); /* pointer */      \
  funcall(updatefun,2); /* (SEQ-UPD sequence pointer) */ \
  pointer = value1; /* =: pointer */                     \
 } while(0)

/* Macro: Advances a backwards pointer (on the stack).
 pointer_fe_update(pointer,sequence,typdescr);
 pointer must be of the form STACK_i!
 can trigger GC */
#define pointer_fe_update(pointer,sequence,typdescr) do {   \
  object updatefun = seq_fe_upd(typdescr);                  \
  pushSTACK(sequence); /* sequence */                       \
  pushSTACK(*(&(pointer) STACKop 1)); /* pointer */         \
  funcall(updatefun,2); /* (SEQ-FE-UPD sequence pointer) */ \
  pointer = value1; /* =: pointer */                        \
 } while(0)

/* Error message when trying to access past the end of a vector.
 > vector: the vector */
nonreturning_function(local, error_vector_index_range, (object vector)) {
  var uintL len = vector_length(vector);
  pushSTACK(UL_to_I(len));
  error_index_range(vector,len);
}

/* UP: Copies a part of sequence into another sequence.
 > STACK_6: sequence1
 > STACK_5: typdescr1
 > STACK_4: sequence2
 > STACK_3: typdescr2
 > STACK_2: count (an integer >=0)
 > STACK_1: pointer1
 > STACK_0: pointer2
 copies count elements from sequence1 to sequence2 and advances
 pointer1 and pointer2 for count elements (with SEQ-UPD), sets count:=0.
 can trigger GC */
local maygc void copy_seqpart_into (void) {
  /* Optimization for vectors: */
  if (vectorp(STACK_6) && vectorp(STACK_4) && posfixnump(STACK_2)) {
    var uintV count = posfixnum_to_V(STACK_2);
    if (count > 0) {
      var uintV index1v = posfixnum_to_V(STACK_1);
      var uintV index2v = posfixnum_to_V(STACK_0);
      if (index1v+count > vector_length(STACK_6))
        with_saved_back_trace_subr(L(aref),STACK STACKop -2,-1,
                                   error_vector_index_range(STACK_6); );
      if (index2v+count > vector_length(STACK_4))
        with_saved_back_trace_subr(L(store),STACK STACKop -3,-1,
                                   error_vector_index_range(STACK_4); );
      var uintL index1 = index1v;
      var uintL index2 = index2v;
      var object dv1 = array_displace_check(STACK_6,count,&index1);
      var object dv2 = array_displace_check(STACK_4,count,&index2);
      if (eq(dv1,dv2))
        elt_move(dv1,index1,dv2,index2,count);
      else
        elt_copy(dv1,index1,dv2,index2,count);
      STACK_1 = I_I_plus_I(STACK_1,STACK_2);
      STACK_0 = I_I_plus_I(STACK_0,STACK_2);
    }
  } else { /* Method like this:
    (loop
      (when (zerop count) (return))
      (SEQ2-ACCESS-SET sequence2 pointer2 (SEQ1-ACCESS sequence1 pointer1))
      (setq pointer1 (SEQ1-UPD pointer1))
      (setq pointer2 (SEQ2-UPD pointer2))
      (decf count)) */
    while (!eq(STACK_2,Fixnum_0)) { /* count (an integer) = 0 -> return */
      /* Construct (SEQ1-ACCESS seq1 pointer1): */
      pushSTACK(STACK_(6+0)); /* seq1 */
      pushSTACK(STACK_(1+1)); /* pointer1 */
      funcall(seq_access(STACK_(5+2)),2);
      /* Call (SEQ2-ACCESS-SET seq2 pointer2 ...): */
      pushSTACK(STACK_(4+0)); /* seq2 */
      pushSTACK(STACK_(0+1)); /* pointer2 */
      pushSTACK(value1);
      funcall(seq_access_set(STACK_(3+3)),3);
      /* pointer1 := (SEQ1-UPD seq1 pointer1) : */
      pointer_update(STACK_1,STACK_6,STACK_5);
      /* pointer2 := (SEQ2-UPD seq2 pointer2) : */
      pointer_update(STACK_0,STACK_4,STACK_3);
      /* count := (1- count) : */
      decrement(STACK_2);
    }
  }
}

LISPFUNNR(sequencep,1)
{ /* (SYS::SEQUENCEP object) checks, if object is a sequence. */
  var object typdescr = get_seq_type(popSTACK()); /* type descriptor or NIL */
  VALUES_IF(!(nullp(typdescr)));
}

LISPFUNN(defseq,1)
{ /* (SYSTEM::%DEFSEQ typdescr) extends the list of sequence types by
   typdescr (must be a Simple-Vector of length 16). */
  /* Construct (list typdescr): */
  var object new_cons = allocate_cons();
  Car(new_cons) = STACK_0;
  /* Construct (nconc SEQ_TYPES (list typdescr)): */
  Cdr(new_cons) = nreverse(O(seq_types)); /* (nreverse SEQ_TYPES) */
  O(seq_types) = nreverse(new_cons);
  /* return type (as symbol): */
  VALUES1(seq_type(popSTACK()));
}

/* Check the index argument for ELT and SETF ELT.
 > seq: the sequence
 > index: the index argument */
local void seq_check_index (object seq, object index) {
  if (!(posfixnump(index))) {
    pushSTACK(index);             /* TYPE-ERROR slot DATUM */
    pushSTACK(O(type_posfixnum)); /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(index); pushSTACK(S(elt));
    error(type_error,GETTEXT("~S: the index should be a fixnum >=0, not ~S"));
  }
  if (vectorp(seq)) { /* vector ==> */
    /* check index against active length (may be smaller than total size) */
    var uintL len = vector_length(seq);
    if (posfixnum_to_V(index) >= len) {
      pushSTACK(index);
      error_index_range(seq,len);
    }
  }
}


LISPFUNNR(elt,2) { /* (ELT sequence index), CLTL p. 248 */
  /* check sequence: */
  var object typdescr = get_valid_seq_type(STACK_1);
  /* check index: */
  seq_check_index(STACK_1,STACK_0);
  /* call SEQ-ELT: */
  funcall(seq_elt(typdescr),2); /* (SEQ-ELT sequence index) */
  /* value1 as value */
}

LISPFUNN(setelt,3) { /* ((SETF ELT) value sequence index), vgl. CLTL p. 248 */
  /* check sequence: */
  var object typdescr = get_valid_seq_type(STACK_1);
  /* check index: */
  seq_check_index(STACK_1,STACK_0);
  /* call SEQ-SET-ELT: */
  pushSTACK(STACK_2);               /* value */
  funcall(seq_set_elt(typdescr),3); /* (SEQ-SET-ELT sequence index value) */
  VALUES1(popSTACK());              /* value */
}

/* UP: Copies a sequence1 - part into sequence2 and returns sequence2 as value.
 copy_seqpart_onto()
 > Stack layout: seq1, typdescr1, seq2, typdescr2, count, pointer1
 < STACK: cleaned up
 < Value: filled seq2 */
local Values copy_seqpart_onto (void) {
  /* Stacklayout: seq1, typdescr1, seq2, typdescr2, count, pointer1. */
  pushSTACK(STACK_3); funcall(seq_init(STACK_(2+1)),1); /* (SEQ2-INIT seq2) */
  pushSTACK(value1);
  /* Stacklayout: seq1, typdescr1, seq2, typdescr2, count, pointer1, pointer2. */
  copy_seqpart_into(); /* Copy part of seq1 to seq2 */
  VALUES1(STACK_4); /* seq2 as value */
  skipSTACK(7);
}

/* UP: Returns a new allocated sequence part as value.
 subseq()
 > Stack layout: sequence, start, end, typdescr,
    with checked arguments (start,end integers >=0, start<=end)
 < STACK: cleaned up
 < Value: Copy of the specified sequence part */
local Values subseq (void) {
  STACK_1 = I_I_minus_I(STACK_1,STACK_2); /* count := (- end start) */
  /* Stack layout: sequence, start, count, typdescr. */
  pushSTACK(STACK_1); funcall(seq_make(STACK_(0+1)),1); /* (SEQ-MAKE count) */
  var object start = STACK_2;
  var object typdescr = STACK_0;
  STACK_2 = typdescr;
  pushSTACK(STACK_1);
  STACK_2 = value1;
  /* Stack layout: sequence, typdescr, seq2, typdescr, count. */
  pushSTACK(STACK_4); pushSTACK(start); funcall(seq_init_start(typdescr),2);
  pushSTACK(value1); /* (SEQ-INIT-START sequence start) */
  /* Stack layout: seq1, typdescr, seq2, typdescr, count, pointer1. */
  return_Values copy_seqpart_onto(); /* copy, seq2 as value */
}

LISPFUN(subseq,seclass_read,2,1,norest,nokey,0,NIL)
{ /* (SUBSEQ sequence start &optional end), CLTL p. 248 */
  /* Stack layout: sequence, start, end. */
  var object typdescr = get_valid_seq_type(STACK_2); /* check sequence */
  pushSTACK(typdescr);
  /* Stack layout: sequence, start, end, typdescr. */
  /* Default value for end is (length sequence): */
  if (!boundp(STACK_1)
     #ifdef X3J13_149
      || nullp(STACK_1)
     #endif
      ) { /* end not supplied -> set end:=(length sequence): */
    pushSTACK(STACK_3); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH sequence) */
    STACK_1 = value1;
  }
  /* Stack layout: sequence, start, end, typdescr. */
  /* Check start- and end- arguments: */
  test_start_end(&O(kwpair_start),&STACK_1);
  /* construct part: */
  return_Values subseq();
}

/* UP: Copies sequence1 into sequence2 and returns sequence2 as value.
 copy_seq_onto()
 > Stack layout: seq1, typdescr1, seq2, typdescr2, len
 < STACK: cleaned up
 < Value: filled seq2 */
local Values copy_seq_onto (void) {
  /* Stack layout: seq1, typdescr1, seq2, typdescr2, len. */
  pushSTACK(STACK_4); funcall(seq_init(STACK_(3+1)),1); /* (SEQ1-INIT seq1) */
  pushSTACK(value1);
  /* Stack layout: seq1, typdescr1, seq2, typdescr2, len, pointer1. */
  return_Values copy_seqpart_onto();
}

LISPFUNNR(copy_seq,1) { /* (COPY-SEQ sequence), CLTL p. 248 */
  /* Stack layout: sequence. */
  /* check sequence: */
  var object typdescr = get_valid_seq_type(STACK_0);
  pushSTACK(typdescr);
  /* Stack layout: sequence, typdescr. */
  pushSTACK(STACK_1); funcall(seq_length(typdescr),1);
  pushSTACK(value1); /* (SEQ-LENGTH sequence) */
  /* Stack layout: sequence, typdescr, len. */
  pushSTACK(STACK_0); funcall(seq_make(STACK_(1+1)),1); /* (SEQ-MAKE len) */
  pushSTACK(STACK_1); pushSTACK(STACK_(0+1)); STACK_2 = value1;
  /* Stack layout: seq1, typdescr, seq2, typdescr, len. */
  return_Values copy_seq_onto();
}

LISPFUNNR(length,1) { /* (LENGTH sequence), CLTL p. 248 */
  var object arg = popSTACK();
  if (consp(arg)) { /* arg is a Cons */
    var object tail = NIL;
    var object len = list_length(arg,&tail);
    if (nullp(len))
      error_proper_list_circular(S(length),arg);
    if (!nullp(tail))
      error_proper_list_dotted(S(length),tail);
    VALUES1(len);
    return;
  } else if (symbolp(arg)) { /* arg is a symbol */
    if (nullp(arg)) { /* other symbols are not sequences */
      VALUES1(Fixnum_0); /* NIL is a list of length 0 */
      return;
    }
  } else if (vectorp(arg)) { /* arg is a vector */
    VALUES1(fixnum(vector_length(arg))); /* vector length as fixnum */
    return;
  } else { /* arg is neither a list nor a vector */
    var object typdescr = get_valid_seq_type(arg); /* maybe error */
    /* other sequences: */
    pushSTACK(arg); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH arg) */
    return;
  }
  /* arg is not a sequence */
  error_sequence(arg);
}

LISPFUNNR(reverse,1) { /* (REVERSE sequence), CLTL p. 248 */
  var object arg = STACK_0;
  if (listp(arg)) { /* arg is a list */
    VALUES1(reverse(arg)); skipSTACK(1);
  } else { /* arg is another sequence */
    var object typdescr = get_valid_seq_type(arg);
    pushSTACK(typdescr);
    /* Stack layout: seq1, typdescr. */
    pushSTACK(arg); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH seq1) */
    pushSTACK(value1);
    /* Stack layout: seq1, typdescr, len. */
    pushSTACK(STACK_0); funcall(seq_make(STACK_(1+1)),1); /* (SEQ-MAKE len) */
    pushSTACK(value1);
    /* Stack layout: seq1, typdescr, count, seq2. */
    if (vectorp(STACK_3) && posfixnump(STACK_1)) {
      var uintV count = posfixnum_to_V(STACK_1);
      if (count > 0) {
        var uintL index1 = 0;
        var object dv1 = array_displace_check(STACK_3,count,&index1);
        var uintL index2 = 0;
        var object dv2 = array_displace_check(STACK_0,count,&index2); /* = STACK_0 */
        elt_reverse(dv1,index1,dv2,index2,count);
      }
    } else {
      pushSTACK(STACK_3); funcall(seq_fe_init(STACK_(2+1)),1); /* (SEQ-FE-INIT seq1) */
      pushSTACK(value1);
      /* Stack layout: seq1, typdescr, count, seq2, pointer1. */
      pushSTACK(STACK_1); funcall(seq_init(STACK_(3+1)),1); /* (SEQ-INIT seq2) */
      pushSTACK(value1);
      /* Stack layout: seq1, typdescr, count, seq2, pointer1, pointer2. */
      while (!eq(STACK_3,Fixnum_0)) { /* count (an integer) = 0 -> return */
        /* Construct (SEQ-ACCESS seq1 pointer1): */
        pushSTACK(STACK_5); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
        /* Call (SEQ-ACCESS-SET seq2 pointer2 ...): */
        pushSTACK(STACK_2); pushSTACK(STACK_(0+1)); pushSTACK(value1);
        funcall(seq_access_set(STACK_(4+3)),3); /* (SEQ-ACCESS-SET seq2 pointer2 ...) */
        /* pointer1 := (SEQ-FE-UPD seq1 pointer1) : */
        pointer_fe_update(STACK_1,STACK_5,STACK_4);
        /* pointer2 := (SEQ-UPD seq2 pointer2) : */
        pointer_update(STACK_0,STACK_2,STACK_4);
        /* count := (1- count) : */
        decrement(STACK_3);
      }
      skipSTACK(2);
    }
    VALUES1(STACK_0); /* return seq2 */
    skipSTACK(4);
  }
}

LISPFUNN(nreverse,1) { /* (NREVERSE sequence), CLTL p. 248 */
  var object seq = STACK_0;
  if (listp(seq)) { /* seq is a list */
    VALUES1(nreverse(seq));
    skipSTACK(1);
  } else if (vectorp(seq)) {
    if (true) {
      var uintL count = vector_length(seq);
      if (count > 0) {
        var uintL index = 0;
        var object dv = array_displace_check(seq,count,&index);
        elt_nreverse(dv,index,count);
      }
    } else { /* seq is a vector */
      var object typdescr = get_valid_seq_type(seq);
      pushSTACK(typdescr);
      /* Stack layout: seq, typdescr. */
      pushSTACK(seq); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH seq) */
      {
        var object len = value1;
        var object len2 = I_I_ash_I(len,Fixnum_minus1);
        pushSTACK(len2); /* (ASH len -1) = (FLOOR len 2) */
      }
      /* Stack layout: seq, typdescr, count. */
      pushSTACK(STACK_2); funcall(seq_init(STACK_(1+1)),1); /* (SEQ-INIT seq) */
      pushSTACK(value1);
      /* Stack layout: seq, typdescr, count, pointer1. */
      pushSTACK(STACK_3); funcall(seq_fe_init(STACK_(2+1)),1); /* (SEQ-FE-INIT seq) */
      pushSTACK(value1);
      /* Stack layout: seq, typdescr, count, pointer1, pointer2. */
      while (!eq(STACK_2,Fixnum_0)) { /* count (an integer) = 0 -> return */
        /* Construct (SEQ-ACCESS seq pointer1): */
        pushSTACK(STACK_4); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(3+2)),2); /* (SEQ-ACCESS seq pointer1) */
        pushSTACK(value1); /* and save */
        /* Construct (SEQ-ACCESS seq pointer2): */
        pushSTACK(STACK_(4+1)); pushSTACK(STACK_(0+1+1));
        funcall(seq_access(STACK_(3+1+2)),2); /* (SEQ-ACCESS seq pointer2) */
        /* Call (SEQ-ACCESS-SET seq pointer1 ...): */
        pushSTACK(STACK_(4+1)); pushSTACK(STACK_(1+1+1)); pushSTACK(value1);
        funcall(seq_access_set(STACK_(3+1+3)),3); /* (SEQ-ACCESS-SET seq pointer1 ...) */
        /* Call (SEQ-ACCESS-SET seq pointer2 ...): */
        {
          var object element1 = popSTACK(); /* saved element */
          pushSTACK(STACK_4); pushSTACK(STACK_(0+1)); pushSTACK(element1);
        }
        funcall(seq_access_set(STACK_(3+3)),3); /* (SEQ-ACCESS-SET seq pointer2 ...) */
        /* pointer1 := (SEQ-UPD seq pointer1) : */
        pointer_update(STACK_1,STACK_4,STACK_3);
        /* pointer2 := (SEQ-FE-UPD seq pointer2) : */
        pointer_fe_update(STACK_0,STACK_4,STACK_3);
        /* count := (1- count) : */
        decrement(STACK_2);
      }
      skipSTACK(4);
    }
    VALUES1(popSTACK()); /* return modified seq */
  } else { /* seq is a general sequence */
    var object typdescr = get_valid_seq_type(seq);
    pushSTACK(typdescr);
    /* Stack layout: seq, typdescr. */
    pushSTACK(seq); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH seq) */
    if (!(posfixnump(value1))) { /* should be a fixnum >=0 */
      pushSTACK(value1); pushSTACK(S(nreverse));
      error(error_condition,GETTEXT("~S: bad length ~S"));
    }
    {
      var uintV len = posfixnum_to_V(value1); /* len */
      /* Basic idea: To flip a sequence with len elements, the left and
         right block with each floor(len/2) elements must be swapped
         and then flipped one by one (recursively!); the middle
         element (with uneven len) stays intact.
         Iterative algorithm:
         For j=0,1,2,... there need to be 2^j times two (almost) adjacent blocks
         of length k2=floor(len/2^(j+1)) swapped. */
      var uintV j = 0; /* j := 0 */
      var uintV k = len; /* k = floor(len/2^j) := len */
      var uintV k2; /* k2 = floor(k/2) */
      var uintV k1; /* k1 = ceiling(k/2) */
      while ((k2 = floor(k,2)) != 0) { /* half of k =0 -> end of loop */
        k1 = k - k2; /* k1 = (old k) - (new k) = ceiling((old k)/2) */
        {
          var uintV pstack = 0; /* a pseudo-stack */
          /* Stack layout: seq, typdescr. */
          pushSTACK(STACK_1); funcall(seq_init(STACK_(0+1)),1); /* (SEQ-INIT seq) */
          pushSTACK(value1);
          /* Stack layout: seq, typdescr, pointer1. */
          pushSTACK(STACK_2); pushSTACK(fixnum(k1));
          funcall(seq_init_start(STACK_(1+2)),2); /* (SEQ-INIT-START seq k1) */
          pushSTACK(value1);
          /* Stack layout: seq, typdescr, pointer1, pointer2.
             pointer1 and pointer2 walk together through seq,
             pointer2 has an advantage of k1. */
          while (1) {
            /* Swap two blocks of length k2 = floor(len/2^(j+1)): */
            {
              var uintV i = k2; /* i:=k2 >0 */
              do {
                /* Contruct (SEQ-ACCESS seq pointer1): */
                pushSTACK(STACK_3); pushSTACK(STACK_(1+1));
                funcall(seq_access(STACK_(2+2)),2); /* (SEQ-ACCESS seq pointer1) */
                pushSTACK(value1); /* and save it */
                /* Contruct (SEQ-ACCESS seq pointer2): */
                pushSTACK(STACK_(3+1)); pushSTACK(STACK_(0+1+1));
                funcall(seq_access(STACK_(2+1+2)),2); /* (SEQ-ACCESS seq pointer2) */
                /* Call (SEQ-ACCESS-SET seq pointer1 ...): */
                pushSTACK(STACK_(3+1)); pushSTACK(STACK_(1+1+1)); pushSTACK(value1);
                funcall(seq_access_set(STACK_(2+1+3)),3); /* (SEQ-ACCESS-SET seq pointer1 ...) */
                /* Call (SEQ-ACCESS-SET seq pointer2 ...): */
                {
                  var object element1 = popSTACK(); /* saved element */
                  pushSTACK(STACK_3); pushSTACK(STACK_(0+1)); pushSTACK(element1);
                }
                funcall(seq_access_set(STACK_(2+3)),3); /* (SEQ-ACCESS-SET seq pointer2 ...) */
                /* pointer1 := (SEQ-UPD seq pointer1) : */
                pointer_update(STACK_1,STACK_3,STACK_2);
                /* pointer2 := (SEQ-FE-UPD seq pointer2) : */
                pointer_fe_update(STACK_0,STACK_3,STACK_2);
                --i; /* i:=i-1 */
              } while (i != 0); /* if i=0 end of loop */
            }
            pstack = pstack+1; /* stack:=stack+1 */
            if (pstack == vbit(j)) /* stack=2^j -> break the loop */
              break;
            /* advance pointer1 and pointer2 by k1+(0 or 1) elements: */
            {
              var uintV skipcount = k1;
              {
                var uintL r1 = 1;
                /* r := Number of zero-bits at the end of the binary representation of the stack: */
                {
                  var uintL pstackr = pstack;
                  while ((pstackr & vbit(0))==0) {
                    pstackr = pstackr>>1; r1=r1+1;
                  }
                }
                /* r1 = r+1 */
                if (len & vbit(j-r1)) /* Bit j-r-1 set in len? */
                  skipcount++; /* if yes: skipcount=k1+1, else skipcount=k1 */
              }
              /* skipcount >= k1 >= k2 > 0 */
              do {
                /* pointer1 := (SEQ-UPD seq pointer1) : */
                pointer_update(STACK_1,STACK_3,STACK_2);
                /* pointer2 := (SEQ-FE-UPD seq pointer2) : */
                pointer_fe_update(STACK_0,STACK_3,STACK_2);
                --skipcount;
              } while (skipcount != 0);
            }
          }
          skipSTACK(2); /* forget pointer1 and pointer2 */
        }
        j = j+1; k = k2; /* j:=j+1, half of k */
      }
    }
    skipSTACK(1); /* forget typdescr */
    VALUES1(popSTACK()); /* return modified seq */
  }
}

/* Verify complicated length constraint, by calling TYPEP:
 > retvalue: address on the STACK of the return value
 > rettype: address on the STACK of the return type
 can trigger GC */
local maygc void verify_return_value (gcv_object_t *retvalue,
                                      gcv_object_t *rettype) {
  pushSTACK(*retvalue); pushSTACK(*rettype); funcall(S(typep),2);
  if (nullp(value1)) {
    pushSTACK(*retvalue);       /* TYPE-ERROR slot DATUM */
    pushSTACK(*rettype);        /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(*rettype); pushSTACK(*retvalue);
    pushSTACK(TheSubr(subr_self)->name);
    error(type_error,GETTEXT("~S: the result ~S is not of type ~S"));
  }
}
#define VERIFY_RETURN_VALUE(retvalue,rettype)   \
  if (boundp(*rettype) && !integerp(*rettype))  \
    verify_return_value(retvalue,rettype)

LISPFUN(make_sequence,seclass_default,2,0,norest,key,2,
        (kw(initial_element),kw(update)) )
{ /* (MAKE-SEQUENCE type size [:initial-element] [:update]), CLTL p. 249
   with additional argument :update, e.g.
   (make-sequence 'vector 5 :initial-element 3 :update #'1+) ==> #(3 4 5 6 7) */
  /* Stack layout: type, size, initial-element, updatefun. */
  var object typdescr = valid_type(&STACK_3); /* Check type */
  /* Stack layout: type, size, initial-element, updatefun, type-len. */
  STACK_4 = typdescr;
  { /* Check size, must be an integer >=0: */
    var object size = STACK_3;
    if (!(integerp(size) && positivep(size))) {
      pushSTACK(size);               /* TYPE-ERROR slot DATUM */
      pushSTACK(O(type_posinteger)); /* TYPE-ERROR slot EXPECTED-TYPE */
      pushSTACK(size); pushSTACK(S(make_sequence));
      error(type_error,GETTEXT("~S: size should be an integer >=0, not ~S"));
    }
    /* Complete initial-element for strings from defaults: */
    if (!boundp(STACK_2)) { /* :initial-element not supplied? */
      if (boundp(STACK_1)) { /* :update without :initial-element -> Error */
        pushSTACK(S(make_sequence));
        error(error_condition,GETTEXT("~S: :UPDATE must not be specified without :INITIAL-ELEMENT"));
      } else if (posfixnump(seq_type(typdescr))) { /* type name integer? (means byte-vector) */
        STACK_2 = Fixnum_0; /* initial-element := 0 */
      }
    }
    if (integerp(STACK_0) && !SEQTYPE_LENGTH_MATCH(STACK_0,size))
      error_seqtype_length(STACK_0,size);
    pushSTACK(size); funcall(seq_make(typdescr),1); /* (SEQ-MAKE size) */
    /* Stack layout: typdescr, size, initial-element, updatefun, type-len. */
  }
  if (boundp(STACK_2)) /* :initial-element supplied? */
    if (!(eq(STACK_3,Fixnum_0))) { /* size (an integer) = 0 -> nothing to do */
      pushSTACK(value1);
      if (!boundp(STACK_(1+1))
          && vectorp(value1) && array_simplep(value1)
          && posfixnump(STACK_(3+1)) && uint32_p(STACK_(3+1))) {
        if (elt_fill(value1,0,posfixnum_to_V(STACK_(3+1)),STACK_(2+1)))
          error_store(STACK_0,STACK_(2+1));
      } else {
        /* Stack layout: typdescr, count, element, updatefun, type-len, seq. */
        pushSTACK(STACK_0); funcall(seq_init(STACK_(5+1)),1); /* (SEQ-INIT seq) */
        pushSTACK(value1);
        /* Stack layout: typdescr, count, element, updatefun, type-len, seq, pointer. */
        while (1) {
          pushSTACK(STACK_(1+0)); pushSTACK(STACK_(0+1)); pushSTACK(STACK_(4+2));
          funcall(seq_access_set(STACK_(6+3)),3); /* (SEQ-ACCESS-SET seq pointer element) */
          /* pointer := (SEQ-UPD seq pointer) : */
          pointer_update(STACK_0,STACK_1,STACK_6);
          /* count := (1- count) : */
          decrement(STACK_5);
          if (eq(STACK_5,Fixnum_0)) /* count (an integer) = 0 -> end of loop */
            break;
          var object updatefun = STACK_3;
          if (boundp(updatefun)) { /* if supplied, */
            pushSTACK(STACK_4); funcall(updatefun,1); /* (FUNCALL updatefun element) */
            STACK_4 = value1; /* =: element */
          }
        }
        skipSTACK(1); /* forget pointer */
      }
      value1 = popSTACK(); /* seq */
    }
  pushSTACK(value1);            /* save seq */
  VERIFY_RETURN_VALUE(&STACK_0,&STACK_1);
  VALUES1(popSTACK());          /* seq as value */
  skipSTACK(5);
}

/* UP: Converts an object into a sequence of the given type.
 coerce_sequence(obj,result_type,error_p)
 > obj: Object, should be sequence
 > result_type: Designator (Symbol) of the sequence type
 > error_p: when result_type is not a sequence:
            when true, signal an error; when false, return nullobj
 < Value: Sequence of type result_type
 can trigger GC */
global maygc Values coerce_sequence (object sequence, object result_type,
                                     bool error_p) {
  pushSTACK(sequence);
  pushSTACK(result_type);
  { /* check result-type: */
    var object typdescr2 =
      (error_p ? valid_type(&STACK_0) : valid_type1(&STACK_0));
    if (!error_p && nullp(typdescr2)) { /* result_type is not a sequence */
      VALUES1(nullobj); skipSTACK(3); return;
    }
    pushSTACK(typdescr2);
    /* Stack layout: seq1, result-type, typdescr2-len, typdescr2. */
    {
      var object typdescr1 = get_valid_seq_type(STACK_3); /* Type of seq1 */
      if (eq(seq_type(typdescr1),seq_type(typdescr2))) {
        /* both types equal -> nothing to do */
        skipSTACK(1);
        if (integerp(STACK_0)) {
          pushSTACK(STACK_2); funcall(seq_length(typdescr1),1); /* (SEQ1-LENGTH seq1) */
          if (!SEQTYPE_LENGTH_MATCH(STACK_0,value1))
            error_seqtype_length(STACK_0,value1);
        }
      } else {
        pushSTACK(typdescr1);
        pushSTACK(NIL);
        pushSTACK(STACK_2);
        STACK_3 = STACK_6;
        /* Stack layout: seq1, result-type, typdescr2-len,
                        seq1, typdescr1, nil, typdescr2. */
        pushSTACK(STACK_3); funcall(seq_length(typdescr1),1); /* (SEQ1-LENGTH seq1) */
        if (integerp(STACK_4) && !SEQTYPE_LENGTH_MATCH(STACK_4,value1))
          error_seqtype_length(STACK_4,value1);
        pushSTACK(value1);
        /* Stack layout: seq1, result-type, typdescr2-len,
                        seq1, typdescr1, nil, typdescr2, len. */
        pushSTACK(STACK_0); funcall(seq_make(STACK_(1+1)),1); /* (SEQ2-MAKE len) */
        STACK_2 = value1;
        /* Stack layout: seq1, result-type, typdescr2-len,
                        seq1, typdescr1, seq2, typdescr2, len. */
        copy_seq_onto();
        /* Stack layout: seq1, result-type, typdescr2-len. */
        STACK_2 = value1;
        /* Stack layout: result, result-type, typdescr2-len. */
      }
      VERIFY_RETURN_VALUE(&STACK_2,&STACK_0);
      skipSTACK(2); VALUES1(popSTACK()); /* return seq1 */
    }
  }
}

LISPFUN(coerced_subseq,seclass_default,2,0,norest,key,2, (kw(start),kw(end)) )
{ /*  (SYSTEM::COERCED-SUBSEQ sequence result-type [:start] [:end])
   == (COERCE (SUBSEQ sequence start end) result-type)
   except that only one sequence is allocated, not two.
   Note: result-type = ARRAY and = VECTOR are interpreted to mean GENERAL-VECTOR. */
  /* Stack layout: sequence, result-type, start, end. */
  { /* Check sequence: */
    var object typdescr = get_valid_seq_type(STACK_3);
    pushSTACK(typdescr);
  }
  /* Stack layout: sequence, result-type, start, end, typdescr. */
  { /* Check result-type: */
    var object typdescr2 = valid_type(&STACK_3);
    pushSTACK(typdescr2);
  }
  /* Stack layout: sequence, result-type, start, end, typdescr, typdescr2-len, typdescr2. */
  /* Default value for start is 0: */
  start_default_0(STACK_4);
  /* Default value for end is (length sequence): */
  end_default_len(STACK_3,STACK_6,STACK_2);
  /* Check start and end arguments: */
  test_start_end(&O(kwpair_start),&STACK_3);
  /* Determine result sequence length. */
  STACK_3 = I_I_minus_I(STACK_3,STACK_4); /* count := (- end start) */
  /* Stack layout: sequence, result-type, start, count, typdescr, typdescr2-len, typdescr2. */
  if (integerp(STACK_1) && !SEQTYPE_LENGTH_MATCH(STACK_1,STACK_3))
    error_seqtype_length(STACK_1,STACK_3);
  if (eq(seq_type(STACK_2),seq_type(STACK_0))) {
    /* Same types of sequences. */
    if (eq(STACK_4,Fixnum_0)) {
      /* With start = 0.
         Test (= count (length sequence))
         via (SEQ-ENDTEST sequence (SEQ-INIT-START sequence count)): */
      pushSTACK(STACK_6); pushSTACK(STACK_(3+1)); funcall(seq_init_start(STACK_(2+2)),2);
      pushSTACK(STACK_6); pushSTACK(value1); funcall(seq_endtest(STACK_(2+2)),2);
      if (!nullp(value1)) {
        /* With end = (length sequence).
           Nothing to do. */
        VERIFY_RETURN_VALUE(&STACK_6,&STACK_1);
        skipSTACK(6); VALUES1(popSTACK()); /* return sequence */
        return;
      }
    }
  }
  STACK_5 = STACK_1; pushSTACK(STACK_3); STACK_4 = STACK_7;
  /* Stack layout: sequence, typdescr2-len, start,
                   sequence, typdescr, typdescr2-len, typdescr2, count. */
  /* Allocate new sequence. */
  pushSTACK(STACK_0); funcall(seq_make(STACK_(1+1)),1); /* (SEQ2-MAKE count) */
  STACK_2 = value1;
  /* Stack layout: sequence, typdescr2-len, start,
                   sequence, typdescr, seq2, typdescr2, count. */
  pushSTACK(STACK_4); pushSTACK(STACK_(5+1));
  funcall(seq_init_start(STACK_(3+2)),2); pushSTACK(value1);
  /* Stack layout: sequence, typdescr2-len, start,
                   sequence, typdescr, seq2, typdescr2, count, pointer1. */
  copy_seqpart_onto(); /* copy, return seq2 */
  STACK_2 = value1;
  /* Stack layout: result, typdescr2-len, start. */
  VERIFY_RETURN_VALUE(&STACK_2,&STACK_1);
  skipSTACK(2); VALUES1(popSTACK()); /* return result */
}

LISPFUN(concatenate,seclass_rd_sig,1,0,rest,nokey,0,NIL)
{ /* (CONCATENATE result-type {sequence}), CLTL p. 249 */
  var gcv_object_t* args_pointer = rest_args_pointer;
  { /* convert result-type to type descriptor: */
    var object type = valid_type(&Before(args_pointer));
    BEFORE(args_pointer) = type;
  }
  /* args_pointer = pointer to the arguments,
     rest_args_pointer = Pointer to the argcount sequence arguments.
     Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len, [STACK].
     Requires 2*argcount STACK entries: */
  get_space_on_STACK(sizeof(gcv_object_t) * 2*(uintL)argcount);
  var gcv_object_t* behind_args_pointer = args_end_pointer; /* Pointer below the arguments */
  /* Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len, [behind_args_pointer].
     Compute type descriptors and lengths and push onto the STACK: */
  if (argcount > 0) {
    var gcv_object_t* ptr = rest_args_pointer;
    var uintC count = argcount;
    do {
      var object seq = NEXT(ptr); /* next sequence */
      var object typdescr = get_valid_seq_type(seq);
      pushSTACK(typdescr); /* type descriptor to the stack */
      pushSTACK(seq); funcall(seq_length(typdescr),1); /* (SEQ-LENGTH seq) */
      pushSTACK(value1); /* length to the stack */
    } while (--count);
  }
  /* Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len,
                  [behind_args_pointer] {typdescr, len}, [STACK]. */
  { /* Add lengths: */
    var object total_length = Fixnum_0;
    if (argcount > 0) {
      var gcv_object_t* ptr = behind_args_pointer;
      var uintC count = argcount;
      do {
        ptr skipSTACKop -2; /* skip typdescr */
        var object len = Before(ptr); /* next length  */
        if (!(posfixnump(len))) {
          pushSTACK(len); pushSTACK(S(concatenate));
          error(error_condition,GETTEXT("~S: bad length ~S"));
        }
        total_length = I_I_plus_I(total_length,len); /* total_length += len */
      } while (--count);
    }
    {
      var object result_type_len = Before(behind_args_pointer);
      if (integerp(result_type_len)
          && !SEQTYPE_LENGTH_MATCH(result_type_len,total_length))
        error_seqtype_length(result_type_len,total_length);
    }
    pushSTACK(NIL); pushSTACK(NIL); pushSTACK(NIL); /* Dummies */
    { /* allocate new sequence: */
      var gcv_object_t* ptr = args_pointer;
      var object typdescr2 = NEXT(ptr);
      pushSTACK(typdescr2);
      pushSTACK(total_length); funcall(seq_make(typdescr2),1); /* (SEQ2-MAKE total_length) */
      STACK_1 = value1; /* =: seq2 */
    }
  }
  /* Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len,
                  [behind_args_pointer] {typdescr, len},
                  NIL, NIL, seq2, typdescr2, [STACK]. */
  pushSTACK(NIL); pushSTACK(NIL); /* Dummies */
  /* Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len,
                  [behind_args_pointer] {typdescr, len},
                  NIL, NIL, seq2, typdescr2, NIL, NIL, [STACK]. */
  pushSTACK(STACK_(3)); funcall(seq_init(STACK_(2+1)),1); /* (SEQ-INIT seq2) */
  pushSTACK(value1);
  /* Stack layout: [args_pointer] typdescr2,
                  [rest_args_pointer] {sequence}, result-type-len,
                  [behind_args_pointer] {typdescr, len},
                  NIL, NIL, seq2, typdescr2, NIL, NIL, pointer2, [STACK].
     Loop over the argcount sequences: copy into seq2 */
  var gcv_object_t* current_arg_pointer = behind_args_pointer;
  while (argcount--) {
    STACK_6 = NEXT(rest_args_pointer); /* seq1 = next sequence */
    STACK_5 = NEXT(current_arg_pointer); /* its typdescr1 */
    STACK_2 = NEXT(current_arg_pointer); /* its length */
    pushSTACK(STACK_6); funcall(seq_init(STACK_(5+1)),1); /* (SEQ1-INIT seq1) */
    STACK_1 = value1; /* =: pointer1 */
    /* Stack layout: [args_pointer] typdescr2,
                    [rest_args_pointer] {sequence}, result-type-len,
                    [behind_args_pointer] {typdescr, len},
                    seq1, typdescr1, seq2, typdescr2, count,
                    pointer1, pointer2, [STACK]. */
    copy_seqpart_into(); /* Copy complete seq1 into seq2 */
  }
  VERIFY_RETURN_VALUE(&STACK_4,&(Before(behind_args_pointer)));
  VALUES1(STACK_4); /* return seq2 */
  set_args_end_pointer(args_pointer); /* clean up STACK */
}

/* UP: Walks through a sequence and executes a function for every element.
 map_sequence(obj,fun,arg);
 > obj: Object, should be a sequence
 > fun: Function, fun(arg,element) can trigger GC
 > arg: any specified argument
 can trigger GC */
modexp maygc void map_sequence
(object obj, map_sequence_function_t* fun, void* arg) {
  var object typdescr = get_valid_seq_type(obj);
  pushSTACK(typdescr);
  pushSTACK(obj);
  pushSTACK(obj); funcall(seq_init(typdescr),1); /* (SEQ-INIT obj) */
  pushSTACK(value1);
  /* Stack layout: typdescr, sequence, pointer. */
  while (1) {
    /* (SEQ-ENDTEST sequence pointer) : */
    pushSTACK(STACK_1); pushSTACK(STACK_1); funcall(seq_endtest(STACK_4),2);
    if (!nullp(value1))
      break;
    /* (SEQ-ACCESS sequence pointer) : */
    pushSTACK(STACK_1); pushSTACK(STACK_1); funcall(seq_access(STACK_4),2);
    /* Execute user function: */
    (*fun)(arg,value1);
    /* pointer := (SEQ-UPD sequence pointer) : */
    pushSTACK(STACK_1); pushSTACK(STACK_1); funcall(seq_upd(STACK_4),2);
    STACK_0 = value1;
  }
  skipSTACK(3);
}

/* UP: Executes a boolean operation with a predicate like SOME or EVERY.
 > Stack layout: [args_pointer] ... predicate sequence,
                [rest_args_pointer] {sequence} [STACK].
 > fun: Function, which checks the predicate result and
        returns true (and leaves the result in value1),
        if this function should break the loop.
 > argcount: Number of sequence arguments - 1
 > default: Default value at the end
 < 1 Value: as left by fun at the break, or default.
 < STACK: cleaned up (= args_pointer at the top)
 can trigger GC */
typedef bool seq_boolop_fun (object pred_result);
local maygc Values seq_boolop (seq_boolop_fun* boolop_fun,
                               gcv_object_t* args_pointer,
                               gcv_object_t* rest_args_pointer,
                               uintC argcount,
                               object defolt) {
  rest_args_pointer skipSTACKop 1;
  {
    var object predicate = Before(rest_args_pointer);
    if (!(symbolp(predicate) || functionp(predicate)))
      Before(rest_args_pointer) = check_function(predicate);
  }
  /* rest_args_pointer points now over all argcount+1 sequence arguments */
  pushSTACK(defolt); /* Save default value */
  /* Allocate space for 3*(argcount+1) objects on the STACK:
     (2 times for type descriptors and pointer, 1 time for the function call) */
  get_space_on_STACK(sizeof(gcv_object_t)*3*(uintL)(argcount+1));
  var gcv_object_t* typdescr_pointer = args_end_pointer; /* Pointer over the type descriptors */
  /* Get the type descriptors and a pointer for each of the argcount+1
     sequences and put them on the STACK: */
  {
    var gcv_object_t* ptr = rest_args_pointer;
    var uintC count = argcount+1;
    do {
      var object seq = NEXT(ptr); /* next sequence */
      var object typdescr = get_valid_seq_type(seq);
      pushSTACK(typdescr); /* push type descriptor to the STACK */
      pushSTACK(seq); funcall(seq_init(typdescr),1); /* (SEQ-INIT sequence) */
      pushSTACK(value1); /* push pointer to the STACK */
    } while (--count);
  }
  /* Stack layout:
             [args_pointer] ... predicate,
             [rest_args_pointer] {sequence}, default,
             [typdescr_pointer] {typdescr, pointer}, [STACK].
     Loop: Call the function: */
  while (1) {
    var gcv_object_t* ptr1 = rest_args_pointer;
    var gcv_object_t* ptr2 = typdescr_pointer;
    /* ptr1 runs from the top through the sequences,
       ptr2 runs from the top through the typdescr/pointers. */
    var uintC count = argcount+1;
    do {
      var gcv_object_t* sequence_ = &NEXT(ptr1);
      var gcv_object_t* typdescr_ = &NEXT(ptr2);
      var gcv_object_t* pointer_ = &NEXT(ptr2);
      /* (SEQ-ENDTEST sequence pointer) : */
      pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_endtest(*typdescr_),2);
      /* End of one of the sequences -> end outer loop: */
      if (!(nullp(value1)))
        goto end_with_default;
      /* (SEQ-ACCESS sequence pointer) : */
      pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_access(*typdescr_),2);
      /* put as argument to the STACK: */
      pushSTACK(value1);
      /* pointer := (SEQ-UPD sequence pointer) : */
      pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_upd(*typdescr_),2);
      *pointer_ = value1;
    } while (--count);
    /* Finished with all sequences.
       Call (FUNCALL predicate (SEQ-ACCESS sequence pointer) ...): */
    {
      var gcv_object_t* ptr = rest_args_pointer;
      var object predicate = BEFORE(ptr);
      funcall(predicate,argcount+1);
    }
    /* Call the checker and break if true: */
    if ((*boolop_fun)(value1))
      goto end_with_value1;
  }
 end_with_default:
  {
    var gcv_object_t* ptr = typdescr_pointer;
    value1 = BEFORE(ptr); /* default as value */
  }
 end_with_value1:
  mv_count=1; /* 1 value */
  set_args_end_pointer(args_pointer); /* clean up STACK */
}

/* Helper function for MAP: */
local bool boolop_nothing (object pred_result)
{
  return false; /* never return if inside */
}

LISPFUN(map,seclass_default,3,0,rest,nokey,0,NIL)
{ /* (MAP result-type function sequence {sequence}), CLTL p. 249 */
  var gcv_object_t* args_pointer = rest_args_pointer STACKop 3;
  /* args_pointer = pointer over the arguments,
     rest_args_pointer = pointer over the next argcount sequence arguments. */
  var gcv_object_t* result_type_ = &Next(args_pointer);
  /* result_type_ points into the STACK, to result-type. */
  if (!(nullp(*result_type_))) {
    /* general result-type */
    rest_args_pointer skipSTACKop 1;
    /* rest_args_pointer now points over all argcount+1 sequence arguments
       Allocate 4*(argcount+1) objects on the STACK:
       (3 times for type descriptors and pointer, 1 time for function call) */
    get_space_on_STACK(sizeof(gcv_object_t)*4*(uintL)(argcount+1));
    /* Check result-type: */
    *result_type_ = valid_type(result_type_);
    var gcv_object_t* typdescr_pointer = args_end_pointer; /* Pointer over the type descriptors */
    /* Get type descriptors and two pointers to each of the argcount+1
       sequences and push it onto the STACK: */
    {
      var gcv_object_t* ptr = rest_args_pointer;
      var uintC count = argcount+1;
      do {
        var gcv_object_t* sequence_ = &NEXT(ptr);
        var object seq = *sequence_; /* next sequence */
        var object typdescr = get_valid_seq_type(seq);
        pushSTACK(typdescr); /* type descriptor to the STACK */
        pushSTACK(seq); funcall(seq_init(typdescr),1); /* (SEQ-INIT sequence) */
        pushSTACK(value1); /* pointer to the STACK */
        pushSTACK(*sequence_); funcall(seq_init(STACK_(1+1)),1); /* (SEQ-INIT sequence) */
        pushSTACK(value1); /* pointer to the STACK */
      } while (--count);
    }
    /* Stack layout:
               [args_pointer] *result_type_ = typdescr2, function,
               [rest_args_pointer] {sequence}, result-type-len,
               [typdescr_pointer] {typdescr, pointer, pointer}, [STACK].
       Get minimal length of all sequences, by running through with the second pointer: */
    pushSTACK(Fixnum_0); /* minlength:=0 */
    while (1) {
      var gcv_object_t* ptr1 = rest_args_pointer;
      var gcv_object_t* ptr2 = typdescr_pointer;
      /* ptr1 runs from the top through the sequences,
         ptr2 runs from the top through the type descriptors/pointers. */
      var uintC count = argcount+1;
      do {
        var gcv_object_t* sequence_ = &NEXT(ptr1);
        var gcv_object_t* typdescr_ = &NEXT(ptr2);
        ptr2 skipSTACKop -1;
        var gcv_object_t* pointer_ = &NEXT(ptr2);
        /* (SEQ-ENDTEST sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_endtest(*typdescr_),2);
        /* one of the sequences ended -> finish outer loop: */
        if (!(nullp(value1)))
          goto end_found;
        /* pointer := (SEQ-UPD sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_upd(*typdescr_),2);
        *pointer_ = value1;
      } while (--count);
      /* None of the sequences ended. */
      STACK_0 = fixnum_inc(STACK_0,1); /* minlength := minlength+1 */
    }
   end_found: {
    /* STACK_0 = minimal length of the sequences
       Stack layout:
               [args_pointer] *result_type_ = typdescr2, function,
               [rest_args_pointer] {sequence}, result-type-len,
               [typdescr_pointer] {typdescr, pointer, pointer},
               size [STACK]. */
      var object result_type_len = Before(typdescr_pointer);
      if (integerp(result_type_len)
          && !SEQTYPE_LENGTH_MATCH(result_type_len,STACK_0))
        error_seqtype_length(result_type_len,STACK_0);
    }
    /* Allocate new sequence of length size: */
    pushSTACK(STACK_0); funcall(seq_make(*result_type_),1); /* (SEQ2-MAKE size) */
    pushSTACK(value1); /* Push seq2 to STACK */
    pushSTACK(STACK_0); funcall(seq_init(*result_type_),1); /* (SEQ2-INIT seq2) */
    pushSTACK(value1); /* Push pointer2 to STACK */
    /* Stack layout:
               [args_pointer] *result_type_ = typdescr2, function,
               [rest_args_pointer] {sequence}, result-type-len,
               [typdescr_pointer] {typdescr, pointer, pointer},
               size, seq2, pointer2 [STACK].
       Call function size times, put result into seq2: */
    while (!eq(STACK_2,Fixnum_0)) { /* count (an integer) = 0 -> finished */
      var gcv_object_t* ptr1 = rest_args_pointer;
      var gcv_object_t* ptr2 = typdescr_pointer;
      /* ptr1 runs from the top through the sequences,
         ptr2 runs from the top through the type descriptors/pointers. */
      var uintC count = argcount+1;
      do {
        var gcv_object_t* sequence_ = &NEXT(ptr1);
        var gcv_object_t* typdescr_ = &NEXT(ptr2);
        var gcv_object_t* pointer_ = &NEXT(ptr2);
        ptr2 skipSTACKop -1;
        /* (SEQ-ACCESS sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_access(*typdescr_),2);
        /* Push as argument to the STACK: */
        pushSTACK(value1);
        /* pointer := (SEQ-UPD sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_upd(*typdescr_),2);
        *pointer_ = value1;
      } while (--count);
      /* Process all sequences.
         Call (FUNCALL function (SEQ-ACCESS sequence pointer) ...): */
      funcall(*(result_type_ STACKop -1),argcount+1);
      /* Call (SEQ2-ACCESS-SET seq2 pointer2 ...): */
      pushSTACK(STACK_(1+0)); pushSTACK(STACK_(0+1)); pushSTACK(value1);
      funcall(seq_access_set(*result_type_),3);
      /* pointer2 := (SEQ2-UPD seq2 pointer2) : */
      pointer_update(STACK_0,STACK_1,*result_type_);
      /* size := (1- size) : */
      STACK_2 = fixnum_inc(STACK_2,-1);
    }
    VERIFY_RETURN_VALUE(&STACK_1,&(Before(typdescr_pointer)));
    VALUES1(STACK_1); /* return seq2 */
    set_args_end_pointer(args_pointer); /* clean up STACK */
  } else {
    /* result-type = NIL -> much easier:
       seq_boolop with boolop_nothing as function and NIL as (default-)value.
       So function is called on each element in the sequence. */
    return_Values seq_boolop(&boolop_nothing,args_pointer,rest_args_pointer,argcount,NIL);
  }
}

LISPFUN(map_into,seclass_default,2,0,rest,nokey,0,NIL)
/* (MAP-INTO result-sequence function {sequence}), CLtL2 p. 395 */
{
  var gcv_object_t* args_pointer = rest_args_pointer STACKop 2;
  /* args_pointer = Pointer over the arguments,
     rest_args_pointer = Pointer over the argcount sequence arguments.
     Allocate size for 3*argcount objects on the STACK:
     (2 times for type descriptors and pointer, 1 time for function call) */
  get_space_on_STACK(sizeof(gcv_object_t)*3*(uintL)argcount);
  /* result-sequence for simplicity also into the STACK: */
  pushSTACK(Next(args_pointer));
  var gcv_object_t* typdescr_pointer = args_end_pointer; /* Pointer over the type descriptors */
  /* Get type descriptors and pointers to each of the argcount+1
     sequences and push to the STACK: */
  {
    var gcv_object_t* ptr = rest_args_pointer;
    var uintC count = argcount+1;
    do {
      var object seq = NEXT(ptr);
      var object typdescr = get_valid_seq_type(seq);
      pushSTACK(typdescr); /* Push type descriptor to the STACK */
      pushSTACK(seq); funcall(seq_init(typdescr),1); /* (SEQ-INIT sequence) */
      pushSTACK(value1); /* Push pointer to the STACK */
    } while (--count);
  }
  /* Stack layout:
             [args_pointer] result-sequence, function,
             [rest_args_pointer] {sequence}, result-sequence,
             [typdescr_pointer] {typdescr, pointer},
             result-typdescr, result-pointer, [STACK].
     Call as often as necessary the function, add result to result-sequence: */
  while (1) {
    { /* Test, if another iteration necessary: */
      var gcv_object_t* ptr1 = rest_args_pointer;
      var gcv_object_t* ptr2 = typdescr_pointer;
      /* ptr1 runs from the top through the sequences,
         ptr2 runs from the top through the type descriptors/pointers. */
      var uintC count = argcount;
      while (count--) {
        var object sequence = NEXT(ptr1);
        var object typdescr = NEXT(ptr2);
        var object pointer = NEXT(ptr2);
        /* (SEQ-ENDTEST sequence pointer) : */
        pushSTACK(sequence); pushSTACK(pointer); funcall(seq_endtest(typdescr),2);
        /* one of the sequences finished -> finish outer loop: */
        if (!nullp(value1))
          goto end_reached;
      }
      { /* result-sequence finished -> finish outer loop: */
        var object sequence = NEXT(ptr1);
        var object typdescr = NEXT(ptr2);
        var object pointer = NEXT(ptr2);
        if (vectorp(sequence)) {
          /* With the result-sequence the fill-pointer is ignored.
             pointer is the index as fixnum. */
          if (posfixnum_to_V(pointer) >= array_total_size(sequence))
            goto end_reached;
        } else {
          /* (SEQ-ENDTEST sequence pointer) : */
          pushSTACK(sequence); pushSTACK(pointer); funcall(seq_endtest(typdescr),2);
          if (!nullp(value1))
           goto end_reached;
        }
      }
    }
    { /* Now call the function: */
      var gcv_object_t* ptr1 = rest_args_pointer;
      var gcv_object_t* ptr2 = typdescr_pointer;
      /* ptr1 runs from the top through the sequences,
         ptr2 runs from the top through the type descriptors/pointers. */
      var uintC count = argcount;
      while (count--) {
        var gcv_object_t* sequence_ = &NEXT(ptr1);
        var gcv_object_t* typdescr_ = &NEXT(ptr2);
        var gcv_object_t* pointer_ = &NEXT(ptr2);
        /* (SEQ-ACCESS sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_access(*typdescr_),2);
        /* als Argument auf den STACK legen: */
        pushSTACK(value1);
        /* pointer := (SEQ-UPD sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_upd(*typdescr_),2);
        *pointer_ = value1;
      }
      /* Run through all sequences
         Call (FUNCALL function (SEQ-ACCESS sequence pointer) ...): */
      funcall(Before(rest_args_pointer),argcount);
      { /* Call (SEQ-ACCESS-SET result-sequence result-pointer ...): */
        var gcv_object_t* sequence_ = &NEXT(ptr1);
        var gcv_object_t* typdescr_ = &NEXT(ptr2);
        var gcv_object_t* pointer_ = &NEXT(ptr2);
        pushSTACK(*sequence_); pushSTACK(*pointer_); pushSTACK(value1);
        funcall(seq_access_set(*typdescr_),3);
        /* pointer := (SEQ-UPD sequence pointer) : */
        pushSTACK(*sequence_); pushSTACK(*pointer_); funcall(seq_upd(*typdescr_),2);
        *pointer_ = value1;
      }
    }
  }
 end_reached: {
    var object result = Next(args_pointer);
    if (vectorp(result) && array_has_fill_pointer_p(result)) {
      /* (SYS::SET-FILL-POINTER result-sequence result-pointer) */
      pushSTACK(result); pushSTACK(STACK_(0+1)); funcall(L(set_fill_pointer),2);
    }
  }
  value1 = Next(args_pointer); /* result-sequence as value */
  set_args_end_pointer(args_pointer); /* Cleanup STACK */
}

/* Helper function for SOME: */
local bool boolop_some (object pred_result) {
  if (nullp(pred_result)) /* Check predicate */
    return false; /* =NIL -> continue search */
  else {
    value1 = pred_result; /* /=NIL -> this as value */
    return true;
  }
}

LISPFUN(some,seclass_default,2,0,rest,nokey,0,NIL)
{ /* (SOME predicate sequence {sequence}), CLTL p. 250 */
  return_Values seq_boolop(&boolop_some,rest_args_pointer STACKop 2,
                           rest_args_pointer,argcount,NIL);
}

/* Helper function for EVERY: */
local bool boolop_every (object pred_result) {
  if (!(nullp(pred_result))) { /* check function return value */
    return false; /* /=NIL -> proceed with search */
  } else {
    value1 = pred_result; /* =NIL -> return this (= NIL) */
    return true;
  }
}

LISPFUN(every,seclass_default,2,0,rest,nokey,0,NIL)
{ /* (EVERY predicate sequence {sequence}), CLTL p. 250 */
  return_Values seq_boolop(&boolop_every,rest_args_pointer STACKop 2,
                           rest_args_pointer,argcount,T);
}

/* Helper function for NOTANY: */
local bool boolop_notany (object pred_result) {
  if (nullp(pred_result)) { /* check function return value */
    return false; /* =NIL -> proceed with search */
  } else {
    value1 = NIL; /* /=NIL -> return NIL */
    return true;
  }
}

LISPFUN(notany,seclass_default,2,0,rest,nokey,0,NIL)
{ /* (NOTANY predicate sequence {sequence}), CLTL p. 250 */
  return_Values seq_boolop(&boolop_notany,rest_args_pointer STACKop 2,
                           rest_args_pointer,argcount,T);
}

/* Helper function for NOTEVERY: */
local bool boolop_notevery (object pred_result) {
  if (!(nullp(pred_result))) { /* check function return value */
    return false; /* /=NIL -> proceed with search */
  } else {
    value1 = T; /* =NIL -> return T */
    return true;
  }
}

LISPFUN(notevery,seclass_default,2,0,rest,nokey,0,NIL)
{ /* (NOTEVERY predicate sequence {sequence}), CLTL p. 250 */
  return_Values seq_boolop(&boolop_notevery,rest_args_pointer STACKop 2,
                           rest_args_pointer,argcount,NIL);
}

LISPFUN(reduce,seclass_default,2,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(initial_value)) )
{ /* (REDUCE function sequence [:from-end] [:start] [:end] [:key]
             [:initial-value]), CLTL p. 251, CLTL2 p. 397
  Stack layout: function, sequence, from-end, start, end, key, initial-value. */
  pushSTACK(get_valid_seq_type(STACK_5)); /* check sequence */
  /* Stack layout: function, sequence, from-end, start, end, key, initial-value,
                  typdescr. */
  check_key_arg(&STACK_(1+1)); /* key check */
  start_default_0(STACK_(3+1)); /* Default value for start is 0 */
  /* Default value for end is the length of the sequence: */
  end_default_len(STACK_(2+1),STACK_(5+1),STACK_0);
  /* check start- and end arguments: */
  test_start_end(&O(kwpair_start),&STACK_(2+1));
  { /* subtract and compare start- and end arguments: */
    var object count = I_I_minus_I(STACK_(2+1),STACK_(3+1));
    /* count = (- end start), an integer >=0. */
    if (eq(count,Fixnum_0)) { /* count = 0 ? */
      /* start and end are equal */
      if (!boundp(STACK_(0+1))) { /* initial-value supplied? */
        /* no -> call function with 0 arguments: */
        funcall(STACK_(6+1),0);
      } else {
        /* yes -> initial-value as result value: */
        VALUES1(STACK_(0+1));
      }
      skipSTACK(7+1);
      return;
    }
    /* common case: start < end, count > 0 */
    pushSTACK(count);
  }
  /* Stack layout: function, sequence, from-end, start, end, key, initial-value,
                   typdescr, count. */
  /* check from-end: */
  if (!missingp(STACK_(4+2))) { /* from-end is given and /=NIL */
    /* Set running pointer: */
    pushSTACK(STACK_(5+2)); pushSTACK(STACK_(2+2+1));
    funcall(seq_fe_init_end(STACK_(1+2)),2); /* (SEQ-FE-INIT-END seq end) */
    pushSTACK(value1); /* =: pointer */
    /* Stack layout: function, sequence, from-end, start, end, key,
                      initial-value, typdescr, count, pointer. */
    /* Calc start value: */
    if (!boundp(STACK_(0+3))) {
      /* initial-value is not given */
      pushSTACK(STACK_(5+3)); pushSTACK(STACK_(0+1));
      funcall(seq_access(STACK_(2+2)),2); /* (SEQ-ACCESS seq pointer) */
      funcall_key(STACK_(1+3),value1); /* (FUNCALL key (SEQ-ACCESS seq pointer)) */
      pushSTACK(value1); /* =: value */
      goto into_fromend_loop;
    } else { /* initial-value is given */
      pushSTACK(STACK_(0+3)); /* value := initial-value */
    }
    /* Stack layout: function, seq, from-end, start, end, key, initial-value,
                     typdescr, count, pointer, value. */
    do {
      /* calc next value: */
      pushSTACK(STACK_(5+4)); pushSTACK(STACK_(1+1));
      funcall(seq_access(STACK_(3+2)),2); /* (SEQ-ACCESS seq pointer) */
      funcall_key(STACK_(1+4),value1); /* (FUNCALL key (SEQ-ACCESS seq pointer)) */
      pushSTACK(value1); pushSTACK(STACK_(0+1));
      funcall(STACK_(6+4+2),2); /* (FUNCALL fun (FUNCALL key (SEQ-ACCESS seq pointer)) value) */
      STACK_0 = value1; /* =: value */
      into_fromend_loop:
      /* Advance pointer: */
      pointer_fe_update(STACK_1,STACK_(5+4),STACK_3);
      /* count := (1- count) : */
      decrement(STACK_2);
    } while (!eq(STACK_2,Fixnum_0)); /* count (an integer) = 0 ? */
    VALUES1(popSTACK()); /* return value */
    skipSTACK(7+3);
  } else { /* from-end is not given */
    /* Set running pointer: */
    pushSTACK(STACK_(5+2)); pushSTACK(STACK_(3+2+1));
    funcall(seq_init_start(STACK_(1+2)),2); /* (SEQ-INIT-START seq start) */
    pushSTACK(value1); /* =: pointer */
    /* Stack layout: function, sequence, from-end, start, end, key,
                     initial-value, typdescr, count, pointer. */
    /* Calc start value: */
    if (!boundp(STACK_(0+3))) { /* initial-value is not given */
      pushSTACK(STACK_(5+3)); pushSTACK(STACK_(0+1));
      funcall(seq_access(STACK_(2+2)),2); /* (SEQ-ACCESS seq pointer) */
      funcall_key(STACK_(1+3),value1); /* (FUNCALL key (SEQ-ACCESS seq pointer)) */
      pushSTACK(value1); /* =: value */
      goto into_fromstart_loop;
    } else { /* initial-value is given */
      pushSTACK(STACK_(0+3)); /* value := initial-value */
    }
    /* Stack layout: function, seq, from-end, start, end, key, initial-value,
                     typdescr, count, pointer, value. */
    do {
      /* Calculate next value: */
      pushSTACK(STACK_(5+4)); pushSTACK(STACK_(1+1));
      funcall(seq_access(STACK_(3+2)),2); /* (SEQ-ACCESS seq pointer) */
      funcall_key(STACK_(1+4),value1); /* (FUNCALL key (SEQ-ACCESS seq pointer)) */
      pushSTACK(STACK_0); pushSTACK(value1);
      funcall(STACK_(6+4+2),2); /* (FUNCALL fun value (FUNCALL key (SEQ-ACCESS seq pointer))) */
      STACK_0 = value1; /* =: value */
      into_fromstart_loop:
      /* Advance pointer: */
      pointer_update(STACK_1,STACK_(5+4),STACK_3);
      /* count := (1- count) : */
      decrement(STACK_2);
    } while (!eq(STACK_2,Fixnum_0)); /* count (an integer) = 0 ? */
    VALUES1(popSTACK()); /* return value */
    skipSTACK(7+3);
  }
}

LISPFUN(fill,seclass_default,2,0,norest,key,2, (kw(start),kw(end)) )
/* (FILL sequence item [:start] [:end]), CLTL p. 252 */
{ /* Stack layout: sequence, item, start, end. */
  /* sequence check: */
  pushSTACK(get_valid_seq_type(STACK_3));
  /* Stack layout: sequence, item, start, end, typdescr. */
  /* Default value for start is 0: */
  start_default_0(STACK_2);
  /* Default value for end is the length of the sequence: */
  end_default_len(STACK_1,STACK_4,STACK_0);
  /* check start- and end arguments: */
  test_start_end(&O(kwpair_start),&STACK_1);
  /* subtract start- and end-arguments: */
  STACK_1 = I_I_minus_I(STACK_1,STACK_2); /* (- end start), an integer >=0 */
  /* Stack layout: sequence, item, start, count, typdescr. */
  /* Set running pointer: */
  pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
  funcall(seq_init_start(STACK_(0+2)),2); /* (SEQ-INIT-START sequence start) */
  STACK_2 = value1; /* =: pointer */
  /* Stack layout: sequence, item, pointer, count, typdescr. */
  if (vectorp(STACK_4) && posfixnump(STACK_1)) {
    var uintV count = posfixnum_to_V(STACK_1);
    if (count > 0) {
      var uintV indexv = posfixnum_to_V(STACK_2);
      if (indexv+count > vector_length(STACK_4))
        with_saved_back_trace_subr(L(store),STACK STACKop -3,-1,
          error_vector_index_range(STACK_4); );
      var uintL index = indexv;
      var object dv = array_displace_check(STACK_4,count,&index);
      if (elt_fill(dv,index,count,STACK_3))
        error_store(STACK_4,STACK_3);
    }
  } else {
    while (!eq(STACK_1,Fixnum_0)) { /* count (an integer) = 0 -> finished */
      pushSTACK(STACK_4); pushSTACK(STACK_(2+1)); pushSTACK(STACK_(3+2));
      funcall(seq_access_set(STACK_(0+3)),3); /* (SEQ-ACCESS-SET sequence pointer item) */
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_2,STACK_4,STACK_0);
      /* count := (1- count) : */
      decrement(STACK_1);
    }
  }
  skipSTACK(4);
  VALUES1(popSTACK()); /* return sequence */
}

LISPFUN(replace,seclass_default,2,0,norest,key,4,
        (kw(start1),kw(end1),kw(start2),kw(end2)) )
/* (REPLACE sequence1 sequence2 [:start1] [:end1] [:start2] [:end2]),
 CLTL p. 252 */
{ /* Method (schematics):
     Argument check.
     Calc. number of to be copied elements:
       count1 := (- end1 start1), count2 := (- end2 start2).
       count1 < count2  ->  count := count1, end2 := (+ start2 count).
       count1 > count2  ->  count := count2, #| end1 := (+ start1 count) |# .
     Now there is (= count #|(- end1 start1)|# (- end2 start2)).
     If sequence1 and sequence2 are EQ, the index ranges do overlap,
     - so this is false (or (>= start2 end1) (>= start1 end2)) -
     and one can copy upwards (< start2 start1):
       Copy the source part from sequence2:
       (unless (or #|(>= start2 end1)|# (>= start1 end2) (>= start2 start1))
         (psetq sequence2 (subseq sequence2 start2 end2)
                start2    0
             #| end2      count |#
       ) )
     Then copy element-wise: for i=0,1,...
       (setf (elt sequence1 (+ start1 i)) (elt sequence2 (+ start2 i))). */
  /* Stack layout: sequence1, sequence2, start1, end1, start2, end2. */
  pushSTACK(get_valid_seq_type(STACK_5)); /* Check sequence1 */
  pushSTACK(get_valid_seq_type(STACK_(4+1))); /* Check sequence2 */
  /* Stack layout: sequence1, sequence2, start1, end1, start2, end2,
                   typdescr1, typdescr2. */
  start_default_0(STACK_(3+2)); /* Default value for start1 is 0 */
  /* Default value for end1 is the length of sequence1: */
  end_default_len(STACK_(2+2),STACK_(5+2),STACK_1);
  start_default_0(STACK_(1+2)); /* Default value for start2 is 0 */
  /* Default value for end2 is the length of sequence2: */
  end_default_len(STACK_(0+2),STACK_(4+2),STACK_0);
  /* Check start- and end arguments: */
  test_start_end(&O(kwpair_start1),&STACK_(2+2));
  test_start_end(&O(kwpair_start2),&STACK_(0+2));
  /* Calc count1: */
  STACK_(2+2) = I_I_minus_I(STACK_(2+2),STACK_(3+2)); /* (- end1 start1) = count1 */
  /* Stack layout: sequence1, sequence2, start1, count1, start2, end2,
                   typdescr1, typdescr2. */
  { /* Calc count2: */
    var object count2 = I_I_minus_I(STACK_(0+2),STACK_(1+2)); /* (- end2 start2) */
    /* Calc count and evtl. decrement end2: */
    if (I_I_comp(STACK_(2+2),count2)<0) { /* count1 < count2 ? */
      /* yes -> count1 is the minimum */
      STACK_(0+2) = I_I_plus_I(STACK_(1+2),STACK_(2+2)); /* end2 := (+ start2 count1) */
    } else { /* no -> count2 is the minimum */
      STACK_(2+2) = count2; /* count := count2 */
    }
  }
  /* Stack layout: sequence1, sequence2, start1, count, start2, end2,
                   typdescr1, typdescr2. */
  /* If both sequences are the same (EQ) and parts (the index ranges) do overlap,
     the source part must be copied: */
  if (eq(STACK_(5+2),STACK_(4+2)) /* (eq sequence1 sequence2) */
      && (I_I_comp(STACK_(1+2),STACK_(3+2))<0)    /* (< start2 start1) */
      && (I_I_comp(STACK_(3+2),STACK_(0+2))<0)) { /* (< start1 end2) */
    /* Copy part from sequence2: */
    pushSTACK(STACK_(4+2)); pushSTACK(STACK_(1+2+1)); pushSTACK(STACK_(0+2+2));
    pushSTACK(STACK_(0+3)); subseq(); /* (SUBSEQ sequence2 start2 end2) */
    STACK_(4+2) = value1; /* =: sequence2 */
    /* Adjust indices: */
    STACK_(1+2) = Fixnum_0; /* start2 := 0 */
  }
  /* Stack layout: sequence1, sequence2, start1, count, start2, dummy,
                   typdescr1, typdescr2. */
  /* Push arguments for copy_seqpart_into to the stack: */
  pushSTACK(STACK_(4+2+0)); pushSTACK(STACK_(0+1));
  pushSTACK(STACK_(5+2+2)); pushSTACK(STACK_(1+3));
  pushSTACK(STACK_(2+2+4));
  /* Stack layout: sequence1, sequence2, start1, count, start2, dummy,
                   typdescr1, typdescr2,
                   sequence2, typdescr2, sequence1, typdescr1, count. */
  pushSTACK(STACK_4); pushSTACK(STACK_(1+2+5+1));
  funcall(seq_init_start(STACK_(3+2)),2); /* (SEQ-INIT-START sequence2 start2) */
  pushSTACK(value1); /* =: pointer2 */
  pushSTACK(STACK_(2+1)); pushSTACK(STACK_(3+2+5+1+1));
  funcall(seq_init_start(STACK_(1+1+2)),2); /* (SEQ-INIT-START sequence1 start1) */
  pushSTACK(value1); /* =: pointer1 */
  /* Stack layout: sequence1, sequence2, start1, count, start2, dummy,
                   typdescr1, typdescr2,
                   sequence2, typdescr2, sequence1, typdescr1, count,
                   pointer2, pointer1. */
  copy_seqpart_into(); /* copy from sequence2 to sequence1 */
  skipSTACK(5+2+5+2);
  VALUES1(popSTACK()); /* return sequence1 */
}

/* local version of call_if & call_if_not for an idiosyncratic Stack layout */
#define MY_CALL(f)                                              \
  local maygc bool seq_##f (const gcv_object_t* stackptr,       \
                            object arg1, object arg2)           \
  { return f(stackptr STACKop 6,arg1,arg2); }
MY_CALL(call_if)
MY_CALL(call_if_not)

/* UP: Checks the :COUNT argument
 > STACK_1: optional argument
 < STACK_1: correct COUNT value: NIL or an integer >=0 */
local void test_count_arg (void) {
  var object count = STACK_1;
  if (!boundp(count)) {
    STACK_1 = NIL; return; /* Default value NIL */
  }
  /* COUNT argument must be NIL or an integer >= 0: */
  if (nullp(count)) /* NIL is OK */
    return;
  if (integerp(count)) {
    if (positivep(count))
      return;
    if (!nullpSv(sequence_count_ansi)) { /* if *SEQUENCE-COUNT-ANSI* */
      STACK_1 = Fixnum_0; return; /* treat negative integers as 0 */
    }
  }
  error_posint(S(Kcount),count);
}

/* UP: Prepares a sequence operation with test.
 > Stack layout:
    ... sequence [stackptr] from-end start end key ... [STACK]
  more exactly:
    ... item sequence [stackptr] from-end start end key test test-not ... [STACK]
    or
    ... test sequence [stackptr] from-end start end key ... [STACK]
    or
    ... test-not sequence [stackptr] from-end start end key ... [STACK]
 > stackptr: Pointer to the stack
 < STACK: will be decremented by 1
 < STACK_0: typedescr for sequence */
local void seq_prepare_testop (gcv_object_t* stackptr) {
  /* sequence check, typedescr to the stack: */
  pushSTACK(get_valid_seq_type(*(stackptr STACKop 0)));
  /* key check: */
  check_key_arg(stackptr STACKop -4);
  /* Default value for from-end is NIL: */
  default_NIL(*(stackptr STACKop -1));
  /* Default value for start is 0: */
  start_default_0(*(stackptr STACKop -2));
  /* Default value for end is NIL: */
  default_NIL(*(stackptr STACKop -3));
  /* Check start and end: */
  test_start_end_1(&O(kwpair_start),&*(stackptr STACKop -3));
}

/* UP: Prepares a sequence filtering operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer into the stack
 < Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr,
      l [STACK].
 can trigger GC */
local maygc void seq_prepare_filterop (gcv_object_t* stackptr) {
  /* COUNT argument must be NIL or an integer >= 0: */
  test_count_arg();
  /* Determine l = (SEQ-LENGTH sequence): */
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  funcall(seq_length(STACK_(0+1)),1); /* (SEQ-LENGTH sequence) */
  pushSTACK(value1); /* put l into the stack */
  /* Default value for END is l: */
  if (nullp(*(stackptr STACKop -3))) { /* end=NIL ? */
    *(stackptr STACKop -3) = STACK_0; /* yes -> end:=l */
    /* Then check start and end again: */
    test_start_end(&O(kwpair_start),&*(stackptr STACKop -3));
  }
  /* Now all arguments are checked. */
}

/* UP: Compute the bit vector length as end-start
 > end   : pointer to the end argument
 > start : pointer to the start argument
 > seq   : pointer to the sequence (for error reporting)
 < the length of the bit vector
 can trigger GC */
local maygc uintV end_minus_start (gcv_object_t *end, gcv_object_t *start,
                                 gcv_object_t *seq) {
  var object bvsize = I_I_minus_I(*end,*start);
  /* bvsize = (- end start), Integer >=0 */
  if (posfixnump(bvsize)) return posfixnum_to_V(bvsize);
  pushSTACK(bvsize); pushSTACK(*seq);
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: sequence ~S is too long: ~S is not a FIXNUM"));
}

/* UP: Executes a sequence filtering operation.
 It traverses a sequence and stores in a bit vector which elements satisfy
 the test. Then a routine is called which does the rest.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer into the stack
 > pcall_test: address of test function with the following specification:
            > stackptr: the pointer into the stack
            > x,y: arguments
            < true, if the test is satisfied, false otherwise.
 > help_fun: address of a helper routine which does the rest. Specification:
        > stackptr: pointer into the stack
          *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
        > STACK_2: typdescr,
        > STACK_1: length l of the sequence,
        > STACK_0: bit vector bv,
        > bvl: length of the bit vector (= end - start),
        > dl: number of bits that are set in the bit vector,
         < result: result
 < mv_space/mv_count: values
 can trigger GC
 help_function is defined to be the type of such a helper function: */
typedef maygc object (*help_function) (gcv_object_t* stackptr, uintV bvl,
                                       uintV dl);
local maygc Values seq_filterop (gcv_object_t* stackptr, funarg_t* pcall_test,
                                 help_function help_fun) {
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  pushSTACK(*(stackptr STACKop -4)); /* key */
  /* get (- end start) and allocate new bitvector: */
  var uintV bvl = end_minus_start(stackptr STACKop -3,stackptr STACKop -2,
                                  stackptr STACKop 0); /* bitvector length */
  var uintV dl = 0; /* Number of bits set in bitvector */
  pushSTACK(allocate_bit_vector_0(bvl)); /* new bitvector bv */
  /* Stack layout: ... count, typdescr,
                   l, sequence, key, bv [STACK]. */
  if (!(nullp(*(stackptr STACKop -1)))) { /* check from-end */
    /* from-end is given */
    pushSTACK(STACK_2); /* sequence */
    pushSTACK(*(stackptr STACKop -3)); /* end */
    funcall(seq_fe_init_end(STACK_(0+4+2)),2); /* (SEQ-FE-INIT-END sequence end) */
    pushSTACK(value1); /* =: pointer */
    pushSTACK(STACK_(1+4+1)); /* countdown := count */
    /* Stack layout: ... count, typdescr,
                     l, sequence, key, bv,
                     pointer, countdown [STACK]. */
    var uintV bvi = bvl; /* run loop bvl times */
    while (bvi != 0) {
      bvi--;
      if (!(nullp(STACK_(1+4+2))) && eq(STACK_0,Fixnum_0))
        /* count/=NIL and countdown=0 -> break loop */
        break;
      /* check next element: */
      pushSTACK(STACK_(2+2)); /* sequence */
      pushSTACK(STACK_(1+1)); /* pointer */
      funcall(seq_access(STACK_(0+4+2+2)),2); /* (SEQ-ACCESS sequence pointer) */
      funcall_key(STACK_(1+2),value1);        /* (FUNCALL key ...) */
      if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
        /* Test ok */
        sbvector_bset(STACK_(0+2),bvi); /* (setf (sbit bv bvi) 1) */
        dl++; /* dl := dl+1, one more set bit */
        if (!(nullp(STACK_(1+4+2)))) { /* if count/=NIL: */
          decrement(STACK_0); /* (decf countdown) */
        }
      }
      /* Advance pointer: */
      pointer_fe_update(STACK_1,STACK_(2+2),STACK_(0+4+2));
    }
  } else { /* from-end is not given */
    pushSTACK(STACK_2); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    funcall(seq_init_start(STACK_(0+4+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    pushSTACK(STACK_(1+4+1)); /* countdown := count */
    /* Stack layout: ... count, typdescr,
                    l, sequence, key, bv,
                    pointer, countdown [STACK]. */
    var uintV bvi = 0; /* run loop bvl times */
    while (bvi != bvl) {
      if (!(nullp(STACK_(1+4+2))) && eq(STACK_0,Fixnum_0))
        /* count/=NIL and countdown=0 -> break loop */
        break;
      /* check next element: */
      pushSTACK(STACK_(2+2)); /* sequence */
      pushSTACK(STACK_(1+1)); /* pointer */
      funcall(seq_access(STACK_(0+4+2+2)),2); /* (SEQ-ACCESS sequence pointer) */
      funcall_key(STACK_(1+2),value1);        /* (FUNCALL key ...) */
      if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
        /* Test ok */
        sbvector_bset(STACK_(0+2),bvi); /* (setf (sbit bv bvi) 1) */
        dl++; /* dl := dl+1, one more set bit */
        if (!(nullp(STACK_(1+4+2)))) { /* if count/=NIL: */
          decrement(STACK_0); /* (decf countdown) */
        }
      }
      /* Advance pointer: */
      pointer_update(STACK_1,STACK_(2+2),STACK_(0+4+2));
      bvi++;
    }
  }
  skipSTACK(2); /* Forget pointer and countdown */
  /* Stack layout: ... count, typdescr,
                  l, sequence, key, bv [STACK]. */
  STACK_2 = STACK_0; skipSTACK(2); /* bv hochschieben */
  /* Stack layout: ... count, typdescr, l, bv [STACK]. */
  VALUES1((*help_fun)(stackptr,bvl,dl));
  skipSTACK(2); /* forget l and bv */
}

/* UP: Helper function for the REMOVE functions
 Constructs a new sequence from a sequence, in which exactly those elements
 are missing, which are marked in a bitvector.
 > stackptr: Pointer to the stack,
    *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
 > STACK_2: Type descriptor,
 > STACK_1: Length l of the sequence,
 > STACK_0: Bitvector bv,
 > bvl: Length of the Bitvectors (= end - start),
 > dl: Number of set bits in the bitvector,
 < result: New sequence
 can trigger GC */
local maygc object remove_help (gcv_object_t* stackptr, uintV bvl, uintV dl) {
  /* dl=0 -> return unchanged sequence: */
  if (dl==0)
    return *(stackptr STACKop 0);
  if (eq(seq_type(STACK_2),S(list))) { /* type LIST ? */
    var uintV start = posfixnum_to_V(*(stackptr STACKop -2));
    var uintV nl;
    {
      /* Find the highest bit set in the bit vector: */
      var uintV bvi = bvl;
      for (;;) {
        bvi--;
        if (sbvector_btst(STACK_0,bvi))
          break;
      }
      nl = bvi+1;
    }
    var object result = make_list(start+nl-dl);
    var object pointer1 = *(stackptr STACKop 0); /* sequence */
    var object pointer2 = result;
    var object lastpointer2 = NIL;
    /* Copy the head part: */
    for (; start > 0; start--) {
      Car(pointer2) = Car(pointer1);
      pointer1 = Cdr(pointer1);
      lastpointer2 = pointer2;
      pointer2 = Cdr(pointer2);
    }
    { /* Copy the middle part, stopping at index nl: */
      var uintV bvi;
      for (bvi = 0; bvi < nl; bvi++) {
        if (!sbvector_btst(STACK_0,bvi)) {
          /* Bit is zero, keep element. */
          Car(pointer2) = Car(pointer1);
          lastpointer2 = pointer2;
          pointer2 = Cdr(pointer2);
        }
        pointer1 = Cdr(pointer1);
      }
    }
    /* Share the tail parts of the lists: */
    if (!nullp(lastpointer2))
      Cdr(lastpointer2) = pointer1;
    else
      result = pointer1;
    return result;
  } else {
    /* Allocate new sequence: */
    pushSTACK(I_I_minus_I(STACK_1,fixnum(dl))); /* (- l dl) */
    funcall(seq_make(STACK_(2+1)),1); /* (SEQ-MAKE (- l dl)) */
    pushSTACK(value1);
    /* Stack layout: typdescr, l, bv, sequence2. */
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(STACK_(3+1)); /* typdescr */
    pushSTACK(STACK_(0+2)); /* sequence2 */
    pushSTACK(STACK_(3+3)); /* typdescr */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    /* Stack layout: typdescr, l, bv, sequence2,
                     seq1, typdescr1, seq2, typdescr2, start. */
    pushSTACK(STACK_4); funcall(seq_init(STACK_(3+1)),1); /* (SEQ-INIT sequence) */
    pushSTACK(value1); /* =: pointer1 */
    pushSTACK(STACK_(2+1)); funcall(seq_init(STACK_(1+1+1)),1); /* (SEQ-INIT sequence2) */
    pushSTACK(value1); /* =: pointer2 */
    /* Stack layout: typdescr, l, bv, sequence2,
                     seq1, typdescr1, seq2, typdescr2, start,
                     pointer1, pointer2. */
    { /* Head part:
         Copy elements for index <start from sequence1 to sequence2 unchanged: */
      copy_seqpart_into();
    }
    { /* Middle part: seeve. */
      var uintV bvi = 0;
      while (bvi != bvl) {
        if (!(sbvector_btst(STACK_(1+5+2),bvi))) { /* Check (sbit bv bvi) */
          /* Bit not set, so take element */
          pushSTACK(STACK_(4+2)); pushSTACK(STACK_(1+1));
          funcall(seq_access(STACK_(3+2+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
          pushSTACK(STACK_(2+2)); pushSTACK(STACK_(0+1)); pushSTACK(value1);
          funcall(seq_access_set(STACK_(1+2+3)),3); /* (SEQ-ACCESS-SET seq2 pointer2 ...) */
          /* pointer2 := (SEQ-UPD seq2 pointer2) : */
          pointer_update(STACK_0,STACK_(2+2),STACK_(1+2));
        }
        /* pointer1 := (SEQ-UPD seq1 pointer1) : */
        pointer_update(STACK_1,STACK_(4+2),STACK_(3+2));
        bvi++;
      }
    }
    { /* Tail part:
         Copy elements for index >=end from sequence1 to sequence2 unchanged: */
      STACK_(0+2) = I_I_minus_I(STACK_(2+5+2),*(stackptr STACKop -3)); /* (- l end) */
      copy_seqpart_into();
    }
    skipSTACK(5+2);
    return popSTACK(); /* sequence2 as return value */
  }
}

/* UP: Helper function for the DELETE functions.
 Removes exactly those elements from the sequence, which are marked in a bitvector.
 > stackptr: Pointer to the stack,
    *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
 > STACK_2: typdescr,
 > STACK_1: Length l of the sequence,
 > STACK_0: Bitvector bv,
 > bvl: Length of the Bitvectors (= end - start),
 > dl: Number of set bits in the bitvector,
 < result: Same sequence
 can trigger GC */
local maygc object delete_help (gcv_object_t* stackptr, uintV bvl, uintV dl) {
  /* dl=0 -> return unchanged sequence: */
  if (dl==0)
    return *(stackptr STACKop 0);
  var object type = seq_type(STACK_2);
  if (eq(type,S(list))) { /* Typ LIST ? */
    /* Check again if, sequence is really a list. */
    /* Because of l >= dl > 0 we have to test, if sequence is a Cons. */
    if (mconsp(*(stackptr STACKop 0))) {
      /* Handle lists especially: */
      var gcunsafe_object_t whole_list = *(stackptr STACKop 0); /* whole list */
      var gcv_object_t* list_ = &whole_list;
      var object list = *list_;
      /* list = *list_. */
      { /* Head part:
         Advance start times with list:=Cdr(list): */
        var uintV count = posfixnum_to_V(*(stackptr STACKop -2));
        while (count--) {
          list_ = &Cdr(list); list = *list_;
        }
      }
      { /* Middle part (seeve):
         Check bvl times the bit and evtl. remove a Cons: */
        var uintV bvi = 0;
        while (bvi != bvl) {
          if (sbvector_btst(STACK_0,bvi)) { /* Check (sbit bv bvi) */
            /* Bit is =1 -> remove Cons from list: */
            *list_ = list = Cdr(list);
          } else {
            /* Bit is =0 -> advance: */
            list_ = &Cdr(list); list = *list_;
          }
          bvi++;
        }
      }
      return whole_list; /* return modified list */
    } else
      goto other;
  } else if (eq(type,S(vector)) || eq(type,S(string)) || posfixnump(type)) {
    /* Type [GENERAL-]VECTOR, STRING, (UNSIGNED-BYTE n)-VECTOR */
    /* Check again, if sequence is really a vector. */
    var object sequence = *(stackptr STACKop 0);
    if (!(vectorp(sequence)))
      goto other;
    /* On arrays without fill-pointer you cannot do anything special: */
    if (!(array_has_fill_pointer_p(sequence)))
      goto other;
    /* Sequence is a vector with fill-pointer. */
    /* Push elements together and decrement fill-pointer: */
    pushSTACK(sequence); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* i := start */
    pushSTACK(STACK_0); /* j := i */
    /* Stack layout: typdescr, l, bv, sequence, i, j. */
    /* j = Source-Index, i = Destination-Index, start <= i <= j . */
    { /* Middle part (seeve): */
      var uintV bvi = 0;
      while (bvi != bvl) {
        if (!(sbvector_btst(STACK_3,bvi))) { /* Check (sbit bv bvi) */
          /* Bit deleted -> element moved: */
          /* (setf (aref sequence i) (aref sequence j)) : */
          pushSTACK(STACK_2); pushSTACK(STACK_(0+1));
          funcall(L(aref),2); /* (AREF sequence j) */
          pushSTACK(STACK_2); pushSTACK(STACK_(1+1)); pushSTACK(value1);
          funcall(L(store),3); /* (SYS::STORE sequence i ...) */
          /* i:=i+1 : */
          STACK_1 = fixnum_inc(STACK_1,1);
        }
        /* j:=j+1 : */
        STACK_0 = fixnum_inc(STACK_0,1);
        bvi++;
      }
    }
    { /* Tail part: */
      while (!eq(STACK_0,STACK_4)) { /* until j = l (both fixnums) */
        /* Move element: */
        /* (setf (aref sequence i) (aref sequence j)) : */
        pushSTACK(STACK_2); pushSTACK(STACK_(0+1));
        funcall(L(aref),2); /* (AREF sequence j) */
        pushSTACK(STACK_2); pushSTACK(STACK_(1+1)); pushSTACK(value1);
        funcall(L(store),3); /* (SYS::STORE sequence i ...) */
        /* i:=i+1 : */
        STACK_1 = fixnum_inc(STACK_1,1);
        /* j:=j+1 : */
        STACK_0 = fixnum_inc(STACK_0,1);
      }
    }
    skipSTACK(1);
    /* Stack layout: typdescr, l, bv, sequence, i. */
    /* (setf (fill-pointer sequence) i) : */
    funcall(L(set_fill_pointer),2); /* (SYS::SET-FILL-POINTER sequence i) */
    /* Stack layout: typdescr, l, bv. */
    return *(stackptr STACKop 0); /* sequence with modified fill-pointer */
  }
 other: /* other sequences */
  return remove_help(stackptr,bvl,dl); /* else handle DELETE as REMOVE */
}

/* UP: Executes a REMOVE operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer into the stack
 > pcall_test: address of test function with the following specification:
           > stackptr: the pointer into the stack
           > x,y: arguments
           < true, if the test is satisfied, false otherwise. */
local Values remove_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  seq_prepare_filterop(stackptr);
  /* Stack layout:
       ... sequence [stackptr] from-end start end key ... count typdescr,
       l [STACK]. */
  if (nullp(*(stackptr STACKop -1)) && eq(seq_type(STACK_(0+1)),S(list))) {
    /* from-end is not specified, and the sequence type is LIST. */
    /* In this case we don't need to allocate a bit vector. */
    pushSTACK(NIL); /* result1 := NIL */
    pushSTACK(*(stackptr STACKop 0)); /* result2 := sequence */
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    funcall(seq_init_start(STACK_(0+3+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    pushSTACK(STACK_(1+4)); /* countdown := count */
    /* Stack layout: ..., count, typdescr,
                     l, result1, result2, pointer, countdown [STACK]. */
    /* length of the relevant portion */
    var uintV bvl = end_minus_start(stackptr STACKop -3,stackptr STACKop -2,
                                    stackptr STACKop 0);
    for (; bvl > 0; bvl--) {
      if (!nullp(STACK_(1+5)) && eq(STACK_0,Fixnum_0))
        /* count/=NIL and countdown=0 -> can terminate loop */
        break;
      /* Test next element: */
      pushSTACK(*(stackptr STACKop 0)); /* sequence */
      pushSTACK(STACK_(1+1)); /* pointer */
      funcall(seq_access(STACK_(0+5+2)),2); /* (SEQ-ACCESS sequence pointer) */
      funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key ...) */
      if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
        /* Test fulfilled. */
        /* result1 := (nreconc (ldiff result2 pointer) result1) */
        pushSTACK(STACK_2); pushSTACK(STACK_(1+1)); funcall(L(ldiff),2);
        STACK_3 = nreconc(value1,STACK_3);
        /* result2 := (setq pointer (cdr pointer)) */
        pointer_update(STACK_1,*(stackptr STACKop 0),STACK_(0+5));
        STACK_2 = STACK_1;
        if (!nullp(STACK_(1+5))) { /* if count/=NIL: */
          decrement(STACK_0); /* (decf countdown) */
        }
      } else { /* Test failed. */
        /* (setq pointer (cdr pointer)) */
        pointer_update(STACK_1,*(stackptr STACKop 0),STACK_(0+5));
      }
    }
    /* Return (nreconc result1 result2): */
    VALUES1(nreconc(STACK_3,STACK_2));
    skipSTACK(5);
  } else {
    /* Use a bit vector for doing the filtering. */
    return_Values seq_filterop(stackptr,pcall_test,&remove_help);
  }
}

/* UP: Executes a DELETE operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer into the stack
 > pcall_test: address of test function with the following specification:
           > stackptr: the pointer into the stack
           > x,y: arguments
           < true, if the test is satisfied, false otherwise. */
local Values delete_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  seq_prepare_filterop(stackptr);
  /* Stack layout:
       ... sequence [stackptr] from-end start end key ... count typdescr,
       l [STACK]. */
  if (nullp(*(stackptr STACKop -1)) && eq(seq_type(STACK_(0+1)),S(list))) {
    /* from-end is not specified, and the sequence type is LIST. */
    /* In this case we don't need to allocate a bit vector. */
    pushSTACK(*(stackptr STACKop 0)); /* result := sequence */
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    funcall(seq_init_start(STACK_(0+2+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    if (eq(*(stackptr STACKop -2),Fixnum_0)) /* start=0 ? */
      pushSTACK(NIL); /* last := NIL */
    else {
      pushSTACK(*(stackptr STACKop 0)); /* sequence */
      pushSTACK(fixnum_inc(*(stackptr STACKop -2),-1)); /* start-1 */
      funcall(seq_init_start(STACK_(0+3+2)),2); /* (SEQ-INIT-START sequence start-1) */
      pushSTACK(value1); /* =: last */
    }
    pushSTACK(STACK_(1+4)); /* countdown := count */
    /* Stack layout: ..., count, typdescr,
                     l, result, pointer, last, countdown [STACK]. */
    /* length of the relevant portion */
    var uintV bvl = end_minus_start(stackptr STACKop -3,stackptr STACKop -2,
                                    stackptr STACKop 0);
    for (; bvl > 0; bvl--) {
      if (!nullp(STACK_(1+5)) && eq(STACK_0,Fixnum_0))
        /* count/=NIL and countdown=0 -> can terminate loop */
        break;
      /* Test next element: */
      pushSTACK(*(stackptr STACKop 0)); /* sequence */
      pushSTACK(STACK_(2+1)); /* pointer */
      funcall(seq_access(STACK_(0+5+2)),2); /* (SEQ-ACCESS sequence pointer) */
      funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key ...) */
      if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
        /* Test fulfilled. */
        if (!nullp(STACK_1)) { /* last/=NIL? */
          /* (cdr last) := (setq pointer (cdr pointer)) */
          pointer_update(STACK_2,*(stackptr STACKop 0),STACK_(0+5));
          Cdr(STACK_1) = STACK_2;
        } else {
          /* result := (setq pointer (cdr pointer)) */
          pointer_update(STACK_2,*(stackptr STACKop 0),STACK_(0+5));
          STACK_3 = STACK_2;
        }
        if (!nullp(STACK_(1+5))) { /* if count/=NIL: */
          decrement(STACK_0); /* (decf countdown) */
        }
      } else {
        /* Test failed. */
        /* last := pointer, (setq pointer (cdr pointer)) */
        STACK_1 = STACK_2;
        pointer_update(STACK_2,*(stackptr STACKop 0),STACK_(0+5));
      }
    }
    /* Return result: */
    VALUES1(STACK_3);
    skipSTACK(5);
  } else {
    /* Use a bit vector for doing the filtering. */
    return_Values seq_filterop(stackptr,pcall_test,&delete_help);
  }
}

LISPFUN(remove,seclass_default,2,0,norest,key,7,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not),kw(count)) )
{ /* (REMOVE item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not] [:count]),
 CLTL p. 253 */
  var gcv_object_t* stackptr = &STACK_7;
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* test function */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  remove_op(stackptr,pcall_test);
  skipSTACK(2+7+1);
}

LISPFUN(remove_if,seclass_default,2,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (REMOVE-IF test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 253 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  remove_op(stackptr,&seq_call_if);
  skipSTACK(2+5+1);
}

LISPFUN(remove_if_not,seclass_default,2,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (REMOVE-IF-NOT test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 253 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  remove_op(stackptr,&seq_call_if_not);
  skipSTACK(2+5+1);
}

LISPFUN(delete,seclass_default,2,0,norest,key,7,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not),kw(count)) )
{ /* (DELETE item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not] [:count]),
 CLTL p. 254 */
  var gcv_object_t* stackptr = &STACK_7;
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* test function */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  delete_op(stackptr,pcall_test);
  skipSTACK(2+7+1);
}

LISPFUN(delete_if,seclass_default,2,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (DELETE-IF test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 254 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  delete_op(stackptr,&seq_call_if);
  skipSTACK(2+5+1);
}

LISPFUN(delete_if_not,seclass_default,2,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (DELETE-IF-NOT test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 254 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  delete_op(stackptr,&seq_call_if_not);
  skipSTACK(2+5+1);
}

/* UP: Executes a REMOVE-DUPLICATES operation on a list.
 > Stack layout: sequence from-end start end key test test-not typdescr l.
 > pcall_test: address of a test function, with specification:
        > stackptr: the pointer into the stack,
          *(stackptr-0) = :test argument, *(stackptr-1) = :test-not argument,
        > x,y: arguments
        < true, if the test is satisfied, false otherwise.
 > bvl: = end - start
 < mv_space/mv_count: values
 can trigger GC */
local maygc Values remove_duplicates_list_from_start (funarg_t* pcall_test,
                                                      uintV bvl) {
  var gcv_object_t* stackptr = &STACK_(6+2);
  pushSTACK(NIL); /* result1 := NIL */
  pushSTACK(STACK_(6+3)); /* result2 := sequence */
  pushSTACK(STACK_(6+4)); /* sequence */
  pushSTACK(STACK_(4+4+1)); /* start */
  funcall(seq_init_start(STACK_(3+2)),2); /* (SEQ-INIT-START sequence start) */
  pushSTACK(value1); /* =: pointer1 */
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr, l, result1, result2, pointer1. */
  /* pointer1 goes from left to right (from start to end). */
  var uintV l1 = bvl;
  for (; l1 > 1; l1--) {
    /* Fetch next element: */
    pushSTACK(STACK_(6+5)); /* sequence */
    pushSTACK(STACK_(0+1)); /* pointer1 */
    funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer1) */
    funcall_key(STACK_(2+5),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
    pushSTACK(value1); /* =: item1 */
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result1, result2, pointer1,
         item1. */
    /* Loop over the remaining elements: */
    /* pointer2 := (SEQ-COPY pointer1): */
    pushSTACK(STACK_(0+1));
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result1, result2, pointer1,
         item1, pointer2. */
    var uintV l2 = l1-1;
    do {
      /* pointer2 := (SEQ-UPD sequence pointer2) : */
      STACK_0 = Cdr(STACK_0);
      pushSTACK(STACK_(6+5+2)); /* sequence */
      pushSTACK(STACK_(0+1)); /* pointer2 */
      funcall(seq_access(STACK_(4+2+2)),2); /* (SEQ-ACCESS sequence pointer2) */
      funcall_key(STACK_(2+5+2),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer2)) */
      /* value1 =: item2 */
      /* Compare item1 and item2: */
      if ((*pcall_test)(stackptr STACKop -6,STACK_1,value1))
        /* Test satisfied -> terminate the inner loop and remove item1: */
        break;
    } while (--l2 > 0);
    skipSTACK(2);
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result1, result2, pointer1. */
    if (l2 > 0) {
      /* Remove item1: */
      /* result1 := (nreconc (ldiff result2 pointer1) result1) */
      pushSTACK(STACK_1); pushSTACK(STACK_(0+1)); funcall(L(ldiff),2);
      STACK_2 = nreconc(value1,STACK_2);
      /* result2 := (setq pointer1 (cdr pointer1)) */
      STACK_1 = STACK_0 = Cdr(STACK_0);
    } else {
      /* (setq pointer1 (cdr pointer1)) */
      STACK_0 = Cdr(STACK_0);
    }
  }
  /* Return (nreconc result1 result2): */
  VALUES1(nreconc(STACK_2,STACK_1));
  skipSTACK(7+5);
}

/* UP: Executes a DELETE-DUPLICATES operation on a list.
 > Stack layout: sequence from-end start end key test test-not typdescr l.
 > pcall_test: address of a test function, with specification:
        > stackptr: the pointer into the stack,
          *(stackptr-0) = :test argument, *(stackptr-1) = :test-not argument,
        > x,y: arguments
        < true, if the test is satisfied, false otherwise.
 > bvl: = end - start
 < mv_space/mv_count: values
 can trigger GC */
local maygc Values delete_duplicates_list_from_start (funarg_t* pcall_test,
                                                      uintV bvl) {
  var gcv_object_t* stackptr = &STACK_(6+2);
  pushSTACK(STACK_(6+2)); /* result := sequence */
  pushSTACK(STACK_(6+3)); /* sequence */
  pushSTACK(STACK_(4+3+1)); /* start */
  funcall(seq_init_start(STACK_(2+2)),2); /* (SEQ-INIT-START sequence start) */
  pushSTACK(value1); /* =: pointer1 */
  if (eq(STACK_(4+4),Fixnum_0)) /* start=0 ? */
    pushSTACK(NIL); /* lastpointer1 := NIL */
  else {
    pushSTACK(STACK_(6+4)); /* sequence */
    pushSTACK(fixnum_inc(STACK_(4+4+1),-1)); /* start-1 */
    funcall(seq_init_start(STACK_(3+2)),2); /* (SEQ-INIT-START sequence start-1) */
    pushSTACK(value1); /* =: lastpointer1 */
  }
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr, l, result, pointer1, lastpointer1. */
  /* pointer1 goes from left to right (from start to end). */
  var uintV l1 = bvl;
  for (; l1 > 1; l1--) {
    /* Fetch next element: */
    pushSTACK(STACK_(6+5)); /* sequence */
    pushSTACK(STACK_(1+1)); /* pointer1 */
    funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer1) */
    funcall_key(STACK_(2+5),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
    pushSTACK(value1); /* =: item1 */
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result, pointer1, lastpointer1,
         item1. */
    /* Loop over the remaining elements: */
    /* pointer2 := (SEQ-COPY pointer1): */
    pushSTACK(STACK_(1+1));
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result, pointer1, lastpointer1,
         item1, pointer2. */
    var uintV l2 = l1-1;
    do {
      /* pointer2 := (SEQ-UPD sequence pointer2) : */
      STACK_0 = Cdr(STACK_0);
      pushSTACK(STACK_(6+5+2)); /* sequence */
      pushSTACK(STACK_(0+1)); /* pointer2 */
      funcall(seq_access(STACK_(4+2+2)),2); /* (SEQ-ACCESS sequence pointer2) */
      funcall_key(STACK_(2+5+2),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer2)) */
      /* value1 =: item2 */
      /* Compare item1 and item2: */
      if ((*pcall_test)(stackptr STACKop -6,STACK_1,value1))
        /* Test satisfied -> terminate the inner loop and remove item1: */
        break;
    } while (--l2 > 0);
    skipSTACK(2);
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, result, pointer1, lastpointer1. */
    if (l2 > 0) {
      /* Remove item1: */
      if (!nullp(STACK_0)) { /* lastpointer1/=NIL? */
        /* (cdr lastpointer1) := (setq pointer1 (cdr pointer1)) */
        Cdr(STACK_0) = STACK_1 = Cdr(STACK_1);
      } else {
        /* result := (setq pointer1 (cdr pointer1)) */
        STACK_2 = STACK_1 = Cdr(STACK_1);
      }
    } else {
      /* lastpointer1 := pointer1, (setq pointer1 (cdr pointer1)) */
      STACK_0 = STACK_1;
      STACK_1 = Cdr(STACK_1);
    }
  }
  /* Return result: */
  VALUES1(STACK_2);
  skipSTACK(7+5);
}

/* UP: Executes a DELETE-DUPLICATES operation on a list.
 > Stack layout: sequence from-end start end key test test-not typdescr l.
 > pcall_test: address of a test function, with specification:
        > stackptr: the pointer into the stack,
          *(stackptr-0) = :test argument, *(stackptr-1) = :test-not argument,
        > x,y: arguments
        < true, if the test is satisfied, false otherwise.
 > bvl: = end - start
 < mv_space/mv_count: values
 can trigger GC */
local maygc Values delete_duplicates_list_from_end (funarg_t* pcall_test,
                                                    uintV bvl) {
  var gcv_object_t* stackptr = &STACK_(6+2);
  pushSTACK(STACK_(6+2)); /* sequence */
  pushSTACK(STACK_(4+2+1)); /* start */
  funcall(seq_init_start(STACK_(1+2)),2); /* (SEQ-INIT-START sequence start) */
  pushSTACK(value1); /* =: pointer1 */
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr, l, pointer1. */
  /* pointer1 goes from left to right (from start to end). */
  var uintV l1 = bvl;
  for (; l1 > 1; l1--) {
    /* Fetch next element: */
    pushSTACK(STACK_(6+3)); /* sequence */
    pushSTACK(STACK_(0+1)); /* pointer1 */
    funcall(seq_access(STACK_(2+2)),2); /* (SEQ-ACCESS sequence pointer1) */
    funcall_key(STACK_(2+3),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
    pushSTACK(value1); /* =: item1 */
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, pointer1,
         item1. */
    /* Loop over the remaining elements: */
    /* pointer2 := (SEQ-COPY pointer1): */
    pushSTACK(STACK_(0+1));
    /* lastpointer2 := pointer2 : */
    pushSTACK(STACK_0);
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, pointer1,
         item1, pointer2, lastpointer2. */
    /* pointer2 := (SEQ-UPD sequence pointer2) : */
    STACK_1 = Cdr(STACK_1);
    var uintV l2 = l1-1;
    do {
      pushSTACK(STACK_(6+3+3)); /* sequence */
      pushSTACK(STACK_(1+1)); /* pointer2 */
      funcall(seq_access(STACK_(2+3+2)),2); /* (SEQ-ACCESS sequence pointer2) */
      funcall_key(STACK_(2+3+3),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer2)) */
      /* value1 =: item2 */
      /* Compare item1 and item2: */
      if ((*pcall_test)(stackptr STACKop -6,STACK_2,value1)) {
        /* Test satisfied -> remove item2: */
        /* (cdr lastpointer2) := (setq pointer2 (cdr pointer2)) */
        Cdr(STACK_0) = STACK_1 = Cdr(STACK_1);
        /* And update the outer loop's counter. */
        l1--;
      } else {
        /* lastpointer2 := pointer2, (setq pointer2 (cdr pointer2)) */
        STACK_0 = STACK_1;
        STACK_1 = Cdr(STACK_1);
      }
    } while (--l2 > 0);
    skipSTACK(3);
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, pointer1. */
    /* (setq pointer1 (cdr pointer1)) */
    STACK_0 = Cdr(STACK_0);
  }
  /* Return sequence: */
  VALUES1(STACK_(6+3));
  skipSTACK(7+3);
}

/* UP: Executes a sequence duplicates-removal operation.
 seq_duplicates(help_fun)
 It traverses a sequence and stores in a bit vector which elements occur
 twice. Then a routine is called which does the rest.
 > Stack layout: sequence from-end start end key test test-not [STACK]
 > help_fun: address of a helper routine which does the rest. Specification:
        > stackptr: pointer into the stack,
          *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
        > STACK_2: typdescr,
        > STACK_1: length l of the sequence,
        > STACK_0: bit vector bv,
        > bvl: length of the bit vector (= end - start),
        > dl: number of bits that are set in the bit vector,
        < result: result
        can trigger GC
 < mv_space/mv_count: values
 can trigger GC */
extern funarg_t call_test;
local maygc Values seq_duplicates (help_function help_fun) {
  var gcv_object_t* stackptr = &STACK_6;
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not. */
  { /* Check sequence: */
    var object sequence = *(stackptr STACKop 0);
    pushSTACK(get_valid_seq_type(sequence)); /* typdescr on the stack */
  }
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr. */
  /* Check :test and :test-not: */
  var funarg_t* pcall_test = check_test_args(&STACK_1);
  /* Check key: */
  check_key_arg(&STACK_3);
  /* Default value for from-end is NIL: */
  default_NIL(*(stackptr STACKop -1));
  /* Default value for start is 0: */
  start_default_0(*(stackptr STACKop -2));
  /* Default value for end is NIL: */
  default_NIL(*(stackptr STACKop -3));
  /* Check start and end: */
  test_start_end_1(&O(kwpair_start),&*(stackptr STACKop -3));
  /* Determine the length of the sequence: */
  pushSTACK(STACK_(6+1)); /* sequence */
  funcall(seq_length(STACK_(0+1)),1); /* (SEQ-LENGTH sequence) */
  pushSTACK(value1); /* l */
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr, l. */
  /* Default value for end is l = (length sequence): */
  if (nullp(*(stackptr STACKop -3))) {
    *(stackptr STACKop -3) = STACK_0; /* end := l */
    /* Then check start and end again: */
    test_start_end(&O(kwpair_start),&*(stackptr STACKop -3));
  }
  /* Now all arguments are checked. */
  var uintV bvl = end_minus_start(stackptr STACKop -3,stackptr STACKop -2,
                                  stackptr STACKop 0); /* bitvector length */
  var uintV dl = 0; /* Number of set bits in the bitvector */
  /* With :test #'eq/eql/equal and large length use hash table: */
  if (bvl < 10)
    goto standard;
  if (pcall_test != &call_test)
    goto standard;
  {
    var object test = STACK_(1+2);
    if (!(eq(test,L(eq)) || eq(test,L(eql)) || eq(test,L(equal))
          || eq(test,S(eq)) || eq(test,S(eql)) || eq(test,S(equal))))
      goto standard;
  }
  if (false) {
    standard: /* standard method */
    if (!(nullp(STACK_(5+2)))) { /* check from-end */
      /* from-end is specified. */
      if (eq(seq_type(STACK_1),S(list))) { /* type LIST ? */
        /* In this case we don't need to allocate a bit vector. */
        if (help_fun == &delete_help) {
          /* Delete duplicates from a list. */
          delete_duplicates_list_from_end(pcall_test,bvl);
          return;
        }
      }
      /* Allocate new bitvector: */
      pushSTACK(allocate_bit_vector_0(bvl));
      {
        pushSTACK(STACK_(6+3)); /* sequence */
        pushSTACK(STACK_(4+3+1)); /* start */
        funcall(seq_init_start(STACK_(2+2)),2); /* (SEQ-INIT-START sequence start) */
        pushSTACK(value1); /* =: pointer1 */
      }
      /* Stack layout:
           sequence [stackptr], from-end, start, end, key, test, test-not,
           typdescr, l, bv,
           pointer1. */
      /* pointer1 runs from left to right (from start to end). */
      {
        var uintV bvi1 = 0; /* Run loop bvl times */
        while (bvi1 != bvl) {
          if (!(sbvector_btst(STACK_(0+1),bvi1))) { /* Check (sbit bv bvi1) */
            /* If Bit=0: this element is not yet marked to be removed ->
               test, if its found to the right: */
            {
              pushSTACK(STACK_(6+3+1)); /* sequence */
              pushSTACK(STACK_(0+1)); /* pointer1 */
              funcall(seq_access(STACK_(2+1+2)),2); /* (SEQ-ACCESS sequence pointer1) */
              funcall_key(STACK_(2+3+1),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
              pushSTACK(value1); /* =: item1 */
            }
            /* Stack layout:
                 sequence [stackptr], from-end, start, end, key, test, test-not,
                 typdescr, l, bv,
                 pointer1, item1. */
            /* pointer1 := (SEQ-UPD sequence pointer1) : */
            pointer_update(STACK_1,STACK_(6+3+2),STACK_(2+2));
            /* pointer2 := (SEQ-COPY pointer1) : */
            {
              pushSTACK(STACK_1); funcall(seq_copy(STACK_(2+2+1)),1); /* (SEQ-COPY pointer1) */
              pushSTACK(value1); /* =: pointer2 */
            }
            /* Stack layout:
                 sequence [stackptr], from-end, start, end, key, test, test-not,
                 typdescr, l, bv,
                 pointer1, item1, pointer2. */
            /* pointer2 runs from pointer1 to the right. */
            {
              var uintV bvi2 = bvi1+1; /* bvi2 := bvi1+1 */
              while (bvi2 != bvl) {
                if (!(sbvector_btst(STACK_(0+3),bvi2))) { /* Check (sbit bv bvi2) */
                  /* If Bit=0: this element is also not yet marked to be removed. */
                  /* compare both elements: */
                  pushSTACK(STACK_(6+3+3)); /* sequence */
                  pushSTACK(STACK_(0+1)); /* pointer2 */
                  funcall(seq_access(STACK_(2+3+2)),2); /* (SEQ-ACCESS sequence pointer2) */
                  funcall_key(STACK_(2+3+3),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer2)) */
                  /* value1 =: item2 */
                  /* Compare item1 and item2: */
                  if ((*pcall_test)(stackptr STACKop -6,STACK_1,value1)) {
                    /* Test ok -> mark item2 to be removed: */
                    sbvector_bset(STACK_(0+3),bvi2); /* (setf (sbit bv bvi2) 1) */
                    dl = dl+1; /* dl:=dl+1 */
                  }
                }
                /* pointer2 := (SEQ-UPD sequence pointer2) : */
                pointer_update(STACK_0,STACK_(6+3+3),STACK_(2+3));
                bvi2++; /* bvi2 := bvi2+1 */
              }
            }
            skipSTACK(2); /* Forget item1 and pointer2 */
          } else {
            /* if Bit=1: simply skip this element */
            /* pointer1 := (SEQ-UPD sequence pointer1) : */
            pointer_update(STACK_0,STACK_(6+3+1),STACK_(2+1));
          }
          bvi1++;
        }
      }
      skipSTACK(1); /* Forget pointer1 */
    } else {
      /* from-end is not specified. */
      if (eq(seq_type(STACK_1),S(list))) { /* type LIST ? */
        /* In this case we don't need to allocate a bit vector. */
        if (help_fun == &remove_help) {
          /* Remove duplicates from a list. */
          remove_duplicates_list_from_start(pcall_test,bvl);
          return;
        }
        if (help_fun == &delete_help) {
          /* Delete duplicates from a list. */
          delete_duplicates_list_from_start(pcall_test,bvl);
          return;
        }
      }
      /* Allocate new bitvector: */
      pushSTACK(allocate_bit_vector_0(bvl));
      {
        pushSTACK(STACK_(6+3)); /* sequence */
        pushSTACK(STACK_(4+3+1)); /* start */
        funcall(seq_init_start(STACK_(2+2)),2); /* (SEQ-INIT-START sequence start) */
        pushSTACK(value1); /* =: pointer0 */
      }
      /* Stack layout:
           sequence [stackptr], from-end, start, end, key, test, test-not,
           typdescr, l, bv,
           pointer0. */
      /* pointer0 is left. */
      {
        pushSTACK(STACK_0); funcall(seq_copy(STACK_(2+1+1)),1); /* (SEQ-COPY pointer0) */
        pushSTACK(value1); /* =: pointer2 */
      }
      /* Stack layout:
           sequence [stackptr], from-end, start, end, key, test, test-not,
           typdescr, l, bv,
           pointer0, pointer2. */
      /* pointer2 runs from left to right (from start to end). */
      {
        var uintV bvi2 = 0; /* Run loop bvl times */
        while (bvi2 != bvl) {
          if (!(sbvector_btst(STACK_(0+2),bvi2))) { /* Check (sbit bv bvi2) */
            /* If Bit=0: this element is not yet marked
               -> test, if found to the left: */
            {
              pushSTACK(STACK_(6+3+2)); /* sequence */
              pushSTACK(STACK_(0+1)); /* pointer2 */
              funcall(seq_access(STACK_(2+2+2)),2); /* (SEQ-ACCESS sequence pointer2) */
              funcall_key(STACK_(2+3+2),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
              pushSTACK(value1); /* =: item2 */
            }
            /* Stack layout:
                 sequence [stackptr], from-end, start, end, key, test, test-not,
                 typdescr, l, bv,
                 pointer0, pointer2, item2. */
            /* pointer1 := (SEQ-COPY pointer0) : */
            {
              pushSTACK(STACK_2); funcall(seq_copy(STACK_(2+3+1)),1); /* (SEQ-COPY pointer0) */
              pushSTACK(value1); /* =: pointer1 */
            }
            /* Stack layout:
                 sequence [stackptr], from-end, start, end, key, test, test-not,
                 typdescr, l, bv,
                 pointer0, pointer2, item2, pointer1. */
            /* pointer1 runs from left to pointer2. */
            {
              var uintV bvi1 = 0; /* bvi1 := 0 */
              while (bvi1 != bvi2) {
                if (!(sbvector_btst(STACK_(0+4),bvi1))) { /* (sbit bv bvi1) abfragen */
                  /* if Bit=0: this elements is also not yet marked. */
                  /* compare both elements: */
                  pushSTACK(STACK_(6+3+4)); /* sequence */
                  pushSTACK(STACK_(0+1)); /* pointer1 */
                  funcall(seq_access(STACK_(2+4+2)),2); /* (SEQ-ACCESS sequence pointer1) */
                  funcall_key(STACK_(2+3+4),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer1)) */
                  /* value1 =: item1 */
                  /* compare item1 and item2: */
                  if ((*pcall_test)(stackptr STACKop -6,value1,STACK_1)) {
                    /* Test ok -> mark item1 to be removed: */
                    sbvector_bset(STACK_(0+4),bvi1); /* (setf (sbit bv bvi1) 1) */
                    dl = dl+1; /* dl:=dl+1 */
                  }
                }
                /* pointer1 := (SEQ-UPD sequence pointer1) : */
                pointer_update(STACK_0,STACK_(6+3+4),STACK_(2+4));
                bvi1++; /* bvi1 := bvi1+1 */
              }
            }
            skipSTACK(2); /* forget item2 and pointer1 */
          }
          /* if Bit=1: simply skip this element */
          /* pointer2 := (SEQ-UPD sequence pointer2) : */
          pointer_update(STACK_0,STACK_(6+3+2),STACK_(2+2));
          bvi2++; /* bvi2 := bvi2+1 */
        }
      }
      skipSTACK(2); /* forget pointer0 and pointer2 */
    }
  } else {
    /* method with hash table */
    /* Allocate new bitvector: */
    pushSTACK(allocate_bit_vector_0(bvl));
    /* Create with (MAKE-HASH-TABLE :test test) an empty hash table: */
    {
      var object test = STACK_(1+3);
      if (eq(test,S(eq)) || eq(test,L(eq)))
        test = S(fasthash_eq);
      else if (eq(test,S(eql)) || eq(test,L(eql)))
        test = S(fasthash_eql);
      else if (eq(test,S(equal)) || eq(test,L(equal)))
        test = S(fasthash_equal);
      pushSTACK(S(Ktest)); pushSTACK(test);
    }
    funcall(L(make_hash_table),2);
    pushSTACK(value1); /* save ht */
    {
      pushSTACK(STACK_(6+3+1)); /* sequence */
      pushSTACK(STACK_(4+3+2)); /* start */
      funcall(seq_init_start(STACK_(2+3)),2); /* (SEQ-INIT-START sequence start) */
      pushSTACK(value1); /* =: pointer */
    }
    /* Stack layout:
         sequence [stackptr], from-end, start, end, key, test, test-not,
         typdescr, l, bv,
         ht, pointer. */
    if (!(nullp(STACK_(5+3+2)))) { /* check from-end */
      /* from-end is given */
      /* pointer runs from left to right (from start to end). */
      var uintV bvi = 0; /* Run loop bvl times */
      while (bvi != bvl) {
        {
          pushSTACK(STACK_(6+3+2)); /* sequence */
          pushSTACK(STACK_(0+1)); /* pointer */
          funcall(seq_access(STACK_(2+2+2)),2); /* (SEQ-ACCESS sequence pointer) */
          funcall_key(STACK_(2+3+2),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        }
        /* Put item into the table; if already existing,
           mark to be removed at pointer. */
        {
          var object old_value = shifthash(STACK_1,value1,T,true);
          if (!nullp(old_value)) {
            /* item already in ht -> mark it as to be removed */
            sbvector_bset(STACK_(0+2),bvi); /* (setf (sbit bv bvi) 1) */
            dl = dl+1; /* dl:=dl+1 */
          }
        }
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_(6+3+2),STACK_(2+2));
        bvi++; /* bvi := bvi+1 */
      }
    } else {
      /* from-end is not given */
      /* pointer runs from left to right (from start to end). */
      var uintV bvi = 0; /* Run loop bvl times */
      while (bvi != bvl) {
        {
          pushSTACK(STACK_(6+3+2)); /* sequence */
          pushSTACK(STACK_(0+1)); /* pointer */
          funcall(seq_access(STACK_(2+2+2)),2); /* (SEQ-ACCESS sequence pointer) */
          funcall_key(STACK_(2+3+2),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        }
        /* Put item into te table; if already existing
           mark the previous position. */
        {
          var object old_value = shifthash(STACK_1,value1,fixnum(bvi),true);
          if (!nullp(old_value)) {
            /* item already in ht -> mark at the previous position */
            var uintV i = posfixnum_to_V(old_value);
            sbvector_bset(STACK_(0+2),i); /* (setf (sbit bv i) 1) */
            dl = dl+1; /* dl:=dl+1 */
          }
        }
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_(6+3+2),STACK_(2+2));
        bvi++; /* bvi := bvi+1 */
      }
    }
    skipSTACK(2); /* forget ht and pointer */
  }
  /* Stack layout:
       sequence [stackptr], from-end, start, end, key, test, test-not,
       typdescr, l, bv. */
  VALUES1((*help_fun)(stackptr,bvl,dl));
  skipSTACK(7+3); /* Cleanup STACK */
}

LISPFUN(remove_duplicates,seclass_default,1,0,norest,key,6,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not)) )
{ /* (REMOVE-DUPLICATES sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not]),
 CLTL p. 254 */
  return_Values seq_duplicates(&remove_help);
}

LISPFUN(delete_duplicates,seclass_default,1,0,norest,key,6,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not)) )
{ /* (DELETE-DUPLICATES sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not]),
 CLTL p. 254 */
  return_Values seq_duplicates(&delete_help);
}

/* UP: Helper function for the SUBSTITUTE functions.
 Constructs for a sequence a new sequence, where exactly those elements
 are replaced, which are marked in a bitvector.
 > stackptr: Pointer to the stack, *(stackptr+2)=newitem,
    *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
 > STACK_2: typdescr,
 > STACK_1: Length l of the sequence,
 > STACK_0: Bitvector bv,
 > bvl: Length of the bitvector (= end - start),
 > dl: Number of set bits in the bitvector,
 < result: New sequence
 can trigger GC */
local maygc object substitute_help (gcv_object_t* stackptr, uintV bvl,
                                    uintV dl) {
  /* dl=0 -> return sequence unchanged: */
  if (dl==0)
    return *(stackptr STACKop 0);
  if (eq(seq_type(STACK_2),S(list))) /* Type LIST ? */
    /* Now check, if sequence is really a LIST. */
    /* Because of l >= dl > 0 we have to test, if sequence is a Cons. */
    if (mconsp(*(stackptr STACKop 0))) {
      /* Special case for lists: */
      pushSTACK(NIL); /* L1 := nil */
      pushSTACK(*(stackptr STACKop 0)); /* L2 := sequence */
      /* Stack layout: ..., typdescr, l, bv, L1, L2. */
      { /* Copy first start Conses: */
        var uintV count = posfixnum_to_V(*(stackptr STACKop -2)); /* 0 <= start <= l ==> start is fixnum */
        while (count--) {
          /* Here is (revappend L1 L2) = sequence */
          var object new_cons = allocate_cons();
          var object L2 = STACK_0;
          Car(new_cons) = Car(L2);
          STACK_0 = Cdr(L2); /* L2 := (cdr L2) */
          Cdr(new_cons) = STACK_1; STACK_1 = new_cons; /* L1 := (cons ... L1) */
        }
      }
      /* decrement bvl over the last one in the bitvector: */
      /* (There exist ones, because dl>0.) */
      {
        var object bv = STACK_(0+2);
        while (1) {
          var uintV bvl_1 = bvl-1;
          if (sbvector_btst(bv,bvl_1)) /* Check bit bvl-1 */
            break;
          bvl = bvl_1; /* Bit =0 -> decrement bvl and continue search */
        }
      }
      { /* Copy part resp. fill with newitem: */
        var uintV bvi = 0; /* bvi := 0 */
        while (bvi != bvl) { /* Run loop bvl times */
          if (sbvector_btst(STACK_(0+2),bvi)) { /* Check (sbit bv bvi) */
            /* Bit =1 -> take newitem */
            pushSTACK(*(stackptr STACKop 2)); /* newitem */
          } else {
            /* Bit =0 -> take (car L2) */
            pushSTACK(Car(STACK_0));
          }
          {
            var object new_cons = allocate_cons();
            Car(new_cons) = popSTACK(); /* with above as CAR */
            Cdr(new_cons) = STACK_1; STACK_1 = new_cons; /* L1 := (cons ... L1) */
          }
          STACK_0 = Cdr(STACK_0); /* L2 := (cdr L2) */
          bvi++; /* bvi:=bvi+1 */
        }
      }
      /* Add last tail part unchanged: */
      {
        var object L2 = popSTACK();
        var object L1 = popSTACK();
        return nreconc(L1,L2); /* (nreconc L1 L2) as result value */
      }
    }
  /* Allocate new sequence: */
  pushSTACK(STACK_1); /* l */
  funcall(seq_make(STACK_(2+1)),1); /* (SEQ-MAKE l) */
  pushSTACK(value1); /* =: sequence2 */
  /* Stack layout: ..., typdescr, l, bv, sequence2. */
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  pushSTACK(STACK_(3+1)); /* typdescr */
  pushSTACK(STACK_(0+2)); /* sequence2 */
  pushSTACK(STACK_(3+3)); /* typdescr */
  pushSTACK(*(stackptr STACKop -2)); /* start */
  /* Stack layout: ..., typdescr, l, bv, sequence2,
                   seq1, typdescr1, seq2, typdescr2, start. */
  pushSTACK(STACK_4); funcall(seq_init(STACK_(3+1)),1); /* (SEQ-INIT sequence) */
  pushSTACK(value1); /* =: pointer1 */
  pushSTACK(STACK_(2+1)); funcall(seq_init(STACK_(1+1+1)),1); /* (SEQ-INIT sequence2) */
  pushSTACK(value1); /* =: pointer2 */
  /* Stack layout: ..., typdescr, l, bv, sequence2,
                   seq1, typdescr1, seq2, typdescr2, start,
                   pointer1, pointer2. */
  { /* Head part: */
    /* Copy elements with index <start of sequence1 to sequence2 unchanged: */
    copy_seqpart_into();
  }
  { /* Middle part: */
    var uintV bvi = 0;
    while (bvi != bvl) {
      var object item; /* to be copied element */
      if (sbvector_btst(STACK_(1+5+2),bvi)) { /* Check (sbit bv bvi) */
        /* Bit =1 -> take newitem: */
        item = *(stackptr STACKop 2);
      } else {
        /* Bit =0 -> take element from sequence: */
        pushSTACK(STACK_(4+2)); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(3+2+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
        item = value1;
      }
      pushSTACK(STACK_(2+2)); pushSTACK(STACK_(0+1)); pushSTACK(item);
      funcall(seq_access_set(STACK_(1+2+3)),3); /* (SEQ-ACCESS-SET seq2 pointer2 ...) */
      /* Advance pointer1, pointer2, bvi: */
      /* pointer1 := (SEQ-UPD seq1 pointer1) : */
      pointer_update(STACK_1,STACK_(4+2),STACK_(3+2));
      /* pointer2 := (SEQ-UPD seq2 pointer2) : */
      pointer_update(STACK_0,STACK_(2+2),STACK_(1+2));
      bvi++;
    }
  }
  { /* Tail part: */
    /* Copy elements with index >=end of sequence1 to sequence2 unchanged: */
    STACK_(0+2) = I_I_minus_I(STACK_(2+5+2),*(stackptr STACKop -3)); /* (- l end) */
    copy_seqpart_into();
  }
  skipSTACK(5+2);
  return popSTACK(); /* sequence2 as result value */
}

/* UP: Executes a SUBSTITUTE operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer into the stack, *(stackptr+2)=newitem,
    *(stackptr+0)=sequence
 > pcall_test: address of test function with the following specification:
           > stackptr: the pointer into the stack
           > x,y: arguments
           < true, if the test is satisfied, false otherwise. */
local Values substitute_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  seq_prepare_filterop(stackptr);
  /* Stack layout:
       ... sequence [stackptr] from-end start end key ... count typdescr,
       l [STACK]. */
  if (nullp(*(stackptr STACKop -1)) && eq(seq_type(STACK_(0+1)),S(list))) {
    /* from-end is not specified, and the sequence type is LIST. */
    /* In this case we don't need to allocate a bit vector. */
    pushSTACK(NIL); /* result1 := NIL */
    pushSTACK(*(stackptr STACKop 0)); /* result2 := sequence */
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    funcall(seq_init_start(STACK_(0+3+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    pushSTACK(STACK_(1+4)); /* countdown := count */
    /* Stack layout: ..., count, typdescr,
                     l, result1, result2, pointer, countdown [STACK]. */
    /* length of the relevant portion */
    var uintV bvl = end_minus_start(stackptr STACKop -3,stackptr STACKop -2,
                                    stackptr STACKop 0);
    for (; bvl > 0; bvl--) {
      if (!nullp(STACK_(1+5)) && eq(STACK_0,Fixnum_0))
        /* count/=NIL and countdown=0 -> can terminate loop */
        break;
        /* Test next element: */
      pushSTACK(*(stackptr STACKop 0)); /* sequence */
      pushSTACK(STACK_(1+1)); /* pointer */
      funcall(seq_access(STACK_(0+5+2)),2); /* (SEQ-ACCESS sequence pointer) */
      funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key ...) */
      if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
        /* Test fulfilled. */
        /* result1 := (cons newitem (nreconc (ldiff result2 pointer) result1)) */
        pushSTACK(STACK_2); pushSTACK(STACK_(1+1)); funcall(L(ldiff),2);
        STACK_3 = nreconc(value1,STACK_3);
        var object new_cons = allocate_cons();
        Car(new_cons) = *(stackptr STACKop 2); Cdr(new_cons) = STACK_3;
        STACK_3 = new_cons;
        /* result2 := (setq pointer (cdr pointer)) */
        pointer_update(STACK_1,*(stackptr STACKop 0),STACK_(0+5));
        STACK_2 = STACK_1;
        if (!nullp(STACK_(1+5))) { /* if count/=NIL: */
          decrement(STACK_0); /* (decf countdown) */
        }
      } else { /* Test failed. */
        /* (setq pointer (cdr pointer)) */
        pointer_update(STACK_1,*(stackptr STACKop 0),STACK_(0+5));
      }
    }
    /* Return (nreconc result1 result2): */
    VALUES1(nreconc(STACK_3,STACK_2));
    skipSTACK(5);
  } else {
    /* Use a bit vector for doing the filtering. */
    seq_filterop(stackptr,pcall_test,&substitute_help);
  }
}

LISPFUN(substitute,seclass_default,3,0,norest,key,7,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),
         kw(test_not),kw(count)) )
{ /* (SUBSTITUTE newitem item sequence [:from-end] [:start] [:end] [:key]
                                       [:test] [:test-not] [:count]),
 CLTL p. 255 */
  var gcv_object_t* stackptr = &STACK_7;
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* test function */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  substitute_op(stackptr,pcall_test);
  skipSTACK(3+7+1);
}

LISPFUN(substitute_if,seclass_default,3,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (SUBSTITUTE-IF newitem test sequence [:from-end] [:start] [:end]
                                          [:key] [:count]),
 CLTL p. 255 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  substitute_op(stackptr,&seq_call_if);
  skipSTACK(3+5+1);
}

LISPFUN(substitute_if_not,seclass_default,3,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (SUBSTITUTE-IF-NOT newitem test sequence [:from-end] [:start] [:end]
                                              [:key] [:count]),
 CLTL p. 255 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  substitute_op(stackptr,&seq_call_if_not);
  skipSTACK(3+5+1);
}

/* UP: Helper function for NSUBSTITUTE functions for the case FROM-END.
 Replaces in the sequence exactly those elements, which are marked in a bitvector.
 > stackptr: Pointer to the stack, *(stackptr+2)=newitem,
    *(stackptr+0)=sequence, *(stackptr-2)=start, *(stackptr-3)=end,
 > STACK_2: typdescr,
 > STACK_1: Length l of the sequence,
 > STACK_0: Bitvector bv,
 > bvl: Length of the bitvector (= end - start),
 > dl: Number of set bits in the bitvector,
 < result: same sequence
 can trigger GC */
local maygc object nsubstitute_fe_help (gcv_object_t* stackptr, uintV bvl,
                                        uintV dl) {
  {
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(*(stackptr STACKop -2)); /* start */
    funcall(seq_init_start(STACK_(2+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
  }
  /* Stack layout: ..., typdescr, l, bv,
                       pointer. */
  {
    var uintV bvi = 0; /* bvi := 0 */
    while (bvi != bvl) { /* Run loop bvl times */
      if (sbvector_btst(STACK_(0+1),bvi)) { /* Check (sbit bv bvi) */
        /* Bit =1 -> replace element by newitem: */
        pushSTACK(*(stackptr STACKop 0)); /* sequence */
        pushSTACK(STACK_(0+1)); /* pointer */
        pushSTACK(*(stackptr STACKop 2)); /* newitem */
        funcall(seq_access_set(STACK_(2+1+3)),3); /* (SEQ-ACCESS-SET sequence pointer newitem) */
      }
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_0,*(stackptr STACKop 0),STACK_(2+1));
      bvi++; /* bvi:=bvi+1 */
    }
  }
  skipSTACK(1); /* forget pointer */
  return *(stackptr STACKop 0); /* sequence as result */
}

/* Macro: Put endvar := (and end (- end start)) to the STACK
 init_endvar(stackptr);
 > stackptr: Pointer to the stack, *(stackptr+1)=start, *(stackptr+0)=end */
#define init_endvar(stackptr) do {                                      \
  var object end = *(stackptr STACKop 0); /* end */                     \
  if (!(nullp(end)))                                                    \
    end = I_I_minus_I(end,*(stackptr STACKop 1)); /* (- end start), an integer >=0 */ \
  pushSTACK(end);                                                       \
 } while(0)

/* Macro: decrement endvar if endvar/=NIL
 decrement_endvar(endvar);
 > object endvar: either NIL or a fixnum >0
 < object endvar: either still NIL or (decremented) a fixnum >=0 */
#define decrement_endvar(endvar) do {                     \
  if (!(nullp(endvar))) { /* end given? */                \
    decrement(endvar); /* yes -> endvar := (1- endvar) */ \
  }                                                       \
 } while(0)

/* UP: Executes a NSUBSTITUTE operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... count typdescr [STACK]
 > stackptr: Pointer to the stack, *(stackptr+2)=newitem
 > pcall_test: Address of the test function, specified like:
            > stackptr: same pointer to the stack,
            > x,y: arguments
            < true, if test ok, otherwise false.
 < mv_space/mv_count: Result values
 can trigger GC */
local maygc Values nsubstitute_op (gcv_object_t* stackptr, funarg_t* pcall_test)
{
  if (!(nullp(*(stackptr STACKop -1)))) { /* check from-end */
    /* from-end is given -> create bitvector and replace then: */
    seq_prepare_filterop(stackptr);
    return_Values seq_filterop(stackptr,pcall_test,&nsubstitute_fe_help);
  } else {
    /* from-end is not given */
    /* COUNT argument must be NIL or an integer >= 0: */
    test_count_arg();
    /* Now all argumente are checked. */
    pushSTACK(*(stackptr STACKop 0)); /* sequence */
    pushSTACK(*(stackptr STACKop -4)); /* key */
    init_endvar(&*(stackptr STACKop -3)); /* endvar := (and end (- end start)) to the stack */
    pushSTACK(STACK_(1+3)); /* countdown := count */
    /* Stack layout: ..., count, typdescr,
                     sequence, key, endvar, countdown. */
    {
      pushSTACK(STACK_3); /* sequence */
      pushSTACK(*(stackptr STACKop -2)); /* start */
      funcall(seq_init_start(STACK_(0+4+2)),2); /* (SEQ-INIT-START sequence start) */
      pushSTACK(value1); /* =: pointer */
    }
    /* Stack layout: ..., count, typdescr,
                     sequence, key, endvar, countdown, pointer. */
    /* endvar and countdown are either =NIL or an integer >=0. */
    {
      while (!eq(STACK_2,Fixnum_0)) { /* endvar = 0 ? */
        /* (so end is given and already looped through (- end start) elements?) */
        /* yes -> finished */
        pushSTACK(STACK_4); pushSTACK(STACK_(0+1));
        funcall(seq_endtest(STACK_(0+5+2)),2); /* (SEQ-ENDTEST sequence pointer) */
        if (!(nullp(value1))) /* Pointer at the end -> finished */
          break;
        if (eq(STACK_1,Fixnum_0)) /* countdown=0 ? */
          /* (also count given and exhausted?) */
          break; /* yes -> loop can be finished */
        /* pick out item: */
        pushSTACK(STACK_4); pushSTACK(STACK_(0+1));
        funcall(seq_access(STACK_(0+5+2)),2); /* (SEQ-ACCESS sequence pointer) */
        funcall_key(STACK_3,value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        /* value1 =: item */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
          /* Test is ok */
          pushSTACK(STACK_4); pushSTACK(STACK_(0+1));
          pushSTACK(*(stackptr STACKop 2)); /* newitem */
          funcall(seq_access_set(STACK_(0+5+3)),3); /* (SEQ-ACCESS-SET sequence pointer newitem) */
          if (!(nullp(STACK_(1+5)))) { /* falls count/=NIL: */
            decrement(STACK_1); /* (decf countdown) */
          }
        }
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_4,STACK_(0+5));
        /* decrement endvar evtl.: */
        decrement_endvar(STACK_2);
      }
    }
    skipSTACK(4);
    VALUES1(popSTACK()); /* return modified sequence */
  }
}

LISPFUN(nsubstitute,seclass_default,3,0,norest,key,7,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not),kw(count)) )
{ /* (NSUBSTITUTE newitem item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not] [:count]),
 CLTL p. 256 */
  var gcv_object_t* stackptr = &STACK_7;
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* test funtion */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  nsubstitute_op(stackptr,pcall_test);
  skipSTACK(3+7+1);
}

LISPFUN(nsubstitute_if,seclass_default,3,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (NSUBSTITUTE-IF newitem test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 256 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  nsubstitute_op(stackptr,&seq_call_if);
  skipSTACK(3+5+1);
}

LISPFUN(nsubstitute_if_not,seclass_default,3,0,norest,key,5,
        (kw(from_end),kw(start),kw(end),kw(key),kw(count)) )
{ /* (NSUBSTITUTE-IF-NOT newitem test sequence [:from-end] [:start] [:end] [:key] [:count]),
 CLTL p. 256 */
  var gcv_object_t* stackptr = &STACK_5;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  nsubstitute_op(stackptr,&seq_call_if_not);
  skipSTACK(3+5+1);
}

/* UP: Executes a FIND operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... typdescr [STACK]
 > stackptr: Pointer to the stack
 > pcall_test: Address of the test function, spezified like:
            > stackptr: same pointer to the stack,
            > x,y: arguments
            < true, if the test is ok, otherwise false.
 < mv_space/mv_count: return values
 can trigger GC */
local maygc Values find_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  /* Stack layout: ..., typdescr, sequence. */
  if (!(nullp(*(stackptr STACKop -1)))) { /* check from-end */
    /* from-end is given */
    /* The default value for end is the length of the sequence: */
    if (nullp(*(stackptr STACKop -3))) {
      pushSTACK(STACK_0); funcall(seq_length(STACK_(1+1)),1); /* (SEQ-LENGTH sequence) */
      *(stackptr STACKop -3) = value1; /* =: end */
      /* So check again start and end: */
      test_start_end(&O(kwpair_start),&*(stackptr STACKop -3));
    }
    {
      pushSTACK(STACK_0); pushSTACK(*(stackptr STACKop -3));
      funcall(seq_fe_init_end(STACK_(1+2)),2); /* (SEQ-FE-INIT-END sequence end) */
      pushSTACK(value1); /* =: pointer */
    }
    { /* count := (- end start), an integer >=0 : */
      pushSTACK(I_I_minus_I(*(stackptr STACKop -3),*(stackptr STACKop -2)));
    }
    /* Stack layout: ..., typdescr, sequence, pointer, count. */
    {
      while (!eq(STACK_0,Fixnum_0)) { /* count (an integer) = 0 -> fertig */
        /* pick out item: */
        pushSTACK(STACK_2); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(3+2)),2); /* (SEQ-ACCESS sequence pointer) */
        pushSTACK(value1); /* =: item */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key item) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1))
          goto found; /* Test ok -> found */
        /* Test failed */
        skipSTACK(1); /* forget item */
        /* Advance pointer and decrement count: */
        /* pointer := (SEQ-FE-UPD sequence pointer) : */
        pointer_fe_update(STACK_1,STACK_2,STACK_3);
        decrement(STACK_0); /* count := (1- count) */
      }
    }
  } else { /* from-end is not given */
    init_endvar(&*(stackptr STACKop -3)); /* endvar := (and end (- end start)) to the stack */
    /* Stack layout: ..., typdescr, sequence, endvar. */
    {
      pushSTACK(STACK_1); pushSTACK(*(stackptr STACKop -2));
      funcall(seq_init_start(STACK_(2+2)),2); /* (SEQ-INIT-START sequence start) */
      pushSTACK(value1); /* =: pointer */
    }
    /* Stack layout: ... typdescr, sequence, endvar, pointer */
    {
      while (!eq(STACK_1,Fixnum_0)) { /* endvar = 0 ? */
        /* (so end is given and already looped (- end start) elements?) */
        /* yes -> finished */
        pushSTACK(STACK_2); pushSTACK(STACK_(0+1));
        funcall(seq_endtest(STACK_(3+2)),2); /* (SEQ-ENDTEST sequence pointer) */
        if (!(nullp(value1))) /* Pointer at the end -> finished */
          break;
        /* pick out item: */
        pushSTACK(STACK_2); pushSTACK(STACK_(0+1));
        funcall(seq_access(STACK_(3+2)),2); /* (SEQ-ACCESS sequence pointer) */
        pushSTACK(value1); /* =: item */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key item) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1))
          goto found; /* Test ok -> found */
        /* Test failed */
        skipSTACK(1); /* forget item */
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_2,STACK_3);
        /* decrement endvar evtl.: */
        decrement_endvar(STACK_1);
      }
    }
  }
  skipSTACK(3); /* cleanup STACK */
  VALUES1(NIL); return;
 found: /* found item (on STACK_0), with ok test. */
  VALUES1(popSTACK()); /* return item */
  skipSTACK(3); /* cleanup STACK */
}

LISPFUN(find,seclass_default,2,0,norest,key,6,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not)) )
{ /* (FIND item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_6;
  var funarg_t* pcall_test = check_test_args(&STACK_0); /* test function */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  find_op(stackptr,pcall_test);
  skipSTACK(2+6+1);
}

LISPFUN(find_if,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (FIND-IF test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  find_op(stackptr,&seq_call_if);
  skipSTACK(2+4+1);
}

LISPFUN(find_if_not,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (FIND-IF-NOT test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  find_op(stackptr,&seq_call_if_not);
  skipSTACK(2+4+1);
}

/* UP: Executes a POSITION operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... typdescr [STACK]
 > stackptr: Pointer to the stack
 > pcall_test: Address to a test function, spezifizied like:
            > stackptr: same pointer to the stack,
            > x,y: arguments
            < true, if test ok, otherwise false.
 < mv_space/mv_count: return values
 can trigger GC */
local maygc Values position_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  /* Stack layout: ..., typdescr, sequence. */
  if (!(nullp(*(stackptr STACKop -1)))) { /* check from-end */
    /* from-end is given */
    /* Default value for end is the length of the sequence: */
    if (nullp(*(stackptr STACKop -3))) {
      pushSTACK(STACK_0); funcall(seq_length(STACK_(1+1)),1); /* (SEQ-LENGTH sequence) */
      *(stackptr STACKop -3) = value1; /* =: end */
      /* So check again start and end: */
      test_start_end(&O(kwpair_start),&*(stackptr STACKop -3));
    }
    pushSTACK(*(stackptr STACKop -3)); /* index := end */
    {
      pushSTACK(STACK_(0+1)); pushSTACK(*(stackptr STACKop -3));
      funcall(seq_fe_init_end(STACK_(1+1+2)),2); /* (SEQ-FE-INIT-END sequence end) */
      pushSTACK(value1); /* =: pointer */
    }
    { /* count := (- end start), an integer >=0 : */
      pushSTACK(I_I_minus_I(*(stackptr STACKop -3),*(stackptr STACKop -2)));
    }
    /* Stack layout: ..., typdescr, sequence, index, pointer, count. */
    {
      while (!eq(STACK_0,Fixnum_0)) { /* count (an integer) = 0 -> fertig */
        /* decrement index: */
        decrement(STACK_2);
        /* pick out item: */
        pushSTACK(STACK_3); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer) */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1))
          goto found; /* Test ok -> found */
        /* Test failed */
        /* Advance pointer and decrement count: */
        /* pointer := (SEQ-FE-UPD sequence pointer) : */
        pointer_fe_update(STACK_1,STACK_3,STACK_4);
        decrement(STACK_0); /* count := (1- count) */
      }
    }
  } else {
    /* from-end is not given */
    pushSTACK(*(stackptr STACKop -2)); /* index := start */
    init_endvar(&*(stackptr STACKop -3)); /* endvar := (and end (- end start)) to the stack */
    /* Stack layout: ..., typdescr, sequence, index, endvar. */
    {
      pushSTACK(STACK_2); pushSTACK(*(stackptr STACKop -2));
      funcall(seq_init_start(STACK_(3+2)),2); /* (SEQ-INIT-START sequence start) */
      pushSTACK(value1); /* =: pointer */
    }
    /* Stack layout: ... typdescr, sequence, index, endvar, pointer */
    {
      while (!eq(STACK_1,Fixnum_0)) { /* endvar = 0 ? */
        /* (also end given and run through (- end start) elements?) */
        /* yes -> finished */
        pushSTACK(STACK_3); pushSTACK(STACK_(0+1));
        funcall(seq_endtest(STACK_(4+2)),2); /* (SEQ-ENDTEST sequence pointer) */
        if (!(nullp(value1))) /* pointer at the end -> finished */
          break;
        /* pick out item: */
        pushSTACK(STACK_3); pushSTACK(STACK_(0+1));
        funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer) */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1))
          goto found; /* Test ok -> found */
        /* Test failed */
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_3,STACK_4);
        /* decrement endvar evtl.: */
        decrement_endvar(STACK_1);
        /* increment index: */
        increment(STACK_2);
      }
    }
  }
  skipSTACK(4); /* Cleanup STACK */
  VALUES1(NIL); return;
 found: /* item found, for which the test is ok. STACK_2 = index. */
  VALUES1(STACK_2); /* return index */
  skipSTACK(4); /* Cleanup STACK */
}

LISPFUN(position,seclass_default,2,0,norest,key,6,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not)) )
{ /* (POSITION item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_6;
  var funarg_t* pcall_test = check_test_args(&STACK_0); /* test function */
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  position_op(stackptr,pcall_test);
  skipSTACK(2+6+1);
}

LISPFUN(position_if,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (POSITION-IF test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  position_op(stackptr,&seq_call_if);
  skipSTACK(2+4+1);
}

LISPFUN(position_if_not,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (POSITION-IF-NOT test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* Prepare arguments, typdescr */
  position_op(stackptr,&seq_call_if_not);
  skipSTACK(2+4+1);
}

/* UP: Executes a COUNT operation.
 > Stack layout:
      ... sequence [stackptr] from-end start end key ... typdescr [STACK]
 > stackptr: Pointer to the stack
 > pcall_test: Address of a test function, specified like this:
            > stackptr: same pointer to the stack,
            > x,y: arguments
            < true, of test ok, or false.
 < mv_space/mv_count: return values
 can trigger GC */
local maygc Values count_op (gcv_object_t* stackptr, funarg_t* pcall_test) {
  pushSTACK(*(stackptr STACKop 0)); /* sequence */
  pushSTACK(Fixnum_0); /* total := 0 */
  /* Stack layout: ..., typdescr, sequence, total. */
  if (!(nullp(*(stackptr STACKop -1)))) { /* Check from-end */
    /* from-end is given */
    /* Default value for end is the sequence length: */
    if (nullp(*(stackptr STACKop -3))) {
      pushSTACK(STACK_1); funcall(seq_length(STACK_(2+1)),1); /* (SEQ-LENGTH sequence) */
      *(stackptr STACKop -3) = value1; /* =: end */
      /* So again start and end check: */
      test_start_end(&O(kwpair_start),&*(stackptr STACKop -3));
    }
    {
      pushSTACK(STACK_1); pushSTACK(*(stackptr STACKop -3));
      funcall(seq_fe_init_end(STACK_(2+2)),2); /* (SEQ-FE-INIT-END sequence end) */
      pushSTACK(value1); /* =: pointer */
    }
    { /* count := (- end start), an integer >=0 : */
      pushSTACK(I_I_minus_I(*(stackptr STACKop -3),*(stackptr STACKop -2)));
    }
    /* Stack layout: ..., typdescr, sequence, total, pointer, count. */
    {
      while (!eq(STACK_0,Fixnum_0)) { /* count (an integer) = 0 -> finished */
        /* Pick out item: */
        pushSTACK(STACK_3); pushSTACK(STACK_(1+1));
        funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer) */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
          /* Test ok -> total := total + 1 : */
          STACK_2 = fixnum_inc(STACK_2,1);
        }
        /* Advance pointer and decrement count: */
        /* pointer := (SEQ-FE-UPD sequence pointer) : */
        pointer_fe_update(STACK_1,STACK_3,STACK_4);
        decrement(STACK_0); /* count := (1- count) */
      }
    }
  } else {
    /* from-end is not given */
    init_endvar(&*(stackptr STACKop -3)); /* endvar := (and end (- end start)) to the stack */
    /* Stack layout: ..., typdescr, sequence, total, endvar. */
    {
      pushSTACK(STACK_2); pushSTACK(*(stackptr STACKop -2));
      funcall(seq_init_start(STACK_(3+2)),2); /* (SEQ-INIT-START sequence start) */
      pushSTACK(value1); /* =: pointer */
    }
    /* Stack layout: ... typdescr, sequence, total, endvar, pointer */
    {
      while (!eq(STACK_1,Fixnum_0)) { /* endvar = 0 ? */
        /* (so end is given and run through (- end start) elements?) */
        /* yes -> finished */
        pushSTACK(STACK_3); pushSTACK(STACK_(0+1));
        funcall(seq_endtest(STACK_(4+2)),2); /* (SEQ-ENDTEST sequence pointer) */
        if (!(nullp(value1))) /* Pointer at the end -> finished */
          break;
        /* Pick out item: */
        pushSTACK(STACK_3); pushSTACK(STACK_(0+1));
        funcall(seq_access(STACK_(4+2)),2); /* (SEQ-ACCESS sequence pointer) */
        funcall_key(*(stackptr STACKop -4),value1); /* (FUNCALL key (SEQ-ACCESS sequence pointer)) */
        if ((*pcall_test)(stackptr STACKop -6,*(stackptr STACKop 1),value1)) {
          /* Test ok -> total := total + 1 : */
          STACK_2 = fixnum_inc(STACK_2,1);
        }
        /* pointer := (SEQ-UPD sequence pointer) : */
        pointer_update(STACK_0,STACK_3,STACK_4);
        /* decrement endvar evtl.: */
        decrement_endvar(STACK_1);
      }
    }
  }
  VALUES1(STACK_2); skipSTACK(4); /* return total */
}

LISPFUN(count,seclass_default,2,0,norest,key,6,
        (kw(from_end),kw(start),kw(end),kw(key),kw(test),kw(test_not)) )
{ /*(COUNT item sequence [:from-end] [:start] [:end] [:key] [:test] [:test-not])
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_6;
  var funarg_t* pcall_test = check_test_args(&STACK_0); /* test function */
  seq_prepare_testop(stackptr); /* prepare arguments, typedescr */
  count_op(stackptr,pcall_test);
  skipSTACK(2+6+1);
}

LISPFUN(count_if,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (COUNT-IF test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* prepare arguments, typedescr */
  count_op(stackptr,&seq_call_if);
  skipSTACK(2+4+1);
}

LISPFUN(count_if_not,seclass_default,2,0,norest,key,4,
        (kw(from_end),kw(start),kw(end),kw(key)) )
{ /* (COUNT-IF-NOT test sequence [:from-end] [:start] [:end] [:key]),
 CLTL p. 257 */
  var gcv_object_t* stackptr = &STACK_4;
  seq_prepare_testop(stackptr); /* prepare arguments, typedescr */
  count_op(stackptr,&seq_call_if_not);
  skipSTACK(2+4+1);
}

LISPFUN(mismatch,seclass_default,2,0,norest,key,8,
        (kw(start1),kw(end1),kw(start2),kw(end2),kw(from_end),
         kw(key),kw(test),kw(test_not)) )
{ /* (MISMATCH sequence1 sequence2 [:start1] [:end1] [:start2] [:end2]
               [:from-end] [:key] [:test] [:test-not])
 CLTL p. 257 */
  /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                   key, test, test-not. */
  var gcv_object_t* stackptr = &STACK_6;
  /* key check: */
  check_key_arg(&STACK_2);
  /* test, test-not check: */
  var funarg_t* pcall_test = check_test_args(&STACK_0);
  /* sequence1 check: */
  pushSTACK(get_valid_seq_type(STACK_(6+3)));
  /* sequence2 check: */
  pushSTACK(get_valid_seq_type(STACK_(5+3+1)));
  /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                   key, test, test-not, typdescr1, typdescr2. */
  default_NIL(STACK_(0+5)); /* Default value for from-end is NIL */
  start_default_0(STACK_(4+5)); /* Default value for start1 is 0 */
  default_NIL(STACK_(3+5)); /* Default value for end1 is NIL */
  start_default_0(STACK_(2+5)); /* Default value for start2 is 0 */
  default_NIL(STACK_(1+5)); /* Default value for end2 is NIL */
  /* Check from-end: */
  if (!(nullp(STACK_(0+5)))) { /* from-end is given */
    /* Default value of end1 is (SEQ-LENGTH seq1): */
    end_default_len(STACK_(3+5),STACK_(6+5),STACK_1);
    /* Default value of end2 is (SEQ-LENGTH seq2): */
    end_default_len(STACK_(1+5),STACK_(5+5),STACK_0);
    /* check start- and end arguments: */
    test_start_end(&O(kwpair_start1),&STACK_(3+5));
    test_start_end(&O(kwpair_start2),&STACK_(1+5));
    /* Set pointer1 and pointer2 to the of the sequences: */
    {
      pushSTACK(STACK_(6+5)); pushSTACK(STACK_(3+5+1));
      funcall(seq_fe_init_end(STACK_(1+2)),2); /* (SEQ-FE-INIT-END seq1 end1) */
      pushSTACK(value1); /* =: pointer1 */
    }
    {
      pushSTACK(STACK_(5+5+1)); pushSTACK(STACK_(1+5+1+1));
      funcall(seq_fe_init_end(STACK_(0+1+2)),2); /* (SEQ-FE-INIT-END seq2 end2) */
      pushSTACK(value1); /* =: pointer2 */
    }
    { pushSTACK(STACK_(3+5+2)); } /* index := end1 */
    {
      var object len1 = I_I_minus_I(STACK_(3+5+3),STACK_(4+5+3)); /* (- end1 start1) */
      pushSTACK(len1); /* =: len1, an integer >=0 */
    }
    {
      var object len2 = I_I_minus_I(STACK_(1+5+4),STACK_(2+5+4)); /* (- end2 start2) */
      pushSTACK(len2); /* =: len2, an integer >=0 */
    }
    {
      var object count = (I_I_comp(STACK_1,STACK_0)<0 ? STACK_1 : STACK_0); /* (min len1 len2) */
      pushSTACK(count); /* =: count, an integer >=0 */
    }
    /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                     key, test, test-not, typdescr1, typdescr2,
                     pointer1, pointer2, index, len1, len2, count. */
    while (!eq(STACK_0,Fixnum_0)) { /* count (an integer) = 0 ? */
      pushSTACK(STACK_(6+5+6)); pushSTACK(STACK_(5+1));
      funcall(seq_access(STACK_(1+6+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
      funcall_key(STACK_(4+6),value1); /* (FUNCALL key (SEQ-ACCESS seq1 pointer1)) */
      pushSTACK(value1); /* =: item1, save */
      pushSTACK(STACK_(5+5+6+1)); pushSTACK(STACK_(4+1+1));
      funcall(seq_access(STACK_(0+6+1+2)),2); /* (SEQ-ACCESS seq2 pointer2) */
      funcall_key(STACK_(4+6+1),value1); /* (FUNCALL key (SEQ-ACCESS seq2 pointer2)) */
      {
        var object item2 = value1;
        var object item1 = popSTACK();
        /* compare both: */
        if (!((*pcall_test)(&STACK_(2+6),item1,item2))) /* Call test function */
          goto fe_found;
      }
      /* Test ok -> continue search: */
      /* pointer1 := (SEQ-FE-UPD seq1 pointer1) : */
      pointer_fe_update(STACK_5,STACK_(6+5+6),STACK_(1+6));
      /* pointer2 := (SEQ-FE-UPD seq2 pointer2) : */
      pointer_fe_update(STACK_4,STACK_(5+5+6),STACK_(0+6));
      /* decrement index: */
      decrement(STACK_3);
      /* decrement count: */
      decrement(STACK_0);
    }
    /* Loop successful. */
    /* With len1=len2 return NIL, otherwise index: */
    if (I_I_comp(STACK_2,STACK_1)==0) { /* len1=len2 (integers) ? */
      /* Both sequence parts are equal -> NIL as result value */
      VALUES1(NIL); skipSTACK(7+5+6); return;
    }
   fe_found: /* Difference found -> index as result value */
    {
      VALUES1(STACK_3); skipSTACK(7+5+6); return;
    }
  } else {
    /* from-end is not given */
    /* Check start- and end arguments: */
    test_start_end_1(&O(kwpair_start1),&STACK_(3+5));
    test_start_end_1(&O(kwpair_start2),&STACK_(1+5));
    /* Set pointer1 and pointer2 to the start of the sequences: */
    {
      pushSTACK(STACK_(6+5)); pushSTACK(STACK_(4+5+1));
      funcall(seq_init_start(STACK_(1+2)),2); /* (SEQ-INIT-START seq1 start1) */
      pushSTACK(value1); /* =: pointer1 */
    }
    {
      pushSTACK(STACK_(5+5+1)); pushSTACK(STACK_(2+5+1+1));
      funcall(seq_init_start(STACK_(0+1+2)),2); /* (SEQ-INIT-START seq2 start2) */
      pushSTACK(value1); /* =: pointer2 */
    }
    { pushSTACK(STACK_(4+5+2)); } /* index := start1 */
    init_endvar(&STACK_(3+5+3)); /* endvar1 := (and end1 (- end1 start1)) */
    init_endvar(&STACK_(1+5+4)); /* endvar2 := (and end2 (- end2 start2)) */
    /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                     key, test, test-not, typdescr1, typdescr2,
                     pointer1, pointer2, index, endvar1, endvar2. */
    {
      var bool seq1_ended; /* Flag, if seq1-part at end */
      var bool seq2_ended; /* Flag, if seq2-part at end */
      while (1) {
        /* Test, if seq1-part at end: */
        if (eq(STACK_1,Fixnum_0)) /* endvar1 = 0 (and therefore end1 /= nil) ? */
          seq1_ended = true;
        else {
          pushSTACK(STACK_(6+5+5)); pushSTACK(STACK_(4+1));
          funcall(seq_endtest(STACK_(1+5+2)),2); /* (SEQ-ENDTEST seq1 pointer1) */
          seq1_ended = !nullp(value1);
        }
        /* Test, if seq2-part at end: */
        if (eq(STACK_0,Fixnum_0)) /* endvar2 = 0 (and therefore end2 /= nil) ? */
          seq2_ended = true;
        else {
          pushSTACK(STACK_(5+5+5)); pushSTACK(STACK_(3+1));
          funcall(seq_endtest(STACK_(0+5+2)),2); /* (SEQ-ENDTEST seq2 pointer2) */
          seq2_ended = !nullp(value1);
        }
        /* Check flags: */
        if (seq1_ended || seq2_ended)
          break;
        /* None of both flags set */
        pushSTACK(STACK_(6+5+5)); pushSTACK(STACK_(4+1));
        funcall(seq_access(STACK_(1+5+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
        funcall_key(STACK_(4+5),value1); /* (FUNCALL key (SEQ-ACCESS seq1 pointer1)) */
        pushSTACK(value1); /* =: item1, save */
        pushSTACK(STACK_(5+5+5+1)); pushSTACK(STACK_(3+1+1));
        funcall(seq_access(STACK_(0+5+1+2)),2); /* (SEQ-ACCESS seq2 pointer2) */
        funcall_key(STACK_(4+5+1),value1); /* (FUNCALL key (SEQ-ACCESS seq2 pointer2)) */
        {
          var object item2 = value1;
          var object item1 = popSTACK();
          /* compare both: */
          if (!((*pcall_test)(&STACK_(2+5),item1,item2)))
            goto fs_found;
        }
        /* Test ok -> continue search: */
        /* pointer1 := (SEQ-UPD seq1 pointer1) : */
        pointer_update(STACK_4,STACK_(6+5+5),STACK_(1+5));
        /* pointer2 := (SEQ-UPD seq2 pointer2) : */
        pointer_update(STACK_3,STACK_(5+5+5),STACK_(0+5));
        /* increment index: */
        increment(STACK_2);
        /* decrement endvar1 evtl.: */
        decrement_endvar(STACK_1);
        /* decrement endvar2 evtl.: */
        decrement_endvar(STACK_0);
      }
      /* If bith flags are set, return NIL, otherwise index: */
      if (seq1_ended && seq2_ended) {
        /* Both sequence-parts are equal -> NIL as return value */
        VALUES1(NIL); skipSTACK(7+5+5); return;
      }
     fs_found: /* Difference found -> index as return value */
      {
        VALUES1(STACK_2); skipSTACK(7+5+5); return;
      }
    }
  }
}

LISPFUN(search,seclass_default,2,0,norest,key,8,
        (kw(start1),kw(end1),kw(start2),kw(end2),kw(from_end),
         kw(key),kw(test),kw(test_not)) )
{ /* (SEARCH sequence1 sequence2 [:start1] [:end1] [:start2] [:end2]
             [:from-end] [:key] [:test] [:test-not]),
 CLTL p. 258
     Primitive algorithm:
       Always advance in sequence2 by 1 and compare with sequence1.
     KMP algorithm:
       [Donald Ervin Knuth, James H. Morris, Vaughan R. Pratt:
        Fast pattern matching in string.
        SIAM J. Comput. 6(1977), 323-350.]
       Cannot be used here, because this requires the commutativity of the test
       function, which according to CLTL p. 247 is not always guaranteed.
  Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                key, test, test-not. */
  var gcv_object_t* stackptr = &STACK_6;
  /* key check: */
  check_key_arg(&STACK_2);
  /* test, test-not check: */
  var funarg_t* pcall_test = check_test_args(&STACK_0);
  /* sequence1 check: */
  pushSTACK(get_valid_seq_type(STACK_(6+3)));
  /* sequence2 check: */
  pushSTACK(get_valid_seq_type(STACK_(5+3+1)));
  /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                   key, test, test-not, typdescr1, typdescr2. */
  default_NIL(STACK_(0+5)); /* Default value for from-end is NIL */
  /* Special case for strings: call faster routine */
  if (eq(seq_type(STACK_1),S(string)) && eq(seq_type(STACK_0),S(string)) /* both STRINGs ? */
      && nullp(STACK_(0+5)) /* and no from-end ? */
      && eq(STACK_4,L(identity)) /* and key = #'identity ? */
      && (pcall_test == &call_test)) { /* and test-not not given ? */
    var object test = STACK_3;
    if (eq(test,L(eq)) || eq(test,L(eql)) || eq(test,L(equal)) || eq(test,L(char_eq))) {
      skipSTACK(6);
      C_search_string_eq(); /* SUBR sys::search-string= with same arguments */
      return;
    }
    if (eq(test,L(equalp)) || eq(test,L(char_equal))) {
      skipSTACK(6);
      C_search_string_equal(); /* SUBR sys::search-string-equal with same arguments */
      return;
    }
  }
  start_default_0(STACK_(4+5)); /* Default value for start1 is 0 */
  default_NIL(STACK_(3+5)); /* Default value for end1 is NIL */
  start_default_0(STACK_(2+5)); /* Default value for start2 is 0 */
  default_NIL(STACK_(1+5)); /* Default value for end2 is NIL */
  /* Check from-end: */
  if (!(nullp(STACK_(0+5)))) {
    /* from-end is given */
    /* Default value of end1 is (SEQ-LENGTH seq1): */
    end_default_len(STACK_(3+5),STACK_(6+5),STACK_1);
    /* Default value of end2 is (SEQ-LENGTH seq2): */
    end_default_len(STACK_(1+5),STACK_(5+5),STACK_0);
    /* Check start- and end arguments: */
    test_start_end(&O(kwpair_start1),&STACK_(3+5));
    test_start_end(&O(kwpair_start2),&STACK_(1+5));
    /* Place pointer10 and pointer20 to the end of the sequences: */
    {
      pushSTACK(STACK_(6+5)); pushSTACK(STACK_(3+5+1));
      funcall(seq_fe_init_end(STACK_(1+2)),2); /* (SEQ-FE-INIT-END seq1 end1) */
      pushSTACK(value1); /* =: pointer10 */
    }
    {
      pushSTACK(STACK_(5+5+1)); pushSTACK(STACK_(1+5+1+1));
      funcall(seq_fe_init_end(STACK_(0+1+2)),2); /* (SEQ-FE-INIT-END seq2 end2) */
      pushSTACK(value1); /* =: pointer20 */
    }
    {
      var object len1 = I_I_minus_I(STACK_(3+5+2),STACK_(4+5+2)); /* (- end1 start1) */
      pushSTACK(len1); /* =: len1, an integer >=0 */
    }
    {
      var object len2 = I_I_minus_I(STACK_(1+5+3),STACK_(2+5+3)); /* (- end2 start2) */
      pushSTACK(len2); /* =: len2, an integer >=0 */
    }
    {
      var object index = I_I_minus_I(STACK_(1+5+4),STACK_1); /* (- end2 len1) */
      pushSTACK(index); /* =: index, an integer */
    }
    /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                     key, test, test-not, typdescr1, typdescr2,
                     pointer10, pointer20, len1, len2, index. */
    while (1) {
      /* Run pointer1 and pointer2 from pointer10 resp. pointer20 on: */
      {
        pushSTACK(STACK_4); funcall(seq_copy(STACK_(1+5+1)),1); /* (SEQ-COPY pointer10) */
        pushSTACK(value1); /* =: pointer1 */
      }
      {
        pushSTACK(STACK_(3+1)); funcall(seq_copy(STACK_(0+5+1+1)),1); /* (SEQ-COPY pointer20) */
        pushSTACK(value1); /* =: pointer2 */
      }
      pushSTACK(STACK_(2+2)); /* count1 := len1 */
      pushSTACK(STACK_(1+3)); /* count2 := len2 */
      /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                       key, test, test-not, typdescr1, typdescr2,
                       pointer10, pointer20, len1, len2, index,
                       pointer1, pointer2, count1, count2. */
      while (1) {
        if (eq(STACK_1,Fixnum_0)) /* count1 (an integer) = 0 ? */
          goto found; /* yes -> seq1 finished, found */
        if (eq(STACK_0,Fixnum_0)) /* count2 (an integer) = 0 ? */
          goto notfound; /* yes -> seq2 finished, not found */
        pushSTACK(STACK_(6+5+5+4)); pushSTACK(STACK_(3+1));
        funcall(seq_access(STACK_(1+5+4+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
        funcall_key(STACK_(4+5+4),value1); /* (FUNCALL key (SEQ-ACCESS seq1 pointer1)) */
        pushSTACK(value1); /* =: item1, save */
        pushSTACK(STACK_(5+5+5+4+1)); pushSTACK(STACK_(2+1+1));
        funcall(seq_access(STACK_(0+5+4+1+2)),2); /* (SEQ-ACCESS seq2 pointer2) */
        funcall_key(STACK_(4+5+4+1),value1); /* (FUNCALL key (SEQ-ACCESS seq2 pointer2)) */
        {
          var object item2 = value1;
          var object item1 = popSTACK();
          /* compare both: */
          if (!((*pcall_test)(&STACK_(2+5+4),item1,item2)))
            break;
        }
        /* Test ok -> continue comparing: */
        /* pointer1 := (SEQ-FE-UPD seq1 pointer1) : */
        pointer_fe_update(STACK_3,STACK_(6+5+5+4),STACK_(1+5+4));
        /* pointer2 := (SEQ-FE-UPD seq2 pointer2) : */
        pointer_fe_update(STACK_2,STACK_(5+5+5+4),STACK_(0+5+4));
        /* decrement count1: */
        decrement(STACK_1);
        /* decrement count2: */
        decrement(STACK_0);
      }
      /* Test not ok -> continue searching */
      skipSTACK(4); /* forget pointer1, pointer2, count1, count2 */
      /* Advance pointer20, decrement len2 and index: */
      pointer_fe_update(STACK_3,STACK_(6+5+5),STACK_(0+5));
      decrement(STACK_1); /* len2 := (1- len2) */
      decrement(STACK_0); /* index := (1- index) */
    }
  } else {
    /* from-end is not given */
    /* Check start- and end arguments: */
    test_start_end_1(&O(kwpair_start1),&STACK_(3+5));
    test_start_end_1(&O(kwpair_start2),&STACK_(1+5));
    /* Set pointer10 and pointer20 to the start of the sequences: */
    {
      pushSTACK(STACK_(6+5)); pushSTACK(STACK_(4+5+1));
      funcall(seq_init_start(STACK_(1+2)),2); /* (SEQ-INIT-START seq1 start1) */
      pushSTACK(value1); /* =: pointer10 */
    }
    {
      pushSTACK(STACK_(5+5+1)); pushSTACK(STACK_(2+5+1+1));
      funcall(seq_init_start(STACK_(0+1+2)),2); /* (SEQ-INIT-START seq2 start2) */
      pushSTACK(value1); /* =: pointer20 */
    }
    init_endvar(&STACK_(3+5+2)); /* endvar10 := (and end1 (- end1 start1)) */
    init_endvar(&STACK_(1+5+3)); /* endvar20 := (and end2 (- end2 start2)) */
    pushSTACK(STACK_(2+5+4)); /* index := start2 */
    /* Stack layout: seq1, seq2, start1, end1, start2, end2, from-end,
                     key, test, test-not, typdescr1, typdescr2,
                     pointer10, pointer20, endvar10, endvar20, index. */
    while (1) {
      /* Run pointer1 and pointer2 from pointer10 resp. pointer20 on: */
      {
        pushSTACK(STACK_4); funcall(seq_copy(STACK_(1+5+1)),1); /* (SEQ-COPY pointer10) */
        pushSTACK(value1); /* =: pointer1 */
      }
      {
        pushSTACK(STACK_(3+1)); funcall(seq_copy(STACK_(0+5+1+1)),1); /* (SEQ-COPY pointer20) */
        pushSTACK(value1); /* =: pointer2 */
      }
      pushSTACK(STACK_(2+2)); /* endvar1 := endvar10 */
      pushSTACK(STACK_(1+3)); /* endvar2 := endvar20 */
      /* Stack layout: seq1, seq2, from-end, start1, end1, start2, end2,
                       key, test, test-not, typdescr1, typdescr2,
                       pointer10, pointer20, endvar10, endvar20, index,
                       pointer1, pointer2, endvar1, endvar2. */
      while (1) {
        /* Test, if seq1-part at the end. If yes: found. */
        if (eq(STACK_1,Fixnum_0)) /* endvar1 = 0 (and therefore end1 /= nil) ? */
          goto found;
        else {
          pushSTACK(STACK_(6+5+5+4)); pushSTACK(STACK_(3+1));
          funcall(seq_endtest(STACK_(1+5+4+2)),2); /* (SEQ-ENDTEST seq1 pointer1) */
          if (!nullp(value1))
            goto found;
        }
        /* seq1 not at the end. */
        /* Test, if seq2-part at the end. If yes: not found. */
        if (eq(STACK_0,Fixnum_0)) /* endvar2 = 0 (and therefore end2 /= nil) ? */
          goto notfound;
        else {
          pushSTACK(STACK_(5+5+5+4)); pushSTACK(STACK_(2+1));
          funcall(seq_endtest(STACK_(0+5+4+2)),2); /* (SEQ-ENDTEST seq2 pointer2) */
          if (!nullp(value1))
            goto notfound;
        }
        /* seq2 not at the end. */
        pushSTACK(STACK_(6+5+5+4)); pushSTACK(STACK_(3+1));
        funcall(seq_access(STACK_(1+5+4+2)),2); /* (SEQ-ACCESS seq1 pointer1) */
        funcall_key(STACK_(4+5+4),value1); /* (FUNCALL key (SEQ-ACCESS seq1 pointer1)) */
        pushSTACK(value1); /* =: item1, save */
        pushSTACK(STACK_(5+5+5+4+1)); pushSTACK(STACK_(2+1+1));
        funcall(seq_access(STACK_(0+5+4+1+2)),2); /* (SEQ-ACCESS seq2 pointer2) */
        funcall_key(STACK_(4+5+4+1),value1); /* (FUNCALL key (SEQ-ACCESS seq2 pointer2)) */
        {
          var object item2 = value1;
          var object item1 = popSTACK();
          /* compare both: */
          if (!((*pcall_test)(&STACK_(2+5+4),item1,item2)))
            break;
        }
        /* Test ok -> continue comparing: */
        /* pointer1 := (SEQ-UPD seq1 pointer1) : */
        pointer_update(STACK_3,STACK_(6+5+5+4),STACK_(1+5+4));
        /* pointer2 := (SEQ-UPD seq2 pointer2) : */
        pointer_update(STACK_2,STACK_(5+5+5+4),STACK_(0+5+4));
        /* endvar1 evtl. decrement: */
        decrement_endvar(STACK_1);
        /* endvar2 evtl. decrement: */
        decrement_endvar(STACK_0);
      }
      /* Test failed -> continue searching */
      skipSTACK(4); /* forget pointer1, pointer2, endvar1, endvar2 */
      /* Advance pointer20: */
      pointer_update(STACK_3,STACK_(6+5+5),STACK_(0+5));
      /* endvar20 evtl. decrement: */
      decrement_endvar(STACK_1);
      /* increment index: */
      increment(STACK_0);
    }
  }
  /*NOTREACHED*/
 found: { /* return index as result value */
    VALUES1(STACK_4); skipSTACK(7+5+5+4); return;
  }
 notfound: { /* return NIL as result value */
    VALUES1(NIL); skipSTACK(7+5+5+4); return;
  }
}

/* UP for SORT, STABLE-SORT and MERGE:
 merge(stackptr);
 merges two sorted sequence parts into a third sequence.
 > STACK_10: sequence1
 > STACK_9: typdescr1
 > STACK_8: sequence2
 > STACK_7: typdescr2
 > STACK_6: sequence3
 > STACK_5: typdescr3
 > STACK_4: count1 (an integer >=0)
 > STACK_3: count2 (an integer >=0)
 > STACK_2: pointer1
 > STACK_1: pointer2
 > STACK_0: pointer3
 > stackptr: Pointer to the stack,
      *(stackptr+0) = predicate, *(stackptr-1) = key
 count1+count2 elements from sequence1 or sequence2 will be copied to sequence3
 (the ones from sequence1 preferred).
 pointer1 will be incremented exactly count1 times (with SEQ-UPD),
 pointer2 will be incremented exactly count2 times (with SEQ-UPD),
 pointer3 will be incremented exactly count1+count2 times (with SEQ-UPD).
 count1 and count2 will be set to 0.
 can trigger GC */
local maygc void merge (gcv_object_t* stackptr) {
  while (1) {
    if (eq(STACK_4,Fixnum_0)) /* count1 = 0 -> seq1 at the end */
      goto seq1_end;
    if (eq(STACK_3,Fixnum_0)) /* count1 = 0 -> seq2 at the end */
      goto seq2_end;
    /* get item2: */
    {
      pushSTACK(STACK_8); pushSTACK(STACK_(1+1));
      funcall(seq_access(STACK_(7+2)),2); /* (SEQ-ACCESS sequence2 pointer2) */
      funcall_key(*(stackptr STACKop -1),value1); /* (FUNCALL key (SEQ-ACCESS sequence2 pointer2)) */
      pushSTACK(value1); /* =: item2 */
    }
    /* get item1: */
    {
      pushSTACK(STACK_(10+1)); pushSTACK(STACK_(2+1+1));
      funcall(seq_access(STACK_(9+1+2)),2); /* (SEQ-ACCESS sequence1 pointer1) */
      funcall_key(*(stackptr STACKop -1),value1); /* (FUNCALL key (SEQ-ACCESS sequence1 pointer1)) */
      pushSTACK(value1); /* =: item1 */
    }
    funcall(*(stackptr STACKop 0),2); /* (FUNCALL predicate item2 item1) */
    if (nullp(value1)) {
      /* predicate returned NIL, take item from sequence1: */
      pushSTACK(STACK_(10)); pushSTACK(STACK_(2+1));
      funcall(seq_access(STACK_(9+2)),2); /* (SEQ-ACCESS sequence1 pointer1) */
      pushSTACK(value1); /* to the stack */
      /* pointer1 := (SEQ-UPD sequence1 pointer1) : */
      pointer_update(STACK_(2+1),STACK_(10+1),STACK_(9+1));
      /* count1 := (1- count1) : */
      decrement(STACK_(4+1));
    } else {
      /* predicate returned OK, take item from sequence2: */
      pushSTACK(STACK_(8)); pushSTACK(STACK_(1+1));
      funcall(seq_access(STACK_(7+2)),2); /* (SEQ-ACCESS sequence2 pointer2) */
      pushSTACK(value1); /* to the stack */
      /* pointer2 := (SEQ-UPD sequence2 pointer2) : */
      pointer_update(STACK_(1+1),STACK_(8+1),STACK_(7+1));
      /* count2 := (1- count2) : */
      decrement(STACK_(3+1));
    }
    {
      var object item = popSTACK(); /* item to hand over */
      pushSTACK(STACK_6); pushSTACK(STACK_(0+1)); pushSTACK(item);
      funcall(seq_access_set(STACK_(5+3)),3); /* (SEQ-ACCESS-SET sequence3 pointer3 item) */
    }
    /* pointer3 := (SEQ-UPD sequence3 pointer3) : */
    pointer_update(STACK_0,STACK_6,STACK_5);
  }
  /*NOTREACHED*/
 seq1_end:
  /* sequence1 finished. Take rest from sequence2:
     If sequence2 and sequence3 are EQ, we are called from SORT or STABLE-SORT.
     There are also the pointers pointer2 and pointer3 equal, so we do not have to copy. */
  if (eq(STACK_8,STACK_6)) /* sequence2 = sequence3 ? */
    return;
  while (!eq(STACK_3,Fixnum_0)) { /* count2 = 0 ? */
    pushSTACK(STACK_(8)); pushSTACK(STACK_(1+1));
    funcall(seq_access(STACK_(7+2)),2); /* (SEQ-ACCESS sequence2 pointer2) */
    pushSTACK(STACK_6); pushSTACK(STACK_(0+1)); pushSTACK(value1);
    funcall(seq_access_set(STACK_(5+3)),3); /* (SEQ-ACCESS-SET sequence3 pointer3 ...) */
    /* pointer2 := (SEQ-UPD sequence2 pointer2) : */
    pointer_update(STACK_1,STACK_8,STACK_7);
    /* count2 := (1- count2) : */
    decrement(STACK_3);
    /* pointer3 := (SEQ-UPD sequence3 pointer3) : */
    pointer_update(STACK_0,STACK_6,STACK_5);
  }
  return;
 seq2_end:
  /* sequence2 finished, sequence1 not. Take rest from sequence1: */
  do {
    pushSTACK(STACK_(10)); pushSTACK(STACK_(2+1));
    funcall(seq_access(STACK_(9+2)),2); /* (SEQ-ACCESS sequence1 pointer1) */
    pushSTACK(STACK_6); pushSTACK(STACK_(0+1)); pushSTACK(value1);
    funcall(seq_access_set(STACK_(5+3)),3); /* (SEQ-ACCESS-SET sequence3 pointer3 ...) */
    /* pointer1 := (SEQ-UPD sequence1 pointer1) : */
    pointer_update(STACK_2,STACK_10,STACK_9);
    /* count1 := (1- count1) : */
    decrement(STACK_4);
    /* pointer3 := (SEQ-UPD sequence3 pointer3) : */
    pointer_update(STACK_0,STACK_6,STACK_5);
  } while (!eq(STACK_4,Fixnum_0)); /* count1 = 0 ? */
  return;
}

/* UP: Sorts in sequence starting from pointer_left exactly k elements (k >= 1)
 and returns a pointer behind these k elements.
 sort_part(pointer_left,k,stackptr)
 pointer_left is destructively changed.
 > pointer_left
 > k
 > stackptr: Pointer into the stack:
             sequence, predicate [stackptr], key, start, end, typdescr, seq2
 < result: Pointer after the k elements
 can trigger GC */
local maygc object sort_part (object pointer_left, object k,
                              gcv_object_t* stackptr) {
  if (eq(k,Fixnum_1)) {
    /* k=1. Almost nothing to do. */
    pushSTACK(*(stackptr STACKop 1)); pushSTACK(pointer_left);
    funcall(seq_upd(*(stackptr STACKop -4)),2); /* (SEQ-UPD sequence pointer_left) */
    return value1; /* as result */
  } else {
    /* k>1. */
    pushSTACK(pointer_left);
    pushSTACK(k);
    pushSTACK(I_I_ash_I(k,Fixnum_minus1)); /* (ASH k -1) = (FLOOR k 2) =: kl */
    STACK_1 = I_I_minus_I(STACK_1,STACK_0); /* (- k (FLOOR k 2)) = (CEILING k 2) =: kr */
    /* Stack layout: pointer_left, kr, kl. */
    /* with kl = (floor k 2) and kr = (ceiling k 2), so k = (+ kl kr). */
    { /* Sort recursively the left half: */
      pushSTACK(STACK_2); /* pointer_left */
      funcall(seq_copy(*(stackptr STACKop -4)),1); /* (SEQ-COPY pointer_left) */
      var object pointer_mid = sort_part(value1,STACK_0,stackptr);
      pushSTACK(pointer_mid);
    }
    /* Stack layout: pointer_left, kr, kl, pointer_mid. */
    { /* Sort recursively the right half: */
      pushSTACK(STACK_0); /* pointer_mid */
      funcall(seq_copy(*(stackptr STACKop -4)),1); /* (SEQ-COPY pointer_mid) */
      var object pointer_right = sort_part(value1,STACK_2,stackptr);
      pushSTACK(pointer_right);
    }
    /* Stack layout: pointer_left, kr, kl, pointer_mid, pointer_right. */
    { /* Copy left half (sorted) to seq2: */
      var object typdescr = *(stackptr STACKop -4);
      pushSTACK(*(stackptr STACKop 1)); /* sequence */
      pushSTACK(typdescr); /* typdescr */
      pushSTACK(*(stackptr STACKop -5)); /* seq2 */
      pushSTACK(typdescr); /* typdescr */
      pushSTACK(STACK_(2+4)); /* kl */
      {
        pushSTACK(STACK_(4+5)); /* pointer_left */
        funcall(seq_copy(typdescr),1); /* (SEQ-COPY pointer_left) */
        pushSTACK(value1); /* =: pointer1 */
      }
      typdescr = STACK_2;
      {
        pushSTACK(STACK_3); /* seq2 */
        funcall(seq_init(typdescr),1); /* (SEQ-INIT seq2) */
        pushSTACK(value1); /* =: pointer2 */
      }
      /* Stack layout: pointer_left, kr, kl, pointer_mid, pointer_right,
                       sequence, typdescr, seq2, typdescr, kl, pointer1, pointer2. */
      copy_seqpart_into(); /* do the copy */
      skipSTACK(3);
    }
    /* Stack layout: pointer_left, kr, kl, pointer_mid, pointer_right,
                     sequence, typdescr, seq2, typdescr. */
    {
      pushSTACK(STACK_3); /* sequence */
      pushSTACK(STACK_(2+1)); /* typdescr */
      pushSTACK(STACK_(3+2)); /* sequence */
      pushSTACK(STACK_(2+3)); /* typdescr */
      pushSTACK(STACK_(2+4+4)); /* kl */
      pushSTACK(STACK_(3+4+5)); /* kr */
      {
        pushSTACK(STACK_(1+6)); /* seq2 */
        funcall(seq_init(STACK_(0+6+1)),1); /* (SEQ-INIT seq2) */
        pushSTACK(value1); /* as source pointer in seq2 */
      }
      pushSTACK(STACK_(1+4+7)); /* pointer_mid as source in sequence */
      pushSTACK(STACK_(4+4+8)); /* pointer_left as destination in sequence */
      merge(stackptr); /* merge from seq2 into sequence */
      var object pointer_right = STACK_(0+4+9); /* pointer_right */
      skipSTACK(5+4+9);
      return pointer_right; /* as result */
    }
  }
}

/* UP for SORT and STABLE-SORT: Sorts a part of a sequence.
 stable_sort();
 > Stack layout: sequence, predicate, key, start, end
 < mv_space/mv_count: Values
 can trigger GC */
local maygc Values stable_sort (void) {
  /* Stack layout: sequence, predicate, key, start, end. */
  /* Check sequence: */
  pushSTACK(get_valid_seq_type(STACK_4)); /* typdescr */
  /* Stack layout: sequence, predicate, key, start, end, typdescr. */
  /* Default value for start is 0 : */
  start_default_0(STACK_2);
  /* Default value for end: */
  end_default_len(STACK_1,STACK_5,STACK_0);
  /* Check arguments start and end: */
  test_start_end(&O(kwpair_start),&STACK_1);
  /* key check: */
  check_key_arg(&STACK_3);
  /* l := (- end start), an integer >=0 */
  var object l = I_I_minus_I(STACK_1,STACK_2);
  pushSTACK(l);
  /* Stack layout: sequence, predicate, key, start, end, typdescr, l. */
  if (!(eq(l,Fixnum_0))) { /* Nothing to do when l=0 */
    /* Create helper sequence with length (floor l 2): */
    {
      pushSTACK(I_I_ash_I(l,Fixnum_minus1)); /* (ASH l -1) = (FLOOR l 2) */
      funcall(seq_make(STACK_(1+1)),1); /* (SEQ-MAKE (FLOOR l 2)) */
      pushSTACK(value1); /* =: seq2 */
    }
    /* Stack layout: sequence, predicate, key, start, end, typdescr, l, seq2. */
    pushSTACK(STACK_(6+1)); pushSTACK(STACK_(3+1+1));
    funcall(seq_init_start(STACK_(1+1+2)),2); /* (SEQ-INIT-START sequence start) */
    l = STACK_(0+1); STACK_(0+1) = STACK_0; skipSTACK(1); /* seq2 replaces l at the stack */
    sort_part(value1,l,&STACK_5); /* Sort part of length l from the start */
  }
  skipSTACK(6); VALUES1(popSTACK()); /* return sorted sequence */
}

LISPFUN(sort,seclass_default,2,0,norest,key,3, (kw(key),kw(start),kw(end)) )
{ /* (SORT sequence predicate [:key] [:start] [:end]), CLTL p. 258 */
  return_Values stable_sort();
}

LISPFUN(stable_sort,seclass_default,2,0,norest,key,3,
        (kw(key),kw(start),kw(end)) )
{ /* (STABLE-SORT sequence predicate [:key] [:start] [:end]), CLTL p. 258 */
  return_Values stable_sort();
}

LISPFUN(merge,seclass_default,4,0,norest,key,1, (kw(key)) )
{ /* (MERGE result-type sequence1 sequence2 predicate [:key]), CLTL p. 260 */
  pushSTACK(NIL);
  /* Stack layout: result-type, sequence1, sequence2, predicate, key, nil. */
  /* key-Argument check: */
  check_key_arg(&STACK_1);
  { /* sequence1 check: */
    var object seq1 = STACK_4;
    pushSTACK(seq1);
    pushSTACK(get_valid_seq_type(seq1));
  }
  { /* sequence2 check: */
    var object seq2 = STACK_(3+2);
    pushSTACK(seq2);
    pushSTACK(get_valid_seq_type(seq2));
  }
  { /* result-type check: */
    var object typdescr3 = valid_type(&STACK_(5+4));
    pushSTACK(typdescr3);
    STACK_6 = STACK_1;
  }
  /* Stack layout: result-type, sequence1, sequence2, predicate, key, result-type-len,
                  sequence1, typdescr1, sequence2, typdescr2, result-type-len, typdescr3. */
  /* Set lengths of sequence1 and sequence2: */
  {
    pushSTACK(STACK_5); funcall(seq_length(STACK_(4+1)),1); /* (SEQ-LENGTH sequence1) */
    pushSTACK(value1); /* =: len1 */
  }
  {
    pushSTACK(STACK_(3+1)); funcall(seq_length(STACK_(2+1+1)),1); /* (SEQ-LENGTH sequence2) */
    pushSTACK(value1); /* =: len2 */
  }
  { /* Add both lengths and construct new sequence with sum-length: */
    pushSTACK(I_I_plus_I(STACK_1,STACK_0)); /* (+ len1 len2) */
    if (integerp(STACK_(1+3)) && !SEQTYPE_LENGTH_MATCH(STACK_(1+3),STACK_0))
      error_seqtype_length(STACK_(1+3),STACK_0);
    funcall(seq_make(STACK_(0+2+1)),1); /* (SEQ-MAKE (+ len1 len2)) */
    STACK_(1+2) = value1; /* replace result-type-len in the stack */
  }
  /* Stack layout: result-type, sequence1, sequence2, predicate, key, result-type-len,
                  sequence1, typdescr1, sequence2, typdescr2, sequence3, typdescr3,
                  len1, len2. */
  { /* Set pointers to the start of the sequences: */
    pushSTACK(STACK_(5+2)); funcall(seq_init(STACK_(4+2+1)),1); /* (SEQ-INIT sequence1) */
    pushSTACK(value1); /* =: pointer1 */
  }
  {
    pushSTACK(STACK_(3+2+1)); funcall(seq_init(STACK_(2+2+1+1)),1); /* (SEQ-INIT sequence2) */
    pushSTACK(value1); /* =: pointer2 */
  }
  {
    pushSTACK(STACK_(1+2+2)); funcall(seq_init(STACK_(0+2+2+1)),1); /* (SEQ-INIT sequence3) */
    pushSTACK(value1); /* =: pointer3 */
  }
  /* Stack layout: result-type, sequence1, sequence2, predicate, key, result-type-len,
                  sequence1, typdescr1, sequence2, typdescr2, sequence3, typdescr3,
                  len1, len2, pointer1, pointer2, pointer3. */
  /* Do the Merge-Operation: */
  merge(&STACK_(2+6+5));
  VERIFY_RETURN_VALUE(&STACK_(1+5),&STACK_(0+6+5));
  VALUES1(STACK_(1+5)); /* return sequence3 */
  skipSTACK(6+6+5);
}

LISPFUN(read_char_sequence,seclass_default,2,0,norest,key,2,
        (kw(start),kw(end)) )
{ /* (READ-CHAR-SEQUENCE sequence stream [:start] [:end]), cf. dpANS p. 21-26 */
  /* Stack layout: sequence, stream, start, end. */
  /* check sequence: */
  pushSTACK(get_valid_seq_type(STACK_3));
  /* Stack layout: sequence, stream, start, end, typdescr. */
  STACK_3 = check_stream(STACK_3);
  /* Default value for start is 0: */
  start_default_0(STACK_2);
  /* Default value for end is the length of the sequence: */
  end_default_len(STACK_1,STACK_4,STACK_0);
  /* Check start- and end arguments: */
  test_start_end(&O(kwpair_start),&STACK_1);
  if (eq(seq_type(STACK_0),S(string))) { /* Typename = STRING ? */
    var uintV start = posfixnum_to_V(STACK_2);
    var uintV end = posfixnum_to_V(STACK_1);
    if (end-start == 0) {
      VALUES1(Fixnum_0); skipSTACK(5); return;
    }
    var uintL index = 0;
    STACK_0 = array_displace_check(STACK_4,end,&index);
    if (simple_nilarray_p(STACK_0)) error_nilarray_store();
    check_sstring_mutable(STACK_0);
    var uintL result = read_char_array(&STACK_3,&STACK_0,index+start,end-start);
    VALUES1(fixnum(start+result));
    skipSTACK(5);
  } else {
    /* Set running pointer: */
    pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
    funcall(seq_init_start(STACK_(0+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    /* Stack layout: sequence, stream, index, end, typdescr, pointer. */
    while (!eql(STACK_3,STACK_2)) { /* index = end (both integers) -> finished */
      var object item = read_char(&STACK_4); /* read one element */
      if (eq(item,eof_value)) /* EOF -> finished */
        break;
      pushSTACK(STACK_5); pushSTACK(STACK_(0+1)); pushSTACK(item);
      funcall(seq_access_set(STACK_(1+3)),3); /* (SEQ-ACCESS-SET sequence pointer item) */
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_0,STACK_5,STACK_1);
      /* index := (1+ index) : */
      increment(STACK_3);
    }
    VALUES1(STACK_3); /* return index */
    skipSTACK(6);
  }
}

LISPFUN(write_char_sequence,seclass_default,2,0,norest,key,2,
        (kw(start),kw(end)) )
{ /* (WRITE-CHAR-SEQUENCE sequence stream [:start] [:end]), cf. dpANS p. 21-27 */
  /* Stack layout: sequence, stream, start, end. */
  /* Check sequence: */
  pushSTACK(get_valid_seq_type(STACK_3));
  /* Stack layout: sequence, stream, start, end, typdescr. */
  STACK_3 = check_stream(STACK_3);
  /* Default value for start is 0: */
  start_default_0(STACK_2);
  /* Default value for end is the length of the sequence: */
  end_default_len(STACK_1,STACK_4,STACK_0);
  /* Check start and end arguments: */
  test_start_end(&O(kwpair_start),&STACK_1);
  if (eq(seq_type(STACK_0),S(string))) { /* Typename = STRING ? */
    var uintV start = posfixnum_to_V(STACK_2);
    var uintV end = posfixnum_to_V(STACK_1);
    var uintV len = end-start;
    if (len > 0) {
      var uintL index = 0;
      STACK_0 = array_displace_check(STACK_4,end,&index);
      if (simple_nilarray_p(STACK_0)) error_nilarray_retrieve();
      write_char_array(&STACK_3,&STACK_0,index+start,len);
    }
  } else {
    /* subtract start- and end arguments: */
    STACK_1 = I_I_minus_I(STACK_1,STACK_2); /* (- end start), an integer >=0 */
    /* Stack layout: sequence, item, start, count, typdescr. */
    /* Set running pointer: */
    pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
    funcall(seq_init_start(STACK_(0+2)),2); /* (SEQ-INIT-START sequence start) */
    STACK_2 = value1; /* =: pointer */
    /* Stack layout: sequence, stream, pointer, count, typdescr. */
    while (!eq(STACK_1,Fixnum_0)) { /* count (an integer) = 0 -> fertig */
      pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
      funcall(seq_access(STACK_(0+2)),2); /* (SEQ-ACCESS sequence pointer) */
      write_char(&STACK_3,value1); /* write one element */
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_2,STACK_4,STACK_0);
      /* count := (1- count) : */
      decrement(STACK_1);
    }
  }
  skipSTACK(4);
  VALUES1(popSTACK()); /* return sequence */
}

LISPFUN(read_byte_sequence,seclass_default,2,0,norest,key,4,
        (kw(start),kw(end),kw(no_hang),kw(interactive)) )
{ /* (READ-BYTE-SEQUENCE sequence stream [:start] [:end] [:no-hang] [:interactive]),
    cf. dpANS p. 21-26 */
  /* Stack layout: sequence, stream, start, end, no-hang, interactive. */
  var bool interactive = !missingp(STACK_0);
  var bool no_hang = !missingp(STACK_1);
  skipSTACK(2);
  pushSTACK(get_valid_seq_type(STACK_3)); /* check sequence */
  /* Stack layout: sequence, stream, start, end, typdescr. */
  STACK_3 = check_stream(STACK_3);
  start_default_0(STACK_2); /* default value for start is 0 */
  end_default_len(STACK_1,STACK_4,STACK_0); /* end defaults to length */
  test_start_end(&O(kwpair_start),&STACK_1); /* check start and end */
  if (eq(seq_type(STACK_0),fixnum(8))) {
    /* type = (VECTOR (UNSIGNED-BYTE 8)) ? */
    var uintV start = posfixnum_to_V(STACK_2);
    var uintV end = posfixnum_to_V(STACK_1);
    var uintL index = 0;
    STACK_0 = array_displace_check(STACK_4,end,&index);
    var uintL result =
      read_byte_array(&STACK_3,&STACK_0,index+start,end-start,
                      no_hang ? persev_immediate : interactive
                      ? persev_partial : persev_full);
    VALUES1(fixnum(start+result));
    skipSTACK(5);
  } else {
    /* determine start pointer: */
    pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
    funcall(seq_init_start(STACK_(0+2)),2); /* (SEQ-INIT-START sequence start) */
    pushSTACK(value1); /* =: pointer */
    /* Stack layout: sequence, stream, index, end, typdescr, pointer. */
    while (!eql(STACK_3,STACK_2)) { /* index = end (both integers) -> done */
      if (no_hang && LISTEN_AVAIL != listen_byte(STACK_4))
        break;
      var object item = read_byte(STACK_4); /* get an element */
      if (eq(item,eof_value)) /* EOF -> done */
        break;
      /* (SEQ-ACCESS-SET sequence pointer item): */
      pushSTACK(STACK_5); pushSTACK(STACK_(0+1)); pushSTACK(item);
      funcall(seq_access_set(STACK_(1+3)),3);
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_0,STACK_5,STACK_1);
      increment(STACK_3); /* index := (1+ index) */
      if (interactive)
        no_hang = true;
    }
    VALUES1(STACK_3); /* return index */
    skipSTACK(6);
  }
}

LISPFUN(write_byte_sequence,seclass_default,2,0,norest,key,4,
        (kw(start),kw(end),kw(no_hang),kw(interactive)) )
{ /* (WRITE-BYTE-SEQUENCE sequence stream [:start] [:end] [:no-hang] [:interactive]),
  2 values: sequence as first value (backward compatible)
   -  second value is the position of first unwritten byte
      (sequence length if everything was written, including :no-hang nil)
    cf. dpANS p. 21-27 */
  /* Stack layout: sequence, stream, start, end, no-hang, interactive. */
  var bool interactive = !missingp(STACK_0);
  var bool no_hang = !missingp(STACK_1);
  skipSTACK(2);
  pushSTACK(get_valid_seq_type(STACK_3)); /* sequence check */
  /* Stack layout: sequence, stream, start, end, typdescr. */
  STACK_3 = check_stream(STACK_3);
  start_default_0(STACK_2); /* default value for start is 0 */
  end_default_len(STACK_1,STACK_4,STACK_0); /* end defaults to length */
  test_start_end(&O(kwpair_start),&STACK_1); /* check start and end */
  if (eq(seq_type(STACK_0),fixnum(8))) {
    /* type = (VECTOR (UNSIGNED-BYTE 8)) ? */
    var uintV start = posfixnum_to_V(STACK_2);
    var uintV end = posfixnum_to_V(STACK_1);
    var uintL index = 0;
    STACK_0 = array_displace_check(STACK_4,end,&index);
    var uintL result =
      write_byte_array(&STACK_3,&STACK_0,index+start,end-start,
                       no_hang ? persev_immediate : interactive
                       ? persev_partial : persev_full);
    skipSTACK(4);
    VALUES2(popSTACK(),fixnum(start+result));
  } else {
    var uintV end = posfixnum_to_V(STACK_1);
    /* subtract start and end: */
    STACK_1 = I_I_minus_I(STACK_1,STACK_2); /* (- end start), an integer >=0 */
    /* Stack layout: sequence, item, start, count, typdescr. */
    /* determine start pointer: */
    pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
    funcall(seq_init_start(STACK_(0+2)),2); /*(SEQ-INIT-START sequence start)*/
    STACK_2 = value1; /* =: pointer */
    /* Stack layout: sequence, stream, pointer, count, typdescr. */
    if (no_hang || interactive) /* FIXME: need write_byte_will_hang_p() */
      error_illegal_streamop(S(write_byte_sequence),STACK_3);
    while (!eq(STACK_1,Fixnum_0)) { /* count (an integer) = 0 -> done */
      pushSTACK(STACK_4); pushSTACK(STACK_(2+1));
      funcall(seq_access(STACK_(0+2)),2); /* (SEQ-ACCESS sequence pointer) */
      write_byte(STACK_3,value1); /* output an element  */
      /* pointer := (SEQ-UPD sequence pointer) : */
      pointer_update(STACK_2,STACK_4,STACK_0);
      /* count := (1- count) : */
      decrement(STACK_1);
    }
    skipSTACK(4);
    VALUES2(popSTACK(),fixnum(end)); /* return sequence */
  }
}
