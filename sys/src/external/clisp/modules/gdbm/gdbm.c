/*
 * GDBM - The GNU database manager
 * <http://www.gnu.org/software/gdbm/>
 * Copyright (C) 2007  Masayuki Onjo <onjo@lispuser.net>
 * Copyright (C) 2007-2008, 2010  Sam Steingold <sds@gnu.org>
 * GPL2
 */

#include "clisp.h"
#include "config.h"

#if defined(HAVE_STRING_H)
# include <string.h>            /* memcpy */
#endif
#if defined(HAVE_UNISTD_H)
# include <unistd.h>            /* for lseek */
#endif

#if defined(HAVE_GDBM_H)
# include <gdbm.h>
#elif defined(HAVE_GDBM_GDBM_H)
# include <gdbm/gdbm.h>
#else
# error No GDBM headers!
#endif

/* gotta do it before DEFMODULE */
typedef enum {
  GDBM_DATA_STRING,
  GDBM_DATA_VECTOR,
  /* No support for sub-byte bit vectors because if we do, we have to
   * keep the vector length in the datum too (to avoid having #*10100000
   * retrieved when #*101 was stored), and the length would take a full
   * word which would nix any potential saving from using bits instead
   * of full bytes (this is similar to sub-byte :ELEMENT-TYPE for streams,
   * see <http://clisp.cons.org/impnotes/stream-dict.html#eltype>).
   * Also, Atype_16Bit is not exported from lispbibl.
   *     GDBM_DATA_BIT_VECTOR,
   *     GDBM_DATA_2BIT_VECTOR,
   *     GDBM_DATA_4BIT_VECTOR, */
  GDBM_DATA_8BIT_VECTOR,
  /*     GDBM_DATA_16BIT_VECTOR, */
  GDBM_DATA_32BIT_VECTOR,
  GDBM_DATA_INTEGER,
  GDBM_DATA_SINGLE_FLOAT,
  GDBM_DATA_DOUBLE_FLOAT,
  GDBM_DATA_NOTYPE              /* raise an error on conversion */
} gdbm_data_t;

/* must be distinct from all gdbm_setopt options */
#ifdef GDBM_COALESCEBLKS
# define GDBM_SETOPT_MAX_OPT  GDBM_COALESCEBLKS
#else
# define GDBM_SETOPT_MAX_OPT  10
#endif
#define GDBM_DEFAULT_VALUE_TYPE (GDBM_SETOPT_MAX_OPT+1)
#define GDBM_DEFAULT_KEY_TYPE   (GDBM_SETOPT_MAX_OPT+2)

DEFMODULE(gdbm,"GDBM");

/* CL::BIT-VECTOR EXT::2BIT-VECTOR EXT::4BIT-VECTOR EXT::16BIT-VECTOR */
DEFCHECKER(check_data_type, default=GDBM_DATA_NOTYPE, enum=gdbm_data_t, \
           prefix=GDBM_DATA, CL::STRING CL::VECTOR                      \
           EXT::8BIT-VECTOR EXT::32BIT-VECTOR                           \
           CL::INTEGER CL::SINGLE-FLOAT CL::DOUBLE-FLOAT)
DEFCHECKER(check_gdbm_errno, prefix=GDBM, NO-ERROR MALLOC-ERROR              \
           BLOCK-SIZE-ERROR FILE-OPEN-ERROR FILE-WRITE-ERROR FILE-SEEK-ERROR \
           FILE-READ-ERROR BAD-MAGIC-NUMBER EMPTY-DATABASE CANT-BE-READER    \
           CANT-BE-WRITER READER-CANT-DELETE READER-CANT-STORE               \
           READER-CANT-REORGANIZE UNKNOWN-UPDATE ITEM-NOT-FOUND              \
           REORGANIZE-FAILED CANNOT-REPLACE ILLEGAL-DATA OPT-ALREADY-SET     \
           OPT-ILLEGAL)
nonreturning_function(static, error_gdbm, (char *fatal_message)) {
  end_blocking_system_call(); /* in case we are called from _gdbm_fatal() */
  pushSTACK(`GDBM::GDBM-ERROR`);
  pushSTACK(`:MESSAGE`);
  if (fatal_message) {
    pushSTACK(asciz_to_string(fatal_message, GLO(misc_encoding)));
    pushSTACK(S(Kcode)); pushSTACK(`:FATAL`);
  } else {
    pushSTACK(safe_to_string(gdbm_strerror(gdbm_errno)));
    pushSTACK(S(Kcode)); pushSTACK(check_gdbm_errno_reverse(gdbm_errno));
  }
  pushSTACK(`"~S: ~A"`);
  pushSTACK(TheSubr(subr_self)->name);
  pushSTACK(STACK_4); /* message */
  funcall(L(error_of_type), 8);
  NOTREACHED;
}

DEFVAR(gdbm_version_cache,NIL)
DEFUN(GDBM::GDBM-VERSION,)
{ VALUES1(!nullp(O(gdbm_version_cache)) ? O(gdbm_version_cache)
          : (O(gdbm_version_cache) = safe_to_string(gdbm_version))); }

/* can trigger GC */
#define GDBM_SLOT_FILE  1
#define GDBM_SLOT_PATH  2
#define GDBM_SLOT_KEY   3
#define GDBM_SLOT_VAL   4
static GDBM_FILE check_gdbm (gcv_object_t *gdbm, gdbm_data_t *key,
                             gdbm_data_t *val, bool require_valid_handle)
{ /* gdbm is modified, so it has to be a pointer */
  *gdbm = check_classname(*gdbm,`GDBM::GDBM`);
  if (key && *key == GDBM_DATA_NOTYPE)
    *key = (gdbm_data_t)
      posfixnum_to_V(TheStructure(*gdbm)->recdata[GDBM_SLOT_KEY]);
  if (val && *val == GDBM_DATA_NOTYPE)
    *val = (gdbm_data_t)
      posfixnum_to_V(TheStructure(*gdbm)->recdata[GDBM_SLOT_VAL]);
  { object fp = TheStructure(*gdbm)->recdata[GDBM_SLOT_FILE];
    if (fpointerp(fp)) return (GDBM_FILE)TheFpointer(fp)->fp_pointer;
    else if (require_valid_handle) {
      pushSTACK(`GDBM::GDBM-ERROR`);
      pushSTACK(`:MESSAGE`);
      pushSTACK(`"open GDBM file required"`);
      pushSTACK(S(Kcode)); pushSTACK(`:CLOSED-FILE`);
      pushSTACK(`"~S: ~A"`);
      pushSTACK(TheSubr(subr_self)->name);
      pushSTACK(STACK_4); /* message */
      funcall(L(error_of_type), 8);
      NOTREACHED;
    } else return NULL;
  }
}

#define SYSCALL(statement) begin_blocking_system_call(); statement; end_blocking_system_call()

static object open_gdbm (object path, int bsize, int rw, int mode) {
  GDBM_FILE gdbm;
  with_string_0(path, GLO(pathname_encoding), name, {
      SYSCALL(gdbm = gdbm_open(name, bsize, rw, mode,
                               (void (*)(void))error_gdbm));
    });
  if (gdbm == NULL) error_gdbm(NULL);
  return allocate_fpointer(gdbm);
}

DEFCHECKER(gdbm_open_read_write, default=GDBM_WRCREAT, prefix=GDBM,     \
           READER WRITER WRCREAT NEWDB)
DEFCHECKER(gdbm_open_option, default=0, prefix=GDBM, SYNC NOLOCK FAST)
#if defined(HAVE_GDBM_OPEN)
DEFUN(GDBM::GDBM-OPEN, name &key BLOCKSIZE READ-WRITE OPTION MODE   \
      DEFAULT-KEY-TYPE DEFAULT-VALUE-TYPE)
{
  gdbm_data_t default_value_type = check_data_type(popSTACK());
  gdbm_data_t default_key_type = check_data_type(popSTACK());
  int mode = check_uint_defaulted(popSTACK(), 0644);
  int rw_opt1 = gdbm_open_option(popSTACK());
  int rw_opt2 = gdbm_open_read_write(popSTACK());
  int rw = rw_opt1 | rw_opt2;
  int bsize = check_uint_defaulted(popSTACK(), 512);
  if (typep_classname(STACK_0,`GDBM::GDBM`)) { /* reuse */
    if (!check_gdbm(&STACK_0,&default_key_type,&default_value_type,false)) {
      value1 = open_gdbm(TheStructure(STACK_0)->recdata[GDBM_SLOT_PATH],
                         bsize, rw, mode); /* reopen */
      TheStructure(STACK_0)->recdata[GDBM_SLOT_FILE] = value1;
    }
    TheStructure(STACK_0)->recdata[GDBM_SLOT_KEY]=fixnum(default_key_type);
    TheStructure(STACK_0)->recdata[GDBM_SLOT_VAL]=fixnum(default_value_type);
    VALUES1(popSTACK());        /* return the argument */
    return;
  }
  pushSTACK(open_gdbm(physical_namestring(STACK_0), bsize, rw, mode));
  pushSTACK(STACK_1);         /* path */
  pushSTACK(fixnum(default_key_type));
  pushSTACK(fixnum(default_value_type));
  funcall(`GDBM::MAKE-GDBM`,4);
  STACK_0 = value1;        /* save GDBM object, drop path */
  pushSTACK(STACK_0); pushSTACK(``GDBM::GDBM-CLOSE``);
  funcall(L(finalize),2);
  VALUES1(popSTACK());      /* restore */
}
#endif  /* HAVE_GDBM_OPEN */

DEFUN(GDBM:GDBM-DEFAULT-KEY-TYPE, dbf) {
  gdbm_data_t key = GDBM_DATA_NOTYPE;
  (void)check_gdbm(&STACK_0,&key,NULL,false); skipSTACK(1);
  VALUES1(check_data_type_reverse(key));
}
DEFUN(GDBM:GDBM-DEFAULT-VALUE-TYPE, dbf) {
  gdbm_data_t val = GDBM_DATA_NOTYPE;
  (void)check_gdbm(&STACK_0,NULL,&val,false); skipSTACK(1);
  VALUES1(check_data_type_reverse(val));
}

#if defined(HAVE_GDBM_CLOSE)
DEFUN(GDBM:GDBM-CLOSE, dbf)
{
  GDBM_FILE dbf = check_gdbm(&STACK_0,NULL,NULL,false);
  if (dbf) {
    SYSCALL(gdbm_close(dbf));
    TheStructure(STACK_0)->recdata[GDBM_SLOT_FILE] = NIL;
    VALUES1(T);
  } else
    VALUES1(NIL);
  skipSTACK(1);
}
#endif  /* HAVE_GDBM_CLOSE */

#if defined(HAVE_GDBM_FDESC)
DEFUN(GDBM:GDBM-FILE-SIZE, dbf)
{
  GDBM_FILE dbf = check_gdbm(&STACK_0,NULL,NULL,true);
  off_t ret;
  SYSCALL(ret = handle_length(NULL,gdbm_fdesc(dbf)));
  VALUES1(off_to_I(ret)); skipSTACK(1);
}
#endif  /* HAVE_GDBM_FDESC */

static object coerce_bitvector (object arg) {
  if (bit_vector_p(Atype_8Bit,arg)) return arg;
  else {
    pushSTACK(arg); pushSTACK(GLO(type_uint8_vector));
    funcall(L(coerce),2);
    if (!bit_vector_p(Atype_8Bit,value1)) { NOTREACHED; }
    return value1;
  }
}

nonreturning_function(static, error_bad_type, (object lisp_obj)) {
  pushSTACK(`GDBM::GDBM-ERROR`);
  pushSTACK(`:MESSAGE`);
  pushSTACK(`"invalid lisp object type: "`);
  pushSTACK(lisp_obj); funcall(L(prin1_to_string),1);
  pushSTACK(value1); value1 = string_concat(2); pushSTACK(value1);
  pushSTACK(S(Kcode)); pushSTACK(`:LISP-TYPE`);
  pushSTACK(`"~S: ~A"`);
  pushSTACK(TheSubr(subr_self)->name);
  pushSTACK(STACK_4); /* message */
  funcall(L(error_of_type), 8);
  NOTREACHED;
}

#define with_datum(lisp_obj, datum_var, statement)  do {                \
  datum datum_var;                                                      \
  if (stringp(lisp_obj)) {                                              \
    with_string_0(lisp_obj, GLO(misc_encoding), datum_var##string, {    \
      datum_var.dptr = datum_var##string;                               \
      datum_var.dsize = datum_var##string_len;                          \
      SYSCALL(statement);                                               \
    });                                                                 \
  } else if (bit_vector_p(Atype_32Bit,lisp_obj)) {                      \
    datum_var.dsize = 4 * vector_length(lisp_obj);                      \
    datum_var.dptr = (char*)TheSbvector(lisp_obj)->data;                \
    SYSCALL(statement);                                                 \
  } else if (vectorp(lisp_obj)) { /* assume Atype_8Bit */               \
    lisp_obj = coerce_bitvector(lisp_obj);                              \
    datum_var.dsize = vector_length(lisp_obj);                          \
    datum_var.dptr = (char*)TheSbvector(lisp_obj)->data;                \
    SYSCALL(statement);                                                 \
  } else if (integerp(lisp_obj)) {                                      \
    unsigned long datum_var##bitsize =                                  \
      1 + I_integer_length(lisp_obj); /* an extra bit for the sign */   \
    datum_var.dsize = ceiling(datum_var##bitsize,8);                    \
    datum_var.dptr = (char*)alloca(datum_var.dsize);                    \
    if (I_to_LEbytes(lisp_obj,8*datum_var.dsize,(uintB*)datum_var.dptr)) \
      NOTREACHED; /* there must not be an overflow! */                  \
    SYSCALL(statement);                                                 \
  } else if (single_float_p(lisp_obj)) {                                \
    ffloatjanus datum_var##ffloat;                                      \
    FF_to_c_float(lisp_obj, &datum_var##ffloat);                        \
    datum_var.dptr = (char*)&datum_var##ffloat;                         \
    datum_var.dsize = sizeof(ffloat);                                   \
    SYSCALL(statement);                                                 \
  } else if (double_float_p(lisp_obj)) {                                \
    dfloatjanus datum_var##dfloat;                                      \
    DF_to_c_double(lisp_obj, &datum_var##dfloat);                       \
    datum_var.dptr = (char*)&datum_var##dfloat;                         \
    datum_var.dsize = sizeof(dfloat);                                   \
    SYSCALL(statement);                                                 \
  } else error_bad_type(lisp_obj);                                      \
 } while(0)


DEFCHECKER(gdbm_store_flag, default=GDBM_REPLACE, prefix=GDBM, REPLACE INSERT)
#if defined(HAVE_GDBM_STORE)
DEFUN(GDBM:GDBM-STORE, dbf key content &key FLAG)
{
  GDBM_FILE dbf = check_gdbm(&STACK_3,NULL,NULL,true);
  int flag = gdbm_store_flag(STACK_0), status;
  with_datum(STACK_2, key,
             with_datum(STACK_1, content,
                        status = gdbm_store(dbf, key, content, flag)));
  if (status) error_gdbm(NULL); /* reader call */
  VALUES0; skipSTACK(4);        /* cleanup */
}
#endif  /* HAVE_GDBM_STORE */

/* convert datum to Lisp string and release memory in datum
 can trigger GC */
static object datum_to_object (datum d, gdbm_data_t data_type) {
  if (d.dptr == NULL) return NIL;
  switch (data_type) {
    case GDBM_DATA_STRING: {
      object o = n_char_to_string(d.dptr, d.dsize, GLO(misc_encoding));
      free(d.dptr);
      return o;
    }
    case GDBM_DATA_VECTOR: case GDBM_DATA_8BIT_VECTOR: {
      object o = allocate_bit_vector(Atype_8Bit,d.dsize);
      SYSCALL(memcpy(TheSbvector(o)->data,d.dptr,d.dsize));
      free(d.dptr);
      return o;
    }
    case GDBM_DATA_32BIT_VECTOR:
      if (d.dsize % 4) {
        pushSTACK(`GDBM::GDBM-ERROR`);
        pushSTACK(`:MESSAGE`);
        pushSTACK(`"32BIT-VECTOR conversion requires a datum length divisible by 4"`);
        pushSTACK(S(Kcode)); pushSTACK(`:DATUM-TYPE`);
        pushSTACK(`"~S: ~A"`);
        pushSTACK(TheSubr(subr_self)->name);
        pushSTACK(STACK_4); /* message */
        funcall(L(error_of_type), 8);
        NOTREACHED;
      } else {
        object o = allocate_bit_vector(Atype_32Bit,d.dsize/4);
        SYSCALL(memcpy(TheSbvector(o)->data,d.dptr,d.dsize));
        free(d.dptr);
        return o;
      }
    case GDBM_DATA_INTEGER: {
      object o = LEbytes_to_I(d.dsize,(uintB*)d.dptr);
      free(d.dptr);
      return o;
    }
    case GDBM_DATA_SINGLE_FLOAT: {
      object o = c_float_to_FF((ffloatjanus*)d.dptr);
      free(d.dptr);
      return o;
    }
    case GDBM_DATA_DOUBLE_FLOAT: {
      object o = c_double_to_DF((dfloatjanus*)d.dptr);
      free(d.dptr);
      return o;
    }
    case GDBM_DATA_NOTYPE:
      pushSTACK(`GDBM::GDBM-ERROR`);
      pushSTACK(`:MESSAGE`);
      pushSTACK(`"desired lisp type not specified"`);
      pushSTACK(S(Kcode)); pushSTACK(`:DATUM-TYPE`);
      pushSTACK(`"~S: ~A"`);
      pushSTACK(TheSubr(subr_self)->name);
      pushSTACK(STACK_4); /* message */
      funcall(L(error_of_type), 8);
      NOTREACHED;
    default: NOTREACHED;        /* pacify the compiler */
  }
}

#if defined(HAVE_GDBM_FETCH)
DEFUN(GDBM:GDBM-FETCH, dbf key &key :TYPE)
{
  gdbm_data_t data_type = check_data_type(popSTACK());
  GDBM_FILE dbf = check_gdbm(&STACK_1,NULL,&data_type,true);
  datum res;
  with_datum(STACK_0, key, res = gdbm_fetch(dbf,key));
  VALUES1(datum_to_object(res,data_type));
  skipSTACK(2);                 /* cleanup */
}
#endif  /* HAVE_GDBM_FETCH */

#if defined(HAVE_GDBM_DELETE)
DEFUN(GDBM:GDBM-DELETE, dbf key)
{
  GDBM_FILE dbf = check_gdbm(&STACK_1,NULL,NULL,true);
  int status;
  with_datum(STACK_0, key, status = gdbm_delete(dbf,key));
  if (status) error_gdbm(NULL); /* reader call */
  VALUES0; skipSTACK(2);        /* cleanup */
}
#endif  /* HAVE_GDBM_DELETE */

#if defined(HAVE_GDBM_FIRSTKEY)
DEFUN(GDBM:GDBM-FIRSTKEY, dbf &key :TYPE)
{
  gdbm_data_t data_type = check_data_type(popSTACK());
  GDBM_FILE dbf = check_gdbm(&STACK_0,&data_type,NULL,true);
  datum res;
  SYSCALL(res = gdbm_firstkey(dbf));
  VALUES1(datum_to_object(res,data_type)); skipSTACK(1);
}
#endif  /* HAVE_GDBM_FIRSTKEY */

#if defined(HAVE_GDBM_NEXTKEY)
DEFUN(GDBM:GDBM-NEXTKEY, dbf key &key :TYPE)
{
  gdbm_data_t data_type = check_data_type(STACK_0);
  GDBM_FILE dbf = check_gdbm(&STACK_2,&data_type,NULL,true);
  datum res;
  with_datum(STACK_1, key, res = gdbm_nextkey(dbf,key));
  VALUES1(datum_to_object(res,data_type));
  skipSTACK(3);                 /* cleanup */
}
#endif  /* HAVE_GDBM_NEXTKEY */

#define CHECK_RUN(statement)  do {              \
    int status;                                 \
    SYSCALL(status = statement);                \
    if (status) error_gdbm(NULL);               \
    else VALUES0;                               \
  } while(0)

#if defined(HAVE_GDBM_REORGANIZE)
DEFUN(GDBM:GDBM-REORGANIZE, dbf)
{
  GDBM_FILE dbf = check_gdbm(&STACK_0,NULL,NULL,true);
  CHECK_RUN(gdbm_reorganize(dbf)); skipSTACK(1);
}
#endif  /* HAVE_GDBM_REORGANIZE */

#if defined(HAVE_GDBM_SYNC)
DEFUN(GDBM:GDBM-SYNC, dbf)
{
  GDBM_FILE dbf = check_gdbm(&STACK_0,NULL,NULL,true);
  SYSCALL(gdbm_sync(dbf));
  VALUES0; skipSTACK(1);
}
#endif  /* HAVE_GDBM_SYNC */

#if defined(HAVE_GDBM_EXISTS)
DEFUN(GDBM:GDBM-EXISTS, dbf key)
{
  GDBM_FILE dbf = check_gdbm(&STACK_1,NULL,NULL,true);
  int status;
  with_datum(STACK_0, key, status = gdbm_exists(dbf, key));
  VALUES_IF(status);
  skipSTACK(2);                 /* cleanup */
}
#endif  /* HAVE_GDBM_EXISTS */

DEFCHECKER(gdbm_setopt_option, prefix=GDBM, CACHESIZE FASTMODE SYNCMODE \
           CENTFREE COALESCEBLKS DEFAULT-VALUE-TYPE DEFAULT-KEY-TYPE)
DEFUN(GDBM:GDBM-SETOPT, dbf option value)
{
  GDBM_FILE dbf = check_gdbm(&STACK_2,NULL,NULL,true);
  int option = gdbm_setopt_option(STACK_1);
  int v;
  switch (option) {
#  if defined(HAVE_GDBM_SETOPT)
    case GDBM_CACHESIZE:
      v = I_to_sint(check_sint(STACK_0));
      goto gdbm_setopt_common;
    case GDBM_FASTMODE: case GDBM_SYNCMODE:
    case GDBM_CENTFREE: case GDBM_COALESCEBLKS:
      v = nullp(STACK_0) ? 0 : 1; break;
    gdbm_setopt_common:
      CHECK_RUN(gdbm_setopt(dbf, option, &v, sizeof(int)));
      break;
#  endif  /* HAVE_GDBM_SETOPT */
    case GDBM_DEFAULT_VALUE_TYPE: v = GDBM_SLOT_VAL; goto gdbm_setopt_slot;
    case GDBM_DEFAULT_KEY_TYPE: v = GDBM_SLOT_KEY; gdbm_setopt_slot:
      TheStructure(STACK_2)->recdata[v] = fixnum(check_data_type(STACK_0));
      VALUES0;
      break;
    default: NOTREACHED;
  }
  skipSTACK(3);
}
