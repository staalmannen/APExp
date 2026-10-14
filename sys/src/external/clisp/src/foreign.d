/* Foreign language interface for CLISP
 * Marcus Daniels 8.4.1994
 * Bruno Haible 1995-2005
 * Sam Steingold 2000-2009
 */

#include "lispbibl.c"
#include "arilev0.c" /* for mulu32_unchecked */
#undef valid

#ifdef DYNAMIC_FFI

BEGIN_DECLS
#include <avcall.h>        /* Low level support for call-out */
#include <callback.h>      /* Low level support for call-in */
END_DECLS

/* complain about non-foreign object */
nonreturning_function(local, error_foreign_object, (object arg)) {
  pushSTACK(arg); pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: argument is not a foreign object: ~S"));
}

/* foreign address vs foreign pointer
 - foreign pointers are available even when FFI is not
   (used by berkeley-db and new-clx modules)
 - foreign addresses can share the base which enables controlling validity
   of resources (see impnotes.html#ex-dffi-validity)

 Historically, the heavy weight foreign address objects come from Amiga:
 A library entry point is a known (negative) offset towards the library
 base pointer -- much like today's COM objects or vtables. */

/* Allocate a foreign address.
 make_faddress(base,offset)
 > base: base address
 > offset: offset relative to the base address
 < result: Lisp object
 can trigger GC */
modexp maygc object make_faddress (object base, uintP offset)
{
  pushSTACK(base);
  var object result = allocate_faddress();
  TheFaddress(result)->fa_base = popSTACK(); /* base */
  TheFaddress(result)->fa_offset = offset;
  return result;
}

/* return the foreign address of the foreign object
 can trigger GC -- only when allocate_p is TRUE */
local /*maygc*/ object foreign_address (object obj, bool allocate_p)
{
  GCTRIGGER_IF(allocate_p,GCTRIGGER1(obj));
  if (orecordp(obj)) {
    switch (Record_type(obj)) {
      case Rectype_Fpointer:
        if (allocate_p) return make_faddress(obj,0);
        pushSTACK(S(foreign_variable));
        pushSTACK(S(foreign_function));
        pushSTACK(S(foreign_address));
        pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
        error(error_condition,
              GETTEXT("~S: argument ~S should be a ~S, ~S or ~S"));
      case Rectype_Faddress:
        return obj;
      case Rectype_Fvariable:
        return TheFvariable(obj)->fv_address;
      case Rectype_Ffunction:
        return TheFfunction(obj)->ff_address;
    }
  }
  error_foreign_object(obj);
}

/* return the foreign pointer of the foreign object
 or nullobj if the argument is not a foreign object */
local object foreign_pointer (object obj)
{
  if (orecordp(obj)) {
    switch (Record_type(obj)) {
      case Rectype_Fpointer:
        return obj;
      case Rectype_Fvariable:
        obj = TheFvariable(obj)->fv_address;
        goto foreign_address;
      case Rectype_Ffunction:
        obj = TheFfunction(obj)->ff_address;
      case Rectype_Faddress: foreign_address:
        return TheFaddress(obj)->fa_base;
    }
  }
  return nullobj; /* non-foreign object */
}

/* return the foreign pointer of the foreign object
 and signal an error if the argument is not a foreign object */
local object foreign_pointer_strict (object obj)
{
  var object fp = foreign_pointer(obj);
  if (eq(fp,nullobj)) error_foreign_object(obj);
  return fp;
}

/* (FFI:VALIDP foreign-entity) tests whether a foreign entity
 is still valid or refers to an invalid foreign pointer. */
LISPFUNNR(validp,1) {
  var object fp = foreign_pointer(popSTACK());
  VALUES_IF(eq(fp,nullobj) || fp_validp(TheFpointer(fp)));
}
LISPFUNN(set_validp,2)
{ /* (setf (validp f-ent) new-value) */
  var bool new_value = !nullp(popSTACK());
  var object arg = popSTACK();
  var object fp = foreign_pointer(arg);
  if (eq(fp,nullobj)) /* permit new_value=true ? */
    error_foreign_object(arg);
  if (fp_validp(TheFpointer(fp))) {
    if (!new_value) {
      if (eq(fp,O(fp_zero))) {
        pushSTACK(TheSubr(subr_self)->name);
        error(error_condition,GETTEXT("~S: must not invalidate the sole FFI session pointer"));
      }
      mark_fp_invalid(TheFpointer(fp));
    }
  } else if (new_value) {
    pushSTACK(fp); pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: cannot resurrect the zombie ~S"));
  }
  VALUES_IF(new_value);
}

/* FOREIGN-POINTER of this foreign entity */
LISPFUNNR(foreign_pointer,1)
{ VALUES1(foreign_pointer_strict(popSTACK())); }

/* (FFI:SET-FOREIGN-POINTER foreign-entity other-entity)
 returns foreign-entity modified to share pointer-base with other entity */
LISPFUNN(set_foreign_pointer,2)
{
  /* TODO? restart that allows all of (OR (EQL :COPY) FOREIGN-xyz) */
  var object address = check_faddress_valid(foreign_address(STACK_1,false));
  var object new_fp = STACK_0;
  STACK_0 = address;
  /* Stack layout: f-entity f-entity-address. */
  if (eq(new_fp,S(Kcopy))) {
    var object fp = TheFaddress(address)->fa_base;
    new_fp = allocate_fpointer(Fpointer_value(fp));
  } else {
    /* extract other entity's FOREIGN-POINTER */
    new_fp = foreign_pointer_strict(new_fp);
    var sintP offset =
      (uintP)Faddress_value(address) - (uintP)Fpointer_value(new_fp);
    TheFaddress(address)->fa_offset = offset;
  }
  TheFaddress(STACK_0)->fa_base = new_fp;
  VALUES1(STACK_1); skipSTACK(2);
}

/* (FFI:UNSIGNED-FOREIGN-ADDRESS integer)
 makes a FOREIGN-ADDRESS object out of an unsigned integer */
LISPFUNNR(unsigned_foreign_address,1) {
  VALUES1(make_faddress(O(fp_zero),I_to_ulong(popSTACK())));
}

/* (FFI:FOREIGN-ADDRESS-UNSIGNED foreign-address)
 returns the unsigned integer value of the FOREIGN-ADDRESS */
LISPFUNNR(foreign_address_unsigned,1) {
  var object arg = popSTACK();
  /* arg --> address */
  if (fvariablep(arg)) arg = TheFvariable(arg)->fv_address;
  else if (ffunctionp(arg)) arg = TheFfunction(arg)->ff_address;
  /* address --> integer */
  if (faddressp(arg)) value1 = ulong_to_I((uintP)Faddress_value(arg));
  else if (fpointerp(arg)) value1 = ulong_to_I((uintP)Fpointer_value(arg));
  else error_foreign_object(arg);
  mv_count = 1;
}

/* (FFI:FOREIGN-ADDRESS foreign-entity) creates or extracts FOREIGN-ADDRESS
 out of a FOREIGN-* object. Useful with C-POINTER type declaration. */
LISPFUNNR(foreign_address,1)
{ VALUES1(foreign_address(popSTACK(),true)); }


/* Registers a foreign variable.
 register_foreign_variable(address,name,flags,size);
 > address: address of a variable in memory
 > name: its name
 > flags: fv_readonly for read-only variables
 > size: its size in bytes
 can trigger GC */
modexp maygc void register_foreign_variable
(void* address, const char * name_asciz, uintBWL flags, uintL size) {
  var object name = asciz_to_string(name_asciz,O(internal_encoding));
  var object obj = gethash(name,O(foreign_variable_table),false);
  if (!eq(obj,nullobj)) {
    obj = TheFvariable(obj)->fv_address;
    obj = TheFaddress(obj)->fa_base;
    if (fp_validp(TheFpointer(obj))) {
      pushSTACK(name);
      error(error_condition,GETTEXT("Foreign variable ~S already exists"));
    } else {
      /* Variable already existed in a previous Lisp session.
         Update the address, and make it and any of its subvariables valid. */
      TheFpointer(obj)->fp_pointer = address;
      mark_fp_valid(TheFpointer(obj));
    }
  } else {
    pushSTACK(name);
    pushSTACK(make_faddress(allocate_fpointer(address),0));
    obj = allocate_fvariable();
    TheFvariable(obj)->fv_address = popSTACK();
    TheFvariable(obj)->fv_name = name = popSTACK();
    TheFvariable(obj)->fv_size = fixnum(size);
    record_flags_replace(TheFvariable(obj), flags);
    shifthash(O(foreign_variable_table),name,obj,true);
  }
}

/* Registers a foreign function.
 register_foreign_function(address,name,flags);
 > address: address of the function in memory
 > name: its name
 > flags: its language and parameter passing convention
 can trigger GC */
modexp maygc void register_foreign_function
(void* address, const char * name_asciz, uintWL flags) {
  var object name = asciz_to_string(name_asciz,O(internal_encoding));
  var object obj = gethash(name,O(foreign_function_table),false);
  if (!eq(obj,nullobj)) {
    obj = TheFfunction(obj)->ff_address;
    obj = TheFaddress(obj)->fa_base;
    if (fp_validp(TheFpointer(obj))) {
      pushSTACK(name);
      error(error_condition,GETTEXT("Foreign function ~S already exists"));
    } else {
      /* Function already existed in a previous Lisp session.
         Update the address, and make it valid. */
      TheFpointer(obj)->fp_pointer = address;
      mark_fp_valid(TheFpointer(obj));
    }
  } else {
    pushSTACK(name);
    pushSTACK(make_faddress(allocate_fpointer(address),0));
    obj = allocate_ffunction();
    TheFfunction(obj)->ff_address = popSTACK();
    TheFfunction(obj)->ff_name = name = popSTACK();
    TheFfunction(obj)->ff_flags = fixnum(flags);
    shifthash(O(foreign_function_table),name,obj,true);
  }
}

/* determine the integer type that corresponds to the given type */
local object parse_foreign_inttype (uintL size, bool signed_p) {
  switch (size) {
    case 1: return signed_p ? S(sint8) : S(uint8);
    case 2: return signed_p ? S(sint16) : S(uint16);
    case 4: return signed_p ? S(sint32) : S(uint32);
    case 8: return signed_p ? S(sint64) : S(uint64);
  }
  pushSTACK(fixnum(size));
  error(error_condition,GETTEXT("No foreign int type of size ~S"));
}

/* Registers a foreign type.
 register_foreign_type (const char * name_asciz, uintL size, uintL alignment)
 > name_asciz: C type name
 > size : sizeof(name_asciz)
 > alignment : alignof(name_asciz)
 can trigger GC */
modexp maygc void register_foreign_inttype
(const char * name_asciz, uintL size, bool signed_p) {
  object name = asciz_to_string(name_asciz,O(internal_encoding));
  object obj = gethash(name,O(foreign_inttype_table),false);
  object inttype = parse_foreign_inttype(size, signed_p);
  if (!eq(obj,nullobj)) {
    if (!eq(inttype,obj)) {
      pushSTACK(inttype); pushSTACK(obj); pushSTACK(name);
      error(error_condition,GETTEXT("Cannot redefine foreign type ~S from ~S to ~S"));
    }
  } else shifthash(O(foreign_inttype_table),name,inttype,true);
}

LISPFUNNF(parse_foreign_inttype,1) { /* "size_t" --> FFI:UINT64 */
  object inttype = gethash(STACK_0,O(foreign_inttype_table),false);
  if (eq(inttype,nullobj))
    error(error_condition,GETTEXT("No foreign int type named ~S"));
  VALUES1(inttype);
  skipSTACK(1);
}

/* A foreign value descriptor describes an item of foreign data.
 <c-type> ::=
   <simple-c-type>   as described in impnotes.html#dffi
   c-pointer
   c-string
   #(c-struct name options slots constructor <c-type>*)
   #(c-union alternatives <c-type>*)
   #(c-array <c-type> number*)
   #(c-array-max <c-type> number)
   #(c-function <c-type> #({<c-type> flags}*) flags)
   #(c-ptr <c-type>)
   #(c-ptr-null <c-type>)
   #(c-array-ptr <c-type>) */

#define C_STRUCT_SLOTS         3
#define C_STRUCT_CONSTRUCTOR   (C_STRUCT_SLOTS+1)
#define C_STRUCT_C_TYPE_START  (C_STRUCT_CONSTRUCTOR+1)

#define C_UNION_ALT            1
#define C_UNION_C_TYPE_START   (C_UNION_ALT+1)

/* Error message. */
nonreturning_function(local, error_foreign_type, (object fvd)) {
  dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
  pushSTACK(fvd); pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: illegal foreign data type ~S"));
}

/* Error message. */
nonreturning_function(local, error_convert, (object fvd, object obj)) {
  dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
  pushSTACK(fvd); pushSTACK(obj);
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: ~S cannot be converted to the foreign type ~S"));
}

#if !defined(HAVE_LONG_LONG_INT)
/* Error message. */
nonreturning_function(local, error_64bit, (object fvd)) {
  dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
  pushSTACK(fvd); pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: 64 bit integers are not supported on this platform and with this C compiler: ~S"));
}
#endif

/* check that fvd is a valid foreign function type specification
 can trigger GC */
local maygc object check_foreign_function_type (object fvd) {
  while (!(simple_vector_p(fvd)
           && (Svector_length(fvd) == 4)
           && eq(TheSvector(fvd)->data[0],S(c_function))
           && simple_vector_p(TheSvector(fvd)->data[2]))) {
    dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
    pushSTACK(NIL);                  /* no PLACE */
    pushSTACK(fvd); pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: illegal foreign function type ~S"));
    fvd = value1;
  }
  return fvd;
}

/* Comparison of two fvd's.
 According to the ANSI C rules, two "c-struct"s are only equivalent if they
 come from the same declaration. Same for "c-union"s.
 "c-array"s, "c-ptr", "c-ptr-null" are compared recursively. Same for
 "c-function". */
local bool equal_fvd (object fvd1, object fvd2);
/* As an exception to strict type and prototype checking,
 C-POINTER matches any C-PTR, C-PTR-NULL, C-ARRAY-PTR and C-FUNCTION type. */
local bool equalp_fvd (object fvd1, object fvd2);
/* Comparison of two argument type vectors. */
local bool equal_argfvds (object argfvds1, object argfvds2);

local bool equal_fvd (object fvd1, object fvd2)
{
  check_SP();
 recurse:
  if (eq(fvd1,fvd2))
    return true;
  if (simple_vector_p(fvd1) && simple_vector_p(fvd2))
    if (Svector_length(fvd1) == Svector_length(fvd2)) {
      var uintL len = Svector_length(fvd1);
      if (len > 0) {
        if (eq(TheSvector(fvd1)->data[0],TheSvector(fvd2)->data[0])) {
          var object obj;
          obj = TheSvector(fvd1)->data[0];
          if ((len >= 2) && (eq(obj,S(c_array)) || eq(obj,S(c_array_max))
                             || eq(obj,S(c_ptr)) || eq(obj,S(c_ptr_null))
                             || eq(obj,S(c_pointer))
                             || eq(obj,S(c_array_ptr)))) {
            var uintL i;
            for (i = 2; i < len; i++)
              if (!eql(TheSvector(fvd1)->data[i],TheSvector(fvd2)->data[i]))
                return false;
            fvd1 = TheSvector(fvd1)->data[1];
            fvd2 = TheSvector(fvd2)->data[1];
            goto recurse;
          } else if ((len == 4) && eq(obj,S(c_function))) {
            if (!equal_fvd(TheSvector(fvd1)->data[1],
                           TheSvector(fvd2)->data[1]))
              return false;
            if (!equal_argfvds(TheSvector(fvd1)->data[2],
                               TheSvector(fvd2)->data[2]))
              return false;
            if (!eql(TheSvector(fvd1)->data[3],TheSvector(fvd2)->data[3]))
              return false;
            return true;
          }
        }
      }
    }
  return false;
}

local bool equal_argfvds (object argfvds1, object argfvds2)
{
  ASSERT(simple_vector_p(argfvds1) && simple_vector_p(argfvds2));
  var uintL len = Svector_length(argfvds1);
  if (!(len == Svector_length(argfvds2)))
    return false;
  while (len > 0) {
    len--;
    if (!equal_fvd(TheSvector(argfvds1)->data[len],
                   TheSvector(argfvds2)->data[len]))
      return false;
  }
  return true;
}

local bool equalp_fvd (object fvd1, object fvd2)
{
  if (eq(fvd1,fvd2))
    return true;
  if (eq(fvd1,S(c_pointer))
      && simple_vector_p(fvd2) && (Svector_length(fvd2) > 0)) {
    var object fvd2type = TheSvector(fvd2)->data[0];
    if (eq(fvd2type,S(c_ptr)) || eq(fvd2type,S(c_ptr_null))
        || eq(fvd2type,S(c_pointer)) || eq(fvd2type,S(c_array_ptr))
        || eq(fvd2type,S(c_function)))
      return true;
  }
  if (eq(fvd2,S(c_pointer))
      && simple_vector_p(fvd1) && (Svector_length(fvd1) > 0)) {
    var object fvd1type = TheSvector(fvd1)->data[0];
    if (eq(fvd1type,S(c_ptr)) || eq(fvd1type,S(c_ptr_null))
        || eq(fvd1type,S(c_pointer)) || eq(fvd1type,S(c_array_ptr))
        || eq(fvd1type,S(c_function)))
      return true;
  }
  return equal_fvd(fvd1,fvd2);
}


/* When a Lisp function is converted to a C function, it has to be stored in
 a table of call-back functions. (Because we can't give away pointers to
 Lisp objects for GC reasons.)
 There is a two-way correspondence:

                   hash table, alist
    Lisp function ------------------> index       array
    Lisp function <------------------ index -----------------> trampoline
                        array               <-----------------
                                             trampoline_data()

 The index also has a reference count attached, in order to not generate
 several trampolines for different conversions of the same Lisp function.

 O(foreign_callin_table) is a hash table.
 O(foreign_callin_vector) is an extendable vector of size 3*n+1, of triples
 #(... lisp-function foreign-function reference-count ...).
       3*index-2     3*index-1        3*index
 (The foreign-function itself contains the trampoline address.)
 Free triples are linked together to a free list like this:
 #(... nil           nil              next-index      ...)
       3*index-2     3*index-1        3*index */

local void callback (void* data, va_alist args);

/* check whether the given Ffunction matches the given calling convention */
local void check_cc_match (object fun, object resulttype,
                           object argtypes, object flags) {
  if (!(equal_fvd(resulttype,TheFfunction(fun)->ff_resulttype)
        && equal_argfvds(argtypes,TheFfunction(fun)->ff_argtypes)
        && eq(flags,TheFfunction(fun)->ff_flags))) {
    pushSTACK(fun);
    error(error_condition,GETTEXT("~S cannot be converted to a foreign function with another calling convention."));
  }
}

/* Convert a Lisp function to a C function.
 convert_function_to_foreign(address,resulttype,argtypes,flags)
 The real C function address is
   Faddress_value(TheFfunction(result)->ff_address).
 can trigger GC */
local maygc object convert_function_to_foreign (object fun, object resulttype,
                                                object argtypes, object flags) {
  /* Convert to a function: */
  if (!functionp(fun)) {
    pushSTACK(resulttype); pushSTACK(argtypes); pushSTACK(flags);
    with_saved_back_trace_subr(L(coerce),STACK STACKop -2,-1,
      { fun = coerce_function(fun); });
    flags = popSTACK(); argtypes = popSTACK(); resulttype = popSTACK();
  }
  /* If it is already a foreign function, return it immediately: */
  if (ffunctionp(fun)) {
    check_cc_match(fun, resulttype, argtypes, flags);
    return fun;
  }
  { /* Look it up in the hash table, alist: */
    var object alist = gethash(fun,O(foreign_callin_table),false);
    if (!eq(alist,nullobj)) {
      while (consp(alist)) {
        var object acons = Car(alist);
        alist = Cdr(alist);
        if (equal_fvd(resulttype,Car(acons))
            && equal_argfvds(argtypes,Car(Cdr(acons)))
            && eq(flags,Car(Cdr(Cdr(acons))))) {
          var uintV f_index = posfixnum_to_V(Cdr(Cdr(Cdr(acons))));
          var gcv_object_t* triple = &TheSvector(TheIarray(O(foreign_callin_vector))->data)->data[3*f_index-2];
          var object ffun = triple[1];
          ASSERT(equal_fvd(resulttype,TheFfunction(ffun)->ff_resulttype));
          ASSERT(equal_argfvds(argtypes,TheFfunction(ffun)->ff_argtypes));
          ASSERT(eq(flags,TheFfunction(ffun)->ff_flags));
          var object faddress = TheFfunction(ffun)->ff_address;
          if (fp_validp(TheFpointer(TheFaddress(faddress)->fa_base))) {
            triple[2] = fixnum_inc(triple[2],1); /* increment reference count */
          } else {     /* callback from a previous session -- renew */
            triple[2] = Fixnum_1; /* reset reference count */
            begin_system_call();
            TheFaddress(faddress)->fa_offset =
              (uintP)alloc_callback(&callback,(void*)(uintP)f_index);
            end_system_call();
            TheFaddress(faddress)->fa_base = O(fp_zero);
          }
          return ffun;
        }
      }
    }
  }
  /* Not already in the hash table -> allocate new: */
  pushSTACK(fun);
  pushSTACK(NIL);
  pushSTACK(resulttype);
  pushSTACK(argtypes);
  pushSTACK(flags);
  { /* First grab an index. */
    var uintV f_index = posfixnum_to_V(TheSvector(TheIarray(O(foreign_callin_vector))->data)->data[0]);
    if (f_index != 0) { /* remove first index from the free list */
      var object dv = TheIarray(O(foreign_callin_vector))->data;
      TheSvector(dv)->data[0] = TheSvector(dv)->data[3*f_index];
    } else { /* free list exhausted */
      var uintC i = 3;
      while (i--) {
        pushSTACK(NIL); pushSTACK(O(foreign_callin_vector));
        funcall(L(vector_push_extend),2);
      }
      f_index = floor(vector_length(O(foreign_callin_vector)),3);
    }
    { /* Next allocate the trampoline. */
      begin_system_call();
      var void* trampoline =
        (void*)alloc_callback(&callback,(void*)(uintP)f_index);
      end_system_call();
      pushSTACK(make_faddress(O(fp_zero),(uintP)trampoline));
      /* Now allocate the foreign-function. */
      var object obj = allocate_ffunction();
      TheFfunction(obj)->ff_name = NIL;
      TheFfunction(obj)->ff_address = popSTACK();
      TheFfunction(obj)->ff_resulttype = STACK_2;
      TheFfunction(obj)->ff_argtypes = STACK_1;
      TheFfunction(obj)->ff_flags = STACK_0;
      STACK_3 = obj;
    }
    pushSTACK(fixnum(f_index)); funcall(L(liststar),4); pushSTACK(value1);
    /* Stack layout: fun, obj, acons. */
    { /* Put it into the hash table. */
      var object new_cons = allocate_cons();
      Car(new_cons) = popSTACK();
      var object alist = gethash(STACK_1,O(foreign_callin_table),false);
      if (eq(alist,nullobj))
        alist = NIL;
      Cdr(new_cons) = alist;
      shifthash(O(foreign_callin_table),STACK_1,new_cons,true);
    }
    /* Put it into the vector. */
    var gcv_object_t* triple = &TheSvector(TheIarray(O(foreign_callin_vector))->data)->data[3*f_index-2];
    triple[1] = popSTACK(); /* obj */
    triple[0] = popSTACK(); /* fun */
    triple[2] = Fixnum_1; /* refcount := 1 */
    return triple[1];
  }
}

/* Undoes the allocation effect of convert_function_to_foreign(). */
local void free_foreign_callin (void* address)
{
  begin_system_call();
  if (is_callback(address) /* safety check */
      && (callback_address(address) == &callback)) {
    var uintL cb_data = (uintL)(uintP)callback_data(address);
    end_system_call();
    var object dv = TheIarray(O(foreign_callin_vector))->data;
    var gcv_object_t* triple = &TheSvector(dv)->data[3*cb_data-2];
    if (!nullp(triple[1])) { /* safety check */
      triple[2] = fixnum_inc(triple[2],-1); /* decrement reference count */
      if (eq(triple[2],Fixnum_0)) {
        var object fun = triple[0];
        var object ffun = triple[1];
        /* clear vector entry, put index=cb_data onto free list: */
        triple[0] = NIL; triple[1] = NIL;
        triple[2] = TheSvector(dv)->data[0];
        TheSvector(dv)->data[0] = fixnum(cb_data);
        { /* remove from hash table entry: */
          var object alist = gethash(fun,O(foreign_callin_table),false);
          if (!eq(alist,nullobj)) { /* safety check */
            /* see list.d:deleteq() */
            var object alist1 = alist;
            var object alist2 = alist;
            while (consp(alist2)) {
              if (eq(Cdr(Cdr(Cdr(Car(alist2)))),fixnum(cb_data))) {
                if (eq(alist2,alist)) {
                  alist2 = alist1 = Cdr(alist2);
                  shifthash(O(foreign_callin_table),fun,alist2,false);
                } else
                  Cdr(alist1) = alist2 = Cdr(alist2);
              } else {
                alist1 = alist2; alist2 = Cdr(alist2);
              }
            }
          }
        }
        var object faddress = TheFfunction(ffun)->ff_address;
        if (fp_validp(TheFpointer(TheFaddress(faddress)->fa_base))) {
          /* free the trampoline: */
          begin_system_call();
          free_callback((__TR_function)Faddress_value(faddress));
          end_system_call();
        }
      }
    }
  } else {
    end_system_call();
  }
}

/* Convert a C function to a Lisp foreign function.
 convert_function_from_foreign(address,resulttype,argtypes,flags) */
local object convert_function_from_foreign (void* address, object resulttype,
                                            object argtypes, object flags) {
  begin_system_call();
  if (is_callback(address) /* safety check */
      && (callback_address(address) == &callback)) {
    var uintL cb_data = (uintL)(uintP)callback_data(address);
    end_system_call();
    var gcv_object_t* triple = &TheSvector(TheIarray(O(foreign_callin_vector))->data)->data[3*cb_data-2];
    var object ffun = triple[1];
    check_cc_match(ffun,resulttype,argtypes,flags);
    return ffun;
  } else {
    end_system_call();
  }
  pushSTACK(argtypes);
  pushSTACK(resulttype);
  pushSTACK(make_faddress(O(fp_zero),(uintP)address));
  var object obj = allocate_ffunction();
  TheFfunction(obj)->ff_name = NIL;
  TheFfunction(obj)->ff_address = popSTACK();
  TheFfunction(obj)->ff_resulttype = popSTACK();
  TheFfunction(obj)->ff_argtypes = popSTACK();
  TheFfunction(obj)->ff_flags = flags;
  return obj;
}

/* ensure that the Faddress is valid
 < fa: foreign address
 can trigger GC */
local inline maygc object validate_fpointer (object obj);
global maygc object check_faddress_valid (object fa) {
  object fp = TheFaddress(fa)->fa_base;
  if (!fp_validp(TheFpointer(fp))) {
    pushSTACK(fa);              /* save */
    check_fpointer(validate_fpointer(fp),false);
    fa = popSTACK();            /* restore */
  }
  return fa;
}

/* (FFI:FOREIGN-FUNCTION address c-type &key name) constructor */
LISPFUN(foreign_function,seclass_read,2,0,norest,key,1,(kw(name)) )
{
  STACK_1 = check_foreign_function_type(STACK_1);
 foreign_function_restart:
  var object fa = STACK_2;
  if (ffunctionp(fa)) {
    if (missingp(STACK_0))
      STACK_0 = TheFfunction(fa)->ff_name;
    fa = TheFfunction(fa)->ff_address;
  }
  /* If you believe objects of type foreign-variable should be accepted,
   * then you probably missed an indirection. */
  if (!faddressp(fa)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(fa);              /* TYPE-ERROR slot DATUM */
    pushSTACK(O(type_foreign_function)); /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(STACK_0); pushSTACK(fa);
    pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not of type ~S"));
    STACK_2 = value1;
    goto foreign_function_restart;
  }
  fa = check_faddress_valid(fa);
  var object fvd = STACK_1;
  var object ff = convert_function_from_foreign(Faddress_value(fa),
                                                TheSvector(fvd)->data[1],
                                                TheSvector(fvd)->data[2],
                                                TheSvector(fvd)->data[3]);
  /* TODO need to visit callback interaction */
  if (nullp(TheFfunction(ff)->ff_name) && !missingp(STACK_0)) {
    pushSTACK(ff);
    STACK_1 = coerce_ss(STACK_1);
    ff = popSTACK();
    TheFfunction(ff)->ff_name = STACK_0;
  }
  VALUES1(ff); skipSTACK(3);
}


#if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
  /* use long long type with ffcall when possible, otherwise pass
     64-bit integers as structs.  Note that long long is incompatible
     with struct passing/returning with gcc/i386/Linux, whereas struct
     passing was tested compatible with MSVC6' __int64 type. */
  #if BIG_ENDIAN_P
    typedef struct { uint32 hi; uint32 lo; } struct_uint64;
    typedef struct { sint32 hi; uint32 lo; } struct_sint64;
  #else
    typedef struct { uint32 lo; uint32 hi; } struct_uint64;
    typedef struct { uint32 lo; sint32 hi; } struct_sint64;
  #endif
#else
  #define struct_uint64  uint64
  #define struct_sint64  sint64
#endif

/* Size, Alignment, Splittable -- layout of the foreign data */
struct foreign_layout {
  uintL size;                   /* size (in bytes) of the type */
  uintL alignment;              /* alignment (in bytes) of the type */
  bool splittable; /* splittable flag, if a struct/union/array type */
};


/* Compute the size and alignment of foreign data.
 foreign_layout(fvd, struct foreign_layout *data);
 > fvd: foreign value descriptor
 < data: foreign layout */
local void foreign_layout (object fvd, struct foreign_layout *data);
/* `struct_alignment' is what gcc calls STRUCTURE_SIZE_BOUNDARY/8.
 It is = 1 on most machines, but = 2 on MC680X0 and = 4 on ARM. */
#ifdef __cplusplus
struct trivial_struct { char slot1; };
static const uintL struct_alignment = sizeof(struct trivial_struct);
#else
#define struct_alignment  sizeof(struct { char slot1; })
#endif
local void foreign_layout (object fvd, struct foreign_layout *data)
{
  check_SP();
  if (symbolp(fvd)) {
    if (eq(fvd,S(nil))) {
      data->size = 0; data->alignment = 1;
      data->splittable = true; return;
    } else if (eq(fvd,S(boolean))) {
      data->size = sizeof(int); data->alignment = alignof(int);
      data->splittable = true; return;
    } else if (eq(fvd,S(character))) {
      data->size = sizeof(unsigned char);
      data->alignment = alignof(unsigned char);
      data->splittable = true; return;
    } else if (eq(fvd,S(char)) || eq(fvd,S(sint8))) {
      data->size = sizeof(sint8); data->alignment = alignof(sint8);
      data->splittable = true; return;
    } else if (eq(fvd,S(uchar)) || eq(fvd,S(uint8))) {
      data->size = sizeof(uint8); data->alignment = alignof(uint8);
      data->splittable = true; return;
    } else if (eq(fvd,S(short)) || eq(fvd,S(sint16))) {
      data->size = sizeof(sint16); data->alignment = alignof(sint16);
      data->splittable = true; return;
    } else if (eq(fvd,S(ushort)) || eq(fvd,S(uint16))) {
      data->size = sizeof(uint16); data->alignment = alignof(uint16);
      data->splittable = true; return;
    } else if (eq(fvd,S(sint32))) {
      data->size = sizeof(sint32); data->alignment = alignof(sint32);
      data->splittable = true; return;
    } else if (eq(fvd,S(uint32))) {
      data->size = sizeof(uint32); data->alignment = alignof(uint32);
      data->splittable = true; return;
    } else if (eq(fvd,S(sint64))) {
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      data->size = sizeof(struct_sint64);
      data->alignment = alignof(struct_sint64);
      data->splittable = av_word_splittable_2(sint32,sint32); /* always true */
     #else
      data->size = sizeof(sint64); data->alignment = alignof(sint64);
      data->splittable = av_word_splittable_1(sint64); /* always true */
     #endif
      return;
    } else if (eq(fvd,S(uint64))) {
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      data->size = sizeof(struct_uint64);
      data->alignment = alignof(struct_uint64);
      data->splittable = av_word_splittable_2(uint32,uint32); /* always true */
     #else
      data->size = sizeof(uint64); data->alignment = alignof(uint64);
      data->splittable = av_word_splittable_1(uint64); /* always true */
     #endif
      return;
    } else if (eq(fvd,S(int))) {
      data->size = sizeof(int); data->alignment = alignof(int);
      data->splittable = true; return;
    } else if (eq(fvd,S(uint))) {
      data->size = sizeof(unsigned int);
      data->alignment = alignof(unsigned int);
      data->splittable = true; return;
    } else if (eq(fvd,S(long))) {
      data->size = sizeof(long); data->alignment = alignof(long);
      data->splittable = true; return;
    } else if (eq(fvd,S(ulong))) {
      data->size = sizeof(unsigned long);
      data->alignment = alignof(unsigned long);
      data->splittable = true; return;
    } else if (eq(fvd,S(single_float))) {
      data->size = sizeof(float); data->alignment = alignof(float);
      data->splittable = (sizeof(float) <= sizeof(long)); return;
    } else if (eq(fvd,S(double_float))) {
      data->size = sizeof(double); data->alignment = alignof(double);
      data->splittable = (sizeof(double) <= sizeof(long)); return;
    } else if (eq(fvd,S(c_pointer))) {
      data->size = sizeof(void*); data->alignment = alignof(void*);
      data->splittable = true; return;
    } else if (eq(fvd,S(c_string))) {
      data->size = sizeof(char*); data->alignment = alignof(char*);
      data->splittable = true; return;
    }
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        var uintL cumul_size = 0;
        var uintL cumul_alignment = struct_alignment;
        var bool cumul_splittable = true;
        var uintL i;
        for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
          foreign_layout(TheSvector(fvd)->data[i],data);
          /* We assume all alignments are of the form 2^k. */
          cumul_size += (-cumul_size) & (data->alignment-1);
          /* cumul_splittable = cumul_splittable AND
               (cumul_size..cumul_size+data->size-1) fits in a word; */
          if (floor(cumul_size,sizeof(long)) <
              floor(cumul_size+data->size-1,sizeof(long)))
            cumul_splittable = false;
          cumul_size += data->size;
          /* cumul_alignment = lcm(cumul_alignment,data->alignment); */
          if (data->alignment > cumul_alignment)
            cumul_alignment = data->alignment;
        }
        cumul_size += (-cumul_size) & (cumul_alignment-1);
        data->size = cumul_size; data->alignment = cumul_alignment;
        data->splittable = cumul_splittable;
        return;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        var uintL cumul_size = 0;
        var uintL cumul_alignment = struct_alignment;
        var bool cumul_splittable = false;
        var uintL i;
        for (i = 2; i < fvdlen; i++) {
          foreign_layout(TheSvector(fvd)->data[i],data);
          /* We assume all alignments are of the form 2^k.
             cumul_size = max(cumul_size,data->size); */
          if (data->size > cumul_size)
            cumul_size = data->size;
          /* cumul_alignment = lcm(cumul_alignment,data->alignment); */
          if (data->alignment > cumul_alignment)
            cumul_alignment = data->alignment;
          /* cumul_splittable = cumul_splittable OR data->splittable; */
          if (data->splittable)
            cumul_splittable = true;
        }
        data->size = cumul_size; data->alignment = cumul_alignment;
        data->splittable = cumul_splittable;
        return;
      } else if ((eq(fvdtype,S(c_array)) && (fvdlen > 1))
                 || (eq(fvdtype,S(c_array_max)) && (fvdlen == 3))) {
        var uintL i;
        foreign_layout(TheSvector(fvd)->data[1],data);
        for (i = 2; i < fvdlen; i++) {
          var object dim = TheSvector(fvd)->data[i];
          if (!uint32_p(dim))
            error_foreign_type(fvd);
          data->size = data->size * I_to_uint32(dim);
        }
        data->splittable = (data->size <= sizeof(long));
        return;
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        data->size = sizeof(void*); data->alignment = alignof(void*);
        data->splittable = true; return;
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null))
                  || eq(fvdtype,S(c_pointer)) || eq(fvdtype,S(c_array_ptr)))
                 && (fvdlen == 2)) {
        data->size = sizeof(void*); data->alignment = alignof(void*);
        data->splittable = true; return;
      }
    }
  } else {
    object inttype = gethash(fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj)) {
      foreign_layout(inttype,data);
      return;
    }
  }
  error_foreign_type(fvd);
}

/* compute the size of the foreign data
 < fvd:  foreign value descriptor
 > size: the size of the foreign data */
local inline uintL foreign_size (object fvd) {
  var struct foreign_layout sas;
  foreign_layout(fvd,&sas);
  return sas.size;
}

LISPFUNN(sizeof,1)
{ /* (FFI::%SIZEOF c-type) returns the size and alignment of a C type,
 measured in bytes. */
  var object fvd = popSTACK();
  var struct foreign_layout sas;
  foreign_layout(fvd,&sas);
  VALUES2(UL_to_I(sas.size),fixnum(sas.alignment));
}

LISPFUNN(bitsizeof,1)
{ /* (FFI::%BITSIZEOF c-type) returns the size and alignment of a C type,
 measured in bits. */
  var object fvd = popSTACK();
  var struct foreign_layout sas;
  foreign_layout(fvd,&sas);
  VALUES2(UL_to_I(8*sas.size),fixnum(8*sas.alignment));
}

/* Zero a block of memory. */
local void blockzero (void* ptr, unsigned long size)
{
  if (size > 0) {
    if ((size % sizeof(long)) || ((uintP)ptr % sizeof(long))) {
      var char* p = (char*)ptr;
      do { *p++ = 0;
      } while (--size > 0);
    } else {
      var long* p = (long*)ptr;
      do { *p++ = 0;
      } while ((size -= sizeof(long)) > 0);
    }
  }
}

/* Test a block of memory for zero. */
local bool blockzerop (const void* ptr, unsigned long size)
{
  if ((size % sizeof(long)) || ((uintP)ptr % sizeof(long))) {
    var const char* p = (const char*)ptr;
    do { if (*p++ != 0) return false;
    } while (--size > 0);
    return true;
  } else {
    var const long* p = (const long*)ptr;
    do { if (*p++ != 0) return false;
    } while ((size -= sizeof(long)) > 0);
    return true;
  }
}

/* Convert foreign data to Lisp data.
 can trigger GC */
global maygc object convert_from_foreign (object fvd, const void* data);
/* Allocate an array corresponding to a foreign array.
 can trigger GC */
local maygc object convert_from_foreign_array_alloc (object dims, object eltype)
{
  var uintL argcount = 1;
  pushSTACK(dims);
  if (symbolp(eltype)) {
    if (eq(eltype,S(character))) {
      pushSTACK(S(Kelement_type)); pushSTACK(S(character));
      argcount += 2;
    } else if (eq(eltype,S(uint8))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_uint8));
      argcount += 2;
    }
   #if 0
    else if (eq(eltype,S(sint8))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_sint8));
      argcount += 2;
    }
   #endif
    else if (eq(eltype,S(uint16))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_uint16));
      argcount += 2;
    }
   #if 0
    else if (eq(eltype,S(sint16))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_sint16));
      argcount += 2;
    }
   #endif
    else if (eq(eltype,S(uint32))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_uint32));
      argcount += 2;
    }
   #if 0
    else if (eq(eltype,S(sint32))) {
      pushSTACK(S(Kelement_type)); pushSTACK(O(type_sint32));
      argcount += 2;
    }
   #endif
  }
  funcall(L(make_array),argcount);
  return value1;
}
/* Fill a specialized Lisp array with foreign data.
 Return the (possibly reallocated) array. */
local object convert_from_foreign_array_fill (object eltype, uintL size,
                                              object array, const void* data)
{
  if (eq(eltype,S(character))) {
    if (size > 0) {
      var const uintB* ptr1 = (const uintB*)data;
     #ifdef ENABLE_UNICODE
      pushSTACK(array);
      var object encoding = O(foreign_8bit_encoding);
      ASSERT(Encoding_mblen(encoding)(encoding,ptr1,ptr1+size) == size);
      var DYNAMIC_ARRAY(tmpbuf,chart,size);
      var chart* ptr2 = &tmpbuf[0];
      Encoding_mbstowcs(encoding)(encoding,nullobj,&ptr1,ptr1+size,&ptr2,
                                  ptr2+size);
      ASSERT(ptr1 == (const uintB*)data+size);
      sstring_store_array(array,0,&tmpbuf[0],size);
      FREE_DYNAMIC_ARRAY(tmpbuf);
      array = popSTACK();
      sstring_un_realloc(array);
     #else
      var chart* ptr2 = &TheSnstring(array)->data[0];
      do { *ptr2++ = as_chart(*ptr1++); } while(--size);
     #endif
    }
  } else if (eq(eltype,S(uint8))) {
    if (size > 0) {
      var const uint8* ptr1 = (const uint8*)data;
      var uint8* ptr2 = (uint8*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #if 0
  else if (eq(eltype,S(sint8))) {
    if (size > 0) {
      var const sint8* ptr1 = (const sint8*)data;
      var sint8* ptr2 = (sint8*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #endif
  else if (eq(eltype,S(uint16))) {
    if (size > 0) {
      var const uint16* ptr1 = (const uint16*)data;
      var uint16* ptr2 = (uint16*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #if 0
  else if (eq(eltype,S(sint16))) {
    if (size > 0) {
      var const sint16* ptr1 = (const sint16*)data;
      var sint16* ptr2 = (sint16*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #endif
  else if (eq(eltype,S(uint32))) {
    if (size > 0) {
      var const uint32* ptr1 = (const uint32*)data;
      var uint32* ptr2 = (uint32*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #if 0
  else if (eq(eltype,S(sint32))) {
    if (size > 0) {
      var const sint32* ptr1 = (const sint32*)data;
      var sint32* ptr2 = (sint32*)&TheSbvector(array)->data[0];
      do { *ptr2++ = *ptr1++; } while(--size);
    }
  }
 #endif
  else
    NOTREACHED;
  return array;
}
/* Error message */
nonreturning_function (local, error_eltype_zero_size, (object fvd)) {
  pushSTACK(fvd);
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: element type has size 0: ~S"));
}
modexp maygc object convert_from_foreign (object fvd, const void* data)
{ /* keep in sync with foreign1.lisp:convert-from-foreign */
  check_SP();
  check_STACK();
  if (NULL == data) {
    pushSTACK(fvd); pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: trying to read an object of type ~S from NULL address"));
  }
  if (symbolp(fvd)) {
    if (eq(fvd,S(nil)))
     /* If we are presented the empty type, we take it as "ignore"
         and return NIL. */
      return NIL;
    else if (eq(fvd,S(boolean))) {
      var const int* pdata = (const int*)data;
      return (*pdata ? T : NIL);
    } else if (eq(fvd,S(character))) {
      var const uintB* pdata = (const unsigned char *)data;
      var chart ch;
     #ifdef ENABLE_UNICODE
      var object encoding = O(foreign_8bit_encoding);
      var chart chbuf[1];
      var const uintB* ptr1 = pdata;
      var chart* ptr2 = &chbuf[0];
      Encoding_mbstowcs(encoding)(encoding,nullobj,&ptr1,ptr1+1,&ptr2,ptr2+1);
      ASSERT(ptr2 == &chbuf[1]);
      ch = chbuf[0];
     #else
      ch = as_chart(*pdata);
     #endif
      return code_char(ch);
    } else if (eq(fvd,S(char)) || eq(fvd,S(sint8))) {
      var const sint8* pdata = (const sint8*)data;
      return sint8_to_I(*pdata);
    } else if (eq(fvd,S(uchar)) || eq(fvd,S(uint8))) {
      var const uint8* pdata = (const uint8*)data;
      return uint8_to_I(*pdata);
    } else if (eq(fvd,S(short)) || eq(fvd,S(sint16))) {
      var const sint16* pdata = (const sint16*)data;
      return sint16_to_I(*pdata);
    } else if (eq(fvd,S(ushort)) || eq(fvd,S(uint16))) {
      var const uint16* pdata = (const uint16*)data;
      return uint16_to_I(*pdata);
    } else if (eq(fvd,S(sint32))) {
      var const sint32* pdata = (const sint32*)data;
      return sint32_to_I(*pdata);
    } else if (eq(fvd,S(uint32))) {
      var const uint32* pdata = (const uint32*)data;
      return uint32_to_I(*pdata);
    } else if (eq(fvd,S(sint64))) {
      var const struct_sint64* pdata = (const struct_sint64*)data;
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      return L2_to_I(pdata->hi,pdata->lo);
     #else
      return sint64_to_I(*pdata);
     #endif
    } else if (eq(fvd,S(uint64))) {
      var const struct_uint64* pdata = (const struct_uint64*)data;
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      return UL2_to_I(pdata->hi,pdata->lo);
     #else
      return uint64_to_I(*pdata);
     #endif
    } else if (eq(fvd,S(int))) {
      var const int* pdata = (const int*)data;
      return sint_to_I(*pdata);
    } else if (eq(fvd,S(uint))) {
      var const unsigned int * pdata = (const unsigned int *)data;
      return uint_to_I(*pdata);
    } else if (eq(fvd,S(long))) {
      var const long* pdata = (const long*)data;
      return slong_to_I(*pdata);
    } else if (eq(fvd,S(ulong))) {
      var const unsigned long * pdata = (const unsigned long *)data;
      return ulong_to_I(*pdata);
    } else if (eq(fvd,S(single_float))) {
      var const ffloatjanus* pdata = (const ffloatjanus*) data;
      return c_float_to_FF(pdata);
    } else if (eq(fvd,S(double_float))) {
      var const dfloatjanus* pdata = (const dfloatjanus*) data;
      return c_double_to_DF(pdata);
    } else if (eq(fvd,S(c_pointer))) {
      var const uintP address = (uintP)(*(void* const *) data);
      return address==0 ? NIL : make_faddress(O(fp_zero),address);
    } else if (eq(fvd,S(c_string))) {
      var const char * asciz = *(const char * const *) data;
      return asciz==NULL ? NIL : asciz_to_string(asciz,O(foreign_encoding));
    }
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        pushSTACK(fvd);
        {
          var gcv_object_t* fvd_ = &STACK_0;
          var uintL cumul_size = 0;
          var uintL cumul_alignment = struct_alignment;
          var uintL i;
          for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
            var object fvdi = TheSvector(*fvd_)->data[i];
            var struct foreign_layout sas;
            foreign_layout(fvdi,&sas);
            /* We assume all alignments are of the form 2^k. */
            cumul_size += (-cumul_size) & (sas.alignment-1);
            var const void* pdata = (const char*)data + cumul_size;
            cumul_size += sas.size;
            /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
            if (sas.alignment > cumul_alignment)
              cumul_alignment = sas.alignment;
            /* Now we are finished with sas.size and sas.alignment.
               Convert the structure slot: */
            fvdi = convert_from_foreign(fvdi,pdata);
            pushSTACK(fvdi);
          }
          /* Call the constructor. */
          funcall(TheSvector(*fvd_)->data[C_STRUCT_CONSTRUCTOR],
                  fvdlen-C_STRUCT_C_TYPE_START);
        }
        skipSTACK(1);
        return value1;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        /* Use the union's first component. */
        return convert_from_foreign(fvdlen > 2 ? (object)TheSvector(fvd)->data[2] : NIL, data);
      } else if (eq(fvdtype,S(c_array)) && (fvdlen > 1)) {
        if (fvdlen == 3 && eq(TheSvector(fvd)->data[1],S(character))) {
          /* 1-dimensional array of CHARACTER. */
          var uintL dim1 = I_to_UL(TheSvector(fvd)->data[2]);
         #ifdef ENABLE_UNICODE
          var object encoding = O(foreign_encoding);
          var uintL clen =
            Encoding_mblen(encoding)(encoding,
                                     (const uintB*)data,(const uintB*)data+dim1);
         #else
          var uintL clen = dim1;
         #endif
          check_stringsize(clen);
          var object string = allocate_string(clen);
          if (clen > 0) {
            var chart* cptr = &TheSnstring(string)->data[0];
            var const uintB* bptr = (const uintB*)data;
           #ifdef ENABLE_UNICODE
            var const uintB* bendptr = bptr+dim1;
            encoding = O(foreign_encoding);
            var chart* cendptr = cptr+clen;
            Encoding_mbstowcs(encoding)(encoding,nullobj,&bptr,bendptr,&cptr,cendptr);
            ASSERT(cptr == cendptr);
           #else
            do { *cptr++ = as_chart(*bptr++); } while(--clen);
           #endif
          }
          return string;
        }
        pushSTACK(fvd);
        /* Allocate the resulting array: (MAKE-ARRAY dims :element-type ...) */
        var object dims = Cdr(Cdr((coerce_sequence(fvd,S(list),true),value1)));
        var object array = convert_from_foreign_array_alloc(dims,TheSvector(STACK_0)->data[1]);
        /* Fill the resulting array.
           Only a single loop is needed since C and Lisp both store the
           elements in row-major order. */
        {
          var object eltype = TheSvector(STACK_0)->data[1];
          var uintL eltype_size = foreign_size(eltype);
          STACK_0 = eltype;
          var uintL size = array_total_size(array);
          pushSTACK(array);
          if (!vectorp(array))
            array = TheIarray(array)->data; /* fetch the data vector */
          if (!simple_vector_p(array)) {
            /* Fill specialized array. */
            var object reallocated_array =
              convert_from_foreign_array_fill(eltype,size,array,data);
            array = STACK_0;
            if (vectorp(array))
              STACK_0 = reallocated_array;
            else
              TheIarray(array)->data = reallocated_array;
          } else {
            /* Fill general array.
               SYS::ROW-MAJOR-STORE is equivalent to SETF SVREF here. */
            pushSTACK(array);
            {
              var const char* pdata = (const char*)data;
              var uintL i;
              for (i = 0; i < size; i++, pdata += eltype_size) {
                /* pdata = (const char*)data + i*eltype_size */
                var object el = convert_from_foreign(STACK_2,(const void*)pdata);
                TheSvector(STACK_0)->data[i] = el;
              }
            }
            skipSTACK(1);
          }
          array = popSTACK();
        }
        skipSTACK(1);
        return array;
      } else if (eq(fvdtype,S(c_array_max)) && (fvdlen == 3)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL eltype_size = foreign_size(eltype);
        if (eltype_size == 0) error_eltype_zero_size(fvd);
        /* Determine length of array: */
        var uintL len = 0;
        {
          var uintL maxdim = I_to_UL(TheSvector(fvd)->data[2]);
          var const void* ptr = data;
          while (!((len == maxdim) || blockzerop(ptr,eltype_size))) {
            ptr = (const void*)((uintP)ptr + eltype_size);
            len++;
          }
        }
        if (eq(eltype,S(character))) {
          /* 1-dimensional array of CHARACTER. */
         #ifdef ENABLE_UNICODE
          var object encoding = O(foreign_encoding);
          var uintL clen =
            Encoding_mblen(encoding)(encoding,
                                     (const uintB*)data,(const uintB*)data+len);
         #else
          var uintL clen = len;
         #endif
          check_stringsize(clen);
          var object string = allocate_string(clen);
          if (clen > 0) {
            var chart* cptr = &TheSnstring(string)->data[0];
            var const uintB* bptr = (const uintB*)data;
           #ifdef ENABLE_UNICODE
            var const uintB* bendptr = bptr+len;
            encoding = O(foreign_encoding);
            var chart* cendptr = cptr+clen;
            Encoding_mbstowcs(encoding)(encoding,nullobj,&bptr,bendptr,&cptr,cendptr);
            ASSERT(cptr == cendptr);
           #else
            do { *cptr++ = as_chart(*bptr++); } while(--clen);
           #endif
          }
          return string;
        }
        pushSTACK(eltype);
        /* Allocate the resulting array: */
        var object array = convert_from_foreign_array_alloc(UL_to_I(len),eltype);
        /* Fill the resulting array. */
        if (!simple_vector_p(array)) { /* Fill specialized array. */
          array = convert_from_foreign_array_fill(STACK_0,len,array,data);
        } else { /* Fill general array, using SYS::SVSTORE. */
          pushSTACK(array);
          {
            var const char* pdata = (const char*)data;
            var uintL i;
            for (i = 0; i < len; i++, pdata += eltype_size) {
              /* pdata = (const char*)data + i*eltype_size */
              pushSTACK(STACK_0); /* array */
              pushSTACK(fixnum(i));
              pushSTACK(convert_from_foreign(STACK_(1+2),(const void*)pdata));
              funcall(L(svstore),3);
            }
          }
          array = popSTACK();
        }
        skipSTACK(1);
        return array;
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        if (*(void* const*)data == NULL)
          return NIL;
        else
          return convert_function_from_foreign(*(void* const*)data,
                                               TheSvector(fvd)->data[1],
                                               TheSvector(fvd)->data[2],
                                               TheSvector(fvd)->data[3]);
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null)))
                 && (fvdlen == 2)) {
        if (*(void* const*)data == NULL)
          return NIL;
        else
          return convert_from_foreign(TheSvector(fvd)->data[1],
                                      *(void* const*)data);
      } else if (eq(fvdtype,S(c_pointer)) && (fvdlen == 2)) {
        if (*(void* const*)data == NULL)
          return NIL;
        else {
          var const uintP address = (uintP)(*(void* const *) data);
          pushSTACK(TheSvector(fvd)->data[1]);
          pushSTACK(make_faddress(O(fp_zero),address));
          var object fvar = allocate_fvariable();
          record_flags_replace(TheFvariable(fvar), 0);
          TheFvariable(fvar)->fv_name    = NIL; /* no name known */
          TheFvariable(fvar)->fv_address = popSTACK();
          fvd = popSTACK();
          TheFvariable(fvar)->fv_size    = fixnum(foreign_size(fvd));
          TheFvariable(fvar)->fv_type    = fvd;
          return fvar;
        }
      } else if (eq(fvdtype,S(c_array_ptr)) && (fvdlen == 2)) {
        if (*(void* const*)data == NULL)
          return NIL;
        else {
          var object eltype = TheSvector(fvd)->data[1];
          var uintL eltype_size = foreign_size(eltype);
          if (eltype_size == 0) error_eltype_zero_size(fvd);
          /* Determine length of array: */
          var uintL len = 0;
          {
            var const void* ptr = *(const void* const*)data;
            while (!blockzerop(ptr,eltype_size)) {
              ptr = (const void*)((uintP)ptr + eltype_size);
              len++;
            }
          }
          if (eq(eltype,S(character))) {
            /* 1-dimensional array of CHARACTER. */
           #ifdef ENABLE_UNICODE
            var object encoding = O(foreign_encoding);
            var uintL clen =
              Encoding_mblen(encoding)(encoding,
                                       *(const uintB**)data,*(const uintB**)data+len);
           #else
            var uintL clen = len;
           #endif
            check_stringsize(clen);
            var object string = allocate_string(clen);
            if (clen > 0) {
              var chart* cptr = &TheSnstring(string)->data[0];
              var const uintB* bptr = *(const uintB**)data;
             #ifdef ENABLE_UNICODE
              var const uintB* bendptr = bptr+len;
              encoding = O(foreign_encoding);
              var chart* cendptr = cptr+clen;
              Encoding_mbstowcs(encoding)(encoding,nullobj,&bptr,bendptr,&cptr,cendptr);
              ASSERT(cptr == cendptr);
             #else
              do { *cptr++ = as_chart(*bptr++); } while(--clen);
             #endif
            }
            return string;
          }
          pushSTACK(eltype);
          /* Allocate Lisp array: */
          pushSTACK(allocate_vector(len));
          /* Fill Lisp array: */
          {
            var const void* ptr = *(const void* const*)data;
            var uintL i;
            for (i = 0; i < len; i++) {
              var object obj = convert_from_foreign(STACK_1,ptr);
              TheSvector(STACK_0)->data[i] = obj;
              ptr = (const void*)((uintP)ptr + eltype_size);
            }
          }
          var object result = STACK_0;
          skipSTACK(2);
          return result;
        }
      }
    }
  } else {
    object inttype = gethash(fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      return convert_from_foreign(inttype,data);
  }
  error_foreign_type(fvd);
}

/* Test whether a foreign type contained C-PTRs (recursively). */
local bool foreign_with_pointers_p (object fvd)
{
  check_SP();
  if (symbolp(fvd)) {
    if (eq(fvd,S(c_string)))
      return true;
    return false;
  } else if (stringp(fvd)) {
    return false; /* inttype */
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        var uintL i;
        for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++)
          if (foreign_with_pointers_p(TheSvector(fvd)->data[i]))
            return true;
        return false;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        /* Use the union's first component. */
        return foreign_with_pointers_p(fvdlen > 2 ? (object)TheSvector(fvd)->data[2] : NIL);
      } else if ((eq(fvdtype,S(c_array)) && (fvdlen > 1))
                 || (eq(fvdtype,S(c_array_max)) && (fvdlen == 3))) {
        var uintL i;
        for (i = 2; i < fvdlen; i++)
          if (eq(TheSvector(fvd)->data[i],Fixnum_0))
            return false;
        return foreign_with_pointers_p(TheSvector(fvd)->data[1]);
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        return true;
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null))
                  || eq(fvdtype,S(c_array_ptr))) && (fvdlen == 2)) {
        return true;
      } else if (eq(fvdtype,S(c_pointer)) && (fvdlen == 2)) {
        return false;
      }
    }
  }
  error_foreign_type(fvd);
}

struct walk_foreign {
  bool null_terminates;
  /* what's the meaning of fvd here?? */
  void (*pre_hook) (object fvd, void** pdata, struct walk_foreign *walk);
  void (*post_hook) (object fvd, void** pdata, struct walk_foreign *walk);
  void (*function_hook) (object fvd, void** pdata, struct walk_foreign *walk);
};

/* Walk foreign data, giving special attention to the pointers. */
local void walk_foreign_pointers (object fvd, void* data,
                                  struct walk_foreign *walk)
{
  if (!foreign_with_pointers_p(fvd))
    return;
  check_SP();
  if (symbolp(fvd)) {
    if (eq(fvd,S(c_string))) {
      if (walk->null_terminates) {
        /* NULL pointers stop the recursion */
        if (*(void**)data == NULL)
          return;
      }
      (*walk->pre_hook)(fvd,(void**)data,walk);
      (*walk->post_hook)(fvd,(void**)data,walk);
      return;
    }
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        var uintL cumul_size = 0;
        var uintL cumul_alignment = struct_alignment;
        var uintL i;
        for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
          var object fvdi = TheSvector(fvd)->data[i];
          var struct foreign_layout sas;
          foreign_layout(fvdi,&sas);
          /* We assume all alignments are of the form 2^k. */
          cumul_size += (-cumul_size) & (sas.alignment-1);
          var void* pdata = (char*)data + cumul_size;
          cumul_size += sas.size;
          /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
          if (sas.alignment > cumul_alignment)
            cumul_alignment = sas.alignment;
          /* Now we are finished with sas.size and sas.alignment.
             Descend into the structure slot: */
          walk_foreign_pointers(fvdi,pdata,walk);
        }
        return;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        /* Use the union's first component. */
        if (fvdlen > 2)
          walk_foreign_pointers(TheSvector(fvd)->data[2],data,walk);
        return;
      } else if (eq(fvdtype,S(c_array)) && (fvdlen > 1)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL eltype_size = foreign_size(eltype);
        var uintL size = 1;
        {
          var uintL i;
          for (i = 2; i < fvdlen; i++) {
            var object dim = TheSvector(fvd)->data[i];
            if (!uint32_p(dim))
              error_foreign_type(fvd);
            size *= I_to_uint32(dim);
          }
        }
        {
          var uintL i;
          var char* pdata = (char*)data;
          for (i = 0; i < size; i++, pdata += eltype_size) {
            /* pdata = (char*)data + i*eltype_size */
            walk_foreign_pointers(eltype,pdata,walk);
          }
        }
        return;
      } else if (eq(fvdtype,S(c_array_max)) && (fvdlen == 3)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL eltype_size = foreign_size(eltype);
        if (eltype_size == 0) error_eltype_zero_size(fvd);
        {
          var uintL maxdim = I_to_UL(TheSvector(fvd)->data[2]);
          var uintL len = 0;
          var void* ptr = data;
          while (!((len == maxdim) || blockzerop(ptr,eltype_size))) {
            walk_foreign_pointers(eltype,ptr,walk);
            ptr = (void*)((uintP)ptr + eltype_size);
            len++;
          }
        }
        return;
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        if (walk->null_terminates) {
          /* NULL pointers stop the recursion */
          if (*(void**)data == NULL)
            return;
        }
        (*walk->function_hook)(fvd,(void**)data,walk);
        return;
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null)))
                 && (fvdlen == 2)) {
        if (walk->null_terminates || eq(fvdtype,S(c_ptr_null))) {
          /* NULL pointers stop the recursion */
          if (*(void**)data == NULL)
            return;
        }
        fvd = TheSvector(fvd)->data[1];
        (*walk->pre_hook)(fvd,(void**)data,walk);
        walk_foreign_pointers(fvd,*(void**)data,walk);
        (*walk->post_hook)(fvd,(void**)data,walk);
        return;
      } else if (eq(fvdtype,S(c_array_ptr)) && (fvdlen == 2)) {
        if (walk->null_terminates) {
          /* NULL pointers stop the recursion */
          if (*(void**)data == NULL)
            return;
        }
        var object elfvd = TheSvector(fvd)->data[1];
        (*walk->pre_hook)(elfvd,(void**)data,walk);
        {
          var uintL eltype_size = foreign_size(elfvd);
          if (eltype_size == 0) error_eltype_zero_size(fvd);
          var void* ptr = *(void**)data;
          while (!blockzerop(ptr,eltype_size)) {
            walk_foreign_pointers(elfvd,ptr,walk);
            ptr = (void*)((uintP)ptr + eltype_size);
          }
        }
        (*walk->post_hook)(elfvd,(void**)data,walk);
        return;
      }
    }
  }
  error_foreign_type(fvd);
}

/* Free the storage used by foreign data. */
global void free_foreign (object fvd, void* data);
local void free_walk_pre (object fvd, void** pdata, struct walk_foreign *walk)
{
}
local void free_walk_post (object fvd, void** pdata, struct walk_foreign *walk)
{
  begin_system_call();
  free(*pdata);
  end_system_call();
  *pdata = NULL; /* for safety */
}
local void free_walk_function (object fvd, void** pdata,
                               struct walk_foreign *walk)
{
  free_foreign_callin(*pdata);
  *pdata = NULL; /* for safety */
}
global void free_foreign (object fvd, void* data)
{
  struct walk_foreign walk
    = { true, &free_walk_pre, &free_walk_post, &free_walk_function };
  walk_foreign_pointers(fvd,data,&walk);
}

/* Some flags and hooks that direct the walk: */
struct walk_lisp {
  uintL counter;
  uintL alignment;
  bool nil_terminates;
  void (*pre_hook) (object fvd, object obj, struct walk_lisp *walk);
  void (*post_hook) (object fvd, object obj, struct walk_lisp *walk);
  void (*function_hook) (object fvd, object obj, struct walk_lisp *walk);
};

/* Walk Lisp data, giving special attention to the pointers.
 can trigger GC */
local maygc void walk_lisp_pointers (object fvd, object obj,
                                     struct walk_lisp *walk) {
  if (!foreign_with_pointers_p(fvd))
    return;
  check_SP();
  check_STACK();
  if (symbolp(fvd)) {
    if (eq(fvd,S(c_string))) {
      if (walk->nil_terminates) {
        /* NIL pointers stop the recursion */
        if (nullp(obj))
          return;
      }
      if (!stringp(obj)) goto bad_obj;
      (*walk->pre_hook)(fvd,obj,walk);
      (*walk->post_hook)(fvd,obj,walk);
      return;
    }
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        var object slots = TheSvector(fvd)->data[C_STRUCT_SLOTS];
        var object constructor = TheSvector(fvd)->data[C_STRUCT_CONSTRUCTOR];
        if (!(simple_vector_p(slots)
              && (Svector_length(slots)==fvdlen-C_STRUCT_C_TYPE_START)))
          error_foreign_type(fvd);
        if (eq(constructor,L(vector))) {
          if (!(simple_vector_p(obj)
                && (Svector_length(obj)==fvdlen-C_STRUCT_C_TYPE_START)))
            goto bad_obj;
        } else if (eq(constructor,L(list))) {
        } else {
          if (!(structurep(obj) || instancep(obj)))
            goto bad_obj;
        }
        pushSTACK(constructor);
        pushSTACK(slots);
        pushSTACK(fvd);
        pushSTACK(obj);
        var uintL cumul_size = 0;
        var uintL cumul_alignment = struct_alignment;
        var uintL i;
        for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
          var object obji;
          if (eq(STACK_3,L(vector))) {
            obji = TheSvector(STACK_0)->data[i-C_STRUCT_C_TYPE_START];
          } else if (eq(STACK_3,L(list))) {
            obji = STACK_0;
            if (atomp(obji)) goto bad_obj;
            STACK_0 = Cdr(obji); obji = Car(obji);
          } else { /* simple_vector_p(slots)
                      && (Svector_length(slots)==fvdlen-C_STRUCT_C_TYPE_START) */
            pushSTACK(STACK_0);
            pushSTACK(TheSvector(STACK_(2+1))->data[i-C_STRUCT_C_TYPE_START]);
            funcall(L(slot_value),2); obji = value1;
          }
          var object fvdi = TheSvector(STACK_1)->data[i];
          var struct foreign_layout sas;
          foreign_layout(fvdi,&sas);
          /* We assume all alignments are of the form 2^k. */
          cumul_size += (-cumul_size) & (sas.alignment-1);
          cumul_size += sas.size;
          /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
          if (sas.alignment > cumul_alignment)
            cumul_alignment = sas.alignment;
          /* Now we are finished with sas.size and sas.alignment.
             Descend into the structure slot: */
          walk_lisp_pointers(fvdi,obji,walk);
        }
        skipSTACK(4);
        return;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        /* Use the union's first component. */
        if (fvdlen > 2)
          walk_lisp_pointers(TheSvector(fvd)->data[2],obj,walk);
        return;
      } else if (eq(fvdtype,S(c_array)) && (fvdlen > 1)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL size = 1;
        var struct foreign_layout sas;
        foreign_layout(eltype,&sas);
        {
          var uintL i;
          for (i = 2; i < fvdlen; i++) {
            var object dim = TheSvector(fvd)->data[i];
            if (!uint32_p(dim))
              error_foreign_type(fvd);
            size *= I_to_uint32(dim);
          }
        }
        if (!(arrayp(obj) && array_total_size(obj)==size))
          goto bad_obj;
        pushSTACK(eltype);
        pushSTACK(obj);
        {
          var uintL i;
          for (i = 0; i < size; i++) {
            pushSTACK(STACK_0); pushSTACK(fixnum(i));
            funcall(L(row_major_aref),2);
            walk_lisp_pointers(STACK_1,value1,walk);
          }
        }
        skipSTACK(2);
        return;
      } else if (eq(fvdtype,S(c_array_max)) && (fvdlen == 3)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL maxdim = I_to_UL(TheSvector(fvd)->data[2]);
        var struct foreign_layout data;
        foreign_layout(eltype,&data);
        if (!vectorp(obj))
          goto bad_obj;
        var uintL len = vector_length(obj);
        if (len > maxdim)
          len = maxdim;
        pushSTACK(eltype);
        pushSTACK(obj);
        {
          var uintL i;
          for (i = 0; i < len; i++) {
            pushSTACK(STACK_0); pushSTACK(fixnum(i));
            funcall(L(aref),2);
            walk_lisp_pointers(STACK_1,value1,walk);
          }
        }
        skipSTACK(2);
        return;
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        (*walk->function_hook)(fvd,obj,walk);
        return;
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null)))
                 && (fvdlen == 2)) {
        if (walk->nil_terminates || eq(fvdtype,S(c_ptr_null))) {
          /* NIL pointers stop the recursion */
          if (nullp(obj))
            return;
        }
        (*walk->pre_hook)(fvd,obj,walk);
        pushSTACK(fvd);
        walk_lisp_pointers(TheSvector(fvd)->data[1],obj,walk);
        fvd = popSTACK();
        (*walk->post_hook)(fvd,obj,walk);
        return;
      } else if (eq(fvdtype,S(c_array_ptr)) && (fvdlen == 2)) {
        if (walk->nil_terminates) {
          /* NIL pointers stop the recursion */
          if (nullp(obj))
            return;
        }
        if (!vectorp(obj)) goto bad_obj;
        (*walk->pre_hook)(fvd,obj,walk);
        pushSTACK(fvd);
        pushSTACK(TheSvector(fvd)->data[1]); /* eltype */
        pushSTACK(obj);
        {
          var uintL size = vector_length(obj);
          var uintL i;
          for (i = 0; i < size; i++) {
            pushSTACK(STACK_0); pushSTACK(fixnum(i));
            funcall(L(aref),2);
            walk_lisp_pointers(STACK_1,value1,walk);
          }
        }
        skipSTACK(2);
        fvd = popSTACK();
        (*walk->post_hook)(fvd,obj,walk);
        return;
      }
    }
  }
  error_foreign_type(fvd);
 bad_obj:
  error_convert(fvd,obj);
}

/* Determine amount of additional storage needed
 to convert Lisp data to foreign data.
 can trigger GC */
local maygc void convert_to_foreign_needs (object fvd, object obj,
                                           struct foreign_layout *sas);
local void count_walk_pre (object fvd, object obj, struct walk_lisp *walk)
{
  var uintL size;
  var uintL alignment;
  if (eq(fvd,S(c_string))) {
    if (nullp(obj))
      size = 0;
    else {
      ASSERT(stringp(obj));
      var uintL len;
      var uintL offset;
      var object string = unpack_string_ro(obj,&len,&offset);
      var const chart* ptr1;
      unpack_sstring_alloca(string,len,offset, ptr1=);
      var uintL bytelen = cslen(O(foreign_encoding),ptr1,len);
      size = bytelen + 1;
    }
    alignment = 1;
  } else {
    /* fvd = #(c-ptr ...), #(c-ptr-null ...), #(c-array-ptr ...) */
    var object eltype = TheSvector(fvd)->data[1];
    var struct foreign_layout sas;
    foreign_layout(eltype,&sas);
    size = sas.size;
    alignment = sas.alignment;
    if (eq(TheSvector(fvd)->data[0],S(c_array_ptr))) {
      if (eq(eltype,S(character)) && stringp(obj)) {
        var uintL clen;
        var uintL offset;
        var object string = unpack_string_ro(obj,&clen,&offset);
        var const chart* ptr1;
        unpack_sstring_alloca(string,clen,offset, ptr1=);
        var uintL blen = cslen(O(foreign_encoding),ptr1,clen);
        size = blen + 1;
      } else {
        size *= vector_length(obj) + 1;
      }
    }
  }
  walk->counter = ((walk->counter + alignment-1) & -alignment) + size;
  /* walk->alignment = lcm(walk->alignment,alignment); */
  if (alignment > walk->alignment)
    walk->alignment = alignment;
}
local void count_walk_post (object fvd, object obj, struct walk_lisp *walk)
{
}
local maygc void convert_to_foreign_needs (object fvd, object obj,
                                           struct foreign_layout *sas)
{
  struct walk_lisp walk
    = { 0, 1, true, &count_walk_pre, &count_walk_post, &count_walk_post };
  walk_lisp_pointers(fvd,obj,&walk);
  sas->size = walk.counter; sas->alignment = walk.alignment;
}

/* Convert Lisp data to foreign data.
   Storage is allocated through converter_malloc().
 Only the toplevel storage must already exist; its address is given.
 can trigger GC */
modexp maygc void convert_to_foreign
(object fvd, object obj, void* data, converter_malloc_t *converter_malloc,
 void** state) { /* keep in sync with foreign1.lisp:convert-to-foreign */
  check_SP();
  check_STACK();
  if (NULL == data) {
    pushSTACK(fvd); pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: trying to write object ~S of type ~S into NULL address"));
  }
  if (symbolp(fvd)) {
    if (eq(fvd,S(c_pointer))) {
      if (fvariablep(obj))
        obj = TheFvariable(obj)->fv_address;
      else if (nullp(obj)) { *(void**)data = NULL; return; }
      else if (fpointerp(obj)) {
        *(void**)data = Fpointer_value(validate_fpointer(obj)); return;
      } else if (!faddressp(obj)) goto bad_obj;
      obj = check_faddress_valid(obj);
      *(void**)data = Faddress_value(obj);
      return;
    } else if (eq(fvd,S(c_string))) {
      if (nullp(obj)) {
        *(char**)data = NULL;
        return;
      }
      if (!stringp(obj)) goto bad_obj;
      var uintL len;
      var uintL offset;
      var object string = unpack_string_ro(obj,&len,&offset);
      var const chart* ptr1;
      unpack_sstring_alloca(string,len,offset, ptr1=);
      var uintL bytelen = cslen(O(foreign_encoding),ptr1,len);
      /* bytelen is the same as computed earlier in count_walk_pre. */
      var char* asciz =
        (char*)converter_malloc(*(char**)data,bytelen+1,1,state);
      cstombs(O(foreign_encoding),ptr1,len,(uintB*)asciz,bytelen);
      asciz[bytelen] = '\0';
      *(char**)data = asciz;
      return;
    } else if (eq(fvd,S(char)) || eq(fvd,S(sint8))) {
      var sint8* pdata = (sint8*)data;
      if (!sint8_p(obj)) goto bad_obj;
      *pdata = I_to_sint8(obj);
      return;
    } else if (eq(fvd,S(uchar)) || eq(fvd,S(uint8))) {
      var uint8* pdata = (uint8*)data;
      if (!uint8_p(obj)) goto bad_obj;
      *pdata = I_to_uint8(obj);
      return;
    } else if (eq(fvd,S(short)) || eq(fvd,S(sint16))) {
      var sint16* pdata = (sint16*)data;
      if (!sint16_p(obj)) goto bad_obj;
      *pdata = I_to_sint16(obj);
      return;
    } else if (eq(fvd,S(ushort)) || eq(fvd,S(uint16))) {
      var uint16* pdata = (uint16*)data;
      if (!uint16_p(obj)) goto bad_obj;
      *pdata = I_to_uint16(obj);
      return;
    } else if (eq(fvd,S(sint32))) {
      var sint32* pdata = (sint32*)data;
      if (!sint32_p(obj)) goto bad_obj;
      *pdata = I_to_sint32(obj);
      return;
    } else if (eq(fvd,S(uint32))) {
      var uint32* pdata = (uint32*)data;
      if (!uint32_p(obj)) goto bad_obj;
      *pdata = I_to_uint32(obj);
      return;
    }
   #ifdef HAVE_LONG_LONG_INT
    else if (eq(fvd,S(sint64))) {
      var struct_sint64* pdata = (struct_sint64*)data;
      if (!sint64_p(obj)) goto bad_obj;
      var sint64 val = I_to_sint64(obj);
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      pdata->hi = (sint32)(val>>32); pdata->lo = (uint32)val;
     #else
      *pdata = val;
     #endif
      return;
    } else if (eq(fvd,S(uint64))) {
      var struct_uint64* pdata = (struct_uint64*)data;
      if (!uint64_p(obj)) goto bad_obj;
      var uint64 val = I_to_uint64(obj);
     #if (long_bitsize<64) && !defined(HAVE_LONG_LONG_INT)
      pdata->hi = (uint32)(val>>32); pdata->lo = (uint32)val;
     #else
      *pdata = val;
     #endif
      return;
    }
   #else
    else if (eq(fvd,S(sint64)) || eq(fvd,S(uint64))) {
      error_64bit(fvd);
    }
   #endif
    else if (eq(fvd,S(int))) {
      var int* pdata = (int*)data;
      if (!sint_p(obj)) goto bad_obj;
      *pdata = I_to_sint(obj);
      return;
    } else if (eq(fvd,S(uint))) {
      var unsigned int * pdata = (unsigned int *)data;
      if (!uint_p(obj)) goto bad_obj;
      *pdata = I_to_uint(obj);
      return;
    } else if (eq(fvd,S(long))) {
      var long* pdata = (long*)data;
      if (!slong_p(obj)) goto bad_obj;
      *pdata = I_to_slong(obj);
      return;
    } else if (eq(fvd,S(ulong))) {
      var unsigned long * pdata = (unsigned long *)data;
      if (!ulong_p(obj)) goto bad_obj;
      *pdata = I_to_ulong(obj);
      return;
    } else if (eq(fvd,S(single_float))) {
      var ffloatjanus* pdata = (ffloatjanus*) data;
      if (!single_float_p(obj)) goto bad_obj;
      FF_to_c_float(obj,pdata);
      return;
    } else if (eq(fvd,S(double_float))) {
      var dfloatjanus* pdata = (dfloatjanus*) data;
      if (!double_float_p(obj)) goto bad_obj;
      DF_to_c_double(obj,pdata);
      return;
    } else if (eq(fvd,S(boolean))) {
      var int* pdata = (int*)data;
      if (nullp(obj))
        *pdata = 0;
      else if (eq(obj,T))
        *pdata = 1;
      else
        goto bad_obj;
      return;
    } else if (eq(fvd,S(character))) {
      var uintB* pdata = (unsigned char *)data;
      if (!charp(obj)) goto bad_obj;
      var chart ch = char_code(obj);
     #ifdef ENABLE_UNICODE
      ASSERT(cslen(O(foreign_8bit_encoding),&ch,1) == 1);
      cstombs(O(foreign_8bit_encoding),&ch,1,pdata,1);
     #else
      *pdata = as_cint(ch);
     #endif
      return;
    } else if (eq(fvd,S(nil)))
      /* If we are presented the empty type, we take it as "ignore". */
      return;
  } else if (simple_vector_p(fvd)) {
    var uintL fvdlen = Svector_length(fvd);
    if (fvdlen > 0) {
      var object fvdtype = TheSvector(fvd)->data[0];
      if (eq(fvdtype,S(c_struct)) && (fvdlen >= C_STRUCT_C_TYPE_START)) {
        var object slots = TheSvector(fvd)->data[C_STRUCT_SLOTS];
        var object constructor = TheSvector(fvd)->data[C_STRUCT_CONSTRUCTOR];
        if (!(simple_vector_p(slots)
              && (Svector_length(slots)==fvdlen-C_STRUCT_C_TYPE_START)))
          error_foreign_type(fvd);
        if (eq(constructor,L(vector))) {
          if (!(simple_vector_p(obj)
                && (Svector_length(obj)==fvdlen-C_STRUCT_C_TYPE_START)))
            goto bad_obj;
        } else if (eq(constructor,L(list))) {
        } else {
          if (!(structurep(obj) || instancep(obj)))
            goto bad_obj;
        }
        pushSTACK(constructor);
        pushSTACK(slots);
        pushSTACK(fvd);
        pushSTACK(obj);
        var uintL cumul_size = 0;
        var uintL cumul_alignment = struct_alignment;
        var uintL i;
        for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
          var object obji;
          if (eq(STACK_3,L(vector))) {
            obji = TheSvector(STACK_0)->data[i-C_STRUCT_C_TYPE_START];
          } else if (eq(STACK_3,L(list))) {
            obji = STACK_0;
            if (atomp(obji)) goto bad_obj;
            STACK_0 = Cdr(obji); obji = Car(obji);
          } else { /* simple_vector_p(slots)
                      && (Svector_length(slots)==fvdlen-C_STRUCT_C_TYPE_START) */
            pushSTACK(STACK_0);
            pushSTACK(TheSvector(STACK_(2+1))->data[i-C_STRUCT_C_TYPE_START]);
            funcall(L(slot_value),2); obji = value1;
          }
          var object fvdi = TheSvector(STACK_1)->data[i];
          var struct foreign_layout sas;
          foreign_layout(fvdi,&sas);
          /* We assume all alignments are of the form 2^k. */
          cumul_size += (-cumul_size) & (sas.alignment-1);
          var void* pdata = (char*)data + cumul_size;
          cumul_size += sas.size;
          /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
          if (sas.alignment > cumul_alignment)
            cumul_alignment = sas.alignment;
          /* Now we are finished with sas.size and sas.alignment.
             Descend into the structure slot: */
          convert_to_foreign(fvdi,obji,pdata,converter_malloc,state);
        }
        skipSTACK(4);
        return;
      } else if (eq(fvdtype,S(c_union)) && (fvdlen > 1)) {
        /* Use the union's first component. */
        convert_to_foreign(fvdlen > 2 ? (object)TheSvector(fvd)->data[2] : NIL,
                           obj,data,converter_malloc,state);
        return;
      } else if (eq(fvdtype,S(c_array)) && (fvdlen > 1)) {
        var object eltype = TheSvector(fvd)->data[1];
        if (fvdlen == 3 && eq(eltype,S(character)) && stringp(obj)) {
          /* 1-dimensional array of CHARACTER. */
          var uintL clen;
          var uintL offset;
          var object string = unpack_string_ro(obj,&clen,&offset);
          var const chart* ptr1;
          unpack_sstring_alloca(string,clen,offset, ptr1=);
          var uintL blen = cslen(O(foreign_encoding),ptr1,clen);
          if (blen != I_to_UL(TheSvector(fvd)->data[2]))
            goto bad_obj;
          cstombs(O(foreign_encoding),ptr1,clen,(uintB*)data,blen);
          return;
        }
        var uintL eltype_size = foreign_size(eltype);
        var uintL size = 1;
        {
          var uintL i;
          for (i = 2; i < fvdlen; i++) {
            var object dim = TheSvector(fvd)->data[i];
            if (!uint32_p(dim))
              error_foreign_type(fvd);
            size *= I_to_uint32(dim);
          }
        }
        if (!(arrayp(obj) && array_total_size(obj)==size))
          goto bad_obj;
        if (eq(eltype,S(character)) && stringp(obj)) {
          var uintL len;
          var uintL offset;
          var object string = unpack_string_ro(obj,&len,&offset);
          var const chart* ptr1;
          unpack_sstring_alloca(string,len,offset, ptr1=);
          ASSERT(cslen(O(foreign_8bit_encoding),ptr1,len) == len);
          cstombs(O(foreign_8bit_encoding),ptr1,len,(uintB*)data,len);
        } else if (eq(eltype,S(uint8)) && bit_vector_p(Atype_8Bit,obj)) {
          if (size > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,size,&offset);
            var const uint8* ptr1 = &TheSbvector(obj)->data[offset];
            var uint8* ptr2 = (uint8*)data;
            var uintL count = size;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
        } else if (eq(eltype,S(uint16)) && bit_vector_p(Atype_16Bit,obj)) {
          if (size > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,size,&offset);
            var const uint16* ptr1 =
              (uint16*)&TheSbvector(obj)->data[2*offset];
            var uint16* ptr2 = (uint16*)data;
            var uintL count = size;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
        } else if (eq(eltype,S(uint32)) && bit_vector_p(Atype_32Bit,obj)) {
          if (size > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,size,&offset);
            var const uint32* ptr1 =
              (uint32*)&TheSbvector(obj)->data[4*offset];
            var uint32* ptr2 = (uint32*)data;
            var uintL count = size;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
        } else {
          pushSTACK(eltype);
          pushSTACK(obj);
          {
            var uintL i;
            var char* pdata = (char*)data;
            for (i = 0; i < size; i++, pdata += eltype_size) {
              /* pdata = (char*)data + i*eltype_size */
              pushSTACK(STACK_0); pushSTACK(fixnum(i));
              funcall(L(row_major_aref),2);
              convert_to_foreign(STACK_1,value1,pdata,converter_malloc,state);
            }
          }
          skipSTACK(2);
        }
        return;
      } else if (eq(fvdtype,S(c_array_max)) && (fvdlen == 3)) {
        var object eltype = TheSvector(fvd)->data[1];
        var uintL maxdim = I_to_UL(TheSvector(fvd)->data[2]);
        if (eq(eltype,S(character)) && stringp(obj)) {
          /* 1-dimensional array of CHARACTER. */
          var uintL clen;
          var uintL offset;
          var object string = unpack_string_ro(obj,&clen,&offset);
          var const chart* ptr1;
          unpack_sstring_alloca(string,clen,offset, ptr1=);
          var uintL blen = cslen(O(foreign_encoding),ptr1,clen);
          if (blen > maxdim)
            blen = maxdim;
          var uintB* ptr2 = (uintB*)data;
         #ifdef ENABLE_UNICODE
          var object encoding = O(foreign_encoding);
          Encoding_wcstombs(encoding)(encoding,nullobj,&ptr1,ptr1+clen,&ptr2,ptr2+blen);
         #else
          begin_system_call(); memcpy(ptr2,ptr1,blen); end_system_call();
          ptr2 += blen;
         #endif
          if (ptr2 < (uintB*)data+maxdim)
            *ptr2 = '\0';
          return;
        }
        var uintL eltype_size = foreign_size(eltype);
        if (!vectorp(obj))
          goto bad_obj;
        var uintL len = vector_length(obj);
        if (len > maxdim)
          len = maxdim;
        if (eq(eltype,S(uint8)) && bit_vector_p(Atype_8Bit,obj)) {
          var uint8* ptr2 = (uint8*)data;
          if (len > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,len,&offset);
            var const uint8* ptr1 = &TheSbvector(obj)->data[offset];
            var uintL count = len;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
          if (len < maxdim)
            *ptr2 = 0;
        } else if (eq(eltype,S(uint16)) && bit_vector_p(Atype_16Bit,obj)) {
          var uint16* ptr2 = (uint16*)data;
          if (len > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,len,&offset);
            var const uint16* ptr1 =
              (uint16*)&TheSbvector(obj)->data[2*offset];
            var uintL count = len;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
          if (len < maxdim)
            *ptr2 = 0;
        } else if (eq(eltype,S(uint32)) && bit_vector_p(Atype_32Bit,obj)) {
          var uint32* ptr2 = (uint32*)data;
          if (len > 0) {
            var uintL offset = 0;
            obj = array_displace_check(obj,len,&offset);
            var const uint32* ptr1 =
              (uint32*)&TheSbvector(obj)->data[4*offset];
            var uintL count = len;
            do { *ptr2++ = *ptr1++; } while(--count);
          }
          if (len < maxdim)
            *ptr2 = 0;
        } else {
          pushSTACK(eltype);
          pushSTACK(obj);
          {
            var uintL i;
            var char* pdata = (char*)data;
            for (i = 0; i < len; i++, pdata += eltype_size) {
              /* pdata = (char*)data + i*eltype_size */
              pushSTACK(STACK_0); pushSTACK(fixnum(i));
              funcall(L(aref),2);
              convert_to_foreign(STACK_1,value1,pdata,converter_malloc,state);
            }
            if (len < maxdim)
              blockzero(pdata,eltype_size);
          }
          skipSTACK(2);
        }
        return;
      } else if (eq(fvdtype,S(c_function)) && (fvdlen == 4)) {
        if (nullp(obj)) {
          *(void**)data = NULL;
        } else {
          var object ffun =
            convert_function_to_foreign(obj,
                                        TheSvector(fvd)->data[1],
                                        TheSvector(fvd)->data[2],
                                        TheSvector(fvd)->data[3]);
          /* known to be valid! */
          *(void**)data = Faddress_value(TheFfunction(ffun)->ff_address);
        }
        return;
      } else if ((eq(fvdtype,S(c_ptr)) || eq(fvdtype,S(c_ptr_null)))
                 && (fvdlen == 2)) {
        if (nullp(obj) && eq(fvdtype,S(c_ptr_null))) {
          *(void**)data = NULL;
          return;
        }
        fvd = TheSvector(fvd)->data[1];
        var struct foreign_layout sas;
        foreign_layout(fvd,&sas);
        var void* p =
          converter_malloc(*(void**)data,sas.size,sas.alignment,state);
        *(void**)data = p;
        convert_to_foreign(fvd,obj,p,converter_malloc,state);
        return;
      } else if (eq(fvdtype,S(c_pointer)) && (fvdlen == 2)) {
        if (faddressp(obj)) {
          obj = check_faddress_valid(obj);
          *(void**)data = Faddress_value(obj);
          return;
        } else if (fvariablep(obj)) {
          fvd = TheSvector(fvd)->data[1];
          if (equal_fvd(fvd,TheFvariable(obj)->fv_type)) {
            obj = TheFvariable(obj)->fv_address;
            obj = check_faddress_valid(obj);
            *(void**)data = Faddress_value(obj);
            return;
          } else goto bad_obj;
        } else if (nullp(obj)) { *(void**)data = NULL; return; }
        else goto bad_obj;
      } else if (eq(fvdtype,S(c_array_ptr)) && (fvdlen == 2)) {
        if (nullp(obj)) {
          *(void**)data = NULL;
          return;
        }
        var object eltype = TheSvector(fvd)->data[1];
        if (eq(eltype,S(character)) && stringp(obj)) {
          /* 1-dimensional array of CHARACTER. */
          var uintL clen;
          var uintL offset;
          var object string = unpack_string_ro(obj,&clen,&offset);
          var const chart* ptr1;
          unpack_sstring_alloca(string,clen,offset, ptr1=);
          var uintL blen = cslen(O(foreign_encoding),ptr1,clen);
          var void* p = converter_malloc(*(void**)data,blen+1,1,state);
          *(void**)data = p;
          cstombs(O(foreign_encoding),ptr1,clen,(uintB*)p,blen);
          ((uintB*)p)[blen] = '\0';
          return;
        }
        if (!vectorp(obj)) goto bad_obj;
        var uintL len = vector_length(obj);
        var struct foreign_layout sas;
        foreign_layout(eltype,&sas);
        var uintL eltype_size = sas.size;
        var void* p = converter_malloc(*(void**)data,(len+1)*eltype_size,
                                       sas.alignment,state);
        *(void**)data = p;
        pushSTACK(eltype);
        pushSTACK(obj);
        {
          var uintL i;
          for (i = 0; i < len; i++, p = (void*)((char*)p + eltype_size)) {
            pushSTACK(STACK_0); pushSTACK(fixnum(i));
            funcall(L(aref),2);
            convert_to_foreign(STACK_1,value1,p,converter_malloc,state);
          }
        }
        skipSTACK(2);
        blockzero(p,eltype_size);
        return;
      }
    }
  } else {
    object inttype = gethash(fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj)) {
      convert_to_foreign(inttype,obj,data,converter_malloc,state);
      return;
    }
  }
  error_foreign_type(fvd);
 bad_obj:
  error_convert(fvd,obj);
}

/* Convert Lisp data to foreign data.
 The foreign data has dynamic extent.
 1. convert_to_foreign_need(fvd,obj);
 2. make room according to sas.size and sas.alignment,
    set allocaing_room_pointer.
 3. convert_to_foreign(fvd,obj,data,room_pointer,&allocaing,
                       &allocaing_room_pointer);
    can trigger GC */
local void* allocaing (void* old_data, uintL size, uintL alignment,
                       void** allocaing_room_pointer) {
  *allocaing_room_pointer = (void*)(((uintP)*allocaing_room_pointer
                                     + alignment-1) & -(long)alignment);
  var void* result = *allocaing_room_pointer;
  *allocaing_room_pointer = (void*)((uintP)*allocaing_room_pointer + size);
  return result;
}

/* Convert Lisp data to foreign data.
 The foreign data is allocated through malloc() and has more than dynamic
 extent. (Not exactly indefinite extent: It is deallocated the next time
 free_foreign() is called on it.)
 can trigger GC */
modexp void* mallocing (void* old_data, uintL size, uintL alignment,
                        void** state)
{ return clisp_malloc(size); }

/* Convert Lisp data to foreign data.
 The foreign data storage is reused.
 DANGEROUS, especially for type C-STRING !!
 Also beware against NULL pointers! They are not treated specially.
 can trigger GC */
modexp void* nomalloc (void* old_data, uintL size, uintL alignment,
                       void** state)
{ return old_data; }

/* Error messages. */
nonreturning_function(local, error_foreign_variable, (object obj)) {
  pushSTACK(NIL);                 /* no PLACE */
  pushSTACK(obj);                 /* TYPE-ERROR slot DATUM */
  pushSTACK(S(foreign_variable)); /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(STACK_0); pushSTACK(obj);
  pushSTACK(TheSubr(subr_self)->name);
  error(type_error,GETTEXT("~S: ~S is not of type ~S"));
}
nonreturning_function(local, error_variable_no_fvd, (object obj)) {
  pushSTACK(obj);
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: foreign variable with unknown type, missing DEF-C-VAR: ~S"));
}

/* UP: looks up a foreign variable, given its Lisp name.
 > name -- lisp name
 > fvd --- FFI type
 can trigger GC */
local maygc object lookup_foreign_variable
(gcv_object_t *name, gcv_object_t *fvd) {
  var object fvar = gethash(*name,O(foreign_variable_table),false);
  if (eq(fvar,nullobj)) {
    pushSTACK(NIL);             /* 4 continue-format-string */
    pushSTACK(S(error));        /* 3 error type */
    pushSTACK(NIL);             /* 2 error-format-string */
    pushSTACK(S(find_foreign_variable)); /* 1 */
    pushSTACK(*name);                    /* 0 */
    STACK_2 = CLSTEXT("~S: foreign variable ~S does not exist");
    STACK_4 = CLSTEXT("Skip foreign variable creation");
    funcall(L(cerror_of_type),5);
    return NIL;
  }
  /* The first lookup_foreign_variable determines the variable's type. */
  if (nullp(TheFvariable(fvar)->fv_type)) {
    var struct foreign_layout sas;
    foreign_layout(*fvd,&sas);
    var object fa = TheFvariable(fvar)->fv_address;
    pushSTACK(fvar); fa = check_faddress_valid(fa); fvar = popSTACK();
    if (!((posfixnum_to_V(TheFvariable(fvar)->fv_size) == sas.size)
          && (((long)Faddress_value(fa) & (sas.alignment-1)) == 0))) {
      pushSTACK(fvar);
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: foreign variable ~S does not have the required size or alignment"));
    }
    TheFvariable(fvar)->fv_type = *fvd;
  } else if (!equal_fvd(TheFvariable(fvar)->fv_type,*fvd)) {
    /* Subsequent lookup_foreign_variable calls only compare the type. */
    if (!equalp_fvd(TheFvariable(fvar)->fv_type,*fvd)) {
      dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
      pushSTACK(*fvd);
      pushSTACK(TheFvariable(fvar)->fv_type);
      pushSTACK(fvar);
      pushSTACK(TheSubr(subr_self)->name);
      error(error_condition,GETTEXT("~S: type specifications for foreign variable ~S conflict: ~S and ~S"));
    }
    /* If the types are not exactly the same but still compatible,
       allocate a new foreign variable with the given fvd. */
    pushSTACK(fvar);
    var object new_fvar = allocate_fvariable();
    fvar = popSTACK();
    record_flags_replace(TheFvariable(new_fvar),
                         record_flags(TheFvariable(fvar)));
    TheFvariable(new_fvar)->fv_name    = TheFvariable(fvar)->fv_name;
    TheFvariable(new_fvar)->fv_address = TheFvariable(fvar)->fv_address;
    TheFvariable(new_fvar)->fv_size    = TheFvariable(fvar)->fv_size;
    TheFvariable(new_fvar)->fv_type    = *fvd;
    fvar = new_fvar;
  }
  return fvar;
}

/* forvard declaration -- defined later */
static maygc object foreign_library_variable
(gcv_object_t *name, gcv_object_t* fvd,
 gcv_object_t *library, gcv_object_t *version, gcv_object_t *offset);

nonreturning_function(local, error_version_nonlibrary,
                      (object name, object version)) {
  pushSTACK(version); pushSTACK(name), pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,
        GETTEXT("~S(~S): version ~S without library does not make sense"));
}

/* (FFI::FIND-FOREIGN-VARIABLE foreign-variable-name foreign-type
     foreign-library version foreign-offset) */
LISPFUNN(find_foreign_variable,5) {
  STACK_4 = coerce_ss(STACK_4); /* name */
  if (nullp(STACK_2)) { /* library */
    if (!nullp(STACK_1)) /* version */
      error_version_nonlibrary(STACK_4,STACK_1);
    VALUES1(lookup_foreign_variable(&STACK_4,&STACK_3));
  } else VALUES1(foreign_library_variable(&STACK_4,&STACK_3,&STACK_2,
                                          &STACK_1,&STACK_0));
  skipSTACK(5);
}

static void check_fvar_alignment (object fvar, uintL alignment) {
  if (((uintP)Faddress_value(TheFvariable(fvar)->fv_address) & (alignment-1))) {
    pushSTACK(fvar); pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: foreign variable ~S does not have the required alignment"));
  }
}

/* (FFI:FOREIGN-VARIABLE address c-type &key name) constructor */
LISPFUN(foreign_variable,seclass_read,2,0,norest,key,1,(kw(name)) )
{
 foreign_variable_restart:
  var object fa = STACK_2;
  if (fvariablep(fa))
    { fa = TheFvariable(fa)->fv_address; }
  /* If you believe objects of type foreign-function should be accepted,
   * then you probably missed an indirection. */
  if (!faddressp(fa)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(fa);              /* TYPE-ERROR slot DATUM */
    pushSTACK(O(type_foreign_variable)); /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(STACK_0); pushSTACK(fa);
    pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not of type ~S"));
    STACK_2 = value1;
    goto foreign_variable_restart;
  }
  fa = check_faddress_valid(fa);
  if (!missingp(STACK_0)) STACK_0 = coerce_ss(STACK_0);
  var object fvar = allocate_fvariable();
  var object fvd = STACK_1;
  var struct foreign_layout sas;
  foreign_layout(fvd,&sas);
  TheFvariable(fvar)->fv_size      = fixnum(sas.size);
  TheFvariable(fvar)->fv_type      = fvd;
  TheFvariable(fvar)->fv_name      = (boundp(STACK_0) ? (object)STACK_0 : NIL);
  if (fvariablep(STACK_2)) {
    var object old_fvar = STACK_2;
    TheFvariable(fvar)->fv_address = TheFvariable(old_fvar)->fv_address;
    record_flags_replace(TheFvariable(fvar),
                         record_flags(TheFvariable(old_fvar)));

    if (nullp(TheFvariable(fvar)->fv_name)) {
      TheFvariable(fvar)->fv_name  = TheFvariable(old_fvar)->fv_name;
    }
  } else {
    TheFvariable(fvar)->fv_address = STACK_2;
    record_flags_replace(TheFvariable(fvar), 0);
  }
  check_fvar_alignment(fvar,sas.alignment);
  VALUES1(fvar); skipSTACK(3);
}

/* (FFI::FOREIGN-VALUE foreign-variable)
 returns the value of the foreign variable as a Lisp data structure. */
LISPFUNN(foreign_value,1)
{
  var object fvar = STACK_0;
  if (!fvariablep(fvar)) error_foreign_variable(fvar);
  var object fa = TheFvariable(fvar)->fv_address;
  fa = check_faddress_valid(fa); fvar = STACK_0;
  var void* address = Faddress_value(fa);
  var object fvd = TheFvariable(fvar)->fv_type;
  if (nullp(fvd)) error_variable_no_fvd(fvar);
  VALUES1(convert_from_foreign(fvd,address)); skipSTACK(1);
}

/* (FFI::SET-FOREIGN-VALUE foreign-variable new-value)
 sets the value of the foreign variable. */
LISPFUNN(set_foreign_value,2)
{
  var object fvar = STACK_1;
  if (!fvariablep(fvar)) error_foreign_variable(fvar);
  var object fa = TheFvariable(fvar)->fv_address;
  fa = check_faddress_valid(fa); fvar = STACK_1;
  var void* address = Faddress_value(fa);
  var object fvd = TheFvariable(fvar)->fv_type;
  if (nullp(fvd)) error_variable_no_fvd(fvar);
  if (record_flags(TheFvariable(fvar)) & fv_readonly) {
    pushSTACK(fvar);
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: foreign variable ~S may not be modified"));
  }
  if (record_flags(TheFvariable(fvar)) & fv_malloc) {
    /* Protect this using a semaphore??
       Free old value: */
    free_foreign(fvd,address);
    /* Put in new value: */
    convert_to_foreign(fvd,STACK_0,address,&mallocing,NULL);
  } else {
    /* Protect this using a semaphore??
       Put in new value, reusing the old value's storage: */
    convert_to_foreign(fvd,STACK_0,address,&nomalloc,NULL);
  }
  VALUES1(STACK_0);
  skipSTACK(2);
}

LISPFUNN(foreign_type,1)
{ /* (FFI::FOREIGN-TYPE foreign-variable) */
  var object fvar = popSTACK();
  if (!fvariablep(fvar))
    error_foreign_variable(fvar);
  if (nullp((value1 = TheFvariable(fvar)->fv_type)))
    error_variable_no_fvd(fvar);
  mv_count=1;
}

/* (FFI::%ELEMENT foreign-array-variable {index}*)
 returns a foreign variable, corresponding to the specified array element. */
LISPFUN(element,seclass_default,1,0,rest,nokey,0,NIL)
{
  var object fvar = Before(rest_args_pointer);
  /* Check that fvar is a foreign variable: */
  if (!fvariablep(fvar))
    error_foreign_variable(fvar);
  /* Check that fvar is a foreign array: */
  var object fvd = TheFvariable(fvar)->fv_type;
  var uintL fvdlen;
  if (!(simple_vector_p(fvd)
        && ((fvdlen = Svector_length(fvd)) > 1)
        && (eq(TheSvector(fvd)->data[0],S(c_array))
            || eq(TheSvector(fvd)->data[0],S(c_array_max))))) {
    dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
    pushSTACK(fvd);
    pushSTACK(fvar);
    pushSTACK(S(element));
    error(error_condition,GETTEXT("~S: foreign variable ~S of type ~S is not an array"));
  }
  /* Check the subscript count: */
  if (!(argcount == fvdlen-2)) {
    pushSTACK(fixnum(fvdlen-2));
    pushSTACK(fvar);
    pushSTACK(fixnum(argcount));
    pushSTACK(S(element));
    error(error_condition,GETTEXT("~S: got ~S subscripts, but ~S has rank ~S"));
  }
  /* Check the subscripts: */
  var uintL row_major_index = 0;
  if (argcount > 0) {
    var gcv_object_t* args_pointer = rest_args_pointer;
    var gcv_object_t* dimptr = &TheSvector(fvd)->data[2];
    var uintC count = argcount;
    do {
      var object subscriptobj = NEXT(args_pointer);
      if (!posfixnump(subscriptobj)) {
        var object list = listof(argcount);
        /* STACK_0 is fvar now. */
        pushSTACK(list);
        pushSTACK(S(element));
        error(error_condition,GETTEXT("~S: subscripts ~S for ~S are not of type `(INTEGER 0 (,ARRAY-DIMENSION-LIMIT))"));
      }
      var uintV subscript = posfixnum_to_V(subscriptobj);
      var uintL dim = I_to_uint32(*dimptr);
      if (!(subscript<dim)) {
        var object list = listof(argcount);
        /* STACK_0 is fvar now. */
        pushSTACK(list);
        pushSTACK(S(element));
        error(error_condition,GETTEXT("~S: subscripts ~S for ~S are out of range"));
      }
      /* Compute row_major_index := row_major_index*dim+subscript: */
      row_major_index = mulu32_unchecked(row_major_index,dim)+subscript;
      dimptr++;
    } while (--count);
  }
  set_args_end_pointer(rest_args_pointer);
  fvd = TheSvector(fvd)->data[1]; /* the element's foreign type */
  pushSTACK(fvd);
  var uintL size = foreign_size(fvd); /* the element's size */
  pushSTACK(make_faddress(TheFaddress(TheFvariable(fvar)->fv_address)->fa_base,
                          TheFaddress(TheFvariable(fvar)->fv_address)->fa_offset
                          + row_major_index * size));
  var object new_fvar = allocate_fvariable();
  fvar = STACK_2;
  record_flags_replace(TheFvariable(new_fvar), record_flags(TheFvariable(fvar)));
  TheFvariable(new_fvar)->fv_name    = NIL; /* no name known */
  TheFvariable(new_fvar)->fv_address = popSTACK();
  TheFvariable(new_fvar)->fv_size    = fixnum(size);
  TheFvariable(new_fvar)->fv_type    = popSTACK();
  VALUES1(new_fvar);
  skipSTACK(1);
}

/* (FFI::%DEREF foreign-pointer-variable)
 returns a foreign variable, corresponding to what the specified pointer
 points to. */
LISPFUNN(deref,1)
{
  var object fvar = STACK_0;
  /* Check that fvar is a foreign variable: */
  if (!fvariablep(fvar)) error_foreign_variable(fvar);
  /* Check that fvar is a foreign pointer: */
  var object fvd = TheFvariable(fvar)->fv_type;
  if (!(simple_vector_p(fvd)
        && (Svector_length(fvd) == 2)
        && (eq(TheSvector(fvd)->data[0],S(c_ptr))
            || eq(TheSvector(fvd)->data[0],S(c_ptr_null))
            || eq(TheSvector(fvd)->data[0],S(c_pointer))))) {
    dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
    pushSTACK(fvd);
    pushSTACK(fvar);
    pushSTACK(S(element));
    error(error_condition,GETTEXT("~S: foreign variable ~S of type ~S is not a pointer"));
  }
  fvd = TheSvector(fvd)->data[1]; /* the target's foreign type */
  pushSTACK(fvd);
  var uintL size = foreign_size(fvd); /* the target's size */
  var object fa = TheFvariable(fvar)->fv_address;
  fa = check_faddress_valid(fa);
  /* Actually dereference the pointer: */
  var void* address = *(void**)Faddress_value(fa);
  if (address == NULL) {
    /* Don't mess with NULL pointers, return NIL instead. */
    VALUES1(NIL); skipSTACK(2);
  } else {
    pushSTACK(make_faddress(O(fp_zero),(uintP)address));
    var object new_fvar = allocate_fvariable();
    fvar = STACK_2;
    record_flags_replace(TheFvariable(new_fvar),
                         record_flags(TheFvariable(fvar)));
    TheFvariable(new_fvar)->fv_name    = NIL; /* no name known */
    TheFvariable(new_fvar)->fv_address = popSTACK();
    TheFvariable(new_fvar)->fv_size    = fixnum(size);
    TheFvariable(new_fvar)->fv_type    = popSTACK();
    VALUES1(new_fvar);
    skipSTACK(1);
  }
}

/* (FFI::%SLOT foreign-struct/union-variable slot-name)
 returns a foreign variable, corresponding to the specified struct slot or
 union alternative. */
LISPFUNN(slot,2)
{
  var object fvar = STACK_1;
  var object slot = STACK_0;
  /* Check that fvar is a foreign variable: */
  if (!fvariablep(fvar))
    error_foreign_variable(fvar);
  /* Check that fvar is a foreign struct or a foreign union: */
  var object fvd = TheFvariable(fvar)->fv_type;
  var uintL fvdlen;
  var struct foreign_layout sas;
  if (simple_vector_p(fvd) && ((fvdlen = Svector_length(fvd)) > 0)) {
    if (eq(TheSvector(fvd)->data[0],S(c_struct))
        && (fvdlen >= C_STRUCT_C_TYPE_START)) {
      var object slots = TheSvector(fvd)->data[C_STRUCT_SLOTS];
      if (!(simple_vector_p(slots)
            && (Svector_length(slots)==fvdlen-C_STRUCT_C_TYPE_START)))
        error_foreign_type(fvd);
      var uintL cumul_size = 0;
      var uintL i;
      for (i = C_STRUCT_C_TYPE_START; i < fvdlen; i++) {
        var object fvdi = TheSvector(fvd)->data[i];
        foreign_layout(fvdi,&sas);
        /* We assume all alignments are of the form 2^k. */
        cumul_size += (-cumul_size) & (sas.alignment-1);
        if (eq(TheSvector(slots)->data[i-C_STRUCT_C_TYPE_START],slot)) {
          pushSTACK(fvdi); goto found_struct_slot;
        }
        cumul_size += sas.size;
      }
      goto bad_slot;
     found_struct_slot: {
        var uintL size = sas.size;
        pushSTACK(make_faddress(TheFaddress(TheFvariable(fvar)->fv_address)->fa_base,
                                TheFaddress(TheFvariable(fvar)->fv_address)->fa_offset
                                + cumul_size));
        var object new_fvar = allocate_fvariable();
        fvar = STACK_3;
        record_flags_replace(TheFvariable(new_fvar), record_flags(TheFvariable(fvar)));
        TheFvariable(new_fvar)->fv_name    = NIL; /* no name known */
        TheFvariable(new_fvar)->fv_address = popSTACK();
        TheFvariable(new_fvar)->fv_size    = fixnum(size);
        TheFvariable(new_fvar)->fv_type    = popSTACK();
        VALUES1(new_fvar);
        skipSTACK(2);
        return;
      }
    }
    if (eq(TheSvector(fvd)->data[0],S(c_union)) && (fvdlen > 1)) {
      var object slots = TheSvector(fvd)->data[1];
      if (!(simple_vector_p(slots) && (Svector_length(slots)==fvdlen-2)))
        error_foreign_type(fvd);
      var uintL i;
      for (i = 2; i < fvdlen; i++) {
        if (eq(TheSvector(slots)->data[i-2],slot))
          goto found_union_slot;
      }
      goto bad_slot;
     found_union_slot:
      pushSTACK(TheSvector(fvd)->data[i]);
      var object new_fvar = allocate_fvariable();
      fvd = popSTACK(); /* the alternative's type */
      fvar = STACK_1;
      record_flags_replace(TheFvariable(new_fvar),
                           record_flags(TheFvariable(fvar)));
      TheFvariable(new_fvar)->fv_name    = NIL; /* no name known */
      TheFvariable(new_fvar)->fv_address = TheFvariable(fvar)->fv_address;
      TheFvariable(new_fvar)->fv_size    = fixnum(foreign_size(fvd));
      TheFvariable(new_fvar)->fv_type    = fvd;
      VALUES1(new_fvar);
      skipSTACK(2);
      return;
    }
  }
  dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
  pushSTACK(fvd);
  pushSTACK(fvar);
  pushSTACK(S(slot));
  error(error_condition,GETTEXT("~S: foreign variable ~S of type ~S is not a struct or union"));
 bad_slot:
  dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T  */
  pushSTACK(slot);
  pushSTACK(fvd);
  pushSTACK(fvar);
  pushSTACK(S(slot));
  error(error_condition,GETTEXT("~S: foreign variable ~S of type ~S has no component with name ~S"));
}

/* (FFI::%CAST foreign-variable c-type)
 returns a foreign variable, referring to the same memory locations, but of
 the given c-type. */
LISPFUNN(cast,2)
{
  var object fvar = STACK_1;
  if (!fvariablep(fvar))
    error_foreign_variable(fvar);
  var object fvd = TheFvariable(fvar)->fv_type;
  if (nullp(fvd))
    error_variable_no_fvd(fvar);
  /* The old and the new type must have the same size. */
  if (!eq(TheFvariable(fvar)->fv_size,fixnum(foreign_size(STACK_0))))
    error_convert(STACK_0,fvar);
  /* Allocate a new foreign variable. */
  var object new_fvar = allocate_fvariable();
  fvar = STACK_1;
  record_flags_replace(TheFvariable(new_fvar),
                       record_flags(TheFvariable(fvar)));
  TheFvariable(new_fvar)->fv_name    = TheFvariable(fvar)->fv_name;
  TheFvariable(new_fvar)->fv_address = TheFvariable(fvar)->fv_address;
  TheFvariable(new_fvar)->fv_size    = TheFvariable(fvar)->fv_size;
  TheFvariable(new_fvar)->fv_type    = STACK_0;
  VALUES1(new_fvar);
  skipSTACK(2);
}

/* (FFI::%OFFSET foreign-variable offset c-type)
 returns a foreign variable, referring to (memory-location + offset),
 of the given c-type.
 This is lower-level than FFI::%SLOT and more general than FFI::%CAST.
 It allows dynamic resizing of arrays,
 e.g. (C-ARRAY uint8 <N>) to (C-ARRAY uint8 <M>). */
LISPFUNN(offset,3) {
  var object fvar = STACK_2;
  if (!fvariablep(fvar))
    error_foreign_variable(fvar);
  {
    var object fvd = TheFvariable(fvar)->fv_type;
    if (nullp(fvd))
      error_variable_no_fvd(fvar);
  }
  STACK_1 = check_sint32(STACK_1);
  var struct foreign_layout sas;
  foreign_layout(STACK_0,&sas);
  fvar = STACK_2;
  var uintL size = sas.size;
  var uintL alignment = sas.alignment;
  { /* Allocate a new foreign address. */
    var object fvaddr = TheFvariable(fvar)->fv_address;
    fvaddr = make_faddress(TheFaddress(fvaddr)->fa_base,
                           TheFaddress(fvaddr)->fa_offset
                           + (sintP)I_to_sint32(STACK_1));
    pushSTACK(fvaddr);
  }
  /* Allocate a new foreign variable. */
  var object new_fvar = allocate_fvariable();
  fvar = STACK_(2+1);
  record_flags_replace(TheFvariable(new_fvar),
                       record_flags(TheFvariable(fvar)));
  TheFvariable(new_fvar)->fv_name    = TheFvariable(fvar)->fv_name;
  TheFvariable(new_fvar)->fv_address = STACK_0;
  TheFvariable(new_fvar)->fv_size    = fixnum(size);
  TheFvariable(new_fvar)->fv_type    = STACK_(0+1);
  check_fvar_alignment(new_fvar,alignment);
  VALUES1(new_fvar);
  skipSTACK(3+1);
}


/* Low-level, little consing accessors */

/* (FFI:MEMORY-AS address ffi-type &optional byte-offset)
   a low-level, little-consing accessor to memory, in effect
   similar to (foreign-value (foreign-variable address type)) */
LISPFUN(read_memory_as,seclass_default,2,1,norest,nokey,0,NIL)
{
  /* TODO accept foreign_pointer as well, without consing */
  /* TODO refuse foreign-function */
  var object fp = check_faddress_valid(foreign_address(STACK_2,false));
  var void* address = Faddress_value(fp);
  if (!missingp(STACK_0)) {
    STACK_0 = check_sint32(STACK_0);
    address = (void*)((uintP)address + (sintP)I_to_sint32(STACK_0));
  }
  /* TODO asciz_to_string is not suitable for unicode */
  var object item = eq(STACK_1,S(string))
        ? asciz_to_string((char*)address,O(foreign_encoding))
        : convert_from_foreign(STACK_1,address);
  VALUES1(item); skipSTACK(3);
}

/* (FFI::WRITE-MEMORY-AS value address type &optional byte-offset) */
LISPFUN(write_memory_as,seclass_default,3,1,norest,nokey,0,NIL)
{
  var object fp = check_faddress_valid(foreign_address(STACK_2,false));
  var void* address = Faddress_value(fp);
  if (!missingp(STACK_0)) {
    STACK_0 = check_sint32(STACK_0);
    address = (void*)((uintP)address + (sintP)I_to_sint32(STACK_0));
  }
  convert_to_foreign(STACK_1,STACK_3,address,&nomalloc,NULL);
  VALUES1(STACK_3); skipSTACK(4);
}

/* Stack-allocated objects */

/* (FFI::EXEC-ON-STACK thunk fvd [initarg]) allocates foreign objects
 on the C stack and executes (funcall thunk (foreign-variable-on-stack)).
 Calling with initarg is radically different than without one.
 With an initarg, CLISP allocates an arbitrarily complex structure on the
 stack. Without one, all it does is like a single calloc(1,sizeof(fvd))! */
LISPFUN(exec_on_stack,seclass_default,2,1,norest,nokey,0,NIL) {
  STACK_2 = check_function(STACK_2);
  var bool init = boundp(STACK_0); /* Passing NIL is also an initialization */
  var object fvd = STACK_1;
  var struct foreign_layout sas;
  foreign_layout(fvd,&sas);
  /* Room for top-level structure: */
  var uintL result_size = sas.size;
  var uintL result_alignment = sas.alignment;
  var uintL cumul_size = result_size;
  var uintL cumul_alignment = result_alignment;
  cumul_size += (-cumul_size) & (cumul_alignment-1);
  if (init) {
    /* Room for pointers in argument: */
    convert_to_foreign_needs(fvd,STACK_0,&sas);
    fvd = STACK_1;
    /* We assume all alignments are of the form 2^k. */
    cumul_size += (-cumul_size) & (sas.alignment-1);
    cumul_size += sas.size;
    /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
    if (sas.alignment > cumul_alignment)
      cumul_alignment = sas.alignment;
  }
  var DYNAMIC_ARRAY(total_room,char,cumul_size+cumul_alignment/*-1*/);
  var void* result_address = (void*)((uintP)(total_room+result_alignment-1)
                                     & -(long)result_alignment);
  if (init) {
    void *allocaing_room_pointer = (void*)((uintP)result_address + result_size);
    convert_to_foreign(fvd,STACK_0,result_address,&allocaing,
                       &allocaing_room_pointer);
  } else {
    blockzero(result_address,result_size);
  }
  STACK_0 = allocate_fpointer(result_address); /* Release initarg early */
  pushSTACK(make_faddress(STACK_0,0));
  /* Stack layout: thunk fvd fp fa. */
  var object fvar = allocate_fvariable();
  TheFvariable(fvar)->fv_name    = Symbol_name(TheSubr(subr_self)->name);
  TheFvariable(fvar)->fv_address = popSTACK();
  var object fp_obj = popSTACK();
  TheFvariable(fvar)->fv_size    = fixnum(result_size);
  TheFvariable(fvar)->fv_type    = STACK_0;
  record_flags_replace(TheFvariable(fvar), 0); /* TODO needed? */
  var object thunk = STACK_1;
  STACK_1 = fp_obj; skipSTACK(1);
  { var gcv_object_t* top_of_frame = STACK;
    var sp_jmp_buf returner; /* return point */
    finish_entry_frame(UNWIND_PROTECT,returner,, goto clean_up; );
  }
  pushSTACK(fvar); funcall(thunk,1); /* protected: (funcall thunk fvar) */
  /* normal clean-up: */
  skipSTACK(2); /* unwind UNWIND-PROTECT-frame */
  fp_obj = popSTACK();
  mark_fp_invalid(TheFpointer(fp_obj));
  FREE_DYNAMIC_ARRAY(total_room);
  return;
 clean_up: {
    var restartf_t fun = unwind_protect_to_save.fun;
    var gcv_object_t* arg = unwind_protect_to_save.upto_frame;
    skipSTACK(2); /* unwind UNWIND-PROTECT-frame */
    fp_obj = popSTACK();
    mark_fp_invalid(TheFpointer(fp_obj));
    FREE_DYNAMIC_ARRAY(total_room);
    fun(arg); /* jump further */
  }
  /* values, mv_count are set by funcall */
}

/* (FFI::CALL-WITH-FOREIGN-STRING thunk encoding string start end extra-zeroes)
 Allocate string on stack, converted according to encoding and
 invoke (funcall thunk foreign-address charsize bytesize).
 Allows to allocate many zero bytes (like a partially filled buffer) */
LISPFUNN(call_with_foreign_string,6)
{
  var uintV zeroes = posfixnum_to_V(check_posfixnum(popSTACK()));
  STACK_4 = check_function(STACK_4);
 #ifdef ENABLE_UNICODE
  STACK_3 = check_encoding(STACK_3,&O(foreign_encoding),false);
 #else
  STACK_3 = check_encoding(STACK_3,&O(default_file_encoding),false);
 #endif
  /* Stack layout: ... string start end. - as needed for test_limits
     the following code inspired by with_string() and substring(): */
  var stringarg arg;
  test_string_limits_ro(&arg);
  var object data_array = arg.string;
  /* Stack: ... thunk encoding. - string, start and end were popped off */
  var const chart* srcptr;
  unpack_sstring_alloca(data_array,arg.len, arg.offset+arg.index, srcptr=);
  var object encoding = STACK_0;
  var uintL charsize = arg.len;
  var uintL bytesize = cslen(encoding,srcptr,charsize);
  var DYNAMIC_ARRAY(stack_data,uintB,bytesize+zeroes);
  if (bytesize>0)
    cstombs(encoding,srcptr,charsize,&stack_data[0],bytesize);
  if (zeroes != 0) { /* add terminating zero bytes */
    do { stack_data[bytesize++] = 0; } while (--zeroes > 0);
    charsize++;
  }
  { var object pointer_base = allocate_fpointer((void*)&stack_data[0]);
    pushSTACK(pointer_base);
    var gcv_object_t* top_of_frame = STACK;
    var sp_jmp_buf returner;
    finish_entry_frame(UNWIND_PROTECT,returner,, {
      /* UNWIND-PROTECT case: (MARK-INVALID-FOREIGN pointer_base) */
      var restartf_t fun = unwind_protect_to_save.fun;
      var gcv_object_t* upto = unwind_protect_to_save.upto_frame;
      skipSTACK(2); /* unwind Unwind-Protect-Frame */
      pointer_base = popSTACK();
      mark_fp_invalid(TheFpointer(pointer_base));
      fun(upto); /* and jump ahead */
      NOTREACHED;
    });
    pushSTACK(make_faddress(pointer_base,0));
    pushSTACK(fixnum(charsize));
    pushSTACK(fixnum(bytesize));
    funcall(STACK_(1+1+2+3),3);
    skipSTACK(2); /* unwind UNWIND-PROTECT frame */
    pointer_base = popSTACK();
    mark_fp_invalid(TheFpointer(pointer_base));
  }
  FREE_DYNAMIC_ARRAY(stack_data);
  skipSTACK(2);
}

/* (FFI:FOREIGN-ALLOCATE c-type &key initial-contents count read-only)
 Allocates memory. If initial-contents is set (even NIL), invokes
 convert_from_foreign() to allocate an arbitrarily nested structure.
 Otherwise performs a single calloc(). */
LISPFUN(foreign_allocate,seclass_default,1,0,norest,key,3,
        (kw(initial_contents),kw(count),kw(read_only)))
{
  var object arg_fvd = STACK_3;
  /* If :COUNT then use c-type (C-ARRAY[-MAX] c-type count) */
  if (!missingp(STACK_1)) {
    var object array_fvd = allocate_vector(3);
    TheSvector(array_fvd)->data[0] =
      eq(arg_fvd,S(character)) ? S(c_array_max) : S(c_array);
    TheSvector(array_fvd)->data[1] = arg_fvd;
    TheSvector(array_fvd)->data[2] = STACK_1; /* count */
    STACK_3 = arg_fvd = array_fvd;
  }
  var struct foreign_layout sas;
  foreign_layout(arg_fvd,&sas);
  var uintL arg_size = sas.size;
  var uintL arg_alignment = sas.alignment;
  if (arg_size == 0) { error_eltype_zero_size(arg_fvd); }
  /* Perform top-level allocation of sizeof(fvd), sublevel allocations follow */
  var void* arg_address = clisp_malloc(arg_size);
  blockzero(arg_address,arg_size);
  /* Create FOREIGN-VARIABLE now so that it may be used in error message */
  pushSTACK(make_faddress(allocate_fpointer(arg_address),0));
  var object fvar = allocate_fvariable();
  arg_fvd = STACK_(3+1);
  TheFvariable(fvar)->fv_name    = TheSubr(subr_self)->name;
  TheFvariable(fvar)->fv_address = STACK_0;
  TheFvariable(fvar)->fv_size    = fixnum(arg_size);
  TheFvariable(fvar)->fv_type    = arg_fvd;
  { var bool readonly = !missingp(STACK_1);
    record_flags_replace(TheFvariable(fvar), readonly ? fv_readonly : 0);
    /* Must not set fv_malloc flag since it applies
       to sublevel structures only. */
  }
  check_fvar_alignment(fvar,arg_alignment);
  { /* :INITIAL-CONTENTS NIL also causes an initialization! */
    var object initarg = STACK_3;
    if (boundp(initarg)) {
      STACK_0 = fvar;
      convert_to_foreign(arg_fvd,initarg,arg_address,&mallocing,NULL);
      /* subr-self name is lost and GC may happen */
      fvar = STACK_0;
    }
  }
  /* Must not finalize foreign-pointer since some protocol (witness the
     :malloc parameter declaration) may require foreign code to call free()
     However, CormanLisp does finalize! */
  VALUES1(fvar);
  skipSTACK(5);
}

/* (FFI:FOREIGN-FREE foreign &key full)
 Deallocate callbacks or memory (even recursively),
 depending on argument type. */
LISPFUN(foreign_free,seclass_default,1,0,norest,key,1,(kw(full)))
{
  var object obj = popSTACK();
  var bool full_recurse = !missingp(obj);
  /* TODO? additional arguments [mark-invalid [silent]] */
  obj = popSTACK();
  if (orecordp(obj)) {
    var void* address;
    switch (Record_type(obj)) {
      case Rectype_Ffunction: { /* Free callback object */
        var object addr_obj = TheFfunction(obj)->ff_address;
        addr_obj = check_faddress_valid(addr_obj);
        address = Faddress_value(addr_obj);
        free_foreign_callin(address);
        /* make the function invalid */
        pushSTACK(addr_obj);
        var object fp = allocate_fpointer(address);
        TheFaddress(STACK_0)->fa_base = fp;
        TheFaddress(STACK_0)->fa_offset = 0;
        mark_fp_invalid(TheFpointer(TheFaddress(popSTACK())->fa_base));
        VALUES1(NIL);
        return;
      }
      case Rectype_Fvariable: {
        var object addr_obj = TheFvariable(obj)->fv_address;
        pushSTACK(obj);
        addr_obj = check_faddress_valid(addr_obj);
        obj = popSTACK();
        address = Faddress_value(addr_obj);
        if (full_recurse)
          free_foreign(TheFvariable(obj)->fv_type,address);
        goto free_address;
      }
      case Rectype_Faddress:
        obj = check_faddress_valid(obj);
        address = Faddress_value(obj);
        if (full_recurse) {
          pushSTACK(obj);
          pushSTACK(TheSubr(subr_self)->name);
          error(error_condition,GETTEXT("~S: ~S has no type, :FULL is illegal"));
        }
      free_address:
        begin_system_call();
        free(address);
        end_system_call();
        VALUES1(NIL);
        return;
    }
  }
  error_foreign_object(obj);
}

/* Error messages. */
nonreturning_function(local, error_foreign_function, (object obj)) {
  pushSTACK(NIL);                 /* no PLACE */
  pushSTACK(obj);                 /* TYPE-ERROR slot DATUM */
  pushSTACK(S(foreign_function)); /* TYPE-ERROR slot EXPECTED-TYPE */
  pushSTACK(STACK_0); pushSTACK(obj);
  pushSTACK(TheSubr(subr_self)->name);
  error(type_error,GETTEXT("~S: ~S is not of type ~S"));
}
nonreturning_function(local, error_function_no_fvd,
                      (object obj, object caller)) {
  pushSTACK(obj);
  pushSTACK(caller);
  error(error_condition,GETTEXT("~S: foreign function with unknown calling convention, missing DEF-CALL-OUT: ~S"));
}

/* UP: looks up a foreign function, given its Lisp name.
 can trigger GC */
local maygc object lookup_foreign_function
(gcv_object_t *name_, gcv_object_t *fvd_, gcv_object_t *properties_) {
  var object ffun = allocate_ffunction();
  var object props = *properties_;
  var object fvd = *fvd_;
  var object name = *name_;
  var object oldffun = gethash(name,O(foreign_function_table),false);
  if (eq(oldffun,nullobj)) {
    pushSTACK(NIL);             /* 4 continue-format-string */
    pushSTACK(S(error));        /* 3 error type */
    pushSTACK(NIL);             /* 2 error-format-string */
    pushSTACK(TheSubr(subr_self)->name); /* 1 */
    pushSTACK(name);            /* 0 */
    STACK_2 = CLSTEXT("~S: foreign function ~S does not exist");
    STACK_4 = CLSTEXT("Skip foreign function creation");
    funcall(L(cerror_of_type),5);
    return NIL;
  }
  if (!eq(TheFfunction(oldffun)->ff_flags,TheSvector(fvd)->data[3])) {
    pushSTACK(oldffun);
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: calling conventions for foreign function ~S conflict"));
  }
  TheFfunction(ffun)->ff_name = TheFfunction(oldffun)->ff_name;
  TheFfunction(ffun)->ff_address = TheFfunction(oldffun)->ff_address;
  TheFfunction(ffun)->ff_resulttype = TheSvector(fvd)->data[1];
  TheFfunction(ffun)->ff_argtypes = TheSvector(fvd)->data[2];
  TheFfunction(ffun)->ff_flags = TheSvector(fvd)->data[3];
  TheFfunction(ffun)->ff_properties = props;
  return ffun;
}

/* forvard declaration -- defined later */
local maygc object foreign_library_function
(gcv_object_t *name, gcv_object_t *fvd, gcv_object_t *properties,
 gcv_object_t *library, gcv_object_t *version, gcv_object_t *offset);

/* (FFI::FIND-FOREIGN-FUNCTION foreign-function-name foreign-type properties
     foreign-library version foreign-offset) */
LISPFUNN(find_foreign_function,6) {
  STACK_5 = coerce_ss(STACK_5); /* name */
  STACK_4 = check_foreign_function_type(STACK_4); /* type */
  if (nullp(STACK_2)) { /* library */
    if (!nullp(STACK_1)) /* version */
      error_version_nonlibrary(STACK_5,STACK_1);
    VALUES1(lookup_foreign_function(&STACK_5,&STACK_4,&STACK_3));
  } else VALUES1(foreign_library_function(&STACK_5,&STACK_4,&STACK_3,
                                          &STACK_2,&STACK_1,&STACK_0));
  skipSTACK(6);
}

/* Here is the point where we use the AVCALL package. */

/* Call the appropriate av_start_xxx macro for the result.
 do_av_start(flags,result_fvd,&alist,address,result_address,
             result_size,result_splittable); */
local void do_av_start (uintWL flags, object result_fvd, av_alist *alist,
                        void *address, void *result_address, uintL result_size,
                        bool result_splittable)
{
  if (symbolp(result_fvd)) {
    if (eq(result_fvd,S(nil))) {
      av_start_void(*alist,address);
    } else if (eq(result_fvd,S(char)) || eq(result_fvd,S(sint8))) {
      if (flags & ff_lang_ansi_c) {
        av_start_schar(*alist,address,result_address);
      } else { /* `signed char' promotes to `int' */
        av_start_int(*alist,address,result_address);
      }
    } else if (eq(result_fvd,S(uchar)) || eq(result_fvd,S(uint8))
               || eq(result_fvd,S(character))) {
      if (flags & ff_lang_ansi_c) {
        av_start_uchar(*alist,address,result_address);
      } else { /* `unsigned char' promotes to `unsigned int' */
        av_start_uint(*alist,address,result_address);
      }
    } else if (eq(result_fvd,S(short)) || eq(result_fvd,S(sint16))) {
      if (flags & ff_lang_ansi_c) {
        av_start_short(*alist,address,result_address);
      } else { /* `short' promotes to `int' */
        av_start_int(*alist,address,result_address);
      }
    } else if (eq(result_fvd,S(ushort)) || eq(result_fvd,S(uint16))) {
      if (flags & ff_lang_ansi_c) {
        av_start_ushort(*alist,address,result_address);
      } else { /* `unsigned short' promotes to `unsigned int' */
        av_start_uint(*alist,address,result_address);
      }
    } else if (eq(result_fvd,S(boolean)) || eq(result_fvd,S(int))
              #if (int_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
               ) {
      av_start_int(*alist,address,result_address);
    } else if (eq(result_fvd,S(uint))
              #if (int_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
               ) {
      av_start_uint(*alist,address,result_address);
    } else if (eq(result_fvd,S(long))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(sint64))
              #endif
               ) {
      av_start_long(*alist,address,result_address);
    } else if (eq(result_fvd,S(ulong))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(uint64))
              #endif
               ) {
      av_start_ulong(*alist,address,result_address);
    }
   #if (long_bitsize<64)
    #if defined(HAVE_LONG_LONG_INT)
    else if (eq(result_fvd,S(sint64))) {
      av_start_longlong(*alist,address,result_address);
    } else if (eq(result_fvd,S(uint64))) {
      av_start_ulonglong(*alist,address,result_address);
    }
    #else
    else if (eq(result_fvd,S(sint64))) {
      av_start_struct(*alist,address,struct_sint64,
                      av_word_splittable_2(sint32,sint32),result_address);
    } else if (eq(result_fvd,S(uint64))) {
      av_start_struct(*alist,address,struct_uint64,
                      av_word_splittable_2(uint32,uint32),result_address);
    }
    #endif
   #endif
    else if (eq(result_fvd,S(single_float))) {
      if (flags & ff_lang_ansi_c) {
        av_start_float(*alist,address,result_address);
      } else { /* `float' promotes to `double' */
        av_start_double(*alist,address,result_address);
      }
    } else if (eq(result_fvd,S(double_float))) {
      av_start_double(*alist,address,result_address);
    } else if (eq(result_fvd,S(c_pointer)) || eq(result_fvd,S(c_string))) {
      av_start_ptr(*alist,address,void*,result_address);
    } else {
      error_foreign_type(result_fvd);
    }
  } else if (simple_vector_p(result_fvd)) {
    var object result_fvdtype = TheSvector(result_fvd)->data[0];
    if (eq(result_fvdtype,S(c_struct)) || eq(result_fvdtype,S(c_union))
        || eq(result_fvdtype,S(c_array)) || eq(result_fvdtype,S(c_array_max))) {
      _av_start_struct(*alist,address,result_size,result_splittable,
                       result_address);
    } else if (eq(result_fvdtype,S(c_function))
               || eq(result_fvdtype,S(c_ptr))
               || eq(result_fvdtype,S(c_ptr_null))
               || eq(result_fvdtype,S(c_pointer))
               || eq(result_fvdtype,S(c_array_ptr))) {
      av_start_ptr(*alist,address,void*,result_address);
    } else {
      error_foreign_type(result_fvd);
    }
  } else {
    object inttype = gethash(result_fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      do_av_start (flags, inttype, alist, address, result_address,
                   result_size, result_splittable);
    else error_foreign_type(result_fvd);
  }
  if (flags & ff_lang_stdcall)
    alist->flags |= __AV_STDCALL_CLEANUP;
}

/* Call the appropriate av_xxx macro for an argument.
 do_av_arg(flags,arg_fvd,&alist,arg_address,arg_size,arg_alignment); */
local void do_av_arg (uintWL flags, object arg_fvd, av_alist * alist,
                      void* arg_address, unsigned long arg_size,
                      unsigned long arg_alignment)
{
  if (symbolp(arg_fvd)) {
    if (eq(arg_fvd,S(nil))) {
    } else if (eq(arg_fvd,S(char)) || eq(arg_fvd,S(sint8))) {
      if (flags & ff_lang_ansi_c) {
        av_schar(*alist,*(sint8*)arg_address);
      } else { /* `signed char' promotes to `int' */
        av_int(*alist,*(sint8*)arg_address);
      }
    } else if (eq(arg_fvd,S(uchar)) || eq(arg_fvd,S(uint8))
               || eq(arg_fvd,S(character))) {
      if (flags & ff_lang_ansi_c) {
        av_uchar(*alist,*(uint8*)arg_address);
      } else { /* `unsigned char' promotes to `unsigned int' */
        av_uint(*alist,*(uint8*)arg_address);
      }
    } else if (eq(arg_fvd,S(short)) || eq(arg_fvd,S(sint16))) {
      if (flags & ff_lang_ansi_c) {
        av_short(*alist,*(sint16*)arg_address);
      } else { /* `short' promotes to `int' */
        av_int(*alist,*(sint16*)arg_address);
      }
    } else if (eq(arg_fvd,S(ushort)) || eq(arg_fvd,S(uint16))) {
      if (flags & ff_lang_ansi_c) {
        av_ushort(*alist,*(uint16*)arg_address);
      } else { /* `unsigned short' promotes to `unsigned int' */
        av_uint(*alist,*(uint16*)arg_address);
      }
    } else if (eq(arg_fvd,S(boolean)) || eq(arg_fvd,S(int))
              #if (int_bitsize==32)
               || eq(arg_fvd,S(sint32))
              #endif
               ) {
      av_int(*alist,*(int*)arg_address);
    } else if (eq(arg_fvd,S(uint))
              #if (int_bitsize==32)
               || eq(arg_fvd,S(uint32))
              #endif
               ) {
      av_uint(*alist,*(unsigned int *)arg_address);
    } else if (eq(arg_fvd,S(long))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(arg_fvd,S(sint32))
              #endif
              #if (long_bitsize==64)
               || eq(arg_fvd,S(sint64))
              #endif
               ) {
      av_long(*alist,*(long*)arg_address);
    } else if (eq(arg_fvd,S(ulong))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(arg_fvd,S(uint32))
              #endif
              #if (long_bitsize==64)
               || eq(arg_fvd,S(uint64))
              #endif
               ) {
      av_ulong(*alist,*(unsigned long *)arg_address);
    }
   #if (long_bitsize<64)
    #if defined(HAVE_LONG_LONG_INT)
    else if (eq(arg_fvd,S(sint64))) {
      av_longlong(*alist,*(sint64*)arg_address);
    } else if (eq(arg_fvd,S(uint64))) {
      av_ulonglong(*alist,*(uint64*)arg_address);
    }
    #else
    else if (eq(arg_fvd,S(sint64))) {
      av_struct(*alist,struct_sint64,*(struct_sint64*)arg_address);
    } else if (eq(arg_fvd,S(uint64))) {
      av_struct(*alist,struct_uint64,*(struct_uint64*)arg_address);
    }
    #endif
   #endif
    else if (eq(arg_fvd,S(single_float))) {
      if (flags & ff_lang_ansi_c) {
        av_float(*alist,*(float*)arg_address);
      } else { /* `float' promotes to `double' */
        av_double(*alist,*(float*)arg_address);
      }
    } else if (eq(arg_fvd,S(double_float))) {
      av_double(*alist,*(double*)arg_address);
    } else if (eq(arg_fvd,S(c_pointer))) {
      av_ptr(*alist,void*,*(void**)arg_address);
    } else if (eq(arg_fvd,S(c_string))) {
      av_ptr(*alist,char*,*(char**)arg_address);
    } else {
      error_foreign_type(arg_fvd);
    }
  } else if (simple_vector_p(arg_fvd)) {
    var object arg_fvdtype = TheSvector(arg_fvd)->data[0];
    if (eq(arg_fvdtype,S(c_struct)) || eq(arg_fvdtype,S(c_union))
        || eq(arg_fvdtype,S(c_array)) || eq(arg_fvdtype,S(c_array_max))) {
      _av_struct(*alist,arg_size,arg_alignment,arg_address);
    } else if (eq(arg_fvdtype,S(c_function))
               || eq(arg_fvdtype,S(c_ptr))
               || eq(arg_fvdtype,S(c_ptr_null))
               || eq(arg_fvdtype,S(c_pointer))
               || eq(arg_fvdtype,S(c_array_ptr))) {
      av_ptr(*alist,void*,*(void**)arg_address);
    } else {
      error_foreign_type(arg_fvd);
    }
  } else {
    object inttype = gethash(arg_fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      do_av_arg (flags, inttype, alist, arg_address, arg_size, arg_alignment);
    else error_foreign_type(arg_fvd);
  }
}

/* (FFI::FOREIGN-CALL-OUT foreign-function . args)
 calls a foreign function with Lisp data structures as arguments,
 and returns the return value as a Lisp data structure. */
LISPFUN(foreign_call_out,seclass_default,1,0,rest,nokey,0,NIL) {
  var object ffun = Before(rest_args_pointer);
  if (!ffunctionp(ffun))
    error_foreign_function(ffun);
  var object argfvds_top = TheFfunction(ffun)->ff_argtypes;
  if (!simple_vector_p(argfvds_top))
    error_function_no_fvd(ffun,S(foreign_call_out));
  var uintWL flags = posfixnum_to_V(TheFfunction(ffun)->ff_flags);
  switch (flags & 0x7F00) {
    /* For the moment, the only supported languages are "C" and "ANSI C". */
    case ff_lang_c:
    case ff_lang_ansi_c:
      break;
    default:
      error_function_no_fvd(ffun,S(foreign_call_out));
  }
  {
    var av_alist alist;
    var object fa = TheFfunction(ffun)->ff_address;
    fa = check_faddress_valid(fa);
    ffun = Before(rest_args_pointer);
    argfvds_top = TheFfunction(ffun)->ff_argtypes;
    var void* address = Faddress_value(fa);
    var object result_fvd = TheFfunction(ffun)->ff_resulttype;
    /* Allocate space for the result and maybe the args: */
    var struct foreign_layout sas;
    foreign_layout(result_fvd,&sas);
    var uintL result_size = sas.size;
    var uintL result_alignment = sas.alignment;
    var bool result_splittable = sas.splittable;
    var uintL result_totalsize = result_size+result_alignment; /* >= result_size+result_alignment-1, > 0 */
    var uintL cumul_alignment = result_alignment;
    var uintL cumul_size = result_totalsize;
    var uintL allargcount = Svector_length(argfvds_top)/2;
    var uintL outargcount = 0;
    {
      var sintL inargcount = 0;
      var uintL i;
      for (i = 0; i < allargcount; i++) {
        var object argfvds = TheFfunction(Before(rest_args_pointer))->ff_argtypes;
        var object arg_fvd = TheSvector(argfvds)->data[2*i];
        var uintWL arg_flags = posfixnum_to_V(TheSvector(argfvds)->data[2*i+1]);
        if (!(arg_flags & ff_out)) {
          inargcount++;
          if (inargcount > argcount)
            error_too_few_args(S(foreign_call_out),Before(rest_args_pointer),
                               argcount,inargcount);
        }
        if (arg_flags & (ff_out | ff_inout)) {
          if (!(simple_vector_p(arg_fvd) && (Svector_length(arg_fvd) == 2)
                && eq(TheSvector(arg_fvd)->data[0],S(c_ptr))) ) {
            dynamic_bind(S(print_circle),T); /* bind *PRINT-CIRCLE* to T */
            pushSTACK(arg_fvd);
            pushSTACK(S(foreign_call_out));
            error(error_condition,GETTEXT("~S: :OUT argument is not a pointer: ~S"));
          }
          outargcount++;
        }
        if (arg_flags & ff_alloca) {
          var struct foreign_layout sas;
          /* Room for arg itself: */
          foreign_layout(arg_fvd,&sas);
          /* We assume all alignments are of the form 2^k. */
          cumul_size += (-cumul_size) & (sas.alignment-1);
          cumul_size += sas.size;
          /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
          if (sas.alignment > cumul_alignment)
            cumul_alignment = sas.alignment;
          if (arg_flags & ff_out) {
            /* Room for top-level pointer in arg: */
            var object argo_fvd = TheSvector(arg_fvd)->data[1];
            foreign_layout(argo_fvd,&sas);
            /* We assume all alignments are of the form 2^k. */
            cumul_size += (-cumul_size) & (sas.alignment-1);
            cumul_size += sas.size;
            /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
            if (sas.alignment > cumul_alignment)
              cumul_alignment = sas.alignment;
          } else {
            /* Room for pointers in arg: */
            var object arg = Before(rest_args_pointer STACKop -inargcount);
            pushSTACK(result_fvd); pushSTACK(argfvds); /* save */
            convert_to_foreign_needs(arg_fvd,arg,&sas);
            argfvds = popSTACK(); result_fvd = popSTACK(); /* restore */
            /* We assume all alignments are of the form 2^k. */
            cumul_size += (-cumul_size) & (sas.alignment-1);
            cumul_size += sas.size;
            /* cumul_alignment = lcm(cumul_alignment,sas.alignment); */
            if (sas.alignment > cumul_alignment)
              cumul_alignment = sas.alignment;
          }
        }
      }
      if (argcount != inargcount)
        error_too_many_args(S(foreign_call_out),Before(rest_args_pointer),argcount,inargcount);
    }
    var uintL result_count = 0;
    typedef struct { void* address; } result_descr; /* fvd is pushed onto the STACK */
    var DYNAMIC_ARRAY(results,result_descr,1+outargcount);
    cumul_size += (-cumul_size) & (cumul_alignment-1);
    var DYNAMIC_ARRAY(total_room,char,cumul_size+cumul_alignment/*-1*/);
    var void* result_address = (void*)((uintP)(total_room+result_alignment-1) & -(long)result_alignment);
    void *allocaing_room_pointer = (void*)((uintP)result_address + result_size);
    if (!eq(result_fvd,S(nil))) {
      pushSTACK(result_fvd);
      results[0].address = result_address;
      result_count++;
    }
    /* Call av_start_xxx: */
    begin_system_call();
    do_av_start(flags,result_fvd,&alist,address,result_address,result_size,
                result_splittable);
    end_system_call();
    { /* Now pass the arguments. */
      var uintL i;
      var sintL j;
      for (i = 0, j = 0; i < allargcount; i++) {
        var object argfvds = TheFfunction(Before(rest_args_pointer))->ff_argtypes;
        var object arg_fvd = TheSvector(argfvds)->data[2*i];
        var uintWL arg_flags = posfixnum_to_V(TheSvector(argfvds)->data[2*i+1]);
        var object arg;
        if (arg_flags & ff_out) {
          arg = unbound; /* only to avoid uninitialized variable */
        } else {
          arg = Next(rest_args_pointer STACKop -j); j++;
        }
        /* Allocate temporary space for the argument: */
        var struct foreign_layout sas;
        foreign_layout(arg_fvd,&sas);
        var uintL arg_size = sas.size;
        var uintL arg_alignment = sas.alignment;
        if (arg_flags & ff_alloca) {
          allocaing_room_pointer =
            (void*)(((uintP)allocaing_room_pointer + arg_alignment-1)
                    & -(long)arg_alignment);
          var void* arg_address = allocaing_room_pointer;
          allocaing_room_pointer = (void*)((uintP)allocaing_room_pointer
                                           + arg_size);
          if (arg_flags & ff_out) {
            /* Pass top-level pointer only: */
            var object argo_fvd = TheSvector(arg_fvd)->data[1];
            foreign_layout(argo_fvd,&sas);
            allocaing_room_pointer =
              (void*)(((uintP)allocaing_room_pointer + sas.alignment-1)
                      & -(long)sas.alignment);
            *(void**)arg_address = allocaing_room_pointer;
            pushSTACK(argo_fvd);
            results[result_count].address = allocaing_room_pointer;
            result_count++;
            /* zero-fill to avoid uninitialized result: */
            blockzero(allocaing_room_pointer,sas.size);
            allocaing_room_pointer =
              (void*)((uintP)allocaing_room_pointer + sas.size);
          } else {
            /* Convert argument: */
            pushSTACK(arg_fvd); /* save */
            convert_to_foreign(arg_fvd,arg,arg_address,&allocaing,
                               &allocaing_room_pointer);
            arg_fvd = popSTACK(); /* restore */
            if (arg_flags & ff_inout) {
              pushSTACK(TheSvector(arg_fvd)->data[1]);
              results[result_count].address = *(void**)arg_address;
              result_count++;
            }
          }
          /* Call av_xxx: */
          begin_system_call();
          do_av_arg(flags,arg_fvd,&alist,arg_address,arg_size,arg_alignment);
          end_system_call();
        } else {
          var uintL arg_totalsize = arg_size+arg_alignment; /* >= arg_size+arg_alignment-1, > 0 */
          var DYNAMIC_ARRAY(arg_room,char,arg_totalsize);
          var void* arg_address = (void*)((uintP)(arg_room+arg_alignment-1)
                                          & -(long)arg_alignment);
          if (!(arg_flags & ff_out)) {
            /* Convert argument: */
            pushSTACK(arg_fvd); /* save */
            if (arg_flags & ff_malloc)
              convert_to_foreign(arg_fvd,arg,arg_address,&mallocing,NULL);
            else
              convert_to_foreign(arg_fvd,arg,arg_address,&nomalloc,NULL);
            arg_fvd = popSTACK(); /* restore */
            if (arg_flags & ff_inout) {
              pushSTACK(TheSvector(arg_fvd)->data[1]);
              results[result_count].address = *(void**)arg_address;
              result_count++;
            }
          }
          /* Call av_xxx: */
          begin_system_call();
          do_av_arg(flags,arg_fvd,&alist,arg_address,arg_size,arg_alignment);
          end_system_call();
          FREE_DYNAMIC_ARRAY(arg_room);
        }
      }
    }
    if (av_overflown(alist))
      /* avcall has limited buffer space
       __AV_ALIST_WORDS is only an approximation in number of arguments */
      error_too_many_args(S(foreign_call_out),Before(rest_args_pointer),
                          allargcount,__AV_ALIST_WORDS);
    /* Finally call the function. */
    begin_call();
    av_call(alist);
    end_call();
    { /* Convert the result(s) back to Lisp. */
      var gcv_object_t* resptr = (&STACK_0 STACKop result_count) STACKop -1;
      var uintL i;
      for (i = 0; i < result_count; i++) {
        *resptr = convert_from_foreign(*resptr,results[i].address);
        resptr skipSTACKop -1;
      }
    }
    /* Return them as multiple values. */
    if (result_count >= mv_limit)
      error_mv_toomany(S(foreign_call_out));
    STACK_to_mv(result_count);
    if (flags & ff_alloca) {
      /* The C functions we passed also have dynamic extent. Free them.
       Not done now. ?? */
    }
    if (flags & ff_malloc) {
      result_fvd = TheFfunction(Before(rest_args_pointer))->ff_resulttype;
      free_foreign(result_fvd,result_address);
    }
    FREE_DYNAMIC_ARRAY(total_room);
    FREE_DYNAMIC_ARRAY(results);
  }
  set_args_end_pointer(rest_args_pointer STACKop 1); /* STACK cleanup */
}

/* Here is the point where we use the VACALL package. */

/* Call the appropriate va_start_xxx macro for the result.
 do_va_start(flags,result_fvd,alist,result_size,result_alignment,
             result_splittable); */
local void do_va_start (uintWL flags, object result_fvd, va_alist alist,
                        uintL result_size, uintL result_alignment,
                        bool result_splittable)
{
  if (symbolp(result_fvd)) {
    if (eq(result_fvd,S(nil))) {
      va_start_void(alist);
    } else if (eq(result_fvd,S(char)) || eq(result_fvd,S(sint8))) {
      if (flags & ff_lang_ansi_c) {
        va_start_schar(alist);
      } else { /* `signed char' promotes to `int' */
        va_start_int(alist);
      }
    } else if (eq(result_fvd,S(uchar)) || eq(result_fvd,S(uint8))
               || eq(result_fvd,S(character))) {
      if (flags & ff_lang_ansi_c) {
        va_start_uchar(alist);
      } else { /* `unsigned char' promotes to `unsigned int' */
        va_start_uint(alist);
      }
    } else if (eq(result_fvd,S(short)) || eq(result_fvd,S(sint16))) {
      if (flags & ff_lang_ansi_c) {
        va_start_short(alist);
      } else { /* `short' promotes to `int' */
        va_start_int(alist);
      }
    } else if (eq(result_fvd,S(ushort)) || eq(result_fvd,S(uint16))) {
      if (flags & ff_lang_ansi_c) {
        va_start_ushort(alist);
      } else { /* `unsigned short' promotes to `unsigned int' */
        va_start_uint(alist);
      }
    } else if (eq(result_fvd,S(boolean)) || eq(result_fvd,S(int))
              #if (int_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
               ) {
      va_start_int(alist);
    } else if (eq(result_fvd,S(uint))
              #if (int_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
               ) {
      va_start_uint(alist);
    } else if (eq(result_fvd,S(long))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(sint64))
              #endif
               ) {
      va_start_long(alist);
    } else if (eq(result_fvd,S(ulong))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(uint64))
              #endif
               ) {
      va_start_ulong(alist);
    }
   #if (long_bitsize<64)
    #if defined(HAVE_LONG_LONG_INT)
    else if (eq(result_fvd,S(sint64))) {
      va_start_longlong(alist);
    } else if (eq(result_fvd,S(uint64))) {
      va_start_ulonglong(alist);
    }
    #else
    else if (eq(result_fvd,S(sint64))) {
      va_start_struct(alist,struct_sint64,va_word_splittable_2(sint32,sint32));
    } else if (eq(result_fvd,S(uint64))) {
      va_start_struct(alist,struct_uint64,va_word_splittable_2(uint32,uint32));
    }
    #endif
   #endif
    else if (eq(result_fvd,S(single_float))) {
      if (flags & ff_lang_ansi_c) {
        va_start_float(alist);
      } else { /* `float' promotes to `double' */
        va_start_double(alist);
      }
    } else if (eq(result_fvd,S(double_float))) {
      va_start_double(alist);
    } else if (eq(result_fvd,S(c_pointer)) || eq(result_fvd,S(c_string))) {
      va_start_ptr(alist,void*);
    } else {
      error_foreign_type(result_fvd);
    }
  } else if (simple_vector_p(result_fvd)) {
    var object result_fvdtype = TheSvector(result_fvd)->data[0];
    if (eq(result_fvdtype,S(c_struct)) || eq(result_fvdtype,S(c_union))
        || eq(result_fvdtype,S(c_array)) || eq(result_fvdtype,S(c_array_max)))
      _va_start_struct(alist,result_size,result_alignment,result_splittable);
    else if (eq(result_fvdtype,S(c_function))
               || eq(result_fvdtype,S(c_ptr))
               || eq(result_fvdtype,S(c_ptr_null))
               || eq(result_fvdtype,S(c_pointer))
               || eq(result_fvdtype,S(c_array_ptr))) {
      va_start_ptr(alist,void*);
    } else {
      error_foreign_type(result_fvd);
    }
  } else {
    object inttype = gethash(result_fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      do_va_start (flags, inttype, alist, result_size, result_alignment,
                   result_splittable);
    else error_foreign_type(result_fvd);
  }
  if (flags & ff_lang_stdcall)
    alist->flags |= __VA_STDCALL_CLEANUP;
}

/* Call the appropriate va_arg_xxx macro for an arguemnt
 and return its address (in temporary storage).
 do_va_arg(flags,xarg_fvd,alist) */
local void* do_va_arg (uintWL flags, object arg_fvd, va_alist alist)
{
  if (symbolp(arg_fvd)) {
    if (eq(arg_fvd,S(nil))) {
      return NULL;
    } else if (eq(arg_fvd,S(char)) || eq(arg_fvd,S(sint8))) {
      alist->tmp._schar =
        (flags & ff_lang_ansi_c
         ? va_arg_schar(alist)
         : /* `signed char' promotes to `int' */
         va_arg_int(alist));
      return &alist->tmp._schar;
    } else if (eq(arg_fvd,S(uchar)) || eq(arg_fvd,S(uint8))
               || eq(arg_fvd,S(character))) {
      alist->tmp._uchar =
        (flags & ff_lang_ansi_c
         ? va_arg_uchar(alist)
         : /* `unsigned char' promotes to `unsigned int' */
         va_arg_uint(alist));
      return &alist->tmp._uchar;
    } else if (eq(arg_fvd,S(short)) || eq(arg_fvd,S(sint16))) {
      alist->tmp._short =
        (flags & ff_lang_ansi_c
         ? va_arg_short(alist)
         : /* `short' promotes to `int' */
         va_arg_int(alist));
      return &alist->tmp._short;
    } else if (eq(arg_fvd,S(ushort)) || eq(arg_fvd,S(uint16))) {
      alist->tmp._ushort =
        (flags & ff_lang_ansi_c
         ? va_arg_ushort(alist)
         : /* `unsigned short' promotes to `unsigned int' */
         va_arg_uint(alist));
      return &alist->tmp._ushort;
    } else if (eq(arg_fvd,S(boolean)) || eq(arg_fvd,S(int))
              #if (int_bitsize==32)
               || eq(arg_fvd,S(sint32))
              #endif
               ) {
      alist->tmp._int = va_arg_int(alist);
      return &alist->tmp._int;
    } else if (eq(arg_fvd,S(uint))
              #if (int_bitsize==32)
               || eq(arg_fvd,S(uint32))
              #endif
               ) {
      alist->tmp._uint = va_arg_uint(alist);
      return &alist->tmp._uint;
    } else if (eq(arg_fvd,S(long))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(arg_fvd,S(sint32))
              #endif
              #if (long_bitsize==64)
               || eq(arg_fvd,S(sint64))
              #endif
               ) {
      alist->tmp._long = va_arg_long(alist);
      return &alist->tmp._long;
    } else if (eq(arg_fvd,S(ulong))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(arg_fvd,S(uint32))
              #endif
              #if (long_bitsize==64)
               || eq(arg_fvd,S(uint64))
              #endif
               ) {
      alist->tmp._ulong = va_arg_ulong(alist);
      return &alist->tmp._ulong;
    }
   #if (long_bitsize<64)
    #if defined(HAVE_LONG_LONG_INT)
    else if (eq(arg_fvd,S(sint64))) {
      alist->tmp._longlong = va_arg_longlong(alist);
      return &alist->tmp._longlong;
    } else if (eq(arg_fvd,S(uint64))) {
      alist->tmp._ulonglong = va_arg_ulonglong(alist);
      return &alist->tmp._ulonglong;
    }
    #else
    else if (eq(arg_fvd,S(sint64))) {
      return &va_arg_struct(alist,struct_sint64);
    } else if (eq(arg_fvd,S(uint64))) {
      return &va_arg_struct(alist,struct_uint64);
    }
    #endif
   #endif
    else if (eq(arg_fvd,S(single_float))) {
      alist->tmp._float =
        (flags & ff_lang_ansi_c
         ? va_arg_float(alist)
         : /* `float' promotes to `double' */
         va_arg_double(alist));
      return &alist->tmp._float;
    } else if (eq(arg_fvd,S(double_float))) {
      alist->tmp._double = va_arg_double(alist);
      return &alist->tmp._double;
    } else if (eq(arg_fvd,S(c_pointer)) || eq(arg_fvd,S(c_string))) {
      alist->tmp._ptr = va_arg_ptr(alist,void*);
      return &alist->tmp._ptr;
    } else {
      error_foreign_type(arg_fvd);
    }
  } else if (simple_vector_p(arg_fvd)) {
    var object arg_fvdtype = TheSvector(arg_fvd)->data[0];
    if (eq(arg_fvdtype,S(c_struct)) || eq(arg_fvdtype,S(c_union))
        || eq(arg_fvdtype,S(c_array)) || eq(arg_fvdtype,S(c_array_max))) {
      var struct foreign_layout sas;
      foreign_layout(arg_fvd,&sas);
      var uintL arg_size = sas.size;
      var uintL arg_alignment = sas.alignment;
      return _va_arg_struct(alist,arg_size,arg_alignment);
    } else if (eq(arg_fvdtype,S(c_function))
               || eq(arg_fvdtype,S(c_ptr))
               || eq(arg_fvdtype,S(c_ptr_null))
               || eq(arg_fvdtype,S(c_pointer))
               || eq(arg_fvdtype,S(c_array_ptr))) {
      alist->tmp._ptr = va_arg_ptr(alist,void*);
      return &alist->tmp._ptr;
    } else {
      error_foreign_type(arg_fvd);
    }
  } else {
    object inttype = gethash(arg_fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      return do_va_arg (flags, inttype, alist);
    else error_foreign_type(arg_fvd);
  }
}

/* Call the appropriate va_return_xxx macro for the result.
 do_va_return(flags,result_fvd,alist,result_size,result_alignment); */
local void do_va_return (uintWL flags, object result_fvd, va_alist alist, void* result_address, uintL result_size, uintL result_alignment)
{
  if (symbolp(result_fvd)) {
    if (eq(result_fvd,S(nil))) {
      va_return_void(alist);
    } else if (eq(result_fvd,S(char)) || eq(result_fvd,S(sint8))) {
      if (flags & ff_lang_ansi_c) {
        va_return_schar(alist,*(sint8*)result_address);
      } else { /* `signed char' promotes to `int' */
        va_return_int(alist,*(sint8*)result_address);
      }
    } else if (eq(result_fvd,S(uchar)) || eq(result_fvd,S(uint8))
               || eq(result_fvd,S(character))) {
      if (flags & ff_lang_ansi_c) {
        va_return_uchar(alist,*(uint8*)result_address);
      } else { /* `unsigned char' promotes to `unsigned int' */
        va_return_uint(alist,*(uint8*)result_address);
      }
    } else if (eq(result_fvd,S(short)) || eq(result_fvd,S(sint16))) {
      if (flags & ff_lang_ansi_c) {
        va_return_short(alist,*(sint16*)result_address);
      } else { /* `short' promotes to `int' */
        va_return_int(alist,*(sint16*)result_address);
      }
    } else if (eq(result_fvd,S(ushort)) || eq(result_fvd,S(uint16))) {
      if (flags & ff_lang_ansi_c) {
        va_return_ushort(alist,*(uint16*)result_address);
      } else { /* `unsigned short' promotes to `unsigned int' */
        va_return_uint(alist,*(uint16*)result_address);
      }
    } else if (eq(result_fvd,S(boolean)) || eq(result_fvd,S(int))
              #if (int_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
               ) {
      va_return_int(alist,*(int*)result_address);
    } else if (eq(result_fvd,S(uint))
              #if (int_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
               ) {
      va_return_uint(alist,*(unsigned int *)result_address);
    } else if (eq(result_fvd,S(long))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(sint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(sint64))
              #endif
               ) {
      va_return_long(alist,*(long*)result_address);
    } else if (eq(result_fvd,S(ulong))
              #if (int_bitsize<32) && (long_bitsize==32)
               || eq(result_fvd,S(uint32))
              #endif
              #if (long_bitsize==64)
               || eq(result_fvd,S(uint64))
              #endif
               ) {
      va_return_ulong(alist,*(unsigned long *)result_address);
    }
   #if (long_bitsize<64)
    #if defined(HAVE_LONG_LONG_INT)
    else if (eq(result_fvd,S(sint64))) {
      va_return_longlong(alist,*(sint64*)result_address);
    } else if (eq(result_fvd,S(uint64))) {
      va_return_ulonglong(alist,*(uint64*)result_address);
    }
    #else
    else if (eq(result_fvd,S(sint64))) {
      va_return_struct(alist,struct_sint64,*(struct_sint64*)result_address);
    } else if (eq(result_fvd,S(uint64))) {
      va_return_struct(alist,struct_uint64,*(struct_uint64*)result_address);
    }
    #endif
   #endif
    else if (eq(result_fvd,S(single_float))) {
      if (flags & ff_lang_ansi_c) {
        va_return_float(alist,*(float*)result_address);
      } else { /* `float' promotes to `double' */
        va_return_double(alist,*(float*)result_address);
      }
    } else if (eq(result_fvd,S(double_float))) {
      va_return_double(alist,*(double*)result_address);
    } else if (eq(result_fvd,S(c_pointer)) || eq(result_fvd,S(c_string))) {
      va_return_ptr(alist,void*,*(void**)result_address);
    } else {
      error_foreign_type(result_fvd);
    }
  } else if (simple_vector_p(result_fvd)) {
    var object result_fvdtype = TheSvector(result_fvd)->data[0];
    if (eq(result_fvdtype,S(c_struct))
        || eq(result_fvdtype,S(c_union))
        || eq(result_fvdtype,S(c_array))
        || eq(result_fvdtype,S(c_array_max))) {
      _va_return_struct(alist,result_size,result_alignment,result_address);
    } else if (eq(result_fvdtype,S(c_function))
               || eq(result_fvdtype,S(c_ptr))
               || eq(result_fvdtype,S(c_ptr_null))
               || eq(result_fvdtype,S(c_pointer))
               || eq(result_fvdtype,S(c_array_ptr))) {
      va_return_ptr(alist,void*,*(void**)result_address);
    } else
      error_foreign_type(result_fvd);
  } else {
    object inttype = gethash(result_fvd,O(foreign_inttype_table),false);
    if (!eq(inttype,nullobj))
      do_va_return (flags, inttype, alist, result_address,
                    result_size, result_alignment);
    else error_foreign_type(result_fvd);
  }
}

/* This is the CALL-IN function called by the trampolines. */
local void callback (void* data, va_alist alist)
{
  begin_callback();
  var gcv_object_t* triple = &TheSvector(TheIarray(O(foreign_callin_vector))->data)->data[3*((uintL)(uintP)data)-2];
  var object fun = triple[0];
  var object ffun = triple[1];
  var uintWL flags = posfixnum_to_V(TheFfunction(ffun)->ff_flags);
  var object result_fvd = TheFfunction(ffun)->ff_resulttype;
  var object argfvds_top = TheFfunction(ffun)->ff_argtypes;
  var uintL argcount = Svector_length(argfvds_top)/2;
  pushSTACK(result_fvd);
  pushSTACK(fun);
  pushSTACK(argfvds_top);
  switch (flags & 0x7F00) {
    /* For the moment, the only supported languages are "C" and "ANSI C". */
    case ff_lang_c:
    case ff_lang_ansi_c:
      break;
    default:
      error_function_no_fvd(ffun,S(foreign_call_in));
  }
  var struct foreign_layout sas;
  foreign_layout(result_fvd,&sas);
  var uintL result_size = sas.size;
  var uintL result_alignment = sas.alignment;
  var bool result_splittable = sas.splittable;
  /* Call va_start_xxx: */
  begin_system_call();
  do_va_start(flags,result_fvd,alist,result_size,result_alignment,
              result_splittable);
  end_system_call();
  { /* Walk through the arguments, convert them to Lisp data: */
    var uintL i;
    for (i = 0; i < argcount; i++) {
      var object argfvds = STACK_(i);
      var object arg_fvd = TheSvector(argfvds)->data[2*i];
      var uintWL arg_flags = posfixnum_to_V(TheSvector(argfvds)->data[2*i+1]);
      begin_system_call();
      var void* arg_addr = do_va_arg(flags,arg_fvd,alist);
      end_system_call();
      var object arg = convert_from_foreign(arg_fvd,arg_addr);
      if (arg_flags & ff_malloc)
        free_foreign(arg_fvd,arg_addr);
      pushSTACK(arg);
    }
  }
  /* Call the Lisp function: */
  funcall(STACK_(1+argcount),argcount);
  /* Allocate space for the result: */
  var DYNAMIC_ARRAY(result_room,char,result_size+result_alignment/*-1*/);
  var void* result_address = (void*)((uintP)(result_room+result_alignment-1)
                                     & -(long)result_alignment);
  /* Convert the result: */
  convert_to_foreign(STACK_2,value1,result_address,
                     (flags & ff_malloc) ? &mallocing : &nomalloc,NULL);
  /* Call va_return_xxx: */
  begin_system_call();
  do_va_return(flags,STACK_2,alist,result_address,result_size,
               result_alignment);
  end_system_call();
  FREE_DYNAMIC_ARRAY(result_room);
  skipSTACK(3);
  end_callback();
}

#if defined(WIN32_NATIVE) || defined(HAVE_DLOPEN)

#if defined(HAVE_DLFCN_H)
#include <dlfcn.h>
#endif

/* O(foreign_libraries) is an alist of all open foreign library specifiers.
 a library specifier is a list (library-name fpointer object1 object2 ...) */

#if defined(HAVE_DLERROR)
/* return the string object for dlerror() value */
local object dlerror_string (void)
{
  var const char* errmesg;
  begin_system_call(); errmesg = dlerror(); end_system_call();
  return safe_to_string(errmesg);
}
#endif

/* Open a library with the given name
 name: pointer to a Lisp string (corrected on error) or :DEFAULT or :NEXT
 returns a dlopen() handle to the DLL
 can trigger GC -- only on error */
local maygc void * open_library (gcv_object_t* name)
{
  var void * handle;
 open_library_restart:
  if (eq(*name,S(Kdefault))) {
   #if defined(RTLD_DEFAULT)
    return RTLD_DEFAULT;
   #else  /* known to work on WIN32, FreeBSD, MacOSX */
    return NULL;
   #endif
  }
  if (eq(*name,S(Knext))) {
   #if defined(RTLD_NEXT)
    return RTLD_NEXT;
   #else
    pushSTACK(NIL); /* no PLACE */
    pushSTACK(S(Knext));
    pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: ~S is not supported on this platform."));
    *name = value1;
    goto open_library_restart;
   #endif
  }
  with_string_0(*name = check_string(*name),O(misc_encoding),libname, {
    begin_blocking_system_call();
    handle = libopen(libname);
    end_blocking_system_call();
  });
  if (handle == NULL) {
    pushSTACK(NIL); /* no PLACE */
    pushSTACK(*name);
   #if defined(HAVE_DLERROR)
    pushSTACK(STACK_0);
    STACK_1 = dlerror_string();
   #endif
    pushSTACK(TheSubr(subr_self)->name);
   #if defined(HAVE_DLERROR)
    check_value(error_condition,GETTEXT("~S: Cannot open library ~S: ~S"));
   #else
    check_value(error_condition,GETTEXT("~S: Cannot open library ~S"));
   #endif
    *name = value1;
    goto open_library_restart;
  }
  return handle;
}

/* close the fpointer to a library */
local void close_library (object fp) {
  var void * libaddr = (TheFpointer(fp)->fp_pointer);
  begin_system_call();
 #if defined(WIN32_NATIVE)
  FreeLibrary((HMODULE)libaddr);
 #else
  dlclose(libaddr);
 #endif
  end_system_call();
  mark_fp_invalid(TheFpointer(fp));
}

/* find versioned symbol in the dynamic library.
 If this functionality is not supported, then the symbol
 is not found, even if the name does exist in the library. */
local void *find_name_version (void *handle, const char *name,
                               const char *ver) {
  var void *ret = NULL;
#ifdef HAVE_DLVSYM
  ret = dlvsym(handle,name,ver);
#else
  unused(ver); unused(name);
#endif
  return ret;
}

/* return the object handle
 > library - library specifier (lib addr obj...)
 > name    - object name (string)
 < address - the foreign library handle (in the C sense)
 can trigger GC */
local maygc void* object_handle (object library, object name, object version) {
  var void * address;
  if (nullp(version)) {
    with_string_0(name,O(foreign_encoding),namez, {
      begin_system_call();
      address = find_name(TheFpointer(Car(Cdr(library)))->fp_pointer, namez);
      end_system_call();
    });
  } else {
    with_string_0(name,O(foreign_encoding),namez, {
      with_string_0(version,O(foreign_encoding),verz, {
        begin_system_call();
        address = find_name_version(TheFpointer(Car(Cdr(library)))->fp_pointer,
                                    namez, verz);
        end_system_call();
      });
    });
  }
  if (address == NULL) {
    uintC argcount = 6;
    gcv_object_t *cfs, *efs;
    pushSTACK(NIL); cfs=&STACK_0; /* continue-format-string */
    pushSTACK(S(error));          /* error type */
    pushSTACK(NIL); efs=&STACK_0; /* error-format-string */
    pushSTACK(TheSubr(subr_self)->name); pushSTACK(name);
    if (!nullp(version)) {
      pushSTACK(version); argcount++;
    }
    pushSTACK(Car(library));
    *efs = nullp(version)
      ? CLSTEXT("~S: no dynamic object named ~S in library ~S")
      : CLSTEXT("~S: no dynamic object named ~S (version ~S) in library ~S");
    *cfs = CLSTEXT("Skip foreign object creation");
    funcall(L(cerror_of_type),argcount);
  }
  return address;
}

/* find the library in O(foreign_libraries):
   (ASSOC name O(foreign_libraries) :TEST (FUNCTION EQUAL))
 > name: the name of the library
 < library specifier (library fpointer deps object1 object2 ...) or NIL */
local object find_library_by_name (object name) {
  var object alist = O(foreign_libraries);
  while (consp(alist)) {
    if (equal(name,Car(Car(alist))))
      return Car(alist);
    alist = Cdr(alist);
  }
  return NIL;
}
/* find the library in O(foreign_libraries):
   (FIND address O(foreign_libraries) :KEY (FUNCTION SECOND))
 > addr: the address of the library
 < library specifier (library fpointer object1 object2 ...) or NIL */
local object find_library_by_address (object addr) {
  var object alist = O(foreign_libraries);
  while (consp(alist)) {
    if (eq(addr,Car(Cdr(Car(alist)))))
      return Car(alist);
    alist = Cdr(alist);
  }
  return NIL;
}

/* update the DLL pointer and all related objects: re-open the library,
 and update the base fp_pointer of fpointer-library-handle and all objects in
 lib_spec = (library-name fpointer-library-handle deps object1 object2 ...)
 can trigger GC -- only on error in open_library() or object_handle() */
local maygc void update_library (object lib_spec) {
  pushSTACK(lib_spec);
  var gcv_object_t *lib_spec_ = &STACK_0;
  /* update dependencies */
  for (pushSTACK(Car(Cdr(Cdr(*lib_spec_)))); consp(STACK_0);
       STACK_0 = Cdr(STACK_0))
    /* dependencies are strings */
    update_library(find_library_by_name(Car(STACK_0)));
  skipSTACK(1);
  /* open the library */
  pushSTACK(Car(*lib_spec_));
  var void *lib_handle = open_library(&STACK_0);
  Car(*lib_spec_) = popSTACK();
  pushSTACK(Car(Cdr(*lib_spec_))); /* library address - Fpointer */
  var gcv_object_t *lib_addr_ = &STACK_0; /* presumably invalid */
  TheFpointer(*lib_addr_)->fp_pointer = lib_handle;
  mark_fp_valid(TheFpointer(*lib_addr_));
  /* update objects */
  pushSTACK(NIL);
  var gcv_object_t *fa_ = &STACK_0; /* place to keep foreign address */
  pushSTACK(Cdr(Cdr(*lib_spec_)));  /* library list */
  while (consp(Cdr(STACK_0))) {
    var object fo = Car(Cdr(STACK_0)); /* foreign object */
    *fa_ = foreign_address(fo,false);  /* its foreign address */
    var object fn;                     /* its name */
    var object ve;                     /* its version */
    switch (Record_type(fo)) {
      case Rectype_Fvariable:
        fn = TheFvariable(fo)->fv_name;
        ve = TheFvariable(fo)->fv_version;
        break;
      case Rectype_Ffunction:
        fn = TheFfunction(fo)->ff_name;
        ve = TheFfunction(fo)->ff_version;
        break;
      default: NOTREACHED;
    }
    ASSERT(eq(TheFaddress(*fa_)->fa_base,*lib_addr_));
    var void* handle = object_handle(*lib_spec_,fn,ve);
    if (handle) {               /* found -- fix Faddress */
      TheFaddress(*fa_)->fa_offset = (sintP)handle - (sintP)lib_handle;
      STACK_0 = Cdr(STACK_0);
    } else {                    /* not found - drop object */
      Cdr(STACK_0) = Cdr(Cdr(STACK_0));
      var object fp = allocate_fpointer((void*)0);
      TheFaddress(*fa_)->fa_base = fp;
      mark_fp_invalid(TheFpointer(TheFaddress(*fa_)->fa_base));
    }
  }
  skipSTACK(4);                /* drop lib_spec, library list & lib_addr */
}

/* Check a foreign library argument: an address or a string
 > obj ----- library name (will be opened) or address (will be updated)
 < Return the library specifier (name fpointer object...)
    if obj was the name, it is checked and updated by open_library
 can trigger GC */
local maygc object check_library (gcv_object_t *obj) {
  var object lib_spec = (fpointerp(*obj) ? find_library_by_address(*obj)
                         : stringp(*obj) ? find_library_by_name(*obj) : NIL);
  if (nullp(lib_spec)) {        /* open new */
    pushSTACK(*obj);
    pushSTACK(allocate_fpointer(open_library(obj)));
    pushSTACK(NIL);             /* dependencies */
    lib_spec = allocate_cons();
    Cdr(lib_spec) = O(foreign_libraries);
    O(foreign_libraries) = lib_spec;
    Car(O(foreign_libraries)) = lib_spec = listof(3);
    return lib_spec;
  } else { /* lib_spec = (library-name library-addr deps obj1 obj2 ...) */
    if (!fp_validp(TheFpointer(Car(Cdr(lib_spec))))) {
      /* Library already existed in a previous Lisp session.
         Update the address, and make it valid. */
      pushSTACK(lib_spec);      /* save */
      update_library(lib_spec);
      lib_spec = popSTACK();    /* restore */
    }
    return lib_spec;
  }
}

/* (FFI:OPEN-FOREIGN-LIBRARY name &require dependencies)
 returns a foreign library specifier (fpointer). */
LISPFUN(open_foreign_library,seclass_read,1,0,norest,key,1,(kw(require))) {
  /* open the dependencies */
  for (pushSTACK(STACK_0); consp(STACK_0); STACK_0 = Cdr(STACK_0)) {
    pushSTACK(Car(STACK_0));
    check_library(&STACK_0);
    var object tmp = popSTACK(); Car(STACK_1) = tmp;
  }
  var object lib_spec = check_library(&STACK_2);
  Car(Cdr(Cdr(lib_spec))) = STACK_1; /* save dependencies */
  VALUES1(Car(Cdr(lib_spec)));
  skipSTACK(3);                 /* name, dependencies, tail */
}

/* (FFI:CLOSE-FOREIGN-LIBRARY name) */
LISPFUNN(close_foreign_library,1) {
  var object lib_cons = find_library_by_name(popSTACK());
  if (consp(lib_cons)) {
    var object library = Car(Cdr(lib_cons));
    if (fp_validp(TheFpointer(library)))
      close_library(library);
    value1 = library;
  } else
    value1 = NIL;
  mv_count = 1;
}

/* Try to make a Foreign-Pointer valid again, returning the argument.
 validate_fpointer(obj);
 can trigger GC */
local maygc object validate_fpointer (object obj)
{ /* If the foreign pointer belongs to a foreign library from a previous
     session, we reopen the library. */
  pushSTACK(obj);
  pushSTACK(O(foreign_libraries));
  while (consp(STACK_0)) {
    var object lib_spec = Car(STACK_0); STACK_0 = Cdr(STACK_0);
    if (eq(Car(Cdr(lib_spec)),STACK_1)) {
      update_library(lib_spec);
      skipSTACK(1); return popSTACK();
    }
  }
  skipSTACK(1);                 /* drop tail */
  return check_fpointer(popSTACK()/*obj*/,false);
}

/* return the foreign address of the foreign object named 'name'
 > library - foreign library specifier (name fpointer obj...)
 > name - string (C name)
 > offset - integer or NIL, if supplied, name is ignored
 can trigger GC */
local maygc object object_address (object library, object name,
                                   object version, object offset)
{ var object lib_addr = Car(Cdr(library));
  var sintP result_offset;
  if (nullp(offset)) {
    pushSTACK(lib_addr);
    var void* name_handle = object_handle(library,name,version);
    lib_addr = popSTACK();
    if (NULL == name_handle) return nullobj;
    result_offset =
      (sintP)name_handle - (sintP)TheFpointer(lib_addr)->fp_pointer;
  } else {
    result_offset = (sintP)I_to_sint32(offset);
  }
  return make_faddress(lib_addr,result_offset);
}

/* add foreign object obj to the lib_spec (name addr obj1 ...)
 can trigger GC */
local maygc void push_foreign_object (object obj, object lib_spec) {
  pushSTACK(obj); pushSTACK(lib_spec);
  var object new_cons = allocate_cons();
  lib_spec = popSTACK();
  Car(new_cons) = popSTACK()/*obj*/; Cdr(new_cons) = Cdr(Cdr(Cdr(lib_spec)));
  Cdr(Cdr(Cdr(lib_spec))) = new_cons;
}

/* UP: check foreign_library_* arguments and create the foreign object
 > name    - object name (pre-checked)
 > library - library name --> library specifier
 > version - object version (checked here)
 > offset  - address offset in the library or NIL
 < new object address
 can trigger GC */
local maygc object foreign_library_check
(gcv_object_t *name, gcv_object_t *library,
 gcv_object_t *version, gcv_object_t *offset) {
  *library = check_library(library);
  if (!nullp(*offset)) *offset = check_sint32(*offset);
  if (!nullp(*version)) *version = coerce_ss(*version);
  return object_address(*library,*name,*version,*offset);
}
#define push_foreign_library_object(n,l,v,o)                    \
  pushSTACK(foreign_library_check(n,l,v,o));                    \
  if (eq(nullobj,STACK_0)) {    /* not found and ignored  */    \
    skipSTACK(1); return NIL;                                   \
  }

/* UP: find and allocate a foreign variable in a dynamic library
 > name     - variable C name (string - prechecked)
 > library  - library C name (string - checked here)
 > version  - object version (NIL or string - checked here)
 > offset   - address offset in the library or NIL
 > fvd      - function type
 can trigger GC */
local maygc object foreign_library_variable
(gcv_object_t *name, gcv_object_t* fvd,
 gcv_object_t *library, gcv_object_t *version, gcv_object_t *offset) {
  push_foreign_library_object(name,library,version,offset);
  var struct foreign_layout sas;
  foreign_layout(*fvd,&sas);
  var uintL size = sas.size;
  var uintL alignment = sas.alignment;
  var object fvar = allocate_fvariable();
  TheFvariable(fvar)->fv_name = *name;
  TheFvariable(fvar)->fv_version = *version;
  TheFvariable(fvar)->fv_address = STACK_0;
  TheFvariable(fvar)->fv_size = fixnum(size);
  TheFvariable(fvar)->fv_type = *fvd;
  check_fvar_alignment(fvar,alignment);
  STACK_0 = fvar; /* save */
  push_foreign_object(fvar,*library);
  return popSTACK(); /* fvar */
}

/* UP: find and allocate a foreign function in a dynamic library
 > name     - function C name (string - prechecked)
 > fvd      - function type (already checked)
 > properties - function properties
 > library  - library C name (string - checked here)
 > version  - object version (NIL or string - checked here)
 > offset   - address offset in the library or NIL
 can trigger GC */
local maygc object foreign_library_function
(gcv_object_t *name, gcv_object_t *fvd, gcv_object_t *properties,
 gcv_object_t *library, gcv_object_t *version, gcv_object_t *offset) {
  push_foreign_library_object(name,library,version,offset);
  var object ffun = allocate_ffunction();
  TheFfunction(ffun)->ff_name = *name;
  TheFfunction(ffun)->ff_version = *version;
  TheFfunction(ffun)->ff_address = STACK_0;
  TheFfunction(ffun)->ff_resulttype = TheSvector(*fvd)->data[1];
  TheFfunction(ffun)->ff_argtypes = TheSvector(*fvd)->data[2];
  TheFfunction(ffun)->ff_flags = TheSvector(*fvd)->data[3];
  TheFfunction(ffun)->ff_properties = *properties;
  STACK_0 = ffun; /* save */
  push_foreign_object(ffun,*library);
  return popSTACK(); /* ffun */
}

#else /* not WIN32_NATIVE || HAVE_DLOPEN */

/* Try to make a Foreign-Pointer valid again.
 validate_fpointer(obj); */
local inline object validate_fpointer (object obj)
{ /* Can't do anything. */
  return check_fpointer(obj,false);
}

/* error-message about lack of dlsym */
nonreturning_function(local,error_no_dlsym,(object name, object library)) {
  pushSTACK(library); pushSTACK(name);
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: cannot find ~S in ~S due to lack of dlsym() on this platform"));
}

/* stubs signalling errors */
local maygc object foreign_library_function
(gcv_object_t* name, gcv_object_t* fvd, gcv_object_t* properties,
 gcv_object_t* library, gcv_object_t* offset)
{ error_no_dlsym(*name,*library); }
local maygc object foreign_library_variable
(gcv_object_t *name, gcv_object_t* fvd,
 gcv_object_t *library, gcv_object_t *offset)
{ error_no_dlsym(*name,*library); }

#endif

/* Allow everybody the creation of a FOREIGN-VARIABLE and FOREIGN-FUNCTION
 object, even without any module.
 This allows, among others, a self-test of the FFI (see testsuite). */
local uintP ffi_identity (uintP arg) { return arg; }
global void* ffi_user_pointer = NULL;

/* Initialize the FFI. */
global maygc void init_ffi (void) {
  /* Allocate a fresh zero foreign pointer: */
  O(fp_zero) = allocate_fpointer((void*)0);
  ffi_user_pointer = NULL;
  register_foreign_inttype("size_t",sizeof(size_t),false);
  register_foreign_inttype("ssize_t",sizeof(ssize_t),true);
  register_foreign_inttype("ffi_uintp",sizeof(uintP),false);
  register_foreign_variable(&ffi_user_pointer,"ffi_user_pointer",
                            0,sizeof(ffi_user_pointer));
  register_foreign_function((void*)&ffi_identity,"ffi_identity",
                            ff_lang_ansi_c);
}

/* De-Initialize the FFI. */
global void exit_ffi (void) {
 #if defined(WIN32_NATIVE) || defined(HAVE_DLOPEN)
  /* Close all foreign libraries. */
  var object alist = O(foreign_libraries);
  while (consp(alist)) {
    var object lib_spec = Car(alist);
    var object obj = Car(Cdr(lib_spec));
    if (stringp(Car(lib_spec)) && fp_validp(TheFpointer(obj)))
      close_library(obj);
    alist = Cdr(alist);
  }
  O(foreign_libraries) = NIL;
 #endif
}

#if defined(HAVE_DLADDR)
LISPFUNN(foreign_pointer_info,1) {
  object arg = foreign_address(popSTACK(),true);
  void *addr = Fpointer_value(arg);
  Dl_info dli;
  int status;
  begin_system_call(); status = dladdr(addr,&dli); end_system_call();
  if (status == 0) {            /* failed */
   #if defined(HAVE_DLERROR)
    pushSTACK(dlerror_string());
   #endif
    pushSTACK(arg); pushSTACK(TheSubr(subr_self)->name);
   #if defined(HAVE_DLERROR)
    error(error_condition,GETTEXT("~S(~S): dladdr() failed: ~S"));
   #else
    error(error_condition,GETTEXT("~S(~S): dladdr() failed"));
   #endif
  } else {
    pushSTACK(safe_to_string(dli.dli_fname));
    pushSTACK(allocate_fpointer(dli.dli_fbase));
    pushSTACK(safe_to_string(dli.dli_sname));
    pushSTACK(allocate_fpointer(dli.dli_saddr));
    STACK_to_mv(4);
  }
}
#endif

#endif
