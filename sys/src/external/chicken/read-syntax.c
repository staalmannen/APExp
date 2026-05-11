/* Generated from read-syntax.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: read-syntax.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file read-syntax.c -emit-import-library chicken.read-syntax
   unit: read-syntax
   uses: internal library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[34];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,16),40,102,95,51,49,52,32,99,104,114,32,112,114,111,99,41};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,114,101,97,100,45,115,121,110,116,97,120,35,115,121,110,116,97,120,45,115,101,116,116,101,114,32,108,111,99,32,115,108,111,116,32,119,114,97,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,114,101,97,100,45,115,121,110,116,97,120,35,99,111,112,121,45,114,101,97,100,45,116,97,98,108,101,32,114,116,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,50),40,99,104,105,99,107,101,110,46,114,101,97,100,45,115,121,110,116,97,120,35,100,101,102,105,110,101,45,114,101,97,100,101,114,45,99,116,111,114,32,115,112,101,99,32,112,114,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,5),40,101,114,114,41,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,117,115,101,114,45,114,101,97,100,45,104,111,111,107,32,99,104,97,114,32,112,111,114,116,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,18),40,102,95,53,51,48,32,95,32,112,111,114,116,32,110,117,109,41,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,11),40,97,53,50,55,32,112,114,111,99,41,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,14),40,102,95,53,52,49,32,95,32,112,111,114,116,41,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,11),40,97,53,51,56,32,112,114,111,99,41,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,14),40,102,95,53,53,50,32,95,32,112,111,114,116,41,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,11),40,97,53,52,57,32,112,114,111,99,41,0,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_286)
static void C_ccall f_286(C_word c,C_word *av) C_noret;
C_noret_decl(f_289)
static void C_ccall f_289(C_word c,C_word *av) C_noret;
C_noret_decl(f_312)
static void C_fcall f_312(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_314)
static void C_ccall f_314(C_word c,C_word *av) C_noret;
C_noret_decl(f_327)
static void C_ccall f_327(C_word c,C_word *av) C_noret;
C_noret_decl(f_330)
static void C_fcall f_330(C_word t0,C_word t1) C_noret;
C_noret_decl(f_339)
static void C_ccall f_339(C_word c,C_word *av) C_noret;
C_noret_decl(f_345)
static void C_ccall f_345(C_word c,C_word *av) C_noret;
C_noret_decl(f_356)
static void C_ccall f_356(C_word c,C_word *av) C_noret;
C_noret_decl(f_373)
static void C_ccall f_373(C_word c,C_word *av) C_noret;
C_noret_decl(f_377)
static void C_ccall f_377(C_word c,C_word *av) C_noret;
C_noret_decl(f_381)
static void C_ccall f_381(C_word c,C_word *av) C_noret;
C_noret_decl(f_385)
static void C_ccall f_385(C_word c,C_word *av) C_noret;
C_noret_decl(f_387)
static void C_ccall f_387(C_word c,C_word *av) C_noret;
C_noret_decl(f_401)
static void C_ccall f_401(C_word c,C_word *av) C_noret;
C_noret_decl(f_408)
static void C_ccall f_408(C_word c,C_word *av) C_noret;
C_noret_decl(f_415)
static void C_ccall f_415(C_word c,C_word *av) C_noret;
C_noret_decl(f_440)
static void C_ccall f_440(C_word c,C_word *av) C_noret;
C_noret_decl(f_442)
static void C_ccall f_442(C_word c,C_word *av) C_noret;
C_noret_decl(f_451)
static void C_ccall f_451(C_word c,C_word *av) C_noret;
C_noret_decl(f_461)
static void C_ccall f_461(C_word c,C_word *av) C_noret;
C_noret_decl(f_464)
static void C_ccall f_464(C_word c,C_word *av) C_noret;
C_noret_decl(f_465)
static void C_fcall f_465(C_word t0,C_word t1) C_noret;
C_noret_decl(f_496)
static void C_ccall f_496(C_word c,C_word *av) C_noret;
C_noret_decl(f_526)
static void C_ccall f_526(C_word c,C_word *av) C_noret;
C_noret_decl(f_528)
static void C_ccall f_528(C_word c,C_word *av) C_noret;
C_noret_decl(f_530)
static void C_ccall f_530(C_word c,C_word *av) C_noret;
C_noret_decl(f_534)
static void C_ccall f_534(C_word c,C_word *av) C_noret;
C_noret_decl(f_539)
static void C_ccall f_539(C_word c,C_word *av) C_noret;
C_noret_decl(f_541)
static void C_ccall f_541(C_word c,C_word *av) C_noret;
C_noret_decl(f_545)
static void C_ccall f_545(C_word c,C_word *av) C_noret;
C_noret_decl(f_550)
static void C_ccall f_550(C_word c,C_word *av) C_noret;
C_noret_decl(f_552)
static void C_ccall f_552(C_word c,C_word *av) C_noret;
C_noret_decl(f_556)
static void C_ccall f_556(C_word c,C_word *av) C_noret;
C_noret_decl(C_read_2dsyntax_toplevel)
C_externexport void C_ccall C_read_2dsyntax_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_312)
static void C_ccall trf_312(C_word c,C_word *av) C_noret;
static void C_ccall trf_312(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_312(t0,t1,t2,t3);}

C_noret_decl(trf_330)
static void C_ccall trf_330(C_word c,C_word *av) C_noret;
static void C_ccall trf_330(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_330(t0,t1);}

C_noret_decl(trf_465)
static void C_ccall trf_465(C_word c,C_word *av) C_noret;
static void C_ccall trf_465(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_465(t0,t1);}

/* k284 */
static void C_ccall f_286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_286,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_289,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k287 in k284 */
static void C_ccall f_289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_289,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[2]+1 /* (set! chicken.read-syntax#current-read-table ...) */,*((C_word*)lf[3]+1));
t3=C_mutate(&lf[4] /* (set! chicken.read-syntax#syntax-setter ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_312,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_377,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_550,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp);
/* read-syntax.scm:64: syntax-setter */
f_312(t4,lf[33],C_fix(1),t5);}

/* chicken.read-syntax#syntax-setter in k287 in k284 */
static void C_fcall f_312(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_312,4,t1,t2,t3,t4);}
a=C_alloc(6);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_314,a[2]=t2,a[3]=t3,a[4]=t4,a[5]=((C_word)li0),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* f_314 in chicken.read-syntax#syntax-setter in k287 in k284 */
static void C_ccall f_314(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_314,c,av);}
a=C_alloc(8);
if(C_truep(C_i_symbolp(t2))){
t4=C_i_assq(t2,*((C_word*)lf[5]+1));
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_setslot(t4,C_fix(1),t3);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_a_i_cons(&a,2,t2,t3);
t6=C_a_i_cons(&a,2,t5,*((C_word*)lf[5]+1));
t7=C_mutate((C_word*)lf[5]+1 /* (set! ##sys#read-marks ...) */,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_327,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=((C_word*)t0)[3],a[6]=t1,a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
/* read-syntax.scm:51: current-read-table */
t5=*((C_word*)lf[2]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k325 */
static void C_ccall f_327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_327,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_330,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_slot(t1,((C_word*)t0)[5]))){
t3=t2;
f_330(t3,C_SCHEME_UNDEFINED);}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_373,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* read-syntax.scm:53: ##sys#make-vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[8]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[8]+1);
av2[1]=t3;
av2[2]=C_fix(256);
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}}

/* k328 in k325 */
static void C_fcall f_330(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_330,2,t0,t1);}
a=C_alloc(9);
t2=C_i_check_char_2(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_fix(C_character_code(((C_word*)t0)[2]));
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_339,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t3,a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[3],tmp=(C_word)a,a+=9,tmp);
/* read-syntax.scm:56: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
av2[4]=C_fix(256);
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}

/* k337 in k328 in k325 */
static void C_ccall f_339(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_339,c,av);}
a=C_alloc(8);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_345,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* read-syntax.scm:58: ##sys#check-closure */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_i_slot(C_slot(((C_word*)t0)[3],((C_word*)t0)[4]),((C_word*)t0)[6],C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k343 in k337 in k328 in k325 */
static void C_ccall f_345(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_345,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_356,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* read-syntax.scm:59: wrap */
t4=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k354 in k343 in k337 in k328 in k325 */
static void C_ccall f_356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_356,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_setslot(((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k371 in k325 */
static void C_ccall f_373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_373,c,av);}
t2=((C_word*)t0)[2];
f_330(t2,C_i_setslot(((C_word*)t0)[3],((C_word*)t0)[4],t1));}

/* k375 in k287 in k284 */
static void C_ccall f_377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_377,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[9]+1 /* (set! chicken.read-syntax#set-read-syntax! ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_381,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_539,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp);
/* read-syntax.scm:72: syntax-setter */
f_312(t3,lf[32],C_fix(2),t4);}

/* k379 in k375 in k287 in k284 */
static void C_ccall f_381(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_381,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[10]+1 /* (set! chicken.read-syntax#set-sharp-read-syntax! ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_385,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_528,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp);
/* read-syntax.scm:80: syntax-setter */
f_312(t3,lf[31],C_fix(3),t4);}

/* k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_385,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[11]+1 /* (set! chicken.read-syntax#set-parameterized-read-syntax! ...) */,t1);
t3=C_mutate((C_word*)lf[12]+1 /* (set! chicken.read-syntax#copy-read-table ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_387,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_440,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* read-syntax.scm:102: scheme#make-vector */
t5=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_fix(301);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* chicken.read-syntax#copy-read-table in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_387,c,av);}
a=C_alloc(4);
t3=C_i_check_structure_2(t2,lf[13],lf[14]);
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_401,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* read-syntax.scm:94: ##sys#vector-resize */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[15]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t5;
av2[2]=t4;
av2[3]=C_block_size(t4);
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_401(2,av2);}}}

/* k399 in chicken.read-syntax#copy-read-table in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_401(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_401,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_408,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t2)){
/* read-syntax.scm:96: ##sys#vector-resize */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[15]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=C_block_size(t2);
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_408(2,av2);}}}

/* k406 in k399 in chicken.read-syntax#copy-read-table in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_408,c,av);}
a=C_alloc(10);
t2=C_slot(((C_word*)t0)[2],C_fix(3));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_415,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t2)){
/* read-syntax.scm:98: ##sys#vector-resize */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[15]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=C_block_size(t2);
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_record4(&a,4,lf[13],((C_word*)t0)[4],t1,C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k413 in k406 in k399 in chicken.read-syntax#copy-read-table in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_415,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[13],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_440(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_440,c,av);}
a=C_alloc(10);
t2=C_mutate(&lf[16] /* (set! chicken.read-syntax#sharp-comma-reader-ctors ...) */,t1);
t3=C_mutate((C_word*)lf[17]+1 /* (set! chicken.read-syntax#define-reader-ctor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_442,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t4=*((C_word*)lf[20]+1);
t5=C_mutate((C_word*)lf[20]+1 /* (set! ##sys#user-read-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_451,a[2]=t4,a[3]=((C_word)li5),tmp=(C_word)a,a+=4,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_526,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* read-syntax.scm:128: chicken.platform#register-feature! */
t7=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[28];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* chicken.read-syntax#define-reader-ctor in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_442(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_442,c,av);}
t4=C_i_check_symbol_2(t2,lf[18]);
/* read-syntax.scm:106: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[19]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[19]+1);
av2[1]=t1;
av2[2]=lf[16];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}

/* ##sys#user-read-hook in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_451,c,av);}
a=C_alloc(4);
if(C_truep(C_i_char_equalp(t2,C_make_character(44)))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_461,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* ##sys#read-char/port */
t5=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
/* read-syntax.scm:126: old */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k459 in ##sys#user-read-hook in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_461,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_464,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* read-syntax.scm:115: read */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k462 in k459 in ##sys#user-read-hook in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_464(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_464,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_465,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li4),tmp=(C_word)a,a+=5,tmp);
t3=C_i_nullp(t1);
t4=(C_truep(t3)?t3:C_i_not(C_i_listp(t1)));
if(C_truep(t4)){
/* read-syntax.scm:118: err */
t5=t2;
f_465(t5,((C_word*)t0)[3]);}
else{
t5=C_slot(t1,C_fix(0));
t6=C_i_symbolp(t5);
if(C_truep(C_i_not(t6))){
/* read-syntax.scm:121: err */
t7=t2;
f_465(t7,((C_word*)t0)[3]);}
else{
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_496,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* read-syntax.scm:122: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[24]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[24]+1);
av2[1]=t7;
av2[2]=lf[16];
av2[3]=t5;
tp(4,av2);}}}}

/* err in k462 in k459 in ##sys#user-read-hook in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_fcall f_465(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_465,2,t0,t1);}
/* read-syntax.scm:116: ##sys#read-error */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[21]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[21]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[22];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}

/* k494 in k462 in k459 in ##sys#user-read-hook in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_496,c,av);}
if(C_truep(t1)){{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_slot(((C_word*)t0)[3],C_fix(1));
C_apply(4,av2);}}
else{
/* read-syntax.scm:125: ##sys#read-error */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[21]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[21]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[23];
av2[4]=((C_word*)t0)[5];
tp(5,av2);}}}

/* k524 in k438 in k383 in k379 in k375 in k287 in k284 */
static void C_ccall f_526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_526,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a527 in k379 in k375 in k287 in k284 */
static void C_ccall f_528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_528,c,av);}
a=C_alloc(4);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_530,a[2]=t2,a[3]=((C_word)li6),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_530 in a527 in k379 in k375 in k287 in k284 */
static void C_ccall f_530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_530,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_534,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* read-syntax.scm:84: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t5;
av2[2]=t3;
tp(3,av2);}}

/* k532 */
static void C_ccall f_534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_534,c,av);}
/* read-syntax.scm:85: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* a538 in k375 in k287 in k284 */
static void C_ccall f_539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_539,c,av);}
a=C_alloc(4);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_541,a[2]=t2,a[3]=((C_word)li8),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_541 in a538 in k375 in k287 in k284 */
static void C_ccall f_541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_541,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_545,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* read-syntax.scm:76: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t4;
av2[2]=t3;
tp(3,av2);}}

/* k543 */
static void C_ccall f_545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_545,c,av);}
/* read-syntax.scm:77: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a549 in k287 in k284 */
static void C_ccall f_550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_550,c,av);}
a=C_alloc(4);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_552,a[2]=t2,a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_552 in a549 in k287 in k284 */
static void C_ccall f_552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_552,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_556,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* read-syntax.scm:68: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t4;
av2[2]=t3;
tp(3,av2);}}

/* k554 */
static void C_ccall f_556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_556,c,av);}
/* read-syntax.scm:69: proc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_read_2dsyntax_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("read-syntax"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_read_2dsyntax_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(210))){
C_save(t1);
C_rereclaim2(210*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,34);
lf[0]=C_h_intern(&lf[0],11, C_text("read-syntax"));
lf[1]=C_h_intern(&lf[1],20, C_text("chicken.read-syntax#"));
lf[2]=C_h_intern(&lf[2],38, C_text("chicken.read-syntax#current-read-table"));
lf[3]=C_h_intern(&lf[3],24, C_text("##sys#current-read-table"));
lf[5]=C_h_intern(&lf[5],16, C_text("##sys#read-marks"));
lf[6]=C_h_intern(&lf[6],19, C_text("##sys#check-closure"));
lf[7]=C_h_intern(&lf[7],17, C_text("##sys#check-range"));
lf[8]=C_h_intern(&lf[8],17, C_text("##sys#make-vector"));
lf[9]=C_h_intern(&lf[9],36, C_text("chicken.read-syntax#set-read-syntax!"));
lf[10]=C_h_intern(&lf[10],42, C_text("chicken.read-syntax#set-sharp-read-syntax!"));
lf[11]=C_h_intern(&lf[11],50, C_text("chicken.read-syntax#set-parameterized-read-syntax!"));
lf[12]=C_h_intern(&lf[12],35, C_text("chicken.read-syntax#copy-read-table"));
lf[13]=C_h_intern(&lf[13],10, C_text("read-table"));
lf[14]=C_h_intern(&lf[14],15, C_text("copy-read-table"));
lf[15]=C_h_intern(&lf[15],19, C_text("##sys#vector-resize"));
lf[17]=C_h_intern(&lf[17],38, C_text("chicken.read-syntax#define-reader-ctor"));
lf[18]=C_h_intern(&lf[18],18, C_text("define-reader-ctor"));
lf[19]=C_h_intern(&lf[19],32, C_text("chicken.internal#hash-table-set!"));
lf[20]=C_h_intern(&lf[20],20, C_text("##sys#user-read-hook"));
lf[21]=C_h_intern(&lf[21],16, C_text("##sys#read-error"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000!invalid sharp-comma external form"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000!undefined sharp-comma constructor"));
lf[24]=C_h_intern(&lf[24],31, C_text("chicken.internal#hash-table-ref"));
lf[25]=C_h_intern(&lf[25],11, C_text("scheme#read"));
lf[26]=C_h_intern(&lf[26],20, C_text("##sys#read-char/port"));
lf[27]=C_h_intern(&lf[27],34, C_text("chicken.platform#register-feature!"));
lf[28]=C_h_intern(&lf[28],7, C_text("srfi-10"));
lf[29]=C_h_intern(&lf[29],18, C_text("scheme#make-vector"));
lf[30]=C_h_intern(&lf[30],17, C_text("##sys#read-char-0"));
lf[31]=C_h_intern(&lf[31],30, C_text("set-parameterized-read-syntax!"));
lf[32]=C_h_intern(&lf[32],22, C_text("set-sharp-read-syntax!"));
lf[33]=C_h_intern(&lf[33],16, C_text("set-read-syntax!"));
C_register_lf2(lf,34,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_286,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[36] = {
{C_text("f_286:read_2dsyntax_2escm"),(void*)f_286},
{C_text("f_289:read_2dsyntax_2escm"),(void*)f_289},
{C_text("f_312:read_2dsyntax_2escm"),(void*)f_312},
{C_text("f_314:read_2dsyntax_2escm"),(void*)f_314},
{C_text("f_327:read_2dsyntax_2escm"),(void*)f_327},
{C_text("f_330:read_2dsyntax_2escm"),(void*)f_330},
{C_text("f_339:read_2dsyntax_2escm"),(void*)f_339},
{C_text("f_345:read_2dsyntax_2escm"),(void*)f_345},
{C_text("f_356:read_2dsyntax_2escm"),(void*)f_356},
{C_text("f_373:read_2dsyntax_2escm"),(void*)f_373},
{C_text("f_377:read_2dsyntax_2escm"),(void*)f_377},
{C_text("f_381:read_2dsyntax_2escm"),(void*)f_381},
{C_text("f_385:read_2dsyntax_2escm"),(void*)f_385},
{C_text("f_387:read_2dsyntax_2escm"),(void*)f_387},
{C_text("f_401:read_2dsyntax_2escm"),(void*)f_401},
{C_text("f_408:read_2dsyntax_2escm"),(void*)f_408},
{C_text("f_415:read_2dsyntax_2escm"),(void*)f_415},
{C_text("f_440:read_2dsyntax_2escm"),(void*)f_440},
{C_text("f_442:read_2dsyntax_2escm"),(void*)f_442},
{C_text("f_451:read_2dsyntax_2escm"),(void*)f_451},
{C_text("f_461:read_2dsyntax_2escm"),(void*)f_461},
{C_text("f_464:read_2dsyntax_2escm"),(void*)f_464},
{C_text("f_465:read_2dsyntax_2escm"),(void*)f_465},
{C_text("f_496:read_2dsyntax_2escm"),(void*)f_496},
{C_text("f_526:read_2dsyntax_2escm"),(void*)f_526},
{C_text("f_528:read_2dsyntax_2escm"),(void*)f_528},
{C_text("f_530:read_2dsyntax_2escm"),(void*)f_530},
{C_text("f_534:read_2dsyntax_2escm"),(void*)f_534},
{C_text("f_539:read_2dsyntax_2escm"),(void*)f_539},
{C_text("f_541:read_2dsyntax_2escm"),(void*)f_541},
{C_text("f_545:read_2dsyntax_2escm"),(void*)f_545},
{C_text("f_550:read_2dsyntax_2escm"),(void*)f_550},
{C_text("f_552:read_2dsyntax_2escm"),(void*)f_552},
{C_text("f_556:read_2dsyntax_2escm"),(void*)f_556},
{C_text("toplevel:read_2dsyntax_2escm"),(void*)C_read_2dsyntax_toplevel},
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
o|hiding unexported module binding: chicken.read-syntax#d 
o|hiding unexported module binding: chicken.read-syntax#define-alias 
o|hiding unexported module binding: chicken.read-syntax#set-read-mark! 
o|hiding unexported module binding: chicken.read-syntax#syntax-setter 
o|hiding unexported module binding: chicken.read-syntax#sharp-comma-reader-ctors 
o|eliminated procedure checks: 12 
(o e)|safe calls: 41 
o|safe globals: (chicken.read-syntax#syntax-setter chicken.read-syntax#current-read-table chicken.read-syntax#set-read-mark!) 
o|inlining procedure: k316 
o|contracted procedure: "(read-syntax.scm:50) chicken.read-syntax#set-read-mark!" 
o|inlining procedure: k296 
o|inlining procedure: k296 
o|inlining procedure: k316 
o|inlining procedure: k413 
o|inlining procedure: k413 
o|inlining procedure: k453 
o|inlining procedure: k485 
o|inlining procedure: k485 
o|inlining procedure: k453 
o|replaced variables: 78 
o|removed binding forms: 26 
o|substituted constant variable: r414566 
o|substituted constant variable: r414566 
o|replaced variables: 7 
o|removed binding forms: 54 
o|removed binding forms: 6 
o|simplifications: ((##core#call . 33)) 
o|  call simplifications:
o|    scheme#char=?
o|    scheme#read-char
o|    scheme#null?
o|    scheme#list?
o|    scheme#not	2
o|    scheme#apply
o|    ##sys#check-symbol
o|    ##sys#check-structure
o|    ##sys#size	3
o|    ##sys#make-structure	2
o|    scheme#symbol?	2
o|    ##sys#check-char
o|    scheme#char->integer
o|    ##sys#slot	8
o|    scheme#assq
o|    scheme#cons	2
o|    ##sys#setslot	4
o|contracted procedure: k319 
o|contracted procedure: k293 
o|contracted procedure: k307 
o|contracted procedure: k303 
o|contracted procedure: k331 
o|contracted procedure: k334 
o|contracted procedure: k350 
o|contracted procedure: k361 
o|contracted procedure: k364 
o|contracted procedure: k389 
o|contracted procedure: k396 
o|contracted procedure: k403 
o|contracted procedure: k410 
o|contracted procedure: k420 
o|contracted procedure: k427 
o|contracted procedure: k434 
o|contracted procedure: k444 
o|contracted procedure: k456 
o|contracted procedure: k473 
o|contracted procedure: k482 
o|contracted procedure: k511 
o|contracted procedure: k488 
o|contracted procedure: k504 
o|contracted procedure: k518 
o|simplifications: ((if . 1) (let . 10)) 
o|removed binding forms: 24 
o|contracted procedure: k476 
o|removed binding forms: 1 
o|customizable procedures: (chicken.read-syntax#syntax-setter err149 k328) 
o|calls to known targets: 9 
o|fast global references: 5 
o|fast global assignments: 2 
o|dropping unused closure argument: f_312 
*/
/* end of file */
