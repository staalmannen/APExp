/* Generated from user-pass.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: user-pass.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.user-pass -output-file user-pass.c
   unit: user-pass
   uses: eval library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[8];
static double C_possibly_force_alignment;


C_noret_decl(f_136)
static void C_ccall f_136(C_word c,C_word *av) C_noret;
C_noret_decl(f_139)
static void C_ccall f_139(C_word c,C_word *av) C_noret;
C_noret_decl(f_143)
static void C_ccall f_143(C_word c,C_word *av) C_noret;
C_noret_decl(f_147)
static void C_ccall f_147(C_word c,C_word *av) C_noret;
C_noret_decl(f_151)
static void C_ccall f_151(C_word c,C_word *av) C_noret;
C_noret_decl(f_155)
static void C_ccall f_155(C_word c,C_word *av) C_noret;
C_noret_decl(f_159)
static void C_ccall f_159(C_word c,C_word *av) C_noret;
C_noret_decl(C_user_2dpass_toplevel)
C_externexport void C_ccall C_user_2dpass_toplevel(C_word c,C_word *av) C_noret;

/* k134 */
static void C_ccall f_136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_136,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_139,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k137 in k134 */
static void C_ccall f_139(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_139,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_143,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* user-pass.scm:37: chicken.base#make-parameter */
t5=C_fast_retrieve(lf[7]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k141 in k137 in k134 */
static void C_ccall f_143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_143,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[2]+1 /* (set! chicken.compiler.user-pass#user-options-pass ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_147,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* user-pass.scm:38: chicken.base#make-parameter */
t4=C_fast_retrieve(lf[7]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k145 in k141 in k137 in k134 */
static void C_ccall f_147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_147,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[3]+1 /* (set! chicken.compiler.user-pass#user-read-pass ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_151,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* user-pass.scm:39: chicken.base#make-parameter */
t4=C_fast_retrieve(lf[7]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k149 in k145 in k141 in k137 in k134 */
static void C_ccall f_151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_151,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[4]+1 /* (set! chicken.compiler.user-pass#user-preprocessor-pass ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_155,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* user-pass.scm:40: chicken.base#make-parameter */
t4=C_fast_retrieve(lf[7]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k153 in k149 in k145 in k141 in k137 in k134 */
static void C_ccall f_155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_155,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[5]+1 /* (set! chicken.compiler.user-pass#user-pass ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_159,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* user-pass.scm:41: chicken.base#make-parameter */
t4=C_fast_retrieve(lf[7]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k157 in k153 in k149 in k145 in k141 in k137 in k134 */
static void C_ccall f_159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_159,c,av);}
t2=C_mutate((C_word*)lf[6]+1 /* (set! chicken.compiler.user-pass#user-post-analysis-pass ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_user_2dpass_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("user-pass"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_user_2dpass_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(56))){
C_save(t1);
C_rereclaim2(56*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,8);
lf[0]=C_h_intern(&lf[0],9, C_text("user-pass"));
lf[1]=C_h_intern(&lf[1],27, C_text("chicken.compiler.user-pass#"));
lf[2]=C_h_intern(&lf[2],44, C_text("chicken.compiler.user-pass#user-options-pass"));
lf[3]=C_h_intern(&lf[3],41, C_text("chicken.compiler.user-pass#user-read-pass"));
lf[4]=C_h_intern(&lf[4],49, C_text("chicken.compiler.user-pass#user-preprocessor-pass"));
lf[5]=C_h_intern(&lf[5],36, C_text("chicken.compiler.user-pass#user-pass"));
lf[6]=C_h_intern(&lf[6],50, C_text("chicken.compiler.user-pass#user-post-analysis-pass"));
lf[7]=C_h_intern(&lf[7],27, C_text("chicken.base#make-parameter"));
C_register_lf2(lf,8,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_136,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[9] = {
{C_text("f_136:user_2dpass_2escm"),(void*)f_136},
{C_text("f_139:user_2dpass_2escm"),(void*)f_139},
{C_text("f_143:user_2dpass_2escm"),(void*)f_143},
{C_text("f_147:user_2dpass_2escm"),(void*)f_147},
{C_text("f_151:user_2dpass_2escm"),(void*)f_151},
{C_text("f_155:user_2dpass_2escm"),(void*)f_155},
{C_text("f_159:user_2dpass_2escm"),(void*)f_159},
{C_text("toplevel:user_2dpass_2escm"),(void*)C_user_2dpass_toplevel},
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
(o e)|safe calls: 5 
o|removed binding forms: 9 
*/
/* end of file */
