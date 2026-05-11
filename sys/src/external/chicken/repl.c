/* Generated from repl.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: repl.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file repl.c -emit-import-library chicken.repl
   unit: repl
   uses: expand eval library
*/
#include "chicken.h"

static C_word code_263() { C_clear_trace_buffer();
; return C_SCHEME_UNDEFINED; }


static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[60];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,6),40,97,52,56,49,41,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,30),40,35,35,115,121,115,35,114,101,112,108,45,112,114,105,110,116,45,104,111,111,107,32,120,32,112,111,114,116,41,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,114,101,112,108,35,113,117,105,116,45,104,111,111,107,32,114,101,115,117,108,116,41,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,26),40,99,104,105,99,107,101,110,46,114,101,112,108,35,113,117,105,116,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,20),40,99,104,105,99,107,101,110,46,114,101,112,108,35,114,101,115,101,116,41,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,24),40,35,35,115,121,115,35,114,101,97,100,45,112,114,111,109,112,116,45,104,111,111,107,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,29),40,35,35,115,121,115,35,114,101,115,105,122,101,45,116,114,97,99,101,45,98,117,102,102,101,114,32,105,41,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,53,54,32,103,49,54,51,41,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,14),40,119,114,105,116,101,45,101,114,114,32,120,115,41,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,114,101,112,108,35,113,117,105,116,45,104,111,111,107,32,114,101,115,117,108,116,41,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,17),40,97,55,49,52,32,109,115,103,32,46,32,97,114,103,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,6),40,97,54,57,52,41,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,6),40,97,56,51,48,41,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,56,54,32,103,49,57,51,41,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,55,54,32,103,50,56,51,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,13),40,108,111,111,112,32,118,97,114,115,32,117,41,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,15),40,97,56,51,54,32,46,32,114,101,115,117,108,116,41,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,6),40,97,57,57,52,41,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,8),40,97,57,56,56,32,99,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,6),40,97,55,57,51,41,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,7),40,97,49,48,48,52,41,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,8),40,97,54,56,56,32,107,41};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,26),40,99,104,105,99,107,101,110,46,114,101,112,108,35,114,101,112,108,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,7),40,97,49,48,50,53,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1005)
static void C_ccall f_1005(C_word c,C_word *av) C_noret;
C_noret_decl(f_1009)
static void C_ccall f_1009(C_word c,C_word *av) C_noret;
C_noret_decl(f_1015)
static void C_ccall f_1015(C_word c,C_word *av) C_noret;
C_noret_decl(f_1026)
static void C_ccall f_1026(C_word c,C_word *av) C_noret;
C_noret_decl(f_462)
static void C_ccall f_462(C_word c,C_word *av) C_noret;
C_noret_decl(f_465)
static void C_ccall f_465(C_word c,C_word *av) C_noret;
C_noret_decl(f_468)
static void C_ccall f_468(C_word c,C_word *av) C_noret;
C_noret_decl(f_473)
static void C_ccall f_473(C_word c,C_word *av) C_noret;
C_noret_decl(f_477)
static void C_ccall f_477(C_word c,C_word *av) C_noret;
C_noret_decl(f_482)
static void C_ccall f_482(C_word c,C_word *av) C_noret;
C_noret_decl(f_488)
static void C_ccall f_488(C_word c,C_word *av) C_noret;
C_noret_decl(f_494)
static void C_ccall f_494(C_word c,C_word *av) C_noret;
C_noret_decl(f_510)
static void C_ccall f_510(C_word c,C_word *av) C_noret;
C_noret_decl(f_514)
static void C_ccall f_514(C_word c,C_word *av) C_noret;
C_noret_decl(f_521)
static void C_ccall f_521(C_word c,C_word *av) C_noret;
C_noret_decl(f_523)
static void C_ccall f_523(C_word c,C_word *av) C_noret;
C_noret_decl(f_527)
static void C_ccall f_527(C_word c,C_word *av) C_noret;
C_noret_decl(f_534)
static void C_ccall f_534(C_word c,C_word *av) C_noret;
C_noret_decl(f_537)
static void C_ccall f_537(C_word c,C_word *av) C_noret;
C_noret_decl(f_539)
static void C_ccall f_539(C_word c,C_word *av) C_noret;
C_noret_decl(f_543)
static void C_ccall f_543(C_word c,C_word *av) C_noret;
C_noret_decl(f_545)
static void C_ccall f_545(C_word c,C_word *av) C_noret;
C_noret_decl(f_551)
static void C_fcall f_551(C_word t0,C_word t1) C_noret;
C_noret_decl(f_565)
static void C_fcall f_565(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_575)
static void C_ccall f_575(C_word c,C_word *av) C_noret;
C_noret_decl(f_612)
static void C_ccall f_612(C_word c,C_word *av) C_noret;
C_noret_decl(f_625)
static void C_ccall f_625(C_word c,C_word *av) C_noret;
C_noret_decl(f_629)
static void C_ccall f_629(C_word c,C_word *av) C_noret;
C_noret_decl(f_637)
static void C_fcall f_637(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_647)
static void C_ccall f_647(C_word c,C_word *av) C_noret;
C_noret_decl(f_669)
static void C_ccall f_669(C_word c,C_word *av) C_noret;
C_noret_decl(f_672)
static void C_ccall f_672(C_word c,C_word *av) C_noret;
C_noret_decl(f_674)
static C_word C_fcall f_674(C_word t0);
C_noret_decl(f_680)
static C_word C_fcall f_680(C_word t0);
C_noret_decl(f_689)
static void C_ccall f_689(C_word c,C_word *av) C_noret;
C_noret_decl(f_695)
static void C_ccall f_695(C_word c,C_word *av) C_noret;
C_noret_decl(f_700)
static void C_ccall f_700(C_word c,C_word *av) C_noret;
C_noret_decl(f_702)
static void C_ccall f_702(C_word c,C_word *av) C_noret;
C_noret_decl(f_709)
static void C_ccall f_709(C_word c,C_word *av) C_noret;
C_noret_decl(f_715)
static void C_ccall f_715(C_word c,C_word *av) C_noret;
C_noret_decl(f_722)
static void C_ccall f_722(C_word c,C_word *av) C_noret;
C_noret_decl(f_725)
static void C_ccall f_725(C_word c,C_word *av) C_noret;
C_noret_decl(f_728)
static void C_ccall f_728(C_word c,C_word *av) C_noret;
C_noret_decl(f_732)
static void C_fcall f_732(C_word t0,C_word t1) C_noret;
C_noret_decl(f_735)
static void C_ccall f_735(C_word c,C_word *av) C_noret;
C_noret_decl(f_738)
static void C_ccall f_738(C_word c,C_word *av) C_noret;
C_noret_decl(f_769)
static void C_ccall f_769(C_word c,C_word *av) C_noret;
C_noret_decl(f_775)
static void C_ccall f_775(C_word c,C_word *av) C_noret;
C_noret_decl(f_789)
static void C_ccall f_789(C_word c,C_word *av) C_noret;
C_noret_decl(f_794)
static void C_ccall f_794(C_word c,C_word *av) C_noret;
C_noret_decl(f_800)
static void C_fcall f_800(C_word t0,C_word t1) C_noret;
C_noret_decl(f_807)
static void C_ccall f_807(C_word c,C_word *av) C_noret;
C_noret_decl(f_810)
static void C_ccall f_810(C_word c,C_word *av) C_noret;
C_noret_decl(f_816)
static void C_ccall f_816(C_word c,C_word *av) C_noret;
C_noret_decl(f_825)
static void C_ccall f_825(C_word c,C_word *av) C_noret;
C_noret_decl(f_831)
static void C_ccall f_831(C_word c,C_word *av) C_noret;
C_noret_decl(f_837)
static void C_ccall f_837(C_word c,C_word *av) C_noret;
C_noret_decl(f_841)
static void C_ccall f_841(C_word c,C_word *av) C_noret;
C_noret_decl(f_844)
static void C_ccall f_844(C_word c,C_word *av) C_noret;
C_noret_decl(f_855)
static void C_fcall f_855(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_859)
static void C_ccall f_859(C_word c,C_word *av) C_noret;
C_noret_decl(f_874)
static void C_ccall f_874(C_word c,C_word *av) C_noret;
C_noret_decl(f_879)
static void C_ccall f_879(C_word c,C_word *av) C_noret;
C_noret_decl(f_882)
static void C_ccall f_882(C_word c,C_word *av) C_noret;
C_noret_decl(f_885)
static void C_ccall f_885(C_word c,C_word *av) C_noret;
C_noret_decl(f_892)
static void C_ccall f_892(C_word c,C_word *av) C_noret;
C_noret_decl(f_895)
static void C_ccall f_895(C_word c,C_word *av) C_noret;
C_noret_decl(f_907)
static void C_ccall f_907(C_word c,C_word *av) C_noret;
C_noret_decl(f_912)
static void C_fcall f_912(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_922)
static void C_ccall f_922(C_word c,C_word *av) C_noret;
C_noret_decl(f_942)
static void C_ccall f_942(C_word c,C_word *av) C_noret;
C_noret_decl(f_987)
static void C_ccall f_987(C_word c,C_word *av) C_noret;
C_noret_decl(f_989)
static void C_ccall f_989(C_word c,C_word *av) C_noret;
C_noret_decl(f_995)
static void C_ccall f_995(C_word c,C_word *av) C_noret;
C_noret_decl(C_repl_toplevel)
C_externexport void C_ccall C_repl_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_551)
static void C_ccall trf_551(C_word c,C_word *av) C_noret;
static void C_ccall trf_551(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_551(t0,t1);}

C_noret_decl(trf_565)
static void C_ccall trf_565(C_word c,C_word *av) C_noret;
static void C_ccall trf_565(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_565(t0,t1,t2);}

C_noret_decl(trf_637)
static void C_ccall trf_637(C_word c,C_word *av) C_noret;
static void C_ccall trf_637(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_637(t0,t1,t2);}

C_noret_decl(trf_732)
static void C_ccall trf_732(C_word c,C_word *av) C_noret;
static void C_ccall trf_732(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_732(t0,t1);}

C_noret_decl(trf_800)
static void C_ccall trf_800(C_word c,C_word *av) C_noret;
static void C_ccall trf_800(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_800(t0,t1);}

C_noret_decl(trf_855)
static void C_ccall trf_855(C_word c,C_word *av) C_noret;
static void C_ccall trf_855(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_855(t0,t1,t2,t3);}

C_noret_decl(trf_912)
static void C_ccall trf_912(C_word c,C_word *av) C_noret;
static void C_ccall trf_912(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_912(t0,t1,t2);}

/* a1004 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_1005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1005,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1009,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* repl.scm:189: chicken.load#load-verbose */
t3=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[7])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k1007 in a1004 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_1009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1009,c,av);}
a=C_alloc(4);
t2=C_mutate(&lf[9] /* (set! chicken.repl#quit-hook ...) */,((C_word*)t0)[2]);
t3=C_mutate((C_word*)lf[26]+1 /* (set! ##sys#notices-enabled ...) */,((C_word*)t0)[3]);
t4=C_mutate((C_word*)lf[27]+1 /* (set! ##sys#unbound-in-eval ...) */,((C_word*)t0)[4]);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1015,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* repl.scm:193: ##sys#error-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[7];
tp(3,av2);}}

/* k1013 in k1007 in a1004 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_1015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1015,c,av);}
/* repl.scm:194: ##sys#reset-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[13]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* a1025 in k466 in k463 in k460 */
static void C_ccall f_1026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1026,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[58];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k460 */
static void C_ccall f_462(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_462,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_465,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k463 in k460 */
static void C_ccall f_465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_465,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_468,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k466 in k463 in k460 */
static void C_ccall f_468(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_468,c,av);}
a=C_alloc(18);
t2=C_set_block_item(lf[2] /* ##sys#repl-print-length-limit */,0,C_SCHEME_FALSE);
t3=C_set_block_item(lf[3] /* ##sys#repl-read-hook */,0,C_SCHEME_FALSE);
t4=C_set_block_item(lf[4] /* ##sys#repl-recent-call-chain */,0,C_SCHEME_FALSE);
t5=C_mutate((C_word*)lf[5]+1 /* (set! ##sys#repl-print-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_473,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate(&lf[9] /* (set! chicken.repl#quit-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_488,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[11]+1 /* (set! chicken.repl#quit ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_494,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[12]+1 /* (set! chicken.repl#reset-handler ...) */,*((C_word*)lf[13]+1));
t9=C_mutate((C_word*)lf[14]+1 /* (set! chicken.repl#reset ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_510,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_521,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1026,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
/* repl.scm:59: chicken.base#make-parameter */
t12=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t12;
av2[1]=t10;
av2[2]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}

/* ##sys#repl-print-hook in k466 in k463 in k460 */
static void C_ccall f_473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_473,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_477,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_482,a[2]=t2,a[3]=t3,a[4]=((C_word)li0),tmp=(C_word)a,a+=5,tmp);
/* repl.scm:49: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[8]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[8]+1);
av2[1]=t4;
av2[2]=*((C_word*)lf[2]+1);
av2[3]=t5;
tp(4,av2);}}

/* k475 in ##sys#repl-print-hook in k466 in k463 in k460 */
static void C_ccall f_477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_477,c,av);}
/* repl.scm:50: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* a481 in ##sys#repl-print-hook in k466 in k463 in k460 */
static void C_ccall f_482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_482,c,av);}
t2=*((C_word*)lf[7]+1);
/* repl.scm:49: g108 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}

/* chicken.repl#quit-hook in k466 in k463 in k460 */
static void C_ccall f_488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_488,c,av);}
/* repl.scm:52: chicken.base#exit */
t3=*((C_word*)lf[10]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.repl#quit in k466 in k463 in k460 */
static void C_ccall f_494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_494,c,av);}
if(C_truep(C_rest_nullp(c,2))){
/* repl.scm:53: quit-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[9]);
C_word av2[3];
av2[0]=lf[9];
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
tp(3,av2);}}
else{
/* repl.scm:53: quit-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[9]);
C_word av2[3];
av2[0]=lf[9];
av2[1]=t1;
av2[2]=C_get_rest_arg(c,2,av,2,t0);
tp(3,av2);}}}

/* chicken.repl#reset in k466 in k463 in k460 */
static void C_ccall f_510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_510,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_514,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* repl.scm:56: reset-handler */
t3=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k512 in chicken.repl#reset in k466 in k463 in k460 */
static void C_ccall f_514(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_514,c,av);}
/* repl.scm:56: g126 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k519 in k466 in k463 in k460 */
static void C_ccall f_521(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_521,c,av);}
a=C_alloc(11);
t2=C_mutate((C_word*)lf[15]+1 /* (set! chicken.repl#repl-prompt ...) */,t1);
t3=*((C_word*)lf[15]+1);
t4=C_mutate((C_word*)lf[16]+1 /* (set! ##sys#read-prompt-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_523,a[2]=t3,a[3]=((C_word)li5),tmp=(C_word)a,a+=4,tmp));
t5=C_mutate((C_word*)lf[19]+1 /* (set! ##sys#resize-trace-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_539,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t6=*((C_word*)lf[21]+1);
t7=C_mutate((C_word*)lf[22]+1 /* (set! chicken.repl#repl ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_545,a[2]=t6,a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* ##sys#read-prompt-hook in k519 in k466 in k463 in k460 */
static void C_ccall f_523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_523,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_527,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_534,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* repl.scm:64: repl-prompt */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k525 in ##sys#read-prompt-hook in k519 in k466 in k463 in k460 */
static void C_ccall f_527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_527,c,av);}
/* repl.scm:65: ##sys#flush-output */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[17]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[17]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[18]+1);
tp(3,av2);}}

/* k532 in ##sys#read-prompt-hook in k519 in k466 in k463 in k460 */
static void C_ccall f_534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_534,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_537,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* repl.scm:64: g131 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k535 in k532 in ##sys#read-prompt-hook in k519 in k466 in k463 in k460 */
static void C_ccall f_537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_537,c,av);}
/* repl.scm:64: ##sys#print */
t2=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* ##sys#resize-trace-buffer in k519 in k466 in k463 in k460 */
static void C_ccall f_539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_539,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_543,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* repl.scm:68: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k541 in ##sys#resize-trace-buffer in k519 in k466 in k463 in k460 */
static void C_ccall f_543(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_543,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_resize_trace_buffer(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_545(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_545,c,av);}
a=C_alloc(17);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?((C_word*)t0)[2]:C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_551,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp);
t5=*((C_word*)lf[25]+1);
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=*((C_word*)lf[18]+1);
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=*((C_word*)lf[24]+1);
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_669,a[2]=t6,a[3]=t8,a[4]=t10,a[5]=t4,a[6]=t3,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* repl.scm:93: ##sys#error-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t11;
tp(2,av2);}}

/* write-err in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_551(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_551,2,t1,t2);}
a=C_alloc(6);
t3=C_i_check_list_2(t2,lf[23]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_565,a[2]=t5,a[3]=((C_word)li7),tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_565(t7,t1,t2);}

/* for-each-loop156 in write-err in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_565(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_565,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_575,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[5]+1);
/* repl.scm:78: g172 */
t6=t5;{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[24]+1);
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k573 in for-each-loop156 in write-err in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_575,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_565(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k610 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_612(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_612,c,av);}
a=C_alloc(6);
if(C_truep(C_i_pairp(C_u_i_cdr(((C_word*)t0)[2])))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_625,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_629,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* repl.scm:87: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=C_i_length(((C_word*)t0)[2]);
tp(3,av2);}}
else{
/* repl.scm:187: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_800(t2,((C_word*)t0)[5]);}}

/* k623 in k610 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_625,c,av);}
/* repl.scm:86: ##sys#print */
t2=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k627 in k610 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_629,c,av);}
/* repl.scm:87: string-append */
t2=*((C_word*)lf[43]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[44];
av2[3]=t1;
av2[4]=lf[45];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* for-each-loop186 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_637(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_637,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_647,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[5]+1);
/* repl.scm:84: g202 */
t6=t5;{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[18]+1);
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k645 in for-each-loop186 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_647(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_647,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_637(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_669(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_669,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_672,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* repl.scm:94: ##sys#reset-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t2;
tp(2,av2);}}

/* k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_672(C_word c,C_word *av){
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
C_word t13;
C_word t14;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,3)))){
C_save_and_reclaim((void *)f_672,c,av);}
a=C_alloc(29);
t2=*((C_word*)lf[26]+1);
t3=C_SCHEME_FALSE;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=lf[9];
t6=*((C_word*)lf[27]+1);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_674,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t12=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_680,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t13=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_689,a[2]=t4,a[3]=t10,a[4]=((C_word*)t0)[5],a[5]=t8,a[6]=((C_word*)t0)[6],a[7]=t5,a[8]=t2,a[9]=t6,a[10]=t1,a[11]=((C_word*)t0)[7],a[12]=((C_word)li22),tmp=(C_word)a,a+=13,tmp);
/* repl.scm:110: call-with-current-continuation */
t14=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t14;
av2[1]=((C_word*)t0)[8];
av2[2]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(3,av2);}}

/* saveports in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static C_word C_fcall f_674(C_word t0){
C_word tmp;
C_word t1;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t1=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[25]+1));
t2=C_mutate(((C_word *)((C_word*)t0)[3])+1,*((C_word*)lf[18]+1));
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,*((C_word*)lf[24]+1));
return(t3);}

/* resetports in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static C_word C_fcall f_680(C_word t0){
C_word tmp;
C_word t1;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t1=C_mutate((C_word*)lf[25]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[2])[1]);
t2=C_mutate((C_word*)lf[18]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate((C_word*)lf[24]+1 /* (set! ##sys#standard-error ...) */,((C_word*)((C_word*)t0)[4])[1]);
return(t3);}

/* a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_689(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_689,c,av);}
a=C_alloc(22);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_695,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li11),tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_794,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],a[5]=((C_word)li20),tmp=(C_word)a,a+=6,tmp);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1005,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[2],a[8]=((C_word)li21),tmp=(C_word)a,a+=9,tmp);
/* repl.scm:112: ##sys#dynamic-wind */
t6=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_695,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_700,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* repl.scm:114: chicken.load#load-verbose */
t3=*((C_word*)lf[40]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_700(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_700,c,av);}
a=C_alloc(9);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(&lf[9] /* (set! chicken.repl#quit-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_702,a[2]=((C_word*)t0)[3],a[3]=((C_word)li9),tmp=(C_word)a,a+=4,tmp));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_709,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* repl.scm:116: chicken.load#load-verbose */
t5=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* chicken.repl#quit-hook in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_702,c,av);}
/* repl.scm:115: k */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_709,c,av);}
a=C_alloc(5);
t2=C_set_block_item(lf[26] /* ##sys#notices-enabled */,0,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_715,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li10),tmp=(C_word)a,a+=5,tmp);
/* repl.scm:118: ##sys#error-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t3;
tp(3,av2);}}

/* a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_715(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +6,c,4)))){
C_save_and_reclaim((void*)f_715,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+6);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(
/* repl.scm:120: resetports */
  f_680(((C_word*)((C_word*)t0)[2])[1])
);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_722,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* repl.scm:121: ##sys#print */
t6=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[38];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_722,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_725,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[5])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_789,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* repl.scm:123: ##sys#print */
t4=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[37];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_725(2,av2);}}}

/* k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_725,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_728,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_i_pairp(((C_word*)t0)[3]);
t4=(C_truep(t3)?C_i_nullp(C_u_i_cdr(((C_word*)t0)[3])):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_769,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* repl.scm:127: ##sys#print */
t6=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[36];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_775,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* repl.scm:130: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=t5;
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[24]+1);
tp(4,av2);}}}

/* k726 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_728,c,av);}
a=C_alloc(3);
t2=*((C_word*)lf[28]+1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_732,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(*((C_word*)lf[28]+1))){
if(C_truep(C_i_structurep(*((C_word*)lf[28]+1),lf[34]))){
t4=C_slot(*((C_word*)lf[28]+1),C_fix(2));
t5=C_i_member(lf[35],t4);
t6=t3;
f_732(t6,(C_truep(t5)?C_i_cadr(t5):C_SCHEME_FALSE));}
else{
t4=t3;
f_732(t4,C_SCHEME_FALSE);}}
else{
t4=t3;
f_732(t4,C_SCHEME_FALSE);}}

/* k730 in k726 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_732(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_732,2,t0,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_735,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=t1;
f_735(2,av2);}}
else{
/* repl.scm:137: chicken.base#get-call-chain */
t3=*((C_word*)lf[32]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(0);
av2[3]=*((C_word*)lf[33]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k733 in k730 in k726 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_735,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_738,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* repl.scm:138: ##sys#really-print-call-chain */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[24]+1);
av2[3]=t1;
av2[4]=lf[31];
tp(5,av2);}}

/* k736 in k733 in k730 in k726 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_738,c,av);}
t2=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#repl-recent-call-chain ...) */,((C_word*)t0)[2]);
/* repl.scm:142: chicken.base#flush-output */
t3=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k767 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_769(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_769,c,av);}
/* repl.scm:128: write-err */
f_551(((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k773 in k723 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_775,c,av);}
/* repl.scm:131: write-err */
f_551(((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k787 in k720 in a714 in k707 in k698 in a694 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_789(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_789,c,av);}
/* repl.scm:124: ##sys#print */
t2=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_794,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_800,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word)li19),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_800(t5,t1);}

/* loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_800(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_800,2,t0,t1);}
a=C_alloc(9);
t2=(
/* repl.scm:145: saveports */
  f_674(((C_word*)((C_word*)t0)[2])[1])
);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_807,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_989,a[2]=((C_word*)t0)[5],a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
/* repl.scm:146: call-with-current-continuation */
t5=*((C_word*)lf[56]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_807,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_810,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* repl.scm:153: ##sys#read-prompt-hook */
t3=*((C_word*)lf[16]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_810,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[3]+1);
t3=(C_truep(t2)?t2:*((C_word*)lf[41]+1));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_816,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* repl.scm:155: g258 */
t5=t3;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)C_fast_retrieve_proc(t5))(2,av2);}}

/* k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_816,c,av);}
a=C_alloc(9);
if(C_truep(C_eofp(t1))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_825,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_987,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* repl.scm:157: ##sys#peek-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[54]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[54]+1);
av2[1]=t3;
av2[2]=*((C_word*)lf[25]+1);
tp(3,av2);}}}

/* k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_825,c,av);}
a=C_alloc(9);
t2=code_263();
t3=C_set_block_item(lf[27] /* ##sys#unbound-in-eval */,0,C_SCHEME_END_OF_LIST);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_831,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li12),tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_837,a[2]=((C_word*)t0)[4],a[3]=((C_word)li16),tmp=(C_word)a,a+=4,tmp);
/* repl.scm:161: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}

/* a830 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_831,c,av);}
/* repl.scm:161: evaluator */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +11,c,4)))){
C_save_and_reclaim((void*)f_837,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+11);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_841,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(C_truep(*((C_word*)lf[47]+1))?C_i_pairp(*((C_word*)lf[27]+1)):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_855,a[2]=t6,a[3]=((C_word)li15),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_855(t8,t3,*((C_word*)lf[27]+1),C_SCHEME_END_OF_LIST);}
else{
t5=t3;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_841(2,av2);}}}

/* k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_841(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_841,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_844,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
/* repl.scm:82: ##sys#print */
t3=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[42];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=C_i_car(((C_word*)t0)[4]);
t4=C_eqp(C_SCHEME_UNDEFINED,t3);
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_612,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_637,a[2]=t7,a[3]=((C_word)li13),tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_637(t9,t5,((C_word*)t0)[4]);}
else{
/* repl.scm:187: loop */
t5=((C_word*)((C_word*)t0)[2])[1];
f_800(t5,((C_word*)t0)[3]);}}}

/* k842 in k839 in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_844,c,av);}
/* repl.scm:187: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_800(t2,((C_word*)t0)[3]);}

/* loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_855(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_855,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_859,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t2))){
if(C_truep(C_i_pairp(t3))){
if(C_truep(*((C_word*)lf[26]+1))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_874,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* repl.scm:168: ##sys#notice */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[50]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[50]+1);
av2[1]=t5;
av2[2]=lf[51];
tp(3,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_fix(9);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_fix(9);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t5=C_i_caar(t2);
t6=C_i_memq(t5,t3);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_942,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t6)){
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=t6;
f_942(2,av2);}}
else{
t8=C_u_i_car(t2);
t9=C_u_i_car(t8);
t10=C_u_i_namespaced_symbolp(t9);
if(C_truep(t10)){
t11=t7;{
C_word av2[2];
av2[0]=t11;
av2[1]=t10;
f_942(2,av2);}}
else{
t11=C_u_i_car(t2);
/* repl.scm:183: ##sys#symbol-has-toplevel-binding? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[52]+1);
av2[1]=t7;
av2[2]=C_u_i_car(t11);
tp(3,av2);}}}}}

/* k857 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_859,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(9);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_874,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_907,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_912,a[2]=t4,a[3]=((C_word)li14),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_912(t6,t2,((C_word*)t0)[3]);}

/* k877 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_879,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_882,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* repl.scm:173: ##sys#print */
t3=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[3]);
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k880 in k877 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_882,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_885,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_u_i_cdr(((C_word*)t0)[3]))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_892,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* repl.scm:175: ##sys#print */
t4=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[48];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* repl.scm:178: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[24]+1);
tp(4,av2);}}}

/* k883 in k880 in k877 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_885,c,av);}
/* repl.scm:178: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[24]+1);
tp(4,av2);}}

/* k890 in k880 in k877 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_892,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_895,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* repl.scm:176: ##sys#print */
t3=*((C_word*)lf[7]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_cdr(((C_word*)t0)[3]);
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k893 in k890 in k880 in k877 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 in ... */
static void C_ccall f_895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_895,c,av);}
/* repl.scm:177: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(41);
av2[3]=*((C_word*)lf[24]+1);
tp(4,av2);}}

/* k905 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_907,c,av);}
/* repl.scm:180: ##sys#flush-output */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[17]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[17]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[24]+1);
tp(3,av2);}}

/* for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_fcall f_912(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_912,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_922,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_879,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* repl.scm:172: ##sys#print */
t6=*((C_word*)lf[7]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[49];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k920 in for-each-loop276 in k872 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_922,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_912(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k940 in loop in a836 in k823 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_942,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
/* repl.scm:184: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_855(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[5]);}
else{
t2=C_u_i_cdr(((C_word*)t0)[4]);
t3=C_u_i_car(((C_word*)t0)[4]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[5]);
/* repl.scm:185: loop */
t5=((C_word*)((C_word*)t0)[2])[1];
f_855(t5,((C_word*)t0)[3],t2,t4);}}

/* k985 in k814 in k808 in k805 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_987(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_987,c,av);}
t2=C_eqp(C_make_character(10),t1);
if(C_truep(t2)){
/* repl.scm:158: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[53]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[53]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[25]+1);
tp(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_825(2,av2);}}}

/* a988 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_989,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_995,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li17),tmp=(C_word)a,a+=5,tmp);
/* repl.scm:148: ##sys#reset-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t1;
av2[2]=t3;
tp(3,av2);}}

/* a994 in a988 in loop in a793 in a688 in k670 in k667 in chicken.repl#repl in k519 in k466 in k463 in k460 */
static void C_ccall f_995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_995,c,av);}
t2=C_set_block_item(lf[55] /* ##sys#read-error-with-line-number */,0,C_SCHEME_FALSE);
t3=(
/* repl.scm:151: resetports */
  f_680(((C_word*)((C_word*)t0)[2])[1])
);
/* repl.scm:152: c */
t4=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_repl_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("repl"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_repl_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(346))){
C_save(t1);
C_rereclaim2(346*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,60);
lf[0]=C_h_intern(&lf[0],4, C_text("repl"));
lf[1]=C_h_intern(&lf[1],13, C_text("chicken.repl#"));
lf[2]=C_h_intern(&lf[2],29, C_text("##sys#repl-print-length-limit"));
lf[3]=C_h_intern(&lf[3],20, C_text("##sys#repl-read-hook"));
lf[4]=C_h_intern(&lf[4],28, C_text("##sys#repl-recent-call-chain"));
lf[5]=C_h_intern(&lf[5],21, C_text("##sys#repl-print-hook"));
lf[6]=C_h_intern(&lf[6],18, C_text("##sys#write-char-0"));
lf[7]=C_h_intern(&lf[7],11, C_text("##sys#print"));
lf[8]=C_h_intern(&lf[8],29, C_text("##sys#with-print-length-limit"));
lf[10]=C_h_intern(&lf[10],17, C_text("chicken.base#exit"));
lf[11]=C_h_intern(&lf[11],17, C_text("chicken.repl#quit"));
lf[12]=C_h_intern(&lf[12],26, C_text("chicken.repl#reset-handler"));
lf[13]=C_h_intern(&lf[13],19, C_text("##sys#reset-handler"));
lf[14]=C_h_intern(&lf[14],18, C_text("chicken.repl#reset"));
lf[15]=C_h_intern(&lf[15],24, C_text("chicken.repl#repl-prompt"));
lf[16]=C_h_intern(&lf[16],22, C_text("##sys#read-prompt-hook"));
lf[17]=C_h_intern(&lf[17],18, C_text("##sys#flush-output"));
lf[18]=C_h_intern(&lf[18],21, C_text("##sys#standard-output"));
lf[19]=C_h_intern(&lf[19],25, C_text("##sys#resize-trace-buffer"));
lf[20]=C_h_intern(&lf[20],18, C_text("##sys#check-fixnum"));
lf[21]=C_h_intern(&lf[21],11, C_text("scheme#eval"));
lf[22]=C_h_intern(&lf[22],17, C_text("chicken.repl#repl"));
lf[23]=C_h_intern(&lf[23],8, C_text("for-each"));
lf[24]=C_h_intern(&lf[24],20, C_text("##sys#standard-error"));
lf[25]=C_h_intern(&lf[25],20, C_text("##sys#standard-input"));
lf[26]=C_h_intern(&lf[26],21, C_text("##sys#notices-enabled"));
lf[27]=C_h_intern(&lf[27],21, C_text("##sys#unbound-in-eval"));
lf[28]=C_h_intern(&lf[28],20, C_text("##sys#last-exception"));
lf[29]=C_h_intern(&lf[29],25, C_text("chicken.base#flush-output"));
lf[30]=C_h_intern(&lf[30],29, C_text("##sys#really-print-call-chain"));
lf[31]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020\012\011Call history:\012"));
lf[32]=C_h_intern(&lf[32],27, C_text("chicken.base#get-call-chain"));
lf[33]=C_h_intern(&lf[33],20, C_text("##sys#current-thread"));
lf[34]=C_h_intern(&lf[34],9, C_text("condition"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001exn\376\001\000\000\012\001call-chain"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[37]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006\012Error"));
lf[39]=C_h_intern(&lf[39],19, C_text("##sys#error-handler"));
lf[40]=C_h_intern(&lf[40],25, C_text("chicken.load#load-verbose"));
lf[41]=C_h_intern(&lf[41],36, C_text("chicken.syntax#read-with-source-info"));
lf[42]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014; no values\012"));
lf[43]=C_h_intern(&lf[43],20, C_text("scheme#string-append"));
lf[44]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002; "));
lf[45]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010 values\012"));
lf[46]=C_h_intern(&lf[46],20, C_text("##sys#number->string"));
lf[47]=C_h_intern(&lf[47],22, C_text("##sys#warnings-enabled"));
lf[48]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005 (in "));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[50]=C_h_intern(&lf[50],12, C_text("##sys#notice"));
lf[51]=C_decode_literal(C_heaptop,C_text("\376B\000\000=the following toplevel variables are referenced but unbound:\012"));
lf[52]=C_h_intern(&lf[52],34, C_text("##sys#symbol-has-toplevel-binding\077"));
lf[53]=C_h_intern(&lf[53],17, C_text("##sys#read-char-0"));
lf[54]=C_h_intern(&lf[54],17, C_text("##sys#peek-char-0"));
lf[55]=C_h_intern(&lf[55],33, C_text("##sys#read-error-with-line-number"));
lf[56]=C_h_intern(&lf[56],37, C_text("scheme#call-with-current-continuation"));
lf[57]=C_h_intern(&lf[57],18, C_text("##sys#dynamic-wind"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004#;> "));
lf[59]=C_h_intern(&lf[59],27, C_text("chicken.base#make-parameter"));
C_register_lf2(lf,60,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_462,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[76] = {
{C_text("f_1005:repl_2escm"),(void*)f_1005},
{C_text("f_1009:repl_2escm"),(void*)f_1009},
{C_text("f_1015:repl_2escm"),(void*)f_1015},
{C_text("f_1026:repl_2escm"),(void*)f_1026},
{C_text("f_462:repl_2escm"),(void*)f_462},
{C_text("f_465:repl_2escm"),(void*)f_465},
{C_text("f_468:repl_2escm"),(void*)f_468},
{C_text("f_473:repl_2escm"),(void*)f_473},
{C_text("f_477:repl_2escm"),(void*)f_477},
{C_text("f_482:repl_2escm"),(void*)f_482},
{C_text("f_488:repl_2escm"),(void*)f_488},
{C_text("f_494:repl_2escm"),(void*)f_494},
{C_text("f_510:repl_2escm"),(void*)f_510},
{C_text("f_514:repl_2escm"),(void*)f_514},
{C_text("f_521:repl_2escm"),(void*)f_521},
{C_text("f_523:repl_2escm"),(void*)f_523},
{C_text("f_527:repl_2escm"),(void*)f_527},
{C_text("f_534:repl_2escm"),(void*)f_534},
{C_text("f_537:repl_2escm"),(void*)f_537},
{C_text("f_539:repl_2escm"),(void*)f_539},
{C_text("f_543:repl_2escm"),(void*)f_543},
{C_text("f_545:repl_2escm"),(void*)f_545},
{C_text("f_551:repl_2escm"),(void*)f_551},
{C_text("f_565:repl_2escm"),(void*)f_565},
{C_text("f_575:repl_2escm"),(void*)f_575},
{C_text("f_612:repl_2escm"),(void*)f_612},
{C_text("f_625:repl_2escm"),(void*)f_625},
{C_text("f_629:repl_2escm"),(void*)f_629},
{C_text("f_637:repl_2escm"),(void*)f_637},
{C_text("f_647:repl_2escm"),(void*)f_647},
{C_text("f_669:repl_2escm"),(void*)f_669},
{C_text("f_672:repl_2escm"),(void*)f_672},
{C_text("f_674:repl_2escm"),(void*)f_674},
{C_text("f_680:repl_2escm"),(void*)f_680},
{C_text("f_689:repl_2escm"),(void*)f_689},
{C_text("f_695:repl_2escm"),(void*)f_695},
{C_text("f_700:repl_2escm"),(void*)f_700},
{C_text("f_702:repl_2escm"),(void*)f_702},
{C_text("f_709:repl_2escm"),(void*)f_709},
{C_text("f_715:repl_2escm"),(void*)f_715},
{C_text("f_722:repl_2escm"),(void*)f_722},
{C_text("f_725:repl_2escm"),(void*)f_725},
{C_text("f_728:repl_2escm"),(void*)f_728},
{C_text("f_732:repl_2escm"),(void*)f_732},
{C_text("f_735:repl_2escm"),(void*)f_735},
{C_text("f_738:repl_2escm"),(void*)f_738},
{C_text("f_769:repl_2escm"),(void*)f_769},
{C_text("f_775:repl_2escm"),(void*)f_775},
{C_text("f_789:repl_2escm"),(void*)f_789},
{C_text("f_794:repl_2escm"),(void*)f_794},
{C_text("f_800:repl_2escm"),(void*)f_800},
{C_text("f_807:repl_2escm"),(void*)f_807},
{C_text("f_810:repl_2escm"),(void*)f_810},
{C_text("f_816:repl_2escm"),(void*)f_816},
{C_text("f_825:repl_2escm"),(void*)f_825},
{C_text("f_831:repl_2escm"),(void*)f_831},
{C_text("f_837:repl_2escm"),(void*)f_837},
{C_text("f_841:repl_2escm"),(void*)f_841},
{C_text("f_844:repl_2escm"),(void*)f_844},
{C_text("f_855:repl_2escm"),(void*)f_855},
{C_text("f_859:repl_2escm"),(void*)f_859},
{C_text("f_874:repl_2escm"),(void*)f_874},
{C_text("f_879:repl_2escm"),(void*)f_879},
{C_text("f_882:repl_2escm"),(void*)f_882},
{C_text("f_885:repl_2escm"),(void*)f_885},
{C_text("f_892:repl_2escm"),(void*)f_892},
{C_text("f_895:repl_2escm"),(void*)f_895},
{C_text("f_907:repl_2escm"),(void*)f_907},
{C_text("f_912:repl_2escm"),(void*)f_912},
{C_text("f_922:repl_2escm"),(void*)f_922},
{C_text("f_942:repl_2escm"),(void*)f_942},
{C_text("f_987:repl_2escm"),(void*)f_987},
{C_text("f_989:repl_2escm"),(void*)f_989},
{C_text("f_995:repl_2escm"),(void*)f_995},
{C_text("toplevel:repl_2escm"),(void*)C_repl_toplevel},
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
o|hiding unexported module binding: chicken.repl#d 
o|hiding unexported module binding: chicken.repl#define-alias 
o|hiding unexported module binding: chicken.repl#quit-hook 
S|applied compiler syntax:
S|  scheme#for-each		3
o|eliminated procedure checks: 22 
o|specializations:
o|  1 (scheme#car pair)
o|  2 (scheme#caar (pair pair *))
o|  6 (scheme#cdr pair)
o|  2 (##sys#check-list (or pair list) *)
(o e)|safe calls: 52 
(o e)|assignments to immediate values: 1 
o|safe globals: (chicken.repl#reset chicken.repl#reset-handler chicken.repl#quit chicken.repl#quit-hook ##sys#repl-print-hook ##sys#repl-recent-call-chain ##sys#repl-read-hook ##sys#repl-print-length-limit) 
o|propagated global variable: g108109 ##sys#print 
o|inlining procedure: k496 
o|inlining procedure: k496 
o|inlining procedure: k567 
o|contracted procedure: "(repl.scm:78) g157164" 
o|inlining procedure: k567 
o|inlining procedure: k590 
o|inlining procedure: k590 
o|inlining procedure: k613 
o|inlining procedure: k613 
o|inlining procedure: k639 
o|contracted procedure: "(repl.scm:84) g187194" 
o|inlining procedure: k639 
o|propagated global variable: lexn239 ##sys#last-exception 
o|inlining procedure: k748 
o|inlining procedure: k748 
o|propagated global variable: lexn239 ##sys#last-exception 
o|inlining procedure: k817 
o|inlining procedure: k817 
o|inlining procedure: k857 
o|inlining procedure: k869 
o|inlining procedure: k914 
o|contracted procedure: "(repl.scm:170) g277284" 
o|inlining procedure: k883 
o|inlining procedure: k883 
o|inlining procedure: k914 
o|inlining procedure: k869 
o|inlining procedure: k857 
o|inlining procedure: k962 
o|inlining procedure: k962 
o|replaced variables: 107 
o|removed binding forms: 82 
o|substituted constant variable: r4971028 
o|substituted constant variable: r4971028 
o|substituted constant variable: r7491047 
o|contracted procedure: "(repl.scm:186) write-results152" 
o|inlining procedure: k857 
o|inlining procedure: k857 
o|converted assignments to bindings: (write-err151) 
o|simplifications: ((let . 1)) 
o|replaced variables: 12 
o|removed binding forms: 104 
o|replaced variables: 9 
o|removed binding forms: 16 
o|inlining procedure: k842 
o|inlining procedure: k842 
o|removed binding forms: 3 
o|removed binding forms: 2 
o|removed binding forms: 1 
o|simplifications: ((let . 5) (if . 5) (##core#call . 36)) 
o|  call simplifications:
o|    scheme#eof-object?
o|    ##sys#call-with-values
o|    scheme#caar
o|    scheme#memq
o|    scheme#cons
o|    scheme#eq?	2
o|    scheme#not
o|    scheme#length
o|    ##sys#structure?
o|    scheme#member
o|    scheme#cadr
o|    ##sys#check-list
o|    scheme#pair?	7
o|    ##sys#slot	7
o|    scheme#null?	5
o|    scheme#car	4
o|contracted procedure: k502 
o|contracted procedure: k496 
o|contracted procedure: k1019 
o|contracted procedure: k547 
o|contracted procedure: k558 
o|contracted procedure: k570 
o|contracted procedure: k580 
o|contracted procedure: k584 
o|contracted procedure: k745 
o|contracted procedure: k761 
o|propagated global variable: lexn239 ##sys#last-exception 
o|contracted procedure: k751 
o|contracted procedure: k779 
o|contracted procedure: k764 
o|contracted procedure: k811 
o|contracted procedure: k820 
o|contracted procedure: k593 
o|contracted procedure: k664 
o|contracted procedure: k660 
o|contracted procedure: k602 
o|contracted procedure: k616 
o|contracted procedure: k631 
o|contracted procedure: k642 
o|contracted procedure: k652 
o|contracted procedure: k656 
o|contracted procedure: k848 
o|contracted procedure: k860 
o|contracted procedure: k866 
o|contracted procedure: k917 
o|contracted procedure: k927 
o|contracted procedure: k931 
o|contracted procedure: k902 
o|contracted procedure: k972 
o|contracted procedure: k937 
o|contracted procedure: k954 
o|contracted procedure: k978 
o|simplifications: ((let . 17)) 
o|removed binding forms: 35 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest117118 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest117118 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest144145 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest144145 0 
o|direct leaf routine/allocation: saveports219 0 
o|direct leaf routine/allocation: resetports220 0 
o|contracted procedure: "(repl.scm:120) k717" 
o|contracted procedure: "(repl.scm:145) k802" 
o|contracted procedure: "(repl.scm:151) k998" 
o|removed binding forms: 3 
o|customizable procedures: (loop267 for-each-loop276292 for-each-loop186204 loop253 write-err151 k730 for-each-loop156174) 
o|calls to known targets: 24 
o|unused rest argument: rest117118 f_494 
o|unused rest argument: rest144145 f_545 
o|fast box initializations: 7 
o|fast global references: 3 
o|fast global assignments: 3 
o|dropping unused closure argument: f_551 
*/
/* end of file */
