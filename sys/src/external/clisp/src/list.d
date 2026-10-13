/*
 * List functions for CLISP
 * Bruno Haible 1990-2005
 * Marcus Daniels 8.4.1994
 * Sam Steingold 1999-2009
 * German comments and names translated into English: Reini Urban 2008-01
 */
#include "lispbibl.c"

/* (PROG1 (CONS STACK_1 STACK_0) skipSTACK(2))
 removes 2 objects from STACK
 can trigger GC */
local inline maygc object cons_from_stack (void)
{
  var object ret = allocate_cons();
  Cdr(ret) = popSTACK();
  Car(ret) = popSTACK();
  return ret;
}

/* UP: Copies a list
 copy_list(list)
 > list: List
 < result: Copy of the list
 can trigger GC */
modexp maygc object copy_list (object old_list) {
  /* Method: (copy-list l) = (mapcar #'identity l), mapcar forwards */
  if (atomp(old_list))
    return old_list;
  else { /* List with at least one element */
    var object run;
    pushSTACK(old_list);
    {
      var object new_list = allocate_cons();
      run = STACK_0; /* run runs through the old list */
      Car(new_list) = Car(run);
      STACK_0 = new_list;
      pushSTACK(new_list);
    }
    /* Loop: STACK_1 is the whole copy, STACK_0 = LAST of it, */
    /* run = the correspondend Cons of the original list. */
    while ( run=Cdr(run), consp(run) ) {
      /* one more Cons */
      pushSTACK(run); /* save run */
      var object new_cons = allocate_cons(); /* allocate new Cons */
      run = popSTACK(); /* run back */
      Cdr(STACK_0) = new_cons; /* and put as CDR of the LAST */
      Car(new_cons) = Car(run); /* copy CAR */
      STACK_0 = new_cons; /* this is now the new LAST */
    }
    Cdr(popSTACK()) = run; /* keep same (CDR (LAST old_list)) */
    return popSTACK();
  }
}

/* UP: Reverses a list by copying
 reverse(list)
 > list: List (x1 ... xm)
 < result: reversed List (xm ... x1)
 can trigger GC */
global maygc object reverse (object list) {
  pushSTACK(list); pushSTACK(NIL);
  while (!endp(list)) {
    /* Here is for r=1,...,m: */
    /* STACK_0 = (xr-1 ... x1), list = (xr ... xm) */
    STACK_1 = Cdr(list);
    /* Here is for r=1,...,m: */
    /* STACK_0 = (xr-1 ... x1), STACK_1 = (xr+1 ... xm) */
    pushSTACK(Car(list));
    {
      var object new_cons = allocate_cons();
      Car(new_cons) = popSTACK(); /* = xr */
      Cdr(new_cons) = STACK_0; /* = (xr-1 ... x1) */
      STACK_0 = new_cons; /* = (xr ... x1) */
    }
    list = STACK_1; /* list := (xr+1 ... xm) */
  }
  list = popSTACK(); skipSTACK(1); return list;
}
#if 0
/* another possibility: */
global object reverse (object list) {
  pushSTACK(list); pushSTACK(NIL);
  while (mconsp(STACK_1)) {
    var object new_cons = allocate_cons();
    var object old_cons = STACK_1;
    STACK_1 = Cdr(old_cons);
    Car(new_cons) = Car(old_cons);
    Cdr(new_cons) = STACK_0;
    STACK_0 = new_cons;
  }
  list = popSTACK(); skipSTACK(1); return list;
}
#endif

/* UP: get the list length and the last atom
 > obj: object
 < len: list length
 < last: the last atom */
modexp uintL llength1 (object list, object* last) {
  var uintL count = 0;
  while (consp(list)) {
    count++; list=Cdr(list);
  }
  if (last) *last = list;
  return count;
}

/* UP: Constructs a list with exactly len elements.
 make_list(len)
 > STACK_0: Initial value for all elements
 > uintL len: wanted list length
 < result: List with len elements
 can trigger GC */
modexp maygc object make_list (uintL len) {
  pushSTACK(NIL);
  while (len--) {
    /* STACK_0 = old list, STACK_1 = initial value */
    var object new_cons = allocate_cons();
    Car(new_cons) = STACK_1; Cdr(new_cons) = STACK_0;
    STACK_0 = new_cons;
  }
  return popSTACK();
}

/* UP: Reverses a list in-place, destructively.
 nreverse(list)
 > list: List (x1 ... xm)
 < result: List (xm ... x1), EQ to the old */
modexp object nreverse (object list) {
  /* Algorithm:
     (lambda (L)
       (cond ((atom L) L)
             ((atom (cdr L)) L)
             ((atom (cddr L)) (rotatef (car L) (cadr L)) L)
             (t (let ((L1 (cdr L)))
                  (do ((L3 L1 (cdr L3))
                       (L2 nil (rplacd L3 L2)))
                      ((atom (cdr L3))
                       (setf (cdr L) L2)
                       (setf (cdr L1) L3)
                       (rotatef (car L) (car L3))))
                  L)))) */
  if (consp(list)) { /* (atom L) -> L */
    var object list3 = Cdr(list); /* L3 := (cdr L) */
    if (!endp(list3)) { /* (atom (cdr L)) -> L */
      if (!endp(Cdr(list3))) {
        var object list1 = list3; /* Begin with L1 = L3 = (cdr L) */
        var object list2 = NIL; /* and L2 = NIL */
        do {
          var object h = Cdr(list3); /* save (cdr L3), */
          Cdr(list3) = list2; /* replace by L2, */
          list2 = list3; /* L2 := old L3 */
          list3 = h; /* L3 := old (cdr L3) */
        } while (!endp(Cdr(list3))); /* (atom (cdr L3)) -> end */
        /* L3 is the last and L2 the last but one list Cons. */
        Cdr(list) = list2; /* (setf (cdr L) L2) */
        Cdr(list1) = list3; /* (setf (cdr L1) L3) */
      }
      /* exchange (car list) and (car list3): */
      var object h = Car(list);
      Car(list) = Car(list3);
      Car(list3) = h;
    }
  }
  return list;
}

/* UP: A0 := (nreconc A0 A1)
 nreconc(list,obj)
 > list: List
 > obj: Object
 < result: (nreconc A0 A1) */
global object nreconc (object list, object obj) {
  if (!endp(list)) { /* (atom L) -> L */
    var object list3 = Cdr(list); /* L3 := (cdr L) */
    if (!endp(list3)) { /* (atom (cdr L)) -> L */
      if (!endp(Cdr(list3))) {
        var object list1 = list3; /* Begin with L1 = L3 = (cdr L) */
        var object list2 = NIL; /* and L2 = NIL */
        do {
          var object h = Cdr(list3); /* save (cdr L3), */
          Cdr(list3) = list2; /* replace by L2, */
          list2 = list3; /* L2 := old L3 */
          list3 = h; /* L3 := old (cdr L3) */
        } while (!endp(Cdr(list3))); /* (atom (cdr L3)) -> end */
        /* L3 is the last and L2 the last but one list Cons. */
        Cdr(list) = list2; /* (setf (cdr L) L2) */
        Cdr(list1) = list3; /* (setf (cdr L1) L3) */
      }
      /* exchange (car list) and (car list3): */
      {
        var object h = Car(list);
        Car(list) = Car(list3);
        Car(list3) = h;
      }
      Cdr(list3) = obj; /* (setf (cdr L3) O) */
    } else {
      Cdr(list) = obj;
    }
    return list;
  } else
    return obj;
}

/* UP: Construct (delete obj (the list list) :test #'EQ)
 deleteq(list,obj)
 Remove from list all elements EQ to obj.
 > obj: to be removed element
 > list: List
 < result: modified List */
modexp object deleteq (object list, object obj) {
  var object list1 = list;
  var object list2 = list;
  while (!atomp(list2)) {
    /* Here is either list1=list2=list or (cdr list1) = list2. */
    if (eq(Car(list2),obj))
      /* Remove (car list2): */
      if (eq(list2,list)) {
        /* Still at the start of the list */
        list2 = list1 = list = Cdr(list2);
      } else {
        /* advanced the start of the list */
        Cdr(list1) = list2 = Cdr(list2);
      }
    else {
      /* Remove nothing, advance: */
      list1 = list2; list2 = Cdr(list2);
    }
  }
  return list;
}

/* UP: Returns (car obj), with type check */
local object car (object obj) {
  if (consp(obj))
    return Car(obj);
  else if (nullp(obj))
    return obj;
  else
    error_list(obj);
}

/* UP: Returns (cdr obj), with type check */
local object cdr (object obj) {
  if (consp(obj))
    return Cdr(obj);
  else if (nullp(obj))
    return obj;
  else
    error_list(obj);
}

LISPFUNNR(car,1)
{ /* (CAR list), CLTL p. 262 */
  VALUES1(car(popSTACK()));
}

LISPFUNNR(cdr,1)
{ /* (CDR list), CLTL p. 262 */
  VALUES1(cdr(popSTACK()));
}

LISPFUNNR(caar,1)
{ /* (CAAR list), CLTL p. 263 */
  VALUES1(car(car(popSTACK())));
}

LISPFUNNR(cadr,1)
{ /* (CADR list), CLTL p. 263 */
  VALUES1(car(cdr(popSTACK())));
}

LISPFUNNR(cdar,1)
{ /* (CDAR list), CLTL p. 263 */
  VALUES1(cdr(car(popSTACK())));
}

LISPFUNNR(cddr,1)
{ /* (CDDR list), CLTL p. 263 */
  VALUES1(cdr(cdr(popSTACK())));
}

LISPFUNNR(caaar,1)
{ /* (CAAAR list), CLTL p. 263 */
  VALUES1(car(car(car(popSTACK()))));
}

LISPFUNNR(caadr,1)
{ /* (CAADR list), CLTL p. 263 */
  VALUES1(car(car(cdr(popSTACK()))));
}

LISPFUNNR(cadar,1)
{ /* (CADAR list), CLTL p. 263 */
  VALUES1(car(cdr(car(popSTACK()))));
}

LISPFUNNR(caddr,1)
{ /* (CADDR list), CLTL p. 263 */
  VALUES1(car(cdr(cdr(popSTACK()))));
}

LISPFUNNR(cdaar,1)
{ /* (CDAAR list), CLTL p. 263 */
  VALUES1(cdr(car(car(popSTACK()))));
}

LISPFUNNR(cdadr,1)
{ /* (CDADR list), CLTL p. 263 */
  VALUES1(cdr(car(cdr(popSTACK()))));
}

LISPFUNNR(cddar,1)
{ /* (CDDAR list), CLTL p. 263 */
  VALUES1(cdr(cdr(car(popSTACK()))));
}

LISPFUNNR(cdddr,1)
{ /* (CDDDR list), CLTL p. 263 */
  VALUES1(cdr(cdr(cdr(popSTACK()))));
}

LISPFUNNR(caaaar,1)
{ /* (CAAAAR list), CLTL p. 263 */
  VALUES1(car(car(car(car(popSTACK())))));
}

LISPFUNNR(caaadr,1)
{ /* (CAAADR list), CLTL p. 263 */
  VALUES1(car(car(car(cdr(popSTACK())))));
}

LISPFUNNR(caadar,1)
{ /* (CAADAR list), CLTL p. 263 */
  VALUES1(car(car(cdr(car(popSTACK())))));
}

LISPFUNNR(caaddr,1)
{ /* (CAADDR list), CLTL p. 263 */
  VALUES1(car(car(cdr(cdr(popSTACK())))));
}

LISPFUNNR(cadaar,1)
{ /* (CADAAR list), CLTL p. 263 */
  VALUES1(car(cdr(car(car(popSTACK())))));
}

LISPFUNNR(cadadr,1)
{ /* (CADADR list), CLTL p. 263 */
  VALUES1(car(cdr(car(cdr(popSTACK())))));
}

LISPFUNNR(caddar,1)
{ /* (CADDAR list), CLTL p. 263 */
  VALUES1(car(cdr(cdr(car(popSTACK())))));
}

LISPFUNNR(cadddr,1)
{ /* (CADDDR list), CLTL p. 263 */
  VALUES1(car(cdr(cdr(cdr(popSTACK())))));
}

LISPFUNNR(cdaaar,1)
{ /* (CDAAAR list), CLTL p. 263 */
  VALUES1(cdr(car(car(car(popSTACK())))));
}

LISPFUNNR(cdaadr,1)
{ /* (CDAADR list), CLTL p. 263 */
  VALUES1(cdr(car(car(cdr(popSTACK())))));
}

LISPFUNNR(cdadar,1)
{ /* (CDADAR list), CLTL p. 263 */
  VALUES1(cdr(car(cdr(car(popSTACK())))));
}

LISPFUNNR(cdaddr,1)
{ /* (CDADDR list), CLTL p. 263 */
  VALUES1(cdr(car(cdr(cdr(popSTACK())))));
}

LISPFUNNR(cddaar,1)
{ /* (CDDAAR list), CLTL p. 263 */
  VALUES1(cdr(cdr(car(car(popSTACK())))));
}

LISPFUNNR(cddadr,1)
{ /* (CDDADR list), CLTL p. 263 */
  VALUES1(cdr(cdr(car(cdr(popSTACK())))));
}

LISPFUNNR(cdddar,1)
{ /* (CDDDAR list), CLTL p. 263 */
  VALUES1(cdr(cdr(cdr(car(popSTACK())))));
}

LISPFUNNR(cddddr,1)
{ /* (CDDDDR list), CLTL p. 263 */
  VALUES1(cdr(cdr(cdr(cdr(popSTACK())))));
}

LISPFUN(cons,seclass_no_se,2,0,norest,nokey,0,NIL)
{ /* (CONS obj1 obj2), CLTL p. 264 */
  VALUES1(cons_from_stack());
}

/* UP: Tests the equality of two trees.
 tree_equal(stackptr,pcall_test,arg1,arg2)
 > arg1,arg2: two trees
 > stackptr: Pointer to the stack
 > A5: Adress of a test function, which compares arg1 and arg2 and may access
        the :TEST/:TEST-NOT arguments in *(stackptr+1).L resp.
        *(stackprt+0).L
 < result: true if equal, otherwise false
 can trigger GC */
local maygc bool tree_equal (const gcv_object_t* stackptr, funarg_t* pcall_test,
                             object arg1, object arg2) {
 start:
  if (atomp(arg1))
    if (atomp(arg2))
      /* arg1 and arg2 both are atoms */
      return pcall_test(stackptr,arg1,arg2);
    else
      return false;
  else
    if (atomp(arg2))
      return false;
    else {
      /* arg1 and arg2 both are Cons */
      check_STACK(); check_SP();
      pushSTACK(Cdr(arg1)); pushSTACK(Cdr(arg2));
      if (tree_equal(stackptr,pcall_test,Car(arg1),Car(arg2))) { /* recursive on CARs */
        /* if equal, compare tail-recursively the CDRs */
        arg2 = popSTACK(); arg1 = popSTACK(); goto start;
      } else {
        skipSTACK(2); return false;
      }
    }
}

LISPFUN(tree_equal,seclass_default,2,0,norest,key,2, (kw(test),kw(test_not)) )
{ /* (TREE-EQUAL x y :test :test-not), CLTL p. 264 */
  var gcv_object_t* stackptr = &STACK_0;
  /* check :TEST/:TEST-NOT arguments: */
  var funarg_t* pcall_test = check_test_args(stackptr);
  VALUES_IF(tree_equal(stackptr,pcall_test,STACK_3,STACK_2));
  skipSTACK(4);
}

/* UP: check whether OBJ ends a proper list
 endp(obj)
 > obj: object
 < result: true if obj is the list end NIL,
           false if obj is a Cons.
           error otherwise */
modexp bool endp (object obj) {
  if (consp(obj))
    return false;
  else if (nullp(obj))
    return true;
  else
    error_proper_list_dotted(TheSubr(subr_self)->name,obj);
}

LISPFUNNF(endp,1)
{ /* (ENDP object), CLTL p. 264 */
  VALUES_IF(endp(popSTACK()));
}

/* Finds the length of a possibly circular or dotted list.
 list_length(list,&dotted)
 > list: an object
 < result: the length (integer >= 0, or NIL for circular lists)
 < dotted: if non-circular, the last atom, i.e., the indicator whether the list
           is dotted
 can trigger GC */
global maygc object list_length (object list, object *dottedp) {
/* (defun list-length (list)
     (do ((n 0 (+ n 2))
          (fast list (cddr fast))
          (slow list (cdr slow)))
         (nil)
       (when (endp fast) (return n))
       (when (endp (cdr fast)) (return (1+ n)))
       (when (eq (cdr fast) slow) (return nil))))
 (see CLtL p 265) */
  var object fast = list;
  var object slow = fast;
  var uintL n = 0;
  while (consp(fast)) {
    fast = Cdr(fast); n++;
    if (atomp(fast))
      break;
    if (eq(fast,slow))
      return NIL;
    fast = Cdr(fast); n++;
    slow = Cdr(slow);
  }
  pushSTACK(fast);
  var object len = UL_to_I(n);
  *dottedp = popSTACK();
  return len;
}

LISPFUNNR(list_length,1)
{ /* (LIST-LENGTH list), CLTL p. 265 */
  var object tail = NIL;
  var object len = list_length(popSTACK(),&tail);
  if (nullp(tail))
    VALUES1(len);
  else
    error_proper_list_dotted(S(list_length),tail);
}

LISPFUNNR(list_length_dotted,1)
{ /* traverses the list just once, otherwise equivalent to
   (defun list-length-dotted (l)
     (let ((ll (list-length l)))
       (when ll (values ll (cdr (last l)))))) */
  var object tail = NIL;
  var object len = list_length(popSTACK(),&tail);
  if (nullp(len))
    VALUES1(NIL);
  else
    VALUES2(len,tail);
}

LISPFUNNR(list_length_proper,1)
{ /* traverses the list just once, otherwise equivalent to
   (defun list-length-proper (l)
     (if (proper-list-p l)
       (length l)
       (error ...))) */
  var object tail = NIL;
  var object len = list_length(STACK_0,&tail);
  if (!nullp(tail)) error_proper_list_dotted(S(list_length_proper),tail);
  if (nullp(len)) error_proper_list_circular(S(list_length_proper),STACK_0);
  VALUES1(len); skipSTACK(1);
}

LISPFUNNR(list_length_in_bounds_p,4)
{ /* (sys::list-length-in-bounds-p obj n m restp) tests whether obj, as a list,
     starts with at least n conses and is either a proper list with < m conses
     or (if restp) has at least m conses or (if not restp) is a proper list with
     exactly m conses. */
  if (!posfixnump(STACK_2)) error_posfixnum(STACK_2);
  if (!posfixnump(STACK_1)) error_posfixnum(STACK_1);
  var object obj = STACK_3;
  var uintV n = posfixnum_to_V(STACK_2);
  var uintV i;
  for (i = n; i > 0; i--) {
    if (!consp(obj)) goto no;
    obj = Cdr(obj);
  }
  { var uintV m = posfixnum_to_V(STACK_1);
    if (m < n) goto no;
    for (i = m-n; i > 0; i--) {
      if (!consp(obj)) {
        if (nullp(obj))
          break;
        else
          goto no;
      }
      obj = Cdr(obj);
    }
  }
  if (nullp(STACK_0) && !nullp(obj))
    goto no;
  VALUES1(T); skipSTACK(4); return;
 no:
  VALUES1(NIL); skipSTACK(4);
}

LISPFUN(proper_list_length_in_bounds_p,seclass_read,2,1,norest,nokey,0,NIL)
{ /* (sys::proper-list-length-in-bounds-p obj n) tests whether obj is a
     proper-list with at least n conses.
     (sys::proper-list-length-in-bounds-p obj n m) tests whether obj is a
     proper-list with at least n and at most m conses. */
  if (!posfixnump(STACK_1)) error_posfixnum(STACK_1);
  if (boundp(STACK_0) && !posfixnump(STACK_0)) error_posfixnum(STACK_0);
  var object tail = NIL;
  var object len = list_length(STACK_2,&tail);
  if (nullp(tail) && !nullp(len)) {
    var uintL l = I_to_UL(len);
    if ((posfixnum_to_V(STACK_1) <= l)
        && (!boundp(STACK_0) || (l <= posfixnum_to_V(STACK_0))))
      VALUES1(T);
    else
      VALUES1(NIL);
  } else
    VALUES1(NIL);
  skipSTACK(3);
}

/* proper_list_p(obj)
   returns true if obj is a proper list, i.e. a list which is neither dotted
   nor circular, i.e. a list which ends in NIL. */
global bool proper_list_p (object obj) {
  var object fast = obj;
  var object slow = fast;
  while (consp(fast)) {
    fast = Cdr(fast);
    if (atomp(fast))
      break;
    if (eq(fast,slow))
      return false;
    fast = Cdr(fast);
    slow = Cdr(slow);
  }
  return nullp(fast);
}

/* We cannot have lists longer than 1<<32 for RAM reasons
 but we must accept arbitrary positive integers in NTH, LAST &c.
 Here we truncate large integers to ~0.
 can trigger GC */
local maygc uintL get_integer_truncate (object number) {
  /* for speed, handle the most common case first */
  if (posfixnump(number)) {
   #if (intVsize>intLsize)
    if (posfixnum_to_V(number) >= vbitm(intLsize))
      return ~(uintL)0; /* most-positive-uintL */
   #endif
    return posfixnum_to_V(number);
  }
  number = check_pos_integer(number);
  if (uint32_p(number)) return I_to_UL(number);
  return ~(uintL)0; /* most-positive-uintL */
}

LISPFUNNR(nth,2)
{ /* (NTH integer list), CLTL p. 265 */
  var uintL count = get_integer_truncate(STACK_1);
  var object list = STACK_0;
  while (count--) { list = cdr(list); } /* count CDRs */
  VALUES1(car(list));                   /* one CAR */
  skipSTACK(2);
}

LISPFUNNR(first,1)
{ /* (FIRST list), CLTL p. 266 */
  VALUES1(car(popSTACK()));
}

LISPFUNNR(second,1)
{ /* (SECOND list), CLTL p. 266 */
  VALUES1(car(cdr(popSTACK())));
}

LISPFUNNR(third,1)
{ /* (THIRD list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(popSTACK()))));
}

LISPFUNNR(fourth,1)
{ /* (FOURTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(popSTACK())))));
}

LISPFUNNR(fifth,1)
{ /* (FIFTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(popSTACK()))))));
}

LISPFUNNR(sixth,1)
{ /* (SIXTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(cdr(popSTACK())))))));
}

LISPFUNNR(seventh,1)
{ /* (SEVENTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(cdr(cdr(popSTACK()))))))));
}

LISPFUNNR(eighth,1)
{ /* (EIGHTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(popSTACK())))))))));
}

LISPFUNNR(ninth,1)
{ /* (NINTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(popSTACK()))))))))));
}

LISPFUNNR(tenth,1)
{ /* (TENTH list), CLTL p. 266 */
  VALUES1(car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(popSTACK())))))))))));
}

LISPFUNNR(rest,1)
{ /* (REST list), CLTL p. 266 */
  VALUES1(cdr(popSTACK()));
}

LISPFUNNR(nthcdr,2)
{ /* (NTHCDR integer list), CLTL p. 267 */
  var uintL count = get_integer_truncate(STACK_1);
  var object list = STACK_0;
  while (count--) {
    if (consp(list))
      /* Walk list. */
      list = Cdr(list);
    else if (nullp(list))
      /* End of list reached. */
      break;
    else
      error_list(list);
  }
  VALUES1(list);
  skipSTACK(2);
}

/* (SYS::CONSES-P n object) determines whether the object is a list
 consisting of length n at least. Similar to
 (if (= n 0) t (consp (nthcdr (- n 1) object)))
 except that it is robust against dotted lists, or to
 (if (= n 0) t (and (listp object) (>= (length object) n)))
 except that it is robust against circular and dotted lists. */
LISPFUNNR(conses_p,2) {
  var uintL count = get_integer_truncate(STACK_1);
  var object list = STACK_0;
  value1 = T;
  if (count > 0) {
    if (atomp(list))
      value1 = NIL;
    else
      for (; --count > 0;) {
        list = Cdr(list);
        if (atomp(list)) {
          value1 = NIL;
          break;
        }
      }
  }
  mv_count=1;
  skipSTACK(2);
}

/* Get a replacement for the circular list
 can trigger GC */
local maygc object replace_circular_list (object list) {
  dynamic_bind(S(print_circle),T);
  pushSTACK(NIL);               /* no PLACE */
  pushSTACK(list); pushSTACK(TheSubr(subr_self)->name);
  check_value(error_condition,GETTEXT("~S: ~S is a circular list"));
  dynamic_unbind(S(print_circle));
  return value1;
}

LISPFUN(last,seclass_read,1,1,norest,nokey,0,NIL)
{ /* (LAST list [n]), CLtL2 p. 416-417, dpANS p. 14-34
 (defun last (list &optional (n 1))
   (check-type n (integer 0 *))
   (check-type list list)
   (do ((l list (cdr l))
        (r list)
        (i 0 (+ i 1)))
       ((atom l) r)
     (when (>= i n) (pop r)))) */
  var object intarg = popSTACK();
  /* check optional integer argument: */
  var uintL count = (boundp(intarg) ? get_integer_truncate(intarg) : 1);
  var object list = check_list(popSTACK());
  /* Optimisation of the two most common cases count=1 and count=0: */
  switch (count) {
    case 0: { last_0_restart:
      var object slow = list;
      while (consp(list)) {
        list = Cdr(list);
        if (atomp(list)) break;
        if (eq(list,slow)) {
          list = check_list(replace_circular_list(list));
          goto last_0_restart;
        }
        list = Cdr(list);
        slow = Cdr(slow);
      }
    } break;
    case 1: { last_1_restart:
      var object list2;
      var object slow = list;
      if (consp(list)) {
        while (1) {
          /* list is a Cons. */
          list2 = Cdr(list); if (atomp(list2)) break; list = list2;
          if (eq(list,slow)) {
            list = check_list(replace_circular_list(list));
            goto last_1_restart;
          }
          list2 = Cdr(list); if (atomp(list2)) break; list = list2;
          slow = Cdr(slow);
        }
      }
    }
      break;
    default: { last_default_restart:
      var object list2 = list;
      var object slow = list;
      var uintL ii = count;
      do {
        if (atomp(list2))
          goto done;
        list2 = Cdr(list2);
      } while (--ii);
      while (consp(list2)) {
        list2 = Cdr(list2); list = Cdr(list); if (atomp(list2)) break;
        if (eq(list,slow)) {
          list = check_list(replace_circular_list(list));
          goto last_default_restart;
        }
        list2 = Cdr(list2); list = Cdr(list);
      }
       done: ;
    }
      break;
  }
  VALUES1(list);
}

/* UP: Constructs a list with given elements.
 listof(len)
 > uintC len: wanted list length
 > on STACK: len Objects, first at the top
 < result: list of these objects
 removes len elements from the STACK
 changes STACK, can trigger GC */
modexp maygc object listof (uintC len) {
  pushSTACK(NIL); /* starting with empty list */
  /* Cons len times the arguments to the front of this list: */
  while (len--) {
    var object new_cons = allocate_cons();
    Cdr(new_cons) = popSTACK();
    Car(new_cons) = STACK_0;
    STACK_0 = new_cons;
  }
  return popSTACK();
}

LISPFUN(list,seclass_no_se,0,0,rest,nokey,0,NIL)
{ /* (LIST {object}), CLTL p. 267 */
  VALUES1(listof(argcount));
}

LISPFUN(liststar,seclass_no_se,1,0,rest,nokey,0,NIL)
{ /* (LIST* obj1 {object}), CLTL p. 267 */
  /* Former list already on the stack */
  /* Cons the argcount arguments to the front of this list: */
  while (argcount--) {
    var object new_cons = allocate_cons();
    Cdr(new_cons) = popSTACK(); /* next argument before */
    Car(new_cons) = STACK_0;
    STACK_0 = new_cons;
  }
  VALUES1(popSTACK());
}

LISPFUN(make_list,seclass_no_se,1,0,norest,key,1, (kw(initial_element)) )
{ /* (MAKE-LIST size :initial-element), CLTL p. 268 */
  if (!boundp(STACK_0)) /* check :initial-element */
    STACK_0 = NIL; /* default :initial-element is NIL */
  VALUES1(make_list(I_to_UL(check_uint32(STACK_1))));
  skipSTACK(2);
}

LISPFUN(append,seclass_read,0,0,rest,nokey,0,NIL)
{ /* (APPEND {list}), CLTL p. 268 */
  if (argcount==0) {
    VALUES1(NIL); /* no arguments -> return NIL as result */
  } else {
    /* Append arguments. Run the loop argcount-1 times: */
    while (--argcount) {
      /* STACK_0 = result list from right. */
      /* STACK_1 := (append STACK_1 STACK_0), increase STACK by 1: */
      var object list1;
      {
        var object list2 = popSTACK(); /* result list (from right) */
        list1 = STACK_0; /* Argument to be added to the front */
        STACK_0 = list2; /* stack resulting list */
      }
      /* list1 needs to be a list: */
      if (atomp(list1))
        if (nullp(list1))
          ; /* if list1=NIL: (append nil x) = x, do nothing */
        else
          error_list(list1);
      else {
        /* (append list1 STACK_0), and list1 is a Cons: */
        /* Copy list1 and keep last Cons: */
        var object run;
        pushSTACK(list1);
        {
          var object new_list = allocate_cons();
          run = STACK_0; /* run runs through the old list list1 */
          Car(new_list) = Car(run);
          STACK_0 = new_list;
          pushSTACK(new_list);
        }
        /* Loop: STACK_1 has the full copy, STACK_0 = LAST of it, */
        /* run = the corresponding Cons of the original list list1. */
        while ( run=Cdr(run), !endp(run) ) {
          /* one more Cons */
          pushSTACK(run); /* save run */
          var object new_cons = allocate_cons(); /* allocate new Cons */
          run = popSTACK(); /* put back run */
          Cdr(STACK_0) = new_cons; /* and add as CDR of the LAST */
          Car(new_cons) = Car(run); /* copy CAR */
          STACK_0 = new_cons; /* this is now the new LAST */
        }
        /* Copy ready. STACK_2 = current result list, */
        /* STACK_1 = copy of list1, STACK_0 = LAST of it. */
        run = popSTACK(); /* end of copy */
        list1 = popSTACK(); /* copy finished */
        /*if (!nullp(Cdr(run))) ????
          error_proper_list_dotted(TheSubr(subr_self)->name,Cdr(run));*/
        Cdr(run) = STACK_0; /* add result copy */
        STACK_0 = list1; /* and the is the new result list */
      }
    }
    VALUES1(popSTACK()); /* result list as value */
  }
}

LISPFUNNR(copy_list,1)
{ /* (COPY-LIST list), CLTL p. 268 */
  VALUES1(copy_list(check_list(popSTACK())));
}

/* UP: Copies an A-list
  copy_alist(alist)
  > alist: A-list
  < result: Copy of the A-list
  can trigger GC */
local maygc object copy_alist (object alist) {
  /* Algorithm:
     Instead of
       (mapcar #'(lambda (x) (if (consp x) (cons (car x) (cdr x)) x)) l)
     the list is first copied via copy-list, then the conses among the top
     level elements of the copy are replaced with conses with same CAR and CDR. */
  alist = copy_list(alist);
  pushSTACK(alist); /* save result list */
  /* a-list runs through to the result list */
  while (!endp(alist)) {
    if (mconsp(Car(alist))) {
      pushSTACK(alist); /* save a-list */
      var object new_cons = allocate_cons(); /* new Cons */
      alist = popSTACK(); /* a-list back */
      {
        var object old_cons = Car(alist);
        Car(new_cons) = Car(old_cons); Cdr(new_cons) = Cdr(old_cons);
      }
      Car(alist) = new_cons;
    }
    alist = Cdr(alist);
  }
  return popSTACK();
}

LISPFUNNR(copy_alist,1) /* (COPY-ALIST alist), CLTL p. 268 */
{ VALUES1(copy_alist(popSTACK())); }

/* UP: Copies a tree. */
local object copy_tree (object tree) {
  if (atomp(tree))
    return tree; /* Return atom unchanged  */
  else {
    check_STACK(); check_SP();
    pushSTACK(Cdr(tree)); /* Save CDR */
    {
      var object temp = copy_tree(Car(tree)); /* Copy the CAR recursively */
      tree = STACK_0;
      STACK_0 = temp; /* Save CAR copy */
      temp = copy_tree(tree); /* Copy the CDR recursively */
      pushSTACK(temp); /* Save CDR copy */
    }
    return cons_from_stack();
  }
}

LISPFUNNR(copy_tree,1) /* (COPY-TREE tree), CLTL p. 269 */
{ VALUES1(copy_tree(popSTACK())); }

LISPFUNNR(revappend,2)
{ /* (REVAPPEND list object), CLTL p. 269 */
  while (!endp(STACK_1)) {
    var object new_cons = allocate_cons(); /* new Cons */
    Car(new_cons) = Car(STACK_1); Cdr(new_cons) = STACK_0; /* (cons (car list) object) */
    STACK_0 = new_cons; /* This is the new, longer object */
    STACK_1 = Cdr(STACK_1); /* Shorten list */
  }
  VALUES1(popSTACK());
  skipSTACK(1);
}

LISPFUN(nconc,seclass_default,0,0,rest,nokey,0,NIL)
{ /* (NCONC {list}), CLTL p. 269 */
  if (argcount==0) {
    VALUES1(NIL); /* no arguments -> return NIL as result */
  } else {
    /* Append arguments. Run the loop for argcount-1 times: */
    while (--argcount) {
      /* STACK_0 = current result list from right. */
      /* STACK_1 := (nconc STACK_1 STACK_0), increase STACK by 1: */
      if (matomp(STACK_1))
        if (nullp(STACK_1)) {
          STACK_1 = STACK_0; skipSTACK(1); /* result list stays, skip argument */
        } else
          error_list(STACK_1);
      else {
        /* Add result list to (cdr (last STACK_1)): */
        var object list1 = STACK_1;
        var object list2;
        while (1) {
          /* Here list1 is a Cons. */
          list2 = Cdr(list1);
          if (atomp(list2))
            break;
          list1 = list2;
        }
        /* list1 is the last Cons of the argument STACK_1 */
        Cdr(list1) = popSTACK(); /* Add current result list */
        /* STACK_0 = new result list */
      }
    }
    VALUES1(popSTACK());
  }
}

LISPFUNN(nreconc,2)             /* (NRECONC list1 list2), CLTL p. 269 */
{
  var object list1 = check_list(STACK_1);
  var object list2 = STACK_0; skipSTACK(2);
  VALUES1(nreconc(list1,list2));
}

LISPFUNN(list_nreverse,1) /* (SYS::LIST-NREVERSE list) */
{ /* as (NREVERSE list), if list is a list. */
  VALUES1(nreverse(popSTACK()));
}

/* check that the argument is a non-circular list and return its length
 can trigger GC */
local inline maygc uintL check_list_length (gcv_object_t *list_) {
  while(1) {
    /* Give an error if the argument is not a list. (It's stupid to allow
       dotted lists of length > 0 but to forbid dotted lists of length 0,
       but that's how ANSI CL specifies it.) */
    if (!listp(*list_)) *list_ = check_list_replacement(*list_);
    var object dotted_p;
    var object llen = list_length(*list_,&dotted_p);
    if (!nullp(llen)) return I_to_UL(llen);
    *list_ = replace_circular_list(*list_);
  }
}

LISPFUN(butlast,seclass_read,1,1,norest,nokey,0,NIL)
{ /* (BUTLAST list [integer]), CLTL p. 271 */
  var object intarg = popSTACK();
  /* check optional integer argument: */
  var uintL count = (boundp(intarg) ? get_integer_truncate(intarg) : 1);
  var uintL len = check_list_length(&STACK_0); /* list length */
  if (len<=count) {
    VALUES1(NIL); skipSTACK(1); /* length(list)<=count -> return NIL */
  } else {
    var uintL new_len = len - count; /* >0 */
    /* Creates a copy of the first new_len conses of the list STACK_0: */
    var object new_list = make_list(new_len); /* allocate new list */
    /* Copy list elements one by one, until new_list is full: */
    var object new_run = new_list; /* runs through the new list */
    var object old_run = popSTACK(); /* runs through the old list */
    do {
      Car(new_run) = Car(old_run);
      old_run = Cdr(old_run); new_run = Cdr(new_run);
    } while (!atomp(new_run));
    VALUES1(new_list);
  }
}

LISPFUN(nbutlast,seclass_default,1,1,norest,nokey,0,NIL)
{ /* (NBUTLAST list [integer]), CLTL p. 271 */
  var object intarg = popSTACK();
  /* check optional integer argument: */
  var uintL count = (boundp(intarg) ? get_integer_truncate(intarg) : 1);
  var uintL len = check_list_length(&STACK_0); /* list length */
  if (len<=count) {
    VALUES1(NIL); skipSTACK(1); /* length(list)<=count -> return NIL */
  } else {
    var uintL new_len = len - count; /* >0 */
    var object run = STACK_0; /* runs through the list */
    /* take new_len-1 times the CDR and then set the CDR to NIL: */
    while (--new_len) run = Cdr(run);
    Cdr(run) = NIL;
    VALUES1(popSTACK()); /* return list */
  }
}

LISPFUNNR(ldiff,2)
{ /* (LDIFF list sublist), CLTL p. 272 */
  var object sublist = popSTACK();
  /* Search where sublist begins in list: */
  var uintL new_len = 0;
  var bool found_p = false;
  {
    var object listr = STACK_0;
   #ifndef X3J13_175
    while (!((found_p = eql(listr,sublist)) || endp(listr))) {
      listr = Cdr(listr); new_len++;
    }
   #else
    if (!listp(listr))
      error_list(listr);
    while (!((found_p = eql(listr,sublist)) || atomp(listr))) {
      listr = Cdr(listr); new_len++;
    }
   #endif
  }
  /* Return a copy of the first new_len conses of the list STACK_0: */
  var object new_list = make_list(new_len); /* allocate new list */
  /* Copy list elements one by one, until new_list is full: */
  var object new_run = new_list; /* runs through the new list */
  var object old_run = popSTACK(); /* runs through the old list */
  if (consp(new_run)) while (1) {  /* loop! */
    Car(new_run) = Car(old_run);
    if (atomp(Cdr(new_run))) {
      if (!found_p)
        Cdr(new_run) = Cdr(old_run);
      break;
    }
    old_run = Cdr(old_run); new_run = Cdr(new_run);
  }
  VALUES1(new_list);
}

/* check_cons(obj)
 > obj: an object
 < result: a cons, either the same as obj or a replacement
 can trigger GC */
local maygc object check_cons_replacement (object obj) {
  do {
    pushSTACK(NIL);               /* no PLACE */
    pushSTACK(obj);               /* TYPE-ERROR slot DATUM */
    pushSTACK(S(cons));           /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(obj); pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: ~S is not a pair"));
    obj = value1;
  } while (!consp(obj));
  return obj;
}
local inline maygc object check_cons (object obj) {
  if (!consp(obj))
    obj = check_cons_replacement(obj);
  return obj;
}

LISPFUNN(rplaca,2)              /* (RPLACA cons object), CLTL p. 272 */
{
  var object arg1 = check_cons(STACK_1);
  var object arg2 = STACK_0;
  skipSTACK(2);
  Car(arg1) = arg2;
  VALUES1(arg1);
}

LISPFUNN(prplaca,2)             /* (SYS::%RPLACA cons object) */
{ /* like (RPLACA cons object), but return object as value */
  var object arg1 = check_cons(STACK_1);
  var object arg2 = STACK_0;
  skipSTACK(2);
  Car(arg1) = arg2;
  VALUES1(arg2);
}

LISPFUNN(rplacd,2)              /* (RPLACD cons object), CLTL p. 272 */
{
  var object arg1 = check_cons(STACK_1);
  var object arg2 = STACK_0;
  skipSTACK(2);
  Cdr(arg1) = arg2;
  VALUES1(arg1);
}

LISPFUNN(prplacd,2)             /* (SYS::%RPLACD cons object) */
{ /* like (RPLACD cons object), but return object as value */
  var object arg1 = check_cons(STACK_1);
  var object arg2 = STACK_0;
  skipSTACK(2);
  Cdr(arg1) = arg2;
  VALUES1(arg2);
}

/* (funcall TESTFUN ...) */
#define CALL_TEST(p)  (*pcall_test)(p,*(p STACKop 3),value1)

/* UP: Replaces in the tree all elements x, which KEY passes the TESTFUNction,
 by NEW. Construktively (copying).
 subst(tree,stackptr,up_fun)
 > tree: the Tree
 > stackptr: *(stackptr-2) = NEW, *(stackptr-1) = KEY
 > up_fun: TESTFUN = Adress of the test function,
        called with same stackptr and with (KEY x) as argument.
        Returns true or false.
 < result: (evtl. newer) tree
 can trigger GC */
local maygc object subst (object tree, gcv_object_t* stackptr,
                          funarg_t* pcall_test) {
  /* First calculate (KEY tree) and call TESTFUN: */
  pushSTACK(tree); /* save tree */
  funcall_key(*(stackptr STACKop -1),tree); /* (KEY tree) */
  if (CALL_TEST(stackptr)) { /* (funcall TESTFUN ...) */
    /* Test ok */
    skipSTACK(1); return *(stackptr STACKop -2); /* return NEW as value */
  } else /* Test not ok */
    if (matomp(STACK_0)) {
      /* Argument is an atom -> keep it unchanged */
      return popSTACK();
    } else {
      /* Argument is a Cons -> call SUBST recursively: */
      check_STACK(); check_SP();
      /* call recursively for the CDR: */
      var object new_cdr = subst(Cdr(STACK_0),stackptr,pcall_test);
      pushSTACK(new_cdr); /* Save CDR result */
      /* call recursively for the CAR: */
      var object new_car = subst(Car(STACK_1),stackptr,pcall_test);
      if (eq(new_car,Car(STACK_1)) && eq(STACK_0,Cdr(STACK_1))) {
        /* both unchanged */
        skipSTACK(1); /* skip CDR result */
        return popSTACK();
      } else {
        STACK_1 = new_car; /* save CAR result */
        return cons_from_stack();
      }
    }
}

LISPFUN(subst,seclass_default,3,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (SUBST new old tree :test :test-not :key), CLTL p. 273 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  pushSTACK(STACK_5); /* newobj */
  /* stack layout: new, old, tree, test, test_not, key, new. */
  VALUES1(subst(STACK_4,&STACK_2,pcall_test)); /* do the substitution */
  skipSTACK(7);
}

LISPFUN(subst_if,seclass_default,3,0,norest,key,1, (kw(key)) )
{ /* (SUBST-IF new pred tree :key), CLTL p. 273 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  pushSTACK(STACK_3); /* newobj */
  /* stack layout: new, pred, tree, key, new. */
  VALUES1(subst(STACK_2,&STACK_2,&call_if)); /* do the substitution */
  skipSTACK(5);
}

LISPFUN(subst_if_not,seclass_default,3,0,norest,key,1, (kw(key)) )
{ /* (SUBST-IF-NOT new pred tree :key), CLTL p. 273 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  pushSTACK(STACK_3); /* newobj */
  /* stack layout: new, pred, tree, key, new. */
  VALUES1(subst(STACK_2,&STACK_2,&call_if_not)); /* do the substitution */
  skipSTACK(5);
}

/* UP: Replaces in the tree all elements x, which KEY passes the TESTFUNction,
 by NEW. Destructively (in-place).
 nsubst(tree,stackptr,up_fun)
 > tree: the Tree
 > stackptr: *(stackptr-2) = NEW, *(stackptr-1) = KEY
 > up_fun: TESTFUN = Adress of the test function,
        called with same stackptr and with (KEY x) as argument.
        Returns true or false.
 < result: same tree CAR
 can trigger GC */
local maygc object nsubst (object tree, gcv_object_t* stackptr,
                           funarg_t* pcall_test) {
  /* First calculate (KEY tree) and call TESTFUN: */
  pushSTACK(tree); /* save tree */
  funcall_key(*(stackptr STACKop -1),tree); /* (KEY tree) */
  if (CALL_TEST(stackptr)) { /* (funcall TESTFUN ...) */
    /* Test ok */
    skipSTACK(1); return *(stackptr STACKop -2); /* NEW as value */
  } else { /* Test not ok */
    if (mconsp(STACK_0)) {
      /* Argument is a Cons -> call NSUBST recursively: */
      check_STACK(); check_SP();
      { /* call recursively for the CDR: */
        var object modified_cdr = nsubst(Cdr(STACK_0),stackptr,pcall_test);
        Cdr(STACK_0) = modified_cdr;
      }
      { /* call recursively for the CAR: */
        var object modified_car = nsubst(Car(STACK_0),stackptr,pcall_test);
        Car(STACK_0) = modified_car;
      }
    }
    return popSTACK(); /* return original tree address */
  }
}

LISPFUN(nsubst,seclass_default,3,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (NSUBST new old tree :test :test-not :key), CLTL p. 274 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  pushSTACK(STACK_5); /* newobj */
  /* stack layout: new, old, tree, test, test_not, key, new. */
  VALUES1(nsubst(STACK_4,&STACK_2,pcall_test)); /* do the substitution */
  skipSTACK(7);
}

LISPFUN(nsubst_if,seclass_default,3,0,norest,key,1, (kw(key)) )
{ /* (NSUBST-IF new pred tree :key), CLTL p. 274 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  pushSTACK(STACK_3); /* newobj */
  /* stack layout: new, pred, tree, key, new. */
  VALUES1(nsubst(STACK_2,&STACK_2,&call_if)); /* do the substitution */
  skipSTACK(5);
}

LISPFUN(nsubst_if_not,seclass_default,3,0,norest,key,1, (kw(key)) )
{ /* (NSUBST-IF-NOT new pred tree :key), CLTL p. 274 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  pushSTACK(STACK_3); /* newobj */
  /* stack layout: new, pred, tree, key, new. */
  VALUES1(nsubst(STACK_2,&STACK_2,&call_if_not)); /* do the substitution */
  skipSTACK(5);
}

/* UP: return the first list element, whose CAR passed the TESTFUNction.
 sublis_assoc(stackptr)
 > *(stackptr+3) = alist
 > stackptr: *(stackptr-1) = KEY
 > *(stackptr-3) = TESTFUN = test function, called on each list element
       (u . v) with the same stackptr and with (KEY x) and u as arguments.
       returns true, when the test passes, false otherwise.
 < return: list element (a CONS) or NIL
 can trigger GC */
local maygc object sublis_assoc (gcv_object_t* stackptr)
{
  var object alist = *(stackptr STACKop 3);
  pushSTACK(alist); /* save the list ((u . v) ...) */
  while (!endp(STACK_0)) {
    /* How to treat atoms in the list?
       a. One can ignore them.
       b. One can signal an error on them.
       c. One can signal an error only for non-NIL atoms.
       Obviously (b) is best, because it provides the best possible
       error checking. But CLtL2 and CLHS both contain a "note" that
       suggests to some people that atoms are ignored, therefore I
       assume that there is code outside which assumes this behaviour,
       and we must not signal an error on it.
       Note: To other people this note suggests that only NILs are
       ignored, and they suggest (c). This is inconsistent with the
       definition of "association list" in the CLHS glossary and with
       the general use of alists as lookup tables.
       Therefore we implement (a).
       SDS 2003-03-08: I am changing the behavior to (c) because
       it is more in line with the ASSOC behavior */
    var object head = Car(STACK_0);
    if (mconsp(head)) { /* skip atoms in the list */
      /* test whether the 2-argument test function
         *(stackptr-3) (an adress!), called on u and the
         value in *(stackptr-2), returns true: */
      var bool erg = /* 2-argument test function, called on (KEY x) and u */
        (*(funarg_t*)TheMachineCode(*(stackptr STACKop -3)))
        ( stackptr, *(stackptr STACKop -2), Car(head) );
      if (erg) /* test passed ==> return x = (u . v) = (CAR alist) */
        return Car(popSTACK());
      /* test failed */
    } else if (!nullp(head))
      error_list(head);
    STACK_0 = Cdr(STACK_0); /* tail recursion */
  }
  skipSTACK(1); /* forget alist */
  /* reached list end ==> return NIL */
  return NIL;
}

/* UP: Replaces in tree all x by its A-LIST representation (by ASSOC):
 x is replaced by the first v, so that (u . v) is a member in ALIST and
 (KEY x) and u pass the TESTFUNction. Constructively (copying).
 sublis(tree,stackptr)
 > tree: the Tree
 > stackptr: *(stackptr-1) = KEY, *(stackptr+3) = ALIST,
             *(stackptr-2) is free for (KEY x)
 < result: (evtl. newer) Tree
 can trigger GC */
local maygc object sublis (object tree, gcv_object_t* stackptr) {
  /* First calculate (KEY tree) and call ASSOC: */
  pushSTACK(tree); /* save tree */
  funcall_key(*(stackptr STACKop -1),tree); /* (KEY tree) */
  *(stackptr STACKop -2) = value1; /* save for sublis_assoc */
  var object assoc_erg = sublis_assoc(stackptr);
  if (consp(assoc_erg)) { /* Test ok */
    skipSTACK(1); return Cdr(assoc_erg); /* (CDR (ASSOC ...)) as value */
  } else /* Test not ok */
    if (matomp(STACK_0)) {
      /* Argument is an atom -> keep unchanged */
      return popSTACK();
    } else {
      /* Argument is a Cons -> call SUBLIS recursively: */
      check_STACK(); check_SP();
      /* call recursively for the CDR: */
      var object new_cdr = sublis(Cdr(STACK_0),stackptr);
      pushSTACK(new_cdr); /* save CDR result */
      /* call recursively for the CAR: */
      var object new_car = sublis(Car(STACK_1),stackptr);
      if (eq(new_car,Car(STACK_1)) && eq(STACK_0,Cdr(STACK_1))) {
        /* both unchanged */
        skipSTACK(1); /* skip CDR result */
        return popSTACK();
      } else {
        STACK_1 = new_car; /* save CAR result */
        return cons_from_stack();
      }
    }
}

LISPFUN(sublis,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (SUBLIS alist tree :test :test-not :key), CLTL p. 274 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var gcv_object_t* stackptr = &STACK_1;
  var funarg_t* pcall_test = check_test_args(stackptr); /* Call with :TEST/:TEST-NOT arguments */
  /* on STACK_2,STACK_1 arguments. Returns true or false. */
  if (nullp(STACK_4)) { /* shortcut: nothing to do if alist = () */
    VALUES1(STACK_3);
    skipSTACK(5);
  } else {
    pushSTACK(NIL); /* Dummy */
    pushSTACK(make_machine_code(pcall_test)); /* Testfunction, because of Typeinfo=machine_type GC-safe! */
    /* stack layout: alist, tree, test, test_not, key, dummy, pcall_test. */
    VALUES1(sublis(STACK_5,stackptr)); /* do the substitution */
    skipSTACK(7);
  }
}

/* UP: Replaces in tree all x by its A-LIST representation (by ASSOC):
 x is replaced by the first v, so that (u . v) is a member in ALIST and
 (KEY x) and u pass the TESTFUNction. Destructively (in-place).
 sublis(tree,stackptr)
 > tree: the Tree
 > stackptr: *(stackptr-1) = KEY, *(stackptr+3) = ALIST,
             *(stackptr-2) is free for (KEY x)
 < result: same Tree CAR
 can trigger GC */
local maygc object nsublis (object tree, gcv_object_t* stackptr) {
  /* First calculate (KEY tree) and call ASSOC: */
  pushSTACK(tree); /* save tree */
  funcall_key(*(stackptr STACKop -1),tree); /* (KEY tree) */
  *(stackptr STACKop -2) = value1; /* save for sublis_assoc */
  var object assoc_erg = sublis_assoc(stackptr);
  if (consp(assoc_erg)) { /* Test ok */
    skipSTACK(1); return Cdr(assoc_erg); /* (CDR (ASSOC ...)) as value */
  } else { /* Test not ok */
    if (mconsp(STACK_0)) {
      /* Argument is a Cons -> call NSUBLIS recursively: */
      check_STACK(); check_SP();
      { /* call recursively for the CDR: */
        var object modified_cdr = nsublis(Cdr(STACK_0),stackptr);
        Cdr(STACK_0) = modified_cdr;
      }
      { /* call recursively for the CAR: */
        var object modified_car = nsublis(Car(STACK_0),stackptr);
        Car(STACK_0) = modified_car;
      }
    }
    return popSTACK(); /* return original tree address */
  }
}

LISPFUN(nsublis,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (NSUBLIS alist tree :test :test-not :key), CLTL p. 275 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var gcv_object_t* stackptr = &STACK_1;
  var funarg_t* pcall_test = check_test_args(stackptr); /* Call with :TEST/:TEST-NOT arguments */
                                       /* on STACK_2,STACK_1 arguments. Returns true or false. */
  if (nullp(STACK_4)) { /* shortcut: nothing to do if alist = () */
    VALUES1(STACK_3);
    skipSTACK(5);
  } else {
    pushSTACK(NIL); /* Dummy */
    pushSTACK(make_machine_code(pcall_test)); /* Testfunction, because of Typeinfo=machine_type GC-safe! */
    /* Stackaufbau: alist, tree, test, test_not, key, dummy, pcall_test. */
    VALUES1(nsublis(STACK_5,stackptr)); /* do the substitution */
    skipSTACK(7);
  }
}

/*  UP: find OBJ in LIS: (MEMBER OBJ LIS :TEST #'EQ) */
modexp object memq (const object obj, const object lis) {
  var object l = lis;
  while (consp(l)) {
    if (eq(Car(l),obj)) return l;
    l = Cdr(l);
  }
  if (!nullp(l))
    error_proper_list_dotted(TheSubr(subr_self)->name,l);
  return NIL;
}

/* (SYS::MEMQ OBJECT LIST) == (MEMBER OBJECT LIST :TEST #'EQ) */
LISPFUNNR(memq,2) {
  var object lis = popSTACK();
  var object obj = popSTACK();
  VALUES1(memq(obj,lis));
}

/* UP: Returns the rest of the list starting with the list element,
   which satisfies the TESTFUNction.
 member(list,stackptr,up_fun)
 > list: List
 > stackptr: *(stackptr-1) = KEY
 > up_fun: TESTFUN = Address of the test function,
        Called with same stackptr and with (KEY x) as argument.
        Returns true or false.
 < result: rest of list
 can trigger GC */
local maygc object member (object list, gcv_object_t* stackptr,
                           funarg_t* pcall_test) {
  while (!endp(list)) {
    pushSTACK(list); /* save rest of list */
    funcall_key(*(stackptr STACKop -1),Car(list)); /* (KEY x) */
    {
      var bool erg = CALL_TEST(stackptr); /* (funcall TESTFUN ...) */
      list = popSTACK();
      if (erg)
        return list; /* Test ok -> list as result */
    }
    /* Test not ok -> call (member ... (cdr list)): */
    list = Cdr(list); /* tail-end-recursively */
  }
  return list; /* NIL as result */
}

LISPFUN(member,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (MEMBER item list :test :test-not :key), CLTL p. 275 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  VALUES1(member(STACK_3,&STACK_1,pcall_test)); /* do the search */
  skipSTACK(5);
}

LISPFUN(member_if,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (MEMBER-IF pred list :key), CLTL p. 275 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(member(STACK_1,&STACK_1,&call_if)); /* do the search */
  skipSTACK(3);
}

LISPFUN(member_if_not,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (MEMBER-IF-NOT pred list :key), CLTL p. 275 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(member(STACK_1,&STACK_1,&call_if_not)); /* do the search */
  skipSTACK(3);
}

LISPFUNNR(tailp,2) /* (TAILP sublist list), CLTL p. 275 */
#ifndef X3J13_175
/* (defun tailp (sublist list)
     (do ((l list (rest l)))
         ((endp l) (null sublist))
       (when (eq l sublist) (return t)))) */
#else
/* (defun tailp (sublist list)
     (loop
       (when (eql sublist list) (return t))
       (when (atom list) (return nil))
       (setq list (cdr list)))) */
#endif
{
  var object list = popSTACK();
  var object sublist = popSTACK();
  #ifndef X3J13_175
  while (!endp(list)) {
    if (eq(list,sublist))
      goto yes;
    list = Cdr(list);
  }
  if (nullp(sublist))
    goto yes;
  #else
  while (1) {
    if (eql(list,sublist))
      goto yes;
    if (atomp(list))
      break;
    list = Cdr(list);
  }
  #endif
  VALUES1(NIL); return; /* NIL as value */
 yes:
  VALUES1(T); return; /* T as value */
}

LISPFUN(adjoin,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (ADJOIN item list :test :test-not :key), CLTL p. 276 */
  /* first test on (MEMBER (key item) list :test :test-not :key): */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  {
    var object item = STACK_4;
    pushSTACK(item); /* save item */
    funcall_key(STACK_1,item); STACK_5 = value1; /* item := (funcall key item) */
  }
  /* stack layout: (key item), list, test, test-not, key, item */
  if (nullp(member(STACK_4,&STACK_2,pcall_test))) { /* do search */
    /* item not yet found in list: must cons */
    var object new_cons = allocate_cons();
    Cdr(new_cons) = STACK_4; /* = list */
    Car(new_cons) = STACK_0; /* = item */
    VALUES1(new_cons);
  } else {
    VALUES1(STACK_4); /* list as value */
  }
  skipSTACK(6); return;
}

LISPFUN(acons,seclass_no_se,3,0,norest,nokey,0,NIL)
{ /* (ACONS key val alist) = (CONS (CONS key val) alist), CLTL p. 279 */
  {
    var object new_cons = allocate_cons();
    Car(new_cons) = STACK_2; /* key */
    Cdr(new_cons) = STACK_1; /* value */
    STACK_1 = new_cons;
  }
  VALUES1(cons_from_stack());
  skipSTACK(1);
}

LISPFUN(pairlis,seclass_read,2,1,norest,nokey,0,NIL)
{ /* (PAIRLIS keys data [alist]), CLTL p. 280 */
  if (!boundp(STACK_0))
    STACK_0=NIL; /* ALIST defaults to NIL */
  pushSTACK(STACK_2);     /* keys */
  pushSTACK(STACK_(1+1)); /* data */
  while (1) { /* stack layout: keys, data, alist, keysr, datar. */
    if (endp(STACK_0)) /* data is over? */
      if (endp(STACK_1)) /* keys are over? */
        goto end;
      else
        goto error_lengths;
    else
      if (endp(STACK_1)) /* keys are over? */
        goto error_lengths;
      else {
        var object new_cons = allocate_cons();
        Car(new_cons) = Car(STACK_1); /* next key as CAR */
        Cdr(new_cons) = Car(STACK_0); /* next data as CDR */
        STACK_1 = Cdr(STACK_1); /* shorten keys */
        STACK_0 = Cdr(STACK_0); /* shorten data */
        pushSTACK(new_cons);
        new_cons = allocate_cons(); /* one more new Cons */
        Car(new_cons) = popSTACK(); /* with (key . data) as CAR */
        Cdr(new_cons) = STACK_2; /* and a-list as CDR */
        STACK_2 = new_cons; /* results in new a-list */
      }
  }
 error_lengths:
  skipSTACK(3);
  {
    var object data_list = popSTACK();
    var object keys_list = popSTACK();
    pushSTACK(data_list); pushSTACK(keys_list);
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: lists ~S and ~S are not of same length"));
  }
 end:
  VALUES1(STACK_2); skipSTACK(5); /* a-list as value */
}

/* UP: Returns the first list element, which CAR satisfies the TESTFUNction.
 assoc(alist,stackptr)
 > alist: A-list
 > stackptr: *(stackptr-1) = KEY
 > up_fun: TESTFUN = Address of the test function. Called for list elements
        (u . v) with same stackptr and with (KEY u) as argument.
        Returns true or false.
 < result: List element (a Cons) or NIL
 can trigger GC */
local maygc object assoc (object alist, gcv_object_t* stackptr,
                          funarg_t* pcall_test) {
 start:
  if (endp(alist)) /* end of alist ==> NIL */
    return NIL;
  else {
    var object head = Car(alist);
    if (mconsp(head)) { /* skip atomic list elements */
      pushSTACK(alist); /* save rest of list ((u . v) ...) */
      funcall_key(*(stackptr STACKop -1),Car(head)); /* (KEY u) */
      var bool erg = CALL_TEST(stackptr); /* (funcall TESTFUN ...) */
      alist = popSTACK();
      if (erg)
        /* Test ok -> x = (u . v) = (CAR alist) as result */
        return Car(alist);
      /* Test not ok */
    } else if (!nullp(head))
      error_list(head);
    /* call tail-recursively (assoc ... (cdr alist)) */
    alist = Cdr(alist); goto start;
  }
}

LISPFUN(assoc,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (ASSOC item alist :test :test-not :key), CLTL p. 280 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  VALUES1(assoc(STACK_3,&STACK_1,pcall_test)); /* do the search */
  skipSTACK(5);
}

LISPFUN(assoc_if,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (ASSOC-IF pred alist :key), CLTL p. 280 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(assoc(STACK_1,&STACK_1,&call_if)); /* do the search */
  skipSTACK(3);
}

LISPFUN(assoc_if_not,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (ASSOC-IF-NOT pred alist :key), CLTL p. 280 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(assoc(STACK_1,&STACK_1,&call_if_not)); /* do the search */
  skipSTACK(3);
}

/* UP: Returns the first list element, which CDR satisfies the TESTFUNction.
 rassoc(alist,stackptr)
 > alist: A-list
 > stackptr: *(stackptr-1) = KEY
 > up_fun: TESTFUN = Address of the test function. Called for list elements
        (u . v) with same stackptr and with (KEY v) as argument.
        Returns true or false.
 < result: List element (a Cons) or NIL
 can trigger GC */
local maygc object rassoc (object alist, gcv_object_t* stackptr,
                           funarg_t* pcall_test) {
 start:
  if (endp(alist)) /* end of alist ==> NIL */
    return NIL;
  else {
    var object head = Car(alist);
    if (mconsp(head)) { /* skip atomic list elements */
      pushSTACK(alist); /* save rest of list ((u . v) ...) */
      funcall_key(*(stackptr STACKop -1),Cdr(head)); /* (KEY v) */
      var bool erg = CALL_TEST(stackptr); /* (funcall TESTFUN ...) */
      alist = popSTACK();
      if (erg)
        /* Test ok -> x = (u . v) = (CAR alist) as result */
        return Car(alist);
      /* Test not ok */
    } else if (!nullp(head))
      error_list(head);
    /* Call tail-recursively (rassoc ... (cdr alist)) */
    alist = Cdr(alist); goto start;
  }
}

LISPFUN(rassoc,seclass_default,2,0,norest,key,3,
        (kw(test),kw(test_not),kw(key)) )
{ /* (RASSOC item alist :test :test-not :key), CLTL p. 281 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  var funarg_t* pcall_test = check_test_args(&STACK_1); /* :TEST/:TEST-NOT arguments on STACK_2,STACK_1 */
  VALUES1(rassoc(STACK_3,&STACK_1,pcall_test)); /* do the search */
  skipSTACK(5);
}

LISPFUN(rassoc_if,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (RASSOC-IF pred alist :key), CLTL p. 281 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(rassoc(STACK_1,&STACK_1,&call_if)); /* do the search */
  skipSTACK(3);
}

LISPFUN(rassoc_if_not,seclass_default,2,0,norest,key,1, (kw(key)) )
{ /* (RASSOC-IF-NOT pred alist :key), CLTL p. 281 */
  check_key_arg(&STACK_0); /* :KEY argument on STACK_0 */
  VALUES1(rassoc(STACK_1,&STACK_1,&call_if_not)); /* do the search */
  skipSTACK(3);
}

/* functions making lists sequences: */

LISPFUNN(list_upd,2)
{ /* #'(lambda (seq pointer) (cdr pointer)) */
  VALUES1(cdr(popSTACK())); skipSTACK(1);
}

LISPFUNN(list_endtest,2)
{ /* #'(lambda (seq pointer) (endp pointer)) */
  VALUES_IF(endp(STACK_0)); skipSTACK(2);
}

LISPFUNN(list_fe_init,1)
{ /* #'(lambda (seq) (revappend seq nil)) */
  pushSTACK(NIL); C_revappend();
}

LISPFUNN(list_access,2)
{ /* #'(lambda (seq pointer) (car pointer)) */
  var object pointer = check_cons(STACK_0);
  VALUES1(Car(pointer));
  skipSTACK(2);
}

LISPFUNN(list_access_set,3)
{ /* #'(lambda (seq pointer value) (rplaca pointer value)) */
  var object pointer = check_cons(STACK_1);
  var object value = STACK_0;
  Car(pointer) = value;
  VALUES1(value);
  skipSTACK(3);
}

/* UP: get the list element at the given index
 elt_up(seq,index)
 > seq
 > index
 < result: list element at this index */
local object elt_up (object seq, object index) {
  var object l = seq;
  var object n = Fixnum_0;
  while (1) {
    if (atomp(l))
      goto index_too_large;
    if (eq(n,index))
      break;
    l = Cdr(l);
    n = fixnum_inc(n,1);
  }
  return l;
 index_too_large:
  pushSTACK(index);             /* TYPE-ERROR slot DATUM */
  pushSTACK(NIL);
  pushSTACK(seq); pushSTACK(index); pushSTACK(TheSubr(subr_self)->name);
  {
    var object tmp;
    pushSTACK(S(integer)); pushSTACK(Fixnum_0); pushSTACK(n);
    tmp = listof(1); pushSTACK(tmp); tmp = listof(3);
    STACK_3 = tmp;              /* TYPE-ERROR slot EXPECTED-TYPE */
  }
  error(type_error,GETTEXT("~S: index ~S too large for ~S"));
}

LISPFUNN(list_elt,2)
{ /* (lambda (seq index)
       (do ((L seq (cdr L)) (N 0 (1+ N)))
           (nil)
         (if (atom L) (error "index ~S too large for ~S" index seq))
         (if (= N index) (return (car L))))) */
  var object index = popSTACK();
  var object seq = popSTACK();
  VALUES1(Car(elt_up(seq,index)));
}

LISPFUNN(list_set_elt,3)
{ /* (lambda (seq index value)
       (do ((L seq (cdr L)) (N 0 (1+ N)))
           (nil)
         (if (atom L) (error "index ~S too large for ~S" index seq))
         (if (= N index) (return (rplaca L value))))) */
  var object nthcdr = elt_up(STACK_2,STACK_1);
  VALUES1(Car(nthcdr) = popSTACK());
  skipSTACK(2);
}

LISPFUNN(list_init_start,2)
{ /* (lambda (seq index)
       (do ((L seq (cdr L)) (N 0 (1+ N)))
           ((= N index) (return L))
         (if (atom L) (error "start index ~S too large for ~S" index seq)))) */
  var object index = popSTACK();
  var object seq = popSTACK();
  var object l = seq;
  var object n = Fixnum_0;
  while (!eq(n,index)) {
    if (atomp(l))
      goto index_too_large;
    l = Cdr(l);
    n = fixnum_inc(n,1);
  }
  VALUES1(l); return;
 index_too_large:
  pushSTACK(seq);
  pushSTACK(index);             /* TYPE-ERROR slot DATUM */
  {
    var object tmp;
    pushSTACK(S(integer)); pushSTACK(Fixnum_0); pushSTACK(n);
    tmp = listof(3); pushSTACK(tmp); /* TYPE-ERROR slot EXPECTED-TYPE */
  }
  pushSTACK(STACK_2);           /* seq */
  pushSTACK(STACK_2);           /* index */
  pushSTACK(S(list_init_start));
  error(type_error,GETTEXT("~S: start index ~S too large for ~S"));
}

LISPFUNN(list_fe_init_end,2)
{ /* (lambda (seq index)
       (if (<= 0 index)
         (do* ((L1 nil (cons (car L2) L1))
               (L2 seq (cdr L2))
               (i index (1- i)))
              ((zerop i) L1)
           (if (atom L2)
             (error "end index ~S too large for ~S" index seq)))
         (error "end index ~S too large for ~S" index seq))) */
  /* index is known to be an Integer >=0. */
  pushSTACK(NIL);                               /* L1 := nil */
  { var object seq = STACK_2; pushSTACK(seq); } /* L2 := seq */
  pushSTACK(Fixnum_0);                          /* i := 0 */
  while (1) {
    /* stack layout: seq, index, L1, L2, i */
    if (eq(STACK_0,STACK_3))    /* i=index ? */
      goto end;
    if (matomp(STACK_1))        /* (atom L2) ? */
      goto index_too_large;
    var object new_cons = allocate_cons();      /* new Cons */
    var object L2 = STACK_1; STACK_1 = Cdr(L2); /* (pop L2) */
    Car(new_cons) = Car(L2);                    /* as CAR */
    Cdr(new_cons) = STACK_2;                    /* L1 as CDR */
    STACK_2 = new_cons;                         /* L1 := new Cons */
    STACK_0 = fixnum_inc(STACK_0,1);            /* i := i+1 */
  }
 index_too_large:
  pushSTACK(STACK_3);           /* TYPE-ERROR slot DATUM */
  {
    var object tmp;
    pushSTACK(S(integer)); pushSTACK(Fixnum_0); pushSTACK(STACK_(0+3));
    tmp = listof(3); pushSTACK(tmp); /* TYPE-ERROR slot EXPECTED-TYPE */
  }
  { pushSTACK(STACK_(4+2));
    pushSTACK(STACK_(3+3));
    pushSTACK(S(list_fe_init_end));
    error(type_error,GETTEXT("~S: end index ~S too large for ~S"));
  }
 end:
  VALUES1(STACK_2); /* return L1 */
  skipSTACK(5);
}

