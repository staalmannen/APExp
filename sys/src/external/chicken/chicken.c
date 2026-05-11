/* Generated from chicken.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.chicken -output-file chicken.c
   uses: c-backend scrutinizer compiler-syntax lfa2 optimizer compiler lolevel extras srfi-4 chicken-ffi-syntax chicken-syntax eval data-structures user-pass support c-platform batch-driver library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_c_2dbackend_toplevel)
C_externimport void C_ccall C_c_2dbackend_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_scrutinizer_toplevel)
C_externimport void C_ccall C_scrutinizer_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_2dsyntax_toplevel)
C_externimport void C_ccall C_compiler_2dsyntax_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lfa2_toplevel)
C_externimport void C_ccall C_lfa2_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_optimizer_toplevel)
C_externimport void C_ccall C_optimizer_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_toplevel)
C_externimport void C_ccall C_compiler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lolevel_toplevel)
C_externimport void C_ccall C_lolevel_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_srfi_2d4_toplevel)
C_externimport void C_ccall C_srfi_2d4_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_chicken_2dffi_2dsyntax_toplevel)
C_externimport void C_ccall C_chicken_2dffi_2dsyntax_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_chicken_2dsyntax_toplevel)
C_externimport void C_ccall C_chicken_2dsyntax_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_user_2dpass_toplevel)
C_externimport void C_ccall C_user_2dpass_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externimport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_c_2dplatform_toplevel)
C_externimport void C_ccall C_c_2dplatform_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_batch_2ddriver_toplevel)
C_externimport void C_ccall C_batch_2ddriver_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[45];
static double C_possibly_force_alignment;


C_noret_decl(f_1020)
static void C_fcall f_1020(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1038)
static void C_ccall f_1038(C_word c,C_word *av) C_noret;
C_noret_decl(f_1052)
static C_word C_fcall f_1052(C_word t0,C_word t1);
C_noret_decl(f_1345)
static void C_fcall f_1345(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1351)
static void C_fcall f_1351(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1365)
static void C_ccall f_1365(C_word c,C_word *av) C_noret;
C_noret_decl(f_2195)
static void C_ccall f_2195(C_word c,C_word *av) C_noret;
C_noret_decl(f_2197)
static void C_ccall f_2197(C_word c,C_word *av) C_noret;
C_noret_decl(f_2203)
static void C_fcall f_2203(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2217)
static void C_ccall f_2217(C_word c,C_word *av) C_noret;
C_noret_decl(f_2255)
static void C_ccall f_2255(C_word c,C_word *av) C_noret;
C_noret_decl(f_2259)
static void C_ccall f_2259(C_word c,C_word *av) C_noret;
C_noret_decl(f_2295)
static void C_ccall f_2295(C_word c,C_word *av) C_noret;
C_noret_decl(f_2301)
static void C_ccall f_2301(C_word c,C_word *av) C_noret;
C_noret_decl(f_2303)
static void C_ccall f_2303(C_word c,C_word *av) C_noret;
C_noret_decl(f_2307)
static void C_ccall f_2307(C_word c,C_word *av) C_noret;
C_noret_decl(f_2315)
static void C_ccall f_2315(C_word c,C_word *av) C_noret;
C_noret_decl(f_2319)
static void C_ccall f_2319(C_word c,C_word *av) C_noret;
C_noret_decl(f_2322)
static void C_ccall f_2322(C_word c,C_word *av) C_noret;
C_noret_decl(f_2327)
static void C_fcall f_2327(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2347)
static void C_ccall f_2347(C_word c,C_word *av) C_noret;
C_noret_decl(f_2362)
static void C_ccall f_2362(C_word c,C_word *av) C_noret;
C_noret_decl(f_2372)
static void C_ccall f_2372(C_word c,C_word *av) C_noret;
C_noret_decl(f_2382)
static void C_ccall f_2382(C_word c,C_word *av) C_noret;
C_noret_decl(f_2392)
static void C_ccall f_2392(C_word c,C_word *av) C_noret;
C_noret_decl(f_2402)
static void C_ccall f_2402(C_word c,C_word *av) C_noret;
C_noret_decl(f_2412)
static void C_ccall f_2412(C_word c,C_word *av) C_noret;
C_noret_decl(f_2435)
static void C_ccall f_2435(C_word c,C_word *av) C_noret;
C_noret_decl(f_2438)
static void C_ccall f_2438(C_word c,C_word *av) C_noret;
C_noret_decl(f_2450)
static void C_ccall f_2450(C_word c,C_word *av) C_noret;
C_noret_decl(f_2525)
static void C_ccall f_2525(C_word c,C_word *av) C_noret;
C_noret_decl(f_2532)
static void C_ccall f_2532(C_word c,C_word *av) C_noret;
C_noret_decl(f_2548)
static void C_ccall f_2548(C_word c,C_word *av) C_noret;
C_noret_decl(f_2552)
static void C_ccall f_2552(C_word c,C_word *av) C_noret;
C_noret_decl(f_2560)
static void C_ccall f_2560(C_word c,C_word *av) C_noret;
C_noret_decl(f_2567)
static void C_ccall f_2567(C_word c,C_word *av) C_noret;
C_noret_decl(f_859)
static void C_ccall f_859(C_word c,C_word *av) C_noret;
C_noret_decl(f_862)
static void C_ccall f_862(C_word c,C_word *av) C_noret;
C_noret_decl(f_865)
static void C_ccall f_865(C_word c,C_word *av) C_noret;
C_noret_decl(f_868)
static void C_ccall f_868(C_word c,C_word *av) C_noret;
C_noret_decl(f_871)
static void C_ccall f_871(C_word c,C_word *av) C_noret;
C_noret_decl(f_874)
static void C_ccall f_874(C_word c,C_word *av) C_noret;
C_noret_decl(f_877)
static void C_ccall f_877(C_word c,C_word *av) C_noret;
C_noret_decl(f_880)
static void C_ccall f_880(C_word c,C_word *av) C_noret;
C_noret_decl(f_883)
static void C_ccall f_883(C_word c,C_word *av) C_noret;
C_noret_decl(f_886)
static void C_ccall f_886(C_word c,C_word *av) C_noret;
C_noret_decl(f_889)
static void C_ccall f_889(C_word c,C_word *av) C_noret;
C_noret_decl(f_892)
static void C_ccall f_892(C_word c,C_word *av) C_noret;
C_noret_decl(f_895)
static void C_ccall f_895(C_word c,C_word *av) C_noret;
C_noret_decl(f_898)
static void C_ccall f_898(C_word c,C_word *av) C_noret;
C_noret_decl(f_901)
static void C_ccall f_901(C_word c,C_word *av) C_noret;
C_noret_decl(f_904)
static void C_ccall f_904(C_word c,C_word *av) C_noret;
C_noret_decl(f_907)
static void C_ccall f_907(C_word c,C_word *av) C_noret;
C_noret_decl(f_910)
static void C_ccall f_910(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1020)
static void C_ccall trf_1020(C_word c,C_word *av) C_noret;
static void C_ccall trf_1020(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1020(t0,t1,t2);}

C_noret_decl(trf_1345)
static void C_ccall trf_1345(C_word c,C_word *av) C_noret;
static void C_ccall trf_1345(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1345(t0,t1,t2);}

C_noret_decl(trf_1351)
static void C_ccall trf_1351(C_word c,C_word *av) C_noret;
static void C_ccall trf_1351(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1351(t0,t1,t2,t3);}

C_noret_decl(trf_2203)
static void C_ccall trf_2203(C_word c,C_word *av) C_noret;
static void C_ccall trf_2203(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2203(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2327)
static void C_ccall trf_2327(C_word c,C_word *av) C_noret;
static void C_ccall trf_2327(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2327(t0,t1,t2);}

/* chicken.compiler.chicken#take in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_fcall f_1020(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_1020,3,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t3,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1038,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:56: take */
t7=t5;
t8=C_u_i_cdr(t2);
t9=C_fixnum_difference(t3,C_fix(1));
t1=t7;
t2=t8;
t3=t9;
goto loop;}}

/* k1036 in chicken.compiler.chicken#take in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_1038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1038,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k2550 in k2546 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static C_word C_fcall f_1052(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_less_or_equal_p(t2,C_fix(0)))){
return(t1);}
else{
t4=C_i_cdr(t1);
t5=C_fixnum_difference(t2,C_fix(1));
t1=t4;
t2=t5;
goto loop;}}

/* chicken.compiler.chicken#cons* in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_fcall f_1345(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_1345,3,t1,t2,t3);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1351,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_1351(t7,t1,t2,t3);}

/* loop in chicken.compiler.chicken#cons* in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_fcall f_1351(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_1351,4,t0,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1365,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:95: loop */
t6=t4;
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
t1=t6;
t2=t7;
t3=t8;
goto loop;}}

/* k1363 in loop in chicken.compiler.chicken#cons* in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_1365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1365,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_2195,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[3] /* (set! chicken.compiler.chicken#compiler-arguments ...) */,t1);
t3=C_mutate(&lf[4] /* (set! chicken.compiler.chicken#process-command-line ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2197,tmp=(C_word)a,a+=2,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2295,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2303,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2315,tmp=(C_word)a,a+=2,tmp);
/* chicken.scm:85: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t4;
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}

/* chicken.compiler.chicken#process-command-line in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_2197,c,av);}
a=C_alloc(5);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2203,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_2203(t6,t1,t2,C_SCHEME_END_OF_LIST,C_SCHEME_FALSE);}

/* loop in chicken.compiler.chicken#process-command-line in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static void C_fcall f_2203(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_2203,5,t0,t1,t2,t3,t4);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2217,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken.scm:70: scheme#reverse */
t6=*((C_word*)lf[5]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_i_car(t2);
t6=C_i_string_length(t5);
t7=C_i_string_ref(t5,C_fix(0));
t8=(C_truep(C_u_i_char_equalp(C_make_character(45),t7))?C_fixnum_greaterp(t6,C_fix(1)):C_SCHEME_FALSE);
if(C_truep(t8)){
t9=C_fixnum_greaterp(t6,C_fix(1));
t10=(C_truep(t9)?C_u_i_char_equalp(C_make_character(58),C_i_string_ref(t5,C_fix(1))):C_SCHEME_FALSE);
if(C_truep(t10)){
/* chicken.scm:76: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t18=t4;
t1=t15;
t2=t16;
t3=t17;
t4=t18;
goto loop;}
else{
t11=C_u_i_cdr(t2);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2255,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t11,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2259,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
/* chicken.scm:77: scheme#substring */
t14=*((C_word*)lf[7]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=t5;
av2[3]=C_fix(1);
av2[4]=t6;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}
else{
if(C_truep(t4)){
t9=C_u_i_cdr(t2);
t10=C_a_i_cons(&a,2,t5,t3);
/* chicken.scm:79: loop */
t15=t1;
t16=t9;
t17=t10;
t18=t4;
t1=t15;
t2=t16;
t3=t17;
t4=t18;
goto loop;}
else{
/* chicken.scm:80: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t18=t5;
t1=t15;
t2=t16;
t3=t17;
t4=t18;
goto loop;}}}}

/* k2215 in loop in chicken.compiler.chicken#process-command-line in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2217,c,av);}
/* chicken.scm:70: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
C_values(4,av2);}}

/* k2253 in loop in chicken.compiler.chicken#process-command-line in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2255,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* chicken.scm:77: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2203(t3,((C_word*)t0)[4],((C_word*)t0)[5],t2,((C_word*)t0)[6]);}

/* k2257 in loop in chicken.compiler.chicken#process-command-line in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2259,c,av);}
/* chicken.scm:77: scheme#string->symbol */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k2293 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2295,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2301,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2299 in k2293 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static void C_ccall f_2301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2301,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2302 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2303,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2307,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken.scm:85: chicken.compiler.user-pass#user-options-pass */
t3=*((C_word*)lf[9]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2305 in a2302 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static void C_ccall f_2307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2307,c,av);}
if(C_truep(t1)){
/* chicken.scm:85: g585 */
t2=t1;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=lf[4];
t3=lf[4];
/* chicken.scm:85: g585 */
t4=lf[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[3];
f_2197(3,av2);}}}

/* a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2315(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_2315,c,av);}
a=C_alloc(13);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2319,a[2]=t1,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2327,a[2]=t4,a[3]=t7,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_2327(t9,t5,((C_word*)t4)[1]);}

/* k2317 in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static void C_ccall f_2319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2319,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2322,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=t2;
av2[2]=*((C_word*)lf[11]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=lf[3];
av2[5]=((C_word*)((C_word*)t0)[4])[1];
C_apply(6,av2);}}

/* k2320 in k2317 in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2322,c,av);}
/* chicken.scm:163: chicken.base#exit */
t2=*((C_word*)lf[10]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 in ... */
static void C_fcall f_2327(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_2327,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=C_eqp(lf[12],t3);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2347,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:92: scheme#string->number */
t7=*((C_word*)lf[27]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_i_car(t4);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=C_eqp(lf[28],t3);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2435,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:145: scheme#string->number */
t8=*((C_word*)lf[27]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_i_car(t4);
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
if(C_truep(C_i_memq(t3,*((C_word*)lf[32]+1)))){
/* chicken.scm:152: loop */
t10=t1;
t11=t4;
t1=t10;
t2=t11;
goto loop;}
else{
if(C_truep(C_i_memq(t3,*((C_word*)lf[33]+1)))){
if(C_truep(C_i_pairp(t4))){
/* chicken.scm:155: loop */
t10=t1;
t11=C_u_i_cdr(t4);
t1=t10;
t2=t11;
goto loop;}
else{
/* chicken.scm:156: chicken.compiler.support#quit-compiling */
t7=*((C_word*)lf[30]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t1;
av2[2]=lf[34];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}
else{
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2525,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2532,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_stringp(t3))){
/* chicken.scm:158: chicken.base#warning */
t9=*((C_word*)lf[35]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t7;
av2[2]=lf[36];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
/* chicken.scm:160: chicken.string#conc */
t9=*((C_word*)lf[37]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[38];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}}}}}}}

/* k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_2347,c,av);}
a=C_alloc(39);
switch(t1){
case C_fix(0):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2362,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:96: cons* */
f_1345(t2,lf[13],C_a_i_list(&a,2,lf[14],((C_word*)((C_word*)t0)[2])[1]));
case C_fix(1):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2372,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:99: cons* */
f_1345(t2,lf[15],C_a_i_list(&a,1,((C_word*)((C_word*)t0)[2])[1]));
case C_fix(2):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2382,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:103: cons* */
f_1345(t2,lf[15],C_a_i_list(&a,3,lf[16],lf[17],((C_word*)((C_word*)t0)[2])[1]));
case C_fix(3):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2392,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:110: cons* */
f_1345(t2,lf[15],C_a_i_list(&a,6,lf[16],lf[18],lf[19],lf[17],lf[20],((C_word*)((C_word*)t0)[2])[1]));
case C_fix(4):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2402,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:120: cons* */
f_1345(t2,lf[15],C_a_i_list(&a,7,lf[16],lf[18],lf[20],lf[17],lf[19],lf[21],((C_word*)((C_word*)t0)[2])[1]));
default:
if(C_truep(C_i_greater_or_equalp(t1,C_fix(5)))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2412,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:131: cons* */
f_1345(t2,lf[22],C_a_i_list(&a,11,lf[23],lf[21],lf[24],lf[20],lf[15],lf[25],lf[16],lf[18],lf[26],lf[17],((C_word*)((C_word*)t0)[2])[1]));}
else{
/* chicken.scm:143: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_2327(t2,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}}}

/* k2360 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2362,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2370 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2372,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2380 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2382,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2390 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2392,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2400 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2402(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2402,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2410 in k2345 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2412,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:143: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2433 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2435(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_2435,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2438,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
switch(t1){
case C_fix(0):
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2450,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken.scm:146: cons* */
f_1345(t3,lf[25],C_a_i_list(&a,2,lf[23],((C_word*)((C_word*)t0)[5])[1]));
case C_fix(1):
t3=C_a_i_cons(&a,2,lf[23],((C_word*)((C_word*)t0)[5])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[5])+1,t3);
/* chicken.scm:151: loop */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2327(t5,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));
case C_fix(2):
/* chicken.scm:151: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2327(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));
case C_fix(3):
t3=C_a_i_cons(&a,2,lf[29],((C_word*)((C_word*)t0)[5])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[5])+1,t3);
/* chicken.scm:151: loop */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2327(t5,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));
default:
/* chicken.scm:150: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[30]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[31];
av2[3]=C_u_i_car(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k2436 in k2433 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2438,c,av);}
/* chicken.scm:151: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2327(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* k2448 in k2433 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in ... */
static void C_ccall f_2450(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2450,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* chicken.scm:151: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2327(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}

/* k2523 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2525,c,av);}
/* chicken.scm:161: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2327(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k2530 in loop in a2314 in k2193 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in ... */
static void C_ccall f_2532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2532,c,av);}
/* chicken.scm:158: chicken.base#warning */
t2=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[36];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k2546 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_2548,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2552,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2560,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken.scm:57: chicken.process-context#get-environment-variable */
t4=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[43];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k2550 in k2546 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_2552,c,av);}
a=C_alloc(2);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1052,tmp=(C_word)a,a+=2,tmp);
t3=(
  f_1052(((C_word*)t0)[2],C_fix(1))
);
/* chicken.scm:56: scheme#append */
t4=*((C_word*)lf[39]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k2558 in k2546 in k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2560,c,av);}
if(C_truep(t1)){
/* chicken.scm:57: chicken.string#string-split */
t2=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
/* chicken.scm:57: chicken.string#string-split */
t2=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[41];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k2565 in k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_2567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2567,c,av);}
a=C_alloc(7);
t2=C_i_cdr(t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2195,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t2))){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
f_2195(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2548,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* chicken.scm:56: take */
f_1020(t4,t2,C_fix(1));}}

/* k857 */
static void C_ccall f_859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_859,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_862,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k860 in k857 */
static void C_ccall f_862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_862,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_865,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_chicken_2dsyntax_toplevel(2,av2);}}

/* k863 in k860 in k857 */
static void C_ccall f_865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_865,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_868,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_chicken_2dffi_2dsyntax_toplevel(2,av2);}}

/* k866 in k863 in k860 in k857 */
static void C_ccall f_868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_868,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_871,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_srfi_2d4_toplevel(2,av2);}}

/* k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_871,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_874,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_874,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_877,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_877,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_880,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lolevel_toplevel(2,av2);}}

/* k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_880,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_883,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_support_toplevel(2,av2);}}

/* k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_883(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_883,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_886,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_toplevel(2,av2);}}

/* k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_886,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_889,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_optimizer_toplevel(2,av2);}}

/* k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_889,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_892,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lfa2_toplevel(2,av2);}}

/* k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_892,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_895,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_2dsyntax_toplevel(2,av2);}}

/* k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_895,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_898,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_scrutinizer_toplevel(2,av2);}}

/* k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_898,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_901,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_batch_2ddriver_toplevel(2,av2);}}

/* k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_901(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_901,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_904,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_c_2dplatform_toplevel(2,av2);}}

/* k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_904,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_907,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_c_2dbackend_toplevel(2,av2);}}

/* k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_907,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_910,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_user_2dpass_toplevel(2,av2);}}

/* k908 in k905 in k902 in k899 in k896 in k893 in k890 in k887 in k884 in k881 in k878 in k875 in k872 in k869 in k866 in k863 in k860 in k857 */
static void C_ccall f_910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_910,c,av);}
a=C_alloc(15);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_mutate(&lf[1] /* (set! chicken.compiler.chicken#take ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1020,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate(&lf[2] /* (set! chicken.compiler.chicken#cons* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1345,tmp=(C_word)a,a+=2,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2567,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.scm:53: chicken.process-context#argv */
t6=*((C_word*)lf[44]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;
C_main_entry_point

void C_ccall C_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("toplevel"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(245))){
C_save(t1);
C_rereclaim2(245*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,45);
lf[0]=C_h_intern(&lf[0],25, C_text("chicken.compiler.chicken#"));
lf[5]=C_h_intern(&lf[5],14, C_text("scheme#reverse"));
lf[6]=C_h_intern(&lf[6],21, C_text("scheme#string->symbol"));
lf[7]=C_h_intern(&lf[7],16, C_text("scheme#substring"));
lf[8]=C_h_intern(&lf[8],34, C_text("chicken.base#implicit-exit-handler"));
lf[9]=C_h_intern(&lf[9],44, C_text("chicken.compiler.user-pass#user-options-pass"));
lf[10]=C_h_intern(&lf[10],17, C_text("chicken.base#exit"));
lf[11]=C_h_intern(&lf[11],49, C_text("chicken.compiler.batch-driver#compile-source-file"));
lf[12]=C_h_intern(&lf[12],14, C_text("optimize-level"));
lf[13]=C_h_intern(&lf[13],18, C_text("no-compiler-syntax"));
lf[14]=C_h_intern(&lf[14],21, C_text("no-usual-integrations"));
lf[15]=C_h_intern(&lf[15],22, C_text("optimize-leaf-routines"));
lf[16]=C_h_intern(&lf[16],6, C_text("inline"));
lf[17]=C_h_intern(&lf[17],4, C_text("lfa2"));
lf[18]=C_h_intern(&lf[18],13, C_text("inline-global"));
lf[19]=C_h_intern(&lf[19],5, C_text("local"));
lf[20]=C_h_intern(&lf[20],10, C_text("specialize"));
lf[21]=C_h_intern(&lf[21],6, C_text("unsafe"));
lf[22]=C_h_intern(&lf[22],18, C_text("disable-interrupts"));
lf[23]=C_h_intern(&lf[23],8, C_text("no-trace"));
lf[24]=C_h_intern(&lf[24],5, C_text("block"));
lf[25]=C_h_intern(&lf[25],14, C_text("no-lambda-info"));
lf[26]=C_h_intern(&lf[26],10, C_text("clustering"));
lf[27]=C_h_intern(&lf[27],21, C_text("scheme#string->number"));
lf[28]=C_h_intern(&lf[28],11, C_text("debug-level"));
lf[29]=C_h_intern(&lf[29],10, C_text("debug-info"));
lf[30]=C_h_intern(&lf[30],39, C_text("chicken.compiler.support#quit-compiling"));
lf[31]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027invalid debug level: ~a"));
lf[32]=C_h_intern(&lf[32],50, C_text("chicken.compiler.c-platform#valid-compiler-options"));
lf[33]=C_h_intern(&lf[33],64, C_text("chicken.compiler.c-platform#valid-compiler-options-with-argument"));
lf[34]=C_decode_literal(C_heaptop,C_text("\376B\000\000 missing argument to `-~s\047 option"));
lf[35]=C_h_intern(&lf[35],20, C_text("chicken.base#warning"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000!invalid compiler option (ignored)"));
lf[37]=C_h_intern(&lf[37],19, C_text("chicken.string#conc"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[39]=C_h_intern(&lf[39],13, C_text("scheme#append"));
lf[40]=C_h_intern(&lf[40],27, C_text("chicken.string#string-split"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[42]=C_h_intern(&lf[42],48, C_text("chicken.process-context#get-environment-variable"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017CHICKEN_OPTIONS"));
lf[44]=C_h_intern(&lf[44],28, C_text("chicken.process-context#argv"));
C_register_lf2(lf,45,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_859,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[56] = {
{C_text("f_1020:chicken_2escm"),(void*)f_1020},
{C_text("f_1038:chicken_2escm"),(void*)f_1038},
{C_text("f_1052:chicken_2escm"),(void*)f_1052},
{C_text("f_1345:chicken_2escm"),(void*)f_1345},
{C_text("f_1351:chicken_2escm"),(void*)f_1351},
{C_text("f_1365:chicken_2escm"),(void*)f_1365},
{C_text("f_2195:chicken_2escm"),(void*)f_2195},
{C_text("f_2197:chicken_2escm"),(void*)f_2197},
{C_text("f_2203:chicken_2escm"),(void*)f_2203},
{C_text("f_2217:chicken_2escm"),(void*)f_2217},
{C_text("f_2255:chicken_2escm"),(void*)f_2255},
{C_text("f_2259:chicken_2escm"),(void*)f_2259},
{C_text("f_2295:chicken_2escm"),(void*)f_2295},
{C_text("f_2301:chicken_2escm"),(void*)f_2301},
{C_text("f_2303:chicken_2escm"),(void*)f_2303},
{C_text("f_2307:chicken_2escm"),(void*)f_2307},
{C_text("f_2315:chicken_2escm"),(void*)f_2315},
{C_text("f_2319:chicken_2escm"),(void*)f_2319},
{C_text("f_2322:chicken_2escm"),(void*)f_2322},
{C_text("f_2327:chicken_2escm"),(void*)f_2327},
{C_text("f_2347:chicken_2escm"),(void*)f_2347},
{C_text("f_2362:chicken_2escm"),(void*)f_2362},
{C_text("f_2372:chicken_2escm"),(void*)f_2372},
{C_text("f_2382:chicken_2escm"),(void*)f_2382},
{C_text("f_2392:chicken_2escm"),(void*)f_2392},
{C_text("f_2402:chicken_2escm"),(void*)f_2402},
{C_text("f_2412:chicken_2escm"),(void*)f_2412},
{C_text("f_2435:chicken_2escm"),(void*)f_2435},
{C_text("f_2438:chicken_2escm"),(void*)f_2438},
{C_text("f_2450:chicken_2escm"),(void*)f_2450},
{C_text("f_2525:chicken_2escm"),(void*)f_2525},
{C_text("f_2532:chicken_2escm"),(void*)f_2532},
{C_text("f_2548:chicken_2escm"),(void*)f_2548},
{C_text("f_2552:chicken_2escm"),(void*)f_2552},
{C_text("f_2560:chicken_2escm"),(void*)f_2560},
{C_text("f_2567:chicken_2escm"),(void*)f_2567},
{C_text("f_859:chicken_2escm"),(void*)f_859},
{C_text("f_862:chicken_2escm"),(void*)f_862},
{C_text("f_865:chicken_2escm"),(void*)f_865},
{C_text("f_868:chicken_2escm"),(void*)f_868},
{C_text("f_871:chicken_2escm"),(void*)f_871},
{C_text("f_874:chicken_2escm"),(void*)f_874},
{C_text("f_877:chicken_2escm"),(void*)f_877},
{C_text("f_880:chicken_2escm"),(void*)f_880},
{C_text("f_883:chicken_2escm"),(void*)f_883},
{C_text("f_886:chicken_2escm"),(void*)f_886},
{C_text("f_889:chicken_2escm"),(void*)f_889},
{C_text("f_892:chicken_2escm"),(void*)f_892},
{C_text("f_895:chicken_2escm"),(void*)f_895},
{C_text("f_898:chicken_2escm"),(void*)f_898},
{C_text("f_901:chicken_2escm"),(void*)f_901},
{C_text("f_904:chicken_2escm"),(void*)f_904},
{C_text("f_907:chicken_2escm"),(void*)f_907},
{C_text("f_910:chicken_2escm"),(void*)f_910},
{C_text("toplevel:chicken_2escm"),(void*)C_toplevel},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
o|hiding unexported module binding: chicken.compiler.chicken#partition 
o|hiding unexported module binding: chicken.compiler.chicken#span 
o|hiding unexported module binding: chicken.compiler.chicken#take 
o|hiding unexported module binding: chicken.compiler.chicken#drop 
o|hiding unexported module binding: chicken.compiler.chicken#split-at 
o|hiding unexported module binding: chicken.compiler.chicken#append-map 
o|hiding unexported module binding: chicken.compiler.chicken#every 
o|hiding unexported module binding: chicken.compiler.chicken#any 
o|hiding unexported module binding: chicken.compiler.chicken#cons* 
o|hiding unexported module binding: chicken.compiler.chicken#concatenate 
o|hiding unexported module binding: chicken.compiler.chicken#delete 
o|hiding unexported module binding: chicken.compiler.chicken#first 
o|hiding unexported module binding: chicken.compiler.chicken#second 
o|hiding unexported module binding: chicken.compiler.chicken#third 
o|hiding unexported module binding: chicken.compiler.chicken#fourth 
o|hiding unexported module binding: chicken.compiler.chicken#fifth 
o|hiding unexported module binding: chicken.compiler.chicken#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.chicken#alist-cons 
o|hiding unexported module binding: chicken.compiler.chicken#filter 
o|hiding unexported module binding: chicken.compiler.chicken#filter-map 
o|hiding unexported module binding: chicken.compiler.chicken#remove 
o|hiding unexported module binding: chicken.compiler.chicken#unzip1 
o|hiding unexported module binding: chicken.compiler.chicken#last 
o|hiding unexported module binding: chicken.compiler.chicken#list-index 
o|hiding unexported module binding: chicken.compiler.chicken#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#list-tabulate 
o|hiding unexported module binding: chicken.compiler.chicken#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.chicken#length+ 
o|hiding unexported module binding: chicken.compiler.chicken#find 
o|hiding unexported module binding: chicken.compiler.chicken#find-tail 
o|hiding unexported module binding: chicken.compiler.chicken#iota 
o|hiding unexported module binding: chicken.compiler.chicken#make-list 
o|hiding unexported module binding: chicken.compiler.chicken#posq 
o|hiding unexported module binding: chicken.compiler.chicken#posv 
o|hiding unexported module binding: chicken.compiler.chicken#compiler-arguments 
o|hiding unexported module binding: chicken.compiler.chicken#process-command-line 
S|applied compiler syntax:
S|  chicken.base#foldl		3
S|  scheme#map		3
S|  chicken.base#foldr		3
o|eliminated procedure checks: 25 
o|specializations:
o|  9 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  2 (scheme#> fixnum fixnum)
o|  2 (scheme#char=? char char)
o|  2 (scheme#string-ref string fixnum)
o|  1 (scheme#eqv? * *)
o|  3 (##sys#check-list (or pair list) *)
o|  30 (scheme#cdr pair)
o|  8 (scheme#car pair)
(o e)|safe calls: 228 
o|safe globals: (chicken.compiler.chicken#posv chicken.compiler.chicken#posq chicken.compiler.chicken#make-list chicken.compiler.chicken#iota chicken.compiler.chicken#find-tail chicken.compiler.chicken#find chicken.compiler.chicken#length+ chicken.compiler.chicken#lset=/eq? chicken.compiler.chicken#lset<=/eq? chicken.compiler.chicken#list-tabulate chicken.compiler.chicken#lset-intersection/eq? chicken.compiler.chicken#lset-union/eq? chicken.compiler.chicken#lset-difference/eq? chicken.compiler.chicken#lset-adjoin/eq? chicken.compiler.chicken#list-index chicken.compiler.chicken#last chicken.compiler.chicken#unzip1 chicken.compiler.chicken#remove chicken.compiler.chicken#filter-map chicken.compiler.chicken#filter chicken.compiler.chicken#alist-cons chicken.compiler.chicken#delete-duplicates chicken.compiler.chicken#fifth chicken.compiler.chicken#fourth chicken.compiler.chicken#third chicken.compiler.chicken#second chicken.compiler.chicken#first chicken.compiler.chicken#delete chicken.compiler.chicken#concatenate chicken.compiler.chicken#cons* chicken.compiler.chicken#any chicken.compiler.chicken#every chicken.compiler.chicken#append-map chicken.compiler.chicken#split-at chicken.compiler.chicken#drop chicken.compiler.chicken#take chicken.compiler.chicken#span chicken.compiler.chicken#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#span 
o|inlining procedure: k1022 
o|inlining procedure: k1022 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#split-at 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#append-map 
o|inlining procedure: k1292 
o|inlining procedure: k1292 
o|inlining procedure: k1323 
o|inlining procedure: k1323 
o|merged explicitly consed rest parameter: xs229 
o|inlining procedure: k1353 
o|inlining procedure: k1353 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#concatenate 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#first 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#third 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#fifth 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#alist-cons 
o|inlining procedure: k1540 
o|inlining procedure: k1540 
o|inlining procedure: k1532 
o|inlining procedure: k1532 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#filter-map 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#remove 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#unzip1 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#last 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#list-index 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset-intersection/eq? 
o|inlining procedure: k1931 
o|inlining procedure: k1931 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#length+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#find 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#make-list 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#posq 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#posv 
o|inlining procedure: k2205 
o|substituted constant variable: a2225 
o|inlining procedure: k2205 
o|inlining procedure: k2232 
o|inlining procedure: k2232 
o|substituted constant variable: a2266 
o|substituted constant variable: a2263 
o|substituted constant variable: a2268 
o|inlining procedure: k2269 
o|inlining procedure: k2269 
o|substituted constant variable: a2286 
o|substituted constant variable: a2292 
o|inlining procedure: k2308 
o|inlining procedure: k2308 
o|propagated global variable: r23092593 chicken.compiler.chicken#process-command-line 
o|inlining procedure: k2329 
o|inlining procedure: k2329 
o|consed rest parameter at call site: "(chicken.scm:96) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2363 
o|consed rest parameter at call site: "(chicken.scm:99) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2363 
o|consed rest parameter at call site: "(chicken.scm:103) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2383 
o|consed rest parameter at call site: "(chicken.scm:110) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2383 
o|consed rest parameter at call site: "(chicken.scm:120) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2403 
o|consed rest parameter at call site: "(chicken.scm:131) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2403 
o|substituted constant variable: a2414 
o|substituted constant variable: a2416 
o|substituted constant variable: a2418 
o|substituted constant variable: a2420 
o|substituted constant variable: a2422 
o|inlining procedure: k2427 
o|consed rest parameter at call site: "(chicken.scm:146) chicken.compiler.chicken#cons*" 2 
o|inlining procedure: k2451 
o|inlining procedure: k2451 
o|inlining procedure: k2467 
o|inlining procedure: k2467 
o|substituted constant variable: a2483 
o|substituted constant variable: a2485 
o|substituted constant variable: a2487 
o|substituted constant variable: a2489 
o|inlining procedure: k2427 
o|inlining procedure: k2503 
o|inlining procedure: k2503 
o|inlining procedure: k2530 
o|inlining procedure: k2530 
o|contracted procedure: "(chicken.scm:58) chicken.compiler.chicken#drop" 
o|inlining procedure: k1054 
o|inlining procedure: k1054 
o|inlining procedure: k2561 
o|inlining procedure: k2561 
o|replaced variables: 163 
o|removed binding forms: 82 
o|substituted constant variable: r10232568 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#every 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#any 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#filter 
o|removed side-effect free assignment to unused variable: chicken.compiler.chicken#list-tabulate 
o|substituted constant variable: n112 
o|substituted constant variable: r25622622 
o|substituted constant variable: r25622622 
o|replaced variables: 18 
o|removed binding forms: 146 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2348 
o|inlining procedure: k2436 
o|inlining procedure: k2436 
o|inlining procedure: k2436 
o|inlining procedure: k2436 
o|removed binding forms: 25 
o|removed binding forms: 12 
o|removed binding forms: 1 
o|simplifications: ((if . 2) (let . 18) (##core#call . 44)) 
o|  call simplifications:
o|    scheme#cdr	2
o|    ##sys#call-with-values
o|    scheme#memq	2
o|    scheme#string?
o|    scheme#pair?
o|    scheme#eq?	11
o|    scheme#>=
o|    scheme#apply
o|    scheme#string-length
o|    chicken.fixnum#fx>	2
o|    scheme#values
o|    scheme#null?	4
o|    chicken.fixnum#fx<=	2
o|    scheme#car	6
o|    chicken.fixnum#fx-	2
o|    scheme#cons	6
o|contracted procedure: k1025 
o|contracted procedure: k1032 
o|contracted procedure: k1042 
o|contracted procedure: k1356 
o|contracted procedure: k1367 
o|contracted procedure: k2190 
o|contracted procedure: k2208 
o|contracted procedure: k2218 
o|contracted procedure: k2221 
o|contracted procedure: k2229 
o|contracted procedure: k2260 
o|contracted procedure: k2235 
o|contracted procedure: k2249 
o|contracted procedure: k2278 
o|contracted procedure: k2332 
o|contracted procedure: k2335 
o|contracted procedure: k2342 
o|contracted procedure: k2356 
o|contracted procedure: k2366 
o|contracted procedure: k2376 
o|contracted procedure: k2386 
o|contracted procedure: k2396 
o|contracted procedure: k2406 
o|contracted procedure: k2424 
o|contracted procedure: k2430 
o|contracted procedure: k2444 
o|contracted procedure: k2454 
o|contracted procedure: k2458 
o|contracted procedure: k2464 
o|contracted procedure: k2470 
o|contracted procedure: k2474 
o|contracted procedure: k2491 
o|contracted procedure: k2497 
o|contracted procedure: k2506 
o|contracted procedure: k2512 
o|contracted procedure: k2533 
o|contracted procedure: k2539 
o|contracted procedure: k1057 
o|contracted procedure: k1064 
o|contracted procedure: k1068 
o|simplifications: ((let . 25)) 
o|removed binding forms: 40 
o|direct leaf routine/allocation: loop113 0 
o|contracted procedure: k2554 
o|converted assignments to bindings: (loop113) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 1 
o|customizable procedures: (chicken.compiler.chicken#cons* loop592 loop575 loop230 chicken.compiler.chicken#take) 
o|calls to known targets: 34 
o|identified direct recursive calls: f_1020 1 
o|identified direct recursive calls: f_1351 1 
o|identified direct recursive calls: f_2203 3 
o|identified direct recursive calls: f_2327 2 
o|identified direct recursive calls: f_1052 1 
o|fast box initializations: 3 
o|fast global references: 15 
o|fast global assignments: 4 
o|dropping unused closure argument: f_1020 
o|dropping unused closure argument: f_1052 
o|dropping unused closure argument: f_1345 
*/
/* end of file */
