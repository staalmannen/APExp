/*
 * Copyright (C) 2007-2008 Yann Nicolas Dauphin
 * Copyright (C) 2007-2008 Sam Steingold
 * This file is a part of GNU CLISP and is distributed under GNU GPL v2+
 *
 * These are the set of macros built on top of GNU Lightning
 * to build the JIT compiler.
 * Simplicity and predictability is enforced.
 *
 * To understand GNU Lightning, have a quick look at the examples in:
 * http://www.gnu.org/software/lightning/manual/html_node/GNU-lightning-macros.html
 *
 * - The macros behave like functions; they may modify JIT_R0 and
 *   JIT_R1 only (exceptions are identified by the 'x' postfix)
 *
 * - Macros ending in 'i' take an immediate value as parameter, a macro
 *   ending with 'r' takes JIT_R2 as parameter.
 *   Macros that take an immediate value and register R2 as parameters
 *   end in 'ir', etc...
 *
 *   Macros ending in 'x' are SPECIAL macros. READ THEIR DOCUMENTATION
 *   before using or code next to them.
 *
 * - MACROS can return values in one of two ways:
 *   - It puts the value in one of it's parameters
 *   - It stores it in JIT_R0
 *
 * Map of the registers:
 * JIT_R0, JIT_R1, JIT_R2: free usage
 * JIT_V0:
 * JIT_V1: Pointer to the closure on the stack(closureptr)
 * JIT_V2:
 * Example of use:
 *
 * General comments:
 * If you plan to extend the JIT, you will probably run into
 *   a GNU lightning's weakness.
 * It has no integrated debugger.
 * But it is not a problem if you know and apply the following:
 *  - Always work in small chunks
 *  - Always use jitc_debug() to check the generated code
 *
 *  - If the code doesn't compile because of 'Cannot apply unary & etc', it's
 *    because you are passing an immediate value in place of a register
 *  - Most weird runtime errors are due to passing a immediate value in
 *    place of a register
 *
 * GOTCHAs
 * - jit_eq*: Always use JIT_R0 as destination value.
 *            Never use the same register in two operand slots.
 * TODO:
 * - Make a smarter algorithm to allocate space for the JITed function
 */

#include <lightning.h>

/* Pointer to a JIT-Compiled function */
/* Takes the closure and the distance to the starting bytecode as arguments */
typedef int (*jitc_func)(object, uintL);

/* This is for x86 (Quite imprecise for now) */
#define JITC_AVG_BCSIZE 130

/* ======= CLISP GC harness */
struct jitc_object {
  int jo_gc_mark;
  jit_insn *code_buffer;
  jit_insn **bc_index;
  struct jitc_object* jo_next;
};
/* all JITC objects as a linked list */
static struct jitc_object *all_jitc_objects = NULL;
bool gc_drop_jitc = false;
/* mark object as used */
void gc_mark_jitc_object (void *ptr) {
  struct jitc_object *jo = (struct jitc_object*)ptr;
  jo->jo_gc_mark = 1;
}
/* scan all JITC objects and release unused objects */
void gc_scan_jitc_objects (void) {
  struct jitc_object **next = &all_jitc_objects;
  while (*next) {
    if ((*next)->jo_gc_mark) {  /* keep */
      (*next)->jo_gc_mark = 0;  /* unmark for the next GC */
      next = &((*next)->jo_next);
    } else {                      /* release */
      struct jitc_object *jo_next = (*next)->jo_next;
      free((*next)->code_buffer);
      free((*next)->bc_index);
      free(*next);
      *next = jo_next;
    }
  }
}
/* ------------------- (*) JIT Internals ----------------------- */
/* Check overflow on codebuffer */
#define jitc_check_overflow()\
    if((jit_insn*)jit_get_ip().ptr > (codeBuffer + (sizeof(jit_insn)*byteptr_max*JITC_AVG_BCSIZE))){\
        fprintf(stderr,"\nFATAL ERROR: JIT codeBuffer overflow\n");\
        exit(-1);\
    }
/* jitc_patch_fwdjmps():
All values in bcIndex are initialized to 0(by calloc).
If the value bcIndex[bcPos] is different from 0, it means there are forward
jumps to this bytecode(see jitc_bcjmpi()).
Forward jumps are stored as a list. See jitc_bcjmpi(bc).
This implies that (bcPos == byteptr - CODEPTR).*/
struct jitc_insn_list {
  jit_insn* jump;
  struct jitc_insn_list* next;
};
#define jitc_patch_fwdjmps()   \
  if(bcIndex[bcPos]){          \
    struct jitc_insn_list *list = (struct jitc_insn_list*)bcIndex[bcPos];\
    while (list != NULL) {         \
      jit_insn *ref = list->jump;  \
      jit_patch(ref);              \
      struct jitc_insn_list *prev = list;  \
      list = list->next;                   \
      free(prev);                          \
    }                                      \
  }

/* jitc_bcjmpi(bc):
 Puts a jump to bytecode bc.
 If it's a back jump, just patch it.
 If it's a forward jump, put a list in the bcIndex[bc] with the address
 to be patched. */
#define jitc_bcjmpi(bc) do {       \
  jit_insn* rf1;                   \
  rf1 = jit_jmpi(jit_forward());   \
  if ((bc) < (byteptr - CODEPTR)) { /* BACK JMP */\
    jit_insn *rf2 = bcIndex[bc]; \
    jit_patch_at ((rf1), (rf2)); \
  } else if (bcIndex[bc] == 0) { /* FWD JMP: no list for this BC */\
    struct jitc_insn_list *list = malloc(sizeof(struct jitc_insn_list));\
    list->jump = rf1;  \
    list->next = NULL; \
    bcIndex[bc] = (jit_insn*)list;\
  } else{ /* FWD JMP: add to list */\
    struct jitc_insn_list *new_cell = malloc(sizeof(struct jitc_insn_list));\
    new_cell->jump = rf1;  \
    new_cell->next = (struct jitc_insn_list*)bcIndex[bc]; \
    bcIndex[bc] = (jit_insn*)new_cell;\
  }  \
} while(0)
/* Uses addresses in bcIndex to jmp */
#define jitc_bcjmpr();\
    jit_muli_ul(JIT_R1,JIT_R2,sizeof(jit_insn*));\
    jit_movi_p(JIT_R0,bcIndex);\
    jit_ldxr_p(JIT_R0,JIT_R0,JIT_R1);\
    jit_jmpr(JIT_R0);

#define jitc_return() jit_ret();

/* All bytecodes that modify the runtime context of a JIT function are tagged
with jitc_tag_unsafe. This eases the task of assigning a register to a permanent value*/
#define jitc_tag_unsafe()
/* ------------------- (0) Utilities ----------------------- */
/* this file is not processed by clisp/src/po/clisp-xgettext
   because all error messages that appear in this file already appear in
   src/eval.d, so we can use GETTEXT in this macro */
#define jitc_errori(type, message)               \
  jit_movi_l(JIT_R0, type);                     \
  jit_movi_p(JIT_R1, GETTEXT(message));         \
  jit_prepare(2);                               \
  jit_pusharg_p(JIT_R1);                        \
  jit_pusharg_p(JIT_R0);                        \
  jit_finish(error)
#define jitc_notreached()                        \
  jit_prepare(2);                               \
  jit_movi_l(JIT_R0,__LINE__);                  \
  jit_pusharg_p(JIT_R0);                        \
  jit_movi_p(JIT_R0,__FILE__);                  \
  jit_pusharg_p(JIT_R0);                        \
  jit_finish(error_notreached)

/* Gives access to slots in structures */
#define jitc_get_fieldr(type, field)\
    jit_ldxi_p(JIT_R0, JIT_R2, The##type(as_object(jit_ptr_field(type, field))));
#define jitc_getptr_fieldr(type, field)\
    jit_addi_p(JIT_R0, JIT_R2, The##type(as_object(jit_ptr_field(type, field))));

/* Length of a srecord */
#define jitc_getlenr(type)\
    jitc_get_fieldr(type,tfl);\
    jit_rshi_ul(JIT_R0,JIT_R0,16);

/* Gives access to a closure's constants */
#define jitc_get_cconsti(n)\
    jit_ldr_p(JIT_R0,JIT_V1);\
    jit_addi_p(JIT_R0, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_consts))));\
    jit_ldxi_p(JIT_R0,JIT_R0,(n)*sizeof(gcv_object_t));
#define jitc_getptr_cconsti(n)\
    jit_ldr_p(JIT_R0,JIT_V1);\
    jit_addi_p(JIT_R0, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_consts))));\
    jit_addi_p(JIT_R0,JIT_R0,(n)*sizeof(gcv_object_t));

/* jitc_repeat():
 > reg: counter
 > STATEMENT:
 Checks if (reg == 0) before looping */
#define jitc_repeat(reg, STATEMENT)              \
  {           jit_insn *rf166,*rf266;           \
    rf166 = jit_beqi_p(jit_forward(),reg,0);    \
    rf266 = jit_get_label();                    \
                                                \
    STATEMENT;                                  \
                                                \
    jit_subi_p(reg,reg,1);                      \
    jit_bnei_p(rf266,reg,0);                    \
    jit_patch(rf166);                           \
  }
/* jitc_repeatp():
 > reg: counter
 > STATEMENT:
 Does not check (if reg == 0) before looping */
#define jitc_repeatp(reg, STATEMENT)\
{           jit_insn *ref66;\
ref66 = jit_get_label();\
            \
            STATEMENT;\
            \
            jit_subi_p(reg,reg,1);\
jit_bnei_p(ref66,reg,0);\
    }
/* ------------------- (1) Stack operations ----------------------- */
#ifdef STANDARD_HEAPCODES
    /* jitc_getsize_framer(): */
    /* > &bottomword: Address of bottomword */
    #define jitc_getsize_framer()\
        jit_ldr_ui(JIT_R1,JIT_R2);\
        jit_andi_ui(JIT_R0,JIT_R1,(wbit(FB1)-1));
    #define jitc_get_framecoder()\
        jit_andi_ui(JIT_R0,JIT_R2,minus_wbit(FB1));
#endif
#ifdef LINUX_NOEXEC_HEAPCODES
    /* jitc_getsize_framer(): */
    /* > &bottomword: Address of bottomword */
    #define jitc_getsize_framer()\
        jit_ldr_ui(JIT_R1,JIT_R2);\
        jit_rshi_ul(JIT_R0,JIT_R1,6);
    #define jitc_get_framecoder()\
        jit_andi_ui(JIT_R0,JIT_R2,0x3F);
#endif
#ifdef STACK_DOWN
    #define jitc_bnov_stacki jit_blti_p
    #define jitc_getptbl_stackr()
  #define jitc_skip_stack_opir jit_addi_p
    #define jitc_skip_stack_opr jit_addr_p
    #define jitc_get_stacki(n)\
        jit_ldi_p(JIT_R1, &STACK);\
        jit_ldxi_i(JIT_R0, JIT_R1,(n)*sizeof(gcv_object_t));
    #define jitc_getptr_stacki(n)\
        jit_ldi_p(JIT_R1, &STACK);\
        jit_addi_i(JIT_R0, JIT_R1,(n)*sizeof(gcv_object_t));
    #define jitc_get_framei(n)\
        jit_ldxi_p(JIT_R0,JIT_R2,(n)*sizeof(gcv_object_t));
    #define jitc_getptr_framei(n)\
        jit_addi_p(JIT_R0,JIT_R2,(n)*sizeof(gcv_object_t));
    /* jitc_gettop_framer(): */
    /* > &bottomword: Address of bottomword */
    #define jitc_gettop_framer()\
        jitc_getsize_framer();\
        jit_addr_ui(JIT_R1,JIT_R2,JIT_R0);\
        jit_movr_p(JIT_R0,JIT_R1);
    /* reg is modified */
    #define jitc_frame_nextx(reg)\
        jit_subi_p(reg,reg,sizeof(gcv_object_t));\
        jit_ldr_p(JIT_R0,reg);
    #define jitc_get_scountr(res,new,old)\
        jit_subr_p(res,old,new);\
        jit_divi_ul(res,res,sizeof(void*));
#endif
#ifdef STACK_UP
    #define jitc_bnov_stacki jit_bgti_p
    #define jitc_getptbl_stackr()  jit_subi_i(JIT_R0,JIT_R2,sizeof(gcv_object_t))
  #define jitc_skip_stack_opir jit_subi_p
    #define jitc_skip_stack_opr jit_subr_p
    #define jitc_get_stacki(n)\
        jit_ldi_p(JIT_R1, &STACK);\
        jit_ldxi_i(JIT_R0, JIT_R1,-sizeof(gcv_object_t) - ((n)*sizeof(gcv_object_t)));
    #define jitc_get_stackr()\
        jit_ldi_p(JIT_R1, &STACK);\
        jit_subi_p(JIT_R1,JIT_R1,sizeof(gcv_object_t));\
        jit_muli_ul(JIT_R0,JIT_R2,sizeof(gcv_object_t));\
        jit_subr_p(JIT_R1,JIT_R1,JIT_R0);\
        jit_ldr_p(JIT_R0, JIT_R1);
    #define jitc_getptr_stacki(n)\
        jit_ldi_p(JIT_R1, &STACK);\
        jit_addi_i(JIT_R0, JIT_R1,-sizeof(gcv_object_t) - ((n)*sizeof(gcv_object_t)));
    #define jitc_get_framei(n)\
        jit_ldxi_i(JIT_R0, JIT_R2,-sizeof(gcv_object_t) - ((n)*sizeof(gcv_object_t)));
    #define jitc_getptr_framei(n)\
        jit_addi_i(JIT_R0, JIT_R2,-sizeof(gcv_object_t) - ((n)*sizeof(gcv_object_t)));
    /* jitc_gettop_framer(): */
    /* > &bottomword: Address of bottomword */
    #define jitc_gettop_framer()\
        jitc_getsize_framer();\
        jit_subr_ui(JIT_R1,JIT_R2,JIT_R0);\
        jit_addi_ui(JIT_R0,JIT_R1,sizeof(gcv_object_t));
    /* reg is modified */
    #define jitc_frame_nextx(reg)\
        jit_ldr_p(JIT_R0,reg);\
        jit_addi_p(reg,reg,sizeof(gcv_object_t));
    #define jitc_get_scountr(res,new,old)\
        jit_subr_p(res,new,old);\
        jit_divi_ul(res,res,sizeof(void*));
#endif


#define jitc_skip_stacki(n)\
    jit_ldi_p(JIT_R0, &STACK);\
    jitc_skip_stack_opir(JIT_R0, JIT_R0,(n)*sizeof(gcv_object_t));\
    jit_sti_p(&STACK, JIT_R0);
#define jitc_skip_stackr()\
    jit_ldi_p(JIT_R0, &STACK);\
    jit_muli_i(JIT_R1,JIT_R2,sizeof(void*));\
    jitc_skip_stack_opr(JIT_R0, JIT_R0,JIT_R1);\
    jit_sti_p(&STACK, JIT_R0);

#define jitc_push_stacki(obj)\
    jitc_getptr_stacki(-1);\
    jit_movi_l(JIT_R1, obj);\
    jit_str_p(JIT_R0, JIT_R1);\
    jitc_skip_stacki(-1);
#define jitc_push_stackr()\
    jitc_getptr_stacki(-1);\
    jit_str_p(JIT_R0, JIT_R2);\
    jitc_skip_stacki(-1);
/* Loads the argument before pushing */
#define jitc_ldpush_stackr()\
    jitc_getptr_stacki(-1);\
    jit_ldr_p(JIT_R1,JIT_R2);\
    jit_str_p(JIT_R0, JIT_R1);\
    jitc_skip_stacki(-1);

#define jitc_pop_stack()\
    jitc_skip_stacki(1);\
    jitc_get_stacki(-1);

/*  Make the 'Frame Info' word of a frame on the lisp stack */
#define jitc_finish_framer(TYPE, SIZE)\
    jitc_getptr_stacki(-1);\
    jit_movi_l(JIT_R1,as_oint(makebottomword(TYPE##_frame_info,SIZE*sizeof(gcv_object_t))));\
    jit_str_p(JIT_R0, JIT_R1);\
    jitc_skip_stacki(-1);

/* Check if the stack has overflowed */
#define jitc_check_stack()\
    { jit_insn* ref;\
        jit_ldi_p(JIT_R0,&(STACK));\
        jit_ldi_p(JIT_R1,&(STACK_bound));\
    ref = jitc_bnov_stacki(jit_forward(), JIT_R0,JIT_R1);\
        (void)jit_calli(STACK_ueber);\
    jit_patch(ref);\
    }
/* jitc_check_stack i-r():
 Check if the stack will overflow given the parameter
 Equivalent to macro get_space_on_STACK */
#define jitc_check_stackr()\
    { jit_insn* ref;\
        jit_ldi_p(JIT_R0,&(STACK));\
        jit_ldi_p(JIT_R1,&(STACK_bound));\
        jit_addr_p(JIT_R1,JIT_R1,JIT_R2);\
    ref = jitc_bnov_stacki(jit_forward(), JIT_R0,JIT_R1);\
        (void)jit_calli(STACK_ueber);\
    jit_patch(ref);\
    }
#define jitc_check_stacki(n)\
    { jit_insn* ref;\
        jit_ldi_p(JIT_R0,&(STACK));\
        jit_ldi_p(JIT_R1,&(STACK_bound));\
        jit_addi_p(JIT_R1,JIT_R1,(n));\
    ref = jitc_bnov_stacki(jit_forward(), JIT_R0,JIT_R1);\
        (void)jit_calli(STACK_ueber);\
    jit_patch(ref);\
    }
/* ------------------- (2) Multiple Values ----------------------- */
/* jitc_rawset_valuesi_1: */
/* Doesn't modify mvcount */
#define jitc_rawset_valuesi_1(value)\
    jit_movi_l(JIT_R0, value);\
    jit_sti_p (mv_space,JIT_R0);

#define jitc_set_valuesi_1(value)\
    jit_movi_l(JIT_R0, value);\
    jit_sti_p(mv_space,JIT_R0);\
    jit_movi_ui(JIT_R0, 1);\
    jit_sti_ui(&mv_count, JIT_R0);
#define jitc_set_valuesr_1()\
    jit_sti_p (mv_space,JIT_R2);\
    jit_movi_ui(JIT_R0, 1);\
    jit_sti_ui(&mv_count, JIT_R0);
#define  jit_set_valuesi(N,value) \
    jit_movi_ui(JIT_R0,N);\
    stxi_p(mv_space,N,value); \
    jit_movi_ui(JIT_R0, N);\
    jit_sti_ui(&mv_count, JIT_R0);

#define jitc_get_valuesr_1()\
    jit_ldi_p(JIT_R0, mv_space);
#define jitc_getptr_valuesr_1()\
    jit_movi_l(JIT_R0, mv_space);

#define jitc_getptr_valuesi(n)\
    jit_movi_l(JIT_R0, mv_space);\
    jit_addi_p(JIT_R0,JIT_R0,(n)*sizeof(gcv_object_t));
#define jitc_getptr_valuesr()\
    jit_movi_l(JIT_R0, mv_space);\
    jit_muli_ul(JIT_R1,JIT_R2,sizeof(gcv_object_t));\
    jit_addr_p(JIT_R0,JIT_R0,JIT_R1);

#define jitc_get_mvcountr()\
    jit_ldi_p(JIT_R0, &mv_count);
#define jitc_set_mvcounti(n)\
    jit_movi_ui(JIT_R0,n);\
    jit_sti_p(&mv_count,JIT_R0);
#define jitc_set_mvcountr()\
    jit_sti_p(&mv_count,JIT_R2);
/* Modifies All registers except JIT_V0 */
#define jitc_mv2stackx()\
    {       jit_insn *rf1,*rf2;\
            jitc_get_mvcountr();\
rf1 = jit_beqi_p(jit_forward(),JIT_R0,0);\
\
            jit_movr_p(JIT_V2,JIT_R0);\
            jit_movr_p(JIT_R2,JIT_R0);\
            jitc_check_stackr();\
            jitc_getptr_valuesi(0);\
            jit_movr_p(JIT_V1,JIT_R0);\
jitc_repeatp(JIT_V2,\
            jit_ldr_p(JIT_R2,JIT_V1);\
            jitc_push_stackr();\
            jit_addi_p(JIT_V1,JIT_V1,sizeof(gcv_object_t));\
);\
\
jit_patch(rf1);\
    }
/* ------------------- (3) SP operations ----------------------- */
/* Operations on a down-growing stack */
#define jitc_set_spr()\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R2);
#define jitc_get_spi(n)\
    jit_ldxi_p(JIT_R1,JIT_FP,jitc_sp_ptr);\
    jit_ldxi_p(JIT_R0, JIT_R1, (n)*sizeof(SPint));
#define jitc_getptr_spi(n)\
    jit_ldxi_p(JIT_R1,JIT_FP,jitc_sp_ptr);\
    jit_addi_p(JIT_R0, JIT_R1, (n)*sizeof(SPint));

#define jitc_skip_spi(n)\
    jit_ldxi_p(JIT_R1,JIT_FP,jitc_sp_ptr);\
    jit_addi_p(JIT_R0,JIT_R1,(n)*sizeof(SPint));\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);

#define jitc_push_spi(item)\
    jitc_getptr_spi(-1);\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);\
    jit_movi_l(JIT_R1, (item));\
    jit_str_p(JIT_R0,JIT_R1);
#define jitc_push_spr()\
    jitc_getptr_spi(-1);\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);\
    jit_str_p(JIT_R0,JIT_R2);
/* Loads the parameter before pushing */
#define jitc_ldpush_spr()\
    jitc_getptr_spi(-1);\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);\
    jit_ldr_p(JIT_R1,JIT_R2);\
    jit_str_p(JIT_R0,JIT_R1);

#define jitc_pop_sp()\
    jitc_getptr_spi(0);\
    jit_addi_p(JIT_R1,JIT_R0,sizeof(SPint));\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R1);\
    jit_ldr_p(JIT_R0, JIT_R0);
#define jitc_alloc_jmpbuf()\
    jit_ldxi_p(JIT_R0,JIT_FP,jitc_sp_ptr);\
    jit_subi_i(JIT_R0,JIT_R0,(jmpbufsize)*sizeof(SPint));\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);
#define jitc_free_jmpbuf()\
    jit_ldxi_p(JIT_R0,JIT_FP,jitc_sp_ptr);\
    jit_addi_i(JIT_R0,JIT_R0,(jmpbufsize)*sizeof(SPint));\
    jit_stxi_p(jitc_sp_ptr,JIT_FP, JIT_R0);
#define jitc_finish_eframex(TYPE, SIZE, ON_REENTRY, ON_FINISH)\
{\
        jit_insn *rf1;\
        jitc_push_stackr();\
        jitc_push_stacki(as_oint(nullobj));\
        \
        jit_prepare(1);\
        jit_pusharg_p(JIT_R2);\
        jit_finish(setjmp);\
        jit_retval(JIT_R2);\
        \
rf1 = jit_beqi_p(jit_forward(),JIT_R2,0);\
        jitc_set_spr();\
        \
        ON_REENTRY;\
        \
jit_patch(rf1);\
        jitc_getptr_stacki(0);\
        jit_movi_l(JIT_R1,as_oint(makebottomword(TYPE##_frame_info,SIZE*sizeof(gcv_object_t))));\
        jit_str_p(JIT_R0,JIT_R1);\
        \
        ON_FINISH;\
}


/* ------------------- (4) Symbols ----------------------- */
#define jitc_get_symvali(symbol)\
    jit_movi_l(JIT_R1,symbol);\
    jit_ldxi_p(JIT_R0,JIT_R1, TheSymbol(as_object(jit_ptr_field(Symbol, symvalue))));
#define jitc_get_symvalr()\
    jit_ldxi_p(JIT_R0,JIT_R2, TheSymbol(as_object(jit_ptr_field(Symbol, symvalue))));
#define jitc_getptr_symvali(symbol)\
    jit_movi_l(JIT_R1,symbol);\
    jit_addi_p(JIT_R0,JIT_R1, TheSymbol(as_object(jit_ptr_field(Symbol, symvalue))));
#define jitc_getptr_symvalr()\
    jit_addi_p(JIT_R0,JIT_R2, TheSymbol(as_object(jit_ptr_field(Symbol, symvalue))));
#define jitc_sym_constpr(sym)\
    jit_ldxi_p(JIT_R0, JIT_R2, TheSymbol(as_object(jit_ptr_field(Symbol, header_flags))));\
    jit_notr_ul(JIT_R0,JIT_R0);\
    jit_andi_ul(JIT_R1,JIT_R0,bit(var_bit0_hf)|bit(var_bit1_hf));\
    jit_eqi_ul(JIT_R0,JIT_R1,0);

#define jitc_sympr()\
  { jit_insn* ref;                                                      \
    jit_andi_ul(JIT_R1, JIT_R2,nonimmediate_heapcode_mask);             \
    jit_movi_l(JIT_R0,0);                                               \
    ref = jit_bnei_p(jit_forward(),JIT_R1,(varobject_bias+varobjects_misaligned)); \
    jit_ldxi_p(JIT_R1,JIT_R2, TheRecord(as_object(jit_ptr_field(Record, tfl))));   \
    jit_andi_ul(JIT_R1, JIT_R1,0xFF);                                   \
    jit_eqi_p(JIT_R0,JIT_R1,Rectype_Symbol);                            \
    jit_patch(ref);}

/* Modifies JIT_R2 */
#define jitc_check_fdefx() {                                             \
    jit_insn *rf1,*rf2;                                                 \
    jitc_sympr();                                                        \
    rf1 = jit_beqi_p(jit_forward(),JIT_R0,1);                           \
    jitc_save_backtrace3(as_oint(L(symbol_function)), STACK, -1, -1,{    \
        jit_prepare(1);                                                 \
        jit_pusharg_p(JIT_R2);                                          \
        jit_finish(check_symbol);                                       \
        jit_retval(JIT_R2);                                             \
      });                                                               \
    jit_patch(rf1);                                                     \
    jitc_get_fieldr(Symbol,symfunction);                                 \
    rf2 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(unbound));            \
    jit_prepare(2);                                                     \
    jit_movi_l(JIT_R0,as_oint(S(symbol_function)));                     \
    jit_pusharg_p(JIT_R0);                                              \
    jit_pusharg_p(JIT_R2);                                              \
    jit_finish(check_fdefinition);                                      \
    jit_retval(JIT_R0);                                                 \
    jit_patch(rf2);                                                     \
  }

#define jitc_sym_atompr()\
    jit_andi_ul(JIT_R1,JIT_R2,7);\
    jit_nei_p(JIT_R0,JIT_R1,(cons_bias+conses_misaligned));
#define jitc_sym_conspr()\
    jit_andi_ul(JIT_R1,JIT_R2,7);\
    jit_eqi_p(JIT_R0,JIT_R1,(cons_bias+conses_misaligned));
/* ------------------- (5) Svectors ----------------------- */
#define jitc_svecpr()\
        { jit_insn* ref;\
    jit_andi_ul(JIT_R1, JIT_R2,nonimmediate_heapcode_mask);\
                jit_movi_l(JIT_R0,0);\
ref = jit_bnei_p(jit_forward(),JIT_R1,(varobject_bias+varobjects_misaligned));\
    jit_ldxi_p(JIT_R1,JIT_R2, TheRecord(as_object(jit_ptr_field(Record, tfl))));\
    jit_andi_ul(JIT_R1, JIT_R1,0xFF);\
    jit_eqi_p(JIT_R0,JIT_R1,Rectype_Svector);\
jit_patch(ref);}
#define jitc_getlen_svecr()\
    jitc_get_fieldr(Svector,tfl);\
    jit_rshi_i(JIT_R0,JIT_R0,8);
#define jitc_get_svecdatair(n)\
    jit_addi_p(JIT_R1, JIT_R2, TheSvector(as_object(jit_ptr_field(Svector, data))));\
    jit_ldxi_p(JIT_R0, JIT_R1, (n)*sizeof(gcv_object_t));
#define jitc_getptr_svecdatair(n)\
    jit_addi_p(JIT_R1, JIT_R2, TheSvector(as_object(jit_ptr_field(Svector, data))));\
    jit_addi_p(JIT_R0, JIT_R1, (n)*sizeof(gcv_object_t));
/* jitc_get_svecdatax():
 > JIT_R2: Address of svec
   JIT_R1: Element position
 Modifies JIT_R1 */
#define jitc_get_svecdatax()\
    jit_addi_p(JIT_R0, JIT_R2, TheSvector(as_object(jit_ptr_field(Svector, data))));\
    jit_muli_ul(JIT_R1,JIT_R1,sizeof(gcv_object_t));\
    jit_ldxr_p(JIT_R0, JIT_R0, JIT_R1);
#define jitc_getptr_svecdatax()\
    jit_addi_p(JIT_R0, JIT_R2, TheSvector(as_object(jit_ptr_field(Svector, data))));\
    jit_muli_ul(JIT_R1,JIT_R1,sizeof(gcv_object_t));\
    jit_addr_p(JIT_R0, JIT_R0, JIT_R1);
/* ------------------- (6) Calls ----------------------- */
#define jitc_funcall()\
  { jit_prepare(2);\
        jit_movi_l(JIT_R0,k);\
        jit_pusharg_p(JIT_R0);\
        jitc_get_cconsti(n);\
        jit_pusharg_p(JIT_R0);\
        jit_finish(funcall);\
  }
#define jitc_funcall0()\
  { jit_prepare(2);\
        jit_movi_l(JIT_R0,0);\
        jit_pusharg_p(JIT_R0);\
        jitc_get_cconsti(n);\
        jit_pusharg_p(JIT_R0);\
        jit_finish(funcall);\
  }
#define jitc_funcall1()\
  { jit_prepare(2);\
        jit_movi_l(JIT_R0,1);\
        jit_pusharg_p(JIT_R0);\
        jit_ldr_p(JIT_R0,JIT_V1);\
        jitc_get_cconsti(n);\
        jit_pusharg_p(JIT_R0);\
        jit_finish(funcall);\
  }
#define jitc_funcall2()\
  { jit_prepare(2);\
        jit_movi_l(JIT_R0,2);\
        jit_pusharg_p(JIT_R0);\
        jitc_get_cconsti(n);\
        jit_pusharg_p(JIT_R0);\
        jit_finish(funcall);\
  }
/* !!! DO NOT NEST jit_save_backtrace*s */
/* jitc_save_backtrace1(fun,stack,num_arg,statement): */
/* This one does not dynamically load the 'fun' argument */
#define jitc_save_backtrace1(fun,stack,num_arg,statement) {      \
    jit_addi_p(JIT_R0,JIT_FP,bt_here);                          \
    jit_ldi_p(JIT_R1,&back_trace);                                      \
    jit_stxi_i (jit_field(struct backtrace_t, bt_next), JIT_R0, JIT_R1); \
    jit_movi_l(JIT_R1,(fun));                                           \
    jit_stxi_i (jit_field(struct backtrace_t, bt_function), JIT_R0, JIT_R1); \
    jit_ldi_p(JIT_R1,&(stack));                                         \
    jit_stxi_i (jit_field(struct backtrace_t, bt_stack), JIT_R0, JIT_R1); \
    jit_movi_l(JIT_R1,(num_arg));                                       \
    jit_stxi_i (jit_field(struct backtrace_t, bt_num_arg), JIT_R0, JIT_R1); \
    jit_sti_p(&back_trace, JIT_R0);                                     \
    statement;                                                          \
    jit_ldi_p(JIT_R0,&back_trace);                                      \
    jit_ldxi_p(JIT_R1, JIT_R0, jit_field(struct backtrace_t, bt_next)); \
    jit_sti_p(&back_trace, JIT_R1);                                     \
  }
/* jitc_save_backtrace2(fun,stack,num_arg,statement):
 This one dynamically loads the 'fun' argument */
#define jitc_save_backtrace2(fun,stack,num_arg,statement) {   \
    jit_addi_p(JIT_R0,JIT_FP,bt_here);                       \
    jit_ldi_p(JIT_R1,&back_trace);                                      \
    jit_stxi_i (jit_field(struct backtrace_t, bt_next), JIT_R0, JIT_R1); \
    jit_ldi_p(JIT_R1,&(fun));                                           \
    jit_stxi_i (jit_field(struct backtrace_t, bt_function), JIT_R0, JIT_R1); \
    jit_ldi_p(JIT_R1,&(stack));                                         \
    jit_stxi_i (jit_field(struct backtrace_t, bt_stack), JIT_R0, JIT_R1); \
    jit_movi_l(JIT_R1,(num_arg));                                       \
    jit_stxi_i (jit_field(struct backtrace_t, bt_num_arg), JIT_R0, JIT_R1); \
    jit_sti_p(&back_trace, JIT_R0);                                     \
    statement;                                                          \
    jit_ldi_p(JIT_R0,&back_trace);                                      \
    jit_ldxi_p(JIT_R1, JIT_R0, jit_field(struct backtrace_t, bt_next)); \
    jit_sti_p(&back_trace, JIT_R1);                                     \
  }
/* jitc_save_backtrace3():
 Saves 'STACK STACKop n' instead of just STACK */
#define jitc_save_backtrace3(fun,stack,n,num_arg,statement) {    \
    jit_addi_p(JIT_R0,JIT_FP,bt_here);                          \
    jit_ldi_p(JIT_R1,&back_trace);                                      \
    jit_stxi_i (jit_field(struct backtrace_t, bt_next), JIT_R0, JIT_R1); \
    jit_movi_l(JIT_R1,(fun));                                           \
    jit_stxi_i (jit_field(struct backtrace_t, bt_function), JIT_R0, JIT_R1); \
    jit_ldi_p(JIT_R1,&(stack));                                         \
    jitc_skip_stack_opir(JIT_R1,JIT_R1,(n)*sizeof(gcv_object_t));        \
    jit_stxi_i (jit_field(struct backtrace_t, bt_stack), JIT_R0, JIT_R1); \
    jit_movi_l(JIT_R1,(num_arg));                                       \
    jit_stxi_i (jit_field(struct backtrace_t, bt_num_arg), JIT_R0, JIT_R1); \
    jit_sti_p(&back_trace, JIT_R0);                                     \
    statement;                                                          \
    jit_ldi_p(JIT_R0,&back_trace);                                      \
    jit_ldxi_p(JIT_R1, JIT_R0, jit_field(struct backtrace_t, bt_next)); \
    jit_sti_p(&back_trace, JIT_R1);                                     \
  }
#define jitc_funcalls1();                        \
  {{ Subr fun = FUNTAB1[n];                                        \
     jitc_save_backtrace1(as_oint(subr_tab_ptr_as_object(fun)),STACK,-1,\
                         jit_movi_p(JIT_R0,(fun->function));            \
                         jit_callr(JIT_R0););                           \
    }}
#define jitc_funcalls2();                        \
  {{ Subr fun = FUNTAB2[n];                                        \
     jitc_save_backtrace1(as_oint(subr_tab_ptr_as_object(fun)),STACK,-1,\
                         jit_movi_p(JIT_R0,(fun->function));      \
                         jit_callr(JIT_R0););                     \
    }}
#define jitc_funcallsr();                        \
  {{ Subr fun = FUNTABR[n];                                        \
     jitc_save_backtrace1(as_oint(subr_tab_ptr_as_object(fun)),STACK,-1,{\
         jit_prepare(2);                                                \
         jit_ldi_p(JIT_R1,&(args_end_pointer));                         \
         jitc_skip_stack_opir(JIT_R0,JIT_R1,m*sizeof(gcv_object_t));    \
         jit_pusharg_p(JIT_R0);                                         \
         jit_movi_l(JIT_R0,m);                                          \
         jit_pusharg_p(JIT_R0);                                         \
         jit_movi_p(JIT_R0,(fun->function));                            \
         jit_finishr(JIT_R0);                                           \
       });}}
#define jitc_funcallc()                          \
  jitc_check_stack();                            \
  jitc_save_backtrace2(value1, STACK,-1,         \
                      jit_prepare(3);           \
                      jitc_get_valuesr_1();                              \
                      jit_ldxi_p(JIT_R0, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_codevec)))); \
                      jit_addi_p(JIT_R0, JIT_R0, TheSbvector(as_object(jit_ptr_field(Sbvector, data)))); \
                      jit_addi_p(JIT_R0, JIT_R0, CCV_START_NONKEY*sizeof(uint8)); \
                      jit_pusharg_p(JIT_R0);                            \
                      jitc_get_valuesr_1();                              \
                      jit_ldxi_p(JIT_R1, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_codevec)))); \
                      jit_addi_p(JIT_R1,JIT_R1,TheSbvector(as_object(0)));         \
                      jit_pusharg_p(JIT_R1);                            \
                      jit_pusharg_p(JIT_R0);                            \
                      jit_finish(cclosure_run););
#define jitc_funcallckey()                       \
  jitc_check_stack();                            \
  jitc_save_backtrace2(value1, STACK,-1,         \
                      jit_prepare(3);           \
                      jitc_get_valuesr_1();                              \
                      jit_ldxi_p(JIT_R0, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_codevec)))); \
                      jit_addi_p(JIT_R0, JIT_R0, TheSbvector(as_object(jit_ptr_field(Sbvector, data)))); \
                      jit_addi_p(JIT_R0, JIT_R0, CCV_START_KEY*sizeof(uint8)); \
                      jit_pusharg_p(JIT_R0);                            \
                      jitc_get_valuesr_1();                              \
                      jit_ldxi_p(JIT_R1, JIT_R0, TheCclosure(as_object(jit_ptr_field(Cclosure, clos_codevec)))); \
                      jit_addi_p(JIT_R1,JIT_R1,TheSbvector(as_object(0)));         \
                      jit_pusharg_p(JIT_R1);                            \
                      jit_pusharg_p(JIT_R0);                            \
                      jit_finish(cclosure_run););
/* ------------------- (6) Fixnum ----------------------- */
#define jitc_val2fixnumr()                       \
  jit_lshi_ul(JIT_R0,JIT_R2,oint_data_shift);   \
  jit_movi_l(JIT_R1,fixnum_type);               \
  jit_lshi_ul(JIT_R1,JIT_R1,oint_type_shift);   \
  jit_addr_p(JIT_R0,JIT_R0,JIT_R1);
#define jitc_posfixnum2valr()\
  jit_andi_ui(JIT_R0,JIT_R2,((oint)wbitm(oint_data_len+oint_data_shift)-1)); \
  jit_rshi_ul(JIT_R0,JIT_R0,oint_data_shift);
#define jitc_posfixnumpr()                       \
  jit_movi_l(JIT_R0,7);                         \
  jit_lshi_ul(JIT_R0,JIT_R0,imm_type_shift);    \
  jit_ori_ul(JIT_R0,JIT_R0,immediate_bias);     \
  jit_andr_ul(JIT_R1,JIT_R0,JIT_R2);            \
  jit_eqi_p(JIT_R0,JIT_R1,fixnum_type);

#define jitc_inc_posfixnumir(n)                  \
  jit_movi_l(JIT_R0,n);                         \
  jit_lshi_ul(JIT_R0,JIT_R0,oint_data_shift);   \
  jit_addr_p(JIT_R0,JIT_R0,JIT_R2);

/* Might need to reassign this to a function hence the 'x' */
#define jitc_ul2ix() jitc_val2fixnumr()

#if (oint_data_len>=intVsize)
    #define jitc_fixnum2valr()  jitc_posfixnum2valr();
#elif (sign_bit_o == oint_data_len+oint_data_shift)
  #define jitc_fixnum2valr()\
        jit_lshi_ul(JIT_R0,JIT_R2,(intVsize-1-sign_bit_o));\
        jit_rshi_ul(JIT_R0,JIT_R0,(intVsize-1-sign_bit_o+oint_data_shift));
#else
  #define jitc_fixnum2valr()\
        jit_rshi_l(JIT_R1,JIT_R2,sign_bit_o);\
        jit_lshi_l(JIT_R1,JIT_R1,(intVsize-1));\
        jit_rshi_l(JIT_R1,JIT_R1,(intVsize-1-oint_data_len));\
        jit_andi_ul(JIT_R0,JIT_R2,((oint)wbitm(oint_data_len+oint_data_shift)-1));\
        jit_rshi_ul(JIT_R0,JIT_R0,oint_data_shift);\
        jit_orr_ul(JIT_R0,JIT_R0,JIT_R1);
#endif


/* ------------------- (X) Debugging ----------------------- */
#define jitc_debug()\
    disassemble(stderr, codeBuffer, jit_get_ip().ptr);
/* Prints to STDOUT */
/* Carefull, since a C function is called, JIT_R* might get modified */
#define jitc_printm(mes)\
    jit_movi_l(JIT_R0, mes);\
    jit_prepare(3);\
    jit_pusharg_p(JIT_R2);\
    jit_pusharg_p(JIT_R2);\
    jit_pusharg_p(JIT_R0);\
    jit_finish(printf);
#define jitc_printr()\
    jit_movi_i(JIT_R0, "The register equals: I=%d, P=%p\n");\
    jit_prepare(3);\
    jit_pusharg_p(JIT_R2);\
    jit_pusharg_p(JIT_R2);\
    jit_pusharg_p(JIT_R0);\
    jit_finish(printf);
#define jitc_printi(val)\
    jit_movi_p(JIT_R0, "The variable equals: I=%d, P=%p\n");\
    jit_movi_l(JIT_R1, val);\
    jit_prepare(3);\
    jit_pusharg_p(JIT_R1);\
    jit_pusharg_p(JIT_R1);\
    jit_pusharg_p(JIT_R0);\
    jit_finish(printf);

/* ---------------------- JIT BYTECODE COMPILER ---------------------- */

/* Compiles the bytecode of a compiled Closure to machine code. See jit.h
   jit_compile_(closure,codeptr,byteptr);
   > closure: compiled closure
   > codeptr: its Codevector, a Simple-Bit-Vector, pointable
   > byteptr: Start-Bytecodepointer
   < mv_count/mv_space: values
   changes STACK, cannot trigger GC */
/* Syntax of local labels in GNU-C assembler-statements: */
#if (defined(GNU) || defined(INTEL)) && !defined(NO_ASM)
/* LD(x) defines Label with number x */
/* LR(x,f) references label with number x forwards */
/* LR(x,b) references label with number x backwards */
/* The scope of the labels is only one assembler-statement. */
  #if defined(I80386)
    #ifdef ASM_UNDERSCORE
      #define LD(nr)  "LASM%=X" STRING(nr)
      #define LR(nr,fb)  "LASM%=X" STRING(nr)
    #else
      #define LD(nr)  ".LASM%=X" STRING(nr)
      #define LR(nr,fb)  ".LASM%=X" STRING(nr)
    #endif
  #elif defined(ARM)
    #define LD(nr)  "LASM%=X" STRING(nr)
    #define LR(nr,fb)  "LASM%=X" STRING(nr)
  #else
    #define LD(nr)  STRING(nr)
    #define LR(nr,fb)  STRING(nr) STRING(fb)
  #endif
#endif
/* Persuade GNU-C, to keep closure and byteptr in registers: */
#if 1
  #ifdef MC680X0
    #define closure_register  "a2"
    #define byteptr_register  "a3"
  #endif
  #ifdef SPARC
    #define closure_register  "%l0"
    #define byteptr_register  "%l1"
  #endif
  #ifdef I80386
    #if (__GNUC__ >= 2) /* The register-names have changed */
      #define byteptr_register  "%edi"
    #else
      #define byteptr_register  "di"
    #endif
  #endif
  #ifdef ARM
    /* Code is better without defining registers for closure and byteptr,
     says Peter Burwood.
     not define closure_register  "%r6"
     not define byteptr_register  "%r7"
     We have assembler macros below, but if they are used with gcc-2.7.2.1,
     (setf cdddr) is miscompiled. So here we temporarily disable them. */
    #ifndef NO_ASM
      #define NO_ASM
    #endif
  #endif
  #ifdef DECALPHA
    #define byteptr_register  "$14"
  #endif
  #if defined(WIDE) && !defined(WIDE_HARD)
    /* An object does not fit into a single register, GCC is overcharged. */
    #undef closure_register
  #endif
#endif
#ifndef closure_register
  #define closure_in  closure
#endif
#ifndef byteptr_register
  #define byteptr_in  byteptr
#endif
#ifdef DEBUG_BYTECODE
  #define GOTO_ERROR(label)  \
    do {                                              \
      fprintf(stderr,"\n[%s:%d] ",__FILE__,__LINE__); \
      goto label;                                     \
    } while(0)
#else
  #define GOTO_ERROR(label)  goto label
#endif
/* Operand-Fetch:
   next Byte:
     Bit 7 = 0 --> Bits 6..0 are the Operand (7 Bits).
     Bit 7 = 1 --> Bits 6..0 and next Byte form the
                   Operand (15 Bits).
                   For jump-distances: Should this be =0, the next
                   4 Bytes form the Operand
                   (32 Bits). */

/* Macro B_operand(where);
 moves the next Operand (a Byte as Unsigned Integer)
 to (uintL)where and advances  bytecodepointer. */
#define B_operand(where)                        \
  { where = *byteptr++; }

/* Macro U_operand(where);
 moves the next Operand (an Unsigned Integer)
 to (uintL)where or (uintC)where
 and advances the Bytecodepointer. */
#define U_operand(where)                                     \
    { where = *byteptr++; /* read first Byte              */ \
      if ((uintB)where & bit(7)) /* Bit 7 set?            */ \
        { where &= ~bit(7); /* yes -> delete              */ \
          where = where << 8;                            \
          where |= *byteptr++; /* and read next Byte      */ \
    }   }
#if defined(GNU) && defined(MC680X0) && !defined(NO_ASM)
  #undef U_operand
  #define U_operand(where)  \
    __asm__(                 \
      "moveq #0,%0"   "\n\t" \
      "moveb %1@+,%0" "\n\t" \
      "bpl 1f"        "\n\t" \
      "addb %0,%0"    "\n\t" \
      "lslw #7,%0"    "\n\t" \
      "moveb %1@+,%0" "\n"   \
      "1:"                   \
      : "=d" (where), "=a" (byteptr) : "1" (byteptr) )
#endif
#if defined(GNU) && defined(SPARC) && !defined(NO_ASM)
  #undef U_operand
  #define U_operand(where)  \
    { uintL dummy;              \
      __asm__(                      \
        "ldub [%1],%0"       "\n\t" \
        "andcc %0,0x80,%%g0" "\n\t" \
        "be 1f"              "\n\t" \
        " add %1,1,%1"       "\n\t" \
        "sll %0,25,%2"       "\n\t" \
        "ldub [%1],%0"       "\n\t" \
        "srl %2,17,%2"       "\n\t" \
        "add %1,1,%1"        "\n\t" \
        "or %0,%2,%0"        "\n"   \
        "1:"                        \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "ccr" ); \
    }
#endif
#if (defined(GNU) || defined(INTEL)) && defined(I80386) && !defined(NO_ASM)
  #if 0
    /* In earlier times, the GNU assembler assembled */
    /* "testb %edx,%edx" as "testb %dl,%dl". This made possible to */
    /* produce the output in any register. */
    #define OUT_EAX  "=q"
    #define EAX      "%0"
    #define AL       "%0"
  #else
    /* Now "testb %edx,%edx" is invalid everywhere. The macros must */
    /* put their result in %eax. */
    #define OUT_EAX  "=a"
    #define EAX      "%%eax"
    #define AL       "%%al"
  #endif
  #undef U_operand
  #define U_operand(where)  \
    __asm__(                   \
      "movzbl (%1),"EAX "\n\t" \
      "incl %1"         "\n\t" \
      "testb "AL","AL   "\n\t" \
      "jge "LR(1,f)     "\n\t" \
      "andb $127,"AL    "\n\t" \
      "sall $8,"EAX     "\n\t" \
      "movb (%1),"AL    "\n\t" \
      "incl %1"         "\n"   \
      LD(1)":"                 \
      : OUT_EAX (where), "=r" (byteptr) : "1" (byteptr) );
  /* Caution: 1. Der Sun-Assembler doesn't know this Syntax for local labels. */
  /*              That's why we generate our local labels ourselves. */
  /* Caution: 2. ccr is changed. How is this to be declared?? */
#endif
#if defined(GNU) && defined(ARM) && !defined(NO_ASM)
  /* Macros written by Peter Burwood. */
  /* Two versions. Which one to choose? */
  /*        instructions      short case        long case */
  /* v1:          5           2 + 3 skipped     5 */
  /* v2:          5           3 + 2 skipped     4 + 1 skipped */
  /* Let's choose the first one. 1-byte operands are most frequent. */
  #undef U_operand
  #define U_operand(where)  /* (v1) */ \
    { uintL dummy;                     \
      __asm__(                         \
        "ldrb   %0,[%1],#1"     "\n\t" \
        "tst    %0,#0x80"       "\n\t" \
        "bicne  %0,%0,#0x80"    "\n\t" \
        "ldrneb %2,[%1],#1"     "\n\t" \
        "orrne  %0,%2,%0,LSL#8"        \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "cc" ); \
    }
  #if 0
  #undef U_operand
  #define U_operand(where)  /* (v2) */ \
    { uintL dummy;                     \
      __asm__(                         \
        "ldrb   %0,[%1],#1"     "\n\t" \
        "movs   %0,%0,LSL#25"   "\n\t" \
        "movcc  %0,%0,LSR#25"   "\n\t" \
        "ldrcsb %2,[%1],#1"     "\n\t" \
        "orrcs  %0,%2,%0,LSR#17"       \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "cc" ); \
    }
  #endif
#endif

/* Macro S_operand(where); */
/* moves the next Operand (a Signed Integer) */
/* to (uintL)where and advances the bytecodepointer. */
  #define S_operand(where)  \
    { where = *byteptr++; /* read first byte                */ \
      if ((uintB)where & bit(7))                           \
        /* Bit 7 was set                                    */ \
        { where = where << 8;                              \
          where |= *byteptr++; /* subjoin next Byte         */ \
          /* Sign-Extend from 15 to 32 Bits:                */ \
          where = (sintL)((sintL)(sintWL)((sintWL)where << (intWLsize-15)) >> (intWLsize-15)); \
          if (where == 0)                                  \
            /* special case: 2-Byte-Operand = 0 -> 6-Byte-Operand */ \
            { where = (uintL)( ((uintWL)(byteptr[0]) << 8) \
                              | (uintWL)(byteptr[1])       \
                             ) << 16                       \
                    | (uintL)( ((uintWL)(byteptr[2]) << 8) \
                              | (uintWL)(byteptr[3])       \
                             );                            \
              byteptr += 4;                                \
        }   }                                              \
        else                                               \
        /* Bit 7 was deleted                                */ \
        { /* Sign-Extend from 7 to 32 Bits:                 */ \
          where = (sintL)((sintL)(sintBWL)((sintBWL)where << (intBWLsize-7)) >> (intBWLsize-7)); \
        }                                                  \
    }
#if defined(GNU) && defined(MC680X0) && !defined(NO_ASM)
  #undef S_operand
  #define S_operand(where)  \
    __asm__(                   \
      "moveb %1@+,%0"   "\n\t" \
      "bpl 1f"          "\n\t" \
      "lslw #8,%0"      "\n\t" \
      "moveb %1@+,%0"   "\n\t" \
      "addw %0,%0"      "\n\t" \
      "asrw #1,%0"      "\n\t" \
      "bne 2f"          "\n\t" \
      "moveb %1@(2),%0" "\n\t" \
      "swap %0"         "\n\t" \
      "moveb %1@+,%0"   "\n\t" \
      "lsll #8,%0"      "\n\t" \
      "moveb %1@,%0"    "\n\t" \
      "swap %0"         "\n\t" \
      "addql #2,%0"     "\n\t" \
      "moveb %1@+,%0"   "\n\t" \
      "jra 3f"          "\n"   \
      "1:"                "\t" \
      "addb %0,%0"      "\n\t" \
      "asrb #1,%0"      "\n\t" \
      "extw %0"         "\n"   \
      "2:"                "\t" \
      "extl %0"         "\n"   \
      "3:"                     \
      : "=d" (where), "=a" (byteptr) : "1" (byteptr) )
#endif
#if defined(GNU) && defined(SPARC) && !defined(NO_ASM)
  #undef S_operand
  #define S_operand(where)  \
    { uintL dummy;                  \
      __asm__(                      \
        "ldub [%1],%0"       "\n\t" \
        "andcc %0,0x80,%%g0" "\n\t" \
        "be 2f"              "\n\t" \
        " add %1,1,%1"       "\n\t" \
        "sll %0,25,%2"       "\n\t" \
        "ldub [%1],%0"       "\n\t" \
        "sra %2,17,%2"       "\n\t" \
        "orcc %2,%0,%0"      "\n\t" \
        "bne 3f"             "\n\t" \
        " add %1,1,%1"       "\n\t" \
        "ldub [%1],%0"       "\n\t" \
        "sll %0,24,%2"       "\n\t" \
        "ldub [%1+1],%0"     "\n\t" \
        "sll %0,16,%0"       "\n\t" \
        "or %2,%0,%2"        "\n\t" \
        "ldub [%1+2],%0"     "\n\t" \
        "sll %0,8,%0"        "\n\t" \
        "or %2,%0,%2"        "\n\t" \
        "ldub [%1+3],%0"     "\n\t" \
        "or %2,%0,%0"        "\n\t" \
        "b 3f"               "\n\t" \
        " add %1,4,%1"       "\n"   \
        "2:"                   "\t" \
        "sll %0,25,%0"       "\n\t" \
        "sra %0,25,%0"       "\n"   \
        "3:"                   "\t" \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "ccr" ); \
    }
#endif
#if (defined(GNU) || defined(INTEL)) && defined(I80386) && !defined(NO_ASM)
  #undef S_operand
  #define S_operand(where)  \
    __asm__(                   \
      "movzbl (%1),"EAX "\n\t" \
      "incl %1"         "\n\t" \
      "testb "AL","AL   "\n\t" \
      "jge "LR(1,f)     "\n\t" \
      "sall $8,"EAX     "\n\t" \
      "movb (%1),"AL    "\n\t" \
      "incl %1"         "\n\t" \
      "sall $17,"EAX    "\n\t" \
      "sarl $17,"EAX    "\n\t" \
      "jne "LR(2,f)     "\n\t" \
      "movb (%1),"AL    "\n\t" \
      "sall $8,"EAX     "\n\t" \
      "movb 1(%1),"AL   "\n\t" \
      "sall $8,"EAX     "\n\t" \
      "movb 2(%1),"AL   "\n\t" \
      "sall $8,"EAX     "\n\t" \
      "movb 3(%1),"AL   "\n\t" \
      "addl $4,"EAX     "\n\t" \
      "jmp "LR(2,f)     "\n"   \
      LD(1)":"            "\t" \
      "sall $25,"EAX    "\n\t" \
      "sarl $25,"EAX    "\n"   \
      LD(2)":"                 \
      : OUT_EAX (where), "=r" (byteptr) : "1" (byteptr) );
#endif
#if defined(GNU) && defined(ARM) && !defined(NO_ASM)
  /* Macro written by Peter Burwood. */
  #undef S_operand
  #define S_operand(where)  \
    { uintL dummy;                      \
      __asm__(                          \
        "ldrb   %0,[%1],#1"      "\n\t" \
        "movs   %0,%0,LSL#25"    "\n\t" \
        "movcc  %0,%0,ASR#25"    "\n\t" \
        "bcc    "LR(1,f)         "\n\t" \
        "ldrb   %2,[%1],#1"      "\n\t" \
        "orr    %0,%0,%2,LSL#17" "\n\t" \
        "movs   %0,%0,ASR#17"    "\n\t" \
        "bne    "LR(1,f)         "\n\t" \
        "ldrb   %0,[%1],#1"      "\n\t" \
        "ldrb   %2,[%1],#1"      "\n\t" \
        "orr    %0,%2,%0,LSL#8"  "\n\t" \
        "ldrb   %2,[%1],#1"      "\n\t" \
        "orr    %0,%2,%0,LSL#8"  "\n\t" \
        "ldrb   %2,[%1],#1"      "\n\t" \
        "orr    %0,%2,%0,LSL#8"  "\n"   \
        LD(1)":"                        \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "cc" ); \
    }
#endif

/* Macro S_operand_ignore(); */
/* skips the next Operand (a Signed Integer) */
/* and advances the bytecodepointer. */
  #define S_operand_ignore()  \
    { uintB where = *byteptr++; /* read first byte          */ \
      if ((uintB)where & bit(7))                               \
        /* Bit 7 war gesetzt                                    */ \
        { if ((uintB)((where<<1) | *byteptr++) == 0) /* next Byte */ \
            /* special case: 2-Byte-Operand = 0 -> 6-Byte-Operand */ \
            { byteptr += 4; }                                  \
    }   }
#if defined(GNU) && defined(MC680X0) && !defined(NO_ASM)
  #undef S_operand_ignore
  #define S_operand_ignore()  \
    { uintB where;               \
      __asm__(                   \
        "moveb %1@+,%0"   "\n\t" \
        "bpl 1f"          "\n\t" \
        "addb %0,%0"      "\n\t" \
        "orb %1@+,%0"     "\n\t" \
        "bne 1f"          "\n\t" \
        "addql #4,%1"     "\n"   \
        "1:"                     \
        : "=d" (where), "=a" (byteptr) : "1" (byteptr) ); \
    }
#endif
#if defined(GNU) && defined(SPARC) && !defined(NO_ASM)
  #undef S_operand_ignore
  #define S_operand_ignore()  \
    { uintL where;                  \
      uintL dummy;                  \
      __asm__(                      \
        "ldub [%1],%0"       "\n\t" \
        "andcc %0,0x80,%%g0" "\n\t" \
        "be 1f"              "\n\t" \
        " add %1,1,%1"       "\n\t" \
        "sll %0,1,%2"        "\n\t" \
        "ldub [%1],%0"       "\n\t" \
        "orcc %2,%0,%0"      "\n\t" \
        "bne 1f"             "\n\t" \
        " add %1,1,%1"       "\n\t" \
        "add %1,4,%1"        "\n"   \
        "1:"                        \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "ccr" ); \
    }
#endif
#if defined(GNU) && defined(ARM) && !defined(NO_ASM)
  /* Macro written by Peter Burwood. */
  #undef S_operand_ignore
  #define S_operand_ignore()  \
    { uintL where;                  \
      uintL dummy;                  \
      __asm__(                          \
        "ldrb   %0,[%1],#1"      "\n\t" \
        "movs   %0,%0,LSL#25"    "\n\t" \
        "bcc    "LR(1,f)         "\n\t" \
        "ldrb   %2,[%1],#1"      "\n\t" \
        "orrs   %0,%2,%0,LSR#24" "\n\t" \
        "addeq  %1,%1,#4"        "\n"   \
        LD(1)":"                        \
        : "=r" (where), "=r" (byteptr), "=r" (dummy) : "1" (byteptr) : "cc" ); \
    }
#endif

/* Macro L_operand(where); */
/* moves the next Operand (a Label) */
/* to (uintB*)where and advances the bytecodepointer. */
  #define L_operand(Lwhere)  \
    { uintL where; /* variable for the displacement */ \
      S_operand(where); /* Displacement                 */ \
      Lwhere = byteptr + (sintL)where; /* add           */ \
    }

/* Macro L_operand_ignore(); */
/* skips the next Operand (a Label) */
/* and advances the Bytecodepointer. */
  #define L_operand_ignore()  S_operand_ignore()
      #undef CODEPTR
      #define CODEPTR  (&codeptr->data[0])

/* do not use cod_labels */
#ifdef FAST_DISPATCH
#undef next_byte
#endif

static /*maygc*/ Values jit_compile_ (object closure_in, Sbvector codeptr,
                                      const uintB* byteptr_in)
{
  GCTRIGGER_IF(true, {
      if (*byteptr_in == cod_handler_begin_push)
        GCTRIGGER3(closure_in,handler_args.condition,handler_args.spdepth);
      else
        GCTRIGGER1(closure_in);
    });
  /* situate argument closure in register: */
  #ifdef closure_register
  object closure __asm__(closure_register);
  closure = closure_in;
  #endif
  /* situate argument byteptr in register: */
  #ifdef byteptr_register
  register const uintB* byteptr __asm__(byteptr_register);
  byteptr = byteptr_in;
  #endif
  TRACE_CALL(closure,'B','C');

  const uintB* saved_byteptr = byteptr;
  /* byteptr_min is never zero: Codevec is stored in the first bytes of the Sbvector */
  const uintL byteptr_min = ((Codevec)codeptr)->ccv_flags & bit(7)
      ? CCV_START_KEY : CCV_START_NONKEY;
  const uintL byteptr_max = sbvector_length(codeptr)-1;
  const uintL sp_length = (uintL)(((Codevec)codeptr)->ccv_spdepth_1)
      + jmpbufsize * (uintL)(((Codevec)codeptr)->ccv_spdepth_jmpbufsize);
 #ifdef DEBUG_BYTECODE
  sintL byteptr_bad_jump;
 #endif

  /* codebuffer: contains the JITed code (Temp allocation scheme) */
  jit_insn *codeBuffer = malloc(sizeof(jit_insn)*byteptr_max*JITC_AVG_BCSIZE);
  /* bcIndex: Address of the beginning of each BC in codeBuffer
     Used by the compiler to patch jumps.  */
  jit_insn **bcIndex = calloc(byteptr_max+1,sizeof(jit_insn*));
  /* save JITC code into the closure */
  struct jitc_object *jo = malloc(sizeof(struct jitc_object));
  jo->jo_gc_mark = 0;
  jo->code_buffer = codeBuffer;
  jo->bc_index = bcIndex;
  jo->jo_next = all_jitc_objects;
  all_jitc_objects = jo;
  TheFpointer(cclosure_jitc(closure))->fp_pointer = jo;

  (void)jit_set_ip(codeBuffer);
  jit_prolog(2);
  /* Arguments */
  const int jitc_arg_closure = jit_arg_i();
  const int jitc_arg_startpos= jit_arg_i();
  /* Stack allocated variables */
  const int jitc_sp_space = (sp_length)?jit_allocai(sizeof(SPint)*sp_length):0;
  const int jitc_sp_ptr = jit_allocai(sizeof(void*)); /* top of SP */
  const int jitc_var_a = jit_allocai(sizeof(void*)); /* Temp variables */
  const int jitc_var_b = jit_allocai(sizeof(void*));
  const int jitc_var_c = jit_allocai(sizeof(void*));
  const int jitc_var_d = jit_allocai(sizeof(void*));
  const int bt_here = jit_allocai(sizeof(struct backtrace_t));
  /* Init of jitc_sp_ptr */
  jit_addi_p(JIT_R0,JIT_FP,jitc_sp_space);
  jit_addi_p(JIT_R0,JIT_R0,sizeof(SPint)*(sp_length)); /* SP grows down */
  jit_stxi_p(jitc_sp_ptr,JIT_FP,JIT_R0);

  /* situate closure in STACK, below the arguments: */
  jit_getarg_p(JIT_R2, jitc_arg_closure);
  jitc_push_stackr();
  jitc_getptr_stacki(0);
  jit_movr_p(JIT_V1,JIT_R0); /* Permanently in JIT_V1 */

  /* Jump to starting instruction */
  jit_getarg_p(JIT_R2, jitc_arg_startpos);
  jitc_bcjmpr();


  /* next Byte to be interpreted */
  /* > codeptr: Closure's codevector, a Simple-Bit-Vector, pointable */
  /* > byteptr: pointer to the next byte in code */
  byteptr = CODEPTR + byteptr_min;

  next_byte:
  /* definition by cases, according to byte to be interpreted byte */
  if((byteptr - CODEPTR) > byteptr_max)
        goto finished;
  uintL bcPos = byteptr - CODEPTR;

  jitc_check_overflow();
  jitc_patch_fwdjmps();
  bcIndex[bcPos] = (jit_insn*)jit_get_ip().ptr;

  switch (*byteptr++)
  #define CASE  case (uintB)
  { /* ------------------- (1) Constants ----------------------- */
    CASE cod_nil: {             /* (NIL) */
      jitc_set_valuesi_1(as_oint(NIL));
      goto next_byte;
    }
    CASE cod_nil_push: {        /* (NIL&PUSH) */
      jitc_push_stacki(as_oint(NIL));
      goto next_byte;
    }
    CASE cod_push_nil: {        /* (PUSH-NIL n) */
      uintC n;
      U_operand(n);
      if (n != 0 ) {
        jit_movi_ui(JIT_R2,n);
        jitc_repeatp(JIT_R2,
                    jitc_push_stacki(as_oint(NIL));
                    );
      }
      goto next_byte;
    }
    CASE cod_t: {               /* (T) */
      jitc_set_valuesi_1(as_oint(T));
      goto next_byte;
    }
    CASE cod_t_push: {          /* (T&PUSH) */
      jitc_push_stacki(as_oint(T));
      goto next_byte;
    }
    CASE cod_const: {           /* (CONST n) */
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const_push: {      /* (CONST&PUSH n) */
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    /* ------------------- (2) static Variables ----------------------- */
    CASE cod_load: {            /* (LOAD n) */
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load_push: {       /* (LOAD&PUSH n) */
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_loadi: {           /* (LOADI k1 k2 n) */
      uintL k1;
      uintL k2;
      uintL n;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_loadi_push: {      /* (LOADI&PUSH k1 k2 n) */
      uintL k1;
      uintL k2;
      uintL n;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_loadc: {           /* (LOADC n m) */
      uintL n;
      uintL m;
      U_operand(n);
      U_operand(m);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_loadc_push: {      /* (LOADC&PUSH n m) */
      uintL n;
      uintL m;
      U_operand(n);
      U_operand(m);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_loadv: {           /* (LOADV k m) */
      uintC k;
      uintL m;
      U_operand(k);
      U_operand(m);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);

      if (k != 0) {
        jit_movi_l(JIT_V2,k);
        jitc_repeatp(JIT_V2,
                    jitc_get_fieldr(Svector,data);
                    jit_movr_p(JIT_R2,JIT_R0);
                    );
      }

      jitc_get_svecdatair(m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_loadv_push: {      /* (LOADV&PUSH k m) */
      uintC k;
      uintL m;
      jit_insn* ref;
      U_operand(k);
      U_operand(m);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);

      if (k != 0) {
        jit_movi_l(JIT_V2,k);
        jitc_repeatp(JIT_V2,
                    jitc_get_fieldr(Svector,data);
                    jit_movr_p(JIT_R2,JIT_R0);
                    );
      }

      jitc_get_svecdatair(m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_loadic: {          /* (LOADIC k1 k2 n m) */
      uintL k1;
      uintL k2;
      uintL n;
      uintL m;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);
      U_operand(m);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_store: store: {    /* (STORE n) */
      uintL n;
      U_operand(n);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0, JIT_R2);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_pop_store: {       /* (POP&STORE n) */
      uintL n;
      U_operand(n);

      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0, JIT_R2);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_storei: {          /* (STOREI k1 k2 n) */
      uintL k1;
      uintL k2;
      uintL n;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_framei(n);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load_storec: {     /* (LOAD&STOREC k m n) */
      uintL k;
      uintL n;
      uintL m;
      U_operand(k);
      U_operand(n);
      U_operand(m);

      jitc_get_stacki(k);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_valuesr_1();
      jit_str_p(JIT_R0,JIT_R2);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R2,JIT_R0);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_storec: {          /* (STOREC n m) */
      uintL n;
      uintL m;
      U_operand(n);
      U_operand(m);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R2,JIT_R0);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_storev: {                /* (STOREV k m) */
      uintC k;
      uintL m;
      U_operand(k);
      U_operand(m);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);

      if (k != 0) {
        jit_movi_l(JIT_V2,k);
        jitc_repeatp(JIT_V2,
                    jitc_get_fieldr(Svector,data);
                    jit_movr_p(JIT_R2,JIT_R0);
                    );
      }

      jitc_getptr_svecdatair(m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R2,JIT_R0);
      jitc_set_mvcounti(1);

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_storeic: {         /* (STOREIC k1 k2 n m) */
      uintL k1;
      uintL k2;
      uintL n;
      uintL m;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);
      U_operand(m);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_svecdatair(1+m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R2,JIT_R0);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    /* ------------------- (3) dynamic Variables ----------------------- */
    CASE cod_getvalue: {        /* (GETVALUE n) */
      uintL n;
      jit_insn  *ref;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_symvalr();
      ref = jit_bnei_p(jit_forward(), JIT_R0, as_oint(unbound));
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_errori(unbound_variable,"~S: symbol ~S has no value");
      jit_patch(ref);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_getvalue_push: {         /* (GETVALUE&PUSH n) */
      uintL n;
      jit_insn  *ref;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_symvalr();
      ref = jit_bnei_p(jit_forward(), JIT_R0, as_oint(unbound));
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_errori(unbound_variable,"~S: symbol ~S has no value");
      jit_patch(ref);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_setvalue: {        /* (SETVALUE n) */
      uintL n;
      jit_insn  *ref;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_sym_constpr();
      ref = jit_bnei_p(jit_forward(), JIT_R0, 1);
      jitc_push_stackr();
      jitc_getptr_fieldr(Cclosure, clos_consts);
      jit_ldxi_p(JIT_R2,JIT_R0,sizeof(gcv_object_t));
      jitc_push_stackr();
      jitc_errori(error_condition,"~S: assignment to constant symbol ~S is impossible");
      jit_patch(ref);
      jitc_getptr_symvalr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R2,JIT_R0);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_bind: {            /* (BIND n) */
      uintL n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_V2,JIT_R0);
      jit_movr_p(JIT_R2,JIT_V2);
      /* Create frame : */
      jitc_get_symvalr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_push_stackr();
      jitc_finish_framer(DYNBIND,3);
      /* modify value */
      jitc_getptr_symvalr();
      jit_ldi_p(JIT_R1, &(value1));
      jit_str_p(JIT_R0, JIT_R1);

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_unbind1: {               /* (UNBIND1) */
      /* unwind variable-binding-frame: */
      jit_insn *rf1,*rf2;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_getptr_stacki(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_gettop_framer();
      jit_movr_p(JIT_R2,JIT_R0);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R2); /* new_stack */
      jitc_getptbl_stackr();
      jit_movr_p(JIT_V2,JIT_R0); /* frame_end */
      jitc_getptr_stacki(1);
      jit_movr_p(JIT_V1,JIT_R0); /* bindingptr */

      rf1 = jit_get_label();
      rf2 = jit_beqr_p(jit_forward(),JIT_V1,JIT_V2);
      jit_ldr_p(JIT_R2,JIT_V1);
      jitc_getptr_symvalr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_skip_stack_opir(JIT_R1,JIT_V1,sizeof(gcv_object_t));
      jit_ldr_p(JIT_R0,JIT_R1);
      jit_str_p(JIT_R2,JIT_R0);

      jitc_skip_stack_opir(JIT_V1,JIT_V1,2*sizeof(gcv_object_t));
      (void)jit_jmpi(rf1);
      jit_patch(rf2);

      jit_ldxi_p(JIT_R0,JIT_FP,jitc_var_c); /* new_stack */
      jit_sti_p(&STACK,JIT_R0);

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_unbind: {          /* (UNBIND n) */
      uintC n;
      jit_insn *rf1,*rf2,*rf3;
      U_operand(n); /* n>0 */

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jit_ldi_p(JIT_V2,&STACK); /* FRAME */
      jit_movi_l(JIT_R0,n);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R0);
      rf1 = jit_get_label();
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_framei(1);
      jit_movr_p(JIT_V1,JIT_R0); /* bindingptr */
      jitc_getptr_framei(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_gettop_framer();
      jit_movr_p(JIT_R2,JIT_R0);
      jit_stxi_p(jitc_var_d,JIT_FP,JIT_R2); /* new_frame */
      jitc_getptbl_stackr();
      jit_movr_p(JIT_V2,JIT_R0); /* frame_end */

      rf2 = jit_get_label();
      rf3 = jit_beqr_p(jit_forward(),JIT_V1,JIT_V2);
      jit_ldr_p(JIT_R2,JIT_V1);
      jitc_getptr_symvalr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_skip_stack_opir(JIT_R1,JIT_V1,sizeof(gcv_object_t));
      jit_ldr_p(JIT_R0,JIT_R1);
      jit_str_p(JIT_R2,JIT_R0);

      jitc_skip_stack_opir(JIT_V1,JIT_V1,2*sizeof(gcv_object_t));
      (void)jit_jmpi(rf2);
      jit_patch(rf3);

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_d); /* new_frame */

      jit_ldxi_p(JIT_R0,JIT_FP,jitc_var_c);
      jit_subi_i(JIT_R2,JIT_R0,1);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R2);
      jit_bnei_i(rf1,JIT_R2,0);

      jit_sti_p(&STACK,JIT_V2);

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_progv: {           /* (PROGV) */
      jit_ldi_p(JIT_R0,&STACK);
      jitc_skip_stack_opir(JIT_R2,JIT_R0,sizeof(gcv_object_t));
      jitc_push_spr();
      jit_prepare(2);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jitc_pop_stack();
      jit_pusharg_p(JIT_R0);
      jit_finish(progv);

      jitc_tag_unsafe();
      goto next_byte;
    }
    /* ------------------- (4) Stack operations ----------------------- */
    CASE cod_push: {            /* (PUSH) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_pop: {             /* (POP) */
      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_skip: {            /* (SKIP n) */
      uintL n;
      U_operand(n);

      jitc_skip_stacki(n);

      goto next_byte;
    }
    CASE cod_skipi: {           /* (SKIPI k1 k2 n) */
      uintL k1;
      uintL k2;
      uintL n;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);

      jitc_skip_spi(k1+jmpbufsize*k2);
      jitc_pop_sp();
      jitc_skip_stack_opir(JIT_R1,JIT_R0,n*sizeof(gcv_object_t));
      jit_sti_p(&STACK,JIT_R1);

      goto next_byte;
    }
    CASE cod_skipsp: {          /* (SKIPSP k1 k2) */
      uintL k1;
      uintL k2;
      U_operand(k1);
      U_operand(k2);

      jitc_skip_spi(k1+jmpbufsize*k2);

      goto next_byte;
    }
    /* ------------------- (5) Control Flow and Jumps ----------------------- */
    CASE cod_skip_ret: {        /* (SKIP&RET n) */
      uintL n;
      U_operand(n);

      jitc_skip_stacki(n);

      jitc_return();

      goto next_byte;
    }
    CASE cod_skip_retgf: {      /* (SKIP&RETGF n) */
      uintL n;
      U_operand(n);
      if (((Codevec)codeptr)->ccv_flags & bit(3)) { /* call inhibition? */
        jitc_skip_stacki(n);
        jitc_set_mvcounti(1);
      } else {
        uintL r = ((Codevec)codeptr)->ccv_numreq;
        n -= r;
        if (((Codevec)codeptr)->ccv_flags & bit(0)) {
          jitc_skip_stacki(n-1);
          jit_prepare(3);
          jitc_pop_stack();
          jit_pusharg_p(JIT_R0);
          jit_movi_l(JIT_R0,r);
          jit_pusharg_p(JIT_R0);
          jitc_get_valuesr_1();
          jit_pusharg_p(JIT_R0);
          jit_finish(apply);
        } else {
          jitc_skip_stacki(n);
          jit_prepare(2);
          jit_movi_l(JIT_R0,r);
          jit_pusharg_p(JIT_R0);
          jitc_get_valuesr_1();
          jit_pusharg_p(JIT_R0);
          jit_finish(funcall);
        }
      }
      jitc_return();

      goto next_byte;
    }
    CASE cod_jmp: {             /* (JMP label) */
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_bcjmpi(label_byteptr - CODEPTR);

      goto next_byte;
    }
    CASE cod_jmpif: {           /* (JMPIF label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifnot: {        /* (JMPIFNOT label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpif1: {          /* (JMPIF1 label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_set_mvcounti(1);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifnot1: {       /* (JMPIFNOT1 label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_set_mvcounti(1);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifatom: {       /* (JMPIFATOM label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_sym_atompr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifconsp: {      /* (JMPIFCONSP label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifeq: {         /* (JMPIFEQ label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      rf1 = jit_bner_p(jit_forward(),JIT_R0,JIT_R2);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifnoteq: {      /* (JMPIFNOTEQ label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      rf1 = jit_beqr_p(jit_forward(),JIT_R0,JIT_R2);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifeqto: {       /* (JMPIFEQTO n label) */
      jit_insn *rf1;
      uintL n;
      const uintB* label_byteptr;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      rf1 = jit_bner_p(jit_forward(),JIT_R0,JIT_R2);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmpifnoteqto: {    /* (JMPIFNOTEQTO n label) */
      jit_insn *rf1;
      uintL n;
      const uintB* label_byteptr;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      rf1 = jit_beqr_p(jit_forward(),JIT_R0,JIT_R2);
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_jmphash: {         /* (JMPHASH n label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      uintL n;
      U_operand(n);
      const uintB *saved_byteptr = byteptr;
      L_operand(label_byteptr);

      jit_prepare(3);
      jit_movi_l(JIT_R0,false);
      jit_pusharg_p(JIT_R0);
      jitc_get_cconsti(n);
      jit_pusharg_p(JIT_R0);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jit_finish(gethash);
      jit_retval(JIT_R2);

      rf1 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(nullobj));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);
      jitc_fixnum2valr();
      jit_movr_p(JIT_R2,JIT_R0);
      jit_addi_p(JIT_R2,JIT_R2,(saved_byteptr - CODEPTR));

      jitc_bcjmpr();

      goto next_byte;
    }
    CASE cod_jmphashv: {        /* (JMPHASHV n label) */
      jit_insn *rf1;
      const uintB* label_byteptr;
      uintL n;
      U_operand(n);
      const uintB *saved_byteptr = byteptr;
      L_operand(label_byteptr);

      jit_prepare(3);
      jit_movi_l(JIT_R0,false);
      jit_pusharg_p(JIT_R0);
      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_svecdatair(n);
      jit_pusharg_p(JIT_R0);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jit_finish(gethash);
      jit_retval(JIT_R2);

      rf1 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(nullobj));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);
      jitc_fixnum2valr();
      jit_movr_p(JIT_R2,JIT_R0);
      jit_addi_p(JIT_R2,JIT_R2,(saved_byteptr - CODEPTR));

      jitc_bcjmpr();

      goto next_byte;
    }
#define jitc_save_backtrace_jsr(statement) {             \
      jit_addi_p(JIT_R0,JIT_FP,bt_here);                \
      jit_ldi_p(JIT_R1,&back_trace);                                    \
      jit_stxi_i (jit_field(struct backtrace_t, bt_next), JIT_R0, JIT_R1); \
      jit_ldr_p(JIT_R1,JIT_V1);                                         \
      jit_stxi_i (jit_field(struct backtrace_t, bt_function), JIT_R0, JIT_R1); \
      jit_ldi_p(JIT_R1,&(STACK));                                       \
      jit_stxi_i (jit_field(struct backtrace_t, bt_stack), JIT_R0, JIT_R1); \
      jit_movi_l(JIT_R1,-1);                                            \
      jit_stxi_i (jit_field(struct backtrace_t, bt_num_arg), JIT_R0, JIT_R1); \
      jit_sti_p(&back_trace, JIT_R0);                                   \
      statement;                                                        \
      jit_ldi_p(JIT_R0,&back_trace);                                    \
      jit_ldxi_p(JIT_R1, JIT_R0, jit_field(struct backtrace_t, bt_next)); \
      jit_sti_p(&back_trace, JIT_R1);                                   \
    }
    CASE cod_jsr: {             /* (JSR label) */
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_check_stack();
      jitc_save_backtrace_jsr({
          jit_prepare(3);
          jit_ldr_p(JIT_R2,JIT_V1);
          jitc_get_fieldr(Closure,clos_codevec);
          jit_addi_p(JIT_R1,JIT_R0,TheSbvector(as_object(0))); /* codeptr */
          jit_addi_p(JIT_R0,JIT_R1,(label_byteptr - (uintB*)codeptr));
          jit_pusharg_p(JIT_R0);
          jit_pusharg_p(JIT_R1);
          jit_pusharg_p(JIT_R2);
          jit_finish(cclosure_run);
        });
      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_jsr_push: {        /* (JSR&PUSH label) */
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_check_stack();
      jitc_save_backtrace_jsr({
          jit_prepare(3);
          jit_ldr_p(JIT_R2,JIT_V1);
          jitc_get_fieldr(Closure,clos_codevec);
          jit_addi_p(JIT_R1,JIT_R0,TheSbvector(as_object(0))); /* codeptr */
          jit_addi_p(JIT_R0,JIT_R1,(label_byteptr - (uintB*)codeptr));
          jit_pusharg_p(JIT_R0);
          jit_pusharg_p(JIT_R1);
          jit_pusharg_p(JIT_R2);
          jit_finish(cclosure_run);
        });
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_jmptail: {         /* (JMPTAIL m n label) */
      const uintB* label_byteptr;
      uintL m;
      uintL n;
      U_operand(m);
      U_operand(n);
      L_operand(label_byteptr);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jit_ldi_p(JIT_R0,&STACK);
      jitc_skip_stack_opir(JIT_V1,JIT_R0,m*sizeof(gcv_object_t));
      jitc_skip_stack_opir(JIT_R2,JIT_R0,n*sizeof(gcv_object_t));

      jit_movi_l(JIT_V2,m);
      jitc_repeat(JIT_V2,{
         #ifdef STACK_DOWN /* Because of postfix/prefix increment diffs */
          jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
         #endif
          jitc_frame_nextx(JIT_V1);
          jit_str_p(JIT_R2,JIT_R0);
         #ifdef STACK_UP
          jit_addi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
         #endif
        });

      /* REMOVE -- ALOT OF THINGS TO REMOVE HERE */
     #ifdef STACK_DOWN
      jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
     #endif
      /* jit_sti_p(&closureptr,JIT_R2); */
      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldr_p(JIT_R0,JIT_V1);
      jit_str_p(JIT_R2,JIT_R0);
     #ifdef STACK_UP
      jit_addi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
     #endif
      jit_sti_p(&STACK,JIT_R2);

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_bcjmpi(label_byteptr - CODEPTR);

      goto next_byte;
    }
    /* ------------------- (6) Environments and Closures ----------------- */
    CASE cod_venv: {            /* (VENV) */
      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_make_vector1_push: { /* (MAKE-VECTOR1&PUSH n) */
      uintL n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jit_prepare(1);
      jit_movi_l(JIT_R0,(n+1));
      jit_pusharg_p(JIT_R0);
      jit_finish(allocate_vector);
      jit_retval(JIT_V2);
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_svecdatair(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_stacki(0);
      jit_str_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(0);
      jit_str_p(JIT_R0,JIT_V2);

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_copy_closure: {    /* (COPY-CLOSURE m n) */
      uintL m;
      uintL n;
      U_operand(m);
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_cconsti(m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      /* Allocate closure */
      jit_prepare(2);
      jitc_getlenr(Cclosure);
      jit_pusharg_p(JIT_R0);
      jitc_get_fieldr(Cclosure,tfl);
      jit_rshi_i(JIT_R0,JIT_R0,8);
      jit_andi_ui(JIT_R0,JIT_R0,0xFF);
      jit_lshi_i(JIT_R0,JIT_R0,8);
      jit_addi_p(JIT_R0,JIT_R0,Rectype_Closure);
      jit_pusharg_p(JIT_R0);
      jit_finish(allocate_srecord_);
      jit_retval(JIT_V1);
      jit_movr_p(JIT_R2,JIT_V1);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R2);

      /* Copy the closure */
      jitc_pop_stack(); /* oldclos */
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getlenr(Cclosure);
      jit_movr_p(JIT_V2,JIT_R0);
      jit_addi_p(JIT_V1, JIT_V1, TheCclosure(as_object(jit_ptr_field(Srecord, recdata)))); /* newclos */
      jit_addi_p(JIT_R2, JIT_R2, TheCclosure(as_object(jit_ptr_field(Srecord, recdata)))); /* oldclos */
      jitc_repeatp(JIT_V2,
                  jit_ldr_p(JIT_R1,JIT_R2);
                  jit_str_p(JIT_V1,JIT_R1);
                  jit_addi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
                  jit_addi_p(JIT_V1,JIT_V1,sizeof(gcv_object_t));
                  );

      /* Copy stack to closure */
      jit_ldxi_p(JIT_R2,JIT_FP,jitc_var_c); /* oldclos */
      jitc_getptr_fieldr(Cclosure,clos_consts);
      jit_addi_p(JIT_R2,JIT_R0,n*sizeof(gcv_object_t)); /* newptr */
      jit_movi_l(JIT_V2,n);
      jitc_repeatp(JIT_V2,
                  jitc_pop_stack();
                  jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
                  jit_str_p(JIT_R2,JIT_R0);
                  );
      jit_ldxi_p(JIT_R2,JIT_FP,jitc_var_c);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_copy_closure_push: { /* (COPY-CLOSURE&PUSH m n) */
      uintL m;
      uintL n;
      U_operand(m);
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_cconsti(m);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      /* Allocate closure */
      jit_prepare(2);
      jitc_getlenr(Cclosure);
      jit_pusharg_p(JIT_R0);
      jitc_get_fieldr(Cclosure,tfl);
      jit_rshi_i(JIT_R0,JIT_R0,8);
      jit_andi_ui(JIT_R0,JIT_R0,0xFF);
      jit_lshi_i(JIT_R0,JIT_R0,8);
      jit_addi_p(JIT_R0,JIT_R0,Rectype_Closure);
      jit_pusharg_p(JIT_R0);
      jit_finish(allocate_srecord_);
      jit_retval(JIT_V1);
      jit_movr_p(JIT_R2,JIT_V1);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R2);

      /* Copy the closure */
      jitc_pop_stack(); /* oldclos */
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getlenr(Cclosure);
      jit_movr_p(JIT_V2,JIT_R0);
      jit_addi_p(JIT_V1, JIT_V1, TheCclosure(as_object(jit_ptr_field(Srecord, recdata)))); /* newclos */
      jit_addi_p(JIT_R2, JIT_R2, TheCclosure(as_object(jit_ptr_field(Srecord, recdata)))); /* oldclos */
      jitc_repeatp(JIT_V2,
                  jit_ldr_p(JIT_R1,JIT_R2);
                  jit_str_p(JIT_V1,JIT_R1);
                  jit_addi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
                  jit_addi_p(JIT_V1,JIT_V1,sizeof(gcv_object_t));
                  );

      /* Copy stack to closure */
      jit_ldxi_p(JIT_R2,JIT_FP,jitc_var_c); /* oldclos */
      jitc_getptr_fieldr(Cclosure,clos_consts);
      jit_addi_p(JIT_R2,JIT_R0,n*sizeof(gcv_object_t)); /* newptr */
      jit_movi_l(JIT_V2,n);
      jitc_repeatp(JIT_V2,
                  jitc_pop_stack();
                  jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
                  jit_str_p(JIT_R2,JIT_R0);
                  );
      jit_ldxi_p(JIT_R2,JIT_FP,jitc_var_c);
      jitc_push_stackr();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    /* ------------------- (7) Function Calls ----------------------- */
    CASE cod_call: {            /* (CALL k n) */
      uintC k;
      uintL n;
      U_operand(k);
      U_operand(n);

      jitc_funcall();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call_push: {       /* (CALL&PUSH k n) */
      uintC k;
      uintL n;
      U_operand(k);
      U_operand(n);

      jitc_funcall();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call0: {           /* (CALL0 n) */
      uintL n;
      U_operand(n);

      jitc_funcall0();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call1: {           /* (CALL1 n) */
      uintL n;
      U_operand(n);

      jitc_funcall1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call1_push: {      /* (CALL1&PUSH n) */
      uintL n;
      U_operand(n);

      jitc_funcall1();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call2: {           /* (CALL2 n) */
      uintL n;
      U_operand(n);

      jitc_funcall2();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call2_push: {      /* (CALL2&PUSH n) */
      uintL n;
      U_operand(n);

      jitc_funcall2();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls1: {          /* (CALLS1 n) */
      uintL n;
      B_operand(n);

      jitc_funcalls1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls1_push: {     /* (CALLS1&PUSH n) */
      uintL n;
      B_operand(n);

      jitc_funcalls1();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls2: {          /* (CALLS2 n) */
      uintL n;
      B_operand(n);

      jitc_funcalls2();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls2_push: {     /* (CALLS2&PUSH n) */
      uintL n;
      B_operand(n);

      jitc_funcalls2();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callsr: {          /* (CALLSR m n) */
      uintL m;
      uintL n;
      U_operand(m);
      B_operand(n);

      jitc_funcallsr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callsr_push: {     /* (CALLSR&PUSH m n) */
      uintL m;
      uintL n;
      U_operand(m);
      B_operand(n);

      jitc_funcallsr();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callc: {           /* (CALLC) */
      jitc_funcallc();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callc_push: {      /* (CALLC&PUSH) */
      jitc_funcallc();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callckey: {        /* (CALLCKEY) */
      jitc_funcallckey();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callckey_push: {   /* (CALLCKEY&PUSH) */
      jitc_funcallckey();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_funcall: {         /* (FUNCALL n) */
      uintL n;
      U_operand(n);

      jit_prepare(2);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(funcall);
      jitc_skip_stacki(1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_funcall_push: {    /* (FUNCALL&PUSH n) */
      uintL n;
      U_operand(n);

      jit_prepare(2);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(funcall);
      jitc_getptr_stacki(0);
      jit_movr_p(JIT_R1,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R1,JIT_R0);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_apply: {           /* (APPLY n) */
      uintL n;
      U_operand(n);

      jit_prepare(3);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(apply);
      jitc_skip_stacki(1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_apply_push: {      /* (APPLY&PUSH n) */
      uintL n;
      U_operand(n);

      jit_prepare(3);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(apply);
      jitc_getptr_stacki(0);
      jit_movr_p(JIT_R1,JIT_R0);
      jitc_get_valuesr_1();
      jit_str_p(JIT_R1,JIT_R0);

      jitc_tag_unsafe();
      goto next_byte;
    }
  /* ------------------- (8) optional and Keyword-arguments -------------- */
    CASE cod_push_unbound: {    /* (PUSH-UNBOUND n) */
      uintC n;
      jit_insn* ref;
      U_operand(n);

      jit_movi_l(JIT_R2,n);
      jitc_repeat(JIT_R2,
                 jitc_push_stacki(as_oint(unbound));
                 );

      goto next_byte;
    }
    CASE cod_unlist: {          /* (UNLIST n m) */
      jit_insn *rf1=0,*rf2=0,*rf3=0;
      uintC n;
      uintC m;
      U_operand(n);
      U_operand(m);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      if (n > 0) {
        jit_movi_l(JIT_V2,n);
        jitc_repeatp(JIT_V2,
                    jitc_sym_atompr();
                    rf2 = jit_beqi_p(jit_forward(), JIT_R0, 1);
                    jitc_get_fieldr(Cons,cdr);
                    jit_movr_p(JIT_V1,JIT_R0);
                    jitc_get_fieldr(Cons,car);
                    jit_movr_p(JIT_R2,JIT_R0);
                    jitc_push_stackr();
                    jit_movr_p(JIT_R2,JIT_V1);
                    );
      }

      jitc_sym_atompr();
      rf1 = jit_beqi_p(jit_forward(), JIT_R0, 1);
      jit_prepare(1);
      jit_movi_l(JIT_R0,as_oint(S(lambda)));
      jit_pusharg_p(JIT_R0);
      jit_finish(error_apply_toomany);

      if (n > 0) {
        jit_patch(rf2);
        rf3 = jit_blei_p(jit_forward(),JIT_V2,m);
        jit_prepare(2);
        jit_pusharg_p(JIT_R2);
        jit_movi_l(JIT_R0,as_oint(S(lambda)));
        jit_pusharg_p(JIT_R0);
        jit_finish(error_apply_toofew);
        jit_patch(rf3);
        jitc_repeatp(JIT_V2,
                    jitc_push_stacki(as_oint(unbound));
                    );
      }

      jit_patch(rf1);
      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_unliststar: {      /* (UNLIST* n m) */
      jit_insn *rf1=0,*rf2=0,*rf3=0;
      uintC n;
      uintC m;
      U_operand(n);
      U_operand(m);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      if (n > 0) {
        jit_movi_l(JIT_V2,n);
        jitc_repeatp(JIT_V2,
                    jitc_sym_atompr();
                    rf2 = jit_beqi_p(jit_forward(), JIT_R0, 1);
                    jitc_get_fieldr(Cons,cdr);
                    jit_movr_p(JIT_V1,JIT_R0);
                    jitc_get_fieldr(Cons,car);
                    jit_movr_p(JIT_R2,JIT_R0);
                    jitc_push_stackr();
                    jit_movr_p(JIT_R2,JIT_V1);
                    );
      }

      jitc_push_stackr();
      rf1 = jit_jmpi(jit_forward());

      if (n > 0) {
        jit_patch(rf2);
        rf3 = jit_blei_p(jit_forward(),JIT_V2,m);
        jit_prepare(2);
        jit_pusharg_p(JIT_R2);
        jit_movi_l(JIT_R0,as_oint(S(lambda)));
        jit_pusharg_p(JIT_R0);
        jit_finish(error_apply_toofew);
        jit_patch(rf3);
        jitc_repeatp(JIT_V2,
                    jitc_push_stacki(as_oint(unbound));
                    );
        jitc_push_stacki(as_oint(NIL));
      }
      jit_patch(rf1);
      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_jmpifboundp: {     /* (JMPIFBOUNDP n label) */
      jit_insn *rf1;
      uintL n;
      const uintB* label_byteptr;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_get_stacki(n);
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(unbound));
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_boundp: {          /* (BOUNDP n) */
      jit_insn *rf1,*rf2;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(unbound));
      jitc_set_valuesi_1(as_oint(NIL));
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jitc_set_valuesi_1(as_oint(T));
      jit_patch(rf2);

      goto next_byte;
    }
    CASE cod_unbound_nil: {     /* (UNBOUND->NIL n) */
      jit_insn *ref;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      ref = jit_bnei_p(jit_forward(),JIT_R0,as_oint(unbound));
      jitc_getptr_stacki(n);
      jit_movi_l(JIT_R1,as_oint(NIL));
      jit_str_p(JIT_R0,JIT_R1);
      jit_patch(ref);

      goto next_byte;
    }
    /* ------------------- (9) Treatment of multiple values ---------------- */
    CASE cod_values0: {         /* (VALUES0) */
      jitc_set_valuesi_1(as_oint(NIL));
      jitc_set_mvcounti(0);

      goto next_byte;
    }
    CASE cod_values1: {         /* (VALUES1) */
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_stack_to_mv: {     /* (STACK-TO-MV n) */
      uintL n;
      U_operand(n);
      if (n >= mv_limit) GOTO_ERROR(error_toomany_values);
      if (n == 0) {
        jitc_rawset_valuesi_1(as_oint(NIL));
        jitc_set_mvcounti(0);
      } else {
        jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

        jitc_set_mvcounti(n);
        jitc_getptr_valuesi(n);
        jit_movr_p(JIT_R2,JIT_R0);
        jit_movi_l(JIT_V2,n);
        jitc_repeatp(JIT_V2,
                    jitc_pop_stack();
                    jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
                    jit_str_p(JIT_R2,JIT_R0);
                    );
        jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);
      }

      goto next_byte;
    }
    CASE cod_mv_to_stack: {     /* (MV-TO-STACK) */
      jit_insn *rf1, *rf2;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_mv2stackx();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_nv_to_stack: {     /* (NV-TO-STACK n) */
      jit_insn *rf1,*rf2,*rf3,*rf4,*rf5,*rf6,*rf7;
      uintL n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jit_movi_l(JIT_R2,n*sizeof(gcv_object_t));
      jitc_check_stackr();

      jit_movi_l(JIT_V2,n);
      rf1 = jit_beqi_p(jit_forward(),JIT_V2,0);
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jit_subi_p(JIT_V2,JIT_V2,1);
      rf2 = jit_beqi_p(jit_forward(),JIT_V2,0);

      jitc_get_mvcountr();
      jit_movr_p(JIT_V1,JIT_R0);
      rf3 = jit_blei_ui(jit_forward(),JIT_V1,1);
      jit_subi_p(JIT_V1,JIT_V1,1);

      jitc_getptr_valuesi(1);
      jit_movr_p(JIT_R2,JIT_R0);
      rf4 = jit_get_label(); /* Infinite loop */
      jitc_ldpush_stackr();

      jit_addi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
      jit_subi_p(JIT_V2,JIT_V2,1);
      rf5 = jit_beqi_p(jit_forward(),JIT_V2,0);
      jit_subi_p(JIT_V1,JIT_V1,1);
      rf6 = jit_beqi_p(jit_forward(),JIT_V1,0);
      (void)jit_jmpi(rf4);

      jit_patch(rf3); /* nv_to_stack_fill */
      jit_patch(rf6);
      jitc_repeatp(JIT_V2,
                  jitc_push_stacki(as_oint(NIL));
                  );

      jit_patch(rf1); /* nv_to_stack_end */
      jit_patch(rf2);
      jit_patch(rf5);
      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_mv_to_list: {      /* (MV-TO-LIST) */
      jit_insn *rf1;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_mv2stackx();
      jitc_push_stacki(as_oint(NIL));

      jitc_get_mvcountr();
      jit_movr_p(JIT_V2,JIT_R0);
      rf1 = jit_beqi_p(jit_forward(),JIT_V2,0);
      jitc_repeatp(JIT_V2,
                  (void)jit_calli(allocate_cons);
                  jit_retval(JIT_R2);

                  jitc_getptr_fieldr(Cons,cdr);
                  jit_movr_p(JIT_V1,JIT_R0);
                  jitc_pop_stack();
                  jit_str_p(JIT_V1,JIT_R0);
                  jitc_getptr_fieldr(Cons,car);
                  jit_movr_p(JIT_V1,JIT_R0);
                  jitc_get_stacki(0);
                  jit_str_p(JIT_V1,JIT_R0);
                  jitc_getptr_stacki(0);
                  jit_str_p(JIT_R0,JIT_R2);
                  );
      jit_patch(rf1);
      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_list_to_mv: {      /* (LIST-TO-MV) */
      jit_insn *rf1,*rf2,*rf3,*rf4,*rf5;
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_sym_atompr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_set_valuesi_1(as_oint(NIL));
      jit_movi_l(JIT_V2,1);
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1); /* else */

      jitc_getptr_valuesi(0);
      jit_movr_p(JIT_V1,JIT_R0);
      jit_movi_l(JIT_V2,0);
      rf3 = jit_get_label();
      rf4 = jit_bnei_p(jit_forward(), JIT_V2,(mv_limit-1));
      jit_ldxi_p(JIT_R0,JIT_FP,jitc_var_b); /* closureptr */
      jit_ldr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_errori(error_condition,"~S: too many return values");
      jit_patch(rf4);
      jitc_get_fieldr(Cons,car);
      jit_str_p(JIT_V1,JIT_R0);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jit_addi_p(JIT_V1,JIT_V1,sizeof(gcv_object_t));
      jit_addi_p(JIT_V2,JIT_V2,1);
      jitc_sym_conspr();
      jit_beqi_p(rf3, JIT_R0,1);
      jit_patch(rf2);
      rf5 = jit_beqi_p(jit_forward(),JIT_R2,as_oint(NIL));
      jit_prepare(2);
      jit_pusharg_p(JIT_R2);
      jit_movi_l(JIT_R0,as_oint(S(values_list)));
      jit_pusharg_p(JIT_R0);
      jit_finish(error_proper_list_dotted);
      jit_patch(rf5);
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_set_mvcountr();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_mvcallp: {         /* (MVCALLP) */
      jit_ldi_p(JIT_R2,&(STACK));
      jitc_push_spr();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_mvcall: {          /* (MVCALL) */
      jit_insn *ref;

      jitc_pop_sp();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_frame_nextx(JIT_R2);
      jit_ldi_p(JIT_R1,&(STACK));
      jitc_get_scountr(JIT_R2,JIT_R1,JIT_R2);

      ref = jit_blei_ui(jit_forward(),JIT_R2,ca_limit_1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(multiple_value_call)));
      jitc_errori(program_error,"~S: too many arguments given to ~S");
      jit_patch(ref);
      jit_prepare(2);
      jit_pusharg_p(JIT_R2);
      jit_pusharg_p(JIT_R0);
      jit_finish(funcall);

      jitc_skip_stacki(1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    /* ------------------- (10) BLOCK ----------------------- */
    CASE cod_block_open: {      /* (BLOCK-OPEN n label) */
      /* occupies 3 STACK-entries and 1 SP-jmp_buf-entry and 2 SP-entries */
      uintL n;
      sintL label_dist;
      U_operand(n);
      S_operand(label_dist);
      label_dist += byteptr - CODEPTR;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_push_spi(label_dist);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_push_spr();

      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V2);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_V1,JIT_R0);
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,car);
      jit_str_p(JIT_R0,JIT_V1);

      jitc_push_stackr();
      jitc_alloc_jmpbuf();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_finish_eframex(CBLOCK,3,{
          /* Executed if catched a RETURN-FROM */
          jitc_free_jmpbuf();
          jitc_skip_stacki(2);
          jitc_pop_stack();
          jit_movr_p(JIT_R2,JIT_R0);
          jitc_getptr_fieldr(Cons,cdr);
          jit_movi_l(JIT_R1,as_oint(disabled));
          jit_str_p(JIT_R0,JIT_R1);
          jitc_pop_sp();
          jit_movr_p(JIT_V1,JIT_R0);
          jitc_skip_spi(1);
          jitc_bcjmpi(label_dist);
        },{
          jit_movr_p(JIT_R2,JIT_V2);
          jitc_getptr_fieldr(Cons,cdr);
          jit_ldi_p(JIT_R1,&(STACK));
          jit_str_p(JIT_R0,JIT_R1);
        });
      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_block_close: {     /* (BLOCK-CLOSE) */
      /* unwind CBLOCK-Frame: */
      jitc_free_jmpbuf();
      jitc_skip_stacki(2);
      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movi_l(JIT_R1,as_oint(disabled));
      jit_str_p(JIT_R0,JIT_R1);
      jitc_skip_spi(2);

      goto next_byte;
    }
    CASE cod_return_from: {     /* (RETURN-FROM n) */
      jit_insn *ref;
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_get_fieldr(Cons,cdr);
      ref = jit_bnei_p(jit_forward(),JIT_R0,as_oint(disabled));
      jit_prepare(1);
      jitc_get_fieldr(Cons,car);
      jit_pusharg_p(JIT_R0);
      jit_finish(error_block_left);
      jit_patch(ref);
      jit_prepare(1);
      jit_pusharg_p(JIT_R0);
      jit_finish(unwind_upto);

      goto next_byte;
    }
    CASE cod_return_from_i: {   /* (RETURN-FROM-I k1 k2 n) */
      jit_insn* ref;
      uintL k1;
      uintL k2;
      uintL n;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_get_fieldr(Cons,cdr);
      ref = jit_bnei_p(jit_forward(),JIT_R0,as_oint(disabled));
      jit_prepare(1);
      jitc_get_fieldr(Cons,car);
      jit_pusharg_p(JIT_R0);
      jit_finish(error_block_left);
      jit_patch(ref);
      jit_prepare(1);
      jit_pusharg_p(JIT_R0);
      jit_finish(unwind_upto);

      goto next_byte;
    }
    /* ------------------- (11) TAGBODY ----------------------- */
    CASE cod_tagbody_open: {    /* (TAGBODY-OPEN n label1 ... labelm) */
      /* occupies 3+m STACK-Entries and 1 SP-jmp_buf-Entry and 1 SP-Entry */
      uintL n;
      U_operand(n);
      const uintB* old_byteptr = byteptr;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V2);

      object tag_vector = TheCclosure(closure)->clos_consts[n];
      uintL m = Svector_length(tag_vector);
      jitc_check_stacki(m*sizeof(gcv_object_t));

      uintL count;
      dotimespL(count,m, {
          const uintB* label_byteptr;
          L_operand(label_byteptr);
          jitc_push_stacki(as_oint(fixnum(label_byteptr - CODEPTR)));
        });

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_V2);
      jit_movr_p(JIT_V2,JIT_R0);
      jitc_getptr_fieldr(Cons,car);
      jit_str_p(JIT_R0,JIT_V2);
      jit_movr_p(JIT_V2,JIT_R2);

      jit_movr_p(JIT_R2,JIT_V1);
      jitc_push_spr();

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_push_stackr();
      jitc_alloc_jmpbuf();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_finish_eframex(CTAGBODY,3,{
          /* Executed if (GO) is reached */
          jitc_get_valuesr_1(); /* n of label */
          jit_movr_p(JIT_R2,JIT_R0);
          jitc_posfixnum2valr();
          jit_movi_l(JIT_R1,m);
          jit_subr_p(JIT_R0,JIT_R1,JIT_R0);
          jit_addi_p(JIT_R2,JIT_R0,3);
          jitc_get_stackr();
          jit_movr_p(JIT_R2,JIT_R0);
          jitc_posfixnum2valr();
          byteptr = old_byteptr;
          uintL count;
          dotimespL(count,m, {
              jit_insn *rf1;
              const uintB* label_byteptr;
              L_operand(label_byteptr);
              rf1 = jit_bnei_p(jit_forward(),JIT_R0,label_byteptr - CODEPTR);
              jitc_bcjmpi(label_byteptr - CODEPTR);
              jit_patch(rf1);
            });
        },{
          jit_movr_p(JIT_R2,JIT_V2);
          jitc_getptr_fieldr(Cons,cdr);
          jit_ldi_p(JIT_R1,&(STACK));
          jit_str_p(JIT_R0,JIT_R1);
        });

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_tagbody_close_nil: { /* (TAGBODY-CLOSE-NIL) */
      jitc_set_valuesi_1(as_oint(NIL));

      jitc_free_jmpbuf();
      jitc_get_stacki(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movi_l(JIT_R1,as_oint(disabled));
      jit_str_p(JIT_R0,JIT_R1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getlen_svecr();
      jit_addi_p(JIT_R0,JIT_R0,3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_skip_stackr();
      jitc_skip_spi(1);

      goto next_byte;
    }
    CASE cod_tagbody_close: {   /* (TAGBODY-CLOSE) */
      /* unwind CTAGBODY-Frame: */
      jitc_free_jmpbuf();
      jitc_get_stacki(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movi_l(JIT_R1,as_oint(disabled));
      jit_str_p(JIT_R0,JIT_R1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getlen_svecr();
      jit_addi_p(JIT_R0,JIT_R0,3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_skip_stackr();
      jitc_skip_spi(1);

      goto next_byte;
    }
    CASE cod_go: {              /* (GO n l) */
      jit_insn *rf1, *rf2, *rf3;
      uintL n;
      uintL l;
      U_operand(n);
      U_operand(l);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_get_fieldr(Cons,cdr);
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(disabled));
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_get_svecdatair(l);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(go)));
      jitc_errori(control_error,"(~S ~S): the tagbody of the tags ~S has already been left");
      jit_patch(rf1);

      jit_movr_p(JIT_R2,JIT_R0);
      jit_movr_p(JIT_V2,JIT_R0);
      jitc_get_framei(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framecoder();
      rf2 = jit_bnei_p(jit_forward(),JIT_R0,CTAGBODY_frame_info);
      jitc_set_valuesi_1(as_oint(fixnum(1+l)));
      rf3 = jit_jmpi(jit_forward());
      jit_patch(rf2);
      jitc_get_framei(frame_bindings+2*l+1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_patch(rf3);
      jit_prepare(1);
      jit_pusharg_p(JIT_V2);
      jit_finish(unwind_upto);

      goto next_byte;
    }
    CASE cod_go_i: {            /* (GO-I k1 k2 n l) */
      jit_insn* ref;
      uintL k1;
      uintL k2;
      uintL n;
      uintL l;
      U_operand(k1);
      U_operand(k2);
      U_operand(n);
      U_operand(l);

      jitc_get_spi(k1+jmpbufsize*k2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_framei(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_get_fieldr(Cons,cdr);
      ref = jit_bnei_p(jit_forward(),JIT_R0,as_oint(disabled));
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_get_svecdatair(l);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(go)));
      jitc_errori(control_error,"(~S ~S): the tagbody of the tags ~S has already been left");
      jit_patch(ref);

      jitc_set_valuesi_1(as_oint(fixnum(1+l)));

      jit_prepare(1);
      jit_pusharg_p(JIT_R0);
      jit_finish(unwind_upto);

      goto next_byte;
    }
    /* ------------------- (12) CATCH and THROW ----------------------- */
    CASE cod_catch_open: {      /* (CATCH-OPEN label) */
      /* occupies 3 STACK-Entries and 1 SP-jmp_buf-Entry and 2 SP-Entries*/
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_push_spi(label_byteptr - CODEPTR);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_push_spr();

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_alloc_jmpbuf();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_finish_eframex(CATCH,3,{
          /* Executed if (throw) is caught */
          jitc_free_jmpbuf();
          jitc_skip_stacki(3);

          jitc_skip_spi(2);
          jitc_bcjmpi(label_byteptr - CODEPTR);
        },{
        });

      goto next_byte;
    }
    CASE cod_catch_close: {     /* (CATCH-CLOSE) */
      jitc_free_jmpbuf();
      jitc_skip_spi(2);
      jitc_skip_stacki(3);

      goto next_byte;
    }
    CASE cod_throw: {           /* (THROW) */
      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jit_prepare(1);
      jit_pusharg_p(JIT_R2);
      jit_finish(throw_to);

      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(throw)));
      jitc_errori(control_error,"~S: there is no CATCHer for tag ~S");

      goto next_byte;
    }
    /* ------------------- (13) UNWIND-PROTECT ----------------------- */
    CASE cod_uwp_open: {        /* (UNWIND-PROTECT-OPEN label) */
      /* occupies 2 STACK-Entries and 1 SP-jmp_buf-Entry and 2 SP-Entries */
      const uintB* label_byteptr;
      L_operand(label_byteptr);

      jitc_push_spi(label_byteptr - CODEPTR);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_spr();

      jitc_alloc_jmpbuf();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_finish_eframex(UNWIND_PROTECT,2,{
          /* Executed if a (throw) is caught */
          jitc_free_jmpbuf();
          jitc_skip_stacki(2);

          jitc_skip_spi(2);
          jit_ldi_p(JIT_R2,&unwind_protect_to_save.fun);
          jitc_push_spr();
          jit_ldi_p(JIT_R2,&unwind_protect_to_save.upto_frame);
          jitc_push_spr();
          jit_ldi_p(JIT_R2,&STACK);
          jitc_push_spr();

          jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
          jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);
          jitc_mv2stackx();
          jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
          jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

          jitc_bcjmpi(label_byteptr - CODEPTR);
        },{
        });

      goto next_byte;
    }
    CASE cod_uwp_normal_exit: { /* (UNWIND-PROTECT-NORMAL-EXIT) */
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_free_jmpbuf();
      jitc_skip_spi(2);
      jitc_skip_stacki(2);

      jitc_push_spi(NULL);
      jitc_push_spi(NULL);
      jit_ldi_p(JIT_R2,&STACK);
      jitc_push_spr();

      jitc_mv2stackx();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_uwp_close: {       /* (UNWIND-PROTECT-CLOSE) */
      jit_insn *rf1;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_pop_sp(); /* oldSTACK */
      jit_ldi_p(JIT_R1,&STACK);
      jitc_get_scountr(JIT_R2,JIT_R1,JIT_R0);

      rf1 = jit_blti_p(jit_forward(),JIT_R2,mv_limit);
      jit_ldr_p(JIT_R2,JIT_V1);
      jitc_push_stackr();
      jitc_errori(error_condition,"~S: too many return values");
      jit_patch(rf1);
      /* Stack to MV */
      jit_movr_p(JIT_V2,JIT_R2);
      jitc_set_mvcountr();
      jitc_getptr_valuesr_1();
      jit_movi_l(JIT_R1,as_oint(NIL));
      jit_str_p(JIT_R0,JIT_R1);
      rf1 = jit_beqi_p(jit_forward(),JIT_V2,0);
      jitc_getptr_valuesr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_repeatp(JIT_V2,{
          jitc_pop_stack();
          jit_subi_p(JIT_R2,JIT_R2,sizeof(gcv_object_t));
          jit_str_p(JIT_R2,JIT_R0);
        });
      jit_patch(rf1);

      jitc_pop_sp();
      jit_movr_p(JIT_R2,JIT_R0); /* arg */
      jitc_pop_sp(); /* fun */
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,NULL);
      jit_prepare(1);
      jit_pusharg_p(JIT_R2);
      jit_finishr(JIT_R0);
      jitc_notreached();
      jit_patch(rf1);
      rf1 = jit_beqi_p(jit_forward(),JIT_R2,NULL);
      jitc_bcjmpr();
      jit_patch(rf1);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_uwp_cleanup: {     /* (UNWIND-PROTECT-CLEANUP) */
      /* this is executed, if within the same Closure an execution
         of the Cleanup-Code is necessary.
         closure remains, byteptr:=label_byteptr : */
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_spi(jmpbufsize+1);
      jit_stxi_p(jitc_var_c,JIT_FP,JIT_R0);

      jitc_free_jmpbuf();
      jitc_skip_spi(2);
      jitc_skip_stacki(2);

      jitc_push_spi(NULL);
      jitc_push_spi(byteptr - CODEPTR);
      jit_ldi_p(JIT_R2,&(STACK));
      jitc_push_spr();

      jitc_mv2stackx();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jit_ldxi_p(JIT_R2,JIT_FP,jitc_var_c);

      jitc_bcjmpr();

      goto next_byte;
    }
    /* ------------------- (14) HANDLER-BIND ----------------------- */
    CASE cod_handler_open: {    /* (HANDLER-OPEN n) */
      /* occupies 4 STACK-Entries */
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jit_ldr_p(JIT_R2,JIT_V1);
      jitc_push_stackr();
      jitc_getptr_spi(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_finish_framer(HANDLER,4);

      goto next_byte;
    }
    CASE cod_handler_begin_push: { /* (HANDLER-BEGIN&PUSH) */
      jit_insn *rf1;
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jit_ldi_p(JIT_R2,&handler_args.spdepth);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_posfixnum2valr();
      jit_movr_p(JIT_V2,JIT_R0);

      jit_ldi_p(JIT_R2,&handler_args.spdepth);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_posfixnum2valr();
      jit_muli_ul(JIT_R0,JIT_R0,jmpbufsize);
      jit_addr_p(JIT_V2,JIT_V2,JIT_R0);

      rf1 = jit_blei_p(jit_forward(),JIT_V2,0);
      jit_ldi_p(JIT_R2,&handler_args.sp);
      jit_lshi_ul(JIT_R0,JIT_V2,sizeof(SPint*)/2);
      jit_addr_p(JIT_R2,JIT_R2,JIT_R0);

      jitc_repeatp(JIT_V2,
                  jit_addi_p(JIT_R2,JIT_R2,-sizeof(SPint*));
                  jitc_ldpush_spr();
                  );
      jit_patch(rf1);

      jit_ldi_p(JIT_R2,&handler_args.stack);
      jitc_push_spr();
      jit_ldi_p(JIT_R2,&handler_args.condition);
      jitc_set_valuesr_1();
      jitc_push_stackr();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    /* ------------------- (15) a few Functions ----------------------- */
    CASE cod_not: {             /* (NOT) */
      jit_insn *rf1,*rf2;

      jitc_get_valuesr_1();

      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_set_valuesi_1(as_oint(T));
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jitc_set_valuesi_1(as_oint(NIL));
      jit_patch(rf2);

      goto next_byte;
    }
    CASE cod_eq: {              /* (EQ) */
      jit_insn *rf1,*rf2;

      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_valuesr_1();

      rf1 = jit_beqr_p(jit_forward(),JIT_R2,JIT_R0);
      jitc_set_valuesi_1(as_oint(NIL));
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jitc_set_valuesi_1(as_oint(T));
      jit_patch(rf2);

      goto next_byte;
    }
    CASE cod_car: {             /* (CAR) */
      jit_insn *rf1,*rf2,*rf3,*rf4;
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(car)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_car_push: {        /* (CAR&PUSH) */
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_push_stackr();
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(car)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);

      goto next_byte;
    }
    CASE cod_load_car_push: {   /* (LOAD&CAR&PUSH n) */
      uintL n;
      U_operand(n);
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_push_stackr();
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(car)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);

      goto next_byte;
    }
    CASE cod_load_car_store: {  /* (LOAD&CAR&STORE m n) */
      uintL m;
      uintL n;
      U_operand(m);
      U_operand(n);
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_stacki(m);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_set_valuesr_1();
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(car)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_cdr: {             /* (CDR) */
      jit_insn *rf1,*rf2,*rf3,*rf4;
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(cdr)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_cdr_push: {        /* (CDR&PUSH) */
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_push_stackr();
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(cdr)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);

      goto next_byte;
    }
    CASE cod_load_cdr_push: {   /* (LOAD&CDR&PUSH n) */
      uintL n;
      U_operand(n);
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_push_stackr();
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(cdr)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);

      goto next_byte;
    }
    CASE cod_load_cdr_store: {  /* (LOAD&CDR&STORE n) */
      uintL n;
      U_operand(n);
      jit_insn *rf1,*rf2,*rf3,*rf4;

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_sym_conspr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_get_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      rf2 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      rf3 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_set_valuesr_1();
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      rf4 = jit_jmpi(jit_forward());
      jit_patch(rf3);
      jitc_save_backtrace3(as_oint(L(cdr)), STACK, -1, -1,{
          jit_prepare(1);
          jit_pusharg_p(JIT_R2);
          jit_finish(error_list);
        });

      jit_patch(rf2);
      jit_patch(rf4);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_cons: {            /* (CONS) */
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V2);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_cons_push: {       /* (CONS&PUSH) */
      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V2);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_push_stackr();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_cons_store: { /* (LOAD&CONS&STORE n) */
      uintL n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V2);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);

      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_stacki(n);
      jit_str_p(JIT_R2,JIT_R0);

      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_V2);
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_symbol_function: { /* (SYMBOL-FUNCTION) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_check_fdefx();

      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_const_symbol_function: { /* (CONST&SYMBOL-FUNCTION n) */
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_check_fdefx();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_const_symbol_function_push: { /* (CONST&SYMBOL-FUNCTION&PUSH n) */
      uintL n;
      U_operand(n);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_check_fdefx();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_const_symbol_function_store: { /* (CONST&SYMBOL-FUNCTION&STORE n k) */
      uintL n;
      uintL k;
      U_operand(n);
      U_operand(k);

      jitc_get_cconsti(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_check_fdefx();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_getptr_stacki(k);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
      /* object vec;object index; */
    CASE cod_svref: {           /* (SVREF) */
      jit_insn *rf1,*rf2;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_stacki(0);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_svecpr();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,1);
      jit_prepare(2);
      jit_pusharg_p(JIT_R2);
      jit_movi_l(JIT_R0,as_oint(S(svref)));
      jit_pusharg_p(JIT_R0);
      jit_finish(error_no_svector);
      jit_patch(rf1);
      jitc_skip_stacki(1);
      jit_movr_p(JIT_V2,JIT_R2);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_posfixnum2valr();
      jit_movr_p(JIT_R2,JIT_V2);
      jit_movr_p(JIT_V2,JIT_R0);
      jitc_getlen_svecr();
      rf2 = jit_bltr_p(jit_forward(),JIT_V2,JIT_R0);
      jit_patch(rf1);
      /* ERROR */
      jit_movr_p(JIT_V2,JIT_R2);
      jitc_push_stackr();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(integer)));
      jitc_push_stacki(as_oint(Fixnum_0));
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getlen_svecr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_ul2ix();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jit_prepare(1);
      jit_movi_l(JIT_R0,1);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_push_stackr();
      jit_prepare(1);
      jit_movi_l(JIT_R0,3);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_push_stackr();
      jitc_get_stacki(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(svref)));
      jitc_errori(type_error,"~S: ~S is not a correct index into ~S");
      jit_patch(rf2);
      jit_movr_p(JIT_R1,JIT_V2);
      jitc_get_svecdatax();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_svset: {           /* (SVSET) */
      jit_insn *rf1,*rf2;

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);

      jitc_get_stacki(0);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_svecpr();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,1);
      jit_prepare(2);
      jit_pusharg_p(JIT_R2);
      jit_movi_l(JIT_R0,as_oint(S(svref)));
      jit_pusharg_p(JIT_R0);
      jit_finish(error_no_svector);
      jit_patch(rf1);
      jitc_skip_stacki(1);
      jit_movr_p(JIT_V2,JIT_R2);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      jitc_posfixnum2valr();
      jit_movr_p(JIT_R2,JIT_V2);
      jit_movr_p(JIT_V2,JIT_R0);
      jitc_getlen_svecr();
      rf2 = jit_bltr_p(jit_forward(),JIT_V2,JIT_R0);
      jit_patch(rf1);
      /* ERROR */
      jit_movr_p(JIT_V2,JIT_R2);
      jitc_push_stackr();
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(integer)));
      jitc_push_stacki(as_oint(Fixnum_0));
      jit_movr_p(JIT_R2,JIT_V2);
      jitc_getlen_svecr();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_ul2ix();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jit_prepare(1);
      jit_movi_l(JIT_R0,1);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_push_stackr();
      jit_prepare(1);
      jit_movi_l(JIT_R0,3);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_push_stackr();
      jitc_get_stacki(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();
      jitc_push_stackr();
      jitc_push_stacki(as_oint(S(svref)));
      jitc_errori(type_error,"~S: ~S is not a correct index into ~S");
      jit_patch(rf2);
      jit_movr_p(JIT_R1,JIT_V2);
      jitc_getptr_svecdatax();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      goto next_byte;
    }
    CASE cod_list: {            /* (LIST n) */
      uintC n;
      U_operand(n);

      jit_prepare(1);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();

      goto next_byte;
    }
    CASE cod_list_push: {       /* (LIST&PUSH n) */
      uintC n;
      U_operand(n);

      jit_prepare(1);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jit_finish(listof);
      jit_retval(JIT_R2);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_liststar: {        /* (LIST* n) */
      jit_insn* ref;
      uintC n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jit_movi_l(JIT_V2,n);
      ref = jit_get_label();
      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V1);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_getptr_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_stacki(0);
      jit_str_p(JIT_R2,JIT_R0);

      jitc_getptr_stacki(0);
      jit_str_p(JIT_R0,JIT_V1);

      jit_subi_p(JIT_V2,JIT_V2,1);
      jit_bnei_p(ref,JIT_V2,0);

      jitc_pop_stack();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_liststar_push: {   /* (LIST*&PUSH n) */
      jit_insn *ref;
      uintC n;
      U_operand(n);

      jit_stxi_p(jitc_var_a,JIT_FP,JIT_V2);
      jit_stxi_p(jitc_var_b,JIT_FP,JIT_V1);

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jit_movi_l(JIT_V2,n);
      ref = jit_get_label();
      (void)jit_calli(allocate_cons);
      jit_retval(JIT_V1);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_getptr_fieldr(Cons,cdr);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_pop_stack();
      jit_str_p(JIT_R2,JIT_R0);
      jit_movr_p(JIT_R2,JIT_V1);
      jitc_getptr_fieldr(Cons,car);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_get_stacki(0);
      jit_str_p(JIT_R2,JIT_R0);

      jitc_getptr_stacki(0);
      jit_str_p(JIT_R0,JIT_V1);

      jit_subi_p(JIT_V2,JIT_V2,1);
      jit_bnei_p(ref,JIT_V2,0);

      jit_ldxi_p(JIT_V1,JIT_FP,jitc_var_b);
      jit_ldxi_p(JIT_V2,JIT_FP,jitc_var_a);

      jitc_tag_unsafe();
      goto next_byte;
    }
    /* ------------------- (16) combined Operations ----------------------- */
    CASE cod_nil_store: {       /* (NIL&STORE n) */
      uintL n;
      U_operand(n);

      jit_movi_l(JIT_R2,as_oint(NIL));

      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_t_store: {         /* (T&STORE n) */
      uintL n;
      U_operand(n);

      jit_movi_l(JIT_R2,as_oint(T));

      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_calls1_store: {    /* (CALLS1&STORE n k) */
      uintL n;
      uintL k;
      B_operand(n);
      U_operand(k);

      jitc_funcalls1();

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(k);
      jit_str_p(JIT_R0, JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls2_store: {    /* (CALLS2&STORE n k) */
      uintL n;
      uintL k;
      B_operand(n);
      U_operand(k);

      jitc_funcalls2();

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(k);
      jit_str_p(JIT_R0, JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callsr_store: {    /* (CALLSR&STORE m n k) */
      uintL m;
      uintL n;
      uintL k;
      U_operand(m);
      B_operand(n);
      U_operand(k);

      jitc_funcallsr();

      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(k);
      jit_str_p(JIT_R0, JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_inc_push: {   /* (LOAD&INC&PUSH n) */
      jit_insn *rf1,*rf2,*rf3;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      rf2 = jit_beqi_p(jit_forward(), JIT_R2,as_oint(fixnum(vbitm(oint_data_len)-1)));
      jitc_inc_posfixnumir(1);
      rf3 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jit_patch(rf2);
      jitc_push_stackr();
      jitc_save_backtrace1(as_oint(L(plus_one)), STACK, -1,{
          (void)jit_calli(C_plus_one);
        });
      jitc_get_valuesr_1();
      jit_patch(rf3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_inc_store: {  /* (LOAD&INC&STORE n) */
      jit_insn *rf1,*rf2,*rf3;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      rf2 = jit_beqi_p(jit_forward(), JIT_R2,as_oint(fixnum(vbitm(oint_data_len)-1)));
      jitc_inc_posfixnumir(1);
      rf3 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jit_patch(rf2);
      jitc_push_stackr();
      jitc_save_backtrace1(as_oint(L(plus_one)), STACK, -1, {
          (void)jit_calli(C_plus_one);
        });
      jitc_get_valuesr_1();
      jit_patch(rf3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_dec_push: {   /* (LOAD&DEC&PUSH n) */
      jit_insn *rf1,*rf2,*rf3;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      rf2 = jit_beqi_p(jit_forward(), JIT_R2,as_oint(Fixnum_0));
      jitc_inc_posfixnumir(-1);
      rf3 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jit_patch(rf2);
      jitc_push_stackr();
      jitc_save_backtrace1(as_oint(L(minus_one)), STACK, -1, {
          (void)jit_calli(C_minus_one);
        });
      jitc_get_valuesr_1();
      jit_patch(rf3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_dec_store: {  /* (LOAD&DEC&STORE n) */
      jit_insn *rf1,*rf2,*rf3;
      uintL n;
      U_operand(n);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);

      jitc_posfixnumpr();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,1);
      rf2 = jit_beqi_p(jit_forward(), JIT_R2,as_oint(Fixnum_0));
      jitc_inc_posfixnumir(-1);
      rf3 = jit_jmpi(jit_forward());
      jit_patch(rf1);
      jit_patch(rf2);
      jitc_push_stackr();
      jitc_save_backtrace1(as_oint(L(minus_one)), STACK, -1, {
          (void)jit_calli(C_minus_one);
        });
      jitc_get_valuesr_1();
      jit_patch(rf3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(n);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_valuesr_1();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call1_jmpif: {     /* (CALL1&JMPIF n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_funcall1();
      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call1_jmpifnot: {  /* (CALL1&JMPIFNOT n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_funcall1();
      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call2_jmpif: {     /* (CALL2&JMPIF n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_funcall2();
      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_call2_jmpifnot: {  /* (CALL2&JMPIFNOT n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_funcall2();
      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls1_jmpif: {    /* (CALLS1&JMPIF n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcalls1();

      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls1_jmpifnot: { /* (CALLS1&JMPIFNOT n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcalls1();

      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls2_jmpif: {    /* (CALLS2&JMPIF n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcalls2();

      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_calls2_jmpifnot: { /* (CALLS2&JMPIFNOT n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL n;
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcalls2();

      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callsr_jmpif: {    /* (CALLSR&JMPIF m n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL m;
      uintL n;
      U_operand(m);
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcallsr();

      jitc_get_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_callsr_jmpifnot: { /* (CALLSR&JMPIFNOT m n label) */
      const uintB* label_byteptr;
      jit_insn *rf1;
      uintL m;
      uintL n;
      U_operand(m);
      B_operand(n);
      L_operand(label_byteptr);

      jitc_funcallsr();

      jitc_get_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R0,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_load_jmpif: {      /* (LOAD&JMPIF n label) */
      jit_insn *rf1;
      uintL n;
      const uintB* label_byteptr;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      rf1 = jit_beqi_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_load_jmpifnot: {   /* (LOAD&JMPIFNOT n label) */
      jit_insn *rf1;
      uintL n;
      const uintB* label_byteptr;
      U_operand(n);
      L_operand(label_byteptr);

      jitc_get_stacki(n);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();
      rf1 = jit_bnei_p(jit_forward(),JIT_R2,as_oint(NIL));
      jitc_bcjmpi(label_byteptr - CODEPTR);
      jit_patch(rf1);

      goto next_byte;
    }
    CASE cod_apply_skip_ret: {  /* (APPLY&SKIP&RET n k) */
      uintL n;
      uintL k;
      U_operand(n);
      U_operand(k);

      jit_prepare(3);
      jitc_get_valuesr_1();
      jit_pusharg_p(JIT_R0);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(apply);
      jitc_skip_stacki(k+1);
      jitc_return();

      jitc_tag_unsafe();
      goto next_byte;
    }
    CASE cod_funcall_skip_retgf: { /* (FUNCALL&SKIP&RETGF n k) */
      uintL n;
      uintL k;
      U_operand(n);
      U_operand(k);
      uintL r = ((Codevec)codeptr)->ccv_numreq;
      uintB flags = ((Codevec)codeptr)->ccv_flags;

      jit_prepare(2);
      jit_movi_l(JIT_R0,n);
      jit_pusharg_p(JIT_R0);
      jitc_get_stacki(n);
      jit_pusharg_p(JIT_R0);
      jit_finish(funcall);
      if (flags & bit(3)) { /* call inhibition? */
        jitc_skip_stacki(k+1);
        jitc_set_mvcounti(1);
      } else {
        k -= r;
        if (flags & bit(0)) {
          jitc_skip_stacki(k);
          jit_prepare(3);
          jitc_pop_stack();
          jit_pusharg_p(JIT_R0);
          jit_movi_l(JIT_R0,r);
          jit_pusharg_p(JIT_R0);
          jitc_get_valuesr_1();
          jit_pusharg_p(JIT_R0);
          jit_finish(apply);
        } else {
          jitc_skip_stacki(k+1);
          jit_prepare(2);
          jit_movi_l(JIT_R0,r);
          jit_pusharg_p(JIT_R0);
          jitc_get_valuesr_1();
          jit_pusharg_p(JIT_R0);
          jit_finish(funcall);
        }
      }
      jitc_return();

      jitc_tag_unsafe();
      goto next_byte;
    }
    /* ------------------- (17) short codes ----------------------- */
    CASE cod_load0: {           /* (LOAD.S 0) */
      jitc_get_stacki(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load1: {           /* (LOAD.S 1) */
      jitc_get_stacki(1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load2: {           /* (LOAD.S 2) */
      jitc_get_stacki(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load3: {           /* (LOAD.S 3) */
      jitc_get_stacki(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load4: {           /* (LOAD.S 4) */
      jitc_get_stacki(4);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load5: {           /* (LOAD.S 5) */
      jitc_get_stacki(5);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load6: {           /* (LOAD.S 6) */
      jitc_get_stacki(6);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load7: {           /* (LOAD.S 7) */
      jitc_get_stacki(7);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load8: {           /* (LOAD.S 8) */
      jitc_get_stacki(8);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load9: {           /* (LOAD.S 9) */
      jitc_get_stacki(9);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load10: {          /* (LOAD.S 10) */
      jitc_get_stacki(10);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load11: {          /* (LOAD.S 11) */
      jitc_get_stacki(11);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load12: {          /* (LOAD.S 12) */
      jitc_get_stacki(12);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load13: {          /* (LOAD.S 13) */
      jitc_get_stacki(13);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load14: {          /* (LOAD.S 14) */
      jitc_get_stacki(14);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_load_push0: {      /* (LOAD&PUSH.S 0) */
      jitc_get_stacki(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push1: {      /* (LOAD&PUSH.S 1) */
      jitc_get_stacki(1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push2: {      /* (LOAD&PUSH.S 2) */
      jitc_get_stacki(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push3: {      /* (LOAD&PUSH.S 3) */
      jitc_get_stacki(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push4: {      /* (LOAD&PUSH.S 4) */
      jitc_get_stacki(4);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push5: {      /* (LOAD&PUSH.S 5) */
      jitc_get_stacki(5);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push6: {      /* (LOAD&PUSH.S 6) */
      jitc_get_stacki(6);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push7: {      /* (LOAD&PUSH.S 7) */
      jitc_get_stacki(7);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push8: {      /* (LOAD&PUSH.S 8) */
      jitc_get_stacki(8);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push9: {      /* (LOAD&PUSH.S 9) */
      jitc_get_stacki(9);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push10: {     /* (LOAD&PUSH.S 10) */
      jitc_get_stacki(10);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push11: {     /* (LOAD&PUSH.S 11) */
      jitc_get_stacki(11);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push12: {     /* (LOAD&PUSH.S 12) */
      jitc_get_stacki(12);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push13: {     /* (LOAD&PUSH.S 13) */
      jitc_get_stacki(13);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push14: {     /* (LOAD&PUSH.S 14) */
      jitc_get_stacki(14);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push15: {     /* (LOAD&PUSH.S 15) */
      jitc_get_stacki(15);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push16: {     /* (LOAD&PUSH.S 16) */
      jitc_get_stacki(16);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push17: {     /* (LOAD&PUSH.S 17) */
      jitc_get_stacki(17);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push18: {     /* (LOAD&PUSH.S 18) */
      jitc_get_stacki(18);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push19: {     /* (LOAD&PUSH.S 19) */
      jitc_get_stacki(19);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push20: {     /* (LOAD&PUSH.S 20) */
      jitc_get_stacki(20);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push21: {     /* (LOAD&PUSH.S 21) */
      jitc_get_stacki(21);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push22: {     /* (LOAD&PUSH.S 22) */
      jitc_get_stacki(22);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push23: {     /* (LOAD&PUSH.S 23) */
      jitc_get_stacki(23);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_load_push24: {     /* (LOAD&PUSH.S 24) */
      jitc_get_stacki(24);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const0: {          /* (CONST.S 0) */
      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const1: {          /* (CONST.S 1) */
      jitc_get_cconsti(1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const2: {          /* (CONST.S 2) */
      jitc_get_cconsti(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const3: {          /* (CONST.S 3) */
      jitc_get_cconsti(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const4: {          /* (CONST.S 4) */
      jitc_get_cconsti(4);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const5: {          /* (CONST.S 5) */
      jitc_get_cconsti(5);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const6: {          /* (CONST.S 6) */
      jitc_get_cconsti(6);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const7: {          /* (CONST.S 7) */
      jitc_get_cconsti(7);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const8: {          /* (CONST.S 8) */
      jitc_get_cconsti(8);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const9: {          /* (CONST.S 9) */
      jitc_get_cconsti(9);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const10: {         /* (CONST.S 10) */
      jitc_get_cconsti(10);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const11: {         /* (CONST.S 11) */
      jitc_get_cconsti(11);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const12: {         /* (CONST.S 12) */
      jitc_get_cconsti(12);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const13: {         /* (CONST.S 13) */
      jitc_get_cconsti(13);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const14: {         /* (CONST.S 14) */
      jitc_get_cconsti(14);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const15: {         /* (CONST.S 15) */
      jitc_get_cconsti(15);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const16: {         /* (CONST.S 16) */
      jitc_get_cconsti(16);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const17: {         /* (CONST.S 17) */
      jitc_get_cconsti(17);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const18: {         /* (CONST.S 18) */
      jitc_get_cconsti(18);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const19: {         /* (CONST.S 19) */
      jitc_get_cconsti(19);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const20: {         /* (CONST.S 20) */
      jitc_get_cconsti(20);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_set_valuesr_1();

      goto next_byte;
    }
    CASE cod_const_push0: {     /* (CONST&PUSH.S 0) */
      jitc_get_cconsti(0);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push1: {     /* (CONST&PUSH.S 1) */
      jitc_get_cconsti(1);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push2: {     /* (CONST&PUSH.S 2) */
      jitc_get_cconsti(2);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push3: {     /* (CONST&PUSH.S 3) */
      jitc_get_cconsti(3);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push4: {     /* (CONST&PUSH.S 4) */
      jitc_get_cconsti(4);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push5: {     /* (CONST&PUSH.S 5) */
      jitc_get_cconsti(5);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push6: {     /* (CONST&PUSH.S 6) */
      jitc_get_cconsti(6);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push7: {     /* (CONST&PUSH.S 7) */
      jitc_get_cconsti(7);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push8: {     /* (CONST&PUSH.S 8) */
      jitc_get_cconsti(8);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push9: {     /* (CONST&PUSH.S 9) */
      jitc_get_cconsti(9);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push10: {    /* (CONST&PUSH.S 10) */
      jitc_get_cconsti(10);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push11: {    /* (CONST&PUSH.S 11) */
      jitc_get_cconsti(11);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push12: {    /* (CONST&PUSH.S 12) */
      jitc_get_cconsti(12);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push13: {    /* (CONST&PUSH.S 13) */
      jitc_get_cconsti(13);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push14: {    /* (CONST&PUSH.S 14) */
      jitc_get_cconsti(14);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push15: {    /* (CONST&PUSH.S 15) */
      jitc_get_cconsti(15);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push16: {    /* (CONST&PUSH.S 16) */
      jitc_get_cconsti(16);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push17: {    /* (CONST&PUSH.S 17) */
      jitc_get_cconsti(17);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push18: {    /* (CONST&PUSH.S 18) */
      jitc_get_cconsti(18);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push19: {    /* (CONST&PUSH.S 19) */
      jitc_get_cconsti(19);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push20: {    /* (CONST&PUSH.S 20) */
      jitc_get_cconsti(20);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push21: {    /* (CONST&PUSH.S 21) */
      jitc_get_cconsti(21);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push22: {    /* (CONST&PUSH.S 22) */
      jitc_get_cconsti(22);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push23: {    /* (CONST&PUSH.S 23) */
      jitc_get_cconsti(23);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push24: {    /* (CONST&PUSH.S 24) */
      jitc_get_cconsti(24);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push25: {    /* (CONST&PUSH.S 25) */
      jitc_get_cconsti(25);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push26: {    /* (CONST&PUSH.S 26) */
      jitc_get_cconsti(26);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push27: {    /* (CONST&PUSH.S 27) */
      jitc_get_cconsti(27);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push28: {    /* (CONST&PUSH.S 28) */
      jitc_get_cconsti(28);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_const_push29: {    /* (CONST&PUSH.S 29) */
      jitc_get_cconsti(29);
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_push_stackr();

      goto next_byte;
    }
    CASE cod_store0: {          /* (STORE.S 0) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(0);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store1: {          /* (STORE.S 1) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(1);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store2: {          /* (STORE.S 2) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(2);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store3: {          /* (STORE.S 3) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(3);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store4: {          /* (STORE.S 4) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(4);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store5: {          /* (STORE.S 5) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(5);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store6: {          /* (STORE.S 6) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(6);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    CASE cod_store7: {          /* (STORE.S 7) */
      jitc_get_valuesr_1();
      jit_movr_p(JIT_R2,JIT_R0);
      jitc_getptr_stacki(7);
      jit_str_p(JIT_R0,JIT_R2);
      jitc_set_mvcounti(1);

      goto next_byte;
    }
    /* ------------------- miscellaneous ----------------------- */
    default:
      /* undefined Code */
  #if defined(GNU) && defined(FAST_SP)
      /* Undo the effect of -fomit-frame-pointer for this function,
         hereby allowing utilization of %sp resp. %esp as private_SP: */
      alloca(1);
  #endif
      pushSTACK(fixnum(byteptr-&codeptr->data[0]-1)); /* bad byte number */
      pushSTACK(closure); /* Closure */
      error(serious_condition,GETTEXT("undefined bytecode in ~S at byte ~S"));
  #undef L_operand
  #undef S_operand
  #undef U_operand
  #undef B_operand
  #undef CASE
  }
#if DEBUG_BYTECODE
 error_byteptr:
  pushSTACK(fixnum(byteptr_max));
  pushSTACK(fixnum(byteptr_min));
  pushSTACK(fixnum(byteptr - codeptr->data));
  pushSTACK(sfixnum(byteptr_bad_jump));
  pushSTACK(closure);
  error(error_condition,GETTEXT("~S: jump by ~S takes ~S outside [~S;~S]"));
#endif
 error_toomany_values:
  pushSTACK(closure);
  error(error_condition,GETTEXT("~S: too many return values"));
#if STACKCHECKC
 error_STACK_putt:
  pushSTACK(fixnum(byteptr - codeptr->data - byteptr_min)); /* PC */
  pushSTACK(closure);                       /* FUNC */
  error(serious_condition,GETTEXT("Corrupted STACK in ~S at byte ~S"));
#endif
 finished:
  /* disassemble(stderr, codeBuffer, jit_get_ip().ptr); */
  jit_flush_code(codeBuffer, jit_get_ip().ptr);
  return;
}

/* ensure that the function has been jit-compiled and run it */
static Values jitc_run (object closure_in, Sbvector codeptr,
                        const uintB* byteptr_in) {
  struct jitc_object *jo;
  if (!fpointerp(cclosure_jitc(closure_in))) {
    pushSTACK(closure_in);
    { object fp = allocate_fpointer(NULL);
      closure_in = popSTACK();
      cclosure_jitc(closure_in) = fp; }
    jit_compile_(closure_in,codeptr,byteptr_in);
  }
  jo = TheFpointer(cclosure_jitc(closure_in))->fp_pointer;
  { jitc_func bc_func = (jitc_func) (jit_set_ip(jo->code_buffer).iptr);
    bc_func(closure, byteptr_in - CODEPTR); }
}
