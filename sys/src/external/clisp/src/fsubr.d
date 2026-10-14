/* List of all FSUBRs
 * Bruno Haible 1990-2000
 * Sam Steingold 2001-2007


 A Special form defined by a declaration:
   LISPSPECFORM(name,req_count,opt_count,body_flag)
 in this file.
 The same declaration (+ implementation) should be in control.d.

 name - the function name (a C identifier)
 req_count - the number of required parameters
 opt_count - the number of optional parameters
 body_flag - either nobody or body

 Expander for the extern declaration: */
#define LISPSPECFORM_A(name,req_count,opt_count,body_flag)      \
    extern fsubr_function_t C_##name;

/* Expander for the declaration of the C function: */
#define LISPSPECFORM_B(name,req_count,opt_count,body_flag)      \
    global Values C_##name (void)

/* Expander for the declaration of the FSUBR table: */
#define LISPSPECFORM_C(name,req_count,opt_count,body_flag)      \
    fsubr_t D_##name;

/* Expander for the initialization of the FSUBR table: */
#define LISPSPECFORM_D(name,req_count,opt_count,body_flag)      \
    &C_##name,

/* Expander for the initialization of the FSUBR symbol: */
#define LISPSPECFORM_E(name,req_count,opt_count,body_flag)      \
    { offsetof(struct symbol_tab_,S_##name), \
      req_count,                  \
      opt_count,                  \
      (uintW)fsubr_##body_flag, \
    },
#define LISPSPECFORM_F(name,req_count,opt_count,body_flag)      \
    { S(name),                  \
      req_count,                  \
      opt_count,                  \
      (uintW)fsubr_##body_flag, \
    },

/* Which expander is used, must be configured by the main file.
 Default is   #define LISPSPECFORM LISPSPECFORM_B */

/* ---------- CONTROL ---------- */
LISPSPECFORM(eval_when, 1,0,body)
LISPSPECFORM(quote, 1,0,nobody)
LISPSPECFORM(function, 1,1,nobody)
LISPSPECFORM(setq, 0,0,body)
LISPSPECFORM(psetq, 0,0,body)
LISPSPECFORM(progn, 0,0,body)
LISPSPECFORM(prog1, 1,0,body)
LISPSPECFORM(prog2, 2,0,body)
LISPSPECFORM(let, 1,0,body)
LISPSPECFORM(letstar, 1,0,body)
LISPSPECFORM(locally, 0,0,body)
LISPSPECFORM(compiler_let, 1,0,body)
LISPSPECFORM(progv, 2,0,body)
LISPSPECFORM(flet, 1,0,body)
LISPSPECFORM(labels, 1,0,body)
LISPSPECFORM(macrolet, 1,0,body)
LISPSPECFORM(function_macro_let, 1,0,body)
LISPSPECFORM(symbol_macrolet, 1,0,body)
LISPSPECFORM(if, 2,1,nobody)
LISPSPECFORM(when, 1,0,body)
LISPSPECFORM(unless, 1,0,body)
LISPSPECFORM(cond, 0,0,body)
LISPSPECFORM(case, 1,0,body)
LISPSPECFORM(block, 1,0,body)
LISPSPECFORM(return_from, 1,1,nobody)
LISPSPECFORM(tagbody, 0,0,body)
LISPSPECFORM(go, 1,0,nobody)
LISPSPECFORM(multiple_value_list, 1,0,nobody)
LISPSPECFORM(multiple_value_call, 1,0,body)
LISPSPECFORM(multiple_value_prog1, 1,0,body)
LISPSPECFORM(multiple_value_bind, 2,0,body)
LISPSPECFORM(multiple_value_setq, 2,0,nobody)
LISPSPECFORM(catch, 1,0,body)
LISPSPECFORM(unwind_protect, 1,0,body)
LISPSPECFORM(throw, 2,0,nobody)
LISPSPECFORM(declare, 0,0,body)
LISPSPECFORM(the, 2,0,nobody)
LISPSPECFORM(load_time_value, 1,1,nobody)
LISPSPECFORM(and, 0,0,body)
LISPSPECFORM(or, 0,0,body)
/* more FSUBRs are in INIT.LSP (%EXPAND-...) and in the Compiler (c-form)! */
