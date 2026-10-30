/*
 * cppclisp-probe.c -- clisp's `GEN_F_op2' VERBATIM, with everything it
 * calls stubbed. The question is whether `CONCAT(TO_F_,r)' expands.
 *
 *	pcc -E cppclisp-probe.c >/tmp/cppclisp.i
 *	grep -n 'CONCAT\|TO_F_' /tmp/cppclisp.i
 *
 * and then, as the sharper form of the same question,
 *
 *	pcc -c cppclisp-probe.c
 *
 * since every pasted name below is DEFINED, so a lost paste is a hard
 * `name not declared: TO_F_' exactly as `flo_rest.d:338' gives.
 *
 * ***A PROBE, AND IT IS A REDUCTION DOWNWARD RATHER THAN UPWARD.***
 * `cppaste-probe' built seven cases upward from a guess about which
 * construct mattered and ALL SEVEN PASSED, which refuted the family
 * without naming the fault; `cpplimit-probe' then refuted a token
 * limit, a length limit, and two-CONCATs-per-expansion. *Three probes
 * built from guesses, three negative results.* So this file does the
 * other thing: `GEN_F_op2' (flo_rest.d:130-292), `floatcase' (the
 * non-TYPECODES arm, 18-26), `GEN_LF_op2_0/_1' (295-317), `LFlen0/1'
 * (322-323) and `TO_F_0/1/2' (325-332) are copied CHARACTER FOR
 * CHARACTER out of the tree, and only the leaves -- the stack, the
 * conversions, the ops -- are stubbed. *The rule this tree already
 * carries about replicating the code in front of you rather than the
 * code you remember, applied to a preprocessor bug.*
 *
 * ***IT REPRODUCED, AND THE ANSWER CAME OUT OF A BETTER INSTRUMENT
 * THAN THIS ONE.*** `sys/lib/tests/cpp-xcheck/' builds kencc's OWN cpp
 * with gcc on the build host -- eleven Plan 9-isms, about sixty lines
 * of shim -- so this file was preprocessed by the real `cpp' locally:
 * **2 unexpanded CONCAT where gcc has 0**, and then the real
 * `lisparit.c', generated on the host with clisp's own
 * `comment5|gctrigger|varbrace' and APExp's own headers, gave **12,
 * which is what the VM's `lisparit.i' had shown to the digit.**
 *
 * **AND THE SITES ARE NOT WHERE THESE NOTES SAID.** The failures are
 * `flo_rest.d:303' and `:310', inside `GEN_LF_op2_0', twice per `s=0'
 * call site -- six call sites, twelve failures. The earlier reading
 * keyed them to 164/202/240/254/266/278 and built a correlation about
 * `CONCAT(LFlen,s)' preceding `CONCAT(TO_F_,r)' in the same arm;
 * **there is no such correlation.** The residue was identified from
 * its text, `CONCAT(TO_F_,1) (LF_op(...),LF_shorten_LF...)', and
 * `LF_shorten_LF_1'/`_2' appear at 303 and 310 and nowhere else --
 * *the line numbers were assigned from the shape of the arm instead of
 * from the only part of the text that names a line.* Twelve was
 * already in these notes and six pairs cannot make twelve.
 *
 * **THE CAUSE IS THE HIDESET, AND IT IS HALF THE ALGORITHM MISSING.**
 * `GEN_LF_op2_0' is reached through `CONCAT(GEN_LF_op2_,s)' at
 * `flo_rest.d:289', so its NAME is a token manufactured by `##' and
 * carries the hideset of the paste that built it. `expand()' painted
 * every name in the expansion with `HS(name) | {macro}', so `CONCAT'
 * -- which built the name -- was hidden inside the body for good.
 * Prosser's algorithm, which this cpp otherwise implements, specifies
 * `(HS(name) & HS(')')) | {macro}' for a CALL, and the `)' comes from
 * the calling macro's own body and was never part of `CONCAT's
 * expansion, so the intersection drops it. The instrumented cpp
 * printed the set: `expand INNER_0: callsite hs=CONCAT_ CONCAT OUTER'.
 * Fixed in `cpp/macro.c' and `cpp/hideset.c'; the five-line form is
 * `V1'/`V2' in `cpp-xcheck/hideset-cases.c'.
 *
 * This file stays as a REGRESSION case, since it is the real macro
 * text rather than a reduction, and `pcc -E' on it must now contain no
 * `CONCAT'.
 *
 * WHAT EACH ANSWER MEANT, WHEN IT WAS STILL A QUESTION:
 *
 *   it reproduces     the fault is in these macros and nothing else,
 *                     and the next step is to bisect by DELETING arms
 *                     from the copy until it stops reproducing. That
 *                     is cheap here and impossible in clisp.
 *   it does not       the fault needs something from clisp's own
 *                     headers -- `lispbibl.d' is 50k lines and defines
 *                     CONCAT itself at :949 -- and *that is a lead
 *                     rather than a dead end*, because it says the
 *                     construct is innocent and the CONTEXT is not.
 *
 * **gcc is the control and must expand all of it**, both arms:
 *
 *	gcc -E cppclisp-probe.c | grep -c 'CONCAT'	-> 0
 *	gcc -c cppclisp-probe.c				-> clean
 *
 * THE SITES THAT FAIL IN CLISP, so that a `grep' on the output can be
 * read against them. `lisparit.c' uses CONCAT 76 times and 70 expand;
 * the six that do not are the `CONCAT(TO_F_,r)' at flo_rest.d 164,
 * 202, 240, 254, 266 and 278, and each of those six is **preceded in
 * the same `floatcase' arm by a `CONCAT(LFlen,s)'** at 162, 200, 238,
 * 252, 264 and 276. Every `CONCAT(TO_F_,r)' with no `CONCAT(LFlen,s)'
 * before it -- 141, 152, 177, 190, 215, 226, and 303/310 inside
 * `GEN_LF_op2_0' -- expands. *That is six pairs and six failures, which
 * is the only correlation in this bug that has survived being checked.*
 *
 * **BOTH PASTED NAMES ARE FUNCTION-LIKE MACROS THAT ARE THEN CALLED**,
 * which is the structural feature `cppaste-probe' never had: `LFlen0'
 * takes `(arg2)' and `TO_F_1' takes `(erg,to)', so each paste produces
 * a macro NAME which the following `(' then invokes. The failing site
 * is always the SECOND such paste in its arm. *Recorded as the shape,
 * not asserted as the mechanism* -- series C of `cpplimit-probe' put
 * two plain CONCATs in one expansion and both expanded, so if this
 * file reproduces, the difference between it and series C is where to
 * look.
 */

/* ---- the leaves, stubbed. Nothing below here is clisp's. ---- */

typedef long object;
typedef unsigned int uintC;
typedef int signean;

#define var
#define local static
#define maygc
#define _EMA_

#define LF_minlen 2

extern object stack[64];
extern int sp;
#define pushSTACK(x)  (stack[sp++] = (object)(x))
#define popSTACK()    (stack[--sp])
#define STACK_0       stack[sp-1]
#define STACK_1       stack[sp-2]

extern int number_immediatep (object);
extern int Record_type (object);
#define Rectype_Dfloat 7
#define nullpSv(name)  (0)
#define warn_on_floating_point_contagion 0
#define floating_point_contagion_ansi 0
extern void warn_floating_point_contagion (void);

extern object SF_to_FF (object);
extern object SF_to_DF (object);
extern object SF_to_LF (object, uintC);
extern object FF_to_DF (object);
extern object FF_to_LF (object, uintC);
extern object DF_to_LF (object, uintC);
extern object FF_to_SF (object);
extern object DF_to_SF (object);
extern object DF_to_FF (object);
extern object LF_to_SF (object);
extern object LF_to_FF (object);
extern object LF_to_DF (object);
extern uintC Lfloat_length (object);
extern object LF_extend_LF (object, uintC);
extern object LF_shorten_LF (object, uintC);

extern object SF_SF_plus_SF (object, object);
extern object FF_FF_plus_FF (object, object);
extern object DF_DF_plus_DF (object, object);
extern object LF_LF_plus_LF (object, object);
extern signean SF_SF_comp (object, object);
extern signean FF_FF_comp (object, object);
extern signean DF_DF_comp (object, object);
extern signean LF_LF_comp (object, object);

/* ---- lispbibl.d:949,955 verbatim ---- */

#define CONCAT_(xxx,yyy)  xxx##yyy
#define CONCAT(xxx,yyy)  CONCAT_(xxx,yyy)

/* ---- flo_rest.d:18-26 verbatim (the non-TYPECODES arm) ---- */

  #define floatcase(obj,SF_statement,FF_statement,DF_statement,LF_statement) \
    do {                                                                     \
      if (number_immediatep(obj)) { SF_statement; }                          \
      else {                                                                 \
        if (Record_type(obj) > Rectype_Dfloat) { FF_statement; }             \
        else if (Record_type(obj) == Rectype_Dfloat) { DF_statement; }       \
        else { LF_statement; }                                               \
      }                                                                      \
    } while(0)

/* ---- flo_rest.d:130-292 verbatim ---- */

#define GEN_F_op2(arg1,arg2,SF_op,FF_op,DF_op,LF_op,r,s,RETURN)    {    \
  floatcase(arg1,/* arg1 SF */ {                                        \
    floatcase(arg2, { /* arg2 SF */                                     \
      RETURN SF_op(arg1,arg2);                                          \
    }, { /* arg2 FF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
      }                                                                 \
      arg1 = SF_to_FF(arg1); arg2 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (FF_op(arg1,arg2),FF_to_SF);             \
      } else {                                                          \
        RETURN FF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 DF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
      }                                                                 \
      arg1 = SF_to_DF(arg1); arg2 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (DF_op(arg1,arg2),DF_to_SF);             \
      } else {                                                          \
        RETURN DF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 LF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
        if (s==0) { arg2 = STACK_0; }                                   \
      }                                                                 \
      arg1 = SF_to_LF(arg1,CONCAT(LFlen,s)(arg2)); arg2 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_SF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    });                                                                 \
  }, { /* arg1 FF */                                                    \
    floatcase(arg2, { /* arg2 SF */                                     \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
      }                                                                 \
      arg2 = SF_to_FF(arg2); arg1 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (FF_op(arg1,arg2),FF_to_SF);             \
      } else {                                                          \
        RETURN FF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 FF */                                                  \
      RETURN FF_op(arg1,arg2);                                          \
    }, { /* arg2 DF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
      }                                                                 \
      arg1 = FF_to_DF(arg1); arg2 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (DF_op(arg1,arg2),DF_to_FF);             \
      } else {                                                          \
        RETURN DF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 LF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
        if (s==0) { arg2 = STACK_0; }                                   \
      }                                                                 \
      arg1 = FF_to_LF(arg1,CONCAT(LFlen,s)(arg2)); arg2 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_FF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    });                                                                 \
  }, { /* arg1 DF */                                                    \
    floatcase(arg2, { /* arg2 SF */                                     \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
      }                                                                 \
      arg2 = SF_to_DF(arg2); arg1 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (DF_op(arg1,arg2),DF_to_SF);             \
      } else {                                                          \
        RETURN DF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 FF */                                                  \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
      }                                                                 \
      arg2 = FF_to_DF(arg2); arg1 = popSTACK();                         \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (DF_op(arg1,arg2),DF_to_FF);             \
      } else {                                                          \
        RETURN DF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 DF */                                                  \
      RETURN DF_op(arg1,arg2);                                          \
    }, { /* arg2 LF */                                                  \
      pushSTACK(arg2);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg1); warn_floating_point_contagion(); arg1 = popSTACK(); \
        if (s==0) { arg2 = STACK_0; }                                   \
      }                                                                 \
      arg1 = DF_to_LF(arg1,CONCAT(LFlen,s)(arg2)); arg2 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_DF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    });                                                                 \
  }, { /* arg1 LF */                                                    \
    floatcase(arg2, { /* arg2 SF */                                     \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
        if (s==0) { arg1 = STACK_0; }                                   \
      }                                                                 \
      arg2 = SF_to_LF(arg2,CONCAT(LFlen,s)(arg1)); arg1 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_SF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 FF */                                                  \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
        if (s==0) { arg1 = STACK_0; }                                   \
      }                                                                 \
      arg2 = FF_to_LF(arg2,CONCAT(LFlen,s)(arg1)); arg1 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_FF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 DF */                                                  \
      pushSTACK(arg1);                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion)) {          \
        pushSTACK(arg2); warn_floating_point_contagion(); arg2 = popSTACK(); \
        if (s==0) { arg1 = STACK_0; }                                   \
      }                                                                 \
      arg2 = DF_to_LF(arg2,CONCAT(LFlen,s)(arg1)); arg1 = popSTACK();   \
      if (nullpSv(floating_point_contagion_ansi)) {                     \
        RETURN CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_to_DF);             \
      } else {                                                          \
        RETURN LF_op(arg1,arg2);                                        \
      }                                                                 \
    }, { /* arg2 LF */                                                  \
      if (r>0 && !nullpSv(warn_on_floating_point_contagion))            \
        if (Lfloat_length(arg1) != Lfloat_length(arg2)) {               \
          pushSTACK(arg1); pushSTACK(arg2);                             \
          warn_floating_point_contagion();                              \
          arg2 = popSTACK(); arg1 = popSTACK();                         \
        }                                                               \
      CONCAT(GEN_LF_op2_,s)(arg1,arg2,LF_op,r,_EMA_ RETURN);            \
    });                                                                 \
  });                                                                   \
}

/* ---- flo_rest.d:295-332 verbatim ---- */

#define GEN_LF_op2_0(arg1,arg2,LF_op,r,result_assignment)     {         \
  var uintC len1 = Lfloat_length(arg1);                                 \
  var uintC len2 = Lfloat_length(arg2);                                 \
  if (len1==len2) { /* equal -> execute directly */                     \
    result_assignment LF_op(arg1,arg2);                                 \
  } else if (len1>len2) { /* -> bring arg2 to the length of arg1 */     \
    pushSTACK(arg1); arg2 = LF_extend_LF(arg2,len1); arg1 = popSTACK(); \
    if (nullpSv(floating_point_contagion_ansi)) {                       \
      result_assignment CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_shorten_LF_2); \
    } else {                                                            \
      result_assignment LF_op(arg1,arg2);                               \
    }                                                                   \
  } else { /* (len1<len2) -> bring arg1 to the length of arg2 */        \
    pushSTACK(arg2); arg1 = LF_extend_LF(arg1,len2); arg2 = popSTACK(); \
    if (nullpSv(floating_point_contagion_ansi)) {                       \
      result_assignment CONCAT(TO_F_,r) (LF_op(arg1,arg2),LF_shorten_LF_1); \
    } else {                                                            \
      result_assignment LF_op(arg1,arg2);                               \
    }                                                                   \
  }                                                                     \
 }
#define GEN_LF_op2_1(arg1,arg2,LF_op,r,result_assignment)       \
     result_assignment LF_op(arg1,arg2);
#define LF_shorten_LF_1(arg)  LF_shorten_LF(arg,len1)
#define LF_shorten_LF_2(arg)  LF_shorten_LF(arg,len2)
#define LFlen0(arg)  Lfloat_length(arg)
#define LFlen1(arg)  LF_minlen
#define TO_F_0(erg,to)  erg
#define TO_F_1(erg,to)  to(erg)
#define TO_F_2(erg,to)                                  \
     erg; /* execute operation */                       \
     {                                                  \
       STACK_1 = to(STACK_1); /* convert 1. value */    \
       STACK_0 = to(STACK_0); /* convert 2. value */    \
     }

/* ---- the two call sites, flo_rest.d:336-340 and :368-371 verbatim.
   `r,s' is `1,0' for the first and `0,1' for the second, and those are
   the only two combinations `lisparit.c' uses. ---- */

local maygc object F_F_plus_F (object x, object y)
{
  GEN_F_op2(x,y,SF_SF_plus_SF,FF_FF_plus_FF,DF_DF_plus_DF,LF_LF_plus_LF,
            1,0,return)
}

local maygc signean F_F_comp (object x, object y)
{
  GEN_F_op2(x,y,SF_SF_comp,FF_FF_comp,DF_DF_comp,LF_LF_comp,0,1,return)
}

object (*cppclisp_probe_plus)(object,object) = F_F_plus_F;
signean (*cppclisp_probe_comp)(object,object) = F_F_comp;
