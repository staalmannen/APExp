/*
 * functional arguments, like :TEST, :TEST-NOT, and :KEY
 * the common part of list.d, sequence.d, weak.d
 * extracted by Sam Steingold 2007-12-26
 */

#include "lispbibl.c"

/* UP: Checks the :KEY argument
 check_key_arg()
 > *pkey_arg: optional argument
 < *pkey_arg: correct KEY function */
global void check_key_arg (gcv_object_t *pkey_arg) {
  if (missingp(*pkey_arg))
    *pkey_arg = L(identity); /* :KEY defaults to #'IDENTITY */
}

/* Subroutine to compute the test :TEST
 call_test(fun,arg1,arg2)
 > *fun: the test function
 > arg1: the first item to compare
 > arg2: the second item
 < result: true if the test is okay, otherwise false.
 can trigger GC */
funarg_t call_test, call_test_not;
funarg_t call_test_eq, call_test_eql, call_test_equal, call_test_equalp;
funarg_t call_test_not_eq, call_test_not_eql, call_test_not_equal, call_test_not_equalp;

global maygc bool call_test (const gcv_object_t* fun,
                             object arg1, object arg2) {
  /* Per CLTL p.247 do a (funcall testfun arg1 arg2): */
  pushSTACK(arg1); pushSTACK(arg2);
  funcall(*(fun STACKop 1),2);
  return !nullp(value1);
}
/* special case the most frequent cases: */
global maygc bool call_test_eq (const gcv_object_t* fun,
                                object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 1),L(eq)))*/;
  return eq(arg2,arg1); }
global maygc bool call_test_eql (const gcv_object_t* fun,
                                 object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 1),L(eql)))*/;
  return eql(arg2,arg1); }
global maygc bool call_test_equal (const gcv_object_t* fun,
                                   object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 1),L(equal)))*/;
  return equal(arg2,arg1); }
global maygc bool call_test_equalp (const gcv_object_t* fun,
                                    object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 1),L(equalp)))*/;
  return equalp(arg2,arg1); }

/* Subroutine to compute the test :TEST-NOT
 call_test_not(fun,arg1,arg2)
 > *fun: the test function
 > arg1: the first item to compare
 > arg2: the second item
 < result: true if the test is okay, otherwise false.
 can trigger GC */
global maygc bool call_test_not (const gcv_object_t* fun,
                                 object arg1, object arg2) {
  /* Per CLTL p.247 do a (not (funcall testfun arg1 arg2)): */
  pushSTACK(arg1); pushSTACK(arg2);
  funcall(*(fun STACKop 0),2);
  return nullp(value1);
}
/* special case the most frequent cases: */
global maygc bool call_test_not_eq (const gcv_object_t* fun,
                                    object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 0),L(eq)))*/;
  return !eq(arg2,arg1); }
global maygc bool call_test_not_eql (const gcv_object_t* fun,
                                     object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 0),L(eql)))*/;
  return !eql(arg2,arg1); }
global maygc bool call_test_not_equal (const gcv_object_t* fun,
                                       object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 0),L(equal)))*/;
  return !equal(arg2,arg1); }
global maygc bool call_test_not_equalp (const gcv_object_t* fun,
                                        object arg1, object arg2)
{ (void)fun/*ASSERT(eq(*(fun STACKop 0),L(equalp)))*/;
  return !equalp(arg2,arg1); }

/* for -IF and -IF-NOT functions */
global maygc bool call_if (const gcv_object_t* stackptr,
                           object arg1, object arg2) {
  (void)arg1;         /* unused */
  /* Per CLTL p. 247 call (funcall predicate arg2): */
  pushSTACK(arg2); funcall(*(stackptr STACKop 1),1);
  return !nullp(value1);
}
global maygc bool call_if_not (const gcv_object_t* stackptr,
                               object arg1, object arg2) {
  (void)arg1;   /* unused */
  /* Per CLTL p. 247 call (not (funcall predicate arg2)): */
  pushSTACK(arg2); funcall(*(stackptr STACKop 1),1);
  return nullp(value1);
}

/* Error when both :TEST and :TEST-NOT are supplied
 error_both_tests(); */
nonreturning_function(local, error_both_tests, (void)) {
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,
        GETTEXT("~S: must not specify both :TEST and :TEST-NOT arguments"));
}

/* UP: Check the :TEST, :TEST-NOT - arguments
 check_test_args()
 > stackptr: Pointer to the STACK
 > *(stackptr+1): :TEST argument
 > *(stackptr+0): :TEST-NOT argument
 < *(stackptr+1): computed :TEST argument
 < *(stackptr+0): computed :TEST-NOT argument
 < call_test: Adress of a test function */
global funarg_t* check_test_args (gcv_object_t* stackptr) {
  var object test_arg = *(stackptr STACKop 1);
  if (!boundp(test_arg))
    *(stackptr STACKop 1) = test_arg = NIL;
  /* test_arg is the :TEST argument */
  var object test_not_arg = *(stackptr STACKop 0);
  if (!boundp(test_not_arg))
    *(stackptr STACKop 0) = test_not_arg = NIL;
  /* test_not_arg is the :TEST-NOT argument */
  if (nullp(test_not_arg)) { /* :TEST-NOT was not specified */
    if (nullp(test_arg))
      *(stackptr STACKop 1) = test_arg = L(eql); /* :TEST defaults to #'EQL */
    if (subrp(test_arg))
      switch (TheSubr(test_arg)->fastcmp) {
        case fastcmp_eq: return &call_test_eq;
        case fastcmp_eql: return &call_test_eql;
        case fastcmp_equal: return &call_test_equal;
        case fastcmp_equalp: return &call_test_equalp;
      }
    return &call_test;
  }
  if (!nullp(test_arg)) error_both_tests();
  if (subrp(test_not_arg))
    switch (TheSubr(test_not_arg)->fastcmp) {
      case fastcmp_eq: return &call_test_not_eq;
      case fastcmp_eql: return &call_test_not_eql;
      case fastcmp_equal: return &call_test_not_equal;
      case fastcmp_equalp: return &call_test_not_equalp;
    }
  return &call_test_not;
}

