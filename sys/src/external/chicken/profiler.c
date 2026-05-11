/* Generated from profiler.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: profiler.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file profiler.c
   unit: profiler
   uses: library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[25];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,6),40,97,51,51,51,41,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,13),40,97,51,52,50,32,46,32,97,114,103,115,41,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,43),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,112,114,111,102,105,108,101,45,105,110,102,111,32,115,105,122,101,32,102,105,108,101,110,97,109,101,41,0,0,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,40),40,35,35,115,121,115,35,115,101,116,45,112,114,111,102,105,108,101,45,105,110,102,111,45,118,101,99,116,111,114,33,32,118,101,99,32,105,32,120,41};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,112,114,111,102,105,108,101,45,101,110,116,114,121,32,105,110,100,101,120,32,118,101,99,41,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,30),40,35,35,115,121,115,35,112,114,111,102,105,108,101,45,101,120,105,116,32,105,110,100,101,120,32,118,101,99,41,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,49,53,51,32,105,41,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,52,48,32,103,49,52,55,41,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,6),40,97,53,48,53,41,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,22),40,35,35,115,121,115,35,102,105,110,105,115,104,45,112,114,111,102,105,108,101,41,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from cpu-ms */
C_regparm static C_word C_fcall stub105(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_uint64_to_num(&C_a,C_cpu_milliseconds());
return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub81(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word p=(C_word )(C_a0);
C_return(ftell(C_port_file(p)) == 0);
C_ret:
#undef return

return C_r;}

C_noret_decl(f_293)
static void C_ccall f_293(C_word c,C_word *av) C_noret;
C_noret_decl(f_301)
static void C_ccall f_301(C_word c,C_word *av) C_noret;
C_noret_decl(f_305)
static void C_ccall f_305(C_word c,C_word *av) C_noret;
C_noret_decl(f_308)
static void C_ccall f_308(C_word c,C_word *av) C_noret;
C_noret_decl(f_320)
static void C_ccall f_320(C_word c,C_word *av) C_noret;
C_noret_decl(f_323)
static void C_ccall f_323(C_word c,C_word *av) C_noret;
C_noret_decl(f_326)
static void C_ccall f_326(C_word c,C_word *av) C_noret;
C_noret_decl(f_329)
static void C_ccall f_329(C_word c,C_word *av) C_noret;
C_noret_decl(f_334)
static void C_ccall f_334(C_word c,C_word *av) C_noret;
C_noret_decl(f_338)
static void C_ccall f_338(C_word c,C_word *av) C_noret;
C_noret_decl(f_343)
static void C_ccall f_343(C_word c,C_word *av) C_noret;
C_noret_decl(f_347)
static void C_ccall f_347(C_word c,C_word *av) C_noret;
C_noret_decl(f_361)
static void C_ccall f_361(C_word c,C_word *av) C_noret;
C_noret_decl(f_364)
static void C_ccall f_364(C_word c,C_word *av) C_noret;
C_noret_decl(f_377)
static void C_ccall f_377(C_word c,C_word *av) C_noret;
C_noret_decl(f_399)
static void C_fcall f_399(C_word t0,C_word t1) C_noret;
C_noret_decl(f_437)
static void C_ccall f_437(C_word c,C_word *av) C_noret;
C_noret_decl(f_497)
static void C_ccall f_497(C_word c,C_word *av) C_noret;
C_noret_decl(f_501)
static void C_ccall f_501(C_word c,C_word *av) C_noret;
C_noret_decl(f_506)
static void C_ccall f_506(C_word c,C_word *av) C_noret;
C_noret_decl(f_510)
static void C_ccall f_510(C_word c,C_word *av) C_noret;
C_noret_decl(f_520)
static void C_fcall f_520(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_530)
static void C_ccall f_530(C_word c,C_word *av) C_noret;
C_noret_decl(f_533)
static void C_ccall f_533(C_word c,C_word *av) C_noret;
C_noret_decl(f_536)
static void C_ccall f_536(C_word c,C_word *av) C_noret;
C_noret_decl(f_539)
static void C_ccall f_539(C_word c,C_word *av) C_noret;
C_noret_decl(f_542)
static void C_ccall f_542(C_word c,C_word *av) C_noret;
C_noret_decl(f_545)
static void C_ccall f_545(C_word c,C_word *av) C_noret;
C_noret_decl(f_548)
static void C_ccall f_548(C_word c,C_word *av) C_noret;
C_noret_decl(f_551)
static void C_ccall f_551(C_word c,C_word *av) C_noret;
C_noret_decl(f_583)
static void C_fcall f_583(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_593)
static void C_ccall f_593(C_word c,C_word *av) C_noret;
C_noret_decl(f_610)
static void C_ccall f_610(C_word c,C_word *av) C_noret;
C_noret_decl(C_profiler_toplevel)
C_externexport void C_ccall C_profiler_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_399)
static void C_ccall trf_399(C_word c,C_word *av) C_noret;
static void C_ccall trf_399(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_399(t0,t1);}

C_noret_decl(trf_520)
static void C_ccall trf_520(C_word c,C_word *av) C_noret;
static void C_ccall trf_520(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_520(t0,t1,t2);}

C_noret_decl(trf_583)
static void C_ccall trf_583(C_word c,C_word *av) C_noret;
static void C_ccall trf_583(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_583(t0,t1,t2);}

/* k291 */
static void C_ccall f_293(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_293,c,av);}
a=C_alloc(17);
t2=lf[1] /* ##sys#profile-vector-list */ =C_SCHEME_END_OF_LIST;;
t3=lf[2] /* ##sys#profile-name */ =C_SCHEME_FALSE;;
t4=C_set_block_item(lf[3] /* ##sys#profile-append-mode */,0,C_SCHEME_FALSE);
t5=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#register-profile-info ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_301,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[12]+1 /* (set! ##sys#set-profile-info-vector! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_364,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t7=*((C_word*)lf[13]+1);
t8=C_mutate((C_word*)lf[14]+1 /* (set! ##sys#profile-entry ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_377,a[2]=t7,a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp));
t9=C_mutate((C_word*)lf[15]+1 /* (set! ##sys#profile-exit ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_437,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t10=*((C_word*)lf[16]+1);
t11=C_mutate((C_word*)lf[6]+1 /* (set! ##sys#finish-profile ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_497,a[2]=t10,a[3]=((C_word)li9),tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}

/* ##sys#register-profile-info in k291 */
static void C_ccall f_301(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_301,c,av);}
a=C_alloc(10);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_305,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_320,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_stringp(t3))){
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t3;
f_320(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_361,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t7=C_fix((C_word)C_getpid());
/* ##sys#fixnum->string */
t8=*((C_word*)lf[11]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t6;
av2[2]=t7;
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_305(2,av2);}}}

/* k303 in ##sys#register-profile-info in k291 */
static void C_ccall f_305(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_305,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_308,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* profiler.scm:74: scheme#make-vector */
t3=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fixnum_times(((C_word*)t0)[3],C_fix(5));
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k306 in k303 in ##sys#register-profile-info in k291 */
static void C_ccall f_308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_308,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,lf[1]);
t3=C_mutate(&lf[1] /* (set! ##sys#profile-vector-list ...) */,t2);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_320,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[2] /* (set! ##sys#profile-name ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_323,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* profiler.scm:63: chicken.base#exit-handler */
t4=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_323,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_326,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* profiler.scm:64: chicken.base#implicit-exit-handler */
t3=*((C_word*)lf[7]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_326,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_329,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_343,a[2]=((C_word*)t0)[3],a[3]=((C_word)li1),tmp=(C_word)a,a+=4,tmp);
/* profiler.scm:65: chicken.base#exit-handler */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k327 in k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_329,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_334,a[2]=((C_word*)t0)[2],a[3]=((C_word)li0),tmp=(C_word)a,a+=4,tmp);
/* profiler.scm:69: chicken.base#implicit-exit-handler */
t3=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a333 in k327 in k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_334,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_338,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* profiler.scm:71: ##sys#finish-profile */
t3=*((C_word*)lf[6]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k336 in a333 in k327 in k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_338,c,av);}
/* profiler.scm:72: oldieh */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a342 in k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_343(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_343,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_347,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* profiler.scm:67: ##sys#finish-profile */
t4=*((C_word*)lf[6]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k345 in a342 in k324 in k321 in k318 in ##sys#register-profile-info in k291 */
static void C_ccall f_347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_347,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_apply(4,av2);}}

/* k359 in ##sys#register-profile-info in k291 */
static void C_ccall f_361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_361,c,av);}
/* ##sys#string-append */
t2=*((C_word*)lf[9]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[10];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* ##sys#set-profile-info-vector! in k291 */
static void C_ccall f_364(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_364,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_setslot(t2,C_fixnum_times(t3,C_fix(5)),t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* ##sys#profile-entry in k291 */
static void C_ccall f_377(C_word c,C_word *av){
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
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_377,c,av);}
a=C_alloc(7);
t4=C_fixnum_times(t2,C_fix(5));
t5=C_u_fixnum_plus(t4,C_fix(1));
t6=C_slot(t3,t5);
t7=C_u_fixnum_plus(t4,C_fix(2));
t8=C_u_fixnum_plus(t4,C_fix(4));
t9=C_slot(t3,t8);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_399,a[2]=t9,a[3]=t3,a[4]=t7,a[5]=t1,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_not(t6))){
t11=t10;
f_399(t11,C_i_set_i_slot(t3,t5,C_SCHEME_FALSE));}
else{
t11=C_eqp(((C_word*)t0)[2],t6);
t12=t10;
f_399(t12,(C_truep(t11)?C_i_set_i_slot(t3,t5,C_SCHEME_FALSE):C_i_set_i_slot(t3,t5,C_u_fixnum_plus(t6,C_fix(1)))));}}

/* k397 in ##sys#profile-entry in k291 */
static void C_fcall f_399(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,1)))){
C_save_and_reclaim_args((void *)trf_399,2,t0,t1);}
a=C_alloc(9);
t2=C_eqp(C_fix(0),((C_word*)t0)[2]);
if(C_truep(t2)){
t3=C_a_i_bytevector(&a,1,C_fix(7));
t4=C_i_setslot(((C_word*)t0)[3],((C_word*)t0)[4],stub105(t3));
t5=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_i_set_i_slot(((C_word*)t0)[3],((C_word*)t0)[6],C_u_fixnum_plus(((C_word*)t0)[2],C_fix(1)));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t3;
av2[1]=C_i_set_i_slot(((C_word*)t0)[3],((C_word*)t0)[6],C_u_fixnum_plus(((C_word*)t0)[2],C_fix(1)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* ##sys#profile-exit in k291 */
static void C_ccall f_437(C_word c,C_word *av){
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
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(67,c,1)))){
C_save_and_reclaim((void *)f_437,c,av);}
a=C_alloc(67);
t4=C_fixnum_times(t2,C_fix(5));
t5=C_u_fixnum_plus(t4,C_fix(2));
t6=C_u_fixnum_plus(t4,C_fix(3));
t7=C_u_fixnum_plus(t4,C_fix(4));
t8=C_slot(t3,t7);
t9=C_u_fixnum_difference(t8,C_fix(1));
t10=C_i_set_i_slot(t3,t7,t9);
t11=C_eqp(C_fix(0),t9);
if(C_truep(t11)){
t12=C_slot(t3,t6);
t13=C_eqp(t12,C_fix(0));
t14=(C_truep(t13)?C_fix(0):t12);
t15=C_a_i_bytevector(&a,1,C_fix(7));
t16=stub105(t15);
t17=C_slot(t3,t5);
t18=C_s_a_i_minus(&a,2,t16,t17);
t19=C_s_a_i_plus(&a,2,t14,t18);
t20=t1;{
C_word *av2=av;
av2[0]=t20;
av2[1]=C_i_setslot(t3,t6,t19);
((C_proc)(void*)(*((C_word*)t20+1)))(2,av2);}}
else{
t12=C_SCHEME_UNDEFINED;
t13=t1;{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}}

/* ##sys#finish-profile in k291 */
static void C_ccall f_497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_497,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_501,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_debug_modep())){
/* profiler.scm:127: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[23];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_501(2,av2);}}}

/* k499 in ##sys#finish-profile in k291 */
static void C_ccall f_501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_501,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_506,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp);
if(C_truep(*((C_word*)lf[3]+1))){
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[2];
av2[3]=t2;
av2[4]=lf[21];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_506(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_506,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_510,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=*((C_word*)lf[18]+1);
if(C_truep(stub81(C_SCHEME_UNDEFINED,*((C_word*)lf[18]+1)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_610,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* profiler.scm:132: write */
t5=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[20];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_510(2,av2);}}}

/* k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_510,c,av);}
a=C_alloc(6);
t2=lf[1];
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_583,a[2]=t4,a[3]=((C_word)li7),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_583(t6,((C_word*)t0)[2],lf[1]);}

/* doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_fcall f_520(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_520,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_530,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* ##sys#write-char/port */
t4=*((C_word*)lf[17]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_make_character(40);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_530,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_533,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* profiler.scm:140: write */
t3=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[5],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_533,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_536,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_536(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_536,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_539,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_u_fixnum_plus(((C_word*)t0)[4],C_fix(1));
/* profiler.scm:142: write */
t4=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k537 in k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_539,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_542,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k540 in k537 in k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_542(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_542,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_545,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_u_fixnum_plus(((C_word*)t0)[4],C_fix(3));
/* profiler.scm:144: write */
t4=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k543 in k540 in k537 in k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_545,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_548,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(41);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k546 in k543 in k540 in k537 in k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_548,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_551,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k549 in k546 in k543 in k540 in k537 in k534 in k531 in k528 in doloop153 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_551,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_520(t2,((C_word*)t0)[3],C_u_fixnum_plus(((C_word*)t0)[4],C_fix(5)));}

/* for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_fcall f_583(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_583,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_593,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_block_size(t4);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_520,a[2]=t5,a[3]=t7,a[4]=t4,a[5]=((C_word)li6),tmp=(C_word)a,a+=6,tmp));
t9=((C_word*)t7)[1];
f_520(t9,t3,C_fix(0));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k591 in for-each-loop140 in k508 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_593,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_583(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k608 in a505 in k499 in ##sys#finish-profile in k291 */
static void C_ccall f_610(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_610,c,av);}
/* ##sys#write-char/port */
t2=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_profiler_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("profiler"));
C_check_nursery_minimum(C_calculate_demand(11,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void*)C_profiler_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(147))){
C_save(t1);
C_rereclaim2(147*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(11);
C_initialize_lf(lf,25);
lf[0]=C_h_intern(&lf[0],8, C_text("profiler"));
lf[3]=C_h_intern(&lf[3],25, C_text("##sys#profile-append-mode"));
lf[4]=C_h_intern(&lf[4],27, C_text("##sys#register-profile-info"));
lf[5]=C_h_intern(&lf[5],18, C_text("scheme#make-vector"));
lf[6]=C_h_intern(&lf[6],20, C_text("##sys#finish-profile"));
lf[7]=C_h_intern(&lf[7],34, C_text("chicken.base#implicit-exit-handler"));
lf[8]=C_h_intern(&lf[8],25, C_text("chicken.base#exit-handler"));
lf[9]=C_h_intern(&lf[9],19, C_text("##sys#string-append"));
lf[10]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010PROFILE."));
lf[11]=C_h_intern(&lf[11],20, C_text("##sys#fixnum->string"));
lf[12]=C_h_intern(&lf[12],30, C_text("##sys#set-profile-info-vector!"));
lf[13]=C_h_intern(&lf[13],35, C_text("chicken.fixnum#most-positive-fixnum"));
lf[14]=C_h_intern(&lf[14],19, C_text("##sys#profile-entry"));
lf[15]=C_h_intern(&lf[15],18, C_text("##sys#profile-exit"));
lf[16]=C_h_intern(&lf[16],26, C_text("scheme#with-output-to-file"));
lf[17]=C_h_intern(&lf[17],21, C_text("##sys#write-char/port"));
lf[18]=C_h_intern(&lf[18],21, C_text("##sys#standard-output"));
lf[19]=C_h_intern(&lf[19],12, C_text("scheme#write"));
lf[20]=C_h_intern(&lf[20],12, C_text("instrumented"));
lf[21]=C_h_intern_kw(&lf[21],6, C_text("append"));
lf[22]=C_h_intern(&lf[22],11, C_text("##sys#print"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033[debug] writing profile...\012"));
lf[24]=C_h_intern(&lf[24],20, C_text("##sys#standard-error"));
C_register_lf2(lf,25,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_293,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[35] = {
{C_text("f_293:profiler_2escm"),(void*)f_293},
{C_text("f_301:profiler_2escm"),(void*)f_301},
{C_text("f_305:profiler_2escm"),(void*)f_305},
{C_text("f_308:profiler_2escm"),(void*)f_308},
{C_text("f_320:profiler_2escm"),(void*)f_320},
{C_text("f_323:profiler_2escm"),(void*)f_323},
{C_text("f_326:profiler_2escm"),(void*)f_326},
{C_text("f_329:profiler_2escm"),(void*)f_329},
{C_text("f_334:profiler_2escm"),(void*)f_334},
{C_text("f_338:profiler_2escm"),(void*)f_338},
{C_text("f_343:profiler_2escm"),(void*)f_343},
{C_text("f_347:profiler_2escm"),(void*)f_347},
{C_text("f_361:profiler_2escm"),(void*)f_361},
{C_text("f_364:profiler_2escm"),(void*)f_364},
{C_text("f_377:profiler_2escm"),(void*)f_377},
{C_text("f_399:profiler_2escm"),(void*)f_399},
{C_text("f_437:profiler_2escm"),(void*)f_437},
{C_text("f_497:profiler_2escm"),(void*)f_497},
{C_text("f_501:profiler_2escm"),(void*)f_501},
{C_text("f_506:profiler_2escm"),(void*)f_506},
{C_text("f_510:profiler_2escm"),(void*)f_510},
{C_text("f_520:profiler_2escm"),(void*)f_520},
{C_text("f_530:profiler_2escm"),(void*)f_530},
{C_text("f_533:profiler_2escm"),(void*)f_533},
{C_text("f_536:profiler_2escm"),(void*)f_536},
{C_text("f_539:profiler_2escm"),(void*)f_539},
{C_text("f_542:profiler_2escm"),(void*)f_542},
{C_text("f_545:profiler_2escm"),(void*)f_545},
{C_text("f_548:profiler_2escm"),(void*)f_548},
{C_text("f_551:profiler_2escm"),(void*)f_551},
{C_text("f_583:profiler_2escm"),(void*)f_583},
{C_text("f_593:profiler_2escm"),(void*)f_593},
{C_text("f_610:profiler_2escm"),(void*)f_610},
{C_text("toplevel:profiler_2escm"),(void*)C_profiler_toplevel},
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
S|applied compiler syntax:
S|  scheme#for-each		1
o|eliminated procedure checks: 19 
o|specializations:
o|  1 (scheme#current-output-port)
o|  1 (##sys#debug-mode?)
o|  1 (scheme#string-append string string)
o|  1 (scheme#number->string fixnum)
(o e)|safe calls: 64 
(o e)|assignments to immediate values: 1 
o|substituted constant variable: a357 
o|inlining procedure: "(profiler.scm:101) cpu-ms" 
o|inlining procedure: k421 
o|inlining procedure: k421 
o|inlining procedure: k457 
o|inlining procedure: "(profiler.scm:116) cpu-ms" 
o|inlining procedure: k457 
o|inlining procedure: k522 
o|inlining procedure: k522 
o|inlining procedure: k585 
o|inlining procedure: k585 
o|propagated global variable: g147150 ##sys#profile-vector-list 
o|contracted procedure: "(profiler.scm:131) empty-file?" 
o|propagated global variable: p8083 ##sys#standard-output 
o|inlining procedure: k615 
o|inlining procedure: k615 
o|replaced variables: 73 
o|removed binding forms: 36 
o|removed side-effect free assignment to unused variable: cpu-ms 
o|substituted constant variable: r422623 
o|substituted constant variable: r422623 
o|inlining procedure: k421 
o|contracted procedure: "(profiler.scm:134) g141149" 
o|substituted constant variable: r616635 
o|substituted constant variable: r616635 
o|substituted constant variable: r616637 
o|substituted constant variable: r616637 
o|replaced variables: 3 
o|removed binding forms: 62 
o|inlining procedure: k417 
o|substituted constant variable: r422639 
o|replaced variables: 5 
o|removed binding forms: 11 
o|contracted procedure: k482 
o|contracted procedure: k605 
o|simplifications: ((let . 1)) 
o|removed binding forms: 6 
o|simplifications: ((if . 1) (let . 1) (##core#call . 55)) 
o|  call simplifications:
o|    scheme#pair?
o|    ##sys#size
o|    chicken.fixnum#fx>=
o|    scheme#write-char	6
o|    chicken.fixnum#fx-
o|    scheme#-
o|    scheme#+
o|    ##sys#slot	10
o|    scheme#not
o|    scheme#eq?	4
o|    chicken.fixnum#fx+	11
o|    ##sys#setislot	5
o|    ##sys#setslot	3
o|    scheme#string?
o|    scheme#apply	3
o|    chicken.fixnum#fx*	4
o|    scheme#cons
o|contracted procedure: k310 
o|contracted procedure: k314 
o|contracted procedure: k351 
o|contracted procedure: k370 
o|contracted procedure: k379 
o|contracted procedure: k382 
o|contracted procedure: k385 
o|contracted procedure: k388 
o|contracted procedure: k391 
o|contracted procedure: k394 
o|contracted procedure: k407 
o|contracted procedure: k410 
o|contracted procedure: k424 
o|contracted procedure: k430 
o|contracted procedure: k421 
o|contracted procedure: k439 
o|contracted procedure: k442 
o|contracted procedure: k445 
o|contracted procedure: k448 
o|contracted procedure: k493 
o|contracted procedure: k451 
o|contracted procedure: k454 
o|contracted procedure: k460 
o|contracted procedure: k463 
o|contracted procedure: k489 
o|contracted procedure: k474 
o|contracted procedure: k486 
o|contracted procedure: k478 
o|contracted procedure: k470 
o|contracted procedure: k588 
o|contracted procedure: k598 
o|contracted procedure: k602 
o|contracted procedure: k513 
o|contracted procedure: k525 
o|contracted procedure: k556 
o|contracted procedure: k564 
o|contracted procedure: k560 
o|contracted procedure: k572 
o|contracted procedure: k568 
o|contracted procedure: k576 
o|simplifications: ((if . 1) (let . 13)) 
o|removed binding forms: 40 
o|inlining procedure: k400 
o|inlining procedure: k400 
o|removed binding forms: 2 
o|customizable procedures: (doloop153154 for-each-loop140165 k397) 
o|calls to known targets: 10 
o|fast box initializations: 2 
o|fast global references: 5 
o|fast global assignments: 4 
*/
/* end of file */
