/*
 * CLISP interface to GNU regex
 * originally by Bruno Haible 14.4.1995
 * rewritten by Sam Steingold 2003-08-06
 */

#include "clisp.h"
#include "config.h"
#include <sys/types.h>          /* regex.h needs this */
#include <stdlib.h>             /* declare malloc(), free() */
#include <stdio.h>              /* BUFSIZ */
#include <regex.h>

#ifndef FOREIGN
#error FOREIGN is not defined.
#error REGEXP needs a CLISP built with the foreign pointer datatype support.
#error Go into the main CLISP makefile and add a -DFOREIGN=void*
#error to CFLAGS make variable and rebuild CLISP before coming back here.
#endif
#ifndef HAVE_ALLOCA
/* clisp.h probably defines alloca... */
#endif

DEFMODULE(regexp,"REGEXP")

DEFFLAGSET(regexp_compile_flags, REG_EXTENDED REG_ICASE REG_NEWLINE REG_NOSUB)
DEFUN(REGEXP::REGEXP-COMPILE, pattern &key EXTENDED IGNORE-CASE NEWLINE NOSUB)
{ /* compile the pattern into a regular expression */
  int cflags = regexp_compile_flags();
  object pattern = check_string(popSTACK());
  int status;
  regex_t* re;
 restart_regcomp:
  re = (regex_t*)clisp_malloc(sizeof(regex_t));
  with_string_0(pattern,GLO(misc_encoding),patternz, {
    begin_system_call();
    status = regcomp(re,patternz,cflags);
    end_system_call();
  });
  if (status) {
    char buf[BUFSIZ];
    begin_system_call();
    regerror(status,re,buf,BUFSIZ);
    free(re);
    end_system_call();
    pushSTACK(NIL); /* no PLACE */
    pushSTACK(NIL); pushSTACK(pattern);
    STACK_1 = asciz_to_string(buf,GLO(misc_encoding));
    pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,"~S (~S): ~S");
    pattern = value1;
    goto restart_regcomp;
  }
  pushSTACK(allocate_fpointer((FOREIGN)re));
  pushSTACK(STACK_0);pushSTACK(``REGEXP::REGEXP-FREE``);funcall(L(finalize),2);
  VALUES1(popSTACK());          /* foreign pointer */
}

DEFUN(REGEXP::REGEXP-FREE, compiled)
{ /* release the contents and the data of the compiled pattern */
  object fp = popSTACK();
  if (fpointerp(fp) && fp_validp(TheFpointer(fp))) {
    regex_t *re = (regex_t*)TheFpointer(fp)->fp_pointer;
    if (re) {
      regfree(re); free(re);
      TheFpointer(fp)->fp_pointer = NULL;
      mark_fp_invalid(TheFpointer(fp));
      VALUES1(T);
    } else VALUES1(NIL);
  } else VALUES1(NIL);
}

typedef enum { ret_values, ret_list, ret_vector } rettype_t;
#define CHECK_RETTYPE(x)                                                \
  (eq(x,S(list)) ? ret_list : eq(x,S(vector)) ? ret_vector : ret_values)

DEFFLAGSET(regexp_exec_flags, REG_NOTBOL REG_NOTEOL)
DEFUN(REGEXP::REGEXP-EXEC,pattern string &key           \
      RETURN-TYPE BOOLEAN :START :END NOTBOL NOTEOL)
{ /* match the compiled pattern against the string */
  int eflags = regexp_exec_flags();
  object string = (STACK_4 = check_string(STACK_4));
  unsigned int length = vector_length(string);
  unsigned int start = check_uint_defaulted(STACK_1,0);
  unsigned int end = check_uint_defaulted(STACK_0,length);
  int status;
  bool bool_p = !missingp(STACK_2);
  rettype_t rettype = CHECK_RETTYPE(STACK_3);
  regex_t *re;
  regmatch_t *ret;
  skipSTACK(4);                 /* drop all options */
  for (;;) {
    STACK_1 = check_fpointer(STACK_1,true);
    re = (regex_t*)TheFpointer(STACK_1)->fp_pointer;
    if (re != NULL) break;
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(STACK_(1+1)); pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: NULL pattern ~S"));
    STACK_1 = value1;
  }
  string = STACK_0;
  if (end != length || start != 0) {
    pushSTACK(sfixnum((int)(end-start)));
    pushSTACK(S(Kelement_type)); pushSTACK(S(character));
    pushSTACK(S(Kdisplaced_to)); pushSTACK(string);
    pushSTACK(S(Kdisplaced_index_offset)); pushSTACK(posfixnum(start));
    funcall(L(make_array),7);
    string = value1;
  }
  begin_system_call();
  ret = (regmatch_t*)alloca((re->re_nsub+1)*sizeof(regmatch_t));
  end_system_call();
  if (ret == NULL) OS_error();
  with_string_0(string,GLO(misc_encoding),stringz, {
    begin_system_call();
    status = regexec(re,stringz,re->re_nsub+1,ret,eflags);
    end_system_call();
  });
  if (bool_p) {
    VALUES_IF(!status);         /* success indicator */
  } else if (status) {
    switch (rettype) {
      case ret_values: VALUES0; break;        /* VALUES => no values */
      case ret_list:   VALUES1(NIL); break;   /* LIST => () */
      case ret_vector: VALUES1(`#()`); break; /* VECTOR => #() */
    }
  } else {
    uintL re_count;
    for (re_count = 0; re_count <= re->re_nsub; re_count++)
      if (ret[re_count].rm_so >= 0 && ret[re_count].rm_eo >= 0) {
        pushSTACK(posfixnum(start+ret[re_count].rm_so));
        pushSTACK(posfixnum(start+ret[re_count].rm_eo));
        funcall(`REGEXP::MAKE-MATCH-BOA`,2); pushSTACK(value1);
      } else pushSTACK(NIL);
    switch (rettype) {
      case ret_values:
        if (re_count < fixnum_to_V(Symbol_value(S(multiple_values_limit)))) {
          STACK_to_mv(re_count);
          break;
        } /* else FALLTHROUGH */
      case ret_list:
        VALUES1(listof(re_count));
        break;
      case ret_vector:
        VALUES1(vectorof(re_count));
        break;
    }
  }
  skipSTACK(2);                 /* drop pattern & string */
}
