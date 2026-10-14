/*
 * PCRE - Perl Compatible Regular Expressions
 * <http://www.pcre.org/> up to v 8.01
 * Copyright (C) 2003-2010 Sam Steingold
 * GPL2
 */

#include "clisp.h"
#include "config.h"

#if defined(HAVE_PCRE_H)
# include <pcre.h>
#elif defined(HAVE_PCRE_PCRE_H)
# include <pcre/pcre.h>
#else
# error No PCRE headers!
#endif

#ifndef FOREIGN
#error FOREIGN is not defined.
#error PCRE needs a CLISP built with the foreign pointer datatype support.
#error Go into the main CLISP makefile and add a -DFOREIGN=void*
#error to CFLAGS make variable and rebuild CLISP before coming back here.
#endif

#include <string.h>             /* for memcpy(3) */

DEFMODULE(pcre,"PCRE")

DEFVAR(pcre_version_cache,NIL)
DEFUN(PCRE::PCRE-VERSION,)
{ value1 = !nullp(O(pcre_version_cache)) ? O(pcre_version_cache)
    : (O(pcre_version_cache) = safe_to_string(pcre_version()));
  value2 = fixnum(PCRE_MAJOR); value3 = fixnum(PCRE_MINOR);
  value4 = `STRINGIFY(PCRE_DATE)`; mv_count = 4; }
#if defined(HAVE_PCRE_CONFIG)
DEFCHECKER(pcre_config_option, prefix=PCRE_CONFIG, UTF8 NEWLINE LINK-SIZE \
           POSIX-MALLOC-THRESHOLD MATCH-LIMIT STACKRECURSE UNICODE-PROPERTIES \
           MATCH-LIMIT-RECURSION BSR)
DEFUN(PCRE::PCRE-CONFIG, &optional what)
{
  if (missingp(STACK_0)) {
    int pos = 0;
    for (; pos < pcre_config_option_map.size; pos++) {
      int ret;
      begin_system_call();
      pcre_config(pcre_config_option_map.table[pos].c_const,&ret);
      end_system_call();
      pushSTACK(*pcre_config_option_map.table[pos].l_const);
      pushSTACK(L_to_I(ret));
    }
    VALUES1(listof(2*pcre_config_option_map.size));
  } else {
    int option = pcre_config_option(STACK_0);
    int ret = 0;
    begin_system_call(); pcre_config(option,&ret); end_system_call();
    VALUES1(L_to_I(ret));
  }
  skipSTACK(1);
}
#endif

DEFUN(PCRE::PCRE-FREE,fp)
{ /* free the pcre* or pcre_extra* object */
  object fp = popSTACK();
  if (fpointerp(fp) && fp_validp(TheFpointer(fp))) {
    void *datum = TheFpointer(fp)->fp_pointer;
    if (datum) {
      pcre_free(datum);
      TheFpointer(fp)->fp_pointer = NULL;
      mark_fp_invalid(TheFpointer(fp));
      VALUES1(T);
    } else VALUES1(NIL);
  } else VALUES1(NIL);
}

DEFFLAGSET(pcre_compile_flags, PCRE_CASELESS PCRE_MULTILINE PCRE_DOTALL \
           PCRE_EXTENDED PCRE_ANCHORED PCRE_DOLLAR_ENDONLY PCRE_EXTRA   \
           PCRE_NOTBOL PCRE_NOTEOL PCRE_UNGREEDY PCRE_NOTEMPTY          \
           PCRE_NO_AUTO_CAPTURE PCRE_AUTO_CALLOUT PCRE_PARTIAL          \
           PCRE_DFA_SHORTEST PCRE_DFA_RESTART PCRE_FIRSTLINE PCRE_DUPNAMES \
           PCRE_NEWLINE_CR PCRE_NEWLINE_LF PCRE_NEWLINE_CRLF PCRE_NEWLINE_ANY \
           PCRE_NEWLINE_ANYCRLF PCRE_BSR_ANYCRLF PCRE_BSR_UNICODE       \
           PCRE_JAVASCRIPT_COMPAT PCRE_NO_START_OPTIMIZE                \
           PCRE_NO_START_OPTIMISE PCRE_PARTIAL_HARD PCRE_NOTEMPTY_ATSTART)
DEFCHECKER(pcre_options,prefix=PCRE,bitmasks=both,\
           CASELESS MULTILINE DOTALL EXTENDED ANCHORED DOLLAR-ENDONLY EXTRA \
           NOTBOL NOTEOL UNGREEDY NOTEMPTY UTF8 NO-AUTO-CAPTURE NO-UTF8-CHECK \
           AUTO-CALLOUT PARTIAL DFA-SHORTEST DFA-RESTART FIRSTLINE DUPNAMES \
           NEWLINE-CR NEWLINE-LF NEWLINE-CRLF NEWLINE-ANY NEWLINE-ANYCRLF \
           BSR-ANYCRLF BSR-UNICODE JAVASCRIPT-COMPAT NO-START-OPTIMIZE  \
           NO-START-OPTIMISE PARTIAL-HARD NOTEMPTY-ATSTART)
DEFUN(PCRE:PCRE-COMPILE,string &key STUDY IGNORE-CASE MULTILINE DOTALL  \
      EXTENDED ANCHORED DOLLAR-ENDONLY EXTRA NOTBOL NOTEOL UNGREEDY     \
      NOTEMPTY NO-AUTO-CAPTURE AUTO-CALLOUT PARTIAL DFA-SHORTEST DFA-RESTART \
      FIRSTLINE DUPNAMES NEWLINE-CR NEWLINE-LF NEWLINE-CRLF NEWLINE-ANY \
      NEWLINE-ANYCRLF BSR-ANYCRLF BSR-UNICODE JAVASCRIPT-COMPAT         \
      NO-START-OPTIMIZE NO-START-OPTIMISE PARTIAL-HARD NOTEMPTY-ATSTART)
{ /* compile the pattern, return PATTERN struct */
  int options = PCRE_UTF8 | pcre_compile_flags();
  bool study = !missingp(STACK_0);
  const char *error_message;
  int error_offset;
  pcre *compiled_pattern;
  gcv_object_t *string = &STACK_1;
 pcre_compile_restart:
  with_string_0(check_string(*string),Symbol_value(S(utf_8)),pattern, {
      begin_system_call();
      compiled_pattern = pcre_compile(pattern,options,&error_message,
                                      &error_offset,NULL);
      end_system_call();
    });
  if (compiled_pattern == NULL) { /* error */
    pushSTACK(NIL);               /* no PLACE */
    pushSTACK(safe_to_string(error_message));
    pushSTACK(fixnum(error_offset));
    pushSTACK(*string); pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S(~S) at ~S: ~S"));
    *string = value1;
    goto pcre_compile_restart;
  }
  pushSTACK(allocate_fpointer(compiled_pattern));
  pushSTACK(STACK_0); pushSTACK(``PCRE::PCRE-FREE``); funcall(L(finalize),2);
  if (study) {
    pcre_extra *pe;
    begin_system_call();
    pe = pcre_study(compiled_pattern,0,&error_message);
    end_system_call();
    if (error_message != NULL) { /* error */
      STACK_0 = NIL;           /* no PLACE - discard compiled_pattern */
      pushSTACK(asciz_to_string(error_message,GLO(misc_encoding)));
      pushSTACK(*string); pushSTACK(TheSubr(subr_self)->name);
      check_value(error_condition,"~S(~S): ~S");
      *string = value1;
      goto pcre_compile_restart;
    }
    if (pe) pushSTACK(allocate_fpointer(pe));
    else pushSTACK(NIL);
  } else pushSTACK(NIL);
  funcall(`PCRE::MAKE-PAT`,2);
  skipSTACK(2);
}

/* can trigger GC */
static void check_pattern (gcv_object_t *pat, pcre** compiled_pattern,
                           pcre_extra** study)
{ /* extract compiled pattern and the study results from the PATTERN */
  *pat = check_classname(*pat,`PCRE::PATTERN`);
  /* FIXME for derived structs! */
  *compiled_pattern =
    (pcre*)TheFpointer(TheStructure(*pat)->recdata[1])->fp_pointer;
  if (nullp(TheStructure(*pat)->recdata[2])) *study = NULL;
  else *study =
    (pcre_extra*)TheFpointer(TheStructure(*pat)->recdata[2])->fp_pointer;
}

/* two objects should be on STACK for the error message */
DEFCHECKER(error_pcre_code,prefix=PCRE_ERROR, NOMATCH NULL BADOPTION    \
           BADMAGIC UNKNOWN-NODE NOMEMORY NOSUBSTRING MATCHLIMIT CALLOUT \
           DFA-UITEM DFA-UCOND DFA-UMLIMIT DFA-WSSIZE DFA-RECURSE       \
           BADUTF8 BADUTF8-OFFSET PARTIAL BADPARTIAL :INTERNAL BADCOUNT \
           DFA-UITEM DFA-UCOND DFA-UMLIMIT DFA-WSSIZE DFA-RECURSE       \
           RECURSIONLIMIT NULLWSLIMIT BADNEWLINE)
nonreturning_function(static, error_pcre, (int status)) {
  pushSTACK(error_pcre_code_reverse(status));
  pushSTACK(sfixnum(status)); pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,"~S/~S=~S: ~S ~S");
}


#define PCRE_INFO(opt,val,bad)    do {                  \
    begin_system_call();                                \
    status = pcre_fullinfo(c_pat,study,opt,val);        \
    end_system_call();                                  \
    if (status < bad) error_pcre(status);               \
  } while(0)
DEFCHECKER(fullinfo_arg,prefix=PCRE_INFO,OPTIONS :SIZE CAPTURECOUNT     \
           BACKREFMAX FIRSTBYTE FIRSTTABLE LASTLITERAL                  \
           NAMEENTRYSIZE NAMECOUNT NAMETABLE STUDYSIZE                  \
           /*DEFAULT-TABLES*/ OKPARTIAL JCHANGED HASCRORLF MINLENGTH)
/* PCRE_INFO_DEFAULTTABLES -- does not look useful
       Return a pointer to the internal default character tables within  PCRE.
       The  fourth  argument should point to an unsigned char * variable. This
       information call is provided for internal use by the pcre_study() func-
       tion.  External  callers  can  cause PCRE to use its internal tables by
       passing a NULL table pointer. */
static object fullinfo_options (pcre *c_pat, pcre_extra *study) {
  unsigned long int options;
  int status;
  PCRE_INFO(PCRE_INFO_OPTIONS,&options,0);
  return pcre_options_to_list(options);
}
static object fullinfo_size (pcre *c_pat, pcre_extra *study, int opt) {
  size_t length;
  int status;
  PCRE_INFO(opt,&length,0);
  return size_to_I(length);
}
static object fullinfo_int (pcre *c_pat, pcre_extra *study, int opt) {
  int ret, status;
  PCRE_INFO(opt,&ret,0);
  return L_to_I(ret);
}
static object fullinfo_bool (pcre *c_pat, pcre_extra *study, int opt) {
  int ret, status;
  PCRE_INFO(opt,&ret,0);
  return ret == 1 ? T : NIL;
}
#if defined(PCRE_INFO_FIRSTBYTE)
static object fullinfo_firstbyte (pcre *c_pat, pcre_extra *study) {
  int value, status;
  PCRE_INFO(PCRE_INFO_FIRSTBYTE,&value,-2);
  if (status == 0) return int_char(value);
  else if (status == -1) return `:BOL`;
  else if (status == -2) return NIL;
  else NOTREACHED;
}
#endif
static object fullinfo_firsttable (pcre *c_pat, pcre_extra *study) {
  unsigned char table[256];
  object ret = allocate_bit_vector(Atype_Bit,256);
  int status;
  void *data = TheSbvector(ret)->data;
  /* no need to pin ret because pcre_fullinfo does not block */
  handle_fault_range(PROT_READ_WRITE,(aint)data,(aint)data + sizeof(table));
  begin_system_call();
  status = pcre_fullinfo(c_pat,study,PCRE_INFO_FIRSTTABLE,&table);
  if (status >= 0) memcpy(data,table,sizeof(table));
  end_system_call();
  if (status < 0) error_pcre(status);
  return ret;
}
static object fullinfo_lastliteral (pcre *c_pat, pcre_extra *study) {
  int value, status;
  PCRE_INFO(PCRE_INFO_LASTLITERAL,&value,0);
  if (status == 0) return int_char(value);
  else return NIL;
}
#if defined(PCRE_INFO_NAMECOUNT) && defined(PCRE_INFO_NAMEENTRYSIZE) && defined(PCRE_INFO_NAMETABLE)
static object fullinfo_nametable (pcre *c_pat, pcre_extra *study) {
  int count, size, pos, status;
  char *table;
  begin_system_call();
  status = pcre_fullinfo(c_pat,study,PCRE_INFO_NAMECOUNT,&count);
  if (status < 0) { end_system_call(); error_pcre(status); }
  status = pcre_fullinfo(c_pat,study,PCRE_INFO_NAMEENTRYSIZE,&size);
  if (status < 0) { end_system_call(); error_pcre(status); }
  status = pcre_fullinfo(c_pat,study,PCRE_INFO_NAMETABLE,&table);
  end_system_call();
  if (status < 0) error_pcre(status);
  for (pos = 0; pos < count; pos++, table+=size) {
    pushSTACK(allocate_cons());
    Car(STACK_0) = asciz_to_string(table+2,GLO(misc_encoding));
    Cdr(STACK_0) = fixnum((table[0]<<8) + table[1]);
  }
  return listof(count);
}
#endif
DEFUN(PCRE:PATTERN-INFO,pattern &optional request)
{
  pcre *c_pat;
  pcre_extra *study;
  check_pattern(&STACK_1,&c_pat,&study);
  if (missingp(STACK_0)) {
    int count = 0;
    pushSTACK(`:OPTIONS`); pushSTACK(fullinfo_options(c_pat,study)); count+=2;
    pushSTACK(S(Ksize));
    pushSTACK(fullinfo_size(c_pat,study,PCRE_INFO_SIZE)); count+=2;
    pushSTACK(`:CAPTURECOUNT`);
    pushSTACK(fullinfo_int(c_pat,study,PCRE_INFO_CAPTURECOUNT)); count+=2;
#  if defined(PCRE_INFO_FIRSTBYTE)
    pushSTACK(`:FIRSTBYTE`);pushSTACK(fullinfo_firstbyte(c_pat,study));count+=2;
#  endif
    pushSTACK(`:FIRSTTABLE`);
    pushSTACK(fullinfo_firsttable(c_pat,study)); count+=2;
    pushSTACK(`:LASTLITERAL`);
    pushSTACK(fullinfo_lastliteral(c_pat,study)); count+=2;
#  if defined(PCRE_INFO_NAMEENTRYSIZE)
    pushSTACK(`:BACKREFMAX`);
    pushSTACK(fullinfo_int(c_pat,study,PCRE_INFO_BACKREFMAX)); count+=2;
#  endif
#  if defined(PCRE_INFO_NAMEENTRYSIZE)
    pushSTACK(`:NAMEENTRYSIZE`);
    pushSTACK(fullinfo_int(c_pat,study,PCRE_INFO_NAMEENTRYSIZE)); count+=2;
#  endif
#  if defined(PCRE_INFO_NAMECOUNT)
    pushSTACK(`:NAMECOUNT`);
    pushSTACK(fullinfo_int(c_pat,study,PCRE_INFO_NAMECOUNT)); count+=2;
#  endif
#  if defined(PCRE_INFO_STUDYSIZE)
    pushSTACK(`:STUDYSIZE`);
    pushSTACK(fullinfo_size(c_pat,study,PCRE_INFO_STUDYSIZE)); count+=2;
#  endif
#  if defined(PCRE_INFO_NAMECOUNT) && defined(PCRE_INFO_NAMEENTRYSIZE) && defined(PCRE_INFO_NAMETABLE)
    pushSTACK(`:NAMETABLE`);
    pushSTACK(fullinfo_nametable(c_pat,study)); count+=2;
#  endif
#  if defined(PCRE_INFO_OKPARTIAL)
    pushSTACK(`:OKPARTIAL`);
    pushSTACK(fullinfo_bool(c_pat,study,PCRE_INFO_OKPARTIAL)); count+=2;
#  endif
#  if defined(PCRE_INFO_JCHANGED)
    pushSTACK(`:JCHANGED`);
    pushSTACK(fullinfo_bool(c_pat,study,PCRE_INFO_JCHANGED)); count+=2;
#  endif
#  if defined(PCRE_INFO_HASCRORLF)
    pushSTACK(`:HASCRORLF`);
    pushSTACK(fullinfo_bool(c_pat,study,PCRE_INFO_HASCRORLF)); count+=2;
#  endif
#  if defined(PCRE_INFO_MINLENGTH)
    pushSTACK(`:MINLENGTH`);
    pushSTACK(fullinfo_int(c_pat,study,PCRE_INFO_MINLENGTH)); count+=2;
#  endif
    VALUES1(listof(count));
  } else {
    int arg = fullinfo_arg(STACK_0);
    switch (arg) {
      case PCRE_INFO_OPTIONS: VALUES1(fullinfo_options(c_pat,study)); break;
      case PCRE_INFO_SIZE:
        VALUES1(fullinfo_size(c_pat,study,PCRE_INFO_SIZE)); break;
      case PCRE_INFO_CAPTURECOUNT: case PCRE_INFO_BACKREFMAX:
#    if defined(PCRE_INFO_NAMEENTRYSIZE)
      case PCRE_INFO_NAMEENTRYSIZE:
#    endif
#    if defined(PCRE_INFO_NAMECOUNT)
      case PCRE_INFO_NAMECOUNT:
#    endif
#    if defined(PCRE_INFO_STUDYSIZE)
      case PCRE_INFO_STUDYSIZE:
#    endif
#    if defined(PCRE_INFO_MINLENGTH)
      case PCRE_INFO_MINLENGTH:
#    endif
        VALUES1(fullinfo_int(c_pat,study,arg)); break;
#    if defined(PCRE_INFO_OKPARTIAL)
      case PCRE_INFO_OKPARTIAL:
#    endif
#    if defined(PCRE_INFO_JCHANGED)
      case PCRE_INFO_JCHANGED:
#    endif
#    if defined(PCRE_INFO_HASCRORLF)
      case PCRE_INFO_HASCRORLF:
#    endif
        VALUES1(fullinfo_bool(c_pat,study,arg)); break;
#    if defined(PCRE_INFO_FIRSTBYTE)
      case PCRE_INFO_FIRSTBYTE: VALUES1(fullinfo_firstbyte(c_pat,study)); break;
#    endif
      case PCRE_INFO_FIRSTTABLE:
        VALUES1(fullinfo_firsttable(c_pat,study)); break;
      case PCRE_INFO_LASTLITERAL:
        VALUES1(fullinfo_lastliteral(c_pat,study)); break;
#    if defined(PCRE_INFO_NAMECOUNT) && defined(PCRE_INFO_NAMEENTRYSIZE) && defined(PCRE_INFO_NAMETABLE)
      case PCRE_INFO_NAMETABLE: VALUES1(fullinfo_nametable(c_pat,study)); break;
#    endif
      default: NOTREACHED;
    }
  }
  skipSTACK(2);
}


DEFUN(PCRE:PCRE-NAME-TO-INDEX,pattern name)
{ /* pcre_get_stringnumber() : named substring index in OVECTOR */
  pcre *c_pat;
  pcre_extra *study;
  int index;
  check_pattern(&STACK_1,&c_pat,&study);
#if defined(HAVE_PCRE_GET_STRINGNUMBER)
 restart_pcre_get_stringnumber:
  with_string_0(check_string(STACK_0),GLO(misc_encoding),name, {
      index = pcre_get_stringnumber(c_pat,name);
    });
  if (index>0) VALUES1(fixnum(index));
  else { /* error */
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(STACK_1);         /* name */
    pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: ~S is not a valid pattern name"));
    STACK_0 = value1;
    goto restart_pcre_get_stringnumber;
  }
  skipSTACK(2);
#else /* PCRE versions before 4.0 did not have pcre_get_stringnumber() */
  pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S (~S ~S): PCRE library lacks pcre_get_stringnumber()"));
#endif
}

DEFFLAGSET(pcre_exec_flags, PCRE_ANCHORED PCRE_NOTBOL PCRE_NOTEOL \
           PCRE_NOTEMPTY PCRE_PARTIAL PCRE_DFA_SHORTEST PCRE_DFA_RESTART)
DEFUN(PCRE:PCRE-EXEC,pattern subject &key WORK-SPACE DFA BOOLEAN OFFSET \
      ANCHORED NOTBOL NOTEOL NOTEMPTY PARTIAL DFA-SHORTEST DFA-RESTART)
{ /* match the SUBJECT string against a pre-compiled PATTERN;
     return a vector of MATCH structures or NIL if no matches */
  int options = pcre_exec_flags();
  int offset = check_uint_default0(popSTACK());
  bool bool_p = !missingp(STACK_0);
  bool dfa_p = !missingp(STACK_1);
  int workspace_size = check_uint_defaulted(STACK_2,20);
  int *ovector;
  int capture_count, ovector_size, ret;
  pcre *c_pat;
  pcre_extra *study;
  skipSTACK(3); /* drop all options */
  check_pattern(&STACK_1,&c_pat,&study);
  begin_system_call();
  ret = pcre_fullinfo(c_pat,study,PCRE_INFO_CAPTURECOUNT,&capture_count);
  end_system_call();
  if (ret < 0) error_pcre(ret);
  /* when DFA is enabled, the number of matches is not easily estimated */
  ovector_size = 3 * (capture_count + (dfa_p ? workspace_size : 1));
 pcre_exec_retry:
  ovector = (int*)alloca(sizeof(int)*ovector_size);
# if !defined(HAVE_PCRE_DFA_EXEC)
  /* use pcre_exec instead */
#  define pcre_dfa_exec(re,st,su,sb,of,op,ov,os,ws,wz) \
              pcre_exec(re,st,su,sb,of,op,ov,os)
# endif
  with_string_0(check_string(STACK_0),Symbol_value(S(utf_8)),subject, {
      begin_system_call();
      /* subject_bytelen is the length of subject in bytes,
         defined in with_string_0 */
      ret = dfa_p
        ? pcre_dfa_exec(c_pat,study,subject,subject_bytelen,offset,options,
                        ovector,ovector_size,
                        (int*)alloca(sizeof(int)*workspace_size),workspace_size)
        : pcre_exec(c_pat,study,subject,subject_bytelen,offset,options,
                    ovector,ovector_size);
      end_system_call();
    });
  if (ret == PCRE_ERROR_NOMATCH) VALUES1(NIL);
  else if (ret == 0) {          /* not enough space in ovector */
    ovector_size <<= 1;
    goto pcre_exec_retry;
  } else if (ret > 0) {
    if (bool_p) VALUES1(T); /* success indicator */
    else { /* return a vector */
      int pos, ov_pos;
      ASSERT(ret <= ovector_size);
      pushSTACK(allocate_vector(ret)); /* return value */
      for (pos = ov_pos = 0; pos < ret; pos++, ov_pos+=2)
        if (ovector[ov_pos] >= 0) {
          pushSTACK(L_to_I(ovector[ov_pos]));
          pushSTACK(L_to_I(ovector[ov_pos+1]));
          funcall(`PCRE::MAKE-MATCH-BOA`,2);
          TheSvector(STACK_0)->data[pos] = value1;
        }
      VALUES1(popSTACK());
    }
  } else error_pcre(ret);
  skipSTACK(2);                 /* drop pattern & subject */
}

void module__pcre__init_function_2 (module_t* module);
void module__pcre__init_function_2 (module_t* module)
{ /* the original pcre_malloc() and pcre_free() cause a crash in FINALIZE */
  pcre_malloc = malloc;
  pcre_free = free;
}

